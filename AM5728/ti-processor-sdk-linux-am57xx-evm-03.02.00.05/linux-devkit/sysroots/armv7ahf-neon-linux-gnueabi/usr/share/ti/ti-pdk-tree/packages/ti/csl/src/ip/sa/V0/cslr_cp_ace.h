/********************************************************************
 * Copyright (C) 2003-2013 Texas Instruments Incorporated.
 * 
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions 
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the   
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/
/*********************************************************************
* file: cslr_cp_ace.h
*
* Brief: This file contains the Register Description for cp_ace
*
*********************************************************************/
#ifndef _CSLR_CP_ACE_V0_H_
#define _CSLR_CP_ACE_V0_H_

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure for MMR
\**************************************************************************/
typedef struct  {
    volatile Uint32 PID;
    volatile Uint32 EFUSE_EN;
    volatile Uint32 CMD_STATUS;
    volatile Uint32 BLKMGR_PA_BLKS;
    volatile Uint32 PA_FLOWID;
    volatile Uint32 CDMA_FLOWID;
    volatile Uint32 PA_ENG_ID;
    volatile Uint32 CDMA_ENG_ID;
    volatile Uint8 RSVD0[224];
    volatile Uint32 CTXCACH_CTRL;
    volatile Uint32 CTXCACH_SC_PTR;
    volatile Uint32 CTXCACH_SC_ID;
    volatile Uint32 CTXCACH_MISSCNT;
} CSL_Cp_aceMmrRegs;

/**************************************************************************\
* Register Overlay Structure for PDSP_CONTROL_STATUS
\**************************************************************************/
typedef struct  {
    volatile Uint32 PDSP_CONTROL;
    volatile Uint32 PDSP_STATUS;
    volatile Uint32 PDSP_WAKEUP_ENABLE;
    volatile Uint32 PDSP_CYCLE_COUNT;
    volatile Uint32 PDSP_STALL_COUNT;
    volatile Uint8 RSVD0[12];
    volatile Uint32 PDSP_CONSTANT_TABLE_BLOCK_INDEX_0;
    volatile Uint32 PDSP_CONSTANT_TABLE_BLOCK_INDEX_1;
    volatile Uint32 PDSP_CONSTANT_TABLE_PROG_PTR_0;
    volatile Uint32 PDSP_CONSTANT_TABLE_PROG_PTR_1;
    volatile Uint8 RSVD1[208];
} CSL_Cp_acePdsp_control_statusRegs;

/**************************************************************************\
* Register Overlay Structure for PDSP_DEBUG
\**************************************************************************/
typedef struct  {
    volatile Uint32 PDSP_IGP[32];
    volatile Uint32 PDSP_ICTE[32];
} CSL_Cp_acePdsp_debugRegs;

/**************************************************************************\
* Register Overlay Structure for PDSP_IRAM
\**************************************************************************/
typedef struct  {
    volatile Uint32 DATA[4096];
} CSL_Cp_acePdsp_iramRegs;

/**************************************************************************\
* Register Overlay Structure for PDSP_SRAM
\**************************************************************************/
typedef struct  {
    volatile Uint32 DATA[2048];
} CSL_Cp_acePdsp_sramRegs;

/**************************************************************************\
* Register Overlay Structure for PKA
\**************************************************************************/
typedef struct  {
    volatile Uint32 PKA_ABCDPTR[4];
    volatile Uint32 PKA_ABLENGTH[2];
    volatile Uint32 PKA_SHIFT;
    volatile Uint32 PKA_FUNCTION;
    volatile Uint32 PKA_COMPARE;
    volatile Uint32 PKA_MSW;
    volatile Uint32 PKA_DIVMSW;
} CSL_Cp_acePkaRegs;

/**************************************************************************\
* Register Overlay Structure for TRNG
\**************************************************************************/
typedef struct  {
    volatile Uint32 TRNG_OUTPUT_L;
    volatile Uint32 TRNG_OUTPUT_H;
    volatile Uint32 TRNG_STATUS;
    volatile Uint32 TRNG_INTMASK;
    volatile Uint32 TRNG_INTACK;
    volatile Uint32 TRNG_CONTROL;
    volatile Uint32 TRNG_CONFIG;
    volatile Uint32 TRNG_ALARMCNT;
    volatile Uint32 TRNG_FROENABLE;
    volatile Uint32 TRNG_FRODETUNE;
    volatile Uint32 TRNG_ALARMMASK;
    volatile Uint32 TRNG_ALARMSTOP;
    volatile Uint32 TRNG_LFSR_L;
    volatile Uint32 TRNG_LFSR_M;
    volatile Uint32 TRNG_LFSR_H;
    volatile Uint32 TRNG_COUNT;
    volatile Uint32 TRNG_TEST;
} CSL_Cp_aceTrngRegs;

/**************************************************************************\
* Register Overlay Structure for PDSP_SRAM2
\**************************************************************************/
typedef struct  {
    volatile Uint32 DATA[4096];
} CSL_Cp_acePdsp_sram2Regs;

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    CSL_Cp_aceMmrRegs MMR;
    volatile Uint8 RSVD0[3824];
    CSL_Cp_acePdsp_control_statusRegs PDSP_CONTROL_STATUS[2];
    volatile Uint8 RSVD1[512];
    CSL_Cp_acePdsp_debugRegs PDSP_DEBUG[2];
    volatile Uint8 RSVD2[10752];
    CSL_Cp_acePdsp_iramRegs PDSP_IRAM[2];
    CSL_Cp_acePdsp_sramRegs PDSP_SRAM[2];
    volatile Uint8 RSVD3[65536];
    CSL_Cp_acePkaRegs PKA;
    volatile Uint8 RSVD4[16340];
    CSL_Cp_aceTrngRegs TRNG;
    volatile Uint8 RSVD5[32700];
    CSL_Cp_acePdsp_sram2Regs PDSP_SRAM2;
} CSL_Cp_aceRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* PID */

#define CSL_CP_ACE_PID_SCHEME_MASK       (0xC0000000u)
#define CSL_CP_ACE_PID_SCHEME_SHIFT      (0x0000001Eu)
#define CSL_CP_ACE_PID_SCHEME_RESETVAL   (0x00000001u)

#define CSL_CP_ACE_PID_BU_MASK           (0x30000000u)
#define CSL_CP_ACE_PID_BU_SHIFT          (0x0000001Cu)
#define CSL_CP_ACE_PID_BU_RESETVAL       (0x00000000u)

#define CSL_CP_ACE_PID_FUNC_MASK         (0x0FFF0000u)
#define CSL_CP_ACE_PID_FUNC_SHIFT        (0x00000010u)
#define CSL_CP_ACE_PID_FUNC_RESETVAL     (0x00000E20u)

#define CSL_CP_ACE_PID_RTL_MASK          (0x0000F800u)
#define CSL_CP_ACE_PID_RTL_SHIFT         (0x0000000Bu)
#define CSL_CP_ACE_PID_RTL_RESETVAL      (0x00000003u)

