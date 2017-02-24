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
/*      IMG_thr_gt2thr_8_cn                                                 */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine has the following C prototype:                         */
/*                                                                          */
/*      void IMG_thr_gt2thr_8_cn                                            */
/*      (                                                                   */
/*          const unsigned char *in_data,     //  Input image data  //      */
/*          unsigned char *restrict out_data, //  Output image data //      */
/*          short cols, short rows,           //  Image dimensions  //      */
/*          unsigned char       threshold     //  Threshold value   //      */
/*      )                                                                   */
/*                                                                          */
/*      This routine performs a thresholding operation on an input          */
/*      image in in_data[] whose dimensions are given in the arguments      */
/*      'cols' and 'rows'.  The thresholded pixels are written to the       */
/*      output image pointed to by out_data[].  The input and output        */
/*      are exactly the same dimensions.                                    */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      Pixels that are below the threshold value are written to the        */
/*      output unmodified.  Pixels that are greater than the threshold      */
/*      are set to the threshold value in the output image.                 */
/*                                                                          */
/*      The exact thresholding function performed is described by           */
/*      the following transfer function diagram:                            */
/*                                                                          */
/*                                                                          */
/*                 255_|                                                    */
/*                     |                                                    */
/*                     |                                                    */
/*            O        |                                                    */
/*            U        |                                                    */
/*            T    th _|. . . . . _________                                 */
/*            P        |        /.                                          */
/*            U        |      /  .                                          */
/*            T        |    /    .                                          */
/*                     |  /      .                                          */
/*                   0_|/________.__________                                */
/*                     |         |        |                                 */
/*                     0        th       255                                */
/*                                                                          */
/*                             INPUT                                        */
/*                                                                          */
/*      Please see the IMGLIB functions IMG_thr_le2thr_8, IMG_thr_gt2max_8  */
/*      and IMG_thr_le2min_8 for other thresholding functions.              */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      The input and output buffers do not alias.                          */
/*                                                                          */
/*  MEMORY NOTE                                                             */
/*      This code is ENDIAN NEUTRAL.                                        */
/* ======================================================================== */

#ifndef THR_GT2THR_8_C_H_
#define THR_GT2THR_8_C_H_ 1

void IMG_thr_gt2thr_8_cn
(
    const unsigned char *in_data,                /*  Input image data    */
    unsigned char       *restrict out_data,      /*  Output image data   */
    short cols, short rows,                      /*  Image dimensions    */
    unsigned char       threshold                /*  Threshold value     */
);

#endif

/* ======================================================================== */
/*  End of file:  IMG_thr_gt2thr_8_c.h                                      */
/* ======================================================================== */
