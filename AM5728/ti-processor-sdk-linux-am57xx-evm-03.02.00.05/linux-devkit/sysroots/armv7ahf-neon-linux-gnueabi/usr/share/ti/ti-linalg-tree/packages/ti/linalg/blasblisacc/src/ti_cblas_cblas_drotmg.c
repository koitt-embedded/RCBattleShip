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
    void __real_cblas_drotmg(double *d1, double *d2, double *b1, const double b2, double *P) ; 

#ifdef __cplusplus
}
extern "C"
#endif
void cblas_drotmg(double *d1, double *d2, double *b1, const double b2, double *P)
{

	/* Do an init on first use */
	if (!ti_cblas_init_done) ti_cblas_init();
	TI_CBLAS_DEBUG_PRINT("Intercepted call to %s\n", "cblas_drotmg");

    TI_CBLAS_PROFILE_START();
	/* Dynamic condtional offload to ARM */
    if ((TI_CBLAS_L1_OFFLOAD == TI_CBLAS_OFFLOAD_NONE)) { 
	TI_CBLAS_DEBUG_PRINT("Executing ARM %s\n", "cblas_drotmg"); 
	__real_cblas_drotmg(d1,d2,b1,b2,P); 
    TI_CBLAS_PROFILE_REPORT("  Entire %s call (ARM) took %8.2f us\n","cblas_drotmg", (float) clock_diff);
	return ;
    }
    /* End ARM offload */

	/******************************************************************/
	/* DSP offload WILL be done if control reaches here */
	TI_CBLAS_DEBUG_PRINT("Offloading to DSP %s\n", "cblas_drotmg"); 

	/* Lookup kernel pointer from global table */
#ifdef __cplusplus
	Event e;
	Kernel* __K;
#else
	cl_kernel __K;
#endif
    __K =  ti_cblas_get_kernel("ocl_cblas_drotmg");

#ifdef __cplusplus
	try 
#else
	cl_int err = CL_SUCCESS;
#endif
	{

#ifdef __cplusplus
		Buffer buf_d1(*ti_cblas_ocl_context, CL_MEM_READ_WRITE|CL_MEM_USE_HOST_PTR, sizeof(double), (void *)d1);
		__K->setArg(0, buf_d1);
#else
		cl_mem buf_d1 = clCreateBuffer(ti_cblas_ocl_context, CL_MEM_READ_WRITE|CL_MEM_USE_HOST_PTR, sizeof(double), (void *)d1, &err);
		TI_CBLAS_OCL_CHKERROR("clCreateBuffer",err);
		err |= clSetKernelArg(__K, 0, sizeof(buf_d1), &buf_d1);
		TI_CBLAS_OCL_CHKERROR("clSetKernelArg",err);
#endif

#ifdef __cplusplus
		Buffer buf_d2(*ti_cblas_ocl_context, CL_MEM_READ_WRITE|CL_MEM_USE_HOST_PTR, sizeof(double), (void *)d2);
		__K->setArg(1, buf_d2);
#else
		cl_mem buf_d2 = clCreateBuffer(ti_cblas_ocl_context, CL_MEM_READ_WRITE|CL_MEM_USE_HOST_PTR, sizeof(double), (void *)d2, &err);
		TI_CBLAS_OCL_CHKERROR("clCreateBuffer",err);
		err |= clSetKernelArg(__K, 1, sizeof(buf_d2), &buf_d2);
		TI_CBLAS_OCL_CHKERROR("clSetKernelArg",err);
#endif

#ifdef __cplusplus
		Buffer buf_b1(*ti_cblas_ocl_context, CL_MEM_READ_WRITE|CL_MEM_USE_HOST_PTR, sizeof(double), (void *)b1);
		__K->setArg(2, buf_b1);
#else
		cl_mem buf_b1 = clCreateBuffer(ti_cblas_ocl_context, CL_MEM_READ_WRITE|CL_MEM_USE_HOST_PTR, sizeof(double), (void *)b1, &err);
		TI_CBLAS_OCL_CHKERROR("clCreateBuffer",err);
		err |= clSetKernelArg(__K, 2, sizeof(buf_b1), &buf_b1);
		TI_CBLAS_OCL_CHKERROR("clSetKernelArg",err);
#endif

#ifdef __cplusplus
		__K->setArg(3, b2);
#else
		err |= clSetKernelArg(__K, 3, sizeof(b2), &b2);
#endif

#ifdef __cplusplus
		Buffer buf_P(*ti_cblas_ocl_context, CL_MEM_READ_WRITE|CL_MEM_USE_HOST_PTR, 5*sizeof(double), (void *)P);
		__K->setArg(4, buf_P);
#else
		cl_mem buf_P = clCreateBuffer(ti_cblas_ocl_context, CL_MEM_READ_WRITE|CL_MEM_USE_HOST_PTR, 5*sizeof(double), (void *)P, &err);
		TI_CBLAS_OCL_CHKERROR("clCreateBuffer",err);
		err |= clSetKernelArg(__K, 4, sizeof(buf_P), &buf_P);
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

		TI_CBLAS_DEBUG_PRINT("Finished executing %s\n", "cblas_drotmg");
		TI_CBLAS_PROFILE_REPORT("  Entire %s call (DSP) took %8.2f us\n","cblas_drotmg", (float) clock_diff);
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

