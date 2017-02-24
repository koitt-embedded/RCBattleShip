/*
 * Copyright (c) 2016, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

MEMORY
{
        L1PRAM:         o = 0x00E00000, l = 0x00008000
        L1DRAM:         o = 0x00F00000, l = 0x00008000
        L2SRAM_UMAP1:   o = 0x007E0000, l = 0x00020000
        L2SRAM_UMAP0:   o = 0x00800000, l = 0x00020000
        L3SRAM:         o = 0x20000000, l = 0x00100000
}

/* Set L1D, L1P and L2 Cache Sizes */
ti_sysbios_family_c64p_Cache_l1dSize = 32*1024;
ti_sysbios_family_c64p_Cache_l1pSize = 32*1024;
ti_sysbios_family_c64p_Cache_l2Size = 0;

SECTIONS
{
    .vecs         >        L2SRAM_UMAP1               // Interrupt Vectors
    .cinit        >        L2SRAM_UMAP1               // Initialization Tables
    .pinit        >        L2SRAM_UMAP1               // Constructor Tables
    .init_array   >        L2SRAM_UMAP1               //
    .binit        >        L2SRAM_UMAP1               // Boot Tables
    .const        >        L2SRAM_UMAP1               // Constant Data
    .switch       >        L2SRAM_UMAP1               // Jump Tables
    .text         >        L2SRAM_UMAP1               // Executable Code
    .text:_c_int00: align=1024 > L2SRAM_UMAP1         // Entrypoint

    GROUP (NEARDP_DATA)                       // group near data
    {
       .neardata
       .rodata
       .bss                                   // note: removed fill = 0
    }             >        L2SRAM_UMAP1
    .far: fill = 0x0, load > L2SRAM_UMAP1             // Far Global & Static Variables
    .fardata      >        L2SRAM_UMAP1               // Far RW Data
    .stack        >        L2SRAM_UMAP1               // Software System Stack
    .sysmem       >        L2SRAM_UMAP1               // Dynamic Memory Allocation Area

    .cio          >        L2SRAM_UMAP1               // C I/O Buffer

/*
    GROUP
    {
        .vects:      {. = align(8);}
        .l2_int:     {. = align(8);}
        .switch:     {. = align(8);}
        .const:      {. += 0x100;}
        .text:       {. = align(4);}
        .int_code:   {. = align(4);}
        .lib_code:   {. = align(4);}
        .sysinit:    {. = align(4);}
        .syssaram:   {. = align(4);}
        .far:	       {. = align(8);}
        .cinit:	     {. = align(4);}
        .pinit:	     {. = align(4);}
        .data16:	   {. = align(2);}
        .data:       {. = align(2);}
        .bss:	       {. = align(8);}

        .sysmem:     {. = align(16);}
         gem_l2ram_usr_init:   {. = align(8);}
         gem_l2ram_usr_uninit: {. = align(8);}
        .stack:	     {. = align(8);}
        .sysstack:   {. = align(8);}

   }	> L2SRAM_UMAP1
*/
   GROUP
   {
       .text0:       {. = align(4);}
       .umap0:      {. = align(8);}

   }	> L2SRAM_UMAP0
}
