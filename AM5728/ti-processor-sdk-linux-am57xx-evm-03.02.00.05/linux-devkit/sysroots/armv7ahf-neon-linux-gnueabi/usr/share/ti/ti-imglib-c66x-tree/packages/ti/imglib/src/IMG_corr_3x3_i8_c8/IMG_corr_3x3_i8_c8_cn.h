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

#ifndef  IMG_CORR_3X3_I8_C8_C_H_
#define  IMG_CORR_3X3_I8_C8_C_H_  1

/* ======================================================================== */
/*  NAME                                                                    */
/*      IMG_corr_3x3_i8_c8_cn                                               */
/*                                                                          */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C-callable and can be called as:                    */
/*                                                                          */
/*      void IMG_corr_3x3_i8_c8_cn                                          */
/*      (                                                                   */
/*          const unsigned char           *imgin_ptr, // input image        */
/*                int           *restrict imgout_ptr, // output image       */
/*                short                   width,      // number of outputs  */
/*                short                   pitch,      // width of image     */
/*          const unsigned char           *mask_ptr,  // convolution mask   */
/*                short                   shift,                            */
/*                int                     round       // rounding constant  */
/*      );                                                                  */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      The correlation performs a point by point multiplication of the     */
/*      3 by 3 mask with the input image.  The result of the nine           */
/*      multiplications are then summed up together to produce a            */
/*      convolution sum. A rounding constant is added to the sum and        */
/*      shifted by user specified amount.                                   */
/*                                                                          */
/*      The image mask to be correlated is typically part of the input      */
/*      image and indicates the area of the best match between the          */
/*      input image and mask.  The mask is moved one column at a time,      */
/*      advancing the mask over the portion of the row specified by         */
/*      'width'.  When 'width' is larger than 'pitch', multiple rows        */
/*      will be processed.                                                  */
/*                                                                          */
/*      An application may call this kernel once per row to calculate       */
/*      the correlation for an entire image:                                */
/*                                                                          */
/*      for (i = 0; i < rows; i++)                                          */
/*      {                                                                   */
/*        IMG_corr_3x3_i8_c8_cn (&imgin_ptr[i*pitch],&imgout_ptr[i*width],  */
/*                               width, pitch, mask_ptr, shift, round);     */
/*      }                                                                   */
/*                                                                          */
/*      Alternately, the kernel may be invoked for multiple rows at         */
/*      a time, although the two outputs at the end of each row will        */
/*      have meaningless values.  For example:                              */
/*                                                                          */
/*      IMG_corr_3x3_i8_c8_cn (imgin_ptr, imgout_ptr, 2*pitch, mask_ptr,    */
/*                             pitch, shift, rnd);                          */
/*                                                                          */
/*      This will produce two rows of outputs into 'imgout_ptr'.  The       */
/*      outputs at locations imgout_ptr[pitch - 2], imgout_ptr[pitch - 1],  */
/*      imgout_ptr[2*pitch - 2] and imgout_ptr[2*pitch - 1] will have       */
/*      meaningless values.  This is harmless, although the application     */
/*      will have to account for this when interpreting the results.        */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      The array pointed to by imgout_ptr does not alias with the array    */
/*      pointed to by imgin_ptr or mask_ptr.                                */
/* ======================================================================== */

void IMG_corr_3x3_i8_c8_cn
(
    const unsigned char           *imgin_ptr,  /* input image       */
          int           *restrict imgout_ptr,  /* output image      */
          short                   width,       /* number of outputs */
          short                   pitch,       /* width of image    */
    const unsigned char           *mask_ptr,   /* correlation mask  */
          short                   shift,
          int                     round        /* rounding constant */ 
);

#endif

/* ======================================================================== */
/*  End of file:  IMG_corr_3x3_i8_c8_cn.h                                   */
/* ======================================================================== */

