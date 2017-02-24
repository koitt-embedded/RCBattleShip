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
#ifndef _CSLR_SDMA_H_
#define _CSLR_SDMA_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for DMA_CHANNEL_REGS
**************************************************************************/
typedef struct {
    volatile Uint32 CCR_0_31;
    volatile Uint32 CLNK_CTRL_0_31;
    volatile Uint32 CICR_0_31;
    volatile Uint32 CSR_0_31;
    volatile Uint32 CSDP_0_31;
    volatile Uint32 CEN_0_31;
    volatile Uint32 CFN_0_31;
    volatile Uint32 CSSA_0_31;
    volatile Uint32 CDSA_0_31;
    volatile Uint32 CSEI_0_31;
    volatile Uint32 CSFI_0_31;
    volatile Uint32 CDEI_0_31;
    volatile Uint32 CDFI_0_31;
    volatile Uint32 CSAC_0_31;
    volatile Uint32 CDAC_0_31;
    volatile Uint32 CCEN_0_31;
    volatile Uint32 CCFN_0_31;
    volatile Uint32 COLOR_0_31;
    volatile Uint8  RSVD0[8];
    volatile Uint32 CDP_0_31;
    volatile Uint32 CNDP_0_31;
    volatile Uint32 CCDN_0_31;
    volatile Uint8  RSVD1[4];
} CSL_SdmaDma_channel_regsRegs;


/**************************************************************************
* Register Overlay Structure
**************************************************************************/
typedef struct {
    volatile Uint32 REVISION;
    volatile Uint8  RSVD2[4];
    volatile Uint32 IRQSTS_L0;
    volatile Uint32 IRQSTS_L1;
    volatile Uint32 IRQSTS_L2;
    volatile Uint32 IRQSTS_L3;
    volatile Uint32 IRQEN_L0;
    volatile Uint32 IRQEN_L1;
    volatile Uint32 IRQEN_L2;
    volatile Uint32 IRQEN_L3;
    volatile Uint32 SYSSTS;
    volatile Uint32 OCP_SYSCONFIG;
    volatile Uint8  RSVD3[52];
    volatile Uint32 CAPS_0;
    volatile Uint8  RSVD4[4];
    volatile Uint32 CAPS_2;
    volatile Uint32 CAPS_3;
    volatile Uint32 CAPS_4;
    volatile Uint32 GCR;
    volatile Uint8  RSVD5[4];
    CSL_SdmaDma_channel_regsRegs	DMA_CHANNEL_REGS[32];
} CSL_SdmaRegs;




/**************************************************************************
* Register Macros
**************************************************************************/

/* IP Revision Identifier This allows a PID showing X.Y.R in silicon to relate
 * the RTL release with a (close-to-correct) spec version X.Y.S. A peripheral
 * ID register must be included at address offset 0 of a peripherals control
 * register MAP. The purpose is to let software read the peripheral to
 * understand what type of peripheral is there and what features are enabled
 * as well as what bugs or issues may exist in a particular version. */
#define CSL_SDMA_REVISION                                       (0x0U)

/* The interrupt status register regroups all the status of the DMA4 channels
 * that can generate an interrupt over line L0. */
#define CSL_SDMA_IRQSTS_L0                                      (0x8U)

/* The interrupt status register regroups all the status of the DMA4 channels
 * that can generate an interrupt over line L1. */
#define CSL_SDMA_IRQSTS_L1                                      (0xCU)

/* The interrupt status register regroups all the status of the DMA4 channels
 * that can generate an interrupt over line L2. */
#define CSL_SDMA_IRQSTS_L2                                      (0x10U)

/* The interrupt status register regroups all the status of the DMA4 channels
 * that can generate an interrupt over line L3. */
#define CSL_SDMA_IRQSTS_L3                                      (0x14U)

/* The interrupt enable register allows to mask/unmask the module internal
 * sources of interrupt, on line L0 */
#define CSL_SDMA_IRQEN_L0                                       (0x18U)

/* The interrupt enable register allows to mask/unmask the module internal
 * sources of interrupt, on line L1 */
#define CSL_SDMA_IRQEN_L1                                       (0x1CU)

/* The interrupt enable register allows to mask/unmask the module internal
 * sources of interrupt, on line L2 */
#define CSL_SDMA_IRQEN_L2                                       (0x20U)

/* The interrupt enable register allows to mask/unmask the module internal
 * sources of interrupt, on line L3 */
#define CSL_SDMA_IRQEN_L3                                       (0x24U)

/* The register provides status information about the module excluding the
 * interrupt status information (see interrupt status register) */
#define CSL_SDMA_SYSSTS                                         (0x28U)

/* This register controls the various parameters of the OCP interface */
#define CSL_SDMA_OCP_SYSCONFIG                                  (0x2CU)

/* DMA Capabilities Register 0 LSW */
#define CSL_SDMA_CAPS_0                                         (0x64U)

/* DMA Capabilities Register 2 */
#define CSL_SDMA_CAPS_2                                         (0x6CU)

/* DMA Capabilities Register 3 */
#define CSL_SDMA_CAPS_3                                         (0x70U)

/* DMA Capabilities Register 4 */
#define CSL_SDMA_CAPS_4                                         (0x74U)

/* FIFO sharing between high and low priority channel. The Maximum per channel
 * FIFO depth is bounded by the low and high channel FIFO budget. The high
 * respectively low priority channels maximum burst size must be less than the
 * min (high respectively low priority channel FIFO budget , per channel
 * maximum FIFO depth) */
#define CSL_SDMA_GCR                                            (0x78U)

/* Channel Control Register */
#define CSL_SDMA_CCR_0_31(n)                                    (0x80U + ((n) * (0x60U)))

/* Channel Link Control Register */
#define CSL_SDMA_CLNK_CTRL_0_31(n)                              (0x84U + ((n) * (0x60U)))

/* Channel Interrupt Control Register */
#define CSL_SDMA_CICR_0_31(n)                                   (0x88U + ((n) * (0x60U)))

/* Channel Status Register */
#define CSL_SDMA_CSR_0_31(n)                                    (0x8CU + ((n) * (0x60U)))

/* Channel Source Destination Parameters */
#define CSL_SDMA_CSDP_0_31(n)                                   (0x90U + ((n) * (0x60U)))

/* Channel Element Number */
#define CSL_SDMA_CEN_0_31(n)                                    (0x94U + ((n) * (0x60U)))

/* Channel Frame Number */
#define CSL_SDMA_CFN_0_31(n)                                    (0x98U + ((n) * (0x60U)))

/* Channel Source Start Address */
#define CSL_SDMA_CSSA_0_31(n)                                   (0x9CU + ((n) * (0x60U)))

/* Channel Destination Start Address */
#define CSL_SDMA_CDSA_0_31(n)                                   (0xA0U + ((n) * (0x60U)))

/* Channel Source Element Index (Signed) */
#define CSL_SDMA_CSEI_0_31(n)                                   (0xA4U + ((n) * (0x60U)))

/* Channel Source Frame Index (Signed) or 16-bit Packet size */
#define CSL_SDMA_CSFI_0_31(n)                                   (0xA8U + ((n) * (0x60U)))

/* Channel Destination Element Index (Signed) */
#define CSL_SDMA_CDEI_0_31(n)                                   (0xACU + ((n) * (0x60U)))

/* Channel Destination Frame Index (Signed) or 16-bit Packet size */
#define CSL_SDMA_CDFI_0_31(n)                                   (0xB0U + ((n) * (0x60U)))

/* Channel Source Address Value. User has to access this register only in
 * 32-bit access. If accessed in 8-bit or 16bit data may be correupted. */
#define CSL_SDMA_CSAC_0_31(n)                                   (0xB4U + ((n) * (0x60U)))

/* Channel Destination Address Value. User has to access this register only in
 * 32-bit access. If accessed in 8-bit or 16bit data may be correupted. */
#define CSL_SDMA_CDAC_0_31(n)                                   (0xB8U + ((n) * (0x60U)))

/* Channel Current Transferred Element Number in the current frame. User has
 * to access this register only in 32-bit access. If accessed in 8-bit or
 * 16bit data may be correupted. */
#define CSL_SDMA_CCEN_0_31(n)                                   (0xBCU + ((n) * (0x60U)))

/* Channel Current Transferred Frame Number in the current transfer. User has
 * to access this register only in 32-bit access. If accessed in 8-bit or
 * 16bit data may be correupted. */
#define CSL_SDMA_CCFN_0_31(n)                                   (0xC0U + ((n) * (0x60U)))

/* Channel DMA COLOR KEY /SOLID COLOR */
#define CSL_SDMA_COLOR_0_31(n)                                  (0xC4U + ((n) * (0x60U)))

/* This register controls the various parameters of the link list mechanism */
#define CSL_SDMA_CDP_0_31(n)                                    (0xD0U + ((n) * (0x60U)))

/* This register contains the Next descriptor Address Pointer for the link
 * list Mechanism */
#define CSL_SDMA_CNDP_0_31(n)                                   (0xD4U + ((n) * (0x60U)))

/* CCDN_0_31 */
#define CSL_SDMA_CCDN_0_31(n)                                   (0xD8U + ((n) * (0x60U)))


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* REVISION */

#define CSL_SDMA_REVISION_MINOR_MASK                            (0x0000003FU)
#define CSL_SDMA_REVISION_MINOR_SHIFT                           (0U)
#define CSL_SDMA_REVISION_MINOR_RESETVAL                        (0x00000000U)
#define CSL_SDMA_REVISION_MINOR_MAX                             (0x0000003fU)

#define CSL_SDMA_REVISION_SCHEME_MASK                           (0xC0000000U)
#define CSL_SDMA_REVISION_SCHEME_SHIFT                          (30U)
#define CSL_SDMA_REVISION_SCHEME_RESETVAL                       (0x00000000U)
#define CSL_SDMA_REVISION_SCHEME_MAX                            (0x00000003U)

#define CSL_SDMA_REVISION_CUSTOM_MASK                           (0x000000C0U)
#define CSL_SDMA_REVISION_CUSTOM_SHIFT                          (6U)
#define CSL_SDMA_REVISION_CUSTOM_RESETVAL                       (0x00000000U)
#define CSL_SDMA_REVISION_CUSTOM_MAX                            (0x00000003U)

#define CSL_SDMA_REVISION_MAJOR_MASK                            (0x00000700U)
#define CSL_SDMA_REVISION_MAJOR_SHIFT                           (8U)
#define CSL_SDMA_REVISION_MAJOR_RESETVAL                        (0x00000001U)
#define CSL_SDMA_REVISION_MAJOR_MAX                             (0x00000007U)

#define CSL_SDMA_REVISION_RTL_MASK                              (0x0000F800U)
#define CSL_SDMA_REVISION_RTL_SHIFT                             (11U)
#define CSL_SDMA_REVISION_RTL_RESETVAL                          (0x00000001U)
#define CSL_SDMA_REVISION_RTL_MAX                               (0x0000001fU)

#define CSL_SDMA_REVISION_FUNC_MASK                             (0x0FFF0000U)
#define CSL_SDMA_REVISION_FUNC_SHIFT                            (16U)
#define CSL_SDMA_REVISION_FUNC_RESETVAL                         (0x00000001U)
#define CSL_SDMA_REVISION_FUNC_MAX                              (0x00000fffU)

#define CSL_SDMA_REVISION_RESETVAL                              (0x00010900U)

/* IRQSTS_L0 */

#define CSL_SDMA_IRQSTS_L0_CH_31_0_L0_MASK                      (0xFFFFFFFFU)
#define CSL_SDMA_IRQSTS_L0_CH_31_0_L0_SHIFT                     (0U)
#define CSL_SDMA_IRQSTS_L0_CH_31_0_L0_RESETVAL                  (0x00000000U)
#define CSL_SDMA_IRQSTS_L0_CH_31_0_L0_MAX                       (0xffffffffU)

