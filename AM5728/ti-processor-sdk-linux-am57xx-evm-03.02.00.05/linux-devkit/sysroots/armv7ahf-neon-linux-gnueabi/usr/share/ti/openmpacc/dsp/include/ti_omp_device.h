/******************************************************************************
 * Copyright (c) 2014, Texas Instruments Incorporated - http://www.ti.com/
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
#ifndef _TI_OMP_DEVICE_H_
#define _TI_OMP_DEVICE_H_

/*-----------------------------------------------------------------------------
* While this file may also be included when compiling device code, the 
* following check ensures that these definitions are only included when 
* compiling for the host.
*----------------------------------------------------------------------------*/
#ifdef __arm__
#ifdef __cplusplus
#include <stdint.h>
#include <cstdlib>
#define _QUALIFY    std::
extern "C" {
#else
#include <stdint.h>
#include <stdlib.h>
#define _QUALIFY
#endif /* __cplusplus */

void*  __malloc_ddr  (_QUALIFY size_t size);
void*  __malloc_msmc (_QUALIFY size_t size);
void   __free_ddr    (void* ptr);
void   __free_msmc   (void* ptr);

void omp_set_default_device (int device_num);
int  omp_get_default_device (void);
int  omp_get_num_devices    (void);
int  omp_is_initial_device  (void);

/*-----------------------------------------------------------------------------
* This following are definitions for host versions of some functions that are 
* typically applicable to executions wihin DSP environments. They include 
* built-in DSP functions as well as functions for cache and dynamic memory 
* management. Host versions of these functions are provided to facilitate easy 
* compilation and execution of target regions that may end up being executed 
* on the host. 
*----------------------------------------------------------------------------*/
void     __touch           (const char *p, uint32_t size);
uint32_t __core_num        (void);
uint32_t __clock           (void);
uint64_t __clock64         (void);
void     __cycle_delay     (uint64_t cyclesToDelay);
void     __mfence          (void);

void     __cache_l1d_none  (void);
void     __cache_l1d_all   (void);
void     __cache_l1d_4k    (void);
void     __cache_l1d_8k    (void);
void     __cache_l1d_16k   (void);
void     __cache_l1d_flush (void);

void     __cache_l2_none   (void);
void     __cache_l2_128k   (void);
void     __cache_l2_256k   (void);
void     __cache_l2_512k   (void);
void     __cache_l2_flush  (void);

void     __heap_init_ddr  (void *ptr, size_t size);
void*    __calloc_ddr     (size_t num, size_t size);
void*    __realloc_ddr    (void *ptr,  size_t size);
void*    __memalign_ddr   (size_t alignment, size_t size);

void     __heap_init_msmc (void *ptr, size_t size);
void*    __calloc_msmc    (size_t num, size_t size);
void*    __realloc_msmc   (void *ptr, size_t size);
void*    __memalign_msmc  (size_t alignment, size_t size);

void     __heap_init_l2   (void *ptr, size_t size);
void*    __malloc_l2      (size_t size);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* __arm__ */

#endif /* _TI_OMP_DEVICE_H_ */
