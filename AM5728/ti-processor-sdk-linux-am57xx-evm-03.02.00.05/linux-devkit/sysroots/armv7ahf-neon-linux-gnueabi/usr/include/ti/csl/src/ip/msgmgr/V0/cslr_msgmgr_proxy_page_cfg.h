/********************************************************************
 * Copyright (C) 2013-2014 Texas Instruments Incorporated.
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
#ifndef _CSLR_MSGMGRPROXYPAGE_H_
#define _CSLR_MSGMGRPROXYPAGE_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for PROXY_PAGE_CONFIG
**************************************************************************/
typedef struct {
    volatile Uint32 REG[1024];
    volatile Uint8  RSVD0[4092];
} CSL_MsgmgrproxypageProxy_page_configRegs;


/**************************************************************************
* Register Overlay Structure
**************************************************************************/
typedef struct {
    CSL_MsgmgrproxypageProxy_page_configRegs	PROXY_PAGE_CONFIG[32];
} CSL_MsgmgrProxyPageRegs;




/**************************************************************************
* Register Macros
**************************************************************************/

/* This register holds the mapping of the virtual proxy R in Page N to a 
 * physical proxy. For simple configurations, each page is given a single 
 * proxy, physical proxy N and virtual proxies R above 0 should not be used. */
#define CSL_MSGMGRPROXYPAGE_REG(n,i)                            (0x0U + ((n) * (0x1000U)) + (i * (0x4U))


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* REG */

#define CSL_MSGMGRPROXYPAGE_REG_PHYSICAL_PROXY_MASK             (0x0000FFFFU)
#define CSL_MSGMGRPROXYPAGE_REG_PHYSICAL_PROXY_SHIFT            (0U)
#define CSL_MSGMGRPROXYPAGE_REG_PHYSICAL_PROXY_RESETVAL         (0x00000000U)
#define CSL_MSGMGRPROXYPAGE_REG_PHYSICAL_PROXY_MAX              (0x0000ffffU)

#define CSL_MSGMGRPROXYPAGE_REG_RESETVAL                        (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
