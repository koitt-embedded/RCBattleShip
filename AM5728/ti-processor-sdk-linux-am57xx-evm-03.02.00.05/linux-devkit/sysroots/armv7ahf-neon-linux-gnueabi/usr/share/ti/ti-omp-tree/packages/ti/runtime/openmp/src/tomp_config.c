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
 * \file tomp_config.c
 * 
 * \brief Implements default versions of configuration functions          
 *
 * Functions implemented:
 *   __TI_omp_reset 
 *   __TI_omp_configure
 */

#include "tomp_defs.h"
#include "omp.h"
#include <ti/csl/csl_chip.h>
#include <ti/csl/csl_cache.h>
#include <ti/csl/csl_cacheAux.h>
#if TOMP_DEVICE_HAS_MSMC
#include <ti/csl/csl_msmc.h>
#include <ti/csl/csl_msmcAux.h>
#endif // TOMP_DEVICE_HAS_MSMC
#if TOMP_DEVICE_HAS_HW_QUEUES
#include <ti/drv/qmss/qmss_qm.h>
#endif // TOMP_DEVICE_HAS_HW_QUEUES

extern cregister volatile unsigned int DNUM;

/** \defgroup omp_config OMP Runtime Configuration Hooks */
/* @{ */

#define MSMCSRAM_START_ADDR     (0x0C000000)
#define MSMCSRAM_NC_SIZE        (0x00020000)    /* 128 KB */

#if defined (TI_C6678)
#define MSMCSRAM_SIZE           (0x00400000)    /* 4 MB */
#define MSMCSRAM_NC_START_ADDR  (0xA0000000)
#define DDR_START_ADDR          (0x80000000)
#define DDR_SIZE                (0x20000000)    /* 512 MB */
#define OMP_NUM_CORES           (8)
#define CLOCK_RATE              (1000)          /* 1000 Mhz */
#elif defined (TI_C6670)
#define MSMCSRAM_SIZE           (0x00200000)    /* 2 MB */
#define MSMCSRAM_NC_START_ADDR  (0xA0000000)
#define DDR_START_ADDR          (0x80000000)
#define DDR_SIZE                (0x20000000)    /* 512 MB */
#define OMP_NUM_CORES           (4)
#define CLOCK_RATE              (983)           /* 983 Mhz */
#elif defined (TI_C6657)
#define MSMCSRAM_SIZE           (0x00100000)    /* 1 MB */
#define MSMCSRAM_NC_START_ADDR  (0xA0000000)
#define DDR_START_ADDR          (0x80000000)
#define DDR_SIZE                (0x20000000)    /* 512 MB */
#define OMP_NUM_CORES           (2)
#define CLOCK_RATE              (1000)          /* 1000 Mhz */
#elif defined (TI_C6636)
#define MSMCSRAM_SIZE           (0x00600000)    /* 6 MB */
#define MSMCSRAM_NC_START_ADDR  (0xE0000000)
#define DDR_START_ADDR          (0xA0000000)
#define DDR_SIZE                (0x20000000)    /* 512 MB */
#define OMP_NUM_CORES           (8)
#define CLOCK_RATE              (1000)          /* 1000 Mhz */
#elif defined (TI_66AK2G)
#define MSMCSRAM_SIZE           (0x00100000)    /* 1 MB */
#define MSMCSRAM_NC_START_ADDR  (0xE0000000)
#define DDR_START_ADDR          (0x80000000)
#define DDR_SIZE                (0x20000000)    /* 512 MB */
#define OMP_NUM_CORES           (1)
#define CLOCK_RATE              (1000)          /* 1000 Mhz */
#elif defined (TI_AM572)
#define DDR_START_ADDR          (0x80000000)
#define DDR_SIZE                (0x01000000)    /* 16 MB */
#define DDR_NC_START_ADDR       (0x81000000)
#define DDR_NC_SIZE             (0x01000000)    /* 16 MB */
#define OMP_NUM_CORES           (2)
#define CLOCK_RATE              (600)          /* 600 Mhz */
#else
#error "Device not supported"
#endif

#define OMP_MASTER_CORE_IDX (0)

