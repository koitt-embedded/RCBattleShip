/**
 *   @file  csl_armGicAux.h
 *
 *   @brief
 *      This is the GIC Auxilary Header File which exposes the various
 *      CSL Functional Layer API's to configure the GIC Module.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2002, 2003, 2004, 2005, 2008, 2009, 2016 Texas Instruments, Inc.
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

#ifndef CSL_ARM_GICDAUX_V0_H_
#define CSL_ARM_GICDAUX_V0_H_

#include <ti/csl/src/ip/arm_gic/V0/csl_armGic.h>
#include <ti/csl/csl_a15.h>
#if defined (SOC_AM572x) || defined (SOC_TDA2XX) || defined (SOC_DRA75X) || defined (SOC_AM571x) || defined (SOC_TDA2EX)
/*
 * The Aux layer is used for OSAL AM335x/AM437x
 * Since the interrupt implementation for A15
 * is done in CSL lib which does not exist
 * for AM335x and AM437x, we keep the original
 * CSL implementation
 */
#include <ti/csl/arch/a15/interrupt.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if defined (SOC_AM572x) || defined (SOC_TDA2XX) || defined (SOC_DRA75X) || defined (SOC_AM571x) || defined (SOC_TDA2EX)
/*
 * The Aux layer is used for OSAL AM335x/AM437x
 * Since the interrupt implementation for A15
 * is done in CSL lib which does not exist
 * for AM335x and AM437x, we keep the original
 * CSL implementation
 */
extern IntrFuncPtr fnRAMVectors[];
extern void       *argArray[];
#endif

/******************************************************************************\
* global macro declarations
\******************************************************************************/

/** @addtogroup  CSL_ARM_GICD_V0AUX_V0_ENUM
 @{ */

/**
@}
*/

/** @addtogroup  CSL_ARM_GICD_V0AUX_V0_FUNCTION
 @{ */

/** ============================================================================
 *   @n@b CSL_armGicInit
 *
 *   @b Description
 *   @n This function is used to initialize MMU registers.
 *
 *   @b Arguments
 *   @n  None
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Example
 *   @verbatim

        CSL_armGicInit();

     @endverbatim
 * =============================================================================
 */
