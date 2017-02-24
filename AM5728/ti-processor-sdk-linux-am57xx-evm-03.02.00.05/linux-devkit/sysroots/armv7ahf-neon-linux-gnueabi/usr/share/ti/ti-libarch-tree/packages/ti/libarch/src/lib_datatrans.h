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
#ifndef _LIBARCH_DATA_TRANS_H
#define _LIBARCH_DATA_TRANS_H

#include <ti/sdo/fc/edmamgr/edmamgr.h>
#include <ti/csl/csl_chipAux.h> 
#include <ti/csl/csl_idmaAux.h>
#include "lib_utils.h"

/** @defgroup libarch_memtrans Memory Transfers API
 *  @{
 */
/** @} */

/**
 *  @ingroup libarch_memtrans
 *
 *  @brief Function lib_imt_copy performs internal memory transfers between 
 *         any two memory locations local to the C66x CorePac: L1P, L1D, and L2. 
 *         This function uses IDMA channel 1 to perform the transfer.
 *
 *  @param[in]     src   source address of transfer
 *  @param[in]     dst   destination address of transfer
 *  @param[in]     size  size of transfer in minimum access units
 *
 *  \remark  This function waits for the pending transfer (if any) to become active.
 *           It is a blocking call.
 *  \remark  There is no need to allocate a channel before using this function.
 *  \remark  Both source and destination addresses increment linearly throughout 
 *           the transfer.
 *  \remark  No DSP interrupt is generated after the transfer. Function
 *           lib_imt_wait can be called to wait for transfer completion before
 *           data in destination memory is used. 
 *  \remark  During any conflicts between CPU and DMA accesses, transfer started 
 *           by this function has the lowest priority. 
 */
static inline void lib_imt_copy(const void *src, void *dst, size_t size)
{
  /* use volatile to prevent compiler from optimizing away subsequent reads */
  volatile uint32_t pend;  
  
  /* wait untill there is no pending transfer */
  while( (pend = CSL_FEXT(hIdma->IDMA1_STAT, CGEM_IDMA1_STAT_PEND) ) );
  
  /* hard code the following configuration:
     - Block fill: 0
     - DSP interrupt enable: 0
     - Transfer priority: 7 (lowest)
  */
  hIdma->IDMA1_SOURCE  = (uint32_t)src;
  hIdma->IDMA1_DEST    = (uint32_t)dst; 
  hIdma->IDMA1_COUNT   = CSL_FMK(CGEM_IDMA1_COUNT_PRI,   (uint32_t)7) |
                         CSL_FMK(CGEM_IDMA1_COUNT_INT,   (uint32_t)0) |
                         CSL_FMK(CGEM_IDMA1_COUNT_FILL,  (uint32_t)0) |
                         CSL_FMK(CGEM_IDMA1_COUNT_COUNT, size);
  return;
}

/**
 *  @ingroup libarch_memtrans
 *
 *  @brief Function lib_imt_set fills a block of internal memory, L1P, L1D, or
 *         L2 with a given pattern. 
 *
 *  @param[in]     pattern   Filling pattern
 *  @param[in]     dst       Address of the memory to be filled 
 *  @param[in]     size      size of memory filling in minimum access units
 *
 *  \remark   This function waits for the pending transfer to become active.
 *            It is a blocking call.
 *  \remark   Refer to remarks of lib_imt_copy. 
 */
static inline void lib_imt_set(uint32_t pattern, void *dst, size_t size)
{
  /* use volatile to prevent compiler from optimizing away subsequent reads */
  volatile uint32_t pend;  
  
  /* wait untill there is no pending transfer */
  while( (pend = CSL_FEXT(hIdma->IDMA1_STAT, CGEM_IDMA1_STAT_PEND) ) );
  
  /* hard code the following configuration:
     - Block fill: 1
     - DSP interrupt enable: 0
     - Transfer priority: 7 (lowest)
  */
  hIdma->IDMA1_SOURCE  = pattern;
  hIdma->IDMA1_DEST    = (uint32_t)dst; 
  hIdma->IDMA1_COUNT   = CSL_FMK(CGEM_IDMA1_COUNT_PRI,   (uint32_t)7) |
                         CSL_FMK(CGEM_IDMA1_COUNT_INT,   (uint32_t)0) |
                         CSL_FMK(CGEM_IDMA1_COUNT_FILL,  (uint32_t)1) |
                         CSL_FMK(CGEM_IDMA1_COUNT_COUNT, size);  
  return;
}

