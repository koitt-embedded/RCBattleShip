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
#ifdef BLIS_ENABLE_PROFILE

void bli_profile_data_free(profile_data_t *bli_profile_data)
{
	if(bli_profile_data == NULL)
			printf("not allocated\n");

	bli_free(bli_profile_data);
}


profile_data_t * bli_profile_data_init(dim_t num_objects)
{
	dim_t i;
	profile_data_t *bli_profile_data;
	bli_profile_data = (profile_data_t *)bli_malloc(num_objects*sizeof(profile_data_t));
	if(bli_profile_data == NULL)
		printf("not allocated\n");
	for (i = 0; i < num_objects; i++)
	{
		(bli_profile_data[i]).total_cycles = 0;
		(bli_profile_data[i]).num_iter = 0;
		(bli_profile_data[i]).num_comp = 0;

	}

    return bli_profile_data;
}


void bli_profile_data_print (profile_data_t *bli_profile_data, dim_t m, dim_t n, dim_t k, num_t datatype, dim_t comp_scale, dim_t num_threads)
{
	dim_t n_ind, j;

   	dim_t index;

   	uint64_t num_iter;
   	//long int total_cycles_kervar2[3];

 	double ideal_gflops, gflops, total_cycles, num_ops, time_taken, num_ops_core;

 	if(datatype == 0 || datatype == 2)
 	{
 		num_ops =  ( (double) comp_scale * m * n * k );
 	}
 	else
 	{
 		// for complex numbers
 		num_ops =  ( (double) 4.0*comp_scale * m * n * k );
 	}

 	if(datatype == 0 || datatype == 1)
 	{
 		ideal_gflops = CLOCK*OPS_PER_CYCLE_S*num_threads;
 	}
 	else
 	{
 		ideal_gflops = CLOCK*OPS_PER_CYCLE_D*num_threads;
 	}
 	// print intro
   	printf("\n");
   	printf("Clock Frequency %4.1f GHz\n", CLOCK);
   	printf("Number of Threads %d\n", num_threads);
   	printf("Datatype %d Number of Operations: %f\n", datatype, num_ops);
   	printf("Operations per cycle %d\n", (datatype == 0 || datatype == 1) ? OPS_PER_CYCLE_S : OPS_PER_CYCLE_D);
   	printf("Peak GFLOPS %5.1f GFLOPS\n", ideal_gflops);
   	printf("\n");

   	// print table header
   	printf("%-10s", "Variant");
   	printf("%2s", "|");
   	printf("%5s", "Cores");
   	printf("%10s", "Num Iter");
   	printf("%15s", "Total Cycles");
   	printf("%10s", "GFLOPS");
   	printf("%12s", "Efficiency");

   	// print separator (scales with dimensions of sweep)
   	printf("\n");
   	printf("%-10s","----------");
   	printf("%2s", "--");
    printf("%10s", "----------");
    printf("%15s", "---------------");
    printf("%10s", "----------");
    printf("%12s", "------------");
   	printf("\n");


   	for (n_ind = 0; n_ind < BLIS_PROFILE_NUM_REPORTS; n_ind++)
   	{
   		if(n_ind < BLIS_PROFILE_KER_VAR2_IND)
   		{
   			index =  0 + BLIS_MAX_NUM_THREADS*n_ind;
   			if((bli_profile_data[index]).num_iter != 0)
   			{
   				total_cycles = ((double)(bli_profile_data[index]).total_cycles);
   				time_taken = total_cycles / CLOCK ;
   				gflops = num_ops / time_taken; // in 10^9
   				printf("%-10d",n_ind);
   				printf("%2s", "|");
   				printf("%5s", "1");
   				printf("%10d", (bli_profile_data[index]).num_iter);
   				printf("%15llu", (bli_profile_data[index]).total_cycles);
   				printf("%10.4f", gflops );
   				printf("%11.4f%%", gflops/ideal_gflops*100);
   				printf("\n");
   			}
   		}
   		else if(n_ind == BLIS_PROFILE_KER_VAR2_IND)
   		{
   			/*The total performance of the operation depends on the slowest thread in kervar2.
   			 * Hence, reporting the max cycles of the thread for ker_var2*/

   			num_iter = 0;
   			total_cycles = 0;

   			for (j = 0; j<num_threads; j++)
   			{
   				num_iter = bli_max(num_iter, (uint64_t) bli_profile_data[j+BLIS_MAX_NUM_THREADS*n_ind].num_iter) ;
   				total_cycles = bli_max(total_cycles, (double) bli_profile_data[j+BLIS_MAX_NUM_THREADS*n_ind].total_cycles);
   			}
   			if(num_iter != 0)
   			{
   				time_taken = total_cycles / CLOCK ;
   				gflops = num_ops / time_taken; // in 10^9
   				printf("%-10d",n_ind);
   				printf("%2s", "|");
   				printf("%5d", 1);
   				printf("%10llu", num_iter);
   				printf("%15llu", (uint64_t) total_cycles);
   				printf("%10.4f", gflops );
   				printf("%11.4f%%", gflops/ideal_gflops*100);
   				printf("\n");
   			}
   		}
   		else
   		{
   			num_iter = 0;
   			total_cycles = 0;

   			for (j = 0; j<num_threads; j++)
   			{
   				num_iter += (uint64_t) bli_profile_data[j+BLIS_MAX_NUM_THREADS*n_ind].num_iter ;
   				total_cycles += (double) bli_profile_data[j+BLIS_MAX_NUM_THREADS*n_ind].total_cycles;
   			}
   			if(num_iter != 0)
   			{
   				time_taken = total_cycles / CLOCK / num_threads ; // total cycles here are for all 8 cores, that is why we have to divide by num_threads to get the time taken for one core
   				gflops = num_ops / time_taken; // in 10^9
   				printf("%-10d",n_ind);
   				printf("%2s", "|");
   				printf("%5d", num_threads);
   				printf("%10llu", num_iter);
   				printf("%15llu", (uint64_t) total_cycles);
   				printf("%10.4f", gflops );
   				printf("%11.4f%%", gflops/ideal_gflops*100);
   				printf("\n");
   			}
   		}
   	}

   	printf("%-10s", "----------");
   	printf("%2s", "--");
   	printf("%10s", "----------");
   	printf("%15s", "---------------");
   	printf("%10s", "----------");
   	printf("%12s", "------------");
   	printf("\n");

   	printf("uKernel details for each core\n");

   	printf("%-10s", "Core #");
   	printf("%2s", "|");
   	printf("%15s", "Num. Computes");
   	printf("%15s", "Total Cycles");
   	printf("%10s", "GFLOPS");
   	printf("%12s", "Efficiency");
   	printf("\n");

   	n_ind = 6;
   	for (j = 0; j<num_threads; j++)
   	{
   		num_iter = (uint64_t) bli_profile_data[j+BLIS_MAX_NUM_THREADS*n_ind].num_iter ;
   		total_cycles = (double) bli_profile_data[j+BLIS_MAX_NUM_THREADS*n_ind].total_cycles;
   		if(datatype == 0 || datatype == 2)
   		   	num_ops_core = (double) bli_profile_data[j+BLIS_MAX_NUM_THREADS*n_ind].num_comp;
   		else
   			num_ops_core = (double) 4.0*bli_profile_data[j+BLIS_MAX_NUM_THREADS*n_ind].num_comp;

   		if(num_iter != 0)
   		{
   			time_taken = total_cycles / CLOCK ;
   			gflops = num_ops_core / time_taken; // in 10^9
   		 	if(datatype == 0 || datatype == 1)
   		 	{
   		 		ideal_gflops = CLOCK*OPS_PER_CYCLE_S;
   		 	}
   		 	else
   		 	{
   		 		ideal_gflops = CLOCK*OPS_PER_CYCLE_D;
   		 	}
   			printf("%-10d",j);
   			printf("%2s", "|");
   			printf("%15llu", (uint64_t) num_ops_core);
   			printf("%15llu", (uint64_t) total_cycles);
   			printf("%10.4f", gflops );
   			printf("%11.4f%%", gflops/ideal_gflops*100);
   			printf("\n");
   		}
   	}
   	printf("%-10s", "----------");
   	printf("%2s", "--");
   	printf("%10s", "----------");
   	printf("%15s", "---------------");
   	printf("%10s", "----------");
   	printf("%12s", "------------");
   	printf("\n");
}


