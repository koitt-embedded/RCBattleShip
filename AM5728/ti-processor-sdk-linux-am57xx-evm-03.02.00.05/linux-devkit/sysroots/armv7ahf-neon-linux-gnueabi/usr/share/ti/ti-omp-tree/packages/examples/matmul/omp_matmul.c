/******************************************************************************
* OpenMP Example - Matrix-vector multiplication - C/C++ Version
* FILE: omp_matvec.c
* DESCRIPTION:
*   This example multiplies all row i elements of matrix A with vector
*   element b(i) and stores the summed products in vector c(i).  A total is
*   maintained for the entire matrix.  Performed by using the OpenMP loop
*   work-sharing construct.  The update of the shared global total is
*   serialized by using the OpenMP critical directive.
* SOURCE: Blaise Barney  5/99
* LAST REVISED: 12/13
******************************************************************************/

#include <ti/runtime/openmp/omp.h>
#include <stdio.h>

#define SIZE (512)

float A[SIZE][SIZE], b[SIZE], c[SIZE], total;

void main()
{

    int i, j;

    /* Initializations */
    total = 0.0;
    for (i=0; i < SIZE; i++)
    {
        for (j=0; j < SIZE; j++)
            A[i][j] = (j+1) * 1.0;
        b[i] = 1.0 * (i+1);
        c[i] = 0.0;
    }

    /* Create a team of threads and scope variables */
#pragma omp parallel shared(A,b,c,total) private(i)
    {
        /* Loop work-sharing construct - distribute rows of matrix */
#pragma omp for private(j)
        for (i=0; i < SIZE; i++)
        {
            for (j=0; j < SIZE; j++)
                c[i] += (A[i][j] * b[i]);
        }   /* end of parallel i loop */

    } /* end of parallel construct */
}

