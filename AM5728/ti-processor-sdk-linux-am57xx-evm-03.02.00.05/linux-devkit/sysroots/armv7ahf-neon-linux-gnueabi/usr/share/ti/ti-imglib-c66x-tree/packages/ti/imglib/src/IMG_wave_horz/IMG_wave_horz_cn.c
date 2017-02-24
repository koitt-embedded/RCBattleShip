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
/*      IMG_wave_horz_cn                                                    */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C-callable and can be called as:                    */
/*                                                                          */
/*      i_data  = input row of data                                         */
/*      lp_filt = Low-pass quadrature mirror filter                         */
/*      hp_filt = High-pass quadrature mirror filter                        */
/*      o_data  = output row of detailed/reference decimated outputs        */
/*      x_dim   = width of the input row                                    */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      This kernel performs a 1D Periodic Orthogonal Wavelet               */
/*      decomposition.  This also performs athe row decomposition in a      */
/*      2D wavelet transform.  An in put signal x[n] is first low pass      */
/*      and high pass filterd and decimated by two.  This results in a      */
/*      reference signal r1[n] which is the decimated output obtained       */
/*      by dropping the odd samples of the low pass filtered output and     */
/*      a detail signal d[n] obtained by dropping the odd samples of        */
/*      the high-pass output.  A circular convolution algorithm is          */
/*      implemented and hence the wavelet transform is periodic.  The       */
/*      reference signal and the detail signal are half the size of the     */
/*      original signal.  The reference signal may then be iterated         */
/*      again to perform another scale of multi-resolution analysis.        */
/*                                                                          */
/*  BIBLIOGRAPHY                                                            */
/*      A Wavelet Tour of Signal Processing Stephane' Mallat. Academic      */
/*      Press                                                               */
/*                                                                          */
/* ======================================================================== */

#pragma CODE_SECTION(IMG_wave_horz_cn, ".text:ansi");


void IMG_wave_horz_cn
(
    const short *restrict i_data,    /* Row of input pixels  */
    const short *restrict lp_filt,   /* Low-pass QMF filter  */
    const short *restrict hp_filt,   /* High-pass QMF filter */
    short       *restrict o_data,    /* Row of output data   */
    int                   x_dim      /* Length of input.     */
)
{
    int i, j;

#ifndef NOASSUME
    _nassert(     x_dim       >= 8);
    _nassert(     x_dim   % 2 == 0);
    _nassert((int)lp_filt % 8 == 0);
    _nassert((int)hp_filt % 8 == 0);
    _nassert((int)i_data  % 8 == 0);
    _nassert((int)o_data  % 8 == 0);
#endif
    
    for (i = 0; i < x_dim; i += 2) {
        int lp_sum = 1 << 14;

        for (j = 0; j < 8; j++) {
            lp_sum += i_data[(i + j) % x_dim] * lp_filt[j];
        }
        o_data[i >> 1] = lp_sum >> 15;
    }

    for (i = 0; i < x_dim; i += 2) {
        int hp_sum = 1 << 14;

        for (j = 0; j < 8; j++) {
            hp_sum += i_data[(i + x_dim - 6 + j) % x_dim] * hp_filt[7 - j];
        }
        o_data[(i + x_dim) >> 1] = hp_sum >> 15;
    }
}

/* ======================================================================== */
/*  End of file:  IMG_wave_horz_cn.c                                        */
/* ======================================================================== */
