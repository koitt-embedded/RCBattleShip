/*
 * Copyright (c) 2014, Texas Instruments Incorporated - http://www.ti.com/
 *   All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *      * Redistributions of source code must retain the above copyright
 *        notice, this list of conditions and the following disclaimer.
 *      * Redistributions in binary form must reproduce the above copyright
 *        notice, this list of conditions and the following disclaimer in the
 *        documentation and/or other materials provided with the distribution.
 *      * Neither the name of Texas Instruments Incorporated nor the
 *        names of its contributors may be used to endorse or promote products
 *        derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE.
 */
/**
 * \file tomp_shared_heap.c
 * 
 * \brief Wrapper functions for heaps in DDR and MSMC.                     
 *
 */

#include <stdlib.h>
#include "tomp_dsp_heap_api.h"
#include "omp.h"

/*---------------------------------------------------------------------------*/
/* Index of the heap configured and used in bare metal mode                  */
/*---------------------------------------------------------------------------*/
#define DDR_HEAP_IDX     (1)
#define MSMC_HEAP_IDX    (2)

far void __heap_init_ddr(void *ptr, size_t size)
{ __ti_dsp_heap_init(DDR_HEAP_IDX, ptr, size); }

far void *__malloc_ddr(size_t size)
{ return __ti_dsp_malloc(DDR_HEAP_IDX, size); }

far void *__calloc_ddr(size_t num, size_t size)
{ return __ti_dsp_calloc(DDR_HEAP_IDX, num, size); }

far void *__realloc_ddr(void *packet, size_t size)
{ return __ti_dsp_realloc(DDR_HEAP_IDX, packet, size); } 

far void __free_ddr(void *packet)
{ __ti_dsp_free(DDR_HEAP_IDX, packet); }

far void *__memalign_ddr(size_t alignment, size_t size)
{ return __ti_dsp_memalign(DDR_HEAP_IDX, alignment, size); }


far void __heap_init_msmc(void *ptr, size_t size)
{ __ti_dsp_heap_init(MSMC_HEAP_IDX, ptr, size); }

far void *__malloc_msmc(size_t size)
{ return __ti_dsp_malloc(MSMC_HEAP_IDX, size); }

far void *__calloc_msmc(size_t num, size_t size)
{ return __ti_dsp_calloc(MSMC_HEAP_IDX, num, size); }

far void *__realloc_msmc(void *packet, size_t size)
{ return __ti_dsp_realloc(MSMC_HEAP_IDX, packet, size); }

far void __free_msmc(void *packet)
{ __ti_dsp_free(MSMC_HEAP_IDX, packet); }

far void *__memalign_msmc(size_t alignment, size_t size)
{ return __ti_dsp_memalign(MSMC_HEAP_IDX, alignment, size); }


