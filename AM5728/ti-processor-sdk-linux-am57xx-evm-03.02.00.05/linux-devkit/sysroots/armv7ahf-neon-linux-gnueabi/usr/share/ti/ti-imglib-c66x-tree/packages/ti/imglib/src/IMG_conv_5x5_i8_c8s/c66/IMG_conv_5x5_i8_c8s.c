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
/*      IMG_conv_5x5_i8_c8s                                                 */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C-callable and can be called as:                    */
/*                                                                          */
/*          void IMG_conv_5x5_i8_c8s                                        */
/*          (                                                               */
/*              const unsigned char  *restrict   imgin_ptr,                 */
/*                    unsigned char  *restrict  imgout_ptr,                 */
/*                             short                 width,                 */
/*                             short                 pitch,                 */
/*              const          char  *restrict    mask_ptr,                 */
/*                             short                 shift                  */
/*          )                                                               */
/*                                                                          */
/*      imgin_ptr :   pointer to an input  array of 8 bit pixels            */
/*      imgout_ptr:   pointer to an output array of 8 bit pixels            */
/*      pitch     :   No. of columns in the Input Image.                    */
/*      width     :   No. of output pixels to be calculated.                */
/*      mask_ptr  :   pointer to 8 bit filter mask.                         */
/*      shift     :   user specified shift amount                           */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      The convolution kernel accepts five rows of 'pitch' input pixels    */
/*      and produces one row of 'width' output pixels using the input       */
/*      mask of 5 by 5. This convolution performs a point by point mult-    */
/*      iplication of 5 by 5 mask with the input image. The result of 25    */
/*      multiplications are then summed together to produce a 32-bit conv-  */
/*      olution intermediate sum. The user defined shift value is used to   */
/*      shift this convolution sum, down to the byte range and store in an  */
/*      output array. The result being stored is also range limited between */
/*      0 to 255 and will be saturated accordingly. The mask is moved one   */
/*      column at a time, advancing the mask over the entire image until    */
/*      the entire 'width' is covered. The masks are provided as  8-bit     */
/*      signed values. The input image pixels are provided as 8-bit uns-    */
/*      igned pixels and the output pixels will be in 8-bit unsigned.       */
/*                                                                          */
/*      The natural C implementation has no restrictions. The Optimized     */
/*      and IntrinsiC codes has restrictions as noted in the ASSUMPTIONS    */
/*      below.                                                              */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      1. width:       'width' >= 4 and multiple of 4.                     */
/*      2. pitch:       'pitch' >= 'width'                                  */
/*      3. Output array should be word-aligned.                             */
/*      4. No restrictions on alignment on input data and mask              */
/*      5. Input and Output arrays should not overlap.                      */
/*                                                                          */
/*  COMPATIBILITY                                                           */
/*      This code is compatible with C66x                                   */
/*                                                                          */
/* ======================================================================== */

#pragma CODE_SECTION(IMG_conv_5x5_i8_c8s,   ".text:optimized");


