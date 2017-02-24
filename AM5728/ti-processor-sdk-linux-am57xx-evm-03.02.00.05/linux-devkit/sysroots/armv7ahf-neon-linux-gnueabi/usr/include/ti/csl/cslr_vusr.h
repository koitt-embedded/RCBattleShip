/********************************************************************
 * Copyright (C) 2003-2011 Texas Instruments Incorporated.
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
* file: cslr_vusr.h
*
* Brief: This file contains the Register Description for vusr
*
*********************************************************************/
#ifndef _CSLR_VUSR_H_
#define _CSLR_VUSR_H_

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint32 REV;
    volatile Uint32 CTL;
    volatile Uint32 STS;
    volatile Uint32 INT_PRI_VEC;
    volatile Uint32 INT_CLR;
    volatile Uint32 INT_SET;
    volatile Uint32 SW_INT;
    volatile Uint32 TX_SEL_CTL;
    volatile Uint8 RSVD0[12];
    volatile Uint32 RX_SEL_CTL;
    volatile Uint32 RX_PRIV_IDX;
    volatile Uint32 RX_PRIV_VAL;
    volatile Uint32 RX_SEG_IDX;
    volatile Uint32 RX_SEG_VAL;
    volatile Uint32 CHIP_ID_VER;
    volatile Uint32 PWR;
    volatile Uint32 RPC;
    volatile Uint32 ECC_CNTR;
    volatile Uint8 RSVD1[8];
    volatile Uint32 LINK_STS;
    volatile Uint32 SBS;
    volatile Uint32 INT_CTL_IDX;
    volatile Uint32 INT_CTL_VAL;
    volatile Uint32 INT_PTR_IDX;
    volatile Uint32 INT_PTR_VAL;
    volatile Uint32 SERDES_CTL_STS1;
    volatile Uint32 SERDES_CTL_STS2;
    volatile Uint32 SERDES_CTL_STS3;
    volatile Uint32 SERDES_CTL_STS4;
    volatile Uint32 REM_REGS[32];
} CSL_VusrRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* REV */

#define CSL_VUSR_REV_SCHEME_MASK         (0xC0000000u)
#define CSL_VUSR_REV_SCHEME_SHIFT        (0x0000001Eu)
#define CSL_VUSR_REV_SCHEME_RESETVAL     (0x00000001u)

#define CSL_VUSR_REV_BU_MASK             (0x30000000u)
#define CSL_VUSR_REV_BU_SHIFT            (0x0000001Cu)
#define CSL_VUSR_REV_BU_RESETVAL         (0x00000000u)

#define CSL_VUSR_REV_MODID_MASK          (0x0FFF0000u)
#define CSL_VUSR_REV_MODID_SHIFT         (0x00000010u)
#define CSL_VUSR_REV_MODID_RESETVAL      (0x00000E90u)

#define CSL_VUSR_REV_RTL_VER_MASK        (0x0000F800u)
#define CSL_VUSR_REV_RTL_VER_SHIFT       (0x0000000Bu)
#define CSL_VUSR_REV_RTL_VER_RESETVAL    (0x00000000u)

#define CSL_VUSR_REV_REVMAJ_MASK         (0x00000700u)
#define CSL_VUSR_REV_REVMAJ_SHIFT        (0x00000008u)
#define CSL_VUSR_REV_REVMAJ_RESETVAL     (0x00000001u)

#define CSL_VUSR_REV_CUSTOMER_MASK       (0x000000C0u)
#define CSL_VUSR_REV_CUSTOMER_SHIFT      (0x00000006u)
#define CSL_VUSR_REV_CUSTOMER_RESETVAL   (0x00000000u)

#define CSL_VUSR_REV_REVMIN_MASK         (0x0000003Fu)
#define CSL_VUSR_REV_REVMIN_SHIFT        (0x00000000u)
#define CSL_VUSR_REV_REVMIN_RESETVAL     (0x00000001u)

#define CSL_VUSR_REV_RESETVAL            (0x4E900101u)

/* CTL */

#define CSL_VUSR_CTL_INTLOCAL_MASK       (0x00004000u)
#define CSL_VUSR_CTL_INTLOCAL_SHIFT      (0x0000000Eu)
#define CSL_VUSR_CTL_INTLOCAL_RESETVAL   (0x00000000u)

#define CSL_VUSR_CTL_INTENABLE_MASK      (0x00002000u)
#define CSL_VUSR_CTL_INTENABLE_SHIFT     (0x0000000Du)
#define CSL_VUSR_CTL_INTENABLE_RESETVAL  (0x00000000u)

#define CSL_VUSR_CTL_INTVEC_MASK         (0x00001F00u)
#define CSL_VUSR_CTL_INTVEC_SHIFT        (0x00000008u)
#define CSL_VUSR_CTL_INTVEC_RESETVAL     (0x00000000u)

