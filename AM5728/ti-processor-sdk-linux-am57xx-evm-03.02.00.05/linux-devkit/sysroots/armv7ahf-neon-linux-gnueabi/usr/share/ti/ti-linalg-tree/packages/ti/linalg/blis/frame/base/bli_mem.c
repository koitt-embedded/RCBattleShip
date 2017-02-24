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
#ifdef BLIS_ENABLE_C66X_BUILD
//#define BLIS_ENABLE_C66X_MEM_DEBUG
#endif


// Declare one memory pool structure for each block size/shape we want to
// be able to allocate.

// Physically contiguous memory for each pool.
//
// Generally speaking, the pool sizes are computed in a sub-header of blis.h
// as follows:
//
//   BLIS_MK_POOL_SIZE = BLIS_MAXIMUM_MC_? * BLIS_MAXIMUM_KC_? * BLIS_SIZEOF_?
//
// where "?" is the datatype that results in the largest pool size. The
// constants BLIS_KN_POOL_SIZE and BLIS_MN_POOL_SIZE are computed in a
// similar manner. All constants are computed with appropriate "padding"
// to ensure enough space given the alignments required by bli_config.h.
//

// For C66x, the memory pools need to be explicitly placed in the different levels of
// the memory.
#ifdef BLIS_ENABLE_C66X_MEM_POOLS

static pool_t pools[12];

//Main Memory Pools
static void*  pool_mk_blk_ptrs[ BLIS_NUM_MC_X_KC_BLOCKS ];
static char   pool_mk_mem[ BLIS_MK_POOL_SIZE ];

static void*  pool_kn_blk_ptrs[ BLIS_NUM_KC_X_NC_BLOCKS ];
static char   pool_kn_mem[ BLIS_KN_POOL_SIZE ];

static void*  pool_mn_blk_ptrs[ BLIS_NUM_MC_X_NC_BLOCKS ];
static char   pool_mn_mem[ BLIS_MN_POOL_SIZE ];

//L1
static void*  pool_mk_blk_ptrs_L1[ BLIS_NUM_MR_X_KC_BLOCKS_L1 ];
char   *pool_mk_mem_L1;

static void*  pool_kn_blk_ptrs_L1[ BLIS_NUM_KC_X_NR_BLOCKS_L1 ];
char   *pool_kn_mem_L1;

static void*  pool_mn_blk_ptrs_L1[ BLIS_NUM_MR_X_NR_BLOCKS_L1 ];
char   *pool_mn_mem_L1;

//
//L2 Pools
//
static void*  pool_mk_blk_ptrs_L2[ BLIS_NUM_MC_X_KC_BLOCKS_L2 ];
char   *pool_mk_mem_L2;

static void*  pool_kn_blk_ptrs_L2[ BLIS_NUM_KC_X_NC_BLOCKS_L2 ];
char   *pool_kn_mem_L2;

static void*  pool_mn_blk_ptrs_L2[ BLIS_NUM_MC_X_NR_BLOCKS_L2 ];
char   *pool_mn_mem_L2;

//
//L3 Pools
//
static void*  pool_mk_blk_ptrs_L3[ BLIS_NUM_MC_X_KC_BLOCKS_L3 ];
char   *pool_mk_mem_L3;

static void*  pool_kn_blk_ptrs_L3[ BLIS_NUM_KC_X_NC_BLOCKS_L3 ];
char   *pool_kn_mem_L3;

static void*  pool_mn_blk_ptrs_L3[ BLIS_NUM_MC_X_NC_BLOCKS_L3 ];
char   *pool_mn_mem_L3;

#else
static pool_t pools[3];

static void*  pool_mk_blk_ptrs[ BLIS_NUM_MC_X_KC_BLOCKS ];
static char   pool_mk_mem[ BLIS_MK_POOL_SIZE ];

static void*  pool_kn_blk_ptrs[ BLIS_NUM_KC_X_NC_BLOCKS ];
static char   pool_kn_mem[ BLIS_KN_POOL_SIZE ];

static void*  pool_mn_blk_ptrs[ BLIS_NUM_MC_X_NC_BLOCKS ];
static char   pool_mn_mem[ BLIS_MN_POOL_SIZE ];
#endif



