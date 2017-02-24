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
 * \file tomp_task.c
 * 
 * \brief Implements (1) tasking APIs: GOMP_task, GOMP_taskwait
 *        (2) tomp_eoStartTask - the execution object for tasks 
 *      
 */

#include <string.h>
#include <stdlib.h>

#include "tomp_parallel.h"
#include "tomp_log.h"

#include <c6x.h>

void GOMP_taskwait(void);

static void tomp_taskInitArgBuffer (tomp_Task *task, void *arg, int arg_size);
static void tomp_taskCleanup(tomp_Task *task);
static void tomp_taskFreeArgBuffer (tomp_Task *task);
static void tomp_taskFree(tomp_Task *task);


/** 
 * Called when encountering an explicit task directive.  If IF_CLAUSE is
 * false, then we must not delay in executing the task.  If UNTIED is true,
 * then the task may be executed by any member of the team.  
 */
void GOMP_task (void (*fn) (void *),
                void *data,
                void (*cpyfn) (unsigned char *, unsigned char *),
                int arg_size,
                int arg_align,
                int if_clause,
                int flags /*__attribute__((unused))*/)
{
    tomp_TeamState *ts            = tomp_thread.ts;
    tomp_Team      *team          = ts->team;
    tomp_event_t    task_event    = NULL;

    int task_id = 0;

    // Attempt to allocate a buffer. If allocation fails because there are
    // insufficient buffers, the task becomes an included task
    if (team && if_clause)
        task_event = tomp_eventAlloc();

    // Lock accesses to curr_task_id, children and task count.
    // 1. Multiple threads could generate tasks & update task_count
    // 2. A task could be decrementing it's parent's child count at the same
    //    time that the parent is generating new tasks and incrementing it
    tomp_mutex_lock (TOMP_TASK_HW_SEM_IDX);
    {
        if (team)
        {
            task_id = team->curr_task_id++;
            team->task_count++;
            tomp_thread.current_task->children_count++;
        }

    }
    tomp_mutex_unlock (TOMP_TASK_HW_SEM_IDX);

    // Task "included" if (1) orphaned task construct (2) if_clause is false
    // or (3) EM buffers are exhausted (4) in a nested parallel region
    if (team == NULL || !if_clause || task_event == NULL || ts->level != 1)
    {
        tomp_Task *prev_task = tomp_thread.current_task;

        // No need to call em_alloc because the task is included. However,
        // we need a task object because:
        // 1. Address of task objects is used to ensure that lock ownership 
        //    works correctly
        // 2. Children tasks decrement the children_count of parent tasks when
        //    they complete execution   
        tomp_Task tmp;
        tomp_taskInit(&tmp, tomp_TaskKind_INCLUDED, prev_task, team);
        tmp.id = task_id;
        tmp.tls_block = NULL;
        tmp.event = NULL;

        tomp_thread.current_task = &tmp;

        // Directly call the function. cpyfn is always NULL in TI lowering
        fn(data);

        if (team != NULL)
        {
            // Wait for children to finish before parent tomp_Task (tmp) goes
            // out of scope.
            GOMP_taskwait();
            tomp_taskCleanup(&tmp);
        }

        tomp_thread.current_task = prev_task;

        return;
    }

    tomp_Task *task  = (tomp_Task *) tomp_event_pointer (task_event);
    tomp_taskInit(task, tomp_TaskKind_DEFERRED, tomp_thread.current_task, team);

    task->event            = task_event;
    task->entry_func       = fn;
    task->id               = task_id;
    task->tls_block        = NULL;

    // Create a snapshot of the argument structure to capture state when the
    // task was generated
    tomp_taskInitArgBuffer(task, data, arg_size);
    
    // Ensure all writes have landed in memory before posting an event
    tomp_mfence();

    tomp_eventPushToHead (tomp_queues.explicitTaskQ[DNUM], task_event);

#pragma diag_suppress 238
    ulm_put_statemsg(ULM_OMP_EVENT_TASK_GEN, task->id, 
                     (uint32_t)task->entry_func);
#pragma diag_default 238

    // OpenMP v3.0, 2.8.6 Implied flush at task scheduling point (TSP).
    // The point immediately following the generation of an explicit task is 
    // a TSP
    tomp_cacheWbInvAll();

    tomp_logDebug3 ("TRACE: [%d] GOMP_task event 0x%08x -> queue 0x%08x \n", 
                    DNUM, (int)task_event, 
                    (unsigned int)tomp_queues.explicitTaskQ[DNUM]);
}


