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
 38690, 43602, 53201, 15427,
 14640, 2339, 35822, 22613,
 29673, 63219, 38324, 19629,

/* Function parameters : 2 */
/* use_for_cycle_estimate, cols, rows, in_size, out_size */
1, 24, 3, 72, 22,

/* Image data : 2 */
 948, 1513, 45653, 23288, 49372, 41405, 32875, 28875, 13651, 55435, 59256, 52047, 15904, 26389, 34589, 40421, 27225, 65524, 21298, 35111, 54398, 29563, 12505, 40422,
 1628, 8011, 665, 13950, 41325, 35190, 57351, 2406, 53953, 38197, 32507, 45233, 39660, 32571, 33502, 2297, 58131, 2764, 58785, 24979, 37955, 28559, 57425, 22262,
 41419, 36590, 34456, 39507, 5083, 38508, 54772, 7059, 25080, 59566, 29439, 10790, 809, 4116, 53903, 419, 63629, 51917, 48837, 64139, 44325, 8369, 55190, 16144,

/* Function parameters : 3 */
/* use_for_cycle_estimate, cols, rows, in_size, out_size */
1, 20, 3, 60, 18,

/* Image data : 3 */
 1773, 3361, 10107, 5529, 14379, 1813, 4094, 12907, 15295, 12291, 14125, 2997, 16366, 14141, 4291, 14704, 8344, 12679, 619, 11632,
 4949, 4930, 12332, 8818, 11286, 4479, 3127, 3802, 12314, 7365, 5838, 10275, 14122, 9047, 9200, 12128, 15372, 3246, 8600, 2513,
 7674, 4590, 15517, 12004, 13718, 469, 5684, 7798, 10803, 9848, 10986, 12570, 1195, 2586, 5898, 3708, 4374, 989, 8275, 13524,

/* Function parameters : 4 */
/* use_for_cycle_estimate, cols, rows, in_size, out_size */
0, 8, 3, 24, 6,

/* Image data : 4 */
 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535,
 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535,
 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535,

/* Function parameters : 5 */
/* use_for_cycle_estimate, cols, rows, in_size, out_size */
1, 28, 3, 84, 26,

/* Image data : 5 */
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

int testcases = 5;
