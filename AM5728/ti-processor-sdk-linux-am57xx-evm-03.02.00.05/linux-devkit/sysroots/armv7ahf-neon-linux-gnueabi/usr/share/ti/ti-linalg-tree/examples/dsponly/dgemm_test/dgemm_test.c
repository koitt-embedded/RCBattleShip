/******************************************************************************
 * Copyright (c) 2015, Texas Instruments Incorporated - http://www.ti.com
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
/******************************************************************************
* FILE: dgemm_test.c 
* Purpose: to test BLAS function DGEMM.
*
* DGEMM  performs one of the matrix-matrix operations
*
*    C := alpha*op( A )*op( B ) + beta*C,
*
*    where  op( X ) is one of
*
*    op( X ) = X   or   op( X ) = X**T,
*
* alpha and beta are scalars, and A, B and C are matrices, with op(A)
* an m by k matrix,  op(B) a k by n matrix and C an m by n matrix.
******************************************************************************/
#include <string.h>              
#include <stdio.h>
#include <omp.h>                 /* OpenMP header */
#include <ti/libarch/libarch.h>  /* Library Architecture header */
#include <ti/linalg/ticblas.h>   /* TI CBLAS API extension header */
#include <ti/linalg/cblas.h>     /* Standard CBLAS header */

extern void cleanup_after_ticblas();
extern void prepare_for_ticblas();
extern double omp_get_wtime(void);

void matrix_gen(double *A, double *B, double *C, int m, int k, int n);
void mat_mpy(const double * A, const double * B, double * C, int mat_N, 
             int mat_K, int mat_M, double alpha, double beta);
double dotprod(const double * A, const double * B, int n);
void print_matrix(double *mat, int m, int n);
double diff_matrix(double *mat1, double * mat2, int m, int n);

int main (int argc, char *argv[]) 
{
  double *A, *B, *C, *C_copy;  /* matrices */
  int m, n, k;                 /* matrix dimensions */
  double alpha, beta;          /* scalars for matrix multiplication */
  double precision_diff;       /* precision difference between TI DGEMM implementation
                                  and a reference implementation */
  double time, time_diff;      /* to compute time spent on DGEMM */
  double gflops;               /* convert time to GFLOPS */
  int nthreads, tid;           /* number of OpenMp threads and thread id */

  /* Verify OpenMP working properly */
  #pragma omp parallel private(nthreads, tid)
  {
    tid = omp_get_thread_num(); /* Obtain thread number */
    printf("Hello World from thread = %d\n", tid);

    /* Only master thread does this */
    if (tid == 0) {
      nthreads = omp_get_num_threads();
      printf("Number of threads = %d\n", nthreads);
    }

  }  /* All threads join master thread and disband */

  /* hard code dgemm parameters */
  m = k = n = 1000;
  alpha = 0.7; 
  beta  = 1.3; 

  /* Allocate memory for matrices */
  A = (double *)malloc( m*k*sizeof( double ) );
  B = (double *)malloc( k*n*sizeof( double ) );
  C = (double *)malloc( m*n*sizeof( double ) );
  C_copy = (double *)malloc( m*n*sizeof( double ) );
  if (A == NULL || B == NULL || C == NULL || C_copy == NULL) {
    printf( "\nERROR: Can't allocate memory for matrices. Aborting... \n\n");
    free(A);
    free(B);
    free(C);
    return 1;
  }   

  /* Initialize random number generator */    
  srand(123456789);

  /* Configure memory and initialize TI CBLAS */
  prepare_for_ticblas();

  /* Generate matrices */
  matrix_gen(A, B, C, m, k, n);
  memcpy(C_copy, C, m*n*sizeof(double));  

  /* Call standard CBLAS API to do matrix multiplication */
  time = omp_get_wtime();
  cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, m, n, k, alpha, A, k, B, n, beta, C, n);
  time_diff = omp_get_wtime() - time;
  gflops = ( 2.0 * m * n * k ) / time_diff / 1e9;
  printf("DGEMM time for (m,n,k) = (%d,%d,%d) is %e, GFLOPS is %e.\n", m,n,k, time_diff, gflops);

  /* Straightforward matrix multiplication as reference */
  mat_mpy(A, B, C_copy, m, n, k, alpha, beta);

  /* Find the difference between dgemm and reference */
  precision_diff = diff_matrix(C, C_copy, m, k);
  printf("Precision error is %e.\n", precision_diff);
 
  /* Finalize TI CBLAS and reconfigure memory */
  cleanup_after_ticblas();
  
  printf("DGEMM test finished and passed.\n");
  
  return 0;
}

/*==============================================================================
 * This function generates matrices of random data
 *============================================================================*/
void matrix_gen(double *A, double *B, double *C, int m, int k, int n)
{

    int i;
    for (i = 0; i < (m*k); i++) {
        A[i] = (double)rand()/RAND_MAX - 0.5;
    }

    for (i = 0; i < (k*n); i++) {
        B[i] = (double)rand()/RAND_MAX - 0.5;
    }

    for (i = 0; i < (m*n); i++) {
        C[i] = (double)rand()/RAND_MAX - 0.5;
    }
    
}


/******************************************************************************
* Straightforward implementation of matrix multiplication with row-major
******************************************************************************/
void mat_mpy(const double * A, const double * B, double * C, int mat_N, 
             int mat_K, int mat_M, double alpha, double beta)
{
    int col, row;
    double b_col[mat_K];

    for (col = 0; col < mat_M; ++col)
    {
        for (row = 0; row < mat_K; ++row)
            b_col[row] = B[row*mat_M+col];

        for (row = 0; row < mat_N; ++row)
            C[row*mat_M+col] =  alpha*dotprod(A + (row * mat_K), b_col, mat_K)
                              + beta*C[row*mat_M+col];
    }
}

/******************************************************************************
* dot product for matrix multiplication
******************************************************************************/
double dotprod(const double * A, const double * B, int n)
{
    int i;
    
    float result = 0;
    for (i = 0; i < n; ++i) result += A[i] * B[i];
    
    return result;
}

/******************************************************************************
* Print a row-major matrix
******************************************************************************/
void print_matrix(double *mat, int m, int n) 
{
   int i, j;
    
   for(i=0; i<m; i++) {
      for(j=0; j<n; j++) {
         printf( " %10.5f ", mat[i*n+j]);
      }
      printf( "\n" );
  }
}

/******************************************************************************
* Find the maximum absolute difference of two matrices
******************************************************************************/
double diff_matrix(double *mat1, double * mat2, int m, int n)
{
    int i, j;
    double abs_max_err, err;
    
    abs_max_err = 0.0f;
    for(i=0; i<m; i++) 
    {
       for(j=0; j<n; j++) 
       {
           err = fabs(mat1[i*n+j] - mat2[i*n+j]);
           if(abs_max_err < err) {
               abs_max_err = err;
           }
       }
    }
    
    return (abs_max_err);
}

/* Nothing past this point */
