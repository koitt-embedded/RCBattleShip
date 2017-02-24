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

/* Profiling includes */
#include "IMG_profile.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/* Profiling globals */
int     est_order;    // Order for the pseudo-inverse (2/3)
int     est_count;    // Number of tests used in estimating formula
int     est_test;     // Use current test in formula estimation
clock_t beg_count;    // Begin cycle count for profiling
clock_t end_count;    // End cycle count for profiling
clock_t overhead;     // Cycle profiling overhead
clock_t cycles[img_KERNEL_CNT];  // Cycle counts for C-natural and optimized

/* Pointers for global matrices and vectors */
int   *AA[img_PROFILE_MAX_TESTS];
float *xx;
int   *bb;


/****************************************************************************
 *  Local Function: IMG_CHOLESKY_DECOMP
 *
 *  void img_cholesky_decomp 
 *  (
 *      double **U,   - Pointer to upper triangular portion of symmetric
 *                      positive definite matrix A'A
 *      double **L,   - Pointer to lower triangular matrix L that satisfies
 *                      A'A = LL'
 *      short sz      - A'A and L matrix size (square) 
 *  )
 *  
 *  Description: 
 *
 ****************************************************************************/
void img_cholesky_decomp (double **U, double **L, short sz)
{
  double  sum;
  short   i, j, k;

  /* Solve for L using LL' = U */
  for (i=0; i<sz; i++) {
    for (j=i; j<sz; j++) {
      sum = U[i][j];
      for (k=i-1; k>=0; k--) {
        sum -= L[i][k] * L[j][k];
      }
      if (i == j) {
        IMG_assert (sum > 0, "Matrix A'A is not positive-definite");
        L[i][i] = sqrt(sum);
      }
      else {
        L[j][i] = sum / L[i][i];
      }
    }
  }
}

/****************************************************************************
 *  Local Function: IMG_CHOLESKY_BACKSUB
 *
 *  void img_cholesky_backsub 
 *  (
 *      double **L,   - Pointer to lower triangular solution from 
 *                      img_cholesky_decomp().
 *      double  *b,   - Pointer to vector from equation A'Ax = b 
 *      float   *x,   - Pointer to solution vector (output) 
 *      short   sz    - Lengths of b and x, square size of L
 *  )
 *  
 *  Description: Displays the estimated cycle formula
 *
 ****************************************************************************/
void img_cholesky_backsub (double **L, double *b, float *x, short sz)
{
  double  z[img_PROFILE_MAX_ORDER];
  double  sum;
  short   i, k;

  /* Back-sub:  Lz = y to solve for z  (where z = L'x) */
  for (i=0; i<sz; i++) {
    sum = b[i];
    for (k=i-1; k>=0; k--) {
      sum -= L[i][k] * (double) z[k];
    }
    z[i] = sum / L[i][i];
  }

  /* Back-sub:  L'x = z to solve for x  */
  for (i=sz-1; i>=0; i--) {  
    sum = z[i];
    for (k=i+1; k<sz; k++) {
      sum -= L[k][i] * x[k];
    }
    x[i] = (float) (sum / L[i][i]);
  }
}


/****************************************************************************
 *  Function: IMG_PRINT_FORMULA
 *
 *  void IMG_print_formula
 *  (
 *      float *x      - Solution to cycle formula
 *  )
 *  
 *  Description: Displays the estimated cycle formula
 *
 ****************************************************************************/
void IMG_print_formula (float *x)
{
  float C = x[1];

  /* Print start of cycle formula string */
  printf("Cycles:  ");

  /* Provide profiling information for x[0] and multiplier (N) */
  IMG_print_float (x[0]);
  printf("*N + ");

  /* If third/fourth order, provide 2nd variable output */
  if (est_order > 2) {
    /* Provide profiling information for x[1] and multiplier (M) */
    IMG_print_float (x[1]);
    printf("*M + ");
    /* Change the constant (overhead) cycles */
    C = x[2];
  }

  /* If fourth order, provide 3rd variable output */
  if (est_order > 3) {
    /* Provide profiling information for x[2] and multiplier (L) */
    IMG_print_float (x[2]);
    printf("*L + ");
    /* Change the constant (overhead) cycles */
    C = x[3];
  }

  /* Provide remainder of formula */
  printf("%d\n", (int) C);
}


/****************************************************************************
 *  Function: IMG_PSEUDO_INVERSE
 *
 *  void IMG_pseudo_inverse
 *  (
 *      int   **A,  - Matrix of parameters for each test performed.  Each 
 *                    row of the matrix holds all parameters for a single test.  
 *                    This includes a 1 for cycle overhead.  
 *      int   *b,   - Vector of cycle counts for each test case.  Holds one
 *                    value per test applied towards formula estimation.
 *      float *x,   - Returned (linear) equation values.  There will as many
 *                    values as the order of the estimation.
 *      short  m,   - Number of test cases (length of b, columns in A)
 *      short  n,   - Order of inverse (rows in A')
 *  )
 *  
 *  Description: Finds the solution to an overdetermined set of linear
 *               equations with N unknowns (currently maximum of 4). It is assumed 
 *               that the equations are of the form:
 *
 *                  b[i] = a[i][0]*x[0] + a[i][1]*x[1] + ... + x[N-1]
 *
 *               The best fit may be found using the Moore-Penrose pseudo-inverse. 
 *               Since A'A is positive-definite, we employ Cholesky decomposition 
 *               and back substitution for the matrix inverse.
 *
 *               The approach follows:
 *
 *                       Ax   = b       (where A is MxN with M>=N over-determined)
 *
 *                       A'Ax = A'b
 *
 *                       Mx   = y       (where M = A'A and y = A'b)
 *
 *                       LL'x = y       (Cholesky for LL' decomposition)
 *                        
 *                       Lz   = y       (where z = L'x)
 *
 *                    Solve for "z" using back substitution
 *
 *                       L'x  = z
 *                       
 *                    Solve for "x" using back substitution (again)
 *
 ****************************************************************************/
void IMG_pseudo_inverse (int **A, int *b, float *x, short m, short n)
{
  double *U [img_PROFILE_MAX_ORDER];
  double *L [img_PROFILE_MAX_ORDER];
  double  y [img_PROFILE_MAX_ORDER];
  double  sum;
  short   i, j, k;

  /* Allocate U & L matrices */
  for (i=0; i<n; i++) {
    U[i] = (double *) malloc (n * sizeof(double));
    L[i] = (double *) malloc (n * sizeof(double));
  }

  /* Create A'A = U (symmetric, upper-triangular only) */
  for (i=0; i<n; i++) {
    for (j=i; j<n; j++) {
      sum = (double) 0.0;
      for (k=0; k<m; k++) {
        sum += (double) A[k][i] * (double) A[k][j];
      }
      U[i][j] = sum;
    }
  }

  /* Use Cholesky decomposition to get L */
  img_cholesky_decomp (U, L, n);

  /* Create A'b = y for Cholesky solution */
  for (i=0; i<n; i++) {
    sum = (double) 0;
    for (j=0; j<m; j++) {
      sum += (double) A[j][i] * b[j];
    }
    y[i] = sum;
  }

  /* Use L,L' to solve for x */
  img_cholesky_backsub (L, y, x, n);

  /* Free U & L matrices */
  for (i=0; i<n; i++) {
    free(U[i]);
    free(L[i]);
  }

  /* Round overhead to integer */
  x[n-1] = (float) ((int) (x[n-1] + 0.5));
}

/* =========================================================================*/
/*  End of file:  IMG_profile.c                                             */
/* =========================================================================*/


