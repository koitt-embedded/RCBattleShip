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

#pragma CODE_SECTION(IMG_histogram_8_cn,   ".text:ansi");

void IMG_histogram_8_cn
(
    const unsigned char *restrict image,
    int   n, 
    short accumulate,
    short *restrict t_hist,
    short *restrict hist
)
#if 1
{
    /* -------------------------------------------------------------------- */
    /*  This is pretty much bit-exact with our optimized implementation.    */
    /* -------------------------------------------------------------------- */
    int p0, p1, p2, p3, i;

#ifndef NOASSUME
    _nassert((int)t_hist % 8 == 0);
    _nassert((int)hist   % 8 == 0);
    _nassert(n % 8 == 0);
    _nassert(n >= 8);    
    #pragma MUST_ITERATE(2,,2);
#endif

    /* -------------------------------------------------------------------- */
    /*  This loop is unrolled four times, producing four interleaved        */
    /*  histograms into a temporary buffer.                                 */
    /* -------------------------------------------------------------------- */
    for (i = 0; i < n; i += 4)
    {
        p0 = image[i + 0] * 4 + 0;
        p1 = image[i + 1] * 4 + 1;
        p2 = image[i + 2] * 4 + 2;
        p3 = image[i + 3] * 4 + 3;

        t_hist[p0]++;
        t_hist[p1]++;
        t_hist[p2]++;
        t_hist[p3]++;
    }

    /* -------------------------------------------------------------------- */
    /*  Accumulate the interleaved histograms back into the final           */
    /*  histogram buffer.                                                   */
    /* -------------------------------------------------------------------- */
    for (i = 0; i < 256; i++)
    {
        hist[i] += (t_hist[i*4 + 0] +
                    t_hist[i*4 + 1] +
                    t_hist[i*4 + 2] +
                    t_hist[i*4 + 3]) * accumulate;
    }
}
#else
{
    /* -------------------------------------------------------------------- */
    /*  This is the cannonical form for Histogram.  We cannot use this      */
    /*  here, as it does not use the temporary array "t_hist", and that's   */
    /*  an "output" of our code.                                            */
    /* -------------------------------------------------------------------- */
    int pixel, j; 
    for (j = 0; j < n; j++) 
    {
        pixel = (int) image[j];
        hist[pixel] += accumulate;
    }
}
#endif

/* ======================================================================== */
/*  End of file:  IMG_histogram_8_cn.c                                      */
/* ======================================================================== */
