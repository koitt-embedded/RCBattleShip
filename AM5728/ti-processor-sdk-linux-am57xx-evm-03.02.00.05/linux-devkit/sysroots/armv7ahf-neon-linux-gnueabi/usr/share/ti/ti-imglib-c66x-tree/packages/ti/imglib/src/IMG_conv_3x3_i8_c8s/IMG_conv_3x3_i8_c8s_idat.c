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
/* Test data for kernel size : 3 x 3 
 * kernel size */
3,

/* Alignment data.
 * 0 = double word, 4 = word, 2 = half word, 1 = byte alignment respectively.
 * src align, mask align, dst align */
1, 1, 4,

/* Function parameters : 1 */
/* use_for_cycle_estimate, width, pitch, shift, in_size, out_size */
0, 8, 10, 4, 30, 8,

/* Image data : 1 */
 151, 170, 208,  60,   4,   6, 178,  91,  25, 176,
  57,   9, 140,  88,   6,  31,   3,  54, 243,  12, 
 116, 247, 150,  77, 162, 143, 135, 154,  41, 102,

/* mask : 1 */
 -3, -2, -1,
  0,  1,  2,
  3,  4,  5,

/* Function parameters : 2 */
/* use_for_cycle_estimate, width, pitch, shift, in_size, out_size */
1, 16, 18, 12, 54, 16,

/* Image data : 2 */
 113,  53, 217, 231, 203,  62, 103, 135, 158, 106, 255,  83, 137, 212, 115,  49,   4,   6, 
   9, 211, 149, 127, 177, 155, 127, 131,   9, 227,  11, 230,  98, 148, 112, 224,   6,  31, 
  28,  98, 233, 115,  42,   3,  16, 211,   2, 249, 203, 191, 251, 173,  33, 216, 162, 143, 

/* mask : 2 */
 96,  81,  10,
 81,  69,  75,
 64, 112, 107,

/* Function parameters : 3 */
/* use_for_cycle_estimate, width, pitch, shift, in_size, out_size */
1, 24, 26, 16, 78, 24,

/* Image data : 3 */
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,

/* mask : 3 */
  127, -128, -128,
 -128, -128,  -62,
 -128,  127, -128,

/* Function parameters : 4 */
/* use_for_cycle_estimate, width, pitch, shift, in_size, out_size */
0, 8, 10, 16, 30, 8,

/* Image data : 4 */
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

/* mask : 4 */
  127, -128, -128,
 -128, -128,  -62,
 -128,  127, -128,

/* Function parameters : 5 */
/* use_for_cycle_estimate, width, pitch, shift, in_size, out_size */
1, 16, 18, 16, 54, 16,

/* Image data : 5 */
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,

/* mask : 5 */
 127, 127, 127,
 127, 127, 127,
 127, 127, 127,

/* Function parameters : 6 */
/* use_for_cycle_estimate, width, pitch, shift, in_size, out_size */
1, 24, 26, 16, 78, 24,

/* Image data : 6 */
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,

/* mask : 6 */
 127, 127, 127,
 127, 127, 127,
 127, 127, 127,

/* Function parameters : 7 */
/* use_for_cycle_estimate, width, pitch, shift, in_size, out_size */
1, 28, 30, 11, 90, 28,

/* Image data : 7 */
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,

/* mask : 7 */
 127, 127, 127,
 127, 127, 127,
 127, 127, 127,

/* Function parameters : 8 */
/* use_for_cycle_estimate, width, pitch, shift, in_size, out_size */
1, 16, 18, 16, 54, 16,

/* Image data : 8 */
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,

/* mask : 8 */
 -128, -128, -128,
 -128, -128, -128,
 -128, -128, -128,
};

int testcases = 8;
