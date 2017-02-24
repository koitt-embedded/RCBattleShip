/******************************************************************************
 * Copyright (c) 2015, Texas Instruments Incorporated - http://www.ti.com
 *   All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions are met:
 *       * Redistributions of source code must retain the above copyright
 *         notice, this list of conditions and the following disclaimer.
 *       * Redistributions in binary form must reproduce the above copyright
 *         notice, this list of conditions and the following disclaimer in the
 *         documentation and/or other materials provided with the distribution.
 *       * Neither the name of Texas Instruments Incorporated nor the
 *         names of its contributors may be used to endorse or promote products
 *         derived from this software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 *   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 *   THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/
#include <xdc/std.h>
#include "lib_memmgt.h"

/**
 *  @brief Macro to align an address to power of 2
 */
#define lib_align(addr, algn) ( ((unsigned int)(addr)+(unsigned int)(algn)-1) \
                                &(~((unsigned int)(algn)-1)) )

/**
 *  @brief Initialization for a given memory handle and memory type
 */
static int lib_smem_init(void *handle, int mem_type, void *base, size_t size)
{
  lib_memdscr_t **dscrs; 
  lib_memdscr_t  *memdscr; 
  
  if (handle == NULL) {
    return (LIB_MEMMGT_ERROR);        /* invalid heap descriptor array */
  }
  
  dscrs = (lib_memdscr_t **)handle;   /* heap descriptor array */
  memdscr = dscrs[mem_type];           /* get heap descriptor   */
  if (memdscr == NULL) {
    return (LIB_MEMMGT_ERROR);        /* invalid heap descriptor */
  }  

  /* Initialize heap descriptor */
  memdscr->base = base;
  memdscr->size = size;
  memdscr->used = 0;      /* mark it as an empty heap */

  return (LIB_MEMMGT_SUCCESS);
}

/**
 *  @brief Memory block allocation for a given memory handle and memory type
 */
static void *lib_smem_alloc(void *handle, int mem_type, size_t size, size_t align)
{
  lib_memdscr_t **dscrs; 
  lib_memdscr_t  *memdscr; 
  char *ptr_avail, *ptr_align;
  ptrdiff_t used_size_after_align;
  
  if (handle == NULL) {
    return (NULL);                     /* invalid heap descriptor array */
  }
  
  dscrs = (lib_memdscr_t **)handle;   /* heap descriptor array */
  memdscr = dscrs[mem_type];           /* get heap descriptor   */
  if (memdscr == NULL) {
    return (NULL);                     /* invalid heap descriptor */
  }  
  
  if (memdscr->base == NULL) {         /* invalid heap */
    return(NULL);
  }
  
  ptr_avail = (char *)memdscr->base + memdscr->used;  /* ptr to available memory  */
  
  ptr_align = (char *)lib_align(ptr_avail, align);   /* align available memory address */

  /* Check if there is enough memory in the heap for this allocation request */
  used_size_after_align = ptr_align - (char *)memdscr->base;
  if((size_t)(used_size_after_align+size) > memdscr->size) {
    /* There is no enough memory */
    return(NULL);
  }
  
  /* There is enough memory to allocate - update used size in the heap */
  memdscr->used += (size_t)(ptr_align-ptr_avail)+size; /*  */
  
  return((void *)ptr_align); /* return the aligned memory address */
}

/**
 *  @brief Reset for a given memory handle and memory type
 */
static int lib_smem_reset (void *handle, int mem_type)
{
  lib_memdscr_t **dscrs; 
  lib_memdscr_t  *memdscr; 
  
  if (handle == NULL) {
    return (LIB_MEMMGT_ERROR);        /* invalid heap descriptor array */
  }
  
  dscrs = (lib_memdscr_t **)handle;   /* heap descriptor array */
  memdscr = dscrs[mem_type];          /* get heap descriptor   */
  if (memdscr == NULL) {
    return (LIB_MEMMGT_ERROR);        /* invalid heap descriptor */
  }  

  memdscr->used = 0;                  /* mark it as an empty heap */
  
  return (LIB_MEMMGT_SUCCESS);
}

/**
 * @brief Refer to lib_memmgt.h for detailed documentation.
 */
int lib_smem_vinit (void *handle, void *base, size_t size) 
{
  return lib_smem_init(handle, LIB_SMEM_VFAST, base, size);
}

/**
 * @brief Refer to lib_memmgt.h for detailed documentation.
 */
int lib_smem_finit (void *handle, void *base, size_t size) 
{
  return lib_smem_init(handle, LIB_SMEM_FAST, base, size);
}

/**
 * @brief Refer to lib_memmgt.h for detailed documentation.
 */
int lib_smem_minit (void *handle, void *base, size_t size) 
{
  return lib_smem_init(handle, LIB_SMEM_MED, base, size);
}

/**
 * @brief Refer to lib_memmgt.h for detailed documentation.
 */
int lib_smem_sinit (void *handle, void *base, size_t size) 
{
  return lib_smem_init(handle, LIB_SMEM_SLOW, base, size);
}

/**
 * @brief Refer to lib_memmgt.h for detailed documentation.
 */
void *lib_smem_valloc (void *handle, size_t size, size_t align)
{
  return lib_smem_alloc(handle, LIB_SMEM_VFAST, size, align);
}

/**
 * @brief Refer to lib_memmgt.h for detailed documentation.
 */
void *lib_smem_falloc (void *handle, size_t size, size_t align)
{
  return lib_smem_alloc(handle, LIB_SMEM_FAST, size, align);
}

/**
 * @brief Refer to lib_memmgt.h for detailed documentation.
 */
void *lib_smem_malloc (void *handle, size_t size, size_t align)
{
  return lib_smem_alloc(handle, LIB_SMEM_MED, size, align);
}

/**
 * @brief Refer to lib_memmgt.h for detailed documentation.
 */
void *lib_smem_salloc (void *handle, size_t size, size_t align)
{
  return lib_smem_alloc(handle, LIB_SMEM_SLOW, size, align);
}

/**
 * @brief Refer to lib_memmgt.h for detailed documentation.
 */
int lib_smem_vreset (void *handle)
{
  return lib_smem_reset(handle, LIB_SMEM_VFAST);
}

/**
 * @brief Refer to lib_memmgt.h for detailed documentation.
 */
int lib_smem_freset (void *handle)
{
  return lib_smem_reset(handle, LIB_SMEM_FAST);
}

/**
 * @brief Refer to lib_memmgt.h for detailed documentation.
 */
int lib_smem_mreset (void *handle)
{
  return lib_smem_reset(handle, LIB_SMEM_MED);
}

/**
 * @brief Refer to lib_memmgt.h for detailed documentation.
 */
int lib_smem_sreset (void *handle)
{
  return lib_smem_reset(handle, LIB_SMEM_SLOW);
}

/* nothing past this point */
