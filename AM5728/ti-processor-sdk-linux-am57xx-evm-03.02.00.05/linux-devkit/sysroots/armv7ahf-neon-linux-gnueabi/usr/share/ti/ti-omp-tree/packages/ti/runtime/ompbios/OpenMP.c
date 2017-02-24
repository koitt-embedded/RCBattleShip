/*
 * Copyright (c) 2013, Texas Instruments Incorporated
 * http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 *  ======== OpenMP.c ========
 */
#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Types.h>
#include <ti/ipc/Ipc.h>
#include <ti/ipc/MultiProc.h>
#include <ti/ipc/SharedRegion.h>

#include <stdlib.h>

#include "package/internal/OpenMP.xdc.h"
#include "package/internal/HeapOMP.xdc.h"
#include <c6x.h>

#include <ti/runtime/openmp/omp.h>
#include <ti/runtime/openmp/src/tomp_init.h>
#include <ti/runtime/openmp/src/tomp_config.h>



       void __TI_omp_reset_rtsc_mode(void);
static void startIpc(void);
static void initRuntimeConfigFromModule(void);

extern void tomp_resetCoreBarrier();

/**
 * Called from OpenCL monitor to initialize the OpenMP runtime
 */
int tomp_initOpenMPforOpenCLPerApp(int master_core, int num_cores)
{
#if defined(TI_AM572)

    // Reset the barrier since OpenMP may have been initialized with a subset of the
    // DSP cores
    tomp_resetCoreBarrier();

    __TI_omp_config_cores (master_core, num_cores);

    /* The OpenCL runtime for AM572 uses index 1.  */
    /* This originally setup for Keystone devices at 3 */
    __TI_omp_config_hw_semaphores(/*hw_sem_base_idx=*/3);

    /* I need to confgure the MMU to get at L2 via a global address? */
    __TI_omp_config_thread_stack(1, 0x100000);
#else
    // On K2x, callback to __TI_omp_configure defined in monitor/omp_config_api.c
    __TI_omp_configure();
#endif

    // Set CPU clock freqency using value read from platform file. 
    // Clock frequency information is used by the OpenMP runtime timing 
    // functions.
    __TI_omp_config_clock_freq_in_mhz(OpenMP_clockFreq);

    // Indicate that OMP runtime responsible for updating DP around calls to
    // implicit events on worker cores. OpenCL will set DP only for the
    // master core.
    TOMP_UPDATE_DP = 1;

    // Wait for all cores to finish configuration
    __TI_omp_wait_at_core_barrier();

    // Start IPC. Required for shared memory heaps in BIOS mode
    if (OpenMP_useIpcSharedHeap)
       startIpc();

    if (DNUM == master_core && !tomp_initGlobalNRT(/*memRegionInitialized=*/1)) 
        return -1;

    // Wait for master core to finish initializing NRT queues
    __TI_omp_wait_at_core_barrier();

    // Perform local initialization on each core
    if (tomp_initLocal() < 0)
        return -1;

    // Initialize the OpenMP runtime data structures
    if (DNUM == master_core)
    {
       if (tomp_initParallel() < 0) return -1;
       tomp_initIcvNoParse();
    }

    return 0;
}


/**
 * Called from OpenCL monitor to cleanup after the OpenMP runtime
 */
void tomp_exitOpenMPforOpenCL(void)
{
#if defined (TI_AM572)
    __TI_omp_wait_at_core_barrier();
    if (DNUM == TOMP_MASTER_CORE_IDX)
       tomp_closeQueues();
#else
    tomp_closeQueues();
#endif
}


/**
 * OpenMP start function when runtime is used in RTSC mode
 *
 * Configures the runtime and calls main()
 *
 * Called via XDC Startup function mechanism (xdc.runtime.Startup) from the
 * application configuration file.
 *
 * Adding this function to xdc.runtime.Startup.lastFxns is done in the 
 * application configuration file (vs. in OpenMP.xs). This gives the programmer
 * flexibility to order the lastFxns. For example, if the application is
 * initializing QMSS, the call to initialize QMSS must be added to lastFxns
 * before __TI_omp_start_rtsc_mode is added.
 */
