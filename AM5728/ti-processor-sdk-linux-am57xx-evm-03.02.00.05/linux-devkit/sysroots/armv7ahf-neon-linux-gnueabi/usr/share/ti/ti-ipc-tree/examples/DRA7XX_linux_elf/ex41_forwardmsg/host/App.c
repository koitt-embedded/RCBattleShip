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
 *  ======== App.c ========
 *
 */

/* host header files */
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/* package header files */
#include <ti/ipc/Std.h>
#include <ti/ipc/MessageQ.h>

/* local header files */
#include "../shared/AppCommon.h"
#include "App.h"

/* module structure */
typedef struct {
    MessageQ_Handle         hostQue;     /* created locally */
    MessageQ_QueueId        slaveQue1;   /* opened remotely */
    MessageQ_QueueId        slaveQue2;   /* opened remotely */
    UInt16                  heapId;      /* MessageQ heapId */
    UInt32                  msgSize;
} App_Module;

/* private data */
static App_Module Module;


/*
 *  ======== App_create ========
 */

Int App_create()
{
    Int                 status = 0;
    MessageQ_Params     msgqParams;

    printf("--> App_create:\n");

    /* setting default values */
    Module.hostQue = NULL;
    Module.slaveQue1 = MessageQ_INVALIDMESSAGEQ;
    Module.slaveQue2 = MessageQ_INVALIDMESSAGEQ;
    Module.heapId = App_MsgHeapId;
    Module.msgSize = sizeof(App_Msg);

    /* create local message queue (inbound messages) */
    MessageQ_Params_init(&msgqParams);

    Module.hostQue = MessageQ_create(App_HostMsgQueName, &msgqParams);

    if (Module.hostQue == NULL) {
        printf("App_create: Failed creating MessageQ\n");
        status = -1;
        goto leave;
    }

    /* open the remote message queues */
    do {
        status = MessageQ_open(App_SlaveMsgQueName1, &Module.slaveQue1);
        sleep(1);
    } while (status == MessageQ_E_NOTFOUND);

    if (status < 0) {
        printf("App_create: Failed opening MessageQ\n");
        goto leave;
    }

    do {
        status = MessageQ_open(App_SlaveMsgQueName2, &Module.slaveQue2);
        sleep(1);
    } while (status == MessageQ_E_NOTFOUND);

    if (status < 0) {
        printf("App_create: Failed opening MessageQ\n");
        goto leave;
    }

    printf("App_create: Host is ready\n");

leave:
    printf("<-- App_create:\n");
    return(status);
}


/*
 *  ======== App_delete ========
 */
Int App_delete(Void)
{
    Int         status;

    printf("--> App_delete:\n");

    /* close remote resources */
    status = MessageQ_close(&Module.slaveQue1);

    if (status < 0) {
        goto leave;
    }

    status = MessageQ_close(&Module.slaveQue2);

    if (status < 0) {
        goto leave;
    }

    /* delete the host message queue */
    status = MessageQ_delete(&Module.hostQue);

    if (status < 0) {
        goto leave;
    }

leave:
    printf("<-- App_delete:\n");
    return(status);
}


/*
 *  ======== App_exec ========
 */
Int App_exec(Void)
{
    Int         status;
    Int         i;
    App_Msg *   msg;

    printf("--> App_exec:\n");

    /* fill process pipeline */
    printf("App_exec: sending 1st message\n");

    /* allocate message */
    msg = (App_Msg *)MessageQ_alloc(Module.heapId, Module.msgSize);

    if (msg == NULL) {
        status = -1;
        goto leave;
    }

    /* set the return address in the message header */
    MessageQ_setReplyQueue(Module.hostQue, (MessageQ_Msg)msg);

    /* fill in message payload */
    msg->cmd = App_CMD_HOST;

    /* send message */
    MessageQ_put(Module.slaveQue1, (MessageQ_Msg)msg);

    printf("App_exec: sending 2nd message\n");

    /* allocate message */
    msg = (App_Msg *)MessageQ_alloc(Module.heapId, Module.msgSize);

    if (msg == NULL) {
        status = -1;
        goto leave;
    }

    /* set the return address in the message header */
    MessageQ_setReplyQueue(Module.hostQue, (MessageQ_Msg)msg);

    /* fill in message payload */
    msg->cmd = App_CMD_HOST;

    /* send message */
    MessageQ_put(Module.slaveQue2, (MessageQ_Msg)msg);

    for (i = 0; i < 2; i++) {
        /* wait for return messages */
        printf("App_exec: Waiting for message %d...\n", i);
        status = MessageQ_get(Module.hostQue, (MessageQ_Msg *)&msg,
                MessageQ_FOREVER);

        if (status < 0) {
            goto leave;
        }

        /* free the message */
        MessageQ_free((MessageQ_Msg)msg);

        printf("App_exec: message %d received\n", i);
    }

    /* allocate shutdown message */
    msg = (App_Msg *)MessageQ_alloc(Module.heapId, Module.msgSize);

    if (msg == NULL) {
        status = -1;
        goto leave;
    }

    /* Last message will tell the slave to shutdown */
    msg->cmd = App_CMD_SHUTDOWN;

    /* send message */
    MessageQ_put(Module.slaveQue1, (MessageQ_Msg)msg);

	/* allocate shutdown message */
    msg = (App_Msg *)MessageQ_alloc(Module.heapId, Module.msgSize);

    if (msg == NULL) {
        status = -1;
        goto leave;
    }

    /* Last message will tell the slave to shutdown */
    msg->cmd = App_CMD_SHUTDOWN;

    /* send message */
    MessageQ_put(Module.slaveQue2, (MessageQ_Msg)msg);


leave:
    printf("<-- App_exec: %d\n", status);
    return(status);
}