/**
 * Default reset routine. Invoked by all cores during boot, before cinit.
 *
 * Invoked before C initialization is performed - C init run addresses
 * can be in regions mapped by MPAX.
 * Annotated weak, can be overridden by a definition in application source
 * @see c_int00
 *
 * Typically performs the following operations:
 * - Sets up caches
 * - Initializes the MPAX registers for mapping memory regions
 * - Initializes the MAR registers to set attributes for memory regions
 *
 * NOTE: The addresses and sizes used here must correspond to those specified 
 * in the Platform or linker command file!
 */
#pragma WEAK(__TI_omp_reset)
#pragma CODE_SECTION(__TI_omp_reset, ".text:omp:reset")
void __TI_omp_reset(void)
{
    /* Configure caches */
    CACHE_setL1DSize(CACHE_L1_32KCACHE);
    CACHE_setL1PSize(CACHE_L1_32KCACHE);
    CACHE_setL2Size(CACHE_128KCACHE);

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
    /* 0x10 => 128K, 0x13 => 1MB */
#if TOMP_DEVICE_HAS_MSMC
    __TI_setMPAX(3, MSMCSRAM_NC_START_ADDR, 
                    MSMCSRAM_START_ADDR, 0x10 /* 128 KB */);
    __TI_omp_disable_caching(MSMCSRAM_NC_START_ADDR, MSMCSRAM_NC_SIZE);

    /* Annotate MSMCSRAM and DDR as cached + prefetch + write through */
    __TI_omp_enable_caching(MSMCSRAM_START_ADDR, MSMCSRAM_SIZE);
    __TI_omp_enable_caching(DDR_START_ADDR,      DDR_SIZE);
#else
    __TI_omp_disable_caching(DDR_NC_START_ADDR, DDR_NC_SIZE);
    __TI_omp_enable_caching(DDR_START_ADDR, DDR_SIZE);
#endif

}


/**
 * Default OpenMP Runtime configuration function.
 *
 * The OpenMP runtime requires the following hardware resources:
 *   - The set of cores (contiguous) that run the OpenMP runtime
 *   - Hardware Semaphores (6)
 * These are optional hardware resources:
 *   - QMSS general purpose hardware queues (11)
 *   - QMSS memory region (1)
 *
 * The configuration function specifies the hardware resources that can be
 * used by the runtime.
 *
 * It is annotated weak and can be overridden by a user provided function 
 * with the same name.
 * @see __TI_omp_config_thread_stack
 */
#pragma CODE_SECTION(__TI_omp_configure, ".text:omp:configure")
#pragma WEAK(__TI_omp_configure)
void __TI_omp_configure(void)
{
    __TI_omp_config_cores (OMP_MASTER_CORE_IDX, OMP_NUM_CORES);

    /* The OpenCL runtime for AM572 uses index 1.  */
    /* This originally setup for Keystone devices at 3 */
    __TI_omp_config_hw_semaphores(/*hw_sem_base_idx=*/3);

    __TI_omp_config_clock_freq_in_mhz(CLOCK_RATE);

#if TOMP_DEVICE_HAS_HW_QUEUES
    /* The OpenMP runtime requires 11 hardware queues and uses the QMSS LLD
     * APIs to initialize these queues. 
     * QMSS_PARAM_NOT_SPECIFIED 
     *      QMSS LLD allocates queue numbers during call to Qmss_queueOpen
     * Qmss_MemRegion_MEMORY_REGION_NOT_SPECIFIED 
     *      QMSS LLD allocates memory region used by Qmss_insertMemoryRegion
     */
#ifdef TI_C6636
    __TI_omp_config_hw_queues (/* init_qmss=*/                        1,
                               /* hw_queue_base_idx=*/             7332,
                               /* first_desc_idx_in_linking_ram=*/ 8000,
                               /* first_memory_region_idx=*/         32);
#else
    __TI_omp_config_hw_queues (/* init_qmss */ 1,
                               QMSS_PARAM_NOT_SPECIFIED,           
                               /* first_desc_idx_in_linking_ram=*/0,
                               Qmss_MemRegion_MEMORY_REGION_NOT_SPECIFIED);
#endif

#endif // TOMP_DEVICE_HAS_HW_QUEUES

#ifdef TI_AM572
    /* I need to confgure the MMU to get at L2 via a global address? */
    __TI_omp_config_thread_stack(1, 0x100000);
#else
    /* Thread stacks in core local memory */
    __TI_omp_config_thread_stack(0, 0);
#endif
}

/* @} */

