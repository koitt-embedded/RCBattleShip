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
#include "blis.h"

void bli_sgemm_ukernel_4x8(
		dim_t              k,
		float*    restrict alpha,
		float*    restrict a,
		float*    restrict b,
		float*    restrict beta,
		float*    restrict c, inc_t rs_c, inc_t cs_c,
		auxinfo_t*         data
)
{
	__float2_t sum0, sum1, sum2, sum3, sum4, sum5, sum6, sum7;
	__float2_t sum8, sum9, suma, sumb, sumc, sumd, sume, sumf;
	__float2_t * restrict ptrB     = (__float2_t *) b;
	__float2_t * restrict ptrA     = (__float2_t *) a;
	__float2_t * restrict ptrC;
	__float2_t regA2;
	int_least16_t index;
	__float2_t regB2;

	//touch routine: both a & b
	//Length of b = NR*K*size of float;
#ifdef BLIS_ENABLE_PREFETCH
	//touch(a, k*BLIS_DEFAULT_MR_S*4);
#endif

	// zero out accumulators
	sum0 = 0.0;
	sum1 = 0.0;
	sum2 = 0.0;
	sum3 = 0.0;
	sum4 = 0.0;
	sum5 = 0.0;
	sum6 = 0.0;
	sum7 = 0.0;
	sum8 = 0.0;
	sum9 = 0.0;
	suma = 0.0;
	sumb = 0.0;
	sumc = 0.0;
	sumd = 0.0;
	sume = 0.0;
	sumf = 0.0;


	for (index = 0; index < k; index++)
	{ // loop over k;
	// each iteration performs rank one update of 4x1 by 1x8
		// matrices of A and B respectively; result is
		// accumulated over 4x8 matrix
		__float2_t b01, b23, b45, b67, a01, a23;
		__x128_t   reg128;

		a01 = *ptrA++;
		a23 = *ptrA++;

		b01 = *ptrB++;
		b23 = *ptrB++;
		b45 = *ptrB++;
		b67 = *ptrB++;

		reg128 = _cmpysp(a01, b01);
		// accumulate a[0]*b[1] and -a[0]*b[0]
		sum0 = _daddsp(sum0, _lof2_128(reg128));
		// accumulate a[1]*b[0] and a[1]*b[1]
		sum1 = _daddsp(sum1, _hif2_128(reg128));

		reg128 = _cmpysp(a01, b23);
		// accumulate a[0]*b[3] and -a[0]*b[2]
		sum2 = _daddsp(sum2, _lof2_128(reg128));
		// accumulate a[1]*b[2] and a[1]*b[3]
		sum3 = _daddsp(sum3, _hif2_128(reg128));

		reg128 = _cmpysp(a01, b45);
		// accumulate a[0]*b[5] and -a[0]*b[4]
		sum4 = _daddsp(sum4, _lof2_128(reg128));
		// accumulate a[1]*b[4] and a[1]*b[5]
		sum5 = _daddsp(sum5, _hif2_128(reg128));

		reg128 = _cmpysp(a01, b67);
		// accumulate a[0]*b[7] and -a[0]*b[6]
		sum6 = _daddsp(sum6, _lof2_128(reg128));
		// accumulate a[1]*b[6] and a[1]*b[7]
		sum7 = _daddsp(sum7, _hif2_128(reg128));

		reg128 = _cmpysp(a23, b01);
		// accumulate a[2]*b[1] and -a[2]*b[0]
		sum8 = _daddsp(sum8, _lof2_128(reg128));
		// accumulate a[3]*b[0] and a[3]*b[1]
		sum9 = _daddsp(sum9, _hif2_128(reg128));

		reg128 = _cmpysp(a23, b23);
		// accumulate a[2]*b[3] and -a[2]*b[2]
		suma = _daddsp(suma, _lof2_128(reg128));
		// accumulate a[3]*b[2] and a[3]*b[3]
		sumb = _daddsp(sumb, _hif2_128(reg128));

		reg128 = _cmpysp(a23, b45);
		// accumulate a[2]*b[5] and -a[2]*b[4]
		sumc = _daddsp(sumc, _lof2_128(reg128));
		// accumulate a[3]*b[4] and a[3]*b[5]
		sumd = _daddsp(sumd, _hif2_128(reg128));

		reg128 = _cmpysp(a23, b67);
		// accumulate a[2]*b[7] and -a[2]*b[6]
		sume = _daddsp(sume, _lof2_128(reg128));
		// accumulate a[3]*b[6] and a[3]*b[7]
		sumf = _daddsp(sumf, _hif2_128(reg128));

	}

	regA2 = _ftof2(*alpha, *alpha);
	regB2 = _ftof2(*beta, *beta);
	if (rs_c != 1)
	{
		__float2_t c0, c1, c2, c3, c4, c5, c6, c7;
		__float2_t c8, c9, ca, cb, cc, cd, ce, cf;

		ptrC = (__float2_t *) c;
		c0 = *ptrC++; //c[0,0] and c[0,1]
		c1 = *ptrC--; //c[0,2] and c[0,3]
		ptrC += (rs_c>>1);
		c4 = *ptrC++; //c[1,0] and c[1,1]
		c5 = *ptrC--; //c[1,2] and c[1,3]
		ptrC += (rs_c>>1);
		c8 = *ptrC++; //c[2,0] and c[2,1]
		c9 = *ptrC--; //c[2,2] and c[2,3]
		ptrC += (rs_c>>1);
		cc = *ptrC++; //c[3,0] and c[3,1]
		cd = *ptrC--; //c[3,2] and c[3,3]

		ptrC = (__float2_t *) c + 2;
		c2 = *ptrC++; //c[0,4] and c[0,5]
		c3 = *ptrC--; //c[0,6] and c[0,7]
		ptrC += (rs_c>>1);
		c6 = *ptrC++; //c[1,4] and c[1,5]
		c7 = *ptrC--; //c[1,6] and c[1,7]
		ptrC += (rs_c>>1);
		ca = *ptrC++; //c[2,4] and c[2,5]
		cb = *ptrC--; //c[2,6] and c[2,7]
		ptrC += (rs_c>>1);
		ce = *ptrC++; //c[3,4] and c[3,5]
		cf = *ptrC;   //c[3,6] and c[3,7]

		sum0 = _dmpysp(regA2, sum0);
		sum1 = _dmpysp(regA2, sum1);
		sum2 = _dmpysp(regA2, sum2);
		sum3 = _dmpysp(regA2, sum3);
		sum4 = _dmpysp(regA2, sum4);
		sum5 = _dmpysp(regA2, sum5);
		sum6 = _dmpysp(regA2, sum6);
		sum7 = _dmpysp(regA2, sum7);
		sum8 = _dmpysp(regA2, sum8);
		sum9 = _dmpysp(regA2, sum9);
		suma = _dmpysp(regA2, suma);
		sumb = _dmpysp(regA2, sumb);
		sumc = _dmpysp(regA2, sumc);
		sumd = _dmpysp(regA2, sumd);
		sume = _dmpysp(regA2, sume);
		sumf = _dmpysp(regA2, sumf);

		c0 = _dmpysp(c0, regB2);
		c1 = _dmpysp(c1, regB2);
		c2 = _dmpysp(c2, regB2);
		c3 = _dmpysp(c3, regB2);
		c4 = _dmpysp(c4, regB2);
		c5 = _dmpysp(c5, regB2);
		c6 = _dmpysp(c6, regB2);
		c7 = _dmpysp(c7, regB2);
		c8 = _dmpysp(c8, regB2);
		c9 = _dmpysp(c9, regB2);
		ca = _dmpysp(ca, regB2);
		cb = _dmpysp(cb, regB2);
		cc = _dmpysp(cc, regB2);
		cd = _dmpysp(cd, regB2);
		ce = _dmpysp(ce, regB2);
		cf = _dmpysp(cf, regB2);

		// update c[0,0] and c[1,0]
		c0 = _daddsp(_ftof2(_lof2(sum0),-_hif2(sum0)),c0);
		// update c[0,2] and c[0,3]
		c1 = _daddsp(_ftof2(_lof2(sum2),-_hif2(sum2)),c1);
		//update c[0,4] and c[0,5]
		c2 = _daddsp(_ftof2(_lof2(sum4),-_hif2(sum4)),c2);
		// update c[0,6] and c[0,7]
		c3 = _daddsp(_ftof2(_lof2(sum6),-_hif2(sum6)),c3);

		//update c[1,0] and c[1,1]
		c4 = _daddsp(_ftof2(_hif2(sum1),_lof2(sum1)),c4);
		//update c[1,2] and c[1,3]
		c5 = _daddsp(_ftof2(_hif2(sum3),_lof2(sum3)),c5);
		//update c[1,4] and c[1,5]
		c6 = _daddsp(_ftof2(_hif2(sum5),_lof2(sum5)),c6);
		//update c[1,6] and c[1,7]
		c7 = _daddsp(_ftof2(_hif2(sum7),_lof2(sum7)),c7);

		// update c[2,0] and c[2,0]
		c8 = _daddsp(_ftof2(_lof2(sum8),-_hif2(sum8)),c8);
		// update c[2,2] and c[2,3]
		c9 = _daddsp(_ftof2(_lof2(suma),-_hif2(suma)),c9);
		//update c[2,4] and c[2,5]
		ca = _daddsp(_ftof2(_lof2(sumc),-_hif2(sumc)),ca);
		// update c[2,6] and c[2,7]
		cb = _daddsp(_ftof2(_lof2(sume),-_hif2(sume)),cb);

		//update c[3,0] and c[3,1]
		cc = _daddsp(_ftof2(_hif2(sum9),_lof2(sum9)),cc);
		//update c[3,2] and c[3,3]
		cd = _daddsp(_ftof2(_hif2(sumb),_lof2(sumb)),cd);
		//update c[3,4] and c[3,5]
		ce = _daddsp(_ftof2(_hif2(sumd),_lof2(sumd)),ce);
		//update c[3,6] and c[3,7]
		cf = _daddsp(_ftof2(_hif2(sumf),_lof2(sumf)),cf);

//		// update c[0,0] and c[1,0]
//		c0 = (c + 0*rs_c + 0*cs_c);
//		c1 = (c + 1*rs_c + 0*cs_c);
//		regC = _ftof2(*c1,*c0);
//		regC = _dmpysp(regC, regB2);
//		regS = _ftof2(_lof2(sum1),-_hif2(sum0));
//		regR = _daddsp(_dmpysp(regA2, regS), regC);
//		*c0 = _lof2(regR);
//		*c1 = _hif2(regR);
//
//		//update c[0,1] and c[1,1]
//		c0 = c0 + 1*cs_c;
//		c1 = c1 + 1*cs_c;
//		regC = _ftof2(*c1,*c0);
//		regC = _dmpysp(regC, regB2);
//		regS = _ftof2(_hif2(sum1),_lof2(sum0));
//		regR = _daddsp(_dmpysp(regA2, regS), regC);
//		*c0 = _lof2(regR);
//		*c1 = _hif2(regR);
//
//		//update c[0,2] and c[1,2]
//		c0 = c0 + 1*cs_c;
//		c1 = c1 + 1*cs_c;
//		regC = _ftof2(*c1,*c0);
//		regC = _dmpysp(regC, regB2);
//		regS = _ftof2(_lof2(sum3),-_hif2(sum2));
//		regR = _daddsp(_dmpysp(regA2, regS), regC);
//		*c0 = _lof2(regR);
//		*c1 = _hif2(regR);
//
//		//update  c[0,3] and c[1,3]
//		c0 = c0 + 1*cs_c;
//		c1 = c1 + 1*cs_c;
//		regC = _ftof2(*c1,*c0);
//		regC = _dmpysp(regC, regB2);
//		regS = _ftof2(_hif2(sum3),_lof2(sum2));
//		regR = _daddsp(_dmpysp(regA2, regS), regC);
//		*c0 = _lof2(regR);
//		*c1 = _hif2(regR);
//
//		//update c[0,4] and c[1,4]
//		c0 = c0 + 1*cs_c;
//		c1 = c1 + 1*cs_c;
//		regC = _ftof2(*c1,*c0);
//		regC = _dmpysp(regC, regB2);
//		regS = _ftof2(_lof2(sum5),-_hif2(sum4));
//		regR = _daddsp(_dmpysp(regA2, regS), regC);
//		*c0 = _lof2(regR);
//		*c1 = _hif2(regR);
//
//		//update c[0,5] and c[1,5]
//		c0 = c0 + 1*cs_c;
//		c1 = c1 + 1*cs_c;
//		regC = _ftof2(*c1,*c0);
//		regC = _dmpysp(regC, regB2);
//		regS = _ftof2(_hif2(sum5),_lof2(sum4));
//		regR = _daddsp(_dmpysp(regA2, regS), regC);
//		*c0 = _lof2(regR);
//		*c1 = _hif2(regR);
//
//		//update c[0,6] and c[1,6]
//		c0 = c0 + 1*cs_c;
//		c1 = c1 + 1*cs_c;
//		regC = _ftof2(*c1,*c0);
//		regC = _dmpysp(regC, regB2);
//		regS = _ftof2(_lof2(sum7),-_hif2(sum6));
//		regR = _daddsp(_dmpysp(regA2, regS), regC);
//		*c0 = _lof2(regR);
//		*c1 = _hif2(regR);
//
//		//update c[0,7] and c[1,7]
//		c0 = c0 + 1*cs_c;
//		c1 = c1 + 1*cs_c;
//		regC = _ftof2(*c1,*c0);
//		regC = _dmpysp(regC, regB2);
//		regS = _ftof2(_hif2(sum7),_lof2(sum6));
//		regR = _daddsp(_dmpysp(regA2, regS), regC);
//		*c0 = _lof2(regR);
//		*c1 = _hif2(regR);
//
//		// update c[2,0] and c[3,0]
//		c0 = (c + 2*rs_c + 0*cs_c);
//		c1 = (c + 3*rs_c + 0*cs_c);
//		regC = _ftof2(*c1,*c0);
//		regC = _dmpysp(regC, regB2);
//		regS = _ftof2(_lof2(sum9),-_hif2(sum8));
//		regR = _daddsp(_dmpysp(regA2, regS), regC);
//		*c0 = _lof2(regR);
//		*c1 = _hif2(regR);
//
//		// update c[2,1] and c[3,1]
//		c0 = c0 + 1*cs_c;
//		c1 = c1 + 1*cs_c;
//		regC = _ftof2(*c1,*c0);
//		regC = _dmpysp(regC, regB2);
//		regS = _ftof2(_hif2(sum9),_lof2(sum8));
//		regR = _daddsp(_dmpysp(regA2, regS), regC);
//		*c0 = _lof2(regR);
//		*c1 = _hif2(regR);
//
//		//update c[2,2] and c[3,2]
//		c0 = c0 + 1*cs_c;
//		c1 = c1 + 1*cs_c;
//		regC = _ftof2(*c1,*c0);
//		regC = _dmpysp(regC, regB2);
//		regS = _ftof2(_lof2(sumb),-_hif2(suma));
//		regR = _daddsp(_dmpysp(regA2, regS), regC);
//		*c0 = _lof2(regR);
//		*c1 = _hif2(regR);
//
//		//update  c[2,3] and c[3,3]
//		c0 = c0 + 1*cs_c;
//		c1 = c1 + 1*cs_c;
//		regC = _ftof2(*c1,*c0);
//		regC = _dmpysp(regC, regB2);
//		regS = _ftof2(_hif2(sumb),_lof2(suma));
//		regR = _daddsp(_dmpysp(regA2, regS), regC);
//		*c0 = _lof2(regR);
//		*c1 = _hif2(regR);
//
//		//update c[2,4] and c[3,4]
//		c0 = c0 + 1*cs_c;
//		c1 = c1 + 1*cs_c;
//		regC = _ftof2(*c1,*c0);
//		regC = _dmpysp(regC, regB2);
//		regS = _ftof2(_lof2(sumd),-_hif2(sumc));
//		regR = _daddsp(_dmpysp(regA2, regS), regC);
//		*c0 = _lof2(regR);
//		*c1 = _hif2(regR);
//
//		//update c[2,5] and c[3,5]
//		c0 = c0 + 1*cs_c;
//		c1 = c1 + 1*cs_c;
//		regC = _ftof2(*c1,*c0);
//		regC = _dmpysp(regC, regB2);
//		regS = _ftof2(_hif2(sumd),_lof2(sumc));
//		regR = _daddsp(_dmpysp(regA2, regS), regC);
//		*c0 = _lof2(regR);
//		*c1 = _hif2(regR);
//
//		//update c[2,6] and c[2,6]
//		c0 = c0 + 1*cs_c;
//		c1 = c1 + 1*cs_c;
//		regC = _ftof2(*c1,*c0);
//		regC = _dmpysp(regC, regB2);
//		regS = _ftof2(_lof2(sumf),-_hif2(sume));
//		regR = _daddsp(_dmpysp(regA2, regS), regC);
//		*c0 = _lof2(regR);
//		*c1 = _hif2(regR);
//
//		//update c[2,7] and c[2,7]
//		c0 = c0 + 1*cs_c;
//		c1 = c1 + 1*cs_c;
//		regC = _ftof2(*c1,*c0);
//		regC = _dmpysp(regC, regB2);
//		regS = _ftof2(_hif2(sumf),_lof2(sume));
//		regR = _daddsp(_dmpysp(regA2, regS), regC);
//		*c0 = _lof2(regR);
//		*c1 = _hif2(regR);

	}
	else
	{
		__float2_t c0, c1, c2, c3, c4, c5, c6, c7;
		__float2_t c8, c9, ca, cb, cc, cd, ce, cf;

		ptrC = (__float2_t *) c;
		c0 = *ptrC++; //c[0,0] and c[1,0]
		c1 = *ptrC--; //c[2,0] and c[3,0]
		ptrC += (cs_c>>1); // divide by 2 because ptrC is __float2_t, and cs_c is the stride for floats
		c2 = *ptrC++; //c[0,1] and c[1,1]
		c3 = *ptrC--; //c[2,1] and c[3,1]
		ptrC += (cs_c>>1);
		c4 = *ptrC++; //c[0,2] and c[1,2]
		c5 = *ptrC--; //c[2,2] and c[3,2]
		ptrC += (cs_c>>1);
		c6 = *ptrC++; //c[0,3] and c[1,3]
		c7 = *ptrC--; //c[2,3] and c[3,3]
		ptrC += (cs_c>>1);
		c8 = *ptrC++; //c[0,4] and c[1,0]
		c9 = *ptrC--; //c[2,4] and c[3,0]
		ptrC += (cs_c>>1);
		ca = *ptrC++; //c[0,5] and c[1,0]
		cb = *ptrC--; //c[2,5] and c[3,0]
		ptrC += (cs_c>>1);
		cc = *ptrC++; //c[0,6] and c[1,0]
		cd = *ptrC--; //c[2,6] and c[3,0]
		ptrC += (cs_c>>1);
		ce = *ptrC++; //c[0,7] and c[1,0]
		cf = *ptrC;   //c[2,7] and c[3,0]

		sum0 = _dmpysp(regA2, sum0);
		sum1 = _dmpysp(regA2, sum1);
		sum2 = _dmpysp(regA2, sum2);
		sum3 = _dmpysp(regA2, sum3);
		sum4 = _dmpysp(regA2, sum4);
		sum5 = _dmpysp(regA2, sum5);
		sum6 = _dmpysp(regA2, sum6);
		sum7 = _dmpysp(regA2, sum7);
		sum8 = _dmpysp(regA2, sum8);
		sum9 = _dmpysp(regA2, sum9);
		suma = _dmpysp(regA2, suma);
		sumb = _dmpysp(regA2, sumb);
		sumc = _dmpysp(regA2, sumc);
		sumd = _dmpysp(regA2, sumd);
		sume = _dmpysp(regA2, sume);
		sumf = _dmpysp(regA2, sumf);

		c0 = _dmpysp(c0, regB2);
		c1 = _dmpysp(c1, regB2);
		c2 = _dmpysp(c2, regB2);
		c3 = _dmpysp(c3, regB2);
		c4 = _dmpysp(c4, regB2);
		c5 = _dmpysp(c5, regB2);
		c6 = _dmpysp(c6, regB2);
		c7 = _dmpysp(c7, regB2);
		c8 = _dmpysp(c8, regB2);
		c9 = _dmpysp(c9, regB2);
		ca = _dmpysp(ca, regB2);
		cb = _dmpysp(cb, regB2);
		cc = _dmpysp(cc, regB2);
		cd = _dmpysp(cd, regB2);
		ce = _dmpysp(ce, regB2);
		cf = _dmpysp(cf, regB2);

		// update c[0,0] and c[1,0]
		c0 = _daddsp(_ftof2(_lof2(sum1),-_hif2(sum0)),c0);
		// update c[2,0] and c[3,0]
		c1 = _daddsp(_ftof2(_lof2(sum9),-_hif2(sum8)),c1);
		//update c[0,1] and c[1,1]
		c2 = _daddsp(_ftof2(_hif2(sum1),_lof2(sum0)),c2);
		// update c[2,1] and c[3,1]
		c3 = _daddsp(_ftof2(_hif2(sum9),_lof2(sum8)),c3);
		//update c[0,2] and c[1,2]
		c4 = _daddsp(_ftof2(_lof2(sum3),-_hif2(sum2)),c4);
		//update c[2,2] and c[3,2]
		c5 = _daddsp(_ftof2(_lof2(sumb),-_hif2(suma)),c5);
		//update  c[0,3] and c[1,3]
		c6 = _daddsp(_ftof2(_hif2(sum3),_lof2(sum2)),c6);
		//update  c[2,3] and c[3,3]
		c7 = _daddsp(_ftof2(_hif2(sumb),_lof2(suma)),c7);
		//update c[0,4] and c[1,4]
		c8 = _daddsp(_ftof2(_lof2(sum5),-_hif2(sum4)),c8);
		//update c[2,4] and c[3,4]
		c9 = _daddsp(_ftof2(_lof2(sumd),-_hif2(sumc)),c9);
		//update c[0,5] and c[1,5]
		ca = _daddsp(_ftof2(_hif2(sum5),_lof2(sum4)),ca);
		//update c[2,5] and c[3,5]
		cb = _daddsp(_ftof2(_hif2(sumd),_lof2(sumc)),cb);
		//update c[0,6] and c[1,6]
		cc = _daddsp(_ftof2(_lof2(sum7),-_hif2(sum6)),cc);
		//update c[2,6] and c[3,6]
		cd = _daddsp(_ftof2(_lof2(sumf),-_hif2(sume)),cd);
		//update c[0,7] and c[1,7]
		ce = _daddsp(_ftof2(_hif2(sum7),_lof2(sum6)),ce);
		//update c[2,7] and c[3,7]
		cf = _daddsp(_ftof2(_hif2(sumf),_lof2(sume)),cf);

		ptrC = (__float2_t *) c;
		*ptrC++ = c0;
		*ptrC-- = c1;
		ptrC += (cs_c>>1);
		*ptrC++ = c2;
		*ptrC-- = c3;
		ptrC += (cs_c>>1);
		*ptrC++ = c4;
		*ptrC-- = c5;
		ptrC += (cs_c>>1);
		*ptrC++ = c6;
		*ptrC-- = c7;
		ptrC += (cs_c>>1);
		*ptrC++ = c8;
		*ptrC-- = c9;
		ptrC += (cs_c>>1);
		*ptrC++ = ca;
		*ptrC-- = cb;
		ptrC += (cs_c>>1);
		*ptrC++ = cc;
		*ptrC-- = cd;
		ptrC += (cs_c>>1);
		*ptrC++ = ce;
		*ptrC = cf;
	}
}

