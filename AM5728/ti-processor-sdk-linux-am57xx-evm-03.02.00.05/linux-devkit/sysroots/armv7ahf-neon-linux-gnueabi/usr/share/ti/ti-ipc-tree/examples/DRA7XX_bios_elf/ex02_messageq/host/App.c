/*
#  Copyright (c) 2012-2014 Texas Instruments Incorporated - http://www.ti.com
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
 *  ======== App.c ========
 */

/* package header files */
#include <xdc/std.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/IHeap.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/System.h>

#include <ti/ipc/Ipc.h>
#include <ti/ipc/MessageQ.h>
#include <ti/ipc/MultiProc.h>
#include <ti/ipc/SharedRegion.h>

#include <ti/sysbios/heaps/HeapBuf.h>
#include <ti/sysbios/knl/Task.h>

/* local header files */
#include "../shared/AppCommon.h"
#include "App.h"

/* round up the value 'size' to the next 'align' boundary */
#define ROUNDUP(size, align) \
    (UInt32)(((UInt32)(size) + ((UInt32)(align) - 1)) & ~((UInt32)(align) - 1))

#define NUM_MSGS 4

/* module structure */
typedef struct {
    MessageQ_Handle     hostQue;    // created locally
    MessageQ_QueueId    slaveQue;   // opened remotely
    UInt16              heapId;     // MessageQ heapId
    HeapBuf_Handle      heap;       // message heap
    Int                 msgSize;    // aligned size of message
    Int                 poolSize;   // size of message pool
    Ptr                 store;      // memory store for message pool
} App_Module;

/* private data */
static App_Module Module;


/*
 *  ======== App_create ========
 */

Int App_create(UInt16 remoteProcId)
{
    Int                 status = 0;
    Int                 align;
    Error_Block         eb;
    IHeap_Handle        srHeap;
    HeapBuf_Params      heapParams;
    MessageQ_Params     msgqParams;
    char                msgqName[32];

    Log_print0(Diags_INFO, "App_create: -->");

    /* setting default values */
    Module.hostQue = NULL;
    Module.slaveQue = MessageQ_INVALIDMESSAGEQ;
    Module.heapId = App_MsgHeapId;
    Module.msgSize = 0;

    /* compute message size to fill entire cache lines */
    align = SharedRegion_getCacheLineSize(0);
    Module.msgSize = ROUNDUP(sizeof(App_Msg), align);

    /* compute message pool size */
    Module.poolSize = Module.msgSize * NUM_MSGS;

    /* acquire message pool memory */
    srHeap = (IHeap_Handle)SharedRegion_getHeap(0);
    Module.store = Memory_alloc(srHeap, Module.poolSize, align, NULL);

    /* create a heap in shared memory for message pool */
    HeapBuf_Params_init(&heapParams);
    heapParams.blockSize = Module.msgSize;
    heapParams.numBlocks = NUM_MSGS;
    heapParams.bufSize = Module.poolSize;
    heapParams.align = align;
    heapParams.buf = Module.store;
    Error_init(&eb);

    Module.heap = HeapBuf_create(&heapParams, &eb);

    if (Module.heap == NULL) {
        Log_error0("App_create: failed creating message pool");
        status = -1;
        goto leave;
    }

    /* bind message pool to heapId */
    MessageQ_registerHeap((Ptr)(Module.heap), App_MsgHeapId);

    /* create local message queue (inbound messages) */
    MessageQ_Params_init(&msgqParams);

    Module.hostQue = MessageQ_create(NULL, &msgqParams);

    if (Module.hostQue == NULL) {
        Log_error0("App_create: failed creating MessageQ");
        status = -1;
        goto leave;
    }

    /* open the remote message queue */
    System_sprintf(msgqName, App_SlaveMsgQueName,
            MultiProc_getName(remoteProcId));

    do {
        status = MessageQ_open(msgqName, &Module.slaveQue);
        Task_sleep(1);
    } while (status == MessageQ_E_NOTFOUND);

    if (status < 0) {
        Log_error0("App_create: failed opening MessageQ");
        goto leave;
    }

    Log_print0(Diags_INFO, "App_create: Host is ready");

leave:
    Log_print1(Diags_INFO, "App_create: <-- status=%d", (IArg)status);
    return(status);
}


