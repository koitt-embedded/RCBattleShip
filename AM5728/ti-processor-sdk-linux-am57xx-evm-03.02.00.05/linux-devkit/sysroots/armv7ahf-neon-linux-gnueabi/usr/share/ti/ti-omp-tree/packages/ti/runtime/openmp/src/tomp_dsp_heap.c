/*
 * Copyright (c) 2014, Texas Instruments Incorporated - http://www.ti.com/
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
 * \file tomp_dsp_heap.c
 * 
 * \brief Thread safe, coherency aware dynamic memory management routines. 
 *
 * Following changes to make malloc/free thread-safe and support coherency on  
 * C66x Keystone architectures:                                           
 *   - Using a Hardware Semaphore to implement mutual exclusion            
 *   - Added invalidate of packet structures before and after updates        
 */
#include <stdlib.h>
#include <string.h>
#include "tomp_util.h"
#include "tomp_dsp_heap_api.h"

/*---------------------------------------------------------------------------*/
/* MIN_BLOCK MUST BE A MULTIPLE OF THE SIZEOF (LARGE_TYPE)                   */
/*---------------------------------------------------------------------------*/
#define LARGE_TYPE      long double

#define MIN_BLOCK       (sizeof(LARGE_TYPE)) 
#define BLOCK_OVERHEAD  MIN_BLOCK
#define BLOCK_USED      1
#define BLOCK_MASK      (MIN_BLOCK-1)


/*---------------------------------------------------------------------------*/
/* "PACKET" is the template for a data packet.  Packet size contains         */
/* the number of bytes allocated for the user, excluding the size required   */
/* for management of the packet (BLOCK_OVERHEAD bytes).  Packets are always  */
/* allocated memory in MIN_BLOCK byte chunks. The lowest order bit of the    */
/* size field is used to indicate whether the packet is free(0) or used(1).  */
/* The size_ptr field is used to manage the free list, and is a pointer      */
/* to the next element in the free list.  The free list is sorted by size.   */
/*---------------------------------------------------------------------------*/
typedef struct pack 
{
    unsigned int packet_size;     /* number of bytes        */
    struct pack  *size_ptr;       /* next elem in free list */
} PACKET;


/*---------------------------------------------------------------------------*/
/* "tomp_DspHeap" keeps track of heap state for a single heap                */
/*---------------------------------------------------------------------------*/
typedef struct _tomp_DspHeap
{
    PACKET* sys_memory;  /* Points to the base of the heap */
    PACKET* free;        /* Points to the free list */
    size_t  size;        /* Total size of the heap */
} tomp_DspHeap;


/*---------------------------------------------------------------------------*/
/* Total number of heaps supported - 3 global                                */
/*---------------------------------------------------------------------------*/
#define NUM_GLOBAL_HEAPS    (3) /* 1 in MSMC, 2 in DDR (user and runtime) */

/*---------------------------------------------------------------------------*/
/* Variable placed in non-cached memory to avoid overhead of cache operations*/
/* when multiple cores access the free pointer.                              */
/*---------------------------------------------------------------------------*/
#pragma DATA_SECTION (__ti_dsp_heap, ".tomp_svNcMem")
tomp_DspHeap __ti_dsp_heap[NUM_GLOBAL_HEAPS];


/**
 * Invalidate packet list
 *
 * For every PACKET in on the heap (i.e. allocated and free packets), 
 * invalidate the cache line the PACKET resides on. In the OMP runtime, heap 
 * must be write-through, so there is no need to writeback.
 */
static inline void inv_packet_list(PACKET *heap, size_t heap_size)
{
    PACKET* current = heap;
    char*   heap_mem = (char *)heap;

    /* Loop through all packets */
    while (current < (PACKET *) &heap_mem[heap_size-BLOCK_OVERHEAD]) 
    {
        tomp_cacheInv(current, sizeof (PACKET));
	int size = current->packet_size & ~BLOCK_USED;
        current = (PACKET *)((char *)current + size + BLOCK_OVERHEAD);
    }
}


