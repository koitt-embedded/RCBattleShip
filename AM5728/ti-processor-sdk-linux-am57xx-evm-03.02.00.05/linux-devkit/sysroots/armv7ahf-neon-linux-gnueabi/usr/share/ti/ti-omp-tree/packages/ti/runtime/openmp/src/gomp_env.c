/* Copyright (C) 2005, 2006, 2007, 2008, 2009, 2010
   Free Software Foundation, Inc.
   Contributed by Richard Henderson <rth@redhat.com>.

   This file is part of the GNU OpenMP Library (libgomp).

   Libgomp is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   Libgomp is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
   FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
   more details.

   Under Section 7 of GPL version 3, you are granted additional
   permissions described in the GCC Runtime Library Exception, version
   3.1, as published by the Free Software Foundation.

   You should have received a copy of the GNU General Public License and
   a copy of the GCC Runtime Library Exception along with this program;
   see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
   <http://www.gnu.org/licenses/>.  */

/* Copyright (C) 2013
   Texas Instruments, Inc.
   
   Changes from original:
   - Replaced gomp_error() with tomp_logErrorStr()    
   - Removed functionality for parsing unsupported environment variables
*/

/* This file defines the OpenMP internal control variables, and arranges
   for them to be initialized from environment variables at startup.  */
   
#include "tomp_parallel.h"
#include "omp.h"
#include "tomp_log.h"
#include "strings.h"

#include <ctype.h>
#include <limits.h>
#include <errno.h>

/* Variables used by multiple cores have to be in shared memory 
 * There are non-cacheable for performance reason like Event Machine variables:
 * Cost of write back/invalidate superior than cost of reading a few times */

/* gomp_task_icv is used:
 * 1. for holding ICV values set with environment variables/default ICV values
 * 2. as a placeholder for capturing initialTaskForMaster's ICVs to be used 
      to initialize ICVs for implicit tasks. */
#pragma DATA_SECTION(gomp_global_icv, ".tomp_svNcMem")
struct gomp_task_icv gomp_global_icv = {
  /*.nthreads_var = */1,
  /*.run_sched_var = */GFS_DYNAMIC,
  /*.run_sched_modifier = */1,
#if 0
  /*.dyn_var = */false,
  /*.nest_var =*/ false
#endif
};

#pragma DATA_SECTION(gomp_max_active_levels_var, ".tomp_svNcMem")
unsigned long gomp_max_active_levels_var = 1;

#pragma DATA_SECTION(gomp_thread_limit_var, ".tomp_svNcMem")
unsigned long gomp_thread_limit_var = ULONG_MAX;



/* Parse the OMP_SCHEDULE environment variable.  */

static void
parse_schedule (void)
{
  char *env, *end;
  unsigned long value;

  env = getenv ("OMP_SCHEDULE");
  if (env == NULL)
    return;

  while (isspace ((unsigned char) *env))
    ++env;
  if (strncasecmp (env, "static", 6) == 0)
    {
      gomp_global_icv.run_sched_var = GFS_STATIC;
      env += 6;
    }
  else if (strncasecmp (env, "dynamic", 7) == 0)
    {
      gomp_global_icv.run_sched_var = GFS_DYNAMIC;
      env += 7;
    }
  else if (strncasecmp (env, "guided", 6) == 0)
    {
      gomp_global_icv.run_sched_var = GFS_GUIDED;
      env += 6;
    }
  else if (strncasecmp (env, "auto", 4) == 0)
    {
      gomp_global_icv.run_sched_var = GFS_AUTO;
      env += 4;
    }
  else
    goto unknown;

  while (isspace ((unsigned char) *env))
    ++env;
  if (*env == '\0')
    return;
  if (*env++ != ',')
    goto unknown;
  while (isspace ((unsigned char) *env))
    ++env;
  if (*env == '\0')
    goto invalid;

  errno = 0;
  value = strtoul (env, &end, 10);
  if (errno)
    goto invalid;

  while (isspace ((unsigned char) *end))
    ++end;
  if (*end != '\0')
    goto invalid;

  if ((int)value != value)
    goto invalid;

  gomp_global_icv.run_sched_modifier = value;
  return;

 unknown:
  tomp_logErrorStr(tomp_ErrorKind_OMP_INIT, 
        "Unknown value for environment variable OMP_SCHEDULE",
        __FILE__, __LINE__);
  return;

 invalid:
  tomp_logErrorStr(tomp_ErrorKind_OMP_INIT, 
        "Invalid value for chunk size in environment variable OMP_SCHEDULE",
        __FILE__, __LINE__);
  return;
}

