/******************************************************************************
 * Copyright (c) 2013-2016, Texas Instruments Incorporated - http://www.ti.com/
 *   All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions are met:
 *       * Redistributions of source code must retain the above copyright
 *         notice, this list of conditions and the following disclaimer.
 *       * Redistributions in binary form must reproduce the above copyright
 *         notice, this list of conditions and the following disclaimer in the
 *         documentation and/or other materials provided with the distribution.
 *       * Neither the name of Texas Instruments Incorporated nor the
 *         names of its contributors may be used to endorse or promote products
 *         derived from this software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 *   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 *   THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <complex.h>

#define EPISILON 1e-5
#define DELTA    1e-5
#define NERRORS  5


#define DISPLAY_ERROR_MESSAGE(num_errs) \
    if (num_errs > 0) { \
         printf("FAIL with %d errors!\n", num_errs); \
    } \
    else { \
        printf("PASS!\n"); \
    }

/*-----------------------------------------------------------------------------
* Compare two single precision real matrices
*----------------------------------------------------------------------------*/
int comp_matrix(const float *C1, const float *C2, int M, int N)
{
    long long i;
    int num_errors = 0;

    for (i=0; i<(long long)M*N; i++)
    {
        float norm;
        float delta = fabsf(C1[i] - C2[i]);
        if(fabsf(C1[i]) > fabsf(C2[i])) {
            norm = fabsf(C1[i]);
        }
        else {
            norm = fabsf(C2[i]);
        }

        if ( (delta > EPISILON*norm) && (delta > DELTA)) {
            if ((num_errors += 1) < NERRORS) {
                printf("Error [elem:%d]: %e <==> %e\n", i, C1[i], C2[i]);
            }
        }
    }

    if (num_errors > 0) {
         printf("FAIL with %d errors!\n", num_errors);
    }
    else {
        printf("PASS!\n");
    }

    return num_errors;
}

/*-----------------------------------------------------------------------------
* Compare two double precision real matrices
*----------------------------------------------------------------------------*/
int comp_matrix_double(const double *C1, const double *C2, int M, int N)
{
    long long i;
    double norm;
    int    num_errors = 0;

    for (i=0; i<(long long)M*N; i++)
    {
        double norm;
        double delta = fabs(C1[i] - C2[i]);
        if(fabs(C1[i]) > fabs(C2[i])) {
            norm = fabs(C1[i]);
        }
        else {
            norm = fabs(C2[i]);
        }

        if ( (delta > EPISILON*norm) && (delta > DELTA)) {
            if ((num_errors += 1) < NERRORS) {
                printf("Error [elem:%d]: %e <==> %e\n", i, C1[i], C2[i]);
            }
        }
    }

    if (num_errors > 0) {
         printf("FAIL with %d errors!\n", num_errors);
    }
    else {
        printf("PASS!\n");
    }

    return num_errors;
} /* comp_matrix_double */

/*-----------------------------------------------------------------------------
* Compare two single precision complex matrices
*----------------------------------------------------------------------------*/
int comp_matrix_complex(const float complex *C1, const float complex *C2, int M, int N)
{
    long long i;
    int num_errors = 0;

    for (i=0; i<(long long)M*N; i++)
    {
        float norm;
        float delta = cabsf(C1[i] - C2[i]);
        if(cabsf(C1[i]) > cabsf(C2[i])) {
            norm = cabsf(C1[i]);
        }
        else {
            norm = cabsf(C2[i]);
        }

        if ( (delta > EPISILON*norm) && (delta > DELTA)) {
            if ((num_errors += 1) < NERRORS) {
                printf("Error [elem:%d]: %e + %e*j <==> %e + %e*j\n", i, 
                       crealf(C1[i]), cimagf(C1[i]), crealf(C2[i]), cimagf(C2[i]));
            }
        }
    }

    if (num_errors > 0) {
         printf("FAIL with %d errors!\n", num_errors);
    }
    else {
        printf("PASS!\n");
    }

    return num_errors;
} /* comp_matrix_complex */


/*-----------------------------------------------------------------------------
* Compare two double precision complex matrices
*----------------------------------------------------------------------------*/
int comp_matrix_double_complex(const double complex *C1, const double complex *C2, int M, int N)
{
    long long i;
    int num_errors = 0;

    for (i=0; i<(long long)M*N; i++)
    {
        double norm;
        double delta = cabs(C1[i] - C2[i]);
        if(cabs(C1[i]) > cabs(C2[i])) {
            norm = cabs(C1[i]);
        }
        else {
            norm = cabs(C2[i]);
        }

        if ( (delta > EPISILON*norm) && (delta > DELTA)) {
            if ((num_errors += 1) < NERRORS) {
                printf("Error [elem:%d]: %e + %e*j <==> %e + %e*j\n", i, 
                       creal(C1[i]), cimag(C1[i]), creal(C2[i]), cimag(C2[i]));
            }
        }
    }

    DISPLAY_ERROR_MESSAGE(num_errors);
    
    return num_errors;
} /* comp_matrix_double_complex */

