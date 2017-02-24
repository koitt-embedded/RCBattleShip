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
/*     IMG_median_3x3_16s_cn                                                */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C-callable and can be called as:                    */
/*                                                                          */
/*          void IMG_median_3x3_16s_cn                                      */
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
/*  DESCRIPTION                                                             */
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
/*      The natural C implementation has no restrictions. The Optimized     */
/*      and IntrinsiC codes has restrictions as noted in the ASSUMPTIONS    */
/*      below.                                                              */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      1. The input array and output array should not overlap.             */
/*      2. Both input and output arrays must be double-word aligned.        */
/*      3. The minimum value for width of input image 'n' is 4.             */
/*      4. The width of input image 'n' must be a multiple of 4.            */
/*                                                                          */
/* ======================================================================== */

#pragma CODE_SECTION(IMG_median_3x3_16s_cn,   ".text:ansi");        


void IMG_median_3x3_16s_cn
(
    const short *restrict i_data,       
    int                        n,       
    short       *restrict o_data        
)
{
    short     prev_col0_0,     prev_col0_1,     prev_col0_2;
    short     prev_col1_0,     prev_col1_1,     prev_col1_2;    
    short     cur_col_0,       cur_col_1,       cur_col_2;
    short     r0_small,        r1_med,          r2_large;
    short     temp,            tmp_lo,          tmp_hi;
    short     median;
    int       cur_col_num;

    /*======================================================================*/
    /* Initialise with the middle value in the range of 16 bit signed short */
    /*======================================================================*/
    prev_col0_0 = 0;
    prev_col0_1 = 0;
    prev_col0_2 = 0;
    prev_col1_0 = 0;
    prev_col1_1 = 0;
    prev_col1_2 = 0;


    for(cur_col_num = 0; cur_col_num < n; cur_col_num++)
    {

        /*------------------------------------------------------------------*/
        /*      Load a new column of 3 pixels                               */
        /*------------------------------------------------------------------*/
        cur_col_0 = i_data[cur_col_num];
        cur_col_1 = i_data[n + cur_col_num];
        cur_col_2 = i_data[2 * n + cur_col_num];
        
        /*------------------------------------------------------------------*/
        /*   Sort the current column in the following :                     */
        /*      cur_col_0 - highest value, cur_col_2 - smallest value       */
        /*------------------------------------------------------------------*/
        
        if(cur_col_0 < cur_col_1)
        {               
            temp      = cur_col_0;
            cur_col_0 = cur_col_1;
            cur_col_1 = temp;
        } 
        if(cur_col_0 < cur_col_2)
        {                
            temp      = cur_col_0;
            cur_col_0 = cur_col_2;
            cur_col_2 = temp;
        }
        if(cur_col_1 < cur_col_2)
        {                
            temp      = cur_col_1;
            cur_col_1 = cur_col_2;
            cur_col_2 = temp;
        }

        /*------------------------------------------------------------------*/
        /* Find the smallest value in the first row (row 0)                 */
        /*------------------------------------------------------------------*/
        
        r0_small     = prev_col0_0;   
        if(prev_col1_0 < prev_col0_0)
        {
            r0_small = prev_col1_0;
        }
        if(cur_col_0 < r0_small)
        {
            r0_small = cur_col_0;
        }
                 
        /*------------------------------------------------------------------*/
        /* Find the medium value in the second row (row 1)                  */
        /*------------------------------------------------------------------*/
        
        r1_med     = prev_col1_1;
        tmp_lo     = prev_col0_1;
        tmp_hi     = cur_col_1;
        if(tmp_hi < tmp_lo)
        {
            temp   = tmp_hi;
            tmp_hi = tmp_lo;
            tmp_lo = temp;
        }
        if(r1_med < tmp_lo)
        {
            r1_med = tmp_lo;
        }
        if(r1_med > tmp_hi)
        {
            r1_med = tmp_hi;
        }

        /*------------------------------------------------------------------*/
        /* Find the largest value in the third row (row 2)                  */
        /*------------------------------------------------------------------*/
        
        r2_large     = prev_col0_2;   
        if(prev_col1_2 > prev_col0_2)
        {
            r2_large = prev_col1_2;
        }
        if(cur_col_2 > r2_large)
        {
            r2_large = cur_col_2;
        }

        /*------------------------------------------------------------------*/
        /* Find the mid value among r0_small, r1_med and r2_large to get    */
        /* the median                                                       */
        /*------------------------------------------------------------------*/
        
        median     = r1_med;
        tmp_lo     = r0_small;
        tmp_hi     = r2_large;
        if(tmp_hi < tmp_lo)
        {
            temp   = tmp_hi;
            tmp_hi = tmp_lo;
            tmp_lo = temp;
        }
        if(median < tmp_lo)
        {
            median = tmp_lo;
        }
        if(median > tmp_hi)
        {
            median = tmp_hi;
        }

        o_data[cur_col_num] = median;

        /*------------------------------------------------------------------*/
        /* Shift the current window (3x3) forward by a single column        */
        /*------------------------------------------------------------------*/
        
        prev_col0_0 = prev_col1_0; 
        prev_col0_1 = prev_col1_1; 
        prev_col0_2 = prev_col1_2;

        prev_col1_0 = cur_col_0; 
        prev_col1_1 = cur_col_1; 
        prev_col1_2 = cur_col_2;
         
    }
    
}

/* ======================================================================== */
/*  End of file:  IMG_median_3x3_16s_cn.c                                   */
/* ======================================================================== */              
