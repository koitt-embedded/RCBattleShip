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
#ifndef TI_CBLAS_ACC_H
#define TI_CBLAS_ACC_H

#ifdef __cplusplus
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <fstream>
#define __CL_ENABLE_EXCEPTIONS
#include <CL/cl.hpp>
using namespace std;
using namespace cl;
/* Both cl and std namespace define size_t, so we must be explicit */
#define size_t ::size_t
#ifndef TI_CBLAS_FAT_BINARY
#include "ocl_util.h"
#endif
#else
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <assert.h>
#include <memory.h>
#include <CL/cl.h>
#include <CL/cl_ext.h>
#endif

extern int ti_cblas_disable_debug;

/* useful macros */
#ifdef TI_CBLAS_DEBUG
#define TI_CBLAS_DEBUG_PRINT(...) { if (! ti_cblas_disable_debug) { fprintf(stderr,"TI_CBLAS DEBUG: "); fprintf(stderr, __VA_ARGS__); } }
#else
#define TI_CBLAS_DEBUG_PRINT(...)
#endif

#define TI_CBLAS_ERROR_PRINT(...) { fprintf(stderr,"TI_CBLAS ERROR: "); fprintf(stderr, __VA_ARGS__); }
#define TI_CBLAS_ERROR_EXIT(...) { fprintf(stderr,"TI_CBLAS ERROR: "); fprintf(stderr, __VA_ARGS__); exit(1); }
#define TI_CBLAS_OCL_CHKERROR(A, B) if (B != CL_SUCCESS) { TI_CBLAS_ERROR_PRINT("opencl %s, error %d\n", A, B); exit(B); }

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define XOR(a,b) ((!(a)) != (!(b)))
#define XOR3(a,b,c) (((!(a)) != (!(b))) == (!(c)))

/* Profiling support */
#ifdef TI_CBLAS_PROFILE
#define TI_CBLAS_CLOCK CLOCK_REALTIME
#define clock_diff ((clock2.tv_sec-clock1.tv_sec)*1e6 + (clock2.tv_nsec-clock1.tv_nsec)/1e3)
#define TI_CBLAS_PROFILE_PRINT(...) fprintf(stderr,"TI_CBLAS PROFILE: "); fprintf(stderr, __VA_ARGS__);
#define TI_CBLAS_PROFILE_START() struct timespec clock1; clock_gettime(TI_CBLAS_CLOCK, &clock1);
#define TI_CBLAS_PROFILE_REPORT(...) struct timespec clock2; clock_gettime(TI_CBLAS_CLOCK, &clock2); TI_CBLAS_PROFILE_PRINT(__VA_ARGS__)

#else /* TI_CBLAS_PROFILE */
#define TI_CBLAS_PROFILE_PRINT(...)
#define TI_CBLAS_PROFILE_START()
#define TI_CBLAS_PROFILE_REPORT(...)
#define TI_CBLAS_PROFILE_OCL_REPORT()
#endif /* TI_CBLAS_PROFILE */

#ifdef __cplusplus
extern "C" {
#endif

#include "cblas.h"
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
#include "blis.h"
#ifdef __cplusplus
}
#endif

/* offload control */
/* NONE: Execute on ARM only */
/* DSP : Force offload to DSP */
/* SIZE:Decision to offload or not is decided based on size */
#define TI_CBLAS_OFFLOAD_NONE 0
#define TI_CBLAS_OFFLOAD_DSP 1
#define TI_CBLAS_OFFLOAD_SIZE 2

/* Global functions and variables */
extern void ti_cblas_error(const char* msg, int code);
extern void ti_cblas_init(void);

extern err_t bli_finalize();
extern err_t bli_init();

void ti_cblas_auto_finalize(void);

void ti_cblas_mem_free(void *ptr);
void *ti_cblas_mem_alloc(size_t size);

extern pthread_cond_t   CV;
extern pthread_mutex_t  MUTEX;


extern Kernel*              ti_cblas_get_kernel(const char *fname);
int                         ti_cblas_delete_kernel(Kernel* K);
extern Context*             ti_cblas_ocl_context;
extern std::vector<Device>* ti_cblas_ocl_devices;
extern CommandQueue*        ti_cblas_ocl_Q;
extern Program::Binaries*   ti_cblas_ocl_binary;
extern Program*             ti_cblas_ocl_program;

extern int ti_cblas_init_done;
extern int ti_cblas_offload;

/* Level 3 kernels offload table */
/* Number of points in each dimension. ARM processing and DSP processing time
   are measured for each point to determine offload or not. */
#define NUM_PNT_EACH_DIM 16

/* Offload table size */
#define GEMM_OFFLOAD_TBL_SIZE (NUM_PNT_EACH_DIM*NUM_PNT_EACH_DIM*NUM_PNT_EACH_DIM)
#define SYRK_OFFLOAD_TBL_SIZE (NUM_PNT_EACH_DIM*NUM_PNT_EACH_DIM)
#define TRMM_OFFLOAD_TBL_SIZE (NUM_PNT_EACH_DIM*NUM_PNT_EACH_DIM)
#define TRSM_OFFLOAD_TBL_SIZE (NUM_PNT_EACH_DIM*NUM_PNT_EACH_DIM)

/* compile time defaults */
#ifndef TI_CBLAS_OFFLOAD_DEF
#define TI_CBLAS_OFFLOAD_DEF "002"
#endif

