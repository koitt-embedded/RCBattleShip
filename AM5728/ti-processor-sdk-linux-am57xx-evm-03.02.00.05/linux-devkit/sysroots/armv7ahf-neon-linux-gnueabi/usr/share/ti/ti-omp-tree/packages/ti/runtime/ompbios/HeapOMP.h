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
 *     PER-INSTANCE TYPES
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

#ifndef ti_runtime_ompbios_HeapOMP__include
#define ti_runtime_ompbios_HeapOMP__include

#ifndef __nested__
#define __nested__
#define ti_runtime_ompbios_HeapOMP__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_runtime_ompbios_HeapOMP___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IInstance.h>
#include <ti/runtime/ompbios/package/package.defs.h>

#include <ti/sdo/ipc/SharedRegion.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/IHeap.h>


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
typedef xdc_Bits32 CT__ti_runtime_ompbios_HeapOMP_Module__diagsEnabled;
__extern __FAR__ const CT__ti_runtime_ompbios_HeapOMP_Module__diagsEnabled ti_runtime_ompbios_HeapOMP_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_runtime_ompbios_HeapOMP_Module__diagsIncluded;
__extern __FAR__ const CT__ti_runtime_ompbios_HeapOMP_Module__diagsIncluded ti_runtime_ompbios_HeapOMP_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16 *CT__ti_runtime_ompbios_HeapOMP_Module__diagsMask;
__extern __FAR__ const CT__ti_runtime_ompbios_HeapOMP_Module__diagsMask ti_runtime_ompbios_HeapOMP_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_runtime_ompbios_HeapOMP_Module__gateObj;
__extern __FAR__ const CT__ti_runtime_ompbios_HeapOMP_Module__gateObj ti_runtime_ompbios_HeapOMP_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_runtime_ompbios_HeapOMP_Module__gatePrms;
__extern __FAR__ const CT__ti_runtime_ompbios_HeapOMP_Module__gatePrms ti_runtime_ompbios_HeapOMP_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_runtime_ompbios_HeapOMP_Module__id;
__extern __FAR__ const CT__ti_runtime_ompbios_HeapOMP_Module__id ti_runtime_ompbios_HeapOMP_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_runtime_ompbios_HeapOMP_Module__loggerDefined;
__extern __FAR__ const CT__ti_runtime_ompbios_HeapOMP_Module__loggerDefined ti_runtime_ompbios_HeapOMP_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_runtime_ompbios_HeapOMP_Module__loggerObj;
__extern __FAR__ const CT__ti_runtime_ompbios_HeapOMP_Module__loggerObj ti_runtime_ompbios_HeapOMP_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_runtime_ompbios_HeapOMP_Module__loggerFxn0;
__extern __FAR__ const CT__ti_runtime_ompbios_HeapOMP_Module__loggerFxn0 ti_runtime_ompbios_HeapOMP_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_runtime_ompbios_HeapOMP_Module__loggerFxn1;
__extern __FAR__ const CT__ti_runtime_ompbios_HeapOMP_Module__loggerFxn1 ti_runtime_ompbios_HeapOMP_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_runtime_ompbios_HeapOMP_Module__loggerFxn2;
__extern __FAR__ const CT__ti_runtime_ompbios_HeapOMP_Module__loggerFxn2 ti_runtime_ompbios_HeapOMP_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_runtime_ompbios_HeapOMP_Module__loggerFxn4;
__extern __FAR__ const CT__ti_runtime_ompbios_HeapOMP_Module__loggerFxn4 ti_runtime_ompbios_HeapOMP_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_runtime_ompbios_HeapOMP_Module__loggerFxn8;
__extern __FAR__ const CT__ti_runtime_ompbios_HeapOMP_Module__loggerFxn8 ti_runtime_ompbios_HeapOMP_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_runtime_ompbios_HeapOMP_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_runtime_ompbios_HeapOMP_Module__startupDoneFxn ti_runtime_ompbios_HeapOMP_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_runtime_ompbios_HeapOMP_Object__count;
__extern __FAR__ const CT__ti_runtime_ompbios_HeapOMP_Object__count ti_runtime_ompbios_HeapOMP_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_runtime_ompbios_HeapOMP_Object__heap;
__extern __FAR__ const CT__ti_runtime_ompbios_HeapOMP_Object__heap ti_runtime_ompbios_HeapOMP_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_runtime_ompbios_HeapOMP_Object__sizeof;
__extern __FAR__ const CT__ti_runtime_ompbios_HeapOMP_Object__sizeof ti_runtime_ompbios_HeapOMP_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_runtime_ompbios_HeapOMP_Object__table;
__extern __FAR__ const CT__ti_runtime_ompbios_HeapOMP_Object__table ti_runtime_ompbios_HeapOMP_Object__table__C;