/**
 * Called when encountering a taskwait directive.  
 */
void GOMP_taskwait (void)
{
    tomp_Team *team = tomp_thread.ts->team;
    tomp_TaskStealing_e prev_task_stealing;

    // Orphaned construct. No pending tasks as they are immediately executed
    if (!team)
        return;
    
    // When in taskwait, a new task can be executed only if it is a 
    // descendant of every suspended tied task on this core. Disable
    // task stealing to enforce this constraint
    // Save the previous task stealing state. A taskwait can be nested
    // in another taskwait via a child task waiting on its children.
    prev_task_stealing = tomp_thread.task_stealing;
    tomp_thread.task_stealing = tomp_TaskStealing_DISABLED;

    bool taskptr_cached = tomp_isPtrCached((void *)tomp_thread.current_task);

    if (taskptr_cached)
        tomp_cacheWbInv(tomp_thread.current_task, sizeof(tomp_Task));

    // Wait for any children to finish execution                             
    while (tomp_thread.current_task->children_count != 0)
    {
    	tomp_dispatch_once();

        // Some other core can potentially update children_count
        if (taskptr_cached)
            tomp_cacheWbInv(tomp_thread.current_task, sizeof(tomp_Task));
    }

    // Since we are done with this taskwait, restore the previous 
    // task stealing state.
    tomp_thread.task_stealing = prev_task_stealing;

    // A taskwait is a task scheduling point. OpenMP v3.0, Section 2.8.6
    // requires a flush without a list at task scheduling points.
    tomp_cacheWbInvAll();
}


/**
 * Function executed by the worker cores when they pull an event from the 
 * task queue.
 */
void tomp_eoStartTaskX (tomp_event_t  eventHdl)
{
    tomp_TeamState *ts   = tomp_thread.ts;
    tomp_Task      *task = (tomp_Task *) tomp_event_pointer (eventHdl);
    tomp_Team      *team = ts->team;

    if (task == NULL || team == NULL)
        tomp_logError(tomp_ErrorKind_NULL_PTR, __FILE__, __LINE__);
                         
#pragma diag_suppress 238
    ulm_put_statemsg(ULM_OMP_EVENT_TASK_START, task->id, 
                     (uint32_t)task->entry_func);
#pragma diag_default 238

    tomp_logDebug2("TRACE: [%d] Executing task (0x%08x)\n", 
                   DNUM, (int) task);

    // Save off the current task associated with the thread
    tomp_Task *old_task = tomp_thread.current_task;
    tomp_thread.current_task = task;

    // Flush before calling a child task
    tomp_cacheWbInvAll();

    // Execute the corresponding outlined OpenMP function
    task->entry_func(task->arg_buffer);

    // Ensure we have a valid parent pointer before calling cleanup
    if (task->parent == NULL)
        tomp_logError(tomp_ErrorKind_NULL_PTR, __FILE__, __LINE__);

    tomp_taskCleanup(task);

    tomp_thread.current_task = old_task;

    // OpenMP Spec 3.0, Section 2.8.6
    // A flush without a list is implied after the last instruction of a task
    // region
    tomp_cacheWbInvAll();

#pragma diag_suppress 238
    ulm_put_statemsg(ULM_OMP_EVENT_TASK_END, task->id, 
                     (uint32_t)task->entry_func);
#pragma diag_default 238
}


