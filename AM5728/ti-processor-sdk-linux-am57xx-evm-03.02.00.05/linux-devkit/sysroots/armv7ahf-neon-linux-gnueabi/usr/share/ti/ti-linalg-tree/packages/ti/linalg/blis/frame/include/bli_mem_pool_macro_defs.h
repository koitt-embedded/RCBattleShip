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

#ifndef BLIS_POOL_BLOCKS_MACRO_DEFS_H
#define BLIS_POOL_BLOCKS_MACRO_DEFS_H


// -- Memory pool block sizing macros ------------------------------------------

// In this file, we compute the memory pool block sizes for A, B, and C for
// each floating-point datatype, and then search for and save the maximum.
// The reason we settle on the largest is to prevent a developer from
// implementing a micro-kernel for one datatype (say, single real) and then
// end up in a situation where the memory pool is not large enough because
// the cache blocksize value of the datatype used to size the pool (e.g.
// double) was not updated accordingly.

// First we compute possible scaling factors for each datatype. These
// scaling factors actually take the form of numerator and denominator
// since we want stay in integer arithmetic. The purpose of the scaling
// factors is to increase the amount of space we reserve for the memory
// pool blocks if one of the packed micro-panels has a "leading dimension"
// that is larger than the register blocksize. (In this case, the leading
// dimension of a micro-panel is the packing register blocksize.)

// Note that when computing the scaling factor, we have to determine which
// of PACKDIM_MR/DEFAULT_MR and PACKDIM_NR/DEFAULT_NR is greater so that
// the pair of values can be used to scale MAXIMUM_MC and MAXIMUM_NC. This
// is needed ONLY because the amount of space allocated for a block of A
// and a panel of B needs to be such that MR and NR can be swapped (ie: A
// is packed with NR and B is packed with MR). This transformation is
// needed for right-side trsm when inducing an algorithm that (a) has
// favorable access patterns for column-stored C and (b) allows the
// macro-kernel to reuse the existing left-side fused gemmtrsm micro-kernels.
// We cross-multiply so that the comparison can stay in integer arithmetic.


//
// Create "local" definitions for the 4m and 3m maximum cache blocksizes
// so that we can more easily show the computation of the pool dimensions
// below.
//

// 4m maximum cache blocksizes
#ifdef BLIS_ENABLE_C66X_MEM_POOLS
//Dnparikh
/* To control the memory blocks better. If the default is not defined in bli_kernel.h
 * then define the MAXIMUM_3M_*_* based on MAXIMIM_MC_* values, else
 * define MAXIMUM_3M_*_* based on the DEFAULT_3M_*_* value (assume EXTEND_3M_*_* = 0)
 */

#ifndef BLIS_DEFAULT_4M_MC_C
#define BLIS_MAXIMUM_4M_MC_C     BLIS_MAXIMUM_MC_S
#else
#define BLIS_MAXIMUM_4M_MC_C     BLIS_DEFAULT_4M_MC_C
#endif

#ifndef BLIS_DEFAULT_4M_KC_C
#define BLIS_MAXIMUM_4M_KC_C   ((BLIS_MAXIMUM_KC_S)/2)
#else
#define BLIS_MAXIMUM_4M_KC_C     BLIS_DEFAULT_4M_KC_C
#endif

#ifndef BLIS_DEFAULT_4M_NC_C
#define BLIS_MAXIMUM_4M_NC_C     BLIS_MAXIMUM_NC_S
#else
#define BLIS_MAXIMUM_4M_NC_C     BLIS_DEFAULT_4M_NC_C
#endif

#ifndef BLIS_DEFAULT_4M_MC_Z
#define BLIS_MAXIMUM_4M_MC_Z     BLIS_MAXIMUM_MC_D
#else
#define BLIS_MAXIMUM_4M_MC_Z     BLIS_DEFAULT_4M_MC_Z
#endif

#ifndef BLIS_DEFAULT_4M_KC_Z
#define BLIS_MAXIMUM_4M_KC_Z   ((BLIS_MAXIMUM_KC_D)/2)
#else
#define BLIS_MAXIMUM_4M_KC_Z     BLIS_DEFAULT_4M_KC_Z
#endif

#ifndef BLIS_DEFAULT_4M_NC_Z
#define BLIS_MAXIMUM_4M_NC_Z     BLIS_MAXIMUM_NC_D
#else
#define BLIS_MAXIMUM_4M_NC_Z     BLIS_DEFAULT_4M_NC_Z
#endif

#else

#define BLIS_MAXIMUM_4M_MC_C     BLIS_MAXIMUM_MC_S
#define BLIS_MAXIMUM_4M_KC_C   ((BLIS_MAXIMUM_KC_S)/2)
#define BLIS_MAXIMUM_4M_NC_C     BLIS_MAXIMUM_NC_S

#define BLIS_MAXIMUM_4M_MC_Z     BLIS_MAXIMUM_MC_D
#define BLIS_MAXIMUM_4M_KC_Z   ((BLIS_MAXIMUM_KC_D)/2)
#define BLIS_MAXIMUM_4M_NC_Z     BLIS_MAXIMUM_NC_D
#endif

// 3m maximum cache blocksizes
#ifdef BLIS_ENABLE_C66X_MEM_POOLS
//Dnparikh
/* To control the memory blocks better. If the default is not defined in bli_kernel.h
 * then define the MAXIMUM_3M_*_* based on MAXIMIM_MC_* values, else
 * define MAXIMUM_3M_*_* based on the DEFAULT_3M_*_* value (assume EXTEND_3M_*_* = 0)
 */

#ifndef BLIS_DEFAULT_3M_MC_C
#define BLIS_MAXIMUM_3M_MC_C     BLIS_MAXIMUM_MC_S
#else
#define BLIS_MAXIMUM_3M_MC_C     BLIS_DEFAULT_3M_MC_C
#endif

#ifndef BLIS_DEFAULT_3M_KC_C
#define BLIS_MAXIMUM_3M_KC_C   ((BLIS_MAXIMUM_KC_S)/2)
#else
#define BLIS_MAXIMUM_3M_KC_C     BLIS_DEFAULT_3M_KC_C
#endif

#ifndef BLIS_DEFAULT_3M_NC_C
#define BLIS_MAXIMUM_3M_NC_C     BLIS_MAXIMUM_NC_S
#else
#define BLIS_MAXIMUM_3M_NC_C     BLIS_DEFAULT_3M_NC_C
#endif

#ifndef BLIS_DEFAULT_3M_MC_Z
#define BLIS_MAXIMUM_3M_MC_Z     BLIS_MAXIMUM_MC_D
#else
#define BLIS_MAXIMUM_3M_MC_Z     BLIS_DEFAULT_3M_MC_Z
#endif

#ifndef BLIS_DEFAULT_3M_KC_Z
#define BLIS_MAXIMUM_3M_KC_Z   ((BLIS_MAXIMUM_KC_D)/2)
#else
#define BLIS_MAXIMUM_3M_KC_Z     BLIS_DEFAULT_3M_KC_Z
#endif

#ifndef BLIS_DEFAULT_3M_NC_Z
#define BLIS_MAXIMUM_3M_NC_Z     BLIS_MAXIMUM_NC_D
#else
#define BLIS_MAXIMUM_3M_NC_Z     BLIS_DEFAULT_3M_NC_Z
#endif

#else

#define BLIS_MAXIMUM_3M_MC_C     BLIS_MAXIMUM_MC_S
#define BLIS_MAXIMUM_3M_KC_C   ((BLIS_MAXIMUM_KC_S)/2)
#define BLIS_MAXIMUM_3M_NC_C     BLIS_MAXIMUM_NC_S

#define BLIS_MAXIMUM_3M_MC_Z     BLIS_MAXIMUM_MC_D
#define BLIS_MAXIMUM_3M_KC_Z   ((BLIS_MAXIMUM_KC_D)/2)
#define BLIS_MAXIMUM_3M_NC_Z     BLIS_MAXIMUM_NC_D
#endif


//
// Compute scaling factors for single real.
//
#if ( BLIS_PACKDIM_MR_S * BLIS_DEFAULT_NR_S ) >= \
    ( BLIS_PACKDIM_NR_S * BLIS_DEFAULT_MR_S )
  #define BLIS_PACKDIM_MAXR_S BLIS_PACKDIM_MR_S
  #define BLIS_DEFAULT_MAXR_S BLIS_DEFAULT_MR_S