void IMG_conv_5x5_i8_c8s
(
    const unsigned char *restrict  imgin_ptr,
    unsigned char       *restrict imgout_ptr,
    short                              width,
    short                              pitch,
    const char          *restrict   mask_ptr,
    short                              shift
)
{
  int                 i;
  int                 sum,            sum1,           sum2;
  int                 sum3,           sum4,           sum1_temp;
  int                 sum2_temp,      sum3_temp,      sum4_temp;
  int                 row_temp1,      row_temp2,      row_temp3;

  int                 mask24;
  int                 mask3_0,        mask8_5,        mask13_10;
  int                 mask18_15,      mask23_20;
  int                 mask7_4,        mask11_8,       mask15_12,  mask19_16;

  int                 temp1,          temp3,          temp5;
  int                 temp6;

  double              row7_0,         mask7_0,        mask15_8;
  double              mask23_16,      mask_temp;
  double              temp_2;

  unsigned            mask24_24,      mask14_14,      mask9_9;      
  unsigned            mask19_19,      mask4_4;
  unsigned            mask_tmp1,      mask_tmp2;
  unsigned            mask_4x4,       mask_9x4,       mask_14x4;
  unsigned            mask_19x4,      mask_24x4;

  const unsigned char	*in,            *in1,           *in2;
  const unsigned char *in3,           *in4;

  /* -------------------------------------------------------------------- */
  /*  Read the mask elements (reverse them to account for rotation)       */
  /* -------------------------------------------------------------------- */
  mask_temp = _memd8_const((void *) &mask_ptr[17]);   
  mask_tmp1 = _swap4(_lo(mask_temp));
  mask_tmp2 = _swap4(_hi(mask_temp));
  mask7_0   = _itod(_packlh2(mask_tmp1,mask_tmp1),_packlh2(mask_tmp2,mask_tmp2));

  mask_temp = _memd8_const((void *) &mask_ptr[9]);   
  mask_tmp1 = _swap4(_lo(mask_temp));
  mask_tmp2 = _swap4(_hi(mask_temp));
  mask15_8  = _itod(_packlh2(mask_tmp1,mask_tmp1),_packlh2(mask_tmp2,mask_tmp2));

  mask_temp = _memd8_const((void *) &mask_ptr[1]);
  mask_tmp1 = _swap4(_lo(mask_temp));
  mask_tmp2 = _swap4(_hi(mask_temp));
  mask23_16 = _itod(_packlh2(mask_tmp1,mask_tmp1),_packlh2(mask_tmp2,mask_tmp2));

  /* -------------------------------------------------------------------- */
  /*   copy the first 4 mask elemsnts of each row in a separate variable  */
  /* -------------------------------------------------------------------- */
  mask3_0   = _lo(mask7_0);
  mask8_5   = _shrmb  (_lo(mask15_8), _hi(mask7_0));
  mask13_10 = _packlh2(_hi(mask15_8), _lo(mask15_8));
  mask18_15 = _shlmb  (_hi(mask15_8), _lo(mask23_16));
  mask23_20 = _hi(mask23_16);

  /* -------------------------------------------------------------------- */
  /*   pack the 5th mask element of each row in 2 lower 8 bits of int     */
  /* -------------------------------------------------------------------- */
  mask7_4   = _hi(mask7_0);
  mask4_4   = _pack2 (mask7_4, mask7_4);
  mask_4x4  = _packl4(mask4_4, mask4_4);

  mask11_8  = _lo(mask15_8);
  mask9_9   = _packh4(mask11_8, mask11_8);
  mask_9x4  = _packl4(mask9_9,  mask9_9);

  mask15_12 = _hi(mask15_8);
  mask14_14 = _packl4(mask15_12, mask15_12);
  mask_14x4 = _packh4(mask14_14, mask14_14);

  mask19_16 = _lo(mask23_16);
  mask19_19 = _packh4(mask19_16, mask19_16);
  mask_19x4 = _packh4(mask19_19, mask19_19);

  mask24    = mask_ptr[0];
  mask24_24 = _pack2 (mask24,    mask24);
  mask_24x4 = _packl4(mask24_24, mask24_24);

  /* -------------------------------------------------------------------- */
  /*       initialise pointers to the starting of each of the 5 rows      */
  /* -------------------------------------------------------------------- */
  in        = imgin_ptr;
  in1       = in  + pitch;
  in2       = in1 + pitch;
  in3       = in2 + pitch;
  in4       = in3 + pitch;

  /* -------------------------------------------------------------------- */
  /*  Inform the compiler by _nasserts the following:                     */
  /*      a) The output array is word aligned                             */
  /*      b) Filter Mask array is double word aligned                     */
  /*      c) The width is greater than or equal to 6                      */
  /*      d) The width is a multiple of 4.                                */
  /* -------------------------------------------------------------------- */
  _nassert((int)imgout_ptr % 4 == 0);    /* word aligned                  */
  _nassert(width               >= 4);    /* width greater or equal to 4   */
  _nassert(width           % 4 == 0);    /* width is a multiple of 4      */

  /* -------------------------------------------------------------------- */
  /*  Loop is manually unrolled by 4                                      */
  /* -------------------------------------------------------------------- */
  #pragma MUST_ITERATE(1, ,1)

  for (i=0; i<width; i+=4) {
    /* ---------------------------------------------------------------- */
    /* Load 8 pixels that can be used to calculate four output pixels   */
    /* from the 1st row                                                 */
    /* ---------------------------------------------------------------- */
    row7_0      = _memd8_const((void *) &in[i]);
    row_temp1   = _shrmb  (_hi(row7_0), _lo(row7_0));
    row_temp2   = _packlh2(_hi(row7_0), _lo(row7_0));
    row_temp3   = _shlmb  (_lo(row7_0), _hi(row7_0));

    /* ---------------------------------------------------------------- */
    /* Perform the partial dot-product of input pixels with             */
    /* correponding mask for the 1st, 2nd, 3rd and fourth output samples*/
    /* ---------------------------------------------------------------- */
    temp1       = _dotpsu4(mask3_0,  _lo(row7_0));
    temp3       = _dotpsu4(mask3_0,  row_temp1);
    temp5       = _dotpsu4(mask3_0,  row_temp2);
    temp6       = _dotpsu4(mask3_0,  row_temp3);
    temp_2      = _mpysu4 (mask_4x4, _hi(row7_0));

    /* ---------------------------------------------------------------- */
    /*  Calculate sum1, sum2, sum3 and sum4 that holds convolution sums */
    /*  for four outptu pixels                                          */
    /* ---------------------------------------------------------------- */
    sum1_temp   = temp1 + _ext(_lo(temp_2), 16, 16);
    sum2_temp   = temp3 + _ext(_lo(temp_2),  0, 16);
    sum3_temp   = temp5 + _ext(_hi(temp_2), 16, 16);
    sum4_temp   = temp6 + _ext(_hi(temp_2),  0, 16);

    /* ---------------------------------------------------------------- */
    /* Load 8 pixels that can be used to calculate four output pixels   */
    /* from the 2nd row                                                 */
    /* ---------------------------------------------------------------- */
    row7_0      = _memd8_const((void *) &in1[i]);
    row_temp1   = _shrmb  (_hi(row7_0), _lo(row7_0));
    row_temp2   = _packlh2(_hi(row7_0), _lo(row7_0));
    row_temp3   = _shlmb  (_lo(row7_0), _hi(row7_0));

    /* ---------------------------------------------------------------- */
    /* Perform the partial dot-product of input pixels with             */
    /* correponding mask for the 1st, 2nd, 3rd and fourth output samples*/
    /* ---------------------------------------------------------------- */
    temp1       = _dotpsu4(mask8_5,  _lo(row7_0));
    temp3       = _dotpsu4(mask8_5,  row_temp1);
    temp5       = _dotpsu4(mask8_5,  row_temp2);
    temp6       = _dotpsu4(mask8_5,  row_temp3);
    temp_2      = _mpysu4 (mask_9x4, _hi(row7_0));

    /* ---------------------------------------------------------------- */
    /*  Calculate sum1, sum2, sum3 and sum4 that holds convolution sums */
    /*  for four outptu pixels                                          */
    /* ---------------------------------------------------------------- */
    sum1_temp  += temp1 + _ext(_lo(temp_2), 16, 16);
    sum2_temp  += temp3 + _ext(_lo(temp_2),  0, 16);
    sum3_temp  += temp5 + _ext(_hi(temp_2), 16, 16);
    sum4_temp  += temp6 + _ext(_hi(temp_2),  0, 16);

    /* ---------------------------------------------------------------- */
    /* Load 8 pixels that can be used to calculate four output pixels   */
    /* from the 3rd row                                                 */
    /* ---------------------------------------------------------------- */
    row7_0      = _memd8_const((void *) &in2[i]);
    row_temp1   = _shrmb  (_hi(row7_0), _lo(row7_0));
    row_temp2   = _packlh2(_hi(row7_0), _lo(row7_0));
    row_temp3   = _shlmb  (_lo(row7_0), _hi(row7_0));

    /* ---------------------------------------------------------------- */
    /* Perform the partial dot-product of input pixels with             */
    /* correponding mask for the 1st, 2nd, 3rd and fourth output samples*/
    /* ---------------------------------------------------------------- */
    temp1       = _dotpsu4(mask13_10, _lo(row7_0));
    temp3       = _dotpsu4(mask13_10, row_temp1);
    temp5       = _dotpsu4(mask13_10, row_temp2);
    temp6       = _dotpsu4(mask13_10, row_temp3);
    temp_2      = _mpysu4 (mask_14x4, _hi(row7_0));

    /* ---------------------------------------------------------------- */
    /*  Calculate sum1, sum2, sum3 and sum4 that holds convolution sums */
    /*  for four outptu pixels                                          */
    /* ---------------------------------------------------------------- */
    sum1_temp  += temp1 + _ext(_lo(temp_2), 16, 16);
    sum2_temp  += temp3 + _ext(_lo(temp_2),  0, 16);
    sum3_temp  += temp5 + _ext(_hi(temp_2), 16, 16);
    sum4_temp  += temp6 + _ext(_hi(temp_2),  0, 16);

    /* ---------------------------------------------------------------- */
    /* Load 8 pixels that can be used to calculate four output pixels   */
    /* from the 4th row                                                 */
    /* ---------------------------------------------------------------- */
    row7_0      = _memd8_const((void *) &in3[i]);
    row_temp1   = _shrmb  (_hi(row7_0), _lo(row7_0));
    row_temp2   = _packlh2(_hi(row7_0), _lo(row7_0));
    row_temp3   = _shlmb  (_lo(row7_0), _hi(row7_0));

    /* ---------------------------------------------------------------- */
    /* Perform the partial dot-product of input pixels with             */
    /* correponding mask for the 1st, 2nd, 3rd and fourth output samples*/
    /* ---------------------------------------------------------------- */
    temp1       = _dotpsu4(mask18_15, _lo(row7_0));
    temp3       = _dotpsu4(mask18_15, row_temp1);
    temp5       = _dotpsu4(mask18_15, row_temp2);
    temp6       = _dotpsu4(mask18_15, row_temp3);
    temp_2      = _mpysu4 (mask_19x4, _hi(row7_0));

    /* ---------------------------------------------------------------- */
    /*  Calculate sum1, sum2, sum3 and sum4 that holds convolution sums */
    /*  for four outptu pixels                                          */
    /* ---------------------------------------------------------------- */
    sum1_temp  += temp1 + _ext(_lo(temp_2), 16, 16);
    sum2_temp  += temp3 + _ext(_lo(temp_2),  0, 16);
    sum3_temp  += temp5 + _ext(_hi(temp_2), 16, 16);
    sum4_temp  += temp6 + _ext(_hi(temp_2),  0, 16);

    /* ---------------------------------------------------------------- */
    /* Load 8 pixels that can be used to calculate four output pixels   */
    /* from the 5th row                                                 */
    /* ---------------------------------------------------------------- */
    row7_0      = _memd8_const((void *) &in4[i]);
    row_temp1   = _shrmb  (_hi(row7_0), _lo(row7_0));
    row_temp2   = _packlh2(_hi(row7_0), _lo(row7_0));
    row_temp3   = _shlmb  (_lo(row7_0), _hi(row7_0));

    /* ---------------------------------------------------------------- */
    /* Perform the partial dot-product of input pixels with             */
    /* correponding mask for the 1st, 2nd, 3rd and fourth output samples*/
    /* ---------------------------------------------------------------- */
    temp1       = _dotpsu4(mask23_20, _lo(row7_0));
    temp3       = _dotpsu4(mask23_20, row_temp1);
    temp5       = _dotpsu4(mask23_20, row_temp2);
    temp6       = _dotpsu4(mask23_20, row_temp3);
    temp_2      = _mpysu4 (mask_24x4, _hi(row7_0));
    
    /* ---------------------------------------------------------------- */
    /*  Calculate sum1, sum2, sum3 and sum4 that holds convolution sums */
    /*  for four outptu pixels                                          */
    /* ---------------------------------------------------------------- */
    sum1_temp  += temp1 + _ext(_lo(temp_2), 16, 16);
    sum2_temp  += temp3 + _ext(_lo(temp_2),  0, 16);
    sum3_temp  += temp5 + _ext(_hi(temp_2), 16, 16);
    sum4_temp  += temp6 + _ext(_hi(temp_2),  0, 16);

    /* ---------------------------------------------------------------- */
    /* Shift the sums to fall in byte range with user defined value     */
    /* ---------------------------------------------------------------- */
    sum1        = (sum1_temp >> shift);
    sum2        = (sum2_temp >> shift);
    sum3        = (sum3_temp >> shift);
    sum4        = (sum4_temp >> shift);

    /* ---------------------------------------------------------------- */
    /* Check for saturation and pack the 4 bytes to store using amem4   */
    /* ---------------------------------------------------------------- */
    sum         = _spacku4(_spack2(sum4,sum3),_spack2(sum2,sum1));

    _amem4((void*) &imgout_ptr[i]) = sum;
  }
}

/* ======================================================================== */
/*  End of file:  IMG_conv_5x5_i8_c8s.c                                     */
/* ======================================================================== */
