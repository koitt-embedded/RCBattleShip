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
/*      IMG_corr_3x3_i8_c8                                                  */
/*                                                                          */
/*      void IMG_corr_3x3_i8_c8                                             */
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
/*        IMG_corr_3x3_i8_c8 (&imgin_ptr[i*pitch],&imgout_ptr[i*width],     */
/*                             width, pitch, mask_ptr, shift, round);       */
/*      }                                                                   */
/*                                                                          */
/*      Alternately, the kernel may be invoked for multiple rows at         */
/*      a time, although the two outputs at the end of each row will        */
/*      have meaningless values.  For example:                              */
/*                                                                          */
/*      IMG_corr_3x3_i8_c8    (imgin_ptr, imgout_ptr, 2*pitch, mask_ptr,    */
/*                             pitch, shift, rnd);                          */
/*                                                                          */
/*      This will produce two rows of outputs into 'imgout_ptr'.  The       */
/*      outputs at locations imgout_ptr[pitch - 2], imgout_ptr[pitch - 1],  */
/*      imgout_ptr[2*pitch - 2] and imgout_ptr[2*pitch - 1] will have       */
/*      meaningless values.  This is harmless, although the application     */
/*      will have to account for this when interpreting the results.        */
/*                                                                          */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      - The array pointed to by imgout_ptr does not alias with the array  */
/*        pointed to by imgin_ptr.                                          */
/*      - Shift should be appropriate to produce 8 bit result.              */
/*      - pitch >= 4 and is a multiple of 2                                 */
/*      - width >= 4 and is a multiple of 4                                 */
/*      - This kernel is developed for Little Endian.                       */
/*                                                                          */
/*     TECHNIQUES                                                           */
/*        Data for the input image pixels is reused by pre-loading them     */
/*        outside the loop and issuing moves to bring them to the appro-    */
/*        priate registers once inside the loop. This is done to minimize   */
/*        the loads from nine to six within the loop, for each pair of      */
/*        pixels in the present computation of the correlation. The loop    */
/*        is unrolled once so that eighteen multiplies for the two output   */
/*        pixels can schedule in 9 cycles leading to 4.5 cycles per output  */
/*        pixel. In addition te trivial loop that did the loads three at a  */
/*        time, per row is collapsed to increase parallel operations.       */
/*                                                                          */
/* ======================================================================== */

#pragma CODE_SECTION(IMG_corr_3x3_i8_c8, ".text:optimized");

void IMG_corr_3x3_i8_c8
(
    const unsigned char           *imgin_ptr,  
          int           *restrict imgout_ptr,  
          short                   width,       
          short                   pitch,       
    const unsigned char           *mask_ptr,
          short                   shift,
          int                     round         
)
{
  int                      j, count;
  const   unsigned char   *IN1,    *IN2,    *IN3;
  double                  *OUT;

  /*----------------------------------------------------------------------*/
  /* maskA_B : A is row no., B is starting column no.                     */
  /*----------------------------------------------------------------------*/
  unsigned int  mask1_0, mask2_0, mask3_0;
  unsigned int  mask1_1, mask2_1, mask3_1;

  /*----------------------------------------------------------------------*/
  /* Other variables.                                                     */
  /*----------------------------------------------------------------------*/
  double       r1_76543210, r2_76543210, r3_76543210;
  unsigned int r1_7654,     r1_3210;
  unsigned int r2_7654,     r2_3210;
  unsigned int r3_7654,     r3_3210;
  unsigned int r1_5432,     r2_5432,     r3_5432;
  int          sum0, sum1, sum2, sum3;

  /*----------------------------------------------------------------------*/
  /*  Read mask values and prepare registers for convolution              */
  /*----------------------------------------------------------------------*/
  mask1_0 = _extu(_mem4_const(&mask_ptr[0]), 8, 8);
  mask2_0 = _extu(_mem4_const(&mask_ptr[3]), 8, 8);
  mask3_0 = _extu(_mem4_const(&mask_ptr[6]), 8, 8);

  mask1_1 = mask1_0 << 8;
  mask2_1 = mask2_0 << 8;
  mask3_1 = mask3_0 << 8;

  /*-----------------------------------------------------------------------*/
  /* Set loop counter for output pixels and three input pointers pitch     */
  /* apart from the user passed input pointer. Copy output pointer         */
  /*-----------------------------------------------------------------------*/
  count   = width >> 2;
  IN1     = imgin_ptr;
  IN2     = IN1+ pitch;
  IN3     = IN2+ pitch;
  OUT     = (double *) imgout_ptr;

  /*----------------------------------------------------------------------*/
  /* In order to minimize data loads, dat re-use is achieved by moves.    */
  /* The data to be used for pix10, pix11 are pre-loaded into pix12 and   */
  /* pix13 and moved within the loop. The process is repeated for rows 2  */
  /* and 3 for pix20, pix21 and pix30 and pix31 respectively.             */
  /*----------------------------------------------------------------------*/
  for (j=0; j<count; j++) {
    r1_76543210 = _memd8_const(IN1);
    r2_76543210 = _memd8_const(IN2);
    r3_76543210 = _memd8_const(IN3);
    IN1    += 4;
    IN2    += 4;
    IN3    += 4;

    r1_3210 = _lo(r1_76543210);
    r2_3210 = _lo(r2_76543210);
    r3_3210 = _lo(r3_76543210);
    r1_7654 = _hi(r1_76543210);
    r2_7654 = _hi(r2_76543210);
    r3_7654 = _hi(r3_76543210);

    sum0    = (_dotpu4(mask1_0, r1_3210) + _dotpu4(mask2_0, r2_3210) +
               _dotpu4(mask3_0, r3_3210) + round) >> shift;

    sum1    = (_dotpu4(mask1_1, r1_3210) + _dotpu4(mask2_1, r2_3210) +
               _dotpu4(mask3_1, r3_3210) + round ) >> shift;

    _memd8(OUT++) = _itod(sum1, sum0);


    r1_5432 = _packlh2(r1_7654, r1_3210);
    r2_5432 = _packlh2(r2_7654, r2_3210);
    r3_5432 = _packlh2(r3_7654, r3_3210);

    sum2    = (_dotpu4(mask1_0, r1_5432) + _dotpu4(mask2_0, r2_5432) +
               _dotpu4(mask3_0, r3_5432) + round) >> shift;


    sum3    = (_dotpu4(mask1_1, r1_5432) + _dotpu4(mask2_1, r2_5432) +
               _dotpu4(mask3_1, r3_5432) + round) >> shift;

    _memd8(OUT++) = _itod(sum3, sum2);
  }
}

/* ======================================================================== */
/*  End of file:  IMG_corr_3x3_i8_c8.c                                      */
/* ======================================================================== */
