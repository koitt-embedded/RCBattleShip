/*
 *
 * Copyright (C) 2011-2013 Texas Instruments Incorporated - http://www.ti.com/
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

#ifndef CSL_AM572X_DEVICE_PLLC_H
#define CSL_AM572X_DEVICE_PLLC_H

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

/**
 *  \brief This structure defines the various Configuration Parameters for
 *         a DPLL.
 */
typedef struct {
    Uint32 mult;
    /**< Multiplier(m) Value */
    Uint32 div;
    /**< Divider(n) Value */
    Uint32 dccEnable;
    /**< Divider(n) Value */
    Uint32 autoDpllMode;
    /**< Auto DPLL Mode, refer to enum #sbllibAutoDpllMode_t for values */
    Uint32 divM2;
    /**< M2 Divider Value */
    Uint32 divM3;
    /**< M3 Divider Value */
    Uint32 divH11;
    /**< H11 Divider Value */
    Uint32 divH12;
    /**< H12 Divider Value */
    Uint32 divH13;
    /**< H13 Divider Value */
    Uint32 divH14;
    /**< H14 Divider Value */
    Uint32 divH21;
    /**< H21 Divider Value */
    Uint32 divH22;
    /**< H22 Divider Value */
    Uint32 divH23;
    /**< H23 Divider Value */
    Uint32 divH24;
    /**< H24 Divider Value */
} CSL_PllcParam;

/**
 *  \brief This structure defines the various Configuration Parameters for
 *         a MPU DPLL.
 */
typedef struct {
    Uint32 mult;
    /**< Multiplier(m) Value */
    Uint32 div;
    /**< Divider(n) Value */
    Uint32 dccEnable;
    /**< Divider(n) Value */
    Uint32 divM2;
    /**< M2 Divider Value */
} CSL_PllcMpuParam;

/**
 *  \brief This structure defines the various Configuration Parameters for
 *         a peripheral DPLL.
 */
typedef struct {
    Uint32 mult;
    /**< Multiplier(m) Value */
    Uint32 div;
    /**< Divider(n) Value */
    Uint32 divM2;
    /**< M2 Divider Value */
    Uint32 divM3;
    /**< M3 Divider Value */
    Uint32 divH11;
    /**< H11 Divider Value */
    Uint32 divH12;
    /**< H12 Divider Value */
    Uint32 divH13;
    /**< H13 Divider Value */
    Uint32 divH14;
    /**< H14 Divider Value */
} CSL_PllcPerParam;

/**
 *  \brief This structure defines the various Configuration Parameters for
 *         a core DPLL.
 */
typedef struct {
    Uint32 l3ClkSel;
    /**< L3 divider */
    Uint32 l4ClkSel;
    /**< L3 divider */
    Uint32 mult;
    /**< Multiplier(m) Value */
    Uint32 div;
    /**< Divider(n) Value */
    Uint32 divM2;
    /**< M2 Divider Value */
    Uint32 divM3;
    /**< M3 Divider Value */
    Uint32 divH12;
    /**< H12 Divider Value */
    Uint32 divH13;
    /**< H13 Divider Value */
    Uint32 divH14;
    /**< H14 Divider Value */
    Uint32 divH22;
    /**< H22 Divider Value */
    Uint32 divH23;
    /**< H23 Divider Value */
    Uint32 divH24;
    /**< H24 Divider Value */
} CSL_PllcCoreParam;

/**
 *  \brief This structure defines the various Configuration Parameters for
 *         an ABE DPLL.
 */
typedef struct {
    Uint32 mult;
    /**< Multiplier(m) Value */
    Uint32 div;
    /**< Divider(n) Value */
    Uint32 divM2;
    /**< M2 Divider Value */
    Uint32 divM3;
    /**< M3 Divider Value */
} CSL_PllcAbeParam;

/**
 *  \brief This structure defines the various Configuration Parameters for
 *         an IVA DPLL.
 */
typedef struct {
    Uint32 mult;
    /**< Multiplier(m) Value */
    Uint32 div;
    /**< Divider(n) Value */
    Uint32 divM2;
    /**< M2 Divider Value */
} CSL_PllcIvaParam;