void bli_mem_acquire_m( siz_t     req_size,
                        packbuf_t buf_type,
                        mem_t*    mem )
{
	siz_t   block_size;
	dim_t   pool_index;
	pool_t* pool;
	void**  block_ptrs;
	void*   block;
	gint_t  i;

#ifdef BLIS_ENABLE_C66X_MEM_POOLS
	dim_t core_id;
	if (bli_buf_type_is_shared(buf_type))
		core_id = 0;
	else
		core_id = omp_get_thread_num ();
#endif


	if ( buf_type == BLIS_BUFFER_FOR_GEN_USE )
	{
		// For general-use buffer requests, such as those used by level-2
		// operations, using bli_malloc() is sufficient, since using
		// physically contiguous memory is not as important there.
		block = bli_malloc( req_size );

		// Initialize the mem_t object with:
		// - the address of the memory block,
		// - the buffer type (a packbuf_t value), and
		// - the size of the requested region.
		// NOTE: We do not initialize the pool field since this block did not
		// come from a contiguous memory pool.
		bli_mem_set_buffer( block, mem );
		bli_mem_set_buf_type( buf_type, mem );
		bli_mem_set_size( req_size, mem );

		//printf("Acquire: block %x \n", block);
	}
	else
	{
		// This branch handles cases where the memory block needs to come
		// from one of the contiguous memory pools.

		// Map the requested packed buffer type to a zero-based index, which
		// we then use to select the corresponding memory pool.
		pool_index = bli_packbuf_index( buf_type );
		pool       = &pools[ pool_index ];

#ifdef BLIS_ENABLE_C66X_MEM_DEBUG
		printf("Acquire: core_id %d buf_type %x block size size %d req size %d ", core_id, buf_type, bli_pool_block_size( pool ), req_size);
#endif

		// Unconditionally perform error checking on the memory pool.
		{
			err_t e_val;

			// Make sure that the requested matrix size fits inside of a block
			// of the corresponding pool.
			e_val = bli_check_requested_block_size_for_pool( req_size, pool );
			bli_check_error_code( e_val );

			// Make sure that the pool contains at least one block to check out
			// to the thread.
#ifdef BLIS_ENABLE_C66X_MEM_POOLS
			e_val = bli_check_if_exhausted_pool( pool, core_id );
#else
			e_val = bli_check_if_exhausted_pool( pool );
#endif
			bli_check_error_code( e_val );
		}

		// Access the block pointer array from the memory pool data structure.
		block_ptrs = bli_pool_block_ptrs( pool );


		// BEGIN CRITICAL SECTION
#ifdef BLIS_ENABLE_OPENMP        
        _Pragma( "omp critical (mem)" )
#endif
        {

		// Query the index of the contiguous memory block that resides at the
        // "top" of the pool.
#ifdef BLIS_ENABLE_C66X_MEM_POOLS
        i = bli_pool_top_index( pool, core_id );
#else
        i = bli_pool_top_index( pool );
#endif

		// Extract the address of the top block from the block pointer array.
		block = block_ptrs[i];

#ifdef BLIS_ENABLE_C66X_MEM_DEBUG
		printf("block %x \n", block);
#endif

		// Clear the entry from the block pointer array. (This is actually not
		// necessary.)
		//block_ptrs[i] = NULL; 

		// Decrement the top of the memory pool.
#ifdef BLIS_ENABLE_C66X_MEM_POOLS
		bli_pool_dec_top_index( pool, core_id );
#else
		bli_pool_dec_top_index( pool );
#endif


		// END CRITICAL SECTION
        }

		// Query the size of the blocks in the pool so we can store it in the
		// mem_t object.
		block_size = bli_pool_block_size( pool );

		// Initialize the mem_t object with:
		// - the address of the memory block,
		// - the buffer type (a packbuf_t value),
		// - the address of the memory pool to which it belongs, and
		// - the size of the contiguous memory block (NOT the size of the
		//   requested region).
		bli_mem_set_buffer( block, mem );
		bli_mem_set_buf_type( buf_type, mem );
		bli_mem_set_pool( pool, mem );
		bli_mem_set_size( block_size, mem );
	}
}


