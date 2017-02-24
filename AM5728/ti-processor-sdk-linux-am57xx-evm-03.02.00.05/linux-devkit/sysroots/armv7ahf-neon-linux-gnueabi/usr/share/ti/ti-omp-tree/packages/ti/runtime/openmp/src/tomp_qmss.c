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
 * \file tomp_qmss.c
 */

#include "tomp_defs.h"
#if TOMP_DEVICE_HAS_HW_QUEUES

#include "tomp_init.h"
#include "tomp_qmss.h"
#include "tomp_qmss_api.h"
#include "tomp_util.h"
#include "tomp_log.h"


/*! Queues used by the OpenMP Runtime */
#pragma DATA_SECTION (tomp_queues, ".tomp_svNcMem");
tomp_Queues tomp_queues;

/*! Memory region used by the OpenMP Runtime */
#pragma DATA_SECTION (tomp_qmssMemRegInfo, ".tomp_svNcMem");
Qmss_MemRegInfo tomp_qmssMemRegInfo;

/*! Buffer used for allocations */
#pragma DATA_ALIGN   (tomp_svEventBufMem, CACHE_L2_LINESIZE)
#pragma DATA_SECTION (tomp_svEventBufMem, ".tomp_svNcMem");
uint8_t tomp_svEventBufMem[TOMP_EVENT_NUM * TOMP_EVENT_BUF_SIZE];

extern Qmss_GlobalConfigParams qmssGblCfgParams;

#if defined (TI_C6636)
#pragma WEAK(tomp_cioInitQmss)
extern bool tomp_cioInitQmss(int32_t qmssStartIndex);

#pragma WEAK(tomp_cioExitQmss)
extern void tomp_cioExitQmss(void);
#endif



static void tomp_initRegionConfig(Qmss_MemRegInfo* memRegInfo,
                                  bool             memRegionInitialized);
static bool tomp_initQmss        (Qmss_MemRegInfo* regionConfigTbl, 
                                  uint8_t* extLinkTbl);

static tomp_queue_t tomp_initFreeDesc(Qmss_MemRegInfo* memRegInfo, int32_t qid);
static void         tomp_resetQueues (void);
static bool         tomp_openQueues  (Qmss_MemRegInfo* memRegInfo);
       void         tomp_closeQueues (void);



/**
 * Initializes the NRT (QMSS sub system) for OpenMP
 *
 * Called by the master core only. Sets up the memory region, initializes
 * QMSS (if required) and opens the queues required by OpenMP.
 *
 * NOTE: This function must be called BEFORE tomp_dispatch_once is 
 *       called on the worker cores.
 */
bool tomp_initGlobalNRT(bool memRegionInitialized)
{
    tomp_resetQueues();

    Qmss_MemRegInfo *memRegInfo = &tomp_qmssMemRegInfo;

    // Build table of region configurations
    tomp_initRegionConfig(memRegInfo, memRegionInitialized);

    // Initialize QMSS if specified by __TI_omp_config_hw_queues API
    if (TOMP_MUST_INIT_QMSS && !tomp_initQmss (memRegInfo, NULL))
        return false;

    // Insert descriptor regions. In OpenCL mode, the memory region is
    // inserted during OpenEM initialization and we get a 
    // already initialized error message. Ignore it.
    Qmss_Result region = Qmss_insertMemoryRegion (memRegInfo);
    if (region >= Qmss_MemRegion_MEMORY_REGION0)
        memRegInfo->memRegion = (Qmss_MemRegion)region;
    else if (region == QMSS_MEMREGION_ALREADY_INITIALIZED)
        ;
    else
        return false;

    // Setup OpenMP queues
    if (!tomp_openQueues(memRegInfo))
        return false;

#if defined (TI_C6636)
    // tomp_cioInitQmss is a weak reference. If the CIO library is included
    // in the link, the initialization function is called.
#pragma diag_suppress 238
    if (&tomp_cioInitQmss)
        tomp_cioInitQmss(memRegInfo->startIndex + TOMP_EVENT_NUM);
#pragma diag_default 238
#endif

    // Ensure all writes to tomp_Queue object land. This object is
    // read by worker cores. There is also a barrier after this call.
    tomp_mfence();

    return true;
}


