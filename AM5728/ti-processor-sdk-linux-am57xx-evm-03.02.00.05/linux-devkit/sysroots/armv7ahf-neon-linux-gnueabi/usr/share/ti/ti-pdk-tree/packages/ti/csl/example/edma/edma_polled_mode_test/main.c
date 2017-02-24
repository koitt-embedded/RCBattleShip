/*
 *  Copyright (C) 2013-2016 Texas Instruments Incorporated - http://www.ti.com/
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
 *  \file   main.c
 *
 *  \brief This file demonstrates polled mode of dma transfer mechanism.
 *         Buffers (src and dest) are needed for mem-2-mem data transfers.
 *         This define is for the MAXIMUM size and hence the maximum data
 *         which could be transferred using the sample test case below.
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
 **/

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <stdint.h>
#include <ti/csl/csl_types.h>
#include <ti/csl/csl_edma.h>
#include <ti/csl/hw_types.h>
#if defined (__ARM_ARCH_7A__)
#include <ti/csl/csl_a15.h>
#endif
#include <ti/csl/soc.h>
#if defined (SOC_AM572x) || defined (SOC_AM571x)
#include <ti/board/board.h>
#endif
#include <ti/csl/example/utils/uart_console/inc/uartConfig.h>

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */
/* MAX ACOUNT */
#define MAX_ACOUNT                  (64U)
/* MAX BCOUNT */
#define MAX_BCOUNT                  (1U)
/* MAX CCOUNT */
#define MAX_CCOUNT                  (1U)

#define MAX_BUFFER_SIZE             (MAX_ACOUNT * MAX_BCOUNT * MAX_CCOUNT)

#define EDMA3_CC_XFER_COMPLETION_INT_DSP                (38U)

#define EDMA3_CC_XFER_COMPLETION_INT_A8                 (12U)
#define EDMA3_CC_XFER_COMPLETION_INT_M3VPSS             (63U)
#define EDMA3_CC_XFER_COMPLETION_INT_M3VIDEO            (62U)
#define EDMA3_CC_XFER_COMPLETION_INT_A15                (12U)
#define EDMA3_CC_XFER_COMPLETION_INT_M4                 (34U)

#if defined (_TMS320C6X)
#define EDMA3_CC_XFER_COMPLETION_INT EDMA3_CC_XFER_COMPLETION_INT_DSP
#elif defined (__ARM_ARCH_7A__)
#define EDMA3_CC_XFER_COMPLETION_INT EDMA3_CC_XFER_COMPLETION_INT_A15
#elif defined (__TI_ARM_V7M4__)
#define EDMA3_CC_XFER_COMPLETION_INT EDMA3_CC_XFER_COMPLETION_INT_M4
#endif

#define EDMA3_CC_REGION_A8                              (0U)
#define EDMA3_CC_REGION_M3VPSS                          (5U)
#define EDMA3_CC_REGION_M3VIDEO                         (4U)
#define EDMA3_CC_REGION_A15                             (0U)
#define EDMA3_CC_REGION_M4                              (1U)

#define EDMA3_CC_REGION_DSP                             (2U)

#if defined (_TMS320C6X)
#define EDMA3_CC_REGION EDMA3_CC_REGION_DSP
#elif defined (__ARM_ARCH_7A__)
#define EDMA3_CC_REGION EDMA3_CC_REGION_A15
#elif defined (__TI_ARM_V7M4__)
#define EDMA3_CC_REGION EDMA3_CC_REGION_M4
#endif

#if defined (__ARM_ARCH_7A__)
#ifndef SOC_EDMA_TPCC_BASE
#if (defined (SOC_AM572x) || defined (SOC_AM571x))
#define SOC_EDMA_TPCC_BASE CSL_MPU_EDMA_TPCC_REGS
#endif
#endif
#endif

#ifndef SOC_EDMA_TPCC_BASE /* Temporary HACK for M4
                            * as 0x43300000 is bit band region*/
#if defined (__TI_ARM_V7M4__)
/* EDMA region 0x43300000 mappped to 0xA0000000 */
#define SOC_EDMA_TPCC_BASE      (0x63300000U)
#endif
#endif

#if defined (__TI_ARM_V7M4__)
#if (defined (SOC_AM572x) || defined (SOC_AM571x))
/* EDMA region 0x43300000 mappped to 0xA0000000 */
#undef SOC_EDMA_TPCC_BASE
#define SOC_EDMA_TPCC_BASE      (0x63300000U)
#endif
#endif

