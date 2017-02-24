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
 *     VIRTUAL FUNCTIONS
 *     FUNCTION DECLARATIONS
 *     CONVERTORS
 *     SYSTEM FUNCTIONS
 *     
 *     EPILOGUE
 *     STATE STRUCTURES
 *     PREFIX ALIASES
 */


/*
 * ======== PROLOGUE ========
 */

#ifndef ti_sdo_ipc_family_vayu_NotifySetup__include
#define ti_sdo_ipc_family_vayu_NotifySetup__include

#ifndef __nested__
#define __nested__
#define ti_sdo_ipc_family_vayu_NotifySetup__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sdo_ipc_family_vayu_NotifySetup___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <ti/sdo/ipc/family/vayu/package/package.defs.h>

#include <xdc/runtime/Assert.h>
#include <ti/sdo/utils/MultiProc.h>
#include <ti/sdo/ipc/interfaces/INotifySetup.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* DriverIsr */
typedef xdc_Void (*ti_sdo_ipc_family_vayu_NotifySetup_DriverIsr)(xdc_UInt16);

/* Driver */
enum ti_sdo_ipc_family_vayu_NotifySetup_Driver {
    ti_sdo_ipc_family_vayu_NotifySetup_Driver_SHAREDMEMORY = 0x01,
    ti_sdo_ipc_family_vayu_NotifySetup_Driver_MAILBOX = 0x02
};
typedef enum ti_sdo_ipc_family_vayu_NotifySetup_Driver ti_sdo_ipc_family_vayu_NotifySetup_Driver;

/* Connection */
struct ti_sdo_ipc_family_vayu_NotifySetup_Connection {
    ti_sdo_ipc_family_vayu_NotifySetup_Driver driver;
    xdc_String procName;
};


/*
 * ======== INTERNAL DEFINITIONS ========
 */

/* NUM_CORES */
#define ti_sdo_ipc_family_vayu_NotifySetup_NUM_CORES (11)

/* NUM_EVES */
#define ti_sdo_ipc_family_vayu_NotifySetup_NUM_EVES (4)

/* NUM_EVE_MBX */
#define ti_sdo_ipc_family_vayu_NotifySetup_NUM_EVE_MBX (12)

/* NUM_SYS_MBX */
#define ti_sdo_ipc_family_vayu_NotifySetup_NUM_SYS_MBX (4)

/* DrvBind */
struct ti_sdo_ipc_family_vayu_NotifySetup_DrvBind {
    ti_sdo_ipc_family_vayu_NotifySetup_Driver driver;
    xdc_UInt16 procId;
};

