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
 * \file tomp_config.h
 * 
 * \brief Defines the configuration structure used by the OpenMP runtime
 */
#ifndef _TOMP_CONFIG_H_
#define _TOMP_CONFIG_H_

#include <stdint.h>

/*! TOMP runtime configuration structure 
 *  Fields initialized by API calls in __TI_omp_configure()
 *  @see __TI_omp_config_cores, __TI_omp_config_hw_semaphores, 
 *       __TI_omp_config_hw_queues, __TI_omp_config_thread_stack
 */
typedef struct _tomp_CoreConfig
{
    /*! Index (DNUM) of the master core */
    uint8_t     master_core_idx;

    /*! Number of cores participating in the OMP runtime */
    uint8_t     num_cores;

    /*! Starting index of hardware semaphore. Runtime uses 6 */
    uint8_t     hw_sem_base_idx;

    /*! If set to 1, runtime must allocate thread stack from the heap */
    uint8_t     thread_stack_from_heap;

    /*! if thread_stack_from_heap is 1, size of stack to allocate */
    uint32_t    thread_stack_size;

    /*! Clock frequency of cores */
    uint32_t     clock_freq;

    /*! If set to 1, runtime must initialize QMSS */
    uint8_t     init_qmss;

    /*! If set to 1, runtime sets DP on worker cores */
    uint8_t     updateDP;

    /*! Set to base queue id of queues used by OpenMP runtime or -1 if queue
     *  ids are allocated by QMSS LLD
     */
    int32_t     qmss_hw_queue_base_idx;
    uint32_t    qmss_first_desc_idx_in_linking_ram;

    /*! Set to memory region id used by OpenMP runtime for its free descriptor
     *  queue or -1 if the memory region is allocated by QMSS LLD.
     */
    uint32_t    qmss_first_memory_region_idx;
} tomp_CoreConfig;


extern tomp_CoreConfig    tomp_gvCoreConfig;


/*
 * CORE CONFIGURATION
 */

/*! Number of cores participating in the runtime */
#define TOMP_NUM_CORES  (tomp_gvCoreConfig.num_cores)

/*! Index of the master core */
#define TOMP_MASTER_CORE_IDX (tomp_gvCoreConfig.master_core_idx)

/*! Clock frequency of the cores in Hertz*/
#define TOMP_CLOCK_FREQ_IN_HZ (tomp_gvCoreConfig.clock_freq * 1.0e6)

/*! If update DP is 1, runtime will update DP for worker cores before
 *  dispatching implicit tasks
 */
#define TOMP_UPDATE_DP        (tomp_gvCoreConfig.updateDP)
#define TOMP_MUST_UPDATE_DP   (tomp_gvCoreConfig.updateDP == 1)

/*
 * QUEUE/LINKING RAM CONFIGURATION
 */

#define TOMP_HW_QUEUE_NUM            (11)
#define TOMP_MUST_INIT_QMSS          (tomp_gvCoreConfig.init_qmss == 1)
#define TOMP_INIT_QMSS               (tomp_gvCoreConfig.init_qmss)

/*! OEM: QMSS general purpose queue base index for the application event
 * pools. These queues store the free events before they are allocated by
 * the runtime.
 */
#define TOMP_HW_QUEUE_BASE_IDX      (tomp_gvCoreConfig.qmss_hw_queue_base_idx)

#define TOMP_QMSS_FIRST_DESC_IDX_IN_LINKING_RAM   \
                        (tomp_gvCoreConfig.qmss_first_desc_idx_in_linking_ram)
#define TOMP_QMSS_FIRST_MEMORY_REGION_IDX         \
                        (tomp_gvCoreConfig.qmss_first_memory_region_idx)


/*
 * HARDWARE SEMAPHORE CONFIGURATION  (6 semaphores required)
 */

/*! General purpose hardware semaphore
 *  - used for atomic increment/decrement on runtime variables
 *  - mutual exclusion in atomic regions
 */
#define TOMP_ATOMIC_HW_SEM_IDX         (tomp_gvCoreConfig.hw_sem_base_idx)

/*! Ensures mutual exclusion in critical regions */
#define TOMP_CRITICAL_HW_SEM_IDX      (tomp_gvCoreConfig.hw_sem_base_idx + 1)

/*! Ensures mutual exclusion when accessing worksharing related variables */
#define TOMP_WS_HW_SEM_IDX      (tomp_gvCoreConfig.hw_sem_base_idx + 2)

/*! Ensures mutual exclusion when accessing tasking related variables */
#define TOMP_TASK_HW_SEM_IDX    (tomp_gvCoreConfig.hw_sem_base_idx + 3)

/*! Used solely to ensure mutual exclusion for malloc/free */
#define TOMP_MALLOC_HW_SEM_IDX  (tomp_gvCoreConfig.hw_sem_base_idx + 4)

/*! Ensures mutual exclusion when accessing lock variables */
#define TOMP_LOCK_HW_SEM_IDX    (tomp_gvCoreConfig.hw_sem_base_idx + 5)

/*! Used solely to ensures mutual exclusion for software queues */
#define TOMP_QUEUES_HW_SEM_IDX    (tomp_gvCoreConfig.hw_sem_base_idx + 6)

/*! Used solely to ensures mutual exclusion for hardware queues */
#define QMSS_HW_SEM             (tomp_gvCoreConfig.hw_sem_base_idx + 6)


#define TOMP_THREAD_STACK_IN_L2 (tomp_gvCoreConfig.thread_stack_from_heap == 0)

#endif /*  _TOMP_CONFIG_H_ */
