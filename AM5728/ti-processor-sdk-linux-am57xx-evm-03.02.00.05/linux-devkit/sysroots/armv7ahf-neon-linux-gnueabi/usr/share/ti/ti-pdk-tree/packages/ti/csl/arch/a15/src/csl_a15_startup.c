/**
 * \file   a15_startup.c
 *
 * \brief  Interrupt vector is copied to the internal Ram. After that the
 *         control is given to the application.
 *
 *  \copyright Copyright (C) 2013-2016 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/**
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <ti/csl/tistdtypes.h>
#include <ti/csl/csl_a15.h>
#include <ti/csl/csl_armGicAux.h>
#include <ti/csl/arch/a15/csl_a15_startup.h>

/* ========================================================================== */
/*                      Internal Function Declarations                        */
/* ========================================================================== */

#define MMU_PAGETABLE_ALIGN_SIZE                           (16U * 1024U)

#define CSL_ENABLE_CACHE_MMU /* Enable MMU & CACHE */

#if defined(CSL_ENABLE_MMU)
#define CSL_MMU_DESC_TYPE_LONG /* MMU to use long descriptor */
#elif defined(CSL_ENABLE_CACHE_MMU)
#define CSL_MMU_DESC_TYPE_LONG /* MMU to use long descriptor */
#endif

void CSL_A15_INIT_copyVectorTable(void);

void CSL_A15_INIT_startup(void);

extern Int32 main(void);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Vector table */
static Uint32 const vecTbl[14]=
{
    0xE59FF018U,    /* Opcode for loading PC with the contents of [PC + 0x18] */
    0xE59FF018U,    /* Opcode for loading PC with the contents of [PC + 0x18] */
    0xE59FF018U,    /* Opcode for loading PC with the contents of [PC + 0x18] */
    0xE59FF018U,    /* Opcode for loading PC with the contents of [PC + 0x18] */
    0xE59FF014U,    /* Opcode for loading PC with the contents of [PC + 0x14] */
    0xE24FF008U,    /* Opcode for loading PC with (PC - 8) (eq. to while(1)) */
    0xE59FF010U,    /* Opcode for loading PC with the contents of [PC + 0x10] */
    0xE59FF010U,    /* Opcode for loading PC with the contents of [PC + 0x10] */
    (Uint32)(&Entry),
    (Uint32)(&UndefInstHandler),
    (Uint32)(&SVC_Handler),
    (Uint32)(&AbortHandler),
    (Uint32)(&IRQHandler),
    (Uint32)(&FIQHandler)
};

#if 1
CSL_ArmGicDistIntrf distrIntrf;
CSL_ArmGicCpuIntrf gCpuIntrf;
#endif

/** \brief Page table configuration.*/
#if defined(CSL_ENABLE_MMU) || defined(CSL_ENABLE_CACHE_MMU)/* Enable MMU */
#if defined(CSL_MMU_DESC_TYPE_LONG) /* Enable to use long descriptor */

/** \brief Page tables to hold physical to virtual address mapping. The start
           address of the page table must be aligned at 16K boundary */
    CSL_A15MmuLongDescObj mmuObj
     __attribute__((aligned(MMU_PAGETABLE_ALIGN_SIZE)));

    CSL_A15MmuLongDescAttr mmuAttr0;
    CSL_A15MmuLongDescAttr mmuAttr1;
    CSL_A15MmuLongDescAttr mmuAttr2;
#else

/** \brief Page tables to hold physical to virtual address mapping. The start
           address of the page table must be aligned at 16K boundary */
    #pragma DATA_ALIGN(mmuobj, MMU_PAGETABLE_ALIGN_SIZE);
    CSL_A15MmuShortDescObj mmuobj;
    CSL_A15MmuShortDescObj mmuobj
     __attribute__((aligned(MMU_PAGETABLE_ALIGN_SIZE)));

    CSL_A15MmuShortDescAttr mmuAttr0;
    CSL_A15MmuShortDescAttr mmuAttr1;
    CSL_A15MmuShortDescAttr mmuAttr2;
    CSL_A15MmuShortDescAttr mmuAttr3;
#endif
#endif

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/**
 * \brief   This function does two operations:\n
 *          1> Copies an array which contains vector table values to the
 *             processor's vector table space.\n
 *          2> Then it calls the main() function.\n
 *
 * \param   None.
 *
 * \retval  None.
 *
 * \note    This function is the first function that needs to be called in a
 *          system. This should be set as the entry point in the linker script
 *          file if the ELF executable is to loaded via a debugger on the
 *          target. This function never returns, but gives control to the
 *          application entry point.
 **/
Uint32 start_boot(void); /*for misra warnings*/
Uint32 start_boot(void)
{
    /* Copy the vector table to desired location.  */
    CSL_A15_INIT_copyVectorTable();

    /* Configure system */
    CSL_A15_INIT_startup();

    /* Calling the main */
    main();

    while(1)
    {}
}

/* This is a local function to trap any spurious or not configured
   interrupt */
static void CSL_armGicDefaultHandler(void* arg)
{
  /* Spurious interrupt could have happened
   * No action
   */
  return;
}

