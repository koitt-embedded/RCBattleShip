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
#ifndef CSLR_EVE4_PRM_H_
#define CSLR_EVE4_PRM_H_

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
    volatile Uint32 PM_EVE4_PWRSTCTRL_REG;
    volatile Uint32 PM_EVE4_PWRSTST_REG;
    volatile Uint8  RSVD0[8];
    volatile Uint32 RM_EVE4_RSTCTRL_REG;
    volatile Uint32 RM_EVE4_RSTST_REG;
    volatile Uint8  RSVD1[8];
    volatile Uint32 PM_EVE4_EVE4_WKDEP_REG;
    volatile Uint32 RM_EVE4_EVE4_CONTEXT_REG;
} CSL_eve4_prmRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* This register controls the EVE power state to reach upon a domain sleep
 * transition */
#define CSL_EVE4_PRM_PM_EVE4_PWRSTCTRL_REG                      (0x0U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTCTRL        (CSL_EVE4_PRM_PM_EVE4_PWRSTCTRL_REG)


/* This register provides a status on the EVE domain current power state.
 * [warm reset insensitive] */
#define CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG                        (0x4U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTST          (CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG)


/* This register controls the release of the EVE sub-system resets. */
#define CSL_EVE4_PRM_RM_EVE4_RSTCTRL_REG                        (0x10U)
/* Below define for backward compatibility */
#define RM_EVE4_RSTCTRL          (CSL_EVE4_PRM_RM_EVE4_RSTCTRL_REG)


/* This register logs the different reset sources of the EVE domain. Each bit
 * is set upon release of the domain reset signal. Must be cleared by
 * software. [warm reset insensitive] */
#define CSL_EVE4_PRM_RM_EVE4_RSTST_REG                          (0x14U)
/* Below define for backward compatibility */
#define RM_EVE4_RSTST            (CSL_EVE4_PRM_RM_EVE4_RSTST_REG)


/* This register controls wakeup dependency based on EVE4 service requests. */
#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG                     (0x20U)
/* Below define for backward compatibility */
#define PM_EVE4_EVE4_WKDEP       (CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG)


/* This register contains dedicated EVE context statuses. [warm reset
 * insensitive] */
#define CSL_EVE4_PRM_RM_EVE4_EVE4_CONTEXT_REG                   (0x24U)
/* Below define for backward compatibility */
#define RM_EVE4_EVE4_CONTEXT     (CSL_EVE4_PRM_RM_EVE4_EVE4_CONTEXT_REG)



/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* PM_EVE4_PWRSTCTRL_REG */

#define CSL_EVE4_PRM_PM_EVE4_PWRSTCTRL_REG_EVE4_BANK_ONSTATE_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTCTRL_EVE4_BANK_ONSTATE_MASK      (CSL_EVE4_PRM_PM_EVE4_PWRSTCTRL_REG_EVE4_BANK_ONSTATE_MASK)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTCTRL_REG_EVE4_BANK_ONSTATE_RESETVAL  (0x00000003U)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTCTRL_REG_EVE4_BANK_ONSTATE_SHIFT  (16U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTCTRL_EVE4_BANK_ONSTATE_SHIFT     (CSL_EVE4_PRM_PM_EVE4_PWRSTCTRL_REG_EVE4_BANK_ONSTATE_SHIFT)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTCTRL_REG_EVE4_BANK_ONSTATE_MEM_ON  (0x00000003U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTCTRL_EVE4_BANK_ONSTATE_MEM_ON    (CSL_EVE4_PRM_PM_EVE4_PWRSTCTRL_REG_EVE4_BANK_ONSTATE_MEM_ON)