#define CSL_SDMA_IRQSTS_L0_RESETVAL                             (0x00000000U)

/* IRQSTS_L1 */

#define CSL_SDMA_IRQSTS_L1_CH_31_0_L1_MASK                      (0xFFFFFFFFU)
#define CSL_SDMA_IRQSTS_L1_CH_31_0_L1_SHIFT                     (0U)
#define CSL_SDMA_IRQSTS_L1_CH_31_0_L1_RESETVAL                  (0x00000000U)
#define CSL_SDMA_IRQSTS_L1_CH_31_0_L1_MAX                       (0xffffffffU)

#define CSL_SDMA_IRQSTS_L1_RESETVAL                             (0x00000000U)

/* IRQSTS_L2 */

#define CSL_SDMA_IRQSTS_L2_CH_31_0_L2_MASK                      (0xFFFFFFFFU)
#define CSL_SDMA_IRQSTS_L2_CH_31_0_L2_SHIFT                     (0U)
#define CSL_SDMA_IRQSTS_L2_CH_31_0_L2_RESETVAL                  (0x00000000U)
#define CSL_SDMA_IRQSTS_L2_CH_31_0_L2_MAX                       (0xffffffffU)

#define CSL_SDMA_IRQSTS_L2_RESETVAL                             (0x00000000U)

/* IRQSTS_L3 */

#define CSL_SDMA_IRQSTS_L3_CH_31_0_L3_MASK                      (0xFFFFFFFFU)
#define CSL_SDMA_IRQSTS_L3_CH_31_0_L3_SHIFT                     (0U)
#define CSL_SDMA_IRQSTS_L3_CH_31_0_L3_RESETVAL                  (0x00000000U)
#define CSL_SDMA_IRQSTS_L3_CH_31_0_L3_MAX                       (0xffffffffU)

#define CSL_SDMA_IRQSTS_L3_RESETVAL                             (0x00000000U)

/* IRQEN_L0 */

#define CSL_SDMA_IRQEN_L0_CH_31_0_L0_EN_MASK                    (0xFFFFFFFFU)
#define CSL_SDMA_IRQEN_L0_CH_31_0_L0_EN_SHIFT                   (0U)
#define CSL_SDMA_IRQEN_L0_CH_31_0_L0_EN_RESETVAL                (0x00000000U)
#define CSL_SDMA_IRQEN_L0_CH_31_0_L0_EN_MAX                     (0xffffffffU)

#define CSL_SDMA_IRQEN_L0_RESETVAL                              (0x00000000U)

/* IRQEN_L1 */

#define CSL_SDMA_IRQEN_L1_CH_0_L1_EN_MASK                       (0xFFFFFFFFU)
#define CSL_SDMA_IRQEN_L1_CH_0_L1_EN_SHIFT                      (0U)
#define CSL_SDMA_IRQEN_L1_CH_0_L1_EN_RESETVAL                   (0x00000000U)
#define CSL_SDMA_IRQEN_L1_CH_0_L1_EN_MAX                        (0xffffffffU)

#define CSL_SDMA_IRQEN_L1_RESETVAL                              (0x00000000U)

/* IRQEN_L2 */

#define CSL_SDMA_IRQEN_L2_CH_31_0_L2_EN_MASK                    (0xFFFFFFFFU)
#define CSL_SDMA_IRQEN_L2_CH_31_0_L2_EN_SHIFT                   (0U)
#define CSL_SDMA_IRQEN_L2_CH_31_0_L2_EN_RESETVAL                (0x00000000U)
#define CSL_SDMA_IRQEN_L2_CH_31_0_L2_EN_MAX                     (0xffffffffU)

#define CSL_SDMA_IRQEN_L2_RESETVAL                              (0x00000000U)

/* IRQEN_L3 */

#define CSL_SDMA_IRQEN_L3_CH_31_0_L3_EN_MASK                    (0xFFFFFFFFU)
#define CSL_SDMA_IRQEN_L3_CH_31_0_L3_EN_SHIFT                   (0U)
#define CSL_SDMA_IRQEN_L3_CH_31_0_L3_EN_RESETVAL                (0x00000000U)
#define CSL_SDMA_IRQEN_L3_CH_31_0_L3_EN_MAX                     (0xffffffffU)

#define CSL_SDMA_IRQEN_L3_RESETVAL                              (0x00000000U)

/* SYSSTS */

#define CSL_SDMA_SYSSTS_RESETDONE_MASK                          (0x00000001U)
#define CSL_SDMA_SYSSTS_RESETDONE_SHIFT                         (0U)
#define CSL_SDMA_SYSSTS_RESETDONE_RESETVAL                      (0x00000000U)
#define CSL_SDMA_SYSSTS_RESETDONE_ONGOING                       (0x00000000U)
#define CSL_SDMA_SYSSTS_RESETDONE_COMPLETED                     (0x00000001U)

#define CSL_SDMA_SYSSTS_RESETVAL                                (0x00000000U)

/* OCP_SYSCONFIG */

#define CSL_SDMA_OCP_SYSCONFIG_CLOCKACTIVITY_MASK               (0x00000300U)
#define CSL_SDMA_OCP_SYSCONFIG_CLOCKACTIVITY_SHIFT              (8U)
#define CSL_SDMA_OCP_SYSCONFIG_CLOCKACTIVITY_RESETVAL           (0x00000000U)
#define CSL_SDMA_OCP_SYSCONFIG_CLOCKACTIVITY_MAX                (0x00000003U)

#define CSL_SDMA_OCP_SYSCONFIG_SOFTRESET_MASK                   (0x00000002U)
#define CSL_SDMA_OCP_SYSCONFIG_SOFTRESET_SHIFT                  (1U)
#define CSL_SDMA_OCP_SYSCONFIG_SOFTRESET_RESETVAL               (0x00000000U)
#define CSL_SDMA_OCP_SYSCONFIG_SOFTRESET_NOEFFECT               (0x00000000U)
#define CSL_SDMA_OCP_SYSCONFIG_SOFTRESET_RESET                  (0x00000001U)

#define CSL_SDMA_OCP_SYSCONFIG_SIDLEMODE_MASK                   (0x00000018U)
#define CSL_SDMA_OCP_SYSCONFIG_SIDLEMODE_SHIFT                  (3U)
#define CSL_SDMA_OCP_SYSCONFIG_SIDLEMODE_RESETVAL               (0x00000000U)
#define CSL_SDMA_OCP_SYSCONFIG_SIDLEMODE_FORCE                  (0x00000000U)
#define CSL_SDMA_OCP_SYSCONFIG_SIDLEMODE_NO                     (0x00000001U)
#define CSL_SDMA_OCP_SYSCONFIG_SIDLEMODE_SMART                  (0x00000002U)
#define CSL_SDMA_OCP_SYSCONFIG_SIDLEMODE_RESERVED               (0x00000003U)

#define CSL_SDMA_OCP_SYSCONFIG_AUTOIDLE_MASK                    (0x00000001U)
#define CSL_SDMA_OCP_SYSCONFIG_AUTOIDLE_SHIFT                   (0U)
#define CSL_SDMA_OCP_SYSCONFIG_AUTOIDLE_RESETVAL                (0x00000000U)
#define CSL_SDMA_OCP_SYSCONFIG_AUTOIDLE_FREERUNNING             (0x00000000U)
#define CSL_SDMA_OCP_SYSCONFIG_AUTOIDLE_CLOCKGATING             (0x00000001U)

#define CSL_SDMA_OCP_SYSCONFIG_MIDLEMODE_MASK                   (0x00003000U)
#define CSL_SDMA_OCP_SYSCONFIG_MIDLEMODE_SHIFT                  (12U)
#define CSL_SDMA_OCP_SYSCONFIG_MIDLEMODE_RESETVAL               (0x00000000U)
#define CSL_SDMA_OCP_SYSCONFIG_MIDLEMODE_FORCE                  (0x00000000U)
#define CSL_SDMA_OCP_SYSCONFIG_MIDLEMODE_NO                     (0x00000001U)
#define CSL_SDMA_OCP_SYSCONFIG_MIDLEMODE_SMART                  (0x00000002U)
#define CSL_SDMA_OCP_SYSCONFIG_MIDLEMODE_RESERVED               (0x00000003U)

#define CSL_SDMA_OCP_SYSCONFIG_EMUFREE_MASK                     (0x00000020U)
#define CSL_SDMA_OCP_SYSCONFIG_EMUFREE_SHIFT                    (5U)
#define CSL_SDMA_OCP_SYSCONFIG_EMUFREE_RESETVAL                 (0x00000000U)
#define CSL_SDMA_OCP_SYSCONFIG_EMUFREE_FROZEN                   (0x00000000U)
#define CSL_SDMA_OCP_SYSCONFIG_EMUFREE_IGNORED                  (0x00000001U)

#define CSL_SDMA_OCP_SYSCONFIG_RESETVAL                         (0x00000000U)

/* CAPS_0 */

#define CSL_SDMA_CAPS_0_CONST_FILL_CPBLTY_MASK                  (0x00080000U)
#define CSL_SDMA_CAPS_0_CONST_FILL_CPBLTY_SHIFT                 (19U)
#define CSL_SDMA_CAPS_0_CONST_FILL_CPBLTY_RESETVAL              (0x00000001U)
#define CSL_SDMA_CAPS_0_CONST_FILL_CPBLTY_NOLCH                 (0x00000000U)
#define CSL_SDMA_CAPS_0_CONST_FILL_CPBLTY_ANYLCH                (0x00000001U)

#define CSL_SDMA_CAPS_0_TRANSPARENT_BLT_CPBLTY_MASK             (0x00040000U)
#define CSL_SDMA_CAPS_0_TRANSPARENT_BLT_CPBLTY_SHIFT            (18U)
#define CSL_SDMA_CAPS_0_TRANSPARENT_BLT_CPBLTY_RESETVAL         (0x00000001U)
#define CSL_SDMA_CAPS_0_TRANSPARENT_BLT_CPBLTY_NOLCH            (0x00000000U)
#define CSL_SDMA_CAPS_0_TRANSPARENT_BLT_CPBLTY_ANYLCH           (0x00000001U)

#define CSL_SDMA_CAPS_0_LINK_LIST_CPBLTY_TYPE123_MASK           (0x00100000U)
#define CSL_SDMA_CAPS_0_LINK_LIST_CPBLTY_TYPE123_SHIFT          (20U)
#define CSL_SDMA_CAPS_0_LINK_LIST_CPBLTY_TYPE123_RESETVAL       (0x00000001U)
#define CSL_SDMA_CAPS_0_LINK_LIST_CPBLTY_TYPE123_MAX            (0x00000001U)

#define CSL_SDMA_CAPS_0_LINK_LIST_CPBLTY_TYPE4_MASK             (0x00200000U)
#define CSL_SDMA_CAPS_0_LINK_LIST_CPBLTY_TYPE4_SHIFT            (21U)
#define CSL_SDMA_CAPS_0_LINK_LIST_CPBLTY_TYPE4_RESETVAL         (0x00000000U)
#define CSL_SDMA_CAPS_0_LINK_LIST_CPBLTY_TYPE4_MAX              (0x00000001U)

#define CSL_SDMA_CAPS_0_RESETVAL                                (0x001c0000U)

/* CAPS_2 */

