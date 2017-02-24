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

int in_data[] = {
/* Alignment data.
 * 0 = double word, 4 = word, 2 = half word, 1 = byte alignment respectively.
 * y align, croma align, dst align, coeff align*/
0, 4, 0, 0,

/* Function parameters : 1 */
/* use_for_cycle_estimate, num_pix */
1, 48,

/* Coefficients : 1 */
 8192, 11229, -2757, -5720, 14192,

/* Input data Y : 1 */
 151, 193, 170, 161, 208,  20,  60, 162,  16, 137,  16, 150, 178, 128,  91, 224,
 151, 193, 170, 161, 208,  20,  60, 162,  16, 137,  16, 150, 178, 128,  91, 224,
 151, 193, 170, 161, 208,  20,  60, 162,  16, 137,  16, 150, 178, 128,  91, 224,

/* Input data Cb: 1 */
 57, 16, 140, 88, 16, 31, 16, 54,
 57, 16, 140, 88, 16, 31, 16, 54,
 57, 16, 140, 88, 16, 31, 16, 54,

/* Input data Cr: 1 */
 116, 240, 150, 77, 162, 143, 135, 154,
 116, 240, 150, 77, 162, 143, 135, 154,
 116, 240, 150, 77, 162, 143, 135, 154,

/* Function parameters : 2 */
/* use_for_cycle_estimate, num_pix */
1, 64,

/* Coefficients : 2 */
 8192, 11229, -2757, -5720, 14192,

/* Input data Y : 2 */
 214,  92,  28, 230,  98, 190, 233,  58, 115, 130,  42, 235,  16,  68,  16, 198, 
 211,  51,  16,  16, 235,  16, 203, 134, 191, 129, 235, 182, 173,  39,  33, 211, 
 216,  46,  63, 138, 120,  27,  72, 102, 235, 126, 188,  16, 214, 235,  16,  81, 
  89, 226, 122,  16, 169, 109, 154, 124, 172, 117, 196, 235,  19, 218,  40,  88,

/* Input data Cb: 2 */
 113,  53, 217, 231, 203,  62, 103, 135, 158, 106, 240,  83, 137, 212, 115,  49, 
 158,  28,  53, 158,  86, 225,  28,  64, 202, 239, 192, 221,  47, 240, 221,  67,

/* Input data Cr: 2 */
  16, 211, 149, 127, 177, 155, 127, 131,  16, 227,  16, 230,  98, 148, 112, 224, 
  87,  77,  77, 193, 138, 176,  70,  49,  59, 192, 115,  91, 161, 221, 141, 144,
};

int testcases = 2;