/**
 *  @ingroup libarch_memtrans
 *
 *  @brief Function lib_imt_wait waits for completion of transfers started by 
 *         lib_imt_copy or lib_imt_set. 
 *
 *  @remarks    This function waits for both pending and active transfers 
 *              to complete. It is a blocking call.
 */
static inline void lib_imt_wait() 
{
  CSL_IDMA_chan1Wait();
}

/** @addtogroup libarch_memtrans
 *  @{
 *  @brief Return error codes of external memory transfer functions
 */
/*@{*/
#define LIB_EMT_SUCCESS          (0)   /**< Success. No error.               */
#define LIB_EMT_ERROR_INVARG     (-1)  /**< Failure. Invalid argument.       */ 
#define LIB_EMT_ERROR_INVCFG     (-2)  /**< Failure. Invalid configuration.  */ 
#define LIB_EMT_ERROR_RMANINIT   (-3)  /**< Failure. RMAN initialization.    */ 
#define LIB_EMT_ERROR_INVHANDLE  (-4)  /**< Failure. Invalid handle.         */ 
#define LIB_EMT_ERROR_FREE       (-5)  /**< Failure to free a resource.      */
/*@}*/
/** @} */

#define LIB_EMT_MAX_NUM_CHANNELS 32    /**< Maximum number of channels supported 
                                            for external linked transfers.   */

/**
 *  @ingroup libarch_memtrans
 *  @brief Handle to an external memory transfer instance 
 */
typedef void * lib_emt_Handle;      

/**
 *  @ingroup libarch_memtrans
 *  @brief   Configuration for large external memory transfers. 
 *
 *  @remarks This configuration is used by functions lib_emt_getSizesLarge and 
 *           lib_emt_allocLarge to prepare for lib_emt_copy2D1DLarge and 
 *           lib_emt_copy1D2DLarge.
 */
typedef struct lib_emt_ConfigLarge_s
{
  int32_t max_num_lines;   /**< Maximum number of lines which may be transfered 
                                during a large 1D->2D or 2D->1D transfer.    */
} lib_emt_ConfigLarge_t;

/**
 *  @ingroup libarch_memtrans
 *
 *  @brief Function lib_emt_init performs all necessary initialization for 
 *         external memory transfers.
 *
 *  @retval  LIB_EMT_SUCCESS         @copydoc LIB_EMT_SUCCESS
 *  @retval  LIB_EMT_ERROR_INVARG    @copydoc LIB_EMT_ERROR_INVARG
 *  @retval  LIB_EMT_ERROR_INVCFG    @copydoc LIB_EMT_ERROR_INVCFG
 *  @retval  LIB_EMT_ERROR_RMANINIT  @copydoc LIB_EMT_ERROR_RMANINIT
 */
static inline int lib_emt_init()
{
#ifdef LIB_OPENCL 
/* OpenCL monitor calls EdmaMgr_init during initialization prior to any kernels 
   being offloaded to DSP. So kernel code doesn't need to call edmaMgr_init.
*/
  return(LIB_EMT_SUCCESS);
#else
#  ifdef LIB_RTOS
     return(EdmaMgr_init(lib_get_coreID(), NULL));
#  else
#    error "Unsupported OS! Please specify either LIB_OPENCL or LIB_RTOS"
#  endif
#endif
}

/**
 *  @ingroup libarch_memtrans
 *  @brief Function lib_emt_alloc allocates a channel to do external memory 
 *         transfers. 
 *
 *  @param[in]  max_linked_transfers    Maximum number of linked transfers which 
 *                                      must be smaller than or equal to 
 *                                      LIB_EMT_MAX_NUM_CHANNELS. 
 *
 *  @retval     NULL      Failure to allocate the channel due to lack of resources 
 *  @retval     non-NULL  The handle to the allocated channel
 *
 *  @pre        lib_emt_init() must be called before this function can be called.
 *
 */
static inline lib_emt_Handle lib_emt_alloc(int32_t max_linked_transfers)
{
  return(EdmaMgr_alloc(max_linked_transfers));
}

