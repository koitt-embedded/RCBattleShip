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
#include "IMG_memory.h"


/* INT to CHAR memory copy utility */
void IMG_copy_int_to_char (char *restrict dst, int *restrict src, int elements)
{
  int i;

  for (i=0; i<elements; i++) {
    dst[i] = src[i] & 0xFF;
  }
}


/* INT to SHORT memory copy utility */
void IMG_copy_int_to_short (short *restrict dst, int *restrict src, int elements)
{
  int i;
  int dat_out;
  char *char_dst = (char *) dst; // For non-aligned memory.

  for (i=0; i<elements; i++) {
    dat_out = src[i];
    *char_dst++ = dat_out & 0xFF;
    *char_dst++ = dat_out >> 8;
  }
}


/* Memory comparison utility (size in bytes) */
void IMG_compare_mem (void *a, void *b, int size)
{
  /* Compare memory (byte-based) */
  if (memcmp (a, b, size)) {
    IMG_assert ((act_kernel == img_KERNEL_OPT || 
                 act_kernel == img_KERNEL_CN), "Invalid kernel type");

    /* Provide failure message */
    if (act_kernel == img_KERNEL_OPT) {
      printf ("\nFailure: Output - Optimized:  Case #%d\n", test_index);
    }
    else {
      printf ("\nFailure: Output - Natural C:  Case #%d\n", test_index);
    }

    /* Return indication of failure */
    IMG_error_handler ();
  }
}

/* =========================================================================*/
/*  End of file:  IMG_memory.c                                              */
/* =========================================================================*/

