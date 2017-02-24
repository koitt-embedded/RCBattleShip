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
 *
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
#include <xdc/runtime/Timestamp.h>
#include <xdc/runtime/Types.h>

#include <stdio.h>

/* package header files */
#include <ti/ipc/Ipc.h>
#include <ti/ipc/MessageQ.h>
#include <ti/ipc/MultiProc.h>
#include <ti/ipc/Notify.h>

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Event.h>
#include <ti/sysbios/knl/Queue.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/syncs/SyncSem.h>

/* local header files */
#include "../shared/AppCommon.h"
#include "../shared/NotifyMsg.h"

/* module header file */
#include "Server.h"

/* define the EVE peer */
//#define EVE "EVE1"

/* queue size, must be a power of 2 */
#define Event_QSZ (1 << 4)

#if defined(EVE)
/* ipc handshake object */
typedef struct {
    Semaphore_Handle            sem;
    struct Semaphore_Struct     semObj;     /* block caller until pong recv'd */
} Handshake;
#endif

/* queue structure */
typedef struct {
    UInt32              queue[Event_QSZ];   /* command queue */
    UInt32              head;               /* dequeue from head pointer */
    UInt32              tail;               /* enqueue at tail pointer */
    UInt32              error;              /* error flag */
} Notify_Queue;

/* module structure */
typedef struct {
    UInt16              hostProcId;         /* host processor id */
    UInt16              eveProcId;          /* eve processor id */
    MessageQ_Handle     messageQ;           /* created locally */
    Notify_Queue        notifyQ;            /* receive events from eve */
#if defined(EVE)
    Queue_Handle        holdQ;
    Event_Handle        event;
    Semaphore_Handle    sem;
    SyncSem_Handle      sync;
#endif
} Server_Module;

/* private functions */
Void Server_doWork(Void);
UInt32 Server_dequeueEvent(Notify_Queue *Q);
Void Server_notifyCB(UInt16, UInt16, UInt32, UArg, UInt32);
Void Server_pingFxn(UArg arg);

/* private data */
Registry_Desc               Registry_CURDESC;
static Server_Module        Module;
#if defined(EVE)
static Handshake            IpcHandshake;
#endif


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
#if defined(EVE)
    Module.eveProcId = MultiProc_getId(EVE);
#else
    Module.eveProcId = MultiProc_INVALIDID;
#endif
    Module.messageQ = NULL;
    Module.notifyQ.head = 0;
    Module.notifyQ.tail = 0;
    Module.notifyQ.error = NotifyMsg_S_SUCCESS;
}

/*
 *  ======== Server_create ========
 */