/* localHeapSize */
#ifdef ti_runtime_ompbios_HeapOMP_localHeapSize__D
#define ti_runtime_ompbios_HeapOMP_localHeapSize (ti_runtime_ompbios_HeapOMP_localHeapSize__D)
#else
#define ti_runtime_ompbios_HeapOMP_localHeapSize (ti_runtime_ompbios_HeapOMP_localHeapSize__C)
typedef xdc_SizeT CT__ti_runtime_ompbios_HeapOMP_localHeapSize;
__extern __FAR__ const CT__ti_runtime_ompbios_HeapOMP_localHeapSize ti_runtime_ompbios_HeapOMP_localHeapSize__C;
#endif

/* sharedHeapSize */
#ifdef ti_runtime_ompbios_HeapOMP_sharedHeapSize__D
#define ti_runtime_ompbios_HeapOMP_sharedHeapSize (ti_runtime_ompbios_HeapOMP_sharedHeapSize__D)
#else
#define ti_runtime_ompbios_HeapOMP_sharedHeapSize (ti_runtime_ompbios_HeapOMP_sharedHeapSize__C)
typedef xdc_SizeT CT__ti_runtime_ompbios_HeapOMP_sharedHeapSize;
__extern __FAR__ const CT__ti_runtime_ompbios_HeapOMP_sharedHeapSize ti_runtime_ompbios_HeapOMP_sharedHeapSize__C;
#endif

/* sharedRegionId */
#ifdef ti_runtime_ompbios_HeapOMP_sharedRegionId__D
#define ti_runtime_ompbios_HeapOMP_sharedRegionId (ti_runtime_ompbios_HeapOMP_sharedRegionId__D)
#else
#define ti_runtime_ompbios_HeapOMP_sharedRegionId (ti_runtime_ompbios_HeapOMP_sharedRegionId__C)
typedef xdc_Int16 CT__ti_runtime_ompbios_HeapOMP_sharedRegionId;
__extern __FAR__ const CT__ti_runtime_ompbios_HeapOMP_sharedRegionId ti_runtime_ompbios_HeapOMP_sharedRegionId__C;
#endif


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct ti_runtime_ompbios_HeapOMP_Params {
    size_t __size;
    const void *__self;
    void *__fxns;
    xdc_runtime_IInstance_Params *instance;
    xdc_Int16 sRegionId;
    xdc_runtime_IHeap_Handle localHeap;
    xdc_runtime_IInstance_Params __iprms;
};

/* Struct */
struct ti_runtime_ompbios_HeapOMP_Struct {
    const ti_runtime_ompbios_HeapOMP_Fxns__ *__fxns;
    xdc_Int16 __f0;
    xdc_runtime_IHeap_Handle __f1;
    xdc_runtime_Types_CordAddr __name;
};


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct ti_runtime_ompbios_HeapOMP_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2* __sysp;
    xdc_Ptr (*alloc)(ti_runtime_ompbios_HeapOMP_Handle, xdc_SizeT, xdc_SizeT, xdc_runtime_Error_Block*);
    xdc_Void (*free)(ti_runtime_ompbios_HeapOMP_Handle, xdc_Ptr, xdc_SizeT);
    xdc_Bool (*isBlocking)(ti_runtime_ompbios_HeapOMP_Handle);
    xdc_Void (*getStats)(ti_runtime_ompbios_HeapOMP_Handle, xdc_runtime_Memory_Stats*);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Module__FXNS__C */
