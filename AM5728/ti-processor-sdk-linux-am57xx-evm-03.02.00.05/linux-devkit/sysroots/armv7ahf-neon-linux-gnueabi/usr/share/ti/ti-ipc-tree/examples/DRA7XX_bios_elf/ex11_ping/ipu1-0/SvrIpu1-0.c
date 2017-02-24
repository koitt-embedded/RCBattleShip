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
 *  ======== SvrIpu1_0.c ========
 *  Platform: DRA7XX_bios_elf
 */

/* this define must precede inclusion of any xdc header file */
#define Registry_CURDESC SvrIpu1_0__Desc
#define MODULE_NAME "SvrIpu1_0"

#include <xdc/std.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Registry.h>
#include <xdc/runtime/System.h>

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/knl/Task.h>

/* local header files */
#include "SvrIpu1-0.h"
#include "../shared/SvrMsg.h"

/* module structure */
typedef struct {
    MessageQ_Handle localMsgQue;
} SvrIpu1_0_Module;

/* friend data */
Semaphore_Handle SvrIpu1_0_doneFlag = NULL;

/* private data */
Registry_Desc           Registry_CURDESC;
static Int              Mod_curInit = 0;
static SvrIpu1_0_Module   Module;


/*
 *  ======== SvrIpu1_0_destroy ========
 */
Int SvrIpu1_0_destroy(Void)
{
    Int status = 0;

    Log_print0(Diags_ENTRY, "--> SvrIpu1_0_destroy:");

    /* TODO enter gate */

    /* reference count the module usage */
    if (--Mod_curInit > 0) {
        goto leave;  /* object still in use */
    }

    /* delete the local message queue */
    status = MessageQ_delete(&Module.localMsgQue);

    if (status < 0) {
        Log_error1("SvrIpu1_0_destroy: message queue delete error=%d",
                (IArg)status);
        goto leave;
    }

    /* delete the done flag */
    Semaphore_delete(&SvrIpu1_0_doneFlag);

leave:
    /* disable log events */
    Log_print1(Diags_EXIT, "<-- SvrIpu1_0_delete: status=%d", (IArg)status);
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
 *  ======== SvrIpu1_0_run ========
 */
Int SvrIpu1_0_run(Void)
{
    Int                 status = 0;
    Bool                running = TRUE;
    SvrMsg_Msg *        msg;
    MessageQ_QueueId    queId;
    UInt16              procId;

    Log_print0(Diags_ENTRY, "--> SvrIpu1_0_run:");

    while (running) {

        /* wait for inbound message */
        status = MessageQ_get(Module.localMsgQue, (MessageQ_Msg *)&msg,
            MessageQ_FOREVER);

        if (status < 0) {
            Log_error1("SvrIpu1_0_run: message get error=%d", (IArg)status);
            goto leave;
        }

        /* process the message */
        queId = MessageQ_getReplyQueue(msg);
        procId = MessageQ_getProcId(queId);
        Log_print2(Diags_INFO, "SvrIpu1_0_run: message received, procId=%d, "
                "cmd=%d", procId, msg->cmd);

        switch (msg->cmd) {
            case SvrMsg_Cmd_START:
                msg->svrProcId = MultiProc_self();
                break;

            case SvrMsg_Cmd_PROCESS:
                break;

            case SvrMsg_Cmd_STOP:
                running = FALSE;
                break;

            default:
                Log_error1("SvrIpu1_0_run: unknown message, cmd=%d",
                        (IArg)(msg->cmd));
                break;
        }

        /* send message back */
        MessageQ_put(queId, (MessageQ_Msg)msg);

        /* decrement the done flag */
        if (Semaphore_getCount(SvrIpu1_0_doneFlag) > 0) {
            Semaphore_pend(SvrIpu1_0_doneFlag, BIOS_WAIT_FOREVER);
        }

    } /* while (running) */

leave:
    Log_print1(Diags_EXIT, "<-- SvrIpu1_0_run: %d", (IArg)status);
    return(status);
}

/*
 *  ======== SvrIpu1_0_setup ========
 */
Int SvrIpu1_0_setup(Void)
{
    Int                 status = 0;
    Error_Block         eb;
    Int                 count;
    Semaphore_Params    semParams;
    Registry_Result     result;
    MessageQ_Params     msgqParams;
    UInt16              procId;
    Char                cbuf[48];

    /* TODO enter gate */

    /* reference count the module usage */
    if (Mod_curInit >= 1) {
        goto leave;  /* already initialized */
    }

    /* initialize module state */
    Error_init(&eb);
    Module.localMsgQue = NULL;

    /* initialize the done flag */
    Semaphore_Params_init(&semParams);
    semParams.mode = Semaphore_Mode_COUNTING;
    count = MultiProc_getNumProcessors() * SvrMsg_NUM_MSGS;

    SvrIpu1_0_doneFlag = Semaphore_create(count, &semParams, &eb);

    if (Error_check(&eb)) {
        status = -2;
        goto leave;
    }

    /* register with xdc.runtime to get a diags mask */
    result = Registry_addModule(&Registry_CURDESC, MODULE_NAME);

    if ((result != Registry_SUCCESS) && (result != Registry_ALREADY_ADDED)) {
        status = -1;
        goto leave;
    }

    /* enable some trace */
    Diags_setMask(MODULE_NAME"+FEX");
    Log_print0(Diags_ENTRY, "--> SvrIpu1_0_setup:");

    /* compute the server queue name */
    procId = MultiProc_self();
    System_sprintf(cbuf, SvrMsg_SvrQueNameFmt, MultiProc_getName(procId));

    /* create local message queue (inbound messages) */
    MessageQ_Params_init(&msgqParams);
    Module.localMsgQue = MessageQ_create(cbuf, &msgqParams);

    if (Module.localMsgQue == NULL) {
        Log_error0("SvrIpu1_0_setup: message queue create failed");
        goto leave;
    }

    Log_print0(Diags_INFO,"SvrIpu1_0_setup: slave is ready");

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
    Log_print0(Diags_EXIT, "<-- SvrIpu1_0_setup:");
    return(status);
}