void bli_sgemm_ukernel_4x4(
		dim_t              k,
		float*    restrict alpha,
		float*    restrict a,
		float*    restrict b,
		float*    restrict beta,
		float*    restrict c, inc_t rs_c, inc_t cs_c,
		auxinfo_t*         data
)
{
	__float2_t sum0, sum1, sum2, sum3, sum4, sum5, sum6, sum7;
	__float2_t sum8, sum9, suma, sumb, sumc, sumd, sume, sumf;
	__float2_t * restrict ptrB     = (__float2_t *) b;
	__float2_t * restrict ptrA     = (__float2_t *) a;
	__float2_t * restrict ptrC;
	__float2_t regA2, regB2;
	int_least16_t index;
	int kEven, kLeft;

	// zero out accumulators
	sum0 = 0.0;
	sum1 = 0.0;
	sum2 = 0.0;
	sum3 = 0.0;
	sum4 = 0.0;
	sum5 = 0.0;
	sum6 = 0.0;
	sum7 = 0.0;
	sum8 = 0.0;
	sum9 = 0.0;
	suma = 0.0;
	sumb = 0.0;
	sumc = 0.0;
	sumd = 0.0;
	sume = 0.0;
	sumf = 0.0;

	kEven=k>>1;
	kLeft=k&1;

	for (index = 0; index < kEven; index++)
	{ // loop over k;
		// each iteration performs rank one update of 4x1 by 1x4
		// matrices of A and B respectively; result is
		// accumulated over 4x4 matrix
		__float2_t b01, b23, a01, a23;
		__x128_t   reg128;

		// for even k
		a01 = *ptrA++;
		a23 = *ptrA++;

		b01 = *ptrB++;
		b23 = *ptrB++;

		reg128 = _cmpysp(a01, b01);
		// accumulate a[0]*b[1] and -a[0]*b[0]
		sum0 = _daddsp(sum0, _lof2_128(reg128));
		// accumulate a[1]*b[0] and a[1]*b[1]
		sum1 = _daddsp(sum1, _hif2_128(reg128));

		reg128 = _cmpysp(a01, b23);
		// accumulate a[0]*b[3] and -a[0]*b[2]
		sum2 = _daddsp(sum2, _lof2_128(reg128));
		// accumulate a[1]*b[2] and a[1]*b[3]
		sum3 = _daddsp(sum3, _hif2_128(reg128));

		reg128 = _cmpysp(a23, b01);
		// accumulate a[2]*b[1] and -a[2]*b[0]
		sum4 = _daddsp(sum4, _lof2_128(reg128));
		// accumulate a[3]*b[0] and a[3]*b[1]
		sum5 = _daddsp(sum5, _hif2_128(reg128));

		reg128 = _cmpysp(a23, b23);
		// accumulate a[2]*b[3] and -a[2]*b[2]
		sum6 = _daddsp(sum6, _lof2_128(reg128));
		// accumulate a[3]*b[2] and a[3]*b[3]
		sum7 = _daddsp(sum7, _hif2_128(reg128));



		// for odd k
		a01 = *ptrA++;
		a23 = *ptrA++;

		b01 = *ptrB++;
		b23 = *ptrB++;

		reg128 = _cmpysp(a01, b01);
		// accumulate a[0]*b[1] and -a[0]*b[0]
		sum8 = _daddsp(sum8, _lof2_128(reg128));
		// accumulate a[1]*b[0] and a[1]*b[1]
		sum9 = _daddsp(sum9, _hif2_128(reg128));

		reg128 = _cmpysp(a01, b23);
		// accumulate a[0]*b[3] and -a[0]*b[2]
		suma = _daddsp(suma, _lof2_128(reg128));
		// accumulate a[1]*b[2] and a[1]*b[3]
		sumb = _daddsp(sumb, _hif2_128(reg128));

		reg128 = _cmpysp(a23, b01);
		// accumulate a[2]*b[1] and -a[2]*b[0]
		sumc = _daddsp(sumc, _lof2_128(reg128));
		// accumulate a[3]*b[0] and a[3]*b[1]
		sumd = _daddsp(sumd, _hif2_128(reg128));

		reg128 = _cmpysp(a23, b23);
		// accumulate a[2]*b[3] and -a[2]*b[2]
		sume = _daddsp(sume, _lof2_128(reg128));
		// accumulate a[3]*b[2] and a[3]*b[3]
		sumf = _daddsp(sumf, _hif2_128(reg128));

	}
	if(kLeft)
	{ // last k if left;
		__float2_t b01, b23, a01, a23;
		__x128_t   reg128;

		a01 = *ptrA++;
		a23 = *ptrA++;

		b01 = *ptrB++;
		b23 = *ptrB++;

		reg128 = _cmpysp(a01, b01);
		// accumulate a[0]*b[1] and -a[0]*b[0]
		sum0 = _daddsp(sum0, _lof2_128(reg128));
		// accumulate a[1]*b[0] and a[1]*b[1]
		sum1 = _daddsp(sum1, _hif2_128(reg128));

		reg128 = _cmpysp(a01, b23);
		// accumulate a[0]*b[3] and -a[0]*b[2]
		sum2 = _daddsp(sum2, _lof2_128(reg128));
		// accumulate a[1]*b[2] and a[1]*b[3]
		sum3 = _daddsp(sum3, _hif2_128(reg128));

		reg128 = _cmpysp(a23, b01);
		// accumulate a[2]*b[1] and -a[2]*b[0]
		sum4 = _daddsp(sum4, _lof2_128(reg128));
		// accumulate a[3]*b[0] and a[3]*b[1]
		sum5 = _daddsp(sum5, _hif2_128(reg128));

		reg128 = _cmpysp(a23, b23);
		// accumulate a[2]*b[3] and -a[2]*b[2]
		sum6 = _daddsp(sum6, _lof2_128(reg128));
		// accumulate a[3]*b[2] and a[3]*b[3]
		sum7 = _daddsp(sum7, _hif2_128(reg128));

	}

	sum0 = _daddsp(sum0, sum8);
	sum1 = _daddsp(sum1, sum9);
	sum2 = _daddsp(sum2, suma);
	sum3 = _daddsp(sum3, sumb);
	sum4 = _daddsp(sum4, sumc);
	sum5 = _daddsp(sum5, sumd);
	sum6 = _daddsp(sum6, sume);
	sum7 = _daddsp(sum7, sumf);


	regA2 = _ftof2(*alpha, *alpha);
	regB2 = _ftof2(*beta, *beta);
	if (rs_c != 1)
	{
		__float2_t c0, c1, c2, c3, c4, c5, c6, c7;

		ptrC = (__float2_t *) c;
		c0 = *ptrC++; //c[0,0] and c[0,1]
		c1 = *ptrC--; //c[0,2] and c[0,3]
		ptrC += (rs_c>>1);
		c2 = *ptrC++; //c[1,0] and c[1,1]
		c3 = *ptrC--; //c[1,2] and c[1,3]
		ptrC += (rs_c>>1);
		c4 = *ptrC++; //c[2,0] and c[2,1]
		c5 = *ptrC--; //c[2,2] and c[2,3]
		ptrC += (rs_c>>1);
		c6 = *ptrC++; //c[3,0] and c[3,1]
		c7 = *ptrC--; //c[3,2] and c[3,3]

		sum0 = _dmpysp(regA2, sum0);
		sum1 = _dmpysp(regA2, sum1);
		sum2 = _dmpysp(regA2, sum2);
		sum3 = _dmpysp(regA2, sum3);
		sum4 = _dmpysp(regA2, sum4);
		sum5 = _dmpysp(regA2, sum5);
		sum6 = _dmpysp(regA2, sum6);
		sum7 = _dmpysp(regA2, sum7);

		c0 = _dmpysp(c0, regB2);
		c1 = _dmpysp(c1, regB2);
		c2 = _dmpysp(c2, regB2);
		c3 = _dmpysp(c3, regB2);
		c4 = _dmpysp(c4, regB2);
		c5 = _dmpysp(c5, regB2);
		c6 = _dmpysp(c6, regB2);
		c7 = _dmpysp(c7, regB2);

		// update c[0,0] and c[0,1]
		c0 = _daddsp(_ftof2(_lof2(sum0),-_hif2(sum0)),c0);
		// update c[0,2] and c[0,3]
		c1 = _daddsp(_ftof2(_lof2(sum2),-_hif2(sum2)),c1);
		// update c[1,0] and c[1,1]
		c2 = _daddsp(_ftof2(_hif2(sum1), _lof2(sum1)),c2);
		// update c[1,2] and c[1,2]
		c3 = _daddsp(_ftof2(_hif2(sum3),_lof2(sum3)),c3);
		// update c[2,0] and c[2,1]
		c4 = _daddsp(_ftof2(_lof2(sum4),-_hif2(sum4)),c4);
		// update c[2,2] and c[2,3]
		c5 = _daddsp(_ftof2(_lof2(sum6),-_hif2(sum6)),c5);
		// update c[3,0] and c[3,1]
		c6 = _daddsp(_ftof2(_hif2(sum5), _lof2(sum5)),c6);
		// update c[3,2] and c[3,2]
		c7 = _daddsp(_ftof2(_hif2(sum7),_lof2(sum7)),c7);

		ptrC = (__float2_t *) c;
		*ptrC++ = c0; //c[0,0] and c[0,1]
		*ptrC-- = c1; //c[0,2] and c[0,3]
		ptrC += (rs_c>>1);
		*ptrC++ = c2; //c[1,0] and c[1,1]
		*ptrC-- = c3; //c[1,2] and c[1,3]
		ptrC += (rs_c>>1);
		*ptrC++ = c4; //c[2,0] and c[2,1]
		*ptrC-- = c5; //c[2,2] and c[2,3]
		ptrC += (rs_c>>1);
		*ptrC++ = c6; //c[3,0] and c[3,1]
		*ptrC-- = c7; //c[3,2] and c[3,3]

//		// update c[0,0] and c[1,0]
//		c0 = (c + 0*rs_c + 0*cs_c);
//		c1 = (c + 1*rs_c + 0*cs_c);
//		regC = _ftof2(*c1,*c0);
//		regC = _dmpysp(regC, regB2);
//		regS = _ftof2(_lof2(sum1),-_hif2(sum0));
//		regR = _daddsp(_dmpysp(regA2, regS), regC);
//		*c0 = _lof2(regR);
//		*c1 = _hif2(regR);
//
//		//update c[0,1] and c[1,1]
//		c0 = c0 + 1*cs_c;
//		c1 = c1 + 1*cs_c;
//		regC = _ftof2(*c1,*c0);
//		regC = _dmpysp(regC, regB2);
//		regS = _ftof2(_hif2(sum1),_lof2(sum0));
//		regR = _daddsp(_dmpysp(regA2, regS), regC);
//		*c0 = _lof2(regR);
//		*c1 = _hif2(regR);
//
//		//update c[0,2] and c[1,2]
//		c0 = c0 + 1*cs_c;
//		c1 = c1 + 1*cs_c;
//		regC = _ftof2(*c1,*c0);
//		regC = _dmpysp(regC, regB2);
//		regS = _ftof2(_lof2(sum3),-_hif2(sum2));
//		regR = _daddsp(_dmpysp(regA2, regS), regC);
//		*c0 = _lof2(regR);
//		*c1 = _hif2(regR);
//
//		//update  c[0,3] and c[1,3]
//		c0 = c0 + 1*cs_c;
//		c1 = c1 + 1*cs_c;
//		regC = _ftof2(*c1,*c0);
//		regC = _dmpysp(regC, regB2);
//		regS = _ftof2(_hif2(sum3),_lof2(sum2));
//		regR = _daddsp(_dmpysp(regA2, regS), regC);
//		*c0 = _lof2(regR);
//		*c1 = _hif2(regR);
//
//		// update c[2,0] and c[3,0]
//		c0 = (c + 2*rs_c + 0*cs_c);
//		c1 = (c + 3*rs_c + 0*cs_c);
//		regC = _ftof2(*c1,*c0);
//		regC = _dmpysp(regC, regB2);
//		regS = _ftof2(_lof2(sum5),-_hif2(sum4));
//		regR = _daddsp(_dmpysp(regA2, regS), regC);
//		*c0 = _lof2(regR);
//		*c1 = _hif2(regR);
//
//		// update c[2,1] and c[3,1]
//		c0 = c0 + 1*cs_c;
//		c1 = c1 + 1*cs_c;
//		regC = _ftof2(*c1,*c0);
//		regC = _dmpysp(regC, regB2);
//		regS = _ftof2(_hif2(sum5),_lof2(sum4));
//		regR = _daddsp(_dmpysp(regA2, regS), regC);
//		*c0 = _lof2(regR);
//		*c1 = _hif2(regR);
//
//		//update c[2,2] and c[3,2]
//		c0 = c0 + 1*cs_c;
//		c1 = c1 + 1*cs_c;
//		regC = _ftof2(*c1,*c0);
//		regC = _dmpysp(regC, regB2);
//		regS = _ftof2(_lof2(sum7),-_hif2(sum6));
//		regR = _daddsp(_dmpysp(regA2, regS), regC);
//		*c0 = _lof2(regR);
//		*c1 = _hif2(regR);
//
//		//update  c[2,3] and c[3,3]
//		c0 = c0 + 1*cs_c;
//		c1 = c1 + 1*cs_c;
//		regC = _ftof2(*c1,*c0);
//		regC = _dmpysp(regC, regB2);
//		regS = _ftof2(_hif2(sum7),_lof2(sum6));
//		regR = _daddsp(_dmpysp(regA2, regS), regC);
//		*c0 = _lof2(regR);
//		*c1 = _hif2(regR);

	}
	else
	{
		__float2_t c0, c1, c2, c3, c4, c5, c6, c7;

		ptrC = (__float2_t *) c;
		c0 = *ptrC++;
		c1 = *ptrC--;
		ptrC += (cs_c>>1);
		c2 = *ptrC++;
		c3 = *ptrC--;
		ptrC += (cs_c>>1);
		c4 = *ptrC++;
		c5 = *ptrC--;
		ptrC += (cs_c>>1);
		c6 = *ptrC++;
		c7 = *ptrC--;

		sum0 = _dmpysp(regA2, sum0);
		sum1 = _dmpysp(regA2, sum1);
		sum2 = _dmpysp(regA2, sum2);
		sum3 = _dmpysp(regA2, sum3);
		sum4 = _dmpysp(regA2, sum4);
		sum5 = _dmpysp(regA2, sum5);
		sum6 = _dmpysp(regA2, sum6);
		sum7 = _dmpysp(regA2, sum7);

		c0 = _dmpysp(c0, regB2);
		c1 = _dmpysp(c1, regB2);
		c2 = _dmpysp(c2, regB2);
		c3 = _dmpysp(c3, regB2);
		c4 = _dmpysp(c4, regB2);
		c5 = _dmpysp(c5, regB2);
		c6 = _dmpysp(c6, regB2);
		c7 = _dmpysp(c7, regB2);

		// update c[0,0] and c[1,0]
		c0 = _daddsp(_ftof2(_lof2(sum1),-_hif2(sum0)),c0);
		// update c[2,0] and c[3,0]
		c1 = _daddsp(_ftof2(_lof2(sum5),-_hif2(sum4)),c1);
		//update c[0,1] and c[1,1]
		c2 = _daddsp(_ftof2(_hif2(sum1),_lof2(sum0)),c2);
		// update c[2,1] and c[3,1]
		c3 = _daddsp(_ftof2(_hif2(sum5),_lof2(sum4)),c3);
		//update c[0,2] and c[1,2]
		c4 = _daddsp(_ftof2(_lof2(sum3),-_hif2(sum2)),c4);
		//update c[2,2] and c[3,2]
		c5 = _daddsp(_ftof2(_lof2(sum7),-_hif2(sum6)),c5);
		//update  c[0,3] and c[1,3]
		c6 = _daddsp(_ftof2(_hif2(sum3),_lof2(sum2)),c6);
		//update  c[2,3] and c[3,3]
		c7 = _daddsp(_ftof2(_hif2(sum7),_lof2(sum6)),c7);

		ptrC = (__float2_t *) c;
		*ptrC++ = c0;
		*ptrC-- = c1;
		ptrC += (cs_c>>1);
		*ptrC++ = c2;
		*ptrC-- = c3;
		ptrC += (cs_c>>1);
		*ptrC++ = c4;
		*ptrC-- = c5;
		ptrC += (cs_c>>1);
		*ptrC++ = c6;
		*ptrC-- = c7;

	}
}


