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
2, 2,

/* Function parameters : 1 */
/* use_for_cycle_estimate, cols, rows, in_size, out_size */
0, 4, 3, 12, 2,

/* Image data : 1 */
 5922, 10834, 20433, -17341,
 -18128, -30429, 3054, -10155,
 -3095, 30451, 5556, -13139,

/* Function parameters : 2 */
/* use_for_cycle_estimate, cols, rows, in_size, out_size */
1, 24, 3, 72, 22,

/* Image data : 2 */
 -31820, -31255, 12885, -9480, 16604, 8637, 107, -3893, -19117, 22667, 26488, 19279, -16864, -6379, 1821, 7653, -5543, 32756, -11470, 2343, 21630, -3205, -20263, 7654,
 -31140, -24757, -32103, -18818, 8557, 2422, 24583, -30362, 21185, 5429, -261, 12465, 6892, -197, 734, -30471, 25363, -30004, 26017, -7789, 5187, -4209, 24657, -10506,
 8651, 3822, 1688, 6739, -27685, 5740, 22004, -25709, -7688, 26798, -3329, -21978, -31959, -28652, 21135, -32349, 30861, 19149, 16069, 31371, 11557, -24399, 22422, -16624,

/* Function parameters : 3 */
/* use_for_cycle_estimate, cols, rows, in_size, out_size */
1, 20, 3, 60, 18,

/* Image data : 3 */
 -3210, -2416, 957, -1332, 3094, -3189, -2049, 2358, 3551, 2050, 2966, -2597, 4087, 2975, -1951, 3256, 76, 2243, -3787, 1720,
 -1622, -1631, 2070, 313, 1547, -1856, -2533, -2195, 2061, -413, -1177, 1041, 2965, 427, 504, 1968, 3590, -2473, 204, -2840,
 -259, -1801, 3662, 1906, 2763, -3861, -1254, -197, 1305, 828, 1397, 2189, -3498, -2803, -1147, -2242, -1909, -3602, 42, 2666,

/* Function parameters : 4 */
/* use_for_cycle_estimate, cols, rows, in_size, out_size */
0, 8, 3, 24, 6,

/* Image data : 4 */
 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,

/* Function parameters : 5 */
/* use_for_cycle_estimate, cols, rows, in_size, out_size */
1, 28, 3, 84, 26,

/* Image data : 5 */
 -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768,
 -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768,
 -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768,
};

int testcases = 5;
