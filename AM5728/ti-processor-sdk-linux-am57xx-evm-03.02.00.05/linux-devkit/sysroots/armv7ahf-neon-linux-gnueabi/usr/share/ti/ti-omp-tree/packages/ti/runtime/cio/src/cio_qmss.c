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
 * \file cio_qmss.c
 */


#include "cio_qmss.h"

/*! Queues used by the OpenMP Runtime */
#pragma DATA_SECTION (tomp_cio_queues, ".tomp_svNcMem");
tomp_CIOQueues tomp_cio_queues;

/*! Memory region used by the OpenMP Runtime */
#pragma DATA_SECTION (cioQmssMemRegInfo, ".tomp_svNcMem");
static Qmss_MemRegInfo cioQmssMemRegInfo;

/*! Buffer used for allocations */
#pragma DATA_ALIGN   (__TI_omp_cio_buffer, 4096)
#pragma DATA_SECTION (__TI_omp_cio_buffer, ".TI.openmp_cio_buffer");
uint8_t __TI_omp_cio_buffer[CIO_MSG_BUF_NUM * CIO_MSG_BUF_SIZE];



static void initRegionConfig(Qmss_MemRegInfo* memRegInfo,
                             int32_t          startIndex);

static tomp_queue_t initFreeDesc(Qmss_MemRegInfo* memRegInfo, int32_t qid);

static void         resetQueues (void);
static bool         openQueues  (Qmss_MemRegInfo* memRegInfo);
static void         closeQueues (void);


extern far int __TI_omp_cio_qmss_queue_base;

/**
 *
 */
bool tomp_cioInitQmss(int32_t qmssStartIndex)
{
    // Initialize QMSS for CIO
    resetQueues();

    Qmss_MemRegInfo *memRegInfo = &cioQmssMemRegInfo;

    // Build table of region configurations
    initRegionConfig(memRegInfo, qmssStartIndex);

    Qmss_Result region = Qmss_insertMemoryRegion (memRegInfo);
    if (region >= Qmss_MemRegion_MEMORY_REGION0)
        memRegInfo->memRegion = (Qmss_MemRegion)region;
    else
        return false;

    // Setup CIO queues
    if (!openQueues(memRegInfo))
        return false;

    // Ensure all writes to tomp_Queue object land. This object is
    // read by worker cores. There is also a barrier after this call.
    tomp_mfence();

    return true;
}


/**
 */
void tomp_cioExitQmss(void)
{
    CIO_Msg *msg = cio_msgAlloc();
    cio_msgInitHeader(msg, CIO_EXIT);
    cio_msgSend(msg);

    //Wait for a response to exit
    cio_msgRecv();

    closeQueues();

    // Must remove memory region before calling Qmss_exit!
    Qmss_removeMemoryRegion(cioQmssMemRegInfo.memRegion, /*qGroup*/0);
}


/**
 *
 */
void initRegionConfig(Qmss_MemRegInfo* memRegInfo,
                      int32_t          startIndex)
{
    // Initialize descriptor regions
    memRegInfo->descSize = CIO_MSG_BUF_SIZE;
    memRegInfo->descNum  = CIO_MSG_BUF_NUM;
    memRegInfo->descBase = (uint32_t *) __TI_omp_cio_buffer;
    memRegInfo->manageDescFlag = Qmss_ManageDesc_UNMANAGED_DESCRIPTOR;
    memRegInfo->memRegion = 
                    (Qmss_MemRegion)(TOMP_QMSS_FIRST_MEMORY_REGION_IDX+1);
    memRegInfo->startIndex = startIndex;
}


/**
 * Open all queues required by OpenMP and populate the free queue
 */
bool openQueues(Qmss_MemRegInfo *memRegInfo)
{
    // Populate the freeQ with descriptors
    // int32_t qid = QMSS_PARAM_NOT_SPECIFIED;
    unsigned int qid = (unsigned int)&__TI_omp_cio_qmss_queue_base;
    tomp_cio_queues.freeDescriptorQ = initFreeDesc(memRegInfo, qid++);
    tomp_cio_queues.hostWriteQ      = tomp_queueOpen(qid++);

    Qmss_queueEmpty (tomp_cio_queues.hostWriteQ);

    int i;
    for (i = 0; i < tomp_cio_queues.numHostReadQ; i++)
    {
        tomp_cio_queues.hostReadQ[i] = tomp_queueOpen(qid++);
        Qmss_queueEmpty (tomp_cio_queues.hostReadQ[i]);
    }


    return true;
}


/**
 * Close and reset all queues used by OpenMP
 */
void closeQueues(void)
{
    int i;

    Qmss_queueEmpty (tomp_cio_queues.hostWriteQ);
    Qmss_queueEmpty (tomp_cio_queues.freeDescriptorQ);

    Qmss_queueClose (tomp_cio_queues.hostWriteQ);
    Qmss_queueClose (tomp_cio_queues.freeDescriptorQ);

    for (i = 0; i < tomp_cio_queues.numHostReadQ; i++)
    {
        Qmss_queueEmpty (tomp_cio_queues.hostReadQ[i]);
        Qmss_queueClose (tomp_cio_queues.hostReadQ[i]);
    }

    resetQueues();
}


/**
 * Reset all queues used by OpenMP 
 */
void resetQueues(void)
{
    tomp_cio_queues.hostWriteQ      = QMSS_PARAM_NOT_SPECIFIED;
    tomp_cio_queues.freeDescriptorQ = QMSS_PARAM_NOT_SPECIFIED;

    tomp_cio_queues.numHostReadQ = TOMP_DEVICE_NUM_CORES;

    int i;
    for (i = 0; i < tomp_cio_queues.numHostReadQ; i++)
    {
        tomp_cio_queues.hostReadQ[i] = QMSS_PARAM_NOT_SPECIFIED;
    }

}


/**
 * Initialize the free queue
 */
tomp_queue_t initFreeDesc(Qmss_MemRegInfo* memRegInfo, int32_t qid)
{
    // Qmss_initDescriptor uses a temporary queue internally to store
    // descriptors. On Hawking, this temporary queue could potentially
    // conflict with queues used by Linux etc. Use Qmss_queuePushDesc
    // onto the OpenMP free queue instead.
    tomp_queue_t freeDescQ = tomp_queueOpen(qid);

    uint8_t* descPtr = (uint8_t *)memRegInfo->descBase;
    uint32_t descSize = memRegInfo->descSize;

    int i;
    for (i = 0; i < memRegInfo->descNum; i++)
    {
        Qmss_queuePushDesc(freeDescQ, (void*)descPtr);
        descPtr += descSize;
    }

    return freeDescQ;
}


