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
#include "../../cblas/include/cblas.h"
#include "../../ticblas/ticblas.h"

/*==============================================================================
 * This file contains functions of the DSP OpenCL layer of ARM+DSP CBLAS library.
 *============================================================================*/

extern int blas_mem_config(void *msmc_buf, size_t msmc_buf_size, void *ddr_buf, size_t ddr_buf_size, 
                             size_t *l1D_SRAM_size_orig, size_t *l2_SRAM_size_orig);
extern int blas_mem_reconfig(size_t l1D_SRAM_size_orig, size_t l2_SRAM_size_orig);


void cblas_caxpy_facade(const int N, const void *alpha, const void *X, const int incX, void *Y, const int incY)
{
	cblas_caxpy(N, alpha, X, incX, Y, incY);
}

void cblas_ccopy_facade(const int N, const void *X, const int incX, void *Y, const int incY)
{
	cblas_ccopy(N, X, incX, Y, incY);
}

void cblas_cdotc_sub_facade(const int N, const void *X, const int incX, const void *Y, const int incY, void *dotc)
{
	cblas_cdotc_sub(N, X, incX, Y, incY, dotc);
}

void cblas_cdotu_sub_facade(const int N, const void *X, const int incX, const void *Y, const int incY, void *dotu)
{
	cblas_cdotu_sub(N, X, incX, Y, incY, dotu);
}

void cblas_cgbmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA, const int M, const int N, const int KL, const int KU, const void *alpha, const void *A, const int lda, const void *X, const int incX, const void *beta, void *Y, const int incY)
{
	cblas_cgbmv(order, TransA, M, N, KL, KU, alpha, A, lda, X, incX, beta, Y, incY);
}

void cblas_cgemm_facade(const enum CBLAS_ORDER Order, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_TRANSPOSE TransB, const int M, const int N, const int K, const void *alpha, const void *A, const int lda, const void *B, const int ldb, const void *beta, void *C, const int ldc, void *l3_buf, size_t l3_buf_size, void *ddr_buf, size_t ddr_buf_size, int *err_code)
{
	size_t l1D_SRAM_size_orig, l2_SRAM_size_orig;
	
	*err_code = blas_mem_config(l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, &l1D_SRAM_size_orig, &l2_SRAM_size_orig);
	if(*err_code != TICBLAS_SUCCESS) {
	    return;
	}
	
	cblas_cgemm(Order, TransA, TransB, M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);

	*err_code = blas_mem_reconfig(l1D_SRAM_size_orig, l2_SRAM_size_orig);	
}

void cblas_cgemv_facade(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA, const int M, const int N, const void *alpha, const void *A, const int lda, const void *X, const int incX, const void *beta, void *Y, const int incY)
{
	cblas_cgemv(order, TransA, M, N, alpha, A, lda, X, incX, beta, Y, incY);
}

void cblas_cgerc_facade(const enum CBLAS_ORDER order, const int M, const int N, const void *alpha, const void *X, const int incX, const void *Y, const int incY, void *A, const int lda)
{
	cblas_cgerc(order, M, N, alpha, X, incX, Y, incY, A, lda);
}

void cblas_cgeru_facade(const enum CBLAS_ORDER order, const int M, const int N, const void *alpha, const void *X, const int incX, const void *Y, const int incY, void *A, const int lda)
{
	cblas_cgeru(order, M, N, alpha, X, incX, Y, incY, A, lda);
}

void cblas_chbmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const int K, const void *alpha, const void *A, const int lda, const void *X, const int incX, const void *beta, void *Y, const int incY)
{
	cblas_chbmv(order, Uplo, N, K, alpha, A, lda, X, incX, beta, Y, incY);
}

void cblas_chemm_facade(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const int M, const int N, const void *alpha, const void *A, const int lda, const void *B, const int ldb, const void *beta, void *C, const int ldc, void *l3_buf, size_t l3_buf_size, void *ddr_buf, size_t ddr_buf_size, int *err_code)
{
	size_t l1D_SRAM_size_orig, l2_SRAM_size_orig;
	
	*err_code = blas_mem_config(l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, &l1D_SRAM_size_orig, &l2_SRAM_size_orig);
	if(*err_code != TICBLAS_SUCCESS) {
	    return;
	}
	
	cblas_chemm(Order, Side, Uplo, M, N, alpha, A, lda, B, ldb, beta, C, ldc);

	*err_code = blas_mem_reconfig(l1D_SRAM_size_orig, l2_SRAM_size_orig);	
}

void cblas_chemv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const void *alpha, const void *A, const int lda, const void *X, const int incX, const void *beta, void *Y, const int incY)
{
	cblas_chemv(order, Uplo, N, alpha, A, lda, X, incX, beta, Y, incY);
}

void cblas_cher_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const float alpha, const void *X, const int incX, void *A, const int lda)
{
	cblas_cher(order, Uplo, N, alpha, X, incX, A, lda);
}

void cblas_cher2_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const void *alpha, const void *X, const int incX, const void *Y, const int incY, void *A, const int lda)
{
	cblas_cher2(order, Uplo, N, alpha, X, incX, Y, incY, A, lda);
}

void cblas_cher2k_facade(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE Trans, const int N, const int K, const void *alpha, const void *A, const int lda, const void *B, const int ldb, const float beta, void *C, const int ldc, void *l3_buf, size_t l3_buf_size, void *ddr_buf, size_t ddr_buf_size, int *err_code)
{
	size_t l1D_SRAM_size_orig, l2_SRAM_size_orig;
	
	*err_code = blas_mem_config(l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, &l1D_SRAM_size_orig, &l2_SRAM_size_orig);
	if(*err_code != TICBLAS_SUCCESS) {
	    return;
	}
	
	cblas_cher2k(Order, Uplo, Trans, N, K, alpha, A, lda, B, ldb, beta, C, ldc);

	*err_code = blas_mem_reconfig(l1D_SRAM_size_orig, l2_SRAM_size_orig);	
}

