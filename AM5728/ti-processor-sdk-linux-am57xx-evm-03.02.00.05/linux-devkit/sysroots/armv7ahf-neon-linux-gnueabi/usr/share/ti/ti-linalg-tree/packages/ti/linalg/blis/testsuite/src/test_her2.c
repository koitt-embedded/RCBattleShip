/*

   BLIS    
   An object-based framework for developing high-performance BLAS-like
   libraries.

   Copyright (C) 2014, The University of Texas at Austin

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    - Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    - Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    - Neither the name of The University of Texas at Austin nor the names
      of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
   HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#include "blis.h"
#include "test_libblis.h"


// Static variables.
static char*     op_str                    = "her2";
static char*     o_types                   = "vvm";  // x y a
static char*     p_types                   = "ucc";  // uploa conjx conjy
static thresh_t  thresh[BLIS_NUM_FP_TYPES] = { { 1e-04, 1e-05 },   // warn, pass for s
                                               { 1e-04, 1e-05 },   // warn, pass for c
                                               { 1e-13, 1e-14 },   // warn, pass for d
                                               { 1e-13, 1e-14 } }; // warn, pass for z

// Local prototypes.
void libblis_test_her2_deps( test_params_t* params,
                             test_op_t*     op );

void libblis_test_her2_experiment( test_params_t* params,
                                   test_op_t*     op,
                                   iface_t        iface,
                                   num_t          datatype,
                                   char*          pc_str,
                                   char*          sc_str,
                                   unsigned int   p_cur,
                                   perf_t*        perf,
                                   double*        resid );

void libblis_test_her2_impl( iface_t   iface,
                             obj_t*    alpha,
                             obj_t*    x,
                             obj_t*    y,
                             obj_t*    a );

void libblis_test_her2_check( obj_t*  alpha,
                              obj_t*  x,
                              obj_t*  y,
                              obj_t*  a,
                              obj_t*  a_orig,
                              double* resid );



void libblis_test_her2_deps( test_params_t* params, test_op_t* op )
{
	libblis_test_randv( params, &(op->ops->randv) );
	libblis_test_randm( params, &(op->ops->randm) );
	libblis_test_normfv( params, &(op->ops->normfv) );
	libblis_test_subv( params, &(op->ops->subv) );
	libblis_test_copym( params, &(op->ops->copym) );
	libblis_test_scal2v( params, &(op->ops->scal2v) );
	libblis_test_dotv( params, &(op->ops->dotv) );
	libblis_test_gemv( params, &(op->ops->gemv) );
}



void libblis_test_her2( test_params_t* params, test_op_t* op )
{

	// Return early if this test has already been done.
	if ( op->test_done == TRUE ) return;

	// Return early if operation is disabled.
	if ( op->op_switch == DISABLE_ALL ||
	     op->ops->l2_over == DISABLE_ALL ) return;

	// Call dependencies first.
	if ( TRUE ) libblis_test_her2_deps( params, op );

	// Execute the test driver for each implementation requested.
	if ( op->front_seq == ENABLE )
	{
		libblis_test_op_driver( params,
		                        op,
		                        BLIS_TEST_SEQ_FRONT_END,
		                        op_str,
		                        p_types,
		                        o_types,
		                        thresh,
		                        libblis_test_her2_experiment );
	}
}



void libblis_test_her2_experiment( test_params_t* params,
                                   test_op_t*     op,
                                   iface_t        iface,
                                   num_t          datatype,
                                   char*          pc_str,
                                   char*          sc_str,
                                   unsigned int   p_cur,
                                   perf_t*        perf,
                                   double*        resid )
{
	unsigned int n_repeats = params->n_repeats;
	unsigned int i;

	double       time_min  = 1e9;
	double       time;

	dim_t        m;

	uplo_t       uploa;
	conj_t       conjx, conjy;

	obj_t        alpha, x, y;
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	dim_t 		 test_way = bli_read_nway_from_env( "BLIS_LB_NT" );
	obj_t	     a[test_way];
	obj_t        a_save[test_way];
	double       resid_local[test_way];
	unsigned int j;
#else
	obj_t        a, a_save;
#endif



	// Map the dimension specifier to an actual dimension.
	m = libblis_test_get_dim_from_prob_size( op->dim_spec[0], p_cur );

	// Map parameter characters to BLIS constants.
	bli_param_map_char_to_blis_uplo( pc_str[0], &uploa );
	bli_param_map_char_to_blis_conj( pc_str[1], &conjx );
	bli_param_map_char_to_blis_conj( pc_str[2], &conjy );

	// Create test scalars.
	bli_obj_scalar_init_detached( datatype, &alpha );

	// Create test operands (vectors and/or matrices).
	libblis_test_vobj_create( params, datatype,
	                          sc_str[0], m,    &x );
	libblis_test_vobj_create( params, datatype,
	                          sc_str[1], m,    &y );
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	for(i = 0; i < test_way; i++)
	{
		libblis_test_mobj_create( params, datatype, BLIS_NO_TRANSPOSE,
		                          sc_str[2], m, m, &a[i] );
		libblis_test_mobj_create( params, datatype, BLIS_NO_TRANSPOSE,
		                          sc_str[2], m, m, &a_save[i] );
	}
#else
	libblis_test_mobj_create( params, datatype, BLIS_NO_TRANSPOSE,
	                          sc_str[2], m, m, &a );
	libblis_test_mobj_create( params, datatype, BLIS_NO_TRANSPOSE,
	                          sc_str[2], m, m, &a_save );
#endif

	// Set alpha.
	//bli_copysc( &BLIS_MINUS_ONE, &alpha );
	bli_setsc( -1.0, 1.0, &alpha );

	// Randomize x and y.
	bli_randv( &x );
	bli_randv( &y );

	// Set the structure and uplo properties of A.
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	for(i = 0; i < test_way; i++)
	{
		bli_obj_set_struc( BLIS_HERMITIAN, a[i] );
		bli_obj_set_uplo( uploa, a[i] );

		// Randomize A, make it densely Hermitian, and zero the unstored triangle
		// to ensure the implementation is reads only from the stored region.
		bli_randm( &a[i] );
		bli_mkherm( &a[i] );
		bli_mktrim( &a[i] );

		// Save A and set its structure and uplo properties.
		bli_obj_set_struc( BLIS_HERMITIAN, a_save[i] );
		bli_obj_set_uplo( uploa, a_save[i] );
		bli_copym( &a[i], &a_save[i] );
	}
#else
	bli_obj_set_struc( BLIS_HERMITIAN, a );
	bli_obj_set_uplo( uploa, a );

	// Randomize A, make it densely Hermitian, and zero the unstored triangle
	// to ensure the implementation is reads only from the stored region.
	bli_randm( &a );
	bli_mkherm( &a );
	bli_mktrim( &a );

	// Save A and set its structure and uplo properties.
	bli_obj_set_struc( BLIS_HERMITIAN, a_save );
	bli_obj_set_uplo( uploa, a_save );
	bli_copym( &a, &a_save );
#endif


	// Apply the remaining parameters.
	bli_obj_set_conj( conjx, x );
	bli_obj_set_conj( conjy, y );

	// Repeat the experiment n_repeats times and record results. 
	for ( i = 0; i < n_repeats; ++i )
	{
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
		// Need only one call to initialize the CBLAS OpenCL kernel
		bli_copym( &a_save[0], &a[0] );

		libblis_test_her2_impl( iface, &alpha, &x, &y, &a[0] );

		//but need to re-initialize C for each of iteration of n_repeats
		for(j = 0; j < test_way; j++)
		{
			bli_copym( &a_save[j], &a[j] );
		}
#else
		bli_copym( &a_save, &a );
		libblis_test_her2_impl( iface, &alpha, &x, &y, &a );
		bli_copym( &a_save, &a );
#endif
		time = bli_clock();

#ifdef BLIS_ENABLE_MULTITHREAD_TEST
#pragma omp parallel num_threads(test_way)
		{
			#pragma omp for
			for(j = 0; j < test_way; j++)
			{
				libblis_test_her2_impl( iface, &alpha, &x, &y, &a[j] );
			}
		}
#else
		libblis_test_her2_impl( iface, &alpha, &x, &y, &a );
#endif

		time_min = bli_clock_min_diff( time_min, time );
	}
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	// Estimate the performance of the best experiment repeat.
	perf->gflops = ( 2.0 * m * m ) * test_way / time_min / FLOPS_PER_UNIT_PERF;
	if ( bli_obj_is_complex( a[0] ) ) perf->gflops *= 4.0;
#else
	// Estimate the performance of the best experiment repeat.
	perf->gflops = ( 2.0 * m * m ) / time_min / FLOPS_PER_UNIT_PERF;
	if ( bli_obj_is_complex( a ) ) perf->gflops *= 4.0;
#endif
	perf->time = time_min;

#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	// Check output of each thread, and send max residue to main
	for(i = 0; i < test_way; i++)
	{
		// Perform checks.
		libblis_test_her2_check( &alpha, &x, &y, &a[i], &a_save[i], &resid_local[i] );

		// Zero out performance and residual if output matrix is empty.
		libblis_test_check_empty_problem( &a[i], perf, &resid_local[i] );

		if(i == 0)
		{
			*resid = resid_local[i];
		}
		else if (resid_local[i] > *resid)
		{
			*resid = resid_local[i];
		}
	}

#else
	// Perform checks.
	libblis_test_her2_check( &alpha, &x, &y, &a, &a_save, resid );

	// Zero out performance and residual if output matrix is empty.
	libblis_test_check_empty_problem( &a, perf, resid );

#endif

	// Free the test objects.
	bli_obj_free( &x );
	bli_obj_free( &y );
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	for(i = 0; i < test_way; i++)
	{
		bli_obj_free( &a[i] );
		bli_obj_free( &a_save[i] );
	}
#else
	bli_obj_free( &a );
	bli_obj_free( &a_save );
#endif
}



void libblis_test_her2_impl( iface_t   iface,
                             obj_t*    alpha,
                             obj_t*    x,
                             obj_t*    y,
                             obj_t*    a )
{
	switch ( iface )
	{
		case BLIS_TEST_SEQ_FRONT_END:
			;
#ifdef CBLAS
			enum CBLAS_ORDER cblas_order;
			enum CBLAS_UPLO cblas_uplo;
			int n;
			int lda, incx, incy;

			void *cblas_alpha;
			void *cblas_a;
			void *cblas_x, *cblas_y;

			cblas_alpha = bli_obj_buffer( *alpha );
			cblas_a     = bli_obj_buffer( *a );
			cblas_x     = bli_obj_buffer( *x );
			cblas_y     = bli_obj_buffer( *y );

			//m     = bli_obj_length( *a );
			n     = bli_obj_width( *a );

			if(bli_obj_is_col_stored( *a ) )
			{
				cblas_order = CblasColMajor;
				lda = bli_obj_col_stride(*a);
			}
			else if(bli_obj_is_row_stored( *a ) )
			{
				cblas_order = CblasRowMajor;
				lda = bli_obj_row_stride(*a);
			}
			else
			{
				bli_check_error_code( BLIS_INVALID_DIM_STRIDE_COMBINATION );
				return;
			}

			incx = bli_obj_vector_inc(*x);
			incy = bli_obj_vector_inc(*y);

			if(bli_obj_is_upper( *a ))
			{
				cblas_uplo = CblasUpper;
			}
			else if (bli_obj_is_lower( *a ))
			{
				cblas_uplo = CblasLower;
			}
			else
			{
				bli_check_error_code( BLIS_INVALID_UPLO );
				return;
			}

			if (bli_obj_is_scomplex( *a ))
			{
				cblas_cher2(cblas_order, cblas_uplo, n, cblas_alpha, cblas_x, incx, cblas_y, incy, cblas_a, lda);
			}
			else if (bli_obj_is_dcomplex( *a ))
			{
				cblas_zher2(cblas_order, cblas_uplo, n, cblas_alpha, cblas_x, incx, cblas_y, incy, cblas_a, lda);
			}
			else
			{
				printf("CBLAS not supported\n");
				return;
			}

#else
			bli_her2( alpha, x, y, a );
#endif
			break;

		default:
		libblis_test_printf_error( "Invalid interface type.\n" );
	}
}



void libblis_test_her2_check( obj_t*  alpha,
                              obj_t*  x,
                              obj_t*  y,
                              obj_t*  a,
                              obj_t*  a_orig,
                              double* resid )
{
	num_t  dt      = bli_obj_datatype( *a );
	num_t  dt_real = bli_obj_datatype_proj_to_real( *a );

	dim_t  m_a     = bli_obj_length( *a );

	obj_t  xh, yh, alphac;
	obj_t  t, v, w1, w2;
	obj_t  tau, rho, norm;

	double junk;

	//
	// Pre-conditions:
	// - x is randomized.
	// - y is randomized.
	// - a is randomized and Hermitian.
	//
	// Under these conditions, we assume that the implementation for
	//
	//   A := A_orig + alpha * conjx(x) * conjy(y)^H + conj(alpha) * conjy(y) * conjx(x)^H
	//
	// is functioning correctly if
	//
	//   normf( v - w )
	//
	// is negligible, where
	//
	//   v = A * t
	//   w = ( A_orig + alpha * conjx(x) * conjy(y)^H + conj(alpha) * conjy(y) * conjx(x)^H ) * t
	//     = A_orig * t + alpha * conjx(x) * conjy(y)^H * t + conj(alpha) * conjy(y) * conjx(x)^H * t
	//     = A_orig * t + alpha * conjx(x) * conjy(y)^H * t + conj(alpha) * conjy(y) * rho
	//     = A_orig * t + alpha * conjx(x) * conjy(y)^H * t + w1
	//     = A_orig * t + alpha * conjx(x) * rho            + w1
	//     = A_orig * t + w2                                + w1
	//

	bli_mkherm( a );
	bli_mkherm( a_orig );
	bli_obj_set_struc( BLIS_GENERAL, *a );
	bli_obj_set_struc( BLIS_GENERAL, *a_orig );
	bli_obj_set_uplo( BLIS_DENSE, *a );
	bli_obj_set_uplo( BLIS_DENSE, *a_orig );

	bli_obj_scalar_init_detached( dt,      &tau );
	bli_obj_scalar_init_detached( dt,      &rho );
	bli_obj_scalar_init_detached( dt,      &alphac );
	bli_obj_scalar_init_detached( dt_real, &norm );

	bli_obj_create( dt, m_a, 1, 0, 0, &t );
	bli_obj_create( dt, m_a, 1, 0, 0, &v );
	bli_obj_create( dt, m_a, 1, 0, 0, &w1 );
	bli_obj_create( dt, m_a, 1, 0, 0, &w2 );

	bli_obj_alias_with_conj( BLIS_CONJUGATE, *x, xh );
	bli_obj_alias_with_conj( BLIS_CONJUGATE, *y, yh );
	bli_obj_alias_with_conj( BLIS_CONJUGATE, *alpha, alphac );

	bli_setsc( 1.0/( double )m_a, -1.0/( double )m_a, &tau );
	bli_setv( &tau, &t );

	bli_gemv( &BLIS_ONE, a, &t, &BLIS_ZERO, &v );

	bli_dotv( &xh, &t, &rho );
	bli_mulsc( &alphac, &rho );
	bli_scal2v( &rho, y, &w1 );

	bli_dotv( &yh, &t, &rho );
	bli_mulsc( alpha, &rho );
	bli_scal2v( &rho, x, &w2 );

	bli_addv( &w2, &w1 );

	bli_gemv( &BLIS_ONE, a_orig, &t, &BLIS_ONE, &w1 );

	bli_subv( &w1, &v );
	bli_normfv( &v, &norm );
	bli_getsc( &norm, resid, &junk );

	bli_obj_free( &t );
	bli_obj_free( &v );
	bli_obj_free( &w1 );
	bli_obj_free( &w2 );
}

