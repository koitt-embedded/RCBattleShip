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
 * \file tomp_parallel.c
 * 
 * \brief Implements GOMP_parallel_[start|end]
 *      
 */

#include <string.h>
#include <stdlib.h>
#include <inttypes.h>

#include "omp.h"
#include "tomp_parallel.h"
#include "tomp_log.h"


/* Variables used by multiple cores have to be in shared memory 
 * There are non-cacheable for performance reason like Event Machine variables:
 * Cost of write back/invalidate superior than cost of reading a few times */


// Local thread structure
#pragma DATA_SECTION (tomp_thread, ".tomp_gvMem");
tomp_Thread tomp_thread;

//! Local TLS pointer (one per core)
//! @see ___c6xabi_get_tp in tomp_tls_get_tp.asm
#pragma DATA_SECTION (__TI_tls_currentTP, ".tomp_gvMem");
void *__TI_tls_currentTP;


// EM events sent to all threads excepting the master for non nested parallelism
#pragma DATA_SECTION (tomp_eventHdlTbl, ".tomp_gvMem");
tomp_event_t tomp_eventHdlTbl[TOMP_DEVICE_NUM_CORES - 1];

// OMP events associated to data_event for non nested parallelism
#pragma DATA_SECTION (tomp_taskPtrTbl, ".tomp_gvMem");
tomp_Task *tomp_taskPtrTbl[TOMP_DEVICE_NUM_CORES - 1];

/** Initial Task for master. This task is the initial implicit task associated
 *  with the initial thread. OpenMP Spec 3.0, p12, lines 1-4. There is a 
 *  distinction between the initial implicit task and the implicit tasks
 *  created for a parallel region and this distinction is important for
 *  ownership of locks.
 */
#pragma DATA_SECTION (tomp_initialTaskForMaster, ".tomp_gvMem");
tomp_Task *tomp_initialTaskForMaster;

/** Implicit Task for master. The current_task field in tomp_Thread for the 
 *  master points to this task when the thread is in a parallel region.
 */
#pragma DATA_SECTION (tomp_implicitTaskForMaster, ".tomp_gvMem");
tomp_Task *tomp_implicitTaskForMaster;

/** Id to annotate parallel region events. Incremented in GOMP_parallel_end */
#pragma DATA_SECTION (parallel_region_id, ".tomp_svNcMem")
static uint32_t parallel_region_id = 0;



/**
 * Function executed by the worker cores when they pull an event from the 
 * workshare queue.
 */
