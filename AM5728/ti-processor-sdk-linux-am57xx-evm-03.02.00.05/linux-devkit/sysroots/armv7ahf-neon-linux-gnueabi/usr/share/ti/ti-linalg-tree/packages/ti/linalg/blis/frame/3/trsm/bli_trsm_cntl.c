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


extern scalm_t*   scalm_cntl;

extern blksz_t*   gemm_mc;
extern blksz_t*   gemm_nc;
extern blksz_t*   gemm_kc;
extern blksz_t*   gemm_mr;
extern blksz_t*   gemm_nr;
extern blksz_t*   gemm_kr;

#ifdef BLIS_ENABLE_C66X_EDMA
#define BLIS_SGEMM_FORTRSM_UKERNEL bli_sgemm_ukernel_4x4
#define bli_sGEMM_FORTRSM_UKERNEL BLIS_SGEMM_FORTRSM_UKERNEL

#undef  GENTPROT
#define GENTPROT( ctype, ch, kername ) \
\
void PASTEMAC(ch,kername) \
     ( \
       dim_t           k, \
       ctype* restrict alpha, \
       ctype* restrict a, \
       ctype* restrict b, \
       ctype* restrict beta, \
       ctype* restrict c, inc_t rs_c, inc_t cs_c, \
       auxinfo_t*      data  \
     );

INSERT_GENTPROT_BASIC( GEMM_FORTRSM_UKERNEL )

blksz_t* trsm_mc;
blksz_t* trsm_nc;
blksz_t* trsm_kc;
blksz_t* trsm_mr;
blksz_t* trsm_nr;
blksz_t* trsm_kr;

func_t* gemm_fortrsm_ukrs;
#endif

extern func_t*    gemm_ukrs;

extern gemm_t*    gemm_cntl_bp_ke;

func_t*           gemmtrsm_l_ukrs;
func_t*           gemmtrsm_u_ukrs;

func_t*           trsm_l_ukrs;
func_t*           trsm_u_ukrs;

packm_t*          trsm_l_packa_cntl;
packm_t*          trsm_l_packb_cntl;

packm_t*          trsm_r_packa_cntl;
packm_t*          trsm_r_packb_cntl;

#ifdef BLIS_ENABLE_C66X_EDMA
extern dmam_t*	  gemm_dmaa_cntl;
extern dmam_t*	  gemm_dmab_cntl;
#endif

trsm_t*           trsm_cntl_bp_ke;

trsm_t*           trsm_l_cntl_op_bp;
trsm_t*           trsm_l_cntl_mm_op;
trsm_t*           trsm_l_cntl_vl_mm;

trsm_t*           trsm_r_cntl_op_bp;
trsm_t*           trsm_r_cntl_mm_op;
trsm_t*           trsm_r_cntl_vl_mm;

trsm_t*           trsm_l_cntl;
trsm_t*           trsm_r_cntl;


