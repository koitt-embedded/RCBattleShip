/*  ============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2002, 2003, 2004, 2005, 2008
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

#include <ti/csl/tistdtypes.h>
#include <ti/csl/cslr_device.h>
#include <ti/csl/soc/am572x/src/cslr_soc.h>

void CSL_pllcMpuUnlock(void)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON;

    CSL_FINS(ckgenCmCoreAonReg->CM_IDLEST_DPLL_MPU_REG,
        CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_CLK,
        CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_CLK_DPLL_UNLOCKED);
}

void CSL_pllcMpuLock(void)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON;

    CSL_FINS(ckgenCmCoreAonReg->CM_IDLEST_DPLL_MPU_REG,
        CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_CLK,
        CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_CLK_DPLL_LOCKED);
}

void CSL_pllcMpuConfigure(const CSL_PllcMpuParam *mpuPllcParam)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON;

    CSL_FINS(ckgenCmCoreAonReg->CM_CLKSEL_DPLL_MPU_REG,
        CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_MPU_REG_DPLL_DIV, mpuPllcParam->div);
    CSL_FINS(ckgenCmCoreAonReg->CM_CLKSEL_DPLL_MPU_REG,
        CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_MPU_REG_DPLL_MULT, mpuPllcParam->mult);
    CSL_FINS(ckgenCmCoreAonReg->CM_CLKSEL_DPLL_MPU_REG,
        CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_MPU_REG_DCC_EN,
        CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_MPU_REG_DCC_EN_ENABLED);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_M2_DPLL_MPU_REG,
        CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_MPU_REG_DIVHS, mpuPllcParam->divM2);
}

void CSL_pllcIvaUnlock(void)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON;

    CSL_FINS(ckgenCmCoreAonReg->CM_IDLEST_DPLL_IVA_REG,
        CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_CLK,
        CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_CLK_DPLL_UNLOCKED);
}

void CSL_pllcIvaLock(void)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON;

    CSL_FINS(ckgenCmCoreAonReg->CM_IDLEST_DPLL_IVA_REG,
        CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_CLK,
        CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_CLK_DPLL_LOCKED);
}

void CSL_pllcIvaConfigure(const CSL_PllcIvaParam *ivaPllcParam)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON;

    CSL_FINS(ckgenCmCoreAonReg->CM_CLKSEL_DPLL_IVA_REG,
        CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_IVA_REG_DPLL_DIV, ivaPllcParam->div);
    CSL_FINS(ckgenCmCoreAonReg->CM_CLKSEL_DPLL_IVA_REG,
        CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_IVA_REG_DPLL_MULT, ivaPllcParam->mult);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_M2_DPLL_IVA_REG,
        CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_IVA_REG_DIVHS, ivaPllcParam->divM2);
}

void CSL_pllcCoreUnlock(void)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON;

    CSL_FINS(ckgenCmCoreAonReg->CM_IDLEST_DPLL_CORE_REG,
        CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_CLK,
        CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_CLK_DPLL_UNLOCKED);
}

void CSL_pllcCoreLock(void)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON;

    CSL_FINS(ckgenCmCoreAonReg->CM_IDLEST_DPLL_CORE_REG,
        CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_CLK,
        CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_CLK_DPLL_LOCKED);
}

void CSL_pllcCoreConfigure(const CSL_PllcCoreParam *corePllcParam)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON;

    CSL_FINS(ckgenCmCoreAonReg->CM_CLKSEL_DPLL_CORE_REG,
        CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DPLL_DIV, corePllcParam->div);
    CSL_FINS(ckgenCmCoreAonReg->CM_CLKSEL_DPLL_CORE_REG,
        CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DPLL_MULT, corePllcParam->mult);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_M2_DPLL_CORE_REG,
        CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_CORE_REG_DIVHS, corePllcParam->divM2);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_M3_DPLL_CORE_REG,
        CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_CORE_REG_DIVHS, corePllcParam->divM3);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_H12_DPLL_CORE_REG,
        CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_CORE_REG_DIVHS, corePllcParam->divH12);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_H13_DPLL_CORE_REG,
        CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_CORE_REG_DIVHS, corePllcParam->divH13);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_H14_DPLL_CORE_REG,
        CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_CORE_REG_DIVHS, corePllcParam->divH14);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_H22_DPLL_CORE_REG,
        CKGEN_CM_CORE_AON_CM_DIV_H22_DPLL_CORE_REG_DIVHS, corePllcParam->divH22);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_H23_DPLL_CORE_REG,
        CKGEN_CM_CORE_AON_CM_DIV_H23_DPLL_CORE_REG_DIVHS, corePllcParam->divH23);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_H24_DPLL_CORE_REG,
        CKGEN_CM_CORE_AON_CM_DIV_H24_DPLL_CORE_REG_DIVHS, corePllcParam->divH24);
}

void CSL_pllcAbeUnlock(void)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON;

    CSL_FINS(ckgenCmCoreAonReg->CM_IDLEST_DPLL_ABE_REG,
        CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_CLK,
        CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_CLK_DPLL_UNLOCKED);
}

void CSL_pllcAbeLock(void)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON;

    CSL_FINS(ckgenCmCoreAonReg->CM_IDLEST_DPLL_ABE_REG,
        CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_CLK,
        CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_CLK_DPLL_LOCKED);
}

void CSL_pllcAbeConfigure(const CSL_PllcAbeParam *abePllcParam)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON;

    CSL_FINS(ckgenCmCoreAonReg->CM_CLKSEL_DPLL_ABE_REG,
        CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_ABE_REG_DPLL_DIV, abePllcParam->div);
    CSL_FINS(ckgenCmCoreAonReg->CM_CLKSEL_DPLL_ABE_REG,
        CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_ABE_REG_DPLL_MULT, abePllcParam->mult);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_M2_DPLL_ABE_REG,
        CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_ABE_REG_DIVHS, abePllcParam->divM2);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_M3_DPLL_ABE_REG,
        CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_ABE_REG_DIVHS, abePllcParam->divM3);
}

void CSL_pllcDdrUnlock(void)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON;

    CSL_FINS(ckgenCmCoreAonReg->CM_IDLEST_DPLL_DDR_REG,
        CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_CLK,
        CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_CLK_DPLL_UNLOCKED);
}

void CSL_pllcDdrLock(void)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON;

    CSL_FINS(ckgenCmCoreAonReg->CM_IDLEST_DPLL_DDR_REG,
        CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_CLK,
        CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_CLK_DPLL_LOCKED);
}

void CSL_pllcDdrConfigure(const CSL_PllcDdrParam *ddrPllcParam)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON;

    CSL_FINS(ckgenCmCoreAonReg->CM_CLKSEL_DPLL_DDR_REG,
        CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DDR_REG_DPLL_DIV, ddrPllcParam->div);
    CSL_FINS(ckgenCmCoreAonReg->CM_CLKSEL_DPLL_DDR_REG,
        CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DDR_REG_DPLL_MULT, ddrPllcParam->mult);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_M2_DPLL_DDR_REG,
        CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DDR_REG_DIVHS, ddrPllcParam->divM2);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_M3_DPLL_DDR_REG,
        CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DDR_REG_DIVHS, ddrPllcParam->divM3);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_H11_DPLL_DDR_REG,
        CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_DDR_REG_DIVHS, ddrPllcParam->divH11);
}

void CSL_pllcDspUnlock(void)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON;

    CSL_FINS(ckgenCmCoreAonReg->CM_IDLEST_DPLL_DSP_REG,
        CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_CLK,
        CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_CLK_DPLL_UNLOCKED);
}

void CSL_pllcDspLock(void)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON;

    CSL_FINS(ckgenCmCoreAonReg->CM_IDLEST_DPLL_DSP_REG,
        CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_CLK,
        CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_CLK_DPLL_LOCKED);
}

void CSL_pllcDspConfigure(const CSL_PllcDspParam *dspPllcParam)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON;

    CSL_FINS(ckgenCmCoreAonReg->CM_CLKSEL_DPLL_DSP_REG,
        CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DSP_REG_DPLL_DIV, dspPllcParam->div);
    CSL_FINS(ckgenCmCoreAonReg->CM_CLKSEL_DPLL_DSP_REG,
        CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DSP_REG_DPLL_MULT, dspPllcParam->mult);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_M2_DPLL_DSP_REG,
        CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DSP_REG_DIVHS, dspPllcParam->divM2);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_M3_DPLL_DSP_REG,
        CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DSP_REG_DIVHS, dspPllcParam->divM3);
}

void CSL_pllcGmacUnlock(void)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON;

    CSL_FINS(ckgenCmCoreAonReg->CM_IDLEST_DPLL_GMAC_REG,
        CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_CLK,
        CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_CLK_DPLL_UNLOCKED);
}

void CSL_pllcGmacLock(void)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON;

    CSL_FINS(ckgenCmCoreAonReg->CM_IDLEST_DPLL_GMAC_REG,
        CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_CLK,
        CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_CLK_DPLL_LOCKED);
}

void CSL_pllcGmacConfigure(const CSL_PllcGmacParam *gmacPllcParam)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON;

    CSL_FINS(ckgenCmCoreAonReg->CM_CLKSEL_DPLL_GMAC_REG,
        CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DPLL_DIV, gmacPllcParam->div);
    CSL_FINS(ckgenCmCoreAonReg->CM_CLKSEL_DPLL_GMAC_REG,
        CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DPLL_MULT, gmacPllcParam->mult);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_M2_DPLL_GMAC_REG,
        CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GMAC_REG_DIVHS, gmacPllcParam->divM2);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_M3_DPLL_GMAC_REG,
        CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GMAC_REG_DIVHS, gmacPllcParam->divM3);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_H11_DPLL_GMAC_REG,
        CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_GMAC_REG_DIVHS, gmacPllcParam->divH11);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_H12_DPLL_GMAC_REG,
        CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_GMAC_REG_DIVHS, gmacPllcParam->divH12);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_H13_DPLL_GMAC_REG,
        CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_GMAC_REG_DIVHS, gmacPllcParam->divH13);
}

void CSL_pllcGpuUnlock(void)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON;

    CSL_FINS(ckgenCmCoreAonReg->CM_IDLEST_DPLL_GPU_REG,
        CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_CLK,
        CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_CLK_DPLL_UNLOCKED);
}

void CSL_pllcGpuLock(void)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON;

    CSL_FINS(ckgenCmCoreAonReg->CM_IDLEST_DPLL_GPU_REG,
        CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_CLK,
        CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_CLK_DPLL_LOCKED);
}

void CSL_pllcGpuConfigure(const CSL_PllcGpuParam *gpuPllcParam)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON;

    CSL_FINS(ckgenCmCoreAonReg->CM_CLKSEL_DPLL_GPU_REG,
        CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DPLL_DIV, gpuPllcParam->div);
    CSL_FINS(ckgenCmCoreAonReg->CM_CLKSEL_DPLL_GPU_REG,
        CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DPLL_MULT, gpuPllcParam->mult);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_M2_DPLL_GPU_REG,
        CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GPU_REG_DIVHS, gpuPllcParam->divM2);
}

void CSL_pllcPcieUnlock(void)
{
    CSL_ckgen_cm_coreRegs *ckgenCmCoreReg =
        (CSL_ckgen_cm_coreRegs *) CSL_MPU_CKGEN_CM_CORE;

    CSL_FINS(ckgenCmCoreReg->CM_IDLEST_DPLL_PCIE_REF_REG,
        CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_CLK,
        CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_CLK_DPLL_UNLOCKED);
}

void CSL_pllcPcieLock(void)
{
    CSL_ckgen_cm_coreRegs *ckgenCmCoreReg =
        (CSL_ckgen_cm_coreRegs *) CSL_MPU_CKGEN_CM_CORE;

    CSL_FINS(ckgenCmCoreReg->CM_IDLEST_DPLL_PCIE_REF_REG,
        CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_CLK,
        CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_CLK_DPLL_LOCKED);
}

void CSL_pllcPcieConfigure(const CSL_PllcPcieParam *pciePllcParam)
{
    CSL_ckgen_cm_coreRegs *ckgenCmCoreReg =
        (CSL_ckgen_cm_coreRegs *) CSL_MPU_CKGEN_CM_CORE;

    CSL_FINS(ckgenCmCoreReg->CM_CLKSEL_DPLL_PCIE_REF_REG,
        CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DPLL_DIV, pciePllcParam->div);
    CSL_FINS(ckgenCmCoreReg->CM_CLKSEL_DPLL_PCIE_REF_REG,
        CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DPLL_MULT, pciePllcParam->mult);
    CSL_FINS(ckgenCmCoreReg->CM_DIV_M2_DPLL_PCIE_REF_REG,
        CKGEN_CM_CORE_CM_DIV_M2_DPLL_PCIE_REF_REG_DIVHS, pciePllcParam->divM2);
}

void CSL_pllcPerUnlock(void)
{
    CSL_ckgen_cm_coreRegs *ckgenCmCoreReg =
        (CSL_ckgen_cm_coreRegs *) CSL_MPU_CKGEN_CM_CORE;

    CSL_FINS(ckgenCmCoreReg->CM_IDLEST_DPLL_PER_REG,
        CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_CLK,
        CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_CLK_DPLL_UNLOCKED);
}

void CSL_pllcPerLock(void)
{
    CSL_ckgen_cm_coreRegs *ckgenCmCoreReg =
        (CSL_ckgen_cm_coreRegs *) CSL_MPU_CKGEN_CM_CORE;

    CSL_FINS(ckgenCmCoreReg->CM_IDLEST_DPLL_PER_REG,
        CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_CLK,
        CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_CLK_DPLL_LOCKED);
}

void CSL_pllcPerConfigure(const CSL_PllcPerParam *perPllcParam)
{
    CSL_ckgen_cm_coreRegs *ckgenCmCoreReg =
        (CSL_ckgen_cm_coreRegs *) CSL_MPU_CKGEN_CM_CORE;

    CSL_FINS(ckgenCmCoreReg->CM_CLKSEL_DPLL_PER_REG,
        CKGEN_CM_CORE_CM_CLKSEL_DPLL_PER_REG_DPLL_DIV, perPllcParam->div);
    CSL_FINS(ckgenCmCoreReg->CM_CLKSEL_DPLL_PER_REG,
        CKGEN_CM_CORE_CM_CLKSEL_DPLL_PER_REG_DPLL_MULT, perPllcParam->mult);
    CSL_FINS(ckgenCmCoreReg->CM_DIV_M2_DPLL_PER_REG,
        CKGEN_CM_CORE_CM_DIV_M2_DPLL_PER_REG_DIVHS, perPllcParam->divM2);
}