#define CSL_CP_ACE_PID_MAJOR_MASK        (0x00000700u)
#define CSL_CP_ACE_PID_MAJOR_SHIFT       (0x00000008u)
#define CSL_CP_ACE_PID_MAJOR_RESETVAL    (0x00000001u)

#define CSL_CP_ACE_PID_CUSTOM_MASK       (0x000000C0u)
#define CSL_CP_ACE_PID_CUSTOM_SHIFT      (0x00000006u)
#define CSL_CP_ACE_PID_CUSTOM_RESETVAL   (0x00000000u)

#define CSL_CP_ACE_PID_MINOR_MASK        (0x0000003Fu)
#define CSL_CP_ACE_PID_MINOR_SHIFT       (0x00000000u)
#define CSL_CP_ACE_PID_MINOR_RESETVAL    (0x00000001u)

#define CSL_CP_ACE_PID_RESETVAL          (0x4E201901u)

/* EFUSE_EN */

#define CSL_CP_ACE_EFUSE_EN_ENABLE_MASK  (0x00000001u)
#define CSL_CP_ACE_EFUSE_EN_ENABLE_SHIFT (0x00000000u)
#define CSL_CP_ACE_EFUSE_EN_ENABLE_RESETVAL (0x00000000u)

#define CSL_CP_ACE_EFUSE_EN_RESETVAL     (0x00000000u)

/* CMD_STATUS */

#define CSL_CP_ACE_CMD_STATUS_AUTHSS1_BUSY_MASK (0x20000000u)
#define CSL_CP_ACE_CMD_STATUS_AUTHSS1_BUSY_SHIFT (0x0000001Du)
#define CSL_CP_ACE_CMD_STATUS_AUTHSS1_BUSY_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CMD_STATUS_ENCSS1_BUSY_MASK (0x10000000u)
#define CSL_CP_ACE_CMD_STATUS_ENCSS1_BUSY_SHIFT (0x0000001Cu)
#define CSL_CP_ACE_CMD_STATUS_ENCSS1_BUSY_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CMD_STATUS_CDMA_OUT_PORT_BUSY_MASK (0x08000000u)
#define CSL_CP_ACE_CMD_STATUS_CDMA_OUT_PORT_BUSY_SHIFT (0x0000001Bu)
#define CSL_CP_ACE_CMD_STATUS_CDMA_OUT_PORT_BUSY_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CMD_STATUS_PA_OUT_PORT_BUSY_MASK (0x04000000u)
#define CSL_CP_ACE_CMD_STATUS_PA_OUT_PORT_BUSY_SHIFT (0x0000001Au)
#define CSL_CP_ACE_CMD_STATUS_PA_OUT_PORT_BUSY_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CMD_STATUS_CDMA_IN_PORT_BUSY_MASK (0x02000000u)
#define CSL_CP_ACE_CMD_STATUS_CDMA_IN_PORT_BUSY_SHIFT (0x00000019u)
#define CSL_CP_ACE_CMD_STATUS_CDMA_IN_PORT_BUSY_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CMD_STATUS_PA_IN_PORT_BUSY_MASK (0x01000000u)
#define CSL_CP_ACE_CMD_STATUS_PA_IN_PORT_BUSY_SHIFT (0x00000018u)
#define CSL_CP_ACE_CMD_STATUS_PA_IN_PORT_BUSY_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CMD_STATUS_CTXCACH_BUSY_MASK (0x00800000u)
#define CSL_CP_ACE_CMD_STATUS_CTXCACH_BUSY_SHIFT (0x00000017u)
#define CSL_CP_ACE_CMD_STATUS_CTXCACH_BUSY_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CMD_STATUS_PHP2SS_BUSY_MASK (0x00400000u)
#define CSL_CP_ACE_CMD_STATUS_PHP2SS_BUSY_SHIFT (0x00000016u)
#define CSL_CP_ACE_CMD_STATUS_PHP2SS_BUSY_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CMD_STATUS_PHP1SS_BUSY_MASK (0x00200000u)
#define CSL_CP_ACE_CMD_STATUS_PHP1SS_BUSY_SHIFT (0x00000015u)
#define CSL_CP_ACE_CMD_STATUS_PHP1SS_BUSY_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CMD_STATUS_PKA_BUSY_MASK (0x00100000u)
#define CSL_CP_ACE_CMD_STATUS_PKA_BUSY_SHIFT (0x00000014u)
#define CSL_CP_ACE_CMD_STATUS_PKA_BUSY_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CMD_STATUS_TRNG_BUSY_MASK (0x00080000u)
#define CSL_CP_ACE_CMD_STATUS_TRNG_BUSY_SHIFT (0x00000013u)
#define CSL_CP_ACE_CMD_STATUS_TRNG_BUSY_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CMD_STATUS_AIRSS_BUSY_MASK (0x00040000u)
#define CSL_CP_ACE_CMD_STATUS_AIRSS_BUSY_SHIFT (0x00000012u)
#define CSL_CP_ACE_CMD_STATUS_AIRSS_BUSY_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CMD_STATUS_AUTHSS_BUSY_MASK (0x00020000u)
#define CSL_CP_ACE_CMD_STATUS_AUTHSS_BUSY_SHIFT (0x00000011u)
#define CSL_CP_ACE_CMD_STATUS_AUTHSS_BUSY_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CMD_STATUS_ENCSS_BUSY_MASK (0x00010000u)
#define CSL_CP_ACE_CMD_STATUS_ENCSS_BUSY_SHIFT (0x00000010u)
#define CSL_CP_ACE_CMD_STATUS_ENCSS_BUSY_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CMD_STATUS_AUTHSS1_EN_MASK (0x00002000u)
#define CSL_CP_ACE_CMD_STATUS_AUTHSS1_EN_SHIFT (0x0000000Du)
#define CSL_CP_ACE_CMD_STATUS_AUTHSS1_EN_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CMD_STATUS_ENCSS1_EN_MASK (0x00001000u)
#define CSL_CP_ACE_CMD_STATUS_ENCSS1_EN_SHIFT (0x0000000Cu)
#define CSL_CP_ACE_CMD_STATUS_ENCSS1_EN_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CMD_STATUS_CDMA_OUT_PORT_EN_MASK (0x00000800u)
#define CSL_CP_ACE_CMD_STATUS_CDMA_OUT_PORT_EN_SHIFT (0x0000000Bu)
#define CSL_CP_ACE_CMD_STATUS_CDMA_OUT_PORT_EN_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CMD_STATUS_PA_OUT_PORT_EN_MASK (0x00000400u)
#define CSL_CP_ACE_CMD_STATUS_PA_OUT_PORT_EN_SHIFT (0x0000000Au)
#define CSL_CP_ACE_CMD_STATUS_PA_OUT_PORT_EN_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CMD_STATUS_CDMA_IN_PORT_EN_MASK (0x00000200u)
#define CSL_CP_ACE_CMD_STATUS_CDMA_IN_PORT_EN_SHIFT (0x00000009u)
#define CSL_CP_ACE_CMD_STATUS_CDMA_IN_PORT_EN_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CMD_STATUS_PA_IN_PORT_EN_MASK (0x00000100u)
#define CSL_CP_ACE_CMD_STATUS_PA_IN_PORT_EN_SHIFT (0x00000008u)
#define CSL_CP_ACE_CMD_STATUS_PA_IN_PORT_EN_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CMD_STATUS_CTXCACH_EN_MASK (0x00000080u)
#define CSL_CP_ACE_CMD_STATUS_CTXCACH_EN_SHIFT (0x00000007u)
#define CSL_CP_ACE_CMD_STATUS_CTXCACH_EN_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CMD_STATUS_PHP2SS_EN_MASK (0x00000040u)
#define CSL_CP_ACE_CMD_STATUS_PHP2SS_EN_SHIFT (0x00000006u)
#define CSL_CP_ACE_CMD_STATUS_PHP2SS_EN_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CMD_STATUS_PHP1SS_EN_MASK (0x00000020u)
#define CSL_CP_ACE_CMD_STATUS_PHP1SS_EN_SHIFT (0x00000005u)
#define CSL_CP_ACE_CMD_STATUS_PHP1SS_EN_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CMD_STATUS_PKA_EN_MASK (0x00000010u)
#define CSL_CP_ACE_CMD_STATUS_PKA_EN_SHIFT (0x00000004u)
#define CSL_CP_ACE_CMD_STATUS_PKA_EN_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CMD_STATUS_TRNG_EN_MASK (0x00000008u)
#define CSL_CP_ACE_CMD_STATUS_TRNG_EN_SHIFT (0x00000003u)
#define CSL_CP_ACE_CMD_STATUS_TRNG_EN_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CMD_STATUS_AIRSS_EN_MASK (0x00000004u)
#define CSL_CP_ACE_CMD_STATUS_AIRSS_EN_SHIFT (0x00000002u)
#define CSL_CP_ACE_CMD_STATUS_AIRSS_EN_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CMD_STATUS_AUTHSS_EN_MASK (0x00000002u)
#define CSL_CP_ACE_CMD_STATUS_AUTHSS_EN_SHIFT (0x00000001u)
#define CSL_CP_ACE_CMD_STATUS_AUTHSS_EN_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CMD_STATUS_ENCSS_EN_MASK (0x00000001u)
#define CSL_CP_ACE_CMD_STATUS_ENCSS_EN_SHIFT (0x00000000u)
#define CSL_CP_ACE_CMD_STATUS_ENCSS_EN_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CMD_STATUS_RESETVAL   (0x00000000u)

