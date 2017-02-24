/******************************************************************************
 * Copyright (c) 2013-2014, Texas Instruments Incorporated - http://www.ti.com/
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
#include <time.h>
#include <complex.h>
#include "../common/tune_com.h"

#include "cblas.h"
#ifdef __cplusplus
extern "C" {
#endif
#include "cblas.h"
#ifdef __cplusplus
}
#endif

/*-----------------------------------------------------------------------------
* Global Variables
*----------------------------------------------------------------------------*/
double complex alpha = 0.7 - 0.3*I; 
double complex beta  = 0.4 + 0.6*I;
enum CBLAS_ORDER     order  = CblasColMajor; 
enum CBLAS_TRANSPOSE transA = CblasNoTrans;
enum CBLAS_UPLO      uplo   = CblasUpper;

extern int TI_CBLAS_L3_OFFLOAD;

/*-----------------------------------------------------------------------------
* Prototypes
*----------------------------------------------------------------------------*/
int check_results(const double complex *C1, const double complex *C2, int N, int K);
int run_zsyrk_dsp_and_arm(int N, int K, float *time_dsp, float *time_arm, 
                          float *gflops_dsp, float *gflops_arm);

/*-----------------------------------------------------------------------------
* MAIN
*----------------------------------------------------------------------------*/
int main()
{
    int num_size, zsyrk_err;
    int N, K, n, k;
    int M_pre, N_pre, K_pre, M_start_size, N_start_size;
    int offload_threshold_1, offload_threshold_2;
    float total_GFLOPS_DSP, total_GFLOPS_ARM;
    float time_DSP, time_ARM, t_dsp, t_arm;
    char ofld_flag[NUM_MATRIX_SIZE_TO_BENCHMARK][NUM_MATRIX_SIZE_TO_BENCHMARK];
    char mem_flag[NUM_MATRIX_SIZE_TO_BENCHMARK][NUM_MATRIX_SIZE_TO_BENCHMARK];
    int skip_next_point;
    float diff_tmp, diff_pre;
    FILE *fp_flag, *fp_time, *fp_tbl;  
  
    fp_flag = fopen("ofld_flag_zsyrk.dat","w");
    fp_tbl  = fopen("ofld_tbl_zsyrk.c","w");
    fp_time = fopen("zsyrk_time_ARMvsDSP.dat","w");

    print_file_header(fp_tbl);
    fprintf(fp_tbl, "char ofld_tbl_zsyrk[SYRK_OFFLOAD_TBL_SIZE] = {\n");
    
    srand(12345);
    
    /* sweep K, and N */    
    for (N=TUNING_START_SIZE_RECTAN_MATRIX,n=0; n<NUM_MATRIX_SIZE_TO_BENCHMARK; n++,N*=2) 
    {
        for (K=TUNING_START_SIZE_RECTAN_MATRIX,k=0; k<NUM_MATRIX_SIZE_TO_BENCHMARK; k++,K*=2) 
        {
            if(  (n>0 && ofld_flag[n-1][k]==OFFLOAD)
               ||(k>0 && ofld_flag[n][k-1]==OFFLOAD) ) {
                ofld_flag[n][k] = OFFLOAD;
                mem_flag[n][k]  = HAS_MEMORY;  // to avoid error
                time_DSP = -1.0;
                time_ARM = -1.0;
                printf("Offloading. Skipping (N,K)=(%d,%d), (n,k)=(%d,%d).\n", N,K,n,k);
            }
            else if(  (n>0 && (mem_flag[n-1][k]==NO_MEMORY))
                    ||(k>0 && (mem_flag[n][k-1]==NO_MEMORY))) {
                ofld_flag[n][k] = NO_OFFLOAD;
                mem_flag[n][k]  = NO_MEMORY;
                time_DSP = -2.0;
                time_ARM = -2.0;
                printf("Out of memory. Skipping (N,K)=(%d,%d), (n,k)=(%d,%d).\n", N,K,n,k);
            }
            else {                    
                printf("Measuring DSP and ARM GFLOPS for (N,K)=(%d,%d), (n,k)=(%d,%d).\n", N,K,n,k);
                zsyrk_err = run_zsyrk_dsp_and_arm(N, K, &t_dsp, &t_arm, &total_GFLOPS_DSP, &total_GFLOPS_ARM);
          
                if(zsyrk_err == -1) {  /* out of memory for DSP offloading */
                    ofld_flag[n][k] = NO_OFFLOAD;
                    mem_flag[n][k] = NO_MEMORY;
                    time_DSP = -2.0;
                    time_ARM = -2.0;
                    printf("Out of memory, skipping next point.\n");
                }
                else {
                    mem_flag[n][k] = HAS_MEMORY;                    
                    time_DSP = t_dsp;
                    time_ARM = t_arm;
                    if (zsyrk_err == 0){
                        if(DSP_FASTER_THAN_ARM(t_dsp,t_arm)) {
                            ofld_flag[n][k] = OFFLOAD;
                            printf("Offloading to DSP for this point. Skipping next point.\n");
                        }
                        else {
                            ofld_flag[n][k] = NO_OFFLOAD;
                        }
                    }
                    else {
                        printf("Error in ZSYRK tuning for (N,K)=(%d,%d)!\n", N,K);
                        exit(0);
                    }
                }
            }
            
            fprintf(fp_flag, "%d\t%d\n", (int)mem_flag[n][k], (int)ofld_flag[n][k]);
            fprintf(fp_time, "%6d,%6d\t%10.8e\t%10.8e\n", N, K, time_ARM, time_DSP);

            if(   (n==(NUM_MATRIX_SIZE_TO_BENCHMARK-1))
               && (k==(NUM_MATRIX_SIZE_TO_BENCHMARK-1))) {
              fprintf(fp_tbl, "%d};", (int)ofld_flag[n][k]);
            } else {
              fprintf(fp_tbl, "%d,", (int)ofld_flag[n][k]);
            }
        }
        fprintf(fp_tbl, "\n");
    }
       
    fclose(fp_flag);
    fclose(fp_time);
    fclose(fp_tbl);
    
    return 0;
}

