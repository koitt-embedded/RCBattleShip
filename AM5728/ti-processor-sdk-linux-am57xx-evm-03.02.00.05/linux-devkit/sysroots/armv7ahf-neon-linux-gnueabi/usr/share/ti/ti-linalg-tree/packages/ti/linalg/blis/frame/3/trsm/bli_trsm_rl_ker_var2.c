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

#define FUNCPTR_T gemm_fp

#ifdef BLIS_ENABLE_C66X_IDMA
#define BLIS_ENABLE_C66X_IDMA_KERVAR2 1
#endif


#ifdef BLIS_ENABLE_C66X_MEM_POOLS
extern char   *pool_mk_mem_L1;

//#define L1POOLSIZE_C (BLIS_MK_POOL_SIZE_L1 + BLIS_KN_POOL_SIZE_L1 + BLIS_MN_POOL_SIZE_L1)
//
//#pragma DATA_SECTION(pool,".mem_l1")
//#pragma DATA_ALIGN(pool,8)
//char pool[L1POOLSIZE_C];
#endif


typedef void (*FUNCPTR_T)(
                           doff_t  diagoffb,
                           pack_t  schema_a,
                           pack_t  schema_b,
                           dim_t   m,
                           dim_t   n,
                           dim_t   k,
                           void*   alpha1,
                           void*   a, inc_t cs_a, inc_t pd_a, inc_t ps_a,
                           void*   b, inc_t rs_b, inc_t pd_b, inc_t ps_b,
                           void*   alpha2,
                           void*   c, inc_t rs_c, inc_t cs_c,
                           void*   gemmtrsm_ukr,
                           void*   gemm_ukr,
                           trsm_thrinfo_t* thread
                         );

static FUNCPTR_T GENARRAY(ftypes,trsm_rl_ker_var2);


void bli_trsm_rl_ker_var2( obj_t*  a,
                           obj_t*  b,
                           obj_t*  c,
                           trsm_t* cntl,
                           trsm_thrinfo_t* thread )
{
	num_t     dt_exec   = bli_obj_execution_datatype( *c );

	doff_t    diagoffb  = bli_obj_diag_offset( *b );

	pack_t    schema_a  = bli_obj_pack_schema( *a );
	pack_t    schema_b  = bli_obj_pack_schema( *b );

	dim_t     m         = bli_obj_length( *c );
	dim_t     n         = bli_obj_width( *c );
	dim_t     k         = bli_obj_width( *a );

	void*     buf_a     = bli_obj_buffer_at_off( *a );
	inc_t     cs_a      = bli_obj_col_stride( *a );
	inc_t     pd_a      = bli_obj_panel_dim( *a );
	inc_t     ps_a      = bli_obj_panel_stride( *a );

	void*     buf_b     = bli_obj_buffer_at_off( *b );
	inc_t     rs_b      = bli_obj_row_stride( *b );
	inc_t     pd_b      = bli_obj_panel_dim( *b );
	inc_t     ps_b      = bli_obj_panel_stride( *b );

	void*     buf_c     = bli_obj_buffer_at_off( *c );
	inc_t     rs_c      = bli_obj_row_stride( *c );
	inc_t     cs_c      = bli_obj_col_stride( *c );

	void*     buf_alpha1;
	void*     buf_alpha2;

	FUNCPTR_T f;

	func_t*   gemmtrsm_ukrs;
	func_t*   gemm_ukrs;
	void*     gemmtrsm_ukr;
	void*     gemm_ukr;


	// Grab the address of the internal scalar buffer for the scalar
	// attached to A. This will be the alpha scalar used in the gemmtrsm
	// subproblems (ie: the scalar that would be applied to the packed
	// copy of A prior to it being updated by the trsm subproblem). This
	// scalar may be unit, if for example it was applied during packing.
	buf_alpha1 = bli_obj_internal_scalar_buffer( *a );

	// Grab the address of the internal scalar buffer for the scalar
	// attached to C. This will be the "beta" scalar used in the gemm-only
	// subproblems that correspond to micro-panels that do not intersect
	// the diagonal. We need this separate scalar because it's possible
	// that the alpha attached to B was reset, if it was applied during
	// packing.
	buf_alpha2 = bli_obj_internal_scalar_buffer( *c );

	// Index into the type combination array to extract the correct
	// function pointer.
	f = ftypes[dt_exec];

	// Extract from the control tree node the func_t objects containing
	// the gemmtrsm and gemm micro-kernel function addresses, and then
	// query the function addresses corresponding to the current datatype.
	gemmtrsm_ukrs = cntl_gemmtrsm_u_ukrs( cntl );
	gemm_ukrs     = cntl_gemm_ukrs( cntl );
	gemmtrsm_ukr  = bli_func_obj_query( dt_exec, gemmtrsm_ukrs );
	gemm_ukr      = bli_func_obj_query( dt_exec, gemm_ukrs );

	// Invoke the function.
	f( diagoffb,
	   schema_a,
	   schema_b,
	   m,
	   n,
	   k,
	   buf_alpha1,
	   buf_a, cs_a, pd_a, ps_a,
	   buf_b, rs_b, pd_b, ps_b,
	   buf_alpha2,
	   buf_c, rs_c, cs_c,
	   gemmtrsm_ukr,
	   gemm_ukr,
	   thread );
}
#ifdef BLIS_ENABLE_C66X_MEM_POOLS

#if defined (BLIS_ENABLE_C66X_EDMA) && defined (BLIS_ENABLE_C66X_IDMA)

