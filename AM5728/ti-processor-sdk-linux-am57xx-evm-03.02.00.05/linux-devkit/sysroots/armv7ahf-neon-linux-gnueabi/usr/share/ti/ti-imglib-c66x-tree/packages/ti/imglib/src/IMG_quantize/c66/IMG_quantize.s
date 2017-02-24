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
                    .asg    IMG_quantize,  _IMG_quantize
                .endif

                .sect ".text:optimized"
                .global _IMG_quantize

_IMG_quantize:

; ===================== INPUT PARAMETERS ------------ ===================== ;
        .asg          A4,      A_di_ptr ; Data 'in' pointer
        .asg          B4,      B_numblks ;Number of 64-element blocks
        .asg          A6,      A_blksz  ; Block size (multiple of 16)
        .asg          B6,      B_r_ptr  ; Reciprocal array pointer (twin)
        .asg          A8,      A_q_pt   ; Q-point of Quant values

; ===================== SYMBOLIC REGISTER ASSIGNMENTS ===================== ;
        .asg          A0,      A_i      ; Inner loop control
        .asg          A0,      A_qt_1   ; Trunc:   qt[ 1] = qr[ 1] >> q_pt
        .asg          A0,      A_q_98   ; Quotients  9,  8
        .asg          A1,      A_q_BA   ; Quotients 11, 10
        .asg          A1,      A_qr_8   ; Round:   qr[ 8] = qp[ 8] + rnd
        .asg          A2,      A_do_ptr ; Data 'out' pointer
        .asg          A3,      A_qt_8   ; Trunc:   qt[ 8] = qr[ 8] >> q_pt
        .asg          A3,      A_qr_1   ; Round:   qr[ 1] = qp[ 1] + rnd
        .asg          A3,      A_qr_B   ; Round:   qr[11] = qp[11] + rnd
        .asg          A5,      A_qr_3   ; Round:   qr[ 3] = qp[ 3] + rnd
        .asg          A5,      A_SP     ; Twin stack pointer
        .asg          A6,      A_fix    ; Pointer fixup value
        .asg          A7,      A_qt_0   ; Trunc:   qt[ 0] = qr[ 0] >> q_pt
        .asg          A9,      A_r_ptr  ; Reciprocal array pointer
        .asg          A10,     A_r_end  ; End of reciprocal array
        .asg          A11,     A_rnd    ; Rounding term:  1 << (q_pt-1)
        .asg          A12,     A_qr_2   ; Round:   qr[ 2] = qp[ 2] + rnd
        .asg          A12,     A_qr_9   ; Round:   qr[ 9] = qp[ 9] + rnd
        .asg          A16,     A_qt_B   ; Trunc:   qt[11] = qr[11] >> q_pt
        .asg          A16,     A_qr_0   ; Round:   qr[ 0] = qp[ 0] + rnd
        .asg          A16,     A_q_10   ; Quotients  1,  0
        .asg          A17,     A_q_32   ; Quotients  3,  2
        .asg          A17,     A_qt_2   ; Trunc:   qt[ 2] = qr[ 2] >> q_pt
        .asg          A18,     A_qt_3   ; Trunc:   qt[ 3] = qr[ 3] >> q_pt
        .asg          A18,     A_qp_8   ; Product: qp[ 8] = r[ 8] * d[ 8]
        .asg          A19,     A_qt_A   ; Trunc:   qt[10] = qr[10] >> q_pt
        .asg          A19,     A_qp_9   ; Product: qp[ 9] = r[ 9] * d[ 9]
        .asg          A20,     A_qp_A   ; Product: qp[10] = r[10] * d[10]
        .asg          A20,     A_qp_2   ; Product: qp[ 2] = r[ 2] * d[ 2]
        .asg          A21,     A_qp_3   ; Product: qp[ 3] = r[ 3] * d[ 3]
        .asg          A21,     A_qp_B   ; Product: qp[11] = r[11] * d[11]
        .asg          A22,     A_d_98   ; Data         9,  8
        .asg          A23,     A_qt_9   ; Trunc:   qt[ 9] = qr[ 9] >> q_pt
        .asg          A23,     A_d_BA   ; Data        11, 10
        .asg          A24,     A_d_10   ; Data         1,  0
        .asg          A25,     A_qr_A   ; Round:   qr[10] = qp[10] + rnd
        .asg          A25,     A_d_32   ; Data         3,  2
        .asg          A26,     A_qp_0   ; Product: qp[ 0] = r[ 0] * d[ 0]
        .asg          A27,     A_qp_1   ; Product: qp[ 1] = r[ 1] * d[ 1]
        .asg          A28,     A_r_98   ; Reciprocals  9,  8
        .asg          A29,     A_r_BA   ; Reciprocals 11, 10
        .asg          A30,     A_r_10   ; Reciprocals  1,  0
        .asg          A31,     A_r_32   ; Reciprocals  3,  2

        .asg          B0,      B_qt_D   ; Trunc:   qt[13] = qr[13] >> q_pt
        .asg          B0,      B_qp_E   ; Product: qp[14] = r[14] * d[14]
        .asg          B1,      B_qp_F   ; Product: qp[15] = r[15] * d[15]
        .asg          B2,      B_j      ; Outer loop counter
        .asg          B3,      B_ret    ; Return address
        .asg          B4,      B_qt_6   ; Trunc:   qt[ 6] = qr[ 6] >> q_pt
        .asg          B4,      B_qt_4   ; Trunc:   qt[ 4] = qr[ 4] >> q_pt
        .asg          B4,      B_qr_E   ; Round:   qr[14] = qp[14] + rnd
        .asg          B5,      B_di_ptr ; Data 'in' pointer (twin)
        .asg          B7,      B_do_ptr ; Data 'out' pointer (twin)
        .asg          B8,      B_q_pt   ; Q-point
        .asg          B9,      B_fix    ; Pointer fixup value.
        .asg          B10,     B_qt_F   ; Trunc:   qt[15] = qr[15] >> q_pt
        .asg          B10,     B_qr_5   ; Round:   qr[ 5] = qp[ 5] + rnd
        .asg          B10,     B_qr_6   ; Round:   qr[ 6] = qp[ 6] + rnd
        .asg          B10,     B_qr_F   ; Round:   qr[15] = qp[15] + rnd
        .asg          B12,     B_qp_C   ; Product: qp[12] = r[12] * d[12]
        .asg          B13,     B_qp_D   ; Product: qp[13] = r[13] * d[13]
        .asg          B15,     B_SP     ; Stack pointer
        .asg          B16,     B_qr_7   ; Round:   qr[ 7] = qp[ 7] + rnd
        .asg          B16,     B_qp_6   ; Product: qp[ 6] = r[ 6] * d[ 6]
        .asg          B17,     B_qt_5   ; Trunc:   qt[ 5] = qr[ 5] >> q_pt
        .asg          B17,     B_qp_7   ; Product: qp[ 7] = r[ 7] * d[ 7]
        .asg          B18,     B_q_DC   ; Quotients 13, 12
        .asg          B18,     B_qt_C   ; Trunc:   qt[12] = qr[12] >> q_pt
        .asg          B19,     B_qt_E   ; Trunc:   qt[14] = qr[14] >> q_pt
        .asg          B19,     B_q_FE   ; Quotients 15, 14
        .asg          B20,     B_qr_4   ; Round:   qr[ 4] = qp[ 4] + rnd
        .asg          B20,     B_qp_4   ; Product: qp[ 4] = r[ 4] * d[ 4]
        .asg          B21,     B_qp_5   ; Product: qp[ 5] = r[ 5] * d[ 5]
        .asg          B22,     B_r_DC   ; Reciprocals 13, 12
        .asg          B23,     B_r_FE   ; Reciprocals 15, 14
        .asg          B24,     B_qr_D   ; Round:   qr[13] = qp[13] + rnd
        .asg          B24,     B_r_54   ; Reciprocals  5,  4
        .asg          B25,     B_r_76   ; Reciprocals  7,  6
        .asg          B26,     B_qr_C   ; Round:   qr[12] = qp[12] + rnd
        .asg          B26,     B_q_54   ; Quotients  5,  4
        .asg          B27,     B_q_76   ; Quotients  7,  6
        .asg          B27,     B_qt_7   ; Trunc:   qt[ 7] = qr[ 7] >> q_pt
        .asg          B28,     B_d_DC   ; Data        13, 12
        .asg          B29,     B_d_FE   ; Data        15, 14
        .asg          B30,     B_d_54   ; Data         5,  4
        .asg          B31,     B_d_76   ; Data         7,  6

