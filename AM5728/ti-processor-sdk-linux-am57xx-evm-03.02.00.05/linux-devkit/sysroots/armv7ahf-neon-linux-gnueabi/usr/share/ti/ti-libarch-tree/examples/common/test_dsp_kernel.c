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


/*
 * This file shows an example of a DSP library that uses the library framework API. 
 */

/* Size requirement of each of the 4 memory types */
#ifdef SOC_K2H
  #define TEST_MEM_SIZE_VFAST (28*1024UL) 
  #define TEST_MEM_SIZE_FAST  (512*1024UL)
  #define TEST_MEM_SIZE_MED   (4608*1024UL)  //4.5MB
  #define TEST_MEM_SIZE_SLOW  (10240*1024UL) //10MB
#endif
#ifdef SOC_AM572x
    #define TEST_MEM_SIZE_VFAST (28*1024UL)
    #define TEST_MEM_SIZE_FAST  (20*1024UL)
    #define TEST_MEM_SIZE_MED   (256*1024UL)  //256KB
    #define TEST_MEM_SIZE_SLOW  (1024*1024UL) //1MB
#endif
#ifdef SOC_C6678
    #define TEST_MEM_SIZE_VFAST (28*1024UL) 
    #define TEST_MEM_SIZE_FAST  (20*1024UL)
    #define TEST_MEM_SIZE_MED   (2048*1024UL)   //2MB 
    #define TEST_MEM_SIZE_SLOW  (10240*1024UL)  //10MB        
#endif
#define LIBFW_TEST_INIT_NOERR 0
#define LIBFW_TEST_INIT_ERROR 1

#define LIBFW_TEST_DATA_SIZE  256

/* Define memory descriptors for memory management */
lib_memdscr_t test_vfast_buf;
lib_memdscr_t test_fast_buf;
lib_memdscr_t test_med_buf;
lib_memdscr_t test_slow_buf;

/* Define a memory descriptor array */
lib_memdscr_t * test_memdscr_tab[LIB_MEMTYPE_N] = {
    &test_vfast_buf,
    &test_fast_buf,
    &test_med_buf,
    &test_slow_buf
};

/*==============================================================================
 * This function returns the address of the memory descriptor array
 *============================================================================*/
void * testGetMemHandle()
{
    return((void *)&test_memdscr_tab[0]);
} /* testGetMemHandle */

/*==============================================================================
 * Example of library memory requirement query function
 *   It returns the size requirement of each of the 4 memory types defined in 
 *   the library framework. 
 *============================================================================*/
void test_GetSizes(size_t *smem_size_vfast, size_t *smem_size_fast, 
                   size_t *smem_size_med,   size_t *smem_size_slow)
{
    *smem_size_vfast = TEST_MEM_SIZE_VFAST;  // very fast scratch memory
    *smem_size_fast  = TEST_MEM_SIZE_FAST;   // fast scratch memory
    *smem_size_med   = TEST_MEM_SIZE_MED;    // medium speed scratch memory
    *smem_size_slow  = TEST_MEM_SIZE_SLOW;   // slow scratch memory
} /* test_GetSizes */

/*==============================================================================
 * Example of library initialization function
 *   It performs necessary initialization through library framework API in order
 *   to do memory allocations.  
 *============================================================================*/
int test_Init(void * svfast_buf_base, size_t svfast_buf_size,
              void * sfast_buf_base,  size_t sfast_buf_size,
              void * smed_buf_base,   size_t smed_buf_size,
              void * sslow_buf_base,  size_t sslow_buf_size)
{
    lib_memdscr_t **test_mem_handle = testGetMemHandle();

    /* Verify supplied memories meet requirements */    
    if(  (svfast_buf_base!=NULL) && (svfast_buf_size>=TEST_MEM_SIZE_VFAST)
       &&(sfast_buf_base !=NULL) && (sfast_buf_size >=TEST_MEM_SIZE_FAST)
       &&(smed_buf_base  !=NULL) && (smed_buf_size  >=TEST_MEM_SIZE_MED) 
       &&(sslow_buf_base !=NULL) && (sslow_buf_size >=TEST_MEM_SIZE_MED) 
      ) {
        lib_smem_vinit(test_mem_handle, svfast_buf_base, svfast_buf_size);
        lib_smem_finit(test_mem_handle, sfast_buf_base,  sfast_buf_size);
        lib_smem_minit(test_mem_handle, smed_buf_base,   smed_buf_size);
        lib_smem_sinit(test_mem_handle, sslow_buf_base,  sslow_buf_size);       
        
        return(LIBFW_TEST_INIT_NOERR);
    }
    else {
        return(LIBFW_TEST_INIT_ERROR);
    }
} /* test_Init */