static inline void acquire_lock_and_inv(PACKET *heap, size_t heap_size)
{
    acquire_dsp_heap_lock();
    inv_packet_list(heap, heap_size);
}

static inline void inv_and_release_lock(PACKET *heap, size_t heap_size)
{
    inv_packet_list(heap, heap_size);
    release_dsp_heap_lock();
}


/*---------------------------------------------------------------------------*/
/* Function declarations                                                     */
/*---------------------------------------------------------------------------*/
static void minsert(ti_omp_dsp_heap_idx, PACKET *);
static void mremove(ti_omp_dsp_heap_idx, PACKET *);


/*****************************************************************************/
/*									     */
/*  MINSERT - Insert a packet into the free list.  This list is sorted by    */
/*	      size in increasing order. 				     */
/*									     */
/* NOTE: All calls to minsert() should occur inside a critical section       */
/*****************************************************************************/
static void minsert(ti_omp_dsp_heap_idx idx, PACKET *ptr)
{
    PACKET *current = (PACKET *) __ti_dsp_heap[idx].free;
    PACKET *last    = NULL;

    /*-----------------------------------------------------------------------*/
    /* CHECK SPECIAL CASE, EMPTY FREE LIST.				     */
    /*-----------------------------------------------------------------------*/
    if (current == NULL)
    {
        __ti_dsp_heap[idx].free = ptr;
        ptr->size_ptr = NULL;
        return;
    }

    /*-----------------------------------------------------------------------*/
    /* SCAN THROUGH LIST, LOOKING FOR A LARGER PACKET.			     */
    /*-----------------------------------------------------------------------*/
    while (current && current->packet_size < ptr->packet_size)
    {
	last	= current;
	current = current->size_ptr;
    }

    /*-----------------------------------------------------------------------*/
    /* LINK THE NEW PACKET INTO THE LIST. THERE ARE THREE CASES :	     */
    /*	 THE NEW POINTER WILL EITHER BE THE FIRST, THE LAST, OR IN THE	     */
    /*	 MIDDLE SOMEWHERE.						     */
    /*-----------------------------------------------------------------------*/
    if (current == NULL) 	        /* PTR WILL BE LAST IN LIST          */
    {
        last->size_ptr = ptr;
        ptr->size_ptr  = NULL;
    }
    else if (last == NULL)	        /* PTR WILL BE FIRST IN THE LIST     */
    {
        ptr->size_ptr               = __ti_dsp_heap[idx].free;
        __ti_dsp_heap[idx].free = ptr;
    }
    else			        /* PTR IS IN THE MIDDLE OF THE LIST  */
    {
        ptr->size_ptr  = current;
        last->size_ptr = ptr;
    }
}

/*****************************************************************************/
/*									     */
/* MREMOVE - REMOVE AN ITEM FROM THE FREE LIST. 			     */
/*									     */
/* NOTE: All calls to mremove() should occur inside a critical section       */
/*****************************************************************************/
static void mremove(ti_omp_dsp_heap_idx idx, PACKET *ptr)
{
    PACKET *current = __ti_dsp_heap[idx].free;
    PACKET *last    = NULL;

    /*-----------------------------------------------------------------------*/
    /* SCAN THROUGH LIST, LOOKING FOR PACKET TO REMOVE                       */
    /*-----------------------------------------------------------------------*/
    while (current && current != ptr)
    {
	last	= current;
	current = current->size_ptr;
    }

    /*-----------------------------------------------------------------------*/
    /* REMOVE THE PACKET FROM THE LIST.                                      */
    /*-----------------------------------------------------------------------*/
    if  (current == NULL) 
        __ti_dsp_heap[idx].free = NULL;           /* NOT FOUND   */
    else if (last    == NULL) 
        __ti_dsp_heap[idx].free  = ptr->size_ptr; /* 1ST IN LIST */
    else                      
        last->size_ptr = ptr->size_ptr;               /* MID OF LIST */
}

