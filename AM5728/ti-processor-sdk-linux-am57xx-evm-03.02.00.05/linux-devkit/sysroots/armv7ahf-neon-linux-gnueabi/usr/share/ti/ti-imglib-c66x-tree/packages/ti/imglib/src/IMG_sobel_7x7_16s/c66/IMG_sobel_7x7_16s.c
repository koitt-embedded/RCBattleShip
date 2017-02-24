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
/*      IMG_sobel_7x7_16s                                                   */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C-callable and can be called as:                    */
/*                                                                          */
/*      void IMG_sobel_7x7_16s                                              */
/*      (                                                                   */
/*          const short restrict  *in,     // Input image data  //          */
/*                short restrict *out,     // Output image data //          */
/*                short          cols,     // image columns     //          */
/*                short          rows      // Image rows        //          */
/*      )                                                                   */
/*      The sobel_7x7 filter is applied to the input image.  The input      */
/*      image dimensions are given by the arguments 'cols' and 'rows'.      */
/*      The output image is 'cols' pixels wide and 'rows - 6' pixels        */
/*      tall.                                                               */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      To see how the implementation is going to work on the input         */
/*      buffer, lets imagine we have the following input buffer:            */
/*      lets imagine we have the following input buffer:                    */
/*                                                                          */
/*              yyyyyyyyyyyyyyyy                                            */
/*              yyyyyyyyyyyyyyyy                                            */
/*              yyyyyyyyyyyyyyyy                                            */
/*              yyyxxxxxxxxxxyyy                                            */
/*              yyyxxxxxxxxxxyyy                                            */
/*              yyyxxxxxxxxxxyyy                                            */
/*              yyyxxxxxxxxxxyyy                                            */
/*              yyyyyyyyyyyyyyyy                                            */
/*              yyyyyyyyyyyyyyyy                                            */
/*              yyyyyyyyyyyyyyyy                                            */
/*                                                                          */
/*      The output buffer would be:                                         */
/*                                                                          */
/*              tttXXXXXXXXXXzzz                                            */
/*              zzzXXXXXXXXXXzzz                                            */
/*              zzzXXXXXXXXXXzzz                                            */
/*              zzzXXXXXXXXXXttt                                            */
/*                                                                          */
/*      Where:                                                              */
/*                                                                          */
/*          X = sobel(x)    The algorithm is applied to that pixel.         */
/*                          The correct output is obtained, the data        */
/*                          around the pixels we work on is used            */
/*                                                                          */
/*          t               Whatever was in the output buffer in that       */
/*                          position is kept there.                         */
/*                                                                          */
/*          z = sobel(y)    The algorithm is applied to that pixel.         */
/*                          The output is not meaningful, because the       */
/*                          necessary data to process the pixel is not      */
/*                          available.  This is because for each output     */
/*                          pixel we need input pixels from the right and   */
/*                          from the left of the output pixel.  But this    */
/*                          data doesn't exist.                             */
/*                                                                          */
/*      This means that we will only process (rows-6) lines.  Then, we      */
/*      will process all the pixels inside each line. Even though the       */
/*      results for the first 3 and last 3 pixels in each line will not     */
/*      be relevant, it makes the control much simpler and ends up          */
/*      saving cycles.                                                      */
/*                                                                          */
/*      Also the first 3 pixels in the first processed line and the         */
/*      last 3 pixels in the last processed line will not be computed.      */
/*      It is not necessary, since the results would be bogus.              */
/*                                                                          */
/*      The following horizontal and vertical masks that are                */
/*      applied to the input buffer to obtain one output pixel.             */
/*                                                                          */
/*          Horizontal:                                                     */
/*              -1 -1 -1 -2 -1 -1 -1                                        */
/*              -1 -1 -1 -2 -1 -1 -1                                        */
/*              -1 -1 -1 -2 -1 -1 -1                                        */
/*               0  0  0  0  0  0  0                                        */
/*               1  1  1  2  1  1  1                                        */
/*               1  1  1  2  1  1  1                                        */
/*               1  1  1  2  1  1  1                                        */
/*                                                                          */
/*          Vertical:                                                       */
/*              -1 -1 -1  0  1  1  1                                        */
/*              -1 -1 -1  0  1  1  1                                        */
/*              -1 -1 -1  0  1  1  1                                        */
/*              -2 -2 -2  0  2  2  2                                        */
/*              -1 -1 -1  0  1  1  1                                        */
/*              -1 -1 -1  0  1  1  1                                        */
/*              -1 -1 -1  0  1  1  1                                        */
/*                                                                          */
/*      The natural C implementation has no restrictions. The Optimized     */
/*      and IntrinsiC codes have restrictions as noted in the ASSUMPTIONS   */
/*      below.                                                              */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      1. cols :     'cols' >  7 and multiple of 2.                        */
/*      2. rows :     'rows' >= 7.                                          */
/*      3. cols * (rows - 6) - 6 should be greater than or equal to 2.      */
/*      4. Input and output arrays do not overlap.                          */
/*      5. Input and output arrays should be half-word aligned.             */
/*                                                                          */
/*  TECHNIQUE                                                               */
/*      The loop is unrolled twice and 2 outputs are calculated every       */
/*      iteration. The horizontal and vertical masks have sub-blocks.       */
/*      where the absolute value of the mask elements are same. These       */
/*      sub-blocks are applied on image only once and are added/subtracted  */
/*      to both horizontal and vertical components,thus improving           */
/*      performance.                                                        */
/*                                                                          */
/*  NOTES                                                                   */
/*      The values of the three left-most and three right-most pixels       */
/*      on each line of the output are not well-defined.                    */
/*                                                                          */
/* ======================================================================== */

