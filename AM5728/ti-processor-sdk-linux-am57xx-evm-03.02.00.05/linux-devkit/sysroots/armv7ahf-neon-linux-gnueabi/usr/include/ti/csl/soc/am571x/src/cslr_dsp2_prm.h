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
#ifndef CSLR_DSP2_PRM_H
#define CSLR_DSP2_PRM_H

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for __ALL__
**************************************************************************/
typedef struct {
    volatile Uint32 PM_DSP2_PWRSTCTRL_REG;
    volatile Uint32 PM_DSP2_PWRSTST_REG;
    volatile Uint8  RSVD0[8];
    volatile Uint32 RM_DSP2_RSTCTRL_REG;
    volatile Uint32 RM_DSP2_RSTST_REG;
    volatile Uint8  RSVD1[12];
    volatile Uint32 RM_DSP2_DSP2_CONTEXT_REG;
} CSL_dsp2_prmRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* This register controls the DSP power state to reach upon a domain sleep 
 * transition */
#define CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG                      (0x0U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTCTRL        (CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG)


/* This register provides a status on the DSP domain current power state. 
 * [warm reset insensitive] */
#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG                        (0x4U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST          (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG)


/* This register controls the release of the DSP sub-system resets. */
#define CSL_DSP2_PRM_RM_DSP2_RSTCTRL_REG                        (0x10U)
/* Below define for backward compatibility */
#define RM_DSP2_RSTCTRL          (CSL_DSP2_PRM_RM_DSP2_RSTCTRL_REG)


/* This register logs the different reset sources of the DSP domain. Each bit 
 * is set upon release of the domain reset signal. Must be cleared by 
 * software. [warm reset insensitive] */
#define CSL_DSP2_PRM_RM_DSP2_RSTST_REG                          (0x14U)
/* Below define for backward compatibility */
#define RM_DSP2_RSTST            (CSL_DSP2_PRM_RM_DSP2_RSTST_REG)


/* This register contains dedicated DSP context statuses. [warm reset 
 * insensitive] */
#define CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG                   (0x24U)
/* Below define for backward compatibility */
#define RM_DSP2_DSP2_CONTEXT     (CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG)



/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* PM_DSP2_PWRSTCTRL_REG */

#define CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_DSP2_L1_ONSTATE_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTCTRL_DSP2_L1_ONSTATE_MASK        (CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_DSP2_L1_ONSTATE_MASK)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_DSP2_L1_ONSTATE_RESETVAL  (0x00000003U)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_DSP2_L1_ONSTATE_SHIFT  (16U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTCTRL_DSP2_L1_ONSTATE_SHIFT       (CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_DSP2_L1_ONSTATE_SHIFT)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_DSP2_L1_ONSTATE_MEM_ON  (0x00000003U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTCTRL_DSP2_L1_ONSTATE_MEM_ON      (CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_DSP2_L1_ONSTATE_MEM_ON)


#define CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_POWERSTATE_MASK      (0x00000003U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTCTRL_POWERSTATE_MASK             (CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_POWERSTATE_MASK)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_POWERSTATE_RESETVAL  (0x00000003U)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_POWERSTATE_SHIFT     (0U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTCTRL_POWERSTATE_SHIFT            (CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_POWERSTATE_SHIFT)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_POWERSTATE_OFF       (0x00000000U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTCTRL_POWERSTATE_OFF              (CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_POWERSTATE_OFF)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_POWERSTATE_INACT     (0x00000002U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTCTRL_POWERSTATE_INACT            (CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_POWERSTATE_INACT)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_POWERSTATE_RET       (0x00000001U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTCTRL_POWERSTATE_RET              (CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_POWERSTATE_RET)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_POWERSTATE_ON        (0x00000003U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTCTRL_POWERSTATE_ON               (CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_POWERSTATE_ON)


