/*
 * Copyright (c) 2012-2013, Texas Instruments Incorporated
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
 *  ======== AppEve2.c ========
 *  Platform: DRA7XX_bios_elf
 */

/* this define must precede inclusion of any xdc header file */
#define Registry_CURDESC AppEve2__Desc
#define MODULE_NAME "AppEve2"

#include <xdc/std.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/IHeap.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/Registry.h>
#include <xdc/runtime/System.h>

#include <ti/ipc/MessageQ.h>
#include <ti/ipc/SharedRegion.h>

#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/knl/Task.h>

/* local header files */
#include "AppEve2.h"
#include "../shared/SvrMsg.h"

/* module structure */
typedef struct {
    IHeap_Handle        heap;           /* SR_0 heap handle */
    MessageQ_Handle     localMsgQue;    /* created locally */
    MessageQ_QueueId    svrQue[10];     /* opened remotely */
    SvrMsg_Msg *        msg;
} AppEve2_Module;

/* friend data */
extern Semaphore_Handle SvrEve2_doneFlag;

/* private data */
Registry_Desc           Registry_CURDESC;
static Int              Mod_curInit = 0;
static AppEve2_Module   Module;


/*
 *  ======== AppEve2_destroy ========
 */
Int AppEve2_destroy(Void)
{
    Int     status = 0;
    UInt16  numProcs;
    UInt16  procId;

    Log_print0(Diags_ENTRY, "--> AppEve2_destroy:");

    /* TODO enter gate */

    /* wait for server thread to finish */
    while (Semaphore_getCount(SvrEve2_doneFlag) > 0) {
        Task_sleep(1);
    }

    /* reference count the module usage */
    if (--Mod_curInit > 0) {
        goto leave;  /* object still in use */
    }

    /* free the static message buffer */
    Memory_free(Module.heap, Module.msg, sizeof(SvrMsg_Msg));

    /* close each remote processor's server queue */
    numProcs = MultiProc_getNumProcessors();
    for (procId = 0; procId < numProcs; procId++) {

        /* close remote message queue */
        status = MessageQ_close(&Module.svrQue[procId]);

        if (status < 0) {
            Log_error2("AppEve2_destroy: procId=%d, server queue close "
                    "error=%d", (IArg)procId, (IArg)status);
            goto leave;
        }
    }

    /* delete the local message queue */
    status = MessageQ_delete(&Module.localMsgQue);

    if (status < 0) {
        Log_error1("AppEve2_destroy: queue delete error=%d", (IArg)status);
        goto leave;
    }

leave:
    /* disable log events */
    Log_print1(Diags_EXIT, "<-- AppEve2_destroy: status=%d", (IArg)status);
    Diags_setMask(MODULE_NAME"-FEX");

    /*
     * Note that there isn't a Registry_removeModule() yet:
     *     https://bugs.eclipse.org/bugs/show_bug.cgi?id=315448
     *
     * ... but this is where we'd call it.
     */

    /* TODO leave gate */
    return(status);
}

/*
 *  ======== AppEve2_run ========
 */
Int AppEve2_run(Void)
{
    Int     status = 0;
    Int     count;
    UInt16  numProcs;
    UInt16  procId;

    Log_print0(Diags_ENTRY, "--> AppEve2_run:");

    /* ping each remote server */
    numProcs = MultiProc_getNumProcessors();
    for (procId = 0; procId < numProcs; procId++) {
        for (count = 1; count <= SvrMsg_NUM_MSGS; count++) {
            Log_print1(Diags_INFO, "AppEve2_run: ping procId=%d",
                    (IArg)procId);

            /* fill and send message */
            Module.msg->cmd = SvrMsg_Cmd_START;
            Module.msg->svrProcId = MultiProc_INVALIDID;
            MessageQ_put(Module.svrQue[procId], (MessageQ_Msg)Module.msg);

            /* wait for return message */
            status = MessageQ_get(Module.localMsgQue,
                    (MessageQ_Msg *)&Module.msg, MessageQ_FOREVER);

            if (status < 0) {
                Log_error1("AppEve2_run: message receive error=%d",
                        (IArg)status);
                goto leave;
            }
            else if (Module.msg->svrProcId != procId) {
                Log_error2("AppEve2_run: message delivery error, remote "
                        "procId=%d, server procId=%d",
                        (IArg)procId, (IArg)Module.msg->svrProcId);
                goto leave;
            }

            Log_print1(Diags_INFO, "AppEve2_run: ack received, procId=%d",
                    (IArg)procId);
        }
    }

leave:
    Log_print1(Diags_EXIT, "<-- AppEve2_run: %d", (IArg)status);
    return(status);
}

