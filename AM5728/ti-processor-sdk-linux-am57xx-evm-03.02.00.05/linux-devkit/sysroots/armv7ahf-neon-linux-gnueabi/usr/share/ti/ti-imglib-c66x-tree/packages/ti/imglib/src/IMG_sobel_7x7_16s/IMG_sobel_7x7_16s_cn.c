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
/*      IMG_sobel_7x7_16s_cn                                                */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C-callable and can be called as:                    */
/*                                                                          */
/*      void IMG_sobel_7x7_16s_cn                                           */
/*      (                                                                   */
/*          const short restrict  *in,     // Input image data  //          */
/*                short restrict *out,     // Output image data //          */
/*                short          cols,     // image columns     //          */
/*                short          rows      // Image rows        //          */
/*      )                                                                   */
/*                                                                          */
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
/*  NOTES                                                                   */
/*      The values of the three left-most and three right-most pixels       */
/*      on each line of the output are not well-defined.                    */
/*                                                                          */
/* ======================================================================== */

#pragma CODE_SECTION(IMG_sobel_7x7_16s_cn,   ".text:ansi");

void IMG_sobel_7x7_16s_cn
(
    const short *restrict  in,   /* Input image data   */
          short *restrict out,   /* Output image data  */
          short          cols,   /* image columns      */
          short          rows    /* Image rows         */
)
{    
  int   H,     O,      V;
  
  int   i;
  
  int   i00,   i01,    i02;
  int   i03,   i04,    i05;
  int   i06,   i10,    i11;
  int   i12,   i13,    i14;
  int   i15,   i16,    i20;
  int   i21,   i22,    i23;
  int   i24,   i25,    i26;
  int   i30,   i31,    i32;
  int   i34,   i35,    i36;
  int   i40,   i41,    i42;
  int   i43,   i44,    i45;
  int   i46,   i50,    i51;
  int   i52,   i53,    i54;
  int   i55,   i56,    i60;
  int   i61,   i62,    i63;
  int   i64,   i65,    i66;
  

  for (i=0; i<(cols*(rows-6)-6); i++) {
    /* ---------------------------------------------------------------- */
    /*  Read in the required 7x7 region from the input.                 */
    /* ---------------------------------------------------------------- */
    i00 = in[i               ];
    i01 = in[i             +1];
    i02 = in[i             +2];
    i03 = in[i             +3];
    i04 = in[i             +4];
    i05 = in[i             +5];
    i06 = in[i             +6];

    i10 = in[i +     cols    ];
    i11 = in[i +     cols + 1];
    i12 = in[i +     cols + 2];
    i13 = in[i +     cols + 3];
    i14 = in[i +     cols + 4];
    i15 = in[i +     cols + 5];
    i16 = in[i +     cols + 6];

    i20 = in[i + 2 * cols    ];
    i21 = in[i + 2 * cols + 1];
    i22 = in[i + 2 * cols + 2];
    i23 = in[i + 2 * cols + 3];
    i24 = in[i + 2 * cols + 4];
    i25 = in[i + 2 * cols + 5];
    i26 = in[i + 2 * cols + 6];
   
    i30 = in[i + 3 * cols    ];
    i31 = in[i + 3 * cols + 1];
    i32 = in[i + 3 * cols + 2];
    i34 = in[i + 3 * cols + 4];
    i35 = in[i + 3 * cols + 5];
    i36 = in[i + 3 * cols + 6];

    i40 = in[i + 4 * cols    ];
    i41 = in[i + 4 * cols + 1];
    i42 = in[i + 4 * cols + 2];
    i43 = in[i + 4 * cols + 3];
    i44 = in[i + 4 * cols + 4];
    i45 = in[i + 4 * cols + 5];
    i46 = in[i + 4 * cols + 6];

    i50 = in[i + 5 * cols    ];
    i51 = in[i + 5 * cols + 1];
    i52 = in[i + 5 * cols + 2];
    i53 = in[i + 5 * cols + 3];
    i54 = in[i + 5 * cols + 4];
    i55 = in[i + 5 * cols + 5];
    i56 = in[i + 5 * cols + 6];

    i60 = in[i + 6 * cols    ];
    i61 = in[i + 6 * cols + 1];
    i62 = in[i + 6 * cols + 2];
    i63 = in[i + 6 * cols + 3];
    i64 = in[i + 6 * cols + 4];
    i65 = in[i + 6 * cols + 5];
    i66 = in[i + 6 * cols + 6];    

    /* ---------------------------------------------------------------- */
    /*  Apply horizontal and vertical filter masks.  The final filter   */
    /*  output is the sum of the absolute values of these filters.      */
    /* ---------------------------------------------------------------- */
    H = -     i00 -  i01 - i02 - 2 * i03 - i04 - i05 - i06
        -     i10 -  i11 - i12 - 2 * i13 - i14 - i15 - i16
        -     i20 -  i21 - i22 - 2 * i23 - i24 - i25 - i26

        +     i40 +  i41 + i42 + 2 * i43 + i44 + i45 + i46
        +     i50 +  i51 + i52 + 2 * i53 + i54 + i55 + i56
        +     i60 +  i61 + i62 + 2 * i63 + i64 + i65 + i66;
    
    V = -     i00 -     i01 -     i02    +      i04 +     i05 +   i06
        -     i10 -     i11 -     i12    +      i14 +     i15 +   i16
        -     i20 -     i21 -     i22    +      i24 +     i25 +   i26
        - 2 * i30 - 2 * i31 - 2 * i32    +  2 * i34 + 2 * i35 + 2*i36
        -     i40 -     i41 -     i42    +      i44 +     i45 +   i46
        -     i50 -     i51 -     i52    +      i54 +     i55 +   i56
        -     i60 -     i61 -     i62    +      i64 +     i65 +   i66;

    O = abs(H) + abs(V);

    /* ---------------------------------------------------------------- */
    /*  Clamp to 16-bit range.  The output is always positive due to    */
    /*  the absolute value, so we only need to check for overflow.      */
    /* ---------------------------------------------------------------- */
    O = (O > 32767) ? 32767 : O;

    /* ---------------------------------------------------------------- */
    /*  Store it.                                                       */
    /* ---------------------------------------------------------------- */
    out[i + 3] = O;
  }
}

/* ======================================================================== */
/*  End of file:  IMG_sobel_7x7_16s_cn.c                                    */
/* ======================================================================== */