void bli_trsm_cntl_init()
{
#ifdef BLIS_ENABLE_C66X_EDMA
	trsm_mc = gemm_mc;
	trsm_nc = gemm_nc;
	trsm_kc = gemm_kc;

	trsm_mr
	=
	bli_blksz_obj_create( 4, 4,
	                      BLIS_DEFAULT_MR_D, BLIS_PACKDIM_MR_D,
                          BLIS_DEFAULT_MR_C, BLIS_PACKDIM_MR_C,
                          BLIS_DEFAULT_MR_Z, BLIS_PACKDIM_MR_Z );
	trsm_nr
	=
	bli_blksz_obj_create( 4, 4,
                          BLIS_DEFAULT_NR_D, BLIS_PACKDIM_NR_D,
                          BLIS_DEFAULT_NR_C, BLIS_PACKDIM_NR_C,
                          BLIS_DEFAULT_NR_Z, BLIS_PACKDIM_NR_Z );

	trsm_kr = gemm_kr;

	// Attach the register blksz_t objects as sub-blocksizes to the cache
	// blksz_t objects.
	bli_blksz_obj_attach_to( trsm_mr, trsm_mc );
	bli_blksz_obj_attach_to( trsm_nr, trsm_nc );
	bli_blksz_obj_attach_to( trsm_kr, trsm_kc );



	gemm_fortrsm_ukrs
		=
		bli_func_obj_create( BLIS_SGEMM_FORTRSM_UKERNEL, BLIS_SGEMM_UKERNEL_PREFERS_CONTIG_ROWS,
		                     BLIS_DGEMM_UKERNEL, BLIS_DGEMM_UKERNEL_PREFERS_CONTIG_ROWS,
		                     BLIS_CGEMM_UKERNEL, BLIS_CGEMM_UKERNEL_PREFERS_CONTIG_ROWS,
		                     BLIS_ZGEMM_UKERNEL, BLIS_ZGEMM_UKERNEL_PREFERS_CONTIG_ROWS );
#endif

	// Create function pointer objects for each datatype-specific
	// gemmtrsm_l and gemmtrsm_u micro-kernel.
	gemmtrsm_l_ukrs
	=
	bli_func_obj_create( BLIS_SGEMMTRSM_L_UKERNEL, FALSE,
	                     BLIS_DGEMMTRSM_L_UKERNEL, FALSE,
	                     BLIS_CGEMMTRSM_L_UKERNEL, FALSE,
	                     BLIS_ZGEMMTRSM_L_UKERNEL, FALSE );

	gemmtrsm_u_ukrs
	=
	bli_func_obj_create( BLIS_SGEMMTRSM_U_UKERNEL, FALSE,
	                     BLIS_DGEMMTRSM_U_UKERNEL, FALSE,
	                     BLIS_CGEMMTRSM_U_UKERNEL, FALSE,
	                     BLIS_ZGEMMTRSM_U_UKERNEL, FALSE );


	// Create function pointer objects for each datatype-specific
	// trsm_l and trsm_u micro-kernel.
	trsm_l_ukrs
	=
	bli_func_obj_create( BLIS_STRSM_L_UKERNEL, FALSE,
	                     BLIS_DTRSM_L_UKERNEL, FALSE,
	                     BLIS_CTRSM_L_UKERNEL, FALSE,
	                     BLIS_ZTRSM_L_UKERNEL, FALSE );

	trsm_u_ukrs
	=
	bli_func_obj_create( BLIS_STRSM_U_UKERNEL, FALSE,
	                     BLIS_DTRSM_U_UKERNEL, FALSE,
	                     BLIS_CTRSM_U_UKERNEL, FALSE,
	                     BLIS_ZTRSM_U_UKERNEL, FALSE );


	// Create control tree objects for packm operations (left side).
#ifdef BLIS_ENABLE_C66X_MEM_POOLS
	trsm_l_packa_cntl
	=
	bli_packm_cntl_obj_create( BLIS_BLOCKED,
	                           BLIS_VARIANT1,
	                           // IMPORTANT: n dim multiple must be mr to
	                           // support right and bottom-right edge cases
	                           trsm_mr,
	                           trsm_mr,
	                           TRUE,  // invert diagonal
	                           TRUE,  // reverse iteration if upper?
	                           FALSE, // reverse iteration if lower?
	                           BLIS_PACKED_ROW_PANELS,
	                           BLIS_BUFFER_FOR_A_BLOCK_L2 );

	trsm_l_packb_cntl
	=
	bli_packm_cntl_obj_create( BLIS_BLOCKED,
	                           BLIS_VARIANT1,
	                           // IMPORTANT: m dim multiple must be mr since
	                           // B_pack is updated (ie: serves as C) in trsm
	                           trsm_mr,
	                           trsm_nr,
	                           FALSE, // do NOT invert diagonal
	                           FALSE, // reverse iteration if upper?
	                           FALSE, // reverse iteration if lower?
	                           BLIS_PACKED_COL_PANELS,
	                           BLIS_BUFFER_FOR_B_PANEL_L3 );

	// Create control tree objects for packm operations (right side).
	trsm_r_packa_cntl
	=
	bli_packm_cntl_obj_create( BLIS_BLOCKED,
	                           BLIS_VARIANT1,
	                           trsm_nr,
	                           trsm_mr,
	                           FALSE, // do NOT invert diagonal
	                           FALSE, // reverse iteration if upper?
	                           FALSE, // reverse iteration if lower?
	                           BLIS_PACKED_ROW_PANELS,
	                           BLIS_BUFFER_FOR_A_BLOCK_L2 );

	trsm_r_packb_cntl
	=
	bli_packm_cntl_obj_create( BLIS_BLOCKED,
	                           BLIS_VARIANT1, // pack panels of B compactly
	                           trsm_mr,
	                           trsm_mr,
	                           TRUE,  // invert diagonal
	                           FALSE, // reverse iteration if upper?
	                           TRUE,  // reverse iteration if lower?
	                           BLIS_PACKED_COL_PANELS,
	                           BLIS_BUFFER_FOR_B_PANEL_L3 );
#else
	trsm_l_packa_cntl
	=
	bli_packm_cntl_obj_create( BLIS_BLOCKED,
	                           BLIS_VARIANT1,
	                           // IMPORTANT: n dim multiple must be mr to
	                           // support right and bottom-right edge cases
	                           gemm_mr,
	                           gemm_mr,
	                           TRUE,  // invert diagonal
	                           TRUE,  // reverse iteration if upper?
	                           FALSE, // reverse iteration if lower?
	                           BLIS_PACKED_ROW_PANELS,
	                           BLIS_BUFFER_FOR_A_BLOCK );

	trsm_l_packb_cntl
	=
	bli_packm_cntl_obj_create( BLIS_BLOCKED,
	                           BLIS_VARIANT1,
	                           // IMPORTANT: m dim multiple must be mr since
	                           // B_pack is updated (ie: serves as C) in trsm
	                           gemm_mr,
	                           gemm_nr,
	                           FALSE, // do NOT invert diagonal
	                           FALSE, // reverse iteration if upper?
	                           FALSE, // reverse iteration if lower?
	                           BLIS_PACKED_COL_PANELS,
	                           BLIS_BUFFER_FOR_B_PANEL );

	// Create control tree objects for packm operations (right side).
	trsm_r_packa_cntl
	=
	bli_packm_cntl_obj_create( BLIS_BLOCKED,
	                           BLIS_VARIANT1,
	                           gemm_nr,
	                           gemm_mr,
	                           FALSE, // do NOT invert diagonal
	                           FALSE, // reverse iteration if upper?
	                           FALSE, // reverse iteration if lower?
	                           BLIS_PACKED_ROW_PANELS,
	                           BLIS_BUFFER_FOR_A_BLOCK );

	trsm_r_packb_cntl
	=
	bli_packm_cntl_obj_create( BLIS_BLOCKED,
	                           BLIS_VARIANT1, // pack panels of B compactly
	                           gemm_mr,
	                           gemm_mr,
	                           TRUE,  // invert diagonal
	                           FALSE, // reverse iteration if upper?
	                           TRUE,  // reverse iteration if lower?
	                           BLIS_PACKED_COL_PANELS,
	                           BLIS_BUFFER_FOR_B_PANEL );
#endif

#ifdef BLIS_ENABLE_C66X_EDMA
	// Create control tree object for lowest-level block-panel kernel.
	trsm_cntl_bp_ke
	=
	bli_trsm_cntl_obj_create( BLIS_UNB_OPT,
	                          BLIS_VARIANT2,
	                          NULL,
	                          gemm_fortrsm_ukrs,
	                          gemmtrsm_l_ukrs,
	                          gemmtrsm_u_ukrs,
	                          NULL, NULL, NULL, NULL,
	                          NULL, NULL, NULL,
	                          NULL, NULL, NULL );

	// Create control tree object for outer panel (to block-panel)
	// problem (left side).
	trsm_l_cntl_op_bp
	=
	bli_trsm_cntl_obj_create( BLIS_BLOCKED,
	                          BLIS_VARIANT1,
	                          trsm_mc,
	                          gemm_fortrsm_ukrs, NULL, NULL,
	                          NULL,
	                          trsm_l_packa_cntl,
	                          trsm_l_packb_cntl,
	                          NULL,
	                          NULL,
	                          NULL,
	                          NULL,
	                          trsm_cntl_bp_ke,
	                          gemm_cntl_bp_ke,
	                          NULL );

	// Create control tree object for general problem via multiple
	// rank-k (outer panel) updates (left side).
	trsm_l_cntl_mm_op
	=
	bli_trsm_cntl_obj_create( BLIS_BLOCKED,
	                          BLIS_VARIANT3,
	                          trsm_kc,
	                          gemm_fortrsm_ukrs, NULL, NULL,
	                          NULL,
	                          NULL,
	                          NULL,
	                          NULL,
	                          NULL,
	                          NULL,
	                          NULL,
	                          trsm_l_cntl_op_bp,
	                          NULL,
	                          NULL );

	// Create control tree object for very large problem via multiple
	// general problems (left side).
	trsm_l_cntl_vl_mm
	=
	bli_trsm_cntl_obj_create( BLIS_BLOCKED,
	                          BLIS_VARIANT2,
	                          trsm_nc,
	                          gemm_fortrsm_ukrs, NULL, NULL,
	                          NULL,
	                          NULL,
	                          NULL,
	                          NULL,
	                          NULL,
	                          NULL,
	                          NULL,
	                          trsm_l_cntl_mm_op,
	                          NULL,
	                          NULL );

	// Create control tree object for outer panel (to block-panel)
	// problem (right side).
	trsm_r_cntl_op_bp
	=
	bli_trsm_cntl_obj_create( BLIS_BLOCKED,
	                          BLIS_VARIANT1,
	                          trsm_mc,
	                          gemm_fortrsm_ukrs, NULL, NULL,
	                          NULL,
	                          trsm_r_packa_cntl,
	                          NULL, //trsm_r_packb_cntl, //
	                          NULL,
	                          BLIS_GEMM_DMAA_CNTL, //NULL, //
	                          NULL,
	                          NULL,
	                          trsm_cntl_bp_ke,
	                          gemm_cntl_bp_ke,
	                          NULL );

	// Create control tree object for general problem via multiple
	// rank-k (outer panel) updates (right side).
	trsm_r_cntl_mm_op
	=
	bli_trsm_cntl_obj_create( BLIS_BLOCKED,
	                          BLIS_VARIANT3,
	                          trsm_kc,
	                          gemm_fortrsm_ukrs, NULL, NULL,
	                          NULL,
	                          NULL,
	                          trsm_r_packb_cntl, //NULL, //
	                          NULL,
	                          NULL,
	                          BLIS_GEMM_DMAB_CNTL, //NULL, //
	                          NULL,
	                          trsm_r_cntl_op_bp,
	                          NULL,
	                          NULL );

	// Create control tree object for very large problem via multiple
	// general problems (right side).
	trsm_r_cntl_vl_mm
	=
	bli_trsm_cntl_obj_create( BLIS_BLOCKED,
	                          BLIS_VARIANT2,
	                          trsm_nc,
	                          gemm_fortrsm_ukrs, NULL, NULL,
	                          NULL,
	                          NULL,
	                          NULL,
	                          NULL,
	                          NULL,
	                          NULL,
	                          NULL,
	                          trsm_r_cntl_mm_op,
	                          NULL,
	                          NULL );

#else
	// Create control tree object for lowest-level block-panel kernel.
	trsm_cntl_bp_ke
	=
	bli_trsm_cntl_obj_create( BLIS_UNB_OPT,
	                          BLIS_VARIANT2,
	                          NULL,
	                          gemm_ukrs,
	                          gemmtrsm_l_ukrs,
	                          gemmtrsm_u_ukrs,
	                          NULL, NULL, NULL, NULL,
	                          NULL, NULL, NULL );

	// Create control tree object for outer panel (to block-panel)
	// problem (left side).
	trsm_l_cntl_op_bp
	=
	bli_trsm_cntl_obj_create( BLIS_BLOCKED,
	                          BLIS_VARIANT1,
	                          gemm_mc,
	                          gemm_ukrs, NULL, NULL,
	                          NULL,
	                          trsm_l_packa_cntl,
	                          trsm_l_packb_cntl,
	                          NULL,
	                          trsm_cntl_bp_ke,
	                          gemm_cntl_bp_ke,
	                          NULL );

	// Create control tree object for general problem via multiple
	// rank-k (outer panel) updates (left side).
	trsm_l_cntl_mm_op
	=
	bli_trsm_cntl_obj_create( BLIS_BLOCKED,
	                          BLIS_VARIANT3,
	                          gemm_kc,
	                          gemm_ukrs, NULL, NULL,
	                          NULL,
	                          NULL, 
	                          NULL,
	                          NULL,
	                          trsm_l_cntl_op_bp,
	                          NULL,
	                          NULL );

	// Create control tree object for very large problem via multiple
	// general problems (left side).
	trsm_l_cntl_vl_mm
	=
	bli_trsm_cntl_obj_create( BLIS_BLOCKED,
	                          BLIS_VARIANT2,
	                          gemm_nc,
	                          gemm_ukrs, NULL, NULL,
	                          NULL,
	                          NULL,
	                          NULL,
	                          NULL,
	                          trsm_l_cntl_mm_op,
	                          NULL,
	                          NULL );

	// Create control tree object for outer panel (to block-panel)
	// problem (right side).
	trsm_r_cntl_op_bp
	=
	bli_trsm_cntl_obj_create( BLIS_BLOCKED,
	                          BLIS_VARIANT1,
	                          gemm_mc,
	                          gemm_ukrs, NULL, NULL,
	                          NULL,
	                          trsm_r_packa_cntl,
	                          trsm_r_packb_cntl,
	                          NULL,
	                          trsm_cntl_bp_ke,
	                          gemm_cntl_bp_ke,
	                          NULL );

	// Create control tree object for general problem via multiple
	// rank-k (outer panel) updates (right side).
	trsm_r_cntl_mm_op
	=
	bli_trsm_cntl_obj_create( BLIS_BLOCKED,
	                          BLIS_VARIANT3,
	                          gemm_kc,
	                          gemm_ukrs, NULL, NULL,
	                          NULL,
	                          NULL, 
	                          NULL,
	                          NULL,
	                          trsm_r_cntl_op_bp,
	                          NULL,
	                          NULL );

	// Create control tree object for very large problem via multiple
	// general problems (right side).
	trsm_r_cntl_vl_mm
	=
	bli_trsm_cntl_obj_create( BLIS_BLOCKED,
	                          BLIS_VARIANT2,
	                          gemm_nc,
	                          gemm_ukrs, NULL, NULL,
	                          NULL,
	                          NULL,
	                          NULL,
	                          NULL,
	                          trsm_r_cntl_mm_op,
	                          NULL,
	                          NULL );
#endif

	// Alias the "master" trsm control trees to shorter names.
	trsm_l_cntl = trsm_l_cntl_vl_mm;
	trsm_r_cntl = trsm_r_cntl_vl_mm;
}

