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

#ifndef BLIS_CONFIG_H
#define BLIS_CONFIG_H

#define BLIS_ENABLE_C66X_BUILD

#define BLIS_ENABLE_C66X_MEM_POOLS


#ifdef BLIS_ENABLE_C66X_OPENCL
// clocl creates a cio section in L2 when fprintf is used. Redefining fprintf to map to printf.
#define fprintf ti_printf
#endif




// -- OPERATING SYSTEM ---------------------------------------------------------

// -- INTEGER PROPERTIES -------------------------------------------------------

// The bit size of the integer type used to track values such as dimensions,
// strides, diagonal offsets. A value of 32 results in BLIS using 32-bit signed
// integers while 64 results in 64-bit integers. Any other value results in use
// of the C99 type "long int". Note that this ONLY affects integers used
// internally within BLIS as well as those exposed in the native BLAS-like BLIS
// interface.
#define BLIS_INT_TYPE_SIZE               32



// -- FLOATING-POINT PROPERTIES ------------------------------------------------

// Define the number of floating-point types supported, and the size of the
// largest type.
#define BLIS_NUM_FP_TYPES                4
#define BLIS_MAX_TYPE_SIZE               sizeof(dcomplex)

// Enable use of built-in C99 "float complex" and "double complex" types and
// associated overloaded operations and functions? Disabling results in
// scomplex and dcomplex being defined in terms of simple structs.
//#define BLIS_ENABLE_C99_COMPLEX

// -- c66x headers -------------------------------------------------------------
#include "c6x.h"

//#include <ti/csl/device/k2h/src/cslr_device.h>

#include <ti/libarch/libarch.h>
#include <ti/csl/csl_chipAux.h> // CSL_chipReadDNUM -> to read coreID
#include <ti/csl/csl_cacheAux.h> // CACHE_invL1d

// for __clock64()
//#include <dsp_c.h>

// -- EDMA ---------------------------------------------------------------------
#define BLIS_ENABLE_C66X_EDMA

#ifdef BLIS_ENABLE_C66X_EDMA

#if defined(MEM_MODEL_LARGE) 

#define BLIS_GEMM_DMAA_CNTL gemm_dmaa_cntl
#define BLIS_GEMM_DMAB_CNTL gemm_dmab_cntl

#elif defined (MEM_MODEL_SMALL) || defined (MEM_MODEL_MEDIUM)
#define BLIS_GEMM_DMAA_CNTL NULL                // disabling EDMA
#define BLIS_GEMM_DMAB_CNTL NULL
#endif

/*
#if USING_FC_EDMAMGR
#include <xdc/std.h>

#define ECPY_INLINE_ALL        1
#define EDMAMGR_INLINE_ALL     1
#include <ti/sdo/fc/edmamgr/edmamgr.h>
#else
#include "edmamgr.h"
#endif
*/

#define BLIS_C66X_MAXDMASTRIDE 0x7FFF

#define BLIS_C66X_EDMA_MAX_NUM_CHANNELS 6
#endif

// -- PREFETCH -----------------------------------------------------------------
//#define BLIS_ENABLE_C66X_PREFETCH

#ifdef BLIS_ENABLE_C66X_PREFETCH
#include "touch.h"
#endif

// -- IDMA -----------------------------------------------------------------
#define BLIS_ENABLE_C66X_IDMA

#ifdef BLIS_ENABLE_C66X_IDMA
#include "idma.h"
#endif

// -- PROFILE -----------------------------------------------------------------
//uncomment to Profile performance
//#define BLIS_ENABLE_PROFILE

// -- MULTITHREADING -----------------------------------------------------------

// The maximum number of BLIS threads that will run concurrently.

/* While testing this code on Hawking, the value of BLIS_MAX_NUM_THREADS
 * needs to be 8. OpenMP randomly assigns the OpenMP threads to the cores.
 * This value needs to be 8 to make sure all the cores are initialized
 * before the openMP region begins.
 *
 * When porting to the specific architecture. Change BLIS_MAX_NUM_THREADS to the
 * number of cores available on the device, and change BLIS_C66X_IC_NT to
 * BLIS_MAX_NUM_THREADS
*/
#define BLIS_ENABLE_MULTITHREADING
#define BLIS_ENABLE_OPENMP