/**
 * \brief   This function copies the vector table to a location in OCMC
 *          RAM and sets the vector base address register.
 *
 * \param   None.
 * \retval  None.
 *
 * Note: The default vector table base is in OCMC RAM, but can be moved to
 *       other locations, to make some more space in OCMC RAM for relocating any
 *       other code, if desired. The vector table can be placed anywhere in the
 *       memory map. If the entire code is intended to be run from DDR, it can be
 *       placed in DDR also. In this case, only vector base address register need
 *       to be set with the base address of the vector table.
 */
void CSL_A15_INIT_copyVectorTable(void)
{
#if defined(SOC_K2H) || defined (SOC_K2L) || defined(SOC_K2K) || defined(SOC_K2E) || defined (SOC_K2G)
   /* vectors in MSMCSRAM for KeyStone */
    uint32_t vectorBase =  CSL_MSMC_SRAM_REGS;
    uint32_t ramSize    =  CSL_MSMC_SRAM_REGS_SIZE;
    vectorBase = vectorBase + ramSize - 0x400U;
#else
   /* vectors in OCMC RAM for TDA/AM57x devices */
    Uint32 vectorBase = 0x40300000U;
    Uint32 ocmcRamSize = 512U * 1024U;
    vectorBase = vectorBase + ocmcRamSize - 0x400U;
#endif

    Uint32 *dest = (Uint32 *)vectorBase;
    Uint32 *src =  (Uint32 *)vecTbl;
    Uint32 count;

    CSL_a15SetVectorTable(vectorBase);

    for(count = 0; count < sizeof(vecTbl)/sizeof(vecTbl[0]); count++)
    {
        dest[count] = src[count];
    }
}

#if 1
void INTCCommonIntrHandler(void); /*for misra warnings*/
void INTCCommonIntrHandler(void)
{
    CSL_armGicCommonIntrHandler(&gCpuIntrf);
}
#endif

