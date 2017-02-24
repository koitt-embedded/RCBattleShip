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

/* This file handles the SINGLE construct.  */

/* Copyright (C) 2012
   Texas Instruments, Inc.
   
   Changes from original:
   - Replaced references to gomp team/thread structures with TI equivalents
   - Replaced gomp barrier with TI implementation
*/
 
#include "tomp_parallel.h"


/* This routine is called when first encountering a SINGLE construct that
   doesn't have a COPYPRIVATE clause.  Returns true if this is the thread
   that should execute the clause.  */

bool
GOMP_single_start (void)
{
  bool ret = gomp_work_share_start (false);
  if (ret)
    gomp_work_share_init_done ();
  gomp_work_share_end_nowait ();
  return ret;
}

/* This routine is called when first encountering a SINGLE construct that
   does have a COPYPRIVATE clause.  Returns NULL if this is the thread
   that should execute the clause; otherwise the return value is pointer
   given to GOMP_single_copy_end by the thread that did execute the clause.  */

void *
GOMP_single_copy_start (void)
{
  tomp_Thread *thr  = &tomp_thread;
  tomp_Team   *team = thr->ts->team;

  bool first;
  void *ret;

  first = gomp_work_share_start (false);
  
  if (first)
    {
      gomp_work_share_init_done ();
      ret = NULL;
    }
  else
    {
      tomp_waitAtBarrier(&team->barrier);

      ret = thr->ts->work_share->copyprivate;
      gomp_work_share_end_nowait ();
    }

  return ret;
}

/* This routine is called when the thread that entered a SINGLE construct
   with a COPYPRIVATE clause gets to the end of the construct.  */

void
GOMP_single_copy_end (void *data)
{
  tomp_Thread *thr  = &tomp_thread;
  tomp_Team   *team = thr->ts->team;

  if (team != NULL)
    {
      thr->ts->work_share->copyprivate = data;
      tomp_waitAtBarrier(&team->barrier);
    }

  gomp_work_share_end_nowait ();
}
