/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-B21
 */

/*
 * ======== GENERATED SECTIONS ========
 *     
 *     PROLOGUE
 *     INCLUDES
 *     
 *     INTERNAL DEFINITIONS
 *     MODULE-WIDE CONFIGS
 *     FUNCTION DECLARATIONS
 *     SYSTEM FUNCTIONS
 *     
 *     EPILOGUE
 *     STATE STRUCTURES
 *     PREFIX ALIASES
 */


/*
 * ======== PROLOGUE ========
 */

#ifndef ti_runtime_ompbios_OpenMP__include
#define ti_runtime_ompbios_OpenMP__include

#ifndef __nested__
#define __nested__
#define ti_runtime_ompbios_OpenMP__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_runtime_ompbios_OpenMP___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <ti/runtime/ompbios/package/package.defs.h>

#include <xdc/runtime/Types.h>
#include <xdc/runtime/IModule.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */


/*
 * ======== INTERNAL DEFINITIONS ========
 */


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_runtime_ompbios_OpenMP_Module__diagsEnabled;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_Module__diagsEnabled ti_runtime_ompbios_OpenMP_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_runtime_ompbios_OpenMP_Module__diagsIncluded;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_Module__diagsIncluded ti_runtime_ompbios_OpenMP_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16 *CT__ti_runtime_ompbios_OpenMP_Module__diagsMask;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_Module__diagsMask ti_runtime_ompbios_OpenMP_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_runtime_ompbios_OpenMP_Module__gateObj;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_Module__gateObj ti_runtime_ompbios_OpenMP_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_runtime_ompbios_OpenMP_Module__gatePrms;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_Module__gatePrms ti_runtime_ompbios_OpenMP_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_runtime_ompbios_OpenMP_Module__id;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_Module__id ti_runtime_ompbios_OpenMP_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_runtime_ompbios_OpenMP_Module__loggerDefined;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_Module__loggerDefined ti_runtime_ompbios_OpenMP_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_runtime_ompbios_OpenMP_Module__loggerObj;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_Module__loggerObj ti_runtime_ompbios_OpenMP_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_runtime_ompbios_OpenMP_Module__loggerFxn0;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_Module__loggerFxn0 ti_runtime_ompbios_OpenMP_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_runtime_ompbios_OpenMP_Module__loggerFxn1;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_Module__loggerFxn1 ti_runtime_ompbios_OpenMP_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_runtime_ompbios_OpenMP_Module__loggerFxn2;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_Module__loggerFxn2 ti_runtime_ompbios_OpenMP_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_runtime_ompbios_OpenMP_Module__loggerFxn4;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_Module__loggerFxn4 ti_runtime_ompbios_OpenMP_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_runtime_ompbios_OpenMP_Module__loggerFxn8;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_Module__loggerFxn8 ti_runtime_ompbios_OpenMP_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_runtime_ompbios_OpenMP_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_Module__startupDoneFxn ti_runtime_ompbios_OpenMP_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_runtime_ompbios_OpenMP_Object__count;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_Object__count ti_runtime_ompbios_OpenMP_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_runtime_ompbios_OpenMP_Object__heap;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_Object__heap ti_runtime_ompbios_OpenMP_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_runtime_ompbios_OpenMP_Object__sizeof;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_Object__sizeof ti_runtime_ompbios_OpenMP_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_runtime_ompbios_OpenMP_Object__table;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_Object__table ti_runtime_ompbios_OpenMP_Object__table__C;

/* numCores */
#ifdef ti_runtime_ompbios_OpenMP_numCores__D
#define ti_runtime_ompbios_OpenMP_numCores (ti_runtime_ompbios_OpenMP_numCores__D)
#else
#define ti_runtime_ompbios_OpenMP_numCores (ti_runtime_ompbios_OpenMP_numCores__C)
typedef xdc_Int32 CT__ti_runtime_ompbios_OpenMP_numCores;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_numCores ti_runtime_ompbios_OpenMP_numCores__C;
#endif

