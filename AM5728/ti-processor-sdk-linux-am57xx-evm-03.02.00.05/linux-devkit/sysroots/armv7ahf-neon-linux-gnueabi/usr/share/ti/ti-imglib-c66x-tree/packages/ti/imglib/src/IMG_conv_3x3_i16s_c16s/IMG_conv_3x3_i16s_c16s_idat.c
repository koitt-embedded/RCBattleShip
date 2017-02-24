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
 * 0 = dooble word, 4 = word, 2 = half word, 1 = byte alignment respectively.
 * src align, mask align, dst align */
2, 2, 4,

/* Function parameters : 1 */
/* use_for_cycle_estimate, width, pitch, shift, in_size, out_size */
0, 2, 4, 13, 12, 2,

/* Image data : 1 */
 -17341, -31820, -31255, 12885,
 -10155, -31140, -24757, -32103,
 -13139, 8651, 3822, 1688,

/* mask : 1 */
 740, -2266, -387,
 1354, -3804, 3806,
 2554, 382, 694,

/* Function parameters : 2 */
/* use_for_cycle_estimate, width, pitch, shift, in_size, out_size */
1, 10, 12, 13, 36, 10,

/* Image data : 2 */
 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,

/* mask : 2 */
 740, -2266, -387,
 1354, -3804, 3806,
 2554, 382, 694,

/* Function parameters : 3 */
/* use_for_cycle_estimate, width, pitch, shift, in_size, out_size */
0, 8, 10, 13, 30, 8,

/* Image data : 3 */
 -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768,
 -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768,
 -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768,

/* mask : 3 */
 740, -2266, -387,
 1354, -3804, 3806,
 2554, 382, 694,

/* Function parameters : 4 */
/* use_for_cycle_estimate, width, pitch, shift, in_size, out_size */
1, 40, 42, 16, 126, 40,

/* Image data : 4 */
 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,

/* mask : 4 */
 7281, 7281, 7281,
 7281, 7281, 7281,
 7281, 7281, 7281,

/* Function parameters : 5 */
/* use_for_cycle_estimate, width, pitch, shift, in_size, out_size */
0, 4, 6, 16, 18, 4,

/* Image data : 5 */
 32767, 32767, 32767, 32767, 32767, 32767,
 32767, 32767, 32767, 32767, 32767, 32767,
 32767, 32767, 32767, 32767, 32767, 32767,

/* mask : 5 */
 7287, 7281, 7281,
 7281, 7281, 7281,
 7281, 7281, 7281,

/* Function parameters : 6 */
/* use_for_cycle_estimate, width, pitch, shift, in_size, out_size */
1, 12, 14, 16, 42, 12,

/* Image data : 6 */
 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,

/* mask : 6 */
 32767, 32767, 0,
 0, 0, 0,
 0, 0, 0,

/* Function parameters : 7 */
/* use_for_cycle_estimate, width, pitch, shift, in_size, out_size */
1, 14, 16, 16, 48, 14,

/* Image data : 7 */
 -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768,
 -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768,
 -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768,

/* mask : 7 */
 -32768, -32767, 0,
 0, 0, 0,
 0, 0, 0,
};

int testcases = 7;
