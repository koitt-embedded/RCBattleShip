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
#ifndef _LIBARCH_MEMMGT_H
#define _LIBARCH_MEMMGT_H

#include <stdlib.h>

/** @defgroup libarch_memmgt Memory Management API
 *  @{
 */
/** @} */

/** @addtogroup libarch_memmgt
 *  @brief Error return codes of memory management functions.
 *  @{
 */
/*@{*/
#define LIB_MEMMGT_SUCCESS          (0)   /**< Success. No error.            */
#define LIB_MEMMGT_ERROR            (-1)  /**< Failure.                      */ 
/*@}*/
/** @} */

/** 
  * @ingroup libarch_memmgt
  * @brief Memory types in terms of speed and volatility
  */
enum {
    LIB_SMEM_VFAST = 0, /**< Scratch memory, very fast       */
    LIB_SMEM_FAST,      /**< Scratch memory, fast            */
    LIB_SMEM_MED,       /**< Scratch memory, medium speed    */
    LIB_SMEM_SLOW,      /**< Scratch memory, slow            */
    LIB_PMEM_MED,       /**< Permanent memory, medium speed  */
    LIB_PMEM_SLOW,      /**< Permanent memory, slow          */
    LIB_MEMTYPE_N       /**< Total number of types           */
};

/**
 * @ingroup libarch_memmgt
 * @brief Memory descriptor structure
 *
 * @remarks  The user MUST define an array of memory descriptors and pass the 
 *   address of the array to the heap initialization and allocation routines. 
 *   For example, the memory descriptor array may be defined as:
 * @verbatim
       lib_memdscr_t libxyz_smem_med;
       lib_memdscr_t libxyz_smem_fast;
       lib_memdscr_t libxyz_smem_vfast;
       
       lib_memdscr_t * libxyz_memdscr_tab[LIB_MEMTYPE_N] = {
         &libxyz_smem_vfast,
         &libxyz_smem_fast,
         &libxyz_smem_med,
         NULL                // scratch slow memory is not used by libxyz 
       };
    \endverbatim
 *
 */
typedef struct lib_memdscr_str {
  void   *base;      /**< base address of the heap     */
  size_t  size;      /**< heap size in number of bytes */
  size_t  used;      /**< used size in number of bytes */
} lib_memdscr_t;

/**
 *  @ingroup libarch_memmgt
 *  @brief   Function lib_smem_vinit performs necessary initialization for the
 *           very fast scratch heap memory allocation.
 *
 *  @param[in]  handle  Pointer to the memory descriptor array
 *  @param[in]  base    Base address of the memory to be used as very fast scratch
 *  @param[in]  size    Size of the memory in bytes
 *
 *  @retval     LIB_MEMMGT_SUCCESS  @copydoc LIB_MEMMGT_SUCCESS
 *  @retval     LIB_MEMMGT_ERROR    @copydoc LIB_MEMMGT_ERROR
 */
int lib_smem_vinit  (void *handle, void *base, size_t size); 

/**
 *  @ingroup libarch_memmgt
 *  @brief   Function lib_smem_finit performs necessary initialization for the 
 *           fast scratch heap memory allocation.
 *
 *  @param[in]  handle  Pointer to the memory descriptor array
 *  @param[in]  base    Base address of the memory to be used as fast scratch
 *  @param[in]  size    Size of the memory in bytes
 *
 *  @retval     LIB_MEMMGT_SUCCESS  @copydoc LIB_MEMMGT_SUCCESS
 *  @retval     LIB_MEMMGT_ERROR    @copydoc LIB_MEMMGT_ERROR
 */
int lib_smem_finit  (void *handle, void *base, size_t size); 

/**
 *  @ingroup libarch_memmgt
 *  @brief   Function lib_smem_minit performs necessary initialization for the 
 *           medium speed scratch heap memory allocation.
 *
 *  @param[in]  handle  Pointer to the memory descriptor array
 *  @param[in]  base    Base address of the memory to be used as medium scratch
 *  @param[in]  size    Size of the memory in bytes
 *
 *  @retval     LIB_MEMMGT_SUCCESS  @copydoc LIB_MEMMGT_SUCCESS
 *  @retval     LIB_MEMMGT_ERROR    @copydoc LIB_MEMMGT_ERROR
 */
int lib_smem_minit  (void *handle, void *base, size_t size); 

