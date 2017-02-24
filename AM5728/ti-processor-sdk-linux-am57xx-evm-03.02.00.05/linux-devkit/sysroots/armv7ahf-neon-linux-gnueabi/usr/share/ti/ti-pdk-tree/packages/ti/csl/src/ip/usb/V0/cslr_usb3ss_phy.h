/********************************************************************
 * Copyright (C) 2013-2014 Texas Instruments Incorporated.
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
#ifndef _CSLR_USB3SSPHY_H_
#define _CSLR_USB3SSPHY_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for picoPHY_MMR
**************************************************************************/
typedef struct {
    volatile Uint32 STS_SQUELCH;
    volatile Uint8  RSVD0[8];
    volatile Uint32 STS_UTMI_TX;
    volatile Uint32 STS_UTMI_RX;
    volatile Uint32 STS_UTMI_DATAOUT;
    volatile Uint32 STS_TX_PAR_RES;
    volatile Uint32 STS_UTMI_DATAIN;
    volatile Uint32 STS_DIFFERENTIAL;
    volatile Uint32 STS_BIST;
    volatile Uint8  RSVD1[4];
    volatile Uint32 STS_DISC_COMP;
    volatile Uint8  RSVD2[4];
    volatile Uint32 STS_TAP;
    volatile Uint8  RSVD3[8];
    volatile Uint32 ANA_TST_CNTL_ADDR;
    volatile Uint8  RSVD4[12];
    volatile Uint32 DP_OVERRIDE;
    volatile Uint32 ANA_TST_CNTL_MST;
    volatile Uint32 TX_PAR_REST;
    volatile Uint8  RSVD5[4];
    volatile Uint32 BIST_EN;
    volatile Uint32 BIST_ERROR;
    volatile Uint8  RSVD6[4];
    volatile Uint32 DISC_COMP;
    volatile Uint8  RSVD7[4];
    volatile Uint32 BIST_MODE;
    volatile Uint32 TAP;
    volatile Uint32 TEST_IF_RESET;
} CSL_Usb3ssPhyRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* STS_SQUELCH */
#define CSL_USB3SSPHY_STS_SQUELCH                               (0x0U)

/* STS_UTMI_TX */
#define CSL_USB3SSPHY_STS_UTMI_TX                               (0xCU)

/* STS_UTMI_RX */
#define CSL_USB3SSPHY_STS_UTMI_RX                               (0x10U)

/* STS_UTMI_DATAOUT */
#define CSL_USB3SSPHY_STS_UTMI_DATAOUT                          (0x14U)

/* STS_TX_PAR_RES */
#define CSL_USB3SSPHY_STS_TX_PAR_RES                            (0x18U)

/* STS_UTMI_DATAIN */
#define CSL_USB3SSPHY_STS_UTMI_DATAIN                           (0x1CU)

/* STS_DIFFERENTIAL */
#define CSL_USB3SSPHY_STS_DIFFERENTIAL                          (0x20U)

/* STS_BIST */
#define CSL_USB3SSPHY_STS_BIST                                  (0x24U)

/* STS_DISC_COMP */
#define CSL_USB3SSPHY_STS_DISC_COMP                             (0x2CU)

/* STS_TAP */
#define CSL_USB3SSPHY_STS_TAP                                   (0x34U)

/* ANA_TST_CNTL_ADDR */
#define CSL_USB3SSPHY_ANA_TST_CNTL_ADDR                         (0x40U)

/* DP_OVERRIDE */
#define CSL_USB3SSPHY_DP_OVERRIDE                               (0x50U)

/* ANA_TST_CNTL_MST */
#define CSL_USB3SSPHY_ANA_TST_CNTL_MST                          (0x54U)

/* TX_PAR_REST */
#define CSL_USB3SSPHY_TX_PAR_REST                               (0x58U)

/* BIST_EN */
#define CSL_USB3SSPHY_BIST_EN                                   (0x60U)

/* BIST_ERROR */
#define CSL_USB3SSPHY_BIST_ERROR                                (0x64U)

/* DISC_COMP */
#define CSL_USB3SSPHY_DISC_COMP                                 (0x6CU)

/* BIST_MODE */
#define CSL_USB3SSPHY_BIST_MODE                                 (0x74U)

/* TAP */
#define CSL_USB3SSPHY_TAP                                       (0x78U)

/* TEST_IF_RESET */
#define CSL_USB3SSPHY_TEST_IF_RESET                             (0x7CU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* STS_SQUELCH */