void bli_mem_release( mem_t* mem )
{
	packbuf_t buf_type;
	pool_t*   pool;
	void**    block_ptrs;
	void*     block;
	gint_t    i;

#ifdef BLIS_ENABLE_C66X_MEM_POOLS
	dim_t core_id;
#endif

	// Extract the address of the memory block we are trying to
	// release.
	block = bli_mem_buffer( mem );

	// Extract the buffer type so we know what kind of memory was allocated.
	buf_type = bli_mem_buf_type( mem );

#ifdef BLIS_ENABLE_C66X_MEM_POOLS
	if (bli_buf_type_is_shared(buf_type))
		core_id = 0;
	else
		core_id = omp_get_thread_num ();
#endif

	if ( buf_type == BLIS_BUFFER_FOR_GEN_USE )
	{
		// For general-use buffers, we allocate with bli_malloc(), and so
		// here we need to call bli_free().
		bli_free( block );
	}
	else
	{
		// This branch handles cases where the memory block came from one
		// of the contiguous memory pools.

		// Extract the pool from which the block was allocated.
		pool = bli_mem_pool( mem );

		// Extract the block pointer array associated with the pool.
		block_ptrs = bli_pool_block_ptrs( pool );
#ifdef BLIS_ENABLE_C66X_MEM_DEBUG
		printf("Release: buf_type %x pool size %d block %x\n", buf_type, bli_pool_block_size( pool ), block);
#endif


		// BEGIN CRITICAL SECTION
#ifdef BLIS_ENABLE_OPENMP        
        _Pragma( "omp critical (mem)" )
#endif
        {

		// Increment the top of the memory pool.
#ifdef BLIS_ENABLE_C66X_MEM_POOLS
		bli_pool_inc_top_index( pool, core_id );
#else
		bli_pool_inc_top_index( pool );
#endif

		// Query the newly incremented top index.
#ifdef BLIS_ENABLE_C66X_MEM_POOLS
		i = bli_pool_top_index( pool, core_id );
#else
		i = bli_pool_top_index( pool );
#endif

		// Place the address of the block back onto the top of the memory pool.
		block_ptrs[i] = block;


		// END CRITICAL SECTION
        }
	}


	// Clear the mem_t object so that it appears unallocated. We clear:
	// - the buffer field,
	// - the pool field, and
	// - the size field.
	// NOTE: We do not clear the buf_type field since there is no
	// "uninitialized" value for packbuf_t.
	bli_mem_set_buffer( NULL, mem );
	bli_mem_set_pool( NULL, mem );
	bli_mem_set_size( 0, mem );
}


void bli_mem_acquire_v( siz_t  req_size,
                        mem_t* mem )
{
	bli_mem_acquire_m( req_size,
	                   BLIS_BUFFER_FOR_GEN_USE,
	                   mem );
}

#ifdef BLIS_ENABLE_C66X_MEM_POOLS
/*==============================================================================
 * Functions bli_get_mem_sizes() and bli_scratch_mem_alloc() are only used for
 * C66x implementation.
 *
 * BLIS memories are allocated in 3 different ways:
 * 1. persistent memory: allocated by lib_pmem_salloc() which calls malloc() for now.
 * 2. very fast, fast, and medium speed scratch memory: allocated by 
 *    bli_scratch_mem_alloc(). 
 *       - This may be done just once at boot time if the provided memory address 
 *         stay the same. This may be the case for DSP-only application where the
 *         memories for BLIS are statically allocated.
 *       - This can also be done before every level 3 BLAS function call. This 
 *         may be the case when memories for BLIS are dynamically allocated in 
 *         ARM+DSP applications. 
 *       - Heaps need to be initialized by tiCblas API before allocation. 
 * 3. slow scratch memory: allocated by lib_smem_salloc() inside BLIS computation.
 *    The heap (slow scratch) needs to be initialized the same as above and reset 
 *    whenever a level 3 BLIS function is called.
 *
 *============================================================================*/
#define getNextMultiple(x, y) ( ( ((x)+(y)-1)/(y) )* (y) )

#define BLAS_MEM_SIZE_VFAST (  getNextMultiple(BLIS_MK_POOL_SIZE_L1, BLIS_CACHE_LINE_SIZE) \
                             + getNextMultiple(BLIS_KN_POOL_SIZE_L1, BLIS_CACHE_LINE_SIZE) \
                             + getNextMultiple(BLIS_MN_POOL_SIZE_L1, BLIS_CACHE_LINE_SIZE) )
