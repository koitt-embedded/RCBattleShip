/********************************************************************
 * Copyright (C) 2003-2012 Texas Instruments Incorporated.
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
*********************************************************************
* file: cslr_xge_cpxmac_sl.h
*
* Brief: This file contains the Register Description for xge_cpxmac_sl
*
*********************************************************************/
#ifndef _CSLR_XGE_CPXMAC_SL_V1_H_
#define _CSLR_XGE_CPXMAC_SL_V1_H_

/* CSL Modification:
 *  The file has been modified from the AUTOGEN file for the following
 *  reasons:-
 *      a) Header files are included as per RTSC guidelines
 */

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint32 IDVER_REG;
    volatile Uint32 MACCONTROL_REG;
    volatile Uint32 MACSTATUS_REG;
    volatile Uint32 SOFT_RESET_REG;
    volatile Uint32 RX_MAXLEN_REG;
    volatile Uint32 BOFFTEST_REG;
    volatile Uint32 RX_PAUSE_REG;
    volatile Uint32 TX_PAUSE_REG;
    volatile Uint32 EMCONTROL_REG;
    volatile Uint32 PRI_MAP_REG;
    volatile Uint32 TX_GAP_REG;
} CSL_Xge_cpxmac_slRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* idver_reg */

#define CSL_XGE_CPXMAC_SL_IDVER_REG_Y_MASK (0x000000FFu)
#define CSL_XGE_CPXMAC_SL_IDVER_REG_Y_SHIFT (0x00000000u)
#define CSL_XGE_CPXMAC_SL_IDVER_REG_Y_RESETVAL (0x00000001u)

#define CSL_XGE_CPXMAC_SL_IDVER_REG_X_MASK (0x00000700u)
#define CSL_XGE_CPXMAC_SL_IDVER_REG_X_SHIFT (0x00000008u)
#define CSL_XGE_CPXMAC_SL_IDVER_REG_X_RESETVAL (0x00000001u)

#define CSL_XGE_CPXMAC_SL_IDVER_REG_Z_MASK (0x0000F800u)
#define CSL_XGE_CPXMAC_SL_IDVER_REG_Z_SHIFT (0x0000000Bu)
#define CSL_XGE_CPXMAC_SL_IDVER_REG_Z_RESETVAL (0x00000000u)

#define CSL_XGE_CPXMAC_SL_IDVER_REG_IDENT_MASK (0xFFFF0000u)
#define CSL_XGE_CPXMAC_SL_IDVER_REG_IDENT_SHIFT (0x00000010u)
#define CSL_XGE_CPXMAC_SL_IDVER_REG_IDENT_RESETVAL (0x00004EC3u)

#define CSL_XGE_CPXMAC_SL_IDVER_REG_RESETVAL (0x4EC30101u)

/* maccontrol_reg */

#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_FULLDUPLEX_MASK (0x00000001u)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_FULLDUPLEX_SHIFT (0x00000000u)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_FULLDUPLEX_RESETVAL (0x00000000u)

#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_LOOPBACK_MASK (0x00000002u)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_LOOPBACK_SHIFT (0x00000001u)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_LOOPBACK_RESETVAL (0x00000000u)

#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_MTEST_MASK (0x00000004u)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_MTEST_SHIFT (0x00000002u)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_MTEST_RESETVAL (0x00000000u)

#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_RX_FLOW_EN_MASK (0x00000008u)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_RX_FLOW_EN_SHIFT (0x00000003u)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_RX_FLOW_EN_RESETVAL (0x00000000u)

#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_TX_FLOW_EN_MASK (0x00000010u)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_TX_FLOW_EN_SHIFT (0x00000004u)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_TX_FLOW_EN_RESETVAL (0x00000000u)

#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_GMII_EN_MASK (0x00000020u)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_GMII_EN_SHIFT (0x00000005u)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_GMII_EN_RESETVAL (0x00000000u)

#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_TX_PACE_MASK (0x00000040u)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_TX_PACE_SHIFT (0x00000006u)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_TX_PACE_RESETVAL (0x00000000u)

#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_GIG_MASK (0x00000080u)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_GIG_SHIFT (0x00000007u)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_GIG_RESETVAL (0x00000000u)

#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_XGIG_MASK (0x00000100u)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_XGIG_SHIFT (0x00000008u)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_XGIG_RESETVAL (0x00000000u)