#define CSL_SDMA_CAPS_2_SRC_CONST_ADRS_CPBLTY_MASK              (0x00000001U)
#define CSL_SDMA_CAPS_2_SRC_CONST_ADRS_CPBLTY_SHIFT             (0U)
#define CSL_SDMA_CAPS_2_SRC_CONST_ADRS_CPBLTY_RESETVAL          (0x00000001U)
#define CSL_SDMA_CAPS_2_SRC_CONST_ADRS_CPBLTY_SUPPORTED         (0x00000001U)
#define CSL_SDMA_CAPS_2_SRC_CONST_ADRS_CPBLTY_NOTSUPPORTED      (0x00000000U)

#define CSL_SDMA_CAPS_2_SRC_SINGLE_IDX_ADRS_CPBLTY_MASK         (0x00000004U)
#define CSL_SDMA_CAPS_2_SRC_SINGLE_IDX_ADRS_CPBLTY_SHIFT        (2U)
#define CSL_SDMA_CAPS_2_SRC_SINGLE_IDX_ADRS_CPBLTY_RESETVAL     (0x00000001U)
#define CSL_SDMA_CAPS_2_SRC_SINGLE_IDX_ADRS_CPBLTY_SUPPORTED    (0x00000001U)
#define CSL_SDMA_CAPS_2_SRC_SINGLE_IDX_ADRS_CPBLTY_NOTSUPPORTED  (0x00000000U)

#define CSL_SDMA_CAPS_2_DST_CONST_ADRS_CPBLTY_MASK              (0x00000010U)
#define CSL_SDMA_CAPS_2_DST_CONST_ADRS_CPBLTY_SHIFT             (4U)
#define CSL_SDMA_CAPS_2_DST_CONST_ADRS_CPBLTY_RESETVAL          (0x00000001U)
#define CSL_SDMA_CAPS_2_DST_CONST_ADRS_CPBLTY_SUPPORTED         (0x00000001U)
#define CSL_SDMA_CAPS_2_DST_CONST_ADRS_CPBLTY_NOTSUPPORTED      (0x00000000U)

#define CSL_SDMA_CAPS_2_DST_SINGLE_IDX_ADRS_CPBLTY_MASK         (0x00000040U)
#define CSL_SDMA_CAPS_2_DST_SINGLE_IDX_ADRS_CPBLTY_SHIFT        (6U)
#define CSL_SDMA_CAPS_2_DST_SINGLE_IDX_ADRS_CPBLTY_RESETVAL     (0x00000001U)
#define CSL_SDMA_CAPS_2_DST_SINGLE_IDX_ADRS_CPBLTY_SUPPORTED    (0x00000001U)
#define CSL_SDMA_CAPS_2_DST_SINGLE_IDX_ADRS_CPBLTY_NOTSUPPORTED  (0x00000000U)

#define CSL_SDMA_CAPS_2_SEPARATE_SRC_AND_DST_IDX_CPBLTY_MASK    (0x00000100U)
#define CSL_SDMA_CAPS_2_SEPARATE_SRC_AND_DST_IDX_CPBLTY_SHIFT   (8U)
#define CSL_SDMA_CAPS_2_SEPARATE_SRC_AND_DST_IDX_CPBLTY_RESETVAL  (0x00000001U)
#define CSL_SDMA_CAPS_2_SEPARATE_SRC_AND_DST_IDX_CPBLTY_SUPPORTED  (0x00000001U)
#define CSL_SDMA_CAPS_2_SEPARATE_SRC_AND_DST_IDX_CPBLTY_NOTSUPPORTED  (0x00000000U)

#define CSL_SDMA_CAPS_2_SRC_POST_INCREMENT_ADRS_CPBLTY_MASK     (0x00000002U)
#define CSL_SDMA_CAPS_2_SRC_POST_INCREMENT_ADRS_CPBLTY_SHIFT    (1U)
#define CSL_SDMA_CAPS_2_SRC_POST_INCREMENT_ADRS_CPBLTY_RESETVAL  (0x00000001U)
#define CSL_SDMA_CAPS_2_SRC_POST_INCREMENT_ADRS_CPBLTY_SUPPORTED  (0x00000001U)
#define CSL_SDMA_CAPS_2_SRC_POST_INCREMENT_ADRS_CPBLTY_NOTSUPPORTED  (0x00000000U)

#define CSL_SDMA_CAPS_2_SRC_DOUBLE_IDX_ADRS_CPBLTY_MASK         (0x00000008U)
#define CSL_SDMA_CAPS_2_SRC_DOUBLE_IDX_ADRS_CPBLTY_SHIFT        (3U)
#define CSL_SDMA_CAPS_2_SRC_DOUBLE_IDX_ADRS_CPBLTY_RESETVAL     (0x00000001U)
#define CSL_SDMA_CAPS_2_SRC_DOUBLE_IDX_ADRS_CPBLTY_SUPPORTED    (0x00000001U)
#define CSL_SDMA_CAPS_2_SRC_DOUBLE_IDX_ADRS_CPBLTY_NOTSUPPORTED  (0x00000000U)

#define CSL_SDMA_CAPS_2_DST_POST_INCRMNT_ADRS_CPBLTY_MASK       (0x00000020U)
#define CSL_SDMA_CAPS_2_DST_POST_INCRMNT_ADRS_CPBLTY_SHIFT      (5U)
#define CSL_SDMA_CAPS_2_DST_POST_INCRMNT_ADRS_CPBLTY_RESETVAL   (0x00000001U)
#define CSL_SDMA_CAPS_2_DST_POST_INCRMNT_ADRS_CPBLTY_SUPPORTED  (0x00000001U)
#define CSL_SDMA_CAPS_2_DST_POST_INCRMNT_ADRS_CPBLTY_NOTSUPPORTED  (0x00000000U)

#define CSL_SDMA_CAPS_2_DST_DOUBLE_IDX_ADRS_CPBLTY_MASK         (0x00000080U)
#define CSL_SDMA_CAPS_2_DST_DOUBLE_IDX_ADRS_CPBLTY_SHIFT        (7U)
#define CSL_SDMA_CAPS_2_DST_DOUBLE_IDX_ADRS_CPBLTY_RESETVAL     (0x00000001U)
#define CSL_SDMA_CAPS_2_DST_DOUBLE_IDX_ADRS_CPBLTY_SUPPORTED    (0x00000001U)
#define CSL_SDMA_CAPS_2_DST_DOUBLE_IDX_ADRS_CPBLTY_NOTSUPPORTED  (0x00000000U)

#define CSL_SDMA_CAPS_2_RESETVAL                                (0x000001ffU)

/* CAPS_3 */

#define CSL_SDMA_CAPS_3_BLOCK_SYNCHR_CPBLTY_MASK                (0x00000080U)
#define CSL_SDMA_CAPS_3_BLOCK_SYNCHR_CPBLTY_SHIFT               (7U)
#define CSL_SDMA_CAPS_3_BLOCK_SYNCHR_CPBLTY_RESETVAL            (0x00000001U)
#define CSL_SDMA_CAPS_3_BLOCK_SYNCHR_CPBLTY_SUPPORTED           (0x00000001U)
#define CSL_SDMA_CAPS_3_BLOCK_SYNCHR_CPBLTY_NOTSUPPORTED        (0x00000000U)

#define CSL_SDMA_CAPS_3_PKT_SYNCHR_CPBLTY_MASK                  (0x00000040U)
#define CSL_SDMA_CAPS_3_PKT_SYNCHR_CPBLTY_SHIFT                 (6U)
#define CSL_SDMA_CAPS_3_PKT_SYNCHR_CPBLTY_RESETVAL              (0x00000001U)
#define CSL_SDMA_CAPS_3_PKT_SYNCHR_CPBLTY_SUPPORTED             (0x00000001U)
#define CSL_SDMA_CAPS_3_PKT_SYNCHR_CPBLTY_NOTSUPPORTED          (0x00000000U)

#define CSL_SDMA_CAPS_3_ELMNT_SYNCHR_CPBLTY_MASK                (0x00000001U)
#define CSL_SDMA_CAPS_3_ELMNT_SYNCHR_CPBLTY_SHIFT               (0U)
#define CSL_SDMA_CAPS_3_ELMNT_SYNCHR_CPBLTY_RESETVAL            (0x00000001U)
#define CSL_SDMA_CAPS_3_ELMNT_SYNCHR_CPBLTY_MAX                 (0x00000001U)

#define CSL_SDMA_CAPS_3_FRM_SYNCHR_CPBLTY_MASK                  (0x00000002U)
#define CSL_SDMA_CAPS_3_FRM_SYNCHR_CPBLTY_SHIFT                 (1U)
#define CSL_SDMA_CAPS_3_FRM_SYNCHR_CPBLTY_RESETVAL              (0x00000001U)
#define CSL_SDMA_CAPS_3_FRM_SYNCHR_CPBLTY_MAX                   (0x00000001U)

#define CSL_SDMA_CAPS_3_CHANNEL_INTERLEAVE_CPBLTY_MASK          (0x00000010U)
#define CSL_SDMA_CAPS_3_CHANNEL_INTERLEAVE_CPBLTY_SHIFT         (4U)
#define CSL_SDMA_CAPS_3_CHANNEL_INTERLEAVE_CPBLTY_RESETVAL      (0x00000001U)
#define CSL_SDMA_CAPS_3_CHANNEL_INTERLEAVE_CPBLTY_MAX           (0x00000001U)

#define CSL_SDMA_CAPS_3_CHANNEL_CHANINIG_CPBLTY_MASK            (0x00000020U)
#define CSL_SDMA_CAPS_3_CHANNEL_CHANINIG_CPBLTY_SHIFT           (5U)
#define CSL_SDMA_CAPS_3_CHANNEL_CHANINIG_CPBLTY_RESETVAL        (0x00000001U)
#define CSL_SDMA_CAPS_3_CHANNEL_CHANINIG_CPBLTY_MAX             (0x00000001U)

#define CSL_SDMA_CAPS_3_RESETVAL                                (0x000000f3U)

/* CAPS_4 */

#define CSL_SDMA_CAPS_4_EVT_DROP_INTR_CPBLTY_MASK               (0x00000002U)
#define CSL_SDMA_CAPS_4_EVT_DROP_INTR_CPBLTY_SHIFT              (1U)
#define CSL_SDMA_CAPS_4_EVT_DROP_INTR_CPBLTY_RESETVAL           (0x00000001U)
#define CSL_SDMA_CAPS_4_EVT_DROP_INTR_CPBLTY_SUPPORTED          (0x00000001U)
#define CSL_SDMA_CAPS_4_EVT_DROP_INTR_CPBLTY_NOTSUPPORTED       (0x00000000U)

#define CSL_SDMA_CAPS_4_FRM_INTR_CPBLTY_MASK                    (0x00000008U)
#define CSL_SDMA_CAPS_4_FRM_INTR_CPBLTY_SHIFT                   (3U)
#define CSL_SDMA_CAPS_4_FRM_INTR_CPBLTY_RESETVAL                (0x00000001U)
#define CSL_SDMA_CAPS_4_FRM_INTR_CPBLTY_SUPPORTED               (0x00000001U)
#define CSL_SDMA_CAPS_4_FRM_INTR_CPBLTY_NOTSUPPORTED            (0x00000000U)

#define CSL_SDMA_CAPS_4_BLOCK_INTR_CPBLTY_MASK                  (0x00000020U)
#define CSL_SDMA_CAPS_4_BLOCK_INTR_CPBLTY_SHIFT                 (5U)
#define CSL_SDMA_CAPS_4_BLOCK_INTR_CPBLTY_RESETVAL              (0x00000001U)
#define CSL_SDMA_CAPS_4_BLOCK_INTR_CPBLTY_SUPPORTED             (0x00000001U)
#define CSL_SDMA_CAPS_4_BLOCK_INTR_CPBLTY_NOTSUPPORTED          (0x00000000U)