#define BLAS_MEM_SIZE_FAST  (  getNextMultiple(BLIS_MK_POOL_SIZE_L2, BLIS_CACHE_LINE_SIZE) \
                             + getNextMultiple(BLIS_KN_POOL_SIZE_L2, BLIS_CACHE_LINE_SIZE) \
                             + getNextMultiple(BLIS_MN_POOL_SIZE_L2, BLIS_CACHE_LINE_SIZE) )
#define BLAS_MEM_SIZE_MEDIUM ( getNextMultiple(BLIS_MK_POOL_SIZE_L3, BLIS_CACHE_LINE_SIZE) \
                             + getNextMultiple(BLIS_KN_POOL_SIZE_L3, BLIS_CACHE_LINE_SIZE) \
                             + getNextMultiple(BLIS_MN_POOL_SIZE_L3, BLIS_CACHE_LINE_SIZE) )
#define BLAS_MEM_SIZE_SLOW    (4804)

/*==============================================================================
 * Purpose: returns the sizes of the non-persistent memories used by BLIS. 
 *============================================================================*/
void bli_get_mem_sizes(size_t *smem_size_vfast,  size_t *smem_size_fast, 
                       size_t *smem_size_medium, size_t *smem_size_slow)
{
    *smem_size_vfast  = BLAS_MEM_SIZE_VFAST;  /* very fast scratch memory     */
    *smem_size_fast   = BLAS_MEM_SIZE_FAST;   /* fast scratch memory          */
    *smem_size_medium = BLAS_MEM_SIZE_MEDIUM; /* medium speed scratch memory  */ 
    *smem_size_slow   = BLAS_MEM_SIZE_SLOW;   /* slow scratch memory          */
}

/*==============================================================================
 * Purpose: allocates very fast, fast, and medium speed scratch memories from
 *          initialized heaps. 
 * Note: slow memoris are allocated during BLIS compuation.
 *============================================================================*/
int bli_scratch_mem_alloc()
{
    lib_memdscr_t **blas_mem_handle = blasGetMemHandle();
    
    pool_mk_mem_L1 = lib_smem_valloc(blas_mem_handle, BLIS_MK_POOL_SIZE_L1, BLIS_CACHE_LINE_SIZE);
    pool_kn_mem_L1 = lib_smem_valloc(blas_mem_handle, BLIS_KN_POOL_SIZE_L1, BLIS_CACHE_LINE_SIZE);
    pool_mn_mem_L1 = lib_smem_valloc(blas_mem_handle, BLIS_MN_POOL_SIZE_L1, BLIS_CACHE_LINE_SIZE);

    pool_mk_mem_L2 = lib_smem_falloc(blas_mem_handle, BLIS_MK_POOL_SIZE_L2, BLIS_CACHE_LINE_SIZE);
    pool_kn_mem_L2 = lib_smem_falloc(blas_mem_handle, BLIS_KN_POOL_SIZE_L2, BLIS_CACHE_LINE_SIZE);
    pool_mn_mem_L2 = lib_smem_falloc(blas_mem_handle, BLIS_MN_POOL_SIZE_L2, BLIS_CACHE_LINE_SIZE);
    
    pool_mk_mem_L3 = lib_smem_malloc(blas_mem_handle, BLIS_MK_POOL_SIZE_L3, BLIS_CACHE_LINE_SIZE);
    pool_kn_mem_L3 = lib_smem_malloc(blas_mem_handle, BLIS_KN_POOL_SIZE_L3, BLIS_CACHE_LINE_SIZE);
    pool_mn_mem_L3 = lib_smem_malloc(blas_mem_handle, BLIS_MN_POOL_SIZE_L3, BLIS_CACHE_LINE_SIZE);    

    if(  (pool_mk_mem_L1 == NULL)
       ||(pool_kn_mem_L1 == NULL) 
       ||(pool_mn_mem_L1 == NULL)          
       ||(pool_mk_mem_L2 == NULL) 
       ||(pool_kn_mem_L2 == NULL) 
       ||(pool_mn_mem_L2 == NULL)          
       ||(pool_mk_mem_L3 == NULL) 
       ||(pool_kn_mem_L3 == NULL) 
       ||(pool_mn_mem_L3 == NULL) ) {
      return(BLI_MEM_ALLOC_ERROR);    
    } 
    else {
      bli_mem_init();
      return(BLI_MEM_ALLOC_SUCCESS);
    }    
}
#endif /* BLIS_ENABLE_C66X_MEM_POOLS */