#pragma CODE_SECTION(IMG_sobel_7x7_16s,   ".text:optimized");

void IMG_sobel_7x7_16s
(
    const short *restrict  in,   /* Input image data   */
          short *restrict out,   /* Output image data  */
          short          cols,   /* image columns      */
          short          rows    /* Image rows         */
)
{
  int  i;

  long long    row1_3210,     row2_3210,     row3_3210;
  long long    row4_3210,     row5_3210,     row6_3210;
  long long    row7_3210;

  long long    dp1,           dp2,           dp3;
  long long    dp4,           dp5,           dp6;
  long long    dp7;
  
  double       dbl3,          dbl4,          dbl5;
  
  
  int          v1,            h1,            v2;
  int          h2,            o1,            o2;
  
  int          lt1_3x3,       lt2_3x3,       lb1_3x3;
  int          lb2_3x3,       rt1_3x3,       rt2_3x3;
  int          rb1_3x3,       rb2_3x3,       col1_3;

  int          col2_3,        dp8,           dp9;
  int          dp10,          dp11;

  long long    dpk1,          dpk2,          dpk3;
  long long    dp12,          dp13;

  int          ones,          twos,          neg_ones;
  int          mask;

  
  /* -------------------------------------------------------------------- */
  /*  Uninitialise pointers to point to staring of each of the 7 rows     */
  /* -------------------------------------------------------------------- */
  const short *restrict in0;
  const short *restrict in1;
  const short *restrict in2;
  const short *restrict in3;
  const short *restrict in4;
  const short *restrict in5;
  const short *restrict in6;
  
  _nassert(cols                  >  7); /* cols must be greater than 2.   */
  _nassert(cols % 2              == 0); /* cols must be a multiple of 2.  */
  _nassert(rows                  >= 7); /* rows must be atleast 7         */
  _nassert(cols * (rows - 6) - 6 >= 2); /* aleast 2 outputs are computed  */

  /* -------------------------------------------------------------------- */
  /*  initialise pointers to point to staring of each of the 7 rows       */
  /* -------------------------------------------------------------------- */
  in0 = in;
  in1 = in0 + cols;
  in2 = in1 + cols;
  in3 = in2 + cols;
  in4 = in3 + cols;
  in5 = in4 + cols;
  in6 = in5 + cols;
  
  /* -------------------------------------------------------------------- */
  /*                  initialise multiplier elements                      */
  /* -------------------------------------------------------------------- */
  ones     = 0x00010001;
  twos     = 0x00020002;
  neg_ones = 0xFFFFFFFF; 
  mask     = 0xFF010101;  

  for (i=0; i<((rows-6)*cols)-6; i+=2) {
    /* ---------------------------------------------------------------- */
    /*   load the first 4 pixels(double word) of each row               */
    /* ---------------------------------------------------------------- */
    row1_3210 = _mem8_const(in0);
    row2_3210 = _mem8_const(in1);
    row3_3210 = _mem8_const(in2);
    row4_3210 = _mem8_const(in3);
    row5_3210 = _mem8_const(in4);
    row6_3210 = _mem8_const(in5);
    row7_3210 = _mem8_const(in6);

    /* ---------------------------------------------------------------- */
    /* dp1,dp2... are dotproducts obtained from multiplying the first 2 */
    /* columns of image with horizontal or vertical mask as both are    */
    /* same except for the 4th row.                                     */
    /* ---------------------------------------------------------------- */
    dp1       = _ddotpl2(row1_3210, neg_ones);
    dp2       = _ddotpl2(row2_3210, neg_ones);
    dp3       = _ddotpl2(row3_3210, neg_ones);

    dp4       = _ddotpl2(row4_3210, twos);

    dp5       = _ddotpl2(row5_3210, ones);
    dp6       = _ddotpl2(row6_3210, ones);
    dp7       = _ddotpl2(row7_3210, ones);

    
    /* ---------------------------------------------------------------- */
    /* Pack the 1st and 2nd row of 3rd and 4th column into dpk1,        */
    /* pack 6th and 7th row pixels of the 3rd and 4th column into dpk2  */
    /* using dpack2 this enables use of dotp2 on result.                */
    /* ---------------------------------------------------------------- */
    dpk1      = _dpack2(_hill(row1_3210),_hill(row2_3210));
    dpk2      = _dpack2(_hill(row6_3210),_hill(row7_3210));
    
    dp8       = _dotp2(_loll(dpk1) , ones);
    dp9       = _dotp2(_hill(dpk1) , ones);
    dp10      = _dotp2(_loll(dpk2) , ones);
    dp11      = _dotp2(_hill(dpk2) , ones);
 
    dbl3      = _mpy2(_hill(row3_3210), ones);
    dbl4      = _mpy2(_hill(row4_3210), twos);
    dbl5      = _mpy2(_hill(row5_3210), ones);

    /* ================================================================ */
    /*                                                                  */
    /* Calculated sum-of-products for the 3x3 regions that are common   */
    /* both the masks(only the absolute values).                        */
    /* A1 B1 C1 correspond to first 3 pixels of row 1 of image block    */
    /*                                                                  */
    /* These sum of products are                                        */
    /*                                                                  */ 
    /* rt1 = right top block  is the result of applying  first 3 rows   */
    /*       and columns of either of the masks on the image pixels     */
    /*       for calculation of first output pixel.                     */
    /*                                                                  */
    /*       -1 * A1   -1 * B1  -1 * C1                                 */
    /*       -1 * A2   -1 * B2  -1 * C2                                 */
    /*       -1 * A3   -1 * B3  -1 * C3                                 */
    /*                                                                  */
    /*                                                                  */
    /* rb1 = right bottom block for calculation of first output pixel   */
    /*                                                                  */
    /*        1 * A5    1 * B5   1 * C5                                 */
    /*        1 * A6    1 * B6   1 * C6                                 */
    /*        1 * A7    1 * B7   1 * C7                                 */
    /*                                                                  */
    /* Similarly there are rt2 and rb2 for calculation of second        */
    /* output pixel.                                                    */
    /*                                                                  */
    /*  it is seen that that the absolute value coefficients are same   */
    /*  The sign part of it can be implemented by add/subtract of the   */
    /*  resultant sum-of-products.                                      */
    /*                                                                  */
    /* ================================================================ */
    lt1_3x3   = _loll(dp1) + _loll(dp2) + _loll(dp3) - dp8  - _lo(dbl3) ;
    lt2_3x3   = _hill(dp1) + _hill(dp2) + _hill(dp3) - dp9  - _hi(dbl3);
    lb1_3x3   = _loll(dp5) + _loll(dp6) + _loll(dp7) + dp10 + _lo(dbl5);
    lb2_3x3   = _hill(dp5) + _hill(dp6) + _hill(dp7) + dp11 + _hi(dbl5);

    /* ---------------------------------------------------------------- */
    /*       calculate for cental column of the horizontal mask         */
    /* ---------------------------------------------------------------- */  
    col1_3    = _hi(dbl5) + dp11 - dp9 - _hi(dbl3);   

    /* ---------------------------------------------------------------- */
    /*  h1, h2 are horizontal components and v1 v2 are vertical         */
    /*  components.                                                     */
    /* ---------------------------------------------------------------- */  
    h1        = lt1_3x3 + lb1_3x3 + (col1_3 << 1); 
    h2        = lt2_3x3 + lb2_3x3 ;
    v1        = lt1_3x3 - lb1_3x3 - _loll(dp4) - _lo(dbl4); 
    v2        = lt2_3x3 - lb2_3x3 - _hill(dp4) - _hi(dbl4) ;

    /* ---------------------------------------------------------------- */
    /*   load the next 4 pixels(double word) of each row                */
    /* ---------------------------------------------------------------- */
    row1_3210 =  _mem8_const(in0 + 4);
    row2_3210 =  _mem8_const(in1 + 4);
    row3_3210 =  _mem8_const(in2 + 4);
    row4_3210 =  _mem8_const(in3 + 4);
    row5_3210 =  _mem8_const(in4 + 4);
    row6_3210 =  _mem8_const(in5 + 4);
    row7_3210 =  _mem8_const(in6 + 4);

    /* ---------------------------------------------------------------- */
    /* Pack the 1st and 2nd row of 5th and 6th column into dpk1,        */
    /* Pack the 3st and 5nd row of 5th and 6th column into dpk3,        */
    /* pack 6th and 7th row pixels of the 5th and 6th column into dpk2  */
    /* using dpack2 this enables use of dotp2 on result.                */
    /* ---------------------------------------------------------------- */
    dpk1      =  _dpack2(_loll(row1_3210),_loll(row2_3210));
    dpk2      =  _dpack2(_loll(row6_3210),_loll(row7_3210));
    dpk3      =  _dpack2(_loll(row3_3210),_loll(row5_3210)); 

    dp8       =  _dotp2(_loll(dpk1) , ones);
    dp9       =  _dotp2(_hill(dpk1) , ones);
    dp10      =  _dotp2(_loll(dpk2) , ones);
    dp11      =  _dotp2(_hill(dpk2) , ones);

    /* ---------------------------------------------------------------- */
    /* The higher 16 bits of the second parameter in _ddotp4 constitute */
    /* 2 horizontal mask values for 3rd column and lower 16 bits        */
    /* constitute 2 vertical mask values for 3rd column.                */
    /* ---------------------------------------------------------------- */  
    dp12      =  _ddotp4(_loll(dpk3) , mask);
    dp13      =  _ddotp4(_hill(dpk3) , mask);
    
    /* ---------------------------------------------------------------- */
    /*         Apply the cenrtal row of the vertical mask               */
    /* ---------------------------------------------------------------- */  
    dbl4      =  _mpy2(_loll(row4_3210) , twos);
    dp4       =  _ddotph2(row4_3210 ,     twos);
     
    dp1       =  _ddotph2(row1_3210 , neg_ones);
    dp2       =  _ddotph2(row2_3210 , neg_ones);
    dp3       =  _ddotph2(row3_3210 , neg_ones);

    dp5       =  _ddotph2(row5_3210 , ones);
    dp6       =  _ddotph2(row6_3210 , ones);
    dp7       =  _ddotph2(row7_3210 , ones);

    /* ================================================================ */
    /*                                                                  */
    /* Calculated sum-of-products for the 3x3 regions that are common   */
    /* both the masks(only the absolute values).                        */
    /* E1 F1 G1 correspond to the last 3 pixels of row 1 of image block */
    /*                                                                  */
    /* These sum of products are                                        */
    /*                                                                  */ 
    /* rt1 = right top block  is the result of applying  first 3 rows   */
    /*       and columns of either of the masks on the image pixels     */
    /*       for calculation of first output pixel                      */
    /*                                                                  */
    /*       -1 * E1   -1 *F1  -1 * G1                                  */
    /*       -1 * E2   -1 *F2  -1 * G2                                  */
    /*                 -1 *F3  -1 * G3                                  */
    /*                                                                  */
    /*                                                                  */
    /* rb1 = right bottom block for calculation first output pixel      */
    /*                                                                  */
    /*       +1 * E5   +1 *F5  +1 * G5                                  */
    /*       +1 * E6   +1 *F6  +1 * G6                                  */
    /*                 +1 *F7  +1 * G7                                  */
    /*                                                                  */
    /* Similarly there are rt2 and rb2 for calculation of second        */
    /* output pixels.                                                   */
    /*                                                                  */
    /*  it is seen that that the absolute value coefficients are same   */
    /*  The sign part of it can be implemented by add/subtract of the   */
    /*  resultant sum-of-products.                                      */
    /*                                                                  */
    /* ================================================================ */
    rt1_3x3   =  _loll(dp1) + _loll(dp2) + _loll(dp3) - dp8 ;
    rt2_3x3   =  _hill(dp1) + _hill(dp2) + _hill(dp3) - dp9 ;
    rb1_3x3   =  _loll(dp5) + _loll(dp6) + _loll(dp7) + dp10;   
    rb2_3x3   =  _hill(dp5) + _hill(dp6) + _hill(dp7) + dp11;

    col2_3    =  dp10 - dp8 + _hill(dp12);

    /* ---------------------------------------------------------------- */
    /*  h1, h2 are horizontal components and v1 v2 are vertical         */
    /*  components.                                                     */
    /* ---------------------------------------------------------------- */
    h1       +=  rb1_3x3 + rt1_3x3 + _hill(dp12); 
    h2       +=  rb2_3x3 + rt2_3x3 + (col2_3 << 1) + _hill(dp13);
    v1       +=  rb1_3x3 - rt1_3x3 + _loll(dp4) + _lo(dbl4) + _loll(dp12); 
    v2       +=  rb2_3x3 - rt2_3x3 + _hill(dp4) + _hi(dbl4) + _loll(dp13);

    /* ---------------------------------------------------------------- */
    /*              update the input pointers                           */
    /* ---------------------------------------------------------------- */
    in0       =  in0 + 2;
    in1       =  in1 + 2;
    in2       =  in2 + 2;
    in3       =  in3 + 2;
    in4       =  in4 + 2;
    in5       =  in5 + 2;
    in6       =  in6 + 2;

    /* ---------------------------------------------------------------- */
    /*   calculate the sum of absolute values of  the horizontal and    */
    /*   vertical components                                            */
    /* ---------------------------------------------------------------- */
    o1        = _abs(v1) + _abs(h1);
    o2        = _abs(v2) + _abs(h2); 

    /* ---------------------------------------------------------------- */
    /*   saturate and pack the 2 output values to be stored in the      */
    /*   output array                                                   */
    /* ---------------------------------------------------------------- */
    _mem4(&(out[i + 3])) = _spack2(o2 , o1); 
  }
}

/* ======================================================================== */
/*  End of file:  IMG_sobel_7x7_16s.c                                       */
/* ======================================================================== */