/* masterCoreIdx */
#ifdef ti_runtime_ompbios_OpenMP_masterCoreIdx__D
#define ti_runtime_ompbios_OpenMP_masterCoreIdx (ti_runtime_ompbios_OpenMP_masterCoreIdx__D)
#else
#define ti_runtime_ompbios_OpenMP_masterCoreIdx (ti_runtime_ompbios_OpenMP_masterCoreIdx__C)
typedef xdc_Int32 CT__ti_runtime_ompbios_OpenMP_masterCoreIdx;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_masterCoreIdx ti_runtime_ompbios_OpenMP_masterCoreIdx__C;
#endif

/* clockFreq */
#ifdef ti_runtime_ompbios_OpenMP_clockFreq__D
#define ti_runtime_ompbios_OpenMP_clockFreq (ti_runtime_ompbios_OpenMP_clockFreq__D)
#else
#define ti_runtime_ompbios_OpenMP_clockFreq (ti_runtime_ompbios_OpenMP_clockFreq__C)
typedef xdc_Int32 CT__ti_runtime_ompbios_OpenMP_clockFreq;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_clockFreq ti_runtime_ompbios_OpenMP_clockFreq__C;
#endif

/* hasMsmc */
#ifdef ti_runtime_ompbios_OpenMP_hasMsmc__D
#define ti_runtime_ompbios_OpenMP_hasMsmc (ti_runtime_ompbios_OpenMP_hasMsmc__D)
#else
#define ti_runtime_ompbios_OpenMP_hasMsmc (ti_runtime_ompbios_OpenMP_hasMsmc__C)
typedef xdc_Bool CT__ti_runtime_ompbios_OpenMP_hasMsmc;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_hasMsmc ti_runtime_ompbios_OpenMP_hasMsmc__C;
#endif

/* msmcBase */
#ifdef ti_runtime_ompbios_OpenMP_msmcBase__D
#define ti_runtime_ompbios_OpenMP_msmcBase (ti_runtime_ompbios_OpenMP_msmcBase__D)
#else
#define ti_runtime_ompbios_OpenMP_msmcBase (ti_runtime_ompbios_OpenMP_msmcBase__C)
typedef xdc_UInt32 CT__ti_runtime_ompbios_OpenMP_msmcBase;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_msmcBase ti_runtime_ompbios_OpenMP_msmcBase__C;
#endif

/* msmcSize */
#ifdef ti_runtime_ompbios_OpenMP_msmcSize__D
#define ti_runtime_ompbios_OpenMP_msmcSize (ti_runtime_ompbios_OpenMP_msmcSize__D)
#else
#define ti_runtime_ompbios_OpenMP_msmcSize (ti_runtime_ompbios_OpenMP_msmcSize__C)
typedef xdc_UInt32 CT__ti_runtime_ompbios_OpenMP_msmcSize;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_msmcSize ti_runtime_ompbios_OpenMP_msmcSize__C;
#endif

/* msmcNoCacheVirtualBase */
#ifdef ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualBase__D
#define ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualBase (ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualBase__D)
#else
#define ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualBase (ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualBase__C)
typedef xdc_UInt32 CT__ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualBase;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualBase ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualBase__C;
#endif

/* msmcNoCacheVirtualSize */
#ifdef ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualSize__D
#define ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualSize (ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualSize__D)
#else
#define ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualSize (ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualSize__C)
typedef xdc_UInt32 CT__ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualSize;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualSize ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualSize__C;
#endif

/* msmcNoCachePhysicalBase */
#ifdef ti_runtime_ompbios_OpenMP_msmcNoCachePhysicalBase__D
#define ti_runtime_ompbios_OpenMP_msmcNoCachePhysicalBase (ti_runtime_ompbios_OpenMP_msmcNoCachePhysicalBase__D)
#else
#define ti_runtime_ompbios_OpenMP_msmcNoCachePhysicalBase (ti_runtime_ompbios_OpenMP_msmcNoCachePhysicalBase__C)
typedef xdc_UInt32 CT__ti_runtime_ompbios_OpenMP_msmcNoCachePhysicalBase;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_msmcNoCachePhysicalBase ti_runtime_ompbios_OpenMP_msmcNoCachePhysicalBase__C;
#endif

