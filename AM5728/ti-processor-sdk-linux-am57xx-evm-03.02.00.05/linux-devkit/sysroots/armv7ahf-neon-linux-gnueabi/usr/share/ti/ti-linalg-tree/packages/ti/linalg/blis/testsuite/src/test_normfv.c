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
static char*     op_str                    = "normfv";
static char*     o_types                   = "v";  // x
static char*     p_types                   = "";   // (no parameters)
static thresh_t  thresh[BLIS_NUM_FP_TYPES] = { { 1e-04, 1e-05 },   // warn, pass for s
                                               { 1e-04, 1e-05 },   // warn, pass for c
                                               { 1e-13, 1e-14 },   // warn, pass for d
                                               { 1e-13, 1e-14 } }; // warn, pass for z

// Local prototypes.
void libblis_test_normfv_deps( test_params_t* params,
                               test_op_t*     op );

void libblis_test_normfv_experiment( test_params_t* params,
                                     test_op_t*     op,
                                     iface_t        iface,
                                     num_t          datatype,
                                     char*          pc_str,
                                     char*          sc_str,
                                     unsigned int   p_cur,
                                     perf_t*        perf,
                                     double*        resid );

void libblis_test_normfv_impl( iface_t   iface,
                               obj_t*    x,
                               obj_t*    norm );

void libblis_test_normfv_check( obj_t*  beta,
                                obj_t*  x,
                                obj_t*  norm,
                                double* resid );



void libblis_test_normfv_deps( test_params_t* params, test_op_t* op )
{
	libblis_test_setv( params, &(op->ops->setv) );
}



void libblis_test_normfv( test_params_t* params, test_op_t* op )
{

	// Return early if this test has already been done.
	if ( op->test_done == TRUE ) return;

	// Return early if operation is disabled.
	if ( op->op_switch == DISABLE_ALL ||
	     op->ops->l1v_over == DISABLE_ALL ) return;

	// Call dependencies first.
	if ( TRUE ) libblis_test_normfv_deps( params, op );

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
		                        libblis_test_normfv_experiment );
	}
}