#define CSL_USB3SSPHY_STS_SQUELCH_SQUELCH_MASK                  (0x00000004U)
#define CSL_USB3SSPHY_STS_SQUELCH_SQUELCH_SHIFT                 (2U)
#define CSL_USB3SSPHY_STS_SQUELCH_SQUELCH_RESETVAL              (0x00000000U)
#define CSL_USB3SSPHY_STS_SQUELCH_SQUELCH_MAX                   (0x00000001U)

#define CSL_USB3SSPHY_STS_SQUELCH_RESETVAL                      (0x00000000U)

/* STS_UTMI_TX */

#define CSL_USB3SSPHY_STS_UTMI_TX_TXVALID_MASK                  (0x00000004U)
#define CSL_USB3SSPHY_STS_UTMI_TX_TXVALID_SHIFT                 (2U)
#define CSL_USB3SSPHY_STS_UTMI_TX_TXVALID_RESETVAL              (0x00000000U)
#define CSL_USB3SSPHY_STS_UTMI_TX_TXVALID_MAX                   (0x00000001U)

#define CSL_USB3SSPHY_STS_UTMI_TX_TXREADY_MASK                  (0x00000001U)
#define CSL_USB3SSPHY_STS_UTMI_TX_TXREADY_SHIFT                 (0U)
#define CSL_USB3SSPHY_STS_UTMI_TX_TXREADY_RESETVAL              (0x00000000U)
#define CSL_USB3SSPHY_STS_UTMI_TX_TXREADY_MAX                   (0x00000001U)

#define CSL_USB3SSPHY_STS_UTMI_TX_TXVALIDH_MASK                 (0x00000002U)
#define CSL_USB3SSPHY_STS_UTMI_TX_TXVALIDH_SHIFT                (1U)
#define CSL_USB3SSPHY_STS_UTMI_TX_TXVALIDH_RESETVAL             (0x00000000U)
#define CSL_USB3SSPHY_STS_UTMI_TX_TXVALIDH_MAX                  (0x00000001U)

#define CSL_USB3SSPHY_STS_UTMI_TX_RESETVAL                      (0x00000000U)

/* STS_UTMI_RX */

#define CSL_USB3SSPHY_STS_UTMI_RX_RXVALID_MASK                  (0x00000004U)
#define CSL_USB3SSPHY_STS_UTMI_RX_RXVALID_SHIFT                 (2U)
#define CSL_USB3SSPHY_STS_UTMI_RX_RXVALID_RESETVAL              (0x00000000U)
#define CSL_USB3SSPHY_STS_UTMI_RX_RXVALID_MAX                   (0x00000001U)

#define CSL_USB3SSPHY_STS_UTMI_RX_RXERROR_MASK                  (0x00000001U)
#define CSL_USB3SSPHY_STS_UTMI_RX_RXERROR_SHIFT                 (0U)
#define CSL_USB3SSPHY_STS_UTMI_RX_RXERROR_RESETVAL              (0x00000000U)
#define CSL_USB3SSPHY_STS_UTMI_RX_RXERROR_MAX                   (0x00000001U)

#define CSL_USB3SSPHY_STS_UTMI_RX_RXVALIDH_MASK                 (0x00000002U)
#define CSL_USB3SSPHY_STS_UTMI_RX_RXVALIDH_SHIFT                (1U)
#define CSL_USB3SSPHY_STS_UTMI_RX_RXVALIDH_RESETVAL             (0x00000000U)
#define CSL_USB3SSPHY_STS_UTMI_RX_RXVALIDH_MAX                  (0x00000001U)

#define CSL_USB3SSPHY_STS_UTMI_RX_RXACTIVE_MASK                 (0x00000008U)
#define CSL_USB3SSPHY_STS_UTMI_RX_RXACTIVE_SHIFT                (3U)
#define CSL_USB3SSPHY_STS_UTMI_RX_RXACTIVE_RESETVAL             (0x00000000U)
#define CSL_USB3SSPHY_STS_UTMI_RX_RXACTIVE_MAX                  (0x00000001U)

#define CSL_USB3SSPHY_STS_UTMI_RX_RESETVAL                      (0x00000000U)

/* STS_UTMI_DATAOUT */

#define CSL_USB3SSPHY_STS_UTMI_DATAOUT_DATAOUT_2_MASK           (0x00000004U)
#define CSL_USB3SSPHY_STS_UTMI_DATAOUT_DATAOUT_2_SHIFT          (2U)
#define CSL_USB3SSPHY_STS_UTMI_DATAOUT_DATAOUT_2_RESETVAL       (0x00000000U)
#define CSL_USB3SSPHY_STS_UTMI_DATAOUT_DATAOUT_2_MAX            (0x00000001U)