/* Module_State */
typedef xdc_UInt16 __T1_ti_sdo_ipc_family_vayu_NotifySetup_Module_State__numPlugged;
typedef xdc_UInt16 *__ARRAY1_ti_sdo_ipc_family_vayu_NotifySetup_Module_State__numPlugged;
typedef __ARRAY1_ti_sdo_ipc_family_vayu_NotifySetup_Module_State__numPlugged __TA_ti_sdo_ipc_family_vayu_NotifySetup_Module_State__numPlugged;
typedef ti_sdo_ipc_family_vayu_NotifySetup_DrvBind __T1_ti_sdo_ipc_family_vayu_NotifySetup_Module_State__connAry;
typedef struct { int length; ti_sdo_ipc_family_vayu_NotifySetup_DrvBind *elem; } __ARRAY1_ti_sdo_ipc_family_vayu_NotifySetup_Module_State__connAry;
typedef __ARRAY1_ti_sdo_ipc_family_vayu_NotifySetup_Module_State__connAry __TA_ti_sdo_ipc_family_vayu_NotifySetup_Module_State__connAry;
typedef xdc_UInt16 __T1_ti_sdo_ipc_family_vayu_NotifySetup_Module_State__interruptTable;
typedef xdc_UInt16 __ARRAY1_ti_sdo_ipc_family_vayu_NotifySetup_Module_State__interruptTable[11];
typedef __ARRAY1_ti_sdo_ipc_family_vayu_NotifySetup_Module_State__interruptTable __TA_ti_sdo_ipc_family_vayu_NotifySetup_Module_State__interruptTable;
typedef ti_sdo_ipc_family_vayu_NotifySetup_DriverIsr __T1_ti_sdo_ipc_family_vayu_NotifySetup_Module_State__isrDispatchTable;
typedef ti_sdo_ipc_family_vayu_NotifySetup_DriverIsr __ARRAY1_ti_sdo_ipc_family_vayu_NotifySetup_Module_State__isrDispatchTable[11];
typedef __ARRAY1_ti_sdo_ipc_family_vayu_NotifySetup_Module_State__isrDispatchTable __TA_ti_sdo_ipc_family_vayu_NotifySetup_Module_State__isrDispatchTable;


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_sdo_ipc_family_vayu_NotifySetup_Module__diagsEnabled;
__extern __FAR__ const CT__ti_sdo_ipc_family_vayu_NotifySetup_Module__diagsEnabled ti_sdo_ipc_family_vayu_NotifySetup_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_sdo_ipc_family_vayu_NotifySetup_Module__diagsIncluded;
__extern __FAR__ const CT__ti_sdo_ipc_family_vayu_NotifySetup_Module__diagsIncluded ti_sdo_ipc_family_vayu_NotifySetup_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16 *CT__ti_sdo_ipc_family_vayu_NotifySetup_Module__diagsMask;
__extern __FAR__ const CT__ti_sdo_ipc_family_vayu_NotifySetup_Module__diagsMask ti_sdo_ipc_family_vayu_NotifySetup_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_sdo_ipc_family_vayu_NotifySetup_Module__gateObj;
__extern __FAR__ const CT__ti_sdo_ipc_family_vayu_NotifySetup_Module__gateObj ti_sdo_ipc_family_vayu_NotifySetup_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_sdo_ipc_family_vayu_NotifySetup_Module__gatePrms;
__extern __FAR__ const CT__ti_sdo_ipc_family_vayu_NotifySetup_Module__gatePrms ti_sdo_ipc_family_vayu_NotifySetup_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_sdo_ipc_family_vayu_NotifySetup_Module__id;
__extern __FAR__ const CT__ti_sdo_ipc_family_vayu_NotifySetup_Module__id ti_sdo_ipc_family_vayu_NotifySetup_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_sdo_ipc_family_vayu_NotifySetup_Module__loggerDefined;
__extern __FAR__ const CT__ti_sdo_ipc_family_vayu_NotifySetup_Module__loggerDefined ti_sdo_ipc_family_vayu_NotifySetup_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_sdo_ipc_family_vayu_NotifySetup_Module__loggerObj;
__extern __FAR__ const CT__ti_sdo_ipc_family_vayu_NotifySetup_Module__loggerObj ti_sdo_ipc_family_vayu_NotifySetup_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_sdo_ipc_family_vayu_NotifySetup_Module__loggerFxn0;
__extern __FAR__ const CT__ti_sdo_ipc_family_vayu_NotifySetup_Module__loggerFxn0 ti_sdo_ipc_family_vayu_NotifySetup_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_sdo_ipc_family_vayu_NotifySetup_Module__loggerFxn1;
__extern __FAR__ const CT__ti_sdo_ipc_family_vayu_NotifySetup_Module__loggerFxn1 ti_sdo_ipc_family_vayu_NotifySetup_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_sdo_ipc_family_vayu_NotifySetup_Module__loggerFxn2;
__extern __FAR__ const CT__ti_sdo_ipc_family_vayu_NotifySetup_Module__loggerFxn2 ti_sdo_ipc_family_vayu_NotifySetup_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_sdo_ipc_family_vayu_NotifySetup_Module__loggerFxn4;
__extern __FAR__ const CT__ti_sdo_ipc_family_vayu_NotifySetup_Module__loggerFxn4 ti_sdo_ipc_family_vayu_NotifySetup_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_sdo_ipc_family_vayu_NotifySetup_Module__loggerFxn8;
__extern __FAR__ const CT__ti_sdo_ipc_family_vayu_NotifySetup_Module__loggerFxn8 ti_sdo_ipc_family_vayu_NotifySetup_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_sdo_ipc_family_vayu_NotifySetup_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_sdo_ipc_family_vayu_NotifySetup_Module__startupDoneFxn ti_sdo_ipc_family_vayu_NotifySetup_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_sdo_ipc_family_vayu_NotifySetup_Object__count;
__extern __FAR__ const CT__ti_sdo_ipc_family_vayu_NotifySetup_Object__count ti_sdo_ipc_family_vayu_NotifySetup_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_sdo_ipc_family_vayu_NotifySetup_Object__heap;
__extern __FAR__ const CT__ti_sdo_ipc_family_vayu_NotifySetup_Object__heap ti_sdo_ipc_family_vayu_NotifySetup_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_sdo_ipc_family_vayu_NotifySetup_Object__sizeof;
__extern __FAR__ const CT__ti_sdo_ipc_family_vayu_NotifySetup_Object__sizeof ti_sdo_ipc_family_vayu_NotifySetup_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_sdo_ipc_family_vayu_NotifySetup_Object__table;
__extern __FAR__ const CT__ti_sdo_ipc_family_vayu_NotifySetup_Object__table ti_sdo_ipc_family_vayu_NotifySetup_Object__table__C;

/* dspIntVectId */
#ifdef ti_sdo_ipc_family_vayu_NotifySetup_dspIntVectId__D
#define ti_sdo_ipc_family_vayu_NotifySetup_dspIntVectId (ti_sdo_ipc_family_vayu_NotifySetup_dspIntVectId__D)
#else
#define ti_sdo_ipc_family_vayu_NotifySetup_dspIntVectId (ti_sdo_ipc_family_vayu_NotifySetup_dspIntVectId__C)
typedef xdc_UInt CT__ti_sdo_ipc_family_vayu_NotifySetup_dspIntVectId;
__extern __FAR__ const CT__ti_sdo_ipc_family_vayu_NotifySetup_dspIntVectId ti_sdo_ipc_family_vayu_NotifySetup_dspIntVectId__C;
#endif

/* eveIntVectId_INTC0 */
#ifdef ti_sdo_ipc_family_vayu_NotifySetup_eveIntVectId_INTC0__D
#define ti_sdo_ipc_family_vayu_NotifySetup_eveIntVectId_INTC0 (ti_sdo_ipc_family_vayu_NotifySetup_eveIntVectId_INTC0__D)
#else
#define ti_sdo_ipc_family_vayu_NotifySetup_eveIntVectId_INTC0 (ti_sdo_ipc_family_vayu_NotifySetup_eveIntVectId_INTC0__C)
typedef xdc_UInt CT__ti_sdo_ipc_family_vayu_NotifySetup_eveIntVectId_INTC0;
__extern __FAR__ const CT__ti_sdo_ipc_family_vayu_NotifySetup_eveIntVectId_INTC0 ti_sdo_ipc_family_vayu_NotifySetup_eveIntVectId_INTC0__C;
#endif

