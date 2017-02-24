/*
 *  Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
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

/**
 *  \file   hw_dss_prm.h
 *
 *  \brief  Register-level header file for PRCM
 *
**/

#ifndef HW_DSS_PRM_H_
#define HW_DSS_PRM_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/

#define PM_DSS_PWRSTCTRL                                            (0x0U)
#define PM_DSS_PWRSTST                                              (0x4U)
#define PM_DSS_DSS_WKDEP                                                                                    (0x20U)
#define RM_DSS_DSS_CONTEXT                                                                                  (0x24U)
#define PM_DSS_DSS2_WKDEP                                           (0x28U)
#define RM_DSS_SDVENC_CONTEXT                                       (0x3cU)

/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define PM_DSS_PWRSTCTRL_DSS_MEM_RETSTATE_SHIFT                                                             (8U)
#define PM_DSS_PWRSTCTRL_DSS_MEM_RETSTATE_MASK                                                              (0x00000100U)
#define PM_DSS_PWRSTCTRL_DSS_MEM_RETSTATE_MEM_OFF                                                            (0U)

#define PM_DSS_PWRSTCTRL_DSS_MEM_ONSTATE_SHIFT                                                              (16U)
#define PM_DSS_PWRSTCTRL_DSS_MEM_ONSTATE_MASK                                                               (0x00030000U)
#define PM_DSS_PWRSTCTRL_DSS_MEM_ONSTATE_MEM_ON                                                              (3U)

#define PM_DSS_PWRSTCTRL_POWERSTATE_SHIFT                                               (0U)
#define PM_DSS_PWRSTCTRL_POWERSTATE_MASK                                                (0x00000003U)
#define PM_DSS_PWRSTCTRL_POWERSTATE_OFF                                                  (0U)
#define PM_DSS_PWRSTCTRL_POWERSTATE_INACT                                                (2U)
#define PM_DSS_PWRSTCTRL_POWERSTATE_RET                                                  (1U)
#define PM_DSS_PWRSTCTRL_POWERSTATE_ON                                                   (3U)

#define PM_DSS_PWRSTCTRL_LOWPOWERSTATECHANGE_SHIFT                                      (4U)
#define PM_DSS_PWRSTCTRL_LOWPOWERSTATECHANGE_MASK                                       (0x00000010U)
#define PM_DSS_PWRSTCTRL_LOWPOWERSTATECHANGE_EN                                          (1U)
#define PM_DSS_PWRSTCTRL_LOWPOWERSTATECHANGE_DIS                                         (0U)

#define PM_DSS_PWRSTCTRL_LOGICRETSTATE_SHIFT                                            (2U)
#define PM_DSS_PWRSTCTRL_LOGICRETSTATE_MASK                                             (0x00000004U)
#define PM_DSS_PWRSTCTRL_LOGICRETSTATE_LOGIC_OFF                                         (0U)

#define PM_DSS_PWRSTST_POWERSTATEST_SHIFT                                               (0U)
#define PM_DSS_PWRSTST_POWERSTATEST_MASK                                                (0x00000003U)
#define PM_DSS_PWRSTST_POWERSTATEST_ON                                                   (3U)
#define PM_DSS_PWRSTST_POWERSTATEST_OFF                                                  (0U)
#define PM_DSS_PWRSTST_POWERSTATEST_RET                                                  (1U)
#define PM_DSS_PWRSTST_POWERSTATEST_INACTIVE                                             (2U)

#define PM_DSS_PWRSTST_INTRANSITION_SHIFT                                               (20U)
#define PM_DSS_PWRSTST_INTRANSITION_MASK                                                (0x00100000U)
#define PM_DSS_PWRSTST_INTRANSITION_NO                                                   (0U)
#define PM_DSS_PWRSTST_INTRANSITION_ONGOING                                              (1U)

#define PM_DSS_PWRSTST_LOGICSTATEST_SHIFT                                               (2U)
#define PM_DSS_PWRSTST_LOGICSTATEST_MASK                                                (0x00000004U)
#define PM_DSS_PWRSTST_LOGICSTATEST_ON                                                   (1U)
#define PM_DSS_PWRSTST_LOGICSTATEST_OFF                                                  (0U)