#define CSL_VUSR_CTL_INT2CFG_MASK        (0x00000080u)
#define CSL_VUSR_CTL_INT2CFG_SHIFT       (0x00000007u)
#define CSL_VUSR_CTL_INT2CFG_RESETVAL    (0x00000000u)

#define CSL_VUSR_CTL_DATAARBCYC_MASK     (0x00000070u)
#define CSL_VUSR_CTL_DATAARBCYC_SHIFT    (0x00000004u)
#define CSL_VUSR_CTL_DATAARBCYC_RESETVAL (0x00000000u)

#define CSL_VUSR_CTL_SERIAL_STOP_MASK    (0x00000004u)
#define CSL_VUSR_CTL_SERIAL_STOP_SHIFT   (0x00000002u)
#define CSL_VUSR_CTL_SERIAL_STOP_RESETVAL (0x00000000u)

#define CSL_VUSR_CTL_LOOPBACK_MASK       (0x00000002u)
#define CSL_VUSR_CTL_LOOPBACK_SHIFT      (0x00000001u)
#define CSL_VUSR_CTL_LOOPBACK_RESETVAL   (0x00000000u)

#define CSL_VUSR_CTL_RESET_MASK          (0x00000001u)
#define CSL_VUSR_CTL_RESET_SHIFT         (0x00000000u)
#define CSL_VUSR_CTL_RESET_RESETVAL      (0x00000000u)

#define CSL_VUSR_CTL_RESETVAL            (0x00000000u)

/* STS */

#define CSL_VUSR_STS_SWIDTHIN_MASK       (0x0F000000u)
#define CSL_VUSR_STS_SWIDTHIN_SHIFT      (0x00000018u)
#define CSL_VUSR_STS_SWIDTHIN_RESETVAL   (0x00000000u)

#define CSL_VUSR_STS_SWIDTHOUT_MASK      (0x00F00000u)
#define CSL_VUSR_STS_SWIDTHOUT_SHIFT     (0x00000014u)
#define CSL_VUSR_STS_SWIDTHOUT_RESETVAL  (0x00000000u)

#define CSL_VUSR_STS_PLL_DISABLE_MASK    (0x00004000u)
#define CSL_VUSR_STS_PLL_DISABLE_SHIFT   (0x0000000Eu)
#define CSL_VUSR_STS_PLL_DISABLE_RESETVAL (0x00000000u)

#define CSL_VUSR_STS_SERIAL_HALT_MASK    (0x00002000u)
#define CSL_VUSR_STS_SERIAL_HALT_SHIFT   (0x0000000Du)
#define CSL_VUSR_STS_SERIAL_HALT_RESETVAL (0x00000000u)

#define CSL_VUSR_STS_PLL_UNLOCK_MASK     (0x00001000u)
#define CSL_VUSR_STS_PLL_UNLOCK_SHIFT    (0x0000000Cu)
#define CSL_VUSR_STS_PLL_UNLOCK_RESETVAL (0x00000001u)

#define CSL_VUSR_STS_RPEND_MASK          (0x00000800u)
#define CSL_VUSR_STS_RPEND_SHIFT         (0x0000000Bu)
#define CSL_VUSR_STS_RPEND_RESETVAL      (0x00000000u)

#define CSL_VUSR_STS_IFLOW_MASK          (0x00000400u)
#define CSL_VUSR_STS_IFLOW_SHIFT         (0x0000000Au)
#define CSL_VUSR_STS_IFLOW_RESETVAL      (0x00000000u)

#define CSL_VUSR_STS_OFLOW_MASK          (0x00000200u)
#define CSL_VUSR_STS_OFLOW_SHIFT         (0x00000009u)
#define CSL_VUSR_STS_OFLOW_RESETVAL      (0x00000000u)

#define CSL_VUSR_STS_RERROR_MASK         (0x00000100u)
#define CSL_VUSR_STS_RERROR_SHIFT        (0x00000008u)
#define CSL_VUSR_STS_RERROR_RESETVAL     (0x00000000u)

#define CSL_VUSR_STS_LERROR_MASK         (0x00000080u)
#define CSL_VUSR_STS_LERROR_SHIFT        (0x00000007u)
#define CSL_VUSR_STS_LERROR_RESETVAL     (0x00000000u)

#define CSL_VUSR_STS_NFEMPTY3_MASK       (0x00000040u)
#define CSL_VUSR_STS_NFEMPTY3_SHIFT      (0x00000006u)
#define CSL_VUSR_STS_NFEMPTY3_RESETVAL   (0x00000000u)