/* eveIntVectId_INTC1 */
#ifdef ti_sdo_ipc_family_vayu_NotifySetup_eveIntVectId_INTC1__D
#define ti_sdo_ipc_family_vayu_NotifySetup_eveIntVectId_INTC1 (ti_sdo_ipc_family_vayu_NotifySetup_eveIntVectId_INTC1__D)
#else
#define ti_sdo_ipc_family_vayu_NotifySetup_eveIntVectId_INTC1 (ti_sdo_ipc_family_vayu_NotifySetup_eveIntVectId_INTC1__C)
typedef xdc_UInt CT__ti_sdo_ipc_family_vayu_NotifySetup_eveIntVectId_INTC1;
__extern __FAR__ const CT__ti_sdo_ipc_family_vayu_NotifySetup_eveIntVectId_INTC1 ti_sdo_ipc_family_vayu_NotifySetup_eveIntVectId_INTC1__C;
#endif

/* mailboxTable */
#define ti_sdo_ipc_family_vayu_NotifySetup_mailboxTable (ti_sdo_ipc_family_vayu_NotifySetup_mailboxTable__C)
typedef xdc_UInt32 __T1_ti_sdo_ipc_family_vayu_NotifySetup_mailboxTable;
typedef xdc_UInt32 __ARRAY1_ti_sdo_ipc_family_vayu_NotifySetup_mailboxTable[11 * 11];
typedef __ARRAY1_ti_sdo_ipc_family_vayu_NotifySetup_mailboxTable __TA_ti_sdo_ipc_family_vayu_NotifySetup_mailboxTable;
typedef __TA_ti_sdo_ipc_family_vayu_NotifySetup_mailboxTable CT__ti_sdo_ipc_family_vayu_NotifySetup_mailboxTable;
__extern __FAR__ const CT__ti_sdo_ipc_family_vayu_NotifySetup_mailboxTable ti_sdo_ipc_family_vayu_NotifySetup_mailboxTable__C;

/* mailboxBaseAddr */
#define ti_sdo_ipc_family_vayu_NotifySetup_mailboxBaseAddr (ti_sdo_ipc_family_vayu_NotifySetup_mailboxBaseAddr__C)
typedef xdc_UInt32 __T1_ti_sdo_ipc_family_vayu_NotifySetup_mailboxBaseAddr;
typedef xdc_UInt32 __ARRAY1_ti_sdo_ipc_family_vayu_NotifySetup_mailboxBaseAddr[12 + 4];
typedef __ARRAY1_ti_sdo_ipc_family_vayu_NotifySetup_mailboxBaseAddr __TA_ti_sdo_ipc_family_vayu_NotifySetup_mailboxBaseAddr;
typedef __TA_ti_sdo_ipc_family_vayu_NotifySetup_mailboxBaseAddr CT__ti_sdo_ipc_family_vayu_NotifySetup_mailboxBaseAddr;
__extern __FAR__ const CT__ti_sdo_ipc_family_vayu_NotifySetup_mailboxBaseAddr ti_sdo_ipc_family_vayu_NotifySetup_mailboxBaseAddr__C;

/* eve1ProcId */
#ifdef ti_sdo_ipc_family_vayu_NotifySetup_eve1ProcId__D
#define ti_sdo_ipc_family_vayu_NotifySetup_eve1ProcId (ti_sdo_ipc_family_vayu_NotifySetup_eve1ProcId__D)
#else
#define ti_sdo_ipc_family_vayu_NotifySetup_eve1ProcId (ti_sdo_ipc_family_vayu_NotifySetup_eve1ProcId__C)
typedef xdc_UInt CT__ti_sdo_ipc_family_vayu_NotifySetup_eve1ProcId;
__extern __FAR__ const CT__ti_sdo_ipc_family_vayu_NotifySetup_eve1ProcId ti_sdo_ipc_family_vayu_NotifySetup_eve1ProcId__C;
#endif

/* eve2ProcId */
#ifdef ti_sdo_ipc_family_vayu_NotifySetup_eve2ProcId__D
#define ti_sdo_ipc_family_vayu_NotifySetup_eve2ProcId (ti_sdo_ipc_family_vayu_NotifySetup_eve2ProcId__D)
#else
#define ti_sdo_ipc_family_vayu_NotifySetup_eve2ProcId (ti_sdo_ipc_family_vayu_NotifySetup_eve2ProcId__C)
typedef xdc_UInt CT__ti_sdo_ipc_family_vayu_NotifySetup_eve2ProcId;
__extern __FAR__ const CT__ti_sdo_ipc_family_vayu_NotifySetup_eve2ProcId ti_sdo_ipc_family_vayu_NotifySetup_eve2ProcId__C;
#endif

/* eve3ProcId */
#ifdef ti_sdo_ipc_family_vayu_NotifySetup_eve3ProcId__D
#define ti_sdo_ipc_family_vayu_NotifySetup_eve3ProcId (ti_sdo_ipc_family_vayu_NotifySetup_eve3ProcId__D)
#else
#define ti_sdo_ipc_family_vayu_NotifySetup_eve3ProcId (ti_sdo_ipc_family_vayu_NotifySetup_eve3ProcId__C)
typedef xdc_UInt CT__ti_sdo_ipc_family_vayu_NotifySetup_eve3ProcId;
__extern __FAR__ const CT__ti_sdo_ipc_family_vayu_NotifySetup_eve3ProcId ti_sdo_ipc_family_vayu_NotifySetup_eve3ProcId__C;
#endif

