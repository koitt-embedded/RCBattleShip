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
#include <omp.h>
#include <string.h>
#include <stdio.h>
#include <ti/libarch/libarch.h>
#include <ti/linalg/ticblas.h>
#include <ti/linalg/cblas.h>

/* use small memory model of BLAS */
#ifdef SOC_C6678
//#define BLAS_L2_BUF_SIZE   (220*1024UL)     /* 220KB SRAM is available in L2 for C6678 EVM */
#define BLAS_L2_BUF_SIZE   (256*1024UL)     /* 256KB SRAM is available in L2 for C6678 EVM */
#define BLAS_MSMC_BUF_SIZE (5*512*1024UL)   /* reserve 2.5MB for BLAS */    
#define BLAS_L3_DDR_SIZE   (5120)              
#else
#  if SOC_K2H
#    define BLAS_L2_BUF_SIZE   (768*1024UL)    
#    define BLAS_MSMC_BUF_SIZE (4608*1024UL)       /* 4.5MB */
#    define BLAS_L3_DDR_SIZE   (5120)              
#  else
#    error "Target undefined! Must be one of SOC_C6678 or SOC_K2H"
#  endif
#endif

size_t l1D_SRAM_size_orig, l2_SRAM_size_orig;

/* define MSMC memory for BLAS - can be shared with other libraries */
#pragma DATA_SECTION(blas_msmc_buf, ".blas_msmc")
#pragma DATA_ALIGN(blas_msmc_buf,32)
char blas_msmc_buf[BLAS_MSMC_BUF_SIZE];

/* define L2 memory for BLAS - can be shared with other libraries */
#pragma DATA_SECTION(blas_l2_buf, ".blas_l2")
#pragma DATA_ALIGN(blas_l2_buf,32)
char blas_l2_buf[BLAS_L2_BUF_SIZE];

char blas_ddr_buf[BLAS_L3_DDR_SIZE];


/*==============================================================================
 * This function configures and initializes memory for BLAS calls
 *============================================================================*/
int config_mem_for_ticblas(double *l2_buf,   size_t l2_buf_size, 
                           double *msmc_buf, size_t msmc_buf_size, 
                           double *ddr_buf,  size_t ddr_buf_size)
{
    size_t smem_size_vfast, smem_size_fast, smem_size_med, smem_size_slow;
    void *l1d_SRAM_ptr;
    int l1d_cfg_err;
    
    /* First, verify the provided/available memory meet requirements */
    tiCblasGetSizes(&smem_size_vfast, &smem_size_fast, &smem_size_med, &smem_size_slow);

    printf("BLAS memory requirements - vfast size: %d, fast size: %d, medium size: %d, slow size: %d.\n", smem_size_vfast, smem_size_fast, smem_size_med, smem_size_slow);
    
    if(  (smem_size_vfast> lib_get_L1D_total_size()) /* total available L1D  */
       ||(smem_size_fast > l2_buf_size)       /* provided L2 size   */
       ||(smem_size_med  > msmc_buf_size)     /* provided MSMC memory */                 
       ||(smem_size_slow > ddr_buf_size) 
      ) {                                                            
        printf("Provided memory is not enough for BLAS!\n");
        exit(0);
    }
    
    /* Configure L1D if necessary */
    l1D_SRAM_size_orig = lib_get_L1D_SRAM_size(); /* get current L1D SRAM size  */
    l1d_cfg_err = LIB_CACHE_SUCCESS;
    printf("Original L1D SRAM size is: %d\n", l1D_SRAM_size_orig);
    printf("Required L1D SRAM size is: %d\n", smem_size_vfast);
    if(l1D_SRAM_size_orig < smem_size_vfast) {    /* configure L1D if needs more SRAM */
      #pragma omp parallel
      {
        l1d_cfg_err = lib_L1D_config_SRAM(smem_size_vfast);  
        if(l1d_cfg_err) {
          printf("L1D configuration fails on core %d!\n", lib_get_coreID());
          exit(1);
        }
      }
    }  

    #pragma omp parallel
    {
      printf("New L1D SRAM size on core %d is: %d\n", lib_get_coreID(), lib_get_L1D_SRAM_size());
    }

    /* get L1D SRAM base address */
    l1d_SRAM_ptr = lib_get_L1D_SRAM_base();  
    printf("L1D SRAM base address is 0x%x.\n", (unsigned int)l1d_SRAM_ptr);
  
    /* pass allocated memories for heap initialization */
    return(tiCblasInit(l1d_SRAM_ptr,  lib_get_L1D_SRAM_size(),
                       l2_buf,        l2_buf_size,
                       msmc_buf,      msmc_buf_size, 
                       ddr_buf,       ddr_buf_size));
} /* config_mem_for_ticblas */

/*==============================================================================
 * This function reconfigures L1D after processing is finished
 *============================================================================*/
int reconfig_mem_after_ticblas()
{
    int l1d_cfg_err;
    
    /* configure L1D back */    
    l1d_cfg_err = LIB_CACHE_SUCCESS;
    if(l1D_SRAM_size_orig!=lib_get_L1D_SRAM_size()) {
      #pragma omp parallel
      {
        l1d_cfg_err = lib_L1D_config_SRAM(l1D_SRAM_size_orig);    
        if(l1d_cfg_err) {
          printf("L1D reconfiguration fails on core %d!\n", lib_get_coreID());
          exit(2);
        }
      }
    }

    printf("L1D SRAM size reconfigured to: %d\n", lib_get_L1D_SRAM_size());
    
    return(TICBLAS_SUCCESS);            
} /* reconfig_mem_after_ticblas */


/*==============================================================================
 * This function prepares for calling TI's CBLAS
 *============================================================================*/
void prepare_for_ticblas()
{
  int err;

  printf("L2 SRAM size is %d, total L2 size is %d.\n", lib_get_L2_SRAM_size(), lib_get_L2_total_size());
  
  /* Call TI CBLAS API to creat new CBLAS instance */
  tiCblasNew();

  /* Configure memory for TI CBLAS if necessary */
  err = config_mem_for_ticblas((double *)blas_l2_buf,   (size_t)BLAS_L2_BUF_SIZE,
                               (double *)blas_msmc_buf, (size_t)BLAS_MSMC_BUF_SIZE, 
                               (double *)blas_ddr_buf,  (size_t)BLAS_L3_DDR_SIZE);
    
  if(err) {
    printf("Memory configuration for CBLAS failed with error code %d.\n", err);
    exit (0);
  }   
}

void cleanup_after_ticblas()
{
  /* Reconfigure memory if necessary */
  if(reconfig_mem_after_ticblas() == TICBLAS_SUCCESS) {
    printf("Memory reconfiguration after BLAS call finished.\n");
  }

  tiCblasDelete();
}