/* prototype defintions for misrac warning fix */
static inline void CSL_armGicInit(CSL_ArmGicCpuIntrf *cpuIntrf);
static inline void CSL_armGicInit(CSL_ArmGicCpuIntrf *cpuIntrf)
{
    CSL_ArmgicDistributorRegs *gicDistInst = NULL;
    CSL_ArmgicGiccRegs *gicCpuInst = NULL;
    Uint32 gicDistIcType = 0;
    Uint32 maskedValue = 0;
    Uint32 intrNum = 0, i = 0, j = 0, intActiveReg = 0;
    Uint32 ctrlConfigval = 0;
    Uint32 PriorityStep = 0;
    Uint32 size;

    gicCpuInst = (CSL_ArmgicGiccRegs *)(cpuIntrf->cpuIntfBasePtr);
    gicDistInst = (CSL_ArmgicDistributorRegs *)(cpuIntrf->gicDist->distBasePtr);

    if(FALSE == cpuIntrf->gicDist->initStatus)
    {
        cpuIntrf->cpuId = 0U;

        /* Set binary point register */
        /* TODO: Need to check this value
        ** cpuIntrf->gicConfig.nonSecureBinaryPoint = GicNsBinaryPointGet();
        */
        cpuIntrf->gicDist->nonSecureBinaryPoint = 0x03;

        /* Initialize GIC instance */
        gicDistIcType = gicDistInst->GICD_TYPER;

        /*  Get the number of interrupt lines supported */
        maskedValue = gicDistIcType & 0x1fU;
        /*  From the mapping get the exact number of interrupts supported */
        maskedValue = (maskedValue + 1U) * 32U;
        /*  Check for max interrupts */
        if (maskedValue > 1020U)
        {
            maskedValue = 1020U;
        }
        cpuIntrf->gicDist->maxValidIntr = maskedValue;

        /* Get the number of CPU interfaces implemented */
        maskedValue = ((gicDistIcType & 0xe0U) >> 5U) + 1U;
        /* Check for max no of CPU interface */
        if (maskedValue > CSL_ARM_GIC_MAX_CPU_NO)
        {
            maskedValue = CSL_ARM_GIC_MAX_CPU_NO;
        }
        cpuIntrf->gicDist->noCpuIntf = maskedValue;

        /* Find the priority levels implemented */
        for(intrNum = 0; intrNum < cpuIntrf->gicDist->maxValidIntr; intrNum++)
        {
                gicDistInst->GICD_IPRIORITYR[intrNum] = (0xFFU);
                PriorityStep = gicDistInst->GICD_IPRIORITYR[intrNum];

                /* Extract the priority level */
                cpuIntrf->gicDist->noPriorityStep = ((~PriorityStep) & 0x0FU) + 1U;
                break;
        }

        /* Register the default handler for all interrupts */
        for(intrNum = 0; intrNum < cpuIntrf->gicDist->maxValidIntr; intrNum++)
        {
#if defined (SOC_AM572x) || defined (SOC_TDA2XX) || defined (SOC_DRA75X) || defined (SOC_AM571x) || defined (SOC_TDA2EX)
          /*
           * The Aux layer is used for OSAL AM335x/AM437x
           * Since the interrupt implementation for A15
           * is done in CSL lib which does not exist
           * for AM335x and AM437x, we keep the original
           * CSL implementation
           */
            Intc_IntUnregister(intrNum);
#else
          cpuIntrf->pIntrHandlers[intrNum] = cpuIntrf->pDefaultIntrHandlers;
          cpuIntrf->pUserParameter[intrNum] = cpuIntrf->pDefaultUserParameter;
#endif

#if defined(SOC_K2G) || defined(SOC_K2H) || defined(SOC_K2K) || defined(SOC_K2L) || defined(SOC_K2E)
         /* initialize the GIC, registers to enable group1 IRQs
          * this is in line with the GEL file
          * please update the priority registers if interrupts are required to be
          * set for Group 0 registers
          */
          gicDistInst->GICD_IGROUPR[intrNum/32U] = 0xFFFFFFFFU;
#endif
        }

        /*
           Register handlers for interrupt ID's 1020-1023. GIC will implement these
           interrupts irrespective of the number of interrupts supported in the device.
        */
        for(intrNum = 1020U; intrNum < 1024U; intrNum++)
        {
#if defined (SOC_AM572x) || defined (SOC_TDA2XX) || defined (SOC_DRA75X) || defined (SOC_AM571x) || defined (SOC_TDA2EX)
          /*
           * The Aux layer is used for OSAL AM335x/AM437x
           * Since the interrupt implementation for A15
           * is done in CSL lib which does not exist
           * for AM335x and AM437x, we keep the original
           * CSL implementation
           */
          Intc_IntUnregister(intrNum);

#else
          cpuIntrf->pIntrHandlers[intrNum] = cpuIntrf->pDefaultIntrHandlers;
          cpuIntrf->pUserParameter[intrNum] = cpuIntrf->pDefaultUserParameter;
#endif
        }

        /*  Initialize distributor sub-module */

        /*  Disable distributor sub-module */
        gicDistInst->GICD_CTLR = 0x0U;

        /*  Initialize all SPI interrupts */

        /*  Configure priority on all SPI interrupts to the lowest priority */
        size = sizeof(gicDistInst->GICD_IPRIORITYR) >> 2U;
        for (intrNum = 32U; intrNum < cpuIntrf->gicDist->maxValidIntr; intrNum += 1U)
        {
           /* limitting to the arrary size of 128 to handle upto 512
            * interrupt lines */
            if ((intrNum) < size)
            {
                gicDistInst->GICD_IPRIORITYR[intrNum] = (Uint32)CSL_ARM_GIC_CPU_INTF_MIN_PRI_ALL;
            }
            else
            {
                /* Break from the loop */
                break;
            }
        }

        /*  Disable all SPI interrupts */
        for (intrNum = 32U; intrNum < cpuIntrf->gicDist->maxValidIntr; intrNum += 32U)
        {
            if((intrNum / 32U) < 16U)
            {
                gicDistInst->GICD_ICENABLER[intrNum / 32U] = CSL_ARM_GICD_DISABLE_INTR;
            }
        }

        /*  Enable distributor sub-module */
#if defined(SOC_K2G) || defined(SOC_K2H) || defined(SOC_K2K) || defined(SOC_K2L) || defined(SOC_K2E)
        /* Enable Group1 and Group0 Interrupts */
        gicDistInst->GICD_CTLR = 0x3U;
#else
        gicDistInst->GICD_CTLR = 0x1U;
#endif
        /* Search for any previously active interrupts and acknowledge them */
        for (i = 0U; i < 6U; i++)
        {
            intActiveReg = gicDistInst->GICD_ISACTIVER[i];

            if (intActiveReg)
            {
                for (j = 0U; j < 32U; j++)
                {
                    if (intActiveReg & 0x1U)
                    {
                        gicCpuInst->GICC_EOIR = (i * 32U + j);
                    }
                    intActiveReg = intActiveReg >> 1;
                }
            }
        }

        /* GICv2 SGIC Clear Pending Register */
        for(i = 0; i < 4U; i++)
        {
            gicDistInst->GICD_CPENDSGIR[i] = 0x01010101U;
        }

        /* Clear all interrupt active status registers. */
        for(i = 0; i < 6U; i++)
        {
             gicDistInst->GICD_ICPENDR[i] = 0xFFFFFFFFU;
        }

        /* Clear active register */
         for(i = 0; i < 6U; i++)
        {
             gicDistInst->GICD_ICACTIVER[i] = 0xFFFFFFFFU;
        }

        /* Target processor register */
        size = sizeof(gicDistInst->GICD_ITARGETSR) >> 2U;
        for(intrNum = 8U; intrNum < cpuIntrf->gicDist->maxValidIntr; intrNum++)
        {
            /* limitting to the arrary size of 128 to handle upto 512
             * interrupt lines */
            if (intrNum < size)
            {
                gicDistInst->GICD_ITARGETSR[intrNum] = 0x01010101U;
            }
            else
            {
                /* Break from the loop */
                break;
            }
        }

        cpuIntrf->gicDist->initStatus = (Uint32)TRUE;
    }

    /*  Initialize CPU Interface sub-module */
    if(FALSE == cpuIntrf->initStatus)
    {
        /* Configure the priority of PPI and SGI interrupts (for primary GIC only) */
        /* Disable both SGI and PPI interrupts. Ability to disable SGI interrupts
           is implementation defined. But if it is RAZ/WI, still the below code
           will hold good. This will simplify the software implementation. */
        gicDistInst->GICD_ICENABLER[0] = CSL_ARM_GICD_DISABLE_INTR;
        for (intrNum = 0U; intrNum < 32U; intrNum += 4U)
        {
            gicDistInst->GICD_IPRIORITYR[intrNum/4U] = CSL_ARM_GICD_DISABLE_INTR;
        }

        /*
            Configure the priority mask to lowest value, so that all the priorities
            can be used. Based on the application need this can be modified apprioriately.
        */
        gicCpuInst->GICC_PMR = (Uint32)CSL_ARM_GIC_CPU_INTF_MIN_PRI_ALL;

        /* Non-Secure BPR */
        gicCpuInst->GICC_BPR = cpuIntrf->gicDist->nonSecureBinaryPoint;

#if defined(SOC_K2G) || defined(SOC_K2H) || defined(SOC_K2K) || defined(SOC_K2L) || defined(SOC_K2E)
       /* Enable NS interrupts for KeyStone2 SoCs
        * 1011b = 0xB
        * Enable signaling of Group 0 interrupts
        * Enable signaling of Group 1 interrupts
        */
        ctrlConfigval = 0x3U;
#else
        /* Enable NS interrupts in Non-secure mode */
        ctrlConfigval = 0x1U;
#endif
        /* Enable CPU interface to signal the interrupt */
        gicCpuInst->GICC_CTLR = ctrlConfigval;

        cpuIntrf->initStatus = (Uint32)TRUE;
    }
}