/* BLIS_MAX_NUM_THREADS is defined in make_defs.mk
#if defined(MEM_MODEL_LARGE)  || defined (MEM_MODEL_MEDIUM)
#define BLIS_MAX_NUM_THREADS            8
#elif defined (MEM_MODEL_SMALL)
#define BLIS_MAX_NUM_THREADS            2
#endif
*/
#define BLIS_C66X_IC_NT                 BLIS_MAX_NUM_THREADS

#define BLIS_C66X_JC_NT                 1
#define BLIS_C66X_JR_NT                 1
#define BLIS_C66X_IR_NT                 1


// -- MEMORY ALLOCATION --------------------------------------------------------

// -- Contiguous (static) memory allocator --

// The number of MC x KC, KC x NC, and MC x NC blocks to reserve in the
// contiguous memory pools.

#define BLIS_NUM_MC_X_KC_BLOCKS_L3          0
#if defined (MEM_MODEL_MEDIUM) || defined (MEM_MODEL_SMALL)
#define BLIS_NUM_MC_X_KC_BLOCKS_L2          1 // no need of ping-pong buffer if EDMA is not used. for matrix A, DDR->L2
#else
#define BLIS_NUM_MC_X_KC_BLOCKS_L2          2 //Each L2 ram is local to the DSP Just need one buffer per thread that is packed
#endif
#define BLIS_NUM_MC_X_KC_BLOCKS_L1          0
#define BLIS_NUM_MR_X_KC_BLOCKS_L1          2 // To transfer A to L1 in a ping-poing manner
#define BLIS_NUM_MC_X_KC_BLOCKS             2*BLIS_MAX_NUM_THREADS + 1 //To test w/o DMA and L2, L3 memory, all memory must be in DDR3 now

#if defined (MEM_MODEL_MEDIUM) || defined (MEM_MODEL_SMALL)
#define BLIS_NUM_KC_X_NC_BLOCKS_L3          1 // no need of ping-pong buffer if EDMA is not used. for matrix B, DDR->L3
#else
#define BLIS_NUM_KC_X_NC_BLOCKS_L3          2 // Each thread shares a B block, so do not need 8 buffers *BLIS_MAX_NUM_THREADS // One for the partitioned B1, and one for the packed B1
#endif
#define BLIS_NUM_KC_X_NC_BLOCKS_L2          0
#define BLIS_NUM_KC_X_NC_BLOCKS_L1          0
#define BLIS_NUM_KC_X_NR_BLOCKS_L1          1
#define BLIS_NUM_KC_X_NC_BLOCKS             2*BLIS_MAX_NUM_THREADS //To test w/o DMA and L2, L3 memory, all memory must be in DDR3 now

#define BLIS_NUM_MC_X_NC_BLOCKS_L3          0
#define BLIS_NUM_MC_X_NC_BLOCKS_L2          0
// still using EDMA in bli_gemm_ker_var2 (DDR->L2 for C output buffer, L2->L1 for matrix A, MSMC->L1 for B)
#define BLIS_NUM_MC_X_NR_BLOCKS_L2          3 //Bringing C into the L2 memory. We need 3 buffers, one to read, one to compute and one to write.
#define BLIS_NUM_MC_X_NC_BLOCKS_L1          0
#define BLIS_NUM_MR_X_NR_BLOCKS_L1          0
#define BLIS_NUM_MC_X_NC_BLOCKS             0


// The maximum preload byte offset is used to pad the end of the contiguous
// memory pools so that the micro-kernel, when computing with the end of the
// last block, can exceed the bounds of the usable portion of the memory
// region without causing a segmentation fault.
#define BLIS_MAX_PRELOAD_BYTE_OFFSET     128

// -- Memory alignment --

// It is sometimes useful to define the various memory alignments in terms
// of some other characteristics of the system, such as the cache line size
// and the page size.
#define BLIS_CACHE_LINE_SIZE             64
#define BLIS_PAGE_SIZE                   4096

// Alignment size needed by the instruction set for aligned SIMD/vector
// instructions.
#define BLIS_SIMD_ALIGN_SIZE             16

