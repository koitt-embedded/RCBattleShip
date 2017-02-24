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
/*      IMG_perimeter_8                                                     */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C-callable and can be called as:                    */
/*                                                                          */
/*          int IMG_perimeter_8                                             */
/*          (                                                               */
/*              const unsigned char *restrict in,  // Input image    //     */
/*              int cols,                          // Width of input //     */
/*              unsigned char       *restrict out  // Output image   //     */
/*          );                                                              */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      This routine produces the boundary of a binary image.  It           */
/*      echoes the boundary pixels with a value of 0xFF and sets the        */
/*      other pisels as 0.  Detection of the boundary of a binary image     */
/*      is a segmentation problem and is done by examining spatial          */
/*      locality of the neighboring pixels.  This is done by using the      */
/*      four connectivity algorithm                                         */
/*                                                                          */
/*                                                                          */
/*                      pix_up                                              */
/*             pix_lft pix_cent pix_rgt                                     */
/*                      pix_dn                                              */
/*                                                                          */
/*      The output pixel at location pix_cent is echoed as a boundary       */
/*      pixel if pix_cent is non-zero and any one of its four               */
/*      neighbors is zero.  The four neighbors are shown and stand          */
/*      for the following:                                                  */
/*                                                                          */
/*            pix_up:  top pixel                                            */
/*            pix_lft: left pixel                                           */
/*            pix_rgt: right pixel                                          */
/*            pix_dn:  bottom pixel                                         */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      The input must be a multiple of 16 pixels across, and be            */
/*      on a double-word boundary.                                          */
/*                                                                          */
/*  MEMORY NOTE                                                             */
/*      No bank conflicts are expected for this kernel.                     */
/*                                                                          */
/*  TECHNIQUES                                                              */
/*      The loop is unrolled 16 times.  Split-compares are used to          */
/*      find boundary pixels, with comparison results reused between        */
/*      adjacent comparisons.  Also, multiplies replace some of the         */
/*      conditional operations to reduce the bottleneck on the              */
/*      predication registers as well as on the L, S, and D units.          */
/*                                                                          */
/* ======================================================================== */

#pragma CODE_SECTION(IMG_perimeter_8,   ".text:optimized");