void CSL_A15_INIT_startup(void)
{
#if defined(CSL_ENABLE_MMU) || defined(CSL_ENABLE_CACHE_MMU) /* Enable MMU */
#if defined(CSL_MMU_DESC_TYPE_LONG) /* Enable to use long descriptor */
    uint32_t phyAddr = 0U;

    mmuObj.numFirstLvlEntires = CSL_A15_MMU_LONG_DESC_LVL1_ENTIRES;
    mmuObj.numSecondLvlEntires = CSL_A15_MMU_LONG_DESC_LVL2_ENTIRES;
    mmuObj.mairEntires = CSL_A15_MMU_MAIR_LEN_BYTES;
    mmuObj.mairAttr[0] = 0x44U;
    mmuObj.mairAttr[1] = 0x0U;
    mmuObj.mairAttr[2] = 0xFFU;
    CSL_a15InitMmuLongDesc(&mmuObj);

    CSL_a15InitMmuLongDescAttrs(&mmuAttr0);
    CSL_a15InitMmuLongDescAttrs(&mmuAttr1);
    CSL_a15InitMmuLongDescAttrs(&mmuAttr2);

    mmuObj.mairAttr[0] = 0x44U;
    mmuObj.mairAttr[1] = 0x0U;
    mmuObj.mairAttr[2] = 0xFFU;
    CSL_a15SetMmuMair(0, mmuObj.mairAttr[0]);
    CSL_a15SetMmuMair(1U, mmuObj.mairAttr[1]);
    CSL_a15SetMmuMair(2U, mmuObj.mairAttr[2]);

    mmuAttr0.type = CSL_A15_MMU_LONG_DESC_TYPE_BLOCK;
    mmuAttr0.accPerm = 0U;
    mmuAttr0.shareable = 2U;
    mmuAttr0.attrIndx = 1U;

#if defined(SOC_K2H) || defined (SOC_K2L) || defined(SOC_K2K) || defined(SOC_K2E) || defined (SOC_K2G)
    /* Add KeyStone device IP memories */
    for (phyAddr = 0x0002200000U; phyAddr < 0x03000000U; phyAddr += 0x00200000U)
    {
        CSL_a15SetMmuSecondLevelLongDesc(&mmuObj, (void *)phyAddr, (void *)phyAddr, &mmuAttr0);
    }
#endif

    for (phyAddr = 0x20000000U; phyAddr < 0x60000000U; phyAddr += 0x00200000U)
    {
        CSL_a15SetMmuSecondLevelLongDesc(&mmuObj, (void *)phyAddr, (void *)phyAddr, &mmuAttr0);
    }

    mmuAttr1.type = CSL_A15_MMU_LONG_DESC_TYPE_BLOCK;
    mmuAttr1.accPerm = 0U;
    mmuAttr1.shareable = 2U;
    mmuAttr1.attrIndx = 2U;

    for (phyAddr = 0x80000000U; phyAddr < 0xA0000000U; phyAddr += 0x00200000U)
    {
        CSL_a15SetMmuSecondLevelLongDesc(&mmuObj, (void *)phyAddr, (void *)phyAddr, &mmuAttr1);
    }

    mmuAttr2.type = CSL_A15_MMU_LONG_DESC_TYPE_BLOCK;
    mmuAttr2.accPerm = 0U;
    mmuAttr2.attrIndx = 0U;

    for (mmuAttr2.phyAddr[0U] = 0xA0000000U; mmuAttr2.phyAddr[0U] < 0xB0000000U;
        mmuAttr2.phyAddr[0U] += 0x00200000U)
    {
        CSL_a15SetMmuSecondLevelLongDesc(&mmuObj, (void *)phyAddr, (void *)phyAddr, &mmuAttr2);
    }

#if defined(SOC_K2H) || defined (SOC_K2L) || defined(SOC_K2K) || defined(SOC_K2E) || defined (SOC_K2G)
    /* For Keystone add MSMCRAM */
    mmuAttr1.type = CSL_A15_MMU_LONG_DESC_TYPE_BLOCK;
    mmuAttr1.accPerm = 0U;
    mmuAttr1.shareable = 2U;
    mmuAttr1.attrIndx = 2U;

    for (phyAddr = CSL_MSMC_SRAM_REGS; phyAddr < (CSL_MSMC_SRAM_REGS + CSL_MSMC_SRAM_REGS_SIZE); phyAddr += 0x00200000U)
    {
        CSL_a15SetMmuSecondLevelLongDesc(&mmuObj, (void *)phyAddr, (void *)phyAddr, &mmuAttr1);
    }
#endif


    CSL_a15EnableMmu();
#if defined(CSL_ENABLE_CACHE_MMU) /* Enable CACHE */
    CSL_a15EnableCache();
#endif
#else
    mmuobj.numFirstLvlEntires = CSL_A15_MMU_SHORT_DESC_LVL1_ENTIRES;
    CSL_a15InitMmuShortDesc(&mmuobj);

    CSL_a15InitMmuShortDescAttrs(&mmuAttr0);
    CSL_a15InitMmuShortDescAttrs(&mmuAttr1);
    CSL_a15InitMmuShortDescAttrs(&mmuAttr2);
    CSL_a15InitMmuShortDescAttrs(&mmuAttr3);

    mmuAttr0.type = CSL_A15_MMU_SHORT_DESC_TYPE_SECTION;
    mmuAttr0.accPerm = 0U;

    for (phyAddr = 0x00000000U; phyAddr < 0x80000000U; phyAddr += 0x00100000)
    {
        CSL_a15SetMmuFirstLevelShortDesc(&mmuobj, (void *)phyAddr, (void *)phyAddr, &mmuAttr0);
    }

    mmuAttr1.type = CSL_A15_MMU_SHORT_DESC_TYPE_SECTION;
    mmuAttr1.bufferable = 1U;
    mmuAttr1.accPerm = 3U;
    mmuAttr1.tex = 5U;
    mmuAttr1.nonSecure = 1U;

    for (phyAddr = 0x80000000U; phyAddr < 0xA0000000U; phyAddr += 0x00100000)
    {
        CSL_a15SetMmuFirstLevelShortDesc(&mmuobj, (void *)phyAddr, (void *)phyAddr, &mmuAttr1);
    }

    mmuAttr2.type = CSL_A15_MMU_SHORT_DESC_TYPE_SECTION;
    mmuAttr2.accPerm = 0U;

    for (phyAddr = 0xA0000000U; phyAddr < 0xC0000000U; phyAddr += 0x00100000)
    {
        CSL_a15SetMmuFirstLevelShortDesc(&mmuobj, (void *)phyAddr, (void *)phyAddr, &mmuAttr2);
    }

    mmuAttr3.type = CSL_A15_MMU_SHORT_DESC_TYPE_SECTION;
    mmuAttr3.accPerm = 0U;

    for (phyAddr = 0xC0000000U; phyAddr < 0xE0000000U; phyAddr += 0x00100000)
    {
        CSL_a15SetMmuFirstLevelShortDesc(&mmuobj, (void *)phyAddr, (void *)phyAddr, &mmuAttr3);
    }

#if defined(CSL_ENABLE_CACHE_MMU) /* Enable CACHE */
    CSL_a15EnableCache();
    CSL_a15InvAllDataCache();
    CSL_a15InvAllInstrCache();
    CSL_a15EnableCache();
#endif
    CSL_a15EnableMmu();
#endif
#endif

#if 1
    gCpuIntrf.gicDist = &distrIntrf;
    gCpuIntrf.cpuIntfBasePtr = (void *)SOC_INTC_MPU_PHYS_CPU_IF_BASE;
    distrIntrf.distBasePtr = (void *)SOC_INTC_MPU_DISTRIBUTOR_BASE;
    gCpuIntrf.initStatus = (Uint32)FALSE;
    gCpuIntrf.gicDist->initStatus = (Uint32)FALSE;
    gCpuIntrf.pDefaultIntrHandlers = &CSL_armGicDefaultHandler;
    gCpuIntrf.pDefaultUserParameter = NULL;

    CSL_armGicInit(&gCpuIntrf);
#endif
}
