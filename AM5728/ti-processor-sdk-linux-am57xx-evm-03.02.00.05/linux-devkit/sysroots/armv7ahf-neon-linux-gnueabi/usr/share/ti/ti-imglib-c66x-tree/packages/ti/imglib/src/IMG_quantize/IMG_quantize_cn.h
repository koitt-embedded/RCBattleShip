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

#ifndef IMG_QUANTIZE_CN_H_
#define IMG_QUANTIZE_CN_H_ 1

/* ======================================================================== */
/*  NAME                                                                    */
/*      IMG_quantize -- Matrix Quantization w/ Rounding, Little Endian      */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C callable, and has the following C prototype:      */
/*                                                                          */
/*      void IMG_quantize                                                   */
/*      (                                                                   */
/*          short           *data,      (* Data to be quantized.        *)  */
/*          unsigned short  num_blks,   (* Number of 64-element blocks. *)  */
/*          unsigned short  blk_sz,     (* Block size (multiple of 16). *)  */
/*          const short     *recip_tbl, (* Quant. values (reciprocals). *)  */
/*          int             q_pt        (* Q-point of Quant values.     *)  */
/*      )                                                                   */
/*                                                                          */
/*      The number of blocks, num_blks, must be at least 1.  The block      */
/*      size (number of elements in each block) must be at least 1.         */
/*      The Q-point, q_pt, controls rounding and final truncation; it       */
/*      must be in the range from 0 <= q_pt <= 31.                          */
/*                                                                          */
/*      The data[] array must be 'num_blks * blk_sz' elements, and the      */
/*      recip_tbl[] array must be 'blk_sz' elements.                        */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      The function IMG_quantize() quantizes matrices by multiplying their */
/*      contents with a second matrix that contains reciprocals of the      */
/*      quantization terms.  This step corresponds to the quantization      */
/*      that is performed in 2-D DCT-based compression techniques,          */
/*      although IMG_quantize() may be used on any signed 16-bit data using */
/*      signed 16-bit quantization terms.                                   */
/*                                                                          */
/*      IMG_quantize() merely multiplies the contents of the quantization   */
/*      matrix with the data being quantized.  Therefore, it may be used    */
/*      for inverse quantization as well, by setting the Q-point            */
/*      appropriately.                                                      */
/*                                                                          */
/*  TECHNIQUES                                                              */
/*      The inner loop steps through individual blocks, while the           */
/*      outer loop steps through reciprocals for quantization.  This        */
/*      eliminates redundant loads for the quantization terms.              */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      The Q-point, q_pt, must be in the range 0 <= q_pt <= 31.            */
/*                                                                          */
/*  NOTES                                                                   */
/*      No checking is performed on the input arguments for correctness.    */
/*                                                                          */
/*  SOURCE                                                                  */
/*      n/a                                                                 */
/*                                                                          */
/* ======================================================================== */

void IMG_quantize_cn
(
    short           *restrict data,         /* Data to be quantized.        */
    unsigned short  num_blks,               /* Number of 64-element blocks. */
    unsigned short  blk_size,               /* Block size (multiple of 16). */
    const short     *restrict recip_tbl,    /* Quant. values (reciprocals). */
    int             q_pt                    /* Q-point of Quant values.     */
);

#endif

/* ======================================================================== */
/*  End of file:  IMG_quantize_cn.h                                         */
/* ======================================================================== */