/** ============================================================================
 *   @n@b CSL_armGicConfigIntr
 *
 *   @b Description
 *   @n This function is used to disable the MMU.
 *
 *   @b Arguments
 *   @n  None
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Example
 *   @verbatim

        CSL_armGicConfigIntr(); // Disable the MMU

     @endverbatim
 * =============================================================================
 */
/* prototype defintions for misrac warning fix */
static inline void CSL_armGicConfigIntr(CSL_ArmGicCpuIntrf *cpuIntrf, Uint32 intrNum,
                                        const CSL_ArmGicIntrParams_t *pIntrParams);
static inline void CSL_armGicConfigIntr
(
    CSL_ArmGicCpuIntrf *cpuIntrf,
    Uint32 intrNum,
    const CSL_ArmGicIntrParams_t *pIntrParams
)
{
    CSL_ArmgicDistributorRegs *gicDistInst = NULL;
    Uint32 trigType = 0;
#if defined(SOC_K2G) || defined(SOC_K2H) || defined(SOC_K2K) || defined(SOC_K2L) || defined(SOC_K2E)
    /* All interrupts are grouped into group 1 */
#else
    Uint32 intrSecConf;
#endif

    gicDistInst = (CSL_ArmgicDistributorRegs *)(cpuIntrf->gicDist->distBasePtr);

    /* Validate the parameters. SGI can't be configured */
    if ((intrNum <= CSL_ARM_GIC_MAX_INTR_NO) ||
              (pIntrParams->priority <= CSL_ARM_GIC_CPU_INTF_MIN_PRI) ||
              (pIntrParams->pFnIntrHandler != NULL) ||
              /* Priority value is not given in the levels supported */
              (pIntrParams->priority % cpuIntrf->gicDist->noPriorityStep == 0))
    {
        /* Disable the interrupt before configuring. Disabling SGI interrupts is
           implementation defined. But if it is RAZ/WI, still the below code will
           hold good. This simplifies the software implementation.
        */
        gicDistInst->GICD_ICENABLER[intrNum/32U] = CSL_ARM_GICD_SET_CLR_MASK(intrNum);

#if defined(SOC_K2G) || defined(SOC_K2H) || defined(SOC_K2K) || defined(SOC_K2L) || defined(SOC_K2E)

        /* initialize the GIC, registers to enable group1 IRQs
         * please update the priority registers if interrupts are required to be
         * set for Group 0 registers
         *
         */
        gicDistInst->GICD_IGROUPR[intrNum/32U] = 0xFFFFFFFFU;
#else
        /* Configure the interrupt as secure or non-secure */
        intrSecConf = gicDistInst->GICD_IGROUPR[intrNum/32U];

        intrSecConf |= CSL_ARM_GICD_SET_CLR_MASK(intrNum);

        gicDistInst->GICD_IGROUPR[intrNum/32U] = intrSecConf;
#endif

        /* Configure trigger type. SGI interrupts are read-only, PPI interrupts
           configurability is implementation defined.
        */
        /* Accept active-high, level-sensitive interrupts */
        if (((intrNum >= 16U) && (intrNum < 32U) && (CSL_ARM_GIC_PPI_TRIG_WRITABLE != 0)) ||
                                        ((intrNum >= 32U) && (intrNum < 1024U)))
        {
            if((intrNum / 16U) < (Uint32)32U)
            {
                trigType = gicDistInst->GICD_ICFGR[intrNum/16U];
                trigType &= ~CSL_ARM_GICD_INT_CONF_MASK(intrNum);
                trigType |= (pIntrParams->triggerType) <<
                                                 CSL_ARM_GICD_INT_CONF_SHIFT(intrNum);

                gicDistInst->GICD_ICFGR[intrNum/16U] = trigType;
            }
        }

        /* Set interrupt priority */
        gicDistInst->GICD_IPRIORITYR[intrNum] = (pIntrParams->priority);

        /* Register interrupt handler */
#if defined (SOC_AM572x) || defined (SOC_TDA2XX) || defined (SOC_DRA75X) || defined (SOC_AM571x) || defined (SOC_TDA2EX)
        /*
         * The Aux layer is used for OSAL AM335x/AM437x
         * Since the interrupt implementation for A15
         * is done in CSL lib which does not exist
         * for AM335x and AM437x, we keep the original
         * CSL implementation
         */
         Intc_IntRegister(intrNum, pIntrParams->pFnIntrHandler, pIntrParams->pUserParam);
#else
          cpuIntrf->pIntrHandlers[intrNum] = pIntrParams->pFnIntrHandler;
          cpuIntrf->pUserParameter[intrNum] = pIntrParams->pUserParam;
#endif

        /* Enable the interrupt (unmask). Disabling SGI interrupts is implementation
           defined. But if it is RAZ/WI, still the below code will hold good. This
           will simplify the software implementation.
        */
        gicDistInst->GICD_ISENABLER[intrNum/32U] = CSL_ARM_GICD_SET_CLR_MASK(intrNum);

        CSL_a15EnableIrq();
    }
}