void cblas_cherk_facade(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE Trans, const int N, const int K, const float alpha, const void *A, const int lda, const float beta, void *C, const int ldc, void *l3_buf, size_t l3_buf_size, void *ddr_buf, size_t ddr_buf_size, int *err_code)
{
	size_t l1D_SRAM_size_orig, l2_SRAM_size_orig;
	
	*err_code = blas_mem_config(l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, &l1D_SRAM_size_orig, &l2_SRAM_size_orig);
	if(*err_code != TICBLAS_SUCCESS) {
	    return;
	}
	
	cblas_cherk(Order, Uplo, Trans, N, K, alpha, A, lda, beta, C, ldc);

	*err_code = blas_mem_reconfig(l1D_SRAM_size_orig, l2_SRAM_size_orig);	
}

void cblas_chpmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const void *alpha, const void *Ap, const void *X, const int incX, const void *beta, void *Y, const int incY)
{
	cblas_chpmv(order, Uplo, N, alpha, Ap, X, incX, beta, Y, incY);
}

void cblas_chpr_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const float alpha, const void *X, const int incX, void *A)
{
	cblas_chpr(order, Uplo, N, alpha, X, incX, A);
}

void cblas_chpr2_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const void *alpha, const void *X, const int incX, const void *Y, const int incY, void *Ap)
{
	cblas_chpr2(order, Uplo, N, alpha, X, incX, Y, incY, Ap);
}

void cblas_crotg_facade(void *a, void *b, float *c, void *s)
{
	cblas_crotg(a, b, c, s);
}

void cblas_cscal_facade(const int N, const void *alpha, void *X, const int incX)
{
	cblas_cscal(N, alpha, X, incX);
}

void cblas_csscal_facade(const int N, const float alpha, void *X, const int incX)
{
	cblas_csscal(N, alpha, X, incX);
}

void cblas_cswap_facade(const int N, void *X, const int incX, void *Y, const int incY)
{
	cblas_cswap(N, X, incX, Y, incY);
}

void cblas_csymm_facade(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const int M, const int N, const void *alpha, const void *A, const int lda, const void *B, const int ldb, const void *beta, void *C, const int ldc, void *l3_buf, size_t l3_buf_size, void *ddr_buf, size_t ddr_buf_size, int *err_code)
{
	size_t l1D_SRAM_size_orig, l2_SRAM_size_orig;
	
	*err_code = blas_mem_config(l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, &l1D_SRAM_size_orig, &l2_SRAM_size_orig);
	if(*err_code != TICBLAS_SUCCESS) {
	    return;
	}
	
	cblas_csymm(Order, Side, Uplo, M, N, alpha, A, lda, B, ldb, beta, C, ldc);

	*err_code = blas_mem_reconfig(l1D_SRAM_size_orig, l2_SRAM_size_orig);	
}

void cblas_csyr2k_facade(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE Trans, const int N, const int K, const void *alpha, const void *A, const int lda, const void *B, const int ldb, const void *beta, void *C, const int ldc, void *l3_buf, size_t l3_buf_size, void *ddr_buf, size_t ddr_buf_size, int *err_code)
{
	size_t l1D_SRAM_size_orig, l2_SRAM_size_orig;
	
	*err_code = blas_mem_config(l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, &l1D_SRAM_size_orig, &l2_SRAM_size_orig);
	if(*err_code != TICBLAS_SUCCESS) {
	    return;
	}
	
	cblas_csyr2k(Order, Uplo, Trans, N, K, alpha, A, lda, B, ldb, beta, C, ldc);

	*err_code = blas_mem_reconfig(l1D_SRAM_size_orig, l2_SRAM_size_orig);	
}

void cblas_csyrk_facade(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE Trans, const int N, const int K, const void *alpha, const void *A, const int lda, const void *beta, void *C, const int ldc, void *l3_buf, size_t l3_buf_size, void *ddr_buf, size_t ddr_buf_size, int *err_code)
{
	size_t l1D_SRAM_size_orig, l2_SRAM_size_orig;
	
	*err_code = blas_mem_config(l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, &l1D_SRAM_size_orig, &l2_SRAM_size_orig);
	if(*err_code != TICBLAS_SUCCESS) {
	    return;
	}
	
	cblas_csyrk(Order, Uplo, Trans, N, K, alpha, A, lda, beta, C, ldc);

	*err_code = blas_mem_reconfig(l1D_SRAM_size_orig, l2_SRAM_size_orig);	
}

void cblas_ctbmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const int K, const void *A, const int lda, void *X, const int incX)
{
	cblas_ctbmv(order, Uplo, TransA, Diag, N, K, A, lda, X, incX);
}

void cblas_ctbsv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const int K, const void *A, const int lda, void *X, const int incX)
{
	cblas_ctbsv(order, Uplo, TransA, Diag, N, K, A, lda, X, incX);
}

void cblas_ctpmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const void *Ap, void *X, const int incX)
{
	cblas_ctpmv(order, Uplo, TransA, Diag, N, Ap, X, incX);
}

void cblas_ctpsv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const void *Ap, void *X, const int incX)
{
	cblas_ctpsv(order, Uplo, TransA, Diag, N, Ap, X, incX);
}

void cblas_ctrmm_facade(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int M, const int N, const void *alpha, const void *A, const int lda, void *B, const int ldb, void *l3_buf, size_t l3_buf_size, void *ddr_buf, size_t ddr_buf_size, int *err_code)
{
	size_t l1D_SRAM_size_orig, l2_SRAM_size_orig;
	
	*err_code = blas_mem_config(l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, &l1D_SRAM_size_orig, &l2_SRAM_size_orig);
	if(*err_code != TICBLAS_SUCCESS) {
	    return;
	}
	
	cblas_ctrmm(Order, Side, Uplo, TransA, Diag, M, N, alpha, A, lda, B, ldb);

	*err_code = blas_mem_reconfig(l1D_SRAM_size_orig, l2_SRAM_size_orig);	
}

