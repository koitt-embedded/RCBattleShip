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
0, 0,

/* Function parameters : 1 */
/* use_for_cycle_estimate, cols, in_size, out_size, count */
0, 16, 48, 16, 5,

/* Input data : 1 */
 151, 170, 208, 0, 0, 0, 178, 0, 193, 162, 128, 0, 0, 217, 231, 203,
 0, 0, 140, 0, 0, 0, 0, 0, 161, 137, 224, 0, 211, 149, 0, 177,
 0, 247, 150, 0, 162, 143, 135, 154, 0, 150, 214, 0, 0, 233, 0, 0,

/* Function parameters : 2 */
/* use_for_cycle_estimate, cols, in_size, out_size, count */
1, 80, 240, 80, 20,

/* Input data : 2 */
 0, 0, 0, 0, 0, 255, 0, 0, 212, 0, 0, 0, 0, 0, 0, 0, 225, 0, 0, 0, 239, 0, 221, 0, 255, 221, 0, 230, 0, 0, 0, 0, 0, 0, 239, 0, 0, 0, 0, 0, 0, 246, 0, 0, 231, 0, 0, 0, 212, 207, 0, 0, 0, 239, 233, 0, 0, 0, 0, 0, 0, 217, 0, 0, 0, 0, 0, 247, 0, 0, 0, 0, 0, 0, 0, 205, 0, 0, 0, 252,
 0, 0, 0, 0, 227, 0, 230, 0, 0, 0, 224, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 221, 0, 0, 0, 240, 0, 0, 0, 0, 0, 0, 0, 245, 231, 0, 0, 237, 214, 0, 0, 0, 238, 0, 0, 247, 0, 0, 249, 0, 0, 0, 0, 0, 0, 210, 0, 0, 0, 0, 224, 251, 254, 0, 250, 0, 0, 0, 0, 0, 206, 0, 231, 0, 247, 0, 250,
 0, 0, 211, 0, 249, 0, 0, 251, 0, 0, 216, 0, 0, 0, 242, 0, 214, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 211, 0, 0, 226, 0, 218, 0, 0, 0, 0, 233, 0, 0, 242, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 235, 0, 0, 252, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

/* Function parameters : 3 */
/* use_for_cycle_estimate, cols, in_size, out_size, count */
1, 48, 144, 48, 0,

/* Input data : 3 */
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

/* Function parameters : 4 */
/* use_for_cycle_estimate, cols, in_size, out_size, count */
1, 48, 144, 48, 0,

/* Input data : 4 */
 151, 127, 25, 229, 200, 61, 63, 110, 240, 204, 229, 135, 237, 211, 162, 165, 63, 91, 87, 63, 86, 40, 19, 254, 234, 218, 101, 99, 223, 180, 218, 52, 173, 8, 38, 67, 119, 143, 9, 27, 127, 54, 193, 251, 11, 194, 164, 229,
 57, 19, 90, 190, 236, 68, 253, 216, 23, 77, 66, 44, 147, 226, 11, 88, 103, 83, 139, 211, 25, 166, 127, 160, 154, 66, 52, 191, 241, 187, 130, 146, 127, 195, 141, 76, 130, 128, 230, 131, 159, 121, 65, 15, 176, 252, 89, 144,
 98, 163, 19, 62, 239, 20, 115, 27, 29, 143, 70, 255, 20, 73, 157, 89, 227, 10, 174, 182, 115, 109, 251, 22, 67, 122, 83, 245, 226, 195, 195, 11, 70, 57, 39, 3, 16, 232, 242, 80, 50, 167, 227, 125, 239, 183, 12, 44,
};

int testcases = 4;
