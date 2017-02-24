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

#ifndef BLIS_PROFILE_H
#define BLIS_PROFILE_H

//#ifdef BLIS_ENABLE_C66X_BUILD
#define BLIS_PROFILE_BLK_VAR2_IND 	0
#define BLIS_PROFILE_BLK_VAR3_IND 	1
#define BLIS_PROFILE_BLK_VAR1_IND 	2
#define BLIS_PROFILE_KER_VAR2_IND 	3
#define BLIS_PROFILE_JR_LOOP_IND 	4
#define BLIS_PROFILE_IR_LOOP_IND 	5
#define BLIS_PROFILE_KER_LOOP_IND 	6
#define BLIS_PROFILE_NUM_REPORTS	7

#define MAX_THREADS 8

#ifdef BLIS_ENABLE_PROFILE

#define CLOCK 1.2 // In GHz

#ifdef BLIS_ENABLE_C66X_BUILD
#define OPS_PER_CYCLE_S 16
#define OPS_PER_CYCLE_D 4
#else
#define OPS_PER_CYCLE_S 8
#define OPS_PER_CYCLE_D 2
#endif


#define BLIS_ENABLE_PROFILE_KERVAR2 1
#else
#define BLIS_ENABLE_PROFILE_KERVAR2 0
#endif


struct profile_data_s
{
    uint64_t total_cycles;
    gint_t num_iter;
    uint64_t num_comp;
};
typedef struct profile_data_s profile_data_t;

struct profile_details_s
{
    dim_t m;
    dim_t n;
    dim_t k;
    long int cycles;
};
typedef struct profile_details_s profile_details_t;


#define bli_profile_data_update( bli_profile_data, cycles, comps) \
{ \
	bli_profile_data.total_cycles += cycles; \
	bli_profile_data.num_comp += comps; \
	bli_profile_data.num_iter++; \
}

#define bli_profile_get_index(n, i, index) \
{ \
	if(n == 1 && i == 2) \
		index = bli_get_thread_num()+BLIS_MAX_NUM_THREADS*BLIS_PROFILE_BLK_VAR2_IND; \
	else if(n == 2 && i == 2) \
		index = bli_get_thread_num()+BLIS_MAX_NUM_THREADS*BLIS_PROFILE_BLK_VAR3_IND; \
	else if(n == 0 && i == 2) \
		index = bli_get_thread_num()+BLIS_MAX_NUM_THREADS*BLIS_PROFILE_BLK_VAR1_IND; \
	else if(n == 1 && i == 1) \
		index = bli_get_thread_num()+BLIS_MAX_NUM_THREADS*BLIS_PROFILE_KER_VAR2_IND; \
}

profile_data_t* bli_profile_data_init (dim_t num_objects);

void bli_profile_data_free (profile_data_t *bli_profile_data);

//void bli_profile_data_update (profile_data_t *bli_profile_data, long int cycles, long int num_comp);

void bli_gemm_profile_data_print (profile_data_t *bli_gemm_profile_data, dim_t m, dim_t n, dim_t k, num_t datatype);

void bli_trsm_profile_data_print (profile_data_t *bli_trsm_profile_data, dim_t m, dim_t n, dim_t mn_side, num_t datatype);

void bli_gemm_kervar2_profile_data_print (profile_data_t *bli_kervar2_profile_data, dim_t m, dim_t n, dim_t k, num_t datatype);
void bli_trsm_kervar2_profile_data_print (profile_data_t *bli_kervar2_profile_data, dim_t m, dim_t n, dim_t k, num_t datatype);

void bli_profile_data_print (profile_data_t *bli_gemm_profile_data, dim_t m, dim_t n, dim_t k, num_t datatype, dim_t comp_scale, dim_t num_threads);

void bli_kervar2_profile_data_print (profile_data_t *bli_kervar2_profile_data, dim_t m, dim_t n, dim_t k, num_t datatype, dim_t comp_scale);



profile_details_t* bli_profile_details_init (long int num_objects);

void bli_profile_details_free (profile_details_t *bli_profile_details);

void bli_profile_details_update (profile_details_t *bli_profile_details, dim_t m, dim_t n, dim_t k, long int cycles);




#endif