#define CSL_EVE4_PRM_PM_EVE4_PWRSTCTRL_REG_POWERSTATE_MASK      (0x00000003U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTCTRL_POWERSTATE_MASK             (CSL_EVE4_PRM_PM_EVE4_PWRSTCTRL_REG_POWERSTATE_MASK)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTCTRL_REG_POWERSTATE_RESETVAL  (0x00000003U)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTCTRL_REG_POWERSTATE_SHIFT     (0U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTCTRL_POWERSTATE_SHIFT            (CSL_EVE4_PRM_PM_EVE4_PWRSTCTRL_REG_POWERSTATE_SHIFT)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTCTRL_REG_POWERSTATE_OFF       (0x00000000U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTCTRL_POWERSTATE_OFF              (CSL_EVE4_PRM_PM_EVE4_PWRSTCTRL_REG_POWERSTATE_OFF)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTCTRL_REG_POWERSTATE_INACT     (0x00000002U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTCTRL_POWERSTATE_INACT            (CSL_EVE4_PRM_PM_EVE4_PWRSTCTRL_REG_POWERSTATE_INACT)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTCTRL_REG_POWERSTATE_RESERVED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTCTRL_POWERSTATE_RESERVED         (CSL_EVE4_PRM_PM_EVE4_PWRSTCTRL_REG_POWERSTATE_RESERVED)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTCTRL_REG_POWERSTATE_ON        (0x00000003U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTCTRL_POWERSTATE_ON               (CSL_EVE4_PRM_PM_EVE4_PWRSTCTRL_REG_POWERSTATE_ON)


#define CSL_EVE4_PRM_PM_EVE4_PWRSTCTRL_REG_LOWPOWERSTATECHANGE_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTCTRL_LOWPOWERSTATECHANGE_MASK    (CSL_EVE4_PRM_PM_EVE4_PWRSTCTRL_REG_LOWPOWERSTATECHANGE_MASK)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTCTRL_REG_LOWPOWERSTATECHANGE_RESETVAL  (0x00000000U)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTCTRL_REG_LOWPOWERSTATECHANGE_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTCTRL_LOWPOWERSTATECHANGE_SHIFT   (CSL_EVE4_PRM_PM_EVE4_PWRSTCTRL_REG_LOWPOWERSTATECHANGE_SHIFT)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTCTRL_REG_LOWPOWERSTATECHANGE_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTCTRL_LOWPOWERSTATECHANGE_EN      (CSL_EVE4_PRM_PM_EVE4_PWRSTCTRL_REG_LOWPOWERSTATECHANGE_EN)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTCTRL_REG_LOWPOWERSTATECHANGE_DIS  (0x00000000U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTCTRL_LOWPOWERSTATECHANGE_DIS     (CSL_EVE4_PRM_PM_EVE4_PWRSTCTRL_REG_LOWPOWERSTATECHANGE_DIS)


#define CSL_EVE4_PRM_PM_EVE4_PWRSTCTRL_REG_RESETVAL             (0x00030003U)

/* PM_EVE4_PWRSTST_REG */

#define CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_POWERSTATEST_MASK      (0x00000003U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTST_POWERSTATEST_MASK             (CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_POWERSTATEST_MASK)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_POWERSTATEST_RESETVAL  (0x00000003U)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_POWERSTATEST_SHIFT     (0U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTST_POWERSTATEST_SHIFT            (CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_POWERSTATEST_SHIFT)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_POWERSTATEST_ON        (0x00000003U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTST_POWERSTATEST_ON               (CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_POWERSTATEST_ON)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_POWERSTATEST_OFF       (0x00000000U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTST_POWERSTATEST_OFF              (CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_POWERSTATEST_OFF)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_POWERSTATEST_RET       (0x00000001U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTST_POWERSTATEST_RET              (CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_POWERSTATEST_RET)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_POWERSTATEST_INACTIVE  (0x00000002U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTST_POWERSTATEST_INACTIVE         (CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_POWERSTATEST_INACTIVE)


