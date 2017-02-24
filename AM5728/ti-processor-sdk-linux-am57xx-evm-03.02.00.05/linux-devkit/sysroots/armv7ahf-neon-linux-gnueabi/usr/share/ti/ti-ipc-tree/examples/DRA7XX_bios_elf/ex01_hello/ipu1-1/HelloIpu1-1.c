/*
 * Copyright (c) 2012-2014 Texas Instruments Incorporated - http://www.ti.com
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
 *  ======== HelloIpu1-1.c ========
 *  Platform: DRA7XX_bios_elf
 */

/* package header files */
#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/System.h>

#include <ti/ipc/Ipc.h>
#include <ti/ipc/MessageQ.h>
#include <ti/ipc/MultiProc.h>
#include <ti/ipc/SharedRegion.h>

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>

/* local header files */
#include "../shared/SysCfg.h"


/* private functions */
Void App_taskFxn(UArg arg0, UArg arg1);
int App_reader(void);
int App_writer(void);

/* define application role */
#define Role_READER 1
#define Role_WRITER 2

#error Must define role and peer
Int role = ;                    /* role of this processor */
String peer = ;                 /* name of peer processor */


/*
 *  ======== main ========
 */
int main(int argc, char *argv[])
{
    Error_Block eb;
    Task_Params taskParams;

    Log_print0(Diags_ENTRY, "main: -->");

    /* create main thread (interrupts not enabled in main on BIOS) */
    Task_Params_init(&taskParams);
    taskParams.instance->name = "App_taskFxn";
    taskParams.arg0 = (UArg)argc;
    taskParams.arg1 = (UArg)argv;
    taskParams.stackSize = 0x1000;
    Error_init(&eb);

    Task_create(App_taskFxn, &taskParams, &eb);

    if (Error_check(&eb)) {
        System_abort("main: failed to create application thread");
    }

    /* start scheduler, this never returns */
    BIOS_start();

    /* should never get here */
    Log_print0(Diags_EXIT, "main: <--");
    return (0);
}

/*
 *  ======== App_taskFxn ========
 */
Void App_taskFxn(UArg arg0, UArg arg1)
{
    Int     status;
    UInt16  remoteProcId;

    Log_print0(Diags_ENTRY, "App_taskFxn: -->");

    /*
     *  initialize the ipc layer
     */
    status = Ipc_start();

    if (status < 0) {
        System_abort("Ipc_start failed\n");
    }

    remoteProcId = MultiProc_getId(peer);
    do {
        status = Ipc_attach(remoteProcId);

    } while ((status < 0) && (status == Ipc_E_NOTREADY));

    Log_print0(Diags_INFO, "App_taskFxn: ipc ready");


    /* perform application role */
    if (role == Role_READER) {
        App_reader();
    }
    else if (role == Role_WRITER) {
        App_writer();
    }
    else {
        System_abort("main: invalid application role");
    }

    Log_print0(Diags_EXIT, "App_taskFxn: <--");
}

/*
 *  ======== App_reader ========
 */
int App_reader(void)
{
    Int                 status;
    MessageQ_Handle     que;
    SysCfg_Msg          *msg;
    Ptr                 heap;
    Bool                running = TRUE;


    Log_print0(Diags_ENTRY, "App_reader: -->");

    /* use SR_0 heap for messages */
    heap = SharedRegion_getHeap(0);
    MessageQ_registerHeap(heap, 0);

    /* create local message queue (inbound messages) */
    que = MessageQ_create("ReaderQ", NULL);

    if (que == NULL) {
        Log_error0("App_reader: MessageQ_create failed");
        goto leave;
    }

    Log_print0(Diags_INFO, "App_reader: reader is ready");

    /* main process loop */
    while (running) {

        /* wait for inbound message */
        status = MessageQ_get(que, (MessageQ_Msg *)&msg, MessageQ_FOREVER);

        if (status < 0) {
            Log_error1("App_reader: MessageQ_get error=%d", (IArg)status);
            goto leave;
        }

        /* process the message */
        switch (msg->cmd) {
            case SysCfg_Cmd_PROCESS:
                Log_print1(Diags_INFO, "App_reader: received job=%d",
                        (IArg)(msg->job));
                /* ... */
                break;

            case SysCfg_Cmd_STOP:
                Log_print0(Diags_INFO, "App_reader: received stop message");
                running = FALSE;
                break;

            default:
                Log_error1("App_reader: unknown cmd=%d", (IArg)(msg->cmd));
                break;
        }

        MessageQ_free((MessageQ_Msg)msg);

    } /* while (running) */

    /* delete the local message queue */
    status = MessageQ_delete(&que);

    if (status < 0) {
        Log_error1("App_reader: MessageQ_delete error=%d", (IArg)status);
        goto leave;
    }

leave:
    Log_print1(Diags_EXIT, "App_reader: <-- %d", (IArg)status);
    return(status);
}

/*
 *  ======== App_writer ========
 */
int App_writer(void)
{
    Int                 status, i;
    Ptr                 heap;
    MessageQ_QueueId    que;
    SysCfg_Msg          *msg;

    Log_print0(Diags_ENTRY, "App_writer: -->");

    /* use SR_0 heap for messages */
    heap = SharedRegion_getHeap(0);
    MessageQ_registerHeap(heap, 0);

    /* open the reader message queue, loop until queue is available */
    do {
        status = MessageQ_open("ReaderQ", &que);

        if (status == MessageQ_E_NOTFOUND) {
            Task_sleep(1);
        }
    } while (status == MessageQ_E_NOTFOUND);

    if (status < 0) {
        Log_error0("App_writer: could not open reader message queue");
        goto leave;
    }

    Log_print0(Diags_INFO, "App_writer: opened reader queue");

    /* send process messages */
    for (i = 1; i <= 10; i++) {

        /* allocate a message */
        msg = (SysCfg_Msg *)MessageQ_alloc(0, sizeof(SysCfg_Msg));

        if (msg == NULL) {
            Log_error0("App_writer: MessageQ_alloc failed");
            goto leave;
        }

        /* fill in the message */
        msg->cmd = SysCfg_Cmd_PROCESS;
        msg->job = i;

        Log_print1(Diags_INFO, "App_writer: sending job=%d", (IArg)(msg->job));

        /* send the message */
        status = MessageQ_put(que, (MessageQ_Msg)msg);

        if (status < 0) {
            Log_error1("App_writer: MessageQ_put error=%d", (IArg)status);
            goto leave;
        }
    }

    /* send stop message */
    msg = (SysCfg_Msg *)MessageQ_alloc(0, sizeof(SysCfg_Msg));

    if (msg == NULL) {
        Log_error0("App_writer: MessageQ_alloc failed");
        goto leave;
    }

    /* fill in the message */
    msg->cmd = SysCfg_Cmd_STOP;

    /* send the message */
    status = MessageQ_put(que, (MessageQ_Msg)msg);

    if (status < 0) {
        Log_error1("App_writer: MessageQ_put error=%d", (IArg)status);
        goto leave;
    }

    /* close the queue */
    status = MessageQ_close(&que);

    if (status < 0) {
        Log_error1("App_writer: MessageQ_close error=%d", (IArg)status);
        goto leave;
    }

leave:
    Log_print1(Diags_EXIT, "App_writer: <-- %d", (IArg)status);
    return(status);
}
