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
#include "IMG_histogram_8.h"
#include "IMG_histogram_8_cn.h"

#define N         32768
#define M           512
#define PAD          64
#define SIZE      (N   + 2*PAD)
#define OUT_SIZE  (M   + 2*PAD)
#define TEMP_SIZE (4*M + 2*PAD)

unsigned char input_1[SIZE], input_2[SIZE];
short output_c[OUT_SIZE], output_i[OUT_SIZE], ref_out[OUT_SIZE];
unsigned short temp_buf[TEMP_SIZE];


main()
{
  int acc, in_size, out_size;
  short align_in, align_out;
  unsigned char *src_ptr_1;
  short *dst_ptr_c, *dst_ptr_i, *ref_out_ptr;
  short *temp_ptr;

  int *inp  = &in_data[0];
  int *outp = &out_data[0];

  align_in  = *inp++;
  align_out = *inp++;

  src_ptr_1   = (unsigned char *) ((unsigned int) &input_1 [PAD] + align_in );
  dst_ptr_c   = (short *)         ((unsigned int) &output_c[PAD] + align_out);
  dst_ptr_i   = (short *)         ((unsigned int) &output_i[PAD] + align_out);
  temp_ptr    = (short *)         ((unsigned int) &temp_buf[PAD]);
  ref_out_ptr = (short *)         ((unsigned int) &ref_out [PAD] + align_out);

  /* Initialize profiling */
  IMG_profile_init (2, "IMG_histogram_8");

  for (test_index=1; test_index<=testcases; test_index++) {
    est_test = *inp++;
    acc      = *inp++;
    in_size  = *inp++;
    out_size = *inp++;

    /* Check memory allocation */
    IMG_assert ((N >= in_size), "Insufficient memory allocated (in_size)");
    IMG_assert ((OUT_SIZE >= out_size), "Insufficient memory allocated (out_size)");

    /* Prepare output arrays */
    IMG_clear_memory (output_c, sizeof(ref_out[0]) * OUT_SIZE);
    IMG_clear_memory (output_i, sizeof(ref_out[0]) * OUT_SIZE);
    IMG_clear_memory (ref_out , sizeof(ref_out[0]) * OUT_SIZE);

    /* Copy input and ref output to respective buffers */
    IMG_copy_int_to_uchar (src_ptr_1,   inp,  in_size);
    IMG_copy_int_to_short (ref_out_ptr, outp, out_size);
    inp  += in_size;
    outp += out_size;

    /* Test optimized kernel */
    IMG_clear_memory  (temp_buf, sizeof(short) * TEMP_SIZE);
    IMG_profile_start (img_KERNEL_OPT);
    IMG_histogram_8   (src_ptr_1, in_size, acc, temp_ptr, dst_ptr_i);
    IMG_profile_stop  ();
    IMG_compare_mem   ((void *) output_i, (void *) ref_out, OUT_SIZE * sizeof(ref_out[0]));

    /* Test natural C kernel */
    IMG_clear_memory    (temp_buf, sizeof(short) * TEMP_SIZE);
    IMG_profile_start   (img_KERNEL_CN);
    IMG_histogram_8_cn  (src_ptr_1, in_size, acc, temp_ptr, dst_ptr_c);
    IMG_profile_stop    ();
    IMG_compare_mem     ((void *) output_c, (void *) ref_out, OUT_SIZE * sizeof(ref_out[0]));

    /* Profile display and preparation for cycle estimation */
    IMG_formula_add_test (in_size, NULL, NULL);
  } /* for */

  /* Calculate and display cycle formula (and testing success) */
  IMG_profile_cycle_formula ();
  IMG_profile_cycle_info    ("N = Pixels");
  
  /* Provide memory requirements */
  IMG_kernel_memory ();
}
