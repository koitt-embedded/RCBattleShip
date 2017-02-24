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
                    .asg    IMG_mad_16x16,  _IMG_mad_16x16
                .endif

                .sect ".text:optimized"
                .global _IMG_mad_16x16


; ================= SYMBOLIC REGISTER ASSIGNMENTS: SETUP ================== ;
        .asg            B15,        B_SP        ; Stack pointer, B datapath
        .asg            B2,         B_csr       ; CSR's value
        .asg            B1,         B_no_gie    ; CSR w/ GIE bit cleared
        .asg            A30,        A_csr       ; Copy of CSR's value
        .asg            B3,         B_ret       ; Return address
; ========================================================================= ;
; ====================== SYMBOLIC REGISTER ASSIGNMENTS =======================
        .asg            A0,         A_best
        .asg            A0,         A_i
        .asg            A0,         A_sub
        .asg            A0,         A_w
        .asg            A1,         A_vl
        .asg            A16,        A_matpos
        .asg            A17,        A_matval
        .asg            A14,        A_ptch
        .asg            A10,        A_ref_ri0d
        .asg            A11,        A_ref_ri0c
        .asg            A18,        A_2diffi_1c
        .asg            A18,        A_2sumi1d
        .asg            A18,        A_diffi_1d
        .asg            A19,        A_2sumi1c
        .asg            A19,        A_sumi1c
        .asg            A2,         A_vl1
        .asg            A20,        A_2diffi_1d
        .asg            A20,        A_2sumi0d
        .asg            A20,        A_diffi_0d
        .asg            A20,        A_diffi_1c
        .asg            A21,        A_matchi1
        .asg            A22,        A_k_ones
        .asg            A23,        A_pitch_8
        .asg            A24,        A_2sumi0c
        .asg            A24,        A_2sumi0cd
        .asg            A24,        A_srchid
        .asg            A25,        A_2sumi1cd
        .asg            A25,        A_diffi_0c
        .asg            A25,        A_srchic
        .asg            A26,        A_2srchid
        .asg            A26,        A_sumi1
        .asg            A26,        A_sumi1cd
        .asg            A27,        A_2diffi_0c
        .asg            A27,        A_2srchic
        .asg            A27,        A_sumi0cd
        .asg            A27,        A_sumi1d
        .asg            A28,        A_2diffi_0d
        .asg            A28,        A_ref_ri2d
        .asg            A28,        A_sumi0c
        .asg            A29,        A_ref_ri2c
        .asg            A29,        A_sumi0d
        .asg            A3,         A_vptch
        .asg            A30,        A_ref_ri1d
        .asg            A31,        A_2sumi1
        .asg            A31,        A_ref_ri1c
        .asg            A4,         A_ref_img
;       .asg            A5,         A_c40
        .asg            A6,         A_hl
        .asg            A6,         A_pitch
        .asg            A7,         A_ffff
        .asg            B6,         B_h
        .asg            A9,         A_bptch
        .asg            B0,         B_best
        .asg            B1,         B_ml
        .asg            B5,         B_matval
        .asg            B16,        B_ref_ri0b
        .asg            B17,        B_ref_ri0a
        .asg            B18,        B_2sumi0ab
        .asg            B18,        B_2sumi0b
        .asg            B18,        B_sumi0a
        .asg            B19,        B_diffi_0b
        .asg            B19,        B_sumi0b
        .asg            B19,        B_sumi1b
        .asg            B20,        B_src_imgcp
        .asg            B21,        B_2diffi_0b
        .asg            B21,        B_2sumi0a
        .asg            B22,        B_matchi0
        .asg            B23,        B_k_ones
        .asg            B24,        B_2sumi1a
        .asg            B24,        B_srchib
        .asg            B25,        B_2diffi_0a
        .asg            B25,        B_diffi_0a
        .asg            B25,        B_srchia
        .asg            B26,        B_2srchib
        .asg            B26,        B_sumi1ab
        .asg            B27,        B_2srchia
        .asg            B27,        B_2sumi1ab
        .asg            B27,        B_diffi_1b
        .asg            B28,        B_2diffi_1b
        .asg            B28,        B_ref_ri2b
        .asg            B29,        B_ref_ri2a
        .asg            B29,        B_sumi1a
        .asg            B30,        B_ref_ri1b
        .asg            B31,        B_2sumi1b
        .asg            B31,        B_ref_ri1a
        .asg            B4,         B_src_img
        .asg            B8,         B_match
        .asg            A8,         A_v
        .asg            B9,         B_2diffi_1a
        .asg            B9,         B_2sumi0
        .asg            B9,         B_diffi_1a
        .asg            B9,         B_sumi0
        .asg            B9,         B_sumi0ab