void bli_trsm_cntl_finalize()
{
#ifdef BLIS_ENABLE_C66X_EDMA
	bli_cntl_obj_free(trsm_mr);
	bli_cntl_obj_free(trsm_nr);

	bli_cntl_obj_free(gemm_fortrsm_ukrs);
#endif
	bli_func_obj_free( gemmtrsm_l_ukrs );
	bli_func_obj_free( gemmtrsm_u_ukrs );
	bli_func_obj_free( trsm_l_ukrs );
	bli_func_obj_free( trsm_u_ukrs );

	bli_cntl_obj_free( trsm_l_packa_cntl );
	bli_cntl_obj_free( trsm_l_packb_cntl );
	bli_cntl_obj_free( trsm_r_packa_cntl );
	bli_cntl_obj_free( trsm_r_packb_cntl );

	bli_cntl_obj_free( trsm_cntl_bp_ke );

	bli_cntl_obj_free( trsm_l_cntl_op_bp );
	bli_cntl_obj_free( trsm_l_cntl_mm_op );
	bli_cntl_obj_free( trsm_l_cntl_vl_mm );
	bli_cntl_obj_free( trsm_r_cntl_op_bp );
	bli_cntl_obj_free( trsm_r_cntl_mm_op );
	bli_cntl_obj_free( trsm_r_cntl_vl_mm );
}
#ifdef BLIS_ENABLE_C66X_EDMA
trsm_t* bli_trsm_cntl_obj_create( impl_t     impl_type,
                                  varnum_t   var_num,
                                  blksz_t*   b,
                                  func_t*    gemm_ukrs_,
                                  func_t*    gemmtrsm_l_ukrs_,
                                  func_t*    gemmtrsm_u_ukrs_,
                                  scalm_t*   sub_scalm,
                                  packm_t*   sub_packm_a,
                                  packm_t*   sub_packm_b,
                                  packm_t*   sub_packm_c,
                                  dmam_t*    sub_dmam_a,
                                  dmam_t*    sub_dmam_b,
                                  dmam_t*    sub_dmam_c,
                                  trsm_t*    sub_trsm,
                                  gemm_t*    sub_gemm,
                                  unpackm_t* sub_unpackm_c )
{
	trsm_t* cntl;

	cntl = ( trsm_t* ) bli_malloc( sizeof(trsm_t) );

	cntl->impl_type       = impl_type;
	cntl->var_num         = var_num;
	cntl->b               = b;
	cntl->gemm_ukrs       = gemm_ukrs_;
	cntl->gemmtrsm_l_ukrs = gemmtrsm_l_ukrs_;
	cntl->gemmtrsm_u_ukrs = gemmtrsm_u_ukrs_;
	cntl->sub_scalm       = sub_scalm;
	cntl->sub_packm_a     = sub_packm_a;
	cntl->sub_packm_b     = sub_packm_b;
	cntl->sub_packm_c     = sub_packm_c;
	cntl->sub_dmam_a	  = sub_dmam_a;
	cntl->sub_dmam_b	  = sub_dmam_b;
	cntl->sub_dmam_c	  = sub_dmam_c;
	cntl->sub_trsm        = sub_trsm;
	cntl->sub_gemm        = sub_gemm;
	cntl->sub_unpackm_c   = sub_unpackm_c;

	return cntl;
}

