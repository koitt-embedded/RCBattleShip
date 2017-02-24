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
 * ====================================================================== = */

#ifndef IMG_YC_DEMUX_LE16_8_CN_H_
#define IMG_YC_DEMUX_LE16_8_CN_H_ 1

/* ======================================================================== */
/*  NAME                                                                    */
/*      IMG_yc_demux_le16_8_cn -- De-interleave a 4:2:2 LITTLE ENDIAN video */
/*                 stream into three separate LITTLE ENDIAN 16-bit planes   */
/*                                                                          */
/*  USAGE                                                                   */
/*      This function is C callable, and is called as follows:              */
/*                                                                          */
/*      void IMG_yc_demux_le16_8_cn                                         */
/*      (                                                                   */
/*          int n,                       // Number of luma pixels    //     */
/*          const unsigned char * yc,    // Interleaved luma/chroma  //     */
/*          short *restrict y,           // Luma plane (16-bit)      //     */
/*          short *restrict cr,          // Cr chroma plane (16-bit) //     */
/*          short *restrict cb           // Cb chroma plane (16-bit) //     */
/*      );                                                                  */
/*                                                                          */
/*      The input array 'yc' is expected to be an interleaved 4:2:2         */
/*      video stream.  The input is expected in LITTLE ENDIAN byte          */
/*      order within each 4-byte word.  This is consistent with reading     */
/*      the video stream from a word-oriented LITTLE ENDIAN device          */
/*      while the C6000 device is in a LITTLE ENDIAN configuration.         */
/*                                                                          */
/*      In other words, the expected pixel order is:                        */
/*                                                                          */
/*                  Word 0           Word 1          Word 2                 */
/*             +---------------+---------------+---------------+--          */
/*       Byte# | 0   1   2   3 | 4   5   6   7 | 8   9  10  11 |...         */
/*             | y0 cr0 y1 cb0 | y2 cr2 y3 cb2 | y4 cr4 y5 cb4 |...         */
/*             +---------------+---------------+---------------+--          */
/*                                                                          */
/*      The output arrays 'y', 'cr', and 'cb' are expected to not           */
/*      overlap.  The de-interleaved pixels are written as half-words       */
/*      in LITTLE ENDIAN order.                                             */
/*                                                                          */
/*      Please see the IMGLIB function IMG_yc_demux_be16 for code which     */
/*      handles input coming from a BIG ENDIAN device.                      */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      This function reads the byte-oriented pixel data, zero-extends      */
/*      it, and then writes it to the appropriate result array.  Both       */
/*      the luma and chroma values are expected to be unsigned.             */
/*                                                                          */
/*      The data is expected to be in an order consistent with reading      */
/*      byte oriented data from a word-oriented peripheral that is          */
/*      operating in LITTLE ENDIAN mode, while the CPU is in LITTLE         */
/*      ENDIAN mode.  This function unpacks the byte-oriented data          */
/*      so that further processing may proceed in LITTLE ENDIAN mode.       */
/*                                                                          */
/* ======================================================================== */

void IMG_yc_demux_le16_8_cn
(
    int n,                    /* Number of luma pixels    */
    const unsigned char *yc,  /* Interleaved luma/chroma  */
    short *restrict y,        /* Luma plane (16-bit)      */
    short *restrict cr,       /* Cr chroma plane (16-bit) */
    short *restrict cb        /* Cb chroma plane (16-bit) */
);

#endif

/* ======================================================================== */
/*  End of file:  IMG_yc_demux_le16_8_cn.h                                  */
/* ======================================================================== */
