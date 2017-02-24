/* ======================================================================== *
 * IMGLIB -- TI Image and Video Processing Library                          *
 *                                                                          *
 *                                                                          *
 * Copyright (C) 2012 Texas Instruments Incorporated - http://www.ti.com/   *
 *                                                                          *
 *                                                                          *
 *  Redistribution and use in source and binary forms, with or without      *
 *  modification, are permitted provided that the following conditions      *
 *  are met:                                                                *
 *                                                                          *
 *    Redistributions of source code must retain the above copyright        *
 *    notice, this list of conditions and the following disclaimer.         *
 *                                                                          *
 *    Redistributions in binary form must reproduce the above copyright     *
 *    notice, this list of conditions and the following disclaimer in the   *
 *    documentation and/or other materials provided with the                *
 *    distribution.                                                         *
 *                                                                          *
 *    Neither the name of Texas Instruments Incorporated nor the names of   *
 *    its contributors may be used to endorse or promote products derived   *
 *    from this software without specific prior written permission.         *
 *                                                                          *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS     *
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT       *
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR   *
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT    *
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,   *
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT        *
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,   *
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY   *
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT     *
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE   *
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.    *
 * ======================================================================== */

#include <stdio.h>
#include <ti/imglib/src/common/IMG_profile.h>
#include <ti/imglib/src/common/IMG_memory.h>
#include "IMG_corr_gen_i16s_c16s.h"
#include "IMG_corr_gen_i16s_c16s_cn.h"

#define N 96
#define C_N 22
#define PAD 32
#define SIZE (N + 2*PAD)
#define C_SIZE (C_N + 2*PAD)

typedef short  I_type;
typedef short  C_type;
typedef short  O_type;

I_type input_1[SIZE];
C_type mask[C_SIZE];
O_type output[SIZE];
O_type ref_output[SIZE];

extern void cholesky_test (void);

main()
{
  int in_size, out_size, k_size;
  short align_in, align_mask, align_out;
  I_type *src_ptr_1;
  C_type *mask_ptr;
  O_type *output_ptr, *ref_output_ptr;

  int *inp  = &in_data[0];
  int *outp = &out_data[0];

  /* Read test parameters. */
  align_in   = *inp++;
  align_mask = *inp++;
  align_out  = *inp++;

  src_ptr_1      = (I_type *) ((unsigned int) &input_1[PAD]    + align_in);
  mask_ptr       = (C_type *) ((unsigned int) &mask[PAD]       + align_mask);
  output_ptr     = (O_type *) ((unsigned int) &output[PAD]     + align_out);
  ref_output_ptr = (O_type *) ((unsigned int) &ref_output[PAD] + align_out);

  /* Initialize profiling */
  IMG_profile_init (4, "IMG_corr_gen_i16s_c16s");

  for (test_index=1; test_index<=testcases; test_index++) {
    /* Read test-case params. */
    est_test = *inp++;
    in_size  = *inp++;
    k_size   = *inp++;
    out_size = *inp++;

    /* Check memory allocation */
    IMG_assert ((N   >= in_size), "Insufficient memory allocated (in_size)");
    IMG_assert ((C_N >= k_size),  "Insufficient memory allocated (k_size)");

    /* Prepare output arrays */
    IMG_clear_memory (input_1,    sizeof(input_1));
    IMG_clear_memory (ref_output, sizeof(ref_output));

    /* Copy input and ref output to respective buffers */
    IMG_copy_int_to_short (src_ptr_1,      inp,  in_size);
    inp  += in_size;
    IMG_copy_int_to_short (mask_ptr,       inp,  k_size);
    IMG_copy_int_to_short (ref_output_ptr, outp, out_size);
    inp  += k_size;
    outp += out_size;

    /* Test optimized kernel */
    IMG_clear_memory  (output, sizeof(output));
    IMG_profile_start (img_KERNEL_OPT);
    IMG_corr_gen_i16s_c16s (src_ptr_1, mask_ptr, output_ptr, k_size, in_size);
    IMG_profile_stop  ();
    IMG_compare_mem   ((void *) output, (void *) ref_output, sizeof(ref_output));

    /* Test natural C kernel */
    IMG_clear_memory  (output, sizeof(output));
    IMG_profile_start (img_KERNEL_CN);
    IMG_corr_gen_i16s_c16s_cn (src_ptr_1, mask_ptr, output_ptr, k_size, in_size);
    IMG_profile_stop  ();
    IMG_compare_mem   ((void *) output, (void *) ref_output, sizeof(ref_output));
    
    /* Profile display and preparation for cycle estimation */
    IMG_formula_add_test ((k_size-(k_size%2))*((in_size-(k_size-(k_size%2))+7)>>3), k_size, 
                          (k_size%2)*((in_size-k_size+3)>>2));
  } /* for */

  /* Calculate and display cycle formula (and testing success) */
  IMG_profile_cycle_formula ();
  IMG_profile_cycle_info ("M = Filter Taps");
  IMG_profile_cycle_info ("R = M modulus 2 (0 if EVEN, 1 if ODD)");
  IMG_profile_cycle_info ("N = (M - R) * Floor((Pitch - M - R + 8) / 8)");
  IMG_profile_cycle_info ("L = R * Floor((Pitch - M + 4) / 4)");
  
  /* Provide memory requirements */
  IMG_kernel_memory ();
}