; ========================================================================= ;

* ========================================================================= *
*   Setup / Prolog Code                                                     *
*                                                                           *
*   This code sets up all of the pointers and controls for the inner loop,  *
*   while simultaneously saving off registers to the stack.  Heavy use of   *
*   twin pointers speeds everything up.                                     *
*                                                                           *
*   The inner loop's "r_ptr" is controlled by comparing r_ptr to an "end    *
*   of array" pointer.  Whenever r_ptr >= r_end, we subtract the "block     *
*   fixup" (blk_sz * sizeof(short)) from the pointer.  Using the r_ptr as   *
*   our inner loop counter saves an instruction which would otherwise be    *
*   used to reinitialize the inner loop counter.  (The effect on register   *
*   pressure is negligible, since we trade an inner loop counter for an     *
*   end-of-block pointer.  Although it predicate register pressure is       *
*   reduced, predicates are not an issue in this code.)                     *
*                                                                           *
*   An early-abort is taken if the loop trip count is calculated to be      *
*   zero.  This might happen if the block count is zero.  Also, because     *
*   the kernel has a minimum trip count of 2, the minimum block size that   *
*   this code supports is 32 elements.                                      *
*                                                                           *
* ========================================================================= *
;-
; =========================== PIPE LOOP PROLOG ============================ ;
               SHR        .S2X       A_blksz,        4,               B2                   ; B2 = blk_sz / 16