#define CSL_USB3SSPHY_STS_UTMI_DATAOUT_DATAOUT_0_MASK           (0x00000001U)
#define CSL_USB3SSPHY_STS_UTMI_DATAOUT_DATAOUT_0_SHIFT          (0U)
#define CSL_USB3SSPHY_STS_UTMI_DATAOUT_DATAOUT_0_RESETVAL       (0x00000000U)
#define CSL_USB3SSPHY_STS_UTMI_DATAOUT_DATAOUT_0_MAX            (0x00000001U)

#define CSL_USB3SSPHY_STS_UTMI_DATAOUT_DATAOUT_1_MASK           (0x00000002U)
#define CSL_USB3SSPHY_STS_UTMI_DATAOUT_DATAOUT_1_SHIFT          (1U)
#define CSL_USB3SSPHY_STS_UTMI_DATAOUT_DATAOUT_1_RESETVAL       (0x00000000U)
#define CSL_USB3SSPHY_STS_UTMI_DATAOUT_DATAOUT_1_MAX            (0x00000001U)

#define CSL_USB3SSPHY_STS_UTMI_DATAOUT_DATAOUT_3_MASK           (0x00000008U)
#define CSL_USB3SSPHY_STS_UTMI_DATAOUT_DATAOUT_3_SHIFT          (3U)
#define CSL_USB3SSPHY_STS_UTMI_DATAOUT_DATAOUT_3_RESETVAL       (0x00000000U)
#define CSL_USB3SSPHY_STS_UTMI_DATAOUT_DATAOUT_3_MAX            (0x00000001U)

#define CSL_USB3SSPHY_STS_UTMI_DATAOUT_RESETVAL                 (0x00000000U)

/* STS_TX_PAR_RES */

#define CSL_USB3SSPHY_STS_TX_PAR_RES_TX_PAR_RES_2_MASK          (0x00000004U)
#define CSL_USB3SSPHY_STS_TX_PAR_RES_TX_PAR_RES_2_SHIFT         (2U)
#define CSL_USB3SSPHY_STS_TX_PAR_RES_TX_PAR_RES_2_RESETVAL      (0x00000000U)
#define CSL_USB3SSPHY_STS_TX_PAR_RES_TX_PAR_RES_2_MAX           (0x00000001U)

#define CSL_USB3SSPHY_STS_TX_PAR_RES_TX_PAR_RES_0_MASK          (0x00000001U)
#define CSL_USB3SSPHY_STS_TX_PAR_RES_TX_PAR_RES_0_SHIFT         (0U)
#define CSL_USB3SSPHY_STS_TX_PAR_RES_TX_PAR_RES_0_RESETVAL      (0x00000000U)
#define CSL_USB3SSPHY_STS_TX_PAR_RES_TX_PAR_RES_0_MAX           (0x00000001U)

#define CSL_USB3SSPHY_STS_TX_PAR_RES_TX_PAR_RES_1_MASK          (0x00000002U)
#define CSL_USB3SSPHY_STS_TX_PAR_RES_TX_PAR_RES_1_SHIFT         (1U)
#define CSL_USB3SSPHY_STS_TX_PAR_RES_TX_PAR_RES_1_RESETVAL      (0x00000000U)
#define CSL_USB3SSPHY_STS_TX_PAR_RES_TX_PAR_RES_1_MAX           (0x00000001U)

#define CSL_USB3SSPHY_STS_TX_PAR_RES_TX_PAR_RES_3_MASK          (0x00000008U)
#define CSL_USB3SSPHY_STS_TX_PAR_RES_TX_PAR_RES_3_SHIFT         (3U)
#define CSL_USB3SSPHY_STS_TX_PAR_RES_TX_PAR_RES_3_RESETVAL      (0x00000000U)
#define CSL_USB3SSPHY_STS_TX_PAR_RES_TX_PAR_RES_3_MAX           (0x00000001U)

#define CSL_USB3SSPHY_STS_TX_PAR_RES_RESETVAL                   (0x00000000U)

/* STS_UTMI_DATAIN */

#define CSL_USB3SSPHY_STS_UTMI_DATAIN_DATAIN_2_MASK             (0x00000004U)
#define CSL_USB3SSPHY_STS_UTMI_DATAIN_DATAIN_2_SHIFT            (2U)
#define CSL_USB3SSPHY_STS_UTMI_DATAIN_DATAIN_2_RESETVAL         (0x00000000U)
#define CSL_USB3SSPHY_STS_UTMI_DATAIN_DATAIN_2_MAX              (0x00000001U)

