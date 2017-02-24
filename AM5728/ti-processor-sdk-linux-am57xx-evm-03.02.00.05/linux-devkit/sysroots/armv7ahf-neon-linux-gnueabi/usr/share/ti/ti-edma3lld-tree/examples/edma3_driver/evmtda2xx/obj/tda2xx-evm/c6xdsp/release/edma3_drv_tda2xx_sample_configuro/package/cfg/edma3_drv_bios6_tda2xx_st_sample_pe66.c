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
#include <ti/sysbios/family/c62/IntrinsicsSupport.h>
#include <ti/sysbios/family/c62/TaskSupport.h>
#include <ti/sysbios/family/c64p/EventCombiner.h>
#include <ti/sysbios/family/c64p/Exception.h>
#include <ti/sysbios/family/c64p/Hwi.h>
#include <ti/sysbios/family/c64p/TimestampProvider.h>
#include <ti/sysbios/family/c66/Cache.h>
#include <ti/sysbios/family/shared/vayu/IntXbar.h>
#include <ti/sysbios/family/shared/vayu/TimerSupport.h>
#include <ti/sysbios/gates/GateHwi.h>
#include <ti/sysbios/gates/GateMutex.h>
#include <ti/sysbios/hal/Cache.h>
#include <ti/sysbios/hal/Hwi.h>
#include <ti/sysbios/hal/TimerNull.h>
#include <ti/sysbios/heaps/HeapMem.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Idle.h>
#include <ti/sysbios/knl/Intrinsics.h>
#include <ti/sysbios/knl/Queue.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/knl/Swi.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/rts/ti/ThreadLocalStorage.h>
#include <ti/sysbios/timers/dmtimer/Timer.h>
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
#include <xdc/runtime/Timestamp.h>
#include <xdc/runtime/TimestampNull.h>

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
 * ======== ti.sysbios.family.c62.IntrinsicsSupport INTERNALS ========
 */


/*
 * ======== ti.sysbios.family.c62.TaskSupport INTERNALS ========
 */


/*
 * ======== ti.sysbios.family.c64p.EventCombiner INTERNALS ========
 */


/*
 * ======== ti.sysbios.family.c64p.Exception INTERNALS ========
 */


/*
 * ======== ti.sysbios.family.c64p.Hwi INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_family_c64p_Hwi_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_family_c64p_Hwi_Module__;

/* Module__root__V */
extern ti_sysbios_family_c64p_Hwi_Module__ ti_sysbios_family_c64p_Hwi_Module__root__V;

/* Object__ */
typedef struct ti_sysbios_family_c64p_Hwi_Object__ {
    const ti_sysbios_family_c64p_Hwi_Fxns__ *__fxns;
    xdc_Bits16 disableMask;
    xdc_Bits16 restoreMask;
    xdc_UArg arg;
    ti_sysbios_family_c64p_Hwi_FuncPtr fxn;
    ti_sysbios_family_c64p_Hwi_Irp irp;
    __TA_ti_sysbios_family_c64p_Hwi_Instance_State__hookEnv hookEnv;
} ti_sysbios_family_c64p_Hwi_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_family_c64p_Hwi_Object__ obj;
} ti_sysbios_family_c64p_Hwi_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_family_c64p_Hwi___VERS
    #define ti_sysbios_family_c64p_Hwi___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_family_c64p_Hwi___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.family.c64p.TimestampProvider INTERNALS ========
 */


/*
 * ======== ti.sysbios.family.c66.Cache INTERNALS ========
 */


/*
 * ======== ti.sysbios.family.shared.vayu.IntXbar INTERNALS ========
 */


/*
 * ======== ti.sysbios.family.shared.vayu.TimerSupport INTERNALS ========
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

/* <-- ti_sysbios_family_c64p_Hwi_Object */

/* Object */
typedef ti_sysbios_family_c64p_Hwi_Object__ ti_sysbios_hal_Hwi_HwiProxy_Object__;

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
 * ======== ti.sysbios.hal.TimerNull INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_hal_TimerNull_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_hal_TimerNull_Module__;

/* Module__root__V */
extern ti_sysbios_hal_TimerNull_Module__ ti_sysbios_hal_TimerNull_Module__root__V;

/* Object__ */
typedef struct ti_sysbios_hal_TimerNull_Object__ {
    const ti_sysbios_hal_TimerNull_Fxns__ *__fxns;
} ti_sysbios_hal_TimerNull_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_hal_TimerNull_Object__ obj;
} ti_sysbios_hal_TimerNull_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_hal_TimerNull___VERS
    #define ti_sysbios_hal_TimerNull___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_hal_TimerNull___ParamsPtr xdc_Ptr
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

/* <-- ti_sysbios_hal_TimerNull_Object */

/* Object */
typedef ti_sysbios_hal_TimerNull_Object__ ti_sysbios_knl_Clock_TimerProxy_Object__;

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
 * ======== ti.sysbios.rts.ti.ThreadLocalStorage INTERNALS ========
 */


/*
 * ======== ti.sysbios.timers.dmtimer.Timer INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_timers_dmtimer_Timer_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_timers_dmtimer_Timer_Module__;

/* Module__root__V */
extern ti_sysbios_timers_dmtimer_Timer_Module__ ti_sysbios_timers_dmtimer_Timer_Module__root__V;

/* Object__ */
typedef struct ti_sysbios_timers_dmtimer_Timer_Object__ {
    const ti_sysbios_timers_dmtimer_Timer_Fxns__ *__fxns;
    xdc_Bool staticInst;
    xdc_Int id;
    xdc_UInt tiocpCfg;
    xdc_UInt tmar;
    xdc_UInt tier;
    xdc_UInt twer;
    xdc_UInt tclr;
    xdc_UInt tsicr;
    ti_sysbios_interfaces_ITimer_RunMode runMode;
    ti_sysbios_interfaces_ITimer_StartMode startMode;
    xdc_UInt period;
    ti_sysbios_interfaces_ITimer_PeriodType periodType;
    xdc_UInt intNum;
    xdc_Int eventId;
    xdc_UArg arg;
    ti_sysbios_hal_Hwi_FuncPtr tickFxn;
    xdc_runtime_Types_FreqHz extFreq;
    ti_sysbios_hal_Hwi_Handle hwi;
    xdc_UInt prevThreshold;
    xdc_UInt rollovers;
    xdc_UInt savedCurrCount;
    xdc_Bool useDefaultEventId;
} ti_sysbios_timers_dmtimer_Timer_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_timers_dmtimer_Timer_Object__ obj;
} ti_sysbios_timers_dmtimer_Timer_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_timers_dmtimer_Timer___VERS
    #define ti_sysbios_timers_dmtimer_Timer___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_timers_dmtimer_Timer___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.timers.dmtimer.Timer_TimerSupportProxy INTERNALS ========
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
 * ======== xdc.runtime.Timestamp INTERNALS ========
 */


/*
 * ======== xdc.runtime.TimestampNull INTERNALS ========
 */


/*
 * ======== xdc.runtime.Timestamp_SupportProxy INTERNALS ========
 */


/*
 * ======== INHERITS ========
 */

#pragma DATA_SECTION(xdc_runtime_IHeap_Interface__BASE__C, ".const:xdc_runtime_IHeap_Interface__BASE__C");
__FAR__ const xdc_runtime_Types_Base xdc_runtime_IHeap_Interface__BASE__C = {(void *)&xdc_runtime_IModule_Interface__BASE__C};

#pragma DATA_SECTION(xdc_runtime_ISystemSupport_Interface__BASE__C, ".const:xdc_runtime_ISystemSupport_Interface__BASE__C");
__FAR__ const xdc_runtime_Types_Base xdc_runtime_ISystemSupport_Interface__BASE__C = {(void *)&xdc_runtime_IModule_Interface__BASE__C};

#pragma DATA_SECTION(ti_sysbios_interfaces_ITimer_Interface__BASE__C, ".const:ti_sysbios_interfaces_ITimer_Interface__BASE__C");
__FAR__ const xdc_runtime_Types_Base ti_sysbios_interfaces_ITimer_Interface__BASE__C = {(void *)&xdc_runtime_IModule_Interface__BASE__C};

#pragma DATA_SECTION(xdc_runtime_ITimestampProvider_Interface__BASE__C, ".const:xdc_runtime_ITimestampProvider_Interface__BASE__C");
__FAR__ const xdc_runtime_Types_Base xdc_runtime_ITimestampProvider_Interface__BASE__C = {(void *)&xdc_runtime_ITimestampClient_Interface__BASE__C};

#pragma DATA_SECTION(xdc_runtime_IGateProvider_Interface__BASE__C, ".const:xdc_runtime_IGateProvider_Interface__BASE__C");
__FAR__ const xdc_runtime_Types_Base xdc_runtime_IGateProvider_Interface__BASE__C = {(void *)&xdc_runtime_IModule_Interface__BASE__C};

#pragma DATA_SECTION(xdc_runtime_IModule_Interface__BASE__C, ".const:xdc_runtime_IModule_Interface__BASE__C");
__FAR__ const xdc_runtime_Types_Base xdc_runtime_IModule_Interface__BASE__C = {0};

#pragma DATA_SECTION(xdc_runtime_ITimestampClient_Interface__BASE__C, ".const:xdc_runtime_ITimestampClient_Interface__BASE__C");
__FAR__ const xdc_runtime_Types_Base xdc_runtime_ITimestampClient_Interface__BASE__C = {(void *)&xdc_runtime_IModule_Interface__BASE__C};


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
        0x8036, /* __mid */
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
        0x8037, /* __mid */
    } /* __sfxns */
};


/*
 * ======== ti.sysbios.hal.TimerNull VTABLE ========
 */

/* Module__FXNS__C */
#pragma DATA_SECTION(ti_sysbios_hal_TimerNull_Module__FXNS__C, ".const:ti_sysbios_hal_TimerNull_Module__FXNS__C");
const ti_sysbios_hal_TimerNull_Fxns__ ti_sysbios_hal_TimerNull_Module__FXNS__C = {
    (void *)&ti_sysbios_interfaces_ITimer_Interface__BASE__C, /* __base */
    &ti_sysbios_hal_TimerNull_Module__FXNS__C.__sfxns, /* __sysp */
    ti_sysbios_hal_TimerNull_getNumTimers__E,
    ti_sysbios_hal_TimerNull_getStatus__E,
    ti_sysbios_hal_TimerNull_startup__E,
    ti_sysbios_hal_TimerNull_getMaxTicks__E,
    ti_sysbios_hal_TimerNull_setNextTick__E,
    ti_sysbios_hal_TimerNull_start__E,
    ti_sysbios_hal_TimerNull_stop__E,
    ti_sysbios_hal_TimerNull_setPeriod__E,
    ti_sysbios_hal_TimerNull_setPeriodMicroSecs__E,
    ti_sysbios_hal_TimerNull_getPeriod__E,
    ti_sysbios_hal_TimerNull_getCount__E,
    ti_sysbios_hal_TimerNull_getFreq__E,
    ti_sysbios_hal_TimerNull_getFunc__E,
    ti_sysbios_hal_TimerNull_setFunc__E,
    ti_sysbios_hal_TimerNull_trigger__E,
    ti_sysbios_hal_TimerNull_getExpiredCounts__E,
    ti_sysbios_hal_TimerNull_getExpiredTicks__E,
    ti_sysbios_hal_TimerNull_getCurrentTick__E,
    {
        ti_sysbios_hal_TimerNull_Object__create__S,
        ti_sysbios_hal_TimerNull_Object__delete__S,
        ti_sysbios_hal_TimerNull_Handle__label__S,
        0x8025, /* __mid */
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
        0x8039, /* __mid */
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
 * ======== xdc.runtime.Timestamp VTABLE ========
 */

/* Module__FXNS__C */
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__FXNS__C, ".const:xdc_runtime_Timestamp_Module__FXNS__C");
const xdc_runtime_Timestamp_Fxns__ xdc_runtime_Timestamp_Module__FXNS__C = {
    (void *)&xdc_runtime_ITimestampClient_Interface__BASE__C, /* __base */
    &xdc_runtime_Timestamp_Module__FXNS__C.__sfxns, /* __sysp */
    xdc_runtime_Timestamp_get32__E,
    xdc_runtime_Timestamp_get64__E,
    xdc_runtime_Timestamp_getFreq__E,
    {
        NULL, /* __create */
        NULL, /* __delete */
        NULL, /* __label */
        0x8010, /* __mid */
    } /* __sfxns */
};


/*
 * ======== xdc.runtime.TimestampNull VTABLE ========
 */

/* Module__FXNS__C */
#pragma DATA_SECTION(xdc_runtime_TimestampNull_Module__FXNS__C, ".const:xdc_runtime_TimestampNull_Module__FXNS__C");
const xdc_runtime_TimestampNull_Fxns__ xdc_runtime_TimestampNull_Module__FXNS__C = {
    (void *)&xdc_runtime_ITimestampProvider_Interface__BASE__C, /* __base */
    &xdc_runtime_TimestampNull_Module__FXNS__C.__sfxns, /* __sysp */
    xdc_runtime_TimestampNull_get32__E,
    xdc_runtime_TimestampNull_get64__E,
    xdc_runtime_TimestampNull_getFreq__E,
    {
        NULL, /* __create */
        NULL, /* __delete */
        NULL, /* __label */
        0x8011, /* __mid */
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
 * ======== ti.sysbios.family.c62.IntrinsicsSupport DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.family.c62.TaskSupport DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.family.c64p.EventCombiner DECLARATIONS ========
 */

/* Module_State__ */
typedef struct ti_sysbios_family_c64p_EventCombiner_Module_State__ {
    __TA_ti_sysbios_family_c64p_EventCombiner_Module_State__dispatchTab dispatchTab;
} ti_sysbios_family_c64p_EventCombiner_Module_State__;

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_unused */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_unused(xdc_UArg);

/* Module__state__V */
ti_sysbios_family_c64p_EventCombiner_Module_State__ ti_sysbios_family_c64p_EventCombiner_Module__state__V;


/*
 * ======== ti.sysbios.family.c64p.Exception DECLARATIONS ========
 */

/* Module_State__ */
typedef struct ti_sysbios_family_c64p_Exception_Module_State__ {
    xdc_Bits32 efr;
    xdc_Bits32 nrp;
    xdc_Bits32 ntsr;
    xdc_Bits32 ierr;
    ti_sysbios_family_c64p_Exception_FuncPtr returnHook;
    ti_sysbios_family_c64p_Exception_Context *excContext;
    __TA_ti_sysbios_family_c64p_Exception_Module_State__scratch scratch;
    xdc_Char *excPtr;
    __TA_ti_sysbios_family_c64p_Exception_Module_State__contextBuf contextBuf;
} ti_sysbios_family_c64p_Exception_Module_State__;

/* Module__state__V */
ti_sysbios_family_c64p_Exception_Module_State__ ti_sysbios_family_c64p_Exception_Module__state__V;


/*
 * ======== ti.sysbios.family.c64p.Hwi DECLARATIONS ========
 */

/* --> ti_sysbios_family_c64p_EventCombiner_dispatch */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_dispatch(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_dispatch */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_dispatch(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_dispatch */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_dispatch(xdc_UArg);

/* --> ti_sysbios_family_c64p_EventCombiner_dispatch */
extern xdc_Void ti_sysbios_family_c64p_EventCombiner_dispatch(xdc_UArg);

/* Object__table__V */
ti_sysbios_family_c64p_Hwi_Object__ ti_sysbios_family_c64p_Hwi_Object__table__V[5];

/* Module_State__ */
typedef struct ti_sysbios_family_c64p_Hwi_Module_State__ {
    __TA_ti_sysbios_family_c64p_Hwi_Module_State__intEvents intEvents;
    xdc_Bits16 ierMask;
    volatile xdc_Int intNum;
    xdc_Char *taskSP;
    xdc_Char *isrStack;
    xdc_Ptr vectorTableBase;
    xdc_Ptr bss;
    xdc_Int scw;
    __TA_ti_sysbios_family_c64p_Hwi_Module_State__dispatchTable dispatchTable;
} ti_sysbios_family_c64p_Hwi_Module_State__;

/* --> ti_sysbios_family_c64p_Hwi0 */
extern void* ti_sysbios_family_c64p_Hwi0;

/* --> __TI_STATIC_BASE */
extern void* __TI_STATIC_BASE;

/* Module__state__V */
ti_sysbios_family_c64p_Hwi_Module_State__ ti_sysbios_family_c64p_Hwi_Module__state__V;

/* --> ti_sysbios_knl_Swi_disable__E */
extern xdc_UInt ti_sysbios_knl_Swi_disable__E(xdc_Void);

/* --> ti_sysbios_knl_Swi_restoreHwi__E */
extern xdc_Void ti_sysbios_knl_Swi_restoreHwi__E(xdc_UInt);

/* --> ti_sysbios_knl_Task_disable__E */
extern xdc_UInt ti_sysbios_knl_Task_disable__E(xdc_Void);

/* --> ti_sysbios_knl_Task_restoreHwi__E */
extern xdc_Void ti_sysbios_knl_Task_restoreHwi__E(xdc_UInt);


/*
 * ======== ti.sysbios.family.c64p.TimestampProvider DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.family.c66.Cache DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.family.shared.vayu.IntXbar DECLARATIONS ========
 */

/* Module_State__ */
typedef struct ti_sysbios_family_shared_vayu_IntXbar_Module_State__ {
    __TA_ti_sysbios_family_shared_vayu_IntXbar_Module_State__intXbar intXbar;
} ti_sysbios_family_shared_vayu_IntXbar_Module_State__;

/* --> ti_sysbios_family_shared_vayu_IntXbar_Module_State_0_intXbar__A */
__T1_ti_sysbios_family_shared_vayu_IntXbar_Module_State__intXbar ti_sysbios_family_shared_vayu_IntXbar_Module_State_0_intXbar__A[64];

/* Module__state__V */
ti_sysbios_family_shared_vayu_IntXbar_Module_State__ ti_sysbios_family_shared_vayu_IntXbar_Module__state__V;

/* --> ti_sysbios_family_shared_vayu_IntXbar_intXbar__A */
const __T1_ti_sysbios_family_shared_vayu_IntXbar_intXbar ti_sysbios_family_shared_vayu_IntXbar_intXbar__A[64];


/*
 * ======== ti.sysbios.family.shared.vayu.TimerSupport DECLARATIONS ========
 */


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

/* Object__table__V */
ti_sysbios_hal_Hwi_Object__ ti_sysbios_hal_Hwi_Object__table__V[1];


/*
 * ======== ti.sysbios.hal.Hwi_HwiProxy DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.hal.TimerNull DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.heaps.HeapMem DECLARATIONS ========
 */

#ifdef __IAR_SYSTEMS_ICC__
    #pragma data_alignment=8
#endif
/* --> ti_sysbios_heaps_HeapMem_Instance_State_0_buf__A */
__T1_ti_sysbios_heaps_HeapMem_Instance_State__buf ti_sysbios_heaps_HeapMem_Instance_State_0_buf__A[4096];
#ifdef __ti__align
    #pragma DATA_ALIGN(ti_sysbios_heaps_HeapMem_Instance_State_0_buf__A, 8);
#endif
#ifdef __GNUC__
#ifndef __TI_COMPILER_VERSION__
__T1_ti_sysbios_heaps_HeapMem_Instance_State__buf ti_sysbios_heaps_HeapMem_Instance_State_0_buf__A[4096] __attribute__ ((aligned(8)));
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

/* --> ti_sysbios_hal_Hwi_checkStack */
extern xdc_Void ti_sysbios_hal_Hwi_checkStack(xdc_Void);

/* --> ti_sysbios_knl_Idle_funcList__A */
const __T1_ti_sysbios_knl_Idle_funcList ti_sysbios_knl_Idle_funcList__A[1];

/* --> ti_sysbios_knl_Idle_coreList__A */
const __T1_ti_sysbios_knl_Idle_coreList ti_sysbios_knl_Idle_coreList__A[1];


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
    #pragma DATA_SECTION(ti_sysbios_knl_Task_Instance_State_0_stack__A, ".far:taskStackSection");
#endif
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
#ifndef __TI_COMPILER_VERSION__
__T1_ti_sysbios_knl_Task_Instance_State__stack ti_sysbios_knl_Task_Instance_State_0_stack__A[2048] __attribute__ ((section(".far:taskStackSection")));
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
 * ======== ti.sysbios.rts.ti.ThreadLocalStorage DECLARATIONS ========
 */

/* Module_State__ */
typedef struct ti_sysbios_rts_ti_ThreadLocalStorage_Module_State__ {
    xdc_Ptr currentTP;
    xdc_UInt contextId;
    xdc_runtime_IHeap_Handle heapHandle;
} ti_sysbios_rts_ti_ThreadLocalStorage_Module_State__;

/* Module__state__V */
ti_sysbios_rts_ti_ThreadLocalStorage_Module_State__ ti_sysbios_rts_ti_ThreadLocalStorage_Module__state__V;


/*
 * ======== ti.sysbios.timers.dmtimer.Timer DECLARATIONS ========
 */

/* --> mainDsp1TimerTick */
extern xdc_Void mainDsp1TimerTick(xdc_UArg);

/* Object__table__V */
ti_sysbios_timers_dmtimer_Timer_Object__ ti_sysbios_timers_dmtimer_Timer_Object__table__V[1];

/* Module_State__ */
typedef struct ti_sysbios_timers_dmtimer_Timer_Module_State__ {
    xdc_Bits32 availMask;
    __TA_ti_sysbios_timers_dmtimer_Timer_Module_State__intFreqs intFreqs;
    __TA_ti_sysbios_timers_dmtimer_Timer_Module_State__device device;
    __TA_ti_sysbios_timers_dmtimer_Timer_Module_State__handles handles;
    xdc_Bool firstInit;
} ti_sysbios_timers_dmtimer_Timer_Module_State__;

/* --> ti_sysbios_timers_dmtimer_Timer_Module_State_0_intFreqs__A */
__T1_ti_sysbios_timers_dmtimer_Timer_Module_State__intFreqs ti_sysbios_timers_dmtimer_Timer_Module_State_0_intFreqs__A[16];

/* --> ti_sysbios_timers_dmtimer_Timer_Module_State_0_device__A */
__T1_ti_sysbios_timers_dmtimer_Timer_Module_State__device ti_sysbios_timers_dmtimer_Timer_Module_State_0_device__A[16];

/* --> ti_sysbios_timers_dmtimer_Timer_Module_State_0_handles__A */
__T1_ti_sysbios_timers_dmtimer_Timer_Module_State__handles ti_sysbios_timers_dmtimer_Timer_Module_State_0_handles__A[16];

/* Module__state__V */
ti_sysbios_timers_dmtimer_Timer_Module_State__ ti_sysbios_timers_dmtimer_Timer_Module__state__V;


/*
 * ======== ti.sysbios.timers.dmtimer.Timer_TimerSupportProxy DECLARATIONS ========
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

/* --> ti_sysbios_hal_Hwi_initStack */
extern xdc_Void ti_sysbios_hal_Hwi_initStack(xdc_Void);

/* --> xdc_runtime_Startup_firstFxns__A */
const __T1_xdc_runtime_Startup_firstFxns xdc_runtime_Startup_firstFxns__A[3];

/* --> xdc_runtime_System_Module_startup__E */
extern xdc_Int xdc_runtime_System_Module_startup__E(xdc_Int);

/* --> xdc_runtime_SysMin_Module_startup__E */
extern xdc_Int xdc_runtime_SysMin_Module_startup__E(xdc_Int);

/* --> ti_sysbios_family_c64p_EventCombiner_Module_startup__E */
extern xdc_Int ti_sysbios_family_c64p_EventCombiner_Module_startup__E(xdc_Int);

/* --> ti_sysbios_family_c64p_Exception_Module_startup__E */
extern xdc_Int ti_sysbios_family_c64p_Exception_Module_startup__E(xdc_Int);

/* --> ti_sysbios_family_c64p_Hwi_Module_startup__E */
extern xdc_Int ti_sysbios_family_c64p_Hwi_Module_startup__E(xdc_Int);

/* --> ti_sysbios_family_c64p_TimestampProvider_Module_startup__E */
extern xdc_Int ti_sysbios_family_c64p_TimestampProvider_Module_startup__E(xdc_Int);

/* --> ti_sysbios_knl_Clock_Module_startup__E */
extern xdc_Int ti_sysbios_knl_Clock_Module_startup__E(xdc_Int);

/* --> ti_sysbios_knl_Swi_Module_startup__E */
extern xdc_Int ti_sysbios_knl_Swi_Module_startup__E(xdc_Int);

/* --> ti_sysbios_knl_Task_Module_startup__E */
extern xdc_Int ti_sysbios_knl_Task_Module_startup__E(xdc_Int);

/* --> ti_sysbios_hal_Hwi_Module_startup__E */
extern xdc_Int ti_sysbios_hal_Hwi_Module_startup__E(xdc_Int);

/* --> ti_sysbios_family_c66_Cache_Module_startup__E */
extern xdc_Int ti_sysbios_family_c66_Cache_Module_startup__E(xdc_Int);

/* --> ti_sysbios_family_shared_vayu_TimerSupport_Module_startup__E */
extern xdc_Int ti_sysbios_family_shared_vayu_TimerSupport_Module_startup__E(xdc_Int);

/* --> ti_sysbios_timers_dmtimer_Timer_Module_startup__E */
extern xdc_Int ti_sysbios_timers_dmtimer_Timer_Module_startup__E(xdc_Int);

/* --> xdc_runtime_Startup_sfxnTab__A */
const __T1_xdc_runtime_Startup_sfxnTab xdc_runtime_Startup_sfxnTab__A[13];

/* --> xdc_runtime_Startup_sfxnRts__A */
const __T1_xdc_runtime_Startup_sfxnRts xdc_runtime_Startup_sfxnRts__A[13];


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
const __T1_xdc_runtime_Text_charTab xdc_runtime_Text_charTab__A[7354];

/* --> xdc_runtime_Text_nodeTab__A */
const __T1_xdc_runtime_Text_nodeTab xdc_runtime_Text_nodeTab__A[58];


/*
 * ======== xdc.runtime.Timestamp DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.TimestampNull DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Timestamp_SupportProxy DECLARATIONS ========
 */


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
xdc__META(__ASM__, "@(#)__ASM__ = /home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/work/am57xx_evm-linux-gnueabi/edma3-lld-rtos/2.12.02.26-r0.0/git/examples/edma3_driver/evmtda2xx/obj/tda2xx-evm/c6xdsp/release/edma3_drv_tda2xx_sample_configuro/package/cfg/edma3_drv_bios6_tda2xx_st_sample_pe66");

/*
 *  ======== __ISA__ ========
 *  Define the ISA of this executable.  This symbol is used by platform
 *  specific "exec" commands that support more than one ISA; e.g., gdb
 */
xdc__META(__ISA__, "@(#)__ISA__ = 66");

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
xdc__META(__TARG__, "@(#)__TARG__ = ti.targets.elf.C66");

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
xdc_Bool ti_sysbios_family_c64p_EventCombiner_Module__startupDone__F(void); /* keep GCC prototype warning quiet */
xdc_Bool ti_sysbios_family_c64p_EventCombiner_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[2] < 0;
}
xdc_Bool ti_sysbios_family_c64p_Exception_Module__startupDone__F(void); /* keep GCC prototype warning quiet */
xdc_Bool ti_sysbios_family_c64p_Exception_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[3] < 0;
}
xdc_Bool ti_sysbios_family_c64p_Hwi_Module__startupDone__F(void); /* keep GCC prototype warning quiet */
xdc_Bool ti_sysbios_family_c64p_Hwi_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[4] < 0;
}
xdc_Bool ti_sysbios_family_c64p_TimestampProvider_Module__startupDone__F(void); /* keep GCC prototype warning quiet */
xdc_Bool ti_sysbios_family_c64p_TimestampProvider_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[5] < 0;
}
xdc_Bool ti_sysbios_knl_Clock_Module__startupDone__F(void); /* keep GCC prototype warning quiet */
xdc_Bool ti_sysbios_knl_Clock_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[6] < 0;
}
xdc_Bool ti_sysbios_knl_Swi_Module__startupDone__F(void); /* keep GCC prototype warning quiet */
xdc_Bool ti_sysbios_knl_Swi_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[7] < 0;
}
xdc_Bool ti_sysbios_knl_Task_Module__startupDone__F(void); /* keep GCC prototype warning quiet */
xdc_Bool ti_sysbios_knl_Task_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[8] < 0;
}
xdc_Bool ti_sysbios_hal_Hwi_Module__startupDone__F(void); /* keep GCC prototype warning quiet */
xdc_Bool ti_sysbios_hal_Hwi_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[9] < 0;
}
xdc_Bool ti_sysbios_family_c66_Cache_Module__startupDone__F(void); /* keep GCC prototype warning quiet */
xdc_Bool ti_sysbios_family_c66_Cache_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[10] < 0;
}
xdc_Bool ti_sysbios_family_shared_vayu_TimerSupport_Module__startupDone__F(void); /* keep GCC prototype warning quiet */
xdc_Bool ti_sysbios_family_shared_vayu_TimerSupport_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[11] < 0;
}
xdc_Bool ti_sysbios_timers_dmtimer_Timer_Module__startupDone__F(void); /* keep GCC prototype warning quiet */
xdc_Bool ti_sysbios_timers_dmtimer_Timer_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[12] < 0;
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
    xdc_Int state[13];
    xdc_runtime_Startup_startModsFxn__C(state, 13);
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

extern xdc_Void ti_sysbios_family_c66_Cache_startup__I(void);  /* user defined reset function */

/*
 *  ======== xdc_runtime_Startup_reset__I ========
 *  This function is called by bootstrap initialization code as early as
 *  possible in the startup process.  This function calls all functions in
 *  the Reset.fxns array _as well as_ Startup.resetFxn (if it's non-NULL)
 */
xdc_Void xdc_runtime_Startup_reset__I(void)
{
    ti_sysbios_family_c66_Cache_startup__I();
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
 * ======== ti.sysbios.family.c64p.Hwi TEMPLATE ========
 */


asm("           .sect \".vecs\"         ");
asm("           .align 0x400            ");
asm("           .nocmp                  ");
asm("           .global ti_sysbios_family_c64p_Hwi0          ");
asm("ti_sysbios_family_c64p_Hwi0:                            ");
asm("           .global ti_sysbios_family_c64p_Hwi_int0         ");
asm("           .global _c_int00         ");
asm("ti_sysbios_family_c64p_Hwi_int0:                           ");
asm("           nop                     ");
asm("           nop                     ");
asm("           nop                     ");
asm("           mvkl    _c_int00, b0     ");
asm("           mvkh    _c_int00, b0     ");
asm("           b       b0              ");
asm("           nop                     ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi_int1         ");
asm("           .global ti_sysbios_family_c64p_Exception_dispatch__E         ");
asm("ti_sysbios_family_c64p_Hwi_int1:                           ");
asm("           stw     b0, *b15--[2]   ");
asm("           mvk     1, b0         ");
asm("           stw     b0, *b15[1]     ");
asm("           mvkl    ti_sysbios_family_c64p_Exception_dispatch__E, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Exception_dispatch__E, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15[2], b0   ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi_int2         ");
asm("           .global ti_sysbios_family_c64p_Hwi_int2         ");
asm("ti_sysbios_family_c64p_Hwi_int2:                           ");
asm("           stw     b0, *b15--[2]   ");
asm("           mvk     2, b0         ");
asm("           stw     b0, *b15[1]     ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi_int2, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi_int2, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15[2], b0   ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi_int3         ");
asm("           .global ti_sysbios_family_c64p_Hwi_int3         ");
asm("ti_sysbios_family_c64p_Hwi_int3:                           ");
asm("           stw     b0, *b15--[2]   ");
asm("           mvk     3, b0         ");
asm("           stw     b0, *b15[1]     ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi_int3, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi_int3, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15[2], b0   ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi_int4         ");
asm("           .global ti_sysbios_family_c64p_Hwi_int4         ");
asm("ti_sysbios_family_c64p_Hwi_int4:                           ");
asm("           stw     b0, *b15--[2]   ");
asm("           mvk     4, b0         ");
asm("           stw     b0, *b15[1]     ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi_int4, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi_int4, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15[2], b0   ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi_int5         ");
asm("           .global ti_sysbios_family_c64p_Hwi_int5         ");
asm("ti_sysbios_family_c64p_Hwi_int5:                           ");
asm("           stw     b0, *b15--[2]   ");
asm("           mvk     5, b0         ");
asm("           stw     b0, *b15[1]     ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi_int5, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi_int5, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15[2], b0   ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi_int6         ");
asm("           .global ti_sysbios_family_c64p_Hwi_int6         ");
asm("ti_sysbios_family_c64p_Hwi_int6:                           ");
asm("           stw     b0, *b15--[2]   ");
asm("           mvk     6, b0         ");
asm("           stw     b0, *b15[1]     ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi_int6, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi_int6, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15[2], b0   ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi_int7         ");
asm("           .global ti_sysbios_family_c64p_Hwi_dispatchAlways         ");
asm("ti_sysbios_family_c64p_Hwi_int7:                           ");
asm("           stw     b0, *b15--[2]   ");
asm("           mvk     7, b0         ");
asm("           stw     b0, *b15[1]     ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi_dispatchAlways, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi_dispatchAlways, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15[2], b0   ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi_int8         ");
asm("           .global ti_sysbios_family_c64p_Hwi_dispatchAlways         ");
asm("ti_sysbios_family_c64p_Hwi_int8:                           ");
asm("           stw     b0, *b15--[2]   ");
asm("           mvk     8, b0         ");
asm("           stw     b0, *b15[1]     ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi_dispatchAlways, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi_dispatchAlways, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15[2], b0   ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi_int9         ");
asm("           .global ti_sysbios_family_c64p_Hwi_dispatchAlways         ");
asm("ti_sysbios_family_c64p_Hwi_int9:                           ");
asm("           stw     b0, *b15--[2]   ");
asm("           mvk     9, b0         ");
asm("           stw     b0, *b15[1]     ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi_dispatchAlways, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi_dispatchAlways, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15[2], b0   ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi_int10         ");
asm("           .global ti_sysbios_family_c64p_Hwi_dispatchAlways         ");
asm("ti_sysbios_family_c64p_Hwi_int10:                           ");
asm("           stw     b0, *b15--[2]   ");
asm("           mvk     10, b0         ");
asm("           stw     b0, *b15[1]     ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi_dispatchAlways, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi_dispatchAlways, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15[2], b0   ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi_int11         ");
asm("           .global ti_sysbios_family_c64p_Hwi_int11         ");
asm("ti_sysbios_family_c64p_Hwi_int11:                           ");
asm("           stw     b0, *b15--[2]   ");
asm("           mvk     11, b0         ");
asm("           stw     b0, *b15[1]     ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi_int11, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi_int11, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15[2], b0   ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi_int12         ");
asm("           .global ti_sysbios_family_c64p_Hwi_int12         ");
asm("ti_sysbios_family_c64p_Hwi_int12:                           ");
asm("           stw     b0, *b15--[2]   ");
asm("           mvk     12, b0         ");
asm("           stw     b0, *b15[1]     ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi_int12, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi_int12, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15[2], b0   ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi_int13         ");
asm("           .global ti_sysbios_family_c64p_Hwi_int13         ");
asm("ti_sysbios_family_c64p_Hwi_int13:                           ");
asm("           stw     b0, *b15--[2]   ");
asm("           mvk     13, b0         ");
asm("           stw     b0, *b15[1]     ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi_int13, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi_int13, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15[2], b0   ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi_int14         ");
asm("           .global ti_sysbios_family_c64p_Hwi_int14         ");
asm("ti_sysbios_family_c64p_Hwi_int14:                           ");
asm("           stw     b0, *b15--[2]   ");
asm("           mvk     14, b0         ");
asm("           stw     b0, *b15[1]     ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi_int14, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi_int14, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15[2], b0   ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi_int15         ");
asm("           .global ti_sysbios_family_c64p_Hwi_dispatchAlways         ");
asm("ti_sysbios_family_c64p_Hwi_int15:                           ");
asm("           stw     b0, *b15--[2]   ");
asm("           mvk     15, b0         ");
asm("           stw     b0, *b15[1]     ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi_dispatchAlways, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi_dispatchAlways, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15[2], b0   ");
asm("           nop     4               ");



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
extern Void ti_sysbios_timers_dmtimer_Timer_startup__E();

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
    ti_sysbios_timers_dmtimer_Timer_startup__E();
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
        (xdc_Bits32)0x23c34600,  /* lo */
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
__FAR__ const CT__ti_sysbios_BIOS_Module__id ti_sysbios_BIOS_Module__id__C = (xdc_Bits16)0x8021;

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
    (xdc_Bits32)0x23c34600,  /* lo */
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
__FAR__ const CT__ti_sysbios_BIOS_heapSize ti_sysbios_BIOS_heapSize__C = (xdc_SizeT)0x1000;

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
 * ======== ti.sysbios.family.c62.IntrinsicsSupport INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsEnabled__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsEnabled__C");
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsEnabled ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsIncluded__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsIncluded__C");
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsIncluded ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsMask__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsMask__C");
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsMask ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsMask__C = ((CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__gateObj__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__gateObj__C");
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__gateObj ti_sysbios_family_c62_IntrinsicsSupport_Module__gateObj__C = ((CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__gatePrms__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__gatePrms__C");
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__gatePrms ti_sysbios_family_c62_IntrinsicsSupport_Module__gatePrms__C = ((CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__id__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__id__C");
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__id ti_sysbios_family_c62_IntrinsicsSupport_Module__id__C = (xdc_Bits16)0x8034;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerDefined__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerDefined__C");
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerDefined ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerObj__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerObj__C");
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerObj ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerObj__C = ((CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn0__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn0__C");
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn0 ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn0__C = ((CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn1__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn1__C");
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn1 ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn1__C = ((CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn2__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn2__C");
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn2 ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn2__C = ((CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn4__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn4__C");
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn4 ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn4__C = ((CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn8__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn8__C");
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn8 ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn8__C = ((CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__startupDoneFxn__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__startupDoneFxn__C");
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__startupDoneFxn ti_sysbios_family_c62_IntrinsicsSupport_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Object__count__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Object__count__C");
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Object__count ti_sysbios_family_c62_IntrinsicsSupport_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Object__heap__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Object__heap__C");
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Object__heap ti_sysbios_family_c62_IntrinsicsSupport_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Object__sizeof__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Object__sizeof__C");
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Object__sizeof ti_sysbios_family_c62_IntrinsicsSupport_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Object__table__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Object__table__C");
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Object__table ti_sysbios_family_c62_IntrinsicsSupport_Object__table__C = 0;


/*
 * ======== ti.sysbios.family.c62.TaskSupport INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__diagsEnabled__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__diagsEnabled__C");
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__diagsEnabled ti_sysbios_family_c62_TaskSupport_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__diagsIncluded__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__diagsIncluded__C");
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__diagsIncluded ti_sysbios_family_c62_TaskSupport_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__diagsMask__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__diagsMask__C");
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__diagsMask ti_sysbios_family_c62_TaskSupport_Module__diagsMask__C = ((CT__ti_sysbios_family_c62_TaskSupport_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__gateObj__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__gateObj__C");
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__gateObj ti_sysbios_family_c62_TaskSupport_Module__gateObj__C = ((CT__ti_sysbios_family_c62_TaskSupport_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__gatePrms__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__gatePrms__C");
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__gatePrms ti_sysbios_family_c62_TaskSupport_Module__gatePrms__C = ((CT__ti_sysbios_family_c62_TaskSupport_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__id__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__id__C");
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__id ti_sysbios_family_c62_TaskSupport_Module__id__C = (xdc_Bits16)0x8033;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__loggerDefined__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__loggerDefined__C");
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__loggerDefined ti_sysbios_family_c62_TaskSupport_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__loggerObj__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__loggerObj__C");
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__loggerObj ti_sysbios_family_c62_TaskSupport_Module__loggerObj__C = ((CT__ti_sysbios_family_c62_TaskSupport_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__loggerFxn0__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__loggerFxn0__C");
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__loggerFxn0 ti_sysbios_family_c62_TaskSupport_Module__loggerFxn0__C = ((CT__ti_sysbios_family_c62_TaskSupport_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__loggerFxn1__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__loggerFxn1__C");
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__loggerFxn1 ti_sysbios_family_c62_TaskSupport_Module__loggerFxn1__C = ((CT__ti_sysbios_family_c62_TaskSupport_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__loggerFxn2__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__loggerFxn2__C");
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__loggerFxn2 ti_sysbios_family_c62_TaskSupport_Module__loggerFxn2__C = ((CT__ti_sysbios_family_c62_TaskSupport_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__loggerFxn4__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__loggerFxn4__C");
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__loggerFxn4 ti_sysbios_family_c62_TaskSupport_Module__loggerFxn4__C = ((CT__ti_sysbios_family_c62_TaskSupport_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__loggerFxn8__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__loggerFxn8__C");
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__loggerFxn8 ti_sysbios_family_c62_TaskSupport_Module__loggerFxn8__C = ((CT__ti_sysbios_family_c62_TaskSupport_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__startupDoneFxn__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__startupDoneFxn__C");
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__startupDoneFxn ti_sysbios_family_c62_TaskSupport_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_c62_TaskSupport_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Object__count__C, ".const:ti_sysbios_family_c62_TaskSupport_Object__count__C");
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Object__count ti_sysbios_family_c62_TaskSupport_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Object__heap__C, ".const:ti_sysbios_family_c62_TaskSupport_Object__heap__C");
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Object__heap ti_sysbios_family_c62_TaskSupport_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Object__sizeof__C, ".const:ti_sysbios_family_c62_TaskSupport_Object__sizeof__C");
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Object__sizeof ti_sysbios_family_c62_TaskSupport_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Object__table__C, ".const:ti_sysbios_family_c62_TaskSupport_Object__table__C");
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Object__table ti_sysbios_family_c62_TaskSupport_Object__table__C = 0;

/* defaultStackSize__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_defaultStackSize__C, ".const:ti_sysbios_family_c62_TaskSupport_defaultStackSize__C");
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_defaultStackSize ti_sysbios_family_c62_TaskSupport_defaultStackSize__C = (xdc_SizeT)0x800;

/* stackAlignment__C */
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_stackAlignment__C, ".const:ti_sysbios_family_c62_TaskSupport_stackAlignment__C");
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_stackAlignment ti_sysbios_family_c62_TaskSupport_stackAlignment__C = (xdc_UInt)0x8;


/*
 * ======== ti.sysbios.family.c64p.EventCombiner INITIALIZERS ========
 */

/* Module__state__V */
#if defined (__ICCARM__)
#pragma location = ".data_ti_sysbios_family_c64p_EventCombiner_Module__state__V"
#endif
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
#ifndef __TI_COMPILER_VERSION__
ti_sysbios_family_c64p_EventCombiner_Module_State__ ti_sysbios_family_c64p_EventCombiner_Module__state__V __attribute__ ((section(".data_ti_sysbios_family_c64p_EventCombiner_Module__state__V")));
#endif
#endif
ti_sysbios_family_c64p_EventCombiner_Module_State__ ti_sysbios_family_c64p_EventCombiner_Module__state__V = {
    {
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x0)),  /* arg */
        },  /* [0] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x1)),  /* arg */
        },  /* [1] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x2)),  /* arg */
        },  /* [2] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x3)),  /* arg */
        },  /* [3] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x4)),  /* arg */
        },  /* [4] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x5)),  /* arg */
        },  /* [5] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x6)),  /* arg */
        },  /* [6] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x7)),  /* arg */
        },  /* [7] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x8)),  /* arg */
        },  /* [8] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x9)),  /* arg */
        },  /* [9] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0xa)),  /* arg */
        },  /* [10] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0xb)),  /* arg */
        },  /* [11] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0xc)),  /* arg */
        },  /* [12] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0xd)),  /* arg */
        },  /* [13] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0xe)),  /* arg */
        },  /* [14] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0xf)),  /* arg */
        },  /* [15] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x10)),  /* arg */
        },  /* [16] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x11)),  /* arg */
        },  /* [17] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x12)),  /* arg */
        },  /* [18] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x13)),  /* arg */
        },  /* [19] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x14)),  /* arg */
        },  /* [20] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x15)),  /* arg */
        },  /* [21] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x16)),  /* arg */
        },  /* [22] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x17)),  /* arg */
        },  /* [23] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x18)),  /* arg */
        },  /* [24] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x19)),  /* arg */
        },  /* [25] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x1a)),  /* arg */
        },  /* [26] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x1b)),  /* arg */
        },  /* [27] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x1c)),  /* arg */
        },  /* [28] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x1d)),  /* arg */
        },  /* [29] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x1e)),  /* arg */
        },  /* [30] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x1f)),  /* arg */
        },  /* [31] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x20)),  /* arg */
        },  /* [32] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x21)),  /* arg */
        },  /* [33] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x22)),  /* arg */
        },  /* [34] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x23)),  /* arg */
        },  /* [35] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x24)),  /* arg */
        },  /* [36] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x25)),  /* arg */
        },  /* [37] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x26)),  /* arg */
        },  /* [38] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x27)),  /* arg */
        },  /* [39] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x28)),  /* arg */
        },  /* [40] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x29)),  /* arg */
        },  /* [41] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x2a)),  /* arg */
        },  /* [42] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x2b)),  /* arg */
        },  /* [43] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x2c)),  /* arg */
        },  /* [44] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x2d)),  /* arg */
        },  /* [45] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x2e)),  /* arg */
        },  /* [46] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x2f)),  /* arg */
        },  /* [47] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x30)),  /* arg */
        },  /* [48] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x31)),  /* arg */
        },  /* [49] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x32)),  /* arg */
        },  /* [50] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x33)),  /* arg */
        },  /* [51] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x34)),  /* arg */
        },  /* [52] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x35)),  /* arg */
        },  /* [53] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x36)),  /* arg */
        },  /* [54] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x37)),  /* arg */
        },  /* [55] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x38)),  /* arg */
        },  /* [56] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x39)),  /* arg */
        },  /* [57] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x3a)),  /* arg */
        },  /* [58] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x3b)),  /* arg */
        },  /* [59] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x3c)),  /* arg */
        },  /* [60] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x3d)),  /* arg */
        },  /* [61] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x3e)),  /* arg */
        },  /* [62] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x3f)),  /* arg */
        },  /* [63] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x40)),  /* arg */
        },  /* [64] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x41)),  /* arg */
        },  /* [65] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x42)),  /* arg */
        },  /* [66] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x43)),  /* arg */
        },  /* [67] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x44)),  /* arg */
        },  /* [68] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x45)),  /* arg */
        },  /* [69] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x46)),  /* arg */
        },  /* [70] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x47)),  /* arg */
        },  /* [71] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x48)),  /* arg */
        },  /* [72] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x49)),  /* arg */
        },  /* [73] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x4a)),  /* arg */
        },  /* [74] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x4b)),  /* arg */
        },  /* [75] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x4c)),  /* arg */
        },  /* [76] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x4d)),  /* arg */
        },  /* [77] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x4e)),  /* arg */
        },  /* [78] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x4f)),  /* arg */
        },  /* [79] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x50)),  /* arg */
        },  /* [80] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x51)),  /* arg */
        },  /* [81] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x52)),  /* arg */
        },  /* [82] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x53)),  /* arg */
        },  /* [83] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x54)),  /* arg */
        },  /* [84] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x55)),  /* arg */
        },  /* [85] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x56)),  /* arg */
        },  /* [86] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x57)),  /* arg */
        },  /* [87] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x58)),  /* arg */
        },  /* [88] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x59)),  /* arg */
        },  /* [89] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x5a)),  /* arg */
        },  /* [90] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x5b)),  /* arg */
        },  /* [91] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x5c)),  /* arg */
        },  /* [92] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x5d)),  /* arg */
        },  /* [93] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x5e)),  /* arg */
        },  /* [94] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x5f)),  /* arg */
        },  /* [95] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x60)),  /* arg */
        },  /* [96] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x61)),  /* arg */
        },  /* [97] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x62)),  /* arg */
        },  /* [98] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x63)),  /* arg */
        },  /* [99] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x64)),  /* arg */
        },  /* [100] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x65)),  /* arg */
        },  /* [101] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x66)),  /* arg */
        },  /* [102] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x67)),  /* arg */
        },  /* [103] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x68)),  /* arg */
        },  /* [104] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x69)),  /* arg */
        },  /* [105] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x6a)),  /* arg */
        },  /* [106] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x6b)),  /* arg */
        },  /* [107] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x6c)),  /* arg */
        },  /* [108] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x6d)),  /* arg */
        },  /* [109] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x6e)),  /* arg */
        },  /* [110] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x6f)),  /* arg */
        },  /* [111] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x70)),  /* arg */
        },  /* [112] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x71)),  /* arg */
        },  /* [113] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x72)),  /* arg */
        },  /* [114] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x73)),  /* arg */
        },  /* [115] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x74)),  /* arg */
        },  /* [116] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x75)),  /* arg */
        },  /* [117] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x76)),  /* arg */
        },  /* [118] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x77)),  /* arg */
        },  /* [119] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x78)),  /* arg */
        },  /* [120] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x79)),  /* arg */
        },  /* [121] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x7a)),  /* arg */
        },  /* [122] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x7b)),  /* arg */
        },  /* [123] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x7c)),  /* arg */
        },  /* [124] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x7d)),  /* arg */
        },  /* [125] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x7e)),  /* arg */
        },  /* [126] */
        {
            ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_unused)),  /* fxn */
            ((xdc_UArg)(0x7f)),  /* arg */
        },  /* [127] */
    },  /* dispatchTab */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_Module__diagsEnabled__C, ".const:ti_sysbios_family_c64p_EventCombiner_Module__diagsEnabled__C");
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_Module__diagsEnabled ti_sysbios_family_c64p_EventCombiner_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_Module__diagsIncluded__C, ".const:ti_sysbios_family_c64p_EventCombiner_Module__diagsIncluded__C");
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_Module__diagsIncluded ti_sysbios_family_c64p_EventCombiner_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_Module__diagsMask__C, ".const:ti_sysbios_family_c64p_EventCombiner_Module__diagsMask__C");
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_Module__diagsMask ti_sysbios_family_c64p_EventCombiner_Module__diagsMask__C = ((CT__ti_sysbios_family_c64p_EventCombiner_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_Module__gateObj__C, ".const:ti_sysbios_family_c64p_EventCombiner_Module__gateObj__C");
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_Module__gateObj ti_sysbios_family_c64p_EventCombiner_Module__gateObj__C = ((CT__ti_sysbios_family_c64p_EventCombiner_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_Module__gatePrms__C, ".const:ti_sysbios_family_c64p_EventCombiner_Module__gatePrms__C");
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_Module__gatePrms ti_sysbios_family_c64p_EventCombiner_Module__gatePrms__C = ((CT__ti_sysbios_family_c64p_EventCombiner_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_Module__id__C, ".const:ti_sysbios_family_c64p_EventCombiner_Module__id__C");
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_Module__id ti_sysbios_family_c64p_EventCombiner_Module__id__C = (xdc_Bits16)0x8015;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_Module__loggerDefined__C, ".const:ti_sysbios_family_c64p_EventCombiner_Module__loggerDefined__C");
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_Module__loggerDefined ti_sysbios_family_c64p_EventCombiner_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_Module__loggerObj__C, ".const:ti_sysbios_family_c64p_EventCombiner_Module__loggerObj__C");
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_Module__loggerObj ti_sysbios_family_c64p_EventCombiner_Module__loggerObj__C = ((CT__ti_sysbios_family_c64p_EventCombiner_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn0__C, ".const:ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn0__C");
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn0 ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn0__C = ((CT__ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn1__C, ".const:ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn1__C");
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn1 ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn1__C = ((CT__ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn2__C, ".const:ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn2__C");
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn2 ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn2__C = ((CT__ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn4__C, ".const:ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn4__C");
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn4 ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn4__C = ((CT__ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn8__C, ".const:ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn8__C");
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn8 ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn8__C = ((CT__ti_sysbios_family_c64p_EventCombiner_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_Module__startupDoneFxn__C, ".const:ti_sysbios_family_c64p_EventCombiner_Module__startupDoneFxn__C");
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_Module__startupDoneFxn ti_sysbios_family_c64p_EventCombiner_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_c64p_EventCombiner_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_Object__count__C, ".const:ti_sysbios_family_c64p_EventCombiner_Object__count__C");
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_Object__count ti_sysbios_family_c64p_EventCombiner_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_Object__heap__C, ".const:ti_sysbios_family_c64p_EventCombiner_Object__heap__C");
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_Object__heap ti_sysbios_family_c64p_EventCombiner_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_Object__sizeof__C, ".const:ti_sysbios_family_c64p_EventCombiner_Object__sizeof__C");
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_Object__sizeof ti_sysbios_family_c64p_EventCombiner_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_Object__table__C, ".const:ti_sysbios_family_c64p_EventCombiner_Object__table__C");
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_Object__table ti_sysbios_family_c64p_EventCombiner_Object__table__C = 0;

/* A_invalidEventId__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_A_invalidEventId__C, ".const:ti_sysbios_family_c64p_EventCombiner_A_invalidEventId__C");
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_A_invalidEventId ti_sysbios_family_c64p_EventCombiner_A_invalidEventId__C = (((xdc_runtime_Assert_Id)400) << 16 | 16);

/* E_unpluggedEvent__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_E_unpluggedEvent__C, ".const:ti_sysbios_family_c64p_EventCombiner_E_unpluggedEvent__C");
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_E_unpluggedEvent ti_sysbios_family_c64p_EventCombiner_E_unpluggedEvent__C = (((xdc_runtime_Error_Id)4406) << 16 | 0);

/* EVTMASK__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_EventCombiner_EVTMASK__C, ".const:ti_sysbios_family_c64p_EventCombiner_EVTMASK__C");
__FAR__ const CT__ti_sysbios_family_c64p_EventCombiner_EVTMASK ti_sysbios_family_c64p_EventCombiner_EVTMASK__C = {
    (xdc_Bits32)(-0x0 - 1),  /* [0] */
    (xdc_Bits32)(-0x0 - 1),  /* [1] */
    (xdc_Bits32)(-0x0 - 1),  /* [2] */
    (xdc_Bits32)(-0x0 - 1),  /* [3] */
};


/*
 * ======== ti.sysbios.family.c64p.Exception INITIALIZERS ========
 */

/* Module__state__V */
#if defined (__ICCARM__)
#pragma location = ".data_ti_sysbios_family_c64p_Exception_Module__state__V"
#endif
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
#ifndef __TI_COMPILER_VERSION__
ti_sysbios_family_c64p_Exception_Module_State__ ti_sysbios_family_c64p_Exception_Module__state__V __attribute__ ((section(".data_ti_sysbios_family_c64p_Exception_Module__state__V")));
#endif
#endif
ti_sysbios_family_c64p_Exception_Module_State__ ti_sysbios_family_c64p_Exception_Module__state__V = {
    (xdc_Bits32)0x0,  /* efr */
    (xdc_Bits32)0x0,  /* nrp */
    (xdc_Bits32)0x0,  /* ntsr */
    (xdc_Bits32)0x0,  /* ierr */
    ((xdc_Void(*)(xdc_Void))0),  /* returnHook */
    ((ti_sysbios_family_c64p_Exception_Context*)0),  /* excContext */
    {
        (xdc_Char)0x0,  /* [0] */
        (xdc_Char)0x0,  /* [1] */
        (xdc_Char)0x0,  /* [2] */
        (xdc_Char)0x0,  /* [3] */
        (xdc_Char)0x0,  /* [4] */
        (xdc_Char)0x0,  /* [5] */
        (xdc_Char)0x0,  /* [6] */
        (xdc_Char)0x0,  /* [7] */
        (xdc_Char)0x0,  /* [8] */
        (xdc_Char)0x0,  /* [9] */
        (xdc_Char)0x0,  /* [10] */
        (xdc_Char)0x0,  /* [11] */
        (xdc_Char)0x0,  /* [12] */
        (xdc_Char)0x0,  /* [13] */
        (xdc_Char)0x0,  /* [14] */
        (xdc_Char)0x0,  /* [15] */
    },  /* scratch */
    ((xdc_Char*)0),  /* excPtr */
    ((void*)0),  /* contextBuf */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__diagsEnabled__C, ".const:ti_sysbios_family_c64p_Exception_Module__diagsEnabled__C");
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__diagsEnabled ti_sysbios_family_c64p_Exception_Module__diagsEnabled__C = (xdc_Bits32)0x190;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__diagsIncluded__C, ".const:ti_sysbios_family_c64p_Exception_Module__diagsIncluded__C");
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__diagsIncluded ti_sysbios_family_c64p_Exception_Module__diagsIncluded__C = (xdc_Bits32)0x190;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__diagsMask__C, ".const:ti_sysbios_family_c64p_Exception_Module__diagsMask__C");
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__diagsMask ti_sysbios_family_c64p_Exception_Module__diagsMask__C = ((CT__ti_sysbios_family_c64p_Exception_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__gateObj__C, ".const:ti_sysbios_family_c64p_Exception_Module__gateObj__C");
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__gateObj ti_sysbios_family_c64p_Exception_Module__gateObj__C = ((CT__ti_sysbios_family_c64p_Exception_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__gatePrms__C, ".const:ti_sysbios_family_c64p_Exception_Module__gatePrms__C");
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__gatePrms ti_sysbios_family_c64p_Exception_Module__gatePrms__C = ((CT__ti_sysbios_family_c64p_Exception_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__id__C, ".const:ti_sysbios_family_c64p_Exception_Module__id__C");
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__id ti_sysbios_family_c64p_Exception_Module__id__C = (xdc_Bits16)0x8016;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__loggerDefined__C, ".const:ti_sysbios_family_c64p_Exception_Module__loggerDefined__C");
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__loggerDefined ti_sysbios_family_c64p_Exception_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__loggerObj__C, ".const:ti_sysbios_family_c64p_Exception_Module__loggerObj__C");
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__loggerObj ti_sysbios_family_c64p_Exception_Module__loggerObj__C = ((CT__ti_sysbios_family_c64p_Exception_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__loggerFxn0__C, ".const:ti_sysbios_family_c64p_Exception_Module__loggerFxn0__C");
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__loggerFxn0 ti_sysbios_family_c64p_Exception_Module__loggerFxn0__C = ((CT__ti_sysbios_family_c64p_Exception_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__loggerFxn1__C, ".const:ti_sysbios_family_c64p_Exception_Module__loggerFxn1__C");
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__loggerFxn1 ti_sysbios_family_c64p_Exception_Module__loggerFxn1__C = ((CT__ti_sysbios_family_c64p_Exception_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__loggerFxn2__C, ".const:ti_sysbios_family_c64p_Exception_Module__loggerFxn2__C");
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__loggerFxn2 ti_sysbios_family_c64p_Exception_Module__loggerFxn2__C = ((CT__ti_sysbios_family_c64p_Exception_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__loggerFxn4__C, ".const:ti_sysbios_family_c64p_Exception_Module__loggerFxn4__C");
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__loggerFxn4 ti_sysbios_family_c64p_Exception_Module__loggerFxn4__C = ((CT__ti_sysbios_family_c64p_Exception_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__loggerFxn8__C, ".const:ti_sysbios_family_c64p_Exception_Module__loggerFxn8__C");
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__loggerFxn8 ti_sysbios_family_c64p_Exception_Module__loggerFxn8__C = ((CT__ti_sysbios_family_c64p_Exception_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__startupDoneFxn__C, ".const:ti_sysbios_family_c64p_Exception_Module__startupDoneFxn__C");
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__startupDoneFxn ti_sysbios_family_c64p_Exception_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_c64p_Exception_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Object__count__C, ".const:ti_sysbios_family_c64p_Exception_Object__count__C");
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Object__count ti_sysbios_family_c64p_Exception_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Object__heap__C, ".const:ti_sysbios_family_c64p_Exception_Object__heap__C");
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Object__heap ti_sysbios_family_c64p_Exception_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Object__sizeof__C, ".const:ti_sysbios_family_c64p_Exception_Object__sizeof__C");
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Object__sizeof ti_sysbios_family_c64p_Exception_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Object__table__C, ".const:ti_sysbios_family_c64p_Exception_Object__table__C");
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Object__table ti_sysbios_family_c64p_Exception_Object__table__C = 0;

/* E_exceptionMin__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_E_exceptionMin__C, ".const:ti_sysbios_family_c64p_Exception_E_exceptionMin__C");
__FAR__ const CT__ti_sysbios_family_c64p_Exception_E_exceptionMin ti_sysbios_family_c64p_Exception_E_exceptionMin__C = (((xdc_runtime_Error_Id)4447) << 16 | 0);

/* E_exceptionMax__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_E_exceptionMax__C, ".const:ti_sysbios_family_c64p_Exception_E_exceptionMax__C");
__FAR__ const CT__ti_sysbios_family_c64p_Exception_E_exceptionMax ti_sysbios_family_c64p_Exception_E_exceptionMax__C = (((xdc_runtime_Error_Id)4589) << 16 | 0);

/* useInternalBuffer__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_useInternalBuffer__C, ".const:ti_sysbios_family_c64p_Exception_useInternalBuffer__C");
__FAR__ const CT__ti_sysbios_family_c64p_Exception_useInternalBuffer ti_sysbios_family_c64p_Exception_useInternalBuffer__C = 0;

/* enableExternalMPC__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_enableExternalMPC__C, ".const:ti_sysbios_family_c64p_Exception_enableExternalMPC__C");
__FAR__ const CT__ti_sysbios_family_c64p_Exception_enableExternalMPC ti_sysbios_family_c64p_Exception_enableExternalMPC__C = 0;

/* enablePrint__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_enablePrint__C, ".const:ti_sysbios_family_c64p_Exception_enablePrint__C");
__FAR__ const CT__ti_sysbios_family_c64p_Exception_enablePrint ti_sysbios_family_c64p_Exception_enablePrint__C = 1;

/* exceptionHook__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_exceptionHook__C, ".const:ti_sysbios_family_c64p_Exception_exceptionHook__C");
__FAR__ const CT__ti_sysbios_family_c64p_Exception_exceptionHook ti_sysbios_family_c64p_Exception_exceptionHook__C = ((CT__ti_sysbios_family_c64p_Exception_exceptionHook)0);

/* internalHook__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_internalHook__C, ".const:ti_sysbios_family_c64p_Exception_internalHook__C");
__FAR__ const CT__ti_sysbios_family_c64p_Exception_internalHook ti_sysbios_family_c64p_Exception_internalHook__C = ((CT__ti_sysbios_family_c64p_Exception_internalHook)0);

/* externalHook__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_externalHook__C, ".const:ti_sysbios_family_c64p_Exception_externalHook__C");
__FAR__ const CT__ti_sysbios_family_c64p_Exception_externalHook ti_sysbios_family_c64p_Exception_externalHook__C = ((CT__ti_sysbios_family_c64p_Exception_externalHook)0);

/* nmiHook__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_nmiHook__C, ".const:ti_sysbios_family_c64p_Exception_nmiHook__C");
__FAR__ const CT__ti_sysbios_family_c64p_Exception_nmiHook ti_sysbios_family_c64p_Exception_nmiHook__C = ((CT__ti_sysbios_family_c64p_Exception_nmiHook)0);

/* returnHook__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_returnHook__C, ".const:ti_sysbios_family_c64p_Exception_returnHook__C");
__FAR__ const CT__ti_sysbios_family_c64p_Exception_returnHook ti_sysbios_family_c64p_Exception_returnHook__C = ((CT__ti_sysbios_family_c64p_Exception_returnHook)0);


/*
 * ======== ti.sysbios.family.c64p.Hwi INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_family_c64p_Hwi_Object__DESC__C;

/* Object__PARAMS__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Object__PARAMS__C, ".const:ti_sysbios_family_c64p_Hwi_Object__PARAMS__C");
__FAR__ const ti_sysbios_family_c64p_Hwi_Params ti_sysbios_family_c64p_Hwi_Object__PARAMS__C = {
    sizeof (ti_sysbios_family_c64p_Hwi_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_family_c64p_Hwi_Object__PARAMS__C.__iprms, /* instance */
    ti_sysbios_interfaces_IHwi_MaskingOption_SELF,  /* maskSetting */
    ((xdc_UArg)(0x0)),  /* arg */
    1,  /* enableInt */
    (xdc_Int)(-0x0 - 1),  /* eventId */
    (xdc_Int)0x0,  /* priority */
    (xdc_Bits16)0x0,  /* disableMask */
    (xdc_Bits16)0x0,  /* restoreMask */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_family_c64p_Hwi_Module__ ti_sysbios_family_c64p_Hwi_Module__root__V = {
    {&ti_sysbios_family_c64p_Hwi_Module__root__V.link,  /* link.next */
    &ti_sysbios_family_c64p_Hwi_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_family_c64p_Hwi_Object__ ti_sysbios_family_c64p_Hwi_Object__table__V[5] = {
    {/* instance#0 */
        0,
        (xdc_Bits16)0x80,  /* disableMask */
        (xdc_Bits16)0x80,  /* restoreMask */
        ((xdc_UArg)(0x0)),  /* arg */
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_dispatch)),  /* fxn */
        ((xdc_UArg)0),  /* irp */
        ((void*)0),  /* hookEnv */
    },
    {/* instance#1 */
        0,
        (xdc_Bits16)0x100,  /* disableMask */
        (xdc_Bits16)0x100,  /* restoreMask */
        ((xdc_UArg)(0x1)),  /* arg */
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_dispatch)),  /* fxn */
        ((xdc_UArg)0),  /* irp */
        ((void*)0),  /* hookEnv */
    },
    {/* instance#2 */
        0,
        (xdc_Bits16)0x200,  /* disableMask */
        (xdc_Bits16)0x200,  /* restoreMask */
        ((xdc_UArg)(0x2)),  /* arg */
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_dispatch)),  /* fxn */
        ((xdc_UArg)0),  /* irp */
        ((void*)0),  /* hookEnv */
    },
    {/* instance#3 */
        0,
        (xdc_Bits16)0x400,  /* disableMask */
        (xdc_Bits16)0x400,  /* restoreMask */
        ((xdc_UArg)(0x3)),  /* arg */
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_dispatch)),  /* fxn */
        ((xdc_UArg)0),  /* irp */
        ((void*)0),  /* hookEnv */
    },
    {/* instance#4 */
        0,
        (xdc_Bits16)0x8000,  /* disableMask */
        (xdc_Bits16)0x8000,  /* restoreMask */
        ((xdc_UArg)((void*)(ti_sysbios_timers_dmtimer_Timer_Handle)&ti_sysbios_timers_dmtimer_Timer_Object__table__V[0])),  /* arg */
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_timers_dmtimer_Timer_stub__E)),  /* fxn */
        ((xdc_UArg)0),  /* irp */
        ((void*)0),  /* hookEnv */
    },
};

/* Module__state__V */
#if defined (__ICCARM__)
#pragma location = ".data_ti_sysbios_family_c64p_Hwi_Module__state__V"
#endif
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
#ifndef __TI_COMPILER_VERSION__
ti_sysbios_family_c64p_Hwi_Module_State__ ti_sysbios_family_c64p_Hwi_Module__state__V __attribute__ ((section(".data_ti_sysbios_family_c64p_Hwi_Module__state__V")));
#endif
#endif
ti_sysbios_family_c64p_Hwi_Module_State__ ti_sysbios_family_c64p_Hwi_Module__state__V = {
    {
        (xdc_Char)(-0x0 - 1),  /* [0] */
        (xdc_Char)(-0x0 - 1),  /* [1] */
        (xdc_Char)(-0x0 - 1),  /* [2] */
        (xdc_Char)(-0x0 - 1),  /* [3] */
        (xdc_Char)(-0x0 - 1),  /* [4] */
        (xdc_Char)(-0x0 - 1),  /* [5] */
        (xdc_Char)(-0x0 - 1),  /* [6] */
        (xdc_Char)0x0,  /* [7] */
        (xdc_Char)0x1,  /* [8] */
        (xdc_Char)0x2,  /* [9] */
        (xdc_Char)0x3,  /* [10] */
        (xdc_Char)(-0x0 - 1),  /* [11] */
        (xdc_Char)(-0x0 - 1),  /* [12] */
        (xdc_Char)(-0x0 - 1),  /* [13] */
        (xdc_Char)(-0x0 - 1),  /* [14] */
        (xdc_Char)0x44,  /* [15] */
    },  /* intEvents */
    (xdc_Bits16)0x8783,  /* ierMask */
    (xdc_Int)0x0,  /* intNum */
    ((xdc_Char*)0),  /* taskSP */
    ((xdc_Char*)0),  /* isrStack */
    ((xdc_Ptr)((void*)&ti_sysbios_family_c64p_Hwi0)),  /* vectorTableBase */
    ((xdc_Ptr)((void*)&__TI_STATIC_BASE)),  /* bss */
    (xdc_Int)0x0,  /* scw */
    {
        0,  /* [0] */
        0,  /* [1] */
        0,  /* [2] */
        0,  /* [3] */
        0,  /* [4] */
        0,  /* [5] */
        0,  /* [6] */
        (ti_sysbios_family_c64p_Hwi_Handle)&ti_sysbios_family_c64p_Hwi_Object__table__V[0],  /* [7] */
        (ti_sysbios_family_c64p_Hwi_Handle)&ti_sysbios_family_c64p_Hwi_Object__table__V[1],  /* [8] */
        (ti_sysbios_family_c64p_Hwi_Handle)&ti_sysbios_family_c64p_Hwi_Object__table__V[2],  /* [9] */
        (ti_sysbios_family_c64p_Hwi_Handle)&ti_sysbios_family_c64p_Hwi_Object__table__V[3],  /* [10] */
        0,  /* [11] */
        0,  /* [12] */
        0,  /* [13] */
        0,  /* [14] */
        (ti_sysbios_family_c64p_Hwi_Handle)&ti_sysbios_family_c64p_Hwi_Object__table__V[4],  /* [15] */
    },  /* dispatchTable */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__diagsEnabled__C, ".const:ti_sysbios_family_c64p_Hwi_Module__diagsEnabled__C");
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__diagsEnabled ti_sysbios_family_c64p_Hwi_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__diagsIncluded__C, ".const:ti_sysbios_family_c64p_Hwi_Module__diagsIncluded__C");
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__diagsIncluded ti_sysbios_family_c64p_Hwi_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__diagsMask__C, ".const:ti_sysbios_family_c64p_Hwi_Module__diagsMask__C");
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__diagsMask ti_sysbios_family_c64p_Hwi_Module__diagsMask__C = ((CT__ti_sysbios_family_c64p_Hwi_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__gateObj__C, ".const:ti_sysbios_family_c64p_Hwi_Module__gateObj__C");
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__gateObj ti_sysbios_family_c64p_Hwi_Module__gateObj__C = ((CT__ti_sysbios_family_c64p_Hwi_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__gatePrms__C, ".const:ti_sysbios_family_c64p_Hwi_Module__gatePrms__C");
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__gatePrms ti_sysbios_family_c64p_Hwi_Module__gatePrms__C = ((CT__ti_sysbios_family_c64p_Hwi_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__id__C, ".const:ti_sysbios_family_c64p_Hwi_Module__id__C");
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__id ti_sysbios_family_c64p_Hwi_Module__id__C = (xdc_Bits16)0x8017;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__loggerDefined__C, ".const:ti_sysbios_family_c64p_Hwi_Module__loggerDefined__C");
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__loggerDefined ti_sysbios_family_c64p_Hwi_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__loggerObj__C, ".const:ti_sysbios_family_c64p_Hwi_Module__loggerObj__C");
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__loggerObj ti_sysbios_family_c64p_Hwi_Module__loggerObj__C = ((CT__ti_sysbios_family_c64p_Hwi_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__loggerFxn0__C, ".const:ti_sysbios_family_c64p_Hwi_Module__loggerFxn0__C");
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__loggerFxn0 ti_sysbios_family_c64p_Hwi_Module__loggerFxn0__C = ((CT__ti_sysbios_family_c64p_Hwi_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__loggerFxn1__C, ".const:ti_sysbios_family_c64p_Hwi_Module__loggerFxn1__C");
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__loggerFxn1 ti_sysbios_family_c64p_Hwi_Module__loggerFxn1__C = ((CT__ti_sysbios_family_c64p_Hwi_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__loggerFxn2__C, ".const:ti_sysbios_family_c64p_Hwi_Module__loggerFxn2__C");
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__loggerFxn2 ti_sysbios_family_c64p_Hwi_Module__loggerFxn2__C = ((CT__ti_sysbios_family_c64p_Hwi_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__loggerFxn4__C, ".const:ti_sysbios_family_c64p_Hwi_Module__loggerFxn4__C");
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__loggerFxn4 ti_sysbios_family_c64p_Hwi_Module__loggerFxn4__C = ((CT__ti_sysbios_family_c64p_Hwi_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__loggerFxn8__C, ".const:ti_sysbios_family_c64p_Hwi_Module__loggerFxn8__C");
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__loggerFxn8 ti_sysbios_family_c64p_Hwi_Module__loggerFxn8__C = ((CT__ti_sysbios_family_c64p_Hwi_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__startupDoneFxn__C, ".const:ti_sysbios_family_c64p_Hwi_Module__startupDoneFxn__C");
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__startupDoneFxn ti_sysbios_family_c64p_Hwi_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_c64p_Hwi_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Object__count__C, ".const:ti_sysbios_family_c64p_Hwi_Object__count__C");
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Object__count ti_sysbios_family_c64p_Hwi_Object__count__C = 5;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Object__heap__C, ".const:ti_sysbios_family_c64p_Hwi_Object__heap__C");
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Object__heap ti_sysbios_family_c64p_Hwi_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Object__sizeof__C, ".const:ti_sysbios_family_c64p_Hwi_Object__sizeof__C");
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Object__sizeof ti_sysbios_family_c64p_Hwi_Object__sizeof__C = sizeof(ti_sysbios_family_c64p_Hwi_Object__);

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Object__table__C, ".const:ti_sysbios_family_c64p_Hwi_Object__table__C");
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Object__table ti_sysbios_family_c64p_Hwi_Object__table__C = ti_sysbios_family_c64p_Hwi_Object__table__V;

/* dispatcherAutoNestingSupport__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_dispatcherAutoNestingSupport__C, ".const:ti_sysbios_family_c64p_Hwi_dispatcherAutoNestingSupport__C");
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_dispatcherAutoNestingSupport ti_sysbios_family_c64p_Hwi_dispatcherAutoNestingSupport__C = 1;

/* dispatcherSwiSupport__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_dispatcherSwiSupport__C, ".const:ti_sysbios_family_c64p_Hwi_dispatcherSwiSupport__C");
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_dispatcherSwiSupport ti_sysbios_family_c64p_Hwi_dispatcherSwiSupport__C = 1;

/* dispatcherTaskSupport__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_dispatcherTaskSupport__C, ".const:ti_sysbios_family_c64p_Hwi_dispatcherTaskSupport__C");
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_dispatcherTaskSupport ti_sysbios_family_c64p_Hwi_dispatcherTaskSupport__C = 1;

/* dispatcherIrpTrackingSupport__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_dispatcherIrpTrackingSupport__C, ".const:ti_sysbios_family_c64p_Hwi_dispatcherIrpTrackingSupport__C");
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_dispatcherIrpTrackingSupport ti_sysbios_family_c64p_Hwi_dispatcherIrpTrackingSupport__C = 1;

/* E_alreadyDefined__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_E_alreadyDefined__C, ".const:ti_sysbios_family_c64p_Hwi_E_alreadyDefined__C");
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_E_alreadyDefined ti_sysbios_family_c64p_Hwi_E_alreadyDefined__C = (((xdc_runtime_Error_Id)4631) << 16 | 0);

/* E_handleNotFound__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_E_handleNotFound__C, ".const:ti_sysbios_family_c64p_Hwi_E_handleNotFound__C");
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_E_handleNotFound ti_sysbios_family_c64p_Hwi_E_handleNotFound__C = (((xdc_runtime_Error_Id)4679) << 16 | 0);

/* E_allocSCFailed__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_E_allocSCFailed__C, ".const:ti_sysbios_family_c64p_Hwi_E_allocSCFailed__C");
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_E_allocSCFailed ti_sysbios_family_c64p_Hwi_E_allocSCFailed__C = (((xdc_runtime_Error_Id)4724) << 16 | 0);

/* E_registerSCFailed__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_E_registerSCFailed__C, ".const:ti_sysbios_family_c64p_Hwi_E_registerSCFailed__C");
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_E_registerSCFailed ti_sysbios_family_c64p_Hwi_E_registerSCFailed__C = (((xdc_runtime_Error_Id)4769) << 16 | 0);

/* E_invalidIntNum__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_E_invalidIntNum__C, ".const:ti_sysbios_family_c64p_Hwi_E_invalidIntNum__C");
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_E_invalidIntNum ti_sysbios_family_c64p_Hwi_E_invalidIntNum__C = (((xdc_runtime_Error_Id)4820) << 16 | 0);

/* LM_begin__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_LM_begin__C, ".const:ti_sysbios_family_c64p_Hwi_LM_begin__C");
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_LM_begin ti_sysbios_family_c64p_Hwi_LM_begin__C = (((xdc_runtime_Log_Event)5986) << 16 | 768);

/* LD_end__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_LD_end__C, ".const:ti_sysbios_family_c64p_Hwi_LD_end__C");
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_LD_end ti_sysbios_family_c64p_Hwi_LD_end__C = (((xdc_runtime_Log_Event)6056) << 16 | 512);

/* enableException__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_enableException__C, ".const:ti_sysbios_family_c64p_Hwi_enableException__C");
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_enableException ti_sysbios_family_c64p_Hwi_enableException__C = 1;

/* swiDisable__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_swiDisable__C, ".const:ti_sysbios_family_c64p_Hwi_swiDisable__C");
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_swiDisable ti_sysbios_family_c64p_Hwi_swiDisable__C = ((CT__ti_sysbios_family_c64p_Hwi_swiDisable)((xdc_Fxn)ti_sysbios_knl_Swi_disable__E));

/* swiRestoreHwi__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_swiRestoreHwi__C, ".const:ti_sysbios_family_c64p_Hwi_swiRestoreHwi__C");
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_swiRestoreHwi ti_sysbios_family_c64p_Hwi_swiRestoreHwi__C = ((CT__ti_sysbios_family_c64p_Hwi_swiRestoreHwi)((xdc_Fxn)ti_sysbios_knl_Swi_restoreHwi__E));

/* taskDisable__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_taskDisable__C, ".const:ti_sysbios_family_c64p_Hwi_taskDisable__C");
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_taskDisable ti_sysbios_family_c64p_Hwi_taskDisable__C = ((CT__ti_sysbios_family_c64p_Hwi_taskDisable)((xdc_Fxn)ti_sysbios_knl_Task_disable__E));

/* taskRestoreHwi__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_taskRestoreHwi__C, ".const:ti_sysbios_family_c64p_Hwi_taskRestoreHwi__C");
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_taskRestoreHwi ti_sysbios_family_c64p_Hwi_taskRestoreHwi__C = ((CT__ti_sysbios_family_c64p_Hwi_taskRestoreHwi)((xdc_Fxn)ti_sysbios_knl_Task_restoreHwi__E));

/* hooks__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_hooks__C, ".const:ti_sysbios_family_c64p_Hwi_hooks__C");
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_hooks ti_sysbios_family_c64p_Hwi_hooks__C = {0, 0};


/*
 * ======== ti.sysbios.family.c64p.TimestampProvider INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__diagsEnabled__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__diagsEnabled__C");
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__diagsEnabled ti_sysbios_family_c64p_TimestampProvider_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__diagsIncluded__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__diagsIncluded__C");
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__diagsIncluded ti_sysbios_family_c64p_TimestampProvider_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__diagsMask__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__diagsMask__C");
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__diagsMask ti_sysbios_family_c64p_TimestampProvider_Module__diagsMask__C = ((CT__ti_sysbios_family_c64p_TimestampProvider_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__gateObj__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__gateObj__C");
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__gateObj ti_sysbios_family_c64p_TimestampProvider_Module__gateObj__C = ((CT__ti_sysbios_family_c64p_TimestampProvider_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__gatePrms__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__gatePrms__C");
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__gatePrms ti_sysbios_family_c64p_TimestampProvider_Module__gatePrms__C = ((CT__ti_sysbios_family_c64p_TimestampProvider_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__id__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__id__C");
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__id ti_sysbios_family_c64p_TimestampProvider_Module__id__C = (xdc_Bits16)0x8018;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__loggerDefined__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__loggerDefined__C");
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerDefined ti_sysbios_family_c64p_TimestampProvider_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__loggerObj__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__loggerObj__C");
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerObj ti_sysbios_family_c64p_TimestampProvider_Module__loggerObj__C = ((CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn0__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn0__C");
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn0 ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn0__C = ((CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn1__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn1__C");
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn1 ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn1__C = ((CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn2__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn2__C");
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn2 ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn2__C = ((CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn4__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn4__C");
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn4 ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn4__C = ((CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn8__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn8__C");
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn8 ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn8__C = ((CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__startupDoneFxn__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__startupDoneFxn__C");
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__startupDoneFxn ti_sysbios_family_c64p_TimestampProvider_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_c64p_TimestampProvider_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Object__count__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Object__count__C");
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Object__count ti_sysbios_family_c64p_TimestampProvider_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Object__heap__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Object__heap__C");
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Object__heap ti_sysbios_family_c64p_TimestampProvider_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Object__sizeof__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Object__sizeof__C");
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Object__sizeof ti_sysbios_family_c64p_TimestampProvider_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Object__table__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Object__table__C");
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Object__table ti_sysbios_family_c64p_TimestampProvider_Object__table__C = 0;


/*
 * ======== ti.sysbios.family.c66.Cache INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_Module__diagsEnabled__C, ".const:ti_sysbios_family_c66_Cache_Module__diagsEnabled__C");
__FAR__ const CT__ti_sysbios_family_c66_Cache_Module__diagsEnabled ti_sysbios_family_c66_Cache_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_Module__diagsIncluded__C, ".const:ti_sysbios_family_c66_Cache_Module__diagsIncluded__C");
__FAR__ const CT__ti_sysbios_family_c66_Cache_Module__diagsIncluded ti_sysbios_family_c66_Cache_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_Module__diagsMask__C, ".const:ti_sysbios_family_c66_Cache_Module__diagsMask__C");
__FAR__ const CT__ti_sysbios_family_c66_Cache_Module__diagsMask ti_sysbios_family_c66_Cache_Module__diagsMask__C = ((CT__ti_sysbios_family_c66_Cache_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_Module__gateObj__C, ".const:ti_sysbios_family_c66_Cache_Module__gateObj__C");
__FAR__ const CT__ti_sysbios_family_c66_Cache_Module__gateObj ti_sysbios_family_c66_Cache_Module__gateObj__C = ((CT__ti_sysbios_family_c66_Cache_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_Module__gatePrms__C, ".const:ti_sysbios_family_c66_Cache_Module__gatePrms__C");
__FAR__ const CT__ti_sysbios_family_c66_Cache_Module__gatePrms ti_sysbios_family_c66_Cache_Module__gatePrms__C = ((CT__ti_sysbios_family_c66_Cache_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_Module__id__C, ".const:ti_sysbios_family_c66_Cache_Module__id__C");
__FAR__ const CT__ti_sysbios_family_c66_Cache_Module__id ti_sysbios_family_c66_Cache_Module__id__C = (xdc_Bits16)0x8027;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_Module__loggerDefined__C, ".const:ti_sysbios_family_c66_Cache_Module__loggerDefined__C");
__FAR__ const CT__ti_sysbios_family_c66_Cache_Module__loggerDefined ti_sysbios_family_c66_Cache_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_Module__loggerObj__C, ".const:ti_sysbios_family_c66_Cache_Module__loggerObj__C");
__FAR__ const CT__ti_sysbios_family_c66_Cache_Module__loggerObj ti_sysbios_family_c66_Cache_Module__loggerObj__C = ((CT__ti_sysbios_family_c66_Cache_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_Module__loggerFxn0__C, ".const:ti_sysbios_family_c66_Cache_Module__loggerFxn0__C");
__FAR__ const CT__ti_sysbios_family_c66_Cache_Module__loggerFxn0 ti_sysbios_family_c66_Cache_Module__loggerFxn0__C = ((CT__ti_sysbios_family_c66_Cache_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_Module__loggerFxn1__C, ".const:ti_sysbios_family_c66_Cache_Module__loggerFxn1__C");
__FAR__ const CT__ti_sysbios_family_c66_Cache_Module__loggerFxn1 ti_sysbios_family_c66_Cache_Module__loggerFxn1__C = ((CT__ti_sysbios_family_c66_Cache_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_Module__loggerFxn2__C, ".const:ti_sysbios_family_c66_Cache_Module__loggerFxn2__C");
__FAR__ const CT__ti_sysbios_family_c66_Cache_Module__loggerFxn2 ti_sysbios_family_c66_Cache_Module__loggerFxn2__C = ((CT__ti_sysbios_family_c66_Cache_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_Module__loggerFxn4__C, ".const:ti_sysbios_family_c66_Cache_Module__loggerFxn4__C");
__FAR__ const CT__ti_sysbios_family_c66_Cache_Module__loggerFxn4 ti_sysbios_family_c66_Cache_Module__loggerFxn4__C = ((CT__ti_sysbios_family_c66_Cache_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_Module__loggerFxn8__C, ".const:ti_sysbios_family_c66_Cache_Module__loggerFxn8__C");
__FAR__ const CT__ti_sysbios_family_c66_Cache_Module__loggerFxn8 ti_sysbios_family_c66_Cache_Module__loggerFxn8__C = ((CT__ti_sysbios_family_c66_Cache_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_Module__startupDoneFxn__C, ".const:ti_sysbios_family_c66_Cache_Module__startupDoneFxn__C");
__FAR__ const CT__ti_sysbios_family_c66_Cache_Module__startupDoneFxn ti_sysbios_family_c66_Cache_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_c66_Cache_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_Object__count__C, ".const:ti_sysbios_family_c66_Cache_Object__count__C");
__FAR__ const CT__ti_sysbios_family_c66_Cache_Object__count ti_sysbios_family_c66_Cache_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_Object__heap__C, ".const:ti_sysbios_family_c66_Cache_Object__heap__C");
__FAR__ const CT__ti_sysbios_family_c66_Cache_Object__heap ti_sysbios_family_c66_Cache_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_Object__sizeof__C, ".const:ti_sysbios_family_c66_Cache_Object__sizeof__C");
__FAR__ const CT__ti_sysbios_family_c66_Cache_Object__sizeof ti_sysbios_family_c66_Cache_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_Object__table__C, ".const:ti_sysbios_family_c66_Cache_Object__table__C");
__FAR__ const CT__ti_sysbios_family_c66_Cache_Object__table ti_sysbios_family_c66_Cache_Object__table__C = 0;

/* initSize__C */
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_initSize__C, ".const:ti_sysbios_family_c66_Cache_initSize__C");
__FAR__ const CT__ti_sysbios_family_c66_Cache_initSize ti_sysbios_family_c66_Cache_initSize__C = {
    ti_sysbios_family_c66_Cache_L1Size_32K,  /* l1pSize */
    ti_sysbios_family_c66_Cache_L1Size_32K,  /* l1dSize */
    ti_sysbios_family_c66_Cache_L2Size_0K,  /* l2Size */
};

/* E_invalidL1CacheSize__C */
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_E_invalidL1CacheSize__C, ".const:ti_sysbios_family_c66_Cache_E_invalidL1CacheSize__C");
__FAR__ const CT__ti_sysbios_family_c66_Cache_E_invalidL1CacheSize ti_sysbios_family_c66_Cache_E_invalidL1CacheSize__C = (((xdc_runtime_Error_Id)4872) << 16 | 0);

/* E_invalidL2CacheSize__C */
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_E_invalidL2CacheSize__C, ".const:ti_sysbios_family_c66_Cache_E_invalidL2CacheSize__C");
__FAR__ const CT__ti_sysbios_family_c66_Cache_E_invalidL2CacheSize ti_sysbios_family_c66_Cache_E_invalidL2CacheSize__C = (((xdc_runtime_Error_Id)4919) << 16 | 0);

/* atomicBlockSize__C */
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_atomicBlockSize__C, ".const:ti_sysbios_family_c66_Cache_atomicBlockSize__C");
__FAR__ const CT__ti_sysbios_family_c66_Cache_atomicBlockSize ti_sysbios_family_c66_Cache_atomicBlockSize__C = (xdc_UInt32)0x400;

/* registerRTSSynch__C */
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_registerRTSSynch__C, ".const:ti_sysbios_family_c66_Cache_registerRTSSynch__C");
__FAR__ const CT__ti_sysbios_family_c66_Cache_registerRTSSynch ti_sysbios_family_c66_Cache_registerRTSSynch__C = 0;

/* marvalues__C */
#pragma DATA_SECTION(ti_sysbios_family_c66_Cache_marvalues__C, ".const:ti_sysbios_family_c66_Cache_marvalues__C");
__FAR__ const CT__ti_sysbios_family_c66_Cache_marvalues ti_sysbios_family_c66_Cache_marvalues__C = {
    (xdc_UInt32)0x1,  /* [0] */
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
    (xdc_UInt32)0xd,  /* [12] */
    (xdc_UInt32)0xd,  /* [13] */
    (xdc_UInt32)0xd,  /* [14] */
    (xdc_UInt32)0xd,  /* [15] */
    (xdc_UInt32)0xc,  /* [16] */
    (xdc_UInt32)0xc,  /* [17] */
    (xdc_UInt32)0xc,  /* [18] */
    (xdc_UInt32)0xc,  /* [19] */
    (xdc_UInt32)0xc,  /* [20] */
    (xdc_UInt32)0xc,  /* [21] */
    (xdc_UInt32)0xc,  /* [22] */
    (xdc_UInt32)0xc,  /* [23] */
    (xdc_UInt32)0xc,  /* [24] */
    (xdc_UInt32)0xc,  /* [25] */
    (xdc_UInt32)0xc,  /* [26] */
    (xdc_UInt32)0xc,  /* [27] */
    (xdc_UInt32)0xc,  /* [28] */
    (xdc_UInt32)0xc,  /* [29] */
    (xdc_UInt32)0xc,  /* [30] */
    (xdc_UInt32)0xc,  /* [31] */
    (xdc_UInt32)0xc,  /* [32] */
    (xdc_UInt32)0xc,  /* [33] */
    (xdc_UInt32)0xc,  /* [34] */
    (xdc_UInt32)0xc,  /* [35] */
    (xdc_UInt32)0xc,  /* [36] */
    (xdc_UInt32)0xc,  /* [37] */
    (xdc_UInt32)0xc,  /* [38] */
    (xdc_UInt32)0xc,  /* [39] */
    (xdc_UInt32)0xc,  /* [40] */
    (xdc_UInt32)0xc,  /* [41] */
    (xdc_UInt32)0xc,  /* [42] */
    (xdc_UInt32)0xc,  /* [43] */
    (xdc_UInt32)0xc,  /* [44] */
    (xdc_UInt32)0xc,  /* [45] */
    (xdc_UInt32)0xc,  /* [46] */
    (xdc_UInt32)0xc,  /* [47] */
    (xdc_UInt32)0xc,  /* [48] */
    (xdc_UInt32)0xc,  /* [49] */
    (xdc_UInt32)0xc,  /* [50] */
    (xdc_UInt32)0xc,  /* [51] */
    (xdc_UInt32)0xc,  /* [52] */
    (xdc_UInt32)0xc,  /* [53] */
    (xdc_UInt32)0xc,  /* [54] */
    (xdc_UInt32)0xc,  /* [55] */
    (xdc_UInt32)0xc,  /* [56] */
    (xdc_UInt32)0xc,  /* [57] */
    (xdc_UInt32)0xc,  /* [58] */
    (xdc_UInt32)0xc,  /* [59] */
    (xdc_UInt32)0xc,  /* [60] */
    (xdc_UInt32)0xc,  /* [61] */
    (xdc_UInt32)0xc,  /* [62] */
    (xdc_UInt32)0xc,  /* [63] */
    (xdc_UInt32)0xd,  /* [64] */
    (xdc_UInt32)0xc,  /* [65] */
    (xdc_UInt32)0xc,  /* [66] */
    (xdc_UInt32)0xc,  /* [67] */
    (xdc_UInt32)0xc,  /* [68] */
    (xdc_UInt32)0xc,  /* [69] */
    (xdc_UInt32)0xc,  /* [70] */
    (xdc_UInt32)0xc,  /* [71] */
    (xdc_UInt32)0xc,  /* [72] */
    (xdc_UInt32)0xc,  /* [73] */
    (xdc_UInt32)0xc,  /* [74] */
    (xdc_UInt32)0xc,  /* [75] */
    (xdc_UInt32)0xc,  /* [76] */
    (xdc_UInt32)0xc,  /* [77] */
    (xdc_UInt32)0xc,  /* [78] */
    (xdc_UInt32)0xc,  /* [79] */
    (xdc_UInt32)0xc,  /* [80] */
    (xdc_UInt32)0xc,  /* [81] */
    (xdc_UInt32)0xc,  /* [82] */
    (xdc_UInt32)0xc,  /* [83] */
    (xdc_UInt32)0xc,  /* [84] */
    (xdc_UInt32)0xc,  /* [85] */
    (xdc_UInt32)0xc,  /* [86] */
    (xdc_UInt32)0xc,  /* [87] */
    (xdc_UInt32)0xc,  /* [88] */
    (xdc_UInt32)0xc,  /* [89] */
    (xdc_UInt32)0xc,  /* [90] */
    (xdc_UInt32)0xc,  /* [91] */
    (xdc_UInt32)0xc,  /* [92] */
    (xdc_UInt32)0xc,  /* [93] */
    (xdc_UInt32)0xc,  /* [94] */
    (xdc_UInt32)0xc,  /* [95] */
    (xdc_UInt32)0xc,  /* [96] */
    (xdc_UInt32)0xc,  /* [97] */
    (xdc_UInt32)0xc,  /* [98] */
    (xdc_UInt32)0xc,  /* [99] */
    (xdc_UInt32)0xc,  /* [100] */
    (xdc_UInt32)0xc,  /* [101] */
    (xdc_UInt32)0xc,  /* [102] */
    (xdc_UInt32)0xc,  /* [103] */
    (xdc_UInt32)0xc,  /* [104] */
    (xdc_UInt32)0xc,  /* [105] */
    (xdc_UInt32)0xc,  /* [106] */
    (xdc_UInt32)0xc,  /* [107] */
    (xdc_UInt32)0xc,  /* [108] */
    (xdc_UInt32)0xc,  /* [109] */
    (xdc_UInt32)0xc,  /* [110] */
    (xdc_UInt32)0xc,  /* [111] */
    (xdc_UInt32)0xc,  /* [112] */
    (xdc_UInt32)0xc,  /* [113] */
    (xdc_UInt32)0xc,  /* [114] */
    (xdc_UInt32)0xc,  /* [115] */
    (xdc_UInt32)0xc,  /* [116] */
    (xdc_UInt32)0xc,  /* [117] */
    (xdc_UInt32)0xc,  /* [118] */
    (xdc_UInt32)0xc,  /* [119] */
    (xdc_UInt32)0xc,  /* [120] */
    (xdc_UInt32)0xc,  /* [121] */
    (xdc_UInt32)0xc,  /* [122] */
    (xdc_UInt32)0xc,  /* [123] */
    (xdc_UInt32)0xc,  /* [124] */
    (xdc_UInt32)0xc,  /* [125] */
    (xdc_UInt32)0xc,  /* [126] */
    (xdc_UInt32)0xc,  /* [127] */
    (xdc_UInt32)0xc,  /* [128] */
    (xdc_UInt32)0xc,  /* [129] */
    (xdc_UInt32)0xc,  /* [130] */
    (xdc_UInt32)0xd,  /* [131] */
    (xdc_UInt32)0xc,  /* [132] */
    (xdc_UInt32)0xc,  /* [133] */
    (xdc_UInt32)0xc,  /* [134] */
    (xdc_UInt32)0xc,  /* [135] */
    (xdc_UInt32)0xc,  /* [136] */
    (xdc_UInt32)0xc,  /* [137] */
    (xdc_UInt32)0xd,  /* [138] */
    (xdc_UInt32)0xd,  /* [139] */
    (xdc_UInt32)0xd,  /* [140] */
    (xdc_UInt32)0xd,  /* [141] */
    (xdc_UInt32)0xc,  /* [142] */
    (xdc_UInt32)0xc,  /* [143] */
    (xdc_UInt32)0xc,  /* [144] */
    (xdc_UInt32)0xc,  /* [145] */
    (xdc_UInt32)0xc,  /* [146] */
    (xdc_UInt32)0xc,  /* [147] */
    (xdc_UInt32)0xc,  /* [148] */
    (xdc_UInt32)0xc,  /* [149] */
    (xdc_UInt32)0xc,  /* [150] */
    (xdc_UInt32)0xc,  /* [151] */
    (xdc_UInt32)0xc,  /* [152] */
    (xdc_UInt32)0xc,  /* [153] */
    (xdc_UInt32)0xc,  /* [154] */
    (xdc_UInt32)0xc,  /* [155] */
    (xdc_UInt32)0xc,  /* [156] */
    (xdc_UInt32)0xc,  /* [157] */
    (xdc_UInt32)0xc,  /* [158] */
    (xdc_UInt32)0xc,  /* [159] */
    (xdc_UInt32)0xd,  /* [160] */
    (xdc_UInt32)0xd,  /* [161] */
    (xdc_UInt32)0xd,  /* [162] */
    (xdc_UInt32)0xc,  /* [163] */
    (xdc_UInt32)0xc,  /* [164] */
    (xdc_UInt32)0xc,  /* [165] */
    (xdc_UInt32)0xc,  /* [166] */
    (xdc_UInt32)0xc,  /* [167] */
    (xdc_UInt32)0xc,  /* [168] */
    (xdc_UInt32)0xc,  /* [169] */
    (xdc_UInt32)0xc,  /* [170] */
    (xdc_UInt32)0xc,  /* [171] */
    (xdc_UInt32)0xc,  /* [172] */
    (xdc_UInt32)0xc,  /* [173] */
    (xdc_UInt32)0xc,  /* [174] */
    (xdc_UInt32)0xc,  /* [175] */
    (xdc_UInt32)0xc,  /* [176] */
    (xdc_UInt32)0xc,  /* [177] */
    (xdc_UInt32)0xc,  /* [178] */
    (xdc_UInt32)0xc,  /* [179] */
    (xdc_UInt32)0xc,  /* [180] */
    (xdc_UInt32)0xc,  /* [181] */
    (xdc_UInt32)0xc,  /* [182] */
    (xdc_UInt32)0xc,  /* [183] */
    (xdc_UInt32)0xc,  /* [184] */
    (xdc_UInt32)0xc,  /* [185] */
    (xdc_UInt32)0xc,  /* [186] */
    (xdc_UInt32)0xc,  /* [187] */
    (xdc_UInt32)0xc,  /* [188] */
    (xdc_UInt32)0xc,  /* [189] */
    (xdc_UInt32)0xc,  /* [190] */
    (xdc_UInt32)0xc,  /* [191] */
    (xdc_UInt32)0xc,  /* [192] */
    (xdc_UInt32)0xc,  /* [193] */
    (xdc_UInt32)0xc,  /* [194] */
    (xdc_UInt32)0xc,  /* [195] */
    (xdc_UInt32)0xc,  /* [196] */
    (xdc_UInt32)0xc,  /* [197] */
    (xdc_UInt32)0xc,  /* [198] */
    (xdc_UInt32)0xc,  /* [199] */
    (xdc_UInt32)0xc,  /* [200] */
    (xdc_UInt32)0xc,  /* [201] */
    (xdc_UInt32)0xc,  /* [202] */
    (xdc_UInt32)0xc,  /* [203] */
    (xdc_UInt32)0xc,  /* [204] */
    (xdc_UInt32)0xc,  /* [205] */
    (xdc_UInt32)0xc,  /* [206] */
    (xdc_UInt32)0xc,  /* [207] */
    (xdc_UInt32)0xc,  /* [208] */
    (xdc_UInt32)0xc,  /* [209] */
    (xdc_UInt32)0xc,  /* [210] */
    (xdc_UInt32)0xc,  /* [211] */
    (xdc_UInt32)0xc,  /* [212] */
    (xdc_UInt32)0xc,  /* [213] */
    (xdc_UInt32)0xc,  /* [214] */
    (xdc_UInt32)0xc,  /* [215] */
    (xdc_UInt32)0xc,  /* [216] */
    (xdc_UInt32)0xc,  /* [217] */
    (xdc_UInt32)0xc,  /* [218] */
    (xdc_UInt32)0xc,  /* [219] */
    (xdc_UInt32)0xc,  /* [220] */
    (xdc_UInt32)0xc,  /* [221] */
    (xdc_UInt32)0xc,  /* [222] */
    (xdc_UInt32)0xc,  /* [223] */
    (xdc_UInt32)0xc,  /* [224] */
    (xdc_UInt32)0xc,  /* [225] */
    (xdc_UInt32)0xc,  /* [226] */
    (xdc_UInt32)0xc,  /* [227] */
    (xdc_UInt32)0xc,  /* [228] */
    (xdc_UInt32)0xc,  /* [229] */
    (xdc_UInt32)0xc,  /* [230] */
    (xdc_UInt32)0xc,  /* [231] */
    (xdc_UInt32)0xc,  /* [232] */
    (xdc_UInt32)0xc,  /* [233] */
    (xdc_UInt32)0xc,  /* [234] */
    (xdc_UInt32)0xc,  /* [235] */
    (xdc_UInt32)0xc,  /* [236] */
    (xdc_UInt32)0xc,  /* [237] */
    (xdc_UInt32)0xc,  /* [238] */
    (xdc_UInt32)0xc,  /* [239] */
    (xdc_UInt32)0xc,  /* [240] */
    (xdc_UInt32)0xc,  /* [241] */
    (xdc_UInt32)0xc,  /* [242] */
    (xdc_UInt32)0xc,  /* [243] */
    (xdc_UInt32)0xc,  /* [244] */
    (xdc_UInt32)0xc,  /* [245] */
    (xdc_UInt32)0xc,  /* [246] */
    (xdc_UInt32)0xc,  /* [247] */
    (xdc_UInt32)0xc,  /* [248] */
    (xdc_UInt32)0xc,  /* [249] */
    (xdc_UInt32)0xc,  /* [250] */
    (xdc_UInt32)0xc,  /* [251] */
    (xdc_UInt32)0xc,  /* [252] */
    (xdc_UInt32)0xc,  /* [253] */
    (xdc_UInt32)0xc,  /* [254] */
    (xdc_UInt32)0xc,  /* [255] */
};


/*
 * ======== ti.sysbios.family.shared.vayu.IntXbar INITIALIZERS ========
 */

/* --> ti_sysbios_family_shared_vayu_IntXbar_Module_State_0_intXbar__A */
__T1_ti_sysbios_family_shared_vayu_IntXbar_Module_State__intXbar ti_sysbios_family_shared_vayu_IntXbar_Module_State_0_intXbar__A[64] = {
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
    (xdc_UInt16)0x0,  /* [57] */
    (xdc_UInt16)0x0,  /* [58] */
    (xdc_UInt16)0x0,  /* [59] */
    (xdc_UInt16)0x0,  /* [60] */
    (xdc_UInt16)0x0,  /* [61] */
    (xdc_UInt16)0x0,  /* [62] */
    (xdc_UInt16)0x0,  /* [63] */
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
const __T1_ti_sysbios_family_shared_vayu_IntXbar_intXbar ti_sysbios_family_shared_vayu_IntXbar_intXbar__A[64] = {
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
    (xdc_UInt16)0x0,  /* [57] */
    (xdc_UInt16)0x0,  /* [58] */
    (xdc_UInt16)0x0,  /* [59] */
    (xdc_UInt16)0x0,  /* [60] */
    (xdc_UInt16)0x0,  /* [61] */
    (xdc_UInt16)0x0,  /* [62] */
    (xdc_UInt16)0x0,  /* [63] */
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
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_Module__id ti_sysbios_family_shared_vayu_IntXbar_Module__id__C = (xdc_Bits16)0x802a;

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
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_A_badEveXbarInstanceNum ti_sysbios_family_shared_vayu_IntXbar_A_badEveXbarInstanceNum__C = (((xdc_runtime_Assert_Id)1825) << 16 | 16);

/* A_badDspXbarInstanceNum__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_A_badDspXbarInstanceNum__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_A_badDspXbarInstanceNum__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_A_badDspXbarInstanceNum ti_sysbios_family_shared_vayu_IntXbar_A_badDspXbarInstanceNum__C = (((xdc_runtime_Assert_Id)1885) << 16 | 16);

/* A_badBenelliXbarInstanceNum__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_A_badBenelliXbarInstanceNum__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_A_badBenelliXbarInstanceNum__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_A_badBenelliXbarInstanceNum ti_sysbios_family_shared_vayu_IntXbar_A_badBenelliXbarInstanceNum__C = (((xdc_runtime_Assert_Id)1946) << 16 | 16);

/* A_badA15XbarInstanceNum__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_A_badA15XbarInstanceNum__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_A_badA15XbarInstanceNum__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_A_badA15XbarInstanceNum ti_sysbios_family_shared_vayu_IntXbar_A_badA15XbarInstanceNum__C = (((xdc_runtime_Assert_Id)2011) << 16 | 16);

/* A_badEveIRQNum__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_A_badEveIRQNum__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_A_badEveIRQNum__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_A_badEveIRQNum ti_sysbios_family_shared_vayu_IntXbar_A_badEveIRQNum__C = (((xdc_runtime_Assert_Id)2073) << 16 | 16);

/* A_badDspIRQNum__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_A_badDspIRQNum__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_A_badDspIRQNum__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_A_badDspIRQNum ti_sysbios_family_shared_vayu_IntXbar_A_badDspIRQNum__C = (((xdc_runtime_Assert_Id)2113) << 16 | 16);

/* A_badBenelliIRQNum__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_A_badBenelliIRQNum__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_A_badBenelliIRQNum__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_A_badBenelliIRQNum ti_sysbios_family_shared_vayu_IntXbar_A_badBenelliIRQNum__C = (((xdc_runtime_Assert_Id)2164) << 16 | 16);

/* A_badA15IRQNum__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_A_badA15IRQNum__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_A_badA15IRQNum__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_A_badA15IRQNum ti_sysbios_family_shared_vayu_IntXbar_A_badA15IRQNum__C = (((xdc_runtime_Assert_Id)2219) << 16 | 16);

/* A_badIntSourceIdx__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_A_badIntSourceIdx__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_A_badIntSourceIdx__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_A_badIntSourceIdx ti_sysbios_family_shared_vayu_IntXbar_A_badIntSourceIdx__C = (((xdc_runtime_Assert_Id)2283) << 16 | 16);

/* A_badEveCpuId__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_A_badEveCpuId__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_A_badEveCpuId__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_A_badEveCpuId ti_sysbios_family_shared_vayu_IntXbar_A_badEveCpuId__C = (((xdc_runtime_Assert_Id)2353) << 16 | 16);

/* A_badDspCpuId__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_A_badDspCpuId__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_A_badDspCpuId__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_A_badDspCpuId ti_sysbios_family_shared_vayu_IntXbar_A_badDspCpuId__C = (((xdc_runtime_Assert_Id)2396) << 16 | 16);

/* A_badBenelliIpuId__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_A_badBenelliIpuId__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_A_badBenelliIpuId__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_A_badBenelliIpuId ti_sysbios_family_shared_vayu_IntXbar_A_badBenelliIpuId__C = (((xdc_runtime_Assert_Id)2433) << 16 | 16);

/* mmrBaseAddr__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_mmrBaseAddr__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_mmrBaseAddr__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_mmrBaseAddr ti_sysbios_family_shared_vayu_IntXbar_mmrBaseAddr__C = (xdc_UInt32)0x4a002000;

/* intXbar__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_IntXbar_intXbar__C, ".const:ti_sysbios_family_shared_vayu_IntXbar_intXbar__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_IntXbar_intXbar ti_sysbios_family_shared_vayu_IntXbar_intXbar__C = ((CT__ti_sysbios_family_shared_vayu_IntXbar_intXbar)ti_sysbios_family_shared_vayu_IntXbar_intXbar__A);


/*
 * ======== ti.sysbios.family.shared.vayu.TimerSupport INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_TimerSupport_Module__diagsEnabled__C, ".const:ti_sysbios_family_shared_vayu_TimerSupport_Module__diagsEnabled__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_TimerSupport_Module__diagsEnabled ti_sysbios_family_shared_vayu_TimerSupport_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_TimerSupport_Module__diagsIncluded__C, ".const:ti_sysbios_family_shared_vayu_TimerSupport_Module__diagsIncluded__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_TimerSupport_Module__diagsIncluded ti_sysbios_family_shared_vayu_TimerSupport_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_TimerSupport_Module__diagsMask__C, ".const:ti_sysbios_family_shared_vayu_TimerSupport_Module__diagsMask__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_TimerSupport_Module__diagsMask ti_sysbios_family_shared_vayu_TimerSupport_Module__diagsMask__C = ((CT__ti_sysbios_family_shared_vayu_TimerSupport_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_TimerSupport_Module__gateObj__C, ".const:ti_sysbios_family_shared_vayu_TimerSupport_Module__gateObj__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_TimerSupport_Module__gateObj ti_sysbios_family_shared_vayu_TimerSupport_Module__gateObj__C = ((CT__ti_sysbios_family_shared_vayu_TimerSupport_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_TimerSupport_Module__gatePrms__C, ".const:ti_sysbios_family_shared_vayu_TimerSupport_Module__gatePrms__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_TimerSupport_Module__gatePrms ti_sysbios_family_shared_vayu_TimerSupport_Module__gatePrms__C = ((CT__ti_sysbios_family_shared_vayu_TimerSupport_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_TimerSupport_Module__id__C, ".const:ti_sysbios_family_shared_vayu_TimerSupport_Module__id__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_TimerSupport_Module__id ti_sysbios_family_shared_vayu_TimerSupport_Module__id__C = (xdc_Bits16)0x802b;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_TimerSupport_Module__loggerDefined__C, ".const:ti_sysbios_family_shared_vayu_TimerSupport_Module__loggerDefined__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_TimerSupport_Module__loggerDefined ti_sysbios_family_shared_vayu_TimerSupport_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_TimerSupport_Module__loggerObj__C, ".const:ti_sysbios_family_shared_vayu_TimerSupport_Module__loggerObj__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_TimerSupport_Module__loggerObj ti_sysbios_family_shared_vayu_TimerSupport_Module__loggerObj__C = ((CT__ti_sysbios_family_shared_vayu_TimerSupport_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_TimerSupport_Module__loggerFxn0__C, ".const:ti_sysbios_family_shared_vayu_TimerSupport_Module__loggerFxn0__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_TimerSupport_Module__loggerFxn0 ti_sysbios_family_shared_vayu_TimerSupport_Module__loggerFxn0__C = ((CT__ti_sysbios_family_shared_vayu_TimerSupport_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_TimerSupport_Module__loggerFxn1__C, ".const:ti_sysbios_family_shared_vayu_TimerSupport_Module__loggerFxn1__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_TimerSupport_Module__loggerFxn1 ti_sysbios_family_shared_vayu_TimerSupport_Module__loggerFxn1__C = ((CT__ti_sysbios_family_shared_vayu_TimerSupport_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_TimerSupport_Module__loggerFxn2__C, ".const:ti_sysbios_family_shared_vayu_TimerSupport_Module__loggerFxn2__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_TimerSupport_Module__loggerFxn2 ti_sysbios_family_shared_vayu_TimerSupport_Module__loggerFxn2__C = ((CT__ti_sysbios_family_shared_vayu_TimerSupport_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_TimerSupport_Module__loggerFxn4__C, ".const:ti_sysbios_family_shared_vayu_TimerSupport_Module__loggerFxn4__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_TimerSupport_Module__loggerFxn4 ti_sysbios_family_shared_vayu_TimerSupport_Module__loggerFxn4__C = ((CT__ti_sysbios_family_shared_vayu_TimerSupport_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_TimerSupport_Module__loggerFxn8__C, ".const:ti_sysbios_family_shared_vayu_TimerSupport_Module__loggerFxn8__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_TimerSupport_Module__loggerFxn8 ti_sysbios_family_shared_vayu_TimerSupport_Module__loggerFxn8__C = ((CT__ti_sysbios_family_shared_vayu_TimerSupport_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_TimerSupport_Module__startupDoneFxn__C, ".const:ti_sysbios_family_shared_vayu_TimerSupport_Module__startupDoneFxn__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_TimerSupport_Module__startupDoneFxn ti_sysbios_family_shared_vayu_TimerSupport_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_shared_vayu_TimerSupport_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_TimerSupport_Object__count__C, ".const:ti_sysbios_family_shared_vayu_TimerSupport_Object__count__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_TimerSupport_Object__count ti_sysbios_family_shared_vayu_TimerSupport_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_TimerSupport_Object__heap__C, ".const:ti_sysbios_family_shared_vayu_TimerSupport_Object__heap__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_TimerSupport_Object__heap ti_sysbios_family_shared_vayu_TimerSupport_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_TimerSupport_Object__sizeof__C, ".const:ti_sysbios_family_shared_vayu_TimerSupport_Object__sizeof__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_TimerSupport_Object__sizeof ti_sysbios_family_shared_vayu_TimerSupport_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_TimerSupport_Object__table__C, ".const:ti_sysbios_family_shared_vayu_TimerSupport_Object__table__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_TimerSupport_Object__table ti_sysbios_family_shared_vayu_TimerSupport_Object__table__C = 0;

/* availMask__C */
#pragma DATA_SECTION(ti_sysbios_family_shared_vayu_TimerSupport_availMask__C, ".const:ti_sysbios_family_shared_vayu_TimerSupport_availMask__C");
__FAR__ const CT__ti_sysbios_family_shared_vayu_TimerSupport_availMask ti_sysbios_family_shared_vayu_TimerSupport_availMask__C = (xdc_Bits32)0x20;


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
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__id ti_sysbios_gates_GateHwi_Module__id__C = (xdc_Bits16)0x8036;

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
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__id ti_sysbios_gates_GateMutex_Module__id__C = (xdc_Bits16)0x8037;

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
__FAR__ const CT__ti_sysbios_gates_GateMutex_A_badContext ti_sysbios_gates_GateMutex_A_badContext__C = (((xdc_runtime_Assert_Id)3137) << 16 | 16);


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
__FAR__ const CT__ti_sysbios_hal_Cache_Module__id ti_sysbios_hal_Cache_Module__id__C = (xdc_Bits16)0x8023;

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
    ti_sysbios_interfaces_IHwi_MaskingOption_SELF,  /* maskSetting */
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

/* Object__table__V */
ti_sysbios_hal_Hwi_Object__ ti_sysbios_hal_Hwi_Object__table__V[1] = {
    {/* instance#0 */
        0,
        (ti_sysbios_hal_Hwi_HwiProxy_Handle)&ti_sysbios_family_c64p_Hwi_Object__table__V[4],  /* pi */
    },
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
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__id ti_sysbios_hal_Hwi_Module__id__C = (xdc_Bits16)0x8024;

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
__FAR__ const CT__ti_sysbios_hal_Hwi_Object__count ti_sysbios_hal_Hwi_Object__count__C = 1;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Object__heap__C, ".const:ti_sysbios_hal_Hwi_Object__heap__C");
__FAR__ const CT__ti_sysbios_hal_Hwi_Object__heap ti_sysbios_hal_Hwi_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Object__sizeof__C, ".const:ti_sysbios_hal_Hwi_Object__sizeof__C");
__FAR__ const CT__ti_sysbios_hal_Hwi_Object__sizeof ti_sysbios_hal_Hwi_Object__sizeof__C = sizeof(ti_sysbios_hal_Hwi_Object__);

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Object__table__C, ".const:ti_sysbios_hal_Hwi_Object__table__C");
__FAR__ const CT__ti_sysbios_hal_Hwi_Object__table ti_sysbios_hal_Hwi_Object__table__C = ti_sysbios_hal_Hwi_Object__table__V;

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
__FAR__ const CT__ti_sysbios_hal_Hwi_E_stackOverflow ti_sysbios_hal_Hwi_E_stackOverflow__C = (((xdc_runtime_Error_Id)5231) << 16 | 0);


/*
 * ======== ti.sysbios.hal.Hwi_HwiProxy INITIALIZERS ========
 */


/*
 * ======== ti.sysbios.hal.TimerNull INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_hal_TimerNull_Object__DESC__C;

/* Object__PARAMS__C */
#pragma DATA_SECTION(ti_sysbios_hal_TimerNull_Object__PARAMS__C, ".const:ti_sysbios_hal_TimerNull_Object__PARAMS__C");
__FAR__ const ti_sysbios_hal_TimerNull_Params ti_sysbios_hal_TimerNull_Object__PARAMS__C = {
    sizeof (ti_sysbios_hal_TimerNull_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_hal_TimerNull_Object__PARAMS__C.__iprms, /* instance */
    ti_sysbios_interfaces_ITimer_RunMode_CONTINUOUS,  /* runMode */
    ti_sysbios_interfaces_ITimer_StartMode_AUTO,  /* startMode */
    ((xdc_UArg)0),  /* arg */
    (xdc_UInt32)0x0,  /* period */
    ti_sysbios_interfaces_ITimer_PeriodType_MICROSECS,  /* periodType */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)0x0,  /* lo */
    },  /* extFreq */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_hal_TimerNull_Module__ ti_sysbios_hal_TimerNull_Module__root__V = {
    {&ti_sysbios_hal_TimerNull_Module__root__V.link,  /* link.next */
    &ti_sysbios_hal_TimerNull_Module__root__V.link},  /* link.prev */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_hal_TimerNull_Module__diagsEnabled__C, ".const:ti_sysbios_hal_TimerNull_Module__diagsEnabled__C");
__FAR__ const CT__ti_sysbios_hal_TimerNull_Module__diagsEnabled ti_sysbios_hal_TimerNull_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_hal_TimerNull_Module__diagsIncluded__C, ".const:ti_sysbios_hal_TimerNull_Module__diagsIncluded__C");
__FAR__ const CT__ti_sysbios_hal_TimerNull_Module__diagsIncluded ti_sysbios_hal_TimerNull_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_hal_TimerNull_Module__diagsMask__C, ".const:ti_sysbios_hal_TimerNull_Module__diagsMask__C");
__FAR__ const CT__ti_sysbios_hal_TimerNull_Module__diagsMask ti_sysbios_hal_TimerNull_Module__diagsMask__C = ((CT__ti_sysbios_hal_TimerNull_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_hal_TimerNull_Module__gateObj__C, ".const:ti_sysbios_hal_TimerNull_Module__gateObj__C");
__FAR__ const CT__ti_sysbios_hal_TimerNull_Module__gateObj ti_sysbios_hal_TimerNull_Module__gateObj__C = ((CT__ti_sysbios_hal_TimerNull_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_hal_TimerNull_Module__gatePrms__C, ".const:ti_sysbios_hal_TimerNull_Module__gatePrms__C");
__FAR__ const CT__ti_sysbios_hal_TimerNull_Module__gatePrms ti_sysbios_hal_TimerNull_Module__gatePrms__C = ((CT__ti_sysbios_hal_TimerNull_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_hal_TimerNull_Module__id__C, ".const:ti_sysbios_hal_TimerNull_Module__id__C");
__FAR__ const CT__ti_sysbios_hal_TimerNull_Module__id ti_sysbios_hal_TimerNull_Module__id__C = (xdc_Bits16)0x8025;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_hal_TimerNull_Module__loggerDefined__C, ".const:ti_sysbios_hal_TimerNull_Module__loggerDefined__C");
__FAR__ const CT__ti_sysbios_hal_TimerNull_Module__loggerDefined ti_sysbios_hal_TimerNull_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_hal_TimerNull_Module__loggerObj__C, ".const:ti_sysbios_hal_TimerNull_Module__loggerObj__C");
__FAR__ const CT__ti_sysbios_hal_TimerNull_Module__loggerObj ti_sysbios_hal_TimerNull_Module__loggerObj__C = ((CT__ti_sysbios_hal_TimerNull_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_hal_TimerNull_Module__loggerFxn0__C, ".const:ti_sysbios_hal_TimerNull_Module__loggerFxn0__C");
__FAR__ const CT__ti_sysbios_hal_TimerNull_Module__loggerFxn0 ti_sysbios_hal_TimerNull_Module__loggerFxn0__C = ((CT__ti_sysbios_hal_TimerNull_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_hal_TimerNull_Module__loggerFxn1__C, ".const:ti_sysbios_hal_TimerNull_Module__loggerFxn1__C");
__FAR__ const CT__ti_sysbios_hal_TimerNull_Module__loggerFxn1 ti_sysbios_hal_TimerNull_Module__loggerFxn1__C = ((CT__ti_sysbios_hal_TimerNull_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_hal_TimerNull_Module__loggerFxn2__C, ".const:ti_sysbios_hal_TimerNull_Module__loggerFxn2__C");
__FAR__ const CT__ti_sysbios_hal_TimerNull_Module__loggerFxn2 ti_sysbios_hal_TimerNull_Module__loggerFxn2__C = ((CT__ti_sysbios_hal_TimerNull_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_hal_TimerNull_Module__loggerFxn4__C, ".const:ti_sysbios_hal_TimerNull_Module__loggerFxn4__C");
__FAR__ const CT__ti_sysbios_hal_TimerNull_Module__loggerFxn4 ti_sysbios_hal_TimerNull_Module__loggerFxn4__C = ((CT__ti_sysbios_hal_TimerNull_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_hal_TimerNull_Module__loggerFxn8__C, ".const:ti_sysbios_hal_TimerNull_Module__loggerFxn8__C");
__FAR__ const CT__ti_sysbios_hal_TimerNull_Module__loggerFxn8 ti_sysbios_hal_TimerNull_Module__loggerFxn8__C = ((CT__ti_sysbios_hal_TimerNull_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(ti_sysbios_hal_TimerNull_Module__startupDoneFxn__C, ".const:ti_sysbios_hal_TimerNull_Module__startupDoneFxn__C");
__FAR__ const CT__ti_sysbios_hal_TimerNull_Module__startupDoneFxn ti_sysbios_hal_TimerNull_Module__startupDoneFxn__C = ((CT__ti_sysbios_hal_TimerNull_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_hal_TimerNull_Object__count__C, ".const:ti_sysbios_hal_TimerNull_Object__count__C");
__FAR__ const CT__ti_sysbios_hal_TimerNull_Object__count ti_sysbios_hal_TimerNull_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_hal_TimerNull_Object__heap__C, ".const:ti_sysbios_hal_TimerNull_Object__heap__C");
__FAR__ const CT__ti_sysbios_hal_TimerNull_Object__heap ti_sysbios_hal_TimerNull_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_hal_TimerNull_Object__sizeof__C, ".const:ti_sysbios_hal_TimerNull_Object__sizeof__C");
__FAR__ const CT__ti_sysbios_hal_TimerNull_Object__sizeof ti_sysbios_hal_TimerNull_Object__sizeof__C = sizeof(ti_sysbios_hal_TimerNull_Object__);

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_hal_TimerNull_Object__table__C, ".const:ti_sysbios_hal_TimerNull_Object__table__C");
__FAR__ const CT__ti_sysbios_hal_TimerNull_Object__table ti_sysbios_hal_TimerNull_Object__table__C = 0;


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
__T1_ti_sysbios_heaps_HeapMem_Instance_State__buf ti_sysbios_heaps_HeapMem_Instance_State_0_buf__A[4096];

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
            ((xdc_UArg)(0x1000)),  /* size */
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
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__id ti_sysbios_heaps_HeapMem_Module__id__C = (xdc_Bits16)0x8039;

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
__FAR__ const CT__ti_sysbios_heaps_HeapMem_A_zeroBlock ti_sysbios_heaps_HeapMem_A_zeroBlock__C = (((xdc_runtime_Assert_Id)3823) << 16 | 16);

/* A_heapSize__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_A_heapSize__C, ".const:ti_sysbios_heaps_HeapMem_A_heapSize__C");
__FAR__ const CT__ti_sysbios_heaps_HeapMem_A_heapSize ti_sysbios_heaps_HeapMem_A_heapSize__C = (((xdc_runtime_Assert_Id)3859) << 16 | 16);

/* A_align__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_A_align__C, ".const:ti_sysbios_heaps_HeapMem_A_align__C");
__FAR__ const CT__ti_sysbios_heaps_HeapMem_A_align ti_sysbios_heaps_HeapMem_A_align__C = (((xdc_runtime_Assert_Id)3904) << 16 | 16);

/* E_memory__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_E_memory__C, ".const:ti_sysbios_heaps_HeapMem_E_memory__C");
__FAR__ const CT__ti_sysbios_heaps_HeapMem_E_memory ti_sysbios_heaps_HeapMem_E_memory__C = (((xdc_runtime_Error_Id)5774) << 16 | 0);

/* A_invalidFree__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_A_invalidFree__C, ".const:ti_sysbios_heaps_HeapMem_A_invalidFree__C");
__FAR__ const CT__ti_sysbios_heaps_HeapMem_A_invalidFree ti_sysbios_heaps_HeapMem_A_invalidFree__C = (((xdc_runtime_Assert_Id)3795) << 16 | 16);

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
    0,  /* timer */
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
__FAR__ const CT__ti_sysbios_knl_Clock_Module__id ti_sysbios_knl_Clock_Module__id__C = (xdc_Bits16)0x801a;

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
__FAR__ const CT__ti_sysbios_knl_Clock_LW_delayed ti_sysbios_knl_Clock_LW_delayed__C = (((xdc_runtime_Log_Event)6074) << 16 | 1024);

/* LM_tick__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_LM_tick__C, ".const:ti_sysbios_knl_Clock_LM_tick__C");
__FAR__ const CT__ti_sysbios_knl_Clock_LM_tick ti_sysbios_knl_Clock_LM_tick__C = (((xdc_runtime_Log_Event)6096) << 16 | 768);

/* LM_begin__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_LM_begin__C, ".const:ti_sysbios_knl_Clock_LM_begin__C");
__FAR__ const CT__ti_sysbios_knl_Clock_LM_begin ti_sysbios_knl_Clock_LM_begin__C = (((xdc_runtime_Log_Event)6114) << 16 | 768);

/* A_clockDisabled__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_A_clockDisabled__C, ".const:ti_sysbios_knl_Clock_A_clockDisabled__C");
__FAR__ const CT__ti_sysbios_knl_Clock_A_clockDisabled ti_sysbios_knl_Clock_A_clockDisabled__C = (((xdc_runtime_Assert_Id)445) << 16 | 16);

/* A_badThreadType__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_A_badThreadType__C, ".const:ti_sysbios_knl_Clock_A_badThreadType__C");
__FAR__ const CT__ti_sysbios_knl_Clock_A_badThreadType ti_sysbios_knl_Clock_A_badThreadType__C = (((xdc_runtime_Assert_Id)526) << 16 | 16);

/* serviceMargin__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_serviceMargin__C, ".const:ti_sysbios_knl_Clock_serviceMargin__C");
__FAR__ const CT__ti_sysbios_knl_Clock_serviceMargin ti_sysbios_knl_Clock_serviceMargin__C = (xdc_UInt32)0x0;

/* tickSource__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_tickSource__C, ".const:ti_sysbios_knl_Clock_tickSource__C");
__FAR__ const CT__ti_sysbios_knl_Clock_tickSource ti_sysbios_knl_Clock_tickSource__C = ti_sysbios_knl_Clock_TickSource_USER;

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

/* --> ti_sysbios_knl_Idle_funcList__A */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_funcList__A, ".const:ti_sysbios_knl_Idle_funcList__A");
const __T1_ti_sysbios_knl_Idle_funcList ti_sysbios_knl_Idle_funcList__A[1] = {
    ((xdc_Void(*)(xdc_Void))((xdc_Fxn)ti_sysbios_hal_Hwi_checkStack)),  /* [0] */
};

/* --> ti_sysbios_knl_Idle_coreList__A */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_coreList__A, ".const:ti_sysbios_knl_Idle_coreList__A");
const __T1_ti_sysbios_knl_Idle_coreList ti_sysbios_knl_Idle_coreList__A[1] = {
    (xdc_UInt)0x0,  /* [0] */
};

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
__FAR__ const CT__ti_sysbios_knl_Idle_Module__id ti_sysbios_knl_Idle_Module__id__C = (xdc_Bits16)0x801b;

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
__FAR__ const CT__ti_sysbios_knl_Idle_funcList ti_sysbios_knl_Idle_funcList__C = {1, ((__T1_ti_sysbios_knl_Idle_funcList*)ti_sysbios_knl_Idle_funcList__A)};

/* coreList__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_coreList__C, ".const:ti_sysbios_knl_Idle_coreList__C");
__FAR__ const CT__ti_sysbios_knl_Idle_coreList ti_sysbios_knl_Idle_coreList__C = {1, ((__T1_ti_sysbios_knl_Idle_coreList*)ti_sysbios_knl_Idle_coreList__A)};


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
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__id ti_sysbios_knl_Intrinsics_Module__id__C = (xdc_Bits16)0x801c;

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
__FAR__ const CT__ti_sysbios_knl_Queue_Module__id ti_sysbios_knl_Queue_Module__id__C = (xdc_Bits16)0x801d;

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
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__id ti_sysbios_knl_Semaphore_Module__id__C = (xdc_Bits16)0x801e;

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
__FAR__ const CT__ti_sysbios_knl_Semaphore_LM_post ti_sysbios_knl_Semaphore_LM_post__C = (((xdc_runtime_Log_Event)6146) << 16 | 768);

/* LM_pend__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_LM_pend__C, ".const:ti_sysbios_knl_Semaphore_LM_pend__C");
__FAR__ const CT__ti_sysbios_knl_Semaphore_LM_pend ti_sysbios_knl_Semaphore_LM_pend__C = (((xdc_runtime_Log_Event)6176) << 16 | 768);

/* A_noEvents__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_A_noEvents__C, ".const:ti_sysbios_knl_Semaphore_A_noEvents__C");
__FAR__ const CT__ti_sysbios_knl_Semaphore_A_noEvents ti_sysbios_knl_Semaphore_A_noEvents__C = (((xdc_runtime_Assert_Id)936) << 16 | 16);

/* A_invTimeout__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_A_invTimeout__C, ".const:ti_sysbios_knl_Semaphore_A_invTimeout__C");
__FAR__ const CT__ti_sysbios_knl_Semaphore_A_invTimeout ti_sysbios_knl_Semaphore_A_invTimeout__C = (((xdc_runtime_Assert_Id)991) << 16 | 16);

/* A_badContext__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_A_badContext__C, ".const:ti_sysbios_knl_Semaphore_A_badContext__C");
__FAR__ const CT__ti_sysbios_knl_Semaphore_A_badContext ti_sysbios_knl_Semaphore_A_badContext__C = (((xdc_runtime_Assert_Id)725) << 16 | 16);

/* A_overflow__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_A_overflow__C, ".const:ti_sysbios_knl_Semaphore_A_overflow__C");
__FAR__ const CT__ti_sysbios_knl_Semaphore_A_overflow ti_sysbios_knl_Semaphore_A_overflow__C = (((xdc_runtime_Assert_Id)1056) << 16 | 16);

/* A_pendTaskDisabled__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_A_pendTaskDisabled__C, ".const:ti_sysbios_knl_Semaphore_A_pendTaskDisabled__C");
__FAR__ const CT__ti_sysbios_knl_Semaphore_A_pendTaskDisabled ti_sysbios_knl_Semaphore_A_pendTaskDisabled__C = (((xdc_runtime_Assert_Id)1110) << 16 | 16);

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
__FAR__ const CT__ti_sysbios_knl_Swi_Module__id ti_sysbios_knl_Swi_Module__id__C = (xdc_Bits16)0x801f;

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
__FAR__ const CT__ti_sysbios_knl_Swi_LM_begin ti_sysbios_knl_Swi_LM_begin__C = (((xdc_runtime_Log_Event)6219) << 16 | 768);

/* LD_end__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_LD_end__C, ".const:ti_sysbios_knl_Swi_LD_end__C");
__FAR__ const CT__ti_sysbios_knl_Swi_LD_end ti_sysbios_knl_Swi_LD_end__C = (((xdc_runtime_Log_Event)6266) << 16 | 512);

/* LM_post__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_LM_post__C, ".const:ti_sysbios_knl_Swi_LM_post__C");
__FAR__ const CT__ti_sysbios_knl_Swi_LM_post ti_sysbios_knl_Swi_LM_post__C = (((xdc_runtime_Log_Event)6284) << 16 | 768);

/* A_swiDisabled__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_A_swiDisabled__C, ".const:ti_sysbios_knl_Swi_A_swiDisabled__C");
__FAR__ const CT__ti_sysbios_knl_Swi_A_swiDisabled ti_sysbios_knl_Swi_A_swiDisabled__C = (((xdc_runtime_Assert_Id)1204) << 16 | 16);

/* A_badPriority__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_A_badPriority__C, ".const:ti_sysbios_knl_Swi_A_badPriority__C");
__FAR__ const CT__ti_sysbios_knl_Swi_A_badPriority ti_sysbios_knl_Swi_A_badPriority__C = (((xdc_runtime_Assert_Id)1261) << 16 | 16);

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
__FAR__ const CT__ti_sysbios_knl_Task_Module__id ti_sysbios_knl_Task_Module__id__C = (xdc_Bits16)0x8020;

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
__FAR__ const CT__ti_sysbios_knl_Task_LM_switch ti_sysbios_knl_Task_LM_switch__C = (((xdc_runtime_Log_Event)6324) << 16 | 768);

/* LM_sleep__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_LM_sleep__C, ".const:ti_sysbios_knl_Task_LM_sleep__C");
__FAR__ const CT__ti_sysbios_knl_Task_LM_sleep ti_sysbios_knl_Task_LM_sleep__C = (((xdc_runtime_Log_Event)6392) << 16 | 768);

/* LD_ready__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_LD_ready__C, ".const:ti_sysbios_knl_Task_LD_ready__C");
__FAR__ const CT__ti_sysbios_knl_Task_LD_ready ti_sysbios_knl_Task_LD_ready__C = (((xdc_runtime_Log_Event)6437) << 16 | 512);

/* LD_block__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_LD_block__C, ".const:ti_sysbios_knl_Task_LD_block__C");
__FAR__ const CT__ti_sysbios_knl_Task_LD_block ti_sysbios_knl_Task_LD_block__C = (((xdc_runtime_Log_Event)6478) << 16 | 512);

/* LM_yield__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_LM_yield__C, ".const:ti_sysbios_knl_Task_LM_yield__C");
__FAR__ const CT__ti_sysbios_knl_Task_LM_yield ti_sysbios_knl_Task_LM_yield__C = (((xdc_runtime_Log_Event)6510) << 16 | 768);

/* LM_setPri__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_LM_setPri__C, ".const:ti_sysbios_knl_Task_LM_setPri__C");
__FAR__ const CT__ti_sysbios_knl_Task_LM_setPri ti_sysbios_knl_Task_LM_setPri__C = (((xdc_runtime_Log_Event)6558) << 16 | 768);

/* LD_exit__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_LD_exit__C, ".const:ti_sysbios_knl_Task_LD_exit__C");
__FAR__ const CT__ti_sysbios_knl_Task_LD_exit ti_sysbios_knl_Task_LD_exit__C = (((xdc_runtime_Log_Event)6614) << 16 | 512);

/* LM_setAffinity__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_LM_setAffinity__C, ".const:ti_sysbios_knl_Task_LM_setAffinity__C");
__FAR__ const CT__ti_sysbios_knl_Task_LM_setAffinity ti_sysbios_knl_Task_LM_setAffinity__C = (((xdc_runtime_Log_Event)6645) << 16 | 768);

/* LM_schedule__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_LM_schedule__C, ".const:ti_sysbios_knl_Task_LM_schedule__C");
__FAR__ const CT__ti_sysbios_knl_Task_LM_schedule ti_sysbios_knl_Task_LM_schedule__C = (((xdc_runtime_Log_Event)6728) << 16 | 1024);

/* LM_noWork__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_LM_noWork__C, ".const:ti_sysbios_knl_Task_LM_noWork__C");
__FAR__ const CT__ti_sysbios_knl_Task_LM_noWork ti_sysbios_knl_Task_LM_noWork__C = (((xdc_runtime_Log_Event)6814) << 16 | 1024);

/* E_stackOverflow__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_E_stackOverflow__C, ".const:ti_sysbios_knl_Task_E_stackOverflow__C");
__FAR__ const CT__ti_sysbios_knl_Task_E_stackOverflow ti_sysbios_knl_Task_E_stackOverflow__C = (((xdc_runtime_Error_Id)4966) << 16 | 0);

/* E_spOutOfBounds__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_E_spOutOfBounds__C, ".const:ti_sysbios_knl_Task_E_spOutOfBounds__C");
__FAR__ const CT__ti_sysbios_knl_Task_E_spOutOfBounds ti_sysbios_knl_Task_E_spOutOfBounds__C = (((xdc_runtime_Error_Id)5009) << 16 | 0);

/* E_deleteNotAllowed__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_E_deleteNotAllowed__C, ".const:ti_sysbios_knl_Task_E_deleteNotAllowed__C");
__FAR__ const CT__ti_sysbios_knl_Task_E_deleteNotAllowed ti_sysbios_knl_Task_E_deleteNotAllowed__C = (((xdc_runtime_Error_Id)5060) << 16 | 0);

/* E_moduleStateCheckFailed__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_E_moduleStateCheckFailed__C, ".const:ti_sysbios_knl_Task_E_moduleStateCheckFailed__C");
__FAR__ const CT__ti_sysbios_knl_Task_E_moduleStateCheckFailed ti_sysbios_knl_Task_E_moduleStateCheckFailed__C = (((xdc_runtime_Error_Id)5091) << 16 | 0);

/* E_objectCheckFailed__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_E_objectCheckFailed__C, ".const:ti_sysbios_knl_Task_E_objectCheckFailed__C");
__FAR__ const CT__ti_sysbios_knl_Task_E_objectCheckFailed ti_sysbios_knl_Task_E_objectCheckFailed__C = (((xdc_runtime_Error_Id)5164) << 16 | 0);

/* A_badThreadType__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_badThreadType__C, ".const:ti_sysbios_knl_Task_A_badThreadType__C");
__FAR__ const CT__ti_sysbios_knl_Task_A_badThreadType ti_sysbios_knl_Task_A_badThreadType__C = (((xdc_runtime_Assert_Id)1310) << 16 | 16);

/* A_badTaskState__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_badTaskState__C, ".const:ti_sysbios_knl_Task_A_badTaskState__C");
__FAR__ const CT__ti_sysbios_knl_Task_A_badTaskState ti_sysbios_knl_Task_A_badTaskState__C = (((xdc_runtime_Assert_Id)1379) << 16 | 16);

/* A_noPendElem__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_noPendElem__C, ".const:ti_sysbios_knl_Task_A_noPendElem__C");
__FAR__ const CT__ti_sysbios_knl_Task_A_noPendElem ti_sysbios_knl_Task_A_noPendElem__C = (((xdc_runtime_Assert_Id)1433) << 16 | 16);

/* A_taskDisabled__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_taskDisabled__C, ".const:ti_sysbios_knl_Task_A_taskDisabled__C");
__FAR__ const CT__ti_sysbios_knl_Task_A_taskDisabled ti_sysbios_knl_Task_A_taskDisabled__C = (((xdc_runtime_Assert_Id)1487) << 16 | 16);

/* A_badPriority__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_badPriority__C, ".const:ti_sysbios_knl_Task_A_badPriority__C");
__FAR__ const CT__ti_sysbios_knl_Task_A_badPriority ti_sysbios_knl_Task_A_badPriority__C = (((xdc_runtime_Assert_Id)1550) << 16 | 16);

/* A_badTimeout__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_badTimeout__C, ".const:ti_sysbios_knl_Task_A_badTimeout__C");
__FAR__ const CT__ti_sysbios_knl_Task_A_badTimeout ti_sysbios_knl_Task_A_badTimeout__C = (((xdc_runtime_Assert_Id)1600) << 16 | 16);

/* A_badAffinity__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_badAffinity__C, ".const:ti_sysbios_knl_Task_A_badAffinity__C");
__FAR__ const CT__ti_sysbios_knl_Task_A_badAffinity ti_sysbios_knl_Task_A_badAffinity__C = (((xdc_runtime_Assert_Id)1635) << 16 | 16);

/* A_sleepTaskDisabled__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_sleepTaskDisabled__C, ".const:ti_sysbios_knl_Task_A_sleepTaskDisabled__C");
__FAR__ const CT__ti_sysbios_knl_Task_A_sleepTaskDisabled ti_sysbios_knl_Task_A_sleepTaskDisabled__C = (((xdc_runtime_Assert_Id)1668) << 16 | 16);

/* A_invalidCoreId__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_invalidCoreId__C, ".const:ti_sysbios_knl_Task_A_invalidCoreId__C");
__FAR__ const CT__ti_sysbios_knl_Task_A_invalidCoreId ti_sysbios_knl_Task_A_invalidCoreId__C = (((xdc_runtime_Assert_Id)1752) << 16 | 16);

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
__FAR__ const CT__ti_sysbios_knl_Task_initStackFlag ti_sysbios_knl_Task_initStackFlag__C = 1;

/* checkStackFlag__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_checkStackFlag__C, ".const:ti_sysbios_knl_Task_checkStackFlag__C");
__FAR__ const CT__ti_sysbios_knl_Task_checkStackFlag ti_sysbios_knl_Task_checkStackFlag__C = 1;

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
 * ======== ti.sysbios.rts.ti.ThreadLocalStorage INITIALIZERS ========
 */

/* Module__state__V */
#if defined (__ICCARM__)
#pragma location = ".data_ti_sysbios_rts_ti_ThreadLocalStorage_Module__state__V"
#endif
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
#ifndef __TI_COMPILER_VERSION__
ti_sysbios_rts_ti_ThreadLocalStorage_Module_State__ ti_sysbios_rts_ti_ThreadLocalStorage_Module__state__V __attribute__ ((section(".data_ti_sysbios_rts_ti_ThreadLocalStorage_Module__state__V")));
#endif
#endif
ti_sysbios_rts_ti_ThreadLocalStorage_Module_State__ ti_sysbios_rts_ti_ThreadLocalStorage_Module__state__V = {
    ((xdc_Ptr)((void*)"&__TI_TLS_MAIN_THREAD_Base")),  /* currentTP */
    (xdc_UInt)(-0x0 - 1),  /* contextId */
    0,  /* heapHandle */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_rts_ti_ThreadLocalStorage_Module__diagsEnabled__C, ".const:ti_sysbios_rts_ti_ThreadLocalStorage_Module__diagsEnabled__C");
__FAR__ const CT__ti_sysbios_rts_ti_ThreadLocalStorage_Module__diagsEnabled ti_sysbios_rts_ti_ThreadLocalStorage_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_rts_ti_ThreadLocalStorage_Module__diagsIncluded__C, ".const:ti_sysbios_rts_ti_ThreadLocalStorage_Module__diagsIncluded__C");
__FAR__ const CT__ti_sysbios_rts_ti_ThreadLocalStorage_Module__diagsIncluded ti_sysbios_rts_ti_ThreadLocalStorage_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_rts_ti_ThreadLocalStorage_Module__diagsMask__C, ".const:ti_sysbios_rts_ti_ThreadLocalStorage_Module__diagsMask__C");
__FAR__ const CT__ti_sysbios_rts_ti_ThreadLocalStorage_Module__diagsMask ti_sysbios_rts_ti_ThreadLocalStorage_Module__diagsMask__C = ((CT__ti_sysbios_rts_ti_ThreadLocalStorage_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_rts_ti_ThreadLocalStorage_Module__gateObj__C, ".const:ti_sysbios_rts_ti_ThreadLocalStorage_Module__gateObj__C");
__FAR__ const CT__ti_sysbios_rts_ti_ThreadLocalStorage_Module__gateObj ti_sysbios_rts_ti_ThreadLocalStorage_Module__gateObj__C = ((CT__ti_sysbios_rts_ti_ThreadLocalStorage_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_rts_ti_ThreadLocalStorage_Module__gatePrms__C, ".const:ti_sysbios_rts_ti_ThreadLocalStorage_Module__gatePrms__C");
__FAR__ const CT__ti_sysbios_rts_ti_ThreadLocalStorage_Module__gatePrms ti_sysbios_rts_ti_ThreadLocalStorage_Module__gatePrms__C = ((CT__ti_sysbios_rts_ti_ThreadLocalStorage_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_rts_ti_ThreadLocalStorage_Module__id__C, ".const:ti_sysbios_rts_ti_ThreadLocalStorage_Module__id__C");
__FAR__ const CT__ti_sysbios_rts_ti_ThreadLocalStorage_Module__id ti_sysbios_rts_ti_ThreadLocalStorage_Module__id__C = (xdc_Bits16)0x8031;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_rts_ti_ThreadLocalStorage_Module__loggerDefined__C, ".const:ti_sysbios_rts_ti_ThreadLocalStorage_Module__loggerDefined__C");
__FAR__ const CT__ti_sysbios_rts_ti_ThreadLocalStorage_Module__loggerDefined ti_sysbios_rts_ti_ThreadLocalStorage_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_rts_ti_ThreadLocalStorage_Module__loggerObj__C, ".const:ti_sysbios_rts_ti_ThreadLocalStorage_Module__loggerObj__C");
__FAR__ const CT__ti_sysbios_rts_ti_ThreadLocalStorage_Module__loggerObj ti_sysbios_rts_ti_ThreadLocalStorage_Module__loggerObj__C = ((CT__ti_sysbios_rts_ti_ThreadLocalStorage_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_rts_ti_ThreadLocalStorage_Module__loggerFxn0__C, ".const:ti_sysbios_rts_ti_ThreadLocalStorage_Module__loggerFxn0__C");
__FAR__ const CT__ti_sysbios_rts_ti_ThreadLocalStorage_Module__loggerFxn0 ti_sysbios_rts_ti_ThreadLocalStorage_Module__loggerFxn0__C = ((CT__ti_sysbios_rts_ti_ThreadLocalStorage_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_rts_ti_ThreadLocalStorage_Module__loggerFxn1__C, ".const:ti_sysbios_rts_ti_ThreadLocalStorage_Module__loggerFxn1__C");
__FAR__ const CT__ti_sysbios_rts_ti_ThreadLocalStorage_Module__loggerFxn1 ti_sysbios_rts_ti_ThreadLocalStorage_Module__loggerFxn1__C = ((CT__ti_sysbios_rts_ti_ThreadLocalStorage_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_rts_ti_ThreadLocalStorage_Module__loggerFxn2__C, ".const:ti_sysbios_rts_ti_ThreadLocalStorage_Module__loggerFxn2__C");
__FAR__ const CT__ti_sysbios_rts_ti_ThreadLocalStorage_Module__loggerFxn2 ti_sysbios_rts_ti_ThreadLocalStorage_Module__loggerFxn2__C = ((CT__ti_sysbios_rts_ti_ThreadLocalStorage_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_rts_ti_ThreadLocalStorage_Module__loggerFxn4__C, ".const:ti_sysbios_rts_ti_ThreadLocalStorage_Module__loggerFxn4__C");
__FAR__ const CT__ti_sysbios_rts_ti_ThreadLocalStorage_Module__loggerFxn4 ti_sysbios_rts_ti_ThreadLocalStorage_Module__loggerFxn4__C = ((CT__ti_sysbios_rts_ti_ThreadLocalStorage_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_rts_ti_ThreadLocalStorage_Module__loggerFxn8__C, ".const:ti_sysbios_rts_ti_ThreadLocalStorage_Module__loggerFxn8__C");
__FAR__ const CT__ti_sysbios_rts_ti_ThreadLocalStorage_Module__loggerFxn8 ti_sysbios_rts_ti_ThreadLocalStorage_Module__loggerFxn8__C = ((CT__ti_sysbios_rts_ti_ThreadLocalStorage_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(ti_sysbios_rts_ti_ThreadLocalStorage_Module__startupDoneFxn__C, ".const:ti_sysbios_rts_ti_ThreadLocalStorage_Module__startupDoneFxn__C");
__FAR__ const CT__ti_sysbios_rts_ti_ThreadLocalStorage_Module__startupDoneFxn ti_sysbios_rts_ti_ThreadLocalStorage_Module__startupDoneFxn__C = ((CT__ti_sysbios_rts_ti_ThreadLocalStorage_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_rts_ti_ThreadLocalStorage_Object__count__C, ".const:ti_sysbios_rts_ti_ThreadLocalStorage_Object__count__C");
__FAR__ const CT__ti_sysbios_rts_ti_ThreadLocalStorage_Object__count ti_sysbios_rts_ti_ThreadLocalStorage_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_rts_ti_ThreadLocalStorage_Object__heap__C, ".const:ti_sysbios_rts_ti_ThreadLocalStorage_Object__heap__C");
__FAR__ const CT__ti_sysbios_rts_ti_ThreadLocalStorage_Object__heap ti_sysbios_rts_ti_ThreadLocalStorage_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_rts_ti_ThreadLocalStorage_Object__sizeof__C, ".const:ti_sysbios_rts_ti_ThreadLocalStorage_Object__sizeof__C");
__FAR__ const CT__ti_sysbios_rts_ti_ThreadLocalStorage_Object__sizeof ti_sysbios_rts_ti_ThreadLocalStorage_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_rts_ti_ThreadLocalStorage_Object__table__C, ".const:ti_sysbios_rts_ti_ThreadLocalStorage_Object__table__C");
__FAR__ const CT__ti_sysbios_rts_ti_ThreadLocalStorage_Object__table ti_sysbios_rts_ti_ThreadLocalStorage_Object__table__C = 0;

/* heapHandle__C */
#pragma DATA_SECTION(ti_sysbios_rts_ti_ThreadLocalStorage_heapHandle__C, ".const:ti_sysbios_rts_ti_ThreadLocalStorage_heapHandle__C");
__FAR__ const CT__ti_sysbios_rts_ti_ThreadLocalStorage_heapHandle ti_sysbios_rts_ti_ThreadLocalStorage_heapHandle__C = 0;

/* enableTLSSupport__C */
#pragma DATA_SECTION(ti_sysbios_rts_ti_ThreadLocalStorage_enableTLSSupport__C, ".const:ti_sysbios_rts_ti_ThreadLocalStorage_enableTLSSupport__C");
__FAR__ const CT__ti_sysbios_rts_ti_ThreadLocalStorage_enableTLSSupport ti_sysbios_rts_ti_ThreadLocalStorage_enableTLSSupport__C = 0;

/* TItlsSectMemory__C */
#pragma DATA_SECTION(ti_sysbios_rts_ti_ThreadLocalStorage_TItlsSectMemory__C, ".const:ti_sysbios_rts_ti_ThreadLocalStorage_TItlsSectMemory__C");
__FAR__ const CT__ti_sysbios_rts_ti_ThreadLocalStorage_TItlsSectMemory ti_sysbios_rts_ti_ThreadLocalStorage_TItlsSectMemory__C = 0;

/* TItls_initSectMemory__C */
#pragma DATA_SECTION(ti_sysbios_rts_ti_ThreadLocalStorage_TItls_initSectMemory__C, ".const:ti_sysbios_rts_ti_ThreadLocalStorage_TItls_initSectMemory__C");
__FAR__ const CT__ti_sysbios_rts_ti_ThreadLocalStorage_TItls_initSectMemory ti_sysbios_rts_ti_ThreadLocalStorage_TItls_initSectMemory__C = 0;


/*
 * ======== ti.sysbios.timers.dmtimer.Timer INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_timers_dmtimer_Timer_Object__DESC__C;

/* Object__PARAMS__C */
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Object__PARAMS__C, ".const:ti_sysbios_timers_dmtimer_Timer_Object__PARAMS__C");
__FAR__ const ti_sysbios_timers_dmtimer_Timer_Params ti_sysbios_timers_dmtimer_Timer_Object__PARAMS__C = {
    sizeof (ti_sysbios_timers_dmtimer_Timer_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_timers_dmtimer_Timer_Object__PARAMS__C.__iprms, /* instance */
    ti_sysbios_interfaces_ITimer_RunMode_CONTINUOUS,  /* runMode */
    ti_sysbios_interfaces_ITimer_StartMode_AUTO,  /* startMode */
    ((xdc_UArg)0),  /* arg */
    (xdc_UInt32)0x0,  /* period */
    ti_sysbios_interfaces_ITimer_PeriodType_MICROSECS,  /* periodType */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)0x0,  /* lo */
    },  /* extFreq */
    {
        (xdc_Bits8)0x0,  /* idlemode */
        (xdc_Bits8)0x0,  /* emufree */
        (xdc_Bits8)0x1,  /* softreset */
    },  /* tiocpCfg */
    {
        (xdc_Bits8)0x0,  /* mat_it_ena */
        (xdc_Bits8)0x1,  /* ovf_it_ena */
        (xdc_Bits8)0x0,  /* tcar_it_ena */
    },  /* tier */
    {
        (xdc_Bits8)0x0,  /* mat_wup_ena */
        (xdc_Bits8)0x0,  /* ovf_wup_ena */
        (xdc_Bits8)0x0,  /* tcar_wup_ena */
    },  /* twer */
    {
        (xdc_Bits32)0x0,  /* ptv */
        (xdc_Bits8)0x0,  /* pre */
        (xdc_Bits8)0x0,  /* ce */
        (xdc_Bits8)0x0,  /* scpwm */
        (xdc_Bits16)0x0,  /* tcm */
        (xdc_Bits16)0x0,  /* trg */
        (xdc_Bits8)0x0,  /* pt */
        (xdc_Bits8)0x0,  /* captmode */
        (xdc_Bits8)0x0,  /* gpocfg */
    },  /* tclr */
    {
        (xdc_Bits8)0x0,  /* sft */
        (xdc_Bits8)0x0,  /* posted */
        (xdc_Bits8)0x0,  /* readmode */
    },  /* tsicr */
    (xdc_UInt32)0x0,  /* tmar */
    (xdc_Int)(-0x0 - 1),  /* intNum */
    (xdc_Int)(-0x0 - 1),  /* eventId */
    ((ti_sysbios_hal_Hwi_Params*)0),  /* hwiParams */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_timers_dmtimer_Timer_Module__ ti_sysbios_timers_dmtimer_Timer_Module__root__V = {
    {&ti_sysbios_timers_dmtimer_Timer_Module__root__V.link,  /* link.next */
    &ti_sysbios_timers_dmtimer_Timer_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_timers_dmtimer_Timer_Object__ ti_sysbios_timers_dmtimer_Timer_Object__table__V[1] = {
    {/* instance#0 */
        0,
        1,  /* staticInst */
        (xdc_Int)0x5,  /* id */
        (xdc_UInt)0x3,  /* tiocpCfg */
        (xdc_UInt)0x0,  /* tmar */
        (xdc_UInt)0x2,  /* tier */
        (xdc_UInt)0x2,  /* twer */
        (xdc_UInt)0x0,  /* tclr */
        (xdc_UInt)0x0,  /* tsicr */
        ti_sysbios_interfaces_ITimer_RunMode_CONTINUOUS,  /* runMode */
        ti_sysbios_interfaces_ITimer_StartMode_AUTO,  /* startMode */
        (xdc_UInt)0x3e8,  /* period */
        ti_sysbios_interfaces_ITimer_PeriodType_MICROSECS,  /* periodType */
        (xdc_UInt)0xf,  /* intNum */
        (xdc_Int)0x44,  /* eventId */
        ((xdc_UArg)0),  /* arg */
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)mainDsp1TimerTick)),  /* tickFxn */
        {
            (xdc_Bits32)0x0,  /* hi */
            (xdc_Bits32)0x0,  /* lo */
        },  /* extFreq */
        (ti_sysbios_hal_Hwi_Handle)&ti_sysbios_hal_Hwi_Object__table__V[0],  /* hwi */
        (xdc_UInt)0x0,  /* prevThreshold */
        (xdc_UInt)0x0,  /* rollovers */
        (xdc_UInt)0x0,  /* savedCurrCount */
        1,  /* useDefaultEventId */
    },
};

/* --> ti_sysbios_timers_dmtimer_Timer_Module_State_0_intFreqs__A */
__T1_ti_sysbios_timers_dmtimer_Timer_Module_State__intFreqs ti_sysbios_timers_dmtimer_Timer_Module_State_0_intFreqs__A[16] = {
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)0x249f000,  /* lo */
    },  /* [0] */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)0x249f000,  /* lo */
    },  /* [1] */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)0x249f000,  /* lo */
    },  /* [2] */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)0x249f000,  /* lo */
    },  /* [3] */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)0x249f000,  /* lo */
    },  /* [4] */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)0x249f000,  /* lo */
    },  /* [5] */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)0x249f000,  /* lo */
    },  /* [6] */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)0x249f000,  /* lo */
    },  /* [7] */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)0x249f000,  /* lo */
    },  /* [8] */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)0x249f000,  /* lo */
    },  /* [9] */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)0x249f000,  /* lo */
    },  /* [10] */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)0x249f000,  /* lo */
    },  /* [11] */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)0x249f000,  /* lo */
    },  /* [12] */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)0x249f000,  /* lo */
    },  /* [13] */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)0x249f000,  /* lo */
    },  /* [14] */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)0x249f000,  /* lo */
    },  /* [15] */
};

/* --> ti_sysbios_timers_dmtimer_Timer_Module_State_0_device__A */
__T1_ti_sysbios_timers_dmtimer_Timer_Module_State__device ti_sysbios_timers_dmtimer_Timer_Module_State_0_device__A[16] = {
    {
        (xdc_Int)0xe,  /* intNum */
        (xdc_Int)0x3f,  /* eventId */
        ((xdc_Ptr)((void*)0x4ae18000)),  /* baseAddr */
    },  /* [0] */
    {
        (xdc_Int)0xf,  /* intNum */
        (xdc_Int)0x40,  /* eventId */
        ((xdc_Ptr)((void*)0x48032000)),  /* baseAddr */
    },  /* [1] */
    {
        (xdc_Int)0xe,  /* intNum */
        (xdc_Int)0x41,  /* eventId */
        ((xdc_Ptr)((void*)0x48034000)),  /* baseAddr */
    },  /* [2] */
    {
        (xdc_Int)0xf,  /* intNum */
        (xdc_Int)0x42,  /* eventId */
        ((xdc_Ptr)((void*)0x48036000)),  /* baseAddr */
    },  /* [3] */
    {
        (xdc_Int)0xe,  /* intNum */
        (xdc_Int)0x43,  /* eventId */
        ((xdc_Ptr)((void*)0x48820000)),  /* baseAddr */
    },  /* [4] */
    {
        (xdc_Int)0xf,  /* intNum */
        (xdc_Int)0x44,  /* eventId */
        ((xdc_Ptr)((void*)0x48822000)),  /* baseAddr */
    },  /* [5] */
    {
        (xdc_Int)0xe,  /* intNum */
        (xdc_Int)0x45,  /* eventId */
        ((xdc_Ptr)((void*)0x48824000)),  /* baseAddr */
    },  /* [6] */
    {
        (xdc_Int)0xf,  /* intNum */
        (xdc_Int)0x46,  /* eventId */
        ((xdc_Ptr)((void*)0x48826000)),  /* baseAddr */
    },  /* [7] */
    {
        (xdc_Int)0xe,  /* intNum */
        (xdc_Int)0x47,  /* eventId */
        ((xdc_Ptr)((void*)0x4803e000)),  /* baseAddr */
    },  /* [8] */
    {
        (xdc_Int)0xf,  /* intNum */
        (xdc_Int)0x48,  /* eventId */
        ((xdc_Ptr)((void*)0x48086000)),  /* baseAddr */
    },  /* [9] */
    {
        (xdc_Int)0xe,  /* intNum */
        (xdc_Int)0x49,  /* eventId */
        ((xdc_Ptr)((void*)0x48088000)),  /* baseAddr */
    },  /* [10] */
    {
        (xdc_Int)(-0x0 - 1),  /* intNum */
        (xdc_Int)0x4b,  /* eventId */
        ((xdc_Ptr)((void*)0x4ae20000)),  /* baseAddr */
    },  /* [11] */
    {
        (xdc_Int)(-0x0 - 1),  /* intNum */
        (xdc_Int)0x4c,  /* eventId */
        ((xdc_Ptr)((void*)0x48828000)),  /* baseAddr */
    },  /* [12] */
    {
        (xdc_Int)(-0x0 - 1),  /* intNum */
        (xdc_Int)0x4d,  /* eventId */
        ((xdc_Ptr)((void*)0x4882a000)),  /* baseAddr */
    },  /* [13] */
    {
        (xdc_Int)(-0x0 - 1),  /* intNum */
        (xdc_Int)0x4e,  /* eventId */
        ((xdc_Ptr)((void*)0x4882c000)),  /* baseAddr */
    },  /* [14] */
    {
        (xdc_Int)(-0x0 - 1),  /* intNum */
        (xdc_Int)0x51,  /* eventId */
        ((xdc_Ptr)((void*)0x4882e000)),  /* baseAddr */
    },  /* [15] */
};

/* --> ti_sysbios_timers_dmtimer_Timer_Module_State_0_handles__A */
__T1_ti_sysbios_timers_dmtimer_Timer_Module_State__handles ti_sysbios_timers_dmtimer_Timer_Module_State_0_handles__A[16] = {
    0,  /* [0] */
    0,  /* [1] */
    0,  /* [2] */
    0,  /* [3] */
    0,  /* [4] */
    (ti_sysbios_timers_dmtimer_Timer_Handle)&ti_sysbios_timers_dmtimer_Timer_Object__table__V[0],  /* [5] */
    0,  /* [6] */
    0,  /* [7] */
    0,  /* [8] */
    0,  /* [9] */
    0,  /* [10] */
    0,  /* [11] */
    0,  /* [12] */
    0,  /* [13] */
    0,  /* [14] */
    0,  /* [15] */
};

/* Module__state__V */
#if defined (__ICCARM__)
#pragma location = ".data_ti_sysbios_timers_dmtimer_Timer_Module__state__V"
#endif
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
#ifndef __TI_COMPILER_VERSION__
ti_sysbios_timers_dmtimer_Timer_Module_State__ ti_sysbios_timers_dmtimer_Timer_Module__state__V __attribute__ ((section(".data_ti_sysbios_timers_dmtimer_Timer_Module__state__V")));
#endif
#endif
ti_sysbios_timers_dmtimer_Timer_Module_State__ ti_sysbios_timers_dmtimer_Timer_Module__state__V = {
    (xdc_Bits32)0x0,  /* availMask */
    ((void*)ti_sysbios_timers_dmtimer_Timer_Module_State_0_intFreqs__A),  /* intFreqs */
    ((void*)ti_sysbios_timers_dmtimer_Timer_Module_State_0_device__A),  /* device */
    ((void*)ti_sysbios_timers_dmtimer_Timer_Module_State_0_handles__A),  /* handles */
    1,  /* firstInit */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Module__diagsEnabled__C, ".const:ti_sysbios_timers_dmtimer_Timer_Module__diagsEnabled__C");
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__diagsEnabled ti_sysbios_timers_dmtimer_Timer_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Module__diagsIncluded__C, ".const:ti_sysbios_timers_dmtimer_Timer_Module__diagsIncluded__C");
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__diagsIncluded ti_sysbios_timers_dmtimer_Timer_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Module__diagsMask__C, ".const:ti_sysbios_timers_dmtimer_Timer_Module__diagsMask__C");
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__diagsMask ti_sysbios_timers_dmtimer_Timer_Module__diagsMask__C = ((CT__ti_sysbios_timers_dmtimer_Timer_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Module__gateObj__C, ".const:ti_sysbios_timers_dmtimer_Timer_Module__gateObj__C");
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__gateObj ti_sysbios_timers_dmtimer_Timer_Module__gateObj__C = ((CT__ti_sysbios_timers_dmtimer_Timer_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Module__gatePrms__C, ".const:ti_sysbios_timers_dmtimer_Timer_Module__gatePrms__C");
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__gatePrms ti_sysbios_timers_dmtimer_Timer_Module__gatePrms__C = ((CT__ti_sysbios_timers_dmtimer_Timer_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Module__id__C, ".const:ti_sysbios_timers_dmtimer_Timer_Module__id__C");
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__id ti_sysbios_timers_dmtimer_Timer_Module__id__C = (xdc_Bits16)0x802e;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Module__loggerDefined__C, ".const:ti_sysbios_timers_dmtimer_Timer_Module__loggerDefined__C");
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerDefined ti_sysbios_timers_dmtimer_Timer_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Module__loggerObj__C, ".const:ti_sysbios_timers_dmtimer_Timer_Module__loggerObj__C");
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerObj ti_sysbios_timers_dmtimer_Timer_Module__loggerObj__C = ((CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn0__C, ".const:ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn0__C");
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn0 ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn0__C = ((CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn1__C, ".const:ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn1__C");
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn1 ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn1__C = ((CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn2__C, ".const:ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn2__C");
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn2 ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn2__C = ((CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn4__C, ".const:ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn4__C");
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn4 ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn4__C = ((CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn8__C, ".const:ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn8__C");
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn8 ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn8__C = ((CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Module__startupDoneFxn__C, ".const:ti_sysbios_timers_dmtimer_Timer_Module__startupDoneFxn__C");
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__startupDoneFxn ti_sysbios_timers_dmtimer_Timer_Module__startupDoneFxn__C = ((CT__ti_sysbios_timers_dmtimer_Timer_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Object__count__C, ".const:ti_sysbios_timers_dmtimer_Timer_Object__count__C");
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Object__count ti_sysbios_timers_dmtimer_Timer_Object__count__C = 1;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Object__heap__C, ".const:ti_sysbios_timers_dmtimer_Timer_Object__heap__C");
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Object__heap ti_sysbios_timers_dmtimer_Timer_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Object__sizeof__C, ".const:ti_sysbios_timers_dmtimer_Timer_Object__sizeof__C");
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Object__sizeof ti_sysbios_timers_dmtimer_Timer_Object__sizeof__C = sizeof(ti_sysbios_timers_dmtimer_Timer_Object__);

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Object__table__C, ".const:ti_sysbios_timers_dmtimer_Timer_Object__table__C");
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Object__table ti_sysbios_timers_dmtimer_Timer_Object__table__C = ti_sysbios_timers_dmtimer_Timer_Object__table__V;

/* A_notAvailable__C */
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_A_notAvailable__C, ".const:ti_sysbios_timers_dmtimer_Timer_A_notAvailable__C");
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_A_notAvailable ti_sysbios_timers_dmtimer_Timer_A_notAvailable__C = (((xdc_runtime_Assert_Id)2622) << 16 | 16);

/* E_invalidTimer__C */
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_E_invalidTimer__C, ".const:ti_sysbios_timers_dmtimer_Timer_E_invalidTimer__C");
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_E_invalidTimer ti_sysbios_timers_dmtimer_Timer_E_invalidTimer__C = (((xdc_runtime_Error_Id)5268) << 16 | 0);

/* E_notAvailable__C */
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_E_notAvailable__C, ".const:ti_sysbios_timers_dmtimer_Timer_E_notAvailable__C");
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_E_notAvailable ti_sysbios_timers_dmtimer_Timer_E_notAvailable__C = (((xdc_runtime_Error_Id)5304) << 16 | 0);

/* E_cannotSupport__C */
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_E_cannotSupport__C, ".const:ti_sysbios_timers_dmtimer_Timer_E_cannotSupport__C");
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_E_cannotSupport ti_sysbios_timers_dmtimer_Timer_E_cannotSupport__C = (((xdc_runtime_Error_Id)5343) << 16 | 0);

/* E_freqMismatch__C */
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_E_freqMismatch__C, ".const:ti_sysbios_timers_dmtimer_Timer_E_freqMismatch__C");
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_E_freqMismatch ti_sysbios_timers_dmtimer_Timer_E_freqMismatch__C = (((xdc_runtime_Error_Id)5401) << 16 | 0);

/* E_badIntNum__C */
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_E_badIntNum__C, ".const:ti_sysbios_timers_dmtimer_Timer_E_badIntNum__C");
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_E_badIntNum ti_sysbios_timers_dmtimer_Timer_E_badIntNum__C = (((xdc_runtime_Error_Id)5536) << 16 | 0);

/* anyMask__C */
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_anyMask__C, ".const:ti_sysbios_timers_dmtimer_Timer_anyMask__C");
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_anyMask ti_sysbios_timers_dmtimer_Timer_anyMask__C = (xdc_Bits32)0x20;

/* checkFrequency__C */
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_checkFrequency__C, ".const:ti_sysbios_timers_dmtimer_Timer_checkFrequency__C");
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_checkFrequency ti_sysbios_timers_dmtimer_Timer_checkFrequency__C = 1;

/* startupNeeded__C */
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_startupNeeded__C, ".const:ti_sysbios_timers_dmtimer_Timer_startupNeeded__C");
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_startupNeeded ti_sysbios_timers_dmtimer_Timer_startupNeeded__C = 1;

/* numTimerDevices__C */
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_numTimerDevices__C, ".const:ti_sysbios_timers_dmtimer_Timer_numTimerDevices__C");
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_numTimerDevices ti_sysbios_timers_dmtimer_Timer_numTimerDevices__C = (xdc_Int)0x10;


/*
 * ======== ti.sysbios.timers.dmtimer.Timer_TimerSupportProxy INITIALIZERS ========
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
__FAR__ const CT__xdc_runtime_Assert_E_assertFailed xdc_runtime_Assert_E_assertFailed__C = (((xdc_runtime_Error_Id)4166) << 16 | 0);


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
__FAR__ const CT__xdc_runtime_Error_E_generic xdc_runtime_Error_E_generic__C = (((xdc_runtime_Error_Id)4188) << 16 | 0);

/* E_memory__C */
#pragma DATA_SECTION(xdc_runtime_Error_E_memory__C, ".const:xdc_runtime_Error_E_memory__C");
__FAR__ const CT__xdc_runtime_Error_E_memory xdc_runtime_Error_E_memory__C = (((xdc_runtime_Error_Id)4192) << 16 | 0);

/* E_msgCode__C */
#pragma DATA_SECTION(xdc_runtime_Error_E_msgCode__C, ".const:xdc_runtime_Error_E_msgCode__C");
__FAR__ const CT__xdc_runtime_Error_E_msgCode xdc_runtime_Error_E_msgCode__C = (((xdc_runtime_Error_Id)4226) << 16 | 0);

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
__FAR__ const CT__xdc_runtime_Log_L_construct xdc_runtime_Log_L_construct__C = (((xdc_runtime_Log_Event)5810) << 16 | 4);

/* L_create__C */
#pragma DATA_SECTION(xdc_runtime_Log_L_create__C, ".const:xdc_runtime_Log_L_create__C");
__FAR__ const CT__xdc_runtime_Log_L_create xdc_runtime_Log_L_create__C = (((xdc_runtime_Log_Event)5834) << 16 | 4);

/* L_destruct__C */
#pragma DATA_SECTION(xdc_runtime_Log_L_destruct__C, ".const:xdc_runtime_Log_L_destruct__C");
__FAR__ const CT__xdc_runtime_Log_L_destruct xdc_runtime_Log_L_destruct__C = (((xdc_runtime_Log_Event)5855) << 16 | 4);

/* L_delete__C */
#pragma DATA_SECTION(xdc_runtime_Log_L_delete__C, ".const:xdc_runtime_Log_L_delete__C");
__FAR__ const CT__xdc_runtime_Log_L_delete xdc_runtime_Log_L_delete__C = (((xdc_runtime_Log_Event)5874) << 16 | 4);

/* L_error__C */
#pragma DATA_SECTION(xdc_runtime_Log_L_error__C, ".const:xdc_runtime_Log_L_error__C");
__FAR__ const CT__xdc_runtime_Log_L_error xdc_runtime_Log_L_error__C = (((xdc_runtime_Log_Event)5891) << 16 | 192);

/* L_warning__C */
#pragma DATA_SECTION(xdc_runtime_Log_L_warning__C, ".const:xdc_runtime_Log_L_warning__C");
__FAR__ const CT__xdc_runtime_Log_L_warning xdc_runtime_Log_L_warning__C = (((xdc_runtime_Log_Event)5905) << 16 | 224);

/* L_info__C */
#pragma DATA_SECTION(xdc_runtime_Log_L_info__C, ".const:xdc_runtime_Log_L_info__C");
__FAR__ const CT__xdc_runtime_Log_L_info xdc_runtime_Log_L_info__C = (((xdc_runtime_Log_Event)5921) << 16 | 16384);

/* L_start__C */
#pragma DATA_SECTION(xdc_runtime_Log_L_start__C, ".const:xdc_runtime_Log_L_start__C");
__FAR__ const CT__xdc_runtime_Log_L_start xdc_runtime_Log_L_start__C = (((xdc_runtime_Log_Event)5928) << 16 | 32768);

/* L_stop__C */
#pragma DATA_SECTION(xdc_runtime_Log_L_stop__C, ".const:xdc_runtime_Log_L_stop__C");
__FAR__ const CT__xdc_runtime_Log_L_stop xdc_runtime_Log_L_stop__C = (((xdc_runtime_Log_Event)5939) << 16 | 32768);

/* L_startInstance__C */
#pragma DATA_SECTION(xdc_runtime_Log_L_startInstance__C, ".const:xdc_runtime_Log_L_startInstance__C");
__FAR__ const CT__xdc_runtime_Log_L_startInstance xdc_runtime_Log_L_startInstance__C = (((xdc_runtime_Log_Event)5949) << 16 | 32768);

/* L_stopInstance__C */
#pragma DATA_SECTION(xdc_runtime_Log_L_stopInstance__C, ".const:xdc_runtime_Log_L_stopInstance__C");
__FAR__ const CT__xdc_runtime_Log_L_stopInstance xdc_runtime_Log_L_stopInstance__C = (((xdc_runtime_Log_Event)5968) << 16 | 32768);


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
    ((xdc_Void(*)(xdc_Void))((xdc_Fxn)ti_sysbios_hal_Hwi_initStack)),  /* [2] */
};

/* --> xdc_runtime_Startup_sfxnTab__A */
#pragma DATA_SECTION(xdc_runtime_Startup_sfxnTab__A, ".const:xdc_runtime_Startup_sfxnTab__A");
const __T1_xdc_runtime_Startup_sfxnTab xdc_runtime_Startup_sfxnTab__A[13] = {
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)xdc_runtime_System_Module_startup__E)),  /* [0] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)xdc_runtime_SysMin_Module_startup__E)),  /* [1] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_family_c64p_EventCombiner_Module_startup__E)),  /* [2] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_family_c64p_Exception_Module_startup__E)),  /* [3] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_family_c64p_Hwi_Module_startup__E)),  /* [4] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_family_c64p_TimestampProvider_Module_startup__E)),  /* [5] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_knl_Clock_Module_startup__E)),  /* [6] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_knl_Swi_Module_startup__E)),  /* [7] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_knl_Task_Module_startup__E)),  /* [8] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_hal_Hwi_Module_startup__E)),  /* [9] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_family_c66_Cache_Module_startup__E)),  /* [10] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_family_shared_vayu_TimerSupport_Module_startup__E)),  /* [11] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_timers_dmtimer_Timer_Module_startup__E)),  /* [12] */
};

/* --> xdc_runtime_Startup_sfxnRts__A */
#pragma DATA_SECTION(xdc_runtime_Startup_sfxnRts__A, ".const:xdc_runtime_Startup_sfxnRts__A");
const __T1_xdc_runtime_Startup_sfxnRts xdc_runtime_Startup_sfxnRts__A[13] = {
    1,  /* [0] */
    1,  /* [1] */
    0,  /* [2] */
    0,  /* [3] */
    0,  /* [4] */
    1,  /* [5] */
    0,  /* [6] */
    0,  /* [7] */
    0,  /* [8] */
    0,  /* [9] */
    0,  /* [10] */
    0,  /* [11] */
    0,  /* [12] */
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
__FAR__ const CT__xdc_runtime_Startup_lastFxns xdc_runtime_Startup_lastFxns__C = {0, 0};

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
const __T1_xdc_runtime_Text_charTab xdc_runtime_Text_charTab__A[7354] = {
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
    (xdc_Char)0x69,  /* [402] */
    (xdc_Char)0x6e,  /* [403] */
    (xdc_Char)0x76,  /* [404] */
    (xdc_Char)0x61,  /* [405] */
    (xdc_Char)0x6c,  /* [406] */
    (xdc_Char)0x69,  /* [407] */
    (xdc_Char)0x64,  /* [408] */
    (xdc_Char)0x45,  /* [409] */
    (xdc_Char)0x76,  /* [410] */
    (xdc_Char)0x65,  /* [411] */
    (xdc_Char)0x6e,  /* [412] */
    (xdc_Char)0x74,  /* [413] */
    (xdc_Char)0x49,  /* [414] */
    (xdc_Char)0x64,  /* [415] */
    (xdc_Char)0x3a,  /* [416] */
    (xdc_Char)0x20,  /* [417] */
    (xdc_Char)0x49,  /* [418] */
    (xdc_Char)0x6e,  /* [419] */
    (xdc_Char)0x76,  /* [420] */
    (xdc_Char)0x61,  /* [421] */
    (xdc_Char)0x6c,  /* [422] */
    (xdc_Char)0x69,  /* [423] */
    (xdc_Char)0x64,  /* [424] */
    (xdc_Char)0x20,  /* [425] */
    (xdc_Char)0x65,  /* [426] */
    (xdc_Char)0x76,  /* [427] */
    (xdc_Char)0x65,  /* [428] */
    (xdc_Char)0x6e,  /* [429] */
    (xdc_Char)0x74,  /* [430] */
    (xdc_Char)0x20,  /* [431] */
    (xdc_Char)0x49,  /* [432] */
    (xdc_Char)0x64,  /* [433] */
    (xdc_Char)0x20,  /* [434] */
    (xdc_Char)0x73,  /* [435] */
    (xdc_Char)0x70,  /* [436] */
    (xdc_Char)0x65,  /* [437] */
    (xdc_Char)0x63,  /* [438] */
    (xdc_Char)0x69,  /* [439] */
    (xdc_Char)0x66,  /* [440] */
    (xdc_Char)0x69,  /* [441] */
    (xdc_Char)0x65,  /* [442] */
    (xdc_Char)0x64,  /* [443] */
    (xdc_Char)0x0,  /* [444] */
    (xdc_Char)0x41,  /* [445] */
    (xdc_Char)0x5f,  /* [446] */
    (xdc_Char)0x63,  /* [447] */
    (xdc_Char)0x6c,  /* [448] */
    (xdc_Char)0x6f,  /* [449] */
    (xdc_Char)0x63,  /* [450] */
    (xdc_Char)0x6b,  /* [451] */
    (xdc_Char)0x44,  /* [452] */
    (xdc_Char)0x69,  /* [453] */
    (xdc_Char)0x73,  /* [454] */
    (xdc_Char)0x61,  /* [455] */
    (xdc_Char)0x62,  /* [456] */
    (xdc_Char)0x6c,  /* [457] */
    (xdc_Char)0x65,  /* [458] */
    (xdc_Char)0x64,  /* [459] */
    (xdc_Char)0x3a,  /* [460] */
    (xdc_Char)0x20,  /* [461] */
    (xdc_Char)0x43,  /* [462] */
    (xdc_Char)0x61,  /* [463] */
    (xdc_Char)0x6e,  /* [464] */
    (xdc_Char)0x6e,  /* [465] */
    (xdc_Char)0x6f,  /* [466] */
    (xdc_Char)0x74,  /* [467] */
    (xdc_Char)0x20,  /* [468] */
    (xdc_Char)0x63,  /* [469] */
    (xdc_Char)0x72,  /* [470] */
    (xdc_Char)0x65,  /* [471] */
    (xdc_Char)0x61,  /* [472] */
    (xdc_Char)0x74,  /* [473] */
    (xdc_Char)0x65,  /* [474] */
    (xdc_Char)0x20,  /* [475] */
    (xdc_Char)0x61,  /* [476] */
    (xdc_Char)0x20,  /* [477] */
    (xdc_Char)0x63,  /* [478] */
    (xdc_Char)0x6c,  /* [479] */
    (xdc_Char)0x6f,  /* [480] */
    (xdc_Char)0x63,  /* [481] */
    (xdc_Char)0x6b,  /* [482] */
    (xdc_Char)0x20,  /* [483] */
    (xdc_Char)0x69,  /* [484] */
    (xdc_Char)0x6e,  /* [485] */
    (xdc_Char)0x73,  /* [486] */
    (xdc_Char)0x74,  /* [487] */
    (xdc_Char)0x61,  /* [488] */
    (xdc_Char)0x6e,  /* [489] */
    (xdc_Char)0x63,  /* [490] */
    (xdc_Char)0x65,  /* [491] */
    (xdc_Char)0x20,  /* [492] */
    (xdc_Char)0x77,  /* [493] */
    (xdc_Char)0x68,  /* [494] */
    (xdc_Char)0x65,  /* [495] */
    (xdc_Char)0x6e,  /* [496] */
    (xdc_Char)0x20,  /* [497] */
    (xdc_Char)0x42,  /* [498] */
    (xdc_Char)0x49,  /* [499] */
    (xdc_Char)0x4f,  /* [500] */
    (xdc_Char)0x53,  /* [501] */
    (xdc_Char)0x2e,  /* [502] */
    (xdc_Char)0x63,  /* [503] */
    (xdc_Char)0x6c,  /* [504] */
    (xdc_Char)0x6f,  /* [505] */
    (xdc_Char)0x63,  /* [506] */
    (xdc_Char)0x6b,  /* [507] */
    (xdc_Char)0x45,  /* [508] */
    (xdc_Char)0x6e,  /* [509] */
    (xdc_Char)0x61,  /* [510] */
    (xdc_Char)0x62,  /* [511] */
    (xdc_Char)0x6c,  /* [512] */
    (xdc_Char)0x65,  /* [513] */
    (xdc_Char)0x64,  /* [514] */
    (xdc_Char)0x20,  /* [515] */
    (xdc_Char)0x69,  /* [516] */
    (xdc_Char)0x73,  /* [517] */
    (xdc_Char)0x20,  /* [518] */
    (xdc_Char)0x66,  /* [519] */
    (xdc_Char)0x61,  /* [520] */
    (xdc_Char)0x6c,  /* [521] */
    (xdc_Char)0x73,  /* [522] */
    (xdc_Char)0x65,  /* [523] */
    (xdc_Char)0x2e,  /* [524] */
    (xdc_Char)0x0,  /* [525] */
    (xdc_Char)0x41,  /* [526] */
    (xdc_Char)0x5f,  /* [527] */
    (xdc_Char)0x62,  /* [528] */
    (xdc_Char)0x61,  /* [529] */
    (xdc_Char)0x64,  /* [530] */
    (xdc_Char)0x54,  /* [531] */
    (xdc_Char)0x68,  /* [532] */
    (xdc_Char)0x72,  /* [533] */
    (xdc_Char)0x65,  /* [534] */
    (xdc_Char)0x61,  /* [535] */
    (xdc_Char)0x64,  /* [536] */
    (xdc_Char)0x54,  /* [537] */
    (xdc_Char)0x79,  /* [538] */
    (xdc_Char)0x70,  /* [539] */
    (xdc_Char)0x65,  /* [540] */
    (xdc_Char)0x3a,  /* [541] */
    (xdc_Char)0x20,  /* [542] */
    (xdc_Char)0x43,  /* [543] */
    (xdc_Char)0x61,  /* [544] */
    (xdc_Char)0x6e,  /* [545] */
    (xdc_Char)0x6e,  /* [546] */
    (xdc_Char)0x6f,  /* [547] */
    (xdc_Char)0x74,  /* [548] */
    (xdc_Char)0x20,  /* [549] */
    (xdc_Char)0x63,  /* [550] */
    (xdc_Char)0x72,  /* [551] */
    (xdc_Char)0x65,  /* [552] */
    (xdc_Char)0x61,  /* [553] */
    (xdc_Char)0x74,  /* [554] */
    (xdc_Char)0x65,  /* [555] */
    (xdc_Char)0x2f,  /* [556] */
    (xdc_Char)0x64,  /* [557] */
    (xdc_Char)0x65,  /* [558] */
    (xdc_Char)0x6c,  /* [559] */
    (xdc_Char)0x65,  /* [560] */
    (xdc_Char)0x74,  /* [561] */
    (xdc_Char)0x65,  /* [562] */
    (xdc_Char)0x20,  /* [563] */
    (xdc_Char)0x61,  /* [564] */
    (xdc_Char)0x20,  /* [565] */
    (xdc_Char)0x43,  /* [566] */
    (xdc_Char)0x6c,  /* [567] */
    (xdc_Char)0x6f,  /* [568] */
    (xdc_Char)0x63,  /* [569] */
    (xdc_Char)0x6b,  /* [570] */
    (xdc_Char)0x20,  /* [571] */
    (xdc_Char)0x66,  /* [572] */
    (xdc_Char)0x72,  /* [573] */
    (xdc_Char)0x6f,  /* [574] */
    (xdc_Char)0x6d,  /* [575] */
    (xdc_Char)0x20,  /* [576] */
    (xdc_Char)0x48,  /* [577] */
    (xdc_Char)0x77,  /* [578] */
    (xdc_Char)0x69,  /* [579] */
    (xdc_Char)0x20,  /* [580] */
    (xdc_Char)0x6f,  /* [581] */
    (xdc_Char)0x72,  /* [582] */
    (xdc_Char)0x20,  /* [583] */
    (xdc_Char)0x53,  /* [584] */
    (xdc_Char)0x77,  /* [585] */
    (xdc_Char)0x69,  /* [586] */
    (xdc_Char)0x20,  /* [587] */
    (xdc_Char)0x74,  /* [588] */
    (xdc_Char)0x68,  /* [589] */
    (xdc_Char)0x72,  /* [590] */
    (xdc_Char)0x65,  /* [591] */
    (xdc_Char)0x61,  /* [592] */
    (xdc_Char)0x64,  /* [593] */
    (xdc_Char)0x2e,  /* [594] */
    (xdc_Char)0x0,  /* [595] */
    (xdc_Char)0x41,  /* [596] */
    (xdc_Char)0x5f,  /* [597] */
    (xdc_Char)0x6e,  /* [598] */
    (xdc_Char)0x75,  /* [599] */
    (xdc_Char)0x6c,  /* [600] */
    (xdc_Char)0x6c,  /* [601] */
    (xdc_Char)0x45,  /* [602] */
    (xdc_Char)0x76,  /* [603] */
    (xdc_Char)0x65,  /* [604] */
    (xdc_Char)0x6e,  /* [605] */
    (xdc_Char)0x74,  /* [606] */
    (xdc_Char)0x4d,  /* [607] */
    (xdc_Char)0x61,  /* [608] */
    (xdc_Char)0x73,  /* [609] */
    (xdc_Char)0x6b,  /* [610] */
    (xdc_Char)0x73,  /* [611] */
    (xdc_Char)0x3a,  /* [612] */
    (xdc_Char)0x20,  /* [613] */
    (xdc_Char)0x6f,  /* [614] */
    (xdc_Char)0x72,  /* [615] */
    (xdc_Char)0x4d,  /* [616] */
    (xdc_Char)0x61,  /* [617] */
    (xdc_Char)0x73,  /* [618] */
    (xdc_Char)0x6b,  /* [619] */
    (xdc_Char)0x20,  /* [620] */
    (xdc_Char)0x61,  /* [621] */
    (xdc_Char)0x6e,  /* [622] */
    (xdc_Char)0x64,  /* [623] */
    (xdc_Char)0x20,  /* [624] */
    (xdc_Char)0x61,  /* [625] */
    (xdc_Char)0x6e,  /* [626] */
    (xdc_Char)0x64,  /* [627] */
    (xdc_Char)0x4d,  /* [628] */
    (xdc_Char)0x61,  /* [629] */
    (xdc_Char)0x73,  /* [630] */
    (xdc_Char)0x6b,  /* [631] */
    (xdc_Char)0x20,  /* [632] */
    (xdc_Char)0x61,  /* [633] */
    (xdc_Char)0x72,  /* [634] */
    (xdc_Char)0x65,  /* [635] */
    (xdc_Char)0x20,  /* [636] */
    (xdc_Char)0x6e,  /* [637] */
    (xdc_Char)0x75,  /* [638] */
    (xdc_Char)0x6c,  /* [639] */
    (xdc_Char)0x6c,  /* [640] */
    (xdc_Char)0x2e,  /* [641] */
    (xdc_Char)0x0,  /* [642] */
    (xdc_Char)0x41,  /* [643] */
    (xdc_Char)0x5f,  /* [644] */
    (xdc_Char)0x6e,  /* [645] */
    (xdc_Char)0x75,  /* [646] */
    (xdc_Char)0x6c,  /* [647] */
    (xdc_Char)0x6c,  /* [648] */
    (xdc_Char)0x45,  /* [649] */
    (xdc_Char)0x76,  /* [650] */
    (xdc_Char)0x65,  /* [651] */
    (xdc_Char)0x6e,  /* [652] */
    (xdc_Char)0x74,  /* [653] */
    (xdc_Char)0x49,  /* [654] */
    (xdc_Char)0x64,  /* [655] */
    (xdc_Char)0x3a,  /* [656] */
    (xdc_Char)0x20,  /* [657] */
    (xdc_Char)0x70,  /* [658] */
    (xdc_Char)0x6f,  /* [659] */
    (xdc_Char)0x73,  /* [660] */
    (xdc_Char)0x74,  /* [661] */
    (xdc_Char)0x65,  /* [662] */
    (xdc_Char)0x64,  /* [663] */
    (xdc_Char)0x20,  /* [664] */
    (xdc_Char)0x65,  /* [665] */
    (xdc_Char)0x76,  /* [666] */
    (xdc_Char)0x65,  /* [667] */
    (xdc_Char)0x6e,  /* [668] */
    (xdc_Char)0x74,  /* [669] */
    (xdc_Char)0x49,  /* [670] */
    (xdc_Char)0x64,  /* [671] */
    (xdc_Char)0x20,  /* [672] */
    (xdc_Char)0x69,  /* [673] */
    (xdc_Char)0x73,  /* [674] */
    (xdc_Char)0x20,  /* [675] */
    (xdc_Char)0x6e,  /* [676] */
    (xdc_Char)0x75,  /* [677] */
    (xdc_Char)0x6c,  /* [678] */
    (xdc_Char)0x6c,  /* [679] */
    (xdc_Char)0x2e,  /* [680] */
    (xdc_Char)0x0,  /* [681] */
    (xdc_Char)0x41,  /* [682] */
    (xdc_Char)0x5f,  /* [683] */
    (xdc_Char)0x65,  /* [684] */
    (xdc_Char)0x76,  /* [685] */
    (xdc_Char)0x65,  /* [686] */
    (xdc_Char)0x6e,  /* [687] */
    (xdc_Char)0x74,  /* [688] */
    (xdc_Char)0x49,  /* [689] */
    (xdc_Char)0x6e,  /* [690] */
    (xdc_Char)0x55,  /* [691] */
    (xdc_Char)0x73,  /* [692] */
    (xdc_Char)0x65,  /* [693] */
    (xdc_Char)0x3a,  /* [694] */
    (xdc_Char)0x20,  /* [695] */
    (xdc_Char)0x45,  /* [696] */
    (xdc_Char)0x76,  /* [697] */
    (xdc_Char)0x65,  /* [698] */
    (xdc_Char)0x6e,  /* [699] */
    (xdc_Char)0x74,  /* [700] */
    (xdc_Char)0x20,  /* [701] */
    (xdc_Char)0x6f,  /* [702] */
    (xdc_Char)0x62,  /* [703] */
    (xdc_Char)0x6a,  /* [704] */
    (xdc_Char)0x65,  /* [705] */
    (xdc_Char)0x63,  /* [706] */
    (xdc_Char)0x74,  /* [707] */
    (xdc_Char)0x20,  /* [708] */
    (xdc_Char)0x61,  /* [709] */
    (xdc_Char)0x6c,  /* [710] */
    (xdc_Char)0x72,  /* [711] */
    (xdc_Char)0x65,  /* [712] */
    (xdc_Char)0x61,  /* [713] */
    (xdc_Char)0x64,  /* [714] */
    (xdc_Char)0x79,  /* [715] */
    (xdc_Char)0x20,  /* [716] */
    (xdc_Char)0x69,  /* [717] */
    (xdc_Char)0x6e,  /* [718] */
    (xdc_Char)0x20,  /* [719] */
    (xdc_Char)0x75,  /* [720] */
    (xdc_Char)0x73,  /* [721] */
    (xdc_Char)0x65,  /* [722] */
    (xdc_Char)0x2e,  /* [723] */
    (xdc_Char)0x0,  /* [724] */
    (xdc_Char)0x41,  /* [725] */
    (xdc_Char)0x5f,  /* [726] */
    (xdc_Char)0x62,  /* [727] */
    (xdc_Char)0x61,  /* [728] */
    (xdc_Char)0x64,  /* [729] */
    (xdc_Char)0x43,  /* [730] */
    (xdc_Char)0x6f,  /* [731] */
    (xdc_Char)0x6e,  /* [732] */
    (xdc_Char)0x74,  /* [733] */
    (xdc_Char)0x65,  /* [734] */
    (xdc_Char)0x78,  /* [735] */
    (xdc_Char)0x74,  /* [736] */
    (xdc_Char)0x3a,  /* [737] */
    (xdc_Char)0x20,  /* [738] */
    (xdc_Char)0x62,  /* [739] */
    (xdc_Char)0x61,  /* [740] */
    (xdc_Char)0x64,  /* [741] */
    (xdc_Char)0x20,  /* [742] */
    (xdc_Char)0x63,  /* [743] */
    (xdc_Char)0x61,  /* [744] */
    (xdc_Char)0x6c,  /* [745] */
    (xdc_Char)0x6c,  /* [746] */
    (xdc_Char)0x69,  /* [747] */
    (xdc_Char)0x6e,  /* [748] */
    (xdc_Char)0x67,  /* [749] */
    (xdc_Char)0x20,  /* [750] */
    (xdc_Char)0x63,  /* [751] */
    (xdc_Char)0x6f,  /* [752] */
    (xdc_Char)0x6e,  /* [753] */
    (xdc_Char)0x74,  /* [754] */
    (xdc_Char)0x65,  /* [755] */
    (xdc_Char)0x78,  /* [756] */
    (xdc_Char)0x74,  /* [757] */
    (xdc_Char)0x2e,  /* [758] */
    (xdc_Char)0x20,  /* [759] */
    (xdc_Char)0x4d,  /* [760] */
    (xdc_Char)0x75,  /* [761] */
    (xdc_Char)0x73,  /* [762] */
    (xdc_Char)0x74,  /* [763] */
    (xdc_Char)0x20,  /* [764] */
    (xdc_Char)0x62,  /* [765] */
    (xdc_Char)0x65,  /* [766] */
    (xdc_Char)0x20,  /* [767] */
    (xdc_Char)0x63,  /* [768] */
    (xdc_Char)0x61,  /* [769] */
    (xdc_Char)0x6c,  /* [770] */
    (xdc_Char)0x6c,  /* [771] */
    (xdc_Char)0x65,  /* [772] */
    (xdc_Char)0x64,  /* [773] */
    (xdc_Char)0x20,  /* [774] */
    (xdc_Char)0x66,  /* [775] */
    (xdc_Char)0x72,  /* [776] */
    (xdc_Char)0x6f,  /* [777] */
    (xdc_Char)0x6d,  /* [778] */
    (xdc_Char)0x20,  /* [779] */
    (xdc_Char)0x61,  /* [780] */
    (xdc_Char)0x20,  /* [781] */
    (xdc_Char)0x54,  /* [782] */
    (xdc_Char)0x61,  /* [783] */
    (xdc_Char)0x73,  /* [784] */
    (xdc_Char)0x6b,  /* [785] */
    (xdc_Char)0x2e,  /* [786] */
    (xdc_Char)0x0,  /* [787] */
    (xdc_Char)0x41,  /* [788] */
    (xdc_Char)0x5f,  /* [789] */
    (xdc_Char)0x70,  /* [790] */
    (xdc_Char)0x65,  /* [791] */
    (xdc_Char)0x6e,  /* [792] */
    (xdc_Char)0x64,  /* [793] */
    (xdc_Char)0x54,  /* [794] */
    (xdc_Char)0x61,  /* [795] */
    (xdc_Char)0x73,  /* [796] */
    (xdc_Char)0x6b,  /* [797] */
    (xdc_Char)0x44,  /* [798] */
    (xdc_Char)0x69,  /* [799] */
    (xdc_Char)0x73,  /* [800] */
    (xdc_Char)0x61,  /* [801] */
    (xdc_Char)0x62,  /* [802] */
    (xdc_Char)0x6c,  /* [803] */
    (xdc_Char)0x65,  /* [804] */
    (xdc_Char)0x64,  /* [805] */
    (xdc_Char)0x3a,  /* [806] */
    (xdc_Char)0x20,  /* [807] */
    (xdc_Char)0x43,  /* [808] */
    (xdc_Char)0x61,  /* [809] */
    (xdc_Char)0x6e,  /* [810] */
    (xdc_Char)0x6e,  /* [811] */
    (xdc_Char)0x6f,  /* [812] */
    (xdc_Char)0x74,  /* [813] */
    (xdc_Char)0x20,  /* [814] */
    (xdc_Char)0x63,  /* [815] */
    (xdc_Char)0x61,  /* [816] */
    (xdc_Char)0x6c,  /* [817] */
    (xdc_Char)0x6c,  /* [818] */
    (xdc_Char)0x20,  /* [819] */
    (xdc_Char)0x45,  /* [820] */
    (xdc_Char)0x76,  /* [821] */
    (xdc_Char)0x65,  /* [822] */
    (xdc_Char)0x6e,  /* [823] */
    (xdc_Char)0x74,  /* [824] */
    (xdc_Char)0x5f,  /* [825] */
    (xdc_Char)0x70,  /* [826] */
    (xdc_Char)0x65,  /* [827] */
    (xdc_Char)0x6e,  /* [828] */
    (xdc_Char)0x64,  /* [829] */
    (xdc_Char)0x28,  /* [830] */
    (xdc_Char)0x29,  /* [831] */
    (xdc_Char)0x20,  /* [832] */
    (xdc_Char)0x77,  /* [833] */
    (xdc_Char)0x68,  /* [834] */
    (xdc_Char)0x69,  /* [835] */
    (xdc_Char)0x6c,  /* [836] */
    (xdc_Char)0x65,  /* [837] */
    (xdc_Char)0x20,  /* [838] */
    (xdc_Char)0x74,  /* [839] */
    (xdc_Char)0x68,  /* [840] */
    (xdc_Char)0x65,  /* [841] */
    (xdc_Char)0x20,  /* [842] */
    (xdc_Char)0x54,  /* [843] */
    (xdc_Char)0x61,  /* [844] */
    (xdc_Char)0x73,  /* [845] */
    (xdc_Char)0x6b,  /* [846] */
    (xdc_Char)0x20,  /* [847] */
    (xdc_Char)0x6f,  /* [848] */
    (xdc_Char)0x72,  /* [849] */
    (xdc_Char)0x20,  /* [850] */
    (xdc_Char)0x53,  /* [851] */
    (xdc_Char)0x77,  /* [852] */
    (xdc_Char)0x69,  /* [853] */
    (xdc_Char)0x20,  /* [854] */
    (xdc_Char)0x73,  /* [855] */
    (xdc_Char)0x63,  /* [856] */
    (xdc_Char)0x68,  /* [857] */
    (xdc_Char)0x65,  /* [858] */
    (xdc_Char)0x64,  /* [859] */
    (xdc_Char)0x75,  /* [860] */
    (xdc_Char)0x6c,  /* [861] */
    (xdc_Char)0x65,  /* [862] */
    (xdc_Char)0x72,  /* [863] */
    (xdc_Char)0x20,  /* [864] */
    (xdc_Char)0x69,  /* [865] */
    (xdc_Char)0x73,  /* [866] */
    (xdc_Char)0x20,  /* [867] */
    (xdc_Char)0x64,  /* [868] */
    (xdc_Char)0x69,  /* [869] */
    (xdc_Char)0x73,  /* [870] */
    (xdc_Char)0x61,  /* [871] */
    (xdc_Char)0x62,  /* [872] */
    (xdc_Char)0x6c,  /* [873] */
    (xdc_Char)0x65,  /* [874] */
    (xdc_Char)0x64,  /* [875] */
    (xdc_Char)0x2e,  /* [876] */
    (xdc_Char)0x0,  /* [877] */
    (xdc_Char)0x4d,  /* [878] */
    (xdc_Char)0x61,  /* [879] */
    (xdc_Char)0x69,  /* [880] */
    (xdc_Char)0x6c,  /* [881] */
    (xdc_Char)0x62,  /* [882] */
    (xdc_Char)0x6f,  /* [883] */
    (xdc_Char)0x78,  /* [884] */
    (xdc_Char)0x5f,  /* [885] */
    (xdc_Char)0x63,  /* [886] */
    (xdc_Char)0x72,  /* [887] */
    (xdc_Char)0x65,  /* [888] */
    (xdc_Char)0x61,  /* [889] */
    (xdc_Char)0x74,  /* [890] */
    (xdc_Char)0x65,  /* [891] */
    (xdc_Char)0x27,  /* [892] */
    (xdc_Char)0x73,  /* [893] */
    (xdc_Char)0x20,  /* [894] */
    (xdc_Char)0x62,  /* [895] */
    (xdc_Char)0x75,  /* [896] */
    (xdc_Char)0x66,  /* [897] */
    (xdc_Char)0x53,  /* [898] */
    (xdc_Char)0x69,  /* [899] */
    (xdc_Char)0x7a,  /* [900] */
    (xdc_Char)0x65,  /* [901] */
    (xdc_Char)0x20,  /* [902] */
    (xdc_Char)0x70,  /* [903] */
    (xdc_Char)0x61,  /* [904] */
    (xdc_Char)0x72,  /* [905] */
    (xdc_Char)0x61,  /* [906] */
    (xdc_Char)0x6d,  /* [907] */
    (xdc_Char)0x65,  /* [908] */
    (xdc_Char)0x74,  /* [909] */
    (xdc_Char)0x65,  /* [910] */
    (xdc_Char)0x72,  /* [911] */
    (xdc_Char)0x20,  /* [912] */
    (xdc_Char)0x69,  /* [913] */
    (xdc_Char)0x73,  /* [914] */
    (xdc_Char)0x20,  /* [915] */
    (xdc_Char)0x69,  /* [916] */
    (xdc_Char)0x6e,  /* [917] */
    (xdc_Char)0x76,  /* [918] */
    (xdc_Char)0x61,  /* [919] */
    (xdc_Char)0x6c,  /* [920] */
    (xdc_Char)0x69,  /* [921] */
    (xdc_Char)0x64,  /* [922] */
    (xdc_Char)0x20,  /* [923] */
    (xdc_Char)0x28,  /* [924] */
    (xdc_Char)0x74,  /* [925] */
    (xdc_Char)0x6f,  /* [926] */
    (xdc_Char)0x6f,  /* [927] */
    (xdc_Char)0x20,  /* [928] */
    (xdc_Char)0x73,  /* [929] */
    (xdc_Char)0x6d,  /* [930] */
    (xdc_Char)0x61,  /* [931] */
    (xdc_Char)0x6c,  /* [932] */
    (xdc_Char)0x6c,  /* [933] */
    (xdc_Char)0x29,  /* [934] */
    (xdc_Char)0x0,  /* [935] */
    (xdc_Char)0x41,  /* [936] */
    (xdc_Char)0x5f,  /* [937] */
    (xdc_Char)0x6e,  /* [938] */
    (xdc_Char)0x6f,  /* [939] */
    (xdc_Char)0x45,  /* [940] */
    (xdc_Char)0x76,  /* [941] */
    (xdc_Char)0x65,  /* [942] */
    (xdc_Char)0x6e,  /* [943] */
    (xdc_Char)0x74,  /* [944] */
    (xdc_Char)0x73,  /* [945] */
    (xdc_Char)0x3a,  /* [946] */
    (xdc_Char)0x20,  /* [947] */
    (xdc_Char)0x54,  /* [948] */
    (xdc_Char)0x68,  /* [949] */
    (xdc_Char)0x65,  /* [950] */
    (xdc_Char)0x20,  /* [951] */
    (xdc_Char)0x45,  /* [952] */
    (xdc_Char)0x76,  /* [953] */
    (xdc_Char)0x65,  /* [954] */
    (xdc_Char)0x6e,  /* [955] */
    (xdc_Char)0x74,  /* [956] */
    (xdc_Char)0x2e,  /* [957] */
    (xdc_Char)0x73,  /* [958] */
    (xdc_Char)0x75,  /* [959] */
    (xdc_Char)0x70,  /* [960] */
    (xdc_Char)0x70,  /* [961] */
    (xdc_Char)0x6f,  /* [962] */
    (xdc_Char)0x72,  /* [963] */
    (xdc_Char)0x74,  /* [964] */
    (xdc_Char)0x73,  /* [965] */
    (xdc_Char)0x45,  /* [966] */
    (xdc_Char)0x76,  /* [967] */
    (xdc_Char)0x65,  /* [968] */
    (xdc_Char)0x6e,  /* [969] */
    (xdc_Char)0x74,  /* [970] */
    (xdc_Char)0x73,  /* [971] */
    (xdc_Char)0x20,  /* [972] */
    (xdc_Char)0x66,  /* [973] */
    (xdc_Char)0x6c,  /* [974] */
    (xdc_Char)0x61,  /* [975] */
    (xdc_Char)0x67,  /* [976] */
    (xdc_Char)0x20,  /* [977] */
    (xdc_Char)0x69,  /* [978] */
    (xdc_Char)0x73,  /* [979] */
    (xdc_Char)0x20,  /* [980] */
    (xdc_Char)0x64,  /* [981] */
    (xdc_Char)0x69,  /* [982] */
    (xdc_Char)0x73,  /* [983] */
    (xdc_Char)0x61,  /* [984] */
    (xdc_Char)0x62,  /* [985] */
    (xdc_Char)0x6c,  /* [986] */
    (xdc_Char)0x65,  /* [987] */
    (xdc_Char)0x64,  /* [988] */
    (xdc_Char)0x2e,  /* [989] */
    (xdc_Char)0x0,  /* [990] */
    (xdc_Char)0x41,  /* [991] */
    (xdc_Char)0x5f,  /* [992] */
    (xdc_Char)0x69,  /* [993] */
    (xdc_Char)0x6e,  /* [994] */
    (xdc_Char)0x76,  /* [995] */
    (xdc_Char)0x54,  /* [996] */
    (xdc_Char)0x69,  /* [997] */
    (xdc_Char)0x6d,  /* [998] */
    (xdc_Char)0x65,  /* [999] */
    (xdc_Char)0x6f,  /* [1000] */
    (xdc_Char)0x75,  /* [1001] */
    (xdc_Char)0x74,  /* [1002] */
    (xdc_Char)0x3a,  /* [1003] */
    (xdc_Char)0x20,  /* [1004] */
    (xdc_Char)0x43,  /* [1005] */
    (xdc_Char)0x61,  /* [1006] */
    (xdc_Char)0x6e,  /* [1007] */
    (xdc_Char)0x27,  /* [1008] */
    (xdc_Char)0x74,  /* [1009] */
    (xdc_Char)0x20,  /* [1010] */
    (xdc_Char)0x75,  /* [1011] */
    (xdc_Char)0x73,  /* [1012] */
    (xdc_Char)0x65,  /* [1013] */
    (xdc_Char)0x20,  /* [1014] */
    (xdc_Char)0x42,  /* [1015] */
    (xdc_Char)0x49,  /* [1016] */
    (xdc_Char)0x4f,  /* [1017] */
    (xdc_Char)0x53,  /* [1018] */
    (xdc_Char)0x5f,  /* [1019] */
    (xdc_Char)0x45,  /* [1020] */
    (xdc_Char)0x56,  /* [1021] */
    (xdc_Char)0x45,  /* [1022] */
    (xdc_Char)0x4e,  /* [1023] */
    (xdc_Char)0x54,  /* [1024] */
    (xdc_Char)0x5f,  /* [1025] */
    (xdc_Char)0x41,  /* [1026] */
    (xdc_Char)0x43,  /* [1027] */
    (xdc_Char)0x51,  /* [1028] */
    (xdc_Char)0x55,  /* [1029] */
    (xdc_Char)0x49,  /* [1030] */
    (xdc_Char)0x52,  /* [1031] */
    (xdc_Char)0x45,  /* [1032] */
    (xdc_Char)0x44,  /* [1033] */
    (xdc_Char)0x20,  /* [1034] */
    (xdc_Char)0x77,  /* [1035] */
    (xdc_Char)0x69,  /* [1036] */
    (xdc_Char)0x74,  /* [1037] */
    (xdc_Char)0x68,  /* [1038] */
    (xdc_Char)0x20,  /* [1039] */
    (xdc_Char)0x74,  /* [1040] */
    (xdc_Char)0x68,  /* [1041] */
    (xdc_Char)0x69,  /* [1042] */
    (xdc_Char)0x73,  /* [1043] */
    (xdc_Char)0x20,  /* [1044] */
    (xdc_Char)0x53,  /* [1045] */
    (xdc_Char)0x65,  /* [1046] */
    (xdc_Char)0x6d,  /* [1047] */
    (xdc_Char)0x61,  /* [1048] */
    (xdc_Char)0x70,  /* [1049] */
    (xdc_Char)0x68,  /* [1050] */
    (xdc_Char)0x6f,  /* [1051] */
    (xdc_Char)0x72,  /* [1052] */
    (xdc_Char)0x65,  /* [1053] */
    (xdc_Char)0x2e,  /* [1054] */
    (xdc_Char)0x0,  /* [1055] */
    (xdc_Char)0x41,  /* [1056] */
    (xdc_Char)0x5f,  /* [1057] */
    (xdc_Char)0x6f,  /* [1058] */
    (xdc_Char)0x76,  /* [1059] */
    (xdc_Char)0x65,  /* [1060] */
    (xdc_Char)0x72,  /* [1061] */
    (xdc_Char)0x66,  /* [1062] */
    (xdc_Char)0x6c,  /* [1063] */
    (xdc_Char)0x6f,  /* [1064] */
    (xdc_Char)0x77,  /* [1065] */
    (xdc_Char)0x3a,  /* [1066] */
    (xdc_Char)0x20,  /* [1067] */
    (xdc_Char)0x43,  /* [1068] */
    (xdc_Char)0x6f,  /* [1069] */
    (xdc_Char)0x75,  /* [1070] */
    (xdc_Char)0x6e,  /* [1071] */
    (xdc_Char)0x74,  /* [1072] */
    (xdc_Char)0x20,  /* [1073] */
    (xdc_Char)0x68,  /* [1074] */
    (xdc_Char)0x61,  /* [1075] */
    (xdc_Char)0x73,  /* [1076] */
    (xdc_Char)0x20,  /* [1077] */
    (xdc_Char)0x65,  /* [1078] */
    (xdc_Char)0x78,  /* [1079] */
    (xdc_Char)0x63,  /* [1080] */
    (xdc_Char)0x65,  /* [1081] */
    (xdc_Char)0x65,  /* [1082] */
    (xdc_Char)0x64,  /* [1083] */
    (xdc_Char)0x65,  /* [1084] */
    (xdc_Char)0x64,  /* [1085] */
    (xdc_Char)0x20,  /* [1086] */
    (xdc_Char)0x36,  /* [1087] */
    (xdc_Char)0x35,  /* [1088] */
    (xdc_Char)0x35,  /* [1089] */
    (xdc_Char)0x33,  /* [1090] */
    (xdc_Char)0x35,  /* [1091] */
    (xdc_Char)0x20,  /* [1092] */
    (xdc_Char)0x61,  /* [1093] */
    (xdc_Char)0x6e,  /* [1094] */
    (xdc_Char)0x64,  /* [1095] */
    (xdc_Char)0x20,  /* [1096] */
    (xdc_Char)0x72,  /* [1097] */
    (xdc_Char)0x6f,  /* [1098] */
    (xdc_Char)0x6c,  /* [1099] */
    (xdc_Char)0x6c,  /* [1100] */
    (xdc_Char)0x65,  /* [1101] */
    (xdc_Char)0x64,  /* [1102] */
    (xdc_Char)0x20,  /* [1103] */
    (xdc_Char)0x6f,  /* [1104] */
    (xdc_Char)0x76,  /* [1105] */
    (xdc_Char)0x65,  /* [1106] */
    (xdc_Char)0x72,  /* [1107] */
    (xdc_Char)0x2e,  /* [1108] */
    (xdc_Char)0x0,  /* [1109] */
    (xdc_Char)0x41,  /* [1110] */
    (xdc_Char)0x5f,  /* [1111] */
    (xdc_Char)0x70,  /* [1112] */
    (xdc_Char)0x65,  /* [1113] */
    (xdc_Char)0x6e,  /* [1114] */
    (xdc_Char)0x64,  /* [1115] */
    (xdc_Char)0x54,  /* [1116] */
    (xdc_Char)0x61,  /* [1117] */
    (xdc_Char)0x73,  /* [1118] */
    (xdc_Char)0x6b,  /* [1119] */
    (xdc_Char)0x44,  /* [1120] */
    (xdc_Char)0x69,  /* [1121] */
    (xdc_Char)0x73,  /* [1122] */
    (xdc_Char)0x61,  /* [1123] */
    (xdc_Char)0x62,  /* [1124] */
    (xdc_Char)0x6c,  /* [1125] */
    (xdc_Char)0x65,  /* [1126] */
    (xdc_Char)0x64,  /* [1127] */
    (xdc_Char)0x3a,  /* [1128] */
    (xdc_Char)0x20,  /* [1129] */
    (xdc_Char)0x43,  /* [1130] */
    (xdc_Char)0x61,  /* [1131] */
    (xdc_Char)0x6e,  /* [1132] */
    (xdc_Char)0x6e,  /* [1133] */
    (xdc_Char)0x6f,  /* [1134] */
    (xdc_Char)0x74,  /* [1135] */
    (xdc_Char)0x20,  /* [1136] */
    (xdc_Char)0x63,  /* [1137] */
    (xdc_Char)0x61,  /* [1138] */
    (xdc_Char)0x6c,  /* [1139] */
    (xdc_Char)0x6c,  /* [1140] */
    (xdc_Char)0x20,  /* [1141] */
    (xdc_Char)0x53,  /* [1142] */
    (xdc_Char)0x65,  /* [1143] */
    (xdc_Char)0x6d,  /* [1144] */
    (xdc_Char)0x61,  /* [1145] */
    (xdc_Char)0x70,  /* [1146] */
    (xdc_Char)0x68,  /* [1147] */
    (xdc_Char)0x6f,  /* [1148] */
    (xdc_Char)0x72,  /* [1149] */
    (xdc_Char)0x65,  /* [1150] */
    (xdc_Char)0x5f,  /* [1151] */
    (xdc_Char)0x70,  /* [1152] */
    (xdc_Char)0x65,  /* [1153] */
    (xdc_Char)0x6e,  /* [1154] */
    (xdc_Char)0x64,  /* [1155] */
    (xdc_Char)0x28,  /* [1156] */
    (xdc_Char)0x29,  /* [1157] */
    (xdc_Char)0x20,  /* [1158] */
    (xdc_Char)0x77,  /* [1159] */
    (xdc_Char)0x68,  /* [1160] */
    (xdc_Char)0x69,  /* [1161] */
    (xdc_Char)0x6c,  /* [1162] */
    (xdc_Char)0x65,  /* [1163] */
    (xdc_Char)0x20,  /* [1164] */
    (xdc_Char)0x74,  /* [1165] */
    (xdc_Char)0x68,  /* [1166] */
    (xdc_Char)0x65,  /* [1167] */
    (xdc_Char)0x20,  /* [1168] */
    (xdc_Char)0x54,  /* [1169] */
    (xdc_Char)0x61,  /* [1170] */
    (xdc_Char)0x73,  /* [1171] */
    (xdc_Char)0x6b,  /* [1172] */
    (xdc_Char)0x20,  /* [1173] */
    (xdc_Char)0x6f,  /* [1174] */
    (xdc_Char)0x72,  /* [1175] */
    (xdc_Char)0x20,  /* [1176] */
    (xdc_Char)0x53,  /* [1177] */
    (xdc_Char)0x77,  /* [1178] */
    (xdc_Char)0x69,  /* [1179] */
    (xdc_Char)0x20,  /* [1180] */
    (xdc_Char)0x73,  /* [1181] */
    (xdc_Char)0x63,  /* [1182] */
    (xdc_Char)0x68,  /* [1183] */
    (xdc_Char)0x65,  /* [1184] */
    (xdc_Char)0x64,  /* [1185] */
    (xdc_Char)0x75,  /* [1186] */
    (xdc_Char)0x6c,  /* [1187] */
    (xdc_Char)0x65,  /* [1188] */
    (xdc_Char)0x72,  /* [1189] */
    (xdc_Char)0x20,  /* [1190] */
    (xdc_Char)0x69,  /* [1191] */
    (xdc_Char)0x73,  /* [1192] */
    (xdc_Char)0x20,  /* [1193] */
    (xdc_Char)0x64,  /* [1194] */
    (xdc_Char)0x69,  /* [1195] */
    (xdc_Char)0x73,  /* [1196] */
    (xdc_Char)0x61,  /* [1197] */
    (xdc_Char)0x62,  /* [1198] */
    (xdc_Char)0x6c,  /* [1199] */
    (xdc_Char)0x65,  /* [1200] */
    (xdc_Char)0x64,  /* [1201] */
    (xdc_Char)0x2e,  /* [1202] */
    (xdc_Char)0x0,  /* [1203] */
    (xdc_Char)0x41,  /* [1204] */
    (xdc_Char)0x5f,  /* [1205] */
    (xdc_Char)0x73,  /* [1206] */
    (xdc_Char)0x77,  /* [1207] */
    (xdc_Char)0x69,  /* [1208] */
    (xdc_Char)0x44,  /* [1209] */
    (xdc_Char)0x69,  /* [1210] */
    (xdc_Char)0x73,  /* [1211] */
    (xdc_Char)0x61,  /* [1212] */
    (xdc_Char)0x62,  /* [1213] */
    (xdc_Char)0x6c,  /* [1214] */
    (xdc_Char)0x65,  /* [1215] */
    (xdc_Char)0x64,  /* [1216] */
    (xdc_Char)0x3a,  /* [1217] */
    (xdc_Char)0x20,  /* [1218] */
    (xdc_Char)0x43,  /* [1219] */
    (xdc_Char)0x61,  /* [1220] */
    (xdc_Char)0x6e,  /* [1221] */
    (xdc_Char)0x6e,  /* [1222] */
    (xdc_Char)0x6f,  /* [1223] */
    (xdc_Char)0x74,  /* [1224] */
    (xdc_Char)0x20,  /* [1225] */
    (xdc_Char)0x63,  /* [1226] */
    (xdc_Char)0x72,  /* [1227] */
    (xdc_Char)0x65,  /* [1228] */
    (xdc_Char)0x61,  /* [1229] */
    (xdc_Char)0x74,  /* [1230] */
    (xdc_Char)0x65,  /* [1231] */
    (xdc_Char)0x20,  /* [1232] */
    (xdc_Char)0x61,  /* [1233] */
    (xdc_Char)0x20,  /* [1234] */
    (xdc_Char)0x53,  /* [1235] */
    (xdc_Char)0x77,  /* [1236] */
    (xdc_Char)0x69,  /* [1237] */
    (xdc_Char)0x20,  /* [1238] */
    (xdc_Char)0x77,  /* [1239] */
    (xdc_Char)0x68,  /* [1240] */
    (xdc_Char)0x65,  /* [1241] */
    (xdc_Char)0x6e,  /* [1242] */
    (xdc_Char)0x20,  /* [1243] */
    (xdc_Char)0x53,  /* [1244] */
    (xdc_Char)0x77,  /* [1245] */
    (xdc_Char)0x69,  /* [1246] */
    (xdc_Char)0x20,  /* [1247] */
    (xdc_Char)0x69,  /* [1248] */
    (xdc_Char)0x73,  /* [1249] */
    (xdc_Char)0x20,  /* [1250] */
    (xdc_Char)0x64,  /* [1251] */
    (xdc_Char)0x69,  /* [1252] */
    (xdc_Char)0x73,  /* [1253] */
    (xdc_Char)0x61,  /* [1254] */
    (xdc_Char)0x62,  /* [1255] */
    (xdc_Char)0x6c,  /* [1256] */
    (xdc_Char)0x65,  /* [1257] */
    (xdc_Char)0x64,  /* [1258] */
    (xdc_Char)0x2e,  /* [1259] */
    (xdc_Char)0x0,  /* [1260] */
    (xdc_Char)0x41,  /* [1261] */
    (xdc_Char)0x5f,  /* [1262] */
    (xdc_Char)0x62,  /* [1263] */
    (xdc_Char)0x61,  /* [1264] */
    (xdc_Char)0x64,  /* [1265] */
    (xdc_Char)0x50,  /* [1266] */
    (xdc_Char)0x72,  /* [1267] */
    (xdc_Char)0x69,  /* [1268] */
    (xdc_Char)0x6f,  /* [1269] */
    (xdc_Char)0x72,  /* [1270] */
    (xdc_Char)0x69,  /* [1271] */
    (xdc_Char)0x74,  /* [1272] */
    (xdc_Char)0x79,  /* [1273] */
    (xdc_Char)0x3a,  /* [1274] */
    (xdc_Char)0x20,  /* [1275] */
    (xdc_Char)0x41,  /* [1276] */
    (xdc_Char)0x6e,  /* [1277] */
    (xdc_Char)0x20,  /* [1278] */
    (xdc_Char)0x69,  /* [1279] */
    (xdc_Char)0x6e,  /* [1280] */
    (xdc_Char)0x76,  /* [1281] */
    (xdc_Char)0x61,  /* [1282] */
    (xdc_Char)0x6c,  /* [1283] */
    (xdc_Char)0x69,  /* [1284] */
    (xdc_Char)0x64,  /* [1285] */
    (xdc_Char)0x20,  /* [1286] */
    (xdc_Char)0x53,  /* [1287] */
    (xdc_Char)0x77,  /* [1288] */
    (xdc_Char)0x69,  /* [1289] */
    (xdc_Char)0x20,  /* [1290] */
    (xdc_Char)0x70,  /* [1291] */
    (xdc_Char)0x72,  /* [1292] */
    (xdc_Char)0x69,  /* [1293] */
    (xdc_Char)0x6f,  /* [1294] */
    (xdc_Char)0x72,  /* [1295] */
    (xdc_Char)0x69,  /* [1296] */
    (xdc_Char)0x74,  /* [1297] */
    (xdc_Char)0x79,  /* [1298] */
    (xdc_Char)0x20,  /* [1299] */
    (xdc_Char)0x77,  /* [1300] */
    (xdc_Char)0x61,  /* [1301] */
    (xdc_Char)0x73,  /* [1302] */
    (xdc_Char)0x20,  /* [1303] */
    (xdc_Char)0x75,  /* [1304] */
    (xdc_Char)0x73,  /* [1305] */
    (xdc_Char)0x65,  /* [1306] */
    (xdc_Char)0x64,  /* [1307] */
    (xdc_Char)0x2e,  /* [1308] */
    (xdc_Char)0x0,  /* [1309] */
    (xdc_Char)0x41,  /* [1310] */
    (xdc_Char)0x5f,  /* [1311] */
    (xdc_Char)0x62,  /* [1312] */
    (xdc_Char)0x61,  /* [1313] */
    (xdc_Char)0x64,  /* [1314] */
    (xdc_Char)0x54,  /* [1315] */
    (xdc_Char)0x68,  /* [1316] */
    (xdc_Char)0x72,  /* [1317] */
    (xdc_Char)0x65,  /* [1318] */
    (xdc_Char)0x61,  /* [1319] */
    (xdc_Char)0x64,  /* [1320] */
    (xdc_Char)0x54,  /* [1321] */
    (xdc_Char)0x79,  /* [1322] */
    (xdc_Char)0x70,  /* [1323] */
    (xdc_Char)0x65,  /* [1324] */
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
    (xdc_Char)0x2f,  /* [1340] */
    (xdc_Char)0x64,  /* [1341] */
    (xdc_Char)0x65,  /* [1342] */
    (xdc_Char)0x6c,  /* [1343] */
    (xdc_Char)0x65,  /* [1344] */
    (xdc_Char)0x74,  /* [1345] */
    (xdc_Char)0x65,  /* [1346] */
    (xdc_Char)0x20,  /* [1347] */
    (xdc_Char)0x61,  /* [1348] */
    (xdc_Char)0x20,  /* [1349] */
    (xdc_Char)0x74,  /* [1350] */
    (xdc_Char)0x61,  /* [1351] */
    (xdc_Char)0x73,  /* [1352] */
    (xdc_Char)0x6b,  /* [1353] */
    (xdc_Char)0x20,  /* [1354] */
    (xdc_Char)0x66,  /* [1355] */
    (xdc_Char)0x72,  /* [1356] */
    (xdc_Char)0x6f,  /* [1357] */
    (xdc_Char)0x6d,  /* [1358] */
    (xdc_Char)0x20,  /* [1359] */
    (xdc_Char)0x48,  /* [1360] */
    (xdc_Char)0x77,  /* [1361] */
    (xdc_Char)0x69,  /* [1362] */
    (xdc_Char)0x20,  /* [1363] */
    (xdc_Char)0x6f,  /* [1364] */
    (xdc_Char)0x72,  /* [1365] */
    (xdc_Char)0x20,  /* [1366] */
    (xdc_Char)0x53,  /* [1367] */
    (xdc_Char)0x77,  /* [1368] */
    (xdc_Char)0x69,  /* [1369] */
    (xdc_Char)0x20,  /* [1370] */
    (xdc_Char)0x74,  /* [1371] */
    (xdc_Char)0x68,  /* [1372] */
    (xdc_Char)0x72,  /* [1373] */
    (xdc_Char)0x65,  /* [1374] */
    (xdc_Char)0x61,  /* [1375] */
    (xdc_Char)0x64,  /* [1376] */
    (xdc_Char)0x2e,  /* [1377] */
    (xdc_Char)0x0,  /* [1378] */
    (xdc_Char)0x41,  /* [1379] */
    (xdc_Char)0x5f,  /* [1380] */
    (xdc_Char)0x62,  /* [1381] */
    (xdc_Char)0x61,  /* [1382] */
    (xdc_Char)0x64,  /* [1383] */
    (xdc_Char)0x54,  /* [1384] */
    (xdc_Char)0x61,  /* [1385] */
    (xdc_Char)0x73,  /* [1386] */
    (xdc_Char)0x6b,  /* [1387] */
    (xdc_Char)0x53,  /* [1388] */
    (xdc_Char)0x74,  /* [1389] */
    (xdc_Char)0x61,  /* [1390] */
    (xdc_Char)0x74,  /* [1391] */
    (xdc_Char)0x65,  /* [1392] */
    (xdc_Char)0x3a,  /* [1393] */
    (xdc_Char)0x20,  /* [1394] */
    (xdc_Char)0x43,  /* [1395] */
    (xdc_Char)0x61,  /* [1396] */
    (xdc_Char)0x6e,  /* [1397] */
    (xdc_Char)0x27,  /* [1398] */
    (xdc_Char)0x74,  /* [1399] */
    (xdc_Char)0x20,  /* [1400] */
    (xdc_Char)0x64,  /* [1401] */
    (xdc_Char)0x65,  /* [1402] */
    (xdc_Char)0x6c,  /* [1403] */
    (xdc_Char)0x65,  /* [1404] */
    (xdc_Char)0x74,  /* [1405] */
    (xdc_Char)0x65,  /* [1406] */
    (xdc_Char)0x20,  /* [1407] */
    (xdc_Char)0x61,  /* [1408] */
    (xdc_Char)0x20,  /* [1409] */
    (xdc_Char)0x74,  /* [1410] */
    (xdc_Char)0x61,  /* [1411] */
    (xdc_Char)0x73,  /* [1412] */
    (xdc_Char)0x6b,  /* [1413] */
    (xdc_Char)0x20,  /* [1414] */
    (xdc_Char)0x69,  /* [1415] */
    (xdc_Char)0x6e,  /* [1416] */
    (xdc_Char)0x20,  /* [1417] */
    (xdc_Char)0x52,  /* [1418] */
    (xdc_Char)0x55,  /* [1419] */
    (xdc_Char)0x4e,  /* [1420] */
    (xdc_Char)0x4e,  /* [1421] */
    (xdc_Char)0x49,  /* [1422] */
    (xdc_Char)0x4e,  /* [1423] */
    (xdc_Char)0x47,  /* [1424] */
    (xdc_Char)0x20,  /* [1425] */
    (xdc_Char)0x73,  /* [1426] */
    (xdc_Char)0x74,  /* [1427] */
    (xdc_Char)0x61,  /* [1428] */
    (xdc_Char)0x74,  /* [1429] */
    (xdc_Char)0x65,  /* [1430] */
    (xdc_Char)0x2e,  /* [1431] */
    (xdc_Char)0x0,  /* [1432] */
    (xdc_Char)0x41,  /* [1433] */
    (xdc_Char)0x5f,  /* [1434] */
    (xdc_Char)0x6e,  /* [1435] */
    (xdc_Char)0x6f,  /* [1436] */
    (xdc_Char)0x50,  /* [1437] */
    (xdc_Char)0x65,  /* [1438] */
    (xdc_Char)0x6e,  /* [1439] */
    (xdc_Char)0x64,  /* [1440] */
    (xdc_Char)0x45,  /* [1441] */
    (xdc_Char)0x6c,  /* [1442] */
    (xdc_Char)0x65,  /* [1443] */
    (xdc_Char)0x6d,  /* [1444] */
    (xdc_Char)0x3a,  /* [1445] */
    (xdc_Char)0x20,  /* [1446] */
    (xdc_Char)0x4e,  /* [1447] */
    (xdc_Char)0x6f,  /* [1448] */
    (xdc_Char)0x74,  /* [1449] */
    (xdc_Char)0x20,  /* [1450] */
    (xdc_Char)0x65,  /* [1451] */
    (xdc_Char)0x6e,  /* [1452] */
    (xdc_Char)0x6f,  /* [1453] */
    (xdc_Char)0x75,  /* [1454] */
    (xdc_Char)0x67,  /* [1455] */
    (xdc_Char)0x68,  /* [1456] */
    (xdc_Char)0x20,  /* [1457] */
    (xdc_Char)0x69,  /* [1458] */
    (xdc_Char)0x6e,  /* [1459] */
    (xdc_Char)0x66,  /* [1460] */
    (xdc_Char)0x6f,  /* [1461] */
    (xdc_Char)0x20,  /* [1462] */
    (xdc_Char)0x74,  /* [1463] */
    (xdc_Char)0x6f,  /* [1464] */
    (xdc_Char)0x20,  /* [1465] */
    (xdc_Char)0x64,  /* [1466] */
    (xdc_Char)0x65,  /* [1467] */
    (xdc_Char)0x6c,  /* [1468] */
    (xdc_Char)0x65,  /* [1469] */
    (xdc_Char)0x74,  /* [1470] */
    (xdc_Char)0x65,  /* [1471] */
    (xdc_Char)0x20,  /* [1472] */
    (xdc_Char)0x42,  /* [1473] */
    (xdc_Char)0x4c,  /* [1474] */
    (xdc_Char)0x4f,  /* [1475] */
    (xdc_Char)0x43,  /* [1476] */
    (xdc_Char)0x4b,  /* [1477] */
    (xdc_Char)0x45,  /* [1478] */
    (xdc_Char)0x44,  /* [1479] */
    (xdc_Char)0x20,  /* [1480] */
    (xdc_Char)0x74,  /* [1481] */
    (xdc_Char)0x61,  /* [1482] */
    (xdc_Char)0x73,  /* [1483] */
    (xdc_Char)0x6b,  /* [1484] */
    (xdc_Char)0x2e,  /* [1485] */
    (xdc_Char)0x0,  /* [1486] */
    (xdc_Char)0x41,  /* [1487] */
    (xdc_Char)0x5f,  /* [1488] */
    (xdc_Char)0x74,  /* [1489] */
    (xdc_Char)0x61,  /* [1490] */
    (xdc_Char)0x73,  /* [1491] */
    (xdc_Char)0x6b,  /* [1492] */
    (xdc_Char)0x44,  /* [1493] */
    (xdc_Char)0x69,  /* [1494] */
    (xdc_Char)0x73,  /* [1495] */
    (xdc_Char)0x61,  /* [1496] */
    (xdc_Char)0x62,  /* [1497] */
    (xdc_Char)0x6c,  /* [1498] */
    (xdc_Char)0x65,  /* [1499] */
    (xdc_Char)0x64,  /* [1500] */
    (xdc_Char)0x3a,  /* [1501] */
    (xdc_Char)0x20,  /* [1502] */
    (xdc_Char)0x43,  /* [1503] */
    (xdc_Char)0x61,  /* [1504] */
    (xdc_Char)0x6e,  /* [1505] */
    (xdc_Char)0x6e,  /* [1506] */
    (xdc_Char)0x6f,  /* [1507] */
    (xdc_Char)0x74,  /* [1508] */
    (xdc_Char)0x20,  /* [1509] */
    (xdc_Char)0x63,  /* [1510] */
    (xdc_Char)0x72,  /* [1511] */
    (xdc_Char)0x65,  /* [1512] */
    (xdc_Char)0x61,  /* [1513] */
    (xdc_Char)0x74,  /* [1514] */
    (xdc_Char)0x65,  /* [1515] */
    (xdc_Char)0x20,  /* [1516] */
    (xdc_Char)0x61,  /* [1517] */
    (xdc_Char)0x20,  /* [1518] */
    (xdc_Char)0x74,  /* [1519] */
    (xdc_Char)0x61,  /* [1520] */
    (xdc_Char)0x73,  /* [1521] */
    (xdc_Char)0x6b,  /* [1522] */
    (xdc_Char)0x20,  /* [1523] */
    (xdc_Char)0x77,  /* [1524] */
    (xdc_Char)0x68,  /* [1525] */
    (xdc_Char)0x65,  /* [1526] */
    (xdc_Char)0x6e,  /* [1527] */
    (xdc_Char)0x20,  /* [1528] */
    (xdc_Char)0x74,  /* [1529] */
    (xdc_Char)0x61,  /* [1530] */
    (xdc_Char)0x73,  /* [1531] */
    (xdc_Char)0x6b,  /* [1532] */
    (xdc_Char)0x69,  /* [1533] */
    (xdc_Char)0x6e,  /* [1534] */
    (xdc_Char)0x67,  /* [1535] */
    (xdc_Char)0x20,  /* [1536] */
    (xdc_Char)0x69,  /* [1537] */
    (xdc_Char)0x73,  /* [1538] */
    (xdc_Char)0x20,  /* [1539] */
    (xdc_Char)0x64,  /* [1540] */
    (xdc_Char)0x69,  /* [1541] */
    (xdc_Char)0x73,  /* [1542] */
    (xdc_Char)0x61,  /* [1543] */
    (xdc_Char)0x62,  /* [1544] */
    (xdc_Char)0x6c,  /* [1545] */
    (xdc_Char)0x65,  /* [1546] */
    (xdc_Char)0x64,  /* [1547] */
    (xdc_Char)0x2e,  /* [1548] */
    (xdc_Char)0x0,  /* [1549] */
    (xdc_Char)0x41,  /* [1550] */
    (xdc_Char)0x5f,  /* [1551] */
    (xdc_Char)0x62,  /* [1552] */
    (xdc_Char)0x61,  /* [1553] */
    (xdc_Char)0x64,  /* [1554] */
    (xdc_Char)0x50,  /* [1555] */
    (xdc_Char)0x72,  /* [1556] */
    (xdc_Char)0x69,  /* [1557] */
    (xdc_Char)0x6f,  /* [1558] */
    (xdc_Char)0x72,  /* [1559] */
    (xdc_Char)0x69,  /* [1560] */
    (xdc_Char)0x74,  /* [1561] */
    (xdc_Char)0x79,  /* [1562] */
    (xdc_Char)0x3a,  /* [1563] */
    (xdc_Char)0x20,  /* [1564] */
    (xdc_Char)0x41,  /* [1565] */
    (xdc_Char)0x6e,  /* [1566] */
    (xdc_Char)0x20,  /* [1567] */
    (xdc_Char)0x69,  /* [1568] */
    (xdc_Char)0x6e,  /* [1569] */
    (xdc_Char)0x76,  /* [1570] */
    (xdc_Char)0x61,  /* [1571] */
    (xdc_Char)0x6c,  /* [1572] */
    (xdc_Char)0x69,  /* [1573] */
    (xdc_Char)0x64,  /* [1574] */
    (xdc_Char)0x20,  /* [1575] */
    (xdc_Char)0x74,  /* [1576] */
    (xdc_Char)0x61,  /* [1577] */
    (xdc_Char)0x73,  /* [1578] */
    (xdc_Char)0x6b,  /* [1579] */
    (xdc_Char)0x20,  /* [1580] */
    (xdc_Char)0x70,  /* [1581] */
    (xdc_Char)0x72,  /* [1582] */
    (xdc_Char)0x69,  /* [1583] */
    (xdc_Char)0x6f,  /* [1584] */
    (xdc_Char)0x72,  /* [1585] */
    (xdc_Char)0x69,  /* [1586] */
    (xdc_Char)0x74,  /* [1587] */
    (xdc_Char)0x79,  /* [1588] */
    (xdc_Char)0x20,  /* [1589] */
    (xdc_Char)0x77,  /* [1590] */
    (xdc_Char)0x61,  /* [1591] */
    (xdc_Char)0x73,  /* [1592] */
    (xdc_Char)0x20,  /* [1593] */
    (xdc_Char)0x75,  /* [1594] */
    (xdc_Char)0x73,  /* [1595] */
    (xdc_Char)0x65,  /* [1596] */
    (xdc_Char)0x64,  /* [1597] */
    (xdc_Char)0x2e,  /* [1598] */
    (xdc_Char)0x0,  /* [1599] */
    (xdc_Char)0x41,  /* [1600] */
    (xdc_Char)0x5f,  /* [1601] */
    (xdc_Char)0x62,  /* [1602] */
    (xdc_Char)0x61,  /* [1603] */
    (xdc_Char)0x64,  /* [1604] */
    (xdc_Char)0x54,  /* [1605] */
    (xdc_Char)0x69,  /* [1606] */
    (xdc_Char)0x6d,  /* [1607] */
    (xdc_Char)0x65,  /* [1608] */
    (xdc_Char)0x6f,  /* [1609] */
    (xdc_Char)0x75,  /* [1610] */
    (xdc_Char)0x74,  /* [1611] */
    (xdc_Char)0x3a,  /* [1612] */
    (xdc_Char)0x20,  /* [1613] */
    (xdc_Char)0x43,  /* [1614] */
    (xdc_Char)0x61,  /* [1615] */
    (xdc_Char)0x6e,  /* [1616] */
    (xdc_Char)0x27,  /* [1617] */
    (xdc_Char)0x74,  /* [1618] */
    (xdc_Char)0x20,  /* [1619] */
    (xdc_Char)0x73,  /* [1620] */
    (xdc_Char)0x6c,  /* [1621] */
    (xdc_Char)0x65,  /* [1622] */
    (xdc_Char)0x65,  /* [1623] */
    (xdc_Char)0x70,  /* [1624] */
    (xdc_Char)0x20,  /* [1625] */
    (xdc_Char)0x46,  /* [1626] */
    (xdc_Char)0x4f,  /* [1627] */
    (xdc_Char)0x52,  /* [1628] */
    (xdc_Char)0x45,  /* [1629] */
    (xdc_Char)0x56,  /* [1630] */
    (xdc_Char)0x45,  /* [1631] */
    (xdc_Char)0x52,  /* [1632] */
    (xdc_Char)0x2e,  /* [1633] */
    (xdc_Char)0x0,  /* [1634] */
    (xdc_Char)0x41,  /* [1635] */
    (xdc_Char)0x5f,  /* [1636] */
    (xdc_Char)0x62,  /* [1637] */
    (xdc_Char)0x61,  /* [1638] */
    (xdc_Char)0x64,  /* [1639] */
    (xdc_Char)0x41,  /* [1640] */
    (xdc_Char)0x66,  /* [1641] */
    (xdc_Char)0x66,  /* [1642] */
    (xdc_Char)0x69,  /* [1643] */
    (xdc_Char)0x6e,  /* [1644] */
    (xdc_Char)0x69,  /* [1645] */
    (xdc_Char)0x74,  /* [1646] */
    (xdc_Char)0x79,  /* [1647] */
    (xdc_Char)0x3a,  /* [1648] */
    (xdc_Char)0x20,  /* [1649] */
    (xdc_Char)0x49,  /* [1650] */
    (xdc_Char)0x6e,  /* [1651] */
    (xdc_Char)0x76,  /* [1652] */
    (xdc_Char)0x61,  /* [1653] */
    (xdc_Char)0x6c,  /* [1654] */
    (xdc_Char)0x69,  /* [1655] */
    (xdc_Char)0x64,  /* [1656] */
    (xdc_Char)0x20,  /* [1657] */
    (xdc_Char)0x61,  /* [1658] */
    (xdc_Char)0x66,  /* [1659] */
    (xdc_Char)0x66,  /* [1660] */
    (xdc_Char)0x69,  /* [1661] */
    (xdc_Char)0x6e,  /* [1662] */
    (xdc_Char)0x69,  /* [1663] */
    (xdc_Char)0x74,  /* [1664] */
    (xdc_Char)0x79,  /* [1665] */
    (xdc_Char)0x2e,  /* [1666] */
    (xdc_Char)0x0,  /* [1667] */
    (xdc_Char)0x41,  /* [1668] */
    (xdc_Char)0x5f,  /* [1669] */
    (xdc_Char)0x73,  /* [1670] */
    (xdc_Char)0x6c,  /* [1671] */
    (xdc_Char)0x65,  /* [1672] */
    (xdc_Char)0x65,  /* [1673] */
    (xdc_Char)0x70,  /* [1674] */
    (xdc_Char)0x54,  /* [1675] */
    (xdc_Char)0x61,  /* [1676] */
    (xdc_Char)0x73,  /* [1677] */
    (xdc_Char)0x6b,  /* [1678] */
    (xdc_Char)0x44,  /* [1679] */
    (xdc_Char)0x69,  /* [1680] */
    (xdc_Char)0x73,  /* [1681] */
    (xdc_Char)0x61,  /* [1682] */
    (xdc_Char)0x62,  /* [1683] */
    (xdc_Char)0x6c,  /* [1684] */
    (xdc_Char)0x65,  /* [1685] */
    (xdc_Char)0x64,  /* [1686] */
    (xdc_Char)0x3a,  /* [1687] */
    (xdc_Char)0x20,  /* [1688] */
    (xdc_Char)0x43,  /* [1689] */
    (xdc_Char)0x61,  /* [1690] */
    (xdc_Char)0x6e,  /* [1691] */
    (xdc_Char)0x6e,  /* [1692] */
    (xdc_Char)0x6f,  /* [1693] */
    (xdc_Char)0x74,  /* [1694] */
    (xdc_Char)0x20,  /* [1695] */
    (xdc_Char)0x63,  /* [1696] */
    (xdc_Char)0x61,  /* [1697] */
    (xdc_Char)0x6c,  /* [1698] */
    (xdc_Char)0x6c,  /* [1699] */
    (xdc_Char)0x20,  /* [1700] */
    (xdc_Char)0x54,  /* [1701] */
    (xdc_Char)0x61,  /* [1702] */
    (xdc_Char)0x73,  /* [1703] */
    (xdc_Char)0x6b,  /* [1704] */
    (xdc_Char)0x5f,  /* [1705] */
    (xdc_Char)0x73,  /* [1706] */
    (xdc_Char)0x6c,  /* [1707] */
    (xdc_Char)0x65,  /* [1708] */
    (xdc_Char)0x65,  /* [1709] */
    (xdc_Char)0x70,  /* [1710] */
    (xdc_Char)0x28,  /* [1711] */
    (xdc_Char)0x29,  /* [1712] */
    (xdc_Char)0x20,  /* [1713] */
    (xdc_Char)0x77,  /* [1714] */
    (xdc_Char)0x68,  /* [1715] */
    (xdc_Char)0x69,  /* [1716] */
    (xdc_Char)0x6c,  /* [1717] */
    (xdc_Char)0x65,  /* [1718] */
    (xdc_Char)0x20,  /* [1719] */
    (xdc_Char)0x74,  /* [1720] */
    (xdc_Char)0x68,  /* [1721] */
    (xdc_Char)0x65,  /* [1722] */
    (xdc_Char)0x20,  /* [1723] */
    (xdc_Char)0x54,  /* [1724] */
    (xdc_Char)0x61,  /* [1725] */
    (xdc_Char)0x73,  /* [1726] */
    (xdc_Char)0x6b,  /* [1727] */
    (xdc_Char)0x20,  /* [1728] */
    (xdc_Char)0x73,  /* [1729] */
    (xdc_Char)0x63,  /* [1730] */
    (xdc_Char)0x68,  /* [1731] */
    (xdc_Char)0x65,  /* [1732] */
    (xdc_Char)0x64,  /* [1733] */
    (xdc_Char)0x75,  /* [1734] */
    (xdc_Char)0x6c,  /* [1735] */
    (xdc_Char)0x65,  /* [1736] */
    (xdc_Char)0x72,  /* [1737] */
    (xdc_Char)0x20,  /* [1738] */
    (xdc_Char)0x69,  /* [1739] */
    (xdc_Char)0x73,  /* [1740] */
    (xdc_Char)0x20,  /* [1741] */
    (xdc_Char)0x64,  /* [1742] */
    (xdc_Char)0x69,  /* [1743] */
    (xdc_Char)0x73,  /* [1744] */
    (xdc_Char)0x61,  /* [1745] */
    (xdc_Char)0x62,  /* [1746] */
    (xdc_Char)0x6c,  /* [1747] */
    (xdc_Char)0x65,  /* [1748] */
    (xdc_Char)0x64,  /* [1749] */
    (xdc_Char)0x2e,  /* [1750] */
    (xdc_Char)0x0,  /* [1751] */
    (xdc_Char)0x41,  /* [1752] */
    (xdc_Char)0x5f,  /* [1753] */
    (xdc_Char)0x69,  /* [1754] */
    (xdc_Char)0x6e,  /* [1755] */
    (xdc_Char)0x76,  /* [1756] */
    (xdc_Char)0x61,  /* [1757] */
    (xdc_Char)0x6c,  /* [1758] */
    (xdc_Char)0x69,  /* [1759] */
    (xdc_Char)0x64,  /* [1760] */
    (xdc_Char)0x43,  /* [1761] */
    (xdc_Char)0x6f,  /* [1762] */
    (xdc_Char)0x72,  /* [1763] */
    (xdc_Char)0x65,  /* [1764] */
    (xdc_Char)0x49,  /* [1765] */
    (xdc_Char)0x64,  /* [1766] */
    (xdc_Char)0x3a,  /* [1767] */
    (xdc_Char)0x20,  /* [1768] */
    (xdc_Char)0x43,  /* [1769] */
    (xdc_Char)0x61,  /* [1770] */
    (xdc_Char)0x6e,  /* [1771] */
    (xdc_Char)0x6e,  /* [1772] */
    (xdc_Char)0x6f,  /* [1773] */
    (xdc_Char)0x74,  /* [1774] */
    (xdc_Char)0x20,  /* [1775] */
    (xdc_Char)0x70,  /* [1776] */
    (xdc_Char)0x61,  /* [1777] */
    (xdc_Char)0x73,  /* [1778] */
    (xdc_Char)0x73,  /* [1779] */
    (xdc_Char)0x20,  /* [1780] */
    (xdc_Char)0x61,  /* [1781] */
    (xdc_Char)0x20,  /* [1782] */
    (xdc_Char)0x6e,  /* [1783] */
    (xdc_Char)0x6f,  /* [1784] */
    (xdc_Char)0x6e,  /* [1785] */
    (xdc_Char)0x2d,  /* [1786] */
    (xdc_Char)0x7a,  /* [1787] */
    (xdc_Char)0x65,  /* [1788] */
    (xdc_Char)0x72,  /* [1789] */
    (xdc_Char)0x6f,  /* [1790] */
    (xdc_Char)0x20,  /* [1791] */
    (xdc_Char)0x43,  /* [1792] */
    (xdc_Char)0x6f,  /* [1793] */
    (xdc_Char)0x72,  /* [1794] */
    (xdc_Char)0x65,  /* [1795] */
    (xdc_Char)0x49,  /* [1796] */
    (xdc_Char)0x64,  /* [1797] */
    (xdc_Char)0x20,  /* [1798] */
    (xdc_Char)0x69,  /* [1799] */
    (xdc_Char)0x6e,  /* [1800] */
    (xdc_Char)0x20,  /* [1801] */
    (xdc_Char)0x61,  /* [1802] */
    (xdc_Char)0x20,  /* [1803] */
    (xdc_Char)0x6e,  /* [1804] */
    (xdc_Char)0x6f,  /* [1805] */
    (xdc_Char)0x6e,  /* [1806] */
    (xdc_Char)0x2d,  /* [1807] */
    (xdc_Char)0x53,  /* [1808] */
    (xdc_Char)0x4d,  /* [1809] */
    (xdc_Char)0x50,  /* [1810] */
    (xdc_Char)0x20,  /* [1811] */
    (xdc_Char)0x61,  /* [1812] */
    (xdc_Char)0x70,  /* [1813] */
    (xdc_Char)0x70,  /* [1814] */
    (xdc_Char)0x6c,  /* [1815] */
    (xdc_Char)0x69,  /* [1816] */
    (xdc_Char)0x63,  /* [1817] */
    (xdc_Char)0x61,  /* [1818] */
    (xdc_Char)0x74,  /* [1819] */
    (xdc_Char)0x69,  /* [1820] */
    (xdc_Char)0x6f,  /* [1821] */
    (xdc_Char)0x6e,  /* [1822] */
    (xdc_Char)0x2e,  /* [1823] */
    (xdc_Char)0x0,  /* [1824] */
    (xdc_Char)0x41,  /* [1825] */
    (xdc_Char)0x5f,  /* [1826] */
    (xdc_Char)0x62,  /* [1827] */
    (xdc_Char)0x61,  /* [1828] */
    (xdc_Char)0x64,  /* [1829] */
    (xdc_Char)0x45,  /* [1830] */
    (xdc_Char)0x76,  /* [1831] */
    (xdc_Char)0x65,  /* [1832] */
    (xdc_Char)0x58,  /* [1833] */
    (xdc_Char)0x62,  /* [1834] */
    (xdc_Char)0x61,  /* [1835] */
    (xdc_Char)0x72,  /* [1836] */
    (xdc_Char)0x49,  /* [1837] */
    (xdc_Char)0x6e,  /* [1838] */
    (xdc_Char)0x73,  /* [1839] */
    (xdc_Char)0x74,  /* [1840] */
    (xdc_Char)0x61,  /* [1841] */
    (xdc_Char)0x6e,  /* [1842] */
    (xdc_Char)0x63,  /* [1843] */
    (xdc_Char)0x65,  /* [1844] */
    (xdc_Char)0x4e,  /* [1845] */
    (xdc_Char)0x75,  /* [1846] */
    (xdc_Char)0x6d,  /* [1847] */
    (xdc_Char)0x3a,  /* [1848] */
    (xdc_Char)0x20,  /* [1849] */
    (xdc_Char)0x78,  /* [1850] */
    (xdc_Char)0x62,  /* [1851] */
    (xdc_Char)0x61,  /* [1852] */
    (xdc_Char)0x72,  /* [1853] */
    (xdc_Char)0x49,  /* [1854] */
    (xdc_Char)0x6e,  /* [1855] */
    (xdc_Char)0x73,  /* [1856] */
    (xdc_Char)0x74,  /* [1857] */
    (xdc_Char)0x61,  /* [1858] */
    (xdc_Char)0x6e,  /* [1859] */
    (xdc_Char)0x63,  /* [1860] */
    (xdc_Char)0x65,  /* [1861] */
    (xdc_Char)0x20,  /* [1862] */
    (xdc_Char)0x6d,  /* [1863] */
    (xdc_Char)0x75,  /* [1864] */
    (xdc_Char)0x73,  /* [1865] */
    (xdc_Char)0x74,  /* [1866] */
    (xdc_Char)0x20,  /* [1867] */
    (xdc_Char)0x62,  /* [1868] */
    (xdc_Char)0x65,  /* [1869] */
    (xdc_Char)0x20,  /* [1870] */
    (xdc_Char)0x3e,  /* [1871] */
    (xdc_Char)0x3d,  /* [1872] */
    (xdc_Char)0x20,  /* [1873] */
    (xdc_Char)0x31,  /* [1874] */
    (xdc_Char)0x20,  /* [1875] */
    (xdc_Char)0x61,  /* [1876] */
    (xdc_Char)0x6e,  /* [1877] */
    (xdc_Char)0x64,  /* [1878] */
    (xdc_Char)0x20,  /* [1879] */
    (xdc_Char)0x3c,  /* [1880] */
    (xdc_Char)0x3d,  /* [1881] */
    (xdc_Char)0x20,  /* [1882] */
    (xdc_Char)0x38,  /* [1883] */
    (xdc_Char)0x0,  /* [1884] */
    (xdc_Char)0x41,  /* [1885] */
    (xdc_Char)0x5f,  /* [1886] */
    (xdc_Char)0x62,  /* [1887] */
    (xdc_Char)0x61,  /* [1888] */
    (xdc_Char)0x64,  /* [1889] */
    (xdc_Char)0x44,  /* [1890] */
    (xdc_Char)0x73,  /* [1891] */
    (xdc_Char)0x70,  /* [1892] */
    (xdc_Char)0x58,  /* [1893] */
    (xdc_Char)0x62,  /* [1894] */
    (xdc_Char)0x61,  /* [1895] */
    (xdc_Char)0x72,  /* [1896] */
    (xdc_Char)0x49,  /* [1897] */
    (xdc_Char)0x6e,  /* [1898] */
    (xdc_Char)0x73,  /* [1899] */
    (xdc_Char)0x74,  /* [1900] */
    (xdc_Char)0x61,  /* [1901] */
    (xdc_Char)0x6e,  /* [1902] */
    (xdc_Char)0x63,  /* [1903] */
    (xdc_Char)0x65,  /* [1904] */
    (xdc_Char)0x4e,  /* [1905] */
    (xdc_Char)0x75,  /* [1906] */
    (xdc_Char)0x6d,  /* [1907] */
    (xdc_Char)0x3a,  /* [1908] */
    (xdc_Char)0x20,  /* [1909] */
    (xdc_Char)0x78,  /* [1910] */
    (xdc_Char)0x62,  /* [1911] */
    (xdc_Char)0x61,  /* [1912] */
    (xdc_Char)0x72,  /* [1913] */
    (xdc_Char)0x49,  /* [1914] */
    (xdc_Char)0x6e,  /* [1915] */
    (xdc_Char)0x73,  /* [1916] */
    (xdc_Char)0x74,  /* [1917] */
    (xdc_Char)0x61,  /* [1918] */
    (xdc_Char)0x6e,  /* [1919] */
    (xdc_Char)0x63,  /* [1920] */
    (xdc_Char)0x65,  /* [1921] */
    (xdc_Char)0x20,  /* [1922] */
    (xdc_Char)0x6d,  /* [1923] */
    (xdc_Char)0x75,  /* [1924] */
    (xdc_Char)0x73,  /* [1925] */
    (xdc_Char)0x74,  /* [1926] */
    (xdc_Char)0x20,  /* [1927] */
    (xdc_Char)0x62,  /* [1928] */
    (xdc_Char)0x65,  /* [1929] */
    (xdc_Char)0x20,  /* [1930] */
    (xdc_Char)0x3e,  /* [1931] */
    (xdc_Char)0x3d,  /* [1932] */
    (xdc_Char)0x20,  /* [1933] */
    (xdc_Char)0x31,  /* [1934] */
    (xdc_Char)0x20,  /* [1935] */
    (xdc_Char)0x61,  /* [1936] */
    (xdc_Char)0x6e,  /* [1937] */
    (xdc_Char)0x64,  /* [1938] */
    (xdc_Char)0x20,  /* [1939] */
    (xdc_Char)0x3c,  /* [1940] */
    (xdc_Char)0x3d,  /* [1941] */
    (xdc_Char)0x20,  /* [1942] */
    (xdc_Char)0x36,  /* [1943] */
    (xdc_Char)0x34,  /* [1944] */
    (xdc_Char)0x0,  /* [1945] */
    (xdc_Char)0x41,  /* [1946] */
    (xdc_Char)0x5f,  /* [1947] */
    (xdc_Char)0x62,  /* [1948] */
    (xdc_Char)0x61,  /* [1949] */
    (xdc_Char)0x64,  /* [1950] */
    (xdc_Char)0x42,  /* [1951] */
    (xdc_Char)0x65,  /* [1952] */
    (xdc_Char)0x6e,  /* [1953] */
    (xdc_Char)0x65,  /* [1954] */
    (xdc_Char)0x6c,  /* [1955] */
    (xdc_Char)0x6c,  /* [1956] */
    (xdc_Char)0x69,  /* [1957] */
    (xdc_Char)0x58,  /* [1958] */
    (xdc_Char)0x62,  /* [1959] */
    (xdc_Char)0x61,  /* [1960] */
    (xdc_Char)0x72,  /* [1961] */
    (xdc_Char)0x49,  /* [1962] */
    (xdc_Char)0x6e,  /* [1963] */
    (xdc_Char)0x73,  /* [1964] */
    (xdc_Char)0x74,  /* [1965] */
    (xdc_Char)0x61,  /* [1966] */
    (xdc_Char)0x6e,  /* [1967] */
    (xdc_Char)0x63,  /* [1968] */
    (xdc_Char)0x65,  /* [1969] */
    (xdc_Char)0x4e,  /* [1970] */
    (xdc_Char)0x75,  /* [1971] */
    (xdc_Char)0x6d,  /* [1972] */
    (xdc_Char)0x3a,  /* [1973] */
    (xdc_Char)0x20,  /* [1974] */
    (xdc_Char)0x78,  /* [1975] */
    (xdc_Char)0x62,  /* [1976] */
    (xdc_Char)0x61,  /* [1977] */
    (xdc_Char)0x72,  /* [1978] */
    (xdc_Char)0x49,  /* [1979] */
    (xdc_Char)0x6e,  /* [1980] */
    (xdc_Char)0x73,  /* [1981] */
    (xdc_Char)0x74,  /* [1982] */
    (xdc_Char)0x61,  /* [1983] */
    (xdc_Char)0x6e,  /* [1984] */
    (xdc_Char)0x63,  /* [1985] */
    (xdc_Char)0x65,  /* [1986] */
    (xdc_Char)0x20,  /* [1987] */
    (xdc_Char)0x6d,  /* [1988] */
    (xdc_Char)0x75,  /* [1989] */
    (xdc_Char)0x73,  /* [1990] */
    (xdc_Char)0x74,  /* [1991] */
    (xdc_Char)0x20,  /* [1992] */
    (xdc_Char)0x62,  /* [1993] */
    (xdc_Char)0x65,  /* [1994] */
    (xdc_Char)0x20,  /* [1995] */
    (xdc_Char)0x3e,  /* [1996] */
    (xdc_Char)0x3d,  /* [1997] */
    (xdc_Char)0x20,  /* [1998] */
    (xdc_Char)0x31,  /* [1999] */
    (xdc_Char)0x20,  /* [2000] */
    (xdc_Char)0x61,  /* [2001] */
    (xdc_Char)0x6e,  /* [2002] */
    (xdc_Char)0x64,  /* [2003] */
    (xdc_Char)0x20,  /* [2004] */
    (xdc_Char)0x3c,  /* [2005] */
    (xdc_Char)0x3d,  /* [2006] */
    (xdc_Char)0x20,  /* [2007] */
    (xdc_Char)0x35,  /* [2008] */
    (xdc_Char)0x37,  /* [2009] */
    (xdc_Char)0x0,  /* [2010] */
    (xdc_Char)0x41,  /* [2011] */
    (xdc_Char)0x5f,  /* [2012] */
    (xdc_Char)0x62,  /* [2013] */
    (xdc_Char)0x61,  /* [2014] */
    (xdc_Char)0x64,  /* [2015] */
    (xdc_Char)0x41,  /* [2016] */
    (xdc_Char)0x31,  /* [2017] */
    (xdc_Char)0x35,  /* [2018] */
    (xdc_Char)0x58,  /* [2019] */
    (xdc_Char)0x62,  /* [2020] */
    (xdc_Char)0x61,  /* [2021] */
    (xdc_Char)0x72,  /* [2022] */
    (xdc_Char)0x49,  /* [2023] */
    (xdc_Char)0x6e,  /* [2024] */
    (xdc_Char)0x73,  /* [2025] */
    (xdc_Char)0x74,  /* [2026] */
    (xdc_Char)0x61,  /* [2027] */
    (xdc_Char)0x6e,  /* [2028] */
    (xdc_Char)0x63,  /* [2029] */
    (xdc_Char)0x65,  /* [2030] */
    (xdc_Char)0x4e,  /* [2031] */
    (xdc_Char)0x75,  /* [2032] */
    (xdc_Char)0x6d,  /* [2033] */
    (xdc_Char)0x3a,  /* [2034] */
    (xdc_Char)0x20,  /* [2035] */
    (xdc_Char)0x78,  /* [2036] */
    (xdc_Char)0x62,  /* [2037] */
    (xdc_Char)0x61,  /* [2038] */
    (xdc_Char)0x72,  /* [2039] */
    (xdc_Char)0x49,  /* [2040] */
    (xdc_Char)0x6e,  /* [2041] */
    (xdc_Char)0x73,  /* [2042] */
    (xdc_Char)0x74,  /* [2043] */
    (xdc_Char)0x61,  /* [2044] */
    (xdc_Char)0x6e,  /* [2045] */
    (xdc_Char)0x63,  /* [2046] */
    (xdc_Char)0x65,  /* [2047] */
    (xdc_Char)0x20,  /* [2048] */
    (xdc_Char)0x6d,  /* [2049] */
    (xdc_Char)0x75,  /* [2050] */
    (xdc_Char)0x73,  /* [2051] */
    (xdc_Char)0x74,  /* [2052] */
    (xdc_Char)0x20,  /* [2053] */
    (xdc_Char)0x62,  /* [2054] */
    (xdc_Char)0x65,  /* [2055] */
    (xdc_Char)0x20,  /* [2056] */
    (xdc_Char)0x3e,  /* [2057] */
    (xdc_Char)0x3d,  /* [2058] */
    (xdc_Char)0x20,  /* [2059] */
    (xdc_Char)0x31,  /* [2060] */
    (xdc_Char)0x20,  /* [2061] */
    (xdc_Char)0x61,  /* [2062] */
    (xdc_Char)0x6e,  /* [2063] */
    (xdc_Char)0x64,  /* [2064] */
    (xdc_Char)0x20,  /* [2065] */
    (xdc_Char)0x3c,  /* [2066] */
    (xdc_Char)0x3d,  /* [2067] */
    (xdc_Char)0x20,  /* [2068] */
    (xdc_Char)0x31,  /* [2069] */
    (xdc_Char)0x35,  /* [2070] */
    (xdc_Char)0x32,  /* [2071] */
    (xdc_Char)0x0,  /* [2072] */
    (xdc_Char)0x41,  /* [2073] */
    (xdc_Char)0x5f,  /* [2074] */
    (xdc_Char)0x62,  /* [2075] */
    (xdc_Char)0x61,  /* [2076] */
    (xdc_Char)0x64,  /* [2077] */
    (xdc_Char)0x45,  /* [2078] */
    (xdc_Char)0x76,  /* [2079] */
    (xdc_Char)0x65,  /* [2080] */
    (xdc_Char)0x49,  /* [2081] */
    (xdc_Char)0x52,  /* [2082] */
    (xdc_Char)0x51,  /* [2083] */
    (xdc_Char)0x4e,  /* [2084] */
    (xdc_Char)0x75,  /* [2085] */
    (xdc_Char)0x6d,  /* [2086] */
    (xdc_Char)0x3a,  /* [2087] */
    (xdc_Char)0x20,  /* [2088] */
    (xdc_Char)0x49,  /* [2089] */
    (xdc_Char)0x52,  /* [2090] */
    (xdc_Char)0x51,  /* [2091] */
    (xdc_Char)0x20,  /* [2092] */
    (xdc_Char)0x6e,  /* [2093] */
    (xdc_Char)0x75,  /* [2094] */
    (xdc_Char)0x6d,  /* [2095] */
    (xdc_Char)0x62,  /* [2096] */
    (xdc_Char)0x65,  /* [2097] */
    (xdc_Char)0x72,  /* [2098] */
    (xdc_Char)0x20,  /* [2099] */
    (xdc_Char)0x6d,  /* [2100] */
    (xdc_Char)0x75,  /* [2101] */
    (xdc_Char)0x73,  /* [2102] */
    (xdc_Char)0x74,  /* [2103] */
    (xdc_Char)0x20,  /* [2104] */
    (xdc_Char)0x62,  /* [2105] */
    (xdc_Char)0x65,  /* [2106] */
    (xdc_Char)0x20,  /* [2107] */
    (xdc_Char)0x3c,  /* [2108] */
    (xdc_Char)0x3d,  /* [2109] */
    (xdc_Char)0x20,  /* [2110] */
    (xdc_Char)0x37,  /* [2111] */
    (xdc_Char)0x0,  /* [2112] */
    (xdc_Char)0x41,  /* [2113] */
    (xdc_Char)0x5f,  /* [2114] */
    (xdc_Char)0x62,  /* [2115] */
    (xdc_Char)0x61,  /* [2116] */
    (xdc_Char)0x64,  /* [2117] */
    (xdc_Char)0x44,  /* [2118] */
    (xdc_Char)0x73,  /* [2119] */
    (xdc_Char)0x70,  /* [2120] */
    (xdc_Char)0x49,  /* [2121] */
    (xdc_Char)0x52,  /* [2122] */
    (xdc_Char)0x51,  /* [2123] */
    (xdc_Char)0x4e,  /* [2124] */
    (xdc_Char)0x75,  /* [2125] */
    (xdc_Char)0x6d,  /* [2126] */
    (xdc_Char)0x3a,  /* [2127] */
    (xdc_Char)0x20,  /* [2128] */
    (xdc_Char)0x49,  /* [2129] */
    (xdc_Char)0x52,  /* [2130] */
    (xdc_Char)0x51,  /* [2131] */
    (xdc_Char)0x20,  /* [2132] */
    (xdc_Char)0x6e,  /* [2133] */
    (xdc_Char)0x75,  /* [2134] */
    (xdc_Char)0x6d,  /* [2135] */
    (xdc_Char)0x62,  /* [2136] */
    (xdc_Char)0x65,  /* [2137] */
    (xdc_Char)0x72,  /* [2138] */
    (xdc_Char)0x20,  /* [2139] */
    (xdc_Char)0x6d,  /* [2140] */
    (xdc_Char)0x75,  /* [2141] */
    (xdc_Char)0x73,  /* [2142] */
    (xdc_Char)0x74,  /* [2143] */
    (xdc_Char)0x20,  /* [2144] */
    (xdc_Char)0x62,  /* [2145] */
    (xdc_Char)0x65,  /* [2146] */
    (xdc_Char)0x20,  /* [2147] */
    (xdc_Char)0x3e,  /* [2148] */
    (xdc_Char)0x3d,  /* [2149] */
    (xdc_Char)0x20,  /* [2150] */
    (xdc_Char)0x33,  /* [2151] */
    (xdc_Char)0x32,  /* [2152] */
    (xdc_Char)0x20,  /* [2153] */
    (xdc_Char)0x61,  /* [2154] */
    (xdc_Char)0x6e,  /* [2155] */
    (xdc_Char)0x64,  /* [2156] */
    (xdc_Char)0x20,  /* [2157] */
    (xdc_Char)0x3c,  /* [2158] */
    (xdc_Char)0x3d,  /* [2159] */
    (xdc_Char)0x20,  /* [2160] */
    (xdc_Char)0x39,  /* [2161] */
    (xdc_Char)0x35,  /* [2162] */
    (xdc_Char)0x0,  /* [2163] */
    (xdc_Char)0x41,  /* [2164] */
    (xdc_Char)0x5f,  /* [2165] */
    (xdc_Char)0x62,  /* [2166] */
    (xdc_Char)0x61,  /* [2167] */
    (xdc_Char)0x64,  /* [2168] */
    (xdc_Char)0x42,  /* [2169] */
    (xdc_Char)0x65,  /* [2170] */
    (xdc_Char)0x6e,  /* [2171] */
    (xdc_Char)0x65,  /* [2172] */
    (xdc_Char)0x6c,  /* [2173] */
    (xdc_Char)0x6c,  /* [2174] */
    (xdc_Char)0x69,  /* [2175] */
    (xdc_Char)0x49,  /* [2176] */
    (xdc_Char)0x52,  /* [2177] */
    (xdc_Char)0x51,  /* [2178] */
    (xdc_Char)0x4e,  /* [2179] */
    (xdc_Char)0x75,  /* [2180] */
    (xdc_Char)0x6d,  /* [2181] */
    (xdc_Char)0x3a,  /* [2182] */
    (xdc_Char)0x20,  /* [2183] */
    (xdc_Char)0x49,  /* [2184] */
    (xdc_Char)0x52,  /* [2185] */
    (xdc_Char)0x51,  /* [2186] */
    (xdc_Char)0x20,  /* [2187] */
    (xdc_Char)0x6e,  /* [2188] */
    (xdc_Char)0x75,  /* [2189] */
    (xdc_Char)0x6d,  /* [2190] */
    (xdc_Char)0x62,  /* [2191] */
    (xdc_Char)0x65,  /* [2192] */
    (xdc_Char)0x72,  /* [2193] */
    (xdc_Char)0x20,  /* [2194] */
    (xdc_Char)0x6d,  /* [2195] */
    (xdc_Char)0x75,  /* [2196] */
    (xdc_Char)0x73,  /* [2197] */
    (xdc_Char)0x74,  /* [2198] */
    (xdc_Char)0x20,  /* [2199] */
    (xdc_Char)0x62,  /* [2200] */
    (xdc_Char)0x65,  /* [2201] */
    (xdc_Char)0x20,  /* [2202] */
    (xdc_Char)0x3e,  /* [2203] */
    (xdc_Char)0x3d,  /* [2204] */
    (xdc_Char)0x20,  /* [2205] */
    (xdc_Char)0x32,  /* [2206] */
    (xdc_Char)0x33,  /* [2207] */
    (xdc_Char)0x20,  /* [2208] */
    (xdc_Char)0x61,  /* [2209] */
    (xdc_Char)0x6e,  /* [2210] */
    (xdc_Char)0x64,  /* [2211] */
    (xdc_Char)0x20,  /* [2212] */
    (xdc_Char)0x3c,  /* [2213] */
    (xdc_Char)0x3d,  /* [2214] */
    (xdc_Char)0x20,  /* [2215] */
    (xdc_Char)0x37,  /* [2216] */
    (xdc_Char)0x39,  /* [2217] */
    (xdc_Char)0x0,  /* [2218] */
    (xdc_Char)0x41,  /* [2219] */
    (xdc_Char)0x5f,  /* [2220] */
    (xdc_Char)0x62,  /* [2221] */
    (xdc_Char)0x61,  /* [2222] */
    (xdc_Char)0x64,  /* [2223] */
    (xdc_Char)0x41,  /* [2224] */
    (xdc_Char)0x31,  /* [2225] */
    (xdc_Char)0x35,  /* [2226] */
    (xdc_Char)0x49,  /* [2227] */
    (xdc_Char)0x52,  /* [2228] */
    (xdc_Char)0x51,  /* [2229] */
    (xdc_Char)0x4e,  /* [2230] */
    (xdc_Char)0x75,  /* [2231] */
    (xdc_Char)0x6d,  /* [2232] */
    (xdc_Char)0x3a,  /* [2233] */
    (xdc_Char)0x20,  /* [2234] */
    (xdc_Char)0x4e,  /* [2235] */
    (xdc_Char)0x6f,  /* [2236] */
    (xdc_Char)0x20,  /* [2237] */
    (xdc_Char)0x58,  /* [2238] */
    (xdc_Char)0x42,  /* [2239] */
    (xdc_Char)0x41,  /* [2240] */
    (xdc_Char)0x52,  /* [2241] */
    (xdc_Char)0x20,  /* [2242] */
    (xdc_Char)0x69,  /* [2243] */
    (xdc_Char)0x6e,  /* [2244] */
    (xdc_Char)0x73,  /* [2245] */
    (xdc_Char)0x74,  /* [2246] */
    (xdc_Char)0x61,  /* [2247] */
    (xdc_Char)0x6e,  /* [2248] */
    (xdc_Char)0x63,  /* [2249] */
    (xdc_Char)0x65,  /* [2250] */
    (xdc_Char)0x20,  /* [2251] */
    (xdc_Char)0x63,  /* [2252] */
    (xdc_Char)0x6f,  /* [2253] */
    (xdc_Char)0x72,  /* [2254] */
    (xdc_Char)0x72,  /* [2255] */
    (xdc_Char)0x65,  /* [2256] */
    (xdc_Char)0x73,  /* [2257] */
    (xdc_Char)0x70,  /* [2258] */
    (xdc_Char)0x6f,  /* [2259] */
    (xdc_Char)0x6e,  /* [2260] */
    (xdc_Char)0x64,  /* [2261] */
    (xdc_Char)0x69,  /* [2262] */
    (xdc_Char)0x6e,  /* [2263] */
    (xdc_Char)0x67,  /* [2264] */
    (xdc_Char)0x20,  /* [2265] */
    (xdc_Char)0x74,  /* [2266] */
    (xdc_Char)0x6f,  /* [2267] */
    (xdc_Char)0x20,  /* [2268] */
    (xdc_Char)0x67,  /* [2269] */
    (xdc_Char)0x69,  /* [2270] */
    (xdc_Char)0x76,  /* [2271] */
    (xdc_Char)0x65,  /* [2272] */
    (xdc_Char)0x6e,  /* [2273] */
    (xdc_Char)0x20,  /* [2274] */
    (xdc_Char)0x49,  /* [2275] */
    (xdc_Char)0x52,  /* [2276] */
    (xdc_Char)0x51,  /* [2277] */
    (xdc_Char)0x20,  /* [2278] */
    (xdc_Char)0x6e,  /* [2279] */
    (xdc_Char)0x75,  /* [2280] */
    (xdc_Char)0x6d,  /* [2281] */
    (xdc_Char)0x0,  /* [2282] */
    (xdc_Char)0x41,  /* [2283] */
    (xdc_Char)0x5f,  /* [2284] */
    (xdc_Char)0x62,  /* [2285] */
    (xdc_Char)0x61,  /* [2286] */
    (xdc_Char)0x64,  /* [2287] */
    (xdc_Char)0x49,  /* [2288] */
    (xdc_Char)0x6e,  /* [2289] */
    (xdc_Char)0x74,  /* [2290] */
    (xdc_Char)0x53,  /* [2291] */
    (xdc_Char)0x6f,  /* [2292] */
    (xdc_Char)0x75,  /* [2293] */
    (xdc_Char)0x72,  /* [2294] */
    (xdc_Char)0x63,  /* [2295] */
    (xdc_Char)0x65,  /* [2296] */
    (xdc_Char)0x49,  /* [2297] */
    (xdc_Char)0x64,  /* [2298] */
    (xdc_Char)0x78,  /* [2299] */
    (xdc_Char)0x3a,  /* [2300] */
    (xdc_Char)0x20,  /* [2301] */
    (xdc_Char)0x49,  /* [2302] */
    (xdc_Char)0x52,  /* [2303] */
    (xdc_Char)0x51,  /* [2304] */
    (xdc_Char)0x20,  /* [2305] */
    (xdc_Char)0x63,  /* [2306] */
    (xdc_Char)0x72,  /* [2307] */
    (xdc_Char)0x6f,  /* [2308] */
    (xdc_Char)0x73,  /* [2309] */
    (xdc_Char)0x73,  /* [2310] */
    (xdc_Char)0x62,  /* [2311] */
    (xdc_Char)0x61,  /* [2312] */
    (xdc_Char)0x72,  /* [2313] */
    (xdc_Char)0x20,  /* [2314] */
    (xdc_Char)0x69,  /* [2315] */
    (xdc_Char)0x6e,  /* [2316] */
    (xdc_Char)0x70,  /* [2317] */
    (xdc_Char)0x75,  /* [2318] */
    (xdc_Char)0x74,  /* [2319] */
    (xdc_Char)0x20,  /* [2320] */
    (xdc_Char)0x69,  /* [2321] */
    (xdc_Char)0x6e,  /* [2322] */
    (xdc_Char)0x64,  /* [2323] */
    (xdc_Char)0x65,  /* [2324] */
    (xdc_Char)0x78,  /* [2325] */
    (xdc_Char)0x20,  /* [2326] */
    (xdc_Char)0x28,  /* [2327] */
    (xdc_Char)0x69,  /* [2328] */
    (xdc_Char)0x6e,  /* [2329] */
    (xdc_Char)0x74,  /* [2330] */
    (xdc_Char)0x53,  /* [2331] */
    (xdc_Char)0x6f,  /* [2332] */
    (xdc_Char)0x75,  /* [2333] */
    (xdc_Char)0x72,  /* [2334] */
    (xdc_Char)0x63,  /* [2335] */
    (xdc_Char)0x65,  /* [2336] */
    (xdc_Char)0x29,  /* [2337] */
    (xdc_Char)0x20,  /* [2338] */
    (xdc_Char)0x6f,  /* [2339] */
    (xdc_Char)0x75,  /* [2340] */
    (xdc_Char)0x74,  /* [2341] */
    (xdc_Char)0x20,  /* [2342] */
    (xdc_Char)0x6f,  /* [2343] */
    (xdc_Char)0x66,  /* [2344] */
    (xdc_Char)0x20,  /* [2345] */
    (xdc_Char)0x72,  /* [2346] */
    (xdc_Char)0x61,  /* [2347] */
    (xdc_Char)0x6e,  /* [2348] */
    (xdc_Char)0x67,  /* [2349] */
    (xdc_Char)0x65,  /* [2350] */
    (xdc_Char)0x2e,  /* [2351] */
    (xdc_Char)0x0,  /* [2352] */
    (xdc_Char)0x41,  /* [2353] */
    (xdc_Char)0x5f,  /* [2354] */
    (xdc_Char)0x62,  /* [2355] */
    (xdc_Char)0x61,  /* [2356] */
    (xdc_Char)0x64,  /* [2357] */
    (xdc_Char)0x45,  /* [2358] */
    (xdc_Char)0x76,  /* [2359] */
    (xdc_Char)0x65,  /* [2360] */
    (xdc_Char)0x43,  /* [2361] */
    (xdc_Char)0x70,  /* [2362] */
    (xdc_Char)0x75,  /* [2363] */
    (xdc_Char)0x49,  /* [2364] */
    (xdc_Char)0x64,  /* [2365] */
    (xdc_Char)0x3a,  /* [2366] */
    (xdc_Char)0x20,  /* [2367] */
    (xdc_Char)0x43,  /* [2368] */
    (xdc_Char)0x50,  /* [2369] */
    (xdc_Char)0x55,  /* [2370] */
    (xdc_Char)0x20,  /* [2371] */
    (xdc_Char)0x49,  /* [2372] */
    (xdc_Char)0x64,  /* [2373] */
    (xdc_Char)0x20,  /* [2374] */
    (xdc_Char)0x6d,  /* [2375] */
    (xdc_Char)0x75,  /* [2376] */
    (xdc_Char)0x73,  /* [2377] */
    (xdc_Char)0x74,  /* [2378] */
    (xdc_Char)0x20,  /* [2379] */
    (xdc_Char)0x62,  /* [2380] */
    (xdc_Char)0x65,  /* [2381] */
    (xdc_Char)0x20,  /* [2382] */
    (xdc_Char)0x30,  /* [2383] */
    (xdc_Char)0x2c,  /* [2384] */
    (xdc_Char)0x20,  /* [2385] */
    (xdc_Char)0x31,  /* [2386] */
    (xdc_Char)0x2c,  /* [2387] */
    (xdc_Char)0x20,  /* [2388] */
    (xdc_Char)0x32,  /* [2389] */
    (xdc_Char)0x20,  /* [2390] */
    (xdc_Char)0x6f,  /* [2391] */
    (xdc_Char)0x72,  /* [2392] */
    (xdc_Char)0x20,  /* [2393] */
    (xdc_Char)0x33,  /* [2394] */
    (xdc_Char)0x0,  /* [2395] */
    (xdc_Char)0x41,  /* [2396] */
    (xdc_Char)0x5f,  /* [2397] */
    (xdc_Char)0x62,  /* [2398] */
    (xdc_Char)0x61,  /* [2399] */
    (xdc_Char)0x64,  /* [2400] */
    (xdc_Char)0x44,  /* [2401] */
    (xdc_Char)0x73,  /* [2402] */
    (xdc_Char)0x70,  /* [2403] */
    (xdc_Char)0x43,  /* [2404] */
    (xdc_Char)0x70,  /* [2405] */
    (xdc_Char)0x75,  /* [2406] */
    (xdc_Char)0x49,  /* [2407] */
    (xdc_Char)0x64,  /* [2408] */
    (xdc_Char)0x3a,  /* [2409] */
    (xdc_Char)0x20,  /* [2410] */
    (xdc_Char)0x43,  /* [2411] */
    (xdc_Char)0x50,  /* [2412] */
    (xdc_Char)0x55,  /* [2413] */
    (xdc_Char)0x20,  /* [2414] */
    (xdc_Char)0x49,  /* [2415] */
    (xdc_Char)0x64,  /* [2416] */
    (xdc_Char)0x20,  /* [2417] */
    (xdc_Char)0x6d,  /* [2418] */
    (xdc_Char)0x75,  /* [2419] */
    (xdc_Char)0x73,  /* [2420] */
    (xdc_Char)0x74,  /* [2421] */
    (xdc_Char)0x20,  /* [2422] */
    (xdc_Char)0x62,  /* [2423] */
    (xdc_Char)0x65,  /* [2424] */
    (xdc_Char)0x20,  /* [2425] */
    (xdc_Char)0x30,  /* [2426] */
    (xdc_Char)0x20,  /* [2427] */
    (xdc_Char)0x6f,  /* [2428] */
    (xdc_Char)0x72,  /* [2429] */
    (xdc_Char)0x20,  /* [2430] */
    (xdc_Char)0x31,  /* [2431] */
    (xdc_Char)0x0,  /* [2432] */
    (xdc_Char)0x41,  /* [2433] */
    (xdc_Char)0x5f,  /* [2434] */
    (xdc_Char)0x62,  /* [2435] */
    (xdc_Char)0x61,  /* [2436] */
    (xdc_Char)0x64,  /* [2437] */
    (xdc_Char)0x42,  /* [2438] */
    (xdc_Char)0x65,  /* [2439] */
    (xdc_Char)0x6e,  /* [2440] */
    (xdc_Char)0x65,  /* [2441] */
    (xdc_Char)0x6c,  /* [2442] */
    (xdc_Char)0x6c,  /* [2443] */
    (xdc_Char)0x69,  /* [2444] */
    (xdc_Char)0x49,  /* [2445] */
    (xdc_Char)0x70,  /* [2446] */
    (xdc_Char)0x75,  /* [2447] */
    (xdc_Char)0x49,  /* [2448] */
    (xdc_Char)0x64,  /* [2449] */
    (xdc_Char)0x3a,  /* [2450] */
    (xdc_Char)0x20,  /* [2451] */
    (xdc_Char)0x49,  /* [2452] */
    (xdc_Char)0x70,  /* [2453] */
    (xdc_Char)0x75,  /* [2454] */
    (xdc_Char)0x20,  /* [2455] */
    (xdc_Char)0x49,  /* [2456] */
    (xdc_Char)0x64,  /* [2457] */
    (xdc_Char)0x20,  /* [2458] */
    (xdc_Char)0x6d,  /* [2459] */
    (xdc_Char)0x75,  /* [2460] */
    (xdc_Char)0x73,  /* [2461] */
    (xdc_Char)0x74,  /* [2462] */
    (xdc_Char)0x20,  /* [2463] */
    (xdc_Char)0x62,  /* [2464] */
    (xdc_Char)0x65,  /* [2465] */
    (xdc_Char)0x20,  /* [2466] */
    (xdc_Char)0x31,  /* [2467] */
    (xdc_Char)0x20,  /* [2468] */
    (xdc_Char)0x6f,  /* [2469] */
    (xdc_Char)0x72,  /* [2470] */
    (xdc_Char)0x20,  /* [2471] */
    (xdc_Char)0x32,  /* [2472] */
    (xdc_Char)0x0,  /* [2473] */
    (xdc_Char)0x41,  /* [2474] */
    (xdc_Char)0x5f,  /* [2475] */
    (xdc_Char)0x6e,  /* [2476] */
    (xdc_Char)0x75,  /* [2477] */
    (xdc_Char)0x6c,  /* [2478] */
    (xdc_Char)0x6c,  /* [2479] */
    (xdc_Char)0x50,  /* [2480] */
    (xdc_Char)0x6f,  /* [2481] */
    (xdc_Char)0x69,  /* [2482] */
    (xdc_Char)0x6e,  /* [2483] */
    (xdc_Char)0x74,  /* [2484] */
    (xdc_Char)0x65,  /* [2485] */
    (xdc_Char)0x72,  /* [2486] */
    (xdc_Char)0x3a,  /* [2487] */
    (xdc_Char)0x20,  /* [2488] */
    (xdc_Char)0x50,  /* [2489] */
    (xdc_Char)0x6f,  /* [2490] */
    (xdc_Char)0x69,  /* [2491] */
    (xdc_Char)0x6e,  /* [2492] */
    (xdc_Char)0x74,  /* [2493] */
    (xdc_Char)0x65,  /* [2494] */
    (xdc_Char)0x72,  /* [2495] */
    (xdc_Char)0x20,  /* [2496] */
    (xdc_Char)0x69,  /* [2497] */
    (xdc_Char)0x73,  /* [2498] */
    (xdc_Char)0x20,  /* [2499] */
    (xdc_Char)0x6e,  /* [2500] */
    (xdc_Char)0x75,  /* [2501] */
    (xdc_Char)0x6c,  /* [2502] */
    (xdc_Char)0x6c,  /* [2503] */
    (xdc_Char)0x0,  /* [2504] */
    (xdc_Char)0x41,  /* [2505] */
    (xdc_Char)0x5f,  /* [2506] */
    (xdc_Char)0x75,  /* [2507] */
    (xdc_Char)0x6e,  /* [2508] */
    (xdc_Char)0x6b,  /* [2509] */
    (xdc_Char)0x6e,  /* [2510] */
    (xdc_Char)0x6f,  /* [2511] */
    (xdc_Char)0x77,  /* [2512] */
    (xdc_Char)0x6e,  /* [2513] */
    (xdc_Char)0x44,  /* [2514] */
    (xdc_Char)0x65,  /* [2515] */
    (xdc_Char)0x73,  /* [2516] */
    (xdc_Char)0x63,  /* [2517] */
    (xdc_Char)0x54,  /* [2518] */
    (xdc_Char)0x79,  /* [2519] */
    (xdc_Char)0x70,  /* [2520] */
    (xdc_Char)0x65,  /* [2521] */
    (xdc_Char)0x3a,  /* [2522] */
    (xdc_Char)0x20,  /* [2523] */
    (xdc_Char)0x44,  /* [2524] */
    (xdc_Char)0x65,  /* [2525] */
    (xdc_Char)0x73,  /* [2526] */
    (xdc_Char)0x63,  /* [2527] */
    (xdc_Char)0x72,  /* [2528] */
    (xdc_Char)0x69,  /* [2529] */
    (xdc_Char)0x70,  /* [2530] */
    (xdc_Char)0x74,  /* [2531] */
    (xdc_Char)0x6f,  /* [2532] */
    (xdc_Char)0x72,  /* [2533] */
    (xdc_Char)0x20,  /* [2534] */
    (xdc_Char)0x74,  /* [2535] */
    (xdc_Char)0x79,  /* [2536] */
    (xdc_Char)0x70,  /* [2537] */
    (xdc_Char)0x65,  /* [2538] */
    (xdc_Char)0x20,  /* [2539] */
    (xdc_Char)0x69,  /* [2540] */
    (xdc_Char)0x73,  /* [2541] */
    (xdc_Char)0x20,  /* [2542] */
    (xdc_Char)0x6e,  /* [2543] */
    (xdc_Char)0x6f,  /* [2544] */
    (xdc_Char)0x74,  /* [2545] */
    (xdc_Char)0x20,  /* [2546] */
    (xdc_Char)0x72,  /* [2547] */
    (xdc_Char)0x65,  /* [2548] */
    (xdc_Char)0x63,  /* [2549] */
    (xdc_Char)0x6f,  /* [2550] */
    (xdc_Char)0x67,  /* [2551] */
    (xdc_Char)0x6e,  /* [2552] */
    (xdc_Char)0x69,  /* [2553] */
    (xdc_Char)0x7a,  /* [2554] */
    (xdc_Char)0x65,  /* [2555] */
    (xdc_Char)0x64,  /* [2556] */
    (xdc_Char)0x0,  /* [2557] */
    (xdc_Char)0x41,  /* [2558] */
    (xdc_Char)0x5f,  /* [2559] */
    (xdc_Char)0x62,  /* [2560] */
    (xdc_Char)0x61,  /* [2561] */
    (xdc_Char)0x73,  /* [2562] */
    (xdc_Char)0x65,  /* [2563] */
    (xdc_Char)0x56,  /* [2564] */
    (xdc_Char)0x61,  /* [2565] */
    (xdc_Char)0x6c,  /* [2566] */
    (xdc_Char)0x75,  /* [2567] */
    (xdc_Char)0x65,  /* [2568] */
    (xdc_Char)0x4f,  /* [2569] */
    (xdc_Char)0x75,  /* [2570] */
    (xdc_Char)0x74,  /* [2571] */
    (xdc_Char)0x4f,  /* [2572] */
    (xdc_Char)0x66,  /* [2573] */
    (xdc_Char)0x52,  /* [2574] */
    (xdc_Char)0x61,  /* [2575] */
    (xdc_Char)0x6e,  /* [2576] */
    (xdc_Char)0x67,  /* [2577] */
    (xdc_Char)0x65,  /* [2578] */
    (xdc_Char)0x3a,  /* [2579] */
    (xdc_Char)0x20,  /* [2580] */
    (xdc_Char)0x54,  /* [2581] */
    (xdc_Char)0x4c,  /* [2582] */
    (xdc_Char)0x42,  /* [2583] */
    (xdc_Char)0x20,  /* [2584] */
    (xdc_Char)0x6c,  /* [2585] */
    (xdc_Char)0x6f,  /* [2586] */
    (xdc_Char)0x63,  /* [2587] */
    (xdc_Char)0x6b,  /* [2588] */
    (xdc_Char)0x20,  /* [2589] */
    (xdc_Char)0x65,  /* [2590] */
    (xdc_Char)0x6e,  /* [2591] */
    (xdc_Char)0x74,  /* [2592] */
    (xdc_Char)0x72,  /* [2593] */
    (xdc_Char)0x69,  /* [2594] */
    (xdc_Char)0x65,  /* [2595] */
    (xdc_Char)0x73,  /* [2596] */
    (xdc_Char)0x20,  /* [2597] */
    (xdc_Char)0x62,  /* [2598] */
    (xdc_Char)0x61,  /* [2599] */
    (xdc_Char)0x73,  /* [2600] */
    (xdc_Char)0x65,  /* [2601] */
    (xdc_Char)0x20,  /* [2602] */
    (xdc_Char)0x76,  /* [2603] */
    (xdc_Char)0x61,  /* [2604] */
    (xdc_Char)0x6c,  /* [2605] */
    (xdc_Char)0x75,  /* [2606] */
    (xdc_Char)0x65,  /* [2607] */
    (xdc_Char)0x20,  /* [2608] */
    (xdc_Char)0x6f,  /* [2609] */
    (xdc_Char)0x75,  /* [2610] */
    (xdc_Char)0x74,  /* [2611] */
    (xdc_Char)0x20,  /* [2612] */
    (xdc_Char)0x6f,  /* [2613] */
    (xdc_Char)0x66,  /* [2614] */
    (xdc_Char)0x20,  /* [2615] */
    (xdc_Char)0x72,  /* [2616] */
    (xdc_Char)0x61,  /* [2617] */
    (xdc_Char)0x6e,  /* [2618] */
    (xdc_Char)0x67,  /* [2619] */
    (xdc_Char)0x65,  /* [2620] */
    (xdc_Char)0x0,  /* [2621] */
    (xdc_Char)0x41,  /* [2622] */
    (xdc_Char)0x5f,  /* [2623] */
    (xdc_Char)0x6e,  /* [2624] */
    (xdc_Char)0x6f,  /* [2625] */
    (xdc_Char)0x74,  /* [2626] */
    (xdc_Char)0x41,  /* [2627] */
    (xdc_Char)0x76,  /* [2628] */
    (xdc_Char)0x61,  /* [2629] */
    (xdc_Char)0x69,  /* [2630] */
    (xdc_Char)0x6c,  /* [2631] */
    (xdc_Char)0x61,  /* [2632] */
    (xdc_Char)0x62,  /* [2633] */
    (xdc_Char)0x6c,  /* [2634] */
    (xdc_Char)0x65,  /* [2635] */
    (xdc_Char)0x3a,  /* [2636] */
    (xdc_Char)0x20,  /* [2637] */
    (xdc_Char)0x73,  /* [2638] */
    (xdc_Char)0x74,  /* [2639] */
    (xdc_Char)0x61,  /* [2640] */
    (xdc_Char)0x74,  /* [2641] */
    (xdc_Char)0x69,  /* [2642] */
    (xdc_Char)0x63,  /* [2643] */
    (xdc_Char)0x61,  /* [2644] */
    (xdc_Char)0x6c,  /* [2645] */
    (xdc_Char)0x6c,  /* [2646] */
    (xdc_Char)0x79,  /* [2647] */
    (xdc_Char)0x20,  /* [2648] */
    (xdc_Char)0x63,  /* [2649] */
    (xdc_Char)0x72,  /* [2650] */
    (xdc_Char)0x65,  /* [2651] */
    (xdc_Char)0x61,  /* [2652] */
    (xdc_Char)0x74,  /* [2653] */
    (xdc_Char)0x65,  /* [2654] */
    (xdc_Char)0x64,  /* [2655] */
    (xdc_Char)0x20,  /* [2656] */
    (xdc_Char)0x74,  /* [2657] */
    (xdc_Char)0x69,  /* [2658] */
    (xdc_Char)0x6d,  /* [2659] */
    (xdc_Char)0x65,  /* [2660] */
    (xdc_Char)0x72,  /* [2661] */
    (xdc_Char)0x20,  /* [2662] */
    (xdc_Char)0x6e,  /* [2663] */
    (xdc_Char)0x6f,  /* [2664] */
    (xdc_Char)0x74,  /* [2665] */
    (xdc_Char)0x20,  /* [2666] */
    (xdc_Char)0x61,  /* [2667] */
    (xdc_Char)0x76,  /* [2668] */
    (xdc_Char)0x61,  /* [2669] */
    (xdc_Char)0x69,  /* [2670] */
    (xdc_Char)0x6c,  /* [2671] */
    (xdc_Char)0x61,  /* [2672] */
    (xdc_Char)0x62,  /* [2673] */
    (xdc_Char)0x6c,  /* [2674] */
    (xdc_Char)0x65,  /* [2675] */
    (xdc_Char)0x0,  /* [2676] */
    (xdc_Char)0x41,  /* [2677] */
    (xdc_Char)0x5f,  /* [2678] */
    (xdc_Char)0x7a,  /* [2679] */
    (xdc_Char)0x65,  /* [2680] */
    (xdc_Char)0x72,  /* [2681] */
    (xdc_Char)0x6f,  /* [2682] */
    (xdc_Char)0x54,  /* [2683] */
    (xdc_Char)0x69,  /* [2684] */
    (xdc_Char)0x6d,  /* [2685] */
    (xdc_Char)0x65,  /* [2686] */
    (xdc_Char)0x6f,  /* [2687] */
    (xdc_Char)0x75,  /* [2688] */
    (xdc_Char)0x74,  /* [2689] */
    (xdc_Char)0x3a,  /* [2690] */
    (xdc_Char)0x20,  /* [2691] */
    (xdc_Char)0x54,  /* [2692] */
    (xdc_Char)0x69,  /* [2693] */
    (xdc_Char)0x6d,  /* [2694] */
    (xdc_Char)0x65,  /* [2695] */
    (xdc_Char)0x6f,  /* [2696] */
    (xdc_Char)0x75,  /* [2697] */
    (xdc_Char)0x74,  /* [2698] */
    (xdc_Char)0x20,  /* [2699] */
    (xdc_Char)0x76,  /* [2700] */
    (xdc_Char)0x61,  /* [2701] */
    (xdc_Char)0x6c,  /* [2702] */
    (xdc_Char)0x75,  /* [2703] */
    (xdc_Char)0x65,  /* [2704] */
    (xdc_Char)0x20,  /* [2705] */
    (xdc_Char)0x61,  /* [2706] */
    (xdc_Char)0x6e,  /* [2707] */
    (xdc_Char)0x6e,  /* [2708] */
    (xdc_Char)0x6f,  /* [2709] */
    (xdc_Char)0x74,  /* [2710] */
    (xdc_Char)0x20,  /* [2711] */
    (xdc_Char)0x62,  /* [2712] */
    (xdc_Char)0x65,  /* [2713] */
    (xdc_Char)0x20,  /* [2714] */
    (xdc_Char)0x7a,  /* [2715] */
    (xdc_Char)0x65,  /* [2716] */
    (xdc_Char)0x72,  /* [2717] */
    (xdc_Char)0x6f,  /* [2718] */
    (xdc_Char)0x0,  /* [2719] */
    (xdc_Char)0x41,  /* [2720] */
    (xdc_Char)0x5f,  /* [2721] */
    (xdc_Char)0x69,  /* [2722] */
    (xdc_Char)0x6e,  /* [2723] */
    (xdc_Char)0x76,  /* [2724] */
    (xdc_Char)0x61,  /* [2725] */
    (xdc_Char)0x6c,  /* [2726] */
    (xdc_Char)0x69,  /* [2727] */
    (xdc_Char)0x64,  /* [2728] */
    (xdc_Char)0x4b,  /* [2729] */
    (xdc_Char)0x65,  /* [2730] */
    (xdc_Char)0x79,  /* [2731] */
    (xdc_Char)0x3a,  /* [2732] */
    (xdc_Char)0x20,  /* [2733] */
    (xdc_Char)0x74,  /* [2734] */
    (xdc_Char)0x68,  /* [2735] */
    (xdc_Char)0x65,  /* [2736] */
    (xdc_Char)0x20,  /* [2737] */
    (xdc_Char)0x6b,  /* [2738] */
    (xdc_Char)0x65,  /* [2739] */
    (xdc_Char)0x79,  /* [2740] */
    (xdc_Char)0x20,  /* [2741] */
    (xdc_Char)0x6d,  /* [2742] */
    (xdc_Char)0x75,  /* [2743] */
    (xdc_Char)0x73,  /* [2744] */
    (xdc_Char)0x74,  /* [2745] */
    (xdc_Char)0x20,  /* [2746] */
    (xdc_Char)0x62,  /* [2747] */
    (xdc_Char)0x65,  /* [2748] */
    (xdc_Char)0x20,  /* [2749] */
    (xdc_Char)0x73,  /* [2750] */
    (xdc_Char)0x65,  /* [2751] */
    (xdc_Char)0x74,  /* [2752] */
    (xdc_Char)0x20,  /* [2753] */
    (xdc_Char)0x74,  /* [2754] */
    (xdc_Char)0x6f,  /* [2755] */
    (xdc_Char)0x20,  /* [2756] */
    (xdc_Char)0x61,  /* [2757] */
    (xdc_Char)0x20,  /* [2758] */
    (xdc_Char)0x6e,  /* [2759] */
    (xdc_Char)0x6f,  /* [2760] */
    (xdc_Char)0x6e,  /* [2761] */
    (xdc_Char)0x2d,  /* [2762] */
    (xdc_Char)0x64,  /* [2763] */
    (xdc_Char)0x65,  /* [2764] */
    (xdc_Char)0x66,  /* [2765] */
    (xdc_Char)0x61,  /* [2766] */
    (xdc_Char)0x75,  /* [2767] */
    (xdc_Char)0x6c,  /* [2768] */
    (xdc_Char)0x74,  /* [2769] */
    (xdc_Char)0x20,  /* [2770] */
    (xdc_Char)0x76,  /* [2771] */
    (xdc_Char)0x61,  /* [2772] */
    (xdc_Char)0x6c,  /* [2773] */
    (xdc_Char)0x75,  /* [2774] */
    (xdc_Char)0x65,  /* [2775] */
    (xdc_Char)0x0,  /* [2776] */
    (xdc_Char)0x41,  /* [2777] */
    (xdc_Char)0x5f,  /* [2778] */
    (xdc_Char)0x62,  /* [2779] */
    (xdc_Char)0x61,  /* [2780] */
    (xdc_Char)0x64,  /* [2781] */
    (xdc_Char)0x43,  /* [2782] */
    (xdc_Char)0x6f,  /* [2783] */
    (xdc_Char)0x6e,  /* [2784] */
    (xdc_Char)0x74,  /* [2785] */
    (xdc_Char)0x65,  /* [2786] */
    (xdc_Char)0x78,  /* [2787] */
    (xdc_Char)0x74,  /* [2788] */
    (xdc_Char)0x3a,  /* [2789] */
    (xdc_Char)0x20,  /* [2790] */
    (xdc_Char)0x62,  /* [2791] */
    (xdc_Char)0x61,  /* [2792] */
    (xdc_Char)0x64,  /* [2793] */
    (xdc_Char)0x20,  /* [2794] */
    (xdc_Char)0x63,  /* [2795] */
    (xdc_Char)0x61,  /* [2796] */
    (xdc_Char)0x6c,  /* [2797] */
    (xdc_Char)0x6c,  /* [2798] */
    (xdc_Char)0x69,  /* [2799] */
    (xdc_Char)0x6e,  /* [2800] */
    (xdc_Char)0x67,  /* [2801] */
    (xdc_Char)0x20,  /* [2802] */
    (xdc_Char)0x63,  /* [2803] */
    (xdc_Char)0x6f,  /* [2804] */
    (xdc_Char)0x6e,  /* [2805] */
    (xdc_Char)0x74,  /* [2806] */
    (xdc_Char)0x65,  /* [2807] */
    (xdc_Char)0x78,  /* [2808] */
    (xdc_Char)0x74,  /* [2809] */
    (xdc_Char)0x2e,  /* [2810] */
    (xdc_Char)0x20,  /* [2811] */
    (xdc_Char)0x4d,  /* [2812] */
    (xdc_Char)0x61,  /* [2813] */
    (xdc_Char)0x79,  /* [2814] */
    (xdc_Char)0x20,  /* [2815] */
    (xdc_Char)0x6e,  /* [2816] */
    (xdc_Char)0x6f,  /* [2817] */
    (xdc_Char)0x74,  /* [2818] */
    (xdc_Char)0x20,  /* [2819] */
    (xdc_Char)0x62,  /* [2820] */
    (xdc_Char)0x65,  /* [2821] */
    (xdc_Char)0x20,  /* [2822] */
    (xdc_Char)0x65,  /* [2823] */
    (xdc_Char)0x6e,  /* [2824] */
    (xdc_Char)0x74,  /* [2825] */
    (xdc_Char)0x65,  /* [2826] */
    (xdc_Char)0x72,  /* [2827] */
    (xdc_Char)0x65,  /* [2828] */
    (xdc_Char)0x64,  /* [2829] */
    (xdc_Char)0x20,  /* [2830] */
    (xdc_Char)0x66,  /* [2831] */
    (xdc_Char)0x72,  /* [2832] */
    (xdc_Char)0x6f,  /* [2833] */
    (xdc_Char)0x6d,  /* [2834] */
    (xdc_Char)0x20,  /* [2835] */
    (xdc_Char)0x61,  /* [2836] */
    (xdc_Char)0x20,  /* [2837] */
    (xdc_Char)0x68,  /* [2838] */
    (xdc_Char)0x61,  /* [2839] */
    (xdc_Char)0x72,  /* [2840] */
    (xdc_Char)0x64,  /* [2841] */
    (xdc_Char)0x77,  /* [2842] */
    (xdc_Char)0x61,  /* [2843] */
    (xdc_Char)0x72,  /* [2844] */
    (xdc_Char)0x65,  /* [2845] */
    (xdc_Char)0x20,  /* [2846] */
    (xdc_Char)0x69,  /* [2847] */
    (xdc_Char)0x6e,  /* [2848] */
    (xdc_Char)0x74,  /* [2849] */
    (xdc_Char)0x65,  /* [2850] */
    (xdc_Char)0x72,  /* [2851] */
    (xdc_Char)0x72,  /* [2852] */
    (xdc_Char)0x75,  /* [2853] */
    (xdc_Char)0x70,  /* [2854] */
    (xdc_Char)0x74,  /* [2855] */
    (xdc_Char)0x20,  /* [2856] */
    (xdc_Char)0x74,  /* [2857] */
    (xdc_Char)0x68,  /* [2858] */
    (xdc_Char)0x72,  /* [2859] */
    (xdc_Char)0x65,  /* [2860] */
    (xdc_Char)0x61,  /* [2861] */
    (xdc_Char)0x64,  /* [2862] */
    (xdc_Char)0x2e,  /* [2863] */
    (xdc_Char)0x0,  /* [2864] */
    (xdc_Char)0x41,  /* [2865] */
    (xdc_Char)0x5f,  /* [2866] */
    (xdc_Char)0x62,  /* [2867] */
    (xdc_Char)0x61,  /* [2868] */
    (xdc_Char)0x64,  /* [2869] */
    (xdc_Char)0x43,  /* [2870] */
    (xdc_Char)0x6f,  /* [2871] */
    (xdc_Char)0x6e,  /* [2872] */
    (xdc_Char)0x74,  /* [2873] */
    (xdc_Char)0x65,  /* [2874] */
    (xdc_Char)0x78,  /* [2875] */
    (xdc_Char)0x74,  /* [2876] */
    (xdc_Char)0x3a,  /* [2877] */
    (xdc_Char)0x20,  /* [2878] */
    (xdc_Char)0x62,  /* [2879] */
    (xdc_Char)0x61,  /* [2880] */
    (xdc_Char)0x64,  /* [2881] */
    (xdc_Char)0x20,  /* [2882] */
    (xdc_Char)0x63,  /* [2883] */
    (xdc_Char)0x61,  /* [2884] */
    (xdc_Char)0x6c,  /* [2885] */
    (xdc_Char)0x6c,  /* [2886] */
    (xdc_Char)0x69,  /* [2887] */
    (xdc_Char)0x6e,  /* [2888] */
    (xdc_Char)0x67,  /* [2889] */
    (xdc_Char)0x20,  /* [2890] */
    (xdc_Char)0x63,  /* [2891] */
    (xdc_Char)0x6f,  /* [2892] */
    (xdc_Char)0x6e,  /* [2893] */
    (xdc_Char)0x74,  /* [2894] */
    (xdc_Char)0x65,  /* [2895] */
    (xdc_Char)0x78,  /* [2896] */
    (xdc_Char)0x74,  /* [2897] */
    (xdc_Char)0x2e,  /* [2898] */
    (xdc_Char)0x20,  /* [2899] */
    (xdc_Char)0x4d,  /* [2900] */
    (xdc_Char)0x61,  /* [2901] */
    (xdc_Char)0x79,  /* [2902] */
    (xdc_Char)0x20,  /* [2903] */
    (xdc_Char)0x6e,  /* [2904] */
    (xdc_Char)0x6f,  /* [2905] */
    (xdc_Char)0x74,  /* [2906] */
    (xdc_Char)0x20,  /* [2907] */
    (xdc_Char)0x62,  /* [2908] */
    (xdc_Char)0x65,  /* [2909] */
    (xdc_Char)0x20,  /* [2910] */
    (xdc_Char)0x65,  /* [2911] */
    (xdc_Char)0x6e,  /* [2912] */
    (xdc_Char)0x74,  /* [2913] */
    (xdc_Char)0x65,  /* [2914] */
    (xdc_Char)0x72,  /* [2915] */
    (xdc_Char)0x65,  /* [2916] */
    (xdc_Char)0x64,  /* [2917] */
    (xdc_Char)0x20,  /* [2918] */
    (xdc_Char)0x66,  /* [2919] */
    (xdc_Char)0x72,  /* [2920] */
    (xdc_Char)0x6f,  /* [2921] */
    (xdc_Char)0x6d,  /* [2922] */
    (xdc_Char)0x20,  /* [2923] */
    (xdc_Char)0x61,  /* [2924] */
    (xdc_Char)0x20,  /* [2925] */
    (xdc_Char)0x73,  /* [2926] */
    (xdc_Char)0x6f,  /* [2927] */
    (xdc_Char)0x66,  /* [2928] */
    (xdc_Char)0x74,  /* [2929] */
    (xdc_Char)0x77,  /* [2930] */
    (xdc_Char)0x61,  /* [2931] */
    (xdc_Char)0x72,  /* [2932] */
    (xdc_Char)0x65,  /* [2933] */
    (xdc_Char)0x20,  /* [2934] */
    (xdc_Char)0x6f,  /* [2935] */
    (xdc_Char)0x72,  /* [2936] */
    (xdc_Char)0x20,  /* [2937] */
    (xdc_Char)0x68,  /* [2938] */
    (xdc_Char)0x61,  /* [2939] */
    (xdc_Char)0x72,  /* [2940] */
    (xdc_Char)0x64,  /* [2941] */
    (xdc_Char)0x77,  /* [2942] */
    (xdc_Char)0x61,  /* [2943] */
    (xdc_Char)0x72,  /* [2944] */
    (xdc_Char)0x65,  /* [2945] */
    (xdc_Char)0x20,  /* [2946] */
    (xdc_Char)0x69,  /* [2947] */
    (xdc_Char)0x6e,  /* [2948] */
    (xdc_Char)0x74,  /* [2949] */
    (xdc_Char)0x65,  /* [2950] */
    (xdc_Char)0x72,  /* [2951] */
    (xdc_Char)0x72,  /* [2952] */
    (xdc_Char)0x75,  /* [2953] */
    (xdc_Char)0x70,  /* [2954] */
    (xdc_Char)0x74,  /* [2955] */
    (xdc_Char)0x20,  /* [2956] */
    (xdc_Char)0x74,  /* [2957] */
    (xdc_Char)0x68,  /* [2958] */
    (xdc_Char)0x72,  /* [2959] */
    (xdc_Char)0x65,  /* [2960] */
    (xdc_Char)0x61,  /* [2961] */
    (xdc_Char)0x64,  /* [2962] */
    (xdc_Char)0x2e,  /* [2963] */
    (xdc_Char)0x0,  /* [2964] */
    (xdc_Char)0x41,  /* [2965] */
    (xdc_Char)0x5f,  /* [2966] */
    (xdc_Char)0x62,  /* [2967] */
    (xdc_Char)0x61,  /* [2968] */
    (xdc_Char)0x64,  /* [2969] */
    (xdc_Char)0x43,  /* [2970] */
    (xdc_Char)0x6f,  /* [2971] */
    (xdc_Char)0x6e,  /* [2972] */
    (xdc_Char)0x74,  /* [2973] */
    (xdc_Char)0x65,  /* [2974] */
    (xdc_Char)0x78,  /* [2975] */
    (xdc_Char)0x74,  /* [2976] */
    (xdc_Char)0x3a,  /* [2977] */
    (xdc_Char)0x20,  /* [2978] */
    (xdc_Char)0x62,  /* [2979] */
    (xdc_Char)0x61,  /* [2980] */
    (xdc_Char)0x64,  /* [2981] */
    (xdc_Char)0x20,  /* [2982] */
    (xdc_Char)0x63,  /* [2983] */
    (xdc_Char)0x61,  /* [2984] */
    (xdc_Char)0x6c,  /* [2985] */
    (xdc_Char)0x6c,  /* [2986] */
    (xdc_Char)0x69,  /* [2987] */
    (xdc_Char)0x6e,  /* [2988] */
    (xdc_Char)0x67,  /* [2989] */
    (xdc_Char)0x20,  /* [2990] */
    (xdc_Char)0x63,  /* [2991] */
    (xdc_Char)0x6f,  /* [2992] */
    (xdc_Char)0x6e,  /* [2993] */
    (xdc_Char)0x74,  /* [2994] */
    (xdc_Char)0x65,  /* [2995] */
    (xdc_Char)0x78,  /* [2996] */
    (xdc_Char)0x74,  /* [2997] */
    (xdc_Char)0x2e,  /* [2998] */
    (xdc_Char)0x20,  /* [2999] */
    (xdc_Char)0x53,  /* [3000] */
    (xdc_Char)0x65,  /* [3001] */
    (xdc_Char)0x65,  /* [3002] */
    (xdc_Char)0x20,  /* [3003] */
    (xdc_Char)0x47,  /* [3004] */
    (xdc_Char)0x61,  /* [3005] */
    (xdc_Char)0x74,  /* [3006] */
    (xdc_Char)0x65,  /* [3007] */
    (xdc_Char)0x4d,  /* [3008] */
    (xdc_Char)0x75,  /* [3009] */
    (xdc_Char)0x74,  /* [3010] */
    (xdc_Char)0x65,  /* [3011] */
    (xdc_Char)0x78,  /* [3012] */
    (xdc_Char)0x50,  /* [3013] */
    (xdc_Char)0x72,  /* [3014] */
    (xdc_Char)0x69,  /* [3015] */
    (xdc_Char)0x20,  /* [3016] */
    (xdc_Char)0x41,  /* [3017] */
    (xdc_Char)0x50,  /* [3018] */
    (xdc_Char)0x49,  /* [3019] */
    (xdc_Char)0x20,  /* [3020] */
    (xdc_Char)0x64,  /* [3021] */
    (xdc_Char)0x6f,  /* [3022] */
    (xdc_Char)0x63,  /* [3023] */
    (xdc_Char)0x20,  /* [3024] */
    (xdc_Char)0x66,  /* [3025] */
    (xdc_Char)0x6f,  /* [3026] */
    (xdc_Char)0x72,  /* [3027] */
    (xdc_Char)0x20,  /* [3028] */
    (xdc_Char)0x64,  /* [3029] */
    (xdc_Char)0x65,  /* [3030] */
    (xdc_Char)0x74,  /* [3031] */
    (xdc_Char)0x61,  /* [3032] */
    (xdc_Char)0x69,  /* [3033] */
    (xdc_Char)0x6c,  /* [3034] */
    (xdc_Char)0x73,  /* [3035] */
    (xdc_Char)0x2e,  /* [3036] */
    (xdc_Char)0x0,  /* [3037] */
    (xdc_Char)0x41,  /* [3038] */
    (xdc_Char)0x5f,  /* [3039] */
    (xdc_Char)0x65,  /* [3040] */
    (xdc_Char)0x6e,  /* [3041] */
    (xdc_Char)0x74,  /* [3042] */
    (xdc_Char)0x65,  /* [3043] */
    (xdc_Char)0x72,  /* [3044] */
    (xdc_Char)0x54,  /* [3045] */
    (xdc_Char)0x61,  /* [3046] */
    (xdc_Char)0x73,  /* [3047] */
    (xdc_Char)0x6b,  /* [3048] */
    (xdc_Char)0x44,  /* [3049] */
    (xdc_Char)0x69,  /* [3050] */
    (xdc_Char)0x73,  /* [3051] */
    (xdc_Char)0x61,  /* [3052] */
    (xdc_Char)0x62,  /* [3053] */
    (xdc_Char)0x6c,  /* [3054] */
    (xdc_Char)0x65,  /* [3055] */
    (xdc_Char)0x64,  /* [3056] */
    (xdc_Char)0x3a,  /* [3057] */
    (xdc_Char)0x20,  /* [3058] */
    (xdc_Char)0x43,  /* [3059] */
    (xdc_Char)0x61,  /* [3060] */
    (xdc_Char)0x6e,  /* [3061] */
    (xdc_Char)0x6e,  /* [3062] */
    (xdc_Char)0x6f,  /* [3063] */
    (xdc_Char)0x74,  /* [3064] */
    (xdc_Char)0x20,  /* [3065] */
    (xdc_Char)0x63,  /* [3066] */
    (xdc_Char)0x61,  /* [3067] */
    (xdc_Char)0x6c,  /* [3068] */
    (xdc_Char)0x6c,  /* [3069] */
    (xdc_Char)0x20,  /* [3070] */
    (xdc_Char)0x47,  /* [3071] */
    (xdc_Char)0x61,  /* [3072] */
    (xdc_Char)0x74,  /* [3073] */
    (xdc_Char)0x65,  /* [3074] */
    (xdc_Char)0x4d,  /* [3075] */
    (xdc_Char)0x75,  /* [3076] */
    (xdc_Char)0x74,  /* [3077] */
    (xdc_Char)0x65,  /* [3078] */
    (xdc_Char)0x78,  /* [3079] */
    (xdc_Char)0x50,  /* [3080] */
    (xdc_Char)0x72,  /* [3081] */
    (xdc_Char)0x69,  /* [3082] */
    (xdc_Char)0x5f,  /* [3083] */
    (xdc_Char)0x65,  /* [3084] */
    (xdc_Char)0x6e,  /* [3085] */
    (xdc_Char)0x74,  /* [3086] */
    (xdc_Char)0x65,  /* [3087] */
    (xdc_Char)0x72,  /* [3088] */
    (xdc_Char)0x28,  /* [3089] */
    (xdc_Char)0x29,  /* [3090] */
    (xdc_Char)0x20,  /* [3091] */
    (xdc_Char)0x77,  /* [3092] */
    (xdc_Char)0x68,  /* [3093] */
    (xdc_Char)0x69,  /* [3094] */
    (xdc_Char)0x6c,  /* [3095] */
    (xdc_Char)0x65,  /* [3096] */
    (xdc_Char)0x20,  /* [3097] */
    (xdc_Char)0x74,  /* [3098] */
    (xdc_Char)0x68,  /* [3099] */
    (xdc_Char)0x65,  /* [3100] */
    (xdc_Char)0x20,  /* [3101] */
    (xdc_Char)0x54,  /* [3102] */
    (xdc_Char)0x61,  /* [3103] */
    (xdc_Char)0x73,  /* [3104] */
    (xdc_Char)0x6b,  /* [3105] */
    (xdc_Char)0x20,  /* [3106] */
    (xdc_Char)0x6f,  /* [3107] */
    (xdc_Char)0x72,  /* [3108] */
    (xdc_Char)0x20,  /* [3109] */
    (xdc_Char)0x53,  /* [3110] */
    (xdc_Char)0x77,  /* [3111] */
    (xdc_Char)0x69,  /* [3112] */
    (xdc_Char)0x20,  /* [3113] */
    (xdc_Char)0x73,  /* [3114] */
    (xdc_Char)0x63,  /* [3115] */
    (xdc_Char)0x68,  /* [3116] */
    (xdc_Char)0x65,  /* [3117] */
    (xdc_Char)0x64,  /* [3118] */
    (xdc_Char)0x75,  /* [3119] */
    (xdc_Char)0x6c,  /* [3120] */
    (xdc_Char)0x65,  /* [3121] */
    (xdc_Char)0x72,  /* [3122] */
    (xdc_Char)0x20,  /* [3123] */
    (xdc_Char)0x69,  /* [3124] */
    (xdc_Char)0x73,  /* [3125] */
    (xdc_Char)0x20,  /* [3126] */
    (xdc_Char)0x64,  /* [3127] */
    (xdc_Char)0x69,  /* [3128] */
    (xdc_Char)0x73,  /* [3129] */
    (xdc_Char)0x61,  /* [3130] */
    (xdc_Char)0x62,  /* [3131] */
    (xdc_Char)0x6c,  /* [3132] */
    (xdc_Char)0x65,  /* [3133] */
    (xdc_Char)0x64,  /* [3134] */
    (xdc_Char)0x2e,  /* [3135] */
    (xdc_Char)0x0,  /* [3136] */
    (xdc_Char)0x41,  /* [3137] */
    (xdc_Char)0x5f,  /* [3138] */
    (xdc_Char)0x62,  /* [3139] */
    (xdc_Char)0x61,  /* [3140] */
    (xdc_Char)0x64,  /* [3141] */
    (xdc_Char)0x43,  /* [3142] */
    (xdc_Char)0x6f,  /* [3143] */
    (xdc_Char)0x6e,  /* [3144] */
    (xdc_Char)0x74,  /* [3145] */
    (xdc_Char)0x65,  /* [3146] */
    (xdc_Char)0x78,  /* [3147] */
    (xdc_Char)0x74,  /* [3148] */
    (xdc_Char)0x3a,  /* [3149] */
    (xdc_Char)0x20,  /* [3150] */
    (xdc_Char)0x62,  /* [3151] */
    (xdc_Char)0x61,  /* [3152] */
    (xdc_Char)0x64,  /* [3153] */
    (xdc_Char)0x20,  /* [3154] */
    (xdc_Char)0x63,  /* [3155] */
    (xdc_Char)0x61,  /* [3156] */
    (xdc_Char)0x6c,  /* [3157] */
    (xdc_Char)0x6c,  /* [3158] */
    (xdc_Char)0x69,  /* [3159] */
    (xdc_Char)0x6e,  /* [3160] */
    (xdc_Char)0x67,  /* [3161] */
    (xdc_Char)0x20,  /* [3162] */
    (xdc_Char)0x63,  /* [3163] */
    (xdc_Char)0x6f,  /* [3164] */
    (xdc_Char)0x6e,  /* [3165] */
    (xdc_Char)0x74,  /* [3166] */
    (xdc_Char)0x65,  /* [3167] */
    (xdc_Char)0x78,  /* [3168] */
    (xdc_Char)0x74,  /* [3169] */
    (xdc_Char)0x2e,  /* [3170] */
    (xdc_Char)0x20,  /* [3171] */
    (xdc_Char)0x53,  /* [3172] */
    (xdc_Char)0x65,  /* [3173] */
    (xdc_Char)0x65,  /* [3174] */
    (xdc_Char)0x20,  /* [3175] */
    (xdc_Char)0x47,  /* [3176] */
    (xdc_Char)0x61,  /* [3177] */
    (xdc_Char)0x74,  /* [3178] */
    (xdc_Char)0x65,  /* [3179] */
    (xdc_Char)0x4d,  /* [3180] */
    (xdc_Char)0x75,  /* [3181] */
    (xdc_Char)0x74,  /* [3182] */
    (xdc_Char)0x65,  /* [3183] */
    (xdc_Char)0x78,  /* [3184] */
    (xdc_Char)0x20,  /* [3185] */
    (xdc_Char)0x41,  /* [3186] */
    (xdc_Char)0x50,  /* [3187] */
    (xdc_Char)0x49,  /* [3188] */
    (xdc_Char)0x20,  /* [3189] */
    (xdc_Char)0x64,  /* [3190] */
    (xdc_Char)0x6f,  /* [3191] */
    (xdc_Char)0x63,  /* [3192] */
    (xdc_Char)0x20,  /* [3193] */
    (xdc_Char)0x66,  /* [3194] */
    (xdc_Char)0x6f,  /* [3195] */
    (xdc_Char)0x72,  /* [3196] */
    (xdc_Char)0x20,  /* [3197] */
    (xdc_Char)0x64,  /* [3198] */
    (xdc_Char)0x65,  /* [3199] */
    (xdc_Char)0x74,  /* [3200] */
    (xdc_Char)0x61,  /* [3201] */
    (xdc_Char)0x69,  /* [3202] */
    (xdc_Char)0x6c,  /* [3203] */
    (xdc_Char)0x73,  /* [3204] */
    (xdc_Char)0x2e,  /* [3205] */
    (xdc_Char)0x0,  /* [3206] */
    (xdc_Char)0x41,  /* [3207] */
    (xdc_Char)0x5f,  /* [3208] */
    (xdc_Char)0x62,  /* [3209] */
    (xdc_Char)0x61,  /* [3210] */
    (xdc_Char)0x64,  /* [3211] */
    (xdc_Char)0x43,  /* [3212] */
    (xdc_Char)0x6f,  /* [3213] */
    (xdc_Char)0x6e,  /* [3214] */
    (xdc_Char)0x74,  /* [3215] */
    (xdc_Char)0x65,  /* [3216] */
    (xdc_Char)0x78,  /* [3217] */
    (xdc_Char)0x74,  /* [3218] */
    (xdc_Char)0x3a,  /* [3219] */
    (xdc_Char)0x20,  /* [3220] */
    (xdc_Char)0x62,  /* [3221] */
    (xdc_Char)0x61,  /* [3222] */
    (xdc_Char)0x64,  /* [3223] */
    (xdc_Char)0x20,  /* [3224] */
    (xdc_Char)0x63,  /* [3225] */
    (xdc_Char)0x61,  /* [3226] */
    (xdc_Char)0x6c,  /* [3227] */
    (xdc_Char)0x6c,  /* [3228] */
    (xdc_Char)0x69,  /* [3229] */
    (xdc_Char)0x6e,  /* [3230] */
    (xdc_Char)0x67,  /* [3231] */
    (xdc_Char)0x20,  /* [3232] */
    (xdc_Char)0x63,  /* [3233] */
    (xdc_Char)0x6f,  /* [3234] */
    (xdc_Char)0x6e,  /* [3235] */
    (xdc_Char)0x74,  /* [3236] */
    (xdc_Char)0x65,  /* [3237] */
    (xdc_Char)0x78,  /* [3238] */
    (xdc_Char)0x74,  /* [3239] */
    (xdc_Char)0x2e,  /* [3240] */
    (xdc_Char)0x20,  /* [3241] */
    (xdc_Char)0x53,  /* [3242] */
    (xdc_Char)0x65,  /* [3243] */
    (xdc_Char)0x65,  /* [3244] */
    (xdc_Char)0x20,  /* [3245] */
    (xdc_Char)0x47,  /* [3246] */
    (xdc_Char)0x61,  /* [3247] */
    (xdc_Char)0x74,  /* [3248] */
    (xdc_Char)0x65,  /* [3249] */
    (xdc_Char)0x53,  /* [3250] */
    (xdc_Char)0x70,  /* [3251] */
    (xdc_Char)0x69,  /* [3252] */
    (xdc_Char)0x6e,  /* [3253] */
    (xdc_Char)0x6c,  /* [3254] */
    (xdc_Char)0x6f,  /* [3255] */
    (xdc_Char)0x63,  /* [3256] */
    (xdc_Char)0x6b,  /* [3257] */
    (xdc_Char)0x20,  /* [3258] */
    (xdc_Char)0x41,  /* [3259] */
    (xdc_Char)0x50,  /* [3260] */
    (xdc_Char)0x49,  /* [3261] */
    (xdc_Char)0x20,  /* [3262] */
    (xdc_Char)0x64,  /* [3263] */
    (xdc_Char)0x6f,  /* [3264] */
    (xdc_Char)0x63,  /* [3265] */
    (xdc_Char)0x20,  /* [3266] */
    (xdc_Char)0x66,  /* [3267] */
    (xdc_Char)0x6f,  /* [3268] */
    (xdc_Char)0x72,  /* [3269] */
    (xdc_Char)0x20,  /* [3270] */
    (xdc_Char)0x64,  /* [3271] */
    (xdc_Char)0x65,  /* [3272] */
    (xdc_Char)0x74,  /* [3273] */
    (xdc_Char)0x61,  /* [3274] */
    (xdc_Char)0x69,  /* [3275] */
    (xdc_Char)0x6c,  /* [3276] */
    (xdc_Char)0x73,  /* [3277] */
    (xdc_Char)0x2e,  /* [3278] */
    (xdc_Char)0x0,  /* [3279] */
    (xdc_Char)0x41,  /* [3280] */
    (xdc_Char)0x5f,  /* [3281] */
    (xdc_Char)0x69,  /* [3282] */
    (xdc_Char)0x6e,  /* [3283] */
    (xdc_Char)0x76,  /* [3284] */
    (xdc_Char)0x61,  /* [3285] */
    (xdc_Char)0x6c,  /* [3286] */
    (xdc_Char)0x69,  /* [3287] */
    (xdc_Char)0x64,  /* [3288] */
    (xdc_Char)0x51,  /* [3289] */
    (xdc_Char)0x75,  /* [3290] */
    (xdc_Char)0x61,  /* [3291] */
    (xdc_Char)0x6c,  /* [3292] */
    (xdc_Char)0x69,  /* [3293] */
    (xdc_Char)0x74,  /* [3294] */
    (xdc_Char)0x79,  /* [3295] */
    (xdc_Char)0x3a,  /* [3296] */
    (xdc_Char)0x20,  /* [3297] */
    (xdc_Char)0x53,  /* [3298] */
    (xdc_Char)0x65,  /* [3299] */
    (xdc_Char)0x65,  /* [3300] */
    (xdc_Char)0x20,  /* [3301] */
    (xdc_Char)0x47,  /* [3302] */
    (xdc_Char)0x61,  /* [3303] */
    (xdc_Char)0x74,  /* [3304] */
    (xdc_Char)0x65,  /* [3305] */
    (xdc_Char)0x53,  /* [3306] */
    (xdc_Char)0x70,  /* [3307] */
    (xdc_Char)0x69,  /* [3308] */
    (xdc_Char)0x6e,  /* [3309] */
    (xdc_Char)0x6c,  /* [3310] */
    (xdc_Char)0x6f,  /* [3311] */
    (xdc_Char)0x63,  /* [3312] */
    (xdc_Char)0x6b,  /* [3313] */
    (xdc_Char)0x20,  /* [3314] */
    (xdc_Char)0x41,  /* [3315] */
    (xdc_Char)0x50,  /* [3316] */
    (xdc_Char)0x49,  /* [3317] */
    (xdc_Char)0x20,  /* [3318] */
    (xdc_Char)0x64,  /* [3319] */
    (xdc_Char)0x6f,  /* [3320] */
    (xdc_Char)0x63,  /* [3321] */
    (xdc_Char)0x20,  /* [3322] */
    (xdc_Char)0x66,  /* [3323] */
    (xdc_Char)0x6f,  /* [3324] */
    (xdc_Char)0x72,  /* [3325] */
    (xdc_Char)0x20,  /* [3326] */
    (xdc_Char)0x64,  /* [3327] */
    (xdc_Char)0x65,  /* [3328] */
    (xdc_Char)0x74,  /* [3329] */
    (xdc_Char)0x61,  /* [3330] */
    (xdc_Char)0x69,  /* [3331] */
    (xdc_Char)0x6c,  /* [3332] */
    (xdc_Char)0x73,  /* [3333] */
    (xdc_Char)0x2e,  /* [3334] */
    (xdc_Char)0x0,  /* [3335] */
    (xdc_Char)0x62,  /* [3336] */
    (xdc_Char)0x75,  /* [3337] */
    (xdc_Char)0x66,  /* [3338] */
    (xdc_Char)0x20,  /* [3339] */
    (xdc_Char)0x70,  /* [3340] */
    (xdc_Char)0x61,  /* [3341] */
    (xdc_Char)0x72,  /* [3342] */
    (xdc_Char)0x61,  /* [3343] */
    (xdc_Char)0x6d,  /* [3344] */
    (xdc_Char)0x65,  /* [3345] */
    (xdc_Char)0x74,  /* [3346] */
    (xdc_Char)0x65,  /* [3347] */
    (xdc_Char)0x72,  /* [3348] */
    (xdc_Char)0x20,  /* [3349] */
    (xdc_Char)0x63,  /* [3350] */
    (xdc_Char)0x61,  /* [3351] */
    (xdc_Char)0x6e,  /* [3352] */
    (xdc_Char)0x6e,  /* [3353] */
    (xdc_Char)0x6f,  /* [3354] */
    (xdc_Char)0x74,  /* [3355] */
    (xdc_Char)0x20,  /* [3356] */
    (xdc_Char)0x62,  /* [3357] */
    (xdc_Char)0x65,  /* [3358] */
    (xdc_Char)0x20,  /* [3359] */
    (xdc_Char)0x6e,  /* [3360] */
    (xdc_Char)0x75,  /* [3361] */
    (xdc_Char)0x6c,  /* [3362] */
    (xdc_Char)0x6c,  /* [3363] */
    (xdc_Char)0x0,  /* [3364] */
    (xdc_Char)0x62,  /* [3365] */
    (xdc_Char)0x75,  /* [3366] */
    (xdc_Char)0x66,  /* [3367] */
    (xdc_Char)0x20,  /* [3368] */
    (xdc_Char)0x6e,  /* [3369] */
    (xdc_Char)0x6f,  /* [3370] */
    (xdc_Char)0x74,  /* [3371] */
    (xdc_Char)0x20,  /* [3372] */
    (xdc_Char)0x70,  /* [3373] */
    (xdc_Char)0x72,  /* [3374] */
    (xdc_Char)0x6f,  /* [3375] */
    (xdc_Char)0x70,  /* [3376] */
    (xdc_Char)0x65,  /* [3377] */
    (xdc_Char)0x72,  /* [3378] */
    (xdc_Char)0x6c,  /* [3379] */
    (xdc_Char)0x79,  /* [3380] */
    (xdc_Char)0x20,  /* [3381] */
    (xdc_Char)0x61,  /* [3382] */
    (xdc_Char)0x6c,  /* [3383] */
    (xdc_Char)0x69,  /* [3384] */
    (xdc_Char)0x67,  /* [3385] */
    (xdc_Char)0x6e,  /* [3386] */
    (xdc_Char)0x65,  /* [3387] */
    (xdc_Char)0x64,  /* [3388] */
    (xdc_Char)0x0,  /* [3389] */
    (xdc_Char)0x61,  /* [3390] */
    (xdc_Char)0x6c,  /* [3391] */
    (xdc_Char)0x69,  /* [3392] */
    (xdc_Char)0x67,  /* [3393] */
    (xdc_Char)0x6e,  /* [3394] */
    (xdc_Char)0x20,  /* [3395] */
    (xdc_Char)0x70,  /* [3396] */
    (xdc_Char)0x61,  /* [3397] */
    (xdc_Char)0x72,  /* [3398] */
    (xdc_Char)0x61,  /* [3399] */
    (xdc_Char)0x6d,  /* [3400] */
    (xdc_Char)0x65,  /* [3401] */
    (xdc_Char)0x74,  /* [3402] */
    (xdc_Char)0x65,  /* [3403] */
    (xdc_Char)0x72,  /* [3404] */
    (xdc_Char)0x20,  /* [3405] */
    (xdc_Char)0x6d,  /* [3406] */
    (xdc_Char)0x75,  /* [3407] */
    (xdc_Char)0x73,  /* [3408] */
    (xdc_Char)0x74,  /* [3409] */
    (xdc_Char)0x20,  /* [3410] */
    (xdc_Char)0x62,  /* [3411] */
    (xdc_Char)0x65,  /* [3412] */
    (xdc_Char)0x20,  /* [3413] */
    (xdc_Char)0x30,  /* [3414] */
    (xdc_Char)0x20,  /* [3415] */
    (xdc_Char)0x6f,  /* [3416] */
    (xdc_Char)0x72,  /* [3417] */
    (xdc_Char)0x20,  /* [3418] */
    (xdc_Char)0x61,  /* [3419] */
    (xdc_Char)0x20,  /* [3420] */
    (xdc_Char)0x70,  /* [3421] */
    (xdc_Char)0x6f,  /* [3422] */
    (xdc_Char)0x77,  /* [3423] */
    (xdc_Char)0x65,  /* [3424] */
    (xdc_Char)0x72,  /* [3425] */
    (xdc_Char)0x20,  /* [3426] */
    (xdc_Char)0x6f,  /* [3427] */
    (xdc_Char)0x66,  /* [3428] */
    (xdc_Char)0x20,  /* [3429] */
    (xdc_Char)0x32,  /* [3430] */
    (xdc_Char)0x20,  /* [3431] */
    (xdc_Char)0x3e,  /* [3432] */
    (xdc_Char)0x3d,  /* [3433] */
    (xdc_Char)0x20,  /* [3434] */
    (xdc_Char)0x74,  /* [3435] */
    (xdc_Char)0x68,  /* [3436] */
    (xdc_Char)0x65,  /* [3437] */
    (xdc_Char)0x20,  /* [3438] */
    (xdc_Char)0x76,  /* [3439] */
    (xdc_Char)0x61,  /* [3440] */
    (xdc_Char)0x6c,  /* [3441] */
    (xdc_Char)0x75,  /* [3442] */
    (xdc_Char)0x65,  /* [3443] */
    (xdc_Char)0x20,  /* [3444] */
    (xdc_Char)0x6f,  /* [3445] */
    (xdc_Char)0x66,  /* [3446] */
    (xdc_Char)0x20,  /* [3447] */
    (xdc_Char)0x4d,  /* [3448] */
    (xdc_Char)0x65,  /* [3449] */
    (xdc_Char)0x6d,  /* [3450] */
    (xdc_Char)0x6f,  /* [3451] */
    (xdc_Char)0x72,  /* [3452] */
    (xdc_Char)0x79,  /* [3453] */
    (xdc_Char)0x5f,  /* [3454] */
    (xdc_Char)0x67,  /* [3455] */
    (xdc_Char)0x65,  /* [3456] */
    (xdc_Char)0x74,  /* [3457] */
    (xdc_Char)0x4d,  /* [3458] */
    (xdc_Char)0x61,  /* [3459] */
    (xdc_Char)0x78,  /* [3460] */
    (xdc_Char)0x44,  /* [3461] */
    (xdc_Char)0x65,  /* [3462] */
    (xdc_Char)0x66,  /* [3463] */
    (xdc_Char)0x61,  /* [3464] */
    (xdc_Char)0x75,  /* [3465] */
    (xdc_Char)0x6c,  /* [3466] */
    (xdc_Char)0x74,  /* [3467] */
    (xdc_Char)0x54,  /* [3468] */
    (xdc_Char)0x79,  /* [3469] */
    (xdc_Char)0x70,  /* [3470] */
    (xdc_Char)0x65,  /* [3471] */
    (xdc_Char)0x41,  /* [3472] */
    (xdc_Char)0x6c,  /* [3473] */
    (xdc_Char)0x69,  /* [3474] */
    (xdc_Char)0x67,  /* [3475] */
    (xdc_Char)0x6e,  /* [3476] */
    (xdc_Char)0x28,  /* [3477] */
    (xdc_Char)0x29,  /* [3478] */
    (xdc_Char)0x0,  /* [3479] */
    (xdc_Char)0x61,  /* [3480] */
    (xdc_Char)0x6c,  /* [3481] */
    (xdc_Char)0x69,  /* [3482] */
    (xdc_Char)0x67,  /* [3483] */
    (xdc_Char)0x6e,  /* [3484] */
    (xdc_Char)0x20,  /* [3485] */
    (xdc_Char)0x70,  /* [3486] */
    (xdc_Char)0x61,  /* [3487] */
    (xdc_Char)0x72,  /* [3488] */
    (xdc_Char)0x61,  /* [3489] */
    (xdc_Char)0x6d,  /* [3490] */
    (xdc_Char)0x65,  /* [3491] */
    (xdc_Char)0x74,  /* [3492] */
    (xdc_Char)0x65,  /* [3493] */
    (xdc_Char)0x72,  /* [3494] */
    (xdc_Char)0x20,  /* [3495] */
    (xdc_Char)0x31,  /* [3496] */
    (xdc_Char)0x29,  /* [3497] */
    (xdc_Char)0x20,  /* [3498] */
    (xdc_Char)0x6d,  /* [3499] */
    (xdc_Char)0x75,  /* [3500] */
    (xdc_Char)0x73,  /* [3501] */
    (xdc_Char)0x74,  /* [3502] */
    (xdc_Char)0x20,  /* [3503] */
    (xdc_Char)0x62,  /* [3504] */
    (xdc_Char)0x65,  /* [3505] */
    (xdc_Char)0x20,  /* [3506] */
    (xdc_Char)0x30,  /* [3507] */
    (xdc_Char)0x20,  /* [3508] */
    (xdc_Char)0x6f,  /* [3509] */
    (xdc_Char)0x72,  /* [3510] */
    (xdc_Char)0x20,  /* [3511] */
    (xdc_Char)0x61,  /* [3512] */
    (xdc_Char)0x20,  /* [3513] */
    (xdc_Char)0x70,  /* [3514] */
    (xdc_Char)0x6f,  /* [3515] */
    (xdc_Char)0x77,  /* [3516] */
    (xdc_Char)0x65,  /* [3517] */
    (xdc_Char)0x72,  /* [3518] */
    (xdc_Char)0x20,  /* [3519] */
    (xdc_Char)0x6f,  /* [3520] */
    (xdc_Char)0x66,  /* [3521] */
    (xdc_Char)0x20,  /* [3522] */
    (xdc_Char)0x32,  /* [3523] */
    (xdc_Char)0x20,  /* [3524] */
    (xdc_Char)0x61,  /* [3525] */
    (xdc_Char)0x6e,  /* [3526] */
    (xdc_Char)0x64,  /* [3527] */
    (xdc_Char)0x20,  /* [3528] */
    (xdc_Char)0x32,  /* [3529] */
    (xdc_Char)0x29,  /* [3530] */
    (xdc_Char)0x20,  /* [3531] */
    (xdc_Char)0x6e,  /* [3532] */
    (xdc_Char)0x6f,  /* [3533] */
    (xdc_Char)0x74,  /* [3534] */
    (xdc_Char)0x20,  /* [3535] */
    (xdc_Char)0x67,  /* [3536] */
    (xdc_Char)0x72,  /* [3537] */
    (xdc_Char)0x65,  /* [3538] */
    (xdc_Char)0x61,  /* [3539] */
    (xdc_Char)0x74,  /* [3540] */
    (xdc_Char)0x65,  /* [3541] */
    (xdc_Char)0x72,  /* [3542] */
    (xdc_Char)0x20,  /* [3543] */
    (xdc_Char)0x74,  /* [3544] */
    (xdc_Char)0x68,  /* [3545] */
    (xdc_Char)0x61,  /* [3546] */
    (xdc_Char)0x6e,  /* [3547] */
    (xdc_Char)0x20,  /* [3548] */
    (xdc_Char)0x74,  /* [3549] */
    (xdc_Char)0x68,  /* [3550] */
    (xdc_Char)0x65,  /* [3551] */
    (xdc_Char)0x20,  /* [3552] */
    (xdc_Char)0x68,  /* [3553] */
    (xdc_Char)0x65,  /* [3554] */
    (xdc_Char)0x61,  /* [3555] */
    (xdc_Char)0x70,  /* [3556] */
    (xdc_Char)0x73,  /* [3557] */
    (xdc_Char)0x20,  /* [3558] */
    (xdc_Char)0x61,  /* [3559] */
    (xdc_Char)0x6c,  /* [3560] */
    (xdc_Char)0x69,  /* [3561] */
    (xdc_Char)0x67,  /* [3562] */
    (xdc_Char)0x6e,  /* [3563] */
    (xdc_Char)0x6d,  /* [3564] */
    (xdc_Char)0x65,  /* [3565] */
    (xdc_Char)0x6e,  /* [3566] */
    (xdc_Char)0x74,  /* [3567] */
    (xdc_Char)0x0,  /* [3568] */
    (xdc_Char)0x62,  /* [3569] */
    (xdc_Char)0x6c,  /* [3570] */
    (xdc_Char)0x6f,  /* [3571] */
    (xdc_Char)0x63,  /* [3572] */
    (xdc_Char)0x6b,  /* [3573] */
    (xdc_Char)0x53,  /* [3574] */
    (xdc_Char)0x69,  /* [3575] */
    (xdc_Char)0x7a,  /* [3576] */
    (xdc_Char)0x65,  /* [3577] */
    (xdc_Char)0x20,  /* [3578] */
    (xdc_Char)0x6d,  /* [3579] */
    (xdc_Char)0x75,  /* [3580] */
    (xdc_Char)0x73,  /* [3581] */
    (xdc_Char)0x74,  /* [3582] */
    (xdc_Char)0x20,  /* [3583] */
    (xdc_Char)0x62,  /* [3584] */
    (xdc_Char)0x65,  /* [3585] */
    (xdc_Char)0x20,  /* [3586] */
    (xdc_Char)0x6c,  /* [3587] */
    (xdc_Char)0x61,  /* [3588] */
    (xdc_Char)0x72,  /* [3589] */
    (xdc_Char)0x67,  /* [3590] */
    (xdc_Char)0x65,  /* [3591] */
    (xdc_Char)0x20,  /* [3592] */
    (xdc_Char)0x65,  /* [3593] */
    (xdc_Char)0x6e,  /* [3594] */
    (xdc_Char)0x6f,  /* [3595] */
    (xdc_Char)0x75,  /* [3596] */
    (xdc_Char)0x67,  /* [3597] */
    (xdc_Char)0x68,  /* [3598] */
    (xdc_Char)0x20,  /* [3599] */
    (xdc_Char)0x74,  /* [3600] */
    (xdc_Char)0x6f,  /* [3601] */
    (xdc_Char)0x20,  /* [3602] */
    (xdc_Char)0x68,  /* [3603] */
    (xdc_Char)0x6f,  /* [3604] */
    (xdc_Char)0x6c,  /* [3605] */
    (xdc_Char)0x64,  /* [3606] */
    (xdc_Char)0x20,  /* [3607] */
    (xdc_Char)0x61,  /* [3608] */
    (xdc_Char)0x74,  /* [3609] */
    (xdc_Char)0x6c,  /* [3610] */
    (xdc_Char)0x65,  /* [3611] */
    (xdc_Char)0x61,  /* [3612] */
    (xdc_Char)0x73,  /* [3613] */
    (xdc_Char)0x74,  /* [3614] */
    (xdc_Char)0x20,  /* [3615] */
    (xdc_Char)0x74,  /* [3616] */
    (xdc_Char)0x77,  /* [3617] */
    (xdc_Char)0x6f,  /* [3618] */
    (xdc_Char)0x20,  /* [3619] */
    (xdc_Char)0x70,  /* [3620] */
    (xdc_Char)0x6f,  /* [3621] */
    (xdc_Char)0x69,  /* [3622] */
    (xdc_Char)0x6e,  /* [3623] */
    (xdc_Char)0x74,  /* [3624] */
    (xdc_Char)0x65,  /* [3625] */
    (xdc_Char)0x72,  /* [3626] */
    (xdc_Char)0x73,  /* [3627] */
    (xdc_Char)0x0,  /* [3628] */
    (xdc_Char)0x6e,  /* [3629] */
    (xdc_Char)0x75,  /* [3630] */
    (xdc_Char)0x6d,  /* [3631] */
    (xdc_Char)0x42,  /* [3632] */
    (xdc_Char)0x6c,  /* [3633] */
    (xdc_Char)0x6f,  /* [3634] */
    (xdc_Char)0x63,  /* [3635] */
    (xdc_Char)0x6b,  /* [3636] */
    (xdc_Char)0x73,  /* [3637] */
    (xdc_Char)0x20,  /* [3638] */
    (xdc_Char)0x63,  /* [3639] */
    (xdc_Char)0x61,  /* [3640] */
    (xdc_Char)0x6e,  /* [3641] */
    (xdc_Char)0x6e,  /* [3642] */
    (xdc_Char)0x6f,  /* [3643] */
    (xdc_Char)0x74,  /* [3644] */
    (xdc_Char)0x20,  /* [3645] */
    (xdc_Char)0x62,  /* [3646] */
    (xdc_Char)0x65,  /* [3647] */
    (xdc_Char)0x20,  /* [3648] */
    (xdc_Char)0x7a,  /* [3649] */
    (xdc_Char)0x65,  /* [3650] */
    (xdc_Char)0x72,  /* [3651] */
    (xdc_Char)0x6f,  /* [3652] */
    (xdc_Char)0x0,  /* [3653] */
    (xdc_Char)0x62,  /* [3654] */
    (xdc_Char)0x75,  /* [3655] */
    (xdc_Char)0x66,  /* [3656] */
    (xdc_Char)0x53,  /* [3657] */
    (xdc_Char)0x69,  /* [3658] */
    (xdc_Char)0x7a,  /* [3659] */
    (xdc_Char)0x65,  /* [3660] */
    (xdc_Char)0x20,  /* [3661] */
    (xdc_Char)0x63,  /* [3662] */
    (xdc_Char)0x61,  /* [3663] */
    (xdc_Char)0x6e,  /* [3664] */
    (xdc_Char)0x6e,  /* [3665] */
    (xdc_Char)0x6f,  /* [3666] */
    (xdc_Char)0x74,  /* [3667] */
    (xdc_Char)0x20,  /* [3668] */
    (xdc_Char)0x62,  /* [3669] */
    (xdc_Char)0x65,  /* [3670] */
    (xdc_Char)0x20,  /* [3671] */
    (xdc_Char)0x7a,  /* [3672] */
    (xdc_Char)0x65,  /* [3673] */
    (xdc_Char)0x72,  /* [3674] */
    (xdc_Char)0x6f,  /* [3675] */
    (xdc_Char)0x0,  /* [3676] */
    (xdc_Char)0x48,  /* [3677] */
    (xdc_Char)0x65,  /* [3678] */
    (xdc_Char)0x61,  /* [3679] */
    (xdc_Char)0x70,  /* [3680] */
    (xdc_Char)0x42,  /* [3681] */
    (xdc_Char)0x75,  /* [3682] */
    (xdc_Char)0x66,  /* [3683] */
    (xdc_Char)0x5f,  /* [3684] */
    (xdc_Char)0x63,  /* [3685] */
    (xdc_Char)0x72,  /* [3686] */
    (xdc_Char)0x65,  /* [3687] */
    (xdc_Char)0x61,  /* [3688] */
    (xdc_Char)0x74,  /* [3689] */
    (xdc_Char)0x65,  /* [3690] */
    (xdc_Char)0x27,  /* [3691] */
    (xdc_Char)0x73,  /* [3692] */
    (xdc_Char)0x20,  /* [3693] */
    (xdc_Char)0x62,  /* [3694] */
    (xdc_Char)0x75,  /* [3695] */
    (xdc_Char)0x66,  /* [3696] */
    (xdc_Char)0x53,  /* [3697] */
    (xdc_Char)0x69,  /* [3698] */
    (xdc_Char)0x7a,  /* [3699] */
    (xdc_Char)0x65,  /* [3700] */
    (xdc_Char)0x20,  /* [3701] */
    (xdc_Char)0x70,  /* [3702] */
    (xdc_Char)0x61,  /* [3703] */
    (xdc_Char)0x72,  /* [3704] */
    (xdc_Char)0x61,  /* [3705] */
    (xdc_Char)0x6d,  /* [3706] */
    (xdc_Char)0x65,  /* [3707] */
    (xdc_Char)0x74,  /* [3708] */
    (xdc_Char)0x65,  /* [3709] */
    (xdc_Char)0x72,  /* [3710] */
    (xdc_Char)0x20,  /* [3711] */
    (xdc_Char)0x69,  /* [3712] */
    (xdc_Char)0x73,  /* [3713] */
    (xdc_Char)0x20,  /* [3714] */
    (xdc_Char)0x69,  /* [3715] */
    (xdc_Char)0x6e,  /* [3716] */
    (xdc_Char)0x76,  /* [3717] */
    (xdc_Char)0x61,  /* [3718] */
    (xdc_Char)0x6c,  /* [3719] */
    (xdc_Char)0x69,  /* [3720] */
    (xdc_Char)0x64,  /* [3721] */
    (xdc_Char)0x20,  /* [3722] */
    (xdc_Char)0x28,  /* [3723] */
    (xdc_Char)0x74,  /* [3724] */
    (xdc_Char)0x6f,  /* [3725] */
    (xdc_Char)0x6f,  /* [3726] */
    (xdc_Char)0x20,  /* [3727] */
    (xdc_Char)0x73,  /* [3728] */
    (xdc_Char)0x6d,  /* [3729] */
    (xdc_Char)0x61,  /* [3730] */
    (xdc_Char)0x6c,  /* [3731] */
    (xdc_Char)0x6c,  /* [3732] */
    (xdc_Char)0x29,  /* [3733] */
    (xdc_Char)0x0,  /* [3734] */
    (xdc_Char)0x43,  /* [3735] */
    (xdc_Char)0x61,  /* [3736] */
    (xdc_Char)0x6e,  /* [3737] */
    (xdc_Char)0x6e,  /* [3738] */
    (xdc_Char)0x6f,  /* [3739] */
    (xdc_Char)0x74,  /* [3740] */
    (xdc_Char)0x20,  /* [3741] */
    (xdc_Char)0x63,  /* [3742] */
    (xdc_Char)0x61,  /* [3743] */
    (xdc_Char)0x6c,  /* [3744] */
    (xdc_Char)0x6c,  /* [3745] */
    (xdc_Char)0x20,  /* [3746] */
    (xdc_Char)0x48,  /* [3747] */
    (xdc_Char)0x65,  /* [3748] */
    (xdc_Char)0x61,  /* [3749] */
    (xdc_Char)0x70,  /* [3750] */
    (xdc_Char)0x42,  /* [3751] */
    (xdc_Char)0x75,  /* [3752] */
    (xdc_Char)0x66,  /* [3753] */
    (xdc_Char)0x5f,  /* [3754] */
    (xdc_Char)0x66,  /* [3755] */
    (xdc_Char)0x72,  /* [3756] */
    (xdc_Char)0x65,  /* [3757] */
    (xdc_Char)0x65,  /* [3758] */
    (xdc_Char)0x20,  /* [3759] */
    (xdc_Char)0x77,  /* [3760] */
    (xdc_Char)0x68,  /* [3761] */
    (xdc_Char)0x65,  /* [3762] */
    (xdc_Char)0x6e,  /* [3763] */
    (xdc_Char)0x20,  /* [3764] */
    (xdc_Char)0x6e,  /* [3765] */
    (xdc_Char)0x6f,  /* [3766] */
    (xdc_Char)0x20,  /* [3767] */
    (xdc_Char)0x62,  /* [3768] */
    (xdc_Char)0x6c,  /* [3769] */
    (xdc_Char)0x6f,  /* [3770] */
    (xdc_Char)0x63,  /* [3771] */
    (xdc_Char)0x6b,  /* [3772] */
    (xdc_Char)0x73,  /* [3773] */
    (xdc_Char)0x20,  /* [3774] */
    (xdc_Char)0x68,  /* [3775] */
    (xdc_Char)0x61,  /* [3776] */
    (xdc_Char)0x76,  /* [3777] */
    (xdc_Char)0x65,  /* [3778] */
    (xdc_Char)0x20,  /* [3779] */
    (xdc_Char)0x62,  /* [3780] */
    (xdc_Char)0x65,  /* [3781] */
    (xdc_Char)0x65,  /* [3782] */
    (xdc_Char)0x6e,  /* [3783] */
    (xdc_Char)0x20,  /* [3784] */
    (xdc_Char)0x61,  /* [3785] */
    (xdc_Char)0x6c,  /* [3786] */
    (xdc_Char)0x6c,  /* [3787] */
    (xdc_Char)0x6f,  /* [3788] */
    (xdc_Char)0x63,  /* [3789] */
    (xdc_Char)0x61,  /* [3790] */
    (xdc_Char)0x74,  /* [3791] */
    (xdc_Char)0x65,  /* [3792] */
    (xdc_Char)0x64,  /* [3793] */
    (xdc_Char)0x0,  /* [3794] */
    (xdc_Char)0x41,  /* [3795] */
    (xdc_Char)0x5f,  /* [3796] */
    (xdc_Char)0x69,  /* [3797] */
    (xdc_Char)0x6e,  /* [3798] */
    (xdc_Char)0x76,  /* [3799] */
    (xdc_Char)0x61,  /* [3800] */
    (xdc_Char)0x6c,  /* [3801] */
    (xdc_Char)0x69,  /* [3802] */
    (xdc_Char)0x64,  /* [3803] */
    (xdc_Char)0x46,  /* [3804] */
    (xdc_Char)0x72,  /* [3805] */
    (xdc_Char)0x65,  /* [3806] */
    (xdc_Char)0x65,  /* [3807] */
    (xdc_Char)0x3a,  /* [3808] */
    (xdc_Char)0x20,  /* [3809] */
    (xdc_Char)0x49,  /* [3810] */
    (xdc_Char)0x6e,  /* [3811] */
    (xdc_Char)0x76,  /* [3812] */
    (xdc_Char)0x61,  /* [3813] */
    (xdc_Char)0x6c,  /* [3814] */
    (xdc_Char)0x69,  /* [3815] */
    (xdc_Char)0x64,  /* [3816] */
    (xdc_Char)0x20,  /* [3817] */
    (xdc_Char)0x66,  /* [3818] */
    (xdc_Char)0x72,  /* [3819] */
    (xdc_Char)0x65,  /* [3820] */
    (xdc_Char)0x65,  /* [3821] */
    (xdc_Char)0x0,  /* [3822] */
    (xdc_Char)0x41,  /* [3823] */
    (xdc_Char)0x5f,  /* [3824] */
    (xdc_Char)0x7a,  /* [3825] */
    (xdc_Char)0x65,  /* [3826] */
    (xdc_Char)0x72,  /* [3827] */
    (xdc_Char)0x6f,  /* [3828] */
    (xdc_Char)0x42,  /* [3829] */
    (xdc_Char)0x6c,  /* [3830] */
    (xdc_Char)0x6f,  /* [3831] */
    (xdc_Char)0x63,  /* [3832] */
    (xdc_Char)0x6b,  /* [3833] */
    (xdc_Char)0x3a,  /* [3834] */
    (xdc_Char)0x20,  /* [3835] */
    (xdc_Char)0x43,  /* [3836] */
    (xdc_Char)0x61,  /* [3837] */
    (xdc_Char)0x6e,  /* [3838] */
    (xdc_Char)0x6e,  /* [3839] */
    (xdc_Char)0x6f,  /* [3840] */
    (xdc_Char)0x74,  /* [3841] */
    (xdc_Char)0x20,  /* [3842] */
    (xdc_Char)0x61,  /* [3843] */
    (xdc_Char)0x6c,  /* [3844] */
    (xdc_Char)0x6c,  /* [3845] */
    (xdc_Char)0x6f,  /* [3846] */
    (xdc_Char)0x63,  /* [3847] */
    (xdc_Char)0x61,  /* [3848] */
    (xdc_Char)0x74,  /* [3849] */
    (xdc_Char)0x65,  /* [3850] */
    (xdc_Char)0x20,  /* [3851] */
    (xdc_Char)0x73,  /* [3852] */
    (xdc_Char)0x69,  /* [3853] */
    (xdc_Char)0x7a,  /* [3854] */
    (xdc_Char)0x65,  /* [3855] */
    (xdc_Char)0x20,  /* [3856] */
    (xdc_Char)0x30,  /* [3857] */
    (xdc_Char)0x0,  /* [3858] */
    (xdc_Char)0x41,  /* [3859] */
    (xdc_Char)0x5f,  /* [3860] */
    (xdc_Char)0x68,  /* [3861] */
    (xdc_Char)0x65,  /* [3862] */
    (xdc_Char)0x61,  /* [3863] */
    (xdc_Char)0x70,  /* [3864] */
    (xdc_Char)0x53,  /* [3865] */
    (xdc_Char)0x69,  /* [3866] */
    (xdc_Char)0x7a,  /* [3867] */
    (xdc_Char)0x65,  /* [3868] */
    (xdc_Char)0x3a,  /* [3869] */
    (xdc_Char)0x20,  /* [3870] */
    (xdc_Char)0x52,  /* [3871] */
    (xdc_Char)0x65,  /* [3872] */
    (xdc_Char)0x71,  /* [3873] */
    (xdc_Char)0x75,  /* [3874] */
    (xdc_Char)0x65,  /* [3875] */
    (xdc_Char)0x73,  /* [3876] */
    (xdc_Char)0x74,  /* [3877] */
    (xdc_Char)0x65,  /* [3878] */
    (xdc_Char)0x64,  /* [3879] */
    (xdc_Char)0x20,  /* [3880] */
    (xdc_Char)0x68,  /* [3881] */
    (xdc_Char)0x65,  /* [3882] */
    (xdc_Char)0x61,  /* [3883] */
    (xdc_Char)0x70,  /* [3884] */
    (xdc_Char)0x20,  /* [3885] */
    (xdc_Char)0x73,  /* [3886] */
    (xdc_Char)0x69,  /* [3887] */
    (xdc_Char)0x7a,  /* [3888] */
    (xdc_Char)0x65,  /* [3889] */
    (xdc_Char)0x20,  /* [3890] */
    (xdc_Char)0x69,  /* [3891] */
    (xdc_Char)0x73,  /* [3892] */
    (xdc_Char)0x20,  /* [3893] */
    (xdc_Char)0x74,  /* [3894] */
    (xdc_Char)0x6f,  /* [3895] */
    (xdc_Char)0x6f,  /* [3896] */
    (xdc_Char)0x20,  /* [3897] */
    (xdc_Char)0x73,  /* [3898] */
    (xdc_Char)0x6d,  /* [3899] */
    (xdc_Char)0x61,  /* [3900] */
    (xdc_Char)0x6c,  /* [3901] */
    (xdc_Char)0x6c,  /* [3902] */
    (xdc_Char)0x0,  /* [3903] */
    (xdc_Char)0x41,  /* [3904] */
    (xdc_Char)0x5f,  /* [3905] */
    (xdc_Char)0x61,  /* [3906] */
    (xdc_Char)0x6c,  /* [3907] */
    (xdc_Char)0x69,  /* [3908] */
    (xdc_Char)0x67,  /* [3909] */
    (xdc_Char)0x6e,  /* [3910] */
    (xdc_Char)0x3a,  /* [3911] */
    (xdc_Char)0x20,  /* [3912] */
    (xdc_Char)0x52,  /* [3913] */
    (xdc_Char)0x65,  /* [3914] */
    (xdc_Char)0x71,  /* [3915] */
    (xdc_Char)0x75,  /* [3916] */
    (xdc_Char)0x65,  /* [3917] */
    (xdc_Char)0x73,  /* [3918] */
    (xdc_Char)0x74,  /* [3919] */
    (xdc_Char)0x65,  /* [3920] */
    (xdc_Char)0x64,  /* [3921] */
    (xdc_Char)0x20,  /* [3922] */
    (xdc_Char)0x61,  /* [3923] */
    (xdc_Char)0x6c,  /* [3924] */
    (xdc_Char)0x69,  /* [3925] */
    (xdc_Char)0x67,  /* [3926] */
    (xdc_Char)0x6e,  /* [3927] */
    (xdc_Char)0x20,  /* [3928] */
    (xdc_Char)0x69,  /* [3929] */
    (xdc_Char)0x73,  /* [3930] */
    (xdc_Char)0x20,  /* [3931] */
    (xdc_Char)0x6e,  /* [3932] */
    (xdc_Char)0x6f,  /* [3933] */
    (xdc_Char)0x74,  /* [3934] */
    (xdc_Char)0x20,  /* [3935] */
    (xdc_Char)0x61,  /* [3936] */
    (xdc_Char)0x20,  /* [3937] */
    (xdc_Char)0x70,  /* [3938] */
    (xdc_Char)0x6f,  /* [3939] */
    (xdc_Char)0x77,  /* [3940] */
    (xdc_Char)0x65,  /* [3941] */
    (xdc_Char)0x72,  /* [3942] */
    (xdc_Char)0x20,  /* [3943] */
    (xdc_Char)0x6f,  /* [3944] */
    (xdc_Char)0x66,  /* [3945] */
    (xdc_Char)0x20,  /* [3946] */
    (xdc_Char)0x32,  /* [3947] */
    (xdc_Char)0x0,  /* [3948] */
    (xdc_Char)0x49,  /* [3949] */
    (xdc_Char)0x6e,  /* [3950] */
    (xdc_Char)0x76,  /* [3951] */
    (xdc_Char)0x61,  /* [3952] */
    (xdc_Char)0x6c,  /* [3953] */
    (xdc_Char)0x69,  /* [3954] */
    (xdc_Char)0x64,  /* [3955] */
    (xdc_Char)0x20,  /* [3956] */
    (xdc_Char)0x62,  /* [3957] */
    (xdc_Char)0x6c,  /* [3958] */
    (xdc_Char)0x6f,  /* [3959] */
    (xdc_Char)0x63,  /* [3960] */
    (xdc_Char)0x6b,  /* [3961] */
    (xdc_Char)0x20,  /* [3962] */
    (xdc_Char)0x61,  /* [3963] */
    (xdc_Char)0x64,  /* [3964] */
    (xdc_Char)0x64,  /* [3965] */
    (xdc_Char)0x72,  /* [3966] */
    (xdc_Char)0x65,  /* [3967] */
    (xdc_Char)0x73,  /* [3968] */
    (xdc_Char)0x73,  /* [3969] */
    (xdc_Char)0x20,  /* [3970] */
    (xdc_Char)0x6f,  /* [3971] */
    (xdc_Char)0x6e,  /* [3972] */
    (xdc_Char)0x20,  /* [3973] */
    (xdc_Char)0x74,  /* [3974] */
    (xdc_Char)0x68,  /* [3975] */
    (xdc_Char)0x65,  /* [3976] */
    (xdc_Char)0x20,  /* [3977] */
    (xdc_Char)0x66,  /* [3978] */
    (xdc_Char)0x72,  /* [3979] */
    (xdc_Char)0x65,  /* [3980] */
    (xdc_Char)0x65,  /* [3981] */
    (xdc_Char)0x2e,  /* [3982] */
    (xdc_Char)0x20,  /* [3983] */
    (xdc_Char)0x46,  /* [3984] */
    (xdc_Char)0x61,  /* [3985] */
    (xdc_Char)0x69,  /* [3986] */
    (xdc_Char)0x6c,  /* [3987] */
    (xdc_Char)0x65,  /* [3988] */
    (xdc_Char)0x64,  /* [3989] */
    (xdc_Char)0x20,  /* [3990] */
    (xdc_Char)0x74,  /* [3991] */
    (xdc_Char)0x6f,  /* [3992] */
    (xdc_Char)0x20,  /* [3993] */
    (xdc_Char)0x66,  /* [3994] */
    (xdc_Char)0x72,  /* [3995] */
    (xdc_Char)0x65,  /* [3996] */
    (xdc_Char)0x65,  /* [3997] */
    (xdc_Char)0x20,  /* [3998] */
    (xdc_Char)0x62,  /* [3999] */
    (xdc_Char)0x6c,  /* [4000] */
    (xdc_Char)0x6f,  /* [4001] */
    (xdc_Char)0x63,  /* [4002] */
    (xdc_Char)0x6b,  /* [4003] */
    (xdc_Char)0x20,  /* [4004] */
    (xdc_Char)0x62,  /* [4005] */
    (xdc_Char)0x61,  /* [4006] */
    (xdc_Char)0x63,  /* [4007] */
    (xdc_Char)0x6b,  /* [4008] */
    (xdc_Char)0x20,  /* [4009] */
    (xdc_Char)0x74,  /* [4010] */
    (xdc_Char)0x6f,  /* [4011] */
    (xdc_Char)0x20,  /* [4012] */
    (xdc_Char)0x68,  /* [4013] */
    (xdc_Char)0x65,  /* [4014] */
    (xdc_Char)0x61,  /* [4015] */
    (xdc_Char)0x70,  /* [4016] */
    (xdc_Char)0x2e,  /* [4017] */
    (xdc_Char)0x0,  /* [4018] */
    (xdc_Char)0x41,  /* [4019] */
    (xdc_Char)0x5f,  /* [4020] */
    (xdc_Char)0x64,  /* [4021] */
    (xdc_Char)0x6f,  /* [4022] */
    (xdc_Char)0x75,  /* [4023] */
    (xdc_Char)0x62,  /* [4024] */
    (xdc_Char)0x6c,  /* [4025] */
    (xdc_Char)0x65,  /* [4026] */
    (xdc_Char)0x46,  /* [4027] */
    (xdc_Char)0x72,  /* [4028] */
    (xdc_Char)0x65,  /* [4029] */
    (xdc_Char)0x65,  /* [4030] */
    (xdc_Char)0x3a,  /* [4031] */
    (xdc_Char)0x20,  /* [4032] */
    (xdc_Char)0x42,  /* [4033] */
    (xdc_Char)0x75,  /* [4034] */
    (xdc_Char)0x66,  /* [4035] */
    (xdc_Char)0x66,  /* [4036] */
    (xdc_Char)0x65,  /* [4037] */
    (xdc_Char)0x72,  /* [4038] */
    (xdc_Char)0x20,  /* [4039] */
    (xdc_Char)0x61,  /* [4040] */
    (xdc_Char)0x6c,  /* [4041] */
    (xdc_Char)0x72,  /* [4042] */
    (xdc_Char)0x65,  /* [4043] */
    (xdc_Char)0x61,  /* [4044] */
    (xdc_Char)0x64,  /* [4045] */
    (xdc_Char)0x79,  /* [4046] */
    (xdc_Char)0x20,  /* [4047] */
    (xdc_Char)0x66,  /* [4048] */
    (xdc_Char)0x72,  /* [4049] */
    (xdc_Char)0x65,  /* [4050] */
    (xdc_Char)0x65,  /* [4051] */
    (xdc_Char)0x0,  /* [4052] */
    (xdc_Char)0x41,  /* [4053] */
    (xdc_Char)0x5f,  /* [4054] */
    (xdc_Char)0x62,  /* [4055] */
    (xdc_Char)0x75,  /* [4056] */
    (xdc_Char)0x66,  /* [4057] */
    (xdc_Char)0x4f,  /* [4058] */
    (xdc_Char)0x76,  /* [4059] */
    (xdc_Char)0x65,  /* [4060] */
    (xdc_Char)0x72,  /* [4061] */
    (xdc_Char)0x66,  /* [4062] */
    (xdc_Char)0x6c,  /* [4063] */
    (xdc_Char)0x6f,  /* [4064] */
    (xdc_Char)0x77,  /* [4065] */
    (xdc_Char)0x3a,  /* [4066] */
    (xdc_Char)0x20,  /* [4067] */
    (xdc_Char)0x42,  /* [4068] */
    (xdc_Char)0x75,  /* [4069] */
    (xdc_Char)0x66,  /* [4070] */
    (xdc_Char)0x66,  /* [4071] */
    (xdc_Char)0x65,  /* [4072] */
    (xdc_Char)0x72,  /* [4073] */
    (xdc_Char)0x20,  /* [4074] */
    (xdc_Char)0x6f,  /* [4075] */
    (xdc_Char)0x76,  /* [4076] */
    (xdc_Char)0x65,  /* [4077] */
    (xdc_Char)0x72,  /* [4078] */
    (xdc_Char)0x66,  /* [4079] */
    (xdc_Char)0x6c,  /* [4080] */
    (xdc_Char)0x6f,  /* [4081] */
    (xdc_Char)0x77,  /* [4082] */
    (xdc_Char)0x0,  /* [4083] */
    (xdc_Char)0x41,  /* [4084] */
    (xdc_Char)0x5f,  /* [4085] */
    (xdc_Char)0x6e,  /* [4086] */
    (xdc_Char)0x6f,  /* [4087] */
    (xdc_Char)0x74,  /* [4088] */
    (xdc_Char)0x45,  /* [4089] */
    (xdc_Char)0x6d,  /* [4090] */
    (xdc_Char)0x70,  /* [4091] */
    (xdc_Char)0x74,  /* [4092] */
    (xdc_Char)0x79,  /* [4093] */
    (xdc_Char)0x3a,  /* [4094] */
    (xdc_Char)0x20,  /* [4095] */
    (xdc_Char)0x48,  /* [4096] */
    (xdc_Char)0x65,  /* [4097] */
    (xdc_Char)0x61,  /* [4098] */
    (xdc_Char)0x70,  /* [4099] */
    (xdc_Char)0x20,  /* [4100] */
    (xdc_Char)0x6e,  /* [4101] */
    (xdc_Char)0x6f,  /* [4102] */
    (xdc_Char)0x74,  /* [4103] */
    (xdc_Char)0x20,  /* [4104] */
    (xdc_Char)0x65,  /* [4105] */
    (xdc_Char)0x6d,  /* [4106] */
    (xdc_Char)0x70,  /* [4107] */
    (xdc_Char)0x74,  /* [4108] */
    (xdc_Char)0x79,  /* [4109] */
    (xdc_Char)0x0,  /* [4110] */
    (xdc_Char)0x41,  /* [4111] */
    (xdc_Char)0x5f,  /* [4112] */
    (xdc_Char)0x6e,  /* [4113] */
    (xdc_Char)0x75,  /* [4114] */
    (xdc_Char)0x6c,  /* [4115] */
    (xdc_Char)0x6c,  /* [4116] */
    (xdc_Char)0x4f,  /* [4117] */
    (xdc_Char)0x62,  /* [4118] */
    (xdc_Char)0x6a,  /* [4119] */
    (xdc_Char)0x65,  /* [4120] */
    (xdc_Char)0x63,  /* [4121] */
    (xdc_Char)0x74,  /* [4122] */
    (xdc_Char)0x3a,  /* [4123] */
    (xdc_Char)0x20,  /* [4124] */
    (xdc_Char)0x48,  /* [4125] */
    (xdc_Char)0x65,  /* [4126] */
    (xdc_Char)0x61,  /* [4127] */
    (xdc_Char)0x70,  /* [4128] */
    (xdc_Char)0x54,  /* [4129] */
    (xdc_Char)0x72,  /* [4130] */
    (xdc_Char)0x61,  /* [4131] */
    (xdc_Char)0x63,  /* [4132] */
    (xdc_Char)0x6b,  /* [4133] */
    (xdc_Char)0x5f,  /* [4134] */
    (xdc_Char)0x70,  /* [4135] */
    (xdc_Char)0x72,  /* [4136] */
    (xdc_Char)0x69,  /* [4137] */
    (xdc_Char)0x6e,  /* [4138] */
    (xdc_Char)0x74,  /* [4139] */
    (xdc_Char)0x48,  /* [4140] */
    (xdc_Char)0x65,  /* [4141] */
    (xdc_Char)0x61,  /* [4142] */
    (xdc_Char)0x70,  /* [4143] */
    (xdc_Char)0x20,  /* [4144] */
    (xdc_Char)0x63,  /* [4145] */
    (xdc_Char)0x61,  /* [4146] */
    (xdc_Char)0x6c,  /* [4147] */
    (xdc_Char)0x6c,  /* [4148] */
    (xdc_Char)0x65,  /* [4149] */
    (xdc_Char)0x64,  /* [4150] */
    (xdc_Char)0x20,  /* [4151] */
    (xdc_Char)0x77,  /* [4152] */
    (xdc_Char)0x69,  /* [4153] */
    (xdc_Char)0x74,  /* [4154] */
    (xdc_Char)0x68,  /* [4155] */
    (xdc_Char)0x20,  /* [4156] */
    (xdc_Char)0x6e,  /* [4157] */
    (xdc_Char)0x75,  /* [4158] */
    (xdc_Char)0x6c,  /* [4159] */
    (xdc_Char)0x6c,  /* [4160] */
    (xdc_Char)0x20,  /* [4161] */
    (xdc_Char)0x6f,  /* [4162] */
    (xdc_Char)0x62,  /* [4163] */
    (xdc_Char)0x6a,  /* [4164] */
    (xdc_Char)0x0,  /* [4165] */
    (xdc_Char)0x61,  /* [4166] */
    (xdc_Char)0x73,  /* [4167] */
    (xdc_Char)0x73,  /* [4168] */
    (xdc_Char)0x65,  /* [4169] */
    (xdc_Char)0x72,  /* [4170] */
    (xdc_Char)0x74,  /* [4171] */
    (xdc_Char)0x69,  /* [4172] */
    (xdc_Char)0x6f,  /* [4173] */
    (xdc_Char)0x6e,  /* [4174] */
    (xdc_Char)0x20,  /* [4175] */
    (xdc_Char)0x66,  /* [4176] */
    (xdc_Char)0x61,  /* [4177] */
    (xdc_Char)0x69,  /* [4178] */
    (xdc_Char)0x6c,  /* [4179] */
    (xdc_Char)0x75,  /* [4180] */
    (xdc_Char)0x72,  /* [4181] */
    (xdc_Char)0x65,  /* [4182] */
    (xdc_Char)0x25,  /* [4183] */
    (xdc_Char)0x73,  /* [4184] */
    (xdc_Char)0x25,  /* [4185] */
    (xdc_Char)0x73,  /* [4186] */
    (xdc_Char)0x0,  /* [4187] */
    (xdc_Char)0x25,  /* [4188] */
    (xdc_Char)0x24,  /* [4189] */
    (xdc_Char)0x53,  /* [4190] */
    (xdc_Char)0x0,  /* [4191] */
    (xdc_Char)0x6f,  /* [4192] */
    (xdc_Char)0x75,  /* [4193] */
    (xdc_Char)0x74,  /* [4194] */
    (xdc_Char)0x20,  /* [4195] */
    (xdc_Char)0x6f,  /* [4196] */
    (xdc_Char)0x66,  /* [4197] */
    (xdc_Char)0x20,  /* [4198] */
    (xdc_Char)0x6d,  /* [4199] */
    (xdc_Char)0x65,  /* [4200] */
    (xdc_Char)0x6d,  /* [4201] */
    (xdc_Char)0x6f,  /* [4202] */
    (xdc_Char)0x72,  /* [4203] */
    (xdc_Char)0x79,  /* [4204] */
    (xdc_Char)0x3a,  /* [4205] */
    (xdc_Char)0x20,  /* [4206] */
    (xdc_Char)0x68,  /* [4207] */
    (xdc_Char)0x65,  /* [4208] */
    (xdc_Char)0x61,  /* [4209] */
    (xdc_Char)0x70,  /* [4210] */
    (xdc_Char)0x3d,  /* [4211] */
    (xdc_Char)0x30,  /* [4212] */
    (xdc_Char)0x78,  /* [4213] */
    (xdc_Char)0x25,  /* [4214] */
    (xdc_Char)0x78,  /* [4215] */
    (xdc_Char)0x2c,  /* [4216] */
    (xdc_Char)0x20,  /* [4217] */
    (xdc_Char)0x73,  /* [4218] */
    (xdc_Char)0x69,  /* [4219] */
    (xdc_Char)0x7a,  /* [4220] */
    (xdc_Char)0x65,  /* [4221] */
    (xdc_Char)0x3d,  /* [4222] */
    (xdc_Char)0x25,  /* [4223] */
    (xdc_Char)0x75,  /* [4224] */
    (xdc_Char)0x0,  /* [4225] */
    (xdc_Char)0x25,  /* [4226] */
    (xdc_Char)0x73,  /* [4227] */
    (xdc_Char)0x20,  /* [4228] */
    (xdc_Char)0x30,  /* [4229] */
    (xdc_Char)0x78,  /* [4230] */
    (xdc_Char)0x25,  /* [4231] */
    (xdc_Char)0x78,  /* [4232] */
    (xdc_Char)0x0,  /* [4233] */
    (xdc_Char)0x45,  /* [4234] */
    (xdc_Char)0x5f,  /* [4235] */
    (xdc_Char)0x62,  /* [4236] */
    (xdc_Char)0x61,  /* [4237] */
    (xdc_Char)0x64,  /* [4238] */
    (xdc_Char)0x4c,  /* [4239] */
    (xdc_Char)0x65,  /* [4240] */
    (xdc_Char)0x76,  /* [4241] */
    (xdc_Char)0x65,  /* [4242] */
    (xdc_Char)0x6c,  /* [4243] */
    (xdc_Char)0x3a,  /* [4244] */
    (xdc_Char)0x20,  /* [4245] */
    (xdc_Char)0x42,  /* [4246] */
    (xdc_Char)0x61,  /* [4247] */
    (xdc_Char)0x64,  /* [4248] */
    (xdc_Char)0x20,  /* [4249] */
    (xdc_Char)0x66,  /* [4250] */
    (xdc_Char)0x69,  /* [4251] */
    (xdc_Char)0x6c,  /* [4252] */
    (xdc_Char)0x74,  /* [4253] */
    (xdc_Char)0x65,  /* [4254] */
    (xdc_Char)0x72,  /* [4255] */
    (xdc_Char)0x20,  /* [4256] */
    (xdc_Char)0x6c,  /* [4257] */
    (xdc_Char)0x65,  /* [4258] */
    (xdc_Char)0x76,  /* [4259] */
    (xdc_Char)0x65,  /* [4260] */
    (xdc_Char)0x6c,  /* [4261] */
    (xdc_Char)0x20,  /* [4262] */
    (xdc_Char)0x76,  /* [4263] */
    (xdc_Char)0x61,  /* [4264] */
    (xdc_Char)0x6c,  /* [4265] */
    (xdc_Char)0x75,  /* [4266] */
    (xdc_Char)0x65,  /* [4267] */
    (xdc_Char)0x3a,  /* [4268] */
    (xdc_Char)0x20,  /* [4269] */
    (xdc_Char)0x25,  /* [4270] */
    (xdc_Char)0x64,  /* [4271] */
    (xdc_Char)0x0,  /* [4272] */
    (xdc_Char)0x66,  /* [4273] */
    (xdc_Char)0x72,  /* [4274] */
    (xdc_Char)0x65,  /* [4275] */
    (xdc_Char)0x65,  /* [4276] */
    (xdc_Char)0x28,  /* [4277] */
    (xdc_Char)0x29,  /* [4278] */
    (xdc_Char)0x20,  /* [4279] */
    (xdc_Char)0x69,  /* [4280] */
    (xdc_Char)0x6e,  /* [4281] */
    (xdc_Char)0x76,  /* [4282] */
    (xdc_Char)0x61,  /* [4283] */
    (xdc_Char)0x6c,  /* [4284] */
    (xdc_Char)0x69,  /* [4285] */
    (xdc_Char)0x64,  /* [4286] */
    (xdc_Char)0x20,  /* [4287] */
    (xdc_Char)0x69,  /* [4288] */
    (xdc_Char)0x6e,  /* [4289] */
    (xdc_Char)0x20,  /* [4290] */
    (xdc_Char)0x67,  /* [4291] */
    (xdc_Char)0x72,  /* [4292] */
    (xdc_Char)0x6f,  /* [4293] */
    (xdc_Char)0x77,  /* [4294] */
    (xdc_Char)0x74,  /* [4295] */
    (xdc_Char)0x68,  /* [4296] */
    (xdc_Char)0x2d,  /* [4297] */
    (xdc_Char)0x6f,  /* [4298] */
    (xdc_Char)0x6e,  /* [4299] */
    (xdc_Char)0x6c,  /* [4300] */
    (xdc_Char)0x79,  /* [4301] */
    (xdc_Char)0x20,  /* [4302] */
    (xdc_Char)0x48,  /* [4303] */
    (xdc_Char)0x65,  /* [4304] */
    (xdc_Char)0x61,  /* [4305] */
    (xdc_Char)0x70,  /* [4306] */
    (xdc_Char)0x4d,  /* [4307] */
    (xdc_Char)0x69,  /* [4308] */
    (xdc_Char)0x6e,  /* [4309] */
    (xdc_Char)0x0,  /* [4310] */
    (xdc_Char)0x54,  /* [4311] */
    (xdc_Char)0x68,  /* [4312] */
    (xdc_Char)0x65,  /* [4313] */
    (xdc_Char)0x20,  /* [4314] */
    (xdc_Char)0x52,  /* [4315] */
    (xdc_Char)0x54,  /* [4316] */
    (xdc_Char)0x53,  /* [4317] */
    (xdc_Char)0x20,  /* [4318] */
    (xdc_Char)0x68,  /* [4319] */
    (xdc_Char)0x65,  /* [4320] */
    (xdc_Char)0x61,  /* [4321] */
    (xdc_Char)0x70,  /* [4322] */
    (xdc_Char)0x20,  /* [4323] */
    (xdc_Char)0x69,  /* [4324] */
    (xdc_Char)0x73,  /* [4325] */
    (xdc_Char)0x20,  /* [4326] */
    (xdc_Char)0x75,  /* [4327] */
    (xdc_Char)0x73,  /* [4328] */
    (xdc_Char)0x65,  /* [4329] */
    (xdc_Char)0x64,  /* [4330] */
    (xdc_Char)0x20,  /* [4331] */
    (xdc_Char)0x75,  /* [4332] */
    (xdc_Char)0x70,  /* [4333] */
    (xdc_Char)0x2e,  /* [4334] */
    (xdc_Char)0x20,  /* [4335] */
    (xdc_Char)0x45,  /* [4336] */
    (xdc_Char)0x78,  /* [4337] */
    (xdc_Char)0x61,  /* [4338] */
    (xdc_Char)0x6d,  /* [4339] */
    (xdc_Char)0x69,  /* [4340] */
    (xdc_Char)0x6e,  /* [4341] */
    (xdc_Char)0x65,  /* [4342] */
    (xdc_Char)0x20,  /* [4343] */
    (xdc_Char)0x50,  /* [4344] */
    (xdc_Char)0x72,  /* [4345] */
    (xdc_Char)0x6f,  /* [4346] */
    (xdc_Char)0x67,  /* [4347] */
    (xdc_Char)0x72,  /* [4348] */
    (xdc_Char)0x61,  /* [4349] */
    (xdc_Char)0x6d,  /* [4350] */
    (xdc_Char)0x2e,  /* [4351] */
    (xdc_Char)0x68,  /* [4352] */
    (xdc_Char)0x65,  /* [4353] */
    (xdc_Char)0x61,  /* [4354] */
    (xdc_Char)0x70,  /* [4355] */
    (xdc_Char)0x2e,  /* [4356] */
    (xdc_Char)0x0,  /* [4357] */
    (xdc_Char)0x45,  /* [4358] */
    (xdc_Char)0x5f,  /* [4359] */
    (xdc_Char)0x62,  /* [4360] */
    (xdc_Char)0x61,  /* [4361] */
    (xdc_Char)0x64,  /* [4362] */
    (xdc_Char)0x43,  /* [4363] */
    (xdc_Char)0x6f,  /* [4364] */
    (xdc_Char)0x6d,  /* [4365] */
    (xdc_Char)0x6d,  /* [4366] */
    (xdc_Char)0x61,  /* [4367] */
    (xdc_Char)0x6e,  /* [4368] */
    (xdc_Char)0x64,  /* [4369] */
    (xdc_Char)0x3a,  /* [4370] */
    (xdc_Char)0x20,  /* [4371] */
    (xdc_Char)0x52,  /* [4372] */
    (xdc_Char)0x65,  /* [4373] */
    (xdc_Char)0x63,  /* [4374] */
    (xdc_Char)0x65,  /* [4375] */
    (xdc_Char)0x69,  /* [4376] */
    (xdc_Char)0x76,  /* [4377] */
    (xdc_Char)0x65,  /* [4378] */
    (xdc_Char)0x64,  /* [4379] */
    (xdc_Char)0x20,  /* [4380] */
    (xdc_Char)0x69,  /* [4381] */
    (xdc_Char)0x6e,  /* [4382] */
    (xdc_Char)0x76,  /* [4383] */
    (xdc_Char)0x61,  /* [4384] */
    (xdc_Char)0x6c,  /* [4385] */
    (xdc_Char)0x69,  /* [4386] */
    (xdc_Char)0x64,  /* [4387] */
    (xdc_Char)0x20,  /* [4388] */
    (xdc_Char)0x63,  /* [4389] */
    (xdc_Char)0x6f,  /* [4390] */
    (xdc_Char)0x6d,  /* [4391] */
    (xdc_Char)0x6d,  /* [4392] */
    (xdc_Char)0x61,  /* [4393] */
    (xdc_Char)0x6e,  /* [4394] */
    (xdc_Char)0x64,  /* [4395] */
    (xdc_Char)0x2c,  /* [4396] */
    (xdc_Char)0x20,  /* [4397] */
    (xdc_Char)0x69,  /* [4398] */
    (xdc_Char)0x64,  /* [4399] */
    (xdc_Char)0x3a,  /* [4400] */
    (xdc_Char)0x20,  /* [4401] */
    (xdc_Char)0x25,  /* [4402] */
    (xdc_Char)0x64,  /* [4403] */
    (xdc_Char)0x2e,  /* [4404] */
    (xdc_Char)0x0,  /* [4405] */
    (xdc_Char)0x45,  /* [4406] */
    (xdc_Char)0x5f,  /* [4407] */
    (xdc_Char)0x75,  /* [4408] */
    (xdc_Char)0x6e,  /* [4409] */
    (xdc_Char)0x70,  /* [4410] */
    (xdc_Char)0x6c,  /* [4411] */
    (xdc_Char)0x75,  /* [4412] */
    (xdc_Char)0x67,  /* [4413] */
    (xdc_Char)0x67,  /* [4414] */
    (xdc_Char)0x65,  /* [4415] */
    (xdc_Char)0x64,  /* [4416] */
    (xdc_Char)0x45,  /* [4417] */
    (xdc_Char)0x76,  /* [4418] */
    (xdc_Char)0x65,  /* [4419] */
    (xdc_Char)0x6e,  /* [4420] */
    (xdc_Char)0x74,  /* [4421] */
    (xdc_Char)0x3a,  /* [4422] */
    (xdc_Char)0x20,  /* [4423] */
    (xdc_Char)0x45,  /* [4424] */
    (xdc_Char)0x76,  /* [4425] */
    (xdc_Char)0x65,  /* [4426] */
    (xdc_Char)0x6e,  /* [4427] */
    (xdc_Char)0x74,  /* [4428] */
    (xdc_Char)0x23,  /* [4429] */
    (xdc_Char)0x20,  /* [4430] */
    (xdc_Char)0x25,  /* [4431] */
    (xdc_Char)0x64,  /* [4432] */
    (xdc_Char)0x20,  /* [4433] */
    (xdc_Char)0x69,  /* [4434] */
    (xdc_Char)0x73,  /* [4435] */
    (xdc_Char)0x20,  /* [4436] */
    (xdc_Char)0x75,  /* [4437] */
    (xdc_Char)0x6e,  /* [4438] */
    (xdc_Char)0x70,  /* [4439] */
    (xdc_Char)0x6c,  /* [4440] */
    (xdc_Char)0x75,  /* [4441] */
    (xdc_Char)0x67,  /* [4442] */
    (xdc_Char)0x67,  /* [4443] */
    (xdc_Char)0x65,  /* [4444] */
    (xdc_Char)0x64,  /* [4445] */
    (xdc_Char)0x0,  /* [4446] */
    (xdc_Char)0x45,  /* [4447] */
    (xdc_Char)0x5f,  /* [4448] */
    (xdc_Char)0x65,  /* [4449] */
    (xdc_Char)0x78,  /* [4450] */
    (xdc_Char)0x63,  /* [4451] */
    (xdc_Char)0x65,  /* [4452] */
    (xdc_Char)0x70,  /* [4453] */
    (xdc_Char)0x74,  /* [4454] */
    (xdc_Char)0x69,  /* [4455] */
    (xdc_Char)0x6f,  /* [4456] */
    (xdc_Char)0x6e,  /* [4457] */
    (xdc_Char)0x4d,  /* [4458] */
    (xdc_Char)0x69,  /* [4459] */
    (xdc_Char)0x6e,  /* [4460] */
    (xdc_Char)0x3a,  /* [4461] */
    (xdc_Char)0x20,  /* [4462] */
    (xdc_Char)0x70,  /* [4463] */
    (xdc_Char)0x63,  /* [4464] */
    (xdc_Char)0x20,  /* [4465] */
    (xdc_Char)0x3d,  /* [4466] */
    (xdc_Char)0x20,  /* [4467] */
    (xdc_Char)0x30,  /* [4468] */
    (xdc_Char)0x78,  /* [4469] */
    (xdc_Char)0x25,  /* [4470] */
    (xdc_Char)0x30,  /* [4471] */
    (xdc_Char)0x38,  /* [4472] */
    (xdc_Char)0x78,  /* [4473] */
    (xdc_Char)0x2c,  /* [4474] */
    (xdc_Char)0x20,  /* [4475] */
    (xdc_Char)0x73,  /* [4476] */
    (xdc_Char)0x70,  /* [4477] */
    (xdc_Char)0x20,  /* [4478] */
    (xdc_Char)0x3d,  /* [4479] */
    (xdc_Char)0x20,  /* [4480] */
    (xdc_Char)0x30,  /* [4481] */
    (xdc_Char)0x78,  /* [4482] */
    (xdc_Char)0x25,  /* [4483] */
    (xdc_Char)0x30,  /* [4484] */
    (xdc_Char)0x38,  /* [4485] */
    (xdc_Char)0x78,  /* [4486] */
    (xdc_Char)0x2e,  /* [4487] */
    (xdc_Char)0xa,  /* [4488] */
    (xdc_Char)0x54,  /* [4489] */
    (xdc_Char)0x6f,  /* [4490] */
    (xdc_Char)0x20,  /* [4491] */
    (xdc_Char)0x73,  /* [4492] */
    (xdc_Char)0x65,  /* [4493] */
    (xdc_Char)0x65,  /* [4494] */
    (xdc_Char)0x20,  /* [4495] */
    (xdc_Char)0x6d,  /* [4496] */
    (xdc_Char)0x6f,  /* [4497] */
    (xdc_Char)0x72,  /* [4498] */
    (xdc_Char)0x65,  /* [4499] */
    (xdc_Char)0x20,  /* [4500] */
    (xdc_Char)0x65,  /* [4501] */
    (xdc_Char)0x78,  /* [4502] */
    (xdc_Char)0x63,  /* [4503] */
    (xdc_Char)0x65,  /* [4504] */
    (xdc_Char)0x70,  /* [4505] */
    (xdc_Char)0x74,  /* [4506] */
    (xdc_Char)0x69,  /* [4507] */
    (xdc_Char)0x6f,  /* [4508] */
    (xdc_Char)0x6e,  /* [4509] */
    (xdc_Char)0x20,  /* [4510] */
    (xdc_Char)0x64,  /* [4511] */
    (xdc_Char)0x65,  /* [4512] */
    (xdc_Char)0x74,  /* [4513] */
    (xdc_Char)0x61,  /* [4514] */
    (xdc_Char)0x69,  /* [4515] */
    (xdc_Char)0x6c,  /* [4516] */
    (xdc_Char)0x2c,  /* [4517] */
    (xdc_Char)0x20,  /* [4518] */
    (xdc_Char)0x75,  /* [4519] */
    (xdc_Char)0x73,  /* [4520] */
    (xdc_Char)0x65,  /* [4521] */
    (xdc_Char)0x20,  /* [4522] */
    (xdc_Char)0x52,  /* [4523] */
    (xdc_Char)0x4f,  /* [4524] */
    (xdc_Char)0x56,  /* [4525] */
    (xdc_Char)0x20,  /* [4526] */
    (xdc_Char)0x6f,  /* [4527] */
    (xdc_Char)0x72,  /* [4528] */
    (xdc_Char)0x20,  /* [4529] */
    (xdc_Char)0x73,  /* [4530] */
    (xdc_Char)0x65,  /* [4531] */
    (xdc_Char)0x74,  /* [4532] */
    (xdc_Char)0x20,  /* [4533] */
    (xdc_Char)0x27,  /* [4534] */
    (xdc_Char)0x74,  /* [4535] */
    (xdc_Char)0x69,  /* [4536] */
    (xdc_Char)0x2e,  /* [4537] */
    (xdc_Char)0x73,  /* [4538] */
    (xdc_Char)0x79,  /* [4539] */
    (xdc_Char)0x73,  /* [4540] */
    (xdc_Char)0x62,  /* [4541] */
    (xdc_Char)0x69,  /* [4542] */
    (xdc_Char)0x6f,  /* [4543] */
    (xdc_Char)0x73,  /* [4544] */
    (xdc_Char)0x2e,  /* [4545] */
    (xdc_Char)0x66,  /* [4546] */
    (xdc_Char)0x61,  /* [4547] */
    (xdc_Char)0x6d,  /* [4548] */
    (xdc_Char)0x69,  /* [4549] */
    (xdc_Char)0x6c,  /* [4550] */
    (xdc_Char)0x79,  /* [4551] */
    (xdc_Char)0x2e,  /* [4552] */
    (xdc_Char)0x63,  /* [4553] */
    (xdc_Char)0x36,  /* [4554] */
    (xdc_Char)0x34,  /* [4555] */
    (xdc_Char)0x70,  /* [4556] */
    (xdc_Char)0x2e,  /* [4557] */
    (xdc_Char)0x45,  /* [4558] */
    (xdc_Char)0x78,  /* [4559] */
    (xdc_Char)0x63,  /* [4560] */
    (xdc_Char)0x65,  /* [4561] */
    (xdc_Char)0x70,  /* [4562] */
    (xdc_Char)0x74,  /* [4563] */
    (xdc_Char)0x69,  /* [4564] */
    (xdc_Char)0x6f,  /* [4565] */
    (xdc_Char)0x6e,  /* [4566] */
    (xdc_Char)0x2e,  /* [4567] */
    (xdc_Char)0x65,  /* [4568] */
    (xdc_Char)0x6e,  /* [4569] */
    (xdc_Char)0x61,  /* [4570] */
    (xdc_Char)0x62,  /* [4571] */
    (xdc_Char)0x6c,  /* [4572] */
    (xdc_Char)0x65,  /* [4573] */
    (xdc_Char)0x50,  /* [4574] */
    (xdc_Char)0x72,  /* [4575] */
    (xdc_Char)0x69,  /* [4576] */
    (xdc_Char)0x6e,  /* [4577] */
    (xdc_Char)0x74,  /* [4578] */
    (xdc_Char)0x20,  /* [4579] */
    (xdc_Char)0x3d,  /* [4580] */
    (xdc_Char)0x20,  /* [4581] */
    (xdc_Char)0x74,  /* [4582] */
    (xdc_Char)0x72,  /* [4583] */
    (xdc_Char)0x75,  /* [4584] */
    (xdc_Char)0x65,  /* [4585] */
    (xdc_Char)0x3b,  /* [4586] */
    (xdc_Char)0x27,  /* [4587] */
    (xdc_Char)0x0,  /* [4588] */
    (xdc_Char)0x45,  /* [4589] */
    (xdc_Char)0x5f,  /* [4590] */
    (xdc_Char)0x65,  /* [4591] */
    (xdc_Char)0x78,  /* [4592] */
    (xdc_Char)0x63,  /* [4593] */
    (xdc_Char)0x65,  /* [4594] */
    (xdc_Char)0x70,  /* [4595] */
    (xdc_Char)0x74,  /* [4596] */
    (xdc_Char)0x69,  /* [4597] */
    (xdc_Char)0x6f,  /* [4598] */
    (xdc_Char)0x6e,  /* [4599] */
    (xdc_Char)0x4d,  /* [4600] */
    (xdc_Char)0x61,  /* [4601] */
    (xdc_Char)0x78,  /* [4602] */
    (xdc_Char)0x3a,  /* [4603] */
    (xdc_Char)0x20,  /* [4604] */
    (xdc_Char)0x70,  /* [4605] */
    (xdc_Char)0x63,  /* [4606] */
    (xdc_Char)0x20,  /* [4607] */
    (xdc_Char)0x3d,  /* [4608] */
    (xdc_Char)0x20,  /* [4609] */
    (xdc_Char)0x30,  /* [4610] */
    (xdc_Char)0x78,  /* [4611] */
    (xdc_Char)0x25,  /* [4612] */
    (xdc_Char)0x30,  /* [4613] */
    (xdc_Char)0x38,  /* [4614] */
    (xdc_Char)0x78,  /* [4615] */
    (xdc_Char)0x2c,  /* [4616] */
    (xdc_Char)0x20,  /* [4617] */
    (xdc_Char)0x73,  /* [4618] */
    (xdc_Char)0x70,  /* [4619] */
    (xdc_Char)0x20,  /* [4620] */
    (xdc_Char)0x3d,  /* [4621] */
    (xdc_Char)0x20,  /* [4622] */
    (xdc_Char)0x30,  /* [4623] */
    (xdc_Char)0x78,  /* [4624] */
    (xdc_Char)0x25,  /* [4625] */
    (xdc_Char)0x30,  /* [4626] */
    (xdc_Char)0x38,  /* [4627] */
    (xdc_Char)0x78,  /* [4628] */
    (xdc_Char)0x2e,  /* [4629] */
    (xdc_Char)0x0,  /* [4630] */
    (xdc_Char)0x45,  /* [4631] */
    (xdc_Char)0x5f,  /* [4632] */
    (xdc_Char)0x61,  /* [4633] */
    (xdc_Char)0x6c,  /* [4634] */
    (xdc_Char)0x72,  /* [4635] */
    (xdc_Char)0x65,  /* [4636] */
    (xdc_Char)0x61,  /* [4637] */
    (xdc_Char)0x64,  /* [4638] */
    (xdc_Char)0x79,  /* [4639] */
    (xdc_Char)0x44,  /* [4640] */
    (xdc_Char)0x65,  /* [4641] */
    (xdc_Char)0x66,  /* [4642] */
    (xdc_Char)0x69,  /* [4643] */
    (xdc_Char)0x6e,  /* [4644] */
    (xdc_Char)0x65,  /* [4645] */
    (xdc_Char)0x64,  /* [4646] */
    (xdc_Char)0x3a,  /* [4647] */
    (xdc_Char)0x20,  /* [4648] */
    (xdc_Char)0x48,  /* [4649] */
    (xdc_Char)0x77,  /* [4650] */
    (xdc_Char)0x69,  /* [4651] */
    (xdc_Char)0x20,  /* [4652] */
    (xdc_Char)0x61,  /* [4653] */
    (xdc_Char)0x6c,  /* [4654] */
    (xdc_Char)0x72,  /* [4655] */
    (xdc_Char)0x65,  /* [4656] */
    (xdc_Char)0x61,  /* [4657] */
    (xdc_Char)0x64,  /* [4658] */
    (xdc_Char)0x79,  /* [4659] */
    (xdc_Char)0x20,  /* [4660] */
    (xdc_Char)0x64,  /* [4661] */
    (xdc_Char)0x65,  /* [4662] */
    (xdc_Char)0x66,  /* [4663] */
    (xdc_Char)0x69,  /* [4664] */
    (xdc_Char)0x6e,  /* [4665] */
    (xdc_Char)0x65,  /* [4666] */
    (xdc_Char)0x64,  /* [4667] */
    (xdc_Char)0x3a,  /* [4668] */
    (xdc_Char)0x20,  /* [4669] */
    (xdc_Char)0x69,  /* [4670] */
    (xdc_Char)0x6e,  /* [4671] */
    (xdc_Char)0x74,  /* [4672] */
    (xdc_Char)0x72,  /* [4673] */
    (xdc_Char)0x23,  /* [4674] */
    (xdc_Char)0x20,  /* [4675] */
    (xdc_Char)0x25,  /* [4676] */
    (xdc_Char)0x64,  /* [4677] */
    (xdc_Char)0x0,  /* [4678] */
    (xdc_Char)0x45,  /* [4679] */
    (xdc_Char)0x5f,  /* [4680] */
    (xdc_Char)0x68,  /* [4681] */
    (xdc_Char)0x61,  /* [4682] */
    (xdc_Char)0x6e,  /* [4683] */
    (xdc_Char)0x64,  /* [4684] */
    (xdc_Char)0x6c,  /* [4685] */
    (xdc_Char)0x65,  /* [4686] */
    (xdc_Char)0x4e,  /* [4687] */
    (xdc_Char)0x6f,  /* [4688] */
    (xdc_Char)0x74,  /* [4689] */
    (xdc_Char)0x46,  /* [4690] */
    (xdc_Char)0x6f,  /* [4691] */
    (xdc_Char)0x75,  /* [4692] */
    (xdc_Char)0x6e,  /* [4693] */
    (xdc_Char)0x64,  /* [4694] */
    (xdc_Char)0x3a,  /* [4695] */
    (xdc_Char)0x20,  /* [4696] */
    (xdc_Char)0x48,  /* [4697] */
    (xdc_Char)0x77,  /* [4698] */
    (xdc_Char)0x69,  /* [4699] */
    (xdc_Char)0x20,  /* [4700] */
    (xdc_Char)0x68,  /* [4701] */
    (xdc_Char)0x61,  /* [4702] */
    (xdc_Char)0x6e,  /* [4703] */
    (xdc_Char)0x64,  /* [4704] */
    (xdc_Char)0x6c,  /* [4705] */
    (xdc_Char)0x65,  /* [4706] */
    (xdc_Char)0x20,  /* [4707] */
    (xdc_Char)0x6e,  /* [4708] */
    (xdc_Char)0x6f,  /* [4709] */
    (xdc_Char)0x74,  /* [4710] */
    (xdc_Char)0x20,  /* [4711] */
    (xdc_Char)0x66,  /* [4712] */
    (xdc_Char)0x6f,  /* [4713] */
    (xdc_Char)0x75,  /* [4714] */
    (xdc_Char)0x6e,  /* [4715] */
    (xdc_Char)0x64,  /* [4716] */
    (xdc_Char)0x3a,  /* [4717] */
    (xdc_Char)0x20,  /* [4718] */
    (xdc_Char)0x30,  /* [4719] */
    (xdc_Char)0x78,  /* [4720] */
    (xdc_Char)0x25,  /* [4721] */
    (xdc_Char)0x78,  /* [4722] */
    (xdc_Char)0x0,  /* [4723] */
    (xdc_Char)0x45,  /* [4724] */
    (xdc_Char)0x5f,  /* [4725] */
    (xdc_Char)0x61,  /* [4726] */
    (xdc_Char)0x6c,  /* [4727] */
    (xdc_Char)0x6c,  /* [4728] */
    (xdc_Char)0x6f,  /* [4729] */
    (xdc_Char)0x63,  /* [4730] */
    (xdc_Char)0x53,  /* [4731] */
    (xdc_Char)0x43,  /* [4732] */
    (xdc_Char)0x46,  /* [4733] */
    (xdc_Char)0x61,  /* [4734] */
    (xdc_Char)0x69,  /* [4735] */
    (xdc_Char)0x6c,  /* [4736] */
    (xdc_Char)0x65,  /* [4737] */
    (xdc_Char)0x64,  /* [4738] */
    (xdc_Char)0x3a,  /* [4739] */
    (xdc_Char)0x20,  /* [4740] */
    (xdc_Char)0x41,  /* [4741] */
    (xdc_Char)0x6c,  /* [4742] */
    (xdc_Char)0x6c,  /* [4743] */
    (xdc_Char)0x6f,  /* [4744] */
    (xdc_Char)0x63,  /* [4745] */
    (xdc_Char)0x20,  /* [4746] */
    (xdc_Char)0x73,  /* [4747] */
    (xdc_Char)0x65,  /* [4748] */
    (xdc_Char)0x63,  /* [4749] */
    (xdc_Char)0x75,  /* [4750] */
    (xdc_Char)0x72,  /* [4751] */
    (xdc_Char)0x65,  /* [4752] */
    (xdc_Char)0x20,  /* [4753] */
    (xdc_Char)0x63,  /* [4754] */
    (xdc_Char)0x6f,  /* [4755] */
    (xdc_Char)0x6e,  /* [4756] */
    (xdc_Char)0x74,  /* [4757] */
    (xdc_Char)0x65,  /* [4758] */
    (xdc_Char)0x78,  /* [4759] */
    (xdc_Char)0x74,  /* [4760] */
    (xdc_Char)0x20,  /* [4761] */
    (xdc_Char)0x66,  /* [4762] */
    (xdc_Char)0x61,  /* [4763] */
    (xdc_Char)0x69,  /* [4764] */
    (xdc_Char)0x6c,  /* [4765] */
    (xdc_Char)0x65,  /* [4766] */
    (xdc_Char)0x64,  /* [4767] */
    (xdc_Char)0x0,  /* [4768] */
    (xdc_Char)0x45,  /* [4769] */
    (xdc_Char)0x5f,  /* [4770] */
    (xdc_Char)0x72,  /* [4771] */
    (xdc_Char)0x65,  /* [4772] */
    (xdc_Char)0x67,  /* [4773] */
    (xdc_Char)0x69,  /* [4774] */
    (xdc_Char)0x73,  /* [4775] */
    (xdc_Char)0x74,  /* [4776] */
    (xdc_Char)0x65,  /* [4777] */
    (xdc_Char)0x72,  /* [4778] */
    (xdc_Char)0x53,  /* [4779] */
    (xdc_Char)0x43,  /* [4780] */
    (xdc_Char)0x46,  /* [4781] */
    (xdc_Char)0x61,  /* [4782] */
    (xdc_Char)0x69,  /* [4783] */
    (xdc_Char)0x6c,  /* [4784] */
    (xdc_Char)0x65,  /* [4785] */
    (xdc_Char)0x64,  /* [4786] */
    (xdc_Char)0x3a,  /* [4787] */
    (xdc_Char)0x20,  /* [4788] */
    (xdc_Char)0x52,  /* [4789] */
    (xdc_Char)0x65,  /* [4790] */
    (xdc_Char)0x67,  /* [4791] */
    (xdc_Char)0x69,  /* [4792] */
    (xdc_Char)0x73,  /* [4793] */
    (xdc_Char)0x74,  /* [4794] */
    (xdc_Char)0x65,  /* [4795] */
    (xdc_Char)0x72,  /* [4796] */
    (xdc_Char)0x20,  /* [4797] */
    (xdc_Char)0x73,  /* [4798] */
    (xdc_Char)0x65,  /* [4799] */
    (xdc_Char)0x63,  /* [4800] */
    (xdc_Char)0x75,  /* [4801] */
    (xdc_Char)0x72,  /* [4802] */
    (xdc_Char)0x65,  /* [4803] */
    (xdc_Char)0x20,  /* [4804] */
    (xdc_Char)0x63,  /* [4805] */
    (xdc_Char)0x6f,  /* [4806] */
    (xdc_Char)0x6e,  /* [4807] */
    (xdc_Char)0x74,  /* [4808] */
    (xdc_Char)0x65,  /* [4809] */
    (xdc_Char)0x78,  /* [4810] */
    (xdc_Char)0x74,  /* [4811] */
    (xdc_Char)0x20,  /* [4812] */
    (xdc_Char)0x66,  /* [4813] */
    (xdc_Char)0x61,  /* [4814] */
    (xdc_Char)0x69,  /* [4815] */
    (xdc_Char)0x6c,  /* [4816] */
    (xdc_Char)0x65,  /* [4817] */
    (xdc_Char)0x64,  /* [4818] */
    (xdc_Char)0x0,  /* [4819] */
    (xdc_Char)0x45,  /* [4820] */
    (xdc_Char)0x5f,  /* [4821] */
    (xdc_Char)0x69,  /* [4822] */
    (xdc_Char)0x6e,  /* [4823] */
    (xdc_Char)0x76,  /* [4824] */
    (xdc_Char)0x61,  /* [4825] */
    (xdc_Char)0x6c,  /* [4826] */
    (xdc_Char)0x69,  /* [4827] */
    (xdc_Char)0x64,  /* [4828] */
    (xdc_Char)0x49,  /* [4829] */
    (xdc_Char)0x6e,  /* [4830] */
    (xdc_Char)0x74,  /* [4831] */
    (xdc_Char)0x4e,  /* [4832] */
    (xdc_Char)0x75,  /* [4833] */
    (xdc_Char)0x6d,  /* [4834] */
    (xdc_Char)0x3a,  /* [4835] */
    (xdc_Char)0x20,  /* [4836] */
    (xdc_Char)0x49,  /* [4837] */
    (xdc_Char)0x6e,  /* [4838] */
    (xdc_Char)0x76,  /* [4839] */
    (xdc_Char)0x61,  /* [4840] */
    (xdc_Char)0x6c,  /* [4841] */
    (xdc_Char)0x69,  /* [4842] */
    (xdc_Char)0x64,  /* [4843] */
    (xdc_Char)0x20,  /* [4844] */
    (xdc_Char)0x69,  /* [4845] */
    (xdc_Char)0x6e,  /* [4846] */
    (xdc_Char)0x74,  /* [4847] */
    (xdc_Char)0x65,  /* [4848] */
    (xdc_Char)0x72,  /* [4849] */
    (xdc_Char)0x72,  /* [4850] */
    (xdc_Char)0x75,  /* [4851] */
    (xdc_Char)0x70,  /* [4852] */
    (xdc_Char)0x74,  /* [4853] */
    (xdc_Char)0x20,  /* [4854] */
    (xdc_Char)0x6e,  /* [4855] */
    (xdc_Char)0x75,  /* [4856] */
    (xdc_Char)0x6d,  /* [4857] */
    (xdc_Char)0x62,  /* [4858] */
    (xdc_Char)0x65,  /* [4859] */
    (xdc_Char)0x72,  /* [4860] */
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
    (xdc_Char)0x69,  /* [4874] */
    (xdc_Char)0x6e,  /* [4875] */
    (xdc_Char)0x76,  /* [4876] */
    (xdc_Char)0x61,  /* [4877] */
    (xdc_Char)0x6c,  /* [4878] */
    (xdc_Char)0x69,  /* [4879] */
    (xdc_Char)0x64,  /* [4880] */
    (xdc_Char)0x4c,  /* [4881] */
    (xdc_Char)0x31,  /* [4882] */
    (xdc_Char)0x43,  /* [4883] */
    (xdc_Char)0x61,  /* [4884] */
    (xdc_Char)0x63,  /* [4885] */
    (xdc_Char)0x68,  /* [4886] */
    (xdc_Char)0x65,  /* [4887] */
    (xdc_Char)0x53,  /* [4888] */
    (xdc_Char)0x69,  /* [4889] */
    (xdc_Char)0x7a,  /* [4890] */
    (xdc_Char)0x65,  /* [4891] */
    (xdc_Char)0x3a,  /* [4892] */
    (xdc_Char)0x20,  /* [4893] */
    (xdc_Char)0x49,  /* [4894] */
    (xdc_Char)0x6e,  /* [4895] */
    (xdc_Char)0x76,  /* [4896] */
    (xdc_Char)0x61,  /* [4897] */
    (xdc_Char)0x6c,  /* [4898] */
    (xdc_Char)0x69,  /* [4899] */
    (xdc_Char)0x64,  /* [4900] */
    (xdc_Char)0x20,  /* [4901] */
    (xdc_Char)0x4c,  /* [4902] */
    (xdc_Char)0x31,  /* [4903] */
    (xdc_Char)0x20,  /* [4904] */
    (xdc_Char)0x63,  /* [4905] */
    (xdc_Char)0x61,  /* [4906] */
    (xdc_Char)0x63,  /* [4907] */
    (xdc_Char)0x68,  /* [4908] */
    (xdc_Char)0x65,  /* [4909] */
    (xdc_Char)0x20,  /* [4910] */
    (xdc_Char)0x73,  /* [4911] */
    (xdc_Char)0x69,  /* [4912] */
    (xdc_Char)0x7a,  /* [4913] */
    (xdc_Char)0x65,  /* [4914] */
    (xdc_Char)0x20,  /* [4915] */
    (xdc_Char)0x25,  /* [4916] */
    (xdc_Char)0x64,  /* [4917] */
    (xdc_Char)0x0,  /* [4918] */
    (xdc_Char)0x45,  /* [4919] */
    (xdc_Char)0x5f,  /* [4920] */
    (xdc_Char)0x69,  /* [4921] */
    (xdc_Char)0x6e,  /* [4922] */
    (xdc_Char)0x76,  /* [4923] */
    (xdc_Char)0x61,  /* [4924] */
    (xdc_Char)0x6c,  /* [4925] */
    (xdc_Char)0x69,  /* [4926] */
    (xdc_Char)0x64,  /* [4927] */
    (xdc_Char)0x4c,  /* [4928] */
    (xdc_Char)0x32,  /* [4929] */
    (xdc_Char)0x43,  /* [4930] */
    (xdc_Char)0x61,  /* [4931] */
    (xdc_Char)0x63,  /* [4932] */
    (xdc_Char)0x68,  /* [4933] */
    (xdc_Char)0x65,  /* [4934] */
    (xdc_Char)0x53,  /* [4935] */
    (xdc_Char)0x69,  /* [4936] */
    (xdc_Char)0x7a,  /* [4937] */
    (xdc_Char)0x65,  /* [4938] */
    (xdc_Char)0x3a,  /* [4939] */
    (xdc_Char)0x20,  /* [4940] */
    (xdc_Char)0x49,  /* [4941] */
    (xdc_Char)0x6e,  /* [4942] */
    (xdc_Char)0x76,  /* [4943] */
    (xdc_Char)0x61,  /* [4944] */
    (xdc_Char)0x6c,  /* [4945] */
    (xdc_Char)0x69,  /* [4946] */
    (xdc_Char)0x64,  /* [4947] */
    (xdc_Char)0x20,  /* [4948] */
    (xdc_Char)0x4c,  /* [4949] */
    (xdc_Char)0x32,  /* [4950] */
    (xdc_Char)0x20,  /* [4951] */
    (xdc_Char)0x63,  /* [4952] */
    (xdc_Char)0x61,  /* [4953] */
    (xdc_Char)0x63,  /* [4954] */
    (xdc_Char)0x68,  /* [4955] */
    (xdc_Char)0x65,  /* [4956] */
    (xdc_Char)0x20,  /* [4957] */
    (xdc_Char)0x73,  /* [4958] */
    (xdc_Char)0x69,  /* [4959] */
    (xdc_Char)0x7a,  /* [4960] */
    (xdc_Char)0x65,  /* [4961] */
    (xdc_Char)0x20,  /* [4962] */
    (xdc_Char)0x25,  /* [4963] */
    (xdc_Char)0x64,  /* [4964] */
    (xdc_Char)0x0,  /* [4965] */
    (xdc_Char)0x45,  /* [4966] */
    (xdc_Char)0x5f,  /* [4967] */
    (xdc_Char)0x73,  /* [4968] */
    (xdc_Char)0x74,  /* [4969] */
    (xdc_Char)0x61,  /* [4970] */
    (xdc_Char)0x63,  /* [4971] */
    (xdc_Char)0x6b,  /* [4972] */
    (xdc_Char)0x4f,  /* [4973] */
    (xdc_Char)0x76,  /* [4974] */
    (xdc_Char)0x65,  /* [4975] */
    (xdc_Char)0x72,  /* [4976] */
    (xdc_Char)0x66,  /* [4977] */
    (xdc_Char)0x6c,  /* [4978] */
    (xdc_Char)0x6f,  /* [4979] */
    (xdc_Char)0x77,  /* [4980] */
    (xdc_Char)0x3a,  /* [4981] */
    (xdc_Char)0x20,  /* [4982] */
    (xdc_Char)0x54,  /* [4983] */
    (xdc_Char)0x61,  /* [4984] */
    (xdc_Char)0x73,  /* [4985] */
    (xdc_Char)0x6b,  /* [4986] */
    (xdc_Char)0x20,  /* [4987] */
    (xdc_Char)0x30,  /* [4988] */
    (xdc_Char)0x78,  /* [4989] */
    (xdc_Char)0x25,  /* [4990] */
    (xdc_Char)0x78,  /* [4991] */
    (xdc_Char)0x20,  /* [4992] */
    (xdc_Char)0x73,  /* [4993] */
    (xdc_Char)0x74,  /* [4994] */
    (xdc_Char)0x61,  /* [4995] */
    (xdc_Char)0x63,  /* [4996] */
    (xdc_Char)0x6b,  /* [4997] */
    (xdc_Char)0x20,  /* [4998] */
    (xdc_Char)0x6f,  /* [4999] */
    (xdc_Char)0x76,  /* [5000] */
    (xdc_Char)0x65,  /* [5001] */
    (xdc_Char)0x72,  /* [5002] */
    (xdc_Char)0x66,  /* [5003] */
    (xdc_Char)0x6c,  /* [5004] */
    (xdc_Char)0x6f,  /* [5005] */
    (xdc_Char)0x77,  /* [5006] */
    (xdc_Char)0x2e,  /* [5007] */
    (xdc_Char)0x0,  /* [5008] */
    (xdc_Char)0x45,  /* [5009] */
    (xdc_Char)0x5f,  /* [5010] */
    (xdc_Char)0x73,  /* [5011] */
    (xdc_Char)0x70,  /* [5012] */
    (xdc_Char)0x4f,  /* [5013] */
    (xdc_Char)0x75,  /* [5014] */
    (xdc_Char)0x74,  /* [5015] */
    (xdc_Char)0x4f,  /* [5016] */
    (xdc_Char)0x66,  /* [5017] */
    (xdc_Char)0x42,  /* [5018] */
    (xdc_Char)0x6f,  /* [5019] */
    (xdc_Char)0x75,  /* [5020] */
    (xdc_Char)0x6e,  /* [5021] */
    (xdc_Char)0x64,  /* [5022] */
    (xdc_Char)0x73,  /* [5023] */
    (xdc_Char)0x3a,  /* [5024] */
    (xdc_Char)0x20,  /* [5025] */
    (xdc_Char)0x54,  /* [5026] */
    (xdc_Char)0x61,  /* [5027] */
    (xdc_Char)0x73,  /* [5028] */
    (xdc_Char)0x6b,  /* [5029] */
    (xdc_Char)0x20,  /* [5030] */
    (xdc_Char)0x30,  /* [5031] */
    (xdc_Char)0x78,  /* [5032] */
    (xdc_Char)0x25,  /* [5033] */
    (xdc_Char)0x78,  /* [5034] */
    (xdc_Char)0x20,  /* [5035] */
    (xdc_Char)0x73,  /* [5036] */
    (xdc_Char)0x74,  /* [5037] */
    (xdc_Char)0x61,  /* [5038] */
    (xdc_Char)0x63,  /* [5039] */
    (xdc_Char)0x6b,  /* [5040] */
    (xdc_Char)0x20,  /* [5041] */
    (xdc_Char)0x65,  /* [5042] */
    (xdc_Char)0x72,  /* [5043] */
    (xdc_Char)0x72,  /* [5044] */
    (xdc_Char)0x6f,  /* [5045] */
    (xdc_Char)0x72,  /* [5046] */
    (xdc_Char)0x2c,  /* [5047] */
    (xdc_Char)0x20,  /* [5048] */
    (xdc_Char)0x53,  /* [5049] */
    (xdc_Char)0x50,  /* [5050] */
    (xdc_Char)0x20,  /* [5051] */
    (xdc_Char)0x3d,  /* [5052] */
    (xdc_Char)0x20,  /* [5053] */
    (xdc_Char)0x30,  /* [5054] */
    (xdc_Char)0x78,  /* [5055] */
    (xdc_Char)0x25,  /* [5056] */
    (xdc_Char)0x78,  /* [5057] */
    (xdc_Char)0x2e,  /* [5058] */
    (xdc_Char)0x0,  /* [5059] */
    (xdc_Char)0x45,  /* [5060] */
    (xdc_Char)0x5f,  /* [5061] */
    (xdc_Char)0x64,  /* [5062] */
    (xdc_Char)0x65,  /* [5063] */
    (xdc_Char)0x6c,  /* [5064] */
    (xdc_Char)0x65,  /* [5065] */
    (xdc_Char)0x74,  /* [5066] */
    (xdc_Char)0x65,  /* [5067] */
    (xdc_Char)0x4e,  /* [5068] */
    (xdc_Char)0x6f,  /* [5069] */
    (xdc_Char)0x74,  /* [5070] */
    (xdc_Char)0x41,  /* [5071] */
    (xdc_Char)0x6c,  /* [5072] */
    (xdc_Char)0x6c,  /* [5073] */
    (xdc_Char)0x6f,  /* [5074] */
    (xdc_Char)0x77,  /* [5075] */
    (xdc_Char)0x65,  /* [5076] */
    (xdc_Char)0x64,  /* [5077] */
    (xdc_Char)0x3a,  /* [5078] */
    (xdc_Char)0x20,  /* [5079] */
    (xdc_Char)0x54,  /* [5080] */
    (xdc_Char)0x61,  /* [5081] */
    (xdc_Char)0x73,  /* [5082] */
    (xdc_Char)0x6b,  /* [5083] */
    (xdc_Char)0x20,  /* [5084] */
    (xdc_Char)0x30,  /* [5085] */
    (xdc_Char)0x78,  /* [5086] */
    (xdc_Char)0x25,  /* [5087] */
    (xdc_Char)0x78,  /* [5088] */
    (xdc_Char)0x2e,  /* [5089] */
    (xdc_Char)0x0,  /* [5090] */
    (xdc_Char)0x45,  /* [5091] */
    (xdc_Char)0x5f,  /* [5092] */
    (xdc_Char)0x6d,  /* [5093] */
    (xdc_Char)0x6f,  /* [5094] */
    (xdc_Char)0x64,  /* [5095] */
    (xdc_Char)0x75,  /* [5096] */
    (xdc_Char)0x6c,  /* [5097] */
    (xdc_Char)0x65,  /* [5098] */
    (xdc_Char)0x53,  /* [5099] */
    (xdc_Char)0x74,  /* [5100] */
    (xdc_Char)0x61,  /* [5101] */
    (xdc_Char)0x74,  /* [5102] */
    (xdc_Char)0x65,  /* [5103] */
    (xdc_Char)0x43,  /* [5104] */
    (xdc_Char)0x68,  /* [5105] */
    (xdc_Char)0x65,  /* [5106] */
    (xdc_Char)0x63,  /* [5107] */
    (xdc_Char)0x6b,  /* [5108] */
    (xdc_Char)0x46,  /* [5109] */
    (xdc_Char)0x61,  /* [5110] */
    (xdc_Char)0x69,  /* [5111] */
    (xdc_Char)0x6c,  /* [5112] */
    (xdc_Char)0x65,  /* [5113] */
    (xdc_Char)0x64,  /* [5114] */
    (xdc_Char)0x3a,  /* [5115] */
    (xdc_Char)0x20,  /* [5116] */
    (xdc_Char)0x54,  /* [5117] */
    (xdc_Char)0x61,  /* [5118] */
    (xdc_Char)0x73,  /* [5119] */
    (xdc_Char)0x6b,  /* [5120] */
    (xdc_Char)0x20,  /* [5121] */
    (xdc_Char)0x6d,  /* [5122] */
    (xdc_Char)0x6f,  /* [5123] */
    (xdc_Char)0x64,  /* [5124] */
    (xdc_Char)0x75,  /* [5125] */
    (xdc_Char)0x6c,  /* [5126] */
    (xdc_Char)0x65,  /* [5127] */
    (xdc_Char)0x20,  /* [5128] */
    (xdc_Char)0x73,  /* [5129] */
    (xdc_Char)0x74,  /* [5130] */
    (xdc_Char)0x61,  /* [5131] */
    (xdc_Char)0x74,  /* [5132] */
    (xdc_Char)0x65,  /* [5133] */
    (xdc_Char)0x20,  /* [5134] */
    (xdc_Char)0x64,  /* [5135] */
    (xdc_Char)0x61,  /* [5136] */
    (xdc_Char)0x74,  /* [5137] */
    (xdc_Char)0x61,  /* [5138] */
    (xdc_Char)0x20,  /* [5139] */
    (xdc_Char)0x69,  /* [5140] */
    (xdc_Char)0x6e,  /* [5141] */
    (xdc_Char)0x74,  /* [5142] */
    (xdc_Char)0x65,  /* [5143] */
    (xdc_Char)0x67,  /* [5144] */
    (xdc_Char)0x72,  /* [5145] */
    (xdc_Char)0x69,  /* [5146] */
    (xdc_Char)0x74,  /* [5147] */
    (xdc_Char)0x79,  /* [5148] */
    (xdc_Char)0x20,  /* [5149] */
    (xdc_Char)0x63,  /* [5150] */
    (xdc_Char)0x68,  /* [5151] */
    (xdc_Char)0x65,  /* [5152] */
    (xdc_Char)0x63,  /* [5153] */
    (xdc_Char)0x6b,  /* [5154] */
    (xdc_Char)0x20,  /* [5155] */
    (xdc_Char)0x66,  /* [5156] */
    (xdc_Char)0x61,  /* [5157] */
    (xdc_Char)0x69,  /* [5158] */
    (xdc_Char)0x6c,  /* [5159] */
    (xdc_Char)0x65,  /* [5160] */
    (xdc_Char)0x64,  /* [5161] */
    (xdc_Char)0x2e,  /* [5162] */
    (xdc_Char)0x0,  /* [5163] */
    (xdc_Char)0x45,  /* [5164] */
    (xdc_Char)0x5f,  /* [5165] */
    (xdc_Char)0x6f,  /* [5166] */
    (xdc_Char)0x62,  /* [5167] */
    (xdc_Char)0x6a,  /* [5168] */
    (xdc_Char)0x65,  /* [5169] */
    (xdc_Char)0x63,  /* [5170] */
    (xdc_Char)0x74,  /* [5171] */
    (xdc_Char)0x43,  /* [5172] */
    (xdc_Char)0x68,  /* [5173] */
    (xdc_Char)0x65,  /* [5174] */
    (xdc_Char)0x63,  /* [5175] */
    (xdc_Char)0x6b,  /* [5176] */
    (xdc_Char)0x46,  /* [5177] */
    (xdc_Char)0x61,  /* [5178] */
    (xdc_Char)0x69,  /* [5179] */
    (xdc_Char)0x6c,  /* [5180] */
    (xdc_Char)0x65,  /* [5181] */
    (xdc_Char)0x64,  /* [5182] */
    (xdc_Char)0x3a,  /* [5183] */
    (xdc_Char)0x20,  /* [5184] */
    (xdc_Char)0x54,  /* [5185] */
    (xdc_Char)0x61,  /* [5186] */
    (xdc_Char)0x73,  /* [5187] */
    (xdc_Char)0x6b,  /* [5188] */
    (xdc_Char)0x20,  /* [5189] */
    (xdc_Char)0x30,  /* [5190] */
    (xdc_Char)0x78,  /* [5191] */
    (xdc_Char)0x25,  /* [5192] */
    (xdc_Char)0x78,  /* [5193] */
    (xdc_Char)0x20,  /* [5194] */
    (xdc_Char)0x6f,  /* [5195] */
    (xdc_Char)0x62,  /* [5196] */
    (xdc_Char)0x6a,  /* [5197] */
    (xdc_Char)0x65,  /* [5198] */
    (xdc_Char)0x63,  /* [5199] */
    (xdc_Char)0x74,  /* [5200] */
    (xdc_Char)0x20,  /* [5201] */
    (xdc_Char)0x64,  /* [5202] */
    (xdc_Char)0x61,  /* [5203] */
    (xdc_Char)0x74,  /* [5204] */
    (xdc_Char)0x61,  /* [5205] */
    (xdc_Char)0x20,  /* [5206] */
    (xdc_Char)0x69,  /* [5207] */
    (xdc_Char)0x6e,  /* [5208] */
    (xdc_Char)0x74,  /* [5209] */
    (xdc_Char)0x65,  /* [5210] */
    (xdc_Char)0x67,  /* [5211] */
    (xdc_Char)0x72,  /* [5212] */
    (xdc_Char)0x69,  /* [5213] */
    (xdc_Char)0x74,  /* [5214] */
    (xdc_Char)0x79,  /* [5215] */
    (xdc_Char)0x20,  /* [5216] */
    (xdc_Char)0x63,  /* [5217] */
    (xdc_Char)0x68,  /* [5218] */
    (xdc_Char)0x65,  /* [5219] */
    (xdc_Char)0x63,  /* [5220] */
    (xdc_Char)0x6b,  /* [5221] */
    (xdc_Char)0x20,  /* [5222] */
    (xdc_Char)0x66,  /* [5223] */
    (xdc_Char)0x61,  /* [5224] */
    (xdc_Char)0x69,  /* [5225] */
    (xdc_Char)0x6c,  /* [5226] */
    (xdc_Char)0x65,  /* [5227] */
    (xdc_Char)0x64,  /* [5228] */
    (xdc_Char)0x2e,  /* [5229] */
    (xdc_Char)0x0,  /* [5230] */
    (xdc_Char)0x45,  /* [5231] */
    (xdc_Char)0x5f,  /* [5232] */
    (xdc_Char)0x73,  /* [5233] */
    (xdc_Char)0x74,  /* [5234] */
    (xdc_Char)0x61,  /* [5235] */
    (xdc_Char)0x63,  /* [5236] */
    (xdc_Char)0x6b,  /* [5237] */
    (xdc_Char)0x4f,  /* [5238] */
    (xdc_Char)0x76,  /* [5239] */
    (xdc_Char)0x65,  /* [5240] */
    (xdc_Char)0x72,  /* [5241] */
    (xdc_Char)0x66,  /* [5242] */
    (xdc_Char)0x6c,  /* [5243] */
    (xdc_Char)0x6f,  /* [5244] */
    (xdc_Char)0x77,  /* [5245] */
    (xdc_Char)0x3a,  /* [5246] */
    (xdc_Char)0x20,  /* [5247] */
    (xdc_Char)0x49,  /* [5248] */
    (xdc_Char)0x53,  /* [5249] */
    (xdc_Char)0x52,  /* [5250] */
    (xdc_Char)0x20,  /* [5251] */
    (xdc_Char)0x73,  /* [5252] */
    (xdc_Char)0x74,  /* [5253] */
    (xdc_Char)0x61,  /* [5254] */
    (xdc_Char)0x63,  /* [5255] */
    (xdc_Char)0x6b,  /* [5256] */
    (xdc_Char)0x20,  /* [5257] */
    (xdc_Char)0x6f,  /* [5258] */
    (xdc_Char)0x76,  /* [5259] */
    (xdc_Char)0x65,  /* [5260] */
    (xdc_Char)0x72,  /* [5261] */
    (xdc_Char)0x66,  /* [5262] */
    (xdc_Char)0x6c,  /* [5263] */
    (xdc_Char)0x6f,  /* [5264] */
    (xdc_Char)0x77,  /* [5265] */
    (xdc_Char)0x2e,  /* [5266] */
    (xdc_Char)0x0,  /* [5267] */
    (xdc_Char)0x45,  /* [5268] */
    (xdc_Char)0x5f,  /* [5269] */
    (xdc_Char)0x69,  /* [5270] */
    (xdc_Char)0x6e,  /* [5271] */
    (xdc_Char)0x76,  /* [5272] */
    (xdc_Char)0x61,  /* [5273] */
    (xdc_Char)0x6c,  /* [5274] */
    (xdc_Char)0x69,  /* [5275] */
    (xdc_Char)0x64,  /* [5276] */
    (xdc_Char)0x54,  /* [5277] */
    (xdc_Char)0x69,  /* [5278] */
    (xdc_Char)0x6d,  /* [5279] */
    (xdc_Char)0x65,  /* [5280] */
    (xdc_Char)0x72,  /* [5281] */
    (xdc_Char)0x3a,  /* [5282] */
    (xdc_Char)0x20,  /* [5283] */
    (xdc_Char)0x49,  /* [5284] */
    (xdc_Char)0x6e,  /* [5285] */
    (xdc_Char)0x76,  /* [5286] */
    (xdc_Char)0x61,  /* [5287] */
    (xdc_Char)0x6c,  /* [5288] */
    (xdc_Char)0x69,  /* [5289] */
    (xdc_Char)0x64,  /* [5290] */
    (xdc_Char)0x20,  /* [5291] */
    (xdc_Char)0x54,  /* [5292] */
    (xdc_Char)0x69,  /* [5293] */
    (xdc_Char)0x6d,  /* [5294] */
    (xdc_Char)0x65,  /* [5295] */
    (xdc_Char)0x72,  /* [5296] */
    (xdc_Char)0x20,  /* [5297] */
    (xdc_Char)0x49,  /* [5298] */
    (xdc_Char)0x64,  /* [5299] */
    (xdc_Char)0x20,  /* [5300] */
    (xdc_Char)0x25,  /* [5301] */
    (xdc_Char)0x64,  /* [5302] */
    (xdc_Char)0x0,  /* [5303] */
    (xdc_Char)0x45,  /* [5304] */
    (xdc_Char)0x5f,  /* [5305] */
    (xdc_Char)0x6e,  /* [5306] */
    (xdc_Char)0x6f,  /* [5307] */
    (xdc_Char)0x74,  /* [5308] */
    (xdc_Char)0x41,  /* [5309] */
    (xdc_Char)0x76,  /* [5310] */
    (xdc_Char)0x61,  /* [5311] */
    (xdc_Char)0x69,  /* [5312] */
    (xdc_Char)0x6c,  /* [5313] */
    (xdc_Char)0x61,  /* [5314] */
    (xdc_Char)0x62,  /* [5315] */
    (xdc_Char)0x6c,  /* [5316] */
    (xdc_Char)0x65,  /* [5317] */
    (xdc_Char)0x3a,  /* [5318] */
    (xdc_Char)0x20,  /* [5319] */
    (xdc_Char)0x54,  /* [5320] */
    (xdc_Char)0x69,  /* [5321] */
    (xdc_Char)0x6d,  /* [5322] */
    (xdc_Char)0x65,  /* [5323] */
    (xdc_Char)0x72,  /* [5324] */
    (xdc_Char)0x20,  /* [5325] */
    (xdc_Char)0x6e,  /* [5326] */
    (xdc_Char)0x6f,  /* [5327] */
    (xdc_Char)0x74,  /* [5328] */
    (xdc_Char)0x20,  /* [5329] */
    (xdc_Char)0x61,  /* [5330] */
    (xdc_Char)0x76,  /* [5331] */
    (xdc_Char)0x61,  /* [5332] */
    (xdc_Char)0x69,  /* [5333] */
    (xdc_Char)0x6c,  /* [5334] */
    (xdc_Char)0x61,  /* [5335] */
    (xdc_Char)0x62,  /* [5336] */
    (xdc_Char)0x6c,  /* [5337] */
    (xdc_Char)0x65,  /* [5338] */
    (xdc_Char)0x20,  /* [5339] */
    (xdc_Char)0x25,  /* [5340] */
    (xdc_Char)0x64,  /* [5341] */
    (xdc_Char)0x0,  /* [5342] */
    (xdc_Char)0x45,  /* [5343] */
    (xdc_Char)0x5f,  /* [5344] */
    (xdc_Char)0x63,  /* [5345] */
    (xdc_Char)0x61,  /* [5346] */
    (xdc_Char)0x6e,  /* [5347] */
    (xdc_Char)0x6e,  /* [5348] */
    (xdc_Char)0x6f,  /* [5349] */
    (xdc_Char)0x74,  /* [5350] */
    (xdc_Char)0x53,  /* [5351] */
    (xdc_Char)0x75,  /* [5352] */
    (xdc_Char)0x70,  /* [5353] */
    (xdc_Char)0x70,  /* [5354] */
    (xdc_Char)0x6f,  /* [5355] */
    (xdc_Char)0x72,  /* [5356] */
    (xdc_Char)0x74,  /* [5357] */
    (xdc_Char)0x3a,  /* [5358] */
    (xdc_Char)0x20,  /* [5359] */
    (xdc_Char)0x54,  /* [5360] */
    (xdc_Char)0x69,  /* [5361] */
    (xdc_Char)0x6d,  /* [5362] */
    (xdc_Char)0x65,  /* [5363] */
    (xdc_Char)0x72,  /* [5364] */
    (xdc_Char)0x20,  /* [5365] */
    (xdc_Char)0x63,  /* [5366] */
    (xdc_Char)0x61,  /* [5367] */
    (xdc_Char)0x6e,  /* [5368] */
    (xdc_Char)0x6e,  /* [5369] */
    (xdc_Char)0x6f,  /* [5370] */
    (xdc_Char)0x74,  /* [5371] */
    (xdc_Char)0x20,  /* [5372] */
    (xdc_Char)0x73,  /* [5373] */
    (xdc_Char)0x75,  /* [5374] */
    (xdc_Char)0x70,  /* [5375] */
    (xdc_Char)0x70,  /* [5376] */
    (xdc_Char)0x6f,  /* [5377] */
    (xdc_Char)0x72,  /* [5378] */
    (xdc_Char)0x74,  /* [5379] */
    (xdc_Char)0x20,  /* [5380] */
    (xdc_Char)0x72,  /* [5381] */
    (xdc_Char)0x65,  /* [5382] */
    (xdc_Char)0x71,  /* [5383] */
    (xdc_Char)0x75,  /* [5384] */
    (xdc_Char)0x65,  /* [5385] */
    (xdc_Char)0x73,  /* [5386] */
    (xdc_Char)0x74,  /* [5387] */
    (xdc_Char)0x65,  /* [5388] */
    (xdc_Char)0x64,  /* [5389] */
    (xdc_Char)0x20,  /* [5390] */
    (xdc_Char)0x70,  /* [5391] */
    (xdc_Char)0x65,  /* [5392] */
    (xdc_Char)0x72,  /* [5393] */
    (xdc_Char)0x69,  /* [5394] */
    (xdc_Char)0x6f,  /* [5395] */
    (xdc_Char)0x64,  /* [5396] */
    (xdc_Char)0x20,  /* [5397] */
    (xdc_Char)0x25,  /* [5398] */
    (xdc_Char)0x64,  /* [5399] */
    (xdc_Char)0x0,  /* [5400] */
    (xdc_Char)0x45,  /* [5401] */
    (xdc_Char)0x5f,  /* [5402] */
    (xdc_Char)0x66,  /* [5403] */
    (xdc_Char)0x72,  /* [5404] */
    (xdc_Char)0x65,  /* [5405] */
    (xdc_Char)0x71,  /* [5406] */
    (xdc_Char)0x4d,  /* [5407] */
    (xdc_Char)0x69,  /* [5408] */
    (xdc_Char)0x73,  /* [5409] */
    (xdc_Char)0x6d,  /* [5410] */
    (xdc_Char)0x61,  /* [5411] */
    (xdc_Char)0x74,  /* [5412] */
    (xdc_Char)0x63,  /* [5413] */
    (xdc_Char)0x68,  /* [5414] */
    (xdc_Char)0x3a,  /* [5415] */
    (xdc_Char)0x20,  /* [5416] */
    (xdc_Char)0x46,  /* [5417] */
    (xdc_Char)0x72,  /* [5418] */
    (xdc_Char)0x65,  /* [5419] */
    (xdc_Char)0x71,  /* [5420] */
    (xdc_Char)0x75,  /* [5421] */
    (xdc_Char)0x65,  /* [5422] */
    (xdc_Char)0x6e,  /* [5423] */
    (xdc_Char)0x63,  /* [5424] */
    (xdc_Char)0x79,  /* [5425] */
    (xdc_Char)0x20,  /* [5426] */
    (xdc_Char)0x6d,  /* [5427] */
    (xdc_Char)0x69,  /* [5428] */
    (xdc_Char)0x73,  /* [5429] */
    (xdc_Char)0x6d,  /* [5430] */
    (xdc_Char)0x61,  /* [5431] */
    (xdc_Char)0x74,  /* [5432] */
    (xdc_Char)0x63,  /* [5433] */
    (xdc_Char)0x68,  /* [5434] */
    (xdc_Char)0x3a,  /* [5435] */
    (xdc_Char)0x20,  /* [5436] */
    (xdc_Char)0x45,  /* [5437] */
    (xdc_Char)0x78,  /* [5438] */
    (xdc_Char)0x70,  /* [5439] */
    (xdc_Char)0x65,  /* [5440] */
    (xdc_Char)0x63,  /* [5441] */
    (xdc_Char)0x74,  /* [5442] */
    (xdc_Char)0x65,  /* [5443] */
    (xdc_Char)0x64,  /* [5444] */
    (xdc_Char)0x20,  /* [5445] */
    (xdc_Char)0x25,  /* [5446] */
    (xdc_Char)0x64,  /* [5447] */
    (xdc_Char)0x20,  /* [5448] */
    (xdc_Char)0x48,  /* [5449] */
    (xdc_Char)0x7a,  /* [5450] */
    (xdc_Char)0x2c,  /* [5451] */
    (xdc_Char)0x20,  /* [5452] */
    (xdc_Char)0x61,  /* [5453] */
    (xdc_Char)0x63,  /* [5454] */
    (xdc_Char)0x74,  /* [5455] */
    (xdc_Char)0x75,  /* [5456] */
    (xdc_Char)0x61,  /* [5457] */
    (xdc_Char)0x6c,  /* [5458] */
    (xdc_Char)0x3a,  /* [5459] */
    (xdc_Char)0x20,  /* [5460] */
    (xdc_Char)0x25,  /* [5461] */
    (xdc_Char)0x64,  /* [5462] */
    (xdc_Char)0x20,  /* [5463] */
    (xdc_Char)0x48,  /* [5464] */
    (xdc_Char)0x7a,  /* [5465] */
    (xdc_Char)0x2e,  /* [5466] */
    (xdc_Char)0x20,  /* [5467] */
    (xdc_Char)0x20,  /* [5468] */
    (xdc_Char)0x59,  /* [5469] */
    (xdc_Char)0x6f,  /* [5470] */
    (xdc_Char)0x75,  /* [5471] */
    (xdc_Char)0x20,  /* [5472] */
    (xdc_Char)0x6e,  /* [5473] */
    (xdc_Char)0x65,  /* [5474] */
    (xdc_Char)0x65,  /* [5475] */
    (xdc_Char)0x64,  /* [5476] */
    (xdc_Char)0x20,  /* [5477] */
    (xdc_Char)0x74,  /* [5478] */
    (xdc_Char)0x6f,  /* [5479] */
    (xdc_Char)0x20,  /* [5480] */
    (xdc_Char)0x6d,  /* [5481] */
    (xdc_Char)0x6f,  /* [5482] */
    (xdc_Char)0x64,  /* [5483] */
    (xdc_Char)0x69,  /* [5484] */
    (xdc_Char)0x66,  /* [5485] */
    (xdc_Char)0x79,  /* [5486] */
    (xdc_Char)0x20,  /* [5487] */
    (xdc_Char)0x54,  /* [5488] */
    (xdc_Char)0x69,  /* [5489] */
    (xdc_Char)0x6d,  /* [5490] */
    (xdc_Char)0x65,  /* [5491] */
    (xdc_Char)0x72,  /* [5492] */
    (xdc_Char)0x2e,  /* [5493] */
    (xdc_Char)0x69,  /* [5494] */
    (xdc_Char)0x6e,  /* [5495] */
    (xdc_Char)0x74,  /* [5496] */
    (xdc_Char)0x46,  /* [5497] */
    (xdc_Char)0x72,  /* [5498] */
    (xdc_Char)0x65,  /* [5499] */
    (xdc_Char)0x71,  /* [5500] */
    (xdc_Char)0x2e,  /* [5501] */
    (xdc_Char)0x6c,  /* [5502] */
    (xdc_Char)0x6f,  /* [5503] */
    (xdc_Char)0x20,  /* [5504] */
    (xdc_Char)0x74,  /* [5505] */
    (xdc_Char)0x6f,  /* [5506] */
    (xdc_Char)0x20,  /* [5507] */
    (xdc_Char)0x6d,  /* [5508] */
    (xdc_Char)0x61,  /* [5509] */
    (xdc_Char)0x74,  /* [5510] */
    (xdc_Char)0x63,  /* [5511] */
    (xdc_Char)0x68,  /* [5512] */
    (xdc_Char)0x20,  /* [5513] */
    (xdc_Char)0x74,  /* [5514] */
    (xdc_Char)0x68,  /* [5515] */
    (xdc_Char)0x65,  /* [5516] */
    (xdc_Char)0x20,  /* [5517] */
    (xdc_Char)0x61,  /* [5518] */
    (xdc_Char)0x63,  /* [5519] */
    (xdc_Char)0x74,  /* [5520] */
    (xdc_Char)0x75,  /* [5521] */
    (xdc_Char)0x61,  /* [5522] */
    (xdc_Char)0x6c,  /* [5523] */
    (xdc_Char)0x20,  /* [5524] */
    (xdc_Char)0x66,  /* [5525] */
    (xdc_Char)0x72,  /* [5526] */
    (xdc_Char)0x65,  /* [5527] */
    (xdc_Char)0x71,  /* [5528] */
    (xdc_Char)0x75,  /* [5529] */
    (xdc_Char)0x65,  /* [5530] */
    (xdc_Char)0x6e,  /* [5531] */
    (xdc_Char)0x63,  /* [5532] */
    (xdc_Char)0x79,  /* [5533] */
    (xdc_Char)0x2e,  /* [5534] */
    (xdc_Char)0x0,  /* [5535] */
    (xdc_Char)0x45,  /* [5536] */
    (xdc_Char)0x5f,  /* [5537] */
    (xdc_Char)0x62,  /* [5538] */
    (xdc_Char)0x61,  /* [5539] */
    (xdc_Char)0x64,  /* [5540] */
    (xdc_Char)0x49,  /* [5541] */
    (xdc_Char)0x6e,  /* [5542] */
    (xdc_Char)0x74,  /* [5543] */
    (xdc_Char)0x4e,  /* [5544] */
    (xdc_Char)0x75,  /* [5545] */
    (xdc_Char)0x6d,  /* [5546] */
    (xdc_Char)0x3a,  /* [5547] */
    (xdc_Char)0x20,  /* [5548] */
    (xdc_Char)0x54,  /* [5549] */
    (xdc_Char)0x69,  /* [5550] */
    (xdc_Char)0x6d,  /* [5551] */
    (xdc_Char)0x65,  /* [5552] */
    (xdc_Char)0x72,  /* [5553] */
    (xdc_Char)0x20,  /* [5554] */
    (xdc_Char)0x72,  /* [5555] */
    (xdc_Char)0x65,  /* [5556] */
    (xdc_Char)0x71,  /* [5557] */
    (xdc_Char)0x75,  /* [5558] */
    (xdc_Char)0x69,  /* [5559] */
    (xdc_Char)0x72,  /* [5560] */
    (xdc_Char)0x65,  /* [5561] */
    (xdc_Char)0x73,  /* [5562] */
    (xdc_Char)0x20,  /* [5563] */
    (xdc_Char)0x61,  /* [5564] */
    (xdc_Char)0x20,  /* [5565] */
    (xdc_Char)0x76,  /* [5566] */
    (xdc_Char)0x61,  /* [5567] */
    (xdc_Char)0x6c,  /* [5568] */
    (xdc_Char)0x69,  /* [5569] */
    (xdc_Char)0x64,  /* [5570] */
    (xdc_Char)0x20,  /* [5571] */
    (xdc_Char)0x69,  /* [5572] */
    (xdc_Char)0x6e,  /* [5573] */
    (xdc_Char)0x74,  /* [5574] */
    (xdc_Char)0x4e,  /* [5575] */
    (xdc_Char)0x75,  /* [5576] */
    (xdc_Char)0x6d,  /* [5577] */
    (xdc_Char)0x2e,  /* [5578] */
    (xdc_Char)0x20,  /* [5579] */
    (xdc_Char)0x50,  /* [5580] */
    (xdc_Char)0x6c,  /* [5581] */
    (xdc_Char)0x65,  /* [5582] */
    (xdc_Char)0x61,  /* [5583] */
    (xdc_Char)0x73,  /* [5584] */
    (xdc_Char)0x65,  /* [5585] */
    (xdc_Char)0x20,  /* [5586] */
    (xdc_Char)0x75,  /* [5587] */
    (xdc_Char)0x73,  /* [5588] */
    (xdc_Char)0x65,  /* [5589] */
    (xdc_Char)0x20,  /* [5590] */
    (xdc_Char)0x44,  /* [5591] */
    (xdc_Char)0x4d,  /* [5592] */
    (xdc_Char)0x54,  /* [5593] */
    (xdc_Char)0x69,  /* [5594] */
    (xdc_Char)0x6d,  /* [5595] */
    (xdc_Char)0x65,  /* [5596] */
    (xdc_Char)0x72,  /* [5597] */
    (xdc_Char)0x20,  /* [5598] */
    (xdc_Char)0x6d,  /* [5599] */
    (xdc_Char)0x6f,  /* [5600] */
    (xdc_Char)0x64,  /* [5601] */
    (xdc_Char)0x75,  /* [5602] */
    (xdc_Char)0x6c,  /* [5603] */
    (xdc_Char)0x65,  /* [5604] */
    (xdc_Char)0x27,  /* [5605] */
    (xdc_Char)0x73,  /* [5606] */
    (xdc_Char)0x20,  /* [5607] */
    (xdc_Char)0x74,  /* [5608] */
    (xdc_Char)0x69,  /* [5609] */
    (xdc_Char)0x6d,  /* [5610] */
    (xdc_Char)0x65,  /* [5611] */
    (xdc_Char)0x72,  /* [5612] */
    (xdc_Char)0x53,  /* [5613] */
    (xdc_Char)0x65,  /* [5614] */
    (xdc_Char)0x74,  /* [5615] */
    (xdc_Char)0x74,  /* [5616] */
    (xdc_Char)0x69,  /* [5617] */
    (xdc_Char)0x6e,  /* [5618] */
    (xdc_Char)0x67,  /* [5619] */
    (xdc_Char)0x73,  /* [5620] */
    (xdc_Char)0x20,  /* [5621] */
    (xdc_Char)0x63,  /* [5622] */
    (xdc_Char)0x6f,  /* [5623] */
    (xdc_Char)0x6e,  /* [5624] */
    (xdc_Char)0x66,  /* [5625] */
    (xdc_Char)0x69,  /* [5626] */
    (xdc_Char)0x67,  /* [5627] */
    (xdc_Char)0x20,  /* [5628] */
    (xdc_Char)0x70,  /* [5629] */
    (xdc_Char)0x61,  /* [5630] */
    (xdc_Char)0x72,  /* [5631] */
    (xdc_Char)0x61,  /* [5632] */
    (xdc_Char)0x6d,  /* [5633] */
    (xdc_Char)0x20,  /* [5634] */
    (xdc_Char)0x74,  /* [5635] */
    (xdc_Char)0x6f,  /* [5636] */
    (xdc_Char)0x20,  /* [5637] */
    (xdc_Char)0x61,  /* [5638] */
    (xdc_Char)0x73,  /* [5639] */
    (xdc_Char)0x73,  /* [5640] */
    (xdc_Char)0x69,  /* [5641] */
    (xdc_Char)0x67,  /* [5642] */
    (xdc_Char)0x6e,  /* [5643] */
    (xdc_Char)0x20,  /* [5644] */
    (xdc_Char)0x61,  /* [5645] */
    (xdc_Char)0x20,  /* [5646] */
    (xdc_Char)0x76,  /* [5647] */
    (xdc_Char)0x61,  /* [5648] */
    (xdc_Char)0x6c,  /* [5649] */
    (xdc_Char)0x69,  /* [5650] */
    (xdc_Char)0x64,  /* [5651] */
    (xdc_Char)0x20,  /* [5652] */
    (xdc_Char)0x69,  /* [5653] */
    (xdc_Char)0x6e,  /* [5654] */
    (xdc_Char)0x74,  /* [5655] */
    (xdc_Char)0x4e,  /* [5656] */
    (xdc_Char)0x75,  /* [5657] */
    (xdc_Char)0x6d,  /* [5658] */
    (xdc_Char)0x20,  /* [5659] */
    (xdc_Char)0x66,  /* [5660] */
    (xdc_Char)0x6f,  /* [5661] */
    (xdc_Char)0x72,  /* [5662] */
    (xdc_Char)0x20,  /* [5663] */
    (xdc_Char)0x74,  /* [5664] */
    (xdc_Char)0x68,  /* [5665] */
    (xdc_Char)0x65,  /* [5666] */
    (xdc_Char)0x20,  /* [5667] */
    (xdc_Char)0x73,  /* [5668] */
    (xdc_Char)0x65,  /* [5669] */
    (xdc_Char)0x6c,  /* [5670] */
    (xdc_Char)0x65,  /* [5671] */
    (xdc_Char)0x63,  /* [5672] */
    (xdc_Char)0x74,  /* [5673] */
    (xdc_Char)0x65,  /* [5674] */
    (xdc_Char)0x64,  /* [5675] */
    (xdc_Char)0x20,  /* [5676] */
    (xdc_Char)0x74,  /* [5677] */
    (xdc_Char)0x69,  /* [5678] */
    (xdc_Char)0x6d,  /* [5679] */
    (xdc_Char)0x65,  /* [5680] */
    (xdc_Char)0x72,  /* [5681] */
    (xdc_Char)0x2e,  /* [5682] */
    (xdc_Char)0x0,  /* [5683] */
    (xdc_Char)0x45,  /* [5684] */
    (xdc_Char)0x5f,  /* [5685] */
    (xdc_Char)0x70,  /* [5686] */
    (xdc_Char)0x72,  /* [5687] */
    (xdc_Char)0x69,  /* [5688] */
    (xdc_Char)0x6f,  /* [5689] */
    (xdc_Char)0x72,  /* [5690] */
    (xdc_Char)0x69,  /* [5691] */
    (xdc_Char)0x74,  /* [5692] */
    (xdc_Char)0x79,  /* [5693] */
    (xdc_Char)0x3a,  /* [5694] */
    (xdc_Char)0x20,  /* [5695] */
    (xdc_Char)0x54,  /* [5696] */
    (xdc_Char)0x68,  /* [5697] */
    (xdc_Char)0x72,  /* [5698] */
    (xdc_Char)0x65,  /* [5699] */
    (xdc_Char)0x61,  /* [5700] */
    (xdc_Char)0x64,  /* [5701] */
    (xdc_Char)0x20,  /* [5702] */
    (xdc_Char)0x70,  /* [5703] */
    (xdc_Char)0x72,  /* [5704] */
    (xdc_Char)0x69,  /* [5705] */
    (xdc_Char)0x6f,  /* [5706] */
    (xdc_Char)0x72,  /* [5707] */
    (xdc_Char)0x69,  /* [5708] */
    (xdc_Char)0x74,  /* [5709] */
    (xdc_Char)0x79,  /* [5710] */
    (xdc_Char)0x20,  /* [5711] */
    (xdc_Char)0x69,  /* [5712] */
    (xdc_Char)0x73,  /* [5713] */
    (xdc_Char)0x20,  /* [5714] */
    (xdc_Char)0x69,  /* [5715] */
    (xdc_Char)0x6e,  /* [5716] */
    (xdc_Char)0x76,  /* [5717] */
    (xdc_Char)0x61,  /* [5718] */
    (xdc_Char)0x6c,  /* [5719] */
    (xdc_Char)0x69,  /* [5720] */
    (xdc_Char)0x64,  /* [5721] */
    (xdc_Char)0x20,  /* [5722] */
    (xdc_Char)0x25,  /* [5723] */
    (xdc_Char)0x64,  /* [5724] */
    (xdc_Char)0x0,  /* [5725] */
    (xdc_Char)0x72,  /* [5726] */
    (xdc_Char)0x65,  /* [5727] */
    (xdc_Char)0x71,  /* [5728] */
    (xdc_Char)0x75,  /* [5729] */
    (xdc_Char)0x65,  /* [5730] */
    (xdc_Char)0x73,  /* [5731] */
    (xdc_Char)0x74,  /* [5732] */
    (xdc_Char)0x65,  /* [5733] */
    (xdc_Char)0x64,  /* [5734] */
    (xdc_Char)0x20,  /* [5735] */
    (xdc_Char)0x73,  /* [5736] */
    (xdc_Char)0x69,  /* [5737] */
    (xdc_Char)0x7a,  /* [5738] */
    (xdc_Char)0x65,  /* [5739] */
    (xdc_Char)0x20,  /* [5740] */
    (xdc_Char)0x69,  /* [5741] */
    (xdc_Char)0x73,  /* [5742] */
    (xdc_Char)0x20,  /* [5743] */
    (xdc_Char)0x74,  /* [5744] */
    (xdc_Char)0x6f,  /* [5745] */
    (xdc_Char)0x6f,  /* [5746] */
    (xdc_Char)0x20,  /* [5747] */
    (xdc_Char)0x62,  /* [5748] */
    (xdc_Char)0x69,  /* [5749] */
    (xdc_Char)0x67,  /* [5750] */
    (xdc_Char)0x3a,  /* [5751] */
    (xdc_Char)0x20,  /* [5752] */
    (xdc_Char)0x68,  /* [5753] */
    (xdc_Char)0x61,  /* [5754] */
    (xdc_Char)0x6e,  /* [5755] */
    (xdc_Char)0x64,  /* [5756] */
    (xdc_Char)0x6c,  /* [5757] */
    (xdc_Char)0x65,  /* [5758] */
    (xdc_Char)0x3d,  /* [5759] */
    (xdc_Char)0x30,  /* [5760] */
    (xdc_Char)0x78,  /* [5761] */
    (xdc_Char)0x25,  /* [5762] */
    (xdc_Char)0x78,  /* [5763] */
    (xdc_Char)0x2c,  /* [5764] */
    (xdc_Char)0x20,  /* [5765] */
    (xdc_Char)0x73,  /* [5766] */
    (xdc_Char)0x69,  /* [5767] */
    (xdc_Char)0x7a,  /* [5768] */
    (xdc_Char)0x65,  /* [5769] */
    (xdc_Char)0x3d,  /* [5770] */
    (xdc_Char)0x25,  /* [5771] */
    (xdc_Char)0x75,  /* [5772] */
    (xdc_Char)0x0,  /* [5773] */
    (xdc_Char)0x6f,  /* [5774] */
    (xdc_Char)0x75,  /* [5775] */
    (xdc_Char)0x74,  /* [5776] */
    (xdc_Char)0x20,  /* [5777] */
    (xdc_Char)0x6f,  /* [5778] */
    (xdc_Char)0x66,  /* [5779] */
    (xdc_Char)0x20,  /* [5780] */
    (xdc_Char)0x6d,  /* [5781] */
    (xdc_Char)0x65,  /* [5782] */
    (xdc_Char)0x6d,  /* [5783] */
    (xdc_Char)0x6f,  /* [5784] */
    (xdc_Char)0x72,  /* [5785] */
    (xdc_Char)0x79,  /* [5786] */
    (xdc_Char)0x3a,  /* [5787] */
    (xdc_Char)0x20,  /* [5788] */
    (xdc_Char)0x68,  /* [5789] */
    (xdc_Char)0x61,  /* [5790] */
    (xdc_Char)0x6e,  /* [5791] */
    (xdc_Char)0x64,  /* [5792] */
    (xdc_Char)0x6c,  /* [5793] */
    (xdc_Char)0x65,  /* [5794] */
    (xdc_Char)0x3d,  /* [5795] */
    (xdc_Char)0x30,  /* [5796] */
    (xdc_Char)0x78,  /* [5797] */
    (xdc_Char)0x25,  /* [5798] */
    (xdc_Char)0x78,  /* [5799] */
    (xdc_Char)0x2c,  /* [5800] */
    (xdc_Char)0x20,  /* [5801] */
    (xdc_Char)0x73,  /* [5802] */
    (xdc_Char)0x69,  /* [5803] */
    (xdc_Char)0x7a,  /* [5804] */
    (xdc_Char)0x65,  /* [5805] */
    (xdc_Char)0x3d,  /* [5806] */
    (xdc_Char)0x25,  /* [5807] */
    (xdc_Char)0x75,  /* [5808] */
    (xdc_Char)0x0,  /* [5809] */
    (xdc_Char)0x3c,  /* [5810] */
    (xdc_Char)0x2d,  /* [5811] */
    (xdc_Char)0x2d,  /* [5812] */
    (xdc_Char)0x20,  /* [5813] */
    (xdc_Char)0x63,  /* [5814] */
    (xdc_Char)0x6f,  /* [5815] */
    (xdc_Char)0x6e,  /* [5816] */
    (xdc_Char)0x73,  /* [5817] */
    (xdc_Char)0x74,  /* [5818] */
    (xdc_Char)0x72,  /* [5819] */
    (xdc_Char)0x75,  /* [5820] */
    (xdc_Char)0x63,  /* [5821] */
    (xdc_Char)0x74,  /* [5822] */
    (xdc_Char)0x3a,  /* [5823] */
    (xdc_Char)0x20,  /* [5824] */
    (xdc_Char)0x25,  /* [5825] */
    (xdc_Char)0x70,  /* [5826] */
    (xdc_Char)0x28,  /* [5827] */
    (xdc_Char)0x27,  /* [5828] */
    (xdc_Char)0x25,  /* [5829] */
    (xdc_Char)0x73,  /* [5830] */
    (xdc_Char)0x27,  /* [5831] */
    (xdc_Char)0x29,  /* [5832] */
    (xdc_Char)0x0,  /* [5833] */
    (xdc_Char)0x3c,  /* [5834] */
    (xdc_Char)0x2d,  /* [5835] */
    (xdc_Char)0x2d,  /* [5836] */
    (xdc_Char)0x20,  /* [5837] */
    (xdc_Char)0x63,  /* [5838] */
    (xdc_Char)0x72,  /* [5839] */
    (xdc_Char)0x65,  /* [5840] */
    (xdc_Char)0x61,  /* [5841] */
    (xdc_Char)0x74,  /* [5842] */
    (xdc_Char)0x65,  /* [5843] */
    (xdc_Char)0x3a,  /* [5844] */
    (xdc_Char)0x20,  /* [5845] */
    (xdc_Char)0x25,  /* [5846] */
    (xdc_Char)0x70,  /* [5847] */
    (xdc_Char)0x28,  /* [5848] */
    (xdc_Char)0x27,  /* [5849] */
    (xdc_Char)0x25,  /* [5850] */
    (xdc_Char)0x73,  /* [5851] */
    (xdc_Char)0x27,  /* [5852] */
    (xdc_Char)0x29,  /* [5853] */
    (xdc_Char)0x0,  /* [5854] */
    (xdc_Char)0x2d,  /* [5855] */
    (xdc_Char)0x2d,  /* [5856] */
    (xdc_Char)0x3e,  /* [5857] */
    (xdc_Char)0x20,  /* [5858] */
    (xdc_Char)0x64,  /* [5859] */
    (xdc_Char)0x65,  /* [5860] */
    (xdc_Char)0x73,  /* [5861] */
    (xdc_Char)0x74,  /* [5862] */
    (xdc_Char)0x72,  /* [5863] */
    (xdc_Char)0x75,  /* [5864] */
    (xdc_Char)0x63,  /* [5865] */
    (xdc_Char)0x74,  /* [5866] */
    (xdc_Char)0x3a,  /* [5867] */
    (xdc_Char)0x20,  /* [5868] */
    (xdc_Char)0x28,  /* [5869] */
    (xdc_Char)0x25,  /* [5870] */
    (xdc_Char)0x70,  /* [5871] */
    (xdc_Char)0x29,  /* [5872] */
    (xdc_Char)0x0,  /* [5873] */
    (xdc_Char)0x2d,  /* [5874] */
    (xdc_Char)0x2d,  /* [5875] */
    (xdc_Char)0x3e,  /* [5876] */
    (xdc_Char)0x20,  /* [5877] */
    (xdc_Char)0x64,  /* [5878] */
    (xdc_Char)0x65,  /* [5879] */
    (xdc_Char)0x6c,  /* [5880] */
    (xdc_Char)0x65,  /* [5881] */
    (xdc_Char)0x74,  /* [5882] */
    (xdc_Char)0x65,  /* [5883] */
    (xdc_Char)0x3a,  /* [5884] */
    (xdc_Char)0x20,  /* [5885] */
    (xdc_Char)0x28,  /* [5886] */
    (xdc_Char)0x25,  /* [5887] */
    (xdc_Char)0x70,  /* [5888] */
    (xdc_Char)0x29,  /* [5889] */
    (xdc_Char)0x0,  /* [5890] */
    (xdc_Char)0x45,  /* [5891] */
    (xdc_Char)0x52,  /* [5892] */
    (xdc_Char)0x52,  /* [5893] */
    (xdc_Char)0x4f,  /* [5894] */
    (xdc_Char)0x52,  /* [5895] */
    (xdc_Char)0x3a,  /* [5896] */
    (xdc_Char)0x20,  /* [5897] */
    (xdc_Char)0x25,  /* [5898] */
    (xdc_Char)0x24,  /* [5899] */
    (xdc_Char)0x46,  /* [5900] */
    (xdc_Char)0x25,  /* [5901] */
    (xdc_Char)0x24,  /* [5902] */
    (xdc_Char)0x53,  /* [5903] */
    (xdc_Char)0x0,  /* [5904] */
    (xdc_Char)0x57,  /* [5905] */
    (xdc_Char)0x41,  /* [5906] */
    (xdc_Char)0x52,  /* [5907] */
    (xdc_Char)0x4e,  /* [5908] */
    (xdc_Char)0x49,  /* [5909] */
    (xdc_Char)0x4e,  /* [5910] */
    (xdc_Char)0x47,  /* [5911] */
    (xdc_Char)0x3a,  /* [5912] */
    (xdc_Char)0x20,  /* [5913] */
    (xdc_Char)0x25,  /* [5914] */
    (xdc_Char)0x24,  /* [5915] */
    (xdc_Char)0x46,  /* [5916] */
    (xdc_Char)0x25,  /* [5917] */
    (xdc_Char)0x24,  /* [5918] */
    (xdc_Char)0x53,  /* [5919] */
    (xdc_Char)0x0,  /* [5920] */
    (xdc_Char)0x25,  /* [5921] */
    (xdc_Char)0x24,  /* [5922] */
    (xdc_Char)0x46,  /* [5923] */
    (xdc_Char)0x25,  /* [5924] */
    (xdc_Char)0x24,  /* [5925] */
    (xdc_Char)0x53,  /* [5926] */
    (xdc_Char)0x0,  /* [5927] */
    (xdc_Char)0x53,  /* [5928] */
    (xdc_Char)0x74,  /* [5929] */
    (xdc_Char)0x61,  /* [5930] */
    (xdc_Char)0x72,  /* [5931] */
    (xdc_Char)0x74,  /* [5932] */
    (xdc_Char)0x3a,  /* [5933] */
    (xdc_Char)0x20,  /* [5934] */
    (xdc_Char)0x25,  /* [5935] */
    (xdc_Char)0x24,  /* [5936] */
    (xdc_Char)0x53,  /* [5937] */
    (xdc_Char)0x0,  /* [5938] */
    (xdc_Char)0x53,  /* [5939] */
    (xdc_Char)0x74,  /* [5940] */
    (xdc_Char)0x6f,  /* [5941] */
    (xdc_Char)0x70,  /* [5942] */
    (xdc_Char)0x3a,  /* [5943] */
    (xdc_Char)0x20,  /* [5944] */
    (xdc_Char)0x25,  /* [5945] */
    (xdc_Char)0x24,  /* [5946] */
    (xdc_Char)0x53,  /* [5947] */
    (xdc_Char)0x0,  /* [5948] */
    (xdc_Char)0x53,  /* [5949] */
    (xdc_Char)0x74,  /* [5950] */
    (xdc_Char)0x61,  /* [5951] */
    (xdc_Char)0x72,  /* [5952] */
    (xdc_Char)0x74,  /* [5953] */
    (xdc_Char)0x49,  /* [5954] */
    (xdc_Char)0x6e,  /* [5955] */
    (xdc_Char)0x73,  /* [5956] */
    (xdc_Char)0x74,  /* [5957] */
    (xdc_Char)0x61,  /* [5958] */
    (xdc_Char)0x6e,  /* [5959] */
    (xdc_Char)0x63,  /* [5960] */
    (xdc_Char)0x65,  /* [5961] */
    (xdc_Char)0x3a,  /* [5962] */
    (xdc_Char)0x20,  /* [5963] */
    (xdc_Char)0x25,  /* [5964] */
    (xdc_Char)0x24,  /* [5965] */
    (xdc_Char)0x53,  /* [5966] */
    (xdc_Char)0x0,  /* [5967] */
    (xdc_Char)0x53,  /* [5968] */
    (xdc_Char)0x74,  /* [5969] */
    (xdc_Char)0x6f,  /* [5970] */
    (xdc_Char)0x70,  /* [5971] */
    (xdc_Char)0x49,  /* [5972] */
    (xdc_Char)0x6e,  /* [5973] */
    (xdc_Char)0x73,  /* [5974] */
    (xdc_Char)0x74,  /* [5975] */
    (xdc_Char)0x61,  /* [5976] */
    (xdc_Char)0x6e,  /* [5977] */
    (xdc_Char)0x63,  /* [5978] */
    (xdc_Char)0x65,  /* [5979] */
    (xdc_Char)0x3a,  /* [5980] */
    (xdc_Char)0x20,  /* [5981] */
    (xdc_Char)0x25,  /* [5982] */
    (xdc_Char)0x24,  /* [5983] */
    (xdc_Char)0x53,  /* [5984] */
    (xdc_Char)0x0,  /* [5985] */
    (xdc_Char)0x4c,  /* [5986] */
    (xdc_Char)0x4d,  /* [5987] */
    (xdc_Char)0x5f,  /* [5988] */
    (xdc_Char)0x62,  /* [5989] */
    (xdc_Char)0x65,  /* [5990] */
    (xdc_Char)0x67,  /* [5991] */
    (xdc_Char)0x69,  /* [5992] */
    (xdc_Char)0x6e,  /* [5993] */
    (xdc_Char)0x3a,  /* [5994] */
    (xdc_Char)0x20,  /* [5995] */
    (xdc_Char)0x68,  /* [5996] */
    (xdc_Char)0x77,  /* [5997] */
    (xdc_Char)0x69,  /* [5998] */
    (xdc_Char)0x3a,  /* [5999] */
    (xdc_Char)0x20,  /* [6000] */
    (xdc_Char)0x30,  /* [6001] */
    (xdc_Char)0x78,  /* [6002] */
    (xdc_Char)0x25,  /* [6003] */
    (xdc_Char)0x78,  /* [6004] */
    (xdc_Char)0x2c,  /* [6005] */
    (xdc_Char)0x20,  /* [6006] */
    (xdc_Char)0x66,  /* [6007] */
    (xdc_Char)0x75,  /* [6008] */
    (xdc_Char)0x6e,  /* [6009] */
    (xdc_Char)0x63,  /* [6010] */
    (xdc_Char)0x3a,  /* [6011] */
    (xdc_Char)0x20,  /* [6012] */
    (xdc_Char)0x30,  /* [6013] */
    (xdc_Char)0x78,  /* [6014] */
    (xdc_Char)0x25,  /* [6015] */
    (xdc_Char)0x78,  /* [6016] */
    (xdc_Char)0x2c,  /* [6017] */
    (xdc_Char)0x20,  /* [6018] */
    (xdc_Char)0x70,  /* [6019] */
    (xdc_Char)0x72,  /* [6020] */
    (xdc_Char)0x65,  /* [6021] */
    (xdc_Char)0x54,  /* [6022] */
    (xdc_Char)0x68,  /* [6023] */
    (xdc_Char)0x72,  /* [6024] */
    (xdc_Char)0x65,  /* [6025] */
    (xdc_Char)0x61,  /* [6026] */
    (xdc_Char)0x64,  /* [6027] */
    (xdc_Char)0x3a,  /* [6028] */
    (xdc_Char)0x20,  /* [6029] */
    (xdc_Char)0x25,  /* [6030] */
    (xdc_Char)0x64,  /* [6031] */
    (xdc_Char)0x2c,  /* [6032] */
    (xdc_Char)0x20,  /* [6033] */
    (xdc_Char)0x69,  /* [6034] */
    (xdc_Char)0x6e,  /* [6035] */
    (xdc_Char)0x74,  /* [6036] */
    (xdc_Char)0x4e,  /* [6037] */
    (xdc_Char)0x75,  /* [6038] */
    (xdc_Char)0x6d,  /* [6039] */
    (xdc_Char)0x3a,  /* [6040] */
    (xdc_Char)0x20,  /* [6041] */
    (xdc_Char)0x25,  /* [6042] */
    (xdc_Char)0x64,  /* [6043] */
    (xdc_Char)0x2c,  /* [6044] */
    (xdc_Char)0x20,  /* [6045] */
    (xdc_Char)0x69,  /* [6046] */
    (xdc_Char)0x72,  /* [6047] */
    (xdc_Char)0x70,  /* [6048] */
    (xdc_Char)0x3a,  /* [6049] */
    (xdc_Char)0x20,  /* [6050] */
    (xdc_Char)0x30,  /* [6051] */
    (xdc_Char)0x78,  /* [6052] */
    (xdc_Char)0x25,  /* [6053] */
    (xdc_Char)0x78,  /* [6054] */
    (xdc_Char)0x0,  /* [6055] */
    (xdc_Char)0x4c,  /* [6056] */
    (xdc_Char)0x44,  /* [6057] */
    (xdc_Char)0x5f,  /* [6058] */
    (xdc_Char)0x65,  /* [6059] */
    (xdc_Char)0x6e,  /* [6060] */
    (xdc_Char)0x64,  /* [6061] */
    (xdc_Char)0x3a,  /* [6062] */
    (xdc_Char)0x20,  /* [6063] */
    (xdc_Char)0x68,  /* [6064] */
    (xdc_Char)0x77,  /* [6065] */
    (xdc_Char)0x69,  /* [6066] */
    (xdc_Char)0x3a,  /* [6067] */
    (xdc_Char)0x20,  /* [6068] */
    (xdc_Char)0x30,  /* [6069] */
    (xdc_Char)0x78,  /* [6070] */
    (xdc_Char)0x25,  /* [6071] */
    (xdc_Char)0x78,  /* [6072] */
    (xdc_Char)0x0,  /* [6073] */
    (xdc_Char)0x4c,  /* [6074] */
    (xdc_Char)0x57,  /* [6075] */
    (xdc_Char)0x5f,  /* [6076] */
    (xdc_Char)0x64,  /* [6077] */
    (xdc_Char)0x65,  /* [6078] */
    (xdc_Char)0x6c,  /* [6079] */
    (xdc_Char)0x61,  /* [6080] */
    (xdc_Char)0x79,  /* [6081] */
    (xdc_Char)0x65,  /* [6082] */
    (xdc_Char)0x64,  /* [6083] */
    (xdc_Char)0x3a,  /* [6084] */
    (xdc_Char)0x20,  /* [6085] */
    (xdc_Char)0x64,  /* [6086] */
    (xdc_Char)0x65,  /* [6087] */
    (xdc_Char)0x6c,  /* [6088] */
    (xdc_Char)0x61,  /* [6089] */
    (xdc_Char)0x79,  /* [6090] */
    (xdc_Char)0x3a,  /* [6091] */
    (xdc_Char)0x20,  /* [6092] */
    (xdc_Char)0x25,  /* [6093] */
    (xdc_Char)0x64,  /* [6094] */
    (xdc_Char)0x0,  /* [6095] */
    (xdc_Char)0x4c,  /* [6096] */
    (xdc_Char)0x4d,  /* [6097] */
    (xdc_Char)0x5f,  /* [6098] */
    (xdc_Char)0x74,  /* [6099] */
    (xdc_Char)0x69,  /* [6100] */
    (xdc_Char)0x63,  /* [6101] */
    (xdc_Char)0x6b,  /* [6102] */
    (xdc_Char)0x3a,  /* [6103] */
    (xdc_Char)0x20,  /* [6104] */
    (xdc_Char)0x74,  /* [6105] */
    (xdc_Char)0x69,  /* [6106] */
    (xdc_Char)0x63,  /* [6107] */
    (xdc_Char)0x6b,  /* [6108] */
    (xdc_Char)0x3a,  /* [6109] */
    (xdc_Char)0x20,  /* [6110] */
    (xdc_Char)0x25,  /* [6111] */
    (xdc_Char)0x64,  /* [6112] */
    (xdc_Char)0x0,  /* [6113] */
    (xdc_Char)0x4c,  /* [6114] */
    (xdc_Char)0x4d,  /* [6115] */
    (xdc_Char)0x5f,  /* [6116] */
    (xdc_Char)0x62,  /* [6117] */
    (xdc_Char)0x65,  /* [6118] */
    (xdc_Char)0x67,  /* [6119] */
    (xdc_Char)0x69,  /* [6120] */
    (xdc_Char)0x6e,  /* [6121] */
    (xdc_Char)0x3a,  /* [6122] */
    (xdc_Char)0x20,  /* [6123] */
    (xdc_Char)0x63,  /* [6124] */
    (xdc_Char)0x6c,  /* [6125] */
    (xdc_Char)0x6b,  /* [6126] */
    (xdc_Char)0x3a,  /* [6127] */
    (xdc_Char)0x20,  /* [6128] */
    (xdc_Char)0x30,  /* [6129] */
    (xdc_Char)0x78,  /* [6130] */
    (xdc_Char)0x25,  /* [6131] */
    (xdc_Char)0x78,  /* [6132] */
    (xdc_Char)0x2c,  /* [6133] */
    (xdc_Char)0x20,  /* [6134] */
    (xdc_Char)0x66,  /* [6135] */
    (xdc_Char)0x75,  /* [6136] */
    (xdc_Char)0x6e,  /* [6137] */
    (xdc_Char)0x63,  /* [6138] */
    (xdc_Char)0x3a,  /* [6139] */
    (xdc_Char)0x20,  /* [6140] */
    (xdc_Char)0x30,  /* [6141] */
    (xdc_Char)0x78,  /* [6142] */
    (xdc_Char)0x25,  /* [6143] */
    (xdc_Char)0x78,  /* [6144] */
    (xdc_Char)0x0,  /* [6145] */
    (xdc_Char)0x4c,  /* [6146] */
    (xdc_Char)0x4d,  /* [6147] */
    (xdc_Char)0x5f,  /* [6148] */
    (xdc_Char)0x70,  /* [6149] */
    (xdc_Char)0x6f,  /* [6150] */
    (xdc_Char)0x73,  /* [6151] */
    (xdc_Char)0x74,  /* [6152] */
    (xdc_Char)0x3a,  /* [6153] */
    (xdc_Char)0x20,  /* [6154] */
    (xdc_Char)0x73,  /* [6155] */
    (xdc_Char)0x65,  /* [6156] */
    (xdc_Char)0x6d,  /* [6157] */
    (xdc_Char)0x3a,  /* [6158] */
    (xdc_Char)0x20,  /* [6159] */
    (xdc_Char)0x30,  /* [6160] */
    (xdc_Char)0x78,  /* [6161] */
    (xdc_Char)0x25,  /* [6162] */
    (xdc_Char)0x78,  /* [6163] */
    (xdc_Char)0x2c,  /* [6164] */
    (xdc_Char)0x20,  /* [6165] */
    (xdc_Char)0x63,  /* [6166] */
    (xdc_Char)0x6f,  /* [6167] */
    (xdc_Char)0x75,  /* [6168] */
    (xdc_Char)0x6e,  /* [6169] */
    (xdc_Char)0x74,  /* [6170] */
    (xdc_Char)0x3a,  /* [6171] */
    (xdc_Char)0x20,  /* [6172] */
    (xdc_Char)0x25,  /* [6173] */
    (xdc_Char)0x64,  /* [6174] */
    (xdc_Char)0x0,  /* [6175] */
    (xdc_Char)0x4c,  /* [6176] */
    (xdc_Char)0x4d,  /* [6177] */
    (xdc_Char)0x5f,  /* [6178] */
    (xdc_Char)0x70,  /* [6179] */
    (xdc_Char)0x65,  /* [6180] */
    (xdc_Char)0x6e,  /* [6181] */
    (xdc_Char)0x64,  /* [6182] */
    (xdc_Char)0x3a,  /* [6183] */
    (xdc_Char)0x20,  /* [6184] */
    (xdc_Char)0x73,  /* [6185] */
    (xdc_Char)0x65,  /* [6186] */
    (xdc_Char)0x6d,  /* [6187] */
    (xdc_Char)0x3a,  /* [6188] */
    (xdc_Char)0x20,  /* [6189] */
    (xdc_Char)0x30,  /* [6190] */
    (xdc_Char)0x78,  /* [6191] */
    (xdc_Char)0x25,  /* [6192] */
    (xdc_Char)0x78,  /* [6193] */
    (xdc_Char)0x2c,  /* [6194] */
    (xdc_Char)0x20,  /* [6195] */
    (xdc_Char)0x63,  /* [6196] */
    (xdc_Char)0x6f,  /* [6197] */
    (xdc_Char)0x75,  /* [6198] */
    (xdc_Char)0x6e,  /* [6199] */
    (xdc_Char)0x74,  /* [6200] */
    (xdc_Char)0x3a,  /* [6201] */
    (xdc_Char)0x20,  /* [6202] */
    (xdc_Char)0x25,  /* [6203] */
    (xdc_Char)0x64,  /* [6204] */
    (xdc_Char)0x2c,  /* [6205] */
    (xdc_Char)0x20,  /* [6206] */
    (xdc_Char)0x74,  /* [6207] */
    (xdc_Char)0x69,  /* [6208] */
    (xdc_Char)0x6d,  /* [6209] */
    (xdc_Char)0x65,  /* [6210] */
    (xdc_Char)0x6f,  /* [6211] */
    (xdc_Char)0x75,  /* [6212] */
    (xdc_Char)0x74,  /* [6213] */
    (xdc_Char)0x3a,  /* [6214] */
    (xdc_Char)0x20,  /* [6215] */
    (xdc_Char)0x25,  /* [6216] */
    (xdc_Char)0x64,  /* [6217] */
    (xdc_Char)0x0,  /* [6218] */
    (xdc_Char)0x4c,  /* [6219] */
    (xdc_Char)0x4d,  /* [6220] */
    (xdc_Char)0x5f,  /* [6221] */
    (xdc_Char)0x62,  /* [6222] */
    (xdc_Char)0x65,  /* [6223] */
    (xdc_Char)0x67,  /* [6224] */
    (xdc_Char)0x69,  /* [6225] */
    (xdc_Char)0x6e,  /* [6226] */
    (xdc_Char)0x3a,  /* [6227] */
    (xdc_Char)0x20,  /* [6228] */
    (xdc_Char)0x73,  /* [6229] */
    (xdc_Char)0x77,  /* [6230] */
    (xdc_Char)0x69,  /* [6231] */
    (xdc_Char)0x3a,  /* [6232] */
    (xdc_Char)0x20,  /* [6233] */
    (xdc_Char)0x30,  /* [6234] */
    (xdc_Char)0x78,  /* [6235] */
    (xdc_Char)0x25,  /* [6236] */
    (xdc_Char)0x78,  /* [6237] */
    (xdc_Char)0x2c,  /* [6238] */
    (xdc_Char)0x20,  /* [6239] */
    (xdc_Char)0x66,  /* [6240] */
    (xdc_Char)0x75,  /* [6241] */
    (xdc_Char)0x6e,  /* [6242] */
    (xdc_Char)0x63,  /* [6243] */
    (xdc_Char)0x3a,  /* [6244] */
    (xdc_Char)0x20,  /* [6245] */
    (xdc_Char)0x30,  /* [6246] */
    (xdc_Char)0x78,  /* [6247] */
    (xdc_Char)0x25,  /* [6248] */
    (xdc_Char)0x78,  /* [6249] */
    (xdc_Char)0x2c,  /* [6250] */
    (xdc_Char)0x20,  /* [6251] */
    (xdc_Char)0x70,  /* [6252] */
    (xdc_Char)0x72,  /* [6253] */
    (xdc_Char)0x65,  /* [6254] */
    (xdc_Char)0x54,  /* [6255] */
    (xdc_Char)0x68,  /* [6256] */
    (xdc_Char)0x72,  /* [6257] */
    (xdc_Char)0x65,  /* [6258] */
    (xdc_Char)0x61,  /* [6259] */
    (xdc_Char)0x64,  /* [6260] */
    (xdc_Char)0x3a,  /* [6261] */
    (xdc_Char)0x20,  /* [6262] */
    (xdc_Char)0x25,  /* [6263] */
    (xdc_Char)0x64,  /* [6264] */
    (xdc_Char)0x0,  /* [6265] */
    (xdc_Char)0x4c,  /* [6266] */
    (xdc_Char)0x44,  /* [6267] */
    (xdc_Char)0x5f,  /* [6268] */
    (xdc_Char)0x65,  /* [6269] */
    (xdc_Char)0x6e,  /* [6270] */
    (xdc_Char)0x64,  /* [6271] */
    (xdc_Char)0x3a,  /* [6272] */
    (xdc_Char)0x20,  /* [6273] */
    (xdc_Char)0x73,  /* [6274] */
    (xdc_Char)0x77,  /* [6275] */
    (xdc_Char)0x69,  /* [6276] */
    (xdc_Char)0x3a,  /* [6277] */
    (xdc_Char)0x20,  /* [6278] */
    (xdc_Char)0x30,  /* [6279] */
    (xdc_Char)0x78,  /* [6280] */
    (xdc_Char)0x25,  /* [6281] */
    (xdc_Char)0x78,  /* [6282] */
    (xdc_Char)0x0,  /* [6283] */
    (xdc_Char)0x4c,  /* [6284] */
    (xdc_Char)0x4d,  /* [6285] */
    (xdc_Char)0x5f,  /* [6286] */
    (xdc_Char)0x70,  /* [6287] */
    (xdc_Char)0x6f,  /* [6288] */
    (xdc_Char)0x73,  /* [6289] */
    (xdc_Char)0x74,  /* [6290] */
    (xdc_Char)0x3a,  /* [6291] */
    (xdc_Char)0x20,  /* [6292] */
    (xdc_Char)0x73,  /* [6293] */
    (xdc_Char)0x77,  /* [6294] */
    (xdc_Char)0x69,  /* [6295] */
    (xdc_Char)0x3a,  /* [6296] */
    (xdc_Char)0x20,  /* [6297] */
    (xdc_Char)0x30,  /* [6298] */
    (xdc_Char)0x78,  /* [6299] */
    (xdc_Char)0x25,  /* [6300] */
    (xdc_Char)0x78,  /* [6301] */
    (xdc_Char)0x2c,  /* [6302] */
    (xdc_Char)0x20,  /* [6303] */
    (xdc_Char)0x66,  /* [6304] */
    (xdc_Char)0x75,  /* [6305] */
    (xdc_Char)0x6e,  /* [6306] */
    (xdc_Char)0x63,  /* [6307] */
    (xdc_Char)0x3a,  /* [6308] */
    (xdc_Char)0x20,  /* [6309] */
    (xdc_Char)0x30,  /* [6310] */
    (xdc_Char)0x78,  /* [6311] */
    (xdc_Char)0x25,  /* [6312] */
    (xdc_Char)0x78,  /* [6313] */
    (xdc_Char)0x2c,  /* [6314] */
    (xdc_Char)0x20,  /* [6315] */
    (xdc_Char)0x70,  /* [6316] */
    (xdc_Char)0x72,  /* [6317] */
    (xdc_Char)0x69,  /* [6318] */
    (xdc_Char)0x3a,  /* [6319] */
    (xdc_Char)0x20,  /* [6320] */
    (xdc_Char)0x25,  /* [6321] */
    (xdc_Char)0x64,  /* [6322] */
    (xdc_Char)0x0,  /* [6323] */
    (xdc_Char)0x4c,  /* [6324] */
    (xdc_Char)0x4d,  /* [6325] */
    (xdc_Char)0x5f,  /* [6326] */
    (xdc_Char)0x73,  /* [6327] */
    (xdc_Char)0x77,  /* [6328] */
    (xdc_Char)0x69,  /* [6329] */
    (xdc_Char)0x74,  /* [6330] */
    (xdc_Char)0x63,  /* [6331] */
    (xdc_Char)0x68,  /* [6332] */
    (xdc_Char)0x3a,  /* [6333] */
    (xdc_Char)0x20,  /* [6334] */
    (xdc_Char)0x6f,  /* [6335] */
    (xdc_Char)0x6c,  /* [6336] */
    (xdc_Char)0x64,  /* [6337] */
    (xdc_Char)0x74,  /* [6338] */
    (xdc_Char)0x73,  /* [6339] */
    (xdc_Char)0x6b,  /* [6340] */
    (xdc_Char)0x3a,  /* [6341] */
    (xdc_Char)0x20,  /* [6342] */
    (xdc_Char)0x30,  /* [6343] */
    (xdc_Char)0x78,  /* [6344] */
    (xdc_Char)0x25,  /* [6345] */
    (xdc_Char)0x78,  /* [6346] */
    (xdc_Char)0x2c,  /* [6347] */
    (xdc_Char)0x20,  /* [6348] */
    (xdc_Char)0x6f,  /* [6349] */
    (xdc_Char)0x6c,  /* [6350] */
    (xdc_Char)0x64,  /* [6351] */
    (xdc_Char)0x66,  /* [6352] */
    (xdc_Char)0x75,  /* [6353] */
    (xdc_Char)0x6e,  /* [6354] */
    (xdc_Char)0x63,  /* [6355] */
    (xdc_Char)0x3a,  /* [6356] */
    (xdc_Char)0x20,  /* [6357] */
    (xdc_Char)0x30,  /* [6358] */
    (xdc_Char)0x78,  /* [6359] */
    (xdc_Char)0x25,  /* [6360] */
    (xdc_Char)0x78,  /* [6361] */
    (xdc_Char)0x2c,  /* [6362] */
    (xdc_Char)0x20,  /* [6363] */
    (xdc_Char)0x6e,  /* [6364] */
    (xdc_Char)0x65,  /* [6365] */
    (xdc_Char)0x77,  /* [6366] */
    (xdc_Char)0x74,  /* [6367] */
    (xdc_Char)0x73,  /* [6368] */
    (xdc_Char)0x6b,  /* [6369] */
    (xdc_Char)0x3a,  /* [6370] */
    (xdc_Char)0x20,  /* [6371] */
    (xdc_Char)0x30,  /* [6372] */
    (xdc_Char)0x78,  /* [6373] */
    (xdc_Char)0x25,  /* [6374] */
    (xdc_Char)0x78,  /* [6375] */
    (xdc_Char)0x2c,  /* [6376] */
    (xdc_Char)0x20,  /* [6377] */
    (xdc_Char)0x6e,  /* [6378] */
    (xdc_Char)0x65,  /* [6379] */
    (xdc_Char)0x77,  /* [6380] */
    (xdc_Char)0x66,  /* [6381] */
    (xdc_Char)0x75,  /* [6382] */
    (xdc_Char)0x6e,  /* [6383] */
    (xdc_Char)0x63,  /* [6384] */
    (xdc_Char)0x3a,  /* [6385] */
    (xdc_Char)0x20,  /* [6386] */
    (xdc_Char)0x30,  /* [6387] */
    (xdc_Char)0x78,  /* [6388] */
    (xdc_Char)0x25,  /* [6389] */
    (xdc_Char)0x78,  /* [6390] */
    (xdc_Char)0x0,  /* [6391] */
    (xdc_Char)0x4c,  /* [6392] */
    (xdc_Char)0x4d,  /* [6393] */
    (xdc_Char)0x5f,  /* [6394] */
    (xdc_Char)0x73,  /* [6395] */
    (xdc_Char)0x6c,  /* [6396] */
    (xdc_Char)0x65,  /* [6397] */
    (xdc_Char)0x65,  /* [6398] */
    (xdc_Char)0x70,  /* [6399] */
    (xdc_Char)0x3a,  /* [6400] */
    (xdc_Char)0x20,  /* [6401] */
    (xdc_Char)0x74,  /* [6402] */
    (xdc_Char)0x73,  /* [6403] */
    (xdc_Char)0x6b,  /* [6404] */
    (xdc_Char)0x3a,  /* [6405] */
    (xdc_Char)0x20,  /* [6406] */
    (xdc_Char)0x30,  /* [6407] */
    (xdc_Char)0x78,  /* [6408] */
    (xdc_Char)0x25,  /* [6409] */
    (xdc_Char)0x78,  /* [6410] */
    (xdc_Char)0x2c,  /* [6411] */
    (xdc_Char)0x20,  /* [6412] */
    (xdc_Char)0x66,  /* [6413] */
    (xdc_Char)0x75,  /* [6414] */
    (xdc_Char)0x6e,  /* [6415] */
    (xdc_Char)0x63,  /* [6416] */
    (xdc_Char)0x3a,  /* [6417] */
    (xdc_Char)0x20,  /* [6418] */
    (xdc_Char)0x30,  /* [6419] */
    (xdc_Char)0x78,  /* [6420] */
    (xdc_Char)0x25,  /* [6421] */
    (xdc_Char)0x78,  /* [6422] */
    (xdc_Char)0x2c,  /* [6423] */
    (xdc_Char)0x20,  /* [6424] */
    (xdc_Char)0x74,  /* [6425] */
    (xdc_Char)0x69,  /* [6426] */
    (xdc_Char)0x6d,  /* [6427] */
    (xdc_Char)0x65,  /* [6428] */
    (xdc_Char)0x6f,  /* [6429] */
    (xdc_Char)0x75,  /* [6430] */
    (xdc_Char)0x74,  /* [6431] */
    (xdc_Char)0x3a,  /* [6432] */
    (xdc_Char)0x20,  /* [6433] */
    (xdc_Char)0x25,  /* [6434] */
    (xdc_Char)0x64,  /* [6435] */
    (xdc_Char)0x0,  /* [6436] */
    (xdc_Char)0x4c,  /* [6437] */
    (xdc_Char)0x44,  /* [6438] */
    (xdc_Char)0x5f,  /* [6439] */
    (xdc_Char)0x72,  /* [6440] */
    (xdc_Char)0x65,  /* [6441] */
    (xdc_Char)0x61,  /* [6442] */
    (xdc_Char)0x64,  /* [6443] */
    (xdc_Char)0x79,  /* [6444] */
    (xdc_Char)0x3a,  /* [6445] */
    (xdc_Char)0x20,  /* [6446] */
    (xdc_Char)0x74,  /* [6447] */
    (xdc_Char)0x73,  /* [6448] */
    (xdc_Char)0x6b,  /* [6449] */
    (xdc_Char)0x3a,  /* [6450] */
    (xdc_Char)0x20,  /* [6451] */
    (xdc_Char)0x30,  /* [6452] */
    (xdc_Char)0x78,  /* [6453] */
    (xdc_Char)0x25,  /* [6454] */
    (xdc_Char)0x78,  /* [6455] */
    (xdc_Char)0x2c,  /* [6456] */
    (xdc_Char)0x20,  /* [6457] */
    (xdc_Char)0x66,  /* [6458] */
    (xdc_Char)0x75,  /* [6459] */
    (xdc_Char)0x6e,  /* [6460] */
    (xdc_Char)0x63,  /* [6461] */
    (xdc_Char)0x3a,  /* [6462] */
    (xdc_Char)0x20,  /* [6463] */
    (xdc_Char)0x30,  /* [6464] */
    (xdc_Char)0x78,  /* [6465] */
    (xdc_Char)0x25,  /* [6466] */
    (xdc_Char)0x78,  /* [6467] */
    (xdc_Char)0x2c,  /* [6468] */
    (xdc_Char)0x20,  /* [6469] */
    (xdc_Char)0x70,  /* [6470] */
    (xdc_Char)0x72,  /* [6471] */
    (xdc_Char)0x69,  /* [6472] */
    (xdc_Char)0x3a,  /* [6473] */
    (xdc_Char)0x20,  /* [6474] */
    (xdc_Char)0x25,  /* [6475] */
    (xdc_Char)0x64,  /* [6476] */
    (xdc_Char)0x0,  /* [6477] */
    (xdc_Char)0x4c,  /* [6478] */
    (xdc_Char)0x44,  /* [6479] */
    (xdc_Char)0x5f,  /* [6480] */
    (xdc_Char)0x62,  /* [6481] */
    (xdc_Char)0x6c,  /* [6482] */
    (xdc_Char)0x6f,  /* [6483] */
    (xdc_Char)0x63,  /* [6484] */
    (xdc_Char)0x6b,  /* [6485] */
    (xdc_Char)0x3a,  /* [6486] */
    (xdc_Char)0x20,  /* [6487] */
    (xdc_Char)0x74,  /* [6488] */
    (xdc_Char)0x73,  /* [6489] */
    (xdc_Char)0x6b,  /* [6490] */
    (xdc_Char)0x3a,  /* [6491] */
    (xdc_Char)0x20,  /* [6492] */
    (xdc_Char)0x30,  /* [6493] */
    (xdc_Char)0x78,  /* [6494] */
    (xdc_Char)0x25,  /* [6495] */
    (xdc_Char)0x78,  /* [6496] */
    (xdc_Char)0x2c,  /* [6497] */
    (xdc_Char)0x20,  /* [6498] */
    (xdc_Char)0x66,  /* [6499] */
    (xdc_Char)0x75,  /* [6500] */
    (xdc_Char)0x6e,  /* [6501] */
    (xdc_Char)0x63,  /* [6502] */
    (xdc_Char)0x3a,  /* [6503] */
    (xdc_Char)0x20,  /* [6504] */
    (xdc_Char)0x30,  /* [6505] */
    (xdc_Char)0x78,  /* [6506] */
    (xdc_Char)0x25,  /* [6507] */
    (xdc_Char)0x78,  /* [6508] */
    (xdc_Char)0x0,  /* [6509] */
    (xdc_Char)0x4c,  /* [6510] */
    (xdc_Char)0x4d,  /* [6511] */
    (xdc_Char)0x5f,  /* [6512] */
    (xdc_Char)0x79,  /* [6513] */
    (xdc_Char)0x69,  /* [6514] */
    (xdc_Char)0x65,  /* [6515] */
    (xdc_Char)0x6c,  /* [6516] */
    (xdc_Char)0x64,  /* [6517] */
    (xdc_Char)0x3a,  /* [6518] */
    (xdc_Char)0x20,  /* [6519] */
    (xdc_Char)0x74,  /* [6520] */
    (xdc_Char)0x73,  /* [6521] */
    (xdc_Char)0x6b,  /* [6522] */
    (xdc_Char)0x3a,  /* [6523] */
    (xdc_Char)0x20,  /* [6524] */
    (xdc_Char)0x30,  /* [6525] */
    (xdc_Char)0x78,  /* [6526] */
    (xdc_Char)0x25,  /* [6527] */
    (xdc_Char)0x78,  /* [6528] */
    (xdc_Char)0x2c,  /* [6529] */
    (xdc_Char)0x20,  /* [6530] */
    (xdc_Char)0x66,  /* [6531] */
    (xdc_Char)0x75,  /* [6532] */
    (xdc_Char)0x6e,  /* [6533] */
    (xdc_Char)0x63,  /* [6534] */
    (xdc_Char)0x3a,  /* [6535] */
    (xdc_Char)0x20,  /* [6536] */
    (xdc_Char)0x30,  /* [6537] */
    (xdc_Char)0x78,  /* [6538] */
    (xdc_Char)0x25,  /* [6539] */
    (xdc_Char)0x78,  /* [6540] */
    (xdc_Char)0x2c,  /* [6541] */
    (xdc_Char)0x20,  /* [6542] */
    (xdc_Char)0x63,  /* [6543] */
    (xdc_Char)0x75,  /* [6544] */
    (xdc_Char)0x72,  /* [6545] */
    (xdc_Char)0x72,  /* [6546] */
    (xdc_Char)0x54,  /* [6547] */
    (xdc_Char)0x68,  /* [6548] */
    (xdc_Char)0x72,  /* [6549] */
    (xdc_Char)0x65,  /* [6550] */
    (xdc_Char)0x61,  /* [6551] */
    (xdc_Char)0x64,  /* [6552] */
    (xdc_Char)0x3a,  /* [6553] */
    (xdc_Char)0x20,  /* [6554] */
    (xdc_Char)0x25,  /* [6555] */
    (xdc_Char)0x64,  /* [6556] */
    (xdc_Char)0x0,  /* [6557] */
    (xdc_Char)0x4c,  /* [6558] */
    (xdc_Char)0x4d,  /* [6559] */
    (xdc_Char)0x5f,  /* [6560] */
    (xdc_Char)0x73,  /* [6561] */
    (xdc_Char)0x65,  /* [6562] */
    (xdc_Char)0x74,  /* [6563] */
    (xdc_Char)0x50,  /* [6564] */
    (xdc_Char)0x72,  /* [6565] */
    (xdc_Char)0x69,  /* [6566] */
    (xdc_Char)0x3a,  /* [6567] */
    (xdc_Char)0x20,  /* [6568] */
    (xdc_Char)0x74,  /* [6569] */
    (xdc_Char)0x73,  /* [6570] */
    (xdc_Char)0x6b,  /* [6571] */
    (xdc_Char)0x3a,  /* [6572] */
    (xdc_Char)0x20,  /* [6573] */
    (xdc_Char)0x30,  /* [6574] */
    (xdc_Char)0x78,  /* [6575] */
    (xdc_Char)0x25,  /* [6576] */
    (xdc_Char)0x78,  /* [6577] */
    (xdc_Char)0x2c,  /* [6578] */
    (xdc_Char)0x20,  /* [6579] */
    (xdc_Char)0x66,  /* [6580] */
    (xdc_Char)0x75,  /* [6581] */
    (xdc_Char)0x6e,  /* [6582] */
    (xdc_Char)0x63,  /* [6583] */
    (xdc_Char)0x3a,  /* [6584] */
    (xdc_Char)0x20,  /* [6585] */
    (xdc_Char)0x30,  /* [6586] */
    (xdc_Char)0x78,  /* [6587] */
    (xdc_Char)0x25,  /* [6588] */
    (xdc_Char)0x78,  /* [6589] */
    (xdc_Char)0x2c,  /* [6590] */
    (xdc_Char)0x20,  /* [6591] */
    (xdc_Char)0x6f,  /* [6592] */
    (xdc_Char)0x6c,  /* [6593] */
    (xdc_Char)0x64,  /* [6594] */
    (xdc_Char)0x50,  /* [6595] */
    (xdc_Char)0x72,  /* [6596] */
    (xdc_Char)0x69,  /* [6597] */
    (xdc_Char)0x3a,  /* [6598] */
    (xdc_Char)0x20,  /* [6599] */
    (xdc_Char)0x25,  /* [6600] */
    (xdc_Char)0x64,  /* [6601] */
    (xdc_Char)0x2c,  /* [6602] */
    (xdc_Char)0x20,  /* [6603] */
    (xdc_Char)0x6e,  /* [6604] */
    (xdc_Char)0x65,  /* [6605] */
    (xdc_Char)0x77,  /* [6606] */
    (xdc_Char)0x50,  /* [6607] */
    (xdc_Char)0x72,  /* [6608] */
    (xdc_Char)0x69,  /* [6609] */
    (xdc_Char)0x20,  /* [6610] */
    (xdc_Char)0x25,  /* [6611] */
    (xdc_Char)0x64,  /* [6612] */
    (xdc_Char)0x0,  /* [6613] */
    (xdc_Char)0x4c,  /* [6614] */
    (xdc_Char)0x44,  /* [6615] */
    (xdc_Char)0x5f,  /* [6616] */
    (xdc_Char)0x65,  /* [6617] */
    (xdc_Char)0x78,  /* [6618] */
    (xdc_Char)0x69,  /* [6619] */
    (xdc_Char)0x74,  /* [6620] */
    (xdc_Char)0x3a,  /* [6621] */
    (xdc_Char)0x20,  /* [6622] */
    (xdc_Char)0x74,  /* [6623] */
    (xdc_Char)0x73,  /* [6624] */
    (xdc_Char)0x6b,  /* [6625] */
    (xdc_Char)0x3a,  /* [6626] */
    (xdc_Char)0x20,  /* [6627] */
    (xdc_Char)0x30,  /* [6628] */
    (xdc_Char)0x78,  /* [6629] */
    (xdc_Char)0x25,  /* [6630] */
    (xdc_Char)0x78,  /* [6631] */
    (xdc_Char)0x2c,  /* [6632] */
    (xdc_Char)0x20,  /* [6633] */
    (xdc_Char)0x66,  /* [6634] */
    (xdc_Char)0x75,  /* [6635] */
    (xdc_Char)0x6e,  /* [6636] */
    (xdc_Char)0x63,  /* [6637] */
    (xdc_Char)0x3a,  /* [6638] */
    (xdc_Char)0x20,  /* [6639] */
    (xdc_Char)0x30,  /* [6640] */
    (xdc_Char)0x78,  /* [6641] */
    (xdc_Char)0x25,  /* [6642] */
    (xdc_Char)0x78,  /* [6643] */
    (xdc_Char)0x0,  /* [6644] */
    (xdc_Char)0x4c,  /* [6645] */
    (xdc_Char)0x4d,  /* [6646] */
    (xdc_Char)0x5f,  /* [6647] */
    (xdc_Char)0x73,  /* [6648] */
    (xdc_Char)0x65,  /* [6649] */
    (xdc_Char)0x74,  /* [6650] */
    (xdc_Char)0x41,  /* [6651] */
    (xdc_Char)0x66,  /* [6652] */
    (xdc_Char)0x66,  /* [6653] */
    (xdc_Char)0x69,  /* [6654] */
    (xdc_Char)0x6e,  /* [6655] */
    (xdc_Char)0x69,  /* [6656] */
    (xdc_Char)0x74,  /* [6657] */
    (xdc_Char)0x79,  /* [6658] */
    (xdc_Char)0x3a,  /* [6659] */
    (xdc_Char)0x20,  /* [6660] */
    (xdc_Char)0x74,  /* [6661] */
    (xdc_Char)0x73,  /* [6662] */
    (xdc_Char)0x6b,  /* [6663] */
    (xdc_Char)0x3a,  /* [6664] */
    (xdc_Char)0x20,  /* [6665] */
    (xdc_Char)0x30,  /* [6666] */
    (xdc_Char)0x78,  /* [6667] */
    (xdc_Char)0x25,  /* [6668] */
    (xdc_Char)0x78,  /* [6669] */
    (xdc_Char)0x2c,  /* [6670] */
    (xdc_Char)0x20,  /* [6671] */
    (xdc_Char)0x66,  /* [6672] */
    (xdc_Char)0x75,  /* [6673] */
    (xdc_Char)0x6e,  /* [6674] */
    (xdc_Char)0x63,  /* [6675] */
    (xdc_Char)0x3a,  /* [6676] */
    (xdc_Char)0x20,  /* [6677] */
    (xdc_Char)0x30,  /* [6678] */
    (xdc_Char)0x78,  /* [6679] */
    (xdc_Char)0x25,  /* [6680] */
    (xdc_Char)0x78,  /* [6681] */
    (xdc_Char)0x2c,  /* [6682] */
    (xdc_Char)0x20,  /* [6683] */
    (xdc_Char)0x6f,  /* [6684] */
    (xdc_Char)0x6c,  /* [6685] */
    (xdc_Char)0x64,  /* [6686] */
    (xdc_Char)0x43,  /* [6687] */
    (xdc_Char)0x6f,  /* [6688] */
    (xdc_Char)0x72,  /* [6689] */
    (xdc_Char)0x65,  /* [6690] */
    (xdc_Char)0x3a,  /* [6691] */
    (xdc_Char)0x20,  /* [6692] */
    (xdc_Char)0x25,  /* [6693] */
    (xdc_Char)0x64,  /* [6694] */
    (xdc_Char)0x2c,  /* [6695] */
    (xdc_Char)0x20,  /* [6696] */
    (xdc_Char)0x6f,  /* [6697] */
    (xdc_Char)0x6c,  /* [6698] */
    (xdc_Char)0x64,  /* [6699] */
    (xdc_Char)0x41,  /* [6700] */
    (xdc_Char)0x66,  /* [6701] */
    (xdc_Char)0x66,  /* [6702] */
    (xdc_Char)0x69,  /* [6703] */
    (xdc_Char)0x6e,  /* [6704] */
    (xdc_Char)0x69,  /* [6705] */
    (xdc_Char)0x74,  /* [6706] */
    (xdc_Char)0x79,  /* [6707] */
    (xdc_Char)0x20,  /* [6708] */
    (xdc_Char)0x25,  /* [6709] */
    (xdc_Char)0x64,  /* [6710] */
    (xdc_Char)0x2c,  /* [6711] */
    (xdc_Char)0x20,  /* [6712] */
    (xdc_Char)0x6e,  /* [6713] */
    (xdc_Char)0x65,  /* [6714] */
    (xdc_Char)0x77,  /* [6715] */
    (xdc_Char)0x41,  /* [6716] */
    (xdc_Char)0x66,  /* [6717] */
    (xdc_Char)0x66,  /* [6718] */
    (xdc_Char)0x69,  /* [6719] */
    (xdc_Char)0x6e,  /* [6720] */
    (xdc_Char)0x69,  /* [6721] */
    (xdc_Char)0x74,  /* [6722] */
    (xdc_Char)0x79,  /* [6723] */
    (xdc_Char)0x20,  /* [6724] */
    (xdc_Char)0x25,  /* [6725] */
    (xdc_Char)0x64,  /* [6726] */
    (xdc_Char)0x0,  /* [6727] */
    (xdc_Char)0x4c,  /* [6728] */
    (xdc_Char)0x44,  /* [6729] */
    (xdc_Char)0x5f,  /* [6730] */
    (xdc_Char)0x73,  /* [6731] */
    (xdc_Char)0x63,  /* [6732] */
    (xdc_Char)0x68,  /* [6733] */
    (xdc_Char)0x65,  /* [6734] */
    (xdc_Char)0x64,  /* [6735] */
    (xdc_Char)0x75,  /* [6736] */
    (xdc_Char)0x6c,  /* [6737] */
    (xdc_Char)0x65,  /* [6738] */
    (xdc_Char)0x3a,  /* [6739] */
    (xdc_Char)0x20,  /* [6740] */
    (xdc_Char)0x63,  /* [6741] */
    (xdc_Char)0x6f,  /* [6742] */
    (xdc_Char)0x72,  /* [6743] */
    (xdc_Char)0x65,  /* [6744] */
    (xdc_Char)0x49,  /* [6745] */
    (xdc_Char)0x64,  /* [6746] */
    (xdc_Char)0x3a,  /* [6747] */
    (xdc_Char)0x20,  /* [6748] */
    (xdc_Char)0x25,  /* [6749] */
    (xdc_Char)0x64,  /* [6750] */
    (xdc_Char)0x2c,  /* [6751] */
    (xdc_Char)0x20,  /* [6752] */
    (xdc_Char)0x77,  /* [6753] */
    (xdc_Char)0x6f,  /* [6754] */
    (xdc_Char)0x72,  /* [6755] */
    (xdc_Char)0x6b,  /* [6756] */
    (xdc_Char)0x46,  /* [6757] */
    (xdc_Char)0x6c,  /* [6758] */
    (xdc_Char)0x61,  /* [6759] */
    (xdc_Char)0x67,  /* [6760] */
    (xdc_Char)0x3a,  /* [6761] */
    (xdc_Char)0x20,  /* [6762] */
    (xdc_Char)0x25,  /* [6763] */
    (xdc_Char)0x64,  /* [6764] */
    (xdc_Char)0x2c,  /* [6765] */
    (xdc_Char)0x20,  /* [6766] */
    (xdc_Char)0x63,  /* [6767] */
    (xdc_Char)0x75,  /* [6768] */
    (xdc_Char)0x72,  /* [6769] */
    (xdc_Char)0x53,  /* [6770] */
    (xdc_Char)0x65,  /* [6771] */
    (xdc_Char)0x74,  /* [6772] */
    (xdc_Char)0x4c,  /* [6773] */
    (xdc_Char)0x6f,  /* [6774] */
    (xdc_Char)0x63,  /* [6775] */
    (xdc_Char)0x61,  /* [6776] */
    (xdc_Char)0x6c,  /* [6777] */
    (xdc_Char)0x3a,  /* [6778] */
    (xdc_Char)0x20,  /* [6779] */
    (xdc_Char)0x25,  /* [6780] */
    (xdc_Char)0x64,  /* [6781] */
    (xdc_Char)0x2c,  /* [6782] */
    (xdc_Char)0x20,  /* [6783] */
    (xdc_Char)0x63,  /* [6784] */
    (xdc_Char)0x75,  /* [6785] */
    (xdc_Char)0x72,  /* [6786] */
    (xdc_Char)0x53,  /* [6787] */
    (xdc_Char)0x65,  /* [6788] */
    (xdc_Char)0x74,  /* [6789] */
    (xdc_Char)0x58,  /* [6790] */
    (xdc_Char)0x3a,  /* [6791] */
    (xdc_Char)0x20,  /* [6792] */
    (xdc_Char)0x25,  /* [6793] */
    (xdc_Char)0x64,  /* [6794] */
    (xdc_Char)0x2c,  /* [6795] */
    (xdc_Char)0x20,  /* [6796] */
    (xdc_Char)0x63,  /* [6797] */
    (xdc_Char)0x75,  /* [6798] */
    (xdc_Char)0x72,  /* [6799] */
    (xdc_Char)0x4d,  /* [6800] */
    (xdc_Char)0x61,  /* [6801] */
    (xdc_Char)0x73,  /* [6802] */
    (xdc_Char)0x6b,  /* [6803] */
    (xdc_Char)0x4c,  /* [6804] */
    (xdc_Char)0x6f,  /* [6805] */
    (xdc_Char)0x63,  /* [6806] */
    (xdc_Char)0x61,  /* [6807] */
    (xdc_Char)0x6c,  /* [6808] */
    (xdc_Char)0x3a,  /* [6809] */
    (xdc_Char)0x20,  /* [6810] */
    (xdc_Char)0x25,  /* [6811] */
    (xdc_Char)0x64,  /* [6812] */
    (xdc_Char)0x0,  /* [6813] */
    (xdc_Char)0x4c,  /* [6814] */
    (xdc_Char)0x44,  /* [6815] */
    (xdc_Char)0x5f,  /* [6816] */
    (xdc_Char)0x6e,  /* [6817] */
    (xdc_Char)0x6f,  /* [6818] */
    (xdc_Char)0x57,  /* [6819] */
    (xdc_Char)0x6f,  /* [6820] */
    (xdc_Char)0x72,  /* [6821] */
    (xdc_Char)0x6b,  /* [6822] */
    (xdc_Char)0x3a,  /* [6823] */
    (xdc_Char)0x20,  /* [6824] */
    (xdc_Char)0x63,  /* [6825] */
    (xdc_Char)0x6f,  /* [6826] */
    (xdc_Char)0x72,  /* [6827] */
    (xdc_Char)0x65,  /* [6828] */
    (xdc_Char)0x49,  /* [6829] */
    (xdc_Char)0x64,  /* [6830] */
    (xdc_Char)0x3a,  /* [6831] */
    (xdc_Char)0x20,  /* [6832] */
    (xdc_Char)0x25,  /* [6833] */
    (xdc_Char)0x64,  /* [6834] */
    (xdc_Char)0x2c,  /* [6835] */
    (xdc_Char)0x20,  /* [6836] */
    (xdc_Char)0x63,  /* [6837] */
    (xdc_Char)0x75,  /* [6838] */
    (xdc_Char)0x72,  /* [6839] */
    (xdc_Char)0x53,  /* [6840] */
    (xdc_Char)0x65,  /* [6841] */
    (xdc_Char)0x74,  /* [6842] */
    (xdc_Char)0x4c,  /* [6843] */
    (xdc_Char)0x6f,  /* [6844] */
    (xdc_Char)0x63,  /* [6845] */
    (xdc_Char)0x61,  /* [6846] */
    (xdc_Char)0x6c,  /* [6847] */
    (xdc_Char)0x3a,  /* [6848] */
    (xdc_Char)0x20,  /* [6849] */
    (xdc_Char)0x25,  /* [6850] */
    (xdc_Char)0x64,  /* [6851] */
    (xdc_Char)0x2c,  /* [6852] */
    (xdc_Char)0x20,  /* [6853] */
    (xdc_Char)0x63,  /* [6854] */
    (xdc_Char)0x75,  /* [6855] */
    (xdc_Char)0x72,  /* [6856] */
    (xdc_Char)0x53,  /* [6857] */
    (xdc_Char)0x65,  /* [6858] */
    (xdc_Char)0x74,  /* [6859] */
    (xdc_Char)0x58,  /* [6860] */
    (xdc_Char)0x3a,  /* [6861] */
    (xdc_Char)0x20,  /* [6862] */
    (xdc_Char)0x25,  /* [6863] */
    (xdc_Char)0x64,  /* [6864] */
    (xdc_Char)0x2c,  /* [6865] */
    (xdc_Char)0x20,  /* [6866] */
    (xdc_Char)0x63,  /* [6867] */
    (xdc_Char)0x75,  /* [6868] */
    (xdc_Char)0x72,  /* [6869] */
    (xdc_Char)0x4d,  /* [6870] */
    (xdc_Char)0x61,  /* [6871] */
    (xdc_Char)0x73,  /* [6872] */
    (xdc_Char)0x6b,  /* [6873] */
    (xdc_Char)0x4c,  /* [6874] */
    (xdc_Char)0x6f,  /* [6875] */
    (xdc_Char)0x63,  /* [6876] */
    (xdc_Char)0x61,  /* [6877] */
    (xdc_Char)0x6c,  /* [6878] */
    (xdc_Char)0x3a,  /* [6879] */
    (xdc_Char)0x20,  /* [6880] */
    (xdc_Char)0x25,  /* [6881] */
    (xdc_Char)0x64,  /* [6882] */
    (xdc_Char)0x0,  /* [6883] */
    (xdc_Char)0x78,  /* [6884] */
    (xdc_Char)0x64,  /* [6885] */
    (xdc_Char)0x63,  /* [6886] */
    (xdc_Char)0x2e,  /* [6887] */
    (xdc_Char)0x0,  /* [6888] */
    (xdc_Char)0x72,  /* [6889] */
    (xdc_Char)0x75,  /* [6890] */
    (xdc_Char)0x6e,  /* [6891] */
    (xdc_Char)0x74,  /* [6892] */
    (xdc_Char)0x69,  /* [6893] */
    (xdc_Char)0x6d,  /* [6894] */
    (xdc_Char)0x65,  /* [6895] */
    (xdc_Char)0x2e,  /* [6896] */
    (xdc_Char)0x0,  /* [6897] */
    (xdc_Char)0x41,  /* [6898] */
    (xdc_Char)0x73,  /* [6899] */
    (xdc_Char)0x73,  /* [6900] */
    (xdc_Char)0x65,  /* [6901] */
    (xdc_Char)0x72,  /* [6902] */
    (xdc_Char)0x74,  /* [6903] */
    (xdc_Char)0x0,  /* [6904] */
    (xdc_Char)0x43,  /* [6905] */
    (xdc_Char)0x6f,  /* [6906] */
    (xdc_Char)0x72,  /* [6907] */
    (xdc_Char)0x65,  /* [6908] */
    (xdc_Char)0x0,  /* [6909] */
    (xdc_Char)0x44,  /* [6910] */
    (xdc_Char)0x65,  /* [6911] */
    (xdc_Char)0x66,  /* [6912] */
    (xdc_Char)0x61,  /* [6913] */
    (xdc_Char)0x75,  /* [6914] */
    (xdc_Char)0x6c,  /* [6915] */
    (xdc_Char)0x74,  /* [6916] */
    (xdc_Char)0x73,  /* [6917] */
    (xdc_Char)0x0,  /* [6918] */
    (xdc_Char)0x44,  /* [6919] */
    (xdc_Char)0x69,  /* [6920] */
    (xdc_Char)0x61,  /* [6921] */
    (xdc_Char)0x67,  /* [6922] */
    (xdc_Char)0x73,  /* [6923] */
    (xdc_Char)0x0,  /* [6924] */
    (xdc_Char)0x45,  /* [6925] */
    (xdc_Char)0x72,  /* [6926] */
    (xdc_Char)0x72,  /* [6927] */
    (xdc_Char)0x6f,  /* [6928] */
    (xdc_Char)0x72,  /* [6929] */
    (xdc_Char)0x0,  /* [6930] */
    (xdc_Char)0x47,  /* [6931] */
    (xdc_Char)0x61,  /* [6932] */
    (xdc_Char)0x74,  /* [6933] */
    (xdc_Char)0x65,  /* [6934] */
    (xdc_Char)0x0,  /* [6935] */
    (xdc_Char)0x4c,  /* [6936] */
    (xdc_Char)0x6f,  /* [6937] */
    (xdc_Char)0x67,  /* [6938] */
    (xdc_Char)0x0,  /* [6939] */
    (xdc_Char)0x4d,  /* [6940] */
    (xdc_Char)0x61,  /* [6941] */
    (xdc_Char)0x69,  /* [6942] */
    (xdc_Char)0x6e,  /* [6943] */
    (xdc_Char)0x0,  /* [6944] */
    (xdc_Char)0x4d,  /* [6945] */
    (xdc_Char)0x65,  /* [6946] */
    (xdc_Char)0x6d,  /* [6947] */
    (xdc_Char)0x6f,  /* [6948] */
    (xdc_Char)0x72,  /* [6949] */
    (xdc_Char)0x79,  /* [6950] */
    (xdc_Char)0x0,  /* [6951] */
    (xdc_Char)0x52,  /* [6952] */
    (xdc_Char)0x65,  /* [6953] */
    (xdc_Char)0x67,  /* [6954] */
    (xdc_Char)0x69,  /* [6955] */
    (xdc_Char)0x73,  /* [6956] */
    (xdc_Char)0x74,  /* [6957] */
    (xdc_Char)0x72,  /* [6958] */
    (xdc_Char)0x79,  /* [6959] */
    (xdc_Char)0x0,  /* [6960] */
    (xdc_Char)0x53,  /* [6961] */
    (xdc_Char)0x74,  /* [6962] */
    (xdc_Char)0x61,  /* [6963] */
    (xdc_Char)0x72,  /* [6964] */
    (xdc_Char)0x74,  /* [6965] */
    (xdc_Char)0x75,  /* [6966] */
    (xdc_Char)0x70,  /* [6967] */
    (xdc_Char)0x0,  /* [6968] */
    (xdc_Char)0x53,  /* [6969] */
    (xdc_Char)0x79,  /* [6970] */
    (xdc_Char)0x73,  /* [6971] */
    (xdc_Char)0x74,  /* [6972] */
    (xdc_Char)0x65,  /* [6973] */
    (xdc_Char)0x6d,  /* [6974] */
    (xdc_Char)0x0,  /* [6975] */
    (xdc_Char)0x53,  /* [6976] */
    (xdc_Char)0x79,  /* [6977] */
    (xdc_Char)0x73,  /* [6978] */
    (xdc_Char)0x4d,  /* [6979] */
    (xdc_Char)0x69,  /* [6980] */
    (xdc_Char)0x6e,  /* [6981] */
    (xdc_Char)0x0,  /* [6982] */
    (xdc_Char)0x54,  /* [6983] */
    (xdc_Char)0x65,  /* [6984] */
    (xdc_Char)0x78,  /* [6985] */
    (xdc_Char)0x74,  /* [6986] */
    (xdc_Char)0x0,  /* [6987] */
    (xdc_Char)0x54,  /* [6988] */
    (xdc_Char)0x69,  /* [6989] */
    (xdc_Char)0x6d,  /* [6990] */
    (xdc_Char)0x65,  /* [6991] */
    (xdc_Char)0x73,  /* [6992] */
    (xdc_Char)0x74,  /* [6993] */
    (xdc_Char)0x61,  /* [6994] */
    (xdc_Char)0x6d,  /* [6995] */
    (xdc_Char)0x70,  /* [6996] */
    (xdc_Char)0x0,  /* [6997] */
    (xdc_Char)0x54,  /* [6998] */
    (xdc_Char)0x69,  /* [6999] */
    (xdc_Char)0x6d,  /* [7000] */
    (xdc_Char)0x65,  /* [7001] */
    (xdc_Char)0x73,  /* [7002] */
    (xdc_Char)0x74,  /* [7003] */
    (xdc_Char)0x61,  /* [7004] */
    (xdc_Char)0x6d,  /* [7005] */
    (xdc_Char)0x70,  /* [7006] */
    (xdc_Char)0x4e,  /* [7007] */
    (xdc_Char)0x75,  /* [7008] */
    (xdc_Char)0x6c,  /* [7009] */
    (xdc_Char)0x6c,  /* [7010] */
    (xdc_Char)0x0,  /* [7011] */
    (xdc_Char)0x74,  /* [7012] */
    (xdc_Char)0x69,  /* [7013] */
    (xdc_Char)0x2e,  /* [7014] */
    (xdc_Char)0x0,  /* [7015] */
    (xdc_Char)0x73,  /* [7016] */
    (xdc_Char)0x79,  /* [7017] */
    (xdc_Char)0x73,  /* [7018] */
    (xdc_Char)0x62,  /* [7019] */
    (xdc_Char)0x69,  /* [7020] */
    (xdc_Char)0x6f,  /* [7021] */
    (xdc_Char)0x73,  /* [7022] */
    (xdc_Char)0x2e,  /* [7023] */
    (xdc_Char)0x0,  /* [7024] */
    (xdc_Char)0x66,  /* [7025] */
    (xdc_Char)0x61,  /* [7026] */
    (xdc_Char)0x6d,  /* [7027] */
    (xdc_Char)0x69,  /* [7028] */
    (xdc_Char)0x6c,  /* [7029] */
    (xdc_Char)0x79,  /* [7030] */
    (xdc_Char)0x2e,  /* [7031] */
    (xdc_Char)0x0,  /* [7032] */
    (xdc_Char)0x63,  /* [7033] */
    (xdc_Char)0x36,  /* [7034] */
    (xdc_Char)0x34,  /* [7035] */
    (xdc_Char)0x70,  /* [7036] */
    (xdc_Char)0x2e,  /* [7037] */
    (xdc_Char)0x0,  /* [7038] */
    (xdc_Char)0x45,  /* [7039] */
    (xdc_Char)0x76,  /* [7040] */
    (xdc_Char)0x65,  /* [7041] */
    (xdc_Char)0x6e,  /* [7042] */
    (xdc_Char)0x74,  /* [7043] */
    (xdc_Char)0x43,  /* [7044] */
    (xdc_Char)0x6f,  /* [7045] */
    (xdc_Char)0x6d,  /* [7046] */
    (xdc_Char)0x62,  /* [7047] */
    (xdc_Char)0x69,  /* [7048] */
    (xdc_Char)0x6e,  /* [7049] */
    (xdc_Char)0x65,  /* [7050] */
    (xdc_Char)0x72,  /* [7051] */
    (xdc_Char)0x0,  /* [7052] */
    (xdc_Char)0x45,  /* [7053] */
    (xdc_Char)0x78,  /* [7054] */
    (xdc_Char)0x63,  /* [7055] */
    (xdc_Char)0x65,  /* [7056] */
    (xdc_Char)0x70,  /* [7057] */
    (xdc_Char)0x74,  /* [7058] */
    (xdc_Char)0x69,  /* [7059] */
    (xdc_Char)0x6f,  /* [7060] */
    (xdc_Char)0x6e,  /* [7061] */
    (xdc_Char)0x0,  /* [7062] */
    (xdc_Char)0x48,  /* [7063] */
    (xdc_Char)0x77,  /* [7064] */
    (xdc_Char)0x69,  /* [7065] */
    (xdc_Char)0x0,  /* [7066] */
    (xdc_Char)0x54,  /* [7067] */
    (xdc_Char)0x69,  /* [7068] */
    (xdc_Char)0x6d,  /* [7069] */
    (xdc_Char)0x65,  /* [7070] */
    (xdc_Char)0x73,  /* [7071] */
    (xdc_Char)0x74,  /* [7072] */
    (xdc_Char)0x61,  /* [7073] */
    (xdc_Char)0x6d,  /* [7074] */
    (xdc_Char)0x70,  /* [7075] */
    (xdc_Char)0x50,  /* [7076] */
    (xdc_Char)0x72,  /* [7077] */
    (xdc_Char)0x6f,  /* [7078] */
    (xdc_Char)0x76,  /* [7079] */
    (xdc_Char)0x69,  /* [7080] */
    (xdc_Char)0x64,  /* [7081] */
    (xdc_Char)0x65,  /* [7082] */
    (xdc_Char)0x72,  /* [7083] */
    (xdc_Char)0x0,  /* [7084] */
    (xdc_Char)0x6b,  /* [7085] */
    (xdc_Char)0x6e,  /* [7086] */
    (xdc_Char)0x6c,  /* [7087] */
    (xdc_Char)0x2e,  /* [7088] */
    (xdc_Char)0x0,  /* [7089] */
    (xdc_Char)0x43,  /* [7090] */
    (xdc_Char)0x6c,  /* [7091] */
    (xdc_Char)0x6f,  /* [7092] */
    (xdc_Char)0x63,  /* [7093] */
    (xdc_Char)0x6b,  /* [7094] */
    (xdc_Char)0x0,  /* [7095] */
    (xdc_Char)0x49,  /* [7096] */
    (xdc_Char)0x64,  /* [7097] */
    (xdc_Char)0x6c,  /* [7098] */
    (xdc_Char)0x65,  /* [7099] */
    (xdc_Char)0x0,  /* [7100] */
    (xdc_Char)0x49,  /* [7101] */
    (xdc_Char)0x6e,  /* [7102] */
    (xdc_Char)0x74,  /* [7103] */
    (xdc_Char)0x72,  /* [7104] */
    (xdc_Char)0x69,  /* [7105] */
    (xdc_Char)0x6e,  /* [7106] */
    (xdc_Char)0x73,  /* [7107] */
    (xdc_Char)0x69,  /* [7108] */
    (xdc_Char)0x63,  /* [7109] */
    (xdc_Char)0x73,  /* [7110] */
    (xdc_Char)0x0,  /* [7111] */
    (xdc_Char)0x51,  /* [7112] */
    (xdc_Char)0x75,  /* [7113] */
    (xdc_Char)0x65,  /* [7114] */
    (xdc_Char)0x75,  /* [7115] */
    (xdc_Char)0x65,  /* [7116] */
    (xdc_Char)0x0,  /* [7117] */
    (xdc_Char)0x53,  /* [7118] */
    (xdc_Char)0x65,  /* [7119] */
    (xdc_Char)0x6d,  /* [7120] */
    (xdc_Char)0x61,  /* [7121] */
    (xdc_Char)0x70,  /* [7122] */
    (xdc_Char)0x68,  /* [7123] */
    (xdc_Char)0x6f,  /* [7124] */
    (xdc_Char)0x72,  /* [7125] */
    (xdc_Char)0x65,  /* [7126] */
    (xdc_Char)0x0,  /* [7127] */
    (xdc_Char)0x53,  /* [7128] */
    (xdc_Char)0x77,  /* [7129] */
    (xdc_Char)0x69,  /* [7130] */
    (xdc_Char)0x0,  /* [7131] */
    (xdc_Char)0x54,  /* [7132] */
    (xdc_Char)0x61,  /* [7133] */
    (xdc_Char)0x73,  /* [7134] */
    (xdc_Char)0x6b,  /* [7135] */
    (xdc_Char)0x0,  /* [7136] */
    (xdc_Char)0x42,  /* [7137] */
    (xdc_Char)0x49,  /* [7138] */
    (xdc_Char)0x4f,  /* [7139] */
    (xdc_Char)0x53,  /* [7140] */
    (xdc_Char)0x0,  /* [7141] */
    (xdc_Char)0x68,  /* [7142] */
    (xdc_Char)0x61,  /* [7143] */
    (xdc_Char)0x6c,  /* [7144] */
    (xdc_Char)0x2e,  /* [7145] */
    (xdc_Char)0x0,  /* [7146] */
    (xdc_Char)0x43,  /* [7147] */
    (xdc_Char)0x61,  /* [7148] */
    (xdc_Char)0x63,  /* [7149] */
    (xdc_Char)0x68,  /* [7150] */
    (xdc_Char)0x65,  /* [7151] */
    (xdc_Char)0x0,  /* [7152] */
    (xdc_Char)0x54,  /* [7153] */
    (xdc_Char)0x69,  /* [7154] */
    (xdc_Char)0x6d,  /* [7155] */
    (xdc_Char)0x65,  /* [7156] */
    (xdc_Char)0x72,  /* [7157] */
    (xdc_Char)0x4e,  /* [7158] */
    (xdc_Char)0x75,  /* [7159] */
    (xdc_Char)0x6c,  /* [7160] */
    (xdc_Char)0x6c,  /* [7161] */
    (xdc_Char)0x0,  /* [7162] */
    (xdc_Char)0x63,  /* [7163] */
    (xdc_Char)0x36,  /* [7164] */
    (xdc_Char)0x36,  /* [7165] */
    (xdc_Char)0x2e,  /* [7166] */
    (xdc_Char)0x0,  /* [7167] */
    (xdc_Char)0x73,  /* [7168] */
    (xdc_Char)0x68,  /* [7169] */
    (xdc_Char)0x61,  /* [7170] */
    (xdc_Char)0x72,  /* [7171] */
    (xdc_Char)0x65,  /* [7172] */
    (xdc_Char)0x64,  /* [7173] */
    (xdc_Char)0x2e,  /* [7174] */
    (xdc_Char)0x0,  /* [7175] */
    (xdc_Char)0x76,  /* [7176] */
    (xdc_Char)0x61,  /* [7177] */
    (xdc_Char)0x79,  /* [7178] */
    (xdc_Char)0x75,  /* [7179] */
    (xdc_Char)0x2e,  /* [7180] */
    (xdc_Char)0x0,  /* [7181] */
    (xdc_Char)0x49,  /* [7182] */
    (xdc_Char)0x6e,  /* [7183] */
    (xdc_Char)0x74,  /* [7184] */
    (xdc_Char)0x58,  /* [7185] */
    (xdc_Char)0x62,  /* [7186] */
    (xdc_Char)0x61,  /* [7187] */
    (xdc_Char)0x72,  /* [7188] */
    (xdc_Char)0x0,  /* [7189] */
    (xdc_Char)0x54,  /* [7190] */
    (xdc_Char)0x69,  /* [7191] */
    (xdc_Char)0x6d,  /* [7192] */
    (xdc_Char)0x65,  /* [7193] */
    (xdc_Char)0x72,  /* [7194] */
    (xdc_Char)0x53,  /* [7195] */
    (xdc_Char)0x75,  /* [7196] */
    (xdc_Char)0x70,  /* [7197] */
    (xdc_Char)0x70,  /* [7198] */
    (xdc_Char)0x6f,  /* [7199] */
    (xdc_Char)0x72,  /* [7200] */
    (xdc_Char)0x74,  /* [7201] */
    (xdc_Char)0x0,  /* [7202] */
    (xdc_Char)0x74,  /* [7203] */
    (xdc_Char)0x69,  /* [7204] */
    (xdc_Char)0x6d,  /* [7205] */
    (xdc_Char)0x65,  /* [7206] */
    (xdc_Char)0x72,  /* [7207] */
    (xdc_Char)0x73,  /* [7208] */
    (xdc_Char)0x2e,  /* [7209] */
    (xdc_Char)0x0,  /* [7210] */
    (xdc_Char)0x64,  /* [7211] */
    (xdc_Char)0x6d,  /* [7212] */
    (xdc_Char)0x74,  /* [7213] */
    (xdc_Char)0x69,  /* [7214] */
    (xdc_Char)0x6d,  /* [7215] */
    (xdc_Char)0x65,  /* [7216] */
    (xdc_Char)0x72,  /* [7217] */
    (xdc_Char)0x2e,  /* [7218] */
    (xdc_Char)0x0,  /* [7219] */
    (xdc_Char)0x54,  /* [7220] */
    (xdc_Char)0x69,  /* [7221] */
    (xdc_Char)0x6d,  /* [7222] */
    (xdc_Char)0x65,  /* [7223] */
    (xdc_Char)0x72,  /* [7224] */
    (xdc_Char)0x0,  /* [7225] */
    (xdc_Char)0x72,  /* [7226] */
    (xdc_Char)0x74,  /* [7227] */
    (xdc_Char)0x73,  /* [7228] */
    (xdc_Char)0x2e,  /* [7229] */
    (xdc_Char)0x0,  /* [7230] */
    (xdc_Char)0x54,  /* [7231] */
    (xdc_Char)0x68,  /* [7232] */
    (xdc_Char)0x72,  /* [7233] */
    (xdc_Char)0x65,  /* [7234] */
    (xdc_Char)0x61,  /* [7235] */
    (xdc_Char)0x64,  /* [7236] */
    (xdc_Char)0x4c,  /* [7237] */
    (xdc_Char)0x6f,  /* [7238] */
    (xdc_Char)0x63,  /* [7239] */
    (xdc_Char)0x61,  /* [7240] */
    (xdc_Char)0x6c,  /* [7241] */
    (xdc_Char)0x53,  /* [7242] */
    (xdc_Char)0x74,  /* [7243] */
    (xdc_Char)0x6f,  /* [7244] */
    (xdc_Char)0x72,  /* [7245] */
    (xdc_Char)0x61,  /* [7246] */
    (xdc_Char)0x67,  /* [7247] */
    (xdc_Char)0x65,  /* [7248] */
    (xdc_Char)0x0,  /* [7249] */
    (xdc_Char)0x63,  /* [7250] */
    (xdc_Char)0x36,  /* [7251] */
    (xdc_Char)0x32,  /* [7252] */
    (xdc_Char)0x2e,  /* [7253] */
    (xdc_Char)0x0,  /* [7254] */
    (xdc_Char)0x54,  /* [7255] */
    (xdc_Char)0x61,  /* [7256] */
    (xdc_Char)0x73,  /* [7257] */
    (xdc_Char)0x6b,  /* [7258] */
    (xdc_Char)0x53,  /* [7259] */
    (xdc_Char)0x75,  /* [7260] */
    (xdc_Char)0x70,  /* [7261] */
    (xdc_Char)0x70,  /* [7262] */
    (xdc_Char)0x6f,  /* [7263] */
    (xdc_Char)0x72,  /* [7264] */
    (xdc_Char)0x74,  /* [7265] */
    (xdc_Char)0x0,  /* [7266] */
    (xdc_Char)0x49,  /* [7267] */
    (xdc_Char)0x6e,  /* [7268] */
    (xdc_Char)0x74,  /* [7269] */
    (xdc_Char)0x72,  /* [7270] */
    (xdc_Char)0x69,  /* [7271] */
    (xdc_Char)0x6e,  /* [7272] */
    (xdc_Char)0x73,  /* [7273] */
    (xdc_Char)0x69,  /* [7274] */
    (xdc_Char)0x63,  /* [7275] */
    (xdc_Char)0x73,  /* [7276] */
    (xdc_Char)0x53,  /* [7277] */
    (xdc_Char)0x75,  /* [7278] */
    (xdc_Char)0x70,  /* [7279] */
    (xdc_Char)0x70,  /* [7280] */
    (xdc_Char)0x6f,  /* [7281] */
    (xdc_Char)0x72,  /* [7282] */
    (xdc_Char)0x74,  /* [7283] */
    (xdc_Char)0x0,  /* [7284] */
    (xdc_Char)0x67,  /* [7285] */
    (xdc_Char)0x61,  /* [7286] */
    (xdc_Char)0x74,  /* [7287] */
    (xdc_Char)0x65,  /* [7288] */
    (xdc_Char)0x73,  /* [7289] */
    (xdc_Char)0x2e,  /* [7290] */
    (xdc_Char)0x0,  /* [7291] */
    (xdc_Char)0x47,  /* [7292] */
    (xdc_Char)0x61,  /* [7293] */
    (xdc_Char)0x74,  /* [7294] */
    (xdc_Char)0x65,  /* [7295] */
    (xdc_Char)0x48,  /* [7296] */
    (xdc_Char)0x77,  /* [7297] */
    (xdc_Char)0x69,  /* [7298] */
    (xdc_Char)0x0,  /* [7299] */
    (xdc_Char)0x47,  /* [7300] */
    (xdc_Char)0x61,  /* [7301] */
    (xdc_Char)0x74,  /* [7302] */
    (xdc_Char)0x65,  /* [7303] */
    (xdc_Char)0x4d,  /* [7304] */
    (xdc_Char)0x75,  /* [7305] */
    (xdc_Char)0x74,  /* [7306] */
    (xdc_Char)0x65,  /* [7307] */
    (xdc_Char)0x78,  /* [7308] */
    (xdc_Char)0x0,  /* [7309] */
    (xdc_Char)0x68,  /* [7310] */
    (xdc_Char)0x65,  /* [7311] */
    (xdc_Char)0x61,  /* [7312] */
    (xdc_Char)0x70,  /* [7313] */
    (xdc_Char)0x73,  /* [7314] */
    (xdc_Char)0x2e,  /* [7315] */
    (xdc_Char)0x0,  /* [7316] */
    (xdc_Char)0x48,  /* [7317] */
    (xdc_Char)0x65,  /* [7318] */
    (xdc_Char)0x61,  /* [7319] */
    (xdc_Char)0x70,  /* [7320] */
    (xdc_Char)0x4d,  /* [7321] */
    (xdc_Char)0x65,  /* [7322] */
    (xdc_Char)0x6d,  /* [7323] */
    (xdc_Char)0x0,  /* [7324] */
    (xdc_Char)0x74,  /* [7325] */
    (xdc_Char)0x69,  /* [7326] */
    (xdc_Char)0x2e,  /* [7327] */
    (xdc_Char)0x73,  /* [7328] */
    (xdc_Char)0x79,  /* [7329] */
    (xdc_Char)0x73,  /* [7330] */
    (xdc_Char)0x62,  /* [7331] */
    (xdc_Char)0x69,  /* [7332] */
    (xdc_Char)0x6f,  /* [7333] */
    (xdc_Char)0x73,  /* [7334] */
    (xdc_Char)0x2e,  /* [7335] */
    (xdc_Char)0x6b,  /* [7336] */
    (xdc_Char)0x6e,  /* [7337] */
    (xdc_Char)0x6c,  /* [7338] */
    (xdc_Char)0x2e,  /* [7339] */
    (xdc_Char)0x54,  /* [7340] */
    (xdc_Char)0x61,  /* [7341] */
    (xdc_Char)0x73,  /* [7342] */
    (xdc_Char)0x6b,  /* [7343] */
    (xdc_Char)0x2e,  /* [7344] */
    (xdc_Char)0x49,  /* [7345] */
    (xdc_Char)0x64,  /* [7346] */
    (xdc_Char)0x6c,  /* [7347] */
    (xdc_Char)0x65,  /* [7348] */
    (xdc_Char)0x54,  /* [7349] */
    (xdc_Char)0x61,  /* [7350] */
    (xdc_Char)0x73,  /* [7351] */
    (xdc_Char)0x6b,  /* [7352] */
    (xdc_Char)0x0,  /* [7353] */
};

/* --> xdc_runtime_Text_nodeTab__A */
#pragma DATA_SECTION(xdc_runtime_Text_nodeTab__A, ".const:xdc_runtime_Text_nodeTab__A");
const __T1_xdc_runtime_Text_nodeTab xdc_runtime_Text_nodeTab__A[58] = {
    {
        (xdc_Bits16)0x0,  /* left */
        (xdc_Bits16)0x0,  /* right */
    },  /* [0] */
    {
        (xdc_Bits16)0x1ae4,  /* left */
        (xdc_Bits16)0x1ae9,  /* right */
    },  /* [1] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1af2,  /* right */
    },  /* [2] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1af9,  /* right */
    },  /* [3] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1afe,  /* right */
    },  /* [4] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1b07,  /* right */
    },  /* [5] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1b0d,  /* right */
    },  /* [6] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1b13,  /* right */
    },  /* [7] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1b18,  /* right */
    },  /* [8] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1b1c,  /* right */
    },  /* [9] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1b21,  /* right */
    },  /* [10] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1b28,  /* right */
    },  /* [11] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1b31,  /* right */
    },  /* [12] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1b39,  /* right */
    },  /* [13] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1b40,  /* right */
    },  /* [14] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1b47,  /* right */
    },  /* [15] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1b4c,  /* right */
    },  /* [16] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1b56,  /* right */
    },  /* [17] */
    {
        (xdc_Bits16)0x1b64,  /* left */
        (xdc_Bits16)0x1b68,  /* right */
    },  /* [18] */
    {
        (xdc_Bits16)0x8012,  /* left */
        (xdc_Bits16)0x1b71,  /* right */
    },  /* [19] */
    {
        (xdc_Bits16)0x8013,  /* left */
        (xdc_Bits16)0x1b79,  /* right */
    },  /* [20] */
    {
        (xdc_Bits16)0x8014,  /* left */
        (xdc_Bits16)0x1b7f,  /* right */
    },  /* [21] */
    {
        (xdc_Bits16)0x8014,  /* left */
        (xdc_Bits16)0x1b8d,  /* right */
    },  /* [22] */
    {
        (xdc_Bits16)0x8014,  /* left */
        (xdc_Bits16)0x1b97,  /* right */
    },  /* [23] */
    {
        (xdc_Bits16)0x8014,  /* left */
        (xdc_Bits16)0x1b9b,  /* right */
    },  /* [24] */
    {
        (xdc_Bits16)0x8012,  /* left */
        (xdc_Bits16)0x1bad,  /* right */
    },  /* [25] */
    {
        (xdc_Bits16)0x8019,  /* left */
        (xdc_Bits16)0x1bb2,  /* right */
    },  /* [26] */
    {
        (xdc_Bits16)0x8019,  /* left */
        (xdc_Bits16)0x1bb8,  /* right */
    },  /* [27] */
    {
        (xdc_Bits16)0x8019,  /* left */
        (xdc_Bits16)0x1bbd,  /* right */
    },  /* [28] */
    {
        (xdc_Bits16)0x8019,  /* left */
        (xdc_Bits16)0x1bc8,  /* right */
    },  /* [29] */
    {
        (xdc_Bits16)0x8019,  /* left */
        (xdc_Bits16)0x1bce,  /* right */
    },  /* [30] */
    {
        (xdc_Bits16)0x8019,  /* left */
        (xdc_Bits16)0x1bd8,  /* right */
    },  /* [31] */
    {
        (xdc_Bits16)0x8019,  /* left */
        (xdc_Bits16)0x1bdc,  /* right */
    },  /* [32] */
    {
        (xdc_Bits16)0x8012,  /* left */
        (xdc_Bits16)0x1be1,  /* right */
    },  /* [33] */
    {
        (xdc_Bits16)0x8012,  /* left */
        (xdc_Bits16)0x1be6,  /* right */
    },  /* [34] */
    {
        (xdc_Bits16)0x8022,  /* left */
        (xdc_Bits16)0x1beb,  /* right */
    },  /* [35] */
    {
        (xdc_Bits16)0x8022,  /* left */
        (xdc_Bits16)0x1b97,  /* right */
    },  /* [36] */
    {
        (xdc_Bits16)0x8022,  /* left */
        (xdc_Bits16)0x1bf1,  /* right */
    },  /* [37] */
    {
        (xdc_Bits16)0x8013,  /* left */
        (xdc_Bits16)0x1bfb,  /* right */
    },  /* [38] */
    {
        (xdc_Bits16)0x8026,  /* left */
        (xdc_Bits16)0x1beb,  /* right */
    },  /* [39] */
    {
        (xdc_Bits16)0x8013,  /* left */
        (xdc_Bits16)0x1c00,  /* right */
    },  /* [40] */
    {
        (xdc_Bits16)0x8028,  /* left */
        (xdc_Bits16)0x1c08,  /* right */
    },  /* [41] */
    {
        (xdc_Bits16)0x8029,  /* left */
        (xdc_Bits16)0x1c0e,  /* right */
    },  /* [42] */
    {
        (xdc_Bits16)0x8029,  /* left */
        (xdc_Bits16)0x1c16,  /* right */
    },  /* [43] */
    {
        (xdc_Bits16)0x8012,  /* left */
        (xdc_Bits16)0x1c23,  /* right */
    },  /* [44] */
    {
        (xdc_Bits16)0x802c,  /* left */
        (xdc_Bits16)0x1c2b,  /* right */
    },  /* [45] */
    {
        (xdc_Bits16)0x802d,  /* left */
        (xdc_Bits16)0x1c34,  /* right */
    },  /* [46] */
    {
        (xdc_Bits16)0x8012,  /* left */
        (xdc_Bits16)0x1c3a,  /* right */
    },  /* [47] */
    {
        (xdc_Bits16)0x802f,  /* left */
        (xdc_Bits16)0x1b64,  /* right */
    },  /* [48] */
    {
        (xdc_Bits16)0x8030,  /* left */
        (xdc_Bits16)0x1c3f,  /* right */
    },  /* [49] */
    {
        (xdc_Bits16)0x8013,  /* left */
        (xdc_Bits16)0x1c52,  /* right */
    },  /* [50] */
    {
        (xdc_Bits16)0x8032,  /* left */
        (xdc_Bits16)0x1c57,  /* right */
    },  /* [51] */
    {
        (xdc_Bits16)0x8032,  /* left */
        (xdc_Bits16)0x1c63,  /* right */
    },  /* [52] */
    {
        (xdc_Bits16)0x8012,  /* left */
        (xdc_Bits16)0x1c75,  /* right */
    },  /* [53] */
    {
        (xdc_Bits16)0x8035,  /* left */
        (xdc_Bits16)0x1c7c,  /* right */
    },  /* [54] */
    {
        (xdc_Bits16)0x8035,  /* left */
        (xdc_Bits16)0x1c84,  /* right */
    },  /* [55] */
    {
        (xdc_Bits16)0x8012,  /* left */
        (xdc_Bits16)0x1c8e,  /* right */
    },  /* [56] */
    {
        (xdc_Bits16)0x8038,  /* left */
        (xdc_Bits16)0x1c95,  /* right */
    },  /* [57] */
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
__FAR__ const CT__xdc_runtime_Text_charCnt xdc_runtime_Text_charCnt__C = (xdc_Int16)0x1cba;

/* nodeCnt__C */
#pragma DATA_SECTION(xdc_runtime_Text_nodeCnt__C, ".const:xdc_runtime_Text_nodeCnt__C");
__FAR__ const CT__xdc_runtime_Text_nodeCnt xdc_runtime_Text_nodeCnt__C = (xdc_Int16)0x3a;

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
 * ======== xdc.runtime.Timestamp INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__diagsEnabled__C, ".const:xdc_runtime_Timestamp_Module__diagsEnabled__C");
__FAR__ const CT__xdc_runtime_Timestamp_Module__diagsEnabled xdc_runtime_Timestamp_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__diagsIncluded__C, ".const:xdc_runtime_Timestamp_Module__diagsIncluded__C");
__FAR__ const CT__xdc_runtime_Timestamp_Module__diagsIncluded xdc_runtime_Timestamp_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__diagsMask__C, ".const:xdc_runtime_Timestamp_Module__diagsMask__C");
__FAR__ const CT__xdc_runtime_Timestamp_Module__diagsMask xdc_runtime_Timestamp_Module__diagsMask__C = ((CT__xdc_runtime_Timestamp_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__gateObj__C, ".const:xdc_runtime_Timestamp_Module__gateObj__C");
__FAR__ const CT__xdc_runtime_Timestamp_Module__gateObj xdc_runtime_Timestamp_Module__gateObj__C = ((CT__xdc_runtime_Timestamp_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__gatePrms__C, ".const:xdc_runtime_Timestamp_Module__gatePrms__C");
__FAR__ const CT__xdc_runtime_Timestamp_Module__gatePrms xdc_runtime_Timestamp_Module__gatePrms__C = ((CT__xdc_runtime_Timestamp_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__id__C, ".const:xdc_runtime_Timestamp_Module__id__C");
__FAR__ const CT__xdc_runtime_Timestamp_Module__id xdc_runtime_Timestamp_Module__id__C = (xdc_Bits16)0x8010;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__loggerDefined__C, ".const:xdc_runtime_Timestamp_Module__loggerDefined__C");
__FAR__ const CT__xdc_runtime_Timestamp_Module__loggerDefined xdc_runtime_Timestamp_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__loggerObj__C, ".const:xdc_runtime_Timestamp_Module__loggerObj__C");
__FAR__ const CT__xdc_runtime_Timestamp_Module__loggerObj xdc_runtime_Timestamp_Module__loggerObj__C = ((CT__xdc_runtime_Timestamp_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__loggerFxn0__C, ".const:xdc_runtime_Timestamp_Module__loggerFxn0__C");
__FAR__ const CT__xdc_runtime_Timestamp_Module__loggerFxn0 xdc_runtime_Timestamp_Module__loggerFxn0__C = ((CT__xdc_runtime_Timestamp_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__loggerFxn1__C, ".const:xdc_runtime_Timestamp_Module__loggerFxn1__C");
__FAR__ const CT__xdc_runtime_Timestamp_Module__loggerFxn1 xdc_runtime_Timestamp_Module__loggerFxn1__C = ((CT__xdc_runtime_Timestamp_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__loggerFxn2__C, ".const:xdc_runtime_Timestamp_Module__loggerFxn2__C");
__FAR__ const CT__xdc_runtime_Timestamp_Module__loggerFxn2 xdc_runtime_Timestamp_Module__loggerFxn2__C = ((CT__xdc_runtime_Timestamp_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__loggerFxn4__C, ".const:xdc_runtime_Timestamp_Module__loggerFxn4__C");
__FAR__ const CT__xdc_runtime_Timestamp_Module__loggerFxn4 xdc_runtime_Timestamp_Module__loggerFxn4__C = ((CT__xdc_runtime_Timestamp_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__loggerFxn8__C, ".const:xdc_runtime_Timestamp_Module__loggerFxn8__C");
__FAR__ const CT__xdc_runtime_Timestamp_Module__loggerFxn8 xdc_runtime_Timestamp_Module__loggerFxn8__C = ((CT__xdc_runtime_Timestamp_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__startupDoneFxn__C, ".const:xdc_runtime_Timestamp_Module__startupDoneFxn__C");
__FAR__ const CT__xdc_runtime_Timestamp_Module__startupDoneFxn xdc_runtime_Timestamp_Module__startupDoneFxn__C = ((CT__xdc_runtime_Timestamp_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(xdc_runtime_Timestamp_Object__count__C, ".const:xdc_runtime_Timestamp_Object__count__C");
__FAR__ const CT__xdc_runtime_Timestamp_Object__count xdc_runtime_Timestamp_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(xdc_runtime_Timestamp_Object__heap__C, ".const:xdc_runtime_Timestamp_Object__heap__C");
__FAR__ const CT__xdc_runtime_Timestamp_Object__heap xdc_runtime_Timestamp_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(xdc_runtime_Timestamp_Object__sizeof__C, ".const:xdc_runtime_Timestamp_Object__sizeof__C");
__FAR__ const CT__xdc_runtime_Timestamp_Object__sizeof xdc_runtime_Timestamp_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(xdc_runtime_Timestamp_Object__table__C, ".const:xdc_runtime_Timestamp_Object__table__C");
__FAR__ const CT__xdc_runtime_Timestamp_Object__table xdc_runtime_Timestamp_Object__table__C = 0;


/*
 * ======== xdc.runtime.TimestampNull INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(xdc_runtime_TimestampNull_Module__diagsEnabled__C, ".const:xdc_runtime_TimestampNull_Module__diagsEnabled__C");
__FAR__ const CT__xdc_runtime_TimestampNull_Module__diagsEnabled xdc_runtime_TimestampNull_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(xdc_runtime_TimestampNull_Module__diagsIncluded__C, ".const:xdc_runtime_TimestampNull_Module__diagsIncluded__C");
__FAR__ const CT__xdc_runtime_TimestampNull_Module__diagsIncluded xdc_runtime_TimestampNull_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
#pragma DATA_SECTION(xdc_runtime_TimestampNull_Module__diagsMask__C, ".const:xdc_runtime_TimestampNull_Module__diagsMask__C");
__FAR__ const CT__xdc_runtime_TimestampNull_Module__diagsMask xdc_runtime_TimestampNull_Module__diagsMask__C = ((CT__xdc_runtime_TimestampNull_Module__diagsMask)0);

/* Module__gateObj__C */
#pragma DATA_SECTION(xdc_runtime_TimestampNull_Module__gateObj__C, ".const:xdc_runtime_TimestampNull_Module__gateObj__C");
__FAR__ const CT__xdc_runtime_TimestampNull_Module__gateObj xdc_runtime_TimestampNull_Module__gateObj__C = ((CT__xdc_runtime_TimestampNull_Module__gateObj)0);

/* Module__gatePrms__C */
#pragma DATA_SECTION(xdc_runtime_TimestampNull_Module__gatePrms__C, ".const:xdc_runtime_TimestampNull_Module__gatePrms__C");
__FAR__ const CT__xdc_runtime_TimestampNull_Module__gatePrms xdc_runtime_TimestampNull_Module__gatePrms__C = ((CT__xdc_runtime_TimestampNull_Module__gatePrms)0);

/* Module__id__C */
#pragma DATA_SECTION(xdc_runtime_TimestampNull_Module__id__C, ".const:xdc_runtime_TimestampNull_Module__id__C");
__FAR__ const CT__xdc_runtime_TimestampNull_Module__id xdc_runtime_TimestampNull_Module__id__C = (xdc_Bits16)0x8011;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(xdc_runtime_TimestampNull_Module__loggerDefined__C, ".const:xdc_runtime_TimestampNull_Module__loggerDefined__C");
__FAR__ const CT__xdc_runtime_TimestampNull_Module__loggerDefined xdc_runtime_TimestampNull_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(xdc_runtime_TimestampNull_Module__loggerObj__C, ".const:xdc_runtime_TimestampNull_Module__loggerObj__C");
__FAR__ const CT__xdc_runtime_TimestampNull_Module__loggerObj xdc_runtime_TimestampNull_Module__loggerObj__C = ((CT__xdc_runtime_TimestampNull_Module__loggerObj)0);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(xdc_runtime_TimestampNull_Module__loggerFxn0__C, ".const:xdc_runtime_TimestampNull_Module__loggerFxn0__C");
__FAR__ const CT__xdc_runtime_TimestampNull_Module__loggerFxn0 xdc_runtime_TimestampNull_Module__loggerFxn0__C = ((CT__xdc_runtime_TimestampNull_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(xdc_runtime_TimestampNull_Module__loggerFxn1__C, ".const:xdc_runtime_TimestampNull_Module__loggerFxn1__C");
__FAR__ const CT__xdc_runtime_TimestampNull_Module__loggerFxn1 xdc_runtime_TimestampNull_Module__loggerFxn1__C = ((CT__xdc_runtime_TimestampNull_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(xdc_runtime_TimestampNull_Module__loggerFxn2__C, ".const:xdc_runtime_TimestampNull_Module__loggerFxn2__C");
__FAR__ const CT__xdc_runtime_TimestampNull_Module__loggerFxn2 xdc_runtime_TimestampNull_Module__loggerFxn2__C = ((CT__xdc_runtime_TimestampNull_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(xdc_runtime_TimestampNull_Module__loggerFxn4__C, ".const:xdc_runtime_TimestampNull_Module__loggerFxn4__C");
__FAR__ const CT__xdc_runtime_TimestampNull_Module__loggerFxn4 xdc_runtime_TimestampNull_Module__loggerFxn4__C = ((CT__xdc_runtime_TimestampNull_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(xdc_runtime_TimestampNull_Module__loggerFxn8__C, ".const:xdc_runtime_TimestampNull_Module__loggerFxn8__C");
__FAR__ const CT__xdc_runtime_TimestampNull_Module__loggerFxn8 xdc_runtime_TimestampNull_Module__loggerFxn8__C = ((CT__xdc_runtime_TimestampNull_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
#pragma DATA_SECTION(xdc_runtime_TimestampNull_Module__startupDoneFxn__C, ".const:xdc_runtime_TimestampNull_Module__startupDoneFxn__C");
__FAR__ const CT__xdc_runtime_TimestampNull_Module__startupDoneFxn xdc_runtime_TimestampNull_Module__startupDoneFxn__C = ((CT__xdc_runtime_TimestampNull_Module__startupDoneFxn)0);

/* Object__count__C */
#pragma DATA_SECTION(xdc_runtime_TimestampNull_Object__count__C, ".const:xdc_runtime_TimestampNull_Object__count__C");
__FAR__ const CT__xdc_runtime_TimestampNull_Object__count xdc_runtime_TimestampNull_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(xdc_runtime_TimestampNull_Object__heap__C, ".const:xdc_runtime_TimestampNull_Object__heap__C");
__FAR__ const CT__xdc_runtime_TimestampNull_Object__heap xdc_runtime_TimestampNull_Object__heap__C = 0;

/* Object__sizeof__C */
#pragma DATA_SECTION(xdc_runtime_TimestampNull_Object__sizeof__C, ".const:xdc_runtime_TimestampNull_Object__sizeof__C");
__FAR__ const CT__xdc_runtime_TimestampNull_Object__sizeof xdc_runtime_TimestampNull_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(xdc_runtime_TimestampNull_Object__table__C, ".const:xdc_runtime_TimestampNull_Object__table__C");
__FAR__ const CT__xdc_runtime_TimestampNull_Object__table xdc_runtime_TimestampNull_Object__table__C = 0;


/*
 * ======== xdc.runtime.Timestamp_SupportProxy INITIALIZERS ========
 */


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

/* DELEGATES TO ti.sysbios.family.c66.Cache */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_hal_Cache_CacheProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_c66_Cache_Module__startupDone__S();
}

/* enable__E */
xdc_Void ti_sysbios_hal_Cache_CacheProxy_enable__E( xdc_Bits16 type )
{
    ti_sysbios_family_c66_Cache_enable(type);
}

/* disable__E */
xdc_Void ti_sysbios_hal_Cache_CacheProxy_disable__E( xdc_Bits16 type )
{
    ti_sysbios_family_c66_Cache_disable(type);
}

/* inv__E */
xdc_Void ti_sysbios_hal_Cache_CacheProxy_inv__E( xdc_Ptr blockPtr, xdc_SizeT byteCnt, xdc_Bits16 type, xdc_Bool wait )
{
    ti_sysbios_family_c66_Cache_inv(blockPtr, byteCnt, type, wait);
}

/* wb__E */
xdc_Void ti_sysbios_hal_Cache_CacheProxy_wb__E( xdc_Ptr blockPtr, xdc_SizeT byteCnt, xdc_Bits16 type, xdc_Bool wait )
{
    ti_sysbios_family_c66_Cache_wb(blockPtr, byteCnt, type, wait);
}

/* wbInv__E */
xdc_Void ti_sysbios_hal_Cache_CacheProxy_wbInv__E( xdc_Ptr blockPtr, xdc_SizeT byteCnt, xdc_Bits16 type, xdc_Bool wait )
{
    ti_sysbios_family_c66_Cache_wbInv(blockPtr, byteCnt, type, wait);
}

/* wbAll__E */
xdc_Void ti_sysbios_hal_Cache_CacheProxy_wbAll__E( void )
{
    ti_sysbios_family_c66_Cache_wbAll();
}

/* wbInvAll__E */
xdc_Void ti_sysbios_hal_Cache_CacheProxy_wbInvAll__E( void )
{
    ti_sysbios_family_c66_Cache_wbInvAll();
}

/* wait__E */
xdc_Void ti_sysbios_hal_Cache_CacheProxy_wait__E( void )
{
    ti_sysbios_family_c66_Cache_wait();
}


/*
 * ======== ti.sysbios.hal.Hwi_HwiProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.family.c64p.Hwi */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_hal_Hwi_HwiProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_c64p_Hwi_Module__startupDone__S();
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
    return ti_sysbios_family_c64p_Hwi_Object__create__S(__obj, __osz, __aa, (const ti_sysbios_family_c64p_Hwi___ParamsPtr)__paramsPtr, sizeof(ti_sysbios_interfaces_IHwi_Params), __eb);
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
    ti_sysbios_family_c64p_Hwi_Object__delete__S(instp);
}

/* delete */
void ti_sysbios_hal_Hwi_HwiProxy_delete(ti_sysbios_hal_Hwi_HwiProxy_Handle *instp)
{
    ti_sysbios_hal_Hwi_HwiProxy_Object__delete__S(instp);
}

/* Params__init__S */
void ti_sysbios_hal_Hwi_HwiProxy_Params__init__S( xdc_Ptr dst, const void *src, xdc_SizeT psz, xdc_SizeT isz )
{
    ti_sysbios_family_c64p_Hwi_Params__init__S(dst, src, psz, isz);
}

/* Handle__label__S */
xdc_runtime_Types_Label *ti_sysbios_hal_Hwi_HwiProxy_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab)
{
    return ti_sysbios_family_c64p_Hwi_Handle__label__S(obj, lab);
}

/* getStackInfo__E */
xdc_Bool ti_sysbios_hal_Hwi_HwiProxy_getStackInfo__E( ti_sysbios_interfaces_IHwi_StackInfo *stkInfo, xdc_Bool computeStackDepth )
{
    return ti_sysbios_family_c64p_Hwi_getStackInfo(stkInfo, computeStackDepth);
}

/* getCoreStackInfo__E */
xdc_Bool ti_sysbios_hal_Hwi_HwiProxy_getCoreStackInfo__E( ti_sysbios_interfaces_IHwi_StackInfo *stkInfo, xdc_Bool computeStackDepth, xdc_UInt coreId )
{
    return ti_sysbios_family_c64p_Hwi_getCoreStackInfo(stkInfo, computeStackDepth, coreId);
}

/* startup__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_startup__E( void )
{
    ti_sysbios_family_c64p_Hwi_startup();
}

/* disable__E */
xdc_UInt ti_sysbios_hal_Hwi_HwiProxy_disable__E( void )
{
    return ti_sysbios_family_c64p_Hwi_disable();
}

/* enable__E */
xdc_UInt ti_sysbios_hal_Hwi_HwiProxy_enable__E( void )
{
    return ti_sysbios_family_c64p_Hwi_enable();
}

/* restore__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_restore__E( xdc_UInt key )
{
    ti_sysbios_family_c64p_Hwi_restore(key);
}

/* switchFromBootStack__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_switchFromBootStack__E( void )
{
    ti_sysbios_family_c64p_Hwi_switchFromBootStack();
}

/* post__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_post__E( xdc_UInt intNum )
{
    ti_sysbios_family_c64p_Hwi_post(intNum);
}

/* getTaskSP__E */
xdc_Char *ti_sysbios_hal_Hwi_HwiProxy_getTaskSP__E( void )
{
    return ti_sysbios_family_c64p_Hwi_getTaskSP();
}

/* disableInterrupt__E */
xdc_UInt ti_sysbios_hal_Hwi_HwiProxy_disableInterrupt__E( xdc_UInt intNum )
{
    return ti_sysbios_family_c64p_Hwi_disableInterrupt(intNum);
}

/* enableInterrupt__E */
xdc_UInt ti_sysbios_hal_Hwi_HwiProxy_enableInterrupt__E( xdc_UInt intNum )
{
    return ti_sysbios_family_c64p_Hwi_enableInterrupt(intNum);
}

/* restoreInterrupt__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_restoreInterrupt__E( xdc_UInt intNum, xdc_UInt key )
{
    ti_sysbios_family_c64p_Hwi_restoreInterrupt(intNum, key);
}

/* clearInterrupt__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_clearInterrupt__E( xdc_UInt intNum )
{
    ti_sysbios_family_c64p_Hwi_clearInterrupt(intNum);
}

/* getFunc__E */
ti_sysbios_interfaces_IHwi_FuncPtr ti_sysbios_hal_Hwi_HwiProxy_getFunc__E( ti_sysbios_hal_Hwi_HwiProxy_Handle __inst, xdc_UArg *arg )
{
    return ti_sysbios_family_c64p_Hwi_getFunc((ti_sysbios_family_c64p_Hwi_Handle)__inst, arg);
}

/* setFunc__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_setFunc__E( ti_sysbios_hal_Hwi_HwiProxy_Handle __inst, ti_sysbios_interfaces_IHwi_FuncPtr fxn, xdc_UArg arg )
{
    ti_sysbios_family_c64p_Hwi_setFunc((ti_sysbios_family_c64p_Hwi_Handle)__inst, fxn, arg);
}

/* getHookContext__E */
xdc_Ptr ti_sysbios_hal_Hwi_HwiProxy_getHookContext__E( ti_sysbios_hal_Hwi_HwiProxy_Handle __inst, xdc_Int id )
{
    return ti_sysbios_family_c64p_Hwi_getHookContext((ti_sysbios_family_c64p_Hwi_Handle)__inst, id);
}

/* setHookContext__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_setHookContext__E( ti_sysbios_hal_Hwi_HwiProxy_Handle __inst, xdc_Int id, xdc_Ptr hookContext )
{
    ti_sysbios_family_c64p_Hwi_setHookContext((ti_sysbios_family_c64p_Hwi_Handle)__inst, id, hookContext);
}

/* getIrp__E */
ti_sysbios_interfaces_IHwi_Irp ti_sysbios_hal_Hwi_HwiProxy_getIrp__E( ti_sysbios_hal_Hwi_HwiProxy_Handle __inst )
{
    return ti_sysbios_family_c64p_Hwi_getIrp((ti_sysbios_family_c64p_Hwi_Handle)__inst);
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

/* DELEGATES TO ti.sysbios.hal.TimerNull */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Clock_TimerProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_hal_TimerNull_Module__startupDone__S();
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
    return ti_sysbios_hal_TimerNull_Object__create__S(__obj, __osz, __aa, (const ti_sysbios_hal_TimerNull___ParamsPtr)__paramsPtr, sizeof(ti_sysbios_interfaces_ITimer_Params), __eb);
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
    ti_sysbios_hal_TimerNull_Object__delete__S(instp);
}

/* delete */
void ti_sysbios_knl_Clock_TimerProxy_delete(ti_sysbios_knl_Clock_TimerProxy_Handle *instp)
{
    ti_sysbios_knl_Clock_TimerProxy_Object__delete__S(instp);
}

/* Params__init__S */
void ti_sysbios_knl_Clock_TimerProxy_Params__init__S( xdc_Ptr dst, const void *src, xdc_SizeT psz, xdc_SizeT isz )
{
    ti_sysbios_hal_TimerNull_Params__init__S(dst, src, psz, isz);
}

/* Handle__label__S */
xdc_runtime_Types_Label *ti_sysbios_knl_Clock_TimerProxy_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab)
{
    return ti_sysbios_hal_TimerNull_Handle__label__S(obj, lab);
}

/* getNumTimers__E */
xdc_UInt ti_sysbios_knl_Clock_TimerProxy_getNumTimers__E( void )
{
    return ti_sysbios_hal_TimerNull_getNumTimers();
}

/* getStatus__E */
ti_sysbios_interfaces_ITimer_Status ti_sysbios_knl_Clock_TimerProxy_getStatus__E( xdc_UInt id )
{
    return ti_sysbios_hal_TimerNull_getStatus(id);
}

/* startup__E */
xdc_Void ti_sysbios_knl_Clock_TimerProxy_startup__E( void )
{
    ti_sysbios_hal_TimerNull_startup();
}

/* getMaxTicks__E */
xdc_UInt32 ti_sysbios_knl_Clock_TimerProxy_getMaxTicks__E( ti_sysbios_knl_Clock_TimerProxy_Handle __inst )
{
    return ti_sysbios_hal_TimerNull_getMaxTicks((ti_sysbios_hal_TimerNull_Handle)__inst);
}

/* setNextTick__E */
xdc_Void ti_sysbios_knl_Clock_TimerProxy_setNextTick__E( ti_sysbios_knl_Clock_TimerProxy_Handle __inst, xdc_UInt32 ticks )
{
    ti_sysbios_hal_TimerNull_setNextTick((ti_sysbios_hal_TimerNull_Handle)__inst, ticks);
}

/* start__E */
xdc_Void ti_sysbios_knl_Clock_TimerProxy_start__E( ti_sysbios_knl_Clock_TimerProxy_Handle __inst )
{
    ti_sysbios_hal_TimerNull_start((ti_sysbios_hal_TimerNull_Handle)__inst);
}

/* stop__E */
xdc_Void ti_sysbios_knl_Clock_TimerProxy_stop__E( ti_sysbios_knl_Clock_TimerProxy_Handle __inst )
{
    ti_sysbios_hal_TimerNull_stop((ti_sysbios_hal_TimerNull_Handle)__inst);
}

/* setPeriod__E */
xdc_Void ti_sysbios_knl_Clock_TimerProxy_setPeriod__E( ti_sysbios_knl_Clock_TimerProxy_Handle __inst, xdc_UInt32 period )
{
    ti_sysbios_hal_TimerNull_setPeriod((ti_sysbios_hal_TimerNull_Handle)__inst, period);
}

/* setPeriodMicroSecs__E */
xdc_Bool ti_sysbios_knl_Clock_TimerProxy_setPeriodMicroSecs__E( ti_sysbios_knl_Clock_TimerProxy_Handle __inst, xdc_UInt32 microsecs )
{
    return ti_sysbios_hal_TimerNull_setPeriodMicroSecs((ti_sysbios_hal_TimerNull_Handle)__inst, microsecs);
}

/* getPeriod__E */
xdc_UInt32 ti_sysbios_knl_Clock_TimerProxy_getPeriod__E( ti_sysbios_knl_Clock_TimerProxy_Handle __inst )
{
    return ti_sysbios_hal_TimerNull_getPeriod((ti_sysbios_hal_TimerNull_Handle)__inst);
}

/* getCount__E */
xdc_UInt32 ti_sysbios_knl_Clock_TimerProxy_getCount__E( ti_sysbios_knl_Clock_TimerProxy_Handle __inst )
{
    return ti_sysbios_hal_TimerNull_getCount((ti_sysbios_hal_TimerNull_Handle)__inst);
}

/* getFreq__E */
xdc_Void ti_sysbios_knl_Clock_TimerProxy_getFreq__E( ti_sysbios_knl_Clock_TimerProxy_Handle __inst, xdc_runtime_Types_FreqHz *freq )
{
    ti_sysbios_hal_TimerNull_getFreq((ti_sysbios_hal_TimerNull_Handle)__inst, freq);
}

/* getFunc__E */
ti_sysbios_interfaces_ITimer_FuncPtr ti_sysbios_knl_Clock_TimerProxy_getFunc__E( ti_sysbios_knl_Clock_TimerProxy_Handle __inst, xdc_UArg *arg )
{
    return ti_sysbios_hal_TimerNull_getFunc((ti_sysbios_hal_TimerNull_Handle)__inst, arg);
}

/* setFunc__E */
xdc_Void ti_sysbios_knl_Clock_TimerProxy_setFunc__E( ti_sysbios_knl_Clock_TimerProxy_Handle __inst, ti_sysbios_interfaces_ITimer_FuncPtr fxn, xdc_UArg arg )
{
    ti_sysbios_hal_TimerNull_setFunc((ti_sysbios_hal_TimerNull_Handle)__inst, fxn, arg);
}

/* trigger__E */
xdc_Void ti_sysbios_knl_Clock_TimerProxy_trigger__E( ti_sysbios_knl_Clock_TimerProxy_Handle __inst, xdc_UInt32 cycles )
{
    ti_sysbios_hal_TimerNull_trigger((ti_sysbios_hal_TimerNull_Handle)__inst, cycles);
}

/* getExpiredCounts__E */
xdc_UInt32 ti_sysbios_knl_Clock_TimerProxy_getExpiredCounts__E( ti_sysbios_knl_Clock_TimerProxy_Handle __inst )
{
    return ti_sysbios_hal_TimerNull_getExpiredCounts((ti_sysbios_hal_TimerNull_Handle)__inst);
}

/* getExpiredTicks__E */
xdc_UInt32 ti_sysbios_knl_Clock_TimerProxy_getExpiredTicks__E( ti_sysbios_knl_Clock_TimerProxy_Handle __inst, xdc_UInt32 tickPeriod )
{
    return ti_sysbios_hal_TimerNull_getExpiredTicks((ti_sysbios_hal_TimerNull_Handle)__inst, tickPeriod);
}

/* getCurrentTick__E */
xdc_UInt32 ti_sysbios_knl_Clock_TimerProxy_getCurrentTick__E( ti_sysbios_knl_Clock_TimerProxy_Handle __inst, xdc_Bool save )
{
    return ti_sysbios_hal_TimerNull_getCurrentTick((ti_sysbios_hal_TimerNull_Handle)__inst, save);
}


/*
 * ======== ti.sysbios.knl.Intrinsics_SupportProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.family.c62.IntrinsicsSupport */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Intrinsics_SupportProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_c62_IntrinsicsSupport_Module__startupDone__S();
}

/* maxbit__E */
xdc_UInt ti_sysbios_knl_Intrinsics_SupportProxy_maxbit__E( xdc_UInt bits )
{
    return ti_sysbios_family_c62_IntrinsicsSupport_maxbit(bits);
}


/*
 * ======== ti.sysbios.knl.Task_SupportProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.family.c62.TaskSupport */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Task_SupportProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_c62_TaskSupport_Module__startupDone__S();
}

/* start__E */
xdc_Ptr ti_sysbios_knl_Task_SupportProxy_start__E( xdc_Ptr curTask, ti_sysbios_interfaces_ITaskSupport_FuncPtr enter, ti_sysbios_interfaces_ITaskSupport_FuncPtr exit, xdc_runtime_Error_Block *eb )
{
    return ti_sysbios_family_c62_TaskSupport_start(curTask, enter, exit, eb);
}

/* swap__E */
xdc_Void ti_sysbios_knl_Task_SupportProxy_swap__E( xdc_Ptr *oldtskContext, xdc_Ptr *newtskContext )
{
    ti_sysbios_family_c62_TaskSupport_swap(oldtskContext, newtskContext);
}

/* checkStack__E */
xdc_Bool ti_sysbios_knl_Task_SupportProxy_checkStack__E( xdc_Char *stack, xdc_SizeT size )
{
    return ti_sysbios_family_c62_TaskSupport_checkStack(stack, size);
}

/* stackUsed__E */
xdc_SizeT ti_sysbios_knl_Task_SupportProxy_stackUsed__E( xdc_Char *stack, xdc_SizeT size )
{
    return ti_sysbios_family_c62_TaskSupport_stackUsed(stack, size);
}

/* getStackAlignment__E */
xdc_UInt ti_sysbios_knl_Task_SupportProxy_getStackAlignment__E( void )
{
    return ti_sysbios_family_c62_TaskSupport_getStackAlignment();
}

/* getDefaultStackSize__E */
xdc_SizeT ti_sysbios_knl_Task_SupportProxy_getDefaultStackSize__E( void )
{
    return ti_sysbios_family_c62_TaskSupport_getDefaultStackSize();
}

/* getCheckValueAddr__E */
xdc_Ptr ti_sysbios_knl_Task_SupportProxy_getCheckValueAddr__E( xdc_Ptr curTask )
{
    return ti_sysbios_family_c62_TaskSupport_getCheckValueAddr(curTask);
}


/*
 * ======== ti.sysbios.timers.dmtimer.Timer_TimerSupportProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.family.shared.vayu.TimerSupport */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_timers_dmtimer_Timer_TimerSupportProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_shared_vayu_TimerSupport_Module__startupDone__S();
}

/* enable__E */
xdc_Void ti_sysbios_timers_dmtimer_Timer_TimerSupportProxy_enable__E( xdc_UInt timerId, xdc_runtime_Error_Block *eb )
{
    ti_sysbios_family_shared_vayu_TimerSupport_enable(timerId, eb);
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
 * ======== xdc.runtime.Timestamp_SupportProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.family.c64p.TimestampProvider */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Timestamp_SupportProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_c64p_TimestampProvider_Module__startupDone__S();
}

/* get32__E */
xdc_Bits32 xdc_runtime_Timestamp_SupportProxy_get32__E( void )
{
    return ti_sysbios_family_c64p_TimestampProvider_get32();
}

/* get64__E */
xdc_Void xdc_runtime_Timestamp_SupportProxy_get64__E( xdc_runtime_Types_Timestamp64 *result )
{
    ti_sysbios_family_c64p_TimestampProvider_get64(result);
}

/* getFreq__E */
xdc_Void xdc_runtime_Timestamp_SupportProxy_getFreq__E( xdc_runtime_Types_FreqHz *freq )
{
    ti_sysbios_family_c64p_TimestampProvider_getFreq(freq);
}


/*
 * ======== ti.sysbios.family.c64p.Hwi OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_family_c64p_Hwi_Object2__ s0; char c; } ti_sysbios_family_c64p_Hwi___S1;
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Object__DESC__C, ".const:ti_sysbios_family_c64p_Hwi_Object__DESC__C");
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_family_c64p_Hwi_Object__DESC__C = {
    (xdc_CPtr)0, /* fxnTab */
    &ti_sysbios_family_c64p_Hwi_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_family_c64p_Hwi___S1) - sizeof(ti_sysbios_family_c64p_Hwi_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_family_c64p_Hwi_Object2__), /* objSize */
    (xdc_CPtr)&ti_sysbios_family_c64p_Hwi_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_family_c64p_Hwi_Params), /* prmsSize */
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
 * ======== ti.sysbios.hal.TimerNull OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_hal_TimerNull_Object2__ s0; char c; } ti_sysbios_hal_TimerNull___S1;
#pragma DATA_SECTION(ti_sysbios_hal_TimerNull_Object__DESC__C, ".const:ti_sysbios_hal_TimerNull_Object__DESC__C");
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_hal_TimerNull_Object__DESC__C = {
    (xdc_CPtr)&ti_sysbios_hal_TimerNull_Module__FXNS__C, /* fxnTab */
    &ti_sysbios_hal_TimerNull_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_hal_TimerNull___S1) - sizeof(ti_sysbios_hal_TimerNull_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_hal_TimerNull_Object2__), /* objSize */
    (xdc_CPtr)&ti_sysbios_hal_TimerNull_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_hal_TimerNull_Params), /* prmsSize */
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
 * ======== ti.sysbios.timers.dmtimer.Timer OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_timers_dmtimer_Timer_Object2__ s0; char c; } ti_sysbios_timers_dmtimer_Timer___S1;
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Object__DESC__C, ".const:ti_sysbios_timers_dmtimer_Timer_Object__DESC__C");
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_timers_dmtimer_Timer_Object__DESC__C = {
    (xdc_CPtr)0, /* fxnTab */
    &ti_sysbios_timers_dmtimer_Timer_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_timers_dmtimer_Timer___S1) - sizeof(ti_sysbios_timers_dmtimer_Timer_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_timers_dmtimer_Timer_Object2__), /* objSize */
    (xdc_CPtr)&ti_sysbios_timers_dmtimer_Timer_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_timers_dmtimer_Timer_Params), /* prmsSize */
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
 * ======== ti.sysbios.interfaces.ITimer VIRTUAL FUNCTIONS ========
 */

/* create */
ti_sysbios_interfaces_ITimer_Handle ti_sysbios_interfaces_ITimer_create( ti_sysbios_interfaces_ITimer_Module __mod, xdc_Int id, ti_sysbios_interfaces_ITimer_FuncPtr tickFxn, const ti_sysbios_interfaces_ITimer_Params *__prms, xdc_runtime_Error_Block *__eb )
{
    ti_sysbios_interfaces_ITimer_Args__create __args;
    __args.id = id;
    __args.tickFxn = tickFxn;
    return (ti_sysbios_interfaces_ITimer_Handle) __mod->__sysp->__create(0, 0, &__args, (const xdc_UChar*)__prms, sizeof (ti_sysbios_interfaces_ITimer_Params), __eb);
}

/* delete */
void ti_sysbios_interfaces_ITimer_delete( ti_sysbios_interfaces_ITimer_Handle *instp )
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
 * ======== ti.sysbios.family.c62.IntrinsicsSupport SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_c62_IntrinsicsSupport_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== ti.sysbios.family.c62.TaskSupport SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_c62_TaskSupport_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== ti.sysbios.family.c64p.EventCombiner SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_c64p_EventCombiner_Module__startupDone__S( void )
{
    return ti_sysbios_family_c64p_EventCombiner_Module__startupDone__F();
}



/*
 * ======== ti.sysbios.family.c64p.Exception SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_c64p_Exception_Module__startupDone__S( void )
{
    return ti_sysbios_family_c64p_Exception_Module__startupDone__F();
}



/*
 * ======== ti.sysbios.family.c64p.Hwi SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_family_c64p_Hwi_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_family_c64p_Hwi_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_family_c64p_Hwi_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_family_c64p_Hwi_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_family_c64p_Hwi_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_family_c64p_Hwi_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_family_c64p_Hwi_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_family_c64p_Hwi_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_family_c64p_Hwi_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_family_c64p_Hwi_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_family_c64p_Hwi_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_family_c64p_Hwi_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_family_c64p_Hwi_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_family_c64p_Hwi_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_family_c64p_Hwi_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_family_c64p_Hwi_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_family_c64p_Hwi_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_family_c64p_Hwi_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_c64p_Hwi_Module__startupDone__S( void )
{
    return ti_sysbios_family_c64p_Hwi_Module__startupDone__F();
}

/* Handle__label__S */
xdc_runtime_Types_Label *ti_sysbios_family_c64p_Hwi_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab) 
{
    lab->handle = obj;
    lab->modId = 32791;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_family_c64p_Hwi_Params__init__S( xdc_Ptr prms, const void *src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_CPtr)(src ? src : &ti_sysbios_family_c64p_Hwi_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_family_c64p_Hwi_Object__get__S(xdc_Ptr oa, xdc_Int i)
{
    if (oa) {
        return ((ti_sysbios_family_c64p_Hwi_Object__ *)oa) + i;
    }

    if (ti_sysbios_family_c64p_Hwi_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_family_c64p_Hwi_Object__ *)ti_sysbios_family_c64p_Hwi_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_family_c64p_Hwi_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_family_c64p_Hwi_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_family_c64p_Hwi_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_family_c64p_Hwi_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_family_c64p_Hwi_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_family_c64p_Hwi_Object__create__S (
    xdc_Ptr __obj, 
    xdc_SizeT __osz,
    const xdc_Ptr __aa,
    const ti_sysbios_family_c64p_Hwi___ParamsPtr __paramsPtr,
    xdc_SizeT __psz,
    xdc_runtime_Error_Block *__eb)
{
    ti_sysbios_family_c64p_Hwi_Args__create *__args = __aa;
    ti_sysbios_family_c64p_Hwi_Params __prms;
    ti_sysbios_family_c64p_Hwi_Object *__newobj;
    int iStat;

    /* common instance initialization */
    __newobj = xdc_runtime_Core_createObject__I(&ti_sysbios_family_c64p_Hwi_Object__DESC__C, __obj, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_family_c64p_Hwi_Params), __eb);
    if (__newobj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    iStat = ti_sysbios_family_c64p_Hwi_Instance_init__E(__newobj, __args->intNum, __args->hwiFxn, &__prms, __eb);
    if (xdc_runtime_Error_check(__eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_c64p_Hwi_Object__DESC__C, __newobj, (xdc_Fxn)ti_sysbios_family_c64p_Hwi_Instance_finalize__E, iStat, (xdc_Bool)(__obj != NULL));
        return NULL;
    }

    return __newobj;
}

/* create */
ti_sysbios_family_c64p_Hwi_Handle ti_sysbios_family_c64p_Hwi_create( xdc_Int intNum, ti_sysbios_interfaces_IHwi_FuncPtr hwiFxn, const ti_sysbios_family_c64p_Hwi_Params *__paramsPtr, xdc_runtime_Error_Block *__eb )
{
    ti_sysbios_family_c64p_Hwi_Params __prms;
    ti_sysbios_family_c64p_Hwi_Object *__newobj;
    int iStat;

    /* common instance initialization */
    __newobj = xdc_runtime_Core_createObject__I(&ti_sysbios_family_c64p_Hwi_Object__DESC__C, 0, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_family_c64p_Hwi_Params), __eb);
    if (__newobj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    iStat = ti_sysbios_family_c64p_Hwi_Instance_init__E(__newobj, intNum, hwiFxn, &__prms, __eb);
    if (xdc_runtime_Error_check(__eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_c64p_Hwi_Object__DESC__C, __newobj, (xdc_Fxn)ti_sysbios_family_c64p_Hwi_Instance_finalize__E, iStat, 0);
        return NULL;
    }

    return __newobj;
}

/* construct */
void ti_sysbios_family_c64p_Hwi_construct(ti_sysbios_family_c64p_Hwi_Struct *__obj, xdc_Int intNum, ti_sysbios_interfaces_IHwi_FuncPtr hwiFxn, const ti_sysbios_family_c64p_Hwi_Params *__paramsPtr, xdc_runtime_Error_Block *__eb )
{
    ti_sysbios_family_c64p_Hwi_Params __prms;
    int iStat;

    /* common instance initialization */
    xdc_runtime_Core_constructObject__I(&ti_sysbios_family_c64p_Hwi_Object__DESC__C, __obj, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_family_c64p_Hwi_Params), __eb);
    /* module-specific initialization */
    iStat = ti_sysbios_family_c64p_Hwi_Instance_init__E((xdc_Ptr)__obj, intNum, hwiFxn, &__prms, __eb);
    if (xdc_runtime_Error_check(__eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_c64p_Hwi_Object__DESC__C, (xdc_Ptr)__obj, (xdc_Fxn)ti_sysbios_family_c64p_Hwi_Instance_finalize__E, iStat, 1);
    }

}

/* Object__destruct__S */
xdc_Void ti_sysbios_family_c64p_Hwi_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_c64p_Hwi_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_family_c64p_Hwi_Instance_finalize__E, 0, TRUE);
}

/* destruct */
void ti_sysbios_family_c64p_Hwi_destruct(ti_sysbios_family_c64p_Hwi_Struct *obj)
{
    ti_sysbios_family_c64p_Hwi_Object__destruct__S(obj);
}

/* Object__delete__S */
xdc_Void ti_sysbios_family_c64p_Hwi_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_c64p_Hwi_Object__DESC__C, *((ti_sysbios_family_c64p_Hwi_Object**)instp), (xdc_Fxn)ti_sysbios_family_c64p_Hwi_Instance_finalize__E, 0, FALSE);
    *((ti_sysbios_family_c64p_Hwi_Handle*)instp) = NULL;
}

/* delete */
void ti_sysbios_family_c64p_Hwi_delete(ti_sysbios_family_c64p_Hwi_Handle *instp)
{
    ti_sysbios_family_c64p_Hwi_Object__delete__S(instp);
}


/*
 * ======== ti.sysbios.family.c64p.TimestampProvider SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_c64p_TimestampProvider_Module__startupDone__S( void )
{
    return ti_sysbios_family_c64p_TimestampProvider_Module__startupDone__F();
}



/*
 * ======== ti.sysbios.family.c66.Cache SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_c66_Cache_Module__startupDone__S( void )
{
    return ti_sysbios_family_c66_Cache_Module__startupDone__F();
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
 * ======== ti.sysbios.family.shared.vayu.TimerSupport SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_shared_vayu_TimerSupport_Module__startupDone__S( void )
{
    return ti_sysbios_family_shared_vayu_TimerSupport_Module__startupDone__F();
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
    lab->modId = 32822;
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
    lab->modId = 32823;
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
    return 0;
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
    lab->modId = 32804;
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
 * ======== ti.sysbios.hal.TimerNull SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_hal_TimerNull_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_hal_TimerNull_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_hal_TimerNull_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_hal_TimerNull_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_hal_TimerNull_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_hal_TimerNull_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_hal_TimerNull_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_hal_TimerNull_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_hal_TimerNull_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_hal_TimerNull_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_hal_TimerNull_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_hal_TimerNull_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_hal_TimerNull_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_hal_TimerNull_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_hal_TimerNull_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_hal_TimerNull_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_hal_TimerNull_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_hal_TimerNull_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_hal_TimerNull_Module__startupDone__S( void )
{
    return 1;
}

/* Handle__label__S */
xdc_runtime_Types_Label *ti_sysbios_hal_TimerNull_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab) 
{
    lab->handle = obj;
    lab->modId = 32805;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_hal_TimerNull_Params__init__S( xdc_Ptr prms, const void *src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_CPtr)(src ? src : &ti_sysbios_hal_TimerNull_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_hal_TimerNull_Object__get__S(xdc_Ptr oa, xdc_Int i)
{
    if (oa) {
        return ((ti_sysbios_hal_TimerNull_Object__ *)oa) + i;
    }

    if (ti_sysbios_hal_TimerNull_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_hal_TimerNull_Object__ *)ti_sysbios_hal_TimerNull_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_hal_TimerNull_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_hal_TimerNull_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_hal_TimerNull_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_hal_TimerNull_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_hal_TimerNull_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_hal_TimerNull_Object__create__S (
    xdc_Ptr __obj, 
    xdc_SizeT __osz,
    const xdc_Ptr __aa,
    const ti_sysbios_hal_TimerNull___ParamsPtr __paramsPtr,
    xdc_SizeT __psz,
    xdc_runtime_Error_Block *__eb)
{
    ti_sysbios_hal_TimerNull_Params __prms;
    ti_sysbios_hal_TimerNull_Object *__newobj;

    /* common instance initialization */
    __newobj = xdc_runtime_Core_createObject__I(&ti_sysbios_hal_TimerNull_Object__DESC__C, __obj, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_hal_TimerNull_Params), __eb);
    if (__newobj == NULL) {
        return NULL;
    }

    return __newobj;
}

/* create */
ti_sysbios_hal_TimerNull_Handle ti_sysbios_hal_TimerNull_create( xdc_Int id, ti_sysbios_interfaces_ITimer_FuncPtr tickFxn, const ti_sysbios_hal_TimerNull_Params *__paramsPtr, xdc_runtime_Error_Block *__eb )
{
    ti_sysbios_hal_TimerNull_Params __prms;
    ti_sysbios_hal_TimerNull_Object *__newobj;

    /* common instance initialization */
    __newobj = xdc_runtime_Core_createObject__I(&ti_sysbios_hal_TimerNull_Object__DESC__C, 0, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_hal_TimerNull_Params), __eb);
    if (__newobj == NULL) {
        return NULL;
    }

    return __newobj;
}

/* construct */
void ti_sysbios_hal_TimerNull_construct(ti_sysbios_hal_TimerNull_Struct *__obj, xdc_Int id, ti_sysbios_interfaces_ITimer_FuncPtr tickFxn, const ti_sysbios_hal_TimerNull_Params *__paramsPtr, xdc_runtime_Error_Block *__eb )
{
    ti_sysbios_hal_TimerNull_Params __prms;

    /* common instance initialization */
    xdc_runtime_Core_constructObject__I(&ti_sysbios_hal_TimerNull_Object__DESC__C, __obj, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_hal_TimerNull_Params), __eb);
}

/* Object__destruct__S */
xdc_Void ti_sysbios_hal_TimerNull_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_hal_TimerNull_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_hal_TimerNull_Instance_finalize__E, 0, TRUE);
}

/* destruct */
void ti_sysbios_hal_TimerNull_destruct(ti_sysbios_hal_TimerNull_Struct *obj)
{
    ti_sysbios_hal_TimerNull_Object__destruct__S(obj);
}

/* Object__delete__S */
xdc_Void ti_sysbios_hal_TimerNull_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_hal_TimerNull_Object__DESC__C, *((ti_sysbios_hal_TimerNull_Object**)instp), (xdc_Fxn)ti_sysbios_hal_TimerNull_Instance_finalize__E, 0, FALSE);
    *((ti_sysbios_hal_TimerNull_Handle*)instp) = NULL;
}

/* delete */
void ti_sysbios_hal_TimerNull_delete(ti_sysbios_hal_TimerNull_Handle *instp)
{
    ti_sysbios_hal_TimerNull_Object__delete__S(instp);
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
    lab->modId = 32825;
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
    lab->modId = 32794;
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
    return (void *)&ti_sysbios_hal_TimerNull_Module__FXNS__C;
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
    return 0;
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
    lab->modId = 32797;
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
    lab->modId = 32798;
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
    lab->modId = 32799;
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
    lab->modId = 32800;
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
 * ======== ti.sysbios.rts.ti.ThreadLocalStorage SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_rts_ti_ThreadLocalStorage_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== ti.sysbios.timers.dmtimer.Timer SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_timers_dmtimer_Timer_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_timers_dmtimer_Timer_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_timers_dmtimer_Timer_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_timers_dmtimer_Timer_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_timers_dmtimer_Timer_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_timers_dmtimer_Timer_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_timers_dmtimer_Timer_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_timers_dmtimer_Timer_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_timers_dmtimer_Timer_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_timers_dmtimer_Timer_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_timers_dmtimer_Timer_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_timers_dmtimer_Timer_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_timers_dmtimer_Timer_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_timers_dmtimer_Timer_Module__startupDone__S( void )
{
    return ti_sysbios_timers_dmtimer_Timer_Module__startupDone__F();
}

/* Handle__label__S */
xdc_runtime_Types_Label *ti_sysbios_timers_dmtimer_Timer_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab) 
{
    lab->handle = obj;
    lab->modId = 32814;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_timers_dmtimer_Timer_Params__init__S( xdc_Ptr prms, const void *src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_CPtr)(src ? src : &ti_sysbios_timers_dmtimer_Timer_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_timers_dmtimer_Timer_Object__get__S(xdc_Ptr oa, xdc_Int i)
{
    if (oa) {
        return ((ti_sysbios_timers_dmtimer_Timer_Object__ *)oa) + i;
    }

    if (ti_sysbios_timers_dmtimer_Timer_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_timers_dmtimer_Timer_Object__ *)ti_sysbios_timers_dmtimer_Timer_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_timers_dmtimer_Timer_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_timers_dmtimer_Timer_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_timers_dmtimer_Timer_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_timers_dmtimer_Timer_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_timers_dmtimer_Timer_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_timers_dmtimer_Timer_Object__create__S (
    xdc_Ptr __obj, 
    xdc_SizeT __osz,
    const xdc_Ptr __aa,
    const ti_sysbios_timers_dmtimer_Timer___ParamsPtr __paramsPtr,
    xdc_SizeT __psz,
    xdc_runtime_Error_Block *__eb)
{
    ti_sysbios_timers_dmtimer_Timer_Args__create *__args = __aa;
    ti_sysbios_timers_dmtimer_Timer_Params __prms;
    ti_sysbios_timers_dmtimer_Timer_Object *__newobj;
    int iStat;

    /* common instance initialization */
    __newobj = xdc_runtime_Core_createObject__I(&ti_sysbios_timers_dmtimer_Timer_Object__DESC__C, __obj, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_timers_dmtimer_Timer_Params), __eb);
    if (__newobj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    iStat = ti_sysbios_timers_dmtimer_Timer_Instance_init__E(__newobj, __args->id, __args->tickFxn, &__prms, __eb);
    if (xdc_runtime_Error_check(__eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_timers_dmtimer_Timer_Object__DESC__C, __newobj, (xdc_Fxn)ti_sysbios_timers_dmtimer_Timer_Instance_finalize__E, iStat, (xdc_Bool)(__obj != NULL));
        return NULL;
    }

    return __newobj;
}

/* create */
ti_sysbios_timers_dmtimer_Timer_Handle ti_sysbios_timers_dmtimer_Timer_create( xdc_Int id, ti_sysbios_interfaces_ITimer_FuncPtr tickFxn, const ti_sysbios_timers_dmtimer_Timer_Params *__paramsPtr, xdc_runtime_Error_Block *__eb )
{
    ti_sysbios_timers_dmtimer_Timer_Params __prms;
    ti_sysbios_timers_dmtimer_Timer_Object *__newobj;
    int iStat;

    /* common instance initialization */
    __newobj = xdc_runtime_Core_createObject__I(&ti_sysbios_timers_dmtimer_Timer_Object__DESC__C, 0, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_timers_dmtimer_Timer_Params), __eb);
    if (__newobj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    iStat = ti_sysbios_timers_dmtimer_Timer_Instance_init__E(__newobj, id, tickFxn, &__prms, __eb);
    if (xdc_runtime_Error_check(__eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_timers_dmtimer_Timer_Object__DESC__C, __newobj, (xdc_Fxn)ti_sysbios_timers_dmtimer_Timer_Instance_finalize__E, iStat, 0);
        return NULL;
    }

    return __newobj;
}

/* construct */
void ti_sysbios_timers_dmtimer_Timer_construct(ti_sysbios_timers_dmtimer_Timer_Struct *__obj, xdc_Int id, ti_sysbios_interfaces_ITimer_FuncPtr tickFxn, const ti_sysbios_timers_dmtimer_Timer_Params *__paramsPtr, xdc_runtime_Error_Block *__eb )
{
    ti_sysbios_timers_dmtimer_Timer_Params __prms;
    int iStat;

    /* common instance initialization */
    xdc_runtime_Core_constructObject__I(&ti_sysbios_timers_dmtimer_Timer_Object__DESC__C, __obj, &__prms, (xdc_Ptr)__paramsPtr, sizeof(ti_sysbios_timers_dmtimer_Timer_Params), __eb);
    /* module-specific initialization */
    iStat = ti_sysbios_timers_dmtimer_Timer_Instance_init__E((xdc_Ptr)__obj, id, tickFxn, &__prms, __eb);
    if (xdc_runtime_Error_check(__eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_timers_dmtimer_Timer_Object__DESC__C, (xdc_Ptr)__obj, (xdc_Fxn)ti_sysbios_timers_dmtimer_Timer_Instance_finalize__E, iStat, 1);
    }

}

/* Object__destruct__S */
xdc_Void ti_sysbios_timers_dmtimer_Timer_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_timers_dmtimer_Timer_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_timers_dmtimer_Timer_Instance_finalize__E, 0, TRUE);
}

/* destruct */
void ti_sysbios_timers_dmtimer_Timer_destruct(ti_sysbios_timers_dmtimer_Timer_Struct *obj)
{
    ti_sysbios_timers_dmtimer_Timer_Object__destruct__S(obj);
}

/* Object__delete__S */
xdc_Void ti_sysbios_timers_dmtimer_Timer_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_timers_dmtimer_Timer_Object__DESC__C, *((ti_sysbios_timers_dmtimer_Timer_Object**)instp), (xdc_Fxn)ti_sysbios_timers_dmtimer_Timer_Instance_finalize__E, 0, FALSE);
    *((ti_sysbios_timers_dmtimer_Timer_Handle*)instp) = NULL;
}

/* delete */
void ti_sysbios_timers_dmtimer_Timer_delete(ti_sysbios_timers_dmtimer_Timer_Handle *instp)
{
    ti_sysbios_timers_dmtimer_Timer_Object__delete__S(instp);
}


/*
 * ======== ti.sysbios.timers.dmtimer.Timer_TimerSupportProxy SYSTEM FUNCTIONS ========
 */


xdc_Bool ti_sysbios_timers_dmtimer_Timer_TimerSupportProxy_Proxy__abstract__S( void )
{
    return 0;
}
xdc_Ptr ti_sysbios_timers_dmtimer_Timer_TimerSupportProxy_Proxy__delegate__S( void )
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
 * ======== xdc.runtime.Timestamp SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Timestamp_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== xdc.runtime.TimestampNull SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_TimestampNull_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== xdc.runtime.Timestamp_SupportProxy SYSTEM FUNCTIONS ========
 */


xdc_Bool xdc_runtime_Timestamp_SupportProxy_Proxy__abstract__S( void )
{
    return 0;
}
xdc_Ptr xdc_runtime_Timestamp_SupportProxy_Proxy__delegate__S( void )
{
    return 0;
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