/* macros used for BLAS/LAPACK buffer size calculations */
#define BLAS_ORD(Order,a,b) ((Order==CblasRowMajor)? (a):(b))
#define BLAS_TRN(Trans,a,b) ((Trans==CblasNoTrans)? (a):(b))
#define BLAS_SIDE(Side,a,b) ((Side==CblasLeft)?(a):(b))
#define BLAS_ORD_T(Order,Trans,a,b) (XOR((Order==CblasRowMajor),(Trans==CblasNoTrans))?(b):(a))
#define BLAS_ORD_S(Order,Side,a,b) (XOR((Order==CblasRowMajor),((Side=='L')||(Side=='l')||(Side==CblasLeft)))?(b):(a))
#define BLAS_ORD_TS(Order,Trans,Side,a,b) (XOR3((Order==CblasRowMajor),(Trans==CblasNoTrans),((Side=='L')||(Side=='l')||(Side==CblasLeft)))?(b):(a))

extern int TI_CBLAS_L1_OFFLOAD;
extern int TI_CBLAS_L2_OFFLOAD;
extern int TI_CBLAS_L3_OFFLOAD;

/* Allocated MSMC/L3 */
#ifdef MEM_MODEL_Large
#  define MSMC_BUF_SIZE 0x47FDC0          /* 4.5MB */
#else
#  ifdef MEM_MODEL_Medium
#    define MSMC_BUF_SIZE (5*512*1024UL)  /* 2.5MB */ 
#  else
#    ifdef MEM_MODEL_Small
#      define MSMC_BUF_SIZE (1024UL*1024UL) /* 1MB */
#    endif
#  endif
#endif

#define DDR_BUF_SIZE (16384)

extern char ofld_tbl_sgemm[GEMM_OFFLOAD_TBL_SIZE];
extern char ofld_tbl_dgemm[GEMM_OFFLOAD_TBL_SIZE];
extern char ofld_tbl_cgemm[GEMM_OFFLOAD_TBL_SIZE];
extern char ofld_tbl_zgemm[GEMM_OFFLOAD_TBL_SIZE];
extern char ofld_tbl_ssyrk[SYRK_OFFLOAD_TBL_SIZE];
extern char ofld_tbl_dsyrk[SYRK_OFFLOAD_TBL_SIZE];
extern char ofld_tbl_csyrk[SYRK_OFFLOAD_TBL_SIZE];
extern char ofld_tbl_zsyrk[SYRK_OFFLOAD_TBL_SIZE];
extern char ofld_tbl_strmm[TRMM_OFFLOAD_TBL_SIZE];
extern char ofld_tbl_dtrmm[TRMM_OFFLOAD_TBL_SIZE];
extern char ofld_tbl_ctrmm[TRMM_OFFLOAD_TBL_SIZE];
extern char ofld_tbl_ztrmm[TRMM_OFFLOAD_TBL_SIZE];
extern char ofld_tbl_strsm[TRSM_OFFLOAD_TBL_SIZE];
extern char ofld_tbl_dtrsm[TRSM_OFFLOAD_TBL_SIZE];
extern char ofld_tbl_ctrsm[TRSM_OFFLOAD_TBL_SIZE];
extern char ofld_tbl_ztrsm[TRSM_OFFLOAD_TBL_SIZE];
extern int sgemm_offload_dsp(const enum CBLAS_ORDER Order, int M, int N, int K);
extern int dgemm_offload_dsp(const enum CBLAS_ORDER Order, int M, int N, int K);
extern int cgemm_offload_dsp(const enum CBLAS_ORDER Order, int M, int N, int K);
extern int zgemm_offload_dsp(const enum CBLAS_ORDER Order, int M, int N, int K);
extern int ssymm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                             int M, int N);
extern int dsymm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                             int M, int N);
extern int csymm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                             int M, int N);
extern int zsymm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                             int M, int N);
extern int chemm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                             int M, int N);
extern int zhemm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                             int M, int N);
extern int ssyrk_offload_dsp(const enum CBLAS_ORDER Order, int N, int K);
extern int dsyrk_offload_dsp(const enum CBLAS_ORDER Order, int N, int K);
extern int csyrk_offload_dsp(const enum CBLAS_ORDER Order, int N, int K);
extern int zsyrk_offload_dsp(const enum CBLAS_ORDER Order, int N, int K);
extern int cherk_offload_dsp(const enum CBLAS_ORDER Order, int N, int K);
extern int zherk_offload_dsp(const enum CBLAS_ORDER Order, int N, int K);
extern int ssyr2k_offload_dsp(const enum CBLAS_ORDER Order, int N, int K);
extern int dsyr2k_offload_dsp(const enum CBLAS_ORDER Order, int N, int K);
extern int csyr2k_offload_dsp(const enum CBLAS_ORDER Order, int N, int K);
extern int zsyr2k_offload_dsp(const enum CBLAS_ORDER Order, int N, int K);
extern int cher2k_offload_dsp(const enum CBLAS_ORDER Order, int N, int K);
extern int zher2k_offload_dsp(const enum CBLAS_ORDER Order, int N, int K);
extern int strmm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                             int M, int N);
extern int dtrmm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                             int M, int N);
extern int ctrmm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                             int M, int N);
extern int ztrmm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                             int M, int N);
extern int strsm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                             int M, int N);
extern int dtrsm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                             int M, int N);
extern int ctrsm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                             int M, int N);
extern int ztrsm_offload_dsp(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, 
                             int M, int N);

#endif

