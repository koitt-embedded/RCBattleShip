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
 *  ======== OpenMP.xdc ========
 */

import xdc.runtime.Types;


/*! 
 *  ======== OpenMP ========
 *  OpenMP RTSC Configuration Module 
 * 
 *  This module must be used (via xdc.useModule) by all OpenMP RTSC
 *  applications. This module is used to setup a configuration for the 
 *  runtime. The configuration is applied by the functions
 *  __TI_omp_reset_bios_mode and __TI_omp_start_bios_mode before main
 *  is called.
 *
 */
module OpenMP
{
    /*! Number of participating cores. 
     * 
     *  Can be fewer than number of cores available on device.
     */
    config Int32    numCores            = 8;

    /*! Index of the core running the main thread */
    config Int32    masterCoreIdx       = 0;

    /*! Core clock rate as defined in Platform.xdc */
    config Int32    clockFreq           = 0;

    /*! Device has onchip MSMC memory (KS1 and KS2) */
    config bool     hasMsmc             = true;

    /*! Base address of MSMC region as defined in Platform.xdc */
    config UInt32   msmcBase            = 0;

    /*! Size of MSMC region as defined in Platform.xdc */
    config UInt32   msmcSize            = 0;

    /*! Base address of OMP_MSMC_NC_VIRT region as defined in Platform.xdc */
    config UInt32   msmcNoCacheVirtualBase     = 0;

    /*! Size of OMP_MSMC_NC_VIRT region as defined in Platform.xdc */
    config UInt32   msmcNoCacheVirtualSize     = 0;

    /*! Base address of OMP_MSMC_NC_PHY region as defined in Platform.xdc */
    config UInt32   msmcNoCachePhysicalBase     = 0;

    /*! Base address of DDR region as defined in Platform.xdc */
    config UInt32   ddrBase             = 0;

    /*! Size of DDR region as defined in Platform.xdc */
    config UInt32   ddrSize             = 0;

    /*! Base address of DDR_NC region as defined in Platform.xdc */
    config UInt32   ddrNoCacheBase      = 0;

    /*! Size of DDR_NC region as defined in Platform.xdc */
    config UInt32   ddrNoCacheSize      = 0;

    /*! MPAX register used for mapping OMP_MSMC_NC_VIRT addresses to
     *  corresponding addresses in the OMP_MSMC_NC_PHY region
     */
    config UInt32   mpaxForMsmcMapping  = 3;

    /*! Base index of Hardware Semaphore. 
     * 
     *  The runtime uses hwSemCount semaphores starting at base index. 
     *  E.g. if hwSemBaseIdx is 3 and hwSemCount is 5, semaphores 3,4,5,6,7
     *  are used.
     */
    config Int32    hwSemBaseIdx        = 3;

    /*! Number of Hardware Semaphores
     * 
     *  The user must not modify this field. The runtime uses 7 semaphores.
     */
    config Int32    hwSemCount          = 7;

    /*! 
     *  @_nodoc
     *  Set via openmp.Settings.runtimeInitializesQmss. Do not set
     *  directly.
     */
    config bool     qmssInit = true;

    /*! Index of the QMSS memory region
     *
     *  Defaults to -1 (Qmss_MemRegion_MEMORY_REGION_NOT_SPECIFIED). 
     *  If the application is initializing QMSS and setting up memory regions, 
     *  it can use qmssMemRegionIndex to indicate the memory region to be used
     */
    config Int32    qmssMemRegionIndex = -1;

    /*! The first descriptor index used in linking RAM.
     * 
     *  If the application is initializing QMSS, it typically provides an
     *  index.
     */
    config UInt32   qmssFirstDescIdxInLinkingRam = 0;

    /*! Base index of QMSS general purpose hardware queue. 
     *
     *  The runtime uses 11 queues starting at this index. When the runtime 
     *  intializes QMSS, the default of -1 allows the QMSS LLD to pick the 
     *  queues allocated.
     */
    config Int32    qmssHwQueueBaseIdx  = -1;

    /*! If true, Use an IPC shared heap */
    config bool     useIpcSharedHeap = true;

    /*! If true, Allocate a local heap for BIOS */
    config bool     allocateLocalHeap = true;

    /*! Size of BIOS local heap */
    config UInt32   allocateLocalHeapSize = 0x8000;

    /*! If true, Allocate a shared heap for malloc/free */
    config bool     allocateSharedHeap = true;

    /*! Size of shared heap */
    config UInt32   allocateSharedHeapSize = 0x08000000;

    /*! If true, stack for each OpenMP thread is malloc'ed from the heap
     *
     *  By default, the stacks are placed in L2SRAM.
     */
    config bool     allocateStackFromHeap    = false;

    /*! If thread stack is allocated from heap, size of the stack on each
     *  core. Defaults to 64K per-core
     */
    config Int32    allocateStackFromHeapSize = 0x10000;

    /*!
     *  @_nodoc
     * Set number of processors for IPC to use
     */
    metaonly Void configureIpc(UInt16 masterCoreIdx, UInt16 numCores);

     /*!
     *  @_nodoc
     *  Used by HeapOMP to switch to using Shared Region heap for allocation
     */
    Bool useSharedHeap();

internal:

    struct Module_State {
        Bool                useSharedHeap;
    };
    

    /*!
     *  Sets the local MultiProc ID based on the DNUM value
     */
    Void setProcId();
}