#define CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_INTRANSITION_MASK      (0x00100000U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTST_INTRANSITION_MASK             (CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_INTRANSITION_MASK)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_INTRANSITION_RESETVAL  (0x00000000U)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_INTRANSITION_SHIFT     (20U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTST_INTRANSITION_SHIFT            (CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_INTRANSITION_SHIFT)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_INTRANSITION_NO        (0x00000000U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTST_INTRANSITION_NO               (CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_INTRANSITION_NO)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_INTRANSITION_ONGOING   (0x00000001U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTST_INTRANSITION_ONGOING          (CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_INTRANSITION_ONGOING)


#define CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_LOGICSTATEST_MASK      (0x00000004U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTST_LOGICSTATEST_MASK             (CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_LOGICSTATEST_MASK)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_LOGICSTATEST_RESETVAL  (0x00000001U)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_LOGICSTATEST_SHIFT     (2U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTST_LOGICSTATEST_SHIFT            (CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_LOGICSTATEST_SHIFT)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_LOGICSTATEST_ON        (0x00000001U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTST_LOGICSTATEST_ON               (CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_LOGICSTATEST_ON)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_LOGICSTATEST_OFF       (0x00000000U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTST_LOGICSTATEST_OFF              (CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_LOGICSTATEST_OFF)


#define CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_EVE4_BANK_STATEST_MASK  (0x00000030U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTST_EVE4_BANK_STATEST_MASK        (CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_EVE4_BANK_STATEST_MASK)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_EVE4_BANK_STATEST_RESETVAL  (0x00000003U)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_EVE4_BANK_STATEST_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTST_EVE4_BANK_STATEST_SHIFT       (CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_EVE4_BANK_STATEST_SHIFT)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_EVE4_BANK_STATEST_MEM_ON  (0x00000003U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTST_EVE4_BANK_STATEST_MEM_ON      (CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_EVE4_BANK_STATEST_MEM_ON)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_EVE4_BANK_STATEST_RESERVED1  (0x00000001U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTST_EVE4_BANK_STATEST_RESERVED1   (CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_EVE4_BANK_STATEST_RESERVED1)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_EVE4_BANK_STATEST_MEM_OFF  (0x00000000U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTST_EVE4_BANK_STATEST_MEM_OFF     (CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_EVE4_BANK_STATEST_MEM_OFF)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_EVE4_BANK_STATEST_RESERVED  (0x00000002U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTST_EVE4_BANK_STATEST_RESERVED    (CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_EVE4_BANK_STATEST_RESERVED)


#define CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_LASTPOWERSTATEENTERED_MASK  (0x03000000U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTST_LASTPOWERSTATEENTERED_MASK    (CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_LASTPOWERSTATEENTERED_MASK)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_LASTPOWERSTATEENTERED_RESETVAL  (0x00000000U)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_LASTPOWERSTATEENTERED_SHIFT  (24U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTST_LASTPOWERSTATEENTERED_SHIFT   (CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_LASTPOWERSTATEENTERED_SHIFT)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_LASTPOWERSTATEENTERED_ON  (0x00000003U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTST_LASTPOWERSTATEENTERED_ON      (CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_LASTPOWERSTATEENTERED_ON)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_LASTPOWERSTATEENTERED_OFF  (0x00000000U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTST_LASTPOWERSTATEENTERED_OFF     (CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_LASTPOWERSTATEENTERED_OFF)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_LASTPOWERSTATEENTERED_RET  (0x00000001U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTST_LASTPOWERSTATEENTERED_RET     (CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_LASTPOWERSTATEENTERED_RET)

#define CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_LASTPOWERSTATEENTERED_INACTIVE  (0x00000002U)
/* Below define for backward compatibility */
#define PM_EVE4_PWRSTST_LASTPOWERSTATEENTERED_INACTIVE  (CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_LASTPOWERSTATEENTERED_INACTIVE)


#define CSL_EVE4_PRM_PM_EVE4_PWRSTST_REG_RESETVAL               (0x00000037U)

/* RM_EVE4_RSTCTRL_REG */