/**
 * Close queues and exit QMSS. Called by master core only
 */
void tomp_exitGlobalNRT(void)
{
    tomp_closeQueues();

#if defined (TI_C6636)
#pragma diag_suppress 238
    if (&tomp_cioExitQmss)
        tomp_cioExitQmss();
#pragma diag_default 238

    // Must remove memory region before calling Qmss_exit!
    Qmss_removeMemoryRegion(tomp_qmssMemRegInfo.memRegion, /*qGroup*/0);

    // If OMP runtime initialized QMSS, "de-initialize" it
    if (TOMP_MUST_INIT_QMSS) 
        Qmss_exit();
#endif
}


/**
 * Per-core initialization for QMSS
 */
bool tomp_initLocalNRT(void)
{
    if (Qmss_start() != QMSS_SOK) return false;

    return true;
}


/**
 * Initialize QMSS memory region for OpenMP
 *
 * @param memRegInfo pointer to memory region info 
 * @param memRegionInitialized if true, indicated that the memRegion and
 *        startIndex have already been set and must not be initialized.
 *        Used in the mode where the application/OpenCL initializes QMSS
 */
void tomp_initRegionConfig(Qmss_MemRegInfo* memRegInfo,
                           bool             memRegionInitialized)
{
    // Initialize descriptor regions
    memRegInfo->descSize = TOMP_EVENT_BUF_SIZE;
    memRegInfo->descNum  = TOMP_EVENT_NUM;
    memRegInfo->descBase = (uint32_t *) tomp_svEventBufMem;

    // LLD manages descriptors via Qmss_initDescriptor
    //memRegInfo->manageDescFlag = Qmss_ManageDesc_MANAGE_DESCRIPTOR;
    memRegInfo->manageDescFlag = Qmss_ManageDesc_UNMANAGED_DESCRIPTOR;

    if (!memRegionInitialized)
    {
        memRegInfo->memRegion = 
                        (Qmss_MemRegion)(TOMP_QMSS_FIRST_MEMORY_REGION_IDX);
        memRegInfo->startIndex = TOMP_QMSS_FIRST_DESC_IDX_IN_LINKING_RAM;
    }
}


/**
 * Initialize QMSS for OpenMP.
 *
 * If an external application or OpenCL has already initialized QMSS, this
 * function is not called by the OpenMP runtime.
 */
bool tomp_initQmss (Qmss_MemRegInfo* regionConfigTbl, uint8_t* extLinkTbl)
{
    Qmss_InitCfg             qmssCfg;
    Qmss_GlobalConfigParams* qmssGlobalCfg;

    // Set up the linking RAM configuration. Use the internal Linking RAM. 
    qmssCfg.linkingRAM0Base = 0; // Use linking RAM of Navigator SS

    qmssGlobalCfg = &qmssGblCfgParams;

#if defined (TI_C6678) || defined (TI_C6670) || defined (TI_C6657)
    qmssCfg.linkingRAM0Size = 0; // Use all linking RAM of Navigator SS
    qmssCfg.linkingRAM1Base = (uint32_t)extLinkTbl;
#elif defined (TI_C6636)
    // Linux already configured QMSS 
    // Retrieving the value
    {
        CSL_Qm_configRegs *qm_config_regs_ptr;
        qm_config_regs_ptr = (CSL_Qm_configRegs *) CSL_QMSS_CFG_QM_1_CFG_REGS;
        qmssCfg.linkingRAM0Size = 
                            qm_config_regs_ptr->LINKING_RAM_REGION_0_SIZE_REG;
        qmssCfg.linkingRAM1Base = 
                    qm_config_regs_ptr->LINKING_RAM_REGION_1_BASE_ADDRESS_REG;
    }

    // mode field available only in the KS2 PDK
    qmssCfg.mode = Qmss_Mode_JOINT_LOADBALANCED;
#else
#error "Device not supported"
#endif

    qmssCfg.maxDescNum = (TOMP_QMSS_FIRST_DESC_IDX_IN_LINKING_RAM > 0) ? 
            TOMP_QMSS_FIRST_DESC_IDX_IN_LINKING_RAM + regionConfigTbl->descNum :
            regionConfigTbl->descNum;

#if defined (TI_C6636)
    // If QMSS is used for CIO, include CIO descriptor count
#pragma diag_suppress 238
    if (&tomp_cioInitQmss)
        qmssCfg.maxDescNum += CIO_MSG_BUF_NUM;
#pragma diag_default 238
#endif

    // Pdsp's are not used by the OpenMP runtime
    int i;
    for (i=0; i<QMSS_MAX_PDSP; i++)
    {
        qmssCfg.pdspFirmware[i].pdspId   = (Qmss_PdspId)i;
        qmssCfg.pdspFirmware[i].firmware = NULL;
        qmssCfg.pdspFirmware[i].size     = 0;
    }

    // Initialize QMSS 
    if (Qmss_init (&qmssCfg, qmssGlobalCfg) != QMSS_SOK)
        return false;

    // Start QMSS
    if (Qmss_start () != QMSS_SOK)
        return false;

    return true;
}


