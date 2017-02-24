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
    void __real_cblas_dspr2(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const double alpha, const double *X, const int incX, const double *Y, const int incY, double *A) ; 

#ifdef __cplusplus
}
extern "C"
#endif
void cblas_dspr2(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const double alpha, const double *X, const int incX, const double *Y, const int incY, double *A)
{

	/* Do an init on first use */
	if (!ti_cblas_init_done) ti_cblas_init();
	TI_CBLAS_DEBUG_PRINT("Intercepted call to %s\n", "cblas_dspr2");

    TI_CBLAS_PROFILE_START();
	/* Dynamic condtional offload to ARM */
    if ((TI_CBLAS_L2_OFFLOAD == TI_CBLAS_OFFLOAD_NONE)) { 
	TI_CBLAS_DEBUG_PRINT("Executing ARM %s\n", "cblas_dspr2"); 
	__real_cblas_dspr2(order,Uplo,N,alpha,X,incX,Y,incY,A); 
    TI_CBLAS_PROFILE_REPORT("  Entire %s call (ARM) took %8.2f us\n","cblas_dspr2", (float) clock_diff);
	return ;
    }
    /* End ARM offload */

	/******************************************************************/
	/* DSP offload WILL be done if control reaches here */
	TI_CBLAS_DEBUG_PRINT("Offloading to DSP %s\n", "cblas_dspr2"); 

	/* Lookup kernel pointer from global table */
#ifdef __cplusplus
	Event e;
	Kernel* __K;
#else
	cl_kernel __K;
#endif
    __K =  ti_cblas_get_kernel("ocl_cblas_dspr2");

#ifdef __cplusplus
	try 
#else
	cl_int err = CL_SUCCESS;
#endif
	{

#ifdef __cplusplus
		__K->setArg(0, order);
#else
		err |= clSetKernelArg(__K, 0, sizeof(order), &order);
#endif

#ifdef __cplusplus
		__K->setArg(1, Uplo);
#else
		err |= clSetKernelArg(__K, 1, sizeof(Uplo), &Uplo);
#endif

#ifdef __cplusplus
		__K->setArg(2, N);
#else
		err |= clSetKernelArg(__K, 2, sizeof(N), &N);
#endif

#ifdef __cplusplus
		__K->setArg(3, alpha);
#else
		err |= clSetKernelArg(__K, 3, sizeof(alpha), &alpha);
#endif
		/* For const arguments we use CL_MEM_USE_READ_ONLY */

		int size_bufX;
		size_bufX = (1+(N-1)*abs(incX))*sizeof(double);
		size_bufX = MAX(size_bufX,1);
		   
#ifdef __cplusplus
		Buffer buf_X(*ti_cblas_ocl_context, CL_MEM_READ_ONLY|CL_MEM_USE_HOST_PTR, size_bufX, (void *)X);
		__K->setArg(4, buf_X);
#else
		cl_mem buf_X = clCreateBuffer(ti_cblas_ocl_context, CL_MEM_READ_ONLY|CL_MEM_USE_HOST_PTR, size_bufX, (void *)X, &err);
		TI_CBLAS_OCL_CHKERROR("clCreateBuffer",err);
		err |= clSetKernelArg(__K, 4, sizeof(buf_X), &buf_X);
		TI_CBLAS_OCL_CHKERROR("clSetKernelArg",err);
#endif

#ifdef __cplusplus
		__K->setArg(5, incX);
#else
		err |= clSetKernelArg(__K, 5, sizeof(incX), &incX);
#endif
		/* For const arguments we use CL_MEM_USE_READ_ONLY */

		int size_bufY;
		size_bufY = (1+(N-1)*abs(incY))*sizeof(double);
		size_bufY = MAX(size_bufY,1);
		   
#ifdef __cplusplus
		Buffer buf_Y(*ti_cblas_ocl_context, CL_MEM_READ_ONLY|CL_MEM_USE_HOST_PTR, size_bufY, (void *)Y);
		__K->setArg(6, buf_Y);
#else
		cl_mem buf_Y = clCreateBuffer(ti_cblas_ocl_context, CL_MEM_READ_ONLY|CL_MEM_USE_HOST_PTR, size_bufY, (void *)Y, &err);
		TI_CBLAS_OCL_CHKERROR("clCreateBuffer",err);
		err |= clSetKernelArg(__K, 6, sizeof(buf_Y), &buf_Y);
		TI_CBLAS_OCL_CHKERROR("clSetKernelArg",err);
#endif

#ifdef __cplusplus
		__K->setArg(7, incY);
#else
		err |= clSetKernelArg(__K, 7, sizeof(incY), &incY);
#endif

		int size_bufA;
		size_bufA = N*(N+1)/2*sizeof(double);
		size_bufA = MAX(size_bufA,1);
		   
#ifdef __cplusplus
		Buffer buf_A(*ti_cblas_ocl_context, CL_MEM_READ_WRITE|CL_MEM_USE_HOST_PTR, size_bufA, (void *)A);
		__K->setArg(8, buf_A);
#else
		cl_mem buf_A = clCreateBuffer(ti_cblas_ocl_context, CL_MEM_READ_WRITE|CL_MEM_USE_HOST_PTR, size_bufA, (void *)A, &err);
		TI_CBLAS_OCL_CHKERROR("clCreateBuffer",err);
		err |= clSetKernelArg(__K, 8, sizeof(buf_A), &buf_A);
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

		ti_cblas_delete_kernel(__K);

		TI_CBLAS_DEBUG_PRINT("Finished executing %s\n", "cblas_dspr2");
		TI_CBLAS_PROFILE_REPORT("  Entire %s call (DSP) took %8.2f us\n","cblas_dspr2", (float) clock_diff);
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

