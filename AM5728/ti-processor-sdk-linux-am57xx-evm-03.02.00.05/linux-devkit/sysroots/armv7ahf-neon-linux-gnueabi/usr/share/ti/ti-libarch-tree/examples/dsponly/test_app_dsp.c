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
/*==============================================================================
  This file shows an example of using libarch in TI RTOS environment. 
===============================================================================*/ 
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include "omp.h"
#include <ti/libarch/libarch.h>
#include "../common/test_dsp_kernel.h"

#define TEST_MEM_NOERR 0
#define TEST_MEM_ERROR 1
#define NUM_MAX_LINKED_TRANSER 1

#define TEST_DATA_SIZE (1024)        //1K data points
#ifdef SOC_C6678
#define L2_SCRATCH_SIZE    (20*1024UL)
#define MSMC_SCRATCH_SIZE  (2*1024*1024UL)   //2M Bytes
#define DDR_SCRATCH_SIZE   (10*1024*1024UL)  //10M Bytes
#endif

#ifdef SOC_K2H
#define L2_SCRATCH_SIZE    (512*1024UL)
#define MSMC_SCRATCH_SIZE  (4608*1024UL)   //4.5M Bytes
#define DDR_SCRATCH_SIZE   (10240*1024UL)  //10M Bytes
#endif

#pragma DATA_SECTION(l2_scratch_buf, ".IRAM_DATA")
char l2_scratch_buf[L2_SCRATCH_SIZE];

#pragma DATA_SECTION(msmc_scratch_buf, ".MSMC_DATA")
char msmc_scratch_buf[MSMC_SCRATCH_SIZE];

#pragma DATA_SECTION(ddr_scratch_buf, ".DDR_DATA")
char ddr_scratch_buf[DDR_SCRATCH_SIZE];

#pragma DATA_SECTION(l2_data_buf, ".IRAM_DATA")
char l2_data_buf[TEST_DATA_SIZE*sizeof(double)];

#pragma DATA_SECTION(ddr_data_buf, ".DDR_DATA")
char ddr_data_buf[TEST_DATA_SIZE*sizeof(double)];

#pragma DATA_SECTION(msmc_data_buf, ".MSMC_DATA");
char msmc_data_buf[TEST_DATA_SIZE*sizeof(double)];

void app_fill_buffers(double *buf1, double *buf2, int num_elements);
double app_err_check(double *in1, double *in2, double *out, int num_elements);
int app_config_memory( void *l2_mem_base, size_t l2_mem_size,
                    void *msmc_mem_base,  size_t msmc_mem_size, 
                       void *ddr_mem_base,   size_t ddr_mem_size,   
                       size_t *l1D_SRAM_size_orig);
void app_reconfig_memory(size_t l1D_SRAM_size_orig);
void app_init_dma();

/*==============================================================================
 * Application code on the host which calls library functions to process data.
 *============================================================================*/
int main()
{  
    size_t l1D_SRAM_size_orig;
    double err;
    int nthreads, tid;
 
    /* Verify OpenMP working properly */
    #pragma omp parallel private(nthreads, tid)
    {
        /* Obtain thread number */
        tid = omp_get_thread_num();
        printf("Hello World from thread = %d\n", tid);

        /* Only master thread does this */
        if (tid == 0) {
            nthreads = omp_get_num_threads();
            printf("Number of threads = %d\n", nthreads);
        }
    }  /* All threads join master thread and disband */
    
    printf("Allocating memory for input/output buffers.\n");   
    double *in1_ptr  = (double *)&l2_data_buf[0];
    double *in2_ptr  = (double *)&ddr_data_buf[0];
    double *out_ptr  = (double *)&msmc_data_buf[0];

    printf("Input buffer 1 address: 0x%08x.\n", (unsigned int)in1_ptr);
    printf("Input buffer 2 address: 0x%08x.\n", (unsigned int)in2_ptr);
    printf("Output buffer  address: 0x%08x.\n", (unsigned int)out_ptr);

    if(in1_ptr==NULL || in2_ptr==NULL || out_ptr==NULL) {
        printf("No memory!\n");
        exit(0);
    }
    else {
        printf("Memory allocated.\n");
    }

    /* Fill buffers with data for testing. */
    app_fill_buffers(in1_ptr, in2_ptr, TEST_DATA_SIZE);

    /* Allocate scratch memory for DSP acceleration */
    printf("Allocating scratch memory for library kernel.\n");   
    void *l2_ptr    = (void *)l2_scratch_buf;
    void *msmc_ptr  = (void *)msmc_scratch_buf;
    void *ddr_ptr   = (void *)ddr_scratch_buf;
    printf("L2 scratch starts from: 0x%08x.\n", (unsigned int)l2_ptr);
    printf("MSMC scratch starts from: 0x%08x.\n", (unsigned int)msmc_ptr);
    printf("DDR scratch starts from: 0x%08x.\n", (unsigned int)ddr_ptr);

    /* Configure memory before calling library kernel */
    printf("Configuring memory for library kernel...\n");   
    if(app_config_memory(l2_ptr, L2_SCRATCH_SIZE, msmc_ptr, MSMC_SCRATCH_SIZE, 
                         ddr_ptr, DDR_SCRATCH_SIZE, &l1D_SRAM_size_orig) != TEST_MEM_NOERR) {
        printf("Memory configuration failed.\n");
        exit (0);
    }
    else {
        printf("Memory configured.\n");   
    }
    
    app_init_dma();
    
    /* Pass input/output buffers to library function which sums two input buffers
       and return the sum in the output buffer. */
    lib_dsp_func(in1_ptr, in2_ptr, out_ptr, TEST_DATA_SIZE);

    /* Restore L1D and L2 original settings after the processing */
    app_reconfig_memory(l1D_SRAM_size_orig);
 
    err = app_err_check(in1_ptr, in2_ptr, out_ptr, TEST_DATA_SIZE);
 
    printf("Error checking.\n");
 
    if(err != 0) {
        printf("Failed!\n");
    }
    else {
        printf("Passed!\n");  
    }

    return(0);
}