/* eve4ProcId */
#ifdef ti_sdo_ipc_family_vayu_NotifySetup_eve4ProcId__D
#define ti_sdo_ipc_family_vayu_NotifySetup_eve4ProcId (ti_sdo_ipc_family_vayu_NotifySetup_eve4ProcId__D)
#else
#define ti_sdo_ipc_family_vayu_NotifySetup_eve4ProcId (ti_sdo_ipc_family_vayu_NotifySetup_eve4ProcId__C)
typedef xdc_UInt CT__ti_sdo_ipc_family_vayu_NotifySetup_eve4ProcId;
__extern __FAR__ const CT__ti_sdo_ipc_family_vayu_NotifySetup_eve4ProcId ti_sdo_ipc_family_vayu_NotifySetup_eve4ProcId__C;
#endif

/* dsp1ProcId */
#ifdef ti_sdo_ipc_family_vayu_NotifySetup_dsp1ProcId__D
#define ti_sdo_ipc_family_vayu_NotifySetup_dsp1ProcId (ti_sdo_ipc_family_vayu_NotifySetup_dsp1ProcId__D)
#else
#define ti_sdo_ipc_family_vayu_NotifySetup_dsp1ProcId (ti_sdo_ipc_family_vayu_NotifySetup_dsp1ProcId__C)
typedef xdc_UInt CT__ti_sdo_ipc_family_vayu_NotifySetup_dsp1ProcId;
__extern __FAR__ const CT__ti_sdo_ipc_family_vayu_NotifySetup_dsp1ProcId ti_sdo_ipc_family_vayu_NotifySetup_dsp1ProcId__C;
#endif

/* dsp2ProcId */
#ifdef ti_sdo_ipc_family_vayu_NotifySetup_dsp2ProcId__D
#define ti_sdo_ipc_family_vayu_NotifySetup_dsp2ProcId (ti_sdo_ipc_family_vayu_NotifySetup_dsp2ProcId__D)
#else
#define ti_sdo_ipc_family_vayu_NotifySetup_dsp2ProcId (ti_sdo_ipc_family_vayu_NotifySetup_dsp2ProcId__C)
typedef xdc_UInt CT__ti_sdo_ipc_family_vayu_NotifySetup_dsp2ProcId;
__extern __FAR__ const CT__ti_sdo_ipc_family_vayu_NotifySetup_dsp2ProcId ti_sdo_ipc_family_vayu_NotifySetup_dsp2ProcId__C;
#endif

/* ipu1_0ProcId */
#ifdef ti_sdo_ipc_family_vayu_NotifySetup_ipu1_0ProcId__D
#define ti_sdo_ipc_family_vayu_NotifySetup_ipu1_0ProcId (ti_sdo_ipc_family_vayu_NotifySetup_ipu1_0ProcId__D)
#else
#define ti_sdo_ipc_family_vayu_NotifySetup_ipu1_0ProcId (ti_sdo_ipc_family_vayu_NotifySetup_ipu1_0ProcId__C)
typedef xdc_UInt CT__ti_sdo_ipc_family_vayu_NotifySetup_ipu1_0ProcId;
__extern __FAR__ const CT__ti_sdo_ipc_family_vayu_NotifySetup_ipu1_0ProcId ti_sdo_ipc_family_vayu_NotifySetup_ipu1_0ProcId__C;
#endif

/* ipu1_1ProcId */
#ifdef ti_sdo_ipc_family_vayu_NotifySetup_ipu1_1ProcId__D
#define ti_sdo_ipc_family_vayu_NotifySetup_ipu1_1ProcId (ti_sdo_ipc_family_vayu_NotifySetup_ipu1_1ProcId__D)
#else
#define ti_sdo_ipc_family_vayu_NotifySetup_ipu1_1ProcId (ti_sdo_ipc_family_vayu_NotifySetup_ipu1_1ProcId__C)
typedef xdc_UInt CT__ti_sdo_ipc_family_vayu_NotifySetup_ipu1_1ProcId;
__extern __FAR__ const CT__ti_sdo_ipc_family_vayu_NotifySetup_ipu1_1ProcId ti_sdo_ipc_family_vayu_NotifySetup_ipu1_1ProcId__C;
#endif

/* ipu2_0ProcId */
#ifdef ti_sdo_ipc_family_vayu_NotifySetup_ipu2_0ProcId__D
#define ti_sdo_ipc_family_vayu_NotifySetup_ipu2_0ProcId (ti_sdo_ipc_family_vayu_NotifySetup_ipu2_0ProcId__D)
#else
#define ti_sdo_ipc_family_vayu_NotifySetup_ipu2_0ProcId (ti_sdo_ipc_family_vayu_NotifySetup_ipu2_0ProcId__C)
typedef xdc_UInt CT__ti_sdo_ipc_family_vayu_NotifySetup_ipu2_0ProcId;
__extern __FAR__ const CT__ti_sdo_ipc_family_vayu_NotifySetup_ipu2_0ProcId ti_sdo_ipc_family_vayu_NotifySetup_ipu2_0ProcId__C;
#endif