||             ADD        .L2        B_r_ptr,        8,               B_r_ptr              ; Twin 'r_ptr'
||             MV         .L1X       B_r_ptr,        A_r_ptr                               ; Twin 'r_ptr'

               MV         .L2X       A_q_pt,         B_q_pt                                ; Partition MV.
||             MPYU       .M2        B2,             B_numblks,       B0                   ; Set up trip count

               NOP


  [!B0]        RET        .S2        B_ret                                                 ; Abort if trip cnt == 0
||[ B0]        ADD        .L2X       A_di_ptr,       8,               B_di_ptr             ; Twin 'di_ptr'
||[ B0]        ADD        .D2        B0,             -1,              B_j                  ; Adjust for para iters

; ============================ PIPE LOOP KERNEL ==============================
               SPLOOPD               8
|| [B0]        MVC        .S2        B_j,            ILC
|| [B0]        MV         .L1X       B_SP,           A_SP                                  ; Twin stack pointer

               SPMASK
|| [B0]        LDDW       .D2T2      *+B_di_ptr[2],  B_d_FE:B_d_DC                         ;[ 1,2] Data  F,E,D,C
||^[B0]        STW        .D1T1      A12,            *-A_SP[5]                             ; Save A12
||^[B0]        MV         .L1        A_di_ptr,       A_do_ptr                              ; Initialize 'do_ptr'


   [B0]        LDDW       .D2T2      *+B_r_ptr[2],   B_r_FE:B_r_DC                         ;[ 2,1] Recip F,E,D,C
|| [B0]        LDDW       .D1T1      *+A_r_ptr[2],   A_r_BA:A_r_98                         ;[ 2,1] Recip B,A,9,8

               SPMASK
|| [B0]        LDDW       .D1T1      *+A_di_ptr[2],  A_d_BA:A_d_98                         ;[ 3,1] Data  B,A,9,8
||^[B0]        ADD        .L1        A_blksz,        A_blksz,         A_fix                ; fix = blk_sz * 2
||^[B0]        STW        .D2T2      B10,            * B_SP--[6]                           ; Save B10

               SPMASK
||^[B0]        STDW       .D1T1      A11:A10,        *-A_SP[ 2]                            ; Save A11, A10
||^[B0]        STDW       .D2T2      B13:B12,        *+B_SP[ 2]                            ; Save B13, B12

               SPMASK
||             LDDW       .D2T2      *B_di_ptr++[4], B_d_76:B_d_54                         ;[ 5,1] Data  7,6,5,4
||^            MV         .L2X       A_fix,          B_fix                                 ; Twin 'fix'

               SPMASK
||             LDDW       .D1T1      *A_r_ptr++[4],  A_r_32:A_r_10                         ;[ 6,1] Recip 3,2,1,0
||             LDDW       .D2T2      *B_r_ptr++[4],  B_r_76:B_r_54                         ;[ 6,1] Recip 7,6,5,4
||^            ADD        .S1        A_fix,          A_r_ptr,        A_r_end              ; Set "end of r[]" ptr
||^            ADD        .S2X       A_di_ptr,       8,              B_do_ptr             ; Twin 'do_ptr'
||^            MVK        .L1        1,              A_rnd

               MPY2       .M2        B_d_DC,         B_r_DC,         B_qp_D:B_qp_C         ;[ 7,1] qp[n]=d[n]*r[n]
||             LDDW       .D1T1      *A_di_ptr++[4], A_d_32:A_d_10                         ;[ 7,1] Data  3,2,1,0
||             CMPLTU     .L1        A_r_ptr,        A_r_end,        A_i                   ;[ 7,3] while (r<r_end)

               SPMASK
