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

#ifndef IMG_SOBEL_3X3_16_C_H_
#define IMG_SOBEL_3X3_16_C_H_ 1

/* ======================================================================== */
/*  NAME                                                                    */
/*      IMG_sobel_3x3_16_cn                                                 */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C-callable and can be called as:                    */
/*                                                                          */
/*      void IMG_sobel_3x3_16_cn                                            */
/*      (                                                                   */
/*          const unsigned short *in_data,    // Input image data           */
/*          unsigned short       *out_data,   // Output image data          */
/*          short cols, short rows     	     // Image dimensions            */
/*      )                                                                   */
/*                                                                          */
/*      The IMG_sobel filter is applied to the input image. The input image */
/*      dimensions are given by the arguments 'cols' and 'rows'.  The       */
/*      output image is 'cols' pixels wide and 'rows - 2' pixels tall.      */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*                                                                          */
/*      To see how the implementation is going to work on the input         */
/*      buffer, lets imagine we have the following input buffer:            */
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
/*          X = IMG_sobel(x)    The algorithm is applied to that pixel.     */
/*                          The correct output is obtained, the data        */
/*                          around the pixels we work on is used            */
/*                                                                          */
/*          t               Whatever was in the output buffer in that       */
/*                          position is kept there.                         */
/*                                                                          */
/*          z = IMG_sobel(y)    The algorithm is applied to that pixel.     */
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
/*      The C code is functionally equivalent to the serial-assembly code   */
/*      without restrictions. The assembly code may impose additional       */
/*      restrictions.                                                       */
/*                                                                          */
/*  TECHNIQUES                                                              */
/*      Four output pixels are computed per iteration using loop unrolling  */
/*      and packed operations.                                              */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      At least four output pixels must be processed.                      */
/*      The input image width must be even (eg. 'cols' must be even).       */
/*      rows >= 3                                                           */
/*                                                                          */
/*  MEMORY NOTE                                                             */
/*      No bank conflicts occur.                                            */
/*      There are no alignment restrictions.                                */
/*                                                                          */
/*  NOTES                                                                   */
/*      This is a LITTLE ENDIAN implementation.                             */
/*      The image arrays do not need to be aligned.                         */
/*                                                                          */
/*      The values of the left-most and right-most pixels on each line      */
/*      of the output are not well-defined.                                 */
/*                                                                          */
/* ======================================================================== */

void IMG_sobel_3x3_16_cn
(
    const unsigned short *restrict in,   /* Input image data   */
          unsigned short *restrict out,  /* Output image data  */
                   short           cols, /* Image columns      */ 
                   short           rows  /* Image rows         */
);

#endif

/* ======================================================================== */
/*   End of file:  IMG_sobel_3x3_16_cn.h                                    */
/* ======================================================================== */