/** ============================================================================
 *   @n@b CSL_armGicEnableIntr
 *
 *   @b Description
 *   @n This function is used to enable the MMU.
 *
 *   @b Arguments
      @verbatim
          tablePtr      Address of the page table
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Example
 *   @verbatim

        CSL_armGicEnableIntr(); // Enable the MMU

     @endverbatim
 * =============================================================================
 */
/* prototype defintions for misrac warning fix */
static inline void CSL_armGicEnableIntr(const CSL_ArmGicCpuIntrf *cpuIntrf, Uint32 intrNum);
static inline void CSL_armGicEnableIntr
(
    const CSL_ArmGicCpuIntrf *cpuIntrf,
    Uint32 intrNum
)
{
    CSL_ArmgicDistributorRegs *gicDistInst = NULL;

    gicDistInst = (CSL_ArmgicDistributorRegs *)cpuIntrf->gicDist->distBasePtr;

    /*  Disable the interrupt */
    gicDistInst->GICD_ISENABLER[intrNum/32U] = CSL_ARM_GICD_SET_CLR_MASK(intrNum);
}

/** ============================================================================
 *   @n@b CSL_armGicDisableIntr
 *
 *   @b Description
 *   @n This function is used to check if MMU is enabled.
 *
 *   @b Arguments
 *   @n  None
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Example
 *   @verbatim

        CSL_armGicDisableIntr(); // Enable the L1D cache

     @endverbatim
 * =============================================================================
 */
