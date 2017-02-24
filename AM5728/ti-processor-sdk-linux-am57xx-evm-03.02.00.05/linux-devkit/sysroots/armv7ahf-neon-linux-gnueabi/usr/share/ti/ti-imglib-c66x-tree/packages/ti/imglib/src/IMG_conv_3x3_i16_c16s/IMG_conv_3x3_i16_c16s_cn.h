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

#ifndef  IMG_CONV_3X3_I16_C16S_C_H_
#define  IMG_CONV_3X3_I16_C16S_C_H_ 1

/* ======================================================================== */
/*  NAME                                                                    */
/*     IMG_conv_3x3_i16_c16s                                                */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine has the following C prototype:                         */
/*                                                                          */
/*      void IMG_conv_3x3_i16_c16s(                                         */
/*                           const unsigned short *restrict imgin_ptr,      */
/*                                 unsigned short *restrict imgout_ptr,     */
/*                                          int             width,          */
/*                           const          short *restrict mask_ptr,       */
/*                                          int             shift)          */
/*                                                                          */
/*     imgin_ptr   : pointer to an input array of unsigned 16 bit pixels    */
/*     imgout_ptr  : pointer to an output array of 16 bit pixels            */
/*     width       : number of output pixels                                */
/*     mask_ptr    : pointer to 3x3 16 bit filter mask.                     */
/*     shift       : user specified shift amount                            */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*     The convolution kernel accepts three rows of 'width' input points    */
/*     and produces one output row of 'width' points using the input mask   */
/*     of 3 by 3. The user defined shift value is used to shift the convo-  */
/*     lution value, down to the 16-bit range. The convolution sum is also  */
/*     range limited to 0..(2^40 - 1). The shift amount is non-zero for low */
/*     pass filters, and zero for high pass and sharpening filters.         */
/*                                                                          */
/*  TECHNIQUES                                                              */
/*     The inner loop that computes the convolution sum is completely       */
/*     unrolled and 4 output pixels are computed together. The mask         */
/*     values are loaded and packed as double words.                        */
/*     Since 40-bit intermediates are used, intermediate results will       */
/*     not overflow                                                         */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*     - width must be a multiple of 4.                                     */
/*     - I/O buffers do not overlap.                                        */
/*     - Input, output and mask pointers should be half word alligned.      */
/*                                                                          */
/* ======================================================================== */

void IMG_conv_3x3_i16_c16s_cn 
(
    const unsigned short *restrict imgin_ptr,
          unsigned short *restrict imgout_ptr,
          int                      width,
    const          short *restrict mask_ptr,
          int                      shift
);

#endif  

/*========================================================================= */
/*   End of file:  IMG_conv_3x3_i16_c16s_cn.h                               */
/* ======================================================================== */
