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
static char*     op_str                    = "scalv";
static char*     o_types                   = "v";  // y
static char*     p_types                   = "c";  // conjbeta
static thresh_t  thresh[BLIS_NUM_FP_TYPES] = { { 1e-04, 1e-05 },   // warn, pass for s
                                               { 1e-04, 1e-05 },   // warn, pass for c
                                               { 1e-13, 1e-14 },   // warn, pass for d
                                               { 1e-13, 1e-14 } }; // warn, pass for z

// Local prototypes.
void libblis_test_scalv_deps( test_params_t* params,
                              test_op_t*     op );

void libblis_test_scalv_experiment( test_params_t* params,
                                    test_op_t*     op,
                                    iface_t        iface,
                                    num_t          datatype,
                                    char*          pc_str,
                                    char*          sc_str,
                                    unsigned int   p_cur,
                                    perf_t*        perf,
                                    double*        resid );

void libblis_test_scalv_impl( iface_t   iface,
                              obj_t*    beta,
                              obj_t*    y );

void libblis_test_scalv_check( obj_t*  beta,
                               obj_t*  y,
                               obj_t*  y_orig,
                               double* resid );



void libblis_test_scalv_deps( test_params_t* params, test_op_t* op )
{
	libblis_test_randv( params, &(op->ops->randv) );
	libblis_test_normfv( params, &(op->ops->normfv) );
	libblis_test_addv( params, &(op->ops->addv) );
	libblis_test_copyv( params, &(op->ops->copyv) );
}



void libblis_test_scalv( test_params_t* params, test_op_t* op )
{

	// Return early if this test has already been done.
	if ( op->test_done == TRUE ) return;

	// Return early if operation is disabled.
	if ( op->op_switch == DISABLE_ALL ||
	     op->ops->l1v_over == DISABLE_ALL ) return;

	// Call dependencies first.
	if ( TRUE ) libblis_test_scalv_deps( params, op );

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
		                        libblis_test_scalv_experiment );
	}
}



