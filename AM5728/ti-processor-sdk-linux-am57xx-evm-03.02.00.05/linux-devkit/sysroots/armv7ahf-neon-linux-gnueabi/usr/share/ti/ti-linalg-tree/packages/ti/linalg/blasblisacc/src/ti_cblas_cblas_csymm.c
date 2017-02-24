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

#ifdef __cplusplus
extern "C" { 
#endif
    void __real_cblas_csymm(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const int M, const int N, const void *alpha, const void *A, const int lda, const void *B, const int ldb, const void *beta, void *C, const int ldc) ; 

#ifdef __cplusplus
}
extern "C"
#endif
void cblas_csymm(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const int M, const int N, const void *alpha, const void *A, const int lda, const void *B, const int ldb, const void *beta, void *C, const int ldc)
{

	/* Do an init on first use */
	if (!ti_cblas_init_done) ti_cblas_init();
	TI_CBLAS_DEBUG_PRINT("Intercepted call to %s\n", "cblas_csymm");

    TI_CBLAS_PROFILE_START();
	/* Dynamic condtional offload to ARM */
    if ((TI_CBLAS_L3_OFFLOAD == TI_CBLAS_OFFLOAD_NONE) || ((TI_CBLAS_L3_OFFLOAD == TI_CBLAS_OFFLOAD_SIZE) && (!csymm_offload_dsp(Order,Side,M,N)))) { 
	TI_CBLAS_DEBUG_PRINT("Executing ARM %s\n", "cblas_csymm"); 
	__real_cblas_csymm(Order,Side,Uplo,M,N,alpha,A,lda,B,ldb,beta,C,ldc); 
    TI_CBLAS_PROFILE_REPORT("  Entire %s call (ARM) took %8.2f us\n","cblas_csymm", (float) clock_diff);
	return ;
    }
    /* End ARM offload */

	/******************************************************************/
	/* DSP offload WILL be done if control reaches here */
	TI_CBLAS_DEBUG_PRINT("Offloading to DSP %s\n", "cblas_csymm"); 

	/* Lookup kernel pointer from global table */
#ifdef __cplusplus
	Event e;
	Kernel* __K;
#else
	cl_kernel __K;
#endif
    __K =  ti_cblas_get_kernel("ocl_cblas_csymm");

#ifdef __cplusplus
	try 
#else
	cl_int err = CL_SUCCESS;
#endif
	{

#ifdef __cplusplus
		__K->setArg(0, Order);
#else
		err |= clSetKernelArg(__K, 0, sizeof(Order), &Order);
#endif

#ifdef __cplusplus
		__K->setArg(1, Side);
#else
		err |= clSetKernelArg(__K, 1, sizeof(Side), &Side);
#endif

#ifdef __cplusplus
		__K->setArg(2, Uplo);
#else
		err |= clSetKernelArg(__K, 2, sizeof(Uplo), &Uplo);
#endif

#ifdef __cplusplus
		__K->setArg(3, M);
#else
		err |= clSetKernelArg(__K, 3, sizeof(M), &M);
#endif

#ifdef __cplusplus
		__K->setArg(4, N);
#else
		err |= clSetKernelArg(__K, 4, sizeof(N), &N);
#endif
		/* For const arguments we use CL_MEM_USE_READ_ONLY */

#ifdef __cplusplus
		Buffer buf_alpha(*ti_cblas_ocl_context, CL_MEM_READ_ONLY|CL_MEM_USE_HOST_PTR, 2*sizeof(float), (void *)alpha);
		__K->setArg(5, buf_alpha);
#else
		cl_mem buf_alpha = clCreateBuffer(ti_cblas_ocl_context, CL_MEM_READ_ONLY|CL_MEM_USE_HOST_PTR, 2*sizeof(float), (void *)alpha, &err);
		TI_CBLAS_OCL_CHKERROR("clCreateBuffer",err);
		err |= clSetKernelArg(__K, 5, sizeof(buf_alpha), &buf_alpha);
		TI_CBLAS_OCL_CHKERROR("clSetKernelArg",err);
#endif
		/* For const arguments we use CL_MEM_USE_READ_ONLY */

		int size_bufA;
		size_bufA = 2*BLAS_SIDE(Side,M,N)*lda*sizeof(float);
		size_bufA = MAX(size_bufA,1);
		   
#ifdef __cplusplus
		Buffer buf_A(*ti_cblas_ocl_context, CL_MEM_READ_ONLY|CL_MEM_USE_HOST_PTR, size_bufA, (void *)A);
		__K->setArg(6, buf_A);
#else
		cl_mem buf_A = clCreateBuffer(ti_cblas_ocl_context, CL_MEM_READ_ONLY|CL_MEM_USE_HOST_PTR, size_bufA, (void *)A, &err);
		TI_CBLAS_OCL_CHKERROR("clCreateBuffer",err);
		err |= clSetKernelArg(__K, 6, sizeof(buf_A), &buf_A);
		TI_CBLAS_OCL_CHKERROR("clSetKernelArg",err);
#endif

#ifdef __cplusplus
		__K->setArg(7, lda);
#else
		err |= clSetKernelArg(__K, 7, sizeof(lda), &lda);
#endif
		/* For const arguments we use CL_MEM_USE_READ_ONLY */

		int size_bufB;
		size_bufB = 2*BLAS_ORD(Order,M,N)*ldb*sizeof(float);
		size_bufB = MAX(size_bufB,1);
		   
#ifdef __cplusplus
		Buffer buf_B(*ti_cblas_ocl_context, CL_MEM_READ_ONLY|CL_MEM_USE_HOST_PTR, size_bufB, (void *)B);
		__K->setArg(8, buf_B);
#else
		cl_mem buf_B = clCreateBuffer(ti_cblas_ocl_context, CL_MEM_READ_ONLY|CL_MEM_USE_HOST_PTR, size_bufB, (void *)B, &err);
		TI_CBLAS_OCL_CHKERROR("clCreateBuffer",err);
		err |= clSetKernelArg(__K, 8, sizeof(buf_B), &buf_B);
		TI_CBLAS_OCL_CHKERROR("clSetKernelArg",err);
#endif

#ifdef __cplusplus
		__K->setArg(9, ldb);
#else
		err |= clSetKernelArg(__K, 9, sizeof(ldb), &ldb);
#endif
		/* For const arguments we use CL_MEM_USE_READ_ONLY */

#ifdef __cplusplus
		Buffer buf_beta(*ti_cblas_ocl_context, CL_MEM_READ_ONLY|CL_MEM_USE_HOST_PTR, 2*sizeof(float), (void *)beta);
		__K->setArg(10, buf_beta);
#else
		cl_mem buf_beta = clCreateBuffer(ti_cblas_ocl_context, CL_MEM_READ_ONLY|CL_MEM_USE_HOST_PTR, 2*sizeof(float), (void *)beta, &err);
		TI_CBLAS_OCL_CHKERROR("clCreateBuffer",err);
		err |= clSetKernelArg(__K, 10, sizeof(buf_beta), &buf_beta);
		TI_CBLAS_OCL_CHKERROR("clSetKernelArg",err);
#endif

		int size_bufC;
		size_bufC = 2*BLAS_ORD(Order,M,N)*ldc*sizeof(float);
		size_bufC = MAX(size_bufC,1);
		   
#ifdef __cplusplus
		Buffer buf_C(*ti_cblas_ocl_context, CL_MEM_READ_WRITE|CL_MEM_USE_HOST_PTR, size_bufC, (void *)C);
		__K->setArg(11, buf_C);
#else
		cl_mem buf_C = clCreateBuffer(ti_cblas_ocl_context, CL_MEM_READ_WRITE|CL_MEM_USE_HOST_PTR, size_bufC, (void *)C, &err);
		TI_CBLAS_OCL_CHKERROR("clCreateBuffer",err);
		err |= clSetKernelArg(__K, 11, sizeof(buf_C), &buf_C);
		TI_CBLAS_OCL_CHKERROR("clSetKernelArg",err);
#endif

#ifdef __cplusplus
		__K->setArg(12, ldc);
#else
		err |= clSetKernelArg(__K, 12, sizeof(ldc), &ldc);
#endif

		void *msmc_ptr;
		size_t msmc_size = MSMC_BUF_SIZE;
		msmc_ptr = ti_cblas_mem_alloc(MSMC_BUF_SIZE);
#ifdef __cplusplus
		Buffer buf_MSMC(*ti_cblas_ocl_context, CL_MEM_READ_WRITE|CL_MEM_USE_HOST_PTR, MSMC_BUF_SIZE, (void *)msmc_ptr);
		//Buffer buf_MSMC(ti_cblas_ocl_context, CL_MEM_READ_WRITE|CL_MEM_USE_MSMC_TI, MSMC_BUF_SIZE);
		__K->setArg(13, buf_MSMC);

#else
		//cl_mem buf_MSMC = clCreateBuffer(ti_cblas_ocl_context, CL_MEM_READ_WRITE|CL_MEM_USE_MSMC_TI, MSMC_BUF_SIZE, NULL, &err);
		cl_mem buf_MSMC = clCreateBuffer(ti_cblas_ocl_context, CL_MEM_READ_WRITE|CL_MEM_USE_HOST_PTR, MSMC_BUF_SIZE, (void *)msmc_ptr, &err);
		TI_CBLAS_OCL_CHKERROR("clCreateBuffer",err);
		err |= clSetKernelArg(__K, 13, sizeof(buf_MSMC), &buf_MSMC);
		TI_CBLAS_OCL_CHKERROR("clSetKernelArg",err);
#endif

#ifdef __cplusplus
		__K->setArg(14, msmc_size);
#else
		err |= clSetKernelArg(__K, 14, sizeof(msmc_size), &msmc_size);
#endif
		
		void *ddr_ptr;
		size_t ddr_size = DDR_BUF_SIZE;
		ddr_ptr = __malloc_ddr(DDR_BUF_SIZE);
		Buffer buf_DDR(*ti_cblas_ocl_context, CL_MEM_READ_WRITE|CL_MEM_USE_HOST_PTR, DDR_BUF_SIZE, ddr_ptr);
		__K->setArg(15, buf_DDR);		
		__K->setArg(16, ddr_size);	
		
        /* create a buffer argument to get the return error code from the DSP */
		int err_code;		
#ifdef __cplusplus
		Buffer buf_err(*ti_cblas_ocl_context, CL_MEM_READ_WRITE|CL_MEM_USE_HOST_PTR, sizeof(int), &err_code);
		__K->setArg(17, buf_err);
#else
		cl_mem buf_err = clCreateBuffer(*ti_cblas_ocl_context, CL_MEM_READ_WRITE|CL_MEM_USE_HOST_PTR, sizeof(int), &err_code, &err);
		TI_CBLAS_OCL_CHKERROR("clCreateBuffer",err);
		err |= clSetKernelArg(__K, 17, sizeof(buf_err), &buf_err);
		TI_CBLAS_OCL_CHKERROR("clSetKernelArg",err);
#endif

#ifdef __cplusplus
		ti_cblas_ocl_Q->enqueueTask(*__K, 0, &e);
		e.wait();
#else
		cl_event e;
		err |= clEnqueueTask(ti_cblas_ocl_Q, __K, 0, 0, &e);
		TI_CBLAS_OCL_CHKERROR("clEnqueueTask",err);
		err |= clWaitForEvents(1, &e);
		TI_CBLAS_OCL_CHKERROR("clWaitForEvents",err);
		err |= clReleaseEvent(e);
		TI_CBLAS_OCL_CHKERROR("clReleaseEvent",err);
#endif

        if(err_code != TICBLAS_SUCCESS) {
          printf("Error in offloaded cblas_csymm with error code %d!\n", err_code);
        }
		
		ti_cblas_mem_free(msmc_ptr);
		__free_ddr(ddr_ptr);

		ti_cblas_delete_kernel(__K);

		TI_CBLAS_DEBUG_PRINT("Finished executing %s\n", "cblas_csymm");
		TI_CBLAS_PROFILE_REPORT("  Entire %s call (DSP) took %8.2f us\n","cblas_csymm", (float) clock_diff);
		return ;
	}

#ifdef __cplusplus
	catch (Error err)
	{
        /* delete __K if it has not been deleted */
        if(__K!=NULL) {
            ti_cblas_delete_kernel(__K);
        }
    
		ti_cblas_error(err.what(),err.err());
		return ;
	}
#endif
}