; ============================================================================

_IMG_mad_16x16:
; parameters: A_refImg, B_srcImg, A_pitch, B_h, A_v, B_match
;             A4,       B4,       A6,      B6,  A8,  B8
 
        STW     .D2T1   A14,        *B_SP--[3]               ; Save A14
||      MVC     .S2     CSR,        B_csr                    ; Remember CSR

        AND             B_csr,      -2,         B_no_gie     ; Clear GIE
||      STW     .D2T1   A11,        *+B_SP[2]                ; Save A11
||      ADD     .D1     A_v,        17,         A_w          ; pitch
||      MPY     .M1     -16,        A_pitch,    A_bptch      ; hpatch
 
        STW     .D2T1   A10,        *+B_SP[1]                ; Save A10
||      MVC     .S2     B_no_gie,   CSR                      ; Disable ints
||      MPY     .M1     A_w,        A_pitch,    A_vptch      ; vptch
||      SUB     .L1     A_pitch,    8,          A_pitch_8    ; pitch - 8
||      MVKL    .S1     0000FFFFh,  A_ffff                   ; save -1
; ===== Interrupts masked here =====                  

        MVKL    .S1     01010101h,  A_k_ones                 ; constant
||      MV      .L1     A_v,        A_vl                     ; vert. v...1
||      LDNDW   .D      *A_ref_img++(8),        B_ref_ri0a:B_ref_ri0b  ; Load ref

        MVKH    .S1     01010101h,  A_k_ones                 ; constant
||      ADD     .L1     -1,         A_vptch,    A_vptch      ; vptch--
||      MPY     .M2X    A_v,        B_h,        B_ml         ; ml = h*v
||      LDNDW   .D      *A_ref_img++(A_pitch_8),A_ref_ri0c:A_ref_ri0d   ; Load
||      MV      .D2     B_src_img,  B_src_imgcp              ; srcimg

        MVKL    .S2     01010101h,  B_k_ones                 ; constant
||      MV      .L1     A_v,        A_vl1                    ; v
||      MVKH    .S1     0000FFFFh,  A_ffff                   ; -1
||      LDNDW   .D2T2   *B_src_imgcp++,         B_srchia:B_srchib      ; Load src
||      SUB     .D1     A_pitch,    A_bptch,    A_bptch      ; 

        MVKH    .S2     01010101h,  B_k_ones                 ; constant
||      OR      .L2     -1,         B_matval,   B_matval     ; matval
||      MV      .S1     A_bptch,    A_ptch                   ; ptch
||      ZERO    .L1     A_hl                                 ; hl 
||      LDNDW   .D      *A_ref_img++(8),        B_ref_ri1a:B_ref_ri1b ; Load ref 

; ============================ PIPE LOOP PROLOG ==============================

        LDNDW   .D2T1   *B_src_imgcp++,         A_srchic:A_srchid     ; Load 
||      ZERO    .S1     A_matpos                             ; matpos

        LDNDW   .D      *A_ref_img++(A_pitch_8),A_ref_ri1c:A_ref_ri1d ;[ 4,1] 

        LDNDW   .D      *A_ref_img++(8),        B_ref_ri2a:B_ref_ri2b ;[ 5,1] 

        LDNDW   .D      *A_ref_img++(A_pitch_8),A_ref_ri2c:A_ref_ri2d ;[ 6,1] 

        SUBABS4 .L2     B_ref_ri1b, B_srchib,   B_diffi_1b   ;[ 7,1]
||      LDNDW   .D2T2   *B_src_imgcp++,  B_2srchia:B_2srchib ;[ 7,1]
||      B       .S2     L_5 + 12                             ;       

        LDNDW   .D2T1   *B_src_imgcp++,  A_2srchic:A_2srchid ;[ 8,1]