#undef  GENTFUNC
#define GENTFUNC( ctype, ch, varname, gemmtrsmtype, gemmtype ) \
\
void PASTEMAC(ch,varname)( \
                           doff_t  diagoffb, \
                           pack_t  schema_a, \
                           pack_t  schema_b, \
                           dim_t   m, \
                           dim_t   n, \
                           dim_t   k, \
                           void*   alpha1, \
                           void*   a, inc_t cs_a, inc_t pd_a, inc_t ps_a, \
                           void*   b, inc_t rs_b, inc_t pd_b, inc_t ps_b, \
                           void*   alpha2, \
                           void*   c, inc_t rs_c, inc_t cs_c, \
                           void*   gemmtrsm_ukr, \
                           void*   gemm_ukr, \
                           trsm_thrinfo_t* thread \
                         ) \
{ \
	/* Cast the micro-kernels' addresses to their function pointer types. */ \
	PASTECH(ch,gemmtrsmtype) gemmtrsm_ukr_cast = ( PASTECH(ch,gemmtrsmtype) ) gemmtrsm_ukr; \
	PASTECH(ch,gemmtype)     gemm_ukr_cast     = ( PASTECH(ch,gemmtype)) gemm_ukr; \
\
	/* Temporary C buffer for edge cases. */ \
	ctype           ct[ PASTEMAC(ch,maxnr) * \
	                    PASTEMAC(ch,maxmr) ] \
	                    __attribute__((aligned(BLIS_STACK_BUF_ALIGN_SIZE))); \
	const inc_t     rs_ct      = 1; \
	const inc_t     cs_ct      = PASTEMAC(ch,maxnr); \
\
	/* Alias some constants to simpler names. */ \
	const dim_t     MR         = pd_a; \
	const dim_t     NR         = pd_b; \
	const dim_t     PACKMR     = cs_a; \
	const dim_t     PACKNR     = rs_b; \
\
	ctype* restrict zero        = PASTEMAC(ch,0); \
	ctype* restrict minus_one   = PASTEMAC(ch,m1); \
	ctype* restrict a_cast      = a; \
	ctype* restrict b_cast      = b; \
	ctype* restrict c_cast      = c; \
	ctype* restrict alpha1_cast = alpha1; \
	ctype* restrict alpha2_cast = alpha2; \
	ctype* restrict b1; \
	ctype* restrict c1; \
\
	doff_t          diagoffb_j; \
	dim_t           k_full; \
	dim_t           m_iter, m_left; \
	dim_t           n_iter, n_left; \
	dim_t           m_cur; \
	dim_t           n_cur; \
	dim_t           k_b1121; \
	dim_t           k_b11; \
	dim_t           k_b21; \
	dim_t           off_b11; \
	dim_t           off_b21; \
	dim_t           i, j, jb; \
	inc_t           rstep_a; \
	inc_t           cstep_b; \
	/*inc_t           rstep_c;*/ \
	inc_t 			cstep_c; \
	inc_t           istep_a; \
	inc_t           istep_b; \
	inc_t           off_scl; \
	inc_t           ss_b_num; \
	inc_t           ss_b_den; \
	inc_t           ps_b_cur; \
	auxinfo_t       aux; \
\
	dim_t n_next; \
	inc_t rstep_c11, rs_c11, cs_c11; \
\
	mem_t b1_L1_mem; \
	/*memcpy does not like b1_L1 if it is restrict. The resid of gemm is non zero if this is changed to ctype* restrict*/ \
	ctype* b1_L1; \
\
	mem_t a1_L1_mem, a2_L1_mem; \
	ctype *a1_L1, *a2_L1, *temp; \
\
    mem_t c0_L2_mem, c1_L2_mem, c2_L2_mem; \
	ctype *cNew0, *cNew1, *cNew2, *cNewTemp; \
	/*EDMA Declarations */ \
\
	lib_emt_Handle emt_handle_b = NULL; \
	lib_emt_Handle emt_handle_c0 = NULL; \
	lib_emt_Handle emt_handle_c1 = NULL; \
\
	/*For DSP timing*/ \
	uint64_t counter_start_ker, counter_start_nr, counter_start_mr; \
	uint64_t counter_end_ker, counter_end_nr, counter_end_mr; \
	extern profile_data_t *bli_trsm_profile_data; \
	/*
	   Assumptions/assertions:
	     rs_a == 1
	     cs_a == PACKNR
	     pd_a == NR
	     ps_a == stride to next micro-panel of A
	     rs_b == PACKMR
	     cs_b == 1
	     pd_b == MR
	     ps_b == stride to next micro-panel of B
	     rs_c == (no assumptions)
	     cs_c == (no assumptions)

	  Note that MR/NR and PACKMR/PACKNR have been swapped to reflect the
	  swapping of values in the control tree (ie: those values used when
	  packing). This swapping is needed since we cast right-hand trsm in
	  terms of transposed left-hand trsm. So, if we're going to be
	  transposing the operation, then A needs to be packed with NR and B
	  needs to be packed with MR (remember: B is the triangular matrix in
	  the right-hand side parameter case).
	*/ \
\
	/* If any dimension is zero, return immediately. */ \
	if ( bli_zero_dim3( m, n, k ) ) return; \
\
	/* Safeguard: If the current panel of B is entirely above its diagonal,
	   it is implicitly zero. So we do nothing. */ \
	if ( bli_is_strictly_above_diag_n( diagoffb, k, n ) ) return; \
\
	/* Compute k_full as k inflated up to a multiple of NR. This is
	   needed because some parameter combinations of trsm reduce k
	   to advance past zero regions in the triangular matrix, and
	   when computing the imaginary stride of B (the non-triangular
	   matrix), which is used by 3m and 4m implementations, we need
	   this unreduced value of k. */ \
	k_full = ( k % NR != 0 ? k + NR - ( k % NR ) : k ); \
\
	/* Compute indexing scaling factor for for 4m or 3m. This is
	   needed because one of the packing register blocksizes (PACKMR
	   or PACKNR) is used to index into the micro-panels of the non-
	   triangular matrix when computing with a diagonal-intersecting
	   micro-panel of the triangular matrix. In the case of 4m or 3m,
	   real values are stored in both sub-panels, and so the indexing
	   needs to occur in units of real values. The value computed
	   here is divided into the complex pointer offset to cause the
	   pointer to be advanced by the correct value. */ \
	if ( bli_is_4m_packed( schema_b ) || \
	     bli_is_3m_packed( schema_b ) || \
	     bli_is_rih_packed( schema_b ) ) off_scl = 2; \
	else                                 off_scl = 1; \
\
	/* Compute the storage stride. Usually this is just PACKMR (for A
	   or PACKNR (for B). However, in the case of 3m, we need to scale
	   the offset by 3/2. Since it's possible we may need to scale
	   the packing dimension by a non-integer value, we break up the
	   scaling factor into numerator and denominator. */ \
	if ( bli_is_3m_packed( schema_b ) ) { ss_b_num = 3*PACKNR; \
	                                      ss_b_den = 2; } \
	else                                { ss_b_num = 1*PACKNR; \
	                                      ss_b_den = 1; } \
\
	/* If there is a zero region above where the diagonal of B intersects
	   the left edge of the panel, adjust the pointer to A and treat this
	   case as if the diagonal offset were zero. Note that we don't need to
	   adjust the pointer to B since packm would have simply skipped over
	   the region that was not stored. */ \
	if ( diagoffb < 0 ) \
	{ \
		j        = -diagoffb; \
		k        = k - j; \
		diagoffb = 0; \
		a_cast   = a_cast + ( j * PACKMR ) / off_scl; \
	} \
\
	/* If there is a zero region to the right of where the diagonal
	   of B intersects the bottom of the panel, shrink it so that
	   we can index to the correct place in C (corresponding to the
	   part of the panel of B that was packed).
	   NOTE: This is NOT being done to skip over "no-op" iterations,
	   as with the trsm_lu macro-kernel. This MUST be done for correct
	   execution because we use n (via n_iter) to compute diagonal and
	   index offsets for backwards movement through B. */ \
	if ( diagoffb + k < n ) \
	{ \
		n = diagoffb + k; \
	} \
\
	/* Check the k dimension, which needs to be a multiple of NR. If k
	   isn't a multiple of NR, we adjust it higher to satisfy the micro-
	   kernel, which is expecting to perform an NR x NR triangular solve.
	   This adjustment of k is consistent with what happened when B was
	   packed: all of its bottom/right edges were zero-padded, and
	   furthermore, the panel that stores the bottom-right corner of the
	   matrix has its diagonal extended into the zero-padded region (as
	   identity). This allows the trsm of that bottom-right panel to
	   proceed without producing any infs or NaNs that would infect the
	   "good" values of the corresponding block of A. */ \
	if ( k % NR != 0 ) k += NR - ( k % NR ); \
\
	/* NOTE: We don't need to check that n is a multiple of PACKNR since we
	   know that the underlying buffer was already allocated to have an n
	   dimension that is a multiple of PACKNR, with the region between the
	   last column and the next multiple of NR zero-padded accordingly. */ \
\
	/* Clear the temporary C buffer in case it has any infs or NaNs. */ \
	PASTEMAC(ch,set0s_mxn)( MR, NR, \
	                        ct, rs_ct, cs_ct ); \
\
	/* Compute number of primary and leftover components of the m and n
       dimensions. */ \
	n_iter = n / NR; \
	n_left = n % NR; \
\
	m_iter = m / MR; \
	m_left = m % MR; \
\
	if ( n_left ) ++n_iter; \
	if ( m_left ) ++m_iter; \
\
	/* Determine some increments used to step through A, B, and C. */ \
	rstep_a = ps_a; \
\
	cstep_b = ps_b; \
\
	/*rstep_c = rs_c * MR;*/ \
	cstep_c = cs_c * NR; \
\
	/* When C (MC*NR) is moved to L2 the stride to get to the next panel of MRxNR*/ \
	if(rs_c == 1) \
	{ \
		rstep_c11 = MR; /*stride to get to next panel of MRxNR in a panel of MCxNR*/\
		rs_c11 = 1; \
		cs_c11 = (m%2 == 0) ? m : m+1; /*stride to get to next column in a panel of MRxNR*/\
	} \
	else\
	{ \
		rstep_c11 = NR*MR; /*stride to get to next panel of MRxNR in a panel of MCxNR*/\
		rs_c11 = NR; /* stride to get to next row in MRxNR panel*/\
		cs_c11 = 1; /*stride to get to next column in a panel of MRxNR*/\
\
		/*rstep_c11 = rstep_c; \
		rs_c11 = rs_c; \
		cs_c11 = cs_c;*/ \
	} \
\
	istep_a = PACKMR * k_full; \
	istep_b = PACKNR * k; \
\
	/* Save the pack schemas of A and B to the auxinfo_t object.
	   NOTE: We swap the values for A and B since the triangular
	   "A" matrix is actually contained within B. */ \
	bli_auxinfo_set_schema_a( schema_b, aux ); \
	bli_auxinfo_set_schema_b( schema_a, aux ); \
\
	/* Save the imaginary stride of A to the auxinfo_t object.
	   NOTE: We swap the values for A and B since the triangular
	   "A" matrix is actually contained within B. */ \
	bli_auxinfo_set_is_b( istep_a, aux ); \
\
	b1 = b_cast; \
	c1 = c_cast; \
\
	/*printf("m %d n %d  k %d pd_a %d, ps_a %d pd_b %d, ps_b %d\n",m, n, k, pd_a, ps_a, pd_b, ps_b);*/\
	/*printf("Acquire B k %d, NR %d, size of ctype %d, B size requested %d\n", k, NR, sizeof(ctype), k*NR*sizeof(ctype)); \
	printf("Acquire A k %d, MR %d, size of ctype %d, A size requested %d\n", k, MR, sizeof(ctype), k*MR*sizeof(ctype));*/ \
	/*Acquiring a buffer for B in L1*/ \
	if((MKSTR(ch)=="c")==1) \
	{\
		a1_L1 = (ctype*) (pool_mk_mem_L1 ); \
		a2_L1 = (ctype*) (pool_mk_mem_L1 + k*MR*sizeof(ctype) ) ;\
		b1_L1 = (ctype*) (pool_mk_mem_L1 + PASTEMAC(ch,bank) +  2 * k*MR*sizeof(ctype)) ;\
		/*printf("%x %x %x \n", a1_L1, a2_L1, b1_L1);*/\
	}\
	else { \
	bli_mem_acquire_m( k*NR*sizeof(ctype), BLIS_BUFFER_FOR_B_PANEL_L1, &b1_L1_mem); \
	b1_L1 = bli_mem_buffer( &b1_L1_mem ); \
	b1_L1 = (ctype *) ((char *) b1_L1_mem.buf + PASTEMAC(ch,bank)); \
\
	/*Acquiring a buffer for A in L1*/ \
	bli_mem_acquire_m( k*MR*sizeof(ctype), BLIS_BUFFER_FOR_A_BLOCK_L1, &a1_L1_mem); \
	a1_L1 = bli_mem_buffer( &a1_L1_mem ); \
\
	bli_mem_acquire_m( k*MR*sizeof(ctype), BLIS_BUFFER_FOR_A_BLOCK_L1, &a2_L1_mem); \
	a2_L1 = bli_mem_buffer( &a2_L1_mem ); \
\
	}\
	/*Acquiring buffers for C (MC_x_NR) in L2 */\
	/*printf("Acquire C NR %d, MR %d, size of ctype %d, C size requested %d\n", m, NR, sizeof(ctype), m*NR*sizeof(ctype));*/ \
	bli_mem_acquire_m( cs_c11*NR*sizeof(ctype), BLIS_BUFFER_FOR_C_PANEL_L2, &c0_L2_mem); \
	cNew0 = bli_mem_buffer( &c0_L2_mem ); \
\
	bli_mem_acquire_m( cs_c11*NR*sizeof(ctype), BLIS_BUFFER_FOR_C_PANEL_L2, &c1_L2_mem); \
	cNew1 = bli_mem_buffer( &c1_L2_mem ); \
\
	bli_mem_acquire_m( cs_c11*NR*sizeof(ctype), BLIS_BUFFER_FOR_C_PANEL_L2, &c2_L2_mem); \
	cNew2 = bli_mem_buffer( &c2_L2_mem ); \
\
	/*Acquiring an EDMA  handle from the pool*/ \
	bli_dma_channel_acquire(&(emt_handle_b), lib_get_coreID()); \
	if(emt_handle_b == NULL) \
	{ \
		printf("ker_var2 Failed to alloc edma handle CoreID %d \n", lib_get_coreID()); \
	} \
	bli_dma_channel_acquire(&(emt_handle_c0), lib_get_coreID()); \
	if(emt_handle_c0 == NULL) \
	{ \
		printf("ker_var2 Failed to alloc edma handle for C0 CoreID %d \n", lib_get_coreID()); \
	} \
	/*Acquiring an EDMA  handle from the pool*/ \
	bli_dma_channel_acquire(&(emt_handle_c1), lib_get_coreID()); \
	if(emt_handle_c1 == NULL) \
	{ \
		printf("ker_var2 Failed to alloc edma handle for C1 CoreID %d \n", lib_get_coreID()); \
	} \
\
	n_cur = ( bli_is_not_edge_f( 0, n_iter, n_left ) ? NR : n_left ); \
	if (BLIS_ENABLE_PROFILE_KERVAR2 == 1) \
	{ \
		counter_start_nr = lib_clock_read();  \
	} \
	\
	if(rs_c == 1) \
	{\
		c1 = c1 + (n_iter-1)*cstep_c; \
		/*printf("rs_c = %d, cs_c = %d, rs_c11 = %d, cs_c11 = %d, cstep_c = %d, rstep_c11 = %d, n_cur = %d, m = %d\n", rs_c, cs_c, rs_c11, cs_c11, cstep_c,rstep_c11, n_cur, m);*/ \
		if (cs_c*sizeof(ctype) < BLIS_C66X_MAXDMASTRIDE) \
		{ \
			lib_emt_copy2D2D(emt_handle_c0, c1, \
	                            cNew1, m*sizeof(ctype), \
	                            n_cur, cs_c*sizeof(ctype), cs_c11*sizeof(ctype)); \
		} \
		else \
		{ \
		   	dim_t ii; \
		   	ctype *ptr_source; \
		   	ctype *ptr_dest; \
		   	ptr_source =  c1; \
		   	ptr_dest = cNew1; \
			for(ii = 0; ii < n_cur; ii++) \
		   	{ \
		    	memcpy(ptr_dest, ptr_source, m*sizeof(ctype)); \
		    	ptr_source += cs_c; \
		    	ptr_dest   += cs_c11; \
		    } \
		}\
	}\
	else \
	{ \
		/*printf("rs_c = %d, cs_c = %d, rs_c11 = %d, cs_c11 = %d, cstep_c = %d, rstep_c11 = %d, n_cur = %d, m = %d\n", rs_c, cs_c, rs_c11, cs_c11, cstep_c,rstep_c11, n_cur, m);*/ \
		c1 = c1 + (n_iter-1)*cstep_c; \
		if (rs_c*sizeof(ctype) < BLIS_C66X_MAXDMASTRIDE) \
		{ \
			lib_emt_copy2D2D(emt_handle_c0, c1, \
								cNew1, n_cur*sizeof(ctype), \
								m, rs_c*sizeof(ctype), rs_c11*sizeof(ctype)); \
		} \
		else \
		{ \
			dim_t ii; \
			ctype *ptr_source; \
			ctype *ptr_dest; \
			ptr_source =  c1; \
			ptr_dest = cNew1; \
			for(ii = 0; ii < m; ii++) \
			{ \
				memcpy(ptr_dest, ptr_source, n_cur*sizeof(ctype)); \
				ptr_source += rs_c; \
				ptr_dest   += rs_c11; \
			} \
		}\
	}\
\
	/* Loop over the n dimension (NR columns at a time). */ \
	for ( jb = 0; jb < n_iter; ++jb ) \
	{ \
		ctype* restrict a1; \
		ctype* restrict c11; \
		ctype* restrict b11; \
		ctype* restrict b21; \
		ctype* restrict b2; \
		\
		j          = n_iter - 1 - jb; \
		diagoffb_j = diagoffb - ( doff_t )j*NR; \
		a1         = a_cast; \
		/*if(rs_c == 1)*/ \
		c11    = cNew1; \
		/*else \
			c11    = c1 + (n_iter-1)*cstep_c; */\
		\
		n_cur = ( bli_is_not_edge_b( jb, n_iter, n_left ) ? NR : n_left ); \
		n_next = ( bli_is_not_edge_b( jb+1, n_iter, n_left ) ? NR : n_left ); \
		\
		lib_emt_copy1D1D(emt_handle_b, b1, b1_L1, k*NR*sizeof(ctype)); \
		/* Initialize our next panel of B to be the current panel of B. */ \
		b2 = b1; \
		/*if(rs_c == 1)*/ \
		lib_emt_wait(emt_handle_c0); \
		if(jb < n_iter-1) /* no transfer for last iteration */ \
		{ \
			if (rs_c == 1) \
			{ \
				if (cs_c*sizeof(ctype) < BLIS_C66X_MAXDMASTRIDE) \
				{ \
					lib_emt_copy2D2D(emt_handle_c0, c1-cstep_c, \
							cNew0, m*sizeof(ctype), \
							n_next, cs_c*sizeof(ctype), \
							cs_c11*sizeof(ctype)); \
				} \
				else \
				{ \
					dim_t ii; \
					ctype *ptr_source; \
					ctype *ptr_dest; \
					ptr_source =  c1-cstep_c; \
					ptr_dest = cNew0; \
					for(ii = 0; ii < n_next; ii++) \
					{ \
						memcpy(ptr_dest, ptr_source, m*sizeof(ctype)); \
						ptr_source += cs_c; \
						ptr_dest   += cs_c11; \
					} \
				}\
			}\
			else \
			{ \
				if (rs_c*sizeof(ctype) < BLIS_C66X_MAXDMASTRIDE) \
				{ \
					lib_emt_copy2D2D(emt_handle_c0, c1 - cstep_c, \
							cNew0, n_next*sizeof(ctype), \
							m, rs_c*sizeof(ctype), rs_c11*sizeof(ctype)); \
				} \
				else \
				{ \
					dim_t ii; \
					ctype *ptr_source; \
					ctype *ptr_dest; \
					ptr_source =  c1 - cstep_c; \
					ptr_dest = cNew0; \
					for(ii = 0; ii < m; ii++) \
					{ \
						memcpy(ptr_dest, ptr_source, n_next*sizeof(ctype)); \
						ptr_source += rs_c; \
						ptr_dest   += rs_c11; \
					} \
				}\
			} \
		} \
\
		/* If the current panel of B intersects the diagonal, use a
		   special micro-kernel that performs a fused gemm and trsm.
		   If the current panel of B resides below the diagonal, use a
		   a regular gemm micro-kernel. Otherwise, if it is above the
		   diagonal, it was not packed (because it is implicitly zero)
		   and so we do nothing. */ \
		if ( bli_intersects_diag_n( diagoffb_j, k, NR ) ) \
		{ \
			/* Determine the offset to and length of the panel that was packed
			   so we can index into the corresponding location in A. */ \
			off_b11   = bli_max( -diagoffb_j, 0 ); \
			k_b1121   = k - off_b11; \
			k_b11     = NR; \
			k_b21     = k_b1121 - NR; \
			off_b21   = off_b11 + k_b11; \
\
			/* Compute the addresses of the triangular block B11 and the
			   panel B21. */ \
			/*b11       = b1; \
			b21       = b1 + ( k_b11 * PACKNR ) / off_scl;*/ \
			b11       = b1_L1; \
			b21       = b1_L1 + ( k_b11 * PACKNR ) / off_scl; \
\
			/* Compute the panel stride for the current micro-panel. */ \
			ps_b_cur = ( k_b1121 * ss_b_num ) / ss_b_den; \
\
			/* Save the imaginary stride of B to the auxinfo_t object.
			   NOTE: We swap the values for A and B since the triangular
			   "A" matrix is actually contained within B. */ \
			bli_auxinfo_set_is_a( PACKNR * k_b1121, aux ); \
\
			/* Loop over the m dimension (MR rows at a time). */ \
\
			if (BLIS_ENABLE_PROFILE_KERVAR2 == 1) \
			{ \
				counter_start_mr = lib_clock_read();  \
			} \
			for ( i = 0; i < m_iter; ++i ) \
			{ \
				if( trsm_my_iter( i, thread ) ) \
				{ \
\
				ctype* restrict a11; \
				ctype* restrict a12; \
				ctype* restrict a2; \
\
				m_cur = ( bli_is_not_edge_f( i, m_iter, m_left ) ? MR : m_left ); \
\
				if (BLIS_ENABLE_C66X_IDMA_KERVAR2 == 1) \
				{ \
					if (i == 0) \
					{ \
					lib_imt_copy(a1 + ( off_b11 * PACKMR ) / off_scl, a2_L1, k_b1121*MR*sizeof(ctype)); \
					} \
				} \
\
				/* Compute the addresses of the next panels of A and B. */ \
				if (BLIS_ENABLE_C66X_IDMA_KERVAR2 == 1) \
				{ \
					a2 = a1 + rstep_a; \
					lib_imt_wait(); \
					temp = a1_L1; \
					a1_L1 = a2_L1; \
					a2_L1 = temp; \
				} \
				else \
				{ \
					a2 = a1; \
				} \
\
				/* Compute the addresses of the next panels of A and B. */ \
				if(i == 0) \
				{ \
					lib_emt_wait(emt_handle_b);\
				} \
				/*if ( i + thread_num_threads(thread) >= m_iter )*/ \
				if ( bli_is_last_iter( i, m_iter, 0, 1 ) ) \
				{ \
					a2 = a_cast; \
					b2 = b1 + ps_b_cur; \
					if ( bli_is_last_iter( jb, n_iter, 0, 1 ) ) \
						b2 = b_cast; \
				} \
				else \
				{ \
					if (BLIS_ENABLE_C66X_IDMA_KERVAR2 == 1) \
					{ \
						/*Start next panel*/ \
					lib_imt_copy(a2 + ( off_b11 * PACKMR ) / off_scl, a2_L1, k_b1121*MR*sizeof(ctype)); \
					} \
				} \
\
				/* Save addresses of next panels of A and B to the auxinfo_t
				   object. NOTE: We swap the values for A and B since the
				   triangular "A" matrix is actually contained within B. */ \
				bli_auxinfo_set_next_a( b2, aux ); \
				bli_auxinfo_set_next_b( a2, aux ); \
\
				/* Compute the addresses of the A11 block and A12 panel. */ \
				/* If IDMA enabled*/ \
				if (BLIS_ENABLE_C66X_IDMA_KERVAR2 == 1) \
				{ \
					a11 = a1_L1;\
					a12 = a1_L1 + ( k_b11 * PACKMR ) / off_scl; \
				} \
				else \
				{ \
					a11 = a1 + ( off_b11 * PACKMR ) / off_scl; \
					a12 = a1 + ( off_b21 * PACKMR ) / off_scl; \
				} \
				/* Handle interior and edge cases separately. */ \
				if (BLIS_ENABLE_PROFILE_KERVAR2 == 1) \
				{ \
					counter_start_ker = lib_clock_read();  \
				} \
				if ( m_cur == MR && n_cur == NR ) \
				{ \
					/* Invoke the fused gemm/trsm micro-kernel. */ \
					gemmtrsm_ukr_cast( k_b21, \
					                   alpha1_cast, \
					                   b21, \
					                   b11, \
					                   a12, \
					                   a11, \
					                   c11, cs_c11, rs_c11, /*cs_c, rs_c, cstep_c11, 1,*/ \
					                   &aux ); \
				} \
				else \
				{ \
					/* Invoke the fused gemm/trsm micro-kernel. */ \
					gemmtrsm_ukr_cast( k_b21, \
					                   alpha1_cast, \
					                   b21, \
					                   b11, \
					                   a12, \
					                   a11, \
					                   ct, cs_ct, rs_ct, \
					                   &aux ); \
\
					/* Copy the result to the bottom edge of C. */ \
					PASTEMAC(ch,copys_mxn)( m_cur, n_cur, \
					                        ct,  rs_ct, cs_ct, \
					                        c11, rs_c11, cs_c11 /* rs_c,  cs_c **** 1, cstep_c11*/); \
				} \
				if (BLIS_ENABLE_PROFILE_KERVAR2 == 1) \
				{ \
					counter_end_ker = lib_clock_read();  \
					bli_profile_data_update(bli_trsm_profile_data[bli_get_thread_num()+BLIS_MAX_NUM_THREADS*BLIS_PROFILE_KER_LOOP_IND],\
											(counter_end_ker-counter_start_ker), 2*k_b21*m_cur*n_cur); \
				} \
				if (BLIS_ENABLE_C66X_IDMA_KERVAR2 == 1) \
				{ \
					/*Storing the value back*/\
					/*lib_imt_wait(); \
					lib_imt_copy(a11, a1 + ( off_b11 * PACKMR ) / off_scl, k_b11*PACKMR*sizeof(ctype));*/ \
					{ \
						ctype *ptr_source; \
						ctype *ptr_dest; \
						ptr_source = a11; \
						ptr_dest = a1 + ( off_b11 * PACKMR ) / off_scl; \
						memcpy(ptr_dest, ptr_source, k_b11*PACKMR*sizeof(ctype)); \
					} \
				} \
				} /*trsm_my_iter( i, thread ) */\
\
				a1  += rstep_a; \
				/*c11 += rstep_c;*/ \
				c11 += rstep_c11; \
			} /*MR loop*/\
			if (BLIS_ENABLE_PROFILE_KERVAR2 == 1) \
			{ \
				counter_end_mr = lib_clock_read();  \
				bli_profile_data_update(bli_trsm_profile_data[bli_get_thread_num()+BLIS_MAX_NUM_THREADS*BLIS_PROFILE_IR_LOOP_IND], \
										(counter_end_mr-counter_start_mr), 2*k*m*n_cur); \
			} \
\
			b1 += ps_b_cur; \
		} \
		else if ( bli_is_strictly_below_diag_n( diagoffb_j, k, NR ) ) \
		{ \
			/* Save the imaginary stride of B to the auxinfo_t object.
			   NOTE: We swap the values for A and B since the triangular
			   "A" matrix is actually contained within B. */ \
			bli_auxinfo_set_is_a( istep_b, aux ); \
\
			/* Loop over the m dimension (MR rows at a time). */ \
			if (BLIS_ENABLE_PROFILE_KERVAR2 == 1) \
			{ \
				counter_start_mr = lib_clock_read();  \
			} \
\
			for ( i = 0; i < m_iter; ++i ) \
			{ \
				if( trsm_my_iter( i, thread ) ){ \
\
				ctype* restrict a2; \
\
				m_cur = ( bli_is_not_edge_f( i, m_iter, m_left ) ? MR : m_left ); \
\
				if (BLIS_ENABLE_C66X_IDMA_KERVAR2 == 1) \
				{ \
					if(i == 0) \
					{ \
					lib_imt_copy(a1, a2_L1, k*MR*sizeof(ctype)); \
					} \
					/* Compute the addresses of the next panels of A and B. */ \
					a2 = a1 + rstep_a; \
					lib_imt_wait(); \
					temp = a1_L1; \
					a1_L1 = a2_L1; \
					a2_L1 = temp; \
				} \
				else \
				{ \
					/* Compute the addresses of the next panels of A and B. */ \
					a2 = a1;\
				} \
\
				if(i == 0) \
				{ \
					lib_emt_wait(emt_handle_b);\
				}\
				/*if ( bli_is_last_iter( i, m_iter, 0, 1 ) ) */\
				if ( i + thread_num_threads(thread) >= m_iter ) \
				{ \
					a2 = a_cast; \
					b2 = b1 + cstep_b; \
					if ( bli_is_last_iter( jb, n_iter, 0, 1 ) ) \
						b2 = b_cast; \
				} \
				else \
				{ \
					if (BLIS_ENABLE_C66X_IDMA_KERVAR2 == 1) \
					{ \
						/*Start next panel*/ \
					lib_imt_copy(a2, a2_L1, k*MR*sizeof(ctype)); \
					} \
				} \
\
				/* Save addresses of next panels of A and B to the auxinfo_t
				   object. NOTE: We swap the values for A and B since the
				   triangular "A" matrix is actually contained within B. */ \
				bli_auxinfo_set_next_a( b2, aux ); \
				bli_auxinfo_set_next_b( a2, aux ); \
\
				/* Handle interior and edge cases separately. */ \
				if (BLIS_ENABLE_PROFILE_KERVAR2 == 1) \
				{ \
					counter_start_ker = lib_clock_read();  \
				} \
				if (BLIS_ENABLE_C66X_IDMA_KERVAR2 == 1) \
				{ \
					if ( m_cur == MR && n_cur == NR ) \
					{ \
						/* Invoke the gemm micro-kernel. */ \
						gemm_ukr_cast( k, \
									   minus_one, \
									   b1_L1, \
									   a1_L1, \
									   alpha2_cast, \
									   c11, cs_c11, rs_c11, /*cs_c, rs_c,  * cstep_c11, 1,*/ \
									   &aux ); \
					} \
					else \
					{ \
						/* Invoke the gemm micro-kernel. */ \
						gemm_ukr_cast( k, \
									   minus_one, \
									   b1_L1, \
									   a1_L1, \
									   zero, \
									   ct, cs_ct, rs_ct, \
									   &aux ); \
\
						/* Add the result to the edge of C. */ \
						PASTEMAC(ch,xpbys_mxn)( m_cur, n_cur, \
												ct,  rs_ct, cs_ct, \
												alpha2_cast, \
												c11, rs_c11, cs_c11 /*rs_c,  cs_c  *1, cstep_c11 */); \
					} \
				} \
				else \
				{ \
					if ( m_cur == MR && n_cur == NR ) \
					{ \
						/* Invoke the gemm micro-kernel. */ \
						gemm_ukr_cast( k, \
									   minus_one, \
									   b1_L1, \
									   a1, \
									   alpha2_cast, \
									   c11, cs_c11, rs_c11, /*cs_c, rs_c,  * cstep_c11, 1,*/ \
									   &aux ); \
					} \
					else \
					{ \
						/* Invoke the gemm micro-kernel. */ \
						gemm_ukr_cast( k, \
									   minus_one, \
									   b1_L1, \
									   a1, \
									   zero, \
									   ct, cs_ct, rs_ct, \
									   &aux ); \
\
						/* Add the result to the edge of C. */ \
						PASTEMAC(ch,xpbys_mxn)( m_cur, n_cur, \
												ct,  rs_ct, cs_ct, \
												alpha2_cast, \
												c11, rs_c11, cs_c11 /*rs_c,  cs_c  *1, cstep_c11 */); \
					} \
				} \
				if (BLIS_ENABLE_PROFILE_KERVAR2 == 1) \
				{ \
					counter_end_ker = lib_clock_read();  \
					bli_profile_data_update(bli_trsm_profile_data[bli_get_thread_num()+BLIS_MAX_NUM_THREADS*BLIS_PROFILE_KER_LOOP_IND],\
											(counter_end_ker-counter_start_ker), 2*k*m_cur*n_cur); \
				} \
				} /*myiter*/\
\
				a1  += rstep_a; \
				/*c11 += rstep_c;*/ \
				c11 += rstep_c11; \
			} /*MR loop if b does not intersect diagonal*/\
			\
			if (BLIS_ENABLE_PROFILE_KERVAR2 == 1) \
			{ \
				counter_end_mr = lib_clock_read();  \
				bli_profile_data_update(bli_trsm_profile_data[bli_get_thread_num()+BLIS_MAX_NUM_THREADS*BLIS_PROFILE_IR_LOOP_IND], \
										(counter_end_mr-counter_start_mr), 2*k*m*n_cur); \
			} \
\
			b1 += cstep_b; \
		} \
\
		/* circularly shift buffers */ \
		cNewTemp = cNew0; \
		cNew0 = cNew2; \
		cNew2 = cNew1; \
		cNew1 = cNewTemp; \
		if(j != 0) /* wait for save c to complete; skip first iteration */ \
		{ \
			lib_emt_wait(emt_handle_c1); \
		} \
		/* save updated c*/ \
		if(rs_c==1) \
		{ \
			if (cs_c*sizeof(ctype) < BLIS_C66X_MAXDMASTRIDE) \
			{ \
				lib_emt_copy2D2D(emt_handle_c1, cNew2, c1, m*sizeof(ctype),  \
				     				n_cur, cs_c11*sizeof(ctype), cs_c*sizeof(ctype)); \
			}\
			else \
			{ \
				dim_t ii; \
				ctype *ptr_source; \
				ctype *ptr_dest; \
				ptr_source = cNew2; \
				ptr_dest = c1; \
				for(ii = 0; ii < n_cur; ii++) \
				{ \
					memcpy(ptr_dest, ptr_source, m*sizeof(ctype)); \
					ptr_source += cs_c11; \
					ptr_dest   += cs_c; \
				} \
			} \
		} \
		else \
		{ \
			if (rs_c*sizeof(ctype) < BLIS_C66X_MAXDMASTRIDE) \
			{ \
				lib_emt_copy2D2D(emt_handle_c1, cNew2, c1, n_cur*sizeof(ctype), \
									m, rs_c11*sizeof(ctype), rs_c*sizeof(ctype)); \
			} \
			else \
			{ \
				dim_t ii; \
				ctype *ptr_source; \
				ctype *ptr_dest; \
				ptr_source =  cNew2; \
				ptr_dest = c1; \
				for(ii = 0; ii < m; ii++) \
				{ \
					memcpy(ptr_dest, ptr_source, n_cur*sizeof(ctype)); \
					ptr_source += rs_c11; \
					ptr_dest   += rs_c; \
				} \
			}\
		}\
\
		c1 -= cstep_c; \
	} /*NR loop*/\
	\
	if (BLIS_ENABLE_PROFILE_KERVAR2 == 1) \
	{ \
		counter_end_nr = lib_clock_read();  \
		bli_profile_data_update(bli_trsm_profile_data[bli_get_thread_num()+BLIS_MAX_NUM_THREADS*BLIS_PROFILE_JR_LOOP_IND], \
								(counter_end_nr-counter_start_nr), 2*k*m*n); \
	} \
	\
    bli_mem_release( &c2_L2_mem ); \
	bli_mem_release( &c1_L2_mem ); \
	bli_mem_release( &c0_L2_mem ); \
	if((MKSTR(ch)=="c")==0) \
	{\
	bli_mem_release( &a2_L1_mem ); \
	bli_mem_release( &a1_L1_mem ); \
	bli_mem_release( &b1_L1_mem ); \
	}\
	if ( emt_handle_b != NULL ) \
    { \
		bli_dma_channel_release(emt_handle_b, lib_get_coreID()); \
		emt_handle_b = NULL; \
    } \
    if ( emt_handle_c0 != NULL ) \
    { \
        bli_dma_channel_release(emt_handle_c0, lib_get_coreID()); \
        emt_handle_c0 = NULL; \
    } \
    if ( emt_handle_c1 != NULL ) \
    { \
        lib_emt_wait(emt_handle_c1); /* wait for save c to complete */ \
        bli_dma_channel_release(emt_handle_c1, lib_get_coreID()); \
        emt_handle_c1 = NULL; \
    } \
}

