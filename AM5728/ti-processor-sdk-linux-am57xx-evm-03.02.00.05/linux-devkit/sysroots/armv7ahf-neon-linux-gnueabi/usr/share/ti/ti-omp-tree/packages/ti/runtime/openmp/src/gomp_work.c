/* Copyright (C) 2005, 2008, 2009 Free Software Foundation, Inc.
   Contributed by Richard Henderson <rth@redhat.com>.

   This file is part of the GNU OpenMP Library (libgomp).

   Libgomp is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   Libgomp is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
   FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
   more details.

   Under Section 7 of GPL version 3, you are granted additional
   permissions described in the GCC Runtime Library Exception, version
   3.1, as published by the Free Software Foundation.

   You should have received a copy of the GNU General Public License and
   a copy of the GCC Runtime Library Exception along with this program;
   see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
   <http://www.gnu.org/licenses/>.  */

/* Copyright (C) 2012
   Texas Instruments, Inc.
   
   Changes from original:
   - gomp_free/gomp_alloc used instead of free/alloc
   - Casting added to suppress warning from TI compiler 
   - Replaced references to gomp team/thread structures with TI equivalents
*/
   
/* This file contains routines to manage the work-share queue for a team
   of threads.  */
#include "tomp_parallel.h"
#include "tomp_log.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/* Update the next_ws pointer after the workshare has been initialized by the
 * thread that encountered the workshare construct and allocated a
 * workshare
 */
void
gomp_work_share_init_done (void)
{
  tomp_Thread *thr = &tomp_thread;
  if (__builtin_expect (thr->ts->last_work_share != NULL, 1))
    gomp_ptrlock_set (&thr->ts->last_work_share->next_ws, thr->ts->work_share);
}



/* Allocate a new work share structure */

static struct gomp_work_share *
alloc_work_share (tomp_Team *team)
{
  struct gomp_work_share *ws;

  tomp_event_t ws_event = tomp_eventAllocChecked(sizeof(struct gomp_work_share),
                                                 __FILE__, __LINE__);

  ws = (struct gomp_work_share *) tomp_event_pointer(ws_event);
  ws->event = ws_event;

  return ws;
}

/* Initialize an already allocated struct gomp_work_share.
   This shouldn't touch the next_alloc field.  */

void
gomp_init_work_share (struct gomp_work_share *ws, bool ordered,
                      unsigned nthreads)
{
  if (__builtin_expect (ordered, 0))
    {
      memset (ws->ordered_team_ids, '\0',
	      TOMP_DEVICE_NUM_CORES * sizeof (ws->ordered_team_ids[0]));
      ws->ordered_num_used = 0;
      ws->ordered_owner = (unsigned)-1;
      ws->ordered_cur = 0;
    }

  ws->lock = TOMP_WS_HW_SEM_IDX;
  gomp_ptrlock_init (&ws->next_ws, NULL);
  ws->threads_completed = 0;
}

/* Do any needed destruction of gomp_work_share fields before it
   is put back into free gomp_work_share cache or freed.  */

void
gomp_fini_work_share (struct gomp_work_share *ws)
{
  gomp_ptrlock_destroy (&ws->next_ws);
}

/* Free a work share struct, if not orphaned, put it into current
   team's free gomp_work_share cache.  */

static inline void
free_work_share (tomp_Team *team, struct gomp_work_share *ws)
{
  gomp_fini_work_share (ws);

  /* ws->event is NULL if the work share was not dynamically allocated */
  if (ws->event) 
    tomp_eventFree (ws->event);
}

/* The current thread is ready to begin the next work sharing construct.
   In all cases, thr->ts->work_share is updated to point to the new
   structure.  In all cases the work_share lock is locked.  Return true
   if this was the first thread to reach this point.  */

bool
gomp_work_share_start (bool ordered)
{
  tomp_Thread *thr = &tomp_thread;
  tomp_Team   *team = thr->ts->team;
  struct gomp_work_share *ws;

  /* Work sharing constructs can be orphaned.  */
  if (team == NULL)
    {
      ws = alloc_work_share(NULL);
      gomp_init_work_share (ws, ordered, 1);
      thr->ts->work_share = ws;
      return (ws != NULL);
    }

  /* work_share set to team->dummy_ws during team initialization
     gomp_init_work_share called from gomp_new_team sets next_ws->ptr to NULL
     ts is thread local */
  ws = thr->ts->work_share;
  thr->ts->last_work_share = ws;
  ws = gomp_ptrlock_get (&ws->next_ws);

  /* ws is NULL for the first thread that reaches here */
  if (ws == NULL)
    {
      /* This thread encountered a new ws first.  */
      struct gomp_work_share *ws = alloc_work_share (team);
      gomp_init_work_share (ws, ordered, team->nthreads);
      thr->ts->work_share = ws;
      return true;
    }
  else
    {
      thr->ts->work_share = ws;
      return false;
    }
}

/* The current thread is done with its current work sharing construct.
   This version does imply a barrier at the end of the work-share.  */

void
gomp_work_share_end (void)
{
  tomp_Thread *thr = &tomp_thread;
  tomp_Team   *team = thr->ts->team;
  struct gomp_work_share *ws = thr->ts->work_share;
  unsigned int completed;

  /* Work sharing constructs can be orphaned.  */
  if (team == NULL)
    {
      free_work_share (NULL, ws);
      thr->ts->work_share = NULL;
      return;
    }

  /* Increment the thread counter */
  completed = tomp_incrementAtomic(&ws->threads_completed);

  /* If this is the last thread to reach this point, we can free the 
     previous workshare */
  if ((completed == team->nthreads) && thr->ts->last_work_share)
    free_work_share (team, thr->ts->last_work_share);
  thr->ts->last_work_share = NULL;

  /* OMP 3.1, p81 - at exit from worksharing regions unless nowait is present*/
  tomp_waitAtBarrierWithFlush(&team->barrier);
}

/* The current thread is done with its current work sharing construct.
   This version does NOT imply a barrier at the end of the work-share.  */

void
gomp_work_share_end_nowait (void)
{
  tomp_Thread *thr = &tomp_thread;
  tomp_Team   *team = thr->ts->team;
  struct gomp_work_share *ws = thr->ts->work_share;
  unsigned int completed;

  /* Work sharing constructs can be orphaned.  */
  if (team == NULL)
    {
      free_work_share (NULL, ws);
      thr->ts->work_share = NULL;
      return;
    }

  if (__builtin_expect (thr->ts->last_work_share == NULL, 0))
    return;

  completed = tomp_incrementAtomic(&ws->threads_completed);

  if (completed == team->nthreads)
    free_work_share (team, thr->ts->last_work_share);
  thr->ts->last_work_share = NULL;
}