/* prototype defintions for misrac warning fix */
static inline void CSL_armGicDisableIntr(const CSL_ArmGicCpuIntrf *cpuIntrf, Uint32 intrNum);
static inline void CSL_armGicDisableIntr
(
    const CSL_ArmGicCpuIntrf *cpuIntrf,
    Uint32 intrNum
)
{
    CSL_ArmgicDistributorRegs *gicDistInst = NULL;

    gicDistInst = (CSL_ArmgicDistributorRegs *)cpuIntrf->gicDist->distBasePtr;

    /*  Disable the interrupt */
    gicDistInst->GICD_ICENABLER[intrNum/32U] = CSL_ARM_GICD_SET_CLR_MASK(intrNum);
}

/** ============================================================================
 *   @n@b CSL_armGicClearIntr
 *
 *   @b Description
 *   @n This function is used to check if MMU is enabled.
 *
 *   @b Arguments
 *   @n  None
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Example
 *   @verbatim

        CSL_armGicClearIntr(); // Enable the L1D cache

     @endverbatim
 * =============================================================================
 */
/* prototype defintions for misrac warning fix */
static inline void CSL_armGicClearIntr(const CSL_ArmGicCpuIntrf *cpuIntrf,Uint32 intrNum);

static inline void CSL_armGicClearIntr
(
    const CSL_ArmGicCpuIntrf *cpuIntrf,
    Uint32 intrNum
)
{
    CSL_ArmgicDistributorRegs *gicDistInst = NULL;

    gicDistInst = (CSL_ArmgicDistributorRegs *)cpuIntrf->gicDist->distBasePtr;

    /* Check if this interrupt is supported */
    gicDistInst->GICD_ICPENDR[intrNum/32U] = (((uint32_t)0x1U) << (intrNum % 32U));
}

/** ============================================================================
 *   @n@b CSL_armGicTriggerSWIntr
 *
 *   @b Description
 *   @n This function is used to check if MMU is enabled.
 *
 *   @b Arguments
 *   @n  None
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Example
 *   @verbatim

        CSL_armGicTriggerSWIntr(); // Enable the L1D cache

     @endverbatim
 * =============================================================================
 */
/* prototype defintions for misrac warning fix */
static inline void CSL_armGicTriggerSWIntr(const CSL_ArmGicCpuIntrf *cpuIntrf, Uint32 intrNum);

