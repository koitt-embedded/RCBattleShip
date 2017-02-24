/*
 * Copyright (c) 2013-2015, Texas Instruments Incorporated
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

/*
 *  ======== App.c ========
 *
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#if defined(OS_QNX)
#include <ti/shmemallocator/SharedMemoryAllocatorUsr.h>
#endif

#include "App.h"
#include <machvis/MachVis.h>


/*
 *  ======== App_main ========
 */
int App_main(void)
{
    int status;
    bool initMachVis;
    int i;
    int32_t ret;
    uint32_t val;
    MachVis_Compute *compute;
#if defined(OS_QNX)
    shm_buf shmCompute, shmInBuf, shmOutBuf;
#endif


    /* initialize module (setup rpc connection) */
    status = MachVis_initialize();

    if (status < 0) {
        printf("App_main: Error: MachVis_initialize() failed, status=%d",
                status);
        initMachVis = false;
        status = -1;
        goto leave;
    }
    else {
        initMachVis = true;
    }

    /* invoke a function with two scalar values */
    status = MachVis_add(44, 66);

    printf("App_main: MachVis_add(44, 66), status=%d\n", status);

    if (status < 0) {
        printf("App_main: Error: MachVis_add() failed, status=%d", status);
        status = -1;
        goto leave;
    }
    else {
        status = 0;
    }

    /* allocate a compute structure in shared memory */
#if defined(OS_QNX)
    SHM_alloc(sizeof(MachVis_Compute), &shmCompute);
    compute = (MachVis_Compute *)(shmCompute.vir_addr);
#else
    /* Allocate memory here if on Linux */
    compute = NULL;
#endif

    if (compute == NULL) {
        /* temporary: memory alloc not implemented on Linux */
        goto leave;
    }

    /* initialize compute structure */
    compute->coef = 0xE0400000;
    compute->key = 0xABA0;
    compute->size = 0x1000;
    compute->inBuf = NULL;
    compute->outBuf = NULL;

    /* allocate an input buffer in shared memory */
#if defined(OS_QNX)
    SHM_alloc(compute->size * sizeof(uint32_t), &shmInBuf);
    compute->inBuf = (uint32_t *)(shmInBuf.vir_addr);
#else
    /* Allocate memory here if on Linux */
//  compute->inBuf = ...;
#endif

    if (compute->inBuf == NULL) {
        printf("App_main: Error: inBuf == NULL\n");
        status = -1;
        goto leave;
    }

    /* fill input buffer with seed value */
    for (i = 0; i < compute->size; i++) {
        compute->inBuf[i] = 0x2010;
    }

    /* allocate an output buffer in shared memory */
#if defined(OS_QNX)
    SHM_alloc(compute->size * sizeof(uint32_t), &shmOutBuf);
    compute->outBuf = (uint32_t *)(shmOutBuf.vir_addr);
#else
    /* Allocate memory here if on Linux */
//  compute->outBuf = ...;
#endif

    if (compute->outBuf == NULL) {
        printf("App_main: Error: outBuf == NULL\n");
        status = -1;
        goto leave;
    }

    /* clear output buffer */
    for (i = 0; i < compute->size; i++) {
        compute->outBuf[i] = 0;
    }

    /* print some debug info */
    printf("App_main: compute->coef=0x%x\n", compute->coef);
    printf("App_main: compute->key=0x%x\n", compute->key);
    printf("App_main: compute->size=0x%x\n", compute->size);
    printf("App_main: compute->inBuf=0x%x\n", (unsigned int)compute->inBuf);
    printf("App_main: compute->outBuf=0x%x\n", (unsigned int)compute->outBuf);

    /* process the buffer */
    printf("App_main: MachVis_compute(0x%x)\n", (unsigned int)compute);
    ret = MachVis_compute(compute);

    if (ret < 0) {
        status = -1;
        printf("App_main: Error: MachVis_Compute() failed\n");
        goto leave;
    }

    printf("App_main: compute->coef=0x%x\n", compute->coef);
    printf("App_main: compute->key=0x%x (expect 0xa0a0)\n", compute->key);
    printf("App_main: compute->size=0x%x\n", compute->size);
    printf("App_main: compute->inBuf=0x%x\n", (unsigned int)compute->inBuf);
    printf("App_main: compute->outBuf=0x%x\n", (unsigned int)compute->outBuf);
    printf("App_main: compute->inBuf[0]=0x%x (expect 0x2010)\n",
            (unsigned int)compute->inBuf[0]);
    printf("App_main: compute->outBuf[0]=0x%x (expect 0xe0402010)\n",
            (unsigned int)compute->outBuf[0]);

    /* check the output buffer */
    for (i = 0; i < compute->size; i++) {
        val = compute->inBuf[i] | compute->coef;
        if (compute->outBuf[i] != val) {
            status = -1;
            printf("App_main: Error: incorrect outBuf\n");
            break;
        }
    }

    /* free resources */
#if defined(OS_QNX)
    SHM_release(&shmOutBuf);
    SHM_release(&shmInBuf);
    SHM_release(&shmCompute);
#else
    /* Free memory here if on Linux */
//  ...
#endif

leave:
    /* finalize module (destroy rpc connection) */
    if (initMachVis) {
        MachVis_finalize();
    }

    return(status);
}