/* ipu2_1ProcId */
#ifdef ti_sdo_ipc_family_vayu_NotifySetup_ipu2_1ProcId__D
#define ti_sdo_ipc_family_vayu_NotifySetup_ipu2_1ProcId (ti_sdo_ipc_family_vayu_NotifySetup_ipu2_1ProcId__D)
#else
#define ti_sdo_ipc_family_vayu_NotifySetup_ipu2_1ProcId (ti_sdo_ipc_family_vayu_NotifySetup_ipu2_1ProcId__C)
typedef xdc_UInt CT__ti_sdo_ipc_family_vayu_NotifySetup_ipu2_1ProcId;
__extern __FAR__ const CT__ti_sdo_ipc_family_vayu_NotifySetup_ipu2_1ProcId ti_sdo_ipc_family_vayu_NotifySetup_ipu2_1ProcId__C;
#endif

/* hostProcId */
#ifdef ti_sdo_ipc_family_vayu_NotifySetup_hostProcId__D
#define ti_sdo_ipc_family_vayu_NotifySetup_hostProcId (ti_sdo_ipc_family_vayu_NotifySetup_hostProcId__D)
#else
#define ti_sdo_ipc_family_vayu_NotifySetup_hostProcId (ti_sdo_ipc_family_vayu_NotifySetup_hostProcId__C)
typedef xdc_UInt CT__ti_sdo_ipc_family_vayu_NotifySetup_hostProcId;
__extern __FAR__ const CT__ti_sdo_ipc_family_vayu_NotifySetup_hostProcId ti_sdo_ipc_family_vayu_NotifySetup_hostProcId__C;
#endif

/* procIdTable */
#define ti_sdo_ipc_family_vayu_NotifySetup_procIdTable (ti_sdo_ipc_family_vayu_NotifySetup_procIdTable__C)
typedef xdc_UInt32 __T1_ti_sdo_ipc_family_vayu_NotifySetup_procIdTable;
typedef xdc_UInt32 __ARRAY1_ti_sdo_ipc_family_vayu_NotifySetup_procIdTable[11];
typedef __ARRAY1_ti_sdo_ipc_family_vayu_NotifySetup_procIdTable __TA_ti_sdo_ipc_family_vayu_NotifySetup_procIdTable;
typedef __TA_ti_sdo_ipc_family_vayu_NotifySetup_procIdTable CT__ti_sdo_ipc_family_vayu_NotifySetup_procIdTable;
__extern __FAR__ const CT__ti_sdo_ipc_family_vayu_NotifySetup_procIdTable ti_sdo_ipc_family_vayu_NotifySetup_procIdTable__C;

/* A_internal */
#define ti_sdo_ipc_family_vayu_NotifySetup_A_internal (ti_sdo_ipc_family_vayu_NotifySetup_A_internal__C)
typedef xdc_runtime_Assert_Id CT__ti_sdo_ipc_family_vayu_NotifySetup_A_internal;
__extern __FAR__ const CT__ti_sdo_ipc_family_vayu_NotifySetup_A_internal ti_sdo_ipc_family_vayu_NotifySetup_A_internal__C;


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct ti_sdo_ipc_family_vayu_NotifySetup_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2* __sysp;
    xdc_Int (*attach)(xdc_UInt16, xdc_Ptr);
    xdc_SizeT (*sharedMemReq)(xdc_UInt16, xdc_Ptr);
    xdc_UInt16 (*numIntLines)(xdc_UInt16);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Module__FXNS__C */
__extern const ti_sdo_ipc_family_vayu_NotifySetup_Fxns__ ti_sdo_ipc_family_vayu_NotifySetup_Module__FXNS__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_sdo_ipc_family_vayu_NotifySetup_Module_startup ti_sdo_ipc_family_vayu_NotifySetup_Module_startup__E
xdc__CODESECT(ti_sdo_ipc_family_vayu_NotifySetup_Module_startup__E, "ti_sdo_ipc_family_vayu_NotifySetup_Module_startup")
__extern xdc_Int ti_sdo_ipc_family_vayu_NotifySetup_Module_startup__E( xdc_Int state );
xdc__CODESECT(ti_sdo_ipc_family_vayu_NotifySetup_Module_startup__F, "ti_sdo_ipc_family_vayu_NotifySetup_Module_startup")
__extern xdc_Int ti_sdo_ipc_family_vayu_NotifySetup_Module_startup__F( xdc_Int state );

/* Module__startupDone__S */
xdc__CODESECT(ti_sdo_ipc_family_vayu_NotifySetup_Module__startupDone__S, "ti_sdo_ipc_family_vayu_NotifySetup_Module__startupDone__S")
__extern xdc_Bool ti_sdo_ipc_family_vayu_NotifySetup_Module__startupDone__S( void );

/* attach__E */
#define ti_sdo_ipc_family_vayu_NotifySetup_attach ti_sdo_ipc_family_vayu_NotifySetup_attach__E
xdc__CODESECT(ti_sdo_ipc_family_vayu_NotifySetup_attach__E, "ti_sdo_ipc_family_vayu_NotifySetup_attach")
__extern xdc_Int ti_sdo_ipc_family_vayu_NotifySetup_attach__E( xdc_UInt16 remoteProcId, xdc_Ptr sharedAddr );

/* sharedMemReq__E */
#define ti_sdo_ipc_family_vayu_NotifySetup_sharedMemReq ti_sdo_ipc_family_vayu_NotifySetup_sharedMemReq__E
xdc__CODESECT(ti_sdo_ipc_family_vayu_NotifySetup_sharedMemReq__E, "ti_sdo_ipc_family_vayu_NotifySetup_sharedMemReq")
__extern xdc_SizeT ti_sdo_ipc_family_vayu_NotifySetup_sharedMemReq__E( xdc_UInt16 remoteProcId, xdc_Ptr sharedAddr );

