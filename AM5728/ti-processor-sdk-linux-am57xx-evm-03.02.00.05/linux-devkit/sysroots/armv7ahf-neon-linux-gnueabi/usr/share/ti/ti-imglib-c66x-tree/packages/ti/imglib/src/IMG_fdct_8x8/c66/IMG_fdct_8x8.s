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

* ======================================================================== *
* IMG_fdct_8x8.asm - Chen FDCT optimized Hand ASM                          *
* ======================================================================== *
               
                .if     __TI_EABI__
                    .asg    IMG_fdct_8x8, _IMG_fdct_8x8
                .endif

                .sect ".text:optimized"
                .global _IMG_fdct_8x8

_IMG_fdct_8x8:
* ================= SYMBOLIC REGISTER ASSIGNMENTS: ARGS. ================== *
        ;;                                      ; void fdct_8x8(
        .asg            A4,         A_dct_data  ;   short dct_data[],
        .asg            B4,         B_num_dcts  ;   unsigned num_dcts
        ;;                                      ; );
* ================= SYMBOLIC REGISTER ASSIGNMENTS: MISC. ================== *
        .asg            B15,        B_SP        ; Stack pointer, B datapath
        .asg            A2,         A_SP        ; Twin Stack ptr, A datapath
        .asg            B3,         B_ret       ; Return address 
        .asg            A11,        A_ret_sv    ; Return address copy
* ===================== SYMBOLIC CONSTANT ASSIGNMENTS ===================== *
        .asg            0xFB15,     cst_C1      ; Cosine term C1
        .asg            0xA73D,     cst_C2      ; Cosine term C2
        .asg            0xD4DB,     cst_C3      ; Cosine term C3
        .asg            0xB505,     cst_C4      ; Cosine term C4
        .asg            0x8E3A,     cst_C5      ; Cosine term C5
        .asg            0x4546,     cst_C6      ; Cosine term C6
        .asg            0x31F1,     cst_C7      ; Cosine term C7
* ================== SYMBOLIC REGISTER ASSIGNMENTS: V_LOOP ================ *
        ;; Cosine terms
        .asg            A21,        A_C1C7      ; Packed terms C1, C7
        .asg            B0,         B_C1C7      ; Packed terms C1, C7
        .asg            B2,         B_C2C6      ; Packed terms C2, C6
        .asg            A23,        A_C3C5      ; Packed terms C3, C5
        .asg            B4,         B_C3C5      ; Packed terms C3, C5
        .asg            A18,        A_C4__      ; Packed terms C4, zero
        .asg            A28,        A___C4      ; Packed terms zero, C4
        .asg            A24,        A_C5C3      ; Packed terms C5, C3
        .asg            A20,        A_C6C2      ; Packed terms C6, C2
        .asg            B10,        B_C7C1      ; Packed terms C7, C1

        ;; Input and output pointers
        .asg            A4,         A_i_ptr     ; Input pointer
        .asg            B26,        B_o_ptr     ; Output pointer
        .asg            B28,        B_fix       ; Pointer fixup constant
        .asg            B23,        B_fix_      ; Pointer fixup offset
        .asg            A29,        A_fix_      ; Pointer fixup offset

        ;; Incoming spatial-domain samples
        .asg            A9,         A_f0f0      ; Packed f0 terms, both cols
        .asg            B24,        B_f1f1      ; Packed f1 terms, both cols
        .asg            B25,        B_f2f2      ; Packed f2 terms, both cols
        .asg            A22,        A_f3f3      ; Packed f3 terms, both cols
        .asg            A26,        A_f4f4      ; Packed f4 terms, both cols
        .asg            B19,        B_f5f5      ; Packed f5 terms, both cols
        .asg            B9,         B_f6f6      ; Packed f6 terms, both cols
        .asg            A5,         A_f7f7      ; Packed f7 terms, both cols

        ;; Initial add/subtract butterflies
        .asg            A17,        A_g0g0      ; g0 = f7 + f0, both columns
        .asg            B29,        B_g1g1      ; g1 = f6 + f1, both columns
        .asg            B16,        B_h1h1      ; h1 = f5 + f2, both columns
        .asg            A1,         A_h0h0      ; h0 = f4 + f3, both columns
        .asg            A31,        A_g2g2      ; g2 = f3 - f4, both columns
        .asg            B9,         B_g3g3      ; g3 = f2 - f5, both columns
        .asg            B8,         B_h3h3      ; h3 = f1 - f6, both columns
        .asg            A31,        A_h2h2      ; h2 = f0 - f7, both columns
        .asg            B9,         B_s0s0      ; s0 = h3 + g3, both columns
        .asg            B8,         B_q0q0      ; q0 = h3 - g3, both columns
        .asg            A10,        A_p0p0      ; p0 = g0 + h0, both columns
        .asg            B16,        B_p1p1      ; p1 = g1 + h1, both columns
        .asg            B21,        B_r1r1      ; r1 = g1 - h1, both columns
        .asg            A7,         A_r0r0      ; r0 = g0 - h0, both columns
        .asg            B20,        B_r1r1_     ; r1, q-point adjusted
        .asg            A3,         A_r0r0_     ; r0, q-point adjusted
        .asg            A27,        A_r0r1_     ; r0, r1 packed, "A" column
        .asg            B29,        B_r1r0_     ; r1, r0 packed, "B" column
        .asg            B31,        B_r0r1_     ; r0, r1 packed, "B" column
        .asg            A9,         A_g2g2_     ; g2, q-point adjusted
        .asg            A3,         A_h2h2_     ; h2, q-point adjusted
        .asg            A30,        A_g2h2      ; g2, h2 packed, "A" column
        .asg            A8,         Axg2h2      ; g2, h2 packed, "B" column
        .asg            B7,         B_g2h2      ; g2, h2 packed, "B" column

        ;; Remaining FDCT butterflies.
        .asg            A5,         A_q1        ; q1 = C4 * g2
        .asg            A11,        A_s1        ; s1 = C4 * h2
        .asg            A5,         A_s1q1      ; s1, q1 packed
        .asg            B5,         Bxs0q0      ; s0, q0 packed
        .asg            A12,        A_S1Q1      ; S1 = s1 + s0, Q1 = q1 + q0
        .asg            A2,         A_S0Q0      ; S0 = s1 - s0, Q0 = q1 - q0

        .asg            B25,        B_q1        ; q1 = C4 * g2
        .asg            B7,         B_s1        ; s1 = C4 * h2
        .asg            B18,        B_s1q1      ; s1, q1 packed
        .asg            B8,         B_s0q0      ; s0, q0 packed
        .asg            B6,         B_S0Q0      ; S1 = s1 + s0, Q1 = q1 + q0
        .asg            B20,        B_S1Q1      ; S0 = s1 - s0, Q0 = q1 - q0

        ;; Final frequency-domain terms.
        .asg            A3,         A_F4F4_     ; F4 terms, both columns
        .asg            A2,         A_F1        ; Freq domain F1, "A" column
        .asg            A19,        A_F2        ; Freq domain F2, "A" column
        .asg            A7,         A_F3        ; Freq domain F3, "A" column
        .asg            A8,         A_F5        ; Freq domain F5, "A" column
        .asg            A31,        A_F6        ; Freq domain F6, "A" column
        .asg            A6,         A_F7        ; Freq domain F7, "A" column
        .asg            B30,        B_F1        ; Freq domain F1, "B" column
        .asg            B21,        B_F2        ; Freq domain F2, "B" column
        .asg            B6,         B_F3        ; Freq domain F3, "B" column
        .asg            B18,        B_F5        ; Freq domain F5, "B" column
        .asg            B17,        B_F6        ; Freq domain F6, "B" column
        .asg            B27,        B_F7        ; Freq domain F7, "B" column
        .asg            A16,        A_F0F0      ; Packed F0 terms, both cols
        .asg            B16,        B_F1F1      ; Packed F1 terms, both cols
        .asg            A19,        A_F2F2      ; Packed F2 terms, both cols
        .asg            B8,         B_F3F3      ; Packed F3 terms, both cols
        .asg            A25,        A_F4F4      ; Packed F4 terms, both cols
        .asg            B7,         B_F5F5      ; Packed F5 terms, both cols
        .asg            A31,        A_F6F6      ; Packed F6 terms, both cols
        .asg            B21,        B_F7F7      ; Packed F7 terms, both cols

        ;; Loop control
        .asg            A0,         Ap          ; Prolog collapse predicate
        .asg            B1,         B_i         ; Loop counter
        .asg            B22,        B_i_horiz   ; Loop ctr copy for h_loop
