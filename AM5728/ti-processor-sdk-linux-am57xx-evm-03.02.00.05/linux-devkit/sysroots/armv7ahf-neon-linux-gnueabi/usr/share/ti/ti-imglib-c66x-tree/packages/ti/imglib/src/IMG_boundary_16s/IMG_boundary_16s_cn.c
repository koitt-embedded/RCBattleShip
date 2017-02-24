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
/*      IMG_boundary_16s_cn                                                 */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C callable, and is called as follows:               */
/*                                                                          */
/*          void IMG_boundary_16s_cn                                        */
/*          (                                                               */
/*              const  short *restrict  i_data,                             */
/*                       int              rows,                             */
/*                       int              cols,                             */
/*              unsigned int *restrict o_coord,                             */
/*                     short *restrict  o_grey                              */
/*          );                                                              */
/*                                                                          */
/*      The arguments are defined as follows:                               */
/*                                                                          */
/*          i_data   Input images that is cols-by-rows in size.             */
/*          rows     Height of the input image                              */
/*          cols     Width of the input image                               */
/*          o_coord  Array to write output coordinates to                   */
/*          o_grey   Array to write output grey levels to                   */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      This routine scans an image looking for non-zero pixels.            */
/*      The locations of those pixels are stored out to the o_coord         */
/*      as packed Y/X pairs, with Y in the upper half, and X in             */
/*      the lower half.  The grey levels encountered are stored             */
/*      in the o_grey array in parallel.                                    */
/*                                                                          */
/*      The natural C implementation has no restrictions. The Optimized     */
/*      and IntrinsiC codes has restrictions as noted in the ASSUMPTIONS    */
/*      below.                                                              */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      1. Rows should minimum of 1 and maximum of 32767.                   */
/*      2. Cols should be a multiple of 4 ,minimum of 4 and max of 32764.   */
/*      3. Input and output arrays should not overlap.                      */
/*      4. Input must be double word aligned.                               */
/*      5. Output arrays should be word alligned.                           */
/*                                                                          */
/*  TECHNIQUES                                                              */
/*      Outer and inner loops are merged.                                   */
/*      "Inner loop" is unrolled to process four pixels per iteration.      */
/*      Packed coordinate value is updated directly, rather than            */
/*      by repacking x, y every time it's needed.                           */
/*                                                                          */
/* ======================================================================== */

#pragma CODE_SECTION(IMG_boundary_16s_cn, ".text:ansi");


void IMG_boundary_16s_cn
(
    const  short *restrict  i_data,
             int              rows,
             int              cols,
    unsigned int *restrict o_coord,
           short *restrict  o_grey
) 
{
    int   x,   y,    p;


    for ( y = 0 ; y < rows ; y++ )

        for (x = 0; x < cols ; x++)

            if (( p = *i_data++ ) != 0)
            {
                /* ----------------------------- */
                /*     store cordinates          */
                /* ----------------------------- */    
                *o_coord++ = (y  << 16) | (x );
                
                /* ----------------------------- */
                /*       store grey level        */
                /* ----------------------------- */
                *o_grey++  = p;
            }
}

/* ======================================================================== */
/*  End of file:  IMG_boundary_16s_cn.c                                      */
/* ======================================================================== */