void cblas_ctrmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const void *A, const int lda, void *X, const int incX)
{
	cblas_ctrmv(order, Uplo, TransA, Diag, N, A, lda, X, incX);
}

void cblas_ctrsm_facade(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int M, const int N, const void *alpha, const void *A, const int lda, void *B, const int ldb, void *l3_buf, size_t l3_buf_size, void *ddr_buf, size_t ddr_buf_size, int *err_code)
{
	size_t l1D_SRAM_size_orig, l2_SRAM_size_orig;
	
	*err_code = blas_mem_config(l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, &l1D_SRAM_size_orig, &l2_SRAM_size_orig);
	if(*err_code != TICBLAS_SUCCESS) {
	    return;
	}
	
	cblas_ctrsm(Order, Side, Uplo, TransA, Diag, M, N, alpha, A, lda, B, ldb);

	*err_code = blas_mem_reconfig(l1D_SRAM_size_orig, l2_SRAM_size_orig);	
}

void cblas_ctrsv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const void *A, const int lda, void *X, const int incX)
{
	cblas_ctrsv(order, Uplo, TransA, Diag, N, A, lda, X, incX);
}

void cblas_dasum_facade(const int N, const double *X, const int incX, double *retval)
{
	*retval = cblas_dasum(N, X, incX);
}

void cblas_daxpy_facade(const int N, const double alpha, const double *X, const int incX, double *Y, const int incY)
{
	cblas_daxpy(N, alpha, X, incX, Y, incY);
}

void cblas_dcopy_facade(const int N, const double *X, const int incX, double *Y, const int incY)
{
	cblas_dcopy(N, X, incX, Y, incY);
}

void cblas_ddot_facade(const int N, const double *X, const int incX, const double *Y, const int incY, double *retval)
{
	*retval = cblas_ddot(N, X, incX, Y, incY);
}

void cblas_dgbmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA, const int M, const int N, const int KL, const int KU, const double alpha, const double *A, const int lda, const double *X, const int incX, const double beta, double *Y, const int incY)
{
	cblas_dgbmv(order, TransA, M, N, KL, KU, alpha, A, lda, X, incX, beta, Y, incY);
}

void cblas_dgemm_facade(const enum CBLAS_ORDER Order, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_TRANSPOSE TransB, const int M, const int N, const int K, const double alpha, const double *A, const int lda, const double *B, const int ldb, const double beta, double *C, const int ldc, void *l3_buf, size_t l3_buf_size, void *ddr_buf, size_t ddr_buf_size, int *err_code)
{
	size_t l1D_SRAM_size_orig, l2_SRAM_size_orig;
	
	*err_code = blas_mem_config(l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, &l1D_SRAM_size_orig, &l2_SRAM_size_orig);
	if(*err_code != TICBLAS_SUCCESS) {
	    return;
	}
	
	cblas_dgemm(Order, TransA, TransB, M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);

	*err_code = blas_mem_reconfig(l1D_SRAM_size_orig, l2_SRAM_size_orig);	
}

void cblas_dgemv_facade(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA, const int M, const int N, const double alpha, const double *A, const int lda, const double *X, const int incX, const double beta, double *Y, const int incY)
{
	cblas_dgemv(order, TransA, M, N, alpha, A, lda, X, incX, beta, Y, incY);
}

void cblas_dger_facade(const enum CBLAS_ORDER order, const int M, const int N, const double alpha, const double *X, const int incX, const double *Y, const int incY, double *A, const int lda)
{
	cblas_dger(order, M, N, alpha, X, incX, Y, incY, A, lda);
}

void cblas_dnrm2_facade(const int N, const double *X, const int incX, double *retval)
{
	*retval = cblas_dnrm2(N, X, incX);
}

void cblas_drot_facade(const int N, double *X, const int incX, double *Y, const int incY, const double c, const double s)
{
	cblas_drot(N, X, incX, Y, incY, c, s);
}

void cblas_drotg_facade(double *a, double *b, double *c, double *s)
{
	cblas_drotg(a, b, c, s);
}

void cblas_drotm_facade(const int N, double *X, const int incX, double *Y, const int incY, const double *P)
{
	cblas_drotm(N, X, incX, Y, incY, P);
}

void cblas_drotmg_facade(double *d1, double *d2, double *b1, const double b2, double *P)
{
	cblas_drotmg(d1, d2, b1, b2, P);
}

void cblas_dsbmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const int K, const double alpha, const double *A, const int lda, const double *X, const int incX, const double beta, double *Y, const int incY)
{
	cblas_dsbmv(order, Uplo, N, K, alpha, A, lda, X, incX, beta, Y, incY);
}

void cblas_dscal_facade(const int N, const double alpha, double *X, const int incX)
{
	cblas_dscal(N, alpha, X, incX);
}

void cblas_dsdot_facade(const int N, const float *X, const int incX, const float *Y, const int incY, double *retval)
{
	*retval = cblas_dsdot(N, X, incX, Y, incY);
}

void cblas_dspmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const double alpha, const double *Ap, const double *X, const int incX, const double beta, double *Y, const int incY)
{
	cblas_dspmv(order, Uplo, N, alpha, Ap, X, incX, beta, Y, incY);
}

void cblas_dspr_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const double alpha, const double *X, const int incX, double *Ap)
{
	cblas_dspr(order, Uplo, N, alpha, X, incX, Ap);
}

void cblas_dspr2_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const double alpha, const double *X, const int incX, const double *Y, const int incY, double *A)
{
	cblas_dspr2(order, Uplo, N, alpha, X, incX, Y, incY, A);
}

void cblas_dswap_facade(const int N, double *X, const int incX, double *Y, const int incY)
{
	cblas_dswap(N, X, incX, Y, incY);
}