#define CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_DSP2_L2_ONSTATE_MASK  (0x000C0000U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTCTRL_DSP2_L2_ONSTATE_MASK        (CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_DSP2_L2_ONSTATE_MASK)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_DSP2_L2_ONSTATE_RESETVAL  (0x00000003U)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_DSP2_L2_ONSTATE_SHIFT  (18U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTCTRL_DSP2_L2_ONSTATE_SHIFT       (CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_DSP2_L2_ONSTATE_SHIFT)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_DSP2_L2_ONSTATE_MEM_ON  (0x00000003U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTCTRL_DSP2_L2_ONSTATE_MEM_ON      (CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_DSP2_L2_ONSTATE_MEM_ON)


#define CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_DSP2_EDMA_ONSTATE_MASK  (0x00300000U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTCTRL_DSP2_EDMA_ONSTATE_MASK      (CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_DSP2_EDMA_ONSTATE_MASK)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_DSP2_EDMA_ONSTATE_RESETVAL  (0x00000003U)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_DSP2_EDMA_ONSTATE_SHIFT  (20U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTCTRL_DSP2_EDMA_ONSTATE_SHIFT     (CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_DSP2_EDMA_ONSTATE_SHIFT)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_DSP2_EDMA_ONSTATE_MEM_ON  (0x00000003U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTCTRL_DSP2_EDMA_ONSTATE_MEM_ON    (CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_DSP2_EDMA_ONSTATE_MEM_ON)


#define CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_LOWPOWERSTATECHANGE_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTCTRL_LOWPOWERSTATECHANGE_MASK    (CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_LOWPOWERSTATECHANGE_MASK)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_LOWPOWERSTATECHANGE_RESETVAL  (0x00000000U)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_LOWPOWERSTATECHANGE_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTCTRL_LOWPOWERSTATECHANGE_SHIFT   (CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_LOWPOWERSTATECHANGE_SHIFT)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_LOWPOWERSTATECHANGE_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTCTRL_LOWPOWERSTATECHANGE_EN      (CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_LOWPOWERSTATECHANGE_EN)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_LOWPOWERSTATECHANGE_DIS  (0x00000000U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTCTRL_LOWPOWERSTATECHANGE_DIS     (CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_LOWPOWERSTATECHANGE_DIS)


#define CSL_DSP2_PRM_PM_DSP2_PWRSTCTRL_REG_RESETVAL             (0x003f0003U)