/**
 *  @ingroup libarch_memtrans
 *  @brief   Function lib_emt_allocLarge allocates a memory transfer channel 
 *           for external "Large" 1D2D or 2D1D transfers which have a pitch  
 *           outside the range [-32768,32768].
 *
 *  @param[in]  cfg       Configuration for a channel to be allocated to do 
 *                        large 1D->2D or 2D->1D transfers. 
 *  @param[in]  memTab    Pointer to the structure which holds the base address 
 *                        and properties of the buffer allocated by the user.
 *                        
 *  @retval     NULL      Failure to allocate the channel
 *  @retval     non-NULL  The handle to the allocated channel
 *
 *  @pre        lib_emt_init() must be called before this function can be called.
 *  @pre        lib_emt_getSizesLarge() must be called and the requested buffer
 *              be allocated satisfying the requirements specified in memTab 
 *              returned by lib_emt_getSizesLarge(). 
 *
 */
static inline 
lib_emt_Handle lib_emt_allocLarge(lib_emt_ConfigLarge_t *cfg, 
                                  IALG_MemRec *memTab)
{
  return(EdmaMgr_allocLarge((EdmaMgr_ConfigLarge *)cfg, memTab));
}

/**
 *  @ingroup libarch_memtrans
 *  @brief   Function lib_emt_getSizesLarge gets buffer requirements for a 
 *           channel used to do large transfers.
 *
 *  @param[in]   cfg     Configuration for a channel to be allocated to do 
 *                       large 1D->2D or 2D->1D transfers. 
 *  @param[out]  memTab  Returned structure that holds the buffer requirements 
 *                       for a channel to do large 1D->2D or 2D->1D transfers.
 *
 *  @retval       LIB_EMT_SUCCESS         @copydoc LIB_EMT_SUCCESS
 *  @retval       LIB_EMT_ERROR_INVCFG    @copydoc LIB_EMT_ERROR_INVCFG
 *
 *  @remarks  The returned array memTab has only one element in it. A buffer 
 *            satisfying the requirements specified in memTab[0] must be 
 *            provided to lib_emt_allocLarge() along with the corresponding 
 *            lib_emt_ConfigLarge_t structure.
 */
static inline int32_t lib_emt_getSizesLarge(lib_emt_ConfigLarge_t *cfg, 
                                            IALG_MemRec *memTab)
{
  return(EdmaMgr_getSizesLarge((EdmaMgr_ConfigLarge *)cfg, memTab));
}

/**
 *  @ingroup libarch_memtrans
 *  @brief Function lib_emt_free frees a channel previously allocated for
 *         external memory transfers.
 *
 *  @param[in]  h  Handle returned from lib_emt_alloc() or lib_emt_allocLarge().
 *
 *  @retval     LIB_EMT_SUCCESS         @copydoc LIB_EMT_SUCCESS
 *  @retval     LIB_EMT_ERROR_INVHANDLE @copydoc LIB_EMT_ERROR_INVHANDLE
 *  @retval     LIB_EMT_ERROR_FREE      @copydoc LIB_EMT_ERROR_FREE
 *
 *  @pre        @c h must be a handle successfully returned from lib_emt_alloc()
 *              or lib_emt_allocLarge().
 */
static inline int32_t lib_emt_free(lib_emt_Handle h)
{
  return(EdmaMgr_free(h));
}

/**
 *  @ingroup libarch_memtrans
 *  @brief   Function lib_emt_wait waits for completion of external transfers
 *           started by lib_emt_copyxxx.
 *
 *  @param[in]  h  Handle returned from lib_emt_alloc() or lib_emt_allocLarge().
 *
 *  @pre        @c h must be a handle successfully returned from lib_emt_alloc()
 *              or lib_emt_allocLarge().
 *
 *  @remarks    This function waits for all transfers on a specific channel
 *              to complete.  It is a blocking call.
 */
static inline void lib_emt_wait(lib_emt_Handle h)
{
  EdmaMgr_wait(h);
}

/**
 *  @ingroup libarch_memtrans
 *  @brief  Function lib_emt_copy1D1D performs a single 1D->1D transfer.
 *
 *  @param[in]  h           Handle returned from lib_emt_alloc().
 *  @param[in]  src         Source address
 *  @param[in]  dst         Destination address
 *  @param[in]  num_bytes   Number of bytes to transfer
 *
 *  @pre        @c h must be a handle successfully returned from lib_emt_alloc().
 *
 *  @retval     Always @copydoc LIB_EMT_SUCCESS
 * 
 *  @remarks    Perform a single 1D->1D transfer of @c num_bytes bytes from
 *              @c src address to @c dst address.
 *
 *  @sa lib_emt_copy1D1DLinked
 *
 */
