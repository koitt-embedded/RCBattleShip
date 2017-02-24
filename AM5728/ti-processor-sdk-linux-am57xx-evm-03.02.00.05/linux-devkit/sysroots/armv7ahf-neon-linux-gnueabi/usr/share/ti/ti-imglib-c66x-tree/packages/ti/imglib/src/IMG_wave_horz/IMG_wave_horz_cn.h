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

#ifndef IMG_WAVE_HORZ_CN_H_
#define IMG_WAVE_HORZ_CN_H_ 1

/* ======================================================================== */
/*  NAME                                                                    */
/*           IMG_wave_horz_cn                                               */
/*                                                                          */
/*  USAGE                                                                   */
/*           This routine is C-callable and can be called as:               */
/*                                                                          */
/*          void IMG_wave_horz_cn                                           */
/*          (                                                               */
/*                short *in_data,                                           */
/*                short *qmf,                                               */
/*                short *mqmf,                                              */
/*                short *out_data,                                          */
/*                int   cols                                                */
/*          );                                                              */
/*                                                                          */
/*            in_data   = Input row of data                                 */
/*            qmf       = Qmf filter-bank for Low-Pass                      */
/*            mqmf      = Mirror qmf filter bank for High_pass              */
/*            out_data  = Output row of detailed decimated outputs          */
/*            cols      = Width of the input row                            */
/*                                                                          */
/*           (See the C compiler reference guide.)                          */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*     This kernel performs a 1D Periodic Orthogonal Wavelet decomp-        */
/*     osition. This also performs athe row decomposition in a 2D wavelet   */
/*     transform. An in put signal x[n] is first low pass and high pass     */
/*     filterd and decimated by two. This results in a reference signal     */
/*     r1[n] which is the decimated output obtained by dropping the odd     */
/*     samples of the low pass filtered output and a detail signal d[n]     */
/*     obtained by dropping the odd samples of the high-pass output. A      */
/*     circular convolution algorithm is implemented and hence the wave-    */
/*     let transform is periodic. The reference signal and the detail       */
/*     signal are half the size of the original signal. The reference       */
/*     signal may then be iterated again to perform another scale of        */
/*     multi-resolution analysis.                                           */
/*                                                                          */
/*     BIBLIOGRAPHY                                                         */
/*        A Wavelet Tour of Signal Processing Stephane' Mallat. Academic    */
/*        Press                                                             */
/*                                                                          */
/* ======================================================================== */

void IMG_wave_horz_cn
(
    const short *restrict in_data,  /* Row of input pixels  */
    const short *restrict qmf,      /* Low-pass QMF filter  */
    const short *restrict mqmf,     /* High-pass QMF filter */
    short       *restrict out_data, /* Row of output data   */
    int                   cols      /* Length of input.     */
);

#endif

/* ======================================================================== */
/*  End of file:  IMG_wave_horz_cn.h                                        */
/* ======================================================================== */