/* BLKMGR_PA_BLKS */

#define CSL_CP_ACE_BLKMGR_PA_BLKS_PA_BLKS_MASK (0x00000007u)
#define CSL_CP_ACE_BLKMGR_PA_BLKS_PA_BLKS_SHIFT (0x00000000u)
#define CSL_CP_ACE_BLKMGR_PA_BLKS_PA_BLKS_RESETVAL (0x00000004u)

#define CSL_CP_ACE_BLKMGR_PA_BLKS_RESETVAL (0x00000004u)

/* PA_FLOWID */

#define CSL_CP_ACE_PA_FLOWID_PA_FLOWID_MASK (0x000000FFu)
#define CSL_CP_ACE_PA_FLOWID_PA_FLOWID_SHIFT (0x00000000u)
#define CSL_CP_ACE_PA_FLOWID_PA_FLOWID_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PA_FLOWID_RESETVAL    (0x00000000u)

/* CDMA_FLOWID */

#define CSL_CP_ACE_CDMA_FLOWID_CDMA_FLOWID_MASK (0x000000FFu)
#define CSL_CP_ACE_CDMA_FLOWID_CDMA_FLOWID_SHIFT (0x00000000u)
#define CSL_CP_ACE_CDMA_FLOWID_CDMA_FLOWID_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CDMA_FLOWID_RESETVAL  (0x00000000u)

/* PA_ENG_ID */

#define CSL_CP_ACE_PA_ENG_ID_PA_ENG_ID_MASK (0x0000001Fu)
#define CSL_CP_ACE_PA_ENG_ID_PA_ENG_ID_SHIFT (0x00000000u)
#define CSL_CP_ACE_PA_ENG_ID_PA_ENG_ID_RESETVAL (0x00000008u)

#define CSL_CP_ACE_PA_ENG_ID_RESETVAL    (0x00000008u)

/* CDMA_ENG_ID */

#define CSL_CP_ACE_CDMA_ENG_ID_CDMA_ENG_ID_MASK (0x0000001Fu)
#define CSL_CP_ACE_CDMA_ENG_ID_CDMA_ENG_ID_SHIFT (0x00000000u)
#define CSL_CP_ACE_CDMA_ENG_ID_CDMA_ENG_ID_RESETVAL (0x00000010u)

#define CSL_CP_ACE_CDMA_ENG_ID_RESETVAL  (0x00000010u)

/* CTXCACH_CTRL */

#define CSL_CP_ACE_CTXCACH_CTRL_BUSY_MASK (0x80000000u)
#define CSL_CP_ACE_CTXCACH_CTRL_BUSY_SHIFT (0x0000001Fu)
#define CSL_CP_ACE_CTXCACH_CTRL_BUSY_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CTXCACH_CTRL_CTX_CNT_MASK (0x7F000000u)
#define CSL_CP_ACE_CTXCACH_CTRL_CTX_CNT_SHIFT (0x00000018u)
#define CSL_CP_ACE_CTXCACH_CTRL_CTX_CNT_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CTXCACH_CTRL_CLR_STATS_MASK (0x00000010u)
#define CSL_CP_ACE_CTXCACH_CTRL_CLR_STATS_SHIFT (0x00000004u)
#define CSL_CP_ACE_CTXCACH_CTRL_CLR_STATS_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CTXCACH_CTRL_CDMA_PORT_EN_MASK (0x00000008u)
#define CSL_CP_ACE_CTXCACH_CTRL_CDMA_PORT_EN_SHIFT (0x00000003u)
#define CSL_CP_ACE_CTXCACH_CTRL_CDMA_PORT_EN_RESETVAL (0x00000001u)

#define CSL_CP_ACE_CTXCACH_CTRL_PA_PORT_EN_MASK (0x00000004u)
#define CSL_CP_ACE_CTXCACH_CTRL_PA_PORT_EN_SHIFT (0x00000002u)
#define CSL_CP_ACE_CTXCACH_CTRL_PA_PORT_EN_RESETVAL (0x00000001u)

