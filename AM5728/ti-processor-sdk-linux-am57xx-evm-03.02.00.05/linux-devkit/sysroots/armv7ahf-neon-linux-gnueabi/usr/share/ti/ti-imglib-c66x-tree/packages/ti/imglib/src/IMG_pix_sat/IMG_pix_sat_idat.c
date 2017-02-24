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
/* use_for_cycle_estimate, dat_size (in, out) */
1, 64,

/* Input data : 1 */
   5922, -18128,  -3095,  10834, -30429,  30451,  20433,   3054, 
   5556, -17341, -10155, -13139, -31820, -31140,   8651, -31255, 
 -24757,   3822,  12885, -32103,   1688,  -9480, -18818,   6739, 
  16604,   8557, -27685,   8637,   2422,   5740,    107,  24583,
   5922, -18128,  -3095,  10834, -30429,  30451,  20433,   3054, 
   5556, -17341, -10155, -13139, -31820, -31140,   8651, -31255, 
 -24757,   3822,  12885, -32103,   1688,  -9480, -18818,   6739, 
  16604,   8557, -27685,   8637,   2422,   5740,    107,  24583,

/* Function parameters : 2 */
/* use_for_cycle_estimate, dat_size (in, out) */
1, 96,

/* Input data : 2 */
 -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, 
 -32768, -32768,     -1,     -1,     -1,     -1,     -1,     -1, 
     -1,      0,      0,      0,      0,      0,      0,      1, 
      1,      1,      1,      1,      1,    255,    255,    255, 
    255,    255,    255,    255,    255,    256,    256,    256, 
  32767,  32767,  32767,  32767,  32767,  32767,  32767,  32767, 
  32767,  32767,  32767,  32767,  32767,  32767,  32767,  32767, 
  32767,  32767,  32767,  32767,  32767,  32767,  32767 , 32767,
  32767,  32767,  32767,  32767,  32767,  32767,  32767,  32767, 
  32767,  32767,  32767,  32767,  32767,  32767,  32767 , 32767,
  32767,  32767,  32767,  32767,  32767,  32767,  32767,  32767, 
  32767,  32767,  32767,  32767,  32767,  32767,  32767 , 32767,

/* Function parameters : 3 */
/* use_for_cycle_estimate, dat_size (in, out) */
1, 128,

/* Input data : 3 */
  344,  -61, -474, -402, -299,  331, -120,  354, 
   85,  419,  414,   -4,  -52,  301,  195, -343, 
 -264,  108, -499, -100,   -3, -448,   28,   11, 
  330,  120, -476, -505,  -87,  396,  482,  512, 
 -469,  299, -179,  407,  251,   37, -122,  490, 
  338,   81,  181,  -50,  -66, -381, -317,  385, 
  350,  120, -164, -260, -401, -203,  -32, -302, 
 -204, -225,  120,  259,  458, -166,   39,  238,
  344,  -61, -474, -402, -299,  331, -120,  354, 
   85,  419,  414,   -4,  -52,  301,  195, -343, 
 -264,  108, -499, -100,   -3, -448,   28,   11, 
  330,  120, -476, -505,  -87,  396,  482,  512, 
 -469,  299, -179,  407,  251,   37, -122,  490, 
  338,   81,  181,  -50,  -66, -381, -317,  385, 
  350,  120, -164, -260, -401, -203,  -32, -302, 
 -204, -225,  120,  259,  458, -166,   39,  238,
};

int testcases = 3;