__extern const ti_runtime_ompbios_HeapOMP_Fxns__ ti_runtime_ompbios_HeapOMP_Module__FXNS__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_runtime_ompbios_HeapOMP_Module_startup( state ) (-1)

/* Instance_init__E */
xdc__CODESECT(ti_runtime_ompbios_HeapOMP_Instance_init__E, "ti_runtime_ompbios_HeapOMP_Instance_init")
__extern xdc_Void ti_runtime_ompbios_HeapOMP_Instance_init__E(ti_runtime_ompbios_HeapOMP_Object *, const ti_runtime_ompbios_HeapOMP_Params *);

/* Handle__label__S */
xdc__CODESECT(ti_runtime_ompbios_HeapOMP_Handle__label__S, "ti_runtime_ompbios_HeapOMP_Handle__label__S")
__extern xdc_runtime_Types_Label *ti_runtime_ompbios_HeapOMP_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label *lab );

/* Module__startupDone__S */
xdc__CODESECT(ti_runtime_ompbios_HeapOMP_Module__startupDone__S, "ti_runtime_ompbios_HeapOMP_Module__startupDone__S")
__extern xdc_Bool ti_runtime_ompbios_HeapOMP_Module__startupDone__S( void );

/* Object__create__S */
xdc__CODESECT(ti_runtime_ompbios_HeapOMP_Object__create__S, "ti_runtime_ompbios_HeapOMP_Object__create__S")
__extern xdc_Ptr ti_runtime_ompbios_HeapOMP_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, xdc_Ptr __aa, const xdc_UChar *__pa, xdc_SizeT __psz, xdc_runtime_Error_Block *__eb );

/* create */
xdc__CODESECT(ti_runtime_ompbios_HeapOMP_create, "ti_runtime_ompbios_HeapOMP_create")
__extern ti_runtime_ompbios_HeapOMP_Handle ti_runtime_ompbios_HeapOMP_create( const ti_runtime_ompbios_HeapOMP_Params *__prms, xdc_runtime_Error_Block *__eb );

/* construct */
xdc__CODESECT(ti_runtime_ompbios_HeapOMP_construct, "ti_runtime_ompbios_HeapOMP_construct")
__extern void ti_runtime_ompbios_HeapOMP_construct( ti_runtime_ompbios_HeapOMP_Struct *__obj, const ti_runtime_ompbios_HeapOMP_Params *__prms );

/* Object__delete__S */
xdc__CODESECT(ti_runtime_ompbios_HeapOMP_Object__delete__S, "ti_runtime_ompbios_HeapOMP_Object__delete__S")
__extern xdc_Void ti_runtime_ompbios_HeapOMP_Object__delete__S( xdc_Ptr instp );

/* delete */
xdc__CODESECT(ti_runtime_ompbios_HeapOMP_delete, "ti_runtime_ompbios_HeapOMP_delete")
__extern void ti_runtime_ompbios_HeapOMP_delete(ti_runtime_ompbios_HeapOMP_Handle *instp);

/* Object__destruct__S */
xdc__CODESECT(ti_runtime_ompbios_HeapOMP_Object__destruct__S, "ti_runtime_ompbios_HeapOMP_Object__destruct__S")
__extern xdc_Void ti_runtime_ompbios_HeapOMP_Object__destruct__S( xdc_Ptr objp );

