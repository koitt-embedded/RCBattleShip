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

/* =======================================================================  */
/*  NAME                                                                    */
/*      IMG_mad_16x16_cn                                                    */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C-callable and can be called as:                    */
/*                                                                          */
/*      void IMG_mad_16x16_cn                                               */
/*      (                                                                   */
/*          const unsigned char *restrict refImg,                           */
/*          const unsigned char *restrict srcImg,                           */
/*          int pitch,                                                      */
/*          int                 h,                                          */
/*          int                 v,                                          */
/*          unsigned            *restrict match                             */
/*      )                                                                   */
/*                                                                          */
/*      refImg          Reference image.                                    */
/*      srcImg[256]     16x16 block image to look for.                      */
/*      pitch           Width of reference image.                           */
/*      h               Horiz. size of search area.                         */
/*      v               Vert.  size of search area. Must be multiple of 2.  */
/*      match[2]        Result:                                             */
/*                          match[0] is packed x, y.                        */
/*                          match[1] is MAD value.                          */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      This routine returns the location of the minimum absolute           */
/*      difference between a 16x16 search block and some block in a         */
/*      (h + 16) x (v + 16) search area. h and v are the sizes of the       */
/*      search space for the top left coordinate of the search block.       */
/*      refImg points to the top left pixel of the search area.             */
/*                                                                          */
/*           (0,0)          (h,0)      (h+16,0)                             */
/*             ;--------------+--------;                                    */
/*             ;    search    |        ;                                    */
/*             ;    space     |        ;                                    */
/*             ;              |        ;        search area                 */
/*             ;--------------+        ;        within reference image      */
/*           (0,v)          (h,v)      ;                                    */
/*             ;                       ;                                    */
/*             ;-----------------------;                                    */
/*           (0, v+16)                 (v+16,h+16)                          */
/*                                                                          */
/*      The location is returned relative to the above coordinate system    */
/*      as x and y packed in two 16-bit quantities in a 32-bit word:        */
/*                                                                          */
/*                  31             16 15             0                      */
/*                  +----------------+----------------+                     */
/*       match[0]:  |       x        |       y        |                     */
/*                  +----------------+----------------+                     */
/*                                                                          */
/*                  31                               0                      */
/*                  +---------------------------------+                     */
/*       match[1]:  |   SAD value at location x, y    |                     */
/*                  +---------------------------------+                     */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      srcImg and refImg do not alias in memory.                           */
/*      The routine is written for Little Endian configuration.             */
/*                                                                          */
/*  MEMORY NOTE                                                             */
/*      None.                                                               */
/*                                                                          */
/* =======================================================================  */

#pragma CODE_SECTION(IMG_mad_16x16_cn, ".text:ansi");


void IMG_mad_16x16_cn
(
    const unsigned char *restrict refImg,
    const unsigned char *restrict srcImg,
    int pitch, 
    int h, 
    int v,
    unsigned int *restrict match
)
{
    int i, j, x, y, matx, maty;
    unsigned matpos, matval;

    matval = ~0U;
    matx   = maty = 0;

#ifndef NOASSUME
    _nassert((int)srcImg % 4 == 0);
    _nassert(pitch > 16);
    _nassert(h    >= 4);
    _nassert(v    >= 4);
    _nassert(h    <= 32767);
    _nassert(v    <= 32767);
    _nassert(v % 2 == 0);
#endif
    for (x = 0; x < h; x++)
        for (y = 0; y < v; y++)
        {
            unsigned acc = 0;

            for (i = 0; i < 16; i++)
                for (j = 0; j < 16; j++)
                    acc += abs(srcImg[i*16 + j] - refImg[(i+y)*pitch + x + j]);

            if (acc < matval)
            {
                matval = acc;
                matx   = x;
                maty   = y;
            }
        }

    matpos    = (0xffff0000 & (matx << 16)) | (0x0000ffff & maty);
    match[0] = matpos;
    match[1] = matval;
}

/* ======================================================================= */
/*  End of file:  IMG_mad_16x16_cn.c                                       */
/* ======================================================================= */
