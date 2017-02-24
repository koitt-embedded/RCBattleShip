 
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
; /** \file tomp_switch_sp.asm */
;

; /** 
;  * Calls a function with a new SP and restores SP before returning
;  * @param newsp pointer to new stack location (1 past the top of the stack)
;  * @param fnptr pointer to function that will be called with new SP
;  */

	.sect	".text:__TI_switch_sp"

	.clink

newsp       .set    a4      ; 1st arg
fnptr       .set    b4      ; 2nd arg

;*---------------------------------------------------------------------------
;* Registers stored to NEWSP. NEWSP points to 1 past the "top" of the 
;* stack and is aligned to an 8 byte boundary 
;*
;* NEWSP[0] = b15
;* NEWSP[1] = b3
;*
;*---------------------------------------------------------------------------

        .global  __TI_switch_sp
__TI_switch_sp:	.asmfunc
         ; save the return address on the new stack
	 stw    b3,  *newsp--(8)

         ; save the old sp on the new stack and update the sp
         stw    b15, *+newsp(4)
||       mv     newsp, b15

         ; call the function provided as the 2nd arg. This function will
         ; use the new sp as it's stack
         call   fnptr
         addkpc __fnptr_ret, b3, 4

__fnptr_ret:;        call occurs

         ; on return from fnptr, load the return address for this function
	 ldw    *+b15(8), a3

         mv     b15, b4

         ; update SP to old SP and return
  	 ldw    *+b4(4), b15

         nop    2

  	 retnop a3, 5
        .endasmfunc