#if defined (__ARM_ARCH_7A__)
#define IRQ_XBAR_INST_NO XBAR_INST_MPU_IRQ_12
#elif defined (__TI_ARM_V7M4__)
#define IRQ_XBAR_INST_NO XBAR_INST_IPU1_IRQ_34
#elif defined (_TMS320C6X)
#define IRQ_XBAR_INST_NO XBAR_INST_DSP1_IRQ_38
#endif

#if defined (SOC_AM572x) || defined (SOC_TDA2XX) || defined (SOC_DRA75X) || defined (SOC_AM571x) || defined (SOC_TDA2EX) || defined (SOC_TDA3XX) || defined (SOC_DRA78X)
#if defined (_TMS320C6X)
#if defined (SOC_AM572x) || defined (SOC_AM571x)
#define EDMA_U_BASE CSL_DSP_EDMA_CC_REGS
#else
#define EDMA_U_BASE SOC_EDMA_CC_BASE
#endif
#else
#define EDMA_U_BASE SOC_EDMA_TPCC_BASE
#endif
#endif

#if !defined (__ARM_ARCH_7A__) && !defined (BUILD_GCC)

#ifdef __cplusplus
#pragma DATA_SECTION(".my_sect_ddr");
#else
#pragma DATA_SECTION(_srcBuff1, ".my_sect_ddr");
#endif  /* #ifdef __cplusplus */
signed char       _srcBuff1[MAX_BUFFER_SIZE];

#ifdef __cplusplus
#pragma DATA_SECTION(".my_sect_ddr");
#else
#pragma DATA_SECTION(_dstBuff1, ".my_sect_ddr");
#endif  /* #ifdef __cplusplus */
signed char       _dstBuff1[MAX_BUFFER_SIZE];

#else
signed char __attribute__((section(".my_sect_ddr"))) _srcBuff1[MAX_BUFFER_SIZE];
signed char __attribute__((section(".my_sect_ddr"))) _dstBuff1[MAX_BUFFER_SIZE];
#endif

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
#if defined (SOC_AM572x) || defined (SOC_AM571x)
uint32_t uartBaseAddr = CSL_MPU_UART3_REGS;
#endif
#if defined (SOC_TDA2XX) || defined (SOC_TDA2EX) || defined (SOC_DRA75X)
uint32_t uartBaseAddr = SOC_UART1_BASE;
#endif
#if defined (SOC_TDA3XX) || defined (SOC_DRA78X)
uint32_t uartBaseAddr = SOC_UART3_BASE;
#endif

uint32_t          edma_ch_num   = 1;
uint32_t          edma_tcc_num  = 1;
uint32_t          edma_evtq_num = 0;

uint32_t          region        = EDMA3_CC_REGION;

signed char      *srcBuff1;
signed char      *dstBuff1;

uint32_t          base_address = EDMA_U_BASE;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
int32_t dma_polled(uint32_t ch_num, uint32_t tcc_num, uint32_t evtq_num,
                   uint32_t aCnt, uint32_t bCnt,
                   uint32_t cCnt);
static void edma_wait_for_transfer_completion(uint32_t tcc_num);

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
void padConfig_prcmEnable()
{
#if defined (SOC_AM572x) || defined (SOC_AM571x)
    /*Pad configurations */
    Board_initCfg boardCfg;
    boardCfg = BOARD_INIT_UNLOCK_MMR | BOARD_INIT_UART_STDIO | 
               BOARD_INIT_MODULE_CLOCK | BOARD_INIT_PINMUX_CONFIG;
    Board_init(boardCfg);
#endif
#if defined (SOC_TDA2XX) || defined (SOC_TDA2EX) || defined (SOC_DRA75X)
    /*Pad configurations */
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_UART1_RXD,0x00040000);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_UART1_TXD,0x00000000);
    UARTConfigInit(uartBaseAddr, BAUD_RATE_115200, UART_WORD_LENGTH_8, UART_STOP_BIT_1, UART_NO_PARITY,
                   UART_16x_MODE);
#endif
#if defined (SOC_TDA3XX) || defined (SOC_DRA78X)
    /*Pad configurations */
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_IO_SPI1_SCLK,0x00040001);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_IO_SPI1_CS0,0x00000001);
    UARTConfigInit(uartBaseAddr, BAUD_RATE_115200, UART_WORD_LENGTH_8, UART_STOP_BIT_1, UART_NO_PARITY,
                   UART_16x_MODE);
