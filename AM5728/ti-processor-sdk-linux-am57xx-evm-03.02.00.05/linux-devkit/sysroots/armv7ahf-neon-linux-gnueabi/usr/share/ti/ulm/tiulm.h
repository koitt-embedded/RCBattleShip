/*
 * ulm.h
 *
 * Usage & Load Monitor Implementation
 *
 * Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com/ 
 * 
 * 
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions 
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the   
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/
#ifndef ULM_H
#define ULM_H

#include <stdint.h>
#include <stdbool.h>

#define CH_START_XPORT_ONLY      0      /* Start of OpenCL message channel space */
#define CH_START_DSPTOP          128    /* Start of dsptop message channel space */

typedef enum {
    ULM_STATE_IDLE = CH_START_XPORT_ONLY,
    ULM_STATE_RUN,
    ULM_OMP_EVENT_PARALLEL_START_ENTER,
    ULM_OMP_EVENT_PARALLEL_START_EXIT,
    ULM_OMP_EVENT_PARALLEL_END_ENTER,
    ULM_OMP_EVENT_PARALLEL_END_EXIT,
    ULM_OMP_EVENT_TASK_GEN,
    ULM_OMP_EVENT_TASK_START,
    ULM_OMP_EVENT_TASK_END,
    ULM_OMP_EVENT_IMPLICIT_TASK_START,
    ULM_OMP_EVENT_IMPLICIT_TASK_END,
    ULM_OCL_EXIT,
    ULM_OCL_NDR_OVERHEAD,
    ULM_OCL_NDR_KERNEL_START,
    ULM_OCL_NDR_KERNEL_COMPLETE,
    ULM_OCL_NDR_CACHE_COHERENCE_COMPLETE,
    ULM_OCL_OOT_OVERHEAD,
    ULM_OCL_OOT_KERNEL_START,
    ULM_OCL_OOT_KERNEL_COMPLETE,
    ULM_OCL_OOT_CACHE_COHERENCE_COMPLETE,
    ULM_OCL_IOT_OVERHEAD,
    ULM_OCL_IOT_KERNEL_START,
    ULM_OCL_IOT_KERNEL_COMPLETE,
    ULM_OCL_IOT_CACHE_COHERENCE_COMPLETE,
    ULM_STATE_EXIT,       
    ULM_STATE_LAST
}ulm_state_t;

typedef enum {
    ULM_MEM_EX_CODE_AND_DATA = ULM_STATE_LAST,
    ULM_MEM_EX_DATA_ONLY,
    ULM_MEM_IN_DATA_ONLY,
    ULM_MEM_LAST
}ulm_mem_t;

typedef enum {
    ULM_TEMP = CH_START_DSPTOP,
    ULM_TEMP_LAST
}ulm_temp_t;

typedef enum {
    ULM_SYNC = ULM_TEMP_LAST
}ulm_flush_t;

/* Transport functions */
void ulm_put_state(ulm_state_t state);
void ulm_put_statemsg(ulm_state_t state, uint32_t taskid, uint32_t value);
void ulm_put_mem(ulm_mem_t mem, uint32_t num_64kb_blocks, float frac_percent_free);
void ulm_put_temp(int8_t temp);

/* Configuration functions */
#ifdef __linux

typedef enum {
    ULM_SUCCESS,
    ULM_ERR_STM_OWNERSHIP_NOT_GRANTED,
    ULM_ERR_STM_FLUSH_FAILED,
    ULM_ERR_STM_MMAP,
    ULM_ERR_CSTF_MMAP
} ulm_error_t;

typedef struct {
	uint32_t  stm_data_flip;
	uint32_t  stp_version;
    uint8_t   atb_id;
    bool      using_twp;
	bool      atb_head_required;
	uint32_t  atb_head_present_0;
	uint32_t  atb_head_pointer_0;
	uint32_t  atb_head_present_1;
	uint32_t  atb_head_pointer_1;

}ulm_dcm_info_t;

ulm_error_t ulm_test_map();
ulm_error_t ulm_config();
void ulm_term();
ulm_error_t ulm_flush();
ulm_error_t ulm_enable();
ulm_error_t ulm_disable();
const char * ulm_get_statefmt(ulm_state_t state);
const char * ulm_get_statemsg(ulm_state_t state);
ulm_state_t ulm_get_runstate(ulm_state_t state);
void ulm_get_version(uint32_t * major, uint32_t * minor, uint32_t * patch);
void ulm_get_dcminfo(ulm_dcm_info_t  * dcm_info_p);
void ulm_put_sync();

#endif /* __linux */
#endif /* ULM_H */