#define CSL_EVE4_PRM_RM_EVE4_RSTCTRL_REG_RST_EVE4_LRST_MASK     (0x00000001U)
/* Below define for backward compatibility */
#define RM_EVE4_RSTCTRL_RST_EVE4_LRST_MASK            (CSL_EVE4_PRM_RM_EVE4_RSTCTRL_REG_RST_EVE4_LRST_MASK)

#define CSL_EVE4_PRM_RM_EVE4_RSTCTRL_REG_RST_EVE4_LRST_RESETVAL  (0x00000001U)

#define CSL_EVE4_PRM_RM_EVE4_RSTCTRL_REG_RST_EVE4_LRST_SHIFT    (0U)
/* Below define for backward compatibility */
#define RM_EVE4_RSTCTRL_RST_EVE4_LRST_SHIFT           (CSL_EVE4_PRM_RM_EVE4_RSTCTRL_REG_RST_EVE4_LRST_SHIFT)

#define CSL_EVE4_PRM_RM_EVE4_RSTCTRL_REG_RST_EVE4_LRST_ASSERT   (0x00000001U)
/* Below define for backward compatibility */
#define RM_EVE4_RSTCTRL_RST_EVE4_LRST_ASSERT          (CSL_EVE4_PRM_RM_EVE4_RSTCTRL_REG_RST_EVE4_LRST_ASSERT)

#define CSL_EVE4_PRM_RM_EVE4_RSTCTRL_REG_RST_EVE4_LRST_CLEAR    (0x00000000U)
/* Below define for backward compatibility */
#define RM_EVE4_RSTCTRL_RST_EVE4_LRST_CLEAR           (CSL_EVE4_PRM_RM_EVE4_RSTCTRL_REG_RST_EVE4_LRST_CLEAR)


#define CSL_EVE4_PRM_RM_EVE4_RSTCTRL_REG_RST_EVE4_MASK          (0x00000002U)
/* Below define for backward compatibility */
#define RM_EVE4_RSTCTRL_RST_EVE4_MASK                 (CSL_EVE4_PRM_RM_EVE4_RSTCTRL_REG_RST_EVE4_MASK)

#define CSL_EVE4_PRM_RM_EVE4_RSTCTRL_REG_RST_EVE4_RESETVAL      (0x00000001U)

#define CSL_EVE4_PRM_RM_EVE4_RSTCTRL_REG_RST_EVE4_SHIFT         (1U)
/* Below define for backward compatibility */
#define RM_EVE4_RSTCTRL_RST_EVE4_SHIFT                (CSL_EVE4_PRM_RM_EVE4_RSTCTRL_REG_RST_EVE4_SHIFT)

#define CSL_EVE4_PRM_RM_EVE4_RSTCTRL_REG_RST_EVE4_ASSERT        (0x00000001U)
/* Below define for backward compatibility */
#define RM_EVE4_RSTCTRL_RST_EVE4_ASSERT               (CSL_EVE4_PRM_RM_EVE4_RSTCTRL_REG_RST_EVE4_ASSERT)

#define CSL_EVE4_PRM_RM_EVE4_RSTCTRL_REG_RST_EVE4_CLEAR         (0x00000000U)
/* Below define for backward compatibility */
#define RM_EVE4_RSTCTRL_RST_EVE4_CLEAR                (CSL_EVE4_PRM_RM_EVE4_RSTCTRL_REG_RST_EVE4_CLEAR)


#define CSL_EVE4_PRM_RM_EVE4_RSTCTRL_REG_RESETVAL               (0x00000003U)

/* RM_EVE4_RSTST_REG */

#define CSL_EVE4_PRM_RM_EVE4_RSTST_REG_RST_EVE4_EMU_MASK        (0x00000004U)
/* Below define for backward compatibility */
#define RM_EVE4_RSTST_RST_EVE4_EMU_MASK               (CSL_EVE4_PRM_RM_EVE4_RSTST_REG_RST_EVE4_EMU_MASK)

