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
/*      IMG_sobel_5x5_16s                                                   */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C-callable and can be called as:                    */
/*                                                                          */
/*      void IMG_sobel_5x5_16s                                              */
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
/*      Following are the horizontal and vertical masks that are            */
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
/*  COMPATIBILITY                                                           */
/*      This code is compatible with C66x processors only.                  */
/*                                                                          */
/*  SOURCE                                                                  */
/*      The algorithm is taken from sobel in IMGLIB                         */
/* ------------------------------------------------------------------------ */

#pragma CODE_SECTION(IMG_sobel_5x5_16s,   ".text:optimized");


#include "c6x.h"

void IMG_sobel_5x5_16s
(
    const short *restrict  in,   /* Input image data   */
          short *restrict out,   /* Output image data  */
          short          cols,   /* image columns      */
          short          rows    /* Image rows         */
)
{    
  int             i,          end;
  int             o1,         o2;

  long long       row1_3210,  row2_3210,  row3_3210;
  long long       row4_3210,  row5_3210;
  
  unsigned int    row1_54,    row2_54,    row3_54;
  unsigned int    row4_54,    row5_54;    
  
  unsigned int    sum_h0,     sum_h1,     sum_v0,     sum_v1;
  int             dsum_m0,    dsum_m1;
  long long       dsum_h0,    dsum_h1,    dsum_v0,    dsum_v1;
  long long       dsum_r3;
  
  long long       mask_hr0,   mask_hr1,   mask_vr0,   mask_vr1;
  long long       mask_vr2;
  int             mask_hc2;

  __x128_t        mask_hr01,  mask_vr01,  mask_vr23;
  __x128_t        data_r4310, data_r5421;


  /* -------------------------------------------------------------------- */
  /*  Pointers to each of the 5 rows.                                     */
  /* -------------------------------------------------------------------- */
  const short *restrict in0;
  const short *restrict in1;
  const short *restrict in2;
  const short *restrict in3;
  const short *restrict in4;
   

  /* -------------------------------------------------------------------- */
  /*  Assertions to gaurantee intrinsic assumptions.                      */
  /* -------------------------------------------------------------------- */
  _nassert(cols                   > 5);  /* cols must be greater than 5 */
  _nassert(cols              % 2 == 0);  /* cols must be multiple of 2  */
  _nassert(rows                  >= 5);  /* rows must be atleast 5      */
  _nassert(cols * (rows - 4) - 4 >= 2);  /* atleast 2 output values     */
  
  /* -------------------------------------------------------------------- */
  /*  Initialize pointers to point to staring of each of the 5 rows       */
  /* -------------------------------------------------------------------- */
  in0 = in;
  in1 = in0 + cols;
  in2 = in1 + cols;
  in3 = in2 + cols;
  in4 = in3 + cols;

  /* -------------------------------------------------------------------- */
  /*  Initialize horizontal and vertical masks                            */
  /* -------------------------------------------------------------------- */
  mask_hc2 = 0x0006000c; 
  
  mask_hr0 = 0x0001000400040001;  /* +1 +4 (0) +4 +1 */
  mask_hr1 = 0x0002000800080002;  /* +2 +8 (0) +8 +2 */
  mask_vr0 = 0xfffffffe00020001;
  mask_vr1 = 0xfffcfff800080004;
  mask_vr2 = 0xfffafff4000c0006;

  mask_vr23 = _llto128(mask_vr2,mask_vr2);
  mask_hr01 = _llto128(mask_hr0,mask_hr1);
  mask_vr01 = _llto128(mask_vr0,mask_vr1);
  
  /* -------------------------------------------------------------------- */
  /*  Calculate the number of iterations                                  */
  /* -------------------------------------------------------------------- */
  end = (cols * (rows - 4) - 4);

  for (i=0; i<end; i+=2) {
    /* ------------------------------------------------------------------ */
    /* (A) Load first 6 pixel values for rows 1 and 2.                    */
    /* ------------------------------------------------------------------ */
    row1_3210 = _mem8_const(in0    );
    row1_54   = _mem4_const(in0 + 4);
    row2_3210 = _mem8_const(in1    );
    row2_54   = _mem4_const(in1 + 4);

    /* ------------------------------------------------------------------ */
    /*  (B) Pack the 1st and 2nd row pixels for cols 4,3,,1,0.            */
    /* ------------------------------------------------------------------ */
    data_r4310 = _ito128(_packlh2(row1_54,_hill(row1_3210)),_loll(row1_3210),
                         _packlh2(row2_54,_hill(row2_3210)),_loll(row2_3210));

    /* ------------------------------------------------------------------ */
    /*  (C) Calculate horizontal and vertical mask sums.                  */
    /* ------------------------------------------------------------------ */
    dsum_h0 = _ddotp4h(mask_hr01,data_r4310);
    dsum_v0 = _ddotp4h(mask_vr01,data_r4310);

    /* ------------------------------------------------------------------ */
    /*  (D) Calculate horizontal sum for pixel 2 in rows 1 and 2.         */
    /* ------------------------------------------------------------------ */
    dsum_m0 = _dotp2(mask_hc2,_pack2(_hill(row1_3210),_hill(row2_3210)));

    /* ------------------------------------------------------------------ */
    /*  (E) Pack the 1st and 2nd row pixels for cols 5,4,,2,1.            */
    /* ------------------------------------------------------------------ */
    data_r5421 = _ito128(row1_54,_packlh2(_hill(row1_3210),_loll(row1_3210)),
                         row2_54,_packlh2(_hill(row2_3210),_loll(row2_3210)));

    /* ------------------------------------------------------------------ */
    /*  (F) Calculate horizontal and vertical mask sums.                  */
    /* ------------------------------------------------------------------ */
    dsum_h1 = _ddotp4h(mask_hr01,data_r5421);
    dsum_v1 = _ddotp4h(mask_vr01,data_r5421);

    /* ------------------------------------------------------------------ */
    /*  (G) Calculate horizontal sum for pixel 3 in rows 1 and 2.         */
    /* ------------------------------------------------------------------ */
    dsum_m1 = _dotp2(mask_hc2,_packh2(_hill(row1_3210),_hill(row2_3210)));


    /* ------------------------------------------------------------------ */
    /* ------------------------------------------------------------------ */
    /*  Repeat similar process (A - G) for the 4th and 5th rows.          */
    /* ------------------------------------------------------------------ */
    /* ------------------------------------------------------------------ */

    
    /* ------------------------------------------------------------------ */
    /* (A) Load first 6 pixel values for rows 4 and 5.                    */
    /* ------------------------------------------------------------------ */
    row4_3210 = _mem8_const(in3    );
    row4_54   = _mem4_const(in3 + 4);
    row5_3210 = _mem8_const(in4    );
    row5_54   = _mem4_const(in4 + 4);

    /* ------------------------------------------------------------------ */
    /*  (B) Pack the 5th and 4th row pixels for cols 4,3,,1,0.            */
    /* ------------------------------------------------------------------ */
    data_r4310 = _ito128(_packlh2(row5_54,_hill(row5_3210)),_loll(row5_3210),
                         _packlh2(row4_54,_hill(row4_3210)),_loll(row4_3210));
    
    /* ------------------------------------------------------------------ */
    /*  (C) Calculate horizontal and vertical mask sums.  Subtract the    */
    /*      horizontal sum from (C) above to account for negative mask    */
    /*      values.  Add the vertical sum to (C) above.                   */
    /* ------------------------------------------------------------------ */
    dsum_h0 = _dssub(        _ddotp4h(mask_hr01,data_r4310),dsum_h0);
    dsum_v0 = _dsadd(dsum_v0,_ddotp4h(mask_vr01,data_r4310));

    /* ------------------------------------------------------------------ */
    /*  (D) Calculate horizontal sum for pixel 2 in rows 5 and 4.         */
    /*      Subtract the horizontal sum from (D) above to account for     */
    /*      negative mask values.                                         */
    /* ------------------------------------------------------------------ */
    dsum_m0 = _ssub(_dotp2(mask_hc2,_pack2(_hill(row5_3210),_hill(row4_3210))),
                    dsum_m0);

    /* ------------------------------------------------------------------ */
    /*  (E) Pack the 5th and 4th row pixels for cols 5,4,,2,1.            */
    /* ------------------------------------------------------------------ */
    data_r5421 = _ito128(row5_54,_packlh2(_hill(row5_3210),_loll(row5_3210)),
                         row4_54,_packlh2(_hill(row4_3210),_loll(row4_3210)));

    /* ------------------------------------------------------------------ */
    /*  (F) Calculate horizontal and vertical mask sums.  Subtract the    */
    /*      horizontal sum from (C) above to account for negative mask    */
    /*      values.  Add the vertical sum to (C) above.                   */
    /* ------------------------------------------------------------------ */
    dsum_h1 = _dssub(        _ddotp4h(mask_hr01,data_r5421),dsum_h1);
    dsum_v1 = _dsadd(dsum_v1,_ddotp4h(mask_vr01,data_r5421));

    /* ------------------------------------------------------------------ */
    /*  (G) Calculate horizontal sum for pixel 2 in rows 5 and 4.         */
    /*      Subtract the horizontal sum from (D) above to account for     */
    /*      negative mask values.                                         */
    /* ------------------------------------------------------------------ */
    dsum_m1 = _ssub(_dotp2(mask_hc2,_packh2(_hill(row5_3210),_hill(row4_3210))),
                    dsum_m1);


    /* ------------------------------------------------------------------ */
    /* ------------------------------------------------------------------ */
    /*  Process the 3rd row for the vertical mask only                    */
    /* ------------------------------------------------------------------ */
    /* ------------------------------------------------------------------ */


    /* ------------------------------------------------------------------ */
    /*  Load first 6 pixel values for row 3.                              */
    /* ------------------------------------------------------------------ */
    row3_3210 = _mem8_const(in2    );
    row3_54   = _mem4_const(in2 + 4);
    
    /* ------------------------------------------------------------------ */
    /*  Pack the 3rd row pixels for cols 4,3,,1,0 and 5,4,,2,1.           */
    /* ------------------------------------------------------------------ */
    data_r4310 = _ito128(_packlh2(row3_54,_hill(row3_3210)),_loll(row3_3210),
                         row3_54,_packlh2(_hill(row3_3210), _loll(row3_3210)));
    
    /* ------------------------------------------------------------------ */
    /*  Calculate vertical mask partial sums for two outputs              */
    /*  simultaneously.                                                   */
    /* ------------------------------------------------------------------ */
    dsum_r3 = _ddotp4h(mask_vr23,data_r4310);
    
    
    /* ------------------------------------------------------------------ */
    /* ------------------------------------------------------------------ */
    /*  Calculate two outputs.                                            */
    /* ------------------------------------------------------------------ */
    /* ------------------------------------------------------------------ */


    /* ------------------------------------------------------------------ */
    /*  Increment all input (row) pointers.                               */
    /* ------------------------------------------------------------------ */
    in0 = in0 + 2;
    in1 = in1 + 2;
    in2 = in2 + 2;
    in3 = in3 + 2;
    in4 = in4 + 2;

    /* ------------------------------------------------------------------ */
    /*  Add all partial sums for the two outputs.                         */
    /* ------------------------------------------------------------------ */
    sum_v0 = _hill(dsum_v0) + _loll(dsum_v0) + _hill(dsum_r3);
    sum_v1 = _hill(dsum_v1) + _loll(dsum_v1) + _loll(dsum_r3);
    sum_h0 = _hill(dsum_h0) + _loll(dsum_h0) + dsum_m0;
    sum_h1 = _hill(dsum_h1) + _loll(dsum_h1) + dsum_m1;

    /* ------------------------------------------------------------------ */
    /*  Calculate each output as the combined sum of the vertical and     */
    /*  horizontal component absolute values.                             */
    /* ------------------------------------------------------------------ */
    o1 = _abs(sum_h0) + _abs(sum_v0);
    o2 = _abs(sum_h1) + _abs(sum_v1);

    /* ----------------------------------------------------------------- */
    /* Saturate and pack the result to store in the output array         */
    /* ----------------------------------------------------------------- */
    _mem4((void *) &(out[i+2])) = _spack2(o2,o1);   
  }                   
}

/* ======================================================================== */
/*  End of file:  IMG_sobel_5x5_16s.c                                       */
/* ======================================================================== */
