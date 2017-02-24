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
/*      IMG_conv_5x5_i8_c16s                                                */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C-callable and can be called as:                    */
/*                                                                          */
/*          void IMG_conv_5x5_i8_c16s                                       */
/*          (                                                               */
/*              const unsigned char  *restrict   imgin_ptr,                 */
/*                    unsigned char  *restrict  imgout_ptr,                 */
/*                             short                 width,                 */
/*                             short                 pitch,                 */
/*              const          short  *restrict    mask_ptr,                */
/*                             short                 shift                  */
/*          )                                                               */
/*                                                                          */
/*      imgin_ptr :   pointer to an input  array of 8 bit pixels            */
/*      imgout_ptr:   pointer to an output array of 8 bit pixels            */
/*      pitch     :   number of columns in the image                        */
/*      width     :   number of output pixels                               */
/*      mask_ptr  :   pointer to 16 bit filter mask.                        */
/*      shift     :   user specified shift amount                           */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      The convolution kernel accepts five rows of 'pitch' input pixels    */
/*      and produces one row of 'width' output pixels using the input       */
/*      mask of 5 by 5. This convolution performs a point by point mult-    */
/*      iplication of 5 by 5 mask with the input image. The result of 25    */
/*      multiplications are then summed together to produce a 32-bit conv-  */
/*      olution intermediate sum. The user defined shift value is used to   */
/*      shift this convolution sum, down to the byte range and store in an  */
/*      output array. The result being stored is also range limited between */
/*      0 to 255 and will be saturated accordingly. The mask is moved one   */
/*      column at a time, advancing the mask over the entire image until    */
/*      the entire 'width' is covered. The masks are provided as 16-bit     */
/*      signed values. The input image pixels are provided as 8-bit uns-    */
/*      igned pixels and the output pixels will be in 8-bit unsigned.       */
/*                                                                          */
/*      The natural C implementation has no restrictions. The Optimized     */
/*      and IntrinsiC codes has restrictions as noted in the ASSUMPTIONS    */
/*      below.                                                              */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      1. width:       'width' >= 2 and multiples of 2.                    */
/*      2. pitch:       'pitch' >= 'width'                                  */
/*      3. Filter Coefficient array should be half-word aligned             */
/*      4. Output array should be word-aligned.                             */
/*      5. No restrictions on the alignment of Input arrays                 */
/*      6. Input and Output arrays should not overlap.                      */
/*                                                                          */
/*  COMPATIBILITY                                                           */
/*      This code is compatible for c66x                                    */
/*                                                                          */
/* ======================================================================== */

#pragma CODE_SECTION(IMG_conv_5x5_i8_c16s,   ".text:optimized");


union db_ll
{
    long long ll;
    double    db;
};  

