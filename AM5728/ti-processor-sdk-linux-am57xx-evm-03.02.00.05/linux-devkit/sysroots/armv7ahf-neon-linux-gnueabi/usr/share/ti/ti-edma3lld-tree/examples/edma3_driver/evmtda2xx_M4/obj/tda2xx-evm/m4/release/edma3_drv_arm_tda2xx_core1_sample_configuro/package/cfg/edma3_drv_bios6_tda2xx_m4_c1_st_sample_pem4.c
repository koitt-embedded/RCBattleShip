/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-B21
 */

#define __nested__
#define __config__

#include <xdc/std.h>

/*
 * ======== GENERATED SECTIONS ========
 *     
 *     MODULE INCLUDES
 *     
 *     <module-name> INTERNALS
 *     <module-name> INHERITS
 *     <module-name> VTABLE
 *     <module-name> PATCH TABLE
 *     <module-name> DECLARATIONS
 *     <module-name> OBJECT OFFSETS
 *     <module-name> TEMPLATES
 *     <module-name> INITIALIZERS
 *     <module-name> FUNCTION STUBS
 *     <module-name> PROXY BODY
 *     <module-name> OBJECT DESCRIPTOR
 *     <module-name> VIRTUAL FUNCTIONS
 *     <module-name> SYSTEM FUNCTIONS
 *     <module-name> PRAGMAS
 *     
 *     INITIALIZATION ENTRY POINT
 *     PROGRAM GLOBALS
 *     CLINK DIRECTIVES
 */


/*
 * ======== MODULE INCLUDES ========
 */

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/family/arm/ducati/CTM.h>
#include <ti/sysbios/family/arm/ducati/Core.h>
#include <ti/sysbios/family/arm/ducati/GateDualCore.h>
#include <ti/sysbios/family/arm/ducati/Timer.h>
#include <ti/sysbios/family/arm/m3/Hwi.h>
#include <ti/sysbios/family/arm/m3/IntrinsicsSupport.h>
#include <ti/sysbios/family/arm/m3/TaskSupport.h>
#include <ti/sysbios/family/shared/vayu/IntXbar.h>
#include <ti/sysbios/gates/GateHwi.h>
#include <ti/sysbios/gates/GateMutex.h>
#include <ti/sysbios/hal/Cache.h>
#include <ti/sysbios/hal/Hwi.h>
#include <ti/sysbios/hal/ammu/AMMU.h>
#include <ti/sysbios/hal/unicache/Cache.h>
#include <ti/sysbios/heaps/HeapMem.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Idle.h>
#include <ti/sysbios/knl/Intrinsics.h>
#include <ti/sysbios/knl/Queue.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/knl/Swi.h>
#include <ti/sysbios/knl/Task.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Core.h>
#include <xdc/runtime/Defaults.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Gate.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Main.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/Registry.h>
#include <xdc/runtime/Startup.h>
#include <xdc/runtime/SysMin.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Text.h>

/*
 * ======== ti.sysbios.BIOS INTERNALS ========
 */


/*
 * ======== ti.sysbios.BIOS_RtsGateProxy INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_BIOS_RtsGateProxy_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_BIOS_RtsGateProxy_Module__;

/* Module__root__V */
extern ti_sysbios_BIOS_RtsGateProxy_Module__ ti_sysbios_BIOS_RtsGateProxy_Module__root__V;

/* @@@ ti_sysbios_knl_Queue_Object__ */
typedef struct ti_sysbios_knl_Queue_Object__ {
    ti_sysbios_knl_Queue_Elem elem;
} ti_sysbios_knl_Queue_Object__;

/* @@@ ti_sysbios_knl_Queue_Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_knl_Queue_Object__ obj;
} ti_sysbios_knl_Queue_Object2__;

/* @@@ ti_sysbios_knl_Semaphore_Object__ */
typedef struct ti_sysbios_knl_Semaphore_Object__ {
    ti_sysbios_knl_Event_Handle event;
    xdc_UInt eventId;
    ti_sysbios_knl_Semaphore_Mode mode;
    volatile xdc_UInt16 count;
    ti_sysbios_knl_Queue_Object__ Object_field_pendQ;
} ti_sysbios_knl_Semaphore_Object__;

/* @@@ ti_sysbios_knl_Semaphore_Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_knl_Semaphore_Object__ obj;
} ti_sysbios_knl_Semaphore_Object2__;

/* Object__ */
typedef struct ti_sysbios_gates_GateMutex_Object__ {
    const ti_sysbios_gates_GateMutex_Fxns__ *__fxns;
    ti_sysbios_knl_Task_Handle owner;
    ti_sysbios_knl_Semaphore_Object__ Object_field_sem;
} ti_sysbios_gates_GateMutex_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_gates_GateMutex_Object__ obj;
} ti_sysbios_gates_GateMutex_Object2__;

/* Object */
typedef ti_sysbios_gates_GateMutex_Object__ ti_sysbios_BIOS_RtsGateProxy_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_BIOS_RtsGateProxy_Object__ obj;
} ti_sysbios_BIOS_RtsGateProxy_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_BIOS_RtsGateProxy___VERS
    #define ti_sysbios_BIOS_RtsGateProxy___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_BIOS_RtsGateProxy___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.family.arm.ducati.CTM INTERNALS ========
 */


/*
 * ======== ti.sysbios.family.arm.ducati.Core INTERNALS ========
 */


/*
 * ======== ti.sysbios.family.arm.ducati.GateDualCore INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_family_arm_ducati_GateDualCore_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_family_arm_ducati_GateDualCore_Module__;

/* Module__root__V */
extern ti_sysbios_family_arm_ducati_GateDualCore_Module__ ti_sysbios_family_arm_ducati_GateDualCore_Module__root__V;

/* Object__ */
typedef struct ti_sysbios_family_arm_ducati_GateDualCore_Object__ {
    const ti_sysbios_family_arm_ducati_GateDualCore_Fxns__ *__fxns;
    xdc_UInt index;
    volatile xdc_UInt32 *gatePtr;
    volatile xdc_UInt8 *gateBytePtr;
    xdc_UInt stalls;
    xdc_UInt noStalls;
    xdc_UInt totalStalls;
    xdc_UInt maxStall;
} ti_sysbios_family_arm_ducati_GateDualCore_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_family_arm_ducati_GateDualCore_Object__ obj;
} ti_sysbios_family_arm_ducati_GateDualCore_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_family_arm_ducati_GateDualCore___VERS
    #define ti_sysbios_family_arm_ducati_GateDualCore___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_family_arm_ducati_GateDualCore___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.family.arm.ducati.Timer INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_family_arm_ducati_Timer_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_family_arm_ducati_Timer_Module__;

/* Module__root__V */
extern ti_sysbios_family_arm_ducati_Timer_Module__ ti_sysbios_family_arm_ducati_Timer_Module__root__V;

/* Object__ */
typedef struct ti_sysbios_family_arm_ducati_Timer_Object__ {
    const ti_sysbios_family_arm_ducati_Timer_Fxns__ *__fxns;
    xdc_Bool staticInst;
    xdc_Int id;
    xdc_Int ctmid;
    ti_sysbios_family_arm_ducati_Timer_RunMode runMode;
    ti_sysbios_family_arm_ducati_Timer_StartMode startMode;
    xdc_UInt period;
    ti_sysbios_family_arm_ducati_Timer_PeriodType periodType;
    xdc_UInt intNum;
    xdc_UArg arg;
    ti_sysbios_family_arm_m3_Hwi_FuncPtr tickFxn;
    xdc_runtime_Types_FreqHz extFreq;
    ti_sysbios_family_arm_m3_Hwi_Handle hwi;
} ti_sysbios_family_arm_ducati_Timer_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_family_arm_ducati_Timer_Object__ obj;
} ti_sysbios_family_arm_ducati_Timer_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_family_arm_ducati_Timer___VERS
    #define ti_sysbios_family_arm_ducati_Timer___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_family_arm_ducati_Timer___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.family.arm.m3.Hwi INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_family_arm_m3_Hwi_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_family_arm_m3_Hwi_Module__;

/* Module__root__V */
extern ti_sysbios_family_arm_m3_Hwi_Module__ ti_sysbios_family_arm_m3_Hwi_Module__root__V;

/* Object__ */
typedef struct ti_sysbios_family_arm_m3_Hwi_Object__ {
    const ti_sysbios_family_arm_m3_Hwi_Fxns__ *__fxns;
    xdc_UArg arg;
    ti_sysbios_family_arm_m3_Hwi_FuncPtr fxn;
    ti_sysbios_family_arm_m3_Hwi_Irp irp;
    xdc_UInt8 priority;
    xdc_Int16 intNum;
    __TA_ti_sysbios_family_arm_m3_Hwi_Instance_State__hookEnv hookEnv;
} ti_sysbios_family_arm_m3_Hwi_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_family_arm_m3_Hwi_Object__ obj;
} ti_sysbios_family_arm_m3_Hwi_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_family_arm_m3_Hwi___VERS
    #define ti_sysbios_family_arm_m3_Hwi___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_family_arm_m3_Hwi___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.family.arm.m3.IntrinsicsSupport INTERNALS ========
 */


/*
 * ======== ti.sysbios.family.arm.m3.TaskSupport INTERNALS ========
 */


/*
 * ======== ti.sysbios.family.shared.vayu.IntXbar INTERNALS ========
 */


/*
 * ======== ti.sysbios.gates.GateHwi INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_gates_GateHwi_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_gates_GateHwi_Module__;

/* Module__root__V */
extern ti_sysbios_gates_GateHwi_Module__ ti_sysbios_gates_GateHwi_Module__root__V;

/* Object__ */
typedef struct ti_sysbios_gates_GateHwi_Object__ {
    const ti_sysbios_gates_GateHwi_Fxns__ *__fxns;
} ti_sysbios_gates_GateHwi_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_gates_GateHwi_Object__ obj;
} ti_sysbios_gates_GateHwi_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_gates_GateHwi___VERS
    #define ti_sysbios_gates_GateHwi___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_gates_GateHwi___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.gates.GateMutex INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_gates_GateMutex_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_gates_GateMutex_Module__;

/* Module__root__V */
extern ti_sysbios_gates_GateMutex_Module__ ti_sysbios_gates_GateMutex_Module__root__V;

/* <-- ti_sysbios_gates_GateMutex_Object */

/* __ParamsPtr */
#ifdef ti_sysbios_gates_GateMutex___VERS
    #define ti_sysbios_gates_GateMutex___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_gates_GateMutex___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.hal.Cache INTERNALS ========
 */


/*
 * ======== ti.sysbios.hal.Cache_CacheProxy INTERNALS ========
 */


/*
 * ======== ti.sysbios.hal.Hwi INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_hal_Hwi_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_hal_Hwi_Module__;

/* Module__root__V */
extern ti_sysbios_hal_Hwi_Module__ ti_sysbios_hal_Hwi_Module__root__V;

/* Object__ */
typedef struct ti_sysbios_hal_Hwi_Object__ {
    const ti_sysbios_hal_Hwi_Fxns__ *__fxns;
    ti_sysbios_hal_Hwi_HwiProxy_Handle pi;
} ti_sysbios_hal_Hwi_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_hal_Hwi_Object__ obj;
} ti_sysbios_hal_Hwi_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_hal_Hwi___VERS
    #define ti_sysbios_hal_Hwi___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_hal_Hwi___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.hal.Hwi_HwiProxy INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_hal_Hwi_HwiProxy_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_hal_Hwi_HwiProxy_Module__;

/* Module__root__V */
extern ti_sysbios_hal_Hwi_HwiProxy_Module__ ti_sysbios_hal_Hwi_HwiProxy_Module__root__V;

/* <-- ti_sysbios_family_arm_m3_Hwi_Object */

/* Object */
typedef ti_sysbios_family_arm_m3_Hwi_Object__ ti_sysbios_hal_Hwi_HwiProxy_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_hal_Hwi_HwiProxy_Object__ obj;
} ti_sysbios_hal_Hwi_HwiProxy_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_hal_Hwi_HwiProxy___VERS
    #define ti_sysbios_hal_Hwi_HwiProxy___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_hal_Hwi_HwiProxy___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.hal.ammu.AMMU INTERNALS ========
 */


/*
 * ======== ti.sysbios.hal.unicache.Cache INTERNALS ========
 */


/*
 * ======== ti.sysbios.hal.unicache.Cache_Module_GateProxy INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_hal_unicache_Cache_Module_GateProxy_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_hal_unicache_Cache_Module_GateProxy_Module__;

/* Module__root__V */
extern ti_sysbios_hal_unicache_Cache_Module_GateProxy_Module__ ti_sysbios_hal_unicache_Cache_Module_GateProxy_Module__root__V;

/* <-- ti_sysbios_family_arm_ducati_GateDualCore_Object */

/* Object */
typedef ti_sysbios_family_arm_ducati_GateDualCore_Object__ ti_sysbios_hal_unicache_Cache_Module_GateProxy_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_hal_unicache_Cache_Module_GateProxy_Object__ obj;
} ti_sysbios_hal_unicache_Cache_Module_GateProxy_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_hal_unicache_Cache_Module_GateProxy___VERS
    #define ti_sysbios_hal_unicache_Cache_Module_GateProxy___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_hal_unicache_Cache_Module_GateProxy___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.heaps.HeapMem INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_heaps_HeapMem_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_heaps_HeapMem_Module__;

/* Module__root__V */
extern ti_sysbios_heaps_HeapMem_Module__ ti_sysbios_heaps_HeapMem_Module__root__V;

/* Object__ */
typedef struct ti_sysbios_heaps_HeapMem_Object__ {
    const ti_sysbios_heaps_HeapMem_Fxns__ *__fxns;
    xdc_runtime_Memory_Size align;
    __TA_ti_sysbios_heaps_HeapMem_Instance_State__buf buf;
    ti_sysbios_heaps_HeapMem_Header head;
    xdc_SizeT minBlockAlign;
} ti_sysbios_heaps_HeapMem_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_heaps_HeapMem_Object__ obj;
} ti_sysbios_heaps_HeapMem_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_heaps_HeapMem___VERS
    #define ti_sysbios_heaps_HeapMem___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_heaps_HeapMem___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.heaps.HeapMem_Module_GateProxy INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__;

/* Module__root__V */
extern ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__ ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__root__V;

/* <-- ti_sysbios_gates_GateMutex_Object */

/* Object */
typedef ti_sysbios_gates_GateMutex_Object__ ti_sysbios_heaps_HeapMem_Module_GateProxy_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_heaps_HeapMem_Module_GateProxy_Object__ obj;
} ti_sysbios_heaps_HeapMem_Module_GateProxy_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_heaps_HeapMem_Module_GateProxy___VERS
    #define ti_sysbios_heaps_HeapMem_Module_GateProxy___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_heaps_HeapMem_Module_GateProxy___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.knl.Clock INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_knl_Clock_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_knl_Clock_Module__;

/* Module__root__V */
extern ti_sysbios_knl_Clock_Module__ ti_sysbios_knl_Clock_Module__root__V;

/* <-- ti_sysbios_knl_Queue_Object */

/* Object__ */
typedef struct ti_sysbios_knl_Clock_Object__ {
    ti_sysbios_knl_Queue_Elem elem;
    xdc_UInt32 timeout;
    xdc_UInt32 currTimeout;
    xdc_UInt32 period;
    volatile xdc_Bool active;
    ti_sysbios_knl_Clock_FuncPtr fxn;
    xdc_UArg arg;
} ti_sysbios_knl_Clock_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_knl_Clock_Object__ obj;
} ti_sysbios_knl_Clock_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_knl_Clock___VERS
    #define ti_sysbios_knl_Clock___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_knl_Clock___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.knl.Clock_TimerProxy INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_knl_Clock_TimerProxy_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_knl_Clock_TimerProxy_Module__;

/* Module__root__V */
extern ti_sysbios_knl_Clock_TimerProxy_Module__ ti_sysbios_knl_Clock_TimerProxy_Module__root__V;

/* <-- ti_sysbios_family_arm_ducati_Timer_Object */

/* Object */
typedef ti_sysbios_family_arm_ducati_Timer_Object__ ti_sysbios_knl_Clock_TimerProxy_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_knl_Clock_TimerProxy_Object__ obj;
} ti_sysbios_knl_Clock_TimerProxy_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_knl_Clock_TimerProxy___VERS
    #define ti_sysbios_knl_Clock_TimerProxy___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_knl_Clock_TimerProxy___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.knl.Idle INTERNALS ========
 */


/*
 * ======== ti.sysbios.knl.Intrinsics INTERNALS ========
 */


/*
 * ======== ti.sysbios.knl.Intrinsics_SupportProxy INTERNALS ========
 */


/*
 * ======== ti.sysbios.knl.Queue INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_knl_Queue_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_knl_Queue_Module__;

/* Module__root__V */
extern ti_sysbios_knl_Queue_Module__ ti_sysbios_knl_Queue_Module__root__V;

/* <-- ti_sysbios_knl_Queue_Object */

/* __ParamsPtr */
#ifdef ti_sysbios_knl_Queue___VERS
    #define ti_sysbios_knl_Queue___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_knl_Queue___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.knl.Semaphore INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_knl_Semaphore_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_knl_Semaphore_Module__;

/* Module__root__V */
extern ti_sysbios_knl_Semaphore_Module__ ti_sysbios_knl_Semaphore_Module__root__V;

/* <-- ti_sysbios_knl_Semaphore_Object */

/* __ParamsPtr */
#ifdef ti_sysbios_knl_Semaphore___VERS
    #define ti_sysbios_knl_Semaphore___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_knl_Semaphore___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.knl.Swi INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_knl_Swi_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_knl_Swi_Module__;

/* Module__root__V */
extern ti_sysbios_knl_Swi_Module__ ti_sysbios_knl_Swi_Module__root__V;

/* Object__ */
typedef struct ti_sysbios_knl_Swi_Object__ {
    ti_sysbios_knl_Queue_Elem qElem;
    ti_sysbios_knl_Swi_FuncPtr fxn;
    xdc_UArg arg0;
    xdc_UArg arg1;
    xdc_UInt priority;
    xdc_UInt mask;
    xdc_Bool posted;
    xdc_UInt initTrigger;
    xdc_UInt trigger;
    ti_sysbios_knl_Queue_Handle readyQ;
    __TA_ti_sysbios_knl_Swi_Instance_State__hookEnv hookEnv;
} ti_sysbios_knl_Swi_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_knl_Swi_Object__ obj;
} ti_sysbios_knl_Swi_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_knl_Swi___VERS
    #define ti_sysbios_knl_Swi___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_knl_Swi___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.knl.Task INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_knl_Task_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_knl_Task_Module__;

/* Module__root__V */
extern ti_sysbios_knl_Task_Module__ ti_sysbios_knl_Task_Module__root__V;

/* <-- ti_sysbios_knl_Queue_Object */

/* Object__ */
typedef struct ti_sysbios_knl_Task_Object__ {
    ti_sysbios_knl_Queue_Elem qElem;
    volatile xdc_Int priority;
    xdc_UInt mask;
    xdc_Ptr context;
    ti_sysbios_knl_Task_Mode mode;
    ti_sysbios_knl_Task_PendElem *pendElem;
    xdc_SizeT stackSize;
    __TA_ti_sysbios_knl_Task_Instance_State__stack stack;
    xdc_runtime_IHeap_Handle stackHeap;
    ti_sysbios_knl_Task_FuncPtr fxn;
    xdc_UArg arg0;
    xdc_UArg arg1;
    xdc_Ptr env;
    __TA_ti_sysbios_knl_Task_Instance_State__hookEnv hookEnv;
    xdc_Bool vitalTaskFlag;
    ti_sysbios_knl_Queue_Handle readyQ;
    xdc_UInt curCoreId;
    xdc_UInt affinity;
} ti_sysbios_knl_Task_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_knl_Task_Object__ obj;
} ti_sysbios_knl_Task_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_knl_Task___VERS
    #define ti_sysbios_knl_Task___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_knl_Task___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.knl.Task_SupportProxy INTERNALS ========
 */


/*
 * ======== xdc.runtime.Assert INTERNALS ========
 */


/*
 * ======== xdc.runtime.Core INTERNALS ========
 */


/*
 * ======== xdc.runtime.Defaults INTERNALS ========
 */


/*
 * ======== xdc.runtime.Diags INTERNALS ========
 */


/*
 * ======== xdc.runtime.Error INTERNALS ========
 */


/*
 * ======== xdc.runtime.Gate INTERNALS ========
 */


/*
 * ======== xdc.runtime.Log INTERNALS ========
 */


/*
 * ======== xdc.runtime.Main INTERNALS ========
 */


/*
 * ======== xdc.runtime.Main_Module_GateProxy INTERNALS ========
 */

/* Module__ */
typedef struct xdc_runtime_Main_Module_GateProxy_Module__ {
    xdc_runtime_Types_Link link;
} xdc_runtime_Main_Module_GateProxy_Module__;

/* Module__root__V */
extern xdc_runtime_Main_Module_GateProxy_Module__ xdc_runtime_Main_Module_GateProxy_Module__root__V;

/* <-- ti_sysbios_gates_GateHwi_Object */

/* Object */
typedef ti_sysbios_gates_GateHwi_Object__ xdc_runtime_Main_Module_GateProxy_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    xdc_runtime_Main_Module_GateProxy_Object__ obj;
} xdc_runtime_Main_Module_GateProxy_Object2__;

/* __ParamsPtr */
#ifdef xdc_runtime_Main_Module_GateProxy___VERS
    #define xdc_runtime_Main_Module_GateProxy___ParamsPtr xdc_UChar*
#else
    #define xdc_runtime_Main_Module_GateProxy___ParamsPtr xdc_Ptr
#endif


/*
 * ======== xdc.runtime.Memory INTERNALS ========
 */


/*
 * ======== xdc.runtime.Memory_HeapProxy INTERNALS ========
 */

/* Module__ */
typedef struct xdc_runtime_Memory_HeapProxy_Module__ {
    xdc_runtime_Types_Link link;
} xdc_runtime_Memory_HeapProxy_Module__;

/* Module__root__V */
extern xdc_runtime_Memory_HeapProxy_Module__ xdc_runtime_Memory_HeapProxy_Module__root__V;

/* <-- ti_sysbios_heaps_HeapMem_Object */

/* Object */
typedef ti_sysbios_heaps_HeapMem_Object__ xdc_runtime_Memory_HeapProxy_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    xdc_runtime_Memory_HeapProxy_Object__ obj;
} xdc_runtime_Memory_HeapProxy_Object2__;

/* __ParamsPtr */
#ifdef xdc_runtime_Memory_HeapProxy___VERS
    #define xdc_runtime_Memory_HeapProxy___ParamsPtr xdc_UChar*
#else
    #define xdc_runtime_Memory_HeapProxy___ParamsPtr xdc_Ptr
#endif


/*
 * ======== xdc.runtime.Registry INTERNALS ========
 */


/*
 * ======== xdc.runtime.Startup INTERNALS ========
 */


/*
 * ======== xdc.runtime.SysMin INTERNALS ========
 */


/*
 * ======== xdc.runtime.System INTERNALS ========
 */


/*
 * ======== xdc.runtime.System_Module_GateProxy INTERNALS ========
 */

/* Module__ */
typedef struct xdc_runtime_System_Module_GateProxy_Module__ {
    xdc_runtime_Types_Link link;
} xdc_runtime_System_Module_GateProxy_Module__;

/* Module__root__V */
extern xdc_runtime_System_Module_GateProxy_Module__ xdc_runtime_System_Module_GateProxy_Module__root__V;

/* <-- ti_sysbios_gates_GateHwi_Object */

/* Object */
typedef ti_sysbios_gates_GateHwi_Object__ xdc_runtime_System_Module_GateProxy_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    xdc_runtime_System_Module_GateProxy_Object__ obj;
} xdc_runtime_System_Module_GateProxy_Object2__;

/* __ParamsPtr */
#ifdef xdc_runtime_System_Module_GateProxy___VERS
    #define xdc_runtime_System_Module_GateProxy___ParamsPtr xdc_UChar*
#else
    #define xdc_runtime_System_Module_GateProxy___ParamsPtr xdc_Ptr
#endif


/*
 * ======== xdc.runtime.System_SupportProxy INTERNALS ========
 */


/*
 * ======== xdc.runtime.Text INTERNALS ========
 */


/*
 * ======== INHERITS ========
 */

#pragma DATA_SECTION(xdc_runtime_IHeap_Interface__BASE__C, ".const:xdc_runtime_IHeap_Interface__BASE__C");
__FAR__ const xdc_runtime_Types_Base xdc_runtime_IHeap_Interface__BASE__C = {(void *)&xdc_runtime_IModule_Interface__BASE__C};

#pragma DATA_SECTION(ti_sysbios_interfaces_ICache_Interface__BASE__C, ".const:ti_sysbios_interfaces_ICache_Interface__BASE__C");
__FAR__ const xdc_runtime_Types_Base ti_sysbios_interfaces_ICache_Interface__BASE__C = {(void *)&xdc_runtime_IModule_Interface__BASE__C};

#pragma DATA_SECTION(xdc_runtime_ISystemSupport_Interface__BASE__C, ".const:xdc_runtime_ISystemSupport_Interface__BASE__C");
__FAR__ const xdc_runtime_Types_Base xdc_runtime_ISystemSupport_Interface__BASE__C = {(void *)&xdc_runtime_IModule_Interface__BASE__C};

#pragma DATA_SECTION(ti_sysbios_interfaces_IIntrinsicsSupport_Interface__BASE__C, ".const:ti_sysbios_interfaces_IIntrinsicsSupport_Interface__BASE__C");
__FAR__ const xdc_runtime_Types_Base ti_sysbios_interfaces_IIntrinsicsSupport_Interface__BASE__C = {(void *)&xdc_runtime_IModule_Interface__BASE__C};

#pragma DATA_SECTION(xdc_runtime_IGateProvider_Interface__BASE__C, ".const:xdc_runtime_IGateProvider_Interface__BASE__C");
__FAR__ const xdc_runtime_Types_Base xdc_runtime_IGateProvider_Interface__BASE__C = {(void *)&xdc_runtime_IModule_Interface__BASE__C};

#pragma DATA_SECTION(xdc_runtime_IModule_Interface__BASE__C, ".const:xdc_runtime_IModule_Interface__BASE__C");
__FAR__ const xdc_runtime_Types_Base xdc_runtime_IModule_Interface__BASE__C = {0};


/*
 * ======== ti.sysbios.family.arm.ducati.GateDualCore VTABLE ========
 */

/* Module__FXNS__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_GateDualCore_Module__FXNS__C, ".const:ti_sysbios_family_arm_ducati_GateDualCore_Module__FXNS__C");
const ti_sysbios_family_arm_ducati_GateDualCore_Fxns__ ti_sysbios_family_arm_ducati_GateDualCore_Module__FXNS__C = {
    (void *)&xdc_runtime_IGateProvider_Interface__BASE__C, /* __base */
    &ti_sysbios_family_arm_ducati_GateDualCore_Module__FXNS__C.__sfxns, /* __sysp */
    ti_sysbios_family_arm_ducati_GateDualCore_query__E,
    ti_sysbios_family_arm_ducati_GateDualCore_enter__E,
    ti_sysbios_family_arm_ducati_GateDualCore_leave__E,
    {
        ti_sysbios_family_arm_ducati_GateDualCore_Object__create__S,
        ti_sysbios_family_arm_ducati_GateDualCore_Object__delete__S,
        ti_sysbios_family_arm_ducati_GateDualCore_Handle__label__S,
        0x8029, /* __mid */
    } /* __sfxns */
};


/*
 * ======== ti.sysbios.family.arm.m3.IntrinsicsSupport VTABLE ========
 */

/* Module__FXNS__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__FXNS__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__FXNS__C");
const ti_sysbios_family_arm_m3_IntrinsicsSupport_Fxns__ ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__FXNS__C = {
    (void *)&ti_sysbios_interfaces_IIntrinsicsSupport_Interface__BASE__C, /* __base */
    &ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__FXNS__C.__sfxns, /* __sysp */
    ti_sysbios_family_arm_m3_IntrinsicsSupport_maxbit__E,
    {
        NULL, /* __create */
        NULL, /* __delete */
        NULL, /* __label */
        0x8021, /* __mid */
    } /* __sfxns */
};


/*
 * ======== ti.sysbios.gates.GateHwi VTABLE ========
 */

/* Module__FXNS__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__FXNS__C, ".const:ti_sysbios_gates_GateHwi_Module__FXNS__C");
const ti_sysbios_gates_GateHwi_Fxns__ ti_sysbios_gates_GateHwi_Module__FXNS__C = {
    (void *)&xdc_runtime_IGateProvider_Interface__BASE__C, /* __base */
    &ti_sysbios_gates_GateHwi_Module__FXNS__C.__sfxns, /* __sysp */
    ti_sysbios_gates_GateHwi_query__E,
    ti_sysbios_gates_GateHwi_enter__E,
    ti_sysbios_gates_GateHwi_leave__E,
    {
        ti_sysbios_gates_GateHwi_Object__create__S,
        ti_sysbios_gates_GateHwi_Object__delete__S,
        ti_sysbios_gates_GateHwi_Handle__label__S,
        0x8030, /* __mid */
    } /* __sfxns */
};


/*
 * ======== ti.sysbios.gates.GateMutex VTABLE ========
 */

/* Module__FXNS__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__FXNS__C, ".const:ti_sysbios_gates_GateMutex_Module__FXNS__C");
const ti_sysbios_gates_GateMutex_Fxns__ ti_sysbios_gates_GateMutex_Module__FXNS__C = {
    (void *)&xdc_runtime_IGateProvider_Interface__BASE__C, /* __base */
    &ti_sysbios_gates_GateMutex_Module__FXNS__C.__sfxns, /* __sysp */
    ti_sysbios_gates_GateMutex_query__E,
    ti_sysbios_gates_GateMutex_enter__E,
    ti_sysbios_gates_GateMutex_leave__E,
    {
        ti_sysbios_gates_GateMutex_Object__create__S,
        ti_sysbios_gates_GateMutex_Object__delete__S,
        ti_sysbios_gates_GateMutex_Handle__label__S,
        0x8031, /* __mid */
    } /* __sfxns */
};


/*
 * ======== ti.sysbios.hal.unicache.Cache VTABLE ========
 */

/* Module__FXNS__C */
#pragma DATA_SECTION(ti_sysbios_hal_unicache_Cache_Module__FXNS__C, ".const:ti_sysbios_hal_unicache_Cache_Module__FXNS__C");
const ti_sysbios_hal_unicache_Cache_Fxns__ ti_sysbios_hal_unicache_Cache_Module__FXNS__C = {
    (void *)&ti_sysbios_interfaces_ICache_Interface__BASE__C, /* __base */
    &ti_sysbios_hal_unicache_Cache_Module__FXNS__C.__sfxns, /* __sysp */
    ti_sysbios_hal_unicache_Cache_enable__E,
    ti_sysbios_hal_unicache_Cache_disable__E,
    ti_sysbios_hal_unicache_Cache_inv__E,
    ti_sysbios_hal_unicache_Cache_wb__E,
    ti_sysbios_hal_unicache_Cache_wbInv__E,
    ti_sysbios_hal_unicache_Cache_wbAll__E,
    ti_sysbios_hal_unicache_Cache_wbInvAll__E,
    ti_sysbios_hal_unicache_Cache_wait__E,
    {
        NULL, /* __create */
        NULL, /* __delete */
        NULL, /* __label */
        0x802c, /* __mid */
    } /* __sfxns */
};


/*
 * ======== ti.sysbios.heaps.HeapMem VTABLE ========
 */

/* Module__FXNS__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__FXNS__C, ".const:ti_sysbios_heaps_HeapMem_Module__FXNS__C");
const ti_sysbios_heaps_HeapMem_Fxns__ ti_sysbios_heaps_HeapMem_Module__FXNS__C = {
    (void *)&xdc_runtime_IHeap_Interface__BASE__C, /* __base */
    &ti_sysbios_heaps_HeapMem_Module__FXNS__C.__sfxns, /* __sysp */
    ti_sysbios_heaps_HeapMem_alloc__E,
    ti_sysbios_heaps_HeapMem_free__E,
    ti_sysbios_heaps_HeapMem_isBlocking__E,
    ti_sysbios_heaps_HeapMem_getStats__E,
    {
        ti_sysbios_heaps_HeapMem_Object__create__S,
        ti_sysbios_heaps_HeapMem_Object__delete__S,
        ti_sysbios_heaps_HeapMem_Handle__label__S,
        0x8033, /* __mid */
    } /* __sfxns */
};


/*
 * ======== xdc.runtime.SysMin VTABLE ========
 */

/* Module__FXNS__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__FXNS__C, ".const:xdc_runtime_SysMin_Module__FXNS__C");
const xdc_runtime_SysMin_Fxns__ xdc_runtime_SysMin_Module__FXNS__C = {
    (void *)&xdc_runtime_ISystemSupport_Interface__BASE__C, /* __base */
    &xdc_runtime_SysMin_Module__FXNS__C.__sfxns, /* __sysp */
    xdc_runtime_SysMin_abort__E,
    xdc_runtime_SysMin_exit__E,
    xdc_runtime_SysMin_flush__E,
    xdc_runtime_SysMin_putch__E,
    xdc_runtime_SysMin_ready__E,
    {
        NULL, /* __create */
        NULL, /* __delete */
        NULL, /* __label */
        0x800e, /* __mid */
    } /* __sfxns */
};


/*
 * ======== ti.sysbios.BIOS DECLARATIONS ========
 */

/* Module_State__ */
typedef struct ti_sysbios_BIOS_Module_State__ {
    xdc_runtime_Types_FreqHz cpuFreq;
    xdc_UInt rtsGateCount;
    xdc_IArg rtsGateKey;
    ti_sysbios_BIOS_RtsGateProxy_Handle rtsGate;
    ti_sysbios_BIOS_ThreadType threadType;
    __TA_ti_sysbios_BIOS_Module_State__smpThreadType smpThreadType;
    volatile ti_sysbios_BIOS_StartFuncPtr startFunc;
    volatile ti_sysbios_BIOS_ExitFuncPtr exitFunc;
} ti_sysbios_BIOS_Module_State__;

/* --> ti_sysbios_BIOS_startFunc */
extern xdc_Void ti_sysbios_BIOS_startFunc(xdc_Void);

/* --> ti_sysbios_BIOS_exitFunc */
extern xdc_Void ti_sysbios_BIOS_exitFunc(xdc_Int);

/* Module__state__V */
ti_sysbios_BIOS_Module_State__ ti_sysbios_BIOS_Module__state__V;


/*
 * ======== ti.sysbios.BIOS_RtsGateProxy DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.family.arm.ducati.CTM DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.family.arm.ducati.Core DECLARATIONS ========
 */

/* Module_State__ */
typedef struct ti_sysbios_family_arm_ducati_Core_Module_State__ {
    volatile xdc_Bool exitFlag;
    __TA_ti_sysbios_family_arm_ducati_Core_Module_State__gateEntered gateEntered;
    __TA_ti_sysbios_family_arm_ducati_Core_Module_State__schedulerInts schedulerInts;
    __TA_ti_sysbios_family_arm_ducati_Core_Module_State__core1HwiStack core1HwiStack;
} ti_sysbios_family_arm_ducati_Core_Module_State__;

/* Module__state__V */
ti_sysbios_family_arm_ducati_Core_Module_State__ ti_sysbios_family_arm_ducati_Core_Module__state__V;


/*
 * ======== ti.sysbios.family.arm.ducati.GateDualCore DECLARATIONS ========
 */

/* Object__table__V */
ti_sysbios_family_arm_ducati_GateDualCore_Object__ ti_sysbios_family_arm_ducati_GateDualCore_Object__table__V[1];

/* Module_State__ */
typedef struct ti_sysbios_family_arm_ducati_GateDualCore_Module_State__ {
    __TA_ti_sysbios_family_arm_ducati_GateDualCore_Module_State__usedGates usedGates;
} ti_sysbios_family_arm_ducati_GateDualCore_Module_State__;

/* Module__state__V */
ti_sysbios_family_arm_ducati_GateDualCore_Module_State__ ti_sysbios_family_arm_ducati_GateDualCore_Module__state__V;


/*
 * ======== ti.sysbios.family.arm.ducati.Timer DECLARATIONS ========
 */

/* Object__table__V */
ti_sysbios_family_arm_ducati_Timer_Object__ ti_sysbios_family_arm_ducati_Timer_Object__table__V[1];

/* Module_State__ */
typedef struct ti_sysbios_family_arm_ducati_Timer_Module_State__ {
    xdc_UInt availMask;
    __TA_ti_sysbios_family_arm_ducati_Timer_Module_State__handles handles;
} ti_sysbios_family_arm_ducati_Timer_Module_State__;

/* Module__state__V */
ti_sysbios_family_arm_ducati_Timer_Module_State__ ti_sysbios_family_arm_ducati_Timer_Module__state__V;


/*
 * ======== ti.sysbios.family.arm.m3.Hwi DECLARATIONS ========
 */

/* Object__table__V */
ti_sysbios_family_arm_m3_Hwi_Object__ ti_sysbios_family_arm_m3_Hwi_Object__table__V[2];

/* Module_State__ */
typedef struct ti_sysbios_family_arm_m3_Hwi_Module_State__ {
    xdc_Char *taskSP;
    __TA_ti_sysbios_family_arm_m3_Hwi_Module_State__excActive excActive;
    __TA_ti_sysbios_family_arm_m3_Hwi_Module_State__excContext excContext;
    __TA_ti_sysbios_family_arm_m3_Hwi_Module_State__excStack excStack;
    xdc_Ptr isrStack;
    xdc_Ptr isrStackBase;
    xdc_Ptr isrStackSize;
    xdc_Ptr vectorTableBase;
    xdc_UInt swiTaskKeys;
    xdc_Ptr dispatchTable;
    volatile xdc_Bool vnvicFlushRequired;
    __TA_ti_sysbios_family_arm_m3_Hwi_Module_State__intAffinity intAffinity;
    __TA_ti_sysbios_family_arm_m3_Hwi_Module_State__intAffinityMasks intAffinityMasks;
} ti_sysbios_family_arm_m3_Hwi_Module_State__;

/* --> ti_sysbios_family_arm_m3_Hwi_Module_State_0_excActive__A */
__T1_ti_sysbios_family_arm_m3_Hwi_Module_State__excActive ti_sysbios_family_arm_m3_Hwi_Module_State_0_excActive__A[1];

/* --> ti_sysbios_family_arm_m3_Hwi_Module_State_0_excContext__A */
__T1_ti_sysbios_family_arm_m3_Hwi_Module_State__excContext ti_sysbios_family_arm_m3_Hwi_Module_State_0_excContext__A[1];

/* --> ti_sysbios_family_arm_m3_Hwi_Module_State_0_excStack__A */
__T1_ti_sysbios_family_arm_m3_Hwi_Module_State__excStack ti_sysbios_family_arm_m3_Hwi_Module_State_0_excStack__A[1];

/* --> __TI_STACK_BASE */
extern void* __TI_STACK_BASE;

/* --> __TI_STACK_SIZE */
extern void* __TI_STACK_SIZE;

/* Module__state__V */
ti_sysbios_family_arm_m3_Hwi_Module_State__ ti_sysbios_family_arm_m3_Hwi_Module__state__V;

/* --> ti_sysbios_family_arm_m3_Hwi_excHookFuncs__A */
const __T1_ti_sysbios_family_arm_m3_Hwi_excHookFuncs ti_sysbios_family_arm_m3_Hwi_excHookFuncs__A[2];

/* --> ti_sysbios_knl_Swi_disable__E */
extern xdc_UInt ti_sysbios_knl_Swi_disable__E(xdc_Void);

/* --> ti_sysbios_knl_Swi_restoreHwi__E */
extern xdc_Void ti_sysbios_knl_Swi_restoreHwi__E(xdc_UInt);

/* --> ti_sysbios_knl_Task_disable__E */
extern xdc_UInt ti_sysbios_knl_Task_disable__E(xdc_Void);

/* --> ti_sysbios_knl_Task_restoreHwi__E */
extern xdc_Void ti_sysbios_knl_Task_restoreHwi__E(xdc_UInt);


/*
 * ======== ti.sysbios.family.arm.m3.IntrinsicsSupport DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.family.arm.m3.TaskSupport DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.family.shared.vayu.IntXbar DECLARATIONS ========
 */

/* Module_State__ */
typedef struct ti_sysbios_family_shared_vayu_IntXbar_Module_State__ {
    __TA_ti_sysbios_family_shared_vayu_IntXbar_Module_State__intXbar intXbar;
} ti_sysbios_family_shared_vayu_IntXbar_Module_State__;

/* --> ti_sysbios_family_shared_vayu_IntXbar_Module_State_0_intXbar__A */
__T1_ti_sysbios_family_shared_vayu_IntXbar_Module_State__intXbar ti_sysbios_family_shared_vayu_IntXbar_Module_State_0_intXbar__A[57];

/* Module__state__V */
ti_sysbios_family_shared_vayu_IntXbar_Module_State__ ti_sysbios_family_shared_vayu_IntXbar_Module__state__V;

/* --> ti_sysbios_family_shared_vayu_IntXbar_intXbar__A */
const __T1_ti_sysbios_family_shared_vayu_IntXbar_intXbar ti_sysbios_family_shared_vayu_IntXbar_intXbar__A[57];


/*
 * ======== ti.sysbios.gates.GateHwi DECLARATIONS ========
 */

/* Object__table__V */
ti_sysbios_gates_GateHwi_Object__ ti_sysbios_gates_GateHwi_Object__table__V[1];


/*
 * ======== ti.sysbios.gates.GateMutex DECLARATIONS ========
 */

/* Object__table__V */
ti_sysbios_gates_GateMutex_Object__ ti_sysbios_gates_GateMutex_Object__table__V[2];


/*
 * ======== ti.sysbios.hal.Cache DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.hal.Cache_CacheProxy DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.hal.Hwi DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.hal.Hwi_HwiProxy DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.hal.ammu.AMMU DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.hal.unicache.Cache DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.hal.unicache.Cache_Module_GateProxy DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.heaps.HeapMem DECLARATIONS ========
 */

#ifdef __IAR_SYSTEMS_ICC__
    #pragma data_alignment=8
#endif
/* --> ti_sysbios_heaps_HeapMem_Instance_State_0_buf__A */
__T1_ti_sysbios_heaps_HeapMem_Instance_State__buf ti_sysbios_heaps_HeapMem_Instance_State_0_buf__A[86016];
#ifdef __ti__align
    #pragma DATA_ALIGN(ti_sysbios_heaps_HeapMem_Instance_State_0_buf__A, 8);
#endif
#ifdef __GNUC__
#ifndef __TI_COMPILER_VERSION__
__T1_ti_sysbios_heaps_HeapMem_Instance_State__buf ti_sysbios_heaps_HeapMem_Instance_State_0_buf__A[86016] __attribute__ ((aligned(8)));
#endif
#endif

/* Object__table__V */
ti_sysbios_heaps_HeapMem_Object__ ti_sysbios_heaps_HeapMem_Object__table__V[1];


/*
 * ======== ti.sysbios.heaps.HeapMem_Module_GateProxy DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.knl.Clock DECLARATIONS ========
 */

/* Module_State__ */
typedef struct ti_sysbios_knl_Clock_Module_State__ {
    volatile xdc_UInt32 ticks;
    xdc_UInt swiCount;
    ti_sysbios_knl_Clock_TimerProxy_Handle timer;
    ti_sysbios_knl_Swi_Handle swi;
    volatile xdc_UInt numTickSkip;
    xdc_UInt32 nextScheduledTick;
    xdc_UInt32 maxSkippable;
    xdc_Bool inWorkFunc;
    xdc_Bool startDuringWorkFunc;
    xdc_Bool ticking;
    ti_sysbios_knl_Queue_Object__ Object_field_clockQ;
} ti_sysbios_knl_Clock_Module_State__;

/* Module__state__V */
ti_sysbios_knl_Clock_Module_State__ ti_sysbios_knl_Clock_Module__state__V;

/* --> ti_sysbios_knl_Clock_doTick__I */
extern xdc_Void ti_sysbios_knl_Clock_doTick__I(xdc_UArg);


/*
 * ======== ti.sysbios.knl.Clock_TimerProxy DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.knl.Idle DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.knl.Intrinsics DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.knl.Intrinsics_SupportProxy DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.knl.Queue DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.knl.Semaphore DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.knl.Swi DECLARATIONS ========
 */

/* Object__table__V */
ti_sysbios_knl_Swi_Object__ ti_sysbios_knl_Swi_Object__table__V[1];

/* Module_State__ */
typedef struct ti_sysbios_knl_Swi_Module_State__ {
    volatile xdc_Bool locked;
    xdc_UInt curSet;
    xdc_UInt curTrigger;
    ti_sysbios_knl_Swi_Handle curSwi;
    ti_sysbios_knl_Queue_Handle curQ;
    __TA_ti_sysbios_knl_Swi_Module_State__readyQ readyQ;
    __TA_ti_sysbios_knl_Swi_Module_State__constructedSwis constructedSwis;
} ti_sysbios_knl_Swi_Module_State__;

/* --> ti_sysbios_knl_Swi_Module_State_0_readyQ__A */
__T1_ti_sysbios_knl_Swi_Module_State__readyQ ti_sysbios_knl_Swi_Module_State_0_readyQ__A[16];

/* Module__state__V */
ti_sysbios_knl_Swi_Module_State__ ti_sysbios_knl_Swi_Module__state__V;

/* --> ti_sysbios_knl_Task_disable__E */
extern xdc_UInt ti_sysbios_knl_Task_disable__E(xdc_Void);

/* --> ti_sysbios_knl_Task_restore__E */
extern xdc_Void ti_sysbios_knl_Task_restore__E(xdc_UInt);


/*
 * ======== ti.sysbios.knl.Task DECLARATIONS ========
 */

#ifdef __IAR_SYSTEMS_ICC__
    #pragma data_alignment=8
#endif
/* --> ti_sysbios_knl_Task_Instance_State_0_stack__A */
__T1_ti_sysbios_knl_Task_Instance_State__stack ti_sysbios_knl_Task_Instance_State_0_stack__A[2048];
#ifdef __ti__sect
    #pragma DATA_SECTION(ti_sysbios_knl_Task_Instance_State_0_stack__A, ".bss:taskStackSection");
#endif
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
#ifndef __TI_COMPILER_VERSION__
__T1_ti_sysbios_knl_Task_Instance_State__stack ti_sysbios_knl_Task_Instance_State_0_stack__A[2048] __attribute__ ((section(".bss:taskStackSection")));
#endif
#endif
#ifdef __ti__align
    #pragma DATA_ALIGN(ti_sysbios_knl_Task_Instance_State_0_stack__A, 8);
#endif
#ifdef __GNUC__
#ifndef __TI_COMPILER_VERSION__
__T1_ti_sysbios_knl_Task_Instance_State__stack ti_sysbios_knl_Task_Instance_State_0_stack__A[2048] __attribute__ ((aligned(8)));
#endif
#endif

/* Object__table__V */
ti_sysbios_knl_Task_Object__ ti_sysbios_knl_Task_Object__table__V[1];

/* Module_State__ */
typedef struct ti_sysbios_knl_Task_Module_State__ {
    volatile xdc_Bool locked;
    volatile xdc_UInt curSet;
    xdc_Bool workFlag;
    xdc_UInt vitalTasks;
    ti_sysbios_knl_Task_Handle curTask;
    ti_sysbios_knl_Queue_Handle curQ;
    __TA_ti_sysbios_knl_Task_Module_State__readyQ readyQ;
    __TA_ti_sysbios_knl_Task_Module_State__smpCurSet smpCurSet;
    __TA_ti_sysbios_knl_Task_Module_State__smpCurMask smpCurMask;
    __TA_ti_sysbios_knl_Task_Module_State__smpCurTask smpCurTask;
    __TA_ti_sysbios_knl_Task_Module_State__smpReadyQ smpReadyQ;
    __TA_ti_sysbios_knl_Task_Module_State__idleTask idleTask;
    __TA_ti_sysbios_knl_Task_Module_State__constructedTasks constructedTasks;
    ti_sysbios_knl_Queue_Object__ Object_field_inactiveQ;
    ti_sysbios_knl_Queue_Object__ Object_field_terminatedQ;
} ti_sysbios_knl_Task_Module_State__;

/* --> ti_sysbios_knl_Task_Module_State_0_readyQ__A */
__T1_ti_sysbios_knl_Task_Module_State__readyQ ti_sysbios_knl_Task_Module_State_0_readyQ__A[16];

/* --> ti_sysbios_knl_Task_Module_State_0_idleTask__A */
__T1_ti_sysbios_knl_Task_Module_State__idleTask ti_sysbios_knl_Task_Module_State_0_idleTask__A[1];

/* Module__state__V */
ti_sysbios_knl_Task_Module_State__ ti_sysbios_knl_Task_Module__state__V;


/*
 * ======== ti.sysbios.knl.Task_SupportProxy DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Assert DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Core DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Defaults DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Diags DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Error DECLARATIONS ========
 */

/* Module_State__ */
typedef struct xdc_runtime_Error_Module_State__ {
    xdc_UInt16 count;
} xdc_runtime_Error_Module_State__;

/* Module__state__V */
xdc_runtime_Error_Module_State__ xdc_runtime_Error_Module__state__V;


/*
 * ======== xdc.runtime.Gate DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Log DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Main DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Main_Module_GateProxy DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Memory DECLARATIONS ========
 */

/* Module_State__ */
typedef struct xdc_runtime_Memory_Module_State__ {
    xdc_SizeT maxDefaultTypeAlign;
} xdc_runtime_Memory_Module_State__;

/* Module__state__V */
xdc_runtime_Memory_Module_State__ xdc_runtime_Memory_Module__state__V;


/*
 * ======== xdc.runtime.Memory_HeapProxy DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Registry DECLARATIONS ========
 */

/* Module_State__ */
typedef struct xdc_runtime_Registry_Module_State__ {
    xdc_runtime_Registry_Desc *listHead;
    xdc_runtime_Types_ModuleId curId;
} xdc_runtime_Registry_Module_State__;

/* Module__state__V */
xdc_runtime_Registry_Module_State__ xdc_runtime_Registry_Module__state__V;


/*
 * ======== xdc.runtime.Startup DECLARATIONS ========
 */

/* Module_State__ */
typedef struct xdc_runtime_Startup_Module_State__ {
    xdc_Int *stateTab;
    xdc_Bool execFlag;
    xdc_Bool rtsDoneFlag;
} xdc_runtime_Startup_Module_State__;

/* Module__state__V */
xdc_runtime_Startup_Module_State__ xdc_runtime_Startup_Module__state__V;

/* --> xdc_runtime_Startup_firstFxns__A */
const __T1_xdc_runtime_Startup_firstFxns xdc_runtime_Startup_firstFxns__A[3];

/* --> xdc_runtime_Startup_lastFxns__A */
const __T1_xdc_runtime_Startup_lastFxns xdc_runtime_Startup_lastFxns__A[1];

/* --> xdc_runtime_System_Module_startup__E */
extern xdc_Int xdc_runtime_System_Module_startup__E(xdc_Int);

/* --> xdc_runtime_SysMin_Module_startup__E */
extern xdc_Int xdc_runtime_SysMin_Module_startup__E(xdc_Int);

/* --> ti_sysbios_knl_Clock_Module_startup__E */
extern xdc_Int ti_sysbios_knl_Clock_Module_startup__E(xdc_Int);

/* --> ti_sysbios_knl_Swi_Module_startup__E */
extern xdc_Int ti_sysbios_knl_Swi_Module_startup__E(xdc_Int);

/* --> ti_sysbios_knl_Task_Module_startup__E */
extern xdc_Int ti_sysbios_knl_Task_Module_startup__E(xdc_Int);

/* --> ti_sysbios_hal_Hwi_Module_startup__E */
extern xdc_Int ti_sysbios_hal_Hwi_Module_startup__E(xdc_Int);

/* --> ti_sysbios_family_arm_m3_Hwi_Module_startup__E */
extern xdc_Int ti_sysbios_family_arm_m3_Hwi_Module_startup__E(xdc_Int);

/* --> ti_sysbios_family_arm_ducati_Core_Module_startup__E */
extern xdc_Int ti_sysbios_family_arm_ducati_Core_Module_startup__E(xdc_Int);

/* --> ti_sysbios_family_arm_ducati_GateDualCore_Module_startup__E */
extern xdc_Int ti_sysbios_family_arm_ducati_GateDualCore_Module_startup__E(xdc_Int);

/* --> ti_sysbios_family_arm_ducati_Timer_Module_startup__E */
extern xdc_Int ti_sysbios_family_arm_ducati_Timer_Module_startup__E(xdc_Int);

/* --> xdc_runtime_Startup_sfxnTab__A */
const __T1_xdc_runtime_Startup_sfxnTab xdc_runtime_Startup_sfxnTab__A[10];

/* --> xdc_runtime_Startup_sfxnRts__A */
const __T1_xdc_runtime_Startup_sfxnRts xdc_runtime_Startup_sfxnRts__A[10];


/*
 * ======== xdc.runtime.SysMin DECLARATIONS ========
 */

/* Module_State__ */
typedef struct xdc_runtime_SysMin_Module_State__ {
    __TA_xdc_runtime_SysMin_Module_State__outbuf outbuf;
    xdc_UInt outidx;
    xdc_Bool wrapped;
} xdc_runtime_SysMin_Module_State__;

/* --> xdc_runtime_SysMin_Module_State_0_outbuf__A */
__T1_xdc_runtime_SysMin_Module_State__outbuf xdc_runtime_SysMin_Module_State_0_outbuf__A[1024];

/* Module__state__V */
xdc_runtime_SysMin_Module_State__ xdc_runtime_SysMin_Module__state__V;

/* --> xdc_runtime_SysMin_output__I */
extern xdc_Void xdc_runtime_SysMin_output__I(xdc_Char*,xdc_UInt);


/*
 * ======== xdc.runtime.System DECLARATIONS ========
 */

/* Module_State__ */
typedef struct xdc_runtime_System_Module_State__ {
    __TA_xdc_runtime_System_Module_State__atexitHandlers atexitHandlers;
    xdc_Int numAtexitHandlers;
} xdc_runtime_System_Module_State__;

/* --> xdc_runtime_System_Module_State_0_atexitHandlers__A */
__T1_xdc_runtime_System_Module_State__atexitHandlers xdc_runtime_System_Module_State_0_atexitHandlers__A[8];

/* Module__state__V */
xdc_runtime_System_Module_State__ xdc_runtime_System_Module__state__V;

/* --> xdc_runtime_System_printfExtend__I */
extern xdc_Int xdc_runtime_System_printfExtend__I(xdc_Char**,xdc_CString*,xdc_VaList*,xdc_runtime_System_ParseData*);


/*
 * ======== xdc.runtime.System_Module_GateProxy DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.System_SupportProxy DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Text DECLARATIONS ========
 */

/* Module_State__ */
typedef struct xdc_runtime_Text_Module_State__ {
    xdc_CPtr charBase;
    xdc_CPtr nodeBase;
} xdc_runtime_Text_Module_State__;

/* Module__state__V */
xdc_runtime_Text_Module_State__ xdc_runtime_Text_Module__state__V;

/* --> xdc_runtime_Text_charTab__A */
const __T1_xdc_runtime_Text_charTab xdc_runtime_Text_charTab__A[7150];

/* --> xdc_runtime_Text_nodeTab__A */
const __T1_xdc_runtime_Text_nodeTab xdc_runtime_Text_nodeTab__A[52];


/*
 * ======== OBJECT OFFSETS ========
 */

#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Instance_State_sem__O, ".const:ti_sysbios_gates_GateMutex_Instance_State_sem__O");
__FAR__ const xdc_SizeT ti_sysbios_gates_GateMutex_Instance_State_sem__O = offsetof(ti_sysbios_gates_GateMutex_Object__, Object_field_sem);


/*
 * ======== OBJECT OFFSETS ========
 */

#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module_State_clockQ__O, ".const:ti_sysbios_knl_Clock_Module_State_clockQ__O");
__FAR__ const xdc_SizeT ti_sysbios_knl_Clock_Module_State_clockQ__O = offsetof(ti_sysbios_knl_Clock_Module_State__, Object_field_clockQ);


/*
 * ======== OBJECT OFFSETS ========
 */

#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Instance_State_pendQ__O, ".const:ti_sysbios_knl_Semaphore_Instance_State_pendQ__O");
__FAR__ const xdc_SizeT ti_sysbios_knl_Semaphore_Instance_State_pendQ__O = offsetof(ti_sysbios_knl_Semaphore_Object__, Object_field_pendQ);


/*
 * ======== OBJECT OFFSETS ========
 */

#pragma DATA_SECTION(ti_sysbios_knl_Task_Module_State_inactiveQ__O, ".const:ti_sysbios_knl_Task_Module_State_inactiveQ__O");
__FAR__ const xdc_SizeT ti_sysbios_knl_Task_Module_State_inactiveQ__O = offsetof(ti_sysbios_knl_Task_Module_State__, Object_field_inactiveQ);
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module_State_terminatedQ__O, ".const:ti_sysbios_knl_Task_Module_State_terminatedQ__O");
__FAR__ const xdc_SizeT ti_sysbios_knl_Task_Module_State_terminatedQ__O = offsetof(ti_sysbios_knl_Task_Module_State__, Object_field_terminatedQ);


/*
 * ======== xdc.cfg.Program TEMPLATE ========
 */

/*
 *  ======== __ASM__ ========
 *  Define absolute path prefix for this executable's
 *  configuration generated files.
 */
xdc__META(__ASM__, "@(#)__ASM__ = /home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/work/am57xx_evm-linux-gnueabi/edma3-lld-rtos/2.12.02.26-r0.0/git/examples/edma3_driver/evmtda2xx_M4/obj/tda2xx-evm/m4/release/edma3_drv_arm_tda2xx_core1_sample_configuro/package/cfg/edma3_drv_bios6_tda2xx_m4_c1_st_sample_pem4");

/*
 *  ======== __ISA__ ========
 *  Define the ISA of this executable.  This symbol is used by platform
 *  specific "exec" commands that support more than one ISA; e.g., gdb
 */
xdc__META(__ISA__, "@(#)__ISA__ = v7M4");

/*
 *  ======== __PLAT__ ========
 *  Define the name of the platform that can run this executable.  This
 *  symbol is used by platform independent "exec" commands
 */
xdc__META(__PLAT__, "@(#)__PLAT__ = ti.platforms.evmDRA7XX");

/*
 *  ======== __TARG__ ========
 *  Define the name of the target used to build this executable.
 */
xdc__META(__TARG__, "@(#)__TARG__ = ti.targets.arm.elf.M4");

/*
 *  ======== __TRDR__ ========
 *  Define the name of the class that can read/parse this executable.
 */
xdc__META(__TRDR__, "@(#)__TRDR__ = ti.targets.omf.elf.Elf32");


/*
 * ======== xdc.cfg.SourceDir TEMPLATE ========
 */



/*
 * ======== xdc.runtime.Diags TEMPLATE ========
 */



/*
 * ======== xdc.runtime.Startup TEMPLATE ========
 */

/*
 *  ======== MODULE STARTUP DONE FUNCTIONS ========
 */
xdc_Bool xdc_runtime_System_Module__startupDone__F(void); /* keep GCC prototype warning quiet */
xdc_Bool xdc_runtime_System_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[0] < 0;
}
xdc_Bool xdc_runtime_SysMin_Module__startupDone__F(void); /* keep GCC prototype warning quiet */
xdc_Bool xdc_runtime_SysMin_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[1] < 0;
}
xdc_Bool ti_sysbios_knl_Clock_Module__startupDone__F(void); /* keep GCC prototype warning quiet */
xdc_Bool ti_sysbios_knl_Clock_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[2] < 0;
}
xdc_Bool ti_sysbios_knl_Swi_Module__startupDone__F(void); /* keep GCC prototype warning quiet */
xdc_Bool ti_sysbios_knl_Swi_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[3] < 0;
}
xdc_Bool ti_sysbios_knl_Task_Module__startupDone__F(void); /* keep GCC prototype warning quiet */
xdc_Bool ti_sysbios_knl_Task_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[4] < 0;
}
xdc_Bool ti_sysbios_hal_Hwi_Module__startupDone__F(void); /* keep GCC prototype warning quiet */
xdc_Bool ti_sysbios_hal_Hwi_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[5] < 0;
}
xdc_Bool ti_sysbios_family_arm_m3_Hwi_Module__startupDone__F(void); /* keep GCC prototype warning quiet */
xdc_Bool ti_sysbios_family_arm_m3_Hwi_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[6] < 0;
}
xdc_Bool ti_sysbios_family_arm_ducati_Core_Module__startupDone__F(void); /* keep GCC prototype warning quiet */
xdc_Bool ti_sysbios_family_arm_ducati_Core_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[7] < 0;
}
xdc_Bool ti_sysbios_family_arm_ducati_GateDualCore_Module__startupDone__F(void); /* keep GCC prototype warning quiet */
xdc_Bool ti_sysbios_family_arm_ducati_GateDualCore_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[8] < 0;
}
xdc_Bool ti_sysbios_family_arm_ducati_Timer_Module__startupDone__F(void); /* keep GCC prototype warning quiet */
xdc_Bool ti_sysbios_family_arm_ducati_Timer_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[9] < 0;
}


/* 
 * Startup_exec__I is an internal entry point called by target/platform
 * boot code. Boot code is not brought into a partial-link assembly. So,
 * without this pragma, whole program optimizers would otherwise optimize-out
 * this function.
 */
#ifdef __ti__
#pragma FUNC_EXT_CALLED(xdc_runtime_Startup_exec__I);
#endif

#ifdef __GNUC__
#if __GNUC__ >= 4
xdc_Void xdc_runtime_Startup_exec__I(void) __attribute__ ((externally_visible));
#endif
#endif

/*
 *  ======== xdc_runtime_Startup_exec__I ========
 *  Initialize all used modules that have startup functions
 */
xdc_Void xdc_runtime_Startup_exec__I(void)
{
    xdc_Int state[10];
    xdc_runtime_Startup_startModsFxn__C(state, 10);
}

/*
 * ======== xdc.runtime.Reset TEMPLATE ========
 */

/* 
 * Startup_reset__I is an internal entry point called by target/platform
 * boot code. Boot code is not brought into a partial-link assembly. So,
 * without this pragma, whole program optimizers would otherwise optimize-out
 * this function.
 */
#ifdef __ti__
#pragma FUNC_EXT_CALLED(xdc_runtime_Startup_reset__I);
#endif

#ifdef __GNUC__
#if __GNUC__ >= 4
xdc_Void xdc_runtime_Startup_reset__I(void) __attribute__ ((externally_visible));
#endif
#endif

extern xdc_Void ti_sysbios_hal_unicache_Cache_startup__I(void);  /* user defined reset function */

/*
 *  ======== xdc_runtime_Startup_reset__I ========
 *  This function is called by bootstrap initialization code as early as
 *  possible in the startup process.  This function calls all functions in
 *  the Reset.fxns array _as well as_ Startup.resetFxn (if it's non-NULL)
 */
xdc_Void xdc_runtime_Startup_reset__I(void)
{
    ti_sysbios_hal_unicache_Cache_startup__I();
}

/*
 * ======== xdc.runtime.System TEMPLATE ========
 */


#include <xdc/std.h>
#include <limits.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/Text.h>
#include <xdc/runtime/Assert.h>

#include <xdc/runtime/System.h>
#include <xdc/runtime/System__internal.h>

/*
 *  ======== System_printfExtend__I ========
 *  This function processes optional extended formats of printf.
 *  
 *  It returns the number of characters added to the result.
 *
 *  Precision (maximum string length) is not supported for %$S.
 *
 *  Right-justified (which is default) minimum width is not supported
 *  for %$L, %$S, or %$F.
 */
xdc_Int xdc_runtime_System_printfExtend__I(xdc_Char **pbuf, xdc_CString *pfmt, 
    xdc_VaList *pva, xdc_runtime_System_ParseData *parse)
{
    xdc_CString fmt = *pfmt;
    xdc_Int     res;
    xdc_Char    c;
    xdc_Bool    found = FALSE;
    
    /* 
     * Create a local variable 'va' to ensure that the dereference of
     * pva only occurs once.
     */
    va_list va = *pva;
    
    res = 0;

    c = *fmt++;
    *pfmt = *pfmt + 1;

    
    if (c == '$') {
        c = *fmt++;
        *pfmt = *pfmt + 1;
        
        if (c == 'L') {
            xdc_runtime_Types_Label *lab = parse->aFlag ? 
                (xdc_runtime_Types_Label *)xdc_iargToPtr(va_arg(va, xdc_IArg)) :
                (xdc_runtime_Types_Label *)va_arg(va, void *);
            
            /* 
             * Call Text_putLab to write out the label, taking the precision 
             * into account.
             */
            res = xdc_runtime_Text_putLab(lab, pbuf, parse->precis);
            
            /*
             * Set the length to 0 to indicate to 'doPrint' that nothing should
             * be copied from parse.ptr.
             */
            parse->len = 0;
            
            /* Update the minimum width field. */
            parse->width -= res;
            
            found = TRUE;
        }
        
        if (c == 'F') {
            xdc_runtime_Types_Site site;
            
            /* Retrieve the file name string from the argument list */
            site.file = parse->aFlag ? (xdc_Char *) xdc_iargToPtr(va_arg(va, xdc_IArg)) :
                                       (xdc_Char *) va_arg(va, xdc_Char *);
            
            /* Retrieve the line number from the argument list. */
            site.line = parse->aFlag ? (xdc_Int) va_arg(va, xdc_IArg) : 
                                       (xdc_Int) va_arg(va, xdc_Int);
            
            /* 
             * Omit the 'mod' field, set it to 0.
             * '0' is a safe sentinel value - the IDs for named modules are 
             * 0x8000 and higher, and the IDs for unnamed modules go from 0x1
             * to 0x7fff.
             */
            site.mod = 0;
            
            /* 
             * Call putSite to format the file and line number.
             * If a precision was specified, it will be used as the maximum
             * string lengrth.
             */
            res = xdc_runtime_Text_putSite(&site, pbuf, parse->precis);
            
            /*
             * Set the length to 0 to indicate to 'doPrint' that nothing should
             * be copied from parse.ptr.
             */
            parse->len = 0;
       
            /* Update the minimum width field */
            parse->width -= res;
            
            found = TRUE;
        }
        
        if (c == 'S') {
            /* Retrieve the format string from the argument list */
            parse->ptr = parse->aFlag ? 
                (xdc_Char *) xdc_iargToPtr(va_arg(va, xdc_IArg)) :
                (xdc_Char *) va_arg(va, xdc_Char *);
            
            /* Update pva before passing it to doPrint. */
            *pva = va;
            
            /* Perform the recursive format. System_doPrint does not advance
             * the buffer pointer, so it has to be done explicitly.
             */
            res = xdc_runtime_System_doPrint__I(*pbuf, parse->precis, 
                                                parse->ptr, pva, parse->aFlag);

            if (*pbuf) {
                *pbuf += res;
            }
            
            /* Update the temporary variable with any changes to *pva */
            va = *pva;
            
            /*
             * Set the length to 0 to indicate to 'doPrint' that nothing should
             * be copied from parse.ptr
             */
            parse->len = 0;

            /* Update the minimum width field */
            parse->width -= res;
            
            /* Indicate that we were able to interpret the specifier */
            found = TRUE;
        }
        
    }

    if (c == 'f') {
        /* support arguments _after_ optional float support */
        if (parse->aFlag) {
            (void)va_arg(va, xdc_IArg);
        }
        else {
            (void)va_arg(va, double);
        }
    }    

    if (found == FALSE) {
        /* other character (like %) copy to output */
        *(parse->ptr) = c;
        parse->len = 1;
    }

    /*
     * Before returning, we must update the value of pva. We use a label here
     * so that all return points will go through this update.
     * The 'goto end' is here to ensure that there is always a reference to the
     * label (to avoid the compiler complaining). 
     */
    goto end; 
end:
    *pva = va;
    return (res);
}

/*
 * ======== xdc.runtime.SysMin TEMPLATE ========
 */


#if defined(__ti__)
extern int HOSTwrite(int, const char *, unsigned);
#elif (defined(gnu_targets_STD_) && defined(xdc_target__os_undefined))
extern int _write(int, char *, int);
#define HOSTwrite(x,y,z) _write((int)(x),(char *)(y),(int)(z))
#elif defined(__IAR_SYSTEMS_ICC__)
#include <yfuns.h>
#define HOSTwrite(x,y,z) __write((x),(unsigned char *)(y),(z))
#else
#include <stdio.h>
#endif

/*
 *  ======== SysMin_output__I ========
 *  HOSTWrite only writes a max of N chars at a time. The amount it writes
 *  is returned. This function loops until the entire buffer is written.
 *  Being a static function allows it to conditionally compile out.
 */
xdc_Void xdc_runtime_SysMin_output__I(xdc_Char *buf, xdc_UInt size)
{
#if defined(__ti__) || (defined(gnu_targets_STD_) && defined(xdc_target__os_undefined)) || defined (__IAR_SYSTEMS_ICC__)
    xdc_Int printCount;
    
    while (size != 0) {
        printCount = HOSTwrite(1, buf, size);
        if ((printCount <= 0) || ((xdc_UInt)printCount > size)) {
            break;  /* ensure we never get stuck in an infinite loop */
        }
        size -= printCount;
        buf = buf + printCount;
    }    
#else
    fwrite(buf, 1, size, stdout);
#endif
}

/*
 * ======== xdc.runtime.Text TEMPLATE ========
 */


/*
 *  ======== xdc_runtime_Text_visitRope__I ========
 *  This function is indirectly called within Text.c through
 *  the visitRopeFxn configuration parameter of xdc.runtime.Text.
 */
void xdc_runtime_Text_visitRope__I(xdc_runtime_Text_RopeId rope,
    xdc_Fxn visFxn, xdc_Ptr visState)
{
    xdc_String stack[6];
    xdc_runtime_Text_visitRope2__I(rope, visFxn, visState, stack);
}


/*
 * ======== ti.sysbios.knl.Clock TEMPLATE ========
 */

Void ti_sysbios_knl_Clock_doTick__I(UArg arg)
{
    /* update system time */
    (&ti_sysbios_knl_Clock_Module__state__V)->ticks++;

    ti_sysbios_knl_Clock_logTick__E();

    if (!ti_sysbios_knl_Queue_empty(ti_sysbios_knl_Clock_Module_State_clockQ())) {
        (&ti_sysbios_knl_Clock_Module__state__V)->swiCount++;

        ti_sysbios_knl_Swi_post((&ti_sysbios_knl_Clock_Module__state__V)->swi);
    }
}

/*
 * ======== ti.sysbios.knl.Task TEMPLATE ========
 */




/*
 * ======== ti.sysbios.BIOS TEMPLATE ========
 */


Void ti_sysbios_BIOS_atExitFunc__I(Int);

extern Void ti_sysbios_BIOS_registerRTSLock();
extern Void ti_sysbios_family_arm_ducati_Timer_startup__E();

Void ti_sysbios_BIOS_startFunc__I()
{
    /*
     *  Check if XDC runtime startup functions have been called. If not, then
     *  call BIOS_linkedWithIncorrectBootLibrary() function. This function
     *  will spin forever.
     */
    if (xdc_runtime_Startup_rtsDone() != TRUE) {
        ti_sysbios_BIOS_linkedWithIncorrectBootLibrary();
    }

    xdc_runtime_System_atexit(
        (xdc_runtime_System_AtexitHandler)ti_sysbios_BIOS_atExitFunc__I);
    ti_sysbios_BIOS_registerRTSLock();
    ti_sysbios_family_arm_ducati_Timer_startup__E();
    ti_sysbios_hal_Hwi_startup();
    ti_sysbios_knl_Swi_startup();
    ti_sysbios_knl_Task_startup();
}

#include <_lock.h>

Void ti_sysbios_BIOS_atExitFunc__I(Int notused)
{
    ti_sysbios_knl_Swi_disable();
    ti_sysbios_knl_Task_disable();
    ti_sysbios_BIOS_setThreadType(ti_sysbios_BIOS_ThreadType_Main);

    if ((&ti_sysbios_BIOS_Module__state__V)->rtsGate != NULL) {
        _register_lock(_nop);
        _register_unlock(_nop);
    }
}

/*
 *  ======== BIOS_rtsLock ========
 *  Called by rts _lock() function
 */
Void ti_sysbios_BIOS_rtsLock()
{
    IArg key;

    key = ti_sysbios_BIOS_RtsGateProxy_enter((&ti_sysbios_BIOS_Module__state__V)->rtsGate);
    if ((&ti_sysbios_BIOS_Module__state__V)->rtsGateCount == 0) {
        (&ti_sysbios_BIOS_Module__state__V)->rtsGateKey = key;
    }
    /* Increment need not be atomic */
    (&ti_sysbios_BIOS_Module__state__V)->rtsGateCount++;
}

/*
 *  ======== BIOS_rtsUnLock ========
 *  Called by rts _unlock() function
 */
Void ti_sysbios_BIOS_rtsUnlock()
{
    xdc_runtime_Assert_isTrue(((&ti_sysbios_BIOS_Module__state__V)->rtsGateCount), NULL);

    (&ti_sysbios_BIOS_Module__state__V)->rtsGateCount--;

    if ((&ti_sysbios_BIOS_Module__state__V)->rtsGateCount == 0) {
        ti_sysbios_BIOS_RtsGateProxy_leave((&ti_sysbios_BIOS_Module__state__V)->rtsGate, (&ti_sysbios_BIOS_Module__state__V)->rtsGateKey);
    }
}

/*
 *  ======== BIOS_nullFunc ========
 */
Void ti_sysbios_BIOS_nullFunc__I()
{
}

/*
 *  ======== BIOS_registerRTSLock ========
 */
Void ti_sysbios_BIOS_registerRTSLock(Void)
{
    if ((&ti_sysbios_BIOS_Module__state__V)->rtsGate != NULL) {
        _register_lock(ti_sysbios_BIOS_rtsLock);
        _register_unlock(ti_sysbios_BIOS_rtsUnlock);
    }
}

/*
 *  ======== BIOS_removeRTSLock ========
 */
Void ti_sysbios_BIOS_removeRTSLock(Void)
{
    if ((&ti_sysbios_BIOS_Module__state__V)->rtsGate != NULL) {
        _register_lock(ti_sysbios_BIOS_nullFunc);
        _register_unlock(ti_sysbios_BIOS_nullFunc);
    }
}

/*
 *  ======== BIOS_exitFunc ========
 */
Void ti_sysbios_BIOS_exitFunc(Int stat)
{
    /* remove the RTS lock */
    ti_sysbios_BIOS_removeRTSLock();

    /* force thread type to 'Main' */
    ti_sysbios_BIOS_setThreadType(ti_sysbios_BIOS_ThreadType_Main);

    xdc_runtime_System_exit(stat);
}

/*
 *  ======== BIOS_errorRaiseHook ========
 */
Void ti_sysbios_BIOS_errorRaiseHook(xdc_runtime_Error_Block *eb)
{
    /*
     * If this is an Assert thread, defang Gate threadtype check
     */
    if (eb->id == xdc_runtime_Assert_E_assertFailed) {
        /* remove the RTS lock */
        ti_sysbios_BIOS_removeRTSLock();
        /* force thread type to 'Main' */
        ti_sysbios_BIOS_setThreadType(ti_sysbios_BIOS_ThreadType_Main);
    }

    /* Call the installed Error.raiseHook */
    ti_sysbios_BIOS_installedErrorHook(eb);
}

/*
 * ======== ti.sysbios.Build TEMPLATE ========
 */


/*
 * ======== ti.sysbios.family.arm.m3.Hwi TEMPLATE ========
 */

extern Void _c_int00();
extern Void ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I();
extern Void ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I();
extern Void ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I();
extern Void ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I();
extern Void ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I();
extern Void ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I();
extern Void ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I();
extern Void ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I();


#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_resetVectors, ".resetVecs");

/* const because it is meant to be placed in ROM */
const UInt32 ti_sysbios_family_arm_m3_Hwi_resetVectors[] = {
    (UInt32)(&__TI_STACK_BASE),
    (UInt32)(&_c_int00),
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),            /* NMI */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),      /* Hard Fault */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),       /* Mem Fault */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),       /* Bus Fault */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),     /* Usage Fault */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),       /* reserved */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),       /* reserved */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),       /* reserved */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),       /* reserved */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),         /* SVCall */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),       /* Debug Mon */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),       /* reserved */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_pendSV__I),  /* pendSV */
    (UInt32)(ti_sysbios_family_arm_m3_Hwi_dispatch__I),  /* intNum = 15 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 16 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 17 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 18 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 19 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 20 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 21 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 22 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 23 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 24 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 25 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 26 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 27 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 28 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 29 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 30 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 31 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 32 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 33 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 34 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 35 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 36 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 37 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 38 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 39 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 40 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 41 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 42 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 43 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 44 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 45 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 46 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 47 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 48 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 49 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 50 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 51 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 52 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 53 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 54 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 55 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 56 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 57 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 58 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 59 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 60 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 61 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 62 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 63 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 64 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 65 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 66 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 67 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 68 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 69 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 70 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 71 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 72 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 73 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 74 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 75 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 76 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 77 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 78 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 79 */
};


UInt32 ti_sysbios_family_arm_m3_Hwi_dispatchTable[80];

#if defined(__IAR_SYSTEMS_ICC__)
Void ti_sysbios_family_arm_m3_Hwi_initIsrStackSize()
{
    #pragma section = "CSTACK"
        ti_sysbios_family_arm_m3_Hwi_Module__state__V.isrStackSize = (Void *)__section_size("CSTACK");
}
#endif

/*
 * ======== ti.sysbios.family.arm.ducati.GateDualCore TEMPLATE ========
 */


#ifdef __ti__

UInt32 ti_sysbios_family_arm_ducati_GateDualCore_gateArray[4];

#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_GateDualCore_gateArray, ".ducatiGates");

#else

UInt32 ti_sysbios_family_arm_ducati_GateDualCore_gateArray[4] __attribute__ ((section(".ducatiGates")));

#endif



/*
 * ======== ti.sysbios.rts.MemAlloc TEMPLATE ========
 */



#if defined(__ti__)

#pragma FUNC_EXT_CALLED(malloc);
#pragma FUNC_EXT_CALLED(memalign);
#pragma FUNC_EXT_CALLED(free);
#pragma FUNC_EXT_CALLED(calloc);
#pragma FUNC_EXT_CALLED(realloc);

#define ATTRIBUTE

#elif defined(__IAR_SYSTEMS_ICC__)

#define ATTRIBUTE

#else

#define ATTRIBUTE __attribute__ ((used))

#endif


#include <xdc/std.h>

#include <xdc/runtime/Memory.h>
#include <xdc/runtime/Error.h>

#include <string.h>

#if defined(__GNUC__) && !defined(__ti__)

#include <reent.h>

#endif

/*
 * Header is a union to make sure that the size is a power of 2.
 *
 * On the MSP430 small model (MSP430X), size_t is 2 bytes, which makes
 * the size of this struct 6 bytes.
 */
typedef union Header {
    struct {
        Ptr   actualBuf;
        SizeT size;
    } header;
    UArg pad[2];	/* 4 words on 28L, 8 bytes on most others */
} Header;

/*
 *  ======== malloc ========
 */
Void ATTRIBUTE *malloc(SizeT size)
{
    Header *packet;
    xdc_runtime_Error_Block eb;

    xdc_runtime_Error_init(&eb);

    if (size == 0) {
        return (NULL);
    }

    packet = (Header *)xdc_runtime_Memory_alloc(NULL,
        (SizeT)(size + sizeof(Header)), 0, &eb);

    if (packet == NULL) {
        return (NULL);
    }

    packet->header.actualBuf = (Ptr)packet;
    packet->header.size = size + sizeof(Header);

    return (packet + 1);
}

/*
 *  ======== memalign ========
 *  mirrors the memalign() function from the TI run-time library
 */
Void ATTRIBUTE *memalign(SizeT alignment, SizeT size)
{
    Header                      *packet;
    Void                        *tmp;
    xdc_runtime_Error_Block     eb;

    xdc_runtime_Error_init(&eb);

    if (alignment < sizeof(Header)) {
        alignment = sizeof(Header);
    }

    /*
     * return NULL if size is 0, or alignment is not a power of 2
     */
    if (size == 0 || (alignment & (alignment - 1))) {
        return (NULL);
    }

    /*
     * Allocate 'align + size' so that we have room for the 'packet'
     * and can return an aligned buffer.
     */
    tmp = xdc_runtime_Memory_alloc(NULL, alignment + size, alignment, &eb);

    if (tmp == NULL) {
        return (NULL);
    }

    packet = (Header *)((char *)tmp + alignment - sizeof(Header));

    packet->header.actualBuf = tmp;
    packet->header.size = size + sizeof(Header);

    return (packet + 1);
}

/*
 *  ======== calloc ========
 */
Void ATTRIBUTE *calloc(SizeT nmemb, SizeT size)
{
    SizeT       nbytes;
    Ptr         retval;

    nbytes = nmemb * size;

    /* return NULL if there's an overflow */
    if (nmemb && size != (nbytes / nmemb)) {
        return (NULL);
    }

    retval = malloc(nbytes);
    if (retval != NULL) {
        (Void)memset(retval, (Int)'\0', nbytes);
    }

    return (retval);
}

/*
 *  ======== free ========
 */
Void ATTRIBUTE free(Void *ptr)
{
    Header      *packet;

    if (ptr != NULL) {
        packet = ((Header *)ptr) - 1;

        xdc_runtime_Memory_free(NULL, (Ptr)packet->header.actualBuf,
            (packet->header.size +
            ((char*)packet - (char*)packet->header.actualBuf)));
    }
}

/*
 *  ======== realloc ========
 */
Void ATTRIBUTE *realloc(Void *ptr, SizeT size)
{
    Ptr         retval;
    Header      *packet;
    SizeT       oldSize;

    if (ptr == NULL) {
        retval = malloc(size);
    }
    else if (size == 0) {
        free(ptr);
        retval = NULL;
    }
    else {
        packet = (Header *)ptr - 1;
        retval = malloc(size);
        if (retval != NULL) {
            oldSize = packet->header.size - sizeof(Header);
            (Void)memcpy(retval, ptr, (size < oldSize) ? size : oldSize);
            free(ptr);
        }
    }

    return (retval);
}

#if defined(__GNUC__) && !defined(__ti__)

/*
 *  ======== _malloc_r ========
 */
Void ATTRIBUTE *_malloc_r(struct _reent *rptr, SizeT size)
{
    return malloc(size);
}

/*
 *  ======== _calloc_r ========
 */
Void ATTRIBUTE *_calloc_r(struct _reent *rptr, SizeT nmemb, SizeT size)
{
    return calloc(nmemb, size);
}

/*
 *  ======== _free_r ========
 */
Void ATTRIBUTE _free_r(struct _reent *rptr, Void *ptr)
{
    free(ptr);
}

/*
 *  ======== _realloc_r ========
 */
Void ATTRIBUTE *_realloc_r(struct _reent *rptr, Void *ptr, SizeT size)
{
    return realloc(ptr, size);
}

#endif


/*
 * ======== ti.sysbios.BIOS INITIALIZERS ========
 */

/* Module__state__V */
#if defined (__ICCARM__)
#pragma location = ".data_ti_sysbios_BIOS_Module__state__V"
#endif
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
#ifndef __TI_COMPILER_VERSION__
ti_sysbios_BIOS_Module_State__ ti_sysbios_BIOS_Module__state__V __attribute__ ((section(".data_ti_sysbios_BIOS_Module__state__V")));
#endif
#endif
ti_sysbios_BIOS_Module_State__ ti_sysbios_BIOS_Module__state__V = {
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)0xcaf1200,  /* lo */
    },  /* cpuFreq */
    (xdc_UInt)0x0,  /* rtsGateCount */
    ((xdc_IArg)(0x0)),  /* rtsGateKey */
    (ti_sysbios_BIOS_RtsGateProxy_Handle)&ti_sysbios_gates_GateMutex_Object__table__V[1],  /* rtsGate */
    ti_sysbios_BIOS_ThreadType_Main,  /* threadType */
    ((void*)0),  /* smpThreadType */
    ((xdc_Void(*)(xdc_Void))((xdc_Fxn)ti_sysbios_BIOS_startFunc)),  /* startFunc */
    ((xdc_Void(*)(xdc_Int))((xdc_Fxn)ti_sysbios_BIOS_exitFunc)),  /* exitFunc */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__diagsEnabled__C, ".const:ti_sysbios_BIOS_Module__diagsEnabled__C");
__FAR__ const CT__ti_sysbios_BIOS_Module__diagsEnabled ti_sysbios_BIOS_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__diagsIncluded__C, ".const:ti_sysbios_BIOS_Module__diagsIncluded__C");
__FAR__ const CT__ti_sysbios_BIOS_Module__diagsIncluded ti_sysbios_BIOS_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__diagsMask__C, ".const:ti_sysbios_BIOS_Module__diagsMask__C");
__FAR__ const CT__ti_sysbios_BIOS_Module__diagsMask ti_sysbios_BIOS_Module__diagsMask__C = ((CT__ti_sysbios_BIOS_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__gateObj__C, ".const:ti_sysbios_BIOS_Module__gateObj__C");
__FAR__ const CT__ti_sysbios_BIOS_Module__gateObj ti_sysbios_BIOS_Module__gateObj__C = ((CT__ti_sysbios_BIOS_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__gatePrms__C, ".const:ti_sysbios_BIOS_Module__gatePrms__C");
__FAR__ const CT__ti_sysbios_BIOS_Module__gatePrms ti_sysbios_BIOS_Module__gatePrms__C = ((CT__ti_sysbios_BIOS_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__id__C, ".const:ti_sysbios_BIOS_Module__id__C");
__FAR__ const CT__ti_sysbios_BIOS_Module__id ti_sysbios_BIOS_Module__id__C = (xdc_Bits16)0x8019;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__loggerDefined__C, ".const:ti_sysbios_BIOS_Module__loggerDefined__C");
__FAR__ const CT__ti_sysbios_BIOS_Module__loggerDefined ti_sysbios_BIOS_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__loggerObj__C, ".const:ti_sysbios_BIOS_Module__loggerObj__C");
__FAR__ const CT__ti_sysbios_BIOS_Module__loggerObj ti_sysbios_BIOS_Module__loggerObj__C = ((CT__ti_sysbios_BIOS_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__loggerFxn0__C, ".const:ti_sysbios_BIOS_Module__loggerFxn0__C");
__FAR__ const CT__ti_sysbios_BIOS_Module__loggerFxn0 ti_sysbios_BIOS_Module__loggerFxn0__C = ((CT__ti_sysbios_BIOS_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__loggerFxn1__C, ".const:ti_sysbios_BIOS_Module__loggerFxn1__C");
__FAR__ const CT__ti_sysbios_BIOS_Module__loggerFxn1 ti_sysbios_BIOS_Module__loggerFxn1__C = ((CT__ti_sysbios_BIOS_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__loggerFxn2__C, ".const:ti_sysbios_BIOS_Module__loggerFxn2__C");
__FAR__ const CT__ti_sysbios_BIOS_Module__loggerFxn2 ti_sysbios_BIOS_Module__loggerFxn2__C = ((CT__ti_sysbios_BIOS_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__loggerFxn4__C, ".const:ti_sysbios_BIOS_Module__loggerFxn4__C");
__FAR__ const CT__ti_sysbios_BIOS_Module__loggerFxn4 ti_sysbios_BIOS_Module__loggerFxn4__C = ((CT__ti_sysbios_BIOS_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__loggerFxn8__C, ".const:ti_sysbios_BIOS_Module__loggerFxn8__C");
__FAR__ const CT__ti_sysbios_BIOS_Module__loggerFxn8 ti_sysbios_BIOS_Module__loggerFxn8__C = ((CT__ti_sysbios_BIOS_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__startupDoneFxn__C, ".const:ti_sysbios_BIOS_Module__startupDoneFxn__C");
__FAR__ const CT__ti_sysbios_BIOS_Module__startupDoneFxn ti_sysbios_BIOS_Module__startupDoneFxn__C = ((CT__ti_sysbios_BIOS_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_Object__count__C, ".const:ti_sysbios_BIOS_Object__count__C");
__FAR__ const CT__ti_sysbios_BIOS_Object__count ti_sysbios_BIOS_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_Object__heap__C, ".const:ti_sysbios_BIOS_Object__heap__C");
__FAR__ const CT__ti_sysbios_BIOS_Object__heap ti_sysbios_BIOS_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_Object__sizeof__C, ".const:ti_sysbios_BIOS_Object__sizeof__C");
__FAR__ const CT__ti_sysbios_BIOS_Object__sizeof ti_sysbios_BIOS_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_Object__table__C, ".const:ti_sysbios_BIOS_Object__table__C");
__FAR__ const CT__ti_sysbios_BIOS_Object__table ti_sysbios_BIOS_Object__table__C = 0;

/* smpEnabled__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_smpEnabled__C, ".const:ti_sysbios_BIOS_smpEnabled__C");
__FAR__ const CT__ti_sysbios_BIOS_smpEnabled ti_sysbios_BIOS_smpEnabled__C = 0;

/* cpuFreq__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_cpuFreq__C, ".const:ti_sysbios_BIOS_cpuFreq__C");
__FAR__ const CT__ti_sysbios_BIOS_cpuFreq ti_sysbios_BIOS_cpuFreq__C = {
    (xdc_Bits32)0x0,  /* hi */
    (xdc_Bits32)0xcaf1200,  /* lo */
};

/* runtimeCreatesEnabled__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_runtimeCreatesEnabled__C, ".const:ti_sysbios_BIOS_runtimeCreatesEnabled__C");
__FAR__ const CT__ti_sysbios_BIOS_runtimeCreatesEnabled ti_sysbios_BIOS_runtimeCreatesEnabled__C = 1;

/* taskEnabled__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_taskEnabled__C, ".const:ti_sysbios_BIOS_taskEnabled__C");
__FAR__ const CT__ti_sysbios_BIOS_taskEnabled ti_sysbios_BIOS_taskEnabled__C = 1;

/* swiEnabled__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_swiEnabled__C, ".const:ti_sysbios_BIOS_swiEnabled__C");
__FAR__ const CT__ti_sysbios_BIOS_swiEnabled ti_sysbios_BIOS_swiEnabled__C = 1;

/* clockEnabled__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_clockEnabled__C, ".const:ti_sysbios_BIOS_clockEnabled__C");
__FAR__ const CT__ti_sysbios_BIOS_clockEnabled ti_sysbios_BIOS_clockEnabled__C = 1;

/* heapSize__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_heapSize__C, ".const:ti_sysbios_BIOS_heapSize__C");
__FAR__ const CT__ti_sysbios_BIOS_heapSize ti_sysbios_BIOS_heapSize__C = (xdc_SizeT)0x15000;

/* heapSection__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_heapSection__C, ".const:ti_sysbios_BIOS_heapSection__C");
__FAR__ const CT__ti_sysbios_BIOS_heapSection ti_sysbios_BIOS_heapSection__C = 0;

/* heapTrackEnabled__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_heapTrackEnabled__C, ".const:ti_sysbios_BIOS_heapTrackEnabled__C");
__FAR__ const CT__ti_sysbios_BIOS_heapTrackEnabled ti_sysbios_BIOS_heapTrackEnabled__C = 0;

/* setupSecureContext__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_setupSecureContext__C, ".const:ti_sysbios_BIOS_setupSecureContext__C");
__FAR__ const CT__ti_sysbios_BIOS_setupSecureContext ti_sysbios_BIOS_setupSecureContext__C = 0;

/* useSK__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_useSK__C, ".const:ti_sysbios_BIOS_useSK__C");
__FAR__ const CT__ti_sysbios_BIOS_useSK ti_sysbios_BIOS_useSK__C = 0;

/* installedErrorHook__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_installedErrorHook__C, ".const:ti_sysbios_BIOS_installedErrorHook__C");
__FAR__ const CT__ti_sysbios_BIOS_installedErrorHook ti_sysbios_BIOS_installedErrorHook__C = ((CT__ti_sysbios_BIOS_installedErrorHook)((xdc_Fxn)xdc_runtime_Error_print__E));


/*
 * ======== ti.sysbios.BIOS_RtsGateProxy INITIALIZERS ========
 */


/*
 * ======== ti.sysbios.family.arm.ducati.CTM INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_CTM_Module__diagsEnabled__C, ".const:ti_sysbios_family_arm_ducati_CTM_Module__diagsEnabled__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_CTM_Module__diagsEnabled ti_sysbios_family_arm_ducati_CTM_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_CTM_Module__diagsIncluded__C, ".const:ti_sysbios_family_arm_ducati_CTM_Module__diagsIncluded__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_CTM_Module__diagsIncluded ti_sysbios_family_arm_ducati_CTM_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_CTM_Module__diagsMask__C, ".const:ti_sysbios_family_arm_ducati_CTM_Module__diagsMask__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_CTM_Module__diagsMask ti_sysbios_family_arm_ducati_CTM_Module__diagsMask__C = ((CT__ti_sysbios_family_arm_ducati_CTM_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_CTM_Module__gateObj__C, ".const:ti_sysbios_family_arm_ducati_CTM_Module__gateObj__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_CTM_Module__gateObj ti_sysbios_family_arm_ducati_CTM_Module__gateObj__C = ((CT__ti_sysbios_family_arm_ducati_CTM_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_CTM_Module__gatePrms__C, ".const:ti_sysbios_family_arm_ducati_CTM_Module__gatePrms__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_CTM_Module__gatePrms ti_sysbios_family_arm_ducati_CTM_Module__gatePrms__C = ((CT__ti_sysbios_family_arm_ducati_CTM_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_CTM_Module__id__C, ".const:ti_sysbios_family_arm_ducati_CTM_Module__id__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_CTM_Module__id ti_sysbios_family_arm_ducati_CTM_Module__id__C = (xdc_Bits16)0x8028;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_CTM_Module__loggerDefined__C, ".const:ti_sysbios_family_arm_ducati_CTM_Module__loggerDefined__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_CTM_Module__loggerDefined ti_sysbios_family_arm_ducati_CTM_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_CTM_Module__loggerObj__C, ".const:ti_sysbios_family_arm_ducati_CTM_Module__loggerObj__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_CTM_Module__loggerObj ti_sysbios_family_arm_ducati_CTM_Module__loggerObj__C = ((CT__ti_sysbios_family_arm_ducati_CTM_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn0__C, ".const:ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn0__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn0 ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn0__C = ((CT__ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn1__C, ".const:ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn1__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn1 ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn1__C = ((CT__ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn2__C, ".const:ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn2__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn2 ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn2__C = ((CT__ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn4__C, ".const:ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn4__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn4 ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn4__C = ((CT__ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn8__C, ".const:ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn8__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn8 ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn8__C = ((CT__ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_CTM_Module__startupDoneFxn__C, ".const:ti_sysbios_family_arm_ducati_CTM_Module__startupDoneFxn__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_CTM_Module__startupDoneFxn ti_sysbios_family_arm_ducati_CTM_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_arm_ducati_CTM_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_CTM_Object__count__C, ".const:ti_sysbios_family_arm_ducati_CTM_Object__count__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_CTM_Object__count ti_sysbios_family_arm_ducati_CTM_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_CTM_Object__heap__C, ".const:ti_sysbios_family_arm_ducati_CTM_Object__heap__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_CTM_Object__heap ti_sysbios_family_arm_ducati_CTM_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_CTM_Object__sizeof__C, ".const:ti_sysbios_family_arm_ducati_CTM_Object__sizeof__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_CTM_Object__sizeof ti_sysbios_family_arm_ducati_CTM_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_CTM_Object__table__C, ".const:ti_sysbios_family_arm_ducati_CTM_Object__table__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_CTM_Object__table ti_sysbios_family_arm_ducati_CTM_Object__table__C = 0;


/*
 * ======== ti.sysbios.family.arm.ducati.Core INITIALIZERS ========
 */

/* Module__state__V */
#if defined (__ICCARM__)
#pragma location = ".data_ti_sysbios_family_arm_ducati_Core_Module__state__V"
#endif
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
#ifndef __TI_COMPILER_VERSION__
ti_sysbios_family_arm_ducati_Core_Module_State__ ti_sysbios_family_arm_ducati_Core_Module__state__V __attribute__ ((section(".data_ti_sysbios_family_arm_ducati_Core_Module__state__V")));
#endif
#endif
ti_sysbios_family_arm_ducati_Core_Module_State__ ti_sysbios_family_arm_ducati_Core_Module__state__V = {
    0,  /* exitFlag */
    {
        0,  /* [0] */
        0,  /* [1] */
    },  /* gateEntered */
    {
        (xdc_UInt)0x0,  /* [0] */
        (xdc_UInt)0x0,  /* [1] */
    },  /* schedulerInts */
    ((void*)0),  /* core1HwiStack */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_Module__diagsEnabled__C, ".const:ti_sysbios_family_arm_ducati_Core_Module__diagsEnabled__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_Module__diagsEnabled ti_sysbios_family_arm_ducati_Core_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_Module__diagsIncluded__C, ".const:ti_sysbios_family_arm_ducati_Core_Module__diagsIncluded__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_Module__diagsIncluded ti_sysbios_family_arm_ducati_Core_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_Module__diagsMask__C, ".const:ti_sysbios_family_arm_ducati_Core_Module__diagsMask__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_Module__diagsMask ti_sysbios_family_arm_ducati_Core_Module__diagsMask__C = ((CT__ti_sysbios_family_arm_ducati_Core_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_Module__gateObj__C, ".const:ti_sysbios_family_arm_ducati_Core_Module__gateObj__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_Module__gateObj ti_sysbios_family_arm_ducati_Core_Module__gateObj__C = ((CT__ti_sysbios_family_arm_ducati_Core_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_Module__gatePrms__C, ".const:ti_sysbios_family_arm_ducati_Core_Module__gatePrms__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_Module__gatePrms ti_sysbios_family_arm_ducati_Core_Module__gatePrms__C = ((CT__ti_sysbios_family_arm_ducati_Core_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_Module__id__C, ".const:ti_sysbios_family_arm_ducati_Core_Module__id__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_Module__id ti_sysbios_family_arm_ducati_Core_Module__id__C = (xdc_Bits16)0x8027;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_Module__loggerDefined__C, ".const:ti_sysbios_family_arm_ducati_Core_Module__loggerDefined__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_Module__loggerDefined ti_sysbios_family_arm_ducati_Core_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_Module__loggerObj__C, ".const:ti_sysbios_family_arm_ducati_Core_Module__loggerObj__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_Module__loggerObj ti_sysbios_family_arm_ducati_Core_Module__loggerObj__C = ((CT__ti_sysbios_family_arm_ducati_Core_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_Module__loggerFxn0__C, ".const:ti_sysbios_family_arm_ducati_Core_Module__loggerFxn0__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_Module__loggerFxn0 ti_sysbios_family_arm_ducati_Core_Module__loggerFxn0__C = ((CT__ti_sysbios_family_arm_ducati_Core_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_Module__loggerFxn1__C, ".const:ti_sysbios_family_arm_ducati_Core_Module__loggerFxn1__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_Module__loggerFxn1 ti_sysbios_family_arm_ducati_Core_Module__loggerFxn1__C = ((CT__ti_sysbios_family_arm_ducati_Core_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_Module__loggerFxn2__C, ".const:ti_sysbios_family_arm_ducati_Core_Module__loggerFxn2__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_Module__loggerFxn2 ti_sysbios_family_arm_ducati_Core_Module__loggerFxn2__C = ((CT__ti_sysbios_family_arm_ducati_Core_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_Module__loggerFxn4__C, ".const:ti_sysbios_family_arm_ducati_Core_Module__loggerFxn4__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_Module__loggerFxn4 ti_sysbios_family_arm_ducati_Core_Module__loggerFxn4__C = ((CT__ti_sysbios_family_arm_ducati_Core_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_Module__loggerFxn8__C, ".const:ti_sysbios_family_arm_ducati_Core_Module__loggerFxn8__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_Module__loggerFxn8 ti_sysbios_family_arm_ducati_Core_Module__loggerFxn8__C = ((CT__ti_sysbios_family_arm_ducati_Core_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_Module__startupDoneFxn__C, ".const:ti_sysbios_family_arm_ducati_Core_Module__startupDoneFxn__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_Module__startupDoneFxn ti_sysbios_family_arm_ducati_Core_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_arm_ducati_Core_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_Object__count__C, ".const:ti_sysbios_family_arm_ducati_Core_Object__count__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_Object__count ti_sysbios_family_arm_ducati_Core_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_Object__heap__C, ".const:ti_sysbios_family_arm_ducati_Core_Object__heap__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_Object__heap ti_sysbios_family_arm_ducati_Core_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_Object__sizeof__C, ".const:ti_sysbios_family_arm_ducati_Core_Object__sizeof__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_Object__sizeof ti_sysbios_family_arm_ducati_Core_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_Object__table__C, ".const:ti_sysbios_family_arm_ducati_Core_Object__table__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_Object__table ti_sysbios_family_arm_ducati_Core_Object__table__C = 0;

/* numCores__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_numCores__C, ".const:ti_sysbios_family_arm_ducati_Core_numCores__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_numCores ti_sysbios_family_arm_ducati_Core_numCores__C = (xdc_UInt)0x2;

/* E_mismatchedIds__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_E_mismatchedIds__C, ".const:ti_sysbios_family_arm_ducati_Core_E_mismatchedIds__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_E_mismatchedIds ti_sysbios_family_arm_ducati_Core_E_mismatchedIds__C = (((xdc_runtime_Error_Id)5443) << 16 | 0);

/* id__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_id__C, ".const:ti_sysbios_family_arm_ducati_Core_id__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_id ti_sysbios_family_arm_ducati_Core_id__C = (xdc_UInt)0x1;

/* ipuId__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_ipuId__C, ".const:ti_sysbios_family_arm_ducati_Core_ipuId__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_ipuId ti_sysbios_family_arm_ducati_Core_ipuId__C = (xdc_UInt)0x1;

/* core1HwiStackSize__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_core1HwiStackSize__C, ".const:ti_sysbios_family_arm_ducati_Core_core1HwiStackSize__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_core1HwiStackSize ti_sysbios_family_arm_ducati_Core_core1HwiStackSize__C = (xdc_SizeT)0x0;

/* syncExits__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_syncExits__C, ".const:ti_sysbios_family_arm_ducati_Core_syncExits__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_syncExits ti_sysbios_family_arm_ducati_Core_syncExits__C = 1;

/* gate__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_gate__C, ".const:ti_sysbios_family_arm_ducati_Core_gate__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_gate ti_sysbios_family_arm_ducati_Core_gate__C = 0;

/* initStackFlag__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_initStackFlag__C, ".const:ti_sysbios_family_arm_ducati_Core_initStackFlag__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_initStackFlag ti_sysbios_family_arm_ducati_Core_initStackFlag__C = 1;


/*
 * ======== ti.sysbios.family.arm.ducati.GateDualCore INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_family_arm_ducati_GateDualCore_Object__DESC__C;

/* Object__PARAMS__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_GateDualCore_Object__PARAMS__C, ".const:ti_sysbios_family_arm_ducati_GateDualCore_Object__PARAMS__C");
__FAR__ const ti_sysbios_family_arm_ducati_GateDualCore_Params ti_sysbios_family_arm_ducati_GateDualCore_Object__PARAMS__C = {
    sizeof (ti_sysbios_family_arm_ducati_GateDualCore_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_family_arm_ducati_GateDualCore_Object__PARAMS__C.__iprms, /* instance */
    (xdc_UInt)0x0,  /* index */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_family_arm_ducati_GateDualCore_Module__ ti_sysbios_family_arm_ducati_GateDualCore_Module__root__V = {
    {&ti_sysbios_family_arm_ducati_GateDualCore_Module__root__V.link,  /* link.next */
    &ti_sysbios_family_arm_ducati_GateDualCore_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_family_arm_ducati_GateDualCore_Object__ ti_sysbios_family_arm_ducati_GateDualCore_Object__table__V[1] = {
    {/* instance#0 */
        &ti_sysbios_family_arm_ducati_GateDualCore_Module__FXNS__C,
        (xdc_UInt)0x0,  /* index */
        ((xdc_UInt32*)0),  /* gatePtr */
        ((xdc_UInt8*)0),  /* gateBytePtr */
        (xdc_UInt)0x0,  /* stalls */
        (xdc_UInt)0x0,  /* noStalls */
        (xdc_UInt)0x0,  /* totalStalls */
        (xdc_UInt)0x0,  /* maxStall */
    },
};

/* Module__state__V */
#if defined (__ICCARM__)
#pragma location = ".data_ti_sysbios_family_arm_ducati_GateDualCore_Module__state__V"
#endif
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
#ifndef __TI_COMPILER_VERSION__
ti_sysbios_family_arm_ducati_GateDualCore_Module_State__ ti_sysbios_family_arm_ducati_GateDualCore_Module__state__V __attribute__ ((section(".data_ti_sysbios_family_arm_ducati_GateDualCore_Module__state__V")));
#endif
#endif
ti_sysbios_family_arm_ducati_GateDualCore_Module_State__ ti_sysbios_family_arm_ducati_GateDualCore_Module__state__V = {
    {
        (xdc_UInt8)0x1,  /* [0] */
        (xdc_UInt8)0x0,  /* [1] */
        (xdc_UInt8)0x0,  /* [2] */
        (xdc_UInt8)0x0,  /* [3] */
    },  /* usedGates */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_GateDualCore_Module__diagsEnabled__C, ".const:ti_sysbios_family_arm_ducati_GateDualCore_Module__diagsEnabled__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_GateDualCore_Module__diagsEnabled ti_sysbios_family_arm_ducati_GateDualCore_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_GateDualCore_Module__diagsIncluded__C, ".const:ti_sysbios_family_arm_ducati_GateDualCore_Module__diagsIncluded__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_GateDualCore_Module__diagsIncluded ti_sysbios_family_arm_ducati_GateDualCore_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_GateDualCore_Module__diagsMask__C, ".const:ti_sysbios_family_arm_ducati_GateDualCore_Module__diagsMask__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_GateDualCore_Module__diagsMask ti_sysbios_family_arm_ducati_GateDualCore_Module__diagsMask__C = ((CT__ti_sysbios_family_arm_ducati_GateDualCore_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_GateDualCore_Module__gateObj__C, ".const:ti_sysbios_family_arm_ducati_GateDualCore_Module__gateObj__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_GateDualCore_Module__gateObj ti_sysbios_family_arm_ducati_GateDualCore_Module__gateObj__C = ((CT__ti_sysbios_family_arm_ducati_GateDualCore_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_GateDualCore_Module__gatePrms__C, ".const:ti_sysbios_family_arm_ducati_GateDualCore_Module__gatePrms__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_GateDualCore_Module__gatePrms ti_sysbios_family_arm_ducati_GateDualCore_Module__gatePrms__C = ((CT__ti_sysbios_family_arm_ducati_GateDualCore_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_GateDualCore_Module__id__C, ".const:ti_sysbios_family_arm_ducati_GateDualCore_Module__id__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_GateDualCore_Module__id ti_sysbios_family_arm_ducati_GateDualCore_Module__id__C = (xdc_Bits16)0x8029;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerDefined__C, ".const:ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerDefined__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerDefined ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerObj__C, ".const:ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerObj__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerObj ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerObj__C = ((CT__ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerFxn0__C, ".const:ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerFxn0__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerFxn0 ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerFxn0__C = ((CT__ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerFxn1__C, ".const:ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerFxn1__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerFxn1 ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerFxn1__C = ((CT__ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerFxn2__C, ".const:ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerFxn2__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerFxn2 ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerFxn2__C = ((CT__ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerFxn4__C, ".const:ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerFxn4__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerFxn4 ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerFxn4__C = ((CT__ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerFxn8__C, ".const:ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerFxn8__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerFxn8 ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerFxn8__C = ((CT__ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_GateDualCore_Module__startupDoneFxn__C, ".const:ti_sysbios_family_arm_ducati_GateDualCore_Module__startupDoneFxn__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_GateDualCore_Module__startupDoneFxn ti_sysbios_family_arm_ducati_GateDualCore_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_arm_ducati_GateDualCore_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_GateDualCore_Object__count__C, ".const:ti_sysbios_family_arm_ducati_GateDualCore_Object__count__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_GateDualCore_Object__count ti_sysbios_family_arm_ducati_GateDualCore_Object__count__C = 1;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_GateDualCore_Object__heap__C, ".const:ti_sysbios_family_arm_ducati_GateDualCore_Object__heap__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_GateDualCore_Object__heap ti_sysbios_family_arm_ducati_GateDualCore_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_GateDualCore_Object__sizeof__C, ".const:ti_sysbios_family_arm_ducati_GateDualCore_Object__sizeof__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_GateDualCore_Object__sizeof ti_sysbios_family_arm_ducati_GateDualCore_Object__sizeof__C = sizeof(ti_sysbios_family_arm_ducati_GateDualCore_Object__);

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_GateDualCore_Object__table__C, ".const:ti_sysbios_family_arm_ducati_GateDualCore_Object__table__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_GateDualCore_Object__table ti_sysbios_family_arm_ducati_GateDualCore_Object__table__C = ti_sysbios_family_arm_ducati_GateDualCore_Object__table__V;

/* A_nestedEnter__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_GateDualCore_A_nestedEnter__C, ".const:ti_sysbios_family_arm_ducati_GateDualCore_A_nestedEnter__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_GateDualCore_A_nestedEnter ti_sysbios_family_arm_ducati_GateDualCore_A_nestedEnter__C = (((xdc_runtime_Assert_Id)2752) << 16 | 16);

/* E_invalidIndex__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_GateDualCore_E_invalidIndex__C, ".const:ti_sysbios_family_arm_ducati_GateDualCore_E_invalidIndex__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_GateDualCore_E_invalidIndex ti_sysbios_family_arm_ducati_GateDualCore_E_invalidIndex__C = (((xdc_runtime_Error_Id)5508) << 16 | 0);

/* E_gateInUse__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_GateDualCore_E_gateInUse__C, ".const:ti_sysbios_family_arm_ducati_GateDualCore_E_gateInUse__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_GateDualCore_E_gateInUse ti_sysbios_family_arm_ducati_GateDualCore_E_gateInUse__C = (((xdc_runtime_Error_Id)5526) << 16 | 0);

/* gateArrayAddress__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_GateDualCore_gateArrayAddress__C, ".const:ti_sysbios_family_arm_ducati_GateDualCore_gateArrayAddress__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_GateDualCore_gateArrayAddress ti_sysbios_family_arm_ducati_GateDualCore_gateArrayAddress__C = ((CT__ti_sysbios_family_arm_ducati_GateDualCore_gateArrayAddress)(0x7f0));

/* numGates__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_GateDualCore_numGates__C, ".const:ti_sysbios_family_arm_ducati_GateDualCore_numGates__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_GateDualCore_numGates ti_sysbios_family_arm_ducati_GateDualCore_numGates__C = (xdc_UInt)0x4;

/* initGates__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_GateDualCore_initGates__C, ".const:ti_sysbios_family_arm_ducati_GateDualCore_initGates__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_GateDualCore_initGates ti_sysbios_family_arm_ducati_GateDualCore_initGates__C = 1;

/* enableStats__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_GateDualCore_enableStats__C, ".const:ti_sysbios_family_arm_ducati_GateDualCore_enableStats__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_GateDualCore_enableStats ti_sysbios_family_arm_ducati_GateDualCore_enableStats__C = 0;


/*
 * ======== ti.sysbios.family.arm.ducati.Timer INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_family_arm_ducati_Timer_Object__DESC__C;

/* Object__PARAMS__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Object__PARAMS__C, ".const:ti_sysbios_family_arm_ducati_Timer_Object__PARAMS__C");
__FAR__ const ti_sysbios_family_arm_ducati_Timer_Params ti_sysbios_family_arm_ducati_Timer_Object__PARAMS__C = {
    sizeof (ti_sysbios_family_arm_ducati_Timer_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_family_arm_ducati_Timer_Object__PARAMS__C.__iprms, /* instance */
    ti_sysbios_interfaces_ITimer_RunMode_CONTINUOUS,  /* runMode */
    ti_sysbios_interfaces_ITimer_StartMode_AUTO,  /* startMode */
    ((xdc_UArg)0),  /* arg */
    (xdc_UInt32)0x0,  /* period */
    ti_sysbios_interfaces_ITimer_PeriodType_MICROSECS,  /* periodType */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)0x0,  /* lo */
    },  /* extFreq */
    ((ti_sysbios_family_arm_m3_Hwi_Params*)0),  /* hwiParams */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_family_arm_ducati_Timer_Module__ ti_sysbios_family_arm_ducati_Timer_Module__root__V = {
    {&ti_sysbios_family_arm_ducati_Timer_Module__root__V.link,  /* link.next */
    &ti_sysbios_family_arm_ducati_Timer_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_family_arm_ducati_Timer_Object__ ti_sysbios_family_arm_ducati_Timer_Object__table__V[1] = {
    {/* instance#0 */
        0,
        1,  /* staticInst */
        (xdc_Int)0x0,  /* id */
        (xdc_Int)0x0,  /* ctmid */
        ti_sysbios_interfaces_ITimer_RunMode_CONTINUOUS,  /* runMode */
        ti_sysbios_interfaces_ITimer_StartMode_AUTO,  /* startMode */
        (xdc_UInt)0x33f40,  /* period */
        ti_sysbios_interfaces_ITimer_PeriodType_COUNTS,  /* periodType */
        (xdc_UInt)0xf,  /* intNum */
        ((xdc_UArg)0),  /* arg */
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_knl_Clock_doTick__I)),  /* tickFxn */
        {
            (xdc_Bits32)0x0,  /* hi */
            (xdc_Bits32)0x0,  /* lo */
        },  /* extFreq */
        (ti_sysbios_family_arm_m3_Hwi_Handle)&ti_sysbios_family_arm_m3_Hwi_Object__table__V[1],  /* hwi */
    },
};

/* Module__state__V */
#if defined (__ICCARM__)
#pragma location = ".data_ti_sysbios_family_arm_ducati_Timer_Module__state__V"
#endif
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
#ifndef __TI_COMPILER_VERSION__
ti_sysbios_family_arm_ducati_Timer_Module_State__ ti_sysbios_family_arm_ducati_Timer_Module__state__V __attribute__ ((section(".data_ti_sysbios_family_arm_ducati_Timer_Module__state__V")));
#endif
#endif
ti_sysbios_family_arm_ducati_Timer_Module_State__ ti_sysbios_family_arm_ducati_Timer_Module__state__V = {
    (xdc_UInt)0x2,  /* availMask */
    {
        (ti_sysbios_family_arm_ducati_Timer_Handle)&ti_sysbios_family_arm_ducati_Timer_Object__table__V[0],  /* [0] */
        0,  /* [1] */
    },  /* handles */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Module__diagsEnabled__C, ".const:ti_sysbios_family_arm_ducati_Timer_Module__diagsEnabled__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_Module__diagsEnabled ti_sysbios_family_arm_ducati_Timer_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Module__diagsIncluded__C, ".const:ti_sysbios_family_arm_ducati_Timer_Module__diagsIncluded__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_Module__diagsIncluded ti_sysbios_family_arm_ducati_Timer_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Module__diagsMask__C, ".const:ti_sysbios_family_arm_ducati_Timer_Module__diagsMask__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_Module__diagsMask ti_sysbios_family_arm_ducati_Timer_Module__diagsMask__C = ((CT__ti_sysbios_family_arm_ducati_Timer_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Module__gateObj__C, ".const:ti_sysbios_family_arm_ducati_Timer_Module__gateObj__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_Module__gateObj ti_sysbios_family_arm_ducati_Timer_Module__gateObj__C = ((CT__ti_sysbios_family_arm_ducati_Timer_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Module__gatePrms__C, ".const:ti_sysbios_family_arm_ducati_Timer_Module__gatePrms__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_Module__gatePrms ti_sysbios_family_arm_ducati_Timer_Module__gatePrms__C = ((CT__ti_sysbios_family_arm_ducati_Timer_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Module__id__C, ".const:ti_sysbios_family_arm_ducati_Timer_Module__id__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_Module__id ti_sysbios_family_arm_ducati_Timer_Module__id__C = (xdc_Bits16)0x802a;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Module__loggerDefined__C, ".const:ti_sysbios_family_arm_ducati_Timer_Module__loggerDefined__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_Module__loggerDefined ti_sysbios_family_arm_ducati_Timer_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Module__loggerObj__C, ".const:ti_sysbios_family_arm_ducati_Timer_Module__loggerObj__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_Module__loggerObj ti_sysbios_family_arm_ducati_Timer_Module__loggerObj__C = ((CT__ti_sysbios_family_arm_ducati_Timer_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn0__C, ".const:ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn0__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn0 ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn0__C = ((CT__ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn1__C, ".const:ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn1__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn1 ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn1__C = ((CT__ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn2__C, ".const:ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn2__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn2 ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn2__C = ((CT__ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn4__C, ".const:ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn4__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn4 ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn4__C = ((CT__ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn8__C, ".const:ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn8__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn8 ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn8__C = ((CT__ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Module__startupDoneFxn__C, ".const:ti_sysbios_family_arm_ducati_Timer_Module__startupDoneFxn__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_Module__startupDoneFxn ti_sysbios_family_arm_ducati_Timer_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_arm_ducati_Timer_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Object__count__C, ".const:ti_sysbios_family_arm_ducati_Timer_Object__count__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_Object__count ti_sysbios_family_arm_ducati_Timer_Object__count__C = 1;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Object__heap__C, ".const:ti_sysbios_family_arm_ducati_Timer_Object__heap__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_Object__heap ti_sysbios_family_arm_ducati_Timer_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Object__sizeof__C, ".const:ti_sysbios_family_arm_ducati_Timer_Object__sizeof__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_Object__sizeof ti_sysbios_family_arm_ducati_Timer_Object__sizeof__C = sizeof(ti_sysbios_family_arm_ducati_Timer_Object__);

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Object__table__C, ".const:ti_sysbios_family_arm_ducati_Timer_Object__table__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_Object__table ti_sysbios_family_arm_ducati_Timer_Object__table__C = ti_sysbios_family_arm_ducati_Timer_Object__table__V;

/* E_invalidTimer__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_E_invalidTimer__C, ".const:ti_sysbios_family_arm_ducati_Timer_E_invalidTimer__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_E_invalidTimer ti_sysbios_family_arm_ducati_Timer_E_invalidTimer__C = (((xdc_runtime_Error_Id)5310) << 16 | 0);

/* E_notAvailable__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_E_notAvailable__C, ".const:ti_sysbios_family_arm_ducati_Timer_E_notAvailable__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_E_notAvailable ti_sysbios_family_arm_ducati_Timer_E_notAvailable__C = (((xdc_runtime_Error_Id)5346) << 16 | 0);

/* E_cannotSupport__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_E_cannotSupport__C, ".const:ti_sysbios_family_arm_ducati_Timer_E_cannotSupport__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_E_cannotSupport ti_sysbios_family_arm_ducati_Timer_E_cannotSupport__C = (((xdc_runtime_Error_Id)5385) << 16 | 0);

/* anyMask__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_anyMask__C, ".const:ti_sysbios_family_arm_ducati_Timer_anyMask__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_anyMask ti_sysbios_family_arm_ducati_Timer_anyMask__C = (xdc_UInt)0x3;

/* startupNeeded__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_startupNeeded__C, ".const:ti_sysbios_family_arm_ducati_Timer_startupNeeded__C");
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_startupNeeded ti_sysbios_family_arm_ducati_Timer_startupNeeded__C = (xdc_UInt)0x1;


/*
 * ======== ti.sysbios.family.arm.m3.Hwi INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_family_arm_m3_Hwi_Object__DESC__C;

/* Object__PARAMS__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Object__PARAMS__C, ".const:ti_sysbios_family_arm_m3_Hwi_Object__PARAMS__C");
__FAR__ const ti_sysbios_family_arm_m3_Hwi_Params ti_sysbios_family_arm_m3_Hwi_Object__PARAMS__C = {
    sizeof (ti_sysbios_family_arm_m3_Hwi_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_family_arm_m3_Hwi_Object__PARAMS__C.__iprms, /* instance */
    ti_sysbios_interfaces_IHwi_MaskingOption_LOWER,  /* maskSetting */
    ((xdc_UArg)(0x0)),  /* arg */
    1,  /* enableInt */
    (xdc_Int)(-0x0 - 1),  /* eventId */
    (xdc_Int)0xff,  /* priority */
    1,  /* useDispatcher */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_family_arm_m3_Hwi_Module__ ti_sysbios_family_arm_m3_Hwi_Module__root__V = {
    {&ti_sysbios_family_arm_m3_Hwi_Module__root__V.link,  /* link.next */
    &ti_sysbios_family_arm_m3_Hwi_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_family_arm_m3_Hwi_Object__ ti_sysbios_family_arm_m3_Hwi_Object__table__V[2] = {
    {/* instance#0 */
        0,
        ((xdc_UArg)(0x1)),  /* arg */
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I)),  /* fxn */
        ((xdc_UArg)(0x3)),  /* irp */
        (xdc_UInt8)0x0,  /* priority */
        (xdc_Int16)0x11,  /* intNum */
        ((void*)0),  /* hookEnv */
    },
    {/* instance#1 */
        0,
        ((xdc_UArg)((void*)(ti_sysbios_family_arm_ducati_Timer_Handle)&ti_sysbios_family_arm_ducati_Timer_Object__table__V[0])),  /* arg */
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_arm_ducati_Timer_periodicStub__E)),  /* fxn */
        ((xdc_UArg)(0x3)),  /* irp */
        (xdc_UInt8)0xff,  /* priority */
        (xdc_Int16)0xf,  /* intNum */
        ((void*)0),  /* hookEnv */
    },
};

/* --> ti_sysbios_family_arm_m3_Hwi_Module_State_0_excActive__A */
__T1_ti_sysbios_family_arm_m3_Hwi_Module_State__excActive ti_sysbios_family_arm_m3_Hwi_Module_State_0_excActive__A[1] = {
    0,  /* [0] */
};

/* --> ti_sysbios_family_arm_m3_Hwi_Module_State_0_excContext__A */
__T1_ti_sysbios_family_arm_m3_Hwi_Module_State__excContext ti_sysbios_family_arm_m3_Hwi_Module_State_0_excContext__A[1] = {
    ((ti_sysbios_family_arm_m3_Hwi_ExcContext*)0),  /* [0] */
};

/* --> ti_sysbios_family_arm_m3_Hwi_Module_State_0_excStack__A */
__T1_ti_sysbios_family_arm_m3_Hwi_Module_State__excStack ti_sysbios_family_arm_m3_Hwi_Module_State_0_excStack__A[1] = {
    ((xdc_Ptr)0),  /* [0] */
};

/* Module__state__V */
#if defined (__ICCARM__)
#pragma location = ".data_ti_sysbios_family_arm_m3_Hwi_Module__state__V"
#endif
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
#ifndef __TI_COMPILER_VERSION__
ti_sysbios_family_arm_m3_Hwi_Module_State__ ti_sysbios_family_arm_m3_Hwi_Module__state__V __attribute__ ((section(".data_ti_sysbios_family_arm_m3_Hwi_Module__state__V")));
#endif
#endif
ti_sysbios_family_arm_m3_Hwi_Module_State__ ti_sysbios_family_arm_m3_Hwi_Module__state__V = {
    ((xdc_Char*)0),  /* taskSP */
    ((void*)ti_sysbios_family_arm_m3_Hwi_Module_State_0_excActive__A),  /* excActive */
    ((void*)ti_sysbios_family_arm_m3_Hwi_Module_State_0_excContext__A),  /* excContext */
    ((void*)ti_sysbios_family_arm_m3_Hwi_Module_State_0_excStack__A),  /* excStack */
    ((xdc_Ptr)0),  /* isrStack */
    ((xdc_Ptr)((void*)&__TI_STACK_BASE)),  /* isrStackBase */
    ((xdc_Ptr)((void*)&__TI_STACK_SIZE)),  /* isrStackSize */
    ((xdc_Ptr)(0x800)),  /* vectorTableBase */
    (xdc_UInt)0x101,  /* swiTaskKeys */
    ((xdc_Ptr)((void*)&ti_sysbios_family_arm_m3_Hwi_dispatchTable[0])),  /* dispatchTable */
    0,  /* vnvicFlushRequired */
    ((void*)0),  /* intAffinity */
    ((void*)0),  /* intAffinityMasks */
};

/* --> ti_sysbios_family_arm_m3_Hwi_excHookFuncs__A */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_excHookFuncs__A, ".const:ti_sysbios_family_arm_m3_Hwi_excHookFuncs__A");
const __T1_ti_sysbios_family_arm_m3_Hwi_excHookFuncs ti_sysbios_family_arm_m3_Hwi_excHookFuncs__A[2] = {
    ((xdc_Void(*)(ti_sysbios_family_arm_m3_Hwi_ExcContext*))0),  /* [0] */
    ((xdc_Void(*)(ti_sysbios_family_arm_m3_Hwi_ExcContext*))0),  /* [1] */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Module__diagsEnabled__C, ".const:ti_sysbios_family_arm_m3_Hwi_Module__diagsEnabled__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__diagsEnabled ti_sysbios_family_arm_m3_Hwi_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Module__diagsIncluded__C, ".const:ti_sysbios_family_arm_m3_Hwi_Module__diagsIncluded__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__diagsIncluded ti_sysbios_family_arm_m3_Hwi_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Module__diagsMask__C, ".const:ti_sysbios_family_arm_m3_Hwi_Module__diagsMask__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__diagsMask ti_sysbios_family_arm_m3_Hwi_Module__diagsMask__C = ((CT__ti_sysbios_family_arm_m3_Hwi_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Module__gateObj__C, ".const:ti_sysbios_family_arm_m3_Hwi_Module__gateObj__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__gateObj ti_sysbios_family_arm_m3_Hwi_Module__gateObj__C = ((CT__ti_sysbios_family_arm_m3_Hwi_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Module__gatePrms__C, ".const:ti_sysbios_family_arm_m3_Hwi_Module__gatePrms__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__gatePrms ti_sysbios_family_arm_m3_Hwi_Module__gatePrms__C = ((CT__ti_sysbios_family_arm_m3_Hwi_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Module__id__C, ".const:ti_sysbios_family_arm_m3_Hwi_Module__id__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__id ti_sysbios_family_arm_m3_Hwi_Module__id__C = (xdc_Bits16)0x8020;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Module__loggerDefined__C, ".const:ti_sysbios_family_arm_m3_Hwi_Module__loggerDefined__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerDefined ti_sysbios_family_arm_m3_Hwi_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Module__loggerObj__C, ".const:ti_sysbios_family_arm_m3_Hwi_Module__loggerObj__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerObj ti_sysbios_family_arm_m3_Hwi_Module__loggerObj__C = ((CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn0__C, ".const:ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn0__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn0 ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn0__C = ((CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn1__C, ".const:ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn1__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn1 ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn1__C = ((CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn2__C, ".const:ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn2__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn2 ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn2__C = ((CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn4__C, ".const:ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn4__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn4 ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn4__C = ((CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn8__C, ".const:ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn8__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn8 ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn8__C = ((CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Module__startupDoneFxn__C, ".const:ti_sysbios_family_arm_m3_Hwi_Module__startupDoneFxn__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__startupDoneFxn ti_sysbios_family_arm_m3_Hwi_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_arm_m3_Hwi_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Object__count__C, ".const:ti_sysbios_family_arm_m3_Hwi_Object__count__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Object__count ti_sysbios_family_arm_m3_Hwi_Object__count__C = 2;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Object__heap__C, ".const:ti_sysbios_family_arm_m3_Hwi_Object__heap__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Object__heap ti_sysbios_family_arm_m3_Hwi_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Object__sizeof__C, ".const:ti_sysbios_family_arm_m3_Hwi_Object__sizeof__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Object__sizeof ti_sysbios_family_arm_m3_Hwi_Object__sizeof__C = sizeof(ti_sysbios_family_arm_m3_Hwi_Object__);

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Object__table__C, ".const:ti_sysbios_family_arm_m3_Hwi_Object__table__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Object__table ti_sysbios_family_arm_m3_Hwi_Object__table__C = ti_sysbios_family_arm_m3_Hwi_Object__table__V;

/* dispatcherAutoNestingSupport__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_dispatcherAutoNestingSupport__C, ".const:ti_sysbios_family_arm_m3_Hwi_dispatcherAutoNestingSupport__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_dispatcherAutoNestingSupport ti_sysbios_family_arm_m3_Hwi_dispatcherAutoNestingSupport__C = 1;

/* dispatcherSwiSupport__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_dispatcherSwiSupport__C, ".const:ti_sysbios_family_arm_m3_Hwi_dispatcherSwiSupport__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_dispatcherSwiSupport ti_sysbios_family_arm_m3_Hwi_dispatcherSwiSupport__C = 1;

/* dispatcherTaskSupport__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_dispatcherTaskSupport__C, ".const:ti_sysbios_family_arm_m3_Hwi_dispatcherTaskSupport__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_dispatcherTaskSupport ti_sysbios_family_arm_m3_Hwi_dispatcherTaskSupport__C = 1;

/* dispatcherIrpTrackingSupport__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_dispatcherIrpTrackingSupport__C, ".const:ti_sysbios_family_arm_m3_Hwi_dispatcherIrpTrackingSupport__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_dispatcherIrpTrackingSupport ti_sysbios_family_arm_m3_Hwi_dispatcherIrpTrackingSupport__C = 1;

/* NUM_INTERRUPTS__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_NUM_INTERRUPTS__C, ".const:ti_sysbios_family_arm_m3_Hwi_NUM_INTERRUPTS__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_NUM_INTERRUPTS ti_sysbios_family_arm_m3_Hwi_NUM_INTERRUPTS__C = (xdc_Int)0x50;

/* NUM_PRIORITIES__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_NUM_PRIORITIES__C, ".const:ti_sysbios_family_arm_m3_Hwi_NUM_PRIORITIES__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_NUM_PRIORITIES ti_sysbios_family_arm_m3_Hwi_NUM_PRIORITIES__C = (xdc_Int)0x10;

/* LM_begin__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_LM_begin__C, ".const:ti_sysbios_family_arm_m3_Hwi_LM_begin__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_LM_begin ti_sysbios_family_arm_m3_Hwi_LM_begin__C = (((xdc_runtime_Log_Event)6683) << 16 | 768);

/* LD_end__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_LD_end__C, ".const:ti_sysbios_family_arm_m3_Hwi_LD_end__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_LD_end ti_sysbios_family_arm_m3_Hwi_LD_end__C = (((xdc_runtime_Log_Event)6753) << 16 | 512);

/* A_unsupportedMaskingOption__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_A_unsupportedMaskingOption__C, ".const:ti_sysbios_family_arm_m3_Hwi_A_unsupportedMaskingOption__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_A_unsupportedMaskingOption ti_sysbios_family_arm_m3_Hwi_A_unsupportedMaskingOption__C = (((xdc_runtime_Assert_Id)1933) << 16 | 16);

/* E_alreadyDefined__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_E_alreadyDefined__C, ".const:ti_sysbios_family_arm_m3_Hwi_E_alreadyDefined__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_E_alreadyDefined ti_sysbios_family_arm_m3_Hwi_E_alreadyDefined__C = (((xdc_runtime_Error_Id)4824) << 16 | 0);

/* E_hwiLimitExceeded__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_E_hwiLimitExceeded__C, ".const:ti_sysbios_family_arm_m3_Hwi_E_hwiLimitExceeded__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_E_hwiLimitExceeded ti_sysbios_family_arm_m3_Hwi_E_hwiLimitExceeded__C = (((xdc_runtime_Error_Id)4872) << 16 | 0);

/* E_exception__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_E_exception__C, ".const:ti_sysbios_family_arm_m3_Hwi_E_exception__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_E_exception ti_sysbios_family_arm_m3_Hwi_E_exception__C = (((xdc_runtime_Error_Id)4920) << 16 | 0);

/* E_noIsr__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_E_noIsr__C, ".const:ti_sysbios_family_arm_m3_Hwi_E_noIsr__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_E_noIsr ti_sysbios_family_arm_m3_Hwi_E_noIsr__C = (((xdc_runtime_Error_Id)5125) << 16 | 0);

/* E_NMI__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_E_NMI__C, ".const:ti_sysbios_family_arm_m3_Hwi_E_NMI__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_E_NMI ti_sysbios_family_arm_m3_Hwi_E_NMI__C = (((xdc_runtime_Error_Id)5153) << 16 | 0);

/* E_hardFault__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_E_hardFault__C, ".const:ti_sysbios_family_arm_m3_Hwi_E_hardFault__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_E_hardFault ti_sysbios_family_arm_m3_Hwi_E_hardFault__C = (((xdc_runtime_Error_Id)5163) << 16 | 0);

/* E_memFault__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_E_memFault__C, ".const:ti_sysbios_family_arm_m3_Hwi_E_memFault__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_E_memFault ti_sysbios_family_arm_m3_Hwi_E_memFault__C = (((xdc_runtime_Error_Id)5179) << 16 | 0);

/* E_busFault__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_E_busFault__C, ".const:ti_sysbios_family_arm_m3_Hwi_E_busFault__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_E_busFault ti_sysbios_family_arm_m3_Hwi_E_busFault__C = (((xdc_runtime_Error_Id)5209) << 16 | 0);

/* E_usageFault__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_E_usageFault__C, ".const:ti_sysbios_family_arm_m3_Hwi_E_usageFault__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_E_usageFault ti_sysbios_family_arm_m3_Hwi_E_usageFault__C = (((xdc_runtime_Error_Id)5239) << 16 | 0);

/* E_svCall__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_E_svCall__C, ".const:ti_sysbios_family_arm_m3_Hwi_E_svCall__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_E_svCall ti_sysbios_family_arm_m3_Hwi_E_svCall__C = (((xdc_runtime_Error_Id)5256) << 16 | 0);

/* E_debugMon__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_E_debugMon__C, ".const:ti_sysbios_family_arm_m3_Hwi_E_debugMon__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_E_debugMon ti_sysbios_family_arm_m3_Hwi_E_debugMon__C = (((xdc_runtime_Error_Id)5277) << 16 | 0);

/* E_reserved__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_E_reserved__C, ".const:ti_sysbios_family_arm_m3_Hwi_E_reserved__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_E_reserved ti_sysbios_family_arm_m3_Hwi_E_reserved__C = (((xdc_runtime_Error_Id)5292) << 16 | 0);

/* nullIsrFunc__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_nullIsrFunc__C, ".const:ti_sysbios_family_arm_m3_Hwi_nullIsrFunc__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_nullIsrFunc ti_sysbios_family_arm_m3_Hwi_nullIsrFunc__C = ((CT__ti_sysbios_family_arm_m3_Hwi_nullIsrFunc)((xdc_Fxn)ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I));

/* excHandlerFunc__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_excHandlerFunc__C, ".const:ti_sysbios_family_arm_m3_Hwi_excHandlerFunc__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_excHandlerFunc ti_sysbios_family_arm_m3_Hwi_excHandlerFunc__C = ((CT__ti_sysbios_family_arm_m3_Hwi_excHandlerFunc)((xdc_Fxn)ti_sysbios_family_arm_m3_Hwi_excHandlerMax__I));

/* excHookFunc__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_excHookFunc__C, ".const:ti_sysbios_family_arm_m3_Hwi_excHookFunc__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_excHookFunc ti_sysbios_family_arm_m3_Hwi_excHookFunc__C = ((CT__ti_sysbios_family_arm_m3_Hwi_excHookFunc)0);

/* excHookFuncs__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_excHookFuncs__C, ".const:ti_sysbios_family_arm_m3_Hwi_excHookFuncs__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_excHookFuncs ti_sysbios_family_arm_m3_Hwi_excHookFuncs__C = ((CT__ti_sysbios_family_arm_m3_Hwi_excHookFuncs)ti_sysbios_family_arm_m3_Hwi_excHookFuncs__A);

/* disablePriority__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_disablePriority__C, ".const:ti_sysbios_family_arm_m3_Hwi_disablePriority__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_disablePriority ti_sysbios_family_arm_m3_Hwi_disablePriority__C = (xdc_UInt)0x10;

/* priGroup__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_priGroup__C, ".const:ti_sysbios_family_arm_m3_Hwi_priGroup__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_priGroup ti_sysbios_family_arm_m3_Hwi_priGroup__C = (xdc_UInt)0x0;

/* numSparseInterrupts__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_numSparseInterrupts__C, ".const:ti_sysbios_family_arm_m3_Hwi_numSparseInterrupts__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_numSparseInterrupts ti_sysbios_family_arm_m3_Hwi_numSparseInterrupts__C = (xdc_UInt)0x0;

/* swiDisable__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_swiDisable__C, ".const:ti_sysbios_family_arm_m3_Hwi_swiDisable__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_swiDisable ti_sysbios_family_arm_m3_Hwi_swiDisable__C = ((CT__ti_sysbios_family_arm_m3_Hwi_swiDisable)((xdc_Fxn)ti_sysbios_knl_Swi_disable__E));

/* swiRestoreHwi__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_swiRestoreHwi__C, ".const:ti_sysbios_family_arm_m3_Hwi_swiRestoreHwi__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_swiRestoreHwi ti_sysbios_family_arm_m3_Hwi_swiRestoreHwi__C = ((CT__ti_sysbios_family_arm_m3_Hwi_swiRestoreHwi)((xdc_Fxn)ti_sysbios_knl_Swi_restoreHwi__E));

/* taskDisable__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_taskDisable__C, ".const:ti_sysbios_family_arm_m3_Hwi_taskDisable__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_taskDisable ti_sysbios_family_arm_m3_Hwi_taskDisable__C = ((CT__ti_sysbios_family_arm_m3_Hwi_taskDisable)((xdc_Fxn)ti_sysbios_knl_Task_disable__E));

/* taskRestoreHwi__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_taskRestoreHwi__C, ".const:ti_sysbios_family_arm_m3_Hwi_taskRestoreHwi__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_taskRestoreHwi ti_sysbios_family_arm_m3_Hwi_taskRestoreHwi__C = ((CT__ti_sysbios_family_arm_m3_Hwi_taskRestoreHwi)((xdc_Fxn)ti_sysbios_knl_Task_restoreHwi__E));

/* ccr__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_ccr__C, ".const:ti_sysbios_family_arm_m3_Hwi_ccr__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_ccr ti_sysbios_family_arm_m3_Hwi_ccr__C = (xdc_UInt32)0x200;

/* hooks__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_hooks__C, ".const:ti_sysbios_family_arm_m3_Hwi_hooks__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_hooks ti_sysbios_family_arm_m3_Hwi_hooks__C = {0, 0};


/*
 * ======== ti.sysbios.family.arm.m3.IntrinsicsSupport INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__diagsEnabled__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__diagsEnabled__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__diagsEnabled ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__diagsIncluded__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__diagsIncluded__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__diagsIncluded ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__diagsMask__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__diagsMask__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__diagsMask ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__diagsMask__C = ((CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__gateObj__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__gateObj__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__gateObj ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__gateObj__C = ((CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__gatePrms__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__gatePrms__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__gatePrms ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__gatePrms__C = ((CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__id__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__id__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__id ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__id__C = (xdc_Bits16)0x8021;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerDefined__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerDefined__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerDefined ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerObj__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerObj__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerObj ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerObj__C = ((CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn0__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn0__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn0 ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn0__C = ((CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn1__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn1__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn1 ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn1__C = ((CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn2__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn2__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn2 ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn2__C = ((CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn4__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn4__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn4 ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn4__C = ((CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn8__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn8__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn8 ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn8__C = ((CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__startupDoneFxn__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__startupDoneFxn__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__startupDoneFxn ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Object__count__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Object__count__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Object__count ti_sysbios_family_arm_m3_IntrinsicsSupport_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Object__heap__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Object__heap__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Object__heap ti_sysbios_family_arm_m3_IntrinsicsSupport_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Object__sizeof__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Object__sizeof__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Object__sizeof ti_sysbios_family_arm_m3_IntrinsicsSupport_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Object__table__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Object__table__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Object__table ti_sysbios_family_arm_m3_IntrinsicsSupport_Object__table__C = 0;


/*
 * ======== ti.sysbios.family.arm.m3.TaskSupport INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_Module__diagsEnabled__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_Module__diagsEnabled__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_Module__diagsEnabled ti_sysbios_family_arm_m3_TaskSupport_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_Module__diagsIncluded__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_Module__diagsIncluded__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_Module__diagsIncluded ti_sysbios_family_arm_m3_TaskSupport_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_Module__diagsMask__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_Module__diagsMask__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_Module__diagsMask ti_sysbios_family_arm_m3_TaskSupport_Module__diagsMask__C = ((CT__ti_sysbios_family_arm_m3_TaskSupport_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_Module__gateObj__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_Module__gateObj__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_Module__gateObj ti_sysbios_family_arm_m3_TaskSupport_Module__gateObj__C = ((CT__ti_sysbios_family_arm_m3_TaskSupport_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_Module__gatePrms__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_Module__gatePrms__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_Module__gatePrms ti_sysbios_family_arm_m3_TaskSupport_Module__gatePrms__C = ((CT__ti_sysbios_family_arm_m3_TaskSupport_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_Module__id__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_Module__id__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_Module__id ti_sysbios_family_arm_m3_TaskSupport_Module__id__C = (xdc_Bits16)0x8022;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_Module__loggerDefined__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_Module__loggerDefined__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_Module__loggerDefined ti_sysbios_family_arm_m3_TaskSupport_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_Module__loggerObj__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_Module__loggerObj__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_Module__loggerObj ti_sysbios_family_arm_m3_TaskSupport_Module__loggerObj__C = ((CT__ti_sysbios_family_arm_m3_TaskSupport_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn0__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn0__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn0 ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn0__C = ((CT__ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn1__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn1__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn1 ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn1__C = ((CT__ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn2__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn2__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn2 ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn2__C = ((CT__ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn4__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn4__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn4 ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn4__C = ((CT__ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn8__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn8__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn8 ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn8__C = ((CT__ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_Module__startupDoneFxn__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_Module__startupDoneFxn__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_Module__startupDoneFxn ti_sysbios_family_arm_m3_TaskSupport_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_arm_m3_TaskSupport_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_Object__count__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_Object__count__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_Object__count ti_sysbios_family_arm_m3_TaskSupport_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_Object__heap__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_Object__heap__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_Object__heap ti_sysbios_family_arm_m3_TaskSupport_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_Object__sizeof__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_Object__sizeof__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_Object__sizeof ti_sysbios_family_arm_m3_TaskSupport_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_Object__table__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_Object__table__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_Object__table ti_sysbios_family_arm_m3_TaskSupport_Object__table__C = 0;

/* defaultStackSize__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_defaultStackSize__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_defaultStackSize__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_defaultStackSize ti_sysbios_family_arm_m3_TaskSupport_defaultStackSize__C = (xdc_SizeT)0x800;

/* stackAlignment__C */
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_stackAlignment__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_stackAlignment__C");
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_stackAlignment ti_sysbios_family_arm_m3_TaskSupport_stackAlignment__C = (xdc_UInt)0x8;


/*
 * ======== ti.sysbios.family.shared.vayu.IntXbar INITIALIZERS ========
 */

/* --> ti_sysbios_family_shared_vayu_IntXbar_Module_State_0_intXbar__A */
__T1_ti_sysbios_family_shared_vayu_IntXbar_Module_State__intXbar ti_sysbios_family_shared_vayu_IntXbar_Module_State_0_intXbar__A[57] = {
    (xdc_UInt16)0x0,  /* [0] */
    (xdc_UInt16)0x0,  /* [1] */
    (xdc_UInt16)0x0,  /* [2] */
    (xdc_UInt16)0x0,  /* [3] */
    (xdc_UInt16)0x0,  /* [4] */
    (xdc_UInt16)0x0,  /* [5] */
    (xdc_UInt16)0x0,  /* [6] */
    (xdc_UInt16)0x0,  /* [7] */
    (xdc_UInt16)0x0,  /* [8] */
    (xdc_UInt16)0x0,  /* [9] */
    (xdc_UInt16)0x0,  /* [10] */
    (xdc_UInt16)0x0,  /* [11] */
    (xdc_UInt16)0x0,  /* [12] */
    (xdc_UInt16)0x0,  /* [13] */
    (xdc_UInt16)0x0,  /* [14] */
    (xdc_UInt16)0x0,  /* [15] */
    (xdc_UInt16)0x0,  /* [16] */
    (xdc_UInt16)0x0,  /* [17] */
    (xdc_UInt16)0x0,  /* [18] */
    (xdc_UInt16)0x0,  /* [19] */
    (xdc_UInt16)0x0,  /* [20] */
    (xdc_UInt16)0x0,  /* [21] */
    (xdc_UInt16)0x0,  /* [22] */
    (xdc_UInt16)0x0,  /* [23] */
    (xdc_UInt16)0x0,  /* [24] */
    (xdc_UInt16)0x0,  /* [25] */
    (xdc_UInt16)0x0,  /* [26] */
    (xdc_UInt16)0x0,  /* [27] */
    (xdc_UInt16)0x0,  /* [28] */
    (xdc_UInt16)0x0,  /* [29] */
    (xdc_UInt16)0x0,  /* [30] */
    (xdc_UInt16)0x0,  /* [31] */
    (xdc_UInt16)0x0,  /* [32] */
    (xdc_UInt16)0x0,  /* [33] */
    (xdc_UInt16)0x0,  /* [34] */
    (xdc_UInt16)0x0,  /* [35] */
    (xdc_UInt16)0x0,  /* [36] */
    (xdc_UInt16)0x0,  /* [37] */
    (xdc_UInt16)0x0,  /* [38] */
    (xdc_UInt16)0x0,  /* [39] */
    (xdc_UInt16)0x0,  /* [40] */
    (xdc_UInt16)0x0,  /* [41] */
    (xdc_UInt16)0x0,  /* [42] */
    (xdc_UInt16)0x0,  /* [43] */
    (xdc_UInt16)0x0,  /* [44] */
    (xdc_UInt16)0x0,  /* [45] */
    (xdc_UInt16)0x0,  /* [46] */
    (xdc_UInt16)0x0,  /* [47] */
    (xdc_UInt16)0x0,  /* [48] */
    (xdc_UInt16)0x0,  /* [49] */
    (xdc_UInt16)0x0,  /* [50] */
    (xdc_UInt16)0x0,  /* [51] */
    (xdc_UInt16)0x0,  /* [52] */
    (xdc_UInt16)0x0,  /* [53] */
    (xdc_UInt16)0x0,  /* [54] */
    (xdc_UInt16)0x0,  /* [55] */
    (xdc_UInt16)0x0,  /* [56] */
};

/* Module__state__V */
#if defined (__ICCARM__)
#pragma location = ".data_ti_sysbios_family_shared_vayu_IntXbar_Module__state__V"
#endif
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
#ifndef __TI_COMPILER_VERSION__
ti_sysbios_family_shared_vayu_IntXbar_Module_State__ ti_sysbios_family_shared_vayu_IntXbar_Module__state__V __attribute__ ((section(".data_ti_sysbios_family_shared_vayu_IntXbar_Module__state__V")));
#endif
#endif
ti_sysbios_family_shared_vayu_IntXbar_Module_State__ ti_sysbios_family_shared_vayu_IntXbar_Module__state__V = {
    ((void*)ti_sysbios_family_shared_vayu_IntXbar_Module_State_0_intXbar__A),  /* intXbar */
};

/* --> ti_sysbios_family_shared_vayu_IntXbar_intXbar__A */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_intXbar__A, ".const:ti_sysbios_family_shared_vayu_IntXbar_intXbar__A");
const __T1_ti_sysbios_family_shared_vayu_IntXbar_intXbar ti_sysbios_family_shared_vayu_IntXbar_intXbar__A[57] = {
    (xdc_UInt16)0x0,  /* [0] */
    (xdc_UInt16)0x0,  /* [1] */
    (xdc_UInt16)0x0,  /* [2] */
    (xdc_UInt16)0x0,  /* [3] */
    (xdc_UInt16)0x0,  /* [4] */
    (xdc_UInt16)0x0,  /* [5] */
    (xdc_UInt16)0x0,  /* [6] */
    (xdc_UInt16)0x0,  /* [7] */
    (xdc_UInt16)0x0,  /* [8] */
    (xdc_UInt16)0x0,  /* [9] */
    (xdc_UInt16)0x0,  /* [10] */
    (xdc_UInt16)0x0,  /* [11] */
    (xdc_UInt16)0x0,  /* [12] */
    (xdc_UInt16)0x0,  /* [13] */
    (xdc_UInt16)0x0,  /* [14] */
    (xdc_UInt16)0x0,  /* [15] */
    (xdc_UInt16)0x0,  /* [16] */
    (xdc_UInt16)0x0,  /* [17] */
    (xdc_UInt16)0x0,  /* [18] */
    (xdc_UInt16)0x0,  /* [19] */
    (xdc_UInt16)0x0,  /* [20] */
    (xdc_UInt16)0x0,  /* [21] */
    (xdc_UInt16)0x0,  /* [22] */
    (xdc_UInt16)0x0,  /* [23] */
    (xdc_UInt16)0x0,  /* [24] */
    (xdc_UInt16)0x0,  /* [25] */
    (xdc_UInt16)0x0,  /* [26] */
    (xdc_UInt16)0x0,  /* [27] */
    (xdc_UInt16)0x0,  /* [28] */
    (xdc_UInt16)0x0,  /* [29] */
    (xdc_UInt16)0x0,  /* [30] */
    (xdc_UInt16)0x0,  /* [31] */
    (xdc_UInt16)0x0,  /* [32] */
    (xdc_UInt16)0x0,  /* [33] */
    (xdc_UInt16)0x0,  /* [34] */
    (xdc_UInt16)0x0,  /* [35] */
    (xdc_UInt16)0x0,  /* [36] */
    (xdc_UInt16)0x0,  /* [37] */
    (xdc_UInt16)0x0,  /* [38] */
    (xdc_UInt16)0x0,  /* [39] */
    (xdc_UInt16)0x0,  /* [40] */
    (xdc_UInt16)0x0,  /* [41] */
    (xdc_UInt16)0x0,  /* [42] */
    (xdc_UInt16)0x0,  /* [43] */
    (xdc_UInt16)0x0,  /* [44] */
    (xdc_UInt16)0x0,  /* [45] */
    (xdc_UInt16)0x0,  /* [46] */
    (xdc_UInt16)0x0,  /* [47] */
    (xdc_UInt16)0x0,  /* [48] */
    (xdc_UInt16)0x0,  /* [49] */
    (xdc_UInt16)0x0,  /* [50] */
    (xdc_UInt16)0x0,  /* [51] */
    (xdc_UInt16)0x0,  /* [52] */
    (xdc_UInt16)0x0,  /* [53] */
    (xdc_UInt16)0x0,  /* [54] */
    (xdc_UInt16)0x0,  /* [55] */
    (xdc_UInt16)0x0,  /* [56] */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_Module__diagsEnabled__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_Module__diagsEnabled__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_Module__diagsEnabled ti_sysbios_family_shared_vayu_IntXbar_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_Module__diagsIncluded__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_Module__diagsIncluded__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_Module__diagsIncluded ti_sysbios_family_shared_vayu_IntXbar_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_Module__diagsMask__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_Module__diagsMask__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_Module__diagsMask ti_sysbios_family_shared_vayu_IntXbar_Module__diagsMask__C = ((CT__ti_sysbios_family_shared_vayu_IntXbar_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_Module__gateObj__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_Module__gateObj__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_Module__gateObj ti_sysbios_family_shared_vayu_IntXbar_Module__gateObj__C = ((CT__ti_sysbios_family_shared_vayu_IntXbar_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_Module__gatePrms__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_Module__gatePrms__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_Module__gatePrms ti_sysbios_family_shared_vayu_IntXbar_Module__gatePrms__C = ((CT__ti_sysbios_family_shared_vayu_IntXbar_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_Module__id__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_Module__id__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_Module__id ti_sysbios_family_shared_vayu_IntXbar_Module__id__C = (xdc_Bits16)0x8025;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_Module__loggerDefined__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_Module__loggerDefined__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_Module__loggerDefined ti_sysbios_family_shared_vayu_IntXbar_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_Module__loggerObj__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_Module__loggerObj__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_Module__loggerObj ti_sysbios_family_shared_vayu_IntXbar_Module__loggerObj__C = ((CT__ti_sysbios_family_shared_vayu_IntXbar_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_Module__loggerFxn0__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_Module__loggerFxn0__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_Module__loggerFxn0 ti_sysbios_family_shared_vayu_IntXbar_Module__loggerFxn0__C = ((CT__ti_sysbios_family_shared_vayu_IntXbar_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_Module__loggerFxn1__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_Module__loggerFxn1__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_Module__loggerFxn1 ti_sysbios_family_shared_vayu_IntXbar_Module__loggerFxn1__C = ((CT__ti_sysbios_family_shared_vayu_IntXbar_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_Module__loggerFxn2__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_Module__loggerFxn2__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_Module__loggerFxn2 ti_sysbios_family_shared_vayu_IntXbar_Module__loggerFxn2__C = ((CT__ti_sysbios_family_shared_vayu_IntXbar_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_Module__loggerFxn4__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_Module__loggerFxn4__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_Module__loggerFxn4 ti_sysbios_family_shared_vayu_IntXbar_Module__loggerFxn4__C = ((CT__ti_sysbios_family_shared_vayu_IntXbar_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_Module__loggerFxn8__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_Module__loggerFxn8__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_Module__loggerFxn8 ti_sysbios_family_shared_vayu_IntXbar_Module__loggerFxn8__C = ((CT__ti_sysbios_family_shared_vayu_IntXbar_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_Module__startupDoneFxn__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_Module__startupDoneFxn__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_Module__startupDoneFxn ti_sysbios_family_shared_vayu_IntXbar_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_shared_vayu_IntXbar_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_Object__count__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_Object__count__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_Object__count ti_sysbios_family_shared_vayu_IntXbar_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_Object__heap__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_Object__heap__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_Object__heap ti_sysbios_family_shared_vayu_IntXbar_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_Object__sizeof__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_Object__sizeof__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_Object__sizeof ti_sysbios_family_shared_vayu_IntXbar_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_Object__table__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_Object__table__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_Object__table ti_sysbios_family_shared_vayu_IntXbar_Object__table__C = 0;

/* A_badEveXbarInstanceNum__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_A_badEveXbarInstanceNum__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_A_badEveXbarInstanceNum__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_A_badEveXbarInstanceNum ti_sysbios_family_shared_vayu_IntXbar_A_badEveXbarInstanceNum__C = (((xdc_runtime_Assert_Id)1986) << 16 | 16);

/* A_badDspXbarInstanceNum__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_A_badDspXbarInstanceNum__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_A_badDspXbarInstanceNum__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_A_badDspXbarInstanceNum ti_sysbios_family_shared_vayu_IntXbar_A_badDspXbarInstanceNum__C = (((xdc_runtime_Assert_Id)2046) << 16 | 16);

/* A_badBenelliXbarInstanceNum__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_A_badBenelliXbarInstanceNum__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_A_badBenelliXbarInstanceNum__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_A_badBenelliXbarInstanceNum ti_sysbios_family_shared_vayu_IntXbar_A_badBenelliXbarInstanceNum__C = (((xdc_runtime_Assert_Id)2107) << 16 | 16);

/* A_badA15XbarInstanceNum__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_A_badA15XbarInstanceNum__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_A_badA15XbarInstanceNum__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_A_badA15XbarInstanceNum ti_sysbios_family_shared_vayu_IntXbar_A_badA15XbarInstanceNum__C = (((xdc_runtime_Assert_Id)2172) << 16 | 16);

/* A_badEveIRQNum__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_A_badEveIRQNum__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_A_badEveIRQNum__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_A_badEveIRQNum ti_sysbios_family_shared_vayu_IntXbar_A_badEveIRQNum__C = (((xdc_runtime_Assert_Id)2234) << 16 | 16);

/* A_badDspIRQNum__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_A_badDspIRQNum__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_A_badDspIRQNum__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_A_badDspIRQNum ti_sysbios_family_shared_vayu_IntXbar_A_badDspIRQNum__C = (((xdc_runtime_Assert_Id)2274) << 16 | 16);

/* A_badBenelliIRQNum__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_A_badBenelliIRQNum__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_A_badBenelliIRQNum__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_A_badBenelliIRQNum ti_sysbios_family_shared_vayu_IntXbar_A_badBenelliIRQNum__C = (((xdc_runtime_Assert_Id)2325) << 16 | 16);

/* A_badA15IRQNum__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_A_badA15IRQNum__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_A_badA15IRQNum__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_A_badA15IRQNum ti_sysbios_family_shared_vayu_IntXbar_A_badA15IRQNum__C = (((xdc_runtime_Assert_Id)2380) << 16 | 16);

/* A_badIntSourceIdx__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_A_badIntSourceIdx__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_A_badIntSourceIdx__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_A_badIntSourceIdx ti_sysbios_family_shared_vayu_IntXbar_A_badIntSourceIdx__C = (((xdc_runtime_Assert_Id)2444) << 16 | 16);

/* A_badEveCpuId__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_A_badEveCpuId__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_A_badEveCpuId__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_A_badEveCpuId ti_sysbios_family_shared_vayu_IntXbar_A_badEveCpuId__C = (((xdc_runtime_Assert_Id)2514) << 16 | 16);

/* A_badDspCpuId__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_A_badDspCpuId__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_A_badDspCpuId__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_A_badDspCpuId ti_sysbios_family_shared_vayu_IntXbar_A_badDspCpuId__C = (((xdc_runtime_Assert_Id)2557) << 16 | 16);

/* A_badBenelliIpuId__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_A_badBenelliIpuId__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_A_badBenelliIpuId__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_A_badBenelliIpuId ti_sysbios_family_shared_vayu_IntXbar_A_badBenelliIpuId__C = (((xdc_runtime_Assert_Id)2594) << 16 | 16);

/* mmrBaseAddr__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_mmrBaseAddr__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_mmrBaseAddr__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_mmrBaseAddr ti_sysbios_family_shared_vayu_IntXbar_mmrBaseAddr__C = (xdc_UInt32)0x4a002000;

/* intXbar__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_intXbar__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_intXbar__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_intXbar ti_sysbios_family_shared_vayu_IntXbar_intXbar__C = ((CT__ti_sysbios_family_shared_vayu_IntXbar_intXbar)ti_sysbios_family_shared_vayu_IntXbar_intXbar__A);


/*
 * ======== ti.sysbios.gates.GateHwi INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_gates_GateHwi_Object__DESC__C;

/* Object__PARAMS__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Object__PARAMS__C, ".const:ti_sysbios_gates_GateHwi_Object__PARAMS__C");
__FAR__ const ti_sysbios_gates_GateHwi_Params ti_sysbios_gates_GateHwi_Object__PARAMS__C = {
    sizeof (ti_sysbios_gates_GateHwi_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_gates_GateHwi_Object__PARAMS__C.__iprms, /* instance */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_gates_GateHwi_Module__ ti_sysbios_gates_GateHwi_Module__root__V = {
    {&ti_sysbios_gates_GateHwi_Module__root__V.link,  /* link.next */
    &ti_sysbios_gates_GateHwi_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_gates_GateHwi_Object__ ti_sysbios_gates_GateHwi_Object__table__V[1] = {
    {/* instance#0 */
        &ti_sysbios_gates_GateHwi_Module__FXNS__C,
    },
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__diagsEnabled__C, ".const:ti_sysbios_gates_GateHwi_Module__diagsEnabled__C");
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__diagsEnabled ti_sysbios_gates_GateHwi_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__diagsIncluded__C, ".const:ti_sysbios_gates_GateHwi_Module__diagsIncluded__C");
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__diagsIncluded ti_sysbios_gates_GateHwi_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__diagsMask__C, ".const:ti_sysbios_gates_GateHwi_Module__diagsMask__C");
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__diagsMask ti_sysbios_gates_GateHwi_Module__diagsMask__C = ((CT__ti_sysbios_gates_GateHwi_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__gateObj__C, ".const:ti_sysbios_gates_GateHwi_Module__gateObj__C");
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__gateObj ti_sysbios_gates_GateHwi_Module__gateObj__C = ((CT__ti_sysbios_gates_GateHwi_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__gatePrms__C, ".const:ti_sysbios_gates_GateHwi_Module__gatePrms__C");
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__gatePrms ti_sysbios_gates_GateHwi_Module__gatePrms__C = ((CT__ti_sysbios_gates_GateHwi_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__id__C, ".const:ti_sysbios_gates_GateHwi_Module__id__C");
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__id ti_sysbios_gates_GateHwi_Module__id__C = (xdc_Bits16)0x8030;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__loggerDefined__C, ".const:ti_sysbios_gates_GateHwi_Module__loggerDefined__C");
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__loggerDefined ti_sysbios_gates_GateHwi_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__loggerObj__C, ".const:ti_sysbios_gates_GateHwi_Module__loggerObj__C");
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__loggerObj ti_sysbios_gates_GateHwi_Module__loggerObj__C = ((CT__ti_sysbios_gates_GateHwi_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__loggerFxn0__C, ".const:ti_sysbios_gates_GateHwi_Module__loggerFxn0__C");
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__loggerFxn0 ti_sysbios_gates_GateHwi_Module__loggerFxn0__C = ((CT__ti_sysbios_gates_GateHwi_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__loggerFxn1__C, ".const:ti_sysbios_gates_GateHwi_Module__loggerFxn1__C");
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__loggerFxn1 ti_sysbios_gates_GateHwi_Module__loggerFxn1__C = ((CT__ti_sysbios_gates_GateHwi_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__loggerFxn2__C, ".const:ti_sysbios_gates_GateHwi_Module__loggerFxn2__C");
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__loggerFxn2 ti_sysbios_gates_GateHwi_Module__loggerFxn2__C = ((CT__ti_sysbios_gates_GateHwi_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__loggerFxn4__C, ".const:ti_sysbios_gates_GateHwi_Module__loggerFxn4__C");
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__loggerFxn4 ti_sysbios_gates_GateHwi_Module__loggerFxn4__C = ((CT__ti_sysbios_gates_GateHwi_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__loggerFxn8__C, ".const:ti_sysbios_gates_GateHwi_Module__loggerFxn8__C");
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__loggerFxn8 ti_sysbios_gates_GateHwi_Module__loggerFxn8__C = ((CT__ti_sysbios_gates_GateHwi_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__startupDoneFxn__C, ".const:ti_sysbios_gates_GateHwi_Module__startupDoneFxn__C");
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__startupDoneFxn ti_sysbios_gates_GateHwi_Module__startupDoneFxn__C = ((CT__ti_sysbios_gates_GateHwi_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Object__count__C, ".const:ti_sysbios_gates_GateHwi_Object__count__C");
__FAR__ const CT__ti_sysbios_gates_GateHwi_Object__count ti_sysbios_gates_GateHwi_Object__count__C = 1;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Object__heap__C, ".const:ti_sysbios_gates_GateHwi_Object__heap__C");
__FAR__ const CT__ti_sysbios_gates_GateHwi_Object__heap ti_sysbios_gates_GateHwi_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Object__sizeof__C, ".const:ti_sysbios_gates_GateHwi_Object__sizeof__C");
__FAR__ const CT__ti_sysbios_gates_GateHwi_Object__sizeof ti_sysbios_gates_GateHwi_Object__sizeof__C = sizeof(ti_sysbios_gates_GateHwi_Object__);

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Object__table__C, ".const:ti_sysbios_gates_GateHwi_Object__table__C");
__FAR__ const CT__ti_sysbios_gates_GateHwi_Object__table ti_sysbios_gates_GateHwi_Object__table__C = ti_sysbios_gates_GateHwi_Object__table__V;


/*
 * ======== ti.sysbios.gates.GateMutex INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_gates_GateMutex_Object__DESC__C;

/* Object__PARAMS__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Object__PARAMS__C, ".const:ti_sysbios_gates_GateMutex_Object__PARAMS__C");
__FAR__ const ti_sysbios_gates_GateMutex_Params ti_sysbios_gates_GateMutex_Object__PARAMS__C = {
    sizeof (ti_sysbios_gates_GateMutex_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_gates_GateMutex_Object__PARAMS__C.__iprms, /* instance */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_gates_GateMutex_Module__ ti_sysbios_gates_GateMutex_Module__root__V = {
    {&ti_sysbios_gates_GateMutex_Module__root__V.link,  /* link.next */
    &ti_sysbios_gates_GateMutex_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_gates_GateMutex_Object__ ti_sysbios_gates_GateMutex_Object__table__V[2] = {
    {/* instance#0 */
        &ti_sysbios_gates_GateMutex_Module__FXNS__C,
        0,  /* owner */
        {
            0,  /* event */
            (xdc_UInt)0x1,  /* eventId */
            ti_sysbios_knl_Semaphore_Mode_COUNTING,  /* mode */
            (xdc_UInt16)0x1,  /* count */
            {
                {
                    ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_gates_GateMutex_Object__table__V[0].Object_field_sem.Object_field_pendQ.elem)),  /* next */
                    ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_gates_GateMutex_Object__table__V[0].Object_field_sem.Object_field_pendQ.elem)),  /* prev */
                },  /* elem */
            },  /* Object_field_pendQ */
        },  /* Object_field_sem */
    },
    {/* instance#1 */
        &ti_sysbios_gates_GateMutex_Module__FXNS__C,
        0,  /* owner */
        {
            0,  /* event */
            (xdc_UInt)0x1,  /* eventId */
            ti_sysbios_knl_Semaphore_Mode_COUNTING,  /* mode */
            (xdc_UInt16)0x1,  /* count */
            {
                {
                    ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_gates_GateMutex_Object__table__V[1].Object_field_sem.Object_field_pendQ.elem)),  /* next */
                    ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_gates_GateMutex_Object__table__V[1].Object_field_sem.Object_field_pendQ.elem)),  /* prev */
                },  /* elem */
            },  /* Object_field_pendQ */
        },  /* Object_field_sem */
    },
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__diagsEnabled__C, ".const:ti_sysbios_gates_GateMutex_Module__diagsEnabled__C");
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__diagsEnabled ti_sysbios_gates_GateMutex_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__diagsIncluded__C, ".const:ti_sysbios_gates_GateMutex_Module__diagsIncluded__C");
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__diagsIncluded ti_sysbios_gates_GateMutex_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__diagsMask__C, ".const:ti_sysbios_gates_GateMutex_Module__diagsMask__C");
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__diagsMask ti_sysbios_gates_GateMutex_Module__diagsMask__C = ((CT__ti_sysbios_gates_GateMutex_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__gateObj__C, ".const:ti_sysbios_gates_GateMutex_Module__gateObj__C");
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__gateObj ti_sysbios_gates_GateMutex_Module__gateObj__C = ((CT__ti_sysbios_gates_GateMutex_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__gatePrms__C, ".const:ti_sysbios_gates_GateMutex_Module__gatePrms__C");
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__gatePrms ti_sysbios_gates_GateMutex_Module__gatePrms__C = ((CT__ti_sysbios_gates_GateMutex_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__id__C, ".const:ti_sysbios_gates_GateMutex_Module__id__C");
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__id ti_sysbios_gates_GateMutex_Module__id__C = (xdc_Bits16)0x8031;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__loggerDefined__C, ".const:ti_sysbios_gates_GateMutex_Module__loggerDefined__C");
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__loggerDefined ti_sysbios_gates_GateMutex_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__loggerObj__C, ".const:ti_sysbios_gates_GateMutex_Module__loggerObj__C");
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__loggerObj ti_sysbios_gates_GateMutex_Module__loggerObj__C = ((CT__ti_sysbios_gates_GateMutex_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__loggerFxn0__C, ".const:ti_sysbios_gates_GateMutex_Module__loggerFxn0__C");
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__loggerFxn0 ti_sysbios_gates_GateMutex_Module__loggerFxn0__C = ((CT__ti_sysbios_gates_GateMutex_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__loggerFxn1__C, ".const:ti_sysbios_gates_GateMutex_Module__loggerFxn1__C");
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__loggerFxn1 ti_sysbios_gates_GateMutex_Module__loggerFxn1__C = ((CT__ti_sysbios_gates_GateMutex_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__loggerFxn2__C, ".const:ti_sysbios_gates_GateMutex_Module__loggerFxn2__C");
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__loggerFxn2 ti_sysbios_gates_GateMutex_Module__loggerFxn2__C = ((CT__ti_sysbios_gates_GateMutex_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__loggerFxn4__C, ".const:ti_sysbios_gates_GateMutex_Module__loggerFxn4__C");
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__loggerFxn4 ti_sysbios_gates_GateMutex_Module__loggerFxn4__C = ((CT__ti_sysbios_gates_GateMutex_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__loggerFxn8__C, ".const:ti_sysbios_gates_GateMutex_Module__loggerFxn8__C");
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__loggerFxn8 ti_sysbios_gates_GateMutex_Module__loggerFxn8__C = ((CT__ti_sysbios_gates_GateMutex_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__startupDoneFxn__C, ".const:ti_sysbios_gates_GateMutex_Module__startupDoneFxn__C");
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__startupDoneFxn ti_sysbios_gates_GateMutex_Module__startupDoneFxn__C = ((CT__ti_sysbios_gates_GateMutex_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Object__count__C, ".const:ti_sysbios_gates_GateMutex_Object__count__C");
__FAR__ const CT__ti_sysbios_gates_GateMutex_Object__count ti_sysbios_gates_GateMutex_Object__count__C = 2;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Object__heap__C, ".const:ti_sysbios_gates_GateMutex_Object__heap__C");
__FAR__ const CT__ti_sysbios_gates_GateMutex_Object__heap ti_sysbios_gates_GateMutex_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Object__sizeof__C, ".const:ti_sysbios_gates_GateMutex_Object__sizeof__C");
__FAR__ const CT__ti_sysbios_gates_GateMutex_Object__sizeof ti_sysbios_gates_GateMutex_Object__sizeof__C = sizeof(ti_sysbios_gates_GateMutex_Object__);

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Object__table__C, ".const:ti_sysbios_gates_GateMutex_Object__table__C");
__FAR__ const CT__ti_sysbios_gates_GateMutex_Object__table ti_sysbios_gates_GateMutex_Object__table__C = ti_sysbios_gates_GateMutex_Object__table__V;

/* A_badContext__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_A_badContext__C, ".const:ti_sysbios_gates_GateMutex_A_badContext__C");
__FAR__ const CT__ti_sysbios_gates_GateMutex_A_badContext ti_sysbios_gates_GateMutex_A_badContext__C = (((xdc_runtime_Assert_Id)3253) << 16 | 16);


/*
 * ======== ti.sysbios.hal.Cache INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_hal_Cache_Module__diagsEnabled__C, ".const:ti_sysbios_hal_Cache_Module__diagsEnabled__C");
__FAR__ const CT__ti_sysbios_hal_Cache_Module__diagsEnabled ti_sysbios_hal_Cache_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_hal_Cache_Module__diagsIncluded__C, ".const:ti_sysbios_hal_Cache_Module__diagsIncluded__C");
__FAR__ const CT__ti_sysbios_hal_Cache_Module__diagsIncluded ti_sysbios_hal_Cache_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_hal_Cache_Module__diagsMask__C, ".const:ti_sysbios_hal_Cache_Module__diagsMask__C");
__FAR__ const CT__ti_sysbios_hal_Cache_Module__diagsMask ti_sysbios_hal_Cache_Module__diagsMask__C = ((CT__ti_sysbios_hal_Cache_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_hal_Cache_Module__gateObj__C, ".const:ti_sysbios_hal_Cache_Module__gateObj__C");
__FAR__ const CT__ti_sysbios_hal_Cache_Module__gateObj ti_sysbios_hal_Cache_Module__gateObj__C = ((CT__ti_sysbios_hal_Cache_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_hal_Cache_Module__gatePrms__C, ".const:ti_sysbios_hal_Cache_Module__gatePrms__C");
__FAR__ const CT__ti_sysbios_hal_Cache_Module__gatePrms ti_sysbios_hal_Cache_Module__gatePrms__C = ((CT__ti_sysbios_hal_Cache_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_hal_Cache_Module__id__C, ".const:ti_sysbios_hal_Cache_Module__id__C");
__FAR__ const CT__ti_sysbios_hal_Cache_Module__id ti_sysbios_hal_Cache_Module__id__C = (xdc_Bits16)0x801b;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_hal_Cache_Module__loggerDefined__C, ".const:ti_sysbios_hal_Cache_Module__loggerDefined__C");
__FAR__ const CT__ti_sysbios_hal_Cache_Module__loggerDefined ti_sysbios_hal_Cache_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_hal_Cache_Module__loggerObj__C, ".const:ti_sysbios_hal_Cache_Module__loggerObj__C");
__FAR__ const CT__ti_sysbios_hal_Cache_Module__loggerObj ti_sysbios_hal_Cache_Module__loggerObj__C = ((CT__ti_sysbios_hal_Cache_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_hal_Cache_Module__loggerFxn0__C, ".const:ti_sysbios_hal_Cache_Module__loggerFxn0__C");
__FAR__ const CT__ti_sysbios_hal_Cache_Module__loggerFxn0 ti_sysbios_hal_Cache_Module__loggerFxn0__C = ((CT__ti_sysbios_hal_Cache_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_hal_Cache_Module__loggerFxn1__C, ".const:ti_sysbios_hal_Cache_Module__loggerFxn1__C");
__FAR__ const CT__ti_sysbios_hal_Cache_Module__loggerFxn1 ti_sysbios_hal_Cache_Module__loggerFxn1__C = ((CT__ti_sysbios_hal_Cache_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_hal_Cache_Module__loggerFxn2__C, ".const:ti_sysbios_hal_Cache_Module__loggerFxn2__C");
__FAR__ const CT__ti_sysbios_hal_Cache_Module__loggerFxn2 ti_sysbios_hal_Cache_Module__loggerFxn2__C = ((CT__ti_sysbios_hal_Cache_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_hal_Cache_Module__loggerFxn4__C, ".const:ti_sysbios_hal_Cache_Module__loggerFxn4__C");
__FAR__ const CT__ti_sysbios_hal_Cache_Module__loggerFxn4 ti_sysbios_hal_Cache_Module__loggerFxn4__C = ((CT__ti_sysbios_hal_Cache_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_hal_Cache_Module__loggerFxn8__C, ".const:ti_sysbios_hal_Cache_Module__loggerFxn8__C");
__FAR__ const CT__ti_sysbios_hal_Cache_Module__loggerFxn8 ti_sysbios_hal_Cache_Module__loggerFxn8__C = ((CT__ti_sysbios_hal_Cache_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(ti_sysbios_hal_Cache_Module__startupDoneFxn__C, ".const:ti_sysbios_hal_Cache_Module__startupDoneFxn__C");
__FAR__ const CT__ti_sysbios_hal_Cache_Module__startupDoneFxn ti_sysbios_hal_Cache_Module__startupDoneFxn__C = ((CT__ti_sysbios_hal_Cache_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_hal_Cache_Object__count__C, ".const:ti_sysbios_hal_Cache_Object__count__C");
__FAR__ const CT__ti_sysbios_hal_Cache_Object__count ti_sysbios_hal_Cache_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_hal_Cache_Object__heap__C, ".const:ti_sysbios_hal_Cache_Object__heap__C");
__FAR__ const CT__ti_sysbios_hal_Cache_Object__heap ti_sysbios_hal_Cache_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_hal_Cache_Object__sizeof__C, ".const:ti_sysbios_hal_Cache_Object__sizeof__C");
__FAR__ const CT__ti_sysbios_hal_Cache_Object__sizeof ti_sysbios_hal_Cache_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_hal_Cache_Object__table__C, ".const:ti_sysbios_hal_Cache_Object__table__C");
__FAR__ const CT__ti_sysbios_hal_Cache_Object__table ti_sysbios_hal_Cache_Object__table__C = 0;


/*
 * ======== ti.sysbios.hal.Cache_CacheProxy INITIALIZERS ========
 */


/*
 * ======== ti.sysbios.hal.Hwi INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_hal_Hwi_Object__DESC__C;

/* Object__PARAMS__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Object__PARAMS__C, ".const:ti_sysbios_hal_Hwi_Object__PARAMS__C");
__FAR__ const ti_sysbios_hal_Hwi_Params ti_sysbios_hal_Hwi_Object__PARAMS__C = {
    sizeof (ti_sysbios_hal_Hwi_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_hal_Hwi_Object__PARAMS__C.__iprms, /* instance */
    ti_sysbios_interfaces_IHwi_MaskingOption_LOWER,  /* maskSetting */
    ((xdc_UArg)(0x0)),  /* arg */
    1,  /* enableInt */
    (xdc_Int)(-0x0 - 1),  /* eventId */
    (xdc_Int)(-0x0 - 1),  /* priority */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_hal_Hwi_Module__ ti_sysbios_hal_Hwi_Module__root__V = {
    {&ti_sysbios_hal_Hwi_Module__root__V.link,  /* link.next */
    &ti_sysbios_hal_Hwi_Module__root__V.link},  /* link.prev */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__diagsEnabled__C, ".const:ti_sysbios_hal_Hwi_Module__diagsEnabled__C");
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__diagsEnabled ti_sysbios_hal_Hwi_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__diagsIncluded__C, ".const:ti_sysbios_hal_Hwi_Module__diagsIncluded__C");
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__diagsIncluded ti_sysbios_hal_Hwi_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__diagsMask__C, ".const:ti_sysbios_hal_Hwi_Module__diagsMask__C");
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__diagsMask ti_sysbios_hal_Hwi_Module__diagsMask__C = ((CT__ti_sysbios_hal_Hwi_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__gateObj__C, ".const:ti_sysbios_hal_Hwi_Module__gateObj__C");
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__gateObj ti_sysbios_hal_Hwi_Module__gateObj__C = ((CT__ti_sysbios_hal_Hwi_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__gatePrms__C, ".const:ti_sysbios_hal_Hwi_Module__gatePrms__C");
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__gatePrms ti_sysbios_hal_Hwi_Module__gatePrms__C = ((CT__ti_sysbios_hal_Hwi_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__id__C, ".const:ti_sysbios_hal_Hwi_Module__id__C");
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__id ti_sysbios_hal_Hwi_Module__id__C = (xdc_Bits16)0x801c;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__loggerDefined__C, ".const:ti_sysbios_hal_Hwi_Module__loggerDefined__C");
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__loggerDefined ti_sysbios_hal_Hwi_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__loggerObj__C, ".const:ti_sysbios_hal_Hwi_Module__loggerObj__C");
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__loggerObj ti_sysbios_hal_Hwi_Module__loggerObj__C = ((CT__ti_sysbios_hal_Hwi_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__loggerFxn0__C, ".const:ti_sysbios_hal_Hwi_Module__loggerFxn0__C");
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__loggerFxn0 ti_sysbios_hal_Hwi_Module__loggerFxn0__C = ((CT__ti_sysbios_hal_Hwi_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__loggerFxn1__C, ".const:ti_sysbios_hal_Hwi_Module__loggerFxn1__C");
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__loggerFxn1 ti_sysbios_hal_Hwi_Module__loggerFxn1__C = ((CT__ti_sysbios_hal_Hwi_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__loggerFxn2__C, ".const:ti_sysbios_hal_Hwi_Module__loggerFxn2__C");
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__loggerFxn2 ti_sysbios_hal_Hwi_Module__loggerFxn2__C = ((CT__ti_sysbios_hal_Hwi_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__loggerFxn4__C, ".const:ti_sysbios_hal_Hwi_Module__loggerFxn4__C");
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__loggerFxn4 ti_sysbios_hal_Hwi_Module__loggerFxn4__C = ((CT__ti_sysbios_hal_Hwi_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__loggerFxn8__C, ".const:ti_sysbios_hal_Hwi_Module__loggerFxn8__C");
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__loggerFxn8 ti_sysbios_hal_Hwi_Module__loggerFxn8__C = ((CT__ti_sysbios_hal_Hwi_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__startupDoneFxn__C, ".const:ti_sysbios_hal_Hwi_Module__startupDoneFxn__C");
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__startupDoneFxn ti_sysbios_hal_Hwi_Module__startupDoneFxn__C = ((CT__ti_sysbios_hal_Hwi_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Object__count__C, ".const:ti_sysbios_hal_Hwi_Object__count__C");
__FAR__ const CT__ti_sysbios_hal_Hwi_Object__count ti_sysbios_hal_Hwi_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Object__heap__C, ".const:ti_sysbios_hal_Hwi_Object__heap__C");
__FAR__ const CT__ti_sysbios_hal_Hwi_Object__heap ti_sysbios_hal_Hwi_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Object__sizeof__C, ".const:ti_sysbios_hal_Hwi_Object__sizeof__C");
__FAR__ const CT__ti_sysbios_hal_Hwi_Object__sizeof ti_sysbios_hal_Hwi_Object__sizeof__C = sizeof(ti_sysbios_hal_Hwi_Object__);

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Object__table__C, ".const:ti_sysbios_hal_Hwi_Object__table__C");
__FAR__ const CT__ti_sysbios_hal_Hwi_Object__table ti_sysbios_hal_Hwi_Object__table__C = 0;

/* dispatcherAutoNestingSupport__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_dispatcherAutoNestingSupport__C, ".const:ti_sysbios_hal_Hwi_dispatcherAutoNestingSupport__C");
__FAR__ const CT__ti_sysbios_hal_Hwi_dispatcherAutoNestingSupport ti_sysbios_hal_Hwi_dispatcherAutoNestingSupport__C = 1;

/* dispatcherSwiSupport__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_dispatcherSwiSupport__C, ".const:ti_sysbios_hal_Hwi_dispatcherSwiSupport__C");
__FAR__ const CT__ti_sysbios_hal_Hwi_dispatcherSwiSupport ti_sysbios_hal_Hwi_dispatcherSwiSupport__C = 1;

/* dispatcherTaskSupport__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_dispatcherTaskSupport__C, ".const:ti_sysbios_hal_Hwi_dispatcherTaskSupport__C");
__FAR__ const CT__ti_sysbios_hal_Hwi_dispatcherTaskSupport ti_sysbios_hal_Hwi_dispatcherTaskSupport__C = 1;

/* dispatcherIrpTrackingSupport__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_dispatcherIrpTrackingSupport__C, ".const:ti_sysbios_hal_Hwi_dispatcherIrpTrackingSupport__C");
__FAR__ const CT__ti_sysbios_hal_Hwi_dispatcherIrpTrackingSupport ti_sysbios_hal_Hwi_dispatcherIrpTrackingSupport__C = 1;

/* E_stackOverflow__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_E_stackOverflow__C, ".const:ti_sysbios_hal_Hwi_E_stackOverflow__C");
__FAR__ const CT__ti_sysbios_hal_Hwi_E_stackOverflow ti_sysbios_hal_Hwi_E_stackOverflow__C = (((xdc_runtime_Error_Id)4787) << 16 | 0);


/*
 * ======== ti.sysbios.hal.Hwi_HwiProxy INITIALIZERS ========
 */


/*
 * ======== ti.sysbios.hal.ammu.AMMU INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_hal_ammu_AMMU_Module__diagsEnabled__C, ".const:ti_sysbios_hal_ammu_AMMU_Module__diagsEnabled__C");
__FAR__ const CT__ti_sysbios_hal_ammu_AMMU_Module__diagsEnabled ti_sysbios_hal_ammu_AMMU_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_hal_ammu_AMMU_Module__diagsIncluded__C, ".const:ti_sysbios_hal_ammu_AMMU_Module__diagsIncluded__C");
__FAR__ const CT__ti_sysbios_hal_ammu_AMMU_Module__diagsIncluded ti_sysbios_hal_ammu_AMMU_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_hal_ammu_AMMU_Module__diagsMask__C, ".const:ti_sysbios_hal_ammu_AMMU_Module__diagsMask__C");
__FAR__ const CT__ti_sysbios_hal_ammu_AMMU_Module__diagsMask ti_sysbios_hal_ammu_AMMU_Module__diagsMask__C = ((CT__ti_sysbios_hal_ammu_AMMU_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_hal_ammu_AMMU_Module__gateObj__C, ".const:ti_sysbios_hal_ammu_AMMU_Module__gateObj__C");
__FAR__ const CT__ti_sysbios_hal_ammu_AMMU_Module__gateObj ti_sysbios_hal_ammu_AMMU_Module__gateObj__C = ((CT__ti_sysbios_hal_ammu_AMMU_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_hal_ammu_AMMU_Module__gatePrms__C, ".const:ti_sysbios_hal_ammu_AMMU_Module__gatePrms__C");
__FAR__ const CT__ti_sysbios_hal_ammu_AMMU_Module__gatePrms ti_sysbios_hal_ammu_AMMU_Module__gatePrms__C = ((CT__ti_sysbios_hal_ammu_AMMU_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_hal_ammu_AMMU_Module__id__C, ".const:ti_sysbios_hal_ammu_AMMU_Module__id__C");
__FAR__ const CT__ti_sysbios_hal_ammu_AMMU_Module__id ti_sysbios_hal_ammu_AMMU_Module__id__C = (xdc_Bits16)0x802e;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_hal_ammu_AMMU_Module__loggerDefined__C, ".const:ti_sysbios_hal_ammu_AMMU_Module__loggerDefined__C");
__FAR__ const CT__ti_sysbios_hal_ammu_AMMU_Module__loggerDefined ti_sysbios_hal_ammu_AMMU_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_hal_ammu_AMMU_Module__loggerObj__C, ".const:ti_sysbios_hal_ammu_AMMU_Module__loggerObj__C");
__FAR__ const CT__ti_sysbios_hal_ammu_AMMU_Module__loggerObj ti_sysbios_hal_ammu_AMMU_Module__loggerObj__C = ((CT__ti_sysbios_hal_ammu_AMMU_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_hal_ammu_AMMU_Module__loggerFxn0__C, ".const:ti_sysbios_hal_ammu_AMMU_Module__loggerFxn0__C");
__FAR__ const CT__ti_sysbios_hal_ammu_AMMU_Module__loggerFxn0 ti_sysbios_hal_ammu_AMMU_Module__loggerFxn0__C = ((CT__ti_sysbios_hal_ammu_AMMU_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_hal_ammu_AMMU_Module__loggerFxn1__C, ".const:ti_sysbios_hal_ammu_AMMU_Module__loggerFxn1__C");
__FAR__ const CT__ti_sysbios_hal_ammu_AMMU_Module__loggerFxn1 ti_sysbios_hal_ammu_AMMU_Module__loggerFxn1__C = ((CT__ti_sysbios_hal_ammu_AMMU_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_hal_ammu_AMMU_Module__loggerFxn2__C, ".const:ti_sysbios_hal_ammu_AMMU_Module__loggerFxn2__C");
__FAR__ const CT__ti_sysbios_hal_ammu_AMMU_Module__loggerFxn2 ti_sysbios_hal_ammu_AMMU_Module__loggerFxn2__C = ((CT__ti_sysbios_hal_ammu_AMMU_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_hal_ammu_AMMU_Module__loggerFxn4__C, ".const:ti_sysbios_hal_ammu_AMMU_Module__loggerFxn4__C");
__FAR__ const CT__ti_sysbios_hal_ammu_AMMU_Module__loggerFxn4 ti_sysbios_hal_ammu_AMMU_Module__loggerFxn4__C = ((CT__ti_sysbios_hal_ammu_AMMU_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_hal_ammu_AMMU_Module__loggerFxn8__C, ".const:ti_sysbios_hal_ammu_AMMU_Module__loggerFxn8__C");
__FAR__ const CT__ti_sysbios_hal_ammu_AMMU_Module__loggerFxn8 ti_sysbios_hal_ammu_AMMU_Module__loggerFxn8__C = ((CT__ti_sysbios_hal_ammu_AMMU_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(ti_sysbios_hal_ammu_AMMU_Module__startupDoneFxn__C, ".const:ti_sysbios_hal_ammu_AMMU_Module__startupDoneFxn__C");
__FAR__ const CT__ti_sysbios_hal_ammu_AMMU_Module__startupDoneFxn ti_sysbios_hal_ammu_AMMU_Module__startupDoneFxn__C = ((CT__ti_sysbios_hal_ammu_AMMU_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_hal_ammu_AMMU_Object__count__C, ".const:ti_sysbios_hal_ammu_AMMU_Object__count__C");
__FAR__ const CT__ti_sysbios_hal_ammu_AMMU_Object__count ti_sysbios_hal_ammu_AMMU_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_hal_ammu_AMMU_Object__heap__C, ".const:ti_sysbios_hal_ammu_AMMU_Object__heap__C");
__FAR__ const CT__ti_sysbios_hal_ammu_AMMU_Object__heap ti_sysbios_hal_ammu_AMMU_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_hal_ammu_AMMU_Object__sizeof__C, ".const:ti_sysbios_hal_ammu_AMMU_Object__sizeof__C");
__FAR__ const CT__ti_sysbios_hal_ammu_AMMU_Object__sizeof ti_sysbios_hal_ammu_AMMU_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_hal_ammu_AMMU_Object__table__C, ".const:ti_sysbios_hal_ammu_AMMU_Object__table__C");
__FAR__ const CT__ti_sysbios_hal_ammu_AMMU_Object__table ti_sysbios_hal_ammu_AMMU_Object__table__C = 0;

/* configureAmmu__C */
#pragma DATA_SECTION(ti_sysbios_hal_ammu_AMMU_configureAmmu__C, ".const:ti_sysbios_hal_ammu_AMMU_configureAmmu__C");
__FAR__ const CT__ti_sysbios_hal_ammu_AMMU_configureAmmu ti_sysbios_hal_ammu_AMMU_configureAmmu__C = 1;

/* numLargePages__C */
#pragma DATA_SECTION(ti_sysbios_hal_ammu_AMMU_numLargePages__C, ".const:ti_sysbios_hal_ammu_AMMU_numLargePages__C");
__FAR__ const CT__ti_sysbios_hal_ammu_AMMU_numLargePages ti_sysbios_hal_ammu_AMMU_numLargePages__C = (xdc_UInt)0x4;

/* numMediumPages__C */
#pragma DATA_SECTION(ti_sysbios_hal_ammu_AMMU_numMediumPages__C, ".const:ti_sysbios_hal_ammu_AMMU_numMediumPages__C");
__FAR__ const CT__ti_sysbios_hal_ammu_AMMU_numMediumPages ti_sysbios_hal_ammu_AMMU_numMediumPages__C = (xdc_UInt)0x2;

/* numSmallPages__C */
#pragma DATA_SECTION(ti_sysbios_hal_ammu_AMMU_numSmallPages__C, ".const:ti_sysbios_hal_ammu_AMMU_numSmallPages__C");
__FAR__ const CT__ti_sysbios_hal_ammu_AMMU_numSmallPages ti_sysbios_hal_ammu_AMMU_numSmallPages__C = (xdc_UInt)0xa;

/* numLinePages__C */
#pragma DATA_SECTION(ti_sysbios_hal_ammu_AMMU_numLinePages__C, ".const:ti_sysbios_hal_ammu_AMMU_numLinePages__C");
__FAR__ const CT__ti_sysbios_hal_ammu_AMMU_numLinePages ti_sysbios_hal_ammu_AMMU_numLinePages__C = (xdc_UInt)0x0;

/* mmuInitConfig__C */
#pragma DATA_SECTION(ti_sysbios_hal_ammu_AMMU_mmuInitConfig__C, ".const:ti_sysbios_hal_ammu_AMMU_mmuInitConfig__C");
__FAR__ const CT__ti_sysbios_hal_ammu_AMMU_mmuInitConfig ti_sysbios_hal_ammu_AMMU_mmuInitConfig__C = {
    {
        ((xdc_Char*)0),  /* [0] */
        ((xdc_Char*)0),  /* [1] */
        ((xdc_Char*)0),  /* [2] */
        ((xdc_Char*)0),  /* [3] */
        ((xdc_Char*)0),  /* [4] */
        ((xdc_Char*)0),  /* [5] */
        ((xdc_Char*)0),  /* [6] */
        ((xdc_Char*)0),  /* [7] */
    },  /* LARGE_ADDR */
    {
        ((xdc_Char*)((-0x0 - 1))),  /* [0] */
        ((xdc_Char*)((-0x0 - 1))),  /* [1] */
        ((xdc_Char*)((-0x0 - 1))),  /* [2] */
        ((xdc_Char*)((-0x0 - 1))),  /* [3] */
        ((xdc_Char*)0),  /* [4] */
        ((xdc_Char*)0),  /* [5] */
        ((xdc_Char*)0),  /* [6] */
        ((xdc_Char*)0),  /* [7] */
    },  /* LARGE_XLTE */
    {
        (xdc_UInt32)0x0,  /* [0] */
        (xdc_UInt32)0x0,  /* [1] */
        (xdc_UInt32)0x0,  /* [2] */
        (xdc_UInt32)0x0,  /* [3] */
        (xdc_UInt32)0x0,  /* [4] */
        (xdc_UInt32)0x0,  /* [5] */
        (xdc_UInt32)0x0,  /* [6] */
        (xdc_UInt32)0x0,  /* [7] */
    },  /* LARGE_POLICY */
    {
        ((xdc_Char*)0),  /* [0] */
        ((xdc_Char*)0),  /* [1] */
        ((xdc_Char*)0),  /* [2] */
        ((xdc_Char*)0),  /* [3] */
        ((xdc_Char*)0),  /* [4] */
        ((xdc_Char*)0),  /* [5] */
        ((xdc_Char*)0),  /* [6] */
        ((xdc_Char*)0),  /* [7] */
        ((xdc_Char*)0),  /* [8] */
        ((xdc_Char*)0),  /* [9] */
        ((xdc_Char*)0),  /* [10] */
        ((xdc_Char*)0),  /* [11] */
        ((xdc_Char*)0),  /* [12] */
        ((xdc_Char*)0),  /* [13] */
        ((xdc_Char*)0),  /* [14] */
        ((xdc_Char*)0),  /* [15] */
    },  /* MEDIUM_ADDR */
    {
        ((xdc_Char*)((void*)0x1)),  /* [0] */
        ((xdc_Char*)((void*)0x1)),  /* [1] */
        ((xdc_Char*)0),  /* [2] */
        ((xdc_Char*)0),  /* [3] */
        ((xdc_Char*)0),  /* [4] */
        ((xdc_Char*)0),  /* [5] */
        ((xdc_Char*)0),  /* [6] */
        ((xdc_Char*)0),  /* [7] */
        ((xdc_Char*)0),  /* [8] */
        ((xdc_Char*)0),  /* [9] */
        ((xdc_Char*)0),  /* [10] */
        ((xdc_Char*)0),  /* [11] */
        ((xdc_Char*)0),  /* [12] */
        ((xdc_Char*)0),  /* [13] */
        ((xdc_Char*)0),  /* [14] */
        ((xdc_Char*)0),  /* [15] */
    },  /* MEDIUM_XLTE */
    {
        (xdc_UInt32)0x0,  /* [0] */
        (xdc_UInt32)0x0,  /* [1] */
        (xdc_UInt32)0x0,  /* [2] */
        (xdc_UInt32)0x0,  /* [3] */
        (xdc_UInt32)0x0,  /* [4] */
        (xdc_UInt32)0x0,  /* [5] */
        (xdc_UInt32)0x0,  /* [6] */
        (xdc_UInt32)0x0,  /* [7] */
        (xdc_UInt32)0x0,  /* [8] */
        (xdc_UInt32)0x0,  /* [9] */
        (xdc_UInt32)0x0,  /* [10] */
        (xdc_UInt32)0x0,  /* [11] */
        (xdc_UInt32)0x0,  /* [12] */
        (xdc_UInt32)0x0,  /* [13] */
        (xdc_UInt32)0x0,  /* [14] */
        (xdc_UInt32)0x0,  /* [15] */
    },  /* MEDIUM_POLICY */
    {
        ((xdc_Char*)0),  /* [0] */
        ((xdc_Char*)((void*)0x40000000)),  /* [1] */
        ((xdc_Char*)0),  /* [2] */
        ((xdc_Char*)0),  /* [3] */
        ((xdc_Char*)0),  /* [4] */
        ((xdc_Char*)0),  /* [5] */
        ((xdc_Char*)0),  /* [6] */
        ((xdc_Char*)0),  /* [7] */
        ((xdc_Char*)0),  /* [8] */
        ((xdc_Char*)0),  /* [9] */
        ((xdc_Char*)0),  /* [10] */
        ((xdc_Char*)0),  /* [11] */
        ((xdc_Char*)0),  /* [12] */
        ((xdc_Char*)0),  /* [13] */
        ((xdc_Char*)0),  /* [14] */
        ((xdc_Char*)0),  /* [15] */
        ((xdc_Char*)0),  /* [16] */
        ((xdc_Char*)0),  /* [17] */
        ((xdc_Char*)0),  /* [18] */
        ((xdc_Char*)0),  /* [19] */
        ((xdc_Char*)0),  /* [20] */
        ((xdc_Char*)0),  /* [21] */
        ((xdc_Char*)0),  /* [22] */
        ((xdc_Char*)0),  /* [23] */
        ((xdc_Char*)0),  /* [24] */
        ((xdc_Char*)0),  /* [25] */
        ((xdc_Char*)0),  /* [26] */
        ((xdc_Char*)0),  /* [27] */
        ((xdc_Char*)0),  /* [28] */
        ((xdc_Char*)0),  /* [29] */
        ((xdc_Char*)0),  /* [30] */
        ((xdc_Char*)0),  /* [31] */
    },  /* SMALL_ADDR */
    {
        ((xdc_Char*)((void*)0x1)),  /* [0] */
        ((xdc_Char*)((void*)0x55080000)),  /* [1] */
        ((xdc_Char*)((void*)0x1)),  /* [2] */
        ((xdc_Char*)((void*)0x1)),  /* [3] */
        ((xdc_Char*)((void*)0x1)),  /* [4] */
        ((xdc_Char*)((void*)0x1)),  /* [5] */
        ((xdc_Char*)((void*)0x1)),  /* [6] */
        ((xdc_Char*)((void*)0x1)),  /* [7] */
        ((xdc_Char*)((void*)0x1)),  /* [8] */
        ((xdc_Char*)((void*)0x1)),  /* [9] */
        ((xdc_Char*)0),  /* [10] */
        ((xdc_Char*)0),  /* [11] */
        ((xdc_Char*)0),  /* [12] */
        ((xdc_Char*)0),  /* [13] */
        ((xdc_Char*)0),  /* [14] */
        ((xdc_Char*)0),  /* [15] */
        ((xdc_Char*)0),  /* [16] */
        ((xdc_Char*)0),  /* [17] */
        ((xdc_Char*)0),  /* [18] */
        ((xdc_Char*)0),  /* [19] */
        ((xdc_Char*)0),  /* [20] */
        ((xdc_Char*)0),  /* [21] */
        ((xdc_Char*)0),  /* [22] */
        ((xdc_Char*)0),  /* [23] */
        ((xdc_Char*)0),  /* [24] */
        ((xdc_Char*)0),  /* [25] */
        ((xdc_Char*)0),  /* [26] */
        ((xdc_Char*)0),  /* [27] */
        ((xdc_Char*)0),  /* [28] */
        ((xdc_Char*)0),  /* [29] */
        ((xdc_Char*)0),  /* [30] */
        ((xdc_Char*)0),  /* [31] */
    },  /* SMALL_XLTE */
    {
        (xdc_UInt32)0x0,  /* [0] */
        (xdc_UInt32)0x3,  /* [1] */
        (xdc_UInt32)0x0,  /* [2] */
        (xdc_UInt32)0x0,  /* [3] */
        (xdc_UInt32)0x0,  /* [4] */
        (xdc_UInt32)0x0,  /* [5] */
        (xdc_UInt32)0x0,  /* [6] */
        (xdc_UInt32)0x0,  /* [7] */
        (xdc_UInt32)0x0,  /* [8] */
        (xdc_UInt32)0x0,  /* [9] */
        (xdc_UInt32)0x0,  /* [10] */
        (xdc_UInt32)0x0,  /* [11] */
        (xdc_UInt32)0x0,  /* [12] */
        (xdc_UInt32)0x0,  /* [13] */
        (xdc_UInt32)0x0,  /* [14] */
        (xdc_UInt32)0x0,  /* [15] */
        (xdc_UInt32)0x0,  /* [16] */
        (xdc_UInt32)0x0,  /* [17] */
        (xdc_UInt32)0x0,  /* [18] */
        (xdc_UInt32)0x0,  /* [19] */
        (xdc_UInt32)0x0,  /* [20] */
        (xdc_UInt32)0x0,  /* [21] */
        (xdc_UInt32)0x0,  /* [22] */
        (xdc_UInt32)0x0,  /* [23] */
        (xdc_UInt32)0x0,  /* [24] */
        (xdc_UInt32)0x0,  /* [25] */
        (xdc_UInt32)0x0,  /* [26] */
        (xdc_UInt32)0x0,  /* [27] */
        (xdc_UInt32)0x0,  /* [28] */
        (xdc_UInt32)0x0,  /* [29] */
        (xdc_UInt32)0x0,  /* [30] */
        (xdc_UInt32)0x0,  /* [31] */
    },  /* SMALL_POLICY */
    {
        (xdc_UInt32)0x0,  /* [0] */
        (xdc_UInt32)0x0,  /* [1] */
        (xdc_UInt32)0x0,  /* [2] */
        (xdc_UInt32)0x0,  /* [3] */
        (xdc_UInt32)0x0,  /* [4] */
        (xdc_UInt32)0x0,  /* [5] */
        (xdc_UInt32)0x0,  /* [6] */
        (xdc_UInt32)0x0,  /* [7] */
        (xdc_UInt32)0x0,  /* [8] */
        (xdc_UInt32)0x0,  /* [9] */
        (xdc_UInt32)0x0,  /* [10] */
        (xdc_UInt32)0x0,  /* [11] */
        (xdc_UInt32)0x0,  /* [12] */
        (xdc_UInt32)0x0,  /* [13] */
        (xdc_UInt32)0x0,  /* [14] */
        (xdc_UInt32)0x0,  /* [15] */
        (xdc_UInt32)0x0,  /* [16] */
        (xdc_UInt32)0x0,  /* [17] */
        (xdc_UInt32)0x0,  /* [18] */
        (xdc_UInt32)0x0,  /* [19] */
        (xdc_UInt32)0x0,  /* [20] */
        (xdc_UInt32)0x0,  /* [21] */
        (xdc_UInt32)0x0,  /* [22] */
        (xdc_UInt32)0x0,  /* [23] */
        (xdc_UInt32)0x0,  /* [24] */
        (xdc_UInt32)0x0,  /* [25] */
        (xdc_UInt32)0x0,  /* [26] */
        (xdc_UInt32)0x0,  /* [27] */
        (xdc_UInt32)0x0,  /* [28] */
        (xdc_UInt32)0x0,  /* [29] */
        (xdc_UInt32)0x0,  /* [30] */
        (xdc_UInt32)0x0,  /* [31] */
    },  /* SMALL_MAINT */
    {
        ((xdc_Char*)0),  /* [0] */
        ((xdc_Char*)0),  /* [1] */
        ((xdc_Char*)0),  /* [2] */
        ((xdc_Char*)0),  /* [3] */
        ((xdc_Char*)0),  /* [4] */
        ((xdc_Char*)0),  /* [5] */
        ((xdc_Char*)0),  /* [6] */
        ((xdc_Char*)0),  /* [7] */
        ((xdc_Char*)0),  /* [8] */
        ((xdc_Char*)0),  /* [9] */
        ((xdc_Char*)0),  /* [10] */
        ((xdc_Char*)0),  /* [11] */
        ((xdc_Char*)0),  /* [12] */
        ((xdc_Char*)0),  /* [13] */
        ((xdc_Char*)0),  /* [14] */
        ((xdc_Char*)0),  /* [15] */
        ((xdc_Char*)0),  /* [16] */
        ((xdc_Char*)0),  /* [17] */
        ((xdc_Char*)0),  /* [18] */
        ((xdc_Char*)0),  /* [19] */
        ((xdc_Char*)0),  /* [20] */
        ((xdc_Char*)0),  /* [21] */
        ((xdc_Char*)0),  /* [22] */
        ((xdc_Char*)0),  /* [23] */
        ((xdc_Char*)0),  /* [24] */
        ((xdc_Char*)0),  /* [25] */
        ((xdc_Char*)0),  /* [26] */
        ((xdc_Char*)0),  /* [27] */
        ((xdc_Char*)0),  /* [28] */
        ((xdc_Char*)0),  /* [29] */
        ((xdc_Char*)0),  /* [30] */
        ((xdc_Char*)0),  /* [31] */
    },  /* LINE_ADDR */
    {
        ((xdc_Char*)0),  /* [0] */
        ((xdc_Char*)0),  /* [1] */
        ((xdc_Char*)0),  /* [2] */
        ((xdc_Char*)0),  /* [3] */
        ((xdc_Char*)0),  /* [4] */
        ((xdc_Char*)0),  /* [5] */
        ((xdc_Char*)0),  /* [6] */
        ((xdc_Char*)0),  /* [7] */
        ((xdc_Char*)0),  /* [8] */
        ((xdc_Char*)0),  /* [9] */
        ((xdc_Char*)0),  /* [10] */
        ((xdc_Char*)0),  /* [11] */
        ((xdc_Char*)0),  /* [12] */
        ((xdc_Char*)0),  /* [13] */
        ((xdc_Char*)0),  /* [14] */
        ((xdc_Char*)0),  /* [15] */
        ((xdc_Char*)0),  /* [16] */
        ((xdc_Char*)0),  /* [17] */
        ((xdc_Char*)0),  /* [18] */
        ((xdc_Char*)0),  /* [19] */
        ((xdc_Char*)0),  /* [20] */
        ((xdc_Char*)0),  /* [21] */
        ((xdc_Char*)0),  /* [22] */
        ((xdc_Char*)0),  /* [23] */
        ((xdc_Char*)0),  /* [24] */
        ((xdc_Char*)0),  /* [25] */
        ((xdc_Char*)0),  /* [26] */
        ((xdc_Char*)0),  /* [27] */
        ((xdc_Char*)0),  /* [28] */
        ((xdc_Char*)0),  /* [29] */
        ((xdc_Char*)0),  /* [30] */
        ((xdc_Char*)0),  /* [31] */
    },  /* LINE_XLTE */
    {
        (xdc_UInt32)0x0,  /* [0] */
        (xdc_UInt32)0x0,  /* [1] */
        (xdc_UInt32)0x0,  /* [2] */
        (xdc_UInt32)0x0,  /* [3] */
        (xdc_UInt32)0x0,  /* [4] */
        (xdc_UInt32)0x0,  /* [5] */
        (xdc_UInt32)0x0,  /* [6] */
        (xdc_UInt32)0x0,  /* [7] */
        (xdc_UInt32)0x0,  /* [8] */
        (xdc_UInt32)0x0,  /* [9] */
        (xdc_UInt32)0x0,  /* [10] */
        (xdc_UInt32)0x0,  /* [11] */
        (xdc_UInt32)0x0,  /* [12] */
        (xdc_UInt32)0x0,  /* [13] */
        (xdc_UInt32)0x0,  /* [14] */
        (xdc_UInt32)0x0,  /* [15] */
        (xdc_UInt32)0x0,  /* [16] */
        (xdc_UInt32)0x0,  /* [17] */
        (xdc_UInt32)0x0,  /* [18] */
        (xdc_UInt32)0x0,  /* [19] */
        (xdc_UInt32)0x0,  /* [20] */
        (xdc_UInt32)0x0,  /* [21] */
        (xdc_UInt32)0x0,  /* [22] */
        (xdc_UInt32)0x0,  /* [23] */
        (xdc_UInt32)0x0,  /* [24] */
        (xdc_UInt32)0x0,  /* [25] */
        (xdc_UInt32)0x0,  /* [26] */
        (xdc_UInt32)0x0,  /* [27] */
        (xdc_UInt32)0x0,  /* [28] */
        (xdc_UInt32)0x0,  /* [29] */
        (xdc_UInt32)0x0,  /* [30] */
        (xdc_UInt32)0x0,  /* [31] */
    },  /* LINE_POLICY */
    ((xdc_Char*)((void*)0x1)),  /* DEBUG_XLTE */
    (xdc_UInt32)0x0,  /* DEBUG_POLICY */
    (xdc_UInt32)0x0,  /* MAINT */
    ((xdc_Char*)0),  /* MSTART */
    ((xdc_Char*)0),  /* MEND */
    (xdc_UInt32)0x0,  /* MSTAT */
};


/*
 * ======== ti.sysbios.hal.unicache.Cache INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_hal_unicache_Cache_Module__diagsEnabled__C, ".const:ti_sysbios_hal_unicache_Cache_Module__diagsEnabled__C");
__FAR__ const CT__ti_sysbios_hal_unicache_Cache_Module__diagsEnabled ti_sysbios_hal_unicache_Cache_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_hal_unicache_Cache_Module__diagsIncluded__C, ".const:ti_sysbios_hal_unicache_Cache_Module__diagsIncluded__C");
__FAR__ const CT__ti_sysbios_hal_unicache_Cache_Module__diagsIncluded ti_sysbios_hal_unicache_Cache_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_hal_unicache_Cache_Module__diagsMask__C, ".const:ti_sysbios_hal_unicache_Cache_Module__diagsMask__C");
__FAR__ const CT__ti_sysbios_hal_unicache_Cache_Module__diagsMask ti_sysbios_hal_unicache_Cache_Module__diagsMask__C = ((CT__ti_sysbios_hal_unicache_Cache_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_hal_unicache_Cache_Module__gateObj__C, ".const:ti_sysbios_hal_unicache_Cache_Module__gateObj__C");
__FAR__ const CT__ti_sysbios_hal_unicache_Cache_Module__gateObj ti_sysbios_hal_unicache_Cache_Module__gateObj__C = ((CT__ti_sysbios_hal_unicache_Cache_Module__gateObj)((void*)(xdc_runtime_IGateProvider_Handle)&ti_sysbios_family_arm_ducati_GateDualCore_Object__table__V[0]));

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_hal_unicache_Cache_Module__gatePrms__C, ".const:ti_sysbios_hal_unicache_Cache_Module__gatePrms__C");
__FAR__ const CT__ti_sysbios_hal_unicache_Cache_Module__gatePrms ti_sysbios_hal_unicache_Cache_Module__gatePrms__C = ((CT__ti_sysbios_hal_unicache_Cache_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_hal_unicache_Cache_Module__id__C, ".const:ti_sysbios_hal_unicache_Cache_Module__id__C");
__FAR__ const CT__ti_sysbios_hal_unicache_Cache_Module__id ti_sysbios_hal_unicache_Cache_Module__id__C = (xdc_Bits16)0x802c;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_hal_unicache_Cache_Module__loggerDefined__C, ".const:ti_sysbios_hal_unicache_Cache_Module__loggerDefined__C");
__FAR__ const CT__ti_sysbios_hal_unicache_Cache_Module__loggerDefined ti_sysbios_hal_unicache_Cache_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_hal_unicache_Cache_Module__loggerObj__C, ".const:ti_sysbios_hal_unicache_Cache_Module__loggerObj__C");
__FAR__ const CT__ti_sysbios_hal_unicache_Cache_Module__loggerObj ti_sysbios_hal_unicache_Cache_Module__loggerObj__C = ((CT__ti_sysbios_hal_unicache_Cache_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_hal_unicache_Cache_Module__loggerFxn0__C, ".const:ti_sysbios_hal_unicache_Cache_Module__loggerFxn0__C");
__FAR__ const CT__ti_sysbios_hal_unicache_Cache_Module__loggerFxn0 ti_sysbios_hal_unicache_Cache_Module__loggerFxn0__C = ((CT__ti_sysbios_hal_unicache_Cache_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_hal_unicache_Cache_Module__loggerFxn1__C, ".const:ti_sysbios_hal_unicache_Cache_Module__loggerFxn1__C");
__FAR__ const CT__ti_sysbios_hal_unicache_Cache_Module__loggerFxn1 ti_sysbios_hal_unicache_Cache_Module__loggerFxn1__C = ((CT__ti_sysbios_hal_unicache_Cache_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_hal_unicache_Cache_Module__loggerFxn2__C, ".const:ti_sysbios_hal_unicache_Cache_Module__loggerFxn2__C");
__FAR__ const CT__ti_sysbios_hal_unicache_Cache_Module__loggerFxn2 ti_sysbios_hal_unicache_Cache_Module__loggerFxn2__C = ((CT__ti_sysbios_hal_unicache_Cache_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_hal_unicache_Cache_Module__loggerFxn4__C, ".const:ti_sysbios_hal_unicache_Cache_Module__loggerFxn4__C");
__FAR__ const CT__ti_sysbios_hal_unicache_Cache_Module__loggerFxn4 ti_sysbios_hal_unicache_Cache_Module__loggerFxn4__C = ((CT__ti_sysbios_hal_unicache_Cache_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_hal_unicache_Cache_Module__loggerFxn8__C, ".const:ti_sysbios_hal_unicache_Cache_Module__loggerFxn8__C");
__FAR__ const CT__ti_sysbios_hal_unicache_Cache_Module__loggerFxn8 ti_sysbios_hal_unicache_Cache_Module__loggerFxn8__C = ((CT__ti_sysbios_hal_unicache_Cache_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(ti_sysbios_hal_unicache_Cache_Module__startupDoneFxn__C, ".const:ti_sysbios_hal_unicache_Cache_Module__startupDoneFxn__C");
__FAR__ const CT__ti_sysbios_hal_unicache_Cache_Module__startupDoneFxn ti_sysbios_hal_unicache_Cache_Module__startupDoneFxn__C = ((CT__ti_sysbios_hal_unicache_Cache_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_hal_unicache_Cache_Object__count__C, ".const:ti_sysbios_hal_unicache_Cache_Object__count__C");
__FAR__ const CT__ti_sysbios_hal_unicache_Cache_Object__count ti_sysbios_hal_unicache_Cache_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_hal_unicache_Cache_Object__heap__C, ".const:ti_sysbios_hal_unicache_Cache_Object__heap__C");
__FAR__ const CT__ti_sysbios_hal_unicache_Cache_Object__heap ti_sysbios_hal_unicache_Cache_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_hal_unicache_Cache_Object__sizeof__C, ".const:ti_sysbios_hal_unicache_Cache_Object__sizeof__C");
__FAR__ const CT__ti_sysbios_hal_unicache_Cache_Object__sizeof ti_sysbios_hal_unicache_Cache_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_hal_unicache_Cache_Object__table__C, ".const:ti_sysbios_hal_unicache_Cache_Object__table__C");
__FAR__ const CT__ti_sysbios_hal_unicache_Cache_Object__table ti_sysbios_hal_unicache_Cache_Object__table__C = 0;

/* E_exception__C */
#pragma DATA_SECTION(ti_sysbios_hal_unicache_Cache_E_exception__C, ".const:ti_sysbios_hal_unicache_Cache_E_exception__C");
__FAR__ const CT__ti_sysbios_hal_unicache_Cache_E_exception ti_sysbios_hal_unicache_Cache_E_exception__C = (((xdc_runtime_Error_Id)5541) << 16 | 0);

/* configureCache__C */
#pragma DATA_SECTION(ti_sysbios_hal_unicache_Cache_configureCache__C, ".const:ti_sysbios_hal_unicache_Cache_configureCache__C");
__FAR__ const CT__ti_sysbios_hal_unicache_Cache_configureCache ti_sysbios_hal_unicache_Cache_configureCache__C = 1;

/* enableCache__C */
#pragma DATA_SECTION(ti_sysbios_hal_unicache_Cache_enableCache__C, ".const:ti_sysbios_hal_unicache_Cache_enableCache__C");
__FAR__ const CT__ti_sysbios_hal_unicache_Cache_enableCache ti_sysbios_hal_unicache_Cache_enableCache__C = 1;

/* maxLineModeBufSize__C */
#pragma DATA_SECTION(ti_sysbios_hal_unicache_Cache_maxLineModeBufSize__C, ".const:ti_sysbios_hal_unicache_Cache_maxLineModeBufSize__C");
__FAR__ const CT__ti_sysbios_hal_unicache_Cache_maxLineModeBufSize ti_sysbios_hal_unicache_Cache_maxLineModeBufSize__C = (xdc_SizeT)0x400;

/* l1ocpConfig__C */
#pragma DATA_SECTION(ti_sysbios_hal_unicache_Cache_l1ocpConfig__C, ".const:ti_sysbios_hal_unicache_Cache_l1ocpConfig__C");
__FAR__ const CT__ti_sysbios_hal_unicache_Cache_l1ocpConfig ti_sysbios_hal_unicache_Cache_l1ocpConfig__C = (xdc_Bits32)0x0;

/* l1secConfig__C */
#pragma DATA_SECTION(ti_sysbios_hal_unicache_Cache_l1secConfig__C, ".const:ti_sysbios_hal_unicache_Cache_l1secConfig__C");
__FAR__ const CT__ti_sysbios_hal_unicache_Cache_l1secConfig ti_sysbios_hal_unicache_Cache_l1secConfig__C = (xdc_Bits32)0x1c;

/* l2ocpConfig__C */
#pragma DATA_SECTION(ti_sysbios_hal_unicache_Cache_l2ocpConfig__C, ".const:ti_sysbios_hal_unicache_Cache_l2ocpConfig__C");
__FAR__ const CT__ti_sysbios_hal_unicache_Cache_l2ocpConfig ti_sysbios_hal_unicache_Cache_l2ocpConfig__C = (xdc_Bits32)0x0;

/* l2secConfig__C */
#pragma DATA_SECTION(ti_sysbios_hal_unicache_Cache_l2secConfig__C, ".const:ti_sysbios_hal_unicache_Cache_l2secConfig__C");
__FAR__ const CT__ti_sysbios_hal_unicache_Cache_l2secConfig ti_sysbios_hal_unicache_Cache_l2secConfig__C = (xdc_Bits32)0x1c;

/* l2CacheSupported__C */
#pragma DATA_SECTION(ti_sysbios_hal_unicache_Cache_l2CacheSupported__C, ".const:ti_sysbios_hal_unicache_Cache_l2CacheSupported__C");
__FAR__ const CT__ti_sysbios_hal_unicache_Cache_l2CacheSupported ti_sysbios_hal_unicache_Cache_l2CacheSupported__C = 0;


/*
 * ======== ti.sysbios.hal.unicache.Cache_Module_GateProxy INITIALIZERS ========
 */


/*
 * ======== ti.sysbios.heaps.HeapMem INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_heaps_HeapMem_Object__DESC__C;

/* Object__PARAMS__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Object__PARAMS__C, ".const:ti_sysbios_heaps_HeapMem_Object__PARAMS__C");
__FAR__ const ti_sysbios_heaps_HeapMem_Params ti_sysbios_heaps_HeapMem_Object__PARAMS__C = {
    sizeof (ti_sysbios_heaps_HeapMem_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_heaps_HeapMem_Object__PARAMS__C.__iprms, /* instance */
    (xdc_SizeT)0x0,  /* minBlockAlign */
    ((xdc_Ptr)(0x0)),  /* buf */
    ((xdc_UArg)(0x0)),  /* size */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* --> ti_sysbios_heaps_HeapMem_Instance_State_0_buf__A */
__T1_ti_sysbios_heaps_HeapMem_Instance_State__buf ti_sysbios_heaps_HeapMem_Instance_State_0_buf__A[86016];

/* Module__root__V */
ti_sysbios_heaps_HeapMem_Module__ ti_sysbios_heaps_HeapMem_Module__root__V = {
    {&ti_sysbios_heaps_HeapMem_Module__root__V.link,  /* link.next */
    &ti_sysbios_heaps_HeapMem_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_heaps_HeapMem_Object__ ti_sysbios_heaps_HeapMem_Object__table__V[1] = {
    {/* instance#0 */
        &ti_sysbios_heaps_HeapMem_Module__FXNS__C,
        ((xdc_UArg)(0x8)),  /* align */
        ((void*)ti_sysbios_heaps_HeapMem_Instance_State_0_buf__A),  /* buf */
        {
            ((ti_sysbios_heaps_HeapMem_Header*)0),  /* next */
            ((xdc_UArg)(0x15000)),  /* size */
        },  /* head */
        (xdc_SizeT)0x8,  /* minBlockAlign */
    },
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__diagsEnabled__C, ".const:ti_sysbios_heaps_HeapMem_Module__diagsEnabled__C");
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__diagsEnabled ti_sysbios_heaps_HeapMem_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__diagsIncluded__C, ".const:ti_sysbios_heaps_HeapMem_Module__diagsIncluded__C");
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__diagsIncluded ti_sysbios_heaps_HeapMem_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__diagsMask__C, ".const:ti_sysbios_heaps_HeapMem_Module__diagsMask__C");
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__diagsMask ti_sysbios_heaps_HeapMem_Module__diagsMask__C = ((CT__ti_sysbios_heaps_HeapMem_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__gateObj__C, ".const:ti_sysbios_heaps_HeapMem_Module__gateObj__C");
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__gateObj ti_sysbios_heaps_HeapMem_Module__gateObj__C = ((CT__ti_sysbios_heaps_HeapMem_Module__gateObj)((void*)(xdc_runtime_IGateProvider_Handle)&ti_sysbios_gates_GateMutex_Object__table__V[0]));

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__gatePrms__C, ".const:ti_sysbios_heaps_HeapMem_Module__gatePrms__C");
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__gatePrms ti_sysbios_heaps_HeapMem_Module__gatePrms__C = ((CT__ti_sysbios_heaps_HeapMem_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__id__C, ".const:ti_sysbios_heaps_HeapMem_Module__id__C");
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__id ti_sysbios_heaps_HeapMem_Module__id__C = (xdc_Bits16)0x8033;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__loggerDefined__C, ".const:ti_sysbios_heaps_HeapMem_Module__loggerDefined__C");
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__loggerDefined ti_sysbios_heaps_HeapMem_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__loggerObj__C, ".const:ti_sysbios_heaps_HeapMem_Module__loggerObj__C");
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__loggerObj ti_sysbios_heaps_HeapMem_Module__loggerObj__C = ((CT__ti_sysbios_heaps_HeapMem_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__loggerFxn0__C, ".const:ti_sysbios_heaps_HeapMem_Module__loggerFxn0__C");
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn0 ti_sysbios_heaps_HeapMem_Module__loggerFxn0__C = ((CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__loggerFxn1__C, ".const:ti_sysbios_heaps_HeapMem_Module__loggerFxn1__C");
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn1 ti_sysbios_heaps_HeapMem_Module__loggerFxn1__C = ((CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__loggerFxn2__C, ".const:ti_sysbios_heaps_HeapMem_Module__loggerFxn2__C");
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn2 ti_sysbios_heaps_HeapMem_Module__loggerFxn2__C = ((CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__loggerFxn4__C, ".const:ti_sysbios_heaps_HeapMem_Module__loggerFxn4__C");
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn4 ti_sysbios_heaps_HeapMem_Module__loggerFxn4__C = ((CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__loggerFxn8__C, ".const:ti_sysbios_heaps_HeapMem_Module__loggerFxn8__C");
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn8 ti_sysbios_heaps_HeapMem_Module__loggerFxn8__C = ((CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__startupDoneFxn__C, ".const:ti_sysbios_heaps_HeapMem_Module__startupDoneFxn__C");
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__startupDoneFxn ti_sysbios_heaps_HeapMem_Module__startupDoneFxn__C = ((CT__ti_sysbios_heaps_HeapMem_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Object__count__C, ".const:ti_sysbios_heaps_HeapMem_Object__count__C");
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Object__count ti_sysbios_heaps_HeapMem_Object__count__C = 1;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Object__heap__C, ".const:ti_sysbios_heaps_HeapMem_Object__heap__C");
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Object__heap ti_sysbios_heaps_HeapMem_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Object__sizeof__C, ".const:ti_sysbios_heaps_HeapMem_Object__sizeof__C");
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Object__sizeof ti_sysbios_heaps_HeapMem_Object__sizeof__C = sizeof(ti_sysbios_heaps_HeapMem_Object__);

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Object__table__C, ".const:ti_sysbios_heaps_HeapMem_Object__table__C");
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Object__table ti_sysbios_heaps_HeapMem_Object__table__C = ti_sysbios_heaps_HeapMem_Object__table__V;

/* A_zeroBlock__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_A_zeroBlock__C, ".const:ti_sysbios_heaps_HeapMem_A_zeroBlock__C");
__FAR__ const CT__ti_sysbios_heaps_HeapMem_A_zeroBlock ti_sysbios_heaps_HeapMem_A_zeroBlock__C = (((xdc_runtime_Assert_Id)3939) << 16 | 16);

/* A_heapSize__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_A_heapSize__C, ".const:ti_sysbios_heaps_HeapMem_A_heapSize__C");
__FAR__ const CT__ti_sysbios_heaps_HeapMem_A_heapSize ti_sysbios_heaps_HeapMem_A_heapSize__C = (((xdc_runtime_Assert_Id)3975) << 16 | 16);

/* A_align__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_A_align__C, ".const:ti_sysbios_heaps_HeapMem_A_align__C");
__FAR__ const CT__ti_sysbios_heaps_HeapMem_A_align ti_sysbios_heaps_HeapMem_A_align__C = (((xdc_runtime_Assert_Id)4020) << 16 | 16);

/* E_memory__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_E_memory__C, ".const:ti_sysbios_heaps_HeapMem_E_memory__C");
__FAR__ const CT__ti_sysbios_heaps_HeapMem_E_memory ti_sysbios_heaps_HeapMem_E_memory__C = (((xdc_runtime_Error_Id)5661) << 16 | 0);

/* A_invalidFree__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_A_invalidFree__C, ".const:ti_sysbios_heaps_HeapMem_A_invalidFree__C");
__FAR__ const CT__ti_sysbios_heaps_HeapMem_A_invalidFree ti_sysbios_heaps_HeapMem_A_invalidFree__C = (((xdc_runtime_Assert_Id)3911) << 16 | 16);

/* primaryHeapBaseAddr__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_primaryHeapBaseAddr__C, ".const:ti_sysbios_heaps_HeapMem_primaryHeapBaseAddr__C");
__FAR__ const CT__ti_sysbios_heaps_HeapMem_primaryHeapBaseAddr ti_sysbios_heaps_HeapMem_primaryHeapBaseAddr__C = ((CT__ti_sysbios_heaps_HeapMem_primaryHeapBaseAddr)0);

/* primaryHeapEndAddr__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_primaryHeapEndAddr__C, ".const:ti_sysbios_heaps_HeapMem_primaryHeapEndAddr__C");
__FAR__ const CT__ti_sysbios_heaps_HeapMem_primaryHeapEndAddr ti_sysbios_heaps_HeapMem_primaryHeapEndAddr__C = ((CT__ti_sysbios_heaps_HeapMem_primaryHeapEndAddr)0);

/* reqAlign__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_reqAlign__C, ".const:ti_sysbios_heaps_HeapMem_reqAlign__C");
__FAR__ const CT__ti_sysbios_heaps_HeapMem_reqAlign ti_sysbios_heaps_HeapMem_reqAlign__C = (xdc_SizeT)0x8;


/*
 * ======== ti.sysbios.heaps.HeapMem_Module_GateProxy INITIALIZERS ========
 */


/*
 * ======== ti.sysbios.knl.Clock INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Clock_Object__DESC__C;

/* Object__PARAMS__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Object__PARAMS__C, ".const:ti_sysbios_knl_Clock_Object__PARAMS__C");
__FAR__ const ti_sysbios_knl_Clock_Params ti_sysbios_knl_Clock_Object__PARAMS__C = {
    sizeof (ti_sysbios_knl_Clock_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_knl_Clock_Object__PARAMS__C.__iprms, /* instance */
    0,  /* startFlag */
    (xdc_UInt32)0x0,  /* period */
    ((xdc_UArg)0),  /* arg */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_knl_Clock_Module__ ti_sysbios_knl_Clock_Module__root__V = {
    {&ti_sysbios_knl_Clock_Module__root__V.link,  /* link.next */
    &ti_sysbios_knl_Clock_Module__root__V.link},  /* link.prev */
};

/* Module__state__V */
#if defined (__ICCARM__)
#pragma location = ".data_ti_sysbios_knl_Clock_Module__state__V"
#endif
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
#ifndef __TI_COMPILER_VERSION__
ti_sysbios_knl_Clock_Module_State__ ti_sysbios_knl_Clock_Module__state__V __attribute__ ((section(".data_ti_sysbios_knl_Clock_Module__state__V")));
#endif
#endif
ti_sysbios_knl_Clock_Module_State__ ti_sysbios_knl_Clock_Module__state__V = {
    (xdc_UInt32)0x0,  /* ticks */
    (xdc_UInt)0x0,  /* swiCount */
    (ti_sysbios_knl_Clock_TimerProxy_Handle)&ti_sysbios_family_arm_ducati_Timer_Object__table__V[0],  /* timer */
    (ti_sysbios_knl_Swi_Handle)&ti_sysbios_knl_Swi_Object__table__V[0],  /* swi */
    (xdc_UInt)0x1,  /* numTickSkip */
    (xdc_UInt32)0x1,  /* nextScheduledTick */
    (xdc_UInt32)0x0,  /* maxSkippable */
    0,  /* inWorkFunc */
    0,  /* startDuringWorkFunc */
    0,  /* ticking */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Clock_Module__state__V.Object_field_clockQ.elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Clock_Module__state__V.Object_field_clockQ.elem)),  /* prev */
        },  /* elem */
    },  /* Object_field_clockQ */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__diagsEnabled__C, ".const:ti_sysbios_knl_Clock_Module__diagsEnabled__C");
__FAR__ const CT__ti_sysbios_knl_Clock_Module__diagsEnabled ti_sysbios_knl_Clock_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__diagsIncluded__C, ".const:ti_sysbios_knl_Clock_Module__diagsIncluded__C");
__FAR__ const CT__ti_sysbios_knl_Clock_Module__diagsIncluded ti_sysbios_knl_Clock_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__diagsMask__C, ".const:ti_sysbios_knl_Clock_Module__diagsMask__C");
__FAR__ const CT__ti_sysbios_knl_Clock_Module__diagsMask ti_sysbios_knl_Clock_Module__diagsMask__C = ((CT__ti_sysbios_knl_Clock_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__gateObj__C, ".const:ti_sysbios_knl_Clock_Module__gateObj__C");
__FAR__ const CT__ti_sysbios_knl_Clock_Module__gateObj ti_sysbios_knl_Clock_Module__gateObj__C = ((CT__ti_sysbios_knl_Clock_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__gatePrms__C, ".const:ti_sysbios_knl_Clock_Module__gatePrms__C");
__FAR__ const CT__ti_sysbios_knl_Clock_Module__gatePrms ti_sysbios_knl_Clock_Module__gatePrms__C = ((CT__ti_sysbios_knl_Clock_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__id__C, ".const:ti_sysbios_knl_Clock_Module__id__C");
__FAR__ const CT__ti_sysbios_knl_Clock_Module__id ti_sysbios_knl_Clock_Module__id__C = (xdc_Bits16)0x8012;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__loggerDefined__C, ".const:ti_sysbios_knl_Clock_Module__loggerDefined__C");
__FAR__ const CT__ti_sysbios_knl_Clock_Module__loggerDefined ti_sysbios_knl_Clock_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__loggerObj__C, ".const:ti_sysbios_knl_Clock_Module__loggerObj__C");
__FAR__ const CT__ti_sysbios_knl_Clock_Module__loggerObj ti_sysbios_knl_Clock_Module__loggerObj__C = ((CT__ti_sysbios_knl_Clock_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__loggerFxn0__C, ".const:ti_sysbios_knl_Clock_Module__loggerFxn0__C");
__FAR__ const CT__ti_sysbios_knl_Clock_Module__loggerFxn0 ti_sysbios_knl_Clock_Module__loggerFxn0__C = ((CT__ti_sysbios_knl_Clock_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__loggerFxn1__C, ".const:ti_sysbios_knl_Clock_Module__loggerFxn1__C");
__FAR__ const CT__ti_sysbios_knl_Clock_Module__loggerFxn1 ti_sysbios_knl_Clock_Module__loggerFxn1__C = ((CT__ti_sysbios_knl_Clock_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__loggerFxn2__C, ".const:ti_sysbios_knl_Clock_Module__loggerFxn2__C");
__FAR__ const CT__ti_sysbios_knl_Clock_Module__loggerFxn2 ti_sysbios_knl_Clock_Module__loggerFxn2__C = ((CT__ti_sysbios_knl_Clock_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__loggerFxn4__C, ".const:ti_sysbios_knl_Clock_Module__loggerFxn4__C");
__FAR__ const CT__ti_sysbios_knl_Clock_Module__loggerFxn4 ti_sysbios_knl_Clock_Module__loggerFxn4__C = ((CT__ti_sysbios_knl_Clock_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__loggerFxn8__C, ".const:ti_sysbios_knl_Clock_Module__loggerFxn8__C");
__FAR__ const CT__ti_sysbios_knl_Clock_Module__loggerFxn8 ti_sysbios_knl_Clock_Module__loggerFxn8__C = ((CT__ti_sysbios_knl_Clock_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__startupDoneFxn__C, ".const:ti_sysbios_knl_Clock_Module__startupDoneFxn__C");
__FAR__ const CT__ti_sysbios_knl_Clock_Module__startupDoneFxn ti_sysbios_knl_Clock_Module__startupDoneFxn__C = ((CT__ti_sysbios_knl_Clock_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Object__count__C, ".const:ti_sysbios_knl_Clock_Object__count__C");
__FAR__ const CT__ti_sysbios_knl_Clock_Object__count ti_sysbios_knl_Clock_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Object__heap__C, ".const:ti_sysbios_knl_Clock_Object__heap__C");
__FAR__ const CT__ti_sysbios_knl_Clock_Object__heap ti_sysbios_knl_Clock_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Object__sizeof__C, ".const:ti_sysbios_knl_Clock_Object__sizeof__C");
__FAR__ const CT__ti_sysbios_knl_Clock_Object__sizeof ti_sysbios_knl_Clock_Object__sizeof__C = sizeof(ti_sysbios_knl_Clock_Object__);

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Object__table__C, ".const:ti_sysbios_knl_Clock_Object__table__C");
__FAR__ const CT__ti_sysbios_knl_Clock_Object__table ti_sysbios_knl_Clock_Object__table__C = 0;

/* LW_delayed__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_LW_delayed__C, ".const:ti_sysbios_knl_Clock_LW_delayed__C");
__FAR__ const CT__ti_sysbios_knl_Clock_LW_delayed ti_sysbios_knl_Clock_LW_delayed__C = (((xdc_runtime_Log_Event)5873) << 16 | 1024);

/* LM_tick__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_LM_tick__C, ".const:ti_sysbios_knl_Clock_LM_tick__C");
__FAR__ const CT__ti_sysbios_knl_Clock_LM_tick ti_sysbios_knl_Clock_LM_tick__C = (((xdc_runtime_Log_Event)5895) << 16 | 768);

/* LM_begin__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_LM_begin__C, ".const:ti_sysbios_knl_Clock_LM_begin__C");
__FAR__ const CT__ti_sysbios_knl_Clock_LM_begin ti_sysbios_knl_Clock_LM_begin__C = (((xdc_runtime_Log_Event)5913) << 16 | 768);

/* A_clockDisabled__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_A_clockDisabled__C, ".const:ti_sysbios_knl_Clock_A_clockDisabled__C");
__FAR__ const CT__ti_sysbios_knl_Clock_A_clockDisabled ti_sysbios_knl_Clock_A_clockDisabled__C = (((xdc_runtime_Assert_Id)553) << 16 | 16);

/* A_badThreadType__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_A_badThreadType__C, ".const:ti_sysbios_knl_Clock_A_badThreadType__C");
__FAR__ const CT__ti_sysbios_knl_Clock_A_badThreadType ti_sysbios_knl_Clock_A_badThreadType__C = (((xdc_runtime_Assert_Id)634) << 16 | 16);

/* serviceMargin__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_serviceMargin__C, ".const:ti_sysbios_knl_Clock_serviceMargin__C");
__FAR__ const CT__ti_sysbios_knl_Clock_serviceMargin ti_sysbios_knl_Clock_serviceMargin__C = (xdc_UInt32)0x0;

/* tickSource__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_tickSource__C, ".const:ti_sysbios_knl_Clock_tickSource__C");
__FAR__ const CT__ti_sysbios_knl_Clock_tickSource ti_sysbios_knl_Clock_tickSource__C = ti_sysbios_knl_Clock_TickSource_TIMER;

/* tickMode__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_tickMode__C, ".const:ti_sysbios_knl_Clock_tickMode__C");
__FAR__ const CT__ti_sysbios_knl_Clock_tickMode ti_sysbios_knl_Clock_tickMode__C = ti_sysbios_knl_Clock_TickMode_PERIODIC;

/* timerId__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_timerId__C, ".const:ti_sysbios_knl_Clock_timerId__C");
__FAR__ const CT__ti_sysbios_knl_Clock_timerId ti_sysbios_knl_Clock_timerId__C = (xdc_UInt)(-0x0 - 1);

/* tickPeriod__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_tickPeriod__C, ".const:ti_sysbios_knl_Clock_tickPeriod__C");
__FAR__ const CT__ti_sysbios_knl_Clock_tickPeriod ti_sysbios_knl_Clock_tickPeriod__C = (xdc_UInt32)0x3e8;

/* doTickFunc__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_doTickFunc__C, ".const:ti_sysbios_knl_Clock_doTickFunc__C");
__FAR__ const CT__ti_sysbios_knl_Clock_doTickFunc ti_sysbios_knl_Clock_doTickFunc__C = ((CT__ti_sysbios_knl_Clock_doTickFunc)((xdc_Fxn)ti_sysbios_knl_Clock_doTick__I));

/* triggerClock__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_triggerClock__C, ".const:ti_sysbios_knl_Clock_triggerClock__C");
__FAR__ const CT__ti_sysbios_knl_Clock_triggerClock ti_sysbios_knl_Clock_triggerClock__C = 0;


/*
 * ======== ti.sysbios.knl.Clock_TimerProxy INITIALIZERS ========
 */


/*
 * ======== ti.sysbios.knl.Idle INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__diagsEnabled__C, ".const:ti_sysbios_knl_Idle_Module__diagsEnabled__C");
__FAR__ const CT__ti_sysbios_knl_Idle_Module__diagsEnabled ti_sysbios_knl_Idle_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__diagsIncluded__C, ".const:ti_sysbios_knl_Idle_Module__diagsIncluded__C");
__FAR__ const CT__ti_sysbios_knl_Idle_Module__diagsIncluded ti_sysbios_knl_Idle_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__diagsMask__C, ".const:ti_sysbios_knl_Idle_Module__diagsMask__C");
__FAR__ const CT__ti_sysbios_knl_Idle_Module__diagsMask ti_sysbios_knl_Idle_Module__diagsMask__C = ((CT__ti_sysbios_knl_Idle_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__gateObj__C, ".const:ti_sysbios_knl_Idle_Module__gateObj__C");
__FAR__ const CT__ti_sysbios_knl_Idle_Module__gateObj ti_sysbios_knl_Idle_Module__gateObj__C = ((CT__ti_sysbios_knl_Idle_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__gatePrms__C, ".const:ti_sysbios_knl_Idle_Module__gatePrms__C");
__FAR__ const CT__ti_sysbios_knl_Idle_Module__gatePrms ti_sysbios_knl_Idle_Module__gatePrms__C = ((CT__ti_sysbios_knl_Idle_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__id__C, ".const:ti_sysbios_knl_Idle_Module__id__C");
__FAR__ const CT__ti_sysbios_knl_Idle_Module__id ti_sysbios_knl_Idle_Module__id__C = (xdc_Bits16)0x8013;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__loggerDefined__C, ".const:ti_sysbios_knl_Idle_Module__loggerDefined__C");
__FAR__ const CT__ti_sysbios_knl_Idle_Module__loggerDefined ti_sysbios_knl_Idle_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__loggerObj__C, ".const:ti_sysbios_knl_Idle_Module__loggerObj__C");
__FAR__ const CT__ti_sysbios_knl_Idle_Module__loggerObj ti_sysbios_knl_Idle_Module__loggerObj__C = ((CT__ti_sysbios_knl_Idle_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__loggerFxn0__C, ".const:ti_sysbios_knl_Idle_Module__loggerFxn0__C");
__FAR__ const CT__ti_sysbios_knl_Idle_Module__loggerFxn0 ti_sysbios_knl_Idle_Module__loggerFxn0__C = ((CT__ti_sysbios_knl_Idle_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__loggerFxn1__C, ".const:ti_sysbios_knl_Idle_Module__loggerFxn1__C");
__FAR__ const CT__ti_sysbios_knl_Idle_Module__loggerFxn1 ti_sysbios_knl_Idle_Module__loggerFxn1__C = ((CT__ti_sysbios_knl_Idle_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__loggerFxn2__C, ".const:ti_sysbios_knl_Idle_Module__loggerFxn2__C");
__FAR__ const CT__ti_sysbios_knl_Idle_Module__loggerFxn2 ti_sysbios_knl_Idle_Module__loggerFxn2__C = ((CT__ti_sysbios_knl_Idle_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__loggerFxn4__C, ".const:ti_sysbios_knl_Idle_Module__loggerFxn4__C");
__FAR__ const CT__ti_sysbios_knl_Idle_Module__loggerFxn4 ti_sysbios_knl_Idle_Module__loggerFxn4__C = ((CT__ti_sysbios_knl_Idle_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__loggerFxn8__C, ".const:ti_sysbios_knl_Idle_Module__loggerFxn8__C");
__FAR__ const CT__ti_sysbios_knl_Idle_Module__loggerFxn8 ti_sysbios_knl_Idle_Module__loggerFxn8__C = ((CT__ti_sysbios_knl_Idle_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__startupDoneFxn__C, ".const:ti_sysbios_knl_Idle_Module__startupDoneFxn__C");
__FAR__ const CT__ti_sysbios_knl_Idle_Module__startupDoneFxn ti_sysbios_knl_Idle_Module__startupDoneFxn__C = ((CT__ti_sysbios_knl_Idle_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Object__count__C, ".const:ti_sysbios_knl_Idle_Object__count__C");
__FAR__ const CT__ti_sysbios_knl_Idle_Object__count ti_sysbios_knl_Idle_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Object__heap__C, ".const:ti_sysbios_knl_Idle_Object__heap__C");
__FAR__ const CT__ti_sysbios_knl_Idle_Object__heap ti_sysbios_knl_Idle_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Object__sizeof__C, ".const:ti_sysbios_knl_Idle_Object__sizeof__C");
__FAR__ const CT__ti_sysbios_knl_Idle_Object__sizeof ti_sysbios_knl_Idle_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Object__table__C, ".const:ti_sysbios_knl_Idle_Object__table__C");
__FAR__ const CT__ti_sysbios_knl_Idle_Object__table ti_sysbios_knl_Idle_Object__table__C = 0;

/* funcList__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_funcList__C, ".const:ti_sysbios_knl_Idle_funcList__C");
__FAR__ const CT__ti_sysbios_knl_Idle_funcList ti_sysbios_knl_Idle_funcList__C = {0, 0};

/* coreList__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_coreList__C, ".const:ti_sysbios_knl_Idle_coreList__C");
__FAR__ const CT__ti_sysbios_knl_Idle_coreList ti_sysbios_knl_Idle_coreList__C = {0, 0};


/*
 * ======== ti.sysbios.knl.Intrinsics INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__diagsEnabled__C, ".const:ti_sysbios_knl_Intrinsics_Module__diagsEnabled__C");
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__diagsEnabled ti_sysbios_knl_Intrinsics_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__diagsIncluded__C, ".const:ti_sysbios_knl_Intrinsics_Module__diagsIncluded__C");
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__diagsIncluded ti_sysbios_knl_Intrinsics_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__diagsMask__C, ".const:ti_sysbios_knl_Intrinsics_Module__diagsMask__C");
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__diagsMask ti_sysbios_knl_Intrinsics_Module__diagsMask__C = ((CT__ti_sysbios_knl_Intrinsics_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__gateObj__C, ".const:ti_sysbios_knl_Intrinsics_Module__gateObj__C");
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__gateObj ti_sysbios_knl_Intrinsics_Module__gateObj__C = ((CT__ti_sysbios_knl_Intrinsics_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__gatePrms__C, ".const:ti_sysbios_knl_Intrinsics_Module__gatePrms__C");
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__gatePrms ti_sysbios_knl_Intrinsics_Module__gatePrms__C = ((CT__ti_sysbios_knl_Intrinsics_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__id__C, ".const:ti_sysbios_knl_Intrinsics_Module__id__C");
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__id ti_sysbios_knl_Intrinsics_Module__id__C = (xdc_Bits16)0x8014;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__loggerDefined__C, ".const:ti_sysbios_knl_Intrinsics_Module__loggerDefined__C");
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__loggerDefined ti_sysbios_knl_Intrinsics_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__loggerObj__C, ".const:ti_sysbios_knl_Intrinsics_Module__loggerObj__C");
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__loggerObj ti_sysbios_knl_Intrinsics_Module__loggerObj__C = ((CT__ti_sysbios_knl_Intrinsics_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__loggerFxn0__C, ".const:ti_sysbios_knl_Intrinsics_Module__loggerFxn0__C");
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn0 ti_sysbios_knl_Intrinsics_Module__loggerFxn0__C = ((CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__loggerFxn1__C, ".const:ti_sysbios_knl_Intrinsics_Module__loggerFxn1__C");
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn1 ti_sysbios_knl_Intrinsics_Module__loggerFxn1__C = ((CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__loggerFxn2__C, ".const:ti_sysbios_knl_Intrinsics_Module__loggerFxn2__C");
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn2 ti_sysbios_knl_Intrinsics_Module__loggerFxn2__C = ((CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__loggerFxn4__C, ".const:ti_sysbios_knl_Intrinsics_Module__loggerFxn4__C");
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn4 ti_sysbios_knl_Intrinsics_Module__loggerFxn4__C = ((CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__loggerFxn8__C, ".const:ti_sysbios_knl_Intrinsics_Module__loggerFxn8__C");
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn8 ti_sysbios_knl_Intrinsics_Module__loggerFxn8__C = ((CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__startupDoneFxn__C, ".const:ti_sysbios_knl_Intrinsics_Module__startupDoneFxn__C");
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__startupDoneFxn ti_sysbios_knl_Intrinsics_Module__startupDoneFxn__C = ((CT__ti_sysbios_knl_Intrinsics_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Object__count__C, ".const:ti_sysbios_knl_Intrinsics_Object__count__C");
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Object__count ti_sysbios_knl_Intrinsics_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Object__heap__C, ".const:ti_sysbios_knl_Intrinsics_Object__heap__C");
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Object__heap ti_sysbios_knl_Intrinsics_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Object__sizeof__C, ".const:ti_sysbios_knl_Intrinsics_Object__sizeof__C");
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Object__sizeof ti_sysbios_knl_Intrinsics_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Object__table__C, ".const:ti_sysbios_knl_Intrinsics_Object__table__C");
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Object__table ti_sysbios_knl_Intrinsics_Object__table__C = 0;


/*
 * ======== ti.sysbios.knl.Intrinsics_SupportProxy INITIALIZERS ========
 */


/*
 * ======== ti.sysbios.knl.Queue INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Queue_Object__DESC__C;

/* Object__PARAMS__C */
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Object__PARAMS__C, ".const:ti_sysbios_knl_Queue_Object__PARAMS__C");
__FAR__ const ti_sysbios_knl_Queue_Params ti_sysbios_knl_Queue_Object__PARAMS__C = {
    sizeof (ti_sysbios_knl_Queue_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_knl_Queue_Object__PARAMS__C.__iprms, /* instance */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_knl_Queue_Module__ ti_sysbios_knl_Queue_Module__root__V = {
    {&ti_sysbios_knl_Queue_Module__root__V.link,  /* link.next */
    &ti_sysbios_knl_Queue_Module__root__V.link},  /* link.prev */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__diagsEnabled__C, ".const:ti_sysbios_knl_Queue_Module__diagsEnabled__C");
__FAR__ const CT__ti_sysbios_knl_Queue_Module__diagsEnabled ti_sysbios_knl_Queue_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__diagsIncluded__C, ".const:ti_sysbios_knl_Queue_Module__diagsIncluded__C");
__FAR__ const CT__ti_sysbios_knl_Queue_Module__diagsIncluded ti_sysbios_knl_Queue_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__diagsMask__C, ".const:ti_sysbios_knl_Queue_Module__diagsMask__C");
__FAR__ const CT__ti_sysbios_knl_Queue_Module__diagsMask ti_sysbios_knl_Queue_Module__diagsMask__C = ((CT__ti_sysbios_knl_Queue_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__gateObj__C, ".const:ti_sysbios_knl_Queue_Module__gateObj__C");
__FAR__ const CT__ti_sysbios_knl_Queue_Module__gateObj ti_sysbios_knl_Queue_Module__gateObj__C = ((CT__ti_sysbios_knl_Queue_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__gatePrms__C, ".const:ti_sysbios_knl_Queue_Module__gatePrms__C");
__FAR__ const CT__ti_sysbios_knl_Queue_Module__gatePrms ti_sysbios_knl_Queue_Module__gatePrms__C = ((CT__ti_sysbios_knl_Queue_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__id__C, ".const:ti_sysbios_knl_Queue_Module__id__C");
__FAR__ const CT__ti_sysbios_knl_Queue_Module__id ti_sysbios_knl_Queue_Module__id__C = (xdc_Bits16)0x8015;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__loggerDefined__C, ".const:ti_sysbios_knl_Queue_Module__loggerDefined__C");
__FAR__ const CT__ti_sysbios_knl_Queue_Module__loggerDefined ti_sysbios_knl_Queue_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__loggerObj__C, ".const:ti_sysbios_knl_Queue_Module__loggerObj__C");
__FAR__ const CT__ti_sysbios_knl_Queue_Module__loggerObj ti_sysbios_knl_Queue_Module__loggerObj__C = ((CT__ti_sysbios_knl_Queue_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__loggerFxn0__C, ".const:ti_sysbios_knl_Queue_Module__loggerFxn0__C");
__FAR__ const CT__ti_sysbios_knl_Queue_Module__loggerFxn0 ti_sysbios_knl_Queue_Module__loggerFxn0__C = ((CT__ti_sysbios_knl_Queue_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__loggerFxn1__C, ".const:ti_sysbios_knl_Queue_Module__loggerFxn1__C");
__FAR__ const CT__ti_sysbios_knl_Queue_Module__loggerFxn1 ti_sysbios_knl_Queue_Module__loggerFxn1__C = ((CT__ti_sysbios_knl_Queue_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__loggerFxn2__C, ".const:ti_sysbios_knl_Queue_Module__loggerFxn2__C");
__FAR__ const CT__ti_sysbios_knl_Queue_Module__loggerFxn2 ti_sysbios_knl_Queue_Module__loggerFxn2__C = ((CT__ti_sysbios_knl_Queue_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__loggerFxn4__C, ".const:ti_sysbios_knl_Queue_Module__loggerFxn4__C");
__FAR__ const CT__ti_sysbios_knl_Queue_Module__loggerFxn4 ti_sysbios_knl_Queue_Module__loggerFxn4__C = ((CT__ti_sysbios_knl_Queue_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__loggerFxn8__C, ".const:ti_sysbios_knl_Queue_Module__loggerFxn8__C");
__FAR__ const CT__ti_sysbios_knl_Queue_Module__loggerFxn8 ti_sysbios_knl_Queue_Module__loggerFxn8__C = ((CT__ti_sysbios_knl_Queue_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__startupDoneFxn__C, ".const:ti_sysbios_knl_Queue_Module__startupDoneFxn__C");
__FAR__ const CT__ti_sysbios_knl_Queue_Module__startupDoneFxn ti_sysbios_knl_Queue_Module__startupDoneFxn__C = ((CT__ti_sysbios_knl_Queue_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Object__count__C, ".const:ti_sysbios_knl_Queue_Object__count__C");
__FAR__ const CT__ti_sysbios_knl_Queue_Object__count ti_sysbios_knl_Queue_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Object__heap__C, ".const:ti_sysbios_knl_Queue_Object__heap__C");
__FAR__ const CT__ti_sysbios_knl_Queue_Object__heap ti_sysbios_knl_Queue_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Object__sizeof__C, ".const:ti_sysbios_knl_Queue_Object__sizeof__C");
__FAR__ const CT__ti_sysbios_knl_Queue_Object__sizeof ti_sysbios_knl_Queue_Object__sizeof__C = sizeof(ti_sysbios_knl_Queue_Object__);

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Object__table__C, ".const:ti_sysbios_knl_Queue_Object__table__C");
__FAR__ const CT__ti_sysbios_knl_Queue_Object__table ti_sysbios_knl_Queue_Object__table__C = 0;


/*
 * ======== ti.sysbios.knl.Semaphore INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Semaphore_Object__DESC__C;

/* Object__PARAMS__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Object__PARAMS__C, ".const:ti_sysbios_knl_Semaphore_Object__PARAMS__C");
__FAR__ const ti_sysbios_knl_Semaphore_Params ti_sysbios_knl_Semaphore_Object__PARAMS__C = {
    sizeof (ti_sysbios_knl_Semaphore_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_knl_Semaphore_Object__PARAMS__C.__iprms, /* instance */
    0,  /* event */
    (xdc_UInt)0x1,  /* eventId */
    ti_sysbios_knl_Semaphore_Mode_COUNTING,  /* mode */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_knl_Semaphore_Module__ ti_sysbios_knl_Semaphore_Module__root__V = {
    {&ti_sysbios_knl_Semaphore_Module__root__V.link,  /* link.next */
    &ti_sysbios_knl_Semaphore_Module__root__V.link},  /* link.prev */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__diagsEnabled__C, ".const:ti_sysbios_knl_Semaphore_Module__diagsEnabled__C");
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__diagsEnabled ti_sysbios_knl_Semaphore_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__diagsIncluded__C, ".const:ti_sysbios_knl_Semaphore_Module__diagsIncluded__C");
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__diagsIncluded ti_sysbios_knl_Semaphore_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__diagsMask__C, ".const:ti_sysbios_knl_Semaphore_Module__diagsMask__C");
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__diagsMask ti_sysbios_knl_Semaphore_Module__diagsMask__C = ((CT__ti_sysbios_knl_Semaphore_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__gateObj__C, ".const:ti_sysbios_knl_Semaphore_Module__gateObj__C");
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__gateObj ti_sysbios_knl_Semaphore_Module__gateObj__C = ((CT__ti_sysbios_knl_Semaphore_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__gatePrms__C, ".const:ti_sysbios_knl_Semaphore_Module__gatePrms__C");
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__gatePrms ti_sysbios_knl_Semaphore_Module__gatePrms__C = ((CT__ti_sysbios_knl_Semaphore_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__id__C, ".const:ti_sysbios_knl_Semaphore_Module__id__C");
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__id ti_sysbios_knl_Semaphore_Module__id__C = (xdc_Bits16)0x8016;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__loggerDefined__C, ".const:ti_sysbios_knl_Semaphore_Module__loggerDefined__C");
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__loggerDefined ti_sysbios_knl_Semaphore_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__loggerObj__C, ".const:ti_sysbios_knl_Semaphore_Module__loggerObj__C");
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__loggerObj ti_sysbios_knl_Semaphore_Module__loggerObj__C = ((CT__ti_sysbios_knl_Semaphore_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__loggerFxn0__C, ".const:ti_sysbios_knl_Semaphore_Module__loggerFxn0__C");
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__loggerFxn0 ti_sysbios_knl_Semaphore_Module__loggerFxn0__C = ((CT__ti_sysbios_knl_Semaphore_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__loggerFxn1__C, ".const:ti_sysbios_knl_Semaphore_Module__loggerFxn1__C");
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__loggerFxn1 ti_sysbios_knl_Semaphore_Module__loggerFxn1__C = ((CT__ti_sysbios_knl_Semaphore_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__loggerFxn2__C, ".const:ti_sysbios_knl_Semaphore_Module__loggerFxn2__C");
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__loggerFxn2 ti_sysbios_knl_Semaphore_Module__loggerFxn2__C = ((CT__ti_sysbios_knl_Semaphore_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__loggerFxn4__C, ".const:ti_sysbios_knl_Semaphore_Module__loggerFxn4__C");
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__loggerFxn4 ti_sysbios_knl_Semaphore_Module__loggerFxn4__C = ((CT__ti_sysbios_knl_Semaphore_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__loggerFxn8__C, ".const:ti_sysbios_knl_Semaphore_Module__loggerFxn8__C");
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__loggerFxn8 ti_sysbios_knl_Semaphore_Module__loggerFxn8__C = ((CT__ti_sysbios_knl_Semaphore_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__startupDoneFxn__C, ".const:ti_sysbios_knl_Semaphore_Module__startupDoneFxn__C");
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__startupDoneFxn ti_sysbios_knl_Semaphore_Module__startupDoneFxn__C = ((CT__ti_sysbios_knl_Semaphore_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Object__count__C, ".const:ti_sysbios_knl_Semaphore_Object__count__C");
__FAR__ const CT__ti_sysbios_knl_Semaphore_Object__count ti_sysbios_knl_Semaphore_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Object__heap__C, ".const:ti_sysbios_knl_Semaphore_Object__heap__C");
__FAR__ const CT__ti_sysbios_knl_Semaphore_Object__heap ti_sysbios_knl_Semaphore_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Object__sizeof__C, ".const:ti_sysbios_knl_Semaphore_Object__sizeof__C");
__FAR__ const CT__ti_sysbios_knl_Semaphore_Object__sizeof ti_sysbios_knl_Semaphore_Object__sizeof__C = sizeof(ti_sysbios_knl_Semaphore_Object__);

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Object__table__C, ".const:ti_sysbios_knl_Semaphore_Object__table__C");
__FAR__ const CT__ti_sysbios_knl_Semaphore_Object__table ti_sysbios_knl_Semaphore_Object__table__C = 0;

/* LM_post__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_LM_post__C, ".const:ti_sysbios_knl_Semaphore_LM_post__C");
__FAR__ const CT__ti_sysbios_knl_Semaphore_LM_post ti_sysbios_knl_Semaphore_LM_post__C = (((xdc_runtime_Log_Event)5945) << 16 | 768);

/* LM_pend__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_LM_pend__C, ".const:ti_sysbios_knl_Semaphore_LM_pend__C");
__FAR__ const CT__ti_sysbios_knl_Semaphore_LM_pend ti_sysbios_knl_Semaphore_LM_pend__C = (((xdc_runtime_Log_Event)5975) << 16 | 768);

/* A_noEvents__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_A_noEvents__C, ".const:ti_sysbios_knl_Semaphore_A_noEvents__C");
__FAR__ const CT__ti_sysbios_knl_Semaphore_A_noEvents ti_sysbios_knl_Semaphore_A_noEvents__C = (((xdc_runtime_Assert_Id)1044) << 16 | 16);

/* A_invTimeout__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_A_invTimeout__C, ".const:ti_sysbios_knl_Semaphore_A_invTimeout__C");
__FAR__ const CT__ti_sysbios_knl_Semaphore_A_invTimeout ti_sysbios_knl_Semaphore_A_invTimeout__C = (((xdc_runtime_Assert_Id)1099) << 16 | 16);

/* A_badContext__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_A_badContext__C, ".const:ti_sysbios_knl_Semaphore_A_badContext__C");
__FAR__ const CT__ti_sysbios_knl_Semaphore_A_badContext ti_sysbios_knl_Semaphore_A_badContext__C = (((xdc_runtime_Assert_Id)833) << 16 | 16);

/* A_overflow__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_A_overflow__C, ".const:ti_sysbios_knl_Semaphore_A_overflow__C");
__FAR__ const CT__ti_sysbios_knl_Semaphore_A_overflow ti_sysbios_knl_Semaphore_A_overflow__C = (((xdc_runtime_Assert_Id)1164) << 16 | 16);

/* A_pendTaskDisabled__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_A_pendTaskDisabled__C, ".const:ti_sysbios_knl_Semaphore_A_pendTaskDisabled__C");
__FAR__ const CT__ti_sysbios_knl_Semaphore_A_pendTaskDisabled ti_sysbios_knl_Semaphore_A_pendTaskDisabled__C = (((xdc_runtime_Assert_Id)1218) << 16 | 16);

/* supportsEvents__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_supportsEvents__C, ".const:ti_sysbios_knl_Semaphore_supportsEvents__C");
__FAR__ const CT__ti_sysbios_knl_Semaphore_supportsEvents ti_sysbios_knl_Semaphore_supportsEvents__C = 0;

/* supportsPriority__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_supportsPriority__C, ".const:ti_sysbios_knl_Semaphore_supportsPriority__C");
__FAR__ const CT__ti_sysbios_knl_Semaphore_supportsPriority ti_sysbios_knl_Semaphore_supportsPriority__C = 1;

/* eventPost__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_eventPost__C, ".const:ti_sysbios_knl_Semaphore_eventPost__C");
__FAR__ const CT__ti_sysbios_knl_Semaphore_eventPost ti_sysbios_knl_Semaphore_eventPost__C = ((CT__ti_sysbios_knl_Semaphore_eventPost)0);

/* eventSync__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_eventSync__C, ".const:ti_sysbios_knl_Semaphore_eventSync__C");
__FAR__ const CT__ti_sysbios_knl_Semaphore_eventSync ti_sysbios_knl_Semaphore_eventSync__C = ((CT__ti_sysbios_knl_Semaphore_eventSync)0);


/*
 * ======== ti.sysbios.knl.Swi INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Swi_Object__DESC__C;

/* Object__PARAMS__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Object__PARAMS__C, ".const:ti_sysbios_knl_Swi_Object__PARAMS__C");
__FAR__ const ti_sysbios_knl_Swi_Params ti_sysbios_knl_Swi_Object__PARAMS__C = {
    sizeof (ti_sysbios_knl_Swi_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_knl_Swi_Object__PARAMS__C.__iprms, /* instance */
    ((xdc_UArg)(0x0)),  /* arg0 */
    ((xdc_UArg)(0x0)),  /* arg1 */
    (xdc_UInt)(-0x0 - 1),  /* priority */
    (xdc_UInt)0x0,  /* trigger */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_knl_Swi_Module__ ti_sysbios_knl_Swi_Module__root__V = {
    {&ti_sysbios_knl_Swi_Module__root__V.link,  /* link.next */
    &ti_sysbios_knl_Swi_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_knl_Swi_Object__ ti_sysbios_knl_Swi_Object__table__V[1] = {
    {/* instance#0 */
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Object__table__V[0].qElem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Object__table__V[0].qElem)),  /* prev */
        },  /* qElem */
        ((xdc_Void(*)(xdc_UArg,xdc_UArg))((xdc_Fxn)ti_sysbios_knl_Clock_workFunc__E)),  /* fxn */
        ((xdc_UArg)(0x0)),  /* arg0 */
        ((xdc_UArg)(0x0)),  /* arg1 */
        (xdc_UInt)0xf,  /* priority */
        (xdc_UInt)0x8000,  /* mask */
        0,  /* posted */
        (xdc_UInt)0x0,  /* initTrigger */
        (xdc_UInt)0x0,  /* trigger */
        (ti_sysbios_knl_Queue_Handle)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[15],  /* readyQ */
        ((void*)0),  /* hookEnv */
    },
};

/* --> ti_sysbios_knl_Swi_Module_State_0_readyQ__A */
__T1_ti_sysbios_knl_Swi_Module_State__readyQ ti_sysbios_knl_Swi_Module_State_0_readyQ__A[16] = {
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[0].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[0].elem)),  /* prev */
        },  /* elem */
    },  /* [0] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[1].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[1].elem)),  /* prev */
        },  /* elem */
    },  /* [1] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[2].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[2].elem)),  /* prev */
        },  /* elem */
    },  /* [2] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[3].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[3].elem)),  /* prev */
        },  /* elem */
    },  /* [3] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[4].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[4].elem)),  /* prev */
        },  /* elem */
    },  /* [4] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[5].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[5].elem)),  /* prev */
        },  /* elem */
    },  /* [5] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[6].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[6].elem)),  /* prev */
        },  /* elem */
    },  /* [6] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[7].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[7].elem)),  /* prev */
        },  /* elem */
    },  /* [7] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[8].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[8].elem)),  /* prev */
        },  /* elem */
    },  /* [8] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[9].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[9].elem)),  /* prev */
        },  /* elem */
    },  /* [9] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[10].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[10].elem)),  /* prev */
        },  /* elem */
    },  /* [10] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[11].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[11].elem)),  /* prev */
        },  /* elem */
    },  /* [11] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[12].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[12].elem)),  /* prev */
        },  /* elem */
    },  /* [12] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[13].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[13].elem)),  /* prev */
        },  /* elem */
    },  /* [13] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[14].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[14].elem)),  /* prev */
        },  /* elem */
    },  /* [14] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[15].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[15].elem)),  /* prev */
        },  /* elem */
    },  /* [15] */
};

/* Module__state__V */
#if defined (__ICCARM__)
#pragma location = ".data_ti_sysbios_knl_Swi_Module__state__V"
#endif
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
#ifndef __TI_COMPILER_VERSION__
ti_sysbios_knl_Swi_Module_State__ ti_sysbios_knl_Swi_Module__state__V __attribute__ ((section(".data_ti_sysbios_knl_Swi_Module__state__V")));
#endif
#endif
ti_sysbios_knl_Swi_Module_State__ ti_sysbios_knl_Swi_Module__state__V = {
    1,  /* locked */
    (xdc_UInt)0x0,  /* curSet */
    (xdc_UInt)0x0,  /* curTrigger */
    0,  /* curSwi */
    0,  /* curQ */
    ((void*)ti_sysbios_knl_Swi_Module_State_0_readyQ__A),  /* readyQ */
    ((void*)0),  /* constructedSwis */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__diagsEnabled__C, ".const:ti_sysbios_knl_Swi_Module__diagsEnabled__C");
__FAR__ const CT__ti_sysbios_knl_Swi_Module__diagsEnabled ti_sysbios_knl_Swi_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__diagsIncluded__C, ".const:ti_sysbios_knl_Swi_Module__diagsIncluded__C");
__FAR__ const CT__ti_sysbios_knl_Swi_Module__diagsIncluded ti_sysbios_knl_Swi_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__diagsMask__C, ".const:ti_sysbios_knl_Swi_Module__diagsMask__C");
__FAR__ const CT__ti_sysbios_knl_Swi_Module__diagsMask ti_sysbios_knl_Swi_Module__diagsMask__C = ((CT__ti_sysbios_knl_Swi_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__gateObj__C, ".const:ti_sysbios_knl_Swi_Module__gateObj__C");
__FAR__ const CT__ti_sysbios_knl_Swi_Module__gateObj ti_sysbios_knl_Swi_Module__gateObj__C = ((CT__ti_sysbios_knl_Swi_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__gatePrms__C, ".const:ti_sysbios_knl_Swi_Module__gatePrms__C");
__FAR__ const CT__ti_sysbios_knl_Swi_Module__gatePrms ti_sysbios_knl_Swi_Module__gatePrms__C = ((CT__ti_sysbios_knl_Swi_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__id__C, ".const:ti_sysbios_knl_Swi_Module__id__C");
__FAR__ const CT__ti_sysbios_knl_Swi_Module__id ti_sysbios_knl_Swi_Module__id__C = (xdc_Bits16)0x8017;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__loggerDefined__C, ".const:ti_sysbios_knl_Swi_Module__loggerDefined__C");
__FAR__ const CT__ti_sysbios_knl_Swi_Module__loggerDefined ti_sysbios_knl_Swi_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__loggerObj__C, ".const:ti_sysbios_knl_Swi_Module__loggerObj__C");
__FAR__ const CT__ti_sysbios_knl_Swi_Module__loggerObj ti_sysbios_knl_Swi_Module__loggerObj__C = ((CT__ti_sysbios_knl_Swi_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__loggerFxn0__C, ".const:ti_sysbios_knl_Swi_Module__loggerFxn0__C");
__FAR__ const CT__ti_sysbios_knl_Swi_Module__loggerFxn0 ti_sysbios_knl_Swi_Module__loggerFxn0__C = ((CT__ti_sysbios_knl_Swi_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__loggerFxn1__C, ".const:ti_sysbios_knl_Swi_Module__loggerFxn1__C");
__FAR__ const CT__ti_sysbios_knl_Swi_Module__loggerFxn1 ti_sysbios_knl_Swi_Module__loggerFxn1__C = ((CT__ti_sysbios_knl_Swi_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__loggerFxn2__C, ".const:ti_sysbios_knl_Swi_Module__loggerFxn2__C");
__FAR__ const CT__ti_sysbios_knl_Swi_Module__loggerFxn2 ti_sysbios_knl_Swi_Module__loggerFxn2__C = ((CT__ti_sysbios_knl_Swi_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__loggerFxn4__C, ".const:ti_sysbios_knl_Swi_Module__loggerFxn4__C");
__FAR__ const CT__ti_sysbios_knl_Swi_Module__loggerFxn4 ti_sysbios_knl_Swi_Module__loggerFxn4__C = ((CT__ti_sysbios_knl_Swi_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__loggerFxn8__C, ".const:ti_sysbios_knl_Swi_Module__loggerFxn8__C");
__FAR__ const CT__ti_sysbios_knl_Swi_Module__loggerFxn8 ti_sysbios_knl_Swi_Module__loggerFxn8__C = ((CT__ti_sysbios_knl_Swi_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__startupDoneFxn__C, ".const:ti_sysbios_knl_Swi_Module__startupDoneFxn__C");
__FAR__ const CT__ti_sysbios_knl_Swi_Module__startupDoneFxn ti_sysbios_knl_Swi_Module__startupDoneFxn__C = ((CT__ti_sysbios_knl_Swi_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Object__count__C, ".const:ti_sysbios_knl_Swi_Object__count__C");
__FAR__ const CT__ti_sysbios_knl_Swi_Object__count ti_sysbios_knl_Swi_Object__count__C = 1;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Object__heap__C, ".const:ti_sysbios_knl_Swi_Object__heap__C");
__FAR__ const CT__ti_sysbios_knl_Swi_Object__heap ti_sysbios_knl_Swi_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Object__sizeof__C, ".const:ti_sysbios_knl_Swi_Object__sizeof__C");
__FAR__ const CT__ti_sysbios_knl_Swi_Object__sizeof ti_sysbios_knl_Swi_Object__sizeof__C = sizeof(ti_sysbios_knl_Swi_Object__);

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Object__table__C, ".const:ti_sysbios_knl_Swi_Object__table__C");
__FAR__ const CT__ti_sysbios_knl_Swi_Object__table ti_sysbios_knl_Swi_Object__table__C = ti_sysbios_knl_Swi_Object__table__V;

/* LM_begin__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_LM_begin__C, ".const:ti_sysbios_knl_Swi_LM_begin__C");
__FAR__ const CT__ti_sysbios_knl_Swi_LM_begin ti_sysbios_knl_Swi_LM_begin__C = (((xdc_runtime_Log_Event)6018) << 16 | 768);

/* LD_end__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_LD_end__C, ".const:ti_sysbios_knl_Swi_LD_end__C");
__FAR__ const CT__ti_sysbios_knl_Swi_LD_end ti_sysbios_knl_Swi_LD_end__C = (((xdc_runtime_Log_Event)6065) << 16 | 512);

/* LM_post__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_LM_post__C, ".const:ti_sysbios_knl_Swi_LM_post__C");
__FAR__ const CT__ti_sysbios_knl_Swi_LM_post ti_sysbios_knl_Swi_LM_post__C = (((xdc_runtime_Log_Event)6083) << 16 | 768);

/* A_swiDisabled__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_A_swiDisabled__C, ".const:ti_sysbios_knl_Swi_A_swiDisabled__C");
__FAR__ const CT__ti_sysbios_knl_Swi_A_swiDisabled ti_sysbios_knl_Swi_A_swiDisabled__C = (((xdc_runtime_Assert_Id)1312) << 16 | 16);

/* A_badPriority__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_A_badPriority__C, ".const:ti_sysbios_knl_Swi_A_badPriority__C");
__FAR__ const CT__ti_sysbios_knl_Swi_A_badPriority ti_sysbios_knl_Swi_A_badPriority__C = (((xdc_runtime_Assert_Id)1369) << 16 | 16);

/* numPriorities__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_numPriorities__C, ".const:ti_sysbios_knl_Swi_numPriorities__C");
__FAR__ const CT__ti_sysbios_knl_Swi_numPriorities ti_sysbios_knl_Swi_numPriorities__C = (xdc_UInt)0x10;

/* hooks__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_hooks__C, ".const:ti_sysbios_knl_Swi_hooks__C");
__FAR__ const CT__ti_sysbios_knl_Swi_hooks ti_sysbios_knl_Swi_hooks__C = {0, 0};

/* taskDisable__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_taskDisable__C, ".const:ti_sysbios_knl_Swi_taskDisable__C");
__FAR__ const CT__ti_sysbios_knl_Swi_taskDisable ti_sysbios_knl_Swi_taskDisable__C = ((CT__ti_sysbios_knl_Swi_taskDisable)((xdc_Fxn)ti_sysbios_knl_Task_disable__E));

/* taskRestore__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_taskRestore__C, ".const:ti_sysbios_knl_Swi_taskRestore__C");
__FAR__ const CT__ti_sysbios_knl_Swi_taskRestore ti_sysbios_knl_Swi_taskRestore__C = ((CT__ti_sysbios_knl_Swi_taskRestore)((xdc_Fxn)ti_sysbios_knl_Task_restore__E));

/* numConstructedSwis__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_numConstructedSwis__C, ".const:ti_sysbios_knl_Swi_numConstructedSwis__C");
__FAR__ const CT__ti_sysbios_knl_Swi_numConstructedSwis ti_sysbios_knl_Swi_numConstructedSwis__C = (xdc_UInt)0x0;


/*
 * ======== ti.sysbios.knl.Task INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Task_Object__DESC__C;

/* Object__PARAMS__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_Object__PARAMS__C, ".const:ti_sysbios_knl_Task_Object__PARAMS__C");
__FAR__ const ti_sysbios_knl_Task_Params ti_sysbios_knl_Task_Object__PARAMS__C = {
    sizeof (ti_sysbios_knl_Task_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_knl_Task_Object__PARAMS__C.__iprms, /* instance */
    ((xdc_UArg)(0x0)),  /* arg0 */
    ((xdc_UArg)(0x0)),  /* arg1 */
    (xdc_Int)0x1,  /* priority */
    ((xdc_Ptr)0),  /* stack */
    (xdc_SizeT)0x0,  /* stackSize */
    0,  /* stackHeap */
    ((xdc_Ptr)0),  /* env */
    1,  /* vitalTaskFlag */
    (xdc_UInt)0x0,  /* affinity */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* --> ti_sysbios_knl_Task_Instance_State_0_stack__A */
__T1_ti_sysbios_knl_Task_Instance_State__stack ti_sysbios_knl_Task_Instance_State_0_stack__A[2048];

/* Module__root__V */
ti_sysbios_knl_Task_Module__ ti_sysbios_knl_Task_Module__root__V = {
    {&ti_sysbios_knl_Task_Module__root__V.link,  /* link.next */
    &ti_sysbios_knl_Task_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_knl_Task_Object__ ti_sysbios_knl_Task_Object__table__V[1] = {
    {/* instance#0 */
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Object__table__V[0].qElem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Object__table__V[0].qElem)),  /* prev */
        },  /* qElem */
        (xdc_Int)0x0,  /* priority */
        (xdc_UInt)0x1,  /* mask */
        ((xdc_Ptr)0),  /* context */
        ti_sysbios_knl_Task_Mode_INACTIVE,  /* mode */
        ((ti_sysbios_knl_Task_PendElem*)0),  /* pendElem */
        (xdc_SizeT)0x800,  /* stackSize */
        ((void*)ti_sysbios_knl_Task_Instance_State_0_stack__A),  /* stack */
        0,  /* stackHeap */
        ((xdc_Void(*)(xdc_UArg,xdc_UArg))((xdc_Fxn)ti_sysbios_knl_Idle_loop__E)),  /* fxn */
        ((xdc_UArg)(0x0)),  /* arg0 */
        ((xdc_UArg)(0x0)),  /* arg1 */
        ((xdc_Ptr)0),  /* env */
        ((void*)0),  /* hookEnv */
        1,  /* vitalTaskFlag */
        0,  /* readyQ */
        (xdc_UInt)0x0,  /* curCoreId */
        (xdc_UInt)0x0,  /* affinity */
    },
};

/* --> ti_sysbios_knl_Task_Module_State_0_readyQ__A */
__T1_ti_sysbios_knl_Task_Module_State__readyQ ti_sysbios_knl_Task_Module_State_0_readyQ__A[16] = {
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[0].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[0].elem)),  /* prev */
        },  /* elem */
    },  /* [0] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[1].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[1].elem)),  /* prev */
        },  /* elem */
    },  /* [1] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[2].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[2].elem)),  /* prev */
        },  /* elem */
    },  /* [2] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[3].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[3].elem)),  /* prev */
        },  /* elem */
    },  /* [3] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[4].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[4].elem)),  /* prev */
        },  /* elem */
    },  /* [4] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[5].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[5].elem)),  /* prev */
        },  /* elem */
    },  /* [5] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[6].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[6].elem)),  /* prev */
        },  /* elem */
    },  /* [6] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[7].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[7].elem)),  /* prev */
        },  /* elem */
    },  /* [7] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[8].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[8].elem)),  /* prev */
        },  /* elem */
    },  /* [8] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[9].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[9].elem)),  /* prev */
        },  /* elem */
    },  /* [9] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[10].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[10].elem)),  /* prev */
        },  /* elem */
    },  /* [10] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[11].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[11].elem)),  /* prev */
        },  /* elem */
    },  /* [11] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[12].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[12].elem)),  /* prev */
        },  /* elem */
    },  /* [12] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[13].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[13].elem)),  /* prev */
        },  /* elem */
    },  /* [13] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[14].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[14].elem)),  /* prev */
        },  /* elem */
    },  /* [14] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[15].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[15].elem)),  /* prev */
        },  /* elem */
    },  /* [15] */
};

/* --> ti_sysbios_knl_Task_Module_State_0_idleTask__A */
__T1_ti_sysbios_knl_Task_Module_State__idleTask ti_sysbios_knl_Task_Module_State_0_idleTask__A[1] = {
    (ti_sysbios_knl_Task_Handle)&ti_sysbios_knl_Task_Object__table__V[0],  /* [0] */
};

/* Module__state__V */
#if defined (__ICCARM__)
#pragma location = ".data_ti_sysbios_knl_Task_Module__state__V"
#endif
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
#ifndef __TI_COMPILER_VERSION__
ti_sysbios_knl_Task_Module_State__ ti_sysbios_knl_Task_Module__state__V __attribute__ ((section(".data_ti_sysbios_knl_Task_Module__state__V")));
#endif
#endif
ti_sysbios_knl_Task_Module_State__ ti_sysbios_knl_Task_Module__state__V = {
    1,  /* locked */
    (xdc_UInt)0x0,  /* curSet */
    0,  /* workFlag */
    (xdc_UInt)0x1,  /* vitalTasks */
    0,  /* curTask */
    0,  /* curQ */
    ((void*)ti_sysbios_knl_Task_Module_State_0_readyQ__A),  /* readyQ */
    ((void*)0),  /* smpCurSet */
    ((void*)0),  /* smpCurMask */
    ((void*)0),  /* smpCurTask */
    ((void*)0),  /* smpReadyQ */
    ((void*)ti_sysbios_knl_Task_Module_State_0_idleTask__A),  /* idleTask */
    ((void*)0),  /* constructedTasks */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module__state__V.Object_field_inactiveQ.elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module__state__V.Object_field_inactiveQ.elem)),  /* prev */
        },  /* elem */
    },  /* Object_field_inactiveQ */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module__state__V.Object_field_terminatedQ.elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module__state__V.Object_field_terminatedQ.elem)),  /* prev */
        },  /* elem */
    },  /* Object_field_terminatedQ */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__diagsEnabled__C, ".const:ti_sysbios_knl_Task_Module__diagsEnabled__C");
__FAR__ const CT__ti_sysbios_knl_Task_Module__diagsEnabled ti_sysbios_knl_Task_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__diagsIncluded__C, ".const:ti_sysbios_knl_Task_Module__diagsIncluded__C");
__FAR__ const CT__ti_sysbios_knl_Task_Module__diagsIncluded ti_sysbios_knl_Task_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__diagsMask__C, ".const:ti_sysbios_knl_Task_Module__diagsMask__C");
__FAR__ const CT__ti_sysbios_knl_Task_Module__diagsMask ti_sysbios_knl_Task_Module__diagsMask__C = ((CT__ti_sysbios_knl_Task_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__gateObj__C, ".const:ti_sysbios_knl_Task_Module__gateObj__C");
__FAR__ const CT__ti_sysbios_knl_Task_Module__gateObj ti_sysbios_knl_Task_Module__gateObj__C = ((CT__ti_sysbios_knl_Task_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__gatePrms__C, ".const:ti_sysbios_knl_Task_Module__gatePrms__C");
__FAR__ const CT__ti_sysbios_knl_Task_Module__gatePrms ti_sysbios_knl_Task_Module__gatePrms__C = ((CT__ti_sysbios_knl_Task_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__id__C, ".const:ti_sysbios_knl_Task_Module__id__C");
__FAR__ const CT__ti_sysbios_knl_Task_Module__id ti_sysbios_knl_Task_Module__id__C = (xdc_Bits16)0x8018;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__loggerDefined__C, ".const:ti_sysbios_knl_Task_Module__loggerDefined__C");
__FAR__ const CT__ti_sysbios_knl_Task_Module__loggerDefined ti_sysbios_knl_Task_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__loggerObj__C, ".const:ti_sysbios_knl_Task_Module__loggerObj__C");
__FAR__ const CT__ti_sysbios_knl_Task_Module__loggerObj ti_sysbios_knl_Task_Module__loggerObj__C = ((CT__ti_sysbios_knl_Task_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__loggerFxn0__C, ".const:ti_sysbios_knl_Task_Module__loggerFxn0__C");
__FAR__ const CT__ti_sysbios_knl_Task_Module__loggerFxn0 ti_sysbios_knl_Task_Module__loggerFxn0__C = ((CT__ti_sysbios_knl_Task_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__loggerFxn1__C, ".const:ti_sysbios_knl_Task_Module__loggerFxn1__C");
__FAR__ const CT__ti_sysbios_knl_Task_Module__loggerFxn1 ti_sysbios_knl_Task_Module__loggerFxn1__C = ((CT__ti_sysbios_knl_Task_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__loggerFxn2__C, ".const:ti_sysbios_knl_Task_Module__loggerFxn2__C");
__FAR__ const CT__ti_sysbios_knl_Task_Module__loggerFxn2 ti_sysbios_knl_Task_Module__loggerFxn2__C = ((CT__ti_sysbios_knl_Task_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__loggerFxn4__C, ".const:ti_sysbios_knl_Task_Module__loggerFxn4__C");
__FAR__ const CT__ti_sysbios_knl_Task_Module__loggerFxn4 ti_sysbios_knl_Task_Module__loggerFxn4__C = ((CT__ti_sysbios_knl_Task_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__loggerFxn8__C, ".const:ti_sysbios_knl_Task_Module__loggerFxn8__C");
__FAR__ const CT__ti_sysbios_knl_Task_Module__loggerFxn8 ti_sysbios_knl_Task_Module__loggerFxn8__C = ((CT__ti_sysbios_knl_Task_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__startupDoneFxn__C, ".const:ti_sysbios_knl_Task_Module__startupDoneFxn__C");
__FAR__ const CT__ti_sysbios_knl_Task_Module__startupDoneFxn ti_sysbios_knl_Task_Module__startupDoneFxn__C = ((CT__ti_sysbios_knl_Task_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_Object__count__C, ".const:ti_sysbios_knl_Task_Object__count__C");
__FAR__ const CT__ti_sysbios_knl_Task_Object__count ti_sysbios_knl_Task_Object__count__C = 1;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_Object__heap__C, ".const:ti_sysbios_knl_Task_Object__heap__C");
__FAR__ const CT__ti_sysbios_knl_Task_Object__heap ti_sysbios_knl_Task_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_Object__sizeof__C, ".const:ti_sysbios_knl_Task_Object__sizeof__C");
__FAR__ const CT__ti_sysbios_knl_Task_Object__sizeof ti_sysbios_knl_Task_Object__sizeof__C = sizeof(ti_sysbios_knl_Task_Object__);

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_Object__table__C, ".const:ti_sysbios_knl_Task_Object__table__C");
__FAR__ const CT__ti_sysbios_knl_Task_Object__table ti_sysbios_knl_Task_Object__table__C = ti_sysbios_knl_Task_Object__table__V;

/* LM_switch__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_LM_switch__C, ".const:ti_sysbios_knl_Task_LM_switch__C");
__FAR__ const CT__ti_sysbios_knl_Task_LM_switch ti_sysbios_knl_Task_LM_switch__C = (((xdc_runtime_Log_Event)6123) << 16 | 768);

/* LM_sleep__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_LM_sleep__C, ".const:ti_sysbios_knl_Task_LM_sleep__C");
__FAR__ const CT__ti_sysbios_knl_Task_LM_sleep ti_sysbios_knl_Task_LM_sleep__C = (((xdc_runtime_Log_Event)6191) << 16 | 768);

/* LD_ready__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_LD_ready__C, ".const:ti_sysbios_knl_Task_LD_ready__C");
__FAR__ const CT__ti_sysbios_knl_Task_LD_ready ti_sysbios_knl_Task_LD_ready__C = (((xdc_runtime_Log_Event)6236) << 16 | 512);

/* LD_block__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_LD_block__C, ".const:ti_sysbios_knl_Task_LD_block__C");
__FAR__ const CT__ti_sysbios_knl_Task_LD_block ti_sysbios_knl_Task_LD_block__C = (((xdc_runtime_Log_Event)6277) << 16 | 512);

/* LM_yield__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_LM_yield__C, ".const:ti_sysbios_knl_Task_LM_yield__C");
__FAR__ const CT__ti_sysbios_knl_Task_LM_yield ti_sysbios_knl_Task_LM_yield__C = (((xdc_runtime_Log_Event)6309) << 16 | 768);

/* LM_setPri__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_LM_setPri__C, ".const:ti_sysbios_knl_Task_LM_setPri__C");
__FAR__ const CT__ti_sysbios_knl_Task_LM_setPri ti_sysbios_knl_Task_LM_setPri__C = (((xdc_runtime_Log_Event)6357) << 16 | 768);

/* LD_exit__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_LD_exit__C, ".const:ti_sysbios_knl_Task_LD_exit__C");
__FAR__ const CT__ti_sysbios_knl_Task_LD_exit ti_sysbios_knl_Task_LD_exit__C = (((xdc_runtime_Log_Event)6413) << 16 | 512);

/* LM_setAffinity__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_LM_setAffinity__C, ".const:ti_sysbios_knl_Task_LM_setAffinity__C");
__FAR__ const CT__ti_sysbios_knl_Task_LM_setAffinity ti_sysbios_knl_Task_LM_setAffinity__C = (((xdc_runtime_Log_Event)6444) << 16 | 768);

/* LM_schedule__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_LM_schedule__C, ".const:ti_sysbios_knl_Task_LM_schedule__C");
__FAR__ const CT__ti_sysbios_knl_Task_LM_schedule ti_sysbios_knl_Task_LM_schedule__C = (((xdc_runtime_Log_Event)6527) << 16 | 1024);

/* LM_noWork__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_LM_noWork__C, ".const:ti_sysbios_knl_Task_LM_noWork__C");
__FAR__ const CT__ti_sysbios_knl_Task_LM_noWork ti_sysbios_knl_Task_LM_noWork__C = (((xdc_runtime_Log_Event)6613) << 16 | 1024);

/* E_stackOverflow__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_E_stackOverflow__C, ".const:ti_sysbios_knl_Task_E_stackOverflow__C");
__FAR__ const CT__ti_sysbios_knl_Task_E_stackOverflow ti_sysbios_knl_Task_E_stackOverflow__C = (((xdc_runtime_Error_Id)4522) << 16 | 0);

/* E_spOutOfBounds__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_E_spOutOfBounds__C, ".const:ti_sysbios_knl_Task_E_spOutOfBounds__C");
__FAR__ const CT__ti_sysbios_knl_Task_E_spOutOfBounds ti_sysbios_knl_Task_E_spOutOfBounds__C = (((xdc_runtime_Error_Id)4565) << 16 | 0);

/* E_deleteNotAllowed__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_E_deleteNotAllowed__C, ".const:ti_sysbios_knl_Task_E_deleteNotAllowed__C");
__FAR__ const CT__ti_sysbios_knl_Task_E_deleteNotAllowed ti_sysbios_knl_Task_E_deleteNotAllowed__C = (((xdc_runtime_Error_Id)4616) << 16 | 0);

/* E_moduleStateCheckFailed__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_E_moduleStateCheckFailed__C, ".const:ti_sysbios_knl_Task_E_moduleStateCheckFailed__C");
__FAR__ const CT__ti_sysbios_knl_Task_E_moduleStateCheckFailed ti_sysbios_knl_Task_E_moduleStateCheckFailed__C = (((xdc_runtime_Error_Id)4647) << 16 | 0);

/* E_objectCheckFailed__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_E_objectCheckFailed__C, ".const:ti_sysbios_knl_Task_E_objectCheckFailed__C");
__FAR__ const CT__ti_sysbios_knl_Task_E_objectCheckFailed ti_sysbios_knl_Task_E_objectCheckFailed__C = (((xdc_runtime_Error_Id)4720) << 16 | 0);

/* A_badThreadType__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_badThreadType__C, ".const:ti_sysbios_knl_Task_A_badThreadType__C");
__FAR__ const CT__ti_sysbios_knl_Task_A_badThreadType ti_sysbios_knl_Task_A_badThreadType__C = (((xdc_runtime_Assert_Id)1418) << 16 | 16);

/* A_badTaskState__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_badTaskState__C, ".const:ti_sysbios_knl_Task_A_badTaskState__C");
__FAR__ const CT__ti_sysbios_knl_Task_A_badTaskState ti_sysbios_knl_Task_A_badTaskState__C = (((xdc_runtime_Assert_Id)1487) << 16 | 16);

/* A_noPendElem__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_noPendElem__C, ".const:ti_sysbios_knl_Task_A_noPendElem__C");
__FAR__ const CT__ti_sysbios_knl_Task_A_noPendElem ti_sysbios_knl_Task_A_noPendElem__C = (((xdc_runtime_Assert_Id)1541) << 16 | 16);

/* A_taskDisabled__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_taskDisabled__C, ".const:ti_sysbios_knl_Task_A_taskDisabled__C");
__FAR__ const CT__ti_sysbios_knl_Task_A_taskDisabled ti_sysbios_knl_Task_A_taskDisabled__C = (((xdc_runtime_Assert_Id)1595) << 16 | 16);

/* A_badPriority__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_badPriority__C, ".const:ti_sysbios_knl_Task_A_badPriority__C");
__FAR__ const CT__ti_sysbios_knl_Task_A_badPriority ti_sysbios_knl_Task_A_badPriority__C = (((xdc_runtime_Assert_Id)1658) << 16 | 16);

/* A_badTimeout__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_badTimeout__C, ".const:ti_sysbios_knl_Task_A_badTimeout__C");
__FAR__ const CT__ti_sysbios_knl_Task_A_badTimeout ti_sysbios_knl_Task_A_badTimeout__C = (((xdc_runtime_Assert_Id)1708) << 16 | 16);

/* A_badAffinity__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_badAffinity__C, ".const:ti_sysbios_knl_Task_A_badAffinity__C");
__FAR__ const CT__ti_sysbios_knl_Task_A_badAffinity ti_sysbios_knl_Task_A_badAffinity__C = (((xdc_runtime_Assert_Id)1743) << 16 | 16);

/* A_sleepTaskDisabled__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_sleepTaskDisabled__C, ".const:ti_sysbios_knl_Task_A_sleepTaskDisabled__C");
__FAR__ const CT__ti_sysbios_knl_Task_A_sleepTaskDisabled ti_sysbios_knl_Task_A_sleepTaskDisabled__C = (((xdc_runtime_Assert_Id)1776) << 16 | 16);

/* A_invalidCoreId__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_invalidCoreId__C, ".const:ti_sysbios_knl_Task_A_invalidCoreId__C");
__FAR__ const CT__ti_sysbios_knl_Task_A_invalidCoreId ti_sysbios_knl_Task_A_invalidCoreId__C = (((xdc_runtime_Assert_Id)1860) << 16 | 16);

/* numPriorities__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_numPriorities__C, ".const:ti_sysbios_knl_Task_numPriorities__C");
__FAR__ const CT__ti_sysbios_knl_Task_numPriorities ti_sysbios_knl_Task_numPriorities__C = (xdc_UInt)0x10;

/* defaultStackSize__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_defaultStackSize__C, ".const:ti_sysbios_knl_Task_defaultStackSize__C");
__FAR__ const CT__ti_sysbios_knl_Task_defaultStackSize ti_sysbios_knl_Task_defaultStackSize__C = (xdc_SizeT)0x800;

/* defaultStackHeap__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_defaultStackHeap__C, ".const:ti_sysbios_knl_Task_defaultStackHeap__C");
__FAR__ const CT__ti_sysbios_knl_Task_defaultStackHeap ti_sysbios_knl_Task_defaultStackHeap__C = 0;

/* allBlockedFunc__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_allBlockedFunc__C, ".const:ti_sysbios_knl_Task_allBlockedFunc__C");
__FAR__ const CT__ti_sysbios_knl_Task_allBlockedFunc ti_sysbios_knl_Task_allBlockedFunc__C = ((CT__ti_sysbios_knl_Task_allBlockedFunc)0);

/* initStackFlag__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_initStackFlag__C, ".const:ti_sysbios_knl_Task_initStackFlag__C");
__FAR__ const CT__ti_sysbios_knl_Task_initStackFlag ti_sysbios_knl_Task_initStackFlag__C = 0;

/* checkStackFlag__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_checkStackFlag__C, ".const:ti_sysbios_knl_Task_checkStackFlag__C");
__FAR__ const CT__ti_sysbios_knl_Task_checkStackFlag ti_sysbios_knl_Task_checkStackFlag__C = 0;

/* deleteTerminatedTasks__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_deleteTerminatedTasks__C, ".const:ti_sysbios_knl_Task_deleteTerminatedTasks__C");
__FAR__ const CT__ti_sysbios_knl_Task_deleteTerminatedTasks ti_sysbios_knl_Task_deleteTerminatedTasks__C = 0;

/* hooks__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_hooks__C, ".const:ti_sysbios_knl_Task_hooks__C");
__FAR__ const CT__ti_sysbios_knl_Task_hooks ti_sysbios_knl_Task_hooks__C = {0, 0};

/* moduleStateCheckFxn__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_moduleStateCheckFxn__C, ".const:ti_sysbios_knl_Task_moduleStateCheckFxn__C");
__FAR__ const CT__ti_sysbios_knl_Task_moduleStateCheckFxn ti_sysbios_knl_Task_moduleStateCheckFxn__C = ((CT__ti_sysbios_knl_Task_moduleStateCheckFxn)((xdc_Fxn)ti_sysbios_knl_Task_moduleStateCheck__I));

/* moduleStateCheckValueFxn__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_moduleStateCheckValueFxn__C, ".const:ti_sysbios_knl_Task_moduleStateCheckValueFxn__C");
__FAR__ const CT__ti_sysbios_knl_Task_moduleStateCheckValueFxn ti_sysbios_knl_Task_moduleStateCheckValueFxn__C = ((CT__ti_sysbios_knl_Task_moduleStateCheckValueFxn)((xdc_Fxn)ti_sysbios_knl_Task_getModuleStateCheckValue__I));

/* moduleStateCheckFlag__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_moduleStateCheckFlag__C, ".const:ti_sysbios_knl_Task_moduleStateCheckFlag__C");
__FAR__ const CT__ti_sysbios_knl_Task_moduleStateCheckFlag ti_sysbios_knl_Task_moduleStateCheckFlag__C = 0;

/* objectCheckFxn__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_objectCheckFxn__C, ".const:ti_sysbios_knl_Task_objectCheckFxn__C");
__FAR__ const CT__ti_sysbios_knl_Task_objectCheckFxn ti_sysbios_knl_Task_objectCheckFxn__C = ((CT__ti_sysbios_knl_Task_objectCheckFxn)((xdc_Fxn)ti_sysbios_knl_Task_objectCheck__I));

/* objectCheckValueFxn__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_objectCheckValueFxn__C, ".const:ti_sysbios_knl_Task_objectCheckValueFxn__C");
__FAR__ const CT__ti_sysbios_knl_Task_objectCheckValueFxn ti_sysbios_knl_Task_objectCheckValueFxn__C = ((CT__ti_sysbios_knl_Task_objectCheckValueFxn)((xdc_Fxn)ti_sysbios_knl_Task_getObjectCheckValue__I));

/* objectCheckFlag__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_objectCheckFlag__C, ".const:ti_sysbios_knl_Task_objectCheckFlag__C");
__FAR__ const CT__ti_sysbios_knl_Task_objectCheckFlag ti_sysbios_knl_Task_objectCheckFlag__C = 0;

/* numConstructedTasks__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_numConstructedTasks__C, ".const:ti_sysbios_knl_Task_numConstructedTasks__C");
__FAR__ const CT__ti_sysbios_knl_Task_numConstructedTasks ti_sysbios_knl_Task_numConstructedTasks__C = (xdc_UInt)0x0;

/* startupHookFunc__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_startupHookFunc__C, ".const:ti_sysbios_knl_Task_startupHookFunc__C");
__FAR__ const CT__ti_sysbios_knl_Task_startupHookFunc ti_sysbios_knl_Task_startupHookFunc__C = ((CT__ti_sysbios_knl_Task_startupHookFunc)0);


/*
 * ======== ti.sysbios.knl.Task_SupportProxy INITIALIZERS ========
 */


/*
 * ======== xdc.runtime.Assert INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(xdc_runtime_Assert_Module__diagsEnabled__C, ".const:xdc_runtime_Assert_Module__diagsEnabled__C");
__FAR__ const CT__xdc_runtime_Assert_Module__diagsEnabled xdc_runtime_Assert_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(xdc_runtime_Assert_Module__diagsIncluded__C, ".const:xdc_runtime_Assert_Module__diagsIncluded__C");
__FAR__ const CT__xdc_runtime_Assert_Module__diagsIncluded xdc_runtime_Assert_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
#pragma DATA_SECTION(xdc_runtime_Assert_Module__diagsMask__C, ".const:xdc_runtime_Assert_Module__diagsMask__C");
__FAR__ const CT__xdc_runtime_Assert_Module__diagsMask xdc_runtime_Assert_Module__diagsMask__C = ((CT__xdc_runtime_Assert_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(xdc_runtime_Assert_Module__gateObj__C, ".const:xdc_runtime_Assert_Module__gateObj__C");
__FAR__ const CT__xdc_runtime_Assert_Module__gateObj xdc_runtime_Assert_Module__gateObj__C = ((CT__xdc_runtime_Assert_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(xdc_runtime_Assert_Module__gatePrms__C, ".const:xdc_runtime_Assert_Module__gatePrms__C");
__FAR__ const CT__xdc_runtime_Assert_Module__gatePrms xdc_runtime_Assert_Module__gatePrms__C = ((CT__xdc_runtime_Assert_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(xdc_runtime_Assert_Module__id__C, ".const:xdc_runtime_Assert_Module__id__C");
__FAR__ const CT__xdc_runtime_Assert_Module__id xdc_runtime_Assert_Module__id__C = (xdc_Bits16)0x8002;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(xdc_runtime_Assert_Module__loggerDefined__C, ".const:xdc_runtime_Assert_Module__loggerDefined__C");
__FAR__ const CT__xdc_runtime_Assert_Module__loggerDefined xdc_runtime_Assert_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(xdc_runtime_Assert_Module__loggerObj__C, ".const:xdc_runtime_Assert_Module__loggerObj__C");
__FAR__ const CT__xdc_runtime_Assert_Module__loggerObj xdc_runtime_Assert_Module__loggerObj__C = ((CT__xdc_runtime_Assert_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(xdc_runtime_Assert_Module__loggerFxn0__C, ".const:xdc_runtime_Assert_Module__loggerFxn0__C");
__FAR__ const CT__xdc_runtime_Assert_Module__loggerFxn0 xdc_runtime_Assert_Module__loggerFxn0__C = ((CT__xdc_runtime_Assert_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(xdc_runtime_Assert_Module__loggerFxn1__C, ".const:xdc_runtime_Assert_Module__loggerFxn1__C");
__FAR__ const CT__xdc_runtime_Assert_Module__loggerFxn1 xdc_runtime_Assert_Module__loggerFxn1__C = ((CT__xdc_runtime_Assert_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(xdc_runtime_Assert_Module__loggerFxn2__C, ".const:xdc_runtime_Assert_Module__loggerFxn2__C");
__FAR__ const CT__xdc_runtime_Assert_Module__loggerFxn2 xdc_runtime_Assert_Module__loggerFxn2__C = ((CT__xdc_runtime_Assert_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(xdc_runtime_Assert_Module__loggerFxn4__C, ".const:xdc_runtime_Assert_Module__loggerFxn4__C");
__FAR__ const CT__xdc_runtime_Assert_Module__loggerFxn4 xdc_runtime_Assert_Module__loggerFxn4__C = ((CT__xdc_runtime_Assert_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(xdc_runtime_Assert_Module__loggerFxn8__C, ".const:xdc_runtime_Assert_Module__loggerFxn8__C");
__FAR__ const CT__xdc_runtime_Assert_Module__loggerFxn8 xdc_runtime_Assert_Module__loggerFxn8__C = ((CT__xdc_runtime_Assert_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(xdc_runtime_Assert_Module__startupDoneFxn__C, ".const:xdc_runtime_Assert_Module__startupDoneFxn__C");
__FAR__ const CT__xdc_runtime_Assert_Module__startupDoneFxn xdc_runtime_Assert_Module__startupDoneFxn__C = ((CT__xdc_runtime_Assert_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(xdc_runtime_Assert_Object__count__C, ".const:xdc_runtime_Assert_Object__count__C");
__FAR__ const CT__xdc_runtime_Assert_Object__count xdc_runtime_Assert_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(xdc_runtime_Assert_Object__heap__C, ".const:xdc_runtime_Assert_Object__heap__C");
__FAR__ const CT__xdc_runtime_Assert_Object__heap xdc_runtime_Assert_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(xdc_runtime_Assert_Object__sizeof__C, ".const:xdc_runtime_Assert_Object__sizeof__C");
__FAR__ const CT__xdc_runtime_Assert_Object__sizeof xdc_runtime_Assert_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(xdc_runtime_Assert_Object__table__C, ".const:xdc_runtime_Assert_Object__table__C");
__FAR__ const CT__xdc_runtime_Assert_Object__table xdc_runtime_Assert_Object__table__C = 0;

/* E_assertFailed__C */
#pragma DATA_SECTION(xdc_runtime_Assert_E_assertFailed__C, ".const:xdc_runtime_Assert_E_assertFailed__C");
__FAR__ const CT__xdc_runtime_Assert_E_assertFailed xdc_runtime_Assert_E_assertFailed__C = (((xdc_runtime_Error_Id)4282) << 16 | 0);


/*
 * ======== xdc.runtime.Core INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(xdc_runtime_Core_Module__diagsEnabled__C, ".const:xdc_runtime_Core_Module__diagsEnabled__C");
__FAR__ const CT__xdc_runtime_Core_Module__diagsEnabled xdc_runtime_Core_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(xdc_runtime_Core_Module__diagsIncluded__C, ".const:xdc_runtime_Core_Module__diagsIncluded__C");
__FAR__ const CT__xdc_runtime_Core_Module__diagsIncluded xdc_runtime_Core_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
#pragma DATA_SECTION(xdc_runtime_Core_Module__diagsMask__C, ".const:xdc_runtime_Core_Module__diagsMask__C");
__FAR__ const CT__xdc_runtime_Core_Module__diagsMask xdc_runtime_Core_Module__diagsMask__C = ((CT__xdc_runtime_Core_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(xdc_runtime_Core_Module__gateObj__C, ".const:xdc_runtime_Core_Module__gateObj__C");
__FAR__ const CT__xdc_runtime_Core_Module__gateObj xdc_runtime_Core_Module__gateObj__C = ((CT__xdc_runtime_Core_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(xdc_runtime_Core_Module__gatePrms__C, ".const:xdc_runtime_Core_Module__gatePrms__C");
__FAR__ const CT__xdc_runtime_Core_Module__gatePrms xdc_runtime_Core_Module__gatePrms__C = ((CT__xdc_runtime_Core_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(xdc_runtime_Core_Module__id__C, ".const:xdc_runtime_Core_Module__id__C");
__FAR__ const CT__xdc_runtime_Core_Module__id xdc_runtime_Core_Module__id__C = (xdc_Bits16)0x8003;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(xdc_runtime_Core_Module__loggerDefined__C, ".const:xdc_runtime_Core_Module__loggerDefined__C");
__FAR__ const CT__xdc_runtime_Core_Module__loggerDefined xdc_runtime_Core_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(xdc_runtime_Core_Module__loggerObj__C, ".const:xdc_runtime_Core_Module__loggerObj__C");
__FAR__ const CT__xdc_runtime_Core_Module__loggerObj xdc_runtime_Core_Module__loggerObj__C = ((CT__xdc_runtime_Core_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(xdc_runtime_Core_Module__loggerFxn0__C, ".const:xdc_runtime_Core_Module__loggerFxn0__C");
__FAR__ const CT__xdc_runtime_Core_Module__loggerFxn0 xdc_runtime_Core_Module__loggerFxn0__C = ((CT__xdc_runtime_Core_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(xdc_runtime_Core_Module__loggerFxn1__C, ".const:xdc_runtime_Core_Module__loggerFxn1__C");
__FAR__ const CT__xdc_runtime_Core_Module__loggerFxn1 xdc_runtime_Core_Module__loggerFxn1__C = ((CT__xdc_runtime_Core_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(xdc_runtime_Core_Module__loggerFxn2__C, ".const:xdc_runtime_Core_Module__loggerFxn2__C");
__FAR__ const CT__xdc_runtime_Core_Module__loggerFxn2 xdc_runtime_Core_Module__loggerFxn2__C = ((CT__xdc_runtime_Core_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(xdc_runtime_Core_Module__loggerFxn4__C, ".const:xdc_runtime_Core_Module__loggerFxn4__C");
__FAR__ const CT__xdc_runtime_Core_Module__loggerFxn4 xdc_runtime_Core_Module__loggerFxn4__C = ((CT__xdc_runtime_Core_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(xdc_runtime_Core_Module__loggerFxn8__C, ".const:xdc_runtime_Core_Module__loggerFxn8__C");
__FAR__ const CT__xdc_runtime_Core_Module__loggerFxn8 xdc_runtime_Core_Module__loggerFxn8__C = ((CT__xdc_runtime_Core_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(xdc_runtime_Core_Module__startupDoneFxn__C, ".const:xdc_runtime_Core_Module__startupDoneFxn__C");
__FAR__ const CT__xdc_runtime_Core_Module__startupDoneFxn xdc_runtime_Core_Module__startupDoneFxn__C = ((CT__xdc_runtime_Core_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(xdc_runtime_Core_Object__count__C, ".const:xdc_runtime_Core_Object__count__C");
__FAR__ const CT__xdc_runtime_Core_Object__count xdc_runtime_Core_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(xdc_runtime_Core_Object__heap__C, ".const:xdc_runtime_Core_Object__heap__C");
__FAR__ const CT__xdc_runtime_Core_Object__heap xdc_runtime_Core_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(xdc_runtime_Core_Object__sizeof__C, ".const:xdc_runtime_Core_Object__sizeof__C");
__FAR__ const CT__xdc_runtime_Core_Object__sizeof xdc_runtime_Core_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(xdc_runtime_Core_Object__table__C, ".const:xdc_runtime_Core_Object__table__C");
__FAR__ const CT__xdc_runtime_Core_Object__table xdc_runtime_Core_Object__table__C = 0;

/* A_initializedParams__C */
#pragma DATA_SECTION(xdc_runtime_Core_A_initializedParams__C, ".const:xdc_runtime_Core_A_initializedParams__C");
__FAR__ const CT__xdc_runtime_Core_A_initializedParams xdc_runtime_Core_A_initializedParams__C = (((xdc_runtime_Assert_Id)1) << 16 | 16);


/*
 * ======== xdc.runtime.Defaults INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__diagsEnabled__C, ".const:xdc_runtime_Defaults_Module__diagsEnabled__C");
__FAR__ const CT__xdc_runtime_Defaults_Module__diagsEnabled xdc_runtime_Defaults_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__diagsIncluded__C, ".const:xdc_runtime_Defaults_Module__diagsIncluded__C");
__FAR__ const CT__xdc_runtime_Defaults_Module__diagsIncluded xdc_runtime_Defaults_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__diagsMask__C, ".const:xdc_runtime_Defaults_Module__diagsMask__C");
__FAR__ const CT__xdc_runtime_Defaults_Module__diagsMask xdc_runtime_Defaults_Module__diagsMask__C = ((CT__xdc_runtime_Defaults_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__gateObj__C, ".const:xdc_runtime_Defaults_Module__gateObj__C");
__FAR__ const CT__xdc_runtime_Defaults_Module__gateObj xdc_runtime_Defaults_Module__gateObj__C = ((CT__xdc_runtime_Defaults_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__gatePrms__C, ".const:xdc_runtime_Defaults_Module__gatePrms__C");
__FAR__ const CT__xdc_runtime_Defaults_Module__gatePrms xdc_runtime_Defaults_Module__gatePrms__C = ((CT__xdc_runtime_Defaults_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__id__C, ".const:xdc_runtime_Defaults_Module__id__C");
__FAR__ const CT__xdc_runtime_Defaults_Module__id xdc_runtime_Defaults_Module__id__C = (xdc_Bits16)0x8004;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__loggerDefined__C, ".const:xdc_runtime_Defaults_Module__loggerDefined__C");
__FAR__ const CT__xdc_runtime_Defaults_Module__loggerDefined xdc_runtime_Defaults_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__loggerObj__C, ".const:xdc_runtime_Defaults_Module__loggerObj__C");
__FAR__ const CT__xdc_runtime_Defaults_Module__loggerObj xdc_runtime_Defaults_Module__loggerObj__C = ((CT__xdc_runtime_Defaults_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__loggerFxn0__C, ".const:xdc_runtime_Defaults_Module__loggerFxn0__C");
__FAR__ const CT__xdc_runtime_Defaults_Module__loggerFxn0 xdc_runtime_Defaults_Module__loggerFxn0__C = ((CT__xdc_runtime_Defaults_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__loggerFxn1__C, ".const:xdc_runtime_Defaults_Module__loggerFxn1__C");
__FAR__ const CT__xdc_runtime_Defaults_Module__loggerFxn1 xdc_runtime_Defaults_Module__loggerFxn1__C = ((CT__xdc_runtime_Defaults_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__loggerFxn2__C, ".const:xdc_runtime_Defaults_Module__loggerFxn2__C");
__FAR__ const CT__xdc_runtime_Defaults_Module__loggerFxn2 xdc_runtime_Defaults_Module__loggerFxn2__C = ((CT__xdc_runtime_Defaults_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__loggerFxn4__C, ".const:xdc_runtime_Defaults_Module__loggerFxn4__C");
__FAR__ const CT__xdc_runtime_Defaults_Module__loggerFxn4 xdc_runtime_Defaults_Module__loggerFxn4__C = ((CT__xdc_runtime_Defaults_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__loggerFxn8__C, ".const:xdc_runtime_Defaults_Module__loggerFxn8__C");
__FAR__ const CT__xdc_runtime_Defaults_Module__loggerFxn8 xdc_runtime_Defaults_Module__loggerFxn8__C = ((CT__xdc_runtime_Defaults_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__startupDoneFxn__C, ".const:xdc_runtime_Defaults_Module__startupDoneFxn__C");
__FAR__ const CT__xdc_runtime_Defaults_Module__startupDoneFxn xdc_runtime_Defaults_Module__startupDoneFxn__C = ((CT__xdc_runtime_Defaults_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(xdc_runtime_Defaults_Object__count__C, ".const:xdc_runtime_Defaults_Object__count__C");
__FAR__ const CT__xdc_runtime_Defaults_Object__count xdc_runtime_Defaults_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(xdc_runtime_Defaults_Object__heap__C, ".const:xdc_runtime_Defaults_Object__heap__C");
__FAR__ const CT__xdc_runtime_Defaults_Object__heap xdc_runtime_Defaults_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(xdc_runtime_Defaults_Object__sizeof__C, ".const:xdc_runtime_Defaults_Object__sizeof__C");
__FAR__ const CT__xdc_runtime_Defaults_Object__sizeof xdc_runtime_Defaults_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(xdc_runtime_Defaults_Object__table__C, ".const:xdc_runtime_Defaults_Object__table__C");
__FAR__ const CT__xdc_runtime_Defaults_Object__table xdc_runtime_Defaults_Object__table__C = 0;


/*
 * ======== xdc.runtime.Diags INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(xdc_runtime_Diags_Module__diagsEnabled__C, ".const:xdc_runtime_Diags_Module__diagsEnabled__C");
__FAR__ const CT__xdc_runtime_Diags_Module__diagsEnabled xdc_runtime_Diags_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(xdc_runtime_Diags_Module__diagsIncluded__C, ".const:xdc_runtime_Diags_Module__diagsIncluded__C");
__FAR__ const CT__xdc_runtime_Diags_Module__diagsIncluded xdc_runtime_Diags_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
#pragma DATA_SECTION(xdc_runtime_Diags_Module__diagsMask__C, ".const:xdc_runtime_Diags_Module__diagsMask__C");
__FAR__ const CT__xdc_runtime_Diags_Module__diagsMask xdc_runtime_Diags_Module__diagsMask__C = ((CT__xdc_runtime_Diags_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(xdc_runtime_Diags_Module__gateObj__C, ".const:xdc_runtime_Diags_Module__gateObj__C");
__FAR__ const CT__xdc_runtime_Diags_Module__gateObj xdc_runtime_Diags_Module__gateObj__C = ((CT__xdc_runtime_Diags_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(xdc_runtime_Diags_Module__gatePrms__C, ".const:xdc_runtime_Diags_Module__gatePrms__C");
__FAR__ const CT__xdc_runtime_Diags_Module__gatePrms xdc_runtime_Diags_Module__gatePrms__C = ((CT__xdc_runtime_Diags_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(xdc_runtime_Diags_Module__id__C, ".const:xdc_runtime_Diags_Module__id__C");
__FAR__ const CT__xdc_runtime_Diags_Module__id xdc_runtime_Diags_Module__id__C = (xdc_Bits16)0x8005;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(xdc_runtime_Diags_Module__loggerDefined__C, ".const:xdc_runtime_Diags_Module__loggerDefined__C");
__FAR__ const CT__xdc_runtime_Diags_Module__loggerDefined xdc_runtime_Diags_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(xdc_runtime_Diags_Module__loggerObj__C, ".const:xdc_runtime_Diags_Module__loggerObj__C");
__FAR__ const CT__xdc_runtime_Diags_Module__loggerObj xdc_runtime_Diags_Module__loggerObj__C = ((CT__xdc_runtime_Diags_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(xdc_runtime_Diags_Module__loggerFxn0__C, ".const:xdc_runtime_Diags_Module__loggerFxn0__C");
__FAR__ const CT__xdc_runtime_Diags_Module__loggerFxn0 xdc_runtime_Diags_Module__loggerFxn0__C = ((CT__xdc_runtime_Diags_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(xdc_runtime_Diags_Module__loggerFxn1__C, ".const:xdc_runtime_Diags_Module__loggerFxn1__C");
__FAR__ const CT__xdc_runtime_Diags_Module__loggerFxn1 xdc_runtime_Diags_Module__loggerFxn1__C = ((CT__xdc_runtime_Diags_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(xdc_runtime_Diags_Module__loggerFxn2__C, ".const:xdc_runtime_Diags_Module__loggerFxn2__C");
__FAR__ const CT__xdc_runtime_Diags_Module__loggerFxn2 xdc_runtime_Diags_Module__loggerFxn2__C = ((CT__xdc_runtime_Diags_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(xdc_runtime_Diags_Module__loggerFxn4__C, ".const:xdc_runtime_Diags_Module__loggerFxn4__C");
__FAR__ const CT__xdc_runtime_Diags_Module__loggerFxn4 xdc_runtime_Diags_Module__loggerFxn4__C = ((CT__xdc_runtime_Diags_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(xdc_runtime_Diags_Module__loggerFxn8__C, ".const:xdc_runtime_Diags_Module__loggerFxn8__C");
__FAR__ const CT__xdc_runtime_Diags_Module__loggerFxn8 xdc_runtime_Diags_Module__loggerFxn8__C = ((CT__xdc_runtime_Diags_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(xdc_runtime_Diags_Module__startupDoneFxn__C, ".const:xdc_runtime_Diags_Module__startupDoneFxn__C");
__FAR__ const CT__xdc_runtime_Diags_Module__startupDoneFxn xdc_runtime_Diags_Module__startupDoneFxn__C = ((CT__xdc_runtime_Diags_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(xdc_runtime_Diags_Object__count__C, ".const:xdc_runtime_Diags_Object__count__C");
__FAR__ const CT__xdc_runtime_Diags_Object__count xdc_runtime_Diags_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(xdc_runtime_Diags_Object__heap__C, ".const:xdc_runtime_Diags_Object__heap__C");
__FAR__ const CT__xdc_runtime_Diags_Object__heap xdc_runtime_Diags_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(xdc_runtime_Diags_Object__sizeof__C, ".const:xdc_runtime_Diags_Object__sizeof__C");
__FAR__ const CT__xdc_runtime_Diags_Object__sizeof xdc_runtime_Diags_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(xdc_runtime_Diags_Object__table__C, ".const:xdc_runtime_Diags_Object__table__C");
__FAR__ const CT__xdc_runtime_Diags_Object__table xdc_runtime_Diags_Object__table__C = 0;

/* setMaskEnabled__C */
#pragma DATA_SECTION(xdc_runtime_Diags_setMaskEnabled__C, ".const:xdc_runtime_Diags_setMaskEnabled__C");
__FAR__ const CT__xdc_runtime_Diags_setMaskEnabled xdc_runtime_Diags_setMaskEnabled__C = 0;

/* dictBase__C */
#pragma DATA_SECTION(xdc_runtime_Diags_dictBase__C, ".const:xdc_runtime_Diags_dictBase__C");
__FAR__ const CT__xdc_runtime_Diags_dictBase xdc_runtime_Diags_dictBase__C = ((CT__xdc_runtime_Diags_dictBase)0);


/*
 * ======== xdc.runtime.Error INITIALIZERS ========
 */

/* Module__state__V */
#if defined (__ICCARM__)
#pragma location = ".data_xdc_runtime_Error_Module__state__V"
#endif
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
#ifndef __TI_COMPILER_VERSION__
xdc_runtime_Error_Module_State__ xdc_runtime_Error_Module__state__V __attribute__ ((section(".data_xdc_runtime_Error_Module__state__V")));
#endif
#endif
xdc_runtime_Error_Module_State__ xdc_runtime_Error_Module__state__V = {
    (xdc_UInt16)0x0,  /* count */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(xdc_runtime_Error_Module__diagsEnabled__C, ".const:xdc_runtime_Error_Module__diagsEnabled__C");
__FAR__ const CT__xdc_runtime_Error_Module__diagsEnabled xdc_runtime_Error_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(xdc_runtime_Error_Module__diagsIncluded__C, ".const:xdc_runtime_Error_Module__diagsIncluded__C");
__FAR__ const CT__xdc_runtime_Error_Module__diagsIncluded xdc_runtime_Error_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(xdc_runtime_Error_Module__diagsMask__C, ".const:xdc_runtime_Error_Module__diagsMask__C");
__FAR__ const CT__xdc_runtime_Error_Module__diagsMask xdc_runtime_Error_Module__diagsMask__C = ((CT__xdc_runtime_Error_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(xdc_runtime_Error_Module__gateObj__C, ".const:xdc_runtime_Error_Module__gateObj__C");
__FAR__ const CT__xdc_runtime_Error_Module__gateObj xdc_runtime_Error_Module__gateObj__C = ((CT__xdc_runtime_Error_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(xdc_runtime_Error_Module__gatePrms__C, ".const:xdc_runtime_Error_Module__gatePrms__C");
__FAR__ const CT__xdc_runtime_Error_Module__gatePrms xdc_runtime_Error_Module__gatePrms__C = ((CT__xdc_runtime_Error_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(xdc_runtime_Error_Module__id__C, ".const:xdc_runtime_Error_Module__id__C");
__FAR__ const CT__xdc_runtime_Error_Module__id xdc_runtime_Error_Module__id__C = (xdc_Bits16)0x8006;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(xdc_runtime_Error_Module__loggerDefined__C, ".const:xdc_runtime_Error_Module__loggerDefined__C");
__FAR__ const CT__xdc_runtime_Error_Module__loggerDefined xdc_runtime_Error_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(xdc_runtime_Error_Module__loggerObj__C, ".const:xdc_runtime_Error_Module__loggerObj__C");
__FAR__ const CT__xdc_runtime_Error_Module__loggerObj xdc_runtime_Error_Module__loggerObj__C = ((CT__xdc_runtime_Error_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(xdc_runtime_Error_Module__loggerFxn0__C, ".const:xdc_runtime_Error_Module__loggerFxn0__C");
__FAR__ const CT__xdc_runtime_Error_Module__loggerFxn0 xdc_runtime_Error_Module__loggerFxn0__C = ((CT__xdc_runtime_Error_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(xdc_runtime_Error_Module__loggerFxn1__C, ".const:xdc_runtime_Error_Module__loggerFxn1__C");
__FAR__ const CT__xdc_runtime_Error_Module__loggerFxn1 xdc_runtime_Error_Module__loggerFxn1__C = ((CT__xdc_runtime_Error_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(xdc_runtime_Error_Module__loggerFxn2__C, ".const:xdc_runtime_Error_Module__loggerFxn2__C");
__FAR__ const CT__xdc_runtime_Error_Module__loggerFxn2 xdc_runtime_Error_Module__loggerFxn2__C = ((CT__xdc_runtime_Error_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(xdc_runtime_Error_Module__loggerFxn4__C, ".const:xdc_runtime_Error_Module__loggerFxn4__C");
__FAR__ const CT__xdc_runtime_Error_Module__loggerFxn4 xdc_runtime_Error_Module__loggerFxn4__C = ((CT__xdc_runtime_Error_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(xdc_runtime_Error_Module__loggerFxn8__C, ".const:xdc_runtime_Error_Module__loggerFxn8__C");
__FAR__ const CT__xdc_runtime_Error_Module__loggerFxn8 xdc_runtime_Error_Module__loggerFxn8__C = ((CT__xdc_runtime_Error_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(xdc_runtime_Error_Module__startupDoneFxn__C, ".const:xdc_runtime_Error_Module__startupDoneFxn__C");
__FAR__ const CT__xdc_runtime_Error_Module__startupDoneFxn xdc_runtime_Error_Module__startupDoneFxn__C = ((CT__xdc_runtime_Error_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(xdc_runtime_Error_Object__count__C, ".const:xdc_runtime_Error_Object__count__C");
__FAR__ const CT__xdc_runtime_Error_Object__count xdc_runtime_Error_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(xdc_runtime_Error_Object__heap__C, ".const:xdc_runtime_Error_Object__heap__C");
__FAR__ const CT__xdc_runtime_Error_Object__heap xdc_runtime_Error_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(xdc_runtime_Error_Object__sizeof__C, ".const:xdc_runtime_Error_Object__sizeof__C");
__FAR__ const CT__xdc_runtime_Error_Object__sizeof xdc_runtime_Error_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(xdc_runtime_Error_Object__table__C, ".const:xdc_runtime_Error_Object__table__C");
__FAR__ const CT__xdc_runtime_Error_Object__table xdc_runtime_Error_Object__table__C = 0;

/* policyFxn__C */
#pragma DATA_SECTION(xdc_runtime_Error_policyFxn__C, ".const:xdc_runtime_Error_policyFxn__C");
__FAR__ const CT__xdc_runtime_Error_policyFxn xdc_runtime_Error_policyFxn__C = ((CT__xdc_runtime_Error_policyFxn)((xdc_Fxn)xdc_runtime_Error_policyDefault__E));

/* E_generic__C */
#pragma DATA_SECTION(xdc_runtime_Error_E_generic__C, ".const:xdc_runtime_Error_E_generic__C");
__FAR__ const CT__xdc_runtime_Error_E_generic xdc_runtime_Error_E_generic__C = (((xdc_runtime_Error_Id)4304) << 16 | 0);

/* E_memory__C */
#pragma DATA_SECTION(xdc_runtime_Error_E_memory__C, ".const:xdc_runtime_Error_E_memory__C");
__FAR__ const CT__xdc_runtime_Error_E_memory xdc_runtime_Error_E_memory__C = (((xdc_runtime_Error_Id)4308) << 16 | 0);

/* E_msgCode__C */
#pragma DATA_SECTION(xdc_runtime_Error_E_msgCode__C, ".const:xdc_runtime_Error_E_msgCode__C");
__FAR__ const CT__xdc_runtime_Error_E_msgCode xdc_runtime_Error_E_msgCode__C = (((xdc_runtime_Error_Id)4342) << 16 | 0);

/* policy__C */
#pragma DATA_SECTION(xdc_runtime_Error_policy__C, ".const:xdc_runtime_Error_policy__C");
__FAR__ const CT__xdc_runtime_Error_policy xdc_runtime_Error_policy__C = xdc_runtime_Error_UNWIND;

/* raiseHook__C */
#pragma DATA_SECTION(xdc_runtime_Error_raiseHook__C, ".const:xdc_runtime_Error_raiseHook__C");
__FAR__ const CT__xdc_runtime_Error_raiseHook xdc_runtime_Error_raiseHook__C = ((CT__xdc_runtime_Error_raiseHook)((xdc_Fxn)ti_sysbios_BIOS_errorRaiseHook__I));

/* maxDepth__C */
#pragma DATA_SECTION(xdc_runtime_Error_maxDepth__C, ".const:xdc_runtime_Error_maxDepth__C");
__FAR__ const CT__xdc_runtime_Error_maxDepth xdc_runtime_Error_maxDepth__C = (xdc_UInt16)0x10;


/*
 * ======== xdc.runtime.Gate INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(xdc_runtime_Gate_Module__diagsEnabled__C, ".const:xdc_runtime_Gate_Module__diagsEnabled__C");
__FAR__ const CT__xdc_runtime_Gate_Module__diagsEnabled xdc_runtime_Gate_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(xdc_runtime_Gate_Module__diagsIncluded__C, ".const:xdc_runtime_Gate_Module__diagsIncluded__C");
__FAR__ const CT__xdc_runtime_Gate_Module__diagsIncluded xdc_runtime_Gate_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
#pragma DATA_SECTION(xdc_runtime_Gate_Module__diagsMask__C, ".const:xdc_runtime_Gate_Module__diagsMask__C");
__FAR__ const CT__xdc_runtime_Gate_Module__diagsMask xdc_runtime_Gate_Module__diagsMask__C = ((CT__xdc_runtime_Gate_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(xdc_runtime_Gate_Module__gateObj__C, ".const:xdc_runtime_Gate_Module__gateObj__C");
__FAR__ const CT__xdc_runtime_Gate_Module__gateObj xdc_runtime_Gate_Module__gateObj__C = ((CT__xdc_runtime_Gate_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(xdc_runtime_Gate_Module__gatePrms__C, ".const:xdc_runtime_Gate_Module__gatePrms__C");
__FAR__ const CT__xdc_runtime_Gate_Module__gatePrms xdc_runtime_Gate_Module__gatePrms__C = ((CT__xdc_runtime_Gate_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(xdc_runtime_Gate_Module__id__C, ".const:xdc_runtime_Gate_Module__id__C");
__FAR__ const CT__xdc_runtime_Gate_Module__id xdc_runtime_Gate_Module__id__C = (xdc_Bits16)0x8007;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(xdc_runtime_Gate_Module__loggerDefined__C, ".const:xdc_runtime_Gate_Module__loggerDefined__C");
__FAR__ const CT__xdc_runtime_Gate_Module__loggerDefined xdc_runtime_Gate_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(xdc_runtime_Gate_Module__loggerObj__C, ".const:xdc_runtime_Gate_Module__loggerObj__C");
__FAR__ const CT__xdc_runtime_Gate_Module__loggerObj xdc_runtime_Gate_Module__loggerObj__C = ((CT__xdc_runtime_Gate_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(xdc_runtime_Gate_Module__loggerFxn0__C, ".const:xdc_runtime_Gate_Module__loggerFxn0__C");
__FAR__ const CT__xdc_runtime_Gate_Module__loggerFxn0 xdc_runtime_Gate_Module__loggerFxn0__C = ((CT__xdc_runtime_Gate_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(xdc_runtime_Gate_Module__loggerFxn1__C, ".const:xdc_runtime_Gate_Module__loggerFxn1__C");
__FAR__ const CT__xdc_runtime_Gate_Module__loggerFxn1 xdc_runtime_Gate_Module__loggerFxn1__C = ((CT__xdc_runtime_Gate_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(xdc_runtime_Gate_Module__loggerFxn2__C, ".const:xdc_runtime_Gate_Module__loggerFxn2__C");
__FAR__ const CT__xdc_runtime_Gate_Module__loggerFxn2 xdc_runtime_Gate_Module__loggerFxn2__C = ((CT__xdc_runtime_Gate_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(xdc_runtime_Gate_Module__loggerFxn4__C, ".const:xdc_runtime_Gate_Module__loggerFxn4__C");
__FAR__ const CT__xdc_runtime_Gate_Module__loggerFxn4 xdc_runtime_Gate_Module__loggerFxn4__C = ((CT__xdc_runtime_Gate_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(xdc_runtime_Gate_Module__loggerFxn8__C, ".const:xdc_runtime_Gate_Module__loggerFxn8__C");
__FAR__ const CT__xdc_runtime_Gate_Module__loggerFxn8 xdc_runtime_Gate_Module__loggerFxn8__C = ((CT__xdc_runtime_Gate_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(xdc_runtime_Gate_Module__startupDoneFxn__C, ".const:xdc_runtime_Gate_Module__startupDoneFxn__C");
__FAR__ const CT__xdc_runtime_Gate_Module__startupDoneFxn xdc_runtime_Gate_Module__startupDoneFxn__C = ((CT__xdc_runtime_Gate_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(xdc_runtime_Gate_Object__count__C, ".const:xdc_runtime_Gate_Object__count__C");
__FAR__ const CT__xdc_runtime_Gate_Object__count xdc_runtime_Gate_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(xdc_runtime_Gate_Object__heap__C, ".const:xdc_runtime_Gate_Object__heap__C");
__FAR__ const CT__xdc_runtime_Gate_Object__heap xdc_runtime_Gate_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(xdc_runtime_Gate_Object__sizeof__C, ".const:xdc_runtime_Gate_Object__sizeof__C");
__FAR__ const CT__xdc_runtime_Gate_Object__sizeof xdc_runtime_Gate_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(xdc_runtime_Gate_Object__table__C, ".const:xdc_runtime_Gate_Object__table__C");
__FAR__ const CT__xdc_runtime_Gate_Object__table xdc_runtime_Gate_Object__table__C = 0;


/*
 * ======== xdc.runtime.Log INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(xdc_runtime_Log_Module__diagsEnabled__C, ".const:xdc_runtime_Log_Module__diagsEnabled__C");
__FAR__ const CT__xdc_runtime_Log_Module__diagsEnabled xdc_runtime_Log_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(xdc_runtime_Log_Module__diagsIncluded__C, ".const:xdc_runtime_Log_Module__diagsIncluded__C");
__FAR__ const CT__xdc_runtime_Log_Module__diagsIncluded xdc_runtime_Log_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
#pragma DATA_SECTION(xdc_runtime_Log_Module__diagsMask__C, ".const:xdc_runtime_Log_Module__diagsMask__C");
__FAR__ const CT__xdc_runtime_Log_Module__diagsMask xdc_runtime_Log_Module__diagsMask__C = ((CT__xdc_runtime_Log_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(xdc_runtime_Log_Module__gateObj__C, ".const:xdc_runtime_Log_Module__gateObj__C");
__FAR__ const CT__xdc_runtime_Log_Module__gateObj xdc_runtime_Log_Module__gateObj__C = ((CT__xdc_runtime_Log_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(xdc_runtime_Log_Module__gatePrms__C, ".const:xdc_runtime_Log_Module__gatePrms__C");
__FAR__ const CT__xdc_runtime_Log_Module__gatePrms xdc_runtime_Log_Module__gatePrms__C = ((CT__xdc_runtime_Log_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(xdc_runtime_Log_Module__id__C, ".const:xdc_runtime_Log_Module__id__C");
__FAR__ const CT__xdc_runtime_Log_Module__id xdc_runtime_Log_Module__id__C = (xdc_Bits16)0x8008;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(xdc_runtime_Log_Module__loggerDefined__C, ".const:xdc_runtime_Log_Module__loggerDefined__C");
__FAR__ const CT__xdc_runtime_Log_Module__loggerDefined xdc_runtime_Log_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(xdc_runtime_Log_Module__loggerObj__C, ".const:xdc_runtime_Log_Module__loggerObj__C");
__FAR__ const CT__xdc_runtime_Log_Module__loggerObj xdc_runtime_Log_Module__loggerObj__C = ((CT__xdc_runtime_Log_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(xdc_runtime_Log_Module__loggerFxn0__C, ".const:xdc_runtime_Log_Module__loggerFxn0__C");
__FAR__ const CT__xdc_runtime_Log_Module__loggerFxn0 xdc_runtime_Log_Module__loggerFxn0__C = ((CT__xdc_runtime_Log_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(xdc_runtime_Log_Module__loggerFxn1__C, ".const:xdc_runtime_Log_Module__loggerFxn1__C");
__FAR__ const CT__xdc_runtime_Log_Module__loggerFxn1 xdc_runtime_Log_Module__loggerFxn1__C = ((CT__xdc_runtime_Log_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(xdc_runtime_Log_Module__loggerFxn2__C, ".const:xdc_runtime_Log_Module__loggerFxn2__C");
__FAR__ const CT__xdc_runtime_Log_Module__loggerFxn2 xdc_runtime_Log_Module__loggerFxn2__C = ((CT__xdc_runtime_Log_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(xdc_runtime_Log_Module__loggerFxn4__C, ".const:xdc_runtime_Log_Module__loggerFxn4__C");
__FAR__ const CT__xdc_runtime_Log_Module__loggerFxn4 xdc_runtime_Log_Module__loggerFxn4__C = ((CT__xdc_runtime_Log_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(xdc_runtime_Log_Module__loggerFxn8__C, ".const:xdc_runtime_Log_Module__loggerFxn8__C");
__FAR__ const CT__xdc_runtime_Log_Module__loggerFxn8 xdc_runtime_Log_Module__loggerFxn8__C = ((CT__xdc_runtime_Log_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(xdc_runtime_Log_Module__startupDoneFxn__C, ".const:xdc_runtime_Log_Module__startupDoneFxn__C");
__FAR__ const CT__xdc_runtime_Log_Module__startupDoneFxn xdc_runtime_Log_Module__startupDoneFxn__C = ((CT__xdc_runtime_Log_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(xdc_runtime_Log_Object__count__C, ".const:xdc_runtime_Log_Object__count__C");
__FAR__ const CT__xdc_runtime_Log_Object__count xdc_runtime_Log_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(xdc_runtime_Log_Object__heap__C, ".const:xdc_runtime_Log_Object__heap__C");
__FAR__ const CT__xdc_runtime_Log_Object__heap xdc_runtime_Log_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(xdc_runtime_Log_Object__sizeof__C, ".const:xdc_runtime_Log_Object__sizeof__C");
__FAR__ const CT__xdc_runtime_Log_Object__sizeof xdc_runtime_Log_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(xdc_runtime_Log_Object__table__C, ".const:xdc_runtime_Log_Object__table__C");
__FAR__ const CT__xdc_runtime_Log_Object__table xdc_runtime_Log_Object__table__C = 0;

/* L_construct__C */
#pragma DATA_SECTION(xdc_runtime_Log_L_construct__C, ".const:xdc_runtime_Log_L_construct__C");
__FAR__ const CT__xdc_runtime_Log_L_construct xdc_runtime_Log_L_construct__C = (((xdc_runtime_Log_Event)5697) << 16 | 4);

/* L_create__C */
#pragma DATA_SECTION(xdc_runtime_Log_L_create__C, ".const:xdc_runtime_Log_L_create__C");
__FAR__ const CT__xdc_runtime_Log_L_create xdc_runtime_Log_L_create__C = (((xdc_runtime_Log_Event)5721) << 16 | 4);

/* L_destruct__C */
#pragma DATA_SECTION(xdc_runtime_Log_L_destruct__C, ".const:xdc_runtime_Log_L_destruct__C");
__FAR__ const CT__xdc_runtime_Log_L_destruct xdc_runtime_Log_L_destruct__C = (((xdc_runtime_Log_Event)5742) << 16 | 4);

/* L_delete__C */
#pragma DATA_SECTION(xdc_runtime_Log_L_delete__C, ".const:xdc_runtime_Log_L_delete__C");
__FAR__ const CT__xdc_runtime_Log_L_delete xdc_runtime_Log_L_delete__C = (((xdc_runtime_Log_Event)5761) << 16 | 4);

/* L_error__C */
#pragma DATA_SECTION(xdc_runtime_Log_L_error__C, ".const:xdc_runtime_Log_L_error__C");
__FAR__ const CT__xdc_runtime_Log_L_error xdc_runtime_Log_L_error__C = (((xdc_runtime_Log_Event)5778) << 16 | 192);

/* L_warning__C */
#pragma DATA_SECTION(xdc_runtime_Log_L_warning__C, ".const:xdc_runtime_Log_L_warning__C");
__FAR__ const CT__xdc_runtime_Log_L_warning xdc_runtime_Log_L_warning__C = (((xdc_runtime_Log_Event)5792) << 16 | 224);

/* L_info__C */
#pragma DATA_SECTION(xdc_runtime_Log_L_info__C, ".const:xdc_runtime_Log_L_info__C");
__FAR__ const CT__xdc_runtime_Log_L_info xdc_runtime_Log_L_info__C = (((xdc_runtime_Log_Event)5808) << 16 | 16384);

/* L_start__C */
#pragma DATA_SECTION(xdc_runtime_Log_L_start__C, ".const:xdc_runtime_Log_L_start__C");
__FAR__ const CT__xdc_runtime_Log_L_start xdc_runtime_Log_L_start__C = (((xdc_runtime_Log_Event)5815) << 16 | 32768);

/* L_stop__C */
#pragma DATA_SECTION(xdc_runtime_Log_L_stop__C, ".const:xdc_runtime_Log_L_stop__C");
__FAR__ const CT__xdc_runtime_Log_L_stop xdc_runtime_Log_L_stop__C = (((xdc_runtime_Log_Event)5826) << 16 | 32768);

/* L_startInstance__C */
#pragma DATA_SECTION(xdc_runtime_Log_L_startInstance__C, ".const:xdc_runtime_Log_L_startInstance__C");
__FAR__ const CT__xdc_runtime_Log_L_startInstance xdc_runtime_Log_L_startInstance__C = (((xdc_runtime_Log_Event)5836) << 16 | 32768);

/* L_stopInstance__C */
#pragma DATA_SECTION(xdc_runtime_Log_L_stopInstance__C, ".const:xdc_runtime_Log_L_stopInstance__C");
__FAR__ const CT__xdc_runtime_Log_L_stopInstance xdc_runtime_Log_L_stopInstance__C = (((xdc_runtime_Log_Event)5855) << 16 | 32768);


/*
 * ======== xdc.runtime.Main INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(xdc_runtime_Main_Module__diagsEnabled__C, ".const:xdc_runtime_Main_Module__diagsEnabled__C");
__FAR__ const CT__xdc_runtime_Main_Module__diagsEnabled xdc_runtime_Main_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(xdc_runtime_Main_Module__diagsIncluded__C, ".const:xdc_runtime_Main_Module__diagsIncluded__C");
__FAR__ const CT__xdc_runtime_Main_Module__diagsIncluded xdc_runtime_Main_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(xdc_runtime_Main_Module__diagsMask__C, ".const:xdc_runtime_Main_Module__diagsMask__C");
__FAR__ const CT__xdc_runtime_Main_Module__diagsMask xdc_runtime_Main_Module__diagsMask__C = ((CT__xdc_runtime_Main_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(xdc_runtime_Main_Module__gateObj__C, ".const:xdc_runtime_Main_Module__gateObj__C");
__FAR__ const CT__xdc_runtime_Main_Module__gateObj xdc_runtime_Main_Module__gateObj__C = ((CT__xdc_runtime_Main_Module__gateObj)((void*)(xdc_runtime_IGateProvider_Handle)&ti_sysbios_gates_GateHwi_Object__table__V[0]));

/* Module__gatePrms__C */
#pragma DATA_SECTION(xdc_runtime_Main_Module__gatePrms__C, ".const:xdc_runtime_Main_Module__gatePrms__C");
__FAR__ const CT__xdc_runtime_Main_Module__gatePrms xdc_runtime_Main_Module__gatePrms__C = ((CT__xdc_runtime_Main_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(xdc_runtime_Main_Module__id__C, ".const:xdc_runtime_Main_Module__id__C");
__FAR__ const CT__xdc_runtime_Main_Module__id xdc_runtime_Main_Module__id__C = (xdc_Bits16)0x8009;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(xdc_runtime_Main_Module__loggerDefined__C, ".const:xdc_runtime_Main_Module__loggerDefined__C");
__FAR__ const CT__xdc_runtime_Main_Module__loggerDefined xdc_runtime_Main_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(xdc_runtime_Main_Module__loggerObj__C, ".const:xdc_runtime_Main_Module__loggerObj__C");
__FAR__ const CT__xdc_runtime_Main_Module__loggerObj xdc_runtime_Main_Module__loggerObj__C = ((CT__xdc_runtime_Main_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(xdc_runtime_Main_Module__loggerFxn0__C, ".const:xdc_runtime_Main_Module__loggerFxn0__C");
__FAR__ const CT__xdc_runtime_Main_Module__loggerFxn0 xdc_runtime_Main_Module__loggerFxn0__C = ((CT__xdc_runtime_Main_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(xdc_runtime_Main_Module__loggerFxn1__C, ".const:xdc_runtime_Main_Module__loggerFxn1__C");
__FAR__ const CT__xdc_runtime_Main_Module__loggerFxn1 xdc_runtime_Main_Module__loggerFxn1__C = ((CT__xdc_runtime_Main_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(xdc_runtime_Main_Module__loggerFxn2__C, ".const:xdc_runtime_Main_Module__loggerFxn2__C");
__FAR__ const CT__xdc_runtime_Main_Module__loggerFxn2 xdc_runtime_Main_Module__loggerFxn2__C = ((CT__xdc_runtime_Main_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(xdc_runtime_Main_Module__loggerFxn4__C, ".const:xdc_runtime_Main_Module__loggerFxn4__C");
__FAR__ const CT__xdc_runtime_Main_Module__loggerFxn4 xdc_runtime_Main_Module__loggerFxn4__C = ((CT__xdc_runtime_Main_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(xdc_runtime_Main_Module__loggerFxn8__C, ".const:xdc_runtime_Main_Module__loggerFxn8__C");
__FAR__ const CT__xdc_runtime_Main_Module__loggerFxn8 xdc_runtime_Main_Module__loggerFxn8__C = ((CT__xdc_runtime_Main_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(xdc_runtime_Main_Module__startupDoneFxn__C, ".const:xdc_runtime_Main_Module__startupDoneFxn__C");
__FAR__ const CT__xdc_runtime_Main_Module__startupDoneFxn xdc_runtime_Main_Module__startupDoneFxn__C = ((CT__xdc_runtime_Main_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(xdc_runtime_Main_Object__count__C, ".const:xdc_runtime_Main_Object__count__C");
__FAR__ const CT__xdc_runtime_Main_Object__count xdc_runtime_Main_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(xdc_runtime_Main_Object__heap__C, ".const:xdc_runtime_Main_Object__heap__C");
__FAR__ const CT__xdc_runtime_Main_Object__heap xdc_runtime_Main_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(xdc_runtime_Main_Object__sizeof__C, ".const:xdc_runtime_Main_Object__sizeof__C");
__FAR__ const CT__xdc_runtime_Main_Object__sizeof xdc_runtime_Main_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(xdc_runtime_Main_Object__table__C, ".const:xdc_runtime_Main_Object__table__C");
__FAR__ const CT__xdc_runtime_Main_Object__table xdc_runtime_Main_Object__table__C = 0;


/*
 * ======== xdc.runtime.Main_Module_GateProxy INITIALIZERS ========
 */


/*
 * ======== xdc.runtime.Memory INITIALIZERS ========
 */

/* Module__state__V */
#if defined (__ICCARM__)
#pragma location = ".data_xdc_runtime_Memory_Module__state__V"
#endif
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
#ifndef __TI_COMPILER_VERSION__
xdc_runtime_Memory_Module_State__ xdc_runtime_Memory_Module__state__V __attribute__ ((section(".data_xdc_runtime_Memory_Module__state__V")));
#endif
#endif
xdc_runtime_Memory_Module_State__ xdc_runtime_Memory_Module__state__V = {
    (xdc_SizeT)0x8,  /* maxDefaultTypeAlign */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(xdc_runtime_Memory_Module__diagsEnabled__C, ".const:xdc_runtime_Memory_Module__diagsEnabled__C");
__FAR__ const CT__xdc_runtime_Memory_Module__diagsEnabled xdc_runtime_Memory_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(xdc_runtime_Memory_Module__diagsIncluded__C, ".const:xdc_runtime_Memory_Module__diagsIncluded__C");
__FAR__ const CT__xdc_runtime_Memory_Module__diagsIncluded xdc_runtime_Memory_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
#pragma DATA_SECTION(xdc_runtime_Memory_Module__diagsMask__C, ".const:xdc_runtime_Memory_Module__diagsMask__C");
__FAR__ const CT__xdc_runtime_Memory_Module__diagsMask xdc_runtime_Memory_Module__diagsMask__C = ((CT__xdc_runtime_Memory_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(xdc_runtime_Memory_Module__gateObj__C, ".const:xdc_runtime_Memory_Module__gateObj__C");
__FAR__ const CT__xdc_runtime_Memory_Module__gateObj xdc_runtime_Memory_Module__gateObj__C = ((CT__xdc_runtime_Memory_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(xdc_runtime_Memory_Module__gatePrms__C, ".const:xdc_runtime_Memory_Module__gatePrms__C");
__FAR__ const CT__xdc_runtime_Memory_Module__gatePrms xdc_runtime_Memory_Module__gatePrms__C = ((CT__xdc_runtime_Memory_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(xdc_runtime_Memory_Module__id__C, ".const:xdc_runtime_Memory_Module__id__C");
__FAR__ const CT__xdc_runtime_Memory_Module__id xdc_runtime_Memory_Module__id__C = (xdc_Bits16)0x800a;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(xdc_runtime_Memory_Module__loggerDefined__C, ".const:xdc_runtime_Memory_Module__loggerDefined__C");
__FAR__ const CT__xdc_runtime_Memory_Module__loggerDefined xdc_runtime_Memory_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(xdc_runtime_Memory_Module__loggerObj__C, ".const:xdc_runtime_Memory_Module__loggerObj__C");
__FAR__ const CT__xdc_runtime_Memory_Module__loggerObj xdc_runtime_Memory_Module__loggerObj__C = ((CT__xdc_runtime_Memory_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(xdc_runtime_Memory_Module__loggerFxn0__C, ".const:xdc_runtime_Memory_Module__loggerFxn0__C");
__FAR__ const CT__xdc_runtime_Memory_Module__loggerFxn0 xdc_runtime_Memory_Module__loggerFxn0__C = ((CT__xdc_runtime_Memory_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(xdc_runtime_Memory_Module__loggerFxn1__C, ".const:xdc_runtime_Memory_Module__loggerFxn1__C");
__FAR__ const CT__xdc_runtime_Memory_Module__loggerFxn1 xdc_runtime_Memory_Module__loggerFxn1__C = ((CT__xdc_runtime_Memory_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(xdc_runtime_Memory_Module__loggerFxn2__C, ".const:xdc_runtime_Memory_Module__loggerFxn2__C");
__FAR__ const CT__xdc_runtime_Memory_Module__loggerFxn2 xdc_runtime_Memory_Module__loggerFxn2__C = ((CT__xdc_runtime_Memory_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(xdc_runtime_Memory_Module__loggerFxn4__C, ".const:xdc_runtime_Memory_Module__loggerFxn4__C");
__FAR__ const CT__xdc_runtime_Memory_Module__loggerFxn4 xdc_runtime_Memory_Module__loggerFxn4__C = ((CT__xdc_runtime_Memory_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(xdc_runtime_Memory_Module__loggerFxn8__C, ".const:xdc_runtime_Memory_Module__loggerFxn8__C");
__FAR__ const CT__xdc_runtime_Memory_Module__loggerFxn8 xdc_runtime_Memory_Module__loggerFxn8__C = ((CT__xdc_runtime_Memory_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(xdc_runtime_Memory_Module__startupDoneFxn__C, ".const:xdc_runtime_Memory_Module__startupDoneFxn__C");
__FAR__ const CT__xdc_runtime_Memory_Module__startupDoneFxn xdc_runtime_Memory_Module__startupDoneFxn__C = ((CT__xdc_runtime_Memory_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(xdc_runtime_Memory_Object__count__C, ".const:xdc_runtime_Memory_Object__count__C");
__FAR__ const CT__xdc_runtime_Memory_Object__count xdc_runtime_Memory_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(xdc_runtime_Memory_Object__heap__C, ".const:xdc_runtime_Memory_Object__heap__C");
__FAR__ const CT__xdc_runtime_Memory_Object__heap xdc_runtime_Memory_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(xdc_runtime_Memory_Object__sizeof__C, ".const:xdc_runtime_Memory_Object__sizeof__C");
__FAR__ const CT__xdc_runtime_Memory_Object__sizeof xdc_runtime_Memory_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(xdc_runtime_Memory_Object__table__C, ".const:xdc_runtime_Memory_Object__table__C");
__FAR__ const CT__xdc_runtime_Memory_Object__table xdc_runtime_Memory_Object__table__C = 0;

/* defaultHeapInstance__C */
#pragma DATA_SECTION(xdc_runtime_Memory_defaultHeapInstance__C, ".const:xdc_runtime_Memory_defaultHeapInstance__C");
__FAR__ const CT__xdc_runtime_Memory_defaultHeapInstance xdc_runtime_Memory_defaultHeapInstance__C = (xdc_runtime_IHeap_Handle)&ti_sysbios_heaps_HeapMem_Object__table__V[0];


/*
 * ======== xdc.runtime.Memory_HeapProxy INITIALIZERS ========
 */


/*
 * ======== xdc.runtime.Registry INITIALIZERS ========
 */

/* Module__state__V */
#if defined (__ICCARM__)
#pragma location = ".data_xdc_runtime_Registry_Module__state__V"
#endif
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
#ifndef __TI_COMPILER_VERSION__
xdc_runtime_Registry_Module_State__ xdc_runtime_Registry_Module__state__V __attribute__ ((section(".data_xdc_runtime_Registry_Module__state__V")));
#endif
#endif
xdc_runtime_Registry_Module_State__ xdc_runtime_Registry_Module__state__V = {
    ((xdc_runtime_Types_RegDesc*)0),  /* listHead */
    (xdc_Bits16)0x7fff,  /* curId */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(xdc_runtime_Registry_Module__diagsEnabled__C, ".const:xdc_runtime_Registry_Module__diagsEnabled__C");
__FAR__ const CT__xdc_runtime_Registry_Module__diagsEnabled xdc_runtime_Registry_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(xdc_runtime_Registry_Module__diagsIncluded__C, ".const:xdc_runtime_Registry_Module__diagsIncluded__C");
__FAR__ const CT__xdc_runtime_Registry_Module__diagsIncluded xdc_runtime_Registry_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(xdc_runtime_Registry_Module__diagsMask__C, ".const:xdc_runtime_Registry_Module__diagsMask__C");
__FAR__ const CT__xdc_runtime_Registry_Module__diagsMask xdc_runtime_Registry_Module__diagsMask__C = ((CT__xdc_runtime_Registry_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(xdc_runtime_Registry_Module__gateObj__C, ".const:xdc_runtime_Registry_Module__gateObj__C");
__FAR__ const CT__xdc_runtime_Registry_Module__gateObj xdc_runtime_Registry_Module__gateObj__C = ((CT__xdc_runtime_Registry_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(xdc_runtime_Registry_Module__gatePrms__C, ".const:xdc_runtime_Registry_Module__gatePrms__C");
__FAR__ const CT__xdc_runtime_Registry_Module__gatePrms xdc_runtime_Registry_Module__gatePrms__C = ((CT__xdc_runtime_Registry_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(xdc_runtime_Registry_Module__id__C, ".const:xdc_runtime_Registry_Module__id__C");
__FAR__ const CT__xdc_runtime_Registry_Module__id xdc_runtime_Registry_Module__id__C = (xdc_Bits16)0x800b;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(xdc_runtime_Registry_Module__loggerDefined__C, ".const:xdc_runtime_Registry_Module__loggerDefined__C");
__FAR__ const CT__xdc_runtime_Registry_Module__loggerDefined xdc_runtime_Registry_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(xdc_runtime_Registry_Module__loggerObj__C, ".const:xdc_runtime_Registry_Module__loggerObj__C");
__FAR__ const CT__xdc_runtime_Registry_Module__loggerObj xdc_runtime_Registry_Module__loggerObj__C = ((CT__xdc_runtime_Registry_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(xdc_runtime_Registry_Module__loggerFxn0__C, ".const:xdc_runtime_Registry_Module__loggerFxn0__C");
__FAR__ const CT__xdc_runtime_Registry_Module__loggerFxn0 xdc_runtime_Registry_Module__loggerFxn0__C = ((CT__xdc_runtime_Registry_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(xdc_runtime_Registry_Module__loggerFxn1__C, ".const:xdc_runtime_Registry_Module__loggerFxn1__C");
__FAR__ const CT__xdc_runtime_Registry_Module__loggerFxn1 xdc_runtime_Registry_Module__loggerFxn1__C = ((CT__xdc_runtime_Registry_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(xdc_runtime_Registry_Module__loggerFxn2__C, ".const:xdc_runtime_Registry_Module__loggerFxn2__C");
__FAR__ const CT__xdc_runtime_Registry_Module__loggerFxn2 xdc_runtime_Registry_Module__loggerFxn2__C = ((CT__xdc_runtime_Registry_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(xdc_runtime_Registry_Module__loggerFxn4__C, ".const:xdc_runtime_Registry_Module__loggerFxn4__C");
__FAR__ const CT__xdc_runtime_Registry_Module__loggerFxn4 xdc_runtime_Registry_Module__loggerFxn4__C = ((CT__xdc_runtime_Registry_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(xdc_runtime_Registry_Module__loggerFxn8__C, ".const:xdc_runtime_Registry_Module__loggerFxn8__C");
__FAR__ const CT__xdc_runtime_Registry_Module__loggerFxn8 xdc_runtime_Registry_Module__loggerFxn8__C = ((CT__xdc_runtime_Registry_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(xdc_runtime_Registry_Module__startupDoneFxn__C, ".const:xdc_runtime_Registry_Module__startupDoneFxn__C");
__FAR__ const CT__xdc_runtime_Registry_Module__startupDoneFxn xdc_runtime_Registry_Module__startupDoneFxn__C = ((CT__xdc_runtime_Registry_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(xdc_runtime_Registry_Object__count__C, ".const:xdc_runtime_Registry_Object__count__C");
__FAR__ const CT__xdc_runtime_Registry_Object__count xdc_runtime_Registry_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(xdc_runtime_Registry_Object__heap__C, ".const:xdc_runtime_Registry_Object__heap__C");
__FAR__ const CT__xdc_runtime_Registry_Object__heap xdc_runtime_Registry_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(xdc_runtime_Registry_Object__sizeof__C, ".const:xdc_runtime_Registry_Object__sizeof__C");
__FAR__ const CT__xdc_runtime_Registry_Object__sizeof xdc_runtime_Registry_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(xdc_runtime_Registry_Object__table__C, ".const:xdc_runtime_Registry_Object__table__C");
__FAR__ const CT__xdc_runtime_Registry_Object__table xdc_runtime_Registry_Object__table__C = 0;


/*
 * ======== xdc.runtime.Startup INITIALIZERS ========
 */

/* Module__state__V */
#if defined (__ICCARM__)
#pragma location = ".data_xdc_runtime_Startup_Module__state__V"
#endif
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
#ifndef __TI_COMPILER_VERSION__
xdc_runtime_Startup_Module_State__ xdc_runtime_Startup_Module__state__V __attribute__ ((section(".data_xdc_runtime_Startup_Module__state__V")));
#endif
#endif
xdc_runtime_Startup_Module_State__ xdc_runtime_Startup_Module__state__V = {
    ((xdc_Int*)0),  /* stateTab */
    0,  /* execFlag */
    0,  /* rtsDoneFlag */
};

/* --> xdc_runtime_Startup_firstFxns__A */
#pragma DATA_SECTION(xdc_runtime_Startup_firstFxns__A, ".const:xdc_runtime_Startup_firstFxns__A");
const __T1_xdc_runtime_Startup_firstFxns xdc_runtime_Startup_firstFxns__A[3] = {
    ((xdc_Void(*)(xdc_Void))((xdc_Fxn)ti_sysbios_heaps_HeapMem_init__I)),  /* [0] */
    ((xdc_Void(*)(xdc_Void))((xdc_Fxn)ti_sysbios_family_shared_vayu_IntXbar_initIntXbar__I)),  /* [1] */
    ((xdc_Void(*)(xdc_Void))((xdc_Fxn)ti_sysbios_family_arm_m3_Hwi_initNVIC__E)),  /* [2] */
};

/* --> xdc_runtime_Startup_lastFxns__A */
#pragma DATA_SECTION(xdc_runtime_Startup_lastFxns__A, ".const:xdc_runtime_Startup_lastFxns__A");
const __T1_xdc_runtime_Startup_lastFxns xdc_runtime_Startup_lastFxns__A[1] = {
    ((xdc_Void(*)(xdc_Void))((xdc_Fxn)ti_sysbios_family_arm_ducati_Core_startCore1__I)),  /* [0] */
};

/* --> xdc_runtime_Startup_sfxnTab__A */
#pragma DATA_SECTION(xdc_runtime_Startup_sfxnTab__A, ".const:xdc_runtime_Startup_sfxnTab__A");
const __T1_xdc_runtime_Startup_sfxnTab xdc_runtime_Startup_sfxnTab__A[10] = {
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)xdc_runtime_System_Module_startup__E)),  /* [0] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)xdc_runtime_SysMin_Module_startup__E)),  /* [1] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_knl_Clock_Module_startup__E)),  /* [2] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_knl_Swi_Module_startup__E)),  /* [3] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_knl_Task_Module_startup__E)),  /* [4] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_hal_Hwi_Module_startup__E)),  /* [5] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_family_arm_m3_Hwi_Module_startup__E)),  /* [6] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_family_arm_ducati_Core_Module_startup__E)),  /* [7] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_family_arm_ducati_GateDualCore_Module_startup__E)),  /* [8] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_family_arm_ducati_Timer_Module_startup__E)),  /* [9] */
};

/* --> xdc_runtime_Startup_sfxnRts__A */
#pragma DATA_SECTION(xdc_runtime_Startup_sfxnRts__A, ".const:xdc_runtime_Startup_sfxnRts__A");
const __T1_xdc_runtime_Startup_sfxnRts xdc_runtime_Startup_sfxnRts__A[10] = {
    1,  /* [0] */
    1,  /* [1] */
    0,  /* [2] */
    0,  /* [3] */
    0,  /* [4] */
    0,  /* [5] */
    0,  /* [6] */
    0,  /* [7] */
    1,  /* [8] */
    0,  /* [9] */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(xdc_runtime_Startup_Module__diagsEnabled__C, ".const:xdc_runtime_Startup_Module__diagsEnabled__C");
__FAR__ const CT__xdc_runtime_Startup_Module__diagsEnabled xdc_runtime_Startup_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(xdc_runtime_Startup_Module__diagsIncluded__C, ".const:xdc_runtime_Startup_Module__diagsIncluded__C");
__FAR__ const CT__xdc_runtime_Startup_Module__diagsIncluded xdc_runtime_Startup_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
#pragma DATA_SECTION(xdc_runtime_Startup_Module__diagsMask__C, ".const:xdc_runtime_Startup_Module__diagsMask__C");
__FAR__ const CT__xdc_runtime_Startup_Module__diagsMask xdc_runtime_Startup_Module__diagsMask__C = ((CT__xdc_runtime_Startup_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(xdc_runtime_Startup_Module__gateObj__C, ".const:xdc_runtime_Startup_Module__gateObj__C");
__FAR__ const CT__xdc_runtime_Startup_Module__gateObj xdc_runtime_Startup_Module__gateObj__C = ((CT__xdc_runtime_Startup_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(xdc_runtime_Startup_Module__gatePrms__C, ".const:xdc_runtime_Startup_Module__gatePrms__C");
__FAR__ const CT__xdc_runtime_Startup_Module__gatePrms xdc_runtime_Startup_Module__gatePrms__C = ((CT__xdc_runtime_Startup_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(xdc_runtime_Startup_Module__id__C, ".const:xdc_runtime_Startup_Module__id__C");
__FAR__ const CT__xdc_runtime_Startup_Module__id xdc_runtime_Startup_Module__id__C = (xdc_Bits16)0x800c;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(xdc_runtime_Startup_Module__loggerDefined__C, ".const:xdc_runtime_Startup_Module__loggerDefined__C");
__FAR__ const CT__xdc_runtime_Startup_Module__loggerDefined xdc_runtime_Startup_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(xdc_runtime_Startup_Module__loggerObj__C, ".const:xdc_runtime_Startup_Module__loggerObj__C");
__FAR__ const CT__xdc_runtime_Startup_Module__loggerObj xdc_runtime_Startup_Module__loggerObj__C = ((CT__xdc_runtime_Startup_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(xdc_runtime_Startup_Module__loggerFxn0__C, ".const:xdc_runtime_Startup_Module__loggerFxn0__C");
__FAR__ const CT__xdc_runtime_Startup_Module__loggerFxn0 xdc_runtime_Startup_Module__loggerFxn0__C = ((CT__xdc_runtime_Startup_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(xdc_runtime_Startup_Module__loggerFxn1__C, ".const:xdc_runtime_Startup_Module__loggerFxn1__C");
__FAR__ const CT__xdc_runtime_Startup_Module__loggerFxn1 xdc_runtime_Startup_Module__loggerFxn1__C = ((CT__xdc_runtime_Startup_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(xdc_runtime_Startup_Module__loggerFxn2__C, ".const:xdc_runtime_Startup_Module__loggerFxn2__C");
__FAR__ const CT__xdc_runtime_Startup_Module__loggerFxn2 xdc_runtime_Startup_Module__loggerFxn2__C = ((CT__xdc_runtime_Startup_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(xdc_runtime_Startup_Module__loggerFxn4__C, ".const:xdc_runtime_Startup_Module__loggerFxn4__C");
__FAR__ const CT__xdc_runtime_Startup_Module__loggerFxn4 xdc_runtime_Startup_Module__loggerFxn4__C = ((CT__xdc_runtime_Startup_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(xdc_runtime_Startup_Module__loggerFxn8__C, ".const:xdc_runtime_Startup_Module__loggerFxn8__C");
__FAR__ const CT__xdc_runtime_Startup_Module__loggerFxn8 xdc_runtime_Startup_Module__loggerFxn8__C = ((CT__xdc_runtime_Startup_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(xdc_runtime_Startup_Module__startupDoneFxn__C, ".const:xdc_runtime_Startup_Module__startupDoneFxn__C");
__FAR__ const CT__xdc_runtime_Startup_Module__startupDoneFxn xdc_runtime_Startup_Module__startupDoneFxn__C = ((CT__xdc_runtime_Startup_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(xdc_runtime_Startup_Object__count__C, ".const:xdc_runtime_Startup_Object__count__C");
__FAR__ const CT__xdc_runtime_Startup_Object__count xdc_runtime_Startup_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(xdc_runtime_Startup_Object__heap__C, ".const:xdc_runtime_Startup_Object__heap__C");
__FAR__ const CT__xdc_runtime_Startup_Object__heap xdc_runtime_Startup_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(xdc_runtime_Startup_Object__sizeof__C, ".const:xdc_runtime_Startup_Object__sizeof__C");
__FAR__ const CT__xdc_runtime_Startup_Object__sizeof xdc_runtime_Startup_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(xdc_runtime_Startup_Object__table__C, ".const:xdc_runtime_Startup_Object__table__C");
__FAR__ const CT__xdc_runtime_Startup_Object__table xdc_runtime_Startup_Object__table__C = 0;

/* maxPasses__C */
#pragma DATA_SECTION(xdc_runtime_Startup_maxPasses__C, ".const:xdc_runtime_Startup_maxPasses__C");
__FAR__ const CT__xdc_runtime_Startup_maxPasses xdc_runtime_Startup_maxPasses__C = (xdc_Int)0x20;

/* firstFxns__C */
#pragma DATA_SECTION(xdc_runtime_Startup_firstFxns__C, ".const:xdc_runtime_Startup_firstFxns__C");
__FAR__ const CT__xdc_runtime_Startup_firstFxns xdc_runtime_Startup_firstFxns__C = {3, ((__T1_xdc_runtime_Startup_firstFxns*)xdc_runtime_Startup_firstFxns__A)};

/* lastFxns__C */
#pragma DATA_SECTION(xdc_runtime_Startup_lastFxns__C, ".const:xdc_runtime_Startup_lastFxns__C");
__FAR__ const CT__xdc_runtime_Startup_lastFxns xdc_runtime_Startup_lastFxns__C = {1, ((__T1_xdc_runtime_Startup_lastFxns*)xdc_runtime_Startup_lastFxns__A)};

/* startModsFxn__C */
#pragma DATA_SECTION(xdc_runtime_Startup_startModsFxn__C, ".const:xdc_runtime_Startup_startModsFxn__C");
__FAR__ const CT__xdc_runtime_Startup_startModsFxn xdc_runtime_Startup_startModsFxn__C = ((CT__xdc_runtime_Startup_startModsFxn)((xdc_Fxn)xdc_runtime_Startup_startMods__I));

/* execImpl__C */
#pragma DATA_SECTION(xdc_runtime_Startup_execImpl__C, ".const:xdc_runtime_Startup_execImpl__C");
__FAR__ const CT__xdc_runtime_Startup_execImpl xdc_runtime_Startup_execImpl__C = ((CT__xdc_runtime_Startup_execImpl)((xdc_Fxn)xdc_runtime_Startup_exec__I));

/* sfxnTab__C */
#pragma DATA_SECTION(xdc_runtime_Startup_sfxnTab__C, ".const:xdc_runtime_Startup_sfxnTab__C");
__FAR__ const CT__xdc_runtime_Startup_sfxnTab xdc_runtime_Startup_sfxnTab__C = ((CT__xdc_runtime_Startup_sfxnTab)xdc_runtime_Startup_sfxnTab__A);

/* sfxnRts__C */
#pragma DATA_SECTION(xdc_runtime_Startup_sfxnRts__C, ".const:xdc_runtime_Startup_sfxnRts__C");
__FAR__ const CT__xdc_runtime_Startup_sfxnRts xdc_runtime_Startup_sfxnRts__C = ((CT__xdc_runtime_Startup_sfxnRts)xdc_runtime_Startup_sfxnRts__A);


/*
 * ======== xdc.runtime.SysMin INITIALIZERS ========
 */

/* --> xdc_runtime_SysMin_Module_State_0_outbuf__A */
__T1_xdc_runtime_SysMin_Module_State__outbuf xdc_runtime_SysMin_Module_State_0_outbuf__A[1024];

/* Module__state__V */
#if defined (__ICCARM__)
#pragma location = ".data_xdc_runtime_SysMin_Module__state__V"
#endif
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
#ifndef __TI_COMPILER_VERSION__
xdc_runtime_SysMin_Module_State__ xdc_runtime_SysMin_Module__state__V __attribute__ ((section(".data_xdc_runtime_SysMin_Module__state__V")));
#endif
#endif
xdc_runtime_SysMin_Module_State__ xdc_runtime_SysMin_Module__state__V = {
    ((void*)xdc_runtime_SysMin_Module_State_0_outbuf__A),  /* outbuf */
    (xdc_UInt)0x0,  /* outidx */
    0,  /* wrapped */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__diagsEnabled__C, ".const:xdc_runtime_SysMin_Module__diagsEnabled__C");
__FAR__ const CT__xdc_runtime_SysMin_Module__diagsEnabled xdc_runtime_SysMin_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__diagsIncluded__C, ".const:xdc_runtime_SysMin_Module__diagsIncluded__C");
__FAR__ const CT__xdc_runtime_SysMin_Module__diagsIncluded xdc_runtime_SysMin_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__diagsMask__C, ".const:xdc_runtime_SysMin_Module__diagsMask__C");
__FAR__ const CT__xdc_runtime_SysMin_Module__diagsMask xdc_runtime_SysMin_Module__diagsMask__C = ((CT__xdc_runtime_SysMin_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__gateObj__C, ".const:xdc_runtime_SysMin_Module__gateObj__C");
__FAR__ const CT__xdc_runtime_SysMin_Module__gateObj xdc_runtime_SysMin_Module__gateObj__C = ((CT__xdc_runtime_SysMin_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__gatePrms__C, ".const:xdc_runtime_SysMin_Module__gatePrms__C");
__FAR__ const CT__xdc_runtime_SysMin_Module__gatePrms xdc_runtime_SysMin_Module__gatePrms__C = ((CT__xdc_runtime_SysMin_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__id__C, ".const:xdc_runtime_SysMin_Module__id__C");
__FAR__ const CT__xdc_runtime_SysMin_Module__id xdc_runtime_SysMin_Module__id__C = (xdc_Bits16)0x800e;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__loggerDefined__C, ".const:xdc_runtime_SysMin_Module__loggerDefined__C");
__FAR__ const CT__xdc_runtime_SysMin_Module__loggerDefined xdc_runtime_SysMin_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__loggerObj__C, ".const:xdc_runtime_SysMin_Module__loggerObj__C");
__FAR__ const CT__xdc_runtime_SysMin_Module__loggerObj xdc_runtime_SysMin_Module__loggerObj__C = ((CT__xdc_runtime_SysMin_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__loggerFxn0__C, ".const:xdc_runtime_SysMin_Module__loggerFxn0__C");
__FAR__ const CT__xdc_runtime_SysMin_Module__loggerFxn0 xdc_runtime_SysMin_Module__loggerFxn0__C = ((CT__xdc_runtime_SysMin_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__loggerFxn1__C, ".const:xdc_runtime_SysMin_Module__loggerFxn1__C");
__FAR__ const CT__xdc_runtime_SysMin_Module__loggerFxn1 xdc_runtime_SysMin_Module__loggerFxn1__C = ((CT__xdc_runtime_SysMin_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__loggerFxn2__C, ".const:xdc_runtime_SysMin_Module__loggerFxn2__C");
__FAR__ const CT__xdc_runtime_SysMin_Module__loggerFxn2 xdc_runtime_SysMin_Module__loggerFxn2__C = ((CT__xdc_runtime_SysMin_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__loggerFxn4__C, ".const:xdc_runtime_SysMin_Module__loggerFxn4__C");
__FAR__ const CT__xdc_runtime_SysMin_Module__loggerFxn4 xdc_runtime_SysMin_Module__loggerFxn4__C = ((CT__xdc_runtime_SysMin_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__loggerFxn8__C, ".const:xdc_runtime_SysMin_Module__loggerFxn8__C");
__FAR__ const CT__xdc_runtime_SysMin_Module__loggerFxn8 xdc_runtime_SysMin_Module__loggerFxn8__C = ((CT__xdc_runtime_SysMin_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__startupDoneFxn__C, ".const:xdc_runtime_SysMin_Module__startupDoneFxn__C");
__FAR__ const CT__xdc_runtime_SysMin_Module__startupDoneFxn xdc_runtime_SysMin_Module__startupDoneFxn__C = ((CT__xdc_runtime_SysMin_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_Object__count__C, ".const:xdc_runtime_SysMin_Object__count__C");
__FAR__ const CT__xdc_runtime_SysMin_Object__count xdc_runtime_SysMin_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_Object__heap__C, ".const:xdc_runtime_SysMin_Object__heap__C");
__FAR__ const CT__xdc_runtime_SysMin_Object__heap xdc_runtime_SysMin_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_Object__sizeof__C, ".const:xdc_runtime_SysMin_Object__sizeof__C");
__FAR__ const CT__xdc_runtime_SysMin_Object__sizeof xdc_runtime_SysMin_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_Object__table__C, ".const:xdc_runtime_SysMin_Object__table__C");
__FAR__ const CT__xdc_runtime_SysMin_Object__table xdc_runtime_SysMin_Object__table__C = 0;

/* bufSize__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_bufSize__C, ".const:xdc_runtime_SysMin_bufSize__C");
__FAR__ const CT__xdc_runtime_SysMin_bufSize xdc_runtime_SysMin_bufSize__C = (xdc_SizeT)0x400;

/* flushAtExit__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_flushAtExit__C, ".const:xdc_runtime_SysMin_flushAtExit__C");
__FAR__ const CT__xdc_runtime_SysMin_flushAtExit xdc_runtime_SysMin_flushAtExit__C = 1;

/* outputFxn__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_outputFxn__C, ".const:xdc_runtime_SysMin_outputFxn__C");
__FAR__ const CT__xdc_runtime_SysMin_outputFxn xdc_runtime_SysMin_outputFxn__C = ((CT__xdc_runtime_SysMin_outputFxn)0);

/* outputFunc__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_outputFunc__C, ".const:xdc_runtime_SysMin_outputFunc__C");
__FAR__ const CT__xdc_runtime_SysMin_outputFunc xdc_runtime_SysMin_outputFunc__C = ((CT__xdc_runtime_SysMin_outputFunc)((xdc_Fxn)xdc_runtime_SysMin_output__I));


/*
 * ======== xdc.runtime.System INITIALIZERS ========
 */

/* --> xdc_runtime_System_Module_State_0_atexitHandlers__A */
__T1_xdc_runtime_System_Module_State__atexitHandlers xdc_runtime_System_Module_State_0_atexitHandlers__A[8] = {
    ((xdc_Void(*)(xdc_Int))0),  /* [0] */
    ((xdc_Void(*)(xdc_Int))0),  /* [1] */
    ((xdc_Void(*)(xdc_Int))0),  /* [2] */
    ((xdc_Void(*)(xdc_Int))0),  /* [3] */
    ((xdc_Void(*)(xdc_Int))0),  /* [4] */
    ((xdc_Void(*)(xdc_Int))0),  /* [5] */
    ((xdc_Void(*)(xdc_Int))0),  /* [6] */
    ((xdc_Void(*)(xdc_Int))0),  /* [7] */
};

/* Module__state__V */
#if defined (__ICCARM__)
#pragma location = ".data_xdc_runtime_System_Module__state__V"
#endif
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
#ifndef __TI_COMPILER_VERSION__
xdc_runtime_System_Module_State__ xdc_runtime_System_Module__state__V __attribute__ ((section(".data_xdc_runtime_System_Module__state__V")));
#endif
#endif
xdc_runtime_System_Module_State__ xdc_runtime_System_Module__state__V = {
    ((void*)xdc_runtime_System_Module_State_0_atexitHandlers__A),  /* atexitHandlers */
    (xdc_Int)0x0,  /* numAtexitHandlers */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(xdc_runtime_System_Module__diagsEnabled__C, ".const:xdc_runtime_System_Module__diagsEnabled__C");
__FAR__ const CT__xdc_runtime_System_Module__diagsEnabled xdc_runtime_System_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(xdc_runtime_System_Module__diagsIncluded__C, ".const:xdc_runtime_System_Module__diagsIncluded__C");
__FAR__ const CT__xdc_runtime_System_Module__diagsIncluded xdc_runtime_System_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
#pragma DATA_SECTION(xdc_runtime_System_Module__diagsMask__C, ".const:xdc_runtime_System_Module__diagsMask__C");
__FAR__ const CT__xdc_runtime_System_Module__diagsMask xdc_runtime_System_Module__diagsMask__C = ((CT__xdc_runtime_System_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(xdc_runtime_System_Module__gateObj__C, ".const:xdc_runtime_System_Module__gateObj__C");
__FAR__ const CT__xdc_runtime_System_Module__gateObj xdc_runtime_System_Module__gateObj__C = ((CT__xdc_runtime_System_Module__gateObj)((void*)(xdc_runtime_IGateProvider_Handle)&ti_sysbios_gates_GateHwi_Object__table__V[0]));

/* Module__gatePrms__C */
#pragma DATA_SECTION(xdc_runtime_System_Module__gatePrms__C, ".const:xdc_runtime_System_Module__gatePrms__C");
__FAR__ const CT__xdc_runtime_System_Module__gatePrms xdc_runtime_System_Module__gatePrms__C = ((CT__xdc_runtime_System_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(xdc_runtime_System_Module__id__C, ".const:xdc_runtime_System_Module__id__C");
__FAR__ const CT__xdc_runtime_System_Module__id xdc_runtime_System_Module__id__C = (xdc_Bits16)0x800d;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(xdc_runtime_System_Module__loggerDefined__C, ".const:xdc_runtime_System_Module__loggerDefined__C");
__FAR__ const CT__xdc_runtime_System_Module__loggerDefined xdc_runtime_System_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(xdc_runtime_System_Module__loggerObj__C, ".const:xdc_runtime_System_Module__loggerObj__C");
__FAR__ const CT__xdc_runtime_System_Module__loggerObj xdc_runtime_System_Module__loggerObj__C = ((CT__xdc_runtime_System_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(xdc_runtime_System_Module__loggerFxn0__C, ".const:xdc_runtime_System_Module__loggerFxn0__C");
__FAR__ const CT__xdc_runtime_System_Module__loggerFxn0 xdc_runtime_System_Module__loggerFxn0__C = ((CT__xdc_runtime_System_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(xdc_runtime_System_Module__loggerFxn1__C, ".const:xdc_runtime_System_Module__loggerFxn1__C");
__FAR__ const CT__xdc_runtime_System_Module__loggerFxn1 xdc_runtime_System_Module__loggerFxn1__C = ((CT__xdc_runtime_System_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(xdc_runtime_System_Module__loggerFxn2__C, ".const:xdc_runtime_System_Module__loggerFxn2__C");
__FAR__ const CT__xdc_runtime_System_Module__loggerFxn2 xdc_runtime_System_Module__loggerFxn2__C = ((CT__xdc_runtime_System_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(xdc_runtime_System_Module__loggerFxn4__C, ".const:xdc_runtime_System_Module__loggerFxn4__C");
__FAR__ const CT__xdc_runtime_System_Module__loggerFxn4 xdc_runtime_System_Module__loggerFxn4__C = ((CT__xdc_runtime_System_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(xdc_runtime_System_Module__loggerFxn8__C, ".const:xdc_runtime_System_Module__loggerFxn8__C");
__FAR__ const CT__xdc_runtime_System_Module__loggerFxn8 xdc_runtime_System_Module__loggerFxn8__C = ((CT__xdc_runtime_System_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(xdc_runtime_System_Module__startupDoneFxn__C, ".const:xdc_runtime_System_Module__startupDoneFxn__C");
__FAR__ const CT__xdc_runtime_System_Module__startupDoneFxn xdc_runtime_System_Module__startupDoneFxn__C = ((CT__xdc_runtime_System_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(xdc_runtime_System_Object__count__C, ".const:xdc_runtime_System_Object__count__C");
__FAR__ const CT__xdc_runtime_System_Object__count xdc_runtime_System_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(xdc_runtime_System_Object__heap__C, ".const:xdc_runtime_System_Object__heap__C");
__FAR__ const CT__xdc_runtime_System_Object__heap xdc_runtime_System_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(xdc_runtime_System_Object__sizeof__C, ".const:xdc_runtime_System_Object__sizeof__C");
__FAR__ const CT__xdc_runtime_System_Object__sizeof xdc_runtime_System_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(xdc_runtime_System_Object__table__C, ".const:xdc_runtime_System_Object__table__C");
__FAR__ const CT__xdc_runtime_System_Object__table xdc_runtime_System_Object__table__C = 0;

/* A_cannotFitIntoArg__C */
#pragma DATA_SECTION(xdc_runtime_System_A_cannotFitIntoArg__C, ".const:xdc_runtime_System_A_cannotFitIntoArg__C");
__FAR__ const CT__xdc_runtime_System_A_cannotFitIntoArg xdc_runtime_System_A_cannotFitIntoArg__C = (((xdc_runtime_Assert_Id)352) << 16 | 16);

/* maxAtexitHandlers__C */
#pragma DATA_SECTION(xdc_runtime_System_maxAtexitHandlers__C, ".const:xdc_runtime_System_maxAtexitHandlers__C");
__FAR__ const CT__xdc_runtime_System_maxAtexitHandlers xdc_runtime_System_maxAtexitHandlers__C = (xdc_Int)0x8;

/* abortFxn__C */
#pragma DATA_SECTION(xdc_runtime_System_abortFxn__C, ".const:xdc_runtime_System_abortFxn__C");
__FAR__ const CT__xdc_runtime_System_abortFxn xdc_runtime_System_abortFxn__C = ((CT__xdc_runtime_System_abortFxn)((xdc_Fxn)xdc_runtime_System_abortStd__E));

/* exitFxn__C */
#pragma DATA_SECTION(xdc_runtime_System_exitFxn__C, ".const:xdc_runtime_System_exitFxn__C");
__FAR__ const CT__xdc_runtime_System_exitFxn xdc_runtime_System_exitFxn__C = ((CT__xdc_runtime_System_exitFxn)((xdc_Fxn)xdc_runtime_System_exitStd__E));

/* extendFxn__C */
#pragma DATA_SECTION(xdc_runtime_System_extendFxn__C, ".const:xdc_runtime_System_extendFxn__C");
__FAR__ const CT__xdc_runtime_System_extendFxn xdc_runtime_System_extendFxn__C = ((CT__xdc_runtime_System_extendFxn)((xdc_Fxn)xdc_runtime_System_printfExtend__I));


/*
 * ======== xdc.runtime.System_Module_GateProxy INITIALIZERS ========
 */


/*
 * ======== xdc.runtime.System_SupportProxy INITIALIZERS ========
 */


/*
 * ======== xdc.runtime.Text INITIALIZERS ========
 */

/* Module__state__V */
#if defined (__ICCARM__)
#pragma location = ".data_xdc_runtime_Text_Module__state__V"
#endif
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
#ifndef __TI_COMPILER_VERSION__
xdc_runtime_Text_Module_State__ xdc_runtime_Text_Module__state__V __attribute__ ((section(".data_xdc_runtime_Text_Module__state__V")));
#endif
#endif
xdc_runtime_Text_Module_State__ xdc_runtime_Text_Module__state__V = {
    ((xdc_CPtr)(&xdc_runtime_Text_charTab__A[0])),  /* charBase */
    ((xdc_CPtr)(&xdc_runtime_Text_nodeTab__A[0])),  /* nodeBase */
};

/* --> xdc_runtime_Text_charTab__A */
#pragma DATA_SECTION(xdc_runtime_Text_charTab__A, ".const:xdc_runtime_Text_charTab__A");
const __T1_xdc_runtime_Text_charTab xdc_runtime_Text_charTab__A[7150] = {
    (xdc_Char)0x0,  /* [0] */
    (xdc_Char)0x41,  /* [1] */
    (xdc_Char)0x5f,  /* [2] */
    (xdc_Char)0x69,  /* [3] */
    (xdc_Char)0x6e,  /* [4] */
    (xdc_Char)0x69,  /* [5] */
    (xdc_Char)0x74,  /* [6] */
    (xdc_Char)0x69,  /* [7] */
    (xdc_Char)0x61,  /* [8] */
    (xdc_Char)0x6c,  /* [9] */
    (xdc_Char)0x69,  /* [10] */
    (xdc_Char)0x7a,  /* [11] */
    (xdc_Char)0x65,  /* [12] */
    (xdc_Char)0x64,  /* [13] */
    (xdc_Char)0x50,  /* [14] */
    (xdc_Char)0x61,  /* [15] */
    (xdc_Char)0x72,  /* [16] */
    (xdc_Char)0x61,  /* [17] */
    (xdc_Char)0x6d,  /* [18] */
    (xdc_Char)0x73,  /* [19] */
    (xdc_Char)0x3a,  /* [20] */
    (xdc_Char)0x20,  /* [21] */
    (xdc_Char)0x75,  /* [22] */
    (xdc_Char)0x6e,  /* [23] */
    (xdc_Char)0x69,  /* [24] */
    (xdc_Char)0x6e,  /* [25] */
    (xdc_Char)0x69,  /* [26] */
    (xdc_Char)0x74,  /* [27] */
    (xdc_Char)0x69,  /* [28] */
    (xdc_Char)0x61,  /* [29] */
    (xdc_Char)0x6c,  /* [30] */
    (xdc_Char)0x69,  /* [31] */
    (xdc_Char)0x7a,  /* [32] */
    (xdc_Char)0x65,  /* [33] */
    (xdc_Char)0x64,  /* [34] */
    (xdc_Char)0x20,  /* [35] */
    (xdc_Char)0x50,  /* [36] */
    (xdc_Char)0x61,  /* [37] */
    (xdc_Char)0x72,  /* [38] */
    (xdc_Char)0x61,  /* [39] */
    (xdc_Char)0x6d,  /* [40] */
    (xdc_Char)0x73,  /* [41] */
    (xdc_Char)0x20,  /* [42] */
    (xdc_Char)0x73,  /* [43] */
    (xdc_Char)0x74,  /* [44] */
    (xdc_Char)0x72,  /* [45] */
    (xdc_Char)0x75,  /* [46] */
    (xdc_Char)0x63,  /* [47] */
    (xdc_Char)0x74,  /* [48] */
    (xdc_Char)0x0,  /* [49] */
    (xdc_Char)0x48,  /* [50] */
    (xdc_Char)0x65,  /* [51] */
    (xdc_Char)0x61,  /* [52] */
    (xdc_Char)0x70,  /* [53] */
    (xdc_Char)0x4d,  /* [54] */
    (xdc_Char)0x69,  /* [55] */
    (xdc_Char)0x6e,  /* [56] */
    (xdc_Char)0x5f,  /* [57] */
    (xdc_Char)0x63,  /* [58] */
    (xdc_Char)0x72,  /* [59] */
    (xdc_Char)0x65,  /* [60] */
    (xdc_Char)0x61,  /* [61] */
    (xdc_Char)0x74,  /* [62] */
    (xdc_Char)0x65,  /* [63] */
    (xdc_Char)0x20,  /* [64] */
    (xdc_Char)0x63,  /* [65] */
    (xdc_Char)0x61,  /* [66] */
    (xdc_Char)0x6e,  /* [67] */
    (xdc_Char)0x6e,  /* [68] */
    (xdc_Char)0x6f,  /* [69] */
    (xdc_Char)0x74,  /* [70] */
    (xdc_Char)0x20,  /* [71] */
    (xdc_Char)0x68,  /* [72] */
    (xdc_Char)0x61,  /* [73] */
    (xdc_Char)0x76,  /* [74] */
    (xdc_Char)0x65,  /* [75] */
    (xdc_Char)0x20,  /* [76] */
    (xdc_Char)0x61,  /* [77] */
    (xdc_Char)0x20,  /* [78] */
    (xdc_Char)0x7a,  /* [79] */
    (xdc_Char)0x65,  /* [80] */
    (xdc_Char)0x72,  /* [81] */
    (xdc_Char)0x6f,  /* [82] */
    (xdc_Char)0x20,  /* [83] */
    (xdc_Char)0x73,  /* [84] */
    (xdc_Char)0x69,  /* [85] */
    (xdc_Char)0x7a,  /* [86] */
    (xdc_Char)0x65,  /* [87] */
    (xdc_Char)0x20,  /* [88] */
    (xdc_Char)0x76,  /* [89] */
    (xdc_Char)0x61,  /* [90] */
    (xdc_Char)0x6c,  /* [91] */
    (xdc_Char)0x75,  /* [92] */
    (xdc_Char)0x65,  /* [93] */
    (xdc_Char)0x0,  /* [94] */
    (xdc_Char)0x48,  /* [95] */
    (xdc_Char)0x65,  /* [96] */
    (xdc_Char)0x61,  /* [97] */
    (xdc_Char)0x70,  /* [98] */
    (xdc_Char)0x53,  /* [99] */
    (xdc_Char)0x74,  /* [100] */
    (xdc_Char)0x64,  /* [101] */
    (xdc_Char)0x5f,  /* [102] */
    (xdc_Char)0x63,  /* [103] */
    (xdc_Char)0x72,  /* [104] */
    (xdc_Char)0x65,  /* [105] */
    (xdc_Char)0x61,  /* [106] */
    (xdc_Char)0x74,  /* [107] */
    (xdc_Char)0x65,  /* [108] */
    (xdc_Char)0x20,  /* [109] */
    (xdc_Char)0x63,  /* [110] */
    (xdc_Char)0x61,  /* [111] */
    (xdc_Char)0x6e,  /* [112] */
    (xdc_Char)0x6e,  /* [113] */
    (xdc_Char)0x6f,  /* [114] */
    (xdc_Char)0x74,  /* [115] */
    (xdc_Char)0x20,  /* [116] */
    (xdc_Char)0x68,  /* [117] */
    (xdc_Char)0x61,  /* [118] */
    (xdc_Char)0x76,  /* [119] */
    (xdc_Char)0x65,  /* [120] */
    (xdc_Char)0x20,  /* [121] */
    (xdc_Char)0x61,  /* [122] */
    (xdc_Char)0x20,  /* [123] */
    (xdc_Char)0x7a,  /* [124] */
    (xdc_Char)0x65,  /* [125] */
    (xdc_Char)0x72,  /* [126] */
    (xdc_Char)0x6f,  /* [127] */
    (xdc_Char)0x20,  /* [128] */
    (xdc_Char)0x73,  /* [129] */
    (xdc_Char)0x69,  /* [130] */
    (xdc_Char)0x7a,  /* [131] */
    (xdc_Char)0x65,  /* [132] */
    (xdc_Char)0x20,  /* [133] */
    (xdc_Char)0x76,  /* [134] */
    (xdc_Char)0x61,  /* [135] */
    (xdc_Char)0x6c,  /* [136] */
    (xdc_Char)0x75,  /* [137] */
    (xdc_Char)0x65,  /* [138] */
    (xdc_Char)0x0,  /* [139] */
    (xdc_Char)0x48,  /* [140] */
    (xdc_Char)0x65,  /* [141] */
    (xdc_Char)0x61,  /* [142] */
    (xdc_Char)0x70,  /* [143] */
    (xdc_Char)0x53,  /* [144] */
    (xdc_Char)0x74,  /* [145] */
    (xdc_Char)0x64,  /* [146] */
    (xdc_Char)0x5f,  /* [147] */
    (xdc_Char)0x61,  /* [148] */
    (xdc_Char)0x6c,  /* [149] */
    (xdc_Char)0x6c,  /* [150] */
    (xdc_Char)0x6f,  /* [151] */
    (xdc_Char)0x63,  /* [152] */
    (xdc_Char)0x20,  /* [153] */
    (xdc_Char)0x61,  /* [154] */
    (xdc_Char)0x6c,  /* [155] */
    (xdc_Char)0x69,  /* [156] */
    (xdc_Char)0x67,  /* [157] */
    (xdc_Char)0x6e,  /* [158] */
    (xdc_Char)0x6d,  /* [159] */
    (xdc_Char)0x65,  /* [160] */
    (xdc_Char)0x6e,  /* [161] */
    (xdc_Char)0x74,  /* [162] */
    (xdc_Char)0x20,  /* [163] */
    (xdc_Char)0x6d,  /* [164] */
    (xdc_Char)0x75,  /* [165] */
    (xdc_Char)0x73,  /* [166] */
    (xdc_Char)0x74,  /* [167] */
    (xdc_Char)0x20,  /* [168] */
    (xdc_Char)0x62,  /* [169] */
    (xdc_Char)0x65,  /* [170] */
    (xdc_Char)0x20,  /* [171] */
    (xdc_Char)0x61,  /* [172] */
    (xdc_Char)0x20,  /* [173] */
    (xdc_Char)0x70,  /* [174] */
    (xdc_Char)0x6f,  /* [175] */
    (xdc_Char)0x77,  /* [176] */
    (xdc_Char)0x65,  /* [177] */
    (xdc_Char)0x72,  /* [178] */
    (xdc_Char)0x20,  /* [179] */
    (xdc_Char)0x6f,  /* [180] */
    (xdc_Char)0x66,  /* [181] */
    (xdc_Char)0x20,  /* [182] */
    (xdc_Char)0x32,  /* [183] */
    (xdc_Char)0x0,  /* [184] */
    (xdc_Char)0x48,  /* [185] */
    (xdc_Char)0x65,  /* [186] */
    (xdc_Char)0x61,  /* [187] */
    (xdc_Char)0x70,  /* [188] */
    (xdc_Char)0x53,  /* [189] */
    (xdc_Char)0x74,  /* [190] */
    (xdc_Char)0x64,  /* [191] */
    (xdc_Char)0x20,  /* [192] */
    (xdc_Char)0x69,  /* [193] */
    (xdc_Char)0x6e,  /* [194] */
    (xdc_Char)0x73,  /* [195] */
    (xdc_Char)0x74,  /* [196] */
    (xdc_Char)0x61,  /* [197] */
    (xdc_Char)0x6e,  /* [198] */
    (xdc_Char)0x63,  /* [199] */
    (xdc_Char)0x65,  /* [200] */
    (xdc_Char)0x20,  /* [201] */
    (xdc_Char)0x74,  /* [202] */
    (xdc_Char)0x6f,  /* [203] */
    (xdc_Char)0x74,  /* [204] */
    (xdc_Char)0x61,  /* [205] */
    (xdc_Char)0x6c,  /* [206] */
    (xdc_Char)0x46,  /* [207] */
    (xdc_Char)0x72,  /* [208] */
    (xdc_Char)0x65,  /* [209] */
    (xdc_Char)0x65,  /* [210] */
    (xdc_Char)0x53,  /* [211] */
    (xdc_Char)0x69,  /* [212] */
    (xdc_Char)0x7a,  /* [213] */
    (xdc_Char)0x65,  /* [214] */
    (xdc_Char)0x20,  /* [215] */
    (xdc_Char)0x69,  /* [216] */
    (xdc_Char)0x73,  /* [217] */
    (xdc_Char)0x20,  /* [218] */
    (xdc_Char)0x67,  /* [219] */
    (xdc_Char)0x72,  /* [220] */
    (xdc_Char)0x65,  /* [221] */
    (xdc_Char)0x61,  /* [222] */
    (xdc_Char)0x74,  /* [223] */
    (xdc_Char)0x65,  /* [224] */
    (xdc_Char)0x72,  /* [225] */
    (xdc_Char)0x20,  /* [226] */
    (xdc_Char)0x74,  /* [227] */
    (xdc_Char)0x68,  /* [228] */
    (xdc_Char)0x61,  /* [229] */
    (xdc_Char)0x6e,  /* [230] */
    (xdc_Char)0x20,  /* [231] */
    (xdc_Char)0x73,  /* [232] */
    (xdc_Char)0x74,  /* [233] */
    (xdc_Char)0x61,  /* [234] */
    (xdc_Char)0x72,  /* [235] */
    (xdc_Char)0x74,  /* [236] */
    (xdc_Char)0x69,  /* [237] */
    (xdc_Char)0x6e,  /* [238] */
    (xdc_Char)0x67,  /* [239] */
    (xdc_Char)0x20,  /* [240] */
    (xdc_Char)0x73,  /* [241] */
    (xdc_Char)0x69,  /* [242] */
    (xdc_Char)0x7a,  /* [243] */
    (xdc_Char)0x65,  /* [244] */
    (xdc_Char)0x0,  /* [245] */
    (xdc_Char)0x48,  /* [246] */
    (xdc_Char)0x65,  /* [247] */
    (xdc_Char)0x61,  /* [248] */
    (xdc_Char)0x70,  /* [249] */
    (xdc_Char)0x53,  /* [250] */
    (xdc_Char)0x74,  /* [251] */
    (xdc_Char)0x64,  /* [252] */
    (xdc_Char)0x5f,  /* [253] */
    (xdc_Char)0x61,  /* [254] */
    (xdc_Char)0x6c,  /* [255] */
    (xdc_Char)0x6c,  /* [256] */
    (xdc_Char)0x6f,  /* [257] */
    (xdc_Char)0x63,  /* [258] */
    (xdc_Char)0x20,  /* [259] */
    (xdc_Char)0x2d,  /* [260] */
    (xdc_Char)0x20,  /* [261] */
    (xdc_Char)0x72,  /* [262] */
    (xdc_Char)0x65,  /* [263] */
    (xdc_Char)0x71,  /* [264] */
    (xdc_Char)0x75,  /* [265] */
    (xdc_Char)0x65,  /* [266] */
    (xdc_Char)0x73,  /* [267] */
    (xdc_Char)0x74,  /* [268] */
    (xdc_Char)0x65,  /* [269] */
    (xdc_Char)0x64,  /* [270] */
    (xdc_Char)0x20,  /* [271] */
    (xdc_Char)0x61,  /* [272] */
    (xdc_Char)0x6c,  /* [273] */
    (xdc_Char)0x69,  /* [274] */
    (xdc_Char)0x67,  /* [275] */
    (xdc_Char)0x6e,  /* [276] */
    (xdc_Char)0x6d,  /* [277] */
    (xdc_Char)0x65,  /* [278] */
    (xdc_Char)0x6e,  /* [279] */
    (xdc_Char)0x74,  /* [280] */
    (xdc_Char)0x20,  /* [281] */
    (xdc_Char)0x69,  /* [282] */
    (xdc_Char)0x73,  /* [283] */
    (xdc_Char)0x20,  /* [284] */
    (xdc_Char)0x67,  /* [285] */
    (xdc_Char)0x72,  /* [286] */
    (xdc_Char)0x65,  /* [287] */
    (xdc_Char)0x61,  /* [288] */
    (xdc_Char)0x74,  /* [289] */
    (xdc_Char)0x65,  /* [290] */
    (xdc_Char)0x72,  /* [291] */
    (xdc_Char)0x20,  /* [292] */
    (xdc_Char)0x74,  /* [293] */
    (xdc_Char)0x68,  /* [294] */
    (xdc_Char)0x61,  /* [295] */
    (xdc_Char)0x6e,  /* [296] */
    (xdc_Char)0x20,  /* [297] */
    (xdc_Char)0x61,  /* [298] */
    (xdc_Char)0x6c,  /* [299] */
    (xdc_Char)0x6c,  /* [300] */
    (xdc_Char)0x6f,  /* [301] */
    (xdc_Char)0x77,  /* [302] */
    (xdc_Char)0x65,  /* [303] */
    (xdc_Char)0x64,  /* [304] */
    (xdc_Char)0x0,  /* [305] */
    (xdc_Char)0x41,  /* [306] */
    (xdc_Char)0x5f,  /* [307] */
    (xdc_Char)0x69,  /* [308] */
    (xdc_Char)0x6e,  /* [309] */
    (xdc_Char)0x76,  /* [310] */
    (xdc_Char)0x61,  /* [311] */
    (xdc_Char)0x6c,  /* [312] */
    (xdc_Char)0x69,  /* [313] */
    (xdc_Char)0x64,  /* [314] */
    (xdc_Char)0x4c,  /* [315] */
    (xdc_Char)0x6f,  /* [316] */
    (xdc_Char)0x67,  /* [317] */
    (xdc_Char)0x67,  /* [318] */
    (xdc_Char)0x65,  /* [319] */
    (xdc_Char)0x72,  /* [320] */
    (xdc_Char)0x3a,  /* [321] */
    (xdc_Char)0x20,  /* [322] */
    (xdc_Char)0x54,  /* [323] */
    (xdc_Char)0x68,  /* [324] */
    (xdc_Char)0x65,  /* [325] */
    (xdc_Char)0x20,  /* [326] */
    (xdc_Char)0x6c,  /* [327] */
    (xdc_Char)0x6f,  /* [328] */
    (xdc_Char)0x67,  /* [329] */
    (xdc_Char)0x67,  /* [330] */
    (xdc_Char)0x65,  /* [331] */
    (xdc_Char)0x72,  /* [332] */
    (xdc_Char)0x20,  /* [333] */
    (xdc_Char)0x69,  /* [334] */
    (xdc_Char)0x64,  /* [335] */
    (xdc_Char)0x20,  /* [336] */
    (xdc_Char)0x25,  /* [337] */
    (xdc_Char)0x64,  /* [338] */
    (xdc_Char)0x20,  /* [339] */
    (xdc_Char)0x69,  /* [340] */
    (xdc_Char)0x73,  /* [341] */
    (xdc_Char)0x20,  /* [342] */
    (xdc_Char)0x69,  /* [343] */
    (xdc_Char)0x6e,  /* [344] */
    (xdc_Char)0x76,  /* [345] */
    (xdc_Char)0x61,  /* [346] */
    (xdc_Char)0x6c,  /* [347] */
    (xdc_Char)0x69,  /* [348] */
    (xdc_Char)0x64,  /* [349] */
    (xdc_Char)0x2e,  /* [350] */
    (xdc_Char)0x0,  /* [351] */
    (xdc_Char)0x41,  /* [352] */
    (xdc_Char)0x5f,  /* [353] */
    (xdc_Char)0x63,  /* [354] */
    (xdc_Char)0x61,  /* [355] */
    (xdc_Char)0x6e,  /* [356] */
    (xdc_Char)0x6e,  /* [357] */
    (xdc_Char)0x6f,  /* [358] */
    (xdc_Char)0x74,  /* [359] */
    (xdc_Char)0x46,  /* [360] */
    (xdc_Char)0x69,  /* [361] */
    (xdc_Char)0x74,  /* [362] */
    (xdc_Char)0x49,  /* [363] */
    (xdc_Char)0x6e,  /* [364] */
    (xdc_Char)0x74,  /* [365] */
    (xdc_Char)0x6f,  /* [366] */
    (xdc_Char)0x41,  /* [367] */
    (xdc_Char)0x72,  /* [368] */
    (xdc_Char)0x67,  /* [369] */
    (xdc_Char)0x3a,  /* [370] */
    (xdc_Char)0x20,  /* [371] */
    (xdc_Char)0x73,  /* [372] */
    (xdc_Char)0x69,  /* [373] */
    (xdc_Char)0x7a,  /* [374] */
    (xdc_Char)0x65,  /* [375] */
    (xdc_Char)0x6f,  /* [376] */
    (xdc_Char)0x66,  /* [377] */
    (xdc_Char)0x28,  /* [378] */
    (xdc_Char)0x46,  /* [379] */
    (xdc_Char)0x6c,  /* [380] */
    (xdc_Char)0x6f,  /* [381] */
    (xdc_Char)0x61,  /* [382] */
    (xdc_Char)0x74,  /* [383] */
    (xdc_Char)0x29,  /* [384] */
    (xdc_Char)0x20,  /* [385] */
    (xdc_Char)0x3e,  /* [386] */
    (xdc_Char)0x20,  /* [387] */
    (xdc_Char)0x73,  /* [388] */
    (xdc_Char)0x69,  /* [389] */
    (xdc_Char)0x7a,  /* [390] */
    (xdc_Char)0x65,  /* [391] */
    (xdc_Char)0x6f,  /* [392] */
    (xdc_Char)0x66,  /* [393] */
    (xdc_Char)0x28,  /* [394] */
    (xdc_Char)0x41,  /* [395] */
    (xdc_Char)0x72,  /* [396] */
    (xdc_Char)0x67,  /* [397] */
    (xdc_Char)0x29,  /* [398] */
    (xdc_Char)0x0,  /* [399] */
    (xdc_Char)0x41,  /* [400] */
    (xdc_Char)0x5f,  /* [401] */
    (xdc_Char)0x6e,  /* [402] */
    (xdc_Char)0x75,  /* [403] */
    (xdc_Char)0x6c,  /* [404] */
    (xdc_Char)0x6c,  /* [405] */
    (xdc_Char)0x50,  /* [406] */
    (xdc_Char)0x6f,  /* [407] */
    (xdc_Char)0x69,  /* [408] */
    (xdc_Char)0x6e,  /* [409] */
    (xdc_Char)0x74,  /* [410] */
    (xdc_Char)0x65,  /* [411] */
    (xdc_Char)0x72,  /* [412] */
    (xdc_Char)0x3a,  /* [413] */
    (xdc_Char)0x20,  /* [414] */
    (xdc_Char)0x50,  /* [415] */
    (xdc_Char)0x6f,  /* [416] */
    (xdc_Char)0x69,  /* [417] */
    (xdc_Char)0x6e,  /* [418] */
    (xdc_Char)0x74,  /* [419] */
    (xdc_Char)0x65,  /* [420] */
    (xdc_Char)0x72,  /* [421] */
    (xdc_Char)0x20,  /* [422] */
    (xdc_Char)0x69,  /* [423] */
    (xdc_Char)0x73,  /* [424] */
    (xdc_Char)0x20,  /* [425] */
    (xdc_Char)0x6e,  /* [426] */
    (xdc_Char)0x75,  /* [427] */
    (xdc_Char)0x6c,  /* [428] */
    (xdc_Char)0x6c,  /* [429] */
    (xdc_Char)0x0,  /* [430] */
    (xdc_Char)0x41,  /* [431] */
    (xdc_Char)0x5f,  /* [432] */
    (xdc_Char)0x69,  /* [433] */
    (xdc_Char)0x6e,  /* [434] */
    (xdc_Char)0x76,  /* [435] */
    (xdc_Char)0x61,  /* [436] */
    (xdc_Char)0x6c,  /* [437] */
    (xdc_Char)0x69,  /* [438] */
    (xdc_Char)0x64,  /* [439] */
    (xdc_Char)0x52,  /* [440] */
    (xdc_Char)0x65,  /* [441] */
    (xdc_Char)0x67,  /* [442] */
    (xdc_Char)0x69,  /* [443] */
    (xdc_Char)0x6f,  /* [444] */
    (xdc_Char)0x6e,  /* [445] */
    (xdc_Char)0x49,  /* [446] */
    (xdc_Char)0x64,  /* [447] */
    (xdc_Char)0x3a,  /* [448] */
    (xdc_Char)0x20,  /* [449] */
    (xdc_Char)0x4d,  /* [450] */
    (xdc_Char)0x50,  /* [451] */
    (xdc_Char)0x55,  /* [452] */
    (xdc_Char)0x20,  /* [453] */
    (xdc_Char)0x52,  /* [454] */
    (xdc_Char)0x65,  /* [455] */
    (xdc_Char)0x67,  /* [456] */
    (xdc_Char)0x69,  /* [457] */
    (xdc_Char)0x6f,  /* [458] */
    (xdc_Char)0x6e,  /* [459] */
    (xdc_Char)0x20,  /* [460] */
    (xdc_Char)0x6e,  /* [461] */
    (xdc_Char)0x75,  /* [462] */
    (xdc_Char)0x6d,  /* [463] */
    (xdc_Char)0x62,  /* [464] */
    (xdc_Char)0x65,  /* [465] */
    (xdc_Char)0x72,  /* [466] */
    (xdc_Char)0x20,  /* [467] */
    (xdc_Char)0x70,  /* [468] */
    (xdc_Char)0x61,  /* [469] */
    (xdc_Char)0x73,  /* [470] */
    (xdc_Char)0x73,  /* [471] */
    (xdc_Char)0x65,  /* [472] */
    (xdc_Char)0x64,  /* [473] */
    (xdc_Char)0x20,  /* [474] */
    (xdc_Char)0x69,  /* [475] */
    (xdc_Char)0x73,  /* [476] */
    (xdc_Char)0x20,  /* [477] */
    (xdc_Char)0x69,  /* [478] */
    (xdc_Char)0x6e,  /* [479] */
    (xdc_Char)0x76,  /* [480] */
    (xdc_Char)0x61,  /* [481] */
    (xdc_Char)0x6c,  /* [482] */
    (xdc_Char)0x69,  /* [483] */
    (xdc_Char)0x64,  /* [484] */
    (xdc_Char)0x2e,  /* [485] */
    (xdc_Char)0x0,  /* [486] */
    (xdc_Char)0x41,  /* [487] */
    (xdc_Char)0x5f,  /* [488] */
    (xdc_Char)0x75,  /* [489] */
    (xdc_Char)0x6e,  /* [490] */
    (xdc_Char)0x61,  /* [491] */
    (xdc_Char)0x6c,  /* [492] */
    (xdc_Char)0x69,  /* [493] */
    (xdc_Char)0x67,  /* [494] */
    (xdc_Char)0x6e,  /* [495] */
    (xdc_Char)0x65,  /* [496] */
    (xdc_Char)0x64,  /* [497] */
    (xdc_Char)0x42,  /* [498] */
    (xdc_Char)0x61,  /* [499] */
    (xdc_Char)0x73,  /* [500] */
    (xdc_Char)0x65,  /* [501] */
    (xdc_Char)0x41,  /* [502] */
    (xdc_Char)0x64,  /* [503] */
    (xdc_Char)0x64,  /* [504] */
    (xdc_Char)0x72,  /* [505] */
    (xdc_Char)0x3a,  /* [506] */
    (xdc_Char)0x20,  /* [507] */
    (xdc_Char)0x4d,  /* [508] */
    (xdc_Char)0x50,  /* [509] */
    (xdc_Char)0x55,  /* [510] */
    (xdc_Char)0x20,  /* [511] */
    (xdc_Char)0x72,  /* [512] */
    (xdc_Char)0x65,  /* [513] */
    (xdc_Char)0x67,  /* [514] */
    (xdc_Char)0x69,  /* [515] */
    (xdc_Char)0x6f,  /* [516] */
    (xdc_Char)0x6e,  /* [517] */
    (xdc_Char)0x20,  /* [518] */
    (xdc_Char)0x62,  /* [519] */
    (xdc_Char)0x61,  /* [520] */
    (xdc_Char)0x73,  /* [521] */
    (xdc_Char)0x65,  /* [522] */
    (xdc_Char)0x20,  /* [523] */
    (xdc_Char)0x61,  /* [524] */
    (xdc_Char)0x64,  /* [525] */
    (xdc_Char)0x64,  /* [526] */
    (xdc_Char)0x72,  /* [527] */
    (xdc_Char)0x65,  /* [528] */
    (xdc_Char)0x73,  /* [529] */
    (xdc_Char)0x73,  /* [530] */
    (xdc_Char)0x20,  /* [531] */
    (xdc_Char)0x6e,  /* [532] */
    (xdc_Char)0x6f,  /* [533] */
    (xdc_Char)0x74,  /* [534] */
    (xdc_Char)0x20,  /* [535] */
    (xdc_Char)0x61,  /* [536] */
    (xdc_Char)0x6c,  /* [537] */
    (xdc_Char)0x69,  /* [538] */
    (xdc_Char)0x67,  /* [539] */
    (xdc_Char)0x6e,  /* [540] */
    (xdc_Char)0x65,  /* [541] */
    (xdc_Char)0x64,  /* [542] */
    (xdc_Char)0x20,  /* [543] */
    (xdc_Char)0x74,  /* [544] */
    (xdc_Char)0x6f,  /* [545] */
    (xdc_Char)0x20,  /* [546] */
    (xdc_Char)0x73,  /* [547] */
    (xdc_Char)0x69,  /* [548] */
    (xdc_Char)0x7a,  /* [549] */
    (xdc_Char)0x65,  /* [550] */
    (xdc_Char)0x2e,  /* [551] */
    (xdc_Char)0x0,  /* [552] */
    (xdc_Char)0x41,  /* [553] */
    (xdc_Char)0x5f,  /* [554] */
    (xdc_Char)0x63,  /* [555] */
    (xdc_Char)0x6c,  /* [556] */
    (xdc_Char)0x6f,  /* [557] */
    (xdc_Char)0x63,  /* [558] */
    (xdc_Char)0x6b,  /* [559] */
    (xdc_Char)0x44,  /* [560] */
    (xdc_Char)0x69,  /* [561] */
    (xdc_Char)0x73,  /* [562] */
    (xdc_Char)0x61,  /* [563] */
    (xdc_Char)0x62,  /* [564] */
    (xdc_Char)0x6c,  /* [565] */
    (xdc_Char)0x65,  /* [566] */
    (xdc_Char)0x64,  /* [567] */
    (xdc_Char)0x3a,  /* [568] */
    (xdc_Char)0x20,  /* [569] */
    (xdc_Char)0x43,  /* [570] */
    (xdc_Char)0x61,  /* [571] */
    (xdc_Char)0x6e,  /* [572] */
    (xdc_Char)0x6e,  /* [573] */
    (xdc_Char)0x6f,  /* [574] */
    (xdc_Char)0x74,  /* [575] */
    (xdc_Char)0x20,  /* [576] */
    (xdc_Char)0x63,  /* [577] */
    (xdc_Char)0x72,  /* [578] */
    (xdc_Char)0x65,  /* [579] */
    (xdc_Char)0x61,  /* [580] */
    (xdc_Char)0x74,  /* [581] */
    (xdc_Char)0x65,  /* [582] */
    (xdc_Char)0x20,  /* [583] */
    (xdc_Char)0x61,  /* [584] */
    (xdc_Char)0x20,  /* [585] */
    (xdc_Char)0x63,  /* [586] */
    (xdc_Char)0x6c,  /* [587] */
    (xdc_Char)0x6f,  /* [588] */
    (xdc_Char)0x63,  /* [589] */
    (xdc_Char)0x6b,  /* [590] */
    (xdc_Char)0x20,  /* [591] */
    (xdc_Char)0x69,  /* [592] */
    (xdc_Char)0x6e,  /* [593] */
    (xdc_Char)0x73,  /* [594] */
    (xdc_Char)0x74,  /* [595] */
    (xdc_Char)0x61,  /* [596] */
    (xdc_Char)0x6e,  /* [597] */
    (xdc_Char)0x63,  /* [598] */
    (xdc_Char)0x65,  /* [599] */
    (xdc_Char)0x20,  /* [600] */
    (xdc_Char)0x77,  /* [601] */
    (xdc_Char)0x68,  /* [602] */
    (xdc_Char)0x65,  /* [603] */
    (xdc_Char)0x6e,  /* [604] */
    (xdc_Char)0x20,  /* [605] */
    (xdc_Char)0x42,  /* [606] */
    (xdc_Char)0x49,  /* [607] */
    (xdc_Char)0x4f,  /* [608] */
    (xdc_Char)0x53,  /* [609] */
    (xdc_Char)0x2e,  /* [610] */
    (xdc_Char)0x63,  /* [611] */
    (xdc_Char)0x6c,  /* [612] */
    (xdc_Char)0x6f,  /* [613] */
    (xdc_Char)0x63,  /* [614] */
    (xdc_Char)0x6b,  /* [615] */
    (xdc_Char)0x45,  /* [616] */
    (xdc_Char)0x6e,  /* [617] */
    (xdc_Char)0x61,  /* [618] */
    (xdc_Char)0x62,  /* [619] */
    (xdc_Char)0x6c,  /* [620] */
    (xdc_Char)0x65,  /* [621] */
    (xdc_Char)0x64,  /* [622] */
    (xdc_Char)0x20,  /* [623] */
    (xdc_Char)0x69,  /* [624] */
    (xdc_Char)0x73,  /* [625] */
    (xdc_Char)0x20,  /* [626] */
    (xdc_Char)0x66,  /* [627] */
    (xdc_Char)0x61,  /* [628] */
    (xdc_Char)0x6c,  /* [629] */
    (xdc_Char)0x73,  /* [630] */
    (xdc_Char)0x65,  /* [631] */
    (xdc_Char)0x2e,  /* [632] */
    (xdc_Char)0x0,  /* [633] */
    (xdc_Char)0x41,  /* [634] */
    (xdc_Char)0x5f,  /* [635] */
    (xdc_Char)0x62,  /* [636] */
    (xdc_Char)0x61,  /* [637] */
    (xdc_Char)0x64,  /* [638] */
    (xdc_Char)0x54,  /* [639] */
    (xdc_Char)0x68,  /* [640] */
    (xdc_Char)0x72,  /* [641] */
    (xdc_Char)0x65,  /* [642] */
    (xdc_Char)0x61,  /* [643] */
    (xdc_Char)0x64,  /* [644] */
    (xdc_Char)0x54,  /* [645] */
    (xdc_Char)0x79,  /* [646] */
    (xdc_Char)0x70,  /* [647] */
    (xdc_Char)0x65,  /* [648] */
    (xdc_Char)0x3a,  /* [649] */
    (xdc_Char)0x20,  /* [650] */
    (xdc_Char)0x43,  /* [651] */
    (xdc_Char)0x61,  /* [652] */
    (xdc_Char)0x6e,  /* [653] */
    (xdc_Char)0x6e,  /* [654] */
    (xdc_Char)0x6f,  /* [655] */
    (xdc_Char)0x74,  /* [656] */
    (xdc_Char)0x20,  /* [657] */
    (xdc_Char)0x63,  /* [658] */
    (xdc_Char)0x72,  /* [659] */
    (xdc_Char)0x65,  /* [660] */
    (xdc_Char)0x61,  /* [661] */
    (xdc_Char)0x74,  /* [662] */
    (xdc_Char)0x65,  /* [663] */
    (xdc_Char)0x2f,  /* [664] */
    (xdc_Char)0x64,  /* [665] */
    (xdc_Char)0x65,  /* [666] */
    (xdc_Char)0x6c,  /* [667] */
    (xdc_Char)0x65,  /* [668] */
    (xdc_Char)0x74,  /* [669] */
    (xdc_Char)0x65,  /* [670] */
    (xdc_Char)0x20,  /* [671] */
    (xdc_Char)0x61,  /* [672] */
    (xdc_Char)0x20,  /* [673] */
    (xdc_Char)0x43,  /* [674] */
    (xdc_Char)0x6c,  /* [675] */
    (xdc_Char)0x6f,  /* [676] */
    (xdc_Char)0x63,  /* [677] */
    (xdc_Char)0x6b,  /* [678] */
    (xdc_Char)0x20,  /* [679] */
    (xdc_Char)0x66,  /* [680] */
    (xdc_Char)0x72,  /* [681] */
    (xdc_Char)0x6f,  /* [682] */
    (xdc_Char)0x6d,  /* [683] */
    (xdc_Char)0x20,  /* [684] */
    (xdc_Char)0x48,  /* [685] */
    (xdc_Char)0x77,  /* [686] */
    (xdc_Char)0x69,  /* [687] */
    (xdc_Char)0x20,  /* [688] */
    (xdc_Char)0x6f,  /* [689] */
    (xdc_Char)0x72,  /* [690] */
    (xdc_Char)0x20,  /* [691] */
    (xdc_Char)0x53,  /* [692] */
    (xdc_Char)0x77,  /* [693] */
    (xdc_Char)0x69,  /* [694] */
    (xdc_Char)0x20,  /* [695] */
    (xdc_Char)0x74,  /* [696] */
    (xdc_Char)0x68,  /* [697] */
    (xdc_Char)0x72,  /* [698] */
    (xdc_Char)0x65,  /* [699] */
    (xdc_Char)0x61,  /* [700] */
    (xdc_Char)0x64,  /* [701] */
    (xdc_Char)0x2e,  /* [702] */
    (xdc_Char)0x0,  /* [703] */
    (xdc_Char)0x41,  /* [704] */
    (xdc_Char)0x5f,  /* [705] */
    (xdc_Char)0x6e,  /* [706] */
    (xdc_Char)0x75,  /* [707] */
    (xdc_Char)0x6c,  /* [708] */
    (xdc_Char)0x6c,  /* [709] */
    (xdc_Char)0x45,  /* [710] */
    (xdc_Char)0x76,  /* [711] */
    (xdc_Char)0x65,  /* [712] */
    (xdc_Char)0x6e,  /* [713] */
    (xdc_Char)0x74,  /* [714] */
    (xdc_Char)0x4d,  /* [715] */
    (xdc_Char)0x61,  /* [716] */
    (xdc_Char)0x73,  /* [717] */
    (xdc_Char)0x6b,  /* [718] */
    (xdc_Char)0x73,  /* [719] */
    (xdc_Char)0x3a,  /* [720] */
    (xdc_Char)0x20,  /* [721] */
    (xdc_Char)0x6f,  /* [722] */
    (xdc_Char)0x72,  /* [723] */
    (xdc_Char)0x4d,  /* [724] */
    (xdc_Char)0x61,  /* [725] */
    (xdc_Char)0x73,  /* [726] */
    (xdc_Char)0x6b,  /* [727] */
    (xdc_Char)0x20,  /* [728] */
    (xdc_Char)0x61,  /* [729] */
    (xdc_Char)0x6e,  /* [730] */
    (xdc_Char)0x64,  /* [731] */
    (xdc_Char)0x20,  /* [732] */
    (xdc_Char)0x61,  /* [733] */
    (xdc_Char)0x6e,  /* [734] */
    (xdc_Char)0x64,  /* [735] */
    (xdc_Char)0x4d,  /* [736] */
    (xdc_Char)0x61,  /* [737] */
    (xdc_Char)0x73,  /* [738] */
    (xdc_Char)0x6b,  /* [739] */
    (xdc_Char)0x20,  /* [740] */
    (xdc_Char)0x61,  /* [741] */
    (xdc_Char)0x72,  /* [742] */
    (xdc_Char)0x65,  /* [743] */
    (xdc_Char)0x20,  /* [744] */
    (xdc_Char)0x6e,  /* [745] */
    (xdc_Char)0x75,  /* [746] */
    (xdc_Char)0x6c,  /* [747] */
    (xdc_Char)0x6c,  /* [748] */
    (xdc_Char)0x2e,  /* [749] */
    (xdc_Char)0x0,  /* [750] */
    (xdc_Char)0x41,  /* [751] */
    (xdc_Char)0x5f,  /* [752] */
    (xdc_Char)0x6e,  /* [753] */
    (xdc_Char)0x75,  /* [754] */
    (xdc_Char)0x6c,  /* [755] */
    (xdc_Char)0x6c,  /* [756] */
    (xdc_Char)0x45,  /* [757] */
    (xdc_Char)0x76,  /* [758] */
    (xdc_Char)0x65,  /* [759] */
    (xdc_Char)0x6e,  /* [760] */
    (xdc_Char)0x74,  /* [761] */
    (xdc_Char)0x49,  /* [762] */
    (xdc_Char)0x64,  /* [763] */
    (xdc_Char)0x3a,  /* [764] */
    (xdc_Char)0x20,  /* [765] */
    (xdc_Char)0x70,  /* [766] */
    (xdc_Char)0x6f,  /* [767] */
    (xdc_Char)0x73,  /* [768] */
    (xdc_Char)0x74,  /* [769] */
    (xdc_Char)0x65,  /* [770] */
    (xdc_Char)0x64,  /* [771] */
    (xdc_Char)0x20,  /* [772] */
    (xdc_Char)0x65,  /* [773] */
    (xdc_Char)0x76,  /* [774] */
    (xdc_Char)0x65,  /* [775] */
    (xdc_Char)0x6e,  /* [776] */
    (xdc_Char)0x74,  /* [777] */
    (xdc_Char)0x49,  /* [778] */
    (xdc_Char)0x64,  /* [779] */
    (xdc_Char)0x20,  /* [780] */
    (xdc_Char)0x69,  /* [781] */
    (xdc_Char)0x73,  /* [782] */
    (xdc_Char)0x20,  /* [783] */
    (xdc_Char)0x6e,  /* [784] */
    (xdc_Char)0x75,  /* [785] */
    (xdc_Char)0x6c,  /* [786] */
    (xdc_Char)0x6c,  /* [787] */
    (xdc_Char)0x2e,  /* [788] */
    (xdc_Char)0x0,  /* [789] */
    (xdc_Char)0x41,  /* [790] */
    (xdc_Char)0x5f,  /* [791] */
    (xdc_Char)0x65,  /* [792] */
    (xdc_Char)0x76,  /* [793] */
    (xdc_Char)0x65,  /* [794] */
    (xdc_Char)0x6e,  /* [795] */
    (xdc_Char)0x74,  /* [796] */
    (xdc_Char)0x49,  /* [797] */
    (xdc_Char)0x6e,  /* [798] */
    (xdc_Char)0x55,  /* [799] */
    (xdc_Char)0x73,  /* [800] */
    (xdc_Char)0x65,  /* [801] */
    (xdc_Char)0x3a,  /* [802] */
    (xdc_Char)0x20,  /* [803] */
    (xdc_Char)0x45,  /* [804] */
    (xdc_Char)0x76,  /* [805] */
    (xdc_Char)0x65,  /* [806] */
    (xdc_Char)0x6e,  /* [807] */
    (xdc_Char)0x74,  /* [808] */
    (xdc_Char)0x20,  /* [809] */
    (xdc_Char)0x6f,  /* [810] */
    (xdc_Char)0x62,  /* [811] */
    (xdc_Char)0x6a,  /* [812] */
    (xdc_Char)0x65,  /* [813] */
    (xdc_Char)0x63,  /* [814] */
    (xdc_Char)0x74,  /* [815] */
    (xdc_Char)0x20,  /* [816] */
    (xdc_Char)0x61,  /* [817] */
    (xdc_Char)0x6c,  /* [818] */
    (xdc_Char)0x72,  /* [819] */
    (xdc_Char)0x65,  /* [820] */
    (xdc_Char)0x61,  /* [821] */
    (xdc_Char)0x64,  /* [822] */
    (xdc_Char)0x79,  /* [823] */
    (xdc_Char)0x20,  /* [824] */
    (xdc_Char)0x69,  /* [825] */
    (xdc_Char)0x6e,  /* [826] */
    (xdc_Char)0x20,  /* [827] */
    (xdc_Char)0x75,  /* [828] */
    (xdc_Char)0x73,  /* [829] */
    (xdc_Char)0x65,  /* [830] */
    (xdc_Char)0x2e,  /* [831] */
    (xdc_Char)0x0,  /* [832] */
    (xdc_Char)0x41,  /* [833] */
    (xdc_Char)0x5f,  /* [834] */
    (xdc_Char)0x62,  /* [835] */
    (xdc_Char)0x61,  /* [836] */
    (xdc_Char)0x64,  /* [837] */
    (xdc_Char)0x43,  /* [838] */
    (xdc_Char)0x6f,  /* [839] */
    (xdc_Char)0x6e,  /* [840] */
    (xdc_Char)0x74,  /* [841] */
    (xdc_Char)0x65,  /* [842] */
    (xdc_Char)0x78,  /* [843] */
    (xdc_Char)0x74,  /* [844] */
    (xdc_Char)0x3a,  /* [845] */
    (xdc_Char)0x20,  /* [846] */
    (xdc_Char)0x62,  /* [847] */
    (xdc_Char)0x61,  /* [848] */
    (xdc_Char)0x64,  /* [849] */
    (xdc_Char)0x20,  /* [850] */
    (xdc_Char)0x63,  /* [851] */
    (xdc_Char)0x61,  /* [852] */
    (xdc_Char)0x6c,  /* [853] */
    (xdc_Char)0x6c,  /* [854] */
    (xdc_Char)0x69,  /* [855] */
    (xdc_Char)0x6e,  /* [856] */
    (xdc_Char)0x67,  /* [857] */
    (xdc_Char)0x20,  /* [858] */
    (xdc_Char)0x63,  /* [859] */
    (xdc_Char)0x6f,  /* [860] */
    (xdc_Char)0x6e,  /* [861] */
    (xdc_Char)0x74,  /* [862] */
    (xdc_Char)0x65,  /* [863] */
    (xdc_Char)0x78,  /* [864] */
    (xdc_Char)0x74,  /* [865] */
    (xdc_Char)0x2e,  /* [866] */
    (xdc_Char)0x20,  /* [867] */
    (xdc_Char)0x4d,  /* [868] */
    (xdc_Char)0x75,  /* [869] */
    (xdc_Char)0x73,  /* [870] */
    (xdc_Char)0x74,  /* [871] */
    (xdc_Char)0x20,  /* [872] */
    (xdc_Char)0x62,  /* [873] */
    (xdc_Char)0x65,  /* [874] */
    (xdc_Char)0x20,  /* [875] */
    (xdc_Char)0x63,  /* [876] */
    (xdc_Char)0x61,  /* [877] */
    (xdc_Char)0x6c,  /* [878] */
    (xdc_Char)0x6c,  /* [879] */
    (xdc_Char)0x65,  /* [880] */
    (xdc_Char)0x64,  /* [881] */
    (xdc_Char)0x20,  /* [882] */
    (xdc_Char)0x66,  /* [883] */
    (xdc_Char)0x72,  /* [884] */
    (xdc_Char)0x6f,  /* [885] */
    (xdc_Char)0x6d,  /* [886] */
    (xdc_Char)0x20,  /* [887] */
    (xdc_Char)0x61,  /* [888] */
    (xdc_Char)0x20,  /* [889] */
    (xdc_Char)0x54,  /* [890] */
    (xdc_Char)0x61,  /* [891] */
    (xdc_Char)0x73,  /* [892] */
    (xdc_Char)0x6b,  /* [893] */
    (xdc_Char)0x2e,  /* [894] */
    (xdc_Char)0x0,  /* [895] */
    (xdc_Char)0x41,  /* [896] */
    (xdc_Char)0x5f,  /* [897] */
    (xdc_Char)0x70,  /* [898] */
    (xdc_Char)0x65,  /* [899] */
    (xdc_Char)0x6e,  /* [900] */
    (xdc_Char)0x64,  /* [901] */
    (xdc_Char)0x54,  /* [902] */
    (xdc_Char)0x61,  /* [903] */
    (xdc_Char)0x73,  /* [904] */
    (xdc_Char)0x6b,  /* [905] */
    (xdc_Char)0x44,  /* [906] */
    (xdc_Char)0x69,  /* [907] */
    (xdc_Char)0x73,  /* [908] */
    (xdc_Char)0x61,  /* [909] */
    (xdc_Char)0x62,  /* [910] */
    (xdc_Char)0x6c,  /* [911] */
    (xdc_Char)0x65,  /* [912] */
    (xdc_Char)0x64,  /* [913] */
    (xdc_Char)0x3a,  /* [914] */
    (xdc_Char)0x20,  /* [915] */
    (xdc_Char)0x43,  /* [916] */
    (xdc_Char)0x61,  /* [917] */
    (xdc_Char)0x6e,  /* [918] */
    (xdc_Char)0x6e,  /* [919] */
    (xdc_Char)0x6f,  /* [920] */
    (xdc_Char)0x74,  /* [921] */
    (xdc_Char)0x20,  /* [922] */
    (xdc_Char)0x63,  /* [923] */
    (xdc_Char)0x61,  /* [924] */
    (xdc_Char)0x6c,  /* [925] */
    (xdc_Char)0x6c,  /* [926] */
    (xdc_Char)0x20,  /* [927] */
    (xdc_Char)0x45,  /* [928] */
    (xdc_Char)0x76,  /* [929] */
    (xdc_Char)0x65,  /* [930] */
    (xdc_Char)0x6e,  /* [931] */
    (xdc_Char)0x74,  /* [932] */
    (xdc_Char)0x5f,  /* [933] */
    (xdc_Char)0x70,  /* [934] */
    (xdc_Char)0x65,  /* [935] */
    (xdc_Char)0x6e,  /* [936] */
    (xdc_Char)0x64,  /* [937] */
    (xdc_Char)0x28,  /* [938] */
    (xdc_Char)0x29,  /* [939] */
    (xdc_Char)0x20,  /* [940] */
    (xdc_Char)0x77,  /* [941] */
    (xdc_Char)0x68,  /* [942] */
    (xdc_Char)0x69,  /* [943] */
    (xdc_Char)0x6c,  /* [944] */
    (xdc_Char)0x65,  /* [945] */
    (xdc_Char)0x20,  /* [946] */
    (xdc_Char)0x74,  /* [947] */
    (xdc_Char)0x68,  /* [948] */
    (xdc_Char)0x65,  /* [949] */
    (xdc_Char)0x20,  /* [950] */
    (xdc_Char)0x54,  /* [951] */
    (xdc_Char)0x61,  /* [952] */
    (xdc_Char)0x73,  /* [953] */
    (xdc_Char)0x6b,  /* [954] */
    (xdc_Char)0x20,  /* [955] */
    (xdc_Char)0x6f,  /* [956] */
    (xdc_Char)0x72,  /* [957] */
    (xdc_Char)0x20,  /* [958] */
    (xdc_Char)0x53,  /* [959] */
    (xdc_Char)0x77,  /* [960] */
    (xdc_Char)0x69,  /* [961] */
    (xdc_Char)0x20,  /* [962] */
    (xdc_Char)0x73,  /* [963] */
    (xdc_Char)0x63,  /* [964] */
    (xdc_Char)0x68,  /* [965] */
    (xdc_Char)0x65,  /* [966] */
    (xdc_Char)0x64,  /* [967] */
    (xdc_Char)0x75,  /* [968] */
    (xdc_Char)0x6c,  /* [969] */
    (xdc_Char)0x65,  /* [970] */
    (xdc_Char)0x72,  /* [971] */
    (xdc_Char)0x20,  /* [972] */
    (xdc_Char)0x69,  /* [973] */
    (xdc_Char)0x73,  /* [974] */
    (xdc_Char)0x20,  /* [975] */
    (xdc_Char)0x64,  /* [976] */
    (xdc_Char)0x69,  /* [977] */
    (xdc_Char)0x73,  /* [978] */
    (xdc_Char)0x61,  /* [979] */
    (xdc_Char)0x62,  /* [980] */
    (xdc_Char)0x6c,  /* [981] */
    (xdc_Char)0x65,  /* [982] */
    (xdc_Char)0x64,  /* [983] */
    (xdc_Char)0x2e,  /* [984] */
    (xdc_Char)0x0,  /* [985] */
    (xdc_Char)0x4d,  /* [986] */
    (xdc_Char)0x61,  /* [987] */
    (xdc_Char)0x69,  /* [988] */
    (xdc_Char)0x6c,  /* [989] */
    (xdc_Char)0x62,  /* [990] */
    (xdc_Char)0x6f,  /* [991] */
    (xdc_Char)0x78,  /* [992] */
    (xdc_Char)0x5f,  /* [993] */
    (xdc_Char)0x63,  /* [994] */
    (xdc_Char)0x72,  /* [995] */
    (xdc_Char)0x65,  /* [996] */
    (xdc_Char)0x61,  /* [997] */
    (xdc_Char)0x74,  /* [998] */
    (xdc_Char)0x65,  /* [999] */
    (xdc_Char)0x27,  /* [1000] */
    (xdc_Char)0x73,  /* [1001] */
    (xdc_Char)0x20,  /* [1002] */
    (xdc_Char)0x62,  /* [1003] */
    (xdc_Char)0x75,  /* [1004] */
    (xdc_Char)0x66,  /* [1005] */
    (xdc_Char)0x53,  /* [1006] */
    (xdc_Char)0x69,  /* [1007] */
    (xdc_Char)0x7a,  /* [1008] */
    (xdc_Char)0x65,  /* [1009] */
    (xdc_Char)0x20,  /* [1010] */
    (xdc_Char)0x70,  /* [1011] */
    (xdc_Char)0x61,  /* [1012] */
    (xdc_Char)0x72,  /* [1013] */
    (xdc_Char)0x61,  /* [1014] */
    (xdc_Char)0x6d,  /* [1015] */
    (xdc_Char)0x65,  /* [1016] */
    (xdc_Char)0x74,  /* [1017] */
    (xdc_Char)0x65,  /* [1018] */
    (xdc_Char)0x72,  /* [1019] */
    (xdc_Char)0x20,  /* [1020] */
    (xdc_Char)0x69,  /* [1021] */
    (xdc_Char)0x73,  /* [1022] */
    (xdc_Char)0x20,  /* [1023] */
    (xdc_Char)0x69,  /* [1024] */
    (xdc_Char)0x6e,  /* [1025] */
    (xdc_Char)0x76,  /* [1026] */
    (xdc_Char)0x61,  /* [1027] */
    (xdc_Char)0x6c,  /* [1028] */
    (xdc_Char)0x69,  /* [1029] */
    (xdc_Char)0x64,  /* [1030] */
    (xdc_Char)0x20,  /* [1031] */
    (xdc_Char)0x28,  /* [1032] */
    (xdc_Char)0x74,  /* [1033] */
    (xdc_Char)0x6f,  /* [1034] */
    (xdc_Char)0x6f,  /* [1035] */
    (xdc_Char)0x20,  /* [1036] */
    (xdc_Char)0x73,  /* [1037] */
    (xdc_Char)0x6d,  /* [1038] */
    (xdc_Char)0x61,  /* [1039] */
    (xdc_Char)0x6c,  /* [1040] */
    (xdc_Char)0x6c,  /* [1041] */
    (xdc_Char)0x29,  /* [1042] */
    (xdc_Char)0x0,  /* [1043] */
    (xdc_Char)0x41,  /* [1044] */
    (xdc_Char)0x5f,  /* [1045] */
    (xdc_Char)0x6e,  /* [1046] */
    (xdc_Char)0x6f,  /* [1047] */
    (xdc_Char)0x45,  /* [1048] */
    (xdc_Char)0x76,  /* [1049] */
    (xdc_Char)0x65,  /* [1050] */
    (xdc_Char)0x6e,  /* [1051] */
    (xdc_Char)0x74,  /* [1052] */
    (xdc_Char)0x73,  /* [1053] */
    (xdc_Char)0x3a,  /* [1054] */
    (xdc_Char)0x20,  /* [1055] */
    (xdc_Char)0x54,  /* [1056] */
    (xdc_Char)0x68,  /* [1057] */
    (xdc_Char)0x65,  /* [1058] */
    (xdc_Char)0x20,  /* [1059] */
    (xdc_Char)0x45,  /* [1060] */
    (xdc_Char)0x76,  /* [1061] */
    (xdc_Char)0x65,  /* [1062] */
    (xdc_Char)0x6e,  /* [1063] */
    (xdc_Char)0x74,  /* [1064] */
    (xdc_Char)0x2e,  /* [1065] */
    (xdc_Char)0x73,  /* [1066] */
    (xdc_Char)0x75,  /* [1067] */
    (xdc_Char)0x70,  /* [1068] */
    (xdc_Char)0x70,  /* [1069] */
    (xdc_Char)0x6f,  /* [1070] */
    (xdc_Char)0x72,  /* [1071] */
    (xdc_Char)0x74,  /* [1072] */
    (xdc_Char)0x73,  /* [1073] */
    (xdc_Char)0x45,  /* [1074] */
    (xdc_Char)0x76,  /* [1075] */
    (xdc_Char)0x65,  /* [1076] */
    (xdc_Char)0x6e,  /* [1077] */
    (xdc_Char)0x74,  /* [1078] */
    (xdc_Char)0x73,  /* [1079] */
    (xdc_Char)0x20,  /* [1080] */
    (xdc_Char)0x66,  /* [1081] */
    (xdc_Char)0x6c,  /* [1082] */
    (xdc_Char)0x61,  /* [1083] */
    (xdc_Char)0x67,  /* [1084] */
    (xdc_Char)0x20,  /* [1085] */
    (xdc_Char)0x69,  /* [1086] */
    (xdc_Char)0x73,  /* [1087] */
    (xdc_Char)0x20,  /* [1088] */
    (xdc_Char)0x64,  /* [1089] */
    (xdc_Char)0x69,  /* [1090] */
    (xdc_Char)0x73,  /* [1091] */
    (xdc_Char)0x61,  /* [1092] */
    (xdc_Char)0x62,  /* [1093] */
    (xdc_Char)0x6c,  /* [1094] */
    (xdc_Char)0x65,  /* [1095] */
    (xdc_Char)0x64,  /* [1096] */
    (xdc_Char)0x2e,  /* [1097] */
    (xdc_Char)0x0,  /* [1098] */
    (xdc_Char)0x41,  /* [1099] */
    (xdc_Char)0x5f,  /* [1100] */
    (xdc_Char)0x69,  /* [1101] */
    (xdc_Char)0x6e,  /* [1102] */
    (xdc_Char)0x76,  /* [1103] */
    (xdc_Char)0x54,  /* [1104] */
    (xdc_Char)0x69,  /* [1105] */
    (xdc_Char)0x6d,  /* [1106] */
    (xdc_Char)0x65,  /* [1107] */
    (xdc_Char)0x6f,  /* [1108] */
    (xdc_Char)0x75,  /* [1109] */
    (xdc_Char)0x74,  /* [1110] */
    (xdc_Char)0x3a,  /* [1111] */
    (xdc_Char)0x20,  /* [1112] */
    (xdc_Char)0x43,  /* [1113] */
    (xdc_Char)0x61,  /* [1114] */
    (xdc_Char)0x6e,  /* [1115] */
    (xdc_Char)0x27,  /* [1116] */
    (xdc_Char)0x74,  /* [1117] */
    (xdc_Char)0x20,  /* [1118] */
    (xdc_Char)0x75,  /* [1119] */
    (xdc_Char)0x73,  /* [1120] */
    (xdc_Char)0x65,  /* [1121] */
    (xdc_Char)0x20,  /* [1122] */
    (xdc_Char)0x42,  /* [1123] */
    (xdc_Char)0x49,  /* [1124] */
    (xdc_Char)0x4f,  /* [1125] */
    (xdc_Char)0x53,  /* [1126] */
    (xdc_Char)0x5f,  /* [1127] */
    (xdc_Char)0x45,  /* [1128] */
    (xdc_Char)0x56,  /* [1129] */
    (xdc_Char)0x45,  /* [1130] */
    (xdc_Char)0x4e,  /* [1131] */
    (xdc_Char)0x54,  /* [1132] */
    (xdc_Char)0x5f,  /* [1133] */
    (xdc_Char)0x41,  /* [1134] */
    (xdc_Char)0x43,  /* [1135] */
    (xdc_Char)0x51,  /* [1136] */
    (xdc_Char)0x55,  /* [1137] */
    (xdc_Char)0x49,  /* [1138] */
    (xdc_Char)0x52,  /* [1139] */
    (xdc_Char)0x45,  /* [1140] */
    (xdc_Char)0x44,  /* [1141] */
    (xdc_Char)0x20,  /* [1142] */
    (xdc_Char)0x77,  /* [1143] */
    (xdc_Char)0x69,  /* [1144] */
    (xdc_Char)0x74,  /* [1145] */
    (xdc_Char)0x68,  /* [1146] */
    (xdc_Char)0x20,  /* [1147] */
    (xdc_Char)0x74,  /* [1148] */
    (xdc_Char)0x68,  /* [1149] */
    (xdc_Char)0x69,  /* [1150] */
    (xdc_Char)0x73,  /* [1151] */
    (xdc_Char)0x20,  /* [1152] */
    (xdc_Char)0x53,  /* [1153] */
    (xdc_Char)0x65,  /* [1154] */
    (xdc_Char)0x6d,  /* [1155] */
    (xdc_Char)0x61,  /* [1156] */
    (xdc_Char)0x70,  /* [1157] */
    (xdc_Char)0x68,  /* [1158] */
    (xdc_Char)0x6f,  /* [1159] */
    (xdc_Char)0x72,  /* [1160] */
    (xdc_Char)0x65,  /* [1161] */
    (xdc_Char)0x2e,  /* [1162] */
    (xdc_Char)0x0,  /* [1163] */
    (xdc_Char)0x41,  /* [1164] */
    (xdc_Char)0x5f,  /* [1165] */
    (xdc_Char)0x6f,  /* [1166] */
    (xdc_Char)0x76,  /* [1167] */
    (xdc_Char)0x65,  /* [1168] */
    (xdc_Char)0x72,  /* [1169] */
    (xdc_Char)0x66,  /* [1170] */
    (xdc_Char)0x6c,  /* [1171] */
    (xdc_Char)0x6f,  /* [1172] */
    (xdc_Char)0x77,  /* [1173] */
    (xdc_Char)0x3a,  /* [1174] */
    (xdc_Char)0x20,  /* [1175] */
    (xdc_Char)0x43,  /* [1176] */
    (xdc_Char)0x6f,  /* [1177] */
    (xdc_Char)0x75,  /* [1178] */
    (xdc_Char)0x6e,  /* [1179] */
    (xdc_Char)0x74,  /* [1180] */
    (xdc_Char)0x20,  /* [1181] */
    (xdc_Char)0x68,  /* [1182] */
    (xdc_Char)0x61,  /* [1183] */
    (xdc_Char)0x73,  /* [1184] */
    (xdc_Char)0x20,  /* [1185] */
    (xdc_Char)0x65,  /* [1186] */
    (xdc_Char)0x78,  /* [1187] */
    (xdc_Char)0x63,  /* [1188] */
    (xdc_Char)0x65,  /* [1189] */
    (xdc_Char)0x65,  /* [1190] */
    (xdc_Char)0x64,  /* [1191] */
    (xdc_Char)0x65,  /* [1192] */
    (xdc_Char)0x64,  /* [1193] */
    (xdc_Char)0x20,  /* [1194] */
    (xdc_Char)0x36,  /* [1195] */
    (xdc_Char)0x35,  /* [1196] */
    (xdc_Char)0x35,  /* [1197] */
    (xdc_Char)0x33,  /* [1198] */
    (xdc_Char)0x35,  /* [1199] */
    (xdc_Char)0x20,  /* [1200] */
    (xdc_Char)0x61,  /* [1201] */
    (xdc_Char)0x6e,  /* [1202] */
    (xdc_Char)0x64,  /* [1203] */
    (xdc_Char)0x20,  /* [1204] */
    (xdc_Char)0x72,  /* [1205] */
    (xdc_Char)0x6f,  /* [1206] */
    (xdc_Char)0x6c,  /* [1207] */
    (xdc_Char)0x6c,  /* [1208] */
    (xdc_Char)0x65,  /* [1209] */
    (xdc_Char)0x64,  /* [1210] */
    (xdc_Char)0x20,  /* [1211] */
    (xdc_Char)0x6f,  /* [1212] */
    (xdc_Char)0x76,  /* [1213] */
    (xdc_Char)0x65,  /* [1214] */
    (xdc_Char)0x72,  /* [1215] */
    (xdc_Char)0x2e,  /* [1216] */
    (xdc_Char)0x0,  /* [1217] */
    (xdc_Char)0x41,  /* [1218] */
    (xdc_Char)0x5f,  /* [1219] */
    (xdc_Char)0x70,  /* [1220] */
    (xdc_Char)0x65,  /* [1221] */
    (xdc_Char)0x6e,  /* [1222] */
    (xdc_Char)0x64,  /* [1223] */
    (xdc_Char)0x54,  /* [1224] */
    (xdc_Char)0x61,  /* [1225] */
    (xdc_Char)0x73,  /* [1226] */
    (xdc_Char)0x6b,  /* [1227] */
    (xdc_Char)0x44,  /* [1228] */
    (xdc_Char)0x69,  /* [1229] */
    (xdc_Char)0x73,  /* [1230] */
    (xdc_Char)0x61,  /* [1231] */
    (xdc_Char)0x62,  /* [1232] */
    (xdc_Char)0x6c,  /* [1233] */
    (xdc_Char)0x65,  /* [1234] */
    (xdc_Char)0x64,  /* [1235] */
    (xdc_Char)0x3a,  /* [1236] */
    (xdc_Char)0x20,  /* [1237] */
    (xdc_Char)0x43,  /* [1238] */
    (xdc_Char)0x61,  /* [1239] */
    (xdc_Char)0x6e,  /* [1240] */
    (xdc_Char)0x6e,  /* [1241] */
    (xdc_Char)0x6f,  /* [1242] */
    (xdc_Char)0x74,  /* [1243] */
    (xdc_Char)0x20,  /* [1244] */
    (xdc_Char)0x63,  /* [1245] */
    (xdc_Char)0x61,  /* [1246] */
    (xdc_Char)0x6c,  /* [1247] */
    (xdc_Char)0x6c,  /* [1248] */
    (xdc_Char)0x20,  /* [1249] */
    (xdc_Char)0x53,  /* [1250] */
    (xdc_Char)0x65,  /* [1251] */
    (xdc_Char)0x6d,  /* [1252] */
    (xdc_Char)0x61,  /* [1253] */
    (xdc_Char)0x70,  /* [1254] */
    (xdc_Char)0x68,  /* [1255] */
    (xdc_Char)0x6f,  /* [1256] */
    (xdc_Char)0x72,  /* [1257] */
    (xdc_Char)0x65,  /* [1258] */
    (xdc_Char)0x5f,  /* [1259] */
    (xdc_Char)0x70,  /* [1260] */
    (xdc_Char)0x65,  /* [1261] */
    (xdc_Char)0x6e,  /* [1262] */
    (xdc_Char)0x64,  /* [1263] */
    (xdc_Char)0x28,  /* [1264] */
    (xdc_Char)0x29,  /* [1265] */
    (xdc_Char)0x20,  /* [1266] */
    (xdc_Char)0x77,  /* [1267] */
    (xdc_Char)0x68,  /* [1268] */
    (xdc_Char)0x69,  /* [1269] */
    (xdc_Char)0x6c,  /* [1270] */
    (xdc_Char)0x65,  /* [1271] */
    (xdc_Char)0x20,  /* [1272] */
    (xdc_Char)0x74,  /* [1273] */
    (xdc_Char)0x68,  /* [1274] */
    (xdc_Char)0x65,  /* [1275] */
    (xdc_Char)0x20,  /* [1276] */
    (xdc_Char)0x54,  /* [1277] */
    (xdc_Char)0x61,  /* [1278] */
    (xdc_Char)0x73,  /* [1279] */
    (xdc_Char)0x6b,  /* [1280] */
    (xdc_Char)0x20,  /* [1281] */
    (xdc_Char)0x6f,  /* [1282] */
    (xdc_Char)0x72,  /* [1283] */
    (xdc_Char)0x20,  /* [1284] */
    (xdc_Char)0x53,  /* [1285] */
    (xdc_Char)0x77,  /* [1286] */
    (xdc_Char)0x69,  /* [1287] */
    (xdc_Char)0x20,  /* [1288] */
    (xdc_Char)0x73,  /* [1289] */
    (xdc_Char)0x63,  /* [1290] */
    (xdc_Char)0x68,  /* [1291] */
    (xdc_Char)0x65,  /* [1292] */
    (xdc_Char)0x64,  /* [1293] */
    (xdc_Char)0x75,  /* [1294] */
    (xdc_Char)0x6c,  /* [1295] */
    (xdc_Char)0x65,  /* [1296] */
    (xdc_Char)0x72,  /* [1297] */
    (xdc_Char)0x20,  /* [1298] */
    (xdc_Char)0x69,  /* [1299] */
    (xdc_Char)0x73,  /* [1300] */
    (xdc_Char)0x20,  /* [1301] */
    (xdc_Char)0x64,  /* [1302] */
    (xdc_Char)0x69,  /* [1303] */
    (xdc_Char)0x73,  /* [1304] */
    (xdc_Char)0x61,  /* [1305] */
    (xdc_Char)0x62,  /* [1306] */
    (xdc_Char)0x6c,  /* [1307] */
    (xdc_Char)0x65,  /* [1308] */
    (xdc_Char)0x64,  /* [1309] */
    (xdc_Char)0x2e,  /* [1310] */
    (xdc_Char)0x0,  /* [1311] */
    (xdc_Char)0x41,  /* [1312] */
    (xdc_Char)0x5f,  /* [1313] */
    (xdc_Char)0x73,  /* [1314] */
    (xdc_Char)0x77,  /* [1315] */
    (xdc_Char)0x69,  /* [1316] */
    (xdc_Char)0x44,  /* [1317] */
    (xdc_Char)0x69,  /* [1318] */
    (xdc_Char)0x73,  /* [1319] */
    (xdc_Char)0x61,  /* [1320] */
    (xdc_Char)0x62,  /* [1321] */
    (xdc_Char)0x6c,  /* [1322] */
    (xdc_Char)0x65,  /* [1323] */
    (xdc_Char)0x64,  /* [1324] */
    (xdc_Char)0x3a,  /* [1325] */
    (xdc_Char)0x20,  /* [1326] */
    (xdc_Char)0x43,  /* [1327] */
    (xdc_Char)0x61,  /* [1328] */
    (xdc_Char)0x6e,  /* [1329] */
    (xdc_Char)0x6e,  /* [1330] */
    (xdc_Char)0x6f,  /* [1331] */
    (xdc_Char)0x74,  /* [1332] */
    (xdc_Char)0x20,  /* [1333] */
    (xdc_Char)0x63,  /* [1334] */
    (xdc_Char)0x72,  /* [1335] */
    (xdc_Char)0x65,  /* [1336] */
    (xdc_Char)0x61,  /* [1337] */
    (xdc_Char)0x74,  /* [1338] */
    (xdc_Char)0x65,  /* [1339] */
    (xdc_Char)0x20,  /* [1340] */
    (xdc_Char)0x61,  /* [1341] */
    (xdc_Char)0x20,  /* [1342] */
    (xdc_Char)0x53,  /* [1343] */
    (xdc_Char)0x77,  /* [1344] */
    (xdc_Char)0x69,  /* [1345] */
    (xdc_Char)0x20,  /* [1346] */
    (xdc_Char)0x77,  /* [1347] */
    (xdc_Char)0x68,  /* [1348] */
    (xdc_Char)0x65,  /* [1349] */
    (xdc_Char)0x6e,  /* [1350] */
    (xdc_Char)0x20,  /* [1351] */
    (xdc_Char)0x53,  /* [1352] */
    (xdc_Char)0x77,  /* [1353] */
    (xdc_Char)0x69,  /* [1354] */
    (xdc_Char)0x20,  /* [1355] */
    (xdc_Char)0x69,  /* [1356] */
    (xdc_Char)0x73,  /* [1357] */
    (xdc_Char)0x20,  /* [1358] */
    (xdc_Char)0x64,  /* [1359] */
    (xdc_Char)0x69,  /* [1360] */
    (xdc_Char)0x73,  /* [1361] */
    (xdc_Char)0x61,  /* [1362] */
    (xdc_Char)0x62,  /* [1363] */
    (xdc_Char)0x6c,  /* [1364] */
    (xdc_Char)0x65,  /* [1365] */
    (xdc_Char)0x64,  /* [1366] */
    (xdc_Char)0x2e,  /* [1367] */
    (xdc_Char)0x0,  /* [1368] */
    (xdc_Char)0x41,  /* [1369] */
    (xdc_Char)0x5f,  /* [1370] */
    (xdc_Char)0x62,  /* [1371] */
    (xdc_Char)0x61,  /* [1372] */
    (xdc_Char)0x64,  /* [1373] */
    (xdc_Char)0x50,  /* [1374] */
    (xdc_Char)0x72,  /* [1375] */
    (xdc_Char)0x69,  /* [1376] */
    (xdc_Char)0x6f,  /* [1377] */
    (xdc_Char)0x72,  /* [1378] */
    (xdc_Char)0x69,  /* [1379] */
    (xdc_Char)0x74,  /* [1380] */
    (xdc_Char)0x79,  /* [1381] */
    (xdc_Char)0x3a,  /* [1382] */
    (xdc_Char)0x20,  /* [1383] */
    (xdc_Char)0x41,  /* [1384] */
    (xdc_Char)0x6e,  /* [1385] */
    (xdc_Char)0x20,  /* [1386] */
    (xdc_Char)0x69,  /* [1387] */
    (xdc_Char)0x6e,  /* [1388] */
    (xdc_Char)0x76,  /* [1389] */
    (xdc_Char)0x61,  /* [1390] */
    (xdc_Char)0x6c,  /* [1391] */
    (xdc_Char)0x69,  /* [1392] */
    (xdc_Char)0x64,  /* [1393] */
    (xdc_Char)0x20,  /* [1394] */
    (xdc_Char)0x53,  /* [1395] */
    (xdc_Char)0x77,  /* [1396] */
    (xdc_Char)0x69,  /* [1397] */
    (xdc_Char)0x20,  /* [1398] */
    (xdc_Char)0x70,  /* [1399] */
    (xdc_Char)0x72,  /* [1400] */
    (xdc_Char)0x69,  /* [1401] */
    (xdc_Char)0x6f,  /* [1402] */
    (xdc_Char)0x72,  /* [1403] */
    (xdc_Char)0x69,  /* [1404] */
    (xdc_Char)0x74,  /* [1405] */
    (xdc_Char)0x79,  /* [1406] */
    (xdc_Char)0x20,  /* [1407] */
    (xdc_Char)0x77,  /* [1408] */
    (xdc_Char)0x61,  /* [1409] */
    (xdc_Char)0x73,  /* [1410] */
    (xdc_Char)0x20,  /* [1411] */
    (xdc_Char)0x75,  /* [1412] */
    (xdc_Char)0x73,  /* [1413] */
    (xdc_Char)0x65,  /* [1414] */
    (xdc_Char)0x64,  /* [1415] */
    (xdc_Char)0x2e,  /* [1416] */
    (xdc_Char)0x0,  /* [1417] */
    (xdc_Char)0x41,  /* [1418] */
    (xdc_Char)0x5f,  /* [1419] */
    (xdc_Char)0x62,  /* [1420] */
    (xdc_Char)0x61,  /* [1421] */
    (xdc_Char)0x64,  /* [1422] */
    (xdc_Char)0x54,  /* [1423] */
    (xdc_Char)0x68,  /* [1424] */
    (xdc_Char)0x72,  /* [1425] */
    (xdc_Char)0x65,  /* [1426] */
    (xdc_Char)0x61,  /* [1427] */
    (xdc_Char)0x64,  /* [1428] */
    (xdc_Char)0x54,  /* [1429] */
    (xdc_Char)0x79,  /* [1430] */
    (xdc_Char)0x70,  /* [1431] */
    (xdc_Char)0x65,  /* [1432] */
    (xdc_Char)0x3a,  /* [1433] */
    (xdc_Char)0x20,  /* [1434] */
    (xdc_Char)0x43,  /* [1435] */
    (xdc_Char)0x61,  /* [1436] */
    (xdc_Char)0x6e,  /* [1437] */
    (xdc_Char)0x6e,  /* [1438] */
    (xdc_Char)0x6f,  /* [1439] */
    (xdc_Char)0x74,  /* [1440] */
    (xdc_Char)0x20,  /* [1441] */
    (xdc_Char)0x63,  /* [1442] */
    (xdc_Char)0x72,  /* [1443] */
    (xdc_Char)0x65,  /* [1444] */
    (xdc_Char)0x61,  /* [1445] */
    (xdc_Char)0x74,  /* [1446] */
    (xdc_Char)0x65,  /* [1447] */
    (xdc_Char)0x2f,  /* [1448] */
    (xdc_Char)0x64,  /* [1449] */
    (xdc_Char)0x65,  /* [1450] */
    (xdc_Char)0x6c,  /* [1451] */
    (xdc_Char)0x65,  /* [1452] */
    (xdc_Char)0x74,  /* [1453] */
    (xdc_Char)0x65,  /* [1454] */
    (xdc_Char)0x20,  /* [1455] */
    (xdc_Char)0x61,  /* [1456] */
    (xdc_Char)0x20,  /* [1457] */
    (xdc_Char)0x74,  /* [1458] */
    (xdc_Char)0x61,  /* [1459] */
    (xdc_Char)0x73,  /* [1460] */
    (xdc_Char)0x6b,  /* [1461] */
    (xdc_Char)0x20,  /* [1462] */
    (xdc_Char)0x66,  /* [1463] */
    (xdc_Char)0x72,  /* [1464] */
    (xdc_Char)0x6f,  /* [1465] */
    (xdc_Char)0x6d,  /* [1466] */
    (xdc_Char)0x20,  /* [1467] */
    (xdc_Char)0x48,  /* [1468] */
    (xdc_Char)0x77,  /* [1469] */
    (xdc_Char)0x69,  /* [1470] */
    (xdc_Char)0x20,  /* [1471] */
    (xdc_Char)0x6f,  /* [1472] */
    (xdc_Char)0x72,  /* [1473] */
    (xdc_Char)0x20,  /* [1474] */
    (xdc_Char)0x53,  /* [1475] */
    (xdc_Char)0x77,  /* [1476] */
    (xdc_Char)0x69,  /* [1477] */
    (xdc_Char)0x20,  /* [1478] */
    (xdc_Char)0x74,  /* [1479] */
    (xdc_Char)0x68,  /* [1480] */
    (xdc_Char)0x72,  /* [1481] */
    (xdc_Char)0x65,  /* [1482] */
    (xdc_Char)0x61,  /* [1483] */
    (xdc_Char)0x64,  /* [1484] */
    (xdc_Char)0x2e,  /* [1485] */
    (xdc_Char)0x0,  /* [1486] */
    (xdc_Char)0x41,  /* [1487] */
    (xdc_Char)0x5f,  /* [1488] */
    (xdc_Char)0x62,  /* [1489] */
    (xdc_Char)0x61,  /* [1490] */
    (xdc_Char)0x64,  /* [1491] */
    (xdc_Char)0x54,  /* [1492] */
    (xdc_Char)0x61,  /* [1493] */
    (xdc_Char)0x73,  /* [1494] */
    (xdc_Char)0x6b,  /* [1495] */
    (xdc_Char)0x53,  /* [1496] */
    (xdc_Char)0x74,  /* [1497] */
    (xdc_Char)0x61,  /* [1498] */
    (xdc_Char)0x74,  /* [1499] */
    (xdc_Char)0x65,  /* [1500] */
    (xdc_Char)0x3a,  /* [1501] */
    (xdc_Char)0x20,  /* [1502] */
    (xdc_Char)0x43,  /* [1503] */
    (xdc_Char)0x61,  /* [1504] */
    (xdc_Char)0x6e,  /* [1505] */
    (xdc_Char)0x27,  /* [1506] */
    (xdc_Char)0x74,  /* [1507] */
    (xdc_Char)0x20,  /* [1508] */
    (xdc_Char)0x64,  /* [1509] */
    (xdc_Char)0x65,  /* [1510] */
    (xdc_Char)0x6c,  /* [1511] */
    (xdc_Char)0x65,  /* [1512] */
    (xdc_Char)0x74,  /* [1513] */
    (xdc_Char)0x65,  /* [1514] */
    (xdc_Char)0x20,  /* [1515] */
    (xdc_Char)0x61,  /* [1516] */
    (xdc_Char)0x20,  /* [1517] */
    (xdc_Char)0x74,  /* [1518] */
    (xdc_Char)0x61,  /* [1519] */
    (xdc_Char)0x73,  /* [1520] */
    (xdc_Char)0x6b,  /* [1521] */
    (xdc_Char)0x20,  /* [1522] */
    (xdc_Char)0x69,  /* [1523] */
    (xdc_Char)0x6e,  /* [1524] */
    (xdc_Char)0x20,  /* [1525] */
    (xdc_Char)0x52,  /* [1526] */
    (xdc_Char)0x55,  /* [1527] */
    (xdc_Char)0x4e,  /* [1528] */
    (xdc_Char)0x4e,  /* [1529] */
    (xdc_Char)0x49,  /* [1530] */
    (xdc_Char)0x4e,  /* [1531] */
    (xdc_Char)0x47,  /* [1532] */
    (xdc_Char)0x20,  /* [1533] */
    (xdc_Char)0x73,  /* [1534] */
    (xdc_Char)0x74,  /* [1535] */
    (xdc_Char)0x61,  /* [1536] */
    (xdc_Char)0x74,  /* [1537] */
    (xdc_Char)0x65,  /* [1538] */
    (xdc_Char)0x2e,  /* [1539] */
    (xdc_Char)0x0,  /* [1540] */
    (xdc_Char)0x41,  /* [1541] */
    (xdc_Char)0x5f,  /* [1542] */
    (xdc_Char)0x6e,  /* [1543] */
    (xdc_Char)0x6f,  /* [1544] */
    (xdc_Char)0x50,  /* [1545] */
    (xdc_Char)0x65,  /* [1546] */
    (xdc_Char)0x6e,  /* [1547] */
    (xdc_Char)0x64,  /* [1548] */
    (xdc_Char)0x45,  /* [1549] */
    (xdc_Char)0x6c,  /* [1550] */
    (xdc_Char)0x65,  /* [1551] */
    (xdc_Char)0x6d,  /* [1552] */
    (xdc_Char)0x3a,  /* [1553] */
    (xdc_Char)0x20,  /* [1554] */
    (xdc_Char)0x4e,  /* [1555] */
    (xdc_Char)0x6f,  /* [1556] */
    (xdc_Char)0x74,  /* [1557] */
    (xdc_Char)0x20,  /* [1558] */
    (xdc_Char)0x65,  /* [1559] */
    (xdc_Char)0x6e,  /* [1560] */
    (xdc_Char)0x6f,  /* [1561] */
    (xdc_Char)0x75,  /* [1562] */
    (xdc_Char)0x67,  /* [1563] */
    (xdc_Char)0x68,  /* [1564] */
    (xdc_Char)0x20,  /* [1565] */
    (xdc_Char)0x69,  /* [1566] */
    (xdc_Char)0x6e,  /* [1567] */
    (xdc_Char)0x66,  /* [1568] */
    (xdc_Char)0x6f,  /* [1569] */
    (xdc_Char)0x20,  /* [1570] */
    (xdc_Char)0x74,  /* [1571] */
    (xdc_Char)0x6f,  /* [1572] */
    (xdc_Char)0x20,  /* [1573] */
    (xdc_Char)0x64,  /* [1574] */
    (xdc_Char)0x65,  /* [1575] */
    (xdc_Char)0x6c,  /* [1576] */
    (xdc_Char)0x65,  /* [1577] */
    (xdc_Char)0x74,  /* [1578] */
    (xdc_Char)0x65,  /* [1579] */
    (xdc_Char)0x20,  /* [1580] */
    (xdc_Char)0x42,  /* [1581] */
    (xdc_Char)0x4c,  /* [1582] */
    (xdc_Char)0x4f,  /* [1583] */
    (xdc_Char)0x43,  /* [1584] */
    (xdc_Char)0x4b,  /* [1585] */
    (xdc_Char)0x45,  /* [1586] */
    (xdc_Char)0x44,  /* [1587] */
    (xdc_Char)0x20,  /* [1588] */
    (xdc_Char)0x74,  /* [1589] */
    (xdc_Char)0x61,  /* [1590] */
    (xdc_Char)0x73,  /* [1591] */
    (xdc_Char)0x6b,  /* [1592] */
    (xdc_Char)0x2e,  /* [1593] */
    (xdc_Char)0x0,  /* [1594] */
    (xdc_Char)0x41,  /* [1595] */
    (xdc_Char)0x5f,  /* [1596] */
    (xdc_Char)0x74,  /* [1597] */
    (xdc_Char)0x61,  /* [1598] */
    (xdc_Char)0x73,  /* [1599] */
    (xdc_Char)0x6b,  /* [1600] */
    (xdc_Char)0x44,  /* [1601] */
    (xdc_Char)0x69,  /* [1602] */
    (xdc_Char)0x73,  /* [1603] */
    (xdc_Char)0x61,  /* [1604] */
    (xdc_Char)0x62,  /* [1605] */
    (xdc_Char)0x6c,  /* [1606] */
    (xdc_Char)0x65,  /* [1607] */
    (xdc_Char)0x64,  /* [1608] */
    (xdc_Char)0x3a,  /* [1609] */
    (xdc_Char)0x20,  /* [1610] */
    (xdc_Char)0x43,  /* [1611] */
    (xdc_Char)0x61,  /* [1612] */
    (xdc_Char)0x6e,  /* [1613] */
    (xdc_Char)0x6e,  /* [1614] */
    (xdc_Char)0x6f,  /* [1615] */
    (xdc_Char)0x74,  /* [1616] */
    (xdc_Char)0x20,  /* [1617] */
    (xdc_Char)0x63,  /* [1618] */
    (xdc_Char)0x72,  /* [1619] */
    (xdc_Char)0x65,  /* [1620] */
    (xdc_Char)0x61,  /* [1621] */
    (xdc_Char)0x74,  /* [1622] */
    (xdc_Char)0x65,  /* [1623] */
    (xdc_Char)0x20,  /* [1624] */
    (xdc_Char)0x61,  /* [1625] */
    (xdc_Char)0x20,  /* [1626] */
    (xdc_Char)0x74,  /* [1627] */
    (xdc_Char)0x61,  /* [1628] */
    (xdc_Char)0x73,  /* [1629] */
    (xdc_Char)0x6b,  /* [1630] */
    (xdc_Char)0x20,  /* [1631] */
    (xdc_Char)0x77,  /* [1632] */
    (xdc_Char)0x68,  /* [1633] */
    (xdc_Char)0x65,  /* [1634] */
    (xdc_Char)0x6e,  /* [1635] */
    (xdc_Char)0x20,  /* [1636] */
    (xdc_Char)0x74,  /* [1637] */
    (xdc_Char)0x61,  /* [1638] */
    (xdc_Char)0x73,  /* [1639] */
    (xdc_Char)0x6b,  /* [1640] */
    (xdc_Char)0x69,  /* [1641] */
    (xdc_Char)0x6e,  /* [1642] */
    (xdc_Char)0x67,  /* [1643] */
    (xdc_Char)0x20,  /* [1644] */
    (xdc_Char)0x69,  /* [1645] */
    (xdc_Char)0x73,  /* [1646] */
    (xdc_Char)0x20,  /* [1647] */
    (xdc_Char)0x64,  /* [1648] */
    (xdc_Char)0x69,  /* [1649] */
    (xdc_Char)0x73,  /* [1650] */
    (xdc_Char)0x61,  /* [1651] */
    (xdc_Char)0x62,  /* [1652] */
    (xdc_Char)0x6c,  /* [1653] */
    (xdc_Char)0x65,  /* [1654] */
    (xdc_Char)0x64,  /* [1655] */
    (xdc_Char)0x2e,  /* [1656] */
    (xdc_Char)0x0,  /* [1657] */
    (xdc_Char)0x41,  /* [1658] */
    (xdc_Char)0x5f,  /* [1659] */
    (xdc_Char)0x62,  /* [1660] */
    (xdc_Char)0x61,  /* [1661] */
    (xdc_Char)0x64,  /* [1662] */
    (xdc_Char)0x50,  /* [1663] */
    (xdc_Char)0x72,  /* [1664] */
    (xdc_Char)0x69,  /* [1665] */
    (xdc_Char)0x6f,  /* [1666] */
    (xdc_Char)0x72,  /* [1667] */
    (xdc_Char)0x69,  /* [1668] */
    (xdc_Char)0x74,  /* [1669] */
    (xdc_Char)0x79,  /* [1670] */
    (xdc_Char)0x3a,  /* [1671] */
    (xdc_Char)0x20,  /* [1672] */
    (xdc_Char)0x41,  /* [1673] */
    (xdc_Char)0x6e,  /* [1674] */
    (xdc_Char)0x20,  /* [1675] */
    (xdc_Char)0x69,  /* [1676] */
    (xdc_Char)0x6e,  /* [1677] */
    (xdc_Char)0x76,  /* [1678] */
    (xdc_Char)0x61,  /* [1679] */
    (xdc_Char)0x6c,  /* [1680] */
    (xdc_Char)0x69,  /* [1681] */
    (xdc_Char)0x64,  /* [1682] */
    (xdc_Char)0x20,  /* [1683] */
    (xdc_Char)0x74,  /* [1684] */
    (xdc_Char)0x61,  /* [1685] */
    (xdc_Char)0x73,  /* [1686] */
    (xdc_Char)0x6b,  /* [1687] */
    (xdc_Char)0x20,  /* [1688] */
    (xdc_Char)0x70,  /* [1689] */
    (xdc_Char)0x72,  /* [1690] */
    (xdc_Char)0x69,  /* [1691] */
    (xdc_Char)0x6f,  /* [1692] */
    (xdc_Char)0x72,  /* [1693] */
    (xdc_Char)0x69,  /* [1694] */
    (xdc_Char)0x74,  /* [1695] */
    (xdc_Char)0x79,  /* [1696] */
    (xdc_Char)0x20,  /* [1697] */
    (xdc_Char)0x77,  /* [1698] */
    (xdc_Char)0x61,  /* [1699] */
    (xdc_Char)0x73,  /* [1700] */
    (xdc_Char)0x20,  /* [1701] */
    (xdc_Char)0x75,  /* [1702] */
    (xdc_Char)0x73,  /* [1703] */
    (xdc_Char)0x65,  /* [1704] */
    (xdc_Char)0x64,  /* [1705] */
    (xdc_Char)0x2e,  /* [1706] */
    (xdc_Char)0x0,  /* [1707] */
    (xdc_Char)0x41,  /* [1708] */
    (xdc_Char)0x5f,  /* [1709] */
    (xdc_Char)0x62,  /* [1710] */
    (xdc_Char)0x61,  /* [1711] */
    (xdc_Char)0x64,  /* [1712] */
    (xdc_Char)0x54,  /* [1713] */
    (xdc_Char)0x69,  /* [1714] */
    (xdc_Char)0x6d,  /* [1715] */
    (xdc_Char)0x65,  /* [1716] */
    (xdc_Char)0x6f,  /* [1717] */
    (xdc_Char)0x75,  /* [1718] */
    (xdc_Char)0x74,  /* [1719] */
    (xdc_Char)0x3a,  /* [1720] */
    (xdc_Char)0x20,  /* [1721] */
    (xdc_Char)0x43,  /* [1722] */
    (xdc_Char)0x61,  /* [1723] */
    (xdc_Char)0x6e,  /* [1724] */
    (xdc_Char)0x27,  /* [1725] */
    (xdc_Char)0x74,  /* [1726] */
    (xdc_Char)0x20,  /* [1727] */
    (xdc_Char)0x73,  /* [1728] */
    (xdc_Char)0x6c,  /* [1729] */
    (xdc_Char)0x65,  /* [1730] */
    (xdc_Char)0x65,  /* [1731] */
    (xdc_Char)0x70,  /* [1732] */
    (xdc_Char)0x20,  /* [1733] */
    (xdc_Char)0x46,  /* [1734] */
    (xdc_Char)0x4f,  /* [1735] */
    (xdc_Char)0x52,  /* [1736] */
    (xdc_Char)0x45,  /* [1737] */
    (xdc_Char)0x56,  /* [1738] */
    (xdc_Char)0x45,  /* [1739] */
    (xdc_Char)0x52,  /* [1740] */
    (xdc_Char)0x2e,  /* [1741] */
    (xdc_Char)0x0,  /* [1742] */
    (xdc_Char)0x41,  /* [1743] */
    (xdc_Char)0x5f,  /* [1744] */
    (xdc_Char)0x62,  /* [1745] */
    (xdc_Char)0x61,  /* [1746] */
    (xdc_Char)0x64,  /* [1747] */
    (xdc_Char)0x41,  /* [1748] */
    (xdc_Char)0x66,  /* [1749] */
    (xdc_Char)0x66,  /* [1750] */
    (xdc_Char)0x69,  /* [1751] */
    (xdc_Char)0x6e,  /* [1752] */
    (xdc_Char)0x69,  /* [1753] */
    (xdc_Char)0x74,  /* [1754] */
    (xdc_Char)0x79,  /* [1755] */
    (xdc_Char)0x3a,  /* [1756] */
    (xdc_Char)0x20,  /* [1757] */
    (xdc_Char)0x49,  /* [1758] */
    (xdc_Char)0x6e,  /* [1759] */
    (xdc_Char)0x76,  /* [1760] */
    (xdc_Char)0x61,  /* [1761] */
    (xdc_Char)0x6c,  /* [1762] */
    (xdc_Char)0x69,  /* [1763] */
    (xdc_Char)0x64,  /* [1764] */
    (xdc_Char)0x20,  /* [1765] */
    (xdc_Char)0x61,  /* [1766] */
    (xdc_Char)0x66,  /* [1767] */
    (xdc_Char)0x66,  /* [1768] */
    (xdc_Char)0x69,  /* [1769] */
    (xdc_Char)0x6e,  /* [1770] */
    (xdc_Char)0x69,  /* [1771] */
    (xdc_Char)0x74,  /* [1772] */
    (xdc_Char)0x79,  /* [1773] */
    (xdc_Char)0x2e,  /* [1774] */
    (xdc_Char)0x0,  /* [1775] */
    (xdc_Char)0x41,  /* [1776] */
    (xdc_Char)0x5f,  /* [1777] */
    (xdc_Char)0x73,  /* [1778] */
    (xdc_Char)0x6c,  /* [1779] */
    (xdc_Char)0x65,  /* [1780] */
    (xdc_Char)0x65,  /* [1781] */
    (xdc_Char)0x70,  /* [1782] */
    (xdc_Char)0x54,  /* [1783] */
    (xdc_Char)0x61,  /* [1784] */
    (xdc_Char)0x73,  /* [1785] */
    (xdc_Char)0x6b,  /* [1786] */
    (xdc_Char)0x44,  /* [1787] */
    (xdc_Char)0x69,  /* [1788] */
    (xdc_Char)0x73,  /* [1789] */
    (xdc_Char)0x61,  /* [1790] */
    (xdc_Char)0x62,  /* [1791] */
    (xdc_Char)0x6c,  /* [1792] */
    (xdc_Char)0x65,  /* [1793] */
    (xdc_Char)0x64,  /* [1794] */
    (xdc_Char)0x3a,  /* [1795] */
    (xdc_Char)0x20,  /* [1796] */
    (xdc_Char)0x43,  /* [1797] */
    (xdc_Char)0x61,  /* [1798] */
    (xdc_Char)0x6e,  /* [1799] */
    (xdc_Char)0x6e,  /* [1800] */
    (xdc_Char)0x6f,  /* [1801] */
    (xdc_Char)0x74,  /* [1802] */
    (xdc_Char)0x20,  /* [1803] */
    (xdc_Char)0x63,  /* [1804] */
    (xdc_Char)0x61,  /* [1805] */
    (xdc_Char)0x6c,  /* [1806] */
    (xdc_Char)0x6c,  /* [1807] */
    (xdc_Char)0x20,  /* [1808] */
    (xdc_Char)0x54,  /* [1809] */
    (xdc_Char)0x61,  /* [1810] */
    (xdc_Char)0x73,  /* [1811] */
    (xdc_Char)0x6b,  /* [1812] */
    (xdc_Char)0x5f,  /* [1813] */
    (xdc_Char)0x73,  /* [1814] */
    (xdc_Char)0x6c,  /* [1815] */
    (xdc_Char)0x65,  /* [1816] */
    (xdc_Char)0x65,  /* [1817] */
    (xdc_Char)0x70,  /* [1818] */
    (xdc_Char)0x28,  /* [1819] */
    (xdc_Char)0x29,  /* [1820] */
    (xdc_Char)0x20,  /* [1821] */
    (xdc_Char)0x77,  /* [1822] */
    (xdc_Char)0x68,  /* [1823] */
    (xdc_Char)0x69,  /* [1824] */
    (xdc_Char)0x6c,  /* [1825] */
    (xdc_Char)0x65,  /* [1826] */
    (xdc_Char)0x20,  /* [1827] */
    (xdc_Char)0x74,  /* [1828] */
    (xdc_Char)0x68,  /* [1829] */
    (xdc_Char)0x65,  /* [1830] */
    (xdc_Char)0x20,  /* [1831] */
    (xdc_Char)0x54,  /* [1832] */
    (xdc_Char)0x61,  /* [1833] */
    (xdc_Char)0x73,  /* [1834] */
    (xdc_Char)0x6b,  /* [1835] */
    (xdc_Char)0x20,  /* [1836] */
    (xdc_Char)0x73,  /* [1837] */
    (xdc_Char)0x63,  /* [1838] */
    (xdc_Char)0x68,  /* [1839] */
    (xdc_Char)0x65,  /* [1840] */
    (xdc_Char)0x64,  /* [1841] */
    (xdc_Char)0x75,  /* [1842] */
    (xdc_Char)0x6c,  /* [1843] */
    (xdc_Char)0x65,  /* [1844] */
    (xdc_Char)0x72,  /* [1845] */
    (xdc_Char)0x20,  /* [1846] */
    (xdc_Char)0x69,  /* [1847] */
    (xdc_Char)0x73,  /* [1848] */
    (xdc_Char)0x20,  /* [1849] */
    (xdc_Char)0x64,  /* [1850] */
    (xdc_Char)0x69,  /* [1851] */
    (xdc_Char)0x73,  /* [1852] */
    (xdc_Char)0x61,  /* [1853] */
    (xdc_Char)0x62,  /* [1854] */
    (xdc_Char)0x6c,  /* [1855] */
    (xdc_Char)0x65,  /* [1856] */
    (xdc_Char)0x64,  /* [1857] */
    (xdc_Char)0x2e,  /* [1858] */
    (xdc_Char)0x0,  /* [1859] */
    (xdc_Char)0x41,  /* [1860] */
    (xdc_Char)0x5f,  /* [1861] */
    (xdc_Char)0x69,  /* [1862] */
    (xdc_Char)0x6e,  /* [1863] */
    (xdc_Char)0x76,  /* [1864] */
    (xdc_Char)0x61,  /* [1865] */
    (xdc_Char)0x6c,  /* [1866] */
    (xdc_Char)0x69,  /* [1867] */
    (xdc_Char)0x64,  /* [1868] */
    (xdc_Char)0x43,  /* [1869] */
    (xdc_Char)0x6f,  /* [1870] */
    (xdc_Char)0x72,  /* [1871] */
    (xdc_Char)0x65,  /* [1872] */
    (xdc_Char)0x49,  /* [1873] */
    (xdc_Char)0x64,  /* [1874] */
    (xdc_Char)0x3a,  /* [1875] */
    (xdc_Char)0x20,  /* [1876] */
    (xdc_Char)0x43,  /* [1877] */
    (xdc_Char)0x61,  /* [1878] */
    (xdc_Char)0x6e,  /* [1879] */
    (xdc_Char)0x6e,  /* [1880] */
    (xdc_Char)0x6f,  /* [1881] */
    (xdc_Char)0x74,  /* [1882] */
    (xdc_Char)0x20,  /* [1883] */
    (xdc_Char)0x70,  /* [1884] */
    (xdc_Char)0x61,  /* [1885] */
    (xdc_Char)0x73,  /* [1886] */
    (xdc_Char)0x73,  /* [1887] */
    (xdc_Char)0x20,  /* [1888] */
    (xdc_Char)0x61,  /* [1889] */
    (xdc_Char)0x20,  /* [1890] */
    (xdc_Char)0x6e,  /* [1891] */
    (xdc_Char)0x6f,  /* [1892] */
    (xdc_Char)0x6e,  /* [1893] */
    (xdc_Char)0x2d,  /* [1894] */
    (xdc_Char)0x7a,  /* [1895] */
    (xdc_Char)0x65,  /* [1896] */
    (xdc_Char)0x72,  /* [1897] */
    (xdc_Char)0x6f,  /* [1898] */
    (xdc_Char)0x20,  /* [1899] */
    (xdc_Char)0x43,  /* [1900] */
    (xdc_Char)0x6f,  /* [1901] */
    (xdc_Char)0x72,  /* [1902] */
    (xdc_Char)0x65,  /* [1903] */
    (xdc_Char)0x49,  /* [1904] */
    (xdc_Char)0x64,  /* [1905] */
    (xdc_Char)0x20,  /* [1906] */
    (xdc_Char)0x69,  /* [1907] */
    (xdc_Char)0x6e,  /* [1908] */
    (xdc_Char)0x20,  /* [1909] */
    (xdc_Char)0x61,  /* [1910] */
    (xdc_Char)0x20,  /* [1911] */
    (xdc_Char)0x6e,  /* [1912] */
    (xdc_Char)0x6f,  /* [1913] */
    (xdc_Char)0x6e,  /* [1914] */
    (xdc_Char)0x2d,  /* [1915] */
    (xdc_Char)0x53,  /* [1916] */
    (xdc_Char)0x4d,  /* [1917] */
    (xdc_Char)0x50,  /* [1918] */
    (xdc_Char)0x20,  /* [1919] */
    (xdc_Char)0x61,  /* [1920] */
    (xdc_Char)0x70,  /* [1921] */
    (xdc_Char)0x70,  /* [1922] */
    (xdc_Char)0x6c,  /* [1923] */
    (xdc_Char)0x69,  /* [1924] */
    (xdc_Char)0x63,  /* [1925] */
    (xdc_Char)0x61,  /* [1926] */
    (xdc_Char)0x74,  /* [1927] */
    (xdc_Char)0x69,  /* [1928] */
    (xdc_Char)0x6f,  /* [1929] */
    (xdc_Char)0x6e,  /* [1930] */
    (xdc_Char)0x2e,  /* [1931] */
    (xdc_Char)0x0,  /* [1932] */
    (xdc_Char)0x41,  /* [1933] */
    (xdc_Char)0x5f,  /* [1934] */
    (xdc_Char)0x75,  /* [1935] */
    (xdc_Char)0x6e,  /* [1936] */
    (xdc_Char)0x73,  /* [1937] */
    (xdc_Char)0x75,  /* [1938] */
    (xdc_Char)0x70,  /* [1939] */
    (xdc_Char)0x70,  /* [1940] */
    (xdc_Char)0x6f,  /* [1941] */
    (xdc_Char)0x72,  /* [1942] */
    (xdc_Char)0x74,  /* [1943] */
    (xdc_Char)0x65,  /* [1944] */
    (xdc_Char)0x64,  /* [1945] */
    (xdc_Char)0x4d,  /* [1946] */
    (xdc_Char)0x61,  /* [1947] */
    (xdc_Char)0x73,  /* [1948] */
    (xdc_Char)0x6b,  /* [1949] */
    (xdc_Char)0x69,  /* [1950] */
    (xdc_Char)0x6e,  /* [1951] */
    (xdc_Char)0x67,  /* [1952] */
    (xdc_Char)0x4f,  /* [1953] */
    (xdc_Char)0x70,  /* [1954] */
    (xdc_Char)0x74,  /* [1955] */
    (xdc_Char)0x69,  /* [1956] */
    (xdc_Char)0x6f,  /* [1957] */
    (xdc_Char)0x6e,  /* [1958] */
    (xdc_Char)0x3a,  /* [1959] */
    (xdc_Char)0x20,  /* [1960] */
    (xdc_Char)0x75,  /* [1961] */
    (xdc_Char)0x6e,  /* [1962] */
    (xdc_Char)0x73,  /* [1963] */
    (xdc_Char)0x75,  /* [1964] */
    (xdc_Char)0x70,  /* [1965] */
    (xdc_Char)0x70,  /* [1966] */
    (xdc_Char)0x6f,  /* [1967] */
    (xdc_Char)0x72,  /* [1968] */
    (xdc_Char)0x74,  /* [1969] */
    (xdc_Char)0x65,  /* [1970] */
    (xdc_Char)0x64,  /* [1971] */
    (xdc_Char)0x20,  /* [1972] */
    (xdc_Char)0x6d,  /* [1973] */
    (xdc_Char)0x61,  /* [1974] */
    (xdc_Char)0x73,  /* [1975] */
    (xdc_Char)0x6b,  /* [1976] */
    (xdc_Char)0x53,  /* [1977] */
    (xdc_Char)0x65,  /* [1978] */
    (xdc_Char)0x74,  /* [1979] */
    (xdc_Char)0x74,  /* [1980] */
    (xdc_Char)0x69,  /* [1981] */
    (xdc_Char)0x6e,  /* [1982] */
    (xdc_Char)0x67,  /* [1983] */
    (xdc_Char)0x2e,  /* [1984] */
    (xdc_Char)0x0,  /* [1985] */
    (xdc_Char)0x41,  /* [1986] */
    (xdc_Char)0x5f,  /* [1987] */
    (xdc_Char)0x62,  /* [1988] */
    (xdc_Char)0x61,  /* [1989] */
    (xdc_Char)0x64,  /* [1990] */
    (xdc_Char)0x45,  /* [1991] */
    (xdc_Char)0x76,  /* [1992] */
    (xdc_Char)0x65,  /* [1993] */
    (xdc_Char)0x58,  /* [1994] */
    (xdc_Char)0x62,  /* [1995] */
    (xdc_Char)0x61,  /* [1996] */
    (xdc_Char)0x72,  /* [1997] */
    (xdc_Char)0x49,  /* [1998] */
    (xdc_Char)0x6e,  /* [1999] */
    (xdc_Char)0x73,  /* [2000] */
    (xdc_Char)0x74,  /* [2001] */
    (xdc_Char)0x61,  /* [2002] */
    (xdc_Char)0x6e,  /* [2003] */
    (xdc_Char)0x63,  /* [2004] */
    (xdc_Char)0x65,  /* [2005] */
    (xdc_Char)0x4e,  /* [2006] */
    (xdc_Char)0x75,  /* [2007] */
    (xdc_Char)0x6d,  /* [2008] */
    (xdc_Char)0x3a,  /* [2009] */
    (xdc_Char)0x20,  /* [2010] */
    (xdc_Char)0x78,  /* [2011] */
    (xdc_Char)0x62,  /* [2012] */
    (xdc_Char)0x61,  /* [2013] */
    (xdc_Char)0x72,  /* [2014] */
    (xdc_Char)0x49,  /* [2015] */
    (xdc_Char)0x6e,  /* [2016] */
    (xdc_Char)0x73,  /* [2017] */
    (xdc_Char)0x74,  /* [2018] */
    (xdc_Char)0x61,  /* [2019] */
    (xdc_Char)0x6e,  /* [2020] */
    (xdc_Char)0x63,  /* [2021] */
    (xdc_Char)0x65,  /* [2022] */
    (xdc_Char)0x20,  /* [2023] */
    (xdc_Char)0x6d,  /* [2024] */
    (xdc_Char)0x75,  /* [2025] */
    (xdc_Char)0x73,  /* [2026] */
    (xdc_Char)0x74,  /* [2027] */
    (xdc_Char)0x20,  /* [2028] */
    (xdc_Char)0x62,  /* [2029] */
    (xdc_Char)0x65,  /* [2030] */
    (xdc_Char)0x20,  /* [2031] */
    (xdc_Char)0x3e,  /* [2032] */
    (xdc_Char)0x3d,  /* [2033] */
    (xdc_Char)0x20,  /* [2034] */
    (xdc_Char)0x31,  /* [2035] */
    (xdc_Char)0x20,  /* [2036] */
    (xdc_Char)0x61,  /* [2037] */
    (xdc_Char)0x6e,  /* [2038] */
    (xdc_Char)0x64,  /* [2039] */
    (xdc_Char)0x20,  /* [2040] */
    (xdc_Char)0x3c,  /* [2041] */
    (xdc_Char)0x3d,  /* [2042] */
    (xdc_Char)0x20,  /* [2043] */
    (xdc_Char)0x38,  /* [2044] */
    (xdc_Char)0x0,  /* [2045] */
    (xdc_Char)0x41,  /* [2046] */
    (xdc_Char)0x5f,  /* [2047] */
    (xdc_Char)0x62,  /* [2048] */
    (xdc_Char)0x61,  /* [2049] */
    (xdc_Char)0x64,  /* [2050] */
    (xdc_Char)0x44,  /* [2051] */
    (xdc_Char)0x73,  /* [2052] */
    (xdc_Char)0x70,  /* [2053] */
    (xdc_Char)0x58,  /* [2054] */
    (xdc_Char)0x62,  /* [2055] */
    (xdc_Char)0x61,  /* [2056] */
    (xdc_Char)0x72,  /* [2057] */
    (xdc_Char)0x49,  /* [2058] */
    (xdc_Char)0x6e,  /* [2059] */
    (xdc_Char)0x73,  /* [2060] */
    (xdc_Char)0x74,  /* [2061] */
    (xdc_Char)0x61,  /* [2062] */
    (xdc_Char)0x6e,  /* [2063] */
    (xdc_Char)0x63,  /* [2064] */
    (xdc_Char)0x65,  /* [2065] */
    (xdc_Char)0x4e,  /* [2066] */
    (xdc_Char)0x75,  /* [2067] */
    (xdc_Char)0x6d,  /* [2068] */
    (xdc_Char)0x3a,  /* [2069] */
    (xdc_Char)0x20,  /* [2070] */
    (xdc_Char)0x78,  /* [2071] */
    (xdc_Char)0x62,  /* [2072] */
    (xdc_Char)0x61,  /* [2073] */
    (xdc_Char)0x72,  /* [2074] */
    (xdc_Char)0x49,  /* [2075] */
    (xdc_Char)0x6e,  /* [2076] */
    (xdc_Char)0x73,  /* [2077] */
    (xdc_Char)0x74,  /* [2078] */
    (xdc_Char)0x61,  /* [2079] */
    (xdc_Char)0x6e,  /* [2080] */
    (xdc_Char)0x63,  /* [2081] */
    (xdc_Char)0x65,  /* [2082] */
    (xdc_Char)0x20,  /* [2083] */
    (xdc_Char)0x6d,  /* [2084] */
    (xdc_Char)0x75,  /* [2085] */
    (xdc_Char)0x73,  /* [2086] */
    (xdc_Char)0x74,  /* [2087] */
    (xdc_Char)0x20,  /* [2088] */
    (xdc_Char)0x62,  /* [2089] */
    (xdc_Char)0x65,  /* [2090] */
    (xdc_Char)0x20,  /* [2091] */
    (xdc_Char)0x3e,  /* [2092] */
    (xdc_Char)0x3d,  /* [2093] */
    (xdc_Char)0x20,  /* [2094] */
    (xdc_Char)0x31,  /* [2095] */
    (xdc_Char)0x20,  /* [2096] */
    (xdc_Char)0x61,  /* [2097] */
    (xdc_Char)0x6e,  /* [2098] */
    (xdc_Char)0x64,  /* [2099] */
    (xdc_Char)0x20,  /* [2100] */
    (xdc_Char)0x3c,  /* [2101] */
    (xdc_Char)0x3d,  /* [2102] */
    (xdc_Char)0x20,  /* [2103] */
    (xdc_Char)0x36,  /* [2104] */
    (xdc_Char)0x34,  /* [2105] */
    (xdc_Char)0x0,  /* [2106] */
    (xdc_Char)0x41,  /* [2107] */
    (xdc_Char)0x5f,  /* [2108] */
    (xdc_Char)0x62,  /* [2109] */
    (xdc_Char)0x61,  /* [2110] */
    (xdc_Char)0x64,  /* [2111] */
    (xdc_Char)0x42,  /* [2112] */
    (xdc_Char)0x65,  /* [2113] */
    (xdc_Char)0x6e,  /* [2114] */
    (xdc_Char)0x65,  /* [2115] */
    (xdc_Char)0x6c,  /* [2116] */
    (xdc_Char)0x6c,  /* [2117] */
    (xdc_Char)0x69,  /* [2118] */
    (xdc_Char)0x58,  /* [2119] */
    (xdc_Char)0x62,  /* [2120] */
    (xdc_Char)0x61,  /* [2121] */
    (xdc_Char)0x72,  /* [2122] */
    (xdc_Char)0x49,  /* [2123] */
    (xdc_Char)0x6e,  /* [2124] */
    (xdc_Char)0x73,  /* [2125] */
    (xdc_Char)0x74,  /* [2126] */
    (xdc_Char)0x61,  /* [2127] */
    (xdc_Char)0x6e,  /* [2128] */
    (xdc_Char)0x63,  /* [2129] */
    (xdc_Char)0x65,  /* [2130] */
    (xdc_Char)0x4e,  /* [2131] */
    (xdc_Char)0x75,  /* [2132] */
    (xdc_Char)0x6d,  /* [2133] */
    (xdc_Char)0x3a,  /* [2134] */
    (xdc_Char)0x20,  /* [2135] */
    (xdc_Char)0x78,  /* [2136] */
    (xdc_Char)0x62,  /* [2137] */
    (xdc_Char)0x61,  /* [2138] */
    (xdc_Char)0x72,  /* [2139] */
    (xdc_Char)0x49,  /* [2140] */
    (xdc_Char)0x6e,  /* [2141] */
    (xdc_Char)0x73,  /* [2142] */
    (xdc_Char)0x74,  /* [2143] */
    (xdc_Char)0x61,  /* [2144] */
    (xdc_Char)0x6e,  /* [2145] */
    (xdc_Char)0x63,  /* [2146] */
    (xdc_Char)0x65,  /* [2147] */
    (xdc_Char)0x20,  /* [2148] */
    (xdc_Char)0x6d,  /* [2149] */
    (xdc_Char)0x75,  /* [2150] */
    (xdc_Char)0x73,  /* [2151] */
    (xdc_Char)0x74,  /* [2152] */
    (xdc_Char)0x20,  /* [2153] */
    (xdc_Char)0x62,  /* [2154] */
    (xdc_Char)0x65,  /* [2155] */
    (xdc_Char)0x20,  /* [2156] */
    (xdc_Char)0x3e,  /* [2157] */
    (xdc_Char)0x3d,  /* [2158] */
    (xdc_Char)0x20,  /* [2159] */
    (xdc_Char)0x31,  /* [2160] */
    (xdc_Char)0x20,  /* [2161] */
    (xdc_Char)0x61,  /* [2162] */
    (xdc_Char)0x6e,  /* [2163] */
    (xdc_Char)0x64,  /* [2164] */
    (xdc_Char)0x20,  /* [2165] */
    (xdc_Char)0x3c,  /* [2166] */
    (xdc_Char)0x3d,  /* [2167] */
    (xdc_Char)0x20,  /* [2168] */
    (xdc_Char)0x35,  /* [2169] */
    (xdc_Char)0x37,  /* [2170] */
    (xdc_Char)0x0,  /* [2171] */
    (xdc_Char)0x41,  /* [2172] */
    (xdc_Char)0x5f,  /* [2173] */
    (xdc_Char)0x62,  /* [2174] */
    (xdc_Char)0x61,  /* [2175] */
    (xdc_Char)0x64,  /* [2176] */
    (xdc_Char)0x41,  /* [2177] */
    (xdc_Char)0x31,  /* [2178] */
    (xdc_Char)0x35,  /* [2179] */
    (xdc_Char)0x58,  /* [2180] */
    (xdc_Char)0x62,  /* [2181] */
    (xdc_Char)0x61,  /* [2182] */
    (xdc_Char)0x72,  /* [2183] */
    (xdc_Char)0x49,  /* [2184] */
    (xdc_Char)0x6e,  /* [2185] */
    (xdc_Char)0x73,  /* [2186] */
    (xdc_Char)0x74,  /* [2187] */
    (xdc_Char)0x61,  /* [2188] */
    (xdc_Char)0x6e,  /* [2189] */
    (xdc_Char)0x63,  /* [2190] */
    (xdc_Char)0x65,  /* [2191] */
    (xdc_Char)0x4e,  /* [2192] */
    (xdc_Char)0x75,  /* [2193] */
    (xdc_Char)0x6d,  /* [2194] */
    (xdc_Char)0x3a,  /* [2195] */
    (xdc_Char)0x20,  /* [2196] */
    (xdc_Char)0x78,  /* [2197] */
    (xdc_Char)0x62,  /* [2198] */
    (xdc_Char)0x61,  /* [2199] */
    (xdc_Char)0x72,  /* [2200] */
    (xdc_Char)0x49,  /* [2201] */
    (xdc_Char)0x6e,  /* [2202] */
    (xdc_Char)0x73,  /* [2203] */
    (xdc_Char)0x74,  /* [2204] */
    (xdc_Char)0x61,  /* [2205] */
    (xdc_Char)0x6e,  /* [2206] */
    (xdc_Char)0x63,  /* [2207] */
    (xdc_Char)0x65,  /* [2208] */
    (xdc_Char)0x20,  /* [2209] */
    (xdc_Char)0x6d,  /* [2210] */
    (xdc_Char)0x75,  /* [2211] */
    (xdc_Char)0x73,  /* [2212] */
    (xdc_Char)0x74,  /* [2213] */
    (xdc_Char)0x20,  /* [2214] */
    (xdc_Char)0x62,  /* [2215] */
    (xdc_Char)0x65,  /* [2216] */
    (xdc_Char)0x20,  /* [2217] */
    (xdc_Char)0x3e,  /* [2218] */
    (xdc_Char)0x3d,  /* [2219] */
    (xdc_Char)0x20,  /* [2220] */
    (xdc_Char)0x31,  /* [2221] */
    (xdc_Char)0x20,  /* [2222] */
    (xdc_Char)0x61,  /* [2223] */
    (xdc_Char)0x6e,  /* [2224] */
    (xdc_Char)0x64,  /* [2225] */
    (xdc_Char)0x20,  /* [2226] */
    (xdc_Char)0x3c,  /* [2227] */
    (xdc_Char)0x3d,  /* [2228] */
    (xdc_Char)0x20,  /* [2229] */
    (xdc_Char)0x31,  /* [2230] */
    (xdc_Char)0x35,  /* [2231] */
    (xdc_Char)0x32,  /* [2232] */
    (xdc_Char)0x0,  /* [2233] */
    (xdc_Char)0x41,  /* [2234] */
    (xdc_Char)0x5f,  /* [2235] */
    (xdc_Char)0x62,  /* [2236] */
    (xdc_Char)0x61,  /* [2237] */
    (xdc_Char)0x64,  /* [2238] */
    (xdc_Char)0x45,  /* [2239] */
    (xdc_Char)0x76,  /* [2240] */
    (xdc_Char)0x65,  /* [2241] */
    (xdc_Char)0x49,  /* [2242] */
    (xdc_Char)0x52,  /* [2243] */
    (xdc_Char)0x51,  /* [2244] */
    (xdc_Char)0x4e,  /* [2245] */
    (xdc_Char)0x75,  /* [2246] */
    (xdc_Char)0x6d,  /* [2247] */
    (xdc_Char)0x3a,  /* [2248] */
    (xdc_Char)0x20,  /* [2249] */
    (xdc_Char)0x49,  /* [2250] */
    (xdc_Char)0x52,  /* [2251] */
    (xdc_Char)0x51,  /* [2252] */
    (xdc_Char)0x20,  /* [2253] */
    (xdc_Char)0x6e,  /* [2254] */
    (xdc_Char)0x75,  /* [2255] */
    (xdc_Char)0x6d,  /* [2256] */
    (xdc_Char)0x62,  /* [2257] */
    (xdc_Char)0x65,  /* [2258] */
    (xdc_Char)0x72,  /* [2259] */
    (xdc_Char)0x20,  /* [2260] */
    (xdc_Char)0x6d,  /* [2261] */
    (xdc_Char)0x75,  /* [2262] */
    (xdc_Char)0x73,  /* [2263] */
    (xdc_Char)0x74,  /* [2264] */
    (xdc_Char)0x20,  /* [2265] */
    (xdc_Char)0x62,  /* [2266] */
    (xdc_Char)0x65,  /* [2267] */
    (xdc_Char)0x20,  /* [2268] */
    (xdc_Char)0x3c,  /* [2269] */
    (xdc_Char)0x3d,  /* [2270] */
    (xdc_Char)0x20,  /* [2271] */
    (xdc_Char)0x37,  /* [2272] */
    (xdc_Char)0x0,  /* [2273] */
    (xdc_Char)0x41,  /* [2274] */
    (xdc_Char)0x5f,  /* [2275] */
    (xdc_Char)0x62,  /* [2276] */
    (xdc_Char)0x61,  /* [2277] */
    (xdc_Char)0x64,  /* [2278] */
    (xdc_Char)0x44,  /* [2279] */
    (xdc_Char)0x73,  /* [2280] */
    (xdc_Char)0x70,  /* [2281] */
    (xdc_Char)0x49,  /* [2282] */
    (xdc_Char)0x52,  /* [2283] */
    (xdc_Char)0x51,  /* [2284] */
    (xdc_Char)0x4e,  /* [2285] */
    (xdc_Char)0x75,  /* [2286] */
    (xdc_Char)0x6d,  /* [2287] */
    (xdc_Char)0x3a,  /* [2288] */
    (xdc_Char)0x20,  /* [2289] */
    (xdc_Char)0x49,  /* [2290] */
    (xdc_Char)0x52,  /* [2291] */
    (xdc_Char)0x51,  /* [2292] */
    (xdc_Char)0x20,  /* [2293] */
    (xdc_Char)0x6e,  /* [2294] */
    (xdc_Char)0x75,  /* [2295] */
    (xdc_Char)0x6d,  /* [2296] */
    (xdc_Char)0x62,  /* [2297] */
    (xdc_Char)0x65,  /* [2298] */
    (xdc_Char)0x72,  /* [2299] */
    (xdc_Char)0x20,  /* [2300] */
    (xdc_Char)0x6d,  /* [2301] */
    (xdc_Char)0x75,  /* [2302] */
    (xdc_Char)0x73,  /* [2303] */
    (xdc_Char)0x74,  /* [2304] */
    (xdc_Char)0x20,  /* [2305] */
    (xdc_Char)0x62,  /* [2306] */
    (xdc_Char)0x65,  /* [2307] */
    (xdc_Char)0x20,  /* [2308] */
    (xdc_Char)0x3e,  /* [2309] */
    (xdc_Char)0x3d,  /* [2310] */
    (xdc_Char)0x20,  /* [2311] */
    (xdc_Char)0x33,  /* [2312] */
    (xdc_Char)0x32,  /* [2313] */
    (xdc_Char)0x20,  /* [2314] */
    (xdc_Char)0x61,  /* [2315] */
    (xdc_Char)0x6e,  /* [2316] */
    (xdc_Char)0x64,  /* [2317] */
    (xdc_Char)0x20,  /* [2318] */
    (xdc_Char)0x3c,  /* [2319] */
    (xdc_Char)0x3d,  /* [2320] */
    (xdc_Char)0x20,  /* [2321] */
    (xdc_Char)0x39,  /* [2322] */
    (xdc_Char)0x35,  /* [2323] */
    (xdc_Char)0x0,  /* [2324] */
    (xdc_Char)0x41,  /* [2325] */
    (xdc_Char)0x5f,  /* [2326] */
    (xdc_Char)0x62,  /* [2327] */
    (xdc_Char)0x61,  /* [2328] */
    (xdc_Char)0x64,  /* [2329] */
    (xdc_Char)0x42,  /* [2330] */
    (xdc_Char)0x65,  /* [2331] */
    (xdc_Char)0x6e,  /* [2332] */
    (xdc_Char)0x65,  /* [2333] */
    (xdc_Char)0x6c,  /* [2334] */
    (xdc_Char)0x6c,  /* [2335] */
    (xdc_Char)0x69,  /* [2336] */
    (xdc_Char)0x49,  /* [2337] */
    (xdc_Char)0x52,  /* [2338] */
    (xdc_Char)0x51,  /* [2339] */
    (xdc_Char)0x4e,  /* [2340] */
    (xdc_Char)0x75,  /* [2341] */
    (xdc_Char)0x6d,  /* [2342] */
    (xdc_Char)0x3a,  /* [2343] */
    (xdc_Char)0x20,  /* [2344] */
    (xdc_Char)0x49,  /* [2345] */
    (xdc_Char)0x52,  /* [2346] */
    (xdc_Char)0x51,  /* [2347] */
    (xdc_Char)0x20,  /* [2348] */
    (xdc_Char)0x6e,  /* [2349] */
    (xdc_Char)0x75,  /* [2350] */
    (xdc_Char)0x6d,  /* [2351] */
    (xdc_Char)0x62,  /* [2352] */
    (xdc_Char)0x65,  /* [2353] */
    (xdc_Char)0x72,  /* [2354] */
    (xdc_Char)0x20,  /* [2355] */
    (xdc_Char)0x6d,  /* [2356] */
    (xdc_Char)0x75,  /* [2357] */
    (xdc_Char)0x73,  /* [2358] */
    (xdc_Char)0x74,  /* [2359] */
    (xdc_Char)0x20,  /* [2360] */
    (xdc_Char)0x62,  /* [2361] */
    (xdc_Char)0x65,  /* [2362] */
    (xdc_Char)0x20,  /* [2363] */
    (xdc_Char)0x3e,  /* [2364] */
    (xdc_Char)0x3d,  /* [2365] */
    (xdc_Char)0x20,  /* [2366] */
    (xdc_Char)0x32,  /* [2367] */
    (xdc_Char)0x33,  /* [2368] */
    (xdc_Char)0x20,  /* [2369] */
    (xdc_Char)0x61,  /* [2370] */
    (xdc_Char)0x6e,  /* [2371] */
    (xdc_Char)0x64,  /* [2372] */
    (xdc_Char)0x20,  /* [2373] */
    (xdc_Char)0x3c,  /* [2374] */
    (xdc_Char)0x3d,  /* [2375] */
    (xdc_Char)0x20,  /* [2376] */
    (xdc_Char)0x37,  /* [2377] */
    (xdc_Char)0x39,  /* [2378] */
    (xdc_Char)0x0,  /* [2379] */
    (xdc_Char)0x41,  /* [2380] */
    (xdc_Char)0x5f,  /* [2381] */
    (xdc_Char)0x62,  /* [2382] */
    (xdc_Char)0x61,  /* [2383] */
    (xdc_Char)0x64,  /* [2384] */
    (xdc_Char)0x41,  /* [2385] */
    (xdc_Char)0x31,  /* [2386] */
    (xdc_Char)0x35,  /* [2387] */
    (xdc_Char)0x49,  /* [2388] */
    (xdc_Char)0x52,  /* [2389] */
    (xdc_Char)0x51,  /* [2390] */
    (xdc_Char)0x4e,  /* [2391] */
    (xdc_Char)0x75,  /* [2392] */
    (xdc_Char)0x6d,  /* [2393] */
    (xdc_Char)0x3a,  /* [2394] */
    (xdc_Char)0x20,  /* [2395] */
    (xdc_Char)0x4e,  /* [2396] */
    (xdc_Char)0x6f,  /* [2397] */
    (xdc_Char)0x20,  /* [2398] */
    (xdc_Char)0x58,  /* [2399] */
    (xdc_Char)0x42,  /* [2400] */
    (xdc_Char)0x41,  /* [2401] */
    (xdc_Char)0x52,  /* [2402] */
    (xdc_Char)0x20,  /* [2403] */
    (xdc_Char)0x69,  /* [2404] */
    (xdc_Char)0x6e,  /* [2405] */
    (xdc_Char)0x73,  /* [2406] */
    (xdc_Char)0x74,  /* [2407] */
    (xdc_Char)0x61,  /* [2408] */
    (xdc_Char)0x6e,  /* [2409] */
    (xdc_Char)0x63,  /* [2410] */
    (xdc_Char)0x65,  /* [2411] */
    (xdc_Char)0x20,  /* [2412] */
    (xdc_Char)0x63,  /* [2413] */
    (xdc_Char)0x6f,  /* [2414] */
    (xdc_Char)0x72,  /* [2415] */
    (xdc_Char)0x72,  /* [2416] */
    (xdc_Char)0x65,  /* [2417] */
    (xdc_Char)0x73,  /* [2418] */
    (xdc_Char)0x70,  /* [2419] */
    (xdc_Char)0x6f,  /* [2420] */
    (xdc_Char)0x6e,  /* [2421] */
    (xdc_Char)0x64,  /* [2422] */
    (xdc_Char)0x69,  /* [2423] */
    (xdc_Char)0x6e,  /* [2424] */
    (xdc_Char)0x67,  /* [2425] */
    (xdc_Char)0x20,  /* [2426] */
    (xdc_Char)0x74,  /* [2427] */
    (xdc_Char)0x6f,  /* [2428] */
    (xdc_Char)0x20,  /* [2429] */
    (xdc_Char)0x67,  /* [2430] */
    (xdc_Char)0x69,  /* [2431] */
    (xdc_Char)0x76,  /* [2432] */
    (xdc_Char)0x65,  /* [2433] */
    (xdc_Char)0x6e,  /* [2434] */
    (xdc_Char)0x20,  /* [2435] */
    (xdc_Char)0x49,  /* [2436] */
    (xdc_Char)0x52,  /* [2437] */
    (xdc_Char)0x51,  /* [2438] */
    (xdc_Char)0x20,  /* [2439] */
    (xdc_Char)0x6e,  /* [2440] */
    (xdc_Char)0x75,  /* [2441] */
    (xdc_Char)0x6d,  /* [2442] */
    (xdc_Char)0x0,  /* [2443] */
    (xdc_Char)0x41,  /* [2444] */
    (xdc_Char)0x5f,  /* [2445] */
    (xdc_Char)0x62,  /* [2446] */
    (xdc_Char)0x61,  /* [2447] */
    (xdc_Char)0x64,  /* [2448] */
    (xdc_Char)0x49,  /* [2449] */
    (xdc_Char)0x6e,  /* [2450] */
    (xdc_Char)0x74,  /* [2451] */
    (xdc_Char)0x53,  /* [2452] */
    (xdc_Char)0x6f,  /* [2453] */
    (xdc_Char)0x75,  /* [2454] */
    (xdc_Char)0x72,  /* [2455] */
    (xdc_Char)0x63,  /* [2456] */
    (xdc_Char)0x65,  /* [2457] */
    (xdc_Char)0x49,  /* [2458] */
    (xdc_Char)0x64,  /* [2459] */
    (xdc_Char)0x78,  /* [2460] */
    (xdc_Char)0x3a,  /* [2461] */
    (xdc_Char)0x20,  /* [2462] */
    (xdc_Char)0x49,  /* [2463] */
    (xdc_Char)0x52,  /* [2464] */
    (xdc_Char)0x51,  /* [2465] */
    (xdc_Char)0x20,  /* [2466] */
    (xdc_Char)0x63,  /* [2467] */
    (xdc_Char)0x72,  /* [2468] */
    (xdc_Char)0x6f,  /* [2469] */
    (xdc_Char)0x73,  /* [2470] */
    (xdc_Char)0x73,  /* [2471] */
    (xdc_Char)0x62,  /* [2472] */
    (xdc_Char)0x61,  /* [2473] */
    (xdc_Char)0x72,  /* [2474] */
    (xdc_Char)0x20,  /* [2475] */
    (xdc_Char)0x69,  /* [2476] */
    (xdc_Char)0x6e,  /* [2477] */
    (xdc_Char)0x70,  /* [2478] */
    (xdc_Char)0x75,  /* [2479] */
    (xdc_Char)0x74,  /* [2480] */
    (xdc_Char)0x20,  /* [2481] */
    (xdc_Char)0x69,  /* [2482] */
    (xdc_Char)0x6e,  /* [2483] */
    (xdc_Char)0x64,  /* [2484] */
    (xdc_Char)0x65,  /* [2485] */
    (xdc_Char)0x78,  /* [2486] */
    (xdc_Char)0x20,  /* [2487] */
    (xdc_Char)0x28,  /* [2488] */
    (xdc_Char)0x69,  /* [2489] */
    (xdc_Char)0x6e,  /* [2490] */
    (xdc_Char)0x74,  /* [2491] */
    (xdc_Char)0x53,  /* [2492] */
    (xdc_Char)0x6f,  /* [2493] */
    (xdc_Char)0x75,  /* [2494] */
    (xdc_Char)0x72,  /* [2495] */
    (xdc_Char)0x63,  /* [2496] */
    (xdc_Char)0x65,  /* [2497] */
    (xdc_Char)0x29,  /* [2498] */
    (xdc_Char)0x20,  /* [2499] */
    (xdc_Char)0x6f,  /* [2500] */
    (xdc_Char)0x75,  /* [2501] */
    (xdc_Char)0x74,  /* [2502] */
    (xdc_Char)0x20,  /* [2503] */
    (xdc_Char)0x6f,  /* [2504] */
    (xdc_Char)0x66,  /* [2505] */
    (xdc_Char)0x20,  /* [2506] */
    (xdc_Char)0x72,  /* [2507] */
    (xdc_Char)0x61,  /* [2508] */
    (xdc_Char)0x6e,  /* [2509] */
    (xdc_Char)0x67,  /* [2510] */
    (xdc_Char)0x65,  /* [2511] */
    (xdc_Char)0x2e,  /* [2512] */
    (xdc_Char)0x0,  /* [2513] */
    (xdc_Char)0x41,  /* [2514] */
    (xdc_Char)0x5f,  /* [2515] */
    (xdc_Char)0x62,  /* [2516] */
    (xdc_Char)0x61,  /* [2517] */
    (xdc_Char)0x64,  /* [2518] */
    (xdc_Char)0x45,  /* [2519] */
    (xdc_Char)0x76,  /* [2520] */
    (xdc_Char)0x65,  /* [2521] */
    (xdc_Char)0x43,  /* [2522] */
    (xdc_Char)0x70,  /* [2523] */
    (xdc_Char)0x75,  /* [2524] */
    (xdc_Char)0x49,  /* [2525] */
    (xdc_Char)0x64,  /* [2526] */
    (xdc_Char)0x3a,  /* [2527] */
    (xdc_Char)0x20,  /* [2528] */
    (xdc_Char)0x43,  /* [2529] */
    (xdc_Char)0x50,  /* [2530] */
    (xdc_Char)0x55,  /* [2531] */
    (xdc_Char)0x20,  /* [2532] */
    (xdc_Char)0x49,  /* [2533] */
    (xdc_Char)0x64,  /* [2534] */
    (xdc_Char)0x20,  /* [2535] */
    (xdc_Char)0x6d,  /* [2536] */
    (xdc_Char)0x75,  /* [2537] */
    (xdc_Char)0x73,  /* [2538] */
    (xdc_Char)0x74,  /* [2539] */
    (xdc_Char)0x20,  /* [2540] */
    (xdc_Char)0x62,  /* [2541] */
    (xdc_Char)0x65,  /* [2542] */
    (xdc_Char)0x20,  /* [2543] */
    (xdc_Char)0x30,  /* [2544] */
    (xdc_Char)0x2c,  /* [2545] */
    (xdc_Char)0x20,  /* [2546] */
    (xdc_Char)0x31,  /* [2547] */
    (xdc_Char)0x2c,  /* [2548] */
    (xdc_Char)0x20,  /* [2549] */
    (xdc_Char)0x32,  /* [2550] */
    (xdc_Char)0x20,  /* [2551] */
    (xdc_Char)0x6f,  /* [2552] */
    (xdc_Char)0x72,  /* [2553] */
    (xdc_Char)0x20,  /* [2554] */
    (xdc_Char)0x33,  /* [2555] */
    (xdc_Char)0x0,  /* [2556] */
    (xdc_Char)0x41,  /* [2557] */
    (xdc_Char)0x5f,  /* [2558] */
    (xdc_Char)0x62,  /* [2559] */
    (xdc_Char)0x61,  /* [2560] */
    (xdc_Char)0x64,  /* [2561] */
    (xdc_Char)0x44,  /* [2562] */
    (xdc_Char)0x73,  /* [2563] */
    (xdc_Char)0x70,  /* [2564] */
    (xdc_Char)0x43,  /* [2565] */
    (xdc_Char)0x70,  /* [2566] */
    (xdc_Char)0x75,  /* [2567] */
    (xdc_Char)0x49,  /* [2568] */
    (xdc_Char)0x64,  /* [2569] */
    (xdc_Char)0x3a,  /* [2570] */
    (xdc_Char)0x20,  /* [2571] */
    (xdc_Char)0x43,  /* [2572] */
    (xdc_Char)0x50,  /* [2573] */
    (xdc_Char)0x55,  /* [2574] */
    (xdc_Char)0x20,  /* [2575] */
    (xdc_Char)0x49,  /* [2576] */
    (xdc_Char)0x64,  /* [2577] */
    (xdc_Char)0x20,  /* [2578] */
    (xdc_Char)0x6d,  /* [2579] */
    (xdc_Char)0x75,  /* [2580] */
    (xdc_Char)0x73,  /* [2581] */
    (xdc_Char)0x74,  /* [2582] */
    (xdc_Char)0x20,  /* [2583] */
    (xdc_Char)0x62,  /* [2584] */
    (xdc_Char)0x65,  /* [2585] */
    (xdc_Char)0x20,  /* [2586] */
    (xdc_Char)0x30,  /* [2587] */
    (xdc_Char)0x20,  /* [2588] */
    (xdc_Char)0x6f,  /* [2589] */
    (xdc_Char)0x72,  /* [2590] */
    (xdc_Char)0x20,  /* [2591] */
    (xdc_Char)0x31,  /* [2592] */
    (xdc_Char)0x0,  /* [2593] */
    (xdc_Char)0x41,  /* [2594] */
    (xdc_Char)0x5f,  /* [2595] */
    (xdc_Char)0x62,  /* [2596] */
    (xdc_Char)0x61,  /* [2597] */
    (xdc_Char)0x64,  /* [2598] */
    (xdc_Char)0x42,  /* [2599] */
    (xdc_Char)0x65,  /* [2600] */
    (xdc_Char)0x6e,  /* [2601] */
    (xdc_Char)0x65,  /* [2602] */
    (xdc_Char)0x6c,  /* [2603] */
    (xdc_Char)0x6c,  /* [2604] */
    (xdc_Char)0x69,  /* [2605] */
    (xdc_Char)0x49,  /* [2606] */
    (xdc_Char)0x70,  /* [2607] */
    (xdc_Char)0x75,  /* [2608] */
    (xdc_Char)0x49,  /* [2609] */
    (xdc_Char)0x64,  /* [2610] */
    (xdc_Char)0x3a,  /* [2611] */
    (xdc_Char)0x20,  /* [2612] */
    (xdc_Char)0x49,  /* [2613] */
    (xdc_Char)0x70,  /* [2614] */
    (xdc_Char)0x75,  /* [2615] */
    (xdc_Char)0x20,  /* [2616] */
    (xdc_Char)0x49,  /* [2617] */
    (xdc_Char)0x64,  /* [2618] */
    (xdc_Char)0x20,  /* [2619] */
    (xdc_Char)0x6d,  /* [2620] */
    (xdc_Char)0x75,  /* [2621] */
    (xdc_Char)0x73,  /* [2622] */
    (xdc_Char)0x74,  /* [2623] */
    (xdc_Char)0x20,  /* [2624] */
    (xdc_Char)0x62,  /* [2625] */
    (xdc_Char)0x65,  /* [2626] */
    (xdc_Char)0x20,  /* [2627] */
    (xdc_Char)0x31,  /* [2628] */
    (xdc_Char)0x20,  /* [2629] */
    (xdc_Char)0x6f,  /* [2630] */
    (xdc_Char)0x72,  /* [2631] */
    (xdc_Char)0x20,  /* [2632] */
    (xdc_Char)0x32,  /* [2633] */
    (xdc_Char)0x0,  /* [2634] */
    (xdc_Char)0x41,  /* [2635] */
    (xdc_Char)0x5f,  /* [2636] */
    (xdc_Char)0x75,  /* [2637] */
    (xdc_Char)0x6e,  /* [2638] */
    (xdc_Char)0x6b,  /* [2639] */
    (xdc_Char)0x6e,  /* [2640] */
    (xdc_Char)0x6f,  /* [2641] */
    (xdc_Char)0x77,  /* [2642] */
    (xdc_Char)0x6e,  /* [2643] */
    (xdc_Char)0x44,  /* [2644] */
    (xdc_Char)0x65,  /* [2645] */
    (xdc_Char)0x73,  /* [2646] */
    (xdc_Char)0x63,  /* [2647] */
    (xdc_Char)0x54,  /* [2648] */
    (xdc_Char)0x79,  /* [2649] */
    (xdc_Char)0x70,  /* [2650] */
    (xdc_Char)0x65,  /* [2651] */
    (xdc_Char)0x3a,  /* [2652] */
    (xdc_Char)0x20,  /* [2653] */
    (xdc_Char)0x44,  /* [2654] */
    (xdc_Char)0x65,  /* [2655] */
    (xdc_Char)0x73,  /* [2656] */
    (xdc_Char)0x63,  /* [2657] */
    (xdc_Char)0x72,  /* [2658] */
    (xdc_Char)0x69,  /* [2659] */
    (xdc_Char)0x70,  /* [2660] */
    (xdc_Char)0x74,  /* [2661] */
    (xdc_Char)0x6f,  /* [2662] */
    (xdc_Char)0x72,  /* [2663] */
    (xdc_Char)0x20,  /* [2664] */
    (xdc_Char)0x74,  /* [2665] */
    (xdc_Char)0x79,  /* [2666] */
    (xdc_Char)0x70,  /* [2667] */
    (xdc_Char)0x65,  /* [2668] */
    (xdc_Char)0x20,  /* [2669] */
    (xdc_Char)0x69,  /* [2670] */
    (xdc_Char)0x73,  /* [2671] */
    (xdc_Char)0x20,  /* [2672] */
    (xdc_Char)0x6e,  /* [2673] */
    (xdc_Char)0x6f,  /* [2674] */
    (xdc_Char)0x74,  /* [2675] */
    (xdc_Char)0x20,  /* [2676] */
    (xdc_Char)0x72,  /* [2677] */
    (xdc_Char)0x65,  /* [2678] */
    (xdc_Char)0x63,  /* [2679] */
    (xdc_Char)0x6f,  /* [2680] */
    (xdc_Char)0x67,  /* [2681] */
    (xdc_Char)0x6e,  /* [2682] */
    (xdc_Char)0x69,  /* [2683] */
    (xdc_Char)0x7a,  /* [2684] */
    (xdc_Char)0x65,  /* [2685] */
    (xdc_Char)0x64,  /* [2686] */
    (xdc_Char)0x0,  /* [2687] */
    (xdc_Char)0x41,  /* [2688] */
    (xdc_Char)0x5f,  /* [2689] */
    (xdc_Char)0x62,  /* [2690] */
    (xdc_Char)0x61,  /* [2691] */
    (xdc_Char)0x73,  /* [2692] */
    (xdc_Char)0x65,  /* [2693] */
    (xdc_Char)0x56,  /* [2694] */
    (xdc_Char)0x61,  /* [2695] */
    (xdc_Char)0x6c,  /* [2696] */
    (xdc_Char)0x75,  /* [2697] */
    (xdc_Char)0x65,  /* [2698] */
    (xdc_Char)0x4f,  /* [2699] */
    (xdc_Char)0x75,  /* [2700] */
    (xdc_Char)0x74,  /* [2701] */
    (xdc_Char)0x4f,  /* [2702] */
    (xdc_Char)0x66,  /* [2703] */
    (xdc_Char)0x52,  /* [2704] */
    (xdc_Char)0x61,  /* [2705] */
    (xdc_Char)0x6e,  /* [2706] */
    (xdc_Char)0x67,  /* [2707] */
    (xdc_Char)0x65,  /* [2708] */
    (xdc_Char)0x3a,  /* [2709] */
    (xdc_Char)0x20,  /* [2710] */
    (xdc_Char)0x54,  /* [2711] */
    (xdc_Char)0x4c,  /* [2712] */
    (xdc_Char)0x42,  /* [2713] */
    (xdc_Char)0x20,  /* [2714] */
    (xdc_Char)0x6c,  /* [2715] */
    (xdc_Char)0x6f,  /* [2716] */
    (xdc_Char)0x63,  /* [2717] */
    (xdc_Char)0x6b,  /* [2718] */
    (xdc_Char)0x20,  /* [2719] */
    (xdc_Char)0x65,  /* [2720] */
    (xdc_Char)0x6e,  /* [2721] */
    (xdc_Char)0x74,  /* [2722] */
    (xdc_Char)0x72,  /* [2723] */
    (xdc_Char)0x69,  /* [2724] */
    (xdc_Char)0x65,  /* [2725] */
    (xdc_Char)0x73,  /* [2726] */
    (xdc_Char)0x20,  /* [2727] */
    (xdc_Char)0x62,  /* [2728] */
    (xdc_Char)0x61,  /* [2729] */
    (xdc_Char)0x73,  /* [2730] */
    (xdc_Char)0x65,  /* [2731] */
    (xdc_Char)0x20,  /* [2732] */
    (xdc_Char)0x76,  /* [2733] */
    (xdc_Char)0x61,  /* [2734] */
    (xdc_Char)0x6c,  /* [2735] */
    (xdc_Char)0x75,  /* [2736] */
    (xdc_Char)0x65,  /* [2737] */
    (xdc_Char)0x20,  /* [2738] */
    (xdc_Char)0x6f,  /* [2739] */
    (xdc_Char)0x75,  /* [2740] */
    (xdc_Char)0x74,  /* [2741] */
    (xdc_Char)0x20,  /* [2742] */
    (xdc_Char)0x6f,  /* [2743] */
    (xdc_Char)0x66,  /* [2744] */
    (xdc_Char)0x20,  /* [2745] */
    (xdc_Char)0x72,  /* [2746] */
    (xdc_Char)0x61,  /* [2747] */
    (xdc_Char)0x6e,  /* [2748] */
    (xdc_Char)0x67,  /* [2749] */
    (xdc_Char)0x65,  /* [2750] */
    (xdc_Char)0x0,  /* [2751] */
    (xdc_Char)0x41,  /* [2752] */
    (xdc_Char)0x5f,  /* [2753] */
    (xdc_Char)0x6e,  /* [2754] */
    (xdc_Char)0x65,  /* [2755] */
    (xdc_Char)0x73,  /* [2756] */
    (xdc_Char)0x74,  /* [2757] */
    (xdc_Char)0x65,  /* [2758] */
    (xdc_Char)0x64,  /* [2759] */
    (xdc_Char)0x45,  /* [2760] */
    (xdc_Char)0x6e,  /* [2761] */
    (xdc_Char)0x74,  /* [2762] */
    (xdc_Char)0x65,  /* [2763] */
    (xdc_Char)0x72,  /* [2764] */
    (xdc_Char)0x3a,  /* [2765] */
    (xdc_Char)0x20,  /* [2766] */
    (xdc_Char)0x43,  /* [2767] */
    (xdc_Char)0x61,  /* [2768] */
    (xdc_Char)0x6e,  /* [2769] */
    (xdc_Char)0x27,  /* [2770] */
    (xdc_Char)0x74,  /* [2771] */
    (xdc_Char)0x20,  /* [2772] */
    (xdc_Char)0x6e,  /* [2773] */
    (xdc_Char)0x65,  /* [2774] */
    (xdc_Char)0x73,  /* [2775] */
    (xdc_Char)0x74,  /* [2776] */
    (xdc_Char)0x20,  /* [2777] */
    (xdc_Char)0x27,  /* [2778] */
    (xdc_Char)0x65,  /* [2779] */
    (xdc_Char)0x6e,  /* [2780] */
    (xdc_Char)0x74,  /* [2781] */
    (xdc_Char)0x65,  /* [2782] */
    (xdc_Char)0x72,  /* [2783] */
    (xdc_Char)0x27,  /* [2784] */
    (xdc_Char)0x20,  /* [2785] */
    (xdc_Char)0x63,  /* [2786] */
    (xdc_Char)0x61,  /* [2787] */
    (xdc_Char)0x6c,  /* [2788] */
    (xdc_Char)0x6c,  /* [2789] */
    (xdc_Char)0x73,  /* [2790] */
    (xdc_Char)0x2e,  /* [2791] */
    (xdc_Char)0x0,  /* [2792] */
    (xdc_Char)0x41,  /* [2793] */
    (xdc_Char)0x5f,  /* [2794] */
    (xdc_Char)0x7a,  /* [2795] */
    (xdc_Char)0x65,  /* [2796] */
    (xdc_Char)0x72,  /* [2797] */
    (xdc_Char)0x6f,  /* [2798] */
    (xdc_Char)0x54,  /* [2799] */
    (xdc_Char)0x69,  /* [2800] */
    (xdc_Char)0x6d,  /* [2801] */
    (xdc_Char)0x65,  /* [2802] */
    (xdc_Char)0x6f,  /* [2803] */
    (xdc_Char)0x75,  /* [2804] */
    (xdc_Char)0x74,  /* [2805] */
    (xdc_Char)0x3a,  /* [2806] */
    (xdc_Char)0x20,  /* [2807] */
    (xdc_Char)0x54,  /* [2808] */
    (xdc_Char)0x69,  /* [2809] */
    (xdc_Char)0x6d,  /* [2810] */
    (xdc_Char)0x65,  /* [2811] */
    (xdc_Char)0x6f,  /* [2812] */
    (xdc_Char)0x75,  /* [2813] */
    (xdc_Char)0x74,  /* [2814] */
    (xdc_Char)0x20,  /* [2815] */
    (xdc_Char)0x76,  /* [2816] */
    (xdc_Char)0x61,  /* [2817] */
    (xdc_Char)0x6c,  /* [2818] */
    (xdc_Char)0x75,  /* [2819] */
    (xdc_Char)0x65,  /* [2820] */
    (xdc_Char)0x20,  /* [2821] */
    (xdc_Char)0x61,  /* [2822] */
    (xdc_Char)0x6e,  /* [2823] */
    (xdc_Char)0x6e,  /* [2824] */
    (xdc_Char)0x6f,  /* [2825] */
    (xdc_Char)0x74,  /* [2826] */
    (xdc_Char)0x20,  /* [2827] */
    (xdc_Char)0x62,  /* [2828] */
    (xdc_Char)0x65,  /* [2829] */
    (xdc_Char)0x20,  /* [2830] */
    (xdc_Char)0x7a,  /* [2831] */
    (xdc_Char)0x65,  /* [2832] */
    (xdc_Char)0x72,  /* [2833] */
    (xdc_Char)0x6f,  /* [2834] */
    (xdc_Char)0x0,  /* [2835] */
    (xdc_Char)0x41,  /* [2836] */
    (xdc_Char)0x5f,  /* [2837] */
    (xdc_Char)0x69,  /* [2838] */
    (xdc_Char)0x6e,  /* [2839] */
    (xdc_Char)0x76,  /* [2840] */
    (xdc_Char)0x61,  /* [2841] */
    (xdc_Char)0x6c,  /* [2842] */
    (xdc_Char)0x69,  /* [2843] */
    (xdc_Char)0x64,  /* [2844] */
    (xdc_Char)0x4b,  /* [2845] */
    (xdc_Char)0x65,  /* [2846] */
    (xdc_Char)0x79,  /* [2847] */
    (xdc_Char)0x3a,  /* [2848] */
    (xdc_Char)0x20,  /* [2849] */
    (xdc_Char)0x74,  /* [2850] */
    (xdc_Char)0x68,  /* [2851] */
    (xdc_Char)0x65,  /* [2852] */
    (xdc_Char)0x20,  /* [2853] */
    (xdc_Char)0x6b,  /* [2854] */
    (xdc_Char)0x65,  /* [2855] */
    (xdc_Char)0x79,  /* [2856] */
    (xdc_Char)0x20,  /* [2857] */
    (xdc_Char)0x6d,  /* [2858] */
    (xdc_Char)0x75,  /* [2859] */
    (xdc_Char)0x73,  /* [2860] */
    (xdc_Char)0x74,  /* [2861] */
    (xdc_Char)0x20,  /* [2862] */
    (xdc_Char)0x62,  /* [2863] */
    (xdc_Char)0x65,  /* [2864] */
    (xdc_Char)0x20,  /* [2865] */
    (xdc_Char)0x73,  /* [2866] */
    (xdc_Char)0x65,  /* [2867] */
    (xdc_Char)0x74,  /* [2868] */
    (xdc_Char)0x20,  /* [2869] */
    (xdc_Char)0x74,  /* [2870] */
    (xdc_Char)0x6f,  /* [2871] */
    (xdc_Char)0x20,  /* [2872] */
    (xdc_Char)0x61,  /* [2873] */
    (xdc_Char)0x20,  /* [2874] */
    (xdc_Char)0x6e,  /* [2875] */
    (xdc_Char)0x6f,  /* [2876] */
    (xdc_Char)0x6e,  /* [2877] */
    (xdc_Char)0x2d,  /* [2878] */
    (xdc_Char)0x64,  /* [2879] */
    (xdc_Char)0x65,  /* [2880] */
    (xdc_Char)0x66,  /* [2881] */
    (xdc_Char)0x61,  /* [2882] */
    (xdc_Char)0x75,  /* [2883] */
    (xdc_Char)0x6c,  /* [2884] */
    (xdc_Char)0x74,  /* [2885] */
    (xdc_Char)0x20,  /* [2886] */
    (xdc_Char)0x76,  /* [2887] */
    (xdc_Char)0x61,  /* [2888] */
    (xdc_Char)0x6c,  /* [2889] */
    (xdc_Char)0x75,  /* [2890] */
    (xdc_Char)0x65,  /* [2891] */
    (xdc_Char)0x0,  /* [2892] */
    (xdc_Char)0x41,  /* [2893] */
    (xdc_Char)0x5f,  /* [2894] */
    (xdc_Char)0x62,  /* [2895] */
    (xdc_Char)0x61,  /* [2896] */
    (xdc_Char)0x64,  /* [2897] */
    (xdc_Char)0x43,  /* [2898] */
    (xdc_Char)0x6f,  /* [2899] */
    (xdc_Char)0x6e,  /* [2900] */
    (xdc_Char)0x74,  /* [2901] */
    (xdc_Char)0x65,  /* [2902] */
    (xdc_Char)0x78,  /* [2903] */
    (xdc_Char)0x74,  /* [2904] */
    (xdc_Char)0x3a,  /* [2905] */
    (xdc_Char)0x20,  /* [2906] */
    (xdc_Char)0x62,  /* [2907] */
    (xdc_Char)0x61,  /* [2908] */
    (xdc_Char)0x64,  /* [2909] */
    (xdc_Char)0x20,  /* [2910] */
    (xdc_Char)0x63,  /* [2911] */
    (xdc_Char)0x61,  /* [2912] */
    (xdc_Char)0x6c,  /* [2913] */
    (xdc_Char)0x6c,  /* [2914] */
    (xdc_Char)0x69,  /* [2915] */
    (xdc_Char)0x6e,  /* [2916] */
    (xdc_Char)0x67,  /* [2917] */
    (xdc_Char)0x20,  /* [2918] */
    (xdc_Char)0x63,  /* [2919] */
    (xdc_Char)0x6f,  /* [2920] */
    (xdc_Char)0x6e,  /* [2921] */
    (xdc_Char)0x74,  /* [2922] */
    (xdc_Char)0x65,  /* [2923] */
    (xdc_Char)0x78,  /* [2924] */
    (xdc_Char)0x74,  /* [2925] */
    (xdc_Char)0x2e,  /* [2926] */
    (xdc_Char)0x20,  /* [2927] */
    (xdc_Char)0x4d,  /* [2928] */
    (xdc_Char)0x61,  /* [2929] */
    (xdc_Char)0x79,  /* [2930] */
    (xdc_Char)0x20,  /* [2931] */
    (xdc_Char)0x6e,  /* [2932] */
    (xdc_Char)0x6f,  /* [2933] */
    (xdc_Char)0x74,  /* [2934] */
    (xdc_Char)0x20,  /* [2935] */
    (xdc_Char)0x62,  /* [2936] */
    (xdc_Char)0x65,  /* [2937] */
    (xdc_Char)0x20,  /* [2938] */
    (xdc_Char)0x65,  /* [2939] */
    (xdc_Char)0x6e,  /* [2940] */
    (xdc_Char)0x74,  /* [2941] */
    (xdc_Char)0x65,  /* [2942] */
    (xdc_Char)0x72,  /* [2943] */
    (xdc_Char)0x65,  /* [2944] */
    (xdc_Char)0x64,  /* [2945] */
    (xdc_Char)0x20,  /* [2946] */
    (xdc_Char)0x66,  /* [2947] */
    (xdc_Char)0x72,  /* [2948] */
    (xdc_Char)0x6f,  /* [2949] */
    (xdc_Char)0x6d,  /* [2950] */
    (xdc_Char)0x20,  /* [2951] */
    (xdc_Char)0x61,  /* [2952] */
    (xdc_Char)0x20,  /* [2953] */
    (xdc_Char)0x68,  /* [2954] */
    (xdc_Char)0x61,  /* [2955] */
    (xdc_Char)0x72,  /* [2956] */
    (xdc_Char)0x64,  /* [2957] */
    (xdc_Char)0x77,  /* [2958] */
    (xdc_Char)0x61,  /* [2959] */
    (xdc_Char)0x72,  /* [2960] */
    (xdc_Char)0x65,  /* [2961] */
    (xdc_Char)0x20,  /* [2962] */
    (xdc_Char)0x69,  /* [2963] */
    (xdc_Char)0x6e,  /* [2964] */
    (xdc_Char)0x74,  /* [2965] */
    (xdc_Char)0x65,  /* [2966] */
    (xdc_Char)0x72,  /* [2967] */
    (xdc_Char)0x72,  /* [2968] */
    (xdc_Char)0x75,  /* [2969] */
    (xdc_Char)0x70,  /* [2970] */
    (xdc_Char)0x74,  /* [2971] */
    (xdc_Char)0x20,  /* [2972] */
    (xdc_Char)0x74,  /* [2973] */
    (xdc_Char)0x68,  /* [2974] */
    (xdc_Char)0x72,  /* [2975] */
    (xdc_Char)0x65,  /* [2976] */
    (xdc_Char)0x61,  /* [2977] */
    (xdc_Char)0x64,  /* [2978] */
    (xdc_Char)0x2e,  /* [2979] */
    (xdc_Char)0x0,  /* [2980] */
    (xdc_Char)0x41,  /* [2981] */
    (xdc_Char)0x5f,  /* [2982] */
    (xdc_Char)0x62,  /* [2983] */
    (xdc_Char)0x61,  /* [2984] */
    (xdc_Char)0x64,  /* [2985] */
    (xdc_Char)0x43,  /* [2986] */
    (xdc_Char)0x6f,  /* [2987] */
    (xdc_Char)0x6e,  /* [2988] */
    (xdc_Char)0x74,  /* [2989] */
    (xdc_Char)0x65,  /* [2990] */
    (xdc_Char)0x78,  /* [2991] */
    (xdc_Char)0x74,  /* [2992] */
    (xdc_Char)0x3a,  /* [2993] */
    (xdc_Char)0x20,  /* [2994] */
    (xdc_Char)0x62,  /* [2995] */
    (xdc_Char)0x61,  /* [2996] */
    (xdc_Char)0x64,  /* [2997] */
    (xdc_Char)0x20,  /* [2998] */
    (xdc_Char)0x63,  /* [2999] */
    (xdc_Char)0x61,  /* [3000] */
    (xdc_Char)0x6c,  /* [3001] */
    (xdc_Char)0x6c,  /* [3002] */
    (xdc_Char)0x69,  /* [3003] */
    (xdc_Char)0x6e,  /* [3004] */
    (xdc_Char)0x67,  /* [3005] */
    (xdc_Char)0x20,  /* [3006] */
    (xdc_Char)0x63,  /* [3007] */
    (xdc_Char)0x6f,  /* [3008] */
    (xdc_Char)0x6e,  /* [3009] */
    (xdc_Char)0x74,  /* [3010] */
    (xdc_Char)0x65,  /* [3011] */
    (xdc_Char)0x78,  /* [3012] */
    (xdc_Char)0x74,  /* [3013] */
    (xdc_Char)0x2e,  /* [3014] */
    (xdc_Char)0x20,  /* [3015] */
    (xdc_Char)0x4d,  /* [3016] */
    (xdc_Char)0x61,  /* [3017] */
    (xdc_Char)0x79,  /* [3018] */
    (xdc_Char)0x20,  /* [3019] */
    (xdc_Char)0x6e,  /* [3020] */
    (xdc_Char)0x6f,  /* [3021] */
    (xdc_Char)0x74,  /* [3022] */
    (xdc_Char)0x20,  /* [3023] */
    (xdc_Char)0x62,  /* [3024] */
    (xdc_Char)0x65,  /* [3025] */
    (xdc_Char)0x20,  /* [3026] */
    (xdc_Char)0x65,  /* [3027] */
    (xdc_Char)0x6e,  /* [3028] */
    (xdc_Char)0x74,  /* [3029] */
    (xdc_Char)0x65,  /* [3030] */
    (xdc_Char)0x72,  /* [3031] */
    (xdc_Char)0x65,  /* [3032] */
    (xdc_Char)0x64,  /* [3033] */
    (xdc_Char)0x20,  /* [3034] */
    (xdc_Char)0x66,  /* [3035] */
    (xdc_Char)0x72,  /* [3036] */
    (xdc_Char)0x6f,  /* [3037] */
    (xdc_Char)0x6d,  /* [3038] */
    (xdc_Char)0x20,  /* [3039] */
    (xdc_Char)0x61,  /* [3040] */
    (xdc_Char)0x20,  /* [3041] */
    (xdc_Char)0x73,  /* [3042] */
    (xdc_Char)0x6f,  /* [3043] */
    (xdc_Char)0x66,  /* [3044] */
    (xdc_Char)0x74,  /* [3045] */
    (xdc_Char)0x77,  /* [3046] */
    (xdc_Char)0x61,  /* [3047] */
    (xdc_Char)0x72,  /* [3048] */
    (xdc_Char)0x65,  /* [3049] */
    (xdc_Char)0x20,  /* [3050] */
    (xdc_Char)0x6f,  /* [3051] */
    (xdc_Char)0x72,  /* [3052] */
    (xdc_Char)0x20,  /* [3053] */
    (xdc_Char)0x68,  /* [3054] */
    (xdc_Char)0x61,  /* [3055] */
    (xdc_Char)0x72,  /* [3056] */
    (xdc_Char)0x64,  /* [3057] */
    (xdc_Char)0x77,  /* [3058] */
    (xdc_Char)0x61,  /* [3059] */
    (xdc_Char)0x72,  /* [3060] */
    (xdc_Char)0x65,  /* [3061] */
    (xdc_Char)0x20,  /* [3062] */
    (xdc_Char)0x69,  /* [3063] */
    (xdc_Char)0x6e,  /* [3064] */
    (xdc_Char)0x74,  /* [3065] */
    (xdc_Char)0x65,  /* [3066] */
    (xdc_Char)0x72,  /* [3067] */
    (xdc_Char)0x72,  /* [3068] */
    (xdc_Char)0x75,  /* [3069] */
    (xdc_Char)0x70,  /* [3070] */
    (xdc_Char)0x74,  /* [3071] */
    (xdc_Char)0x20,  /* [3072] */
    (xdc_Char)0x74,  /* [3073] */
    (xdc_Char)0x68,  /* [3074] */
    (xdc_Char)0x72,  /* [3075] */
    (xdc_Char)0x65,  /* [3076] */
    (xdc_Char)0x61,  /* [3077] */
    (xdc_Char)0x64,  /* [3078] */
    (xdc_Char)0x2e,  /* [3079] */
    (xdc_Char)0x0,  /* [3080] */
    (xdc_Char)0x41,  /* [3081] */
    (xdc_Char)0x5f,  /* [3082] */
    (xdc_Char)0x62,  /* [3083] */
    (xdc_Char)0x61,  /* [3084] */
    (xdc_Char)0x64,  /* [3085] */
    (xdc_Char)0x43,  /* [3086] */
    (xdc_Char)0x6f,  /* [3087] */
    (xdc_Char)0x6e,  /* [3088] */
    (xdc_Char)0x74,  /* [3089] */
    (xdc_Char)0x65,  /* [3090] */
    (xdc_Char)0x78,  /* [3091] */
    (xdc_Char)0x74,  /* [3092] */
    (xdc_Char)0x3a,  /* [3093] */
    (xdc_Char)0x20,  /* [3094] */
    (xdc_Char)0x62,  /* [3095] */
    (xdc_Char)0x61,  /* [3096] */
    (xdc_Char)0x64,  /* [3097] */
    (xdc_Char)0x20,  /* [3098] */
    (xdc_Char)0x63,  /* [3099] */
    (xdc_Char)0x61,  /* [3100] */
    (xdc_Char)0x6c,  /* [3101] */
    (xdc_Char)0x6c,  /* [3102] */
    (xdc_Char)0x69,  /* [3103] */
    (xdc_Char)0x6e,  /* [3104] */
    (xdc_Char)0x67,  /* [3105] */
    (xdc_Char)0x20,  /* [3106] */
    (xdc_Char)0x63,  /* [3107] */
    (xdc_Char)0x6f,  /* [3108] */
    (xdc_Char)0x6e,  /* [3109] */
    (xdc_Char)0x74,  /* [3110] */
    (xdc_Char)0x65,  /* [3111] */
    (xdc_Char)0x78,  /* [3112] */
    (xdc_Char)0x74,  /* [3113] */
    (xdc_Char)0x2e,  /* [3114] */
    (xdc_Char)0x20,  /* [3115] */
    (xdc_Char)0x53,  /* [3116] */
    (xdc_Char)0x65,  /* [3117] */
    (xdc_Char)0x65,  /* [3118] */
    (xdc_Char)0x20,  /* [3119] */
    (xdc_Char)0x47,  /* [3120] */
    (xdc_Char)0x61,  /* [3121] */
    (xdc_Char)0x74,  /* [3122] */
    (xdc_Char)0x65,  /* [3123] */
    (xdc_Char)0x4d,  /* [3124] */
    (xdc_Char)0x75,  /* [3125] */
    (xdc_Char)0x74,  /* [3126] */
    (xdc_Char)0x65,  /* [3127] */
    (xdc_Char)0x78,  /* [3128] */
    (xdc_Char)0x50,  /* [3129] */
    (xdc_Char)0x72,  /* [3130] */
    (xdc_Char)0x69,  /* [3131] */
    (xdc_Char)0x20,  /* [3132] */
    (xdc_Char)0x41,  /* [3133] */
    (xdc_Char)0x50,  /* [3134] */
    (xdc_Char)0x49,  /* [3135] */
    (xdc_Char)0x20,  /* [3136] */
    (xdc_Char)0x64,  /* [3137] */
    (xdc_Char)0x6f,  /* [3138] */
    (xdc_Char)0x63,  /* [3139] */
    (xdc_Char)0x20,  /* [3140] */
    (xdc_Char)0x66,  /* [3141] */
    (xdc_Char)0x6f,  /* [3142] */
    (xdc_Char)0x72,  /* [3143] */
    (xdc_Char)0x20,  /* [3144] */
    (xdc_Char)0x64,  /* [3145] */
    (xdc_Char)0x65,  /* [3146] */
    (xdc_Char)0x74,  /* [3147] */
    (xdc_Char)0x61,  /* [3148] */
    (xdc_Char)0x69,  /* [3149] */
    (xdc_Char)0x6c,  /* [3150] */
    (xdc_Char)0x73,  /* [3151] */
    (xdc_Char)0x2e,  /* [3152] */
    (xdc_Char)0x0,  /* [3153] */
    (xdc_Char)0x41,  /* [3154] */
    (xdc_Char)0x5f,  /* [3155] */
    (xdc_Char)0x65,  /* [3156] */
    (xdc_Char)0x6e,  /* [3157] */
    (xdc_Char)0x74,  /* [3158] */
    (xdc_Char)0x65,  /* [3159] */
    (xdc_Char)0x72,  /* [3160] */
    (xdc_Char)0x54,  /* [3161] */
    (xdc_Char)0x61,  /* [3162] */
    (xdc_Char)0x73,  /* [3163] */
    (xdc_Char)0x6b,  /* [3164] */
    (xdc_Char)0x44,  /* [3165] */
    (xdc_Char)0x69,  /* [3166] */
    (xdc_Char)0x73,  /* [3167] */
    (xdc_Char)0x61,  /* [3168] */
    (xdc_Char)0x62,  /* [3169] */
    (xdc_Char)0x6c,  /* [3170] */
    (xdc_Char)0x65,  /* [3171] */
    (xdc_Char)0x64,  /* [3172] */
    (xdc_Char)0x3a,  /* [3173] */
    (xdc_Char)0x20,  /* [3174] */
    (xdc_Char)0x43,  /* [3175] */
    (xdc_Char)0x61,  /* [3176] */
    (xdc_Char)0x6e,  /* [3177] */
    (xdc_Char)0x6e,  /* [3178] */
    (xdc_Char)0x6f,  /* [3179] */
    (xdc_Char)0x74,  /* [3180] */
    (xdc_Char)0x20,  /* [3181] */
    (xdc_Char)0x63,  /* [3182] */
    (xdc_Char)0x61,  /* [3183] */
    (xdc_Char)0x6c,  /* [3184] */
    (xdc_Char)0x6c,  /* [3185] */
    (xdc_Char)0x20,  /* [3186] */
    (xdc_Char)0x47,  /* [3187] */
    (xdc_Char)0x61,  /* [3188] */
    (xdc_Char)0x74,  /* [3189] */
    (xdc_Char)0x65,  /* [3190] */
    (xdc_Char)0x4d,  /* [3191] */
    (xdc_Char)0x75,  /* [3192] */
    (xdc_Char)0x74,  /* [3193] */
    (xdc_Char)0x65,  /* [3194] */
    (xdc_Char)0x78,  /* [3195] */
    (xdc_Char)0x50,  /* [3196] */
    (xdc_Char)0x72,  /* [3197] */
    (xdc_Char)0x69,  /* [3198] */
    (xdc_Char)0x5f,  /* [3199] */
    (xdc_Char)0x65,  /* [3200] */
    (xdc_Char)0x6e,  /* [3201] */
    (xdc_Char)0x74,  /* [3202] */
    (xdc_Char)0x65,  /* [3203] */
    (xdc_Char)0x72,  /* [3204] */
    (xdc_Char)0x28,  /* [3205] */
    (xdc_Char)0x29,  /* [3206] */
    (xdc_Char)0x20,  /* [3207] */
    (xdc_Char)0x77,  /* [3208] */
    (xdc_Char)0x68,  /* [3209] */
    (xdc_Char)0x69,  /* [3210] */
    (xdc_Char)0x6c,  /* [3211] */
    (xdc_Char)0x65,  /* [3212] */
    (xdc_Char)0x20,  /* [3213] */
    (xdc_Char)0x74,  /* [3214] */
    (xdc_Char)0x68,  /* [3215] */
    (xdc_Char)0x65,  /* [3216] */
    (xdc_Char)0x20,  /* [3217] */
    (xdc_Char)0x54,  /* [3218] */
    (xdc_Char)0x61,  /* [3219] */
    (xdc_Char)0x73,  /* [3220] */
    (xdc_Char)0x6b,  /* [3221] */
    (xdc_Char)0x20,  /* [3222] */
    (xdc_Char)0x6f,  /* [3223] */
    (xdc_Char)0x72,  /* [3224] */
    (xdc_Char)0x20,  /* [3225] */
    (xdc_Char)0x53,  /* [3226] */
    (xdc_Char)0x77,  /* [3227] */
    (xdc_Char)0x69,  /* [3228] */
    (xdc_Char)0x20,  /* [3229] */
    (xdc_Char)0x73,  /* [3230] */
    (xdc_Char)0x63,  /* [3231] */
    (xdc_Char)0x68,  /* [3232] */
    (xdc_Char)0x65,  /* [3233] */
    (xdc_Char)0x64,  /* [3234] */
    (xdc_Char)0x75,  /* [3235] */
    (xdc_Char)0x6c,  /* [3236] */
    (xdc_Char)0x65,  /* [3237] */
    (xdc_Char)0x72,  /* [3238] */
    (xdc_Char)0x20,  /* [3239] */
    (xdc_Char)0x69,  /* [3240] */
    (xdc_Char)0x73,  /* [3241] */
    (xdc_Char)0x20,  /* [3242] */
    (xdc_Char)0x64,  /* [3243] */
    (xdc_Char)0x69,  /* [3244] */
    (xdc_Char)0x73,  /* [3245] */
    (xdc_Char)0x61,  /* [3246] */
    (xdc_Char)0x62,  /* [3247] */
    (xdc_Char)0x6c,  /* [3248] */
    (xdc_Char)0x65,  /* [3249] */
    (xdc_Char)0x64,  /* [3250] */
    (xdc_Char)0x2e,  /* [3251] */
    (xdc_Char)0x0,  /* [3252] */
    (xdc_Char)0x41,  /* [3253] */
    (xdc_Char)0x5f,  /* [3254] */
    (xdc_Char)0x62,  /* [3255] */
    (xdc_Char)0x61,  /* [3256] */
    (xdc_Char)0x64,  /* [3257] */
    (xdc_Char)0x43,  /* [3258] */
    (xdc_Char)0x6f,  /* [3259] */
    (xdc_Char)0x6e,  /* [3260] */
    (xdc_Char)0x74,  /* [3261] */
    (xdc_Char)0x65,  /* [3262] */
    (xdc_Char)0x78,  /* [3263] */
    (xdc_Char)0x74,  /* [3264] */
    (xdc_Char)0x3a,  /* [3265] */
    (xdc_Char)0x20,  /* [3266] */
    (xdc_Char)0x62,  /* [3267] */
    (xdc_Char)0x61,  /* [3268] */
    (xdc_Char)0x64,  /* [3269] */
    (xdc_Char)0x20,  /* [3270] */
    (xdc_Char)0x63,  /* [3271] */
    (xdc_Char)0x61,  /* [3272] */
    (xdc_Char)0x6c,  /* [3273] */
    (xdc_Char)0x6c,  /* [3274] */
    (xdc_Char)0x69,  /* [3275] */
    (xdc_Char)0x6e,  /* [3276] */
    (xdc_Char)0x67,  /* [3277] */
    (xdc_Char)0x20,  /* [3278] */
    (xdc_Char)0x63,  /* [3279] */
    (xdc_Char)0x6f,  /* [3280] */
    (xdc_Char)0x6e,  /* [3281] */
    (xdc_Char)0x74,  /* [3282] */
    (xdc_Char)0x65,  /* [3283] */
    (xdc_Char)0x78,  /* [3284] */
    (xdc_Char)0x74,  /* [3285] */
    (xdc_Char)0x2e,  /* [3286] */
    (xdc_Char)0x20,  /* [3287] */
    (xdc_Char)0x53,  /* [3288] */
    (xdc_Char)0x65,  /* [3289] */
    (xdc_Char)0x65,  /* [3290] */
    (xdc_Char)0x20,  /* [3291] */
    (xdc_Char)0x47,  /* [3292] */
    (xdc_Char)0x61,  /* [3293] */
    (xdc_Char)0x74,  /* [3294] */
    (xdc_Char)0x65,  /* [3295] */
    (xdc_Char)0x4d,  /* [3296] */
    (xdc_Char)0x75,  /* [3297] */
    (xdc_Char)0x74,  /* [3298] */
    (xdc_Char)0x65,  /* [3299] */
    (xdc_Char)0x78,  /* [3300] */
    (xdc_Char)0x20,  /* [3301] */
    (xdc_Char)0x41,  /* [3302] */
    (xdc_Char)0x50,  /* [3303] */
    (xdc_Char)0x49,  /* [3304] */
    (xdc_Char)0x20,  /* [3305] */
    (xdc_Char)0x64,  /* [3306] */
    (xdc_Char)0x6f,  /* [3307] */
    (xdc_Char)0x63,  /* [3308] */
    (xdc_Char)0x20,  /* [3309] */
    (xdc_Char)0x66,  /* [3310] */
    (xdc_Char)0x6f,  /* [3311] */
    (xdc_Char)0x72,  /* [3312] */
    (xdc_Char)0x20,  /* [3313] */
    (xdc_Char)0x64,  /* [3314] */
    (xdc_Char)0x65,  /* [3315] */
    (xdc_Char)0x74,  /* [3316] */
    (xdc_Char)0x61,  /* [3317] */
    (xdc_Char)0x69,  /* [3318] */
    (xdc_Char)0x6c,  /* [3319] */
    (xdc_Char)0x73,  /* [3320] */
    (xdc_Char)0x2e,  /* [3321] */
    (xdc_Char)0x0,  /* [3322] */
    (xdc_Char)0x41,  /* [3323] */
    (xdc_Char)0x5f,  /* [3324] */
    (xdc_Char)0x62,  /* [3325] */
    (xdc_Char)0x61,  /* [3326] */
    (xdc_Char)0x64,  /* [3327] */
    (xdc_Char)0x43,  /* [3328] */
    (xdc_Char)0x6f,  /* [3329] */
    (xdc_Char)0x6e,  /* [3330] */
    (xdc_Char)0x74,  /* [3331] */
    (xdc_Char)0x65,  /* [3332] */
    (xdc_Char)0x78,  /* [3333] */
    (xdc_Char)0x74,  /* [3334] */
    (xdc_Char)0x3a,  /* [3335] */
    (xdc_Char)0x20,  /* [3336] */
    (xdc_Char)0x62,  /* [3337] */
    (xdc_Char)0x61,  /* [3338] */
    (xdc_Char)0x64,  /* [3339] */
    (xdc_Char)0x20,  /* [3340] */
    (xdc_Char)0x63,  /* [3341] */
    (xdc_Char)0x61,  /* [3342] */
    (xdc_Char)0x6c,  /* [3343] */
    (xdc_Char)0x6c,  /* [3344] */
    (xdc_Char)0x69,  /* [3345] */
    (xdc_Char)0x6e,  /* [3346] */
    (xdc_Char)0x67,  /* [3347] */
    (xdc_Char)0x20,  /* [3348] */
    (xdc_Char)0x63,  /* [3349] */
    (xdc_Char)0x6f,  /* [3350] */
    (xdc_Char)0x6e,  /* [3351] */
    (xdc_Char)0x74,  /* [3352] */
    (xdc_Char)0x65,  /* [3353] */
    (xdc_Char)0x78,  /* [3354] */
    (xdc_Char)0x74,  /* [3355] */
    (xdc_Char)0x2e,  /* [3356] */
    (xdc_Char)0x20,  /* [3357] */
    (xdc_Char)0x53,  /* [3358] */
    (xdc_Char)0x65,  /* [3359] */
    (xdc_Char)0x65,  /* [3360] */
    (xdc_Char)0x20,  /* [3361] */
    (xdc_Char)0x47,  /* [3362] */
    (xdc_Char)0x61,  /* [3363] */
    (xdc_Char)0x74,  /* [3364] */
    (xdc_Char)0x65,  /* [3365] */
    (xdc_Char)0x53,  /* [3366] */
    (xdc_Char)0x70,  /* [3367] */
    (xdc_Char)0x69,  /* [3368] */
    (xdc_Char)0x6e,  /* [3369] */
    (xdc_Char)0x6c,  /* [3370] */
    (xdc_Char)0x6f,  /* [3371] */
    (xdc_Char)0x63,  /* [3372] */
    (xdc_Char)0x6b,  /* [3373] */
    (xdc_Char)0x20,  /* [3374] */
    (xdc_Char)0x41,  /* [3375] */
    (xdc_Char)0x50,  /* [3376] */
    (xdc_Char)0x49,  /* [3377] */
    (xdc_Char)0x20,  /* [3378] */
    (xdc_Char)0x64,  /* [3379] */
    (xdc_Char)0x6f,  /* [3380] */
    (xdc_Char)0x63,  /* [3381] */
    (xdc_Char)0x20,  /* [3382] */
    (xdc_Char)0x66,  /* [3383] */
    (xdc_Char)0x6f,  /* [3384] */
    (xdc_Char)0x72,  /* [3385] */
    (xdc_Char)0x20,  /* [3386] */
    (xdc_Char)0x64,  /* [3387] */
    (xdc_Char)0x65,  /* [3388] */
    (xdc_Char)0x74,  /* [3389] */
    (xdc_Char)0x61,  /* [3390] */
    (xdc_Char)0x69,  /* [3391] */
    (xdc_Char)0x6c,  /* [3392] */
    (xdc_Char)0x73,  /* [3393] */
    (xdc_Char)0x2e,  /* [3394] */
    (xdc_Char)0x0,  /* [3395] */
    (xdc_Char)0x41,  /* [3396] */
    (xdc_Char)0x5f,  /* [3397] */
    (xdc_Char)0x69,  /* [3398] */
    (xdc_Char)0x6e,  /* [3399] */
    (xdc_Char)0x76,  /* [3400] */
    (xdc_Char)0x61,  /* [3401] */
    (xdc_Char)0x6c,  /* [3402] */
    (xdc_Char)0x69,  /* [3403] */
    (xdc_Char)0x64,  /* [3404] */
    (xdc_Char)0x51,  /* [3405] */
    (xdc_Char)0x75,  /* [3406] */
    (xdc_Char)0x61,  /* [3407] */
    (xdc_Char)0x6c,  /* [3408] */
    (xdc_Char)0x69,  /* [3409] */
    (xdc_Char)0x74,  /* [3410] */
    (xdc_Char)0x79,  /* [3411] */
    (xdc_Char)0x3a,  /* [3412] */
    (xdc_Char)0x20,  /* [3413] */
    (xdc_Char)0x53,  /* [3414] */
    (xdc_Char)0x65,  /* [3415] */
    (xdc_Char)0x65,  /* [3416] */
    (xdc_Char)0x20,  /* [3417] */
    (xdc_Char)0x47,  /* [3418] */
    (xdc_Char)0x61,  /* [3419] */
    (xdc_Char)0x74,  /* [3420] */
    (xdc_Char)0x65,  /* [3421] */
    (xdc_Char)0x53,  /* [3422] */
    (xdc_Char)0x70,  /* [3423] */
    (xdc_Char)0x69,  /* [3424] */
    (xdc_Char)0x6e,  /* [3425] */
    (xdc_Char)0x6c,  /* [3426] */
    (xdc_Char)0x6f,  /* [3427] */
    (xdc_Char)0x63,  /* [3428] */
    (xdc_Char)0x6b,  /* [3429] */
    (xdc_Char)0x20,  /* [3430] */
    (xdc_Char)0x41,  /* [3431] */
    (xdc_Char)0x50,  /* [3432] */
    (xdc_Char)0x49,  /* [3433] */
    (xdc_Char)0x20,  /* [3434] */
    (xdc_Char)0x64,  /* [3435] */
    (xdc_Char)0x6f,  /* [3436] */
    (xdc_Char)0x63,  /* [3437] */
    (xdc_Char)0x20,  /* [3438] */
    (xdc_Char)0x66,  /* [3439] */
    (xdc_Char)0x6f,  /* [3440] */
    (xdc_Char)0x72,  /* [3441] */
    (xdc_Char)0x20,  /* [3442] */
    (xdc_Char)0x64,  /* [3443] */
    (xdc_Char)0x65,  /* [3444] */
    (xdc_Char)0x74,  /* [3445] */
    (xdc_Char)0x61,  /* [3446] */
    (xdc_Char)0x69,  /* [3447] */
    (xdc_Char)0x6c,  /* [3448] */
    (xdc_Char)0x73,  /* [3449] */
    (xdc_Char)0x2e,  /* [3450] */
    (xdc_Char)0x0,  /* [3451] */
    (xdc_Char)0x62,  /* [3452] */
    (xdc_Char)0x75,  /* [3453] */
    (xdc_Char)0x66,  /* [3454] */
    (xdc_Char)0x20,  /* [3455] */
    (xdc_Char)0x70,  /* [3456] */
    (xdc_Char)0x61,  /* [3457] */
    (xdc_Char)0x72,  /* [3458] */
    (xdc_Char)0x61,  /* [3459] */
    (xdc_Char)0x6d,  /* [3460] */
    (xdc_Char)0x65,  /* [3461] */
    (xdc_Char)0x74,  /* [3462] */
    (xdc_Char)0x65,  /* [3463] */
    (xdc_Char)0x72,  /* [3464] */
    (xdc_Char)0x20,  /* [3465] */
    (xdc_Char)0x63,  /* [3466] */
    (xdc_Char)0x61,  /* [3467] */
    (xdc_Char)0x6e,  /* [3468] */
    (xdc_Char)0x6e,  /* [3469] */
    (xdc_Char)0x6f,  /* [3470] */
    (xdc_Char)0x74,  /* [3471] */
    (xdc_Char)0x20,  /* [3472] */
    (xdc_Char)0x62,  /* [3473] */
    (xdc_Char)0x65,  /* [3474] */
    (xdc_Char)0x20,  /* [3475] */
    (xdc_Char)0x6e,  /* [3476] */
    (xdc_Char)0x75,  /* [3477] */
    (xdc_Char)0x6c,  /* [3478] */
    (xdc_Char)0x6c,  /* [3479] */
    (xdc_Char)0x0,  /* [3480] */
    (xdc_Char)0x62,  /* [3481] */
    (xdc_Char)0x75,  /* [3482] */
    (xdc_Char)0x66,  /* [3483] */
    (xdc_Char)0x20,  /* [3484] */
    (xdc_Char)0x6e,  /* [3485] */
    (xdc_Char)0x6f,  /* [3486] */
    (xdc_Char)0x74,  /* [3487] */
    (xdc_Char)0x20,  /* [3488] */
    (xdc_Char)0x70,  /* [3489] */
    (xdc_Char)0x72,  /* [3490] */
    (xdc_Char)0x6f,  /* [3491] */
    (xdc_Char)0x70,  /* [3492] */
    (xdc_Char)0x65,  /* [3493] */
    (xdc_Char)0x72,  /* [3494] */
    (xdc_Char)0x6c,  /* [3495] */
    (xdc_Char)0x79,  /* [3496] */
    (xdc_Char)0x20,  /* [3497] */
    (xdc_Char)0x61,  /* [3498] */
    (xdc_Char)0x6c,  /* [3499] */
    (xdc_Char)0x69,  /* [3500] */
    (xdc_Char)0x67,  /* [3501] */
    (xdc_Char)0x6e,  /* [3502] */
    (xdc_Char)0x65,  /* [3503] */
    (xdc_Char)0x64,  /* [3504] */
    (xdc_Char)0x0,  /* [3505] */
    (xdc_Char)0x61,  /* [3506] */
    (xdc_Char)0x6c,  /* [3507] */
    (xdc_Char)0x69,  /* [3508] */
    (xdc_Char)0x67,  /* [3509] */
    (xdc_Char)0x6e,  /* [3510] */
    (xdc_Char)0x20,  /* [3511] */
    (xdc_Char)0x70,  /* [3512] */
    (xdc_Char)0x61,  /* [3513] */
    (xdc_Char)0x72,  /* [3514] */
    (xdc_Char)0x61,  /* [3515] */
    (xdc_Char)0x6d,  /* [3516] */
    (xdc_Char)0x65,  /* [3517] */
    (xdc_Char)0x74,  /* [3518] */
    (xdc_Char)0x65,  /* [3519] */
    (xdc_Char)0x72,  /* [3520] */
    (xdc_Char)0x20,  /* [3521] */
    (xdc_Char)0x6d,  /* [3522] */
    (xdc_Char)0x75,  /* [3523] */
    (xdc_Char)0x73,  /* [3524] */
    (xdc_Char)0x74,  /* [3525] */
    (xdc_Char)0x20,  /* [3526] */
    (xdc_Char)0x62,  /* [3527] */
    (xdc_Char)0x65,  /* [3528] */
    (xdc_Char)0x20,  /* [3529] */
    (xdc_Char)0x30,  /* [3530] */
    (xdc_Char)0x20,  /* [3531] */
    (xdc_Char)0x6f,  /* [3532] */
    (xdc_Char)0x72,  /* [3533] */
    (xdc_Char)0x20,  /* [3534] */
    (xdc_Char)0x61,  /* [3535] */
    (xdc_Char)0x20,  /* [3536] */
    (xdc_Char)0x70,  /* [3537] */
    (xdc_Char)0x6f,  /* [3538] */
    (xdc_Char)0x77,  /* [3539] */
    (xdc_Char)0x65,  /* [3540] */
    (xdc_Char)0x72,  /* [3541] */
    (xdc_Char)0x20,  /* [3542] */
    (xdc_Char)0x6f,  /* [3543] */
    (xdc_Char)0x66,  /* [3544] */
    (xdc_Char)0x20,  /* [3545] */
    (xdc_Char)0x32,  /* [3546] */
    (xdc_Char)0x20,  /* [3547] */
    (xdc_Char)0x3e,  /* [3548] */
    (xdc_Char)0x3d,  /* [3549] */
    (xdc_Char)0x20,  /* [3550] */
    (xdc_Char)0x74,  /* [3551] */
    (xdc_Char)0x68,  /* [3552] */
    (xdc_Char)0x65,  /* [3553] */
    (xdc_Char)0x20,  /* [3554] */
    (xdc_Char)0x76,  /* [3555] */
    (xdc_Char)0x61,  /* [3556] */
    (xdc_Char)0x6c,  /* [3557] */
    (xdc_Char)0x75,  /* [3558] */
    (xdc_Char)0x65,  /* [3559] */
    (xdc_Char)0x20,  /* [3560] */
    (xdc_Char)0x6f,  /* [3561] */
    (xdc_Char)0x66,  /* [3562] */
    (xdc_Char)0x20,  /* [3563] */
    (xdc_Char)0x4d,  /* [3564] */
    (xdc_Char)0x65,  /* [3565] */
    (xdc_Char)0x6d,  /* [3566] */
    (xdc_Char)0x6f,  /* [3567] */
    (xdc_Char)0x72,  /* [3568] */
    (xdc_Char)0x79,  /* [3569] */
    (xdc_Char)0x5f,  /* [3570] */
    (xdc_Char)0x67,  /* [3571] */
    (xdc_Char)0x65,  /* [3572] */
    (xdc_Char)0x74,  /* [3573] */
    (xdc_Char)0x4d,  /* [3574] */
    (xdc_Char)0x61,  /* [3575] */
    (xdc_Char)0x78,  /* [3576] */
    (xdc_Char)0x44,  /* [3577] */
    (xdc_Char)0x65,  /* [3578] */
    (xdc_Char)0x66,  /* [3579] */
    (xdc_Char)0x61,  /* [3580] */
    (xdc_Char)0x75,  /* [3581] */
    (xdc_Char)0x6c,  /* [3582] */
    (xdc_Char)0x74,  /* [3583] */
    (xdc_Char)0x54,  /* [3584] */
    (xdc_Char)0x79,  /* [3585] */
    (xdc_Char)0x70,  /* [3586] */
    (xdc_Char)0x65,  /* [3587] */
    (xdc_Char)0x41,  /* [3588] */
    (xdc_Char)0x6c,  /* [3589] */
    (xdc_Char)0x69,  /* [3590] */
    (xdc_Char)0x67,  /* [3591] */
    (xdc_Char)0x6e,  /* [3592] */
    (xdc_Char)0x28,  /* [3593] */
    (xdc_Char)0x29,  /* [3594] */
    (xdc_Char)0x0,  /* [3595] */
    (xdc_Char)0x61,  /* [3596] */
    (xdc_Char)0x6c,  /* [3597] */
    (xdc_Char)0x69,  /* [3598] */
    (xdc_Char)0x67,  /* [3599] */
    (xdc_Char)0x6e,  /* [3600] */
    (xdc_Char)0x20,  /* [3601] */
    (xdc_Char)0x70,  /* [3602] */
    (xdc_Char)0x61,  /* [3603] */
    (xdc_Char)0x72,  /* [3604] */
    (xdc_Char)0x61,  /* [3605] */
    (xdc_Char)0x6d,  /* [3606] */
    (xdc_Char)0x65,  /* [3607] */
    (xdc_Char)0x74,  /* [3608] */
    (xdc_Char)0x65,  /* [3609] */
    (xdc_Char)0x72,  /* [3610] */
    (xdc_Char)0x20,  /* [3611] */
    (xdc_Char)0x31,  /* [3612] */
    (xdc_Char)0x29,  /* [3613] */
    (xdc_Char)0x20,  /* [3614] */
    (xdc_Char)0x6d,  /* [3615] */
    (xdc_Char)0x75,  /* [3616] */
    (xdc_Char)0x73,  /* [3617] */
    (xdc_Char)0x74,  /* [3618] */
    (xdc_Char)0x20,  /* [3619] */
    (xdc_Char)0x62,  /* [3620] */
    (xdc_Char)0x65,  /* [3621] */
    (xdc_Char)0x20,  /* [3622] */
    (xdc_Char)0x30,  /* [3623] */
    (xdc_Char)0x20,  /* [3624] */
    (xdc_Char)0x6f,  /* [3625] */
    (xdc_Char)0x72,  /* [3626] */
    (xdc_Char)0x20,  /* [3627] */
    (xdc_Char)0x61,  /* [3628] */
    (xdc_Char)0x20,  /* [3629] */
    (xdc_Char)0x70,  /* [3630] */
    (xdc_Char)0x6f,  /* [3631] */
    (xdc_Char)0x77,  /* [3632] */
    (xdc_Char)0x65,  /* [3633] */
    (xdc_Char)0x72,  /* [3634] */
    (xdc_Char)0x20,  /* [3635] */
    (xdc_Char)0x6f,  /* [3636] */
    (xdc_Char)0x66,  /* [3637] */
    (xdc_Char)0x20,  /* [3638] */
    (xdc_Char)0x32,  /* [3639] */
    (xdc_Char)0x20,  /* [3640] */
    (xdc_Char)0x61,  /* [3641] */
    (xdc_Char)0x6e,  /* [3642] */
    (xdc_Char)0x64,  /* [3643] */
    (xdc_Char)0x20,  /* [3644] */
    (xdc_Char)0x32,  /* [3645] */
    (xdc_Char)0x29,  /* [3646] */
    (xdc_Char)0x20,  /* [3647] */
    (xdc_Char)0x6e,  /* [3648] */
    (xdc_Char)0x6f,  /* [3649] */
    (xdc_Char)0x74,  /* [3650] */
    (xdc_Char)0x20,  /* [3651] */
    (xdc_Char)0x67,  /* [3652] */
    (xdc_Char)0x72,  /* [3653] */
    (xdc_Char)0x65,  /* [3654] */
    (xdc_Char)0x61,  /* [3655] */
    (xdc_Char)0x74,  /* [3656] */
    (xdc_Char)0x65,  /* [3657] */
    (xdc_Char)0x72,  /* [3658] */
    (xdc_Char)0x20,  /* [3659] */
    (xdc_Char)0x74,  /* [3660] */
    (xdc_Char)0x68,  /* [3661] */
    (xdc_Char)0x61,  /* [3662] */
    (xdc_Char)0x6e,  /* [3663] */
    (xdc_Char)0x20,  /* [3664] */
    (xdc_Char)0x74,  /* [3665] */
    (xdc_Char)0x68,  /* [3666] */
    (xdc_Char)0x65,  /* [3667] */
    (xdc_Char)0x20,  /* [3668] */
    (xdc_Char)0x68,  /* [3669] */
    (xdc_Char)0x65,  /* [3670] */
    (xdc_Char)0x61,  /* [3671] */
    (xdc_Char)0x70,  /* [3672] */
    (xdc_Char)0x73,  /* [3673] */
    (xdc_Char)0x20,  /* [3674] */
    (xdc_Char)0x61,  /* [3675] */
    (xdc_Char)0x6c,  /* [3676] */
    (xdc_Char)0x69,  /* [3677] */
    (xdc_Char)0x67,  /* [3678] */
    (xdc_Char)0x6e,  /* [3679] */
    (xdc_Char)0x6d,  /* [3680] */
    (xdc_Char)0x65,  /* [3681] */
    (xdc_Char)0x6e,  /* [3682] */
    (xdc_Char)0x74,  /* [3683] */
    (xdc_Char)0x0,  /* [3684] */
    (xdc_Char)0x62,  /* [3685] */
    (xdc_Char)0x6c,  /* [3686] */
    (xdc_Char)0x6f,  /* [3687] */
    (xdc_Char)0x63,  /* [3688] */
    (xdc_Char)0x6b,  /* [3689] */
    (xdc_Char)0x53,  /* [3690] */
    (xdc_Char)0x69,  /* [3691] */
    (xdc_Char)0x7a,  /* [3692] */
    (xdc_Char)0x65,  /* [3693] */
    (xdc_Char)0x20,  /* [3694] */
    (xdc_Char)0x6d,  /* [3695] */
    (xdc_Char)0x75,  /* [3696] */
    (xdc_Char)0x73,  /* [3697] */
    (xdc_Char)0x74,  /* [3698] */
    (xdc_Char)0x20,  /* [3699] */
    (xdc_Char)0x62,  /* [3700] */
    (xdc_Char)0x65,  /* [3701] */
    (xdc_Char)0x20,  /* [3702] */
    (xdc_Char)0x6c,  /* [3703] */
    (xdc_Char)0x61,  /* [3704] */
    (xdc_Char)0x72,  /* [3705] */
    (xdc_Char)0x67,  /* [3706] */
    (xdc_Char)0x65,  /* [3707] */
    (xdc_Char)0x20,  /* [3708] */
    (xdc_Char)0x65,  /* [3709] */
    (xdc_Char)0x6e,  /* [3710] */
    (xdc_Char)0x6f,  /* [3711] */
    (xdc_Char)0x75,  /* [3712] */
    (xdc_Char)0x67,  /* [3713] */
    (xdc_Char)0x68,  /* [3714] */
    (xdc_Char)0x20,  /* [3715] */
    (xdc_Char)0x74,  /* [3716] */
    (xdc_Char)0x6f,  /* [3717] */
    (xdc_Char)0x20,  /* [3718] */
    (xdc_Char)0x68,  /* [3719] */
    (xdc_Char)0x6f,  /* [3720] */
    (xdc_Char)0x6c,  /* [3721] */
    (xdc_Char)0x64,  /* [3722] */
    (xdc_Char)0x20,  /* [3723] */
    (xdc_Char)0x61,  /* [3724] */
    (xdc_Char)0x74,  /* [3725] */
    (xdc_Char)0x6c,  /* [3726] */
    (xdc_Char)0x65,  /* [3727] */
    (xdc_Char)0x61,  /* [3728] */
    (xdc_Char)0x73,  /* [3729] */
    (xdc_Char)0x74,  /* [3730] */
    (xdc_Char)0x20,  /* [3731] */
    (xdc_Char)0x74,  /* [3732] */
    (xdc_Char)0x77,  /* [3733] */
    (xdc_Char)0x6f,  /* [3734] */
    (xdc_Char)0x20,  /* [3735] */
    (xdc_Char)0x70,  /* [3736] */
    (xdc_Char)0x6f,  /* [3737] */
    (xdc_Char)0x69,  /* [3738] */
    (xdc_Char)0x6e,  /* [3739] */
    (xdc_Char)0x74,  /* [3740] */
    (xdc_Char)0x65,  /* [3741] */
    (xdc_Char)0x72,  /* [3742] */
    (xdc_Char)0x73,  /* [3743] */
    (xdc_Char)0x0,  /* [3744] */
    (xdc_Char)0x6e,  /* [3745] */
    (xdc_Char)0x75,  /* [3746] */
    (xdc_Char)0x6d,  /* [3747] */
    (xdc_Char)0x42,  /* [3748] */
    (xdc_Char)0x6c,  /* [3749] */
    (xdc_Char)0x6f,  /* [3750] */
    (xdc_Char)0x63,  /* [3751] */
    (xdc_Char)0x6b,  /* [3752] */
    (xdc_Char)0x73,  /* [3753] */
    (xdc_Char)0x20,  /* [3754] */
    (xdc_Char)0x63,  /* [3755] */
    (xdc_Char)0x61,  /* [3756] */
    (xdc_Char)0x6e,  /* [3757] */
    (xdc_Char)0x6e,  /* [3758] */
    (xdc_Char)0x6f,  /* [3759] */
    (xdc_Char)0x74,  /* [3760] */
    (xdc_Char)0x20,  /* [3761] */
    (xdc_Char)0x62,  /* [3762] */
    (xdc_Char)0x65,  /* [3763] */
    (xdc_Char)0x20,  /* [3764] */
    (xdc_Char)0x7a,  /* [3765] */
    (xdc_Char)0x65,  /* [3766] */
    (xdc_Char)0x72,  /* [3767] */
    (xdc_Char)0x6f,  /* [3768] */
    (xdc_Char)0x0,  /* [3769] */
    (xdc_Char)0x62,  /* [3770] */
    (xdc_Char)0x75,  /* [3771] */
    (xdc_Char)0x66,  /* [3772] */
    (xdc_Char)0x53,  /* [3773] */
    (xdc_Char)0x69,  /* [3774] */
    (xdc_Char)0x7a,  /* [3775] */
    (xdc_Char)0x65,  /* [3776] */
    (xdc_Char)0x20,  /* [3777] */
    (xdc_Char)0x63,  /* [3778] */
    (xdc_Char)0x61,  /* [3779] */
    (xdc_Char)0x6e,  /* [3780] */
    (xdc_Char)0x6e,  /* [3781] */
    (xdc_Char)0x6f,  /* [3782] */
    (xdc_Char)0x74,  /* [3783] */
    (xdc_Char)0x20,  /* [3784] */
    (xdc_Char)0x62,  /* [3785] */
    (xdc_Char)0x65,  /* [3786] */
    (xdc_Char)0x20,  /* [3787] */
    (xdc_Char)0x7a,  /* [3788] */
    (xdc_Char)0x65,  /* [3789] */
    (xdc_Char)0x72,  /* [3790] */
    (xdc_Char)0x6f,  /* [3791] */
    (xdc_Char)0x0,  /* [3792] */
    (xdc_Char)0x48,  /* [3793] */
    (xdc_Char)0x65,  /* [3794] */
    (xdc_Char)0x61,  /* [3795] */
    (xdc_Char)0x70,  /* [3796] */
    (xdc_Char)0x42,  /* [3797] */
    (xdc_Char)0x75,  /* [3798] */
    (xdc_Char)0x66,  /* [3799] */
    (xdc_Char)0x5f,  /* [3800] */
    (xdc_Char)0x63,  /* [3801] */
    (xdc_Char)0x72,  /* [3802] */
    (xdc_Char)0x65,  /* [3803] */
    (xdc_Char)0x61,  /* [3804] */
    (xdc_Char)0x74,  /* [3805] */
    (xdc_Char)0x65,  /* [3806] */
    (xdc_Char)0x27,  /* [3807] */
    (xdc_Char)0x73,  /* [3808] */
    (xdc_Char)0x20,  /* [3809] */
    (xdc_Char)0x62,  /* [3810] */
    (xdc_Char)0x75,  /* [3811] */
    (xdc_Char)0x66,  /* [3812] */
    (xdc_Char)0x53,  /* [3813] */
    (xdc_Char)0x69,  /* [3814] */
    (xdc_Char)0x7a,  /* [3815] */
    (xdc_Char)0x65,  /* [3816] */
    (xdc_Char)0x20,  /* [3817] */
    (xdc_Char)0x70,  /* [3818] */
    (xdc_Char)0x61,  /* [3819] */
    (xdc_Char)0x72,  /* [3820] */
    (xdc_Char)0x61,  /* [3821] */
    (xdc_Char)0x6d,  /* [3822] */
    (xdc_Char)0x65,  /* [3823] */
    (xdc_Char)0x74,  /* [3824] */
    (xdc_Char)0x65,  /* [3825] */
    (xdc_Char)0x72,  /* [3826] */
    (xdc_Char)0x20,  /* [3827] */
    (xdc_Char)0x69,  /* [3828] */
    (xdc_Char)0x73,  /* [3829] */
    (xdc_Char)0x20,  /* [3830] */
    (xdc_Char)0x69,  /* [3831] */
    (xdc_Char)0x6e,  /* [3832] */
    (xdc_Char)0x76,  /* [3833] */
    (xdc_Char)0x61,  /* [3834] */
    (xdc_Char)0x6c,  /* [3835] */
    (xdc_Char)0x69,  /* [3836] */
    (xdc_Char)0x64,  /* [3837] */
    (xdc_Char)0x20,  /* [3838] */
    (xdc_Char)0x28,  /* [3839] */
    (xdc_Char)0x74,  /* [3840] */
    (xdc_Char)0x6f,  /* [3841] */
    (xdc_Char)0x6f,  /* [3842] */
    (xdc_Char)0x20,  /* [3843] */
    (xdc_Char)0x73,  /* [3844] */
    (xdc_Char)0x6d,  /* [3845] */
    (xdc_Char)0x61,  /* [3846] */
    (xdc_Char)0x6c,  /* [3847] */
    (xdc_Char)0x6c,  /* [3848] */
    (xdc_Char)0x29,  /* [3849] */
    (xdc_Char)0x0,  /* [3850] */
    (xdc_Char)0x43,  /* [3851] */
    (xdc_Char)0x61,  /* [3852] */
    (xdc_Char)0x6e,  /* [3853] */
    (xdc_Char)0x6e,  /* [3854] */
    (xdc_Char)0x6f,  /* [3855] */
    (xdc_Char)0x74,  /* [3856] */
    (xdc_Char)0x20,  /* [3857] */
    (xdc_Char)0x63,  /* [3858] */
    (xdc_Char)0x61,  /* [3859] */
    (xdc_Char)0x6c,  /* [3860] */
    (xdc_Char)0x6c,  /* [3861] */
    (xdc_Char)0x20,  /* [3862] */
    (xdc_Char)0x48,  /* [3863] */
    (xdc_Char)0x65,  /* [3864] */
    (xdc_Char)0x61,  /* [3865] */
    (xdc_Char)0x70,  /* [3866] */
    (xdc_Char)0x42,  /* [3867] */
    (xdc_Char)0x75,  /* [3868] */
    (xdc_Char)0x66,  /* [3869] */
    (xdc_Char)0x5f,  /* [3870] */
    (xdc_Char)0x66,  /* [3871] */
    (xdc_Char)0x72,  /* [3872] */
    (xdc_Char)0x65,  /* [3873] */
    (xdc_Char)0x65,  /* [3874] */
    (xdc_Char)0x20,  /* [3875] */
    (xdc_Char)0x77,  /* [3876] */
    (xdc_Char)0x68,  /* [3877] */
    (xdc_Char)0x65,  /* [3878] */
    (xdc_Char)0x6e,  /* [3879] */
    (xdc_Char)0x20,  /* [3880] */
    (xdc_Char)0x6e,  /* [3881] */
    (xdc_Char)0x6f,  /* [3882] */
    (xdc_Char)0x20,  /* [3883] */
    (xdc_Char)0x62,  /* [3884] */
    (xdc_Char)0x6c,  /* [3885] */
    (xdc_Char)0x6f,  /* [3886] */
    (xdc_Char)0x63,  /* [3887] */
    (xdc_Char)0x6b,  /* [3888] */
    (xdc_Char)0x73,  /* [3889] */
    (xdc_Char)0x20,  /* [3890] */
    (xdc_Char)0x68,  /* [3891] */
    (xdc_Char)0x61,  /* [3892] */
    (xdc_Char)0x76,  /* [3893] */
    (xdc_Char)0x65,  /* [3894] */
    (xdc_Char)0x20,  /* [3895] */
    (xdc_Char)0x62,  /* [3896] */
    (xdc_Char)0x65,  /* [3897] */
    (xdc_Char)0x65,  /* [3898] */
    (xdc_Char)0x6e,  /* [3899] */
    (xdc_Char)0x20,  /* [3900] */
    (xdc_Char)0x61,  /* [3901] */
    (xdc_Char)0x6c,  /* [3902] */
    (xdc_Char)0x6c,  /* [3903] */
    (xdc_Char)0x6f,  /* [3904] */
    (xdc_Char)0x63,  /* [3905] */
    (xdc_Char)0x61,  /* [3906] */
    (xdc_Char)0x74,  /* [3907] */
    (xdc_Char)0x65,  /* [3908] */
    (xdc_Char)0x64,  /* [3909] */
    (xdc_Char)0x0,  /* [3910] */
    (xdc_Char)0x41,  /* [3911] */
    (xdc_Char)0x5f,  /* [3912] */
    (xdc_Char)0x69,  /* [3913] */
    (xdc_Char)0x6e,  /* [3914] */
    (xdc_Char)0x76,  /* [3915] */
    (xdc_Char)0x61,  /* [3916] */
    (xdc_Char)0x6c,  /* [3917] */
    (xdc_Char)0x69,  /* [3918] */
    (xdc_Char)0x64,  /* [3919] */
    (xdc_Char)0x46,  /* [3920] */
    (xdc_Char)0x72,  /* [3921] */
    (xdc_Char)0x65,  /* [3922] */
    (xdc_Char)0x65,  /* [3923] */
    (xdc_Char)0x3a,  /* [3924] */
    (xdc_Char)0x20,  /* [3925] */
    (xdc_Char)0x49,  /* [3926] */
    (xdc_Char)0x6e,  /* [3927] */
    (xdc_Char)0x76,  /* [3928] */
    (xdc_Char)0x61,  /* [3929] */
    (xdc_Char)0x6c,  /* [3930] */
    (xdc_Char)0x69,  /* [3931] */
    (xdc_Char)0x64,  /* [3932] */
    (xdc_Char)0x20,  /* [3933] */
    (xdc_Char)0x66,  /* [3934] */
    (xdc_Char)0x72,  /* [3935] */
    (xdc_Char)0x65,  /* [3936] */
    (xdc_Char)0x65,  /* [3937] */
    (xdc_Char)0x0,  /* [3938] */
    (xdc_Char)0x41,  /* [3939] */
    (xdc_Char)0x5f,  /* [3940] */
    (xdc_Char)0x7a,  /* [3941] */
    (xdc_Char)0x65,  /* [3942] */
    (xdc_Char)0x72,  /* [3943] */
    (xdc_Char)0x6f,  /* [3944] */
    (xdc_Char)0x42,  /* [3945] */
    (xdc_Char)0x6c,  /* [3946] */
    (xdc_Char)0x6f,  /* [3947] */
    (xdc_Char)0x63,  /* [3948] */
    (xdc_Char)0x6b,  /* [3949] */
    (xdc_Char)0x3a,  /* [3950] */
    (xdc_Char)0x20,  /* [3951] */
    (xdc_Char)0x43,  /* [3952] */
    (xdc_Char)0x61,  /* [3953] */
    (xdc_Char)0x6e,  /* [3954] */
    (xdc_Char)0x6e,  /* [3955] */
    (xdc_Char)0x6f,  /* [3956] */
    (xdc_Char)0x74,  /* [3957] */
    (xdc_Char)0x20,  /* [3958] */
    (xdc_Char)0x61,  /* [3959] */
    (xdc_Char)0x6c,  /* [3960] */
    (xdc_Char)0x6c,  /* [3961] */
    (xdc_Char)0x6f,  /* [3962] */
    (xdc_Char)0x63,  /* [3963] */
    (xdc_Char)0x61,  /* [3964] */
    (xdc_Char)0x74,  /* [3965] */
    (xdc_Char)0x65,  /* [3966] */
    (xdc_Char)0x20,  /* [3967] */
    (xdc_Char)0x73,  /* [3968] */
    (xdc_Char)0x69,  /* [3969] */
    (xdc_Char)0x7a,  /* [3970] */
    (xdc_Char)0x65,  /* [3971] */
    (xdc_Char)0x20,  /* [3972] */
    (xdc_Char)0x30,  /* [3973] */
    (xdc_Char)0x0,  /* [3974] */
    (xdc_Char)0x41,  /* [3975] */
    (xdc_Char)0x5f,  /* [3976] */
    (xdc_Char)0x68,  /* [3977] */
    (xdc_Char)0x65,  /* [3978] */
    (xdc_Char)0x61,  /* [3979] */
    (xdc_Char)0x70,  /* [3980] */
    (xdc_Char)0x53,  /* [3981] */
    (xdc_Char)0x69,  /* [3982] */
    (xdc_Char)0x7a,  /* [3983] */
    (xdc_Char)0x65,  /* [3984] */
    (xdc_Char)0x3a,  /* [3985] */
    (xdc_Char)0x20,  /* [3986] */
    (xdc_Char)0x52,  /* [3987] */
    (xdc_Char)0x65,  /* [3988] */
    (xdc_Char)0x71,  /* [3989] */
    (xdc_Char)0x75,  /* [3990] */
    (xdc_Char)0x65,  /* [3991] */
    (xdc_Char)0x73,  /* [3992] */
    (xdc_Char)0x74,  /* [3993] */
    (xdc_Char)0x65,  /* [3994] */
    (xdc_Char)0x64,  /* [3995] */
    (xdc_Char)0x20,  /* [3996] */
    (xdc_Char)0x68,  /* [3997] */
    (xdc_Char)0x65,  /* [3998] */
    (xdc_Char)0x61,  /* [3999] */
    (xdc_Char)0x70,  /* [4000] */
    (xdc_Char)0x20,  /* [4001] */
    (xdc_Char)0x73,  /* [4002] */
    (xdc_Char)0x69,  /* [4003] */
    (xdc_Char)0x7a,  /* [4004] */
    (xdc_Char)0x65,  /* [4005] */
    (xdc_Char)0x20,  /* [4006] */
    (xdc_Char)0x69,  /* [4007] */
    (xdc_Char)0x73,  /* [4008] */
    (xdc_Char)0x20,  /* [4009] */
    (xdc_Char)0x74,  /* [4010] */
    (xdc_Char)0x6f,  /* [4011] */
    (xdc_Char)0x6f,  /* [4012] */
    (xdc_Char)0x20,  /* [4013] */
    (xdc_Char)0x73,  /* [4014] */
    (xdc_Char)0x6d,  /* [4015] */
    (xdc_Char)0x61,  /* [4016] */
    (xdc_Char)0x6c,  /* [4017] */
    (xdc_Char)0x6c,  /* [4018] */
    (xdc_Char)0x0,  /* [4019] */
    (xdc_Char)0x41,  /* [4020] */
    (xdc_Char)0x5f,  /* [4021] */
    (xdc_Char)0x61,  /* [4022] */
    (xdc_Char)0x6c,  /* [4023] */
    (xdc_Char)0x69,  /* [4024] */
    (xdc_Char)0x67,  /* [4025] */
    (xdc_Char)0x6e,  /* [4026] */
    (xdc_Char)0x3a,  /* [4027] */
    (xdc_Char)0x20,  /* [4028] */
    (xdc_Char)0x52,  /* [4029] */
    (xdc_Char)0x65,  /* [4030] */
    (xdc_Char)0x71,  /* [4031] */
    (xdc_Char)0x75,  /* [4032] */
    (xdc_Char)0x65,  /* [4033] */
    (xdc_Char)0x73,  /* [4034] */
    (xdc_Char)0x74,  /* [4035] */
    (xdc_Char)0x65,  /* [4036] */
    (xdc_Char)0x64,  /* [4037] */
    (xdc_Char)0x20,  /* [4038] */
    (xdc_Char)0x61,  /* [4039] */
    (xdc_Char)0x6c,  /* [4040] */
    (xdc_Char)0x69,  /* [4041] */
    (xdc_Char)0x67,  /* [4042] */
    (xdc_Char)0x6e,  /* [4043] */
    (xdc_Char)0x20,  /* [4044] */
    (xdc_Char)0x69,  /* [4045] */
    (xdc_Char)0x73,  /* [4046] */
    (xdc_Char)0x20,  /* [4047] */
    (xdc_Char)0x6e,  /* [4048] */
    (xdc_Char)0x6f,  /* [4049] */
    (xdc_Char)0x74,  /* [4050] */
    (xdc_Char)0x20,  /* [4051] */
    (xdc_Char)0x61,  /* [4052] */
    (xdc_Char)0x20,  /* [4053] */
    (xdc_Char)0x70,  /* [4054] */
    (xdc_Char)0x6f,  /* [4055] */
    (xdc_Char)0x77,  /* [4056] */
    (xdc_Char)0x65,  /* [4057] */
    (xdc_Char)0x72,  /* [4058] */
    (xdc_Char)0x20,  /* [4059] */
    (xdc_Char)0x6f,  /* [4060] */
    (xdc_Char)0x66,  /* [4061] */
    (xdc_Char)0x20,  /* [4062] */
    (xdc_Char)0x32,  /* [4063] */
    (xdc_Char)0x0,  /* [4064] */
    (xdc_Char)0x49,  /* [4065] */
    (xdc_Char)0x6e,  /* [4066] */
    (xdc_Char)0x76,  /* [4067] */
    (xdc_Char)0x61,  /* [4068] */
    (xdc_Char)0x6c,  /* [4069] */
    (xdc_Char)0x69,  /* [4070] */
    (xdc_Char)0x64,  /* [4071] */
    (xdc_Char)0x20,  /* [4072] */
    (xdc_Char)0x62,  /* [4073] */
    (xdc_Char)0x6c,  /* [4074] */
    (xdc_Char)0x6f,  /* [4075] */
    (xdc_Char)0x63,  /* [4076] */
    (xdc_Char)0x6b,  /* [4077] */
    (xdc_Char)0x20,  /* [4078] */
    (xdc_Char)0x61,  /* [4079] */
    (xdc_Char)0x64,  /* [4080] */
    (xdc_Char)0x64,  /* [4081] */
    (xdc_Char)0x72,  /* [4082] */
    (xdc_Char)0x65,  /* [4083] */
    (xdc_Char)0x73,  /* [4084] */
    (xdc_Char)0x73,  /* [4085] */
    (xdc_Char)0x20,  /* [4086] */
    (xdc_Char)0x6f,  /* [4087] */
    (xdc_Char)0x6e,  /* [4088] */
    (xdc_Char)0x20,  /* [4089] */
    (xdc_Char)0x74,  /* [4090] */
    (xdc_Char)0x68,  /* [4091] */
    (xdc_Char)0x65,  /* [4092] */
    (xdc_Char)0x20,  /* [4093] */
    (xdc_Char)0x66,  /* [4094] */
    (xdc_Char)0x72,  /* [4095] */
    (xdc_Char)0x65,  /* [4096] */
    (xdc_Char)0x65,  /* [4097] */
    (xdc_Char)0x2e,  /* [4098] */
    (xdc_Char)0x20,  /* [4099] */
    (xdc_Char)0x46,  /* [4100] */
    (xdc_Char)0x61,  /* [4101] */
    (xdc_Char)0x69,  /* [4102] */
    (xdc_Char)0x6c,  /* [4103] */
    (xdc_Char)0x65,  /* [4104] */
    (xdc_Char)0x64,  /* [4105] */
    (xdc_Char)0x20,  /* [4106] */
    (xdc_Char)0x74,  /* [4107] */
    (xdc_Char)0x6f,  /* [4108] */
    (xdc_Char)0x20,  /* [4109] */
    (xdc_Char)0x66,  /* [4110] */
    (xdc_Char)0x72,  /* [4111] */
    (xdc_Char)0x65,  /* [4112] */
    (xdc_Char)0x65,  /* [4113] */
    (xdc_Char)0x20,  /* [4114] */
    (xdc_Char)0x62,  /* [4115] */
    (xdc_Char)0x6c,  /* [4116] */
    (xdc_Char)0x6f,  /* [4117] */
    (xdc_Char)0x63,  /* [4118] */
    (xdc_Char)0x6b,  /* [4119] */
    (xdc_Char)0x20,  /* [4120] */
    (xdc_Char)0x62,  /* [4121] */
    (xdc_Char)0x61,  /* [4122] */
    (xdc_Char)0x63,  /* [4123] */
    (xdc_Char)0x6b,  /* [4124] */
    (xdc_Char)0x20,  /* [4125] */
    (xdc_Char)0x74,  /* [4126] */
    (xdc_Char)0x6f,  /* [4127] */
    (xdc_Char)0x20,  /* [4128] */
    (xdc_Char)0x68,  /* [4129] */
    (xdc_Char)0x65,  /* [4130] */
    (xdc_Char)0x61,  /* [4131] */
    (xdc_Char)0x70,  /* [4132] */
    (xdc_Char)0x2e,  /* [4133] */
    (xdc_Char)0x0,  /* [4134] */
    (xdc_Char)0x41,  /* [4135] */
    (xdc_Char)0x5f,  /* [4136] */
    (xdc_Char)0x64,  /* [4137] */
    (xdc_Char)0x6f,  /* [4138] */
    (xdc_Char)0x75,  /* [4139] */
    (xdc_Char)0x62,  /* [4140] */
    (xdc_Char)0x6c,  /* [4141] */
    (xdc_Char)0x65,  /* [4142] */
    (xdc_Char)0x46,  /* [4143] */
    (xdc_Char)0x72,  /* [4144] */
    (xdc_Char)0x65,  /* [4145] */
    (xdc_Char)0x65,  /* [4146] */
    (xdc_Char)0x3a,  /* [4147] */
    (xdc_Char)0x20,  /* [4148] */
    (xdc_Char)0x42,  /* [4149] */
    (xdc_Char)0x75,  /* [4150] */
    (xdc_Char)0x66,  /* [4151] */
    (xdc_Char)0x66,  /* [4152] */
    (xdc_Char)0x65,  /* [4153] */
    (xdc_Char)0x72,  /* [4154] */
    (xdc_Char)0x20,  /* [4155] */
    (xdc_Char)0x61,  /* [4156] */
    (xdc_Char)0x6c,  /* [4157] */
    (xdc_Char)0x72,  /* [4158] */
    (xdc_Char)0x65,  /* [4159] */
    (xdc_Char)0x61,  /* [4160] */
    (xdc_Char)0x64,  /* [4161] */
    (xdc_Char)0x79,  /* [4162] */
    (xdc_Char)0x20,  /* [4163] */
    (xdc_Char)0x66,  /* [4164] */
    (xdc_Char)0x72,  /* [4165] */
    (xdc_Char)0x65,  /* [4166] */
    (xdc_Char)0x65,  /* [4167] */
    (xdc_Char)0x0,  /* [4168] */
    (xdc_Char)0x41,  /* [4169] */
    (xdc_Char)0x5f,  /* [4170] */
    (xdc_Char)0x62,  /* [4171] */
    (xdc_Char)0x75,  /* [4172] */
    (xdc_Char)0x66,  /* [4173] */
    (xdc_Char)0x4f,  /* [4174] */
    (xdc_Char)0x76,  /* [4175] */
    (xdc_Char)0x65,  /* [4176] */
    (xdc_Char)0x72,  /* [4177] */
    (xdc_Char)0x66,  /* [4178] */
    (xdc_Char)0x6c,  /* [4179] */
    (xdc_Char)0x6f,  /* [4180] */
    (xdc_Char)0x77,  /* [4181] */
    (xdc_Char)0x3a,  /* [4182] */
    (xdc_Char)0x20,  /* [4183] */
    (xdc_Char)0x42,  /* [4184] */
    (xdc_Char)0x75,  /* [4185] */
    (xdc_Char)0x66,  /* [4186] */
    (xdc_Char)0x66,  /* [4187] */
    (xdc_Char)0x65,  /* [4188] */
    (xdc_Char)0x72,  /* [4189] */
    (xdc_Char)0x20,  /* [4190] */
    (xdc_Char)0x6f,  /* [4191] */
    (xdc_Char)0x76,  /* [4192] */
    (xdc_Char)0x65,  /* [4193] */
    (xdc_Char)0x72,  /* [4194] */
    (xdc_Char)0x66,  /* [4195] */
    (xdc_Char)0x6c,  /* [4196] */
    (xdc_Char)0x6f,  /* [4197] */
    (xdc_Char)0x77,  /* [4198] */
    (xdc_Char)0x0,  /* [4199] */
    (xdc_Char)0x41,  /* [4200] */
    (xdc_Char)0x5f,  /* [4201] */
    (xdc_Char)0x6e,  /* [4202] */
    (xdc_Char)0x6f,  /* [4203] */
    (xdc_Char)0x74,  /* [4204] */
    (xdc_Char)0x45,  /* [4205] */
    (xdc_Char)0x6d,  /* [4206] */
    (xdc_Char)0x70,  /* [4207] */
    (xdc_Char)0x74,  /* [4208] */
    (xdc_Char)0x79,  /* [4209] */
    (xdc_Char)0x3a,  /* [4210] */
    (xdc_Char)0x20,  /* [4211] */
    (xdc_Char)0x48,  /* [4212] */
    (xdc_Char)0x65,  /* [4213] */
    (xdc_Char)0x61,  /* [4214] */
    (xdc_Char)0x70,  /* [4215] */
    (xdc_Char)0x20,  /* [4216] */
    (xdc_Char)0x6e,  /* [4217] */
    (xdc_Char)0x6f,  /* [4218] */
    (xdc_Char)0x74,  /* [4219] */
    (xdc_Char)0x20,  /* [4220] */
    (xdc_Char)0x65,  /* [4221] */
    (xdc_Char)0x6d,  /* [4222] */
    (xdc_Char)0x70,  /* [4223] */
    (xdc_Char)0x74,  /* [4224] */
    (xdc_Char)0x79,  /* [4225] */
    (xdc_Char)0x0,  /* [4226] */
    (xdc_Char)0x41,  /* [4227] */
    (xdc_Char)0x5f,  /* [4228] */
    (xdc_Char)0x6e,  /* [4229] */
    (xdc_Char)0x75,  /* [4230] */
    (xdc_Char)0x6c,  /* [4231] */
    (xdc_Char)0x6c,  /* [4232] */
    (xdc_Char)0x4f,  /* [4233] */
    (xdc_Char)0x62,  /* [4234] */
    (xdc_Char)0x6a,  /* [4235] */
    (xdc_Char)0x65,  /* [4236] */
    (xdc_Char)0x63,  /* [4237] */
    (xdc_Char)0x74,  /* [4238] */
    (xdc_Char)0x3a,  /* [4239] */
    (xdc_Char)0x20,  /* [4240] */
    (xdc_Char)0x48,  /* [4241] */
    (xdc_Char)0x65,  /* [4242] */
    (xdc_Char)0x61,  /* [4243] */
    (xdc_Char)0x70,  /* [4244] */
    (xdc_Char)0x54,  /* [4245] */
    (xdc_Char)0x72,  /* [4246] */
    (xdc_Char)0x61,  /* [4247] */
    (xdc_Char)0x63,  /* [4248] */
    (xdc_Char)0x6b,  /* [4249] */
    (xdc_Char)0x5f,  /* [4250] */
    (xdc_Char)0x70,  /* [4251] */
    (xdc_Char)0x72,  /* [4252] */
    (xdc_Char)0x69,  /* [4253] */
    (xdc_Char)0x6e,  /* [4254] */
    (xdc_Char)0x74,  /* [4255] */
    (xdc_Char)0x48,  /* [4256] */
    (xdc_Char)0x65,  /* [4257] */
    (xdc_Char)0x61,  /* [4258] */
    (xdc_Char)0x70,  /* [4259] */
    (xdc_Char)0x20,  /* [4260] */
    (xdc_Char)0x63,  /* [4261] */
    (xdc_Char)0x61,  /* [4262] */
    (xdc_Char)0x6c,  /* [4263] */
    (xdc_Char)0x6c,  /* [4264] */
    (xdc_Char)0x65,  /* [4265] */
    (xdc_Char)0x64,  /* [4266] */
    (xdc_Char)0x20,  /* [4267] */
    (xdc_Char)0x77,  /* [4268] */
    (xdc_Char)0x69,  /* [4269] */
    (xdc_Char)0x74,  /* [4270] */
    (xdc_Char)0x68,  /* [4271] */
    (xdc_Char)0x20,  /* [4272] */
    (xdc_Char)0x6e,  /* [4273] */
    (xdc_Char)0x75,  /* [4274] */
    (xdc_Char)0x6c,  /* [4275] */
    (xdc_Char)0x6c,  /* [4276] */
    (xdc_Char)0x20,  /* [4277] */
    (xdc_Char)0x6f,  /* [4278] */
    (xdc_Char)0x62,  /* [4279] */
    (xdc_Char)0x6a,  /* [4280] */
    (xdc_Char)0x0,  /* [4281] */
    (xdc_Char)0x61,  /* [4282] */
    (xdc_Char)0x73,  /* [4283] */
    (xdc_Char)0x73,  /* [4284] */
    (xdc_Char)0x65,  /* [4285] */
    (xdc_Char)0x72,  /* [4286] */
    (xdc_Char)0x74,  /* [4287] */
    (xdc_Char)0x69,  /* [4288] */
    (xdc_Char)0x6f,  /* [4289] */
    (xdc_Char)0x6e,  /* [4290] */
    (xdc_Char)0x20,  /* [4291] */
    (xdc_Char)0x66,  /* [4292] */
    (xdc_Char)0x61,  /* [4293] */
    (xdc_Char)0x69,  /* [4294] */
    (xdc_Char)0x6c,  /* [4295] */
    (xdc_Char)0x75,  /* [4296] */
    (xdc_Char)0x72,  /* [4297] */
    (xdc_Char)0x65,  /* [4298] */
    (xdc_Char)0x25,  /* [4299] */
    (xdc_Char)0x73,  /* [4300] */
    (xdc_Char)0x25,  /* [4301] */
    (xdc_Char)0x73,  /* [4302] */
    (xdc_Char)0x0,  /* [4303] */
    (xdc_Char)0x25,  /* [4304] */
    (xdc_Char)0x24,  /* [4305] */
    (xdc_Char)0x53,  /* [4306] */
    (xdc_Char)0x0,  /* [4307] */
    (xdc_Char)0x6f,  /* [4308] */
    (xdc_Char)0x75,  /* [4309] */
    (xdc_Char)0x74,  /* [4310] */
    (xdc_Char)0x20,  /* [4311] */
    (xdc_Char)0x6f,  /* [4312] */
    (xdc_Char)0x66,  /* [4313] */
    (xdc_Char)0x20,  /* [4314] */
    (xdc_Char)0x6d,  /* [4315] */
    (xdc_Char)0x65,  /* [4316] */
    (xdc_Char)0x6d,  /* [4317] */
    (xdc_Char)0x6f,  /* [4318] */
    (xdc_Char)0x72,  /* [4319] */
    (xdc_Char)0x79,  /* [4320] */
    (xdc_Char)0x3a,  /* [4321] */
    (xdc_Char)0x20,  /* [4322] */
    (xdc_Char)0x68,  /* [4323] */
    (xdc_Char)0x65,  /* [4324] */
    (xdc_Char)0x61,  /* [4325] */
    (xdc_Char)0x70,  /* [4326] */
    (xdc_Char)0x3d,  /* [4327] */
    (xdc_Char)0x30,  /* [4328] */
    (xdc_Char)0x78,  /* [4329] */
    (xdc_Char)0x25,  /* [4330] */
    (xdc_Char)0x78,  /* [4331] */
    (xdc_Char)0x2c,  /* [4332] */
    (xdc_Char)0x20,  /* [4333] */
    (xdc_Char)0x73,  /* [4334] */
    (xdc_Char)0x69,  /* [4335] */
    (xdc_Char)0x7a,  /* [4336] */
    (xdc_Char)0x65,  /* [4337] */
    (xdc_Char)0x3d,  /* [4338] */
    (xdc_Char)0x25,  /* [4339] */
    (xdc_Char)0x75,  /* [4340] */
    (xdc_Char)0x0,  /* [4341] */
    (xdc_Char)0x25,  /* [4342] */
    (xdc_Char)0x73,  /* [4343] */
    (xdc_Char)0x20,  /* [4344] */
    (xdc_Char)0x30,  /* [4345] */
    (xdc_Char)0x78,  /* [4346] */
    (xdc_Char)0x25,  /* [4347] */
    (xdc_Char)0x78,  /* [4348] */
    (xdc_Char)0x0,  /* [4349] */
    (xdc_Char)0x45,  /* [4350] */
    (xdc_Char)0x5f,  /* [4351] */
    (xdc_Char)0x62,  /* [4352] */
    (xdc_Char)0x61,  /* [4353] */
    (xdc_Char)0x64,  /* [4354] */
    (xdc_Char)0x4c,  /* [4355] */
    (xdc_Char)0x65,  /* [4356] */
    (xdc_Char)0x76,  /* [4357] */
    (xdc_Char)0x65,  /* [4358] */
    (xdc_Char)0x6c,  /* [4359] */
    (xdc_Char)0x3a,  /* [4360] */
    (xdc_Char)0x20,  /* [4361] */
    (xdc_Char)0x42,  /* [4362] */
    (xdc_Char)0x61,  /* [4363] */
    (xdc_Char)0x64,  /* [4364] */
    (xdc_Char)0x20,  /* [4365] */
    (xdc_Char)0x66,  /* [4366] */
    (xdc_Char)0x69,  /* [4367] */
    (xdc_Char)0x6c,  /* [4368] */
    (xdc_Char)0x74,  /* [4369] */
    (xdc_Char)0x65,  /* [4370] */
    (xdc_Char)0x72,  /* [4371] */
    (xdc_Char)0x20,  /* [4372] */
    (xdc_Char)0x6c,  /* [4373] */
    (xdc_Char)0x65,  /* [4374] */
    (xdc_Char)0x76,  /* [4375] */
    (xdc_Char)0x65,  /* [4376] */
    (xdc_Char)0x6c,  /* [4377] */
    (xdc_Char)0x20,  /* [4378] */
    (xdc_Char)0x76,  /* [4379] */
    (xdc_Char)0x61,  /* [4380] */
    (xdc_Char)0x6c,  /* [4381] */
    (xdc_Char)0x75,  /* [4382] */
    (xdc_Char)0x65,  /* [4383] */
    (xdc_Char)0x3a,  /* [4384] */
    (xdc_Char)0x20,  /* [4385] */
    (xdc_Char)0x25,  /* [4386] */
    (xdc_Char)0x64,  /* [4387] */
    (xdc_Char)0x0,  /* [4388] */
    (xdc_Char)0x66,  /* [4389] */
    (xdc_Char)0x72,  /* [4390] */
    (xdc_Char)0x65,  /* [4391] */
    (xdc_Char)0x65,  /* [4392] */
    (xdc_Char)0x28,  /* [4393] */
    (xdc_Char)0x29,  /* [4394] */
    (xdc_Char)0x20,  /* [4395] */
    (xdc_Char)0x69,  /* [4396] */
    (xdc_Char)0x6e,  /* [4397] */
    (xdc_Char)0x76,  /* [4398] */
    (xdc_Char)0x61,  /* [4399] */
    (xdc_Char)0x6c,  /* [4400] */
    (xdc_Char)0x69,  /* [4401] */
    (xdc_Char)0x64,  /* [4402] */
    (xdc_Char)0x20,  /* [4403] */
    (xdc_Char)0x69,  /* [4404] */
    (xdc_Char)0x6e,  /* [4405] */
    (xdc_Char)0x20,  /* [4406] */
    (xdc_Char)0x67,  /* [4407] */
    (xdc_Char)0x72,  /* [4408] */
    (xdc_Char)0x6f,  /* [4409] */
    (xdc_Char)0x77,  /* [4410] */
    (xdc_Char)0x74,  /* [4411] */
    (xdc_Char)0x68,  /* [4412] */
    (xdc_Char)0x2d,  /* [4413] */
    (xdc_Char)0x6f,  /* [4414] */
    (xdc_Char)0x6e,  /* [4415] */
    (xdc_Char)0x6c,  /* [4416] */
    (xdc_Char)0x79,  /* [4417] */
    (xdc_Char)0x20,  /* [4418] */
    (xdc_Char)0x48,  /* [4419] */
    (xdc_Char)0x65,  /* [4420] */
    (xdc_Char)0x61,  /* [4421] */
    (xdc_Char)0x70,  /* [4422] */
    (xdc_Char)0x4d,  /* [4423] */
    (xdc_Char)0x69,  /* [4424] */
    (xdc_Char)0x6e,  /* [4425] */
    (xdc_Char)0x0,  /* [4426] */
    (xdc_Char)0x54,  /* [4427] */
    (xdc_Char)0x68,  /* [4428] */
    (xdc_Char)0x65,  /* [4429] */
    (xdc_Char)0x20,  /* [4430] */
    (xdc_Char)0x52,  /* [4431] */
    (xdc_Char)0x54,  /* [4432] */
    (xdc_Char)0x53,  /* [4433] */
    (xdc_Char)0x20,  /* [4434] */
    (xdc_Char)0x68,  /* [4435] */
    (xdc_Char)0x65,  /* [4436] */
    (xdc_Char)0x61,  /* [4437] */
    (xdc_Char)0x70,  /* [4438] */
    (xdc_Char)0x20,  /* [4439] */
    (xdc_Char)0x69,  /* [4440] */
    (xdc_Char)0x73,  /* [4441] */
    (xdc_Char)0x20,  /* [4442] */
    (xdc_Char)0x75,  /* [4443] */
    (xdc_Char)0x73,  /* [4444] */
    (xdc_Char)0x65,  /* [4445] */
    (xdc_Char)0x64,  /* [4446] */
    (xdc_Char)0x20,  /* [4447] */
    (xdc_Char)0x75,  /* [4448] */
    (xdc_Char)0x70,  /* [4449] */
    (xdc_Char)0x2e,  /* [4450] */
    (xdc_Char)0x20,  /* [4451] */
    (xdc_Char)0x45,  /* [4452] */
    (xdc_Char)0x78,  /* [4453] */
    (xdc_Char)0x61,  /* [4454] */
    (xdc_Char)0x6d,  /* [4455] */
    (xdc_Char)0x69,  /* [4456] */
    (xdc_Char)0x6e,  /* [4457] */
    (xdc_Char)0x65,  /* [4458] */
    (xdc_Char)0x20,  /* [4459] */
    (xdc_Char)0x50,  /* [4460] */
    (xdc_Char)0x72,  /* [4461] */
    (xdc_Char)0x6f,  /* [4462] */
    (xdc_Char)0x67,  /* [4463] */
    (xdc_Char)0x72,  /* [4464] */
    (xdc_Char)0x61,  /* [4465] */
    (xdc_Char)0x6d,  /* [4466] */
    (xdc_Char)0x2e,  /* [4467] */
    (xdc_Char)0x68,  /* [4468] */
    (xdc_Char)0x65,  /* [4469] */
    (xdc_Char)0x61,  /* [4470] */
    (xdc_Char)0x70,  /* [4471] */
    (xdc_Char)0x2e,  /* [4472] */
    (xdc_Char)0x0,  /* [4473] */
    (xdc_Char)0x45,  /* [4474] */
    (xdc_Char)0x5f,  /* [4475] */
    (xdc_Char)0x62,  /* [4476] */
    (xdc_Char)0x61,  /* [4477] */
    (xdc_Char)0x64,  /* [4478] */
    (xdc_Char)0x43,  /* [4479] */
    (xdc_Char)0x6f,  /* [4480] */
    (xdc_Char)0x6d,  /* [4481] */
    (xdc_Char)0x6d,  /* [4482] */
    (xdc_Char)0x61,  /* [4483] */
    (xdc_Char)0x6e,  /* [4484] */
    (xdc_Char)0x64,  /* [4485] */
    (xdc_Char)0x3a,  /* [4486] */
    (xdc_Char)0x20,  /* [4487] */
    (xdc_Char)0x52,  /* [4488] */
    (xdc_Char)0x65,  /* [4489] */
    (xdc_Char)0x63,  /* [4490] */
    (xdc_Char)0x65,  /* [4491] */
    (xdc_Char)0x69,  /* [4492] */
    (xdc_Char)0x76,  /* [4493] */
    (xdc_Char)0x65,  /* [4494] */
    (xdc_Char)0x64,  /* [4495] */
    (xdc_Char)0x20,  /* [4496] */
    (xdc_Char)0x69,  /* [4497] */
    (xdc_Char)0x6e,  /* [4498] */
    (xdc_Char)0x76,  /* [4499] */
    (xdc_Char)0x61,  /* [4500] */
    (xdc_Char)0x6c,  /* [4501] */
    (xdc_Char)0x69,  /* [4502] */
    (xdc_Char)0x64,  /* [4503] */
    (xdc_Char)0x20,  /* [4504] */
    (xdc_Char)0x63,  /* [4505] */
    (xdc_Char)0x6f,  /* [4506] */
    (xdc_Char)0x6d,  /* [4507] */
    (xdc_Char)0x6d,  /* [4508] */
    (xdc_Char)0x61,  /* [4509] */
    (xdc_Char)0x6e,  /* [4510] */
    (xdc_Char)0x64,  /* [4511] */
    (xdc_Char)0x2c,  /* [4512] */
    (xdc_Char)0x20,  /* [4513] */
    (xdc_Char)0x69,  /* [4514] */
    (xdc_Char)0x64,  /* [4515] */
    (xdc_Char)0x3a,  /* [4516] */
    (xdc_Char)0x20,  /* [4517] */
    (xdc_Char)0x25,  /* [4518] */
    (xdc_Char)0x64,  /* [4519] */
    (xdc_Char)0x2e,  /* [4520] */
    (xdc_Char)0x0,  /* [4521] */
    (xdc_Char)0x45,  /* [4522] */
    (xdc_Char)0x5f,  /* [4523] */
    (xdc_Char)0x73,  /* [4524] */
    (xdc_Char)0x74,  /* [4525] */
    (xdc_Char)0x61,  /* [4526] */
    (xdc_Char)0x63,  /* [4527] */
    (xdc_Char)0x6b,  /* [4528] */
    (xdc_Char)0x4f,  /* [4529] */
    (xdc_Char)0x76,  /* [4530] */
    (xdc_Char)0x65,  /* [4531] */
    (xdc_Char)0x72,  /* [4532] */
    (xdc_Char)0x66,  /* [4533] */
    (xdc_Char)0x6c,  /* [4534] */
    (xdc_Char)0x6f,  /* [4535] */
    (xdc_Char)0x77,  /* [4536] */
    (xdc_Char)0x3a,  /* [4537] */
    (xdc_Char)0x20,  /* [4538] */
    (xdc_Char)0x54,  /* [4539] */
    (xdc_Char)0x61,  /* [4540] */
    (xdc_Char)0x73,  /* [4541] */
    (xdc_Char)0x6b,  /* [4542] */
    (xdc_Char)0x20,  /* [4543] */
    (xdc_Char)0x30,  /* [4544] */
    (xdc_Char)0x78,  /* [4545] */
    (xdc_Char)0x25,  /* [4546] */
    (xdc_Char)0x78,  /* [4547] */
    (xdc_Char)0x20,  /* [4548] */
    (xdc_Char)0x73,  /* [4549] */
    (xdc_Char)0x74,  /* [4550] */
    (xdc_Char)0x61,  /* [4551] */
    (xdc_Char)0x63,  /* [4552] */
    (xdc_Char)0x6b,  /* [4553] */
    (xdc_Char)0x20,  /* [4554] */
    (xdc_Char)0x6f,  /* [4555] */
    (xdc_Char)0x76,  /* [4556] */
    (xdc_Char)0x65,  /* [4557] */
    (xdc_Char)0x72,  /* [4558] */
    (xdc_Char)0x66,  /* [4559] */
    (xdc_Char)0x6c,  /* [4560] */
    (xdc_Char)0x6f,  /* [4561] */
    (xdc_Char)0x77,  /* [4562] */
    (xdc_Char)0x2e,  /* [4563] */
    (xdc_Char)0x0,  /* [4564] */
    (xdc_Char)0x45,  /* [4565] */
    (xdc_Char)0x5f,  /* [4566] */
    (xdc_Char)0x73,  /* [4567] */
    (xdc_Char)0x70,  /* [4568] */
    (xdc_Char)0x4f,  /* [4569] */
    (xdc_Char)0x75,  /* [4570] */
    (xdc_Char)0x74,  /* [4571] */
    (xdc_Char)0x4f,  /* [4572] */
    (xdc_Char)0x66,  /* [4573] */
    (xdc_Char)0x42,  /* [4574] */
    (xdc_Char)0x6f,  /* [4575] */
    (xdc_Char)0x75,  /* [4576] */
    (xdc_Char)0x6e,  /* [4577] */
    (xdc_Char)0x64,  /* [4578] */
    (xdc_Char)0x73,  /* [4579] */
    (xdc_Char)0x3a,  /* [4580] */
    (xdc_Char)0x20,  /* [4581] */
    (xdc_Char)0x54,  /* [4582] */
    (xdc_Char)0x61,  /* [4583] */
    (xdc_Char)0x73,  /* [4584] */
    (xdc_Char)0x6b,  /* [4585] */
    (xdc_Char)0x20,  /* [4586] */
    (xdc_Char)0x30,  /* [4587] */
    (xdc_Char)0x78,  /* [4588] */
    (xdc_Char)0x25,  /* [4589] */
    (xdc_Char)0x78,  /* [4590] */
    (xdc_Char)0x20,  /* [4591] */
    (xdc_Char)0x73,  /* [4592] */
    (xdc_Char)0x74,  /* [4593] */
    (xdc_Char)0x61,  /* [4594] */
    (xdc_Char)0x63,  /* [4595] */
    (xdc_Char)0x6b,  /* [4596] */
    (xdc_Char)0x20,  /* [4597] */
    (xdc_Char)0x65,  /* [4598] */
    (xdc_Char)0x72,  /* [4599] */
    (xdc_Char)0x72,  /* [4600] */
    (xdc_Char)0x6f,  /* [4601] */
    (xdc_Char)0x72,  /* [4602] */
    (xdc_Char)0x2c,  /* [4603] */
    (xdc_Char)0x20,  /* [4604] */
    (xdc_Char)0x53,  /* [4605] */
    (xdc_Char)0x50,  /* [4606] */
    (xdc_Char)0x20,  /* [4607] */
    (xdc_Char)0x3d,  /* [4608] */
    (xdc_Char)0x20,  /* [4609] */
    (xdc_Char)0x30,  /* [4610] */
    (xdc_Char)0x78,  /* [4611] */
    (xdc_Char)0x25,  /* [4612] */
    (xdc_Char)0x78,  /* [4613] */
    (xdc_Char)0x2e,  /* [4614] */
    (xdc_Char)0x0,  /* [4615] */
    (xdc_Char)0x45,  /* [4616] */
    (xdc_Char)0x5f,  /* [4617] */
    (xdc_Char)0x64,  /* [4618] */
    (xdc_Char)0x65,  /* [4619] */
    (xdc_Char)0x6c,  /* [4620] */
    (xdc_Char)0x65,  /* [4621] */
    (xdc_Char)0x74,  /* [4622] */
    (xdc_Char)0x65,  /* [4623] */
    (xdc_Char)0x4e,  /* [4624] */
    (xdc_Char)0x6f,  /* [4625] */
    (xdc_Char)0x74,  /* [4626] */
    (xdc_Char)0x41,  /* [4627] */
    (xdc_Char)0x6c,  /* [4628] */
    (xdc_Char)0x6c,  /* [4629] */
    (xdc_Char)0x6f,  /* [4630] */
    (xdc_Char)0x77,  /* [4631] */
    (xdc_Char)0x65,  /* [4632] */
    (xdc_Char)0x64,  /* [4633] */
    (xdc_Char)0x3a,  /* [4634] */
    (xdc_Char)0x20,  /* [4635] */
    (xdc_Char)0x54,  /* [4636] */
    (xdc_Char)0x61,  /* [4637] */
    (xdc_Char)0x73,  /* [4638] */
    (xdc_Char)0x6b,  /* [4639] */
    (xdc_Char)0x20,  /* [4640] */
    (xdc_Char)0x30,  /* [4641] */
    (xdc_Char)0x78,  /* [4642] */
    (xdc_Char)0x25,  /* [4643] */
    (xdc_Char)0x78,  /* [4644] */
    (xdc_Char)0x2e,  /* [4645] */
    (xdc_Char)0x0,  /* [4646] */
    (xdc_Char)0x45,  /* [4647] */
    (xdc_Char)0x5f,  /* [4648] */
    (xdc_Char)0x6d,  /* [4649] */
    (xdc_Char)0x6f,  /* [4650] */
    (xdc_Char)0x64,  /* [4651] */
    (xdc_Char)0x75,  /* [4652] */
    (xdc_Char)0x6c,  /* [4653] */
    (xdc_Char)0x65,  /* [4654] */
    (xdc_Char)0x53,  /* [4655] */
    (xdc_Char)0x74,  /* [4656] */
    (xdc_Char)0x61,  /* [4657] */
    (xdc_Char)0x74,  /* [4658] */
    (xdc_Char)0x65,  /* [4659] */
    (xdc_Char)0x43,  /* [4660] */
    (xdc_Char)0x68,  /* [4661] */
    (xdc_Char)0x65,  /* [4662] */
    (xdc_Char)0x63,  /* [4663] */
    (xdc_Char)0x6b,  /* [4664] */
    (xdc_Char)0x46,  /* [4665] */
    (xdc_Char)0x61,  /* [4666] */
    (xdc_Char)0x69,  /* [4667] */
    (xdc_Char)0x6c,  /* [4668] */
    (xdc_Char)0x65,  /* [4669] */
    (xdc_Char)0x64,  /* [4670] */
    (xdc_Char)0x3a,  /* [4671] */
    (xdc_Char)0x20,  /* [4672] */
    (xdc_Char)0x54,  /* [4673] */
    (xdc_Char)0x61,  /* [4674] */
    (xdc_Char)0x73,  /* [4675] */
    (xdc_Char)0x6b,  /* [4676] */
    (xdc_Char)0x20,  /* [4677] */
    (xdc_Char)0x6d,  /* [4678] */
    (xdc_Char)0x6f,  /* [4679] */
    (xdc_Char)0x64,  /* [4680] */
    (xdc_Char)0x75,  /* [4681] */
    (xdc_Char)0x6c,  /* [4682] */
    (xdc_Char)0x65,  /* [4683] */
    (xdc_Char)0x20,  /* [4684] */
    (xdc_Char)0x73,  /* [4685] */
    (xdc_Char)0x74,  /* [4686] */
    (xdc_Char)0x61,  /* [4687] */
    (xdc_Char)0x74,  /* [4688] */
    (xdc_Char)0x65,  /* [4689] */
    (xdc_Char)0x20,  /* [4690] */
    (xdc_Char)0x64,  /* [4691] */
    (xdc_Char)0x61,  /* [4692] */
    (xdc_Char)0x74,  /* [4693] */
    (xdc_Char)0x61,  /* [4694] */
    (xdc_Char)0x20,  /* [4695] */
    (xdc_Char)0x69,  /* [4696] */
    (xdc_Char)0x6e,  /* [4697] */
    (xdc_Char)0x74,  /* [4698] */
    (xdc_Char)0x65,  /* [4699] */
    (xdc_Char)0x67,  /* [4700] */
    (xdc_Char)0x72,  /* [4701] */
    (xdc_Char)0x69,  /* [4702] */
    (xdc_Char)0x74,  /* [4703] */
    (xdc_Char)0x79,  /* [4704] */
    (xdc_Char)0x20,  /* [4705] */
    (xdc_Char)0x63,  /* [4706] */
    (xdc_Char)0x68,  /* [4707] */
    (xdc_Char)0x65,  /* [4708] */
    (xdc_Char)0x63,  /* [4709] */
    (xdc_Char)0x6b,  /* [4710] */
    (xdc_Char)0x20,  /* [4711] */
    (xdc_Char)0x66,  /* [4712] */
    (xdc_Char)0x61,  /* [4713] */
    (xdc_Char)0x69,  /* [4714] */
    (xdc_Char)0x6c,  /* [4715] */
    (xdc_Char)0x65,  /* [4716] */
    (xdc_Char)0x64,  /* [4717] */
    (xdc_Char)0x2e,  /* [4718] */
    (xdc_Char)0x0,  /* [4719] */
    (xdc_Char)0x45,  /* [4720] */
    (xdc_Char)0x5f,  /* [4721] */
    (xdc_Char)0x6f,  /* [4722] */
    (xdc_Char)0x62,  /* [4723] */
    (xdc_Char)0x6a,  /* [4724] */
    (xdc_Char)0x65,  /* [4725] */
    (xdc_Char)0x63,  /* [4726] */
    (xdc_Char)0x74,  /* [4727] */
    (xdc_Char)0x43,  /* [4728] */
    (xdc_Char)0x68,  /* [4729] */
    (xdc_Char)0x65,  /* [4730] */
    (xdc_Char)0x63,  /* [4731] */
    (xdc_Char)0x6b,  /* [4732] */
    (xdc_Char)0x46,  /* [4733] */
    (xdc_Char)0x61,  /* [4734] */
    (xdc_Char)0x69,  /* [4735] */
    (xdc_Char)0x6c,  /* [4736] */
    (xdc_Char)0x65,  /* [4737] */
    (xdc_Char)0x64,  /* [4738] */
    (xdc_Char)0x3a,  /* [4739] */
    (xdc_Char)0x20,  /* [4740] */
    (xdc_Char)0x54,  /* [4741] */
    (xdc_Char)0x61,  /* [4742] */
    (xdc_Char)0x73,  /* [4743] */
    (xdc_Char)0x6b,  /* [4744] */
    (xdc_Char)0x20,  /* [4745] */
    (xdc_Char)0x30,  /* [4746] */
    (xdc_Char)0x78,  /* [4747] */
    (xdc_Char)0x25,  /* [4748] */
    (xdc_Char)0x78,  /* [4749] */
    (xdc_Char)0x20,  /* [4750] */
    (xdc_Char)0x6f,  /* [4751] */
    (xdc_Char)0x62,  /* [4752] */
    (xdc_Char)0x6a,  /* [4753] */
    (xdc_Char)0x65,  /* [4754] */
    (xdc_Char)0x63,  /* [4755] */
    (xdc_Char)0x74,  /* [4756] */
    (xdc_Char)0x20,  /* [4757] */
    (xdc_Char)0x64,  /* [4758] */
    (xdc_Char)0x61,  /* [4759] */
    (xdc_Char)0x74,  /* [4760] */
    (xdc_Char)0x61,  /* [4761] */
    (xdc_Char)0x20,  /* [4762] */
    (xdc_Char)0x69,  /* [4763] */
    (xdc_Char)0x6e,  /* [4764] */
    (xdc_Char)0x74,  /* [4765] */
    (xdc_Char)0x65,  /* [4766] */
    (xdc_Char)0x67,  /* [4767] */
    (xdc_Char)0x72,  /* [4768] */
    (xdc_Char)0x69,  /* [4769] */
    (xdc_Char)0x74,  /* [4770] */
    (xdc_Char)0x79,  /* [4771] */
    (xdc_Char)0x20,  /* [4772] */
    (xdc_Char)0x63,  /* [4773] */
    (xdc_Char)0x68,  /* [4774] */
    (xdc_Char)0x65,  /* [4775] */
    (xdc_Char)0x63,  /* [4776] */
    (xdc_Char)0x6b,  /* [4777] */
    (xdc_Char)0x20,  /* [4778] */
    (xdc_Char)0x66,  /* [4779] */
    (xdc_Char)0x61,  /* [4780] */
    (xdc_Char)0x69,  /* [4781] */
    (xdc_Char)0x6c,  /* [4782] */
    (xdc_Char)0x65,  /* [4783] */
    (xdc_Char)0x64,  /* [4784] */
    (xdc_Char)0x2e,  /* [4785] */
    (xdc_Char)0x0,  /* [4786] */
    (xdc_Char)0x45,  /* [4787] */
    (xdc_Char)0x5f,  /* [4788] */
    (xdc_Char)0x73,  /* [4789] */
    (xdc_Char)0x74,  /* [4790] */
    (xdc_Char)0x61,  /* [4791] */
    (xdc_Char)0x63,  /* [4792] */
    (xdc_Char)0x6b,  /* [4793] */
    (xdc_Char)0x4f,  /* [4794] */
    (xdc_Char)0x76,  /* [4795] */
    (xdc_Char)0x65,  /* [4796] */
    (xdc_Char)0x72,  /* [4797] */
    (xdc_Char)0x66,  /* [4798] */
    (xdc_Char)0x6c,  /* [4799] */
    (xdc_Char)0x6f,  /* [4800] */
    (xdc_Char)0x77,  /* [4801] */
    (xdc_Char)0x3a,  /* [4802] */
    (xdc_Char)0x20,  /* [4803] */
    (xdc_Char)0x49,  /* [4804] */
    (xdc_Char)0x53,  /* [4805] */
    (xdc_Char)0x52,  /* [4806] */
    (xdc_Char)0x20,  /* [4807] */
    (xdc_Char)0x73,  /* [4808] */
    (xdc_Char)0x74,  /* [4809] */
    (xdc_Char)0x61,  /* [4810] */
    (xdc_Char)0x63,  /* [4811] */
    (xdc_Char)0x6b,  /* [4812] */
    (xdc_Char)0x20,  /* [4813] */
    (xdc_Char)0x6f,  /* [4814] */
    (xdc_Char)0x76,  /* [4815] */
    (xdc_Char)0x65,  /* [4816] */
    (xdc_Char)0x72,  /* [4817] */
    (xdc_Char)0x66,  /* [4818] */
    (xdc_Char)0x6c,  /* [4819] */
    (xdc_Char)0x6f,  /* [4820] */
    (xdc_Char)0x77,  /* [4821] */
    (xdc_Char)0x2e,  /* [4822] */
    (xdc_Char)0x0,  /* [4823] */
    (xdc_Char)0x45,  /* [4824] */
    (xdc_Char)0x5f,  /* [4825] */
    (xdc_Char)0x61,  /* [4826] */
    (xdc_Char)0x6c,  /* [4827] */
    (xdc_Char)0x72,  /* [4828] */
    (xdc_Char)0x65,  /* [4829] */
    (xdc_Char)0x61,  /* [4830] */
    (xdc_Char)0x64,  /* [4831] */
    (xdc_Char)0x79,  /* [4832] */
    (xdc_Char)0x44,  /* [4833] */
    (xdc_Char)0x65,  /* [4834] */
    (xdc_Char)0x66,  /* [4835] */
    (xdc_Char)0x69,  /* [4836] */
    (xdc_Char)0x6e,  /* [4837] */
    (xdc_Char)0x65,  /* [4838] */
    (xdc_Char)0x64,  /* [4839] */
    (xdc_Char)0x3a,  /* [4840] */
    (xdc_Char)0x20,  /* [4841] */
    (xdc_Char)0x48,  /* [4842] */
    (xdc_Char)0x77,  /* [4843] */
    (xdc_Char)0x69,  /* [4844] */
    (xdc_Char)0x20,  /* [4845] */
    (xdc_Char)0x61,  /* [4846] */
    (xdc_Char)0x6c,  /* [4847] */
    (xdc_Char)0x72,  /* [4848] */
    (xdc_Char)0x65,  /* [4849] */
    (xdc_Char)0x61,  /* [4850] */
    (xdc_Char)0x64,  /* [4851] */
    (xdc_Char)0x79,  /* [4852] */
    (xdc_Char)0x20,  /* [4853] */
    (xdc_Char)0x64,  /* [4854] */
    (xdc_Char)0x65,  /* [4855] */
    (xdc_Char)0x66,  /* [4856] */
    (xdc_Char)0x69,  /* [4857] */
    (xdc_Char)0x6e,  /* [4858] */
    (xdc_Char)0x65,  /* [4859] */
    (xdc_Char)0x64,  /* [4860] */
    (xdc_Char)0x3a,  /* [4861] */
    (xdc_Char)0x20,  /* [4862] */
    (xdc_Char)0x69,  /* [4863] */
    (xdc_Char)0x6e,  /* [4864] */
    (xdc_Char)0x74,  /* [4865] */
    (xdc_Char)0x72,  /* [4866] */
    (xdc_Char)0x23,  /* [4867] */
    (xdc_Char)0x20,  /* [4868] */
    (xdc_Char)0x25,  /* [4869] */
    (xdc_Char)0x64,  /* [4870] */
    (xdc_Char)0x0,  /* [4871] */
    (xdc_Char)0x45,  /* [4872] */
    (xdc_Char)0x5f,  /* [4873] */
    (xdc_Char)0x68,  /* [4874] */
    (xdc_Char)0x77,  /* [4875] */
    (xdc_Char)0x69,  /* [4876] */
    (xdc_Char)0x4c,  /* [4877] */
    (xdc_Char)0x69,  /* [4878] */
    (xdc_Char)0x6d,  /* [4879] */
    (xdc_Char)0x69,  /* [4880] */
    (xdc_Char)0x74,  /* [4881] */
    (xdc_Char)0x45,  /* [4882] */
    (xdc_Char)0x78,  /* [4883] */
    (xdc_Char)0x63,  /* [4884] */
    (xdc_Char)0x65,  /* [4885] */
    (xdc_Char)0x65,  /* [4886] */
    (xdc_Char)0x64,  /* [4887] */
    (xdc_Char)0x65,  /* [4888] */
    (xdc_Char)0x64,  /* [4889] */
    (xdc_Char)0x3a,  /* [4890] */
    (xdc_Char)0x20,  /* [4891] */
    (xdc_Char)0x54,  /* [4892] */
    (xdc_Char)0x6f,  /* [4893] */
    (xdc_Char)0x6f,  /* [4894] */
    (xdc_Char)0x20,  /* [4895] */
    (xdc_Char)0x6d,  /* [4896] */
    (xdc_Char)0x61,  /* [4897] */
    (xdc_Char)0x6e,  /* [4898] */
    (xdc_Char)0x79,  /* [4899] */
    (xdc_Char)0x20,  /* [4900] */
    (xdc_Char)0x69,  /* [4901] */
    (xdc_Char)0x6e,  /* [4902] */
    (xdc_Char)0x74,  /* [4903] */
    (xdc_Char)0x65,  /* [4904] */
    (xdc_Char)0x72,  /* [4905] */
    (xdc_Char)0x72,  /* [4906] */
    (xdc_Char)0x75,  /* [4907] */
    (xdc_Char)0x70,  /* [4908] */
    (xdc_Char)0x74,  /* [4909] */
    (xdc_Char)0x73,  /* [4910] */
    (xdc_Char)0x20,  /* [4911] */
    (xdc_Char)0x64,  /* [4912] */
    (xdc_Char)0x65,  /* [4913] */
    (xdc_Char)0x66,  /* [4914] */
    (xdc_Char)0x69,  /* [4915] */
    (xdc_Char)0x6e,  /* [4916] */
    (xdc_Char)0x65,  /* [4917] */
    (xdc_Char)0x64,  /* [4918] */
    (xdc_Char)0x0,  /* [4919] */
    (xdc_Char)0x45,  /* [4920] */
    (xdc_Char)0x5f,  /* [4921] */
    (xdc_Char)0x65,  /* [4922] */
    (xdc_Char)0x78,  /* [4923] */
    (xdc_Char)0x63,  /* [4924] */
    (xdc_Char)0x65,  /* [4925] */
    (xdc_Char)0x70,  /* [4926] */
    (xdc_Char)0x74,  /* [4927] */
    (xdc_Char)0x69,  /* [4928] */
    (xdc_Char)0x6f,  /* [4929] */
    (xdc_Char)0x6e,  /* [4930] */
    (xdc_Char)0x3a,  /* [4931] */
    (xdc_Char)0x20,  /* [4932] */
    (xdc_Char)0x69,  /* [4933] */
    (xdc_Char)0x64,  /* [4934] */
    (xdc_Char)0x20,  /* [4935] */
    (xdc_Char)0x3d,  /* [4936] */
    (xdc_Char)0x20,  /* [4937] */
    (xdc_Char)0x25,  /* [4938] */
    (xdc_Char)0x64,  /* [4939] */
    (xdc_Char)0x2c,  /* [4940] */
    (xdc_Char)0x20,  /* [4941] */
    (xdc_Char)0x70,  /* [4942] */
    (xdc_Char)0x63,  /* [4943] */
    (xdc_Char)0x20,  /* [4944] */
    (xdc_Char)0x3d,  /* [4945] */
    (xdc_Char)0x20,  /* [4946] */
    (xdc_Char)0x25,  /* [4947] */
    (xdc_Char)0x30,  /* [4948] */
    (xdc_Char)0x38,  /* [4949] */
    (xdc_Char)0x78,  /* [4950] */
    (xdc_Char)0x2e,  /* [4951] */
    (xdc_Char)0xa,  /* [4952] */
    (xdc_Char)0x54,  /* [4953] */
    (xdc_Char)0x6f,  /* [4954] */
    (xdc_Char)0x20,  /* [4955] */
    (xdc_Char)0x73,  /* [4956] */
    (xdc_Char)0x65,  /* [4957] */
    (xdc_Char)0x65,  /* [4958] */
    (xdc_Char)0x20,  /* [4959] */
    (xdc_Char)0x6d,  /* [4960] */
    (xdc_Char)0x6f,  /* [4961] */
    (xdc_Char)0x72,  /* [4962] */
    (xdc_Char)0x65,  /* [4963] */
    (xdc_Char)0x20,  /* [4964] */
    (xdc_Char)0x65,  /* [4965] */
    (xdc_Char)0x78,  /* [4966] */
    (xdc_Char)0x63,  /* [4967] */
    (xdc_Char)0x65,  /* [4968] */
    (xdc_Char)0x70,  /* [4969] */
    (xdc_Char)0x74,  /* [4970] */
    (xdc_Char)0x69,  /* [4971] */
    (xdc_Char)0x6f,  /* [4972] */
    (xdc_Char)0x6e,  /* [4973] */
    (xdc_Char)0x20,  /* [4974] */
    (xdc_Char)0x64,  /* [4975] */
    (xdc_Char)0x65,  /* [4976] */
    (xdc_Char)0x74,  /* [4977] */
    (xdc_Char)0x61,  /* [4978] */
    (xdc_Char)0x69,  /* [4979] */
    (xdc_Char)0x6c,  /* [4980] */
    (xdc_Char)0x2c,  /* [4981] */
    (xdc_Char)0x20,  /* [4982] */
    (xdc_Char)0x73,  /* [4983] */
    (xdc_Char)0x65,  /* [4984] */
    (xdc_Char)0x74,  /* [4985] */
    (xdc_Char)0x20,  /* [4986] */
    (xdc_Char)0x74,  /* [4987] */
    (xdc_Char)0x69,  /* [4988] */
    (xdc_Char)0x2e,  /* [4989] */
    (xdc_Char)0x73,  /* [4990] */
    (xdc_Char)0x79,  /* [4991] */
    (xdc_Char)0x73,  /* [4992] */
    (xdc_Char)0x62,  /* [4993] */
    (xdc_Char)0x69,  /* [4994] */
    (xdc_Char)0x6f,  /* [4995] */
    (xdc_Char)0x73,  /* [4996] */
    (xdc_Char)0x2e,  /* [4997] */
    (xdc_Char)0x66,  /* [4998] */
    (xdc_Char)0x61,  /* [4999] */
    (xdc_Char)0x6d,  /* [5000] */
    (xdc_Char)0x69,  /* [5001] */
    (xdc_Char)0x6c,  /* [5002] */
    (xdc_Char)0x79,  /* [5003] */
    (xdc_Char)0x2e,  /* [5004] */
    (xdc_Char)0x61,  /* [5005] */
    (xdc_Char)0x72,  /* [5006] */
    (xdc_Char)0x6d,  /* [5007] */
    (xdc_Char)0x2e,  /* [5008] */
    (xdc_Char)0x6d,  /* [5009] */
    (xdc_Char)0x33,  /* [5010] */
    (xdc_Char)0x2e,  /* [5011] */
    (xdc_Char)0x48,  /* [5012] */
    (xdc_Char)0x77,  /* [5013] */
    (xdc_Char)0x69,  /* [5014] */
    (xdc_Char)0x2e,  /* [5015] */
    (xdc_Char)0x65,  /* [5016] */
    (xdc_Char)0x6e,  /* [5017] */
    (xdc_Char)0x61,  /* [5018] */
    (xdc_Char)0x62,  /* [5019] */
    (xdc_Char)0x6c,  /* [5020] */
    (xdc_Char)0x65,  /* [5021] */
    (xdc_Char)0x45,  /* [5022] */
    (xdc_Char)0x78,  /* [5023] */
    (xdc_Char)0x63,  /* [5024] */
    (xdc_Char)0x65,  /* [5025] */
    (xdc_Char)0x70,  /* [5026] */
    (xdc_Char)0x74,  /* [5027] */
    (xdc_Char)0x69,  /* [5028] */
    (xdc_Char)0x6f,  /* [5029] */
    (xdc_Char)0x6e,  /* [5030] */
    (xdc_Char)0x20,  /* [5031] */
    (xdc_Char)0x3d,  /* [5032] */
    (xdc_Char)0x20,  /* [5033] */
    (xdc_Char)0x74,  /* [5034] */
    (xdc_Char)0x72,  /* [5035] */
    (xdc_Char)0x75,  /* [5036] */
    (xdc_Char)0x65,  /* [5037] */
    (xdc_Char)0x20,  /* [5038] */
    (xdc_Char)0x6f,  /* [5039] */
    (xdc_Char)0x72,  /* [5040] */
    (xdc_Char)0x2c,  /* [5041] */
    (xdc_Char)0xa,  /* [5042] */
    (xdc_Char)0x65,  /* [5043] */
    (xdc_Char)0x78,  /* [5044] */
    (xdc_Char)0x61,  /* [5045] */
    (xdc_Char)0x6d,  /* [5046] */
    (xdc_Char)0x69,  /* [5047] */
    (xdc_Char)0x6e,  /* [5048] */
    (xdc_Char)0x65,  /* [5049] */
    (xdc_Char)0x20,  /* [5050] */
    (xdc_Char)0x74,  /* [5051] */
    (xdc_Char)0x68,  /* [5052] */
    (xdc_Char)0x65,  /* [5053] */
    (xdc_Char)0x20,  /* [5054] */
    (xdc_Char)0x45,  /* [5055] */
    (xdc_Char)0x78,  /* [5056] */
    (xdc_Char)0x63,  /* [5057] */
    (xdc_Char)0x65,  /* [5058] */
    (xdc_Char)0x70,  /* [5059] */
    (xdc_Char)0x74,  /* [5060] */
    (xdc_Char)0x69,  /* [5061] */
    (xdc_Char)0x6f,  /* [5062] */
    (xdc_Char)0x6e,  /* [5063] */
    (xdc_Char)0x20,  /* [5064] */
    (xdc_Char)0x76,  /* [5065] */
    (xdc_Char)0x69,  /* [5066] */
    (xdc_Char)0x65,  /* [5067] */
    (xdc_Char)0x77,  /* [5068] */
    (xdc_Char)0x20,  /* [5069] */
    (xdc_Char)0x66,  /* [5070] */
    (xdc_Char)0x6f,  /* [5071] */
    (xdc_Char)0x72,  /* [5072] */
    (xdc_Char)0x20,  /* [5073] */
    (xdc_Char)0x74,  /* [5074] */
    (xdc_Char)0x68,  /* [5075] */
    (xdc_Char)0x65,  /* [5076] */
    (xdc_Char)0x20,  /* [5077] */
    (xdc_Char)0x74,  /* [5078] */
    (xdc_Char)0x69,  /* [5079] */
    (xdc_Char)0x2e,  /* [5080] */
    (xdc_Char)0x73,  /* [5081] */
    (xdc_Char)0x79,  /* [5082] */
    (xdc_Char)0x73,  /* [5083] */
    (xdc_Char)0x62,  /* [5084] */
    (xdc_Char)0x69,  /* [5085] */
    (xdc_Char)0x6f,  /* [5086] */
    (xdc_Char)0x73,  /* [5087] */
    (xdc_Char)0x2e,  /* [5088] */
    (xdc_Char)0x66,  /* [5089] */
    (xdc_Char)0x61,  /* [5090] */
    (xdc_Char)0x6d,  /* [5091] */
    (xdc_Char)0x69,  /* [5092] */
    (xdc_Char)0x6c,  /* [5093] */
    (xdc_Char)0x79,  /* [5094] */
    (xdc_Char)0x2e,  /* [5095] */
    (xdc_Char)0x61,  /* [5096] */
    (xdc_Char)0x72,  /* [5097] */
    (xdc_Char)0x6d,  /* [5098] */
    (xdc_Char)0x2e,  /* [5099] */
    (xdc_Char)0x6d,  /* [5100] */
    (xdc_Char)0x33,  /* [5101] */
    (xdc_Char)0x2e,  /* [5102] */
    (xdc_Char)0x48,  /* [5103] */
    (xdc_Char)0x77,  /* [5104] */
    (xdc_Char)0x69,  /* [5105] */
    (xdc_Char)0x20,  /* [5106] */
    (xdc_Char)0x6d,  /* [5107] */
    (xdc_Char)0x6f,  /* [5108] */
    (xdc_Char)0x64,  /* [5109] */
    (xdc_Char)0x75,  /* [5110] */
    (xdc_Char)0x6c,  /* [5111] */
    (xdc_Char)0x65,  /* [5112] */
    (xdc_Char)0x20,  /* [5113] */
    (xdc_Char)0x75,  /* [5114] */
    (xdc_Char)0x73,  /* [5115] */
    (xdc_Char)0x69,  /* [5116] */
    (xdc_Char)0x6e,  /* [5117] */
    (xdc_Char)0x67,  /* [5118] */
    (xdc_Char)0x20,  /* [5119] */
    (xdc_Char)0x52,  /* [5120] */
    (xdc_Char)0x4f,  /* [5121] */
    (xdc_Char)0x56,  /* [5122] */
    (xdc_Char)0x2e,  /* [5123] */
    (xdc_Char)0x0,  /* [5124] */
    (xdc_Char)0x45,  /* [5125] */
    (xdc_Char)0x5f,  /* [5126] */
    (xdc_Char)0x6e,  /* [5127] */
    (xdc_Char)0x6f,  /* [5128] */
    (xdc_Char)0x49,  /* [5129] */
    (xdc_Char)0x73,  /* [5130] */
    (xdc_Char)0x72,  /* [5131] */
    (xdc_Char)0x3a,  /* [5132] */
    (xdc_Char)0x20,  /* [5133] */
    (xdc_Char)0x69,  /* [5134] */
    (xdc_Char)0x64,  /* [5135] */
    (xdc_Char)0x20,  /* [5136] */
    (xdc_Char)0x3d,  /* [5137] */
    (xdc_Char)0x20,  /* [5138] */
    (xdc_Char)0x25,  /* [5139] */
    (xdc_Char)0x64,  /* [5140] */
    (xdc_Char)0x2c,  /* [5141] */
    (xdc_Char)0x20,  /* [5142] */
    (xdc_Char)0x70,  /* [5143] */
    (xdc_Char)0x63,  /* [5144] */
    (xdc_Char)0x20,  /* [5145] */
    (xdc_Char)0x3d,  /* [5146] */
    (xdc_Char)0x20,  /* [5147] */
    (xdc_Char)0x25,  /* [5148] */
    (xdc_Char)0x30,  /* [5149] */
    (xdc_Char)0x38,  /* [5150] */
    (xdc_Char)0x78,  /* [5151] */
    (xdc_Char)0x0,  /* [5152] */
    (xdc_Char)0x45,  /* [5153] */
    (xdc_Char)0x5f,  /* [5154] */
    (xdc_Char)0x4e,  /* [5155] */
    (xdc_Char)0x4d,  /* [5156] */
    (xdc_Char)0x49,  /* [5157] */
    (xdc_Char)0x3a,  /* [5158] */
    (xdc_Char)0x20,  /* [5159] */
    (xdc_Char)0x25,  /* [5160] */
    (xdc_Char)0x73,  /* [5161] */
    (xdc_Char)0x0,  /* [5162] */
    (xdc_Char)0x45,  /* [5163] */
    (xdc_Char)0x5f,  /* [5164] */
    (xdc_Char)0x68,  /* [5165] */
    (xdc_Char)0x61,  /* [5166] */
    (xdc_Char)0x72,  /* [5167] */
    (xdc_Char)0x64,  /* [5168] */
    (xdc_Char)0x46,  /* [5169] */
    (xdc_Char)0x61,  /* [5170] */
    (xdc_Char)0x75,  /* [5171] */
    (xdc_Char)0x6c,  /* [5172] */
    (xdc_Char)0x74,  /* [5173] */
    (xdc_Char)0x3a,  /* [5174] */
    (xdc_Char)0x20,  /* [5175] */
    (xdc_Char)0x25,  /* [5176] */
    (xdc_Char)0x73,  /* [5177] */
    (xdc_Char)0x0,  /* [5178] */
    (xdc_Char)0x45,  /* [5179] */
    (xdc_Char)0x5f,  /* [5180] */
    (xdc_Char)0x6d,  /* [5181] */
    (xdc_Char)0x65,  /* [5182] */
    (xdc_Char)0x6d,  /* [5183] */
    (xdc_Char)0x46,  /* [5184] */
    (xdc_Char)0x61,  /* [5185] */
    (xdc_Char)0x75,  /* [5186] */
    (xdc_Char)0x6c,  /* [5187] */
    (xdc_Char)0x74,  /* [5188] */
    (xdc_Char)0x3a,  /* [5189] */
    (xdc_Char)0x20,  /* [5190] */
    (xdc_Char)0x25,  /* [5191] */
    (xdc_Char)0x73,  /* [5192] */
    (xdc_Char)0x2c,  /* [5193] */
    (xdc_Char)0x20,  /* [5194] */
    (xdc_Char)0x61,  /* [5195] */
    (xdc_Char)0x64,  /* [5196] */
    (xdc_Char)0x64,  /* [5197] */
    (xdc_Char)0x72,  /* [5198] */
    (xdc_Char)0x65,  /* [5199] */
    (xdc_Char)0x73,  /* [5200] */
    (xdc_Char)0x73,  /* [5201] */
    (xdc_Char)0x3a,  /* [5202] */
    (xdc_Char)0x20,  /* [5203] */
    (xdc_Char)0x25,  /* [5204] */
    (xdc_Char)0x30,  /* [5205] */
    (xdc_Char)0x38,  /* [5206] */
    (xdc_Char)0x78,  /* [5207] */
    (xdc_Char)0x0,  /* [5208] */
    (xdc_Char)0x45,  /* [5209] */
    (xdc_Char)0x5f,  /* [5210] */
    (xdc_Char)0x62,  /* [5211] */
    (xdc_Char)0x75,  /* [5212] */
    (xdc_Char)0x73,  /* [5213] */
    (xdc_Char)0x46,  /* [5214] */
    (xdc_Char)0x61,  /* [5215] */
    (xdc_Char)0x75,  /* [5216] */
    (xdc_Char)0x6c,  /* [5217] */
    (xdc_Char)0x74,  /* [5218] */
    (xdc_Char)0x3a,  /* [5219] */
    (xdc_Char)0x20,  /* [5220] */
    (xdc_Char)0x25,  /* [5221] */
    (xdc_Char)0x73,  /* [5222] */
    (xdc_Char)0x2c,  /* [5223] */
    (xdc_Char)0x20,  /* [5224] */
    (xdc_Char)0x61,  /* [5225] */
    (xdc_Char)0x64,  /* [5226] */
    (xdc_Char)0x64,  /* [5227] */
    (xdc_Char)0x72,  /* [5228] */
    (xdc_Char)0x65,  /* [5229] */
    (xdc_Char)0x73,  /* [5230] */
    (xdc_Char)0x73,  /* [5231] */
    (xdc_Char)0x3a,  /* [5232] */
    (xdc_Char)0x20,  /* [5233] */
    (xdc_Char)0x25,  /* [5234] */
    (xdc_Char)0x30,  /* [5235] */
    (xdc_Char)0x38,  /* [5236] */
    (xdc_Char)0x78,  /* [5237] */
    (xdc_Char)0x0,  /* [5238] */
    (xdc_Char)0x45,  /* [5239] */
    (xdc_Char)0x5f,  /* [5240] */
    (xdc_Char)0x75,  /* [5241] */
    (xdc_Char)0x73,  /* [5242] */
    (xdc_Char)0x61,  /* [5243] */
    (xdc_Char)0x67,  /* [5244] */
    (xdc_Char)0x65,  /* [5245] */
    (xdc_Char)0x46,  /* [5246] */
    (xdc_Char)0x61,  /* [5247] */
    (xdc_Char)0x75,  /* [5248] */
    (xdc_Char)0x6c,  /* [5249] */
    (xdc_Char)0x74,  /* [5250] */
    (xdc_Char)0x3a,  /* [5251] */
    (xdc_Char)0x20,  /* [5252] */
    (xdc_Char)0x25,  /* [5253] */
    (xdc_Char)0x73,  /* [5254] */
    (xdc_Char)0x0,  /* [5255] */
    (xdc_Char)0x45,  /* [5256] */
    (xdc_Char)0x5f,  /* [5257] */
    (xdc_Char)0x73,  /* [5258] */
    (xdc_Char)0x76,  /* [5259] */
    (xdc_Char)0x43,  /* [5260] */
    (xdc_Char)0x61,  /* [5261] */
    (xdc_Char)0x6c,  /* [5262] */
    (xdc_Char)0x6c,  /* [5263] */
    (xdc_Char)0x3a,  /* [5264] */
    (xdc_Char)0x20,  /* [5265] */
    (xdc_Char)0x73,  /* [5266] */
    (xdc_Char)0x76,  /* [5267] */
    (xdc_Char)0x4e,  /* [5268] */
    (xdc_Char)0x75,  /* [5269] */
    (xdc_Char)0x6d,  /* [5270] */
    (xdc_Char)0x20,  /* [5271] */
    (xdc_Char)0x3d,  /* [5272] */
    (xdc_Char)0x20,  /* [5273] */
    (xdc_Char)0x25,  /* [5274] */
    (xdc_Char)0x64,  /* [5275] */
    (xdc_Char)0x0,  /* [5276] */
    (xdc_Char)0x45,  /* [5277] */
    (xdc_Char)0x5f,  /* [5278] */
    (xdc_Char)0x64,  /* [5279] */
    (xdc_Char)0x65,  /* [5280] */
    (xdc_Char)0x62,  /* [5281] */
    (xdc_Char)0x75,  /* [5282] */
    (xdc_Char)0x67,  /* [5283] */
    (xdc_Char)0x4d,  /* [5284] */
    (xdc_Char)0x6f,  /* [5285] */
    (xdc_Char)0x6e,  /* [5286] */
    (xdc_Char)0x3a,  /* [5287] */
    (xdc_Char)0x20,  /* [5288] */
    (xdc_Char)0x25,  /* [5289] */
    (xdc_Char)0x73,  /* [5290] */
    (xdc_Char)0x0,  /* [5291] */
    (xdc_Char)0x45,  /* [5292] */
    (xdc_Char)0x5f,  /* [5293] */
    (xdc_Char)0x72,  /* [5294] */
    (xdc_Char)0x65,  /* [5295] */
    (xdc_Char)0x73,  /* [5296] */
    (xdc_Char)0x65,  /* [5297] */
    (xdc_Char)0x72,  /* [5298] */
    (xdc_Char)0x76,  /* [5299] */
    (xdc_Char)0x65,  /* [5300] */
    (xdc_Char)0x64,  /* [5301] */
    (xdc_Char)0x3a,  /* [5302] */
    (xdc_Char)0x20,  /* [5303] */
    (xdc_Char)0x25,  /* [5304] */
    (xdc_Char)0x73,  /* [5305] */
    (xdc_Char)0x20,  /* [5306] */
    (xdc_Char)0x25,  /* [5307] */
    (xdc_Char)0x64,  /* [5308] */
    (xdc_Char)0x0,  /* [5309] */
    (xdc_Char)0x45,  /* [5310] */
    (xdc_Char)0x5f,  /* [5311] */
    (xdc_Char)0x69,  /* [5312] */
    (xdc_Char)0x6e,  /* [5313] */
    (xdc_Char)0x76,  /* [5314] */
    (xdc_Char)0x61,  /* [5315] */
    (xdc_Char)0x6c,  /* [5316] */
    (xdc_Char)0x69,  /* [5317] */
    (xdc_Char)0x64,  /* [5318] */
    (xdc_Char)0x54,  /* [5319] */
    (xdc_Char)0x69,  /* [5320] */
    (xdc_Char)0x6d,  /* [5321] */
    (xdc_Char)0x65,  /* [5322] */
    (xdc_Char)0x72,  /* [5323] */
    (xdc_Char)0x3a,  /* [5324] */
    (xdc_Char)0x20,  /* [5325] */
    (xdc_Char)0x49,  /* [5326] */
    (xdc_Char)0x6e,  /* [5327] */
    (xdc_Char)0x76,  /* [5328] */
    (xdc_Char)0x61,  /* [5329] */
    (xdc_Char)0x6c,  /* [5330] */
    (xdc_Char)0x69,  /* [5331] */
    (xdc_Char)0x64,  /* [5332] */
    (xdc_Char)0x20,  /* [5333] */
    (xdc_Char)0x54,  /* [5334] */
    (xdc_Char)0x69,  /* [5335] */
    (xdc_Char)0x6d,  /* [5336] */
    (xdc_Char)0x65,  /* [5337] */
    (xdc_Char)0x72,  /* [5338] */
    (xdc_Char)0x20,  /* [5339] */
    (xdc_Char)0x49,  /* [5340] */
    (xdc_Char)0x64,  /* [5341] */
    (xdc_Char)0x20,  /* [5342] */
    (xdc_Char)0x25,  /* [5343] */
    (xdc_Char)0x64,  /* [5344] */
    (xdc_Char)0x0,  /* [5345] */
    (xdc_Char)0x45,  /* [5346] */
    (xdc_Char)0x5f,  /* [5347] */
    (xdc_Char)0x6e,  /* [5348] */
    (xdc_Char)0x6f,  /* [5349] */
    (xdc_Char)0x74,  /* [5350] */
    (xdc_Char)0x41,  /* [5351] */
    (xdc_Char)0x76,  /* [5352] */
    (xdc_Char)0x61,  /* [5353] */
    (xdc_Char)0x69,  /* [5354] */
    (xdc_Char)0x6c,  /* [5355] */
    (xdc_Char)0x61,  /* [5356] */
    (xdc_Char)0x62,  /* [5357] */
    (xdc_Char)0x6c,  /* [5358] */
    (xdc_Char)0x65,  /* [5359] */
    (xdc_Char)0x3a,  /* [5360] */
    (xdc_Char)0x20,  /* [5361] */
    (xdc_Char)0x54,  /* [5362] */
    (xdc_Char)0x69,  /* [5363] */
    (xdc_Char)0x6d,  /* [5364] */
    (xdc_Char)0x65,  /* [5365] */
    (xdc_Char)0x72,  /* [5366] */
    (xdc_Char)0x20,  /* [5367] */
    (xdc_Char)0x6e,  /* [5368] */
    (xdc_Char)0x6f,  /* [5369] */
    (xdc_Char)0x74,  /* [5370] */
    (xdc_Char)0x20,  /* [5371] */
    (xdc_Char)0x61,  /* [5372] */
    (xdc_Char)0x76,  /* [5373] */
    (xdc_Char)0x61,  /* [5374] */
    (xdc_Char)0x69,  /* [5375] */
    (xdc_Char)0x6c,  /* [5376] */
    (xdc_Char)0x61,  /* [5377] */
    (xdc_Char)0x62,  /* [5378] */
    (xdc_Char)0x6c,  /* [5379] */
    (xdc_Char)0x65,  /* [5380] */
    (xdc_Char)0x20,  /* [5381] */
    (xdc_Char)0x25,  /* [5382] */
    (xdc_Char)0x64,  /* [5383] */
    (xdc_Char)0x0,  /* [5384] */
    (xdc_Char)0x45,  /* [5385] */
    (xdc_Char)0x5f,  /* [5386] */
    (xdc_Char)0x63,  /* [5387] */
    (xdc_Char)0x61,  /* [5388] */
    (xdc_Char)0x6e,  /* [5389] */
    (xdc_Char)0x6e,  /* [5390] */
    (xdc_Char)0x6f,  /* [5391] */
    (xdc_Char)0x74,  /* [5392] */
    (xdc_Char)0x53,  /* [5393] */
    (xdc_Char)0x75,  /* [5394] */
    (xdc_Char)0x70,  /* [5395] */
    (xdc_Char)0x70,  /* [5396] */
    (xdc_Char)0x6f,  /* [5397] */
    (xdc_Char)0x72,  /* [5398] */
    (xdc_Char)0x74,  /* [5399] */
    (xdc_Char)0x3a,  /* [5400] */
    (xdc_Char)0x20,  /* [5401] */
    (xdc_Char)0x54,  /* [5402] */
    (xdc_Char)0x69,  /* [5403] */
    (xdc_Char)0x6d,  /* [5404] */
    (xdc_Char)0x65,  /* [5405] */
    (xdc_Char)0x72,  /* [5406] */
    (xdc_Char)0x20,  /* [5407] */
    (xdc_Char)0x63,  /* [5408] */
    (xdc_Char)0x61,  /* [5409] */
    (xdc_Char)0x6e,  /* [5410] */
    (xdc_Char)0x6e,  /* [5411] */
    (xdc_Char)0x6f,  /* [5412] */
    (xdc_Char)0x74,  /* [5413] */
    (xdc_Char)0x20,  /* [5414] */
    (xdc_Char)0x73,  /* [5415] */
    (xdc_Char)0x75,  /* [5416] */
    (xdc_Char)0x70,  /* [5417] */
    (xdc_Char)0x70,  /* [5418] */
    (xdc_Char)0x6f,  /* [5419] */
    (xdc_Char)0x72,  /* [5420] */
    (xdc_Char)0x74,  /* [5421] */
    (xdc_Char)0x20,  /* [5422] */
    (xdc_Char)0x72,  /* [5423] */
    (xdc_Char)0x65,  /* [5424] */
    (xdc_Char)0x71,  /* [5425] */
    (xdc_Char)0x75,  /* [5426] */
    (xdc_Char)0x65,  /* [5427] */
    (xdc_Char)0x73,  /* [5428] */
    (xdc_Char)0x74,  /* [5429] */
    (xdc_Char)0x65,  /* [5430] */
    (xdc_Char)0x64,  /* [5431] */
    (xdc_Char)0x20,  /* [5432] */
    (xdc_Char)0x70,  /* [5433] */
    (xdc_Char)0x65,  /* [5434] */
    (xdc_Char)0x72,  /* [5435] */
    (xdc_Char)0x69,  /* [5436] */
    (xdc_Char)0x6f,  /* [5437] */
    (xdc_Char)0x64,  /* [5438] */
    (xdc_Char)0x20,  /* [5439] */
    (xdc_Char)0x25,  /* [5440] */
    (xdc_Char)0x64,  /* [5441] */
    (xdc_Char)0x0,  /* [5442] */
    (xdc_Char)0x45,  /* [5443] */
    (xdc_Char)0x5f,  /* [5444] */
    (xdc_Char)0x6d,  /* [5445] */
    (xdc_Char)0x69,  /* [5446] */
    (xdc_Char)0x73,  /* [5447] */
    (xdc_Char)0x6d,  /* [5448] */
    (xdc_Char)0x61,  /* [5449] */
    (xdc_Char)0x74,  /* [5450] */
    (xdc_Char)0x63,  /* [5451] */
    (xdc_Char)0x68,  /* [5452] */
    (xdc_Char)0x65,  /* [5453] */
    (xdc_Char)0x64,  /* [5454] */
    (xdc_Char)0x49,  /* [5455] */
    (xdc_Char)0x64,  /* [5456] */
    (xdc_Char)0x73,  /* [5457] */
    (xdc_Char)0x3a,  /* [5458] */
    (xdc_Char)0x20,  /* [5459] */
    (xdc_Char)0x43,  /* [5460] */
    (xdc_Char)0x6f,  /* [5461] */
    (xdc_Char)0x72,  /* [5462] */
    (xdc_Char)0x65,  /* [5463] */
    (xdc_Char)0x5f,  /* [5464] */
    (xdc_Char)0x49,  /* [5465] */
    (xdc_Char)0x64,  /* [5466] */
    (xdc_Char)0x3a,  /* [5467] */
    (xdc_Char)0x20,  /* [5468] */
    (xdc_Char)0x25,  /* [5469] */
    (xdc_Char)0x64,  /* [5470] */
    (xdc_Char)0x20,  /* [5471] */
    (xdc_Char)0x64,  /* [5472] */
    (xdc_Char)0x6f,  /* [5473] */
    (xdc_Char)0x65,  /* [5474] */
    (xdc_Char)0x73,  /* [5475] */
    (xdc_Char)0x20,  /* [5476] */
    (xdc_Char)0x6e,  /* [5477] */
    (xdc_Char)0x6f,  /* [5478] */
    (xdc_Char)0x74,  /* [5479] */
    (xdc_Char)0x20,  /* [5480] */
    (xdc_Char)0x6d,  /* [5481] */
    (xdc_Char)0x61,  /* [5482] */
    (xdc_Char)0x74,  /* [5483] */
    (xdc_Char)0x63,  /* [5484] */
    (xdc_Char)0x68,  /* [5485] */
    (xdc_Char)0x20,  /* [5486] */
    (xdc_Char)0x68,  /* [5487] */
    (xdc_Char)0x61,  /* [5488] */
    (xdc_Char)0x72,  /* [5489] */
    (xdc_Char)0x64,  /* [5490] */
    (xdc_Char)0x77,  /* [5491] */
    (xdc_Char)0x61,  /* [5492] */
    (xdc_Char)0x72,  /* [5493] */
    (xdc_Char)0x65,  /* [5494] */
    (xdc_Char)0x20,  /* [5495] */
    (xdc_Char)0x63,  /* [5496] */
    (xdc_Char)0x6f,  /* [5497] */
    (xdc_Char)0x72,  /* [5498] */
    (xdc_Char)0x65,  /* [5499] */
    (xdc_Char)0x20,  /* [5500] */
    (xdc_Char)0x49,  /* [5501] */
    (xdc_Char)0x64,  /* [5502] */
    (xdc_Char)0x3a,  /* [5503] */
    (xdc_Char)0x20,  /* [5504] */
    (xdc_Char)0x25,  /* [5505] */
    (xdc_Char)0x64,  /* [5506] */
    (xdc_Char)0x0,  /* [5507] */
    (xdc_Char)0x45,  /* [5508] */
    (xdc_Char)0x5f,  /* [5509] */
    (xdc_Char)0x69,  /* [5510] */
    (xdc_Char)0x6e,  /* [5511] */
    (xdc_Char)0x76,  /* [5512] */
    (xdc_Char)0x61,  /* [5513] */
    (xdc_Char)0x6c,  /* [5514] */
    (xdc_Char)0x69,  /* [5515] */
    (xdc_Char)0x64,  /* [5516] */
    (xdc_Char)0x49,  /* [5517] */
    (xdc_Char)0x6e,  /* [5518] */
    (xdc_Char)0x64,  /* [5519] */
    (xdc_Char)0x65,  /* [5520] */
    (xdc_Char)0x78,  /* [5521] */
    (xdc_Char)0x20,  /* [5522] */
    (xdc_Char)0x25,  /* [5523] */
    (xdc_Char)0x64,  /* [5524] */
    (xdc_Char)0x0,  /* [5525] */
    (xdc_Char)0x45,  /* [5526] */
    (xdc_Char)0x5f,  /* [5527] */
    (xdc_Char)0x67,  /* [5528] */
    (xdc_Char)0x61,  /* [5529] */
    (xdc_Char)0x74,  /* [5530] */
    (xdc_Char)0x65,  /* [5531] */
    (xdc_Char)0x49,  /* [5532] */
    (xdc_Char)0x6e,  /* [5533] */
    (xdc_Char)0x55,  /* [5534] */
    (xdc_Char)0x73,  /* [5535] */
    (xdc_Char)0x65,  /* [5536] */
    (xdc_Char)0x20,  /* [5537] */
    (xdc_Char)0x25,  /* [5538] */
    (xdc_Char)0x64,  /* [5539] */
    (xdc_Char)0x0,  /* [5540] */
    (xdc_Char)0x45,  /* [5541] */
    (xdc_Char)0x5f,  /* [5542] */
    (xdc_Char)0x65,  /* [5543] */
    (xdc_Char)0x78,  /* [5544] */
    (xdc_Char)0x63,  /* [5545] */
    (xdc_Char)0x65,  /* [5546] */
    (xdc_Char)0x70,  /* [5547] */
    (xdc_Char)0x74,  /* [5548] */
    (xdc_Char)0x69,  /* [5549] */
    (xdc_Char)0x6f,  /* [5550] */
    (xdc_Char)0x6e,  /* [5551] */
    (xdc_Char)0x3a,  /* [5552] */
    (xdc_Char)0x20,  /* [5553] */
    (xdc_Char)0x4c,  /* [5554] */
    (xdc_Char)0x25,  /* [5555] */
    (xdc_Char)0x64,  /* [5556] */
    (xdc_Char)0x20,  /* [5557] */
    (xdc_Char)0x72,  /* [5558] */
    (xdc_Char)0x65,  /* [5559] */
    (xdc_Char)0x61,  /* [5560] */
    (xdc_Char)0x73,  /* [5561] */
    (xdc_Char)0x6f,  /* [5562] */
    (xdc_Char)0x6e,  /* [5563] */
    (xdc_Char)0x3a,  /* [5564] */
    (xdc_Char)0x20,  /* [5565] */
    (xdc_Char)0x30,  /* [5566] */
    (xdc_Char)0x78,  /* [5567] */
    (xdc_Char)0x25,  /* [5568] */
    (xdc_Char)0x78,  /* [5569] */
    (xdc_Char)0x0,  /* [5570] */
    (xdc_Char)0x45,  /* [5571] */
    (xdc_Char)0x5f,  /* [5572] */
    (xdc_Char)0x70,  /* [5573] */
    (xdc_Char)0x72,  /* [5574] */
    (xdc_Char)0x69,  /* [5575] */
    (xdc_Char)0x6f,  /* [5576] */
    (xdc_Char)0x72,  /* [5577] */
    (xdc_Char)0x69,  /* [5578] */
    (xdc_Char)0x74,  /* [5579] */
    (xdc_Char)0x79,  /* [5580] */
    (xdc_Char)0x3a,  /* [5581] */
    (xdc_Char)0x20,  /* [5582] */
    (xdc_Char)0x54,  /* [5583] */
    (xdc_Char)0x68,  /* [5584] */
    (xdc_Char)0x72,  /* [5585] */
    (xdc_Char)0x65,  /* [5586] */
    (xdc_Char)0x61,  /* [5587] */
    (xdc_Char)0x64,  /* [5588] */
    (xdc_Char)0x20,  /* [5589] */
    (xdc_Char)0x70,  /* [5590] */
    (xdc_Char)0x72,  /* [5591] */
    (xdc_Char)0x69,  /* [5592] */
    (xdc_Char)0x6f,  /* [5593] */
    (xdc_Char)0x72,  /* [5594] */
    (xdc_Char)0x69,  /* [5595] */
    (xdc_Char)0x74,  /* [5596] */
    (xdc_Char)0x79,  /* [5597] */
    (xdc_Char)0x20,  /* [5598] */
    (xdc_Char)0x69,  /* [5599] */
    (xdc_Char)0x73,  /* [5600] */
    (xdc_Char)0x20,  /* [5601] */
    (xdc_Char)0x69,  /* [5602] */
    (xdc_Char)0x6e,  /* [5603] */
    (xdc_Char)0x76,  /* [5604] */
    (xdc_Char)0x61,  /* [5605] */
    (xdc_Char)0x6c,  /* [5606] */
    (xdc_Char)0x69,  /* [5607] */
    (xdc_Char)0x64,  /* [5608] */
    (xdc_Char)0x20,  /* [5609] */
    (xdc_Char)0x25,  /* [5610] */
    (xdc_Char)0x64,  /* [5611] */
    (xdc_Char)0x0,  /* [5612] */
    (xdc_Char)0x72,  /* [5613] */
    (xdc_Char)0x65,  /* [5614] */
    (xdc_Char)0x71,  /* [5615] */
    (xdc_Char)0x75,  /* [5616] */
    (xdc_Char)0x65,  /* [5617] */
    (xdc_Char)0x73,  /* [5618] */
    (xdc_Char)0x74,  /* [5619] */
    (xdc_Char)0x65,  /* [5620] */
    (xdc_Char)0x64,  /* [5621] */
    (xdc_Char)0x20,  /* [5622] */
    (xdc_Char)0x73,  /* [5623] */
    (xdc_Char)0x69,  /* [5624] */
    (xdc_Char)0x7a,  /* [5625] */
    (xdc_Char)0x65,  /* [5626] */
    (xdc_Char)0x20,  /* [5627] */
    (xdc_Char)0x69,  /* [5628] */
    (xdc_Char)0x73,  /* [5629] */
    (xdc_Char)0x20,  /* [5630] */
    (xdc_Char)0x74,  /* [5631] */
    (xdc_Char)0x6f,  /* [5632] */
    (xdc_Char)0x6f,  /* [5633] */
    (xdc_Char)0x20,  /* [5634] */
    (xdc_Char)0x62,  /* [5635] */
    (xdc_Char)0x69,  /* [5636] */
    (xdc_Char)0x67,  /* [5637] */
    (xdc_Char)0x3a,  /* [5638] */
    (xdc_Char)0x20,  /* [5639] */
    (xdc_Char)0x68,  /* [5640] */
    (xdc_Char)0x61,  /* [5641] */
    (xdc_Char)0x6e,  /* [5642] */
    (xdc_Char)0x64,  /* [5643] */
    (xdc_Char)0x6c,  /* [5644] */
    (xdc_Char)0x65,  /* [5645] */
    (xdc_Char)0x3d,  /* [5646] */
    (xdc_Char)0x30,  /* [5647] */
    (xdc_Char)0x78,  /* [5648] */
    (xdc_Char)0x25,  /* [5649] */
    (xdc_Char)0x78,  /* [5650] */
    (xdc_Char)0x2c,  /* [5651] */
    (xdc_Char)0x20,  /* [5652] */
    (xdc_Char)0x73,  /* [5653] */
    (xdc_Char)0x69,  /* [5654] */
    (xdc_Char)0x7a,  /* [5655] */
    (xdc_Char)0x65,  /* [5656] */
    (xdc_Char)0x3d,  /* [5657] */
    (xdc_Char)0x25,  /* [5658] */
    (xdc_Char)0x75,  /* [5659] */
    (xdc_Char)0x0,  /* [5660] */
    (xdc_Char)0x6f,  /* [5661] */
    (xdc_Char)0x75,  /* [5662] */
    (xdc_Char)0x74,  /* [5663] */
    (xdc_Char)0x20,  /* [5664] */
    (xdc_Char)0x6f,  /* [5665] */
    (xdc_Char)0x66,  /* [5666] */
    (xdc_Char)0x20,  /* [5667] */
    (xdc_Char)0x6d,  /* [5668] */
    (xdc_Char)0x65,  /* [5669] */
    (xdc_Char)0x6d,  /* [5670] */
    (xdc_Char)0x6f,  /* [5671] */
    (xdc_Char)0x72,  /* [5672] */
    (xdc_Char)0x79,  /* [5673] */
    (xdc_Char)0x3a,  /* [5674] */
    (xdc_Char)0x20,  /* [5675] */
    (xdc_Char)0x68,  /* [5676] */
    (xdc_Char)0x61,  /* [5677] */
    (xdc_Char)0x6e,  /* [5678] */
    (xdc_Char)0x64,  /* [5679] */
    (xdc_Char)0x6c,  /* [5680] */
    (xdc_Char)0x65,  /* [5681] */
    (xdc_Char)0x3d,  /* [5682] */
    (xdc_Char)0x30,  /* [5683] */
    (xdc_Char)0x78,  /* [5684] */
    (xdc_Char)0x25,  /* [5685] */
    (xdc_Char)0x78,  /* [5686] */
    (xdc_Char)0x2c,  /* [5687] */
    (xdc_Char)0x20,  /* [5688] */
    (xdc_Char)0x73,  /* [5689] */
    (xdc_Char)0x69,  /* [5690] */
    (xdc_Char)0x7a,  /* [5691] */
    (xdc_Char)0x65,  /* [5692] */
    (xdc_Char)0x3d,  /* [5693] */
    (xdc_Char)0x25,  /* [5694] */
    (xdc_Char)0x75,  /* [5695] */
    (xdc_Char)0x0,  /* [5696] */
    (xdc_Char)0x3c,  /* [5697] */
    (xdc_Char)0x2d,  /* [5698] */
    (xdc_Char)0x2d,  /* [5699] */
    (xdc_Char)0x20,  /* [5700] */
    (xdc_Char)0x63,  /* [5701] */
    (xdc_Char)0x6f,  /* [5702] */
    (xdc_Char)0x6e,  /* [5703] */
    (xdc_Char)0x73,  /* [5704] */
    (xdc_Char)0x74,  /* [5705] */
    (xdc_Char)0x72,  /* [5706] */
    (xdc_Char)0x75,  /* [5707] */
    (xdc_Char)0x63,  /* [5708] */
    (xdc_Char)0x74,  /* [5709] */
    (xdc_Char)0x3a,  /* [5710] */
    (xdc_Char)0x20,  /* [5711] */
    (xdc_Char)0x25,  /* [5712] */
    (xdc_Char)0x70,  /* [5713] */
    (xdc_Char)0x28,  /* [5714] */
    (xdc_Char)0x27,  /* [5715] */
    (xdc_Char)0x25,  /* [5716] */
    (xdc_Char)0x73,  /* [5717] */
    (xdc_Char)0x27,  /* [5718] */
    (xdc_Char)0x29,  /* [5719] */
    (xdc_Char)0x0,  /* [5720] */
    (xdc_Char)0x3c,  /* [5721] */
    (xdc_Char)0x2d,  /* [5722] */
    (xdc_Char)0x2d,  /* [5723] */
    (xdc_Char)0x20,  /* [5724] */
    (xdc_Char)0x63,  /* [5725] */
    (xdc_Char)0x72,  /* [5726] */
    (xdc_Char)0x65,  /* [5727] */
    (xdc_Char)0x61,  /* [5728] */
    (xdc_Char)0x74,  /* [5729] */
    (xdc_Char)0x65,  /* [5730] */
    (xdc_Char)0x3a,  /* [5731] */
    (xdc_Char)0x20,  /* [5732] */
    (xdc_Char)0x25,  /* [5733] */
    (xdc_Char)0x70,  /* [5734] */
    (xdc_Char)0x28,  /* [5735] */
    (xdc_Char)0x27,  /* [5736] */
    (xdc_Char)0x25,  /* [5737] */
    (xdc_Char)0x73,  /* [5738] */
    (xdc_Char)0x27,  /* [5739] */
    (xdc_Char)0x29,  /* [5740] */
    (xdc_Char)0x0,  /* [5741] */
    (xdc_Char)0x2d,  /* [5742] */
    (xdc_Char)0x2d,  /* [5743] */
    (xdc_Char)0x3e,  /* [5744] */
    (xdc_Char)0x20,  /* [5745] */
    (xdc_Char)0x64,  /* [5746] */
    (xdc_Char)0x65,  /* [5747] */
    (xdc_Char)0x73,  /* [5748] */
    (xdc_Char)0x74,  /* [5749] */
    (xdc_Char)0x72,  /* [5750] */
    (xdc_Char)0x75,  /* [5751] */
    (xdc_Char)0x63,  /* [5752] */
    (xdc_Char)0x74,  /* [5753] */
    (xdc_Char)0x3a,  /* [5754] */
    (xdc_Char)0x20,  /* [5755] */
    (xdc_Char)0x28,  /* [5756] */
    (xdc_Char)0x25,  /* [5757] */
    (xdc_Char)0x70,  /* [5758] */
    (xdc_Char)0x29,  /* [5759] */
    (xdc_Char)0x0,  /* [5760] */
    (xdc_Char)0x2d,  /* [5761] */
    (xdc_Char)0x2d,  /* [5762] */
    (xdc_Char)0x3e,  /* [5763] */
    (xdc_Char)0x20,  /* [5764] */
    (xdc_Char)0x64,  /* [5765] */
    (xdc_Char)0x65,  /* [5766] */
    (xdc_Char)0x6c,  /* [5767] */
    (xdc_Char)0x65,  /* [5768] */
    (xdc_Char)0x74,  /* [5769] */
    (xdc_Char)0x65,  /* [5770] */
    (xdc_Char)0x3a,  /* [5771] */
    (xdc_Char)0x20,  /* [5772] */
    (xdc_Char)0x28,  /* [5773] */
    (xdc_Char)0x25,  /* [5774] */
    (xdc_Char)0x70,  /* [5775] */
    (xdc_Char)0x29,  /* [5776] */
    (xdc_Char)0x0,  /* [5777] */
    (xdc_Char)0x45,  /* [5778] */
    (xdc_Char)0x52,  /* [5779] */
    (xdc_Char)0x52,  /* [5780] */
    (xdc_Char)0x4f,  /* [5781] */
    (xdc_Char)0x52,  /* [5782] */
    (xdc_Char)0x3a,  /* [5783] */
    (xdc_Char)0x20,  /* [5784] */
    (xdc_Char)0x25,  /* [5785] */
    (xdc_Char)0x24,  /* [5786] */
    (xdc_Char)0x46,  /* [5787] */
    (xdc_Char)0x25,  /* [5788] */
    (xdc_Char)0x24,  /* [5789] */
    (xdc_Char)0x53,  /* [5790] */
    (xdc_Char)0x0,  /* [5791] */
    (xdc_Char)0x57,  /* [5792] */
    (xdc_Char)0x41,  /* [5793] */
    (xdc_Char)0x52,  /* [5794] */
    (xdc_Char)0x4e,  /* [5795] */
    (xdc_Char)0x49,  /* [5796] */
    (xdc_Char)0x4e,  /* [5797] */
    (xdc_Char)0x47,  /* [5798] */
    (xdc_Char)0x3a,  /* [5799] */
    (xdc_Char)0x20,  /* [5800] */
    (xdc_Char)0x25,  /* [5801] */
    (xdc_Char)0x24,  /* [5802] */
    (xdc_Char)0x46,  /* [5803] */
    (xdc_Char)0x25,  /* [5804] */
    (xdc_Char)0x24,  /* [5805] */
    (xdc_Char)0x53,  /* [5806] */
    (xdc_Char)0x0,  /* [5807] */
    (xdc_Char)0x25,  /* [5808] */
    (xdc_Char)0x24,  /* [5809] */
    (xdc_Char)0x46,  /* [5810] */
    (xdc_Char)0x25,  /* [5811] */
    (xdc_Char)0x24,  /* [5812] */
    (xdc_Char)0x53,  /* [5813] */
    (xdc_Char)0x0,  /* [5814] */
    (xdc_Char)0x53,  /* [5815] */
    (xdc_Char)0x74,  /* [5816] */
    (xdc_Char)0x61,  /* [5817] */
    (xdc_Char)0x72,  /* [5818] */
    (xdc_Char)0x74,  /* [5819] */
    (xdc_Char)0x3a,  /* [5820] */
    (xdc_Char)0x20,  /* [5821] */
    (xdc_Char)0x25,  /* [5822] */
    (xdc_Char)0x24,  /* [5823] */
    (xdc_Char)0x53,  /* [5824] */
    (xdc_Char)0x0,  /* [5825] */
    (xdc_Char)0x53,  /* [5826] */
    (xdc_Char)0x74,  /* [5827] */
    (xdc_Char)0x6f,  /* [5828] */
    (xdc_Char)0x70,  /* [5829] */
    (xdc_Char)0x3a,  /* [5830] */
    (xdc_Char)0x20,  /* [5831] */
    (xdc_Char)0x25,  /* [5832] */
    (xdc_Char)0x24,  /* [5833] */
    (xdc_Char)0x53,  /* [5834] */
    (xdc_Char)0x0,  /* [5835] */
    (xdc_Char)0x53,  /* [5836] */
    (xdc_Char)0x74,  /* [5837] */
    (xdc_Char)0x61,  /* [5838] */
    (xdc_Char)0x72,  /* [5839] */
    (xdc_Char)0x74,  /* [5840] */
    (xdc_Char)0x49,  /* [5841] */
    (xdc_Char)0x6e,  /* [5842] */
    (xdc_Char)0x73,  /* [5843] */
    (xdc_Char)0x74,  /* [5844] */
    (xdc_Char)0x61,  /* [5845] */
    (xdc_Char)0x6e,  /* [5846] */
    (xdc_Char)0x63,  /* [5847] */
    (xdc_Char)0x65,  /* [5848] */
    (xdc_Char)0x3a,  /* [5849] */
    (xdc_Char)0x20,  /* [5850] */
    (xdc_Char)0x25,  /* [5851] */
    (xdc_Char)0x24,  /* [5852] */
    (xdc_Char)0x53,  /* [5853] */
    (xdc_Char)0x0,  /* [5854] */
    (xdc_Char)0x53,  /* [5855] */
    (xdc_Char)0x74,  /* [5856] */
    (xdc_Char)0x6f,  /* [5857] */
    (xdc_Char)0x70,  /* [5858] */
    (xdc_Char)0x49,  /* [5859] */
    (xdc_Char)0x6e,  /* [5860] */
    (xdc_Char)0x73,  /* [5861] */
    (xdc_Char)0x74,  /* [5862] */
    (xdc_Char)0x61,  /* [5863] */
    (xdc_Char)0x6e,  /* [5864] */
    (xdc_Char)0x63,  /* [5865] */
    (xdc_Char)0x65,  /* [5866] */
    (xdc_Char)0x3a,  /* [5867] */
    (xdc_Char)0x20,  /* [5868] */
    (xdc_Char)0x25,  /* [5869] */
    (xdc_Char)0x24,  /* [5870] */
    (xdc_Char)0x53,  /* [5871] */
    (xdc_Char)0x0,  /* [5872] */
    (xdc_Char)0x4c,  /* [5873] */
    (xdc_Char)0x57,  /* [5874] */
    (xdc_Char)0x5f,  /* [5875] */
    (xdc_Char)0x64,  /* [5876] */
    (xdc_Char)0x65,  /* [5877] */
    (xdc_Char)0x6c,  /* [5878] */
    (xdc_Char)0x61,  /* [5879] */
    (xdc_Char)0x79,  /* [5880] */
    (xdc_Char)0x65,  /* [5881] */
    (xdc_Char)0x64,  /* [5882] */
    (xdc_Char)0x3a,  /* [5883] */
    (xdc_Char)0x20,  /* [5884] */
    (xdc_Char)0x64,  /* [5885] */
    (xdc_Char)0x65,  /* [5886] */
    (xdc_Char)0x6c,  /* [5887] */
    (xdc_Char)0x61,  /* [5888] */
    (xdc_Char)0x79,  /* [5889] */
    (xdc_Char)0x3a,  /* [5890] */
    (xdc_Char)0x20,  /* [5891] */
    (xdc_Char)0x25,  /* [5892] */
    (xdc_Char)0x64,  /* [5893] */
    (xdc_Char)0x0,  /* [5894] */
    (xdc_Char)0x4c,  /* [5895] */
    (xdc_Char)0x4d,  /* [5896] */
    (xdc_Char)0x5f,  /* [5897] */
    (xdc_Char)0x74,  /* [5898] */
    (xdc_Char)0x69,  /* [5899] */
    (xdc_Char)0x63,  /* [5900] */
    (xdc_Char)0x6b,  /* [5901] */
    (xdc_Char)0x3a,  /* [5902] */
    (xdc_Char)0x20,  /* [5903] */
    (xdc_Char)0x74,  /* [5904] */
    (xdc_Char)0x69,  /* [5905] */
    (xdc_Char)0x63,  /* [5906] */
    (xdc_Char)0x6b,  /* [5907] */
    (xdc_Char)0x3a,  /* [5908] */
    (xdc_Char)0x20,  /* [5909] */
    (xdc_Char)0x25,  /* [5910] */
    (xdc_Char)0x64,  /* [5911] */
    (xdc_Char)0x0,  /* [5912] */
    (xdc_Char)0x4c,  /* [5913] */
    (xdc_Char)0x4d,  /* [5914] */
    (xdc_Char)0x5f,  /* [5915] */
    (xdc_Char)0x62,  /* [5916] */
    (xdc_Char)0x65,  /* [5917] */
    (xdc_Char)0x67,  /* [5918] */
    (xdc_Char)0x69,  /* [5919] */
    (xdc_Char)0x6e,  /* [5920] */
    (xdc_Char)0x3a,  /* [5921] */
    (xdc_Char)0x20,  /* [5922] */
    (xdc_Char)0x63,  /* [5923] */
    (xdc_Char)0x6c,  /* [5924] */
    (xdc_Char)0x6b,  /* [5925] */
    (xdc_Char)0x3a,  /* [5926] */
    (xdc_Char)0x20,  /* [5927] */
    (xdc_Char)0x30,  /* [5928] */
    (xdc_Char)0x78,  /* [5929] */
    (xdc_Char)0x25,  /* [5930] */
    (xdc_Char)0x78,  /* [5931] */
    (xdc_Char)0x2c,  /* [5932] */
    (xdc_Char)0x20,  /* [5933] */
    (xdc_Char)0x66,  /* [5934] */
    (xdc_Char)0x75,  /* [5935] */
    (xdc_Char)0x6e,  /* [5936] */
    (xdc_Char)0x63,  /* [5937] */
    (xdc_Char)0x3a,  /* [5938] */
    (xdc_Char)0x20,  /* [5939] */
    (xdc_Char)0x30,  /* [5940] */
    (xdc_Char)0x78,  /* [5941] */
    (xdc_Char)0x25,  /* [5942] */
    (xdc_Char)0x78,  /* [5943] */
    (xdc_Char)0x0,  /* [5944] */
    (xdc_Char)0x4c,  /* [5945] */
    (xdc_Char)0x4d,  /* [5946] */
    (xdc_Char)0x5f,  /* [5947] */
    (xdc_Char)0x70,  /* [5948] */
    (xdc_Char)0x6f,  /* [5949] */
    (xdc_Char)0x73,  /* [5950] */
    (xdc_Char)0x74,  /* [5951] */
    (xdc_Char)0x3a,  /* [5952] */
    (xdc_Char)0x20,  /* [5953] */
    (xdc_Char)0x73,  /* [5954] */
    (xdc_Char)0x65,  /* [5955] */
    (xdc_Char)0x6d,  /* [5956] */
    (xdc_Char)0x3a,  /* [5957] */
    (xdc_Char)0x20,  /* [5958] */
    (xdc_Char)0x30,  /* [5959] */
    (xdc_Char)0x78,  /* [5960] */
    (xdc_Char)0x25,  /* [5961] */
    (xdc_Char)0x78,  /* [5962] */
    (xdc_Char)0x2c,  /* [5963] */
    (xdc_Char)0x20,  /* [5964] */
    (xdc_Char)0x63,  /* [5965] */
    (xdc_Char)0x6f,  /* [5966] */
    (xdc_Char)0x75,  /* [5967] */
    (xdc_Char)0x6e,  /* [5968] */
    (xdc_Char)0x74,  /* [5969] */
    (xdc_Char)0x3a,  /* [5970] */
    (xdc_Char)0x20,  /* [5971] */
    (xdc_Char)0x25,  /* [5972] */
    (xdc_Char)0x64,  /* [5973] */
    (xdc_Char)0x0,  /* [5974] */
    (xdc_Char)0x4c,  /* [5975] */
    (xdc_Char)0x4d,  /* [5976] */
    (xdc_Char)0x5f,  /* [5977] */
    (xdc_Char)0x70,  /* [5978] */
    (xdc_Char)0x65,  /* [5979] */
    (xdc_Char)0x6e,  /* [5980] */
    (xdc_Char)0x64,  /* [5981] */
    (xdc_Char)0x3a,  /* [5982] */
    (xdc_Char)0x20,  /* [5983] */
    (xdc_Char)0x73,  /* [5984] */
    (xdc_Char)0x65,  /* [5985] */
    (xdc_Char)0x6d,  /* [5986] */
    (xdc_Char)0x3a,  /* [5987] */
    (xdc_Char)0x20,  /* [5988] */
    (xdc_Char)0x30,  /* [5989] */
    (xdc_Char)0x78,  /* [5990] */
    (xdc_Char)0x25,  /* [5991] */
    (xdc_Char)0x78,  /* [5992] */
    (xdc_Char)0x2c,  /* [5993] */
    (xdc_Char)0x20,  /* [5994] */
    (xdc_Char)0x63,  /* [5995] */
    (xdc_Char)0x6f,  /* [5996] */
    (xdc_Char)0x75,  /* [5997] */
    (xdc_Char)0x6e,  /* [5998] */
    (xdc_Char)0x74,  /* [5999] */
    (xdc_Char)0x3a,  /* [6000] */
    (xdc_Char)0x20,  /* [6001] */
    (xdc_Char)0x25,  /* [6002] */
    (xdc_Char)0x64,  /* [6003] */
    (xdc_Char)0x2c,  /* [6004] */
    (xdc_Char)0x20,  /* [6005] */
    (xdc_Char)0x74,  /* [6006] */
    (xdc_Char)0x69,  /* [6007] */
    (xdc_Char)0x6d,  /* [6008] */
    (xdc_Char)0x65,  /* [6009] */
    (xdc_Char)0x6f,  /* [6010] */
    (xdc_Char)0x75,  /* [6011] */
    (xdc_Char)0x74,  /* [6012] */
    (xdc_Char)0x3a,  /* [6013] */
    (xdc_Char)0x20,  /* [6014] */
    (xdc_Char)0x25,  /* [6015] */
    (xdc_Char)0x64,  /* [6016] */
    (xdc_Char)0x0,  /* [6017] */
    (xdc_Char)0x4c,  /* [6018] */
    (xdc_Char)0x4d,  /* [6019] */
    (xdc_Char)0x5f,  /* [6020] */
    (xdc_Char)0x62,  /* [6021] */
    (xdc_Char)0x65,  /* [6022] */
    (xdc_Char)0x67,  /* [6023] */
    (xdc_Char)0x69,  /* [6024] */
    (xdc_Char)0x6e,  /* [6025] */
    (xdc_Char)0x3a,  /* [6026] */
    (xdc_Char)0x20,  /* [6027] */
    (xdc_Char)0x73,  /* [6028] */
    (xdc_Char)0x77,  /* [6029] */
    (xdc_Char)0x69,  /* [6030] */
    (xdc_Char)0x3a,  /* [6031] */
    (xdc_Char)0x20,  /* [6032] */
    (xdc_Char)0x30,  /* [6033] */
    (xdc_Char)0x78,  /* [6034] */
    (xdc_Char)0x25,  /* [6035] */
    (xdc_Char)0x78,  /* [6036] */
    (xdc_Char)0x2c,  /* [6037] */
    (xdc_Char)0x20,  /* [6038] */
    (xdc_Char)0x66,  /* [6039] */
    (xdc_Char)0x75,  /* [6040] */
    (xdc_Char)0x6e,  /* [6041] */
    (xdc_Char)0x63,  /* [6042] */
    (xdc_Char)0x3a,  /* [6043] */
    (xdc_Char)0x20,  /* [6044] */
    (xdc_Char)0x30,  /* [6045] */
    (xdc_Char)0x78,  /* [6046] */
    (xdc_Char)0x25,  /* [6047] */
    (xdc_Char)0x78,  /* [6048] */
    (xdc_Char)0x2c,  /* [6049] */
    (xdc_Char)0x20,  /* [6050] */
    (xdc_Char)0x70,  /* [6051] */
    (xdc_Char)0x72,  /* [6052] */
    (xdc_Char)0x65,  /* [6053] */
    (xdc_Char)0x54,  /* [6054] */
    (xdc_Char)0x68,  /* [6055] */
    (xdc_Char)0x72,  /* [6056] */
    (xdc_Char)0x65,  /* [6057] */
    (xdc_Char)0x61,  /* [6058] */
    (xdc_Char)0x64,  /* [6059] */
    (xdc_Char)0x3a,  /* [6060] */
    (xdc_Char)0x20,  /* [6061] */
    (xdc_Char)0x25,  /* [6062] */
    (xdc_Char)0x64,  /* [6063] */
    (xdc_Char)0x0,  /* [6064] */
    (xdc_Char)0x4c,  /* [6065] */
    (xdc_Char)0x44,  /* [6066] */
    (xdc_Char)0x5f,  /* [6067] */
    (xdc_Char)0x65,  /* [6068] */
    (xdc_Char)0x6e,  /* [6069] */
    (xdc_Char)0x64,  /* [6070] */
    (xdc_Char)0x3a,  /* [6071] */
    (xdc_Char)0x20,  /* [6072] */
    (xdc_Char)0x73,  /* [6073] */
    (xdc_Char)0x77,  /* [6074] */
    (xdc_Char)0x69,  /* [6075] */
    (xdc_Char)0x3a,  /* [6076] */
    (xdc_Char)0x20,  /* [6077] */
    (xdc_Char)0x30,  /* [6078] */
    (xdc_Char)0x78,  /* [6079] */
    (xdc_Char)0x25,  /* [6080] */
    (xdc_Char)0x78,  /* [6081] */
    (xdc_Char)0x0,  /* [6082] */
    (xdc_Char)0x4c,  /* [6083] */
    (xdc_Char)0x4d,  /* [6084] */
    (xdc_Char)0x5f,  /* [6085] */
    (xdc_Char)0x70,  /* [6086] */
    (xdc_Char)0x6f,  /* [6087] */
    (xdc_Char)0x73,  /* [6088] */
    (xdc_Char)0x74,  /* [6089] */
    (xdc_Char)0x3a,  /* [6090] */
    (xdc_Char)0x20,  /* [6091] */
    (xdc_Char)0x73,  /* [6092] */
    (xdc_Char)0x77,  /* [6093] */
    (xdc_Char)0x69,  /* [6094] */
    (xdc_Char)0x3a,  /* [6095] */
    (xdc_Char)0x20,  /* [6096] */
    (xdc_Char)0x30,  /* [6097] */
    (xdc_Char)0x78,  /* [6098] */
    (xdc_Char)0x25,  /* [6099] */
    (xdc_Char)0x78,  /* [6100] */
    (xdc_Char)0x2c,  /* [6101] */
    (xdc_Char)0x20,  /* [6102] */
    (xdc_Char)0x66,  /* [6103] */
    (xdc_Char)0x75,  /* [6104] */
    (xdc_Char)0x6e,  /* [6105] */
    (xdc_Char)0x63,  /* [6106] */
    (xdc_Char)0x3a,  /* [6107] */
    (xdc_Char)0x20,  /* [6108] */
    (xdc_Char)0x30,  /* [6109] */
    (xdc_Char)0x78,  /* [6110] */
    (xdc_Char)0x25,  /* [6111] */
    (xdc_Char)0x78,  /* [6112] */
    (xdc_Char)0x2c,  /* [6113] */
    (xdc_Char)0x20,  /* [6114] */
    (xdc_Char)0x70,  /* [6115] */
    (xdc_Char)0x72,  /* [6116] */
    (xdc_Char)0x69,  /* [6117] */
    (xdc_Char)0x3a,  /* [6118] */
    (xdc_Char)0x20,  /* [6119] */
    (xdc_Char)0x25,  /* [6120] */
    (xdc_Char)0x64,  /* [6121] */
    (xdc_Char)0x0,  /* [6122] */
    (xdc_Char)0x4c,  /* [6123] */
    (xdc_Char)0x4d,  /* [6124] */
    (xdc_Char)0x5f,  /* [6125] */
    (xdc_Char)0x73,  /* [6126] */
    (xdc_Char)0x77,  /* [6127] */
    (xdc_Char)0x69,  /* [6128] */
    (xdc_Char)0x74,  /* [6129] */
    (xdc_Char)0x63,  /* [6130] */
    (xdc_Char)0x68,  /* [6131] */
    (xdc_Char)0x3a,  /* [6132] */
    (xdc_Char)0x20,  /* [6133] */
    (xdc_Char)0x6f,  /* [6134] */
    (xdc_Char)0x6c,  /* [6135] */
    (xdc_Char)0x64,  /* [6136] */
    (xdc_Char)0x74,  /* [6137] */
    (xdc_Char)0x73,  /* [6138] */
    (xdc_Char)0x6b,  /* [6139] */
    (xdc_Char)0x3a,  /* [6140] */
    (xdc_Char)0x20,  /* [6141] */
    (xdc_Char)0x30,  /* [6142] */
    (xdc_Char)0x78,  /* [6143] */
    (xdc_Char)0x25,  /* [6144] */
    (xdc_Char)0x78,  /* [6145] */
    (xdc_Char)0x2c,  /* [6146] */
    (xdc_Char)0x20,  /* [6147] */
    (xdc_Char)0x6f,  /* [6148] */
    (xdc_Char)0x6c,  /* [6149] */
    (xdc_Char)0x64,  /* [6150] */
    (xdc_Char)0x66,  /* [6151] */
    (xdc_Char)0x75,  /* [6152] */
    (xdc_Char)0x6e,  /* [6153] */
    (xdc_Char)0x63,  /* [6154] */
    (xdc_Char)0x3a,  /* [6155] */
    (xdc_Char)0x20,  /* [6156] */
    (xdc_Char)0x30,  /* [6157] */
    (xdc_Char)0x78,  /* [6158] */
    (xdc_Char)0x25,  /* [6159] */
    (xdc_Char)0x78,  /* [6160] */
    (xdc_Char)0x2c,  /* [6161] */
    (xdc_Char)0x20,  /* [6162] */
    (xdc_Char)0x6e,  /* [6163] */
    (xdc_Char)0x65,  /* [6164] */
    (xdc_Char)0x77,  /* [6165] */
    (xdc_Char)0x74,  /* [6166] */
    (xdc_Char)0x73,  /* [6167] */
    (xdc_Char)0x6b,  /* [6168] */
    (xdc_Char)0x3a,  /* [6169] */
    (xdc_Char)0x20,  /* [6170] */
    (xdc_Char)0x30,  /* [6171] */
    (xdc_Char)0x78,  /* [6172] */
    (xdc_Char)0x25,  /* [6173] */
    (xdc_Char)0x78,  /* [6174] */
    (xdc_Char)0x2c,  /* [6175] */
    (xdc_Char)0x20,  /* [6176] */
    (xdc_Char)0x6e,  /* [6177] */
    (xdc_Char)0x65,  /* [6178] */
    (xdc_Char)0x77,  /* [6179] */
    (xdc_Char)0x66,  /* [6180] */
    (xdc_Char)0x75,  /* [6181] */
    (xdc_Char)0x6e,  /* [6182] */
    (xdc_Char)0x63,  /* [6183] */
    (xdc_Char)0x3a,  /* [6184] */
    (xdc_Char)0x20,  /* [6185] */
    (xdc_Char)0x30,  /* [6186] */
    (xdc_Char)0x78,  /* [6187] */
    (xdc_Char)0x25,  /* [6188] */
    (xdc_Char)0x78,  /* [6189] */
    (xdc_Char)0x0,  /* [6190] */
    (xdc_Char)0x4c,  /* [6191] */
    (xdc_Char)0x4d,  /* [6192] */
    (xdc_Char)0x5f,  /* [6193] */
    (xdc_Char)0x73,  /* [6194] */
    (xdc_Char)0x6c,  /* [6195] */
    (xdc_Char)0x65,  /* [6196] */
    (xdc_Char)0x65,  /* [6197] */
    (xdc_Char)0x70,  /* [6198] */
    (xdc_Char)0x3a,  /* [6199] */
    (xdc_Char)0x20,  /* [6200] */
    (xdc_Char)0x74,  /* [6201] */
    (xdc_Char)0x73,  /* [6202] */
    (xdc_Char)0x6b,  /* [6203] */
    (xdc_Char)0x3a,  /* [6204] */
    (xdc_Char)0x20,  /* [6205] */
    (xdc_Char)0x30,  /* [6206] */
    (xdc_Char)0x78,  /* [6207] */
    (xdc_Char)0x25,  /* [6208] */
    (xdc_Char)0x78,  /* [6209] */
    (xdc_Char)0x2c,  /* [6210] */
    (xdc_Char)0x20,  /* [6211] */
    (xdc_Char)0x66,  /* [6212] */
    (xdc_Char)0x75,  /* [6213] */
    (xdc_Char)0x6e,  /* [6214] */
    (xdc_Char)0x63,  /* [6215] */
    (xdc_Char)0x3a,  /* [6216] */
    (xdc_Char)0x20,  /* [6217] */
    (xdc_Char)0x30,  /* [6218] */
    (xdc_Char)0x78,  /* [6219] */
    (xdc_Char)0x25,  /* [6220] */
    (xdc_Char)0x78,  /* [6221] */
    (xdc_Char)0x2c,  /* [6222] */
    (xdc_Char)0x20,  /* [6223] */
    (xdc_Char)0x74,  /* [6224] */
    (xdc_Char)0x69,  /* [6225] */
    (xdc_Char)0x6d,  /* [6226] */
    (xdc_Char)0x65,  /* [6227] */
    (xdc_Char)0x6f,  /* [6228] */
    (xdc_Char)0x75,  /* [6229] */
    (xdc_Char)0x74,  /* [6230] */
    (xdc_Char)0x3a,  /* [6231] */
    (xdc_Char)0x20,  /* [6232] */
    (xdc_Char)0x25,  /* [6233] */
    (xdc_Char)0x64,  /* [6234] */
    (xdc_Char)0x0,  /* [6235] */
    (xdc_Char)0x4c,  /* [6236] */
    (xdc_Char)0x44,  /* [6237] */
    (xdc_Char)0x5f,  /* [6238] */
    (xdc_Char)0x72,  /* [6239] */
    (xdc_Char)0x65,  /* [6240] */
    (xdc_Char)0x61,  /* [6241] */
    (xdc_Char)0x64,  /* [6242] */
    (xdc_Char)0x79,  /* [6243] */
    (xdc_Char)0x3a,  /* [6244] */
    (xdc_Char)0x20,  /* [6245] */
    (xdc_Char)0x74,  /* [6246] */
    (xdc_Char)0x73,  /* [6247] */
    (xdc_Char)0x6b,  /* [6248] */
    (xdc_Char)0x3a,  /* [6249] */
    (xdc_Char)0x20,  /* [6250] */
    (xdc_Char)0x30,  /* [6251] */
    (xdc_Char)0x78,  /* [6252] */
    (xdc_Char)0x25,  /* [6253] */
    (xdc_Char)0x78,  /* [6254] */
    (xdc_Char)0x2c,  /* [6255] */
    (xdc_Char)0x20,  /* [6256] */
    (xdc_Char)0x66,  /* [6257] */
    (xdc_Char)0x75,  /* [6258] */
    (xdc_Char)0x6e,  /* [6259] */
    (xdc_Char)0x63,  /* [6260] */
    (xdc_Char)0x3a,  /* [6261] */
    (xdc_Char)0x20,  /* [6262] */
    (xdc_Char)0x30,  /* [6263] */
    (xdc_Char)0x78,  /* [6264] */
    (xdc_Char)0x25,  /* [6265] */
    (xdc_Char)0x78,  /* [6266] */
    (xdc_Char)0x2c,  /* [6267] */
    (xdc_Char)0x20,  /* [6268] */
    (xdc_Char)0x70,  /* [6269] */
    (xdc_Char)0x72,  /* [6270] */
    (xdc_Char)0x69,  /* [6271] */
    (xdc_Char)0x3a,  /* [6272] */
    (xdc_Char)0x20,  /* [6273] */
    (xdc_Char)0x25,  /* [6274] */
    (xdc_Char)0x64,  /* [6275] */
    (xdc_Char)0x0,  /* [6276] */
    (xdc_Char)0x4c,  /* [6277] */
    (xdc_Char)0x44,  /* [6278] */
    (xdc_Char)0x5f,  /* [6279] */
    (xdc_Char)0x62,  /* [6280] */
    (xdc_Char)0x6c,  /* [6281] */
    (xdc_Char)0x6f,  /* [6282] */
    (xdc_Char)0x63,  /* [6283] */
    (xdc_Char)0x6b,  /* [6284] */
    (xdc_Char)0x3a,  /* [6285] */
    (xdc_Char)0x20,  /* [6286] */
    (xdc_Char)0x74,  /* [6287] */
    (xdc_Char)0x73,  /* [6288] */
    (xdc_Char)0x6b,  /* [6289] */
    (xdc_Char)0x3a,  /* [6290] */
    (xdc_Char)0x20,  /* [6291] */
    (xdc_Char)0x30,  /* [6292] */
    (xdc_Char)0x78,  /* [6293] */
    (xdc_Char)0x25,  /* [6294] */
    (xdc_Char)0x78,  /* [6295] */
    (xdc_Char)0x2c,  /* [6296] */
    (xdc_Char)0x20,  /* [6297] */
    (xdc_Char)0x66,  /* [6298] */
    (xdc_Char)0x75,  /* [6299] */
    (xdc_Char)0x6e,  /* [6300] */
    (xdc_Char)0x63,  /* [6301] */
    (xdc_Char)0x3a,  /* [6302] */
    (xdc_Char)0x20,  /* [6303] */
    (xdc_Char)0x30,  /* [6304] */
    (xdc_Char)0x78,  /* [6305] */
    (xdc_Char)0x25,  /* [6306] */
    (xdc_Char)0x78,  /* [6307] */
    (xdc_Char)0x0,  /* [6308] */
    (xdc_Char)0x4c,  /* [6309] */
    (xdc_Char)0x4d,  /* [6310] */
    (xdc_Char)0x5f,  /* [6311] */
    (xdc_Char)0x79,  /* [6312] */
    (xdc_Char)0x69,  /* [6313] */
    (xdc_Char)0x65,  /* [6314] */
    (xdc_Char)0x6c,  /* [6315] */
    (xdc_Char)0x64,  /* [6316] */
    (xdc_Char)0x3a,  /* [6317] */
    (xdc_Char)0x20,  /* [6318] */
    (xdc_Char)0x74,  /* [6319] */
    (xdc_Char)0x73,  /* [6320] */
    (xdc_Char)0x6b,  /* [6321] */
    (xdc_Char)0x3a,  /* [6322] */
    (xdc_Char)0x20,  /* [6323] */
    (xdc_Char)0x30,  /* [6324] */
    (xdc_Char)0x78,  /* [6325] */
    (xdc_Char)0x25,  /* [6326] */
    (xdc_Char)0x78,  /* [6327] */
    (xdc_Char)0x2c,  /* [6328] */
    (xdc_Char)0x20,  /* [6329] */
    (xdc_Char)0x66,  /* [6330] */
    (xdc_Char)0x75,  /* [6331] */
    (xdc_Char)0x6e,  /* [6332] */
    (xdc_Char)0x63,  /* [6333] */
    (xdc_Char)0x3a,  /* [6334] */
    (xdc_Char)0x20,  /* [6335] */
    (xdc_Char)0x30,  /* [6336] */
    (xdc_Char)0x78,  /* [6337] */
    (xdc_Char)0x25,  /* [6338] */
    (xdc_Char)0x78,  /* [6339] */
    (xdc_Char)0x2c,  /* [6340] */
    (xdc_Char)0x20,  /* [6341] */
    (xdc_Char)0x63,  /* [6342] */
    (xdc_Char)0x75,  /* [6343] */
    (xdc_Char)0x72,  /* [6344] */
    (xdc_Char)0x72,  /* [6345] */
    (xdc_Char)0x54,  /* [6346] */
    (xdc_Char)0x68,  /* [6347] */
    (xdc_Char)0x72,  /* [6348] */
    (xdc_Char)0x65,  /* [6349] */
    (xdc_Char)0x61,  /* [6350] */
    (xdc_Char)0x64,  /* [6351] */
    (xdc_Char)0x3a,  /* [6352] */
    (xdc_Char)0x20,  /* [6353] */
    (xdc_Char)0x25,  /* [6354] */
    (xdc_Char)0x64,  /* [6355] */
    (xdc_Char)0x0,  /* [6356] */
    (xdc_Char)0x4c,  /* [6357] */
    (xdc_Char)0x4d,  /* [6358] */
    (xdc_Char)0x5f,  /* [6359] */
    (xdc_Char)0x73,  /* [6360] */
    (xdc_Char)0x65,  /* [6361] */
    (xdc_Char)0x74,  /* [6362] */
    (xdc_Char)0x50,  /* [6363] */
    (xdc_Char)0x72,  /* [6364] */
    (xdc_Char)0x69,  /* [6365] */
    (xdc_Char)0x3a,  /* [6366] */
    (xdc_Char)0x20,  /* [6367] */
    (xdc_Char)0x74,  /* [6368] */
    (xdc_Char)0x73,  /* [6369] */
    (xdc_Char)0x6b,  /* [6370] */
    (xdc_Char)0x3a,  /* [6371] */
    (xdc_Char)0x20,  /* [6372] */
    (xdc_Char)0x30,  /* [6373] */
    (xdc_Char)0x78,  /* [6374] */
    (xdc_Char)0x25,  /* [6375] */
    (xdc_Char)0x78,  /* [6376] */
    (xdc_Char)0x2c,  /* [6377] */
    (xdc_Char)0x20,  /* [6378] */
    (xdc_Char)0x66,  /* [6379] */
    (xdc_Char)0x75,  /* [6380] */
    (xdc_Char)0x6e,  /* [6381] */
    (xdc_Char)0x63,  /* [6382] */
    (xdc_Char)0x3a,  /* [6383] */
    (xdc_Char)0x20,  /* [6384] */
    (xdc_Char)0x30,  /* [6385] */
    (xdc_Char)0x78,  /* [6386] */
    (xdc_Char)0x25,  /* [6387] */
    (xdc_Char)0x78,  /* [6388] */
    (xdc_Char)0x2c,  /* [6389] */
    (xdc_Char)0x20,  /* [6390] */
    (xdc_Char)0x6f,  /* [6391] */
    (xdc_Char)0x6c,  /* [6392] */
    (xdc_Char)0x64,  /* [6393] */
    (xdc_Char)0x50,  /* [6394] */
    (xdc_Char)0x72,  /* [6395] */
    (xdc_Char)0x69,  /* [6396] */
    (xdc_Char)0x3a,  /* [6397] */
    (xdc_Char)0x20,  /* [6398] */
    (xdc_Char)0x25,  /* [6399] */
    (xdc_Char)0x64,  /* [6400] */
    (xdc_Char)0x2c,  /* [6401] */
    (xdc_Char)0x20,  /* [6402] */
    (xdc_Char)0x6e,  /* [6403] */
    (xdc_Char)0x65,  /* [6404] */
    (xdc_Char)0x77,  /* [6405] */
    (xdc_Char)0x50,  /* [6406] */
    (xdc_Char)0x72,  /* [6407] */
    (xdc_Char)0x69,  /* [6408] */
    (xdc_Char)0x20,  /* [6409] */
    (xdc_Char)0x25,  /* [6410] */
    (xdc_Char)0x64,  /* [6411] */
    (xdc_Char)0x0,  /* [6412] */
    (xdc_Char)0x4c,  /* [6413] */
    (xdc_Char)0x44,  /* [6414] */
    (xdc_Char)0x5f,  /* [6415] */
    (xdc_Char)0x65,  /* [6416] */
    (xdc_Char)0x78,  /* [6417] */
    (xdc_Char)0x69,  /* [6418] */
    (xdc_Char)0x74,  /* [6419] */
    (xdc_Char)0x3a,  /* [6420] */
    (xdc_Char)0x20,  /* [6421] */
    (xdc_Char)0x74,  /* [6422] */
    (xdc_Char)0x73,  /* [6423] */
    (xdc_Char)0x6b,  /* [6424] */
    (xdc_Char)0x3a,  /* [6425] */
    (xdc_Char)0x20,  /* [6426] */
    (xdc_Char)0x30,  /* [6427] */
    (xdc_Char)0x78,  /* [6428] */
    (xdc_Char)0x25,  /* [6429] */
    (xdc_Char)0x78,  /* [6430] */
    (xdc_Char)0x2c,  /* [6431] */
    (xdc_Char)0x20,  /* [6432] */
    (xdc_Char)0x66,  /* [6433] */
    (xdc_Char)0x75,  /* [6434] */
    (xdc_Char)0x6e,  /* [6435] */
    (xdc_Char)0x63,  /* [6436] */
    (xdc_Char)0x3a,  /* [6437] */
    (xdc_Char)0x20,  /* [6438] */
    (xdc_Char)0x30,  /* [6439] */
    (xdc_Char)0x78,  /* [6440] */
    (xdc_Char)0x25,  /* [6441] */
    (xdc_Char)0x78,  /* [6442] */
    (xdc_Char)0x0,  /* [6443] */
    (xdc_Char)0x4c,  /* [6444] */
    (xdc_Char)0x4d,  /* [6445] */
    (xdc_Char)0x5f,  /* [6446] */
    (xdc_Char)0x73,  /* [6447] */
    (xdc_Char)0x65,  /* [6448] */
    (xdc_Char)0x74,  /* [6449] */
    (xdc_Char)0x41,  /* [6450] */
    (xdc_Char)0x66,  /* [6451] */
    (xdc_Char)0x66,  /* [6452] */
    (xdc_Char)0x69,  /* [6453] */
    (xdc_Char)0x6e,  /* [6454] */
    (xdc_Char)0x69,  /* [6455] */
    (xdc_Char)0x74,  /* [6456] */
    (xdc_Char)0x79,  /* [6457] */
    (xdc_Char)0x3a,  /* [6458] */
    (xdc_Char)0x20,  /* [6459] */
    (xdc_Char)0x74,  /* [6460] */
    (xdc_Char)0x73,  /* [6461] */
    (xdc_Char)0x6b,  /* [6462] */
    (xdc_Char)0x3a,  /* [6463] */
    (xdc_Char)0x20,  /* [6464] */
    (xdc_Char)0x30,  /* [6465] */
    (xdc_Char)0x78,  /* [6466] */
    (xdc_Char)0x25,  /* [6467] */
    (xdc_Char)0x78,  /* [6468] */
    (xdc_Char)0x2c,  /* [6469] */
    (xdc_Char)0x20,  /* [6470] */
    (xdc_Char)0x66,  /* [6471] */
    (xdc_Char)0x75,  /* [6472] */
    (xdc_Char)0x6e,  /* [6473] */
    (xdc_Char)0x63,  /* [6474] */
    (xdc_Char)0x3a,  /* [6475] */
    (xdc_Char)0x20,  /* [6476] */
    (xdc_Char)0x30,  /* [6477] */
    (xdc_Char)0x78,  /* [6478] */
    (xdc_Char)0x25,  /* [6479] */
    (xdc_Char)0x78,  /* [6480] */
    (xdc_Char)0x2c,  /* [6481] */
    (xdc_Char)0x20,  /* [6482] */
    (xdc_Char)0x6f,  /* [6483] */
    (xdc_Char)0x6c,  /* [6484] */
    (xdc_Char)0x64,  /* [6485] */
    (xdc_Char)0x43,  /* [6486] */
    (xdc_Char)0x6f,  /* [6487] */
    (xdc_Char)0x72,  /* [6488] */
    (xdc_Char)0x65,  /* [6489] */
    (xdc_Char)0x3a,  /* [6490] */
    (xdc_Char)0x20,  /* [6491] */
    (xdc_Char)0x25,  /* [6492] */
    (xdc_Char)0x64,  /* [6493] */
    (xdc_Char)0x2c,  /* [6494] */
    (xdc_Char)0x20,  /* [6495] */
    (xdc_Char)0x6f,  /* [6496] */
    (xdc_Char)0x6c,  /* [6497] */
    (xdc_Char)0x64,  /* [6498] */
    (xdc_Char)0x41,  /* [6499] */
    (xdc_Char)0x66,  /* [6500] */
    (xdc_Char)0x66,  /* [6501] */
    (xdc_Char)0x69,  /* [6502] */
    (xdc_Char)0x6e,  /* [6503] */
    (xdc_Char)0x69,  /* [6504] */
    (xdc_Char)0x74,  /* [6505] */
    (xdc_Char)0x79,  /* [6506] */
    (xdc_Char)0x20,  /* [6507] */
    (xdc_Char)0x25,  /* [6508] */
    (xdc_Char)0x64,  /* [6509] */
    (xdc_Char)0x2c,  /* [6510] */
    (xdc_Char)0x20,  /* [6511] */
    (xdc_Char)0x6e,  /* [6512] */
    (xdc_Char)0x65,  /* [6513] */
    (xdc_Char)0x77,  /* [6514] */
    (xdc_Char)0x41,  /* [6515] */
    (xdc_Char)0x66,  /* [6516] */
    (xdc_Char)0x66,  /* [6517] */
    (xdc_Char)0x69,  /* [6518] */
    (xdc_Char)0x6e,  /* [6519] */
    (xdc_Char)0x69,  /* [6520] */
    (xdc_Char)0x74,  /* [6521] */
    (xdc_Char)0x79,  /* [6522] */
    (xdc_Char)0x20,  /* [6523] */
    (xdc_Char)0x25,  /* [6524] */
    (xdc_Char)0x64,  /* [6525] */
    (xdc_Char)0x0,  /* [6526] */
    (xdc_Char)0x4c,  /* [6527] */
    (xdc_Char)0x44,  /* [6528] */
    (xdc_Char)0x5f,  /* [6529] */
    (xdc_Char)0x73,  /* [6530] */
    (xdc_Char)0x63,  /* [6531] */
    (xdc_Char)0x68,  /* [6532] */
    (xdc_Char)0x65,  /* [6533] */
    (xdc_Char)0x64,  /* [6534] */
    (xdc_Char)0x75,  /* [6535] */
    (xdc_Char)0x6c,  /* [6536] */
    (xdc_Char)0x65,  /* [6537] */
    (xdc_Char)0x3a,  /* [6538] */
    (xdc_Char)0x20,  /* [6539] */
    (xdc_Char)0x63,  /* [6540] */
    (xdc_Char)0x6f,  /* [6541] */
    (xdc_Char)0x72,  /* [6542] */
    (xdc_Char)0x65,  /* [6543] */
    (xdc_Char)0x49,  /* [6544] */
    (xdc_Char)0x64,  /* [6545] */
    (xdc_Char)0x3a,  /* [6546] */
    (xdc_Char)0x20,  /* [6547] */
    (xdc_Char)0x25,  /* [6548] */
    (xdc_Char)0x64,  /* [6549] */
    (xdc_Char)0x2c,  /* [6550] */
    (xdc_Char)0x20,  /* [6551] */
    (xdc_Char)0x77,  /* [6552] */
    (xdc_Char)0x6f,  /* [6553] */
    (xdc_Char)0x72,  /* [6554] */
    (xdc_Char)0x6b,  /* [6555] */
    (xdc_Char)0x46,  /* [6556] */
    (xdc_Char)0x6c,  /* [6557] */
    (xdc_Char)0x61,  /* [6558] */
    (xdc_Char)0x67,  /* [6559] */
    (xdc_Char)0x3a,  /* [6560] */
    (xdc_Char)0x20,  /* [6561] */
    (xdc_Char)0x25,  /* [6562] */
    (xdc_Char)0x64,  /* [6563] */
    (xdc_Char)0x2c,  /* [6564] */
    (xdc_Char)0x20,  /* [6565] */
    (xdc_Char)0x63,  /* [6566] */
    (xdc_Char)0x75,  /* [6567] */
    (xdc_Char)0x72,  /* [6568] */
    (xdc_Char)0x53,  /* [6569] */
    (xdc_Char)0x65,  /* [6570] */
    (xdc_Char)0x74,  /* [6571] */
    (xdc_Char)0x4c,  /* [6572] */
    (xdc_Char)0x6f,  /* [6573] */
    (xdc_Char)0x63,  /* [6574] */
    (xdc_Char)0x61,  /* [6575] */
    (xdc_Char)0x6c,  /* [6576] */
    (xdc_Char)0x3a,  /* [6577] */
    (xdc_Char)0x20,  /* [6578] */
    (xdc_Char)0x25,  /* [6579] */
    (xdc_Char)0x64,  /* [6580] */
    (xdc_Char)0x2c,  /* [6581] */
    (xdc_Char)0x20,  /* [6582] */
    (xdc_Char)0x63,  /* [6583] */
    (xdc_Char)0x75,  /* [6584] */
    (xdc_Char)0x72,  /* [6585] */
    (xdc_Char)0x53,  /* [6586] */
    (xdc_Char)0x65,  /* [6587] */
    (xdc_Char)0x74,  /* [6588] */
    (xdc_Char)0x58,  /* [6589] */
    (xdc_Char)0x3a,  /* [6590] */
    (xdc_Char)0x20,  /* [6591] */
    (xdc_Char)0x25,  /* [6592] */
    (xdc_Char)0x64,  /* [6593] */
    (xdc_Char)0x2c,  /* [6594] */
    (xdc_Char)0x20,  /* [6595] */
    (xdc_Char)0x63,  /* [6596] */
    (xdc_Char)0x75,  /* [6597] */
    (xdc_Char)0x72,  /* [6598] */
    (xdc_Char)0x4d,  /* [6599] */
    (xdc_Char)0x61,  /* [6600] */
    (xdc_Char)0x73,  /* [6601] */
    (xdc_Char)0x6b,  /* [6602] */
    (xdc_Char)0x4c,  /* [6603] */
    (xdc_Char)0x6f,  /* [6604] */
    (xdc_Char)0x63,  /* [6605] */
    (xdc_Char)0x61,  /* [6606] */
    (xdc_Char)0x6c,  /* [6607] */
    (xdc_Char)0x3a,  /* [6608] */
    (xdc_Char)0x20,  /* [6609] */
    (xdc_Char)0x25,  /* [6610] */
    (xdc_Char)0x64,  /* [6611] */
    (xdc_Char)0x0,  /* [6612] */
    (xdc_Char)0x4c,  /* [6613] */
    (xdc_Char)0x44,  /* [6614] */
    (xdc_Char)0x5f,  /* [6615] */
    (xdc_Char)0x6e,  /* [6616] */
    (xdc_Char)0x6f,  /* [6617] */
    (xdc_Char)0x57,  /* [6618] */
    (xdc_Char)0x6f,  /* [6619] */
    (xdc_Char)0x72,  /* [6620] */
    (xdc_Char)0x6b,  /* [6621] */
    (xdc_Char)0x3a,  /* [6622] */
    (xdc_Char)0x20,  /* [6623] */
    (xdc_Char)0x63,  /* [6624] */
    (xdc_Char)0x6f,  /* [6625] */
    (xdc_Char)0x72,  /* [6626] */
    (xdc_Char)0x65,  /* [6627] */
    (xdc_Char)0x49,  /* [6628] */
    (xdc_Char)0x64,  /* [6629] */
    (xdc_Char)0x3a,  /* [6630] */
    (xdc_Char)0x20,  /* [6631] */
    (xdc_Char)0x25,  /* [6632] */
    (xdc_Char)0x64,  /* [6633] */
    (xdc_Char)0x2c,  /* [6634] */
    (xdc_Char)0x20,  /* [6635] */
    (xdc_Char)0x63,  /* [6636] */
    (xdc_Char)0x75,  /* [6637] */
    (xdc_Char)0x72,  /* [6638] */
    (xdc_Char)0x53,  /* [6639] */
    (xdc_Char)0x65,  /* [6640] */
    (xdc_Char)0x74,  /* [6641] */
    (xdc_Char)0x4c,  /* [6642] */
    (xdc_Char)0x6f,  /* [6643] */
    (xdc_Char)0x63,  /* [6644] */
    (xdc_Char)0x61,  /* [6645] */
    (xdc_Char)0x6c,  /* [6646] */
    (xdc_Char)0x3a,  /* [6647] */
    (xdc_Char)0x20,  /* [6648] */
    (xdc_Char)0x25,  /* [6649] */
    (xdc_Char)0x64,  /* [6650] */
    (xdc_Char)0x2c,  /* [6651] */
    (xdc_Char)0x20,  /* [6652] */
    (xdc_Char)0x63,  /* [6653] */
    (xdc_Char)0x75,  /* [6654] */
    (xdc_Char)0x72,  /* [6655] */
    (xdc_Char)0x53,  /* [6656] */
    (xdc_Char)0x65,  /* [6657] */
    (xdc_Char)0x74,  /* [6658] */
    (xdc_Char)0x58,  /* [6659] */
    (xdc_Char)0x3a,  /* [6660] */
    (xdc_Char)0x20,  /* [6661] */
    (xdc_Char)0x25,  /* [6662] */
    (xdc_Char)0x64,  /* [6663] */
    (xdc_Char)0x2c,  /* [6664] */
    (xdc_Char)0x20,  /* [6665] */
    (xdc_Char)0x63,  /* [6666] */
    (xdc_Char)0x75,  /* [6667] */
    (xdc_Char)0x72,  /* [6668] */
    (xdc_Char)0x4d,  /* [6669] */
    (xdc_Char)0x61,  /* [6670] */
    (xdc_Char)0x73,  /* [6671] */
    (xdc_Char)0x6b,  /* [6672] */
    (xdc_Char)0x4c,  /* [6673] */
    (xdc_Char)0x6f,  /* [6674] */
    (xdc_Char)0x63,  /* [6675] */
    (xdc_Char)0x61,  /* [6676] */
    (xdc_Char)0x6c,  /* [6677] */
    (xdc_Char)0x3a,  /* [6678] */
    (xdc_Char)0x20,  /* [6679] */
    (xdc_Char)0x25,  /* [6680] */
    (xdc_Char)0x64,  /* [6681] */
    (xdc_Char)0x0,  /* [6682] */
    (xdc_Char)0x4c,  /* [6683] */
    (xdc_Char)0x4d,  /* [6684] */
    (xdc_Char)0x5f,  /* [6685] */
    (xdc_Char)0x62,  /* [6686] */
    (xdc_Char)0x65,  /* [6687] */
    (xdc_Char)0x67,  /* [6688] */
    (xdc_Char)0x69,  /* [6689] */
    (xdc_Char)0x6e,  /* [6690] */
    (xdc_Char)0x3a,  /* [6691] */
    (xdc_Char)0x20,  /* [6692] */
    (xdc_Char)0x68,  /* [6693] */
    (xdc_Char)0x77,  /* [6694] */
    (xdc_Char)0x69,  /* [6695] */
    (xdc_Char)0x3a,  /* [6696] */
    (xdc_Char)0x20,  /* [6697] */
    (xdc_Char)0x30,  /* [6698] */
    (xdc_Char)0x78,  /* [6699] */
    (xdc_Char)0x25,  /* [6700] */
    (xdc_Char)0x78,  /* [6701] */
    (xdc_Char)0x2c,  /* [6702] */
    (xdc_Char)0x20,  /* [6703] */
    (xdc_Char)0x66,  /* [6704] */
    (xdc_Char)0x75,  /* [6705] */
    (xdc_Char)0x6e,  /* [6706] */
    (xdc_Char)0x63,  /* [6707] */
    (xdc_Char)0x3a,  /* [6708] */
    (xdc_Char)0x20,  /* [6709] */
    (xdc_Char)0x30,  /* [6710] */
    (xdc_Char)0x78,  /* [6711] */
    (xdc_Char)0x25,  /* [6712] */
    (xdc_Char)0x78,  /* [6713] */
    (xdc_Char)0x2c,  /* [6714] */
    (xdc_Char)0x20,  /* [6715] */
    (xdc_Char)0x70,  /* [6716] */
    (xdc_Char)0x72,  /* [6717] */
    (xdc_Char)0x65,  /* [6718] */
    (xdc_Char)0x54,  /* [6719] */
    (xdc_Char)0x68,  /* [6720] */
    (xdc_Char)0x72,  /* [6721] */
    (xdc_Char)0x65,  /* [6722] */
    (xdc_Char)0x61,  /* [6723] */
    (xdc_Char)0x64,  /* [6724] */
    (xdc_Char)0x3a,  /* [6725] */
    (xdc_Char)0x20,  /* [6726] */
    (xdc_Char)0x25,  /* [6727] */
    (xdc_Char)0x64,  /* [6728] */
    (xdc_Char)0x2c,  /* [6729] */
    (xdc_Char)0x20,  /* [6730] */
    (xdc_Char)0x69,  /* [6731] */
    (xdc_Char)0x6e,  /* [6732] */
    (xdc_Char)0x74,  /* [6733] */
    (xdc_Char)0x4e,  /* [6734] */
    (xdc_Char)0x75,  /* [6735] */
    (xdc_Char)0x6d,  /* [6736] */
    (xdc_Char)0x3a,  /* [6737] */
    (xdc_Char)0x20,  /* [6738] */
    (xdc_Char)0x25,  /* [6739] */
    (xdc_Char)0x64,  /* [6740] */
    (xdc_Char)0x2c,  /* [6741] */
    (xdc_Char)0x20,  /* [6742] */
    (xdc_Char)0x69,  /* [6743] */
    (xdc_Char)0x72,  /* [6744] */
    (xdc_Char)0x70,  /* [6745] */
    (xdc_Char)0x3a,  /* [6746] */
    (xdc_Char)0x20,  /* [6747] */
    (xdc_Char)0x30,  /* [6748] */
    (xdc_Char)0x78,  /* [6749] */
    (xdc_Char)0x25,  /* [6750] */
    (xdc_Char)0x78,  /* [6751] */
    (xdc_Char)0x0,  /* [6752] */
    (xdc_Char)0x4c,  /* [6753] */
    (xdc_Char)0x44,  /* [6754] */
    (xdc_Char)0x5f,  /* [6755] */
    (xdc_Char)0x65,  /* [6756] */
    (xdc_Char)0x6e,  /* [6757] */
    (xdc_Char)0x64,  /* [6758] */
    (xdc_Char)0x3a,  /* [6759] */
    (xdc_Char)0x20,  /* [6760] */
    (xdc_Char)0x68,  /* [6761] */
    (xdc_Char)0x77,  /* [6762] */
    (xdc_Char)0x69,  /* [6763] */
    (xdc_Char)0x3a,  /* [6764] */
    (xdc_Char)0x20,  /* [6765] */
    (xdc_Char)0x30,  /* [6766] */
    (xdc_Char)0x78,  /* [6767] */
    (xdc_Char)0x25,  /* [6768] */
    (xdc_Char)0x78,  /* [6769] */
    (xdc_Char)0x0,  /* [6770] */
    (xdc_Char)0x78,  /* [6771] */
    (xdc_Char)0x64,  /* [6772] */
    (xdc_Char)0x63,  /* [6773] */
    (xdc_Char)0x2e,  /* [6774] */
    (xdc_Char)0x0,  /* [6775] */
    (xdc_Char)0x72,  /* [6776] */
    (xdc_Char)0x75,  /* [6777] */
    (xdc_Char)0x6e,  /* [6778] */
    (xdc_Char)0x74,  /* [6779] */
    (xdc_Char)0x69,  /* [6780] */
    (xdc_Char)0x6d,  /* [6781] */
    (xdc_Char)0x65,  /* [6782] */
    (xdc_Char)0x2e,  /* [6783] */
    (xdc_Char)0x0,  /* [6784] */
    (xdc_Char)0x41,  /* [6785] */
    (xdc_Char)0x73,  /* [6786] */
    (xdc_Char)0x73,  /* [6787] */
    (xdc_Char)0x65,  /* [6788] */
    (xdc_Char)0x72,  /* [6789] */
    (xdc_Char)0x74,  /* [6790] */
    (xdc_Char)0x0,  /* [6791] */
    (xdc_Char)0x43,  /* [6792] */
    (xdc_Char)0x6f,  /* [6793] */
    (xdc_Char)0x72,  /* [6794] */
    (xdc_Char)0x65,  /* [6795] */
    (xdc_Char)0x0,  /* [6796] */
    (xdc_Char)0x44,  /* [6797] */
    (xdc_Char)0x65,  /* [6798] */
    (xdc_Char)0x66,  /* [6799] */
    (xdc_Char)0x61,  /* [6800] */
    (xdc_Char)0x75,  /* [6801] */
    (xdc_Char)0x6c,  /* [6802] */
    (xdc_Char)0x74,  /* [6803] */
    (xdc_Char)0x73,  /* [6804] */
    (xdc_Char)0x0,  /* [6805] */
    (xdc_Char)0x44,  /* [6806] */
    (xdc_Char)0x69,  /* [6807] */
    (xdc_Char)0x61,  /* [6808] */
    (xdc_Char)0x67,  /* [6809] */
    (xdc_Char)0x73,  /* [6810] */
    (xdc_Char)0x0,  /* [6811] */
    (xdc_Char)0x45,  /* [6812] */
    (xdc_Char)0x72,  /* [6813] */
    (xdc_Char)0x72,  /* [6814] */
    (xdc_Char)0x6f,  /* [6815] */
    (xdc_Char)0x72,  /* [6816] */
    (xdc_Char)0x0,  /* [6817] */
    (xdc_Char)0x47,  /* [6818] */
    (xdc_Char)0x61,  /* [6819] */
    (xdc_Char)0x74,  /* [6820] */
    (xdc_Char)0x65,  /* [6821] */
    (xdc_Char)0x0,  /* [6822] */
    (xdc_Char)0x4c,  /* [6823] */
    (xdc_Char)0x6f,  /* [6824] */
    (xdc_Char)0x67,  /* [6825] */
    (xdc_Char)0x0,  /* [6826] */
    (xdc_Char)0x4d,  /* [6827] */
    (xdc_Char)0x61,  /* [6828] */
    (xdc_Char)0x69,  /* [6829] */
    (xdc_Char)0x6e,  /* [6830] */
    (xdc_Char)0x0,  /* [6831] */
    (xdc_Char)0x4d,  /* [6832] */
    (xdc_Char)0x65,  /* [6833] */
    (xdc_Char)0x6d,  /* [6834] */
    (xdc_Char)0x6f,  /* [6835] */
    (xdc_Char)0x72,  /* [6836] */
    (xdc_Char)0x79,  /* [6837] */
    (xdc_Char)0x0,  /* [6838] */
    (xdc_Char)0x52,  /* [6839] */
    (xdc_Char)0x65,  /* [6840] */
    (xdc_Char)0x67,  /* [6841] */
    (xdc_Char)0x69,  /* [6842] */
    (xdc_Char)0x73,  /* [6843] */
    (xdc_Char)0x74,  /* [6844] */
    (xdc_Char)0x72,  /* [6845] */
    (xdc_Char)0x79,  /* [6846] */
    (xdc_Char)0x0,  /* [6847] */
    (xdc_Char)0x53,  /* [6848] */
    (xdc_Char)0x74,  /* [6849] */
    (xdc_Char)0x61,  /* [6850] */
    (xdc_Char)0x72,  /* [6851] */
    (xdc_Char)0x74,  /* [6852] */
    (xdc_Char)0x75,  /* [6853] */
    (xdc_Char)0x70,  /* [6854] */
    (xdc_Char)0x0,  /* [6855] */
    (xdc_Char)0x53,  /* [6856] */
    (xdc_Char)0x79,  /* [6857] */
    (xdc_Char)0x73,  /* [6858] */
    (xdc_Char)0x74,  /* [6859] */
    (xdc_Char)0x65,  /* [6860] */
    (xdc_Char)0x6d,  /* [6861] */
    (xdc_Char)0x0,  /* [6862] */
    (xdc_Char)0x53,  /* [6863] */
    (xdc_Char)0x79,  /* [6864] */
    (xdc_Char)0x73,  /* [6865] */
    (xdc_Char)0x4d,  /* [6866] */
    (xdc_Char)0x69,  /* [6867] */
    (xdc_Char)0x6e,  /* [6868] */
    (xdc_Char)0x0,  /* [6869] */
    (xdc_Char)0x54,  /* [6870] */
    (xdc_Char)0x65,  /* [6871] */
    (xdc_Char)0x78,  /* [6872] */
    (xdc_Char)0x74,  /* [6873] */
    (xdc_Char)0x0,  /* [6874] */
    (xdc_Char)0x74,  /* [6875] */
    (xdc_Char)0x69,  /* [6876] */
    (xdc_Char)0x2e,  /* [6877] */
    (xdc_Char)0x0,  /* [6878] */
    (xdc_Char)0x73,  /* [6879] */
    (xdc_Char)0x79,  /* [6880] */
    (xdc_Char)0x73,  /* [6881] */
    (xdc_Char)0x62,  /* [6882] */
    (xdc_Char)0x69,  /* [6883] */
    (xdc_Char)0x6f,  /* [6884] */
    (xdc_Char)0x73,  /* [6885] */
    (xdc_Char)0x2e,  /* [6886] */
    (xdc_Char)0x0,  /* [6887] */
    (xdc_Char)0x6b,  /* [6888] */
    (xdc_Char)0x6e,  /* [6889] */
    (xdc_Char)0x6c,  /* [6890] */
    (xdc_Char)0x2e,  /* [6891] */
    (xdc_Char)0x0,  /* [6892] */
    (xdc_Char)0x43,  /* [6893] */
    (xdc_Char)0x6c,  /* [6894] */
    (xdc_Char)0x6f,  /* [6895] */
    (xdc_Char)0x63,  /* [6896] */
    (xdc_Char)0x6b,  /* [6897] */
    (xdc_Char)0x0,  /* [6898] */
    (xdc_Char)0x49,  /* [6899] */
    (xdc_Char)0x64,  /* [6900] */
    (xdc_Char)0x6c,  /* [6901] */
    (xdc_Char)0x65,  /* [6902] */
    (xdc_Char)0x0,  /* [6903] */
    (xdc_Char)0x49,  /* [6904] */
    (xdc_Char)0x6e,  /* [6905] */
    (xdc_Char)0x74,  /* [6906] */
    (xdc_Char)0x72,  /* [6907] */
    (xdc_Char)0x69,  /* [6908] */
    (xdc_Char)0x6e,  /* [6909] */
    (xdc_Char)0x73,  /* [6910] */
    (xdc_Char)0x69,  /* [6911] */
    (xdc_Char)0x63,  /* [6912] */
    (xdc_Char)0x73,  /* [6913] */
    (xdc_Char)0x0,  /* [6914] */
    (xdc_Char)0x51,  /* [6915] */
    (xdc_Char)0x75,  /* [6916] */
    (xdc_Char)0x65,  /* [6917] */
    (xdc_Char)0x75,  /* [6918] */
    (xdc_Char)0x65,  /* [6919] */
    (xdc_Char)0x0,  /* [6920] */
    (xdc_Char)0x53,  /* [6921] */
    (xdc_Char)0x65,  /* [6922] */
    (xdc_Char)0x6d,  /* [6923] */
    (xdc_Char)0x61,  /* [6924] */
    (xdc_Char)0x70,  /* [6925] */
    (xdc_Char)0x68,  /* [6926] */
    (xdc_Char)0x6f,  /* [6927] */
    (xdc_Char)0x72,  /* [6928] */
    (xdc_Char)0x65,  /* [6929] */
    (xdc_Char)0x0,  /* [6930] */
    (xdc_Char)0x53,  /* [6931] */
    (xdc_Char)0x77,  /* [6932] */
    (xdc_Char)0x69,  /* [6933] */
    (xdc_Char)0x0,  /* [6934] */
    (xdc_Char)0x54,  /* [6935] */
    (xdc_Char)0x61,  /* [6936] */
    (xdc_Char)0x73,  /* [6937] */
    (xdc_Char)0x6b,  /* [6938] */
    (xdc_Char)0x0,  /* [6939] */
    (xdc_Char)0x42,  /* [6940] */
    (xdc_Char)0x49,  /* [6941] */
    (xdc_Char)0x4f,  /* [6942] */
    (xdc_Char)0x53,  /* [6943] */
    (xdc_Char)0x0,  /* [6944] */
    (xdc_Char)0x68,  /* [6945] */
    (xdc_Char)0x61,  /* [6946] */
    (xdc_Char)0x6c,  /* [6947] */
    (xdc_Char)0x2e,  /* [6948] */
    (xdc_Char)0x0,  /* [6949] */
    (xdc_Char)0x43,  /* [6950] */
    (xdc_Char)0x61,  /* [6951] */
    (xdc_Char)0x63,  /* [6952] */
    (xdc_Char)0x68,  /* [6953] */
    (xdc_Char)0x65,  /* [6954] */
    (xdc_Char)0x0,  /* [6955] */
    (xdc_Char)0x48,  /* [6956] */
    (xdc_Char)0x77,  /* [6957] */
    (xdc_Char)0x69,  /* [6958] */
    (xdc_Char)0x0,  /* [6959] */
    (xdc_Char)0x66,  /* [6960] */
    (xdc_Char)0x61,  /* [6961] */
    (xdc_Char)0x6d,  /* [6962] */
    (xdc_Char)0x69,  /* [6963] */
    (xdc_Char)0x6c,  /* [6964] */
    (xdc_Char)0x79,  /* [6965] */
    (xdc_Char)0x2e,  /* [6966] */
    (xdc_Char)0x0,  /* [6967] */
    (xdc_Char)0x61,  /* [6968] */
    (xdc_Char)0x72,  /* [6969] */
    (xdc_Char)0x6d,  /* [6970] */
    (xdc_Char)0x2e,  /* [6971] */
    (xdc_Char)0x0,  /* [6972] */
    (xdc_Char)0x6d,  /* [6973] */
    (xdc_Char)0x33,  /* [6974] */
    (xdc_Char)0x2e,  /* [6975] */
    (xdc_Char)0x0,  /* [6976] */
    (xdc_Char)0x49,  /* [6977] */
    (xdc_Char)0x6e,  /* [6978] */
    (xdc_Char)0x74,  /* [6979] */
    (xdc_Char)0x72,  /* [6980] */
    (xdc_Char)0x69,  /* [6981] */
    (xdc_Char)0x6e,  /* [6982] */
    (xdc_Char)0x73,  /* [6983] */
    (xdc_Char)0x69,  /* [6984] */
    (xdc_Char)0x63,  /* [6985] */
    (xdc_Char)0x73,  /* [6986] */
    (xdc_Char)0x53,  /* [6987] */
    (xdc_Char)0x75,  /* [6988] */
    (xdc_Char)0x70,  /* [6989] */
    (xdc_Char)0x70,  /* [6990] */
    (xdc_Char)0x6f,  /* [6991] */
    (xdc_Char)0x72,  /* [6992] */
    (xdc_Char)0x74,  /* [6993] */
    (xdc_Char)0x0,  /* [6994] */
    (xdc_Char)0x54,  /* [6995] */
    (xdc_Char)0x61,  /* [6996] */
    (xdc_Char)0x73,  /* [6997] */
    (xdc_Char)0x6b,  /* [6998] */
    (xdc_Char)0x53,  /* [6999] */
    (xdc_Char)0x75,  /* [7000] */
    (xdc_Char)0x70,  /* [7001] */
    (xdc_Char)0x70,  /* [7002] */
    (xdc_Char)0x6f,  /* [7003] */
    (xdc_Char)0x72,  /* [7004] */
    (xdc_Char)0x74,  /* [7005] */
    (xdc_Char)0x0,  /* [7006] */
    (xdc_Char)0x73,  /* [7007] */
    (xdc_Char)0x68,  /* [7008] */
    (xdc_Char)0x61,  /* [7009] */
    (xdc_Char)0x72,  /* [7010] */
    (xdc_Char)0x65,  /* [7011] */
    (xdc_Char)0x64,  /* [7012] */
    (xdc_Char)0x2e,  /* [7013] */
    (xdc_Char)0x0,  /* [7014] */
    (xdc_Char)0x76,  /* [7015] */
    (xdc_Char)0x61,  /* [7016] */
    (xdc_Char)0x79,  /* [7017] */
    (xdc_Char)0x75,  /* [7018] */
    (xdc_Char)0x2e,  /* [7019] */
    (xdc_Char)0x0,  /* [7020] */
    (xdc_Char)0x49,  /* [7021] */
    (xdc_Char)0x6e,  /* [7022] */
    (xdc_Char)0x74,  /* [7023] */
    (xdc_Char)0x58,  /* [7024] */
    (xdc_Char)0x62,  /* [7025] */
    (xdc_Char)0x61,  /* [7026] */
    (xdc_Char)0x72,  /* [7027] */
    (xdc_Char)0x0,  /* [7028] */
    (xdc_Char)0x64,  /* [7029] */
    (xdc_Char)0x75,  /* [7030] */
    (xdc_Char)0x63,  /* [7031] */
    (xdc_Char)0x61,  /* [7032] */
    (xdc_Char)0x74,  /* [7033] */
    (xdc_Char)0x69,  /* [7034] */
    (xdc_Char)0x2e,  /* [7035] */
    (xdc_Char)0x0,  /* [7036] */
    (xdc_Char)0x43,  /* [7037] */
    (xdc_Char)0x54,  /* [7038] */
    (xdc_Char)0x4d,  /* [7039] */
    (xdc_Char)0x0,  /* [7040] */
    (xdc_Char)0x47,  /* [7041] */
    (xdc_Char)0x61,  /* [7042] */
    (xdc_Char)0x74,  /* [7043] */
    (xdc_Char)0x65,  /* [7044] */
    (xdc_Char)0x44,  /* [7045] */
    (xdc_Char)0x75,  /* [7046] */
    (xdc_Char)0x61,  /* [7047] */
    (xdc_Char)0x6c,  /* [7048] */
    (xdc_Char)0x43,  /* [7049] */
    (xdc_Char)0x6f,  /* [7050] */
    (xdc_Char)0x72,  /* [7051] */
    (xdc_Char)0x65,  /* [7052] */
    (xdc_Char)0x0,  /* [7053] */
    (xdc_Char)0x54,  /* [7054] */
    (xdc_Char)0x69,  /* [7055] */
    (xdc_Char)0x6d,  /* [7056] */
    (xdc_Char)0x65,  /* [7057] */
    (xdc_Char)0x72,  /* [7058] */
    (xdc_Char)0x0,  /* [7059] */
    (xdc_Char)0x75,  /* [7060] */
    (xdc_Char)0x6e,  /* [7061] */
    (xdc_Char)0x69,  /* [7062] */
    (xdc_Char)0x63,  /* [7063] */
    (xdc_Char)0x61,  /* [7064] */
    (xdc_Char)0x63,  /* [7065] */
    (xdc_Char)0x68,  /* [7066] */
    (xdc_Char)0x65,  /* [7067] */
    (xdc_Char)0x2e,  /* [7068] */
    (xdc_Char)0x0,  /* [7069] */
    (xdc_Char)0x61,  /* [7070] */
    (xdc_Char)0x6d,  /* [7071] */
    (xdc_Char)0x6d,  /* [7072] */
    (xdc_Char)0x75,  /* [7073] */
    (xdc_Char)0x2e,  /* [7074] */
    (xdc_Char)0x0,  /* [7075] */
    (xdc_Char)0x41,  /* [7076] */
    (xdc_Char)0x4d,  /* [7077] */
    (xdc_Char)0x4d,  /* [7078] */
    (xdc_Char)0x55,  /* [7079] */
    (xdc_Char)0x0,  /* [7080] */
    (xdc_Char)0x67,  /* [7081] */
    (xdc_Char)0x61,  /* [7082] */
    (xdc_Char)0x74,  /* [7083] */
    (xdc_Char)0x65,  /* [7084] */
    (xdc_Char)0x73,  /* [7085] */
    (xdc_Char)0x2e,  /* [7086] */
    (xdc_Char)0x0,  /* [7087] */
    (xdc_Char)0x47,  /* [7088] */
    (xdc_Char)0x61,  /* [7089] */
    (xdc_Char)0x74,  /* [7090] */
    (xdc_Char)0x65,  /* [7091] */
    (xdc_Char)0x48,  /* [7092] */
    (xdc_Char)0x77,  /* [7093] */
    (xdc_Char)0x69,  /* [7094] */
    (xdc_Char)0x0,  /* [7095] */
    (xdc_Char)0x47,  /* [7096] */
    (xdc_Char)0x61,  /* [7097] */
    (xdc_Char)0x74,  /* [7098] */
    (xdc_Char)0x65,  /* [7099] */
    (xdc_Char)0x4d,  /* [7100] */
    (xdc_Char)0x75,  /* [7101] */
    (xdc_Char)0x74,  /* [7102] */
    (xdc_Char)0x65,  /* [7103] */
    (xdc_Char)0x78,  /* [7104] */
    (xdc_Char)0x0,  /* [7105] */
    (xdc_Char)0x68,  /* [7106] */
    (xdc_Char)0x65,  /* [7107] */
    (xdc_Char)0x61,  /* [7108] */
    (xdc_Char)0x70,  /* [7109] */
    (xdc_Char)0x73,  /* [7110] */
    (xdc_Char)0x2e,  /* [7111] */
    (xdc_Char)0x0,  /* [7112] */
    (xdc_Char)0x48,  /* [7113] */
    (xdc_Char)0x65,  /* [7114] */
    (xdc_Char)0x61,  /* [7115] */
    (xdc_Char)0x70,  /* [7116] */
    (xdc_Char)0x4d,  /* [7117] */
    (xdc_Char)0x65,  /* [7118] */
    (xdc_Char)0x6d,  /* [7119] */
    (xdc_Char)0x0,  /* [7120] */
    (xdc_Char)0x74,  /* [7121] */
    (xdc_Char)0x69,  /* [7122] */
    (xdc_Char)0x2e,  /* [7123] */
    (xdc_Char)0x73,  /* [7124] */
    (xdc_Char)0x79,  /* [7125] */
    (xdc_Char)0x73,  /* [7126] */
    (xdc_Char)0x62,  /* [7127] */
    (xdc_Char)0x69,  /* [7128] */
    (xdc_Char)0x6f,  /* [7129] */
    (xdc_Char)0x73,  /* [7130] */
    (xdc_Char)0x2e,  /* [7131] */
    (xdc_Char)0x6b,  /* [7132] */
    (xdc_Char)0x6e,  /* [7133] */
    (xdc_Char)0x6c,  /* [7134] */
    (xdc_Char)0x2e,  /* [7135] */
    (xdc_Char)0x54,  /* [7136] */
    (xdc_Char)0x61,  /* [7137] */
    (xdc_Char)0x73,  /* [7138] */
    (xdc_Char)0x6b,  /* [7139] */
    (xdc_Char)0x2e,  /* [7140] */
    (xdc_Char)0x49,  /* [7141] */
    (xdc_Char)0x64,  /* [7142] */
    (xdc_Char)0x6c,  /* [7143] */
    (xdc_Char)0x65,  /* [7144] */
    (xdc_Char)0x54,  /* [7145] */
    (xdc_Char)0x61,  /* [7146] */
    (xdc_Char)0x73,  /* [7147] */
    (xdc_Char)0x6b,  /* [7148] */
    (xdc_Char)0x0,  /* [7149] */
};

/* --> xdc_runtime_Text_nodeTab__A */
#pragma DATA_SECTION(xdc_runtime_Text_nodeTab__A, ".const:xdc_runtime_Text_nodeTab__A");
const __T1_xdc_runtime_Text_nodeTab xdc_runtime_Text_nodeTab__A[52] = {
    {
        (xdc_Bits16)0x0,  /* left */
        (xdc_Bits16)0x0,  /* right */
    },  /* [0] */
    {
        (xdc_Bits16)0x1a73,  /* left */
        (xdc_Bits16)0x1a78,  /* right */
    },  /* [1] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1a81,  /* right */
    },  /* [2] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1a88,  /* right */
    },  /* [3] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1a8d,  /* right */
    },  /* [4] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1a96,  /* right */
    },  /* [5] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1a9c,  /* right */
    },  /* [6] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1aa2,  /* right */
    },  /* [7] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1aa7,  /* right */
    },  /* [8] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1aab,  /* right */
    },  /* [9] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1ab0,  /* right */
    },  /* [10] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1ab7,  /* right */
    },  /* [11] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1ac0,  /* right */
    },  /* [12] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1ac8,  /* right */
    },  /* [13] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1acf,  /* right */
    },  /* [14] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1ad6,  /* right */
    },  /* [15] */
    {
        (xdc_Bits16)0x1adb,  /* left */
        (xdc_Bits16)0x1adf,  /* right */
    },  /* [16] */
    {
        (xdc_Bits16)0x8010,  /* left */
        (xdc_Bits16)0x1ae8,  /* right */
    },  /* [17] */
    {
        (xdc_Bits16)0x8011,  /* left */
        (xdc_Bits16)0x1aed,  /* right */
    },  /* [18] */
    {
        (xdc_Bits16)0x8011,  /* left */
        (xdc_Bits16)0x1af3,  /* right */
    },  /* [19] */
    {
        (xdc_Bits16)0x8011,  /* left */
        (xdc_Bits16)0x1af8,  /* right */
    },  /* [20] */
    {
        (xdc_Bits16)0x8011,  /* left */
        (xdc_Bits16)0x1b03,  /* right */
    },  /* [21] */
    {
        (xdc_Bits16)0x8011,  /* left */
        (xdc_Bits16)0x1b09,  /* right */
    },  /* [22] */
    {
        (xdc_Bits16)0x8011,  /* left */
        (xdc_Bits16)0x1b13,  /* right */
    },  /* [23] */
    {
        (xdc_Bits16)0x8011,  /* left */
        (xdc_Bits16)0x1b17,  /* right */
    },  /* [24] */
    {
        (xdc_Bits16)0x8010,  /* left */
        (xdc_Bits16)0x1b1c,  /* right */
    },  /* [25] */
    {
        (xdc_Bits16)0x8010,  /* left */
        (xdc_Bits16)0x1b21,  /* right */
    },  /* [26] */
    {
        (xdc_Bits16)0x801a,  /* left */
        (xdc_Bits16)0x1b26,  /* right */
    },  /* [27] */
    {
        (xdc_Bits16)0x801a,  /* left */
        (xdc_Bits16)0x1b2c,  /* right */
    },  /* [28] */
    {
        (xdc_Bits16)0x8010,  /* left */
        (xdc_Bits16)0x1b30,  /* right */
    },  /* [29] */
    {
        (xdc_Bits16)0x801d,  /* left */
        (xdc_Bits16)0x1b38,  /* right */
    },  /* [30] */
    {
        (xdc_Bits16)0x801e,  /* left */
        (xdc_Bits16)0x1b3d,  /* right */
    },  /* [31] */
    {
        (xdc_Bits16)0x801f,  /* left */
        (xdc_Bits16)0x1b2c,  /* right */
    },  /* [32] */
    {
        (xdc_Bits16)0x801f,  /* left */
        (xdc_Bits16)0x1b41,  /* right */
    },  /* [33] */
    {
        (xdc_Bits16)0x801f,  /* left */
        (xdc_Bits16)0x1b53,  /* right */
    },  /* [34] */
    {
        (xdc_Bits16)0x801d,  /* left */
        (xdc_Bits16)0x1b5f,  /* right */
    },  /* [35] */
    {
        (xdc_Bits16)0x8023,  /* left */
        (xdc_Bits16)0x1b67,  /* right */
    },  /* [36] */
    {
        (xdc_Bits16)0x8024,  /* left */
        (xdc_Bits16)0x1b6d,  /* right */
    },  /* [37] */
    {
        (xdc_Bits16)0x801e,  /* left */
        (xdc_Bits16)0x1b75,  /* right */
    },  /* [38] */
    {
        (xdc_Bits16)0x8026,  /* left */
        (xdc_Bits16)0x1a88,  /* right */
    },  /* [39] */
    {
        (xdc_Bits16)0x8026,  /* left */
        (xdc_Bits16)0x1b7d,  /* right */
    },  /* [40] */
    {
        (xdc_Bits16)0x8026,  /* left */
        (xdc_Bits16)0x1b81,  /* right */
    },  /* [41] */
    {
        (xdc_Bits16)0x8026,  /* left */
        (xdc_Bits16)0x1b8e,  /* right */
    },  /* [42] */
    {
        (xdc_Bits16)0x801a,  /* left */
        (xdc_Bits16)0x1b94,  /* right */
    },  /* [43] */
    {
        (xdc_Bits16)0x802b,  /* left */
        (xdc_Bits16)0x1b26,  /* right */
    },  /* [44] */
    {
        (xdc_Bits16)0x801a,  /* left */
        (xdc_Bits16)0x1b9e,  /* right */
    },  /* [45] */
    {
        (xdc_Bits16)0x802d,  /* left */
        (xdc_Bits16)0x1ba4,  /* right */
    },  /* [46] */
    {
        (xdc_Bits16)0x8010,  /* left */
        (xdc_Bits16)0x1ba9,  /* right */
    },  /* [47] */
    {
        (xdc_Bits16)0x802f,  /* left */
        (xdc_Bits16)0x1bb0,  /* right */
    },  /* [48] */
    {
        (xdc_Bits16)0x802f,  /* left */
        (xdc_Bits16)0x1bb8,  /* right */
    },  /* [49] */
    {
        (xdc_Bits16)0x8010,  /* left */
        (xdc_Bits16)0x1bc2,  /* right */
    },  /* [50] */
    {
        (xdc_Bits16)0x8032,  /* left */
        (xdc_Bits16)0x1bc9,  /* right */
    },  /* [51] */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(xdc_runtime_Text_Module__diagsEnabled__C, ".const:xdc_runtime_Text_Module__diagsEnabled__C");
__FAR__ const CT__xdc_runtime_Text_Module__diagsEnabled xdc_runtime_Text_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(xdc_runtime_Text_Module__diagsIncluded__C, ".const:xdc_runtime_Text_Module__diagsIncluded__C");
__FAR__ const CT__xdc_runtime_Text_Module__diagsIncluded xdc_runtime_Text_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
#pragma DATA_SECTION(xdc_runtime_Text_Module__diagsMask__C, ".const:xdc_runtime_Text_Module__diagsMask__C");
__FAR__ const CT__xdc_runtime_Text_Module__diagsMask xdc_runtime_Text_Module__diagsMask__C = ((CT__xdc_runtime_Text_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(xdc_runtime_Text_Module__gateObj__C, ".const:xdc_runtime_Text_Module__gateObj__C");
__FAR__ const CT__xdc_runtime_Text_Module__gateObj xdc_runtime_Text_Module__gateObj__C = ((CT__xdc_runtime_Text_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(xdc_runtime_Text_Module__gatePrms__C, ".const:xdc_runtime_Text_Module__gatePrms__C");
__FAR__ const CT__xdc_runtime_Text_Module__gatePrms xdc_runtime_Text_Module__gatePrms__C = ((CT__xdc_runtime_Text_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(xdc_runtime_Text_Module__id__C, ".const:xdc_runtime_Text_Module__id__C");
__FAR__ const CT__xdc_runtime_Text_Module__id xdc_runtime_Text_Module__id__C = (xdc_Bits16)0x800f;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(xdc_runtime_Text_Module__loggerDefined__C, ".const:xdc_runtime_Text_Module__loggerDefined__C");
__FAR__ const CT__xdc_runtime_Text_Module__loggerDefined xdc_runtime_Text_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(xdc_runtime_Text_Module__loggerObj__C, ".const:xdc_runtime_Text_Module__loggerObj__C");
__FAR__ const CT__xdc_runtime_Text_Module__loggerObj xdc_runtime_Text_Module__loggerObj__C = ((CT__xdc_runtime_Text_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(xdc_runtime_Text_Module__loggerFxn0__C, ".const:xdc_runtime_Text_Module__loggerFxn0__C");
__FAR__ const CT__xdc_runtime_Text_Module__loggerFxn0 xdc_runtime_Text_Module__loggerFxn0__C = ((CT__xdc_runtime_Text_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(xdc_runtime_Text_Module__loggerFxn1__C, ".const:xdc_runtime_Text_Module__loggerFxn1__C");
__FAR__ const CT__xdc_runtime_Text_Module__loggerFxn1 xdc_runtime_Text_Module__loggerFxn1__C = ((CT__xdc_runtime_Text_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(xdc_runtime_Text_Module__loggerFxn2__C, ".const:xdc_runtime_Text_Module__loggerFxn2__C");
__FAR__ const CT__xdc_runtime_Text_Module__loggerFxn2 xdc_runtime_Text_Module__loggerFxn2__C = ((CT__xdc_runtime_Text_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(xdc_runtime_Text_Module__loggerFxn4__C, ".const:xdc_runtime_Text_Module__loggerFxn4__C");
__FAR__ const CT__xdc_runtime_Text_Module__loggerFxn4 xdc_runtime_Text_Module__loggerFxn4__C = ((CT__xdc_runtime_Text_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(xdc_runtime_Text_Module__loggerFxn8__C, ".const:xdc_runtime_Text_Module__loggerFxn8__C");
__FAR__ const CT__xdc_runtime_Text_Module__loggerFxn8 xdc_runtime_Text_Module__loggerFxn8__C = ((CT__xdc_runtime_Text_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(xdc_runtime_Text_Module__startupDoneFxn__C, ".const:xdc_runtime_Text_Module__startupDoneFxn__C");
__FAR__ const CT__xdc_runtime_Text_Module__startupDoneFxn xdc_runtime_Text_Module__startupDoneFxn__C = ((CT__xdc_runtime_Text_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(xdc_runtime_Text_Object__count__C, ".const:xdc_runtime_Text_Object__count__C");
__FAR__ const CT__xdc_runtime_Text_Object__count xdc_runtime_Text_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(xdc_runtime_Text_Object__heap__C, ".const:xdc_runtime_Text_Object__heap__C");
__FAR__ const CT__xdc_runtime_Text_Object__heap xdc_runtime_Text_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(xdc_runtime_Text_Object__sizeof__C, ".const:xdc_runtime_Text_Object__sizeof__C");
__FAR__ const CT__xdc_runtime_Text_Object__sizeof xdc_runtime_Text_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(xdc_runtime_Text_Object__table__C, ".const:xdc_runtime_Text_Object__table__C");
__FAR__ const CT__xdc_runtime_Text_Object__table xdc_runtime_Text_Object__table__C = 0;

/* nameUnknown__C */
#pragma DATA_SECTION(xdc_runtime_Text_nameUnknown__C, ".const:xdc_runtime_Text_nameUnknown__C");
__FAR__ const CT__xdc_runtime_Text_nameUnknown xdc_runtime_Text_nameUnknown__C = "{unknown-instance-name}";

/* nameEmpty__C */
#pragma DATA_SECTION(xdc_runtime_Text_nameEmpty__C, ".const:xdc_runtime_Text_nameEmpty__C");
__FAR__ const CT__xdc_runtime_Text_nameEmpty xdc_runtime_Text_nameEmpty__C = "{empty-instance-name}";

/* nameStatic__C */
#pragma DATA_SECTION(xdc_runtime_Text_nameStatic__C, ".const:xdc_runtime_Text_nameStatic__C");
__FAR__ const CT__xdc_runtime_Text_nameStatic xdc_runtime_Text_nameStatic__C = "{static-instance-name}";

/* isLoaded__C */
#pragma DATA_SECTION(xdc_runtime_Text_isLoaded__C, ".const:xdc_runtime_Text_isLoaded__C");
__FAR__ const CT__xdc_runtime_Text_isLoaded xdc_runtime_Text_isLoaded__C = 1;

/* charTab__C */
#pragma DATA_SECTION(xdc_runtime_Text_charTab__C, ".const:xdc_runtime_Text_charTab__C");
__FAR__ const CT__xdc_runtime_Text_charTab xdc_runtime_Text_charTab__C = ((CT__xdc_runtime_Text_charTab)xdc_runtime_Text_charTab__A);

/* nodeTab__C */
#pragma DATA_SECTION(xdc_runtime_Text_nodeTab__C, ".const:xdc_runtime_Text_nodeTab__C");
__FAR__ const CT__xdc_runtime_Text_nodeTab xdc_runtime_Text_nodeTab__C = ((CT__xdc_runtime_Text_nodeTab)xdc_runtime_Text_nodeTab__A);

/* charCnt__C */
#pragma DATA_SECTION(xdc_runtime_Text_charCnt__C, ".const:xdc_runtime_Text_charCnt__C");
__FAR__ const CT__xdc_runtime_Text_charCnt xdc_runtime_Text_charCnt__C = (xdc_Int16)0x1bee;

/* nodeCnt__C */
#pragma DATA_SECTION(xdc_runtime_Text_nodeCnt__C, ".const:xdc_runtime_Text_nodeCnt__C");
__FAR__ const CT__xdc_runtime_Text_nodeCnt xdc_runtime_Text_nodeCnt__C = (xdc_Int16)0x34;

/* unnamedModsLastId__C */
#pragma DATA_SECTION(xdc_runtime_Text_unnamedModsLastId__C, ".const:xdc_runtime_Text_unnamedModsLastId__C");
__FAR__ const CT__xdc_runtime_Text_unnamedModsLastId xdc_runtime_Text_unnamedModsLastId__C = (xdc_UInt16)0x4000;

/* registryModsLastId__C */
#pragma DATA_SECTION(xdc_runtime_Text_registryModsLastId__C, ".const:xdc_runtime_Text_registryModsLastId__C");
__FAR__ const CT__xdc_runtime_Text_registryModsLastId xdc_runtime_Text_registryModsLastId__C = (xdc_UInt16)0x7fff;

/* visitRopeFxn__C */
#pragma DATA_SECTION(xdc_runtime_Text_visitRopeFxn__C, ".const:xdc_runtime_Text_visitRopeFxn__C");
__FAR__ const CT__xdc_runtime_Text_visitRopeFxn xdc_runtime_Text_visitRopeFxn__C = ((CT__xdc_runtime_Text_visitRopeFxn)((xdc_Fxn)xdc_runtime_Text_visitRope__I));

/* visitRopeFxn2__C */
#pragma DATA_SECTION(xdc_runtime_Text_visitRopeFxn2__C, ".const:xdc_runtime_Text_visitRopeFxn2__C");
__FAR__ const CT__xdc_runtime_Text_visitRopeFxn2 xdc_runtime_Text_visitRopeFxn2__C = ((CT__xdc_runtime_Text_visitRopeFxn2)((xdc_Fxn)xdc_runtime_Text_visitRope2__I));


/*
 * ======== xdc.runtime.System FUNCTION STUBS ========
 */

/* printf_va__E */
xdc_Int xdc_runtime_System_printf_va__E( xdc_CString fmt, va_list __va ) 
{
    return xdc_runtime_System_printf_va__F(fmt, __va);
}

/* printf__E */
xdc_Int xdc_runtime_System_printf__E( xdc_CString fmt, ... ) 
{
    xdc_Int __ret;

    va_list __va; va_start(__va, fmt);
    __ret = xdc_runtime_System_printf_va__F(fmt, __va);

    va_end(__va);
    return __ret;
}

/* aprintf_va__E */
xdc_Int xdc_runtime_System_aprintf_va__E( xdc_CString fmt, va_list __va ) 
{
    return xdc_runtime_System_aprintf_va__F(fmt, __va);
}

/* aprintf__E */
xdc_Int xdc_runtime_System_aprintf__E( xdc_CString fmt, ... ) 
{
    xdc_Int __ret;

    va_list __va; va_start(__va, fmt);
    __ret = xdc_runtime_System_aprintf_va__F(fmt, __va);

    va_end(__va);
    return __ret;
}

/* sprintf_va__E */
xdc_Int xdc_runtime_System_sprintf_va__E( xdc_Char buf[], xdc_CString fmt, va_list __va ) 
{
    return xdc_runtime_System_sprintf_va__F(buf, fmt, __va);
}

/* sprintf__E */
xdc_Int xdc_runtime_System_sprintf__E( xdc_Char buf[], xdc_CString fmt, ... ) 
{
    xdc_Int __ret;

    va_list __va; va_start(__va, fmt);
    __ret = xdc_runtime_System_sprintf_va__F(buf, fmt, __va);

    va_end(__va);
    return __ret;
}

/* asprintf_va__E */
xdc_Int xdc_runtime_System_asprintf_va__E( xdc_Char buf[], xdc_CString fmt, va_list __va ) 
{
    return xdc_runtime_System_asprintf_va__F(buf, fmt, __va);
}

/* asprintf__E */
xdc_Int xdc_runtime_System_asprintf__E( xdc_Char buf[], xdc_CString fmt, ... ) 
{
    xdc_Int __ret;

    va_list __va; va_start(__va, fmt);
    __ret = xdc_runtime_System_asprintf_va__F(buf, fmt, __va);

    va_end(__va);
    return __ret;
}

/* snprintf_va__E */
xdc_Int xdc_runtime_System_snprintf_va__E( xdc_Char buf[], xdc_SizeT n, xdc_CString fmt, va_list __va ) 
{
    return xdc_runtime_System_snprintf_va__F(buf, n, fmt, __va);
}

/* snprintf__E */
xdc_Int xdc_runtime_System_snprintf__E( xdc_Char buf[], xdc_SizeT n, xdc_CString fmt, ... ) 
{
    xdc_Int __ret;

    va_list __va; va_start(__va, fmt);
    __ret = xdc_runtime_System_snprintf_va__F(buf, n, fmt, __va);

    va_end(__va);
    return __ret;
}


/*
 * ======== ti.sysbios.BIOS_RtsGateProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.gates.GateMutex */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_BIOS_RtsGateProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_gates_GateMutex_Module__startupDone__S();
}

/* Object__create__S */
xdc_Ptr ti_sysbios_BIOS_RtsGateProxy_Object__create__S (
    xdc_Ptr __obj, 
    xdc_SizeT __osz,
    const xdc_Ptr __aa,
    const ti_sysbios_BIOS_RtsGateProxy___ParamsPtr __paramsPtr,
    xdc_SizeT __psz,
    xdc_runtime_Error_Block *__eb)
{
    return ti_sysbios_gates_GateMutex_Object__create__S(__obj, __osz, __aa, (const ti_sysbios_gates_GateMutex___ParamsPtr)__paramsPtr, sizeof(xdc_runtime_IGateProvider_Params), __eb);
}

/* create */
ti_sysbios_BIOS_RtsGateProxy_Handle ti_sysbios_BIOS_RtsGateProxy_create( const ti_sysbios_BIOS_RtsGateProxy_Params *__prms, xdc_runtime_Error_Block *__eb )
{
    return (ti_sysbios_BIOS_RtsGateProxy_Handle)ti_sysbios_BIOS_RtsGateProxy_Object__create__S(0, 0, 0, (const xdc_UChar*)__prms, sizeof(ti_sysbios_BIOS_RtsGateProxy_Params), __eb);
}

/* Object__delete__S */
void ti_sysbios_BIOS_RtsGateProxy_Object__delete__S( xdc_Ptr instp ) 
{
    ti_sysbios_gates_GateMutex_Object__delete__S(instp);
}

/* delete */
void ti_sysbios_BIOS_RtsGateProxy_delete(ti_sysbios_BIOS_RtsGateProxy_Handle *instp)
{
    ti_sysbios_BIOS_RtsGateProxy_Object__delete__S(instp);
}

/* Params__init__S */
void ti_sysbios_BIOS_RtsGateProxy_Params__init__S( xdc_Ptr dst, const void *src, xdc_SizeT psz, xdc_SizeT isz )
{
    ti_sysbios_gates_GateMutex_Params__init__S(dst, src, psz, isz);
}

/* Handle__label__S */
xdc_runtime_Types_Label *ti_sysbios_BIOS_RtsGateProxy_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab)
{
    return ti_sysbios_gates_GateMutex_Handle__label__S(obj, lab);
}

/* query__E */
xdc_Bool ti_sysbios_BIOS_RtsGateProxy_query__E( xdc_Int qual )
{
    return ti_sysbios_gates_GateMutex_query(qual);
}

/* enter__E */
xdc_IArg ti_sysbios_BIOS_RtsGateProxy_enter__E( ti_sysbios_BIOS_RtsGateProxy_Handle __inst )
{
    return ti_sysbios_gates_GateMutex_enter((ti_sysbios_gates_GateMutex_Handle)__inst);
}

/* leave__E */
xdc_Void ti_sysbios_BIOS_RtsGateProxy_leave__E( ti_sysbios_BIOS_RtsGateProxy_Handle __inst, xdc_IArg key )
{
    ti_sysbios_gates_GateMutex_leave((ti_sysbios_gates_GateMutex_Handle)__inst, key);
}


/*
 * ======== ti.sysbios.hal.Cache_CacheProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.hal.unicache.Cache */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_hal_Cache_CacheProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_hal_unicache_Cache_Module__startupDone__S();
}

/* enable__E */
xdc_Void ti_sysbios_hal_Cache_CacheProxy_enable__E( xdc_Bits16 type )
{
    ti_sysbios_hal_unicache_Cache_enable(type);
}

/* disable__E */
xdc_Void ti_sysbios_hal_Cache_CacheProxy_disable__E( xdc_Bits16 type )
{
    ti_sysbios_hal_unicache_Cache_disable(type);
}

/* inv__E */
xdc_Void ti_sysbios_hal_Cache_CacheProxy_inv__E( xdc_Ptr blockPtr, xdc_SizeT byteCnt, xdc_Bits16 type, xdc_Bool wait )
{
    ti_sysbios_hal_unicache_Cache_inv(blockPtr, byteCnt, type, wait);
}

/* wb__E */
xdc_Void ti_sysbios_hal_Cache_CacheProxy_wb__E( xdc_Ptr blockPtr, xdc_SizeT byteCnt, xdc_Bits16 type, xdc_Bool wait )
{
    ti_sysbios_hal_unicache_Cache_wb(blockPtr, byteCnt, type, wait);
}

/* wbInv__E */
xdc_Void ti_sysbios_hal_Cache_CacheProxy_wbInv__E( xdc_Ptr blockPtr, xdc_SizeT byteCnt, xdc_Bits16 type, xdc_Bool wait )
{
    ti_sysbios_hal_unicache_Cache_wbInv(blockPtr, byteCnt, type, wait);
}

/* wbAll__E */
xdc_Void ti_sysbios_hal_Cache_CacheProxy_wbAll__E( void )
{
    ti_sysbios_hal_unicache_Cache_wbAll();
}

/* wbInvAll__E */
xdc_Void ti_sysbios_hal_Cache_CacheProxy_wbInvAll__E( void )
{
    ti_sysbios_hal_unicache_Cache_wbInvAll();
}

/* wait__E */
xdc_Void ti_sysbios_hal_Cache_CacheProxy_wait__E( void )
{
    ti_sysbios_hal_unicache_Cache_wait();
}


/*
 * ======== ti.sysbios.hal.Hwi_HwiProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.family.arm.m3.Hwi */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_hal_Hwi_HwiProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_arm_m3_Hwi_Module__startupDone__S();
}

/* Object__create__S */
xdc_Ptr ti_sysbios_hal_Hwi_HwiProxy_Object__create__S (
    xdc_Ptr __obj, 
    xdc_SizeT __osz,
    const xdc_Ptr __aa,
    const ti_sysbios_hal_Hwi_HwiProxy___ParamsPtr __paramsPtr,
    xdc_SizeT __psz,
    xdc_runtime_Error_Block *__eb)
{
    return ti_sysbios_family_arm_m3_Hwi_Object__create__S(__obj, __osz, __aa, (const ti_sysbios_family_arm_m3_Hwi___ParamsPtr)__paramsPtr, sizeof(ti_sysbios_interfaces_IHwi_Params), __eb);
}

/* create */
ti_sysbios_hal_Hwi_HwiProxy_Handle ti_sysbios_hal_Hwi_HwiProxy_create( xdc_Int intNum, ti_sysbios_interfaces_IHwi_FuncPtr hwiFxn, const ti_sysbios_hal_Hwi_HwiProxy_Params *__prms, xdc_runtime_Error_Block *__eb )
{
    ti_sysbios_hal_Hwi_HwiProxy_Args__create __args;
    __args.intNum = intNum;
    __args.hwiFxn = hwiFxn;
    return (ti_sysbios_hal_Hwi_HwiProxy_Handle)ti_sysbios_hal_Hwi_HwiProxy_Object__create__S(0, 0, &__args, (const xdc_UChar*)__prms, sizeof(ti_sysbios_hal_Hwi_HwiProxy_Params), __eb);
}

/* Object__delete__S */
void ti_sysbios_hal_Hwi_HwiProxy_Object__delete__S( xdc_Ptr instp ) 
{
    ti_sysbios_family_arm_m3_Hwi_Object__delete__S(instp);
}

/* delete */
void ti_sysbios_hal_Hwi_HwiProxy_delete(ti_sysbios_hal_Hwi_HwiProxy_Handle *instp)
{
    ti_sysbios_hal_Hwi_HwiProxy_Object__delete__S(instp);
}

/* Params__init__S */
void ti_sysbios_hal_Hwi_HwiProxy_Params__init__S( xdc_Ptr dst, const void *src, xdc_SizeT psz, xdc_SizeT isz )
{
    ti_sysbios_family_arm_m3_Hwi_Params__init__S(dst, src, psz, isz);
}

/* Handle__label__S */
xdc_runtime_Types_Label *ti_sysbios_hal_Hwi_HwiProxy_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab)
{
    return ti_sysbios_family_arm_m3_Hwi_Handle__label__S(obj, lab);
}

/* getStackInfo__E */
xdc_Bool ti_sysbios_hal_Hwi_HwiProxy_getStackInfo__E( ti_sysbios_interfaces_IHwi_StackInfo *stkInfo, xdc_Bool computeStackDepth )
{
    return ti_sysbios_family_arm_m3_Hwi_getStackInfo(stkInfo, computeStackDepth);
}

/* getCoreStackInfo__E */
xdc_Bool ti_sysbios_hal_Hwi_HwiProxy_getCoreStackInfo__E( ti_sysbios_interfaces_IHwi_StackInfo *stkInfo, xdc_Bool computeStackDepth, xdc_UInt coreId )
{
    return ti_sysbios_family_arm_m3_Hwi_getCoreStackInfo(stkInfo, computeStackDepth, coreId);
}

/* startup__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_startup__E( void )
{
    ti_sysbios_family_arm_m3_Hwi_startup();
}

/* disable__E */
xdc_UInt ti_sysbios_hal_Hwi_HwiProxy_disable__E( void )
{
    return ti_sysbios_family_arm_m3_Hwi_disable();
}

/* enable__E */
xdc_UInt ti_sysbios_hal_Hwi_HwiProxy_enable__E( void )
{
    return ti_sysbios_family_arm_m3_Hwi_enable();
}

/* restore__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_restore__E( xdc_UInt key )
{
    ti_sysbios_family_arm_m3_Hwi_restore(key);
}

/* switchFromBootStack__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_switchFromBootStack__E( void )
{
    ti_sysbios_family_arm_m3_Hwi_switchFromBootStack();
}

/* post__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_post__E( xdc_UInt intNum )
{
    ti_sysbios_family_arm_m3_Hwi_post(intNum);
}

/* getTaskSP__E */
xdc_Char *ti_sysbios_hal_Hwi_HwiProxy_getTaskSP__E( void )
{
    return ti_sysbios_family_arm_m3_Hwi_getTaskSP();
}

/* disableInterrupt__E */
xdc_UInt ti_sysbios_hal_Hwi_HwiProxy_disableInterrupt__E( xdc_UInt intNum )
{
    return ti_sysbios_family_arm_m3_Hwi_disableInterrupt(intNum);
}

/* enableInterrupt__E */
xdc_UInt ti_sysbios_hal_Hwi_HwiProxy_enableInterrupt__E( xdc_UInt intNum )
{
    return ti_sysbios_family_arm_m3_Hwi_enableInterrupt(intNum);
}

/* restoreInterrupt__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_restoreInterrupt__E( xdc_UInt intNum, xdc_UInt key )
{
    ti_sysbios_family_arm_m3_Hwi_restoreInterrupt(intNum, key);
}

/* clearInterrupt__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_clearInterrupt__E( xdc_UInt intNum )
{
    ti_sysbios_family_arm_m3_Hwi_clearInterrupt(intNum);
}

/* getFunc__E */
ti_sysbios_interfaces_IHwi_FuncPtr ti_sysbios_hal_Hwi_HwiProxy_getFunc__E( ti_sysbios_hal_Hwi_HwiProxy_Handle __inst, xdc_UArg *arg )
{
    return ti_sysbios_family_arm_m3_Hwi_getFunc((ti_sysbios_family_arm_m3_Hwi_Handle)__inst, arg);
}

/* setFunc__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_setFunc__E( ti_sysbios_hal_Hwi_HwiProxy_Handle __inst, ti_sysbios_interfaces_IHwi_FuncPtr fxn, xdc_UArg arg )
{
    ti_sysbios_family_arm_m3_Hwi_setFunc((ti_sysbios_family_arm_m3_Hwi_Handle)__inst, fxn, arg);
}

/* getHookContext__E */
xdc_Ptr ti_sysbios_hal_Hwi_HwiProxy_getHookContext__E( ti_sysbios_hal_Hwi_HwiProxy_Handle __inst, xdc_Int id )
{
    return ti_sysbios_family_arm_m3_Hwi_getHookContext((ti_sysbios_family_arm_m3_Hwi_Handle)__inst, id);
}

/* setHookContext__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_setHookContext__E( ti_sysbios_hal_Hwi_HwiProxy_Handle __inst, xdc_Int id, xdc_Ptr hookContext )
{
    ti_sysbios_family_arm_m3_Hwi_setHookContext((ti_sysbios_family_arm_m3_Hwi_Handle)__inst, id, hookContext);
}

/* getIrp__E */
ti_sysbios_interfaces_IHwi_Irp ti_sysbios_hal_Hwi_HwiProxy_getIrp__E( ti_sysbios_hal_Hwi_HwiProxy_Handle __inst )
{
    return ti_sysbios_family_arm_m3_Hwi_getIrp((ti_sysbios_family_arm_m3_Hwi_Handle)__inst);
}


/*
 * ======== ti.sysbios.hal.unicache.Cache_Module_GateProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.family.arm.ducati.GateDualCore */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_hal_unicache_Cache_Module_GateProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_arm_ducati_GateDualCore_Module__startupDone__S();
}

/* Object__create__S */
xdc_Ptr ti_sysbios_hal_unicache_Cache_Module_GateProxy_Object__create__S (
    xdc_Ptr __obj, 
    xdc_SizeT __osz,
    const xdc_Ptr __aa,
    const ti_sysbios_hal_unicache_Cache_Module_GateProxy___ParamsPtr __paramsPtr,
    xdc_SizeT __psz,
    xdc_runtime_Error_Block *__eb)
{
    return ti_sysbios_family_arm_ducati_GateDualCore_Object__create__S(__obj, __osz, __aa, (const ti_sysbios_family_arm_ducati_GateDualCore___ParamsPtr)__paramsPtr, sizeof(xdc_runtime_IGateProvider_Params), __eb);
}

/* create */
ti_sysbios_hal_unicache_Cache_Module_GateProxy_Handle ti_sysbios_hal_unicache_Cache_Module_GateProxy_create( const ti_sysbios_hal_unicache_Cache_Module_GateProxy_Params *__prms, xdc_runtime_Error_Block *__eb )
{
    return (ti_sysbios_hal_unicache_Cache_Module_GateProxy_Handle)ti_sysbios_hal_unicache_Cache_Module_GateProxy_Object__create__S(0, 0, 0, (const xdc_UChar*)__prms, sizeof(ti_sysbios_hal_unicache_Cache_Module_GateProxy_Params), __eb);
}

/* Object__delete__S */
void ti_sysbios_hal_unicache_Cache_Module_GateProxy_Object__delete__S( xdc_Ptr instp ) 
{
    ti_sysbios_family_arm_ducati_GateDualCore_Object__delete__S(instp);
}

/* delete */
void ti_sysbios_hal_unicache_Cache_Module_GateProxy_delete(ti_sysbios_hal_unicache_Cache_Module_GateProxy_Handle *instp)
{
    ti_sysbios_hal_unicache_Cache_Module_GateProxy_Object__delete__S(instp);
}

/* Params__init__S */
void ti_sysbios_hal_unicache_Cache_Module_GateProxy_Params__init__S( xdc_Ptr dst, const void *src, xdc_SizeT psz, xdc_SizeT isz )
{
    ti_sysbios_family_arm_ducati_GateDualCore_Params__init__S(dst, src, psz, isz);
}

/* Handle__label__S */
xdc_runtime_Types_Label *ti_sysbios_hal_unicache_Cache_Module_GateProxy_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab)
{
    return ti_sysbios_family_arm_ducati_GateDualCore_Handle__label__S(obj, lab);
}

/* query__E */
xdc_Bool ti_sysbios_hal_unicache_Cache_Module_GateProxy_query__E( xdc_Int qual )
{
    return ti_sysbios_family_arm_ducati_GateDualCore_query(qual);
}

/* enter__E */
xdc_IArg ti_sysbios_hal_unicache_Cache_Module_GateProxy_enter__E( ti_sysbios_hal_unicache_Cache_Module_GateProxy_Handle __inst )
{
    return ti_sysbios_family_arm_ducati_GateDualCore_enter((ti_sysbios_family_arm_ducati_GateDualCore_Handle)__inst);
}

/* leave__E */
xdc_Void ti_sysbios_hal_unicache_Cache_Module_GateProxy_leave__E( ti_sysbios_hal_unicache_Cache_Module_GateProxy_Handle __inst, xdc_IArg key )
{
    ti_sysbios_family_arm_ducati_GateDualCore_leave((ti_sysbios_family_arm_ducati_GateDualCore_Handle)__inst, key);
}


/*
 * ======== ti.sysbios.heaps.HeapMem_Module_GateProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.gates.GateMutex */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_gates_GateMutex_Module__startupDone__S();
}

/* Object__create__S */
xdc_Ptr ti_sysbios_heaps_HeapMem_Module_GateProxy_Object__create__S (
    xdc_Ptr __obj, 
    xdc_SizeT __osz,
    const xdc_Ptr __aa,
    const ti_sysbios_heaps_HeapMem_Module_GateProxy___ParamsPtr __paramsPtr,
    xdc_SizeT __psz,
    xdc_runtime_Error_Block *__eb)
{
    return ti_sysbios_gates_GateMutex_Object__create__S(__obj, __osz, __aa, (const ti_sysbios_gates_GateMutex___ParamsPtr)__paramsPtr, sizeof(xdc_runtime_IGateProvider_Params), __eb);
}

/* create */
ti_sysbios_heaps_HeapMem_Module_GateProxy_Handle ti_sysbios_heaps_HeapMem_Module_GateProxy_create( const ti_sysbios_heaps_HeapMem_Module_GateProxy_Params *__prms, xdc_runtime_Error_Block *__eb )
{
    return (ti_sysbios_heaps_HeapMem_Module_GateProxy_Handle)ti_sysbios_heaps_HeapMem_Module_GateProxy_Object__create__S(0, 0, 0, (const xdc_UChar*)__prms, sizeof(ti_sysbios_heaps_HeapMem_Module_GateProxy_Params), __eb);
}

/* Object__delete__S */
void ti_sysbios_heaps_HeapMem_Module_GateProxy_Object__delete__S( xdc_Ptr instp ) 
{
    ti_sysbios_gates_GateMutex_Object__delete__S(instp);
}

/* delete */
void ti_sysbios_heaps_HeapMem_Module_GateProxy_delete(ti_sysbios_heaps_HeapMem_Module_GateProxy_Handle *instp)
{
    ti_sysbios_heaps_HeapMem_Module_GateProxy_Object__delete__S(instp);
}

/* Params__init__S */
void ti_sysbios_heaps_HeapMem_Module_GateProxy_Params__init__S( xdc_Ptr dst, const void *src, xdc_SizeT psz, xdc_SizeT isz )
{
    ti_sysbios_gates_GateMutex_Params__init__S(dst, src, psz, isz);
}

/* Handle__label__S */
xdc_runtime_Types_Label *ti_sysbios_heaps_HeapMem_Module_GateProxy_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab)
{
    return ti_sysbios_gates_GateMutex_Handle__label__S(obj, lab);
}

/* query__E */
xdc_Bool ti_sysbios_heaps_HeapMem_Module_GateProxy_query__E( xdc_Int qual )
{
    return ti_sysbios_gates_GateMutex_query(qual);
}

/* enter__E */
xdc_IArg ti_sysbios_heaps_HeapMem_Module_GateProxy_enter__E( ti_sysbios_heaps_HeapMem_Module_GateProxy_Handle __inst )
{
    return ti_sysbios_gates_GateMutex_enter((ti_sysbios_gates_GateMutex_Handle)__inst);
}

/* leave__E */
xdc_Void ti_sysbios_heaps_HeapMem_Module_GateProxy_leave__E( ti_sysbios_heaps_HeapMem_Module_GateProxy_Handle __inst, xdc_IArg key )
{
    ti_sysbios_gates_GateMutex_leave((ti_sysbios_gates_GateMutex_Handle)__inst, key);
}


/*
 * ======== ti.sysbios.knl.Clock_TimerProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.family.arm.ducati.Timer */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Clock_TimerProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_arm_ducati_Timer_Module__startupDone__S();
}

/* Object__create__S */
xdc_Ptr ti_sysbios_knl_Clock_TimerProxy_Object__create__S (
    xdc_Ptr __obj, 
    xdc_SizeT __osz,
    const xdc_Ptr __aa,
    const ti_sysbios_knl_Clock_TimerProxy___ParamsPtr __paramsPtr,
    xdc_SizeT __psz,
    xdc_runtime_Error_Block *__eb)
{
    return ti_sysbios_family_arm_ducati_Timer_Object__create__S(__obj, __osz, __aa, (const ti_sysbios_family_arm_ducati_Timer___ParamsPtr)__paramsPtr, sizeof(ti_sysbios_interfaces_ITimer_Params), __eb);
}

/* create */
ti_sysbios_knl_Clock_TimerProxy_Handle ti_sysbios_knl_Clock_TimerProxy_create( xdc_Int id, ti_sysbios_interfaces_ITimer_FuncPtr tickFxn, const ti_sysbios_knl_Clock_TimerProxy_Params *__prms, xdc_runtime_Error_Block *__eb )
{
    ti_sysbios_knl_Clock_TimerProxy_Args__create __args;
    __args.id = id;
    __args.tickFxn = tickFxn;
    return (ti_sysbios_knl_Clock_TimerProxy_Handle)ti_sysbios_knl_Clock_TimerProxy_Object__create__S(0, 0, &__args, (const xdc_UChar*)__prms, sizeof(ti_sysbios_knl_Clock_TimerProxy_Params), __eb);
}

/* Object__delete__S */
void ti_sysbios_knl_Clock_TimerProxy_Object__delete__S( xdc_Ptr instp ) 
{
    ti_sysbios_family_arm_ducati_Timer_Object__delete__S(instp);
}

/* delete */
void ti_sysbios_knl_Clock_TimerProxy_delete(ti_sysbios_knl_Clock_TimerProxy_Handle *instp)
{
    ti_sysbios_knl_Clock_TimerProxy_Object__delete__S(instp);
}

/* Params__init__S */
void ti_sysbios_knl_Clock_TimerProxy_Params__init__S( xdc_Ptr dst, const void *src, xdc_SizeT psz, xdc_SizeT isz )
{
    ti_sysbios_family_arm_ducati_Timer_Params__init__S(dst, src, psz, isz);
}

/* Handle__label__S */
xdc_runtime_Types_Label *ti_sysbios_knl_Clock_TimerProxy_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab)
{
    return ti_sysbios_family_arm_ducati_Timer_Handle__label__S(obj, lab);
}

/* getNumTimers__E */
xdc_UInt ti_sysbios_knl_Clock_TimerProxy_getNumTimers__E( void )
{
    return ti_sysbios_family_arm_ducati_Timer_getNumTimers();
}

/* getStatus__E */
ti_sysbios_interfaces_ITimer_Status ti_sysbios_knl_Clock_TimerProxy_getStatus__E( xdc_UInt id )
{
    return ti_sysbios_family_arm_ducati_Timer_getStatus(id);
}

/* startup__E */
xdc_Void ti_sysbios_knl_Clock_TimerProxy_startup__E( void )
{
    ti_sysbios_family_arm_ducati_Timer_startup();
}

/* getMaxTicks__E */
xdc_UInt32 ti_sysbios_knl_Clock_TimerProxy_getMaxTicks__E( ti_sysbios_knl_Clock_TimerProxy_Handle __inst )
{
    return ti_sysbios_family_arm_ducati_Timer_getMaxTicks((ti_sysbios_family_arm_ducati_Timer_Handle)__inst);
}

/* setNextTick__E */
xdc_Void ti_sysbios_knl_Clock_TimerProxy_setNextTick__E( ti_sysbios_knl_Clock_TimerProxy_Handle __inst, xdc_UInt32 ticks )
{
    ti_sysbios_family_arm_ducati_Timer_setNextTick((ti_sysbios_family_arm_ducati_Timer_Handle)__inst, ticks);
}

/* start__E */
xdc_Void ti_sysbios_knl_Clock_TimerProxy_start__E( ti_sysbios_knl_Clock_TimerProxy_Handle __inst )
{
    ti_sysbios_family_arm_ducati_Timer_start((ti_sysbios_family_arm_ducati_Timer_Handle)__inst);
}

/* stop__E */
xdc_Void ti_sysbios_knl_Clock_TimerProxy_stop__E( ti_sysbios_knl_Clock_TimerProxy_Handle __inst )
{
    ti_sysbios_family_arm_ducati_Timer_stop((ti_sysbios_family_arm_ducati_Timer_Handle)__inst);
}

/* setPeriod__E */
xdc_Void ti_sysbios_knl_Clock_TimerProxy_setPeriod__E( ti_sysbios_knl_Clock_TimerProxy_Handle __inst, xdc_UInt32 period )
{
    ti_sysbios_family_arm_ducati_Timer_setPeriod((ti_sysbios_family_arm_ducati_Timer_Handle)__inst, period);
}

/* setPeriodMicroSecs__E */
xdc_Bool ti_sysbios_knl_Clock_TimerProxy_setPeriodMicroSecs__E( ti_sysbios_knl_Clock_TimerProxy_Handle __inst, xdc_UInt32 microsecs )
{
    return ti_sysbios_family_arm_ducati_Timer_setPeriodMicroSecs((ti_sysbios_family_arm_ducati_Timer_Handle)__inst, microsecs);
}

/* getPeriod__E */
xdc_UInt32 ti_sysbios_knl_Clock_TimerProxy_getPeriod__E( ti_sysbios_knl_Clock_TimerProxy_Handle __inst )
{
    return ti_sysbios_family_arm_ducati_Timer_getPeriod((ti_sysbios_family_arm_ducati_Timer_Handle)__inst);
}

/* getCount__E */
xdc_UInt32 ti_sysbios_knl_Clock_TimerProxy_getCount__E( ti_sysbios_knl_Clock_TimerProxy_Handle __inst )
{
    return ti_sysbios_family_arm_ducati_Timer_getCount((ti_sysbios_family_arm_ducati_Timer_Handle)__inst);
}

/* getFreq__E */
xdc_Void ti_sysbios_knl_Clock_TimerProxy_getFreq__E( ti_sysbios_knl_Clock_TimerProxy_Handle __inst, xdc_runtime_Types_FreqHz *freq )
{
    ti_sysbios_family_arm_ducati_Timer_getFreq((ti_sysbios_family_arm_ducati_Timer_Handle)__inst, freq);
}

/* getFunc__E */
ti_sysbios_interfaces_ITimer_FuncPtr ti_sysbios_knl_Clock_TimerProxy_getFunc__E( ti_sysbios_knl_Clock_TimerProxy_Handle __inst, xdc_UArg *arg )
{
    return ti_sysbios_family_arm_ducati_Timer_getFunc((ti_sysbios_family_arm_ducati_Timer_Handle)__inst, arg);
}

/* setFunc__E */
xdc_Void ti_sysbios_knl_Clock_TimerProxy_setFunc__E( ti_sysbios_knl_Clock_TimerProxy_Handle __inst, ti_sysbios_interfaces_ITimer_FuncPtr fxn, xdc_UArg arg )
{
    ti_sysbios_family_arm_ducati_Timer_setFunc((ti_sysbios_family_arm_ducati_Timer_Handle)__inst, fxn, arg);
}

/* trigger__E */
xdc_Void ti_sysbios_knl_Clock_TimerProxy_trigger__E( ti_sysbios_knl_Clock_TimerProxy_Handle __inst, xdc_UInt32 cycles )
{
    ti_sysbios_family_arm_ducati_Timer_trigger((ti_sysbios_family_arm_ducati_Timer_Handle)__inst, cycles);
}

/* getExpiredCounts__E */
xdc_UInt32 ti_sysbios_knl_Clock_TimerProxy_getExpiredCounts__E( ti_sysbios_knl_Clock_TimerProxy_Handle __inst )
{
    return ti_sysbios_family_arm_ducati_Timer_getExpiredCounts((ti_sysbios_family_arm_ducati_Timer_Handle)__inst);
}

/* getExpiredTicks__E */
xdc_UInt32 ti_sysbios_knl_Clock_TimerProxy_getExpiredTicks__E( ti_sysbios_knl_Clock_TimerProxy_Handle __inst, xdc_UInt32 tickPeriod )
{
    return ti_sysbios_family_arm_ducati_Timer_getExpiredTicks((ti_sysbios_family_arm_ducati_Timer_Handle)__inst, tickPeriod);
}

/* getCurrentTick__E */
xdc_UInt32 ti_sysbios_knl_Clock_TimerProxy_getCurrentTick__E( ti_sysbios_knl_Clock_TimerProxy_Handle __inst, xdc_Bool save )
{
    return ti_sysbios_family_arm_ducati_Timer_getCurrentTick((ti_sysbios_family_arm_ducati_Timer_Handle)__inst, save);
}


/*
 * ======== ti.sysbios.knl.Intrinsics_SupportProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.family.arm.m3.IntrinsicsSupport */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Intrinsics_SupportProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__startupDone__S();
}

/* maxbit__E */
xdc_UInt ti_sysbios_knl_Intrinsics_SupportProxy_maxbit__E( xdc_UInt bits )
{
    return ti_sysbios_family_arm_m3_IntrinsicsSupport_maxbit(bits);
}


/*
 * ======== ti.sysbios.knl.Task_SupportProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.family.arm.m3.TaskSupport */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Task_SupportProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_arm_m3_TaskSupport_Module__startupDone__S();
}

/* start__E */
xdc_Ptr ti_sysbios_knl_Task_SupportProxy_start__E( xdc_Ptr curTask, ti_sysbios_interfaces_ITaskSupport_FuncPtr enter, ti_sysbios_interfaces_ITaskSupport_FuncPtr exit, xdc_runtime_Error_Block *eb )
{
    return ti_sysbios_family_arm_m3_TaskSupport_start(curTask, enter, exit, eb);
}

/* swap__E */
xdc_Void ti_sysbios_knl_Task_SupportProxy_swap__E( xdc_Ptr *oldtskContext, xdc_Ptr *newtskContext )
{
    ti_sysbios_family_arm_m3_TaskSupport_swap(oldtskContext, newtskContext);
}

/* checkStack__E */
xdc_Bool ti_sysbios_knl_Task_SupportProxy_checkStack__E( xdc_Char *stack, xdc_SizeT size )
{
    return ti_sysbios_family_arm_m3_TaskSupport_checkStack(stack, size);
}

/* stackUsed__E */
xdc_SizeT ti_sysbios_knl_Task_SupportProxy_stackUsed__E( xdc_Char *stack, xdc_SizeT size )
{
    return ti_sysbios_family_arm_m3_TaskSupport_stackUsed(stack, size);
}

/* getStackAlignment__E */
xdc_UInt ti_sysbios_knl_Task_SupportProxy_getStackAlignment__E( void )
{
    return ti_sysbios_family_arm_m3_TaskSupport_getStackAlignment();
}

/* getDefaultStackSize__E */
xdc_SizeT ti_sysbios_knl_Task_SupportProxy_getDefaultStackSize__E( void )
{
    return ti_sysbios_family_arm_m3_TaskSupport_getDefaultStackSize();
}

/* getCheckValueAddr__E */
xdc_Ptr ti_sysbios_knl_Task_SupportProxy_getCheckValueAddr__E( xdc_Ptr curTask )
{
    return ti_sysbios_family_arm_m3_TaskSupport_getCheckValueAddr(curTask);
}


/*
 * ======== xdc.runtime.Main_Module_GateProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.gates.GateHwi */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Main_Module_GateProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_gates_GateHwi_Module__startupDone__S();
}

/* Object__create__S */
xdc_Ptr xdc_runtime_Main_Module_GateProxy_Object__create__S (
    xdc_Ptr __obj, 
    xdc_SizeT __osz,
    const xdc_Ptr __aa,
    const xdc_runtime_Main_Module_GateProxy___ParamsPtr __paramsPtr,
    xdc_SizeT __psz,
    xdc_runtime_Error_Block *__eb)
{
    return ti_sysbios_gates_GateHwi_Object__create__S(__obj, __osz, __aa, (const ti_sysbios_gates_GateHwi___ParamsPtr)__paramsPtr, sizeof(xdc_runtime_IGateProvider_Params), __eb);
}

/* create */
xdc_runtime_Main_Module_GateProxy_Handle xdc_runtime_Main_Module_GateProxy_create( const xdc_runtime_Main_Module_GateProxy_Params *__prms, xdc_runtime_Error_Block *__eb )
{
    return (xdc_runtime_Main_Module_GateProxy_Handle)xdc_runtime_Main_Module_GateProxy_Object__create__S(0, 0, 0, (const xdc_UChar*)__prms, sizeof(xdc_runtime_Main_Module_GateProxy_Params), __eb);
}

/* Object__delete__S */
void xdc_runtime_Main_Module_GateProxy_Object__delete__S( xdc_Ptr instp ) 
{
    ti_sysbios_gates_GateHwi_Object__delete__S(instp);
}

/* delete */
void xdc_runtime_Main_Module_GateProxy_delete(xdc_runtime_Main_Module_GateProxy_Handle *instp)
{
    xdc_runtime_Main_Module_GateProxy_Object__delete__S(instp);
}

/* Params__init__S */
void xdc_runtime_Main_Module_GateProxy_Params__init__S( xdc_Ptr dst, const void *src, xdc_SizeT psz, xdc_SizeT isz )
{
    ti_sysbios_gates_GateHwi_Params__init__S(dst, src, psz, isz);
}

/* Handle__label__S */
xdc_runtime_Types_Label *xdc_runtime_Main_Module_GateProxy_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab)
{
    return ti_sysbios_gates_GateHwi_Handle__label__S(obj, lab);
}

/* query__E */
xdc_Bool xdc_runtime_Main_Module_GateProxy_query__E( xdc_Int qual )
{
    return ti_sysbios_gates_GateHwi_query(qual);
}

/* enter__E */
xdc_IArg xdc_runtime_Main_Module_GateProxy_enter__E( xdc_runtime_Main_Module_GateProxy_Handle __inst )
{
    return ti_sysbios_gates_GateHwi_enter((ti_sysbios_gates_GateHwi_Handle)__inst);
}

/* leave__E */
xdc_Void xdc_runtime_Main_Module_GateProxy_leave__E( xdc_runtime_Main_Module_GateProxy_Handle __inst, xdc_IArg key )
{
    ti_sysbios_gates_GateHwi_leave((ti_sysbios_gates_GateHwi_Handle)__inst, key);
}


/*
 * ======== xdc.runtime.Memory_HeapProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.heaps.HeapMem */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Memory_HeapProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_heaps_HeapMem_Module__startupDone__S();
}

/* Object__create__S */
xdc_Ptr xdc_runtime_Memory_HeapProxy_Object__create__S (
    xdc_Ptr __obj, 
    xdc_SizeT __osz,
    const xdc_Ptr __aa,
    const xdc_runtime_Memory_HeapProxy___ParamsPtr __paramsPtr,
    xdc_SizeT __psz,
    xdc_runtime_Error_Block *__eb)
{
    return ti_sysbios_heaps_HeapMem_Object__create__S(__obj, __osz, __aa, (const ti_sysbios_heaps_HeapMem___ParamsPtr)__paramsPtr, sizeof(xdc_runtime_IHeap_Params), __eb);
}

/* create */
xdc_runtime_Memory_HeapProxy_Handle xdc_runtime_Memory_HeapProxy_create( const xdc_runtime_Memory_HeapProxy_Params *__prms, xdc_runtime_Error_Block *__eb )
{
    return (xdc_runtime_Memory_HeapProxy_Handle)xdc_runtime_Memory_HeapProxy_Object__create__S(0, 0, 0, (const xdc_UChar*)__prms, sizeof(xdc_runtime_Memory_HeapProxy_Params), __eb);
}

/* Object__delete__S */
void xdc_runtime_Memory_HeapProxy_Object__delete__S( xdc_Ptr instp ) 
{
    ti_sysbios_heaps_HeapMem_Object__delete__S(instp);
}

/* delete */
void xdc_runtime_Memory_HeapProxy_delete(xdc_runtime_Memory_HeapProxy_Handle *instp)
{
    xdc_runtime_Memory_HeapProxy_Object__delete__S(instp);
}

/* Params__init__S */
void xdc_runtime_Memory_HeapProxy_Params__init__S( xdc_Ptr dst, const void *src, xdc_SizeT psz, xdc_SizeT isz )
{
    ti_sysbios_heaps_HeapMem_Params__init__S(dst, src, psz, isz);
}

/* Handle__label__S */
xdc_runtime_Types_Label *xdc_runtime_Memory_HeapProxy_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab)
{
    return ti_sysbios_heaps_HeapMem_Handle__label__S(obj, lab);
}

/* alloc__E */
xdc_Ptr xdc_runtime_Memory_HeapProxy_alloc__E( xdc_runtime_Memory_HeapProxy_Handle __inst, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block *eb )
{
    return xdc_runtime_IHeap_alloc((xdc_runtime_IHeap_Handle)__inst, size, align, eb);
}

/* free__E */
xdc_Void xdc_runtime_Memory_HeapProxy_free__E( xdc_runtime_Memory_HeapProxy_Handle __inst, xdc_Ptr block, xdc_SizeT size )
{
    xdc_runtime_IHeap_free((xdc_runtime_IHeap_Handle)__inst, block, size);
}

/* isBlocking__E */
xdc_Bool xdc_runtime_Memory_HeapProxy_isBlocking__E( xdc_runtime_Memory_HeapProxy_Handle __inst )
{
    return xdc_runtime_IHeap_isBlocking((xdc_runtime_IHeap_Handle)__inst);
}

/* getStats__E */
xdc_Void xdc_runtime_Memory_HeapProxy_getStats__E( xdc_runtime_Memory_HeapProxy_Handle __inst, xdc_runtime_Memory_Stats *stats )
{
    xdc_runtime_IHeap_getStats((xdc_runtime_IHeap_Handle)__inst, stats);
}


/*
 * ======== xdc.runtime.System_Module_GateProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.gates.GateHwi */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_System_Module_GateProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_gates_GateHwi_Module__startupDone__S();
}

/* Object__create__S */
xdc_Ptr xdc_runtime_System_Module_GateProxy_Object__create__S (
    xdc_Ptr __obj, 
    xdc_SizeT __osz,
    const xdc_Ptr __aa,
    const xdc_runtime_System_Module_GateProxy___ParamsPtr __paramsPtr,
    xdc_SizeT __psz,
    xdc_runtime_Error_Block *__eb)
{
    return ti_sysbios_gates_GateHwi_Object__create__S(__obj, __osz, __aa, (const ti_sysbios_gates_GateHwi___ParamsPtr)__paramsPtr, sizeof(xdc_runtime_IGateProvider_Params), __eb);
}

/* create */
xdc_runtime_System_Module_GateProxy_Handle xdc_runtime_System_Module_GateProxy_create( const xdc_runtime_System_Module_GateProxy_Params *__prms, xdc_runtime_Error_Block *__eb )
{
    return (xdc_runtime_System_Module_GateProxy_Handle)xdc_runtime_System_Module_GateProxy_Object__create__S(0, 0, 0, (const xdc_UChar*)__prms, sizeof(xdc_runtime_System_Module_GateProxy_Params), __eb);
}

/* Object__delete__S */
void xdc_runtime_System_Module_GateProxy_Object__delete__S( xdc_Ptr instp ) 
{
    ti_sysbios_gates_GateHwi_Object__delete__S(instp);
}

/* delete */
void xdc_runtime_System_Module_GateProxy_delete(xdc_runtime_System_Module_GateProxy_Handle *instp)
{
    xdc_runtime_System_Module_GateProxy_Object__delete__S(instp);
}

/* Params__init__S */
void xdc_runtime_System_Module_GateProxy_Params__init__S( xdc_Ptr dst, const void *src, xdc_SizeT psz, xdc_SizeT isz )
{
    ti_sysbios_gates_GateHwi_Params__init__S(dst, src, psz, isz);
}

/* Handle__label__S */
xdc_runtime_Types_Label *xdc_runtime_System_Module_GateProxy_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab)
{
    return ti_sysbios_gates_GateHwi_Handle__label__S(obj, lab);
}

/* query__E */
xdc_Bool xdc_runtime_System_Module_GateProxy_query__E( xdc_Int qual )
{
    return ti_sysbios_gates_GateHwi_query(qual);
}

/* enter__E */
xdc_IArg xdc_runtime_System_Module_GateProxy_enter__E( xdc_runtime_System_Module_GateProxy_Handle __inst )
{
    return ti_sysbios_gates_GateHwi_enter((ti_sysbios_gates_GateHwi_Handle)__inst);
}

/* leave__E */
xdc_Void xdc_runtime_System_Module_GateProxy_leave__E( xdc_runtime_System_Module_GateProxy_Handle __inst, xdc_IArg key )
{
    ti_sysbios_gates_GateHwi_leave((ti_sysbios_gates_GateHwi_Handle)__inst, key);
}


/*
 * ======== xdc.runtime.System_SupportProxy PROXY BODY ========
 */

/* DELEGATES TO xdc.runtime.SysMin */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_System_SupportProxy_Module__startupDone__S( void ) 
{
    return xdc_runtime_SysMin_Module__startupDone__S();
}

/* abort__E */
xdc_Void xdc_runtime_System_SupportProxy_abort__E( xdc_CString str )
{
    xdc_runtime_SysMin_abort(str);
}

/* exit__E */
xdc_Void xdc_runtime_System_SupportProxy_exit__E( xdc_Int stat )
{
    xdc_runtime_SysMin_exit(stat);
}

/* flush__E */
xdc_Void xdc_runtime_System_SupportProxy_flush__E( void )
{
    xdc_runtime_SysMin_flush();
}

/* putch__E */
xdc_Void xdc_runtime_System_SupportProxy_putch__E( xdc_Char ch )
{
    xdc_runtime_SysMin_putch(ch);
}

/* ready__E */
xdc_Bool xdc_runtime_System_SupportProxy_ready__E( void )
{
    return xdc_runtime_SysMin_ready();
}


/*
 * ======== ti.sysbios.family.arm.ducati.GateDualCore OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_family_arm_ducati_GateDualCore_Object2__ s0; char c; } ti_sysbios_family_arm_ducati_GateDualCore___S1;
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_GateDualCore_Object__DESC__C, ".const:ti_sysbios_family_arm_ducati_GateDualCore_Object__DESC__C");
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_family_arm_ducati_GateDualCore_Object__DESC__C = {
    (xdc_CPtr)&ti_sysbios_family_arm_ducati_GateDualCore_Module__FXNS__C, /* fxnTab */
    &ti_sysbios_family_arm_ducati_GateDualCore_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_family_arm_ducati_GateDualCore___S1) - sizeof(ti_sysbios_family_arm_ducati_GateDualCore_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_family_arm_ducati_GateDualCore_Object2__), /* objSize */
    (xdc_CPtr)&ti_sysbios_family_arm_ducati_GateDualCore_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_family_arm_ducati_GateDualCore_Params), /* prmsSize */
};


/*
 * ======== ti.sysbios.family.arm.ducati.Timer OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_family_arm_ducati_Timer_Object2__ s0; char c; } ti_sysbios_family_arm_ducati_Timer___S1;
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Object__DESC__C, ".const:ti_sysbios_family_arm_ducati_Timer_Object__DESC__C");
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_family_arm_ducati_Timer_Object__DESC__C = {
    (xdc_CPtr)0, /* fxnTab */
    &ti_sysbios_family_arm_ducati_Timer_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_family_arm_ducati_Timer___S1) - sizeof(ti_sysbios_family_arm_ducati_Timer_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_family_arm_ducati_Timer_Object2__), /* objSize */
    (xdc_CPtr)&ti_sysbios_family_arm_ducati_Timer_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_family_arm_ducati_Timer_Params), /* prmsSize */
};


/*
 * ======== ti.sysbios.family.arm.m3.Hwi OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_family_arm_m3_Hwi_Object2__ s0; char c; } ti_sysbios_family_arm_m3_Hwi___S1;
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Object__DESC__C, ".const:ti_sysbios_family_arm_m3_Hwi_Object__DESC__C");
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_family_arm_m3_Hwi_Object__DESC__C = {
    (xdc_CPtr)0, /* fxnTab */
    &ti_sysbios_family_arm_m3_Hwi_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_family_arm_m3_Hwi___S1) - sizeof(ti_sysbios_family_arm_m3_Hwi_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_family_arm_m3_Hwi_Object2__), /* objSize */
    (xdc_CPtr)&ti_sysbios_family_arm_m3_Hwi_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_family_arm_m3_Hwi_Params), /* prmsSize */
};


/*
 * ======== ti.sysbios.gates.GateHwi OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_gates_GateHwi_Object2__ s0; char c; } ti_sysbios_gates_GateHwi___S1;
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Object__DESC__C, ".const:ti_sysbios_gates_GateHwi_Object__DESC__C");
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_gates_GateHwi_Object__DESC__C = {
    (xdc_CPtr)&ti_sysbios_gates_GateHwi_Module__FXNS__C, /* fxnTab */
    &ti_sysbios_gates_GateHwi_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_gates_GateHwi___S1) - sizeof(ti_sysbios_gates_GateHwi_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_gates_GateHwi_Object2__), /* objSize */
    (xdc_CPtr)&ti_sysbios_gates_GateHwi_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_gates_GateHwi_Params), /* prmsSize */
};


/*
 * ======== ti.sysbios.gates.GateMutex OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_gates_GateMutex_Object2__ s0; char c; } ti_sysbios_gates_GateMutex___S1;
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Object__DESC__C, ".const:ti_sysbios_gates_GateMutex_Object__DESC__C");
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_gates_GateMutex_Object__DESC__C = {
    (xdc_CPtr)&ti_sysbios_gates_GateMutex_Module__FXNS__C, /* fxnTab */
    &ti_sysbios_gates_GateMutex_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_gates_GateMutex___S1) - sizeof(ti_sysbios_gates_GateMutex_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_gates_GateMutex_Object2__), /* objSize */
    (xdc_CPtr)&ti_sysbios_gates_GateMutex_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_gates_GateMutex_Params), /* prmsSize */
};


/*
 * ======== ti.sysbios.hal.Hwi OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_hal_Hwi_Object2__ s0; char c; } ti_sysbios_hal_Hwi___S1;
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Object__DESC__C, ".const:ti_sysbios_hal_Hwi_Object__DESC__C");
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_hal_Hwi_Object__DESC__C = {
    (xdc_CPtr)0, /* fxnTab */
    &ti_sysbios_hal_Hwi_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_hal_Hwi___S1) - sizeof(ti_sysbios_hal_Hwi_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_hal_Hwi_Object2__), /* objSize */
    (xdc_CPtr)&ti_sysbios_hal_Hwi_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_hal_Hwi_Params), /* prmsSize */
};


/*
 * ======== ti.sysbios.heaps.HeapMem OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_heaps_HeapMem_Object2__ s0; char c; } ti_sysbios_heaps_HeapMem___S1;
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Object__DESC__C, ".const:ti_sysbios_heaps_HeapMem_Object__DESC__C");
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_heaps_HeapMem_Object__DESC__C = {
    (xdc_CPtr)&ti_sysbios_heaps_HeapMem_Module__FXNS__C, /* fxnTab */
    &ti_sysbios_heaps_HeapMem_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_heaps_HeapMem___S1) - sizeof(ti_sysbios_heaps_HeapMem_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_heaps_HeapMem_Object2__), /* objSize */
    (xdc_CPtr)&ti_sysbios_heaps_HeapMem_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_heaps_HeapMem_Params), /* prmsSize */
};


/*
 * ======== ti.sysbios.knl.Clock OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_knl_Clock_Object2__ s0; char c; } ti_sysbios_knl_Clock___S1;
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Object__DESC__C, ".const:ti_sysbios_knl_Clock_Object__DESC__C");
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Clock_Object__DESC__C = {
    (xdc_CPtr)-1, /* fxnTab */
    &ti_sysbios_knl_Clock_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_knl_Clock___S1) - sizeof(ti_sysbios_knl_Clock_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_knl_Clock_Object2__), /* objSize */
    (xdc_CPtr)&ti_sysbios_knl_Clock_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_knl_Clock_Params), /* prmsSize */
};


/*
 * ======== ti.sysbios.knl.Queue OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_knl_Queue_Object2__ s0; char c; } ti_sysbios_knl_Queue___S1;
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Object__DESC__C, ".const:ti_sysbios_knl_Queue_Object__DESC__C");
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Queue_Object__DESC__C = {
    (xdc_CPtr)-1, /* fxnTab */
    &ti_sysbios_knl_Queue_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_knl_Queue___S1) - sizeof(ti_sysbios_knl_Queue_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_knl_Queue_Object2__), /* objSize */
    (xdc_CPtr)&ti_sysbios_knl_Queue_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_knl_Queue_Params), /* prmsSize */
};


/*
 * ======== ti.sysbios.knl.Semaphore OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_knl_Semaphore_Object2__ s0; char c; } ti_sysbios_knl_Semaphore___S1;
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Object__DESC__C, ".const:ti_sysbios_knl_Semaphore_Object__DESC__C");
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Semaphore_Object__DESC__C = {
    (xdc_CPtr)-1, /* fxnTab */
    &ti_sysbios_knl_Semaphore_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_knl_Semaphore___S1) - sizeof(ti_sysbios_knl_Semaphore_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_knl_Semaphore_Object2__), /* objSize */
    (xdc_CPtr)&ti_sysbios_knl_Semaphore_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_knl_Semaphore_Params), /* prmsSize */
};


/*
 * ======== ti.sysbios.knl.Swi OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_knl_Swi_Object2__ s0; char c; } ti_sysbios_knl_Swi___S1;
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Object__DESC__C, ".const:ti_sysbios_knl_Swi_Object__DESC__C");
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Swi_Object__DESC__C = {
    (xdc_CPtr)-1, /* fxnTab */
    &ti_sysbios_knl_Swi_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_knl_Swi___S1) - sizeof(ti_sysbios_knl_Swi_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_knl_Swi_Object2__), /* objSize */
    (xdc_CPtr)&ti_sysbios_knl_Swi_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_knl_Swi_Params), /* prmsSize */
};


/*
 * ======== ti.sysbios.knl.Task OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_knl_Task_Object2__ s0; char c; } ti_sysbios_knl_Task___S1;
#pragma DATA_SECTION(ti_sysbios_knl_Task_Object__DESC__C, ".const:ti_sysbios_knl_Task_Object__DESC__C");
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Task_Object__DESC__C = {
    (xdc_CPtr)-1, /* fxnTab */
    &ti_sysbios_knl_Task_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_knl_Task___S1) - sizeof(ti_sysbios_knl_Task_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_knl_Task_Object2__), /* objSize */
    (xdc_CPtr)&ti_sysbios_knl_Task_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_knl_Task_Params), /* prmsSize */
};


/*
 * ======== xdc.runtime.IHeap VIRTUAL FUNCTIONS ========
 */

/* create */
xdc_runtime_IHeap_Handle xdc_runtime_IHeap_create( xdc_runtime_IHeap_Module __mod, const xdc_runtime_IHeap_Params *__prms, xdc_runtime_Error_Block *__eb )
{
    return (xdc_runtime_IHeap_Handle) __mod->__sysp->__create(0, 0, 0, (const xdc_UChar*)__prms, sizeof (xdc_runtime_IHeap_Params), __eb);
}

/* delete */
void xdc_runtime_IHeap_delete( xdc_runtime_IHeap_Handle *instp )
{
    (*instp)->__fxns->__sysp->__delete(instp);
}


/*
 * ======== xdc.runtime.IGateProvider VIRTUAL FUNCTIONS ========
 */

/* create */
xdc_runtime_IGateProvider_Handle xdc_runtime_IGateProvider_create( xdc_runtime_IGateProvider_Module __mod, const xdc_runtime_IGateProvider_Params *__prms, xdc_runtime_Error_Block *__eb )
{
    return (xdc_runtime_IGateProvider_Handle) __mod->__sysp->__create(0, 0, 0, (const xdc_UChar*)__prms, sizeof (xdc_runtime_IGateProvider_Params), __eb);
}

/* delete */
void xdc_runtime_IGateProvider_delete( xdc_runtime_IGateProvider_Handle *instp )
{
    (*instp)->__fxns->__sysp->__delete(instp);
}


/*
 * ======== ti.sysbios.BIOS SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_BIOS_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== ti.sysbios.BIOS_RtsGateProxy SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_BIOS_RtsGateProxy_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_BIOS_RtsGateProxy_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_BIOS_RtsGateProxy_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_BIOS_RtsGateProxy_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_BIOS_RtsGateProxy_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_BIOS_RtsGateProxy_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_BIOS_RtsGateProxy_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_BIOS_RtsGateProxy_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_BIOS_RtsGateProxy_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_BIOS_RtsGateProxy_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_BIOS_RtsGateProxy_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_BIOS_RtsGateProxy_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_BIOS_RtsGateProxy_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_BIOS_RtsGateProxy_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_BIOS_RtsGateProxy_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_BIOS_RtsGateProxy_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_BIOS_RtsGateProxy_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_BIOS_RtsGateProxy_Module_GateProxy_query

xdc_Bool ti_sysbios_BIOS_RtsGateProxy_Proxy__abstract__S( void )
{
    return 0;
}
xdc_Ptr ti_sysbios_BIOS_RtsGateProxy_Proxy__delegate__S( void )
{
    return (void *)&ti_sysbios_gates_GateMutex_Module__FXNS__C;
}



/*
 * ======== ti.sysbios.family.arm.ducati.CTM SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_arm_ducati_CTM_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== ti.sysbios.family.arm.ducati.Core SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_arm_ducati_Core_Module__startupDone__S( void )
{
    return ti_sysbios_family_arm_ducati_Core_Module__startupDone__F();
}



/*
 * ======== ti.sysbios.family.arm.ducati.GateDualCore SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_family_arm_ducati_GateDualCore_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_family_arm_ducati_GateDualCore_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_family_arm_ducati_GateDualCore_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_family_arm_ducati_GateDualCore_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_family_arm_ducati_GateDualCore_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_family_arm_ducati_GateDualCore_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_family_arm_ducati_GateDualCore_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_family_arm_ducati_GateDualCore_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_family_arm_ducati_GateDualCore_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_family_arm_ducati_GateDualCore_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_family_arm_ducati_GateDualCore_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_family_arm_ducati_GateDualCore_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_arm_ducati_GateDualCore_Module__startupDone__S( void )
{
    return ti_sysbios_family_arm_ducati_GateDualCore_Module__startupDone__F();
}

/* Handle__label__S */
xdc_runtime_Types_Label *ti_sysbios_family_arm_ducati_GateDualCore_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab) 
{
    lab->handle = obj;
    lab->modId = 32809;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_family_arm_ducati_GateDualCore_Params__init__S( xdc_Ptr prms, const void *src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_CPtr)(src ? src : &ti_sysbios_family_arm_ducati_GateDualCore_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_family_arm_ducati_GateDualCore_Object__get__S(xdc_Ptr oa, xdc_Int i)
{
    if (oa) {
        return ((ti_sysbios_family_arm_ducati_GateDualCore_Object__ *)oa) + i;
    }

    if (ti_sysbios_family_arm_ducati_GateDualCore_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_family_arm_ducati_GateDualCore_Object__ *)ti_sysbios_family_arm_ducati_GateDualCore_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_family_arm_ducati_GateDualCore_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_family_arm_ducati_GateDualCore_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_family_arm_ducati_GateDualCore_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_family_arm_ducati_GateDualCore_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_family_arm_ducati_GateDualCore_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_family_arm_ducati_GateDualCore_Object__create__S (
    xdc_Ptr __obj, 
    xdc_SizeT __osz,
    const xdc_Ptr __aa,
    const ti_sysbios_family_arm_ducati_GateDualCore___ParamsPtr __paramsPtr,
    xdc_SizeT __psz,
    xdc_runtime_Error_Block *__eb)
{
    ti_sysbios_family_arm_ducati_GateDualCore_Params __prms;
    ti_sysbios_family_arm_ducati_GateDualCore_Object *__newobj;
    int iStat;

    /* common instance initialization */
    __newobj = xdc_runtime_Core_createObject__I(&ti_sysbios_family_arm_ducati_GateDualCore_Object__DESC__C, __obj, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_family_arm_ducati_GateDualCore_Params), __eb);
    if (__newobj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    iStat = ti_sysbios_family_arm_ducati_GateDualCore_Instance_init__E(__newobj, &__prms, __eb);
    if (xdc_runtime_Error_check(__eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_arm_ducati_GateDualCore_Object__DESC__C, __newobj, NULL, iStat, (xdc_Bool)(__obj != NULL));
        return NULL;
    }

    return __newobj;
}

/* create */
ti_sysbios_family_arm_ducati_GateDualCore_Handle ti_sysbios_family_arm_ducati_GateDualCore_create( const ti_sysbios_family_arm_ducati_GateDualCore_Params *__paramsPtr, xdc_runtime_Error_Block *__eb )
{
    ti_sysbios_family_arm_ducati_GateDualCore_Params __prms;
    ti_sysbios_family_arm_ducati_GateDualCore_Object *__newobj;
    int iStat;

    /* common instance initialization */
    __newobj = xdc_runtime_Core_createObject__I(&ti_sysbios_family_arm_ducati_GateDualCore_Object__DESC__C, 0, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_family_arm_ducati_GateDualCore_Params), __eb);
    if (__newobj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    iStat = ti_sysbios_family_arm_ducati_GateDualCore_Instance_init__E(__newobj, &__prms, __eb);
    if (xdc_runtime_Error_check(__eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_arm_ducati_GateDualCore_Object__DESC__C, __newobj, NULL, iStat, 0);
        return NULL;
    }

    return __newobj;
}

/* construct */
void ti_sysbios_family_arm_ducati_GateDualCore_construct(ti_sysbios_family_arm_ducati_GateDualCore_Struct *__obj, const ti_sysbios_family_arm_ducati_GateDualCore_Params *__paramsPtr, xdc_runtime_Error_Block *__eb )
{
    ti_sysbios_family_arm_ducati_GateDualCore_Params __prms;
    int iStat;

    /* common instance initialization */
    xdc_runtime_Core_constructObject__I(&ti_sysbios_family_arm_ducati_GateDualCore_Object__DESC__C, __obj, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_family_arm_ducati_GateDualCore_Params), __eb);
    /* module-specific initialization */
    iStat = ti_sysbios_family_arm_ducati_GateDualCore_Instance_init__E((xdc_Ptr)__obj, &__prms, __eb);
    if (xdc_runtime_Error_check(__eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_arm_ducati_GateDualCore_Object__DESC__C, (xdc_Ptr)__obj, NULL, iStat, 1);
    }

}

/* Object__destruct__S */
xdc_Void ti_sysbios_family_arm_ducati_GateDualCore_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_arm_ducati_GateDualCore_Object__DESC__C, obj, NULL, 0, TRUE);
}

/* destruct */
void ti_sysbios_family_arm_ducati_GateDualCore_destruct(ti_sysbios_family_arm_ducati_GateDualCore_Struct *obj)
{
    ti_sysbios_family_arm_ducati_GateDualCore_Object__destruct__S(obj);
}

/* Object__delete__S */
xdc_Void ti_sysbios_family_arm_ducati_GateDualCore_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_arm_ducati_GateDualCore_Object__DESC__C, *((ti_sysbios_family_arm_ducati_GateDualCore_Object**)instp), NULL, 0, FALSE);
    *((ti_sysbios_family_arm_ducati_GateDualCore_Handle*)instp) = NULL;
}

/* delete */
void ti_sysbios_family_arm_ducati_GateDualCore_delete(ti_sysbios_family_arm_ducati_GateDualCore_Handle *instp)
{
    ti_sysbios_family_arm_ducati_GateDualCore_Object__delete__S(instp);
}


/*
 * ======== ti.sysbios.family.arm.ducati.Timer SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_family_arm_ducati_Timer_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_family_arm_ducati_Timer_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_family_arm_ducati_Timer_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_family_arm_ducati_Timer_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_family_arm_ducati_Timer_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_family_arm_ducati_Timer_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_family_arm_ducati_Timer_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_family_arm_ducati_Timer_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_family_arm_ducati_Timer_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_family_arm_ducati_Timer_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_family_arm_ducati_Timer_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_family_arm_ducati_Timer_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_family_arm_ducati_Timer_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_arm_ducati_Timer_Module__startupDone__S( void )
{
    return ti_sysbios_family_arm_ducati_Timer_Module__startupDone__F();
}

/* Handle__label__S */
xdc_runtime_Types_Label *ti_sysbios_family_arm_ducati_Timer_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab) 
{
    lab->handle = obj;
    lab->modId = 32810;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_family_arm_ducati_Timer_Params__init__S( xdc_Ptr prms, const void *src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_CPtr)(src ? src : &ti_sysbios_family_arm_ducati_Timer_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_family_arm_ducati_Timer_Object__get__S(xdc_Ptr oa, xdc_Int i)
{
    if (oa) {
        return ((ti_sysbios_family_arm_ducati_Timer_Object__ *)oa) + i;
    }

    if (ti_sysbios_family_arm_ducati_Timer_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_family_arm_ducati_Timer_Object__ *)ti_sysbios_family_arm_ducati_Timer_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_family_arm_ducati_Timer_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_family_arm_ducati_Timer_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_family_arm_ducati_Timer_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_family_arm_ducati_Timer_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_family_arm_ducati_Timer_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_family_arm_ducati_Timer_Object__create__S (
    xdc_Ptr __obj, 
    xdc_SizeT __osz,
    const xdc_Ptr __aa,
    const ti_sysbios_family_arm_ducati_Timer___ParamsPtr __paramsPtr,
    xdc_SizeT __psz,
    xdc_runtime_Error_Block *__eb)
{
    ti_sysbios_family_arm_ducati_Timer_Args__create *__args = __aa;
    ti_sysbios_family_arm_ducati_Timer_Params __prms;
    ti_sysbios_family_arm_ducati_Timer_Object *__newobj;
    int iStat;

    /* common instance initialization */
    __newobj = xdc_runtime_Core_createObject__I(&ti_sysbios_family_arm_ducati_Timer_Object__DESC__C, __obj, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_family_arm_ducati_Timer_Params), __eb);
    if (__newobj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    iStat = ti_sysbios_family_arm_ducati_Timer_Instance_init__E(__newobj, __args->id, __args->tickFxn, &__prms, __eb);
    if (xdc_runtime_Error_check(__eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_arm_ducati_Timer_Object__DESC__C, __newobj, (xdc_Fxn)ti_sysbios_family_arm_ducati_Timer_Instance_finalize__E, iStat, (xdc_Bool)(__obj != NULL));
        return NULL;
    }

    return __newobj;
}

/* create */
ti_sysbios_family_arm_ducati_Timer_Handle ti_sysbios_family_arm_ducati_Timer_create( xdc_Int id, ti_sysbios_interfaces_ITimer_FuncPtr tickFxn, const ti_sysbios_family_arm_ducati_Timer_Params *__paramsPtr, xdc_runtime_Error_Block *__eb )
{
    ti_sysbios_family_arm_ducati_Timer_Params __prms;
    ti_sysbios_family_arm_ducati_Timer_Object *__newobj;
    int iStat;

    /* common instance initialization */
    __newobj = xdc_runtime_Core_createObject__I(&ti_sysbios_family_arm_ducati_Timer_Object__DESC__C, 0, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_family_arm_ducati_Timer_Params), __eb);
    if (__newobj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    iStat = ti_sysbios_family_arm_ducati_Timer_Instance_init__E(__newobj, id, tickFxn, &__prms, __eb);
    if (xdc_runtime_Error_check(__eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_arm_ducati_Timer_Object__DESC__C, __newobj, (xdc_Fxn)ti_sysbios_family_arm_ducati_Timer_Instance_finalize__E, iStat, 0);
        return NULL;
    }

    return __newobj;
}

/* construct */
void ti_sysbios_family_arm_ducati_Timer_construct(ti_sysbios_family_arm_ducati_Timer_Struct *__obj, xdc_Int id, ti_sysbios_interfaces_ITimer_FuncPtr tickFxn, const ti_sysbios_family_arm_ducati_Timer_Params *__paramsPtr, xdc_runtime_Error_Block *__eb )
{
    ti_sysbios_family_arm_ducati_Timer_Params __prms;
    int iStat;

    /* common instance initialization */
    xdc_runtime_Core_constructObject__I(&ti_sysbios_family_arm_ducati_Timer_Object__DESC__C, __obj, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_family_arm_ducati_Timer_Params), __eb);
    /* module-specific initialization */
    iStat = ti_sysbios_family_arm_ducati_Timer_Instance_init__E((xdc_Ptr)__obj, id, tickFxn, &__prms, __eb);
    if (xdc_runtime_Error_check(__eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_arm_ducati_Timer_Object__DESC__C, (xdc_Ptr)__obj, (xdc_Fxn)ti_sysbios_family_arm_ducati_Timer_Instance_finalize__E, iStat, 1);
    }

}

/* Object__destruct__S */
xdc_Void ti_sysbios_family_arm_ducati_Timer_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_arm_ducati_Timer_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_family_arm_ducati_Timer_Instance_finalize__E, 0, TRUE);
}

/* destruct */
void ti_sysbios_family_arm_ducati_Timer_destruct(ti_sysbios_family_arm_ducati_Timer_Struct *obj)
{
    ti_sysbios_family_arm_ducati_Timer_Object__destruct__S(obj);
}

/* Object__delete__S */
xdc_Void ti_sysbios_family_arm_ducati_Timer_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_arm_ducati_Timer_Object__DESC__C, *((ti_sysbios_family_arm_ducati_Timer_Object**)instp), (xdc_Fxn)ti_sysbios_family_arm_ducati_Timer_Instance_finalize__E, 0, FALSE);
    *((ti_sysbios_family_arm_ducati_Timer_Handle*)instp) = NULL;
}

/* delete */
void ti_sysbios_family_arm_ducati_Timer_delete(ti_sysbios_family_arm_ducati_Timer_Handle *instp)
{
    ti_sysbios_family_arm_ducati_Timer_Object__delete__S(instp);
}


/*
 * ======== ti.sysbios.family.arm.m3.Hwi SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_family_arm_m3_Hwi_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_family_arm_m3_Hwi_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_family_arm_m3_Hwi_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_family_arm_m3_Hwi_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_family_arm_m3_Hwi_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_family_arm_m3_Hwi_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_family_arm_m3_Hwi_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_family_arm_m3_Hwi_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_family_arm_m3_Hwi_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_family_arm_m3_Hwi_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_family_arm_m3_Hwi_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_family_arm_m3_Hwi_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_family_arm_m3_Hwi_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_arm_m3_Hwi_Module__startupDone__S( void )
{
    return ti_sysbios_family_arm_m3_Hwi_Module__startupDone__F();
}

/* Handle__label__S */
xdc_runtime_Types_Label *ti_sysbios_family_arm_m3_Hwi_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab) 
{
    lab->handle = obj;
    lab->modId = 32800;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_family_arm_m3_Hwi_Params__init__S( xdc_Ptr prms, const void *src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_CPtr)(src ? src : &ti_sysbios_family_arm_m3_Hwi_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_family_arm_m3_Hwi_Object__get__S(xdc_Ptr oa, xdc_Int i)
{
    if (oa) {
        return ((ti_sysbios_family_arm_m3_Hwi_Object__ *)oa) + i;
    }

    if (ti_sysbios_family_arm_m3_Hwi_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_family_arm_m3_Hwi_Object__ *)ti_sysbios_family_arm_m3_Hwi_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_family_arm_m3_Hwi_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_family_arm_m3_Hwi_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_family_arm_m3_Hwi_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_family_arm_m3_Hwi_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_family_arm_m3_Hwi_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_family_arm_m3_Hwi_Object__create__S (
    xdc_Ptr __obj, 
    xdc_SizeT __osz,
    const xdc_Ptr __aa,
    const ti_sysbios_family_arm_m3_Hwi___ParamsPtr __paramsPtr,
    xdc_SizeT __psz,
    xdc_runtime_Error_Block *__eb)
{
    ti_sysbios_family_arm_m3_Hwi_Args__create *__args = __aa;
    ti_sysbios_family_arm_m3_Hwi_Params __prms;
    ti_sysbios_family_arm_m3_Hwi_Object *__newobj;
    int iStat;

    /* common instance initialization */
    __newobj = xdc_runtime_Core_createObject__I(&ti_sysbios_family_arm_m3_Hwi_Object__DESC__C, __obj, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_family_arm_m3_Hwi_Params), __eb);
    if (__newobj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    iStat = ti_sysbios_family_arm_m3_Hwi_Instance_init__E(__newobj, __args->intNum, __args->hwiFxn, &__prms, __eb);
    if (xdc_runtime_Error_check(__eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_arm_m3_Hwi_Object__DESC__C, __newobj, (xdc_Fxn)ti_sysbios_family_arm_m3_Hwi_Instance_finalize__E, iStat, (xdc_Bool)(__obj != NULL));
        return NULL;
    }

    return __newobj;
}

/* create */
ti_sysbios_family_arm_m3_Hwi_Handle ti_sysbios_family_arm_m3_Hwi_create( xdc_Int intNum, ti_sysbios_interfaces_IHwi_FuncPtr hwiFxn, const ti_sysbios_family_arm_m3_Hwi_Params *__paramsPtr, xdc_runtime_Error_Block *__eb )
{
    ti_sysbios_family_arm_m3_Hwi_Params __prms;
    ti_sysbios_family_arm_m3_Hwi_Object *__newobj;
    int iStat;

    /* common instance initialization */
    __newobj = xdc_runtime_Core_createObject__I(&ti_sysbios_family_arm_m3_Hwi_Object__DESC__C, 0, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_family_arm_m3_Hwi_Params), __eb);
    if (__newobj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    iStat = ti_sysbios_family_arm_m3_Hwi_Instance_init__E(__newobj, intNum, hwiFxn, &__prms, __eb);
    if (xdc_runtime_Error_check(__eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_arm_m3_Hwi_Object__DESC__C, __newobj, (xdc_Fxn)ti_sysbios_family_arm_m3_Hwi_Instance_finalize__E, iStat, 0);
        return NULL;
    }

    return __newobj;
}

/* construct */
void ti_sysbios_family_arm_m3_Hwi_construct(ti_sysbios_family_arm_m3_Hwi_Struct *__obj, xdc_Int intNum, ti_sysbios_interfaces_IHwi_FuncPtr hwiFxn, const ti_sysbios_family_arm_m3_Hwi_Params *__paramsPtr, xdc_runtime_Error_Block *__eb )
{
    ti_sysbios_family_arm_m3_Hwi_Params __prms;
    int iStat;

    /* common instance initialization */
    xdc_runtime_Core_constructObject__I(&ti_sysbios_family_arm_m3_Hwi_Object__DESC__C, __obj, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_family_arm_m3_Hwi_Params), __eb);
    /* module-specific initialization */
    iStat = ti_sysbios_family_arm_m3_Hwi_Instance_init__E((xdc_Ptr)__obj, intNum, hwiFxn, &__prms, __eb);
    if (xdc_runtime_Error_check(__eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_arm_m3_Hwi_Object__DESC__C, (xdc_Ptr)__obj, (xdc_Fxn)ti_sysbios_family_arm_m3_Hwi_Instance_finalize__E, iStat, 1);
    }

}

/* Object__destruct__S */
xdc_Void ti_sysbios_family_arm_m3_Hwi_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_arm_m3_Hwi_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_family_arm_m3_Hwi_Instance_finalize__E, 0, TRUE);
}

/* destruct */
void ti_sysbios_family_arm_m3_Hwi_destruct(ti_sysbios_family_arm_m3_Hwi_Struct *obj)
{
    ti_sysbios_family_arm_m3_Hwi_Object__destruct__S(obj);
}

/* Object__delete__S */
xdc_Void ti_sysbios_family_arm_m3_Hwi_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_arm_m3_Hwi_Object__DESC__C, *((ti_sysbios_family_arm_m3_Hwi_Object**)instp), (xdc_Fxn)ti_sysbios_family_arm_m3_Hwi_Instance_finalize__E, 0, FALSE);
    *((ti_sysbios_family_arm_m3_Hwi_Handle*)instp) = NULL;
}

/* delete */
void ti_sysbios_family_arm_m3_Hwi_delete(ti_sysbios_family_arm_m3_Hwi_Handle *instp)
{
    ti_sysbios_family_arm_m3_Hwi_Object__delete__S(instp);
}


/*
 * ======== ti.sysbios.family.arm.m3.IntrinsicsSupport SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== ti.sysbios.family.arm.m3.TaskSupport SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_arm_m3_TaskSupport_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== ti.sysbios.family.shared.vayu.IntXbar SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_shared_vayu_IntXbar_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== ti.sysbios.gates.GateHwi SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_gates_GateHwi_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_gates_GateHwi_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_gates_GateHwi_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_gates_GateHwi_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_gates_GateHwi_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_gates_GateHwi_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_gates_GateHwi_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_gates_GateHwi_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_gates_GateHwi_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_gates_GateHwi_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_gates_GateHwi_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_gates_GateHwi_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_gates_GateHwi_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_gates_GateHwi_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_gates_GateHwi_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_gates_GateHwi_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_gates_GateHwi_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_gates_GateHwi_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_gates_GateHwi_Module__startupDone__S( void )
{
    return 1;
}

/* Handle__label__S */
xdc_runtime_Types_Label *ti_sysbios_gates_GateHwi_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab) 
{
    lab->handle = obj;
    lab->modId = 32816;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_gates_GateHwi_Params__init__S( xdc_Ptr prms, const void *src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_CPtr)(src ? src : &ti_sysbios_gates_GateHwi_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_gates_GateHwi_Object__get__S(xdc_Ptr oa, xdc_Int i)
{
    if (oa) {
        return ((ti_sysbios_gates_GateHwi_Object__ *)oa) + i;
    }

    if (ti_sysbios_gates_GateHwi_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_gates_GateHwi_Object__ *)ti_sysbios_gates_GateHwi_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_gates_GateHwi_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_gates_GateHwi_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_gates_GateHwi_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_gates_GateHwi_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_gates_GateHwi_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_gates_GateHwi_Object__create__S (
    xdc_Ptr __obj, 
    xdc_SizeT __osz,
    const xdc_Ptr __aa,
    const ti_sysbios_gates_GateHwi___ParamsPtr __paramsPtr,
    xdc_SizeT __psz,
    xdc_runtime_Error_Block *__eb)
{
    ti_sysbios_gates_GateHwi_Params __prms;
    ti_sysbios_gates_GateHwi_Object *__newobj;

    /* common instance initialization */
    __newobj = xdc_runtime_Core_createObject__I(&ti_sysbios_gates_GateHwi_Object__DESC__C, __obj, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_gates_GateHwi_Params), __eb);
    if (__newobj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    ti_sysbios_gates_GateHwi_Instance_init__E(__newobj, &__prms);
    return __newobj;
}

/* create */
ti_sysbios_gates_GateHwi_Handle ti_sysbios_gates_GateHwi_create( const ti_sysbios_gates_GateHwi_Params *__paramsPtr, xdc_runtime_Error_Block *__eb )
{
    ti_sysbios_gates_GateHwi_Params __prms;
    ti_sysbios_gates_GateHwi_Object *__newobj;

    /* common instance initialization */
    __newobj = xdc_runtime_Core_createObject__I(&ti_sysbios_gates_GateHwi_Object__DESC__C, 0, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_gates_GateHwi_Params), __eb);
    if (__newobj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    ti_sysbios_gates_GateHwi_Instance_init__E(__newobj, &__prms);
    return __newobj;
}

/* construct */
void ti_sysbios_gates_GateHwi_construct(ti_sysbios_gates_GateHwi_Struct *__obj, const ti_sysbios_gates_GateHwi_Params *__paramsPtr )
{
    ti_sysbios_gates_GateHwi_Params __prms;

    /* common instance initialization */
    xdc_runtime_Core_constructObject__I(&ti_sysbios_gates_GateHwi_Object__DESC__C, __obj, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_gates_GateHwi_Params), NULL);
    /* module-specific initialization */
    ti_sysbios_gates_GateHwi_Instance_init__E((xdc_Ptr)__obj, &__prms);
}

/* Object__destruct__S */
xdc_Void ti_sysbios_gates_GateHwi_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_gates_GateHwi_Object__DESC__C, obj, NULL, -1, TRUE);
}

/* destruct */
void ti_sysbios_gates_GateHwi_destruct(ti_sysbios_gates_GateHwi_Struct *obj)
{
    ti_sysbios_gates_GateHwi_Object__destruct__S(obj);
}

/* Object__delete__S */
xdc_Void ti_sysbios_gates_GateHwi_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_gates_GateHwi_Object__DESC__C, *((ti_sysbios_gates_GateHwi_Object**)instp), NULL, -1, FALSE);
    *((ti_sysbios_gates_GateHwi_Handle*)instp) = NULL;
}

/* delete */
void ti_sysbios_gates_GateHwi_delete(ti_sysbios_gates_GateHwi_Handle *instp)
{
    ti_sysbios_gates_GateHwi_Object__delete__S(instp);
}


/*
 * ======== ti.sysbios.gates.GateMutex SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_gates_GateMutex_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_gates_GateMutex_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_gates_GateMutex_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_gates_GateMutex_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_gates_GateMutex_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_gates_GateMutex_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_gates_GateMutex_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_gates_GateMutex_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_gates_GateMutex_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_gates_GateMutex_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_gates_GateMutex_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_gates_GateMutex_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_gates_GateMutex_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_gates_GateMutex_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_gates_GateMutex_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_gates_GateMutex_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_gates_GateMutex_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_gates_GateMutex_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_gates_GateMutex_Module__startupDone__S( void )
{
    return 1;
}

/* Handle__label__S */
xdc_runtime_Types_Label *ti_sysbios_gates_GateMutex_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab) 
{
    lab->handle = obj;
    lab->modId = 32817;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_gates_GateMutex_Params__init__S( xdc_Ptr prms, const void *src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_CPtr)(src ? src : &ti_sysbios_gates_GateMutex_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_gates_GateMutex_Object__get__S(xdc_Ptr oa, xdc_Int i)
{
    if (oa) {
        return ((ti_sysbios_gates_GateMutex_Object__ *)oa) + i;
    }

    if (ti_sysbios_gates_GateMutex_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_gates_GateMutex_Object__ *)ti_sysbios_gates_GateMutex_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_gates_GateMutex_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_gates_GateMutex_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_gates_GateMutex_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_gates_GateMutex_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_gates_GateMutex_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_gates_GateMutex_Object__create__S (
    xdc_Ptr __obj, 
    xdc_SizeT __osz,
    const xdc_Ptr __aa,
    const ti_sysbios_gates_GateMutex___ParamsPtr __paramsPtr,
    xdc_SizeT __psz,
    xdc_runtime_Error_Block *__eb)
{
    ti_sysbios_gates_GateMutex_Params __prms;
    ti_sysbios_gates_GateMutex_Object *__newobj;

    /* common instance initialization */
    __newobj = xdc_runtime_Core_createObject__I(&ti_sysbios_gates_GateMutex_Object__DESC__C, __obj, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_gates_GateMutex_Params), __eb);
    if (__newobj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    ti_sysbios_gates_GateMutex_Instance_init__E(__newobj, &__prms);
    return __newobj;
}

/* create */
ti_sysbios_gates_GateMutex_Handle ti_sysbios_gates_GateMutex_create( const ti_sysbios_gates_GateMutex_Params *__paramsPtr, xdc_runtime_Error_Block *__eb )
{
    ti_sysbios_gates_GateMutex_Params __prms;
    ti_sysbios_gates_GateMutex_Object *__newobj;

    /* common instance initialization */
    __newobj = xdc_runtime_Core_createObject__I(&ti_sysbios_gates_GateMutex_Object__DESC__C, 0, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_gates_GateMutex_Params), __eb);
    if (__newobj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    ti_sysbios_gates_GateMutex_Instance_init__E(__newobj, &__prms);
    return __newobj;
}

/* construct */
void ti_sysbios_gates_GateMutex_construct(ti_sysbios_gates_GateMutex_Struct *__obj, const ti_sysbios_gates_GateMutex_Params *__paramsPtr )
{
    ti_sysbios_gates_GateMutex_Params __prms;

    /* common instance initialization */
    xdc_runtime_Core_constructObject__I(&ti_sysbios_gates_GateMutex_Object__DESC__C, __obj, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_gates_GateMutex_Params), NULL);
    /* module-specific initialization */
    ti_sysbios_gates_GateMutex_Instance_init__E((xdc_Ptr)__obj, &__prms);
}

/* Object__destruct__S */
xdc_Void ti_sysbios_gates_GateMutex_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_gates_GateMutex_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_gates_GateMutex_Instance_finalize__E, -1, TRUE);
}

/* destruct */
void ti_sysbios_gates_GateMutex_destruct(ti_sysbios_gates_GateMutex_Struct *obj)
{
    ti_sysbios_gates_GateMutex_Object__destruct__S(obj);
}

/* Object__delete__S */
xdc_Void ti_sysbios_gates_GateMutex_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_gates_GateMutex_Object__DESC__C, *((ti_sysbios_gates_GateMutex_Object**)instp), (xdc_Fxn)ti_sysbios_gates_GateMutex_Instance_finalize__E, -1, FALSE);
    *((ti_sysbios_gates_GateMutex_Handle*)instp) = NULL;
}

/* delete */
void ti_sysbios_gates_GateMutex_delete(ti_sysbios_gates_GateMutex_Handle *instp)
{
    ti_sysbios_gates_GateMutex_Object__delete__S(instp);
}


/*
 * ======== ti.sysbios.hal.Cache SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_hal_Cache_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== ti.sysbios.hal.Cache_CacheProxy SYSTEM FUNCTIONS ========
 */


xdc_Bool ti_sysbios_hal_Cache_CacheProxy_Proxy__abstract__S( void )
{
    return 0;
}
xdc_Ptr ti_sysbios_hal_Cache_CacheProxy_Proxy__delegate__S( void )
{
    return (void *)&ti_sysbios_hal_unicache_Cache_Module__FXNS__C;
}


/*
 * ======== ti.sysbios.hal.Hwi SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_hal_Hwi_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_hal_Hwi_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_hal_Hwi_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_hal_Hwi_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_hal_Hwi_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_hal_Hwi_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_hal_Hwi_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_hal_Hwi_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_hal_Hwi_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_hal_Hwi_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_hal_Hwi_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_hal_Hwi_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_hal_Hwi_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_hal_Hwi_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_hal_Hwi_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_hal_Hwi_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_hal_Hwi_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_hal_Hwi_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_hal_Hwi_Module__startupDone__S( void )
{
    return ti_sysbios_hal_Hwi_Module__startupDone__F();
}

/* Handle__label__S */
xdc_runtime_Types_Label *ti_sysbios_hal_Hwi_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab) 
{
    lab->handle = obj;
    lab->modId = 32796;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_hal_Hwi_Params__init__S( xdc_Ptr prms, const void *src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_CPtr)(src ? src : &ti_sysbios_hal_Hwi_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_hal_Hwi_Object__get__S(xdc_Ptr oa, xdc_Int i)
{
    if (oa) {
        return ((ti_sysbios_hal_Hwi_Object__ *)oa) + i;
    }

    if (ti_sysbios_hal_Hwi_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_hal_Hwi_Object__ *)ti_sysbios_hal_Hwi_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_hal_Hwi_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_hal_Hwi_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_hal_Hwi_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_hal_Hwi_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_hal_Hwi_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_hal_Hwi_Object__create__S (
    xdc_Ptr __obj, 
    xdc_SizeT __osz,
    const xdc_Ptr __aa,
    const ti_sysbios_hal_Hwi___ParamsPtr __paramsPtr,
    xdc_SizeT __psz,
    xdc_runtime_Error_Block *__eb)
{
    ti_sysbios_hal_Hwi_Args__create *__args = __aa;
    ti_sysbios_hal_Hwi_Params __prms;
    ti_sysbios_hal_Hwi_Object *__newobj;
    int iStat;

    /* common instance initialization */
    __newobj = xdc_runtime_Core_createObject__I(&ti_sysbios_hal_Hwi_Object__DESC__C, __obj, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_hal_Hwi_Params), __eb);
    if (__newobj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    iStat = ti_sysbios_hal_Hwi_Instance_init__E(__newobj, __args->intNum, __args->hwiFxn, &__prms, __eb);
    if (xdc_runtime_Error_check(__eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_hal_Hwi_Object__DESC__C, __newobj, (xdc_Fxn)ti_sysbios_hal_Hwi_Instance_finalize__E, iStat, (xdc_Bool)(__obj != NULL));
        return NULL;
    }

    return __newobj;
}

/* create */
ti_sysbios_hal_Hwi_Handle ti_sysbios_hal_Hwi_create( xdc_Int intNum, ti_sysbios_hal_Hwi_FuncPtr hwiFxn, const ti_sysbios_hal_Hwi_Params *__paramsPtr, xdc_runtime_Error_Block *__eb )
{
    ti_sysbios_hal_Hwi_Params __prms;
    ti_sysbios_hal_Hwi_Object *__newobj;
    int iStat;

    /* common instance initialization */
    __newobj = xdc_runtime_Core_createObject__I(&ti_sysbios_hal_Hwi_Object__DESC__C, 0, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_hal_Hwi_Params), __eb);
    if (__newobj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    iStat = ti_sysbios_hal_Hwi_Instance_init__E(__newobj, intNum, hwiFxn, &__prms, __eb);
    if (xdc_runtime_Error_check(__eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_hal_Hwi_Object__DESC__C, __newobj, (xdc_Fxn)ti_sysbios_hal_Hwi_Instance_finalize__E, iStat, 0);
        return NULL;
    }

    return __newobj;
}

/* construct */
void ti_sysbios_hal_Hwi_construct(ti_sysbios_hal_Hwi_Struct *__obj, xdc_Int intNum, ti_sysbios_hal_Hwi_FuncPtr hwiFxn, const ti_sysbios_hal_Hwi_Params *__paramsPtr, xdc_runtime_Error_Block *__eb )
{
    ti_sysbios_hal_Hwi_Params __prms;
    int iStat;

    /* common instance initialization */
    xdc_runtime_Core_constructObject__I(&ti_sysbios_hal_Hwi_Object__DESC__C, __obj, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_hal_Hwi_Params), __eb);
    /* module-specific initialization */
    iStat = ti_sysbios_hal_Hwi_Instance_init__E((xdc_Ptr)__obj, intNum, hwiFxn, &__prms, __eb);
    if (xdc_runtime_Error_check(__eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_hal_Hwi_Object__DESC__C, (xdc_Ptr)__obj, (xdc_Fxn)ti_sysbios_hal_Hwi_Instance_finalize__E, iStat, 1);
    }

}

/* Object__destruct__S */
xdc_Void ti_sysbios_hal_Hwi_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_hal_Hwi_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_hal_Hwi_Instance_finalize__E, 0, TRUE);
}

/* destruct */
void ti_sysbios_hal_Hwi_destruct(ti_sysbios_hal_Hwi_Struct *obj)
{
    ti_sysbios_hal_Hwi_Object__destruct__S(obj);
}

/* Object__delete__S */
xdc_Void ti_sysbios_hal_Hwi_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_hal_Hwi_Object__DESC__C, *((ti_sysbios_hal_Hwi_Object**)instp), (xdc_Fxn)ti_sysbios_hal_Hwi_Instance_finalize__E, 0, FALSE);
    *((ti_sysbios_hal_Hwi_Handle*)instp) = NULL;
}

/* delete */
void ti_sysbios_hal_Hwi_delete(ti_sysbios_hal_Hwi_Handle *instp)
{
    ti_sysbios_hal_Hwi_Object__delete__S(instp);
}


/*
 * ======== ti.sysbios.hal.Hwi_HwiProxy SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_hal_Hwi_HwiProxy_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_hal_Hwi_HwiProxy_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_hal_Hwi_HwiProxy_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_hal_Hwi_HwiProxy_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_hal_Hwi_HwiProxy_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_hal_Hwi_HwiProxy_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_hal_Hwi_HwiProxy_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_hal_Hwi_HwiProxy_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_hal_Hwi_HwiProxy_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_hal_Hwi_HwiProxy_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_hal_Hwi_HwiProxy_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_hal_Hwi_HwiProxy_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_hal_Hwi_HwiProxy_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_hal_Hwi_HwiProxy_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_hal_Hwi_HwiProxy_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_hal_Hwi_HwiProxy_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_hal_Hwi_HwiProxy_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_hal_Hwi_HwiProxy_Module_GateProxy_query

xdc_Bool ti_sysbios_hal_Hwi_HwiProxy_Proxy__abstract__S( void )
{
    return 0;
}
xdc_Ptr ti_sysbios_hal_Hwi_HwiProxy_Proxy__delegate__S( void )
{
    return 0;
}



/*
 * ======== ti.sysbios.hal.ammu.AMMU SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_hal_ammu_AMMU_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== ti.sysbios.hal.unicache.Cache SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_hal_unicache_Cache_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== ti.sysbios.hal.unicache.Cache_Module_GateProxy SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_hal_unicache_Cache_Module_GateProxy_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_hal_unicache_Cache_Module_GateProxy_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_hal_unicache_Cache_Module_GateProxy_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_hal_unicache_Cache_Module_GateProxy_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_hal_unicache_Cache_Module_GateProxy_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_hal_unicache_Cache_Module_GateProxy_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_hal_unicache_Cache_Module_GateProxy_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_hal_unicache_Cache_Module_GateProxy_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_hal_unicache_Cache_Module_GateProxy_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_hal_unicache_Cache_Module_GateProxy_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_hal_unicache_Cache_Module_GateProxy_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_hal_unicache_Cache_Module_GateProxy_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_hal_unicache_Cache_Module_GateProxy_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_hal_unicache_Cache_Module_GateProxy_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_hal_unicache_Cache_Module_GateProxy_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_hal_unicache_Cache_Module_GateProxy_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_hal_unicache_Cache_Module_GateProxy_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_hal_unicache_Cache_Module_GateProxy_Module_GateProxy_query

xdc_Bool ti_sysbios_hal_unicache_Cache_Module_GateProxy_Proxy__abstract__S( void )
{
    return 0;
}
xdc_Ptr ti_sysbios_hal_unicache_Cache_Module_GateProxy_Proxy__delegate__S( void )
{
    return (void *)&ti_sysbios_family_arm_ducati_GateDualCore_Module__FXNS__C;
}



/*
 * ======== ti.sysbios.heaps.HeapMem SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_heaps_HeapMem_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_heaps_HeapMem_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_heaps_HeapMem_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_heaps_HeapMem_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_heaps_HeapMem_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_heaps_HeapMem_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_heaps_HeapMem_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_heaps_HeapMem_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_heaps_HeapMem_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_heaps_HeapMem_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_heaps_HeapMem_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_heaps_HeapMem_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_heaps_HeapMem_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_heaps_HeapMem_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_heaps_HeapMem_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_heaps_HeapMem_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_heaps_HeapMem_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_heaps_HeapMem_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_heaps_HeapMem_Module__startupDone__S( void )
{
    return 1;
}

/* Handle__label__S */
xdc_runtime_Types_Label *ti_sysbios_heaps_HeapMem_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab) 
{
    lab->handle = obj;
    lab->modId = 32819;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_heaps_HeapMem_Params__init__S( xdc_Ptr prms, const void *src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_CPtr)(src ? src : &ti_sysbios_heaps_HeapMem_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_heaps_HeapMem_Object__get__S(xdc_Ptr oa, xdc_Int i)
{
    if (oa) {
        return ((ti_sysbios_heaps_HeapMem_Object__ *)oa) + i;
    }

    if (ti_sysbios_heaps_HeapMem_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_heaps_HeapMem_Object__ *)ti_sysbios_heaps_HeapMem_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_heaps_HeapMem_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_heaps_HeapMem_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_heaps_HeapMem_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_heaps_HeapMem_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_heaps_HeapMem_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_heaps_HeapMem_Object__create__S (
    xdc_Ptr __obj, 
    xdc_SizeT __osz,
    const xdc_Ptr __aa,
    const ti_sysbios_heaps_HeapMem___ParamsPtr __paramsPtr,
    xdc_SizeT __psz,
    xdc_runtime_Error_Block *__eb)
{
    ti_sysbios_heaps_HeapMem_Params __prms;
    ti_sysbios_heaps_HeapMem_Object *__newobj;

    /* common instance initialization */
    __newobj = xdc_runtime_Core_createObject__I(&ti_sysbios_heaps_HeapMem_Object__DESC__C, __obj, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_heaps_HeapMem_Params), __eb);
    if (__newobj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    ti_sysbios_heaps_HeapMem_Instance_init__E(__newobj, &__prms);
    return __newobj;
}

/* create */
ti_sysbios_heaps_HeapMem_Handle ti_sysbios_heaps_HeapMem_create( const ti_sysbios_heaps_HeapMem_Params *__paramsPtr, xdc_runtime_Error_Block *__eb )
{
    ti_sysbios_heaps_HeapMem_Params __prms;
    ti_sysbios_heaps_HeapMem_Object *__newobj;

    /* common instance initialization */
    __newobj = xdc_runtime_Core_createObject__I(&ti_sysbios_heaps_HeapMem_Object__DESC__C, 0, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_heaps_HeapMem_Params), __eb);
    if (__newobj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    ti_sysbios_heaps_HeapMem_Instance_init__E(__newobj, &__prms);
    return __newobj;
}

/* construct */
void ti_sysbios_heaps_HeapMem_construct(ti_sysbios_heaps_HeapMem_Struct *__obj, const ti_sysbios_heaps_HeapMem_Params *__paramsPtr )
{
    ti_sysbios_heaps_HeapMem_Params __prms;

    /* common instance initialization */
    xdc_runtime_Core_constructObject__I(&ti_sysbios_heaps_HeapMem_Object__DESC__C, __obj, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_heaps_HeapMem_Params), NULL);
    /* module-specific initialization */
    ti_sysbios_heaps_HeapMem_Instance_init__E((xdc_Ptr)__obj, &__prms);
}

/* Object__destruct__S */
xdc_Void ti_sysbios_heaps_HeapMem_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_heaps_HeapMem_Object__DESC__C, obj, NULL, -1, TRUE);
}

/* destruct */
void ti_sysbios_heaps_HeapMem_destruct(ti_sysbios_heaps_HeapMem_Struct *obj)
{
    ti_sysbios_heaps_HeapMem_Object__destruct__S(obj);
}

/* Object__delete__S */
xdc_Void ti_sysbios_heaps_HeapMem_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_heaps_HeapMem_Object__DESC__C, *((ti_sysbios_heaps_HeapMem_Object**)instp), NULL, -1, FALSE);
    *((ti_sysbios_heaps_HeapMem_Handle*)instp) = NULL;
}

/* delete */
void ti_sysbios_heaps_HeapMem_delete(ti_sysbios_heaps_HeapMem_Handle *instp)
{
    ti_sysbios_heaps_HeapMem_Object__delete__S(instp);
}


/*
 * ======== ti.sysbios.heaps.HeapMem_Module_GateProxy SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_heaps_HeapMem_Module_GateProxy_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_heaps_HeapMem_Module_GateProxy_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_heaps_HeapMem_Module_GateProxy_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_heaps_HeapMem_Module_GateProxy_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_heaps_HeapMem_Module_GateProxy_Module_GateProxy_query

xdc_Bool ti_sysbios_heaps_HeapMem_Module_GateProxy_Proxy__abstract__S( void )
{
    return 0;
}
xdc_Ptr ti_sysbios_heaps_HeapMem_Module_GateProxy_Proxy__delegate__S( void )
{
    return (void *)&ti_sysbios_gates_GateMutex_Module__FXNS__C;
}



/*
 * ======== ti.sysbios.knl.Clock SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_knl_Clock_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_knl_Clock_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_knl_Clock_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_knl_Clock_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_knl_Clock_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_knl_Clock_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_knl_Clock_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_knl_Clock_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_knl_Clock_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_knl_Clock_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_knl_Clock_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_knl_Clock_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_knl_Clock_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_knl_Clock_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_knl_Clock_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_knl_Clock_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_knl_Clock_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_knl_Clock_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Clock_Module__startupDone__S( void )
{
    return ti_sysbios_knl_Clock_Module__startupDone__F();
}

/* Handle__label__S */
xdc_runtime_Types_Label *ti_sysbios_knl_Clock_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab) 
{
    lab->handle = obj;
    lab->modId = 32786;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_knl_Clock_Params__init__S( xdc_Ptr prms, const void *src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_CPtr)(src ? src : &ti_sysbios_knl_Clock_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_knl_Clock_Object__get__S(xdc_Ptr oa, xdc_Int i)
{
    if (oa) {
        return ((ti_sysbios_knl_Clock_Object__ *)oa) + i;
    }

    if (ti_sysbios_knl_Clock_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_knl_Clock_Object__ *)ti_sysbios_knl_Clock_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_knl_Clock_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_knl_Clock_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_knl_Clock_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_knl_Clock_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_knl_Clock_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_knl_Clock_Object__create__S (
    xdc_Ptr __obj, 
    xdc_SizeT __osz,
    const xdc_Ptr __aa,
    const ti_sysbios_knl_Clock___ParamsPtr __paramsPtr,
    xdc_SizeT __psz,
    xdc_runtime_Error_Block *__eb)
{
    ti_sysbios_knl_Clock_Args__create *__args = __aa;
    ti_sysbios_knl_Clock_Params __prms;
    ti_sysbios_knl_Clock_Object *__newobj;

    /* common instance initialization */
    __newobj = xdc_runtime_Core_createObject__I(&ti_sysbios_knl_Clock_Object__DESC__C, __obj, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_knl_Clock_Params), __eb);
    if (__newobj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    ti_sysbios_knl_Clock_Instance_init__E(__newobj, __args->clockFxn, __args->timeout, &__prms);
    return __newobj;
}

/* create */
ti_sysbios_knl_Clock_Handle ti_sysbios_knl_Clock_create( ti_sysbios_knl_Clock_FuncPtr clockFxn, xdc_UInt timeout, const ti_sysbios_knl_Clock_Params *__paramsPtr, xdc_runtime_Error_Block *__eb )
{
    ti_sysbios_knl_Clock_Params __prms;
    ti_sysbios_knl_Clock_Object *__newobj;

    /* common instance initialization */
    __newobj = xdc_runtime_Core_createObject__I(&ti_sysbios_knl_Clock_Object__DESC__C, 0, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_knl_Clock_Params), __eb);
    if (__newobj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    ti_sysbios_knl_Clock_Instance_init__E(__newobj, clockFxn, timeout, &__prms);
    return __newobj;
}

/* construct */
void ti_sysbios_knl_Clock_construct(ti_sysbios_knl_Clock_Struct *__obj, ti_sysbios_knl_Clock_FuncPtr clockFxn, xdc_UInt timeout, const ti_sysbios_knl_Clock_Params *__paramsPtr )
{
    ti_sysbios_knl_Clock_Params __prms;

    /* common instance initialization */
    xdc_runtime_Core_constructObject__I(&ti_sysbios_knl_Clock_Object__DESC__C, __obj, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_knl_Clock_Params), NULL);
    /* module-specific initialization */
    ti_sysbios_knl_Clock_Instance_init__E((xdc_Ptr)__obj, clockFxn, timeout, &__prms);
}

/* Object__destruct__S */
xdc_Void ti_sysbios_knl_Clock_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Clock_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_knl_Clock_Instance_finalize__E, -1, TRUE);
}

/* destruct */
void ti_sysbios_knl_Clock_destruct(ti_sysbios_knl_Clock_Struct *obj)
{
    ti_sysbios_knl_Clock_Object__destruct__S(obj);
}

/* Object__delete__S */
xdc_Void ti_sysbios_knl_Clock_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Clock_Object__DESC__C, *((ti_sysbios_knl_Clock_Object**)instp), (xdc_Fxn)ti_sysbios_knl_Clock_Instance_finalize__E, -1, FALSE);
    *((ti_sysbios_knl_Clock_Handle*)instp) = NULL;
}

/* delete */
void ti_sysbios_knl_Clock_delete(ti_sysbios_knl_Clock_Handle *instp)
{
    ti_sysbios_knl_Clock_Object__delete__S(instp);
}


/*
 * ======== ti.sysbios.knl.Clock_TimerProxy SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_knl_Clock_TimerProxy_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_knl_Clock_TimerProxy_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_knl_Clock_TimerProxy_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_knl_Clock_TimerProxy_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_knl_Clock_TimerProxy_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_knl_Clock_TimerProxy_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_knl_Clock_TimerProxy_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_knl_Clock_TimerProxy_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_knl_Clock_TimerProxy_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_knl_Clock_TimerProxy_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_knl_Clock_TimerProxy_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_knl_Clock_TimerProxy_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_knl_Clock_TimerProxy_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_knl_Clock_TimerProxy_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_knl_Clock_TimerProxy_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_knl_Clock_TimerProxy_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_knl_Clock_TimerProxy_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_knl_Clock_TimerProxy_Module_GateProxy_query

xdc_Bool ti_sysbios_knl_Clock_TimerProxy_Proxy__abstract__S( void )
{
    return 0;
}
xdc_Ptr ti_sysbios_knl_Clock_TimerProxy_Proxy__delegate__S( void )
{
    return 0;
}



/*
 * ======== ti.sysbios.knl.Idle SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Idle_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== ti.sysbios.knl.Intrinsics SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Intrinsics_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== ti.sysbios.knl.Intrinsics_SupportProxy SYSTEM FUNCTIONS ========
 */


xdc_Bool ti_sysbios_knl_Intrinsics_SupportProxy_Proxy__abstract__S( void )
{
    return 0;
}
xdc_Ptr ti_sysbios_knl_Intrinsics_SupportProxy_Proxy__delegate__S( void )
{
    return (void *)&ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__FXNS__C;
}


/*
 * ======== ti.sysbios.knl.Queue SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_knl_Queue_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_knl_Queue_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_knl_Queue_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_knl_Queue_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_knl_Queue_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_knl_Queue_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_knl_Queue_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_knl_Queue_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_knl_Queue_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_knl_Queue_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_knl_Queue_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_knl_Queue_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_knl_Queue_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_knl_Queue_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_knl_Queue_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_knl_Queue_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_knl_Queue_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_knl_Queue_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Queue_Module__startupDone__S( void )
{
    return 1;
}

/* Handle__label__S */
xdc_runtime_Types_Label *ti_sysbios_knl_Queue_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab) 
{
    lab->handle = obj;
    lab->modId = 32789;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_knl_Queue_Params__init__S( xdc_Ptr prms, const void *src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_CPtr)(src ? src : &ti_sysbios_knl_Queue_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_knl_Queue_Object__get__S(xdc_Ptr oa, xdc_Int i)
{
    if (oa) {
        return ((ti_sysbios_knl_Queue_Object__ *)oa) + i;
    }

    if (ti_sysbios_knl_Queue_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_knl_Queue_Object__ *)ti_sysbios_knl_Queue_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_knl_Queue_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_knl_Queue_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_knl_Queue_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_knl_Queue_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_knl_Queue_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_knl_Queue_Object__create__S (
    xdc_Ptr __obj, 
    xdc_SizeT __osz,
    const xdc_Ptr __aa,
    const ti_sysbios_knl_Queue___ParamsPtr __paramsPtr,
    xdc_SizeT __psz,
    xdc_runtime_Error_Block *__eb)
{
    ti_sysbios_knl_Queue_Params __prms;
    ti_sysbios_knl_Queue_Object *__newobj;

    /* common instance initialization */
    __newobj = xdc_runtime_Core_createObject__I(&ti_sysbios_knl_Queue_Object__DESC__C, __obj, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_knl_Queue_Params), __eb);
    if (__newobj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    ti_sysbios_knl_Queue_Instance_init__E(__newobj, &__prms);
    return __newobj;
}

/* create */
ti_sysbios_knl_Queue_Handle ti_sysbios_knl_Queue_create( const ti_sysbios_knl_Queue_Params *__paramsPtr, xdc_runtime_Error_Block *__eb )
{
    ti_sysbios_knl_Queue_Params __prms;
    ti_sysbios_knl_Queue_Object *__newobj;

    /* common instance initialization */
    __newobj = xdc_runtime_Core_createObject__I(&ti_sysbios_knl_Queue_Object__DESC__C, 0, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_knl_Queue_Params), __eb);
    if (__newobj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    ti_sysbios_knl_Queue_Instance_init__E(__newobj, &__prms);
    return __newobj;
}

/* construct */
void ti_sysbios_knl_Queue_construct(ti_sysbios_knl_Queue_Struct *__obj, const ti_sysbios_knl_Queue_Params *__paramsPtr )
{
    ti_sysbios_knl_Queue_Params __prms;

    /* common instance initialization */
    xdc_runtime_Core_constructObject__I(&ti_sysbios_knl_Queue_Object__DESC__C, __obj, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_knl_Queue_Params), NULL);
    /* module-specific initialization */
    ti_sysbios_knl_Queue_Instance_init__E((xdc_Ptr)__obj, &__prms);
}

/* Object__destruct__S */
xdc_Void ti_sysbios_knl_Queue_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Queue_Object__DESC__C, obj, NULL, -1, TRUE);
}

/* destruct */
void ti_sysbios_knl_Queue_destruct(ti_sysbios_knl_Queue_Struct *obj)
{
    ti_sysbios_knl_Queue_Object__destruct__S(obj);
}

/* Object__delete__S */
xdc_Void ti_sysbios_knl_Queue_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Queue_Object__DESC__C, *((ti_sysbios_knl_Queue_Object**)instp), NULL, -1, FALSE);
    *((ti_sysbios_knl_Queue_Handle*)instp) = NULL;
}

/* delete */
void ti_sysbios_knl_Queue_delete(ti_sysbios_knl_Queue_Handle *instp)
{
    ti_sysbios_knl_Queue_Object__delete__S(instp);
}


/*
 * ======== ti.sysbios.knl.Semaphore SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_knl_Semaphore_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_knl_Semaphore_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_knl_Semaphore_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_knl_Semaphore_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_knl_Semaphore_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_knl_Semaphore_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_knl_Semaphore_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_knl_Semaphore_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_knl_Semaphore_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_knl_Semaphore_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_knl_Semaphore_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_knl_Semaphore_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_knl_Semaphore_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_knl_Semaphore_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_knl_Semaphore_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_knl_Semaphore_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_knl_Semaphore_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_knl_Semaphore_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Semaphore_Module__startupDone__S( void )
{
    return 1;
}

/* Handle__label__S */
xdc_runtime_Types_Label *ti_sysbios_knl_Semaphore_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab) 
{
    lab->handle = obj;
    lab->modId = 32790;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_knl_Semaphore_Params__init__S( xdc_Ptr prms, const void *src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_CPtr)(src ? src : &ti_sysbios_knl_Semaphore_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_knl_Semaphore_Object__get__S(xdc_Ptr oa, xdc_Int i)
{
    if (oa) {
        return ((ti_sysbios_knl_Semaphore_Object__ *)oa) + i;
    }

    if (ti_sysbios_knl_Semaphore_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_knl_Semaphore_Object__ *)ti_sysbios_knl_Semaphore_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_knl_Semaphore_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_knl_Semaphore_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_knl_Semaphore_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_knl_Semaphore_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_knl_Semaphore_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_knl_Semaphore_Object__create__S (
    xdc_Ptr __obj, 
    xdc_SizeT __osz,
    const xdc_Ptr __aa,
    const ti_sysbios_knl_Semaphore___ParamsPtr __paramsPtr,
    xdc_SizeT __psz,
    xdc_runtime_Error_Block *__eb)
{
    ti_sysbios_knl_Semaphore_Args__create *__args = __aa;
    ti_sysbios_knl_Semaphore_Params __prms;
    ti_sysbios_knl_Semaphore_Object *__newobj;

    /* common instance initialization */
    __newobj = xdc_runtime_Core_createObject__I(&ti_sysbios_knl_Semaphore_Object__DESC__C, __obj, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_knl_Semaphore_Params), __eb);
    if (__newobj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    ti_sysbios_knl_Semaphore_Instance_init__E(__newobj, __args->count, &__prms);
    return __newobj;
}

/* create */
ti_sysbios_knl_Semaphore_Handle ti_sysbios_knl_Semaphore_create( xdc_Int count, const ti_sysbios_knl_Semaphore_Params *__paramsPtr, xdc_runtime_Error_Block *__eb )
{
    ti_sysbios_knl_Semaphore_Params __prms;
    ti_sysbios_knl_Semaphore_Object *__newobj;

    /* common instance initialization */
    __newobj = xdc_runtime_Core_createObject__I(&ti_sysbios_knl_Semaphore_Object__DESC__C, 0, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_knl_Semaphore_Params), __eb);
    if (__newobj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    ti_sysbios_knl_Semaphore_Instance_init__E(__newobj, count, &__prms);
    return __newobj;
}

/* construct */
void ti_sysbios_knl_Semaphore_construct(ti_sysbios_knl_Semaphore_Struct *__obj, xdc_Int count, const ti_sysbios_knl_Semaphore_Params *__paramsPtr )
{
    ti_sysbios_knl_Semaphore_Params __prms;

    /* common instance initialization */
    xdc_runtime_Core_constructObject__I(&ti_sysbios_knl_Semaphore_Object__DESC__C, __obj, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_knl_Semaphore_Params), NULL);
    /* module-specific initialization */
    ti_sysbios_knl_Semaphore_Instance_init__E((xdc_Ptr)__obj, count, &__prms);
}

/* Object__destruct__S */
xdc_Void ti_sysbios_knl_Semaphore_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Semaphore_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_knl_Semaphore_Instance_finalize__E, -1, TRUE);
}

/* destruct */
void ti_sysbios_knl_Semaphore_destruct(ti_sysbios_knl_Semaphore_Struct *obj)
{
    ti_sysbios_knl_Semaphore_Object__destruct__S(obj);
}

/* Object__delete__S */
xdc_Void ti_sysbios_knl_Semaphore_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Semaphore_Object__DESC__C, *((ti_sysbios_knl_Semaphore_Object**)instp), (xdc_Fxn)ti_sysbios_knl_Semaphore_Instance_finalize__E, -1, FALSE);
    *((ti_sysbios_knl_Semaphore_Handle*)instp) = NULL;
}

/* delete */
void ti_sysbios_knl_Semaphore_delete(ti_sysbios_knl_Semaphore_Handle *instp)
{
    ti_sysbios_knl_Semaphore_Object__delete__S(instp);
}


/*
 * ======== ti.sysbios.knl.Swi SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_knl_Swi_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_knl_Swi_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_knl_Swi_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_knl_Swi_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_knl_Swi_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_knl_Swi_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_knl_Swi_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_knl_Swi_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_knl_Swi_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_knl_Swi_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_knl_Swi_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_knl_Swi_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_knl_Swi_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_knl_Swi_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_knl_Swi_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_knl_Swi_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_knl_Swi_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_knl_Swi_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Swi_Module__startupDone__S( void )
{
    return ti_sysbios_knl_Swi_Module__startupDone__F();
}

/* Handle__label__S */
xdc_runtime_Types_Label *ti_sysbios_knl_Swi_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab) 
{
    lab->handle = obj;
    lab->modId = 32791;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_knl_Swi_Params__init__S( xdc_Ptr prms, const void *src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_CPtr)(src ? src : &ti_sysbios_knl_Swi_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_knl_Swi_Object__get__S(xdc_Ptr oa, xdc_Int i)
{
    if (oa) {
        return ((ti_sysbios_knl_Swi_Object__ *)oa) + i;
    }

    if (ti_sysbios_knl_Swi_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_knl_Swi_Object__ *)ti_sysbios_knl_Swi_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_knl_Swi_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_knl_Swi_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_knl_Swi_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_knl_Swi_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_knl_Swi_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_knl_Swi_Object__create__S (
    xdc_Ptr __obj, 
    xdc_SizeT __osz,
    const xdc_Ptr __aa,
    const ti_sysbios_knl_Swi___ParamsPtr __paramsPtr,
    xdc_SizeT __psz,
    xdc_runtime_Error_Block *__eb)
{
    ti_sysbios_knl_Swi_Args__create *__args = __aa;
    ti_sysbios_knl_Swi_Params __prms;
    ti_sysbios_knl_Swi_Object *__newobj;
    int iStat;

    /* common instance initialization */
    __newobj = xdc_runtime_Core_createObject__I(&ti_sysbios_knl_Swi_Object__DESC__C, __obj, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_knl_Swi_Params), __eb);
    if (__newobj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    iStat = ti_sysbios_knl_Swi_Instance_init__E(__newobj, __args->swiFxn, &__prms, __eb);
    if (xdc_runtime_Error_check(__eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Swi_Object__DESC__C, __newobj, (xdc_Fxn)ti_sysbios_knl_Swi_Instance_finalize__E, iStat, (xdc_Bool)(__obj != NULL));
        return NULL;
    }

    return __newobj;
}

/* create */
ti_sysbios_knl_Swi_Handle ti_sysbios_knl_Swi_create( ti_sysbios_knl_Swi_FuncPtr swiFxn, const ti_sysbios_knl_Swi_Params *__paramsPtr, xdc_runtime_Error_Block *__eb )
{
    ti_sysbios_knl_Swi_Params __prms;
    ti_sysbios_knl_Swi_Object *__newobj;
    int iStat;

    /* common instance initialization */
    __newobj = xdc_runtime_Core_createObject__I(&ti_sysbios_knl_Swi_Object__DESC__C, 0, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_knl_Swi_Params), __eb);
    if (__newobj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    iStat = ti_sysbios_knl_Swi_Instance_init__E(__newobj, swiFxn, &__prms, __eb);
    if (xdc_runtime_Error_check(__eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Swi_Object__DESC__C, __newobj, (xdc_Fxn)ti_sysbios_knl_Swi_Instance_finalize__E, iStat, 0);
        return NULL;
    }

    return __newobj;
}

/* construct */
void ti_sysbios_knl_Swi_construct(ti_sysbios_knl_Swi_Struct *__obj, ti_sysbios_knl_Swi_FuncPtr swiFxn, const ti_sysbios_knl_Swi_Params *__paramsPtr, xdc_runtime_Error_Block *__eb )
{
    ti_sysbios_knl_Swi_Params __prms;
    int iStat;

    /* common instance initialization */
    xdc_runtime_Core_constructObject__I(&ti_sysbios_knl_Swi_Object__DESC__C, __obj, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_knl_Swi_Params), __eb);
    /* module-specific initialization */
    iStat = ti_sysbios_knl_Swi_Instance_init__E((xdc_Ptr)__obj, swiFxn, &__prms, __eb);
    if (xdc_runtime_Error_check(__eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Swi_Object__DESC__C, (xdc_Ptr)__obj, (xdc_Fxn)ti_sysbios_knl_Swi_Instance_finalize__E, iStat, 1);
    }

}

/* Object__destruct__S */
xdc_Void ti_sysbios_knl_Swi_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Swi_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_knl_Swi_Instance_finalize__E, 0, TRUE);
}

/* destruct */
void ti_sysbios_knl_Swi_destruct(ti_sysbios_knl_Swi_Struct *obj)
{
    ti_sysbios_knl_Swi_Object__destruct__S(obj);
}

/* Object__delete__S */
xdc_Void ti_sysbios_knl_Swi_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Swi_Object__DESC__C, *((ti_sysbios_knl_Swi_Object**)instp), (xdc_Fxn)ti_sysbios_knl_Swi_Instance_finalize__E, 0, FALSE);
    *((ti_sysbios_knl_Swi_Handle*)instp) = NULL;
}

/* delete */
void ti_sysbios_knl_Swi_delete(ti_sysbios_knl_Swi_Handle *instp)
{
    ti_sysbios_knl_Swi_Object__delete__S(instp);
}


/*
 * ======== ti.sysbios.knl.Task SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_knl_Task_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_knl_Task_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_knl_Task_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_knl_Task_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_knl_Task_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_knl_Task_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_knl_Task_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_knl_Task_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_knl_Task_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_knl_Task_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_knl_Task_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_knl_Task_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_knl_Task_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_knl_Task_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_knl_Task_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_knl_Task_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_knl_Task_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_knl_Task_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Task_Module__startupDone__S( void )
{
    return ti_sysbios_knl_Task_Module__startupDone__F();
}

/* Handle__label__S */
xdc_runtime_Types_Label *ti_sysbios_knl_Task_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab) 
{
    lab->handle = obj;
    lab->modId = 32792;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_knl_Task_Params__init__S( xdc_Ptr prms, const void *src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_CPtr)(src ? src : &ti_sysbios_knl_Task_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_knl_Task_Object__get__S(xdc_Ptr oa, xdc_Int i)
{
    if (oa) {
        return ((ti_sysbios_knl_Task_Object__ *)oa) + i;
    }

    if (ti_sysbios_knl_Task_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_knl_Task_Object__ *)ti_sysbios_knl_Task_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_knl_Task_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_knl_Task_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_knl_Task_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_knl_Task_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_knl_Task_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_knl_Task_Object__create__S (
    xdc_Ptr __obj, 
    xdc_SizeT __osz,
    const xdc_Ptr __aa,
    const ti_sysbios_knl_Task___ParamsPtr __paramsPtr,
    xdc_SizeT __psz,
    xdc_runtime_Error_Block *__eb)
{
    ti_sysbios_knl_Task_Args__create *__args = __aa;
    ti_sysbios_knl_Task_Params __prms;
    ti_sysbios_knl_Task_Object *__newobj;
    int iStat;

    /* common instance initialization */
    __newobj = xdc_runtime_Core_createObject__I(&ti_sysbios_knl_Task_Object__DESC__C, __obj, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_knl_Task_Params), __eb);
    if (__newobj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    iStat = ti_sysbios_knl_Task_Instance_init__E(__newobj, __args->fxn, &__prms, __eb);
    if (xdc_runtime_Error_check(__eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Task_Object__DESC__C, __newobj, (xdc_Fxn)ti_sysbios_knl_Task_Instance_finalize__E, iStat, (xdc_Bool)(__obj != NULL));
        return NULL;
    }

    return __newobj;
}

/* create */
ti_sysbios_knl_Task_Handle ti_sysbios_knl_Task_create( ti_sysbios_knl_Task_FuncPtr fxn, const ti_sysbios_knl_Task_Params *__paramsPtr, xdc_runtime_Error_Block *__eb )
{
    ti_sysbios_knl_Task_Params __prms;
    ti_sysbios_knl_Task_Object *__newobj;
    int iStat;

    /* common instance initialization */
    __newobj = xdc_runtime_Core_createObject__I(&ti_sysbios_knl_Task_Object__DESC__C, 0, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_knl_Task_Params), __eb);
    if (__newobj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    iStat = ti_sysbios_knl_Task_Instance_init__E(__newobj, fxn, &__prms, __eb);
    if (xdc_runtime_Error_check(__eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Task_Object__DESC__C, __newobj, (xdc_Fxn)ti_sysbios_knl_Task_Instance_finalize__E, iStat, 0);
        return NULL;
    }

    return __newobj;
}

/* construct */
void ti_sysbios_knl_Task_construct(ti_sysbios_knl_Task_Struct *__obj, ti_sysbios_knl_Task_FuncPtr fxn, const ti_sysbios_knl_Task_Params *__paramsPtr, xdc_runtime_Error_Block *__eb )
{
    ti_sysbios_knl_Task_Params __prms;
    int iStat;

    /* common instance initialization */
    xdc_runtime_Core_constructObject__I(&ti_sysbios_knl_Task_Object__DESC__C, __obj, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_knl_Task_Params), __eb);
    /* module-specific initialization */
    iStat = ti_sysbios_knl_Task_Instance_init__E((xdc_Ptr)__obj, fxn, &__prms, __eb);
    if (xdc_runtime_Error_check(__eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Task_Object__DESC__C, (xdc_Ptr)__obj, (xdc_Fxn)ti_sysbios_knl_Task_Instance_finalize__E, iStat, 1);
    }

}

/* Object__destruct__S */
xdc_Void ti_sysbios_knl_Task_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Task_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_knl_Task_Instance_finalize__E, 0, TRUE);
}

/* destruct */
void ti_sysbios_knl_Task_destruct(ti_sysbios_knl_Task_Struct *obj)
{
    ti_sysbios_knl_Task_Object__destruct__S(obj);
}

/* Object__delete__S */
xdc_Void ti_sysbios_knl_Task_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Task_Object__DESC__C, *((ti_sysbios_knl_Task_Object**)instp), (xdc_Fxn)ti_sysbios_knl_Task_Instance_finalize__E, 0, FALSE);
    *((ti_sysbios_knl_Task_Handle*)instp) = NULL;
}

/* delete */
void ti_sysbios_knl_Task_delete(ti_sysbios_knl_Task_Handle *instp)
{
    ti_sysbios_knl_Task_Object__delete__S(instp);
}


/*
 * ======== ti.sysbios.knl.Task_SupportProxy SYSTEM FUNCTIONS ========
 */


xdc_Bool ti_sysbios_knl_Task_SupportProxy_Proxy__abstract__S( void )
{
    return 0;
}
xdc_Ptr ti_sysbios_knl_Task_SupportProxy_Proxy__delegate__S( void )
{
    return 0;
}


/*
 * ======== xdc.runtime.Assert SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Assert_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== xdc.runtime.Core SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Core_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== xdc.runtime.Defaults SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Defaults_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== xdc.runtime.Diags SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Diags_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== xdc.runtime.Error SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Error_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== xdc.runtime.Gate SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Gate_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== xdc.runtime.Log SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Log_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== xdc.runtime.Main SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Main_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== xdc.runtime.Main_Module_GateProxy SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID xdc_runtime_Main_Module_GateProxy_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Main_Module_GateProxy_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Main_Module_GateProxy_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Main_Module_GateProxy_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Main_Module_GateProxy_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Main_Module_GateProxy_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 xdc_runtime_Main_Module_GateProxy_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 xdc_runtime_Main_Module_GateProxy_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 xdc_runtime_Main_Module_GateProxy_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Main_Module_GateProxy_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Main_Module_GateProxy_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_Main_Module_GateProxy_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_Main_Module_GateProxy_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_Main_Module_GateProxy_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_Main_Module_GateProxy_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_Main_Module_GateProxy_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_Main_Module_GateProxy_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_Main_Module_GateProxy_Module_GateProxy_query

xdc_Bool xdc_runtime_Main_Module_GateProxy_Proxy__abstract__S( void )
{
    return 0;
}
xdc_Ptr xdc_runtime_Main_Module_GateProxy_Proxy__delegate__S( void )
{
    return (void *)&ti_sysbios_gates_GateHwi_Module__FXNS__C;
}



/*
 * ======== xdc.runtime.Memory SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Memory_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== xdc.runtime.Memory_HeapProxy SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID xdc_runtime_Memory_HeapProxy_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Memory_HeapProxy_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Memory_HeapProxy_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Memory_HeapProxy_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Memory_HeapProxy_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Memory_HeapProxy_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 xdc_runtime_Memory_HeapProxy_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 xdc_runtime_Memory_HeapProxy_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 xdc_runtime_Memory_HeapProxy_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Memory_HeapProxy_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Memory_HeapProxy_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_Memory_HeapProxy_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_Memory_HeapProxy_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_Memory_HeapProxy_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_Memory_HeapProxy_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_Memory_HeapProxy_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_Memory_HeapProxy_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_Memory_HeapProxy_Module_GateProxy_query

xdc_Bool xdc_runtime_Memory_HeapProxy_Proxy__abstract__S( void )
{
    return 1;
}
xdc_Ptr xdc_runtime_Memory_HeapProxy_Proxy__delegate__S( void )
{
    return (void *)&ti_sysbios_heaps_HeapMem_Module__FXNS__C;
}



/*
 * ======== xdc.runtime.Registry SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Registry_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== xdc.runtime.Startup SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Startup_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== xdc.runtime.SysMin SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_SysMin_Module__startupDone__S( void )
{
    return xdc_runtime_SysMin_Module__startupDone__F();
}



/*
 * ======== xdc.runtime.System SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_System_Module__startupDone__S( void )
{
    return xdc_runtime_System_Module__startupDone__F();
}



/*
 * ======== xdc.runtime.System_Module_GateProxy SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID xdc_runtime_System_Module_GateProxy_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_System_Module_GateProxy_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_System_Module_GateProxy_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_System_Module_GateProxy_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_System_Module_GateProxy_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_System_Module_GateProxy_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 xdc_runtime_System_Module_GateProxy_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 xdc_runtime_System_Module_GateProxy_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 xdc_runtime_System_Module_GateProxy_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_System_Module_GateProxy_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_System_Module_GateProxy_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_System_Module_GateProxy_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_System_Module_GateProxy_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_System_Module_GateProxy_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_System_Module_GateProxy_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_System_Module_GateProxy_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_System_Module_GateProxy_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_System_Module_GateProxy_Module_GateProxy_query

xdc_Bool xdc_runtime_System_Module_GateProxy_Proxy__abstract__S( void )
{
    return 0;
}
xdc_Ptr xdc_runtime_System_Module_GateProxy_Proxy__delegate__S( void )
{
    return (void *)&ti_sysbios_gates_GateHwi_Module__FXNS__C;
}



/*
 * ======== xdc.runtime.System_SupportProxy SYSTEM FUNCTIONS ========
 */


xdc_Bool xdc_runtime_System_SupportProxy_Proxy__abstract__S( void )
{
    return 0;
}
xdc_Ptr xdc_runtime_System_SupportProxy_Proxy__delegate__S( void )
{
    return (void *)&xdc_runtime_SysMin_Module__FXNS__C;
}


/*
 * ======== xdc.runtime.Text SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Text_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== INITIALIZATION ENTRY POINT ========
 */

extern int __xdc__init(void);
#ifdef __GNUC__
#ifndef __TI_COMPILER_VERSION__
    __attribute__ ((externally_visible))
#endif
#endif
__FAR__ int (* volatile __xdc__init__addr)(void) = &__xdc__init;


/*
 * ======== PROGRAM GLOBALS ========
 */

