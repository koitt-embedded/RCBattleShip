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
#include "ti_cblas_acc.h"
#include "../../ticblas/ticblas.h"
#include <pthread.h>

#ifdef TI_CBLAS_FAT_BINARY
#include "ti_cblas_kernel.dsp_h"
#endif

/*==============================================================================
 * This file contains functions of the ARM wrapper of ARM+DSP CBLAS library.
 * It has the initialization and finalization routines. 
 *
 * The standard CBLAS API for each BLAS function can be found in file 
 * ti_cblas_cblas_<func_name>.c, such as ti_cblas_cblas_dgemm.c for DGEMM. 
 *============================================================================*/

#define TI_CBLAS_INITFINI_SUCCESS   0
#define TI_CBLAS_INITFINI_OCL_ERR   1
#define TI_CBLAS_INITFINI_BLI_ERR   2

/* Global variables */
Context*             ti_cblas_ocl_context = NULL;
std::vector<Device>* ti_cblas_ocl_devices = NULL;
CommandQueue*        ti_cblas_ocl_Q       = NULL;
Program::Binaries*   ti_cblas_ocl_binary  = NULL;
Program*             ti_cblas_ocl_program = NULL;

int ti_cblas_init_done = 0;       /* flag to check if init is complete */
int ti_cblas_disable_debug = 0;   /* runtime toggle to disable debug */
int ti_cblas_offload = TI_CBLAS_OFFLOAD_SIZE;  
int TI_CBLAS_L1_OFFLOAD = TI_CBLAS_OFFLOAD_NONE;
int TI_CBLAS_L2_OFFLOAD = TI_CBLAS_OFFLOAD_NONE;
int TI_CBLAS_L3_OFFLOAD = TI_CBLAS_OFFLOAD_NONE;

pthread_cond_t   CV;
pthread_mutex_t  MUTEX;

/*============================================================================
 * Function purpose: report error encoutered in ARM wrapper code.
 *============================================================================*/
void ti_cblas_error(const char* msg, int code)
{
  fprintf(stderr, "TI CBLAS wrapper ERROR: (%s,%d)\n", msg, code);
}

/*============================================================================
 * Function purpose: initialize BLIS on both ARM and DSP
 *============================================================================*/
int ti_blis_init(void)
{
    int r_val = TI_CBLAS_INITFINI_SUCCESS;
    
    /* Initialize BLIS on ARM */
    TI_CBLAS_DEBUG_PRINT("Initializing BLIS on ARM...\n");   
    bli_init();    
    TI_CBLAS_DEBUG_PRINT("BLIS initialized on ARM.\n");

    /* Initialize BLIS on DSP by offloading bli_init() on DSP */
    TI_CBLAS_DEBUG_PRINT("Initializing BLIS on DSP...\n");   
    Event e;
    Kernel* __K;

    __K =  ti_cblas_get_kernel("ocl_bli_init");
    try
    {
        int err_code;        
        Buffer buf_err(*ti_cblas_ocl_context, CL_MEM_READ_WRITE|CL_MEM_USE_HOST_PTR, sizeof(int), &err_code);
        __K->setArg(0, buf_err);

        ti_cblas_ocl_Q->enqueueTask(*__K, 0, &e);
        e.wait();

        if(err_code != TICBLAS_SUCCESS) {
          TI_CBLAS_DEBUG_PRINT("Error in offloaded ocl_bli_init with error code %d!\n", err_code);
          r_val = TI_CBLAS_INITFINI_BLI_ERR;
        }
        
        ti_cblas_delete_kernel(__K);
        TI_CBLAS_DEBUG_PRINT("BLIS DSP initialization finished.\n");        
    }

    catch (Error err)
    {
        ti_cblas_delete_kernel(__K);
        ti_cblas_error(err.what(),err.err());
        r_val = TI_CBLAS_INITFINI_OCL_ERR;
    }

    return r_val;
} // ti_blis_init 


/*============================================================================
 * Function purpose: initialize and prepare for CBLAS calls:
 *    - parse the environment variables 
 *    - initialize OpenCL 
 *    - initialize BLIS
 *
 * Note: this function is invoked exactly once on startup, when any CBLAS function
 *       is called the first time. 
 *============================================================================*/
