/*
 * Copyright (c) 2013, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/** ============================================================================
 *  @file       MachVis.h
 *
 *  @brief      Example of a host-side module which uses MmRpc to
 *              invoke functions on a remote processor.
 *
 *  ============================================================================
 */

#ifndef MachVis__include
#define MachVis__include

#include <stddef.h>
#include <stdint.h>

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 *  @brief      Operation is successful
 */
#define MachVis_S_SUCCESS (0)

/*!
 *  @brief      Operation failed
 */
#define MachVis_E_FAIL (-1)

/*!
 *  @brief      Compute structure
 */
typedef struct {
    uint32_t    coef;
    int         key;
    int         size;
    uint32_t *  inBuf;
    uint32_t *  outBuf;
} MachVis_Compute;

/*!
 *  @brief      Initialize the module, must be called first
 */
int MachVis_initialize(void);

/*!
 *  @brief      Finalize the module, must be called last
 */
void MachVis_finalize(void);

/*!
 *  @brief      Sample function which addes two arguments
 */
int32_t MachVis_add(int32_t a, int32_t b);

/*!
 *  @brief      Sample function which has pointer parameter to
 *              a structure with two embedded pointers.
 */
int32_t MachVis_compute(MachVis_Compute *compute);


#if defined(__cplusplus)
}
#endif
#endif /* MachVis__include */
