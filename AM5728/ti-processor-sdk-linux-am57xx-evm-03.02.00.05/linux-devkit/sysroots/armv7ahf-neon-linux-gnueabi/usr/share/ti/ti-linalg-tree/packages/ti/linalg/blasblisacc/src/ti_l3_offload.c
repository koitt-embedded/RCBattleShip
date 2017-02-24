/******************************************************************************
 * Copyright (c) 2013-2015, Texas Instruments Incorporated - http://www.ti.com/
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
 
#include "ti_cblas_acc.h"

#define OFFLOAD_TO_DSP    1
#define NO_OFFLOAD_TO_DSP 0

#define TI_L3_OFFLOAD_SEARCH_SIZE_MIN_LOG2 3
#define TI_L3_OFFLOAD_SEARCH_SIZE_MIN      8
#define TI_L3_OFFLOAD_SEARCH_SIZE_MAX      (TI_L3_OFFLOAD_SEARCH_SIZE_MIN<<(NUM_PNT_EACH_DIM-1))

/* Function to calculate log2 of an integer */
static int log2_integer(int x)
{
    int i = 0;
	int y = x;
	
	while (x>>=1) {
	    i++;
	}

    /* rounding to log2(nearest power of 2)*/		
	if(y&(1<<(i-1))) {
	    i+=1;
	}
		
	return i;
}

/* Function to find the offloading decision for given (M,N,K) and lookup table */
static int l3_offload_dsp_3d(char *lookup_tbl, int M, int N, int K)
{
    int log2_M, log2_N, log2_K, tbl_ind;
	
    /* The lookup table covers M, N, and K ranging from TI_L3_OFFLOAD_SEARCH_SIZE_MIN
	   to TI_L3_OFFLOAD_SEARCH_SIZE_MAX. For sizes smaller than MIN, will not offload.
	   Lookup table will be improved in future with better granularity for smaller sizes.
    */	
    if((M<TI_L3_OFFLOAD_SEARCH_SIZE_MIN) || (N<TI_L3_OFFLOAD_SEARCH_SIZE_MIN)
       || (K<TI_L3_OFFLOAD_SEARCH_SIZE_MIN)) {
	   return (NO_OFFLOAD_TO_DSP);
	}
	
	if(M>TI_L3_OFFLOAD_SEARCH_SIZE_MAX) M=TI_L3_OFFLOAD_SEARCH_SIZE_MAX;
	if(N>TI_L3_OFFLOAD_SEARCH_SIZE_MAX) N=TI_L3_OFFLOAD_SEARCH_SIZE_MAX;
	if(K>TI_L3_OFFLOAD_SEARCH_SIZE_MAX) K=TI_L3_OFFLOAD_SEARCH_SIZE_MAX;
	
	log2_M = log2_integer(M);
	log2_N = log2_integer(N);
	log2_K = log2_integer(K);
	
	/* The lookup table is a 3-dimensional but stored linearly in memory */ 
	tbl_ind = (log2_M-TI_L3_OFFLOAD_SEARCH_SIZE_MIN_LOG2)*NUM_PNT_EACH_DIM*NUM_PNT_EACH_DIM
	         +(log2_N-TI_L3_OFFLOAD_SEARCH_SIZE_MIN_LOG2)*NUM_PNT_EACH_DIM
			 +(log2_K-TI_L3_OFFLOAD_SEARCH_SIZE_MIN_LOG2);
	return((int)(lookup_tbl[tbl_ind]));
}

/* Function to find the offloading decision for given (M,N) and lookup table */
static int l3_offload_dsp_2d(char *lookup_tbl, int M, int N)
{
    int log2_M, log2_N, tbl_ind;
	
    /* The lookup table covers M and N ranging from TI_L3_OFFLOAD_SEARCH_SIZE_MIN
	   to TI_L3_OFFLOAD_SEARCH_SIZE_MAX. For sizes smaller than MIN, will not offload.
	   Lookup table will be improved in future with better granularity for smaller sizes.
    */	
    if((M<TI_L3_OFFLOAD_SEARCH_SIZE_MIN) || (N<TI_L3_OFFLOAD_SEARCH_SIZE_MIN)) {
	   return (NO_OFFLOAD_TO_DSP);
	}
	
	if(M>TI_L3_OFFLOAD_SEARCH_SIZE_MAX) M=TI_L3_OFFLOAD_SEARCH_SIZE_MAX;
	if(N>TI_L3_OFFLOAD_SEARCH_SIZE_MAX) N=TI_L3_OFFLOAD_SEARCH_SIZE_MAX;
	
	log2_M = log2_integer(M);
	log2_N = log2_integer(N);
	
	/* The lookup table is a 2-dimensional but stored linearly in memory */ 
	tbl_ind = (log2_M-TI_L3_OFFLOAD_SEARCH_SIZE_MIN_LOG2)*NUM_PNT_EACH_DIM
	         +(log2_N-TI_L3_OFFLOAD_SEARCH_SIZE_MIN_LOG2);
	return((int)(lookup_tbl[tbl_ind]));
}

