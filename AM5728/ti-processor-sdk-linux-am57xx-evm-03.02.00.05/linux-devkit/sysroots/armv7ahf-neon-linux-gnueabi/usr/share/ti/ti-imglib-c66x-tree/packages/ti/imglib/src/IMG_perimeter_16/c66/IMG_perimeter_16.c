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
/*      IMG_perimeter_16                                                    */
/*                                                                          */
/*  USAGE                                                                   */
/*      This function is C callable, and has the following prototype:       */
/*                                                                          */
/*          int IMG_perimeter_16                                            */
/*          (                                                               */
/*              const unsigned short *restrict in,  // Input image    //    */
/*              int cols,                           // Width of input //    */
/*              unsigned short       *restrict out  // Output image   //    */
/*          );                                                              */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      This function returns the boundary pixels of an image.              */
/*      Each call of perimeter() calculates one new line of output          */
/*      from a three line window of input.                                  */
/*                                                                          */
/*      The input pointer "in" points to the middle line of a three-line    */
/*      window of the image.  The perimeter function scans this window      */
/*      looking for pixels in the middle row which are on the perimeter     */
/*      of the image.  A pixel is on the perimeter of the image if          */
/*      the pixel itself is non-zero, but one of its neighbors is zero.     */
/*      The total count of perimeter pixels is returned.                    */
/*                                                                          */
/*      This particular implementation evaluates four neighbors for         */
/*      the perimeter test:  The neighbors to the left, right, top          */
/*      and bottom.                                                         */
/*                                                                          */
/*      Perimeter pixels retain their original grey level in the            */
/*      output.  Non-perimeter pixels are set to zero in the output.        */
/*      Pixels on the far left and right edges of a row are defined         */
/*      as *not* being on the perimeter, and are always forced to           */
/*      zero.                                                               */
/*                                                                          */
/*      The natural C implementation has no restrictions. The Optimized     */
/*      and IntrinsiC codes has restrictions as noted in the ASSUMPTIONS    */
/*      below.                                                              */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      1. 'cols' should be a multiple of 8                                 */
/*      2. input and output arrays should not overlap.                      */
/*      3. input and output arrays should be double word aligned.           */
/*                                                                          */
/*  COMPATIBILITY                                                           */
/*     The code is compatible both C66x                                     */
/*                                                                          */
/* ======================================================================== */

#pragma CODE_SECTION(IMG_perimeter_16,   ".text:optimized");