void cblas_dsymm_facade(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const int M, const int N, const double alpha, const double *A, const int lda, const double *B, const int ldb, const double beta, double *C, const int ldc, void *l3_buf, size_t l3_buf_size, void *ddr_buf, size_t ddr_buf_size, int *err_code)
{
	size_t l1D_SRAM_size_orig, l2_SRAM_size_orig;
	
	*err_code = blas_mem_config(l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, &l1D_SRAM_size_orig, &l2_SRAM_size_orig);
	if(*err_code != TICBLAS_SUCCESS) {
	    return;
	}
	
	cblas_dsymm(Order, Side, Uplo, M, N, alpha, A, lda, B, ldb, beta, C, ldc);

	*err_code = blas_mem_reconfig(l1D_SRAM_size_orig, l2_SRAM_size_orig);	
}

void cblas_dsymv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const double alpha, const double *A, const int lda, const double *X, const int incX, const double beta, double *Y, const int incY)
{
	cblas_dsymv(order, Uplo, N, alpha, A, lda, X, incX, beta, Y, incY);
}

void cblas_dsyr_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const double alpha, const double *X, const int incX, double *A, const int lda)
{
	cblas_dsyr(order, Uplo, N, alpha, X, incX, A, lda);
}

void cblas_dsyr2_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const double alpha, const double *X, const int incX, const double *Y, const int incY, double *A, const int lda)
{
	cblas_dsyr2(order, Uplo, N, alpha, X, incX, Y, incY, A, lda);
}

void cblas_dsyr2k_facade(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE Trans, const int N, const int K, const double alpha, const double *A, const int lda, const double *B, const int ldb, const double beta, double *C, const int ldc, void *l3_buf, size_t l3_buf_size, void *ddr_buf, size_t ddr_buf_size, int *err_code)
{
	size_t l1D_SRAM_size_orig, l2_SRAM_size_orig;
	
	*err_code = blas_mem_config(l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, &l1D_SRAM_size_orig, &l2_SRAM_size_orig);
	if(*err_code != TICBLAS_SUCCESS) {
	    return;
	}
	
	cblas_dsyr2k(Order, Uplo, Trans, N, K, alpha, A, lda, B, ldb, beta, C, ldc);

	*err_code = blas_mem_reconfig(l1D_SRAM_size_orig, l2_SRAM_size_orig);	
}

void cblas_dsyrk_facade(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE Trans, const int N, const int K, const double alpha, const double *A, const int lda, const double beta, double *C, const int ldc, void *l3_buf, size_t l3_buf_size, void *ddr_buf, size_t ddr_buf_size, int *err_code)
{
	size_t l1D_SRAM_size_orig, l2_SRAM_size_orig;
	
	*err_code = blas_mem_config(l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, &l1D_SRAM_size_orig, &l2_SRAM_size_orig);
	if(*err_code != TICBLAS_SUCCESS) {
	    return;
	}
	
	cblas_dsyrk(Order, Uplo, Trans, N, K, alpha, A, lda, beta, C, ldc);

	*err_code = blas_mem_reconfig(l1D_SRAM_size_orig, l2_SRAM_size_orig);	
}

void cblas_dtbmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const int K, const double *A, const int lda, double *X, const int incX)
{
	cblas_dtbmv(order, Uplo, TransA, Diag, N, K, A, lda, X, incX);
}

void cblas_dtbsv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const int K, const double *A, const int lda, double *X, const int incX)
{
	cblas_dtbsv(order, Uplo, TransA, Diag, N, K, A, lda, X, incX);
}

void cblas_dtpmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const double *Ap, double *X, const int incX)
{
	cblas_dtpmv(order, Uplo, TransA, Diag, N, Ap, X, incX);
}

void cblas_dtpsv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const double *Ap, double *X, const int incX)
{
	cblas_dtpsv(order, Uplo, TransA, Diag, N, Ap, X, incX);
}

void cblas_dtrmm_facade(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int M, const int N, const double alpha, const double *A, const int lda, double *B, const int ldb, void *l3_buf, size_t l3_buf_size, void *ddr_buf, size_t ddr_buf_size, int *err_code)
{
	size_t l1D_SRAM_size_orig, l2_SRAM_size_orig;
	
	*err_code = blas_mem_config(l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, &l1D_SRAM_size_orig, &l2_SRAM_size_orig);
	if(*err_code != TICBLAS_SUCCESS) {
	    return;
	}
	
	cblas_dtrmm(Order, Side, Uplo, TransA, Diag, M, N, alpha, A, lda, B, ldb);

	*err_code = blas_mem_reconfig(l1D_SRAM_size_orig, l2_SRAM_size_orig);	
}

void cblas_dtrmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const double *A, const int lda, double *X, const int incX)
{
	cblas_dtrmv(order, Uplo, TransA, Diag, N, A, lda, X, incX);
}

void cblas_dtrsm_facade(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int M, const int N, const double alpha, const double *A, const int lda, double *B, const int ldb, void *l3_buf, size_t l3_buf_size, void *ddr_buf, size_t ddr_buf_size, int *err_code)
{
	size_t l1D_SRAM_size_orig, l2_SRAM_size_orig;
	
	*err_code = blas_mem_config(l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, &l1D_SRAM_size_orig, &l2_SRAM_size_orig);
	if(*err_code != TICBLAS_SUCCESS) {
	    return;
	}
	
	cblas_dtrsm(Order, Side, Uplo, TransA, Diag, M, N, alpha, A, lda, B, ldb);

	*err_code = blas_mem_reconfig(l1D_SRAM_size_orig, l2_SRAM_size_orig);	
}

void cblas_dtrsv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const double *A, const int lda, double *X, const int incX)
{
	cblas_dtrsv(order, Uplo, TransA, Diag, N, A, lda, X, incX);
}

void cblas_dzasum_facade(const int N, const void *X, const int incX, double *retval)
{
	*retval = cblas_dzasum(N, X, incX);
}

void cblas_dznrm2_facade(const int N, const void *X, const int incX, double *retval)
{
	*retval = cblas_dznrm2(N, X, incX);
}