/* destruct */
xdc__CODESECT(ti_runtime_ompbios_HeapOMP_destruct, "ti_runtime_ompbios_HeapOMP_destruct")
__extern void ti_runtime_ompbios_HeapOMP_destruct(ti_runtime_ompbios_HeapOMP_Struct *obj);

/* Object__get__S */
xdc__CODESECT(ti_runtime_ompbios_HeapOMP_Object__get__S, "ti_runtime_ompbios_HeapOMP_Object__get__S")
__extern xdc_Ptr ti_runtime_ompbios_HeapOMP_Object__get__S( xdc_Ptr oarr, xdc_Int i );

/* Object__first__S */
xdc__CODESECT(ti_runtime_ompbios_HeapOMP_Object__first__S, "ti_runtime_ompbios_HeapOMP_Object__first__S")
__extern xdc_Ptr ti_runtime_ompbios_HeapOMP_Object__first__S( void );

/* Object__next__S */
xdc__CODESECT(ti_runtime_ompbios_HeapOMP_Object__next__S, "ti_runtime_ompbios_HeapOMP_Object__next__S")
__extern xdc_Ptr ti_runtime_ompbios_HeapOMP_Object__next__S( xdc_Ptr obj );

/* Params__init__S */
xdc__CODESECT(ti_runtime_ompbios_HeapOMP_Params__init__S, "ti_runtime_ompbios_HeapOMP_Params__init__S")
__extern xdc_Void ti_runtime_ompbios_HeapOMP_Params__init__S( xdc_Ptr dst, const xdc_Void *src, xdc_SizeT psz, xdc_SizeT isz );

/* isBlocking__E */
#define ti_runtime_ompbios_HeapOMP_isBlocking ti_runtime_ompbios_HeapOMP_isBlocking__E
xdc__CODESECT(ti_runtime_ompbios_HeapOMP_isBlocking__E, "ti_runtime_ompbios_HeapOMP_isBlocking")
__extern xdc_Bool ti_runtime_ompbios_HeapOMP_isBlocking__E( ti_runtime_ompbios_HeapOMP_Handle __inst );

/* getStats__E */
#define ti_runtime_ompbios_HeapOMP_getStats ti_runtime_ompbios_HeapOMP_getStats__E
xdc__CODESECT(ti_runtime_ompbios_HeapOMP_getStats__E, "ti_runtime_ompbios_HeapOMP_getStats")
__extern xdc_Void ti_runtime_ompbios_HeapOMP_getStats__E( ti_runtime_ompbios_HeapOMP_Handle __inst, xdc_runtime_Memory_Stats *stats );

/* alloc__E */
#define ti_runtime_ompbios_HeapOMP_alloc ti_runtime_ompbios_HeapOMP_alloc__E
xdc__CODESECT(ti_runtime_ompbios_HeapOMP_alloc__E, "ti_runtime_ompbios_HeapOMP_alloc")
__extern xdc_Ptr ti_runtime_ompbios_HeapOMP_alloc__E( ti_runtime_ompbios_HeapOMP_Handle __inst, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block *eb );

/* free__E */
#define ti_runtime_ompbios_HeapOMP_free ti_runtime_ompbios_HeapOMP_free__E
xdc__CODESECT(ti_runtime_ompbios_HeapOMP_free__E, "ti_runtime_ompbios_HeapOMP_free")
__extern xdc_Void ti_runtime_ompbios_HeapOMP_free__E( ti_runtime_ompbios_HeapOMP_Handle __inst, xdc_Ptr block, xdc_SizeT size );


/*
 * ======== CONVERTORS ========
 */

/* Module_upCast */
static inline xdc_runtime_IHeap_Module ti_runtime_ompbios_HeapOMP_Module_upCast( void )
{
    return (xdc_runtime_IHeap_Module)&ti_runtime_ompbios_HeapOMP_Module__FXNS__C;
}

/* Module_to_xdc_runtime_IHeap */
#define ti_runtime_ompbios_HeapOMP_Module_to_xdc_runtime_IHeap ti_runtime_ompbios_HeapOMP_Module_upCast

