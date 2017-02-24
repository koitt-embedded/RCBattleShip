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

#ifndef IMG_CLIPPING_16S_CN_H_
#define IMG_CLIPPING_16S_CN_H_ 1

/* ======================================================================== */
/*  NAME                                                                    */
/*      IMG_clipping_16s_cn:                                                */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C-callable and has the prototype                    */
/*                                                                          */
/*      void IMG_clipping_16s_cn                                            */
/*      (                                                                   */
/*          const short *restrict x,    // Input matrix Pointer         //  */
/*          short              rows,    // Height of input matrix       //  */
/*          short              cols,    // Width of input matrix        //  */
/*          short       *restrict r,    // Output matrix Pointer        //  */
/*          short         THRES_MAX,    // User-Defined THRES_MAX value //  */
/*          short         THRES_MIN     // User-Defined THRES_MIN value //  */
/*      )                                                                   */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      The function truncates elements of a matrix to the maximum and      */
/*      minimum values defined by the user. Each element is 16-bit signed   */
/*      and the size of the matrix is user determined dimensions. The       */
/*      output matrix has the same size as that of the input matrix and     */
/*      each value will be truncated to minimum or maximum value defined    */
/*      by user based on whether it is lesser than the minimum value        */
/*      or greater than the maximum value respectively.                     */
/*                                                                          */
/*      The natural C implementation has no restrictions.The Optimized and  */
/*      IntrinsiC codes has restrictions as noted in the the ASSUMPTIONS    */
/*      below.                                                              */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      1. (rows * cols) >= 8 and should be a  multiples of 8               */
/*      2. THRES_MAX >= THRES_MIN                                           */
/*      3. Input and output arrays are double word - aligned.               */
/*      4. Input and output arrays should not overlap.                      */
/*                                                                          */
/* ======================================================================== */

void IMG_clipping_16s_cn
(
    const short *restrict x,        /* Input Matrix Pointer     */
    short              rows,        /* Height of input matrix   */
    short              cols,        /* Width of input matrix    */
    short       *restrict r,        /* Output matrix Pointer    */
    short         THRES_MAX,        /* Maximum Threshold Value  */
    short         THRES_MIN         /* Minimum Threshold Value  */
);

#endif

/* ======================================================================= */
/*  End of file:  IMG_clipping_16s_cn.h                                    */
/* ======================================================================= */