||             MPY2       .M1        A_d_BA,         A_r_BA,         A_qp_B:A_qp_A         ;[ 8,1] qp[n]=d[n]*r[n]
||  [!A_i]     SUB        .D2        B_r_ptr,        B_fix,          B_r_ptr               ;[ 8,3] (o) update r_ptr
||^            ADD        .S1        A_q_pt,         -1,              A3                   ; A3 = q_pt - 1

               SPMASK
||             MPY2       .M2        B_d_FE,         B_r_FE,         B_qp_F:B_qp_E         ;[ 9,1] qp[n]=d[n]*r[n]
||  [!A_i]     SUB        .D1        A_r_ptr,        A_fix,          A_r_ptr               ;[ 9,3] (o) update r_ptr
||^            SHL        .S1        A_rnd,          A3,             A_rnd                 ; rnd = 1 << (q_pt-1)

               MPY2       .M1        A_d_98,         A_r_98,         A_qp_9:A_qp_8         ;[10,1] qp[n]=d[n]*r[n] 

               ADD        .S2X       B_qp_C,         A_rnd,          B_qr_C                ;[11,1] qp_C=qr_C+rnd
||             ADD        .L2X       B_qp_D,         A_rnd,          B_qr_D                ;[11,1] qp_D=qr_D+rnd
||             MPY2       .M2        B_d_54,         B_r_54,         B_qp_5:B_qp_4         ;[11,1] qp[n]=d[n]*r[n]

               SHR        .S2        B_qr_C,         B_q_pt,         B_qt_C                ;[12,1] qt_C=qr_C>>q_pt
||             ADD        .L1        A_qp_A,         A_rnd,          A_qr_A                ;[12,1] qp_A=qr_A+rnd
||             MPY2       .M1        A_d_32,         A_r_32,         A_qp_3:A_qp_2         ;[12,1] qp[n]=d[n]*r[n]
||             ADD        .S1        A_qp_B,         A_rnd,          A_qr_B                ;[12,2] qp_B=qr_B+rnd

               SHR        .S1        A_qr_B,         A_q_pt,         A_qt_B                ;[13,1] qt_B=qr_B>>q_pt
||             ADD        .L2X       B_qp_E,         A_rnd,          B_qr_E                ;[13,1] qp_E=qr_E+rnd
||             MPY2       .M2        B_d_76,         B_r_76,         B_qp_7:B_qp_6         ;[13,1] qp[n]=d[n]*r[n]
||             SHR        .S2        B_qr_D,         B_q_pt,         B_qt_D                ;[13,2] qt_D=qr_D>>q_pt

               SHR        .S1        A_qr_A,         A_q_pt,         A_qt_A                ;[14,2] qt_A=qr_A>>q_pt
||             SHR        .S2        B_qr_E,         B_q_pt,         B_qt_E                ;[14,2] qt_E=qr_E>>q_pt
||             ADD        .L1        A_qp_9,         A_rnd,          A_qr_9                ;[14,2] qp_9=qr_9+rnd
||             ADD        .L2X       B_qp_F,         A_rnd,          B_qr_F                ;[14,2] qp_F=qr_F+rnd
||             MPY2       .M1        A_d_10,         A_r_10,         A_qp_1:A_qp_0         ;[14,2] qp[n]=d[n]*r[n]

               PACK2      .L2        B_qt_D,         B_qt_C,         B_q_DC                ;[15,2] Packed quot D,C
||             ADD        .D2X       B_qp_4,         A_rnd,          B_qr_4                ;[15,2] qp_4=qr_4+rnd
||             ADD        .S1        A_qp_8,         A_rnd,          A_qr_8                ;[15,2] qp_8=qr_8+rnd
||             SHR        .S2        B_qr_F,         B_q_pt,         B_qt_F                ;[15,2] qt_F=qr_F>>q_pt

               SSHVR      .M2        B_qr_4,         B_q_pt,         B_qt_4                ;[16,2] qt_4=qr_4>>q_pt
||             SHR        .S1        A_qr_9,         A_q_pt,         A_qt_9                ;[16,2] qt_9=qr_9>>q_pt
||             ADD        .D1        A_qp_2,         A_rnd,          A_qr_2                ;[16,2] qp_2=qr_2+rnd
||             ADD        .L1        A_qp_3,         A_rnd,          A_qr_3                ;[16,2] qp_3=qr_3+rnd

               PACK2      .S2        B_qt_F,         B_qt_E,         B_q_FE                ;[17,2] Packed quot F,E
||             SHR        .S1        A_qr_8,         A_q_pt,         A_qt_8                ;[17,2] qt_8=qr_8>>q_pt
||             ADD        .L2X       B_qp_5,         A_rnd,          B_qr_5                ;[17,2] qp_5=qr_5+rnd

               PACK2      .S1        A_qt_B,         A_qt_A,         A_q_BA                ;[18,2] Packed quot B,A
