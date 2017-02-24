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

#ifndef IMG_CORR_11X11_I8_C16S_C_H
#define IMG_CORR_11X11_I8_C16S_C_H 1

/* ======================================================================== */
/*  NAME                                                                    */
/*      IMG_corr_11x11_i8_c8s_cn                                            */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C-callable and can be called as:                    */
/*                                                                          */
/*          void IMG_corr_11x11_i8_c16s_cn                                  */
/*          (                                                               */
/*              const unsigned char    *restrict  imgin_ptr,                */
/*                    int              *restrict imgout_ptr,                */
/*                    short                           width,                */
/*                    short                           pitch,                */
/*              const short            *restrict   mask_ptr,                */
/*          )                                                               */
/*                                                                          */
/*      imgin_ptr :  pointer to an input  array of 8 bit pixels             */
/*      imgout_ptr:  pointer to an output array of 32 bit pixels            */
/*      width     :  number of output pixels                                */
/*      pitch     :  number of columns in the image                         */
/*      mask_ptr  :  pointer to 16 bit filter mask.                         */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      The correlation kernel accepts 11 rows of 'pitch' input pixels and  */
/*      produces one row of 'width' output pixels using the input mask of   */
/*      11x11. This correlation performs a point by point multiplication    */
/*      of 11x11 mask with the input image. The result of the 121 multipl-  */
/*      ications are then summed together to produce a 32-bit sum which is  */
/*      then stored in an output array. Overflow will not occur.            */
/*      The mask is moved one column at a time, advancing the mask over     */
/*      the entire image until the entire 'width' is covered. The masks     */
/*      are provided as 16-bit signed values and the input image pixels     */
/*      are provided as 8-bit unsigned values and the output pixels         */
/*      will be 32-bit signed. The image mask to be correlated is typically */
/*      part of the input image or another image.                           */
/*                                                                          */
/*      The natural C implementation has no restrictions. The Optimized     */
/*      and IntrinsiC codes has restrictions as noted in the ASSUMPTIONS    */
/*      below.                                                              */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      1. width:   'width' >=2 and a multiple of 2.                        */
/*      2. pitch:   'pitch' >= 'width'                                      */
/*      3. Input and Output arrays should not overlap                       */
/*      4. Output array should be double word aligned.                      */
/*      5. No restrictions on the alignment of Input array                  */
/*      6. Mask array should be half-word aligned.                          */
/*                                                                          */
/* ======================================================================== */

void IMG_corr_11x11_i8_c16s_cn
(
    const unsigned char    *restrict  imgin_ptr,
                   int     *restrict imgout_ptr,
                   short                  width, 
                   short                  pitch, 
    const          short   *restrict   mask_ptr
);

#endif

/* ======================================================================== */
/*  End of file:  IMG_corr_11x11_i8_c16s_c.h                                */
/* ======================================================================== */