#else
  #define BLIS_PACKDIM_MAXR_S BLIS_PACKDIM_NR_S
  #define BLIS_DEFAULT_MAXR_S BLIS_DEFAULT_NR_S
#endif

//
// Compute scaling factors for double real.
//
#if ( BLIS_PACKDIM_MR_D * BLIS_DEFAULT_NR_D ) >= \
    ( BLIS_PACKDIM_NR_D * BLIS_DEFAULT_MR_D )
  #define BLIS_PACKDIM_MAXR_D BLIS_PACKDIM_MR_D
  #define BLIS_DEFAULT_MAXR_D BLIS_DEFAULT_MR_D
#else
  #define BLIS_PACKDIM_MAXR_D BLIS_PACKDIM_NR_D
  #define BLIS_DEFAULT_MAXR_D BLIS_DEFAULT_NR_D
#endif

//
// Compute scaling factors for single complex.
//
#if ( BLIS_PACKDIM_MR_C * BLIS_DEFAULT_NR_C ) >= \
    ( BLIS_PACKDIM_NR_C * BLIS_DEFAULT_MR_C )
  #define BLIS_PACKDIM_MAXR_C BLIS_PACKDIM_MR_C
  #define BLIS_DEFAULT_MAXR_C BLIS_DEFAULT_MR_C
#else
  #define BLIS_PACKDIM_MAXR_C BLIS_PACKDIM_NR_C
  #define BLIS_DEFAULT_MAXR_C BLIS_DEFAULT_NR_C
#endif

//
// Compute scaling factors for double complex.
//
#if ( BLIS_PACKDIM_MR_Z * BLIS_DEFAULT_NR_Z ) >= \
    ( BLIS_PACKDIM_NR_Z * BLIS_DEFAULT_MR_Z )
  #define BLIS_PACKDIM_MAXR_Z BLIS_PACKDIM_MR_Z
  #define BLIS_DEFAULT_MAXR_Z BLIS_DEFAULT_MR_Z
#else
  #define BLIS_PACKDIM_MAXR_Z BLIS_PACKDIM_NR_Z
  #define BLIS_DEFAULT_MAXR_Z BLIS_DEFAULT_NR_Z
#endif


// Next, we define the dimensions of the pool blocks for each datatype.

//
// Compute pool dimensions for single real
//
#define BLIS_POOL_MC_S     ( ( BLIS_MAXIMUM_MC_S * BLIS_PACKDIM_MAXR_S ) \
                                                 / BLIS_DEFAULT_MAXR_S )
#define BLIS_POOL_NC_S     ( ( BLIS_MAXIMUM_NC_S * BLIS_PACKDIM_MAXR_S ) \
                                                 / BLIS_DEFAULT_MAXR_S )
#define BLIS_POOL_KC_S     ( ( BLIS_MAXIMUM_KC_S * BLIS_PACKDIM_KR_S   ) \
                                                 / BLIS_DEFAULT_KR_S   )
#ifdef BLIS_ENABLE_C66X_MEM_POOLS
#define BLIS_POOL_NR_S BLIS_PACKDIM_NR_S
#define BLIS_POOL_MR_S BLIS_PACKDIM_MR_S

#define BLIS_POOL_MC_L2_S (BLIS_POOL_MC_S + BLIS_POOL_KC_S)/2
#define BLIS_POOL_KC_L2_S (BLIS_POOL_MC_S + BLIS_POOL_KC_S)/2
#define BLIS_POOL_KC_L3_S (BLIS_POOL_NC_S + BLIS_POOL_KC_S)/2
#define BLIS_POOL_NC_L3_S (BLIS_POOL_NC_S + BLIS_POOL_KC_S)/2
#endif

//
// Compute pool dimensions for double real
//
#define BLIS_POOL_MC_D     ( ( BLIS_MAXIMUM_MC_D * BLIS_PACKDIM_MAXR_D ) \
                                                 / BLIS_DEFAULT_MAXR_D )
#define BLIS_POOL_NC_D     ( ( BLIS_MAXIMUM_NC_D * BLIS_PACKDIM_MAXR_D ) \
                                                 / BLIS_DEFAULT_MAXR_D )
#define BLIS_POOL_KC_D     ( ( BLIS_MAXIMUM_KC_D * BLIS_PACKDIM_KR_D   ) \
                                                 / BLIS_DEFAULT_KR_D   )
#ifdef BLIS_ENABLE_C66X_MEM_POOLS
#define BLIS_POOL_MC_L2_D (BLIS_POOL_MC_D + BLIS_POOL_KC_D)/2
#define BLIS_POOL_KC_L2_D (BLIS_POOL_MC_D + BLIS_POOL_KC_D)/2
#define BLIS_POOL_KC_L3_D (BLIS_POOL_NC_D + BLIS_POOL_KC_D)/2
#define BLIS_POOL_NC_L3_D (BLIS_POOL_NC_D + BLIS_POOL_KC_D)/2
#define BLIS_POOL_NR_D BLIS_PACKDIM_NR_D
#define BLIS_POOL_MR_D BLIS_PACKDIM_MR_D
#endif
//
// Compute pool dimensions for single complex
//
#define BLIS_POOL_MC_C     ( ( BLIS_MAXIMUM_MC_C * BLIS_PACKDIM_MAXR_C ) \
                                                 / BLIS_DEFAULT_MAXR_C )
#define BLIS_POOL_NC_C     ( ( BLIS_MAXIMUM_NC_C * BLIS_PACKDIM_MAXR_C ) \
                                                 / BLIS_DEFAULT_MAXR_C )
#define BLIS_POOL_KC_C     ( ( BLIS_MAXIMUM_KC_C * BLIS_PACKDIM_KR_C   ) \
                                                 / BLIS_DEFAULT_KR_C   )

#ifdef BLIS_ENABLE_C66X_MEM_POOLS
#define BLIS_POOL_MC_L2_C (BLIS_POOL_MC_C + BLIS_POOL_KC_C)/2
#define BLIS_POOL_KC_L2_C (BLIS_POOL_MC_C + BLIS_POOL_KC_C)/2
#define BLIS_POOL_KC_L3_C (BLIS_POOL_NC_C + BLIS_POOL_KC_C)/2
#define BLIS_POOL_NC_L3_C (BLIS_POOL_NC_C + BLIS_POOL_KC_C)/2
#define BLIS_POOL_NR_C BLIS_PACKDIM_NR_C
#define BLIS_POOL_MR_C BLIS_PACKDIM_MR_C
#endif


//
// Compute pool dimensions for double complex
//
#define BLIS_POOL_MC_Z     ( ( BLIS_MAXIMUM_MC_Z * BLIS_PACKDIM_MAXR_Z ) \
                                                 / BLIS_DEFAULT_MAXR_Z )
#define BLIS_POOL_NC_Z     ( ( BLIS_MAXIMUM_NC_Z * BLIS_PACKDIM_MAXR_Z ) \
                                                 / BLIS_DEFAULT_MAXR_Z )
#define BLIS_POOL_KC_Z     ( ( BLIS_MAXIMUM_KC_Z * BLIS_PACKDIM_KR_Z   ) \
                                                 / BLIS_DEFAULT_KR_Z   )

#ifdef BLIS_ENABLE_C66X_MEM_POOLS
#define BLIS_POOL_MC_L2_Z (BLIS_POOL_MC_Z + BLIS_POOL_KC_Z)/2
#define BLIS_POOL_KC_L2_Z (BLIS_POOL_MC_Z + BLIS_POOL_KC_Z)/2
#define BLIS_POOL_KC_L3_Z (BLIS_POOL_NC_Z + BLIS_POOL_KC_Z)/2
#define BLIS_POOL_NC_L3_Z (BLIS_POOL_NC_Z + BLIS_POOL_KC_Z)/2
#define BLIS_POOL_NR_Z BLIS_PACKDIM_NR_Z
#define BLIS_POOL_MR_Z BLIS_PACKDIM_MR_Z
#endif

//
// Compute pool dimensions for single complex (4m)
//
#define BLIS_POOL_4M_MC_C  ( ( BLIS_MAXIMUM_4M_MC_C * BLIS_PACKDIM_MAXR_S ) \
                                                    / BLIS_DEFAULT_MAXR_S )
#define BLIS_POOL_4M_NC_C  ( ( BLIS_MAXIMUM_4M_NC_C * BLIS_PACKDIM_MAXR_S ) \
                                                    / BLIS_DEFAULT_MAXR_S )