/* PM_DSP2_PWRSTST_REG */

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_POWERSTATEST_MASK      (0x00000003U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_POWERSTATEST_MASK             (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_POWERSTATEST_MASK)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_POWERSTATEST_RESETVAL  (0x00000003U)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_POWERSTATEST_SHIFT     (0U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_POWERSTATEST_SHIFT            (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_POWERSTATEST_SHIFT)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_POWERSTATEST_ON        (0x00000003U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_POWERSTATEST_ON               (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_POWERSTATEST_ON)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_POWERSTATEST_OFF       (0x00000000U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_POWERSTATEST_OFF              (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_POWERSTATEST_OFF)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_POWERSTATEST_RET       (0x00000001U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_POWERSTATEST_RET              (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_POWERSTATEST_RET)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_POWERSTATEST_INACTIVE  (0x00000002U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_POWERSTATEST_INACTIVE         (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_POWERSTATEST_INACTIVE)


#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_INTRANSITION_MASK      (0x00100000U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_INTRANSITION_MASK             (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_INTRANSITION_MASK)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_INTRANSITION_RESETVAL  (0x00000000U)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_INTRANSITION_SHIFT     (20U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_INTRANSITION_SHIFT            (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_INTRANSITION_SHIFT)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_INTRANSITION_NO        (0x00000000U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_INTRANSITION_NO               (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_INTRANSITION_NO)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_INTRANSITION_ONGOING   (0x00000001U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_INTRANSITION_ONGOING          (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_INTRANSITION_ONGOING)


#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_LOGICSTATEST_MASK      (0x00000004U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_LOGICSTATEST_MASK             (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_LOGICSTATEST_MASK)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_LOGICSTATEST_RESETVAL  (0x00000001U)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_LOGICSTATEST_SHIFT     (2U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_LOGICSTATEST_SHIFT            (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_LOGICSTATEST_SHIFT)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_LOGICSTATEST_ON        (0x00000001U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_LOGICSTATEST_ON               (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_LOGICSTATEST_ON)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_LOGICSTATEST_OFF       (0x00000000U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_LOGICSTATEST_OFF              (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_LOGICSTATEST_OFF)


#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_L1_STATEST_MASK   (0x00000030U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_DSP2_L1_STATEST_MASK          (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_L1_STATEST_MASK)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_L1_STATEST_RESETVAL  (0x00000003U)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_L1_STATEST_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_DSP2_L1_STATEST_SHIFT         (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_L1_STATEST_SHIFT)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_L1_STATEST_MEM_ON  (0x00000003U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_DSP2_L1_STATEST_MEM_ON        (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_L1_STATEST_MEM_ON)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_L1_STATEST_MEM_RET  (0x00000001U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_DSP2_L1_STATEST_MEM_RET       (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_L1_STATEST_MEM_RET)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_L1_STATEST_MEM_OFF  (0x00000000U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_DSP2_L1_STATEST_MEM_OFF       (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_L1_STATEST_MEM_OFF)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_L1_STATEST_RESERVED  (0x00000002U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_DSP2_L1_STATEST_RESERVED      (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_L1_STATEST_RESERVED)


#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_L2_STATEST_MASK   (0x000000C0U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_DSP2_L2_STATEST_MASK          (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_L2_STATEST_MASK)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_L2_STATEST_RESETVAL  (0x00000003U)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_L2_STATEST_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_DSP2_L2_STATEST_SHIFT         (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_L2_STATEST_SHIFT)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_L2_STATEST_MEM_ON  (0x00000003U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_DSP2_L2_STATEST_MEM_ON        (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_L2_STATEST_MEM_ON)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_L2_STATEST_MEM_RET  (0x00000001U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_DSP2_L2_STATEST_MEM_RET       (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_L2_STATEST_MEM_RET)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_L2_STATEST_MEM_OFF  (0x00000000U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_DSP2_L2_STATEST_MEM_OFF       (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_L2_STATEST_MEM_OFF)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_L2_STATEST_RESERVED  (0x00000002U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_DSP2_L2_STATEST_RESERVED      (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_L2_STATEST_RESERVED)


#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_EDMA_STATEST_MASK  (0x00000300U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_DSP2_EDMA_STATEST_MASK        (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_EDMA_STATEST_MASK)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_EDMA_STATEST_RESETVAL  (0x00000003U)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_EDMA_STATEST_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_DSP2_EDMA_STATEST_SHIFT       (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_EDMA_STATEST_SHIFT)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_EDMA_STATEST_MEM_ON  (0x00000003U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_DSP2_EDMA_STATEST_MEM_ON      (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_EDMA_STATEST_MEM_ON)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_EDMA_STATEST_MEM_RET  (0x00000001U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_DSP2_EDMA_STATEST_MEM_RET     (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_EDMA_STATEST_MEM_RET)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_EDMA_STATEST_MEM_OFF  (0x00000000U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_DSP2_EDMA_STATEST_MEM_OFF     (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_EDMA_STATEST_MEM_OFF)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_EDMA_STATEST_RESERVED  (0x00000002U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_DSP2_EDMA_STATEST_RESERVED    (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_DSP2_EDMA_STATEST_RESERVED)


#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_LASTPOWERSTATEENTERED_MASK  (0x03000000U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_LASTPOWERSTATEENTERED_MASK    (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_LASTPOWERSTATEENTERED_MASK)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_LASTPOWERSTATEENTERED_RESETVAL  (0x00000000U)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_LASTPOWERSTATEENTERED_SHIFT  (24U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_LASTPOWERSTATEENTERED_SHIFT   (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_LASTPOWERSTATEENTERED_SHIFT)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_LASTPOWERSTATEENTERED_ON  (0x00000003U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_LASTPOWERSTATEENTERED_ON      (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_LASTPOWERSTATEENTERED_ON)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_LASTPOWERSTATEENTERED_OFF  (0x00000000U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_LASTPOWERSTATEENTERED_OFF     (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_LASTPOWERSTATEENTERED_OFF)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_LASTPOWERSTATEENTERED_RET  (0x00000001U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_LASTPOWERSTATEENTERED_RET     (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_LASTPOWERSTATEENTERED_RET)

#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_LASTPOWERSTATEENTERED_INACTIVE  (0x00000002U)
/* Below define for backward compatibility */
#define PM_DSP2_PWRSTST_LASTPOWERSTATEENTERED_INACTIVE  (CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_LASTPOWERSTATEENTERED_INACTIVE)


#define CSL_DSP2_PRM_PM_DSP2_PWRSTST_REG_RESETVAL               (0x000003f7U)

/* RM_DSP2_RSTCTRL_REG */

#define CSL_DSP2_PRM_RM_DSP2_RSTCTRL_REG_RST_DSP2_LRST_MASK     (0x00000001U)
/* Below define for backward compatibility */
#define RM_DSP2_RSTCTRL_RST_DSP2_LRST_MASK            (CSL_DSP2_PRM_RM_DSP2_RSTCTRL_REG_RST_DSP2_LRST_MASK)

#define CSL_DSP2_PRM_RM_DSP2_RSTCTRL_REG_RST_DSP2_LRST_RESETVAL  (0x00000001U)

#define CSL_DSP2_PRM_RM_DSP2_RSTCTRL_REG_RST_DSP2_LRST_SHIFT    (0U)
/* Below define for backward compatibility */
#define RM_DSP2_RSTCTRL_RST_DSP2_LRST_SHIFT           (CSL_DSP2_PRM_RM_DSP2_RSTCTRL_REG_RST_DSP2_LRST_SHIFT)

#define CSL_DSP2_PRM_RM_DSP2_RSTCTRL_REG_RST_DSP2_LRST_ASSERT   (0x00000001U)
/* Below define for backward compatibility */
#define RM_DSP2_RSTCTRL_RST_DSP2_LRST_ASSERT          (CSL_DSP2_PRM_RM_DSP2_RSTCTRL_REG_RST_DSP2_LRST_ASSERT)

#define CSL_DSP2_PRM_RM_DSP2_RSTCTRL_REG_RST_DSP2_LRST_CLEAR    (0x00000000U)
/* Below define for backward compatibility */
#define RM_DSP2_RSTCTRL_RST_DSP2_LRST_CLEAR           (CSL_DSP2_PRM_RM_DSP2_RSTCTRL_REG_RST_DSP2_LRST_CLEAR)


#define CSL_DSP2_PRM_RM_DSP2_RSTCTRL_REG_RST_DSP2_MASK          (0x00000002U)
/* Below define for backward compatibility */
#define RM_DSP2_RSTCTRL_RST_DSP2_MASK                 (CSL_DSP2_PRM_RM_DSP2_RSTCTRL_REG_RST_DSP2_MASK)

#define CSL_DSP2_PRM_RM_DSP2_RSTCTRL_REG_RST_DSP2_RESETVAL      (0x00000001U)

#define CSL_DSP2_PRM_RM_DSP2_RSTCTRL_REG_RST_DSP2_SHIFT         (1U)
/* Below define for backward compatibility */
#define RM_DSP2_RSTCTRL_RST_DSP2_SHIFT                (CSL_DSP2_PRM_RM_DSP2_RSTCTRL_REG_RST_DSP2_SHIFT)

#define CSL_DSP2_PRM_RM_DSP2_RSTCTRL_REG_RST_DSP2_ASSERT        (0x00000001U)
/* Below define for backward compatibility */
#define RM_DSP2_RSTCTRL_RST_DSP2_ASSERT               (CSL_DSP2_PRM_RM_DSP2_RSTCTRL_REG_RST_DSP2_ASSERT)

#define CSL_DSP2_PRM_RM_DSP2_RSTCTRL_REG_RST_DSP2_CLEAR         (0x00000000U)
/* Below define for backward compatibility */
#define RM_DSP2_RSTCTRL_RST_DSP2_CLEAR                (CSL_DSP2_PRM_RM_DSP2_RSTCTRL_REG_RST_DSP2_CLEAR)


#define CSL_DSP2_PRM_RM_DSP2_RSTCTRL_REG_RESETVAL               (0x00000003U)

/* RM_DSP2_RSTST_REG */

#define CSL_DSP2_PRM_RM_DSP2_RSTST_REG_RST_DSP2_EMU_MASK        (0x00000004U)
/* Below define for backward compatibility */
#define RM_DSP2_RSTST_RST_DSP2_EMU_MASK               (CSL_DSP2_PRM_RM_DSP2_RSTST_REG_RST_DSP2_EMU_MASK)

#define CSL_DSP2_PRM_RM_DSP2_RSTST_REG_RST_DSP2_EMU_RESETVAL    (0x00000000U)

#define CSL_DSP2_PRM_RM_DSP2_RSTST_REG_RST_DSP2_EMU_SHIFT       (2U)
/* Below define for backward compatibility */
#define RM_DSP2_RSTST_RST_DSP2_EMU_SHIFT              (CSL_DSP2_PRM_RM_DSP2_RSTST_REG_RST_DSP2_EMU_SHIFT)

#define CSL_DSP2_PRM_RM_DSP2_RSTST_REG_RST_DSP2_EMU_RESET_YES   (0x00000001U)
/* Below define for backward compatibility */
#define RM_DSP2_RSTST_RST_DSP2_EMU_RESET_YES          (CSL_DSP2_PRM_RM_DSP2_RSTST_REG_RST_DSP2_EMU_RESET_YES)

#define CSL_DSP2_PRM_RM_DSP2_RSTST_REG_RST_DSP2_EMU_RESET_NO    (0x00000000U)
/* Below define for backward compatibility */
#define RM_DSP2_RSTST_RST_DSP2_EMU_RESET_NO           (CSL_DSP2_PRM_RM_DSP2_RSTST_REG_RST_DSP2_EMU_RESET_NO)


#define CSL_DSP2_PRM_RM_DSP2_RSTST_REG_RST_DSP2_LRST_MASK       (0x00000001U)
/* Below define for backward compatibility */
#define RM_DSP2_RSTST_RST_DSP2_LRST_MASK              (CSL_DSP2_PRM_RM_DSP2_RSTST_REG_RST_DSP2_LRST_MASK)

#define CSL_DSP2_PRM_RM_DSP2_RSTST_REG_RST_DSP2_LRST_RESETVAL   (0x00000000U)

#define CSL_DSP2_PRM_RM_DSP2_RSTST_REG_RST_DSP2_LRST_SHIFT      (0U)
/* Below define for backward compatibility */
#define RM_DSP2_RSTST_RST_DSP2_LRST_SHIFT             (CSL_DSP2_PRM_RM_DSP2_RSTST_REG_RST_DSP2_LRST_SHIFT)

#define CSL_DSP2_PRM_RM_DSP2_RSTST_REG_RST_DSP2_LRST_RESET_YES  (0x00000001U)
/* Below define for backward compatibility */
#define RM_DSP2_RSTST_RST_DSP2_LRST_RESET_YES         (CSL_DSP2_PRM_RM_DSP2_RSTST_REG_RST_DSP2_LRST_RESET_YES)

#define CSL_DSP2_PRM_RM_DSP2_RSTST_REG_RST_DSP2_LRST_RESET_NO   (0x00000000U)
/* Below define for backward compatibility */
#define RM_DSP2_RSTST_RST_DSP2_LRST_RESET_NO          (CSL_DSP2_PRM_RM_DSP2_RSTST_REG_RST_DSP2_LRST_RESET_NO)


#define CSL_DSP2_PRM_RM_DSP2_RSTST_REG_RST_DSP2_MASK            (0x00000002U)
/* Below define for backward compatibility */
#define RM_DSP2_RSTST_RST_DSP2_MASK                   (CSL_DSP2_PRM_RM_DSP2_RSTST_REG_RST_DSP2_MASK)

#define CSL_DSP2_PRM_RM_DSP2_RSTST_REG_RST_DSP2_RESETVAL        (0x00000000U)

#define CSL_DSP2_PRM_RM_DSP2_RSTST_REG_RST_DSP2_SHIFT           (1U)
/* Below define for backward compatibility */
#define RM_DSP2_RSTST_RST_DSP2_SHIFT                  (CSL_DSP2_PRM_RM_DSP2_RSTST_REG_RST_DSP2_SHIFT)

#define CSL_DSP2_PRM_RM_DSP2_RSTST_REG_RST_DSP2_RESET_YES       (0x00000001U)
/* Below define for backward compatibility */
#define RM_DSP2_RSTST_RST_DSP2_RESET_YES              (CSL_DSP2_PRM_RM_DSP2_RSTST_REG_RST_DSP2_RESET_YES)

#define CSL_DSP2_PRM_RM_DSP2_RSTST_REG_RST_DSP2_RESET_NO        (0x00000000U)
/* Below define for backward compatibility */
#define RM_DSP2_RSTST_RST_DSP2_RESET_NO               (CSL_DSP2_PRM_RM_DSP2_RSTST_REG_RST_DSP2_RESET_NO)


#define CSL_DSP2_PRM_RM_DSP2_RSTST_REG_RST_DSP2_EMU_REQ_MASK    (0x00000008U)
/* Below define for backward compatibility */
#define RM_DSP2_RSTST_RST_DSP2_EMU_REQ_MASK           (CSL_DSP2_PRM_RM_DSP2_RSTST_REG_RST_DSP2_EMU_REQ_MASK)

#define CSL_DSP2_PRM_RM_DSP2_RSTST_REG_RST_DSP2_EMU_REQ_RESETVAL  (0x00000000U)

#define CSL_DSP2_PRM_RM_DSP2_RSTST_REG_RST_DSP2_EMU_REQ_SHIFT   (3U)
/* Below define for backward compatibility */
#define RM_DSP2_RSTST_RST_DSP2_EMU_REQ_SHIFT          (CSL_DSP2_PRM_RM_DSP2_RSTST_REG_RST_DSP2_EMU_REQ_SHIFT)

#define CSL_DSP2_PRM_RM_DSP2_RSTST_REG_RST_DSP2_EMU_REQ_RESET_YES  (0x00000001U)
/* Below define for backward compatibility */
#define RM_DSP2_RSTST_RST_DSP2_EMU_REQ_RESET_YES      (CSL_DSP2_PRM_RM_DSP2_RSTST_REG_RST_DSP2_EMU_REQ_RESET_YES)

#define CSL_DSP2_PRM_RM_DSP2_RSTST_REG_RST_DSP2_EMU_REQ_RESET_NO  (0x00000000U)
/* Below define for backward compatibility */
#define RM_DSP2_RSTST_RST_DSP2_EMU_REQ_RESET_NO       (CSL_DSP2_PRM_RM_DSP2_RSTST_REG_RST_DSP2_EMU_REQ_RESET_NO)


#define CSL_DSP2_PRM_RM_DSP2_RSTST_REG_RESETVAL                 (0x00000000U)

/* RM_DSP2_DSP2_CONTEXT_REG */

#define CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_DSP2_DSP2_CONTEXT_LOSTCONTEXT_DFF_MASK     (CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_DSP2_DSP2_CONTEXT_LOSTCONTEXT_DFF_SHIFT    (CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_DSP2_DSP2_CONTEXT_LOSTCONTEXT_DFF_LOST     (CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_DSP2_DSP2_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG_LOSTMEM_DSP_L1_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define RM_DSP2_DSP2_CONTEXT_LOSTMEM_DSP_L1_MASK      (CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG_LOSTMEM_DSP_L1_MASK)

#define CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG_LOSTMEM_DSP_L1_RESETVAL  (0x00000001U)

#define CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG_LOSTMEM_DSP_L1_SHIFT  (8U)
/* Below define for backward compatibility */
#define RM_DSP2_DSP2_CONTEXT_LOSTMEM_DSP_L1_SHIFT     (CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG_LOSTMEM_DSP_L1_SHIFT)

#define CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG_LOSTMEM_DSP_L1_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_DSP2_DSP2_CONTEXT_LOSTMEM_DSP_L1_LOST      (CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG_LOSTMEM_DSP_L1_LOST)

#define CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG_LOSTMEM_DSP_L1_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_DSP2_DSP2_CONTEXT_LOSTMEM_DSP_L1_MAINTAINED  (CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG_LOSTMEM_DSP_L1_MAINTAINED)


#define CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG_LOSTMEM_DSP_L2_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define RM_DSP2_DSP2_CONTEXT_LOSTMEM_DSP_L2_MASK      (CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG_LOSTMEM_DSP_L2_MASK)

#define CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG_LOSTMEM_DSP_L2_RESETVAL  (0x00000001U)

#define CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG_LOSTMEM_DSP_L2_SHIFT  (9U)
/* Below define for backward compatibility */
#define RM_DSP2_DSP2_CONTEXT_LOSTMEM_DSP_L2_SHIFT     (CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG_LOSTMEM_DSP_L2_SHIFT)

#define CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG_LOSTMEM_DSP_L2_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_DSP2_DSP2_CONTEXT_LOSTMEM_DSP_L2_LOST      (CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG_LOSTMEM_DSP_L2_LOST)

#define CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG_LOSTMEM_DSP_L2_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_DSP2_DSP2_CONTEXT_LOSTMEM_DSP_L2_MAINTAINED  (CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG_LOSTMEM_DSP_L2_MAINTAINED)


#define CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG_LOSTMEM_DSP_EDMA_MASK  (0x00000400U)
/* Below define for backward compatibility */
#define RM_DSP2_DSP2_CONTEXT_LOSTMEM_DSP_EDMA_MASK    (CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG_LOSTMEM_DSP_EDMA_MASK)

#define CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG_LOSTMEM_DSP_EDMA_RESETVAL  (0x00000001U)

#define CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG_LOSTMEM_DSP_EDMA_SHIFT  (10U)
/* Below define for backward compatibility */
#define RM_DSP2_DSP2_CONTEXT_LOSTMEM_DSP_EDMA_SHIFT   (CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG_LOSTMEM_DSP_EDMA_SHIFT)

#define CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG_LOSTMEM_DSP_EDMA_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_DSP2_DSP2_CONTEXT_LOSTMEM_DSP_EDMA_LOST    (CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG_LOSTMEM_DSP_EDMA_LOST)

#define CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG_LOSTMEM_DSP_EDMA_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_DSP2_DSP2_CONTEXT_LOSTMEM_DSP_EDMA_MAINTAINED  (CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG_LOSTMEM_DSP_EDMA_MAINTAINED)


#define CSL_DSP2_PRM_RM_DSP2_DSP2_CONTEXT_REG_RESETVAL          (0x00000701U)

#ifdef __cplusplus
}
#endif
#endif
