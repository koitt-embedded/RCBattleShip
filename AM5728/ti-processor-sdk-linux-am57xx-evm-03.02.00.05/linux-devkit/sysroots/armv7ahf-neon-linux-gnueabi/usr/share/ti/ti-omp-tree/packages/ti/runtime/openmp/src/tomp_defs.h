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
 * \file tomp_defs.h
 * 
 * \brief Defines various constants used by the TOMP runtime
 */

#ifndef _TOMP_DEFS_H_
#define _TOMP_DEFS_H_

/*! Number of cores on the device. Used to size data structures */
#if defined (TI_C6678) || defined (TI_C6636)
#define TOMP_DEVICE_NUM_CORES (8)
#define TOMP_DEVICE_HAS_HW_QUEUES 1
#define TOMP_DEVICE_HAS_HW_SEMAPHORES 1
#define TOMP_DEVICE_HAS_HW_SPINLOCKS 0
#define TOMP_DEVICE_HAS_XMC 1
#define TOMP_DEVICE_HAS_MSMC 1
#elif defined (TI_66AK2G)
#define TOMP_DEVICE_NUM_CORES (1)
#define TOMP_DEVICE_HAS_HW_QUEUES 0
#define TOMP_DEVICE_HAS_HW_SEMAPHORES 1
#define TOMP_DEVICE_HAS_HW_SPINLOCKS 0
#define TOMP_DEVICE_HAS_XMC 1
#define TOMP_DEVICE_HAS_MSMC 1
#elif defined (TI_C6670)
#define TOMP_DEVICE_NUM_CORES (4)
#define TOMP_DEVICE_HAS_HW_QUEUES 1
#define TOMP_DEVICE_HAS_HW_SEMAPHORES 1
#define TOMP_DEVICE_HAS_HW_SPINLOCKS 0
#define TOMP_DEVICE_HAS_XMC 1
#define TOMP_DEVICE_HAS_MSMC 1
#elif defined (TI_C6657)
#define TOMP_DEVICE_NUM_CORES (2)
#define TOMP_DEVICE_HAS_HW_QUEUES 1
#define TOMP_DEVICE_HAS_HW_SEMAPHORES 1
#define TOMP_DEVICE_HAS_HW_SPINLOCKS 0
#define TOMP_DEVICE_HAS_XMC 1
#define TOMP_DEVICE_HAS_MSMC 1
#elif defined (TI_AM572)
#define TOMP_DEVICE_NUM_CORES (2)
#define TOMP_DEVICE_HAS_HW_QUEUES 0
#define TOMP_DEVICE_HAS_HW_SEMAPHORES 0
#define TOMP_DEVICE_HAS_HW_SPINLOCKS 1
#define TOMP_DEVICE_HAS_XMC 1
#define TOMP_DEVICE_HAS_MSMC 0
#else
#define "Error, device not supported"
#endif

/*! Number of events in the QMSS free descriptor queue */
#define TOMP_EVENT_NUM      (256)

/*! Size of each event buffer */
/*! Needs to be large enough to hold the gomp_work_share structure */
#define TOMP_EVENT_BUF_SIZE (160)

/*! Size of each CIO buffer (includes header) */
#define CIO_MSG_BUF_SIZE    (512)

/*! Number of CIO buffers */
#define CIO_MSG_BUF_NUM     (1024)

/*! Global Timestamp register address on KeyStone 1 and 2 */
#define GLOBAL_TIMESTAMP_ADRS   (0x023101F0)

/*! Base address for memory mapped MARs */
#define MAR_ADDRESS_BASE        (0x1848000)

#endif /* _TOMP_DEFS_H_ */