#define BLIS_POOL_4M_KC_C  ( ( BLIS_MAXIMUM_4M_KC_C * BLIS_PACKDIM_KR_S   ) \
                                                    / BLIS_DEFAULT_KR_S   )

#ifdef BLIS_ENABLE_C66X_MEM_POOLS
#define BLIS_POOL_4M_MC_L2_C (BLIS_POOL_4M_MC_C + BLIS_POOL_4M_KC_C)/2
#define BLIS_POOL_4M_KC_L2_C (BLIS_POOL_4M_MC_C + BLIS_POOL_4M_KC_C)/2
#define BLIS_POOL_4M_KC_L3_C (BLIS_POOL_4M_NC_C + BLIS_POOL_4M_KC_C)/2
#define BLIS_POOL_4M_NC_L3_C (BLIS_POOL_4M_NC_C + BLIS_POOL_4M_KC_C)/2
#endif


//
// Compute pool dimensions for double complex (4m)
//
#define BLIS_POOL_4M_MC_Z  ( ( BLIS_MAXIMUM_4M_MC_Z * BLIS_PACKDIM_MAXR_D ) \
                                                    / BLIS_DEFAULT_MAXR_D )
#define BLIS_POOL_4M_NC_Z  ( ( BLIS_MAXIMUM_4M_NC_Z * BLIS_PACKDIM_MAXR_D ) \
                                                    / BLIS_DEFAULT_MAXR_D )
#define BLIS_POOL_4M_KC_Z  ( ( BLIS_MAXIMUM_4M_KC_Z * BLIS_PACKDIM_KR_D   ) \
                                                    / BLIS_DEFAULT_KR_D   )
#ifdef BLIS_ENABLE_C66X_MEM_POOLS
#define BLIS_POOL_4M_MC_L2_Z (BLIS_POOL_4M_MC_Z + BLIS_POOL_4M_KC_Z)/2
#define BLIS_POOL_4M_KC_L2_Z (BLIS_POOL_4M_MC_Z + BLIS_POOL_4M_KC_Z)/2
#define BLIS_POOL_4M_KC_L3_Z (BLIS_POOL_4M_NC_Z + BLIS_POOL_4M_KC_Z)/2
#define BLIS_POOL_4M_NC_L3_Z (BLIS_POOL_4M_NC_Z + BLIS_POOL_4M_KC_Z)/2
#endif


//
// Compute pool dimensions for single complex (3m)
//
#define BLIS_POOL_3M_MC_C  ( ( BLIS_MAXIMUM_3M_MC_C * BLIS_PACKDIM_MAXR_S ) \
                                                    / BLIS_DEFAULT_MAXR_S )
#define BLIS_POOL_3M_NC_C  ( ( BLIS_MAXIMUM_3M_NC_C * BLIS_PACKDIM_MAXR_S ) \
                                                    / BLIS_DEFAULT_MAXR_S )
#define BLIS_POOL_3M_KC_C  ( ( BLIS_MAXIMUM_3M_KC_C * BLIS_PACKDIM_KR_S   ) \
                                                    / BLIS_DEFAULT_KR_S   )
#ifdef BLIS_ENABLE_C66X_MEM_POOLS
#define BLIS_POOL_3M_MC_L2_C (BLIS_POOL_4M_MC_C + BLIS_POOL_4M_KC_C)/2
#define BLIS_POOL_3M_KC_L2_C (BLIS_POOL_4M_MC_C + BLIS_POOL_4M_KC_C)/2
#define BLIS_POOL_3M_KC_L3_C (BLIS_POOL_4M_NC_C + BLIS_POOL_4M_KC_C)/2
#define BLIS_POOL_3M_NC_L3_C (BLIS_POOL_4M_NC_C + BLIS_POOL_4M_KC_C)/2
#endif

//
// Compute pool dimensions for double complex (3m)
//
#define BLIS_POOL_3M_MC_Z  ( ( BLIS_MAXIMUM_3M_MC_Z * BLIS_PACKDIM_MAXR_D ) \
                                                    / BLIS_DEFAULT_MAXR_D )
#define BLIS_POOL_3M_NC_Z  ( ( BLIS_MAXIMUM_3M_NC_Z * BLIS_PACKDIM_MAXR_D ) \
                                                    / BLIS_DEFAULT_MAXR_D )
#define BLIS_POOL_3M_KC_Z  ( ( BLIS_MAXIMUM_3M_KC_Z * BLIS_PACKDIM_KR_D   ) \
                                                    / BLIS_DEFAULT_KR_D   )

#ifdef BLIS_ENABLE_C66X_MEM_POOLS
#define BLIS_POOL_3M_MC_L2_Z (BLIS_POOL_3M_MC_Z + BLIS_POOL_3M_KC_Z)/2
#define BLIS_POOL_3M_KC_L2_Z (BLIS_POOL_3M_MC_Z + BLIS_POOL_3M_KC_Z)/2
#define BLIS_POOL_3M_KC_L3_Z (BLIS_POOL_3M_NC_Z + BLIS_POOL_3M_KC_Z)/2
#define BLIS_POOL_3M_NC_L3_Z (BLIS_POOL_3M_NC_Z + BLIS_POOL_3M_KC_Z)/2
#endif


// Now, we compute the size of each block/panel of A, B, and C for each
// datatype.

//
// Compute memory pool block sizes for single real.
//


#ifdef BLIS_ENABLE_C66X_MEM_POOLS

#if defined(MEM_MODEL_LARGE) 

#define BLIS_MK_BLOCK_SIZE_S ( bli_max( BLIS_POOL_MC_S*(BLIS_POOL_MC_S + BLIS_POOL_KC_S), \
		                               (BLIS_POOL_MC_S + BLIS_POOL_KC_S)*(BLIS_POOL_MC_S + BLIS_POOL_KC_S)/4 \
		                              ) * \
		                       BLIS_SIZEOF_S \
		                     )

#define BLIS_KN_BLOCK_SIZE_S ( bli_max( BLIS_POOL_KC_S*(BLIS_POOL_KC_S + BLIS_POOL_NC_S), \
		                               (BLIS_POOL_KC_S + BLIS_POOL_NC_S)*(BLIS_POOL_KC_S + BLIS_POOL_NC_S)/4 \
		                              ) * \
		                       BLIS_SIZEOF_S \
		                     )

#elif defined (MEM_MODEL_SMALL) || defined (MEM_MODEL_MEDIUM)

//DMA is not used, and so we do not need to calculate the extra memory that needs to DMA'ed to rebuild symmetric matrices

#define BLIS_MK_BLOCK_SIZE_S ( BLIS_POOL_MC_S * \
                               ( BLIS_POOL_KC_S \
                               ) * \
                               BLIS_SIZEOF_S \
                             )

#define BLIS_KN_BLOCK_SIZE_S ( \
                               ( BLIS_POOL_KC_S \
                               ) * \
                               BLIS_POOL_NC_S * \
                               BLIS_SIZEOF_S \
                             )

#endif

#define BLIS_MN_BLOCK_SIZE_S ( BLIS_POOL_MC_S * \
                               BLIS_POOL_NC_S * \
                               BLIS_SIZEOF_S \
                             )

#define BLIS_MNR_BLOCK_SIZE_S ( BLIS_POOL_MC_S * \
                               BLIS_POOL_NR_S * \
                               BLIS_SIZEOF_S \
                             )

#define BLIS_KNR_BLOCK_SIZE_S ( BLIS_POOL_KC_S * \
                               BLIS_POOL_NR_S * \
                               BLIS_SIZEOF_S \
                               + BLIS_KNR_PANEL_BUFFER_L1_S \
                             )

#define BLIS_MRK_BLOCK_SIZE_S ( BLIS_POOL_MR_S * \
                               BLIS_POOL_KC_S * \
                               BLIS_SIZEOF_S \
                               + BLIS_MRK_BLOCK_BUFFER_L1_S \
                             )

#define BLIS_MRNR_BLOCK_SIZE_S ( BLIS_POOL_MR_S * \
                               BLIS_POOL_NR_S * \
                               BLIS_SIZEOF_S \
                               + BLIS_MRNR_BLOCK_BUFFER_L1_S \
                             )
#else
#define BLIS_MK_BLOCK_SIZE_S ( BLIS_POOL_MC_S * \
                               ( BLIS_POOL_KC_S + \
                                 ( BLIS_UPANEL_A_ALIGN_SIZE_S / \
                                   BLIS_SIZEOF_S ) \
                               ) * \
                               BLIS_SIZEOF_S \
                             )