* ========================================================================= *

* ========================================================================= *
*  V_LOOP:  VERTICAL PASS LOOP                                              *
* ========================================================================= *

* ==================== SETUP CODE AND PIPE LOOP PROLOG ==================== *
        LDW     .D1T1   *+A_i_ptr  [16],        A_f4f4          ;[ 1,1] 
||      ADDK    .S1     32,         A_i_ptr                     ; offset i_ptr
||      SHL     .S2     B_num_dcts, 2,          B_i             ; i = 4*num

  [ B_i]LDW     .D1T1   *+A_i_ptr  [ 4],        A_f3f3          ;[ 2,1] 
||[ B_i]ZERO    .L1     A_C4__                                  ; set up cst 0
||[!B_i]RET     .S2     B_ret                                   ; early abort

  [ B_i]LDW     .D1T1   *-A_i_ptr  [ 8],        A_f0f0          ;[ 3,1] 
||[ B_i]MVKLH   .S1     cst_C4,     A_C4__                      ; const C4
||[ B_i]MV      .L2X    A_i_ptr,    B_o_ptr

  [ B_i]LDW     .D1T1   *+A_i_ptr  [20],        A_f7f7          ;[ 4,1] 
||[ B_i]MVKL    .S1     cst_C5,     A_C3C5                      ; const C5
||[ B_i]MV      .L1X    B_SP,       A_SP

  [ B_i]LDW     .D1T2   *-A_i_ptr  [ 4],        B_f1f1          ;[ 5,1] 
||[ B_i]MVKL    .S1     cst_C2,     A_C6C2                      ; const C2
||[ B_i]MVK     .L1     1,          A_fix_                      ; init fixup

  [ B_i]LDW     .D1T2   *+A_i_ptr  [12],        B_f5f5          ;[ 6,1] 
