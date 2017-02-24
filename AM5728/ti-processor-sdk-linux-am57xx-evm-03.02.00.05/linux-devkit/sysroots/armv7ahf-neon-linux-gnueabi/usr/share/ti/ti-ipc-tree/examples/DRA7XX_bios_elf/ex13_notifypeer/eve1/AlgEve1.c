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
 *  ======== AlgEve1.c ========
 *  Platform: DRA7XX_bios_elf
 */

/* this define must precede inclusion of any xdc header file */
#define Registry_CURDESC AlgEve1__Desc
#define MODULE_NAME "AlgEve1"

/* package header files */
#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Registry.h>
#include <xdc/runtime/Timestamp.h>
#include <xdc/runtime/Types.h>

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/knl/Task.h>

#include <ti/ipc/MultiProc.h>
#include <ti/ipc/Notify.h>

/* local header files */
#include "AlgEve1.h"
#include "../shared/NotifyMsg.h"

/* queue size, must be a power of 2 */
#define Event_QSZ (1 << 4)

/* queue structure */
typedef struct
{
    UInt32              queue[Event_QSZ];   /* command queue */
    UInt32              head;               /* dequeue from head pointer */
    UInt32              tail;               /* enqueue at tail pointer */
    UInt32              error;              /* error flag */
    Semaphore_Struct    semObj;             /* semaphore object */
    Semaphore_Handle    sem;                /* semaphore handle */
} Notify_Queue;

/* module structure */
typedef struct {
    UInt16              peerId;             /* MultiProc ID */
    Notify_Queue        notifyQ;
} AlgEve1_Module;

/* private data */
Registry_Desc           Registry_CURDESC;
static Int              Mod_curInit = 0;
static AlgEve1_Module   Module;

/* private functions */
Void AlgEve1_doWork(UInt usec);
Void AlgEve1_notifyCB(UInt16, UInt16, UInt32, UArg, UInt32);
UInt32 AlgEve1_waitForEvent(Notify_Queue *queue);


/*
 *  ======== AlgEve1_doWork ========
 */
Void AlgEve1_doWork(UInt usec)
{
    UInt32 start, now;
    UInt32 count;
    Types_FreqHz freq;
    Task_Handle tid = Task_selfMacro();

    /* latch the start timestamp */
    start = Timestamp_get32();

    /* compute delay in timestamp counts */
    Timestamp_getFreq(&freq);
    count = (freq.lo / 1000000) * usec;

    do {
        now = Timestamp_get32();
    } while ((now - start) < count);

}

/*
 *  ======== AlgEve1_waitForEvent ========
 */
UInt32 AlgEve1_waitForEvent(Notify_Queue *queue)
{
    UInt32 event;

    /* check for queue error */
    if (queue->error >= NotifyMsg_E_FAILURE) {
        event = queue->error;
    }
    else {
        /* use counting semaphore to wait for next event */
        Semaphore_pend(queue->sem,  BIOS_WAIT_FOREVER);

        /* remove next command from queue */
        event = queue->queue[queue->head];
        queue->head++;
    }

    return (event);
}

/*
 *  ======== AlgEve1_destroy ========
 */
Int AlgEve1_destroy(Void)
{
    Int status = 0;

    Log_print0(Diags_ENTRY, "AlgEve1_destroy: -->");

    /* reference count the module usage */
    if (--Mod_curInit > 0) {
        goto leave;  /* object still in use */
    }

    /* unregister notify callback only with remote processors */
    status = Notify_unregisterEventSingle(Module.peerId, 0, NotifyMsg_Evt_EVE);

    if (status < 0) {
        Log_error2("AlgEve1_destroy: notify unregister error, "
                "procId=%d, error=%d", (IArg)Module.peerId, (IArg)status);
        goto leave;
    }

    /* destruct the queue's semaphore */
    Semaphore_destruct(&Module.notifyQ.semObj);
    Module.notifyQ.sem = NULL;

leave:
    /* disable log events */
    Log_print1(Diags_EXIT, "AlgEve1_destroy: <-- status=%d", (IArg)status);
    Diags_setMask(MODULE_NAME"-FEX");

    /*
     * Note that there isn't a Registry_removeModule() yet:
     *     https://bugs.eclipse.org/bugs/show_bug.cgi?id=315448
     *
     * ... but this is where we'd call it.
     */

    return(status);
}