#define BLIS_KN_BLOCK_SIZE_S ( \
                               ( BLIS_POOL_KC_S + \
                                 ( BLIS_UPANEL_B_ALIGN_SIZE_S / \
                                   BLIS_SIZEOF_S ) \
                               ) * \
                               BLIS_POOL_NC_S * \
                               BLIS_SIZEOF_S \
                             )
#define BLIS_MN_BLOCK_SIZE_S ( BLIS_POOL_MC_S * \
                               BLIS_POOL_NC_S * \
                               BLIS_SIZEOF_S \
                             )

#endif
//
// Compute memory pool block sizes for double real.
//


#ifdef BLIS_ENABLE_C66X_MEM_POOLS

#if defined(MEM_MODEL_LARGE) 

#define BLIS_MK_BLOCK_SIZE_D ( bli_max( BLIS_POOL_MC_D*(BLIS_POOL_MC_D + BLIS_POOL_KC_D), \
		                               (BLIS_POOL_MC_D + BLIS_POOL_KC_D)*(BLIS_POOL_MC_D + BLIS_POOL_KC_D)/4 \
		                              ) * \
		                       BLIS_SIZEOF_D \
		                     )

#define BLIS_KN_BLOCK_SIZE_D ( bli_max( BLIS_POOL_KC_D*(BLIS_POOL_KC_D + BLIS_POOL_NC_D), \
		                               (BLIS_POOL_KC_D + BLIS_POOL_NC_D)*(BLIS_POOL_KC_D + BLIS_POOL_NC_D)/4 \
		                              ) * \
		                       BLIS_SIZEOF_D \
		                     )

#elif defined (MEM_MODEL_SMALL) || defined (MEM_MODEL_MEDIUM)
#define BLIS_MK_BLOCK_SIZE_D ( BLIS_POOL_MC_D * \
                               ( BLIS_POOL_KC_D \
                               ) * \
                               BLIS_SIZEOF_D \
                             )

#define BLIS_KN_BLOCK_SIZE_D ( \
                               ( BLIS_POOL_KC_D \
                               ) * \
                               BLIS_POOL_NC_D * \
                               BLIS_SIZEOF_D \
                             )

#endif

#define BLIS_MN_BLOCK_SIZE_D ( BLIS_POOL_MC_D * \
                               BLIS_POOL_NC_D * \
                               BLIS_SIZEOF_D \
                             )

#define BLIS_MNR_BLOCK_SIZE_D ( BLIS_POOL_MC_D * \
                               BLIS_POOL_NR_D * \
                               BLIS_SIZEOF_D \
                             )

#define BLIS_KNR_BLOCK_SIZE_D ( BLIS_POOL_KC_D * \
                               BLIS_POOL_NR_D * \
                               BLIS_SIZEOF_D \
                               + BLIS_KNR_PANEL_BUFFER_L1_D \
                             )
#define BLIS_MRK_BLOCK_SIZE_D ( BLIS_POOL_MR_D * \
                               BLIS_POOL_KC_D * \
                               BLIS_SIZEOF_D \
                               + BLIS_MRK_BLOCK_BUFFER_L1_D \
                             )

#define BLIS_MRNR_BLOCK_SIZE_D ( BLIS_POOL_MR_D * \
                               BLIS_POOL_NR_D * \
                               BLIS_SIZEOF_D \
                               + BLIS_MRNR_BLOCK_BUFFER_L1_D \
                             )
#else
#define BLIS_MK_BLOCK_SIZE_D ( BLIS_POOL_MC_D * \
                               ( BLIS_POOL_KC_D + \
                                 ( BLIS_UPANEL_A_ALIGN_SIZE_D / \
                                   BLIS_SIZEOF_D ) \
                               ) * \
                               BLIS_SIZEOF_D \
                             )

#define BLIS_KN_BLOCK_SIZE_D ( \
                               ( BLIS_POOL_KC_D + \
                                 ( BLIS_UPANEL_B_ALIGN_SIZE_D / \
                                   BLIS_SIZEOF_D ) \
                               ) * \
                               BLIS_POOL_NC_D * \
                               BLIS_SIZEOF_D \
                             )
#define BLIS_MN_BLOCK_SIZE_D ( BLIS_POOL_MC_D * \
                               BLIS_POOL_NC_D * \
                               BLIS_SIZEOF_D \
                             )
#endif

//
// Compute memory pool block sizes for single complex.
//



#ifdef BLIS_ENABLE_C66X_MEM_POOLS

#if defined(MEM_MODEL_LARGE) 

#define BLIS_MK_BLOCK_SIZE_C ( bli_max( BLIS_POOL_MC_C*(BLIS_POOL_MC_C + BLIS_POOL_KC_C), \
		                               (BLIS_POOL_MC_C + BLIS_POOL_KC_C)*(BLIS_POOL_MC_C + BLIS_POOL_KC_C)/4 \
		                              ) * \
		                       BLIS_SIZEOF_C \
		                     )

#define BLIS_KN_BLOCK_SIZE_C ( bli_max( BLIS_POOL_KC_C*(BLIS_POOL_KC_C + BLIS_POOL_NC_C), \
		                               (BLIS_POOL_KC_C + BLIS_POOL_NC_C)*(BLIS_POOL_KC_C + BLIS_POOL_NC_C)/4 \
		                              ) * \
		                       BLIS_SIZEOF_D \
		                     )

#elif defined (MEM_MODEL_SMALL) || defined (MEM_MODEL_MEDIUM)

#define BLIS_MK_BLOCK_SIZE_C ( BLIS_POOL_MC_C * \
                               ( BLIS_POOL_KC_C \
                               ) * \
                               BLIS_SIZEOF_C \
                             )

#define BLIS_KN_BLOCK_SIZE_C ( \
                               ( BLIS_POOL_KC_C \
                               ) * \
                               BLIS_POOL_NC_C * \
                               BLIS_SIZEOF_C \
                             )
#endif

#define BLIS_MN_BLOCK_SIZE_C ( BLIS_POOL_MC_C * \
                               BLIS_POOL_NC_C * \
                               BLIS_SIZEOF_C \
                             )

#define BLIS_MNR_BLOCK_SIZE_C ( BLIS_POOL_MC_C * \
                               BLIS_POOL_NR_C * \
                               BLIS_SIZEOF_C \
                             )

#define BLIS_KNR_BLOCK_SIZE_C ( BLIS_POOL_KC_C * \
                               BLIS_POOL_NR_C * \
                               BLIS_SIZEOF_C \
                               + BLIS_KNR_PANEL_BUFFER_L1_C \
                             )
#define BLIS_MRK_BLOCK_SIZE_C ( BLIS_POOL_MR_C * \
                               BLIS_POOL_KC_C * \
                               BLIS_SIZEOF_C \
                               + BLIS_MRK_BLOCK_BUFFER_L1_C \
                             )

#define BLIS_MRNR_BLOCK_SIZE_C ( BLIS_POOL_MR_C * \
                               BLIS_POOL_NR_C * \
                               BLIS_SIZEOF_C \
                               + BLIS_MRNR_BLOCK_BUFFER_L1_C \
                             )
#else
#define BLIS_MK_BLOCK_SIZE_C ( BLIS_POOL_MC_C * \
                               ( BLIS_POOL_KC_C + \
                                 ( BLIS_UPANEL_A_ALIGN_SIZE_C / \
                                   BLIS_SIZEOF_C ) \
                               ) * \
                               BLIS_SIZEOF_C \
                             )

#define BLIS_KN_BLOCK_SIZE_C ( \
                               ( BLIS_POOL_KC_C + \
                                 ( BLIS_UPANEL_B_ALIGN_SIZE_C / \
                                   BLIS_SIZEOF_C ) \
                               ) * \
                               BLIS_POOL_NC_C * \
                               BLIS_SIZEOF_C \
                             )
#define BLIS_MN_BLOCK_SIZE_C ( BLIS_POOL_MC_C * \
                               BLIS_POOL_NC_C * \
                               BLIS_SIZEOF_C \
                             )
#endif
//
// Compute memory pool block sizes for double complex.
//



#ifdef BLIS_ENABLE_C66X_MEM_POOLS

#if defined(MEM_MODEL_LARGE) 