// Alignment size used to align local stack buffers within macro-kernel
// functions.
#define BLIS_STACK_BUF_ALIGN_SIZE        BLIS_SIMD_ALIGN_SIZE

// Alignment size used when allocating memory dynamically from the operating
// system (eg: posix_memalign()). To disable heap alignment and just use
// malloc() instead, set this to 1.
#define BLIS_HEAP_ADDR_ALIGN_SIZE        BLIS_SIMD_ALIGN_SIZE

// Alignment size used when sizing leading dimensions of dynamically
// allocated memory.
#define BLIS_HEAP_STRIDE_ALIGN_SIZE      BLIS_CACHE_LINE_SIZE

// Alignment size used when allocating entire blocks of contiguous memory
// from the contiguous memory allocator.
#define BLIS_CONTIG_ADDR_ALIGN_SIZE      BLIS_CACHE_LINE_SIZE//BLIS_PAGE_SIZE

// Extra buffer space in each block in L1 to account for bank conflict
/* There are 2 buffers of size MRK and 1 buffer of size KNR in L1. The
 * extra buffer space in each block in L1 is computed based on the
 * remaining space available in L1. L1DSRAM is configured to size 28K.
 * The total size of the blocks in L1 = 2*MR*KC*size of datatype + KC*NR* size of datatype.
 * The remaining available space in L1 is divided such that
 * 2*BLIS_MRK_BLOCK_BUFFER_L1+1*BLIS_KNR_PANEL_BUFFER_L1+0BLIS_MRNR_BLOCK_BUFFER_L1_S = remaining available space.
 */
#define BLIS_MRK_BLOCK_BUFFER_L1_S                 128 //
#define BLIS_MRK_BLOCK_BUFFER_L1_D                 64 //
#define BLIS_MRK_BLOCK_BUFFER_L1_C                 64 //
#define BLIS_MRK_BLOCK_BUFFER_L1_Z                 32 //
#define BLIS_KNR_PANEL_BUFFER_L1_S                 256 //
#define BLIS_KNR_PANEL_BUFFER_L1_D                 128
#define BLIS_KNR_PANEL_BUFFER_L1_C                 128
#define BLIS_KNR_PANEL_BUFFER_L1_Z                 64
#define BLIS_MRNR_BLOCK_BUFFER_L1_S                128 //
#define BLIS_MRNR_BLOCK_BUFFER_L1_D                64 //
#define BLIS_MRNR_BLOCK_BUFFER_L1_C                64 //
#define BLIS_MRNR_BLOCK_BUFFER_L1_Z                32 //

//

#define bli_sbank 8
#define bli_dbank 16
#define bli_cbank 16
#define bli_zbank 24



// -- MIXED DATATYPE SUPPORT ---------------------------------------------------

// Basic (homogeneous) datatype support always enabled.

// Enable mixed domain operations?
//#define BLIS_ENABLE_MIXED_DOMAIN_SUPPORT

// Enable extra mixed precision operations?
//#define BLIS_ENABLE_MIXED_PRECISION_SUPPORT



// -- MISCELLANEOUS OPTIONS ----------------------------------------------------

// Stay initialized after auto-initialization, unless and until the user
// explicitly calls bli_finalize().
#define BLIS_ENABLE_STAY_AUTO_INITIALIZED



// -- BLAS-to-BLIS COMPATIBILITY LAYER -----------------------------------------

// Enable the BLAS compatibility layer?
#define BLIS_ENABLE_BLAS2BLIS

// The bit size of the integer type used to track values such as dimensions and
// leading dimensions (ie: column strides) within the BLAS compatibility layer.
// A value of 32 results in the compatibility layer using 32-bit signed integers
// while 64 results in 64-bit integers. Any other value results in use of the
// C99 type "long int". Note that this ONLY affects integers used within the
// BLAS compatibility layer.
#define BLIS_BLAS2BLIS_INT_TYPE_SIZE     32

// Fortran-77 name-mangling macros.
#define PASTEF770(name)                        name ## _
#define PASTEF77(ch1,name)       ch1        ## name ## _
#define PASTEF772(ch1,ch2,name)  ch1 ## ch2 ## name ## _



extern void * blasGetMemHandle();

#endif

