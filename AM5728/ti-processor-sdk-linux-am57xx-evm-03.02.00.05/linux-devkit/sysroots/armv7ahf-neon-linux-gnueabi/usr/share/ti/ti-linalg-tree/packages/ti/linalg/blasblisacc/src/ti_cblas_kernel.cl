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
/*==============================================================================
 * This file contains the OpenCL kernels of ARM+DSP CBLAS library.
 *============================================================================*/

#define CBLAS_H
#define CBLAS_INDEX size_t  /* this may vary between platforms */
enum CBLAS_ORDER {CblasRowMajor=101, CblasColMajor=102};
enum CBLAS_TRANSPOSE {CblasNoTrans=111, CblasTrans=112, CblasConjTrans=113};
enum CBLAS_UPLO {CblasUpper=121, CblasLower=122};
enum CBLAS_DIAG {CblasNonUnit=131, CblasUnit=132};
enum CBLAS_SIDE {CblasLeft=141, CblasRight=142};

int tiCblasNew(void);
kernel void ocl_bli_init(global int *err_code)
{
  *err_code = tiCblasNew();
}

int tiCblasDelete(void);
kernel void ocl_bli_finalize(global int *err_code)
{
  *err_code = tiCblasDelete();
}

void cblas_caxpy_facade(const int N, global const void *alpha, global const void *X, const int incX, global void *Y, const int incY);
kernel void ocl_cblas_caxpy(const int N, global const void *alpha, global const void *X, const int incX, global void *Y, const int incY)
{ cblas_caxpy_facade(N, alpha, X, incX, Y, incY); }
void cblas_ccopy_facade(const int N, global const void *X, const int incX, global void *Y, const int incY);
kernel void ocl_cblas_ccopy(const int N, global const void *X, const int incX, global void *Y, const int incY)
{ cblas_ccopy_facade(N, X, incX, Y, incY); }
void cblas_cdotc_sub_facade(const int N, global const void *X, const int incX, global const void *Y, const int incY, global void *dotc);
kernel void ocl_cblas_cdotc_sub(const int N, global const void *X, const int incX, global const void *Y, const int incY, global void *dotc)
{ cblas_cdotc_sub_facade(N, X, incX, Y, incY, dotc); }
void cblas_cdotu_sub_facade(const int N, global const void *X, const int incX, global const void *Y, const int incY, global void *dotu);
kernel void ocl_cblas_cdotu_sub(const int N, global const void *X, const int incX, global const void *Y, const int incY, global void *dotu)
{ cblas_cdotu_sub_facade(N, X, incX, Y, incY, dotu); }
void cblas_cgbmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA, const int M, const int N, const int KL, const int KU, global const void *alpha, global const void *A, const int lda, global const void *X, const int incX, global const void *beta, global void *Y, const int incY);
kernel void ocl_cblas_cgbmv(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA, const int M, const int N, const int KL, const int KU, global const void *alpha, global const void *A, const int lda, global const void *X, const int incX, global const void *beta, global void *Y, const int incY)
{ cblas_cgbmv_facade(order, TransA, M, N, KL, KU, alpha, A, lda, X, incX, beta, Y, incY); }
void cblas_cgemm_facade(const enum CBLAS_ORDER Order, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_TRANSPOSE TransB, const int M, const int N, const int K, global const void *alpha, global const void *A, const int lda, global const void *B, const int ldb, global const void *beta, global void *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code);
kernel void ocl_cblas_cgemm(const enum CBLAS_ORDER Order, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_TRANSPOSE TransB, const int M, const int N, const int K, global const void *alpha, global const void *A, const int lda, global const void *B, const int ldb, global const void *beta, global void *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code)
{ cblas_cgemm_facade(Order, TransA, TransB, M, N, K, alpha, A, lda, B, ldb, beta, C, ldc, l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, err_code); }
void cblas_cgemv_facade(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA, const int M, const int N, global const void *alpha, global const void *A, const int lda, global const void *X, const int incX, global const void *beta, global void *Y, const int incY);
kernel void ocl_cblas_cgemv(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA, const int M, const int N, global const void *alpha, global const void *A, const int lda, global const void *X, const int incX, global const void *beta, global void *Y, const int incY)
{ cblas_cgemv_facade(order, TransA, M, N, alpha, A, lda, X, incX, beta, Y, incY); }
void cblas_cgerc_facade(const enum CBLAS_ORDER order, const int M, const int N, global const void *alpha, global const void *X, const int incX, global const void *Y, const int incY, global void *A, const int lda);
kernel void ocl_cblas_cgerc(const enum CBLAS_ORDER order, const int M, const int N, global const void *alpha, global const void *X, const int incX, global const void *Y, const int incY, global void *A, const int lda)
{ cblas_cgerc_facade(order, M, N, alpha, X, incX, Y, incY, A, lda); }
void cblas_cgeru_facade(const enum CBLAS_ORDER order, const int M, const int N, global const void *alpha, global const void *X, const int incX, global const void *Y, const int incY, global void *A, const int lda);
kernel void ocl_cblas_cgeru(const enum CBLAS_ORDER order, const int M, const int N, global const void *alpha, global const void *X, const int incX, global const void *Y, const int incY, global void *A, const int lda)
{ cblas_cgeru_facade(order, M, N, alpha, X, incX, Y, incY, A, lda); }
void cblas_chbmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const int K, global const void *alpha, global const void *A, const int lda, global const void *X, const int incX, global const void *beta, global void *Y, const int incY);
kernel void ocl_cblas_chbmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const int K, global const void *alpha, global const void *A, const int lda, global const void *X, const int incX, global const void *beta, global void *Y, const int incY)
{ cblas_chbmv_facade(order, Uplo, N, K, alpha, A, lda, X, incX, beta, Y, incY); }
void cblas_chemm_facade(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const int M, const int N, global const void *alpha, global const void *A, const int lda, global const void *B, const int ldb, global const void *beta, global void *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code);
kernel void ocl_cblas_chemm(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const int M, const int N, global const void *alpha, global const void *A, const int lda, global const void *B, const int ldb, global const void *beta, global void *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code)
{ cblas_chemm_facade(Order, Side, Uplo, M, N, alpha, A, lda, B, ldb, beta, C, ldc, l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, err_code); }
void cblas_chemv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, global const void *alpha, global const void *A, const int lda, global const void *X, const int incX, global const void *beta, global void *Y, const int incY);
kernel void ocl_cblas_chemv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, global const void *alpha, global const void *A, const int lda, global const void *X, const int incX, global const void *beta, global void *Y, const int incY)
{ cblas_chemv_facade(order, Uplo, N, alpha, A, lda, X, incX, beta, Y, incY); }
void cblas_cher_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const float alpha, global const void *X, const int incX, global void *A, const int lda);
kernel void ocl_cblas_cher(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const float alpha, global const void *X, const int incX, global void *A, const int lda)
{ cblas_cher_facade(order, Uplo, N, alpha, X, incX, A, lda); }
void cblas_cher2_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, global const void *alpha, global const void *X, const int incX, global const void *Y, const int incY, global void *A, const int lda);
kernel void ocl_cblas_cher2(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, global const void *alpha, global const void *X, const int incX, global const void *Y, const int incY, global void *A, const int lda)
{ cblas_cher2_facade(order, Uplo, N, alpha, X, incX, Y, incY, A, lda); }
void cblas_cher2k_facade(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE Trans, const int N, const int K, global const void *alpha, global const void *A, const int lda, global const void *B, const int ldb, const float beta, global void *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code);
kernel void ocl_cblas_cher2k(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE Trans, const int N, const int K, global const void *alpha, global const void *A, const int lda, global const void *B, const int ldb, const float beta, global void *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code)
{ cblas_cher2k_facade(Order, Uplo, Trans, N, K, alpha, A, lda, B, ldb, beta, C, ldc, l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, err_code); }
void cblas_cherk_facade(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE Trans, const int N, const int K, const float alpha, global const void *A, const int lda, const float beta, global void *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code);
kernel void ocl_cblas_cherk(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE Trans, const int N, const int K, const float alpha, global const void *A, const int lda, const float beta, global void *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code)
{ cblas_cherk_facade(Order, Uplo, Trans, N, K, alpha, A, lda, beta, C, ldc, l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, err_code); }
void cblas_chpmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, global const void *alpha, global const void *Ap, global const void *X, const int incX, global const void *beta, global void *Y, const int incY);
kernel void ocl_cblas_chpmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, global const void *alpha, global const void *Ap, global const void *X, const int incX, global const void *beta, global void *Y, const int incY)
{ cblas_chpmv_facade(order, Uplo, N, alpha, Ap, X, incX, beta, Y, incY); }
void cblas_chpr_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const float alpha, global const void *X, const int incX, global void *A);
kernel void ocl_cblas_chpr(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const float alpha, global const void *X, const int incX, global void *A)
{ cblas_chpr_facade(order, Uplo, N, alpha, X, incX, A); }
void cblas_chpr2_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, global const void *alpha, global const void *X, const int incX, global const void *Y, const int incY, global void *Ap);
kernel void ocl_cblas_chpr2(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, global const void *alpha, global const void *X, const int incX, global const void *Y, const int incY, global void *Ap)
{ cblas_chpr2_facade(order, Uplo, N, alpha, X, incX, Y, incY, Ap); }
void cblas_crotg_facade(global void *a, global void *b, global float *c, global void *s);
kernel void ocl_cblas_crotg(global void *a, global void *b, global float *c, global void *s)
{ cblas_crotg_facade(a, b, c, s); }
void cblas_cscal_facade(const int N, global const void *alpha, global void *X, const int incX);
kernel void ocl_cblas_cscal(const int N, global const void *alpha, global void *X, const int incX)
{ cblas_cscal_facade(N, alpha, X, incX); }
void cblas_csscal_facade(const int N, const float alpha, global void *X, const int incX);
kernel void ocl_cblas_csscal(const int N, const float alpha, global void *X, const int incX)
{ cblas_csscal_facade(N, alpha, X, incX); }
void cblas_cswap_facade(const int N, global void *X, const int incX, global void *Y, const int incY);
kernel void ocl_cblas_cswap(const int N, global void *X, const int incX, global void *Y, const int incY)
{ cblas_cswap_facade(N, X, incX, Y, incY); }
void cblas_csymm_facade(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const int M, const int N, global const void *alpha, global const void *A, const int lda, global const void *B, const int ldb, global const void *beta, global void *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code);
kernel void ocl_cblas_csymm(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const int M, const int N, global const void *alpha, global const void *A, const int lda, global const void *B, const int ldb, global const void *beta, global void *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code)
{ cblas_csymm_facade(Order, Side, Uplo, M, N, alpha, A, lda, B, ldb, beta, C, ldc, l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, err_code); }
void cblas_csyr2k_facade(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE Trans, const int N, const int K, global const void *alpha, global const void *A, const int lda, global const void *B, const int ldb, global const void *beta, global void *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code);
kernel void ocl_cblas_csyr2k(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE Trans, const int N, const int K, global const void *alpha, global const void *A, const int lda, global const void *B, const int ldb, global const void *beta, global void *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code)
{ cblas_csyr2k_facade(Order, Uplo, Trans, N, K, alpha, A, lda, B, ldb, beta, C, ldc, l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, err_code); }
void cblas_csyrk_facade(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE Trans, const int N, const int K, global const void *alpha, global const void *A, const int lda, global const void *beta, global void *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code);
kernel void ocl_cblas_csyrk(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE Trans, const int N, const int K, global const void *alpha, global const void *A, const int lda, global const void *beta, global void *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code)
{ cblas_csyrk_facade(Order, Uplo, Trans, N, K, alpha, A, lda, beta, C, ldc, l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, err_code); }
void cblas_ctbmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const int K, global const void *A, const int lda, global void *X, const int incX);
kernel void ocl_cblas_ctbmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const int K, global const void *A, const int lda, global void *X, const int incX)
{ cblas_ctbmv_facade(order, Uplo, TransA, Diag, N, K, A, lda, X, incX); }
void cblas_ctbsv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const int K, global const void *A, const int lda, global void *X, const int incX);
kernel void ocl_cblas_ctbsv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const int K, global const void *A, const int lda, global void *X, const int incX)
{ cblas_ctbsv_facade(order, Uplo, TransA, Diag, N, K, A, lda, X, incX); }
void cblas_ctpmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, global const void *Ap, global void *X, const int incX);
kernel void ocl_cblas_ctpmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, global const void *Ap, global void *X, const int incX)
{ cblas_ctpmv_facade(order, Uplo, TransA, Diag, N, Ap, X, incX); }
void cblas_ctpsv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, global const void *Ap, global void *X, const int incX);
kernel void ocl_cblas_ctpsv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, global const void *Ap, global void *X, const int incX)
{ cblas_ctpsv_facade(order, Uplo, TransA, Diag, N, Ap, X, incX); }
void cblas_ctrmm_facade(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int M, const int N, global const void *alpha, global const void *A, const int lda, global void *B, const int ldb, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code);
kernel void ocl_cblas_ctrmm(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int M, const int N, global const void *alpha, global const void *A, const int lda, global void *B, const int ldb, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code)
{ cblas_ctrmm_facade(Order, Side, Uplo, TransA, Diag, M, N, alpha, A, lda, B, ldb, l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, err_code); }
void cblas_ctrmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, global const void *A, const int lda, global void *X, const int incX);
kernel void ocl_cblas_ctrmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, global const void *A, const int lda, global void *X, const int incX)
{ cblas_ctrmv_facade(order, Uplo, TransA, Diag, N, A, lda, X, incX); }
void cblas_ctrsm_facade(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int M, const int N, global const void *alpha, global const void *A, const int lda, global void *B, const int ldb, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code);
kernel void ocl_cblas_ctrsm(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int M, const int N, global const void *alpha, global const void *A, const int lda, global void *B, const int ldb, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code)
{ cblas_ctrsm_facade(Order, Side, Uplo, TransA, Diag, M, N, alpha, A, lda, B, ldb, l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, err_code); }
void cblas_ctrsv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, global const void *A, const int lda, global void *X, const int incX);
kernel void ocl_cblas_ctrsv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, global const void *A, const int lda, global void *X, const int incX)
{ cblas_ctrsv_facade(order, Uplo, TransA, Diag, N, A, lda, X, incX); }
void cblas_dasum_facade(const int N, global const double *X, const int incX, global double *retval);
kernel void ocl_cblas_dasum(const int N, global const double *X, const int incX, global double *retval)
{ cblas_dasum_facade(N, X, incX, retval); }
void cblas_daxpy_facade(const int N, const double alpha, global const double *X, const int incX, global double *Y, const int incY);
kernel void ocl_cblas_daxpy(const int N, const double alpha, global const double *X, const int incX, global double *Y, const int incY)
{ cblas_daxpy_facade(N, alpha, X, incX, Y, incY); }
void cblas_dcopy_facade(const int N, global const double *X, const int incX, global double *Y, const int incY);
kernel void ocl_cblas_dcopy(const int N, global const double *X, const int incX, global double *Y, const int incY)
{ cblas_dcopy_facade(N, X, incX, Y, incY); }
void cblas_ddot_facade(const int N, global const double *X, const int incX, global const double *Y, const int incY, global double *retval);
kernel void ocl_cblas_ddot(const int N, global const double *X, const int incX, global const double *Y, const int incY, global double *retval)
{ cblas_ddot_facade(N, X, incX, Y, incY, retval); }
void cblas_dgbmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA, const int M, const int N, const int KL, const int KU, const double alpha, global const double *A, const int lda, global const double *X, const int incX, const double beta, global double *Y, const int incY);
kernel void ocl_cblas_dgbmv(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA, const int M, const int N, const int KL, const int KU, const double alpha, global const double *A, const int lda, global const double *X, const int incX, const double beta, global double *Y, const int incY)
{ cblas_dgbmv_facade(order, TransA, M, N, KL, KU, alpha, A, lda, X, incX, beta, Y, incY); }
void cblas_dgemm_facade(const enum CBLAS_ORDER Order, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_TRANSPOSE TransB, const int M, const int N, const int K, const double alpha, global const double *A, const int lda, global const double *B, const int ldb, const double beta, global double *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code);
kernel void ocl_cblas_dgemm(const enum CBLAS_ORDER Order, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_TRANSPOSE TransB, const int M, const int N, const int K, const double alpha, global const double *A, const int lda, global const double *B, const int ldb, const double beta, global double *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code)
{ cblas_dgemm_facade(Order, TransA, TransB, M, N, K, alpha, A, lda, B, ldb, beta, C, ldc, l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, err_code); }
void cblas_dgemv_facade(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA, const int M, const int N, const double alpha, global const double *A, const int lda, global const double *X, const int incX, const double beta, global double *Y, const int incY);
kernel void ocl_cblas_dgemv(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA, const int M, const int N, const double alpha, global const double *A, const int lda, global const double *X, const int incX, const double beta, global double *Y, const int incY)
{ cblas_dgemv_facade(order, TransA, M, N, alpha, A, lda, X, incX, beta, Y, incY); }
void cblas_dger_facade(const enum CBLAS_ORDER order, const int M, const int N, const double alpha, global const double *X, const int incX, global const double *Y, const int incY, global double *A, const int lda);
kernel void ocl_cblas_dger(const enum CBLAS_ORDER order, const int M, const int N, const double alpha, global const double *X, const int incX, global const double *Y, const int incY, global double *A, const int lda)
{ cblas_dger_facade(order, M, N, alpha, X, incX, Y, incY, A, lda); }
void cblas_dnrm2_facade(const int N, global const double *X, const int incX, global double *retval);
kernel void ocl_cblas_dnrm2(const int N, global const double *X, const int incX, global double *retval)
{ cblas_dnrm2_facade(N, X, incX, retval); }
void cblas_drot_facade(const int N, global double *X, const int incX, global double *Y, const int incY, const double c, const double s);
kernel void ocl_cblas_drot(const int N, global double *X, const int incX, global double *Y, const int incY, const double c, const double s)
{ cblas_drot_facade(N, X, incX, Y, incY, c, s); }
void cblas_drotg_facade(global double *a, global double *b, global double *c, global double *s);
kernel void ocl_cblas_drotg(global double *a, global double *b, global double *c, global double *s)
{ cblas_drotg_facade(a, b, c, s); }
void cblas_drotm_facade(const int N, global double *X, const int incX, global double *Y, const int incY, global const double *P);
kernel void ocl_cblas_drotm(const int N, global double *X, const int incX, global double *Y, const int incY, global const double *P)
{ cblas_drotm_facade(N, X, incX, Y, incY, P); }
void cblas_drotmg_facade(global double *d1, global double *d2, global double *b1, const double b2, global double *P);
kernel void ocl_cblas_drotmg(global double *d1, global double *d2, global double *b1, const double b2, global double *P)
{ cblas_drotmg_facade(d1, d2, b1, b2, P); }
void cblas_dsbmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const int K, const double alpha, global const double *A, const int lda, global const double *X, const int incX, const double beta, global double *Y, const int incY);
kernel void ocl_cblas_dsbmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const int K, const double alpha, global const double *A, const int lda, global const double *X, const int incX, const double beta, global double *Y, const int incY)
{ cblas_dsbmv_facade(order, Uplo, N, K, alpha, A, lda, X, incX, beta, Y, incY); }
void cblas_dscal_facade(const int N, const double alpha, global double *X, const int incX);
kernel void ocl_cblas_dscal(const int N, const double alpha, global double *X, const int incX)
{ cblas_dscal_facade(N, alpha, X, incX); }
void cblas_dsdot_facade(const int N, global const float *X, const int incX, global const float *Y, const int incY, global double *retval);
kernel void ocl_cblas_dsdot(const int N, global const float *X, const int incX, global const float *Y, const int incY, global double *retval)
{ cblas_dsdot_facade(N, X, incX, Y, incY, retval); }
void cblas_dspmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const double alpha, global const double *Ap, global const double *X, const int incX, const double beta, global double *Y, const int incY);
kernel void ocl_cblas_dspmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const double alpha, global const double *Ap, global const double *X, const int incX, const double beta, global double *Y, const int incY)
{ cblas_dspmv_facade(order, Uplo, N, alpha, Ap, X, incX, beta, Y, incY); }
void cblas_dspr_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const double alpha, global const double *X, const int incX, global double *Ap);
kernel void ocl_cblas_dspr(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const double alpha, global const double *X, const int incX, global double *Ap)
{ cblas_dspr_facade(order, Uplo, N, alpha, X, incX, Ap); }
void cblas_dspr2_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const double alpha, global const double *X, const int incX, global const double *Y, const int incY, global double *A);
kernel void ocl_cblas_dspr2(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const double alpha, global const double *X, const int incX, global const double *Y, const int incY, global double *A)
{ cblas_dspr2_facade(order, Uplo, N, alpha, X, incX, Y, incY, A); }
void cblas_dswap_facade(const int N, global double *X, const int incX, global double *Y, const int incY);
kernel void ocl_cblas_dswap(const int N, global double *X, const int incX, global double *Y, const int incY)
{ cblas_dswap_facade(N, X, incX, Y, incY); }
void cblas_dsymm_facade(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const int M, const int N, const double alpha, global const double *A, const int lda, global const double *B, const int ldb, const double beta, global double *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code);
kernel void ocl_cblas_dsymm(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const int M, const int N, const double alpha, global const double *A, const int lda, global const double *B, const int ldb, const double beta, global double *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code)
{ cblas_dsymm_facade(Order, Side, Uplo, M, N, alpha, A, lda, B, ldb, beta, C, ldc, l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, err_code); }
void cblas_dsymv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const double alpha, global const double *A, const int lda, global const double *X, const int incX, const double beta, global double *Y, const int incY);
kernel void ocl_cblas_dsymv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const double alpha, global const double *A, const int lda, global const double *X, const int incX, const double beta, global double *Y, const int incY)
{ cblas_dsymv_facade(order, Uplo, N, alpha, A, lda, X, incX, beta, Y, incY); }
void cblas_dsyr_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const double alpha, global const double *X, const int incX, global double *A, const int lda);
kernel void ocl_cblas_dsyr(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const double alpha, global const double *X, const int incX, global double *A, const int lda)
{ cblas_dsyr_facade(order, Uplo, N, alpha, X, incX, A, lda); }
void cblas_dsyr2_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const double alpha, global const double *X, const int incX, global const double *Y, const int incY, global double *A, const int lda);
kernel void ocl_cblas_dsyr2(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const double alpha, global const double *X, const int incX, global const double *Y, const int incY, global double *A, const int lda)
{ cblas_dsyr2_facade(order, Uplo, N, alpha, X, incX, Y, incY, A, lda); }
void cblas_dsyr2k_facade(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE Trans, const int N, const int K, const double alpha, global const double *A, const int lda, global const double *B, const int ldb, const double beta, global double *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code);
kernel void ocl_cblas_dsyr2k(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE Trans, const int N, const int K, const double alpha, global const double *A, const int lda, global const double *B, const int ldb, const double beta, global double *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code)
{ cblas_dsyr2k_facade(Order, Uplo, Trans, N, K, alpha, A, lda, B, ldb, beta, C, ldc, l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, err_code); }
void cblas_dsyrk_facade(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE Trans, const int N, const int K, const double alpha, global const double *A, const int lda, const double beta, global double *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code);
kernel void ocl_cblas_dsyrk(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE Trans, const int N, const int K, const double alpha, global const double *A, const int lda, const double beta, global double *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code)
{ cblas_dsyrk_facade(Order, Uplo, Trans, N, K, alpha, A, lda, beta, C, ldc, l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, err_code); }
void cblas_dtbmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const int K, global const double *A, const int lda, global double *X, const int incX);
kernel void ocl_cblas_dtbmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const int K, global const double *A, const int lda, global double *X, const int incX)
{ cblas_dtbmv_facade(order, Uplo, TransA, Diag, N, K, A, lda, X, incX); }
void cblas_dtbsv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const int K, global const double *A, const int lda, global double *X, const int incX);
kernel void ocl_cblas_dtbsv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const int K, global const double *A, const int lda, global double *X, const int incX)
{ cblas_dtbsv_facade(order, Uplo, TransA, Diag, N, K, A, lda, X, incX); }
void cblas_dtpmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, global const double *Ap, global double *X, const int incX);
kernel void ocl_cblas_dtpmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, global const double *Ap, global double *X, const int incX)
{ cblas_dtpmv_facade(order, Uplo, TransA, Diag, N, Ap, X, incX); }
void cblas_dtpsv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, global const double *Ap, global double *X, const int incX);
kernel void ocl_cblas_dtpsv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, global const double *Ap, global double *X, const int incX)
{ cblas_dtpsv_facade(order, Uplo, TransA, Diag, N, Ap, X, incX); }
void cblas_dtrmm_facade(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int M, const int N, const double alpha, global const double *A, const int lda, global double *B, const int ldb, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code);
kernel void ocl_cblas_dtrmm(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int M, const int N, const double alpha, global const double *A, const int lda, global double *B, const int ldb, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code)
{ cblas_dtrmm_facade(Order, Side, Uplo, TransA, Diag, M, N, alpha, A, lda, B, ldb, l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, err_code); }
void cblas_dtrmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, global const double *A, const int lda, global double *X, const int incX);
kernel void ocl_cblas_dtrmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, global const double *A, const int lda, global double *X, const int incX)
{ cblas_dtrmv_facade(order, Uplo, TransA, Diag, N, A, lda, X, incX); }
void cblas_dtrsm_facade(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int M, const int N, const double alpha, global const double *A, const int lda, global double *B, const int ldb, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code);
kernel void ocl_cblas_dtrsm(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int M, const int N, const double alpha, global const double *A, const int lda, global double *B, const int ldb, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code)
{ cblas_dtrsm_facade(Order, Side, Uplo, TransA, Diag, M, N, alpha, A, lda, B, ldb, l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, err_code); }
void cblas_dtrsv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, global const double *A, const int lda, global double *X, const int incX);
kernel void ocl_cblas_dtrsv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, global const double *A, const int lda, global double *X, const int incX)
{ cblas_dtrsv_facade(order, Uplo, TransA, Diag, N, A, lda, X, incX); }
void cblas_dzasum_facade(const int N, global const void *X, const int incX, global double *retval);
kernel void ocl_cblas_dzasum(const int N, global const void *X, const int incX, global double *retval)
{ cblas_dzasum_facade(N, X, incX, retval); }
void cblas_dznrm2_facade(const int N, global const void *X, const int incX, global double *retval);
kernel void ocl_cblas_dznrm2(const int N, global const void *X, const int incX, global double *retval)
{ cblas_dznrm2_facade(N, X, incX, retval); }
void cblas_icamax_facade(const int N, global const void *X, const int incX, global CBLAS_INDEX *retval);
kernel void ocl_cblas_icamax(const int N, global const void *X, const int incX, global CBLAS_INDEX *retval)
{ cblas_icamax_facade(N, X, incX, retval); }
void cblas_idamax_facade(const int N, global const double *X, const int incX, global CBLAS_INDEX *retval);
kernel void ocl_cblas_idamax(const int N, global const double *X, const int incX, global CBLAS_INDEX *retval)
{ cblas_idamax_facade(N, X, incX, retval); }
void cblas_isamax_facade(const int N, global const float *X, const int incX, global CBLAS_INDEX *retval);
kernel void ocl_cblas_isamax(const int N, global const float *X, const int incX, global CBLAS_INDEX *retval)
{ cblas_isamax_facade(N, X, incX, retval); }
void cblas_izamax_facade(const int N, global const void *X, const int incX, global CBLAS_INDEX *retval);
kernel void ocl_cblas_izamax(const int N, global const void *X, const int incX, global CBLAS_INDEX *retval)
{ cblas_izamax_facade(N, X, incX, retval); }
void cblas_sasum_facade(const int N, global const float *X, const int incX, global float *retval);
kernel void ocl_cblas_sasum(const int N, global const float *X, const int incX, global float *retval)
{ cblas_sasum_facade(N, X, incX, retval); }
void cblas_saxpy_facade(const int N, const float alpha, global const float *X, const int incX, global float *Y, const int incY);
kernel void ocl_cblas_saxpy(const int N, const float alpha, global const float *X, const int incX, global float *Y, const int incY)
{ cblas_saxpy_facade(N, alpha, X, incX, Y, incY); }
void cblas_scasum_facade(const int N, global const void *X, const int incX, global float *retval);
kernel void ocl_cblas_scasum(const int N, global const void *X, const int incX, global float *retval)
{ cblas_scasum_facade(N, X, incX, retval); }
void cblas_scnrm2_facade(const int N, global const void *X, const int incX, global float *retval);
kernel void ocl_cblas_scnrm2(const int N, global const void *X, const int incX, global float *retval)
{ cblas_scnrm2_facade(N, X, incX, retval); }
void cblas_scopy_facade(const int N, global const float *X, const int incX, global float *Y, const int incY);
kernel void ocl_cblas_scopy(const int N, global const float *X, const int incX, global float *Y, const int incY)
{ cblas_scopy_facade(N, X, incX, Y, incY); }
void cblas_sdot_facade(const int N, global const float *X, const int incX, global const float *Y, const int incY, global float *retval);
kernel void ocl_cblas_sdot(const int N, global const float *X, const int incX, global const float *Y, const int incY, global float *retval)
{ cblas_sdot_facade(N, X, incX, Y, incY, retval); }
void cblas_sdsdot_facade(const int N, const float alpha, global const float *X, const int incX, global const float *Y, const int incY, global float *retval);
kernel void ocl_cblas_sdsdot(const int N, const float alpha, global const float *X, const int incX, global const float *Y, const int incY, global float *retval)
{ cblas_sdsdot_facade(N, alpha, X, incX, Y, incY, retval); }
void cblas_sgbmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA, const int M, const int N, const int KL, const int KU, const float alpha, global const float *A, const int lda, global const float *X, const int incX, const float beta, global float *Y, const int incY);
kernel void ocl_cblas_sgbmv(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA, const int M, const int N, const int KL, const int KU, const float alpha, global const float *A, const int lda, global const float *X, const int incX, const float beta, global float *Y, const int incY)
{ cblas_sgbmv_facade(order, TransA, M, N, KL, KU, alpha, A, lda, X, incX, beta, Y, incY); }
void cblas_sgemm_facade(const enum CBLAS_ORDER Order, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_TRANSPOSE TransB, const int M, const int N, const int K, const float alpha, global const float *A, const int lda, global const float *B, const int ldb, const float beta, global float *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code);
kernel void ocl_cblas_sgemm(const enum CBLAS_ORDER Order, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_TRANSPOSE TransB, const int M, const int N, const int K, const float alpha, global const float *A, const int lda, global const float *B, const int ldb, const float beta, global float *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code)
{ cblas_sgemm_facade(Order, TransA, TransB, M, N, K, alpha, A, lda, B, ldb, beta, C, ldc, l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, err_code); }
void cblas_sgemv_facade(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA, const int M, const int N, const float alpha, global const float *A, const int lda, global const float *X, const int incX, const float beta, global float *Y, const int incY);
kernel void ocl_cblas_sgemv(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA, const int M, const int N, const float alpha, global const float *A, const int lda, global const float *X, const int incX, const float beta, global float *Y, const int incY)
{ cblas_sgemv_facade(order, TransA, M, N, alpha, A, lda, X, incX, beta, Y, incY); }
void cblas_sger_facade(const enum CBLAS_ORDER order, const int M, const int N, const float alpha, global const float *X, const int incX, global const float *Y, const int incY, global float *A, const int lda);
kernel void ocl_cblas_sger(const enum CBLAS_ORDER order, const int M, const int N, const float alpha, global const float *X, const int incX, global const float *Y, const int incY, global float *A, const int lda)
{ cblas_sger_facade(order, M, N, alpha, X, incX, Y, incY, A, lda); }
void cblas_snrm2_facade(const int N, global const float *X, const int incX, global float *retval);
kernel void ocl_cblas_snrm2(const int N, global const float *X, const int incX, global float *retval)
{ cblas_snrm2_facade(N, X, incX, retval); }
void cblas_srot_facade(const int N, global float *X, const int incX, global float *Y, const int incY, const float c, const float s);
kernel void ocl_cblas_srot(const int N, global float *X, const int incX, global float *Y, const int incY, const float c, const float s)
{ cblas_srot_facade(N, X, incX, Y, incY, c, s); }
void cblas_srotg_facade(global float *a, global float *b, global float *c, global float *s);
kernel void ocl_cblas_srotg(global float *a, global float *b, global float *c, global float *s)
{ cblas_srotg_facade(a, b, c, s); }
void cblas_srotm_facade(const int N, global float *X, const int incX, global float *Y, const int incY, global const float *P);
kernel void ocl_cblas_srotm(const int N, global float *X, const int incX, global float *Y, const int incY, global const float *P)
{ cblas_srotm_facade(N, X, incX, Y, incY, P); }
void cblas_srotmg_facade(global float *d1, global float *d2, global float *b1, const float b2, global float *P);
kernel void ocl_cblas_srotmg(global float *d1, global float *d2, global float *b1, const float b2, global float *P)
{ cblas_srotmg_facade(d1, d2, b1, b2, P); }
void cblas_ssbmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const int K, const float alpha, global const float *A, const int lda, global const float *X, const int incX, const float beta, global float *Y, const int incY);
kernel void ocl_cblas_ssbmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const int K, const float alpha, global const float *A, const int lda, global const float *X, const int incX, const float beta, global float *Y, const int incY)
{ cblas_ssbmv_facade(order, Uplo, N, K, alpha, A, lda, X, incX, beta, Y, incY); }
void cblas_sscal_facade(const int N, const float alpha, global float *X, const int incX);
kernel void ocl_cblas_sscal(const int N, const float alpha, global float *X, const int incX)
{ cblas_sscal_facade(N, alpha, X, incX); }
void cblas_sspmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const float alpha, global const float *Ap, global const float *X, const int incX, const float beta, global float *Y, const int incY);
kernel void ocl_cblas_sspmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const float alpha, global const float *Ap, global const float *X, const int incX, const float beta, global float *Y, const int incY)
{ cblas_sspmv_facade(order, Uplo, N, alpha, Ap, X, incX, beta, Y, incY); }
void cblas_sspr_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const float alpha, global const float *X, const int incX, global float *Ap);
kernel void ocl_cblas_sspr(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const float alpha, global const float *X, const int incX, global float *Ap)
{ cblas_sspr_facade(order, Uplo, N, alpha, X, incX, Ap); }
void cblas_sspr2_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const float alpha, global const float *X, const int incX, global const float *Y, const int incY, global float *A);
kernel void ocl_cblas_sspr2(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const float alpha, global const float *X, const int incX, global const float *Y, const int incY, global float *A)
{ cblas_sspr2_facade(order, Uplo, N, alpha, X, incX, Y, incY, A); }
void cblas_sswap_facade(const int N, global float *X, const int incX, global float *Y, const int incY);
kernel void ocl_cblas_sswap(const int N, global float *X, const int incX, global float *Y, const int incY)
{ cblas_sswap_facade(N, X, incX, Y, incY); }
void cblas_ssymm_facade(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const int M, const int N, const float alpha, global const float *A, const int lda, global const float *B, const int ldb, const float beta, global float *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code);
kernel void ocl_cblas_ssymm(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const int M, const int N, const float alpha, global const float *A, const int lda, global const float *B, const int ldb, const float beta, global float *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code)
{ cblas_ssymm_facade(Order, Side, Uplo, M, N, alpha, A, lda, B, ldb, beta, C, ldc, l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, err_code); }
void cblas_ssymv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const float alpha, global const float *A, const int lda, global const float *X, const int incX, const float beta, global float *Y, const int incY);
kernel void ocl_cblas_ssymv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const float alpha, global const float *A, const int lda, global const float *X, const int incX, const float beta, global float *Y, const int incY)
{ cblas_ssymv_facade(order, Uplo, N, alpha, A, lda, X, incX, beta, Y, incY); }
void cblas_ssyr_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const float alpha, global const float *X, const int incX, global float *A, const int lda);
kernel void ocl_cblas_ssyr(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const float alpha, global const float *X, const int incX, global float *A, const int lda)
{ cblas_ssyr_facade(order, Uplo, N, alpha, X, incX, A, lda); }
void cblas_ssyr2_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const float alpha, global const float *X, const int incX, global const float *Y, const int incY, global float *A, const int lda);
kernel void ocl_cblas_ssyr2(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const float alpha, global const float *X, const int incX, global const float *Y, const int incY, global float *A, const int lda)
{ cblas_ssyr2_facade(order, Uplo, N, alpha, X, incX, Y, incY, A, lda); }
void cblas_ssyr2k_facade(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE Trans, const int N, const int K, const float alpha, global const float *A, const int lda, global const float *B, const int ldb, const float beta, global float *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code);
kernel void ocl_cblas_ssyr2k(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE Trans, const int N, const int K, const float alpha, global const float *A, const int lda, global const float *B, const int ldb, const float beta, global float *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code)
{ cblas_ssyr2k_facade(Order, Uplo, Trans, N, K, alpha, A, lda, B, ldb, beta, C, ldc, l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, err_code); }
void cblas_ssyrk_facade(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE Trans, const int N, const int K, const float alpha, global const float *A, const int lda, const float beta, global float *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code);
kernel void ocl_cblas_ssyrk(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE Trans, const int N, const int K, const float alpha, global const float *A, const int lda, const float beta, global float *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code)
{ cblas_ssyrk_facade(Order, Uplo, Trans, N, K, alpha, A, lda, beta, C, ldc, l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, err_code); }
void cblas_stbmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const int K, global const float *A, const int lda, global float *X, const int incX);
kernel void ocl_cblas_stbmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const int K, global const float *A, const int lda, global float *X, const int incX)
{ cblas_stbmv_facade(order, Uplo, TransA, Diag, N, K, A, lda, X, incX); }
void cblas_stbsv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const int K, global const float *A, const int lda, global float *X, const int incX);
kernel void ocl_cblas_stbsv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const int K, global const float *A, const int lda, global float *X, const int incX)
{ cblas_stbsv_facade(order, Uplo, TransA, Diag, N, K, A, lda, X, incX); }
void cblas_stpmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, global const float *Ap, global float *X, const int incX);
kernel void ocl_cblas_stpmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, global const float *Ap, global float *X, const int incX)
{ cblas_stpmv_facade(order, Uplo, TransA, Diag, N, Ap, X, incX); }
void cblas_stpsv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, global const float *Ap, global float *X, const int incX);
kernel void ocl_cblas_stpsv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, global const float *Ap, global float *X, const int incX)
{ cblas_stpsv_facade(order, Uplo, TransA, Diag, N, Ap, X, incX); }
void cblas_strmm_facade(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int M, const int N, const float alpha, global const float *A, const int lda, global float *B, const int ldb, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code);
kernel void ocl_cblas_strmm(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int M, const int N, const float alpha, global const float *A, const int lda, global float *B, const int ldb, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code)
{ cblas_strmm_facade(Order, Side, Uplo, TransA, Diag, M, N, alpha, A, lda, B, ldb, l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, err_code); }
void cblas_strmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, global const float *A, const int lda, global float *X, const int incX);
kernel void ocl_cblas_strmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, global const float *A, const int lda, global float *X, const int incX)
{ cblas_strmv_facade(order, Uplo, TransA, Diag, N, A, lda, X, incX); }
void cblas_strsm_facade(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int M, const int N, const float alpha, global const float *A, const int lda, global float *B, const int ldb, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code);
kernel void ocl_cblas_strsm(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int M, const int N, const float alpha, global const float *A, const int lda, global float *B, const int ldb, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code)
{ cblas_strsm_facade(Order, Side, Uplo, TransA, Diag, M, N, alpha, A, lda, B, ldb, l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, err_code); }
void cblas_strsv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, global const float *A, const int lda, global float *X, const int incX);
kernel void ocl_cblas_strsv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, global const float *A, const int lda, global float *X, const int incX)
{ cblas_strsv_facade(order, Uplo, TransA, Diag, N, A, lda, X, incX); }
void cblas_xerbla_facade(int p, global const char *rout, global const char *form);
kernel void ocl_cblas_xerbla(int p, global const char *rout, global const char *form)
{ cblas_xerbla_facade(p, rout, form); }
void cblas_zaxpy_facade(const int N, global const void *alpha, global const void *X, const int incX, global void *Y, const int incY);
kernel void ocl_cblas_zaxpy(const int N, global const void *alpha, global const void *X, const int incX, global void *Y, const int incY)
{ cblas_zaxpy_facade(N, alpha, X, incX, Y, incY); }
void cblas_zcopy_facade(const int N, global const void *X, const int incX, global void *Y, const int incY);
kernel void ocl_cblas_zcopy(const int N, global const void *X, const int incX, global void *Y, const int incY)
{ cblas_zcopy_facade(N, X, incX, Y, incY); }
void cblas_zdotc_sub_facade(const int N, global const void *X, const int incX, global const void *Y, const int incY, global void *dotc);
kernel void ocl_cblas_zdotc_sub(const int N, global const void *X, const int incX, global const void *Y, const int incY, global void *dotc)
{ cblas_zdotc_sub_facade(N, X, incX, Y, incY, dotc); }
void cblas_zdotu_sub_facade(const int N, global const void *X, const int incX, global const void *Y, const int incY, global void *dotu);
kernel void ocl_cblas_zdotu_sub(const int N, global const void *X, const int incX, global const void *Y, const int incY, global void *dotu)
{ cblas_zdotu_sub_facade(N, X, incX, Y, incY, dotu); }
void cblas_zdscal_facade(const int N, const double alpha, global void *X, const int incX);
kernel void ocl_cblas_zdscal(const int N, const double alpha, global void *X, const int incX)
{ cblas_zdscal_facade(N, alpha, X, incX); }
void cblas_zgbmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA, const int M, const int N, const int KL, const int KU, global const void *alpha, global const void *A, const int lda, global const void *X, const int incX, global const void *beta, global void *Y, const int incY);
kernel void ocl_cblas_zgbmv(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA, const int M, const int N, const int KL, const int KU, global const void *alpha, global const void *A, const int lda, global const void *X, const int incX, global const void *beta, global void *Y, const int incY)
{ cblas_zgbmv_facade(order, TransA, M, N, KL, KU, alpha, A, lda, X, incX, beta, Y, incY); }
void cblas_zgemm_facade(const enum CBLAS_ORDER Order, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_TRANSPOSE TransB, const int M, const int N, const int K, global const void *alpha, global const void *A, const int lda, global const void *B, const int ldb, global const void *beta, global void *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code);
kernel void ocl_cblas_zgemm(const enum CBLAS_ORDER Order, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_TRANSPOSE TransB, const int M, const int N, const int K, global const void *alpha, global const void *A, const int lda, global const void *B, const int ldb, global const void *beta, global void *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code)
{ cblas_zgemm_facade(Order, TransA, TransB, M, N, K, alpha, A, lda, B, ldb, beta, C, ldc, l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, err_code); }
void cblas_zgemv_facade(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA, const int M, const int N, global const void *alpha, global const void *A, const int lda, global const void *X, const int incX, global const void *beta, global void *Y, const int incY);
kernel void ocl_cblas_zgemv(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA, const int M, const int N, global const void *alpha, global const void *A, const int lda, global const void *X, const int incX, global const void *beta, global void *Y, const int incY)
{ cblas_zgemv_facade(order, TransA, M, N, alpha, A, lda, X, incX, beta, Y, incY); }
void cblas_zgerc_facade(const enum CBLAS_ORDER order, const int M, const int N, global const void *alpha, global const void *X, const int incX, global const void *Y, const int incY, global void *A, const int lda);
kernel void ocl_cblas_zgerc(const enum CBLAS_ORDER order, const int M, const int N, global const void *alpha, global const void *X, const int incX, global const void *Y, const int incY, global void *A, const int lda)
{ cblas_zgerc_facade(order, M, N, alpha, X, incX, Y, incY, A, lda); }
void cblas_zgeru_facade(const enum CBLAS_ORDER order, const int M, const int N, global const void *alpha, global const void *X, const int incX, global const void *Y, const int incY, global void *A, const int lda);
kernel void ocl_cblas_zgeru(const enum CBLAS_ORDER order, const int M, const int N, global const void *alpha, global const void *X, const int incX, global const void *Y, const int incY, global void *A, const int lda)
{ cblas_zgeru_facade(order, M, N, alpha, X, incX, Y, incY, A, lda); }
void cblas_zhbmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const int K, global const void *alpha, global const void *A, const int lda, global const void *X, const int incX, global const void *beta, global void *Y, const int incY);
kernel void ocl_cblas_zhbmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const int K, global const void *alpha, global const void *A, const int lda, global const void *X, const int incX, global const void *beta, global void *Y, const int incY)
{ cblas_zhbmv_facade(order, Uplo, N, K, alpha, A, lda, X, incX, beta, Y, incY); }
void cblas_zhemm_facade(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const int M, const int N, global const void *alpha, global const void *A, const int lda, global const void *B, const int ldb, global const void *beta, global void *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code);
kernel void ocl_cblas_zhemm(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const int M, const int N, global const void *alpha, global const void *A, const int lda, global const void *B, const int ldb, global const void *beta, global void *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code)
{ cblas_zhemm_facade(Order, Side, Uplo, M, N, alpha, A, lda, B, ldb, beta, C, ldc, l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, err_code); }
void cblas_zhemv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, global const void *alpha, global const void *A, const int lda, global const void *X, const int incX, global const void *beta, global void *Y, const int incY);
kernel void ocl_cblas_zhemv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, global const void *alpha, global const void *A, const int lda, global const void *X, const int incX, global const void *beta, global void *Y, const int incY)
{ cblas_zhemv_facade(order, Uplo, N, alpha, A, lda, X, incX, beta, Y, incY); }
void cblas_zher_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const double alpha, global const void *X, const int incX, global void *A, const int lda);
kernel void ocl_cblas_zher(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const double alpha, global const void *X, const int incX, global void *A, const int lda)
{ cblas_zher_facade(order, Uplo, N, alpha, X, incX, A, lda); }
void cblas_zher2_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, global const void *alpha, global const void *X, const int incX, global const void *Y, const int incY, global void *A, const int lda);
kernel void ocl_cblas_zher2(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, global const void *alpha, global const void *X, const int incX, global const void *Y, const int incY, global void *A, const int lda)
{ cblas_zher2_facade(order, Uplo, N, alpha, X, incX, Y, incY, A, lda); }
void cblas_zher2k_facade(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE Trans, const int N, const int K, global const void *alpha, global const void *A, const int lda, global const void *B, const int ldb, const double beta, global void *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code);
kernel void ocl_cblas_zher2k(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE Trans, const int N, const int K, global const void *alpha, global const void *A, const int lda, global const void *B, const int ldb, const double beta, global void *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code)
{ cblas_zher2k_facade(Order, Uplo, Trans, N, K, alpha, A, lda, B, ldb, beta, C, ldc, l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, err_code); }
void cblas_zherk_facade(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE Trans, const int N, const int K, const double alpha, global const void *A, const int lda, const double beta, global void *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code);
kernel void ocl_cblas_zherk(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE Trans, const int N, const int K, const double alpha, global const void *A, const int lda, const double beta, global void *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code)
{ cblas_zherk_facade(Order, Uplo, Trans, N, K, alpha, A, lda, beta, C, ldc, l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, err_code); }
void cblas_zhpmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, global const void *alpha, global const void *Ap, global const void *X, const int incX, global const void *beta, global void *Y, const int incY);
kernel void ocl_cblas_zhpmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, global const void *alpha, global const void *Ap, global const void *X, const int incX, global const void *beta, global void *Y, const int incY)
{ cblas_zhpmv_facade(order, Uplo, N, alpha, Ap, X, incX, beta, Y, incY); }
void cblas_zhpr_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const double alpha, global const void *X, const int incX, global void *A);
kernel void ocl_cblas_zhpr(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, const double alpha, global const void *X, const int incX, global void *A)
{ cblas_zhpr_facade(order, Uplo, N, alpha, X, incX, A); }
void cblas_zhpr2_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, global const void *alpha, global const void *X, const int incX, global const void *Y, const int incY, global void *Ap);
kernel void ocl_cblas_zhpr2(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N, global const void *alpha, global const void *X, const int incX, global const void *Y, const int incY, global void *Ap)
{ cblas_zhpr2_facade(order, Uplo, N, alpha, X, incX, Y, incY, Ap); }
void cblas_zrotg_facade(global void *a, global void *b, global double *c, global void *s);
kernel void ocl_cblas_zrotg(global void *a, global void *b, global double *c, global void *s)
{ cblas_zrotg_facade(a, b, c, s); }
void cblas_zscal_facade(const int N, global const void *alpha, global void *X, const int incX);
kernel void ocl_cblas_zscal(const int N, global const void *alpha, global void *X, const int incX)
{ cblas_zscal_facade(N, alpha, X, incX); }
void cblas_zswap_facade(const int N, global void *X, const int incX, global void *Y, const int incY);
kernel void ocl_cblas_zswap(const int N, global void *X, const int incX, global void *Y, const int incY)
{ cblas_zswap_facade(N, X, incX, Y, incY); }
void cblas_zsymm_facade(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const int M, const int N, global const void *alpha, global const void *A, const int lda, global const void *B, const int ldb, global const void *beta, global void *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code);
kernel void ocl_cblas_zsymm(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const int M, const int N, global const void *alpha, global const void *A, const int lda, global const void *B, const int ldb, global const void *beta, global void *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code)
{ cblas_zsymm_facade(Order, Side, Uplo, M, N, alpha, A, lda, B, ldb, beta, C, ldc, l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, err_code); }
void cblas_zsyr2k_facade(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE Trans, const int N, const int K, global const void *alpha, global const void *A, const int lda, global const void *B, const int ldb, global const void *beta, global void *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code);
kernel void ocl_cblas_zsyr2k(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE Trans, const int N, const int K, global const void *alpha, global const void *A, const int lda, global const void *B, const int ldb, global const void *beta, global void *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code)
{ cblas_zsyr2k_facade(Order, Uplo, Trans, N, K, alpha, A, lda, B, ldb, beta, C, ldc, l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, err_code); }
void cblas_zsyrk_facade(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE Trans, const int N, const int K, global const void *alpha, global const void *A, const int lda, global const void *beta, global void *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code);
kernel void ocl_cblas_zsyrk(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE Trans, const int N, const int K, global const void *alpha, global const void *A, const int lda, global const void *beta, global void *C, const int ldc, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code)
{ cblas_zsyrk_facade(Order, Uplo, Trans, N, K, alpha, A, lda, beta, C, ldc, l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, err_code); }
void cblas_ztbmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const int K, global const void *A, const int lda, global void *X, const int incX);
kernel void ocl_cblas_ztbmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const int K, global const void *A, const int lda, global void *X, const int incX)
{ cblas_ztbmv_facade(order, Uplo, TransA, Diag, N, K, A, lda, X, incX); }
void cblas_ztbsv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const int K, global const void *A, const int lda, global void *X, const int incX);
kernel void ocl_cblas_ztbsv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, const int K, global const void *A, const int lda, global void *X, const int incX)
{ cblas_ztbsv_facade(order, Uplo, TransA, Diag, N, K, A, lda, X, incX); }
void cblas_ztpmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, global const void *Ap, global void *X, const int incX);
kernel void ocl_cblas_ztpmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, global const void *Ap, global void *X, const int incX)
{ cblas_ztpmv_facade(order, Uplo, TransA, Diag, N, Ap, X, incX); }
void cblas_ztpsv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, global const void *Ap, global void *X, const int incX);
kernel void ocl_cblas_ztpsv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, global const void *Ap, global void *X, const int incX)
{ cblas_ztpsv_facade(order, Uplo, TransA, Diag, N, Ap, X, incX); }
void cblas_ztrmm_facade(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int M, const int N, global const void *alpha, global const void *A, const int lda, global void *B, const int ldb, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code);
kernel void ocl_cblas_ztrmm(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int M, const int N, global const void *alpha, global const void *A, const int lda, global void *B, const int ldb, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code)
{ cblas_ztrmm_facade(Order, Side, Uplo, TransA, Diag, M, N, alpha, A, lda, B, ldb, l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, err_code); }
void cblas_ztrmv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, global const void *A, const int lda, global void *X, const int incX);
kernel void ocl_cblas_ztrmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, global const void *A, const int lda, global void *X, const int incX)
{ cblas_ztrmv_facade(order, Uplo, TransA, Diag, N, A, lda, X, incX); }
void cblas_ztrsm_facade(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int M, const int N, global const void *alpha, global const void *A, const int lda, global void *B, const int ldb, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code);
kernel void ocl_cblas_ztrsm(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int M, const int N, global const void *alpha, global const void *A, const int lda, global void *B, const int ldb, global void *l3_buf, size_t l3_buf_size, global void *ddr_buf, size_t ddr_buf_size, global int *err_code)
{ cblas_ztrsm_facade(Order, Side, Uplo, TransA, Diag, M, N, alpha, A, lda, B, ldb, l3_buf, l3_buf_size, ddr_buf, ddr_buf_size, err_code); }
void cblas_ztrsv_facade(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, global const void *A, const int lda, global void *X, const int incX);
kernel void ocl_cblas_ztrsv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag, const int N, global const void *A, const int lda, global void *X, const int incX)
{ cblas_ztrsv_facade(order, Uplo, TransA, Diag, N, A, lda, X, incX); }