#define BLIS_MK_BLOCK_SIZE_Z ( bli_max( BLIS_POOL_MC_Z * (BLIS_POOL_MC_Z + BLIS_POOL_KC_Z), \
		                               (BLIS_POOL_MC_Z + BLIS_POOL_KC_Z)*(BLIS_POOL_MC_Z + BLIS_POOL_KC_Z)/4 \
		                              ) * \
		                       BLIS_SIZEOF_Z \
		                     )

#define BLIS_KN_BLOCK_SIZE_Z ( bli_max( BLIS_POOL_KC_Z*(BLIS_POOL_KC_Z + BLIS_POOL_NC_Z), \
		                               (BLIS_POOL_KC_Z + BLIS_POOL_NC_Z)*(BLIS_POOL_KC_Z + BLIS_POOL_NC_Z)/4 \
		                              ) * \
		                       BLIS_SIZEOF_Z \
		                     )

#elif defined (MEM_MODEL_SMALL) || defined (MEM_MODEL_MEDIUM)

#define BLIS_MK_BLOCK_SIZE_Z ( BLIS_POOL_MC_Z * \
                               ( BLIS_POOL_KC_Z \
                               ) * \
                               BLIS_SIZEOF_Z \
                             )

#define BLIS_KN_BLOCK_SIZE_Z ( \
                               ( BLIS_POOL_KC_Z \
                               ) * \
                               BLIS_POOL_NC_Z * \
                               BLIS_SIZEOF_Z \
                             )

#endif

#define BLIS_MN_BLOCK_SIZE_Z ( BLIS_POOL_MC_Z * \
                               BLIS_POOL_NC_Z * \
                               BLIS_SIZEOF_Z \
                             )

#define BLIS_MNR_BLOCK_SIZE_Z ( BLIS_POOL_MC_Z * \
                               BLIS_POOL_NR_Z * \
                               BLIS_SIZEOF_Z \
                             )

#define BLIS_KNR_BLOCK_SIZE_Z ( BLIS_POOL_KC_Z * \
                               BLIS_POOL_NR_Z * \
                               BLIS_SIZEOF_Z \
                               + BLIS_KNR_PANEL_BUFFER_L1_Z \
                             )
#define BLIS_MRK_BLOCK_SIZE_Z ( BLIS_POOL_MR_Z * \
                               BLIS_POOL_KC_Z * \
                               BLIS_SIZEOF_Z \
                               + BLIS_MRK_BLOCK_BUFFER_L1_Z \
                             )

#define BLIS_MRNR_BLOCK_SIZE_Z ( BLIS_POOL_MR_Z * \
                               BLIS_POOL_NR_Z * \
                               BLIS_SIZEOF_Z \
                               + BLIS_MRNR_BLOCK_BUFFER_L1_Z \
                             )
#else
#define BLIS_MK_BLOCK_SIZE_Z ( BLIS_POOL_MC_Z * \
                               ( BLIS_POOL_KC_Z + \
                                 ( BLIS_UPANEL_A_ALIGN_SIZE_Z / \
                                   BLIS_SIZEOF_Z ) \
                               ) * \
                               BLIS_SIZEOF_Z \
                             )

#define BLIS_KN_BLOCK_SIZE_Z ( \
                               ( BLIS_POOL_KC_Z + \
                                 ( BLIS_UPANEL_B_ALIGN_SIZE_Z / \
                                   BLIS_SIZEOF_Z ) \
                               ) * \
                               BLIS_POOL_NC_Z * \
                               BLIS_SIZEOF_Z \
                             )
#define BLIS_MN_BLOCK_SIZE_Z ( BLIS_POOL_MC_Z * \
                               BLIS_POOL_NC_Z * \
                               BLIS_SIZEOF_Z \
                             )
#endif

//
// Compute memory pool block sizes for single complex (4m).
//
#ifdef BLIS_ENABLE_C66X_MEM_POOLS

#if defined(MEM_MODEL_LARGE) 

#define BLIS_MK_BLOCK_SIZE_4M_C ( bli_max( BLIS_POOL_4M_MC_C*(BLIS_POOL_4M_MC_C + BLIS_POOL_4M_KC_C), \
		                               (BLIS_POOL_4M_MC_C + BLIS_POOL_4M_KC_C)*(BLIS_POOL_4M_MC_C + BLIS_POOL_4M_KC_C)/4 \
		                              ) * \
		                       BLIS_SIZEOF_C \
		                     )

#define BLIS_KN_BLOCK_SIZE_4M_C ( bli_max( BLIS_POOL_4M_KC_C*(BLIS_POOL_4M_KC_C + BLIS_POOL_4M_NC_C), \
		                               (BLIS_POOL_4M_KC_C + BLIS_POOL_4M_NC_C)*(BLIS_POOL_4M_KC_C + BLIS_POOL_4M_NC_C)/4 \
		                              ) * \
		                       BLIS_SIZEOF_C \
		                     )
#elif defined (MEM_MODEL_SMALL) || defined (MEM_MODEL_MEDIUM)
#define BLIS_MK_BLOCK_SIZE_4M_C ( BLIS_POOL_4M_MC_C * \
                                  ( BLIS_POOL_4M_KC_C \
                                  ) * \
                                  BLIS_SIZEOF_C \
                                )

#define BLIS_KN_BLOCK_SIZE_4M_C ( \
                                  ( BLIS_POOL_4M_KC_C \
                                  ) * \
                                  BLIS_POOL_4M_NC_C * \
                                  BLIS_SIZEOF_C \
                                )
#endif



#define BLIS_MN_BLOCK_SIZE_4M_C ( BLIS_POOL_4M_MC_C * \
                                  BLIS_POOL_4M_NC_C * \
                                  BLIS_SIZEOF_C \
                                )
#else
#define BLIS_MK_BLOCK_SIZE_4M_C ( BLIS_POOL_4M_MC_C * \
                                  ( BLIS_POOL_4M_KC_C + \
                                    ( BLIS_UPANEL_A_ALIGN_SIZE_C / \
                                      BLIS_SIZEOF_C ) \
                                  ) * \
                                  BLIS_SIZEOF_C \
                                )

#define BLIS_KN_BLOCK_SIZE_4M_C ( \
                                  ( BLIS_POOL_4M_KC_C + \
                                    ( BLIS_UPANEL_B_ALIGN_SIZE_C / \
                                      BLIS_SIZEOF_C ) \
                                  ) * \
                                  BLIS_POOL_4M_NC_C * \
                                  BLIS_SIZEOF_C \
                                )
#define BLIS_MN_BLOCK_SIZE_4M_C ( BLIS_POOL_4M_MC_C * \
                                  BLIS_POOL_4M_NC_C * \
                                  BLIS_SIZEOF_C \
                                )

#endif

//
// Compute memory pool block sizes for double complex (4m).
//
#ifdef BLIS_ENABLE_C66X_MEM_POOLS

#if defined(MEM_MODEL_LARGE) 

#define BLIS_MK_BLOCK_SIZE_4M_Z ( bli_max( BLIS_POOL_4M_MC_Z*(BLIS_POOL_4M_MC_Z + BLIS_POOL_4M_KC_Z), \
		                               (BLIS_POOL_4M_MC_Z + BLIS_POOL_4M_KC_Z)*(BLIS_POOL_4M_MC_Z + BLIS_POOL_4M_KC_Z)/4 \
		                              ) * \
		                       BLIS_SIZEOF_Z \
		                     )

#define BLIS_KN_BLOCK_SIZE_4M_Z ( bli_max( BLIS_POOL_4M_KC_Z*(BLIS_POOL_4M_KC_Z + BLIS_POOL_4M_NC_Z), \
		                               (BLIS_POOL_4M_KC_Z + BLIS_POOL_4M_NC_Z)*(BLIS_POOL_4M_KC_Z + BLIS_POOL_4M_NC_Z)/4 \
		                              ) * \
		                       BLIS_SIZEOF_Z \
		                     )

#elif defined (MEM_MODEL_SMALL) || defined (MEM_MODEL_MEDIUM)

#define BLIS_MK_BLOCK_SIZE_4M_Z ( BLIS_POOL_4M_MC_Z * \
                                  ( BLIS_POOL_4M_KC_Z \
                                  ) * \
                                  BLIS_SIZEOF_Z \
                                )

#define BLIS_KN_BLOCK_SIZE_4M_Z ( \
                                  ( BLIS_POOL_4M_KC_Z \
                                  ) * \
                                  BLIS_POOL_4M_NC_Z * \
                                  BLIS_SIZEOF_Z \
                                )
#endif