||      B       .S2     L_6 + 4                              ;       

M_LOOP:
        ADD     .D1     -2,         A_vl,       A_vl         ; vl-= 2
||      MPY     .M1     0, A_matchi1, A_matchi1              ; matchi1
||[!A_vl1 ]MV   .S1     A_v,        A_vl1                    ;[16,0] 
||      SUBABS4 .L2     B_ref_ri1a, B_srchia,   B_diffi_1a   ;[ 9,1] 
||      SUBABS4 .L1     A_ref_ri1d, A_srchid,   A_diffi_1d   ;[ 9,1] 
||      LDNDW   .D2T2   *B_src_imgcp++,  B_srchia:B_srchib   ;[ 1,2] 
||      B       .S2     L_7 + 8                              ;      

        MVK     .S1     7,          A_i                      ; i = 7
||      MV      .D2     B_ref_ri2b, B_ref_ri0b               ;[10,1]
||      SUBABS4 .L2     B_ref_ri0b, B_srchib,   B_diffi_0b   ;[10,1]
||      DOTPU4  .M2     B_diffi_1a, B_k_ones,   B_sumi1a     ;[10,1] 
||      SUBABS4 .L1     A_ref_ri1c, A_srchic,   A_diffi_1c   ;[10,1] 
||      LDNDW   .D      *A_ref_img++(8), B_ref_ri1a:B_ref_ri1b;[ 2,2]
||      B       .S2     L_8 + 8                              ;[ 2,2] 

        MV      .S2     B_ref_ri2a, B_ref_ri0a               ;[11,1]
||      DOTPU4  .M2     B_diffi_1b, B_k_ones,   B_sumi1b     ;[11,1]
||      SUBABS4 .L2     B_ref_ri0a, B_srchia,   B_diffi_0a   ;[11,1]
||      SUBABS4 .L1     A_ref_ri0d, A_srchid,   A_diffi_0d   ;[11,1]
||      DOTPU4  .M1     A_diffi_1c, A_k_ones,   A_sumi1c     ;[11,1]
||      LDNDW   .D2T1   *B_src_imgcp++,  A_srchic:A_srchid   ;[ 3,2]
||      B       .S1     LOOP_X                               ;
||[!A_vl]MV     .D1     A_vptch,    A_ptch                   ; ptch   

        SUBABS4 .L1     A_ref_ri0c, A_srchic,   A_diffi_0c   ;[12,1]
||      DOTPU4  .M2     B_diffi_0a, B_k_ones,   B_sumi0a     ;[12,1]
||      SUBABS4 .L2     B_ref_ri1a, B_2srchia,  B_2diffi_0a  ;[12,1]
||      DOTPU4  .M1     A_diffi_0d, A_k_ones,   A_sumi0d     ;[12,1]
||      LDNDW   .D      *A_ref_img++(A_pitch_8),A_ref_ri1c:A_ref_ri1d ;[ 4,2]
||[!A_vl]MV     .S1     A_v,         A_vl                    ; vl = v 
||      ZERO    .S2     B_matchi0                            ; matchi0 

; ============================ PIPE LOOP KERNEL ==============================
LOOP_X:

  [ A_i]ADD     .S1     A_i,        -1,         A_i           ;[17,1]
||      ADD     .S2     B_sumi1a,   B_sumi1b,   B_sumi1ab     ;[17,1]
||      DOTPU4  .M2     B_2diffi_1b,B_k_ones,   B_2sumi1b     ;[17,1]
||      DOTPU4  .M1     A_2diffi_0d,A_k_ones,   A_2sumi0d     ;[17,1]
||      ADD     .D1     A_sumi1c,   A_sumi1d,   A_sumi1cd     ;[17,1]
||      SUBABS4 .L2     B_ref_ri1a, B_srchia,   B_diffi_1a    ;[ 9,2]
||      SUBABS4 .L1     A_ref_ri1d, A_srchid,   A_diffi_1d    ;[ 9,2]
||      LDNDW   .D2T2   *B_src_imgcp++,  B_srchia:B_srchib    ;[ 1,3]

        ADD     .S2     B_sumi0a,   B_sumi0b,   B_sumi0ab     ;[18,1]