||[ B_i]MVKLH   .S1     cst_C6,     A_C6C2                      ; const C6
||[ B_i]MVKL    .S2     cst_C7,     B_C1C7                      ; const C7
||[ B_i]SWAP2   .L1     A_C4__,     A___C4                      ; swapped pair
||[ B_i]ADDAW   .D2     B_o_ptr,    20,         B_o_ptr         ; offset o_ptr

  [ B_i]LDW     .D1T2   *+A_i_ptr  [16],        B_f6f6          ;[ 7,1] 
||[ B_i]MVK     .L1     2,          Ap                          ; pro. collapse
||[ B_i]MVKLH   .S2     cst_C1,     B_C1C7                      ; const C1
||[ B_i]MVKLH   .S1     cst_C3,     A_C3C5                      ; const C3
||[ B_i]SUBU    .L2X    B_i,        A_fix_,     B_fix_:B_i_horiz; 2nd loop copy

        SUB2    .L1     A_f3f3,     A_f4f4,     A_g2g2          ;[ 8,1] 
||      ADD2    .S1     A_f3f3,     A_f4f4,     A_h0h0          ;[ 8,1] 
||      MVKL    .S2     0x0101011D, B_fix                       ; ptr fix cst.
||      ROTL    .M2X    A_C6C2,     16,         B_C2C6          ; swapped pair
||      ROTL    .M1     A_C3C5,     16,         A_C5C3          ; swapped pair
||      STW     .D1T1   A12,        *-A_SP[3]                   ; Save A12
||      STW     .D2T2   B10,        * B_SP--[4]                 ; Save B10

        ADD2    .L1     A_g2g2,     A_g2g2,     A_g2g2_         ;[ 9,1] 
||      SUB2    .S1     A_f0f0,     A_f7f7,     A_h2h2          ;[ 9,1] 
||      ADD2    .D1     A_f0f0,     A_f7f7,     A_g0g0          ;[ 9,1] 
||      MVKH    .S2     0x0101011D, B_fix                       ; ptr fix cst.
||      SWAP2   .L2     B_C1C7,     B_C7C1                      ; swapped pair
||      ROTL    .M2X    A_C3C5,     0,          B_C3C5          ; swapped pair
||      ROTL    .M1X    B_C1C7,     0,          A_C1C7          ; swapped pair
||      STDW    .D2T1   A11:A10,    *+B_SP[1]                   ; Save A11, A10

; Collapsed 2 prolog stages.
; ============================ PIPE LOOP KERNEL =========================== *
v_loop:
  [!Ap] STW     .D2T1   A_F0F0,     *-B_o_ptr  [28]             ;[30,1] 
||      PACK2   .S2X    B_F5,       A_F5,       B_F5F5          ;[30,1] 
||      DOTPNRSU2.M1    A_r0r1_,    A_C6C2,     A_F6            ;[30,1] 
||      PACK2   .L2     B_s1,       B_q1,       B_s1q1          ;[20,2] 
||      ROTL    .M2     B_r1r0_,    16,         B_r0r1_         ;[20,2] 
||      PACKH2  .S1X    A_r0r0_,    B_r1r1_,    A_r0r1_         ;[20,2] 
||      ADD2    .L1     A_h2h2,     A_h2h2,     A_h2h2_         ;[10,3] 
||[B_i] LDW     .D1T2   * A_i_ptr++[A_fix_],    B_f2f2          ;[10,3] 

        PACK2   .S2X    B_F3,       A_F3,       B_F3F3          ;[31,1] 
||      DOTPNRSU2.M1X   A_S1Q1,     B_C7C1,     A_F7            ;[31,1] 
||      SUB2    .D2     B_s1q1,     B_s0q0,     B_S0Q0          ;[21,2] 
||      ADD2    .L2     B_s1q1,     B_s0q0,     B_S1Q1          ;[21,2] 
||      PACK2   .L1     A_g2g2_,    A_h2h2_,    Axg2h2          ;[11,3] 
||      PACKH2  .S1     A_g2g2_,    A_h2h2_,    A_g2h2          ;[11,3] 
||[B_i] LDW     .D1T1   *+A_i_ptr  [ 8],        A_f4f4          ;[ 1,4] 
||      ROTL    .M2     B_fix,      8,          B_fix           ;[ 1,4]

  [!Ap] STW     .D2T2   B_F3F3,     *-B_o_ptr  [16]             ;[32,1] 
||      SUB2    .L1X    A_p0p0,     B_p1p1,     A_F4F4          ;[22,2] 
||      DOTPRSU2.M2X    B_S0Q0,     A_C5C3,     B_F5            ;[22,2] 
||      ROTL    .M1     A_F4F4,     0,          A_F4F4_         ;[22,2] 
||      SUB2    .S1     A_g0g0,     A_h0h0,     A_r0r0          ;[12,3] 
||      SUB2    .S2     B_f1f1,     B_f6f6,     B_h3h3          ;[12,3] 
||      ADD2    .L2     B_f1f1,     B_f6f6,     B_g1g1          ;[12,3] 
||[B_i] LDW     .D1T1   *+A_i_ptr  [ 4],        A_f3f3          ;[ 2,4] 

  [!Ap] STW     .D2T2   B_F5F5,     *-B_o_ptr  [ 8]             ;[33,1] 