/* ddrBase */
#ifdef ti_runtime_ompbios_OpenMP_ddrBase__D
#define ti_runtime_ompbios_OpenMP_ddrBase (ti_runtime_ompbios_OpenMP_ddrBase__D)
#else
#define ti_runtime_ompbios_OpenMP_ddrBase (ti_runtime_ompbios_OpenMP_ddrBase__C)
typedef xdc_UInt32 CT__ti_runtime_ompbios_OpenMP_ddrBase;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_ddrBase ti_runtime_ompbios_OpenMP_ddrBase__C;
#endif

/* ddrSize */
#ifdef ti_runtime_ompbios_OpenMP_ddrSize__D
#define ti_runtime_ompbios_OpenMP_ddrSize (ti_runtime_ompbios_OpenMP_ddrSize__D)
#else
#define ti_runtime_ompbios_OpenMP_ddrSize (ti_runtime_ompbios_OpenMP_ddrSize__C)
typedef xdc_UInt32 CT__ti_runtime_ompbios_OpenMP_ddrSize;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_ddrSize ti_runtime_ompbios_OpenMP_ddrSize__C;
#endif

/* ddrNoCacheBase */
#ifdef ti_runtime_ompbios_OpenMP_ddrNoCacheBase__D
#define ti_runtime_ompbios_OpenMP_ddrNoCacheBase (ti_runtime_ompbios_OpenMP_ddrNoCacheBase__D)
#else
#define ti_runtime_ompbios_OpenMP_ddrNoCacheBase (ti_runtime_ompbios_OpenMP_ddrNoCacheBase__C)
typedef xdc_UInt32 CT__ti_runtime_ompbios_OpenMP_ddrNoCacheBase;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_ddrNoCacheBase ti_runtime_ompbios_OpenMP_ddrNoCacheBase__C;
#endif

/* ddrNoCacheSize */
#ifdef ti_runtime_ompbios_OpenMP_ddrNoCacheSize__D
#define ti_runtime_ompbios_OpenMP_ddrNoCacheSize (ti_runtime_ompbios_OpenMP_ddrNoCacheSize__D)
#else
#define ti_runtime_ompbios_OpenMP_ddrNoCacheSize (ti_runtime_ompbios_OpenMP_ddrNoCacheSize__C)
typedef xdc_UInt32 CT__ti_runtime_ompbios_OpenMP_ddrNoCacheSize;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_ddrNoCacheSize ti_runtime_ompbios_OpenMP_ddrNoCacheSize__C;
#endif

/* mpaxForMsmcMapping */
#ifdef ti_runtime_ompbios_OpenMP_mpaxForMsmcMapping__D
#define ti_runtime_ompbios_OpenMP_mpaxForMsmcMapping (ti_runtime_ompbios_OpenMP_mpaxForMsmcMapping__D)
#else
#define ti_runtime_ompbios_OpenMP_mpaxForMsmcMapping (ti_runtime_ompbios_OpenMP_mpaxForMsmcMapping__C)
typedef xdc_UInt32 CT__ti_runtime_ompbios_OpenMP_mpaxForMsmcMapping;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_mpaxForMsmcMapping ti_runtime_ompbios_OpenMP_mpaxForMsmcMapping__C;
#endif

/* hwSemBaseIdx */
#ifdef ti_runtime_ompbios_OpenMP_hwSemBaseIdx__D
#define ti_runtime_ompbios_OpenMP_hwSemBaseIdx (ti_runtime_ompbios_OpenMP_hwSemBaseIdx__D)
#else
#define ti_runtime_ompbios_OpenMP_hwSemBaseIdx (ti_runtime_ompbios_OpenMP_hwSemBaseIdx__C)
typedef xdc_Int32 CT__ti_runtime_ompbios_OpenMP_hwSemBaseIdx;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_hwSemBaseIdx ti_runtime_ompbios_OpenMP_hwSemBaseIdx__C;
#endif

