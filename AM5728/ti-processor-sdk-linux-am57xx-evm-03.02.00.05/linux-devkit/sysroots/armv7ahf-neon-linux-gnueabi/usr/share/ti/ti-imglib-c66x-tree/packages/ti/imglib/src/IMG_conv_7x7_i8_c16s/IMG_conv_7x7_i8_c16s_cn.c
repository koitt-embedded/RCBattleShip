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
/*      IMG_conv_7x7_i8_c16s_cn                                             */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C-callable and can be called as:                    */
/*                                                                          */
/*          void IMG_conv_7x7_i8_c16s_cn                                    */
/*          (                                                               */
/*              const unsigned char  *restrict   imgin_ptr,                 */
/*                    unsigned char  *restrict  imgout_ptr,                 */
/*                             short                 width,                 */
/*                             short                 pitch,                 */
/*              const          short  *restrict    mask_ptr,                */
/*                             short                 shift                  */
/*          )                                                               */
/*                                                                          */
/*      imgin_ptr :   pointer to an input  array of 8 bit pixels            */
/*      imgout_ptr:   pointer to an output array of 8 bit pixels            */
/*      pitch     :   number of columns in the image                        */
/*      width     :   number of output pixels                               */
/*      mask_ptr  :   pointer to 16 bit filter mask.                        */
/*      shift     :   user specified shift amount                           */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      The convolution kernel accepts seven rows of 'pitch' input pixels   */
/*      and produces one row of 'width' output pixels using the input       */
/*      mask of 7 by 7. This convolution performs a point by point mult-    */
/*      iplication of 7 by 7 mask with the input image. The result of 49    */
/*      multiplications are then summed together to produce a 32-bit conv-  */
/*      olution intermediate sum. The user defined shift value is used to   */
/*      shift this convolution sum, down to the byte range and stored in    */
/*      output array. The result being stored is also range limited between */
/*      0 to 255 and will be saturated accordingly. The mask is moved one   */
/*      column at a time, advancing the mask over the entire image until    */
/*      the entire 'width' is covered. The masks are provided as 16-bit     */
/*      signed values. The input image pixels are provided as 8-bit uns-    */
/*      igned pixels and the output pixels will be in 8-bit unsigned.       */
/*                                                                          */
/*      The natural C implementation has no restrictions. The Optimized     */
/*      and IntrinsiC codes has restrictions as noted in the ASSUMPTIONS    */
/*      below.                                                              */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      1. width:          'width' >= 2 and multiple of 2.                  */
/*      2. pitch:          'pitch' >= 'width'                               */
/*      3. Input and Output arrays should not overlap.                      */
/*      4. Output array should be word-aligned.                             */
/*      5. Mask pointer should be half-word aligned.                        */
/*      6. No restrictions on the alignment of Input arrays.                */
/*                                                                          */
/* ======================================================================== */

#pragma CODE_SECTION(IMG_conv_7x7_i8_c16s_cn,   ".text:ansi");


void IMG_conv_7x7_i8_c16s_cn
(
    const unsigned char *restrict  imgin_ptr,
    unsigned char       *restrict imgout_ptr,
    short                              width,
    short                              pitch,
    const          short *restrict  mask_ptr,
    int                                shift
)
{
  int     i,      j,      k;
  int     sum;

  /* Point to the end of the mask to account for rotation */
  const short *mask_rot = &mask_ptr[7*7 - 1];

  /* -------------------------------------------------------------------- */
  /* outer loop to calculate "width" pixel outputs                        */
  /* -------------------------------------------------------------------- */

  for (i=0; i<width; i++) {
    /* ---------------------------------------------------------------- */
    /* Reset the accumulator to the user defined value for one output   */
    /* sample, on the first iteration of the loop.                      */
    /* ---------------------------------------------------------------- */
    sum = 0;

    /* ---------------------------------------------------------------- */
    /*  This loop computes the convolution corresponding to one output  */
    /* ---------------------------------------------------------------- */
    for (j=0; j<7; j++) {
      for (k=0; k<7; k++) {
        sum += imgin_ptr[j * pitch + i + k] * mask_rot[-(j*7 + k)];
      }
    }

    sum = sum >> shift; 
    sum = (sum > 255) ? 255 : (sum < 0 ? 0 : sum);

    imgout_ptr[i] = sum;
  }
}

/* ======================================================================== */
/*  End of file:  IMG_conv_7x7_i8_c16s_cn.c                                 */
/* ======================================================================== */