/*
 *  ======== AppEve2_setup ========
 */
Int AppEve2_setup(Void)
{
    Int                 status = 0;
    Registry_Result     result;
    MessageQ_Params     msgqParams;
    UInt16              numProcs;
    UInt16              procId;
    Char                cbuf[48];

    /* TODO enter gate */

    /* reference count the module usage */
    if (Mod_curInit >= 1) {
        goto leave;  /* already initialized */
    }

    /* initialize module state */
    Module.heap = NULL;
    Module.localMsgQue = NULL;
    Module.msg = NULL;

    /* register with xdc.runtime to get a diags mask */
    result = Registry_addModule(&Registry_CURDESC, MODULE_NAME);

    if ((result != Registry_SUCCESS) && (result != Registry_ALREADY_ADDED)) {
        status = -1;
        goto leave;
    }

    /* enable some trace */
    Diags_setMask(MODULE_NAME"+FEX");
    Log_print0(Diags_ENTRY, "--> AppEve2_setup:");

    /* create local message queue (inbound messages) */
    MessageQ_Params_init(&msgqParams);
    Module.localMsgQue = MessageQ_create(Eve2_AppMsgQue, &msgqParams);

    if (Module.localMsgQue == NULL) {
        Log_error0("AppEve2_setup: message queue create failed");
        status = -1;
        goto leave;
    }

    /* open each remote processor's server queue */
    numProcs = MultiProc_getNumProcessors();
    for (procId = 0; procId < numProcs; procId++) {

        /* compute the remote processor server queue name */
        System_sprintf(cbuf, SvrMsg_SvrQueNameFmt, MultiProc_getName(procId));

        /* open the remote message queue, loop until queue is available */
        do {
            status = MessageQ_open(cbuf, &Module.svrQue[procId]);
            if (status == MessageQ_E_NOTFOUND) {
                Task_sleep(1);
            }
        } while (status == MessageQ_E_NOTFOUND);

        if (status < 0) {
            Log_error0("AppEve2_setup: could not open slave message queue");
            goto leave;
        }

        Log_print1(Diags_INFO,"AppEve2_setup: procId=%d, opened server queue",
                (IArg)procId);
    }

    /* get the SR_0 heap handle */
    Module.heap = (IHeap_Handle)SharedRegion_getHeap(0);

    /* allocate a static message from SR_0 heap */
    Module.msg = (SvrMsg_Msg *)Memory_alloc(Module.heap, sizeof(SvrMsg_Msg),
            0, NULL);

    if (Module.msg == NULL) {
        Log_error0("AppEve2_setup: could not allocate message");
        status = -1;
        goto leave;
    }

    /* initialize message header */
    MessageQ_staticMsgInit((MessageQ_Msg)Module.msg, sizeof(SvrMsg_Msg));
    MessageQ_setReplyQueue(Module.localMsgQue, (MessageQ_Msg)Module.msg);

    Log_print0(Diags_INFO,"AppEve2_setup: slave is ready");

leave:
    /* success, increment reference count */
    if (status >= 0) {
        Mod_curInit++;
    }

    /* error handling */
    else {
        /* unregister diags mask */
        /* release resources */
    }

    /* TODO leave gate */
    Log_print0(Diags_EXIT, "<-- AppEve2_setup:");
    return(status);
}