#define GEMM_OFFLOAD_DSP_DECISION(ofld_tbl)                              \
    int col_maj_m,col_maj_n,col_maj_k;                                   \
    if(Order == CblasColMajor) {                                         \
	    col_maj_m = M;                                                   \
	    col_maj_n = N;                                                   \
	    col_maj_k = K;                                                   \
	}                                                                    \
	else {                                                               \
	    col_maj_m = N;                                                   \
	    col_maj_n = M;                                                   \
	    col_maj_k = K;                                                   \
	}                                                                    \
	return l3_offload_dsp_3d(ofld_tbl, col_maj_m,col_maj_n,col_maj_k);

/* Function to decide whether to offload SGEMM based on (M,N,K) and Order */
int sgemm_offload_dsp(const enum CBLAS_ORDER Order, int M, int N, int K)
{
    GEMM_OFFLOAD_DSP_DECISION(ofld_tbl_sgemm);
}

/* Function to decide whether to offload DGEMM based on (M,N,K) and Order */
int dgemm_offload_dsp(const enum CBLAS_ORDER Order, int M, int N, int K)
{
    GEMM_OFFLOAD_DSP_DECISION(ofld_tbl_dgemm);
}

/* Function to decide whether to offload CGEMM based on (M,N,K) and Order */
int cgemm_offload_dsp(const enum CBLAS_ORDER Order, int M, int N, int K)
{
    GEMM_OFFLOAD_DSP_DECISION(ofld_tbl_cgemm);
}

/* Function to decide whether to offload ZGEMM based on (M,N,K) and Order */
int zgemm_offload_dsp(const enum CBLAS_ORDER Order, int M, int N, int K)
{
    GEMM_OFFLOAD_DSP_DECISION(ofld_tbl_zgemm);
}

#define MAP_SYMM_TO_GEMM        \
    int K;                      \
	if(Side==CblasLeft) {      \
        K = M;                  \
	}                           \
	else {                      \
	    K = N;                  \
	}

/* offloading decision for xSYMM and xHEMM is based on xGEMM */
int ssymm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                      int M, int N)
{
    MAP_SYMM_TO_GEMM
    GEMM_OFFLOAD_DSP_DECISION(ofld_tbl_sgemm)
}

int dsymm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                      int M, int N)
{
    MAP_SYMM_TO_GEMM	
    GEMM_OFFLOAD_DSP_DECISION(ofld_tbl_dgemm)
}

int csymm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                      int M, int N)
{
    MAP_SYMM_TO_GEMM	
    GEMM_OFFLOAD_DSP_DECISION(ofld_tbl_cgemm)
}

int zsymm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                      int M, int N)
{
    MAP_SYMM_TO_GEMM	
    GEMM_OFFLOAD_DSP_DECISION(ofld_tbl_zgemm)
}

int chemm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                      int M, int N)
{
    MAP_SYMM_TO_GEMM	
    GEMM_OFFLOAD_DSP_DECISION(ofld_tbl_cgemm)
}

int zhemm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                      int M, int N)
{
    MAP_SYMM_TO_GEMM	
    GEMM_OFFLOAD_DSP_DECISION(ofld_tbl_zgemm)
}

/* offloading decision for xSYRK and xHERK is based on xSYRK */
#define SYRK_OFFLOAD_DSP_DECISION(ofld_tbl)                              \
    int col_maj_n,col_maj_k;                                             \
    if(Order == CblasColMajor) {                                         \
	    col_maj_n = N;                                                   \
	    col_maj_k = K;                                                   \
	}                                                                    \
	else {                                                               \
	    col_maj_n = K;                                                   \
	    col_maj_k = N;                                                   \
	}                                                                    \
	return l3_offload_dsp_2d(ofld_tbl,col_maj_n,col_maj_k);
