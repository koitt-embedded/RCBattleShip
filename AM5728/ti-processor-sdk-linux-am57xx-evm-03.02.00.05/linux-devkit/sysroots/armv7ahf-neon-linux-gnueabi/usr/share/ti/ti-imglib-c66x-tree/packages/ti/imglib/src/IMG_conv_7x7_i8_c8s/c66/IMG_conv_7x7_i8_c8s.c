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
/*      IMG_conv_7x7_i8_c8s                                                 */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C-callable and can be called as:                    */
/*                                                                          */
/*          void IMG_conv_7x7_i8_c8s                                        */
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
/*      pitch     :   number of columns in the image                        */
/*      width     :   number of output pixels                               */
/*      mask_ptr  :   pointer to 8 bit filter mask.                         */
/*      shift     :   user specified shift amount                           */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      The convolution kernel accepts seven rows of 'pitch' input pixels   */
/*      and produces one row of 'width' output pixels using the input       */
/*      mask of 7 by 7. This convolution performs a point by point mult-    */
/*      iplication of 7 by 7 mask with the input image. The result of 49    */
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
/*      1. width:    'width' >= 2 and multiple of 2.                        */
/*      2. pitch:    'pitch' >= 'width'                                     */
/*      3. Input and Output arrays should not overlap.                      */
/*      4. Output array should be word-aligned                              */
/*      5. no restrictions on the alignment of Input or mask arrays         */
/*                                                                          */
/*  COMPATIBILITY                                                           */
/*      The code is compatible with C66x                                    */
/* ======================================================================== */

#pragma CODE_SECTION(IMG_conv_7x7_i8_c8s,   ".text:optimized");


void IMG_conv_7x7_i8_c8s
(
    const unsigned char *restrict  imgin_ptr,
    unsigned char       *restrict imgout_ptr,
    short                              width,
    short                              pitch,
    const char          *restrict   mask_ptr,
    short                              shift
)
{
  int                 i,              k;  
  int                 sum1,           sum2; 
  int                 sum1_temp,      sum2_temp;
  int                 mask_temp1,     mask_temp2,     mask_temp3;
  int                 mask_tempL;

  int                 temp1,          temp2,          temp3;
  int                 temp4;

  double              row7_0,         mask7_0;

  int                 sum;

  const unsigned char *in; 

  /* -------------------------------------------------------------------- */
  /*  Inform the compiler by _nasserts the following:                     */
  /*      a) The output array is  word aligned                            */
  /*      b) The width is greater than or equal to 2                      */
  /*      c) The width is a multiple of 2.                                */
  /* -------------------------------------------------------------------- */
  _nassert((int)imgout_ptr % 4 == 0);        
  _nassert(width               >= 2);
  _nassert(width           % 2 == 0);   

  /* -------------------------------------------------------------------- */
  /*  Loop is manually unrolled by 2                                      */
  /* -------------------------------------------------------------------- */
  #pragma MUST_ITERATE(1,,1)
  for (i=0; i<width; i+=2) {
    /* ------------------------------------------------------------------- */
    /* Introduce a pointer to point to the ith input image pixel within    */
    /* the iteration. Also zero accumulator values for two output samples  */
    /* ------------------------------------------------------------------- */
    in        = &imgin_ptr[i];
    sum1_temp = 0;
    sum2_temp = 0;

    /*-------------------------------------------------------------------- */
    /*  This loop calculates the convolution sum for a single row. Inform  */
    /*  the compiler that the loop will execute at least five times and    */
    /*  multiple of five from then.                                        */
    /*-------------------------------------------------------------------- */
    #pragma MUST_ITERATE(7, 7, 7);
    #pragma UNROLL(7);
    for (k=0; k<7; k++) {
      /* -------------------------------------------------------------- */
      /* Load 8 pixels that can be used to calculate two output pixels  */
      /* from the kth row                                               */
      /* -------------------------------------------------------------- */
      row7_0     = _memd8_const((void *) &in[k * pitch]);

      /* -------------------------------------------------------------- */
      /*  Load the 7 mask values to be used                             */
      /* -------------------------------------------------------------- */
      mask7_0    = _memd8_const((void *) &mask_ptr[(6-k) * 7]);

      /* -------------------------------------------------------------- */
      /* Make 6th, 7th and 8th mask zero for the first output sample    */
      /* and shift accordingly for calculating the second output sample */
      /* -------------------------------------------------------------- */
      mask_temp3 = _swap4(_packlh2(_lo(mask7_0),_lo(mask7_0)));
      mask_temp2 = _swap4(_packlh2(_hi(mask7_0),_hi(mask7_0))) & 0xffffff00;
      mask_temp1 = (mask_temp3 >> 8) & 0x00ffffff;
      mask_tempL = _shrmb(mask_temp3,mask_temp2);

      /* -------------------------------------------------------------- */
      /* Perform the partial multiplications of input pixel with corre- */
      /* ponding mask for the first and second sample outputs           */
      /* -------------------------------------------------------------- */
      temp1      = _dotpsu4(mask_tempL, _lo(row7_0));
      temp2      = _dotpsu4(mask_temp1, _hi(row7_0));
      temp3      = _dotpsu4(mask_temp2, _lo(row7_0));
      temp4      = _dotpsu4(mask_temp3, _hi(row7_0));

      /* -------------------------------------------------------------- */
      /*  Calculate sum1 and sum2 which holds the convolution sums      */
      /*  sums for two pixels                                           */
      /* -------------------------------------------------------------- */
      sum1_temp += (temp1 + temp2);                             
      sum2_temp += (temp3 + temp4);  

    }
    /* ---------------------------------------------------------------- */
    /* shift the sum to fall in byte range with user defined value      */
    /* ---------------------------------------------------------------- */

    sum1 = (sum1_temp >> shift); 
    sum2 = (sum2_temp >> shift); 

    /* ---------------------------------------------------------------- */
    /* check for saturation and pack the two bytes to store using amem2 */
    /* ---------------------------------------------------------------- */
    sum  = _spacku4 (0,_spack2(sum2,sum1));
    _amem2((void *) &imgout_ptr[i]) = sum;
  }    
}

/* ======================================================================== */
/*  End of file:  IMG_conv_7x7_i8_c8s.c                                     */
/* ======================================================================== */