#define PM_DSS_PWRSTST_DSS_MEM_STATEST_SHIFT                                                                (4U)
#define PM_DSS_PWRSTST_DSS_MEM_STATEST_MASK                                                                 (0x00000030U)
#define PM_DSS_PWRSTST_DSS_MEM_STATEST_MEM_ON                                                                (3U)
#define PM_DSS_PWRSTST_DSS_MEM_STATEST_RESERVED1                                                             (1U)
#define PM_DSS_PWRSTST_DSS_MEM_STATEST_MEM_OFF                                                               (0U)
#define PM_DSS_PWRSTST_DSS_MEM_STATEST_RESERVED                                                              (2U)

#define PM_DSS_PWRSTST_LASTPOWERSTATEENTERED_SHIFT                                      (24U)
#define PM_DSS_PWRSTST_LASTPOWERSTATEENTERED_MASK                                       (0x03000000U)
#define PM_DSS_PWRSTST_LASTPOWERSTATEENTERED_ON                                          (3U)
#define PM_DSS_PWRSTST_LASTPOWERSTATEENTERED_OFF                                         (0U)
#define PM_DSS_PWRSTST_LASTPOWERSTATEENTERED_RET                                         (1U)
#define PM_DSS_PWRSTST_LASTPOWERSTATEENTERED_INACTIVE                                    (2U)

#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_MPU_SHIFT                                                            (0U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_MPU_MASK                                                             (0x00000001U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_MPU_ENABLED                                                           (1U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_MPU_DISABLED                                                          (0U)

#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_IPU2_SHIFT                                                           (1U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_IPU2_MASK                                                            (0x00000002U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_IPU2_ENABLED                                                          (1U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_IPU2_DISABLED                                                         (0U)

#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_DSP1_SHIFT                                                           (2U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_DSP1_MASK                                                            (0x00000004U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_DSP1_ENABLED                                                          (1U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_DSP1_DISABLED                                                         (0U)

#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_SDMA_SHIFT                                                           (3U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_SDMA_MASK                                                            (0x00000008U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_SDMA_ENABLED                                                          (1U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_SDMA_DISABLED                                                         (0U)

#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_IPU1_SHIFT                                                           (4U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_IPU1_MASK                                                            (0x00000010U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_IPU1_ENABLED                                                          (1U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_IPU1_DISABLED                                                         (0U)

#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_DSP2_SHIFT                                                           (5U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_DSP2_MASK                                                            (0x00000020U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_DSP2_ENABLED                                                          (1U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_DSP2_DISABLED                                                         (0U)

#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_EVE1_SHIFT                                                           (6U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_EVE1_MASK                                                            (0x00000040U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_EVE1_ENABLED                                                          (1U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_EVE1_DISABLED                                                         (0U)

#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_EVE2_SHIFT                                                           (7U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_EVE2_MASK                                                            (0x00000080U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_EVE2_ENABLED                                                          (1U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_EVE2_DISABLED                                                         (0U)

#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_EVE3_SHIFT                                                           (8U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_EVE3_MASK                                                            (0x00000100U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_EVE3_ENABLED                                                          (1U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_EVE3_DISABLED                                                         (0U)

#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_EVE4_SHIFT                                                           (9U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_EVE4_MASK                                                            (0x00000200U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_EVE4_ENABLED                                                          (1U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DISPC_EVE4_DISABLED                                                         (0U)

#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_MPU_SHIFT                                                           (10U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_MPU_MASK                                                            (0x00000400U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_MPU_ENABLED                                                          (1U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_MPU_DISABLED                                                         (0U)

#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_IPU2_SHIFT                                                          (11U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_IPU2_MASK                                                           (0x00000800U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_IPU2_ENABLED                                                         (1U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_IPU2_DISABLED                                                        (0U)

