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

/* ======================================================================== */
/*  NAME                                                                    */
/*      IMG_pix_expand                                                      */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C-callable and can be called as:                    */
/*                                                                          */
/*      void IMG_pix_expand                                                 */
/*      (                                                                   */
/*          int n,                                    // # of elements //   */
/*          const unsigned char *restrict in_data,    // Input data    //   */
/*          short               *restrict out_data    // Output data   //   */
/*      )                                                                   */
/*                                                                          */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      Reads an array of unsigned 8-bit values and store them to a         */
/*      16-bit array.  This step is often used as the first step            */
/*      when processing pixels or other low-precision data at 16-bit        */
/*      intermediate precision.                                             */
/*                                                                          */
/*                                                                          */
/*    ASSUMPTIONS                                                           */
/*       Input and output arrays must be double-word (8-byte) aligned.      */
/*                                                                          */
/*       The input must be at least 16 elements long and contain a          */
/*       multiple of 16 elements.                                           */
/*                                                                          */
/*                                                                          */
/*   TECHNIQUES                                                             */
/*       The loop is unrolled 16 times, loading bytes with LDDW.  It uses   */
/*       UNPKHU4 and UNPKLU4 to unpack the data and store the results with  */
/*       STDW.                                                              */
/*                                                                          */
/* ======================================================================== */

#pragma CODE_SECTION(IMG_pix_expand, ".text:optimized");


void IMG_pix_expand
(   
    int n,
    const unsigned char *restrict in_data,
    short               *restrict out_data
)
{   
    int i;

    _nassert((int) in_data  % 8 == 0);
    _nassert((int) out_data % 8 == 0);

    #pragma MUST_ITERATE(16,,16);
    #pragma UNROLL(16);
    for (i = 0; i < n; i++)
        out_data[i] =  in_data[i];
}

/* ======================================================================== */
/*  End of file: IMG_pix_expand.c                                           */
/* ======================================================================== */