//void dgemmKernel(const double *pA, const double *pB, double *pC, const double a, const int k, const int stepC)
void bli_dgemm_ukernel_4x4(
		dim_t              k,
		double*    restrict alpha,
		double*    restrict a,
		double*    restrict b,
		double*    restrict beta,
		double*    restrict c, inc_t rs_c, inc_t cs_c,
		auxinfo_t*         data
)
{
	double sum00, sum01, sum02, sum03;
	double sum10, sum11, sum12, sum13;
	double sum20, sum21, sum22, sum23;
	double sum30, sum31, sum32, sum33;
	int index;
	double al = *alpha;
	double be = *beta;

	//touch routine: both a & b
	//Length of b = NR*K*size of double;
	//Length of a = MR*K*size of double;
#ifdef BLIS_ENABLE_PREFETCH
	//touch(b, k*BLIS_DEFAULT_NR_D*8);
	//touch(a, k*BLIS_DEFAULT_MR_D*8);
#endif

	sum00 = 0.0;
	sum01 = 0.0;
	sum02 = 0.0;
	sum03 = 0.0;
	sum10 = 0.0;
	sum11 = 0.0;
	sum12 = 0.0;
	sum13 = 0.0;
	sum20 = 0.0;
	sum21 = 0.0;
	sum22 = 0.0;
	sum23 = 0.0;
	sum30 = 0.0;
	sum31 = 0.0;
	sum32 = 0.0;
	sum33 = 0.0;

	for(index = 0; index < k; index++)
	{  // loop over k;
		// each iteration performs rank one update of 4x1 by 1x4
		// matrices of A and B respectively; result is
		// accumulated over 4x4 matrix
		register double a0, a1, a2, a3;
		register double b0, b1, b2, b3;

		a0 = *a++;
		a1 = *a++;
		a2 = *a++;
		a3 = *a++;
		b0 = *b++;
		b1 = *b++;
		b2 = *b++;
		b3 = *b++;

		// a[0]*b[0]
		sum00 += a0*b0;
		// a[0]*b[1]
		sum01 += a0*b1;
		// a[0]*b[2]
		sum02 += a0*b2;
		// a[0]*b[3]
		sum03 += a0*b3;
		// a[1]*b[0]
		sum10 += a1*b0;
		// a[1]*b[1]
		sum11 += a1*b1;
		// a[1]*b[2]
		sum12 += a1*b2;
		// a[1]*b[3]
		sum13 += a1*b3;
		// a[2]*b[0]
		sum20 += a2*b0;
		// a[2]*b[1]
		sum21 += a2*b1;
		// a[2]*b[2]
		sum22 += a2*b2;
		// a[2]*b[3]
		sum23 += a2*b3;
		// a[3]*b[0]
		sum30 += a3*b0;
		// a[3]*b[1]
		sum31 += a3*b1;
		// a[3]*b[2]
		sum32 += a3*b2;
		// a[3]*b[3]
		sum33 += a3*b3;
	}

	double* restrict cptr;
	// 0th Column
	// updating C[00]
	cptr = c;
	*cptr = *cptr * be;
	*cptr += sum00 * al;

	// updating C[10]
	cptr += rs_c;
	*cptr = *cptr*be;
	*cptr += sum10 * al;

	// updating C[20]
	cptr += rs_c;
	*cptr = *cptr*be;
	*cptr += sum20 * al;

	// updating C[30]
	cptr += rs_c;
	*cptr = *cptr*be;
	*cptr += sum30 * al;

	// 1st column
	// updating C[01]
	cptr = c + cs_c;
	*cptr = *cptr*be;
	*cptr += sum01 * al;

	// updating C[11]
	cptr += rs_c;
	*cptr = *cptr*be;
	*cptr += sum11 * al;

	// updating C[21]
	cptr += rs_c;
	*cptr = *cptr*be;
	*cptr += sum21 * al;

	// updating C[31]
	cptr += rs_c;
	*cptr = *cptr*be;
	*cptr += sum31 * al;

	// 2nd Column
	// updating C[02]
	cptr = c + 2*cs_c;
	*cptr = *cptr*be;
	*cptr += sum02 * al;

	// updating C[12]
	cptr += rs_c;
	*cptr = *cptr*be;
	*cptr += sum12 * al;

	// updating C[22]
	cptr += rs_c;
	*cptr = *cptr*be;
	*cptr += sum22 * al;

	// updating C[32]
	cptr += rs_c;
	*cptr = *cptr*be;
	*cptr += sum32 * al;

	// 3rd Column
	// updating C[03]
	cptr = c + 3*cs_c;
	*cptr = *cptr*be;
	*cptr += sum03 * al;

	// updating C[13]
	cptr += rs_c;
	*cptr = *cptr*be;
	*cptr += sum13 * al;

	// updating C[23]
	cptr += rs_c;
	*cptr = *cptr*be;
	*cptr += sum23 * al;

	// updating C[33]
	cptr += rs_c;
	*cptr = *cptr*be;
	*cptr += sum33 * al;

	return;
}