#define CSL_CP_ACE_CTXCACH_CTRL_CLR_CACHE_TABLE_MASK (0x00000002u)
#define CSL_CP_ACE_CTXCACH_CTRL_CLR_CACHE_TABLE_SHIFT (0x00000001u)
#define CSL_CP_ACE_CTXCACH_CTRL_CLR_CACHE_TABLE_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CTXCACH_CTRL_AUTO_FETCH_EN_MASK (0x00000001u)
#define CSL_CP_ACE_CTXCACH_CTRL_AUTO_FETCH_EN_SHIFT (0x00000000u)
#define CSL_CP_ACE_CTXCACH_CTRL_AUTO_FETCH_EN_RESETVAL (0x00000001u)

#define CSL_CP_ACE_CTXCACH_CTRL_RESETVAL (0x0000000Du)

/* CTXCACH_SC_PTR */

#define CSL_CP_ACE_CTXCACH_SC_PTR_CTX_SC_PTR_MASK (0xFFFFFFFFu)
#define CSL_CP_ACE_CTXCACH_SC_PTR_CTX_SC_PTR_SHIFT (0x00000000u)
#define CSL_CP_ACE_CTXCACH_SC_PTR_CTX_SC_PTR_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CTXCACH_SC_PTR_RESETVAL (0x00000000u)

/* CTXCACH_SC_ID */

#define CSL_CP_ACE_CTXCACH_SC_ID_DONE_MASK (0x80000000u)
#define CSL_CP_ACE_CTXCACH_SC_ID_DONE_SHIFT (0x0000001Fu)
#define CSL_CP_ACE_CTXCACH_SC_ID_DONE_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CTXCACH_SC_ID_SC_ERRORCODE_MASK (0x70000000u)
#define CSL_CP_ACE_CTXCACH_SC_ID_SC_ERRORCODE_SHIFT (0x0000001Cu)
#define CSL_CP_ACE_CTXCACH_SC_ID_SC_ERRORCODE_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CTXCACH_SC_ID_SC_RAMIDX_MASK (0x0FF00000u)
#define CSL_CP_ACE_CTXCACH_SC_ID_SC_RAMIDX_SHIFT (0x00000014u)
#define CSL_CP_ACE_CTXCACH_SC_ID_SC_RAMIDX_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CTXCACH_SC_ID_GO_MASK (0x00080000u)
#define CSL_CP_ACE_CTXCACH_SC_ID_GO_SHIFT (0x00000013u)
#define CSL_CP_ACE_CTXCACH_SC_ID_GO_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CTXCACH_SC_ID_SC_TEAR_MASK (0x00020000u)
#define CSL_CP_ACE_CTXCACH_SC_ID_SC_TEAR_SHIFT (0x00000011u)
#define CSL_CP_ACE_CTXCACH_SC_ID_SC_TEAR_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CTXCACH_SC_ID_SC_FETCH_EVICT_MASK (0x00010000u)
#define CSL_CP_ACE_CTXCACH_SC_ID_SC_FETCH_EVICT_SHIFT (0x00000010u)
#define CSL_CP_ACE_CTXCACH_SC_ID_SC_FETCH_EVICT_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CTXCACH_SC_ID_SC_ID_MASK (0x0000FFFFu)
#define CSL_CP_ACE_CTXCACH_SC_ID_SC_ID_SHIFT (0x00000000u)
#define CSL_CP_ACE_CTXCACH_SC_ID_SC_ID_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CTXCACH_SC_ID_RESETVAL (0x00000000u)

/* CTXCACH_MISSCNT */

#define CSL_CP_ACE_CTXCACH_MISSCNT_CTX_MISSCNT_MASK (0xFFFFFFFFu)
#define CSL_CP_ACE_CTXCACH_MISSCNT_CTX_MISSCNT_SHIFT (0x00000000u)
#define CSL_CP_ACE_CTXCACH_MISSCNT_CTX_MISSCNT_RESETVAL (0x00000000u)

#define CSL_CP_ACE_CTXCACH_MISSCNT_RESETVAL (0x00000000u)

/* PDSP_CONTROL */

#define CSL_CP_ACE_PDSP_CONTROL_SOFT_RST_N_MASK (0x00000001u)
#define CSL_CP_ACE_PDSP_CONTROL_SOFT_RST_N_SHIFT (0x00000000u)
#define CSL_CP_ACE_PDSP_CONTROL_SOFT_RST_N_RESETVAL (0x00000001u)

#define CSL_CP_ACE_PDSP_CONTROL_ENABLE_MASK (0x00000002u)
#define CSL_CP_ACE_PDSP_CONTROL_ENABLE_SHIFT (0x00000001u)
#define CSL_CP_ACE_PDSP_CONTROL_ENABLE_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PDSP_CONTROL_SLEEPING_MASK (0x00000004u)
#define CSL_CP_ACE_PDSP_CONTROL_SLEEPING_SHIFT (0x00000002u)
#define CSL_CP_ACE_PDSP_CONTROL_SLEEPING_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PDSP_CONTROL_COUNTER_ENABLE_MASK (0x00000008u)
#define CSL_CP_ACE_PDSP_CONTROL_COUNTER_ENABLE_SHIFT (0x00000003u)
#define CSL_CP_ACE_PDSP_CONTROL_COUNTER_ENABLE_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PDSP_CONTROL_RESTART_MASK (0x00000010u)
#define CSL_CP_ACE_PDSP_CONTROL_RESTART_SHIFT (0x00000004u)
#define CSL_CP_ACE_PDSP_CONTROL_RESTART_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PDSP_CONTROL_SINGLE_STEP_MASK (0x00000100u)
#define CSL_CP_ACE_PDSP_CONTROL_SINGLE_STEP_SHIFT (0x00000008u)
#define CSL_CP_ACE_PDSP_CONTROL_SINGLE_STEP_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PDSP_CONTROL_BIG_ENDIAN_MASK (0x00004000u)
#define CSL_CP_ACE_PDSP_CONTROL_BIG_ENDIAN_SHIFT (0x0000000Eu)
#define CSL_CP_ACE_PDSP_CONTROL_BIG_ENDIAN_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PDSP_CONTROL_PDSP_STATE_MASK (0x00008000u)
#define CSL_CP_ACE_PDSP_CONTROL_PDSP_STATE_SHIFT (0x0000000Fu)
#define CSL_CP_ACE_PDSP_CONTROL_PDSP_STATE_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PDSP_CONTROL_PCOUNTER_RST_VAL_MASK (0xFFFF0000u)
#define CSL_CP_ACE_PDSP_CONTROL_PCOUNTER_RST_VAL_SHIFT (0x00000010u)
#define CSL_CP_ACE_PDSP_CONTROL_PCOUNTER_RST_VAL_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PDSP_CONTROL_RESETVAL (0x00000001u)

/* PDSP_STATUS */

#define CSL_CP_ACE_PDSP_STATUS_PCOUNTER_MASK (0x0000FFFFu)
#define CSL_CP_ACE_PDSP_STATUS_PCOUNTER_SHIFT (0x00000000u)
#define CSL_CP_ACE_PDSP_STATUS_PCOUNTER_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PDSP_STATUS_RESETVAL  (0x00000000u)