void bli_kervar2_profile_data_print (profile_data_t *bli_kervar2_profile_data, dim_t m, dim_t n, dim_t k, num_t datatype, dim_t comp_scale)
{
//	dim_t i,j;
//
//	gint_t num_iter[3];
//    long int total_cycles[3];
//    gint_t min_cycles[3];
//    gint_t max_cycles[3];
//
//
//    double ideal_gflops, gflops, total_cycles_j, num_ops, time_taken;
//
//    num_ops = ( (float) comp_scale * (float) m * (float) n * (float) k );
//
//    if(datatype == 0 || datatype == 1)
//    {
//    	ideal_gflops = CLOCK*OPS_PER_CYCLE_S*NUM_THREADS;
//    }
//    else
//    {
//    	ideal_gflops = CLOCK*OPS_PER_CYCLE_D*NUM_THREADS;
//    }
//
//	for(i = 0; i<3; i++)
//	{
//		num_iter[i] = 0;
//		total_cycles[i] = 0;
//		min_cycles[i] = 0;
//		max_cycles[i] = 0;
//		for (j = 0; j<NUM_THREADS; j++)
//		{
//			num_iter[i] += bli_kervar2_profile_data[j*3+i].num_iter ;
//
//			total_cycles[i] += bli_kervar2_profile_data[j*3+i].total_cycles;
//			if(i == 0 )
//			{
//				min_cycles[i] = bli_kervar2_profile_data[j*3+i].min_cycles;
//				max_cycles[i] = bli_kervar2_profile_data[j*3+i].max_cycles;
//			}
//			else
//			{
//				if(bli_kervar2_profile_data[j*3+i].max_cycles > max_cycles[i])
//					max_cycles[i] = bli_kervar2_profile_data[j*3+i].max_cycles;
//				if(bli_kervar2_profile_data[j*3+i].min_cycles < min_cycles[i])
//					min_cycles[i] = bli_kervar2_profile_data[j*3+i].min_cycles;
//			}
//
//		}
//	}
//
//	for(i = 0; i<3; i++)
//		{
//			num_iter[i] = 0;
//			total_cycles[i] = 0;
//			min_cycles[i] = 0;
//			max_cycles[i] = 0;
//			for (j = 0; j<8; j++)
//			{
//				num_iter[i] += bli_kervar2_profile_data[j*3+i].num_iter ;
//
//				total_cycles[i] += bli_kervar2_profile_data[j*3+i].total_cycles;
//				if(i == 0 )
//				{
//					min_cycles[i] = bli_kervar2_profile_data[j*3+i].min_cycles;
//					max_cycles[i] = bli_kervar2_profile_data[j*3+i].max_cycles;
//				}
//				else
//				{
//					if(bli_kervar2_profile_data[j*3+i].max_cycles > max_cycles[i])
//						max_cycles[i] = bli_kervar2_profile_data[j*3+i].max_cycles;
//					if(bli_kervar2_profile_data[j*3+i].min_cycles < min_cycles[i])
//						min_cycles[i] = bli_kervar2_profile_data[j*3+i].min_cycles;
//				}
//
//			}
//		}
//
//	for(j = 0; j < 3; j++)
//	{
//		if(num_iter[j] != 0)
//		{
//
//			total_cycles_j = (double) total_cycles[j];
//			time_taken = total_cycles_j / CLOCK / NUM_THREADS;
//			gflops = num_ops / time_taken; // in 10^9
//			if(j == 0)
//				printf("%-10s","kernel");
//			else if(j ==1)
//				printf("%-10s","mr");
//			else
//				printf("%-10s","nr");
//
//			printf("%2s", "|");
//			printf("%10d", num_iter[j]);
//			printf("%15ld", total_cycles[j]);
//			printf("%10.4f", gflops);
//			printf("%11.4f%%", gflops/ideal_gflops*100);
//			printf("\n");
//		}
//	}
//#if 1
//	for(j = 0; j < 3; j++)
//	{
//		if(j == 0)
//			printf("%-10s\n","kernel");
//		else if(j ==1)
//			printf("%-10s\n","mr");
//		else
//			printf("%-10s\n","nr");
//
//		for(i = 0; i < 8; i++)
//		{
//			printf("core %d\t",i);
//			printf("%15ld\t", bli_kervar2_profile_data[i*3+j].total_cycles);
//			printf("%15ld\t", bli_kervar2_profile_data[i*3+j].num_comp);
//			printf("\n");
//		}
//	}
//#endif
}