#define CSL_EVE4_PRM_RM_EVE4_RSTST_REG_RST_EVE4_EMU_RESETVAL    (0x00000000U)

#define CSL_EVE4_PRM_RM_EVE4_RSTST_REG_RST_EVE4_EMU_SHIFT       (2U)
/* Below define for backward compatibility */
#define RM_EVE4_RSTST_RST_EVE4_EMU_SHIFT              (CSL_EVE4_PRM_RM_EVE4_RSTST_REG_RST_EVE4_EMU_SHIFT)

#define CSL_EVE4_PRM_RM_EVE4_RSTST_REG_RST_EVE4_EMU_RESET_YES   (0x00000001U)
/* Below define for backward compatibility */
#define RM_EVE4_RSTST_RST_EVE4_EMU_RESET_YES          (CSL_EVE4_PRM_RM_EVE4_RSTST_REG_RST_EVE4_EMU_RESET_YES)

#define CSL_EVE4_PRM_RM_EVE4_RSTST_REG_RST_EVE4_EMU_RESET_NO    (0x00000000U)
/* Below define for backward compatibility */
#define RM_EVE4_RSTST_RST_EVE4_EMU_RESET_NO           (CSL_EVE4_PRM_RM_EVE4_RSTST_REG_RST_EVE4_EMU_RESET_NO)


#define CSL_EVE4_PRM_RM_EVE4_RSTST_REG_RST_EVE4_LRST_MASK       (0x00000001U)
/* Below define for backward compatibility */
#define RM_EVE4_RSTST_RST_EVE4_LRST_MASK              (CSL_EVE4_PRM_RM_EVE4_RSTST_REG_RST_EVE4_LRST_MASK)

#define CSL_EVE4_PRM_RM_EVE4_RSTST_REG_RST_EVE4_LRST_RESETVAL   (0x00000000U)

#define CSL_EVE4_PRM_RM_EVE4_RSTST_REG_RST_EVE4_LRST_SHIFT      (0U)
/* Below define for backward compatibility */
#define RM_EVE4_RSTST_RST_EVE4_LRST_SHIFT             (CSL_EVE4_PRM_RM_EVE4_RSTST_REG_RST_EVE4_LRST_SHIFT)

#define CSL_EVE4_PRM_RM_EVE4_RSTST_REG_RST_EVE4_LRST_RESET_YES  (0x00000001U)
/* Below define for backward compatibility */
#define RM_EVE4_RSTST_RST_EVE4_LRST_RESET_YES         (CSL_EVE4_PRM_RM_EVE4_RSTST_REG_RST_EVE4_LRST_RESET_YES)

#define CSL_EVE4_PRM_RM_EVE4_RSTST_REG_RST_EVE4_LRST_RESET_NO   (0x00000000U)
/* Below define for backward compatibility */
#define RM_EVE4_RSTST_RST_EVE4_LRST_RESET_NO          (CSL_EVE4_PRM_RM_EVE4_RSTST_REG_RST_EVE4_LRST_RESET_NO)


#define CSL_EVE4_PRM_RM_EVE4_RSTST_REG_RST_EVE4_MASK            (0x00000002U)
/* Below define for backward compatibility */
#define RM_EVE4_RSTST_RST_EVE4_MASK                   (CSL_EVE4_PRM_RM_EVE4_RSTST_REG_RST_EVE4_MASK)

#define CSL_EVE4_PRM_RM_EVE4_RSTST_REG_RST_EVE4_RESETVAL        (0x00000000U)

#define CSL_EVE4_PRM_RM_EVE4_RSTST_REG_RST_EVE4_SHIFT           (1U)
/* Below define for backward compatibility */
#define RM_EVE4_RSTST_RST_EVE4_SHIFT                  (CSL_EVE4_PRM_RM_EVE4_RSTST_REG_RST_EVE4_SHIFT)