||      PACK2   .L2X    B_F1,       A_F1,       B_F1F1          ;[33,1] 
||      ADD2    .S1X    A_p0p0,     B_p1p1,     A_F0F0          ;[23,2] 
||      DOTPNRSU2.M2    B_S0Q0,     B_C3C5,     B_F3            ;[23,2] 
||      PACK2   .L1     A_s1,       A_q1,       A_s1q1          ;[23,2] 
||      DOTPRSU2.M1     A_g2h2,     A___C4,     A_s1            ;[13,3] 
||[B_i] LDW     .D1T1   *-A_i_ptr  [ 8],        A_f0f0          ;[ 3,4] 
||[!Ap] EXT     .S2     B_fix,      8,  24,     B_fix_          ;[ 3,4]

  [B_i] BDEC    .S2     v_loop,     B_i                         ;[34,1] 
||[!Ap] STW     .D2T2   B_F1F1,     *-B_o_ptr  [24]             ;[34,1] 
||      DOTPRSU2.M2     B_S1Q1,     B_C1C7,     B_F1            ;[24,2] 
||      SUB2    .L1X    A_s1q1,     Bxs0q0,     A_S0Q0          ;[24,2] 
||      ADD2    .S1X    A_s1q1,     Bxs0q0,     A_S1Q1          ;[24,2] 
||      MV      .L2X    Axg2h2,     B_g2h2                      ;[14,3] 
||[B_i] LDW     .D1T1   *+A_i_ptr  [20],        A_f7f7          ;[ 4,4] 

        PACK2   .L1X    A_F6,       B_F6,       A_F6F6          ;[35,1] 
||[!Ap] STW     .D2T1   A_F4F4_,    *-B_o_ptr  [12]             ;[35,1] 
||      DOTPRSU2.M1     A_S0Q0,     A_C5C3,     A_F5            ;[25,2] 
||      DOTPRSU2.M2X    B_g2h2,     A_C4__,     B_q1            ;[15,3] 
||      ADD2    .S1     A_r0r0,     A_r0r0,     A_r0r0_         ;[15,3] 
||      SUB2    .S2     B_f2f2,     B_f5f5,     B_g3g3          ;[15,3] 
||      ADD2    .L2     B_f2f2,     B_f5f5,     B_h1h1          ;[15,3] 
||[B_i] LDW     .D1T2   *-A_i_ptr  [ 4],        B_f1f1          ;[ 5,4] 

        PACK2   .L1X    A_F2,       B_F2,       A_F2F2          ;[36,1] 
||      DOTPNRSU2.M1    A_S0Q0,     A_C3C5,     A_F3            ;[26,2] 
||      DOTPRSU2.M2X    B_g2h2,     A___C4,     B_s1            ;[16,3] 
||      SUB2    .S2     B_g1g1,     B_h1h1,     B_r1r1          ;[16,3] 
||      SUB2    .L2     B_h3h3,     B_g3g3,     B_q0q0          ;[16,3] 
||      ADD2    .D2     B_h3h3,     B_g3g3,     B_s0s0          ;[16,3] 
||[B_i] LDW     .D1T2   *+A_i_ptr  [12],        B_f5f5          ;[ 6,4] 

  [!Ap] STW     .D2T1   A_F2F2,     *-B_o_ptr  [20]             ;[37,1] 
||      DOTPNRSU2.M2X   B_r0r1_,    A_C6C2,     B_F6            ;[27,2] 
||      DOTPRSU2.M1     A_S1Q1,     A_C1C7,     A_F1            ;[27,2] 
||      PACK2   .S2     B_s0s0,     B_q0q0,     B_s0q0          ;[17,3] 
||      PACKH2  .L2     B_s0s0,     B_q0q0,     Bxs0q0          ;[17,3] 
||      ADD2    .L1     A_g0g0,     A_h0h0,     A_p0p0          ;[17,3] 
||[B_i] LDW     .D1T2   *+A_i_ptr  [16],        B_f6f6          ;[ 7,4] 
||      SHR     .S1X    B_fix,      24,         A_fix_          ;[ 7,4]

  [!Ap] STW     .D2T1   A_F6F6,     *-B_o_ptr  [ 4]             ;[38,1] 
||      PACK2   .L2X    B_F7,       A_F7,       B_F7F7          ;[38,1] 
||      DOTPNRSU2.M2    B_S1Q1,     B_C7C1,     B_F7            ;[28,2] 
||      DOTPRSU2.M1X    A_r0r1_,    B_C2C6,     A_F2            ;[28,2] 
||      ADD2    .S2     B_r1r1,     B_r1r1,     B_r1r1_         ;[18,3] 
||      SUB2    .L1     A_f3f3,     A_f4f4,     A_g2g2          ;[ 8,4] 
||      ADD2    .D1     A_f3f3,     A_f4f4,     A_h0h0          ;[ 8,4] 
||[ Ap] SUB     .S1     Ap,         1,          Ap

  [!Ap] STW     .D2T2   B_F7F7,     * B_o_ptr++[B_fix_]         ;[39,1] 
||      DOTPRSU2.M2     B_r0r1_,    B_C2C6,     B_F2            ;[29,2] 
||      DOTPRSU2.M1     A_g2h2,     A_C4__,     A_q1            ;[19,3] 
||      PACK2   .S2X    B_r1r1_,    A_r0r0_,    B_r1r0_         ;[19,3] 
||      ADD2    .L2     B_g1g1,     B_h1h1,     B_p1p1          ;[19,3] 
||      ADD2    .L1     A_g2g2,     A_g2g2,     A_g2g2_         ;[ 9,4] 
||      SUB2    .S1     A_f0f0,     A_f7f7,     A_h2h2          ;[ 9,4] 
||      ADD2    .D1     A_f0f0,     A_f7f7,     A_g0g0          ;[ 9,4] 
* ========================================================================= *


