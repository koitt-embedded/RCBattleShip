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
static char*     op_str                    = "dotv";
static char*     o_types                   = "vv";  // x y
static char*     p_types                   = "cc";  // conjx conjy
static thresh_t  thresh[BLIS_NUM_FP_TYPES] = { { 1e-04, 1e-05 },   // warn, pass for s
                                               { 1e-04, 1e-05 },   // warn, pass for c
                                               { 1e-13, 1e-14 },   // warn, pass for d
                                               { 1e-13, 1e-14 } }; // warn, pass for z

// Local prototypes.
void libblis_test_dotv_deps( test_params_t* params,
                             test_op_t*     op );

void libblis_test_dotv_experiment( test_params_t* params,
                                   test_op_t*     op,
                                   iface_t        iface,
                                   num_t          datatype,
                                   char*          pc_str,
                                   char*          sc_str,
                                   unsigned int   p_cur,
                                   perf_t*        perf,
                                   double*        resid );

void libblis_test_dotv_impl( iface_t   iface,
                             obj_t*    x,
                             obj_t*    y,
                             obj_t*    rho );

void libblis_test_dotv_check( obj_t*  x,
                              obj_t*  y,
                              obj_t*  rho,
                              double* resid );



void libblis_test_dotv_deps( test_params_t* params, test_op_t* op )
{
	libblis_test_randv( params, &(op->ops->randv) );
	libblis_test_normfv( params, &(op->ops->normfv) );
	libblis_test_copyv( params, &(op->ops->copyv) );
}



void libblis_test_dotv( test_params_t* params, test_op_t* op )
{

	// Return early if this test has already been done.
	if ( op->test_done == TRUE ) return;

	// Return early if operation is disabled.
	if ( op->op_switch == DISABLE_ALL ||
	     op->ops->l1v_over == DISABLE_ALL ) return;

	// Call dependencies first.
	if ( TRUE ) libblis_test_dotv_deps( params, op );

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
		                        libblis_test_dotv_experiment );
	}
}