void tomp_eoStartLoopX (tomp_event_t eventHdl)
{
    tomp_TeamState *ts          = tomp_thread.ts;
    tomp_Task      *eventOpenMP = (tomp_Task *) tomp_event_pointer (eventHdl);
    tomp_Team      *team        = NULL;
    unsigned int    oldDP;

    if (eventOpenMP == NULL)
        tomp_logError(tomp_ErrorKind_NULL_PTR, __FILE__, __LINE__);

#pragma diag_suppress 238
    ulm_put_statemsg(ULM_OMP_EVENT_IMPLICIT_TASK_START, 
                     eventOpenMP->id, (uint32_t)eventOpenMP->entry_func);
#pragma diag_default 238

    tomp_clear_TeamState(ts);

    // Set current task to implicit task
    tomp_thread.current_task = eventOpenMP;

    // Enable task stealing for worker core
    tomp_thread.task_stealing = tomp_TaskSteaking_ENABLED;

    // Initialize thread-specific workshare pointer to workshare in team
    ts->work_share      = &eventOpenMP->team->dummy_ws;

    // Only implicit tasks at the first level of nesting are pushed to
    // the workshare queue
    ts->level = 1;
    ts->team_id = eventOpenMP->teamMember;
    team = ts->team = eventOpenMP->team;

    //Set ICV for task using gomp_global_icv
    eventOpenMP->icv.nthreads_var  = gomp_global_icv.nthreads_var;
    eventOpenMP->icv.run_sched_var  = gomp_global_icv.run_sched_var;
    eventOpenMP->icv.run_sched_modifier  = gomp_global_icv.run_sched_modifier;

    __TI_tls_currentTP = eventOpenMP->tls_block;

    if (team == NULL)
        tomp_logError(tomp_ErrorKind_NULL_PTR, __FILE__, __LINE__);
    
    tomp_logDebug2 ("TRACE: [%d] StartLoop executing (0x%08x)\n",
                    DNUM, (int) eventOpenMP->entry_func);

    // Perform a flush to ensure that any updates to shared variables by the 
    // master thread prior to this parallel region are visible to the worker 
    // threads. Perform the flush right before invoking the outlined function
    // to prevent inadvertent "early" loads of shared variables into the cache
    // during execution of OpenMP runtime code.
    tomp_cacheWbInvAll();

    // In OpenCL mode, we need to switch DP before calling application code
    if (TOMP_MUST_UPDATE_DP)
    {
        // Save the current value of DP
        oldDP = __TI_get_DP();

        // Update DP to correspond to static base in application code
        __TI_set_DP(team->DP);
    }

    // Execute the corresponding OpenMP funtion
    eventOpenMP->entry_func (eventOpenMP->arg_buffer);

    // Ensure all writes to shared variables land before exiting the barrier
    // See GOMP_parallel_end(). 
    tomp_mfence();

    // Wait for other threads on the team to reach the barrier. Will also
    // execute any pending tasks
    tomp_waitAtBarrier(&team->barrier);

    // In OpenCL mode, restore DP after return from application code
    if (TOMP_MUST_UPDATE_DP)
        __TI_set_DP(oldDP);

    // Reset the team pointer. team determines if the thread is participating
    // in the team and is initialized during each parallel region startup
    ts->team = NULL;

    // The worker core is done with the implicit task associated with the 
    // parallel region. It must not steal any tasks until it starts executing
    // the implicit task associated with a subsequent parallel region.
    tomp_thread.task_stealing = tomp_TaskStealing_DISABLED;

#if 0 // Not required because we flush before calling the outlined function
    // OMP v3.0, 2.8.6. Implied flush at exit from parallel region
    tomp_cacheWbInvAll();
#endif

#pragma diag_suppress 238
    ulm_put_statemsg(ULM_OMP_EVENT_IMPLICIT_TASK_END, 
                     eventOpenMP->id, (uint32_t)eventOpenMP->entry_func);
#pragma diag_default 238
}


/**
 * Create and initialize a team
 *
 * @param threadNum number of threads in the team
 * @return a pointer to the initialized team
 * @see GOMP_parallel_start
 */
tomp_Team *tomp_initialize_team(unsigned int threadNum)
{
    /* Configuration of tomp_ThreadDsc structure 
     * Initialisation of the team */
    int lvThreadNum;
    struct gomp_task_icv *icv = gomp_icv();
    tomp_TeamState *ts = tomp_thread.ts;
    tomp_Team *team;
    int nested = (ts->level > 0);

    // Determine the number of threads that form the team.
    if (nested)
       lvThreadNum = 1;
    else if (ts->level == gomp_max_active_levels_var)
       lvThreadNum = 1;
    else if (threadNum > TOMP_NUM_CORES)
       lvThreadNum = TOMP_NUM_CORES;
    else if (threadNum > 0)
        lvThreadNum = threadNum;
    else if (icv->nthreads_var > TOMP_NUM_CORES)
        lvThreadNum = TOMP_NUM_CORES;
    else
        lvThreadNum = icv->nthreads_var;


    // Allocate a team
    tomp_event_t event = tomp_eventAllocChecked(sizeof(tomp_Team),
                                                __FILE__, __LINE__);
    team        = (tomp_Team *) tomp_event_pointer(event);
    team->event = event;
    if (nested)
    {
       // Capture the current team state
       team->prev_ts = ts;
       // Create a new team state for the nested team
       ts = tomp_alloc_TeamState();
       tomp_clear_TeamState (ts);
       // Increment level to reflect the current nesting level
       ts->level = team->prev_ts->level + 1;
       tomp_thread.ts = ts;
    }
    else
    {
       tomp_clear_TeamState(ts);
       // This is the outermost parallel region
       ts->level = 1;
    }
    
    ts->team    = team;
    
    // Initialize the workshare pointer
    team->dummy_ws.event = NULL;
    ts->work_share      = &team->dummy_ws;
    
    // Get the team Id from the event msg
    // Default: master thread team id = 0
    ts->team_id = 0;

    team->nthreads         = lvThreadNum;
    team->task_count       = 0;
    team->curr_task_id     = 0;

    // In OpenCL mode, master core DP must be propagated to worker cores.
    team->DP               = __TI_get_DP();

    // Initialize the dummy workshare structure
    gomp_init_work_share(&team->dummy_ws, false/*ordered*/, team->nthreads);

    //Initialisation for GOMP_BARRIER with the correct number of threads
    tomp_initBarrier (&team->barrier, lvThreadNum);

    // Initialize the array used to gate entrance into an ordered region
    memset((void *)team->ordered_release, 0, 
            TOMP_DEVICE_NUM_CORES * sizeof(team->ordered_release[0]));

    return team;
}