void cblas_icamax_facade(const int N, const void *X, const int incX, CBLAS_INDEX *retval)
{
	*retval = cblas_icamax(N, X, incX);
}

void cblas_idamax_facade(const int N, const double *X, const int incX, CBLAS_INDEX *retval)
{
	*retval = cblas_idamax(N, X, incX);
}

void cblas_isamax_facade(const int N, const float *X, const int incX, CBLAS_INDEX *retval)
{
	*retval = cblas_isamax(N, X, incX);
}

void cblas_izamax_facade(const int N, const void *X, const int incX, CBLAS_INDEX *retval)
{
	*retval = cblas_izamax(N, X, incX);
}

void cblas_sasum_facade(const int N, const float *X, const int incX, float *retval)
{
	*retval = cblas_sasum(N, X, incX);
}

void cblas_saxpy_facade(const int N, const float alpha, const float *X, const int incX, float *Y, const int incY)
{
	cblas_saxpy(N, alpha, X, incX, Y, incY);
}

void cblas_scasum_facade(const int N, const void *X, const int incX, float *retval)
{
	*retval = cblas_scasum(N, X, incX);
}

void cblas_scnrm2_facade(const int N, const void *X, const int incX, float *retval)
{
	*retval = cblas_scnrm2(N, X, incX);
}

void cblas_scopy_facade(const int N, const float *X, const int incX, float *Y, const int incY)
{
	cblas_scopy(N, X, incX, Y, incY);
}

void cblas_sdot_facade(const int N, const float *X, const int incX, const float *Y, const int incY, float *retval)
{
	*retval = cblas_sdot(N, X, incX, Y, incY);
}

void cblas_sdsdot_facade(const int N, const float alpha, const float *X, const int incX, const float *Y, const int incY, float *retval)
{
	*retval = cblas_sdsdot(N, alpha, X, incX, Y, incY);
}

void cblas_sgbmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA, const int M, const int N, const int KL, const int KU, const float alpha, const float *A, const int lda, const float *X, const int incX, const float beta, float *Y, const int incY)
{
	cblas_sgbmv(order, TransA, M, N, KL, KU, alpha, A, lda, X, incX, beta, Y, incY);
}

void cblas_sgemm_facade(const enum CBLAS_ORDER Order, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_TRANSPOSE TransB, const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc, void *l3_buf, size_t l3_buf_size, void *ddr_buf, size_t ddr_buf_size, int *err_code)
{
	size_t l1D_SRAM_size_orig, l2_SRAM_size_orig;
	
	*err_code = blas_mem_config(l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, &l1D_SRAM_size_orig, &l2_SRAM_size_orig);
	if(*err_code != TICBLAS_SUCCESS) {
	    return;
	}
	
	cblas_sgemm(Order, TransA, TransB, M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);

	*err_code = blas_mem_reconfig(l1D_SRAM_size_orig, l2_SRAM_size_orig);	
}

void cblas_sgemv_facade(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA, const int M, const int N, const float alpha, const float *A, const int lda, const float *X, const int incX, const float beta, float *Y, const int incY)
{
	cblas_sgemv(order, TransA, M, N, alpha, A, lda, X, incX, beta, Y, incY);
}

void cblas_sger_facade(const enum CBLAS_ORDER order, const int M, const int N, const float alpha, const float *X, const int incX, const float *Y, const int incY, float *A, const int lda)
{
	cblas_sger(order, M, N, alpha, X, incX, Y, incY, A, lda);
}

void cblas_snrm2_facade(const int N, const float *X, const int incX, float *retval)
{
	*retval = cblas_snrm2(N, X, incX);
}

void cblas_srot_facade(const int N, float *X, const int incX, float *Y, const int incY, const float c, const float s)
{
	cblas_srot(N, X, incX, Y, incY, c, s);
}

void cblas_srotg_facade(float *a, float *b, float *c, float *s)
{
	cblas_srotg(a, b, c, s);
}

void cblas_srotm_facade(const int N, float *X, const int incX, float *Y, const int incY, const float *P)
{
	cblas_srotm(N, X, incX, Y, incY, P);
}

void cblas_srotmg_facade(float *d1, float *d2, float *b1, const float b2, float *P)
{
	cblas_srotmg(d1, d2, b1, b2, P);
}

void cblas_ssbmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const int K, const float alpha, const float *A, const int lda, const float *X, const int incX, const float beta, float *Y, const int incY)
{
	cblas_ssbmv(order, Uplo, N, K, alpha, A, lda, X, incX, beta, Y, incY);
}

void cblas_sscal_facade(const int N, const float alpha, float *X, const int incX)
{
	cblas_sscal(N, alpha, X, incX);
}

void cblas_sspmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const float alpha, const float *Ap, const float *X, const int incX, const float beta, float *Y, const int incY)
{
	cblas_sspmv(order, Uplo, N, alpha, Ap, X, incX, beta, Y, incY);
}

void cblas_sspr_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const float alpha, const float *X, const int incX, float *Ap)
{
	cblas_sspr(order, Uplo, N, alpha, X, incX, Ap);
}

void cblas_sspr2_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const float alpha, const float *X, const int incX, const float *Y, const int incY, float *A)
{
	cblas_sspr2(order, Uplo, N, alpha, X, incX, Y, incY, A);
}

void cblas_sswap_facade(const int N, float *X, const int incX, float *Y, const int incY)
{
	cblas_sswap(N, X, incX, Y, incY);
}

void cblas_ssymm_facade(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const int M, const int N, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc, void *l3_buf, size_t l3_buf_size, void *ddr_buf, size_t ddr_buf_size, int *err_code)
{
	size_t l1D_SRAM_size_orig, l2_SRAM_size_orig;
	
	*err_code = blas_mem_config(l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, &l1D_SRAM_size_orig, &l2_SRAM_size_orig);
	if(*err_code != TICBLAS_SUCCESS) {
	    return;
	}
	
	cblas_ssymm(Order, Side, Uplo, M, N, alpha, A, lda, B, ldb, beta, C, ldc);

	*err_code = blas_mem_reconfig(l1D_SRAM_size_orig, l2_SRAM_size_orig);	
}

