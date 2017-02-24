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

/* ######################################################################## */
/* #  TI Disclaimer: This kernel is obsolete. It is provided here for     # */
/* #  backward compatibility.                                             # */
/* ######################################################################## */

/* ======================================================================== */
/*  NAME                                                                    */
/*      IMG_fdct_8x8 -- 8x8 Block FDCT With Rounding, Endian Neutral.       */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine has the following C prototype:                         */
/*                                                                          */
/*          void IMG_fdct_8x8(short fdct_data[], unsigned num_fdcts)        */
/*                                                                          */
/*      The fdct routine accepts a list of 8x8 pixel blocks and performs    */
/*      FDCTs on each.  The array should be laid out identically to         */
/*      "fdct_data[num_fdcts][8][8]".  All operations in this array are     */
/*      performed entirely in-place.                                        */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      The fdct_8x8 function implements a Chen FDCT.  Output values are    */
/*      rounded, providing improved accuracy.  Input terms are expected     */
/*      to be signed 12Q0 values, producing signed 16Q0 results.  (A        */
/*      smaller dynamic range may be used on the input, producing a         */
/*      correspondingly smaller output range.  Typical applications         */
/*      include processing signed 9Q0 and unsigned 8Q0 pixel data,          */
/*      producing signed 13Q0 or 12Q0 outputs, respectively.)               */
/*                                                                          */
/*      Note:  This code guarantees correct operation, even in the case     */
/*      that 'num_fdcts == 0'.  In this case, the function performs an      */
/*      early exit without storing any results or intermediate values.      */
/*                                                                          */
/*  TECHNIQUES                                                              */
/*      I've applied a sqrt(2) scaling to each pass, which results in a     */
/*      fractional Q point at various points of the algorithm.  A chief     */
/*      benefit of this technique is that the F0 and F4 terms see no        */
/*      multiplies.  To perform this scaling, the C2 and C6 cosine terms    */
/*      are scaled up by sqrt(2), and the intermediate values in stage 2    */
/*      (s0, q0, s1, and q1) are also multiplied by sqrt(2).  The           */
/*      effect in stage 2 is to cancel the multiply by C4 on s0 and q0,     */
/*      and to introduce a multiply by 2*C4 on s1 and q1.                   */
/*                                                                          */
/*      The horizontal pass does not explicitly jump from block-to-block,   */
/*      since all horizontal rows are adjacent in memory.  (eg. Moving      */
/*      between rows within a block is identical to moving between the      */
/*      last row of one block and the first row of the next block.)         */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      n/a                                                                 */
/*                                                                          */
/*  NOTES                                                                   */
/*      n/a                                                                 */
/*                                                                          */
/*  SOURCE                                                                  */
/*      Chen FDCT.                                                          */
/* ======================================================================== */

#pragma CODE_SECTION(IMG_fdct_8x8_cn,   ".text:ansi");