#define CSL_USB3SSPHY_STS_UTMI_DATAIN_DATAIN_0_MASK             (0x00000001U)
#define CSL_USB3SSPHY_STS_UTMI_DATAIN_DATAIN_0_SHIFT            (0U)
#define CSL_USB3SSPHY_STS_UTMI_DATAIN_DATAIN_0_RESETVAL         (0x00000000U)
#define CSL_USB3SSPHY_STS_UTMI_DATAIN_DATAIN_0_MAX              (0x00000001U)

#define CSL_USB3SSPHY_STS_UTMI_DATAIN_DATAIN_1_MASK             (0x00000002U)
#define CSL_USB3SSPHY_STS_UTMI_DATAIN_DATAIN_1_SHIFT            (1U)
#define CSL_USB3SSPHY_STS_UTMI_DATAIN_DATAIN_1_RESETVAL         (0x00000000U)
#define CSL_USB3SSPHY_STS_UTMI_DATAIN_DATAIN_1_MAX              (0x00000001U)

#define CSL_USB3SSPHY_STS_UTMI_DATAIN_DATAIN_3_MASK             (0x00000008U)
#define CSL_USB3SSPHY_STS_UTMI_DATAIN_DATAIN_3_SHIFT            (3U)
#define CSL_USB3SSPHY_STS_UTMI_DATAIN_DATAIN_3_RESETVAL         (0x00000000U)
#define CSL_USB3SSPHY_STS_UTMI_DATAIN_DATAIN_3_MAX              (0x00000001U)

#define CSL_USB3SSPHY_STS_UTMI_DATAIN_RESETVAL                  (0x00000000U)

/* STS_DIFFERENTIAL */

#define CSL_USB3SSPHY_STS_DIFFERENTIAL_SE_RX_DP_MASK            (0x00000004U)
#define CSL_USB3SSPHY_STS_DIFFERENTIAL_SE_RX_DP_SHIFT           (2U)
#define CSL_USB3SSPHY_STS_DIFFERENTIAL_SE_RX_DP_RESETVAL        (0x00000000U)
#define CSL_USB3SSPHY_STS_DIFFERENTIAL_SE_RX_DP_MAX             (0x00000001U)

#define CSL_USB3SSPHY_STS_DIFFERENTIAL_FS_DIFF_RX_DATA_MASK     (0x00000001U)
#define CSL_USB3SSPHY_STS_DIFFERENTIAL_FS_DIFF_RX_DATA_SHIFT    (0U)
#define CSL_USB3SSPHY_STS_DIFFERENTIAL_FS_DIFF_RX_DATA_RESETVAL  (0x00000000U)
#define CSL_USB3SSPHY_STS_DIFFERENTIAL_FS_DIFF_RX_DATA_MAX      (0x00000001U)

#define CSL_USB3SSPHY_STS_DIFFERENTIAL_HS_DIFF_RX_DATA_MASK     (0x00000002U)
#define CSL_USB3SSPHY_STS_DIFFERENTIAL_HS_DIFF_RX_DATA_SHIFT    (1U)
#define CSL_USB3SSPHY_STS_DIFFERENTIAL_HS_DIFF_RX_DATA_RESETVAL  (0x00000000U)
#define CSL_USB3SSPHY_STS_DIFFERENTIAL_HS_DIFF_RX_DATA_MAX      (0x00000001U)

#define CSL_USB3SSPHY_STS_DIFFERENTIAL_SE_RX_DM_MASK            (0x00000008U)
#define CSL_USB3SSPHY_STS_DIFFERENTIAL_SE_RX_DM_SHIFT           (3U)
#define CSL_USB3SSPHY_STS_DIFFERENTIAL_SE_RX_DM_RESETVAL        (0x00000000U)
#define CSL_USB3SSPHY_STS_DIFFERENTIAL_SE_RX_DM_MAX             (0x00000001U)

#define CSL_USB3SSPHY_STS_DIFFERENTIAL_RESETVAL                 (0x00000000U)

/* STS_BIST */

#define CSL_USB3SSPHY_STS_BIST_HS_TX_SHORT_DET_MASK             (0x00000004U)
#define CSL_USB3SSPHY_STS_BIST_HS_TX_SHORT_DET_SHIFT            (2U)
#define CSL_USB3SSPHY_STS_BIST_HS_TX_SHORT_DET_RESETVAL         (0x00000000U)
#define CSL_USB3SSPHY_STS_BIST_HS_TX_SHORT_DET_MAX              (0x00000001U)

