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
#include "IMG_yc_demux_le16_8.h"
#include "IMG_yc_demux_le16_8_cn.h"

#define N   256
#define N_Y (N >> 1)
#define N_C (N >> 2)
#define PAD 64
#define SIZE (N + 2*PAD)
#define SIZE_Y (N_Y + 2*PAD)
#define SIZE_C (N_C + 2*PAD)

typedef unsigned char  I_type;
typedef          short O_type;

I_type input[SIZE];
O_type y_out[SIZE_Y], cr_out[SIZE_C], cb_out[SIZE_C];
O_type y_out_ref[SIZE_Y], cr_out_ref[SIZE_C], cb_out_ref[SIZE_C];


main()
{
  int in_size, out_size_y, out_size_c;
  int num_luma;
  short align_in, align_out;
  I_type *src_ptr;
  O_type *y_out_ptr, *y_out_ptr_ref;
  O_type *cb_out_ptr, *cb_out_ptr_ref;
  O_type *cr_out_ptr, *cr_out_ptr_ref;

  int *inp  = &in_data[0];
  int *outp = &out_data[0];

  /* Read alignment parameters. */
  align_in   = *inp++;
  align_out  = *inp++;

  src_ptr    		 = (I_type *) ((unsigned int) &input[PAD]      + align_in );
  y_out_ptr  		 = (O_type *) ((unsigned int) &y_out[PAD]      + align_out);
  y_out_ptr_ref  = (O_type *) ((unsigned int) &y_out_ref[PAD]  + align_out);
  cr_out_ptr     = (O_type *) ((unsigned int) &cr_out[PAD]     + align_out);
  cr_out_ptr_ref = (O_type *) ((unsigned int) &cr_out_ref[PAD] + align_out);
  cb_out_ptr     = (O_type *) ((unsigned int) &cb_out[PAD]     + align_out);
  cb_out_ptr_ref = (O_type *) ((unsigned int) &cb_out_ref[PAD] + align_out);

  /* Initialize profiling */
  IMG_profile_init (2, "IMG_yc_demux_le16_8");

  for (test_index=1; test_index<=testcases; test_index++) {
    /* Read test-case params. */
    est_test   = *inp++;
    num_luma   = *inp++;
    in_size    = *inp++;
    out_size_y = *inp++;
    out_size_c = *inp++;

    /* Check memory allocation */
    IMG_assert ((N >= in_size), "Insufficient memory allocated (in_size)");

    /* Prepare output arrays */
    IMG_clear_memory (input,      sizeof (input));
    IMG_clear_memory (y_out,      sizeof (y_out));
    IMG_clear_memory (y_out_ref,  sizeof (y_out_ref));
    IMG_clear_memory (cr_out,     sizeof (cr_out));
    IMG_clear_memory (cr_out_ref, sizeof (cr_out_ref));
    IMG_clear_memory (cb_out,     sizeof (cb_out));
    IMG_clear_memory (cb_out_ref, sizeof (cb_out_ref));

    /* Copy input and ref output to respective buffers */
    IMG_copy_int_to_uchar (src_ptr, inp, in_size);
    inp  += in_size;
    IMG_copy_int_to_short (y_out_ptr_ref, outp, out_size_y);
    outp += out_size_y;
    IMG_copy_int_to_short (cr_out_ptr_ref, outp, out_size_c);
    outp += out_size_c;
    IMG_copy_int_to_short (cb_out_ptr_ref, outp, out_size_c);
    outp += out_size_c;

    /* Test optimized kernel */
    IMG_clear_memory  (y_out,  sizeof(y_out));
    IMG_clear_memory  (cr_out, sizeof(cr_out));
    IMG_clear_memory  (cb_out, sizeof(cb_out));
    IMG_profile_start (img_KERNEL_OPT);
    IMG_yc_demux_le16_8 (num_luma, src_ptr, y_out_ptr, cr_out_ptr, cb_out_ptr);
    IMG_profile_stop  ();
    IMG_compare_mem   ((void *)  y_out, (void *)  y_out_ref, sizeof(y_out_ref));
    IMG_compare_mem   ((void *) cr_out, (void *) cr_out_ref, sizeof(cr_out_ref));
    IMG_compare_mem   ((void *) cb_out, (void *) cb_out_ref, sizeof(cb_out_ref));

    /* Test natural C kernel */
    IMG_clear_memory  (y_out,  sizeof(y_out));
    IMG_clear_memory  (cr_out, sizeof(cr_out));
    IMG_clear_memory  (cb_out, sizeof(cb_out));
    IMG_profile_start (img_KERNEL_CN);
    IMG_yc_demux_le16_8_cn (num_luma, src_ptr, y_out_ptr, cr_out_ptr, cb_out_ptr);
    IMG_profile_stop  ();
    IMG_compare_mem   ((void *)  y_out, (void *)  y_out_ref, sizeof(y_out_ref));
    IMG_compare_mem   ((void *) cr_out, (void *) cr_out_ref, sizeof(cr_out_ref));
    IMG_compare_mem   ((void *) cb_out, (void *) cb_out_ref, sizeof(cb_out_ref));

    /* Profile display and preparation for cycle estimation */
    IMG_formula_add_test (num_luma, NULL, NULL);
  } /* for */

  /* Calculate and display cycle formula (and testing success) */
  IMG_profile_cycle_formula ();
  IMG_profile_cycle_info    ("N = Luma Pixels");
  
  /* Provide memory requirements */
  IMG_kernel_memory ();
}