#define CSL_SDMA_CAPS_4_PKT_INTR_CPBLTY_MASK                    (0x00000080U)
#define CSL_SDMA_CAPS_4_PKT_INTR_CPBLTY_SHIFT                   (7U)
#define CSL_SDMA_CAPS_4_PKT_INTR_CPBLTY_RESETVAL                (0x00000001U)
#define CSL_SDMA_CAPS_4_PKT_INTR_CPBLTY_SUPPORTED               (0x00000001U)
#define CSL_SDMA_CAPS_4_PKT_INTR_CPBLTY_NOTSUPPORTED            (0x00000000U)

#define CSL_SDMA_CAPS_4_HALF_FRM_INTR_CPBLTY_MASK               (0x00000004U)
#define CSL_SDMA_CAPS_4_HALF_FRM_INTR_CPBLTY_SHIFT              (2U)
#define CSL_SDMA_CAPS_4_HALF_FRM_INTR_CPBLTY_RESETVAL           (0x00000001U)
#define CSL_SDMA_CAPS_4_HALF_FRM_INTR_CPBLTY_SUPPORTED          (0x00000001U)
#define CSL_SDMA_CAPS_4_HALF_FRM_INTR_CPBLTY_NOTSUPPORTED       (0x00000000U)

#define CSL_SDMA_CAPS_4_LAST_FRM_INTR_CPBLTY_MASK               (0x00000010U)
#define CSL_SDMA_CAPS_4_LAST_FRM_INTR_CPBLTY_SHIFT              (4U)
#define CSL_SDMA_CAPS_4_LAST_FRM_INTR_CPBLTY_RESETVAL           (0x00000001U)
#define CSL_SDMA_CAPS_4_LAST_FRM_INTR_CPBLTY_SUPPORTED          (0x00000001U)
#define CSL_SDMA_CAPS_4_LAST_FRM_INTR_CPBLTY_NOTSUPPORTED       (0x00000000U)

#define CSL_SDMA_CAPS_4_SYNC_STS_CPBLTY_MASK                    (0x00000040U)
#define CSL_SDMA_CAPS_4_SYNC_STS_CPBLTY_SHIFT                   (6U)
#define CSL_SDMA_CAPS_4_SYNC_STS_CPBLTY_RESETVAL                (0x00000001U)
#define CSL_SDMA_CAPS_4_SYNC_STS_CPBLTY_SUPPORTED               (0x00000001U)
#define CSL_SDMA_CAPS_4_SYNC_STS_CPBLTY_NOTSUPPORTED            (0x00000000U)

#define CSL_SDMA_CAPS_4_TRANS_ERR_INTR_CPBLTY_MASK              (0x00000100U)
#define CSL_SDMA_CAPS_4_TRANS_ERR_INTR_CPBLTY_SHIFT             (8U)
#define CSL_SDMA_CAPS_4_TRANS_ERR_INTR_CPBLTY_RESETVAL          (0x00000001U)
#define CSL_SDMA_CAPS_4_TRANS_ERR_INTR_CPBLTY_MAX               (0x00000001U)

#define CSL_SDMA_CAPS_4_SECURE_ERR_INTR_CPBLTY_MASK             (0x00000200U)
#define CSL_SDMA_CAPS_4_SECURE_ERR_INTR_CPBLTY_SHIFT            (9U)
#define CSL_SDMA_CAPS_4_SECURE_ERR_INTR_CPBLTY_RESETVAL         (0x00000001U)
#define CSL_SDMA_CAPS_4_SECURE_ERR_INTR_CPBLTY_MAX              (0x00000001U)

#define CSL_SDMA_CAPS_4_SUPERVISOR_ERR_INTR_CPBLTY_MASK         (0x00000400U)
#define CSL_SDMA_CAPS_4_SUPERVISOR_ERR_INTR_CPBLTY_SHIFT        (10U)
#define CSL_SDMA_CAPS_4_SUPERVISOR_ERR_INTR_CPBLTY_RESETVAL     (0x00000001U)
#define CSL_SDMA_CAPS_4_SUPERVISOR_ERR_INTR_CPBLTY_MAX          (0x00000001U)

#define CSL_SDMA_CAPS_4_MISALIGNED_ADRS_ERR_INTR_CPBLTY_MASK    (0x00000800U)
#define CSL_SDMA_CAPS_4_MISALIGNED_ADRS_ERR_INTR_CPBLTY_SHIFT   (11U)
#define CSL_SDMA_CAPS_4_MISALIGNED_ADRS_ERR_INTR_CPBLTY_RESETVAL  (0x00000001U)
#define CSL_SDMA_CAPS_4_MISALIGNED_ADRS_ERR_INTR_CPBLTY_MAX     (0x00000001U)

#define CSL_SDMA_CAPS_4_DRAIN_END_INTR_CPBLTY_MASK              (0x00001000U)
#define CSL_SDMA_CAPS_4_DRAIN_END_INTR_CPBLTY_SHIFT             (12U)
#define CSL_SDMA_CAPS_4_DRAIN_END_INTR_CPBLTY_RESETVAL          (0x00000001U)
#define CSL_SDMA_CAPS_4_DRAIN_END_INTR_CPBLTY_MAX               (0x00000001U)

#define CSL_SDMA_CAPS_4_DOMAIN_ERR_INTR_CPBLTY_MASK             (0x00002000U)
#define CSL_SDMA_CAPS_4_DOMAIN_ERR_INTR_CPBLTY_SHIFT            (13U)
#define CSL_SDMA_CAPS_4_DOMAIN_ERR_INTR_CPBLTY_RESETVAL         (0x00000001U)
#define CSL_SDMA_CAPS_4_DOMAIN_ERR_INTR_CPBLTY_MAX              (0x00000001U)

#define CSL_SDMA_CAPS_4_EOSB_INTR_CPBLTY_MASK                   (0x00004000U)
#define CSL_SDMA_CAPS_4_EOSB_INTR_CPBLTY_SHIFT                  (14U)
#define CSL_SDMA_CAPS_4_EOSB_INTR_CPBLTY_RESETVAL               (0x00000001U)
#define CSL_SDMA_CAPS_4_EOSB_INTR_CPBLTY_MAX                    (0x00000001U)

#define CSL_SDMA_CAPS_4_RESETVAL                                (0x00007ffeU)

/* GCR */

#define CSL_SDMA_GCR_ARBITRATION_RATE_MASK                      (0x00FF0000U)
#define CSL_SDMA_GCR_ARBITRATION_RATE_SHIFT                     (16U)
#define CSL_SDMA_GCR_ARBITRATION_RATE_RESETVAL                  (0x00000001U)
#define CSL_SDMA_GCR_ARBITRATION_RATE_MAX                       (0x000000ffU)

#define CSL_SDMA_GCR_MAX_CHANNEL_FIFO_DEPTH_MASK                (0x000000FFU)
#define CSL_SDMA_GCR_MAX_CHANNEL_FIFO_DEPTH_SHIFT               (0U)
#define CSL_SDMA_GCR_MAX_CHANNEL_FIFO_DEPTH_RESETVAL            (0x00000010U)
#define CSL_SDMA_GCR_MAX_CHANNEL_FIFO_DEPTH_MAX                 (0x000000ffU)

#define CSL_SDMA_GCR_HI_LO_FIFO_BUDGET_MASK                     (0x0000C000U)
#define CSL_SDMA_GCR_HI_LO_FIFO_BUDGET_SHIFT                    (14U)
#define CSL_SDMA_GCR_HI_LO_FIFO_BUDGET_RESETVAL                 (0x00000000U)
#define CSL_SDMA_GCR_HI_LO_FIFO_BUDGET_MAX                      (0x00000003U)

#define CSL_SDMA_GCR_CHANNEL_ID_GATE_MASK                       (0x01000000U)
#define CSL_SDMA_GCR_CHANNEL_ID_GATE_SHIFT                      (24U)
#define CSL_SDMA_GCR_CHANNEL_ID_GATE_RESETVAL                   (0x00000000U)
#define CSL_SDMA_GCR_CHANNEL_ID_GATE_MAX                        (0x00000001U)

#define CSL_SDMA_GCR_RESETVAL                                   (0x00010010U)

/* CCR_0_31 */

#define CSL_SDMA_CCR_0_31_DST_AMODE_MASK                        (0x0000C000U)
#define CSL_SDMA_CCR_0_31_DST_AMODE_SHIFT                       (14U)
#define CSL_SDMA_CCR_0_31_DST_AMODE_RESETVAL                    (0x00000000U)
#define CSL_SDMA_CCR_0_31_DST_AMODE_CONSTANT                    (0x00000000U)
#define CSL_SDMA_CCR_0_31_DST_AMODE_POSTINCREMENTED             (0x00000001U)
#define CSL_SDMA_CCR_0_31_DST_AMODE_SINGLEINDEX                 (0x00000002U)
#define CSL_SDMA_CCR_0_31_DST_AMODE_DOUBLEINDEX                 (0x00000003U)

#define CSL_SDMA_CCR_0_31_TRANSPARENT_COPY_EN_MASK              (0x00020000U)
#define CSL_SDMA_CCR_0_31_TRANSPARENT_COPY_EN_SHIFT             (17U)
#define CSL_SDMA_CCR_0_31_TRANSPARENT_COPY_EN_RESETVAL          (0x00000000U)
#define CSL_SDMA_CCR_0_31_TRANSPARENT_COPY_EN_ENABLED           (0x00000001U)
#define CSL_SDMA_CCR_0_31_TRANSPARENT_COPY_EN_DISABLED          (0x00000000U)

#define CSL_SDMA_CCR_0_31_EN_MASK                               (0x00000080U)
#define CSL_SDMA_CCR_0_31_EN_SHIFT                              (7U)
#define CSL_SDMA_CCR_0_31_EN_RESETVAL                           (0x00000000U)
#define CSL_SDMA_CCR_0_31_EN_ENABLED                            (0x00000001U)
#define CSL_SDMA_CCR_0_31_EN_DISABLED                           (0x00000000U)

#define CSL_SDMA_CCR_0_31_RD_ACTIVE_MASK                        (0x00000200U)
#define CSL_SDMA_CCR_0_31_RD_ACTIVE_SHIFT                       (9U)
#define CSL_SDMA_CCR_0_31_RD_ACTIVE_RESETVAL                    (0x00000000U)
#define CSL_SDMA_CCR_0_31_RD_ACTIVE_ACTIVE                      (0x00000001U)
#define CSL_SDMA_CCR_0_31_RD_ACTIVE_NOTACTIVE                   (0x00000000U)

#define CSL_SDMA_CCR_0_31_READ_PRIORITY_MASK                    (0x00000040U)
#define CSL_SDMA_CCR_0_31_READ_PRIORITY_SHIFT                   (6U)
#define CSL_SDMA_CCR_0_31_READ_PRIORITY_RESETVAL                (0x00000000U)
#define CSL_SDMA_CCR_0_31_READ_PRIORITY_HIGH                    (0x00000001U)
#define CSL_SDMA_CCR_0_31_READ_PRIORITY_LOW                     (0x00000000U)

#define CSL_SDMA_CCR_0_31_SUSPEND_SENSITIVE_MASK                (0x00000100U)
#define CSL_SDMA_CCR_0_31_SUSPEND_SENSITIVE_SHIFT               (8U)
#define CSL_SDMA_CCR_0_31_SUSPEND_SENSITIVE_RESETVAL            (0x00000000U)
#define CSL_SDMA_CCR_0_31_SUSPEND_SENSITIVE_MUSTCOMPLETE        (0x00000001U)
#define CSL_SDMA_CCR_0_31_SUSPEND_SENSITIVE_IGNORED             (0x00000000U)