#define BLIS_MN_BLOCK_SIZE_4M_Z ( BLIS_POOL_4M_MC_Z * \
                                  BLIS_POOL_4M_NC_Z * \
                                  BLIS_SIZEOF_Z \
                                )
#else
#define BLIS_MK_BLOCK_SIZE_4M_Z ( BLIS_POOL_4M_MC_Z * \
                                  ( BLIS_POOL_4M_KC_Z + \
                                    ( BLIS_UPANEL_A_ALIGN_SIZE_Z / \
                                      BLIS_SIZEOF_Z ) \
                                  ) * \
                                  BLIS_SIZEOF_Z \
                                )

#define BLIS_KN_BLOCK_SIZE_4M_Z ( \
                                  ( BLIS_POOL_4M_KC_Z + \
                                    ( BLIS_UPANEL_B_ALIGN_SIZE_Z / \
                                      BLIS_SIZEOF_Z ) \
                                  ) * \
                                  BLIS_POOL_4M_NC_Z * \
                                  BLIS_SIZEOF_Z \
                                )
#define BLIS_MN_BLOCK_SIZE_4M_Z ( BLIS_POOL_4M_MC_Z * \
                                  BLIS_POOL_4M_NC_Z * \
                                  BLIS_SIZEOF_Z \
                                )
#endif

//
// Compute memory pool block sizes for single complex (3m).
//

// NOTE: We scale by 3/2 because 3m requires 50% more space than 4m.
#ifdef BLIS_ENABLE_C66X_MEM_POOLS

#if defined(MEM_MODEL_LARGE) 

#define BLIS_MK_BLOCK_SIZE_3M_C ( bli_max( BLIS_POOL_3M_MC_C*(BLIS_POOL_3M_MC_C + BLIS_POOL_3M_KC_C), \
		                               (BLIS_POOL_3M_MC_C + BLIS_POOL_3M_KC_C)*(BLIS_POOL_3M_MC_C + BLIS_POOL_3M_KC_C)/4 \
		                              ) * \
		                          BLIS_SIZEOF_C * \
                                  3 / 2 \
		                         )

#define BLIS_KN_BLOCK_SIZE_3M_C ( bli_max( BLIS_POOL_3M_KC_C*(BLIS_POOL_3M_KC_C + BLIS_POOL_3M_NC_C), \
		                               (BLIS_POOL_3M_KC_C + BLIS_POOL_3M_NC_C)*(BLIS_POOL_3M_KC_C + BLIS_POOL_3M_NC_C)/4 \
		                              ) * \
		                       BLIS_SIZEOF_C * \
                                  3 / 2 \
		                     )

#elif defined (MEM_MODEL_SMALL) || defined (MEM_MODEL_MEDIUM)

#define BLIS_MK_BLOCK_SIZE_3M_C ( BLIS_POOL_3M_MC_C * \
                                  ( BLIS_POOL_3M_KC_C \
                                  ) * \
                                  ( BLIS_SIZEOF_C * \
                                    3 \
                                  ) / 2 \
                                )

#define BLIS_KN_BLOCK_SIZE_3M_C ( \
                                  ( BLIS_POOL_3M_KC_C \
                                  ) * \
                                  BLIS_POOL_3M_NC_C * \
                                  ( BLIS_SIZEOF_C * \
                                    3 \
                                  ) / 2 \
                                )
#endif

#define BLIS_MN_BLOCK_SIZE_3M_C ( BLIS_POOL_3M_MC_C * \
                                  BLIS_POOL_3M_NC_C * \
                                  ( BLIS_SIZEOF_C * \
                                    3 \
                                  ) / 2 \
                                )
#else
#define BLIS_MK_BLOCK_SIZE_3M_C ( BLIS_POOL_3M_MC_C * \
                                  ( BLIS_POOL_3M_KC_C + \
                                    ( BLIS_UPANEL_A_ALIGN_SIZE_C / \
                                      BLIS_SIZEOF_C ) \
                                  ) * \
                                  ( BLIS_SIZEOF_C * \
                                    3 \
                                  ) / 2 \
                                )

#define BLIS_KN_BLOCK_SIZE_3M_C ( \
                                  ( BLIS_POOL_3M_KC_C + \
                                    ( BLIS_UPANEL_B_ALIGN_SIZE_C / \
                                      BLIS_SIZEOF_C ) \
                                  ) * \
                                  BLIS_POOL_3M_NC_C * \
                                  ( BLIS_SIZEOF_C * \
                                    3 \
                                  ) / 2 \
                                )
#define BLIS_MN_BLOCK_SIZE_3M_C ( BLIS_POOL_3M_MC_C * \
                                  BLIS_POOL_3M_NC_C * \
                                  ( BLIS_SIZEOF_C * \
                                    3 \
                                  ) / 2 \
                                )
#endif

//
// Compute memory pool block sizes for double complex (3m).
//

// NOTE: We scale by 3/2 because 3m requires 50% more space than 4m.

#ifdef BLIS_ENABLE_C66X_MEM_POOLS

#if defined(MEM_MODEL_LARGE) 

#define BLIS_MK_BLOCK_SIZE_3M_Z ( bli_max( BLIS_POOL_3M_MC_Z*(BLIS_POOL_3M_MC_Z + BLIS_POOL_3M_KC_Z), \
		                               (BLIS_POOL_3M_MC_Z + BLIS_POOL_3M_KC_Z)*(BLIS_POOL_3M_MC_Z + BLIS_POOL_3M_KC_Z) / 4 \
		                              ) * \
		                          BLIS_SIZEOF_Z * \
                                  3 / 2 \
		                         )

#define BLIS_KN_BLOCK_SIZE_3M_Z ( bli_max( BLIS_POOL_3M_KC_Z*(BLIS_POOL_3M_KC_Z + BLIS_POOL_3M_NC_Z), \
		                               (BLIS_POOL_3M_KC_Z + BLIS_POOL_3M_NC_Z)*(BLIS_POOL_3M_KC_Z + BLIS_POOL_3M_NC_Z)/4 \
		                              ) * \
		                       BLIS_SIZEOF_Z * \
                                  3 / 2 \
		                     )

#elif defined (MEM_MODEL_SMALL) || defined (MEM_MODEL_MEDIUM)
#define BLIS_MK_BLOCK_SIZE_3M_Z ( BLIS_POOL_3M_MC_Z * \
                                  ( BLIS_POOL_3M_KC_Z \
                                  ) * \
                                  ( BLIS_SIZEOF_Z * \
                                    3 \
                                  ) / 2 \
                                )


#define BLIS_KN_BLOCK_SIZE_3M_Z ( \
                                  ( BLIS_POOL_3M_KC_Z \
                                  ) * \
                                  BLIS_POOL_3M_NC_Z * \
                                  ( BLIS_SIZEOF_Z * \
                                    3 \
                                  ) / 2 \
                                )
#endif


#define BLIS_MN_BLOCK_SIZE_3M_Z ( BLIS_POOL_3M_MC_Z * \
                                  BLIS_POOL_3M_NC_Z * \
                                  ( BLIS_SIZEOF_Z * \
                                    3 \
                                  ) / 2 \
                                )
#else
#define BLIS_MK_BLOCK_SIZE_3M_Z ( BLIS_POOL_3M_MC_Z * \
                                  ( BLIS_POOL_3M_KC_Z + \
                                    ( BLIS_UPANEL_A_ALIGN_SIZE_Z / \
                                      BLIS_SIZEOF_Z ) \
                                  ) * \
                                  ( BLIS_SIZEOF_Z * \
                                    3 \
                                  ) / 2 \
                                )


#define BLIS_KN_BLOCK_SIZE_3M_Z ( \
                                  ( BLIS_POOL_3M_KC_Z + \
                                    ( BLIS_UPANEL_B_ALIGN_SIZE_Z / \
                                      BLIS_SIZEOF_Z ) \
                                  ) * \
                                  BLIS_POOL_3M_NC_Z * \
                                  ( BLIS_SIZEOF_Z * \
                                    3 \
                                  ) / 2 \
                                )
#define BLIS_MN_BLOCK_SIZE_3M_Z ( BLIS_POOL_3M_MC_Z * \
                                  BLIS_POOL_3M_NC_Z * \
                                  ( BLIS_SIZEOF_Z * \
                                    3 \
                                  ) / 2 \
                                )
#endif


// -- Maximum block size search ------------------------------------------------

// In this section, we find the largest of each block size.

