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
 * src align, dst align */
1, 1,

/* Function parameters : 1 */
/* use_for_cycle_estimate, cols, rows, in_size, out_size */
0, 8, 3, 24, 6,

/* Image data : 1 */
 151, 170, 208, 60, 4, 6, 178, 91,
 57, 9, 140, 88, 6, 31, 3, 54,
 116, 247, 150, 77, 162, 143, 135, 154,

/* Function parameters : 2 */
/* use_for_cycle_estimate, cols, rows, in_size, out_size */
0, 16, 3, 48, 14,

/* Image data : 2 */
 193, 162, 128, 113, 53, 217, 231, 203, 62, 103, 135, 158, 106, 255, 83, 137,
 161, 137, 224, 9, 211, 149, 127, 177, 155, 127, 131, 9, 227, 11, 230, 98,
 20, 150, 214, 28, 98, 233, 115, 42, 3, 16, 211, 2, 249, 203, 191, 251,

/* Function parameters : 3 */
/* use_for_cycle_estimate, cols, rows, in_size, out_size */
1, 32, 3, 96, 30,

/* Image data : 3 */
 53, 29, 12, 39, 7, 13, 39, 22, 56, 7, 16, 50, 60, 48, 55, 12, 64, 55, 17, 57, 33, 50, 2, 45, 12, 26, 60, 1, 29, 22, 42, 33,
 37, 28, 56, 22, 19, 19, 48, 34, 44, 17, 12, 15, 48, 29, 23, 40, 55, 35, 36, 47, 60, 13, 34, 10, 34, 32, 20, 27, 61, 58, 32, 35,
 43, 8, 54, 16, 30, 18, 61, 47, 54, 2, 22, 30, 42, 38, 43, 49, 5, 10, 23, 14, 17, 4, 32, 53, 7, 2, 57, 31, 55, 3, 11, 28,

/* Function parameters : 4 */
/* use_for_cycle_estimate, cols, rows, in_size, out_size */
1, 24, 3, 72, 22,

/* Image data : 4 */
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,

/* Function parameters : 5 */
/* use_for_cycle_estimate, cols, rows, in_size, out_size */
1, 28, 3, 84, 26,

/* Image data : 5 */
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

int testcases = 5;