void cblas_ssymv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const float alpha, const float *A, const int lda, const float *X, const int incX, const float beta, float *Y, const int incY)
{
	cblas_ssymv(order, Uplo, N, alpha, A, lda, X, incX, beta, Y, incY);
}

void cblas_ssyr_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const float alpha, const float *X, const int incX, float *A, const int lda)
{
	cblas_ssyr(order, Uplo, N, alpha, X, incX, A, lda);
}

void cblas_ssyr2_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const float alpha, const float *X, const int incX, const float *Y, const int incY, float *A, const int lda)
{
	cblas_ssyr2(order, Uplo, N, alpha, X, incX, Y, incY, A, lda);
}

void cblas_ssyr2k_facade(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE Trans, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc, void *l3_buf, size_t l3_buf_size, void *ddr_buf, size_t ddr_buf_size, int *err_code)
{
	size_t l1D_SRAM_size_orig, l2_SRAM_size_orig;
	
	*err_code = blas_mem_config(l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, &l1D_SRAM_size_orig, &l2_SRAM_size_orig);
	if(*err_code != TICBLAS_SUCCESS) {
	    return;
	}
	
	cblas_ssyr2k(Order, Uplo, Trans, N, K, alpha, A, lda, B, ldb, beta, C, ldc);

	*err_code = blas_mem_reconfig(l1D_SRAM_size_orig, l2_SRAM_size_orig);	
}

void cblas_ssyrk_facade(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE Trans, const int N, const int K, const float alpha, const float *A, const int lda, const float beta, float *C, const int ldc, void *l3_buf, size_t l3_buf_size, void *ddr_buf, size_t ddr_buf_size, int *err_code)
{
	size_t l1D_SRAM_size_orig, l2_SRAM_size_orig;
	
	*err_code = blas_mem_config(l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, &l1D_SRAM_size_orig, &l2_SRAM_size_orig);
	if(*err_code != TICBLAS_SUCCESS) {
	    return;
	}
	
	cblas_ssyrk(Order, Uplo, Trans, N, K, alpha, A, lda, beta, C, ldc);

	*err_code = blas_mem_reconfig(l1D_SRAM_size_orig, l2_SRAM_size_orig);	
}

void cblas_stbmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const int K, const float *A, const int lda, float *X, const int incX)
{
	cblas_stbmv(order, Uplo, TransA, Diag, N, K, A, lda, X, incX);
}

void cblas_stbsv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const int K, const float *A, const int lda, float *X, const int incX)
{
	cblas_stbsv(order, Uplo, TransA, Diag, N, K, A, lda, X, incX);
}

void cblas_stpmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const float *Ap, float *X, const int incX)
{
	cblas_stpmv(order, Uplo, TransA, Diag, N, Ap, X, incX);
}

void cblas_stpsv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const float *Ap, float *X, const int incX)
{
	cblas_stpsv(order, Uplo, TransA, Diag, N, Ap, X, incX);
}

void cblas_strmm_facade(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int M, const int N, const float alpha, const float *A, const int lda, float *B, const int ldb, void *l3_buf, size_t l3_buf_size, void *ddr_buf, size_t ddr_buf_size, int *err_code)
{
	size_t l1D_SRAM_size_orig, l2_SRAM_size_orig;
	
	*err_code = blas_mem_config(l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, &l1D_SRAM_size_orig, &l2_SRAM_size_orig);
	if(*err_code != TICBLAS_SUCCESS) {
	    return;
	}
	
	cblas_strmm(Order, Side, Uplo, TransA, Diag, M, N, alpha, A, lda, B, ldb);

	*err_code = blas_mem_reconfig(l1D_SRAM_size_orig, l2_SRAM_size_orig);	
}

void cblas_strmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const float *A, const int lda, float *X, const int incX)
{
	cblas_strmv(order, Uplo, TransA, Diag, N, A, lda, X, incX);
}

void cblas_strsm_facade(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int M, const int N, const float alpha, const float *A, const int lda, float *B, const int ldb, void *l3_buf, size_t l3_buf_size, void *ddr_buf, size_t ddr_buf_size, int *err_code)
{
	size_t l1D_SRAM_size_orig, l2_SRAM_size_orig;
	
	*err_code = blas_mem_config(l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, &l1D_SRAM_size_orig, &l2_SRAM_size_orig);
	if(*err_code != TICBLAS_SUCCESS) {
	    return;
	}
	
	cblas_strsm(Order, Side, Uplo, TransA, Diag, M, N, alpha, A, lda, B, ldb);

	*err_code = blas_mem_reconfig(l1D_SRAM_size_orig, l2_SRAM_size_orig);	
}

void cblas_strsv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const float *A, const int lda, float *X, const int incX)
{
	cblas_strsv(order, Uplo, TransA, Diag, N, A, lda, X, incX);
}

void cblas_xerbla_facade(int p, const char *rout, const char *form)
{
	cblas_xerbla(p, rout, form);
}

void cblas_zaxpy_facade(const int N, const void *alpha, const void *X, const int incX, void *Y, const int incY)
{
	cblas_zaxpy(N, alpha, X, incX, Y, incY);
}

void cblas_zcopy_facade(const int N, const void *X, const int incX, void *Y, const int incY)
{
	cblas_zcopy(N, X, incX, Y, incY);
}

void cblas_zdotc_sub_facade(const int N, const void *X, const int incX, const void *Y, const int incY, void *dotc)
{
	cblas_zdotc_sub(N, X, incX, Y, incY, dotc);
}

void cblas_zdotu_sub_facade(const int N, const void *X, const int incX, const void *Y, const int incY, void *dotu)
{
	cblas_zdotu_sub(N, X, incX, Y, incY, dotu);
}

