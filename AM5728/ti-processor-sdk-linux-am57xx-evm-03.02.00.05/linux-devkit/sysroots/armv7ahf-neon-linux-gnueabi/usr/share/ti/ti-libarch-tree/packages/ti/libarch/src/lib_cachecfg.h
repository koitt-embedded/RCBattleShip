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
#ifndef _LIBARCH_CACHE_CONFIG_H
#define _LIBARCH_CACHE_CONFIG_H

#ifdef LIB_OPENCL 
#include <dsp_c.h>
#else
#   ifdef LIB_RTOS
#     include <ti/csl/csl_cache.h>
#     include <ti/csl/csl_cacheAux.h>
#   else
#     error "Unsupported OS! Please specify either LIB_OPENCL or LIB_RTOS"
#   endif
#endif

/** @defgroup libarch_cachecfg Cache Configuration API
 *  @{
 */
/** @} */

/** @addtogroup libarch_cachecfg
 *  @{
 *  @name Cache Configuration Macros
 *  @brief L1D and L2 related macros 
 */
/*@{*/
/**
 *  @brief L1D and L2 information such as base address, total size, etc.
 *  \remark These macros are meant to be used by the inlined functions defined 
 *          in this header file. Users should NOT directly use these macros, but
 *          should use the appropriate functions. 
 */
#ifdef LIB_RTOS
#define LIB_L1D_BASE_ADDRESS_K2H         (0x00F00000U)
#define LIB_L2_BASE_ADDRESS_K2H          (0x00800000U)
#define LIB_L2_SRAM_SIZE_DEFAULT_K2H     (896*1024UL) 
#define LIB_L2_SIZE_TOTAL_K2H            (1024*1024UL) 
#define LIB_L1D_BASE_ADDRESS_AM572x      (0x00F00000U)
#define LIB_L2_BASE_ADDRESS_AM572x       (0x00800000U)
#define LIB_L2_SRAM_SIZE_DEFAULT_AM572x  (128*1024UL) 
#define LIB_L2_SIZE_TOTAL_AM572x         (288*1024UL) 

#define LIB_L1D_BASE_ADDRESS_C6678       (0x00F00000U)
#define LIB_L2_BASE_ADDRESS_C6678        (0x00800000U)
#define LIB_L2_SRAM_SIZE_DEFAULT_C6678   (384*1024UL) 
#define LIB_L2_SIZE_TOTAL_C6678          (512*1024UL) 
#endif

#ifdef SOC_K2H
#define LIB_L2_SIZE_TOTAL          LIB_L2_SIZE_TOTAL_K2H       
#define LIB_L1D_BASE_ADDRESS       LIB_L1D_BASE_ADDRESS_K2H 
#define LIB_L2_BASE_ADDRESS        LIB_L2_BASE_ADDRESS_K2H  
#else
#ifdef SOC_AM572x
#define LIB_L2_SIZE_TOTAL          LIB_L2_SIZE_TOTAL_AM572x       
#define LIB_L1D_BASE_ADDRESS       LIB_L1D_BASE_ADDRESS_AM572x 
#define LIB_L2_BASE_ADDRESS        LIB_L2_BASE_ADDRESS_AM572x  
#else
#ifdef SOC_C6678
#define LIB_L2_SIZE_TOTAL          LIB_L2_SIZE_TOTAL_C6678       
#define LIB_L1D_BASE_ADDRESS       LIB_L1D_BASE_ADDRESS_C6678 
#define LIB_L2_BASE_ADDRESS        LIB_L2_BASE_ADDRESS_C6678 
#else
#error "Unsupported TARGET"
#endif															
#endif
#endif

#define LIB_L1D_SIZE_TOTAL         (32*1024UL) 

/*@}*/
/** @} */

/** @addtogroup libarch_cachecfg
 *  @{
 *  @brief Error return codes of cache configuration functions.
 */
/*@{*/
#define LIB_CACHE_SUCCESS          (0)   /**< Success. No error.            */
#define LIB_CACHE_ERROR            (-1)  /**< Failure.                      */ 
/*@}*/
/** @} */

/** 
 *  @ingroup libarch_cachecfg
 *  @brief Function lib_get_L1D_SRAM_base() returns the base address of the
 *         configured L1D SRAM that can be used as scratchpad. 
 *
 *  @retval     Base address of SRAM in L1D
 */
static inline void * lib_get_L1D_SRAM_base()
{
#ifdef LIB_OPENCL 
    return((void *)__scratch_l1d_start()); 
#else
#   ifdef LIB_RTOS
        return((void *)LIB_L1D_BASE_ADDRESS); 
#   else
#       error "Unsupported OS! Please specify either LIB_OPENCL or LIB_RTOS"
#   endif
#endif
}