/*
 *  ======== App_delete ========
 */
Int App_delete(Void)
{
    Int             status;
    IHeap_Handle    srHeap;

    Log_print0(Diags_INFO, "App_delete: -->");

    /* close remote resources */
    status = MessageQ_close(&Module.slaveQue);

    if (status < 0) {
        goto leave;
    }

    /* delete the host message queue */
    status = MessageQ_delete(&Module.hostQue);

    if (status < 0) {
        goto leave;
    }

    /* unregister message pool heap */
    MessageQ_unregisterHeap(App_MsgHeapId);

    /* delete the message pool heap */
    HeapBuf_delete(&Module.heap);

    /* release message pool memory */
    srHeap = (IHeap_Handle)SharedRegion_getHeap(0);
    Memory_free(srHeap, Module.store, Module.poolSize);

leave:
    Log_print1(Diags_INFO, "App_delete: <-- status=%d", (IArg)status);
    return(status);
}


/*
 *  ======== App_exec ========
 */
Int App_exec(Void)
{
    Int         status;
    Int         i;
    App_Msg *   msg;

    Log_print0(Diags_INFO, "App_exec: -->");

    /* fill process pipeline */
    for (i = 1; i <= 3; i++) {
        Log_print1(Diags_INFO, "App_exec: sending message %d", (IArg)i);

        /* allocate message */
        msg = (App_Msg *)MessageQ_alloc(Module.heapId, Module.msgSize);

        if (msg == NULL) {
            status = -1;
            goto leave;
        }

        /* set the return address in the message header */
        MessageQ_setReplyQueue(Module.hostQue, (MessageQ_Msg)msg);

        /* fill in message payload */
        msg->cmd = App_CMD_NOP;

        /* send message */
        MessageQ_put(Module.slaveQue, (MessageQ_Msg)msg);
    }

    /* process steady state (keep pipeline full) */
    for (i = 4; i <= 15; i++) {

        /* wait for return message */
        status = MessageQ_get(Module.hostQue, (MessageQ_Msg *)&msg,
            MessageQ_FOREVER);

        if (status < 0) {
            goto leave;
        }

        /* extract message payload */

        /* free the message */
        MessageQ_free((MessageQ_Msg)msg);

        Log_print1(Diags_INFO, "App_exec: message received, sending message %d",
                (IArg)i);

        /* allocate message */
        msg = (App_Msg *)MessageQ_alloc(Module.heapId, Module.msgSize);

        if (msg == NULL) {
            status = -1;
            goto leave;
        }

        /* set the return address in the message header */
        MessageQ_setReplyQueue(Module.hostQue, (MessageQ_Msg)msg);

        /* fill in message payload */
        if (i == 15) {
            /* Last message will tell the slave to shutdown */
            msg->cmd = App_CMD_SHUTDOWN;
        }
        else {
            msg->cmd = App_CMD_NOP;
        }

        /* send message */
        MessageQ_put(Module.slaveQue, (MessageQ_Msg)msg);
    }

    /* drain process pipeline */
    for (i = 1; i <= 3; i++) {
        Log_print0(Diags_INFO, "App_exec: message received");

        /* wait for return message */
        status = MessageQ_get(Module.hostQue, (MessageQ_Msg *)&msg,
            MessageQ_FOREVER);

        if (status < 0) {
            goto leave;
        }

        /* extract message payload */

        /* free the message */
        MessageQ_free((MessageQ_Msg)msg);
    }

leave:
    Log_print1(Diags_INFO, "App_exec: <-- status=%d", (IArg)status);
    return(status);
}