void libblis_test_normfv_experiment( test_params_t* params,
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

	num_t        dt_real   = bli_datatype_proj_to_real( datatype );

	double       time_min  = 1e9;
	double       time;

	dim_t        m;

	obj_t        beta;
	obj_t        x;

#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	dim_t 		 test_way = bli_read_nway_from_env( "BLIS_LB_NT" );
	obj_t	     norm[test_way];
	double       resid_local[test_way];
	unsigned int j;
#else
	obj_t        norm;
#endif

	// Map the dimension specifier to an actual dimension.
	m = libblis_test_get_dim_from_prob_size( op->dim_spec[0], p_cur );

	// Map parameter characters to BLIS constants.


	// Create test scalars.
	bli_obj_scalar_init_detached( datatype, &beta );
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	for(i = 0; i < test_way; i++)
	{
		bli_obj_scalar_init_detached( dt_real,  &norm[i] );
	}
#else
	bli_obj_scalar_init_detached( dt_real,  &norm );
#endif

	// Create test operands (vectors and/or matrices).
	libblis_test_vobj_create( params, datatype, sc_str[0], m, &x );

	// Initialize beta to 2 - 2i.
	bli_setsc( 2.0, -2.0, &beta );

	// Set all elements of x to beta.
	bli_setv( &beta, &x );

	// Repeat the experiment n_repeats times and record results. 
	for ( i = 0; i < n_repeats; ++i )
	{
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
		libblis_test_normfv_impl( iface, &x, &norm[0] );
#else
		libblis_test_normfv_impl( iface, &x, &norm );
#endif
		time = bli_clock();

#ifdef BLIS_ENABLE_MULTITHREAD_TEST
#pragma omp parallel num_threads(test_way)
		{
			#pragma omp for
			for(j = 0; j < test_way; j++)
			{
				libblis_test_normfv_impl( iface, &x, &norm[j] );
			}
		}
#else
		libblis_test_normfv_impl( iface, &x, &norm );
#endif

		time_min = bli_clock_min_diff( time_min, time );
	}
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	// Estimate the performance of the best experiment repeat.
	perf->gflops = ( 2.0 * m ) * test_way / time_min / FLOPS_PER_UNIT_PERF;
	if ( bli_obj_is_complex( x ) ) perf->gflops *= 2.0;
#else
	// Estimate the performance of the best experiment repeat.
	perf->gflops = ( 2.0 * m ) / time_min / FLOPS_PER_UNIT_PERF;
	if ( bli_obj_is_complex( x ) ) perf->gflops *= 2.0;
#endif
	perf->time = time_min;

#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	// Check output of each thread, and send max residue to main
	for(i = 0; i < test_way; i++)
	{
		// Perform checks.
		libblis_test_normfv_check( &beta, &x, &norm[i], &resid_local[i] );

		// Zero out performance and residual if input vector is empty.
		libblis_test_check_empty_problem( &x, perf, &resid_local[i] );

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
	libblis_test_normfv_check( &beta, &x, &norm, resid );

	// Zero out performance and residual if input vector is empty.
	libblis_test_check_empty_problem( &x, perf, resid );
#endif


	// Free the test objects.
	bli_obj_free( &x );
}



void libblis_test_normfv_impl( iface_t   iface,
                               obj_t*    x,
                               obj_t*    norm )
{
	switch ( iface )
	{
		case BLIS_TEST_SEQ_FRONT_END:
			;
#ifdef CBLAS
			int n;
			int incx;

			n     = bli_obj_vector_dim( *x );
			incx  = bli_obj_vector_inc( *x );

			if (bli_obj_is_float( *x ))
			{
				float *cblas_norm;
				float *cblas_x;

				cblas_norm  = (float *) bli_obj_buffer( *norm );
				cblas_x     = (float *) bli_obj_buffer( *x );

				*cblas_norm = cblas_snrm2(n, cblas_x, incx);

			}
			else if (bli_obj_is_double( *x ))
			{
				double *cblas_norm;
				double *cblas_x;

				cblas_norm  = (double *) bli_obj_buffer( *norm );
				cblas_x     = (double *) bli_obj_buffer( *x );

				*cblas_norm = cblas_dnrm2(n, cblas_x, incx);

			}
			else if (bli_obj_is_scomplex( *x ))
			{
				float *cblas_norm;
				void *cblas_x;

				cblas_norm  = (float *) bli_obj_buffer( *norm );
				cblas_x     = bli_obj_buffer( *x );

				*cblas_norm = cblas_scnrm2(n, cblas_x, incx);
			}
			else if (bli_obj_is_dcomplex( *x ))
			{
				double *cblas_norm;
				void *cblas_x;

				cblas_norm  = (double *) bli_obj_buffer( *norm );
				cblas_x     = bli_obj_buffer( *x );

				*cblas_norm = cblas_dznrm2(n, cblas_x, incx);
			}

#else
		bli_normfv( x, norm );
#endif
		break;

		default:
		libblis_test_printf_error( "Invalid interface type.\n" );
	}
}



void libblis_test_normfv_check( obj_t*  beta,
                                obj_t*  x,
                                obj_t*  norm,
                                double* resid )
{
	num_t  dt_real = bli_obj_datatype_proj_to_real( *x );
	dim_t  m       = bli_obj_vector_dim( *x );

	obj_t  m_r, temp_r;

	double junk;

	//
	// Pre-conditions:
	// - x is set to beta.
	// Note:
	// - beta should have a non-zero imaginary component in the complex
	//   cases in order to more fully exercise the implementation.
	//
	// Under these conditions, we assume that the implementation for
	//
	//   norm := normf( x )
	//
	// is functioning correctly if
	//
	//   norm = sqrt( absqsc( beta ) * m )
	//
	// where m is the length of x.
	//

	bli_obj_scalar_init_detached( dt_real, &temp_r );
	bli_obj_scalar_init_detached( dt_real, &m_r );

	bli_setsc( ( double )m, 0.0, &m_r );

	bli_absqsc( beta, &temp_r );
	bli_mulsc( &m_r, &temp_r );
	bli_sqrtsc( &temp_r, &temp_r );
	bli_subsc( &temp_r, norm );

	bli_getsc( norm, resid, &junk );
}

