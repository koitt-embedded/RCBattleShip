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

void bli_trsm_blk_var1b( obj_t*  a,
                         obj_t*  b,
                         obj_t*  c,
                         trsm_t* cntl,
                         trsm_thrinfo_t* thread )
{
    obj_t b_pack_s;
    obj_t a1_pack_s;

	obj_t a1, c1;
	obj_t* b_pack = NULL;
	obj_t* a1_pack = NULL;

#ifdef BLIS_ENABLE_C66X_EDMA
    obj_t c2;
	obj_t a1_dma_s;
	obj_t *a1_dma = NULL;
#endif

	dim_t i;
	dim_t b_alg;

#ifdef BLIS_ENABLE_C66X_EDMA
	dim_t b_alg_next;
#endif
#ifdef BLIS_ENABLE_CYCLE_COUNT
    uint64_t counter_start;
    uint64_t counter_end;
#endif
//	printf("blk_var1b\n");

    // Initialize object for packing B.
    if( thread_am_ochief( thread ) ) {
	    bli_obj_init_pack( &b_pack_s );
        bli_packm_init( b, &b_pack_s,
                        cntl_sub_packm_b( cntl ) );
    }
    b_pack = thread_obroadcast( thread, &b_pack_s );

    // Initialize object for packing B.
    if( thread_am_ichief( thread ) ) {
#ifdef BLIS_ENABLE_C66X_EDMA
    	bli_obj_init_dma( &a1_dma_s );
#endif
        bli_obj_init_pack( &a1_pack_s );
    }
#ifdef BLIS_ENABLE_C66X_EDMA
    a1_dma = thread_ibroadcast(thread, &a1_dma_s);
#endif
    a1_pack = thread_ibroadcast( thread, &a1_pack_s );

	// Pack B1 (if instructed).
	bli_packm_int( b, b_pack,
	               cntl_sub_packm_b( cntl ),
                   trsm_thread_sub_opackm( thread ) );

    dim_t start, end;
    num_t dt = bli_obj_execution_datatype( *a );
	dim_t bf = ( bli_obj_root_is_triangular( *a ) ?
	             bli_info_get_default_mr( dt ) :
	             bli_info_get_default_nr( dt ) );

    bli_get_range_b2t( thread, a, bf,
                       &start, &end );

	// Partition along the remaining portion of the m dimension.
	for ( i = start; i < end; i += b_alg )
	{
#ifdef BLIS_ENABLE_C66X_EDMA
		//printf("i = %d\n ", i);
		if(i == start)
		{
			// Determine the current algorithmic blocksize.
			b_alg = bli_determine_blocksize_b( i, end, a,
			                                   cntl_blocksize( cntl ) );

			// Acquire partitions for A1 and C1.
			bli_acquire_mpart_b2t( BLIS_SUBPART1,
			                       i, b_alg, a, &a1 );
			bli_acquire_mpart_b2t( BLIS_SUBPART1,
			                       i, b_alg, c, &c1 );

			if( thread_am_ichief( thread ) )
			{
				// DMA control leaf unrolling for A
				bli_dmam_init( &a1, a1_dma, cntl_sub_dmam_a( cntl ) );
			}
			bli_dmam_int( &a1, a1_dma, cntl_sub_dmam_a( cntl ), (dmam_thrinfo_t *) trsm_thread_sub_ipackm( thread ) );
		}
		else
		{
			b_alg = b_alg_next;
		}
		//printf("blk_var1 b_alg %d\n", b_alg);

		bli_dmam_wait(a1_dma, cntl_sub_dmam_a( cntl ), (dmam_thrinfo_t *) trsm_thread_sub_ipackm( thread ));
		thread_ibarrier( thread );

		// Initialize object for packing A1.
		if( thread_am_ichief( thread ) ) {
			bli_packm_init( a1_dma, a1_pack,
							cntl_sub_packm_a( cntl ) );
			//printf("after Pack init %x %x %x\n", bli_mem_buffer(&(a1_pack->dma_mem)), bli_mem_buffer(&(a1_pack->pack_mem)), a1_pack->emt_handle);

		}
		thread_ibarrier( thread );

		// Pack A1 (if instructed).
		bli_packm_int( a1_dma, a1_pack,
				cntl_sub_packm_a( cntl ),
				trsm_thread_sub_ipackm( thread ) );

		//printf("blk_var1: a: m %d n %d\n", bli_obj_length( a1 ), bli_obj_width( a1));
		//printf("blk_var1: a: m_panel %d n_panel %d\n", bli_obj_panel_length( *a1_pack ), bli_obj_panel_width( *a1_pack ));

		//Get the next partition and start DMA
		if( (i+b_alg) < end ) //Making sure we aren't at the end of the matrix
		{
			// Determine the current algorithmic blocksize.
			b_alg_next = bli_determine_blocksize_b( i+b_alg, end, a,
						                            cntl_blocksize( cntl ) );
			// Acquire partitions for A1 and C1.
			bli_acquire_mpart_b2t( BLIS_SUBPART1,
								   i+b_alg, b_alg_next, a, &a1 );
			bli_acquire_mpart_b2t( BLIS_SUBPART1,
								   i+b_alg, b_alg_next, c, &c2 );

			if( thread_am_ichief( thread ) )
			{
				// DMA control leaf unrolling for A
				//printf("Init DMA A2 %x ", bli_mem_buffer(&(a1_dma->dma_mem)));
				bli_dmam_init( &a1, a1_dma, cntl_sub_dmam_a( cntl ) );
				//printf("after DMA init %x %x %x\n", bli_mem_buffer(&(a1_dma->dma_mem)), bli_mem_buffer(&(a1_dma->pack_mem)), a1_dma->emt_handle);

			}
			bli_dmam_int( &a1, a1_dma, cntl_sub_dmam_a( cntl ), (dmam_thrinfo_t *) trsm_thread_sub_ipackm( thread ) );

		}

#else
		// Determine the current algorithmic blocksize.
		b_alg = bli_determine_blocksize_b( i, end, a,
		                                   cntl_blocksize( cntl ) );

		// Acquire partitions for A1 and C1.
		bli_acquire_mpart_b2t( BLIS_SUBPART1,
		                       i, b_alg, a, &a1 );
		bli_acquire_mpart_b2t( BLIS_SUBPART1,
		                       i, b_alg, c, &c1 );

		// Initialize object for packing A1.
        if( thread_am_ichief( thread ) ) {
            bli_packm_init( &a1, a1_pack,
                            cntl_sub_packm_a( cntl ) );
        }
        thread_ibarrier( thread );

		// Pack A1 (if instructed).
		bli_packm_int( &a1, a1_pack,
		               cntl_sub_packm_a( cntl ),
                       trsm_thread_sub_ipackm( thread ) );
#endif

		// Perform trsm subproblem.
#ifdef BLIS_ENABLE_CYCLE_COUNT
		lib_clock_enable();
		counter_start = lib_clock_read();
#endif
		bli_trsm_int( &BLIS_ONE,
		              a1_pack,
		              b_pack,
		              &BLIS_ONE,
		              &c1,
		              cntl_sub_trsm( cntl ),
                      trsm_thread_sub_trsm( thread ) );

#ifdef BLIS_ENABLE_CYCLE_COUNT
		counter_end = lib_clock_read();
		if(lib_get_coreID()==0)
		{
			printf("%d\n", (counter_end-counter_start));
		}
#endif
#ifdef BLIS_ENABLE_C66X_EDMA
		if( (i+b_alg) < end ) //Making sure we aren't at the end of the matrix
		{
			bli_obj_alias_to(c2, c1);
		}
#endif
	}

	// If any packing buffers were acquired within packm, release them back
	// to the memory manager.
    thread_obarrier( thread );
    if( thread_am_ochief( thread ) )
    	bli_obj_release_pack( b_pack , cntl_sub_packm_b(cntl));
    if( thread_am_ichief( thread ) )
    {
    	//printf("before Pack release %x %x %x\n", bli_mem_buffer(&(a1_pack->dma_mem)), bli_mem_buffer(&(a1_pack->pack_mem)), a1_pack->emt_handle);
    	bli_obj_release_pack( a1_pack, cntl_sub_packm_a(cntl) );
    	//printf("after Pack release %x %x %x\n", bli_mem_buffer(&(a1_pack->dma_mem)), bli_mem_buffer(&(a1_pack->pack_mem)), a1_pack->emt_handle);
#ifdef BLIS_ENABLE_C66X_EDMA
//    	printf("before DMA release %x %x %x\n", bli_mem_buffer(&(a1_dma->dma_mem)), bli_mem_buffer(&(a1_dma->pack_mem)), a1_dma->emt_handle);
    	bli_obj_release_dma( a1_dma, cntl_sub_dmam_a(cntl) );
		bli_obj_release_emt_handle( a1_dma );
//		printf("after DMA release %x %x %x\n", bli_mem_buffer(&(a1_dma->dma_mem)), bli_mem_buffer(&(a1_dma->pack_mem)), a1_dma->emt_handle);
#endif

    }
//    printf("blk_var1b end\n");
}