/* Handle_upCast */
static inline xdc_runtime_IHeap_Handle ti_runtime_ompbios_HeapOMP_Handle_upCast( ti_runtime_ompbios_HeapOMP_Handle i )
{
    return (xdc_runtime_IHeap_Handle)i;
}

/* Handle_to_xdc_runtime_IHeap */
#define ti_runtime_ompbios_HeapOMP_Handle_to_xdc_runtime_IHeap ti_runtime_ompbios_HeapOMP_Handle_upCast

/* Handle_downCast */
static inline ti_runtime_ompbios_HeapOMP_Handle ti_runtime_ompbios_HeapOMP_Handle_downCast( xdc_runtime_IHeap_Handle i )
{
    xdc_runtime_IHeap_Handle i2 = (xdc_runtime_IHeap_Handle)i;
    return (const void*)i2->__fxns == (const void*)&ti_runtime_ompbios_HeapOMP_Module__FXNS__C ? (ti_runtime_ompbios_HeapOMP_Handle)i : (ti_runtime_ompbios_HeapOMP_Handle)0;
}

/* Handle_from_xdc_runtime_IHeap */
#define ti_runtime_ompbios_HeapOMP_Handle_from_xdc_runtime_IHeap ti_runtime_ompbios_HeapOMP_Handle_downCast


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_runtime_ompbios_HeapOMP_Module_startupDone() ti_runtime_ompbios_HeapOMP_Module__startupDone__S()

/* Object_heap */
#define ti_runtime_ompbios_HeapOMP_Object_heap() ti_runtime_ompbios_HeapOMP_Object__heap__C

/* Module_heap */
#define ti_runtime_ompbios_HeapOMP_Module_heap() ti_runtime_ompbios_HeapOMP_Object__heap__C

/* Module_id */
static inline CT__ti_runtime_ompbios_HeapOMP_Module__id ti_runtime_ompbios_HeapOMP_Module_id( void ) 
{
    return ti_runtime_ompbios_HeapOMP_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_runtime_ompbios_HeapOMP_Module_hasMask( void ) 
{
    return (xdc_Bool)(ti_runtime_ompbios_HeapOMP_Module__diagsMask__C != NULL);
}

/* Module_getMask */
static inline xdc_Bits16 ti_runtime_ompbios_HeapOMP_Module_getMask( void ) 
{
    return ti_runtime_ompbios_HeapOMP_Module__diagsMask__C != NULL ? *ti_runtime_ompbios_HeapOMP_Module__diagsMask__C : (xdc_Bits16)0;
}

/* Module_setMask */
static inline xdc_Void ti_runtime_ompbios_HeapOMP_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_runtime_ompbios_HeapOMP_Module__diagsMask__C != NULL) {
        *ti_runtime_ompbios_HeapOMP_Module__diagsMask__C = mask;
    }
}