#define FREE_QID                (TOMP_HW_QUEUE_BASE_IDX)
#define IMPLICIT_TASK_QID       (TOMP_HW_QUEUE_BASE_IDX + 1)
#define EXIT_QID                (TOMP_HW_QUEUE_BASE_IDX + 2)
#define EXPLICIT_TASK_BASE_QID  (TOMP_HW_QUEUE_BASE_IDX + 3)

#define SELECT_QID(a, b) ((a) == QMSS_PARAM_NOT_SPECIFIED ? (a) : (b))

/**
 * Open all queues required by OpenMP and populate the free queue
 */
bool tomp_openQueues(Qmss_MemRegInfo *memRegInfo)
{
    // Populate the freeQ with descriptors
    int32_t qid = SELECT_QID(TOMP_HW_QUEUE_BASE_IDX, FREE_QID);
    tomp_queues.freeDescriptorQ = tomp_initFreeDesc(memRegInfo, qid);

    qid = SELECT_QID(TOMP_HW_QUEUE_BASE_IDX, IMPLICIT_TASK_QID);
    tomp_queues.implicitTaskQ = tomp_queueOpen(qid);

    qid = SELECT_QID(TOMP_HW_QUEUE_BASE_IDX, EXIT_QID);
    tomp_queues.exitQ         = tomp_queueOpen(qid);

    Qmss_queueEmpty (tomp_queues.implicitTaskQ);
    Qmss_queueEmpty (tomp_queues.exitQ);

    int i;
    for (i = 0; i < tomp_queues.numExplicitTaskQ; i++)
    {
        qid = SELECT_QID(TOMP_HW_QUEUE_BASE_IDX, EXPLICIT_TASK_BASE_QID + i);
        tomp_queues.explicitTaskQ[i] = tomp_queueOpen(qid);
        Qmss_queueEmpty (tomp_queues.explicitTaskQ[i]);
    }

    return true;
}


/**
 * Close and reset all queues used by OpenMP
 */
void tomp_closeQueues(void)
{
    int i;

    Qmss_queueEmpty (tomp_queues.implicitTaskQ);
    Qmss_queueEmpty (tomp_queues.exitQ);
    Qmss_queueEmpty (tomp_queues.freeDescriptorQ);

    Qmss_queueClose (tomp_queues.implicitTaskQ);
    Qmss_queueClose (tomp_queues.exitQ);
    Qmss_queueClose (tomp_queues.freeDescriptorQ);

    for (i = 0; i < tomp_queues.numExplicitTaskQ; i++)
    {
        Qmss_queueEmpty (tomp_queues.explicitTaskQ[i]);
        Qmss_queueClose (tomp_queues.explicitTaskQ[i]);
    }

    tomp_resetQueues();
}


/**
 * Reset all queues used by OpenMP 
 */
void tomp_resetQueues(void)
{
    int i;

    tomp_queues.implicitTaskQ   = QMSS_PARAM_NOT_SPECIFIED;
    tomp_queues.exitQ           = QMSS_PARAM_NOT_SPECIFIED;
    tomp_queues.freeDescriptorQ = QMSS_PARAM_NOT_SPECIFIED;

    tomp_queues.numExplicitTaskQ = TOMP_DEVICE_NUM_CORES;

    for (i = 0; i < tomp_queues.numExplicitTaskQ; i++)
    {
        tomp_queues.explicitTaskQ[i] = QMSS_PARAM_NOT_SPECIFIED;
    }
}


