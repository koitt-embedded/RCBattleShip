/*
 * Copyright (c) 2013, Texas Instruments Incorporated - http://www.ti.com/
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
 * \file tomp_util.c
 * 
 * \brief Implements utility functions
 *      
 */

#include "tomp_util.h"
#include <stdlib.h>

typedef struct _tomp_CoreBarrier{
    uint8_t tbl0[TOMP_DEVICE_NUM_CORES];
    uint8_t tbl1[TOMP_DEVICE_NUM_CORES];
} tomp_CoreBarrier;

#pragma DATA_SECTION (tomp_svCoreBarrier, ".tomp_svNcMem");
tomp_CoreBarrier tomp_svCoreBarrier;

#pragma DATA_SECTION (tomp_gvCoreBarrierSense, ".tomp_gvMem");
uint8_t tomp_gvCoreBarrierSense = 0;

void tomp_waitAtCoreBarrier(void)
{
    volatile uint8_t* lvCoreBarrierPtr;
    volatile uint8_t lvGo=0;
    int i;

    if (tomp_gvCoreBarrierSense == 0)
    {
            lvCoreBarrierPtr=tomp_svCoreBarrier.tbl0;
            tomp_gvCoreBarrierSense = 1;
    }
    else
    {
            lvCoreBarrierPtr=tomp_svCoreBarrier.tbl1;
            tomp_gvCoreBarrierSense = 0;
    }

    for (i=TOMP_MASTER_CORE_IDX; i<TOMP_MASTER_CORE_IDX + TOMP_NUM_CORES; i++)
    {
            *(lvCoreBarrierPtr+i)=0;
    }

    while (!lvGo)
    {
            lvGo = 1;
            *(lvCoreBarrierPtr+DNUM)=1;
            for (i=TOMP_MASTER_CORE_IDX; 
                    i<TOMP_MASTER_CORE_IDX + TOMP_NUM_CORES; i++)
            {
                    lvGo = lvGo & *(lvCoreBarrierPtr+i);
            }
            *(lvCoreBarrierPtr+DNUM)=1;
    }
}

void tomp_resetCoreBarrier()
{
    tomp_gvCoreBarrierSense = 0;
}


void __gomp_flush0()
{
    tomp_cacheWbInvAll();
}

/* Defined in the C6000 RTS */
extern void   __TI_tls_init(void * TLS_block_addr);
extern size_t __TI_tls_block_size();


/**
 * Create and initialize the TLS block for a thread.
 * @return Initialized TLS block
 */
void *tomp_allocInitTLSBlock(void)
{
    size_t  lvTlsBlockSize = __TI_tls_block_size();

    if (lvTlsBlockSize == 0)
        return NULL;

    // Use malloc to allocate the TLS block
    void *lvPtr = malloc(lvTlsBlockSize);
        
    // Use the TLS init function provided by the C6x RTS to initialize TLS
    if (lvPtr != NULL) 
        __TI_tls_init(lvPtr);
    else
        tomp_logError(tomp_ErrorKind_NULL_PTR, __FILE__, __LINE__);

    return lvPtr;
}

/** 
 * Implements a core-level barrier. Used during OpenMP runtime initialization
 */
void __TI_omp_wait_at_core_barrier(void)
{
    tomp_waitAtCoreBarrier();
}