void cblas_zdscal_facade(const int N, const double alpha, void *X, const int incX)
{
	cblas_zdscal(N, alpha, X, incX);
}

void cblas_zgbmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA, const int M, const int N, const int KL, const int KU, const void *alpha, const void *A, const int lda, const void *X, const int incX, const void *beta, void *Y, const int incY)
{
	cblas_zgbmv(order, TransA, M, N, KL, KU, alpha, A, lda, X, incX, beta, Y, incY);
}

void cblas_zgemm_facade(const enum CBLAS_ORDER Order, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_TRANSPOSE TransB, const int M, const int N, const int K, const void *alpha, const void *A, const int lda, const void *B, const int ldb, const void *beta, void *C, const int ldc, void *l3_buf, size_t l3_buf_size, void *ddr_buf, size_t ddr_buf_size, int *err_code)
{
	size_t l1D_SRAM_size_orig, l2_SRAM_size_orig;
	
	*err_code = blas_mem_config(l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, &l1D_SRAM_size_orig, &l2_SRAM_size_orig);
	if(*err_code != TICBLAS_SUCCESS) {
	    return;
	}
	
	cblas_zgemm(Order, TransA, TransB, M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);

	*err_code = blas_mem_reconfig(l1D_SRAM_size_orig, l2_SRAM_size_orig);	
}

void cblas_zgemv_facade(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA, const int M, const int N, const void *alpha, const void *A, const int lda, const void *X, const int incX, const void *beta, void *Y, const int incY)
{
	cblas_zgemv(order, TransA, M, N, alpha, A, lda, X, incX, beta, Y, incY);
}

void cblas_zgerc_facade(const enum CBLAS_ORDER order, const int M, const int N, const void *alpha, const void *X, const int incX, const void *Y, const int incY, void *A, const int lda)
{
	cblas_zgerc(order, M, N, alpha, X, incX, Y, incY, A, lda);
}

void cblas_zgeru_facade(const enum CBLAS_ORDER order, const int M, const int N, const void *alpha, const void *X, const int incX, const void *Y, const int incY, void *A, const int lda)
{
	cblas_zgeru(order, M, N, alpha, X, incX, Y, incY, A, lda);
}

void cblas_zhbmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const int K, const void *alpha, const void *A, const int lda, const void *X, const int incX, const void *beta, void *Y, const int incY)
{
	cblas_zhbmv(order, Uplo, N, K, alpha, A, lda, X, incX, beta, Y, incY);
}

void cblas_zhemm_facade(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const int M, const int N, const void *alpha, const void *A, const int lda, const void *B, const int ldb, const void *beta, void *C, const int ldc, void *l3_buf, size_t l3_buf_size, void *ddr_buf, size_t ddr_buf_size, int *err_code)
{
	size_t l1D_SRAM_size_orig, l2_SRAM_size_orig;
	
	*err_code = blas_mem_config(l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, &l1D_SRAM_size_orig, &l2_SRAM_size_orig);
	if(*err_code != TICBLAS_SUCCESS) {
	    return;
	}
	
	cblas_zhemm(Order, Side, Uplo, M, N, alpha, A, lda, B, ldb, beta, C, ldc);

	*err_code = blas_mem_reconfig(l1D_SRAM_size_orig, l2_SRAM_size_orig);	
}

void cblas_zhemv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const void *alpha, const void *A, const int lda, const void *X, const int incX, const void *beta, void *Y, const int incY)
{
	cblas_zhemv(order, Uplo, N, alpha, A, lda, X, incX, beta, Y, incY);
}

void cblas_zher_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const double alpha, const void *X, const int incX, void *A, const int lda)
{
	cblas_zher(order, Uplo, N, alpha, X, incX, A, lda);
}

void cblas_zher2_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const void *alpha, const void *X, const int incX, const void *Y, const int incY, void *A, const int lda)
{
	cblas_zher2(order, Uplo, N, alpha, X, incX, Y, incY, A, lda);
}

void cblas_zher2k_facade(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE Trans, const int N, const int K, const void *alpha, const void *A, const int lda, const void *B, const int ldb, const double beta, void *C, const int ldc, void *l3_buf, size_t l3_buf_size, void *ddr_buf, size_t ddr_buf_size, int *err_code)
{
	size_t l1D_SRAM_size_orig, l2_SRAM_size_orig;
	
	*err_code = blas_mem_config(l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, &l1D_SRAM_size_orig, &l2_SRAM_size_orig);
	if(*err_code != TICBLAS_SUCCESS) {
	    return;
	}
	
	cblas_zher2k(Order, Uplo, Trans, N, K, alpha, A, lda, B, ldb, beta, C, ldc);

	*err_code = blas_mem_reconfig(l1D_SRAM_size_orig, l2_SRAM_size_orig);	
}

void cblas_zherk_facade(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE Trans, const int N, const int K, const double alpha, const void *A, const int lda, const double beta, void *C, const int ldc, void *l3_buf, size_t l3_buf_size, void *ddr_buf, size_t ddr_buf_size, int *err_code)
{
	size_t l1D_SRAM_size_orig, l2_SRAM_size_orig;
	
	*err_code = blas_mem_config(l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, &l1D_SRAM_size_orig, &l2_SRAM_size_orig);
	if(*err_code != TICBLAS_SUCCESS) {
	    return;
	}
	
	cblas_zherk(Order, Uplo, Trans, N, K, alpha, A, lda, beta, C, ldc);

	*err_code = blas_mem_reconfig(l1D_SRAM_size_orig, l2_SRAM_size_orig);	
}

void cblas_zhpmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const void *alpha, const void *Ap, const void *X, const int incX, const void *beta, void *Y, const int incY)
{
	cblas_zhpmv(order, Uplo, N, alpha, Ap, X, incX, beta, Y, incY);
}

