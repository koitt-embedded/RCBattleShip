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
/* use_for_cycle_estimate, pitch, in_size, out_size */
0, 6, 18, 4,

/* Image data : 1 */
3403, 3756, 3087,  310, 3191, 2329,
2397, 1170, 1558,  220, 3825, 1922,
2251, 3101, 2325, 2174,  532,   48,

/* mask : 1 */
3952, 3920,  581, 
 645, 1988, 1727, 
3975, 3277, 3750, 

/* Function parameters : 2 */
/* use_for_cycle_estimate, pitch, in_size, out_size */
1, 34, 102, 32,

/* Image data : 2 */
 24698,  2485, 25531, 18639, 11046, 10197, 19725, 22584,  2746,  4993, 32641,  3494, 25392,  2766, 26216,  5958,  4458, 18017, 20383, 13166,  4040, 13673, 30958, 11066,  3643,  7919,  4324, 18848, 11572,  1409, 23977, 17924,  6191, 12074, 
 12466,  1767, 30605, 15380,  5314, 17318,  8617, 24515,  7503, 27060,  2561, 31519, 26781, 13100, 14136,  8644, 28484,  4749, 11500,  2489,  6026,  1627, 16084, 29492, 25567, 13235, 30869,  1958, 26908,  5537, 21225,  9709, 22504, 20500, 
 18606, 17393,  4256,   390, 26027,  5427, 21432, 14763, 29928, 17640, 14505,   151, 28465,  8515, 29840,  4769, 18995, 27952, 16818,  7861,  7862, 29580, 16031, 12099, 12770,  3160, 31330,  7693,   504, 21270, 14775, 24402,  6013, 25566, 

/* mask : 2 */
  2658, 15951,  6038,
 20454, 14282,   662,
  5418,  4640, 10736,

/* Function parameters : 3 */
/* use_for_cycle_estimate, pitch, in_size, out_size */
1, 26, 78, 24,

/* Image data : 3 */
 26696, 29929,  9125, 31617, 31364,  4649, 25959,  1170, 22240, 12852, 23135,  1512, 22768,  1128, 25084, 16048, 23244, 22272,  3899, 11153, 24617, 22907, 17931,  8438, 26682, 11468, 
 29680, 20721, 17920,  5164, 15904, 13820, 31440, 27824, 24829, 21478,  1043,  3182, 10390, 14376, 26057, 14600, 24729, 21466, 16330, 19178,  8358, 29193,  4542, 27548,  7979,  6442, 
  4161,  3196, 31375, 31804, 26223, 30006, 21487, 30605, 24350,  5609,  9074, 26983, 31136, 12502,  6123, 21178,  9044,  5328, 31448,  7333, 16579, 31434,  4892,  8332, 30450,  8227, 

/* mask : 3 */
 3087,  310, 3191, 
 1558,  220, 3825, 
 2325, 2174,  532, 

/* Function parameters : 4 */
/* use_for_cycle_estimate, pitch, in_size, out_size */
1, 22, 66, 20,

/* Image data : 4 */
  5474, 26551, 19781,  2675,  7427, 27480,   714, 27509, 12984, 15046,  6902, 32216, 12540,  3752, 18653, 20946, 24995, 20460, 13632, 13179, 19410, 12381,
  7749,  2050,   328, 17521, 10458, 20255, 13839, 18996,  3185, 27964,  7485, 28980, 19046,  5561, 12879, 13931, 24363,  3684, 17273,  4186,  1878, 32477,
 23255, 14291, 17966,  8539, 27386, 10532, 13750, 12704,   936, 12720,   156, 23992, 28781, 29999, 21559,  6504,  5387, 31241,  7769,  7050, 21241,  6593,

/* mask : 4 */
  1716,  5658,  3341,
  5535,  7497,  6226,
  2186,  6579,  2124,
};

int testcases = 4;