* ================== SYMBOLIC REGISTER ASSIGNMENTS: H_LOOP ================ *
        ;; Cosine terms and rounding constant
        .asg            A21,        A_c1c7      ; Packed c1, c7
        .asg            A3,         A_c2c6      ; Packed c2, c6
        .asg            A23,        A_c3c5      ; Packed c3, c5
        .asg            A18,        A_C4__      ; Packed c4, zero
        .asg            B28,        B_C4__      ; Packed c4, zero 
        .asg            A24,        A_c5c3      ; Packed c5, c3
        .asg            A20,        A_c6c2      ; Packed c6, c2
        .asg            A22,        A_c7c1      ; Packed c7, c1
        .asg            A25,        A_dc_rnd    ; Packed DC rounding terms

        ;; Input and output pointers
        .asg            A4,         A_io_ptr    ; Twin Input/Output pointer
        .asg            B26,        B_io_ptr    ; Twin Input/Output pointer

        ;; Incoming spatial-domain samples
        .asg            A17,        A_f7f6      ; Packed f7, f6, "A" row
        .asg            A16,        A_f5f4      ; Packed f5, f4, "A" row
        .asg            A1,         A_f4f5      ; Packed f4, f5, "A" row
        .asg            A29,        A_f3f2      ; Packed f3, f2, "A" row
        .asg            A28,        A_f1f0      ; Packed f1, f0, "A" row
        .asg            A6,         A_f0f1      ; Packed f0, f1, "A" row

        .asg            A2,         Axf7f6      ; Packed f7, f6, "B" row
        .asg            B5,         B_f7f6      ; Packed f7, f6, "B" row
        .asg            B25,        B_f6f7      ; Packed f6, f7, "B" row
        .asg            B24,        B_f4f5      ; Packed f4, f5, "B" row
        .asg            B6,         B_f3f2      ; Packed f3, f2, "B" row
        .asg            B1,         B_f2f3      ; Packed f2, f3, "B" row
        .asg            B0,         B_f0f1      ; Packed f0, f1, "B" row

        ;; Initial add/subtract butterflies
                                                ; "A" row:
        .asg            A7,         A_g0g1      ; g0 = f0 + f7, g1 = f1 + f6
        .asg            A19,        A_h2h3      ; h2 = f0 - f7, h3 = f1 - f6
        .asg            A1,         A_h0h1      ; h0 = f3 + f4, h1 = f2 + f5
        .asg            A5,         A_g2g3      ; g2 = f3 - f4, g3 = f2 - f5
        .asg            A9,         A_p0p1      ; p0 = g0 + h0, p1 = g1 + h1
        .asg            A0,         A_r0r1      ; r0 = g0 - h0, r1 = g1 - h1

                                                ; "B" row:
        .asg            B5,         B_g0g1      ; g0 = f0 + f7, g1 = f1 + f6
        .asg            B24,        B_h2h3      ; h2 = f0 - f7, h3 = f1 - f6
        .asg            B7,         B_h0h1      ; h0 = f3 + f4, h1 = f2 + f5
        .asg            B6,         B_g2g3      ; g2 = f3 - f4, g3 = f2 - f5
        .asg            B9,         B_p0p1      ; p0 = g0 + h0, p1 = g1 + h1
        .asg            B29,        B_r0r1      ; r0 = g0 - h0, r1 = g1 - h1

        ;; DC and Nyquist term butterflies, which straddle both datapaths
        .asg            A7,         A_p0p0_     ; Packed p0's, pre-round.
        .asg            A30,        A_p0p0      ; Packed p0's, rounded.
        .asg            A9,         A_p1p1      ; Packed p1's.

        .asg            A9,         A_F0F0_     ; Packed F0's, Q3
        .asg            A16,        A_F4F4_     ; Packed F4's, Q3
        .asg            B19,        B_F0F0      ; Packed F0's, Q0 (final)
        .asg            B8,         B_F4F4      ; Packed F0's, Q0 (final)

        ;; Remaining FDCT butterflies
                                                ; "A" row:
        .asg            A27,        A_q1_       ; q1_= C4 * g2 
        .asg            A26,        A_s1_       ; s1_= C4 * h2
        .asg            A1,         A_s1q1_     ; Packed s1_, q1_
        .asg            A30,        A_s1q1      ; s1 = s1_ << 1, q1 = q1_ << 1 
        .asg            A5,         A_q0        ; q0 = h3 + g3
        .asg            A6,         A_s0        ; s0 = h3 - g3
        .asg            A5,         A_s0q0      ; Packed s0, q0
        .asg            A12,        A_S1Q1      ; S1 = s1 + s0, Q1 = q1 + q0
        .asg            A30,        A_S0Q0      ; S0 = s1 - s0, Q0 = q1 - q0

                                                ; "B" row:
        .asg            B4,         B_q1_       ; q1_= C4 * g2 
        .asg            B3,         B_s1_       ; s1_= C4 * h2
        .asg            B3,         B_s1q1_     ; Packed s1_, q1_
        .asg            B3,         B_s1q1      ; s1 = s1_ << 1, q1 = q1_ << 1 
        .asg            B6,         B_q0        ; q0 = h3 + g3
        .asg            B0,         B_s0        ; s0 = h3 - g3
        .asg            B10,        B_s0q0      ; Packed s0, q0
        .asg            B20,        B_S1Q1      ; S1 = s1 + s0, Q1 = q1 + q0
        .asg            B1,         B_S0Q0      ; S0 = s1 - s0, Q0 = q1 - q0

        ;; Final frequency-domain results.
                                                ; "A" row:
        .asg            A2,         A_F1        ; Freq. domain F1 term.
        .asg            A19,        A_F2        ; Freq. domain F2 term.
        .asg            A7,         A_F3        ; Freq. domain F3 term.
        .asg            A8,         A_F5        ; Freq. domain F5 term.
        .asg            A31,        A_F6        ; Freq. domain F6 term.
        .asg            A6,         A_F7        ; Freq. domain F7 term.

        .asg            A27,        A_F7F6      ; Packed F7, F6
        .asg            A26,        A_F5F4      ; Packed F5, F4
        .asg            A29,        A_F3F2      ; Packed F3, F2
        .asg            A28,        A_F1F0      ; Packed F1, F0

                                                ; "B" row:
        .asg            B30,        B_F1        ; Freq. domain F1 term.
        .asg            B21,        B_F2        ; Freq. domain F2 term.
        .asg            B6,         B_F3        ; Freq. domain F3 term.
        .asg            B18,        B_F5        ; Freq. domain F5 term.
        .asg            B17,        B_F6        ; Freq. domain F6 term.
        .asg            B27,        B_F7        ; Freq. domain F7 term.

        .asg            B17,        B_F7F6      ; Packed F7, F6
        .asg            B16,        B_F5F4      ; Packed F5, F4
        .asg            B31,        B_F3F2      ; Packed F3, F2
        .asg            B30,        B_F1F0      ; Packed F1, F0

        ;; Loop control
        .asg            B2,         Bp          ; Prolog collapse counter.
        .asg            B22,        B_i         ; Loop trip counter.