#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_DSP1_SHIFT                                                          (12U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_DSP1_MASK                                                           (0x00001000U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_DSP1_ENABLED                                                         (1U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_DSP1_DISABLED                                                        (0U)

#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_SDMA_SHIFT                                                          (13U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_SDMA_MASK                                                           (0x00002000U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_SDMA_ENABLED                                                         (1U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_SDMA_DISABLED                                                        (0U)

#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_IPU1_SHIFT                                                          (14U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_IPU1_MASK                                                           (0x00004000U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_IPU1_ENABLED                                                         (1U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_IPU1_DISABLED                                                        (0U)

#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_DSP2_SHIFT                                                          (15U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_DSP2_MASK                                                           (0x00008000U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_DSP2_ENABLED                                                         (1U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_DSP2_DISABLED                                                        (0U)

#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_EVE1_SHIFT                                                          (16U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_EVE1_MASK                                                           (0x00010000U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_EVE1_ENABLED                                                         (1U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_EVE1_DISABLED                                                        (0U)

#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_EVE2_SHIFT                                                          (17U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_EVE2_MASK                                                           (0x00020000U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_EVE2_ENABLED                                                         (1U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_EVE2_DISABLED                                                        (0U)

#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_EVE3_SHIFT                                                          (18U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_EVE3_MASK                                                           (0x00040000U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_EVE3_ENABLED                                                         (1U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_EVE3_DISABLED                                                        (0U)

#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_EVE4_SHIFT                                                          (19U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_EVE4_MASK                                                           (0x00080000U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_EVE4_ENABLED                                                         (1U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_A_EVE4_DISABLED                                                        (0U)

#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_MPU_SHIFT                                                           (20U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_MPU_MASK                                                            (0x00100000U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_MPU_ENABLED                                                          (1U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_MPU_DISABLED                                                         (0U)

#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_IPU2_SHIFT                                                          (21U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_IPU2_MASK                                                           (0x00200000U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_IPU2_ENABLED                                                         (1U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_IPU2_DISABLED                                                        (0U)

#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_DSP1_SHIFT                                                          (22U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_DSP1_MASK                                                           (0x00400000U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_DSP1_ENABLED                                                         (1U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_DSP1_DISABLED                                                        (0U)

#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_SDMA_SHIFT                                                          (23U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_SDMA_MASK                                                           (0x00800000U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_SDMA_ENABLED                                                         (1U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_SDMA_DISABLED                                                        (0U)

#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_IPU1_SHIFT                                                          (24U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_IPU1_MASK                                                           (0x01000000U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_IPU1_ENABLED                                                         (1U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_IPU1_DISABLED                                                        (0U)

#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_DSP2_SHIFT                                                          (25U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_DSP2_MASK                                                           (0x02000000U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_DSP2_ENABLED                                                         (1U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_DSP2_DISABLED                                                        (0U)

#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_EVE1_SHIFT                                                          (26U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_EVE1_MASK                                                           (0x04000000U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_EVE1_ENABLED                                                         (1U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_EVE1_DISABLED                                                        (0U)

#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_EVE2_SHIFT                                                          (27U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_EVE2_MASK                                                           (0x08000000U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_EVE2_ENABLED                                                         (1U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_EVE2_DISABLED                                                        (0U)

#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_EVE3_SHIFT                                                          (28U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_EVE3_MASK                                                           (0x10000000U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_EVE3_ENABLED                                                         (1U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_EVE3_DISABLED                                                        (0U)

#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_EVE4_SHIFT                                                          (29U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_EVE4_MASK                                                           (0x20000000U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_EVE4_ENABLED                                                         (1U)
#define PM_DSS_DSS_WKDEP_WKUPDEP_DSI1_B_EVE4_DISABLED                                                        (0U)

#define RM_DSS_DSS_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                                            (0U)
#define RM_DSS_DSS_CONTEXT_LOSTCONTEXT_DFF_MASK                                                             (0x00000001U)
#define RM_DSS_DSS_CONTEXT_LOSTCONTEXT_DFF_LOST                                                              (1U)
#define RM_DSS_DSS_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                                                        (0U)