#define CSL_USB3SSPHY_STS_BIST_BISTERROR_MASK                   (0x00000001U)
#define CSL_USB3SSPHY_STS_BIST_BISTERROR_SHIFT                  (0U)
#define CSL_USB3SSPHY_STS_BIST_BISTERROR_RESETVAL               (0x00000000U)
#define CSL_USB3SSPHY_STS_BIST_BISTERROR_MAX                    (0x00000001U)

#define CSL_USB3SSPHY_STS_BIST_BISTDONE_MASK                    (0x00000002U)
#define CSL_USB3SSPHY_STS_BIST_BISTDONE_SHIFT                   (1U)
#define CSL_USB3SSPHY_STS_BIST_BISTDONE_RESETVAL                (0x00000000U)
#define CSL_USB3SSPHY_STS_BIST_BISTDONE_MAX                     (0x00000001U)

#define CSL_USB3SSPHY_STS_BIST_RESETVAL                         (0x00000000U)

/* STS_DISC_COMP */

#define CSL_USB3SSPHY_STS_DISC_COMP_DISC_COMP_LATCH_EN_MASK     (0x00000004U)
#define CSL_USB3SSPHY_STS_DISC_COMP_DISC_COMP_LATCH_EN_SHIFT    (2U)
#define CSL_USB3SSPHY_STS_DISC_COMP_DISC_COMP_LATCH_EN_RESETVAL  (0x00000000U)
#define CSL_USB3SSPHY_STS_DISC_COMP_DISC_COMP_LATCH_EN_MAX      (0x00000001U)

#define CSL_USB3SSPHY_STS_DISC_COMP_DISC_COMP_OUT_MASK          (0x00000002U)
#define CSL_USB3SSPHY_STS_DISC_COMP_DISC_COMP_OUT_SHIFT         (1U)
#define CSL_USB3SSPHY_STS_DISC_COMP_DISC_COMP_OUT_RESETVAL      (0x00000000U)
#define CSL_USB3SSPHY_STS_DISC_COMP_DISC_COMP_OUT_MAX           (0x00000001U)

#define CSL_USB3SSPHY_STS_DISC_COMP_RESETVAL                    (0x00000000U)

/* STS_TAP */

#define CSL_USB3SSPHY_STS_TAP_TAP_VAL_2_MASK                    (0x00000004U)
#define CSL_USB3SSPHY_STS_TAP_TAP_VAL_2_SHIFT                   (2U)
#define CSL_USB3SSPHY_STS_TAP_TAP_VAL_2_RESETVAL                (0x00000000U)
#define CSL_USB3SSPHY_STS_TAP_TAP_VAL_2_MAX                     (0x00000001U)

#define CSL_USB3SSPHY_STS_TAP_TAP_VAL_0_MASK                    (0x00000001U)
#define CSL_USB3SSPHY_STS_TAP_TAP_VAL_0_SHIFT                   (0U)
#define CSL_USB3SSPHY_STS_TAP_TAP_VAL_0_RESETVAL                (0x00000000U)
#define CSL_USB3SSPHY_STS_TAP_TAP_VAL_0_MAX                     (0x00000001U)

#define CSL_USB3SSPHY_STS_TAP_TAP_VAL_1_MASK                    (0x00000002U)
#define CSL_USB3SSPHY_STS_TAP_TAP_VAL_1_SHIFT                   (1U)
#define CSL_USB3SSPHY_STS_TAP_TAP_VAL_1_RESETVAL                (0x00000000U)
#define CSL_USB3SSPHY_STS_TAP_TAP_VAL_1_MAX                     (0x00000001U)

#define CSL_USB3SSPHY_STS_TAP_TAP_VAL_3_MASK                    (0x00000008U)
#define CSL_USB3SSPHY_STS_TAP_TAP_VAL_3_SHIFT                   (3U)
#define CSL_USB3SSPHY_STS_TAP_TAP_VAL_3_RESETVAL                (0x00000000U)
#define CSL_USB3SSPHY_STS_TAP_TAP_VAL_3_MAX                     (0x00000001U)

#define CSL_USB3SSPHY_STS_TAP_RESETVAL                          (0x00000000U)

/* ANA_TST_CNTL_ADDR */

#define CSL_USB3SSPHY_ANA_TST_CNTL_ADDR_ADDR_2_MASK             (0x00000004U)
#define CSL_USB3SSPHY_ANA_TST_CNTL_ADDR_ADDR_2_SHIFT            (2U)
#define CSL_USB3SSPHY_ANA_TST_CNTL_ADDR_ADDR_2_RESETVAL         (0x00000000U)
#define CSL_USB3SSPHY_ANA_TST_CNTL_ADDR_ADDR_2_MAX              (0x00000001U)

