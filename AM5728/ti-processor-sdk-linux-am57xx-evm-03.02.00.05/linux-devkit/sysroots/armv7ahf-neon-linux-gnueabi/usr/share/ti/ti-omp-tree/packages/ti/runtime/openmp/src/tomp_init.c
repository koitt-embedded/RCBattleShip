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
 * \file tomp_init.c
 * 
 * \brief Implements initialization/termination for OMP runtime
 *      
 */

#include "tomp_parallel.h"
#include "tomp_init.h"
#include "tomp_util.h"
#include <stdlib.h>
#include <limits.h>

/**
 * OpenMP local (per-core) initialization
 */
int tomp_initLocal(void)
{
    // Allocate a team state for the thread and initialize it to ensure 
    // orphaned constructs are handled correctly
    tomp_thread.ts = tomp_alloc_TeamState();
    tomp_clear_TeamState (tomp_thread.ts);

    // level is 0 outside parallel regions
    tomp_thread.ts->level = 0;

    tomp_thread.current_task = NULL;

    // Task stealing is disabled till a core participates in an OMP team by
    // dispatching an implicit task accociated with a parallel region
    tomp_thread.task_stealing = tomp_TaskStealing_DISABLED;

    return 0;
}


/**
 * Set icvs for master core's initial and implicit tasks
 */
void tomp_initIcv(void)
{
    struct gomp_task_icv *icv = &gomp_global_icv;
    tomp_initialTaskForMaster->icv = *icv;
    tomp_implicitTaskForMaster->icv = *icv;
}


/**
 * Set icvs for master core's initial and implicit tasks without
 * parsing the environment variables. Used in the OpenCL context.
 */
void tomp_initIcvNoParse(void)
{
    gomp_global_icv.nthreads_var       = TOMP_NUM_CORES;
    gomp_global_icv.run_sched_var      = GFS_DYNAMIC;
    gomp_global_icv.run_sched_modifier = 1;
    tomp_initIcv();

    gomp_max_active_levels_var = 1;
    gomp_thread_limit_var = ULONG_MAX;
}

#if 0 // __cleanup in 7.4.x C6X compiler
#if TOMP_DEVICE_HAS_HW_QUEUES
#if defined (TI_C6636)
#pragma WEAK(tomp_cioExitQmss)
extern void tomp_cioExitQmss(void);
extern void __TI_cleanup(void);
#endif
#endif // TOMP_DEVICE_HAS_HW_QUEUES
#endif

/**
 *  Called by all cores (master & workers) before exit 
 */
void tomp_exitProcessing(void)
{
    // ts can be NULL if allocation failed at startup
    if (tomp_thread.ts)
    {
        tomp_eventFree(tomp_thread.ts->event);
        tomp_thread.ts = NULL;
    }

#if 0 // __cleanup in 7.4.x C6X compiler
#if TOMP_DEVICE_HAS_HW_QUEUES
#if defined (TI_C6636)
#pragma diag_suppress 238
    if (&tomp_cioExitQmss)
        __TI_cleanup();
#pragma diag_default 238
#endif
#endif // TOMP_DEVICE_HAS_HW_QUEUES
#endif

    // Barrier to ensure that worker cores process the exit events before
    // the master core closes the queues & exits QMSS
    tomp_waitAtCoreBarrier();

    #pragma diag_suppress 238
    ulm_put_state(ULM_STATE_EXIT);
    #pragma diag_default 238
}


/** 
 *  Called by the worker cores (only) during program termination
 */
void tomp_exitLocalX (tomp_event_t eventHdl)
{
    tomp_exitProcessing();
    exit(0);
}


/**
 * Initialization function. Called only by the master core
 *
 * Sets up all the queues and associates them with execution objects
 */