/*****************************************************************************/
/*									     */
/*  Initialize the heap at a given index. Must be called before any calls    */
/*  to heap memory management functions such as __ti_dsp_[malloc|free]   */
/*									     */
/*****************************************************************************/
_CODE_ACCESS void __ti_dsp_heap_init(ti_omp_dsp_heap_idx idx, char *ptr, 
                                         int size)
{
    acquire_dsp_heap_lock();
    tomp_dsp_heap_init(idx, ptr, size);
    release_dsp_heap_lock();
}

/*****************************************************************************/
/*									     */
/*  MINIT - This function can be called by the user to completely reset the  */
/*	    memory management system.					     */
/*									     */
/*****************************************************************************/
_CODE_ACCESS void tomp_dsp_heap_init(ti_omp_dsp_heap_idx idx, char *ptr, 
                                         int size)
{
    /*-----------------------------------------------------------------------*/
    /* TO INITIALIZE THE MEMORY SYSTEM, SET UP THE FREE LIST TO POINT TO     */
    /* THE ENTIRE HEAP, AND INITIALIZE HEAP TO A SINGLE EMPTY PACKET.        */
    /*-----------------------------------------------------------------------*/
    __ti_dsp_heap[idx].free       = (PACKET *)ptr;
    __ti_dsp_heap[idx].sys_memory = (PACKET *)ptr;
    __ti_dsp_heap[idx].size       = size;

    PACKET *free = __ti_dsp_heap[idx].free;
    free->packet_size = size - BLOCK_OVERHEAD;
    free->size_ptr    = NULL;
}

/*****************************************************************************/
/*									     */
/*  MALLOC - Allocate a packet of a given size, and return a pointer to it.  */
/*	     This function only allocates in multiples of MIN_BLOCK bytes.   */
/*									     */
/*****************************************************************************/
_CODE_ACCESS void *__ti_dsp_malloc(ti_omp_dsp_heap_idx idx, int size)
{
    PACKET       *current;
    unsigned int  newsize = (size + BLOCK_MASK) & ~BLOCK_MASK;
    unsigned int  oldsize;
    PACKET*       sys_memory  = __ti_dsp_heap[idx].sys_memory;
    size_t        memory_size = __ti_dsp_heap[idx].size;

    if (size <= 0) return 0;

    /*-----------------------------------------------------------------------*/
    /* Critical region to protect accesses to packet free list that are made */
    /* by minsert() and/or mremove()                                         */
    /*-----------------------------------------------------------------------*/
    acquire_lock_and_inv(sys_memory, memory_size);

    current = __ti_dsp_heap[idx].free;

    /*-----------------------------------------------------------------------*/
    /* SCAN THROUGH FREE LIST FOR PACKET LARGE ENOUGH TO CONTAIN PACKET      */
    /*-----------------------------------------------------------------------*/
    while (current && current->packet_size < newsize)
       current = current->size_ptr;

    if (!current) { inv_and_release_lock(sys_memory, memory_size); return 0; }
    
    oldsize = current->packet_size;	    /* REMEMBER OLD SIZE	     */
    mremove(idx, current);                  /* REMOVE PACKET FROM FREE LIST  */

    /*-----------------------------------------------------------------------*/
    /* IF PACKET IS LARGER THAN NEEDED, FREE EXTRA SPACE AT END	             */
    /* BY INSERTING REMAINING SPACE INTO FREE LIST.			     */
    /*-----------------------------------------------------------------------*/
    if (oldsize - newsize >= (MIN_BLOCK + BLOCK_OVERHEAD))
    {
       PACKET *next = 
	       (PACKET *) ((char *) current + BLOCK_OVERHEAD + newsize);
 
       next->packet_size    = oldsize - newsize - BLOCK_OVERHEAD;
       minsert(idx, next);
       current->packet_size = newsize;
    }

   current->packet_size |= BLOCK_USED;

   inv_and_release_lock(sys_memory, memory_size);

   return (char *)current + BLOCK_OVERHEAD;
}