/* hwSemCount */
#ifdef ti_runtime_ompbios_OpenMP_hwSemCount__D
#define ti_runtime_ompbios_OpenMP_hwSemCount (ti_runtime_ompbios_OpenMP_hwSemCount__D)
#else
#define ti_runtime_ompbios_OpenMP_hwSemCount (ti_runtime_ompbios_OpenMP_hwSemCount__C)
typedef xdc_Int32 CT__ti_runtime_ompbios_OpenMP_hwSemCount;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_hwSemCount ti_runtime_ompbios_OpenMP_hwSemCount__C;
#endif

/* qmssInit */
#ifdef ti_runtime_ompbios_OpenMP_qmssInit__D
#define ti_runtime_ompbios_OpenMP_qmssInit (ti_runtime_ompbios_OpenMP_qmssInit__D)
#else
#define ti_runtime_ompbios_OpenMP_qmssInit (ti_runtime_ompbios_OpenMP_qmssInit__C)
typedef xdc_Bool CT__ti_runtime_ompbios_OpenMP_qmssInit;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_qmssInit ti_runtime_ompbios_OpenMP_qmssInit__C;
#endif

/* qmssMemRegionIndex */
#ifdef ti_runtime_ompbios_OpenMP_qmssMemRegionIndex__D
#define ti_runtime_ompbios_OpenMP_qmssMemRegionIndex (ti_runtime_ompbios_OpenMP_qmssMemRegionIndex__D)
#else
#define ti_runtime_ompbios_OpenMP_qmssMemRegionIndex (ti_runtime_ompbios_OpenMP_qmssMemRegionIndex__C)
typedef xdc_Int32 CT__ti_runtime_ompbios_OpenMP_qmssMemRegionIndex;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_qmssMemRegionIndex ti_runtime_ompbios_OpenMP_qmssMemRegionIndex__C;
#endif

/* qmssFirstDescIdxInLinkingRam */
#ifdef ti_runtime_ompbios_OpenMP_qmssFirstDescIdxInLinkingRam__D
#define ti_runtime_ompbios_OpenMP_qmssFirstDescIdxInLinkingRam (ti_runtime_ompbios_OpenMP_qmssFirstDescIdxInLinkingRam__D)
#else
#define ti_runtime_ompbios_OpenMP_qmssFirstDescIdxInLinkingRam (ti_runtime_ompbios_OpenMP_qmssFirstDescIdxInLinkingRam__C)
typedef xdc_UInt32 CT__ti_runtime_ompbios_OpenMP_qmssFirstDescIdxInLinkingRam;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_qmssFirstDescIdxInLinkingRam ti_runtime_ompbios_OpenMP_qmssFirstDescIdxInLinkingRam__C;
#endif

/* qmssHwQueueBaseIdx */
#ifdef ti_runtime_ompbios_OpenMP_qmssHwQueueBaseIdx__D
#define ti_runtime_ompbios_OpenMP_qmssHwQueueBaseIdx (ti_runtime_ompbios_OpenMP_qmssHwQueueBaseIdx__D)
#else
#define ti_runtime_ompbios_OpenMP_qmssHwQueueBaseIdx (ti_runtime_ompbios_OpenMP_qmssHwQueueBaseIdx__C)
typedef xdc_Int32 CT__ti_runtime_ompbios_OpenMP_qmssHwQueueBaseIdx;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_qmssHwQueueBaseIdx ti_runtime_ompbios_OpenMP_qmssHwQueueBaseIdx__C;
#endif

/* useIpcSharedHeap */
#ifdef ti_runtime_ompbios_OpenMP_useIpcSharedHeap__D
#define ti_runtime_ompbios_OpenMP_useIpcSharedHeap (ti_runtime_ompbios_OpenMP_useIpcSharedHeap__D)
#else
#define ti_runtime_ompbios_OpenMP_useIpcSharedHeap (ti_runtime_ompbios_OpenMP_useIpcSharedHeap__C)
typedef xdc_Bool CT__ti_runtime_ompbios_OpenMP_useIpcSharedHeap;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_useIpcSharedHeap ti_runtime_ompbios_OpenMP_useIpcSharedHeap__C;
#endif

