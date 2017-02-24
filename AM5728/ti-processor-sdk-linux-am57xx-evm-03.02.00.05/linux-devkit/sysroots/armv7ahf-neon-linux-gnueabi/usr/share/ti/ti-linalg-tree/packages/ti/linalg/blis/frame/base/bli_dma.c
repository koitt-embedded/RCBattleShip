/*

   BLIS
   An object-based framework for developing high-performance BLAS-like
   libraries.

   Copyright (C) 2014, The University of Texas

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    - Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    - Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    - Neither the name of The University of Texas nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

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

#if defined(BLIS_ENABLE_C66X_OPENCL)
int ti_printf(FILE* _fp, const char *_format, ...)
{
	 va_list argptr;
	 va_start(argptr,_format);
	 printf(_format, argptr);
	 va_end(argptr);
	 return 0;
}
#endif

#if defined(BLIS_ENABLE_C66X_BUILD) && defined(BLIS_ENABLE_C66X_MEM_POOLS) && defined(BLIS_ENABLE_C66X_EDMA)
//#define BLIS_EDMA_DEBUG
//#define BLIS_ENABLE_CYCLE_COUNT
static dma_t dma_pools[BLIS_MAX_NUM_THREADS]; // One pool for each core.

static lib_emt_Handle pool_coreX_emt_handles[BLIS_MAX_NUM_THREADS][BLIS_C66X_EDMA_MAX_NUM_CHANNELS];

//for initilization during encoding the dma control leaf
dmam_t* bli_dmam_cntl_obj_create( impl_t     impl_type,
		varnum_t   var_num,
		blksz_t*   mc,
		blksz_t*   nc,
		membuf_t   dma_buf_type )
{
	dmam_t* cntl;

	cntl = ( dmam_t* ) bli_malloc( sizeof(dmam_t) );

	cntl->impl_type         = impl_type;
	cntl->var_num           = var_num;
	cntl->mc                = mc;
	cntl->nc                = nc;
	cntl->dma_buf_type      = dma_buf_type;

	return cntl;
}

void bli_dma_init()
{
	// Create threads so that initialization is done on each core.
	_Pragma( "omp parallel num_threads(BLIS_MAX_NUM_THREADS)" )
	{
		gint_t status; //int32_t
        status = lib_emt_init();
   
		if(status != LIB_EMT_SUCCESS)
		{
			printf("Core %d DMA not initialized\n", lib_get_coreID());
			exit(1);
		}
		bli_dma_init_pool(status, BLIS_C66X_EDMA_MAX_NUM_CHANNELS, pool_coreX_emt_handles[lib_get_coreID()], &dma_pools[lib_get_coreID()]);
	}
}

void bli_dma_init_pool(gint_t emt_status,
		gint_t num_channels,
		lib_emt_Handle* pool_emt_handles,
		dma_t* dma_pool)
{
	dim_t i;
	lib_emt_Handle temp_handle;
	if(emt_status != LIB_EMT_SUCCESS)
	{
		dma_pool->emt_status = FALSE;
		printf("Core %d DMA not initialized\n", lib_get_coreID());
		return;
	}
	dma_pool->emt_status = TRUE;

	for(i = 0; i < num_channels; i++)
	{
		//pool_emt_handles[i] =  lib_emt_alloc(1);
		temp_handle =  lib_emt_alloc(1);
		if(temp_handle == NULL)
		{
			printf("Failed to alloc edma handle CoreID %d\n", lib_get_coreID());
			return;
		}

		pool_emt_handles[i] = temp_handle;
	}
	dma_pool->num_channels = num_channels;
	dma_pool->emt_handle = pool_emt_handles;
	dma_pool->top_index = num_channels-1;
#ifdef BLIS_EDMA_DEBUG
	printf("Core ID %d, Dma pool top index %d, num channels = %d\n",lib_get_coreID(), dma_pool->top_index, dma_pool->num_channels);
#endif
}

void bli_dma_channel_acquire(lib_emt_Handle* emt_handle, dim_t core_id)
{
	dma_t* dma_pool;
	lib_emt_Handle* emt_handle_ptrs;
	dim_t i;

	dma_pool = &dma_pools[core_id];

	// Check if channels are still available
	if(dma_pool->top_index == -1)
	{
		printf("DMA pool exhausted\n");
		return;
	}

	// Get all the handles of DMA pool
	emt_handle_ptrs = dma_pool->emt_handle;

	//Get index of the top most available handle
	i = dma_pool->top_index;

	//Get edma handle
	*emt_handle = emt_handle_ptrs[i];
#ifdef BLIS_EDMA_DEBUG
	printf("Acquiring DMA handle, top index %d edma handle %x %x\n", i, *emt_handle, emt_handle_ptrs[i]);
#endif
	// Decrement the index so that it now points to the next available handle.
	dma_pool->top_index--;

}

void bli_dma_channel_release(lib_emt_Handle emt_handle, dim_t core_id)
{
	dma_t* dma_pool;
	lib_emt_Handle* emt_handle_ptrs;
	dim_t i;

	if(emt_handle == NULL)
	{
		printf("nothing to release\n");
		return;
	}
	dma_pool = &dma_pools[core_id];

	// Get all the handles of DMA pool
	emt_handle_ptrs = dma_pool->emt_handle;

	// Increment the index so that it now points to the next available handle.
	dma_pool->top_index++;

	//Get this new top index
	i = dma_pool->top_index;

	//Place the edma handle back onto the top of the dma pool.
	// This is done so that if handles were release not in the same order
	// that they were acquired, the next time a handle is acquired it gets the latest released one.
	emt_handle_ptrs[i] = emt_handle;

#ifdef BLIS_EDMA_DEBUG
	printf("Released DMA handle, top index %d edma handle %x \n", i, emt_handle_ptrs[i]);
#endif
}

void bli_dmam_init( obj_t*   a,
		obj_t*   p,
		dmam_t* cntl)
{
	dim_t     m_root, n_root;
	dim_t     m_p, n_p;
	dim_t     m_transfer, n_transfer;
	struc_t   struc_p;
	uplo_t    uplo_p;
	doff_t    diagoff_p;

	mem_t* dmamem_a; //source mem_t
	mem_t* dmamem_p; // destination mem_t
	siz_t  size_p; //Size in bytes of the destination buffer. Will this be same as the source?
	membuf_t dma_buf_type;

	inc_t   rs_a, cs_a;
	inc_t   rs_p, cs_p;
	inc_t   offm_p, offn_p;
	inc_t   offm_a, offn_a;

	siz_t  elem_size;

	void*   buf; //Will point to the data buffer within destination


	if ( bli_error_checking_is_enabled() )
		bli_dmam_init_check( a, p, cntl ); //Need to add functionality

	// First check if we are to skip this operation because the control tree
	// is NULL, and if so, simply alias the object to its destination counterpart.
	if ( cntl_is_noop( cntl ) )
	{
		bli_obj_alias_to( *a, *p );
		return;
	}

	if ( bli_obj_is_zeros( *a ) )
	{
		bli_obj_alias_for_dma( *a, *p );
		return;
	}

	// Get dma_mem field from the source
	dmamem_a =  bli_obj_dma_mem( *a );

	// Check if source object is already in destination buffer type. If so alias,
	// simply alias the object to its destination counterpart.
	if ( dmamem_a->buf_type == cntl->dma_buf_type)
	{
		bli_obj_alias_to(*a, *p);
		return;
	}


	// If DMA needs to occur, copy the basic fields of the object.
	bli_obj_alias_for_dma( *a, *p );

	rs_a       = bli_obj_row_stride(*a);
	cs_a       = bli_obj_col_stride(*a);

	m_root        = bli_obj_length( *(bli_obj_root( *a )) );
	n_root        = bli_obj_width( *(bli_obj_root( *a )) );

	offm_a     = bli_obj_row_offset( *a );
	offn_a     = bli_obj_col_offset( *a );

	m_p        = bli_obj_length( *p );
	n_p        = bli_obj_width( *p );
	diagoff_p   = bli_obj_diag_offset( *p );
	struc_p     = bli_obj_struc( *p );
	uplo_p      = bli_obj_uplo( *p );



	elem_size = p->elem_size;

	/* If the partition is not a general and if it intersects the diagonal, then we
	 * must transfer rows/columns that are outside the partition so that the packing
	 * routine can "densify" or symmetrize the panel.
	 */
	if(!bli_obj_root_is_general( *p ) && bli_obj_intersects_diag( *p ) && !(bli_is_triangular( struc_p )) && bli_is_herm_or_symm(struc_p))
	{
		//printf("not general and diag intersects\n");
			if(bli_is_lower(uplo_p))
			{
				//printf("lower diagoff %d m_p %d, n_p %d offm_a %d, offn_a %d\n", diagoff_p, m_p, n_p, offm_a, offn_a);
				m_transfer = bli_max(m_p, n_p - diagoff_p);
				n_transfer = bli_max(m_p, bli_min (n_p, m_p + diagoff_p ));

				if (offm_a + m_transfer > m_root)
					m_transfer = m_root - offm_a;

				offm_p = 0;
				if(diagoff_p < 0 )
					offn_p = -diagoff_p;
				else
					offn_p = 0;

				if (bli_is_col_stored( rs_a , cs_a ))
				{
					rs_p = 1;
					cs_p = m_transfer;
				}
				else if (bli_is_row_stored( rs_a , cs_a ))
				{
					rs_p = n_transfer;
					cs_p = 1;
				}
			}
			else
			{
				//printf("upper diagoff %d\n", diagoff_p);
				m_transfer = bli_max(m_p, m_p + diagoff_p);
				n_transfer = bli_max(m_p, bli_min (n_p, n_p - diagoff_p ));

				if (offn_a + n_transfer > n_root)
					n_transfer = n_root - offn_a;

				//printf("upper diagoff %d m_p %d, n_p %d offm_a %d, offn_a %d\n", diagoff_p, m_p, n_p, offm_a, offn_a);

				if(diagoff_p > 0 )
				{
					offm_p = diagoff_p;
					offn_p = -diagoff_p; // Move to the right
				}
				else
				{
					offm_p = 0;
					offn_p = 0;
				}

				if (bli_is_col_stored( rs_a , cs_a ))
				{
					rs_p = 1;
					cs_p = m_transfer;
				}
				else
				{
					rs_p = n_transfer;
					cs_p = 1;
				}

			}
	}
	else
	{
		offm_p = 0;
		offn_p = 0;

		m_transfer = m_p;
		n_transfer = n_p;


		if (bli_is_col_stored( rs_a , cs_a ))
		{
			rs_p = 1;
			cs_p = m_p;
		}
		else
		{
			rs_p = n_p;
			cs_p = 1;
		}
	}

	bli_obj_set_incs( rs_p, cs_p, *p );
	bli_obj_set_offs( offm_p, offn_p, *p );

	size_p = m_transfer * n_transfer * elem_size;

	//printf("m_p %d n_p %d m_trans %d, n_trans %d size %d\n",m_p, n_p, m_transfer, n_transfer, size_p);

	dmamem_p = bli_obj_dma_mem(*p);
	dma_buf_type  = cntl->dma_buf_type;

	if ( bli_mem_is_unalloc( dmamem_p ) )
	{
		// If the mem_t object of p has not yet been allocated, then acquire
		// a memory block of type pack_buf_type.
		// Will need to change this to allocate memory from the correct location
		bli_mem_acquire_m( size_p,
				dma_buf_type,
				dmamem_p );
	}
	else
	{
		// If the mem_t object is currently allocated and smaller than is
		// needed, then it must have been allocated for a different type
		// of object (a different pack_buf_type value), so we must first
		// release it and then re-acquire it using the new size and new
		// pack_buf_type value.
		if ( bli_mem_size( dmamem_p ) < size_p )
		{
			bli_mem_release( dmamem_p );
			bli_mem_acquire_m( size_p,
					dma_buf_type,
					dmamem_p );
		}
	}


	//Set buffer in obj_t to point to the buffer in dma_mem;

	buf = bli_mem_buffer( dmamem_p );
	bli_obj_set_buffer( buf, *p );

	//If definition does not have an EDMA channel, then acquire a channel from the pool
	if(p->emt_handle == NULL)
	{
		bli_dma_channel_acquire(&(p->emt_handle), lib_get_coreID());
		if(p->emt_handle == NULL)
			printf("DMAM_INIT Failed to alloc edma handle CoreID %d.\n", lib_get_coreID());
	}
}