#define CSL_EVE4_PRM_RM_EVE4_RSTST_REG_RST_EVE4_RESET_YES       (0x00000001U)
/* Below define for backward compatibility */
#define RM_EVE4_RSTST_RST_EVE4_RESET_YES              (CSL_EVE4_PRM_RM_EVE4_RSTST_REG_RST_EVE4_RESET_YES)

#define CSL_EVE4_PRM_RM_EVE4_RSTST_REG_RST_EVE4_RESET_NO        (0x00000000U)
/* Below define for backward compatibility */
#define RM_EVE4_RSTST_RST_EVE4_RESET_NO               (CSL_EVE4_PRM_RM_EVE4_RSTST_REG_RST_EVE4_RESET_NO)


#define CSL_EVE4_PRM_RM_EVE4_RSTST_REG_RST_EVE4_EMU_REQ_MASK    (0x00000008U)
/* Below define for backward compatibility */
#define RM_EVE4_RSTST_RST_EVE4_EMU_REQ_MASK           (CSL_EVE4_PRM_RM_EVE4_RSTST_REG_RST_EVE4_EMU_REQ_MASK)

#define CSL_EVE4_PRM_RM_EVE4_RSTST_REG_RST_EVE4_EMU_REQ_RESETVAL  (0x00000000U)

#define CSL_EVE4_PRM_RM_EVE4_RSTST_REG_RST_EVE4_EMU_REQ_SHIFT   (3U)
/* Below define for backward compatibility */
#define RM_EVE4_RSTST_RST_EVE4_EMU_REQ_SHIFT          (CSL_EVE4_PRM_RM_EVE4_RSTST_REG_RST_EVE4_EMU_REQ_SHIFT)

#define CSL_EVE4_PRM_RM_EVE4_RSTST_REG_RST_EVE4_EMU_REQ_RESET_YES  (0x00000001U)
/* Below define for backward compatibility */
#define RM_EVE4_RSTST_RST_EVE4_EMU_REQ_RESET_YES      (CSL_EVE4_PRM_RM_EVE4_RSTST_REG_RST_EVE4_EMU_REQ_RESET_YES)

#define CSL_EVE4_PRM_RM_EVE4_RSTST_REG_RST_EVE4_EMU_REQ_RESET_NO  (0x00000000U)
/* Below define for backward compatibility */
#define RM_EVE4_RSTST_RST_EVE4_EMU_REQ_RESET_NO       (CSL_EVE4_PRM_RM_EVE4_RSTST_REG_RST_EVE4_EMU_REQ_RESET_NO)


#define CSL_EVE4_PRM_RM_EVE4_RSTST_REG_RESETVAL                 (0x00000000U)

/* PM_EVE4_EVE4_WKDEP_REG */

#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_EVE4_EVE4_WKDEP_WKUPDEP_EVE4_MPU_MASK      (CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_MPU_MASK)

#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_MPU_RESETVAL  (0x00000000U)

#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_EVE4_EVE4_WKDEP_WKUPDEP_EVE4_MPU_SHIFT     (CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_MPU_SHIFT)

#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_EVE4_EVE4_WKDEP_WKUPDEP_EVE4_MPU_ENABLED   (CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_MPU_ENABLED)

#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_EVE4_EVE4_WKDEP_WKUPDEP_EVE4_MPU_DISABLED  (CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_MPU_DISABLED)


#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_EVE4_EVE4_WKDEP_WKUPDEP_EVE4_DSP1_MASK     (CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_DSP1_MASK)

#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_DSP1_RESETVAL  (0x00000000U)

#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_EVE4_EVE4_WKDEP_WKUPDEP_EVE4_DSP1_SHIFT    (CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_DSP1_SHIFT)

#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_EVE4_EVE4_WKDEP_WKUPDEP_EVE4_DSP1_ENABLED  (CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_DSP1_ENABLED)

#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_EVE4_EVE4_WKDEP_WKUPDEP_EVE4_DSP1_DISABLED  (CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_DSP1_DISABLED)