/* PDSP_WAKEUP_ENABLE */

#define CSL_CP_ACE_PDSP_WAKEUP_ENABLE_BITWISE_ENABLES_MASK (0xFFFFFFFFu)
#define CSL_CP_ACE_PDSP_WAKEUP_ENABLE_BITWISE_ENABLES_SHIFT (0x00000000u)
#define CSL_CP_ACE_PDSP_WAKEUP_ENABLE_BITWISE_ENABLES_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PDSP_WAKEUP_ENABLE_RESETVAL (0x00000000u)

/* PDSP_CYCLE_COUNT */

#define CSL_CP_ACE_PDSP_CYCLE_COUNT_CYCLECOUNT_MASK (0xFFFFFFFFu)
#define CSL_CP_ACE_PDSP_CYCLE_COUNT_CYCLECOUNT_SHIFT (0x00000000u)
#define CSL_CP_ACE_PDSP_CYCLE_COUNT_CYCLECOUNT_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PDSP_CYCLE_COUNT_RESETVAL (0x00000000u)

/* PDSP_STALL_COUNT */

#define CSL_CP_ACE_PDSP_STALL_COUNT_STALLCOUNT_MASK (0xFFFFFFFFu)
#define CSL_CP_ACE_PDSP_STALL_COUNT_STALLCOUNT_SHIFT (0x00000000u)
#define CSL_CP_ACE_PDSP_STALL_COUNT_STALLCOUNT_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PDSP_STALL_COUNT_RESETVAL (0x00000000u)

/* PDSP_CONSTANT_TABLE_BLOCK_INDEX_0 */

#define CSL_CP_ACE_PDSP_CONSTANT_TABLE_BLOCK_INDEX_0_C24_BLK_INDEX_MASK (0x000000FFu)
#define CSL_CP_ACE_PDSP_CONSTANT_TABLE_BLOCK_INDEX_0_C24_BLK_INDEX_SHIFT (0x00000000u)
#define CSL_CP_ACE_PDSP_CONSTANT_TABLE_BLOCK_INDEX_0_C24_BLK_INDEX_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PDSP_CONSTANT_TABLE_BLOCK_INDEX_0_C25_BLK_INDEX_MASK (0x00FF0000u)
#define CSL_CP_ACE_PDSP_CONSTANT_TABLE_BLOCK_INDEX_0_C25_BLK_INDEX_SHIFT (0x00000010u)
#define CSL_CP_ACE_PDSP_CONSTANT_TABLE_BLOCK_INDEX_0_C25_BLK_INDEX_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PDSP_CONSTANT_TABLE_BLOCK_INDEX_0_RESETVAL (0x00000000u)

/* PDSP_CONSTANT_TABLE_BLOCK_INDEX_1 */

#define CSL_CP_ACE_PDSP_CONSTANT_TABLE_BLOCK_INDEX_1_C26_BLK_INDEX_MASK (0x000000FFu)
#define CSL_CP_ACE_PDSP_CONSTANT_TABLE_BLOCK_INDEX_1_C26_BLK_INDEX_SHIFT (0x00000000u)
#define CSL_CP_ACE_PDSP_CONSTANT_TABLE_BLOCK_INDEX_1_C26_BLK_INDEX_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PDSP_CONSTANT_TABLE_BLOCK_INDEX_1_C27_BLK_INDEX_MASK (0x00FF0000u)
#define CSL_CP_ACE_PDSP_CONSTANT_TABLE_BLOCK_INDEX_1_C27_BLK_INDEX_SHIFT (0x00000010u)
#define CSL_CP_ACE_PDSP_CONSTANT_TABLE_BLOCK_INDEX_1_C27_BLK_INDEX_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PDSP_CONSTANT_TABLE_BLOCK_INDEX_1_RESETVAL (0x00000000u)

/* PDSP_CONSTANT_TABLE_PROG_PTR_0 */

#define CSL_CP_ACE_PDSP_CONSTANT_TABLE_PROG_PTR_0_C28_POINTER_MASK (0x0000FFFFu)
#define CSL_CP_ACE_PDSP_CONSTANT_TABLE_PROG_PTR_0_C28_POINTER_SHIFT (0x00000000u)
#define CSL_CP_ACE_PDSP_CONSTANT_TABLE_PROG_PTR_0_C28_POINTER_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PDSP_CONSTANT_TABLE_PROG_PTR_0_C29_POINTER_MASK (0xFFFF0000u)
#define CSL_CP_ACE_PDSP_CONSTANT_TABLE_PROG_PTR_0_C29_POINTER_SHIFT (0x00000010u)
#define CSL_CP_ACE_PDSP_CONSTANT_TABLE_PROG_PTR_0_C29_POINTER_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PDSP_CONSTANT_TABLE_PROG_PTR_0_RESETVAL (0x00000000u)

/* PDSP_CONSTANT_TABLE_PROG_PTR_1 */

#define CSL_CP_ACE_PDSP_CONSTANT_TABLE_PROG_PTR_1_C30_POINTER_MASK (0x0000FFFFu)
#define CSL_CP_ACE_PDSP_CONSTANT_TABLE_PROG_PTR_1_C30_POINTER_SHIFT (0x00000000u)
#define CSL_CP_ACE_PDSP_CONSTANT_TABLE_PROG_PTR_1_C30_POINTER_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PDSP_CONSTANT_TABLE_PROG_PTR_1_C31_POINTER_MASK (0xFFFF0000u)
#define CSL_CP_ACE_PDSP_CONSTANT_TABLE_PROG_PTR_1_C31_POINTER_SHIFT (0x00000010u)
#define CSL_CP_ACE_PDSP_CONSTANT_TABLE_PROG_PTR_1_C31_POINTER_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PDSP_CONSTANT_TABLE_PROG_PTR_1_RESETVAL (0x00000000u)

/* PDSP_IGP */

#define CSL_CP_ACE_PDSP_IGP_REGN_MASK    (0xFFFFFFFFu)
#define CSL_CP_ACE_PDSP_IGP_REGN_SHIFT   (0x00000000u)
#define CSL_CP_ACE_PDSP_IGP_REGN_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PDSP_IGP_RESETVAL     (0x00000000u)

/* PDSP_ICTE */

#define CSL_CP_ACE_PDSP_ICTE_CT_ENTRYN_MASK (0xFFFFFFFFu)
#define CSL_CP_ACE_PDSP_ICTE_CT_ENTRYN_SHIFT (0x00000000u)
#define CSL_CP_ACE_PDSP_ICTE_CT_ENTRYN_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PDSP_ICTE_RESETVAL    (0x00000000u)

/* DATA */

#define CSL_CP_ACE_DATA_RESETVAL         (0x00000000u)

/* DATA */

#define CSL_CP_ACE_DATA_RESETVAL         (0x00000000u)

/* PKA_ABCDPTR */

