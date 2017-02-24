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
2, 2, 2,

/* Function parameters : 1 */
/* use_for_cycle_estimate, width, shift, in_size, out_size */
0, 8, 4, 26, 8,

/* Image data : 1 */
 38690, 43602, 53201, 15427,   948,  1513, 45653, 23288,
 14640,  2339, 35822, 22613,  1628,  8011,   665, 13950,
 29673, 63219, 38324, 19629, 41419, 36590, 34456, 39507,
 38690, 43602,

/* mask : 1 */
  5,  4,  3,
  2,  1,  0,
 -1, -2, -3,

/* Function parameters : 2 */
/* use_for_cycle_estimate, width, shift, in_size, out_size */
0, 16, 17, 50, 16,

/* Image data : 2 */
 28875, 13651, 55435, 59256, 52047, 15904, 26389, 34589, 40421, 27225, 65524, 21298, 35111, 54398, 29563, 12505,
  2406, 53953, 38197, 32507, 45233, 39660, 32571, 33502,  2297, 58131,  2764, 58785, 24979, 37955, 28559, 57425,
  7059, 25080, 59566, 29439, 10790,   809,  4116, 53903,   419, 63629, 51917, 48837, 64139, 44325,  8369, 55190,
 28875, 13651,

/* mask : 2 */
 6846, 7169, 4109,
 4813, 4399, 5176,
  635, 5166, 6171,

/* Function parameters : 3 */
/* use_for_cycle_estimate, width, shift, in_size, out_size */
1, 24, 16, 74, 24,

/* Image data : 3 */
 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535,
 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535,
 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535,
 65535, 65535,

/* mask : 3 */
  32767, -32768, -32765,
 -32768, -32768, -32768,
  -7842, -32768,   5982,

/* Function parameters : 4 */
/* use_for_cycle_estimate, width, shift, in_size, out_size */
0, 8, 16, 26, 8,

/* Image data : 4 */
 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0,

/* mask : 4 */
  32767, -32768, -32765,
 -32768, -32768, -32768,
  -7842, -32768,   5982,

/* Function parameters : 5 */
/* use_for_cycle_estimate, width, shift, in_size, out_size */
1, 32, 16, 98, 32,

/* Image data : 5 */
 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535,
 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535,
 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535,
 65535, 65535,

/* mask : 5 */
 7281, 7281, 7281,
 7281, 7281, 7281,
 7281, 7281, 7281,

/* Function parameters : 6 */
/* use_for_cycle_estimate, width, shift, in_size, out_size */
1, 16, 16, 50, 16,

/* Image data : 6 */
 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535,
 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535,
 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535,
 65535, 65535,

/* mask : 6 */
 7287, 7281, 7281,
 7281, 7281, 7281,
 7281, 7281, 7281,

/* Function parameters : 7 */
/* use_for_cycle_estimate, width, shift, in_size, out_size */
1, 24, 11, 74, 24,

/* Image data : 7 */
 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535,
 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535,
 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535,
 65535, 65535,

/* mask : 7 */
 0,     0,     0,
 0,     0,     0,
 0, 32767, 32767,

/* Function parameters : 8 */
/* use_for_cycle_estimate, width, shift, in_size, out_size */
1, 28, 16, 86, 28,

/* Image data : 8 */
 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 
 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 
 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 
 65535, 65535,

/* mask : 8 */
 0,      0,      0,
 0,      0,      0,
 0, -32768, -32768,
};

int testcases = 8;

