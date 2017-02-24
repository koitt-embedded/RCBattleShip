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
 *  ======== MainEve2.c ========
 *  Platform: DRA7XX_bios_elf
 */

/* package header files */
#include <xdc/std.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/System.h>

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>

#include <ti/ipc/MultiProc.h>
#include <ti/ipc/Notify.h>

/* local header files */
#include "AlgEve2.h"
#include "../shared/NotifyMsg.h"

/* private functions */
static Void MainEve2_mainTskFxn(UArg arg0, UArg arg1);

String peer = "DSP1";           /* name of peer processor */

/*
 *  ======== main ========
 */
Int main(Int argc, Char* argv[])
{
    UInt16      procId;
    Error_Block eb;
    Task_Params taskParams;

    Log_print0(Diags_ENTRY, "main: -->");

    /* initialize the ipc layer (only with remote processors) */
    procId = MultiProc_getId(peer);
    Notify_attach(procId, 0);
    Log_print0(Diags_INFO, "main: ipc ready");

    /* create main thread */
    Task_Params_init(&taskParams);
    taskParams.instance->name = "AlgTsk";
    taskParams.priority = 3;
    taskParams.arg0 = (UArg)argc;
    taskParams.arg1 = (UArg)argv;
    taskParams.stackSize = 0x600;
    Error_init(&eb);

    Task_create(MainEve2_mainTskFxn, &taskParams, &eb);

    if (Error_check(&eb)) {
        System_abort("main: failed to create server thread");
    }

    Log_print0(Diags_INFO, "main: --> BIOS_start");

    /* start scheduler, this never returns */
    BIOS_start();

    /* should never get here */
    Log_print0(Diags_EXIT, "main: <--");
    return (0);
}

/*
 *  ======== MainEve2_mainTskFxn ========
 */
Void MainEve2_mainTskFxn(UArg arg0, UArg arg1)
{
    Int status = 0;

    Log_print0(Diags_ENTRY | Diags_INFO, "MainEve2_svrTskFxn: -->");

    /* server setup phase */
    status = AlgEve2_setup(MultiProc_getId(peer));

    if (status < 0) {
        goto leave;
    }

    /* server execute phase */
    status = AlgEve2_run();

    if (status < 0) {
        goto leave;
    }

    /* server shutdown phase */
    status = AlgEve2_destroy();

    if (status < 0) {
        goto leave;
    }

leave:
    Log_print1(Diags_EXIT | Diags_INFO, "MainEve2_svrTskFxn: <-- %d",
            (IArg)status);
}