void bli_dmam_init_check(obj_t*   a,
		obj_t*   p,
		dmam_t* cntl)
{



}

void bli_dmam_int( obj_t*   a,
		obj_t*   p,
		dmam_t* cntl,
		dmam_thrinfo_t* thread )
{
	mem_t* dmamem_a; //source mem_t

	// First check if we are to skip this operation because the control tree
	// is NULL. We return without taking any action because a was already
	// aliased to p in dmam_init().
	if ( cntl_is_noop( cntl ) )
	{
		return;
	}

	if ( bli_obj_is_zeros( *a ) )
	{
		return;
	}


	// Get dma_mem field from the source
	dmamem_a =  bli_obj_dma_mem( *a );

	// Check if source object is already in destination buffer type. If so the destination
	// has already been aliased during the initialization, so can return.
	if ( dmamem_a->buf_type == cntl->dma_buf_type)
	{
		return;
	}

	bli_dma_var1(a, p, thread);

}

void bli_dma_var1( obj_t*   a,
		obj_t*   p,
		dmam_thrinfo_t* thread )
{
	dim_t     m_root, n_root;
	dim_t     m_p, n_p;
	dim_t     m_transfer, n_transfer;
	struc_t   struc_p;
	uplo_t    uplo_p;
	doff_t    diagoff_p;
	dim_t     offm_p;
	dim_t     offn_p;

	dim_t     offm_a, offn_a;

	inc_t cs_source;
	inc_t rs_source;

	inc_t cs_dest;
	inc_t rs_dest;

	dim_t num_iter = 0; // # of iterations of memcpy will be required.
	dim_t iter; //loop counter for iterations

	dim_t ld_source = 0; // leading dimension of the source.
	//Indicates the number of elements to be jumped to reach the next row/column.
	// This value will be the (row/column stride)*size of element;
	dim_t ld_dest = 0; // leading dimension of the destination.

	siz_t elem_size;
	siz_t elem_move = 0; // number of bytes to be moved during the memcpy

	void* ptr_source;
	void* ptr_dest;

#ifdef BLIS_ENABLE_CYCLE_COUNT
    uint64_t counter_start;
    uint64_t counter_end;
#endif

	m_root     = bli_obj_length( *(bli_obj_root( *a )) );
	n_root     = bli_obj_width( *(bli_obj_root( *a )) );

	offm_a     = bli_obj_row_offset( *a );
	offn_a     = bli_obj_col_offset( *a );

	m_p        = bli_obj_length( *p );
	n_p        = bli_obj_width( *p );

	cs_source = bli_obj_col_stride( *a ) ;
	rs_source = bli_obj_row_stride( *a ) ;

	cs_dest   = bli_obj_col_stride( *p ) ;
	rs_dest   = bli_obj_row_stride( *p ) ;

	elem_size = bli_obj_elem_size( *a );

	struc_p     = bli_obj_struc( *p );
	uplo_p      = bli_obj_uplo( *p );
	diagoff_p   = bli_obj_diag_offset( *p );

	m_transfer = m_p;
	n_transfer = n_p;
	if(!bli_obj_root_is_general( *p ) && bli_obj_intersects_diag( *p ) && !(bli_is_triangular( struc_p )))
	{
		//printf("not general and diag intersects\n");
		if(bli_is_herm_or_symm( struc_p ))
		{
			if(bli_is_lower(uplo_p))
			{
				m_transfer = bli_max (m_p, n_p - diagoff_p);
				n_transfer = bli_max(m_p, bli_min (n_p, m_p + diagoff_p ));
				if (offm_a + m_transfer > m_root)
					m_transfer = m_root - offm_a;
			}
			else if (bli_is_upper(uplo_p))
			{
				m_transfer = bli_max(m_p, m_p + diagoff_p);
				n_transfer = bli_max(m_p, bli_min (n_p, n_p - diagoff_p ));

				if (offn_a + n_transfer > n_root)
					n_transfer = n_root - offn_a;
			}
		}
	}

	//If source is column major
	if( bli_is_col_stored( rs_source, cs_source ) )
	{
		//If the source is stored in column major, then the number of iterations of
		// memcpy will equal to the number of columns, because each column will be copied
		// at once in each iteration.
		//num_iter  = bli_obj_width(*a);
		num_iter  = n_transfer;

		// the source.buffer is a void pointer. Hence, when jumping to the next column we
		// have to calculate how many bytes and not elements the pointer needs to move
		// to get to the next column
		ld_source = cs_source * elem_size;
		ld_dest   = cs_dest * elem_size;

		// for column-major, each column will be moved at a time.
		// Therefore, the number of bytes to be moved will be
		// equal to the number of rows in each column multiplied
		// by the size of each element.
		//elem_move = bli_obj_length(*a) * elem_size;

		// equal to the column stride of the destination. (In case
		// of symmetric or Hermitian matrices we may be transferring more rows
		// than the length of the destination.
		elem_move = cs_dest * elem_size;


	}
	//if source is row-major stored
	else if( bli_is_row_stored( rs_source, cs_source ) )
	{
		//If the source is stored in row major, then the number of iterations of
		// memcpy will equal to the number of rows, because each row will be copied
		// at once in each iteration.
		//num_iter = bli_obj_length(*a);
		num_iter = m_transfer;

		// the source.buffer is a void pointer. Hence, when jumping to the next row we
		// have to calculate how many bytes and not elements the pointer needs to move
		// to get to the next row
		ld_source = rs_source * elem_size;
		ld_dest   = rs_dest * elem_size;

		// for row-major, each row will be moved at a time.
		// Therefore, the number of bytes to be moved will be
		// equal to the number of columns in each row multiplied
		// by the size of each element.
		//elem_move = bli_obj_width(*a) * elem_size;

		// equal to the row stride of the destination. (In case
		// of symmetric or Hermitian matrices we may be transferring more rows
		// than the length of the destination.)
		elem_move = rs_dest * elem_size;

	}

	offm_p     = bli_obj_row_offset( *p );
	offn_p     = bli_obj_col_offset( *p );


	ptr_source = bli_obj_buffer_at_off( *a );
	ptr_dest = bli_obj_buffer_at_off( *p );

	//printf("prt_s %x ptr_dest %x offm_p %d offn_p %d \n", ptr_source, ptr_dest, offm_p, offn_p );
	//printf("num_iter = %d, elem_move = %d, m_trans = %d, n_trans = %d", num_iter, elem_move, m_transfer, n_transfer);

	if(offm_p != 0 || offn_p != 0)
	{
		ptr_source = (void *) (( char* ) ptr_source - ( dim_t ) elem_size * ( offn_p * cs_source + offm_p * rs_source));
		ptr_dest = (void *) (( char* ) ptr_dest - ( dim_t ) elem_size * ( offn_p * cs_dest + offm_p * rs_dest));

	}

#ifdef BLIS_ENABLE_CYCLE_COUNT
	lib_clock_enable();
	counter_start = lib_clock_read();
	counter_end = lib_clock_read();
	printf("Cache invalidate %d \n", counter_end-counter_start);
#endif

	if(thread->work_id == 0)
	{
		// ld_source is already in terms of bytes
		if(ld_source < BLIS_C66X_MAXDMASTRIDE && p->emt_handle != NULL)
		{
			int status = -100;
#ifdef BLIS_ENABLE_CYCLE_COUNT
			lib_clock_enable();
			counter_start = lib_clock_read();
#endif
			// The destination object contains the EDMA handle
			status = lib_emt_copy2D2D	(	p->emt_handle,
					ptr_source,
					ptr_dest,
					elem_move,
					num_iter,
					ld_source,
					ld_dest
			);
#ifdef BLIS_ENABLE_CYCLE_COUNT
			counter_end = lib_clock_read();
			printf("DMA start %d \n", counter_end-counter_start);
#endif


			if(status != LIB_EMT_SUCCESS)
				printf("DMA Transfer Error %d \n",status);
		}
		else // cannot use DMA since stride is only 16 bit signed
		{
			for(iter = 0; iter < num_iter; iter++)
			{
				memcpy(ptr_dest, ptr_source, elem_move);

				ptr_source = (void *) ( (char *) ptr_source + ld_source);
				ptr_dest   = (void *) ( (char *) ptr_dest + ld_dest);
			}

		}
	}
}