/**
 *  @ingroup libarch_memmgt
 *  @brief   Function lib_smem_sinit performs necessary initialization for the 
 *           slow scratch heap memory allocation.
 *
 *  @param[in]  handle  Pointer to the memory descriptor array
 *  @param[in]  base    Base address of the memory to be used as slow scratch
 *  @param[in]  size    Size of the memory in bytes
 *
 *  @retval     LIB_MEMMGT_SUCCESS  @copydoc LIB_MEMMGT_SUCCESS
 *  @retval     LIB_MEMMGT_ERROR    @copydoc LIB_MEMMGT_ERROR
 */
int lib_smem_sinit  (void *handle, void *base, size_t size); 

/**
 *  @ingroup libarch_memmgt
 *  @brief   Function lib_smem_valloc allocates a memory block from the very 
 *           fast scratch heap. It will also align the allocated memory block 
 *           as requested.  
 *
 *  @param[in]  handle  Pointer to the memory descriptor array
 *  @param[in]  size    Size of memory block to be allocated 
 *  @param[in]  align   Alignment. The address of the allocated memory block will
 *                      be aligned to 2^align bytes. 
 *
 *  @retval    Non-NULL   Address of the allocated memory block
 *  @retval    NULL       Failure to allocate memory
 *
 *  @pre       Function lib_smem_vinit must be called first before this function
 *             can be used to allocate memory.
 */
void *lib_smem_valloc (void *handle, size_t size, size_t align);

/**
 *  @ingroup libarch_memmgt
 *  @brief   Function lib_smem_falloc allocates a memory block from the 
 *           fast scratch heap. It will also align the address of the allocated 
 *           memory block as requested.  
 *
 *  @param[in]  handle  Pointer to the memory descriptor array defined by the 
 *                      library using this funciton
 *  @param[in]  size    Size of memory block to be allocated 
 *  @param[in]  align   Alignment. The address of the allocated memory block will
 *                      be aligned to 2^align bytes. 
 *
 *  @retval    Non-NULL   Address of the allocated memory block
 *  @retval    NULL       Failure to allocate memory
 *
 *  @pre       Function lib_smem_finit must be called first before this function
 *             can be used to allocate memory.
 */
void *lib_smem_falloc (void *handle, size_t size, size_t align);

/**
 *  @ingroup libarch_memmgt
 *  @brief   Function lib_smem_malloc allocates a memory block from the medium 
 *           speed scratch heap. It will also align the address of the allocated 
 *           memory block as requested.  
 *
 *  @param[in]  handle  Pointer to the memory descriptor array defined by the 
 *                      library using this funciton
 *  @param[in]  size    Size of memory block to be allocated 
 *  @param[in]  align   Alignment. The address of the allocated memory block will
 *                      be aligned to 2^align bytes. 
 *
 *  @retval    Non-NULL   Address of the allocated memory block
 *  @retval    NULL       Failure to allocate memory
 *
 *  @pre       Function lib_smem_minit must be called first before this function
 *             can be used to allocate memory.
 */
void *lib_smem_malloc (void *handle, size_t size, size_t align);

/**
 *  @ingroup libarch_memmgt
 *  @brief   Function lib_smem_salloc allocates a memory block from the slow 
 *           scratch heap. It will also align the address of the allocated 
 *           memory block as requested.  
 *
 *  @param[in]  handle  Pointer to the memory descriptor array defined by the 
 *                      library using this funciton
 *  @param[in]  size    Size of memory block to be allocated 
 *  @param[in]  align   Alignment. The address of the allocated memory block will
 *                      be aligned to 2^align bytes. 
 *
 *  @retval    Non-NULL   Address of the allocated memory block
 *  @retval    NULL       Failure to allocate memory
 *
 *  @pre       Function lib_smem_sinit must be called first before this function
 *             can be used to allocate memory.
 */
void *lib_smem_salloc (void *handle, size_t size, size_t align);

/**
 *  @ingroup libarch_memmgt
 *  @brief   Function lib_smem_vreset resets the very fast scratch heap and 
 *           destroys all allocated memory blocks in it.  
 *
 *  @param[in]  handle  Pointer to the memory descriptor array defined by the 
 *                      library using this funciton
 *
 *  @retval    LIB_MEMMGT_SUCCESS  @copydoc LIB_MEMMGT_SUCCESS
 *  @retval    LIB_MEMMGT_ERROR    @copydoc LIB_MEMMGT_ERROR
 *
 *  @pre       Function lib_smem_vinit must be called first before this function
 *             can be called.
 */
int lib_smem_vreset (void *handle);