#define CSL_SDMA_CCR_0_31_WR_ACTIVE_MASK                        (0x00000400U)
#define CSL_SDMA_CCR_0_31_WR_ACTIVE_SHIFT                       (10U)
#define CSL_SDMA_CCR_0_31_WR_ACTIVE_RESETVAL                    (0x00000000U)
#define CSL_SDMA_CCR_0_31_WR_ACTIVE_ACTIVE                      (0x00000001U)
#define CSL_SDMA_CCR_0_31_WR_ACTIVE_NOTACTIVE                   (0x00000000U)

#define CSL_SDMA_CCR_0_31_SYNCHRO_CTRL_MASK                     (0x0000001FU)
#define CSL_SDMA_CCR_0_31_SYNCHRO_CTRL_SHIFT                    (0U)
#define CSL_SDMA_CCR_0_31_SYNCHRO_CTRL_RESETVAL                 (0x00000000U)
#define CSL_SDMA_CCR_0_31_SYNCHRO_CTRL_MAX                      (0x0000001fU)

#define CSL_SDMA_CCR_0_31_FS_MASK                               (0x00000020U)
#define CSL_SDMA_CCR_0_31_FS_SHIFT                              (5U)
#define CSL_SDMA_CCR_0_31_FS_RESETVAL                           (0x00000000U)
#define CSL_SDMA_CCR_0_31_FS_MAX                                (0x00000001U)

#define CSL_SDMA_CCR_0_31_SYNCHRO_CTRL_UPPER_MASK               (0x00180000U)
#define CSL_SDMA_CCR_0_31_SYNCHRO_CTRL_UPPER_SHIFT              (19U)
#define CSL_SDMA_CCR_0_31_SYNCHRO_CTRL_UPPER_RESETVAL           (0x00000000U)
#define CSL_SDMA_CCR_0_31_SYNCHRO_CTRL_UPPER_MAX                (0x00000003U)

#define CSL_SDMA_CCR_0_31_SUPERVISOR_MASK                       (0x00400000U)
#define CSL_SDMA_CCR_0_31_SUPERVISOR_SHIFT                      (22U)
#define CSL_SDMA_CCR_0_31_SUPERVISOR_RESETVAL                   (0x00000000U)
#define CSL_SDMA_CCR_0_31_SUPERVISOR_ENABLED                    (0x00000001U)
#define CSL_SDMA_CCR_0_31_SUPERVISOR_DISABLED                   (0x00000000U)

#define CSL_SDMA_CCR_0_31_SEL_SRC_DST_SYNC_MASK                 (0x01000000U)
#define CSL_SDMA_CCR_0_31_SEL_SRC_DST_SYNC_SHIFT                (24U)
#define CSL_SDMA_CCR_0_31_SEL_SRC_DST_SYNC_RESETVAL             (0x00000000U)
#define CSL_SDMA_CCR_0_31_SEL_SRC_DST_SYNC_SOURCE               (0x00000001U)
#define CSL_SDMA_CCR_0_31_SEL_SRC_DST_SYNC_DESTINATION          (0x00000000U)

#define CSL_SDMA_CCR_0_31_CONST_FILL_EN_MASK                    (0x00010000U)
#define CSL_SDMA_CCR_0_31_CONST_FILL_EN_SHIFT                   (16U)
#define CSL_SDMA_CCR_0_31_CONST_FILL_EN_RESETVAL                (0x00000000U)
#define CSL_SDMA_CCR_0_31_CONST_FILL_EN_ENABLED                 (0x00000001U)
#define CSL_SDMA_CCR_0_31_CONST_FILL_EN_DISABLED                (0x00000000U)

#define CSL_SDMA_CCR_0_31_BS_MASK                               (0x00040000U)
#define CSL_SDMA_CCR_0_31_BS_SHIFT                              (18U)
#define CSL_SDMA_CCR_0_31_BS_RESETVAL                           (0x00000000U)
#define CSL_SDMA_CCR_0_31_BS_MAX                                (0x00000001U)

#define CSL_SDMA_CCR_0_31_SECURE_MASK                           (0x00200000U)
#define CSL_SDMA_CCR_0_31_SECURE_SHIFT                          (21U)
#define CSL_SDMA_CCR_0_31_SECURE_RESETVAL                       (0x00000000U)
#define CSL_SDMA_CCR_0_31_SECURE_ENABLED                        (0x00000001U)
#define CSL_SDMA_CCR_0_31_SECURE_DISABLED                       (0x00000000U)

#define CSL_SDMA_CCR_0_31_PREFETCH_MASK                         (0x00800000U)
#define CSL_SDMA_CCR_0_31_PREFETCH_SHIFT                        (23U)
#define CSL_SDMA_CCR_0_31_PREFETCH_RESETVAL                     (0x00000000U)
#define CSL_SDMA_CCR_0_31_PREFETCH_ENABLED                      (0x00000001U)
#define CSL_SDMA_CCR_0_31_PREFETCH_DISABLED                     (0x00000000U)

#define CSL_SDMA_CCR_0_31_SRC_AMODE_MASK                        (0x00003000U)
#define CSL_SDMA_CCR_0_31_SRC_AMODE_SHIFT                       (12U)
#define CSL_SDMA_CCR_0_31_SRC_AMODE_RESETVAL                    (0x00000000U)
#define CSL_SDMA_CCR_0_31_SRC_AMODE_CONSTANT                    (0x00000000U)
#define CSL_SDMA_CCR_0_31_SRC_AMODE_POSTINCREMENTED             (0x00000001U)
#define CSL_SDMA_CCR_0_31_SRC_AMODE_SINGLEINDEX                 (0x00000002U)
#define CSL_SDMA_CCR_0_31_SRC_AMODE_DOUBLEINDEX                 (0x00000003U)

#define CSL_SDMA_CCR_0_31_WRITE_PRIORITY_MASK                   (0x04000000U)
#define CSL_SDMA_CCR_0_31_WRITE_PRIORITY_SHIFT                  (26U)
#define CSL_SDMA_CCR_0_31_WRITE_PRIORITY_RESETVAL               (0x00000000U)
#define CSL_SDMA_CCR_0_31_WRITE_PRIORITY_HIGH                   (0x00000001U)
#define CSL_SDMA_CCR_0_31_WRITE_PRIORITY_LOW                    (0x00000000U)

#define CSL_SDMA_CCR_0_31_BUFFERING_DISABLE_MASK                (0x02000000U)
#define CSL_SDMA_CCR_0_31_BUFFERING_DISABLE_SHIFT               (25U)
#define CSL_SDMA_CCR_0_31_BUFFERING_DISABLE_RESETVAL            (0x00000000U)
#define CSL_SDMA_CCR_0_31_BUFFERING_DISABLE_BUFFERING_ENABLED   (0x00000000U)
#define CSL_SDMA_CCR_0_31_BUFFERING_DISABLE_BUFFERING_DISABLED  (0x00000001U)

#define CSL_SDMA_CCR_0_31_DOMAIN_MASK                           (0x38000000U)
#define CSL_SDMA_CCR_0_31_DOMAIN_SHIFT                          (27U)
#define CSL_SDMA_CCR_0_31_DOMAIN_RESETVAL                       (0x00000000U)
#define CSL_SDMA_CCR_0_31_DOMAIN_MAX                            (0x00000007U)

#define CSL_SDMA_CCR_0_31_RESETVAL                              (0x00000000U)

/* CLNK_CTRL_0_31 */

#define CSL_SDMA_CLNK_CTRL_0_31_EN_LNK_MASK                     (0x00008000U)
#define CSL_SDMA_CLNK_CTRL_0_31_EN_LNK_SHIFT                    (15U)
#define CSL_SDMA_CLNK_CTRL_0_31_EN_LNK_RESETVAL                 (0x00000000U)
#define CSL_SDMA_CLNK_CTRL_0_31_EN_LNK_ENABLED                  (0x00000001U)
#define CSL_SDMA_CLNK_CTRL_0_31_EN_LNK_DISABLED                 (0x00000000U)

#define CSL_SDMA_CLNK_CTRL_0_31_NEXTLCH_ID_MASK                 (0x0000001FU)
#define CSL_SDMA_CLNK_CTRL_0_31_NEXTLCH_ID_SHIFT                (0U)
#define CSL_SDMA_CLNK_CTRL_0_31_NEXTLCH_ID_RESETVAL             (0x00000000U)
#define CSL_SDMA_CLNK_CTRL_0_31_NEXTLCH_ID_MAX                  (0x0000001fU)

#define CSL_SDMA_CLNK_CTRL_0_31_RESETVAL                        (0x00000000U)

/* CICR_0_31 */

#define CSL_SDMA_CICR_0_31_HALF_IE_MASK                         (0x00000004U)
#define CSL_SDMA_CICR_0_31_HALF_IE_SHIFT                        (2U)
#define CSL_SDMA_CICR_0_31_HALF_IE_RESETVAL                     (0x00000000U)
#define CSL_SDMA_CICR_0_31_HALF_IE_ENABLED                      (0x00000001U)
#define CSL_SDMA_CICR_0_31_HALF_IE_DISABLED                     (0x00000000U)

#define CSL_SDMA_CICR_0_31_DRAIN_IE_MASK                        (0x00001000U)
#define CSL_SDMA_CICR_0_31_DRAIN_IE_SHIFT                       (12U)
#define CSL_SDMA_CICR_0_31_DRAIN_IE_RESETVAL                    (0x00000000U)
#define CSL_SDMA_CICR_0_31_DRAIN_IE_MAX                         (0x00000001U)

#define CSL_SDMA_CICR_0_31_PKT_IE_MASK                          (0x00000080U)
#define CSL_SDMA_CICR_0_31_PKT_IE_SHIFT                         (7U)
#define CSL_SDMA_CICR_0_31_PKT_IE_RESETVAL                      (0x00000000U)
#define CSL_SDMA_CICR_0_31_PKT_IE_ENABLED                       (0x00000001U)
#define CSL_SDMA_CICR_0_31_PKT_IE_DISABLED                      (0x00000000U)

#define CSL_SDMA_CICR_0_31_SECURE_ERR_IE_MASK                   (0x00000200U)
#define CSL_SDMA_CICR_0_31_SECURE_ERR_IE_SHIFT                  (9U)
#define CSL_SDMA_CICR_0_31_SECURE_ERR_IE_RESETVAL               (0x00000001U)
#define CSL_SDMA_CICR_0_31_SECURE_ERR_IE_ENABLED                (0x00000001U)
#define CSL_SDMA_CICR_0_31_SECURE_ERR_IE_DISABLED               (0x00000000U)

#define CSL_SDMA_CICR_0_31_MISALIGNED_ERR_IE_MASK               (0x00000800U)
#define CSL_SDMA_CICR_0_31_MISALIGNED_ERR_IE_SHIFT              (11U)
#define CSL_SDMA_CICR_0_31_MISALIGNED_ERR_IE_RESETVAL           (0x00000000U)
#define CSL_SDMA_CICR_0_31_MISALIGNED_ERR_IE_ENABLED            (0x00000001U)
#define CSL_SDMA_CICR_0_31_MISALIGNED_ERR_IE_DISABLED           (0x00000000U)

#define CSL_SDMA_CICR_0_31_LAST_IE_MASK                         (0x00000010U)
#define CSL_SDMA_CICR_0_31_LAST_IE_SHIFT                        (4U)
#define CSL_SDMA_CICR_0_31_LAST_IE_RESETVAL                     (0x00000000U)
#define CSL_SDMA_CICR_0_31_LAST_IE_ENABLED                      (0x00000001U)
#define CSL_SDMA_CICR_0_31_LAST_IE_DISABLED                     (0x00000000U)