void bli_mem_init()
{
	dim_t index_a;
	dim_t index_b;
	dim_t index_c;

#ifdef BLIS_ENABLE_C66X_MEM_POOLS

	dim_t index_aL1;
	dim_t index_bL1;
	dim_t index_cL1;

	dim_t index_aL2;
	dim_t index_bL2;
	dim_t index_cL2;

	dim_t index_aL3;
	dim_t index_bL3;
	dim_t index_cL3;
#endif


	// Map each of the packbuf_t values to an index starting at zero.
	index_a = bli_packbuf_index( BLIS_BUFFER_FOR_A_BLOCK );
	index_b = bli_packbuf_index( BLIS_BUFFER_FOR_B_PANEL );
	index_c = bli_packbuf_index( BLIS_BUFFER_FOR_C_PANEL );

#ifdef BLIS_ENABLE_C66X_MEM_POOLS
	index_aL1 = bli_packbuf_index( BLIS_BUFFER_FOR_A_BLOCK_L1 );
	index_bL1 = bli_packbuf_index( BLIS_BUFFER_FOR_B_PANEL_L1 );
	index_cL1 = bli_packbuf_index( BLIS_BUFFER_FOR_C_PANEL_L1 );

	index_aL2 = bli_packbuf_index( BLIS_BUFFER_FOR_A_BLOCK_L2 );
	index_bL2 = bli_packbuf_index( BLIS_BUFFER_FOR_B_PANEL_L2 );
	index_cL2 = bli_packbuf_index( BLIS_BUFFER_FOR_C_PANEL_L2 );

	index_aL3 = bli_packbuf_index( BLIS_BUFFER_FOR_A_BLOCK_L3 );
	index_bL3 = bli_packbuf_index( BLIS_BUFFER_FOR_B_PANEL_L3 );
	index_cL3 = bli_packbuf_index( BLIS_BUFFER_FOR_C_PANEL_L3 );
#endif

#ifdef BLIS_ENABLE_C66X_MEM_POOLS

	// Initialize contiguous memory pool for MC x KC blocks.
	bli_mem_init_pool( pool_mk_mem,
	                   BLIS_MK_BLOCK_SIZE,
	                   BLIS_NUM_MC_X_KC_BLOCKS,
	                   pool_mk_blk_ptrs,
	                   &pools[ index_a ],
	                   BLIS_BUFFER_FOR_A_BLOCK);

	// Initialize contiguous memory pool for KC x NC blocks.
	bli_mem_init_pool( pool_kn_mem,
	                   BLIS_KN_BLOCK_SIZE,
	                   BLIS_NUM_KC_X_NC_BLOCKS,
	                   pool_kn_blk_ptrs,
	                   &pools[ index_b ],
	                   BLIS_BUFFER_FOR_B_PANEL);

	// Initialize contiguous memory pool for MC x NC blocks.
	bli_mem_init_pool( pool_mn_mem,
	                   BLIS_MN_BLOCK_SIZE,
	                   BLIS_NUM_MC_X_NC_BLOCKS,
	                   pool_mn_blk_ptrs,
	                   &pools[ index_c ],
	                   BLIS_BUFFER_FOR_C_PANEL);

#ifdef BLIS_ENABLE_C66X_MEM_DEBUG
	printf("L1 Cache\n");
	printf("MK: Pool Size %d, Num Blocks %d, Block size %d\n",BLIS_MK_POOL_SIZE_L1, BLIS_NUM_MR_X_KC_BLOCKS_L1, BLIS_MRK_BLOCK_SIZE);
	printf("MK: Block size %d Block size S %d Block size D %d\n",BLIS_MRK_BLOCK_SIZE, BLIS_MRK_BLOCK_SIZE_S, BLIS_MRK_BLOCK_SIZE_D);
	printf("KN: Pool Size %d, Num Blocks %d, Block size %d\n",BLIS_KN_POOL_SIZE_L1, BLIS_NUM_KC_X_NR_BLOCKS_L1, BLIS_KNR_BLOCK_SIZE);
	printf("MN: Pool Size %d, Num Blocks %d, Block size %d\n",BLIS_MN_POOL_SIZE_L1, BLIS_NUM_MR_X_NR_BLOCKS_L1, BLIS_MRNR_BLOCK_SIZE);
#endif

	//L1 Cache
	// Initialize contiguous memory pool for MR x KC blocks.
		bli_mem_init_pool( pool_mk_mem_L1,
				BLIS_MRK_BLOCK_SIZE,
				BLIS_NUM_MR_X_KC_BLOCKS_L1,
				pool_mk_blk_ptrs_L1,
				&pools[ index_aL1 ],
				BLIS_BUFFER_FOR_A_BLOCK_L1);

		// Pool for L1
		// Initialize contiguous memory pool for KC x NR blocks.
		bli_mem_init_pool( pool_kn_mem_L1,
				BLIS_KNR_BLOCK_SIZE,
				BLIS_NUM_KC_X_NR_BLOCKS_L1,
				pool_kn_blk_ptrs_L1,
				&pools[ index_bL1 ],
				BLIS_BUFFER_FOR_B_PANEL_L1);

		// Pool for L1
		// Initialize contiguous memory pool for MC x NC blocks.
		bli_mem_init_pool( pool_mn_mem_L1,
				BLIS_MRNR_BLOCK_SIZE,
				BLIS_NUM_MR_X_NR_BLOCKS_L1,
				pool_mn_blk_ptrs_L1,
				&pools[ index_cL1 ],
				BLIS_BUFFER_FOR_C_PANEL_L1);

#ifdef BLIS_ENABLE_C66X_MEM_DEBUG
		printf("L2 Cache\n");
		printf("MK: Pool Size %d, Num Blocks %d, Block size %d\n",BLIS_MK_POOL_SIZE_L2, BLIS_NUM_MC_X_KC_BLOCKS_L2, BLIS_MK_BLOCK_SIZE);
		printf("KN: Pool Size %d, Num Blocks %d, Block size %d\n",BLIS_KN_POOL_SIZE_L2, BLIS_NUM_KC_X_NC_BLOCKS_L2, BLIS_KN_BLOCK_SIZE);
		printf("MN: Pool Size %d, Num Blocks %d, Block size %d\n",BLIS_MN_POOL_SIZE_L2, BLIS_NUM_MC_X_NC_BLOCKS_L2, BLIS_MN_BLOCK_SIZE);
		printf("MK: Block Size %d, %d, %d, %d, %d, %d, %d, %d\n",BLIS_MK_BLOCK_SIZE_S ,BLIS_MK_BLOCK_SIZE_D ,BLIS_MK_BLOCK_SIZE_C,
					BLIS_MK_BLOCK_SIZE_Z,BLIS_MK_BLOCK_SIZE_4M_C,BLIS_MK_BLOCK_SIZE_4M_Z,BLIS_MK_BLOCK_SIZE_3M_C,BLIS_MK_BLOCK_SIZE_3M_Z );
#endif
		//L2 Cache
		// Initialize contiguous memory pool for MC x KC blocks.
		bli_mem_init_pool( pool_mk_mem_L2,
			                   BLIS_MK_BLOCK_SIZE,
			                   BLIS_NUM_MC_X_KC_BLOCKS_L2,
			                   pool_mk_blk_ptrs_L2,
			                   &pools[ index_aL2 ],
			                   BLIS_BUFFER_FOR_A_BLOCK_L2 );

		// Initialize contiguous memory pool for KC x NC blocks.
		bli_mem_init_pool( pool_kn_mem_L2,
						   BLIS_KN_BLOCK_SIZE,
		                   BLIS_NUM_KC_X_NC_BLOCKS_L2,
		                   pool_kn_blk_ptrs_L2,
		                   &pools[ index_bL2 ],
		                   BLIS_BUFFER_FOR_B_PANEL_L2);

		// Initialize contiguous memory pool for MC x NC blocks.
		bli_mem_init_pool( pool_mn_mem_L2,
				           BLIS_MNR_BLOCK_SIZE,
		                   BLIS_NUM_MC_X_NR_BLOCKS_L2,
		                   pool_mn_blk_ptrs_L2,
		                   &pools[ index_cL2 ],
		                   BLIS_BUFFER_FOR_C_PANEL_L2);

#ifdef BLIS_ENABLE_C66X_MEM_DEBUG
		//L3 Cache
			printf("L3 Cache\n");
			printf("MK: Pool Size %d, Num Blocks %d, Block size %d\n",BLIS_MK_POOL_SIZE_L3, BLIS_NUM_MC_X_KC_BLOCKS_L3, BLIS_MK_BLOCK_SIZE);
			printf("KN: Pool Size %d, Num Blocks %d, Block size %d\n",BLIS_KN_POOL_SIZE_L3, BLIS_NUM_KC_X_NC_BLOCKS_L3, BLIS_KN_BLOCK_SIZE);
			printf("MN: Pool Size %d, Num Blocks %d, Block size %d\n",BLIS_MN_POOL_SIZE_L3, BLIS_NUM_MC_X_NC_BLOCKS_L3, BLIS_MN_BLOCK_SIZE);
			printf("BLIS_POOL_KC_S: %d BLIS_POOL_NC_S: %d\n", BLIS_POOL_KC_S, BLIS_POOL_NC_S);

			printf("KN: Block Size %d, %d, %d, %d, %d, %d, %d, %d\n",BLIS_KN_BLOCK_SIZE_S ,BLIS_KN_BLOCK_SIZE_D ,BLIS_KN_BLOCK_SIZE_C,
								BLIS_KN_BLOCK_SIZE_Z,BLIS_KN_BLOCK_SIZE_4M_C,BLIS_KN_BLOCK_SIZE_4M_Z,BLIS_KN_BLOCK_SIZE_3M_C,BLIS_KN_BLOCK_SIZE_3M_Z );
#endif
		//L3 Cache
		// Initialize contiguous memory pool for MC x KC blocks.
		bli_mem_init_pool( pool_mk_mem_L3,
		                   BLIS_MK_BLOCK_SIZE,
		                   BLIS_NUM_MC_X_KC_BLOCKS_L3,
		                   pool_mk_blk_ptrs_L3,
		                   &pools[ index_aL3 ],
		                   BLIS_BUFFER_FOR_A_BLOCK_L3);

		// Initialize contiguous memory pool for KC x NC blocks.
		bli_mem_init_pool( pool_kn_mem_L3,
		                   BLIS_KN_BLOCK_SIZE,
		                   BLIS_NUM_KC_X_NC_BLOCKS_L3,
		                   pool_kn_blk_ptrs_L3,
		                   &pools[ index_bL3 ],
		                   BLIS_BUFFER_FOR_B_PANEL_L3);

		// Initialize contiguous memory pool for MC x NC blocks.
		bli_mem_init_pool( pool_mn_mem_L3,
		                   BLIS_MN_BLOCK_SIZE,
		                   BLIS_NUM_MC_X_NC_BLOCKS_L3,
		                   pool_mn_blk_ptrs_L3,
		                   &pools[ index_cL3 ],
		                   BLIS_BUFFER_FOR_C_PANEL_L3);
#ifdef BLIS_ENABLE_C66X_MEM_DEBUG
	printf("Pools initialized\n");
#endif

#else
		// Initialize contiguous memory pool for MC x KC blocks.
		bli_mem_init_pool( pool_mk_mem,
		                   BLIS_MK_BLOCK_SIZE,
		                   BLIS_NUM_MC_X_KC_BLOCKS,
		                   pool_mk_blk_ptrs,
		                   &pools[ index_a ] );

		// Initialize contiguous memory pool for KC x NC blocks.
		bli_mem_init_pool( pool_kn_mem,
		                   BLIS_KN_BLOCK_SIZE,
		                   BLIS_NUM_KC_X_NC_BLOCKS,
		                   pool_kn_blk_ptrs,
		                   &pools[ index_b ] );

		// Initialize contiguous memory pool for MC x NC blocks.
		bli_mem_init_pool( pool_mn_mem,
		                   BLIS_MN_BLOCK_SIZE,
		                   BLIS_NUM_MC_X_NC_BLOCKS,
		                   pool_mn_blk_ptrs,
		                   &pools[ index_c ] );
#endif
}


