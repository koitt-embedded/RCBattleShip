/* 
 * Copyright (c) 2012, Texas Instruments Incorporated
 * http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * */
/*
 *  ======== HeapOMP.c ========
 */

#include <xdc/std.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/IHeap.h>
#include <ti/ipc/SharedRegion.h>

#include <ti/runtime/ompbios/OpenMP.h>

#include "package/internal/HeapOMP.xdc.h"


/*
 *  ======== HeapOMP_getHeapFromAddr ========
 */
static IHeap_Handle HeapOMP_getHeapFromAddr(HeapOMP_Object *obj, Ptr addr)
{
    /* HeapOMP does not keep track of the heap used by alloc i.e. HeapMemMP
     * vs. HeapMem. Used the SharedRegion_getId function to determine if
     * the allocation is in a shared heap (HeapMemMP)
     */
    IHeap_Handle iHeap    = obj->localHeap;
    UInt16       regionId = SharedRegion_getId(addr);

    if (regionId != SharedRegion_INVALIDREGIONID)
        iHeap = SharedRegion_getHeap(regionId);

    return iHeap;
}

/*
 *************************************************************************
 *                      Instance functions
 *************************************************************************
 */

/*
 *  ======== HeapOMP_Instance_init ========
 */
Void HeapOMP_Instance_init(HeapOMP_Object *obj, const HeapOMP_Params *params)
{
    obj->localHeap      = params->localHeap;
    obj->sharedRegionId = params->sRegionId;
}


/*
 *  ======== HeapOMP_alloc ========
 */
Ptr HeapOMP_alloc(HeapOMP_Object *obj, SizeT reqSize, 
                  SizeT reqAlign, Error_Block *eb)
{
    /* Ipc_start() initializes shared regions & creates a shared heap.
     * If Ipc_start() has been called, allocate from shared heap (HeapMemMP)
     * If not, allocate from HeapMem
     */
    if (OpenMP_useSharedHeap()) {
        return Memory_alloc(SharedRegion_getHeap(obj->sharedRegionId), 
                            reqSize, reqAlign, eb);
    }
    else {
        return Memory_alloc(obj->localHeap, reqSize, reqAlign, eb);
    }

}

/*
 *  ======== HeapOMP_free ========
 */
Void HeapOMP_free(HeapOMP_Object *obj, Ptr addr, SizeT size)
{
    Memory_free(HeapOMP_getHeapFromAddr(obj, addr), addr, size);
}

/*
 *  ======== HeapOMP_isBlocking ========
 */
Bool HeapOMP_isBlocking(HeapOMP_Object *obj)
{
    return TRUE;
}

/*
 *  ======== HeapOMP_getStats ========
 */
Void HeapOMP_getStats(HeapOMP_Object *obj, Memory_Stats *stats)
{
    /* Call appropriate getStats */
}