Int Server_create()
{
    Int                 status = 0;
    UInt16              remoteProcId;
#if defined(EVE)
    Event_Params        eventP;
    Semaphore_Params    semP;
    SyncSem_Params      syncSemP;
    Clock_Params        clockP;
    Clock_Handle        pingPRD;
#endif
    MessageQ_Params     msgQueP;

    /* enable some log events */
    Diags_setMask(MODULE_NAME"+EXF");

#if defined(EVE)
    /* setup IPC-notify with eve processor */
    Notify_attach(Module.eveProcId, 0);

   /* register notify callback */
    status = Notify_registerEventSingle(Module.eveProcId, 0,
            NotifyMsg_Evt_EVE, Server_notifyCB, (UArg)(&Module.notifyQ));

    if (status < 0) {
        Log_error1("Server_create: notify register error=%d", (IArg)status);
        goto leave;
    }

    /* initialize the handshake object */
    Semaphore_Params_init(&semP);
    semP.mode = Semaphore_Mode_BINARY;
    Semaphore_construct(&IpcHandshake.semObj, 0, &semP);
    IpcHandshake.sem = Semaphore_handle(&IpcHandshake.semObj);

    /* create periodic function to ping eve processor */
    Clock_Params_init(&clockP);
    clockP.arg = NULL;
    clockP.period = 2;
    clockP.startFlag = TRUE;
    pingPRD = Clock_create(Server_pingFxn, 1, &clockP, NULL);

    /* block until pong message is received */
    Semaphore_pend(IpcHandshake.sem, BIOS_WAIT_FOREVER);

    /* stop the ping function */
    Clock_stop(pingPRD);
    Task_sleep(5);
    Clock_delete(&pingPRD);
#endif

    /* setup IPC-full with host processor */
    status = Ipc_start();

    if (status < 0) {
        Log_error1("Server_create: Ipc_start failed, error=%d", (IArg)status);
        goto leave;
    }

    remoteProcId = MultiProc_getId("HOST");
    do {
        status = Ipc_attach(remoteProcId);

    } while ((status < 0) && (status == Ipc_E_NOTREADY));

    Log_print0(Diags_INFO, "Server_create: ipc to host is ready");

#if defined(EVE)
    /* create the message holding queue (messages from host) */
    Module.holdQ = Queue_create(NULL, NULL);

    /* create event object needed by message queue and notify callback */
    Event_Params_init(&eventP);
    Module.event = Event_create(&eventP, NULL);

    /* create semaphore needed by synchronizer */
    Semaphore_Params_init(&semP);
    semP.event = Module.event;
    semP.eventId = Event_Id_01; /* message queue */
    semP.mode = Semaphore_Mode_BINARY;

    Module.sem = Semaphore_create(0, &semP, NULL);

    /* create synchronizer needed by message queue */
    SyncSem_Params_init(&syncSemP);
    syncSemP.sem = Module.sem;

    Module.sync = SyncSem_create(&syncSemP, NULL);
#endif

    /* create local message queue (inbound messages) */
    MessageQ_Params_init(&msgQueP);
#if defined(EVE)
    msgQueP.synchronizer = (Void *)(Module.sync);
#endif

    Module.messageQ = MessageQ_create(App_ServerQue, &msgQueP);

    if (Module.messageQ == NULL) {
        status = -1;
        goto leave;
    }

    Log_print0(Diags_INFO,"Server_create: server is ready");

leave:
    Log_print1(Diags_EXIT, "Server_create: <-- %d", (IArg)status);
    return (status);
}

/*
 *  ======== Server_doWork ========
 *  Simulate some work effort
 */
