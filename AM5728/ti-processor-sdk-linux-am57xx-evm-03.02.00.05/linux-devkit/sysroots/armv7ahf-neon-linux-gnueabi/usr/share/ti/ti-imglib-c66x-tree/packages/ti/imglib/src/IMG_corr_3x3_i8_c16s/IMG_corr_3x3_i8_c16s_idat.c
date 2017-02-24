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
1, 2, 0,

/* Function parameters : 1 */
/* use_for_cycle_estimate, width, pitch, in_size, out_size */
0, 2, 4, 12, 2,

/* Image data : 1 */
 151, 170, 208, 60,
 57, 9, 140, 88,
 116, 247, 150, 77,

/* mask : 1 */
 -50, -49, -48,
 -47, -46, -45,
 -44, -43, -42,

/* Function parameters : 2 */
/* use_for_cycle_estimate, width, pitch, in_size, out_size */
1, 30, 32, 96, 30,

/* Image data : 2 */
 91, 193, 162, 128, 113, 53, 217, 231, 203, 62, 103, 135, 158, 106, 255, 83, 137, 212, 115, 49, 158, 28, 53, 158, 86, 225, 28, 64, 202, 239, 192, 221,
 54, 161, 137, 224, 9, 211, 149, 127, 177, 155, 127, 131, 9, 227, 11, 230, 98, 148, 112, 224, 87, 77, 77, 193, 138, 176, 70, 49, 59, 192, 115, 91,
 154, 20, 150, 214, 28, 98, 233, 115, 42, 3, 16, 211, 2, 249, 203, 191, 251, 173, 33, 216, 63, 120, 72, 242, 188, 214, 7, 89, 122, 169, 154, 172,

/* mask : 2 */
 -31820, -31140, 8651,
 -31255, -24757, 3822,
 12885, -32103, 1688,

/* Function parameters : 3 */
/* use_for_cycle_estimate, width, pitch, in_size, out_size */
1, 10, 12, 36, 10,

/* Image data : 3 */
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,

/* mask : 3 */
 -20779, 8330, 17514,
 32697, 23722, -27988,
 23798, 3418, -22422,

/* Function parameters : 4 */
/* use_for_cycle_estimate, width, pitch, in_size, out_size */
0, 8, 10, 30, 8,

/* Image data : 4 */
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

/* mask : 4 */
 -20779, 8330, 17514,
 32697, 23722, -27988,
 23798, 3418, -22422,

/* Function parameters : 5 */
/* use_for_cycle_estimate, width, pitch, in_size, out_size */
1, 40, 42, 126, 40,

/* Image data : 5 */
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 
 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 

/* mask : 5 */
 32767, 32767, 32767,
 32767, 32767, 32767,
 32767, 32767, 32767,

/* Function parameters : 6 */
/* use_for_cycle_estimate, width, pitch, in_size, out_size */
0, 4, 6, 18, 4,

/* Image data : 6 */
 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255,
 255, 255, 255, 255, 255, 255,

/* mask : 6 */
 -32768, -32768, -32768,
 -32768, -32768, -32768,
 -32768, -32768, -32768,
};

int testcases = 6;
