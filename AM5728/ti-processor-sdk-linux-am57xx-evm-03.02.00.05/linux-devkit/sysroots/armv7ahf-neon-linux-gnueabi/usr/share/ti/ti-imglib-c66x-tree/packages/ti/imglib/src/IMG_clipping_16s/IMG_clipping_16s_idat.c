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
/* use_for_cycle_estimate, cols, rows, threshold_max, threshold_min, dat_size (in, out) */
0, 4, 2, 24575, -8192, 8,

/* Input data : 1 */
 5922, -18128, -3095, 10834, -30429, 30451, 20433, 3054,

/* Function parameters : 2 */
/* use_for_cycle_estimate, cols, rows, threshold_max, threshold_min, dat_size (in, out) */
1, 12, 2, 22937, -13107, 24,

/* Input data : 2 */
 5556, -17341, -10155, -13139, -31820, -31140, 8651, -31255, -24757, 3822, 12885, -32103, 1688, -9480, -18818, 6739, 16604, 8557, -27685, 8637, 2422, 5740, 107, 24583,

/* Function parameters : 3 */
/* use_for_cycle_estimate, cols, rows, threshold_max, threshold_min, dat_size (in, out) */
1, 8, 7, 100, 100, 56,

/* Input data : 3 */
 22004, -3893, -30362, -25709, -19117, 21185, -7688, 22667, 5429, 26798, 26488, -261, -3329, 19279, 12465, -21978, -16864, 6892, -31959, -6379, -197, -28652, 1821, 734, 21135, 7653, -30471, -32349, -5543, 25363, 30861, 32756, -30004, 19149, -11470, 26017, 16069, 2343, -7789, 31371, 21630, 5187, 11557, -3205, -4209, -24399, -20263, 24657, 22422, 7654, -10506, -16624, -25678, -12973, -2072, -19326,

/* Function parameters : 4 */
/* use_for_cycle_estimate, cols, rows, threshold_max, threshold_min, dat_size (in, out) */
1, 4, 12, 1, 1, 48,

/* Input data : 4 */
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

/* Function parameters : 5 */
/* use_for_cycle_estimate, cols, rows, threshold_max, threshold_min, dat_size (in, out) */
1, 4, 10, 14, 9, 40,

/* Input data : 5 */
 5, 5, 5, 5, 5, 10, 10, 10, 10, 10, 10, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,

/* Function parameters : 6 */
/* use_for_cycle_estimate, cols, rows, threshold_max, threshold_min, dat_size (in, out) */
0, 8, 6, 23, 13, 48,

/* Input data : 6 */
 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48,
};

int testcases = 6;
