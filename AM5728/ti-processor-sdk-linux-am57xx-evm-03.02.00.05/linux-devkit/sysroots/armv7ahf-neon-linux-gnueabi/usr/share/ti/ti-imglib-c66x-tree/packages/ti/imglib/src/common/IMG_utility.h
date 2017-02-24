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

#ifndef IMG_UTILITY_H_
#define IMG_UTILITY_H_ 1


/* Number of significant digits in cycle formula display */
#define img_PROFILE_SIG_DIGIT   5

/* Kernel routine type enumeration (must not use explicit numbering) */
enum {
  img_KERNEL_OPT,             // Kernel type optimized (C-intrinsics, assembly)
  img_KERNEL_CN,              // Kernel type natural C 
  img_KERNEL_CNT              
};

/* Global test case index */
extern int test_index;          // Index of current active test
extern int testcases;           // Total test cases (in KERNEL_idat.c)
extern int act_kernel;          // Active kernel type for test and profile


/* Utility routine  */
extern void IMG_error_handler (void);
extern void IMG_print_float   (float num);


/* Standardized assertion utility */
static inline void IMG_assert (int assertion, char *err_string)
{
  if (!assertion) {
    /* Display start of error message */
    printf ("Assertion Error");
    
    /* Display test if relavent */
    if (test_index > 0) {
      printf (" (Test %d)", test_index);
    }

    /* Display remainder of error message */
    printf (": %s\n", err_string);

    /* Call error handler */
    IMG_error_handler ();
  }
}

#endif

/* =========================================================================*/
/*  End of file:  IMG_utility.h                                             */
/* =========================================================================*/
