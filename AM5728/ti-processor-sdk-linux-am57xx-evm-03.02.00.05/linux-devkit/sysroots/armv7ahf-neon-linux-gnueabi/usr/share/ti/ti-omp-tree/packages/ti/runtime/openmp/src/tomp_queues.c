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
 * \file tomp_qmss.c
 */

#include "tomp_defs.h"
#if !TOMP_DEVICE_HAS_HW_QUEUES

#include "tomp_init.h"
#include "tomp_queues.h"
#include "tomp_util.h"
#include "tomp_log.h"


/*! Queues used by the OpenMP Runtime */
#pragma DATA_SECTION (tomp_queues, ".tomp_svNcMem");
tomp_Queues tomp_queues;

#pragma DATA_SECTION (queues, ".tomp_svNcMem");
sw_queue queues[TOMP_MAX_SW_QUEUES];


/*! Buffer used for allocations */
#pragma DATA_ALIGN   (tomp_svEventBufMem, CACHE_L2_LINESIZE)
#pragma DATA_SECTION (tomp_svEventBufMem, ".tomp_svNcMem");
uint8_t tomp_svEventBufMem[TOMP_EVENT_NUM * TOMP_EVENT_BUF_SIZE];

static void         tomp_resetQueues (void);
static bool         tomp_openQueues  (void);
       void         tomp_closeQueues (void);

/**
 * Initializes the NRT (QMSS sub system) for OpenMP
 *
 * Called by the master core only. Sets up the memory region, initializes
 * QMSS (if required) and opens the queues required by OpenMP.
 *
 * NOTE: This function must be called BEFORE tomp_dispatch_once is 
 *       called on the worker cores.
 */
bool tomp_initGlobalNRT(bool memRegionInitialized)
{
    tomp_resetQueues();

    // Setup OpenMP queues
    if (!tomp_openQueues())
        return false;

    // Ensure all writes to tomp_Queue object land. This object is
    // read by worker cores. There is also a barrier after this call.
    tomp_mfence();

    return true;
}


/**
 * Close queues and exit QMSS. Called by master core only
 */
void tomp_exitGlobalNRT(void)
{
    tomp_closeQueues();
}


/**
 * Per-core initialization for QMSS
 */
bool tomp_initLocalNRT(void)
{
    return true;
}

/**
 * Open all queues required by OpenMP and populate the free queue
 */
bool tomp_openQueues(void)
{
    int i;

    tomp_queues.freeDescriptorQ = queueAlloc(0);
    tomp_queues.implicitTaskQ = queueAlloc(1);
    tomp_queues.exitQ = queueAlloc(2);
    tomp_queues.finishQ = queueAlloc(3);
    queueEmpty(tomp_queues.freeDescriptorQ);
    queueEmpty(tomp_queues.implicitTaskQ);
    queueEmpty(tomp_queues.exitQ);
    queueEmpty(tomp_queues.finishQ);

    for (i = 0; i < tomp_queues.numExplicitTaskQ; i++)
    {
        tomp_queues.explicitTaskQ[i] = queueAlloc(4+i);
        queueEmpty(tomp_queues.explicitTaskQ[i]);
    }

    // initFreeDesc inlined here
    uint8_t *p = (uint8_t*)tomp_svEventBufMem;
    for (i = 0; i < TOMP_EVENT_NUM; i++)
    {
        queuePush(tomp_queues.freeDescriptorQ, (void*)p);
        p += TOMP_EVENT_BUF_SIZE;
    }

    return true;
}


/**
 * Close and reset all queues used by OpenMP
 */
void tomp_closeQueues(void)
{
    int i;

    queueEmpty (tomp_queues.implicitTaskQ);
    queueEmpty (tomp_queues.exitQ);
    queueEmpty (tomp_queues.finishQ);
    queueEmpty (tomp_queues.freeDescriptorQ);

    queueClose (tomp_queues.implicitTaskQ);
    queueClose (tomp_queues.exitQ);
    queueClose (tomp_queues.finishQ);
    queueClose (tomp_queues.freeDescriptorQ);

    for (i = 0; i < tomp_queues.numExplicitTaskQ; i++)
    {
        queueEmpty (tomp_queues.explicitTaskQ[i]);
        queueClose (tomp_queues.explicitTaskQ[i]);
    }

    tomp_resetQueues();
}


/**
 * Reset all queues used by OpenMP 
 */
void tomp_resetQueues(void)
{
    tomp_queues.numExplicitTaskQ = TOMP_DEVICE_NUM_CORES;
    return;
}

/** \defgroup omp_config */
/* @{ */
/**
 * API to get information on Memory regions used by the OpenMP runtime.
 *
 * @param memRegions array of memory regions allocated by caller. OpenMP
 *  runtime will update memRegions with descriptor size, number and base
 *  address for each region it uses.
 * @param memRegionCount OpenMP runtime will set to number of regions used 
 *  by it
 */
void __TI_omp_get_qmss_memory_regions(void* memRegions, 
                                      int*  memRegionCount)
{
   return;
}


/**
 * API to update the OpenMP runtime with memRegion and startIndex
 * allocated by the caller.
 */
void __TI_omp_update_qmss_memory_regions(void* memRegions, 
                                         int   memRegionCount)
{
   return;
}

/* @} */

#endif // !TOMP_DEVICE_HAS_HW_QUEUES