#define CSL_VUSR_STS_NFEMPTY2_MASK       (0x00000020u)
#define CSL_VUSR_STS_NFEMPTY2_SHIFT      (0x00000005u)
#define CSL_VUSR_STS_NFEMPTY2_RESETVAL   (0x00000000u)

#define CSL_VUSR_STS_NFEMPTY1_MASK       (0x00000010u)
#define CSL_VUSR_STS_NFEMPTY1_SHIFT      (0x00000004u)
#define CSL_VUSR_STS_NFEMPTY1_RESETVAL   (0x00000000u)

#define CSL_VUSR_STS_NFEMPTY0_MASK       (0x00000008u)
#define CSL_VUSR_STS_NFEMPTY0_SHIFT      (0x00000003u)
#define CSL_VUSR_STS_NFEMPTY0_RESETVAL   (0x00000000u)

#define CSL_VUSR_STS_SPEND_MASK          (0x00000004u)
#define CSL_VUSR_STS_SPEND_SHIFT         (0x00000002u)
#define CSL_VUSR_STS_SPEND_RESETVAL      (0x00000000u)

#define CSL_VUSR_STS_MPEND_MASK          (0x00000002u)
#define CSL_VUSR_STS_MPEND_SHIFT         (0x00000001u)
#define CSL_VUSR_STS_MPEND_RESETVAL      (0x00000000u)

#define CSL_VUSR_STS_LINK_MASK           (0x00000001u)
#define CSL_VUSR_STS_LINK_SHIFT          (0x00000000u)
#define CSL_VUSR_STS_LINK_RESETVAL       (0x00000000u)

#define CSL_VUSR_STS_RESETVAL            (0x00001000u)

/* INT_PRI_VEC */

#define CSL_VUSR_INT_PRI_VEC_NOINTPEND_MASK (0x80000000u)
#define CSL_VUSR_INT_PRI_VEC_NOINTPEND_SHIFT (0x0000001Fu)
#define CSL_VUSR_INT_PRI_VEC_NOINTPEND_RESETVAL (0x00000001u)

#define CSL_VUSR_INT_PRI_VEC_INTSTAT_MASK (0x0000001Fu)
#define CSL_VUSR_INT_PRI_VEC_INTSTAT_SHIFT (0x00000000u)
#define CSL_VUSR_INT_PRI_VEC_INTSTAT_RESETVAL (0x00000000u)

#define CSL_VUSR_INT_PRI_VEC_RESETVAL    (0x80000000u)

/* INT_CLR */

#define CSL_VUSR_INT_CLR_INTCLR_MASK     (0xFFFFFFFFu)
#define CSL_VUSR_INT_CLR_INTCLR_SHIFT    (0x00000000u)
#define CSL_VUSR_INT_CLR_INTCLR_RESETVAL (0x00000000u)

#define CSL_VUSR_INT_CLR_RESETVAL        (0x00000000u)

/* INT_SET */

#define CSL_VUSR_INT_SET_INTSET_MASK     (0xFFFFFFFFu)
#define CSL_VUSR_INT_SET_INTSET_SHIFT    (0x00000000u)
#define CSL_VUSR_INT_SET_INTSET_RESETVAL (0x00000000u)

#define CSL_VUSR_INT_SET_RESETVAL        (0x00000000u)

/* SW_INT */

#define CSL_VUSR_SW_INT_EOI_FLAG_MASK    (0x0000FF00u)
#define CSL_VUSR_SW_INT_EOI_FLAG_SHIFT   (0x00000008u)
#define CSL_VUSR_SW_INT_EOI_FLAG_RESETVAL (0x00000000u)

#define CSL_VUSR_SW_INT_IVECTOR_MASK     (0x000000FFu)
#define CSL_VUSR_SW_INT_IVECTOR_SHIFT    (0x00000000u)
#define CSL_VUSR_SW_INT_IVECTOR_RESETVAL (0x00000000u)

#define CSL_VUSR_SW_INT_RESETVAL         (0x00000000u)

/* TX_SEL_CTL */

#define CSL_VUSR_TX_SEL_CTL_TXSECOVL_MASK (0x000F0000u)
#define CSL_VUSR_TX_SEL_CTL_TXSECOVL_SHIFT (0x00000010u)
#define CSL_VUSR_TX_SEL_CTL_TXSECOVL_RESETVAL (0x00000000u)

#define CSL_VUSR_TX_SEL_CTL_TXPRIVIDOVL_MASK (0x00000F00u)
#define CSL_VUSR_TX_SEL_CTL_TXPRIVIDOVL_SHIFT (0x00000008u)
#define CSL_VUSR_TX_SEL_CTL_TXPRIVIDOVL_RESETVAL (0x00000000u)