#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_EVE4_EVE4_WKDEP_WKUPDEP_EVE4_IPU2_MASK     (CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_IPU2_MASK)

#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_IPU2_RESETVAL  (0x00000000U)

#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_EVE4_EVE4_WKDEP_WKUPDEP_EVE4_IPU2_SHIFT    (CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_IPU2_SHIFT)

#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_EVE4_EVE4_WKDEP_WKUPDEP_EVE4_IPU2_ENABLED  (CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_IPU2_ENABLED)

#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_EVE4_EVE4_WKDEP_WKUPDEP_EVE4_IPU2_DISABLED  (CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_IPU2_DISABLED)


#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_SDMA_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define PM_EVE4_EVE4_WKDEP_WKUPDEP_EVE4_SDMA_MASK     (CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_SDMA_MASK)

#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_SDMA_RESETVAL  (0x00000000U)

#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_SDMA_SHIFT  (3U)
/* Below define for backward compatibility */
#define PM_EVE4_EVE4_WKDEP_WKUPDEP_EVE4_SDMA_SHIFT    (CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_SDMA_SHIFT)

#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_SDMA_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_EVE4_EVE4_WKDEP_WKUPDEP_EVE4_SDMA_ENABLED  (CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_SDMA_ENABLED)

#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_SDMA_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_EVE4_EVE4_WKDEP_WKUPDEP_EVE4_SDMA_DISABLED  (CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_SDMA_DISABLED)


#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_EVE4_EVE4_WKDEP_WKUPDEP_EVE4_IPU1_MASK     (CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_IPU1_MASK)

#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_IPU1_RESETVAL  (0x00000000U)

#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_EVE4_EVE4_WKDEP_WKUPDEP_EVE4_IPU1_SHIFT    (CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_IPU1_SHIFT)

#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_EVE4_EVE4_WKDEP_WKUPDEP_EVE4_IPU1_ENABLED  (CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_IPU1_ENABLED)

#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_EVE4_EVE4_WKDEP_WKUPDEP_EVE4_IPU1_DISABLED  (CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_IPU1_DISABLED)


#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_EVE4_EVE4_WKDEP_WKUPDEP_EVE4_DSP2_MASK     (CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_DSP2_MASK)

#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_DSP2_RESETVAL  (0x00000000U)

#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_EVE4_EVE4_WKDEP_WKUPDEP_EVE4_DSP2_SHIFT    (CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_DSP2_SHIFT)

#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_EVE4_EVE4_WKDEP_WKUPDEP_EVE4_DSP2_ENABLED  (CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_DSP2_ENABLED)

#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_EVE4_EVE4_WKDEP_WKUPDEP_EVE4_DSP2_DISABLED  (CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_DSP2_DISABLED)


#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_EVE4_EVE4_WKDEP_WKUPDEP_EVE4_EVE1_MASK     (CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_EVE1_MASK)

#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_EVE1_RESETVAL  (0x00000000U)

#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_EVE4_EVE4_WKDEP_WKUPDEP_EVE4_EVE1_SHIFT    (CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_EVE1_SHIFT)

#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_EVE4_EVE4_WKDEP_WKUPDEP_EVE4_EVE1_ENABLED  (CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_EVE1_ENABLED)

#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_EVE4_EVE4_WKDEP_WKUPDEP_EVE4_EVE1_DISABLED  (CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_EVE1_DISABLED)


#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_EVE4_EVE4_WKDEP_WKUPDEP_EVE4_EVE2_MASK     (CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_EVE2_MASK)

#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_EVE2_RESETVAL  (0x00000000U)

#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_EVE4_EVE4_WKDEP_WKUPDEP_EVE4_EVE2_SHIFT    (CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_EVE2_SHIFT)

#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_EVE4_EVE4_WKDEP_WKUPDEP_EVE4_EVE2_ENABLED  (CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_EVE2_ENABLED)