* ========================================================================= *

* ========================================================================= *
*  H_LOOP: HORIZONTAL PASS LOOP                                             *
*                                                                           *
*  Note:  2 cycles of this code have been "relocated" to the end so that    *
*  the h_loop branch target does not span two fetch packets.  The net       *
*  result is that this function has NO execute packet padding.              *
* ========================================================================= *

* ====================== PIPE LOOP EPILOG AND PROLOG ====================== *
; Collapsed 2 epilog stages.
        LDNDW   .D2T2   *--B_io_ptr(12),        B_f2f3:B_f0f1   ;[ 2,1] 
||      PACK2   .S2X    B_F5,       A_F5,       B_F5F5          ;[30,4] 
||      DOTPNRSU2.M1X   A_S1Q1,     B_C7C1,     A_F7            ;[31,4] 
||      B               reloc

        LDW     .D1T2   *-A_io_ptr  [10],       B_f4f5          ;
||      DOTPNRSU2.M1    A_r0r1_,    A_C6C2,     A_F6            ;[30,4] 
||      STW     .D2T1   A_F0F0,     *-B_io_ptr [25]             ;[30,4] 
||      ADDK    .S2     -20,        B_io_ptr

        SHRU2   .S1     A_C6C2,     2,          A_c6c2
||      PACK2   .L2X    B_F3,       A_F3,       B_F3F3          ;[31,4] 
||      STW     .D2T2   B_F5F5,     *B_io_ptr--[ 8]             ;[33,4] 
||      B               h_loop

        SHRU2   .S1     A_C5C3,     3,          A_c5c3
||      STW     .D2T2   B_F3F3,     *B_io_ptr--[ 8]             ;[32,4] 
||      PACK2   .L2X    B_F1,       A_F1,       B_F1F1          ;[33,4] 
||      MV      .L1X    B_ret,      A_ret_sv

        SHRU2   .S1     A_C3C5,     3,          A_c3c5
||      MVK     .L2     3,          Bp
||      STW     .D2T2   B_F1F1,     *B_io_ptr++[12]             ;[34,4] 
||      PACK2   .L1X    A_F7,       B_F7,       Axf7f6          ;

        SWAP2   .L2     B_f2f3,     B_f3f2                      ;[ 7,1] 
||      MV      .S2X    A_C4__,     B_C4__
||      SHRU2   .S1     A_C1C7,     3,          A_c1c7
||      PACK2   .L1X    A_F2,       B_F2,       A_F2F2          ;[36,4] 
||      STW     .D2T1   A_F4F4,     *B_io_ptr--[ 8]             ;[35,4] 
||      MVK     .D1     4,          A_dc_rnd
* ========================== RELOC. BRANCH OCCURS ========================= *

; Collapsed 2 prolog stages.
* ============================ PIPE LOOP KERNEL ============================ *
h_loop:
        DOTPNRSU2.M1    A_S1Q1,     A_c7c1,     A_F7            ;[28,1] 
||      ADD2    .S2     B_s1q1,     B_s0q0,     B_S1Q1          ;[19,2] 
||      PACK2   .L1     A_s0,       A_q0,       A_s0q0          ;[19,2] 
||      ADD2    .S1     A_g0g1,     A_h0h1,     A_p0p1          ;[19,2] 
||      SUB     .L2     B_h2h3,     B_g2g3,     B_q0            ;[10,3] 
||      DOTPRSU2.M2     B_h2h3,     B_C4__,     B_s1_           ;[10,3] 
||      LDDW    .D1T1   * A_io_ptr--[4],        A_f3f2:A_f1f0   ;[10,3] 
||      LDDW    .D2T2   *+B_io_ptr  [1],        B_f6f7:B_f4f5   ;[ 1,4] 

        DOTPRSU2.M1     A_S1Q1,     A_c1c7,     A_F1            ;[29,1] 
