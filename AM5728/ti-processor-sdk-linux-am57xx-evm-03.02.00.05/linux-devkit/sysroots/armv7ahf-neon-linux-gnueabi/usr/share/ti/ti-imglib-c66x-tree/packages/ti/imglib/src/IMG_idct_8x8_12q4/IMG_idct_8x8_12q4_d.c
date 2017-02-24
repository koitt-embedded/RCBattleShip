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
#include "IMG_idct_8x8_12q4.h"
#include "IMG_idct_8x8_12q4_cn.h"

#define BLOCK_SIZE  (8 * 8)
#define O_N         24
#define N           (BLOCK_SIZE * O_N)
#define PAD         64
#define SIZE        (N + 2*PAD)

typedef short IO_type;

IO_type input_output[SIZE];
IO_type ref_output[SIZE];


main()
{
  int   in_size, out_size, num_block;
  short align_in, align_out;
  IO_type *src_ptr;
  IO_type *ref_output_ptr;

  int *inp  = &in_data[0];
  int *outp = &out_data[0];

  /* Read test parameters. */
  align_in   = *inp++;
  align_out  = *inp++;

  src_ptr        = (IO_type *) ((unsigned int) &input_output[PAD] + align_in);
  ref_output_ptr = (IO_type *) ((unsigned int) &ref_output[PAD]   + align_out);

  /* Initialize profiling */
  IMG_profile_init (2, "IMG_idct_8x8_12q4");

  for (test_index=1; test_index<=testcases; test_index++) {
    /* Read test-case params. */
    est_test  = *inp++;
    num_block = *inp++;
    in_size   = *inp++;
    out_size  = *inp++;

    /* Check memory allocation */
    IMG_assert ((N >= in_size), "Insufficient memory allocated (in_size)");

    /* Prepare output arrays */
    IMG_clear_memory (ref_output,   sizeof(ref_output));
    IMG_clear_memory (input_output, sizeof(input_output));

    /* Copy ref output to its buffer */
    IMG_copy_int_to_short (ref_output_ptr, outp, out_size);
    outp += out_size;

    /* Test optimized kernel */
    IMG_copy_int_to_short (src_ptr, inp, in_size);
    IMG_profile_start (img_KERNEL_OPT);
    IMG_idct_8x8_12q4 (src_ptr, num_block);
    IMG_profile_stop  ();
    IMG_compare_mem   ((void *) input_output, (void *) ref_output, sizeof(ref_output));

    /* Test natural C kernel */
    IMG_copy_int_to_short (src_ptr, inp, in_size);
    IMG_profile_start (img_KERNEL_CN);
    IMG_idct_8x8_12q4_cn (src_ptr, num_block);
    IMG_profile_stop  ();
    IMG_compare_mem   ((void *) input_output, (void *) ref_output, sizeof(ref_output));
    inp += in_size;
    
    /* Profile display and preparation for cycle estimation */
    IMG_formula_add_test (num_block, NULL, NULL);
  } /* for */

  /* Calculate and display cycle formula (and testing success) */
  IMG_profile_cycle_formula ();
  IMG_profile_cycle_info    ("N = Number of 8x8 IDCT Blocks");
  
  /* Provide memory requirements */
  IMG_kernel_memory ();
}