#define CSL_VUSR_TX_SEL_CTL_TXIGNMSK_MASK (0x0000000Fu)
#define CSL_VUSR_TX_SEL_CTL_TXIGNMSK_SHIFT (0x00000000u)
#define CSL_VUSR_TX_SEL_CTL_TXIGNMSK_RESETVAL (0x00000000u)

#define CSL_VUSR_TX_SEL_CTL_RESETVAL     (0x00000000u)

/* RX_SEL_CTL */

#define CSL_VUSR_RX_SEL_CTL_RXSECHI_MASK (0x02000000u)
#define CSL_VUSR_RX_SEL_CTL_RXSECHI_SHIFT (0x00000019u)
#define CSL_VUSR_RX_SEL_CTL_RXSECHI_RESETVAL (0x00000000u)

#define CSL_VUSR_RX_SEL_CTL_RXSECLO_MASK (0x01000000u)
#define CSL_VUSR_RX_SEL_CTL_RXSECLO_SHIFT (0x00000018u)
#define CSL_VUSR_RX_SEL_CTL_RXSECLO_RESETVAL (0x00000000u)

#define CSL_VUSR_RX_SEL_CTL_RXSECSEL_MASK (0x000F0000u)
#define CSL_VUSR_RX_SEL_CTL_RXSECSEL_SHIFT (0x00000010u)
#define CSL_VUSR_RX_SEL_CTL_RXSECSEL_RESETVAL (0x00000000u)

#define CSL_VUSR_RX_SEL_CTL_RXPRIVIDSEL_MASK (0x00000F00u)
#define CSL_VUSR_RX_SEL_CTL_RXPRIVIDSEL_SHIFT (0x00000008u)
#define CSL_VUSR_RX_SEL_CTL_RXPRIVIDSEL_RESETVAL (0x00000000u)

#define CSL_VUSR_RX_SEL_CTL_RXSEGSEL_MASK (0x0000000Fu)
#define CSL_VUSR_RX_SEL_CTL_RXSEGSEL_SHIFT (0x00000000u)
#define CSL_VUSR_RX_SEL_CTL_RXSEGSEL_RESETVAL (0x00000000u)

#define CSL_VUSR_RX_SEL_CTL_RESETVAL     (0x00000000u)

/* RX_PRIV_IDX */

#define CSL_VUSR_RX_PRIV_IDX_RXPRIVID_IDX_MASK (0x0000000Fu)
#define CSL_VUSR_RX_PRIV_IDX_RXPRIVID_IDX_SHIFT (0x00000000u)
#define CSL_VUSR_RX_PRIV_IDX_RXPRIVID_IDX_RESETVAL (0x00000000u)

#define CSL_VUSR_RX_PRIV_IDX_RESETVAL    (0x00000000u)

/* RX_PRIV_VAL */

#define CSL_VUSR_RX_PRIV_VAL_RXPRIVID_VAL_MASK (0x0000000Fu)
#define CSL_VUSR_RX_PRIV_VAL_RXPRIVID_VAL_SHIFT (0x00000000u)
#define CSL_VUSR_RX_PRIV_VAL_RXPRIVID_VAL_RESETVAL (0x00000000u)

#define CSL_VUSR_RX_PRIV_VAL_RESETVAL    (0x00000000u)

/* RX_SEG_IDX */

#define CSL_VUSR_RX_SEG_IDX_RXSEG_IDX_MASK (0x0000003Fu)
#define CSL_VUSR_RX_SEG_IDX_RXSEG_IDX_SHIFT (0x00000000u)
#define CSL_VUSR_RX_SEG_IDX_RXSEG_IDX_RESETVAL (0x00000000u)

#define CSL_VUSR_RX_SEG_IDX_RESETVAL     (0x00000000u)

/* RX_SEG_VAL */

#define CSL_VUSR_RX_SEG_VAL_RXSEG_VAL_MASK (0xFFFF0000u)
#define CSL_VUSR_RX_SEG_VAL_RXSEG_VAL_SHIFT (0x00000010u)
#define CSL_VUSR_RX_SEG_VAL_RXSEG_VAL_RESETVAL (0x00000000u)

#define CSL_VUSR_RX_SEG_VAL_RXLEN_VAL_MASK (0x0000001Fu)
#define CSL_VUSR_RX_SEG_VAL_RXLEN_VAL_SHIFT (0x00000000u)
#define CSL_VUSR_RX_SEG_VAL_RXLEN_VAL_RESETVAL (0x00000000u)

#define CSL_VUSR_RX_SEG_VAL_RESETVAL     (0x00000000u)

/* CHIP_ID_VER */

#define CSL_VUSR_CHIP_ID_VER_DEVREV_MASK (0xFFFF0000u)
#define CSL_VUSR_CHIP_ID_VER_DEVREV_SHIFT (0x00000010u)
#define CSL_VUSR_CHIP_ID_VER_DEVREV_RESETVAL (0x00000000u)

