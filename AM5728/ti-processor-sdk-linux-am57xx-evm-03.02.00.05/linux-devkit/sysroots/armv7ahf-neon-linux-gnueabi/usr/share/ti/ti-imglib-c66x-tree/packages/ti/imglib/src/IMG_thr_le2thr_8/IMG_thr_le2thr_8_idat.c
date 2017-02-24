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
/* use_for_cycle_estimate, cols, rows, threshold, dat_size (in, out) */
0, 16, 1, 191, 16,

/* Input data : 1 */
 151, 57, 116, 170, 9, 247, 208, 140, 150, 60, 88, 77, 4, 6, 162, 6,

/* Function parameters : 2 */
/* use_for_cycle_estimate, cols, rows, threshold, dat_size (in, out) */
0, 32, 2, 179, 64,

/* Input data : 2 */
 31, 143, 178,   3, 135, 91,  54, 154, 193, 161, 20, 162, 137, 150, 128, 224, 214, 113,  9,  28,  53, 211, 98, 217, 149, 233, 231, 127, 115, 203, 177,  42, 
 62, 155,   3, 103, 127, 16, 135, 131, 211, 158,  9,   2, 106, 227, 249, 255,  11, 203, 83, 230, 191, 137, 98, 251, 212, 148, 173, 115, 112,  33,  49, 224,

/* Function parameters : 3 */
/* use_for_cycle_estimate, cols, rows, threshold, dat_size (in, out) */
1, 8, 12, 0, 96,

/* Input data : 3 */
 216, 158,  87,  63,  28,  77, 120,  53, 
  77,  72, 158, 193, 242,  86, 138, 188, 
 225, 176, 214,  28,  70,   7,  64,  49, 
  89, 202,  59, 122, 239, 192, 169, 192, 
 115, 154, 221,  91, 172,  47, 161, 196, 
 255, 221,  19, 221, 141,  40,  67, 144,
 216, 158,  87,  63,  28,  77, 120,  53, 
  77,  72, 158, 193, 242,  86, 138, 188, 
 225, 176, 214,  28,  70,   7,  64,  49, 
  89, 202,  59, 122, 239, 192, 169, 192, 
 115, 154, 221,  91, 172,  47, 161, 196, 
 255, 221,  19, 221, 141,  40,  67, 144,

/* Function parameters : 4 */
/* use_for_cycle_estimate, cols, rows, threshold, dat_size (in, out) */
0, 4, 16, 1, 64,

/* Input data : 4 */
 0, 0, 0, 0, 
 0, 0, 0, 0, 
 0, 0, 0, 0, 
 0, 0, 0, 0, 
 0, 0, 0, 0, 
 0, 0, 0, 0, 
 0, 0, 0, 0, 
 0, 0, 0, 0, 
 0, 0, 0, 0, 
 0, 0, 0, 0, 
 0, 0, 0, 0, 
 0, 0, 0, 0, 
 0, 0, 0, 0, 
 0, 0, 0, 0, 
 0, 0, 0, 0, 
 0, 0, 0, 0, 

/* Function parameters : 5 */
/* use_for_cycle_estimate, cols, rows, threshold, dat_size (in, out) */
1, 16, 10, 10, 160,

/* Input data : 5 */
  5,  5,  5,  5,  5, 10, 10, 10, 10, 10, 10, 15, 15, 15, 15, 15, 
 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 
 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,

/* Function parameters : 6 */
/* use_for_cycle_estimate, cols, rows, threshold, dat_size (in, out) */
1, 30, 8, 23, 240,

/* Input data : 6 */
   1,   2,   3,   4,   5,   6,   7,   8, 
   9,  10,  11,  12,  13,  14,  15,  16, 
  17,  18,  19,  20,  21,  22,  23,  24, 
  25,  26,  27,  28,  29,  30,  31,  32, 
  33,  34,  35,  36,  37,  38,  39,  40, 
  41,  42,  43,  44,  45,  46,  47,  48, 
  49,  50,  51,  52,  53,  54,  55,  56, 
  57,  58,  59,  60,  61,  62,  63,  64,
  65,  66,  67,  68,  69,  70,  71,  72, 
  73,  74,  75,  76,  77,  78,  79,  80, 
  81,  82,  83,  84,  85,  86,  87,  88, 
  89,  90,  91,  92,  93,  94,  95,  96, 
  97,  98,  99, 100, 101, 102, 103, 104,
 105, 106, 107, 108, 109, 110, 111, 112, 
 113, 114, 115, 116, 117, 118, 119, 120, 
 121, 136, 151, 166, 181, 196, 211, 226,
 122, 137, 152, 167, 182, 197, 212, 227,
 123, 138, 153, 168, 183, 198, 213, 228,
 124, 139, 154, 169, 184, 199, 214, 229,
 125, 140, 155, 170, 185, 200, 215, 230,
 126, 141, 156, 171, 186, 201, 216, 231,
 127, 142, 157, 172, 187, 202, 217, 232,
 128, 143, 158, 173, 188, 203, 218, 233,
 129, 144, 159, 174, 189, 204, 219, 234,
 130, 145, 160, 175, 190, 205, 220, 235,
 131, 146, 161, 176, 191, 206, 221, 236,
 132, 147, 162, 177, 192, 207, 222, 237,
 133, 148, 163, 178, 193, 208, 223, 238,
 134, 149, 164, 179, 194, 209, 224, 239,
 135, 150, 165, 180, 195, 210, 225, 240,
};

int testcases = 6;
