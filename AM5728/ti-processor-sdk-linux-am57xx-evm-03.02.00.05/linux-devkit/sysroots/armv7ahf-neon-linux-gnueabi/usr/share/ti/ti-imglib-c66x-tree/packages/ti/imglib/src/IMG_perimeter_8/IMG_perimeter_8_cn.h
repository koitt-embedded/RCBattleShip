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

#ifndef IMG_PERIMETER_8_C_H_
#define IMG_PERIMETER_8_C_H_ 1

/* ======================================================================== */
/*  NAME                                                                    */
/*      IMG_perimeter_8_cn                                                  */
/*                                                                          */
/*  USAGE                                                                   */
/*      This function is C callable, and has the following prototype:       */
/*                                                                          */
/*          int IMG_perimeter_8_cn                                          */
/*          (                                                               */
/*              const unsigned char *restrict in,  // Input image    //     */
/*              int cols,                          // Width of input //     */
/*              unsigned char       *restrict out  // Output image   //     */
/*          );                                                              */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      This function returns the boundary pixels of an image.              */
/*      Each call of IMG_perimeter_8() calculates one new line of output    */
/*      from a three line window of input.                                  */
/*                                                                          */
/*      The input pointer "in" points to the middle line of a three-line    */
/*      window of the image.  The perimeter function scans this window      */
/*      looking for pixels in the middle row which are on the perimeter     */
/*      of the image.  A pixel is on the perimeter of the image if          */
/*      the pixel itself is non-zero, but one of its neighbors is zero.     */
/*      The total count of perimeter pixels is returned.                    */
/*                                                                          */
/*      This particular implementation evaluates four neighbors for         */
/*      the perimeter test:  The neighbors to the left, right, top          */
/*      and bottom.                                                         */
/*                                                                          */
/*      Perimeter pixels retain their original grey level in the            */
/*      output.  Non-perimeter pixels are set to zero in the output.        */
/*      Pixels on the far left and right edges of a row are defined         */
/*      as *not* being on the perimeter, and are always forced to           */
/*      zero.                                                               */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      The optimized implementations assume that the input and output      */
/*      arrays are double-word aligned.  They also assume that the          */
/*      input is a multiple of 16 pixels long.                              */
/*                                                                          */
/* ======================================================================== */

int IMG_perimeter_8_cn
(
    const unsigned char *restrict in,
    int cols,
    unsigned char       *restrict out
);

#endif

/* ======================================================================== */
/*  End of file:  IMG_perimeter_8_cn.h                                      */
/* ======================================================================== */