void bli_cgemm_ukernel_2x4(
		dim_t              k,
		scomplex* restrict alpha,
		scomplex* restrict a,
		scomplex* restrict b,
		scomplex* restrict beta,
		scomplex* restrict c, inc_t rs_c, inc_t cs_c,
		auxinfo_t*         data
)
{
	__float2_t sum00a, sum10a, sum00b, sum10b;
	__float2_t sum01a, sum11a, sum01b, sum11b;
	__float2_t sum02a, sum12a, sum02b, sum12b;
	__float2_t sum03a, sum13a, sum03b, sum13b;
	__float2_t * restrict ptrB     = (__float2_t *) b;
	__float2_t * restrict ptrA     = (__float2_t *) a;
	__float2_t * restrict ptrC;
	__float2_t regA, regB, regC;
	int_least16_t index;

	// zero out accumulators
	sum00a = 0.0;
	sum10a = 0.0;
	sum01a = 0.0;
	sum11a = 0.0;
	sum02a = 0.0;
	sum12a = 0.0;
	sum03a = 0.0;
	sum13a = 0.0;
	sum00b = 0.0;
	sum10b = 0.0;
	sum01b = 0.0;
	sum11b = 0.0;
	sum02b = 0.0;
	sum12b = 0.0;
	sum03b = 0.0;
	sum13b = 0.0;

	for (index = 0; index < k; index++)
	{ // loop over k;
		// each iteration performs rank one update of 2x1 by 1x4
		// matrices of A and B respectively; result is
		// accumulated over 2x4 matrix
		__float2_t b0, b1, b2, b3, a0, a1;
		__x128_t   reg128;

		a0 = *ptrA++;
		a1 = *ptrA++;

		b0 = *ptrB++;
		b1 = *ptrB++;
		b2 = *ptrB++;
		b3 = *ptrB++;

		// the four partial sums are accumulated independently
		// a[0]*b[0]
		reg128 = _cmpysp(a0, b0);
		sum00a = _daddsp(sum00a, _lof2_128(reg128));
		sum00b = _daddsp(sum00b, _hif2_128(reg128));

		// a[1]*b[0]
		reg128 = _cmpysp(a1, b0);
		sum10a = _daddsp(sum10a, _lof2_128(reg128));
		sum10b = _daddsp(sum10b, _hif2_128(reg128));

		// a[0]*b[1]
		reg128 = _cmpysp(a0, b1);
		sum01a = _daddsp(sum01a, _lof2_128(reg128));
		sum01b = _daddsp(sum01b, _hif2_128(reg128));

		// a[1]*b[1]
		reg128 = _cmpysp(a1, b1);
		sum11a = _daddsp(sum11a, _lof2_128(reg128));
		sum11b = _daddsp(sum11b, _hif2_128(reg128));

		// a[0]*b[2]
		reg128 = _cmpysp(a0, b2);
		sum02a = _daddsp(sum02a, _lof2_128(reg128));
		sum02b = _daddsp(sum02b, _hif2_128(reg128));

		// a[1]*b[2]
		reg128 = _cmpysp(a1, b2);
		sum12a = _daddsp(sum12a, _lof2_128(reg128));
		sum12b = _daddsp(sum12b, _hif2_128(reg128));

		// a[0]*b[3]
		reg128 = _cmpysp(a0, b3);
		sum03a = _daddsp(sum03a, _lof2_128(reg128));
		sum03b = _daddsp(sum03b, _hif2_128(reg128));

		// a[1]*b[3]
		reg128 = _cmpysp(a1, b3);
		sum13a = _daddsp(sum13a, _lof2_128(reg128));
		sum13b = _daddsp(sum13b, _hif2_128(reg128));
	}

	{
		__x128_t   reg128;
		ptrA  = (__float2_t *) alpha;
		ptrB =  (__float2_t *) beta;
		regA  = *ptrA;
		regB = *ptrB;

		// the value of a and the final values need to be
		// rearranged due to the specific way cmpysp assumes
		// data arrangement
		regA  =_ftof2(-_lof(regA), _hif(regA));
		//regB = _ftof2(_lof(regB),_hif(regB));
		ptrC  = (__float2_t *) c;

		// update and save c[0,0]
		sum00a = _daddsp(sum00a, sum00b);
		reg128 = _cmpysp(regA, sum00a);
		sum00a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
		regC = *ptrC;
		//regC = _ftof2(_lof(regC), _hif(regC));
		reg128 = _cmpysp(regC,regB);
		regC = _daddsp(_lof2_128(reg128),_hif2_128(reg128));
		*ptrC = _daddsp(_ftof2(-_lof(sum00a),_hif(sum00a)),_ftof2(_lof(regC),-_hif(regC)));

		ptrC = (__float2_t *) c + rs_c;

		// update and save c[1,0]
		sum10a = _daddsp(sum10a, sum10b);
		reg128 = _cmpysp(regA, sum10a);
		sum10a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
		regC = *ptrC;
		//regC = _ftof2(_lof(regC), _hif(regC));
		reg128 = _cmpysp(regC,regB);
		regC = _daddsp(_lof2_128(reg128),_hif2_128(reg128));
		*ptrC = _daddsp(_ftof2(-_lof(sum10a),_hif(sum10a)),_ftof2(_lof(regC),-_hif(regC)));


		ptrC = (__float2_t *) c + cs_c;

		// update and save c[0,1]
		sum01a = _daddsp(sum01a, sum01b);
		reg128 = _cmpysp(regA, sum01a);
		sum01a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
		regC = *ptrC;
		//regC = _ftof2(_lof(regC), _hif(regC));
		reg128 = _cmpysp(regC,regB);
		regC = _daddsp(_lof2_128(reg128),_hif2_128(reg128));
		*ptrC = _daddsp(_ftof2(-_lof(sum01a),_hif(sum01a)),_ftof2(_lof(regC),-_hif(regC)));

		ptrC = (__float2_t *) c + rs_c + cs_c;

		// update and save c[1,1]
		sum11a = _daddsp(sum11a, sum11b);
		reg128 = _cmpysp(regA, sum11a);
		sum11a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
		regC = *ptrC;
		//regC = _ftof2(_lof(regC), _hif(regC));
		reg128 = _cmpysp(regC,regB);
		regC = _daddsp(_lof2_128(reg128),_hif2_128(reg128));
		*ptrC = _daddsp(_ftof2(-_lof(sum11a),_hif(sum11a)),_ftof2(_lof(regC),-_hif(regC)));

		ptrC = (__float2_t *) c + 2 * cs_c;

		// update and save c[0,2]
		sum02a = _daddsp(sum02a, sum02b);
		reg128 = _cmpysp(regA, sum02a);
		sum02a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
		regC = *ptrC;
		//regC = _ftof2(_lof(regC), _hif(regC));
		reg128 = _cmpysp(regC,regB);
		regC = _daddsp(_lof2_128(reg128),_hif2_128(reg128));
		*ptrC = _daddsp(_ftof2(-_lof(sum02a),_hif(sum02a)),_ftof2(_lof(regC),-_hif(regC)));

		ptrC = (__float2_t *) c + rs_c + 2* cs_c;

		// update and save c[1,2]
		sum12a = _daddsp(sum12a, sum12b);
		reg128 = _cmpysp(regA, sum12a);
		sum12a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
		regC = *ptrC;
		//regC = _ftof2(_lof(regC), _hif(regC));
		reg128 = _cmpysp(regC,regB);
		regC = _daddsp(_lof2_128(reg128),_hif2_128(reg128));
		*ptrC = _daddsp(_ftof2(-_lof(sum12a),_hif(sum12a)),_ftof2(_lof(regC),-_hif(regC)));

		ptrC = (__float2_t *) c + 3 * cs_c;

		// update and save c[0,3]
		sum03a = _daddsp(sum03a, sum03b);
		reg128 = _cmpysp(regA, sum03a);
		sum03a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
		regC = *ptrC;
		//regC = _ftof2(_lof(regC), _hif(regC));
		reg128 = _cmpysp(regC,regB);
		regC = _daddsp(_lof2_128(reg128),_hif2_128(reg128));
		*ptrC = _daddsp(_ftof2(-_lof(sum03a),_hif(sum03a)),_ftof2(_lof(regC),-_hif(regC)));

		ptrC = (__float2_t *) c + rs_c + 3 * cs_c;

		// update and save c[1,3]
		sum13a = _daddsp(sum13a, sum13b);
		reg128 = _cmpysp(regA, sum13a);
		sum13a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
		regC = *ptrC;
		//regC = _ftof2(_lof(regC), _hif(regC));
		reg128 = _cmpysp(regC,regB);
		regC = _daddsp(_lof2_128(reg128),_hif2_128(reg128));
		*ptrC = _daddsp(_ftof2(-_lof(sum13a),_hif(sum13a)),_ftof2(_lof(regC),-_hif(regC)));
	}
	return;
}

