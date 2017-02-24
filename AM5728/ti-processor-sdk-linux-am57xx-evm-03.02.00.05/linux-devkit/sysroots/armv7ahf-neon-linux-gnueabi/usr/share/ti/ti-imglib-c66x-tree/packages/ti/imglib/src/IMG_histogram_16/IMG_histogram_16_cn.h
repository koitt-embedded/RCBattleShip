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

#ifndef IMG_HISTOGRAM_16_C_H_
#define IMG_HISTOGRAM_16_C_H_ 1

/* ======================================================================== */
/*  NAME                                                                    */
/*      IMG_histogram_16_cn                                                 */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C-callable and can be called as:                    */
/*                                                                          */
/*       void IMG_histogram_16_cn                                           */
/*       (                                                                  */
/*          unsigned short *restrict       in,                              */
/*                     int                  n,                              */
/*                     int         accumulate,                              */
/*          unsigned short *restrict   t_hist,                              */
/*          unsigned short *restrict     hist,                              */
/*                     int           img_bits                               */
/*       )                                                                  */
/*                                                                          */
/*           image      =  input image data                                 */
/*           n          =  number of points                                 */
/*           accumulate =  defines addition/subtract from existing          */
/*                         histogram: 1, -1                                 */
/*           t_hist     =  temporary histogram bins( (2^img_bits) * 4)      */
/*           hist       =  running histogram bins (2^img_bits)              */
/*           img_bits   =  number of valid data bits in a pixel.            */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      This code takes a histogram of an array (of type short) with n      */
/*      number of pixels, with "img_bits" being the number of               */
/*      valid data bits in a pixel. It returns the histogram of             */
/*      corresponding number of bins at "img_bits" bits precision. It can   */
/*      either add or subtract to an existing histogram, using the          */
/*      'accumulate' control.  It requires some temporary storage for 4     */
/*      temporary histograms, which are later summed together.The length    */
/*      of the hist and the t_hist arrays depends on the value of           */
/*      "img_bits" . Actual length of hist is (2 ^IMG_BITS) and that of     */
/*      t_hist is (4 * (2 ^ IMG_BITS)) as there are no pixel values greater */
/*      than or equal to  (2 ^ IMG_BITS) in the given image.                */
/*                                                                          */
/*                                                                          */
/*      The natural C implementation has no restrictions. The Optimized     */
/*      and IntrinsiC codes have restrictions as noted in the ASSUMPTIONS   */
/*      below.                                                              */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      1. 'n' must be a multiple of 8 and greater than or equal to 8.      */
/*      2. The arrays t_hist is initialized to zero.                        */
/*      3. all arrays must be double word aligned.                          */
/*      5. Input and output arrays do not overlap.                          */
/*      6. img_bits must be atleast 1 and at most 16                        */
/*      7. Max number of pixels that can be profiled in each bin is 32767   */
/*                                                                          */
/*  TECHNIQUES                                                              */
/*      This code operates on four interleaved histogram bins.  The loop    */
/*      is divided into two halves:  The "even" half operates on the        */
/*      even-numbered double-words from the input image, and the "odd"      */
/*      half operates on odd double-words.  Each half processes four        */
/*      pixels at a time, and both halves operate on the same four sets     */
/*      of histogram bins. This introduces a memory dependency on the       */
/*      histogram bins which ordinarily would degrade performance. To       */
/*      break the memory depenencies, the two halves forward their results  */
/*      to each other via the register file, bypassing memory.              */
/*                                                                          */
/*      Exact memory access ordering obviates the need to predicate         */
/*      stores within the loop.                                             */
/*                                                                          */
/*      The algorithm is ordered as follows:                                */
/*                                                                          */
/*        1. Load from histogram for even half                              */
/*        2. Store odd_bin to histogram for odd half (previous itn.)        */
/*        3. if data_even == previous data_odd increment even_bin by 2      */
/*           else increment even_bin by 1, forward to odd                   */
/*        4. Load from histogram for odd half (current itn.)                */
/*        5. Store even_bin to histogram for even half                      */
/*        6. if data_odd == previous data_even increment odd_bin by 2       */
/*           else increment odd_bin by 1, forward to even                   */
/*        7. goto 1.                                                        */
/*                                                                          */
/*      With this particular ordering, forwarding is necessary between      */
/*      even/odd halves when pixels in adjacent halves need to be           */
/*      placed in the same bin.                                             */
/*      The store is never predicated and occurs speculatively              */
/*      as it will be overwritten by the next value containing the          */
/*      extra forwarded value.                                              */
/*                                                                          */
/*      The four histograms are interleaved with each bin spaced four       */
/*      half-words apart and each histogram starting in a different         */
/*      memory bank. This allows the four histogram accesses to             */
/*      proceed in any order without worrying about bank conflicts.         */
/*      The diagram below illustrates this:  (addresses are halfword        */
/*      offsets)                                                            */
/*                                                                          */
/*           0       1       2       3       4       5       6   ...        */
/*       | hst 0 | hst 1 | hst 2 | hst 3 | hst 0 | hst 1 | ...   ...        */
/*       | bin 0 | bin 0 | bin 0 | bin 0 | bin 1 | bin 1 | ...   ...        */
/*                                                                          */
/* ======================================================================== */

void IMG_histogram_16_cn
(
     unsigned short *restrict    image,  /* input image data                */
                int                  n,  /* number of input image pixels    */
                int         accumulate,  /* define add/sum for histogtram   */
              short *restrict   t_hist,  /* temporary histogram bins        */
              short *restrict     hist,  /* running histogram bins          */
                int           img_bits   /* number of data bits in a pixel  */
);

#endif

/* ======================================================================== */
/*  End of file:  IMG_histogram_16_cn.h                                     */
/* ======================================================================== */