#define RM_DSS_DSS_CONTEXT_LOSTCONTEXT_RFF_SHIFT                                                            (1U)
#define RM_DSS_DSS_CONTEXT_LOSTCONTEXT_RFF_MASK                                                             (0x00000002U)
#define RM_DSS_DSS_CONTEXT_LOSTCONTEXT_RFF_LOST                                                              (1U)
#define RM_DSS_DSS_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED                                                        (0U)

#define RM_DSS_DSS_CONTEXT_LOSTMEM_DSS_MEM_SHIFT                                                            (8U)
#define RM_DSS_DSS_CONTEXT_LOSTMEM_DSS_MEM_MASK                                                             (0x00000100U)
#define RM_DSS_DSS_CONTEXT_LOSTMEM_DSS_MEM_LOST                                                              (1U)
#define RM_DSS_DSS_CONTEXT_LOSTMEM_DSS_MEM_MAINTAINED                                                        (0U)

#define PM_DSS_DSS2_WKDEP_WKUPDEP_HDMIIRQ_DSP1_SHIFT                                    (2U)
#define PM_DSS_DSS2_WKDEP_WKUPDEP_HDMIIRQ_DSP1_MASK                                     (0x00000004U)
#define PM_DSS_DSS2_WKDEP_WKUPDEP_HDMIIRQ_DSP1_ENABLED                                   (1U)
#define PM_DSS_DSS2_WKDEP_WKUPDEP_HDMIIRQ_DSP1_DISABLED                                  (0U)

#define PM_DSS_DSS2_WKDEP_WKUPDEP_HDMIIRQ_IPU1_SHIFT                                    (4U)
#define PM_DSS_DSS2_WKDEP_WKUPDEP_HDMIIRQ_IPU1_MASK                                     (0x00000010U)
#define PM_DSS_DSS2_WKDEP_WKUPDEP_HDMIIRQ_IPU1_ENABLED                                   (1U)
#define PM_DSS_DSS2_WKDEP_WKUPDEP_HDMIIRQ_IPU1_DISABLED                                  (0U)

#define PM_DSS_DSS2_WKDEP_WKUPDEP_HDMIIRQ_DSP2_SHIFT                                    (5U)
#define PM_DSS_DSS2_WKDEP_WKUPDEP_HDMIIRQ_DSP2_MASK                                     (0x00000020U)
#define PM_DSS_DSS2_WKDEP_WKUPDEP_HDMIIRQ_DSP2_ENABLED                                   (1U)
#define PM_DSS_DSS2_WKDEP_WKUPDEP_HDMIIRQ_DSP2_DISABLED                                  (0U)

#define PM_DSS_DSS2_WKDEP_WKUPDEP_HDMIIRQ_EVE1_SHIFT                                    (6U)
#define PM_DSS_DSS2_WKDEP_WKUPDEP_HDMIIRQ_EVE1_MASK                                     (0x00000040U)
#define PM_DSS_DSS2_WKDEP_WKUPDEP_HDMIIRQ_EVE1_ENABLED                                   (1U)
#define PM_DSS_DSS2_WKDEP_WKUPDEP_HDMIIRQ_EVE1_DISABLED                                  (0U)

#define PM_DSS_DSS2_WKDEP_WKUPDEP_DSI1_C_DSP1_SHIFT                                     (12U)
#define PM_DSS_DSS2_WKDEP_WKUPDEP_DSI1_C_DSP1_MASK                                      (0x00001000U)
#define PM_DSS_DSS2_WKDEP_WKUPDEP_DSI1_C_DSP1_ENABLED                                    (1U)
#define PM_DSS_DSS2_WKDEP_WKUPDEP_DSI1_C_DSP1_DISABLED                                   (0U)

