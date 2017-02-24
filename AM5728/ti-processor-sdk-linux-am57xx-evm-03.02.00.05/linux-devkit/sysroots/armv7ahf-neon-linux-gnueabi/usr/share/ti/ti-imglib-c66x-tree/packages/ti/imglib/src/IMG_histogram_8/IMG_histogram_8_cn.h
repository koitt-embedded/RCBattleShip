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

#ifndef IMG_HISTOGRAM_8_C_H_
#define IMG_HISTOGRAM_8_C_H_ 1

/* ======================================================================== */
/*  NAME                                                                    */
/*      IMG_histogram_8_cn                                                  */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C-callable and can be called as:                    */
/*                                                                          */
/*       void IMG_histogram_8_cn                                            */
/*       (                                                                  */
/*          unsigned short *restrict    image,                              */
/*                     int                  n,                              */
/*                     int         accumulate,                              */
/*          unsigned short *restrict   t_hist,                              */
/*          unsigned short *restrict     hist,                              */
/*       )                                                                  */
/*                                                                          */
/*           image      =  input image data                                 */
/*           n          =  number of points                                 */
/*           accumulate =  defines addition/subtract from existing          */
/*                         histogram: 1, -1                                 */
/*           t_hist     =  temporary histogram bins (1024)                  */
/*           hist       =  running histogram bins (256)                     */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      This code takes a histogram of an array of n, 8 bit inputs. It      */
/*      returns the histogram of 256 bins at 16 bit precision.  It can      */
/*      either add or subtract to an existing histogram, using the          */
/*      'accumulate' control.  It requires some temporary storage for 4     */
/*      temporary histograms, which are later summed together.              */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      It is assumed that the array of data, t_hist is initialized         */
/*      to zero.  The input array of image data must be aligned to an 8     */
/*      byte boundary and n must be a multiple of 8.  The maximum number    */
/*      of pixels that can be profiled in each bin is 65535 in the main     */
/*      histogram and the maximum n is 262143.                              */
/* ======================================================================== */

void IMG_histogram_8_cn
(
    const unsigned char *restrict image,
    int   n, 
    short accumulate,
    short *restrict t_hist,
    short *restrict hist
);

#endif

/*============================================================================*/
/*  End of file:  IMG_histogram_8_cn.h                                        */
/*============================================================================*/