/* allocateLocalHeap */
#ifdef ti_runtime_ompbios_OpenMP_allocateLocalHeap__D
#define ti_runtime_ompbios_OpenMP_allocateLocalHeap (ti_runtime_ompbios_OpenMP_allocateLocalHeap__D)
#else
#define ti_runtime_ompbios_OpenMP_allocateLocalHeap (ti_runtime_ompbios_OpenMP_allocateLocalHeap__C)
typedef xdc_Bool CT__ti_runtime_ompbios_OpenMP_allocateLocalHeap;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_allocateLocalHeap ti_runtime_ompbios_OpenMP_allocateLocalHeap__C;
#endif

/* allocateLocalHeapSize */
#ifdef ti_runtime_ompbios_OpenMP_allocateLocalHeapSize__D
#define ti_runtime_ompbios_OpenMP_allocateLocalHeapSize (ti_runtime_ompbios_OpenMP_allocateLocalHeapSize__D)
#else
#define ti_runtime_ompbios_OpenMP_allocateLocalHeapSize (ti_runtime_ompbios_OpenMP_allocateLocalHeapSize__C)
typedef xdc_UInt32 CT__ti_runtime_ompbios_OpenMP_allocateLocalHeapSize;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_allocateLocalHeapSize ti_runtime_ompbios_OpenMP_allocateLocalHeapSize__C;
#endif

/* allocateSharedHeap */
#ifdef ti_runtime_ompbios_OpenMP_allocateSharedHeap__D
#define ti_runtime_ompbios_OpenMP_allocateSharedHeap (ti_runtime_ompbios_OpenMP_allocateSharedHeap__D)
#else
#define ti_runtime_ompbios_OpenMP_allocateSharedHeap (ti_runtime_ompbios_OpenMP_allocateSharedHeap__C)
typedef xdc_Bool CT__ti_runtime_ompbios_OpenMP_allocateSharedHeap;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_allocateSharedHeap ti_runtime_ompbios_OpenMP_allocateSharedHeap__C;
#endif

/* allocateSharedHeapSize */
#ifdef ti_runtime_ompbios_OpenMP_allocateSharedHeapSize__D
#define ti_runtime_ompbios_OpenMP_allocateSharedHeapSize (ti_runtime_ompbios_OpenMP_allocateSharedHeapSize__D)
#else
#define ti_runtime_ompbios_OpenMP_allocateSharedHeapSize (ti_runtime_ompbios_OpenMP_allocateSharedHeapSize__C)
typedef xdc_UInt32 CT__ti_runtime_ompbios_OpenMP_allocateSharedHeapSize;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_allocateSharedHeapSize ti_runtime_ompbios_OpenMP_allocateSharedHeapSize__C;
#endif

/* allocateStackFromHeap */
#ifdef ti_runtime_ompbios_OpenMP_allocateStackFromHeap__D
#define ti_runtime_ompbios_OpenMP_allocateStackFromHeap (ti_runtime_ompbios_OpenMP_allocateStackFromHeap__D)
#else
#define ti_runtime_ompbios_OpenMP_allocateStackFromHeap (ti_runtime_ompbios_OpenMP_allocateStackFromHeap__C)
typedef xdc_Bool CT__ti_runtime_ompbios_OpenMP_allocateStackFromHeap;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_allocateStackFromHeap ti_runtime_ompbios_OpenMP_allocateStackFromHeap__C;
#endif

/* allocateStackFromHeapSize */
#ifdef ti_runtime_ompbios_OpenMP_allocateStackFromHeapSize__D
#define ti_runtime_ompbios_OpenMP_allocateStackFromHeapSize (ti_runtime_ompbios_OpenMP_allocateStackFromHeapSize__D)
#else
#define ti_runtime_ompbios_OpenMP_allocateStackFromHeapSize (ti_runtime_ompbios_OpenMP_allocateStackFromHeapSize__C)
typedef xdc_Int32 CT__ti_runtime_ompbios_OpenMP_allocateStackFromHeapSize;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_allocateStackFromHeapSize ti_runtime_ompbios_OpenMP_allocateStackFromHeapSize__C;
#endif


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_runtime_ompbios_OpenMP_Module_startup( state ) (-1)