static inline void CSL_armGicTriggerSWIntr
(
    const CSL_ArmGicCpuIntrf *cpuIntrf,
    Uint32 intrNum
)
{
    CSL_ArmgicDistributorRegs *gicDistInst = NULL;

    gicDistInst = (CSL_ArmgicDistributorRegs *)cpuIntrf->gicDist->distBasePtr;

    /* Check if this interrupt is supported */
    gicDistInst->GICD_ISPENDR[intrNum/32U] = (((uint32_t)0x1U) << (intrNum % 32U));
}

/** ============================================================================
 *   @n@b CSL_armGicTriggerIpcIntr
 *
 *   @b Description
 *   @n This function is used to check if MMU is enabled.
 *
 *   @b Arguments
 *   @n  None
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Example
 *   @verbatim

        CSL_armGicTriggerIpcIntr(); // Enable the L1D cache

     @endverbatim
 * =============================================================================
 */
/* prototype defintions for misrac warning fix */
static inline void CSL_armGicTriggerIpcIntr(const CSL_ArmGicCpuIntrf *cpuIntrf, Uint32 intrNum);

static inline void CSL_armGicTriggerIpcIntr
(
    const CSL_ArmGicCpuIntrf *cpuIntrf,
    Uint32 intrNum
)
{
    Uint32 sgiVal = 0;
    CSL_ArmgicDistributorRegs *gicDistInst = NULL;

    /* Valid interrupt numbers are 0-15 */
    if (intrNum <= 15U)
    {
        gicDistInst = (CSL_ArmgicDistributorRegs *)cpuIntrf->gicDist->distBasePtr;

        sgiVal = (
            (CSL_ARM_GIC_SGI_TARGET_LIST << CSL_ARMGIC_GICD_SGIR_TARGETLISTFILTER_SHIFT) |
            (cpuIntrf->cpuId << CSL_ARMGIC_GICD_SGIR_CPUTARGETLIST_SHIFT) |
            (CSL_ARM_GIC_SGI_SATT_NON_SECURE << CSL_ARMGIC_GICD_SGIR_SATT_SHIFT) |
            (intrNum << CSL_ARMGIC_GICD_SGIR_SGIINTID_SHIFT)
                 );

        gicDistInst->GICD_SGIR = sgiVal;
    }
}

/** ============================================================================
 *   @n@b CSL_armGicCommonIntrHandler
 *
 *   @b Description
 *   @n This function is used to check if MMU is enabled.
 *
 *   @b Arguments
 *   @n  None
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Example
 *   @verbatim

        CSL_armGicCommonIntrHandler(); // Enable the L1D cache

     @endverbatim
 * =============================================================================
 */

/* prototype defintions for misrac warning fix */
extern        void CSL_armGicCallBackFxn(void *arg, void *fxn);
static inline void CSL_armGicCommonIntrHandler(CSL_ArmGicCpuIntrf *cpuIntrf);
static inline void CSL_armGicCommonIntrHandler(CSL_ArmGicCpuIntrf *cpuIntrf)
{
    CSL_ArmgicGiccRegs *gicCpuInst = NULL;

    gicCpuInst = (CSL_ArmgicGiccRegs *)(cpuIntrf->cpuIntfBasePtr);

#if defined(SOC_K2G) || defined(SOC_K2H) || defined(SOC_K2K) || defined(SOC_K2L) || defined(SOC_K2E)
    Uint32 intrAckVal   = gicCpuInst->GICC_AIAR;
    Uint32 activeIntrId = intrAckVal & CSL_ARMGIC_GICC_AIAR_AACKINTID_MASK;
#else
    /*
        Security considerations need to be taken care by the application. If
        the security state of the CPU not matches with the active interrupt
        type special interrupt numbers 1022/1023 will be returned. It is the
        responsibility of the application to handle these interrupts.
    */
    Uint32 intrAckVal = gicCpuInst->GICC_IAR;
    Uint32 activeIntrId = intrAckVal & CSL_ARMGIC_GICC_IAR_ACKINTID_MASK;
#endif
    /* Save the current threshold value in stack */
    Uint32 prevPriMask = gicCpuInst->GICC_PMR;

    /*
        Get the active IRQ priority and set this priority as the threshold value,
        so that only interrupts with higher priority can interrupt the CPU when
        the current interrupt us being serviced.
    */
    gicCpuInst->GICC_PMR = gicCpuInst->GICC_RPR;

    /* Call user ISR function in system mode and then return back to IRQ mode */
#if defined (SOC_AM572x) || defined (SOC_TDA2XX) || defined (SOC_DRA75X) || defined (SOC_AM571x) || defined (SOC_TDA2EX)
    CSL_armGicCallBackFxn(argArray[activeIntrId], fnRAMVectors[activeIntrId]);
#else
    CSL_armGicCallBackFxn(cpuIntrf->pUserParameter[activeIntrId], cpuIntrf->pIntrHandlers[activeIntrId]);
#endif

#if defined(SOC_K2G) || defined(SOC_K2H) || defined(SOC_K2K) || defined(SOC_K2L) || defined(SOC_K2E)
    /* End of Interrupt - inform the CPU interface that ISR is completed */
    gicCpuInst->GICC_AEOIR = intrAckVal;
#else
    /* End of Interrupt - inform the CPU interface that ISR is completed */
    gicCpuInst->GICC_EOIR = intrAckVal;
#endif
    /* Reload original priority mask value */
    gicCpuInst->GICC_PMR = prevPriMask;
}

