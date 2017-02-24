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
/* NAME                                                                     */
/*     IMG_median_3x3_16s                                                   */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C-callable and can be called as:                    */
/*                                                                          */
/*          void IMG_median_3x3_16s                                         */
/*          (                                                               */
/*             const short *restrict i_data,                                */
/*             int                        n,                                */
/*             short       *restrict o_data                                 */
/*          )                                                               */
/*                                                                          */
/*      i_data  == Input image containing 3 rows (i.e., size of 3 x n).     */
/*      n       == Width of input image.                                    */
/*      o_data  == Output image containing 1 row (i.e., size of 1 x n).     */
/*                                                                          */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*                                                                          */
/*      This kernel performs a 3x3 median filter operation on 16-bit        */
/*      signed image pixels. The grey level at each pixel is replaced by    */
/*      the median of nine adjacent values. The median of a set of nine     */
/*      numbers is the middle element so that half of the elements in the   */
/*      list are larger and half are smaller. The input image contains 3    */
/*      adjacent rows from an actual image. The output array will be of     */
/*      size 1 row containing the median values of the middle row of the    */
/*      input. For the first two output's, the two columns outside the      */
/*      image are assumed to be all zeros.                                  */
/*                                                                          */
/*      The first 2 values in the output array will not be containing       */
/*      any meaningful data. The 3rd value in the output array will be      */
/*      the median of 2nd value in the middle row of input array and so on. */
/*      The nth value in the output array will be the median of the (n-1)th */
/*      value in the mid row of input array. Hence the output array will    */
/*      not contain the median values of first and last elements in the     */
/*      middle row of input image. Instead it will contain 2 meaningless    */
/*      values at the beginning of the array.                               */
/*                                                                          */
/*                                                                          */
/*  TECHNIQUES                                                              */
/*                                                                          */
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
/*      The natural C implementation has no restrictions. The Optimized     */
/*      and IntrinsiC codes has restrictions as noted in the ASSUMPTIONS    */
/*      below.                                                              */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*                                                                          */
/*      1. The input array and output array should not overlap.             */
/*      2. Both input and output arrays must be double-word aligned.        */
/*      3. The minimum value for width of input image 'n' is 4.             */
/*      4. The width of input image 'n' must be a multiple of 4.            */
/*                                                                          */
/*  COMPATIBILITY                                                           */
/*      This code is compatible for both C64x and C64x+ processors.         */
/* ======================================================================== */

#pragma CODE_SECTION(IMG_median_3x3_16s,   ".text:optimized");