#define CSL_VUSR_CHIP_ID_VER_DEVID_MASK  (0x0000FFFFu)
#define CSL_VUSR_CHIP_ID_VER_DEVID_SHIFT (0x00000000u)
#define CSL_VUSR_CHIP_ID_VER_DEVID_RESETVAL (0x00000000u)

#define CSL_VUSR_CHIP_ID_VER_RESETVAL    (0x00000000u)

/* PWR */

#define CSL_VUSR_PWR_H2L_MASK            (0x07000000u)
#define CSL_VUSR_PWR_H2L_SHIFT           (0x00000018u)
#define CSL_VUSR_PWR_H2L_RESETVAL        (0x00000007u)

#define CSL_VUSR_PWR_L2H_MASK            (0x00070000u)
#define CSL_VUSR_PWR_L2H_SHIFT           (0x00000010u)
#define CSL_VUSR_PWR_L2H_RESETVAL        (0x00000007u)

#define CSL_VUSR_PWR_PWC_MASK            (0x0000FF00u)
#define CSL_VUSR_PWR_PWC_SHIFT           (0x00000008u)
#define CSL_VUSR_PWR_PWC_RESETVAL        (0x00000000u)

#define CSL_VUSR_PWR_HIGHSPEED_MASK      (0x00000008u)
#define CSL_VUSR_PWR_HIGHSPEED_SHIFT     (0x00000003u)
#define CSL_VUSR_PWR_HIGHSPEED_RESETVAL  (0x00000000u)

#define CSL_VUSR_PWR_QUADLANE_MASK       (0x00000004u)
#define CSL_VUSR_PWR_QUADLANE_SHIFT      (0x00000002u)
#define CSL_VUSR_PWR_QUADLANE_RESETVAL   (0x00000001u)

#define CSL_VUSR_PWR_SINGLELANE_MASK     (0x00000002u)
#define CSL_VUSR_PWR_SINGLELANE_SHIFT    (0x00000001u)
#define CSL_VUSR_PWR_SINGLELANE_RESETVAL (0x00000001u)

#define CSL_VUSR_PWR_ZEROLANE_MASK       (0x00000001u)
#define CSL_VUSR_PWR_ZEROLANE_SHIFT      (0x00000000u)
#define CSL_VUSR_PWR_ZEROLANE_RESETVAL   (0x00000001u)

#define CSL_VUSR_PWR_RESETVAL            (0x07070007u)

/* RPC */

#define CSL_VUSR_RPC_TRAN0PRI_MASK       (0x70000000u)
#define CSL_VUSR_RPC_TRAN0PRI_SHIFT      (0x0000001Cu)
#define CSL_VUSR_RPC_TRAN0PRI_RESETVAL   (0x00000000u)

#define CSL_VUSR_RPC_TRAN1PRI_MASK       (0x07000000u)
#define CSL_VUSR_RPC_TRAN1PRI_SHIFT      (0x00000018u)
#define CSL_VUSR_RPC_TRAN1PRI_RESETVAL   (0x00000004u)

#define CSL_VUSR_RPC_TRAN0EPRI_MASK      (0x00007000u)
#define CSL_VUSR_RPC_TRAN0EPRI_SHIFT     (0x0000000Cu)
#define CSL_VUSR_RPC_TRAN0EPRI_RESETVAL  (0x00000000u)

#define CSL_VUSR_RPC_TRAN1EPRI_MASK      (0x00000700u)
#define CSL_VUSR_RPC_TRAN1EPRI_SHIFT     (0x00000008u)
#define CSL_VUSR_RPC_TRAN1EPRI_RESETVAL  (0x00000004u)

#define CSL_VUSR_RPC_RESETVAL            (0x04000400u)

/* ECC_CNTR */

#define CSL_VUSR_ECC_CNTR_SGL_ERR_COR_MASK (0xFFFF0000u)
#define CSL_VUSR_ECC_CNTR_SGL_ERR_COR_SHIFT (0x00000010u)
#define CSL_VUSR_ECC_CNTR_SGL_ERR_COR_RESETVAL (0x00000000u)

#define CSL_VUSR_ECC_CNTR_DBL_ERR_DET_MASK (0x000000FFu)
#define CSL_VUSR_ECC_CNTR_DBL_ERR_DET_SHIFT (0x00000000u)
#define CSL_VUSR_ECC_CNTR_DBL_ERR_DET_RESETVAL (0x00000000u)

#define CSL_VUSR_ECC_CNTR_RESETVAL       (0x00000000u)

/* LINK_STS */