/*****************************************************************************/
/*									     */
/*  CALLOC - Allocate a packet of a given size, set the data in the packet   */
/*	     to nulls, and return a pointer to it.			     */
/*									     */
/*****************************************************************************/
_CODE_ACCESS void *__ti_dsp_calloc(ti_omp_dsp_heap_idx idx, int num, 
                                       int size)
{
    size_t      i	 = size * num;
    LARGE_TYPE *current = __ti_dsp_malloc(idx, i);
    char       *save    = (char *) current;

    if (current == 0) return 0;

    i = ((i + BLOCK_MASK) & ~BLOCK_MASK) / sizeof(LARGE_TYPE);

    while (i--) *current++ = 0;

    return save;
}

/*****************************************************************************/
/*									     */
/*  REALLOC - Reallocate a packet to a new size.			     */
/*									     */
/*****************************************************************************/
_CODE_ACCESS void *__ti_dsp_realloc(ti_omp_dsp_heap_idx idx, void *packet, 
                                        int size)
{
    char *pptr    = (char *) packet - BLOCK_OVERHEAD;
    int   newsize = (size + BLOCK_MASK) & ~BLOCK_MASK;
    int   oldsize;

    PACKET*  sys_memory  = __ti_dsp_heap[idx].sys_memory;
    size_t memory_size = __ti_dsp_heap[idx].size;

    if (packet == 0)  return __ti_dsp_malloc(idx, size);
    if (size   == 0)  { __ti_dsp_free(idx, packet); return 0; }

    /*-----------------------------------------------------------------------*/
    /* Critical region to protect accesses to packet free list that are made */
    /* by minsert() and/or mremove()                                         */
    /*-----------------------------------------------------------------------*/
    acquire_lock_and_inv(sys_memory, memory_size);

    oldsize = ((PACKET *)pptr)->packet_size;

    if (!(oldsize & BLOCK_USED))  
       { inv_and_release_lock(sys_memory, memory_size); return 0; }

    if (newsize == --oldsize)
       { inv_and_release_lock(sys_memory, memory_size); return packet; }

    /*-----------------------------------------------------------------------*/
    /* IF NEW SIZE IS LESS THAN CURRENT SIZE, TRUNCATE PACKET AND RETURN END */
    /* TO FREE LIST		                                             */
    /*-----------------------------------------------------------------------*/
    if (newsize < oldsize)
    {
       if ((oldsize - newsize) >= (MIN_BLOCK + BLOCK_OVERHEAD)) 
       {
          ((PACKET *)pptr)->packet_size = newsize | BLOCK_USED;

          oldsize -= newsize + BLOCK_OVERHEAD;
          pptr    += newsize + BLOCK_OVERHEAD;
          ((PACKET *)pptr)->packet_size = oldsize | BLOCK_USED;
          __ti_dsp_free(idx, pptr + BLOCK_OVERHEAD);
       }
       inv_and_release_lock(sys_memory, memory_size);
       return packet;
    }

    /*-----------------------------------------------------------------------*/
    /* IF NEW SIZE IS BIGGER THAN CURRENT PACKET,		             */
    /*	1) CHECK NEXT PACKET IN LIST, SEE IF PACKET CAN BE EXPANDED          */
    /*	2) IF NOT, MOVE PACKET TO NEW LOCATION. 		             */
    /*-----------------------------------------------------------------------*/
    else
    {
	PACKET *next = (PACKET *)(pptr + oldsize + BLOCK_OVERHEAD);
	int     temp;
        char* heap_mem = (char *)packet;

	if (((char *)next < &heap_mem[memory_size - BLOCK_OVERHEAD]) &&
           (!(next->packet_size & BLOCK_USED))                           &&
           ((temp = oldsize +next->packet_size +BLOCK_OVERHEAD -newsize) >= 0))
	{
	    mremove(idx, next);
	    if (temp < MIN_BLOCK + BLOCK_OVERHEAD)
	    {
	       ((PACKET *)pptr)->packet_size = newsize + temp | BLOCK_USED;
               inv_and_release_lock(sys_memory, memory_size);
	       return packet;
	    }

	    ((PACKET *)pptr)->packet_size = newsize | BLOCK_USED;
	    pptr += newsize + BLOCK_OVERHEAD;
	    ((PACKET *)pptr)->packet_size = temp - BLOCK_OVERHEAD;
	    minsert(idx, (PACKET *)pptr);
            inv_and_release_lock(sys_memory, memory_size);
	    return packet;
	}
	else
	{
            /*---------------------------------------------------------------*/
	    /* ALLOCATE NEW PACKET AND MOVE DATA INTO IT. 	             */
            /*---------------------------------------------------------------*/
            inv_and_release_lock(sys_memory, memory_size);
	    char *new = __ti_dsp_malloc(idx, size);
	    if (new != 0) 
	    {
	       memcpy(new, packet, oldsize);
	       __ti_dsp_free(idx, packet);
	    }
	    return new;
	}
    }
}

