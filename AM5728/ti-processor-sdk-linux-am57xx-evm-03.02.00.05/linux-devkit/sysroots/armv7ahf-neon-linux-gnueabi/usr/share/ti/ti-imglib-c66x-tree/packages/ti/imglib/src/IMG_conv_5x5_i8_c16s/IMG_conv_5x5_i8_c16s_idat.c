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
1, 2, 4,

/* Function parameters : 1 */
/* use_for_cycle_estimate, width, pitch, shift, in_size, out_size */
0, 2, 6, 9, 30, 2,

/* Image data : 1 */
 151, 247, 88, 6, 135, 161,
 57, 208, 77, 31, 91, 20,
 116, 140, 4, 143, 54, 162,
 170, 150, 6, 178, 154, 137,
 9, 60, 162, 3, 193, 150,

/* mask : 1 */
 1, 2, 3, 4, 5,
 6, 7, 8, 9, 10,
 11, 12, 13, 14, 15,
 16, 17, 18, 19, 20,
 21, 22, 23, 24, 25,

/* Function parameters : 2 */
/* use_for_cycle_estimate, width, pitch, shift, in_size, out_size */
1, 30, 34, 16, 170, 30,

/* Image data : 2 */
 131, 106, 203, 98, 115, 216, 77, 158, 188, 70, 202, 169, 91, 255, 40, 190, 198, 129, 138, 239, 124, 231, 133, 0, 3, 231, 160, 137, 207, 95, 99, 233, 90, 140,
 211, 227, 83, 251, 112, 158, 120, 193, 225, 7, 59, 192, 172, 221, 67, 58, 51, 182, 27, 81, 117, 11, 139, 246, 146, 155, 92, 69, 184, 180, 34, 71, 13, 6,
 158, 249, 230, 212, 33, 87, 53, 242, 176, 64, 122, 115, 47, 19, 144, 130, 15, 39, 102, 226, 245, 167, 111, 214, 177, 242, 188, 212, 37, 249, 239, 157, 144, 59,
 9, 255, 191, 148, 49, 63, 77, 86, 214, 49, 239, 154, 161, 221, 92, 240, 10, 211, 126, 4, 218, 127, 117, 233, 21, 127, 158, 247, 170, 191, 133, 53, 167, 210,
 2, 11, 137, 173, 224, 28, 72, 138, 28, 89, 192, 221, 196, 141, 230, 68, 134, 46, 7, 109, 88, 44, 237, 141, 33, 238, 44, 187, 147, 170, 101, 122, 174, 235,

/* mask : 2 */
 4109, 7169, 6846, 3609, 301,
 882, 1706, 6744, 3135, 6929,
 4775, 7446, 7407, 4063, 3680,
 6506, 5654, 1349, 1988, 4958,
 101, 3299, 4071, 514, 4324,

/* Function parameters : 3 */
/* use_for_cycle_estimate, width, pitch, shift, in_size, out_size */
1, 10, 14, 16, 70, 10,

/* Image data : 3 */
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,

/* mask : 3 */
 -32768, -32768, -14491, 32767, 7974,
 -32768, 12933, 20414, 8936, 32767,
 -11331, -32768, -32768, -32768, -1751,
 -25104, -32768, -32768, -32768, -32768,
 -7907, -32768, -32768, -32768, -32768,

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
 -32768, -32768, -14491, 32767, 7974,
 -32768, 12933, 20414, 8936, 32767,
 -11331, -32768, -32768, -32768, -1751,
 -25104, -32768, -32768, -32768, -32768,
 -7907, -32768, -32768, -32768, -32768,

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
 32767, 32767, 32767, 32767, 32767,
 32767, 32767, 32767, 32767, 32767,
 32767, 32767, 32767, 32767, 32767,
 32767, 32767, 32767, 32767, 32767,
 32767, 32767, 32767, 32767, 32767,

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
 32767, 32767, 32767, 32767, 32767,
 32767, 32767, 32767, 32767, 32767,
 32767, 32767, 32767, 32767, 32767,
 32767, 32767, 32767, 32767, 32767,
 32767, 32767, 32767, 32767, 32767,

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
 32767, 32767, 32767, 32767, 32767,
 32767, 32767, 32767, 32767, 32767,
 32767, 32767, 32767, 32767, 32767,
 32767, 32767, 32767, 32767, 32767,
 32767, 32767, 32767, 32767, 32767,

/* Function parameters : 8 */
/* use_for_cycle_estimate, width, pitch, shift, in_size, out_size */
1, 14, 18, 16, 90, 14,

/* Image data : 8 */
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,

/* mask : 8 */
 -32768, -32768, -32768, -32768, -32768,
 -32768, -32768, -32768, -32768, -32768,
 -32768, -32768, -32768, -32768, -32768,
 -32768, -32768, -32768, -32768, -32768,
 -32768, -32768, -32768, -32768, -32768,
};

int testcases = 8;