Void Server_doWork(Void)
{
    UInt32 start, now;
    UInt32 count;
    Types_FreqHz freq;
    UInt32 usec;
    Task_Handle tid = Task_selfMacro();

    /* set delay value */
    usec = 3000; /* 3 ms */

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
 *  ======== Server_exec ========
 */
Int Server_exec()
{
    Int                 status;
    Bool                running = TRUE;
    App_Msg *           msg;
    MessageQ_QueueId    queId;
#if defined(EVE)
    UInt32              job;
    UInt                evts;
    Int                 offset;
#endif

    Log_print0(Diags_ENTRY | Diags_INFO, "Server_exec: -->");

    while (running) {
        msg = NULL;
#if defined(EVE)
        job = 0;

        /* wait on next event: notify or message */
        evts = Event_pend(Module.event, Event_Id_NONE, Event_Id_01|Event_Id_00,
                BIOS_WAIT_FOREVER);

        if (evts & Event_Id_00) {
            /* get payload from the notify queue */
            job = Server_dequeueEvent(&Module.notifyQ);
        }
        if (evts & Event_Id_01) {
            /* get message from message queue */
            MessageQ_get(Module.messageQ, (MessageQ_Msg *)&msg, BIOS_NO_WAIT);
        }
#else
        /* wait for inbound message */
        status = MessageQ_get(Module.messageQ, (MessageQ_Msg *)&msg,
            MessageQ_FOREVER);

        if (status < 0) {
            goto leave;
        }
#endif

        /* process the message */
        if ((msg != NULL) && (msg->cmd == App_CMD_PROCESS)) {
            Log_print1(Diags_INFO, "Server_exec: received from host, job=%d",
                    (IArg)msg->job);
#if defined(EVE)
            /* hold the message until job is done */
            Queue_enqueue(Module.holdQ, &(msg->elem));

            Log_print1(Diags_INFO, "Server_exec: sent to eve, job=%d",
                    (IArg)msg->job);

            /* dispatch work to eve */
            status = Notify_sendEvent(Module.eveProcId, 0, NotifyMsg_Evt_EVE,
                    msg->job, TRUE);

            if (status < 0) {
                Log_error2("Server_exec: Notify_sendEvent error=%d, "
                        "procId=%d", (IArg)status, (IArg)Module.eveProcId);
                goto leave;
            }
#else
            /* do work */
            Server_doWork();

            /* send message back */
            queId = MessageQ_getReplyQueue(msg); /* type-cast not needed */
            MessageQ_put(queId, (MessageQ_Msg)msg);
#endif
        }
        else if ((msg != NULL) && (msg->cmd == App_CMD_SHUTDOWN)) {
            running = FALSE;

            /* send message back */
            queId = MessageQ_getReplyQueue(msg); /* type-cast not needed */
            MessageQ_put(queId, (MessageQ_Msg)msg);
        }

#if defined(EVE)
        /* process the notify event */
        if (job != 0) {

            Log_print1(Diags_INFO, "Server_exec: received from eve, job=%d",
                    (IArg)job);

            /* retrieve message for the given job */
            msg = Queue_dequeue(Module.holdQ); /* returns pointer to elem */

            /* compute start address of message */
            offset = (Int)&(((App_Msg *)0)->elem);
            msg = (App_Msg *)((Char *)msg - offset);

            Log_print1(Diags_INFO, "Server_exec: send to host, job=%d (done)",
                    (IArg)msg->job);

            /* send message back to client */
            queId = MessageQ_getReplyQueue(msg); /* type-cast not needed */
            MessageQ_put(queId, (MessageQ_Msg)msg);
        }
#endif
    } /* while (running) */

leave:
    Log_print1(Diags_EXIT, "Server_exec: <-- %d", (IArg)status);
    return(status);
}

/*
 *  ======== Server_delete ========
 */

Int Server_delete()
{
    Int         status;

    Log_print0(Diags_ENTRY, "Server_delete: -->");

#if defined(EVE)
    Notify_unregisterEventSingle(Module.eveProcId, 0, NotifyMsg_Evt_EVE);
#endif

    /* delete the server message queue */
    status = MessageQ_delete(&Module.messageQ);

    if (status < 0) {
        goto leave;
    }

#if defined(EVE)
    SyncSem_delete(&Module.sync);
    Semaphore_delete(&Module.sem);
    Event_delete(&Module.event);
    Queue_delete(&Module.holdQ);
    IpcHandshake.sem = NULL;
    Semaphore_destruct(&IpcHandshake.semObj);
#endif

leave:
    if (status < 0) {
        Log_error1("Server_finish: error=0x%x", (IArg)status);
    }

    /* disable log events */
    Log_print1(Diags_EXIT, "Server_delete: <-- %d", (IArg)status);
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

#if defined(EVE)
/*
 *  ======== Server_dequeueEvent ========
 */
UInt32 Server_dequeueEvent(Notify_Queue *Q)
{
    UInt32 event;

    /* check for queue error */
    if (Q->error >= NotifyMsg_E_FAILURE) {
        event = Q->error;
    }
    else {
        if (Q->head == Q->tail) {
            /* queue should not be empty */
            Q->error = NotifyMsg_E_NOEVENT;
            event = Q->error;
        }
        else {
            /* remove next command from queue */
            event = Q->queue[Q->head];
            Q->head++;
        }
    }

    return (event);
}

/*
 *  ======== Server_notifyCB ========
 *  This function runs with the notify callback disabled. It will not
 *  be preempted by another notify event.
 */
Void Server_notifyCB(UInt16 procId, UInt16 lineId, UInt32 eventId, UArg arg,
        UInt32 payload)
{
    Notify_Queue *Q = (Notify_Queue *)arg;

    /* handle pong message, release the waiting task */
    if (payload == Notify_Evt_PONG) {
        Semaphore_post(IpcHandshake.sem);
    }

    /* if queue is full, set error flag */
    else if ((Q->head + Event_QSZ) == Q->tail) {
        Q->error = NotifyMsg_E_OVERFLOW;
    }

    /* save payload in queue, release waiting task  */
    else {
        Q->queue[Q->tail % Event_QSZ] = payload;
        Q->tail++;
        Event_post(Module.event, Event_Id_00);
    }
}

/*
 *  ======== Server_pingFxn ========
 *  Send a ping event to the eve processor.
 */
Void Server_pingFxn(UArg arg)
{
    /*  Send ping event. Do not busy-wait if previous event
     *  has not been received (waitClear = FALSE). The eve
     *  processor might not be running, so it is expected that
     *  previous messages will be lost or overwritten.
     */
    Notify_sendEvent(Module.eveProcId, 0, NotifyMsg_Evt_EVE,
            Notify_Evt_PING, FALSE);
}
#endif
