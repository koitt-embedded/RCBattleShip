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
1, 1, 0,

/* Function parameters : 1 */
/* use_for_cycle_estimate, width, shift, round const, in_size, out_size */
0, 6, 7, 64, 18, 4,

/* Image data : 1 */
 151, 170, 208, 60,   4,   6,
  57,   9, 140, 88,   6,  31,
 116, 247, 150, 77, 162, 143,

/* mask : 1 */
  5,  6,  7,
  8,  9, 10,
 11, 12, 13,

/* Function parameters : 2 */
/* use_for_cycle_estimate, width, shift, round const, in_size, out_size */
1, 22, 5, 0, 66, 20,

/* Image data : 2 */
 40, 32, 28, 13, 54, 58, 51, 16, 26, 34, 39, 27, 64, 21, 34, 53, 29, 12, 39,  7, 13, 39,
 34, 56,  2, 53, 37, 32, 44, 39, 32, 33,  2, 57,  3, 57, 24, 37, 28, 56, 22, 19, 19, 48,
 38, 53,  7, 24, 58, 29, 11,  1,  4, 53,  0, 62, 51, 48, 63, 43,  8, 54, 16, 30, 18, 61,

/* mask : 2 */
 22,  0, 17,
 11,  7, 19,
 24, 20,  2,

/* Function parameters : 3 */
/* use_for_cycle_estimate, width, shift, round const, in_size, out_size */
0, 10, 5, 16, 30, 8,

/* Image data : 3 */
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,

/* mask : 3 */
   0, 0,  32,
  74, 0, 255,
 255, 0,  84,

/* Function parameters : 4 */
/* use_for_cycle_estimate, width, shift, round const, in_size, out_size */
1, 14, 5, 0, 42, 12,

/* Image data : 4 */
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

/* mask : 4 */
   0, 0,  32,
  74, 0, 255,
 255, 0,  84,

/* Function parameters : 5 */
/* use_for_cycle_estimate, width, shift, round const, in_size, out_size */
1, 22, 5, 16, 66, 20,

/* Image data : 5 */
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 

/* mask : 5 */
 255, 255, 255,
 255, 255, 255,
 255, 255, 255,

/* Function parameters : 6 */
/* use_for_cycle_estimate, width, shift, round const, in_size, out_size */
0, 6, 5, 0, 18, 4,

/* Image data : 6 */
 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255,

/* mask : 6 */
 255, 255, 255,
 255, 255, 255,
 255, 255, 255,

/* Function parameters : 7 */
/* use_for_cycle_estimate, width, shift, round const, in_size, out_size */
1, 18, 5, 16, 54, 16,

/* Image data : 7 */
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,

/* mask : 7 */
 255, 255, 255,
 255, 255, 255,
 255, 255, 255,
};

int testcases = 7;