void IMG_conv_5x5_i8_c16s
(
    const unsigned char *restrict  imgin_ptr,
    unsigned char       *restrict imgout_ptr,
    short                              width,
    short                              pitch,
    const          short *restrict  mask_ptr,
    short                              shift
)
{
  int                  i;  
  int                  sum1 ,      sum2,       sum21;
  int                  row_54,     row_10;
  int                  mask44,     mask55,     mask24;
  int                  mask15_15,  mask24_24,  mask14_14;

  double               temp3; 
  double               mask3_0,    mask7_4,    mask11_8;
  double               mask15_12,  mask19_16,  mask23_20;
     
  long long            r1;
  long long            temp1,      temp2,      mask_temp;

  union db_ll          row_3210,   row_5432;

  const unsigned char  *in,        *in1,       *in2;
  const unsigned char  *in3,       *in4; 

  
  /* -------------------------------------------------------------------- */
  /*  Inform the compiler by _nasserts the following:                     */
  /*      a) The output array is word aligned                             */
  /*      b) Filter Mask array is double word aligned                     */
  /*      c) The width is greater than or equal to 2                      */
  /*      d) The width is a multiple of 2.                                */
  /* -------------------------------------------------------------------- */
  _nassert((int)imgout_ptr % 4 == 0);    
  _nassert(width               >= 2);
  _nassert(width           % 2 == 0);    

  /* -------------------------------------------------------------------- */
  /*       initialise pointers to the starting of each of the 5 rows      */
  /* -------------------------------------------------------------------- */
  in        = imgin_ptr;
  in1       = in  + pitch;
  in2       = in1 + pitch;
  in3       = in2 + pitch;
  in4       = in3 + pitch;
  
  /* -------------------------------------------------------------------- */
  /*  Load the 5 mask values (in reverse for mask rotation)               */
  /* -------------------------------------------------------------------- */
  mask_temp = _mem8((void *) &mask_ptr[21]);
  mask3_0   = _itod(_packlh2(_loll(mask_temp),_loll(mask_temp)),
                    _packlh2(_hill(mask_temp),_hill(mask_temp)));
  mask_temp = _mem8((void *) &mask_ptr[17]);
  mask7_4   = _itod(_packlh2(_loll(mask_temp),_loll(mask_temp)),
                    _packlh2(_hill(mask_temp),_hill(mask_temp)));
  mask_temp = _mem8((void *) &mask_ptr[13]);
  mask11_8  = _itod(_packlh2(_loll(mask_temp),_loll(mask_temp)),
                    _packlh2(_hill(mask_temp),_hill(mask_temp)));
  mask_temp = _mem8((void *) &mask_ptr[9]);
  mask15_12 = _itod(_packlh2(_loll(mask_temp),_loll(mask_temp)),
                    _packlh2(_hill(mask_temp),_hill(mask_temp)));
  mask_temp = _mem8((void *) &mask_ptr[5]);
  mask19_16 = _itod(_packlh2(_loll(mask_temp),_loll(mask_temp)),
                    _packlh2(_hill(mask_temp),_hill(mask_temp)));
  mask_temp = _mem8((void *) &mask_ptr[1]);
  mask23_20 = _itod(_packlh2(_loll(mask_temp),_loll(mask_temp)),
                    _packlh2(_hill(mask_temp),_hill(mask_temp)));

  mask24    =  mask_ptr[0];
  
  mask44    = _pack2 (_lo(mask7_4),  _lo(mask7_4));
  mask55    = _packh2(_lo(mask7_4),  _lo(mask7_4));
  mask14_14 = _pack2 (_hi(mask15_12),_hi(mask15_12));
  mask15_15 = _packh2(_hi(mask15_12),_hi(mask15_12));
  mask24_24 = _pack2 (mask24,mask24);
  
  /* -------------------------------------------------------------------- */
  /*  Loop is manually unrolled by 2.                                     */
  /* -------------------------------------------------------------------- */
  sum1      = 0;
  sum2      = 0;

  #pragma MUST_ITERATE(1,,1);

  for (i=0; i<width; i += 2) {
    /* -------------------------------------------------------------- */
    /* Load 8 pixels that can be used to calculate two output pixels  */
    /* from the kth row                                               */
    /* -------------------------------------------------------------- */
    r1    =   _mem8_const((void * ) &in[i]);

    /* -------------------------------------------------------------- */
    /* Convert the 8 bit pixels to 16 bit values so that ddotpl2      */
    /* can be used                                                    */
    /* -------------------------------------------------------------- */
    row_3210.db = _mpyu4(_loll(r1),0x01010101);
    row_54      = _unpklu4(_hill(r1));

    /* -------------------------------------------------------------- */
    /* Perform the partial multiplications of input pixel with corre- */
    /* ponding mask for the first and second sample outputs           */
    /* -------------------------------------------------------------- */
    temp1       = _ddotpl2(row_3210.ll,_lo(mask3_0));
    temp2       = _ddotpl2(_itoll(row_54,_hill(row_3210.ll)),_hi(mask3_0));
    temp3       = _mpy2(row_54 , mask44);
 
    /* -------------------------------------------------------------- */
    /* Calculate sum1 and sum2 which holds the sums for two output    */
    /* pixels                                                         */
    /* -------------------------------------------------------------- */
    sum1       += (_loll(temp1) +  _loll(temp2) +  _lo(temp3));                             
    sum2       += (_hill(temp1) +  _hill(temp2) +  _hi(temp3));  

    /* -------------------------------------------------------------- */
    /* Load 8 pixels that can be used to calculate two output pixels  */
    /* from the kth row                                               */
    /* -------------------------------------------------------------- */
    r1          = _mem8_const((void * ) &in1[i ]);

    /* -------------------------------------------------------------- */
    /* Convert the 8 bit pixels to 16 bit values so that ddotpl2      */
    /* can be used                                                    */
    /* -------------------------------------------------------------- */
    row_5432.ll = _itoll(_unpklu4(_hill(r1)),_unpkhu4(_loll(r1)) );
    row_10      = _unpklu4(_loll(r1));

    /* -------------------------------------------------------------- */
    /* Perform the partial multiplications of input pixel with corre- */
    /* ponding mask for the first and second sample outputs           */
    /* -------------------------------------------------------------- */
    temp1       = _ddotph2(_itoll(_loll(row_5432.ll),row_10),_hi(mask7_4));
    temp2       = _ddotph2(row_5432.ll,_lo(mask11_8));
    temp3       = _mpy2(row_10 , mask55);
 
    /* -------------------------------------------------------------- */
    /* Calculate sum1 and sum2 which holds the sums for two output    */
    /* pixels                                                         */
    /* -------------------------------------------------------------- */
    sum1       += (_loll(temp1) + _loll(temp2) +_lo(temp3));                             
    sum2       += (_hill(temp1) + _hill(temp2) +_hi(temp3)); 
    r1          = _mem8_const((void * ) &in2[i]);

    /* -------------------------------------------------------------- */
    /* Convert the 8 bit pixels to 16 bit values so that ddotpl2      */
    /* can be used                                                    */
    /* -------------------------------------------------------------- */
    row_3210.db = _mpyu4(_loll(r1), 0x01010101);
    row_54      = _unpklu4(_hill(r1));

    /* -------------------------------------------------------------- */
    /* Perform the partial multiplications of input pixel with corre- */
    /* ponding mask for the first and second sample outputs           */
    /* -------------------------------------------------------------- */
    temp1       = _ddotpl2(row_3210.ll,_hi(mask11_8));
    temp2       = _ddotpl2(_itoll(row_54,_hill(row_3210.ll)),_lo(mask15_12));
    temp3       = _mpy2(row_54 , mask14_14);
 
    /* -------------------------------------------------------------- */
    /* Calculate sum1 and sum2 which holds the sums for two output    */
    /* pixels                                                         */
    /* -------------------------------------------------------------- */
    sum1       += (_loll(temp1) + _loll(temp2) + _lo(temp3));
    sum2       += (_hill(temp1) + _hill(temp2) + _hi(temp3));
    r1          = _mem8_const((void * ) &in3[i]);

    /* -------------------------------------------------------------- */
    /* Convert the 8 bit pixels to 16 bit values so that ddotpl2      */
    /* can be used                                                    */
    /* -------------------------------------------------------------- */
    row_5432.ll = _itoll(_unpklu4(_hill(r1)),_unpkhu4(_loll(r1)) );
    row_10      = _unpklu4(_loll(r1));

    /* -------------------------------------------------------------- */
    /* Perform the partial multiplications of input pixel with corre- */
    /* ponding mask for the first and second sample outputs           */
    /* -------------------------------------------------------------- */
    temp1       = _ddotph2(_itoll(_loll(row_5432.ll),row_10),_lo(mask19_16));
    temp2       = _ddotph2(row_5432.ll,_hi(mask19_16));
    temp3       = _mpy2(row_10 , mask15_15);
 
    /* -------------------------------------------------------------- */
    /* Calculate sum1 and sum2 which holds the sums for two output    */
    /* pixels                                                         */
    /* -------------------------------------------------------------- */
    sum1       += (_loll(temp1) + _loll(temp2) +_lo(temp3));
    sum2       += (_hill(temp1) + _hill(temp2) +_hi(temp3));
    r1          = _mem8_const((void * ) &in4[i]);

    /* -------------------------------------------------------------- */
    /* Convert the 8 bit pixels to 16 bit values so that ddotpl2      */
    /* can be used                                                    */
    /* -------------------------------------------------------------- */
    row_3210.db =  _mpyu4(_loll(r1),0x01010101);
    row_54      =  _unpklu4(_hill(r1));

    /* -------------------------------------------------------------- */
    /* Perform the partial multiplications of input pixel with corre- */
    /* ponding mask for the first and second sample outputs           */
    /* -------------------------------------------------------------- */
    temp1       = _ddotpl2(row_3210.ll,_lo(mask23_20));
    temp2       = _ddotpl2(_itoll(row_54,_hill(row_3210.ll)),_hi(mask23_20));
    temp3       = _mpy2(row_54 , mask24_24);
 
    /* -------------------------------------------------------------- */
    /* Calculate sum1 and sum2 which holds the sums for two output    */
    /* pixels                                                         */
    /* -------------------------------------------------------------- */
    sum1       += (_loll(temp1) + _loll(temp2) + _lo(temp3));
    sum2       += (_hill(temp1) + _hill(temp2) + _hi(temp3));
    
    /* -------------------------------------------------------------- */
    /* shift the sum to fall in byte range with user defined value    */
    /* -------------------------------------------------------------- */
    sum1        = (sum1 >> shift); 
    sum2        = (sum2 >> shift); 
    
    /* -------------------------------------------------------------- */
    /* check for saturation and pack two bytes to store using amem2   */
    /* -------------------------------------------------------------- */
    sum21       =  _spacku4(0, _spack2(sum2, sum1)); 
     
    _amem2((void *) &imgout_ptr[i]) = sum21;
  }
}

/* ======================================================================== */
/*  End of file:  IMG_conv_5x5_i8_c16s.c                                    */
/* ======================================================================== */