#define PM_DSS_DSS2_WKDEP_WKUPDEP_DSI1_C_SDMA_SHIFT                                     (13U)
#define PM_DSS_DSS2_WKDEP_WKUPDEP_DSI1_C_SDMA_MASK                                      (0x00002000U)
#define PM_DSS_DSS2_WKDEP_WKUPDEP_DSI1_C_SDMA_ENABLED                                    (1U)
#define PM_DSS_DSS2_WKDEP_WKUPDEP_DSI1_C_SDMA_DISABLED                                   (0U)

#define PM_DSS_DSS2_WKDEP_WKUPDEP_DSI1_C_IPU1_SHIFT                                     (14U)
#define PM_DSS_DSS2_WKDEP_WKUPDEP_DSI1_C_IPU1_MASK                                      (0x00004000U)
#define PM_DSS_DSS2_WKDEP_WKUPDEP_DSI1_C_IPU1_ENABLED                                    (1U)
#define PM_DSS_DSS2_WKDEP_WKUPDEP_DSI1_C_IPU1_DISABLED                                   (0U)

#define PM_DSS_DSS2_WKDEP_WKUPDEP_DSI1_C_DSP2_SHIFT                                     (15U)
#define PM_DSS_DSS2_WKDEP_WKUPDEP_DSI1_C_DSP2_MASK                                      (0x00008000U)
#define PM_DSS_DSS2_WKDEP_WKUPDEP_DSI1_C_DSP2_ENABLED                                    (1U)
#define PM_DSS_DSS2_WKDEP_WKUPDEP_DSI1_C_DSP2_DISABLED                                   (0U)

#define PM_DSS_DSS2_WKDEP_WKUPDEP_DSI1_C_EVE1_SHIFT                                     (16U)
#define PM_DSS_DSS2_WKDEP_WKUPDEP_DSI1_C_EVE1_MASK                                      (0x00010000U)
#define PM_DSS_DSS2_WKDEP_WKUPDEP_DSI1_C_EVE1_ENABLED                                    (1U)
#define PM_DSS_DSS2_WKDEP_WKUPDEP_DSI1_C_EVE1_DISABLED                                   (0U)

#define PM_DSS_DSS2_WKDEP_WKUPDEP_HDMIDMA_DSP1_SHIFT                                    (22U)
#define PM_DSS_DSS2_WKDEP_WKUPDEP_HDMIDMA_DSP1_MASK                                     (0x00400000U)
#define PM_DSS_DSS2_WKDEP_WKUPDEP_HDMIDMA_DSP1_ENABLED                                   (1U)
#define PM_DSS_DSS2_WKDEP_WKUPDEP_HDMIDMA_DSP1_DISABLED                                  (0U)

#define PM_DSS_DSS2_WKDEP_WKUPDEP_HDMIDMA_SDMA_SHIFT                                    (23U)
#define PM_DSS_DSS2_WKDEP_WKUPDEP_HDMIDMA_SDMA_MASK                                     (0x00800000U)
#define PM_DSS_DSS2_WKDEP_WKUPDEP_HDMIDMA_SDMA_ENABLED                                   (1U)
#define PM_DSS_DSS2_WKDEP_WKUPDEP_HDMIDMA_SDMA_DISABLED                                  (0U)

#define PM_DSS_DSS2_WKDEP_WKUPDEP_HDMIDMA_DSP2_SHIFT                                    (25U)
#define PM_DSS_DSS2_WKDEP_WKUPDEP_HDMIDMA_DSP2_MASK                                     (0x02000000U)
#define PM_DSS_DSS2_WKDEP_WKUPDEP_HDMIDMA_DSP2_ENABLED                                   (1U)
#define PM_DSS_DSS2_WKDEP_WKUPDEP_HDMIDMA_DSP2_DISABLED                                  (0U)

#define RM_DSS_SDVENC_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                     (0U)
#define RM_DSS_SDVENC_CONTEXT_LOSTCONTEXT_DFF_MASK                                      (0x00000001U)
#define RM_DSS_SDVENC_CONTEXT_LOSTCONTEXT_DFF_LOST                                       (1U)
#define RM_DSS_SDVENC_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                                 (0U)

#ifdef __cplusplus
}
#endif
#endif  /* HW_DSS_PRM_H_ */