/**
 * Open a queue specified by qid. If the queue is already open, report error
 */
tomp_queue_t tomp_queueOpen(int32_t qid)
{
    uint8_t isAllocated;
    Qmss_QueueHnd qHnd = Qmss_queueOpen(Qmss_QueueType_GENERAL_PURPOSE_QUEUE,
                                        qid, &isAllocated);

    if (qHnd < 0 || (isAllocated != 1))
       tomp_logError(tomp_ErrorKind_QMSS, __FILE__, __LINE__); 

    return qHnd;
}


#if 0
/**
 * Re-open a queue. Do not report an error if queue is already open
 */
tomp_queue_t tomp_queueReopen(int32_t qid)
{
    uint8_t isAllocated;
    Qmss_QueueHnd qHnd = Qmss_queueOpen(Qmss_QueueType_GENERAL_PURPOSE_QUEUE,
                                        qid, &isAllocated);

    if (qHnd < 0)
       tomp_logError(tomp_ErrorKind_QMSS, __FILE__, __LINE__); 

    return qHnd;
}
#endif


/**
 * Initialize the free queue
 */
tomp_queue_t tomp_initFreeDesc(Qmss_MemRegInfo* memRegInfo, int32_t qid)
{
#if 0
    // Set up a descriptor configuration
    Qmss_DescCfg descCfg;
    descCfg.memRegion    = memRegInfo->memRegion;
    descCfg.descNum      = memRegInfo->descNum;
    descCfg.destQueueNum = qid;
    descCfg.queueType    = Qmss_QueueType_GENERAL_PURPOSE_QUEUE;

    // Chunks up the total descriptor memory into descriptors and
    // pushes into a queue
    uint32_t numAllocated;
    Qmss_QueueHnd freeDescQ = Qmss_initDescriptor (&descCfg, &numAllocated);
    if (freeDescQ < 0 || numAllocated != descCfg.descNum)
        tomp_logError(tomp_ErrorKind_QMSS, __FILE__, __LINE__);
#else
    // Qmss_initDescriptor uses a temporary queue internally to store
    // descriptors. On Hawking, this temporary queue could potentially
    // conflict with queues used by Linux etc. Use Qmss_queuePushDesc
    // onto the OpenMP free queue instead.
    tomp_queue_t freeDescQ = tomp_queueOpen(qid);

    // Clear out any descriptors left behind from a previous run - typically
    // because the previous run of the program did not terminate and 
    // the queues were not emptied.
    Qmss_queueEmpty (freeDescQ);

    uint8_t* descPtr = (uint8_t *)memRegInfo->descBase;
    uint32_t descSize = memRegInfo->descSize;

    int i;
    for (i = 0; i < memRegInfo->descNum; i++)
    {
        Qmss_queuePushDesc(freeDescQ, (void*)descPtr);
        descPtr += descSize;
    }
#endif

    return freeDescQ;
}


/** \defgroup omp_config */
/* @{ */
/**
 * API to get information on Memory regions used by the OpenMP runtime.
 *
 * @param memRegions array of memory regions allocated by caller. OpenMP
 *  runtime will update memRegions with descriptor size, number and base
 *  address for each region it uses.
 * @param memRegionCount OpenMP runtime will set to number of regions used 
 *  by it
 */
void __TI_omp_get_qmss_memory_regions(Qmss_MemRegInfo* memRegions, 
                                      int*             memRegionCount)
{
    *memRegionCount = 1;
    tomp_initRegionConfig(&memRegions[0], false);
}


/**
 * API to update the OpenMP runtime with memRegion and startIndex
 * allocated by the caller.
 */
void __TI_omp_update_qmss_memory_regions(Qmss_MemRegInfo* memRegions, 
                                         int              memRegionCount)
{
    tomp_initRegionConfig(&tomp_qmssMemRegInfo, false);
    tomp_qmssMemRegInfo.memRegion =  memRegions[0].memRegion;
    tomp_qmssMemRegInfo.startIndex = memRegions[0].startIndex;
}

#endif // TOMP_DEVICE_HAS_HW_QUEUES
/* @} */
