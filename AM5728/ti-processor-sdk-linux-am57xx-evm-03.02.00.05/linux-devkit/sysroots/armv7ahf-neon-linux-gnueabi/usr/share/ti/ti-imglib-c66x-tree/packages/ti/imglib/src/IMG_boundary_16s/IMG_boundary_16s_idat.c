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
 * 0 = dooble word, 4 = word, 2 = half word, 1 = byte alignment respectively.
 * src align, dst align */
0, 4,

/* Function parameters : 1 */
/* use_for_cycle_estimate, rows, cols, in_size, out_size */
0, 1, 4, 4, 4,

/* Input data.*/
 5922, -18128, -3095, 10834,

/* Function parameters : 2 */
/* use_for_cycle_estimate, rows, cols, in_size, out_size */
0, 2, 4, 8, 0,

/* Input data.*/
 0, 0, 0, 0,
 0, 0, 0, 0,

/* Function parameters : 3 */
/* use_for_cycle_estimate, rows, cols, in_size, out_size */
1, 4, 8, 32, 13,

/* Input data.*/
 0, -15273, 28382, 0, 7482, 0, -9416, 0,
 0, 0, -13856, -4431, 0, 0, -6582, 0,
 16487, 0, 0, 0, -19783, 0, 0, -12034,
 -11927, 0, -30294, 10443, 0, 0, 0, 0,

/* Function parameters : 4 */
/* use_for_cycle_estimate, rows, cols, in_size, out_size */
1, 20, 20, 400, 14,

/* Input data.*/
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -22797, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, -4562, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, -14006, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, -18164, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25877, 0, 0, 16681, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -13584, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -31365, 0,
 0, 0, 0, 0, 6164, 0, 0, 0, 0, 0, 0, 0, 5908, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, -13639, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, -25289, 0, 0, 0, 0, 0, 0, 0, 0, -10549, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 16347, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

/* Function parameters : 5 */
/* use_for_cycle_estimate, rows, cols, in_size, out_size */
1, 7, 4, 28, 12,

/* Input data.*/
 0, 0, -21421, 0,
 0, 0, 16575, 0,
 -14266, 29084, -27750, 24593,
 25238, -45853, 12981, 0,
 0, 0, 28438, 0,
 10386, 0, 28144, 0,
 0, 0, 0, 0,

/* Function parameters : 6 */
/* use_for_cycle_estimate, rows, cols, in_size, out_size */
1, 4, 12, 48, 1,

/* Input data.*/
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 15621, 0, 0, 0, 0, 0, 0, 0,
};

int testcases = 6;