#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_TX_SHORT_GAP_ENABLE_MASK (0x00000400u)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_TX_SHORT_GAP_ENABLE_SHIFT (0x0000000Au)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_TX_SHORT_GAP_ENABLE_RESETVAL (0x00000000u)

#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_CMD_IDLE_MASK (0x00000800u)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_CMD_IDLE_SHIFT (0x0000000Bu)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_CMD_IDLE_RESETVAL (0x00000000u)

#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_CRC_TYPE_MASK (0x00001000u)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_CRC_TYPE_SHIFT (0x0000000Cu)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_CRC_TYPE_RESETVAL (0x00000000u)

#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_XGMII_EN_MASK (0x00002000u)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_XGMII_EN_SHIFT (0x0000000Du)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_XGMII_EN_RESETVAL (0x00000000u)

#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_IFCTL_A_MASK (0x00008000u)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_IFCTL_A_SHIFT (0x0000000Fu)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_IFCTL_A_RESETVAL (0x00000000u)

#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_IFCTL_B_MASK (0x00010000u)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_IFCTL_B_SHIFT (0x00000010u)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_IFCTL_B_RESETVAL (0x00000000u)

#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_GIG_FORCE_MASK (0x00020000u)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_GIG_FORCE_SHIFT (0x00000011u)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_GIG_FORCE_RESETVAL (0x00000000u)

#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_CTL_EN_MASK (0x00040000u)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_CTL_EN_SHIFT (0x00000012u)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_CTL_EN_RESETVAL (0x00000000u)

#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_TX_SHORT_GAP_LIM_EN_MASK (0x00200000u)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_TX_SHORT_GAP_LIM_EN_SHIFT (0x00000015u)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_TX_SHORT_GAP_LIM_EN_RESETVAL (0x00000000u)

#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_RX_CEF_EN_MASK (0x00400000u)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_RX_CEF_EN_SHIFT (0x00000016u)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_RX_CEF_EN_RESETVAL (0x00000000u)

#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_RX_CSF_EN_MASK (0x00800000u)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_RX_CSF_EN_SHIFT (0x00000017u)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_RX_CSF_EN_RESETVAL (0x00000000u)

#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_RX_CMF_EN_MASK (0x01000000u)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_RX_CMF_EN_SHIFT (0x00000018u)
#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_RX_CMF_EN_RESETVAL (0x00000000u)

#define CSL_XGE_CPXMAC_SL_MACCONTROL_REG_RESETVAL (0x00000000u)

/* macstatus_reg */

#define CSL_XGE_CPXMAC_SL_MACSTATUS_REG_TX_FLOW_ACT_MASK (0x00000001u)
#define CSL_XGE_CPXMAC_SL_MACSTATUS_REG_TX_FLOW_ACT_SHIFT (0x00000000u)
#define CSL_XGE_CPXMAC_SL_MACSTATUS_REG_TX_FLOW_ACT_RESETVAL (0x00000000u)

#define CSL_XGE_CPXMAC_SL_MACSTATUS_REG_RX_FLOW_ACT_MASK (0x00000002u)
#define CSL_XGE_CPXMAC_SL_MACSTATUS_REG_RX_FLOW_ACT_SHIFT (0x00000001u)
#define CSL_XGE_CPXMAC_SL_MACSTATUS_REG_RX_FLOW_ACT_RESETVAL (0x00000000u)

#define CSL_XGE_CPXMAC_SL_MACSTATUS_REG_EXT_FULLDUPLEX_MASK (0x00000008u)
#define CSL_XGE_CPXMAC_SL_MACSTATUS_REG_EXT_FULLDUPLEX_SHIFT (0x00000003u)

#define CSL_XGE_CPXMAC_SL_MACSTATUS_REG_EXT_GIG_MASK (0x00000010u)
#define CSL_XGE_CPXMAC_SL_MACSTATUS_REG_EXT_GIG_SHIFT (0x00000004u)

#define CSL_XGE_CPXMAC_SL_MACSTATUS_REG_IDLE_MASK (0x80000000u)
#define CSL_XGE_CPXMAC_SL_MACSTATUS_REG_IDLE_SHIFT (0x0000001Fu)
#define CSL_XGE_CPXMAC_SL_MACSTATUS_REG_IDLE_RESETVAL (0x00000001u)

#define CSL_XGE_CPXMAC_SL_MACSTATUS_REG_RESETVAL (0x80000000u)