#define CSL_CP_ACE_PKA_ABCDPTR_PTR_MASK  (0x000003FFu)
#define CSL_CP_ACE_PKA_ABCDPTR_PTR_SHIFT (0x00000000u)
#define CSL_CP_ACE_PKA_ABCDPTR_PTR_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PKA_ABCDPTR_RESETVAL  (0x00000000u)

/* PKA_ABLENGTH */

#define CSL_CP_ACE_PKA_ABLENGTH_LENGTH_MASK (0x000000FFu)
#define CSL_CP_ACE_PKA_ABLENGTH_LENGTH_SHIFT (0x00000000u)
#define CSL_CP_ACE_PKA_ABLENGTH_LENGTH_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PKA_ABLENGTH_RESETVAL (0x00000000u)

/* PKA_SHIFT */

#define CSL_CP_ACE_PKA_SHIFT_SHIFT_MASK  (0x0000001Fu)
#define CSL_CP_ACE_PKA_SHIFT_SHIFT_SHIFT (0x00000000u)
#define CSL_CP_ACE_PKA_SHIFT_SHIFT_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PKA_SHIFT_RESETVAL    (0x00000000u)

/* PKA_FUNCTION */

#define CSL_CP_ACE_PKA_FUNCTION_RUN_MASK (0x00008000u)
#define CSL_CP_ACE_PKA_FUNCTION_RUN_SHIFT (0x0000000Fu)
#define CSL_CP_ACE_PKA_FUNCTION_RUN_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PKA_FUNCTION_EXP2_MASK (0x00004000u)
#define CSL_CP_ACE_PKA_FUNCTION_EXP2_SHIFT (0x0000000Eu)
#define CSL_CP_ACE_PKA_FUNCTION_EXP2_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PKA_FUNCTION_EXP4_MASK (0x00002000u)
#define CSL_CP_ACE_PKA_FUNCTION_EXP4_SHIFT (0x0000000Du)
#define CSL_CP_ACE_PKA_FUNCTION_EXP4_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PKA_FUNCTION_COPY_MASK (0x00000800u)
#define CSL_CP_ACE_PKA_FUNCTION_COPY_SHIFT (0x0000000Bu)
#define CSL_CP_ACE_PKA_FUNCTION_COPY_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PKA_FUNCTION_COMPARE_MASK (0x00000400u)
#define CSL_CP_ACE_PKA_FUNCTION_COMPARE_SHIFT (0x0000000Au)
#define CSL_CP_ACE_PKA_FUNCTION_COMPARE_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PKA_FUNCTION_DIVIDE_MASK (0x00000100u)
#define CSL_CP_ACE_PKA_FUNCTION_DIVIDE_SHIFT (0x00000008u)
#define CSL_CP_ACE_PKA_FUNCTION_DIVIDE_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PKA_FUNCTION_LSHIFT_MASK (0x00000080u)
#define CSL_CP_ACE_PKA_FUNCTION_LSHIFT_SHIFT (0x00000007u)
#define CSL_CP_ACE_PKA_FUNCTION_LSHIFT_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PKA_FUNCTION_RSHIFT_MASK (0x00000040u)
#define CSL_CP_ACE_PKA_FUNCTION_RSHIFT_SHIFT (0x00000006u)
#define CSL_CP_ACE_PKA_FUNCTION_RSHIFT_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PKA_FUNCTION_SUBSTRACT_MASK (0x00000020u)
#define CSL_CP_ACE_PKA_FUNCTION_SUBSTRACT_SHIFT (0x00000005u)
#define CSL_CP_ACE_PKA_FUNCTION_SUBSTRACT_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PKA_FUNCTION_ADD_MASK (0x00000010u)
#define CSL_CP_ACE_PKA_FUNCTION_ADD_SHIFT (0x00000004u)
#define CSL_CP_ACE_PKA_FUNCTION_ADD_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PKA_FUNCTION_MULTIPLY_MASK (0x00000001u)
#define CSL_CP_ACE_PKA_FUNCTION_MULTIPLY_SHIFT (0x00000000u)
#define CSL_CP_ACE_PKA_FUNCTION_MULTIPLY_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PKA_FUNCTION_RESETVAL (0x00000000u)

/* PKA_COMPARE */

#define CSL_CP_ACE_PKA_COMPARE_ASUPB_MASK (0x00000004u)
#define CSL_CP_ACE_PKA_COMPARE_ASUPB_SHIFT (0x00000002u)
#define CSL_CP_ACE_PKA_COMPARE_ASUPB_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PKA_COMPARE_AINFB_MASK (0x00000002u)
#define CSL_CP_ACE_PKA_COMPARE_AINFB_SHIFT (0x00000001u)
#define CSL_CP_ACE_PKA_COMPARE_AINFB_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PKA_COMPARE_AEQB_MASK (0x00000001u)
#define CSL_CP_ACE_PKA_COMPARE_AEQB_SHIFT (0x00000000u)
#define CSL_CP_ACE_PKA_COMPARE_AEQB_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PKA_COMPARE_RESETVAL  (0x00000000u)

/* PKA_MSW */

#define CSL_CP_ACE_PKA_MSW_RES_ZERO_MASK (0x00008000u)
#define CSL_CP_ACE_PKA_MSW_RES_ZERO_SHIFT (0x0000000Fu)
#define CSL_CP_ACE_PKA_MSW_RES_ZERO_RESETVAL (0x00000001u)

#define CSL_CP_ACE_PKA_MSW_MSW_ADDRESS_MASK (0x000003FFu)
#define CSL_CP_ACE_PKA_MSW_MSW_ADDRESS_SHIFT (0x00000000u)
#define CSL_CP_ACE_PKA_MSW_MSW_ADDRESS_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PKA_MSW_RESETVAL      (0x00008000u)

/* PKA_DIVMSW */

#define CSL_CP_ACE_PKA_DIVMSW_RES_ZERO_MASK (0x00008000u)
#define CSL_CP_ACE_PKA_DIVMSW_RES_ZERO_SHIFT (0x0000000Fu)
#define CSL_CP_ACE_PKA_DIVMSW_RES_ZERO_RESETVAL (0x00000001u)

#define CSL_CP_ACE_PKA_DIVMSW_MSW_ADDRESS_MASK (0x000003FFu)
#define CSL_CP_ACE_PKA_DIVMSW_MSW_ADDRESS_SHIFT (0x00000000u)
#define CSL_CP_ACE_PKA_DIVMSW_MSW_ADDRESS_RESETVAL (0x00000000u)

#define CSL_CP_ACE_PKA_DIVMSW_RESETVAL   (0x00008000u)

/* TRNG_OUTPUT_L */

#define CSL_CP_ACE_TRNG_OUTPUT_L_TRNG_OUTPUT_LOW_MASK (0xFFFFFFFFu)
#define CSL_CP_ACE_TRNG_OUTPUT_L_TRNG_OUTPUT_LOW_SHIFT (0x00000000u)
#define CSL_CP_ACE_TRNG_OUTPUT_L_TRNG_OUTPUT_LOW_RESETVAL (0x00000000u)

