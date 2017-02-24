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
 * \file cio_qmss.h
 *       API to access the QMSS sub-system. Wraps the QMSS LLD APIs
 */

#ifndef _CIO_QMSS_H_
#define _CIO_QMSS_H_

#include <stdbool.h>
#include <stdint.h>
#include <c6x.h>

#include <ti/runtime/openmp/src/tomp_defs.h>
#include <ti/runtime/openmp/src/tomp_util.h>
#include <ti/runtime/openmp/src/tomp_qmss.h>

// QMSS LLD includes
#include <ti/drv/qmss/qmss_drv.h>


#define CIO_TRANSFER (1)
#define CIO_EXIT     (2)

/* _CIOBUF_ must be 4-byte aligned, writemsg writes length as integer! */
typedef struct
{
    volatile int32_t  id;
    volatile int32_t core_id;
    volatile uint8_t _CIOBUF_[CIO_MSG_BUF_SIZE-2*sizeof(int32_t)]; 
} CIO_Msg;


/**
 * CIO QMSS Queues
 */
typedef struct
{
    tomp_queue_t freeDescriptorQ;
    tomp_queue_t hostWriteQ;                      /* DSP -> ARM (writemsg) */
    int32_t      numHostReadQ;     
    tomp_queue_t hostReadQ[TOMP_DEVICE_NUM_CORES];/* ARM -> DSPx (readmsg) */
} tomp_CIOQueues;

extern tomp_CIOQueues     tomp_cio_queues;


/**
 * Allocate a buffer from the TOMP free queue
 */
static inline CIO_Msg* cio_msgAlloc(void)
{
    // The popped descriptor may have its size encoded in lower 4 bits.
    // QMSS_DESC_PTR clears these bits out.
    return (CIO_Msg*)QMSS_DESC_PTR(
                               Qmss_queuePop(tomp_cio_queues.freeDescriptorQ));
}


static inline void cio_msgInitHeader(CIO_Msg* msg, int8_t msg_id)
{
    msg->id      = msg_id;
    msg->core_id = DNUM;
}


/**
 * Free a buffer allocated from the TOMP free queue
 */
static inline void cio_msgFree(CIO_Msg* msg)
{
    Qmss_queuePushDesc (tomp_cio_queues.freeDescriptorQ, (void*)msg);
    return;
}

static inline void cio_msgSend(CIO_Msg* msg)
{
    tomp_cacheWbInv(msg, sizeof(msg));
    tomp_eventPush(tomp_cio_queues.hostWriteQ, (void*)msg);
}

static inline CIO_Msg* cio_msgRecv()
{
    CIO_Msg* msg = NULL;
    
    while (msg == NULL)
        msg = (CIO_Msg *)tomp_eventPop(tomp_cio_queues.hostReadQ[DNUM]);
    
    // msg is on a cache line boundary
    tomp_cacheInv(msg, sizeof(msg));

    return msg;
}


bool tomp_cioInitQmss(int32_t qmssStartIndex);
void tomp_cioExitQmss(void);

#endif /*  _CIO_QMSS_H_ */
