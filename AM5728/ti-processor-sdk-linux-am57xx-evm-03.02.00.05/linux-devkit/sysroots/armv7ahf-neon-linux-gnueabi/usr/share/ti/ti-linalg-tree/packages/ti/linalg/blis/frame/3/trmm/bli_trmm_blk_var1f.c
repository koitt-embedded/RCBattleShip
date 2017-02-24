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

void bli_trmm_blk_var1f( obj_t*  a,
                         obj_t*  b,
                         obj_t*  c,
                         gemm_t* cntl,
                         trmm_thrinfo_t* thread )
{
    obj_t b_pack_s;
    obj_t a1_pack_s, c1_pack_s;

    obj_t a1, c1; 
    obj_t* a1_pack  = NULL;
    obj_t* b_pack   = NULL;
    obj_t* c1_pack  = NULL;

	dim_t i;
	dim_t b_alg;

#ifdef BLIS_ENABLE_C66X_EDMA
	obj_t c2;
	obj_t b_dma_s;
	obj_t *b_dma;
	obj_t a1_dma_s;
	obj_t *a1_dma;
	obj_t c1_dma_s;
	obj_t *c1_dma;
#endif

#ifdef BLIS_ENABLE_C66X_EDMA
	if( thread_am_ochief( thread ) )
		{
			//printf("Inside if \n");
			bli_obj_init_dma( &b_dma_s );
			bli_obj_init_pack( &b_dma_s ); //Even though we aren't packing this buffer, initializing the pack buf to NULL
			bli_dmam_init( b, &b_dma_s, cntl_sub_dmam_b( cntl ));
		}
		b_dma = thread_obroadcast( thread, &b_dma_s );
		bli_dmam_int( b, b_dma, cntl_sub_dmam_b( cntl ), (dmam_thrinfo_t*) trmm_thread_sub_opackm( thread ) );
		//Waiting for B to finish transfer
		bli_dmam_wait(b_dma, cntl_sub_dmam_b( cntl ), (dmam_thrinfo_t *) trmm_thread_sub_opackm( thread ));
		// Other cores need to wait while one core waits for DMA to complete
		thread_obarrier( thread );


		if( thread_am_ochief( thread ) )
		{
			//printf("Pack B init ocomm_id %d \n", thread->ocomm_id);
			// Initialize object for packing B.
			bli_obj_init_pack( &b_pack_s );
			bli_obj_init_dma( &b_pack_s );
			bli_packm_init( b_dma, &b_pack_s,
					        cntl_sub_packm_b( cntl ) );

			// Scale C by beta (if instructed).
			// Since scalm doesn't support multithreading yet, must be done by chief thread (ew)
			bli_scalm_int( &BLIS_ONE,
					       c,
					       cntl_sub_scalm( cntl ) );
		}
		b_pack = thread_obroadcast( thread, &b_pack_s );

#else
    if( thread_am_ochief( thread ) ) { 
        // Initialize object for packing B.
        bli_obj_init_pack( &b_pack_s );
        bli_packm_init( b, &b_pack_s,
                        cntl_sub_packm_b( cntl ) );

        // Scale C by beta (if instructed).
        // Since scalm doesn't support multithreading yet, must be done by chief thread (ew)
        bli_scalm_int( &BLIS_ONE,
                       c,  
                       cntl_sub_scalm( cntl ) );
    }   
    b_pack = thread_obroadcast( thread, &b_pack_s );
#endif

	// Initialize all pack objects that are passed into packm_init().
    if( thread_am_ichief( thread ) )
    {
#ifdef BLIS_ENABLE_C66X_EDMA
		bli_obj_init_dma( &a1_dma_s );
		bli_obj_init_pack( &a1_dma_s ); //Even though we aren't packing this buffer, initializing the pack buf to NULL

		bli_obj_init_dma( &c1_dma_s );
		bli_obj_init_pack( &c1_dma_s ); //Even though we aren't packing this buffer, initializing the pack buf to NULL
#endif
        bli_obj_init_pack( &a1_pack_s );
        bli_obj_init_pack( &c1_pack_s );

#ifdef BLIS_ENABLE_C66X_EDMA
		bli_obj_init_dma( &a1_pack_s );
		bli_obj_init_dma( &c1_pack_s );
#endif
    }
    a1_pack = thread_ibroadcast( thread, &a1_pack_s );
    c1_pack = thread_ibroadcast( thread, &c1_pack_s );
#ifdef BLIS_ENABLE_C66X_EDMA
    a1_dma = thread_ibroadcast( thread, &a1_dma_s );
    c1_dma = thread_ibroadcast( thread, &c1_dma_s );
#endif

	// Pack B (if instructed).

#ifdef BLIS_ENABLE_C66X_EDMA
	bli_packm_int( b_dma, b_pack,
	               cntl_sub_packm_b( cntl ),
                   trmm_thread_sub_opackm( thread ) );
#else
	bli_packm_int( b, b_pack,
	               cntl_sub_packm_b( cntl ),
                   trmm_thread_sub_opackm( thread ) );
#endif

    dim_t start, end;
    siz_t area;

    area = bli_get_range_weighted_t2b( thread, a,
    							bli_determine_reg_blocksize( a, cntl_blocksize( cntl ) ),
                                &start, &end );

#ifdef BLIS_ENABLE_C66X_EDMA
    if(start<end)
    {
    	// Determine the current algorithmic blocksize.
    	b_alg = bli_determine_blocksize_f( start, end, a,
    			cntl_blocksize( cntl ) );

    	// Acquire partitions for A1 and C1.
    	bli_acquire_mpart_t2b( BLIS_SUBPART1,
    			start, b_alg, a, &a1 );
    	bli_acquire_mpart_t2b( BLIS_SUBPART1,
    			start, b_alg, c, &c1 );

    	if( thread_am_ichief( thread ) )
    	{
    		bli_dmam_init( &a1, a1_dma, cntl_sub_dmam_a( cntl ) );
    		bli_dmam_init( &c1, c1_dma, cntl_sub_dmam_c( cntl ) );
    	}

    	bli_dmam_int( &a1, a1_dma, cntl_sub_dmam_a( cntl ), (dmam_thrinfo_t *) trmm_thread_sub_ipackm( thread ) );
    	bli_dmam_int( &c1, c1_dma, cntl_sub_dmam_c( cntl ), (dmam_thrinfo_t *) trmm_thread_sub_ipackm( thread ) );
    }
    else
    {
    	b_alg = 0;
    }

    if (start < end)
    {
    	for ( i = start+b_alg; i <= end; i += b_alg )
    	{
    		// Wait for DMA to complete. Start packing the panel that has just completed.
    		bli_dmam_wait(a1_dma, cntl_sub_dmam_a( cntl ), (dmam_thrinfo_t *) trmm_thread_sub_ipackm( thread ));
    		bli_dmam_wait(c1_dma, cntl_sub_dmam_c( cntl ), (dmam_thrinfo_t *) trmm_thread_sub_ipackm( thread ));
    		thread_ibarrier( thread );

    		// Initialize objects for packing A1 and C1.
    		if( thread_am_ichief( thread ) )
    		{
    			bli_packm_init( a1_dma, a1_pack,
    					cntl_sub_packm_a( cntl ) );
    			bli_packm_init( c1_dma, c1_pack,
    					cntl_sub_packm_c( cntl ) );
    		}

    		bli_packm_int( a1_dma, a1_pack,
    				cntl_sub_packm_a( cntl ),
    				trmm_thread_sub_ipackm( thread ) );
    		bli_packm_int( c1_dma, c1_pack,
    				cntl_sub_packm_c( cntl ),
    				trmm_thread_sub_ipackm( thread ) );

    		if(i < end) // Only if i < end do we want to DMA the next block
    		{
    			b_alg = bli_determine_blocksize_f( i, end, a,
    					cntl_blocksize( cntl ) );

    			// Acquire partitions for A1 and C1.
    			bli_acquire_mpart_t2b( BLIS_SUBPART1,
    					i, b_alg, a, &a1 );
    			bli_acquire_mpart_t2b( BLIS_SUBPART1,
    					i, b_alg, c, &c2 ); // Since after the sub_gemm is called, the output is then unpacked back into C. //
    			//We need to make sure it is unpacked into the previous panel and not the current one that is being moved by the DMA

    			if( thread_am_ichief( thread ) )
    			{
    				// DMA control leaf unrolling for A
    				//printf("Init DMA A2\n");
    				bli_dmam_init( &a1, a1_dma, cntl_sub_dmam_a( cntl ) );
    				bli_dmam_init( &c2, c1_dma, cntl_sub_dmam_c( cntl ) );
    			}
    			//thread_ibarrier( thread );
    			bli_dmam_int( &a1, a1_dma, cntl_sub_dmam_a( cntl ), (dmam_thrinfo_t *) trmm_thread_sub_ipackm( thread ) );
    			bli_dmam_int( &c2, c1_dma, cntl_sub_dmam_c( cntl ), (dmam_thrinfo_t *) trmm_thread_sub_ipackm( thread ) );
    		}

    		// Perform trmm subproblem.
    		bli_trmm_int( &BLIS_ONE,
    				a1_pack,
    				b_pack,
    				&BLIS_ONE,
    				c1_pack,
    				cntl_sub_gemm( cntl ),
    				trmm_thread_sub_trmm( thread ) );

    		// Unpack C1 (if C1 was packed).
    		bli_unpackm_int( c1_pack, &c1,
    				cntl_sub_unpackm_c( cntl ),
    				trmm_thread_sub_ipackm( thread ) );

    		if(i < end) // Only if i < end do we want to DMA the next block
    		{
				bli_obj_alias_to(c2, c1);
			}
    	}
    }

#else
	// Partition along the m dimension.
	for ( i = start; i < end; i += b_alg )
	{
		// Determine the current algorithmic blocksize.
		b_alg = bli_determine_blocksize_f( i, end, a,
		                                   cntl_blocksize( cntl ) );

		// Acquire partitions for A1 and C1.
		bli_acquire_mpart_t2b( BLIS_SUBPART1,
		                       i, b_alg, a, &a1 );
		bli_acquire_mpart_t2b( BLIS_SUBPART1,
		                       i, b_alg, c, &c1 );

		// Initialize objects for packing A1 and C1.
        if( thread_am_ichief( thread ) ) {
            bli_packm_init( &a1, a1_pack,
                            cntl_sub_packm_a( cntl ) );
            bli_packm_init( &c1, c1_pack,
                            cntl_sub_packm_c( cntl ) );
        }
        thread_ibarrier( thread );

		// Pack A1 (if instructed).
		bli_packm_int( &a1, a1_pack,
		               cntl_sub_packm_a( cntl ),
                       trmm_thread_sub_ipackm( thread ) );

		// Pack C1 (if instructed).
		bli_packm_int( &c1, c1_pack,
		               cntl_sub_packm_c( cntl ),
                       trmm_thread_sub_ipackm( thread ) );
        
		// Perform trmm subproblem.
		bli_trmm_int( &BLIS_ONE,
		              a1_pack,
		              b_pack,
		              &BLIS_ONE,
		              c1_pack,
		              cntl_sub_gemm( cntl ),
                      trmm_thread_sub_trmm( thread ) );

		// Unpack C1 (if C1 was packed).
        bli_unpackm_int( c1_pack, &c1,
                         cntl_sub_unpackm_c( cntl ),
                         trmm_thread_sub_ipackm( thread ) );
	}
#endif

	// If any packing buffers were acquired within packm, release them back
	// to the memory manager.
    thread_obarrier( thread );
    if( thread_am_ochief( thread ) )
    {
        bli_obj_release_pack( b_pack, cntl_sub_packm_b( cntl ));
#ifdef BLIS_ENABLE_C66X_EDMA
		bli_obj_release_dma( b_dma, cntl_sub_dmam_b( cntl ) );
		bli_obj_release_emt_handle( b_dma );
#endif
    }
    if( thread_am_ichief( thread ) )
    {
        bli_obj_release_pack( a1_pack , cntl_sub_packm_a( cntl ));
        bli_obj_release_pack( c1_pack , cntl_sub_packm_c( cntl ) );
#ifdef BLIS_ENABLE_C66X_EDMA
        bli_obj_release_dma( a1_dma, cntl_sub_dmam_a( cntl ) );
        bli_obj_release_dma( c1_dma, cntl_sub_dmam_c( cntl ) );
		bli_obj_release_emt_handle( a1_dma );
		bli_obj_release_emt_handle( c1_dma );
#endif
    }
}

