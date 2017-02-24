/*
 *  Copyright (C) 2016 Texas Instruments Incorporated - http://www.ti.com/
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

#ifndef CSLR_SOC_DRA78X_IN_H_
#define CSLR_SOC_DRA78X_IN_H_

#include <ti/csl/soc/tda3xx/cslr_soc.h>

/******************************************************************************\
 * Interrupt Event IDs
 \*****************************************************************************/
/* McASP Interrupts
     All are crossbar mapped please cross check before use */

/* McASP1 RX interrupt                                                        */
#define    CSL_INTC_EVENTID_MCASP0_RXINT        (58U)
/* McASP1 TX interrupt                                                        */
#define    CSL_INTC_EVENTID_MCASP0_TXINT        (59U)
/* McASP2 RX interrupt                                                        */
#define    CSL_INTC_EVENTID_MCASP1_RXINT        (60U)
/* McASP2 TX interrupt                                                        */
#define    CSL_INTC_EVENTID_MCASP1_TXINT        (61U)
/* McASP3 RX interrupt                                                        */
#define    CSL_INTC_EVENTID_MCASP2_RXINT        (91U)
/* McASP3 TX interrupt                                                        */
#define    CSL_INTC_EVENTID_MCASP2_TXINT        (92U)

/*************************** EDMA RELATED DEFINES  ****************************/
/* EDMA channel synchronization events                                        */

/* McASP0 Receive Event                                                       */
#define CSL_EDMA3_CHA_MCASP0_RX             0
/* McASP0 Transmit Event                                                      */
#define CSL_EDMA3_CHA_MCASP0_TX             1
/* McASP1 Receive Event                                                       */
#define CSL_EDMA3_CHA_MCASP1_RX             2
/* McASP1 Transmit Event                                                      */
#define CSL_EDMA3_CHA_MCASP1_TX             3
/* McASP2 Receive Event                                                       */
#define CSL_EDMA3_CHA_MCASP2_RX             4
/* McASP2 Transmit Event                                                      */
#define CSL_EDMA3_CHA_MCASP2_TX             5
/* McASP3 Receive Event                                                       */

#endif /* CSLR_SOC_DRA78X_IN_H_ */