#define CSL_VUSR_LINK_STS_TXPLS_REQ_MASK (0xC0000000u)
#define CSL_VUSR_LINK_STS_TXPLS_REQ_SHIFT (0x0000001Eu)
#define CSL_VUSR_LINK_STS_TXPLS_REQ_RESETVAL (0x00000000u)

#define CSL_VUSR_LINK_STS_TXPLS_ACK_MASK (0x30000000u)
#define CSL_VUSR_LINK_STS_TXPLS_ACK_SHIFT (0x0000001Cu)
#define CSL_VUSR_LINK_STS_TXPLS_ACK_RESETVAL (0x00000000u)

#define CSL_VUSR_LINK_STS_TXPM_REQ_MASK  (0x0C000000u)
#define CSL_VUSR_LINK_STS_TXPM_REQ_SHIFT (0x0000001Au)
#define CSL_VUSR_LINK_STS_TXPM_REQ_RESETVAL (0x00000000u)

#define CSL_VUSR_LINK_STS_TX_RSYNC_MASK  (0x02000000u)
#define CSL_VUSR_LINK_STS_TX_RSYNC_SHIFT (0x00000019u)
#define CSL_VUSR_LINK_STS_TX_RSYNC_RESETVAL (0x00000000u)

#define CSL_VUSR_LINK_STS_TXPLSOK_MASK   (0x01000000u)
#define CSL_VUSR_LINK_STS_TXPLSOK_SHIFT  (0x00000018u)
#define CSL_VUSR_LINK_STS_TXPLSOK_RESETVAL (0x00000000u)

#define CSL_VUSR_LINK_STS_TX_PHY_EN_MASK (0x00F00000u)
#define CSL_VUSR_LINK_STS_TX_PHY_EN_SHIFT (0x00000014u)
#define CSL_VUSR_LINK_STS_TX_PHY_EN_RESETVAL (0x00000000u)

#define CSL_VUSR_LINK_STS_TXFLOW_STS_MASK (0x000F0000u)
#define CSL_VUSR_LINK_STS_TXFLOW_STS_SHIFT (0x00000010u)
#define CSL_VUSR_LINK_STS_TXFLOW_STS_RESETVAL (0x00000000u)

#define CSL_VUSR_LINK_STS_RXPLS_REQ_MASK (0x0000C000u)
#define CSL_VUSR_LINK_STS_RXPLS_REQ_SHIFT (0x0000000Eu)
#define CSL_VUSR_LINK_STS_RXPLS_REQ_RESETVAL (0x00000000u)

#define CSL_VUSR_LINK_STS_RXPLS_ACK_MASK (0x00003000u)
#define CSL_VUSR_LINK_STS_RXPLS_ACK_SHIFT (0x0000000Cu)
#define CSL_VUSR_LINK_STS_RXPLS_ACK_RESETVAL (0x00000000u)

#define CSL_VUSR_LINK_STS_RXPM_REQ_MASK  (0x00000C00u)
#define CSL_VUSR_LINK_STS_RXPM_REQ_SHIFT (0x0000000Au)
#define CSL_VUSR_LINK_STS_RXPM_REQ_RESETVAL (0x00000000u)

#define CSL_VUSR_LINK_STS_RX_LSYNC_MASK  (0x00000200u)
#define CSL_VUSR_LINK_STS_RX_LSYNC_SHIFT (0x00000009u)
#define CSL_VUSR_LINK_STS_RX_LSYNC_RESETVAL (0x00000000u)

#define CSL_VUSR_LINK_STS_RX_ONE_ID_MASK (0x00000100u)
#define CSL_VUSR_LINK_STS_RX_ONE_ID_SHIFT (0x00000008u)
#define CSL_VUSR_LINK_STS_RX_ONE_ID_RESETVAL (0x00000000u)

#define CSL_VUSR_LINK_STS_RX_PHY_EN_MASK (0x000000F0u)
#define CSL_VUSR_LINK_STS_RX_PHY_EN_SHIFT (0x00000004u)
#define CSL_VUSR_LINK_STS_RX_PHY_EN_RESETVAL (0x00000000u)

#define CSL_VUSR_LINK_STS_RX_PHY_POL_MASK (0x0000000Fu)
#define CSL_VUSR_LINK_STS_RX_PHY_POL_SHIFT (0x00000000u)
#define CSL_VUSR_LINK_STS_RX_PHY_POL_RESETVAL (0x00000000u)

#define CSL_VUSR_LINK_STS_RESETVAL       (0x00000000u)

/* SBS */

#define CSL_VUSR_SBS_TXFL_FLAGS_SEL_MASK (0xFF000000u)
#define CSL_VUSR_SBS_TXFL_FLAGS_SEL_SHIFT (0x00000018u)
#define CSL_VUSR_SBS_TXFL_FLAGS_SEL_RESETVAL (0x00000000u)

