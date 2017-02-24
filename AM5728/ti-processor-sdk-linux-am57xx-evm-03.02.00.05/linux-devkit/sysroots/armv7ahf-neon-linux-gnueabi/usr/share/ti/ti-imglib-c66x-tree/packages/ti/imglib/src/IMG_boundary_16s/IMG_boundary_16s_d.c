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
#include "IMG_boundary_16s.h"
#include "IMG_boundary_16s_cn.h"

#define N 400
#define PAD 64
#define SIZE (N + 2*PAD)
short input_1[SIZE], input_2[SIZE];
unsigned int coord[SIZE], ref_coord[SIZE];
short grey[SIZE], ref_grey[SIZE];


main()
{
  int in_size, out_size;
  int rows, cols;
  short align_in, align_out;
  short *src_ptr_1;
  unsigned int *coord_ptr, *ref_coord_ptr;
  short *grey_ptr, *ref_grey_ptr;
  int *inp, *outp;

  inp  = &in_data[0];
  outp = &out_data[0];

  align_in  = *inp++;
  align_out = *inp++;

  coord_ptr     = (unsigned int *)((unsigned int) &coord[PAD]     + align_out);
  ref_coord_ptr = (unsigned int *)((unsigned int) &ref_coord[PAD] + align_out);
  src_ptr_1     = (short *)       ((unsigned int) &input_1[PAD]   + align_in);
  grey_ptr      = (short *)       ((unsigned int) &grey[PAD]      + align_out);
  ref_grey_ptr  = (short *)       ((unsigned int) &ref_grey[PAD]  + align_out);

  /* Initialize profiling */
  IMG_profile_init (2, "IMG_boundary_16s");

  for (test_index=1; test_index<=testcases; test_index++) {
    /* Read test-case params. */
    est_test = *inp++;
    rows     = *inp++;
    cols     = *inp++;
    in_size  = *inp++;
    out_size = *inp++;

    /* Check memory allocation */
    IMG_assert ((N >= in_size), "Insufficient memory allocated (in_size)");

    /* Prepare output arrays */
    IMG_clear_memory (coord,     sizeof(coord[0])     * SIZE);
    IMG_clear_memory (grey,      sizeof(grey[0])      * SIZE);
    IMG_clear_memory (ref_coord, sizeof(ref_coord[0]) * SIZE);
    IMG_clear_memory (ref_grey,  sizeof(ref_grey[0])  * SIZE);

    /* Copy input and ref output to respective buffers */
    IMG_copy_int_to_short (src_ptr_1,     inp,  in_size);
    IMG_copy_int_to_uint  (ref_coord_ptr, outp, out_size);
    outp += out_size;
    IMG_copy_int_to_short (ref_grey_ptr,  outp, out_size);
    outp += out_size;
    inp  += in_size;

    /* Test optimized kernel */
    IMG_clear_memory  (coord, sizeof(short) * SIZE);
    IMG_clear_memory  (grey,  sizeof(short) * SIZE);
    IMG_profile_start (img_KERNEL_OPT);
    IMG_boundary_16s  (src_ptr_1, rows, cols, coord_ptr, grey_ptr);
    IMG_profile_stop  ();
    IMG_compare_mem   ((void *) coord, (void *) ref_coord, sizeof(ref_coord));
    IMG_compare_mem   ((void *) grey,  (void *) ref_grey,  sizeof(ref_grey));

    /* Test natural C kernel */
    IMG_clear_memory    (coord, sizeof(short) * SIZE);
    IMG_clear_memory    (grey,  sizeof(short) * SIZE);
    IMG_profile_start   (img_KERNEL_CN);
    IMG_boundary_16s_cn (src_ptr_1, rows, cols, coord_ptr, grey_ptr);
    IMG_profile_stop    ();
    IMG_compare_mem     ((void *) coord, (void *) ref_coord, sizeof(ref_coord));
    IMG_compare_mem     ((void *) grey,  (void *) ref_grey,  sizeof(ref_grey));

    /* Profile display and preparation for cycle estimation */
    IMG_formula_add_test (rows*cols, NULL, NULL);
  } /* for */

  /* Calculate and display cycle formula (and testing success) */
  IMG_profile_cycle_formula ();
  IMG_profile_cycle_info    ("N = Rows * Columns");
  
  /* Provide memory requirements */
  IMG_kernel_memory ();
}

