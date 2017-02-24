/******************************************************************************
 * Copyright (c) 2015, Texas Instruments Incorporated - http://www.ti.com
 *   All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions are met:
 *       * Redistributions of source code must retain the above copyright
 *         notice, this list of conditions and the following disclaimer.
 *       * Redistributions in binary form must reproduce the above copyright
 *         notice, this list of conditions and the following disclaimer in the
 *         documentation and/or other materials provided with the distribution.
 *       * Neither the name of Texas Instruments Incorporated nor the
 *         names of its contributors may be used to endorse or promote products
 *         derived from this software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 *   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 *   THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/
#ifndef _LIBARCH_UTILS_H
#define _LIBARCH_UTILS_H

//#include <c6x.h>
#include <ti/csl/csl_tsc.h>

#ifdef LIB_OPENCL 
#include <dsp_c.h>
#endif

/** @defgroup libarch_utils Utilities API
 *  @{
 */
/** @} */

/** 
 *  @ingroup libarch_utils
 *
 *  @brief Function lib_get_coreID returns the DSP Core Number of the core 
 *         currently executing this code. 
 *  @retval      DSP core number
 *
 */
static inline int lib_get_coreID()
{
  return(CSL_chipReadDNUM());
}

/** 
 *  @ingroup libarch_utils
 *
 *  @brief Function lib_clock_enable enables the time stamp counter. 
 *  @retval      None 
 *
 */
static inline void lib_clock_enable(void)
{
  /* Time stamp counter is enabled by writing to TSCL. The value written to 
     TSCL is ignored. */
  //TSCL = 0; 
  CSL_tscEnable();
}


/** 
 *  @ingroup libarch_utils
 *
 *  @brief Function lib_clock_read returns the 64-bit clock register of the core 
 *         currently executing this code. 
 *  @retval      DSP clock register (time stamp counter register) 
 *
 */
static inline uint64_t lib_clock_read(void)
{
  //uint32_t low  = TSCL;
  //uint32_t high = TSCH;
  //return _itoll(high,low);
  return (uint64_t)CSL_tscRead();
}

#endif /* _LIBARCH_UTILS_H */
/* nothing past this point */