void bli_zgemm_ukernel_2x2(
		dim_t              k,
		dcomplex* restrict alpha,
		dcomplex* restrict a,
		dcomplex* restrict b,
		dcomplex* restrict beta,
		dcomplex* restrict c, inc_t rs_c, inc_t cs_c,
		auxinfo_t*         data
)
{
	double * restrict ptrA = (double *) a;
	double * restrict ptrB = (double *) b;
	//double * restrict ptrC = (double *) c;
	double sum00r, sum00i;
	int index;
	int kEven = k&0xFFFE;

	sum00r = 0.0;
	sum00i = 0.0;

	if(k>4) // The loop is safe for k > 4
	{
#pragma UNROLL(2)
		for(index = 0; index<kEven; index++)
		{ // loop over k;
			// each iteration performs rank one update of 1x1 by 1x1
			// matrices of A and B respectively; result is
			// accumulated over 1x1 matrix
			double a0r, a0i;
			double b0r, b0i;

			a0r = *ptrA++;
			a0i = *ptrA++;

			b0r = *ptrB++;
			b0i = *ptrB++;

			sum00r += a0r*b0r;
			sum00r -= a0i*b0i;
			sum00i += a0r*b0i;
			sum00i += a0i*b0r;

		}
		if(k&1) // odd k; one left to do
		{
			double a0r, a0i;
			double b0r, b0i;

			a0r = *ptrA++;
			a0i = *ptrA++;

			b0r = *ptrB++;
			b0i = *ptrB++;

			sum00r += a0r*b0r;
			sum00r -= a0i*b0i;
			sum00i += a0r*b0i;
			sum00i += a0i*b0r;
		}
	}
	else
	{
		if(k>0)
		{
			double a0r, a0i;
			double b0r, b0i;

			a0r = *ptrA++;
			a0i = *ptrA++;

			b0r = *ptrB++;
			b0i = *ptrB++;

			sum00r += a0r*b0r;
			sum00r -= a0i*b0i;
			sum00i += a0r*b0i;
			sum00i += a0i*b0r;
		}
		if(k>1)
		{
			double a0r, a0i;
			double b0r, b0i;

			a0r = *ptrA++;
			a0i = *ptrA++;

			b0r = *ptrB++;
			b0i = *ptrB++;

			sum00r += a0r*b0r;
			sum00r -= a0i*b0i;
			sum00i += a0r*b0i;
			sum00i += a0i*b0r;
		}
		if(k>2)
		{
			double a0r, a0i;
			double b0r, b0i;

			a0r = *ptrA++;
			a0i = *ptrA++;

			b0r = *ptrB++;
			b0i = *ptrB++;

			sum00r += a0r*b0r;
			sum00r -= a0i*b0i;
			sum00i += a0r*b0i;
			sum00i += a0i*b0r;
		}
		if(k>3)
		{
			double a0r, a0i;
			double b0r, b0i;

			a0r = *ptrA++;
			a0i = *ptrA++;

			b0r = *ptrB++;
			b0i = *ptrB++;

			sum00r += a0r*b0r;
			sum00r -= a0i*b0i;
			sum00i += a0r*b0i;
			sum00i += a0i*b0r;
		}

	}

	{  // final saving
		double alphar, alphai, betar, betai, cr, ci;
		alphar = alpha->real;
		alphai = alpha->imag;
		betar  = beta->real;
		betai  = beta->imag;

		cr = c->real;
		ci = c->imag;

		c->imag = (betar * ci + betai * cr);
		c->real = (betar * cr - betai * ci);
		c->real += (alphar * sum00r - alphai * sum00i);
		c->imag += (alphar * sum00i + alphai * sum00r);
	}


	return;
}