//
// Find the largest block size for blocks of A.
//
#define BLIS_MK_BLOCK_SIZE BLIS_MK_BLOCK_SIZE_S
#if     BLIS_MK_BLOCK_SIZE_D > BLIS_MK_BLOCK_SIZE
#undef  BLIS_MK_BLOCK_SIZE
#define BLIS_MK_BLOCK_SIZE BLIS_MK_BLOCK_SIZE_D
#endif
#if     BLIS_MK_BLOCK_SIZE_C > BLIS_MK_BLOCK_SIZE
#undef  BLIS_MK_BLOCK_SIZE
#define BLIS_MK_BLOCK_SIZE BLIS_MK_BLOCK_SIZE_C
#endif
#if     BLIS_MK_BLOCK_SIZE_Z > BLIS_MK_BLOCK_SIZE
#undef  BLIS_MK_BLOCK_SIZE
#define BLIS_MK_BLOCK_SIZE BLIS_MK_BLOCK_SIZE_Z
#endif
#if     BLIS_MK_BLOCK_SIZE_4M_C > BLIS_MK_BLOCK_SIZE
#undef  BLIS_MK_BLOCK_SIZE
#define BLIS_MK_BLOCK_SIZE BLIS_MK_BLOCK_SIZE_4M_C
#endif
#if     BLIS_MK_BLOCK_SIZE_4M_Z > BLIS_MK_BLOCK_SIZE
#undef  BLIS_MK_BLOCK_SIZE
#define BLIS_MK_BLOCK_SIZE BLIS_MK_BLOCK_SIZE_4M_Z
#endif
#if     BLIS_MK_BLOCK_SIZE_3M_C > BLIS_MK_BLOCK_SIZE
#undef  BLIS_MK_BLOCK_SIZE
#define BLIS_MK_BLOCK_SIZE BLIS_MK_BLOCK_SIZE_3M_C
#endif
#if     BLIS_MK_BLOCK_SIZE_3M_Z > BLIS_MK_BLOCK_SIZE
#undef  BLIS_MK_BLOCK_SIZE
#define BLIS_MK_BLOCK_SIZE BLIS_MK_BLOCK_SIZE_3M_Z
#endif


// Finding the largest micro BLOCK of A
#ifdef BLIS_ENABLE_C66X_MEM_POOLS
#define BLIS_MRK_BLOCK_SIZE BLIS_MRK_BLOCK_SIZE_S
#if     BLIS_MRK_BLOCK_SIZE_D > BLIS_MRK_BLOCK_SIZE
#undef  BLIS_MRK_BLOCK_SIZE
#define BLIS_MRK_BLOCK_SIZE BLIS_MRK_BLOCK_SIZE_D
#endif
#if     BLIS_MRK_BLOCK_SIZE_C > BLIS_MRK_BLOCK_SIZE
#undef  BLIS_MRK_BLOCK_SIZE
#define BLIS_MRK_BLOCK_SIZE BLIS_MRK_BLOCK_SIZE_C
#endif
#if     BLIS_MRK_BLOCK_SIZE_Z > BLIS_MRK_BLOCK_SIZE
#undef  BLIS_MRK_BLOCK_SIZE
#define BLIS_MRK_BLOCK_SIZE BLIS_MRK_BLOCK_SIZE_Z
#endif
#endif

//
// Find the largest block size for panels of B.
//
#define BLIS_KN_BLOCK_SIZE BLIS_KN_BLOCK_SIZE_S
#if     BLIS_KN_BLOCK_SIZE_D > BLIS_KN_BLOCK_SIZE
#undef  BLIS_KN_BLOCK_SIZE
#define BLIS_KN_BLOCK_SIZE BLIS_KN_BLOCK_SIZE_D
#endif
#if     BLIS_KN_BLOCK_SIZE_C > BLIS_KN_BLOCK_SIZE
#undef  BLIS_KN_BLOCK_SIZE
#define BLIS_KN_BLOCK_SIZE BLIS_KN_BLOCK_SIZE_C
#endif
#if     BLIS_KN_BLOCK_SIZE_Z > BLIS_KN_BLOCK_SIZE
#undef  BLIS_KN_BLOCK_SIZE
#define BLIS_KN_BLOCK_SIZE BLIS_KN_BLOCK_SIZE_Z
#endif
#if     BLIS_KN_BLOCK_SIZE_4M_C > BLIS_KN_BLOCK_SIZE
#undef  BLIS_KN_BLOCK_SIZE
#define BLIS_KN_BLOCK_SIZE BLIS_KN_BLOCK_SIZE_4M_C
#endif
#if     BLIS_KN_BLOCK_SIZE_4M_Z > BLIS_KN_BLOCK_SIZE
#undef  BLIS_KN_BLOCK_SIZE
#define BLIS_KN_BLOCK_SIZE BLIS_KN_BLOCK_SIZE_4M_Z
#endif
#if     BLIS_KN_BLOCK_SIZE_3M_C > BLIS_KN_BLOCK_SIZE
#undef  BLIS_KN_BLOCK_SIZE
#define BLIS_KN_BLOCK_SIZE BLIS_KN_BLOCK_SIZE_3M_C
#endif
#if     BLIS_KN_BLOCK_SIZE_3M_Z > BLIS_KN_BLOCK_SIZE
#undef  BLIS_KN_BLOCK_SIZE
#define BLIS_KN_BLOCK_SIZE BLIS_KN_BLOCK_SIZE_3M_Z
#endif

// Finding the largest micro panel of B
#ifdef BLIS_ENABLE_C66X_MEM_POOLS

#define BLIS_KNR_BLOCK_SIZE BLIS_KNR_BLOCK_SIZE_S
#if     BLIS_KNR_BLOCK_SIZE_D > BLIS_KNR_BLOCK_SIZE
#undef  BLIS_KNR_BLOCK_SIZE
#define BLIS_KNR_BLOCK_SIZE BLIS_KNR_BLOCK_SIZE_D
#endif
#if     BLIS_KNR_BLOCK_SIZE_C > BLIS_KNR_BLOCK_SIZE
#undef  BLIS_KNR_BLOCK_SIZE
#define BLIS_KNR_BLOCK_SIZE BLIS_KNR_BLOCK_SIZE_C
#endif
#if     BLIS_KNR_BLOCK_SIZE_Z > BLIS_KNR_BLOCK_SIZE
#undef  BLIS_KNR_BLOCK_SIZE
#define BLIS_KNR_BLOCK_SIZE BLIS_KNR_BLOCK_SIZE_Z
#endif
#endif

//
// Find the largest block size for panels of C.
//
#define BLIS_MN_BLOCK_SIZE BLIS_MN_BLOCK_SIZE_S
#if     BLIS_MN_BLOCK_SIZE_D > BLIS_MN_BLOCK_SIZE
#undef  BLIS_MN_BLOCK_SIZE
#define BLIS_MN_BLOCK_SIZE BLIS_MN_BLOCK_SIZE_D
#endif
#if     BLIS_MN_BLOCK_SIZE_C > BLIS_MN_BLOCK_SIZE
#undef  BLIS_MN_BLOCK_SIZE
#define BLIS_MN_BLOCK_SIZE BLIS_MN_BLOCK_SIZE_C
#endif
#if     BLIS_MN_BLOCK_SIZE_Z > BLIS_MN_BLOCK_SIZE
#undef  BLIS_MN_BLOCK_SIZE
#define BLIS_MN_BLOCK_SIZE BLIS_MN_BLOCK_SIZE_Z
#endif
#if     BLIS_MN_BLOCK_SIZE_4M_C > BLIS_MN_BLOCK_SIZE
#undef  BLIS_MN_BLOCK_SIZE
#define BLIS_MN_BLOCK_SIZE BLIS_MN_BLOCK_SIZE_4M_C
#endif
#if     BLIS_MN_BLOCK_SIZE_4M_Z > BLIS_MN_BLOCK_SIZE
#undef  BLIS_MN_BLOCK_SIZE
#define BLIS_MN_BLOCK_SIZE BLIS_MN_BLOCK_SIZE_4M_Z
#endif
#if     BLIS_MN_BLOCK_SIZE_3M_C > BLIS_MN_BLOCK_SIZE
#undef  BLIS_MN_BLOCK_SIZE
#define BLIS_MN_BLOCK_SIZE BLIS_MN_BLOCK_SIZE_3M_C
#endif
#if     BLIS_MN_BLOCK_SIZE_3M_Z > BLIS_MN_BLOCK_SIZE
#undef  BLIS_MN_BLOCK_SIZE
#define BLIS_MN_BLOCK_SIZE BLIS_MN_BLOCK_SIZE_3M_Z
#endif