||      PACK2   .L1X    A_p0p1,     B_p0p1,     A_p1p1          ;[20,2] 
||      PACKH2  .S1X    A_p0p1,     B_p0p1,     A_p0p0_         ;[20,2] 
||      DOTPNRSU2.M2X   B_S0Q0,     A_c3c5,     B_F3            ;[20,2] 
||      SUB2    .D1     A_g0g1,     A_h0h1,     A_r0r1          ;[20,2] 
||      PACK2   .L2     B_s0,       B_q0,       B_s0q0          ;[11,3] 
||      ADD2    .S2     B_g0g1,     B_h0h1,     B_p0p1          ;[11,3] 
||      LDDW    .D2T2   * B_io_ptr--[4],        B_f2f3:B_f0f1   ;[ 2,4] 

        PACK2   .S2     B_F1,       B_F0F0,     B_F1F0          ;[30,1] 
||      PACK2   .L2     B_F7,       B_F6,       B_F7F6          ;[30,1] 
||      PACKLH2 .L1X    A_F5,       B_F4F4,     A_F5F4          ;[30,1] 
||      DOTPNRSU2.M1    A_S0Q0,     A_c3c5,     A_F3            ;[30,1] 
||      ADD2    .D1     A_p0p0_,    A_dc_rnd,   A_p0p0          ;[21,2] 
||      DOTPNRSU2.M2X   B_S1Q1,     A_c7c1,     B_F7            ;[21,2] 
||      PACK2   .S1     A_s1_,      A_q1_,      A_s1q1_         ;[21,2] 
||[ Bp] SUB     .D2     Bp,         1,          Bp              ;pro. collapse

        BDEC    .S2     h_loop,     B_i                         ;[31,1]
||[!Bp] STDW    .D2T2   B_F3F2:B_F1F0,          *+B_io_ptr[16]  ;[31,1] 
||      SUB2    .D1     A_p0p0,     A_p1p1,     A_F4F4_         ;[22,2] 
||      ADD2    .S1     A_p0p0,     A_p1p1,     A_F0F0_         ;[22,2] 
||      DOTPRSU2.M2X    B_S1Q1,     A_c1c7,     B_F1            ;[22,2] 
||      ADD2    .L1     A_s1q1_,    A_s1q1_,    A_s1q1          ;[22,2] 
||      ROTL    .M1     A_f5f4,     16,         A_f4f5          ;[13,3] 

  [!Bp] STDW    .D2T2   B_F7F6:B_F5F4,          *+B_io_ptr[17]  ;[32,1] 
||      PACK2   .L1     A_F7,       A_F6,       A_F7F6          ;[32,1] 
||      DOTPNRSU2.M2X   B_r0r1,     A_c6c2,     B_F6            ;[23,2] 
||      SUB2    .S1     A_s1q1,     A_s0q0,     A_S0Q0          ;[23,2] 
||      ADD2    .D1     A_s1q1,     A_s0q0,     A_S1Q1          ;[23,2] 
||      DOTPNRSU2.M1    A_r0r1,     A_c6c2,     A_F6            ;[23,2] 
||      PACK2   .L2     B_s1_,      B_q1_,      B_s1q1_         ;[14,3] 
||      SUB2    .S2     B_g0g1,     B_h0h1,     B_r0r1          ;[14,3] 

        PACK2   .L2     B_F3,       B_F2,       B_F3F2          ;[24,2] 
||      SHR2    .S2X    A_F4F4_,    3,          B_F4F4          ;[24,2] 
||      DOTPRSU2.M1     A_S0Q0,     A_c5c3,     A_F5            ;[24,2] 
||      ADD2    .D2     B_s1q1_,    B_s1q1_,    B_s1q1          ;[15,3] 
||      SUB2    .D1     A_f3f2,     A_f4f5,     A_g2g3          ;[15,3] 
||      ADD2    .S1     A_f3f2,     A_f4f5,     A_h0h1          ;[15,3] 
||      SWAP2   .L1     A_f1f0,     A_f0f1                      ;[15,3] 
||      ROTL    .M2     B_f6f7,     16,         B_f7f6          ;[ 6,4] 

  [!Bp] STDW    .D1T1   A_F7F6:A_F5F4,          *+A_io_ptr[13]  ;[34,1] 
||      PACK2   .S1     A_F3,       A_F2,       A_F3F2          ;[34,1] 
||      PACK2   .S2     B_F5,       B_F4F4,     B_F5F4          ;[25,2] 
||      SUB2    .D2     B_s1q1,     B_s0q0,     B_S0Q0          ;[16,3] 
||      DOTPRSU2.M2X    B_r0r1,     A_c2c6,     B_F2            ;[16,3] 
||      DOTPRSU2.M1     A_g2g3,     A_C4__,     A_q1_           ;[16,3] 
||      SUB2    .L1     A_f0f1,     A_f7f6,     A_h2h3          ;[16,3] 
||      SWAP2   .L2     B_f2f3,     B_f3f2                      ;[ 7,4] 

        PACKLH2 .S1X    A_F1,       B_F0F0,     A_F1F0          ;[35,1] 
