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
 *   \file  tomp_dispatch.c
 *
 *   Dispatcher Implementation for OpenMP.
 */

#include "tomp_parallel.h"


extern void tomp_exitLocalX   (tomp_event_t event);

typedef void (*tomp_dispatchFn) (tomp_event_t eventHdl);

static inline bool tomp_dispatchEvent(tomp_dispatchFn fn, tomp_queue_t qid)
{
    tomp_event_t event = tomp_eventPop(qid);
    if (event != NULL)
        (*fn)(event);

    return (event != NULL);
}

#if !TOMP_DEVICE_HAS_HW_QUEUES
void tomp_dispatch_finish (void)
{
    int i;

    // Send exit events to all cores except the one that invoked this function
    for (i=0; i< TOMP_NUM_CORES - 1; i++)
    {
        tomp_event_t event;

        do {
            event = tomp_eventAlloc();
        } while (event == NULL);

        tomp_eventPush (tomp_queues.finishQ, event);
    }
}

bool tomp_dispatch_is_finished(void)
{
    tomp_event_t event = tomp_eventPop(tomp_queues.finishQ);
    bool is_finished = (event != NULL);
    if (is_finished)
       tomp_eventFree(event);

    return is_finished;
}
#endif

/**
 *  OpenMP dispatch function
 */
void tomp_dispatch_once (void)
{
    // If there is an event in the exit Q, exit() is called and we will not
    // return
    tomp_dispatchEvent(&tomp_exitLocalX, tomp_queues.exitQ);

    // If core is not part of a team, check to see if there are any
    // implicit tasks in the queue. A core cannot execute any explicit
    // tasks until it joins the OpenMP team by dispatching an implicit task
    if (tomp_thread.ts->team == NULL)
        tomp_dispatchEvent(&tomp_eoStartLoopX, tomp_queues.implicitTaskQ);
    else
    {
        // Task stealing disabled, only check the explicit task
        // queue corresponding to the core.
        if (tomp_thread.task_stealing == tomp_TaskStealing_DISABLED)
            tomp_dispatchEvent(&tomp_eoStartTaskX,
                               tomp_queues.explicitTaskQ[DNUM]);

        // Task stealing disabled, check all the explicit task queues for 
        // any tasks to dispatch.
        // NOTE: For now, we just cycle through queues for cores in order
        // looking for tasks. Try other approaches such as round robin,
        // starting with the core executing the dispatch function.
        else
        {
            int i;
            for (i = 0; i < TOMP_NUM_CORES; i++)
            {
                if (tomp_dispatchEvent(&tomp_eoStartTaskX, 
                                       tomp_queues.explicitTaskQ[i]))
                    return;
            }
        }
    }
}

