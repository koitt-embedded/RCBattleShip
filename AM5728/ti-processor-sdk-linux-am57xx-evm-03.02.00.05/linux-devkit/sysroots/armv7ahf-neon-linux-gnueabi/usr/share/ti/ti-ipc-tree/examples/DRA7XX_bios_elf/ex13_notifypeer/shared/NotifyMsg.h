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
 *  ======== NotifyMsg.h ========
 *
 */

#ifndef NotifyMsg__include
#define NotifyMsg__include

#if defined (__cplusplus)
extern "C" {
#endif

#define NotifyMsg_NUM_JOBS 5       /* number of message to send each server */

#define NotifyMsg_Evt_EVE          7       /* eve event number */
#define NotifyMsg_Evt_Appl         15      /* application event number */

#define Notify_Evt_PING         0xFFFE0000      /* FFFE eeee */
#define Notify_Evt_PONG         0xFFFFFFFF

#define NotifyMsg_Cmd_NOP          0x0
#define NotifyMsg_Cmd_PONG         0x1
#define NotifyMsg_Cmd_PROCESS      0x2     /* has ack */
#define NotifyMsg_Cmd_DONE         0x3
#define NotifyMsg_Cmd_STOP         0x4     /* has ack */
#define NotifyMsg_Cmd_PROCESSACK   0xA
#define NotifyMsg_Cmd_STOPACK      0xB

#define NotifyMsg_S_EMPTY          0x00000000
#define NotifyMsg_S_SUCCESS        0x00000000
#define NotifyMsg_E_FAILURE        0x80000000
#define NotifyMsg_E_OVERFLOW       0x90000000
#define NotifyMsg_E_NOEVENT        0xA0000000

//#define NotifyMsg_CMD_MASK         0xFF000000      /* cc------ */
//#define NotifyMsg_PAYLOAD_MASK     0x00FFFFFF      /* --pppppp */

/*  event format
 *
 *  ssss---- ppppiiii cccc---- yyyyyyyy
 *
 *  [31:28] (s) success/error code
 *  [27:24] (-) unused
 *  [23:20] (p) sender processor ID
 *  [19:16] (i) reply event ID
 *  [15:12] (c) command
 *  [11:8]  (-) unused
 *  [7:0]   (y) payload
 */
#define NotifyMsg_getProcId(event) (UInt16)((0x00F00000 & (event)) >> 20)
#define NotifyMsg_getEventId(event) (UInt)((0x000F0000 & (event)) >> 16)
#define NotifyMsg_getCmd(event) (UInt)((0x0000F000 & (event)) >> 12)
#define NotifyMsg_getPayload(event) (UInt8)(0x000000FF & (event))

#define NotifyMsg_setProcId(event, procId) \
    (event = (((event) & 0xFF0FFFFF) | (((UInt32)(procId) & 0xF) << 20)))

#define NotifyMsg_setEventId(event, eventId) \
    (event = (((event) & 0xFFF0FFFF) | (((UInt32)(eventId) & 0xF) << 16)))

#define NotifyMsg_setCmd(event, cmd) \
    (event = (((event) & 0xFFFF0FFF) | (((UInt32)(cmd) & 0xF) << 12)))

#define NotifyMsg_setPayload(event, payload) \
    (event = (((event) & 0xFFFFFF00) | ((UInt32)(payload) & 0xFF)))


#if defined (__cplusplus)
}
#endif
#endif