/* Params_init */
static inline void ti_runtime_ompbios_HeapOMP_Params_init( ti_runtime_ompbios_HeapOMP_Params *prms ) 
{
    if (prms) {
        ti_runtime_ompbios_HeapOMP_Params__init__S(prms, 0, sizeof(ti_runtime_ompbios_HeapOMP_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Params_copy */
static inline void ti_runtime_ompbios_HeapOMP_Params_copy(ti_runtime_ompbios_HeapOMP_Params *dst, const ti_runtime_ompbios_HeapOMP_Params *src) 
{
    if (dst) {
        ti_runtime_ompbios_HeapOMP_Params__init__S(dst, (const void *)src, sizeof(ti_runtime_ompbios_HeapOMP_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Object_count */
#define ti_runtime_ompbios_HeapOMP_Object_count() ti_runtime_ompbios_HeapOMP_Object__count__C

/* Object_sizeof */
#define ti_runtime_ompbios_HeapOMP_Object_sizeof() ti_runtime_ompbios_HeapOMP_Object__sizeof__C

/* Object_get */
static inline ti_runtime_ompbios_HeapOMP_Handle ti_runtime_ompbios_HeapOMP_Object_get(ti_runtime_ompbios_HeapOMP_Instance_State *oarr, int i) 
{
    return (ti_runtime_ompbios_HeapOMP_Handle)ti_runtime_ompbios_HeapOMP_Object__get__S(oarr, i);
}

/* Object_first */
static inline ti_runtime_ompbios_HeapOMP_Handle ti_runtime_ompbios_HeapOMP_Object_first( void )
{
    return (ti_runtime_ompbios_HeapOMP_Handle)ti_runtime_ompbios_HeapOMP_Object__first__S();
}

/* Object_next */
static inline ti_runtime_ompbios_HeapOMP_Handle ti_runtime_ompbios_HeapOMP_Object_next( ti_runtime_ompbios_HeapOMP_Object *obj )
{
    return (ti_runtime_ompbios_HeapOMP_Handle)ti_runtime_ompbios_HeapOMP_Object__next__S(obj);
}

/* Handle_label */
static inline xdc_runtime_Types_Label *ti_runtime_ompbios_HeapOMP_Handle_label( ti_runtime_ompbios_HeapOMP_Handle inst, xdc_runtime_Types_Label *lab )
{
    return ti_runtime_ompbios_HeapOMP_Handle__label__S(inst, lab);
}

/* Handle_name */
static inline xdc_String ti_runtime_ompbios_HeapOMP_Handle_name( ti_runtime_ompbios_HeapOMP_Handle inst )
{
    xdc_runtime_Types_Label lab;
    return ti_runtime_ompbios_HeapOMP_Handle__label__S(inst, &lab)->iname;
}

/* handle */
static inline ti_runtime_ompbios_HeapOMP_Handle ti_runtime_ompbios_HeapOMP_handle( ti_runtime_ompbios_HeapOMP_Struct *str )
{
    return (ti_runtime_ompbios_HeapOMP_Handle)str;
}

/* struct */
static inline ti_runtime_ompbios_HeapOMP_Struct *ti_runtime_ompbios_HeapOMP_struct( ti_runtime_ompbios_HeapOMP_Handle inst )
{
    return (ti_runtime_ompbios_HeapOMP_Struct*)inst;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_runtime_ompbios_HeapOMP__top__
#undef __nested__
#endif

#endif /* ti_runtime_ompbios_HeapOMP__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_runtime_ompbios_HeapOMP__internalaccess))

#ifndef ti_runtime_ompbios_HeapOMP__include_state
#define ti_runtime_ompbios_HeapOMP__include_state

/* Object */
struct ti_runtime_ompbios_HeapOMP_Object {
    const ti_runtime_ompbios_HeapOMP_Fxns__ *__fxns;
    xdc_Int16 sharedRegionId;
    xdc_runtime_IHeap_Handle localHeap;
};

#endif /* ti_runtime_ompbios_HeapOMP__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_runtime_ompbios_HeapOMP__nolocalnames)

#ifndef ti_runtime_ompbios_HeapOMP__localnames__done
#define ti_runtime_ompbios_HeapOMP__localnames__done

/* module prefix */
#define HeapOMP_Instance ti_runtime_ompbios_HeapOMP_Instance
#define HeapOMP_Handle ti_runtime_ompbios_HeapOMP_Handle
#define HeapOMP_Module ti_runtime_ompbios_HeapOMP_Module
#define HeapOMP_Object ti_runtime_ompbios_HeapOMP_Object
#define HeapOMP_Struct ti_runtime_ompbios_HeapOMP_Struct
#define HeapOMP_Instance_State ti_runtime_ompbios_HeapOMP_Instance_State
#define HeapOMP_localHeapSize ti_runtime_ompbios_HeapOMP_localHeapSize
#define HeapOMP_sharedHeapSize ti_runtime_ompbios_HeapOMP_sharedHeapSize
#define HeapOMP_sharedRegionId ti_runtime_ompbios_HeapOMP_sharedRegionId
#define HeapOMP_Params ti_runtime_ompbios_HeapOMP_Params
#define HeapOMP_isBlocking ti_runtime_ompbios_HeapOMP_isBlocking
#define HeapOMP_getStats ti_runtime_ompbios_HeapOMP_getStats
#define HeapOMP_alloc ti_runtime_ompbios_HeapOMP_alloc
#define HeapOMP_free ti_runtime_ompbios_HeapOMP_free
#define HeapOMP_Module_name ti_runtime_ompbios_HeapOMP_Module_name
#define HeapOMP_Module_id ti_runtime_ompbios_HeapOMP_Module_id
#define HeapOMP_Module_startup ti_runtime_ompbios_HeapOMP_Module_startup
#define HeapOMP_Module_startupDone ti_runtime_ompbios_HeapOMP_Module_startupDone
#define HeapOMP_Module_hasMask ti_runtime_ompbios_HeapOMP_Module_hasMask
#define HeapOMP_Module_getMask ti_runtime_ompbios_HeapOMP_Module_getMask
#define HeapOMP_Module_setMask ti_runtime_ompbios_HeapOMP_Module_setMask
#define HeapOMP_Object_heap ti_runtime_ompbios_HeapOMP_Object_heap
#define HeapOMP_Module_heap ti_runtime_ompbios_HeapOMP_Module_heap
#define HeapOMP_construct ti_runtime_ompbios_HeapOMP_construct
#define HeapOMP_create ti_runtime_ompbios_HeapOMP_create
#define HeapOMP_handle ti_runtime_ompbios_HeapOMP_handle
#define HeapOMP_struct ti_runtime_ompbios_HeapOMP_struct
#define HeapOMP_Handle_label ti_runtime_ompbios_HeapOMP_Handle_label
#define HeapOMP_Handle_name ti_runtime_ompbios_HeapOMP_Handle_name
#define HeapOMP_Instance_init ti_runtime_ompbios_HeapOMP_Instance_init
#define HeapOMP_Object_count ti_runtime_ompbios_HeapOMP_Object_count
#define HeapOMP_Object_get ti_runtime_ompbios_HeapOMP_Object_get
#define HeapOMP_Object_first ti_runtime_ompbios_HeapOMP_Object_first
#define HeapOMP_Object_next ti_runtime_ompbios_HeapOMP_Object_next
#define HeapOMP_Object_sizeof ti_runtime_ompbios_HeapOMP_Object_sizeof
#define HeapOMP_Params_copy ti_runtime_ompbios_HeapOMP_Params_copy
#define HeapOMP_Params_init ti_runtime_ompbios_HeapOMP_Params_init
#define HeapOMP_delete ti_runtime_ompbios_HeapOMP_delete
#define HeapOMP_destruct ti_runtime_ompbios_HeapOMP_destruct
#define HeapOMP_Module_upCast ti_runtime_ompbios_HeapOMP_Module_upCast
#define HeapOMP_Module_to_xdc_runtime_IHeap ti_runtime_ompbios_HeapOMP_Module_to_xdc_runtime_IHeap
#define HeapOMP_Handle_upCast ti_runtime_ompbios_HeapOMP_Handle_upCast
#define HeapOMP_Handle_to_xdc_runtime_IHeap ti_runtime_ompbios_HeapOMP_Handle_to_xdc_runtime_IHeap
#define HeapOMP_Handle_downCast ti_runtime_ompbios_HeapOMP_Handle_downCast
#define HeapOMP_Handle_from_xdc_runtime_IHeap ti_runtime_ompbios_HeapOMP_Handle_from_xdc_runtime_IHeap

#endif /* ti_runtime_ompbios_HeapOMP__localnames__done */
#endif
