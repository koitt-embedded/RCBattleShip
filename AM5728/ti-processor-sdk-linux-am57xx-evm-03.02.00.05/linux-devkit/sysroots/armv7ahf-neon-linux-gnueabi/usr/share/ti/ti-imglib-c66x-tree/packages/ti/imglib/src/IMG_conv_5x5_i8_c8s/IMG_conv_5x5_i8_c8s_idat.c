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
/* Test data for kernel size : 5 x 5 
 * kernel size */
 5,
/* Alignment data.
 * 0 = dooble word, 4 = word, 2 = half word, 1 = byte alignment respectively.
 * src align, mask align, dst align */
1, 1, 4,

/* Function parameters : 1 */
/* use_for_cycle_estimate, width, pitch, shift, in_size, out_size */
0, 4, 8, 8, 40, 4,

/* Image data : 1 */
 161, 128, 28, 149, 203, 3, 131, 106,
 20, 224, 53, 233, 177, 103, 211, 227,
 162, 214, 211, 231, 42, 127, 158, 249,
 137, 113, 98, 127, 62, 16, 9, 255,
 150, 9, 217, 115, 155, 135, 2, 11,

/* mask : 1 */
 23, -71, -12, 42, -119,
 119, 80, 12, 22, -68,
 -40, -51, -124, -122, 34,
 -122, -97, 15, 50, -125,
 7, -37, -74, 26, 65,

/* Function parameters : 2 */
/* use_for_cycle_estimate, width, pitch, shift, in_size, out_size */
1, 32, 36, 12, 180, 32,

/* Image data : 2 */
 158, 188, 70, 202, 169, 91, 255, 40, 190, 198, 129, 138, 239, 124, 231, 133, 0, 3, 231, 160, 137, 207, 95, 99, 233, 90, 140, 167, 104, 7, 199, 191, 250, 151, 192, 87,
 193, 225, 7, 59, 192, 172, 221, 67, 58, 51, 182, 27, 81, 117, 11, 139, 246, 146, 155, 92, 69, 184, 180, 34, 71, 13, 6, 27, 217, 186, 251, 195, 62, 152, 110, 29,
 242, 176, 64, 122, 115, 47, 19, 144, 130, 15, 39, 102, 226, 245, 167, 111, 214, 177, 242, 188, 212, 37, 249, 239, 157, 144, 59, 102, 96, 36, 36, 93, 201, 44, 116, 5,
 86, 214, 49, 239, 154, 161, 221, 92, 240, 10, 211, 126, 4, 218, 127, 117, 233, 21, 127, 158, 247, 170, 191, 133, 53, 167, 210, 36, 252, 224, 67, 193, 98, 76, 75, 206,
 138, 28, 89, 192, 221, 196, 141, 230, 68, 134, 46, 7, 109, 88, 44, 237, 141, 33, 238, 44, 187, 147, 170, 101, 122, 174, 235, 162, 202, 14, 254, 247, 91, 75, 193, 112,

/* mask : 2 */
 101, 42, 115, 95, 69,
 49, 125, 106, 74, 87,
 58, 56, 16, 24, 112,
 108, 79, 43, 32, 14,
 39, 60, 26, 39, 36,

/* Function parameters : 3 */
/* use_for_cycle_estimate, width, pitch, shift, in_size, out_size */
1, 12, 16, 16, 80, 12,

/* Image data : 3 */
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,

/* mask : 3 */
 -128, -98, -47, 127, -128,
 32, 77, 113, -128, -74,
 -67, -128, -128, 127, -128,
 -28, -105, -128, -128, -14,
 -128, 72, 18, -128, -128,

/* Function parameters : 4 */
/* use_for_cycle_estimate, width, pitch, shift, in_size, out_size */
0, 8, 12, 16, 60, 8,

/* Image data : 4 */
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

/* mask : 4 */
 -128, -98, -47, 127, -128,
 32, 77, 113, -128, -74,
 -67, -128, -128, 127, -128,
 -28, -105, -128, -128, -14,
 -128, 72, 18, -128, -128,

/* Function parameters : 5 */
/* use_for_cycle_estimate, width, pitch, shift, in_size, out_size */
1, 40, 44, 16, 220, 40,

/* Image data : 5 */
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,

/* mask : 5 */
 127, 127, 127, 127, 127,
 127, 127, 127, 127, 127,
 127, 127, 127, 127, 127,
 127, 127, 127, 127, 127,
 127, 127, 127, 127, 127,

/* Function parameters : 6 */
/* use_for_cycle_estimate, width, pitch, shift, in_size, out_size */
0, 4, 8, 16, 40, 4,

/* Image data : 6 */
 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255,

/* mask : 6 */
 127, 127, 127, 127, 127,
 127, 127, 127, 127, 127,
 127, 127, 127, 127, 127,
 127, 127, 127, 127, 127,
 127, 127, 127, 127, 127,

/* Function parameters : 7 */
/* use_for_cycle_estimate, width, pitch, shift, in_size, out_size */
1, 12, 16, 11, 80, 12,

/* Image data : 7 */
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,

/* mask : 7 */
 127, 127, 127, 127, 127,
 127, 127, 127, 127, 127,
 127, 127, 127, 127, 127,
 127, 127, 127, 127, 127,
 127, 127, 127, 127, 127,

/* Function parameters : 8 */
/* use_for_cycle_estimate, width, pitch, shift, in_size, out_size */
1, 16, 20, 16, 100, 16,

/* Image data : 8 */
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,

/* mask : 8 */
 -128, -128, -128, -128, -128,
 -128, -128, -128, -128, -128,
 -128, -128, -128, -128, -128,
 -128, -128, -128, -128, -128,
 -128, -128, -128, -128, -128,
};

int testcases = 8;
