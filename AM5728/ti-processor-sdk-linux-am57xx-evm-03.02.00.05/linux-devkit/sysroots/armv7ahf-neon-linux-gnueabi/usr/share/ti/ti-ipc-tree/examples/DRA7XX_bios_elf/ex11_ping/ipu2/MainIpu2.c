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
 *  ======== MainIpu2.c ========
 *  Platform: DRA7XX_bios_elf
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
#include "AppIpu2.h"
#include "SvrIpu2.h"

#define PRI_HIGH        5
#define PRI_MED         3

/* private functions */
static Void MainIpu2_appTskFxn(UArg arg0, UArg arg1);
static Void MainIpu2_svrTskFxn(UArg arg0, UArg arg1);
static Void MainIpu2_done(Void);


/*
 *  ======== main ========
 */
Int main(Int argc, Char* argv[])
{
    Int             status;
    Error_Block     eb;
    Task_Params     taskParams;

    Log_print0(Diags_ENTRY, "--> main:");

    /* must initialize the error block before using it */
    Error_init(&eb);

    /* initialize the ipc layer */
    status = Ipc_start();

    if (status < 0) {
        System_abort("Ipc_start failed\n");
    }

    Log_print0(Diags_INFO, "main: ipc ready");

    /* create server thread */
    Task_Params_init(&taskParams);
    taskParams.instance->name = "Svr";
    taskParams.priority = PRI_HIGH;
    taskParams.arg0 = (UArg)argc;
    taskParams.arg1 = (UArg)argv;
    taskParams.stackSize = 0x600;
    Task_create(MainIpu2_svrTskFxn, &taskParams, &eb);

    if (Error_check(&eb)) {
        System_abort("main: failed to create server thread");
    }

    /* create application thread */
    Task_Params_init(&taskParams);
    taskParams.instance->name = "App";
    taskParams.priority = PRI_MED;
    taskParams.arg0 = (UArg)argc;
    taskParams.arg1 = (UArg)argv;
    taskParams.stackSize = 0x600;
    Task_create(MainIpu2_appTskFxn, &taskParams, &eb);

    if (Error_check(&eb)) {
        System_abort("main: failed to create application thread");
    }

    /* start scheduler, this never returns */
    BIOS_start();

    /* should never get here */
    Log_print0(Diags_EXIT, "<-- main:");
    return (0);
}

/*
 *  ======== MainIpu2_appTskFxn ========
 */
Void MainIpu2_appTskFxn(UArg arg0, UArg arg1)
{
    Int status = 0;

    Log_print0(Diags_ENTRY | Diags_INFO, "--> MainIpu2_appTskFxn:");

    /* application setup phase */
    status = AppIpu2_setup();

    if (status < 0) {
        goto leave;
    }

    /* application execute phase */
    status = AppIpu2_run();

    if (status < 0) {
        goto leave;
    }

    /* application shutdown phase */
    status = AppIpu2_destroy();

    if (status < 0) {
        goto leave;
    }

leave:
    Log_print1(Diags_EXIT | Diags_INFO, "<-- MainIpu2_appTskFxn: %d",
            (IArg)status);

    /* ccs debug hook */
    MainIpu2_done();
}

/*
 *  ======== MainIpu2_svrTskFxn ========
 */
Void MainIpu2_svrTskFxn(UArg arg0, UArg arg1)
{
    Int status = 0;

    Log_print0(Diags_ENTRY | Diags_INFO, "--> MainIpu2_svrTskFxn:");

    /* server setup phase */
    status = SvrIpu2_setup();

    if (status < 0) {
        goto leave;
    }

    /* server execute phase */
    status = SvrIpu2_run();

    if (status < 0) {
        goto leave;
    }

    /* server shutdown phase */
    status = SvrIpu2_destroy();

    if (status < 0) {
        goto leave;
    }

leave:
    Log_print1(Diags_EXIT | Diags_INFO, "<-- MainIpu2_svrTskFxn: %d",
            (IArg)status);
}

/*
 *  ======== MainIpu2_done ========
 */
Void MainIpu2_done(Void)
{
    Log_print0(Diags_INFO, "MainIpu2_done:");
}