int IMG_perimeter_16
(           
    const unsigned short *restrict in,      /* Input image    */
    int cols,                               /* Width of input */
    unsigned short       *restrict out      /* Output image   */
)
{

    int             i;
    double          top_dword0,         bot_dword0,      mid_dword0;
    double          top_dword1,         bot_dword1,      mid_dword1;

    unsigned int    mid_right_val0,     mid_left_val0;

    unsigned int    top_word0,          mid_word0,       udrlm_s1;
    unsigned int    top_word1,          mid_word1,       bot_word1;
    unsigned int    top_word2,          mid_word2,       midval_w10;

    unsigned int    top_word3,          mid_word3,       bot_word3;
    unsigned int    bot_word0,          midval00,        midval01;
    unsigned int    bot_word2,          midval02,        midval03;

    unsigned int    midval_w0,          upval00,         upval01;
    unsigned int    midval_w1,          upval02,         upval03;
    unsigned int    upval_w0,           botval00,        botval01;

    unsigned int    upval_w1,           botval02,        botval03;
    unsigned int    botval_w0,          mid_rt_tmp0,     mid_lf_tmp0;
    unsigned int    botval_w1,          upval_w10  ,     botval_w10 ;

    unsigned int    updnval0,           rgtlft0,         udrl0;
    unsigned int    mid_right0,         mid_left0,       udrlm_s0;

    unsigned int    udrlm0,             count,           sum;
    unsigned int    pixel0,             pixel1;
    unsigned int    pixel2,             pixel3,          udrlm_r;

    unsigned int    bot_zero,           mid_zero,        top_zero;
    

    bot_zero = 0;
    mid_zero = 0;
    top_zero = 0;
 


    sum      = 0;

    _nassert((int)in   % 8 == 0);       /*  input double word aligned       */
    _nassert((int)out  % 8 == 0);       /*  output double word aligned      */
    _nassert((int)cols % 8 == 0);       /*  columns multiple of 8           */ 

    /*----------------------------------------------------------------------*/
    /* load double words for top, mid and bottom and extract high and       */
    /* lowhalves.  Use cmpeq2  to issue split compares.                     */
    /* Prepare 4 bits of this compare result to set up a 4 bit mask         */
    /* Perform logicals  and use bitc4 and  expand2 instructions to         */  
    /*  create pixelmap and count boundary pix.                             */
    /* And with original midword to get back middle pixels.                 */
    /* Store as double word. This loop processes 8 ouput pixels at          */
    /* a time and examines 26 inout pixels to do so.                        */
    /*----------------------------------------------------------------------*/

    for ( i = 0; i < cols; i += 8)
    {

        /*------------------------------------------------------------------*/
        /* Load 8 pixels from top middle and bottom rows                    */
        /*------------------------------------------------------------------*/

        top_dword0      =  _amemd8_const(&in[i - cols]);
        mid_dword0      =  _amemd8_const(&in[i       ]);
        bot_dword0      =  _amemd8_const(&in[i + cols]);

        top_dword1      =  _amemd8_const(&in[i - cols + 4]);
        mid_dword1      =  _amemd8_const(&in[i        + 4]);
        bot_dword1      =  _amemd8_const(&in[i + cols + 4]);
 
        top_word0       =  _lo(top_dword0);
        top_word1       =  _hi(top_dword0);
        mid_word0       =  _lo(mid_dword0);
        mid_word1       =  _hi(mid_dword0);
        bot_word0       =  _lo(bot_dword0);
        bot_word1       =  _hi(bot_dword0);
        top_word2       =  _lo(top_dword1);
        top_word3       =  _hi(top_dword1);
        mid_word2       =  _lo(mid_dword1);
        mid_word3       =  _hi(mid_dword1);
        bot_word2       =  _lo(bot_dword1);
        bot_word3       =  _hi(bot_dword1);

        /*------------------------------------------------------------------*/
        /* using cmpeq2 check if the pixels in the middle row are equal to  */
        /* zero and store those results.Similarly check for any zero pixels */
        /* in the top and bottom rows.                                      */
        /*------------------------------------------------------------------*/
        midval00        =  _cmpeq2(mid_word0, mid_zero);    
        midval01        =  _cmpeq2(mid_word1, mid_zero);    
        midval02        =  _cmpeq2(mid_word2, mid_zero);    
        midval03        =  _cmpeq2(mid_word3, mid_zero);   
        midval_w0       =  	midval00 - _mpy(midval01, -4);
        midval_w1       =  midval02 - _mpy(midval03, -4); 
        midval_w10      =  (midval_w0 & 0xF) - _mpy((midval_w1 & 0xF), -16); 

        upval00         =  _cmpeq2(top_word0, top_zero);     
        upval01         =  _cmpeq2(top_word1, top_zero);     
        upval02         =  _cmpeq2(top_word2, top_zero);     
        upval03         =  _cmpeq2(top_word3, top_zero);     
        upval_w0        =  upval00 - _mpy(upval01, -4);    
        upval_w1        =  upval02 - _mpy(upval03, -4);    
        upval_w10       =  (upval_w0 & 0xf) -_mpy((upval_w1 & 0xF), -16);

        botval00        =   _cmpeq2(bot_word0, bot_zero);
        botval01        =   _cmpeq2(bot_word1, bot_zero);
        botval02        =   _cmpeq2(bot_word2, bot_zero);
        botval03        =   _cmpeq2(bot_word3, bot_zero);
        botval_w0       =   botval00 - _mpy(botval01, -4);  
        botval_w1       =   botval02 - _mpy(botval03, -4);  
        botval_w10      =   (botval_w0 & 0xF ) -_mpy((botval_w1 & 0xF), -16);
        

        mid_rt_tmp0     =   _sshvr(midval_w10, 1) & 0x7F;
        mid_lf_tmp0     =   _mpy(midval_w10, 2) & 0xFF ;  
         
        mid_right0      =   in[i + 8];

        mid_right_val0  =   mid_rt_tmp0;
        mid_left_val0   =   mid_lf_tmp0; 

        if(mid_right0 == 0)    mid_right_val0 += 0x80 ;
        if(mid_left0  == 0 )   mid_left_val0  += 0x01 ; 
       
        updnval0        =   (upval_w10      | botval_w10    );
        rgtlft0         =   (mid_right_val0 | mid_left_val0);
        udrl0           =   (rgtlft0        | updnval0     );
        udrlm0          =   (udrl0 & (~midval_w10) & 0xFF);

        mid_left0       =   (mid_word3 >> 16) & 0xffff;  

        /*------------------------------------------------------------------*/
        /* Count the number of perimeter pixels and store in sum            */
        /*------------------------------------------------------------------*/

        count           =   _bitc4(udrlm0);
        sum            +=   count;

        /*------------------------------------------------------------------*/
        /* Using xpnd2 pixels get the output pixels and store               */
        /*------------------------------------------------------------------*/

        pixel0          =   _xpnd2(udrlm0 & 0x03) & mid_word0;
        udrlm_s0        =   _sshvr(udrlm0,2);
        pixel1          =   _xpnd2(udrlm_s0 & 0x03) & mid_word1;
        udrlm_s1        =   _sshvr(udrlm0,4);
        pixel2          =   _xpnd2(udrlm_s1 & 0x03) & mid_word2;
        udrlm_r         =   _sshvr(udrlm0,6);
        pixel3          =   _xpnd2(udrlm_r & 0x03) & mid_word3;

        _amemd8( ( void * )&out[i] )     = _itod((int)pixel1, (int)pixel0);
        _amemd8( ( void * )&out[i + 4] ) = _itod((int)pixel3, (int)pixel2);
    }

    if (out[0])        sum--;
    if (udrlm_r >> 1)  sum--;
    /*----------------------------------------------------------------------*/
    /* Set the pixels on the far left and right edges of the image to zero. */
    /*----------------------------------------------------------------------*/
  
    out[0]        = 0;
    out[cols - 1] = 0;
    return sum;
}

/* ======================================================================== */
/*  End of file:  IMG_perimeter_16.c                                        */
/* ======================================================================== */
