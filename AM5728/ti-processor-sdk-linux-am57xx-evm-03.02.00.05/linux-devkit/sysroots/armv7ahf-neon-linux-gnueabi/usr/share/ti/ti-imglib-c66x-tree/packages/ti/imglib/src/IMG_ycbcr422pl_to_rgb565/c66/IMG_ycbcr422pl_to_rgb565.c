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
/*      IMG_ycbcr422pl_to_rgb565 -- Planarized YCbCr 4:2:2/4:2:0 to 16-bit  */
/*                                  RGB 5:6:5 color space conversion.       */
/*                                                                          */
/*  USAGE                                                                   */
/*      This function is C callable, and is called according to this        */
/*      C prototype:                                                        */
/*                                                                          */
/*      void IMG_ycbcr422pl_to_rgb565                                       */
/*      (                                                                   */
/*        const short         coeff[5],  // Matrix coefficients.        //  */
/*        const unsigned char *y_data,   // Luminence data  (Y')        //  */
/*        const unsigned char *cb_data,  // Blue color-diff (B'-Y')     //  */
/*        const unsigned char *cr_data,  // Red color-diff  (R'-Y')     //  */
/*        unsigned short                                                    */
/*                   *restrict rgb_data, // RGB 5:6:5 packed pixel out. //  */
/*        unsigned            num_pixels // # of luma pixels to process //  */
/*      );                                                                  */
/*                                                                          */
/*      The 'coeff[]' array contains the color-space-conversion matrix      */
/*      coefficients.  The 'y_data', 'cb_data' and 'cr_data' pointers       */
/*      point to the separate input image planes.  The 'rgb_data' pointer   */
/*      points to the output image buffer.  See below for alignment         */
/*      constraints on these buffers.                                       */
/*                                                                          */
/*      The kernel is designed to process arbitrary amounts of 4:2:2        */
/*      image data, although 4:2:0 image data may be processed as well.     */
/*      For 4:2:2 input data, the 'y_data', 'cb_data' and 'cr_data'         */
/*      arrays may hold an arbitrary amount of image data, including        */
/*      multiple scan lines of image data.                                  */
/*                                                                          */
/*      For 4:2:0 input data, only a single scan-line (or portion           */
/*      thereof) may be processed at a time.  This is achieved by           */
/*      calling the function twice using the same row data for              */
/*      'cr_data' and 'cb_data', and providing new row data for             */
/*      'y_data'.  This is numerically equivalent to replicating the Cr     */
/*      and Cb pixels vertically.                                           */
/*                                                                          */
/*      The coefficients in the coeff array must be in signed Q13 form.     */
/*      These coefficients correspond to the following matrix equation:     */
/*                                                                          */
/*          [ coeff[0] 0.0000   coeff[1] ]   [ Y' -  16 ]     [ R']         */
/*          [ coeff[0] coeff[2] coeff[3] ] * [ Cb - 128 ]  =  [ G']         */
/*          [ coeff[0] coeff[4] 0.0000   ]   [ Cr - 128 ]     [ B']         */
/*                                                                          */
/*      The output from this kernel is 16-bit RGB in 5:6:5 format.          */
/*      The RGB components are packed into halfwords as shown below.        */
/*                                                                          */
/*                     15      11 10       5 4        0                     */
/*                    +----------+----------+----------+                    */
/*                    |   Red    |  Green   |   Blue   |                    */
/*                    +----------+----------+----------+                    */
/*                                                                          */
/*      This kernel can also return the red, green, and blue values in      */
/*      the opposite order if a particular application requires it.         */
/*      This is achieved by exchanging the 'cb_data' and 'cr_data'          */
/*      arguments when calling the function, and by reversing the order     */
/*      of coefficients in coeff[1] through coeff[4].  This essentially     */
/*      implements the following matrix multiply:                           */
/*                                                                          */
/*          [ coeff[0] 0.0000   coeff[4] ]   [ Y' -  16 ]     [ B']         */
/*          [ coeff[0] coeff[3] coeff[2] ] * [ Cr - 128 ]  =  [ G']         */
/*          [ coeff[0] coeff[1] 0.0000   ]   [ Cb - 128 ]     [ R']         */
/*                                                                          */
/*      The reversed RGB ordering output by this mode is as follows:        */
/*                                                                          */
/*                     15      11 10       5 4        0                     */
/*                    +----------+----------+----------+                    */
/*                    |   Blue   |  Green   |   Red    |                    */
/*                    +----------+----------+----------+                    */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      This kernel performs Y'CbCr to RGB conversion.  From the Color      */
/*      FAQ, http://home.inforamp.net/~poynton/ColorFAQ.html :              */
/*                                                                          */
/*          Various scale factors are applied to (B'-Y') and (R'-Y')        */
/*          for different applications.  The Y'PbPr scale factors are       */
/*          optimized for component analog video.  The Y'CbCr scaling       */
/*          is appropriate for component digital video, JPEG and MPEG.      */
/*          Kodak's PhotoYCC(tm) uses scale factors optimized for the       */
/*          gamut of film colors.  Y'UV scaling is appropriate as an        */
/*          intermediate step in the formation of composite NTSC or PAL     */
/*          video signals, but is not appropriate when the components       */
/*          are keps separate.  Y'UV nomenclature is now used rather        */
/*          loosely, and it sometimes denotes any scaling of (B'-Y')        */
/*          and (R'-Y').  Y'IQ coding is obsolete.                          */
/*                                                                          */
/*      This code can perform various flavors of Y'CbCr to RGB              */
/*      conversion as long as the offsets on Y, Cb, and Cr are -16,         */
/*      -128, and -128, respectively, and the coefficients match the        */
/*      pattern shown.                                                      */
/*                                                                          */
/*      The kernel implements the following matrix form, which involves 5   */
/*      unique coefficients:                                                */
/*                                                                          */
/*          [ coeff[0] 0.0000   coeff[1] ]   [ Y' -  16 ]     [ R']         */
/*          [ coeff[0] coeff[2] coeff[3] ] * [ Cb - 128 ]  =  [ G']         */
/*          [ coeff[0] coeff[4] 0.0000   ]   [ Cr - 128 ]     [ B']         */
/*                                                                          */
/*                                                                          */
/*      Below are some common coefficient sets, along with the matrix       */
/*      equation that they correspond to.   Coefficients are in signed      */
/*      Q13 notation, which gives a suitable balance between precision      */
/*      and range.                                                          */
/*                                                                          */
/*      1.  Y'CbCr -> RGB conversion with RGB levels that correspond to     */
/*          the 219-level range of Y'.  Expected ranges are [16..235] for   */
/*          Y' and [16..240] for Cb and Cr.                                 */
/*                                                                          */
/*          coeff[] = { 0x2000, 0x2BDD, -0x0AC5, -0x1658, 0x3770 };         */
/*                                                                          */
/*          [ 1.0000    0.0000    1.3707 ]   [ Y' -  16 ]     [ R']         */
/*          [ 1.0000   -0.3365   -0.6982 ] * [ Cb - 128 ]  =  [ G']         */
/*          [ 1.0000    1.7324    0.0000 ]   [ Cr - 128 ]     [ B']         */
/*                                                                          */
/*      2.  Y'CbCr -> RGB conversion with the 219-level range of Y'         */
/*          expanded to fill the full RGB dynamic range.  (The matrix       */
/*          has been scaled by 255/219.)  Expected ranges are [16..235]     */
/*          for Y' and [16..240] for Cb and Cr.                             */
/*                                                                          */
/*          coeff[] = { 0x2543, 0x3313, -0x0C8A, -0x1A04, 0x408D };         */
/*                                                                          */
/*          [ 1.1644    0.0000    1.5960 ]   [ Y' -  16 ]     [ R']         */
/*          [ 1.1644   -0.3918   -0.8130 ] * [ Cb - 128 ]  =  [ G']         */
/*          [ 1.1644    2.0172    0.0000 ]   [ Cr - 128 ]     [ B']         */
/*                                                                          */
/*      3.  Y'CbCr -> BGR conversion with RGB levels that correspond to     */
/*          the 219-level range of Y'.  This is equivalent to #1 above,     */
/*          except that the R, G, and B output order in the packed          */
/*          pixels is reversed.  Note:  The 'cr_data' and 'cb_data'         */
/*          input arguments must be exchanged for this example as           */
/*          indicated under USAGE above.                                    */
/*                                                                          */
/*          coeff[] = { 0x2000, 0x3770, -0x1658, -0x0AC5, 0x2BDD };         */
/*                                                                          */
/*          [ 1.0000    0.0000    1.7324 ]   [ Y' -  16 ]     [ B']         */
/*          [ 1.0000   -0.6982   -0.3365 ] * [ Cr - 128 ]  =  [ G']         */
/*          [ 1.0000    1.3707    0.0000 ]   [ Cb - 128 ]     [ R']         */
/*                                                                          */
/*      4.  Y'CbCr -> BGR conversion with the 219-level range of Y'         */
/*          expanded to fill the full RGB dynamic range.  This is           */
/*          equivalent to #2 above, except that the R, G, and B output      */
/*          order in the packed pixels is reversed.  Note:  The             */
/*          'cr_data' and 'cb_data' input arguments must be exchanged       */
/*          for this example as indicated under USAGE above.                */
/*                                                                          */
/*          coeff[] = { 0x2000, 0x408D, -0x1A04, -0x0C8A, 0x3313 };         */
/*                                                                          */
/*          [ 1.0000    0.0000    2.0172 ]   [ Y' -  16 ]     [ B']         */
/*          [ 1.0000   -0.8130   -0.3918 ] * [ Cr - 128 ]  =  [ G']         */
/*          [ 1.0000    1.5960    0.0000 ]   [ Cb - 128 ]     [ R']         */
/*                                                                          */
/*      Other scalings of the color differences (B'-Y') and (R'-Y')         */
/*      (sometimes incorrectly referred to as U and V) are supported, as    */
/*      long as the color differences are unsigned values centered around   */
/*      128 rather than signed values centered around 0, as noted above.    */
/*                                                                          */
/*      In addition to performing plain color-space conversion, color       */
/*      saturation can be adjusted by scaling coeff[1] through coeff[4].    */
/*      Similarly, brightness can be adjusted by scaling coeff[0].          */
/*      General hue adjustment can not be performed, however, due to the    */
/*      two zeros hard-coded in the matrix.                                 */
/*                                                                          */
/*  TECHNIQUES                                                              */
/*      Pixel replication is performed implicitly on chroma data to         */
/*      reduce the total number of multiplies required.  The chroma         */
/*      portion of the matrix is calculated once for each Cb, Cr pair,      */
/*      and the result is added to both Y' samples.                         */
/*                                                                          */
/*      Matrix Multiplication is performed as a combination of MPY2s and    */
/*      DOTP2s.  Saturation to 8bit values is performed using SPACKU4       */
/*      which takes in 4 signed 16-bit values and saturates them to         */
/*      unsigned 8-bit values.  The output of Matrix Multiplication would   */
/*      ideally be in a Q13 format.  This however, cannot be fed directly   */
/*      to SPACKU4.                                                         */
/*                                                                          */
/*      This implies a shift left by 3 bits, which could be pretty          */
/*      expensive in terms of the number of shifts to be performed.  Thus,  */
/*      to avoid being bottlenecked by so many shifts, the Y, Cr & Cb data  */
/*      are shifted left by 3 before multiplication.  This is possible      */
/*      because they are 8-bit unsigned data.  Due to this, the output of   */
/*      Matrix Multiplication is in a Q16 format, which can be directly     */
/*      fed to SPACKU4.                                                     */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      The number of luma samples to be processed needs to be a multiple   */
/*      of 8.                                                               */
/*      The input Y array needs to be double-word aligned.                  */
/*      The input Cr and Cb arrays need to be word aligned                  */
/*      The output image must be double-word aligned.                       */
/*                                                                          */
/*  SOURCE                                                                  */
/*      Poynton, Charles et al.  "The Color FAQ,"  1999.                    */
/*          http://home.inforamp.net/~poynton/ColorFAQ.html                 */
/*                                                                          */
/* ======================================================================== */