/*==============================================================================
 * Example of library processing function
 *   It uses library framework API to do:
 *      - scratch memory allocations
 *      - memory transfers
 *============================================================================*/
void lib_dsp_func(const double *in1, const double *in2, double *out,
                   int num_elements)
{
    double *vfast_buf, *fast_buf1, *fast_buf2, *med_buf, *slow_buf;
    void *test_mem_handle;
    lib_emt_Handle test_emt_handle;
    int i;
  
    printf("DSP library kernel for LibArch testing:\n");
  
    /* Use memory allocation API to allocate memories. This can also be done in 
       test_Init, but that would require usage of global variables.  */
    test_mem_handle = testGetMemHandle();
    vfast_buf = (double *)lib_smem_valloc(test_mem_handle, num_elements*sizeof(double), 3);
    fast_buf1 = (double *)lib_smem_falloc(test_mem_handle, num_elements*sizeof(double), 3);
    med_buf   = (double *)lib_smem_malloc(test_mem_handle, num_elements*sizeof(double), 3);
    slow_buf  = (double *)lib_smem_salloc(test_mem_handle, num_elements*sizeof(double), 3);
  
    if(vfast_buf==NULL || fast_buf1==NULL || med_buf==NULL || slow_buf==NULL) {
        printf("Scratch (shared) heap allocation error!\n");
        return;
    }
  
    /* Use external memory transfer API */
    if((test_emt_handle=lib_emt_alloc(1))==NULL) {
        printf("External memory transfer handle allocation error!\n");
        return;    
    } 
  
	printf("DSP library kernel: Transferring input 1 to very fast memory buffer (L1D).\n");
    if(lib_emt_copy1D1D(test_emt_handle, (void *)in1, (void *)vfast_buf, 
                        num_elements*sizeof(double))) {
        printf("External memory transfer error!\n");
        return;    
    }
  
    lib_emt_wait(test_emt_handle);
  
	printf("DSP library kernel: Transferring input 2 to fast memory buffer (L2).\n");
    if(lib_emt_copy1D1D(test_emt_handle, (void *)in2, (void *)fast_buf1, 
                         num_elements*sizeof(double))){
        printf("External memory transfer error!\n");
        return;    
    }
  
    lib_emt_wait(test_emt_handle);
  
    /*
    for(i=0;i<10;i++)
    {
        printf("Input 1: %e, Input 2: %e\n", vfast_buf[i],fast_buf1[i]);
    }
    */  

    /* Process input data */
	printf("DSP library kernel: Processing data in very fast memory.\n");
    for(i=0;i<num_elements;i++){
        vfast_buf[i] += fast_buf1[i];
    }
  
    /* Allocate another block of memory */
    fast_buf2 = lib_smem_falloc(test_mem_handle, num_elements*sizeof(double), 3);
  
    /* Use internal memory transfer API */
	printf("DSP library kernel: Transferring data from very fast memory to fast memory.\n");
    lib_imt_copy((void *)vfast_buf, (void *)fast_buf2, num_elements*sizeof(double));
    lib_imt_wait();
    /*
    for(i=0;i<10;i++)
    {
        printf("Output: %e\n", fast_buf2[i]);
    }
    */

	printf("DSP library kernel: Transferring data from fast memory to output buffer.\n");
    if(lib_emt_copy1D1D(test_emt_handle, (void *)fast_buf2, (void *)out, 
                         num_elements*sizeof(double))) {
      printf("Memory transfer to output error!\n");
      return;    
    }
  
    lib_emt_wait(test_emt_handle);
	
	printf("DSP library kernel finished.\n");
	
} /* lib_dsp_func */      

/* Nothing after this line */
