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

#ifndef IMG_IDCT_8X8_12Q4_C_H_
#define IMG_IDCT_8X8_12Q4_C_H_ 1

/* ======================================================================== */
/*  NAME                                                                    */
/*      IMG_idct_8x8_12q4 -- IEEE-1180/1990 Compliant IDCT, Little Endian.  */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C callable, and has the following C prototype:      */
/*                                                                          */
/*          void IMG_idct_8x8_12q4(short idct_data[], unsigned num_idcts)   */
/*                                                                          */
/*      The IMG_idct_8x8_12q4 routine accepts a list of 8x8 DCT coeffient   */
/*      blocks and performs IDCTs on each.  The array should be laid out    */
/*      equivalently to the C array idct_data[num_idcts][8][8].  The        */
/*      input data should be in 12Q4 format.                                */
/*                                                                          */
/*      The routine operates entirely in-place, requiring no additional     */
/*      storage for intermediate results.                                   */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      The idct_8x8 algorithm performs an IEEE-1180 compliant IDCT,        */
/*      complete with rounding and saturation to signed 9-bit quantities.   */
/*      The input coefficients are assumed to be signed 16-bit DCT          */
/*      coefficients in 12Q4 format.                                        */
/*                                                                          */
/*      Note:  This code guarantees correct operation, even in the case     */
/*      that 'num_idcts == 0'.                                              */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      This is a LITTLE ENDIAN implementation.                             */
/*                                                                          */
/*  NOTES                                                                   */
/*      The cosine terms have all been scaled by sqrt(2), so that the       */
/*      "c4" term is basically an even power of 2.                          */
/* ======================================================================== */

void IMG_idct_8x8_12q4_cn
(
    short    *idct_data,  /* Pointer to 8x8 IDCT blocks "idct_data[num_idcts][8][8]" */
    unsigned  num_idcts   /* Number of IDCT blocks */
);

#endif

/* ======================================================================== */
/*  End of file:  IMG_idct_8x8_12q4_cn.h                                    */
/* ======================================================================== */
