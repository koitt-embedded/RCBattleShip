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
/*      IMG_thr_le2min_16_cn                                                */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine has the following C prototype:                         */
/*                                                                          */
/*      void IMG_thr_le2min_16_cn                                           */
/*      (                                                                   */
/*          const unsigned short *in_data,     //  Input image data         */
/*          unsigned short *restrict out_data, //  Output image data        */
/*          short cols, short rows,            //  Image dimensions         */
/*          unsigned short       threshold     //  Threshold value          */
/*      )                                                                   */
/*                                                                          */
/*      This routine performs a thresholding operation on an input          */
/*      image in in_data[] whose dimensions are given in the arguments      */
/*      'cols' and 'rows'.  The thresholded pixels are written to the       */
/*      output image pointed to by out_data[].  The input and output        */
/*      are exactly the same dimensions.                                    */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      Pixels that are above the threshold value are written to the        */
/*      output unmodified.  Pixels that are less than or equal to the       */
/*      threshold are set to 0 in the output image.                         */
/*                                                                          */
/*      The exact thresholding function performed is described by           */
/*      the following transfer function diagram:                            */
/*                                                                          */
/*                                                                          */
/*               65535_|                                                    */
/*                     |                  /                                 */
/*                     |                /                                   */
/*            O        |              /                                     */
/*            U        |            /                                       */
/*            T    th _|. . . . . /                                         */
/*            P        |         |                                          */
/*            U        |         |                                          */
/*            T        |         |                                          */
/*                     |         |                                          */
/*                   0_|_________|__________                                */
/*                     |         |        |                                 */
/*                     0        th     65535                                */
/*                                                                          */
/*                             INPUT                                        */
/*                                                                          */
/*      See the IMGLIB functions IMG_thr_gt2thr_16, IMG_thr_le2thr_16       */
/*      and IMG_thr_gt2max_16 for other thresholding operations.            */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      - The input and output buffers do not alias.                        */
/*      - The input and output buffers must be double-word aligned.         */
/*      - The total number of pixels rows*cols must be at least             */
/*        16 and a multiple of 16.                                          */
/*                                                                          */
/*  TECHNIQUES                                                              */
/*      - The loop is unrolled 16x. Packed-data processing techniques       */
/*        allow us to process all 16 pixels in parallel.                    */
/*                                                                          */
/*      - Four LDDW instructions load in 16 pixels.                         */
/*      - The 16 results are then written with four STDWs.                  */
/*                                                                          */
/*  MEMORY NOTE                                                             */
/*      - This code is ENDIAN NEUTRAL.                                      */
/*      - No bank conflicts occur, regardless of the relative alignment of  */
/*        in_data[] and out_data[].                                         */
/*                                                                          */
/* ======================================================================== */

void IMG_thr_le2min_16_cn
(
    const unsigned short *restrict in_data,      /*  Input image data    */
          unsigned short *restrict out_data,     /*  Output image data   */
                   short           cols,         /*  Image columns       */ 
                   short           rows,         /*  Image rows          */
          unsigned short           threshold     /*  Threshold value     */
);

/*=========================================================================== */
/*   End of file:  IMG_thr_le2min_16_cn.h                                     */
/* ========================================================================== */