void IMG_median_3x3_16s
(
    const short *restrict i_data,
    int                        n,
    short       *restrict o_data
)
{
  long long   R0_5432,  R1_5432,  R2_5432;
  long long   HI_5432,  MD_5432,  LO_5432;
  long long   HI_4321,  MD_4321,  LO_4321;
  long long   HI_3210,  MD_3210,  LO_3210;
  long long   C_max1,   C_min1,   C_min2;
  long long   d_med_max1, d_med_min1, d_med_min2, d_median2;
  long long   d_min_max,  d_med_med,  d_max_min;
  int         HI_10,    MD_10,    LO_10;
  int         MIN_HI,   MIN_LO,   MAX_HI,   MAX_LO;
  int         i;


  /*====================================================================*/
  /* Initialise with middle value in range of 16 bit signed short       */
  /*====================================================================*/
  HI_10 = 0L;
  MD_10 = 0L;
  LO_10 = 0L;
  

  /*====================================================================*/
  /* Inform the compiler about assumptions that can be made.            */
  /* 1. Minimum value for width of input image 'n' is 4.                */
  /* 2. Width of input image 'n' is a multiple of 4.                    */
  /* 3. All the 3 adjacent rows in input array are double-word aligned. */
  /* 4. Output image array is double-word aligned.                      */
  /*====================================================================*/
  _nassert (          n       >= 4);
  _nassert (          n  % 4  == 0);
  _nassert ((int) i_data % 8  == 0);
  _nassert ((int) o_data % 8  == 0);

  #pragma MUST_ITERATE(1,,1)
  #pragma UNROLL(1)
  for (i=0 ;i<n; i+=4) {
   
    /*==================================================================*/
    /* Get the input into x0_01,x1_01,x2_01 each containing 2 elements  */
    /* Get 2 columns of 3 rows of elements sorted columnwise in         */      
    /* descending order                                                 */      
    /*==================================================================*/
    R0_5432   = _mem8_const ((void *) &i_data[i        ]);
    R1_5432   = _mem8_const ((void *) &i_data[i +     n]);
    R2_5432   = _mem8_const ((void *) &i_data[i + 2 * n]);
   
    C_max1   = _dmax2(R0_5432,R1_5432);
    C_min1   = _dmin2(R0_5432,R1_5432);
    /* The following replaces "_dmin2" to make use of S unit */
    MIN_HI   = _min2(_hill(C_max1),_hill(R2_5432));
    MIN_LO   = _min2(_loll(C_max1),_loll(R2_5432));
    C_min2   = _itoll(MIN_HI,MIN_LO);
    

    /*==================================================================*/
    /* Sorted columns                                                   */   
    /*==================================================================*/
    HI_5432  = _dmax2(C_max1,R2_5432);
    MD_5432  = _dmax2(C_min1,C_min2);
    /* The following replaces "_dmin2" to make use of S unit */
    MIN_HI   = _min2(_hill(C_min1),_hill(C_min2));
    MIN_LO   = _min2(_loll(C_min1),_loll(C_min2));
    LO_5432  = _dmv(MIN_HI,MIN_LO);

    HI_3210  = _dmv(_loll(HI_5432),HI_10);
    MD_3210  = _dmv(_loll(MD_5432),MD_10);
    LO_3210  = _dmv(_loll(LO_5432),LO_10);
    
    HI_4321  = _dpacklh2(HI_5432,HI_3210);
    MD_4321  = _dpacklh2(MD_5432,MD_3210);
    LO_4321  = _dpacklh2(LO_5432,LO_3210);


    /*==================================================================*/
    /* Find the min value among R00, R01,row0_pk to get min of max      */
    /*==================================================================*/
    d_min_max = _dmin2(HI_5432,HI_3210);
    d_min_max = _dmin2(d_min_max,HI_4321);
    

    /*==================================================================*/
    /* Find the med value among R10,R11,row1_pk to get med of med       */
    /*==================================================================*/
    d_med_max1 = _dmax2(MD_5432,MD_3210);
    d_med_min1 = _dmin2(MD_5432,MD_3210);
    d_med_min2 = _dmin2(d_med_max1,MD_4321);
    /* The following replaces "_dmax2" to make use of S unit */
    MAX_HI     = _max2(_hill(d_med_min1), _hill(d_med_min2));
    MAX_LO     = _max2(_loll(d_med_min1), _loll(d_med_min2));
    d_med_med  = _dmv(MAX_HI,MAX_LO);

    /*==================================================================*/
    /* Find the max value among R20,R21,row2_pk to get max of min       */
    /*==================================================================*/
    d_max_min = _dmax2(LO_5432,LO_3210);
    d_max_min = _dmax2(d_max_min,LO_4321);
    

    /*==================================================================*/
    /* Find the med value among min_max,med_med and max_min             */
    /*==================================================================*/
    d_med_max1 = _dmax2(d_min_max,d_med_med);
    d_med_min1 = _dmin2(d_min_max,d_med_med);
    d_med_min2 = _dmin2(d_med_max1,d_max_min);
    d_median2  = _dmax2(d_med_min1,d_med_min2);


    /*==================================================================*/
    /* Write these four (median) values out                             */
    /*==================================================================*/
    _mem8 ((void * ) &o_data[i]) = d_median2;
    

    /*==================================================================*/
    /* Store the already sorted columns into R00, R10 and R20           */
    /*==================================================================*/
    HI_10 = _hill(HI_5432);
    MD_10 = _hill(MD_5432);
    LO_10 = _hill(LO_5432);
  }
}

/* ======================================================================== */
/*  End of file:  IMG_median_3x3_16s.c                                      */
/* ======================================================================== */