||      DOTPRSU2.M2X    B_S0Q0,     A_c5c3,     B_F5            ;[17,3] 
||      DOTPRSU2.M1     A_h2h3,     A_C4__,     A_s1_           ;[17,3] 
||      ADD2    .L1     A_f0f1,     A_f7f6,     A_g0g1          ;[17,3] 
||      SUB2    .D2     B_f3f2,     B_f4f5,     B_g2g3          ;[ 8,4] 
||      ADD2    .L2     B_f3f2,     B_f4f5,     B_h0h1          ;[ 8,4] 
||      SUB2    .S2     B_f0f1,     B_f7f6,     B_h2h3          ;[ 8,4] 
||      LDDW    .D1T1   *+A_io_ptr  [1],        A_f7f6:A_f5f4   ;[ 8,4] 

  [!Bp] STDW    .D1T1   A_F3F2:A_F1F0,          *+A_io_ptr[12]  ;[36,1] 
||      SHR2    .S2X    A_F0F0_,    3,          B_F0F0          ;[27,2] 
||      DOTPRSU2.M1     A_r0r1,     A_c2c6,     A_F2            ;[27,2] 
||      SUB     .S1     A_h2h3,     A_g2g3,     A_q0            ;[18,3] 
||      ADD     .L1     A_h2h3,     A_g2g3,     A_s0            ;[18,3] 
||      ADD     .D2     B_h2h3,     B_g2g3,     B_s0            ;[ 9,4] 
||      DOTPRSU2.M2     B_g2g3,     B_C4__,     B_q1_           ;[ 9,4] 
||      ADD2    .L2     B_f0f1,     B_f7f6,     B_g0g1          ;[ 9,4] 

* ============================ PIPE LOOP EPILOG ============================ *
; Collapsed 2 epilog stages.
        DOTPNRSU2.M1    A_S1Q1,     A_c7c1,     A_F7            ;[28,4] 
||      PACK2   .L2     B_F7,       B_F6,       B_F7F6          ;[30,4] 
||      PACK2   .S2     B_F1,       B_F0F0,     B_F1F0          ;[30,4] 

        DOTPRSU2.M1     A_S1Q1,     A_c1c7,     A_F1            ;[29,4] 
||      LDW     .D2T1   *+B_SP[1],  A12                         ; get A12

        PACKLH2 .L1X    A_F5,       B_F4F4,     A_F5F4          ;[30,4] 
||      DOTPNRSU2.M1    A_S0Q0,     A_c3c5,     A_F3            ;[30,4] 
||      RET     .S2X    A_ret_sv
||      LDDW    .D2T1   *+B_SP[1],  A11:A10                     ; get A11,A10

        LDW     .D2T2   *++B_SP[4], B10                         ; get B10

        PACK2   .L1     A_F7,       A_F6,       A_F7F6          ;[32,4] 

        PACKLH2 .S1X    A_F1,       B_F0F0,     A_F1F0          ;[35,4] 

        PACK2   .L1     A_F3,       A_F2,       A_F3F2          ;[34,4] 
||      STDW    .D1T1   A_F7F6:A_F5F4,          *+A_io_ptr[ 9]  ;[34,4] 
||      STDW    .D2T2   B_F3F2:B_F1F0,          *+B_io_ptr[12]  ;[31,4] 

        STDW    .D1T1   A_F3F2:A_F1F0,          *+A_io_ptr[ 8]  ;[36,4] 
||      STDW    .D2T2   B_F7F6:B_F5F4,          *+B_io_ptr[13]  ;[32,4] 
* ========================== RETURN BRANCH OCCURS ========================= *

* ================ RELOCATED CODE (BRANCH TARGET ALIGNMENT) =============== *
reloc:
        SUB2    .D2     B_f3f2,     B_f4f5,     B_g2g3          ;[ 8,1] 
||      ADD2    .L2     B_f3f2,     B_f4f5,     B_h0h1          ;[ 8,1] 
||      SUB2    .S2X    B_f0f1,     Axf7f6,     B_h2h3          ;[ 8,1] 
||      LDW     .D1T1   *--A_io_ptr[14],        A_f5f4          ;
||      ROTL    .M1     A_c1c7,     16,         A_c7c1
||      PACK2   .S1     A_dc_rnd,   A_dc_rnd,   A_dc_rnd        ; 0x00040004

        ADD     .S2     B_h2h3,     B_g2g3,     B_s0            ;[ 9,1] 
||      DOTPRSU2.M2     B_g2g3,     B_C4__,     B_q1_           ;[ 9,1] 
||      ADD2    .L2X    B_f0f1,     Axf7f6,     B_g0g1          ;[ 9,1] 
||      ROTL    .M1     A_c6c2,     16,         A_c2c6
||      PACK2   .L1X    A_F6,       B_F6,       A_f7f6          ;[35,4] 
||      STW     .D2T1   A_F2F2,     *B_io_ptr++[ 9]             ;[37,4] 
||      ADDK    .S1     -8,         A_io_ptr
* ========================== H_LOOP BRANCH OCCURS ========================= *

* ========================================================================= *
*   End of file:  fdct_8x8_h.asm                                            *
* ========================================================================= *