void ti_cblas_init(void)
{
#pragma omp critical (ti_cblas_init_critical)
  {
    /* Add code for interception */
#ifdef TI_CBLAS_DEBUG
      char *no_debug_env = getenv("TI_CBLAS_NO_DEBUG");
      if (no_debug_env) {
        if (atoi(no_debug_env) > 0) {
          ti_cblas_disable_debug = 1;
        }
      }
#endif
    
      TI_CBLAS_DEBUG_PRINT("ti_cblas_init: Initializing OpenCL on first use..\n");

      TI_CBLAS_PROFILE_START();
    
      /* check environment variables */
      const char *offload_env = getenv("TI_CBLAS_OFFLOAD");
      if (!offload_env)  { 
        TI_CBLAS_DEBUG_PRINT("Using build time default for offload: TI_CBLAS_OFFLOAD=%s\n", TI_CBLAS_OFFLOAD_DEF);
        offload_env = TI_CBLAS_OFFLOAD_DEF;
      }
      else {
        TI_CBLAS_DEBUG_PRINT("Using runtime override for offloads: TI_CBLAS_OFFLOAD=%s\n", offload_env);
      }
      if (offload_env) {
        ti_cblas_offload = atoi(offload_env);
        if (ti_cblas_offload == TI_CBLAS_OFFLOAD_NONE) {
            TI_CBLAS_DEBUG_PRINT("Disabling all offloads\n");
        }
      }
  
      /* 3-digit value: 012
       * Left-most digit => L1 (0)
       * Middle-digit    => L2 (1)
       * Right-most      => L3 (2)
       */
      TI_CBLAS_L1_OFFLOAD = ti_cblas_offload / 100;
      int tmp_offload = ti_cblas_offload % 100;
      TI_CBLAS_L2_OFFLOAD = tmp_offload / 10;
      TI_CBLAS_L3_OFFLOAD = tmp_offload % 10;
      TI_CBLAS_DEBUG_PRINT("BLAS Offload values: L1=%d, L2=%d, L3=%d\n",  
      TI_CBLAS_L1_OFFLOAD, TI_CBLAS_L2_OFFLOAD, TI_CBLAS_L3_OFFLOAD);
      if ((TI_CBLAS_L1_OFFLOAD == TI_CBLAS_OFFLOAD_SIZE)) {
        TI_CBLAS_ERROR_EXIT("Size-based offload NOT supported for BLAS Level 1 yet.\n");
      }
      if ((TI_CBLAS_L2_OFFLOAD == TI_CBLAS_OFFLOAD_SIZE)) {
        TI_CBLAS_ERROR_EXIT("Size-based offload NOT supported for BLAS Level 2 yet.\n");
      }

      /*------------------------------------------------------------------------
       * Read the offline compiled kernel module
       *-----------------------------------------------------------------------*/
      TI_CBLAS_DEBUG_PRINT("Reading Kernels\n");
      const unsigned char* bin;
#ifdef TI_CBLAS_FAT_BINARY
      bin = (unsigned char *)ti_cblas_kernel_dsp_bin;
      const size_t bin_length = ti_cblas_kernel_dsp_bin_len;
#else
      const char binary[] = "./ti_cblas_kernel.out";
      unsigned int bin_length;
      bin_length = ocl_read_binary(binary, (char*&)bin); 
#endif /* FAT_BINARY */
    
      /* OpenCL init */
      TI_CBLAS_DEBUG_PRINT("Initializing OpenCL\n");
      ti_cblas_ocl_context = new Context(CL_DEVICE_TYPE_ACCELERATOR);
      ti_cblas_ocl_devices = new std::vector<Device> (ti_cblas_ocl_context->getInfo<CL_CONTEXT_DEVICES>());
      ti_cblas_ocl_binary = new Program::Binaries(1, std::make_pair(bin, bin_length));
      ti_cblas_ocl_program = new Program(*ti_cblas_ocl_context, *ti_cblas_ocl_devices, *ti_cblas_ocl_binary);
      ti_cblas_ocl_program->build(*ti_cblas_ocl_devices);
      ti_cblas_ocl_Q = new CommandQueue(*ti_cblas_ocl_context, ti_cblas_ocl_devices[0][0], CL_QUEUE_PROFILING_ENABLE);
    
#ifndef TI_CBLAS_FAT_BINARY
      delete [] bin;
#endif /* FAT_BINARY */
      
      TI_CBLAS_DEBUG_PRINT("OpenCL initialized\n");

      /* Initializing pthreads */
      TI_CBLAS_DEBUG_PRINT("Initializing Pthreads\n");
      pthread_cond_init (&CV, 0);
      pthread_mutex_init(&MUTEX, 0);
      TI_CBLAS_DEBUG_PRINT("Pthreads initialized\n");
      TI_CBLAS_DEBUG_PRINT("Initializing BLIS\n");
      if(ti_blis_init() == TI_CBLAS_INITFINI_SUCCESS) {
        TI_CBLAS_DEBUG_PRINT("BLIS initialized\n");\
      }
      else {
        TI_CBLAS_DEBUG_PRINT("BLIS NOT initialized!\n");\
      }
      
      /* Register auto finalization to be called when program exits */
      atexit(ti_cblas_auto_finalize);

      TI_CBLAS_PROFILE_REPORT("Initialization took %8.2f us\n", (float) clock_diff);
      ti_cblas_init_done = 1;
      TI_CBLAS_DEBUG_PRINT("ti_cblas_init: Finished initialization\n");
      
  } // End of critical section

  return;
} //ti_cblas_init

/*============================================================================
 * Function purpose: finalize BLIS on both ARM and DSP
 *============================================================================*/