static inline 
int32_t lib_emt_copy1D1D(lib_emt_Handle h, void *restrict src, 
                          void *restrict dst, int32_t num_bytes)
{
  return(EdmaMgr_copy1D1D(h,src,dst,num_bytes));
}                                        
 
/**
 *  @ingroup libarch_memtrans
 *  @brief   Function lib_emt_copy1D2D performs a 1D->2D transfer.
 *
 *  @param[in]  h           Handle returned from lib_emt_alloc().
 *  @param[in]  src         Source address
 *  @param[in]  dst         Destination (two dimensional) address
 *  @param[in]  num_bytes   Number of bytes to transfer
 *  @param[in]  num_lines   Number of lines
 *  @param[in]  pitch       Pitch for destination address increment
 *
 *  @retval     Always @copydoc LIB_EMT_SUCCESS
 * 
 *  @pre        @c h must be a handle successfully returned from lib_emt_alloc().
 *
 *  @remarks    Perform a 1D->2D transfer of @c num_bytes bytes.  The source
 *              is one dimensional, and the destination is two dimensional.
 *
 *  @remarks    After every line of @c num_bytes is transferred, the @c src
 *              address is incremented by @c num_bytes and the @c dst address
 *              is incremented by @c pitch bytes.
 */
static inline 
int32_t lib_emt_copy1D2D(lib_emt_Handle h, void *restrict src, void *restrict dst, 
                          int32_t num_bytes, int32_t num_lines, int32_t pitch)
{
  return(EdmaMgr_copy1D2D(h,src,dst,num_bytes,num_lines,pitch));
} 

/**
 *  @ingroup libarch_memtrans
 *  @brief Function lib_emt_copy2D1D performs a 2D->1D transfer.
 *
 *  @param[in]  h           Handle returned from lib_emt_alloc().
 *  @param[in]  src         Source (two dimensional) address
 *  @param[in]  dst         Destination address
 *  @param[in]  num_bytes   Number of bytes to transfer
 *  @param[in]  num_lines   Number of lines
 *  @param[in]  pitch       Pitch for source address increment
 *
 *  @retval     Always @copydoc LIB_EMT_SUCCESS
 * 
 *  @pre        @c h must be a handle successfully returned from lib_emt_alloc().
 *
 *  @remarks    Perform a 2D->1D transfer of @c num_bytes bytes.  The source
 *              is two dimensional, and the destination is one dimensional.
 *
 *  @remarks    After every line of @c num_bytes is transferred, the @c src
 *              address is incremented by @c pitch and the @c dst address
 *              is incremented by @c num_bytes bytes.
 */
static inline 
int32_t lib_emt_copy2D1D(lib_emt_Handle h, void *restrict src, void *restrict dst, 
                          int32_t num_bytes, int32_t num_lines, int32_t pitch)
{
  return(EdmaMgr_copy2D1D(h,src,dst,num_bytes,num_lines,pitch));
} 

/**
 *  @ingroup libarch_memtrans
 *  @brief   Function lib_emt_copy2D2D perform a 2D->2D transfer. 
 *
 *  @param[in]  h           Handle returned from lib_emt_alloc().
 *  @param[in]  src         Source address
 *  @param[in]  dst         Destination address
 *  @param[in]  num_bytes   Number of bytes to transfer
 *  @param[in]  num_lines   Number of lines
 *  @param[in]  src_pitch   Pitch for source address increment
 *  @param[in]  dst_pitch   Pitch for destination address increment
 *
 *  @retval     Always @copydoc LIB_EMT_SUCCESS
 * 
 *  @pre        @c h must be a handle successfully returned from lib_emt_alloc().
 *
 *  @remarks    Perform a 2D->2D transfer of @c num_bytes bytes. The source
 *              and destination are both two dimensional.
 *
 *  @remarks    After every line of @c num_bytes is transferred, the @c src
 *              address is incremented by @c src_pitch bytes and the @c dst
 *              address is incremented by @c dst_pitch bytes.
 */
static inline 
int32_t lib_emt_copy2D2D(lib_emt_Handle h, void *restrict src, void *restrict dst, 
                          int32_t num_bytes, int32_t num_lines, int32_t src_pitch, 
                          int32_t dst_pitch)
{
  return(EdmaMgr_copy2D2DSep(h,src,dst,num_bytes,num_lines,src_pitch,dst_pitch));
}

