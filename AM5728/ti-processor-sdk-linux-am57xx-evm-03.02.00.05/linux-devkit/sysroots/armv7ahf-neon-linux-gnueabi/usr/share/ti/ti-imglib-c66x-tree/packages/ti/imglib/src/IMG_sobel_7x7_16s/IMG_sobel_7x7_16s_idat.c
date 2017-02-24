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
0, 8, 7, 56, 2,

/* Image data : 1 */
 740, 382, 1081, -1185, 303, -3214, 3311, 862,
 -2266, 694, -3907, -2352, 717, -2390, -33, -3995,
 -387, -2168, -3095, 842, 13, 2648, -416, -797,
 1354, -1269, 478, 2075, 3073, -961, 2410, -25,
 -3804, -1642, 1611, 1070, 2750, 2833, 1558, -3582,
 3806, -3978, -4013, -3461, -487, 679, -2747, 228,
 2554, -3892, 211, 1080, -3795, 3350, -2108, 92,

/* Function parameters : 2 */
/* use_for_cycle_estimate, cols, rows, in_size, out_size */
0, 10, 7, 70, 4,

/* Image data : 2 */
 2642, 4095, -974, -3050, -3210, 2070, 2763, 2358, -413, 2189,
 957, -3751, 3921, -2533, -1622, 3662, -3189, -2195, 828, 4087,
 -3809, 2394, 2704, 3082, -259, -1332, -1856, -197, 2966, 2965,
 -4044, -1434, 648, 2803, -2416, 313, -3861, 3551, -1177, -3498,
 -693, 3252, 1445, 957, -1631, 1906, -2049, 2061, 1397, 2975,
 3170, 2009, -401, -1313, -1801, 3094, -2533, 1305, -2597, 427,
 3858, 293, -526, -2078, 957, 1547, -1254, 2050, 1041, -2803,

/* Function parameters : 3 */
/* use_for_cycle_estimate, cols, rows, in_size, out_size */
1, 22, 7, 154, 16,

/* Image data : 3 */
 -488, 898, 10, -206, -151, -937, -91, -1003, 916, -673, 452, 503, 844, 127, 853, 715, 770, 501, 582, -425, -790, 617,
 126, -477, 430, -14, -33, 315, 872, 147, -11, 73, -729, 334, -457, 310, 312, -259, -910, 539, -243, 508, -980, 827,
 -287, 561, -710, -970, -90, -5, -1022, 395, 883, -472, 334, -232, 236, 365, -806, 992, 568, -282, -293, -143, 620, 289,
 814, -618, 667, 887, 935, -673, 945, -855, 260, 672, 155, -750, -598, 96, -209, 588, 986, 522, 185, -97, -127, 511,
 492, -900, -656, -373, 722, 43, 690, -763, -291, 953, -262, 885, -44, -979, -739, -972, -738, 948, 193, -426, -712, 470,
 -561, -947, 78, 787, -322, 84, 840, 820, 477, 475, 419, 44, -302, -551, 272, 467, -486, 977, -673, 521, -630, -438,
 19, 51, -811, -994, 824, -138, 108, 220, 239, 632, 967, -216, -919, 655, -192, -739, 1004, -526, -414, -330, -794, 157,

/* Function parameters : 4 */
/* use_for_cycle_estimate, cols, rows, in_size, out_size */
1, 18, 7, 126, 12,

/* Image data : 4 */
 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,

/* Function parameters : 5 */
/* use_for_cycle_estimate, cols, rows, in_size, out_size */
1, 20, 7, 140, 14,

/* Image data : 5 */
 -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768,
 -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768,
 -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768,
 -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768,
 -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768,
 -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768,
 -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768,
};

int testcases = 5;
