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
/*     IMG_median_3x3_16_cn                                                 */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C-callable and can be called as:                    */
/*                                                                          */
/*      void IMG_median_3x3_16_cn                                           */
/*           (                                                              */
/*               const unsigned short *restrict i_data, // Input image      */
/*               int n,                                 // Length of input  */
/*               unsigned short       *restrict o_data  // Output image     */
/*           )                                                              */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      This kernel performs a 3x3 median filter operation on 16-bit        */
/*      unsigned values.  The median filter comes under the class           */
/*      of non-linear signal processing algorithms.                         */
/*                                                                          */
/*      Rather than replace the grey level at a pixel by a weighted         */
/*      average of the nine pixels including and surrounding it, the        */
/*      grey level at each pixel is replaced by the median of the nine      */
/*      values.  The median of a set of nine numbers is the middle          */
/*      element so that half of the elements in the list are larger and     */
/*      half are smaller.  Median filters remove the effects of extreme     */
/*      values from data, such as salt and pepper noise, although using     */
/*      a wide may result in unacceptable blurring of sharp edges in        */
/*      the original image.                                                 */
/*                                                                          */
/*      The C code of the algorithm has no restrictions.  The optimized     */
/*      implementations have restrictions, as noted under the "ASSUMPTIONS" */
/*      below.                                                              */
/*                                                                          */
/*                                                                          */
/*  TECHNIQUES                                                              */
/*      This implementation uses an incremental sorting technique to        */
/*      greatly reduce the number of compares and exchanges necessary       */
/*      to sort the image pixels.                                           */
/*                                                                          */
/*      The main loop reads three new pixels from the input image each      */
/*      iteration.  These three pixels form the right edge of the filter    */
/*      mask.  The filter data from the previous iteration is "slid         */
/*      over" by one pixel to form the complete 3x3 mask.                   */
/*                                                                          */
/*      As 3-pixel is read in from the image, the pixels are sorted,        */
/*      resulting in a "lo", "medium" and "hi" pixel value for that         */
/*      column.  The result is that the filter mask is sorted into          */
/*      three rows -- a row of "minimums", a row of "middle values",        */
/*      and a row of "maximums".                                            */
/*                                                                          */
/*      The median filter operates from this partially ordered mask.        */
/*      It finds the smallest element in the row of "maximums",             */
/*      the middle element in the row of "middle values", and               */
/*      the largest element in the row of "minimums".  The median           */
/*      value of these three values is the median for the entire 3x3        */
/*      mask.                                                               */
/*                                                                          */
/*      This process minimizes compares, as the whole mask does not         */
/*      need to be sorted between iterations.  Rather, the partial          */
/*      ordering for two of the three columns from one iteration is         */
/*      used directly for the next iteration.                               */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      The length 'n' must be a multiple of four.                          */
/*                                                                          */
/*   MEMORY NOTE                                                            */
/*      - No bank conflicts occur                                           */ 
/*      - No allignment restrictions on input/output buffers.               */
/*                                                                          */
/* ======================================================================== */

void IMG_median_3x3_16_cn
(
    const unsigned short *restrict i_data,
    int n,
    unsigned short       *restrict o_data
)
{
  unsigned short c0h, c1h, c2h, h_min;  /* "hi",  columns 0..2, and "min" */
  unsigned short c0m, c1m, c2m, m_mid;  /* "mid", columns 0..2, and "mid" */
  unsigned short c0l, c1l, c2l, l_max;  /* "lo",  columns 0..2, and "max" */
  unsigned short m_h, m_l, tmp, out;

  int i;

  /* -------------------------------------------------------------------- */
  /*  Start off with a well-defined initial state.                        */
  /* -------------------------------------------------------------------- */
  c1h = c2h = c1m = c2m = c1l = c2l = 0x7fff;

  /* -------------------------------------------------------------------- */
  /*  Iterate over the input row.                                         */
  /* -------------------------------------------------------------------- */
  for (i=0; i<n; i++) {
    /* ---------------------------------------------------------------- */
    /*  Slide our two previous columns of sorted pixels over by 1.      */
    /* ---------------------------------------------------------------- */
    c0h = c1h;    c1h = c2h;
    c0m = c1m;    c1m = c2m;
    c0l = c1l;    c1l = c2l;

    /* ---------------------------------------------------------------- */
    /*  Load in a new column of pixels, and sort into lo, med, high.    */
    /* ---------------------------------------------------------------- */
    c2h = i_data[i      ];
    c2m = i_data[i +   n];
    c2l = i_data[i + 2*n];
	
    if (c2l > c2h) { tmp = c2l; c2l = c2h; c2h = tmp; }
    if (c2l > c2m) { tmp = c2l; c2l = c2m; c2m = tmp; }
    if (c2m > c2h) { tmp = c2m; c2m = c2h; c2h = tmp; }

    /* ---------------------------------------------------------------- */
    /*  Find the minimum value of the "hi" terms.                       */
    /* ---------------------------------------------------------------- */
    h_min = c2h;
    if (c1h < h_min) { h_min = c1h; }
    if (c0h < h_min) { h_min = c0h; }

    /* ---------------------------------------------------------------- */
    /*  Find the middle value of the "mid" terms.                       */
    /* ---------------------------------------------------------------- */
    m_l   = c0m;
    m_mid = c1m;
    m_h   = c2m;

    if (m_l   > m_h  ) { tmp = m_l; m_l = m_h; m_h = tmp; }
    if (m_l   > m_mid) { m_mid = m_l; }
    if (m_mid > m_h  ) { m_mid = m_h; }

    /* ---------------------------------------------------------------- */
    /*  Find the maximum value of the "lo" terms.                       */
    /* ---------------------------------------------------------------- */
    l_max = c2l;
    if (c1l > l_max) { l_max = c1l; }
    if (c0l > l_max) { l_max = c0l; }

    /* ---------------------------------------------------------------- */
    /*  Find the middle value of "h_min", "m_mid", "l_max" into "out".  */
    /* ---------------------------------------------------------------- */
    out = m_mid;

    if (h_min > l_max) { tmp   = h_min; h_min = l_max; l_max = tmp; }
    if (h_min > out  ) { out   = h_min; }
    if (out   > l_max) { out   = l_max; }

    /* ---------------------------------------------------------------- */
    /*  Store the resulting pixel.                                      */
    /* ---------------------------------------------------------------- */
    o_data[i] = out;
  }
}

/*========================================================================= */
/*   End of file:  IMG_median_3x3_16_cn.c                                   */
/* ======================================================================== */