#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_EVE4_EVE4_WKDEP_WKUPDEP_EVE4_EVE2_DISABLED  (CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_EVE2_DISABLED)


#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_EVE4_EVE4_WKDEP_WKUPDEP_EVE4_EVE3_MASK     (CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_EVE3_MASK)

#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_EVE3_RESETVAL  (0x00000000U)

#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_EVE4_EVE4_WKDEP_WKUPDEP_EVE4_EVE3_SHIFT    (CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_EVE3_SHIFT)

#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_EVE4_EVE4_WKDEP_WKUPDEP_EVE4_EVE3_ENABLED  (CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_EVE3_ENABLED)

#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_EVE4_EVE4_WKDEP_WKUPDEP_EVE4_EVE3_DISABLED  (CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_WKUPDEP_EVE4_EVE3_DISABLED)


#define CSL_EVE4_PRM_PM_EVE4_EVE4_WKDEP_REG_RESETVAL            (0x00000000U)

/* RM_EVE4_EVE4_CONTEXT_REG */

#define CSL_EVE4_PRM_RM_EVE4_EVE4_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_EVE4_EVE4_CONTEXT_LOSTCONTEXT_DFF_MASK     (CSL_EVE4_PRM_RM_EVE4_EVE4_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_EVE4_PRM_RM_EVE4_EVE4_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_EVE4_PRM_RM_EVE4_EVE4_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_EVE4_EVE4_CONTEXT_LOSTCONTEXT_DFF_SHIFT    (CSL_EVE4_PRM_RM_EVE4_EVE4_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_EVE4_PRM_RM_EVE4_EVE4_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_EVE4_EVE4_CONTEXT_LOSTCONTEXT_DFF_LOST     (CSL_EVE4_PRM_RM_EVE4_EVE4_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_EVE4_PRM_RM_EVE4_EVE4_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_EVE4_EVE4_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_EVE4_PRM_RM_EVE4_EVE4_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_EVE4_PRM_RM_EVE4_EVE4_CONTEXT_REG_LOSTMEM_EVE_BANK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define RM_EVE4_EVE4_CONTEXT_LOSTMEM_EVE_BANK_MASK    (CSL_EVE4_PRM_RM_EVE4_EVE4_CONTEXT_REG_LOSTMEM_EVE_BANK_MASK)

#define CSL_EVE4_PRM_RM_EVE4_EVE4_CONTEXT_REG_LOSTMEM_EVE_BANK_RESETVAL  (0x00000001U)

#define CSL_EVE4_PRM_RM_EVE4_EVE4_CONTEXT_REG_LOSTMEM_EVE_BANK_SHIFT  (8U)
/* Below define for backward compatibility */
#define RM_EVE4_EVE4_CONTEXT_LOSTMEM_EVE_BANK_SHIFT   (CSL_EVE4_PRM_RM_EVE4_EVE4_CONTEXT_REG_LOSTMEM_EVE_BANK_SHIFT)

#define CSL_EVE4_PRM_RM_EVE4_EVE4_CONTEXT_REG_LOSTMEM_EVE_BANK_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_EVE4_EVE4_CONTEXT_LOSTMEM_EVE_BANK_LOST    (CSL_EVE4_PRM_RM_EVE4_EVE4_CONTEXT_REG_LOSTMEM_EVE_BANK_LOST)

#define CSL_EVE4_PRM_RM_EVE4_EVE4_CONTEXT_REG_LOSTMEM_EVE_BANK_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_EVE4_EVE4_CONTEXT_LOSTMEM_EVE_BANK_MAINTAINED  (CSL_EVE4_PRM_RM_EVE4_EVE4_CONTEXT_REG_LOSTMEM_EVE_BANK_MAINTAINED)


#define CSL_EVE4_PRM_RM_EVE4_EVE4_CONTEXT_REG_RESETVAL          (0x00000101U)

#ifdef __cplusplus
}
#endif
#endif