/**
 *  @ingroup libarch_memtrans
 *  @brief   Function lib_emt_copy1D1DLinked performs a group of linked 1D->1D 
 *           transfers.
 *
 *  @param[in]  h               Handle returned from lib_emt_alloc().
 *  @param[in]  src[]           Array of source addresses
 *  @param[in]  dst[]           Array of destination addresses
 *  @param[in]  num_bytes[]     Array of number of bytes to transfer
 *  @param[in]  num_transfers   Number of transfers
 *
 *  @retval     Always @copydoc LIB_EMT_SUCCESS
 * 
 *  @pre        @c h must be a handle successfully returned from lib_emt_alloc().
 *
 *  @sa lib_emt_copy1D1D
 */
static inline 
int32_t lib_emt_copy1D1DLinked(lib_emt_Handle h, void *restrict src[], 
                                void *restrict dst[], int32_t num_bytes[], 
                                int32_t num_transfers)
{
  return(EdmaMgr_copy1D1DLinked(h,src,dst,num_bytes,num_transfers));
}
 
/**
 *  @ingroup libarch_memtrans
 *  @brief   Function lib_emt_copy1D2DLinked performs a group of linked 1D->2D 
 *           transfers.
 *
 *  @param[in]  h               Handle returned from lib_emt_alloc().
 *  @param[in]  src[]           Array of source addresses
 *  @param[in]  dst[]           Array of destination addresses
 *  @param[in]  num_bytes[]     Array of number of bytes to transfer
 *  @param[in]  num_lines[]     Array of lines to transfer
 *  @param[in]  pitch[]         Array of pitches for destination address increment
 *  @param[in]  num_transfers   Number of transfers
 *
 *  @retval     Always @copydoc LIB_EMT_SUCCESS
 * 
 *  @pre        @c h must be a handle successfully returned from lib_emt_alloc().
 *
 *  @sa lib_emt_copy1D2D
 */
static inline 
int32_t lib_emt_copy1D2DLinked(lib_emt_Handle h, void *restrict src[], 
                                void *restrict dst[], int32_t num_bytes[], 
                                int32_t num_lines[], int32_t pitch[], 
                                int32_t num_transfers)
{
  return(EdmaMgr_copy1D2DLinked(h,src,dst,num_bytes,num_lines,pitch,num_transfers));
} 

/**
 *  @ingroup libarch_memtrans
 *  @brief   Function lib_emt_copy2D1DLinked performs a group of linked 2D->1D 
 *           transfers.
 *
 *  @param[in]  h               Handle returned from lib_emt_alloc().
 *  @param[in]  src[]           Array of source addresses
 *  @param[in]  dst[]           Array of destination addresses
 *  @param[in]  num_bytes[]     Array of number of bytes to transfer
 *  @param[in]  num_lines[]     Array of lines to transfer
 *  @param[in]  pitch[]         Array of pitches for source address increment
 *  @param[in]  num_transfers   Number of transfers
 *
 *  @retval     Always @copydoc LIB_EMT_SUCCESS
 * 
 *  @pre        @c h must be a handle successfully returned from lib_emt_alloc().
 *
 *  @sa lib_emt_copy2D1D
 */
static inline 
int32_t lib_emt_copy2D1DLinked(lib_emt_Handle h, void *restrict src[], 
                                void *restrict dst[], int32_t num_bytes[], 
                                int32_t num_lines[], int32_t pitch[], 
                                int32_t num_transfers)
{
  return(EdmaMgr_copy2D1DLinked(h,src,dst,num_bytes,num_lines,pitch,num_transfers));
}
 
/**
 *  @ingroup libarch_memtrans
 *  @brief   Function lib_emt_copy2D2DLinked performs a group of linked 2D->2D 
 *           transfers.
 *
 *  @param[in]  h               Handle returned from lib_emt_alloc().
 *  @param[in]  src[]           Array of source addresses
 *  @param[in]  dst[]           Array of destination addresses
 *  @param[in]  num_bytes[]     Array of number of bytes to transfer
 *  @param[in]  num_lines[]     Array of lines to transfer
 *  @param[in]  src_pitch[]     Array of source pitches
 *  @param[in]  dst_pitch[]     Array of destination pitches
 *  @param[in]  num_transfers   Number of transfers
 *
 *  @retval     Always @copydoc LIB_EMT_SUCCESS
 * 
 *  @pre        @c h must be a handle successfully returned from lib_emt_alloc().
 *
 *  @sa lib_emt_copy2D2DSep
 */
