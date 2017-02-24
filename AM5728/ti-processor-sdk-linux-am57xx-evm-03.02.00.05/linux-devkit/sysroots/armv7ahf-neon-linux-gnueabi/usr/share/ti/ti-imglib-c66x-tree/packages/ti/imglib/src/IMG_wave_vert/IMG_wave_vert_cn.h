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

#ifndef IMG_WAVE_VERT_CN_H_
#define IMG_WAVE_VERT_CN_H_ 1

/* ======================================================================== */
/*  NAME                                                                    */
/*      IMG_wave_vert_cn                                                    */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C-callable and can be called as:                    */
/*                                                                          */
/*          void IMG_wave_vert_cn                                           */
/*          (                                                               */
/*              const short *restrict                                       */
/*                    const *restrict in_data,                              */
/*              const short *restrict lp_filt,                              */
/*              const short *restrict hp_filt,                              */
/*              short       *restrict out_ldata,                            */
/*              short       *restrict out_hdata,                            */
/*              int cols                                                    */
/*          )                                                               */
/*                                                                          */
/*          in_data   = Eight pointers to input image rows.                 */
/*          lp_filt   = Low-pass quadrature mirror filter coeffs (8 taps)   */
/*          hp_filt   = High-pass quadrature mirror filter coeffs (8 taps)  */
/*          out_ldata = Outgoing low-pass image data.                       */
/*          out_hdata = Outgoing high-pass image data.                      */
/*          cols      = Total number of colums in row of image.             */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      This function performs the vertical pass of 2D wavelet              */
/*      transform It performs a vertical filter on 8 rows which are         */
/*      pointed to by the pointers contained in an array of pointers.       */
/*      It produces two lines worth of output, one being the low-pass       */
/*      and the other being the high pass result.  Instead of               */
/*      transposing the input image and re-using the horizontal wavelet     */
/*      function, the vertical filter is applied directly to the image      */
/*      data as-is, producing a single line of high pass and a single       */
/*      line of low pass outputs.                                           */
/*                                                                          */
/*      This function accepts eight row pointers for the eight rows         */
/*      that form the context for the two filters.  It also accepts         */
/*      two output pointers, one for the high-pass filtered output          */
/*      and one for the low-pass filtered output.  Finally, it also         */
/*      accepts two input pointers for the low- and high-pass filters.      */
/*                                                                          */
/*      In a traditional wavelet implementation, for a given pair of        */
/*      output lines, the input context for the low-pass filter is          */
/*      offset by a number of lines from the input context for the          */
/*      high-pass filter.  The amount of offset is determined by the        */
/*      number of filter taps and is generally "num_taps - 2" rows.         */
/*      This implementation is fixed at 8 taps, so the offset would be      */
/*      6 rows.                                                             */
/*                                                                          */
/*      This implementation breaks from the traditional model so that       */
/*      it can reuse the same input context for both low-pass and           */
/*      high-pass filters simultaneously.  The result is that the           */
/*      low-pass and high-pass *outputs* must instead be offset by the      */
/*      calling function.  The following sample pseudo-code illustrates     */
/*      one possible method for producing the desired result.               */
/*                                                                          */
/*          // ------------------------------------------------------ //    */
/*          //  Iterate over whole input image, starting at the top.  //    */
/*          // ------------------------------------------------------ //    */
/*          for (y = 0; y < y_dim; y += 2)                                  */
/*          {                                                               */
/*              // -------------------------------------------------- //    */
/*              //  Set up our eight input pointers, wrapping around  //    */
/*              //  the bottom as necessary.                          //    */
/*              // -------------------------------------------------- //    */
/*              for (y0 = 0; y0 < 8; y0++)                                  */
/*                  in_data[y0] = in_image + ((y + y0) % y_dim) * x_dim;    */
/*                                                                          */
/*              // -------------------------------------------------- //    */
/*              //  Set up our output pointers.  The high-pass data   //    */
/*              //  is three rows ahead of the low-pass data.         //    */
/*              // -------------------------------------------------- //    */
/*              out_ldata = out_image + (y / 2);                            */
/*              out_hdata = out_image + ((y + 6) % y_dim) / 2 + y_dim;      */
/*                                                                          */
/*              // -------------------------------------------------- //    */
/*              //  Perform the wavelet.                              //    */
/*              // -------------------------------------------------- //    */
/*              wave_vert(in_data, lpf, hpf, out_ldata, out_hdata, x_dim);  */
/*          }                                                               */
/*                                                                          */
/*  BIBLIOGRAPHY                                                            */
/*      A Wavelet Tour of Signal Processing Stephane Mallat                 */
/*                                                                          */
/* ======================================================================== */

void IMG_wave_vert_cn
(
    const short *restrict
    const       *restrict in_data,   /* Array of row pointers */
    const short *restrict lp_filt,   /* Low pass QMF filter   */
    const short *restrict hp_filt,   /* High pass QMF filter  */
    short       *restrict out_ldata, /* Low pass output data  */
    short       *restrict out_hdata, /* High pass output data */
    int cols                         /* Length of rows to process */
);

#endif

/* ======================================================================== */
/*  End of file:  IMG_wave_vert_cn.h                                        */
/* ======================================================================== */
