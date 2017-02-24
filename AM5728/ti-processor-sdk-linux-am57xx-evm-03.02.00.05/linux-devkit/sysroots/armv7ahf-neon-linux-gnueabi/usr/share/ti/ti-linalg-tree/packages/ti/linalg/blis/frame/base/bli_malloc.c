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
#if defined(BLIS_ENABLE_TI_ARM_OPENCL) //|| defined (BLIS_ENABLE_C66X_BUILD)
#include <CL/cl_ext.h>
#endif

/* This function is used to allocate memory during BLIS initialization. 
   Allocated memory will be freed when bli_finalize() is called */
void* bli_malloc( siz_t size )
{
	void* p = NULL;
#if !defined(BLIS_ENABLE_TI_ARM_OPENCL) && !defined(_WIN32) && !defined(BLIS_ENABLE_C66X_BUILD) && (BLIS_HEAP_ADDR_ALIGN_SIZE != 1)
	int   r_val;
#endif

	if ( size == 0 ) return NULL;

#if defined(BLIS_ENABLE_TI_ARM_OPENCL)
	_Pragma( "omp critical (bli_malloc_critical)" )
	{
        p = __malloc_ddr( ( size_t )size );
	}
#elif BLIS_HEAP_ADDR_ALIGN_SIZE == 1
	p = malloc( ( size_t )size );
#elif defined(_WIN32)
	p = _aligned_malloc( ( size_t )size,
	                     ( size_t )BLIS_HEAP_ADDR_ALIGN_SIZE );
#elif defined (BLIS_ENABLE_C66X_BUILD)
	//p = malloc( ( size_t )size );
	/* Use LibArch slow permanent memory allocator */
	p = lib_pmem_salloc(blasGetMemHandle(), size, 0);
#else
	r_val = posix_memalign( &p,
	                        ( size_t )BLIS_HEAP_ADDR_ALIGN_SIZE,
	                        ( size_t )size );

	if ( r_val != 0 ) bli_abort();
#endif

	if ( p == NULL ) bli_abort();

	return p;
}

/* This function is used to allocate memory for kernel computation. 
   The allocated memory will be freed at the end of the computation.
   For TI DSP implementation, LibArch scratch heap allocator will be 
   used to obtain a memory block from a scratch heap that is 
   initialized during BLIS initialization. */
void* bli_malloc_scratch( siz_t size )
{
	void* p = NULL;
#if !defined(BLIS_ENABLE_TI_ARM_OPENCL) && !defined(_WIN32) && !defined(BLIS_ENABLE_C66X_BUILD) && (BLIS_HEAP_ADDR_ALIGN_SIZE != 1)
	int   r_val;
#endif

	if ( size == 0 ) return NULL;

#if defined(BLIS_ENABLE_TI_ARM_OPENCL)
	_Pragma( "omp critical (bli_malloc_critical)" )
	{
        p = __malloc_ddr( ( size_t )size );
	}
#elif BLIS_HEAP_ADDR_ALIGN_SIZE == 1
	p = malloc( ( size_t )size );
#elif defined(_WIN32)
	p = _aligned_malloc( ( size_t )size,
	                     ( size_t )BLIS_HEAP_ADDR_ALIGN_SIZE );
#elif defined (BLIS_ENABLE_C66X_BUILD)
	/* Use LibArch slow scratch memory allocator */
	p = lib_smem_salloc(blasGetMemHandle(), size, 1);
#else
	r_val = posix_memalign( &p,
	                        ( size_t )BLIS_HEAP_ADDR_ALIGN_SIZE,
	                        ( size_t )size );

	if ( r_val != 0 ) bli_abort();
#endif

	if ( p == NULL ) bli_abort();

	return p;
}

#ifdef BLIS_ENABLE_C66X_BUILD
/* This function is used to allocate memory for kernel computation
   with required alignment. */
void* bli_memalign(siz_t alignment,  siz_t size )
{
	void* p = NULL;

	//p = memalign(BLIS_CACHE_LINE_SIZE, ( size_t )size);
	p = lib_pmem_salloc(blasGetMemHandle(), size, BLIS_CACHE_LINE_SIZE);

	if ( p == NULL ) bli_abort();

	return p;
}

/* This function is used to allocate memory for kernel computation
   with required alignment using LibArch scratch heap allocator.  
   A memory block will be obtained from a scratch heap that is 
   initialized during BLIS initialization. */
void* bli_malloc_scratch_align(siz_t alignment,  siz_t size )
{
	void* p = NULL;

	p = lib_smem_salloc(blasGetMemHandle(), size, BLIS_CACHE_LINE_SIZE);

	if ( p == NULL ) bli_abort();

	return p;
}

#endif

/* This function is used to free the memory allocated by bli_malloc. */
void bli_free( void* p )
{
#if defined(BLIS_ENABLE_TI_ARM_OPENCL)
	_Pragma( "omp critical (bli_malloc_critical)" )
	{
		__free_ddr( p );
	}
#elif defined (BLIS_ENABLE_C66X_BUILD)
	//free(p);
    lib_pmem_sfree(blasGetMemHandle(), p);
#elif BLIS_HEAP_ADDR_ALIGN_SIZE == 1 || !defined(_WIN32)
	free( p );
#else
	_aligned_free( p );
#endif
}

/* This function is used to free the memory allocated by bli_malloc_scratch. */
void bli_free_scratch( void* p )
{
#if defined(BLIS_ENABLE_TI_ARM_OPENCL)
	_Pragma( "omp critical (bli_malloc_critical)" )
	{
		__free_ddr( p );
	}
#elif defined (BLIS_ENABLE_C66X_BUILD)
    /* for DSP implementation, freeing scratch heap is not needed. */
	
#elif BLIS_HEAP_ADDR_ALIGN_SIZE == 1 || !defined(_WIN32)
	free( p );
#else
	_aligned_free( p );
#endif
}