/* Parse an unsigned long environment variable.  Return true if one was
   present and it was successfully parsed.  */

static bool
parse_unsigned_long (const char *name, unsigned long *pvalue, bool allow_zero)
{
  char *env, *end;
  unsigned long value;

  env = getenv (name);
  if (env == NULL)
    return false;

  while (isspace ((unsigned char) *env))
    ++env;
  if (*env == '\0')
    goto invalid;

  errno = 0;
  value = strtoul (env, &end, 10);
  if (errno || (long) value <= 0 - allow_zero)
    goto invalid;

  while (isspace ((unsigned char) *end))
    ++end;
  if (*end != '\0')
    goto invalid;

  *pvalue = value;
  return true;

 invalid:
  tomp_logErrorStr(tomp_ErrorKind_OMP_INIT, 
        "Invalid value for environment variable",
        __FILE__, __LINE__);
  return false;
}

void initialize_env (void)
{

  parse_schedule ();
  parse_unsigned_long ("OMP_MAX_ACTIVE_LEVELS", &gomp_max_active_levels_var,
		       true);
  parse_unsigned_long ("OMP_THREAD_LIMIT", &gomp_thread_limit_var, false);
  gomp_global_icv.nthreads_var = TOMP_NUM_CORES;
  parse_unsigned_long ("OMP_NUM_THREADS", &gomp_global_icv.nthreads_var, 
                            false);
}


/* The public OpenMP API routines that access these variables.  */

void
omp_set_num_threads (int n)
{
   struct gomp_task_icv *icv = gomp_icv ();
   icv->nthreads_var = (n > 0 ? n : 1);
}

int
omp_get_max_threads (void)
{
   struct gomp_task_icv *icv = gomp_icv ();
   return icv->nthreads_var;
}

void
omp_set_dynamic (int val)
{
   return;
}

int
omp_get_dynamic (void)
{
#if 0
  struct gomp_task_icv *icv = gomp_icv ();
  return icv->dyn_var;
#endif
  return false;
}

void
omp_set_nested (int val)
{
   return;
}

int
omp_get_nested (void)
{
#if 0
  struct gomp_task_icv *icv = gomp_icv ();
  return icv->nest_var;
#endif
  return false;
}

void
omp_set_schedule (omp_sched_t kind, int modifier)
{
  struct gomp_task_icv *icv = gomp_icv ();
  switch (kind)
    {
    case omp_sched_static:
      if (modifier < 1)
	modifier = 0;
      icv->run_sched_modifier = modifier;
      break;
    case omp_sched_dynamic:
    case omp_sched_guided:
      if (modifier < 1)
	modifier = 1;
      icv->run_sched_modifier = modifier;
      break;
    case omp_sched_auto:
      break;
    default:
      return;
    }
  icv->run_sched_var = (enum gomp_schedule_type)kind;
}

void
omp_get_schedule (omp_sched_t *kind, int *modifier)
{
  struct gomp_task_icv *icv = gomp_icv ();
  *kind = (omp_sched_t)icv->run_sched_var;
  *modifier = icv->run_sched_modifier;
}

int
omp_get_thread_limit (void)
{
  return gomp_thread_limit_var > TOMP_NUM_CORES ? TOMP_NUM_CORES
     : gomp_thread_limit_var;
}

void
omp_set_max_active_levels (int max_levels)
{
  if ((max_levels == 0) || (max_levels == 1))
    gomp_max_active_levels_var = max_levels;
}

int
omp_get_max_active_levels (void)
{
  return gomp_max_active_levels_var;
}

int
omp_is_initial_device (void)
{
  return false;
}