#else
trsm_t* bli_trsm_cntl_obj_create( impl_t     impl_type,
                                  varnum_t   var_num,
                                  blksz_t*   b,
                                  func_t*    gemm_ukrs_,
                                  func_t*    gemmtrsm_l_ukrs_,
                                  func_t*    gemmtrsm_u_ukrs_,
                                  scalm_t*   sub_scalm,
                                  packm_t*   sub_packm_a,
                                  packm_t*   sub_packm_b,
                                  packm_t*   sub_packm_c,
                                  trsm_t*    sub_trsm,
                                  gemm_t*    sub_gemm,
                                  unpackm_t* sub_unpackm_c )
{
	trsm_t* cntl;

	cntl = ( trsm_t* ) bli_malloc( sizeof(trsm_t) );

	cntl->impl_type       = impl_type;
	cntl->var_num         = var_num;
	cntl->b               = b;
	cntl->gemm_ukrs       = gemm_ukrs_;
	cntl->gemmtrsm_l_ukrs = gemmtrsm_l_ukrs_;
	cntl->gemmtrsm_u_ukrs = gemmtrsm_u_ukrs_;
	cntl->sub_scalm       = sub_scalm;
	cntl->sub_packm_a     = sub_packm_a;
	cntl->sub_packm_b     = sub_packm_b;
	cntl->sub_packm_c     = sub_packm_c;
	cntl->sub_trsm        = sub_trsm;
	cntl->sub_gemm        = sub_gemm;
	cntl->sub_unpackm_c   = sub_unpackm_c;

	return cntl;
}
#endif

