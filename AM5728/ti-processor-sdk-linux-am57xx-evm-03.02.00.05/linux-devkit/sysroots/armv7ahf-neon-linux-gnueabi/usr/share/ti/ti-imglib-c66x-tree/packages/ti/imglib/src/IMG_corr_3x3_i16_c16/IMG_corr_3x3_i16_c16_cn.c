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

/* ======================================================================== */
/*  NAME                                                                    */
/*     IMG_corr_3x3_i16_c16_cn                                              */
/*                                                                          */
/*  USAGE                                                                   */
/*     This routine is C-callable and can be called as:                     */
/*                                                                          */
/*         void IMG_corr_3x3_i16s_c16s_cn                                   */
/*         (                                                                */
/*             const unsigned short           *imgin_ptr,                   */
/*                   unsigned int   *restrict imgout_ptr,                   */
/*             const unsigned short            *mask_ptr,                   */
/*                   short                     pitch,                       */
/*                   short                     width,                       */
/*         )                                                                */
/*                                                                          */
/*     imgin_ptr :  pointer to an input  array of 16 bit pixels             */
/*     imgout_ptr:  pointer to an output array of 32 bit pixels             */
/*     width     :  number of output pixels                                 */
/*     pitch     :  number of columns in the input image                    */
/*     mask_ptr  :  pointer to 16 bit filter mask.                          */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      The correlation performs a point by point multiplication of the     */
/*      3 by 3 mask with the input image.  The result of the nine           */
/*      multiplications are then summed up together to produce a            */
/*      convolution sum.  This sum is then stored to the output array.      */
/*                                                                          */
/*      The image mask to be correlated is typically part of the input      */
/*      image and indicates the area of the best match between the          */
/*      input image and mask.  The mask is moved one column at a time,      */
/*      advancing the mask over the portion of the row specified by         */
/*      'width'.  When 'width' is larger than 'pitch', multiple rows        */
/*      will be processed.                                                  */
/*                                                                          */
/*      An application may call this kernel once per row to calculate       */
/*      the correlation for an entire image:                                */
/*                                                                          */
/*          for (i = 0; i < rows; i++)                                      */
/*          {                                                               */
/*              IMG_corr_3x3_i16_c16_cn (&imgin_ptr[i * pitch],             */
/*                                       &imgout_ptr[i * width],            */
/*                                       mask_ptr, pitch, width);           */
/*          }                                                               */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*     - Input and Output buffers do not alias.                             */
/*     - 'width' should be a multiple of 4                                  */
/*                                                                          */
/*  MEMORY NOTE                                                             */
/*     - This kernel places no restrictions on the alignment of its input.  */
/*     - No bank conflicts occur.                                           */
/*     - This code assumes a LITTLE ENDIAN configuration.                   */
/*                                                                          */
/*  TECHNIQUES                                                              */
/*      The inner loops are unrolled completely, and the outer loop is      */
/*      unrolled 4 times.                                                   */
/*      Half-word unsigned multiplication is used here.                     */
/*      Non-aligned loads and stores are used to avoid alignment issues.    */
/*                                                                          */
/* ======================================================================== */

#ifdef __TI_INT40_T__
  typedef __int40_t long40;
#else
  typedef long long long40;
#endif

void IMG_corr_3x3_i16_c16_cn
(
    const unsigned short           *imgin_ptr,   /* input image       */
          unsigned int   *restrict imgout_ptr,   /* output image      */
    const unsigned short            *mask_ptr,   /* correlation mask  */
          short                     pitch,       /* columns in image  */
          short                     width        /* number of outputs */
)
{
  int i, j, k;
  long40 sum;

  for (i=0; i<width; i++) {
    sum = 0;					        /* 40-bit intermediate sum */

    for (j=0; j<3; j++) {
      for (k=0; k<3; k++) {
        sum += (long40) imgin_ptr[j * pitch + i + k] * mask_ptr[j * 3 + k];
      }
    }

    /* Cast to 32-bits for output */
    imgout_ptr[i] = (unsigned int) sum;
  }
}

/* ======================================================================== */
/*  End of file:  IMG_corr_3x3_i16_c16_cn.c                                 */
/* ======================================================================== */