/** 
 *  @ingroup libarch_cachecfg
 *  @brief Function lib_get_L2_SRAM_base() returns the base address of the 
 *         configured L2 SRAM that can be used as scratchpad.
 *
 *  @retval     Base address of SRAM in L2
 */
static inline void * lib_get_L2_SRAM_base()
{
#ifdef LIB_OPENCL 
    return((void *)__scratch_l2_start()); 
#else
#   ifdef LIB_RTOS
        return((void *)LIB_L2_BASE_ADDRESS); 
#   else
#       error "Unsupported OS! Please specify either LIB_OPENCL or LIB_RTOS"
#   endif
#endif
}

/** 
 *  @ingroup libarch_cachecfg
 *  @brief Function lib_get_L1D_total_size() returns the total size of L1D.  
 *
 *  @retval     Total size of L1D
 */
static inline int lib_get_L1D_total_size()
{
#ifdef LIB_OPENCL 
    return(__scratch_l1d_size() + __cache_l1d_size()); 
#else
#   ifdef LIB_RTOS
        return(LIB_L1D_SIZE_TOTAL);
#   else
#       error "Unsupported OS! Please specify either LIB_OPENCL or LIB_RTOS"
#   endif
#endif
}

/** 
 *  @ingroup libarch_cachecfg
 *  @brief Function lib_get_L1D_SRAM_size() returns the size of the configured 
 *         L1D SRAM that can be used as scratchpad. 
 *
 *  @retval     Size of SRAM in L1D
 */
#ifdef LIB_OPENCL 
    static inline uint32_t lib_get_L1D_SRAM_size()
    {
        return(__scratch_l1d_size()); 
    }
#else
#   ifdef LIB_RTOS
        extern uint32_t lib_get_L1D_SRAM_size(); 
#   else
#       error "Unsupported OS! Please specify either LIB_OPENCL or LIB_RTOS"
#   endif
#endif

/** 
 *  @ingroup libarch_cachecfg
 *  @brief Function lib_get_L2_total_size() returns the total size of L2.  
 *
 *  @retval     Maximum size of SRAM in L2
 */
static inline int lib_get_L2_total_size()
{   
#ifdef LIB_OPENCL 
    return(__scratch_l2_size() + __cache_l2_size()); 
#else
#   ifdef LIB_RTOS
        return(LIB_L2_SIZE_TOTAL);
#   else
#       error "Unsupported OS! Please specify either LIB_OPENCL or LIB_RTOS"
#   endif
#endif
}

/** 
 *  @ingroup libarch_cachecfg
 *  @brief Function lib_get_L2_SRAM_size() returns the size of the configured 
 *         L2 SRAM that can be used as scratchpad. 
 *
 *  @retval     Size of SRAM in L2
 */
#ifdef LIB_OPENCL 
    static inline uint32_t lib_get_L2_SRAM_size()
    {
      return(__scratch_l2_size());
    }	
#else
#   ifdef LIB_RTOS
        extern uint32_t lib_get_L2_SRAM_size(); /* defined in lib_cachecfg.c */
#   else
#       error "Unsupported OS! Please specify either LIB_OPENCL or LIB_RTOS"
#   endif
#endif


/** 
 *  @ingroup libarch_cachecfg
 *  @brief Function \ref lib_L1D_config_SRAM configures L1D to have the desired 
 *         SRAM size. 
 *
 *  @param[in] size_SRAM    desired L1D SRAM size in bytes
 *
 *  @retval   LIB_CACHE_SUCCESS    @copydoc LIB_CACHE_SUCCESS
 *  @retval   LIB_CACHE_ERROR      @copydoc LIB_CACHE_ERROR
 *
 *  \remark L1D will be write-back invalidated before being configured. 
 *  \remark To avoid unnecessary cache configuration, users can first call function 
 *          lib_get_L1D_SRAM_size() to find out current SRAM size. If it is the 
 *          desired size, this function does not need to be called. 
 */
extern int lib_L1D_config_SRAM(size_t size_SRAM);

/** 
 *  @ingroup libarch_cachecfg
 *  @brief Function lib_L2_config_SRAM() configures L2 to have desired SRAM size. 
 *
 *  @param[in] size_SRAM    desired L2 SRAM size in bytes
 *
 *  @retval   LIB_CACHE_SUCCESS    @copydoc LIB_CACHE_SUCCESS
 *  @retval   LIB_CACHE_ERROR    @copydoc LIB_CACHE_ERROR
 *
 *  \remark L2 will be write-back invalidated before being configured. 
 *  \remark To avoid unnecessary cache configuration, users can first call function 
 *          lib_get_L2_SRAM_size() to find out current SRAM size. If it is the 
 *          desired size, this function does not need to be called. 
 */
extern int lib_L2_config_SRAM(size_t size_SRAM);

#endif  /* _LIBARCH_CACHE_CONFIG_H */

/* nothing past this point */
