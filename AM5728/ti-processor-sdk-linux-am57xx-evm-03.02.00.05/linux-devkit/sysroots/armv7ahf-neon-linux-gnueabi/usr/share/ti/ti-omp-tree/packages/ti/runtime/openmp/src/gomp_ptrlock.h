/* Copyright (C) 2008, 2009 Free Software Foundation, Inc.
   Contributed by Jakub Jelinek <jakub@redhat.com>.

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

   Using a Hardware Semaphore to implement mutex lock/unlock
*/
   

#ifndef GOMP_PTRLOCK_H
#define GOMP_PTRLOCK_H 1

#include "tomp_util.h"

typedef struct { void *ptr; volatile unsigned int lock; } gomp_ptrlock_t;

static inline void gomp_ptrlock_init (gomp_ptrlock_t *ptrlock, void *ptr)
{
  ptrlock->ptr = ptr;
  ptrlock->lock = TOMP_WS_HW_SEM_IDX;
}

static inline void *gomp_ptrlock_get (gomp_ptrlock_t *ptrlock)
{
  if (ptrlock->ptr != NULL)
    return ptrlock->ptr;

  /* First thread to hit this point from gomp_loop_*_start acquires the lock
   * All remaining threads will sit and
   * spin here waiting for the lock to be released by the first thread
   * via gomp_ptrlock_set
   */
  tomp_mutex_lock (ptrlock->lock);
  if (ptrlock->ptr != NULL)
    {
      tomp_mutex_unlock (ptrlock->lock);
      return ptrlock->ptr;
    }

  return NULL;
}

static inline void gomp_ptrlock_set (gomp_ptrlock_t *ptrlock, void *ptr)
{
  ptrlock->ptr = ptr;
  tomp_mutex_unlock (ptrlock->lock);
}

static inline void gomp_ptrlock_destroy (gomp_ptrlock_t *ptrlock)
{
  /* Nothing to do here */
}

#endif /* GOMP_PTRLOCK_H */