/**
 * Start the team by pushing events to the StartLoop queue
 *
 * @param team pointer to a team
 * @param fn   function corresponding to the implicit task (outlined fn)
 * @param data data associated with the function
 * @see GOMP_parallel_start, tomp_eoStartLoop
 */
void tomp_start_team(tomp_Team *team,
                     void (*fn) (void *),
                     unsigned char *data)
{
    int lvThreadNum = team->nthreads;
    int i;
    int nested = (tomp_thread.ts->level > 1);

    // At the first level of nesting, the master threads's task is 
    // tomp_implicitTaskForMaster.  Otherwise, a new implicit task object 
    // is created for the master thread.
    tomp_Task *prev_task = tomp_thread.current_task;
    if (!nested)
    {
       tomp_thread.current_task = tomp_implicitTaskForMaster;
    }
    else
    {
       tomp_Task *task;
       // Allocate a task
       tomp_event_t event = tomp_eventAllocChecked(sizeof(tomp_Task),
                                                __FILE__, __LINE__);
       task = (tomp_Task *) tomp_event_pointer(event);
       task->event = event;
       tomp_thread.current_task = task;
    }

    tomp_taskInit(tomp_thread.current_task, tomp_TaskKind_IMPLICIT, 
                  prev_task, team);

    // If there is only one thread, there is no need to create events
    if (lvThreadNum == 1)
        return;

    // Implicit tasks need to get their ICVs from tomp_initialTaskForMaster.
    // We achieve this by capturing tomp_initialTaskForMaster's ICV into the
    // shared gomp_global_icv that is accessible from all cores.
    gomp_global_icv = tomp_initialTaskForMaster->icv;

    // Enable for master
    tomp_thread.task_stealing = tomp_TaskSteaking_ENABLED;

    // OMP v3.0, 2.8.6. Implied flush: 
    // "At entry to parallel region" 
    // "At entry to combined parallel worksharing regions (loop)"
    tomp_cacheWbInvAll();
    
    // To avoid having to lock team->curr_task_id, set all the id's before
    // sending events into the queue!
    for (i = 0; i < lvThreadNum - 1; i++)
        tomp_taskPtrTbl[i]->id = team->curr_task_id++;

    // Create a set of events for implicit tasks on worker cores
    for (i = 0; i < lvThreadNum - 1; i++)
    {
        // Linking the function to execute and the data with the msg
        tomp_taskPtrTbl[i]->entry_func = fn;
        tomp_taskPtrTbl[i]->arg_buffer = data;

        // teamMember = team_id sent to the core that execute the function
        tomp_taskPtrTbl[i]->teamMember = i + 1;

        // team pointer
        tomp_taskPtrTbl[i]->team = team;

        // Initialize implicit task related variables
        tomp_taskPtrTbl[i]->children_count = 0;
        tomp_taskPtrTbl[i]->parent         = NULL;

        tomp_eventPush (tomp_queues.implicitTaskQ, tomp_eventHdlTbl[i]);

        tomp_logDebug2 ("TRACE: StartTeam event 0x%08x -> queue 0x%08x\n", 
                        (int)tomp_eventHdlTbl[i], 
                        (unsigned int)tomp_queues.implicitTaskQ);
    }

    return;
}