||      DOTPU4  .M1     A_2diffi_1d,A_k_ones,   A_2sumi1d     ;[18,1]
||      ADD     .S1     A_sumi0c,   A_sumi0d,   A_sumi0cd     ;[18,1]
||      ADD     .D2     B_ref_ri2b, 0,          B_ref_ri0b    ;[10,2]
||      SUBABS4 .L2     B_ref_ri0b, B_srchib,   B_diffi_0b    ;[10,2]
||      DOTPU4  .M2     B_diffi_1a, B_k_ones,   B_sumi1a      ;[10,2]
||      SUBABS4 .L1     A_ref_ri1c, A_srchic,   A_diffi_1c    ;[10,2]
||      LDNDW   .D      *A_ref_img++(8), B_ref_ri1a:B_ref_ri1b;[ 2,3]

  [ A_i]B       .S1     LOOP_X                                ;[19,1]
||      ADD     .D1X    A_sumi1cd,  B_sumi1ab,  A_sumi1       ;[19,1]
||      ADD     .S2     B_ref_ri2a, 0,          B_ref_ri0a    ;[11,2]
||      DOTPU4  .M2     B_diffi_1b, B_k_ones,   B_sumi1b      ;[11,2]
||      SUBABS4 .L2     B_ref_ri0a, B_srchia,   B_diffi_0a    ;[11,2]
||      SUBABS4 .L1     A_ref_ri0d, A_srchid,   A_diffi_0d    ;[11,2]
||      DOTPU4  .M1     A_diffi_1c, A_k_ones,   A_sumi1c      ;[11,2]
||      LDNDW   .D2T1   *B_src_imgcp++,  A_srchic:A_srchid    ;[ 3,3]

        ADD     .S2X    B_sumi0ab,  A_sumi0cd,  B_sumi0       ;[20,1]
||      ADD     .S1     A_matchi1,  A_sumi1,    A_matchi1     ;[20,1]
||      SUBABS4 .L1     A_ref_ri0c, A_srchic,   A_diffi_0c    ;[12,2]
||      DOTPU4  .M2     B_diffi_0a, B_k_ones,   B_sumi0a      ;[12,2]
||      SUBABS4 .L2     B_ref_ri1a, B_2srchia,  B_2diffi_0a   ;[12,2]
||      DOTPU4  .M1     A_diffi_0d, A_k_ones,   A_sumi0d      ;[12,2]
||      LDNDW   .D      *A_ref_img++(A_pitch_8),A_ref_ri1c:A_ref_ri1d   ;[ 4,3]

L_5:    ADD     .D2     B_matchi0,  B_sumi0,    B_matchi0     ;[21,1]
||      ADD     .S2     B_2sumi1a,  B_2sumi1b,  B_2sumi1ab    ;[21,1]
||      ADD     .S1     A_2sumi0c,  A_2sumi0d,  A_2sumi0cd    ;[21,1]
||      SUBABS4 .L2     B_ref_ri2a, B_2srchia,  B_2diffi_1a   ;[13,2]
||      DOTPU4  .M1     A_diffi_1d, A_k_ones,   A_sumi1d      ;[13,2]
||      SUBABS4 .L1     A_ref_ri2d, A_2srchid,  A_2diffi_1d   ;[13,2]
||      DOTPU4  .M2     B_2diffi_0a,B_k_ones,   B_2sumi0a     ;[13,2]
||      LDNDW   .D      *A_ref_img++(8), B_ref_ri2a:B_ref_ri2b;[ 5,3]

L_6:    ADD     .D2     B_2sumi0a,  B_2sumi0b,  B_2sumi0ab    ;[22,1]
||      ADD     .S1     A_2sumi1c,  A_2sumi1d,  A_2sumi1cd    ;[22,1]
||      DOTPU4  .M1     A_diffi_0c, A_k_ones,   A_sumi0c      ;[14,2]
||      SUBABS4 .L1     A_ref_ri2c, A_2srchic,  A_2diffi_1c   ;[14,2]
||      DOTPU4  .M2     B_diffi_0b, B_k_ones,   B_sumi0b      ;[14,2]
||      SUBABS4 .L2     B_ref_ri1b, B_2srchib,  B_2diffi_0b   ;[14,2]
||      LDNDW   .D      *A_ref_img++(A_pitch_8), A_ref_ri2c:A_ref_ri2d  ;[ 6,3]

