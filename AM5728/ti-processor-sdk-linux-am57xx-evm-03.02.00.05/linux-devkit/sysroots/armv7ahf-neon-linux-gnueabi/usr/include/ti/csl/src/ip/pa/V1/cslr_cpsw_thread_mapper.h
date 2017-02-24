/********************************************************************
* Copyright (C) 2012-2013 Texas Instruments Incorporated.
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
#ifndef _CSLR_CPSW_THREAD_MAPPER_H_
#define _CSLR_CPSW_THREAD_MAPPER_H_

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint32 MAP[16]; /* These registers are used to map the threads coming out of the cpsw (one per port/priority pair), and map them to assets within PA */
} CSL_Cpsw_thread_mapperRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* MAP */

#define CSL_CPSW_THREAD_MAPPER_MAP_TARGET3_MASK (0xFF000000u)
#define CSL_CPSW_THREAD_MAPPER_MAP_TARGET3_SHIFT (0x00000018u)
#define CSL_CPSW_THREAD_MAPPER_MAP_TARGET3_RESETVAL (0x00000000u)

#define CSL_CPSW_THREAD_MAPPER_MAP_TARGET2_MASK (0x00FF0000u)
#define CSL_CPSW_THREAD_MAPPER_MAP_TARGET2_SHIFT (0x00000010u)
#define CSL_CPSW_THREAD_MAPPER_MAP_TARGET2_RESETVAL (0x00000000u)

#define CSL_CPSW_THREAD_MAPPER_MAP_TARGET1_MASK (0x0000FF00u)
#define CSL_CPSW_THREAD_MAPPER_MAP_TARGET1_SHIFT (0x00000008u)
#define CSL_CPSW_THREAD_MAPPER_MAP_TARGET1_RESETVAL (0x00000000u)

#define CSL_CPSW_THREAD_MAPPER_MAP_TARGET0_MASK (0x000000FFu)
#define CSL_CPSW_THREAD_MAPPER_MAP_TARGET0_SHIFT (0x00000000u)
#define CSL_CPSW_THREAD_MAPPER_MAP_TARGET0_RESETVAL (0x00000000u)

#define CSL_CPSW_THREAD_MAPPER_MAP_RESETVAL (0x00000000u)

#endif