/* Module__startupDone__S */
xdc__CODESECT(ti_runtime_ompbios_OpenMP_Module__startupDone__S, "ti_runtime_ompbios_OpenMP_Module__startupDone__S")
__extern xdc_Bool ti_runtime_ompbios_OpenMP_Module__startupDone__S( void );

/* useSharedHeap__E */
#define ti_runtime_ompbios_OpenMP_useSharedHeap ti_runtime_ompbios_OpenMP_useSharedHeap__E
xdc__CODESECT(ti_runtime_ompbios_OpenMP_useSharedHeap__E, "ti_runtime_ompbios_OpenMP_useSharedHeap")
__extern xdc_Bool ti_runtime_ompbios_OpenMP_useSharedHeap__E( void );
xdc__CODESECT(ti_runtime_ompbios_OpenMP_useSharedHeap__F, "ti_runtime_ompbios_OpenMP_useSharedHeap")
__extern xdc_Bool ti_runtime_ompbios_OpenMP_useSharedHeap__F( void );

/* setProcId__I */
#define ti_runtime_ompbios_OpenMP_setProcId ti_runtime_ompbios_OpenMP_setProcId__I
xdc__CODESECT(ti_runtime_ompbios_OpenMP_setProcId__I, "ti_runtime_ompbios_OpenMP_setProcId")
__extern xdc_Void ti_runtime_ompbios_OpenMP_setProcId__I( void );


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_runtime_ompbios_OpenMP_Module_startupDone() ti_runtime_ompbios_OpenMP_Module__startupDone__S()

/* Object_heap */
#define ti_runtime_ompbios_OpenMP_Object_heap() ti_runtime_ompbios_OpenMP_Object__heap__C

/* Module_heap */
#define ti_runtime_ompbios_OpenMP_Module_heap() ti_runtime_ompbios_OpenMP_Object__heap__C

/* Module_id */
static inline CT__ti_runtime_ompbios_OpenMP_Module__id ti_runtime_ompbios_OpenMP_Module_id( void ) 
{
    return ti_runtime_ompbios_OpenMP_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_runtime_ompbios_OpenMP_Module_hasMask( void ) 
{
    return (xdc_Bool)(ti_runtime_ompbios_OpenMP_Module__diagsMask__C != NULL);
}

/* Module_getMask */
static inline xdc_Bits16 ti_runtime_ompbios_OpenMP_Module_getMask( void ) 
{
    return ti_runtime_ompbios_OpenMP_Module__diagsMask__C != NULL ? *ti_runtime_ompbios_OpenMP_Module__diagsMask__C : (xdc_Bits16)0;
}

/* Module_setMask */
static inline xdc_Void ti_runtime_ompbios_OpenMP_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_runtime_ompbios_OpenMP_Module__diagsMask__C != NULL) {
        *ti_runtime_ompbios_OpenMP_Module__diagsMask__C = mask;
    }
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_runtime_ompbios_OpenMP__top__
#undef __nested__
#endif

#endif /* ti_runtime_ompbios_OpenMP__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_runtime_ompbios_OpenMP__internalaccess))

#ifndef ti_runtime_ompbios_OpenMP__include_state
#define ti_runtime_ompbios_OpenMP__include_state

/* Module_State */
struct ti_runtime_ompbios_OpenMP_Module_State {
    xdc_Bool useSharedHeap;
};

/* Module__state__V */
extern struct ti_runtime_ompbios_OpenMP_Module_State__ ti_runtime_ompbios_OpenMP_Module__state__V;

#endif /* ti_runtime_ompbios_OpenMP__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_runtime_ompbios_OpenMP__nolocalnames)

#ifndef ti_runtime_ompbios_OpenMP__localnames__done
#define ti_runtime_ompbios_OpenMP__localnames__done

