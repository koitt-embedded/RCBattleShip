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
 * \file omp_init.c
 * 
 * \brief Implements function hooks to initialize the runtime during boot
 *
 * Functions implemented:
 *   __TI_omp_initialize
 *   __TI_omp_start
 */

#include <setjmp.h>
#include <stdlib.h>

#include "tomp_util.h"
#include "tomp_log.h"
#include "tomp_parallel.h"
#include "tomp_queues.h"
#include "omp.h"
#include "tomp_init.h"

#if TOMP_DEVICE_HAS_MSMC
#include <ti/csl/csl_msmc.h>
#include <ti/csl/csl_msmcAux.h>
#endif
#include <ti/csl/csl_emif4fAux.h>

#define L2SRAM_START_ADDR       (0x00800000) 

/** MAR register bits to enable caching/prefetch/write-through */
#define CACHE_DISABLE   (0x0)
#define CACHE_PC        (0x1)
#define CACHE_WTE       (0x2)
#define CACHE_PFX       (0x8)


extern cregister volatile unsigned int DNUM;

/** Configuration structure */
#pragma DATA_SECTION (tomp_gvCoreConfig, ".tomp_gvMem");
tomp_CoreConfig tomp_gvCoreConfig;

static void switchL2SpToGlobal(void);
static void tomp_setMAR(unsigned int start, unsigned int length, 
                        unsigned int val);

extern void __TI_omp_configure(void);

extern far int _args_main();
extern void __TI_switch_sp(int new_sp, void *fn);
extern void __TI_omp_terminate(void);


void tomp_entry_func(void)
{
    if (DNUM == TOMP_MASTER_CORE_IDX)
    {
        #pragma diag_suppress 238
        ulm_put_state(ULM_STATE_RUN);
        #pragma diag_default 238

        _args_main();
        __TI_omp_terminate();
        exit(1);
    }
    else
    {
        #pragma diag_suppress 238
        ulm_put_state(ULM_STATE_IDLE);
        #pragma diag_default 238

        // Never returns. Worker cores exit when they get an exit event
        while(1) 
            tomp_dispatch_once();
    }
}

void __TI_omp_start(void)
{
    tomp_OmpStartCommon(&tomp_entry_func);
}

void tomp_OmpStartCommon(tomp_EntryFunc fn)
{
    int new_sp_start = 0;

    if (tomp_gvCoreConfig.thread_stack_from_heap)
    {
        int stack_size   = tomp_gvCoreConfig.thread_stack_size;
        int new_sp_end   = 0;

        new_sp_start = (int)malloc(stack_size);

        if (new_sp_start == NULL)
            tomp_logErrorStr(tomp_ErrorKind_NULL_PTR, 
                    "Heap not large enough for thread stacks",
                    __FILE__, __LINE__);

        new_sp_end   = (new_sp_start+stack_size-4) & ~7;
        __TI_switch_sp(new_sp_end, (void *)fn);
    }
    else
        (*fn)();
    
    // TODO: Only the master core gets here. Worker cores need to free
    // thread_stack_heap in their local exit function
    if (tomp_gvCoreConfig.thread_stack_from_heap)
        free((void *)new_sp_start);
}


/**
 * Initializes the OMP runtime. Invoked after cinit.
 * see @boot.c
 */
int __TI_omp_initialize (void)
{
    // Configures the # cores available to the runtime and the DNUM of the
    // master core (TOMP_MASTER_CORE_IDX). Needs to happen before any 
    // references to TOMP_MASTER_CORE_IDX
    __TI_omp_configure();

    // In OpenMP mode, all cores will set DP before OMP runtime startup.
    // The runtime does not need to update DP on worker cores.
    TOMP_UPDATE_DP = 0;

    tomp_switchL2SpToGlobal();

    tomp_waitAtCoreBarrier();

    if (!tomp_ompInitCommon())
        return -1;

    return 0;
}


/**
 * Initialization steps shared in RTSC and bare-metal modes.
 */
