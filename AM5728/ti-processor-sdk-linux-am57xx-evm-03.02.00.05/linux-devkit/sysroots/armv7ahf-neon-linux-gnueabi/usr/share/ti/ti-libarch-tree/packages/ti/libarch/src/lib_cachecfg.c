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
#include <xdc/std.h>
#include "lib_cachecfg.h"

#ifdef LIB_OPENCL 
#include <dsp_c.h>
#endif

/**
 *  @brief Macros for cache sizes in bytes
 */
#define LIB_SIZE_4KB       (4*1024UL)
#define LIB_SIZE_8KB       (8*1024UL)
#define LIB_SIZE_16KB      (16*1024UL)
#define LIB_SIZE_32KB      (32*1024UL)
#define LIB_SIZE_64KB      (64*1024UL)
#define LIB_SIZE_128KB     (128*1024UL)
#define LIB_SIZE_256KB     (256*1024UL)
#define LIB_SIZE_512KB     (512*1024UL)
#define LIB_SIZE_1024KB    (1024*1024UL)

/**
 *  @brief Function lib_L1D_config_SRAM() configures L1D to have the desired 
 *         SRAM size. Refer to lib_cachecfg.h for detailed documentation.
 */
int lib_L1D_config_SRAM(size_t size_SRAM)
{
    int size_cache;
    
    /* Convert SRAM size to cache size since cache configuration API deals with 
       cache size */
    size_cache = lib_get_L1D_total_size() - (int)size_SRAM;

    /* Due to limited configurable cache size, configure cache to smaller size 
       if necessary, in order to satisfy the SRAM request.
    */      
#ifdef LIB_OPENCL 
    /* use OpenCL builtins to do cache configuration */
    if(size_cache == lib_get_L1D_total_size()) {
        __cache_l1d_all();
    }
    else if(size_cache >= LIB_SIZE_16KB) {
        __cache_l1d_16k();
    }
    else if(size_cache >= LIB_SIZE_8KB) {
        __cache_l1d_8k();
    }
    else if(size_cache >= LIB_SIZE_4KB) {
        __cache_l1d_4k();
    }
    else if(size_cache >= 0) {
        __cache_l1d_none();
    }
    else {
        return(LIB_CACHE_ERROR);
    }
#else
#   ifdef LIB_RTOS
    if(size_cache < 0) {
        return(LIB_CACHE_ERROR);
    }
    /* use CSL functions to do cache configuration */
    else if(size_cache >= lib_get_L1D_total_size()) {
        CACHE_setL1DSize(CACHE_L1_32KCACHE);  /* no need to do CACHE_wbinv */
    }
    else{
        CACHE_wbInvAllL1d(CACHE_WAIT);   /* first write back and invalidate */

        if(size_cache >= LIB_SIZE_16KB) {
            CACHE_setL1DSize(CACHE_L1_16KCACHE);
        }
        else if(size_cache >= LIB_SIZE_8KB) {
            CACHE_setL1DSize(CACHE_L1_8KCACHE);
        }
        else if(size_cache >= LIB_SIZE_4KB) {
            CACHE_setL1DSize(CACHE_L1_4KCACHE);
        }
        else {
            CACHE_setL1DSize(CACHE_L1_0KCACHE);
        }
    }
#   else
#     error "Unsupported OS! Please specify either LIB_OPENCL or LIB_RTOS"
#   endif
#endif
    
    return(LIB_CACHE_SUCCESS);
} /* lib_L1D_config_SRAM */
   
/**
 *  @brief Function lib_L2_config_SRAM() configures L2 to have the desired 
 *         SRAM size. Refer to lib_cachecfg.h for detailed documentation.
 */