#define CSL_CP_ACE_TRNG_OUTPUT_L_RESETVAL (0x00000000u)

/* TRNG_OUTPUT_H */

#define CSL_CP_ACE_TRNG_OUTPUT_H_TRNG_OUTPUT_HIGH_MASK (0xFFFFFFFFu)
#define CSL_CP_ACE_TRNG_OUTPUT_H_TRNG_OUTPUT_HIGH_SHIFT (0x00000000u)
#define CSL_CP_ACE_TRNG_OUTPUT_H_TRNG_OUTPUT_HIGH_RESETVAL (0x00000000u)

#define CSL_CP_ACE_TRNG_OUTPUT_H_RESETVAL (0x00000000u)

/* TRNG_STATUS */

#define CSL_CP_ACE_TRNG_STATUS_NEED_CLOCK_MASK (0x80000000u)
#define CSL_CP_ACE_TRNG_STATUS_NEED_CLOCK_SHIFT (0x0000001Fu)
#define CSL_CP_ACE_TRNG_STATUS_NEED_CLOCK_RESETVAL (0x00000000u)

#define CSL_CP_ACE_TRNG_STATUS_SHUTDOWN_OFLO_MASK (0x00000002u)
#define CSL_CP_ACE_TRNG_STATUS_SHUTDOWN_OFLO_SHIFT (0x00000001u)
#define CSL_CP_ACE_TRNG_STATUS_SHUTDOWN_OFLO_RESETVAL (0x00000000u)

#define CSL_CP_ACE_TRNG_STATUS_READY_MASK (0x00000001u)
#define CSL_CP_ACE_TRNG_STATUS_READY_SHIFT (0x00000000u)
#define CSL_CP_ACE_TRNG_STATUS_READY_RESETVAL (0x00000000u)

#define CSL_CP_ACE_TRNG_STATUS_RESETVAL  (0x00000000u)

/* TRNG_INTMASK */

#define CSL_CP_ACE_TRNG_INTMASK_SHUTDOWN_OFLO_MASK (0x00000002u)
#define CSL_CP_ACE_TRNG_INTMASK_SHUTDOWN_OFLO_SHIFT (0x00000001u)
#define CSL_CP_ACE_TRNG_INTMASK_SHUTDOWN_OFLO_RESETVAL (0x00000000u)

#define CSL_CP_ACE_TRNG_INTMASK_READY_MASK (0x00000001u)
#define CSL_CP_ACE_TRNG_INTMASK_READY_SHIFT (0x00000000u)
#define CSL_CP_ACE_TRNG_INTMASK_READY_RESETVAL (0x00000000u)

#define CSL_CP_ACE_TRNG_INTMASK_RESETVAL (0x00000000u)

/* TRNG_INTACK */

#define CSL_CP_ACE_TRNG_INTACK_SHUTDOWN_OFLO_MASK (0x00000002u)
#define CSL_CP_ACE_TRNG_INTACK_SHUTDOWN_OFLO_SHIFT (0x00000001u)
#define CSL_CP_ACE_TRNG_INTACK_SHUTDOWN_OFLO_RESETVAL (0x00000000u)

#define CSL_CP_ACE_TRNG_INTACK_READY_MASK (0x00000001u)
#define CSL_CP_ACE_TRNG_INTACK_READY_SHIFT (0x00000000u)
#define CSL_CP_ACE_TRNG_INTACK_READY_RESETVAL (0x00000000u)

#define CSL_CP_ACE_TRNG_INTACK_RESETVAL  (0x00000000u)

/* TRNG_CONTROL */

#define CSL_CP_ACE_TRNG_CONTROL_STARTUP_CYCLES_MASK (0xFFFF0000u)
#define CSL_CP_ACE_TRNG_CONTROL_STARTUP_CYCLES_SHIFT (0x00000010u)
#define CSL_CP_ACE_TRNG_CONTROL_STARTUP_CYCLES_RESETVAL (0x00000000u)

#define CSL_CP_ACE_TRNG_CONTROL_ENABLE_TRNG_MASK (0x00000400u)
#define CSL_CP_ACE_TRNG_CONTROL_ENABLE_TRNG_SHIFT (0x0000000Au)
#define CSL_CP_ACE_TRNG_CONTROL_ENABLE_TRNG_RESETVAL (0x00000000u)

#define CSL_CP_ACE_TRNG_CONTROL_NO_LFSR_FB_MASK (0x00000004u)
#define CSL_CP_ACE_TRNG_CONTROL_NO_LFSR_FB_SHIFT (0x00000002u)
#define CSL_CP_ACE_TRNG_CONTROL_NO_LFSR_FB_RESETVAL (0x00000000u)

#define CSL_CP_ACE_TRNG_CONTROL_TEST_MODE_MASK (0x00000002u)
#define CSL_CP_ACE_TRNG_CONTROL_TEST_MODE_SHIFT (0x00000001u)
#define CSL_CP_ACE_TRNG_CONTROL_TEST_MODE_RESETVAL (0x00000000u)

#define CSL_CP_ACE_TRNG_CONTROL_RESETVAL (0x00000000u)

/* TRNG_CONFIG */

#define CSL_CP_ACE_TRNG_CONFIG_MAX_REFILL_CYCLES_MASK (0xFFFF0000u)
#define CSL_CP_ACE_TRNG_CONFIG_MAX_REFILL_CYCLES_SHIFT (0x00000010u)
#define CSL_CP_ACE_TRNG_CONFIG_MAX_REFILL_CYCLES_RESETVAL (0x00000000u)

#define CSL_CP_ACE_TRNG_CONFIG_SAMPLE_DIV_MASK (0x00000F00u)
#define CSL_CP_ACE_TRNG_CONFIG_SAMPLE_DIV_SHIFT (0x00000008u)
#define CSL_CP_ACE_TRNG_CONFIG_SAMPLE_DIV_RESETVAL (0x00000000u)

#define CSL_CP_ACE_TRNG_CONFIG_MIN_REFILL_CYCLES_MASK (0x000000FFu)
#define CSL_CP_ACE_TRNG_CONFIG_MIN_REFILL_CYCLES_SHIFT (0x00000000u)
#define CSL_CP_ACE_TRNG_CONFIG_MIN_REFILL_CYCLES_RESETVAL (0x00000000u)

#define CSL_CP_ACE_TRNG_CONFIG_RESETVAL  (0x00000000u)

/* TRNG_ALARMCNT */

#define CSL_CP_ACE_TRNG_ALARMCNT_SHUTDOWN_COUNT_MASK (0x3F000000u)
#define CSL_CP_ACE_TRNG_ALARMCNT_SHUTDOWN_COUNT_SHIFT (0x00000018u)
#define CSL_CP_ACE_TRNG_ALARMCNT_SHUTDOWN_COUNT_RESETVAL (0x00000000u)

