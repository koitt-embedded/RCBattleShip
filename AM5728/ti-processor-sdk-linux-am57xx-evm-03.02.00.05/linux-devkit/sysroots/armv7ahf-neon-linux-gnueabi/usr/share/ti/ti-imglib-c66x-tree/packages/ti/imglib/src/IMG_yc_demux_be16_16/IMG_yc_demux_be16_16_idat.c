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
/* use_for_cycle_estimate, num_luma, in_size, y_size, cb_cr_size */
1, 48, 96, 48, 24,

/* Input data : 1 */
  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 
 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32,
  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 
 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32,
  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 
 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32,

/* Function parameters : 2 */
/* use_for_cycle_estimate, num_luma, in_size, y_size, cb_cr_size */
1, 64, 128, 64, 32,

/* Input data : 2 */
 19345,  7320, 14836, 21801,  1170, 31610, 26600, 17911, 
 19162,  7714, 11307,  9815,   474,   814, 20709,   757, 
  4006, 18295, 22827,   332, 17228, 11644,  6975, 19754, 
 24686, 20663,  2542, 20703, 17595, 19254, 16437, 28675, 
 27386, 14437,  1203,  3529,  6825, 26976, 12540, 27718, 
 19099, 29783, 29628, 16253, 14720, 26024, 22616,  5395, 
  7952, 19830,   404, 13194, 16286,  2058, 17295, 16751, 
 26951, 20210,  1148,   209, 13612, 29066, 31815, 32762, 
  1382, 25958, 10649, 29393, 24419, 17556, 12490, 32070, 
 27199, 18977, 22163, 14781, 14280,  4184,  6252, 28712, 
 27595, 20211, 11131,  8072,  3545,  9897, 15348,  6721, 
  9860,  9180, 20214, 24663, 31033, 11058, 17636, 24008, 
 28759, 22573, 27436,  3627,  8959,   938,  8187,  6253, 
 11368, 25814,  7605, 15595, 30590, 24627, 21606, 24582, 
 14731, 19695, 28249, 11676, 21971,  5994, 20549, 25141, 
 32733, 28245,  2390, 28283, 18093,  5173,  8582, 18400,
};

int testcases = 2;
