/*
 * Copyright (c) 2014, Texas Instruments Incorporated - http://www.ti.com/
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
 * \file tomp_util.h
 * 
 * \brief This file defines utility functions, types, variables and constants
 */


#ifndef _tomp_util_h_
#define _tomp_util_h_

#include "tomp_defs.h"
#include "tomp_config.h"
#include "tomp_log.h"

#include <stdint.h>
#include <stdbool.h>

#include <ti/csl/csl_chip.h>
#include <ti/csl/csl_cache.h>
#include <ti/csl/csl_cacheAux.h>
#if TOMP_DEVICE_HAS_XMC
#include <ti/csl/csl_xmc.h>
#include <ti/csl/csl_xmcAux.h>
#endif
#if TOMP_DEVICE_HAS_HW_SEMAPHORES
#include <ti/csl/csl_semAux.h>
#endif

/** 
 *  Represents a barrier
 *  @see tomp_waitAtBarrier
 */
typedef struct _tomp_Barrier
{
    //! Counter initialized to number of threads that will reach the barrier
    //! Each thread decrements this count when it reaches the barrier
    volatile unsigned int count;

    //! Total number of threads
    volatile unsigned int size;

    //! Usefull for the re-use of the barrier
    volatile unsigned int sense;

} tomp_Barrier;

extern void tomp_completePendingTasks();

// Convert local address to global address.
static inline uint32_t tomp_makeAddressGlobal(uint32_t core_idx, 
                                              uint32_t address)
{
#if defined(TI_AM572)
    if (address < 0x01000000)
    {
        if (core_idx == 0)
        {
           // dsp1_l2_sram 0x4080_0000 - 0x4084_7fff
           address = 0x40800000 | (address & 0x000FFFFF);
        } 
        else if (core_idx == 1)
        {
           // dsp2_l2_sram 0x4100_0000 - 0x4104_7fff
           address = 0x41000000 | (address & 0x000FFFFF);
        } 
    }
#else
    if (address < 0x01000000)
    {
        // Mask: 0x00****** => 0x1"core_idx"******
        address = (0x10 + core_idx) << 24 | address;
    }
#endif

    return address;
}

// Wait until data written to memory
static inline void tomp_mfence(void)
{
    // In order to accurately trace mfence instructions, a nop and mark 
    // instruction must follow each mfence instruction 
    asm (" mfence ");
    asm(" nop ");
    asm(" mark 0");
    asm (" mfence ");  // 2nd MFENCE as per Keystone I FAE Alert
    asm(" nop ");
    asm(" mark 0");

    // sprz332b.pdf, Advisory 24 - Require 16 NOPs after MFENCE after certain
    // cache coherency operations
    asm(" nop 9");  
    asm(" nop 7");
}

// Invalidate the XMC Prefetch Buffer
static inline void tomp_invalidatePrefetchBuffer(void)
{
#if TOMP_DEVICE_HAS_XMC
    CSL_XMC_invalidatePrefetchBuffer();
#endif
    return;
}

#if defined(TI_AM572)
#define ADDR_SPINLOCK(idx) ((volatile uint32_t *) (0x4A0F6800 + 4 * idx))

static inline bool AcquireSpinLock(unsigned int idx)
{
   return (((*ADDR_SPINLOCK(idx)) & 0x1) == 0);
}

static inline void ReleaseSpinLock(unsigned int idx)
{
   *ADDR_SPINLOCK(idx) = 0;
}
#endif

// Acquire Semaphore
static inline bool tomp_semAcquire(unsigned int sem)
{
#if TOMP_DEVICE_HAS_HW_SEMAPHORES
    return CSL_semAcquireDirect(sem);
#endif

#if TOMP_DEVICE_HAS_HW_SPINLOCKS
    return AcquireSpinLock(sem);
#endif
}

