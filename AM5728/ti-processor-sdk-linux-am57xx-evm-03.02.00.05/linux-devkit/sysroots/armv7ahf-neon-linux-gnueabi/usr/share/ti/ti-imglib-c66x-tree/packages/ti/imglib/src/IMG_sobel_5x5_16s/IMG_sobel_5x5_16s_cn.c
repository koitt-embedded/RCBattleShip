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
/*      IMG_sobel_5x5_16s_cn                                                */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C-callable and can be called as:                    */
/*                                                                          */
/*      void IMG_sobel_5x5_16s_cn                                           */
/*      (                                                                   */
/*          const short restrict  *in,     // Input image data  //          */
/*                short restrict *out,     // Output image data //          */
/*                short          cols,     // image columns     //          */
/*                short          rows      // Image rows        //          */
/*      )                                                                   */
/*                                                                          */
/*      The sobel filter is applied to the input image.  The input image    */
/*      dimensions are given by the arguments 'cols' and 'rows'.  The       */
/*      output image is 'cols' pixels wide and 'rows - 4' pixels tall.      */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*                                                                          */
/*      To see how the implementation is going to work on the input         */
/*      buffer, lets imagine we have the following input buffer:            */
/*      lets imagine we have the following input buffer:                    */
/*                                                                          */
/*              yyyyyyyyyyyyyyyy                                            */
/*              yyyyyyyyyyyyyyyy                                            */
/*              yyxxxxxxxxxxxxyy                                            */
/*              yyxxxxxxxxxxxxyy                                            */
/*              yyxxxxxxxxxxxxyy                                            */
/*              yyxxxxxxxxxxxxyy                                            */
/*              yyyyyyyyyyyyyyyy                                            */
/*              yyyyyyyyyyyyyyyy                                            */
/*                                                                          */
/*      The output buffer would be:                                         */
/*                                                                          */
/*              ttXXXXXXXXXXXXzz                                            */
/*              zzXXXXXXXXXXXXzz                                            */
/*              zzXXXXXXXXXXXXzz                                            */
/*              zzXXXXXXXXXXXXtt                                            */
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
/*      This means that we will only process (rows-4) lines.  Then, we      */
/*      will process all the pixels inside each line. Even though the       */
/*      results for the first and last pixels in each line will not         */
/*      be relevant, it makes the control much simpler and ends up          */
/*      saving cycles.                                                      */
/*                                                                          */
/*      Also the fist two pixels in the first processed line and the        */
/*      last two pixel in the last processed line will not be computed.     */
/*      It is not necessary, since the results would be bogus, and          */
/*      not computing them saves some time.                                 */
/*                                                                          */
/*      The following horizontal and vertical masks that are                */
/*      applied to the input buffer to obtain one output pixel.             */
/*                                                                          */
/*          Horizontal:                                                     */
/*              -1  -4  -6  -4  -1                                          */
/*              -2  -8 -12  -8  -2                                          */
/*               0   0   0   0   0                                          */
/*               2   8  12   8   2                                          */
/*               1   4   6   4   1                                          */
/*                                                                          */
/*          Vertical:                                                       */
/*               1   2   0  -2  -1                                          */
/*               4   8   0  -8  -4                                          */
/*               6  12   0 -12  -6                                          */
/*               4   8   0  -8  -4                                          */
/*               1   2   0  -2  -1                                          */
/*                                                                          */
/*                                                                          */
/*      The natural C implementation has no restrictions. The Optimized     */
/*      and IntrinsiC codes have restrictions as noted in the ASSUMPTIONS   */
/*      bellow.                                                             */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      1. cols :     'cols' >  5 and multiple of 2.                        */
/*      2. rows :     'rows' >= 5.                                          */
/*      3. cols * (rows - 4) - 4 should be greater than or equal to 2.      */
/*      4. Input and output arrays should not overlap.                      */
/*      5. Input and Output arrays do not have alignment requirements.      */
/*                                                                          */
/*  NOTES                                                                   */
/*      The values of the two left-most and two right-most pixels on        */
/*       each line of the output are not well-defined.                      */
/*                                                                          */
/* ======================================================================== */

