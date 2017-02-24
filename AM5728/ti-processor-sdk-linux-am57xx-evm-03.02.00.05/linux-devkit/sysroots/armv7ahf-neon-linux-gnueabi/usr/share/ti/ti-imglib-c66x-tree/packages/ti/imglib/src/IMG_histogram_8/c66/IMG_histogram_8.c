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
/*      IMG_histogram_8                                                     */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C-callable and can be called as:                    */
/*                                                                          */
/*       void IMG_histogram_8 (unsigned char * image, int  n, int           */
/*                              accumulate, short * t_hist, short * hist)   */
/*                                                                          */
/*                image      =  input image data                            */
/*                n          =  number of points                            */
/*                accumulate =  defines add/subtract from existing          */
/*                              histogram: takes values 1, -1               */
/*                t_hist     =  temporary histogram bins (1024)             */
/*                hist       =  running histogram bins (256)                */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      This code takes a histogram of an array of n, 8 bit inputs. It      */
/*      returns the histogram of 256 bins at 16 bit precision. It can       */
/*      either add to, or subtract from, an existing histogram, using       */
/*      the 'accumulate' control.                                           */
/*                                                                          */
/*      It requires some temporary storage for 4 temporary histograms,      */
/*      which are later summed together.                                    */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      It is assumed that the temporary array of data, t_hist is           */
/*      initialized to zero.  The input array of image data must be         */
/*      aligned to a 4 byte boundary and n must be a multiple of 8.         */
/*      The maximum number of pixels that can be profiled in each bin       */
/*      is 32767 in the main histogram and the maximum n is 262143.         */
/*                                                                          */
/*  TECHNIQUES                                                              */
/*      This code operates on four interleaved histogram bins.  The loop    */
/*      is divided into two halves:  The "even" half operates on the        */
/*      even-numbered words from the input image, and the "odd" half        */
/*      operates on odd words.  Each half processes four pixels at a        */
/*      time, and both halves operate on the same four sets of histogram    */
/*      bins.  This introduces a memory dependency on the histogram bins    */
/*      which ordinarily would degrade performance.  To break the memory    */
/*      depenencies, the two halves forward their results to each other     */
/*      via the register file, bypassing memory.                            */
/*                                                                          */
/*      Exact memory access ordering obviates the need to predicate         */
/*      stores within the the loop.                                         */
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

#pragma CODE_SECTION (IMG_histogram_8,   ".text:optimized");

#include <c6x.h>