INSERT_GENTFUNC_BASIC2( trsm_rl_ker_var2, gemmtrsm_ukr_t, gemm_ukr_t )
#endif

#else

#undef  GENTFUNC
#define GENTFUNC( ctype, ch, varname, gemmtrsmtype, gemmtype ) \
\
void PASTEMAC(ch,varname)( \
                           doff_t  diagoffb, \
                           pack_t  schema_a, \
                           pack_t  schema_b, \
                           dim_t   m, \
                           dim_t   n, \
                           dim_t   k, \
                           void*   alpha1, \
                           void*   a, inc_t cs_a, inc_t pd_a, inc_t ps_a, \
                           void*   b, inc_t rs_b, inc_t pd_b, inc_t ps_b, \
                           void*   alpha2, \
                           void*   c, inc_t rs_c, inc_t cs_c, \
                           void*   gemmtrsm_ukr, \
                           void*   gemm_ukr, \
                           trsm_thrinfo_t* thread \
                         ) \
{ \
	/* Cast the micro-kernels' addresses to their function pointer types. */ \
	PASTECH(ch,gemmtrsmtype) gemmtrsm_ukr_cast = gemmtrsm_ukr; \
	PASTECH(ch,gemmtype)     gemm_ukr_cast     = gemm_ukr; \
\
	/* Temporary C buffer for edge cases. */ \
	ctype           ct[ PASTEMAC(ch,maxnr) * \
	                    PASTEMAC(ch,maxmr) ] \
	                    __attribute__((aligned(BLIS_STACK_BUF_ALIGN_SIZE))); \
	const inc_t     rs_ct      = 1; \
	const inc_t     cs_ct      = PASTEMAC(ch,maxnr); \
\
	/* Alias some constants to simpler names. */ \
	const dim_t     MR         = pd_a; \
	const dim_t     NR         = pd_b; \
	const dim_t     PACKMR     = cs_a; \
	const dim_t     PACKNR     = rs_b; \
\
	ctype* restrict zero        = PASTEMAC(ch,0); \
	ctype* restrict minus_one   = PASTEMAC(ch,m1); \
	ctype* restrict a_cast      = a; \
	ctype* restrict b_cast      = b; \
	ctype* restrict c_cast      = c; \
	ctype* restrict alpha1_cast = alpha1; \
	ctype* restrict alpha2_cast = alpha2; \
	ctype* restrict b1; \
	ctype* restrict c1; \
\
	doff_t          diagoffb_j; \
	dim_t           k_full; \
	dim_t           m_iter, m_left; \
	dim_t           n_iter, n_left; \
	dim_t           m_cur; \
	dim_t           n_cur; \
	dim_t           k_b1121; \
	dim_t           k_b11; \
	dim_t           k_b21; \
	dim_t           off_b11; \
	dim_t           off_b21; \
	dim_t           i, j, jb; \
	inc_t           rstep_a; \
	inc_t           cstep_b; \
	inc_t           rstep_c, cstep_c; \
	inc_t           istep_a; \
	inc_t           istep_b; \
	inc_t           off_scl; \
	inc_t           ss_b_num; \
	inc_t           ss_b_den; \
	inc_t           ps_b_cur; \
	auxinfo_t       aux; \
\
	/*
	   Assumptions/assertions:
	     rs_a == 1
	     cs_a == PACKNR
	     pd_a == NR
	     ps_a == stride to next micro-panel of A
	     rs_b == PACKMR
	     cs_b == 1
	     pd_b == MR
	     ps_b == stride to next micro-panel of B
	     rs_c == (no assumptions)
	     cs_c == (no assumptions)

	  Note that MR/NR and PACKMR/PACKNR have been swapped to reflect the
	  swapping of values in the control tree (ie: those values used when
	  packing). This swapping is needed since we cast right-hand trsm in
	  terms of transposed left-hand trsm. So, if we're going to be
	  transposing the operation, then A needs to be packed with NR and B
	  needs to be packed with MR (remember: B is the triangular matrix in
	  the right-hand side parameter case).
	*/ \
\
	/* If any dimension is zero, return immediately. */ \
	if ( bli_zero_dim3( m, n, k ) ) return; \
\
	/* Safeguard: If the current panel of B is entirely above its diagonal,
	   it is implicitly zero. So we do nothing. */ \
	if ( bli_is_strictly_above_diag_n( diagoffb, k, n ) ) return; \
\
	/* Compute k_full as k inflated up to a multiple of NR. This is
	   needed because some parameter combinations of trsm reduce k
	   to advance past zero regions in the triangular matrix, and
	   when computing the imaginary stride of B (the non-triangular
	   matrix), which is used by 3m and 4m implementations, we need
	   this unreduced value of k. */ \
	k_full = ( k % NR != 0 ? k + NR - ( k % NR ) : k ); \
\
	/* Compute indexing scaling factor for for 4m or 3m. This is
	   needed because one of the packing register blocksizes (PACKMR
	   or PACKNR) is used to index into the micro-panels of the non-
	   triangular matrix when computing with a diagonal-intersecting
	   micro-panel of the triangular matrix. In the case of 4m or 3m,
	   real values are stored in both sub-panels, and so the indexing
	   needs to occur in units of real values. The value computed
	   here is divided into the complex pointer offset to cause the
	   pointer to be advanced by the correct value. */ \
	if ( bli_is_4m_packed( schema_b ) || \
	     bli_is_3m_packed( schema_b ) || \
	     bli_is_rih_packed( schema_b ) ) off_scl = 2; \
	else                                 off_scl = 1; \
\
	/* Compute the storage stride. Usually this is just PACKMR (for A
	   or PACKNR (for B). However, in the case of 3m, we need to scale
	   the offset by 3/2. Since it's possible we may need to scale
	   the packing dimension by a non-integer value, we break up the
	   scaling factor into numerator and denominator. */ \
	if ( bli_is_3m_packed( schema_b ) ) { ss_b_num = 3*PACKNR; \
	                                      ss_b_den = 2; } \
	else                                { ss_b_num = 1*PACKNR; \
	                                      ss_b_den = 1; } \
\
	/* If there is a zero region above where the diagonal of B intersects
	   the left edge of the panel, adjust the pointer to A and treat this
	   case as if the diagonal offset were zero. Note that we don't need to
	   adjust the pointer to B since packm would have simply skipped over
	   the region that was not stored. */ \
	if ( diagoffb < 0 ) \
	{ \
		j        = -diagoffb; \
		k        = k - j; \
		diagoffb = 0; \
		a_cast   = a_cast + ( j * PACKMR ) / off_scl; \
	} \
\
	/* If there is a zero region to the right of where the diagonal
	   of B intersects the bottom of the panel, shrink it so that
	   we can index to the correct place in C (corresponding to the
	   part of the panel of B that was packed).
	   NOTE: This is NOT being done to skip over "no-op" iterations,
	   as with the trsm_lu macro-kernel. This MUST be done for correct
	   execution because we use n (via n_iter) to compute diagonal and
	   index offsets for backwards movement through B. */ \
	if ( diagoffb + k < n ) \
	{ \
		n = diagoffb + k; \
	} \
\
	/* Check the k dimension, which needs to be a multiple of NR. If k
	   isn't a multiple of NR, we adjust it higher to satisfy the micro-
	   kernel, which is expecting to perform an NR x NR triangular solve.
	   This adjustment of k is consistent with what happened when B was
	   packed: all of its bottom/right edges were zero-padded, and
	   furthermore, the panel that stores the bottom-right corner of the
	   matrix has its diagonal extended into the zero-padded region (as
	   identity). This allows the trsm of that bottom-right panel to
	   proceed without producing any infs or NaNs that would infect the
	   "good" values of the corresponding block of A. */ \
	if ( k % NR != 0 ) k += NR - ( k % NR ); \
\
	/* NOTE: We don't need to check that n is a multiple of PACKNR since we
	   know that the underlying buffer was already allocated to have an n
	   dimension that is a multiple of PACKNR, with the region between the
	   last column and the next multiple of NR zero-padded accordingly. */ \
\
	/* Clear the temporary C buffer in case it has any infs or NaNs. */ \
	PASTEMAC(ch,set0s_mxn)( MR, NR, \
	                        ct, rs_ct, cs_ct ); \
\
	/* Compute number of primary and leftover components of the m and n
       dimensions. */ \
	n_iter = n / NR; \
	n_left = n % NR; \
\
	m_iter = m / MR; \
	m_left = m % MR; \
\
	if ( n_left ) ++n_iter; \
	if ( m_left ) ++m_iter; \
\
	/* Determine some increments used to step through A, B, and C. */ \
	rstep_a = ps_a; \
\
	cstep_b = ps_b; \
\
	rstep_c = rs_c * MR; \
	cstep_c = cs_c * NR; \
\
	istep_a = PACKMR * k_full; \
	istep_b = PACKNR * k; \
\
	/* Save the pack schemas of A and B to the auxinfo_t object.
	   NOTE: We swap the values for A and B since the triangular
	   "A" matrix is actually contained within B. */ \
	bli_auxinfo_set_schema_a( schema_b, aux ); \
	bli_auxinfo_set_schema_b( schema_a, aux ); \
\
	/* Save the imaginary stride of A to the auxinfo_t object.
	   NOTE: We swap the values for A and B since the triangular
	   "A" matrix is actually contained within B. */ \
	bli_auxinfo_set_is_b( istep_a, aux ); \
\
	b1 = b_cast; \
	c1 = c_cast; \
\
	/* Loop over the n dimension (NR columns at a time). */ \
	for ( jb = 0; jb < n_iter; ++jb ) \
	{ \
		ctype* restrict a1; \
		ctype* restrict c11; \
		ctype* restrict b11; \
		ctype* restrict b21; \
		ctype* restrict b2; \
\
		j          = n_iter - 1 - jb; \
		diagoffb_j = diagoffb - ( doff_t )j*NR; \
		a1         = a_cast; \
		c11        = c1 + (n_iter-1)*cstep_c; \
\
		n_cur = ( bli_is_not_edge_b( jb, n_iter, n_left ) ? NR : n_left ); \
\
		/* Initialize our next panel of B to be the current panel of B. */ \
		b2 = b1; \
\
		/* If the current panel of B intersects the diagonal, use a
		   special micro-kernel that performs a fused gemm and trsm.
		   If the current panel of B resides below the diagonal, use a
		   a regular gemm micro-kernel. Otherwise, if it is above the
		   diagonal, it was not packed (because it is implicitly zero)
		   and so we do nothing. */ \
		if ( bli_intersects_diag_n( diagoffb_j, k, NR ) ) \
		{ \
			/* Determine the offset to and length of the panel that was packed
			   so we can index into the corresponding location in A. */ \
			off_b11   = bli_max( -diagoffb_j, 0 ); \
			k_b1121   = k - off_b11; \
			k_b11     = NR; \
			k_b21     = k_b1121 - NR; \
			off_b21   = off_b11 + k_b11; \
\
			/* Compute the addresses of the triangular block B11 and the
			   panel B21. */ \
			b11       = b1; \
			b21       = b1 + ( k_b11 * PACKNR ) / off_scl; \
\
			/* Compute the panel stride for the current micro-panel. */ \
			ps_b_cur = ( k_b1121 * ss_b_num ) / ss_b_den; \
\
			/* Save the imaginary stride of B to the auxinfo_t object.
			   NOTE: We swap the values for A and B since the triangular
			   "A" matrix is actually contained within B. */ \
			bli_auxinfo_set_is_a( PACKNR * k_b1121, aux ); \
\
			/* Loop over the m dimension (MR rows at a time). */ \
			for ( i = 0; i < m_iter; ++i ) \
			{ \
				if( trsm_my_iter( i, thread ) ){ \
\
				ctype* restrict a11; \
				ctype* restrict a12; \
				ctype* restrict a2; \
\
				m_cur = ( bli_is_not_edge_f( i, m_iter, m_left ) ? MR : m_left ); \
\
				/* Compute the addresses of the A11 block and A12 panel. */ \
				a11  = a1 + ( off_b11 * PACKMR ) / off_scl; \
				a12  = a1 + ( off_b21 * PACKMR ) / off_scl; \
\
				/* Compute the addresses of the next panels of A and B. */ \
				a2 = a1; \
				/*if ( bli_is_last_iter( i, m_iter, 0, 1 ) ) */\
				if ( i + thread_num_threads(thread) >= m_iter ) \
				{ \
					a2 = a_cast; \
					b2 = b1 + ps_b_cur; \
					if ( bli_is_last_iter( jb, n_iter, 0, 1 ) ) \
						b2 = b_cast; \
				} \
\
				/* Save addresses of next panels of A and B to the auxinfo_t
				   object. NOTE: We swap the values for A and B since the
				   triangular "A" matrix is actually contained within B. */ \
				bli_auxinfo_set_next_a( b2, aux ); \
				bli_auxinfo_set_next_b( a2, aux ); \
\
				/* Handle interior and edge cases separately. */ \
				if ( m_cur == MR && n_cur == NR ) \
				{ \
					/* Invoke the fused gemm/trsm micro-kernel. */ \
					gemmtrsm_ukr_cast( k_b21, \
					                   alpha1_cast, \
					                   b21, \
					                   b11, \
					                   a12, \
					                   a11, \
					                   c11, cs_c, rs_c, \
					                   &aux ); \
				} \
				else \
				{ \
					/* Invoke the fused gemm/trsm micro-kernel. */ \
					gemmtrsm_ukr_cast( k_b21, \
					                   alpha1_cast, \
					                   b21, \
					                   b11, \
					                   a12, \
					                   a11, \
					                   ct, cs_ct, rs_ct, \
					                   &aux ); \
\
					/* Copy the result to the bottom edge of C. */ \
					PASTEMAC(ch,copys_mxn)( m_cur, n_cur, \
					                        ct,  rs_ct, cs_ct, \
					                        c11, rs_c,  cs_c ); \
				} \
				} \
\
				a1  += rstep_a; \
				c11 += rstep_c; \
			} \
\
			b1 += ps_b_cur; \
		} \
		else if ( bli_is_strictly_below_diag_n( diagoffb_j, k, NR ) ) \
		{ \
			/* Save the imaginary stride of B to the auxinfo_t object.
			   NOTE: We swap the values for A and B since the triangular
			   "A" matrix is actually contained within B. */ \
			bli_auxinfo_set_is_a( istep_b, aux ); \
\
			/* Loop over the m dimension (MR rows at a time). */ \
			for ( i = 0; i < m_iter; ++i ) \
			{ \
				if( trsm_my_iter( i, thread ) ){ \
\
				ctype* restrict a2; \
\
				m_cur = ( bli_is_not_edge_f( i, m_iter, m_left ) ? MR : m_left ); \
\
				/* Compute the addresses of the next panels of A and B. */ \
				a2 = a1; \
				/*if ( bli_is_last_iter( i, m_iter, 0, 1 ) ) */\
				if ( i + thread_num_threads(thread) >= m_iter ) \
				{ \
					a2 = a_cast; \
					b2 = b1 + cstep_b; \
					if ( bli_is_last_iter( jb, n_iter, 0, 1 ) ) \
						b2 = b_cast; \
				} \
\
				/* Save addresses of next panels of A and B to the auxinfo_t
				   object. NOTE: We swap the values for A and B since the
				   triangular "A" matrix is actually contained within B. */ \
				bli_auxinfo_set_next_a( b2, aux ); \
				bli_auxinfo_set_next_b( a2, aux ); \
\
				/* Handle interior and edge cases separately. */ \
				if ( m_cur == MR && n_cur == NR ) \
				{ \
					/* Invoke the gemm micro-kernel. */ \
					gemm_ukr_cast( k, \
					               minus_one, \
					               b1, \
					               a1, \
					               alpha2_cast, \
					               c11, cs_c, rs_c, \
					               &aux ); \
				} \
				else \
				{ \
					/* Invoke the gemm micro-kernel. */ \
					gemm_ukr_cast( k, \
					               minus_one, \
					               b1, \
					               a1, \
					               zero, \
					               ct, cs_ct, rs_ct, \
					               &aux ); \
\
					/* Add the result to the edge of C. */ \
					PASTEMAC(ch,xpbys_mxn)( m_cur, n_cur, \
					                        ct,  rs_ct, cs_ct, \
					                        alpha2_cast, \
					                        c11, rs_c,  cs_c ); \
				} \
				} \
\
				a1  += rstep_a; \
				c11 += rstep_c; \
			} \
\
			b1 += cstep_b; \
		} \
\
		c1 -= cstep_c; \
	} \
}

INSERT_GENTFUNC_BASIC2( trsm_rl_ker_var2, gemmtrsm_ukr_t, gemm_ukr_t )

#endif
