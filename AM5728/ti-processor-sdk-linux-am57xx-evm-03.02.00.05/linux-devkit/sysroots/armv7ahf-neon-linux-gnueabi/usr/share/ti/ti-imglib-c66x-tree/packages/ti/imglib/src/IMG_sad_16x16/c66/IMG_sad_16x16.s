* ======================================================================== *
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
* ======================================================================== *

* ######################################################################## *
* #  TI Disclaimer: This kernel is obsolete. It is provided here for     # *
* #  backward compatibility.                                             # *
* ######################################################################## *

                .if     __TI_EABI__
                    .asg    IMG_sad_16x16,  _IMG_sad_16x16
                .endif

                .sect ".text:optimized"
                .global _IMG_sad_16x16


_IMG_sad_16x16:

* ===================== SYMBOLIC REGISTER ASSIGNMENTS ===================== *
        .asg            A0,         A_p
        .asg            A1,         A_i
        .asg            A2,         A_s0
        .asg            A3,         A_k1
        .asg            A4,         A_srcImg
        .asg            A4,         A_retval
        .asg            A5,         A_sad
        .asg            A6,         A_pitch
        .asg            A6,         A_s3210
        .asg            A7,         A_d7654
        .asg            A7,         A_s7654
        .asg            A8,         A_r3210
        .asg            A8,         A_s1
        .asg            A9,         A_d3210
        .asg            A9,         A_r7654
        .asg            B3,         B_retaddr
        .asg            B4,         B_refImg
        .asg            B5,         B_pitch
        .asg            B6,         B_rBA98
        .asg            B7,         B_dFEDC
        .asg            B7,         B_rFEDC
        .asg            B8,         B_dBA98
        .asg            B8,         B_sBA98
        .asg            B9,         B_sFEDC
        .asg            B16,        B_sad
        .asg            B17,        B_srcImg
        .asg            B18,        B_s2
        .asg            B19,        B_s3
* ========================================================================= *
* =========================== PIPE LOOP PROLOG ============================ *
        LDNDW   .D2T2   *+B_refImg(8),          B_rFEDC:B_rBA98 ;[ 1,1] 
||      B       .S2     loop
||      MVK     .S1     0x0101,     A_k1
||      ADD     .L2X    A_srcImg,   8,          B_srcImg

        LDDW    .D1T1   *A_srcImg++(16),        A_s7654:A_s3210 ;[ 2,1] 
||      LDDW    .D2T2   *B_srcImg++(16),        B_sFEDC:B_sBA98 ;[ 2,1] 
||      MV      .L2X    A_pitch,    B_pitch
||      PACK2   .L1     A_k1,       A_k1,       A_k1

        LDNDW   .D2T1   *B_refImg++(B_pitch),   A_r7654:A_r3210 ;[ 3,1] 
||      ZERO    .L2     B_sad
||      ZERO    .L1     A_sad
||      MVK     .S1     15,         A_i
||      MVK     .D1     3,          A_p

* =========================== PIPE LOOP KERNEL ============================ *
loop:
  [!A_p]ADD     .L1     A_sad,      A_s1,       A_sad           ;[13,1] 
||[!A_p]ADD     .S2     B_sad,      B_s3,       B_sad           ;[13,1] 
||[ A_i]BDEC    .S1     loop,       A_i                         ;[10,2] 
||      DOTPU4  .M1     A_d3210,    A_k1,       A_s0            ;[10,2] 
||      SUBABS4 .L2     B_sFEDC,    B_rFEDC,    B_dFEDC         ;[ 7,3] 
||      LDNDW   .D2T2   *+B_refImg(8),          B_rFEDC:B_rBA98 ;[ 1,5] 

  [!A_p]ADD     .S2     B_sad,      B_s2,       B_sad           ;[14,1] 
||      DOTPU4  .M2X    B_dFEDC,    A_k1,       B_s3            ;[ 8,3] 
||      SUBABS4 .L1     A_s7654,    A_r7654,    A_d7654         ;[ 8,3] 
||      SUBABS4 .L2     B_sBA98,    B_rBA98,    B_dBA98         ;[ 8,3] 
||      LDDW    .D1T1   *A_srcImg++(16),        A_s7654:A_s3210 ;[ 2,5] 
||      LDDW    .D2T2   *B_srcImg++(16),        B_sFEDC:B_sBA98 ;[ 2,5] 

  [ A_p]SUB     .D1     A_p,        1,          A_p             ;[15,1] 
||[!A_p]ADD     .S1     A_sad,      A_s0,       A_sad           ;[15,1] 
||      DOTPU4  .M1     A_d7654,    A_k1,       A_s1            ;[ 9,3] 
||      DOTPU4  .M2X    B_dBA98,    A_k1,       B_s2            ;[ 9,3] 
||      SUBABS4 .L1     A_s3210,    A_r3210,    A_d3210         ;[ 9,3] 
||      LDNDW   .D2T1   *B_refImg++(B_pitch),   A_r7654:A_r3210 ;[ 3,5] 

* =========================== PIPE LOOP EPILOG ============================ *
        ADD     .L1     A_sad,      A_s1,       A_sad           ;[13,4] 
||      ADD     .S2     B_sad,      B_s3,       B_sad           ;[13,4] 
||      DOTPU4  .M1     A_d3210,    A_k1,       A_s0            ;[10,5] 

        ADD     .L2     B_sad,      B_s2,       B_sad           ;[14,4] 
||      RET     .S2     B_retaddr

        ADD     .S1     A_sad,      A_s0,       A_sad           ;[15,4] 

        ADD     .L1     A_sad,      A_s1,       A_sad           ;[13,5] 
||      ADD     .S2     B_sad,      B_s3,       B_sad           ;[13,5] 

        ADD     .S2     B_sad,      B_s2,       B_sad           ;[14,5] 

        ADD     .S1     A_sad,      A_s0,       A_sad           ;[15,5] 

        ADD     .S1X    A_sad,      B_sad,      A_retval
* ========================================================================= *

* ========================================================================= *
*   End of file: IMG_sad_16x16.s                                            *
* ========================================================================= *