#define CSL_SDMA_CICR_0_31_TRANS_ERR_IE_MASK                    (0x00000100U)
#define CSL_SDMA_CICR_0_31_TRANS_ERR_IE_SHIFT                   (8U)
#define CSL_SDMA_CICR_0_31_TRANS_ERR_IE_RESETVAL                (0x00000000U)
#define CSL_SDMA_CICR_0_31_TRANS_ERR_IE_ENABLED                 (0x00000001U)
#define CSL_SDMA_CICR_0_31_TRANS_ERR_IE_DISABLED                (0x00000000U)

#define CSL_SDMA_CICR_0_31_SUPERVISOR_ERR_IE_MASK               (0x00000400U)
#define CSL_SDMA_CICR_0_31_SUPERVISOR_ERR_IE_SHIFT              (10U)
#define CSL_SDMA_CICR_0_31_SUPERVISOR_ERR_IE_RESETVAL           (0x00000001U)
#define CSL_SDMA_CICR_0_31_SUPERVISOR_ERR_IE_ENABLED            (0x00000001U)
#define CSL_SDMA_CICR_0_31_SUPERVISOR_ERR_IE_DISABLED           (0x00000000U)

#define CSL_SDMA_CICR_0_31_DROP_IE_MASK                         (0x00000002U)
#define CSL_SDMA_CICR_0_31_DROP_IE_SHIFT                        (1U)
#define CSL_SDMA_CICR_0_31_DROP_IE_RESETVAL                     (0x00000000U)
#define CSL_SDMA_CICR_0_31_DROP_IE_ENABLED                      (0x00000001U)
#define CSL_SDMA_CICR_0_31_DROP_IE_DISABLED                     (0x00000000U)

#define CSL_SDMA_CICR_0_31_FRM_IE_MASK                          (0x00000008U)
#define CSL_SDMA_CICR_0_31_FRM_IE_SHIFT                         (3U)
#define CSL_SDMA_CICR_0_31_FRM_IE_RESETVAL                      (0x00000000U)
#define CSL_SDMA_CICR_0_31_FRM_IE_ENABLED                       (0x00000001U)
#define CSL_SDMA_CICR_0_31_FRM_IE_DISABLED                      (0x00000000U)

#define CSL_SDMA_CICR_0_31_BLOCK_IE_MASK                        (0x00000020U)
#define CSL_SDMA_CICR_0_31_BLOCK_IE_SHIFT                       (5U)
#define CSL_SDMA_CICR_0_31_BLOCK_IE_RESETVAL                    (0x00000000U)
#define CSL_SDMA_CICR_0_31_BLOCK_IE_ENABLED                     (0x00000001U)
#define CSL_SDMA_CICR_0_31_BLOCK_IE_DISABLED                    (0x00000000U)

#define CSL_SDMA_CICR_0_31_DOMAIN_ERR_IE_MASK                   (0x00002000U)
#define CSL_SDMA_CICR_0_31_DOMAIN_ERR_IE_SHIFT                  (13U)
#define CSL_SDMA_CICR_0_31_DOMAIN_ERR_IE_RESETVAL               (0x00000001U)
#define CSL_SDMA_CICR_0_31_DOMAIN_ERR_IE_MAX                    (0x00000001U)

#define CSL_SDMA_CICR_0_31_SUPER_BLOCK_IE_MASK                  (0x00004000U)
#define CSL_SDMA_CICR_0_31_SUPER_BLOCK_IE_SHIFT                 (14U)
#define CSL_SDMA_CICR_0_31_SUPER_BLOCK_IE_RESETVAL              (0x00000000U)
#define CSL_SDMA_CICR_0_31_SUPER_BLOCK_IE_MAX                   (0x00000001U)

#define CSL_SDMA_CICR_0_31_RESETVAL                             (0x00002600U)

/* CSR_0_31 */

#define CSL_SDMA_CSR_0_31_DROP_MASK                             (0x00000002U)
#define CSL_SDMA_CSR_0_31_DROP_SHIFT                            (1U)
#define CSL_SDMA_CSR_0_31_DROP_RESETVAL                         (0x00000000U)
#define CSL_SDMA_CSR_0_31_DROP_READ0X1                          (0x00000001U)
#define CSL_SDMA_CSR_0_31_DROP_READ0X0                          (0x00000000U)
#define CSL_SDMA_CSR_0_31_DROP_WRITE0X0                         (0x00000000U)
#define CSL_SDMA_CSR_0_31_DROP_WRITE0X1                         (0x00000001U)

#define CSL_SDMA_CSR_0_31_BLOCK_MASK                            (0x00000020U)
#define CSL_SDMA_CSR_0_31_BLOCK_SHIFT                           (5U)
#define CSL_SDMA_CSR_0_31_BLOCK_RESETVAL                        (0x00000000U)
#define CSL_SDMA_CSR_0_31_BLOCK_READ0X1                         (0x00000001U)
#define CSL_SDMA_CSR_0_31_BLOCK_READ0X0                         (0x00000000U)
#define CSL_SDMA_CSR_0_31_BLOCK_WRITE0X0                        (0x00000000U)
#define CSL_SDMA_CSR_0_31_BLOCK_WRITE0X1                        (0x00000001U)

#define CSL_SDMA_CSR_0_31_HALF_MASK                             (0x00000004U)
#define CSL_SDMA_CSR_0_31_HALF_SHIFT                            (2U)
#define CSL_SDMA_CSR_0_31_HALF_RESETVAL                         (0x00000000U)
#define CSL_SDMA_CSR_0_31_HALF_READ0X1                          (0x00000001U)
#define CSL_SDMA_CSR_0_31_HALF_READ0X0                          (0x00000000U)
#define CSL_SDMA_CSR_0_31_HALF_WRITE0X0                         (0x00000000U)
#define CSL_SDMA_CSR_0_31_HALF_WRITE0X1                         (0x00000001U)

#define CSL_SDMA_CSR_0_31_DRAIN_END_MASK                        (0x00001000U)
#define CSL_SDMA_CSR_0_31_DRAIN_END_SHIFT                       (12U)
#define CSL_SDMA_CSR_0_31_DRAIN_END_RESETVAL                    (0x00000000U)
#define CSL_SDMA_CSR_0_31_DRAIN_END_MAX                         (0x00000001U)

#define CSL_SDMA_CSR_0_31_MISALIGNED_ADRS_ERR_MASK              (0x00000800U)
#define CSL_SDMA_CSR_0_31_MISALIGNED_ADRS_ERR_SHIFT             (11U)
#define CSL_SDMA_CSR_0_31_MISALIGNED_ADRS_ERR_RESETVAL          (0x00000000U)
#define CSL_SDMA_CSR_0_31_MISALIGNED_ADRS_ERR_READ0X1           (0x00000001U)
#define CSL_SDMA_CSR_0_31_MISALIGNED_ADRS_ERR_READ0X0           (0x00000000U)
#define CSL_SDMA_CSR_0_31_MISALIGNED_ADRS_ERR_WRITE0X0          (0x00000000U)
#define CSL_SDMA_CSR_0_31_MISALIGNED_ADRS_ERR_WRITE0X1          (0x00000001U)

#define CSL_SDMA_CSR_0_31_SECURE_ERR_MASK                       (0x00000200U)
#define CSL_SDMA_CSR_0_31_SECURE_ERR_SHIFT                      (9U)
#define CSL_SDMA_CSR_0_31_SECURE_ERR_RESETVAL                   (0x00000000U)
#define CSL_SDMA_CSR_0_31_SECURE_ERR_READ0X1                    (0x00000001U)
#define CSL_SDMA_CSR_0_31_SECURE_ERR_READ0X0                    (0x00000000U)
#define CSL_SDMA_CSR_0_31_SECURE_ERR_WRITE0X0                   (0x00000000U)
#define CSL_SDMA_CSR_0_31_SECURE_ERR_WRITE0X1                   (0x00000001U)

#define CSL_SDMA_CSR_0_31_SYNC_MASK                             (0x00000040U)
#define CSL_SDMA_CSR_0_31_SYNC_SHIFT                            (6U)
#define CSL_SDMA_CSR_0_31_SYNC_RESETVAL                         (0x00000000U)
#define CSL_SDMA_CSR_0_31_SYNC_READ0X1                          (0x00000001U)
#define CSL_SDMA_CSR_0_31_SYNC_READ0X0                          (0x00000000U)
#define CSL_SDMA_CSR_0_31_SYNC_WRITE0X0                         (0x00000000U)
#define CSL_SDMA_CSR_0_31_SYNC_WRITE0X1                         (0x00000001U)

#define CSL_SDMA_CSR_0_31_SUPERVISOR_ERR_MASK                   (0x00000400U)
#define CSL_SDMA_CSR_0_31_SUPERVISOR_ERR_SHIFT                  (10U)
#define CSL_SDMA_CSR_0_31_SUPERVISOR_ERR_RESETVAL               (0x00000000U)
#define CSL_SDMA_CSR_0_31_SUPERVISOR_ERR_READ0X1                (0x00000001U)
#define CSL_SDMA_CSR_0_31_SUPERVISOR_ERR_READ0X0                (0x00000000U)
#define CSL_SDMA_CSR_0_31_SUPERVISOR_ERR_WRITE0X0               (0x00000000U)
#define CSL_SDMA_CSR_0_31_SUPERVISOR_ERR_WRITE0X1               (0x00000001U)

#define CSL_SDMA_CSR_0_31_PKT_MASK                              (0x00000080U)
#define CSL_SDMA_CSR_0_31_PKT_SHIFT                             (7U)
#define CSL_SDMA_CSR_0_31_PKT_RESETVAL                          (0x00000000U)
#define CSL_SDMA_CSR_0_31_PKT_READ0X1                           (0x00000001U)
#define CSL_SDMA_CSR_0_31_PKT_READ0X0                           (0x00000000U)
#define CSL_SDMA_CSR_0_31_PKT_WRITE0X0                          (0x00000000U)
#define CSL_SDMA_CSR_0_31_PKT_WRITE0X1                          (0x00000001U)

#define CSL_SDMA_CSR_0_31_LAST_MASK                             (0x00000010U)
#define CSL_SDMA_CSR_0_31_LAST_SHIFT                            (4U)
#define CSL_SDMA_CSR_0_31_LAST_RESETVAL                         (0x00000000U)
#define CSL_SDMA_CSR_0_31_LAST_READ0X1                          (0x00000001U)
#define CSL_SDMA_CSR_0_31_LAST_READ0X0                          (0x00000000U)
#define CSL_SDMA_CSR_0_31_LAST_WRITE0X0                         (0x00000000U)
#define CSL_SDMA_CSR_0_31_LAST_WRITE0X1                         (0x00000001U)

#define CSL_SDMA_CSR_0_31_TRANS_ERR_MASK                        (0x00000100U)
#define CSL_SDMA_CSR_0_31_TRANS_ERR_SHIFT                       (8U)
#define CSL_SDMA_CSR_0_31_TRANS_ERR_RESETVAL                    (0x00000000U)
#define CSL_SDMA_CSR_0_31_TRANS_ERR_READ0X1                     (0x00000001U)
#define CSL_SDMA_CSR_0_31_TRANS_ERR_READ0X0                     (0x00000000U)
#define CSL_SDMA_CSR_0_31_TRANS_ERR_WRITE0X0                    (0x00000000U)
#define CSL_SDMA_CSR_0_31_TRANS_ERR_WRITE0X1                    (0x00000001U)

#define CSL_SDMA_CSR_0_31_FRM_MASK                              (0x00000008U)
#define CSL_SDMA_CSR_0_31_FRM_SHIFT                             (3U)
#define CSL_SDMA_CSR_0_31_FRM_RESETVAL                          (0x00000000U)
#define CSL_SDMA_CSR_0_31_FRM_READ0X1                           (0x00000001U)
#define CSL_SDMA_CSR_0_31_FRM_READ0X0                           (0x00000000U)
#define CSL_SDMA_CSR_0_31_FRM_WRITE0X0                          (0x00000000U)
#define CSL_SDMA_CSR_0_31_FRM_WRITE0X1                          (0x00000001U)

