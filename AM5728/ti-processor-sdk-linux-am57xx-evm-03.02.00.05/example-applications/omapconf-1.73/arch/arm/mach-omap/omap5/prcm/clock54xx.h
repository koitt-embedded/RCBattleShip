/*
 *
 * @Component			OMAPCONF
 * @Filename			clock54xx.h
 * @Description			OMAP5 PRCM Clocks Definitions & Functions
 * @Author			Patrick Titiano (p-titiano@ti.com)
 * @Date			2011
 * @Copyright			Texas Instruments Incorporated
 *
 *
 * Copyright (C) 2011 Texas Instruments Incorporated - http://www.ti.com/
 *
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


#ifndef __PRCM_CLOCK54XX_H__
#define __PRCM_CLOCK54XX_H__

#define CLK54XX_MAX_NAME_LENGTH		32

typedef enum {
	/* 32K CLKS */
	CLK54XX_SYS_32K,
	CLK54XX_FUNC_32K_CLK,
	CLK54XX_SECURE_32K_CLK,
	CLK54XX_HDMI_CEC_GFCLK,
	CLK54XX_WKUPAON_32K_GFCLK,
	CLK54XX_COREAON_32K_GFCLK,
	CLK54XX_PER_32K_GFCLK,
	CLK54XX_ABE_32K_CLK,
	CLK54XX_MMC1_32K_GFCLK, /* ES2.0 only */
	/* SYS CLKS */
	CLK54XX_SYS_CLKIN,
	CLK54XX_SYS_CLK,
	CLK54XX_CUSTEFUSE_SYS_GFCLK,
	CLK54XX_EMU_SYS_CLK,
	CLK54XX_CORE_DPLL_CLK,
	CLK54XX_PER_DPLL_CLK,
	CLK54XX_IVA_DPLL_CLK,
	CLK54XX_MPU_DPLL_CLK,
	CLK54XX_UNIPRO2_DPLL_CLK,
	CLK54XX_USB_DPLL_CLK,
	CLK54XX_USB_OTG_SS_REF_CLK,
	CLK54XX_UNIPRO1_DPLL_CLK,
	CLK54XX_WKUPAON_IO_SRCOMP_GFCLK,
	CLK54XX_COREAON_IO_SRCOMP_GFCLK,
	CLK54XX_UNIPRO2_PHY_REF_GFCLK,
	CLK54XX_MIPIEXT_PHY_REF_GFCLK,
	CLK54XX_SATA_REF_GFCLK,
	CLK54XX_DSS_SYS_CLK,
	CLK54XX_ABE_SYS_CLK,
	/* DPLL BYPASS INPUT CLKS */
	CLK54XX_ABE_DPLL_CLK,
	CLK54XX_ABE_DPLL_BYPASS_CLK,
	CLK54XX_MPU_DPLL_HS_CLK,
	CLK54XX_IVA_DPLL_HS_CLK,
	CLK54XX_PER_DPLL_HS_CLK,
	CLK54XX_USB_DPLL_HS_CLK,
	/* DPLL ABE OUTPUT CLKS */
	CLK54XX_PER_ABE_X1_GFCLK, /* ES1.0 only */
	CLK54XX_DPLL_ABE_X2_FCLK,
	CLK54XX_CORE_DPLL_HS_CLK,
	/* DPLL CORE OUTPUTS */
	CLK54XX_EMIF_PHY_GCLK,
	CLK54XX_CORE_DPLL_SCRM_CLK,
	CLK54XX_CORE_DLL_GCLK,
	CLK54XX_CORE_X2_CLK,
	CLK54XX_CORE_USB_OTG_SS_LFPS_TX_CLK,
	CLK54XX_CORE_GPU_CLK,
	CLK54XX_CORE_C2C_CLK, /* ES2.0 only */
	CLK54XX_CORE_IPU_ISS_BOOST_CLK,
	CLK54XX_CORE_ISS_MAIN_CLK,
	CLK54XX_BB2D_GFCLK, /* ES2.0 only */
	/* DPLL PER OUTPUTS */
	CLK54XX_FUNC_96M_AON_CLK,
	CLK54XX_FUNC_192M_FCLK,
	CLK54XX_PER_DPLL_SCRM_CLK,
	CLK54XX_FUNC_128M_CLK, /* ES1.0 only */
	CLK54XX_FUNC_256M_CLK, /* ES2.0 only */
	CLK54XX_DSS_GFCLK,
	CLK54XX_PER_GPU_CLK,
	/* DPLL MPU OUTPUTS */
	CLK54XX_MPU_GCLK,
	/* DPLL IVA OUTPUTS */
	CLK54XX_DSP_GCLK,
	CLK54XX_IVA_GCLK,
	/* DPLL USB OUTPUTS */
	CLK54XX_L3INIT_480M_GFCLK,
	CLK54XX_L3INIT_960M_FCLK,
	/* DPLL UNIPRO1 OUTPUTS */
	CLK54XX_UNIPRO1_TXPHY_LS_GFCLK,
	CLK54XX_UNIPRO1_PHY_GFCLK,
	/* DPLL UNIPRO2 OUTPUTS */
	CLK54XX_UNIPRO2_TXPHY_LS_GFCLK,
	CLK54XX_UNIPRO2_PHY_GFCLK,
	/* COREAON CLKDM Clocks */
	CLK54XX_FUNC_24M_CLK,
	CLK54XX_FUNC_24M_GFCLK,
	CLK54XX_CORE_CLK,
	CLK54XX_L3_ICLK,
	CLK54XX_EMIF_L3_GICLK,
	CLK54XX_L4SEC_L3_GICLK,
	CLK54XX_CAM_L3_GICLK,
	CLK54XX_C2C_L3_GICLK, /* ES1.0 only */
	CLK54XX_DMA_L3_GICLK,
	CLK54XX_L3INSTR_L3_GICLK,
	CLK54XX_L3MAIN1_L3_GICLK,
	CLK54XX_L3MAIN2_L3_GICLK,
	CLK54XX_MIPIEXT_L3_GICLK,
	CLK54XX_DSS_L3_GICLK,
	CLK54XX_L3INIT_L3_GICLK,
	CLK54XX_CM_CORE_AON_PROFILING_L3_GICLK,
	CLK54XX_L4_ROOT_CLK,
	CLK54XX_L4_ICLK,
	CLK54XX_L4PER_L4_GICLK,
	CLK54XX_L4SEC_L4_GICLK,
	CLK54XX_C2C_L4_GICLK,
	CLK54XX_L4CFG_L4_GICLK,
	CLK54XX_MIPIEXT_L4_GICLK,
	CLK54XX_L3INIT_L4_GICLK,
	CLK54XX_CM_CORE_AON_PROFILING_L4_GICLK,
	/* PRM CLKDM Clocks */
	CLK54XX_ABE_LP_CLK,
	CLK54XX_WKUPAON_ICLK,
	CLK54XX_SR_MM_SYS_GFCLK,
	CLK54XX_SR_MPU_SYS_GFCLK,
	CLK54XX_SR_CORE_SYS_GFCLK,
	CLK54XX_WKUPAON_GCLK,
	CLK54XX_WKUPAON_GICLK,
	CLK54XX_CM_CORE_AON_SYS_CLK,
	CLK54XX_WKUPAON_PROFILING_GCLK,
	CLK54XX_CORE_TS_GFCLK, /* ES1.0 only */
	CLK54XX_COREAON_TS_GFCLK, /* ES1.0 only */
	CLK54XX_L3INSTR_DLL_AGING_GCLK,
	CLK54XX_L3INSTR_TS_GFCLK,
	/* PRM TIMER Clocks */
	CLK54XX_TIMER1_GFCLK,
	CLK54XX_TIMER2_GFCLK,
	CLK54XX_TIMER3_GFCLK,
	CLK54XX_TIMER4_GFCLK,
	CLK54XX_TIMER9_GFCLK,
	CLK54XX_TIMER10_GFCLK,
	CLK54XX_TIMER11_GFCLK,
	/* CKGEN_USB Clocks */
	CLK54XX_UTMI_P3_GFCLK,
	CLK54XX_HSIC_P3_GFCLK,
	CLK54XX_HSIC_P2_GFCLK,
	CLK54XX_HSIC_P1_GFCLK,
	CLK54XX_L3INIT_60M_P1_GFCLK,
	CLK54XX_L3INIT_60M_P2_GFCLK,
	CLK54XX_UTMI_ROOT_GFCLK,
	CLK54XX_TLL_CH0_GFCLK,
	CLK54XX_TLL_CH1_GFCLK,
	CLK54XX_TLL_CH2_GFCLK,
	CLK54XX_L3INIT_60M_FCLK,
	CLK54XX_HSIC_P1_480M_GFCLK,
	CLK54XX_HSIC_P2_480M_GFCLK,
	CLK54XX_HSIC_P3_480M_GFCLK,
	CLK54XX_XCLK_60M_HSP2,
	CLK54XX_XCLK_60M_HSP1,
	CLK54XX_UTMI_P1_GFCLK,
	CLK54XX_UTMI_P2_GFCLK,
	/* CKGEN_ABE Clocks */
	CLK54XX_PAD_UCLKS,
	CLK54XX_SLIMBUS_UCLKS,
	CLK54XX_ABE_CLK,
	CLK54XX_AESS_FCLK,
	CLK54XX_ABE_GICLK,
	CLK54XX_ABE_24M_FCLK,
	CLK54XX_PAD_GCLKS,
	CLK54XX_SLIMBUS_CLK,
	CLK54XX_MCBSP1_INT_GFCLK,
	CLK54XX_MCBSP2_INT_GFCLK,
	CLK54XX_MCBSP3_INT_GFCLK,
	CLK54XX_MCASP1_INT_GFCLK,
	CLK54XX_DMIC_INT_GFCLK,
	CLK54XX_MCBSP1_GFCLK,
	CLK54XX_MCBSP2_GFCLK,
	CLK54XX_MCBSP3_GFCLK,
	CLK54XX_MCASP1_GFCLK,
	CLK54XX_DMIC_GFCLK,
	CLK54XX_TIMER5_GFCLK,
	CLK54XX_TIMER6_GFCLK,
	CLK54XX_TIMER7_GFCLK,
	CLK54XX_TIMER8_GFCLK,
	/* CM_CORE Clocks */
	CLK54XX_GPU_HYD_GCLK,
	CLK54XX_GPU_CORE_GCLK,
	CLK54XX_FDIF_GFCLK,
	CLK54XX_PER_ABE_24M_FCLK, /* ES1.0 only */
	CLK54XX_FUNC_96M_FCLK,
	CLK54XX_FUNC_48M_FCLK,
	CLK54XX_FUNC_24M_FCLK,
	CLK54XX_HSI_FCLK,
	CLK54XX_FUNC_12M_FCLK,
	CLK54XX_MMC1_GFCLK,
	CLK54XX_MMC2_GFCLK,
	CLK54XX_PER_ABE_24M_GFCLK,
	CLK54XX_PER_96M_GFCLK,
	CLK54XX_PER_48M_GFCLK,
	CLK54XX_PER_24M_GFCLK, /* ES1.0 only */
	CLK54XX_HSI_GFCLK,
	CLK54XX_PER_12M_GFCLK,
	CLK54XX_C2C_GFCLK, /* ES2.0 only */
	CLK54XX_C2C_ICLK, /* ES2.0 only */
	CLK54XX_C2C_GICLK, /* ES2.0 only */
	CLK54XX_EMIF_LL_GCLK, /* ES2.0 only */
	CLK54XX_GPU_L3_GICLK, /* ES2.0 only */
	CLK54XX_DSS_L4_GICLK, /* ES2.0 only */
	CLK54XX_ID_MAX
} clk54xx_id;


double clk54xx_sysclk_rate_get(void);
const char *clk54xx_name_get(clk54xx_id id);
double clk54xx_rate_get(clk54xx_id clk, unsigned short ignore);
double clk54xx_rate_get_fw(clk54xx_id clk);
const char *clk54xx_name_get_fw(clk54xx_id id);


#endif