void IMG_fdct_8x8_cn
(
    short    *dct_data,   /* Pointer to 8x8 DCT blocks "dct_data[num_fdcts][8][8]" */
    unsigned  num_fdcts   /* Number of DCT blocks */
)
{
    /* -------------------------------------------------------------------- */
    /*  Set up the cosine coefficients.                                     */
    /* -------------------------------------------------------------------- */
    const unsigned short c1 = 0x1F62, c3 = 0x1A9B;      /* Q13   coeffs     */
    const unsigned short c5 = 0x11C7, c7 = 0x063E;      /* Q13   coeffs     */
    const unsigned short c2 = 0x29CF, c6 = 0x1151;      /* Q13.5 coeffs     */
    const unsigned short C1 = 0xFB15, C3 = 0xD4DB;      /* Q16   coeffs     */
    const unsigned short C5 = 0x8E3A, C7 = 0x31F1;      /* Q16   coeffs     */
    const unsigned short C2 = 0xA73D, C6 = 0x4546;      /* Q15.5 coeffs     */
    const unsigned short C4 = 0xB505;                   /* Q16   coeff      */

    /* -------------------------------------------------------------------- */
    /*  Intermediate calculations.                                          */
    /* -------------------------------------------------------------------- */
    short f0, f1, f2, f3, f4, f5, f6, f7;   /* Spatial domain samples.      */
    short g0, g1, h0, h1, p0, p1;           /* Even-half intermediate.      */
    short r0, r1, r0_,r1_;                  /* Even-half intermediate.      */
    short P0, P1, R0, R1;                   /* Even-half intermediate.      */
    short g2, g3, h2, h3;                   /* Odd-half intermediate.       */
    short q1a,s1a,q0, q1, s0, s1;           /* Odd-half intermediate.       */
    short Q0, Q1, S0, S1;                   /* Odd-half intermediate.       */
    short F0, F1, F2, F3, F4, F5, F6, F7;   /* Freq. domain results.        */

    /* -------------------------------------------------------------------- */
    /*  Input and output pointers, loop control.                            */
    /* -------------------------------------------------------------------- */
    unsigned i, j;
    short (*dct)[8][8] = (short (*)[8][8])dct_data;

    if (!num_fdcts) return;

#ifndef NOASSUME
    _nassert((int) dct % 8 == 0);
    _nassert(num_fdcts     >= 1);
#endif

    /* -------------------------------------------------------------------- */
    /*  Outer vertical loop -- Process each 8x8 block.                      */
    /* -------------------------------------------------------------------- */
    for (i=0; i<num_fdcts; i++) {
        /* ---------------------------------------------------------------- */
        /*  Perform Vertical 1-D FDCT on columns within each block.         */
        /* ---------------------------------------------------------------- */
        for (j=0; j<8; j++) {
            /* ------------------------------------------------------------ */
            /*  Load the spatial-domain samples.                            */
            /*  The incoming terms start at Q0 precision.                   */
            /* ------------------------------------------------------------ */
            f0 = dct[i][0][j];
            f1 = dct[i][1][j];
            f2 = dct[i][2][j];
            f3 = dct[i][3][j];
            f4 = dct[i][4][j];
            f5 = dct[i][5][j];
            f6 = dct[i][6][j];
            f7 = dct[i][7][j];

            /* ------------------------------------------------------------ */
            /*  Stage 1:  Separate into even and odd halves.                */
            /*                                                              */
            /*  The results of this stage are implicitly in Q1, since we    */
            /*  do not explicitly multiply by 0.5.                          */
            /* ------------------------------------------------------------ */
            g0 = f0 + f7;               g1 = f1 + f6;   /* Results in Q1    */
            h1 = f2 + f5;               h0 = f3 + f4;   /* Results in Q1    */
            g3 = f2 - f5;               g2 = f3 - f4;   /* Results in Q1    */
            h2 = f0 - f7;               h3 = f1 - f6;   /* Results in Q1    */

            /* ------------------------------------------------------------ */
            /*  Stage 2                                                     */
            /*                                                              */
            /*  Note, on the odd-half, the results are in Q1.5 since those  */
            /*  values are scaled upwards by sqrt(2) at this point.         */
            /* ------------------------------------------------------------ */
            p0 = g0 + h0;               r0 = g0 - h0;   /* Results in Q1    */
            p1 = g1 + h1;               r1 = g1 - h1;   /* Results in Q1    */

            q1a = g2 + g2;                              /* q1a is now Q2    */
            s1a = h2 + h2;                              /* s1a is now Q2    */
            q1  = (q1a * C4 + 0x8000) >> 16;            /* Results in Q1.5  */
            s1  = (s1a * C4 + 0x8000) >> 16;            /* Results in Q1.5  */

            s0 = h3 + g3;                               /* Results in Q1.5  */
            q0 = h3 - g3;                               /* Results in Q1.5  */

            /* ------------------------------------------------------------ */
            /*  Stage 3                                                     */
            /*                                                              */
            /*  Now, the even-half ends up in Q1.5.  On P0 and P1, this     */
            /*  happens because the multiply-by-C4 was canceled with an     */
            /*  upward scaling by sqrt(2).  On R0 and R1, this happens      */
            /*  because C2 and C6 are at Q15.5, and we scale r0 and r1 to   */
            /*  Q2 before we multiply.                                      */
            /* ------------------------------------------------------------ */
            P0 = p0 + p1;                               /* Results in Q1.5  */
            P1 = p0 - p1;                               /* Results in Q1.5  */

            r0_= r0 + r0;                               /* r0_ is now Q2    */
            r1_= r1 + r1;                               /* r1_ is now Q2    */
            R1 = (C6 * r1_+ C2 * r0_+ 0x8000) >> 16;    /* Results in Q1.5  */
            R0 = (C6 * r0_- C2 * r1_+ 0x8000) >> 16;    /* Results in Q1.5  */

            Q1 = q1 + q0;               Q0 = q1 - q0;
            S1 = s1 + s0;               S0 = s1 - s0;

            /* ------------------------------------------------------------ */
            /*  Stage 4                                                     */
            /*  No further changes in Q-point happen here.                  */
            /* ------------------------------------------------------------ */
            F0 = P0;                    F4 = P1;
            F2 = R1;                    F6 = R0;

            F1 = (C7 * Q1 + C1 * S1 + 0x8000) >> 16;    /* Results in Q1.5  */
            F7 = (C7 * S1 - C1 * Q1 + 0x8000) >> 16;    /* Results in Q1.5  */
            F5 = (C3 * Q0 + C5 * S0 + 0x8000) >> 16;    /* Results in Q1.5  */
            F3 = (C3 * S0 - C5 * Q0 + 0x8000) >> 16;    /* Results in Q1.5  */

            /* ------------------------------------------------------------ */
            /*  Store the frequency domain results.                         */
            /*  These values are all at Q1.5 precision.                     */
            /* ------------------------------------------------------------ */
            dct[i][0][j] = F0;
            dct[i][1][j] = F1;
            dct[i][2][j] = F2;
            dct[i][3][j] = F3;
            dct[i][4][j] = F4;
            dct[i][5][j] = F5;
            dct[i][6][j] = F6;
            dct[i][7][j] = F7;
        }
    }

    /* -------------------------------------------------------------------- */
    /*  Perform Horizontal 1-D FDCT on each 8x8 block.                      */
    /* -------------------------------------------------------------------- */
    for (i=0; i<num_fdcts; i++) {
        /* ---------------------------------------------------------------- */
        /*  Perform Vertical 1-D FDCT on columns within each block.         */
        /* ---------------------------------------------------------------- */
        for (j=0; j<8; j++) {
            /* ------------------------------------------------------------ */
            /*  Load the spatial-domain samples.                            */
            /*  The incoming terms are at Q1.5 precision from first pass.   */
            /* ------------------------------------------------------------ */
            f0 = dct[i][j][0];
            f1 = dct[i][j][1];
            f2 = dct[i][j][2];
            f3 = dct[i][j][3];
            f4 = dct[i][j][4];
            f5 = dct[i][j][5];
            f6 = dct[i][j][6];
            f7 = dct[i][j][7];

            /* ------------------------------------------------------------ */
            /*  Stage 1:  Separate into even and odd halves.                */
            /*                                                              */
            /*  The results of this stage are implicitly in Q2.5, since we  */
            /*  do not explicitly multiply by 0.5.                          */
            /* ------------------------------------------------------------ */
            g0 = f0 + f7;               g1 = f1 + f6;   /* Results in Q2.5  */
            h1 = f2 + f5;               h0 = f3 + f4;   /* Results in Q2.5  */
            h2 = f0 - f7;               h3 = f1 - f6;   /* Results in Q2.5  */
            g3 = f2 - f5;               g2 = f3 - f4;   /* Results in Q2.5  */

            /* ------------------------------------------------------------ */
            /*  Stage 2                                                     */
            /*                                                              */
            /*  Note, on the odd-half, the results are in Q3 since those    */
            /*  values are scaled upwards by sqrt(2) at this point.  The    */
            /*  order of operations differs in this pass as compared to     */
            /*  the first due to overflow concerns.                         */
            /*                                                              */
            /*  We also inject a rounding term into the DC term which will  */
            /*  also round the Nyquist term, F4.  This trick works despite  */
            /*  the fact that we are technically still at Q2.5 here, since  */
            /*  the step from Q2.5 to Q3 later is done implicitly, rather   */
            /*  than with a multiply.  (This is due to the sqrt(2) terms    */
            /*  cancelling on the P0/P1 butterfly.)                         */
            /* ------------------------------------------------------------ */
            p0 = g0 + h0 + 4;           p1 = g1 + h1;   /* Results in Q2.5  */
            r0 = g0 - h0;               r1 = g1 - h1;   /* Results in Q2.5  */

            q1a= (g2 * C4 + 0x8000) >> 16;              /* q1a now in Q2    */
            s1a= (h2 * C4 + 0x8000) >> 16;              /* s1a now in Q2    */
            q1 = q1a + q1a;                             /* Results in Q3    */
            s1 = s1a + s1a;                             /* Results in Q3    */

            s0 = h3 + g3;                               /* Results in Q3    */
            q0 = h3 - g3;                               /* Results in Q3    */

            /* ------------------------------------------------------------ */
            /*  Stage 3                                                     */
            /*                                                              */
            /*  Now, the even-half ends up in Q0.  This happens on P0 and   */
            /*  P1 because the multiply-by-c4 was canceled with an upward   */
            /*  scaling by sqrt(2), yielding Q3 intermediate value.  The    */
            /*  final >> 3 leaves these at Q0.  On R0 and R1, this happens  */
            /*  because c2 and c6 are at Q13.5, giving a Q16 intermediate   */
            /*  value.  The final >> 16 then leaves those values at Q0.     */
            /* ------------------------------------------------------------ */
            P0 = ((short)(p0 + p1)) >> 3;               /* Results in Q0    */
            P1 = ((short)(p0 - p1)) >> 3;               /* Results in Q0    */
            R1 = (c6 * r1 + c2 * r0 + 0x8000) >> 16;    /* Results in Q0    */
            R0 = (c6 * r0 - c2 * r1 + 0x8000) >> 16;    /* Results in Q0    */

            Q1 = q1 + q0;               Q0 = q1 - q0;   /* Results in Q3    */
            S1 = s1 + s0;               S0 = s1 - s0;   /* Results in Q3    */

            /* ------------------------------------------------------------ */
            /*  Stage 4                                                     */
            /*                                                              */
            /*  Next, the odd-half ends up in Q0.  This happens because     */
            /*  our values are in Q3 and our cosine terms are in Q13,       */
            /*  giving us Q16 intermediate values. The final >> 16 leaves   */
            /*  us a Q0 result.                                             */
            /* ------------------------------------------------------------ */
            F0 = P0;                    F4 = P1;
            F2 = R1;                    F6 = R0;

            F1 = (c7 * Q1 + c1 * S1 + 0x8000) >> 16;    /* Results in Q0    */
            F7 = (c7 * S1 - c1 * Q1 + 0x8000) >> 16;    /* Results in Q0    */
            F5 = (c3 * Q0 + c5 * S0 + 0x8000) >> 16;    /* Results in Q0    */
            F3 = (c3 * S0 - c5 * Q0 + 0x8000) >> 16;    /* Results in Q0    */

            /* ------------------------------------------------------------ */
            /*  Store the results                                           */
            /* ------------------------------------------------------------ */
            dct[i][j][0] = F0;
            dct[i][j][1] = F1;
            dct[i][j][2] = F2;
            dct[i][j][3] = F3;
            dct[i][j][4] = F4;
            dct[i][j][5] = F5;
            dct[i][j][6] = F6;
            dct[i][j][7] = F7;
        }
    }
    return;
}

/* ======================================================================== */
/*  End of file:  IMG_fdct_8x8_cn.c                                         */
/* ======================================================================== */