/** ============================================================================
*   @n@b CSL_armGicGetGicIdForIrqInputLine 
*
*   @b Description
*   @n This API returns the ARM GIC ID for a given IRQ Input line.
*
*   @b Arguments
     @verbatim
        IRQ Input Line
     @endverbatim
*
*   <b> Return Value </b>
*   @n  Corresponding GIC Id
*
*   <b> Pre Condition </b>
*   @n  None
*
*   <b> Post Condition </b>
*   @n  None
*
*   @b Example
*   @verbatim

      uint32_t   gicId;
      uint32_t   irqInputLine = (uint32_t) 44U;
      gicId      = CSL_armGicGetGicIdForIrqInputLine (irqInputLine);

     @endverbatim
* =============================================================================
*/
static inline uint32_t CSL_armGicGetGicIdForIrqInputLine (uint32_t  irqInputLine)
{
    return (irqInputLine + (uint32_t) 32U);
}

/** ============================================================================
*   @n@b CSL_armGicGlobalDisableInterrupt
*
*   @b Description
*   @n This API disables the interrupt globally.
*
*   @b Arguments
     @verbatim
*       None
     @endverbatim
*
*   <b> Return Value </b>
*   @n  CPSR value before disable interrupt
*
*   <b> Pre Condition </b>
*   @n  None
*
*   <b> Post Condition </b>
*   @n  None
*
*   @b Example
*   @verbatim

      uint32_t   key;
      key     = CSL_armGicGlobalDisableInterrupt();

     @endverbatim
* =============================================================================
*/
static inline uint32_t  CSL_armGicGlobalDisableInterrupt(void)
{
    uint32_t status;

    asm (
      "dsb    \n\t"
      "     mrs r0, cpsr_cf\n\t"
      "     cpsid i\n\t"
      "     mov %0, r0"
      :"=r" (status));
    return (status);
}

/** ============================================================================
*   @n@b CSL_armGicGlobalRestoreInterrupt
*
*   @b Description
*   @n This API restores the interrupt globally.
*
*   @b Arguments
     @verbatim
*       None
     @endverbatim
*
*   <b> Return Value </b>
*   @n  CPSR value to be restored
*
*   <b> Pre Condition </b>
*   @n  Call the CSL_armGicGlobalDisableInterrupt() to get the key
*
*   <b> Post Condition </b>
*   @n  None
*
*   @b Example
*   @verbatim

      uint32_t   key;
      key     = CSL_armGicGlobalDisableInterrupt();
      ...
      ...
      ...
      CSL_armGicGlobalRestoreInterrupt(key);

     @endverbatim
* =============================================================================
*/
static inline void CSL_armGicGlobalRestoreInterrupt (uint32_t restoreValue)
{
    asm(
      "dsb    \n\t"
      "and r1, r0, #128\n\t"
      "mrs r0, cpsr_cf\n\t"
      "bic r0, r0, #128\n\t"
      "orr r1, r1, r0\n\t"
      "msr cpsr_cf, r1\n\t"
      :::"r1","r0"
    );
}

/**
@}
*/

#ifdef __cplusplus
}
#endif

#endif /* CSL_ARM_GICD_V0AUX_V0_H_*/