#define CSL_USB3SSPHY_ANA_TST_CNTL_ADDR_ADDR_0_MASK             (0x00000001U)
#define CSL_USB3SSPHY_ANA_TST_CNTL_ADDR_ADDR_0_SHIFT            (0U)
#define CSL_USB3SSPHY_ANA_TST_CNTL_ADDR_ADDR_0_RESETVAL         (0x00000000U)
#define CSL_USB3SSPHY_ANA_TST_CNTL_ADDR_ADDR_0_MAX              (0x00000001U)

#define CSL_USB3SSPHY_ANA_TST_CNTL_ADDR_ADDR_1_MASK             (0x00000002U)
#define CSL_USB3SSPHY_ANA_TST_CNTL_ADDR_ADDR_1_SHIFT            (1U)
#define CSL_USB3SSPHY_ANA_TST_CNTL_ADDR_ADDR_1_RESETVAL         (0x00000000U)
#define CSL_USB3SSPHY_ANA_TST_CNTL_ADDR_ADDR_1_MAX              (0x00000001U)

#define CSL_USB3SSPHY_ANA_TST_CNTL_ADDR_ADDR_3_MASK             (0x00000008U)
#define CSL_USB3SSPHY_ANA_TST_CNTL_ADDR_ADDR_3_SHIFT            (3U)
#define CSL_USB3SSPHY_ANA_TST_CNTL_ADDR_ADDR_3_RESETVAL         (0x00000000U)
#define CSL_USB3SSPHY_ANA_TST_CNTL_ADDR_ADDR_3_MAX              (0x00000001U)

#define CSL_USB3SSPHY_ANA_TST_CNTL_ADDR_RESETVAL                (0x00000000U)

/* DP_OVERRIDE */

#define CSL_USB3SSPHY_DP_OVERRIDE_DP_PULLUP_OVERR_1_MASK        (0x00000001U)
#define CSL_USB3SSPHY_DP_OVERRIDE_DP_PULLUP_OVERR_1_SHIFT       (0U)
#define CSL_USB3SSPHY_DP_OVERRIDE_DP_PULLUP_OVERR_1_RESETVAL    (0x00000000U)
#define CSL_USB3SSPHY_DP_OVERRIDE_DP_PULLUP_OVERR_1_MAX         (0x00000001U)

#define CSL_USB3SSPHY_DP_OVERRIDE_DP_PULLUP_OVERR_2_MASK        (0x00000002U)
#define CSL_USB3SSPHY_DP_OVERRIDE_DP_PULLUP_OVERR_2_SHIFT       (1U)
#define CSL_USB3SSPHY_DP_OVERRIDE_DP_PULLUP_OVERR_2_RESETVAL    (0x00000000U)
#define CSL_USB3SSPHY_DP_OVERRIDE_DP_PULLUP_OVERR_2_MAX         (0x00000001U)

#define CSL_USB3SSPHY_DP_OVERRIDE_RESETVAL                      (0x00000000U)

/* ANA_TST_CNTL_MST */

#define CSL_USB3SSPHY_ANA_TST_CNTL_MST_ADDR_4_MASK              (0x00000001U)
#define CSL_USB3SSPHY_ANA_TST_CNTL_MST_ADDR_4_SHIFT             (0U)
#define CSL_USB3SSPHY_ANA_TST_CNTL_MST_ADDR_4_RESETVAL          (0x00000000U)
#define CSL_USB3SSPHY_ANA_TST_CNTL_MST_ADDR_4_MAX               (0x00000001U)

#define CSL_USB3SSPHY_ANA_TST_CNTL_MST_MST_OVERRIDE_MASK        (0x00000002U)
#define CSL_USB3SSPHY_ANA_TST_CNTL_MST_MST_OVERRIDE_SHIFT       (1U)
#define CSL_USB3SSPHY_ANA_TST_CNTL_MST_MST_OVERRIDE_RESETVAL    (0x00000000U)
#define CSL_USB3SSPHY_ANA_TST_CNTL_MST_MST_OVERRIDE_MAX         (0x00000001U)

#define CSL_USB3SSPHY_ANA_TST_CNTL_MST_RESETVAL                 (0x00000000U)

/* TX_PAR_REST */

#define CSL_USB3SSPHY_TX_PAR_REST_TX_PAR_RES_2_MASK             (0x00000004U)
#define CSL_USB3SSPHY_TX_PAR_REST_TX_PAR_RES_2_SHIFT            (2U)
#define CSL_USB3SSPHY_TX_PAR_REST_TX_PAR_RES_2_RESETVAL         (0x00000000U)
#define CSL_USB3SSPHY_TX_PAR_REST_TX_PAR_RES_2_MAX              (0x00000001U)

