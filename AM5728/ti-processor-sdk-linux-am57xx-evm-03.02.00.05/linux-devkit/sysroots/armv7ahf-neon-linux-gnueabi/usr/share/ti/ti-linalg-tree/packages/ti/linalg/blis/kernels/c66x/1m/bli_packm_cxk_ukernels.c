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

/* Need to implement optimization for various cases */

void bli_spackm_4xk_ukernel(
                           conj_t  conja,
                           dim_t   n,
                           void*   kappa,
                           void*   a, inc_t inca, inc_t lda, 
                           void*   p,             inc_t ldp
                      )
{

  float* restrict kappa_cast = kappa;
  dim_t index; 

  if(*kappa_cast == 1.0f)
  {
    if((inca==1) && ((lda&1)==0) && ((ldp&1)==0))
    {
      __float2_t *restrict ptrA0 = (__float2_t *) a;
      __float2_t *restrict ptrP0  = (__float2_t *) p;

      for(index=0;index<n;index++)
      {
        *ptrP0++ = *ptrA0++;
        *ptrP0++ = *ptrA0++;
        ptrA0 += ((lda>>1)-2);
        ptrP0 += ((ldp>>1)-2);
      }
      return;
    }
    else if((lda==1) && ((ldp&1) == 0) && ((inca&1)==0))
    {
      __float2_t *restrict ptrA0 = (__float2_t *) a;
      __float2_t *restrict ptrA1 = (__float2_t *) (((float *) a)+inca);
      __float2_t *restrict ptrA2 = (__float2_t *) (((float *) a)+2*inca);
      __float2_t *restrict ptrA3 = (__float2_t *) (((float *) a)+3*inca);
      __float2_t *restrict ptrP0  = (__float2_t *) p;
      __float2_t *restrict ptrP1  = (__float2_t *) (((float *) p)+ldp);
      __float2_t val0, val1;
      dim_t           n_iter     = n >> 1;
      dim_t           n_left     = n & 1;

      for(index=0;index<n_iter;index++)
      {
        val0 = *ptrA0++;
        val1 = *ptrA1++;
        *ptrP0++ = _ftof2(_lof(val1),_lof(val0));
        *ptrP1++ = _ftof2(_hif(val1),_hif(val0));
        val0 = *ptrA2++;
        val1 = *ptrA3++;
        *ptrP0++ = _ftof2(_lof(val1),_lof(val0));
        *ptrP1++ = _ftof2(_hif(val1),_hif(val0));
        ptrP0 += ((ldp)-2);
        ptrP1 += ((ldp)-2);
      }
      if(n_left)
      {
        float *restrict ptrA = ((float *) a+2*n_iter);
        float *restrict ptrP = ((float *) p+2*n_iter*ldp);
        ptrP[0] = ptrA[0];
        ptrP[1] = ptrA[inca];
        ptrP[2] = ptrA[2*inca];
        ptrP[3] = ptrA[3*inca];
      }   
      return;  
    }
  }

  /* handle unoptimized case using default packing routine */
  bli_spackm_ref_4xk(conja, n, kappa, a, inca, lda, p, ldp);
}

void bli_spackm_8xk_ukernel(
                           conj_t  conja,
                           dim_t   n,
                           void*   kappa,
                           void*   a, inc_t inca, inc_t lda, 
                           void*   p,             inc_t ldp
                      )
{

  float* restrict kappa_cast = kappa;
  dim_t index;

  if(*kappa_cast == 1.0f)
  {
    if((inca==1) && ((lda&1)==0) && ((ldp&1)==0))
    {
      __float2_t *restrict ptrA0 = (__float2_t *) a;
      __float2_t *restrict ptrP0  = (__float2_t *) p;
      for(index=0;index<n;index++)
      {
        *ptrP0++ = *ptrA0++;
        *ptrP0++ = *ptrA0++;
        *ptrP0++ = *ptrA0++;
        *ptrP0++ = *ptrA0++;
        ptrA0 += ((lda>>1)-4);
        ptrP0 += ((ldp>>1)-4);
      }
    return;
    }
    else if((lda==1) && ((ldp&1) == 0) && ((inca&1)==0))
    {
      __float2_t *restrict ptrA0 = (__float2_t *) a;
      __float2_t *restrict ptrA1 = (__float2_t *) (((float *) a)+inca);
      __float2_t *restrict ptrA2 = (__float2_t *) (((float *) a)+2*inca);
      __float2_t *restrict ptrA3 = (__float2_t *) (((float *) a)+3*inca);
      __float2_t *restrict ptrA4 = (__float2_t *) (((float *) a)+4*inca);
      __float2_t *restrict ptrA5 = (__float2_t *) (((float *) a)+5*inca);
      __float2_t *restrict ptrA6 = (__float2_t *) (((float *) a)+6*inca);
      __float2_t *restrict ptrA7 = (__float2_t *) (((float *) a)+7*inca);
      __float2_t *restrict ptrP0  = (__float2_t *) p;
      __float2_t *restrict ptrP1  = (__float2_t *) (((float *) p)+ldp);
      __float2_t val0, val1;
      dim_t           n_iter     = n >> 1;
      dim_t           n_left     = n & 1;
      for(index=0;index<n_iter;index++)
      {
        val0 = *ptrA0++;
        val1 = *ptrA1++;
        *ptrP0++ = _ftof2(_lof(val1),_lof(val0));
        *ptrP1++ = _ftof2(_hif(val1),_hif(val0));
        val0 = *ptrA2++;
        val1 = *ptrA3++;
        *ptrP0++ = _ftof2(_lof(val1),_lof(val0));
        *ptrP1++ = _ftof2(_hif(val1),_hif(val0));
        val0 = *ptrA4++;
        val1 = *ptrA5++;
        *ptrP0++ = _ftof2(_lof(val1),_lof(val0));
        *ptrP1++ = _ftof2(_hif(val1),_hif(val0));
        val0 = *ptrA6++;
        val1 = *ptrA7++;
        *ptrP0++ = _ftof2(_lof(val1),_lof(val0));
        *ptrP1++ = _ftof2(_hif(val1),_hif(val0));
        ptrP0 += ((ldp)-4);
        ptrP1 += ((ldp)-4);
      }
      if(n_left)
      {
        float *restrict ptrA = ((float *) a+2*n_iter);
        float *restrict ptrP = ((float *) p+2*n_iter*ldp);
        ptrP[0] = ptrA[0];
        ptrP[1] = ptrA[inca];
        ptrP[2] = ptrA[2*inca];
        ptrP[3] = ptrA[3*inca];
        ptrP[4] = ptrA[4*inca];
        ptrP[5] = ptrA[5*inca];
        ptrP[6] = ptrA[6*inca];
        ptrP[7] = ptrA[7*inca];
      }
      return;    
    }
  }
  /* handle unoptimized case using default packing routine */
  bli_spackm_ref_8xk(conja, n, kappa, a, inca, lda, p, ldp);
}