int ti_blis_finalize(void)
{
    int r_val = TI_CBLAS_INITFINI_SUCCESS;
    
    /* Finalize BLIS on ARM */
    TI_CBLAS_DEBUG_PRINT("Finalizing BLIS on ARM...\n");
    bli_finalize();
    TI_CBLAS_DEBUG_PRINT("BLIS finalized on ARM.\n");

    /* Finalize BLIS on DSP */
    Event e;
    Kernel* __K;

    __K =  ti_cblas_get_kernel("ocl_bli_finalize");

    TI_CBLAS_DEBUG_PRINT("Finalizing BLIS on DSP...\n");
    int err_code;        
    Buffer buf_err(*ti_cblas_ocl_context, CL_MEM_READ_WRITE|CL_MEM_USE_HOST_PTR, sizeof(int), &err_code);
    __K->setArg(0, buf_err);
    
    try
    {
        ti_cblas_ocl_Q->enqueueTask(*__K, 0, &e);
        e.wait();

        if(err_code != TICBLAS_SUCCESS) {
          TI_CBLAS_DEBUG_PRINT("Error in offloaded ocl_bli_finalize with error code %d!\n", err_code);
          r_val = TI_CBLAS_INITFINI_BLI_ERR;
        }
        
        ti_cblas_delete_kernel(__K);
    }

    catch (Error err)
    {
        ti_cblas_error(err.what(),err.err());
        r_val = TI_CBLAS_INITFINI_OCL_ERR;
    }

    return r_val;
} // ti_blis_finalize 

/*============================================================================
 * Function purpose: finalize after all CBLAS calls:
 *    - finalize BLIS
 *    - delete OpenCL context
 *
 * Note: this function is invoked exactly once on program exit.
 *============================================================================*/
int ti_cblas_finalize(void)
{
    /* If ti_cblas_init_done is equal to 0,
     * then we know that ti_cblas_init was not called,
     * and so we can return early.
     */
    if(ti_cblas_init_done == 0) {
        return TI_CBLAS_INITFINI_SUCCESS;
    }

    int r_val = ti_blis_finalize();
    /*Using same name as ti_cblas_init critical region. See notes in bli_init*/
#pragma omp critical (ti_cblas_init_critical)
    {
        // Destroy Pthread
        pthread_mutex_destroy(&MUTEX);
        pthread_cond_destroy (&CV);

        //destroy Command queue, program, devices and context.
        if(ti_cblas_ocl_Q != NULL)
        {
            delete(ti_cblas_ocl_Q);
            ti_cblas_ocl_Q = NULL;
        }
        if(ti_cblas_ocl_program != NULL)
        {
            delete(ti_cblas_ocl_program);
            ti_cblas_ocl_program = NULL;
        }
        if(ti_cblas_ocl_binary != NULL)
        {
            delete(ti_cblas_ocl_binary);
            ti_cblas_ocl_binary = NULL;
        }
        if(ti_cblas_ocl_devices != NULL)
        {
            delete(ti_cblas_ocl_devices);
            ti_cblas_ocl_devices = NULL;
        }
        if(ti_cblas_ocl_context != NULL)
        {
            delete(ti_cblas_ocl_context);
            ti_cblas_ocl_context = NULL;
        }
    }
    
    return r_val;
} // ti_cblas_finalize


/*============================================================================
 * Function purpose: auto-finalize on program exit.
 *============================================================================*/
void ti_cblas_auto_finalize(void)
{
    int r_val;

    r_val = ti_cblas_finalize();
    if (r_val != TI_CBLAS_INITFINI_SUCCESS)
    {
        fprintf(stderr, "Error: ti_cblas_finalize failed with error code %d!\n", r_val);
    }
} //ti_cblas_auto_finalize


/*============================================================================
 * Function purpose: free previously allocated MSMC memory
 *============================================================================*/
void ti_cblas_mem_free(void *ptr)
{
    pthread_mutex_lock(&MUTEX);
    __free_msmc(ptr);
    pthread_cond_broadcast(&CV);
    pthread_mutex_unlock(&MUTEX);

}

/*============================================================================
 * Function purpose: allocate MSMC memory
 *============================================================================*/
void *ti_cblas_mem_alloc(size_t size)
{
    void *ptr;
    pthread_mutex_lock(&MUTEX);
    
    /*-------------------------------------------------------------------------
     * Loop in case of false signal after broadcast.
     *------------------------------------------------------------------------*/
    while ((ptr = __malloc_msmc(size)) == 0)
    {
        pthread_cond_wait(&CV, &MUTEX);
    }

    pthread_mutex_unlock(&MUTEX);
    
    return ptr;
} //ti_cblas_mem_alloc


/*============================================================================
 * Function purpose: create an OpenCL kernel
 *============================================================================*/
Kernel *ti_cblas_get_kernel(const char *fname)
{
    Kernel* __K;
    
    __K = new Kernel(*ti_cblas_ocl_program, fname);

    return __K;
}

/*============================================================================
 * Function purpose: delete an OpenCL kernel
 *============================================================================*/
int ti_cblas_delete_kernel(Kernel* K)
{
    if(K != NULL)
    {
        delete(K);
        K=NULL;
    }
    
    return 0;
}

/* Nothing after this line */