#ifdef BLIS_ENABLE_C66X_MEM_POOLS

void bli_mem_init_pool( char*   pool_mem,
                        siz_t   block_size,
                        dim_t   num_blocks,
                        void**  block_ptrs,
                        pool_t* pool,
                        membuf_t buf_type)
{
	//const siz_t align_size = BLIS_CONTIG_ADDR_ALIGN_SIZE;
	const siz_t align_size = 64;
	dim_t       i;

	// If the pool starting address is not already aligned, advance it
	// accordingly.
	if ( bli_is_unaligned_to( ( uintptr_t )pool_mem, ( uintptr_t )align_size ) )
	{
		// Notice that this works even if the alignment is not a power of two.
		pool_mem += (   ( uintptr_t )align_size -
		              ( ( uintptr_t )pool_mem % align_size ) );
	}

	// Step through the memory pool, beginning with the aligned address
	// determined above, assigning pointers to the beginning of each block_size
	// bytes to the ith element of the block_ptrs array.
	for ( i = 0; i < num_blocks; ++i )
	{
		// Save the address of pool, which is guaranteed to be aligned.
		block_ptrs[i] = pool_mem;

		// Advance pool by one block.
		pool_mem += block_size;

		// Advance pool a bit further if needed in order to get to the
		// beginning of an alignment boundary.
		if ( bli_is_unaligned_to( ( uintptr_t )pool_mem, ( uintptr_t )align_size ) )
		{
			pool_mem += (   ( uintptr_t )align_size -
			              ( ( uintptr_t )pool_mem % align_size ) );
		}
	}

	// Now that we have initialized the array of pointers to the individual
	// blocks in the pool, we initialize a pool_t data structure so that we
	// can easily manage this pool.
	bli_pool_init( num_blocks,
	               block_size,
	               block_ptrs,
	               pool);
#ifdef BLIS_ENABLE_C66X_MEM_DEBUG
	printf("buf_type %x shared %d num_blocks %d\n", buf_type, bli_buf_type_is_shared(buf_type), num_blocks);
#endif


	for(i = 0; i < BLIS_MAX_NUM_THREADS; i++)
	{
		if (bli_buf_type_is_shared(buf_type))
		{
			/* If buf_type is shared then set only top_index[0] to num_blocks-1*/
			if (i == 0)
			{
				bli_pool_set_top_index( num_blocks-1, pool, 0 );
			}
			else
			{
				bli_pool_set_top_index( -1, pool, i );
			}
		}
		else
		{
			bli_pool_set_top_index( num_blocks-1, pool, i );
		}
	}

}