/**
 * Performs book-keeping activities on completion of task execution
 *
 * This function modifies shared variables - task_count and children_count.
 * Therefore, task lock must be acquired on entry to & released on exit.
 * @param task Pointer to a task that has completed execution.
 *
 * @see tomp_eoStartTask
 */
static void tomp_taskCleanup(tomp_Task *task)
{
    tomp_mutex_lock(TOMP_TASK_HW_SEM_IDX);

    // Decrement the team's task count
    task->team->task_count--;

    tomp_Task *lvParentTask = task->parent;

    // If the task is included, the task object is on the stack which may be
    // cached. Invalidate before making any updates.
    if (tomp_isPtrCached((void *)lvParentTask))
        tomp_cacheWbInv(lvParentTask, sizeof(tomp_Task));

    // Decrement the children count for this task's parent
    lvParentTask->children_count--;

    // If the parent has completed execution and it's children have also
    // completed execution, free the parent
    if (lvParentTask->completed_execution && lvParentTask->children_count == 0)
        tomp_taskFree(lvParentTask);

    if (tomp_isPtrCached((void *)lvParentTask))
        tomp_cacheWbInv(lvParentTask, sizeof(tomp_Task));

    // Task event handle allocated dynamically in GOMP_task & must be free'd
    // Free only if the task has no children. 
    if (task->children_count == 0)
        tomp_taskFree(task);
    else
    {
        // Mark for later deletion. 
        task->completed_execution = true;
    }

    tomp_mutex_unlock(TOMP_TASK_HW_SEM_IDX);

}


/**
 * Allocate and initialize a task argument buffer
 *
 * If the arg buffer will fit in an EM buffer, allocate from EM to speed up
 * task generation. 
 *   - em_alloc/em_free       ~240  cycles
 *   - bare-metal malloc/free ~1474 cycles
 *   - IPC malloc/free        ~4578 cycles
 *
 * @param task pointer to task
 * @param data pointer to data associated with the task
 * @param arg_size size of the argument buffer associated with the task
 */
#define ALIGN_SIZE          (sizeof(long long))
#define ALIGN_TO_SIZE(x)    (((x) + ALIGN_SIZE-1) & ~(ALIGN_SIZE-1))
static inline void tomp_taskInitArgBuffer(tomp_Task *task, void *arg,
                                           int arg_size)
{
    if (arg_size == 0)
        return;

    char *buf_start = (char *)ALIGN_TO_SIZE((int)task + sizeof(*task));
    int   buf_size  = (char *)task + TOMP_EVENT_BUF_SIZE - buf_start;

    if (buf_size > arg_size)
    {
        task->arg_buffer         = buf_start;
        task->arg_buffer_in_task = true;
    }
    else
        task->arg_buffer = malloc(arg_size);

    if (task->arg_buffer == NULL)
        tomp_logError(tomp_ErrorKind_NULL_PTR, __FILE__, __LINE__);

    memcpy(task->arg_buffer, arg, arg_size);
}


/**
 * Free up memory allocated for the task argument buffer
 * @param task pointer to a task
 */
static inline void tomp_taskFreeArgBuffer(tomp_Task *task)
{
    // If buffer was malloc'ed, free it
    if (task->arg_buffer && task->arg_buffer_in_task == false)
    {
        free (task->arg_buffer);
        task->arg_buffer = NULL;
    }
}


/**
 * Free up memory allocated for an explicit task
 * @param task pointer to a task
 */
static inline void tomp_taskFree(tomp_Task *task)
{
    if (task->kind == tomp_TaskKind_INCLUDED) 
        return;

    tomp_logDebug1 ("TRACE: tomp_taskFree task 0x%08x\n", (int)task);

    tomp_taskFreeArgBuffer(task);
    tomp_eventFree (task->event);
}