int tomp_initParallel(void)
{
    int i;

    for (i = 0; i < TOMP_NUM_CORES - 1; i++)
    {
        // Static non-nested events for loop level parallelism
        tomp_eventHdlTbl[i] = tomp_eventAllocChecked (sizeof (tomp_Task),
                                                      __FILE__, __LINE__);
        tomp_taskPtrTbl[i] = (tomp_Task *)tomp_event_pointer(
                                                        tomp_eventHdlTbl[i]);
        tomp_taskPtrTbl[i]->event = tomp_eventHdlTbl[i];
        tomp_taskPtrTbl[i]->kind  = tomp_TaskKind_IMPLICIT;

        // Allocate and initialize TLS block for worker cores
        tomp_taskPtrTbl[i]->tls_block = tomp_allocInitTLSBlock();
    }
    
    // Create an initial task for master.
    tomp_event_t event = tomp_eventAllocChecked(sizeof (tomp_Task), 
                                              __FILE__, __LINE__);
    tomp_initialTaskForMaster = (tomp_Task *)tomp_event_pointer(event);
    tomp_initialTaskForMaster->event = event;
    tomp_initialTaskForMaster->kind = tomp_TaskKind_IMPLICIT;

    // Set current_task pointer for master thread to this initial task
    tomp_thread.current_task = tomp_initialTaskForMaster;

    // Create an implicit task for master. This task is not used to spawn
    // execution. It represents the root of the generated task "tree"
    event = tomp_eventAllocChecked (sizeof (tomp_Task), __FILE__, __LINE__);
    tomp_implicitTaskForMaster = (tomp_Task *)tomp_event_pointer(event);
    tomp_implicitTaskForMaster->event = event;
    tomp_implicitTaskForMaster->kind = tomp_TaskKind_IMPLICIT;


    // Allocate and Initialize the master core's TLS block
    // Can be set directly to __TI_tls_currentTP - will not change for master
    __TI_tls_currentTP = tomp_allocInitTLSBlock();
    tomp_implicitTaskForMaster->tls_block = __TI_tls_currentTP;
    tomp_initialTaskForMaster->tls_block = __TI_tls_currentTP;

    return 0;
}




/**
 * Terminate program across cores by sending events to the exit queue
 */
void tomp_sendExitEvents(void)
{
    int i;

#if TOMP_DEVICE_HAS_HW_QUEUES
    // Queues have not been initialized! Cannot send exit events
    if (tomp_queues.exitQ           == QMSS_PARAM_NOT_SPECIFIED ||
        tomp_queues.freeDescriptorQ == QMSS_PARAM_NOT_SPECIFIED)
        return;
#endif // TOMP_DEVICE_HAS_HW_QUEUES

    // Send exit events to all cores except the one that invoked this function
    for (i=0; i< TOMP_NUM_CORES - 1; i++)
    {
        tomp_event_t event;

        do {
            event = tomp_eventAlloc();
        } while (event == NULL);

        tomp_eventPush (tomp_queues.exitQ, event);
    }
}

/**
 * Terminate the OpenMP runtime
 *
 * Executed only be the master core. Pushes exit events to the worker exit 
 * queues to terminate execution on workers. Also does cleanup on the master
 */
void __TI_omp_terminate(void)
{
    // Only the master core should execute this function. 
    if (DNUM != TOMP_MASTER_CORE_IDX) return;

    // Only need to terminate the workers, not the master
    tomp_sendExitEvents();

    tomp_exitProcessing();

    int i;
    for (i = 0; i < TOMP_NUM_CORES - 1; i++)
    {
        if (tomp_eventHdlTbl[i])
            tomp_eventFree(tomp_eventHdlTbl[i]);
    }

    // Free the initial and implicit tasks allocated for the master core
    tomp_eventFree (tomp_initialTaskForMaster->event);
    tomp_initialTaskForMaster = NULL;
    tomp_eventFree (tomp_implicitTaskForMaster->event);
    tomp_implicitTaskForMaster = NULL;
    tomp_exitGlobalNRT();
}