#define CSL_CP_ACE_TRNG_ALARMCNT_SHUTDOWN_THRESHOLD_MASK (0x001F0000u)
#define CSL_CP_ACE_TRNG_ALARMCNT_SHUTDOWN_THRESHOLD_SHIFT (0x00000010u)
#define CSL_CP_ACE_TRNG_ALARMCNT_SHUTDOWN_THRESHOLD_RESETVAL (0x00000000u)

#define CSL_CP_ACE_TRNG_ALARMCNT_ALARM_THRESHOLD_MASK (0x000000FFu)
#define CSL_CP_ACE_TRNG_ALARMCNT_ALARM_THRESHOLD_SHIFT (0x00000000u)
#define CSL_CP_ACE_TRNG_ALARMCNT_ALARM_THRESHOLD_RESETVAL (0x00000000u)

#define CSL_CP_ACE_TRNG_ALARMCNT_RESETVAL (0x00000000u)

/* TRNG_FROENABLE */

#define CSL_CP_ACE_TRNG_FROENABLE_FRO_ENABLES_MASK (0x00FFFFFFu)
#define CSL_CP_ACE_TRNG_FROENABLE_FRO_ENABLES_SHIFT (0x00000000u)
#define CSL_CP_ACE_TRNG_FROENABLE_FRO_ENABLES_RESETVAL (0x00000000u)

#define CSL_CP_ACE_TRNG_FROENABLE_RESETVAL (0x00000000u)

/* TRNG_FRODETUNE */

#define CSL_CP_ACE_TRNG_FRODETUNE_FRO_DETUNES_MASK (0x00FFFFFFu)
#define CSL_CP_ACE_TRNG_FRODETUNE_FRO_DETUNES_SHIFT (0x00000000u)
#define CSL_CP_ACE_TRNG_FRODETUNE_FRO_DETUNES_RESETVAL (0x00000000u)

#define CSL_CP_ACE_TRNG_FRODETUNE_RESETVAL (0x00000000u)

/* TRNG_ALARMMASK */

#define CSL_CP_ACE_TRNG_ALARMMASK_FRO_ALARMMASKS_MASK (0x00FFFFFFu)
#define CSL_CP_ACE_TRNG_ALARMMASK_FRO_ALARMMASKS_SHIFT (0x00000000u)
#define CSL_CP_ACE_TRNG_ALARMMASK_FRO_ALARMMASKS_RESETVAL (0x00000000u)

#define CSL_CP_ACE_TRNG_ALARMMASK_RESETVAL (0x00000000u)

/* TRNG_ALARMSTOP */

#define CSL_CP_ACE_TRNG_ALARMSTOP_FRO_ALARMSTOPS_MASK (0x00FFFFFFu)
#define CSL_CP_ACE_TRNG_ALARMSTOP_FRO_ALARMSTOPS_SHIFT (0x00000000u)
#define CSL_CP_ACE_TRNG_ALARMSTOP_FRO_ALARMSTOPS_RESETVAL (0x00000000u)

#define CSL_CP_ACE_TRNG_ALARMSTOP_RESETVAL (0x00000000u)

/* TRNG_LFSR_L */

#define CSL_CP_ACE_TRNG_LFSR_L_LFSR_LOW_MASK (0xFFFFFFFFu)
#define CSL_CP_ACE_TRNG_LFSR_L_LFSR_LOW_SHIFT (0x00000000u)
#define CSL_CP_ACE_TRNG_LFSR_L_LFSR_LOW_RESETVAL (0x00000000u)

#define CSL_CP_ACE_TRNG_LFSR_L_RESETVAL  (0x00000000u)

/* TRNG_LFSR_M */

#define CSL_CP_ACE_TRNG_LFSR_M_LFSR_MID_MASK (0xFFFFFFFFu)
#define CSL_CP_ACE_TRNG_LFSR_M_LFSR_MID_SHIFT (0x00000000u)
#define CSL_CP_ACE_TRNG_LFSR_M_LFSR_MID_RESETVAL (0x00000000u)

#define CSL_CP_ACE_TRNG_LFSR_M_RESETVAL  (0x00000000u)

/* TRNG_LFSR_H */

#define CSL_CP_ACE_TRNG_LFSR_H_LFSR_HIGH_MASK (0x0001FFFFu)
#define CSL_CP_ACE_TRNG_LFSR_H_LFSR_HIGH_SHIFT (0x00000000u)
#define CSL_CP_ACE_TRNG_LFSR_H_LFSR_HIGH_RESETVAL (0x00000000u)

#define CSL_CP_ACE_TRNG_LFSR_H_RESETVAL  (0x00000000u)

/* TRNG_COUNT */

#define CSL_CP_ACE_TRNG_COUNT_SAMPLE_COUNTER_MASK (0x00FFFFFFu)
#define CSL_CP_ACE_TRNG_COUNT_SAMPLE_COUNTER_SHIFT (0x00000000u)
#define CSL_CP_ACE_TRNG_COUNT_SAMPLE_COUNTER_RESETVAL (0x00000000u)

#define CSL_CP_ACE_TRNG_COUNT_RESETVAL   (0x00000000u)

/* TRNG_TEST */

#define CSL_CP_ACE_TRNG_TEST_TEST_PATTERN_MASK (0x0FFF0000u)
#define CSL_CP_ACE_TRNG_TEST_TEST_PATTERN_SHIFT (0x00000010u)
#define CSL_CP_ACE_TRNG_TEST_TEST_PATTERN_RESETVAL (0x00000000u)

#define CSL_CP_ACE_TRNG_TEST_TEST_SELECT_MASK (0x00001F00u)
#define CSL_CP_ACE_TRNG_TEST_TEST_SELECT_SHIFT (0x00000008u)
#define CSL_CP_ACE_TRNG_TEST_TEST_SELECT_RESETVAL (0x00000000u)

#define CSL_CP_ACE_TRNG_TEST_TEST_PATT_DET_MASK (0x00000004u)
#define CSL_CP_ACE_TRNG_TEST_TEST_PATT_DET_SHIFT (0x00000002u)
#define CSL_CP_ACE_TRNG_TEST_TEST_PATT_DET_RESETVAL (0x00000000u)

#define CSL_CP_ACE_TRNG_TEST_TEST_PATT_FRO_MASK (0x00000002u)
#define CSL_CP_ACE_TRNG_TEST_TEST_PATT_FRO_SHIFT (0x00000001u)
#define CSL_CP_ACE_TRNG_TEST_TEST_PATT_FRO_RESETVAL (0x00000000u)

#define CSL_CP_ACE_TRNG_TEST_TEST_EN_OUT_MASK (0x00000001u)
#define CSL_CP_ACE_TRNG_TEST_TEST_EN_OUT_SHIFT (0x00000000u)
#define CSL_CP_ACE_TRNG_TEST_TEST_EN_OUT_RESETVAL (0x00000000u)

#define CSL_CP_ACE_TRNG_TEST_RESETVAL    (0x00000000u)

/* DATA */

#define CSL_CP_ACE_DATA_RESETVAL         (0x00000000u)

#endif
