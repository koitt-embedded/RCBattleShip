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
#include "IMG_sobel_3x3_16.h"
#include "IMG_sobel_3x3_16_cn.h"

#define N 96
#define PAD 64
#define SIZE (N + 2*PAD)

typedef unsigned short D_type;

D_type input[SIZE];
D_type output[SIZE];
D_type ref_output[SIZE];


main()
{
  int in_size, out_size;
  int cols, rows;
  short align_in, align_out;
  D_type *src_ptr;
  D_type *output_ptr, *ref_output_ptr;

  int *inp  = &in_data[0];
  int *outp = &out_data[0];

  /* Read test parameters. */
  align_in  = *inp++;
  align_out = *inp++;

  src_ptr        = (D_type *) ((unsigned int) &input[PAD]      + align_in);
  output_ptr     = (D_type *) ((unsigned int) &output[PAD]     + align_out);
  ref_output_ptr = (D_type *) ((unsigned int) &ref_output[PAD] + align_out);

  /* Initialize profiling */
  IMG_profile_init (2, "IMG_sobel_3x3_16");

  for (test_index=1; test_index<=testcases; test_index++) {
    est_test = *inp++;
    cols     = *inp++;
    rows     = *inp++;
    in_size  = *inp++;
    out_size = *inp++;  // input and output size is the same.

    /* Check memory allocation */
    IMG_assert ((N >= in_size), "Insufficient memory allocated (in_size)");

    /* Prepare output arrays */
    IMG_clear_memory (input,      sizeof(input));
    IMG_clear_memory (ref_output, sizeof(ref_output));

    /* Copy input and ref output to respective buffers */
    IMG_copy_int_to_ushort (src_ptr,            inp,  in_size);
    IMG_copy_int_to_ushort (ref_output_ptr + 1, outp, out_size);
    inp  += in_size;
    outp += out_size;

    /* Test optimized kernel */
    IMG_clear_memory  (output, sizeof(output));
    IMG_profile_start (img_KERNEL_OPT);
    IMG_sobel_3x3_16  (src_ptr, output_ptr, cols, rows);
    IMG_profile_stop  ();
    IMG_compare_mem   ((void *) output, (void *) ref_output, sizeof(ref_output));

    /* Test natural C kernel */
    IMG_clear_memory    (output, sizeof(output));
    IMG_profile_start   (img_KERNEL_CN);
    IMG_sobel_3x3_16_cn (src_ptr, output_ptr, cols, rows);
    IMG_profile_stop    ();
    IMG_compare_mem     ((void *) output, (void *) ref_output, sizeof(ref_output));

    /* Profile display and preparation for cycle estimation */
    IMG_formula_add_test ((rows-2)*cols, NULL, NULL);
  } /* for */

  /* Calculate and display cycle formula (and testing success) */
  IMG_profile_cycle_formula ();
  IMG_profile_cycle_info    ("N = (Rows - 2) * Columns");
  
  /* Provide memory requirements */
  IMG_kernel_memory ();
}

    