/*****************************************************************************/
/*									     */
/*  FREE - Return a packet allocated by malloc to free memory pool.	     */
/*	   Return 0 if successful, -1 if not successful.		     */
/*									     */
/*****************************************************************************/
_CODE_ACCESS void __ti_dsp_free(ti_omp_dsp_heap_idx idx, void *packet)
{
    char   *ptr = (char *)packet;
    PACKET *last;	      /* POINT TO PREVIOUS PACKET            */
    PACKET *current;	      /* POINTER TO THIS PACKET              */
    PACKET *next;	      /* POINTER TO NEXT PACKET              */

    if (ptr == NULL) return;

    PACKET*  sys_memory  = __ti_dsp_heap[idx].sys_memory;
    size_t memory_size = __ti_dsp_heap[idx].size;
    char*  heap_mem    = (char *)packet;

    last = next = NULL;		      /* INITIALIZE POINTERS                 */
    ptr -= BLOCK_OVERHEAD;	      /* ADJUST POINT TO BEGINNING OF PACKET */

    /*-----------------------------------------------------------------------*/
    /* Critical region to protect accesses to packet free list that are made */
    /* by minsert() and/or mremove() (see note #4 in file header comment).   */
    /*-----------------------------------------------------------------------*/
    acquire_lock_and_inv(sys_memory, memory_size);

    current = sys_memory;

    /*-----------------------------------------------------------------------*/
    /* SEARCH FOR THE POINTER IN THE PACKET POINTED TO			     */
    /*-----------------------------------------------------------------------*/
    while (current < (PACKET *) ptr)
    {
        last    = current;
        current = (PACKET *)((char *)current + 
		  (current->packet_size & ~BLOCK_USED) + BLOCK_OVERHEAD);
    }

    /*-----------------------------------------------------------------------*/
    /* CHECK FOR POINTER OR PACKET ERRORS.				     */
    /*-----------------------------------------------------------------------*/
    if ((current != (PACKET *) ptr) || (!(current->packet_size & BLOCK_USED)))
       { inv_and_release_lock(sys_memory, memory_size); return; }

    current->packet_size &= ~BLOCK_USED;   /* MARK PACKET AS FREE */

    /*-----------------------------------------------------------------------*/
    /* GET POINTER TO NEXT PACKET IN MEMORY, IF ANY.			     */
    /*-----------------------------------------------------------------------*/
    next = (PACKET *)((char *)current + BLOCK_OVERHEAD + current->packet_size);
    if (next > (PACKET *) &heap_mem[memory_size-BLOCK_OVERHEAD]) 
	next = NULL;

    if (last && (last->packet_size & BLOCK_USED)) last = NULL;
    if (next && (next->packet_size & BLOCK_USED)) next = NULL;

    /*-----------------------------------------------------------------------*/
    /* ATTEMPT TO COLLESCE THE THREE PACKETS (PREVIOUS, CURRENT, NEXT)	     */
    /*-----------------------------------------------------------------------*/
    if (last && next)
    {
	mremove(idx, last);
	mremove(idx, next);
	last->packet_size += current->packet_size + next->packet_size + 
			     BLOCK_OVERHEAD + BLOCK_OVERHEAD;
	minsert(idx, last);
        inv_and_release_lock(sys_memory, memory_size);
	return;
    }

    /*-----------------------------------------------------------------------*/
    /* ATTEMPT TO COLLESCE THE CURRENT WITH LAST PACKET. (LAST, CURRENT)     */
    /*-----------------------------------------------------------------------*/
    if (last)
    {
        mremove(idx, last);
        last->packet_size += current->packet_size + BLOCK_OVERHEAD;
        minsert(idx, last);
        inv_and_release_lock(sys_memory, memory_size);
        return;
    }

    /*-----------------------------------------------------------------------*/
    /* ATTEMPT TO COLLESCE THE CURRENT WITH NEXT PACKET. (CURRENT, NEXT)     */
    /*-----------------------------------------------------------------------*/
    if (next)
    {
        mremove(idx, next);
        current->packet_size += next->packet_size + BLOCK_OVERHEAD;
        minsert(idx, current);
        inv_and_release_lock(sys_memory, memory_size);
        return;
    }

    /*-----------------------------------------------------------------------*/
    /* NO COLLESCENCE POSSIBLE, JUST INSERT THIS PACKET INTO LIST	     */
    /*-----------------------------------------------------------------------*/
    minsert(idx, current);
    inv_and_release_lock(sys_memory, memory_size);
}

