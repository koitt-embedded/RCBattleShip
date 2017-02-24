/*
 * Copyright (c) 2015, Texas Instruments Incorporated - http://www.ti.com/
 *   All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *      * Redistributions of source code must retain the above copyright
 *        notice, this list of conditions and the following disclaimer.
 *      * Redistributions in binary form must reproduce the above copyright
 *        notice, this list of conditions and the following disclaimer in the
 *        documentation and/or other materials provided with the distribution.
 *      * Neither the name of Texas Instruments Incorporated nor the
 *        names of its contributors may be used to endorse or promote products
 *        derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE.
 */
#include <stdint.h>

#include <c6x.h>

// For System_printf
#include <xdc/std.h>
#include <xdc/runtime/System.h>

#include <ti/csl/csl_chip.h>

// QMSS LLD include
#include <ti/drv/qmss/qmss_drv.h>
#include <ti/drv/qmss/qmss_firmware.h>

#if defined (TI_C6678) || defined (TI_C6670) || defined (TI_C6657)
#include <ti/drv/qmss/qmss_drv.h>
#if defined (TI_C6678)
#include <ti/drv/qmss/device/c6678/src/qmss_device.c>
#elif defined (TI_C6657)
#include <ti/drv/qmss/device/c6657/src/qmss_device.c>
#elif defined (TI_C6670)
#include <ti/drv/qmss/device/c6670/src/qmss_device.c>
#endif
#elif defined (TI_C6636)
#include <ti/drv/qmss/qmss_drv.h>
#include <ti/drv/qmss/device/k2h/src/qmss_device.c>
#elif defined (TI_AM572)
#else
#error "Device not supported"
#endif

#include <ti/csl/csl_cache.h>
#include <ti/csl/csl_cacheAux.h>

// Number of descriptors used by the OpenMP runtime
#include <ti/runtime/openmp/src/tomp_defs.h>
#define NUM_OPENMP_DESC  TOMP_EVENT_NUM


void app_qmss_init (void)
{
    if (DNUM != 0) 
        return;

    /* QMSS memories are not cacheable 
     * - Keystone I  devices: MAR52 : 0x34xx_xxxx
     * - Keystone II devices: MAR35 : 0x23xx_xxxx 
     */
#ifdef TI_C6636
    CACHE_disableCaching(35);
    CACHE_setMemRegionInfo(35, 0, 0);
#else
    CACHE_disableCaching(52);
    CACHE_setMemRegionInfo(52, 0, 0);
#endif

    Qmss_InitCfg             qmssCfg;
    Qmss_GlobalConfigParams* qmssGlobalCfg;

    // Set up the linking RAM configuration. Use the internal Linking RAM. 
    qmssCfg.linkingRAM0Base = 0; // Use linking RAM of Navigator SS

    qmssGlobalCfg = &qmssGblCfgParams;
    qmssCfg.linkingRAM0Size = 0; // Use all linking RAM of Navigator SS
    qmssCfg.linkingRAM1Base = 0x0;
    qmssCfg.maxDescNum      = NUM_OPENMP_DESC;

    // Pdsp's are not used by the OpenMP runtime
    int i;
    for (i=0; i<QMSS_MAX_PDSP; i++)
    {
        qmssCfg.pdspFirmware[i].pdspId   = (Qmss_PdspId)i;
        qmssCfg.pdspFirmware[i].firmware = NULL;
        qmssCfg.pdspFirmware[i].size     = 0;
    }

    // Initialize QMSS 
    if (Qmss_init (&qmssCfg, qmssGlobalCfg) != QMSS_SOK)
        System_printf("Qmss_init failed\n");

    // Start QMSS
    if (Qmss_start () != QMSS_SOK)
        System_printf("Qmss_start failed\n");

    System_printf("QMSS initialized by application\n");
}



