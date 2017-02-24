/******************************************************************************
 * Copyright (c) 2014, Texas Instruments Incorporated - http://www.ti.com/
 *   All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions are met:
 *       * Redistributions of source code must retain the above copyright
 *         notice, this list of conditions and the following disclaimer.
 *       * Redistributions in binary form must reproduce the above copyright
 *         notice, this list of conditions and the following disclaimer in the
 *         documentation and/or other materials provided with the distribution.
 *       * Neither the name of Texas Instruments Incorporated nor the
 *         names of its contributors may be used to endorse or promote products
 *         derived from this software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 *   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 *   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 *   THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/
/**
 * \file omp.h
 *
 * \brief OMP header file to include in OpenMPAcc user applications
 */

#ifndef OMP_H_
#define OMP_H_

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#include <stdint.h>
#include <stdlib.h>

/* Lock type */
typedef struct _omp_lock
{
    volatile int  entered;
    void         *owner_task;
    volatile int  count;
    int           hw_sem;
} *omp_lock_t;

typedef struct _omp_lock *omp_nest_lock_t;

/* Schedule kinds */
typedef enum omp_sched_t
{
  omp_sched_static = 1,
  omp_sched_dynamic = 2,
  omp_sched_guided = 3,
  omp_sched_auto = 4
} omp_sched_t;

/* Execution environment routines */
void omp_set_num_threads (int nthreads);
int omp_get_num_threads (void);
int omp_get_max_threads (void);
int omp_get_thread_num (void);
int omp_get_num_procs(void);
int omp_in_parallel(void);
void omp_set_dynamic (int nthreads);
int omp_get_dynamic (void);
void omp_set_nested (int val);
int omp_get_nested (void);
void omp_set_schedule (omp_sched_t kind, int modifier);
void omp_get_schedule (omp_sched_t *kind, int *modifier);
int omp_get_thread_limit (void);
void omp_set_max_active_levels(int val);
int omp_get_max_active_levels(void);
int omp_get_level (void);
int omp_get_ancestor_thread_num (int level);
int omp_get_team_size (int level);
int omp_get_active_level (void);
void omp_set_default_device (int device_num);
int omp_get_default_device (void);
int omp_get_num_devices (void);
int omp_is_initial_device (void);
#if 0
int omp_in_final (void);
#endif

/* Lock Routines */
void omp_init_lock (omp_lock_t* lock);
void omp_destroy_lock (omp_lock_t *lock);
void omp_set_lock (omp_lock_t* lock);
int  omp_test_lock (omp_lock_t* lock);
void omp_unset_lock (omp_lock_t* lock);

void omp_init_nest_lock (omp_nest_lock_t* lock);
void omp_destroy_nest_lock (omp_nest_lock_t *lock);
void omp_set_nest_lock (omp_nest_lock_t* lock);
int  omp_test_nest_lock (omp_nest_lock_t* lock);
void omp_unset_nest_lock (omp_nest_lock_t* lock);

/* Timing Routines */
double omp_get_wtime (void);
double omp_get_wtick (void);

/*-----------------------------------------------------------------------------
* The extended TI built-in function set
*----------------------------------------------------------------------------*/
void     __touch           (const char *p, uint32_t size);
uint32_t __core_num        (void);
uint32_t __clock           (void);
uint64_t __clock64         (void);
void     __cycle_delay     (uint64_t cyclesToDelay);
void     __mfence          (void);

void     __cache_l1d_none  (void);
void     __cache_l1d_all   (void);
void     __cache_l1d_4k    (void);
void     __cache_l1d_8k    (void);
void     __cache_l1d_16k   (void);
void     __cache_l1d_flush (void);

void     __cache_l2_none   (void);
void     __cache_l2_128k   (void);
void     __cache_l2_256k   (void);
void     __cache_l2_512k   (void);
void     __cache_l2_flush  (void);

void     __heap_init_ddr  (void *ptr, size_t size);
void*    __malloc_ddr     (size_t size);
void*    __calloc_ddr     (size_t num, size_t size);
void*    __realloc_ddr    (void *ptr,  size_t size);
void     __free_ddr       (void *ptr);
void*    __memalign_ddr   (size_t alignment, size_t size);

void     __heap_init_msmc (void *ptr, size_t size);
void*    __malloc_msmc    (size_t size);
void*    __calloc_msmc    (size_t num, size_t size);
void*    __realloc_msmc   (void *ptr, size_t size);
void     __free_msmc      (void *ptr);
void*    __memalign_msmc  (size_t alignment, size_t size);

void     __heap_init_l2   (void *ptr, size_t size);
void*    __malloc_l2      (size_t size);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* OMP_H_ */