void libblis_test_scalv_experiment( test_params_t* params,
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

	conj_t       conjbeta;

	obj_t        beta;
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	dim_t 		 test_way = bli_read_nway_from_env( "BLIS_LB_NT" );
	obj_t	     y[test_way];
	obj_t        y_save[test_way];
	double       resid_local[test_way];
	unsigned int j;
#else
	obj_t        y, y_save;
#endif


	// Map the dimension specifier to an actual dimension.
	m = libblis_test_get_dim_from_prob_size( op->dim_spec[0], p_cur );

	// Map parameter characters to BLIS constants.
	bli_param_map_char_to_blis_conj( pc_str[0], &conjbeta );

	// Create test scalars.
	bli_obj_scalar_init_detached( datatype, &beta );

	// Create test operands (vectors and/or matrices).
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	for(i = 0; i < test_way; i++)
	{
		libblis_test_vobj_create( params, datatype, sc_str[0], m, &y[i] );
		libblis_test_vobj_create( params, datatype, sc_str[0], m, &y_save[i] );
	}
#else
	libblis_test_vobj_create( params, datatype, sc_str[0], m, &y );
	libblis_test_vobj_create( params, datatype, sc_str[0], m, &y_save );
#endif


	// Set beta.
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	if ( bli_obj_is_real( y[0] ) )
#else
	if ( bli_obj_is_real( y ) )
#endif
	{
		bli_setsc( -2.0,  0.0, &beta );
	}
	else
		bli_setsc(  0.0, -2.0, &beta );

	// Randomize and save y.
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	for(i = 0; i < test_way; i++)
	{
		bli_randv( &y[i] );
		bli_copyv( &y[i], &y_save[i] );
	}
#else
	bli_randv( &y );
	bli_copyv( &y, &y_save );
#endif


	// Apply the parameters.
	bli_obj_set_conj( conjbeta, beta );

	// Repeat the experiment n_repeats times and record results. 
	for ( i = 0; i < n_repeats; ++i )
	{
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
		// Need only one call to initialize the CBLAS OpenCL kernel
		bli_copyv( &y_save[0], &y[0] );
		libblis_test_scalv_impl( iface, &beta, &y[0] );


		//but need to re-initialize C for each of iteration of n_repeats
		for(j = 0; j < test_way; j++)
		{
			bli_copyv( &y_save[j], &y[j] );
		}

#else
		bli_copyv( &y_save, &y );
		libblis_test_scalv_impl( iface, &beta, &y );
		bli_copyv( &y_save, &y );
#endif

		time = bli_clock();
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
#pragma omp parallel num_threads(test_way)
		{
			#pragma omp for
			for(j = 0; j < test_way; j++)
			{
				libblis_test_scalv_impl( iface, &beta, &y[j] );
			}
		}
#else
		libblis_test_scalv_impl( iface, &beta, &y );
#endif

		time_min = bli_clock_min_diff( time_min, time );
	}
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	// Estimate the performance of the best experiment repeat.
	perf->gflops = ( 1.0 * m ) *test_way/ time_min / FLOPS_PER_UNIT_PERF;
	if ( bli_obj_is_complex( y[0] ) ) perf->gflops *= 6.0;
#else
	// Estimate the performance of the best experiment repeat.
	perf->gflops = ( 1.0 * m ) / time_min / FLOPS_PER_UNIT_PERF;
	if ( bli_obj_is_complex( y ) ) perf->gflops *= 6.0;
#endif
	perf->time = time_min;

#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	// Check output of each thread, and send max residue to main
	for(i = 0; i < test_way; i++)
	{
		// Perform checks.
		libblis_test_scalv_check( &beta, &y[i], &y_save[i], &resid_local[i] );

		// Zero out performance and residual if output vector is empty.
		libblis_test_check_empty_problem( &y[i], perf, &resid_local[i] );

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
	libblis_test_scalv_check( &beta, &y, &y_save, resid );

	// Zero out performance and residual if output vector is empty.
	libblis_test_check_empty_problem( &y, perf, resid );
#endif


	// Free the test objects.
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	for(i = 0; i < test_way; i++)
	{
		bli_obj_free( &y[i] );
		bli_obj_free( &y_save[i] );
	}
#else
	bli_obj_free( &y );
	bli_obj_free( &y_save );
#endif

}



void libblis_test_scalv_impl( iface_t   iface,
                              obj_t*    beta,
                              obj_t*    y )
{
	switch ( iface )
	{
		case BLIS_TEST_SEQ_FRONT_END:
			;
#ifdef CBLAS
			int n;
			int incy;

			n     = bli_obj_vector_dim( *y );
			incy  = bli_obj_vector_inc( *y );

			if (bli_obj_is_float( *y ))
			{
				float *cblas_beta;
				float *cblas_y;

				cblas_beta = (float *) bli_obj_buffer( *beta );
				cblas_y     = (float *) bli_obj_buffer( *y );

				cblas_sscal(n, *cblas_beta, cblas_y, incy);

			}
			else if (bli_obj_is_double( *y ))
			{
				double *cblas_beta;
				double *cblas_y;

				cblas_beta = (double *) bli_obj_buffer( *beta );
				cblas_y     = (double *) bli_obj_buffer( *y );

				cblas_dscal(n, *cblas_beta, cblas_y, incy);

			}
			else if (bli_obj_is_scomplex( *y ))
			{
				void *cblas_y;
				cblas_y     = bli_obj_buffer( *y );

				if (bli_obj_is_scomplex(*beta))
				{
					void *cblas_beta;
					cblas_beta = bli_obj_buffer( *beta );
					cblas_cscal(n, cblas_beta, cblas_y, incy);
				}
				else if(bli_obj_is_float(*beta))
				{
					float *cblas_beta;
					cblas_beta = (float *) bli_obj_buffer( *beta );
					cblas_csscal(n, *cblas_beta, cblas_y, incy);

				}



			}
			else if (bli_obj_is_dcomplex( *y ))
			{
				void *cblas_y;
				cblas_y     = bli_obj_buffer( *y );

				if (bli_obj_is_dcomplex(*beta))
				{
					void *cblas_beta;
					cblas_beta = bli_obj_buffer( *beta );
					cblas_zscal(n, cblas_beta, cblas_y, incy);
				}
				else if(bli_obj_is_double(*beta))
				{
					double *cblas_beta;
					cblas_beta = (double *) bli_obj_buffer( *beta );
					cblas_zdscal(n, *cblas_beta, cblas_y, incy);

				}
			}

#else
		bli_scalv( beta, y );
#endif
		break;

		default:
		libblis_test_printf_error( "Invalid interface type.\n" );
	}
}



void libblis_test_scalv_check( obj_t*  beta,
                               obj_t*  y,
                               obj_t*  y_orig,
                               double* resid )
{
	num_t  dt      = bli_obj_datatype( *y );
	num_t  dt_real = bli_obj_datatype_proj_to_real( *y );

	dim_t  m       = bli_obj_vector_dim( *y );

	obj_t  norm_y_r;
	obj_t  nbeta;

	obj_t  y2;

	double junk;

	//
	// Pre-conditions:
	// - y_orig is randomized.
	// Note:
	// - beta should have a non-zero imaginary component in the complex
	//   cases in order to more fully exercise the implementation.
	//
	// Under these conditions, we assume that the implementation for
	//
	//   y := conjbeta(beta) * y_orig
	//
	// is functioning correctly if
	//
	//   normf( y + -conjbeta(beta) * y_orig )
	//
	// is negligible.
	//

	bli_obj_create( dt, m, 1, 0, 0, &y2 );
    bli_copyv( y_orig, &y2 );

	bli_obj_scalar_init_detached( dt,      &nbeta );
	bli_obj_scalar_init_detached( dt_real, &norm_y_r );

	bli_copysc( beta, &nbeta );
	bli_mulsc( &BLIS_MINUS_ONE, &nbeta );

	bli_scalv( &nbeta, &y2 );
    bli_addv( &y2, y );

    bli_normfv( y, &norm_y_r );

    bli_getsc( &norm_y_r, resid, &junk );

    bli_obj_free( &y2 );
}

