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
/*      IMG_corr_3x3_i16s_c16s_cn                                           */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C-callable and can be called as:                    */
/*                                                                          */
/*          void IMG_corr_3x3_i16s_c16s_cn                                  */
/*          (                                                               */
/*              const short      *restrict  imgin_ptr,                      */
/*                    int        *restrict imgout_ptr,                      */
/*                    short                     width,                      */
/*                    short                     pitch,                      */
/*              const short      *restrict   mask_ptr,                      */
/*                    short                     shift,                      */
/*                    int                       round                       */
/*          )                                                               */
/*                                                                          */
/*      imgin_ptr :  pointer to an input  array of 16 bit pixels            */
/*      imgout_ptr:  pointer to an output array of 32 bit pixels            */
/*      width     :  number of output pixels                                */
/*      pitch     :  number of columns in the input image                   */
/*      mask_ptr  :  pointer to 16 bit filter mask.                         */
/*      shift     :  user specified shift amount                            */
/*      round     :  user specified round value                             */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      The correlation kernel accepts 3 rows of 'pitch' input pixels and   */
/*      produces one row of 'width' output pixels using the input mask of   */
/*      3x3. This correlation performs a point by point multiplications     */
/*      of 3x3 mask with the input image. The result of the 9 multiplic-    */
/*      ations are then summed together to produce a 40-bit sum which is    */
/*      added to user specified round value and then stored in an output    */
/*      array. Overflow and Saturation of the accumulated sum is not han-   */
/*      dled. However assumptions are made on filter gain to avoid them.    */
/*      The mask is moved one column at a time, advancing the mask over     */
/*      the entire image until the entire 'width' is covered. The masks     */
/*      are provided as 16-bit signed values and the input image pixels     */
/*      are provided as 16-bit  signed values and the output pixels will    */
/*      be 32-bit signed.The image mask to be correlated is typically part  */
/*      of the input image or another image.                                */
/*                                                                          */
/*      The natural C implementation has no restrictions. The Optimized     */
/*      and Intrinsic codes has restrictions as noted in the ASSUMPTIONS    */
/*      below.                                                              */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      1. width:   'width' >=4 and a multiple of 4.                        */
/*      2. pitch:   'pitch' >= 'width'                                      */
/*      3. Input and Output arrays should not overlap                       */
/*      4. Output array should be double word aligned.                      */
/*      5. Input and mask arrays should be half-word aligned.               */
/*      6. Internal accuracy of the computations is 40 bits. To ensure      */
/*         correctness on a 16 bit input data, the maximum permissible      */
/*         filter gain in terms of bits is 24-bits i.e. the cumulative sum  */
/*         of the absolute values of the filter coefficients should not     */
/*         exceed 2^24 - 1.                                                 */
/*      7. Shift is appropriate to produce a 32-bit result.                 */
/*      8. Range of filter co-efficients is -32767 to 32767.                */
/*                                                                          */
/* ======================================================================== */

#ifdef __TI_INT40_T__
  typedef __int40_t long40;
#else
  typedef long long long40;
#endif

#pragma CODE_SECTION(IMG_corr_3x3_i16s_c16s_cn,   ".text:ansi");

void IMG_corr_3x3_i16s_c16s_cn
(
    const  short    *restrict  imgin_ptr,
           int      *restrict imgout_ptr,
           short                   width,
           short                   pitch,
    const  short    *restrict   mask_ptr,
           short                   shift,
           int                     round
)
{
  int     i, j, k;
  long40  sum;
  int     res;

  for (i=0; i<width; i++) {
    sum = round;

    /* ---------------------------------------------------------------- */
    /*  This loop computes the convolution sum corresponding to 1 pixel */
    /* ---------------------------------------------------------------- */
    for (j=0; j<3; j++) {
      for (k=0; k<3; k++) {
        sum  += imgin_ptr[ j * pitch + i + k] * mask_ptr[j * 3 + k];
      }
    }

    /* ---------------------------------------------------------------- */
    /*  Shift the sums appropriately to avoid overflow                  */
    /* ---------------------------------------------------------------- */
    res           = (sum >> shift); 
    imgout_ptr[i] =  (int) res;
  }
}

/* ======================================================================== */
/*  End of file:  IMG_corr_3x3_i16s_c16s_cn.c                               */
/* ======================================================================== */