#define CSL_VUSR_SBS_TXFL_FLAGS_CAP_MASK (0x00F00000u)
#define CSL_VUSR_SBS_TXFL_FLAGS_CAP_SHIFT (0x00000014u)
#define CSL_VUSR_SBS_TXFL_FLAGS_CAP_RESETVAL (0x00000000u)

#define CSL_VUSR_SBS_TXFL_FLAGS_STS_MASK (0x000F0000u)
#define CSL_VUSR_SBS_TXFL_FLAGS_STS_SHIFT (0x00000010u)
#define CSL_VUSR_SBS_TXFL_FLAGS_STS_RESETVAL (0x00000000u)

#define CSL_VUSR_SBS_RXPM_FLAGS_SEL_MASK (0x0000FF00u)
#define CSL_VUSR_SBS_RXPM_FLAGS_SEL_SHIFT (0x00000008u)
#define CSL_VUSR_SBS_RXPM_FLAGS_SEL_RESETVAL (0x00000000u)

#define CSL_VUSR_SBS_RXPM_FLAGS_CAP_MASK (0x000000F0u)
#define CSL_VUSR_SBS_RXPM_FLAGS_CAP_SHIFT (0x00000004u)
#define CSL_VUSR_SBS_RXPM_FLAGS_CAP_RESETVAL (0x00000000u)

#define CSL_VUSR_SBS_RXPM_FLAGS_STS_MASK (0x0000000Fu)
#define CSL_VUSR_SBS_RXPM_FLAGS_STS_SHIFT (0x00000000u)
#define CSL_VUSR_SBS_RXPM_FLAGS_STS_RESETVAL (0x00000000u)

#define CSL_VUSR_SBS_RESETVAL            (0x00000000u)

/* INT_CTL_IDX */

#define CSL_VUSR_INT_CTL_IDX_ICIDX_MASK  (0x000000FFu)
#define CSL_VUSR_INT_CTL_IDX_ICIDX_SHIFT (0x00000000u)
#define CSL_VUSR_INT_CTL_IDX_ICIDX_RESETVAL (0x00000000u)

#define CSL_VUSR_INT_CTL_IDX_RESETVAL    (0x00000000u)

/* INT_CTL_VAL */

#define CSL_VUSR_INT_CTL_VAL_INTEN_MASK  (0x80000000u)
#define CSL_VUSR_INT_CTL_VAL_INTEN_SHIFT (0x0000001Fu)
#define CSL_VUSR_INT_CTL_VAL_INTEN_RESETVAL (0x00000000u)

#define CSL_VUSR_INT_CTL_VAL_INTTYPE_MASK (0x40000000u)
#define CSL_VUSR_INT_CTL_VAL_INTTYPE_SHIFT (0x0000001Eu)
#define CSL_VUSR_INT_CTL_VAL_INTTYPE_RESETVAL (0x00000000u)

#define CSL_VUSR_INT_CTL_VAL_INTPOL_MASK (0x20000000u)
#define CSL_VUSR_INT_CTL_VAL_INTPOL_SHIFT (0x0000001Du)
#define CSL_VUSR_INT_CTL_VAL_INTPOL_RESETVAL (0x00000000u)

#define CSL_VUSR_INT_CTL_VAL_ISEC_MASK   (0x10000000u)
#define CSL_VUSR_INT_CTL_VAL_ISEC_SHIFT  (0x0000001Cu)
#define CSL_VUSR_INT_CTL_VAL_ISEC_RESETVAL (0x00000000u)

#define CSL_VUSR_INT_CTL_VAL_SIEN_MASK   (0x08000000u)
#define CSL_VUSR_INT_CTL_VAL_SIEN_SHIFT  (0x0000001Bu)
#define CSL_VUSR_INT_CTL_VAL_SIEN_RESETVAL (0x00000000u)

#define CSL_VUSR_INT_CTL_VAL_DNID_MASK   (0x00030000u)
#define CSL_VUSR_INT_CTL_VAL_DNID_SHIFT  (0x00000010u)
#define CSL_VUSR_INT_CTL_VAL_DNID_RESETVAL (0x00000000u)

#define CSL_VUSR_INT_CTL_VAL_MPS_MASK    (0x00000F00u)
#define CSL_VUSR_INT_CTL_VAL_MPS_SHIFT   (0x00000008u)
#define CSL_VUSR_INT_CTL_VAL_MPS_RESETVAL (0x00000000u)

#define CSL_VUSR_INT_CTL_VAL_VECTOR_MASK (0x0000001Fu)
#define CSL_VUSR_INT_CTL_VAL_VECTOR_SHIFT (0x00000000u)
#define CSL_VUSR_INT_CTL_VAL_VECTOR_RESETVAL (0x00000000u)

#define CSL_VUSR_INT_CTL_VAL_RESETVAL    (0x00000000u)