||             SSHVR      .M2        B_qr_5,         B_q_pt,         B_qt_5                ;[18,2] qt_5=qr_5>>q_pt
||             ADD        .L1        A_qp_0,         A_rnd,          A_qr_0                ;[18,2] qp_0=qr_0+rnd
||             ADD        .L2X       B_qp_6,         A_rnd,          B_qr_6                ;[18,2] qp_6=qr_6+rnd
||             ADD        .S2X       B_qp_7,         A_rnd,          B_qr_7                ;[18,2] qp_7=qr_7+rnd

               PACK2      .S1        A_qt_9,         A_qt_8,         A_q_98                ;[19,1] Packed quot 9,8
||             SSHVR      .M1        A_qr_0,         A_q_pt,         A_qt_0                ;[19,1] qt_0=qr_0>>q_pt

               STDW       .D2T2      B_q_FE:B_q_DC,  *+B_do_ptr[2]                         ;[20,1] Quot. F,E,D,C
||             PACK2      .L2        B_qt_5,         B_qt_4,         B_q_54                ;[20,1] Packed quot 5,4
||             SSHVR      .M2        B_qr_7,         B_q_pt,         B_qt_7                ;[20,1] qt_7=qr_7>>q_pt

               STDW       .D1T1      A_q_BA:A_q_98,  *+A_do_ptr[2]                         ;[21,1] Quot. B,A,9,8
||             SSHVR      .M1        A_qr_2,         A_q_pt,         A_qt_2                ;[21,1] qt_2=qr_2>>q_pt
||             ADD        .L1        A_qp_1,         A_rnd,          A_qr_1                ;[21,1] qp_1=qr_1+rnd

               SSHVR      .M2        B_qr_6,         B_q_pt,         B_qt_6                ;[22,1] qt_6=qr_6>>q_pt

               SSHVR      .M1        A_qr_3,         A_q_pt,         A_qt_3                ;[23,1] qt_3=qr_3>>q_pt

               PACK2      .L2        B_qt_7,         B_qt_6,         B_q_76                ;[24,1] Packed quot 7,6

               PACK2      .L1        A_qt_3,         A_qt_2,         A_q_32                ;[25,1] Packed quot 3,2
||             SSHVR      .M1        A_qr_1,         A_q_pt,         A_qt_1                ;[25,1] qt_1=qr_1>>q_pt

               NOP

               STDW       .D2T2      B_q_76:B_q_54,  *B_do_ptr++[4]                        ;[27,1] Quot. 7,6,5,4
||             PACK2      .L1        A_qt_1,         A_qt_0,         A_q_10                ;[27,1] Packed quot 1,0


               SPKERNEL              0,0
||             STDW       .D1T1      A_q_32:A_q_10,  *A_do_ptr++[4]                        ;[28,1] Quot. 3,2,1,0

               NOP                   9
               NOP                   4

; ================ SYMBOLIC REGISTER ASSIGNMENTS: CLEANUP ================= ;
              .asg                   A0,            A_SP                                   ; Stack pointer, B datapath
              .asg                   B3,            B_ret                                  ; Return address
; ========================================================================= ;

               MV     .S1X           B_SP,            A_SP                                 ; Twin the stack ptr.

               LDDW   .D1T2          *+ A_SP[ 2],     B13:B12                              ; Restore B13,B12
||             LDDW   .D2T1          *+ B_SP[ 1],     A11:A10                              ; Restore A11,A10
||             RET    .S2            B_ret                                                 ; Return to caller

               LDW    .D2T2          *++B_SP[ 6],     B10                                  ; Load val of B10
||             LDW    .D1T1          *+ A_SP[ 1],     A12                                  ; Load val of A12


               NOP      ; Epilog cycle 17 (overlays loop cycle 25) :  Available units = .D1 .D2 .L1 .L2 .M1 .M2 .S1 .S2 .1X .2X

               NOP      ; Epilog cycle 18 (overlays loop cycle 26) :  Available units = .D1 .D2 .L1 .L2 .M1 .M2 .S1 .S2 .1X .2X

               NOP      ; Epilog cycle 19 (overlays loop cycle 27) :  Available units = .D1 .D2 .L1 .L2 .M1 .M2 .S1 .S2 .1X .2X

               NOP      ; Epilog cycle 20 (overlays loop cycle 28) :  Available units = .D1 .D2 .L1 .L2 .M1 .M2 .S1 .S2 .1X .2X

               
;-
; ========================================================================= ;

* ========================================================================= *
*   End of file:  IMG_quantize.s                                            *
* ========================================================================= *