int run_zsyrk_dsp_and_arm(int N, int K, float *time_dsp, float *time_arm, 
                          float *gflops_dsp, float *gflops_arm)
{
    int   iter;
    long long i, size_A, size_C;
    float time_secs, total_time_dsp, total_time_arm;
    float gflops_ARM, gflops_DSP;
    float operation_count = 2.0*(float)N*(float)K;
    float total_GFLOPS_DSP = 0.0f;
    float total_GFLOPS_ARM = 0.0f;
    int    num_errors = 0;
    
    total_time_dsp = 0.0;
    total_time_arm = 0.0;
    size_A = (long long)N*(long long)K;
    size_C = (long long)N*(long long)N;
    if(  (size_A*sizeof(double complex)>(long long)0x0ffffffff) 
       ||(size_C*sizeof(double complex)>(long long)0x0ffffffff) ) {
        return (-1);
    }
	
    for (iter = 0; iter <= NUM_TEST_RUN; iter++)
    {      
      /*-------------------------------------------------------------------------
      * Allocate space for the matrices.  The matrices that will be passed to 
      * the DSP are allocated using device memory.  The Carm array is not passed
      * to the dsp and so can use system memory.
      *------------------------------------------------------------------------*/
      double complex *A    = (double complex *) __malloc_ddr(size_A*sizeof(double complex));
      double complex *Cdsp = (double complex *) __malloc_ddr(size_C*sizeof(double complex));
      double complex *Carm = (double complex *) malloc(size_C*sizeof(double complex));
  
      if (!A || !Cdsp || !Carm)
      {
          printf("Could not allocate enough space for the arrays!");
          if(A) __free_ddr(A);
          if(Cdsp) __free_ddr(Cdsp);
          if(Carm) free(Carm);
          
          return (-1);
      }
  
      /*-------------------------------------------------------------------------
      * Initialize matrices 
      *------------------------------------------------------------------------*/
      for (i = 0; i < size_A; ++i) 
	  {
          A[i] = (double)rand()/RAND_MAX + (double)rand()/RAND_MAX * I;
	  }

      for (i = 0; i < size_C; ++i)
	  {
          Cdsp[i] = Carm[i] = (double)rand()/RAND_MAX + (double)rand()/RAND_MAX * I;
      }
	  
      int lda = ((order == CblasColMajor && transA == CblasNoTrans) ||
              (order == CblasRowMajor && transA == CblasTrans)) ? N : K;
  
      int ldc = N;
    
      /*============ BLAS tuning: running on DSP and then on ARM =============*/
      /*------------------------------------------------------------------------
      * Time DSP zsyrk
      *-----------------------------------------------------------------------*/
      TI_CBLAS_L3_OFFLOAD = 1;
      
      tick();
      cblas_zsyrk(order,uplo,transA,N,K,&alpha,A,lda,&beta,Cdsp,ldc);
      time_secs = tock();
      if(iter > 0) { /* skip first iteration */
        total_time_dsp += time_secs;
        gflops_DSP = operation_count/time_secs*1e-9;
        total_GFLOPS_DSP += gflops_DSP;
      }
	  
      /*-------------------------------------------------------------------------
      * Time ARM zsyrk
      *------------------------------------------------------------------------*/
      TI_CBLAS_L3_OFFLOAD = 0;
      
      tick();
      cblas_zsyrk(order,uplo,transA,N,K,&alpha,A,lda,&beta,Carm,ldc);
      time_secs = tock();
      if(iter > 0) { /* skip first iteration */
        total_time_arm += time_secs;
        gflops_ARM = operation_count/time_secs*1e-9;
        total_GFLOPS_ARM += gflops_ARM;
      }
	  
      /*-------------------------------------------------------------------------
      * Verify Results
      *------------------------------------------------------------------------*/
      num_errors += check_results(Cdsp, Carm, N, N);
  
      __free_ddr(A);
      __free_ddr(Cdsp);
      free(Carm);
    }
    
    *gflops_dsp = total_GFLOPS_DSP;
    *gflops_arm = total_GFLOPS_ARM;
    *time_dsp   = total_time_dsp / (float)NUM_TEST_RUN;
    *time_arm   = total_time_arm / (float)NUM_TEST_RUN;
    
    return num_errors;
}


/*-----------------------------------------------------------------------------
* check_results
*----------------------------------------------------------------------------*/
int check_results(const double complex *C1, const double complex *C2, int M, int N)
{
    int i;
    const double EPISILON = 1e-5;
    //const double EPISILON = 1e-200;
    const int NERRORS  = 5;
    int       num_errors = 0;

    for (i=0; i<M*N; i++)
    {
        double delta = cabs(C1[i]) - cabs(C2[i]);

        if (delta > EPISILON*cabs(C1[i]))
            if ((num_errors += 1) < NERRORS)
                printf("Error [elem:%d]: %f <==> %f\n", i, cabs(C1[i]), cabs(C2[i]));
    }

    if (num_errors > 0)
    {
         printf("FAIL with %d errors!\n", num_errors);
         return num_errors;
    }
    else 
    {
        //printf("PASS!\n");
        return 0;
    }
}


