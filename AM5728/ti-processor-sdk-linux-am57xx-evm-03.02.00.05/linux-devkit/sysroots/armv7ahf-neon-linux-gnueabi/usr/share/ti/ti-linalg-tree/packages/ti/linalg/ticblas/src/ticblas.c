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
#include <ti/libarch/libarch.h>
#include "../ticblas.h"
#include "blis.h"

/*=============================================================================
 * This file contains the CBLAS API Extension for TI-DSP. This extension is used
 * in the OpenCL DSP layer for ARM+DSP CBLAS library. It may also be used directly
 * by the user for DSP-only applications. 
 *===========================================================================*/

/* Define memory descriptors for memory management */
lib_memdscr_t blas_mem_vfast;    /* memory descriptor for very fast scratch memory */
lib_memdscr_t blas_mem_fast;     /* memory descriptor for fast scratch memory */
lib_memdscr_t blas_mem_medium;   /* memory descriptor for medium speed scratch memory */
lib_memdscr_t blas_mem_slow;     /* memory descriptor for slow scratch memory */

/* Define an array of memory descriptors by BLAS */
lib_memdscr_t * blas_memdscr_tab[LIB_MEMTYPE_N] = {
    &blas_mem_vfast,
    &blas_mem_fast,
    &blas_mem_medium,
    &blas_mem_slow
};

/*==============================================================================
 * This internal function returns the address of the memory descriptor array.
 *============================================================================*/
void * blasGetMemHandle(void)
{
    return((void *)&blas_memdscr_tab[0]);
} /* blasGetMemHandle */

/*==============================================================================
 * External API. Refer to ticblas.h for detailed documentation.
 *============================================================================*/
void tiCblasGetSizes(size_t *smem_size_vfast,  size_t *smem_size_fast, 
                     size_t *smem_size_medium, size_t *smem_size_slow)
{   
    /* get memory requirement information from BLIS */
    bli_get_mem_sizes(smem_size_vfast, smem_size_fast, smem_size_medium, smem_size_slow);
} /* tiCblasGetSizes */

/*==============================================================================
 * External API. Refer to ticblas.h for detailed documentation.
 *============================================================================*/
int tiCblasInit(void * mem_vfast_base,  size_t mem_vfast_size,
                void * mem_fast_base,   size_t mem_fast_size,
                void * mem_medium_base, size_t mem_medium_size,
                void * mem_slow_base,   size_t mem_slow_size)
{
  size_t mem_vfast_size_req, mem_fast_size_req, mem_medium_size_req, mem_slow_size_req;
  lib_memdscr_t **blas_mem_handle = blasGetMemHandle();

  /* Get the memory size requirements by BLIS */
  bli_get_mem_sizes(&mem_vfast_size_req, &mem_fast_size_req, 
                    &mem_medium_size_req, &mem_slow_size_req);
    
  /* Verify supplied memory meet requirements */    
  if(  ( (mem_vfast_base  == NULL) || (mem_vfast_size  < mem_vfast_size_req)  )
     ||( (mem_fast_base   == NULL) || (mem_fast_size   < mem_fast_size_req)   )
     ||( (mem_medium_base == NULL) || (mem_medium_size < mem_medium_size_req) )
     ||( (mem_slow_base   == NULL) || (mem_slow_size   < mem_slow_size_req)   )
    ) {
    return(TICBLAS_ERROR_NOMEM);
  }
  else {
    /* Initialize all 4 types of scratch heaps */
    lib_smem_vinit(blas_mem_handle, mem_vfast_base,  mem_vfast_size);
    lib_smem_finit(blas_mem_handle, mem_fast_base,   mem_fast_size);
    lib_smem_minit(blas_mem_handle, mem_medium_base, mem_medium_size);
    lib_smem_sinit(blas_mem_handle, mem_slow_base,   mem_slow_size);      
    
    /* Make a BLIS call to allocate scratch memory from very fast heap, 
     * fast heap and medium speed heap for BLIS. Slow memoris are allocated during 
     * BLIS compuation. Refer to blis/frame/base/bli_mem.c for detailed information. 
     */
    if(bli_scratch_mem_alloc() == BLI_MEM_ALLOC_ERROR) {
      return(TICBLAS_ERROR_MEMALLOC);
    }
    else {
      return(TICBLAS_SUCCESS);
    }
  }
} /* tiCblasInit */

/*==============================================================================
 * External API. Refer to ticblas.h for detailed documentation.
 *============================================================================*/
int tiCblasNew(void)
{
  if(bli_init() == BLIS_SUCCESS) {
    return(TICBLAS_SUCCESS);
  }
  else {
    return(TICBLAS_ERROR_NEW);
  }
}

/*==============================================================================
 * External API. Refer to ticblas.h for detailed documentation.
 *============================================================================*/
int tiCblasDelete(void)
{
  if(bli_finalize() == BLIS_SUCCESS) {
    return(TICBLAS_SUCCESS);
  }
  else {
    return(TICBLAS_ERROR_DELETE);
  }
}

/* Nothing after this line */
