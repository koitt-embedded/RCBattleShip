/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-B21
 */

#ifndef ti_sdo_ipc_family_vayu_InterruptIpu__INTERNAL__
#define ti_sdo_ipc_family_vayu_InterruptIpu__INTERNAL__

#ifndef ti_sdo_ipc_family_vayu_InterruptIpu__internalaccess
#define ti_sdo_ipc_family_vayu_InterruptIpu__internalaccess
#endif

#include <ti/sdo/ipc/family/vayu/InterruptIpu.h>

#undef xdc_FILE__
#ifndef xdc_FILE
#define xdc_FILE__ NULL
#else
#define xdc_FILE__ xdc_FILE
#endif

/* intEnable */
#undef ti_sdo_ipc_family_vayu_InterruptIpu_intEnable
#define ti_sdo_ipc_family_vayu_InterruptIpu_intEnable ti_sdo_ipc_family_vayu_InterruptIpu_intEnable__E

/* intDisable */
#undef ti_sdo_ipc_family_vayu_InterruptIpu_intDisable
#define ti_sdo_ipc_family_vayu_InterruptIpu_intDisable ti_sdo_ipc_family_vayu_InterruptIpu_intDisable__E

/* intRegister */
#undef ti_sdo_ipc_family_vayu_InterruptIpu_intRegister
#define ti_sdo_ipc_family_vayu_InterruptIpu_intRegister ti_sdo_ipc_family_vayu_InterruptIpu_intRegister__E

/* intUnregister */
#undef ti_sdo_ipc_family_vayu_InterruptIpu_intUnregister
#define ti_sdo_ipc_family_vayu_InterruptIpu_intUnregister ti_sdo_ipc_family_vayu_InterruptIpu_intUnregister__E

/* intSend */
#undef ti_sdo_ipc_family_vayu_InterruptIpu_intSend
#define ti_sdo_ipc_family_vayu_InterruptIpu_intSend ti_sdo_ipc_family_vayu_InterruptIpu_intSend__E

/* intPost */
#undef ti_sdo_ipc_family_vayu_InterruptIpu_intPost
#define ti_sdo_ipc_family_vayu_InterruptIpu_intPost ti_sdo_ipc_family_vayu_InterruptIpu_intPost__E

/* intClear */
#undef ti_sdo_ipc_family_vayu_InterruptIpu_intClear
#define ti_sdo_ipc_family_vayu_InterruptIpu_intClear ti_sdo_ipc_family_vayu_InterruptIpu_intClear__E

/* intShmDucatiStub */
#define InterruptIpu_intShmDucatiStub ti_sdo_ipc_family_vayu_InterruptIpu_intShmDucatiStub__I

/* intShmMbxStub */
#define InterruptIpu_intShmMbxStub ti_sdo_ipc_family_vayu_InterruptIpu_intShmMbxStub__I

/* Module_startup */
#undef ti_sdo_ipc_family_vayu_InterruptIpu_Module_startup
#define ti_sdo_ipc_family_vayu_InterruptIpu_Module_startup ti_sdo_ipc_family_vayu_InterruptIpu_Module_startup__E

/* Instance_init */
#undef ti_sdo_ipc_family_vayu_InterruptIpu_Instance_init
#define ti_sdo_ipc_family_vayu_InterruptIpu_Instance_init ti_sdo_ipc_family_vayu_InterruptIpu_Instance_init__E

/* Instance_finalize */
#undef ti_sdo_ipc_family_vayu_InterruptIpu_Instance_finalize
#define ti_sdo_ipc_family_vayu_InterruptIpu_Instance_finalize ti_sdo_ipc_family_vayu_InterruptIpu_Instance_finalize__E

/* module */
#define InterruptIpu_module ((ti_sdo_ipc_family_vayu_InterruptIpu_Module_State *)(xdc__MODOBJADDR__(ti_sdo_ipc_family_vayu_InterruptIpu_Module__state__V)))
#if !defined(__cplusplus) || !defined(ti_sdo_ipc_family_vayu_InterruptIpu__cplusplus)
#define module ((ti_sdo_ipc_family_vayu_InterruptIpu_Module_State *)(xdc__MODOBJADDR__(ti_sdo_ipc_family_vayu_InterruptIpu_Module__state__V)))
#endif
/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sdo_ipc_family_vayu_InterruptIpu_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sdo_ipc_family_vayu_InterruptIpu_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sdo_ipc_family_vayu_InterruptIpu_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sdo_ipc_family_vayu_InterruptIpu_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sdo_ipc_family_vayu_InterruptIpu_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sdo_ipc_family_vayu_InterruptIpu_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sdo_ipc_family_vayu_InterruptIpu_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sdo_ipc_family_vayu_InterruptIpu_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sdo_ipc_family_vayu_InterruptIpu_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sdo_ipc_family_vayu_InterruptIpu_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sdo_ipc_family_vayu_InterruptIpu_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sdo_ipc_family_vayu_InterruptIpu_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sdo_ipc_family_vayu_InterruptIpu_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sdo_ipc_family_vayu_InterruptIpu_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sdo_ipc_family_vayu_InterruptIpu_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sdo_ipc_family_vayu_InterruptIpu_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sdo_ipc_family_vayu_InterruptIpu_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sdo_ipc_family_vayu_InterruptIpu_Module_GateProxy_query


#endif /* ti_sdo_ipc_family_vayu_InterruptIpu__INTERNAL____ */
