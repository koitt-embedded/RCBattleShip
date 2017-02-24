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

#ifndef BLIS_DMA_H
#define BLIS_DMA_H


int ti_printf(FILE *_fp, const char *_format, ...);
int ti_sprintf(char *str, const char *_format, ...);


/*
 * EDMA Pool
 */
struct dma_s
{
    bool_t emt_status;
    void** emt_handle;
    dim_t num_channels;
    dim_t top_index;
};
typedef struct dma_s dma_t;

/*
 * Control Leaf for DMA
 */
struct dmam_s
{
	impl_t         impl_type;
	varnum_t       var_num;
	blksz_t*       mc;
	blksz_t*       nc;
	membuf_t       dma_buf_type; //target level buffer
};
typedef struct dmam_s dmam_t;

/*
 * Thread info for DMA
 */
struct dmam_thrinfo_s //implements thrinfo_t
{
    thread_comm_t*      ocomm;       //The thread communicator for the other threads sharing the same work at this level
    dim_t               ocomm_id;    //Our thread id within that thread comm
    thread_comm_t*      icomm;       //The thread communicator for the other threads sharing the same work at this level
    dim_t               icomm_id;    //Our thread id within that thread comm

    dim_t               n_way;       //Number of distinct caucuses used to parallelize the loop
    dim_t               work_id;     //What we're working on
};
typedef struct dmam_thrinfo_s dmam_thrinfo_t;

dmam_t* bli_dmam_cntl_obj_create( impl_t     impl_type,
                                  varnum_t   var_num,
                                  blksz_t*   mc,
                                  blksz_t*   nc,
                                  membuf_t  pack_buf_type );

#define bli_obj_alias_for_dma( a, b ) \
{ \
	bli_obj_init_basic_shallow_copy_of( a, b ); \
	\
		/*(b).pack_mem  = (a).pack_mem; \
		(b).m_padded  = (a).m_padded; \
		(b).n_padded  = (a).n_padded; \
		(b).ps        = (a).ps; \
		(b).pd        = (a).pd; */\
}

#define bli_obj_dma_mem( obj ) \
\
	( &((obj).dma_mem) )

#define bli_obj_emt_handle( obj ) \
\
	( &((obj).emt_handle) )

#define bli_emt_handle_set_NULL(obj) \
{	\
	(obj).emt_handle = NULL; \
}

#define bli_obj_alias_with_dma(a, b) \
{ \
     bli_obj_alias_to( a, b ); \
     &((b).emt_handle) = &((a).emt_handle); \
}

#define bli_obj_init_dma( obj_p ) \
{ \
	mem_t* pack_mem = bli_obj_pack_mem( *obj_p ); \
	mem_t* dma_mem = bli_obj_dma_mem( *obj_p ); \
\
	bli_mem_set_buffer( NULL, pack_mem ); \
	bli_mem_set_buffer( NULL, dma_mem ); \
	bli_emt_handle_set_NULL( *obj_p ); \
}
//#define bli_obj_init_dma( obj_p ) \
//{ \
//	mem_t* dma_mem = bli_obj_dma_mem( *obj_p ); \
//\
//	bli_mem_set_buffer( NULL, dma_mem ); \
//}



#define cntl_sub_dmam_b( cntl )       cntl->sub_dmam_b
#define cntl_sub_dmam_a( cntl )       cntl->sub_dmam_a
#define cntl_sub_dmam_c( cntl )       cntl->sub_dmam_c

#define bli_obj_release_dma( obj_p , cntl ) \
{ \
	mem_t* dma_mem = bli_obj_dma_mem( *(obj_p) ); \
	if ( bli_mem_is_alloc( dma_mem ) && cntl != NULL ) \
		bli_mem_release( dma_mem ); \
}

// Functions to initialize the EDMA and EDMA channels
void bli_dma_init (void);
void bli_dma_init_pool(gint_t emt_status,
	                   gint_t num_channels,
	                   lib_emt_Handle* pool_emt_handles,
	                   dma_t * dma_pool);

void bli_dma_channel_acquire(lib_emt_Handle* emt_handle, dim_t core_id);
void bli_dma_channel_release(lib_emt_Handle emt_handle, dim_t core_id);

void bli_dmam_wait(obj_t* p, dmam_t* cntl, dmam_thrinfo_t* thread);
void bli_obj_release_emt_handle(obj_t* p);

void bli_dma_finalize(void);

/*
 * Checks the parameters, and initializes the destination obj_t with parameters from the source, and allocate
 * memory for the destination buffer.
 */
void bli_dmam_init( obj_t*   a,
                    obj_t*   p,
                    dmam_t* cntl);

void bli_dmam_init_check(obj_t*   a,
                         obj_t*   p,
                         dmam_t* cntl);

void bli_dmam_int( obj_t*   a,
                   obj_t*   p,
                   dmam_t* cntl,
                   dmam_thrinfo_t* thread );

void bli_dma_var1( obj_t*   a,
                   obj_t*   p,
                   dmam_thrinfo_t* thread );



#endif //BLIS_DMA_H
