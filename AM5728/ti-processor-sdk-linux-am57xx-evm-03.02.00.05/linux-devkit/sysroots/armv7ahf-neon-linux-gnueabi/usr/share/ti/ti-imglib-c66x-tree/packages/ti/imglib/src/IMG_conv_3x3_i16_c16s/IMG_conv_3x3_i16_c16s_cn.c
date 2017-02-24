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

#ifdef __TI_INT40_T__
  typedef __int40_t long40;
#else
  typedef long long long40;
#endif

#pragma CODE_SECTION (IMG_conv_3x3_i16_c16s_cn, ".text:ansi");

void IMG_conv_3x3_i16_c16s_cn
(
    const unsigned short *restrict imgin_ptr,
          unsigned short *restrict imgout_ptr,
          int                      width,
    const          short *restrict mask_ptr,
          int                      shift
)
{
  long40                sum,    sum00,    sum11,    sum22;
  const unsigned short  *IN1,   *IN2,     *IN3;
  unsigned       short  *OUT;
  unsigned       short  pix10,  pix20,    pix30;
                 short  mask10, mask20,   mask30;
  int                   i,      j;


  /*-------------------------------------------------------------------*/
  /* Set imgcols to the width of the image and set three pointers for  */
  /* reading data from the three input rows. Also set the output       */
  /* pointer.                                                          */
  /*-------------------------------------------------------------------*/
  IN1 = imgin_ptr;
  IN2 = IN1 + width;
  IN3 = IN2 + width;
  OUT = imgout_ptr;

  /*-------------------------------------------------------------------*/
  /* The j: loop iterates to produce one output pixel per iteration.   */
  /* The mask values and the input values are read using the i loop.   */
  /* The convolution sum is then computed. The convolution sum is      */
  /* then shifted and range limited to 0..255                          */
  /*-------------------------------------------------------------------*/
  for (j=0; j<width ; j++) {

    /*-----------------------------------------------------------------*/
    /* Initialize convolution sum to zero, for every iteration of      */
    /* outer loop. The inner loop computes convolution sum.            */
    /*-----------------------------------------------------------------*/
    sum = 0;
       
    for (i=0; i<3; i++) {
      pix10  = IN1[i];
      pix20  = IN2[i];
      pix30  = IN3[i];

      /*---------------------------------------------------------------*/
      /* Reverse mask to get 180 degree rotation.                      */
      /*---------------------------------------------------------------*/
      mask10 = mask_ptr[(8 - i) - 0];
      mask20 = mask_ptr[(8 - i) - 3];
      mask30 = mask_ptr[(8 - i) - 6];

      sum00  = (long40) pix10 * mask10;
      sum11  = (long40) pix20 * mask20;
      sum22  = (long40) pix30 * mask30;

      sum   += sum00 + sum11+ sum22;
    }

    /*-----------------------------------------------------------------*/
    /*  Increment input pointers and shift sum and range limit to      */
    /*  0...65535.                                                     */
    /*-----------------------------------------------------------------*/
    IN1++;
    IN2++;
    IN3++;
    
    sum = (sum >> shift);
    
    if (sum < 0)     sum = 0;
    if (sum > 65535) sum = 65535;

    /*-----------------------------------------------------------------*/
    /* Store output sum into the output pointer OUT                    */
    /*-----------------------------------------------------------------*/
    *OUT++ = sum;
  }
}

/*========================================================================= */
/*   End of file:  IMG_conv_3x3_i16_c16s_cn.c                               */
/* ======================================================================== */