/* soft_reset_reg */

#define CSL_XGE_CPXMAC_SL_SOFT_RESET_REG_SOFT_RESET_MASK (0x00000001u)
#define CSL_XGE_CPXMAC_SL_SOFT_RESET_REG_SOFT_RESET_SHIFT (0x00000000u)
#define CSL_XGE_CPXMAC_SL_SOFT_RESET_REG_SOFT_RESET_RESETVAL (0x00000000u)

#define CSL_XGE_CPXMAC_SL_SOFT_RESET_REG_RESETVAL (0x00000000u)

/* rx_maxlen_reg */

#define CSL_XGE_CPXMAC_SL_RX_MAXLEN_REG_RX_MAXLEN_MASK (0x00003FFFu)
#define CSL_XGE_CPXMAC_SL_RX_MAXLEN_REG_RX_MAXLEN_SHIFT (0x00000000u)
#define CSL_XGE_CPXMAC_SL_RX_MAXLEN_REG_RX_MAXLEN_RESETVAL (0x000005EEu)

#define CSL_XGE_CPXMAC_SL_RX_MAXLEN_REG_RESETVAL (0x000005EEu)

/* bofftest_reg */

#define CSL_XGE_CPXMAC_SL_BOFFTEST_REG_TX_BACKOFF_MASK (0x000003FFu)
#define CSL_XGE_CPXMAC_SL_BOFFTEST_REG_TX_BACKOFF_SHIFT (0x00000000u)
#define CSL_XGE_CPXMAC_SL_BOFFTEST_REG_TX_BACKOFF_RESETVAL (0x00000000u)

#define CSL_XGE_CPXMAC_SL_BOFFTEST_REG_COLL_COUNT_MASK (0x0000F000u)
#define CSL_XGE_CPXMAC_SL_BOFFTEST_REG_COLL_COUNT_SHIFT (0x0000000Cu)
#define CSL_XGE_CPXMAC_SL_BOFFTEST_REG_COLL_COUNT_RESETVAL (0x00000000u)

#define CSL_XGE_CPXMAC_SL_BOFFTEST_REG_RNDNUM_MASK (0x03FF0000u)
#define CSL_XGE_CPXMAC_SL_BOFFTEST_REG_RNDNUM_SHIFT (0x00000010u)
#define CSL_XGE_CPXMAC_SL_BOFFTEST_REG_RNDNUM_RESETVAL (0x00000000u)

#define CSL_XGE_CPXMAC_SL_BOFFTEST_REG_PACEVAL_MASK (0x7C000000u)
#define CSL_XGE_CPXMAC_SL_BOFFTEST_REG_PACEVAL_SHIFT (0x0000001Au)
#define CSL_XGE_CPXMAC_SL_BOFFTEST_REG_PACEVAL_RESETVAL (0x00000000u)

#define CSL_XGE_CPXMAC_SL_BOFFTEST_REG_RESETVAL (0x00000000u)

/* rx_pause_reg */

#define CSL_XGE_CPXMAC_SL_RX_PAUSE_REG_RX_PAUSETIMER_MASK (0x0000FFFFu)
#define CSL_XGE_CPXMAC_SL_RX_PAUSE_REG_RX_PAUSETIMER_SHIFT (0x00000000u)
#define CSL_XGE_CPXMAC_SL_RX_PAUSE_REG_RX_PAUSETIMER_RESETVAL (0x00000000u)

#define CSL_XGE_CPXMAC_SL_RX_PAUSE_REG_RESETVAL (0x00000000u)

/* tx_pause_reg */

#define CSL_XGE_CPXMAC_SL_TX_PAUSE_REG_TX_PAUSETIMER_MASK (0x0000FFFFu)
#define CSL_XGE_CPXMAC_SL_TX_PAUSE_REG_TX_PAUSETIMER_SHIFT (0x00000000u)
#define CSL_XGE_CPXMAC_SL_TX_PAUSE_REG_TX_PAUSETIMER_RESETVAL (0x00000000u)

#define CSL_XGE_CPXMAC_SL_TX_PAUSE_REG_RESETVAL (0x00000000u)

/* emcontrol_reg */

#define CSL_XGE_CPXMAC_SL_EMCONTROL_REG_FREE_MASK (0x00000001u)
#define CSL_XGE_CPXMAC_SL_EMCONTROL_REG_FREE_SHIFT (0x00000000u)
#define CSL_XGE_CPXMAC_SL_EMCONTROL_REG_FREE_RESETVAL (0x00000000u)