// Release Semaphore
static inline void tomp_semRelease(unsigned int sem)
{
#if TOMP_DEVICE_HAS_HW_SEMAPHORES
    CSL_semReleaseSemaphore(sem);
#endif

#if TOMP_DEVICE_HAS_HW_SPINLOCKS
    return ReleaseSpinLock(sem);
#endif
}

// Write back and invalidate all L1 cache
static inline void tomp_cacheWbInvAllL1d (void)
{
    uint32_t lvInt = _disable_interrupts();
    CACHE_wbInvAllL1d(CACHE_NOWAIT);
    tomp_mfence();
    tomp_invalidatePrefetchBuffer();
    tomp_mfence();
    _restore_interrupts(lvInt);
    return;
}


// Write back and invalidate all L2 cache
static inline void tomp_cacheWbInvAll (void)
{
    uint32_t lvInt = _disable_interrupts();
    CACHE_wbInvAllL1d(CACHE_NOWAIT);
    tomp_mfence();
    if (CACHE_getL2Size() > 0)
        CACHE_invAllL2(CACHE_NOWAIT);
    tomp_invalidatePrefetchBuffer();
    tomp_mfence();
    _restore_interrupts(lvInt);
    return;
}

// Write back and invalidate L1D specific block
static inline void tomp_cacheWbInv 
(
    void*       blockPtr,
    Uint32      byteCnt)
{
    uint32_t lvInt = _disable_interrupts();
    if (((uint32_t)blockPtr) & 0x80000000)
        CACHE_wbInvL2(blockPtr,byteCnt,CACHE_NOWAIT);
    else
    	CACHE_wbInvL1d(blockPtr,byteCnt,CACHE_NOWAIT);
    tomp_invalidatePrefetchBuffer();
    tomp_mfence();
    _restore_interrupts(lvInt);
    return;
}

static inline void tomp_cacheInv (void* blockPtr, Uint32 byteCnt)
{
    uint32_t lvInt = _disable_interrupts();
    if (((uint32_t)blockPtr) & 0x80000000)
        CACHE_invL2(blockPtr,byteCnt,CACHE_NOWAIT);
    else
    	CACHE_invL1d(blockPtr,byteCnt,CACHE_NOWAIT);
    tomp_invalidatePrefetchBuffer();
    tomp_mfence();
    _restore_interrupts(lvInt);
    return;
}


/**
 * Atomic decrement of an integer value stored in non-cacheable memory
 * @param ptr pointer to location with value
 */
static inline unsigned int tomp_decrementAtomic(volatile unsigned int *ptr)
{
   while ((tomp_semAcquire(TOMP_ATOMIC_HW_SEM_IDX)) == 0);
   unsigned int oldval = *ptr;
   *ptr -= 1;
   tomp_mfence();
   tomp_semRelease(TOMP_ATOMIC_HW_SEM_IDX);
   return oldval;
}

/**
 * Atomic increment of an integer value stored in non-cacheable memory
 * @return Value after the increment
 */
static inline unsigned int tomp_incrementAtomic(volatile unsigned int *ptr)
{
    while ((tomp_semAcquire(TOMP_ATOMIC_HW_SEM_IDX)) == 0);
    unsigned int newval;
    *ptr += 1;
    newval = *ptr;
    tomp_mfence();
    tomp_semRelease(TOMP_ATOMIC_HW_SEM_IDX);
    return newval;
}


/**
 * Initializes tomp_Barrier
 * @param barrier pointer to barrier
 * @param ntheads number of threads involved in the barrier
 */
static inline void tomp_initBarrier(tomp_Barrier *barrier, unsigned int nthreads)
{
	barrier->count = nthreads;
	barrier->size = nthreads;
	barrier->sense = 0;
}

/**
 * Wait for a certain number of threads to reach this point. The number of
 * threads is specified by barrier->size.
 */
