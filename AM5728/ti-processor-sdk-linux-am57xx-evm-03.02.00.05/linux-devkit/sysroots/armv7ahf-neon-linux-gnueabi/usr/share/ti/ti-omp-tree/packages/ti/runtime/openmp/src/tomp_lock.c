/*
 * Copyright (c) 2013, Texas Instruments Incorporated - http://www.ti.com/
 *   All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *      * Redistributions of source code must retain the above copyright
 *        notice, this list of conditions and the following disclaimer.
 *      * Redistributions in binary form must reproduce the above copyright
 *        notice, this list of conditions and the following disclaimer in the
 *        documentation and/or other materials provided with the distribution.
 *      * Neither the name of Texas Instruments Incorporated nor the
 *        names of its contributors may be used to endorse or promote products
 *        derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * \file tomp_lock.c
 * 
 * \brief Implements the OMP locking APIs
 *      
 */

#include "tomp_parallel.h"
#include "omp.h"


/**
 * Allocate the lock variable and initialize it to an unlocked state. Also, no
 * task owns the lock.
 * @param lock ptr to variable of type omp_lock_t
 */
void omp_init_lock (omp_lock_t* lock)
{
    *lock = (omp_lock_t) memalign(CACHE_L2_LINESIZE, CACHE_L2_LINESIZE);

    // Updates to lock do not have to be in a critical section because only 
    // one thread should call omp_init_lock() at a time, and a lock should 
    // be initalized before it is accessed.
    (*lock)->entered    = false;
    (*lock)->owner_task = NULL;
    (*lock)->count      = 0;
    (*lock)->hw_sem     = TOMP_LOCK_HW_SEM_IDX;
    // Ensure that writes land to memory before exit. We assume the heap is 
    // write-through, so there is no need to writeback.
    tomp_mfence();
}

/**
 * Free storage associated with the lock variable
 * @param lock ptr to variable of type omp_lock_t
 */
void omp_destroy_lock (omp_lock_t *lock)
{
    free(*lock);
}

/**
 * Set the lock
 * @param lock ptr to variable of type omp_lock_t
 */
void omp_set_lock (omp_lock_t* lock)
{
    
    // To ensure that we are accessing the current version of a shared lock, 
    // we must invalidate any local copy of lock. 
    tomp_cacheInv(*lock, sizeof(omp_lock_t));

    // Spin while the lock is held by another thread. INV lock while spinning 
    // to ensure that we have the current version of lock.
    while ((*lock)->entered)
    {
        tomp_cacheInv(*lock, sizeof(omp_lock_t));
    }
    
    // the lock is potentially available now
    while (1)
    {
        // Only one thread can set/unset a lock at a time. Therefore, these 
        // updates to lock must be within a critical section.
        tomp_mutex_lock((*lock)->hw_sem);

        // INV again in case lock was set by another thread before this point.
        tomp_cacheInv(*lock, sizeof(omp_lock_t));

        // check if the lock is still available
        if ((*lock)->entered == false)
        {
            (*lock)->entered = true;
            (*lock)->owner_task = tomp_thread.current_task;

            tomp_mutex_unlock ((*lock)->hw_sem);

            // OMP v3.0, 2.8.6
            // * During omp_set_lock and omp_set_unlock regions
            // * During omp_test_lock,... if the region causes the lock 
            //   to be set or unset
            tomp_cacheWbInvAll();
            return;
        }
        else
        {
            tomp_mutex_unlock ((*lock)->hw_sem);

            // spin again while the lock is held by another thread
            while ((*lock)->entered)
            {
                tomp_cacheInv(*lock, sizeof(omp_lock_t));
            }
        }
    }  // while(1)
}

/**
 * Attempt to set the lock
 * @param lock ptr to variable of type omp_lock_t
 * @returns 1 if the lock is successfully set, 0 otherwise
 */
int omp_test_lock (omp_lock_t* lock)
{
    // To ensure that we are accessing the current version of a shared lock, 
    // we must invalidate any local copy of lock. 
    tomp_cacheInv(*lock, sizeof(omp_lock_t));
    if ((*lock)->entered)
        return 0;
    else
    {
        omp_set_lock(lock);
        return 1;
    }
}


/**
 * Unset the lock
 * @param lock ptr to variable of type omp_lock_t
 */
void omp_unset_lock (omp_lock_t* lock)
{    
    // It is not necessary to INV lock first because the task that sets a
    // lock must unset it, and this task always resides on the same core.
    // Only one thread can set/unset a lock at a time. Therefore these 
    // updates to lock must be within a critical section.
    tomp_mutex_lock ((*lock)->hw_sem);
    (*lock)->entered = false;
    (*lock)->owner_task = NULL;

    tomp_mutex_unlock ((*lock)->hw_sem);
    // OMP v3.0, 2.8.6
    // * During omp_set_lock and omp_set_unlock regions
    // * During omp_test_lock,... if the region causes the lock 
    //   to be set or unset
    tomp_cacheWbInvAll();
}


/**
 * Initialize the nested lock and set nesting count to 0
 * @param lock ptr to variable of type omp_nest_lock_t
 *
 * @see omp_init_lock
 */
void omp_init_nest_lock (omp_nest_lock_t* lock)
{
    omp_init_lock(lock);
}


/**
 * Free storage associated with the lock variable
 * @param lock ptr to variable of type omp_nest_lock_t
 */
void omp_destroy_nest_lock (omp_nest_lock_t* lock)
{
   omp_destroy_lock(lock);
}


/** 
 * Set the nested lock.
 * @param lock ptr to variable of type omp_nest_lock_t
 */ 
void omp_set_nest_lock (omp_nest_lock_t* lock)
{
    // Invalidate local copy of lock to ensure that we access the current 
    // copy of lock. In particular, it is possibile that owner_task has
    // been set by another task.
    tomp_cacheInv(*lock, sizeof(omp_lock_t));
    // If the lock is not owned by the task executing the routine, set it
    if ((*lock)->owner_task != tomp_thread.current_task)
        omp_set_lock(lock);

    // Task already owns the lock - increment the nesting count. A critical 
    // section is not required to protect this operation because only the 
    // owning task can increment count.
    ++(*lock)->count;
}


/**
 * Attempt to set the nested lock
 * @param lock ptr to variable of type omp_nest_lock_t
 * @returns The new nesting count if the lock is successfully set, 0 otherwise
 */
int  omp_test_nest_lock (omp_nest_lock_t* lock)
{
    // Invalidate local copy of lock to ensure that we access the current 
    // copy of lock.
    tomp_cacheInv(*lock, sizeof(omp_lock_t));
    if ((*lock)->owner_task != tomp_thread.current_task)
    {
        if (omp_test_lock(lock) == 0)
            return 0;
    }

    // A critial section is not required to protect this operation because 
    // only the owning task can increment count.
    ++(*lock)->count;

    // Ensure writes land before exiting 
    tomp_mfence();
    
    return (*lock)->count;
}


/**
 * Decrement the nesting count and unset if resulting count is 0
 * @param lock ptr to variable of type omp_nest_lock_t
 */
void omp_unset_nest_lock (omp_nest_lock_t* lock)
{  
    // It is not necessary to INV lock first because the task that sets a
    // lock must unset it, and this task always resides on the same core.
    // Decrement the nesting count. A critial section is not required to 
    // protect this operation because only the owning task can increment 
    // count.
    (*lock)->count--;

    // If nesting count is 0, unset the lock
    if ((*lock)->count == 0)
        omp_unset_lock(lock);
}