bool tomp_ompInitCommon(void)
{
#if TOMP_DEVICE_HAS_HW_QUEUES
    /* QMSS memories are not cacheable 
     * - Keystone I  devices: MAR52 : 0x34xx_xxxx
     * - Keystone II devices: MAR35 : 0x23xx_xxxx 
     */
#ifdef TI_C6636
    CACHE_disableCaching(35);
    CACHE_setMemRegionInfo(35, 0, 0);
#else
    CACHE_disableCaching(52);
    CACHE_setMemRegionInfo(52, 0, 0);
#endif

#endif // TOMP_DEVICE_HAS_HW_QUEUES

    if (DNUM == TOMP_MASTER_CORE_IDX)
    {

        if (!tomp_initGlobalNRT(/*memRegionInitialized=*/false))
            tomp_logError(tomp_ErrorKind_QMSS, __FILE__, __LINE__);
    }

    // Wait for master core to perform global NRT initialization before
    // performing local NRT initialization
    tomp_waitAtCoreBarrier();

    if (!tomp_initLocalNRT()) 
        return false;

#if 0
    // QMSS LObj is in shared memory! It must be mapped to local memory!
    // Workaround: Invalidate caches after qmssLobj is initialized in
    // tomp_initLocalNRT
    tomp_waitAtCoreBarrier();
    tomp_cacheWbInvAll();
#endif

    if (tomp_initLocal() < 0) 
        return false;

    if (DNUM == TOMP_MASTER_CORE_IDX)
    {
        if (tomp_initParallel() < 0)
            tomp_logError(tomp_ErrorKind_OMP_INIT, __FILE__, __LINE__);

        //Initialize OpenMP ICVs from environment variables
        initialize_env();
        tomp_initIcv();
    }

    return true;
}


/**
 * If OpenMP thread stacks are in L2SRAM, switch SP to global address,
 * update MAR bit to disable caching of this range and wb-invalidate L1.
 */
void tomp_switchL2SpToGlobal(void)
{
    if (!TOMP_THREAD_STACK_IN_L2) return;

#if 0
    // Disable caching for the master core's L2 SRAM global address range.
    // This prevents coherence issues when thread stacks are in local memory, 
    // since the master core's stack may be shared and accessed by other 
    // threads.
    uint32_t address = tomp_makeAddressGlobal(TOMP_MASTER_CORE_IDX, 
                                              L2SRAM_START_ADDR);
    tomp_setMAR(address, CACHE_getL2Size(), 0);
#endif

    switchL2SpToGlobal();

    // wbInv L1 cache to remove any stack variables cached previously
    tomp_cacheWbInvAllL1d();
}


/**
 * Switches SP (in L2) from local to global address. 
 *
 * The global address allows other cores to access a given core's L2. 
 * This enables local variables on the stack to be shared, a requirement 
 * for OpenMP
 */
static void switchL2SpToGlobal(void)
{
    jmp_buf env;

    // Save the environment
    if(setjmp(env) == 0)
    {
        int sp;
        // env[11] = stack pointer
        sp = env[11] & ((int) 0x00FFFFFF);
        // Change SP from local to global (adresses can be read by all cores)
        sp = tomp_makeAddressGlobal(DNUM, sp);
        env[11] = sp;
        // Apply the modification
        longjmp(env, 1);
    }
}


/**
 * Setup MAR registers corresponding to the memory range provided
 * @param start start of the address range
 * @param length length of the address range
 * @param val value to write to the MAR register(s)
 */
void tomp_setMAR(unsigned int start, unsigned int length, unsigned int val)
{
    volatile uint32_t *MAR = (volatile uint32_t *)MAR_ADDRESS_BASE;

    /* 1 MAR register corresponds to 16MB of memory */
    if (length < 0x01000000) length = 0x01000000;

    length = (start + length) >> 24;
    start >>= 24;

    int i;
    for (i = start; i < length; ++i) MAR[i] = val;
}


/** \defgroup omp_config_helper OMP Runtime Configuration Helper Functions */
/* @{ */

void __TI_omp_configure_caches(void)
{
    /* Default initial configure for caches, can be changed later */
    CACHE_setL1DSize(CACHE_L1_32KCACHE);
    CACHE_setL1PSize(CACHE_L1_32KCACHE);
    CACHE_setL2Size(CACHE_128KCACHE);
}

void __TI_omp_enable_caching(unsigned int start, unsigned int length)
{
    tomp_setMAR(start, length, CACHE_PC|CACHE_PFX|CACHE_WTE);
}

void __TI_omp_disable_caching(unsigned int start, unsigned int length)
{
    tomp_setMAR(start, length, CACHE_DISABLE);
}

/** 
 * Configure an MPAX register
 * @param mpax_id MPAX register id
 * @param base_addr Address range to match in C66x native 32b address space
 * @param replacement_addr Replace/extend the bits in base_addr
 * @param seg_size_encoding Encoded segment size
 */