/* module prefix */
#define OpenMP_Module_State ti_runtime_ompbios_OpenMP_Module_State
#define OpenMP_numCores ti_runtime_ompbios_OpenMP_numCores
#define OpenMP_masterCoreIdx ti_runtime_ompbios_OpenMP_masterCoreIdx
#define OpenMP_clockFreq ti_runtime_ompbios_OpenMP_clockFreq
#define OpenMP_hasMsmc ti_runtime_ompbios_OpenMP_hasMsmc
#define OpenMP_msmcBase ti_runtime_ompbios_OpenMP_msmcBase
#define OpenMP_msmcSize ti_runtime_ompbios_OpenMP_msmcSize
#define OpenMP_msmcNoCacheVirtualBase ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualBase
#define OpenMP_msmcNoCacheVirtualSize ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualSize
#define OpenMP_msmcNoCachePhysicalBase ti_runtime_ompbios_OpenMP_msmcNoCachePhysicalBase
#define OpenMP_ddrBase ti_runtime_ompbios_OpenMP_ddrBase
#define OpenMP_ddrSize ti_runtime_ompbios_OpenMP_ddrSize
#define OpenMP_ddrNoCacheBase ti_runtime_ompbios_OpenMP_ddrNoCacheBase
#define OpenMP_ddrNoCacheSize ti_runtime_ompbios_OpenMP_ddrNoCacheSize
#define OpenMP_mpaxForMsmcMapping ti_runtime_ompbios_OpenMP_mpaxForMsmcMapping
#define OpenMP_hwSemBaseIdx ti_runtime_ompbios_OpenMP_hwSemBaseIdx
#define OpenMP_hwSemCount ti_runtime_ompbios_OpenMP_hwSemCount
#define OpenMP_qmssInit ti_runtime_ompbios_OpenMP_qmssInit
#define OpenMP_qmssMemRegionIndex ti_runtime_ompbios_OpenMP_qmssMemRegionIndex
#define OpenMP_qmssFirstDescIdxInLinkingRam ti_runtime_ompbios_OpenMP_qmssFirstDescIdxInLinkingRam
#define OpenMP_qmssHwQueueBaseIdx ti_runtime_ompbios_OpenMP_qmssHwQueueBaseIdx
#define OpenMP_useIpcSharedHeap ti_runtime_ompbios_OpenMP_useIpcSharedHeap
#define OpenMP_allocateLocalHeap ti_runtime_ompbios_OpenMP_allocateLocalHeap
#define OpenMP_allocateLocalHeapSize ti_runtime_ompbios_OpenMP_allocateLocalHeapSize
#define OpenMP_allocateSharedHeap ti_runtime_ompbios_OpenMP_allocateSharedHeap
#define OpenMP_allocateSharedHeapSize ti_runtime_ompbios_OpenMP_allocateSharedHeapSize
#define OpenMP_allocateStackFromHeap ti_runtime_ompbios_OpenMP_allocateStackFromHeap
#define OpenMP_allocateStackFromHeapSize ti_runtime_ompbios_OpenMP_allocateStackFromHeapSize
#define OpenMP_useSharedHeap ti_runtime_ompbios_OpenMP_useSharedHeap
#define OpenMP_Module_name ti_runtime_ompbios_OpenMP_Module_name
#define OpenMP_Module_id ti_runtime_ompbios_OpenMP_Module_id
#define OpenMP_Module_startup ti_runtime_ompbios_OpenMP_Module_startup
#define OpenMP_Module_startupDone ti_runtime_ompbios_OpenMP_Module_startupDone
#define OpenMP_Module_hasMask ti_runtime_ompbios_OpenMP_Module_hasMask
#define OpenMP_Module_getMask ti_runtime_ompbios_OpenMP_Module_getMask
#define OpenMP_Module_setMask ti_runtime_ompbios_OpenMP_Module_setMask
#define OpenMP_Object_heap ti_runtime_ompbios_OpenMP_Object_heap
#define OpenMP_Module_heap ti_runtime_ompbios_OpenMP_Module_heap

#endif /* ti_runtime_ompbios_OpenMP__localnames__done */
#endif