/*
 *  ======== AlgEve1_notifyCB ========
 *  This function runs with the notify callback disabled. It will not
 *  be preempted by another notify event.
 */
Void AlgEve1_notifyCB(UInt16 procId, UInt16 lineId, UInt32 eventId, UArg arg,
        UInt32 payload)
{
    Notify_Queue *Q = (Notify_Queue *)arg;

    /* handle ping message, reply with pong message  */
    if ((payload & 0xFFFF0000) == Notify_Evt_PING) {
        Notify_sendEvent(procId, lineId, NotifyMsg_Evt_EVE, Notify_Evt_PONG,
                FALSE);
    }

    /* if queue is full, set error flag */
    else if ((Q->head + Event_QSZ) == Q->tail) {
        Q->error = NotifyMsg_E_OVERFLOW;
    }

    /* save payload in queue, release waiting task */
    else {
        Q->queue[Q->tail % Event_QSZ] = payload;
        Q->tail++;
        Semaphore_post(Q->sem);
    }
}

/*
 *  ======== AlgEve1_run ========
 */
Int AlgEve1_run(Void)
{
    Int         status = 0;
    UInt32      event;
    Bool        running = TRUE;
    UInt16      procId;
    UInt8       job;

    Log_print0(Diags_ENTRY, "AlgEve1_run: -->");

    while (running) {

        /* wait for inbound event */
        event = AlgEve1_waitForEvent(&Module.notifyQ);

        if (event >= NotifyMsg_E_FAILURE) {
            Log_error1("AlgEve1_run: event error 0x%x", (IArg)event);
            goto leave;
        }

        /* extract data from event */
        job = (UInt8)event;

        Log_print1(Diags_INFO, "AlgEve1_run: event received, job=%d, ",
                (IArg)job);

        /* process the message */
        AlgEve1_doWork(10000);

        /* send message back */
        status = Notify_sendEvent(Module.peerId, 0, NotifyMsg_Evt_EVE,
                (UInt32)job, TRUE);

        if (status < 0) {
            Log_error2("AlgEve1_run: Notify_sendEvent error=%d, "
                    "procId=%d", (IArg)status, (IArg)procId);
            goto leave;
        }

        Log_print2(Diags_INFO, "AlgEve1_run: event sent, procId=%d, job=%d",
                (IArg)Module.peerId, (IArg)job);

    } /* while (running) */

leave:
    Log_print1(Diags_EXIT, "AlgEve1_run: <-- status=%d", (IArg)status);
    return(status);
}

/*
 *  ======== AlgEve1_setup ========
 */
Int AlgEve1_setup(UInt16 remoteProcId)
{
    Int                 status = 0;
    Semaphore_Params    semParams;
    Registry_Result     result;

    /* reference count the module usage */
    if (Mod_curInit >= 1) {
        goto leave;  /* already initialized */
    }

    /* register with xdc.runtime to get a diags mask */
    result = Registry_addModule(&Registry_CURDESC, MODULE_NAME);

    if ((result != Registry_SUCCESS) && (result != Registry_ALREADY_ADDED)) {
        status = -1;
        goto leave;
    }

    /* enable some trace */
    Diags_setMask(MODULE_NAME"+FEX");
    Log_print0(Diags_ENTRY, "AlgEve1_setup: -->");

    /* initialize module state */
    Module.peerId = remoteProcId;
    Module.notifyQ.head = 0;
    Module.notifyQ.tail = 0;
    Module.notifyQ.error = NotifyMsg_S_SUCCESS;
    Module.notifyQ.sem = NULL;

    /* construct the semaphore for the queue */
    Semaphore_Params_init(&semParams);
    semParams.mode = Semaphore_Mode_COUNTING;
    Semaphore_construct(&Module.notifyQ.semObj, 0, &semParams);
    Module.notifyQ.sem = Semaphore_handle(&Module.notifyQ.semObj);

    /* register notify callback only with remote processors */
    status = Notify_registerEventSingle(Module.peerId, 0,
            NotifyMsg_Evt_EVE, AlgEve1_notifyCB, (UArg)(&Module.notifyQ));

    if (status < 0) {
        Log_error1("AppEve1_setup: notify register error=%d", (IArg)status);
        goto leave;
    }

    Log_print0(Diags_INFO,"AlgEve1_setup: slave is ready");

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

    Log_print1(Diags_EXIT, "AlgEve1_setup: <-- status=%d", (IArg)status);
    return(status);
}