void __TI_omp_initialize_rtsc_mode(void)
{
    // XDC startup has reinitialized MARs to BIOS defaults. Fix
    __TI_omp_reset_rtsc_mode();

    // Start IPC. Required for shared memory heaps in BIOS mode
    if (OpenMP_useIpcSharedHeap)
       startIpc();

    // Initialize runtime configuration structures from OpenMP module settings
    initRuntimeConfigFromModule();

    // Switch SP from local L2 address to corresponding global L2 address
    tomp_switchL2SpToGlobal();

    __TI_omp_wait_at_core_barrier();

    // There is a call to malloc to set up TLS storage. The malloc can 
    // overflow the core-local heap. Call function after Ipc has started to
    // ensure that malloc is satisfied by the larger shared heap!
    if (!tomp_ompInitCommon())
        System_abort("Error, OpenMP init failed!");

    return;
}


/**
 * Reset function in RTSC mode
 *
 * Uses parameters from the OpenMP module to enable/disable caching for the
 * appropriate memory ranges.
 */
void __TI_omp_reset_rtsc_mode(void)
{
    // Cache configured via ti_sysbios_family_c66_Cache_Module_startup using
    // sizes specified in Platform.xdc
    //__TI_omp_configure_caches();

    /* OMP runtime requires a portion of MSMCSRAM to be non-cached. Since it is 
     * not possible to disable caching in the MSMCSRAM address range, we need a 
     * 2 step process:
     * 1. Map a portion of MSMCSRAM into a range that can be marked as
     *    non-cached. This is done using the MPAX register
     * 2. Annotate the mapped section as non-cached using the appropriate
     *    MAR register for that memory range
     * All accesses to MSMCSRAM through the mapped address range will not
     * be cached.
     */
    if (OpenMP_hasMsmc)
    {
       __TI_setMPAX(OpenMP_mpaxForMsmcMapping, 
                    OpenMP_msmcNoCacheVirtualBase, 
                    OpenMP_msmcNoCachePhysicalBase, 0x10 /* 128 KB */);
       __TI_omp_disable_caching(OpenMP_msmcNoCacheVirtualBase, 
                                OpenMP_msmcNoCacheVirtualSize);

       /* Enable Caching for MSMCSRAM */
       __TI_omp_enable_caching(OpenMP_msmcBase, OpenMP_msmcSize);
    }
    else
    {
       __TI_omp_disable_caching(OpenMP_ddrNoCacheBase, OpenMP_ddrNoCacheSize);
    }

    /* Enable caching for DDR */
    __TI_omp_enable_caching(OpenMP_ddrBase,  OpenMP_ddrSize);
}


/**
 * Initialize internal runtime configuration using values specified
 * in OpenMP RTSC module
 */
void initRuntimeConfigFromModule(void)
{
    __TI_omp_config_cores (OpenMP_masterCoreIdx, OpenMP_numCores);

    __TI_omp_config_hw_semaphores(OpenMP_hwSemBaseIdx);

    __TI_omp_config_clock_freq_in_mhz(OpenMP_clockFreq);

    __TI_omp_config_hw_queues (OpenMP_qmssInit,
                               OpenMP_qmssHwQueueBaseIdx,           
                               OpenMP_qmssFirstDescIdxInLinkingRam,
                               OpenMP_qmssMemRegionIndex);

    __TI_omp_config_thread_stack(OpenMP_allocateStackFromHeap, 
                                 OpenMP_allocateStackFromHeapSize);
}

/*! 
 * ======== OpenMP_useSharedHeap ======== 
 */ 
Bool OpenMP_useSharedHeap() 
{ 
    return OpenMP_module->useSharedHeap; 
} 


/** 
  * Start IPC 
  */ 
void startIpc(void) 
{ 
    MultiProc_setLocalId(DNUM); 

    // Ipc_start sets up the shared heap in Shared Region 0 used for malloc's 
    Int status = Ipc_start(); 
    if (status < 0) 
        System_abort("Error, IPC failed!"); 
    
    // Can start using shared heap after Ipc has been started 
    OpenMP_module->useSharedHeap = TRUE; 
} 


/**
 * Work around for AM57 MultiProc module problems.
 */
#define DSP_SYS_HWINFO  (0x01D00004)

static uint32_t get_dsp_id()
{
      uint32_t id = (*((uint32_t *)DSP_SYS_HWINFO)) & 0xf;
         return id;
}

/*!
 *  *  ======== OpenMP_setProcId ========
 *   */
Void OpenMP_setProcId()
{
   uint32_t dsp_id = get_dsp_id();

   if (dsp_id != DNUM)
      System_abort("Error, Processor ID not same as DNUM");

   if      (dsp_id == 0) MultiProc_setLocalId(MultiProc_getId("DSP1"));
   else if (dsp_id == 1) MultiProc_setLocalId(MultiProc_getId("DSP2"));
   else    System_abort("Error, Invalid Processor ID");

}
