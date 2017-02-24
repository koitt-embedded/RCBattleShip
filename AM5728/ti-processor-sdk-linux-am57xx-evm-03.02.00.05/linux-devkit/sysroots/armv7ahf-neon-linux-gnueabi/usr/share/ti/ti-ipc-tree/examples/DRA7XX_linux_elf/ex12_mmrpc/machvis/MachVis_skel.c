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
 *  ======== MachVis_skel.c ========
 *
 *  Example of how to integrate the MachVis module with the
 *  MmService manager.
 */
#include <stddef.h>
#include <stdint.h>

#include <xdc/std.h>
#include <xdc/runtime/System.h>

#include <ti/grcm/RcmServer.h>
#include <ti/ipc/mm/MmType.h>
#include <ti/ipc/mm/MmServiceMgr.h>
#include <ti/sysbios/hal/Cache.h>

#include "MachVis.h"
#include "MachVis_skel.h"

void MachVis_startup(void);
void (*fp)(void) = MachVis_startup;

/* MachVis skel function declarations */
static Int32 MachVis_add_skel(UInt32 size, UInt32 *data);
static Int32 MachVis_compute_skel(UInt32 size, UInt32 *data);

/* skel function array */
static RcmServer_FxnDesc skelAry[] = {
    { "MachVis_add",        MachVis_add_skel        },
    { "MachVis_compute",    MachVis_compute_skel    }
};

/* skel function table */
static const RcmServer_FxnDescAry skelTab = {
    (sizeof(skelAry) / sizeof(skelAry[0])),
    skelAry
};

/* function signature array */
static MmType_FxnSig sigAry[] = {
    { "MxServer_add", 3,
        {
            { MmType_Dir_Out, MmType_Param_S32, 1 }, /* return */
            { MmType_Dir_In,  MmType_Param_S32, 1 },
            { MmType_Dir_In,  MmType_Param_S32, 1 }
        }
    },
    { "MxServer_compute", 2,
        {
            { MmType_Dir_Out, MmType_Param_S32, 1 }, /* return */
            { MmType_Dir_In,  MmType_PtrType(MmType_Param_VOID), 1 }
        }
    }
};

/* function signature table */
static MmType_FxnSigTab sigTab = {
    MmType_NumElem(sigAry), sigAry
};

/* the server create parameters, must be in persistent memory */
static RcmServer_Params rcmParams;


Void RPC_SKEL_SrvDelNotification(Void)
{
    System_printf("RPC_SKEL_SrvDelNotification: Nothing to cleanup for "
        "Mm service instance id=%d\n", MmServiceMgr_getId());
}

/*
 *  ======== MachVis_add_skel ========
 */
Int32 MachVis_add_skel(UInt32 size, UInt32 *data)
{
    MmType_Param *payload = (MmType_Param *)data;
    Int32 a, b;
    Int32 result;

    System_printf("skel_add: For mm service instance id %d\n",
        MmServiceMgr_getId());

    a = (Int32)payload[0].data;
    b = (Int32)payload[1].data;

    result = MachVis_add(a, b);

    return(result);
}

/*
 *  ======== MachVis_compute_skel ========
 */
Int32 MachVis_compute_skel(UInt32 size, UInt32 *data)
{
    MmType_Param *payload;
    MachVis_Compute *compute;
    Int32 result = 0;

    payload = (MmType_Param *)data;
    compute = (MachVis_Compute *)payload[0].data;

    System_printf("skel_compute: For mm service instance id %d\n",
        MmServiceMgr_getId());

    System_printf("skel_compute: compute=0x%x\n", compute);
    System_printf("skel_compute: compute size=%d\n", (Int)payload[0].size);
    System_printf("skel_compute: coef=0x%x\n", compute->coef);
    System_printf("skel_compute: key=0x%x\n", compute->key);
    System_printf("skel_compute: size=0x%x\n", compute->size);
    System_printf("skel_compute: inBuf=0x%x\n", compute->inBuf);
    System_printf("skel_compute: outBuf=0x%x\n", compute->outBuf);

    Cache_inv(compute->inBuf, compute->size * sizeof(uint32_t),
            Cache_Type_ALL, TRUE);
    Cache_inv(compute->outBuf, compute->size * sizeof(uint32_t),
            Cache_Type_ALL, TRUE);

    /* invoke the implementation function */
    result = MachVis_compute(compute);

    Cache_wbInv(compute->outBuf, compute->size * sizeof(uint32_t),
            Cache_Type_ALL, TRUE);

    return(result);
}

/*
 *  ======== MachVis_startup ========
 *
 *  Service startup function. This function must be added to the
 *  BIOS.addUserStartupFunctions configuration parameter.
 */
void MachVis_startup(void)
{
    Int status = MmServiceMgr_S_SUCCESS;

    System_printf("MachVis_startup: -->\n");

    /* must initialize these modules before using them */
    RcmServer_init();
    MmServiceMgr_init();

    /* setup the server create params */
    RcmServer_Params_init(&rcmParams);
    rcmParams.priority = Thread_Priority_ABOVE_NORMAL;
    rcmParams.stackSize = 0x1000;
    rcmParams.fxns.length = skelTab.length;
    rcmParams.fxns.elem = skelTab.elem;

    /* register an example service */
    status = MmServiceMgr_register(MachVis_SERVICE, &rcmParams, &sigTab,
            RPC_SKEL_SrvDelNotification);

    if (status < 0) {
        System_printf("MachVis_startup: MmServiceMgr_register failed, "
                "status=%d\n", status);
        status = -1;
        goto leave;
    }

leave:
    System_printf("MachVis_startup: <--, status=%d\n", status);
}