int ssyrk_offload_dsp(const enum CBLAS_ORDER Order, int N, int K)
{
    SYRK_OFFLOAD_DSP_DECISION(ofld_tbl_ssyrk);
}

int dsyrk_offload_dsp(const enum CBLAS_ORDER Order, int N, int K)
{
    SYRK_OFFLOAD_DSP_DECISION(ofld_tbl_dsyrk);
}

int csyrk_offload_dsp(const enum CBLAS_ORDER Order, int N, int K)
{
    SYRK_OFFLOAD_DSP_DECISION(ofld_tbl_csyrk);
}

int zsyrk_offload_dsp(const enum CBLAS_ORDER Order, int N, int K)
{
    SYRK_OFFLOAD_DSP_DECISION(ofld_tbl_zsyrk);
}

int cherk_offload_dsp(const enum CBLAS_ORDER Order, int N, int K)
{
    return csyrk_offload_dsp(Order,N,K);
}

int zherk_offload_dsp(const enum CBLAS_ORDER Order, int N, int K)
{
    return zsyrk_offload_dsp(Order,N,K);
}

/* offloading decision for xSYR2K and xHER2K is based on xSYRK */
int ssyr2k_offload_dsp(const enum CBLAS_ORDER Order, int N, int K)
{
    return ssyrk_offload_dsp(Order,N,K);
}

int dsyr2k_offload_dsp(const enum CBLAS_ORDER Order, int N, int K)
{
    return dsyrk_offload_dsp(Order,N,K);
}

int csyr2k_offload_dsp(const enum CBLAS_ORDER Order, int N, int K)
{
    return csyrk_offload_dsp(Order,N,K);
}

int zsyr2k_offload_dsp(const enum CBLAS_ORDER Order, int N, int K)
{
    return zsyrk_offload_dsp(Order,N,K);
}

int cher2k_offload_dsp(const enum CBLAS_ORDER Order, int N, int K)
{
    return csyrk_offload_dsp(Order,N,K);
}

int zher2k_offload_dsp(const enum CBLAS_ORDER Order, int N, int K)
{
    return zsyrk_offload_dsp(Order,N,K);
}

/* offloading decision for xTRMM */
#define TRMM_OFFLOAD_DSP_DECISION(ofld_tbl)                              \
    int col_maj_m,col_maj_n;                                             \
    if(Order == CblasColMajor) {                                         \
	    col_maj_m = M;                                                   \
	    col_maj_n = N;                                                   \
	}                                                                    \
	else {                                                               \
	    col_maj_m = N;                                                   \
	    col_maj_n = M;                                                   \
	}                                                                    \
	return l3_offload_dsp_2d(ofld_tbl,col_maj_m,col_maj_n);
int strmm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                      int M, int N)
{
    TRMM_OFFLOAD_DSP_DECISION(ofld_tbl_strmm)
}

int dtrmm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                      int M, int N)
{
    TRMM_OFFLOAD_DSP_DECISION(ofld_tbl_dtrmm)
}

int ctrmm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                      int M, int N)
{
    TRMM_OFFLOAD_DSP_DECISION(ofld_tbl_ctrmm)
}

int ztrmm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                      int M, int N)
{
    TRMM_OFFLOAD_DSP_DECISION(ofld_tbl_ztrmm)
}

/* offloading decision for xTRSM */
#define TRSM_OFFLOAD_DSP_DECISION(ofld_tbl)                              \
    int col_maj_m,col_maj_n;                                             \
    if(Order == CblasColMajor) {                                         \
	    col_maj_m = M;                                                   \
	    col_maj_n = N;                                                   \
	}                                                                    \
	else {                                                               \
	    col_maj_m = N;                                                   \
	    col_maj_n = M;                                                   \
	}                                                                    \
	return l3_offload_dsp_2d(ofld_tbl,col_maj_m,col_maj_n);
int strsm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                      int M, int N)
{
    TRSM_OFFLOAD_DSP_DECISION(ofld_tbl_strsm)
}

int dtrsm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                      int M, int N)
{
    TRSM_OFFLOAD_DSP_DECISION(ofld_tbl_dtrsm)
}

int ctrsm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                      int M, int N)
{
    TRSM_OFFLOAD_DSP_DECISION(ofld_tbl_ctrsm)
}

int ztrsm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                      int M, int N)
{
    TRSM_OFFLOAD_DSP_DECISION(ofld_tbl_ztrsm)
}