#define CSL_XGE_CPXMAC_SL_EMCONTROL_REG_SOFT_MASK (0x00000002u)
#define CSL_XGE_CPXMAC_SL_EMCONTROL_REG_SOFT_SHIFT (0x00000001u)
#define CSL_XGE_CPXMAC_SL_EMCONTROL_REG_SOFT_RESETVAL (0x00000000u)

#define CSL_XGE_CPXMAC_SL_EMCONTROL_REG_RESETVAL (0x00000000u)

/* pri_map_reg */

#define CSL_XGE_CPXMAC_SL_PRI_MAP_REG_PRI0_MASK (0x00000007u)
#define CSL_XGE_CPXMAC_SL_PRI_MAP_REG_PRI0_SHIFT (0x00000000u)
#define CSL_XGE_CPXMAC_SL_PRI_MAP_REG_PRI0_RESETVAL (0x00000000u)

#define CSL_XGE_CPXMAC_SL_PRI_MAP_REG_PRI1_MASK (0x00000070u)
#define CSL_XGE_CPXMAC_SL_PRI_MAP_REG_PRI1_SHIFT (0x00000004u)
#define CSL_XGE_CPXMAC_SL_PRI_MAP_REG_PRI1_RESETVAL (0x00000001u)

#define CSL_XGE_CPXMAC_SL_PRI_MAP_REG_PRI2_MASK (0x00000700u)
#define CSL_XGE_CPXMAC_SL_PRI_MAP_REG_PRI2_SHIFT (0x00000008u)
#define CSL_XGE_CPXMAC_SL_PRI_MAP_REG_PRI2_RESETVAL (0x00000002u)

#define CSL_XGE_CPXMAC_SL_PRI_MAP_REG_PRI3_MASK (0x00007000u)
#define CSL_XGE_CPXMAC_SL_PRI_MAP_REG_PRI3_SHIFT (0x0000000Cu)
#define CSL_XGE_CPXMAC_SL_PRI_MAP_REG_PRI3_RESETVAL (0x00000003u)

#define CSL_XGE_CPXMAC_SL_PRI_MAP_REG_PRI4_MASK (0x00070000u)
#define CSL_XGE_CPXMAC_SL_PRI_MAP_REG_PRI4_SHIFT (0x00000010u)
#define CSL_XGE_CPXMAC_SL_PRI_MAP_REG_PRI4_RESETVAL (0x00000004u)

#define CSL_XGE_CPXMAC_SL_PRI_MAP_REG_PRI5_MASK (0x00700000u)
#define CSL_XGE_CPXMAC_SL_PRI_MAP_REG_PRI5_SHIFT (0x00000014u)
#define CSL_XGE_CPXMAC_SL_PRI_MAP_REG_PRI5_RESETVAL (0x00000005u)

#define CSL_XGE_CPXMAC_SL_PRI_MAP_REG_PRI6_MASK (0x07000000u)
#define CSL_XGE_CPXMAC_SL_PRI_MAP_REG_PRI6_SHIFT (0x00000018u)
#define CSL_XGE_CPXMAC_SL_PRI_MAP_REG_PRI6_RESETVAL (0x00000006u)

#define CSL_XGE_CPXMAC_SL_PRI_MAP_REG_PRI7_MASK (0x70000000u)
#define CSL_XGE_CPXMAC_SL_PRI_MAP_REG_PRI7_SHIFT (0x0000001Cu)
#define CSL_XGE_CPXMAC_SL_PRI_MAP_REG_PRI7_RESETVAL (0x00000007u)

#define CSL_XGE_CPXMAC_SL_PRI_MAP_REG_RESETVAL (0x76543210u)

/* tx_gap_reg */

#define CSL_XGE_CPXMAC_SL_TX_GAP_REG_TX_GAP_MASK (0x0000FFFFu)
#define CSL_XGE_CPXMAC_SL_TX_GAP_REG_TX_GAP_SHIFT (0x00000000u)
#define CSL_XGE_CPXMAC_SL_TX_GAP_REG_TX_GAP_RESETVAL (0x0000000Cu)

#define CSL_XGE_CPXMAC_SL_TX_GAP_REG_RESETVAL (0x0000000Cu)

#endif