/* numIntLines__E */
#define ti_sdo_ipc_family_vayu_NotifySetup_numIntLines ti_sdo_ipc_family_vayu_NotifySetup_numIntLines__E
xdc__CODESECT(ti_sdo_ipc_family_vayu_NotifySetup_numIntLines__E, "ti_sdo_ipc_family_vayu_NotifySetup_numIntLines")
__extern xdc_UInt16 ti_sdo_ipc_family_vayu_NotifySetup_numIntLines__E( xdc_UInt16 remoteProcId );

/* plugHwi__E */
#define ti_sdo_ipc_family_vayu_NotifySetup_plugHwi ti_sdo_ipc_family_vayu_NotifySetup_plugHwi__E
xdc__CODESECT(ti_sdo_ipc_family_vayu_NotifySetup_plugHwi__E, "ti_sdo_ipc_family_vayu_NotifySetup_plugHwi")
__extern xdc_Void ti_sdo_ipc_family_vayu_NotifySetup_plugHwi__E( xdc_UInt16 remoteProcId, xdc_Int cpuIntrNum, ti_sdo_ipc_family_vayu_NotifySetup_DriverIsr isr );
xdc__CODESECT(ti_sdo_ipc_family_vayu_NotifySetup_plugHwi__F, "ti_sdo_ipc_family_vayu_NotifySetup_plugHwi")
__extern xdc_Void ti_sdo_ipc_family_vayu_NotifySetup_plugHwi__F( xdc_UInt16 remoteProcId, xdc_Int cpuIntrNum, ti_sdo_ipc_family_vayu_NotifySetup_DriverIsr isr );

/* unplugHwi__E */
#define ti_sdo_ipc_family_vayu_NotifySetup_unplugHwi ti_sdo_ipc_family_vayu_NotifySetup_unplugHwi__E
xdc__CODESECT(ti_sdo_ipc_family_vayu_NotifySetup_unplugHwi__E, "ti_sdo_ipc_family_vayu_NotifySetup_unplugHwi")
__extern xdc_Void ti_sdo_ipc_family_vayu_NotifySetup_unplugHwi__E( xdc_UInt16 remoteProcId, xdc_Int cpuIntrNum );
xdc__CODESECT(ti_sdo_ipc_family_vayu_NotifySetup_unplugHwi__F, "ti_sdo_ipc_family_vayu_NotifySetup_unplugHwi")
__extern xdc_Void ti_sdo_ipc_family_vayu_NotifySetup_unplugHwi__F( xdc_UInt16 remoteProcId, xdc_Int cpuIntrNum );

/* interruptTable__E */
#define ti_sdo_ipc_family_vayu_NotifySetup_interruptTable ti_sdo_ipc_family_vayu_NotifySetup_interruptTable__E
xdc__CODESECT(ti_sdo_ipc_family_vayu_NotifySetup_interruptTable__E, "ti_sdo_ipc_family_vayu_NotifySetup_interruptTable")
__extern xdc_UInt16 ti_sdo_ipc_family_vayu_NotifySetup_interruptTable__E( xdc_Int srcVirtId );
xdc__CODESECT(ti_sdo_ipc_family_vayu_NotifySetup_interruptTable__F, "ti_sdo_ipc_family_vayu_NotifySetup_interruptTable")
__extern xdc_UInt16 ti_sdo_ipc_family_vayu_NotifySetup_interruptTable__F( xdc_Int srcVirtId );

/* driverType__I */
#define ti_sdo_ipc_family_vayu_NotifySetup_driverType ti_sdo_ipc_family_vayu_NotifySetup_driverType__I
xdc__CODESECT(ti_sdo_ipc_family_vayu_NotifySetup_driverType__I, "ti_sdo_ipc_family_vayu_NotifySetup_driverType")
__extern ti_sdo_ipc_family_vayu_NotifySetup_Driver ti_sdo_ipc_family_vayu_NotifySetup_driverType__I( xdc_UInt16 remoteProcId );

/* Shm_attach__I */
#define ti_sdo_ipc_family_vayu_NotifySetup_Shm_attach ti_sdo_ipc_family_vayu_NotifySetup_Shm_attach__I
xdc__CODESECT(ti_sdo_ipc_family_vayu_NotifySetup_Shm_attach__I, "ti_sdo_ipc_family_vayu_NotifySetup_Shm_attach")
__extern xdc_Int ti_sdo_ipc_family_vayu_NotifySetup_Shm_attach__I( xdc_UInt16 remoteProcId, xdc_Ptr sharedAddr );

/* Shm_sharedMemReq__I */
#define ti_sdo_ipc_family_vayu_NotifySetup_Shm_sharedMemReq ti_sdo_ipc_family_vayu_NotifySetup_Shm_sharedMemReq__I
xdc__CODESECT(ti_sdo_ipc_family_vayu_NotifySetup_Shm_sharedMemReq__I, "ti_sdo_ipc_family_vayu_NotifySetup_Shm_sharedMemReq")
__extern xdc_SizeT ti_sdo_ipc_family_vayu_NotifySetup_Shm_sharedMemReq__I( xdc_UInt16 remoteProcId, xdc_Ptr sharedAddr );

/* Mbx_attach__I */
#define ti_sdo_ipc_family_vayu_NotifySetup_Mbx_attach ti_sdo_ipc_family_vayu_NotifySetup_Mbx_attach__I
xdc__CODESECT(ti_sdo_ipc_family_vayu_NotifySetup_Mbx_attach__I, "ti_sdo_ipc_family_vayu_NotifySetup_Mbx_attach")
__extern xdc_Int ti_sdo_ipc_family_vayu_NotifySetup_Mbx_attach__I( xdc_UInt16 remoteProcId, xdc_Ptr sharedAddr );

