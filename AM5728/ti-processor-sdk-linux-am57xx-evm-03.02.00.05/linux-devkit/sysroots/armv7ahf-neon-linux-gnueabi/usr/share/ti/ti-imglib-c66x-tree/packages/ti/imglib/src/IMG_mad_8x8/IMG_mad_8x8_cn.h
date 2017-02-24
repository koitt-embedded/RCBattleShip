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

#ifndef IMG_MAD_8x8_CN_H_
#define IMG_MAD_8x8_CN_H_ 1

/* ======================================================================== */
/*  NAME                                                                    */
/*      IMG_mad_8x8_cn -- Minimum Absolute Difference motion search         */
/*                                                                          */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C callable and has the following C prototype.       */
/*                                                                          */
/*      void IMG_mad_8x8_cn                                                 */
/*      (                                                                   */
/*          const unsigned char *refImg,    // Ref. image to search //      */
/*          const unsigned char *srcImg,    // Source 8x8 block     //      */
/*          int                 pitch,      // Width of ref image   //      */
/*          int sx, int sy,                 // Search window size   //      */
/*          unsigned int        *match      // Motion vector result //      */
/*      );                                                                  */
/*                                                                          */
/*      This routine accepts an 8x8 source block and a pointer to           */
/*      a window to search within a bitmap.  The pointer "refImg"           */
/*      points to the upper left corner of the search window.  The          */
/*      parameters "sx" and "sy" describe the dimensions of the search      */
/*      area.  The bitmap itself may be wider than the search window.       */
/*      It's width is described by the "pitch" argument.                    */
/*                                                                          */
/*      The search area dimensions specify the range of positions that      */
/*      the 8x8 source block is compared to.  This means that the           */
/*      actual bitmap area examined extends 7 pixels beyond the right       */
/*      and bottom edges of the search area within the reference image.     */
/*                                                                          */
/*      The best match position and its absolute difference are returned    */
/*      in match, packed as follows:                                        */
/*                                                                          */
/*                     31             16 15             0                   */
/*                     +----------------+----------------+                  */
/*           match[0]: |    X offset    |    Y offset    |                  */
/*                     +----------------+----------------+                  */
/*                                                                          */
/*                     31                               0                   */
/*                     +---------------------------------+                  */
/*           match[1]: |   Sum of absolute differences   |                  */
/*                     +---------------------------------+                  */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      The IMG_mad_8x8 function performs a full search for an 8x8 block    */
/*      within a specified search window.  It finds the position within     */
/*      the search window that has the Minimum Absolute Difference with     */
/*      respect to the given source block.                                  */
/*                                                                          */
/*      This type of search is useful for video algorithms which use        */
/*      motion compensation.  The search performed by this routine is a     */
/*      full search, meaning that all possible starting positions from      */
/*      [0, 0] to [sx-1, sy-1] are checked for potential matches.           */
/*                                                                          */
/*      The Absolute Difference metric is calculated by summing the         */
/*      absolute values of the differences between pixels in the            */
/*      source block and their corresponding pixels for the match           */
/*      point being evaluated in the reference image.  Smaller sums         */
/*      denote better matches--that is, less overall difference between     */
/*      the source block and match point in the reference block.            */
/*                                                                          */
/*      The algorithm returns the X and Y offsets of the best match         */
/*      point, as well as the calculated Absolute Difference for that       */
/*      position.  If two match points have equal Absolute Differences,     */
/*      the earlier block in the search sequence is returned.  The          */
/*      search presently checks in vertical stripes from top to bottom,     */
/*      moving from 1 column to the right after each stripe.                */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      The input pointers do not alias the output pointer for match.       */
/*                                                                          */
/* ======================================================================== */

void IMG_mad_8x8_cn
(
    const unsigned char *restrict refImg,
    const unsigned char *restrict srcImg,
    int                 pitch, 
    int                 sx, 
    int                 sy,
    unsigned int        *restrict match
);

#endif

/* ======================================================================== */
/*  End of file:  IMG_mad_8x8_cn.h                                          */
/* ======================================================================== */
