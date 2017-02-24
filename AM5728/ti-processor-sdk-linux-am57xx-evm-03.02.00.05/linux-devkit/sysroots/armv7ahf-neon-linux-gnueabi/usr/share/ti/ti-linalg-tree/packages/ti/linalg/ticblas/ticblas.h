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
#ifndef _TICBLAS_H
#define _TICBLAS_H

#include <stddef.h> 

/** @defgroup ti_cblas_api CBLAS API Extension for TI-DSP 
 *  @brief This extension contains the initialization and finalization APIs 
 *         for proper usage of CBLAS optimized for TI's C66x DSP.
 *            - for ARM+DSP applications with CBLAS API on ARM (host), users
 *              do not need to use this extension. 
 *            - for DSP-only applications, uers will need to use this extension
 *              to set up before making standard CBLAS calls in their programs
 *              running on the DSP, and to tear down before the program exits. 
 *  @{
 */
/** @} */

/** @addtogroup ti_cblas_api 
 *  @{
 *  @name Error Return Codes
 */
/*@{*/
#define TICBLAS_SUCCESS        (0)  /**< Success. No error.                      */
#define TICBLAS_ERROR_NOMEM    (1)  /**< Failure. Provided memory is not enough. */
#define TICBLAS_ERROR_MEMALLOC (2)  /**< Failure. Memory allocation error.       */
#define TICBLAS_ERROR_NEW      (3)  /**< Failure. CBLAS creation error.          */
#define TICBLAS_ERROR_DELETE   (4)  /**< Failure. CBLAS deletion error.          */
/*@}*/
/** @} */

/**
 *  @ingroup ti_cblas_api
 *  @brief   Function tiCblasGetSizes() returns the required size of each of 
 *           the memory types defined by the Library Architecture and 
 *           Framework  (LibArch).
 *
 *  @remarks Memory types are categorized into scratch and permanent memory:
 *           - Scratch memory content doesn't need to be stored from call to call;
 *           - Permanent memory content must be stored across multiple calls.
 *           For example, if an application uses library A and library B, the 
 *           scratch memory of library A and library B can be shared/overlapped,
 *           but permanent memory may not be shared/overlapped.  
 *
 *           Scratch and permanent memory are each categorized into four types
 *           based on speed:
 *           - very fast memory, e.g. L1D;
 *           - fast memory, e.g. L2;
 *           - medium speed memory, e.g. L3/MSMC;
 *           - slow memory, e.g. DDR.
 *
 *  @param[out]  smem_size_vfast    size of very fast scratch memory 
 *  @param[out]  smem_size_fast     size of fast scratch memory 
 *  @param[out]  smem_size_medium   size of medium speed scratch memory 
 *  @param[out]  smem_size_slow     size of slow scratch memory  
 *
 */
void tiCblasGetSizes(size_t *smem_size_vfast,  size_t *smem_size_fast, 
                     size_t *smem_size_medium, size_t *smem_size_slow);

/**
 *  @ingroup ti_cblas_api
 *  @brief   Function tiCblasNew() creates and initializes global structures 
 *           for CBLAS.
 *
 *  @remarks  tiCblasNew() MUST be called before tiCblasInit().
 *
 *  @retval     TICBLAS_SUCCESS      @copydoc TICBLAS_SUCCESS
 *  @retval     TICBLAS_ERROR_NEW    @copydoc TICBLAS_ERROR_NEW
 */
int tiCblasNew(void);

/**
 *  @ingroup ti_cblas_api
 *  @brief   Function tiCblasInit() performs heap initialization for TI CBLAS 
 *           to do dynamic memory allocations. 
 *
 *  @remarks  Users must allocate memory according to the requirements 
 *            given by tiCblasGetSizes() and pass the bases and sizes to this
 *            function. 
 *
 *  @remarks  tiCblasNew() MUST be called before tiCblasInit() can be called.
 *
 *  @remarks  The provided memory can be shared with other modules and thus its
 *            content do not need to be preserved from call to call. If the 
 *            memory bases do not change from call to call, this function only 
 *            needs to be called just once at boot time. However, if it cannot
 *            be guaranteed that memory bases stay the same, this function 
 *            needs to be called every time a level 3 CBLAS function is called
 *            on DSP. 
 *
 *  @param[in]  smem_vfast_base    base of very fast scratch memory 
 *  @param[in]  smem_vfast_size    size of very fast scratch memory 
 *  @param[in]  smem_fast_base     base of fast scratch memory 
 *  @param[in]  smem_fast_size     size of fast scratch memory  
 *  @param[in]  smem_medium_base   base of medium speed scratch memory 
 *  @param[in]  smem_medium_size   size of medium speed scratch memory 
 *  @param[in]  smem_slow_base     base of slow scratch memory 
 *  @param[in]  smem_slow_size     size of slow scratch memory  
 *
 *  @retval     TICBLAS_SUCCESS         @copydoc TICBLAS_SUCCESS
 *  @retval     TICBLAS_ERROR_NOMEM     @copydoc TICBLAS_ERROR_NOMEM
 *  @retval     TICBLAS_ERROR_MEMALLOC  @copydoc TICBLAS_ERROR_MEMALLOC
 */
int tiCblasInit(void * smem_vfast_base,  size_t smem_vfast_size,
                void * smem_fast_base,   size_t smem_fast_size,
                void * smem_medium_base, size_t smem_medium_size,
                void * smem_slow_base,   size_t smem_slow_size);

/**
 *  @ingroup ti_cblas_api
 *  @brief   Function tiCblasDelete() deletes global structures and frees 
 *           memory of CBLAS created by tiCblasNew(). 
 *
 *  @retval     TICBLAS_SUCCESS         @copydoc TICBLAS_SUCCESS
 *  @retval     TICBLAS_ERROR_DELETE    @copydoc TICBLAS_ERROR_DELETE
 */
int tiCblasDelete(void);

#endif  /* _TICBLAS_H */
