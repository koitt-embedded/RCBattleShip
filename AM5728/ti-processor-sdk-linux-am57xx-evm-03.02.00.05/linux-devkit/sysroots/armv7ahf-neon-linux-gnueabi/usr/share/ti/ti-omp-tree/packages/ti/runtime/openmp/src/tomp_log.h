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
 * \file tomp_log.h
 * 
 * \brief Supports various mechanisms for logging errors & tracing
 */

#ifndef _TOMP_LOG_H_
#define _TOMP_LOG_H_

/*! Log errors/warnings with printf */
#define tomp_LOG_WITH_PRINTF    (1)

#if tomp_LOG_WITH_PRINTF
#include <stdio.h>
#endif

#include <stdlib.h>     // for exit()

extern void tomp_sendExitEvents(void);

/*! Error kinds */
typedef enum { tomp_ErrorKind_EM_ALLOC = 0, 
               tomp_ErrorKind_EM_ALLOC_SIZE,
               tomp_ErrorKind_NULL_PTR,
               tomp_ErrorKind_OEM_INIT,
               tomp_ErrorKind_OMP_INIT,
               tomp_ErrorKind_QMSS,
               tomp_ErrorKind_QUEUE
} tomp_ErrorKind_e;

/*! String corresponding to the error kinds */
extern const char *tomp_ErrorString[];

#define GLOBAL_TIMESTAMP_ADRS (0x023101F0)

static inline unsigned long long getGlobalTimeStamp()
{
#if defined(TI_AM572)
    return 0LL;
#else
    return _itoll( *(unsigned int *)(4+GLOBAL_TIMESTAMP_ADRS),
                   *(unsigned int *)(GLOBAL_TIMESTAMP_ADRS));
#endif
}


/**
 * Log an error message along with file name and line number
 * and terminate execution
 */
static inline void tomp_logError(tomp_ErrorKind_e  e,
                                 const char       *file,
                                 int               line)
{
    #if tomp_LOG_WITH_PRINTF
    printf("INTERNAL ERROR: %s - %s, %d\n", tomp_ErrorString[e], file, line);
    #endif
    tomp_sendExitEvents();
    exit(1);
} 

/**
 * Log an error message along with a custom string, file name and line number
 * and terminate execution
 */
static inline void tomp_logErrorStr(tomp_ErrorKind_e  e, 
                                    const char       *str, 
                                    const char       *file,
                                    int               line)
{
    #if tomp_LOG_WITH_PRINTF
    printf("INTERNAL ERROR: %s (%s) - %s, %d\n", tomp_ErrorString[e],
                                                 str, file, line);
    #endif
    tomp_sendExitEvents();
    exit(1);
} 

/**
 * Log a debug message with a format string and 1 integer argument
 */
static inline void tomp_logDebug1(const char *fmt, int arg1)
{
#if defined (TOMP_TRACE_LEVEL) && (TOMP_TRACE_LEVEL > 0)
    #if tomp_LOG_WITH_PRINTF
    printf("(%016llu) ", getGlobalTimeStamp());
    printf(fmt, arg1);
    #endif
#endif
}

/**
 * Log a debug message with a format string and 2 integer arguments
 */
static inline void tomp_logDebug2(const char *fmt, int arg1, int arg2)
{
#if defined (TOMP_TRACE_LEVEL) && (TOMP_TRACE_LEVEL > 0)
    #if tomp_LOG_WITH_PRINTF
    printf("(%016llu) ", getGlobalTimeStamp());
    printf(fmt, arg1, arg2);
    #endif
#endif
}

/**
 * Log a debug message with a format string and 3 integer arguments
 */
static inline void tomp_logDebug3(const char *fmt, int arg1, int arg2, int arg3)
{
#if defined (TOMP_TRACE_LEVEL) && (TOMP_TRACE_LEVEL > 0)
    #if tomp_LOG_WITH_PRINTF
    printf("(%016llu) ", getGlobalTimeStamp());
    printf(fmt, arg1, arg2, arg3);
    #endif
#endif
}


/******************
 * TASK STATISTICS 
 ******************/
//#define TASK_STATS
#ifdef TASK_STATS

typedef struct {
    unsigned short      id;
    unsigned short      parent_id;
    unsigned long long  gen_cycle;
    unsigned int        start_cycle_delta;
    unsigned int        end_cycle_delta;
    unsigned char       gen_core;
    unsigned char       exec_core;
} TaskStats;

extern TaskStats tomp_TaskStats[];
#endif


#endif /* _TOMP_LOG_H_ */