void bli_trsm_kervar2_profile_data_print (profile_data_t *bli_kervar2_profile_data, dim_t m, dim_t n, dim_t k, num_t datatype)
{
//	dim_t i,j;
//
//	long int num_iter[3];
//    long int total_cycles[3];
//    gint_t min_cycles[3];
//    gint_t max_cycles[3];
//
//
//    double ideal_gflops, gflops, total_cycles_j, num_ops, time_taken;
//
//    num_ops = ( 1.0 * m * n * k );
//
//    if(datatype == 0 || datatype == 1)
//    {
//    	ideal_gflops = CLOCK*OPS_PER_CYCLE_S*NUM_THREADS;
//    }
//    else
//    {
//    	ideal_gflops = CLOCK*OPS_PER_CYCLE_D*NUM_THREADS;
//    }
//
//	for(i = 0; i<3; i++)
//	{
//		num_iter[i] = 0;
//		total_cycles[i] = 0;
//		min_cycles[i] = 0;
//		max_cycles[i] = 0;
//		for (j = 0; j<8; j++)
//		{
//			num_iter[i] += bli_kervar2_profile_data[j*3+i].num_iter ;
//
//			total_cycles[i] += bli_kervar2_profile_data[j*3+i].total_cycles;
//			if(i == 0 )
//			{
//				min_cycles[i] = bli_kervar2_profile_data[j*3+i].min_cycles;
//				max_cycles[i] = bli_kervar2_profile_data[j*3+i].max_cycles;
//			}
//			else
//			{
//				if(bli_kervar2_profile_data[j*3+i].max_cycles > max_cycles[i])
//					max_cycles[i] = bli_kervar2_profile_data[j*3+i].max_cycles;
//				if(bli_kervar2_profile_data[j*3+i].min_cycles < min_cycles[i])
//					min_cycles[i] = bli_kervar2_profile_data[j*3+i].min_cycles;
//			}
//
//		}
//	}
//
//	for(j = 0; j < 3; j++)
//	{
//		if(num_iter[j] != 0)
//		{
//			total_cycles_j = (double) total_cycles[j];
//			time_taken = total_cycles_j / CLOCK / NUM_THREADS;
//			gflops = num_ops / time_taken; // in 10^9
//			if(j == 0)
//				printf("%-10s","gemmtrsm");
//			else if(j ==1)
//				printf("%-10s","MR loop");
//			else
//				printf("%-10s","nr");
//
//			printf("%2s", "|");
//			printf("%10ld", num_iter[j]);
//			printf("%15ld", total_cycles[j]);
//			printf("%10.4f", gflops);
//			printf("%11.4f%%", gflops/ideal_gflops*100);
//			printf("\n");
//		}
//	}
//	printf("%-10s", "----------");
//	printf("%2s", "--");
//	printf("%10s", "----------");
//	printf("%15s", "---------------");
//	printf("%10s", "----------");
//	printf("%12s", "------------");
//
//	printf("\nNumber of loop iterations across cores %d\n", NUM_THREADS);
//
//	// print table header
//   	printf("%-10s", " ");
//   	printf("%2s", "|");
//   	printf("%12s", "Core 0");
//   	printf("%12s", "Core 1");
//   	printf("%12s", "Core 2");
//   	printf("%12s", "Core 3");
//   	printf("%12s", "Core 4");
//   	printf("%12s", "Core 5");
//   	printf("%12s", "Core 6");
//   	printf("%12s\n", "Core 7");
//
//	for(j = 0; j < 3; j++)
//	{
//		if(j == 0)
//			printf("%-10s","kernel");
//		else if(j ==1)
//			printf("%-10s","MR loop");
//		else
//			printf("%-10s","NR loop");
//
//		printf("%2s", "|");
//
//		for(i = 0; i < 8; i++)
//			printf("%12ld", bli_kervar2_profile_data[i*3+j].num_comp);
//
//		printf("\n");
//	}
//
//	for(j = 0; j < 3; j++)
//	{
//		if(j == 0)
//			printf("%-10s","kernel");
//		else if(j ==1)
//			printf("%-10s","MR loop");
//		else
//			printf("%-10s","NR loop");
//
//		printf("%2s", "|");
//
//		for(i = 0; i < 8; i++)
//			printf("%15ld", bli_kervar2_profile_data[i*3+j].total_cycles);
//
//		printf("\n");
//	}
}




#endif
