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

////////////////////////////////////////////////////////////////////////////////
//  This file shows an example of the host code of an application that uses an 
//  ARM+DSP library. 
//////////////////////////////////////////////////////////////////////////////// 
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <fstream>
#define __CL_ENABLE_EXCEPTIONS
#include <CL/cl.hpp>
using namespace std;
using namespace cl;
// Both cl and std namespace define size_t, so we must be explicit.
#define size_t ::size_t
#ifndef TEST_FAT_BINARY
#include "ocl_util.h"
#endif
#include <pthread.h>


#define TEST_DEBUG_PRINT(...) {fprintf(stdout,"TEST DEBUG: ");fprintf(stdout,__VA_ARGS__);}

extern void lib_init_arm();
extern void lib_find_l2_start();
extern void lib_kernel_arm(double *in1_ptr, double *in2_ptr, double *out_ptr, int data_size);

void app_fill_memory(double *buf1, double *buf2, int num_elements);
double app_err_check(double *in1, double *in2, double *out, int num_elements);

#define TEST_DATA_SIZE     (1024)        //1K data points

/*==============================================================================
 * Application code on the host which calls library functions to process data.
 *============================================================================*/
int main()
{    
    // Allocate input/output buffers using TI-OpenCL built-ins. 
    TEST_DEBUG_PRINT("Allocating memory for input/output buffers.\n");   
    double *in1_ptr  = (double *)__malloc_ddr(TEST_DATA_SIZE*sizeof(double));
    double *in2_ptr  = (double *)__malloc_ddr(TEST_DATA_SIZE*sizeof(double));
    double *out_ptr  = (double *)__malloc_ddr(TEST_DATA_SIZE*sizeof(double));

    TEST_DEBUG_PRINT("in1_ptr  is: 0x%08x.\n", (unsigned int)in1_ptr);
    TEST_DEBUG_PRINT("in2_ptr  is: 0x%08x.\n", (unsigned int)in2_ptr);
    TEST_DEBUG_PRINT("out_ptr  is: 0x%08x.\n", (unsigned int)out_ptr);

    if(in1_ptr==NULL || in2_ptr==NULL || out_ptr==NULL) {
        TEST_DEBUG_PRINT("No memory!\n");
        exit(0);
    }
    else {
        TEST_DEBUG_PRINT("Memory allocated.\n");
    }

    // Fill memory with data for testing. 
    app_fill_memory(in1_ptr, in2_ptr, TEST_DATA_SIZE);

    // OpenCL initialization
    lib_init_arm();
	
	// Testing - print L2 start address
	lib_find_l2_start();
	
    // Pass input/output buffers to library function which sums two input buffers
    // and return the sum in the output buffer. 
    lib_kernel_arm(in1_ptr, in2_ptr, out_ptr, TEST_DATA_SIZE);

    __free_ddr(in1_ptr); 
    __free_ddr(in2_ptr); 
    __free_ddr(out_ptr); 

	double err = app_err_check(in1_ptr, in2_ptr, out_ptr, TEST_DATA_SIZE);
	
    TEST_DEBUG_PRINT("Error checking. Difference between ARM results and DSP results: %e\n", err);
	
	if(err != 0) {
        TEST_DEBUG_PRINT("Failed!\n");		
	}
	else {
        TEST_DEBUG_PRINT("Passed!\n");		
	}
	
    return(0);
} /* main */

/*==============================================================================
 * Filling memory with random data.
 *============================================================================*/
void app_fill_memory(double *buf1, double *buf2, int num_elements)
{
    for(int i=0; i<num_elements; i++)
    {
        buf1[i] = (double)rand()/RAND_MAX;
        buf2[i] = (double)rand()/RAND_MAX;
    }

    for(int i=0;i<10;i++)
    {
      TEST_DEBUG_PRINT("ARM Input 1: %e, Input 2: %e\n", buf1[i],buf2[i]);
    }

} /* app_fill_memory */

/*==============================================================================
 * Error checking: check if buffer out is the sum of buffer in1 and buffer in2.
 *============================================================================*/
double app_err_check(double *in1, double *in2, double *out, int num_elements)
{
    double error = 0.0;

    for(int i=0;i<10;i++)
    {
      TEST_DEBUG_PRINT("Output returned by DSP: %e\n", out[i]);
    }
  
    for(int i=0; i<num_elements; i++)
    {
        error += out[i] - (in1[i]+in2[i]);
    }
   
    return(error);
} /* app_err_check */

/* Nothing past this point */
