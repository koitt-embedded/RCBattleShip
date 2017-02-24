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
 * \file tomp_memory.c
 * 
 * \brief Thread safe, coherency aware dynamic memory management routines. 
 *
 */

#include <stdlib.h>
#include <string.h>
#include "tomp_dsp_heap_api.h"
#include "tomp_util.h"

/*---------------------------------------------------------------------------*/
/* _SYSMEM_SIZE is a symbol whose *address* is set by the linker to the      */
/* size of the heap, via the -heap flag.                                     */
/*---------------------------------------------------------------------------*/

extern _DATA_ACCESS int __TI_SYSMEM_SIZE;         /* address = size of heap */
 
/*---------------------------------------------------------------------------*/
/* Size of the heap area as defined by the linker.                           */
/*---------------------------------------------------------------------------*/
static _DATA_ACCESS int _memory_size = (int)&__TI_SYSMEM_SIZE;
 
/*---------------------------------------------------------------------------*/
/* Define the heap memory area.  Note that allocated space is actually       */
/* (re)allocated in the linker.  The object must appear in the ".sysmem"     */
/* data section, and it must be aligned properly.                            */
/*---------------------------------------------------------------------------*/
/* Autoinitialize the first packet to indicate a single heap packet whose    */
/* size is equal to the total heap minus the size of the header (a PACKET).  */
/* This is equivalent to calling minit() at boot time.                       */
/*---------------------------------------------------------------------------*/
#pragma DATA_SECTION(_sys_memory, ".sysmem")
#pragma DATA_ALIGN(_sys_memory, 8)
far char _sys_memory[1];

#pragma DATA_SECTION (need_mem_init, ".tomp_svNcMem")
far int need_mem_init = 1;
 

/*---------------------------------------------------------------------------*/
/* Index of the heap configured and used in bare metal mode                  */
/*---------------------------------------------------------------------------*/
#define HEAP_IDX    (0)

/*****************************************************************************/
/*									     */
/*  MINIT - Initialize the memory management system.                         */
/*									     */
/*****************************************************************************/
_CODE_ACCESS void _minit(void)
{
    acquire_dsp_heap_lock();

    if (!need_mem_init) 
    { 
        release_dsp_heap_lock();
        return;
    }

    tomp_dsp_heap_init(HEAP_IDX, (char *)_sys_memory, _memory_size);
    need_mem_init = 0;

    release_dsp_heap_lock();
}

/*****************************************************************************/
/*									     */
/*  MALLOC - Allocate a packet of a given size, and return a pointer to it.  */
/*	     This function only allocates in multiples of MIN_BLOCK bytes.   */
/*									     */
/*****************************************************************************/
_CODE_ACCESS void *malloc(size_t size)
{
    _minit();
    return __ti_dsp_malloc(HEAP_IDX, size);
}

/*****************************************************************************/
/*									     */
/*  CALLOC - Allocate a packet of a given size, set the data in the packet   */
/*	     to nulls, and return a pointer to it.			     */
/*									     */
/*****************************************************************************/
_CODE_ACCESS void *calloc(size_t num, size_t size)
{
    _minit();
    return __ti_dsp_calloc(HEAP_IDX, num, size);
}

/*****************************************************************************/
/*									     */
/*  REALLOC - Reallocate a packet to a new size.			     */
/*									     */
/*****************************************************************************/
_CODE_ACCESS void *realloc(void *packet, size_t size)
{
    return __ti_dsp_realloc(HEAP_IDX, packet, size);
}

/*****************************************************************************/
/*									     */
/*  FREE - Return a packet allocated by malloc to free memory pool.	     */
/*	   Return 0 if successful, -1 if not successful.		     */
/*									     */
/*****************************************************************************/
_CODE_ACCESS void free(void *packet)
{
    __ti_dsp_free(HEAP_IDX, packet);
    return;
}

/*****************************************************************************/
/*                                                                           */
/*  MEMALIGN - Allocate a packet of a given size, and on a given boundary.   */
/*                                                                           */
/*****************************************************************************/
_CODE_ACCESS void *memalign(size_t alignment, size_t size)
{
    _minit();
    return __ti_dsp_memalign(HEAP_IDX, alignment, size);
}


