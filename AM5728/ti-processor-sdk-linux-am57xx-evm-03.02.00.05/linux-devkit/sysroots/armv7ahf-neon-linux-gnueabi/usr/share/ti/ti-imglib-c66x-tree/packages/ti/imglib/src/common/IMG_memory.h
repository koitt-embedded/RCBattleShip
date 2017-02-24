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

#ifndef IMG_MEMORY_H_
#define IMG_MEMORY_H_ 1

/* Memory utility includes */
#include <string.h>
#include "IMG_utility.h"


/* Handle COFF/ELF for linker cmd file symbols */
#if defined(__TI_EABI__)
#define kernel_size _kernel_size
#endif

/* External symbols used for kernel size calculation */
extern char kernel_size;

/* Input and number of test cases variables */
extern int in_data[]; 
extern int out_data[];


/* Memory handling utilities in IMG_memory.c */
extern void IMG_copy_int_to_char  (char  *restrict dst, int *restrict src, int elements);
extern void IMG_copy_int_to_short (short *restrict dst, int *restrict src, int elements);
extern void IMG_compare_mem       (void *a, void *b, int n);


/* Memory clear (to zero) utility */
static inline void IMG_clear_memory (void *ptr, int size)
{
  memset (ptr, 0, size);
}


/* INT to INT memory copy utility */
static inline void IMG_copy_int_to_int (int *restrict dst, int *restrict src, int elements)
{
  memcpy (dst, src, elements * sizeof(int));
}


/* INT to UNSIGNED CHAR memory copy utility */
static inline void IMG_copy_int_to_uchar (unsigned char *restrict dst, int *restrict src, 
                                          int elements)
{
  IMG_copy_int_to_char ((char *) dst, src, elements);
}


/* INT to UNSIGNED SHORT memory copy utility */
static inline void IMG_copy_int_to_ushort (unsigned short *restrict dst, int *restrict src, 
                                           int elements)
{
  IMG_copy_int_to_short ((short *) dst, src, elements);
}


/* INT to UNSIGNED INT memory copy utility */
static inline void IMG_copy_int_to_uint (unsigned int *restrict dst, int *restrict src, 
                                         int elements)
{
  IMG_copy_int_to_int ((int *) dst, src, elements);
}


/* Display memory reqirements */
static inline void IMG_kernel_memory (void)
{
  /* Provide memory information */
  printf("Memory:  %d bytes\n", &kernel_size);
}

#endif

/* =========================================================================*/
/*  End of file:  IMG_memory.h                                              */
/* =========================================================================*/