void IMG_histogram_8
(
    const unsigned char *restrict image, 
    int   n, 
    short accumulate,
    short *restrict t_hist, 
    short *restrict hist 
)
{
  /* -------------------------------------------------------------------- */
  /*  Perform histogram on image data.  Four separate histograms are      */
  /*  generated in an interleaved fashion, in order to avoid bank         */
  /*  conflicts.   Additional C scoping is used to increase the           */
  /*  effectiveness of the 'restrict' qualifiers on the pointers.         */
  /* -------------------------------------------------------------------- */
  {
    short              *restrict hist0 = &t_hist[0];
    short              *restrict hist1 = &t_hist[1];
    short              *restrict hist2 = &t_hist[2];
    short              *restrict hist3 = &t_hist[3];
    const unsigned int *restrict even_img = (const unsigned int*)&image[0];
    const unsigned int *restrict odd_img  = (const unsigned int*)&image[4];
    unsigned int        ha0o, bn0e, hs0e, ha0e, bn0o, hs0o;
    unsigned int        ha1o, bn1e, hs1e, ha1e, bn1o, hs1o;
    unsigned int        ha2o, bn2e, hs2e, ha2e, bn2o, hs2o;
    unsigned int        ha3o, bn3e, hs3e, ha3e, bn3o, hs3o;
    unsigned int        pix7654, pix3210;
    int                 i, j;

    _nassert(((unsigned)hist0)    % 8 == 0);
    _nassert(((unsigned)hist1)    % 8 == 2);
    _nassert(((unsigned)hist2)    % 8 == 4);
    _nassert(((unsigned)hist3)    % 8 == 6);
    _nassert(((unsigned)even_img) % 4 == 0);
    _nassert(((unsigned)odd_img)  % 4 == 0);
    _nassert(n % 8 == 0);

    /* ---------------------------------------------------------------- */
    /*  Seed 'previous odd pixel' with bogus bin values that won't      */
    /*  match the first even pixels.                                    */
    /* ---------------------------------------------------------------- */
    bn3o = 1;
    bn2o = 1;
    bn1o = 1;
    bn0o = 1;

    /* ---------------------------------------------------------------- */
    /*  Prefetch the initial bins for each of our four histograms.      */
    /*  This is needed for properly handling our forwarding logic.      */
    /* ---------------------------------------------------------------- */
    ha3o = hist3[bn3o];    /* read previous odd data */
    ha2o = hist2[bn2o];    /* read previous odd data */
    ha1o = hist1[bn1o];    /* read previous odd data */
    ha0o = hist0[bn0o];    /* read previous odd data */

    for (i=j=0; i<n; i+=8, j+=2) {
      /* ------------------------------------------------------------ */
      /*  Load 4 pixels from the even side of the image.  Extract     */
      /*  these so that our bin address is 4 * pixel_value.  (The     */
      /*  factor of 4 accounts for the interleave.)                   */
      /* ------------------------------------------------------------ */
      pix3210 = even_img[j];

      bn3e = (pix3210 >> 22) & 0x000003FC; /* extract byte 3 */
      bn2e = (pix3210 >> 14) & 0x000003FC; /* extract byte 2 */
      bn1e = (pix3210 >>  6) & 0x000003FC; /* extract byte 1 */
      bn0e = (pix3210 <<  2) & 0x000003FC; /* extract byte 0 */

      /* ------------------------------------------------------------ */
      /*  For each of the four even bins, do the following steps:     */
      /*   -- Read the current value of the bin for even pixel.       */
      /*   -- Store the update for the previous odd pixel.            */
      /*   -- Increment the value we read for even pixel's bin.       */
      /*   -- Add one more if even pixel equals previous odd pixel.   */
      /*      (Except on first iteration, since there is no prev.)    */
      /* ------------------------------------------------------------ */
      hs3e        = hist3[bn3e];      /* Get even bin.                */
      hs2e        = hist2[bn2e];      /* Get even bin.                */
      hs1e        = hist1[bn1e];      /* Get even bin.                */
      hs0e        = hist0[bn0e];      /* Get even bin.                */

      hist3[bn3o] = ha3o;             /* Save previous odd bin.       */
      hist2[bn2o] = ha2o;             /* Save previous odd bin.       */
      hist1[bn1o] = ha1o;             /* Save previous odd bin.       */
      hist0[bn0o] = ha0o;             /* Save previous odd bin.       */

      ha3e        = 1 + hs3e;         /* Update even bin.             */
      ha2e        = 1 + hs2e;         /* Update even bin.             */
      ha1e        = 1 + hs1e;         /* Update even bin.             */
      ha0e        = 1 + hs0e;         /* Update even bin.             */

      ha3e       += (bn3e == bn3o);   /* Add forwarding.              */
      ha2e       += (bn2e == bn2o);   /* Add forwarding.              */
      ha1e       += (bn1e == bn1o);   /* Add forwarding.              */
      ha0e       += (bn0e == bn0o);   /* Add forwarding.              */

      /* ------------------------------------------------------------ */
      /*  Load 4 pixels from the odd side of the image.               */
      /* ------------------------------------------------------------ */
      pix7654 = odd_img [j];

      bn3o = (pix7654 >> 22) & 0x000003FC;
      bn2o = (pix7654 >> 14) & 0x000003FC;
      bn1o = (pix7654 >>  6) & 0x000003FC;
      bn0o = (pix7654 <<  2) & 0x000003FC;

      /* ------------------------------------------------------------ */
      /*  For each of the four odd bins, do the following steps:      */
      /*   -- Read the current value of the bin for odd pixel.        */
      /*   -- Store the update for the previous even pixel.           */
      /*   -- Increment the value we read for odd pixel's bin.        */
      /*   -- Add one more if odd pixel equals previous even pixel.   */
      /* ------------------------------------------------------------ */
      hs3o        = hist3[bn3o];      /* Get odd bin.                 */
      hs2o        = hist2[bn2o];      /* Get odd bin.                 */
      hs1o        = hist1[bn1o];      /* Get odd bin.                 */
      hs0o        = hist0[bn0o];      /* Get odd bin.                 */

      hist3[bn3e] = ha3e;             /* Save previous even bin.      */
      hist2[bn2e] = ha2e;             /* Save previous even bin.      */
      hist1[bn1e] = ha1e;             /* Save previous even bin.      */
      hist0[bn0e] = ha0e;             /* Save previous even bin.      */

      ha3o        = 1 + hs3o;         /* Update odd bin.              */
      ha2o        = 1 + hs2o;         /* Update odd bin.              */
      ha1o        = 1 + hs1o;         /* Update odd bin.              */
      ha0o        = 1 + hs0o;         /* Update odd bin.              */

      ha3o       += (bn3o == bn3e);   /* Add forwarding.              */
      ha2o       += (bn2o == bn2e);   /* Add forwarding.              */
      ha1o       += (bn1o == bn1e);   /* Add forwarding.              */
      ha0o       += (bn0o == bn0e);   /* Add forwarding.              */
    }

    /* ---------------------------------------------------------------- */
    /*  Store final odd-pixel bin values.                               */
    /* ---------------------------------------------------------------- */
    hist3[bn3o] = ha3o;
    hist2[bn2o] = ha2o;
    hist1[bn1o] = ha1o;
    hist0[bn0o] = ha0o;
  }

  /* -------------------------------------------------------------------- */
  /*  Merge the four separate histograms into a single histogram, and     */
  /*  accumulate this into the final histogram buffer.                    */
  /* -------------------------------------------------------------------- */
  {
    int i;

    _nassert((int) t_hist % 8 == 0);
    _nassert((int) hist   % 8 == 0);
    
    #pragma UNROLL(4)

    /* ---------------------------------------------------------------- */
    /*  Note:  Manually unrolling to SIMD the "hist[i] +=" part may     */
    /*  give a slight performance boost.   I'd rather let the compiler  */
    /*  get it though.                                                  */
    /* ---------------------------------------------------------------- */
    for (i=0; i<256; i++) {
      hist[i] += accumulate * t_hist[i*4 + 0] 
              +  accumulate * t_hist[i*4 + 1] 
              +  accumulate * t_hist[i*4 + 2] 
              +  accumulate * t_hist[i*4 + 3];
    }
  }
}

/* ======================================================================== */
/*  End of file:  IMG_histogram_8.c                                         */
/* ======================================================================== */