#pragma CODE_SECTION(IMG_ycbcr422pl_to_rgb565, ".text:optimized");


void IMG_ycbcr422pl_to_rgb565
(
    const short                   coeff[5],  /* Matrix coefficients.          */
    const unsigned char *restrict y_data,    /* Luminence data        (Y')    */
    const unsigned char *restrict cb_data,   /* Blue color-difference (B'-Y') */
    const unsigned char *restrict cr_data,   /* Red color-difference  (R'-Y') */
    unsigned short      *restrict rgb_data,  /* RGB 5:6:5 packed pixel output */
    unsigned                      num_pixels /* # of luma pixels to process.  */
)
{
    int i;   
    const unsigned c0   = _pack2(coeff[0], coeff[0]);
    const unsigned c1   = _pack2(coeff[1], coeff[1]);
    const unsigned c2c3 = _pack2(coeff[2], coeff[3]);
    const unsigned c3c2 = _pack2(coeff[3], coeff[2]);
    const unsigned c4   = _pack2(coeff[4], coeff[4]);

    _nassert((int)y_data   % 8 == 0);
    _nassert((int)cr_data  % 4 == 0);
    _nassert((int)cb_data  % 4 == 0);
    _nassert((int)rgb_data % 8 == 0);

    for (i = 0; i < num_pixels; i += 8)
    {
        /* ---------------------------------------------------------------- */
        /*  Load 8 luma, 4 Cr, 4 Cb from the input arrays.  Remove the      */
        /*  +128 bias on the chroma.                                        */
        /* ---------------------------------------------------------------- */
        unsigned y_7654_ = _amem4_const(&y_data [i  + 4]);
        unsigned y_3210_ = _amem4_const(&y_data [i  + 0]);
        unsigned cb6420_ = _amem4_const(&cb_data[i >> 1]) ^ 0x80808080;
        unsigned cr6420_ = _amem4_const(&cr_data[i >> 1]) ^ 0x80808080;

        /* ---------------------------------------------------------------- */
        /*  Unpack the chroma and left-shift it by 3.                       */
        /* ---------------------------------------------------------------- */
        double   cb6420  = _mpysu4(cb6420_, 0x08080808);
        double   cr6420  = _mpysu4(cr6420_, 0x08080808);
        unsigned cb64    = _hi(cb6420);
        unsigned cb20    = _lo(cb6420);
        unsigned cr64    = _hi(cr6420);
        unsigned cr20    = _lo(cr6420);

        /* ---------------------------------------------------------------- */
        /*  Unpack the luma, left-shift it by 3, and remove the +16 bias.   */
        /* ---------------------------------------------------------------- */
        double   y_7654  = _mpyu4(   y_7654_, 0x08080808);
        double   y_3210  = _mpyu4(   y_3210_, 0x08080808);
        unsigned y_76    = _sub2(_hi(y_7654), 0x00800080);
        unsigned y_54    = _sub2(_lo(y_7654), 0x00800080);
        unsigned y_32    = _sub2(_hi(y_3210), 0x00800080);
        unsigned y_10    = _sub2(_lo(y_3210), 0x00800080);

        /* ---------------------------------------------------------------- */
        /*  Perform leftmost column of matrix multiply.  We generate 8      */
        /*  separate 16Q16 products for the 8 output pixels.                */
        /* ---------------------------------------------------------------- */
        double   y_76_c0 = _mpy2(c0, y_76);
        double   y_54_c0 = _mpy2(c0, y_54);
        double   y_32_c0 = _mpy2(c0, y_32);
        double   y_10_c0 = _mpy2(c0, y_10);
        int      y_7_c0  = _hi(y_76_c0), y_6_c0  = _lo(y_76_c0);
        int      y_5_c0  = _hi(y_54_c0), y_4_c0  = _lo(y_54_c0);
        int      y_3_c0  = _hi(y_32_c0), y_2_c0  = _lo(y_32_c0);
        int      y_1_c0  = _hi(y_10_c0), y_0_c0  = _lo(y_10_c0);

        /* ---------------------------------------------------------------- */
        /*  Perform right two columns of matrix multiply.  We generate 4    */
        /*  pairs of outputs that will be mixed with the results of the     */
        /*  luma calculations.  Recall that each chroma pair is shared      */
        /*  across two luma values.  The results here are 16Q16.            */
        /* ---------------------------------------------------------------- */
        double   cr64_c1 = _mpy2(c1, cr64);
        double   cr20_c1 = _mpy2(c1, cr20);
        double   cb64_c4 = _mpy2(c4, cb64);
        double   cb20_c4 = _mpy2(c4, cb20);
        int      cr6_c1  = _hi(cr64_c1), cr4_c1  = _lo(cr64_c1);
        int      cr2_c1  = _hi(cr20_c1), cr0_c1  = _lo(cr20_c1);
        int      cb6_c4  = _hi(cb64_c4), cb4_c4  = _lo(cb64_c4);
        int      cb2_c4  = _hi(cb20_c4), cb0_c4  = _lo(cb20_c4);

        int      cg6     = _dotp2(_packh2(cr64, cb64), c3c2);
        int      cg4     = _dotp2(_pack2 (cr64, cb64), c3c2);
        int      cg2     = _dotp2(_packh2(cb20, cr20), c2c3);
        int      cg0     = _dotp2(_pack2 (cb20, cr20), c2c3);

        /* ---------------------------------------------------------------- */
        /*  Mix the chroma and the luma together to make RGB.               */
        /* ---------------------------------------------------------------- */
        int      r_7     = y_7_c0 + cr6_c1;
        int      r_6     = y_6_c0 + cr6_c1;
        int      r_5     = y_5_c0 + cr4_c1;
        int      r_4     = y_4_c0 + cr4_c1;
        int      r_3     = y_3_c0 + cr2_c1;
        int      r_2     = y_2_c0 + cr2_c1;
        int      r_1     = y_1_c0 + cr0_c1;
        int      r_0     = y_0_c0 + cr0_c1;

        int      g_7     = y_7_c0 + cg6;
        int      g_6     = y_6_c0 + cg6;
        int      g_5     = y_5_c0 + cg4;
        int      g_4     = y_4_c0 + cg4;
        int      g_3     = y_3_c0 + cg2;
        int      g_2     = y_2_c0 + cg2;
        int      g_1     = y_1_c0 + cg0;
        int      g_0     = y_0_c0 + cg0;

        int      b_7     = y_7_c0 + cb6_c4;
        int      b_6     = y_6_c0 + cb6_c4;
        int      b_5     = y_5_c0 + cb4_c4;
        int      b_4     = y_4_c0 + cb4_c4;
        int      b_3     = y_3_c0 + cb2_c4;
        int      b_2     = y_2_c0 + cb2_c4;
        int      b_1     = y_1_c0 + cb0_c4;
        int      b_0     = y_0_c0 + cb0_c4;

        /* ---------------------------------------------------------------- */
        /*  Keep only the integer portion of the 16Q16 data, and pack down  */
        /*  to 8-bit bytes.                                                 */
        /* ---------------------------------------------------------------- */
        unsigned r_7654  = _spacku4(_packh2(r_7, r_6), _packh2(r_5, r_4));
        unsigned r_3210  = _spacku4(_packh2(r_3, r_2), _packh2(r_1, r_0));
        unsigned g_7654  = _spacku4(_packh2(g_7, g_6), _packh2(g_5, g_4));
        unsigned g_3210  = _spacku4(_packh2(g_3, g_2), _packh2(g_1, g_0));
        unsigned b_7654  = _spacku4(_packh2(b_7, b_6), _packh2(b_5, b_4));
        unsigned b_3210  = _spacku4(_packh2(b_3, b_2), _packh2(b_1, b_0));

        /* ---------------------------------------------------------------- */
        /*  Mask away LSBs to map to 5:6:5 gamut.                           */
        /* ---------------------------------------------------------------- */
        unsigned r_7654_ = r_7654 & 0xF8F8F8F8, r_3210_ = r_3210 & 0xF8F8F8F8;
        unsigned g_7654_ = g_7654 & 0xFCFCFCFC, g_3210_ = g_3210 & 0xFCFCFCFC;
        unsigned b_7654_ = b_7654 & 0xF8F8F8F8, b_3210_ = b_3210 & 0xF8F8F8F8;

        /* ---------------------------------------------------------------- */
        /*  Unpack the bytes to halfwords, aligning the red, green and      */
        /*  blue fields so that we can merge these together as 16-bit       */
        /*  5:6:5 pixels.  For Red, we need to unpack and shift left by 8.  */
        /*  For Green, unpack and shift left by 3.  For Blue, unpack and    */
        /*  shift right 3.  We do the Red and Blue shifts in two steps.     */
        /* ---------------------------------------------------------------- */
        double   r_7654u = _mpyu4(r_7654_, 0x80808080);             /* << 7 */
        double   r_3210u = _mpyu4(r_3210_, 0x80808080);             /* << 7 */
        double   g_7654u = _mpyu4(g_7654_, 0x08080808);             /* << 3 */
        double   g_3210u = _mpyu4(g_3210_, 0x08080808);             /* << 3 */
        double   b_7654u = _mpyu4(_rotl(b_7654_, 29), 0x01010101);  /* >> 6 */
        double   b_3210u = _mpyu4(_rotl(b_3210_, 29), 0x01010101);  /* >> 6 */
        unsigned r_76u   = _hi(r_7654u)*2, r_54u = _lo(r_7654u)*2;  /* << 1 */
        unsigned r_32u   = _hi(r_3210u)*2, r_10u = _lo(r_3210u)*2;  /* << 1 */
        unsigned g_76u   = _hi(g_7654u),   g_54u = _lo(g_7654u);
        unsigned g_32u   = _hi(g_3210u),   g_10u = _lo(g_3210u);
        unsigned b_76u   = _hi(b_7654u),   b_54u = _lo(b_7654u);
        unsigned b_32u   = _hi(b_3210u),   b_10u = _lo(b_3210u);

        /* ---------------------------------------------------------------- */
        /*  Merge together the R, G, and B fields.                          */
        /* ---------------------------------------------------------------- */
        unsigned rgb_76  = r_76u + g_76u + b_76u;
        unsigned rgb_54  = r_54u + g_54u + b_54u;
        unsigned rgb_32  = r_32u + g_32u + b_32u;
        unsigned rgb_10  = r_10u + g_10u + b_10u;



#if 0
printf ("c0      = 0x%08X\n",c0);
printf ("c1      = 0x%08X\n",c1);
printf ("c2c3    = 0x%08X\n",c2c3);
printf ("c3c2    = 0x%08X\n",c3c2);
printf ("c4      = 0x%08X\n\n",c4);

printf ("y_7654_ = 0x%08X\n",y_7654_);
printf ("y_3210_ = 0x%08X\n",y_3210_);
printf ("cb6420_ = 0x08%X\n",cb6420_);
printf ("cr6420_ = 0x%08X\n",cr6420_);
printf ("cb6420  = 0x%016X _mpysu4\n",cb6420);
printf ("cr6420  = 0x%016X _mpysu4\n",cr6420);
printf ("cb64    = 0x%08X\n",cb64);
printf ("cb20    = 0x%08X\n",cb20);
printf ("cr64    = 0x%08X\n",cr64);
printf ("cr20    = 0x%08X\n",cr20);
printf ("y_7654  = 0x%016X _mpyu4\n",y_7654);
printf ("y_3210  = 0x%016X _mpyu4\n",y_3210);
printf ("y_76    = 0x%08X\n",y_76);
printf ("y_54    = 0x08%X\n",y_54);
printf ("y_32    = 0x%08X\n",y_32);
printf ("y_10    = 0x%08X\n",y_10);

printf ("y_76_c0 = 0x%016X\n",y_76_c0);
printf ("y_54_c0 = 0x%016X\n",y_54_c0);
printf ("y_32_c0 = 0x%016X\n",y_32_c0);
printf ("y_10_c0 = 0x%016X\n",y_10_c0);
printf ("y_7_c0  = 0x%08X\n",y_7_c0);
printf ("y_5_c0  = 0x%08X\n",y_5_c0);
printf ("y_3_c0  = 0x%08X\n",y_3_c0);
printf ("y_1_c0  = 0x%08X\n",y_1_c0);


printf ("cr64_c1 = 0x%016X _mpy2\n",cr64_c1);
printf ("cr20_c1 = 0x%016X _mpy2\n",cr20_c1);
printf ("cb64_c4 = 0x%016X _mpy2\n",cb64_c4);
printf ("cb20_c4 = 0x%016X _mpy2\n",cb20_c4);

printf ("cr6_c1  = 0x%08X\n",cr6_c1);
printf ("cr2_c1  = 0x%08X\n",cr2_c1);
printf ("cb6_c4  = 0x%08X\n",cb6_c4);
printf ("cb2_c4  = 0x%08X\n",cb2_c4);

printf ("cr4_c1  = 0x%08X\n",cr4_c1);
printf ("cr0_c1  = 0x%08X\n",cr0_c1);
printf ("cb4_c4  = 0x%08X\n",cb4_c4);
printf ("cb0_c4  = 0x%08X\n",cb0_c4);

printf ("cg6     = 0x%08X _dotp2\n",cg6);
printf ("cg4     = 0x%08X _dotp2\n",cg4);
printf ("cg2     = 0x%08X _dotp2\n",cg2);
printf ("cg0     = 0x%08X _dotp2\n",cg0);


printf ("r_7     = 0x%08X _dotp2\n",r_7);
printf ("r_6     = 0x%08X _dotp2\n",r_6);
printf ("r_5     = 0x%08X _dotp2\n",r_5);
printf ("r_4     = 0x%08X _dotp2\n",r_4);
printf ("r_3     = 0x%08X _dotp2\n",r_3);
printf ("r_2     = 0x%08X _dotp2\n",r_2);
printf ("r_1     = 0x%08X _dotp2\n",r_1);
printf ("r_0     = 0x%08X _dotp2\n",r_0);

printf ("g_7     = 0x%08X _dotp2\n",g_7);
printf ("g_6     = 0x%08X _dotp2\n",g_6);
printf ("g_5     = 0x%08X _dotp2\n",g_5);
printf ("g_4     = 0x%08X _dotp2\n",g_4);
printf ("g_3     = 0x%08X _dotp2\n",g_3);
printf ("g_2     = 0x%08X _dotp2\n",g_2);
printf ("g_1     = 0x%08X _dotp2\n",g_1);
printf ("g_0     = 0x%08X _dotp2\n",g_0);

printf ("b_7     = 0x%08X _dotp2\n",b_7);
printf ("b_6     = 0x%08X _dotp2\n",b_6);
printf ("b_5     = 0x%08X _dotp2\n",b_5);
printf ("b_4     = 0x%08X _dotp2\n",b_4);
printf ("b_3     = 0x%08X _dotp2\n",b_3);
printf ("b_2     = 0x%08X _dotp2\n",b_2);
printf ("b_1     = 0x%08X _dotp2\n",b_1);
printf ("b_0     = 0x%08X _dotp2\n",b_0);


printf ("r_7654  = 0x%08X _spacku4\n",r_7654);
printf ("r_3210  = 0x%08X _spacku4\n",r_3210);
printf ("g_7654  = 0x%08X _spacku4\n",g_7654);
printf ("g_3210  = 0x%08X _spacku4\n",g_3210);
printf ("b_7654  = 0x%08X _spacku4\n",b_7654);
printf ("b_3210  = 0x%08X _spacku4\n",b_3210);

printf ("r_7654_ = 0x%08X\n",r_7654_);
printf ("g_7654_ = 0x%08X\n",g_7654_);
printf ("b_7654_ = 0x%08X\n",b_7654_);
printf ("r_3210_ = 0x%08X\n",r_3210_);
printf ("g_3210_ = 0x%08X\n",g_3210_);
printf ("b_3210_ = 0x%08X\n",b_3210_);


printf ("r_7654u = 0x%016X _mpyu4\n",r_7654u);
printf ("r_3210u = 0x%016X _mpyu4\n",r_3210u);
printf ("g_7654u = 0x%016X _mpyu4\n",g_7654u);
printf ("g_3210u = 0x%016X _mpyu4\n",g_3210u);
printf ("b_7654u = 0x%016X _mpyu4\n",b_7654u);
printf ("b_3210u = 0x%016X _mpyu4\n",b_3210u);

printf ("r_76u   = 0x%08X\n",r_76u);
printf ("r_32u   = 0x%08X\n",r_32u);
printf ("g_76u   = 0x%08X\n",g_76u);
printf ("g_32u   = 0x%08X\n",g_32u);
printf ("b_76u   = 0x%08X\n",b_76u);
printf ("b_32u   = 0x%08X\n",b_32u);
printf ("r_54u   = 0x%08X\n",r_54u);
printf ("r_10u   = 0x%08X\n",r_10u);
printf ("g_54u   = 0x%08X\n",g_54u);
printf ("g_10u   = 0x%08X\n",g_10u);
printf ("b_54u   = 0x%08X\n",b_54u);
printf ("b_10u   = 0x%08X\n",b_10u);

printf ("rgb_76  = 0x%08X\n",rgb_76);
printf ("rgb_54  = 0x%08X\n",rgb_54);
printf ("rgb_32  = 0x%08X\n",rgb_32);
printf ("rgb_10  = 0x%08X\n\n\n",rgb_10);
#endif

        /* ---------------------------------------------------------------- */
        /*  Store out the 8 pixels.                                         */
        /* ---------------------------------------------------------------- */
        _amem4(&rgb_data[i + 6]) = rgb_76;
        _amem4(&rgb_data[i + 4]) = rgb_54;
        _amem4(&rgb_data[i + 2]) = rgb_32;
        _amem4(&rgb_data[i + 0]) = rgb_10;
    }

    return;
}

/* ======================================================================== */
/*  End of file:  IMG_ycbcr422pl_to_rgb565.c                                */
/* ======================================================================== */