/*****************************************************************************/
/*                                                                           */
/*  MEMALIGN - Allocate a packet of a given size, and on a given boundary.   */
/*                                                                           */
/*****************************************************************************/
_CODE_ACCESS void *__ti_dsp_memalign(ti_omp_dsp_heap_idx idx, 
                                         int alignment, int size)
{
    PACKET *aln_packet;
    PACKET *current;
    size_t  newsize  = (size + BLOCK_MASK) & ~BLOCK_MASK;
    size_t  aln_mask = alignment - 1;
    int     leftover = -1;
    char   *aln_start;
    char   *un_aln_start;
    PACKET*   sys_memory  = __ti_dsp_heap[idx].sys_memory;
    size_t  memory_size = __ti_dsp_heap[idx].size;

    if (size <= 0) return 0;

    /*-----------------------------------------------------------------------*/
    /* Critical region to protect accesses to packet free list that are made */
    /* by minsert() and/or mremove()                                         */
    /*-----------------------------------------------------------------------*/
    acquire_lock_and_inv(sys_memory, memory_size);

    current = __ti_dsp_heap[idx].free;

    /*--------------------------------------------------------------------*/
    /* IF ALIGNMENT IS NOT A POWER OF TWO OR IS LESS THAN THE DEFAULT     */
    /* ALIGNMENT OF MALLOC, THEN SIMPLY RETURN WHAT MALLOC RETURNS.       */
    /*--------------------------------------------------------------------*/
    if (alignment <= BLOCK_OVERHEAD || (alignment & (alignment-1))) 
       { release_dsp_heap_lock(); return __ti_dsp_malloc(idx, size); }

    /*-----------------------------------------------------------------------*/
    /* SCAN THROUGH FREE LIST FOR PACKET LARGE ENOUGH TO CONTAIN ALIGNED     */
    /* PACKET                                                                */
    /*-----------------------------------------------------------------------*/
    for ( ; current ; current = current->size_ptr)
    {
       un_aln_start = (char *) current + BLOCK_OVERHEAD;
       aln_start   = (char *) (((size_t) un_aln_start + aln_mask) & ~aln_mask);
       leftover    = un_aln_start + current->packet_size - aln_start - newsize;

       /*--------------------------------------------------------------------*/
       /* MAKE SURE THAT THE PRE BLOCK SPACE IS LARGE ENOUGH TO BE A BLOCK   */
       /* OF ITS OWN.                                                        */
       /*--------------------------------------------------------------------*/
       for ( ; (char *)current+sizeof(PACKET) > aln_start-BLOCK_OVERHEAD ;
	       aln_start += alignment, leftover -= alignment);

       if (leftover >= 0) break;
    }

    if (!current) 
       { inv_and_release_lock(sys_memory, memory_size); return 0; }

    /*-----------------------------------------------------------------------*/
    /* SETUP NEW PACKET FOR ALIGNED MEMORY.                                  */
    /*-----------------------------------------------------------------------*/
    mremove(idx, current);
    aln_packet              = (PACKET *) (aln_start - BLOCK_OVERHEAD);
    aln_packet->packet_size = newsize | BLOCK_USED;

    /*-----------------------------------------------------------------------*/
    /* HANDLE THE FREE SPACE BEFORE THE ALIGNED BLOCK.  IF THE ORIGINAL      */
    /* BLOCK WAS ALIGNED, THERE WON'T BE FREE SPACE BEFORE THE ALIGNED BLOCK.*/
    /*-----------------------------------------------------------------------*/
    if (aln_start != un_aln_start) 
    {
	current->packet_size = (char *)aln_packet - un_aln_start;
	minsert(idx, current);
    }

    /*-----------------------------------------------------------------------*/
    /* HANDLE THE FREE SPACE AFTER THE ALIGNED BLOCK. IF IT IS LARGE ENOUGH  */
    /* TO BE A BLOCK OF ITS OWN, THEN MAKE IT ONE, OTHERWISE ADD THE         */
    /* LEFTOVER SIZE TO THE ALIGNED BLOCK.                                   */
    /*-----------------------------------------------------------------------*/
    if (leftover >= BLOCK_OVERHEAD + MIN_BLOCK)
    {
       PACKET *next = (PACKET *) (aln_start + newsize);
       next->packet_size     = leftover - BLOCK_OVERHEAD;
       minsert(idx, next);
    }
    else aln_packet->packet_size += leftover;

    inv_and_release_lock(sys_memory, memory_size);
    return aln_start;
}

/*****************************************************************************/
/*                                                                           */
/*  Dynamic Memory Management API for L2                                     */
/*                                                                           */
/*****************************************************************************/

typedef struct _tomp_DspLocalHeap
{
    char*   free;            /* Points to the free list */
    size_t  remaining_bytes;
} tomp_DspLocalHeap;

#pragma DATA_SECTION (dsp_local_heap, ".tomp_gvMem")
static tomp_DspLocalHeap dsp_local_heap;


/**
 * Heap Initialization function.
 * ptr must be aligned to a 64b boundary
 */
far void __heap_init_l2(void *ptr, size_t size)
{
    dsp_local_heap.free             = ptr;
    dsp_local_heap.remaining_bytes  = size;
}


/**
 * Malloc. Return addresses are aligned on 64bit boundaries
 */
far void *__malloc_l2(size_t size)
{
    if (!dsp_local_heap.free)
        return NULL;

    size_t newsize = (size + BLOCK_MASK) & ~BLOCK_MASK;

    if (dsp_local_heap.remaining_bytes < newsize)
        return NULL;

    void *ptr = dsp_local_heap.free;

    dsp_local_heap.free            += newsize;
    dsp_local_heap.remaining_bytes -= newsize;

    return ptr;
}
