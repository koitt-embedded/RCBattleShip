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
/*      IMG_corr_gen_i16s_c16s_cn                                           */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C-callable and can be called as:                    */
/*                                                                          */
/*      void IMG_corr_gen_i16s_c16s_cn                                      */
/*      (                                                                   */
/*          short   *x,                                                     */
/*          short   *h,                                                     */
/*          short   *y,                                                     */
/*          int     m,                                                      */
/*          int     pitch                                                   */
/*      );                                                                  */
/*                                                                          */
/*      x[]   : Input pixel array.                                          */
/*      h[M]  : Input 1xM mask array                                        */
/*      y[]   : Output array of correlation sum                             */
/*      M     : Length of filter.                                           */
/*      pitch : Width of input image                                        */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      The routine performs a generalized correlation with a 1 by M tap    */
/*      filter. It can be called repetitively to form an arbitrary MxN 2D   */
/*      generalized correlation kernel. The correlation sum is stored as    */
/*      half words. The input pixel, and mask data is assumed to come in    */
/*      as shorts.  No restrictions apply to pitch and M.                   */
/*                                                                          */
/*      If the width of the input image is pitch and the mask is M then     */
/*      the output array must have at-least a dimension of (pitch - m + 8). */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      - Array x[] must be word aligned, array y[ ] must be double-word    */
/*        aligned, and array h[ ] must be half-word aligned.                */
/*      - Internal accuracy is 16 bits. The convloution sum should not      */
/*        exceed 16 bit's (signed).                                         */
/*      - Output array size must be at-least (pitch - m + 8)                */
/*      - pitch > m                                                         */
/*                                                                          */
/* ======================================================================== */

#pragma CODE_SECTION(IMG_corr_gen_i16s_c16s_cn, ".text:ansi");

void IMG_corr_gen_i16s_c16s_cn
(
    const short *restrict x, 
    const short *restrict h, 
    short       *restrict y, 
    int                   m, 
    int                   pitch 
) 
{
  int i, j;

#ifndef NOASSUME
  _nassert((int) x % 8 == 0);
  _nassert((int) y % 8 == 0);
  _nassert((int) h % 8 == 0);
  _nassert(      m     >  0);
  #pragma MUST_ITERATE(1,,1);
#endif

  for (j=0; j<(pitch-m); j++) {
    for (i=0; i<m; i++) {
      y[j] += x[i + j] * h[i];
    }
  }
}

/* ======================================================================== */
/*  End of file:  IMG_corr_gen_i16s_c16s_cn.c                               */
/* ======================================================================== */