#define CSL_USB3SSPHY_TX_PAR_REST_TX_PAR_RES_0_MASK             (0x00000001U)
#define CSL_USB3SSPHY_TX_PAR_REST_TX_PAR_RES_0_SHIFT            (0U)
#define CSL_USB3SSPHY_TX_PAR_REST_TX_PAR_RES_0_RESETVAL         (0x00000000U)
#define CSL_USB3SSPHY_TX_PAR_REST_TX_PAR_RES_0_MAX              (0x00000001U)

#define CSL_USB3SSPHY_TX_PAR_REST_TX_PAR_RES_1_MASK             (0x00000002U)
#define CSL_USB3SSPHY_TX_PAR_REST_TX_PAR_RES_1_SHIFT            (1U)
#define CSL_USB3SSPHY_TX_PAR_REST_TX_PAR_RES_1_RESETVAL         (0x00000000U)
#define CSL_USB3SSPHY_TX_PAR_REST_TX_PAR_RES_1_MAX              (0x00000001U)

#define CSL_USB3SSPHY_TX_PAR_REST_TX_PAR_RES_3_MASK             (0x00000008U)
#define CSL_USB3SSPHY_TX_PAR_REST_TX_PAR_RES_3_SHIFT            (3U)
#define CSL_USB3SSPHY_TX_PAR_REST_TX_PAR_RES_3_RESETVAL         (0x00000000U)
#define CSL_USB3SSPHY_TX_PAR_REST_TX_PAR_RES_3_MAX              (0x00000001U)

#define CSL_USB3SSPHY_TX_PAR_REST_RESETVAL                      (0x00000000U)

/* BIST_EN */

#define CSL_USB3SSPHY_BIST_EN_HS_BIST_MASK                      (0x00000004U)
#define CSL_USB3SSPHY_BIST_EN_HS_BIST_SHIFT                     (2U)
#define CSL_USB3SSPHY_BIST_EN_HS_BIST_RESETVAL                  (0x00000000U)
#define CSL_USB3SSPHY_BIST_EN_HS_BIST_MAX                       (0x00000001U)

#define CSL_USB3SSPHY_BIST_EN_LS_BIST_MASK                      (0x00000001U)
#define CSL_USB3SSPHY_BIST_EN_LS_BIST_SHIFT                     (0U)
#define CSL_USB3SSPHY_BIST_EN_LS_BIST_RESETVAL                  (0x00000000U)
#define CSL_USB3SSPHY_BIST_EN_LS_BIST_MAX                       (0x00000001U)

#define CSL_USB3SSPHY_BIST_EN_FS_BIST_MASK                      (0x00000002U)
#define CSL_USB3SSPHY_BIST_EN_FS_BIST_SHIFT                     (1U)
#define CSL_USB3SSPHY_BIST_EN_FS_BIST_RESETVAL                  (0x00000000U)
#define CSL_USB3SSPHY_BIST_EN_FS_BIST_MAX                       (0x00000001U)

#define CSL_USB3SSPHY_BIST_EN_BIST_EN_MASK                      (0x00000008U)
#define CSL_USB3SSPHY_BIST_EN_BIST_EN_SHIFT                     (3U)
#define CSL_USB3SSPHY_BIST_EN_BIST_EN_RESETVAL                  (0x00000000U)
#define CSL_USB3SSPHY_BIST_EN_BIST_EN_MAX                       (0x00000001U)

#define CSL_USB3SSPHY_BIST_EN_RESETVAL                          (0x00000000U)

/* BIST_ERROR */

#define CSL_USB3SSPHY_BIST_ERROR_INSERT_BIST_ERR_MASK           (0x00000008U)
#define CSL_USB3SSPHY_BIST_ERROR_INSERT_BIST_ERR_SHIFT          (3U)
#define CSL_USB3SSPHY_BIST_ERROR_INSERT_BIST_ERR_RESETVAL       (0x00000000U)
#define CSL_USB3SSPHY_BIST_ERROR_INSERT_BIST_ERR_MAX            (0x00000001U)

#define CSL_USB3SSPHY_BIST_ERROR_RESETVAL                       (0x00000000U)

/* DISC_COMP */

#define CSL_USB3SSPHY_DISC_COMP_DISABLE_INCR_TUNE_MASK          (0x00000004U)
#define CSL_USB3SSPHY_DISC_COMP_DISABLE_INCR_TUNE_SHIFT         (2U)
#define CSL_USB3SSPHY_DISC_COMP_DISABLE_INCR_TUNE_RESETVAL      (0x00000000U)
#define CSL_USB3SSPHY_DISC_COMP_DISABLE_INCR_TUNE_MAX           (0x00000001U)

