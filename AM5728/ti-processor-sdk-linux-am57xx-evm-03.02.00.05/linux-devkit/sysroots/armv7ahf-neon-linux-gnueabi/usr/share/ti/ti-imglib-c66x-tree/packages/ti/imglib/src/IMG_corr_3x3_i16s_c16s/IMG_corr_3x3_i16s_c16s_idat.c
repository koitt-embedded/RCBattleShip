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
2, 2, 0,

/* Function parameters : 1 */
/* use_for_cycle_estimate, width, pitch, shift, round, in_size, out_size */
0, 4, 6, 6, 1, 18, 4,

/* Image data : 1 */
 5922, 10834, 20433, -17341, -31820, -31255,
 -18128, -30429, 3054, -10155, -31140, -24757,
 -3095, 30451, 5556, -13139, 8651, 3822,

/* mask : 1 */
 1, 2, 3,
 4, 5, 6,
 7, 8, 9,

/* Function parameters : 2 */
/* use_for_cycle_estimate, width, pitch, shift, round, in_size, out_size */
1, 32, 34, 5, 0, 102, 32,

/* Image data : 2 */
 8637, 107, -3893, -19117, 22667, 26488, 19279, -16864, -6379, 1821, 7653, -5543, 32756, -11470, 2343, 21630, -3205, -20263, 7654, -25678, -19326, 7659, -10653, 24750, -25514, -16394, 18860, 28411, 16396, 23731, -20779, 32697, 23798, -15605,
 2422, 24583, -30362, 21185, 5429, -261, 12465, 6892, -197, 734, -30471, 25363, -30004, 26017, -7789, 5187, -4209, 24657, -10506, -12973, -13048, 16558, 2504, 12378, -14850, -20262, -17559, 16487, -3306, -9416, 8330, 23722, 3418, 4031,
 5740, 22004, -25709, -7688, 26798, -3329, -21978, -31959, -28652, 21135, -32349, 30861, 19149, 16069, 31371, 11557, -24399, 22422, -16624, -2072, -14408, 29299, 15248, 22104, -30891, -10032, -1578, 10443, 6622, 11174, 17514, -27988, -22422, -9177,

/* mask : 2 */
 1611, -4013, 211,
 -1185, -2352, 842,
 2075, 1070, -3461,

/* Function parameters : 3 */
/* use_for_cycle_estimate, width, pitch, shift, round, in_size, out_size */
1, 12, 14, 5, 1, 42, 12,

/* Image data : 3 */
 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,

/* mask : 3 */
 26048, 15744, -17937,
 606, 28722, -15273,
 17947, -19783, -28814,

/* Function parameters : 4 */
/* use_for_cycle_estimate, width, pitch, shift, round, in_size, out_size */
0, 8, 10, 5, 0, 30, 8,

/* Image data : 4 */
 -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768,
 -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768,
 -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768,

/* mask : 4 */
 26048, 15744, -17937,
 606, 28722, -15273,
 17947, -19783, -28814,

/* Function parameters : 5 */
/* use_for_cycle_estimate, width, pitch, shift, round, in_size, out_size */
1, 40, 42, 5, 1, 126, 40,

/* Image data : 5 */
 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,

/* mask : 5 */
 32767, 32767, 32767,
 32767, 32767, 32767,
 32767, 32767, 32767,

/* Function parameters : 6 */
/* use_for_cycle_estimate, width, pitch, shift, round, in_size, out_size */
0, 4, 6, 5, 0, 18, 4,

/* Image data : 6 */
 -32768, -32768, -32768, -32768, -32768, -32768,
 -32768, -32768, -32768, -32768, -32768, -32768,
 -32768, -32768, -32768, -32768, -32768, -32768,

/* mask : 6 */
 -32767, -32767, -32767,
 -32767, -32767, -32767,
 -32767, -32767, -32767,

/* Function parameters : 7 */
/* use_for_cycle_estimate, width, pitch, shift, round, in_size, out_size */
1, 12, 14, 5, 1, 42, 12,

/* Image data : 7 */
 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,

/* mask : 7 */
 -32768, -32768, -32768,
 -32768, -32768, -32768,
 -32768, -32768, -32768,
};

int testcases = 7;