static inline 
int32_t lib_emt_copy2D2DLinked(lib_emt_Handle h, void *restrict src[], 
                                void *restrict dst[], int32_t num_bytes[], 
                                int32_t num_lines[], int32_t src_pitch[], 
                                int32_t dst_pitch[], int32_t num_transfers)
{
  return(EdmaMgr_copy2D2DSepLinked(h,src,dst,num_bytes,num_lines,src_pitch,
                                   dst_pitch,num_transfers));
} 

/**
 *  @ingroup libarch_memtrans
 *  @brief   Function lib_emt_copy1D2DLarge performs a 1D->2D transfer when
 *           destination pitch is large (outside the range of [-32768,32767]).
 *
 *  @param[in]  h           Handle returned from lib_emt_allocLarge().
 *  @param[in]  src         Source address
 *  @param[in]  dst         Destination address
 *  @param[in]  num_bytes   Number of bytes to transfer
 *  @param[in]  num_lines   Number of lines
 *  @param[in]  pitch       Pitch for destination address increment
 *
 *  @retval     Always @copydoc LIB_EMT_SUCCESS
 * 
 *  @pre        @c h must be a handle successfully returned from
 *              lib_emt_allocLarge().
 *
 *  @remarks    Perform a 1D->2D transfer of @c num_bytes bytes.  The source
 *              is one dimensional, and the destination is two dimensional.
 *
 *  @remarks    After every line of @c num_bytes is transferred, the @c src
 *              address is incremented by @c num_bytes and the @c dst address
 *              is incremented by @c pitch bytes.
 *
 *  @remarks    This should be used when the pitch is outside the range of
 *              [-32768,32767].
 */
static inline 
int32_t lib_emt_copy1D2DLarge(lib_emt_Handle h, void *restrict src, 
                               void *restrict dst, int32_t num_bytes, 
                               int32_t num_lines, int32_t pitch)
{
  return(EdmaMgr_copy1D2DLarge(h,src,dst,num_bytes,num_lines,pitch));
}
 
/**
 *  @ingroup libarch_memtrans
 *  @brief   Function lib_emt_copy2D1DLarge performs a 2D->1D transfer when
 *           source pitch is large (outside the range of [-32768,32767]).
 *
 *  @param[in]  h           Handle returned from lib_emt_allocLarge().
 *  @param[in]  src         Source address
 *  @param[in]  dst         Destination address
 *  @param[in]  num_bytes   Number of bytes to transfer
 *  @param[in]  num_lines   Number of lines
 *  @param[in]  pitch       Pitch
 *
 *  @retval     Always @copydoc LIB_EMT_SUCCESS
 * 
 *  @pre        @c h must be a handle successfully returned from
 *              lib_emt_allocLarge().
 *
 *  @remarks    Perform a 2D->1D transfer of @c num_bytes bytes.  The source
 *              is two dimensional, and the destination is one dimensional.
 *
 *  @remarks    After every line of @c num_bytes is transferred, the @c src
 *              address is incremented by @c pitch and the @c dst address
 *              is incremented by @c num_bytes bytes.
 *
 *  @remarks    This should be used when the pitch is outside the range of
 *              [-32768,32767].
 */
static inline 
int32_t lib_emt_copy2D1DLarge(lib_emt_Handle h, void *restrict src, 
                               void *restrict dst, int32_t num_bytes, 
                               int32_t num_lines, int32_t pitch)
{
  return(EdmaMgr_copy2D1DLarge(h,src,dst,num_bytes,num_lines,pitch));
} 

/* EdmaMgr APIs listed below are not mapped to LibArch APIs:
int32_t EdmaMgr_copy2D2D(EdmaMgr_Handle h, void *restrict src, void *restrict dst, 
                         int32_t num_bytes, int32_t num_lines, int32_t pitch);
int32_t EdmaMgr_copy2D2DLinked(EdmaMgr_Handle h, void *restrict src[], 
                               void *restrict dst[], int32_t num_bytes[], 
                               int32_t num_lines[], int32_t pitch[], 
                               int32_t num_transfers);
int32_t EdmaMgr_copyFast(EdmaMgr_Handle h, void *restrict src, void *restrict dst);
int32_t EdmaMgr_copyLinkedFast(EdmaMgr_Handle h, void *restrict src[], 
                               void *restrict dst[], int32_t num_transfers);
*/

#endif 