#else

void bli_mem_init_pool( char*   pool_mem,
                        siz_t   block_size,
                        dim_t   num_blocks,
                        void**  block_ptrs,
                        pool_t* pool )
{
	const siz_t align_size = BLIS_CONTIG_ADDR_ALIGN_SIZE;
	dim_t       i;

	// If the pool starting address is not already aligned, advance it
	// accordingly.
	if ( bli_is_unaligned_to( ( uintptr_t )pool_mem, ( uintptr_t )align_size ) )
	{
		// Notice that this works even if the alignment is not a power of two.
		pool_mem += (   ( uintptr_t )align_size - 
		              ( ( uintptr_t )pool_mem % align_size ) );
	}

	// Step through the memory pool, beginning with the aligned address
	// determined above, assigning pointers to the beginning of each block_size
	// bytes to the ith element of the block_ptrs array.
	for ( i = 0; i < num_blocks; ++i )
	{
		// Save the address of pool, which is guaranteed to be aligned.
		block_ptrs[i] = pool_mem;

		// Advance pool by one block.
		pool_mem += block_size;

		// Advance pool a bit further if needed in order to get to the
		// beginning of an alignment boundary.
		if ( bli_is_unaligned_to( ( uintptr_t )pool_mem, ( uintptr_t )align_size ) )
		{
			pool_mem += (   ( uintptr_t )align_size -
			              ( ( uintptr_t )pool_mem % align_size ) );
		}
	}

	// Now that we have initialized the array of pointers to the individual
	// blocks in the pool, we initialize a pool_t data structure so that we
	// can easily manage this pool.
	bli_pool_init( num_blocks,
	               block_size,
	               block_ptrs,
	               pool );
}
#endif


void bli_mem_finalize()
{
	// Nothing to do.
}