/**
 *  \brief This structure defines the various Configuration Parameters for
 *         a GMAC DPLL.
 */
typedef struct {
    Uint32 mult;
    /**< Multiplier(m) Value */
    Uint32 div;
    /**< Divider(n) Value */
    Uint32 divM2;
    /**< M2 Divider Value */
    Uint32 divM3;
    /**< M3 Divider Value */
    Uint32 divH11;
    /**< H11 Divider Value */
    Uint32 divH12;
    /**< H12 Divider Value */
    Uint32 divH13;
    /**< H13 Divider Value */
} CSL_PllcGmacParam;

/**
 *  \brief This structure defines the various Configuration Parameters for
 *         a PCIE DPLL.
 */
typedef struct {
    Uint32 mult;
    /**< Multiplier(m) Value */
    Uint32 div;
    /**< Divider(n) Value */
    Uint32 divM2;
    /**< M2 Divider Value */
} CSL_PllcPcieParam;

/**
 *  \brief This structure defines the various Configuration Parameters for
 *         a DDR DPLL.
 */
typedef struct {
    Uint32 mult;
    /**< Multiplier(m) Value */
    Uint32 div;
    /**< Divider(n) Value */
    Uint32 divM2;
    /**< M2 Divider Value */
    Uint32 divM3;
    /**< M3 Divider Value */
    Uint32 divH11;
    /**< H11 Divider Value */
} CSL_PllcDdrParam;

/**
 *  \brief This structure defines the various Configuration Parameters for
 *         a GPU DPLL.
 */
typedef struct {
    Uint32 mult;
    /**< Multiplier(m) Value */
    Uint32 div;
    /**< Divider(n) Value */
    Uint32 divM2;
    /**< M2 Divider Value */
} CSL_PllcGpuParam;

/**
 *  \brief This structure defines the various Configuration Parameters for
 *         a DSP DPLL.
 */
typedef struct {
    Uint32 mult;
    /**< Multiplier(m) Value */
    Uint32 div;
    /**< Divider(n) Value */
    Uint32 divM2;
    /**< M2 Divider Value */
    Uint32 divM3;
    /**< M3 Divider Value */
} CSL_PllcDspParam;


void CSL_pllcMpuUnlock(void);

void CSL_pllcMpuLock(void);

void CSL_pllcMpuConfigure(const CSL_PllcMpuParam *mpuPllcParam);

void CSL_pllcIvaUnlock(void);

void CSL_pllcIvaLock(void);

void CSL_pllcIvaConfigure(const CSL_PllcIvaParam *ivaPllcParam);

void CSL_pllcCoreUnlock(void);

void CSL_pllcCoreLock(void);

void CSL_pllcCoreConfigure(const CSL_PllcCoreParam *corePllcParam);

void CSL_pllcAbeUnlock(void);

void CSL_pllcAbeLock(void);

void CSL_pllcAbeConfigure(const CSL_PllcAbeParam *abePllcParam);

void CSL_pllcDdrUnlock(void);

void CSL_pllcDdrLock(void);

void CSL_pllcDdrConfigure(const CSL_PllcDdrParam *ddrPllcParam);

void CSL_pllcDspUnlock(void);

void CSL_pllcDspLock(void);

void CSL_pllcDspConfigure(const CSL_PllcDspParam *dspPllcParam);

void CSL_pllcGmacUnlock(void);

void CSL_pllcGmacLock(void);

void CSL_pllcGmacConfigure(const CSL_PllcGmacParam *gmacPllcParam);

void CSL_pllcGpuUnlock(void);

void CSL_pllcGpuLock(void);

void CSL_pllcGpuConfigure(const CSL_PllcGpuParam *gpuPllcParam);

void CSL_pllcPcieUnlock(void);

void CSL_pllcPcieLock(void);

void CSL_pllcPcieConfigure(const CSL_PllcPcieParam *pciePllcParam);

void CSL_pllcPerUnlock(void);

void CSL_pllcPerLock(void);

void CSL_pllcPerConfigure(const CSL_PllcPerParam *perPllcParam);

#endif /* _CSL_AM572X_DEVICE_PLLC_H */
