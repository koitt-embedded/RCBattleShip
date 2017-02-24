/*
 * Copyright (c) 2013, Texas Instruments Incorporated
 * http://www.ti.com
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

#include <c6x.h>
#include <ti/runtime/openmp/src/tomp_init.h>
#include <ti/runtime/openmp/src/tomp_config.h>

extern far int main(int argc, char *argv[]);

static void entryFuncBios(void);


/**
 * RTSC mode: Custom _args_main to switch SP (if specified) and call main
 *
 * Replaces _args_main from C6000 RTS in RTSC mode. Cannot call main via a 
 * XDC Startup.lastFxns hook because any entry in lastFxns after the OpenMP
 * runtime entry calling main call will NOT be executed. 
 */
void _args_main(void)
{
    tomp_OmpStartCommon(&entryFuncBios);
}

typedef struct { int argc; char *argv[1]; } ARGS;
extern ARGS __c_args__;
#define NO_C_ARGS   ((unsigned int)-1)

void entryFuncBios(void)
{
    if (DNUM == TOMP_MASTER_CORE_IDX)
    {
#pragma diag_suppress 1107,173
        register ARGS *pargs = (ARGS*)_symval(&__c_args__);
#pragma diag_default 1107,173
        register int    argc = 0;
        register char **argv = 0;
   

        if (_symval(&__c_args__) != NO_C_ARGS)
        { argc = pargs->argc; argv = pargs->argv; }

        main(argc, argv);

        // Terminate dispatch loops on worker cores and free up hardware
        // resources.
        __TI_omp_terminate();
    }
    else
    {
        // Never returns. Worker cores exit when they get an exit event
        while(1) 
            tomp_dispatch_once();
    }
}