// Finding the largest micro panel of C for L2
#ifdef BLIS_ENABLE_C66X_MEM_POOLS

#define BLIS_MNR_BLOCK_SIZE BLIS_MNR_BLOCK_SIZE_S
#if     BLIS_MNR_BLOCK_SIZE_D > BLIS_MNR_BLOCK_SIZE
#undef  BLIS_MNR_BLOCK_SIZE
#define BLIS_MNR_BLOCK_SIZE BLIS_MNR_BLOCK_SIZE_D
#endif
#if     BLIS_MNR_BLOCK_SIZE_C > BLIS_MNR_BLOCK_SIZE
#undef  BLIS_MNR_BLOCK_SIZE
#define BLIS_MNR_BLOCK_SIZE BLIS_MNR_BLOCK_SIZE_C
#endif
#if     BLIS_MNR_BLOCK_SIZE_Z > BLIS_MNR_BLOCK_SIZE
#undef  BLIS_MNR_BLOCK_SIZE
#define BLIS_MNR_BLOCK_SIZE BLIS_MNR_BLOCK_SIZE_Z
#endif
#endif

// Finding the largest micro panel of C for L1
#ifdef BLIS_ENABLE_C66X_MEM_POOLS

#define BLIS_MRNR_BLOCK_SIZE BLIS_MRNR_BLOCK_SIZE_S
#if     BLIS_MRNR_BLOCK_SIZE_D > BLIS_MRNR_BLOCK_SIZE
#undef  BLIS_MRNR_BLOCK_SIZE
#define BLIS_MRNR_BLOCK_SIZE BLIS_MRNR_BLOCK_SIZE_D
#endif
#if     BLIS_MRNR_BLOCK_SIZE_C > BLIS_MRNR_BLOCK_SIZE
#undef  BLIS_MRNR_BLOCK_SIZE
#define BLIS_MRNR_BLOCK_SIZE BLIS_MRNR_BLOCK_SIZE_C
#endif
#if     BLIS_MRNR_BLOCK_SIZE_Z > BLIS_MRNR_BLOCK_SIZE
#undef  BLIS_MRNR_BLOCK_SIZE
#define BLIS_MRNR_BLOCK_SIZE BLIS_MRNR_BLOCK_SIZE_Z
#endif
#endif


// -- Compute pool sizes -------------------------------------------------------


// Define each pool's total size using the block sizes determined above.
// These values are used in bli_mem.c to size the static memory pool
// arrays.

#ifdef BLIS_ENABLE_C66X_MEM_POOLS

//
// Pool for MC x KC blocks of A.
//
#define BLIS_MK_POOL_SIZE_L3  ( \
                             BLIS_NUM_MC_X_KC_BLOCKS_L3 * \
                             ( BLIS_MK_BLOCK_SIZE + \
                               BLIS_CONTIG_ADDR_ALIGN_SIZE \
                             ) + \
                             BLIS_MAX_PRELOAD_BYTE_OFFSET \
                           )

#define BLIS_MK_POOL_SIZE_L2  ( \
                             BLIS_NUM_MC_X_KC_BLOCKS_L2 * \
                             ( BLIS_MK_BLOCK_SIZE \
                               ) + \
                             BLIS_MAX_PRELOAD_BYTE_OFFSET \
                           )


#define BLIS_MK_POOL_SIZE_L1  ( \
                             BLIS_NUM_MR_X_KC_BLOCKS_L1 * \
                             ( BLIS_MRK_BLOCK_SIZE  \
                               ) \
                           )

#define BLIS_MK_POOL_SIZE  ( \
                             BLIS_NUM_MC_X_KC_BLOCKS * \
                             ( BLIS_MK_BLOCK_SIZE + \
                               BLIS_CONTIG_ADDR_ALIGN_SIZE \
                             ) + \
                             BLIS_MAX_PRELOAD_BYTE_OFFSET \
                           )

//
// Pool for KC x NC panels of B.
//
#define BLIS_KN_POOL_SIZE_L3  ( \
                             BLIS_NUM_KC_X_NC_BLOCKS_L3 * \
                             ( BLIS_KN_BLOCK_SIZE + \
                               BLIS_CONTIG_ADDR_ALIGN_SIZE \
                             ) + \
                             BLIS_MAX_PRELOAD_BYTE_OFFSET \
                           )

#define BLIS_KN_POOL_SIZE_L2  ( \
                             BLIS_NUM_KC_X_NC_BLOCKS_L2 * \
                             ( BLIS_KN_BLOCK_SIZE + \
                               BLIS_CONTIG_ADDR_ALIGN_SIZE \
                             ) + \
                             BLIS_MAX_PRELOAD_BYTE_OFFSET \
                           )

//For B panel in L1 the pool size must be KC*NR
#define BLIS_KN_POOL_SIZE_L1  ( \
                             BLIS_NUM_KC_X_NR_BLOCKS_L1 * \
                             ( BLIS_KNR_BLOCK_SIZE  \
                               ) \
                           )

#define BLIS_KN_POOL_SIZE  ( \
                             BLIS_NUM_KC_X_NC_BLOCKS * \
                             ( BLIS_KN_BLOCK_SIZE + \
                               BLIS_CONTIG_ADDR_ALIGN_SIZE \
                             ) + \
                             BLIS_MAX_PRELOAD_BYTE_OFFSET \
                           )

//
// Pool for MC x NC panels of C.
//
#define BLIS_MN_POOL_SIZE_L3  ( \
                             BLIS_NUM_MC_X_NC_BLOCKS_L3 * \
                             ( BLIS_MN_BLOCK_SIZE + \
                               BLIS_CONTIG_ADDR_ALIGN_SIZE \
                             ) + \
                             BLIS_MAX_PRELOAD_BYTE_OFFSET \
                           )

#define BLIS_MN_POOL_SIZE_L2  ( \
                             BLIS_NUM_MC_X_NC_BLOCKS_L2 * \
                             ( BLIS_MN_BLOCK_SIZE + \
                               BLIS_CONTIG_ADDR_ALIGN_SIZE \
                             ) + \
                             BLIS_MAX_PRELOAD_BYTE_OFFSET \
                           )


#define BLIS_MNR_POOL_SIZE_L2  ( \
                             BLIS_NUM_MC_X_NR_BLOCKS_L1 * \
                             ( BLIS_MNR_BLOCK_SIZE ) \
                           )

#define BLIS_MN_POOL_SIZE_L1  ( \
                             BLIS_NUM_MC_X_NC_BLOCKS_L1 * \
                             ( BLIS_MN_BLOCK_SIZE + \
                               BLIS_CONTIG_ADDR_ALIGN_SIZE \
                             ) \
                           )

#define BLIS_MN_POOL_SIZE  ( \
                             BLIS_NUM_MC_X_NC_BLOCKS * \
                             ( BLIS_MN_BLOCK_SIZE + \
                               BLIS_CONTIG_ADDR_ALIGN_SIZE \
                             ) + \
                             BLIS_MAX_PRELOAD_BYTE_OFFSET \
                           )

#else

//
// Pool for MC x KC blocks of A.
//
#define BLIS_MK_POOL_SIZE  ( \
                             BLIS_NUM_MC_X_KC_BLOCKS * \
                             ( BLIS_MK_BLOCK_SIZE + \
                               BLIS_CONTIG_ADDR_ALIGN_SIZE \
                             ) + \
                             BLIS_MAX_PRELOAD_BYTE_OFFSET \
                           )

//
// Pool for KC x NC panels of B.
//
#define BLIS_KN_POOL_SIZE  ( \
                             BLIS_NUM_KC_X_NC_BLOCKS * \
                             ( BLIS_KN_BLOCK_SIZE + \
                               BLIS_CONTIG_ADDR_ALIGN_SIZE \
                             ) + \
                             BLIS_MAX_PRELOAD_BYTE_OFFSET \
                           )

//
// Pool for MC x NC panels of C.
//
#define BLIS_MN_POOL_SIZE  ( \
                             BLIS_NUM_MC_X_NC_BLOCKS * \
                             ( BLIS_MN_BLOCK_SIZE + \
                               BLIS_CONTIG_ADDR_ALIGN_SIZE \
                             ) + \
                             BLIS_MAX_PRELOAD_BYTE_OFFSET \
                           )

#endif


#endif 