#define CSL_SDMA_CSR_0_31_DOMAIN_ERR_MASK                       (0x00002000U)
#define CSL_SDMA_CSR_0_31_DOMAIN_ERR_SHIFT                      (13U)
#define CSL_SDMA_CSR_0_31_DOMAIN_ERR_RESETVAL                   (0x00000000U)
#define CSL_SDMA_CSR_0_31_DOMAIN_ERR_MAX                        (0x00000001U)

#define CSL_SDMA_CSR_0_31_SUPER_BLOCK_MASK                      (0x00004000U)
#define CSL_SDMA_CSR_0_31_SUPER_BLOCK_SHIFT                     (14U)
#define CSL_SDMA_CSR_0_31_SUPER_BLOCK_RESETVAL                  (0x00000000U)
#define CSL_SDMA_CSR_0_31_SUPER_BLOCK_MAX                       (0x00000001U)

#define CSL_SDMA_CSR_0_31_RESETVAL                              (0x00000000U)

/* CSDP_0_31 */

#define CSL_SDMA_CSDP_0_31_DST_ENDIAN_LOCK_MASK                 (0x00040000U)
#define CSL_SDMA_CSDP_0_31_DST_ENDIAN_LOCK_SHIFT                (18U)
#define CSL_SDMA_CSDP_0_31_DST_ENDIAN_LOCK_RESETVAL             (0x00000000U)
#define CSL_SDMA_CSDP_0_31_DST_ENDIAN_LOCK_ADAPTED              (0x00000000U)
#define CSL_SDMA_CSDP_0_31_DST_ENDIAN_LOCK_LOCKED               (0x00000001U)

#define CSL_SDMA_CSDP_0_31_SRC_ENDIAN_LOCK_MASK                 (0x00100000U)
#define CSL_SDMA_CSDP_0_31_SRC_ENDIAN_LOCK_SHIFT                (20U)
#define CSL_SDMA_CSDP_0_31_SRC_ENDIAN_LOCK_RESETVAL             (0x00000000U)
#define CSL_SDMA_CSDP_0_31_SRC_ENDIAN_LOCK_ADAPTED              (0x00000000U)
#define CSL_SDMA_CSDP_0_31_SRC_ENDIAN_LOCK_LOCKED               (0x00000001U)

#define CSL_SDMA_CSDP_0_31_DST_BURST_EN_MASK                    (0x0000C000U)
#define CSL_SDMA_CSDP_0_31_DST_BURST_EN_SHIFT                   (14U)
#define CSL_SDMA_CSDP_0_31_DST_BURST_EN_RESETVAL                (0x00000000U)
#define CSL_SDMA_CSDP_0_31_DST_BURST_EN_SINGLE                  (0x00000000U)
#define CSL_SDMA_CSDP_0_31_DST_BURST_EN__16B                    (0x00000001U)
#define CSL_SDMA_CSDP_0_31_DST_BURST_EN__32B                    (0x00000002U)
#define CSL_SDMA_CSDP_0_31_DST_BURST_EN__64B                    (0x00000003U)

#define CSL_SDMA_CSDP_0_31_WR_ADD_TRSLT_MASK                    (0x00001E00U)
#define CSL_SDMA_CSDP_0_31_WR_ADD_TRSLT_SHIFT                   (9U)
#define CSL_SDMA_CSDP_0_31_WR_ADD_TRSLT_RESETVAL                (0x00000000U)
#define CSL_SDMA_CSDP_0_31_WR_ADD_TRSLT_MAX                     (0x0000000fU)

#define CSL_SDMA_CSDP_0_31_WRITE_MODE_MASK                      (0x00030000U)
#define CSL_SDMA_CSDP_0_31_WRITE_MODE_SHIFT                     (16U)
#define CSL_SDMA_CSDP_0_31_WRITE_MODE_RESETVAL                  (0x00000000U)
#define CSL_SDMA_CSDP_0_31_WRITE_MODE_WRNP                      (0x00000000U)
#define CSL_SDMA_CSDP_0_31_WRITE_MODE_POSTED                    (0x00000001U)
#define CSL_SDMA_CSDP_0_31_WRITE_MODE_MAPPED                    (0x00000002U)
#define CSL_SDMA_CSDP_0_31_WRITE_MODE_UNDEFINED                 (0x00000003U)

#define CSL_SDMA_CSDP_0_31_DST_ENDIAN_MASK                      (0x00080000U)
#define CSL_SDMA_CSDP_0_31_DST_ENDIAN_SHIFT                     (19U)
#define CSL_SDMA_CSDP_0_31_DST_ENDIAN_RESETVAL                  (0x00000000U)
#define CSL_SDMA_CSDP_0_31_DST_ENDIAN_LITTLE                    (0x00000000U)
#define CSL_SDMA_CSDP_0_31_DST_ENDIAN_BIG                       (0x00000001U)

#define CSL_SDMA_CSDP_0_31_SRC_BURST_EN_MASK                    (0x00000180U)
#define CSL_SDMA_CSDP_0_31_SRC_BURST_EN_SHIFT                   (7U)
#define CSL_SDMA_CSDP_0_31_SRC_BURST_EN_RESETVAL                (0x00000000U)
#define CSL_SDMA_CSDP_0_31_SRC_BURST_EN_SINGLE                  (0x00000000U)
#define CSL_SDMA_CSDP_0_31_SRC_BURST_EN__16B                    (0x00000001U)
#define CSL_SDMA_CSDP_0_31_SRC_BURST_EN__32B                    (0x00000002U)
#define CSL_SDMA_CSDP_0_31_SRC_BURST_EN__64B                    (0x00000003U)

#define CSL_SDMA_CSDP_0_31_RD_ADD_TRSLT_MASK                    (0x0000003CU)
#define CSL_SDMA_CSDP_0_31_RD_ADD_TRSLT_SHIFT                   (2U)
#define CSL_SDMA_CSDP_0_31_RD_ADD_TRSLT_RESETVAL                (0x00000000U)
#define CSL_SDMA_CSDP_0_31_RD_ADD_TRSLT_MAX                     (0x0000000fU)

#define CSL_SDMA_CSDP_0_31_DST_PACKED_MASK                      (0x00002000U)
#define CSL_SDMA_CSDP_0_31_DST_PACKED_SHIFT                     (13U)
#define CSL_SDMA_CSDP_0_31_DST_PACKED_RESETVAL                  (0x00000000U)
#define CSL_SDMA_CSDP_0_31_DST_PACKED_PACKED                    (0x00000001U)
#define CSL_SDMA_CSDP_0_31_DST_PACKED_NONPACKED                 (0x00000000U)

#define CSL_SDMA_CSDP_0_31_SRC_PACKED_MASK                      (0x00000040U)
#define CSL_SDMA_CSDP_0_31_SRC_PACKED_SHIFT                     (6U)
#define CSL_SDMA_CSDP_0_31_SRC_PACKED_RESETVAL                  (0x00000000U)
#define CSL_SDMA_CSDP_0_31_SRC_PACKED_PACKED                    (0x00000001U)
#define CSL_SDMA_CSDP_0_31_SRC_PACKED_NONPACKED                 (0x00000000U)

#define CSL_SDMA_CSDP_0_31_DATA_TYPE_MASK                       (0x00000003U)
#define CSL_SDMA_CSDP_0_31_DATA_TYPE_SHIFT                      (0U)
#define CSL_SDMA_CSDP_0_31_DATA_TYPE_RESETVAL                   (0x00000000U)
#define CSL_SDMA_CSDP_0_31_DATA_TYPE__8B                        (0x00000000U)
#define CSL_SDMA_CSDP_0_31_DATA_TYPE__16B                       (0x00000001U)
#define CSL_SDMA_CSDP_0_31_DATA_TYPE__32B                       (0x00000002U)
#define CSL_SDMA_CSDP_0_31_DATA_TYPE_UNDEFINED                  (0x00000003U)

#define CSL_SDMA_CSDP_0_31_SRC_ENDIAN_MASK                      (0x00200000U)
#define CSL_SDMA_CSDP_0_31_SRC_ENDIAN_SHIFT                     (21U)
#define CSL_SDMA_CSDP_0_31_SRC_ENDIAN_RESETVAL                  (0x00000000U)
#define CSL_SDMA_CSDP_0_31_SRC_ENDIAN_LITTLE                    (0x00000000U)
#define CSL_SDMA_CSDP_0_31_SRC_ENDIAN_BIG                       (0x00000001U)

#define CSL_SDMA_CSDP_0_31_RESETVAL                             (0x00000000U)

/* CEN_0_31 */

#define CSL_SDMA_CEN_0_31_CHANNEL_ELMNT_NBR_MASK                (0x00FFFFFFU)
#define CSL_SDMA_CEN_0_31_CHANNEL_ELMNT_NBR_SHIFT               (0U)
#define CSL_SDMA_CEN_0_31_CHANNEL_ELMNT_NBR_RESETVAL            (0x00000000U)
#define CSL_SDMA_CEN_0_31_CHANNEL_ELMNT_NBR_MAX                 (0x00ffffffU)

#define CSL_SDMA_CEN_0_31_RESETVAL                              (0x00000000U)

/* CFN_0_31 */

#define CSL_SDMA_CFN_0_31_CHANNEL_FRM_NBR_MASK                  (0x0000FFFFU)
#define CSL_SDMA_CFN_0_31_CHANNEL_FRM_NBR_SHIFT                 (0U)
#define CSL_SDMA_CFN_0_31_CHANNEL_FRM_NBR_RESETVAL              (0x00000000U)
#define CSL_SDMA_CFN_0_31_CHANNEL_FRM_NBR_MAX                   (0x0000ffffU)

#define CSL_SDMA_CFN_0_31_RESETVAL                              (0x00000000U)

/* CSSA_0_31 */

#define CSL_SDMA_CSSA_0_31_SRC_START_ADRS_MASK                  (0xFFFFFFFFU)
#define CSL_SDMA_CSSA_0_31_SRC_START_ADRS_SHIFT                 (0U)
#define CSL_SDMA_CSSA_0_31_SRC_START_ADRS_RESETVAL              (0x00000000U)
#define CSL_SDMA_CSSA_0_31_SRC_START_ADRS_MAX                   (0xffffffffU)

#define CSL_SDMA_CSSA_0_31_RESETVAL                             (0x00000000U)

/* CDSA_0_31 */

#define CSL_SDMA_CDSA_0_31_DST_START_ADRS_MASK                  (0xFFFFFFFFU)
#define CSL_SDMA_CDSA_0_31_DST_START_ADRS_SHIFT                 (0U)
#define CSL_SDMA_CDSA_0_31_DST_START_ADRS_RESETVAL              (0x00000000U)
#define CSL_SDMA_CDSA_0_31_DST_START_ADRS_MAX                   (0xffffffffU)

#define CSL_SDMA_CDSA_0_31_RESETVAL                             (0x00000000U)

/* CSEI_0_31 */

#define CSL_SDMA_CSEI_0_31_CHANNEL_SRC_ELMNT_IDX_MASK           (0x0000FFFFU)
#define CSL_SDMA_CSEI_0_31_CHANNEL_SRC_ELMNT_IDX_SHIFT          (0U)
#define CSL_SDMA_CSEI_0_31_CHANNEL_SRC_ELMNT_IDX_RESETVAL       (0x00000000U)
#define CSL_SDMA_CSEI_0_31_CHANNEL_SRC_ELMNT_IDX_MAX            (0x0000ffffU)

