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

/* ######################################################################## */
/* #  TI Disclaimer: This kernel is obsolete. It is provided here for     # */
/* #  backward compatibility.                                             # */
/* ######################################################################## */

#ifndef IMG_FDCT_8X8_C_H_
#define IMG_FDCT_8X8_C_H_ 1

/* ======================================================================== */
/*  NAME                                                                    */
/*      IMG_fdct_8x8 -- 8x8 Block FDCT With Rounding, Endian Neutral.       */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine has the following C prototype:                         */
/*                                                                          */
/*          void IMG_fdct_8x8(short fdct_data[], unsigned num_fdcts)        */
/*                                                                          */
/*      The fdct routine accepts a list of 8x8 pixel blocks and performs    */
/*      FDCTs on each.  The array should be laid out identically to         */
/*      "fdct_data[num_fdcts][8][8]".  All operations in this array are     */
/*      performed entirely in-place.                                        */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      The fdct_8x8 function implements a Chen FDCT.  Output values are    */
/*      rounded, providing improved accuracy.  Input terms are expected     */
/*      to be signed 12Q0 values, producing signed 16Q0 results.  (A        */
/*      smaller dynamic range may be used on the input, producing a         */
/*      correspondingly smaller output range.  Typical applications         */
/*      include processing signed 9Q0 and unsigned 8Q0 pixel data,          */
/*      producing signed 13Q0 or 12Q0 outputs, respectively.)               */
/*                                                                          */
/*      Note:  This code guarantees correct operation, even in the case     */
/*      that 'num_fdcts == 0'.  In this case, the function performs an      */
/*      early exit without storing any results or intermediate values.      */
/*                                                                          */
/*  TECHNIQUES                                                              */
/*      I've applied a sqrt(2) scaling to each pass, which results in a     */
/*      fractional Q point at various points of the algorithm.  A chief     */
/*      benefit of this technique is that the F0 and F4 terms see no        */
/*      multiplies.  To perform this scaling, the C2 and C6 cosine terms    */
/*      are scaled up by sqrt(2), and the intermediate values in stage 2    */
/*      (s0, q0, s1, and q1) are also multiplied by sqrt(2).  The           */
/*      effect in stage 2 is to cancel the multiply by C4 on s0 and q0,     */
/*      and to introduce a multiply by 2*C4 on s1 and q1.                   */
/*                                                                          */
/*      The horizontal pass does not explicitly jump from block-to-block,   */
/*      since all horizontal rows are adjacent in memory.  (eg. Moving      */
/*      between rows within a block is identical to moving between the      */
/*      last row of one block and the first row of the next block.)         */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      n/a                                                                 */
/*                                                                          */
/*  NOTES                                                                   */
/*      n/a                                                                 */
/*                                                                          */
/*  SOURCE                                                                  */
/*      Chen FDCT.                                                          */
/* ======================================================================== */

void IMG_fdct_8x8_cn
(
    short    *dct_data,   /* Pointer to 8x8 DCT blocks "dct_data[num_fdcts][8][8]" */
    unsigned  num_fdcts   /* Number of DCT blocks */
);

#endif

/* ======================================================================== */
/*  End of file:  IMG_fdct_8x8_cn.h                                         */
/* ======================================================================== */
