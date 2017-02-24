/******************************************************************************
 * Copyright (c) 2013-2015, Texas Instruments Incorporated - http://www.ti.com/
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
#ifdef TI_CBLAS_DEBUG
#include <stdio.h>
#include <ti/csl/csl_chipAux.h> 
#include <ti/csl/csl_idmaAux.h>
#endif
#include "../../ticblas/ticblas.h"
#include <ti/libarch/libarch.h>

/*==============================================================================
 * This file contains functions of the DSP OpenCL layer of ARM+DSP CBLAS library.
 *============================================================================*/

#define TICBLAS_ERROR_MEMCFG   (-1)  /* L1D/L2 config error.           */
#define TICBLAS_ERROR_MEMRECFG (-2)  /* /L2 reconfig error.            */

extern void bli_init();
extern void bli_finalize();

#ifdef TI_CBLAS_DEBUG 
int malloc_size;
extern lib_memdscr_t * blas_memdscr_tab[4];
#endif

/*==============================================================================
 * This function configures L1D and L2 and initializes heap for BLIS.
 *
 * Input:
 *   msmc_buf              - base address of MSMC/L3 buffer
 *   msmc_buf_size         - size of MSMC/L3 buffer
 *   ddr_buf               - base address of DDR buffer
 *   ddr_buf_size          - size of DDR buffer
 * Output:
 *   l1D_SRAM_size_orig    - original L1D SRAM size
 *   l2_SRAM_size_orig     - original L2 SRAM size
 *============================================================================*/
int blas_mem_config(void *msmc_buf, size_t msmc_buf_size, 
                      void *ddr_buf, size_t ddr_buf_size, 
                      size_t *l1D_SRAM_size_orig, size_t *l2_SRAM_size_orig)
{
    size_t smem_size_vfast, smem_size_fast, smem_size_med, smem_size_slow;
    void *l1d_SRAM_ptr, *l2_SRAM_ptr;
    int l1d_cfg_err, l2_cfg_err, blas_ret_err_code;

#ifdef TI_CBLAS_DEBUG 
    malloc_size = 0;
    printf("Memory buffers passed to blas_mem_config are: MSMC base 0x%x, size %d, DDR base 0x%x, size%d.\n", 
           (unsigned int)msmc_buf, msmc_buf_size, (unsigned int) ddr_buf, ddr_buf_size);
    printf("Before calling BLIS, malloc_size is %d.\n", malloc_size);
#endif
    
    /* First, verify the provided and available memory meet requirements */
    tiCblasGetSizes(&smem_size_vfast, &smem_size_fast, &smem_size_med, &smem_size_slow);
    
#ifdef TI_CBLAS_DEBUG 
    printf("Very fast mem size is %d, fast mem size is %d, medium mem size is %d, slow mem size is %d.\n", 
           smem_size_vfast, smem_size_fast, smem_size_med, smem_size_slow);
    printf("Total L1D size is: %d\n", lib_get_L1D_total_size());
    printf("Total L2 size is: %d\n", lib_get_L2_total_size());
#endif

    if(  (smem_size_vfast> lib_get_L1D_total_size()) /* total available L1D  */
       ||(smem_size_fast > lib_get_L2_total_size())  /* total available L2   */
       ||(smem_size_med  > msmc_buf_size)            /* provided MSMC memory */                 
       ||(smem_size_slow > ddr_buf_size)             /* provided DDR memory  */
      ) {                                                            
#ifdef TI_CBLAS_DEBUG 
        printf("No enough memory!\n");
#endif
        return(TICBLAS_ERROR_NOMEM);
    }
    
    /* Configure L1D if necessary */
    *l1D_SRAM_size_orig = lib_get_L1D_SRAM_size(); /* get current L1D SRAM size  */
    l1d_cfg_err = LIB_CACHE_SUCCESS;
 
#ifdef TI_CBLAS_DEBUG 
   printf("Original L1D SRAM size is: %d\n", *l1D_SRAM_size_orig);
   printf("Required L1D SRAM size is: %d\n", smem_size_vfast);
#endif
 
    if(*l1D_SRAM_size_orig < smem_size_vfast) {    /* configure L1D if needs more SRAM */
      #pragma omp parallel                         
      {
        l1d_cfg_err = lib_L1D_config_SRAM(smem_size_vfast);  
#ifdef TI_CBLAS_DEBUG 
        if(l1d_cfg_err != LIB_CACHE_SUCCESS) {
          printf("Error in configuring L1D on core %d!\n", lib_get_coreID());
        }
        else {
          printf("On core %d, new L1D SRAM size is %d.\n", lib_get_coreID(), lib_get_L1D_SRAM_size());  
        }
#endif
      }
    }  
 
    /* Configure L2 if necessary */
    *l2_SRAM_size_orig  = lib_get_L2_SRAM_size();   /* get current L2 SRAM size */
    l2_cfg_err = LIB_CACHE_SUCCESS;

#ifdef TI_CBLAS_DEBUG 
    printf("Original L2 SRAM size is: %d\n", *l2_SRAM_size_orig);
    printf("Required L2 SRAM size is: %d\n", smem_size_fast);
#endif
 
    if(*l2_SRAM_size_orig < smem_size_fast) {      /* configure L2 if needs more SRAM */
      #pragma omp parallel
      { 
        l2_cfg_err  = lib_L2_config_SRAM(smem_size_fast);    
#ifdef TI_CBLAS_DEBUG 
        if(l2_cfg_err != LIB_CACHE_SUCCESS) {
          printf("Error in configuring L2 on core %d!\n", lib_get_coreID());
        }
        else {
          printf("On core %d, new L2 SRAM size is %d.\n", lib_get_coreID(), lib_get_L2_SRAM_size());  
        }
#endif
      }
    }
    
    if(l1d_cfg_err || l2_cfg_err) {
#ifdef TI_CBLAS_DEBUG 
      printf("L1D or L2 configuration error!\n");
#endif        
      return(TICBLAS_ERROR_MEMCFG);        
    }

#ifdef TI_CBLAS_DEBUG 
    printf("New L1D SRAM size is: %d\n", lib_get_L1D_SRAM_size());
    printf("New L2 SRAM size is: %d\n", lib_get_L2_SRAM_size());
#endif
 
    /* get L1D and L2 SRAM base address */
    l1d_SRAM_ptr = lib_get_L1D_SRAM_base();  
    l2_SRAM_ptr  = lib_get_L2_SRAM_base();   
  
#ifdef TI_CBLAS_DEBUG 
    printf("L1D SRAM base address is 0x%x.\n", (unsigned int)l1d_SRAM_ptr);
    printf("L2  SRAM base address is 0x%x.\n", (unsigned int) l2_SRAM_ptr);
    printf("MSMC SRAM address is 0x%x.\n", (unsigned int) msmc_buf);
#endif
 
    /* pass allocated memories for heap initialization */
    blas_ret_err_code = tiCblasInit(l1d_SRAM_ptr,  smem_size_vfast,
                                    l2_SRAM_ptr,   smem_size_fast,
                                    msmc_buf,      msmc_buf_size, 
                                    ddr_buf,       ddr_buf_size);

#ifdef TI_CBLAS_DEBUG 
    if(blas_ret_err_code == TICBLAS_SUCCESS) {
      printf("Before calling BLIS, memory descriptor base is 0x%x, used is %d.\n", 
             blas_memdscr_tab[3]->base, blas_memdscr_tab[3]->used);
    }
    else {
      printf("BLAS init error with code %d.\n   ", blas_ret_err_code);
    }
#endif
    
    return(blas_ret_err_code);
} /* blas_mem_config */