/**
 * GOMP_parallel_start is used for the for loop parallelism.
 * The same function is executed on various chunks of data (SPMD)
 * Therefore, we are creating a single EO, a single PARALLEL queue,
 * and an event group. For each thread in the team, we are sending an
 * event that belongs to the event group.
 *
 * @param fn                     pointer to the function to execute
 * @param data                      pointer to the data to process
 * @param num_threads     (number of threads in the OpenMP team)
 *
 * @see GOMP_parallel_end()
 */
void GOMP_parallel_start (
    void (*fn) (void *),
    unsigned char *data,
    unsigned int num_threads
)
{
    /* TODO: Must use algorithm in OMP Spec v3.0, 2.4.1 to resolve number of 
     * threads in a parallel region
     */

#pragma diag_suppress 238
    ulm_put_statemsg(ULM_OMP_EVENT_PARALLEL_START_ENTER,
                     parallel_region_id, (uint32_t)fn);
#pragma diag_default 238

    tomp_Team *team = tomp_initialize_team(num_threads);
    tomp_start_team(team, fn, data);

#pragma diag_suppress 238
    ulm_put_statemsg(ULM_OMP_EVENT_PARALLEL_START_EXIT, parallel_region_id,
                     (uint32_t)fn);
#pragma diag_default 238
}

/**
 * Wait for implicit/explicit tasks to complete and terminate the team
 */
void GOMP_parallel_end (void)
{
#pragma diag_suppress 238
    ulm_put_statemsg(ULM_OMP_EVENT_PARALLEL_END_ENTER,parallel_region_id,0);
#pragma diag_default 238

    // Wait for all threads in the team to reach this implicit synchronization 
    // point.
    tomp_TeamState *ts   = tomp_thread.ts;
    tomp_Team      *team = ts->team;
    tomp_Task      *prev_task = NULL;

    tomp_waitAtBarrierWithFlush(&team->barrier);
    
    // gomp_work_share_end[_nowait] frees the previous workshare. At the end 
    // of a parallel region, the last remaining workshare must be freed. 
    // Since this is the last work share in the region, all threadstates 
    // will point to the same work share. 
    if (ts->work_share->event) 
        tomp_eventFree(ts->work_share->event);

    // Free team
    tomp_eventFree(team->event);
    ts->team = NULL;

    // Set the current task to point to its parent task
    // Note that parent task for the master at the outermost/first parallel 
    // region is tomp_initialTaskForMaster
    prev_task = tomp_thread.current_task;
    tomp_thread.current_task = tomp_thread.current_task->parent;

    if (ts->level == 1)
    {
       //Reset level
       ts->level = 0;

       // Reset the master's TP. There is a corner case where the core executing
       // the master thread can pick up an implicit task and have it's TP
       // changed in tomp_eoStartLoop
       __TI_tls_currentTP = tomp_initialTaskForMaster->tls_block;
    }
    else
    {
       //Free the nested team state
       tomp_eventFree(tomp_thread.ts->event);

       //Restore the previous team state 
       tomp_thread.ts = team->prev_ts;

       //Free the nested implicit task
       tomp_eventFree (prev_task->event);
    }

#pragma diag_suppress 238
    ulm_put_statemsg(ULM_OMP_EVENT_PARALLEL_END_EXIT,parallel_region_id,0);
#pragma diag_default 238
    tomp_incrementAtomic(&parallel_region_id);
}


// Return the number of threads set
int omp_get_num_threads (void)
{
    if (tomp_thread.ts->team != NULL)
	return (int)(tomp_thread.ts->team->nthreads);
    return 1;
}


/* Return the ID of the running thread in the team */
int omp_get_thread_num (void)
{
    if (tomp_thread.ts->team != NULL)
        return tomp_thread.ts->team_id;
    return 0;
}

int omp_get_num_procs(void)
{
    return TOMP_NUM_CORES;
}