void libblis_test_dotv_experiment( test_params_t* params,
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

	conj_t       conjx, conjy, conjconjxy;

	obj_t        x, y;
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	dim_t 		 test_way = bli_read_nway_from_env( "BLIS_LB_NT" );
	obj_t	     rho[test_way];
	double       resid_local[test_way];
	unsigned int j;
#else
	obj_t        rho;
#endif

	// Map the dimension specifier to an actual dimension.
	m = libblis_test_get_dim_from_prob_size( op->dim_spec[0], p_cur );

	// Map parameter characters to BLIS constants.
	bli_param_map_char_to_blis_conj( pc_str[0], &conjx );
	bli_param_map_char_to_blis_conj( pc_str[1], &conjy );

	// Create test scalars.
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	for(i = 0; i < test_way; i++)
	{
		bli_obj_scalar_init_detached( datatype, &rho[i] );
	}
#else
	bli_obj_scalar_init_detached( datatype, &rho );
#endif


	// Create test operands (vectors and/or matrices).
	libblis_test_vobj_create( params, datatype, sc_str[0], m, &x );
	libblis_test_vobj_create( params, datatype, sc_str[1], m, &y );

	// Randomize x.
	bli_randv( &x );

	// Determine whether to make a copy of x with or without conjugation.
	// 
	//  conjx conjy  ~conjx^conjy   y is initialized as
	//  n     n      c              y = conj(x)
	//  n     c      n              y = x
	//  c     n      n              y = x
	//  c     c      c              y = conj(x)
	//
	conjconjxy = bli_apply_conj( conjx, conjy );
	conjconjxy = bli_conj_toggled( conjconjxy );
	bli_obj_set_conj( conjconjxy, x );
	bli_copyv( &x, &y );

	// Apply the parameters.
	bli_obj_set_conj( conjx, x );
	bli_obj_set_conj( conjy, y );

	// Repeat the experiment n_repeats times and record results. 
	for ( i = 0; i < n_repeats; ++i )
	{
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	for(j = 0; j < test_way; j++)
	{
		bli_copysc( &BLIS_MINUS_ONE, &rho[j] );
	}
#else
		bli_copysc( &BLIS_MINUS_ONE, &rho );
#endif

		time = bli_clock();
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
#pragma omp parallel num_threads(test_way)
		{
			#pragma omp for
			for(j = 0; j < test_way; j++)
			{
				libblis_test_dotv_impl( iface, &x, &y, &rho[j] );
			}
		}
#else
		libblis_test_dotv_impl( iface, &x, &y, &rho );
#endif
		time_min = bli_clock_min_diff( time_min, time );
	}
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	// Estimate the performance of the best experiment repeat.
	perf->gflops = ( 2.0 * m ) *test_way / time_min / FLOPS_PER_UNIT_PERF;
	if ( bli_obj_is_complex( y ) ) perf->gflops *= 4.0;
#else
	// Estimate the performance of the best experiment repeat.
	perf->gflops = ( 2.0 * m ) / time_min / FLOPS_PER_UNIT_PERF;
	if ( bli_obj_is_complex( y ) ) perf->gflops *= 4.0;
#endif
	perf->time = time_min;

#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	// Check output of each thread, and send max residue to main
	for(i = 0; i < test_way; i++)
	{
		// Perform checks.
		libblis_test_dotv_check( &x, &y, &rho[i], &resid_local[i] );

		// Zero out performance and residual if output scalar is empty.
		libblis_test_check_empty_problem( &rho[i], perf, &resid_local[i] );

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
	libblis_test_dotv_check( &x, &y, &rho, resid );

	// Zero out performance and residual if output scalar is empty.
	libblis_test_check_empty_problem( &rho, perf, resid );
#endif


	// Free the test objects.
	bli_obj_free( &x );
	bli_obj_free( &y );
}



void libblis_test_dotv_impl( iface_t   iface,
                             obj_t*    x,
                             obj_t*    y,
                             obj_t*    rho )
{
	switch ( iface )
	{
		case BLIS_TEST_SEQ_FRONT_END:
			;
#ifdef CBLAS
			int n;
			int incx, incy;
			enum CBLAS_TRANSPOSE transX;

			n     = bli_obj_vector_dim( *x );
			incx  = bli_obj_vector_inc( *x );
			incy  = bli_obj_vector_inc( *y );


			if(bli_obj_has_notrans( *x ) && bli_obj_has_noconj( *x ))
			{
				transX = CblasNoTrans;
			}
			else if(bli_obj_has_conj( *x ) )
			{
				transX = CblasConjTrans;
			}
			else
			{
				bli_check_error_code( BLIS_INVALID_TRANS );
				return;
			}

			if (bli_obj_is_float( *x ))
			{
				float *cblas_x, *cblas_y;
				cblas_x     = (float *) bli_obj_buffer( *x );
				cblas_y     = (float *) bli_obj_buffer( *y );

				if (bli_obj_is_float(*rho))
				{
					float *cblas_rho;
					cblas_rho   = (float *) bli_obj_buffer( *rho);

					*cblas_rho = cblas_sdot(n, cblas_x, incx, cblas_y, incy);
				}
				else if (bli_obj_is_double(*rho))
				{
					double *cblas_rho;
					cblas_rho   = (double *) bli_obj_buffer( *rho);

					*cblas_rho = cblas_dsdot(n, cblas_x, incx, cblas_y, incy);
				}


			}
			else if (bli_obj_is_double( *y ))
			{
				double *cblas_rho;
				double *cblas_x, *cblas_y;

				cblas_rho   = (double *) bli_obj_buffer( *rho);
				cblas_x     = (double *) bli_obj_buffer( *x );
				cblas_y     = (double *) bli_obj_buffer( *y );

				*cblas_rho = cblas_ddot(n, cblas_x, incx, cblas_y, incy);

			}
			else if (bli_obj_is_scomplex( *y ))
			{
				void *cblas_rho;
				void *cblas_x, *cblas_y;

				cblas_rho   = bli_obj_buffer( *rho);
				cblas_x     = bli_obj_buffer( *x );
				cblas_y     = bli_obj_buffer( *y );

				if(transX == CblasNoTrans)
					cblas_cdotu_sub(n, cblas_x, incx, cblas_y, incy, cblas_rho);
				else if (transX==CblasConjTrans)
					cblas_cdotc_sub(n, cblas_x, incx, cblas_y, incy, cblas_rho);
			}
			else if (bli_obj_is_dcomplex( *y ))
			{
				void *cblas_rho;
				void *cblas_x, *cblas_y;

				cblas_rho = bli_obj_buffer( *rho );
				cblas_x     = bli_obj_buffer( *x );
				cblas_y     = bli_obj_buffer( *y );

				if(transX == CblasNoTrans)
					cblas_zdotu_sub(n, cblas_x, incx, cblas_y, incy, cblas_rho);
				else if (transX==CblasConjTrans)
					cblas_zdotc_sub(n, cblas_x, incx, cblas_y, incy, cblas_rho);
			}

#else
		bli_dotv( x, y, rho );
#endif
		break;

		default:
		libblis_test_printf_error( "Invalid interface type.\n" );
	}
}



void libblis_test_dotv_check( obj_t*  x,
                              obj_t*  y,
                              obj_t*  rho,
                              double* resid )
{
	num_t  dt_real = bli_obj_datatype_proj_to_real( *y );

	obj_t  rho_r, rho_i;
	obj_t  norm_x, norm_xy;

	double zero;
	double junk;

	//
	// Pre-conditions:
	// - x is randomized.
	// - y is equal to conj(conjx(conjy(x))).
	//
	// Under these conditions, we assume that the implementation for
	//
	//   rho := conjx(x^T) conjy(y)
	//
	// is functioning correctly if
	//
	//   sqrtsc( rho.real ) - normf( x )
	//
	// and
	//
	//   rho.imag
	//
	// are negligible.
	//

	bli_obj_scalar_init_detached( dt_real, &rho_r );
	bli_obj_scalar_init_detached( dt_real, &rho_i );
	bli_obj_scalar_init_detached( dt_real, &norm_x );
	bli_obj_scalar_init_detached( dt_real, &norm_xy );

	bli_normfv( x, &norm_x );

	bli_unzipsc( rho, &rho_r, &rho_i );

	bli_sqrtsc( &rho_r, &norm_xy );

	bli_subsc( &norm_x, &norm_xy );
	bli_getsc( &norm_xy, resid, &junk );
	bli_getsc( &rho_i,   &zero, &junk );

	*resid = bli_fmaxabs( *resid, zero );
}