/*==============================================================================
 * This function reconfigures L1D and L2 after processing is finished
 *============================================================================*/
int blas_mem_reconfig(size_t l1D_SRAM_size_orig, size_t l2_SRAM_size_orig)
{
    int l1d_cfg_err, l2_cfg_err;

#ifdef TI_CBLAS_DEBUG 
    printf("After calling BLIS, malloc_size is %d.\n", malloc_size);
    printf("After calling BLIS, used_size in memory descriptor is %d.\n", 
           blas_memdscr_tab[3]->used);
    printf("Configuring L1D SRAM and L2 SRAM back to %d and %d.\n", 
           l1D_SRAM_size_orig, l2_SRAM_size_orig);
#endif
    
    /* configure L1D back if necessary */    
    l1d_cfg_err = LIB_CACHE_SUCCESS;
    if(l1D_SRAM_size_orig!=lib_get_L1D_SRAM_size()) {
      #pragma omp parallel
      {
        l1d_cfg_err = lib_L1D_config_SRAM(l1D_SRAM_size_orig);    
      }
    }     
    if(l1d_cfg_err != LIB_CACHE_SUCCESS) {
      return(TICBLAS_ERROR_MEMRECFG);
    }   

    /* configure L2 back if necessary */    
    l2_cfg_err = LIB_CACHE_SUCCESS;
    if(l2_SRAM_size_orig != lib_get_L2_SRAM_size()) {
      #pragma omp parallel
      {
        l2_cfg_err  = lib_L2_config_SRAM(l2_SRAM_size_orig);      
      }
    }  
    if(l2_cfg_err != LIB_CACHE_SUCCESS) {
      return(TICBLAS_ERROR_MEMRECFG);
    }   

#ifdef TI_CBLAS_DEBUG 
    printf("Reconfigured L1D SRAM size is: %d\n", lib_get_L1D_SRAM_size());
    printf("Reconfigured L2 SRAM size is: %d\n", lib_get_L2_SRAM_size());
#endif
    
    return(TICBLAS_SUCCESS);            
} /* blas_mem_reconfig */

/* Nothing after this line */