/*==============================================================================
 * Filling memory with random data.
 *============================================================================*/
void app_fill_buffers(double *buf1, double *buf2, int num_elements)
{
    int i;

    for(i=0; i<num_elements; i++)
    {
        buf1[i] = (double)rand()/RAND_MAX;
        buf2[i] = (double)rand()/RAND_MAX;
    }
} /* app_fill_buffers */

/*==============================================================================
 * Error checking: check if buffer out is the sum of buffer in1 and buffer in2.
 *============================================================================*/
double app_err_check(double *in1, double *in2, double *out, int num_elements)
{
    double error = 0.0;
    int i;
  
    for(i=0; i<num_elements; i++)
    {
        error += out[i] - (in1[i]+in2[i]);
    }
   
    return(error);
} /* app_err_check */


/*==============================================================================
 * This function prepares memory for the processing function 
 *============================================================================*/
int app_config_memory( void *l2_mem_base,    size_t l2_mem_size,
                       void *msmc_mem_base,  size_t msmc_mem_size, 
                       void *ddr_mem_base,   size_t ddr_mem_size,   
                       size_t *l1D_SRAM_size_orig)
{
    size_t smem_size_vfast, smem_size_fast, smem_size_med, smem_size_slow;
    void *l1d_SRAM_ptr;
    int l1d_cfg_err;
    
    /* First, verify the provided/available memory meet requirements */
    printf("Check memory requirement and configure L1D if necessary.\n");
    test_GetSizes(&smem_size_vfast, &smem_size_fast, &smem_size_med, &smem_size_slow);

    if(  (smem_size_vfast> lib_get_L1D_total_size()) // available L1D SRAM 
       ||(smem_size_fast > l2_mem_size)              // provided L2 SRAM  
       ||(smem_size_med  > msmc_mem_size)            // provided MSMC memory                  
       ||(smem_size_slow > ddr_mem_size)             // provided DDR memory
      ) {                                                            
        return(TEST_MEM_ERROR);
    }
    
    /* Configure L1D if necessary */
    *l1D_SRAM_size_orig = lib_get_L1D_SRAM_size();  // get current L1D SRAM size 
    printf("Original L1D SRAM size is %d.\n", *l1D_SRAM_size_orig);
 
    l1d_cfg_err = LIB_CACHE_SUCCESS;
    if(*l1D_SRAM_size_orig <= smem_size_vfast) {    // configure L1D if needs more SRAM 
        #pragma omp parallel     
        {
            l1d_cfg_err = lib_L1D_config_SRAM(smem_size_vfast);  
            if(l1d_cfg_err) {
                printf("Error in configuring L1D on core %d!\n.", lib_get_coreID());
            }
            else {
                printf("Configured L1D SRAM size is %d on core %d.\n", lib_get_L1D_SRAM_size(), lib_get_coreID());
            }
        }
    }      
    
    /* get L1D SRAM base address */
    l1d_SRAM_ptr = lib_get_L1D_SRAM_base();  
    printf("L1D SRAM base address is 0x%x.\n", (unsigned int)l1d_SRAM_ptr);
 
    /* pass allocated memories for heap initialization */
    if(test_Init(l1d_SRAM_ptr,  smem_size_vfast,
                 l2_mem_base,   smem_size_fast,
                 msmc_mem_base, smem_size_med, 
                 ddr_mem_base,  smem_size_slow)) {
      return(TEST_MEM_ERROR);        
    }

    return(TEST_MEM_NOERR);            
} /* app_config_memory */

/*==============================================================================
 * This function reconfigures L1D after processing is finished
 *============================================================================*/
void app_reconfig_memory(size_t l1D_SRAM_size_orig)
{
    int l1d_cfg_err;
    
    /* configure L1D back */    
    l1d_cfg_err = LIB_CACHE_SUCCESS;
    if(l1D_SRAM_size_orig!=lib_get_L1D_SRAM_size()) {
        #pragma omp parallel     
        {
            l1d_cfg_err = lib_L1D_config_SRAM(l1D_SRAM_size_orig);    
            if(l1d_cfg_err) {
                printf("Error in reconfiguring L1D on core %d!\n.", lib_get_coreID());
            }
            else {
                printf("Reconfigured L1D SRAM size is %d on core %d.\n", lib_get_L1D_SRAM_size(), lib_get_coreID());
            }
        }
    }     
} /* app_reconfig_memory */

/*==============================================================================
 * This function initializes the EDMA on all cores
 *============================================================================*/
void app_init_dma()
{
    #pragma omp parallel
    {
        int status = lib_emt_init();
   
        if(status != LIB_EMT_SUCCESS) {
            printf("EDMA not initialized for core %d. Error code is %d.\n", lib_get_coreID(), status);
        }
        else {
            printf("EDMA initialized successfully for core %d.\n", lib_get_coreID());
        }
    }
}

/* Nothing past this point */