void __TI_setMPAX(unsigned int mpax_id, unsigned int base_addr, 
                         unsigned long long replacement_addr,
                         unsigned int seg_size_encoding)
{
#if TOMP_DEVICE_HAS_XMC
    CSL_XMC_XMPAXH lvMpaxh;
    CSL_XMC_XMPAXL lvMpaxl;

    lvMpaxh.segSize = seg_size_encoding; 
    lvMpaxh.bAddr = base_addr >> 12;
    CSL_XMC_setXMPAXH(mpax_id,&lvMpaxh);
    lvMpaxl.ux = 1;
    lvMpaxl.uw = 1;
    lvMpaxl.ur = 1;
    lvMpaxl.sx = 1;
    lvMpaxl.sw = 1;
    lvMpaxl.sr = 1;
    lvMpaxl.rAddr = replacement_addr >> 12;
    CSL_XMC_setXMPAXL(mpax_id,&lvMpaxl);
#endif
}

/**
 * Configure location of Thread Stacks 
 *
 * Must be called from within __TI_omp_configure. By default, thread stacks
 * are placed in on chip local memory (L2 SRAM). Use this function to 
 * indicate that thread stacks must be placed in memory allocated from the 
 * heap.
 * @param from_heap Set to 1 to allocate thread stacks from the heap
 * @param size If from_heap is set to 1, specify the size of stack to allocate
 */
void __TI_omp_config_thread_stack(char from_heap, unsigned int size)
{
    tomp_gvCoreConfig.thread_stack_from_heap = from_heap;
    tomp_gvCoreConfig.thread_stack_size      = size;
}


/** 
 * Configure number of cores available to OpenMP runtime and the index of the
 * master core.
 *
 * Must be called from within __TI_omp_configure.
 *
 * @param master_core_idx Index of the master core
 * @param num_cores  Number of cores participating in the runtime 
 */
void __TI_omp_config_cores (unsigned char master_core_idx, 
                            unsigned char num_cores)
{
    tomp_gvCoreConfig.master_core_idx = master_core_idx;
    tomp_gvCoreConfig.num_cores       = num_cores;
}


/** 
 * Configure location of hardware queues used by Open Event Machine
 *
 * Must be called from within __TI_omp_configure.
 *
 * @param init_qmss
 * Set to 1 if OpenMP runtime must initialize QMSS sub-system. This is the
 * typical case. Set to 0 only if the application will initialize QMSS.
 * @param hw_queue_base_idx 
 * QMSS general purpose queue base index for OpenMP
 * processing. OpenMP requires 11 queues.
 * @param first_desc_idx_in_linking_ram
 * Index of linking ram entry to be used by OpenMP
 * @param first_memory_region_idx
 * Index of the first memory region to be used by OpenMP
 */
#ifdef TOMP_DEVICE_HAS_HW_QUEUES
void __TI_omp_config_hw_queues (char init_qmss,
                                int  hw_queue_base_idx,
                                int  first_desc_idx_in_linking_ram,
                                int  first_memory_region_idx)
{
    TOMP_INIT_QMSS                           = init_qmss;
    TOMP_HW_QUEUE_BASE_IDX                   = hw_queue_base_idx;
    TOMP_QMSS_FIRST_DESC_IDX_IN_LINKING_RAM  = first_desc_idx_in_linking_ram;
    TOMP_QMSS_FIRST_MEMORY_REGION_IDX        = first_memory_region_idx;
}
#endif // TOMP_DEVICE_HAS_HW_QUEUES


/** 
 * Configure hardware semaphores available to OpenMP runtime. 
 *
 * Must be called from within __TI_omp_configure.
 *
 * @param hw_sem_base_idx Index of the first semaphore. The runtime will use
 *                        6 semaphores starting at hw_sem_base_idx
 */
void __TI_omp_config_hw_semaphores(unsigned char hw_sem_base_idx)
{
    tomp_gvCoreConfig.hw_sem_base_idx = hw_sem_base_idx;
}

/** 
 * Configure the device core frequency. This is used by the OpenMP runtime 
 * timing functions.
 *
 * Must be called from within __TI_omp_configure.
 *
 * @param clock_freq Frequency of the cores
 */
void __TI_omp_config_clock_freq_in_mhz (unsigned int clock_freq) 
{
    tomp_gvCoreConfig.clock_freq = clock_freq;
}
/* @} */