#define CSL_USB3SSPHY_DISC_COMP_DISC_COMP_TEST_MODE_MASK        (0x00000002U)
#define CSL_USB3SSPHY_DISC_COMP_DISC_COMP_TEST_MODE_SHIFT       (1U)
#define CSL_USB3SSPHY_DISC_COMP_DISC_COMP_TEST_MODE_RESETVAL    (0x00000000U)
#define CSL_USB3SSPHY_DISC_COMP_DISC_COMP_TEST_MODE_MAX         (0x00000001U)

#define CSL_USB3SSPHY_DISC_COMP_RESETVAL                        (0x00000000U)

/* BIST_MODE */

#define CSL_USB3SSPHY_BIST_MODE_BIST_MODE_MASK                  (0x00000008U)
#define CSL_USB3SSPHY_BIST_MODE_BIST_MODE_SHIFT                 (3U)
#define CSL_USB3SSPHY_BIST_MODE_BIST_MODE_RESETVAL              (0x00000000U)
#define CSL_USB3SSPHY_BIST_MODE_BIST_MODE_MAX                   (0x00000001U)

#define CSL_USB3SSPHY_BIST_MODE_BIST_TEST_PKT_REP_MASK          (0x00000004U)
#define CSL_USB3SSPHY_BIST_MODE_BIST_TEST_PKT_REP_SHIFT         (2U)
#define CSL_USB3SSPHY_BIST_MODE_BIST_TEST_PKT_REP_RESETVAL      (0x00000000U)
#define CSL_USB3SSPHY_BIST_MODE_BIST_TEST_PKT_REP_MAX           (0x00000001U)

#define CSL_USB3SSPHY_BIST_MODE_RESETVAL                        (0x00000000U)

/* TAP */

#define CSL_USB3SSPHY_TAP_TAP_SEL_OVERRIDE_MASK                 (0x00000008U)
#define CSL_USB3SSPHY_TAP_TAP_SEL_OVERRIDE_SHIFT                (3U)
#define CSL_USB3SSPHY_TAP_TAP_SEL_OVERRIDE_RESETVAL             (0x00000000U)
#define CSL_USB3SSPHY_TAP_TAP_SEL_OVERRIDE_MAX                  (0x00000001U)

#define CSL_USB3SSPHY_TAP_TAP_SHIFT_EN_MASK                     (0x00000004U)
#define CSL_USB3SSPHY_TAP_TAP_SHIFT_EN_SHIFT                    (2U)
#define CSL_USB3SSPHY_TAP_TAP_SHIFT_EN_RESETVAL                 (0x00000000U)
#define CSL_USB3SSPHY_TAP_TAP_SHIFT_EN_MAX                      (0x00000001U)

#define CSL_USB3SSPHY_TAP_TAP_SHIFT_DIR_MASK                    (0x00000002U)
#define CSL_USB3SSPHY_TAP_TAP_SHIFT_DIR_SHIFT                   (1U)
#define CSL_USB3SSPHY_TAP_TAP_SHIFT_DIR_RESETVAL                (0x00000000U)
#define CSL_USB3SSPHY_TAP_TAP_SHIFT_DIR_MAX                     (0x00000001U)

#define CSL_USB3SSPHY_TAP_RESETVAL                              (0x00000000U)

/* TEST_IF_RESET */

#define CSL_USB3SSPHY_TEST_IF_RESET_SCALE_DN_EN_MASK            (0x00000004U)
#define CSL_USB3SSPHY_TEST_IF_RESET_SCALE_DN_EN_SHIFT           (2U)
#define CSL_USB3SSPHY_TEST_IF_RESET_SCALE_DN_EN_RESETVAL        (0x00000000U)
#define CSL_USB3SSPHY_TEST_IF_RESET_SCALE_DN_EN_MAX             (0x00000001U)

#define CSL_USB3SSPHY_TEST_IF_RESET_TEST_IF_RESET_MASK          (0x00000001U)
#define CSL_USB3SSPHY_TEST_IF_RESET_TEST_IF_RESET_SHIFT         (0U)
#define CSL_USB3SSPHY_TEST_IF_RESET_TEST_IF_RESET_RESETVAL      (0x00000000U)
#define CSL_USB3SSPHY_TEST_IF_RESET_TEST_IF_RESET_MAX           (0x00000001U)

#define CSL_USB3SSPHY_TEST_IF_RESET_RESETVAL                    (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