static inline void tomp_waitAtBarrier(tomp_Barrier *barrier)
{
    // Complete any pending tasks. Implicit and explicit barriers are task
    // synchronization points.
    tomp_completePendingTasks();
 
    // For re-use reason, the barrier contains a sense variation
    unsigned int mysense = !(barrier->sense);

    // Pass only if it's the last thread
    if (tomp_decrementAtomic(&barrier->count) == 1)
    {
        // Reset of the barrier
        barrier->count = barrier->size;
        barrier->sense = !(barrier->sense);
    }
    else
    {
        // A modification of the sense represents the end of the barrier
        // Check for pending tasks and execute them when waiting
        while (mysense != barrier->sense)
            tomp_completePendingTasks();
    }
}

/**
 * OpenMP barrier including the implicit flush.                
 * @param barrier Team barrier location
 */
static inline tomp_waitAtBarrierWithFlush(tomp_Barrier *barrier)
{
    // Wait for all writes to land before exiting the barrier. Will ensure
    // that inadvertent reads of shared variables by worker cores when
    // executing runtime code will pull in updated values into their
    // caches.
    tomp_mfence();

    // Wait for other threads on the team to reach the barrier. Will also
    // execute any pending tasks
    tomp_waitAtBarrier(barrier);
    
    // OMP v3.0, 2.8.6, p75: Implied flush at exit from parallel region
    // Flush AFTER all threads have reached the barrier. This handles a 
    // corner case where a shared variable on the stack is on the same 
    // cache line as the location of return address on the stack. The read 
    // of the return address during function epilog also reads in the 
    // shared variable into the cache and marks it as valid. Because of 
    // this inadvertent read of the shared variable, we need to ensure that 
    // writes to the shared variable from all threads have landed before 
    // we perform the flush.
    tomp_cacheWbInvAll();
}

void tomp_waitAtCoreBarrier(void);
void *tomp_allocInitTLSBlock(void);

/**
 * Wrapper for acquiring a hardware semaphore. Cannot be nested
 * @param lock Index to the Hardware Semaphore used
 */
static inline void tomp_mutex_lock(unsigned int lock)
{
    while ((tomp_semAcquire(lock)) == 0);
}

/**
 * Wrapper for releasing a hardware semaphore. Does an mfence before release
 * to ensure that writes initiated in the critical section have landed.
 * @param lock Index to the Hardware Semaphore used
 */
static inline void tomp_mutex_unlock(unsigned int lock)
{
    tomp_mfence(); /* To ensure writes have landed in memory */
    tomp_semRelease(lock);
}


/** 
 * Returns true if ptr points to an object in cached memory
 */
static inline bool tomp_isPtrCached(void *ptr)
{
    volatile uint32_t *MAR = (volatile uint32_t *)MAR_ADDRESS_BASE;

    // Compute the MAR index for the pointer
    int idx = (uint32_t)ptr >> 24;

    // Need to special case L2SRAM as this space could be mapped to a 
    // global address space by ORing with (DNUM + 16) << 24. 
    // The MAR indices corresponding to this global space are invalid.
    // Assumption: any variable in L2SRAM scratch is cached in L1
    if ((idx & (~(DNUM + 16))) == 0)
        return true;

    // if bit 0 (PC) of the MAR is 1, the address has caching enabled
    if (MAR[idx] & 0x1) 
        return true;

    return false;
}

static inline void acquire_dsp_heap_lock()
{
    while ((tomp_semAcquire(TOMP_MALLOC_HW_SEM_IDX)) == 0);
}

static inline void release_dsp_heap_lock()
{
    tomp_mfence();
    tomp_semRelease(TOMP_MALLOC_HW_SEM_IDX);
}

static inline void acquire_dsp_queue_lock()
{
    while ((tomp_semAcquire(TOMP_QUEUES_HW_SEM_IDX)) == 0);
}

static inline void release_dsp_queue_lock()
{
    tomp_mfence();
    tomp_semRelease(TOMP_QUEUES_HW_SEM_IDX);
}

extern unsigned int __TI_get_DP(void);
extern void         __TI_set_DP(unsigned int new_DP);

#endif /* _tomp_util_h_ */
