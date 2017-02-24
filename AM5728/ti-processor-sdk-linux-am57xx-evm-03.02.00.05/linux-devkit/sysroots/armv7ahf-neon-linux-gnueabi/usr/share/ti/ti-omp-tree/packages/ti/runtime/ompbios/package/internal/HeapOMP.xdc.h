/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-B21
 */

#ifndef ti_runtime_ompbios_HeapOMP__INTERNAL__
#define ti_runtime_ompbios_HeapOMP__INTERNAL__

#ifndef ti_runtime_ompbios_HeapOMP__internalaccess
#define ti_runtime_ompbios_HeapOMP__internalaccess
#endif

#include <ti/runtime/ompbios/HeapOMP.h>

#undef xdc_FILE__
#ifndef xdc_FILE
#define xdc_FILE__ NULL
#else
#define xdc_FILE__ xdc_FILE
#endif

/* isBlocking */
#undef ti_runtime_ompbios_HeapOMP_isBlocking
#define ti_runtime_ompbios_HeapOMP_isBlocking ti_runtime_ompbios_HeapOMP_isBlocking__E

/* getStats */
#undef ti_runtime_ompbios_HeapOMP_getStats
#define ti_runtime_ompbios_HeapOMP_getStats ti_runtime_ompbios_HeapOMP_getStats__E

/* alloc */
#undef ti_runtime_ompbios_HeapOMP_alloc
#define ti_runtime_ompbios_HeapOMP_alloc ti_runtime_ompbios_HeapOMP_alloc__E

/* free */
#undef ti_runtime_ompbios_HeapOMP_free
#define ti_runtime_ompbios_HeapOMP_free ti_runtime_ompbios_HeapOMP_free__E

/* Module_startup */
#undef ti_runtime_ompbios_HeapOMP_Module_startup
#define ti_runtime_ompbios_HeapOMP_Module_startup ti_runtime_ompbios_HeapOMP_Module_startup__E

/* Instance_init */
#undef ti_runtime_ompbios_HeapOMP_Instance_init
#define ti_runtime_ompbios_HeapOMP_Instance_init ti_runtime_ompbios_HeapOMP_Instance_init__E

/* Instance_finalize */
#undef ti_runtime_ompbios_HeapOMP_Instance_finalize
#define ti_runtime_ompbios_HeapOMP_Instance_finalize ti_runtime_ompbios_HeapOMP_Instance_finalize__E

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_runtime_ompbios_HeapOMP_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_runtime_ompbios_HeapOMP_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_runtime_ompbios_HeapOMP_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_runtime_ompbios_HeapOMP_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_runtime_ompbios_HeapOMP_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_runtime_ompbios_HeapOMP_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_runtime_ompbios_HeapOMP_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_runtime_ompbios_HeapOMP_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_runtime_ompbios_HeapOMP_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_runtime_ompbios_HeapOMP_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_runtime_ompbios_HeapOMP_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_runtime_ompbios_HeapOMP_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_runtime_ompbios_HeapOMP_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_runtime_ompbios_HeapOMP_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_runtime_ompbios_HeapOMP_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_runtime_ompbios_HeapOMP_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_runtime_ompbios_HeapOMP_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_runtime_ompbios_HeapOMP_Module_GateProxy_query

/* Object__sizingError */
#line 1 "Error_inconsistent_object_size_in_ti.runtime.ompbios.HeapOMP"
typedef char ti_runtime_ompbios_HeapOMP_Object__sizingError[sizeof(ti_runtime_ompbios_HeapOMP_Object) > sizeof(ti_runtime_ompbios_HeapOMP_Struct) ? -1 : 1];


#endif /* ti_runtime_ompbios_HeapOMP__INTERNAL____ */
