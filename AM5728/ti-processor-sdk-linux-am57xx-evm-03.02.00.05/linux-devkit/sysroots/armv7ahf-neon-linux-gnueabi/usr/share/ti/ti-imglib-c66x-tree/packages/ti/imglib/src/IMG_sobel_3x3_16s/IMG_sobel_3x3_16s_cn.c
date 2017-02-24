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
/*      IMG_sobel_3x3_16s_cn                                                */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C-callable and can be called as:                    */
/*                                                                          */
/*      void IMG_sobel_3x3_16s_cn                                           */
/*      (                                                                   */
/*          const short *restrict  in,  // Input image data  //             */
/*                short *restrict  out, // Output image data //             */
/*                short           cols, // Image columns     //             */
/*                short           rows  // Image rows        //             */
/*      )                                                                   */
/*                                                                          */
/*      The sobel filter is applied to the input image.  The input image    */
/*      dimensions are given by the arguments 'cols' and 'rows'.  The       */
/*      output image is 'cols' pixels wide and 'rows - 2' pixels tall.      */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*                                                                          */
/*      To see how the implementation is going to work on the input         */
/*      buffer, lets imagine we have the following input buffer:            */
/*      lets imagine we have the following input buffer:                    */
/*                                                                          */
/*              yyyyyyyyyyyyyyyy                                            */
/*              yxxxxxxxxxxxxxxy                                            */
/*              yxxxxxxxxxxxxxxy                                            */
/*              yxxxxxxxxxxxxxxy                                            */
/*              yxxxxxxxxxxxxxxy                                            */
/*              yyyyyyyyyyyyyyyy                                            */
/*                                                                          */
/*      The output buffer would be:                                         */
/*                                                                          */
/*              tXXXXXXXXXXXXXXz                                            */
/*              zXXXXXXXXXXXXXXz                                            */
/*              zXXXXXXXXXXXXXXz                                            */
/*              zXXXXXXXXXXXXXXt                                            */
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
/*      This means that we will only process (rows-2) lines.  Then, we      */
/*      will process all the pixels inside each line. Even though the       */
/*      results for the first and last pixels in each line will not         */
/*      be relevant, it makes the control much simpler and ends up          */
/*      saving cycles.                                                      */
/*                                                                          */
/*      Also the first pixel in the first processed line and the            */
/*      last pixel in the last processed line will not be computed.         */
/*      It is not necessary, since the results would be bogus.              */
/*                                                                          */
/*      The following horizontal and vertical masks that are                */
/*      applied to the input buffer to obtain one output pixel.             */
/*                                                                          */
/*          Horizontal:                                                     */
/*              -1 -2 -1                                                    */
/*               0  0  0                                                    */
/*               1  2  1                                                    */
/*                                                                          */
/*          Vertical:                                                       */
/*              -1  0  1                                                    */
/*              -2  0  2                                                    */
/*              -1  0  1                                                    */
/*                                                                          */
/*      The natural C implementation has no restrictions. The Optimized     */
/*      and IntrinsiC codes has restrictions as noted in the ASSUMPTIONS    */
/*      below.                                                              */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      1. cols :     'cols' >  3 and multiple of 2.                        */
/*      2. rows :     'rows' >= 3 .                                         */
/*      3. Input and outpur arrays do not overlap.                          */
/*      4. Input and output arrays have no alignment requirements.          */
/*                                                                          */
/* ======================================================================== */

#pragma CODE_SECTION(IMG_sobel_3x3_16s_cn,   ".text:ansi");

void IMG_sobel_3x3_16s_cn
(
    const short *restrict   in,  /* Input image data   */
          short *restrict  out,  /* Output image data  */
          short           cols,  /* image columns      */
          short           rows   /* Image rows         */
)
{    
  int    H,       O,       V;
  int    i;
  int    i00,     i01,     i02;
  int    i10,     i12;
  int    i20,     i21,     i22;

  /* -------------------------------------------------------------------- */
  /*  Iterate over entire image as a single, continuous raster line.      */
  /* -------------------------------------------------------------------- */
  for (i=0; i<(cols*(rows-2)-2); i++) {
    /* ---------------------------------------------------------------- */
    /*  Read in the required 3x3 region from the input.                 */
    /* ---------------------------------------------------------------- */
    i00 =   in[i               ]; 
    i01 =   in[i            + 1]; 
    i02 =   in[i            + 2];
    i10 =   in[i +     cols    ];                  
    i12 =   in[i +     cols + 2];
    i20 =   in[i + 2 * cols    ]; 
    i21 =   in[i + 2 * cols + 1]; 
    i22 =   in[i + 2 * cols + 2];

    /* ---------------------------------------------------------------- */
    /*  Apply horizontal and vertical filter masks.  The final filter   */
    /*  output is the sum of the absolute values of these filters.      */
    /* ---------------------------------------------------------------- */
    H   =   - i00 - 2 * i01 -  i02
            + i20 + 2 * i21 +  i22;

    V   =   - i00      +     i02 
            - 2 * i10  + 2 * i12 
            - i20      +     i22;    

    O   =   abs(H) + abs(V);

    /* ---------------------------------------------------------------- */
    /*  Clamp to 16-bit range.  The output is always positive due to    */
    /*  the absolute value, so we only need to check for overflow.      */
    /* ---------------------------------------------------------------- */
    O   =   (O > 32767) ? 32767 : O;

    /* ---------------------------------------------------------------- */
    /*  Store it.                                                       */
    /* ---------------------------------------------------------------- */
    out[i + 1] = O;
  }
}

/* ======================================================================== */
/*  End of file:  IMG_sobel_3x3_16s_cn.c                                    */
/* ======================================================================== */