/* Mbx_sharedMemReq__I */
#define ti_sdo_ipc_family_vayu_NotifySetup_Mbx_sharedMemReq ti_sdo_ipc_family_vayu_NotifySetup_Mbx_sharedMemReq__I
xdc__CODESECT(ti_sdo_ipc_family_vayu_NotifySetup_Mbx_sharedMemReq__I, "ti_sdo_ipc_family_vayu_NotifySetup_Mbx_sharedMemReq")
__extern xdc_SizeT ti_sdo_ipc_family_vayu_NotifySetup_Mbx_sharedMemReq__I( xdc_UInt16 remoteProcId, xdc_Ptr sharedAddr );

/* dispatchIsr__I */
#define ti_sdo_ipc_family_vayu_NotifySetup_dispatchIsr ti_sdo_ipc_family_vayu_NotifySetup_dispatchIsr__I
xdc__CODESECT(ti_sdo_ipc_family_vayu_NotifySetup_dispatchIsr__I, "ti_sdo_ipc_family_vayu_NotifySetup_dispatchIsr")
__extern xdc_Void ti_sdo_ipc_family_vayu_NotifySetup_dispatchIsr__I( xdc_UArg arg );


/*
 * ======== CONVERTORS ========
 */

/* Module_upCast */
static inline ti_sdo_ipc_interfaces_INotifySetup_Module ti_sdo_ipc_family_vayu_NotifySetup_Module_upCast( void )
{
    return (ti_sdo_ipc_interfaces_INotifySetup_Module)&ti_sdo_ipc_family_vayu_NotifySetup_Module__FXNS__C;
}

/* Module_to_ti_sdo_ipc_interfaces_INotifySetup */
#define ti_sdo_ipc_family_vayu_NotifySetup_Module_to_ti_sdo_ipc_interfaces_INotifySetup ti_sdo_ipc_family_vayu_NotifySetup_Module_upCast


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_sdo_ipc_family_vayu_NotifySetup_Module_startupDone() ti_sdo_ipc_family_vayu_NotifySetup_Module__startupDone__S()

/* Object_heap */
#define ti_sdo_ipc_family_vayu_NotifySetup_Object_heap() ti_sdo_ipc_family_vayu_NotifySetup_Object__heap__C

/* Module_heap */
#define ti_sdo_ipc_family_vayu_NotifySetup_Module_heap() ti_sdo_ipc_family_vayu_NotifySetup_Object__heap__C

/* Module_id */
static inline CT__ti_sdo_ipc_family_vayu_NotifySetup_Module__id ti_sdo_ipc_family_vayu_NotifySetup_Module_id( void ) 
{
    return ti_sdo_ipc_family_vayu_NotifySetup_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_sdo_ipc_family_vayu_NotifySetup_Module_hasMask( void ) 
{
    return (xdc_Bool)(ti_sdo_ipc_family_vayu_NotifySetup_Module__diagsMask__C != NULL);
}

/* Module_getMask */
static inline xdc_Bits16 ti_sdo_ipc_family_vayu_NotifySetup_Module_getMask( void ) 
{
    return ti_sdo_ipc_family_vayu_NotifySetup_Module__diagsMask__C != NULL ? *ti_sdo_ipc_family_vayu_NotifySetup_Module__diagsMask__C : (xdc_Bits16)0;
}

/* Module_setMask */
static inline xdc_Void ti_sdo_ipc_family_vayu_NotifySetup_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_sdo_ipc_family_vayu_NotifySetup_Module__diagsMask__C != NULL) {
        *ti_sdo_ipc_family_vayu_NotifySetup_Module__diagsMask__C = mask;
    }
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sdo_ipc_family_vayu_NotifySetup__top__
#undef __nested__
#endif

#endif /* ti_sdo_ipc_family_vayu_NotifySetup__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_sdo_ipc_family_vayu_NotifySetup__internalaccess))

#ifndef ti_sdo_ipc_family_vayu_NotifySetup__include_state
#define ti_sdo_ipc_family_vayu_NotifySetup__include_state

/* Module_State */
struct ti_sdo_ipc_family_vayu_NotifySetup_Module_State {
    __TA_ti_sdo_ipc_family_vayu_NotifySetup_Module_State__numPlugged numPlugged;
    __TA_ti_sdo_ipc_family_vayu_NotifySetup_Module_State__connAry connAry;
    __TA_ti_sdo_ipc_family_vayu_NotifySetup_Module_State__interruptTable interruptTable;
    __TA_ti_sdo_ipc_family_vayu_NotifySetup_Module_State__isrDispatchTable isrDispatchTable;
};

/* Module__state__V */
extern struct ti_sdo_ipc_family_vayu_NotifySetup_Module_State__ ti_sdo_ipc_family_vayu_NotifySetup_Module__state__V;

#endif /* ti_sdo_ipc_family_vayu_NotifySetup__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sdo_ipc_family_vayu_NotifySetup__nolocalnames)

#ifndef ti_sdo_ipc_family_vayu_NotifySetup__localnames__done
#define ti_sdo_ipc_family_vayu_NotifySetup__localnames__done