/**
 *  @ingroup libarch_memmgt
 *  @brief   Function lib_smem_freset resets the fast scratch heap and destroys 
 *           all allocated memory blocks in it.  
 *
 *  @param[in]  handle  Pointer to the memory descriptor array defined by the 
 *                      library using this funciton
 *
 *  @retval    LIB_MEMMGT_SUCCESS  @copydoc LIB_MEMMGT_SUCCESS
 *  @retval    LIB_MEMMGT_ERROR    @copydoc LIB_MEMMGT_ERROR
 *
 *  @pre       Function lib_smem_finit must be called first before this function
 *             can be called.
 */
int lib_smem_freset (void *handle);

/**
 *  @ingroup libarch_memmgt
 *  @brief   Function lib_smem_mreset resets the medium speed scratch heap and 
 *           destroys all allocated memory blocks in it.  
 *
 *  @param[in]  handle  Pointer to the memory descriptor array defined by the 
 *                      library using this funciton
 *
 *  @retval    LIB_MEMMGT_SUCCESS  @copydoc LIB_MEMMGT_SUCCESS
 *  @retval    LIB_MEMMGT_ERROR    @copydoc LIB_MEMMGT_ERROR
 *
 *  @pre       Function lib_smem_minit must be called first before this function
 *             can be called.
 */
int lib_smem_mreset (void *handle);

/**
 *  @ingroup libarch_memmgt
 *  @brief   Function lib_smem_mreset resets the slow scratch heap and 
 *           destroys all allocated memory blocks in it.  
 *
 *  @param[in]  handle  Pointer to the memory descriptor array defined by the 
 *                      library using this funciton
 *
 *  @retval    LIB_MEMMGT_SUCCESS  @copydoc LIB_MEMMGT_SUCCESS
 *  @retval    LIB_MEMMGT_ERROR    @copydoc LIB_MEMMGT_ERROR
 *
 *  @pre       Function lib_smem_sinit must be called first before this function
 *             can be called.
 */
int lib_smem_sreset (void *handle);

/**
 *  @ingroup libarch_memmgt
 *  @brief   Function lib_pmem_malloc allocates a memory block from the medium 
 *           speed permanent heap. It will also align the address of the allocated 
 *           memory block as requested.  
 *
 *  @remark  In this release, this function simply calls run time support library 
 *           function memalign(). 
 *
 *  @param[in]  handle  Pointer to the memory descriptor array defined by the 
 *                      library using this funciton
 *  @param[in]  size    Size of memory block to be allocated 
 *  @param[in]  align   Alignment. The address of the allocated memory block will
 *                      be aligned to 2^align bytes. 
 *
 *  @retval    Non-NULL   Address of the allocated memory block
 *  @retval    NULL       Failure to allocate memory
 *
 */
static inline void *lib_pmem_malloc (void *handle, size_t size, size_t align)
{
    return(memalign(align, size));
}

/**
 *  @ingroup libarch_memmgt
 *  @brief   Function lib_pmem_salloc allocates a memory block from the slow 
 *           permanent heap. It will also align the address of the allocated 
 *           memory block as requested.  
 *
 *  @remark  In this release, this function simply calls run time support library 
 *           function memalign(). 
 *
 *  @param[in]  handle  Pointer to the memory descriptor array defined by the 
 *                      library using this funciton
 *  @param[in]  size    Size of memory block to be allocated 
 *  @param[in]  align   Alignment. The address of the allocated memory block will
 *                      be aligned to 2^align bytes. 
 *
 *  @retval    Non-NULL   Address of the allocated memory block
 *  @retval    NULL       Failure to allocate memory
 *
 */
static inline void *lib_pmem_salloc (void *handle, size_t size, size_t align)
{
    return(memalign(align, size));
}

/**
 *  @ingroup libarch_memmgt
 *  @brief Refer to lib_memmgt.h for detailed documentation.
 *
 *  @remark  In this release, this function simply calls run time support library 
 *           function free(). 
 *
 *  @param[in]  handle  Pointer to the memory descriptor array defined by the 
 *                      library using this funciton
 *  @param[in]  mem_ptr Pointer to the memory to be freed
 *
 */
static inline void lib_pmem_mfree (void *handle, void *mem_ptr)
{
  free(mem_ptr);
}

/**
 *  @ingroup libarch_memmgt
 *  @brief Refer to lib_memmgt.h for detailed documentation.
 *
 *  @remark  In this release, this function simply calls run time support library 
 *           function free(). 
 *
 *  @param[in]  handle  Pointer to the memory descriptor array defined by the 
 *                      library using this funciton
 *  @param[in]  mem_ptr Pointer to the memory to be freed
 *
 */
static inline void lib_pmem_sfree (void *handle, void *mem_ptr)
{
  free(mem_ptr);
}

#endif  /* _LIBARCH_MEMMGT_H */

/* nothing past this point */
