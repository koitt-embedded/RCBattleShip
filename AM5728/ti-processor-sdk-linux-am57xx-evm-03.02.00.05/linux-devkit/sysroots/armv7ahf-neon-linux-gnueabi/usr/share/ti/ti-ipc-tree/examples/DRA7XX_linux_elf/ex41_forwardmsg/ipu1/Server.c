/*
 * Copyright (c) 2013-2014, Texas Instruments Incorporated
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
 *  ======== Server.c ========
 */

/* this define must precede inclusion of any xdc header file */
#define Registry_CURDESC Test__Desc
#define MODULE_NAME "Server"

/* xdctools header files */
#include <xdc/std.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Registry.h>
#include <xdc/runtime/IHeap.h>

/* package header files */
#include <ti/ipc/MessageQ.h>
#include <ti/ipc/MultiProc.h>
#include <ti/ipc/Ipc.h>
#include <ti/ipc/HeapBufMP.h>

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>

/* local header files */
#include "../shared/AppCommon.h"

/* module header file */
#include "Server.h"

/* module structure */
typedef struct {
    UInt16              hostProcId;         // host processor id
    MessageQ_Handle     slaveQue;           // created locally
    MessageQ_QueueId    remoteSlaveQueId;   // Opened queue handle
    UInt32              msgSize;
    HeapBufMP_Handle    srHeapHandle;
} Server_Module;

/* private data */
Registry_Desc               Registry_CURDESC;
static Server_Module        Module;


/*
 *  ======== Server_init ========
 */
Void Server_init(Void)
{
    Registry_Result result;

    /* register with xdc.runtime to get a diags mask */
    result = Registry_addModule(&Registry_CURDESC, MODULE_NAME);
    Assert_isTrue(result == Registry_SUCCESS, (Assert_Id)NULL);

    /* initialize module object state */
    Module.hostProcId = MultiProc_getId("HOST");
    Module.msgSize = sizeof(App_Msg);
    Module.srHeapHandle = NULL;
    Module.slaveQue = NULL;
}

/*
 *  ======== Server_create ========
 */
Int Server_create()
{
    Int                 status = 0;
    MessageQ_Params     msgqParams;

    /* enable some log events */
    Diags_setMask(MODULE_NAME"+EXF");


    Log_print0(Diags_INFO,"Opening HeapBufMP...");
    /* Open the heap created by the other processor. Loop until opened. */
    do {
        status = HeapBufMP_open(App_SrHeapName, &Module.srHeapHandle);
        /*
         *  Sleep for 1 clock tick to avoid inundating remote processor
         *  with interrupts if open failed
         */
        if (status < 0) {
            Task_sleep(1);
        }
    } while (status < 0);

    /* Register this heap with MessageQ */
    MessageQ_registerHeap((IHeap_Handle)Module.srHeapHandle, App_SrHeapId);

    /* create local message queue (inbound messages) */
    MessageQ_Params_init(&msgqParams);
    Module.slaveQue = MessageQ_create(App_SlaveMsgQueName2, &msgqParams);

    if (Module.slaveQue == NULL) {
        status = -1;
        goto leave;
    }

    /* open the remote message queues */
    do {
        status = MessageQ_open(App_SlaveMsgQueName1, &Module.remoteSlaveQueId);
        Task_sleep(1);
    } while (status == MessageQ_E_NOTFOUND);

    if (status < 0) {
        Log_print0(Diags_INFO,"Server_exec: Failed opening MessageQ");
        goto leave;
    }

    Log_print0(Diags_INFO,"Server_create: Slave is ready");

leave:
    Log_print1(Diags_EXIT, "<-- Server_create: %d", (IArg)status);
    return (status);
}

/*
 *  ======== Server_exec ========
 */
Int Server_exec()
{
    Int                 status;
    Bool                running = TRUE;
    App_Msg *           msg;
    MessageQ_QueueId    hostQueId;
    MessageQ_QueueId    slaveQueId;
    Int                 execMask = 0;

    Log_print0(Diags_ENTRY | Diags_INFO, "--> Server_exec:");

    while (running) {

        /* wait for inbound message */
        status = MessageQ_get(Module.slaveQue, (MessageQ_Msg *)&msg,
            MessageQ_FOREVER);

        if (status < 0) {
            goto leave;
        }

        /* process the message */
        Log_print1(Diags_INFO, "Server_exec: processing cmd=0x%x", msg->cmd);

        if (msg->cmd == App_CMD_SHUTDOWN) {
            running = FALSE;
            MessageQ_free((MessageQ_Msg)msg);
        }
        else if (msg->cmd == App_CMD_HOST) {
            execMask |= 0x1;

            hostQueId = MessageQ_getReplyQueue(msg); /* type-cast not needed */

            MessageQ_free((MessageQ_Msg)msg);

            /* Allocate a new message from SR for slave */
            Log_print0(Diags_INFO,"Server_exec: Allocating from SR heap");
            msg = (App_Msg *)MessageQ_alloc(App_SrHeapId, Module.msgSize);

            slaveQueId = Module.remoteSlaveQueId;
            msg->cmd = App_CMD_SLAVE;
            /* Send message to other slave */
            MessageQ_put(slaveQueId, (MessageQ_Msg)msg);
        }
        else if (msg->cmd == App_CMD_SLAVE) {
            execMask |= 0x2;
            MessageQ_free((MessageQ_Msg)msg);
        }

        /* send message back */
        if (execMask == 0x3) {
            /* allocate message */
            Log_print0(Diags_INFO,"Server_exec: Replying to host...");
            msg = (App_Msg *)MessageQ_alloc(App_MsgHeapId, Module.msgSize);
            MessageQ_put(hostQueId, (MessageQ_Msg)msg); /* say we are done */
            execMask = 0;
        }
    } /* while (running) */

leave:
    Log_print1(Diags_EXIT, "<-- Server_exec: %d", (IArg)status);
    return(status);
}

/*
 *  ======== Server_delete ========
 */
Int Server_delete()
{
    Int         status;

    Log_print0(Diags_ENTRY, "--> Server_delete:");

    /* close remote message queue */
    status = MessageQ_close(&Module.remoteSlaveQueId);
    if (status < 0) {
        goto leave;
    }

    /* delete the local message queue */
    status = MessageQ_delete(&Module.slaveQue);
    if (status < 0) {
        goto leave;
    }

    /* Unregister the SR heap from MessageQ module */
    status = MessageQ_unregisterHeap(App_SrHeapId);
    if (status < 0) {
        goto leave;
    }

    /* Close the SR heap */
    if (Module.srHeapHandle) {
        HeapBufMP_close(&Module.srHeapHandle);
    }

leave:
    if (status < 0) {
        Log_error1("Server_finish: error=0x%x", (IArg)status);
    }

    /* disable log events */
    Log_print1(Diags_EXIT, "<-- Server_delete: %d", (IArg)status);
    Diags_setMask(MODULE_NAME"-EXF");

    return(status);
}

/*
 *  ======== Server_exit ========
 */
Void Server_exit(Void)
{
    /*
     * Note that there isn't a Registry_removeModule() yet:
     *     https://bugs.eclipse.org/bugs/show_bug.cgi?id=315448
     *
     * ... but this is where we'd call it.
     */
}