/* module prefix */
#define NotifySetup_DriverIsr ti_sdo_ipc_family_vayu_NotifySetup_DriverIsr
#define NotifySetup_Driver ti_sdo_ipc_family_vayu_NotifySetup_Driver
#define NotifySetup_Connection ti_sdo_ipc_family_vayu_NotifySetup_Connection
#define NotifySetup_NUM_CORES ti_sdo_ipc_family_vayu_NotifySetup_NUM_CORES
#define NotifySetup_NUM_EVES ti_sdo_ipc_family_vayu_NotifySetup_NUM_EVES
#define NotifySetup_NUM_EVE_MBX ti_sdo_ipc_family_vayu_NotifySetup_NUM_EVE_MBX
#define NotifySetup_NUM_SYS_MBX ti_sdo_ipc_family_vayu_NotifySetup_NUM_SYS_MBX
#define NotifySetup_DrvBind ti_sdo_ipc_family_vayu_NotifySetup_DrvBind
#define NotifySetup_Module_State ti_sdo_ipc_family_vayu_NotifySetup_Module_State
#define NotifySetup_Driver_SHAREDMEMORY ti_sdo_ipc_family_vayu_NotifySetup_Driver_SHAREDMEMORY
#define NotifySetup_Driver_MAILBOX ti_sdo_ipc_family_vayu_NotifySetup_Driver_MAILBOX
#define NotifySetup_dspIntVectId ti_sdo_ipc_family_vayu_NotifySetup_dspIntVectId
#define NotifySetup_eveIntVectId_INTC0 ti_sdo_ipc_family_vayu_NotifySetup_eveIntVectId_INTC0
#define NotifySetup_eveIntVectId_INTC1 ti_sdo_ipc_family_vayu_NotifySetup_eveIntVectId_INTC1
#define NotifySetup_mailboxTable ti_sdo_ipc_family_vayu_NotifySetup_mailboxTable
#define NotifySetup_mailboxBaseAddr ti_sdo_ipc_family_vayu_NotifySetup_mailboxBaseAddr
#define NotifySetup_eve1ProcId ti_sdo_ipc_family_vayu_NotifySetup_eve1ProcId
#define NotifySetup_eve2ProcId ti_sdo_ipc_family_vayu_NotifySetup_eve2ProcId
#define NotifySetup_eve3ProcId ti_sdo_ipc_family_vayu_NotifySetup_eve3ProcId
#define NotifySetup_eve4ProcId ti_sdo_ipc_family_vayu_NotifySetup_eve4ProcId
#define NotifySetup_dsp1ProcId ti_sdo_ipc_family_vayu_NotifySetup_dsp1ProcId
#define NotifySetup_dsp2ProcId ti_sdo_ipc_family_vayu_NotifySetup_dsp2ProcId
#define NotifySetup_ipu1_0ProcId ti_sdo_ipc_family_vayu_NotifySetup_ipu1_0ProcId
#define NotifySetup_ipu1_1ProcId ti_sdo_ipc_family_vayu_NotifySetup_ipu1_1ProcId
#define NotifySetup_ipu2_0ProcId ti_sdo_ipc_family_vayu_NotifySetup_ipu2_0ProcId
#define NotifySetup_ipu2_1ProcId ti_sdo_ipc_family_vayu_NotifySetup_ipu2_1ProcId
#define NotifySetup_hostProcId ti_sdo_ipc_family_vayu_NotifySetup_hostProcId
#define NotifySetup_procIdTable ti_sdo_ipc_family_vayu_NotifySetup_procIdTable
#define NotifySetup_A_internal ti_sdo_ipc_family_vayu_NotifySetup_A_internal
#define NotifySetup_attach ti_sdo_ipc_family_vayu_NotifySetup_attach
#define NotifySetup_sharedMemReq ti_sdo_ipc_family_vayu_NotifySetup_sharedMemReq
#define NotifySetup_numIntLines ti_sdo_ipc_family_vayu_NotifySetup_numIntLines
#define NotifySetup_plugHwi ti_sdo_ipc_family_vayu_NotifySetup_plugHwi
#define NotifySetup_unplugHwi ti_sdo_ipc_family_vayu_NotifySetup_unplugHwi
#define NotifySetup_interruptTable ti_sdo_ipc_family_vayu_NotifySetup_interruptTable
#define NotifySetup_Module_name ti_sdo_ipc_family_vayu_NotifySetup_Module_name
#define NotifySetup_Module_id ti_sdo_ipc_family_vayu_NotifySetup_Module_id
#define NotifySetup_Module_startup ti_sdo_ipc_family_vayu_NotifySetup_Module_startup
#define NotifySetup_Module_startupDone ti_sdo_ipc_family_vayu_NotifySetup_Module_startupDone
#define NotifySetup_Module_hasMask ti_sdo_ipc_family_vayu_NotifySetup_Module_hasMask
#define NotifySetup_Module_getMask ti_sdo_ipc_family_vayu_NotifySetup_Module_getMask
#define NotifySetup_Module_setMask ti_sdo_ipc_family_vayu_NotifySetup_Module_setMask
#define NotifySetup_Object_heap ti_sdo_ipc_family_vayu_NotifySetup_Object_heap
#define NotifySetup_Module_heap ti_sdo_ipc_family_vayu_NotifySetup_Module_heap
#define NotifySetup_Module_upCast ti_sdo_ipc_family_vayu_NotifySetup_Module_upCast
#define NotifySetup_Module_to_ti_sdo_ipc_interfaces_INotifySetup ti_sdo_ipc_family_vayu_NotifySetup_Module_to_ti_sdo_ipc_interfaces_INotifySetup

#endif /* ti_sdo_ipc_family_vayu_NotifySetup__localnames__done */
#endif
