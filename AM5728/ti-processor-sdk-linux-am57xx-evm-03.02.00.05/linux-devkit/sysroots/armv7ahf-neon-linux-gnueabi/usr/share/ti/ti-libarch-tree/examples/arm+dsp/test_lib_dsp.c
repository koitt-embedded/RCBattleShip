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
#include <stdio.h>
#include <ti/libarch/libarch.h>

#define TEST_MEM_NOERR 0
#define TEST_MEM_ERROR 1

extern void test_GetSizes(size_t *smem_size_vfast, size_t *smem_size_fast, 
                          size_t *smem_size_med,   size_t *smem_size_slow);
extern int test_Init(void * svfast_buf_base, size_t svfast_buf_size,
                     void * sfast_buf_base,  size_t sfast_buf_size,
                     void * smem_buf_base,   size_t smem_buf_size,
                     void * sslow_buf_base,  size_t sslow_buf_size);

/*==============================================================================
 * This function prepares memory for the processing function 
 *============================================================================*/
int lib_config_memory(void *msmc_mem_base,  size_t msmc_mem_size, 
                       void *ddr_mem_base,   size_t ddr_mem_size,   
                       size_t *l1D_SRAM_size_orig, size_t *l2_SRAM_size_orig)
{
    size_t smem_size_vfast, smem_size_fast, smem_size_med, smem_size_slow;
    void *l1d_SRAM_ptr, *l2_SRAM_ptr;
    int l1d_cfg_err, l2_cfg_err;

    printf("DSP: Check memory requirement and configure L1D/L2 if necessary.\n");
    
    /* First, verify the provided/available memory meet requirements */
    test_GetSizes(&smem_size_vfast, &smem_size_fast, &smem_size_med, &smem_size_slow);

    printf("Required very fast memory size is %d, fast memory size is %d, medium memory size is %d, slow memory size is %d\n",
           smem_size_vfast, smem_size_fast, smem_size_med, smem_size_slow);
    
    printf("Available very fast memory size is %d, fast memory size is %d, medium memory size is %d, slow memory size is %d\n",
           lib_get_L1D_total_size(), lib_get_L2_total_size(), msmc_mem_size, ddr_mem_size);

    *l1D_SRAM_size_orig = lib_get_L1D_SRAM_size();   /* get current L1D SRAM size */ 
    printf("Original L1D SRAM size is %d.\n", *l1D_SRAM_size_orig);
    
    *l2_SRAM_size_orig  = lib_get_L2_SRAM_size();    /* get current L2 SRAM size */
    printf("Original L2 SRAM size is %d.\n", *l2_SRAM_size_orig);
    
    if(  (smem_size_vfast> lib_get_L1D_total_size()) /* available L1D SRAM    */
       ||(smem_size_fast > lib_get_L2_total_size())  /* available L2 SRAM     */
       ||(smem_size_med  > msmc_mem_size)            /* provided MSMC memory  */              
       ||(smem_size_slow > ddr_mem_size)             /* provided DDR memory   */
      ) {                                                            
        printf("No enough memory!\n");
        return(TEST_MEM_ERROR);
    }
    
    /* Configure L1D if necessary */
    l1d_cfg_err = LIB_CACHE_SUCCESS;
    if(*l1D_SRAM_size_orig <= smem_size_vfast) {     /* configure L1D if needs more SRAM */
      #pragma omp parallel     
      {
        l1d_cfg_err = lib_L1D_config_SRAM(smem_size_vfast);
      }
    }  

    /* Configure L2 if necessary */
    l2_cfg_err = LIB_CACHE_SUCCESS;
    if(*l2_SRAM_size_orig <= smem_size_fast) {       /* configure L2 if needs more SRAM */
      #pragma omp parallel     
      { 
        l2_cfg_err  = lib_L2_config_SRAM(smem_size_fast);    
      }
    }
    
    if(l1d_cfg_err || l2_cfg_err) {
      printf("Error in configuring L1D and L2!\n.");
      return(TEST_MEM_ERROR);        
    }

    printf("Configured L1D SRAM size is %d.\n", lib_get_L1D_SRAM_size());
    printf("Configured L2  SRAM size is %d.\n", lib_get_L2_SRAM_size());
    
    /* get L1D and L2 SRAM base address */
    l1d_SRAM_ptr = lib_get_L1D_SRAM_base();  
    l2_SRAM_ptr  = lib_get_L2_SRAM_base();   

    printf("L1D SRAM base address is 0x%x.\n", (unsigned int)l1d_SRAM_ptr);
    printf("L2  SRAM base address is 0x%x.\n", (unsigned int) l2_SRAM_ptr);
    
    /* pass allocated memories for heap initialization */
    if(test_Init(l1d_SRAM_ptr,  smem_size_vfast,
                 l2_SRAM_ptr,   smem_size_fast,
                 msmc_mem_base, smem_size_med, 
                 ddr_mem_base,  smem_size_slow)) {
      return(TEST_MEM_ERROR);        
    }

    return(TEST_MEM_NOERR);            
} /* lib_config_memory */


/*==============================================================================
 * This function reconfigures L1D and L2 after processing is finished
 *============================================================================*/
int lib_reconfig_memory(size_t l1D_SRAM_size_orig, size_t l2_SRAM_size_orig)
{
    int l1d_cfg_err, l2_cfg_err;

    printf("Reconfiguring L1D and L2.\n");
    printf("L1D total size is %d.\n", lib_get_L1D_total_size());
    printf("Original L1D SRAM size is %d.\n", l1D_SRAM_size_orig);   
    printf("Original L2  SRAM size is %d.\n",  l2_SRAM_size_orig);
    
    /* configure L1D back */    
    l1d_cfg_err = LIB_CACHE_SUCCESS;
    if(l1D_SRAM_size_orig!=lib_get_L1D_SRAM_size()) {
      #pragma omp parallel     
      {
        l1d_cfg_err = lib_L1D_config_SRAM(l1D_SRAM_size_orig);    
        //__cache_l1d_all();
      }
    }     

    l2_cfg_err = LIB_CACHE_SUCCESS;
    if(l2_SRAM_size_orig <= lib_get_L2_SRAM_size()) {
      #pragma omp parallel     
      {
        l2_cfg_err  = lib_L2_config_SRAM(l2_SRAM_size_orig);      
      }
    }
    
    /* configure L1D and L2 back */    
    if(l1d_cfg_err || l2_cfg_err) {
      printf("Error in reconfiguring L1D and L2!\n.");
      return(TEST_MEM_ERROR);
    }   

    printf("Reconfigured L1D SRAM size is %d.\n", lib_get_L1D_SRAM_size());
    printf("Reconfigured L1D total size is %d.\n", lib_get_L1D_total_size());
    printf("Reconfigured L2  SRAM size is %d.\n", lib_get_L2_SRAM_size());
    
    return(TEST_MEM_NOERR);            
} /* lib_reconfig_memory */

/*==============================================================================
 * This function prints out the L2 SRAM start address which is passed from host
 * through OpenCL.
 *============================================================================*/
void print_l2_start(char * l2_buf)
{
    printf("Function print_l2_start: L2 SRAM start address is 0x%x.\n", (unsigned int)l2_buf);
}

/* Nothing past this point */
