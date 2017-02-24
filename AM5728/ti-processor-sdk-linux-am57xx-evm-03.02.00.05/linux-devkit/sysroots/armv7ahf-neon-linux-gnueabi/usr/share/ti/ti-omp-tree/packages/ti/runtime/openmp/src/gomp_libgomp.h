/* Copyright (C) 2005, 2007, 2008, 2009 Free Software Foundation, Inc.
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
   - Workshare related structures from original libgomp.h 
*/

/**
 * \file gomp_libgomp.h
 * 
 * \brief Declares gomp_schedule_type, gomp_work_share
 *
 * This file contains data types and function declarations that are not
 * part of the official OpenMP user interface.  There are declarations
 * in here that are part of the GNU OpenMP ABI, in that the compiler is
 * required to know about them and use them.
 *
 * The convention is that the all caps prefix "GOMP" is used group items
 * that are part of the external ABI, and the lower case prefix "gomp"
 * is used group items that are completely private to the library.  
 */

#ifndef LIBGOMP_H 
#define LIBGOMP_H 1

#include "gomp_ptrlock.h"   
#include <stdbool.h>                          /* for bool, false, true */
#include "tomp_defs.h"                        /* for TOMP_DEVICE_NUM_CORES */
#include "tomp_queues.h"                      /* for tomp_event_t */

/* This structure contains the data to control one work-sharing construct,
   either a LOOP (FOR/DO) or a SECTIONS.  */

enum gomp_schedule_type
{
  GFS_RUNTIME,
  GFS_STATIC,
  GFS_DYNAMIC,
  GFS_GUIDED,
  GFS_AUTO
};

struct gomp_work_share
{
  /* This member records the SCHEDULE clause to be used for this construct.
     The user specification of "runtime" will already have been resolved.
     If this is a SECTIONS construct, this value will always be DYNAMIC.  */
  enum gomp_schedule_type sched;

   int mode;

  union {
     struct {
        /* This is the chunk_size argument to the SCHEDULE clause.  */
        long chunk_size;

        /* This is the iteration end point.  If this is a SECTIONS construct,
           this is the number of contained sections.  */
        long end;

        /* This is the iteration step.  If this is a SECTIONS construct, this
           is always 1.  */
        long incr;
     };

     struct
     {
        /* The same as above, but for unsigned long long variants. */
        unsigned long long chunk_size_ull;
        unsigned long long end_ull;
        unsigned long long incr_ull;
     };
  };

  /* This is a circular queue that details which threads will be allowed
     into the ordered region and in which order.  When a thread allocates
     iterations on which it is going to work, it also registers itself at
     the end of the array.  When a thread reaches the ordered region, it
     checks to see if it is the one at the head of the queue.  If not, it
     blocks on its RELEASE semaphore.  */
  unsigned char ordered_team_ids[TOMP_DEVICE_NUM_CORES];

  /* This is the number of threads that have registered themselves in
     the circular queue ordered_team_ids.  */
  unsigned ordered_num_used;

  /* This is the team_id of the currently acknowledged owner of the ordered
     section, or -1u if the ordered section has not been acknowledged by
     any thread.  This is distinguished from the thread that is *allowed*
     to take the section next.  */
  unsigned ordered_owner;

  /* This is the index into the circular queue ordered_team_ids of the
     current thread that's allowed into the ordered reason.  */
  unsigned ordered_cur;

  /* The above fields are written once during workshare initialization,
     or related to ordered worksharing.  Make sure the following fields
     are in a different cache line.  */

  /* This lock protects the update of the following members.  */
  unsigned int lock;

  /* This is the count of the number of threads that have exited the work
     share construct.  If the construct was marked nowait, they have moved on
     to other work; otherwise they're blocked on a barrier.  The last member
     of the team to exit the work share construct must deallocate it.  */
  unsigned threads_completed;

  union {
    /* This is the next iteration value to be allocated.  In the case of
       GFS_STATIC loops, this the iteration start point and never changes.  */
    long next;

    /* The same, but with unsigned long long type. */
    unsigned long long next_ull;

    /* This is the returned data structure for SINGLE COPYPRIVATE.  */
    void *copyprivate;
  };

  /* Link to gomp_work_share struct for next work sharing construct
     encountered after this one.  */
  gomp_ptrlock_t next_ws;

  /* Event pointer to free the work share */
  tomp_event_t event;
};

/* These are the OpenMP 3.0 Internal Control Variables described in
   section 2.3.1.  Those described as having one copy per task are
   stored within the structure; those described as having one copy
   for the whole program are (naturally) global variables.  */

struct gomp_task_icv
{
  unsigned long nthreads_var;
  enum gomp_schedule_type run_sched_var;
  int run_sched_modifier;
  //Removing these
#if 0
  bool dyn_var;
  bool nest_var;
#endif
};

extern  struct gomp_task_icv gomp_global_icv;
extern  unsigned long gomp_thread_limit_var;
extern  unsigned long gomp_max_active_levels_var;

extern void initialize_env (void);

/* iter.c */

extern int gomp_iter_static_next (long *, long *);
extern bool gomp_iter_dynamic_next_locked (long *, long *);
extern bool gomp_iter_guided_next_locked (long *, long *);

/* iter_ull.c */

extern int gomp_iter_ull_static_next (unsigned long long *,
                                      unsigned long long *);
extern bool gomp_iter_ull_dynamic_next_locked (unsigned long long *,
                                               unsigned long long *);
extern bool gomp_iter_ull_guided_next_locked (unsigned long long *,
                                              unsigned long long *);

/* ordered.c */

extern void gomp_ordered_first (void);
extern void gomp_ordered_last (void);
extern void gomp_ordered_next (void);
extern void gomp_ordered_static_init (void);
extern void gomp_ordered_static_next (void);
extern void gomp_ordered_sync (void);

/* work.c */

extern void gomp_init_work_share (struct gomp_work_share *, bool, unsigned);
extern void gomp_fini_work_share (struct gomp_work_share *);
extern bool gomp_work_share_start (bool);
extern void gomp_work_share_end (void);
extern void gomp_work_share_end_nowait (void);

extern void gomp_work_share_init_done (void);

#endif /* LIBGOMP_H */
