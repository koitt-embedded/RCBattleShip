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
 *  ======== SvrMsg.h ========
 *
 */

#ifndef SvrMsg__include
#define SvrMsg__include
#if defined (__cplusplus)
extern "C" {
#endif

#include <ti/ipc/MessageQ.h>

#define SvrMsg_NUM_MSGS 5       /* number of message to send each server */

#define SvrMsg_SvrQueNameFmt "%s_SvrMsgQ"   /* %s = proc name */

#define Dsp1_AppMsgQue "Dsp1_AppMsgQ"
#define Dsp2_AppMsgQue "Dsp2_AppMsgQ"
#define Eve1_AppMsgQue "Eve1_AppMsgQ"
#define Eve2_AppMsgQue "Eve2_AppMsgQ"
#define Eve3_AppMsgQue "Eve3_AppMsgQ"
#define Eve4_AppMsgQue "Eve4_AppMsgQ"
#define Ipu1_AppMsgQue "Ipu1_AppMsgQ"
#define Ipu1_0_AppMsgQue "Ipu1-0_AppMsgQ"
#define Ipu1_1_AppMsgQue "Ipu1-1_AppMsgQ"
#define Ipu2_AppMsgQue "Ipu2_AppMsgQ"
#define Host_AppMsgQue "Host_AppMsgQ"

#define SvrMsg_Cmd_START        1
#define SvrMsg_Cmd_STOP         2
#define SvrMsg_Cmd_PROCESS      3

typedef struct {
    MessageQ_MsgHeader  reserved;

    UInt32      cmd;
    UInt16      svrProcId;
    Char        buf[32];
} SvrMsg_Msg;


#if defined (__cplusplus)
}
#endif
#endif
