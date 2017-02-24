; 
;  Copyright (c) 2013, Texas Instruments Incorporated
;  http://www.ti.com
;  All rights reserved.
;
;  Redistribution and use in source and binary forms, with or without
;  modification, are permitted provided that the following conditions
;  are met:
;
;  *  Redistributions of source code must retain the above copyright
;     notice, this list of conditions and the following disclaimer.
;
;  *  Redistributions in binary form must reproduce the above copyright
;     notice, this list of conditions and the following disclaimer in the
;     documentation and/or other materials provided with the distribution.
;
;  *  Neither the name of Texas Instruments Incorporated nor the names of
;     its contributors may be used to endorse or promote products derived
;     from this software without specific prior written permission.
;
;  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
;  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
;  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
;  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
;  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
;  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
;  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
;  OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
;  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
;  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
;  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
;
; ======== tomp_tls_get_tp.asm ========
;

;******************************************************************************
;* __c6xabi_get_tp() - This function must return the Thread Pointer (TP) of   *
;*                     the current thread. The definition provided below is   *
;*                     a for the case where the OMP runtime manages TLS and   *
;*                     returns the current thread's TP.                       *
;*                                                                            *
;*  NOTE: This function must not modify any register other than the return    *
;*        register A4 and B30/B31                                             *
;******************************************************************************

        .global __TI_tls_currentTP

	.sect	".text:tls:get_tp"
	.clink
	.global	__c6xabi_get_tp

__c6xabi_get_tp:  .asmfunc
           MVKL     .S1       __TI_tls_currentTP,A4
           MVKH     .S1       __TI_tls_currentTP,A4
 ||        B        .S2       B3
           LDW      .D1T1      *+A4[0],A4
           NOP           4
            .endasmfunc