/* INT_PTR_IDX */

#define CSL_VUSR_INT_PTR_IDX_IPIDX_MASK  (0x0000000Fu)
#define CSL_VUSR_INT_PTR_IDX_IPIDX_SHIFT (0x00000000u)
#define CSL_VUSR_INT_PTR_IDX_IPIDX_RESETVAL (0x00000000u)

#define CSL_VUSR_INT_PTR_IDX_RESETVAL    (0x00000000u)

/* INT_PTR_VAL */

#define CSL_VUSR_INT_PTR_VAL_INTPTR_MASK (0xFFFFFFFCu)
#define CSL_VUSR_INT_PTR_VAL_INTPTR_SHIFT (0x00000002u)
#define CSL_VUSR_INT_PTR_VAL_INTPTR_RESETVAL (0x00000000u)

#define CSL_VUSR_INT_PTR_VAL_RESETVAL    (0x00000000u)

/* SERDES_CTL_STS1 */

#define CSL_VUSR_SERDES_CTL_STS1_SLEEP_CNT_MASK (0xFF000000u)
#define CSL_VUSR_SERDES_CTL_STS1_SLEEP_CNT_SHIFT (0x00000018u)
#define CSL_VUSR_SERDES_CTL_STS1_SLEEP_CNT_RESETVAL (0x00000009u)

#define CSL_VUSR_SERDES_CTL_STS1_DISABLE_CNT_MASK (0x00FF0000u)
#define CSL_VUSR_SERDES_CTL_STS1_DISABLE_CNT_SHIFT (0x00000010u)
#define CSL_VUSR_SERDES_CTL_STS1_DISABLE_CNT_RESETVAL (0x0000002Eu)

#define CSL_VUSR_SERDES_CTL_STS1_RESETVAL (0x092E0000u)

/* SERDES_CTL_STS2 */

#define CSL_VUSR_SERDES_CTL_STS2_S2CTL_MASK (0xFFFF0000u)
#define CSL_VUSR_SERDES_CTL_STS2_S2CTL_SHIFT (0x00000010u)
#define CSL_VUSR_SERDES_CTL_STS2_S2CTL_RESETVAL (0x00000000u)

#define CSL_VUSR_SERDES_CTL_STS2_RESETVAL (0x00000000u)

/* SERDES_CTL_STS3 */

#define CSL_VUSR_SERDES_CTL_STS3_S3CTL_MASK (0xFFFF0000u)
#define CSL_VUSR_SERDES_CTL_STS3_S3CTL_SHIFT (0x00000010u)
#define CSL_VUSR_SERDES_CTL_STS3_S3CTL_RESETVAL (0x00000000u)

#define CSL_VUSR_SERDES_CTL_STS3_RESETVAL (0x00000000u)

/* SERDES_CTL_STS4 */

#define CSL_VUSR_SERDES_CTL_STS4_DVQUICK_MASK (0x80000000u)
#define CSL_VUSR_SERDES_CTL_STS4_DVQUICK_SHIFT (0x0000001Fu)
#define CSL_VUSR_SERDES_CTL_STS4_DVQUICK_RESETVAL (0x00000000u)

#define CSL_VUSR_SERDES_CTL_STS4_S4CTL_MASK (0x7FF00000u)
#define CSL_VUSR_SERDES_CTL_STS4_S4CTL_SHIFT (0x00000014u)
#define CSL_VUSR_SERDES_CTL_STS4_S4CTL_RESETVAL (0x00000000u)

#define CSL_VUSR_SERDES_CTL_STS4_TX_SPC_MASK (0x000C0000u)
#define CSL_VUSR_SERDES_CTL_STS4_TX_SPC_SHIFT (0x00000012u)
#define CSL_VUSR_SERDES_CTL_STS4_TX_SPC_RESETVAL (0x00000000u)

#define CSL_VUSR_SERDES_CTL_STS4_RX_SPC_MASK (0x00030000u)
#define CSL_VUSR_SERDES_CTL_STS4_RX_SPC_SHIFT (0x00000010u)
#define CSL_VUSR_SERDES_CTL_STS4_RX_SPC_RESETVAL (0x00000000u)

#define CSL_VUSR_SERDES_CTL_STS4_RESETVAL (0x00000000u)

/* REM_REGS */

#define CSL_VUSR_REM_REGS_REMOTE_REGISTERS_MASK (0xFFFFFFFFu)
#define CSL_VUSR_REM_REGS_REMOTE_REGISTERS_SHIFT (0x00000000u)
#define CSL_VUSR_REM_REGS_REMOTE_REGISTERS_RESETVAL (0x00000000u)

#define CSL_VUSR_REM_REGS_RESETVAL       (0x00000000u)

#endif
