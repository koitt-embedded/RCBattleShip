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

#define TEST_MEM_NOERR 0
#define TEST_MEM_ERROR 1

extern void lib_dsp_func(global const double *in1, global const double *in2, 
                          global double *out, int num_elements);
			 
extern int lib_config_memory(global void *msmc_mem_base,  size_t msmc_mem_size, 
                              global void *ddr_mem_base,   size_t ddr_mem_size,   
                              size_t l1D_SRAM_size_orig,   size_t l2_SRAM_size_orig);
extern int lib_reconfig_memory(size_t l1D_SRAM_size_orig, size_t l2_SRAM_size_orig);

/*==============================================================================
 * This is the OpenCl kernel to be dispatched from ARM. 
 *============================================================================*/
kernel void lib_kernel_ocl(global void *msmc_mem_base, size_t msmc_mem_size,
                           global void *ddr_mem_base,  size_t ddr_mem_size,
                           global const double *in1, global const double *in2,
                           global double *out, int data_size)
{
    size_t l1D_SRAM_size_orig, l2_SRAM_size_orig;
	
    /* prepare memory before calling the DSP processing function */
    lib_config_memory(msmc_mem_base, msmc_mem_size, ddr_mem_base,
                       ddr_mem_size, &l1D_SRAM_size_orig, &l2_SRAM_size_orig);
	
    /* call the DSP processing function */
	lib_dsp_func(in1, in2, out, data_size);
	
    /* reconfigure L1D and L2 after the processing */
    lib_reconfig_memory(l1D_SRAM_size_orig, l2_SRAM_size_orig);
}

void print_l2_start(local char * l2_buf);
kernel void ocl_find_l2_start(local char *l2_buf)
{
    print_l2_start(l2_buf);
}


/* Nothing past this point */
