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
 * src align, mask align, dst align */
4, 2, 0,

/* Function parameters : 1 */
/* use_for_cycle_estimate, in_size, k_size, out_size */
0, 2, 1, 1,

/* Image data : 1 */
 5922, -18128,

/* mask : 1 */
 1,

/* Function parameters : 2 */
/* use_for_cycle_estimate, in_size, k_size, out_size */
0, 3, 1, 2,

/* Image data : 2 */
 -3095, 10834, -30429,

/* mask : 2 */
 1,

/* Function parameters : 3 */
/* use_for_cycle_estimate, in_size, k_size, out_size */
0, 13, 5, 8,

/* Image data : 3 */
 -40, -51, -124, -122, 34, -122, -97, 15, 50, -125, 7, -37, -74,

/* mask : 3 */
 119, 80, 12, 22, -68,

/* Function parameters : 4 */
/* use_for_cycle_estimate, in_size, k_size, out_size */
0, 15, 6, 9,

/* Image data : 4 */
 22, 0, 96, 86, -15, -119, -100, -75, 83, -30, 89, 21, 105, 103, -1,

/* mask : 4 */
 26, 65, 33, -108, 34, 9,

/* Function parameters : 5 */
/* use_for_cycle_estimate, in_size, k_size, out_size */
0, 21, 10, 11,

/* Image data : 5 */
 14, 6, 165, 60, -238, -253, -43, 198, 241, 256, -234, 150, -90, 203, 126, 18, -61, 245, 169, 41, 90,

/* mask : 5 */
 -7, 38, 24, -43, -33, 13, -62, -12, 0, -56,

/* Function parameters : 6 */
/* use_for_cycle_estimate, in_size, k_size, out_size */
0, 11, 10, 1,

/* Image data : 6 */
 -25, -4, -38, -25, -28, 15, 32, 57, -21, 5, 30,

/* mask : 6 */
 -25, -33, -191, -158, 193, 175, 60, -82, -130, -201,

/* Function parameters : 7 */
/* use_for_cycle_estimate, in_size, k_size, out_size */
0, 10, 9, 1,

/* Image data : 7 */
 37, -34, -3, 55, 32, 20, 32, -6, 13, 46,

/* mask : 7 */
 193, 97, 173, -199, -116, -241, -128, -158, -78,

/* Function parameters : 8 */
/* use_for_cycle_estimate, in_size, k_size, out_size */
1, 61, 13, 48,

/* Image data : 8 */
 -25,  -8,  24,  16, -26,  -3, -23, -24,  12,  24,  
   6,  -5,  -2, -10,  15,  11, -31, -17, -26,  19,
 -29,  26, -23, -10,  28, -16,   2,  11,  13,   5,
 -12,  29,   3, -15, -29,  27, -10,   3, -21,  -8,
 -19,   8,  29,   5,  28,  -1, -27,  21,  22,  -1,  
   0, -16,  14, -24,  19,  -8,  19, -31,  -2, -28,
 -19,

/* mask : 8 */
 -42, -84,-101, -34,-128,  96,-117,-108, -50, -33,  43, 101, -43,

/* Function parameters : 9 */
/* use_for_cycle_estimate, in_size, k_size, out_size */
1, 66, 5, 61,

/* Image data : 9 */
 -28, -24,   9, -54, -38, -56,  63, -30, -44,  14,  
  26,  13, -16, -42, -32,  51, -50,  24,  49,  19, 
 -33,  49, -26, -21,  39, -14, -39,  -5,  13, -61,   
   8,  48, -52,  24, -61, -15, -52,  50, -35, -44,  
  15,  31,  32, -28, -26,   3,  -9, -58,  52, -37,  
  58, -26, -38, -10,  -3,  20, -35, -63,  60,   8,  
  47, -45,  -2,  -5,  18, -20,

/* mask : 9 */
 10, -101, -26, -2, -121,

/* Function parameters : 10 */
/* use_for_cycle_estimate, in_size, k_size, out_size */
0, 24, 4, 20,

/* Image data : 10 */
  18,  49, -107, -95, 103,  27, 114,  -1, 110, 32, 
 -36,  60,   30, -84,   9, -59,  84, 119,  59, 79, 
  56, -91,   42,  19,

/* mask : 10 */
 86, 105, 13, -125,

/* Function parameters : 11 */
/* use_for_cycle_estimate, in_size, k_size, out_size */
1, 64, 9, 55,

/* Image data : 11 */
 -25,  -8,  24,  16, -26,  -3, -23, -24,  12,  24, 
   6,  -5,  -2, -10,  15,  11, -31, -17, -26,  19,
 -29,  26, -23, -10,  28, -16,   2,  11,  13,   5,
 -12,  29,   3, -15, -29,  27, -10,   3, -21,  -8,
 -19,   8,  29,   5,  28,  -1, -27,  21,  22,  -1,  
   0, -16,  14, -24,  19,  -8,  19, -31,  -2, -28,
 -19,  20,   1, -32,

/* mask : 11 */
 -16, 26, 60, 31, 21, -14, -47, 55, 3,

/* Function parameters : 12 */
/* use_for_cycle_estimate, in_size, k_size, out_size */
1, 48, 7, 41,

/* Image data : 12 */
  -56,  42,   7,  -55,   50, -108,  -90,  104,  108,  -29, 
 -102,  61,  38,   64,  -75,  -97, -120,  -33,  -15,  -97,  
   46,  99,  68,   24,  -53,  -89, -108,   14,  -92,   22,    
   87, -33,  32,   27, -102,  127,   54, -104,  -38, -105,  
  -52, -20, 105,  -32,  -86,  -27, -117, -102,

/* mask : 12 */
 -7, -23, 9, -6, 22, -8, 31,
};

int testcases = 12;
