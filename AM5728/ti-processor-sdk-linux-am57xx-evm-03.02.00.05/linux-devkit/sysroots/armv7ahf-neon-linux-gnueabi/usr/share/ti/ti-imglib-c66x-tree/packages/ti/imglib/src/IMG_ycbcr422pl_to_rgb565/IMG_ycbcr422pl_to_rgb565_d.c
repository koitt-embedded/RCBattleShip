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
#include "IMG_ycbcr422pl_to_rgb565.h"
#include "IMG_ycbcr422pl_to_rgb565_cn.h"

#define N   64
#define PAD 32
#define SIZE (N + 2*PAD)
#define NUM_COEFF 5

typedef unsigned char  I_type;
typedef unsigned short O_type;

I_type y_in[SIZE], cr_in[SIZE], cb_in[SIZE];
O_type rgb[SIZE], rgb_ref[SIZE];
short coeff[NUM_COEFF + 2*PAD];


main()
{
  int num, c_num;
  short align_y, align_c, align_out, align_coeff;
  I_type *y_in_ptr, *cb_in_ptr, *cr_in_ptr;
  O_type *rgb_ptr, *rgb_ref_ptr;
  short *coeff_ptr;

  int *inp  = &in_data[0];
  int *outp = &out_data[0];

  /* Read alignment parameters. */
  align_y    = *inp++;
  align_c    = *inp++;
  align_out  = *inp++;
  align_coeff= *inp++;

  y_in_ptr    = (I_type *) ((unsigned int) &y_in[PAD]    + align_y);
  cr_in_ptr   = (I_type *) ((unsigned int) &cr_in[PAD]   + align_c);
  cb_in_ptr   = (I_type *) ((unsigned int) &cb_in[PAD]   + align_c);
  rgb_ptr     = (O_type *) ((unsigned int) &rgb[PAD]     + align_out);
  rgb_ref_ptr = (O_type *) ((unsigned int) &rgb_ref[PAD] + align_out);
  coeff_ptr   = (short  *) ((unsigned int) &coeff[PAD]   + align_coeff);

  /* Initialize profiling */
  IMG_profile_init (2, "IMG_ycbcr422pl_to_rgb565");

  for (test_index=1; test_index<=testcases; test_index++) {
    /* Read test-case params. */
    est_test = *inp++;
    num      = *inp++;
    c_num    = num >> 1;

    /* Check memory allocation */
    IMG_assert ((N >= num), "Insufficient memory allocated (in_size)");

    /* Prepare output arrays */
    IMG_clear_memory (y_in,    sizeof(y_in));
    IMG_clear_memory (cr_in,   sizeof(cr_in));
    IMG_clear_memory (cb_in,   sizeof(cb_in));
    IMG_clear_memory (rgb,     sizeof(rgb));
    IMG_clear_memory (rgb_ref, sizeof(rgb_ref));

    /* Copy input and ref output to respective buffers */
    IMG_copy_int_to_short (coeff_ptr, inp, NUM_COEFF);
    inp  += NUM_COEFF;
    IMG_copy_int_to_uchar (y_in_ptr, inp, num);
    inp += num;
    IMG_copy_int_to_uchar (cb_in_ptr, inp, c_num);  
    inp += c_num;
    IMG_copy_int_to_uchar (cr_in_ptr, inp, c_num);  
    inp += c_num;
    IMG_copy_int_to_ushort (rgb_ref_ptr, outp, num);
    outp += num;
    
    /* Test optimized kernel */
    IMG_clear_memory  (rgb, sizeof(rgb));
    IMG_profile_start (img_KERNEL_OPT);
    IMG_ycbcr422pl_to_rgb565 (coeff_ptr, y_in_ptr, cb_in_ptr, cr_in_ptr, rgb_ptr, num);
    IMG_profile_stop  ();
    IMG_compare_mem   ((void *) rgb, (void *) rgb_ref, sizeof(rgb_ref));

    /* Test natural C kernel */
    IMG_clear_memory  (rgb, sizeof(rgb));
    IMG_profile_start (img_KERNEL_CN);
    IMG_ycbcr422pl_to_rgb565_cn (coeff_ptr, y_in_ptr, cb_in_ptr, cr_in_ptr, rgb_ptr, num);
    IMG_profile_stop  ();
    IMG_compare_mem   ((void *) rgb, (void *) rgb_ref, sizeof(rgb_ref));

    /* Profile display and preparation for cycle estimation */
    IMG_formula_add_test (num, NULL, NULL);
  } /* for */

  /* Calculate and display cycle formula (and testing success) */
  IMG_profile_cycle_formula ();
  IMG_profile_cycle_info    ("N = Luma Pixels");
  
  /* Provide memory requirements */
  IMG_kernel_memory ();
}

