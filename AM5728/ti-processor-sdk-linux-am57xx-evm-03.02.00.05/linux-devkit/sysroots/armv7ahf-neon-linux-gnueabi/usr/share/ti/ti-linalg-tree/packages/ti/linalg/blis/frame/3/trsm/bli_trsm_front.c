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



#ifdef BLIS_ENABLE_PROFILE
    profile_data_t *bli_trsm_profile_data;
    profile_data_t *bli_trsm_kervar2_profile_data;
#endif

void bli_trsm_front( side_t  side,
                     obj_t*  alpha,
                     obj_t*  a,
                     obj_t*  b,
                     trsm_t* l_cntl,
                     trsm_t* r_cntl )
{
	trsm_t* cntl;
	obj_t   a_local;
	obj_t   b_local;
	obj_t   c_local;

#ifdef BLIS_ENABLE_PROFILE
    dim_t mn_side, m_profile, n_profile;
#endif

#ifdef BLIS_ENABLE_PROFILE
    m_profile =  bli_obj_length( *b );
    n_profile =  bli_obj_width( *b );
    bli_set_dim_with_side( side, m_profile, n_profile, mn_side );

#endif

	// Check parameters.
	if ( bli_error_checking_is_enabled() )
		bli_trsm_check( side, alpha, a, b );

	// If alpha is zero, scale by beta and return.
	if ( bli_obj_equals( alpha, &BLIS_ZERO ) )
	{
		bli_scalm( alpha, b );
		return;
	}

	// Alias A and B so we can tweak the objects if necessary.
	bli_obj_alias_to( *a, a_local );
	bli_obj_alias_to( *b, b_local );
	bli_obj_alias_to( *b, c_local );

#ifdef BLIS_ENABLE_C66X_BUILD
	/* Left sided trsm is that the loops over the M dimension (the ones indexed by ic and ir),
	 *  the iterations are dependent so you can’t parallelize them, instead the JC loop is parallized.
	 *  In this case, since each core has it's own L2 memory, only core 0 has the packed panel of A
	 *  (the packing of A occurs in the IC loop), the other cores do not have access to this panel
	 *  So we transpose the operation so that instead of (for instance) having a left-lower TRSM we have a
	 *  right-upper TRSM. In this case we can parallelize over IC.*/
	if ( bli_is_left( side ) )
	{
		bli_toggle_side( side );
		bli_obj_induce_trans( a_local );
		bli_obj_induce_trans( b_local );
		bli_obj_induce_trans( c_local );
	}
#endif

	// We do not explicitly implement the cases where A is transposed.
	// However, we can still handle them. Specifically, if A is marked as
	// needing a transposition, we simply induce a transposition. This
	// allows us to only explicitly implement the no-transpose cases. Once
	// the transposition is induced, the correct algorithm will be called,
	// since, for example, an algorithm over a transposed lower triangular
	// matrix A moves in the same direction (forwards) as a non-transposed
	// upper triangular matrix. And with the transposition induced, the
	// matrix now appears to be upper triangular, so the upper triangular
	// algorithm will grab the correct partitions, as if it were upper
	// triangular (with no transpose) all along.
	if ( bli_obj_has_trans( a_local ) )
	{
		bli_obj_induce_trans( a_local );
		bli_obj_set_onlytrans( BLIS_NO_TRANSPOSE, a_local );
	}

#if 0

	// If A is being solved against from the right, transpose all operands
	// so that we can perform the computation as if A were being solved
	// from the left.
	if ( bli_is_right( side ) )
	{
		bli_toggle_side( side );
		bli_obj_induce_trans( a_local );
		bli_obj_induce_trans( b_local );
		bli_obj_induce_trans( c_local );
	}

#else

	// If A is being solved against from the right, swap A and B so that
	// the triangular matrix will actually be on the right.
	if ( bli_is_right( side ) )
	{
		bli_obj_swap( a_local, b_local );
	}

#endif

	// Set each alias as the root object.
	// NOTE: We MUST wait until we are done potentially swapping the objects
	// before setting the root fields!
	bli_obj_set_as_root( a_local );
	bli_obj_set_as_root( b_local );
	bli_obj_set_as_root( c_local );

	// Choose the control tree.
	if ( bli_is_left( side ) ) cntl = l_cntl;
	else                       cntl = r_cntl;

    trsm_thrinfo_t** infos = bli_create_trsm_thrinfo_paths( bli_is_right( side ) );
    dim_t n_threads = thread_num_threads( infos[0] );
    
#ifdef BLIS_ENABLE_PROFILE
    bli_trsm_profile_data = bli_profile_data_init(BLIS_MAX_NUM_THREADS*BLIS_PROFILE_NUM_REPORTS);
#endif

    // Invoke the internal back-end.
    bli_level3_thread_decorator( n_threads,   
                                 (level3_int_t) bli_trsm_int, 
                                 alpha, 
                                 &a_local,  
                                 &b_local,  
                                 alpha, 
                                 &c_local,  
                                 (void*) cntl, 
                                 (void**) infos );

    bli_trsm_thrinfo_free_paths( infos, n_threads );

#ifdef BLIS_ENABLE_PROFILE
    {

    	bli_profile_data_print (bli_trsm_profile_data,
    	    					m_profile, n_profile, mn_side,
    	    					bli_obj_execution_datatype( *b ), 1, n_threads);


    	bli_profile_data_free(bli_trsm_profile_data);
    }

#endif
}

