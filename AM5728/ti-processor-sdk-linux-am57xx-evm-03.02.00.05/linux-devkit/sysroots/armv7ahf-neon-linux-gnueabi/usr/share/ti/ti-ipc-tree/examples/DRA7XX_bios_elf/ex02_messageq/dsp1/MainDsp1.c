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
 *  ======== MainDsp1.c ========
 */

/* xdctools header files */
#include <xdc/std.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/System.h>

/* package header files */
#include <ti/ipc/Ipc.h>
#include <ti/ipc/MultiProc.h>

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>

/* local header files */
#include "Server.h"

/* private functions */
Void Server_taskFxn(UArg arg0, UArg arg1);


/*
 *  ======== main ========
 */
int main(int argc, char* argv[])
{
    Int             status;
    Error_Block     eb;
    Task_Params     taskParams;

    Log_print0(Diags_ENTRY, "main: -->");

    /* create main thread (interrupts not enabled in main on BIOS) */
    Task_Params_init(&taskParams);
    taskParams.instance->name = "Server_taskFxn";
    taskParams.arg0 = (UArg)argc;
    taskParams.arg1 = (UArg)argv;
    taskParams.stackSize = 0x1000;
    Error_init(&eb);

    Task_create(Server_taskFxn, &taskParams, &eb);

    if (Error_check(&eb)) {
        System_abort("main: failed to create application startup thread");
    }

    /* start scheduler, this never returns */
    BIOS_start();

    /* should never get here */
    Log_print0(Diags_EXIT, "main: <--");
    return (0);
}

/*
 *  ======== Server_taskFxn ========
 */
Void Server_taskFxn(UArg arg0, UArg arg1)
{
    Int     status;
    UInt16  remoteProcId;

    Log_print0(Diags_INFO, "Server_taskFxn: -->");

    /*
     *  initialize the ipc layer
     */
    status = Ipc_start();

    if (status < 0) {
        System_abort("Ipc_start failed\n");
    }

    remoteProcId = MultiProc_getId("HOST");
    if (remoteProcId == MultiProc_INVALIDID) {
        System_abort("Improper MultiProc ID\n");
    }
    do {
        status = Ipc_attach(remoteProcId);

    } while ((status < 0) && (status == Ipc_E_NOTREADY));

    Log_print0(Diags_INFO, "Server_taskFxn: ipc ready");

    /* initialize the server module */
    Server_init();
    Diags_setMask("Server+F"); /* turn on some trace */

    /* create a server instance */
    status = Server_create();

    if (status < 0) {
        goto leave;
    }

    /* start the server */
    status = Server_exec();

    if (status < 0) {
        goto leave;
    }

    /* finalize the server */
    status = Server_delete();

    if (status < 0) {
        goto leave;
    }

    /* finalize the server module */
    Server_exit();

leave:
    Log_print1(Diags_INFO, "Server_taskFxn: <-- status=%d", (IArg)status);
    return;
}
