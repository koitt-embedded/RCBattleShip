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
 * \file  mailbox_receiver.c
 * \brief This acts as mailbox receiver
**/

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <stdint.h>
#include <stdio.h>
#include <ti/csl/csl_mailbox.h>
#include <ti/csl/soc.h>
#include "mailbox_app.h"
#if defined (SOC_AM572x) || defined (SOC_AM571x)
#include <ti/board/board.h>
#endif
#include <ti/csl/example/utils/uart_console/inc/uartConfig.h>

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */
#define INTERRUPT_MODE  (0)
#define POLLED_MODE     (1)

#if defined (SOC_AM572x) || defined (SOC_AM571x)
/* Receiver Will run on A15 */
#define MAILBOX_BASE_ADDRESS    CSL_MPU_MAILBOX2_REGS
#endif

#if defined (SOC_TDA2XX) || defined (SOC_TDA2EX) || defined (SOC_DRA75X) || defined (SOC_TDA3XX) || defined (SOC_DRA78X)
#define MAILBOX_BASE_ADDRESS SOC_MAILBOX2_BASE
#endif
#define MAILBOX_USER            (0U)

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
/*To use UARTConfigPuts function for prints*/
#if defined (SOC_AM572x) || defined (SOC_AM571x)
uint32_t uartBaseAddr = CSL_MPU_UART3_REGS;
#endif
#if defined (SOC_TDA2XX) || defined (SOC_TDA2EX) || defined (SOC_DRA75X)
uint32_t uartBaseAddr = SOC_UART1_BASE;
#endif
#if defined (SOC_TDA3XX) || defined (SOC_DRA78X)
uint32_t uartBaseAddr = SOC_UART3_BASE;
#endif

volatile uint32_t msg  = 0, msgStatus = MESSAGE_INVALID;
volatile uint32_t done = 1;
uint32_t          opMode = 1;

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
    /* Set the UART Parameters */
    UARTConfigInit(uartBaseAddr, BAUD_RATE_115200, UART_WORD_LENGTH_8, UART_STOP_BIT_1, UART_NO_PARITY,
                    UART_16x_MODE);
#endif
#if defined (SOC_TDA3XX) || defined (SOC_DRA78X)
    /*Pad configurations */
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_IO_SPI1_SCLK,0x00040001);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_IO_SPI1_CS0,0x00000001);
    /* Set the UART Parameters */
    UARTConfigInit(uartBaseAddr, BAUD_RATE_115200, UART_WORD_LENGTH_8, UART_STOP_BIT_1, UART_NO_PARITY,
                    UART_16x_MODE);
#endif
}

int main(void)
{

    /*Pad configuration and PRCM enable*/
    padConfig_prcmEnable();
    
    UARTConfigPuts(uartBaseAddr,"\nReceiver: Mailbox Application", -1);

    MailboxEnableNewMsgInt(MAILBOX_BASE_ADDRESS, MAILBOX_USER,
                            MAILBOX_QUEUE_0);

    while (done)
    {
        if (opMode == POLLED_MODE)
        {
            while (msgStatus == MESSAGE_INVALID)
            {
                msgStatus =
                    MailboxGetMessage(MAILBOX_BASE_ADDRESS, MAILBOX_QUEUE_0,
                                        (uint32_t *) &msg);
            }
        }
        if (msgStatus == MESSAGE_VALID)
        {
            if (msg == MAILBOX_APP_A15_MSG)
            {
                UARTConfigPuts(uartBaseAddr,"\nReceiver: A15 Core is up", -1);
            }
            if (msg == MAILBOX_APP_DSP_MSG)
            {
                UARTConfigPuts(uartBaseAddr,"\nReceiver: DSP Core is up", -1);
            }
            if (msg == MAILBOX_APP_M4_MSG)
            {
                UARTConfigPuts(uartBaseAddr,"\nReceiver: M4 Core is up", -1);
            }
            msg       = 0;
            msgStatus = MESSAGE_INVALID;
        }
    }
    return 0;
}
/********************************* End of file ******************************/