L_7:    ADD     .S1X    A_2sumi1cd, B_2sumi1ab, A_2sumi1     ;[23,1]
||      ADD     .S2X    B_2sumi0ab, A_2sumi0cd, B_2sumi0     ;[23,1]
||      ADD     .D1     A_ref_ri2c, 0,          A_ref_ri0c   ;[15,2]
||      DOTPU4  .M1     A_2diffi_1c,A_k_ones,   A_2sumi1c    ;[15,2]
||      SUBABS4 .L1     A_ref_ri1c, A_2srchic,  A_2diffi_0c  ;[15,2]
||      DOTPU4  .M2     B_2diffi_1a,B_k_ones,   B_2sumi1a    ;[15,2]
||      SUBABS4 .L2     B_ref_ri1b, B_srchib,   B_diffi_1b   ;[ 7,3]
||      LDNDW   .D2T2   *B_src_imgcp++,  B_2srchia:B_2srchib ;[ 7,3]


L_8:    ADD     .S2     B_matchi0,  B_2sumi0,   B_matchi0    ;[24,1]
||      ADD     .S1     A_matchi1,  A_2sumi1,   A_matchi1    ;[24,1]
||      ADD     .D1     A_ref_ri2d, 0,          A_ref_ri0d   ;[16,2]
||      DOTPU4  .M2     B_2diffi_0b,B_k_ones,   B_2sumi0b    ;[16,2]
||      SUBABS4 .L2     B_ref_ri2b, B_2srchib,  B_2diffi_1b  ;[16,2]
||      SUBABS4 .L1     A_ref_ri1d, A_2srchid,  A_2diffi_0d  ;[16,2]
||      DOTPU4  .M1     A_2diffi_0c,A_k_ones,   A_2sumi0c    ;[16,2]
||      LDNDW   .D2T1   *B_src_imgcp++,  A_2srchic:A_2srchid ;[ 8,3]

; ============================ PIPE LOOP EPILOG ==============================
; EPILOG:

        ADD     .S2     B_sumi1a,   B_sumi1b,   B_sumi1ab    ;[17,3]
||      DOTPU4  .M2     B_2diffi_1b,B_k_ones,   B_2sumi1b    ;[17,3]
||      DOTPU4  .M1     A_2diffi_0d,A_k_ones,   A_2sumi0d    ;[17,3]
||      ADD     .D1     A_sumi1c,   A_sumi1d,   A_sumi1cd    ;[17,3]
||      SUB     .S1     A_ref_img,  A_ptch,     A_ref_img    ; 

        ADD     .S2     B_sumi0a,   B_sumi0b,   B_sumi0ab    ;[18,3]
||      DOTPU4  .M1     A_2diffi_1d,A_k_ones,   A_2sumi1d    ;[18,3]
||      ADD     .S1     A_sumi0c,   A_sumi0d,   A_sumi0cd    ;[18,3]
||      MV      .L2     B_src_img,  B_src_imgcp              ;

        ADD     .S1X    A_sumi1cd,  B_sumi1ab,  A_sumi1      ;[19,3]
||      LDNDW   .D      *A_ref_img++(8), B_ref_ri0a:B_ref_ri0b;

        ADD     .S2X    B_sumi0ab,  A_sumi0cd,  B_sumi0      ;[20,3]
||      ADD     .S1     A_matchi1,  A_sumi1,    A_matchi1    ;[20,3]
||      LDNDW   .D      *A_ref_img++(A_pitch_8), A_ref_ri0c:A_ref_ri0d;

        ADD     .L2     B_matchi0,  B_sumi0,    B_matchi0    ;[21,3]
||      ADD     .S2     B_2sumi1a,  B_2sumi1b,  B_2sumi1ab   ;[21,3]
||      ADD     .S1     A_2sumi0c,  A_2sumi0d,  A_2sumi0cd   ;[21,3]
||      LDNDW   .D2T2   *B_src_imgcp++,  B_srchia:B_srchib   ;

        ADD     .S2     B_2sumi0a,  B_2sumi0b,  B_2sumi0ab   ;[22,3]