void bli_dmam_wait(obj_t* p, dmam_t* cntl, dmam_thrinfo_t* thread )
{
	if ( cntl_is_noop( cntl ) )
	{
		return;
	}

	// Wait only if current thread work ID is zero
	if(thread->work_id == 0)
	{
		lib_emt_wait(p->emt_handle);
	}
}

void bli_obj_release_emt_handle( obj_t* p)
{
	if ( p->emt_handle != NULL )
	{
		bli_dma_channel_release(p->emt_handle, lib_get_coreID());
		p->emt_handle = NULL;
	}
}

void bli_dma_finalize(void)
{
	_Pragma( "omp parallel num_threads(BLIS_MAX_NUM_THREADS)" )
	{
	dim_t i;
	dma_t* dma_pool;
	lib_emt_Handle* emt_handle;

	//Create omp threads
	dma_pool = &dma_pools[lib_get_coreID()];
	emt_handle = dma_pool->emt_handle;
	for(i = 0; i < BLIS_C66X_EDMA_MAX_NUM_CHANNELS; i ++)
	{
		if( emt_handle[i] != NULL)
		{
			if(lib_emt_free( emt_handle[i] ) == LIB_EMT_ERROR_FREE)
			{
				printf("ERROR: emt_free\n");
			}
			else
				emt_handle[i] = NULL;
		}
	}
	}
}
#endif