void cblas_zhpr_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const double alpha, const void *X, const int incX, void *A)
{
	cblas_zhpr(order, Uplo, N, alpha, X, incX, A);
}

void cblas_zhpr2_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const void *alpha, const void *X, const int incX, const void *Y, const int incY, void *Ap)
{
	cblas_zhpr2(order, Uplo, N, alpha, X, incX, Y, incY, Ap);
}

void cblas_zrotg_facade(void *a, void *b, double *c, void *s)
{
	cblas_zrotg(a, b, c, s);
}

void cblas_zscal_facade(const int N, const void *alpha, void *X, const int incX)
{
	cblas_zscal(N, alpha, X, incX);
}

void cblas_zswap_facade(const int N, void *X, const int incX, void *Y, const int incY)
{
	cblas_zswap(N, X, incX, Y, incY);
}

void cblas_zsymm_facade(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const int M, const int N, const void *alpha, const void *A, const int lda, const void *B, const int ldb, const void *beta, void *C, const int ldc, void *l3_buf, size_t l3_buf_size, void *ddr_buf, size_t ddr_buf_size, int *err_code)
{
	size_t l1D_SRAM_size_orig, l2_SRAM_size_orig;
	
	*err_code = blas_mem_config(l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, &l1D_SRAM_size_orig, &l2_SRAM_size_orig);
	if(*err_code != TICBLAS_SUCCESS) {
	    return;
	}
	
	cblas_zsymm(Order, Side, Uplo, M, N, alpha, A, lda, B, ldb, beta, C, ldc);

	*err_code = blas_mem_reconfig(l1D_SRAM_size_orig, l2_SRAM_size_orig);	
}

void cblas_zsyr2k_facade(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE Trans, const int N, const int K, const void *alpha, const void *A, const int lda, const void *B, const int ldb, const void *beta, void *C, const int ldc, void *l3_buf, size_t l3_buf_size, void *ddr_buf, size_t ddr_buf_size, int *err_code)
{
	size_t l1D_SRAM_size_orig, l2_SRAM_size_orig;
	
	*err_code = blas_mem_config(l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, &l1D_SRAM_size_orig, &l2_SRAM_size_orig);
	if(*err_code != TICBLAS_SUCCESS) {
	    return;
	}
	
	cblas_zsyr2k(Order, Uplo, Trans, N, K, alpha, A, lda, B, ldb, beta, C, ldc);

	*err_code = blas_mem_reconfig(l1D_SRAM_size_orig, l2_SRAM_size_orig);	
}

void cblas_zsyrk_facade(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE Trans, const int N, const int K, const void *alpha, const void *A, const int lda, const void *beta, void *C, const int ldc, void *l3_buf, size_t l3_buf_size, void *ddr_buf, size_t ddr_buf_size, int *err_code)
{
	size_t l1D_SRAM_size_orig, l2_SRAM_size_orig;
	
	*err_code = blas_mem_config(l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, &l1D_SRAM_size_orig, &l2_SRAM_size_orig);
	if(*err_code != TICBLAS_SUCCESS) {
	    return;
	}
	
	cblas_zsyrk(Order, Uplo, Trans, N, K, alpha, A, lda, beta, C, ldc);

	*err_code = blas_mem_reconfig(l1D_SRAM_size_orig, l2_SRAM_size_orig);	
}

void cblas_ztbmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const int K, const void *A, const int lda, void *X, const int incX)
{
	cblas_ztbmv(order, Uplo, TransA, Diag, N, K, A, lda, X, incX);
}

void cblas_ztbsv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const int K, const void *A, const int lda, void *X, const int incX)
{
	cblas_ztbsv(order, Uplo, TransA, Diag, N, K, A, lda, X, incX);
}

void cblas_ztpmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const void *Ap, void *X, const int incX)
{
	cblas_ztpmv(order, Uplo, TransA, Diag, N, Ap, X, incX);
}

void cblas_ztpsv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const void *Ap, void *X, const int incX)
{
	cblas_ztpsv(order, Uplo, TransA, Diag, N, Ap, X, incX);
}

void cblas_ztrmm_facade(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int M, const int N, const void *alpha, const void *A, const int lda, void *B, const int ldb, void *l3_buf, size_t l3_buf_size, void *ddr_buf, size_t ddr_buf_size, int *err_code)
{
	size_t l1D_SRAM_size_orig, l2_SRAM_size_orig;
	
	*err_code = blas_mem_config(l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, &l1D_SRAM_size_orig, &l2_SRAM_size_orig);
	if(*err_code != TICBLAS_SUCCESS) {
	    return;
	}
	
	cblas_ztrmm(Order, Side, Uplo, TransA, Diag, M, N, alpha, A, lda, B, ldb);

	*err_code = blas_mem_reconfig(l1D_SRAM_size_orig, l2_SRAM_size_orig);	
}

void cblas_ztrmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const void *A, const int lda, void *X, const int incX)
{
	cblas_ztrmv(order, Uplo, TransA, Diag, N, A, lda, X, incX);
}

void cblas_ztrsm_facade(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int M, const int N, const void *alpha, const void *A, const int lda, void *B, const int ldb, void *l3_buf, size_t l3_buf_size, void *ddr_buf, size_t ddr_buf_size, int *err_code)
{
	size_t l1D_SRAM_size_orig, l2_SRAM_size_orig;
	
	*err_code = blas_mem_config(l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, &l1D_SRAM_size_orig, &l2_SRAM_size_orig);
	if(*err_code != TICBLAS_SUCCESS) {
	    return;
	}
	
	cblas_ztrsm(Order, Side, Uplo, TransA, Diag, M, N, alpha, A, lda, B, ldb);

	*err_code = blas_mem_reconfig(l1D_SRAM_size_orig, l2_SRAM_size_orig);	
}

void cblas_ztrsv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const void *A, const int lda, void *X, const int incX)
{
	cblas_ztrsv(order, Uplo, TransA, Diag, N, A, lda, X, incX);
}