#endif
}

int32_t dma_polled(uint32_t ch_num, uint32_t tcc_num, uint32_t evtq_num,
                   uint32_t aCnt, uint32_t bCnt,
                   uint32_t cCnt)
{
    volatile uint32_t i, error = TRUE, count;
    EDMA3CCPaRAMEntry edmaParam;

    srcBuff1 = (signed char *) (_srcBuff1);
    dstBuff1 = (signed char *) (_dstBuff1);

    UARTConfigPuts(uartBaseAddr,"\nDma Polled Mode test", -1);

    /*
     * Initialize the source address with a pattern
     * initialize dst address with zero/another pattern (optional)
     */
    for (count = 0U; count < (aCnt * bCnt * cCnt); count++)
    {
        srcBuff1[count] = (int) 0xAA;

        dstBuff1[count] = 0;
    }

#if defined (__ARM_ARCH_7A__)
    CSL_a15WbDataCache((void *)_srcBuff1, MAX_BUFFER_SIZE);
    CSL_a15WbDataCache((void *)_dstBuff1, MAX_BUFFER_SIZE);
#endif
    
    EDMA3RequestChannel(base_address, EDMA3_CHANNEL_TYPE_DMA, ch_num, tcc_num,
                        evtq_num);

    edmaParam.opt      = 0;
    edmaParam.srcAddr  = (uint32_t) srcBuff1;
    edmaParam.destAddr = (uint32_t) dstBuff1;
    edmaParam.aCnt     = aCnt;
    edmaParam.bCnt     = bCnt;
    edmaParam.cCnt     = cCnt;
    edmaParam.srcBIdx  = aCnt;
    edmaParam.destBIdx = aCnt;
    edmaParam.srcCIdx  = aCnt;
    edmaParam.destCIdx = aCnt;
    edmaParam.linkAddr = 0xFFFFU;
    edmaParam.opt     |=
        (EDMA3_OPT_TCINTEN_MASK | EDMA3_OPT_ITCINTEN_MASK |
         ((tcc_num << EDMA3_OPT_TCC_SHIFT) & EDMA3_OPT_TCC_MASK));

    EDMA3SetPaRAM(base_address, ch_num, &edmaParam);

    /*
     * Transfer is done in a sync mode
     * Number of triggers required are bCnt * cCnt
     */
    for (i = 0; i < (bCnt * cCnt); i++)
    {
        EDMA3EnableTransfer(base_address, ch_num, EDMA3_TRIG_MODE_MANUAL);
        edma_wait_for_transfer_completion(tcc_num);
        EDMA3ClrIntr(base_address, tcc_num);
    }

#if defined (__ARM_ARCH_7A__)
    CSL_a15InvDataCache((void *)_srcBuff1, MAX_BUFFER_SIZE);
    CSL_a15InvDataCache((void *)_dstBuff1, MAX_BUFFER_SIZE);
#endif

    for (i = 0; i < (aCnt * bCnt * cCnt); i++)
    {
        if (srcBuff1[i] != dstBuff1[i])
        {
            error = FALSE;
            UARTConfigPuts(uartBaseAddr,"\nError matching value at src and dst address", -1);
            break;
        }
    }

    return error;
}

int main(void)
{
    padConfig_prcmEnable();

    UARTConfigPuts(uartBaseAddr,"\nEDMA App", -1);

    EDMAsetRegion(region);

    /* Do EDMA init Done once in the beginning of application */
    EDMA3Init(base_address, 0);

    if (dma_polled(edma_ch_num, edma_tcc_num, edma_evtq_num, MAX_ACOUNT,
                   MAX_BCOUNT, MAX_CCOUNT) == TRUE)
    {
        UARTConfigPuts(uartBaseAddr,"\nEDMA polled test transfer is complete", -1);
    }

    EDMA3Deinit(base_address, 0);

    return 0;
}

static void edma_wait_for_transfer_completion(uint32_t tcc_num)
{
    if(tcc_num < 32)
    {
        while ((EDMA3GetIntrStatus(base_address) & (0x1 << tcc_num)) !=
            (0x1 << tcc_num)) ;
    }
    else
    {
        while ((EDMA3IntrStatusHighGet(base_address) &
               (0x1 << (tcc_num - 32))) !=
               (0x1 << (tcc_num - 32))) ;
    }
}

/********************************* End of file ******************************/