||      ADD     .S1     A_2sumi1c,  A_2sumi1d,  A_2sumi1cd   ;[22,3]
|| [B_ml]ADD    .L2     B_ml,       -2,         B_ml         ;
||      LDNDW   .D      *A_ref_img++(8),        B_ref_ri1a:B_ref_ri1b; Load ref 

        ADD     .S1X    A_2sumi1cd, B_2sumi1ab, A_2sumi1     ;[23,3]
||      ADD     .L2X    B_2sumi0ab, A_2sumi0cd, B_2sumi0     ;[23,3]
||[ B_ml]B      .S2     M_LOOP                               ;
||      LDNDW   .D2T1   *B_src_imgcp++,         A_srchic:A_srchid ; Load 

        ADD     .L2     B_matchi0,  B_2sumi0,   B_matchi0    ;[24,3]
||      ADD     .S1     A_matchi1,  A_2sumi1,   A_matchi1    ;[24,3]
||      LDNDW   .D      *A_ref_img++(A_pitch_8),  A_ref_ri1c:A_ref_ri1d ;[ 4,1] 
||      MV      .L1X    B_matval,   A_matval

; ============================================================================
; END:

        CMPLTU  .L2     B_matchi0,  B_matval,   B_best       ;
||      ADD     .L1     -1,         A_vl1,      A_vl1        ;
||      MV      .S1     A_bptch,    A_ptch                   ;
||      LDNDW   .D      *A_ref_img++(8),        B_ref_ri2a:B_ref_ri2b ;[ 5,1] 

  [ B_best] MV    .L2   B_matchi0,  B_matval                 ;
||[ B_best] MV    .L1X  B_matchi0,  A_matval                 ;
||[ B_best] PACK2 .S1   A_hl,       A_vl1,      A_matpos     ;
||          LDNDW .D    *A_ref_img++(A_pitch_8),A_ref_ri2c:A_ref_ri2d ;[ 6,1]

        ADD     .S1     -1,         A_vl1,      A_vl1        ;
||      CMPLTU  .L1     A_matchi1,  A_matval,   A_best       ; XP stall
||      SUBABS4 .L2     B_ref_ri1b, B_srchib,   B_diffi_1b   ;[ 7,1] 
||      LDNDW   .D2T2   *B_src_imgcp++,  B_2srchia:B_2srchib ;[ 7,1] 
||[ B_ml]B      .S2     L_5 + 12                             ;       

  [ A_best] PACK2 .L1   A_hl,       A_vl1,      A_matpos     ;
||[!A_vl1 ] ADD   .D1   A_hl,       1,          A_hl         ;
||[ A_best] MV    .S2X  A_matchi1,  B_matval                 ;
||          LDNDW .D2T1 *B_src_imgcp++,  A_2srchic:A_2srchid ;[ 8,1] 
||[ B_ml]   B     .S1   L_6 + 4                              ;     

        ;==== Branch occurs                                  

; ========================================================================= ;
        LDW     .D2T1   *+B_SP[1],  A10

        RET     .S2     B_ret                                ; Return to caller
||      LDW     .D2T1   *+B_SP[2],  A11

        MV      .S1     A_v,        A_sub                    ;
||      AND     .L1     A_matpos,   A_ffff,     A_vl         ;
||      LDW     .D2T1   *++B_SP[3],  A14

        SUB     .L1     A_sub,      1,          A_sub        ;
||      SHL     .S1     A_ffff,     16,         A_ffff       ;

        SUB     .S1     A_sub,      A_vl,       A_vl         ;
||      AND     .L1     A_matpos,   A_ffff,     A_matpos     ;

        ADD     .S1     A_matpos,   A_vl,       A_matpos     ;
||      MV      .L1X    B_matval,   A_matval                 ;
        
        STNDW   .D2T1   A_matval:A_matpos,      *B_match     ;
||      MVC     .S2     B_csr,            CSR         ; Restore CSR
; ===== Interruptibility state restored here =====
; ===== Branch Occurs =====

* ========================================================================= *
*   End of file:  IMG_mad_16x16.s                                           *
* ========================================================================= *