/* Return true if within an active parallel region */
int omp_in_parallel(void)
{
    tomp_TeamState *ts   = tomp_thread.ts;
    int level = ts->level;
    
    if (level == 0)
       return 0;
    for (level = ts->level; level > 0; --level)
    {
       if (ts->team->nthreads > 1)
          return 1;
       ts = ts->team->prev_ts;
    }
    return 0;
}

/* Return the number of enclosing nested parallel regions */
int omp_get_level(void)
{
    return tomp_thread.ts->level;
}

/* Return the ID of an ancestor or current thread at a given nested level */
int omp_get_ancestor_thread_num(int level)
{
    tomp_TeamState *ts   = tomp_thread.ts;

    if (level < 0 || level > ts->level)
       return -1;
    if (level == 0)
       return 0;
    for (level = ts->level - level; level > 0; --level)
       ts = ts->team->prev_ts;
    return ts->team_id;
}

/* Return the team size of an ancestor or current thread at a given nested 
 * level */
int omp_get_team_size(int level)
{
    tomp_TeamState *ts   = tomp_thread.ts;

    if (level < 0 || level > ts->level)
       return -1;
    if (level == 0)
       return 1;
    for (level = ts->level - level; level > 0; --level)
       ts = ts->team->prev_ts;
    if (ts->team == NULL)
       return 1;
    else
       return ts->team->nthreads;
}

/* Return the number of enclosing nested, active parallel regions */
int omp_get_active_level(void)
{
    tomp_TeamState *ts   = tomp_thread.ts;
    int level = ts->level;
    int active_level = 0;
    
    if (level == 0) 
       return 0;
    for (level = ts->level; level > 0; --level)
    {
       if (ts->team->nthreads > 1)
          ++active_level;
       ts = ts->team->prev_ts;
    }
    return active_level;
}
/**
 * Complete all explicit tasks generated upto the implicit/explicit barrier
 *
 * From OMP Spec 3.0, p67, line 23
 * All threads of the team executing the binding parallel region must execute 
 * the barrier region and complete execution of all explicit tasks generated in
 * the binding parallel region up to this point before any are allowed to 
 * continue execution beyond the barrier.
 */
void tomp_completePendingTasks()
{
    tomp_TeamState *ts   = tomp_thread.ts;
    tomp_Team      *team = ts->team;

    // Without a team, there are no pending tasks - they are all "included"
    // Also, when level != 1, the team will comprise no more than one thread 
    // and all tasks are "included"
    if (tomp_thread.ts->team == NULL || ts->level != 1) return;
    //if (tomp_thread.ts->team == NULL) return;

    // Check for pending explicit tasks. No need to lock task_count - even if 
    // there is a race on task_count and thread reads a non-zero value when it
    // should be zero, the task queue will be empty and tomp_dispatch_once
    // will just return
    while (team->task_count != 0)
    {
        tomp_dispatch_once();
    }

    return;
} 

tomp_TeamState *tomp_alloc_TeamState()
{
    tomp_event_t event = tomp_eventAllocChecked(sizeof(tomp_TeamState), 
                                                __FILE__, __LINE__);
    tomp_TeamState *ts    = (tomp_TeamState *) tomp_event_pointer(event);
    ts->event = event;

    return ts;
}

/** \mainpage
 *
 *  
 *  The OpenMP runtime requires certain parameters to be initialized before
 *  the program starts (i.e. reaches main). It provides callback functions
 *  and default implementations for these functions in tomp_config.c
 *  - __TI_omp_reset
 *  - __TI_omp_configure
 *
 *  The body of the callback functions consist of calls to a predefined
 *  set of helper functions.
 *  Refer the User Guide for details on configuring the OpenMP runtime.
 *
 *  \subsection reset __TI_omp_reset
 *  @see __TI_omp_reset
 *  
 *  \subsection config __TI_omp_configure
 *  @see __TI_omp_configure
 *  
 *  __TI_omp_configure consists of calls to the following functions:
 *  @see __TI_omp_config_cores
 *  @see __TI_omp_config_hw_semaphores
 *  @see __TI_omp_config_hw_queues
 *  @see __TI_omp_config_thread_stack
 *
 */
