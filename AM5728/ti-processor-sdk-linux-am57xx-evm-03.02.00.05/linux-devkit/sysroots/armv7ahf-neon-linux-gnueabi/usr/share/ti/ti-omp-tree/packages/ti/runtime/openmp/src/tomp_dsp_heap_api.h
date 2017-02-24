/*
 * Copyright (c) 2014, Texas Instruments Incorporated - http://www.ti.com/
 *   All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *      * Redistributions of source code must retain the above copyright
 *        notice, this list of conditions and the following disclaimer.
 *      * Redistributions in binary form must reproduce the above copyright
 *        notice, this list of conditions and the following disclaimer in the
 *        documentation and/or other materials provided with the distribution.
 *      * Neither the name of Texas Instruments Incorporated nor the
 *        names of its contributors may be used to endorse or promote products
 *        derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE.
 */
/**
 * \file tomp_dsp_heap_api.h
 */

#ifndef _TOMP_DSP_HEAP_API_H_
#define _TOMP_DSP_HEAP_API_H_

typedef int ti_omp_dsp_heap_idx;

void  __ti_dsp_heap_init(ti_omp_dsp_heap_idx idx, char *ptr, int size);
void *__ti_dsp_malloc   (ti_omp_dsp_heap_idx idx, int size);
void *__ti_dsp_realloc  (ti_omp_dsp_heap_idx idx, void *ptr, int size);
void  __ti_dsp_free     (ti_omp_dsp_heap_idx idx, void *ptr);
void *__ti_dsp_calloc   (ti_omp_dsp_heap_idx idx, int num, int size);
void *__ti_dsp_memalign (ti_omp_dsp_heap_idx idx, int alignment, int size);

void tomp_dsp_heap_init(ti_omp_dsp_heap_idx idx, char *ptr, int size);

#endif