#pragma CODE_SECTION(IMG_sobel_5x5_16s_cn,   ".text:ansi");


void IMG_sobel_5x5_16s_cn
(
     const short *restrict  in,   /* Input image data   */
           short *restrict out,   /* Output image data  */
           short          cols,   /* image columns      */
           short          rows    /* Image rows         */
)
{    
    int    H,       O,       V;
    int    i;

    int    i00,     i01,     i02;
    int    i03,     i04,     i10;
    int    i11,     i12,     i13;
    int    i14,     i20,     i21;
    int    i23,     i24,     i30;
    int    i31,     i32,     i33;
    int    i34,     i40,     i41;
    int    i42,     i43,     i44;

    
    /* -------------------------------------------------------------------- */
    /*  Iterate over entire image as a single, continuous raster line.      */
    /* -------------------------------------------------------------------- */
    for (i = 0; i < cols * (rows - 4) - 4; i++) {
        /* ---------------------------------------------------------------- */
        /*  Read in the required 5x5 region from the input.                 */
        /* ---------------------------------------------------------------- */
        i00 = in[i               ];
        i01 = in[i +            1];
        i02 = in[i +            2];
        i03 = in[i +            3];
        i04 = in[i +            4];
        
        i10 = in[i +     cols    ];
        i11 = in[i +     cols + 1];
        i12 = in[i +     cols + 2];
        i13 = in[i +     cols + 3];
        i14 = in[i +     cols + 4];
        
        i20 = in[i + 2 * cols    ];
        i21 = in[i + 2 * cols + 1];
        i23 = in[i + 2 * cols + 3];
        i24 = in[i + 2 * cols + 4];
        
        i30 = in[i + 3 * cols    ];
        i31 = in[i + 3 * cols + 1];
        i32 = in[i + 3 * cols + 2];
        i33 = in[i + 3 * cols + 3];
        i34 = in[i + 3 * cols + 4];
        
        i40 = in[i + 4 * cols    ];
        i41 = in[i + 4 * cols + 1];
        i42 = in[i + 4 * cols + 2];
        i43 = in[i + 4 * cols + 3];
        i44 = in[i + 4 * cols + 4];
 
        /* ---------------------------------------------------------------- */
        /*  Apply horizontal and vertical filter masks.  The final filter   */
        /*  output is the sum of the absolute values of these filters.      */
        /* ---------------------------------------------------------------- */
        H = -     i00 - 4 * i01 - 6 * i02 - 4 * i03 -     i04
            - 2 * i10 - 8 * i11 -12 * i12 - 8 * i13 - 2 * i14

            + 2 * i30 + 8 * i31 +12 * i32 + 8 * i33 + 2 * i34
            +     i40 + 4 * i41 + 6 * i42 + 4 * i43 +     i44;
        
        V = +     i00 + 2 * i01           - 2 * i03 -     i04
            + 4 * i10 + 8 * i11           - 8 * i13 - 4 * i14
            + 6 * i20 +12 * i21           -12 * i23 - 6 * i24
            + 4 * i30 + 8 * i31           - 8 * i33 - 4 * i34
            +     i40 + 2 * i41           - 2 * i43 -     i44;
        
        O = abs(H) + abs(V);

        /* ---------------------------------------------------------------- */
        /*  Clamp to 16-bit range.  The output is always positive due to    */
        /*  the absolute value, so we only need to check for positive       */
        /*  overflow.                                                       */
        /* ---------------------------------------------------------------- */
        O = (O > 32767) ? 32767 : O;

        /* ---------------------------------------------------------------- */
        /*  Store it.                                                       */
        /* ---------------------------------------------------------------- */
        out[i + 2] = O;
    }
}

/* ======================================================================== */
/*  End of file:  IMG_sobel_5x5_16s_cn.c                                    */
/* ======================================================================== */