int lib_L2_config_SRAM(size_t size_SRAM)
{
    int size_cache;
    
    size_cache = lib_get_L2_total_size() - (int)size_SRAM;
    
#ifdef LIB_OPENCL 
    /* use OpenCL builtins to do cache configuration */
    if(size_cache >= LIB_SIZE_512KB) {
        __cache_l2_512k();
    }
    else if(size_cache >= LIB_SIZE_256KB) {
        __cache_l2_256k();
    }
    else if(size_cache >= LIB_SIZE_128KB) {
        __cache_l2_128k();
    }
    else if(size_cache >= 0) {
        __cache_l2_none();
    }
    else {
        return(LIB_CACHE_ERROR);
    }
#else
#   ifdef LIB_RTOS
    if(size_cache < 0) {
        return(LIB_CACHE_ERROR);
    }
    else {
        /* use CSL functions to do cache configuration */
        CACHE_wbInvAllL2(CACHE_NOWAIT);

        if(size_cache >= LIB_SIZE_1024KB) {
            CACHE_setL2Size(CACHE_1024KCACHE);
        }
        else if(size_cache >= LIB_SIZE_512KB) {
            CACHE_setL2Size(CACHE_512KCACHE);
        }
        else if(size_cache >= LIB_SIZE_256KB) {
            CACHE_setL2Size(CACHE_256KCACHE);
        }
        else if(size_cache >= LIB_SIZE_128KB) {
            CACHE_setL2Size(CACHE_128KCACHE);
        }
        else if(size_cache >= LIB_SIZE_64KB) {
            CACHE_setL2Size(CACHE_64KCACHE);
        }
        else if(size_cache >= LIB_SIZE_32KB) {
            CACHE_setL2Size(CACHE_32KCACHE);
        }
        else {
            CACHE_setL2Size(CACHE_0KCACHE);
        }
    }
#   else
#     error "Unsupported OS! Please specify either LIB_OPENCL or LIB_RTOS"
#   endif
#endif
    
    return(LIB_CACHE_SUCCESS);
} /* lib_L2_config_SRAM */

#ifdef LIB_RTOS
/**
 *  @brief Function lib_cache_l1d_size() obtains the size of L1D cache in bytes.
 *         This function is needed only for TI-RTOS case without OpenCL built-in.
 */
static inline uint32_t lib_cache_l1d_size()
{
    switch (CACHE_getL1DSize())  /* CACHE_getL1DSize() returns size in KB */
    {
        case CACHE_L1_0KCACHE:  return 0;
        case CACHE_L1_4KCACHE:  return (4  << 10);
        case CACHE_L1_8KCACHE:  return (8  << 10);
        case CACHE_L1_16KCACHE: return (16 << 10);
        case CACHE_L1_32KCACHE: return (32 << 10);
        default:                return (32 << 10);
    }
}

/**
 *  @brief Function lib_get_L1D_SRAM_size() obtains the size of L1D SRAM in bytes. 
 *  Refer to lib_cachecfg.h for detailed API description.
 */
uint32_t lib_get_L1D_SRAM_size()
{
    return(lib_get_L1D_total_size() - lib_cache_l1d_size()); 
}

/**
 *  @brief Function lib_cache_l2_size() obtains the size of L2 cache in bytes.
 *         This function is needed only for TI-RTOS case without OpenCL built-in.
 */
static inline uint32_t lib_cache_l2_size()
{
    switch (CACHE_getL2Size())  /* CACHE_getL2Size() returns size in KB */
    {
        case CACHE_0KCACHE:    return 0;
        case CACHE_32KCACHE:   return (32   << 10);
        case CACHE_64KCACHE:   return (64   << 10);
        case CACHE_128KCACHE:  return (128  << 10);
        case CACHE_256KCACHE:  return (256  << 10);
        case CACHE_512KCACHE:  return (512  << 10);
        case CACHE_1024KCACHE: return (1024 << 10);
        default:               return (1024 << 10);
    }
}

/**
 *  @brief Function lib_get_L2_SRAM_size() obtains the size of L2 SRAM in bytes. 
 *  Refer to lib_cachecfg.h for detailed API description.
 */
uint32_t lib_get_L2_SRAM_size()
{
    return(lib_get_L2_total_size() - lib_cache_l2_size());
}
#endif

/* nothing past this point */