#define CSL_SDMA_CSEI_0_31_RESETVAL                             (0x00000000U)

/* CSFI_0_31 */

#define CSL_SDMA_CSFI_0_31_CH_SRC_FRM_IDX_OR_16BIT_PKT_ELNT_NBR_MASK  (0xFFFFFFFFU)
#define CSL_SDMA_CSFI_0_31_CH_SRC_FRM_IDX_OR_16BIT_PKT_ELNT_NBR_SHIFT  (0U)
#define CSL_SDMA_CSFI_0_31_CH_SRC_FRM_IDX_OR_16BIT_PKT_ELNT_NBR_RESETVAL  (0x00000000U)
#define CSL_SDMA_CSFI_0_31_CH_SRC_FRM_IDX_OR_16BIT_PKT_ELNT_NBR_MAX  (0xffffffffU)

#define CSL_SDMA_CSFI_0_31_RESETVAL                             (0x00000000U)

/* CDEI_0_31 */

#define CSL_SDMA_CDEI_0_31_CHANNEL_DST_ELMNT_IDX_MASK           (0x0000FFFFU)
#define CSL_SDMA_CDEI_0_31_CHANNEL_DST_ELMNT_IDX_SHIFT          (0U)
#define CSL_SDMA_CDEI_0_31_CHANNEL_DST_ELMNT_IDX_RESETVAL       (0x00000000U)
#define CSL_SDMA_CDEI_0_31_CHANNEL_DST_ELMNT_IDX_MAX            (0x0000ffffU)

#define CSL_SDMA_CDEI_0_31_RESETVAL                             (0x00000000U)

/* CDFI_0_31 */

#define CSL_SDMA_CDFI_0_31_CH_DST_FRM_IDX_OR_16BIT_PKT_ELNT_NBR_MASK  (0xFFFFFFFFU)
#define CSL_SDMA_CDFI_0_31_CH_DST_FRM_IDX_OR_16BIT_PKT_ELNT_NBR_SHIFT  (0U)
#define CSL_SDMA_CDFI_0_31_CH_DST_FRM_IDX_OR_16BIT_PKT_ELNT_NBR_RESETVAL  (0x00000000U)
#define CSL_SDMA_CDFI_0_31_CH_DST_FRM_IDX_OR_16BIT_PKT_ELNT_NBR_MAX  (0xffffffffU)

#define CSL_SDMA_CDFI_0_31_RESETVAL                             (0x00000000U)

/* CSAC_0_31 */

#define CSL_SDMA_CSAC_0_31_SRC_ELMNT_ADRS_MASK                  (0xFFFFFFFFU)
#define CSL_SDMA_CSAC_0_31_SRC_ELMNT_ADRS_SHIFT                 (0U)
#define CSL_SDMA_CSAC_0_31_SRC_ELMNT_ADRS_RESETVAL              (0x00000000U)
#define CSL_SDMA_CSAC_0_31_SRC_ELMNT_ADRS_MAX                   (0xffffffffU)

#define CSL_SDMA_CSAC_0_31_RESETVAL                             (0x00000000U)

/* CDAC_0_31 */

#define CSL_SDMA_CDAC_0_31_DST_ELMNT_ADRS_MASK                  (0xFFFFFFFFU)
#define CSL_SDMA_CDAC_0_31_DST_ELMNT_ADRS_SHIFT                 (0U)
#define CSL_SDMA_CDAC_0_31_DST_ELMNT_ADRS_RESETVAL              (0x00000000U)
#define CSL_SDMA_CDAC_0_31_DST_ELMNT_ADRS_MAX                   (0xffffffffU)

#define CSL_SDMA_CDAC_0_31_RESETVAL                             (0x00000000U)

/* CCEN_0_31 */

#define CSL_SDMA_CCEN_0_31_CURRENT_ELMNT_NBR_MASK               (0x00FFFFFFU)
#define CSL_SDMA_CCEN_0_31_CURRENT_ELMNT_NBR_SHIFT              (0U)
#define CSL_SDMA_CCEN_0_31_CURRENT_ELMNT_NBR_RESETVAL           (0x00000000U)
#define CSL_SDMA_CCEN_0_31_CURRENT_ELMNT_NBR_MAX                (0x00ffffffU)

#define CSL_SDMA_CCEN_0_31_RESETVAL                             (0x00000000U)

/* CCFN_0_31 */

#define CSL_SDMA_CCFN_0_31_CURRENT_FRM_NBR_MASK                 (0x0000FFFFU)
#define CSL_SDMA_CCFN_0_31_CURRENT_FRM_NBR_SHIFT                (0U)
#define CSL_SDMA_CCFN_0_31_CURRENT_FRM_NBR_RESETVAL             (0x00000000U)
#define CSL_SDMA_CCFN_0_31_CURRENT_FRM_NBR_MAX                  (0x0000ffffU)

#define CSL_SDMA_CCFN_0_31_RESETVAL                             (0x00000000U)

/* COLOR_0_31 */

#define CSL_SDMA_COLOR_0_31_CH_BLT_FRGRND_COLOR_OR_SOLID_PTRN_MASK  (0x00FFFFFFU)
#define CSL_SDMA_COLOR_0_31_CH_BLT_FRGRND_COLOR_OR_SOLID_PTRN_SHIFT  (0U)
#define CSL_SDMA_COLOR_0_31_CH_BLT_FRGRND_COLOR_OR_SOLID_PTRN_RESETVAL  (0x00000000U)
#define CSL_SDMA_COLOR_0_31_CH_BLT_FRGRND_COLOR_OR_SOLID_PTRN_MAX  (0x00ffffffU)

#define CSL_SDMA_COLOR_0_31_RESETVAL                            (0x00000000U)

/* CDP_0_31 */

#define CSL_SDMA_CDP_0_31_DEST_VALID_MASK                       (0x00000003U)
#define CSL_SDMA_CDP_0_31_DEST_VALID_SHIFT                      (0U)
#define CSL_SDMA_CDP_0_31_DEST_VALID_RESETVAL                   (0x00000000U)
#define CSL_SDMA_CDP_0_31_DEST_VALID_MAX                        (0x00000003U)

#define CSL_SDMA_CDP_0_31_SOURCE_VALID_MASK                     (0x0000000CU)
#define CSL_SDMA_CDP_0_31_SOURCE_VALID_SHIFT                    (2U)
#define CSL_SDMA_CDP_0_31_SOURCE_VALID_RESETVAL                 (0x00000000U)
#define CSL_SDMA_CDP_0_31_SOURCE_VALID_MAX                      (0x00000003U)

#define CSL_SDMA_CDP_0_31_NEXT_DESCRIPTOR_TYPE_MASK             (0x00000070U)
#define CSL_SDMA_CDP_0_31_NEXT_DESCRIPTOR_TYPE_SHIFT            (4U)
#define CSL_SDMA_CDP_0_31_NEXT_DESCRIPTOR_TYPE_RESETVAL         (0x00000000U)
#define CSL_SDMA_CDP_0_31_NEXT_DESCRIPTOR_TYPE_MAX              (0x00000007U)

#define CSL_SDMA_CDP_0_31_PAUSE_LINK_LIST_MASK                  (0x00000080U)
#define CSL_SDMA_CDP_0_31_PAUSE_LINK_LIST_SHIFT                 (7U)
#define CSL_SDMA_CDP_0_31_PAUSE_LINK_LIST_RESETVAL              (0x00000000U)
#define CSL_SDMA_CDP_0_31_PAUSE_LINK_LIST_MAX                   (0x00000001U)

#define CSL_SDMA_CDP_0_31_TRANSFER_MODE_MASK                    (0x00000300U)
#define CSL_SDMA_CDP_0_31_TRANSFER_MODE_SHIFT                   (8U)
#define CSL_SDMA_CDP_0_31_TRANSFER_MODE_RESETVAL                (0x00000000U)
#define CSL_SDMA_CDP_0_31_TRANSFER_MODE_MAX                     (0x00000003U)

#define CSL_SDMA_CDP_0_31_FAST_MASK                             (0x00000400U)
#define CSL_SDMA_CDP_0_31_FAST_SHIFT                            (10U)
#define CSL_SDMA_CDP_0_31_FAST_RESETVAL                         (0x00000000U)
#define CSL_SDMA_CDP_0_31_FAST_MAX                              (0x00000001U)

#define CSL_SDMA_CDP_0_31_OV_MASK                               (0x00000800U)
#define CSL_SDMA_CDP_0_31_OV_SHIFT                              (11U)
#define CSL_SDMA_CDP_0_31_OV_RESETVAL                           (0x00000000U)
#define CSL_SDMA_CDP_0_31_OV_MAX                                (0x00000001U)

#define CSL_SDMA_CDP_0_31_WI_MASK                               (0x00001000U)
#define CSL_SDMA_CDP_0_31_WI_SHIFT                              (12U)
#define CSL_SDMA_CDP_0_31_WI_RESETVAL                           (0x00000000U)
#define CSL_SDMA_CDP_0_31_WI_MAX                                (0x00000001U)

#define CSL_SDMA_CDP_0_31_ALGO_MASK                             (0x00006000U)
#define CSL_SDMA_CDP_0_31_ALGO_SHIFT                            (13U)
#define CSL_SDMA_CDP_0_31_ALGO_RESETVAL                         (0x00000000U)
#define CSL_SDMA_CDP_0_31_ALGO_MAX                              (0x00000003U)

#define CSL_SDMA_CDP_0_31_DES_ENDIAN_MASK                       (0x00008000U)
#define CSL_SDMA_CDP_0_31_DES_ENDIAN_SHIFT                      (15U)
#define CSL_SDMA_CDP_0_31_DES_ENDIAN_RESETVAL                   (0x00000000U)
#define CSL_SDMA_CDP_0_31_DES_ENDIAN_MAX                        (0x00000001U)

#define CSL_SDMA_CDP_0_31_SLAVE2FREE_MASK                       (0x00010000U)
#define CSL_SDMA_CDP_0_31_SLAVE2FREE_SHIFT                      (16U)
#define CSL_SDMA_CDP_0_31_SLAVE2FREE_RESETVAL                   (0x00000000U)
#define CSL_SDMA_CDP_0_31_SLAVE2FREE_MAX                        (0x00000001U)

#define CSL_SDMA_CDP_0_31_RESETVAL                              (0x00000000U)

/* CNDP_0_31 */

#define CSL_SDMA_CNDP_0_31_NEXT_DESCRIPTOR_POINTER_MASK         (0xFFFFFFFCU)
#define CSL_SDMA_CNDP_0_31_NEXT_DESCRIPTOR_POINTER_SHIFT        (2U)
#define CSL_SDMA_CNDP_0_31_NEXT_DESCRIPTOR_POINTER_RESETVAL     (0x00000000U)
#define CSL_SDMA_CNDP_0_31_NEXT_DESCRIPTOR_POINTER_MAX          (0x3fffffffU)

#define CSL_SDMA_CNDP_0_31_RESETVAL                             (0x00000000U)

/* CCDN_0_31 */

#define CSL_SDMA_CCDN_0_31_NEXT_DESCRIPTOR_POINTER_MASK         (0x0000FFFFU)
#define CSL_SDMA_CCDN_0_31_NEXT_DESCRIPTOR_POINTER_SHIFT        (0U)
#define CSL_SDMA_CCDN_0_31_NEXT_DESCRIPTOR_POINTER_RESETVAL     (0x00000000U)
#define CSL_SDMA_CCDN_0_31_NEXT_DESCRIPTOR_POINTER_MAX          (0x0000ffffU)

#define CSL_SDMA_CCDN_0_31_RESETVAL                             (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
