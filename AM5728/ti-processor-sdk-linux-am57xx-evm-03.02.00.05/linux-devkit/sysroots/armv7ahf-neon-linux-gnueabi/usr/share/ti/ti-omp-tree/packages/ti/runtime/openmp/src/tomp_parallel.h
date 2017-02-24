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
 * \file tomp_parallel.h
 * 
 * \brief Declares various OMP data structures such as thread, teamstate
 *        team etc.
 */

#ifndef TOMP_PARALLEL_H_
#define TOMP_PARALLEL_H_

#include "tomp_defs.h"
#include "tomp_init.h"
#include "tomp_util.h"
#include "tomp_queues.h"
#include "gomp_libgomp.h"
#include "ulm_wrapper.h"

//! Function type executed in the receive function
typedef void (*tomp_OutlinedFunc) (void*);

/**
 * Describes a team of "threads"
 *
 * Allocated and initialized at the start of a parallel region
 * Free'd at the end of a parallel region
 */
typedef struct _tomp_Team
{
    //! Number of threads in the current team.
    unsigned int nthreads;

    //! This barrier is used for most synchronization of the team
    tomp_Barrier barrier;

    //! Counter of task that have not completed execution
    volatile unsigned int task_count;

    //! Count of the number of tasks in the current parallel region
    volatile unsigned int curr_task_id;

    //! - "Dummy" work share, used for it's next_ws pointer for worksharing
    //! - Used by combined worksharing constructs with schedule clause - these
    //!   only require a single workshare construct
    struct gomp_work_share dummy_ws;

    //! Array used to gate entry of a thread into an ordered region. 
    volatile unsigned char ordered_release[TOMP_DEVICE_NUM_CORES];

    unsigned int DP;

    //! Event pointer to free the team
    tomp_event_t event;

    //! Previous team state that applied to a master thread in its 
    //  parent team.
    struct _tomp_TeamState *prev_ts;

} tomp_Team;

/** 
 *  Describes current state of the thread
 */
typedef struct _tomp_TeamState
{
    //! Pointer to the team
    tomp_Team *team;

    //! Number of the thread in the team
    //! Important to know what part of the work you have to do
    int team_id;

    //! Current workshare being processed by thread
    struct gomp_work_share *work_share;

    //! Previous workshare that was processed by thread
    struct gomp_work_share *last_work_share;

    //! Count of iteration chunk processed by a thread
    unsigned long static_trip;
    
    //! Event pointer to free the team state
    tomp_event_t event;

    //! Nesting level
    int level;

} tomp_TeamState;


/** Task Stealing */
typedef enum { tomp_TaskStealing_DISABLED = 0, 
               tomp_TaskSteaking_ENABLED
} tomp_TaskStealing_e;


/**
 * Thread structure
 *
 * There is a tomp_Thread per core participating in the OMP runtime. 
 * tomp_Thread is stored in core local memory
 */
typedef struct _tomp_Thread
{
    //! Current state of the thread
    tomp_TeamState *ts;

    //! Pointer to task being executed by thread. Initialized to implicit task
    struct _tomp_Task *current_task;

    //! Keeps track of whether task stealing is enabled or disabled
    tomp_TaskStealing_e task_stealing;
} tomp_Thread;


/** Task kinds */
typedef enum { tomp_TaskKind_IMPLICIT = 0, 
               tomp_TaskKind_DEFERRED,
               tomp_TaskKind_INCLUDED
} tomp_TaskKind_e;


/**
 * Task structure
 *
 * Represents implicit and explicit OpenMP tasks                      
 */
typedef struct _tomp_Task
{                    
    //! Pointer to the outlined OpenMP function to be executed
    tomp_OutlinedFunc entry_func;

    //! Pointer to arguments for the outlined function
    void*      arg_buffer;

    //! Pointer to the team
    tomp_Team *team;

    //! Team (or) thread ID
    int teamMember;

    //! Pointer to the task that generated this task, can be implicit task
    struct _tomp_Task *parent;

    //! Number of children generated by this task
    volatile int children_count;

    //! Unique id to identify the task in a parallel region
    unsigned short id;

    //! Has the task completed execution?
    volatile unsigned char completed_execution;
    
    //! Is the argument buffer embedded in the task object?
    unsigned char arg_buffer_in_task;

    //! Indicates if the task is explicit or implicit
    unsigned char kind;

    //! Pointer to thread local storage - only used by implicit tasks
    void *tls_block;

    //! Event pointer to free the task
    tomp_event_t event;

    //! Per-task ICV
    struct gomp_task_icv icv;
} tomp_Task;


extern tomp_Thread tomp_thread;
extern void*       __TI_tls_currentTP;
extern uint32_t    tomp_threadNum;

extern tomp_event_t tomp_eventHdlTbl[TOMP_DEVICE_NUM_CORES - 1];
extern tomp_Task*   tomp_taskPtrTbl[TOMP_DEVICE_NUM_CORES - 1];

extern tomp_Task* tomp_initialTaskForMaster;
extern tomp_Task* tomp_implicitTaskForMaster;

extern void tomp_eoStartLoopX(tomp_event_t event);
extern void tomp_eoStartTaskX(tomp_event_t event);

tomp_Team* tomp_initialize_team(unsigned int num_threads);
void tomp_start_team(tomp_Team *ts, void (*fn) (void *), unsigned char *data);

tomp_TeamState* tomp_alloc_TeamState();

/** 
 *  Reset a tomp_teamState variable
 *
 * Ensure that tomp_TeamState is properly initialized at: 
 * 1. startup - to deal with orphaned constucts
 * 2. start of each parallel region - to remove state from a previous region
 */
static inline void tomp_clear_TeamState(tomp_TeamState *ts)
{
    ts->team            = NULL;
    ts->work_share      = NULL;
    ts->last_work_share = NULL;
    ts->static_trip     = 0;
}


/**
 * Initialize a task object
 */
static inline void tomp_taskInit(tomp_Task *task, tomp_TaskKind_e kind, 
                                 tomp_Task *parent, tomp_Team *team)
{
    task->id                  = 0;
    task->kind                = kind;
    task->entry_func          = NULL;
    task->arg_buffer          = NULL;
    task->arg_buffer_in_task  = false;
    task->team                = team;
    task->teamMember          = (kind == tomp_TaskKind_IMPLICIT) ? 0 : -1;
    task->parent              = parent;
    task->children_count      = 0;
    task->completed_execution = false;
    task->icv                 = parent->icv;
}

extern void tomp_completePendingTasks();

/* Here's how to access the current copy of the ICVs.  */

static inline struct gomp_task_icv *gomp_icv (void)
{
  return &tomp_thread.current_task->icv;
}
#endif /* TOMP_PARALLEL_H_ */