int IMG_perimeter_8
(
    const unsigned char *restrict in,  /* Input image    */
    int                         cols,  /* Width of input */
    unsigned char       *restrict out  /* Output image   */
)
{

    int      i;
    double   top_dword0,       bot_dword0,      mid_dword0;
    double   top_dword1,       bot_dword1,      mid_dword1;

    unsigned char mid_lft0,    mid_lft1;
    unsigned int  top_word0,   mid_word0;
    unsigned int  top_word1,   mid_word1,       bot_word1;
    unsigned int  top_word2,   mid_word2,       midval_k1;

    unsigned int  top_word3,   mid_word3,       bot_word3;
    unsigned int  bot_word0,   midval00,        midval01;
    unsigned int  bot_word2,   midval02,        midval03;

    unsigned int  midval_w0,   upval00,         upval01;
    unsigned int  midval_w1,   upval02,         upval03;
    unsigned int  upval_w0,    botval00,        botval01;

    unsigned int  upval_w1,    botval02,        botval03;
    unsigned int  botval_w0,   mid_rt_tmp0,     mid_lf_tmp0;
    unsigned int  botval_w1,   mid_rt_tmp1,     mid_lf_tmp1;

    unsigned int  mid_right0,  mid_right_val0,  mid_left_val0;
    unsigned int  mid_right1,  mid_right_val1,  mid_left_val1;
    unsigned int  updnval0,    rgtlft0,         udrl0;
    unsigned int  updnval1,    rgtlft1,         udrl1;

    unsigned int  udrlm0,      count,           sum;
    unsigned int  udrlm1;
    unsigned int  pixel0,      pixel1,          udrlm_s;
    unsigned int  pixel2,      pixel3,          udrlm_r;

    unsigned int  bot_zero, mid_zero, top_zero;
    unsigned int  midval_k0;

    bot_zero = mid_zero = top_zero = 0;
 

    mid_lft0     = 0;
    sum          = 0;

    _nassert((int)in   % 8 == 0);
    _nassert((int)out  % 8 == 0);
    _nassert((int)cols % 16 == 0);

    /*------------------------------------------------------------------*/
    /* load double words for top, mid and bottom and extract high and   */
    /* lowhalves.  Use cmpeq4 and cmpgtu4 to issue split compares.      */
    /* Prepare 8 bits of this compare result to set up a 8 bit mask     */
    /* Perform logicals as described in Techniques and use bitc4 and    */  
    /* expand4 instructions to create pixelmap and count boundary pix.  */
    /* And with original midword to get back middle pixels.             */
    /* Store as double word. This loop processes 16 ouput pixels at     */
    /* a time and examines 50 inout pixels to do so.                    */
    /*------------------------------------------------------------------*/
    for (i = 0; i < cols; i += 16) {
        top_dword0      = _amemd8_const(&in[i - cols]);
        mid_dword0      = _amemd8_const(&in[i       ]);
        bot_dword0      = _amemd8_const(&in[i + cols]);

        top_dword1      = _amemd8_const(&in[i - cols + 8]);
        mid_dword1      = _amemd8_const(&in[i        + 8]);
        bot_dword1      = _amemd8_const(&in[i + cols + 8]);
 
        top_word0       = _lo(top_dword0);
        top_word1       = _hi(top_dword0);
        mid_word0       = _lo(mid_dword0);
        mid_word1       = _hi(mid_dword0);
        bot_word0       = _lo(bot_dword0);
        bot_word1       = _hi(bot_dword0);
        top_word2       = _lo(top_dword1);
        top_word3       = _hi(top_dword1);
        mid_word2       = _lo(mid_dword1);
        mid_word3       = _hi(mid_dword1);
        bot_word2       = _lo(bot_dword1);
        bot_word3       = _hi(bot_dword1);

        midval00        = _cmpgtu4(mid_word0, mid_zero);    
        midval01        = _cmpgtu4(mid_word1, mid_zero);    
        midval02        = _cmpgtu4(mid_word2, mid_zero);    
        midval03        = _cmpgtu4(mid_word3, mid_zero);    
        midval_w0       = midval00 - _mpy(midval01, -16);
        midval_w1       = midval02 - _mpy(midval03, -16); 

        upval00         = _cmpeq4(top_word0, top_zero);     
        upval01         = _cmpeq4(top_word1, top_zero);     
        upval02         = _cmpeq4(top_word2, top_zero);     
        upval03         = _cmpeq4(top_word3, top_zero);     
        upval_w0        = upval00 - _mpy(upval01, -16);    
        upval_w1        = upval02 - _mpy(upval03, -16);    

        botval00        = _cmpeq4(bot_word0, bot_zero);
        botval01        = _cmpeq4(bot_word1, bot_zero);
        botval02        = _cmpeq4(bot_word2, bot_zero);
        botval03        = _cmpeq4(bot_word3, bot_zero);
        botval_w0       = botval00 - _mpy(botval01, -16);  
        botval_w1       = botval02 - _mpy(botval03, -16);  

        midval_k0       = 0xFF & ~midval_w0;
        midval_k1       = 0xFF & ~midval_w1;

        mid_rt_tmp0     = _sshvr(midval_k0, 1);
        mid_rt_tmp1     = _sshvr(midval_k1, 1);

        mid_lf_tmp0     = _mpy(midval_k0, 2) & 0xFF;  
        mid_lf_tmp1     = _mpy(midval_k1, 2) & 0xFF;  

        mid_right0      = mid_word2 & 0xFF;  
        mid_lft1        = mid_word1 >> 24;   
        mid_right1      = in[i + 16];

        mid_right_val0  = mid_rt_tmp0 ;
        mid_left_val0   = mid_lf_tmp0 ; 
        mid_right_val1  = mid_rt_tmp1 ; 
        mid_left_val1   = mid_lf_tmp1 ; 

        if (!mid_right0)   mid_right_val0 += 0x80; 
        if (!mid_lft0)     mid_left_val0  += 1; 
        if (!mid_right1)   mid_right_val1 += 0x80; 
        if (!mid_lft1)     mid_left_val1  += 1; 

        updnval0      = (upval_w0       | botval_w0    );
        rgtlft0       = (mid_right_val0 | mid_left_val0);
        udrl0         = (rgtlft0        | updnval0     );
        udrlm0        = (udrl0 & midval_w0);

        updnval1      = (upval_w1       | botval_w1    );
        rgtlft1       = (mid_right_val1 | mid_left_val1);
        udrl1         = (rgtlft1        | updnval1     );
        udrlm1        = (udrl1 & midval_w1);

        mid_lft0      = mid_word3 >> 24;  

        count         = _bitc4(udrlm0) + _bitc4(udrlm1);
        sum          += count;

        pixel0        = _xpnd4(udrlm0) & mid_word0;
        udrlm_s       = _sshvr(udrlm0,4);
        pixel1        = _xpnd4(udrlm_s) & mid_word1;

        pixel2        = _xpnd4(udrlm1) & mid_word2;
        udrlm_r       = _sshvr(udrlm1,4);
        pixel3        = _xpnd4(udrlm_r) & mid_word3;

        _amem4(&out[i +  0]) = pixel0;
        _amem4(&out[i +  4]) = pixel1;
        _amem4(&out[i +  8]) = pixel2;
        _amem4(&out[i + 12]) = pixel3;
    }

    if (out[0])       sum--;
    if (udrlm_r >> 3) sum--;

    out[0] = 0;
    out[cols - 1] = 0;
    return sum;
}

/* ======================================================================== */
/*  End of file:  IMG_perimeter_8.c                                         */
/* ======================================================================== */
