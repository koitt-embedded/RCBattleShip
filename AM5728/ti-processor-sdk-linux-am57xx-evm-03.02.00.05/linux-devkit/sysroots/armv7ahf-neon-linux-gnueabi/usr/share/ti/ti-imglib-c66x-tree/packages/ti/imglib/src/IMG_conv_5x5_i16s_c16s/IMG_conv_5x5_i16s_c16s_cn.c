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
/*      IMG_conv_5x5_i16s_c16s_cn                                           */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C-callable and can be called as:                    */
/*                                                                          */
/*          void IMG_conv_5x5_i16s_c16s_cn                                  */
/*          (                                                               */
/*              const short        *restrict   imgin_ptr,                   */
/*                    short        *restrict  imgout_ptr,                   */
/*                    short                        width,                   */
/*                    short                        pitch,                   */
/*              const short        *restrict    mask_ptr,                   */
/*                    short                        shift                    */
/*          )                                                               */
/*                                                                          */
/*      imgin_ptr :   pointer to an input  array of 16 bit pixels           */
/*      imgout_ptr:   pointer to an output array of 16 bit pixels           */
/*      width     :   number of output pixels                               */
/*      pitch     :   number of columns in the image                        */
/*      mask_ptr  :   pointer to 16 bit filter mask.                        */
/*      shift     :   user specified shift amount                           */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      The convolution kernel accepts five rows of 'pitch' input pixels    */
/*      and produces one row of 'width' output pixels using the input       */
/*      mask of 5 by 5. This convolution performs a point by point mult-    */
/*      iplication of 5 by 5 mask with the input image. The result of 25    */
/*      multiplications are then summed together to produce a 32-bit conv-  */
/*      olution intermediate sum. Overflow while accumulation is not hand-  */
/*      led. However assumptions are made on filter gain to avoid overflow. */
/*      The user defined shift value is used to shift this convolution sum  */
/*      down to the short range and store in an output array. The result    */
/*      being stored is also range limited between -32768 to 32767 and will */
/*      be saturated accordingly. The mask is moved one column at a time,   */
/*      advancing the mask over the entire image until the entire 'width'   */
/*      is covered.The input, output image pixels and the masks are         */
/*      provided as 16-bit signed values.                                   */
/*                                                                          */
/*      The natural C implementation has no restrictions. The Optimized     */
/*      and IntrinsiC codes has restrictions as noted in the ASSUMPTIONS    */
/*      below.                                                              */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      1. width:   'width' >=2 and a multiple of 2.                        */
/*      2. pitch:   'pitch' >= 'width'.                                     */
/*      3. Input and output arrays should not overlap                       */
/*      4. Output array should be word aligned                              */
/*      5. The mask and input arrays should be half-word aligned.           */
/*      6. Internal accuracy of the computations is 32 bits. To ensure      */
/*         correctness on a 16 bit input data, the maximum permissible      */
/*         filter gain in terms of bits is 16-bits i.e. the cumulative sum  */
/*         of the absolute values of the filter coefficients should not     */
/*         exceed 2^16 - 1.                                                 */
/*                                                                          */
/* ======================================================================== */

#pragma CODE_SECTION(IMG_conv_5x5_i16s_c16s_cn,   ".text:ansi");


void IMG_conv_5x5_i16s_c16s_cn
(
    const short   *restrict    imgin_ptr,
          short   *restrict   imgout_ptr,
          short                    width,
          short                    pitch,
    const short   *restrict     mask_ptr,
          short                    shift
)
{
  int    i, j, k; 
  int    sum;
  int    acc;

  /* Point to the end of the mask to account for rotation */
  const short *mask_rot = &mask_ptr[5*5 - 1];

  for (i=0; i<width; i++) {
    acc = 0;

    /* ---------------------------------------------------------------- */
    /*  This loop computes the convolution sum corresponding to a pixel */
    /* ---------------------------------------------------------------- */
    for (j=0; j<5; j++) {
      for (k=0; k<5; k++) {
        acc += imgin_ptr[j * pitch + i + k] * mask_rot[-(j*5 + k)];
      }
    }

    /* ---------------------------------------------------------------- */
    /* Shift the int sum by user-defined value to fall in short range   */
    /* ---------------------------------------------------------------- */
    sum = (acc >> shift); 

    /* ---------------------------------------------------------------- */
    /* Range limit the convolution sum to -32768,,32767                 */
    /* ---------------------------------------------------------------- */
    sum = (sum >  32767) ?  32767 : (sum < -32768 ? -32768 : sum);

    /* ---------------------------------------------------------------- */
    /* Store the result in an output array                              */
    /* ---------------------------------------------------------------- */
    imgout_ptr[i] = sum;
  }
}

/* ======================================================================== */
/*  End of file:  IMG_conv_5x5_i16s_c16s_cn.c                               */
/* ======================================================================== */
