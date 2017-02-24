/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-B21
 */
import java.util.*;
import org.mozilla.javascript.*;
import xdc.services.intern.xsr.*;
import xdc.services.spec.Session;

public class ti_runtime_ompbios
{
    static final String VERS = "@(#) xdc-B21\n";

    static final Proto.Elm $$T_Bool = Proto.Elm.newBool();
    static final Proto.Elm $$T_Num = Proto.Elm.newNum();
    static final Proto.Elm $$T_Str = Proto.Elm.newStr();
    static final Proto.Elm $$T_Obj = Proto.Elm.newObj();

    static final Proto.Fxn $$T_Met = new Proto.Fxn(null, null, 0, -1, false);
    static final Proto.Map $$T_Map = new Proto.Map($$T_Obj);
    static final Proto.Arr $$T_Vec = new Proto.Arr($$T_Obj);

    static final XScriptO $$DEFAULT = Value.DEFAULT;
    static final Object $$UNDEF = Undefined.instance;

    static final Proto.Obj $$Package = (Proto.Obj)Global.get("$$Package");
    static final Proto.Obj $$Module = (Proto.Obj)Global.get("$$Module");
    static final Proto.Obj $$Instance = (Proto.Obj)Global.get("$$Instance");
    static final Proto.Obj $$Params = (Proto.Obj)Global.get("$$Params");

    static final Object $$objFldGet = Global.get("$$objFldGet");
    static final Object $$objFldSet = Global.get("$$objFldSet");
    static final Object $$proxyGet = Global.get("$$proxyGet");
    static final Object $$proxySet = Global.get("$$proxySet");
    static final Object $$delegGet = Global.get("$$delegGet");
    static final Object $$delegSet = Global.get("$$delegSet");

    Scriptable xdcO;
    Session ses;
    Value.Obj om;

    boolean isROV;
    boolean isCFG;

    Proto.Obj pkgP;
    Value.Obj pkgV;

    ArrayList<Object> imports = new ArrayList<Object>();
    ArrayList<Object> loggables = new ArrayList<Object>();
    ArrayList<Object> mcfgs = new ArrayList<Object>();
    ArrayList<Object> icfgs = new ArrayList<Object>();
    ArrayList<String> inherits = new ArrayList<String>();
    ArrayList<Object> proxies = new ArrayList<Object>();
    ArrayList<Object> sizes = new ArrayList<Object>();
    ArrayList<Object> tdefs = new ArrayList<Object>();

    void $$IMPORTS()
    {
        Global.callFxn("loadPackage", xdcO, "xdc");
        Global.callFxn("loadPackage", xdcO, "xdc.corevers");
        Global.callFxn("loadPackage", xdcO, "xdc.runtime");
        Global.callFxn("loadPackage", xdcO, "ti.sdo.ipc");
    }

    void $$OBJECTS()
    {
        pkgP = (Proto.Obj)om.bind("ti.runtime.ompbios.Package", new Proto.Obj());
        pkgV = (Value.Obj)om.bind("ti.runtime.ompbios", new Value.Obj("ti.runtime.ompbios", pkgP));
    }

    void OpenMP$$OBJECTS()
    {
        Proto.Obj po, spo;
        Value.Obj vo;

        po = (Proto.Obj)om.bind("ti.runtime.ompbios.OpenMP.Module", new Proto.Obj());
        vo = (Value.Obj)om.bind("ti.runtime.ompbios.OpenMP", new Value.Obj("ti.runtime.ompbios.OpenMP", po));
        pkgV.bind("OpenMP", vo);
        // decls 
        spo = (Proto.Obj)om.bind("ti.runtime.ompbios.OpenMP$$Module_State", new Proto.Obj());
        om.bind("ti.runtime.ompbios.OpenMP.Module_State", new Proto.Str(spo, false));
    }

    void HeapOMP$$OBJECTS()
    {
        Proto.Obj po, spo;
        Value.Obj vo;

        po = (Proto.Obj)om.bind("ti.runtime.ompbios.HeapOMP.Module", new Proto.Obj());
        vo = (Value.Obj)om.bind("ti.runtime.ompbios.HeapOMP", new Value.Obj("ti.runtime.ompbios.HeapOMP", po));
        pkgV.bind("HeapOMP", vo);
        // decls 
        spo = (Proto.Obj)om.bind("ti.runtime.ompbios.HeapOMP$$Instance_State", new Proto.Obj());
        om.bind("ti.runtime.ompbios.HeapOMP.Instance_State", new Proto.Str(spo, false));
        // insts 
        Object insP = om.bind("ti.runtime.ompbios.HeapOMP.Instance", new Proto.Obj());
        po = (Proto.Obj)om.bind("ti.runtime.ompbios.HeapOMP$$Object", new Proto.Obj());
        om.bind("ti.runtime.ompbios.HeapOMP.Object", new Proto.Str(po, false));
        po = (Proto.Obj)om.bind("ti.runtime.ompbios.HeapOMP$$Params", new Proto.Obj());
        om.bind("ti.runtime.ompbios.HeapOMP.Params", new Proto.Str(po, false));
        om.bind("ti.runtime.ompbios.HeapOMP.Handle", insP);
        if (isROV) {
            om.bind("ti.runtime.ompbios.HeapOMP.Object", om.findStrict("ti.runtime.ompbios.HeapOMP.Instance_State", "ti.runtime.ompbios"));
        }//isROV
    }

    void OpenMP$$CONSTS()
    {
        // module OpenMP
        om.bind("ti.runtime.ompbios.OpenMP.useSharedHeap", new Extern("ti_runtime_ompbios_OpenMP_useSharedHeap__E", "xdc_Bool(*)(xdc_Void)", true, false));
        om.bind("ti.runtime.ompbios.OpenMP.setProcId", new Extern("ti_runtime_ompbios_OpenMP_setProcId__I", "xdc_Void(*)(xdc_Void)", true, false));
    }

    void HeapOMP$$CONSTS()
    {
        // module HeapOMP
    }

    void OpenMP$$CREATES()
    {
        Proto.Fxn fxn;
        StringBuilder sb;

    }

    void HeapOMP$$CREATES()
    {
        Proto.Fxn fxn;
        StringBuilder sb;

        if (isCFG) {
            sb = new StringBuilder();
            sb.append("ti$runtime$ompbios$HeapOMP$$__initObject = function( inst ) {\n");
                sb.append("if (!this.$used) {\n");
                    sb.append("throw new Error(\"Function ti.runtime.ompbios.HeapOMP.create() called before xdc.useModule('ti.runtime.ompbios.HeapOMP')\");\n");
                sb.append("}\n");
                sb.append("var name = xdc.module('xdc.runtime.Text').defineRopeCord(inst.instance.name);\n");
                sb.append("inst.$object.$$bind('__name', name);\n");
                sb.append("this.instance$static$init.$fxn.apply(inst, [inst.$object, inst, inst.$module]);\n");
                sb.append("inst.$seal();\n");
            sb.append("};\n");
            Global.eval(sb.toString());
            fxn = (Proto.Fxn)om.bind("ti.runtime.ompbios.HeapOMP$$create", new Proto.Fxn(om.findStrict("ti.runtime.ompbios.HeapOMP.Module", "ti.runtime.ompbios"), om.findStrict("ti.runtime.ompbios.HeapOMP.Instance", "ti.runtime.ompbios"), 1, 0, false));
                        fxn.addArg(0, "__params", (Proto)om.findStrict("ti.runtime.ompbios.HeapOMP.Params", "ti.runtime.ompbios"), Global.newObject());
            sb = new StringBuilder();
            sb.append("ti$runtime$ompbios$HeapOMP$$create = function( __params ) {\n");
                sb.append("var __mod = xdc.om['ti.runtime.ompbios.HeapOMP'];\n");
                sb.append("var __inst = xdc.om['ti.runtime.ompbios.HeapOMP.Instance'].$$make();\n");
                sb.append("__inst.$$bind('$package', xdc.om['ti.runtime.ompbios']);\n");
                sb.append("__inst.$$bind('$index', __mod.$instances.length);\n");
                sb.append("__inst.$$bind('$category', 'Instance');\n");
                sb.append("__inst.$$bind('$args', {});\n");
                sb.append("__inst.$$bind('$module', __mod);\n");
                sb.append("__mod.$instances.$add(__inst);\n");
                sb.append("__inst.$$bind('$object', new xdc.om['ti.runtime.ompbios.HeapOMP'].Instance_State);\n");
                sb.append("for (var __p in __params) __inst[__p] = __params[__p];\n");
                sb.append("var save = xdc.om.$curpkg;\n");
                sb.append("xdc.om.$$bind('$curpkg', __mod.$package.$name);\n");
                sb.append("__mod.instance$meta$init.$fxn.apply(__inst, []);\n");
                sb.append("xdc.om.$$bind('$curpkg', save);\n");
                sb.append("__inst.$$bless();\n");
                sb.append("if (xdc.om.$$phase >= 5) xdc.om['ti.runtime.ompbios.HeapOMP'].__initObject(__inst);\n");
                sb.append("__inst.$$bind('$$phase', xdc.om.$$phase);\n");
                sb.append("return __inst;\n");
            sb.append("}\n");
            Global.eval(sb.toString());
        }//isCFG
        if (isCFG) {
            fxn = (Proto.Fxn)om.bind("ti.runtime.ompbios.HeapOMP$$construct", new Proto.Fxn(om.findStrict("ti.runtime.ompbios.HeapOMP.Module", "ti.runtime.ompbios"), null, 2, 0, false));
                        fxn.addArg(0, "__obj", (Proto)om.findStrict("ti.runtime.ompbios.HeapOMP$$Object", "ti.runtime.ompbios"), null);
                        fxn.addArg(1, "__params", (Proto)om.findStrict("ti.runtime.ompbios.HeapOMP.Params", "ti.runtime.ompbios"), Global.newObject());
            sb = new StringBuilder();
            sb.append("ti$runtime$ompbios$HeapOMP$$construct = function( __obj, __params ) {\n");
                sb.append("var __mod = xdc.om['ti.runtime.ompbios.HeapOMP'];\n");
                sb.append("var __inst = __obj;\n");
                sb.append("__inst.$$bind('$args', {});\n");
                sb.append("__inst.$$bind('$module', __mod);\n");
                sb.append("__mod.$objects.$add(__inst);\n");
                sb.append("__inst.$$bind('$object', xdc.om['ti.runtime.ompbios.HeapOMP'].Instance_State.$$make(__inst.$$parent, __inst.$name));\n");
                sb.append("for (var __p in __params) __inst[__p] = __params[__p];\n");
                sb.append("__inst.$$bless();\n");
                sb.append("if (xdc.om.$$phase >= 5) xdc.om['ti.runtime.ompbios.HeapOMP'].__initObject(__inst);\n");
                sb.append("__inst.$$bind('$$phase', xdc.om.$$phase);\n");
                sb.append("return null;\n");
            sb.append("}\n");
            Global.eval(sb.toString());
        }//isCFG
    }

    void OpenMP$$FUNCTIONS()
    {
        Proto.Fxn fxn;

        // fxn OpenMP.configureIpc
        fxn = (Proto.Fxn)om.bind("ti.runtime.ompbios.OpenMP$$configureIpc", new Proto.Fxn(om.findStrict("ti.runtime.ompbios.OpenMP.Module", "ti.runtime.ompbios"), null, 2, 2, false));
                fxn.addArg(0, "masterCoreIdx", Proto.Elm.newCNum("(xdc_UInt16)"), $$UNDEF);
                fxn.addArg(1, "numCores", Proto.Elm.newCNum("(xdc_UInt16)"), $$UNDEF);
    }

    void HeapOMP$$FUNCTIONS()
    {
        Proto.Fxn fxn;

        // fxn HeapOMP.configure
        fxn = (Proto.Fxn)om.bind("ti.runtime.ompbios.HeapOMP$$configure", new Proto.Fxn(om.findStrict("ti.runtime.ompbios.HeapOMP.Module", "ti.runtime.ompbios"), null, 2, 2, false));
                fxn.addArg(0, "sharedRegionId", Proto.Elm.newCNum("(xdc_Int16)"), $$UNDEF);
                fxn.addArg(1, "localHeapSize", Proto.Elm.newCNum("(xdc_SizeT)"), $$UNDEF);
    }

    void OpenMP$$SIZES()
    {
        Proto.Str so;
        Object fxn;

        so = (Proto.Str)om.findStrict("ti.runtime.ompbios.OpenMP.Module_State", "ti.runtime.ompbios");
        sizes.clear();
        sizes.add(Global.newArray("useSharedHeap", "UShort"));
        so.bind("$$sizes", Global.newArray(sizes.toArray()));
        fxn = Global.eval("function() { return $$sizeof(xdc.om['ti.runtime.ompbios.OpenMP.Module_State']); }");
        so.bind("$sizeof", fxn);
        fxn = Global.eval("function() { return $$alignof(xdc.om['ti.runtime.ompbios.OpenMP.Module_State']); }");
        so.bind("$alignof", fxn);
        fxn = Global.eval("function(fld) { return $$offsetof(xdc.om['ti.runtime.ompbios.OpenMP.Module_State'], fld); }");
        so.bind("$offsetof", fxn);
    }

    void HeapOMP$$SIZES()
    {
        Proto.Str so;
        Object fxn;

        so = (Proto.Str)om.findStrict("ti.runtime.ompbios.HeapOMP.Instance_State", "ti.runtime.ompbios");
        sizes.clear();
        sizes.add(Global.newArray("__fxns", "UPtr"));
        sizes.add(Global.newArray("sharedRegionId", "TInt16"));
        sizes.add(Global.newArray("localHeap", "UPtr"));
        so.bind("$$sizes", Global.newArray(sizes.toArray()));
        fxn = Global.eval("function() { return $$sizeof(xdc.om['ti.runtime.ompbios.HeapOMP.Instance_State']); }");
        so.bind("$sizeof", fxn);
        fxn = Global.eval("function() { return $$alignof(xdc.om['ti.runtime.ompbios.HeapOMP.Instance_State']); }");
        so.bind("$alignof", fxn);
        fxn = Global.eval("function(fld) { return $$offsetof(xdc.om['ti.runtime.ompbios.HeapOMP.Instance_State'], fld); }");
        so.bind("$offsetof", fxn);
    }

    void OpenMP$$TYPES()
    {
        Scriptable cap;
        Proto.Obj po;
        Proto.Str ps;
        Proto.Typedef pt;
        Object fxn;

        cap = (Scriptable)Global.callFxn("loadCapsule", xdcO, "ti/runtime/ompbios/OpenMP.xs");
        om.bind("ti.runtime.ompbios.OpenMP$$capsule", cap);
        po = (Proto.Obj)om.findStrict("ti.runtime.ompbios.OpenMP.Module", "ti.runtime.ompbios");
        po.init("ti.runtime.ompbios.OpenMP.Module", om.findStrict("xdc.runtime.IModule.Module", "ti.runtime.ompbios"));
                po.addFld("$hostonly", $$T_Num, 0, "r");
        if (isCFG) {
            po.addFld("numCores", Proto.Elm.newCNum("(xdc_Int32)"), 8L, "w");
            po.addFld("masterCoreIdx", Proto.Elm.newCNum("(xdc_Int32)"), 0L, "w");
            po.addFld("clockFreq", Proto.Elm.newCNum("(xdc_Int32)"), 0L, "w");
            po.addFld("hasMsmc", $$T_Bool, true, "w");
            po.addFld("msmcBase", Proto.Elm.newCNum("(xdc_UInt32)"), 0L, "w");
            po.addFld("msmcSize", Proto.Elm.newCNum("(xdc_UInt32)"), 0L, "w");
            po.addFld("msmcNoCacheVirtualBase", Proto.Elm.newCNum("(xdc_UInt32)"), 0L, "w");
            po.addFld("msmcNoCacheVirtualSize", Proto.Elm.newCNum("(xdc_UInt32)"), 0L, "w");
            po.addFld("msmcNoCachePhysicalBase", Proto.Elm.newCNum("(xdc_UInt32)"), 0L, "w");
            po.addFld("ddrBase", Proto.Elm.newCNum("(xdc_UInt32)"), 0L, "w");
            po.addFld("ddrSize", Proto.Elm.newCNum("(xdc_UInt32)"), 0L, "w");
            po.addFld("ddrNoCacheBase", Proto.Elm.newCNum("(xdc_UInt32)"), 0L, "w");
            po.addFld("ddrNoCacheSize", Proto.Elm.newCNum("(xdc_UInt32)"), 0L, "w");
            po.addFld("mpaxForMsmcMapping", Proto.Elm.newCNum("(xdc_UInt32)"), 3L, "w");
            po.addFld("hwSemBaseIdx", Proto.Elm.newCNum("(xdc_Int32)"), 3L, "w");
            po.addFld("hwSemCount", Proto.Elm.newCNum("(xdc_Int32)"), 7L, "w");
            po.addFld("qmssInit", $$T_Bool, true, "w");
            po.addFld("qmssMemRegionIndex", Proto.Elm.newCNum("(xdc_Int32)"), Global.eval("-1"), "w");
            po.addFld("qmssFirstDescIdxInLinkingRam", Proto.Elm.newCNum("(xdc_UInt32)"), 0L, "w");
            po.addFld("qmssHwQueueBaseIdx", Proto.Elm.newCNum("(xdc_Int32)"), Global.eval("-1"), "w");
            po.addFld("useIpcSharedHeap", $$T_Bool, true, "w");
            po.addFld("allocateLocalHeap", $$T_Bool, true, "w");
            po.addFld("allocateLocalHeapSize", Proto.Elm.newCNum("(xdc_UInt32)"), 0x8000L, "w");
            po.addFld("allocateSharedHeap", $$T_Bool, true, "w");
            po.addFld("allocateSharedHeapSize", Proto.Elm.newCNum("(xdc_UInt32)"), 0x08000000L, "w");
            po.addFld("allocateStackFromHeap", $$T_Bool, false, "w");
            po.addFld("allocateStackFromHeapSize", Proto.Elm.newCNum("(xdc_Int32)"), 0x10000L, "w");
        }//isCFG
        fxn = Global.get(cap, "module$use");
        if (fxn != null) om.bind("ti.runtime.ompbios.OpenMP$$module$use", true);
        if (fxn != null) po.addFxn("module$use", $$T_Met, fxn);
        fxn = Global.get(cap, "module$meta$init");
        if (fxn != null) om.bind("ti.runtime.ompbios.OpenMP$$module$meta$init", true);
        if (fxn != null) po.addFxn("module$meta$init", $$T_Met, fxn);
        fxn = Global.get(cap, "module$static$init");
        if (fxn != null) om.bind("ti.runtime.ompbios.OpenMP$$module$static$init", true);
        if (fxn != null) po.addFxn("module$static$init", $$T_Met, fxn);
        fxn = Global.get(cap, "module$validate");
        if (fxn != null) om.bind("ti.runtime.ompbios.OpenMP$$module$validate", true);
        if (fxn != null) po.addFxn("module$validate", $$T_Met, fxn);
                po.addFxn("configureIpc", (Proto.Fxn)om.findStrict("ti.runtime.ompbios.OpenMP$$configureIpc", "ti.runtime.ompbios"), Global.get(cap, "configureIpc"));
        // struct OpenMP.Module_State
        po = (Proto.Obj)om.findStrict("ti.runtime.ompbios.OpenMP$$Module_State", "ti.runtime.ompbios");
        po.init("ti.runtime.ompbios.OpenMP.Module_State", null);
                po.addFld("$hostonly", $$T_Num, 0, "r");
                po.addFld("useSharedHeap", $$T_Bool, $$UNDEF, "w");
    }

    void HeapOMP$$TYPES()
    {
        Scriptable cap;
        Proto.Obj po;
        Proto.Str ps;
        Proto.Typedef pt;
        Object fxn;

        cap = (Scriptable)Global.callFxn("loadCapsule", xdcO, "ti/runtime/ompbios/HeapOMP.xs");
        om.bind("ti.runtime.ompbios.HeapOMP$$capsule", cap);
        po = (Proto.Obj)om.findStrict("ti.runtime.ompbios.HeapOMP.Module", "ti.runtime.ompbios");
        po.init("ti.runtime.ompbios.HeapOMP.Module", om.findStrict("xdc.runtime.IHeap.Module", "ti.runtime.ompbios"));
                po.addFld("$hostonly", $$T_Num, 0, "r");
        if (isCFG) {
            po.addFld("localHeapSize", Proto.Elm.newCNum("(xdc_SizeT)"), 0L, "w");
            po.addFld("sharedHeapSize", Proto.Elm.newCNum("(xdc_SizeT)"), 0L, "w");
            po.addFld("sharedRegionId", Proto.Elm.newCNum("(xdc_Int16)"), 0xFFFFL, "w");
        }//isCFG
        if (isCFG) {
                        po.addFxn("create", (Proto.Fxn)om.findStrict("ti.runtime.ompbios.HeapOMP$$create", "ti.runtime.ompbios"), Global.get("ti$runtime$ompbios$HeapOMP$$create"));
                        po.addFxn("construct", (Proto.Fxn)om.findStrict("ti.runtime.ompbios.HeapOMP$$construct", "ti.runtime.ompbios"), Global.get("ti$runtime$ompbios$HeapOMP$$construct"));
        }//isCFG
        fxn = Global.get(cap, "module$use");
        if (fxn != null) om.bind("ti.runtime.ompbios.HeapOMP$$module$use", true);
        if (fxn != null) po.addFxn("module$use", $$T_Met, fxn);
        fxn = Global.get(cap, "module$meta$init");
        if (fxn != null) om.bind("ti.runtime.ompbios.HeapOMP$$module$meta$init", true);
        if (fxn != null) po.addFxn("module$meta$init", $$T_Met, fxn);
        fxn = Global.get(cap, "instance$meta$init");
        if (fxn != null) om.bind("ti.runtime.ompbios.HeapOMP$$instance$meta$init", true);
        if (fxn != null) po.addFxn("instance$meta$init", $$T_Met, fxn);
        fxn = Global.get(cap, "module$static$init");
        if (fxn != null) om.bind("ti.runtime.ompbios.HeapOMP$$module$static$init", true);
        if (fxn != null) po.addFxn("module$static$init", $$T_Met, fxn);
        fxn = Global.get(cap, "module$validate");
        if (fxn != null) om.bind("ti.runtime.ompbios.HeapOMP$$module$validate", true);
        if (fxn != null) po.addFxn("module$validate", $$T_Met, fxn);
        fxn = Global.get(cap, "instance$static$init");
        if (fxn != null) om.bind("ti.runtime.ompbios.HeapOMP$$instance$static$init", true);
        if (fxn != null) po.addFxn("instance$static$init", $$T_Met, fxn);
                po.addFxn("configure", (Proto.Fxn)om.findStrict("ti.runtime.ompbios.HeapOMP$$configure", "ti.runtime.ompbios"), Global.get(cap, "configure"));
        po = (Proto.Obj)om.findStrict("ti.runtime.ompbios.HeapOMP.Instance", "ti.runtime.ompbios");
        po.init("ti.runtime.ompbios.HeapOMP.Instance", om.findStrict("xdc.runtime.IHeap.Instance", "ti.runtime.ompbios"));
                po.addFld("$hostonly", $$T_Num, 0, "r");
        if (isCFG) {
            po.addFld("sRegionId", Proto.Elm.newCNum("(xdc_Int16)"), 0xFFFFL, "w");
            po.addFld("localHeap", (Proto)om.findStrict("xdc.runtime.IHeap.Handle", "ti.runtime.ompbios"), null, "w");
                        po.addFld("instance", (Proto)om.findStrict("xdc.runtime.IInstance.Params", "ti.runtime.ompbios"), $$UNDEF, "w");
        }//isCFG
        po = (Proto.Obj)om.findStrict("ti.runtime.ompbios.HeapOMP$$Params", "ti.runtime.ompbios");
        po.init("ti.runtime.ompbios.HeapOMP.Params", om.findStrict("xdc.runtime.IHeap$$Params", "ti.runtime.ompbios"));
                po.addFld("$hostonly", $$T_Num, 0, "r");
        if (isCFG) {
            po.addFld("sRegionId", Proto.Elm.newCNum("(xdc_Int16)"), 0xFFFFL, "w");
            po.addFld("localHeap", (Proto)om.findStrict("xdc.runtime.IHeap.Handle", "ti.runtime.ompbios"), null, "w");
                        po.addFld("instance", (Proto)om.findStrict("xdc.runtime.IInstance.Params", "ti.runtime.ompbios"), $$UNDEF, "w");
        }//isCFG
        po = (Proto.Obj)om.findStrict("ti.runtime.ompbios.HeapOMP$$Object", "ti.runtime.ompbios");
        po.init("ti.runtime.ompbios.HeapOMP.Object", om.findStrict("ti.runtime.ompbios.HeapOMP.Instance", "ti.runtime.ompbios"));
        // struct HeapOMP.Instance_State
        po = (Proto.Obj)om.findStrict("ti.runtime.ompbios.HeapOMP$$Instance_State", "ti.runtime.ompbios");
        po.init("ti.runtime.ompbios.HeapOMP.Instance_State", null);
                po.addFld("$hostonly", $$T_Num, 0, "r");
                po.addFld("sharedRegionId", Proto.Elm.newCNum("(xdc_Int16)"), $$UNDEF, "w");
                po.addFld("localHeap", (Proto)om.findStrict("xdc.runtime.IHeap.Handle", "ti.runtime.ompbios"), $$UNDEF, "w");
    }

    void OpenMP$$ROV()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("ti.runtime.ompbios.OpenMP", "ti.runtime.ompbios");
        vo.bind("Module_State$fetchDesc", Global.newObject("type", "ti.runtime.ompbios.OpenMP.Module_State", "isScalar", false));
        po = (Proto.Obj)om.findStrict("ti.runtime.ompbios.OpenMP$$Module_State", "ti.runtime.ompbios");
    }

    void HeapOMP$$ROV()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("ti.runtime.ompbios.HeapOMP", "ti.runtime.ompbios");
        po = (Proto.Obj)om.findStrict("ti.runtime.ompbios.HeapOMP$$Instance_State", "ti.runtime.ompbios");
        po.addFld("__fxns", new Proto.Adr("xdc_Ptr", "Pv"), $$UNDEF, "w");
        vo.bind("Instance_State$fetchDesc", Global.newObject("type", "ti.runtime.ompbios.HeapOMP.Instance_State", "isScalar", false));
        po = (Proto.Obj)om.findStrict("ti.runtime.ompbios.HeapOMP$$Instance_State", "ti.runtime.ompbios");
    }

    void $$SINGLETONS()
    {
        pkgP.init("ti.runtime.ompbios.Package", (Proto.Obj)om.findStrict("xdc.IPackage.Module", "ti.runtime.ompbios"));
        Scriptable cap = (Scriptable)Global.callFxn("loadCapsule", xdcO, "ti/runtime/ompbios/package.xs");
        om.bind("xdc.IPackage$$capsule", cap);
        Object fxn;
                fxn = Global.get(cap, "init");
                if (fxn != null) pkgP.addFxn("init", (Proto.Fxn)om.findStrict("xdc.IPackage$$init", "ti.runtime.ompbios"), fxn);
                fxn = Global.get(cap, "close");
                if (fxn != null) pkgP.addFxn("close", (Proto.Fxn)om.findStrict("xdc.IPackage$$close", "ti.runtime.ompbios"), fxn);
                fxn = Global.get(cap, "validate");
                if (fxn != null) pkgP.addFxn("validate", (Proto.Fxn)om.findStrict("xdc.IPackage$$validate", "ti.runtime.ompbios"), fxn);
                fxn = Global.get(cap, "exit");
                if (fxn != null) pkgP.addFxn("exit", (Proto.Fxn)om.findStrict("xdc.IPackage$$exit", "ti.runtime.ompbios"), fxn);
                fxn = Global.get(cap, "getLibs");
                if (fxn != null) pkgP.addFxn("getLibs", (Proto.Fxn)om.findStrict("xdc.IPackage$$getLibs", "ti.runtime.ompbios"), fxn);
                fxn = Global.get(cap, "getSects");
                if (fxn != null) pkgP.addFxn("getSects", (Proto.Fxn)om.findStrict("xdc.IPackage$$getSects", "ti.runtime.ompbios"), fxn);
        pkgP.bind("$capsule", cap);
        pkgV.init2(pkgP, "ti.runtime.ompbios", Value.DEFAULT, false);
        pkgV.bind("$name", "ti.runtime.ompbios");
        pkgV.bind("$category", "Package");
        pkgV.bind("$$qn", "ti.runtime.ompbios.");
        pkgV.bind("$vers", Global.newArray());
        Value.Map atmap = (Value.Map)pkgV.getv("$attr");
        atmap.seal("length");
        imports.clear();
        pkgV.bind("$imports", imports);
        StringBuilder sb = new StringBuilder();
        sb.append("var pkg = xdc.om['ti.runtime.ompbios'];\n");
        sb.append("if (pkg.$vers.length >= 3) {\n");
            sb.append("pkg.$vers.push(Packages.xdc.services.global.Vers.getDate(xdc.csd() + '/..'));\n");
        sb.append("}\n");
        sb.append("if ('ti.runtime.ompbios$$stat$base' in xdc.om) {\n");
            sb.append("pkg.packageBase = xdc.om['ti.runtime.ompbios$$stat$base'];\n");
            sb.append("pkg.packageRepository = xdc.om['ti.runtime.ompbios$$stat$root'];\n");
        sb.append("}\n");
        sb.append("pkg.build.libraries = [\n");
            sb.append("'lib/ti_runtime_ompbios_debug_e66.ae66',\n");
            sb.append("'lib/ti_runtime_ompbios_release_e66.ae66',\n");
        sb.append("];\n");
        sb.append("pkg.build.libDesc = [\n");
            sb.append("['lib/ti_runtime_ompbios_debug_e66.ae66', {target: 'ti.targets.elf.C66', suffix: 'e66'}],\n");
            sb.append("['lib/ti_runtime_ompbios_release_e66.ae66', {target: 'ti.targets.elf.C66', suffix: 'e66'}],\n");
        sb.append("];\n");
        Global.eval(sb.toString());
    }

    void OpenMP$$SINGLETONS()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("ti.runtime.ompbios.OpenMP", "ti.runtime.ompbios");
        po = (Proto.Obj)om.findStrict("ti.runtime.ompbios.OpenMP.Module", "ti.runtime.ompbios");
        vo.init2(po, "ti.runtime.ompbios.OpenMP", $$DEFAULT, false);
        vo.bind("Module", po);
        vo.bind("$category", "Module");
        vo.bind("$capsule", om.findStrict("ti.runtime.ompbios.OpenMP$$capsule", "ti.runtime.ompbios"));
        vo.bind("$package", om.findStrict("ti.runtime.ompbios", "ti.runtime.ompbios"));
        tdefs.clear();
        proxies.clear();
        mcfgs.clear();
        icfgs.clear();
        inherits.clear();
        mcfgs.add("Module__diagsEnabled");
        icfgs.add("Module__diagsEnabled");
        mcfgs.add("Module__diagsIncluded");
        icfgs.add("Module__diagsIncluded");
        mcfgs.add("Module__diagsMask");
        icfgs.add("Module__diagsMask");
        mcfgs.add("Module__gateObj");
        icfgs.add("Module__gateObj");
        mcfgs.add("Module__gatePrms");
        icfgs.add("Module__gatePrms");
        mcfgs.add("Module__id");
        icfgs.add("Module__id");
        mcfgs.add("Module__loggerDefined");
        icfgs.add("Module__loggerDefined");
        mcfgs.add("Module__loggerObj");
        icfgs.add("Module__loggerObj");
        mcfgs.add("Module__loggerFxn0");
        icfgs.add("Module__loggerFxn0");
        mcfgs.add("Module__loggerFxn1");
        icfgs.add("Module__loggerFxn1");
        mcfgs.add("Module__loggerFxn2");
        icfgs.add("Module__loggerFxn2");
        mcfgs.add("Module__loggerFxn4");
        icfgs.add("Module__loggerFxn4");
        mcfgs.add("Module__loggerFxn8");
        icfgs.add("Module__loggerFxn8");
        mcfgs.add("Module__startupDoneFxn");
        icfgs.add("Module__startupDoneFxn");
        mcfgs.add("Object__count");
        icfgs.add("Object__count");
        mcfgs.add("Object__heap");
        icfgs.add("Object__heap");
        mcfgs.add("Object__sizeof");
        icfgs.add("Object__sizeof");
        mcfgs.add("Object__table");
        icfgs.add("Object__table");
        mcfgs.add("numCores");
        mcfgs.add("masterCoreIdx");
        mcfgs.add("clockFreq");
        mcfgs.add("hasMsmc");
        mcfgs.add("msmcBase");
        mcfgs.add("msmcSize");
        mcfgs.add("msmcNoCacheVirtualBase");
        mcfgs.add("msmcNoCacheVirtualSize");
        mcfgs.add("msmcNoCachePhysicalBase");
        mcfgs.add("ddrBase");
        mcfgs.add("ddrSize");
        mcfgs.add("ddrNoCacheBase");
        mcfgs.add("ddrNoCacheSize");
        mcfgs.add("mpaxForMsmcMapping");
        mcfgs.add("hwSemBaseIdx");
        mcfgs.add("hwSemCount");
        mcfgs.add("qmssInit");
        mcfgs.add("qmssMemRegionIndex");
        mcfgs.add("qmssFirstDescIdxInLinkingRam");
        mcfgs.add("qmssHwQueueBaseIdx");
        mcfgs.add("useIpcSharedHeap");
        mcfgs.add("allocateLocalHeap");
        mcfgs.add("allocateLocalHeapSize");
        mcfgs.add("allocateSharedHeap");
        mcfgs.add("allocateSharedHeapSize");
        mcfgs.add("allocateStackFromHeap");
        mcfgs.add("allocateStackFromHeapSize");
        vo.bind("Module_State", om.findStrict("ti.runtime.ompbios.OpenMP.Module_State", "ti.runtime.ompbios"));
        tdefs.add(om.findStrict("ti.runtime.ompbios.OpenMP.Module_State", "ti.runtime.ompbios"));
        vo.bind("$$tdefs", Global.newArray(tdefs.toArray()));
        vo.bind("$$proxies", Global.newArray(proxies.toArray()));
        vo.bind("$$mcfgs", Global.newArray(mcfgs.toArray()));
        vo.bind("$$icfgs", Global.newArray(icfgs.toArray()));
        inherits.add("xdc.runtime");
        vo.bind("$$inherits", Global.newArray(inherits.toArray()));
        ((Value.Arr)pkgV.getv("$modules")).add(vo);
        ((Value.Arr)om.findStrict("$modules", "ti.runtime.ompbios")).add(vo);
        vo.bind("$$instflag", 0);
        vo.bind("$$iobjflag", 0);
        vo.bind("$$sizeflag", 1);
        vo.bind("$$dlgflag", 0);
        vo.bind("$$iflag", 0);
        vo.bind("$$romcfgs", "|");
        vo.bind("$$nortsflag", 0);
        if (isCFG) {
            Proto.Str ps = (Proto.Str)vo.find("Module_State");
            if (ps != null) vo.bind("$object", ps.newInstance());
            vo.bind("$$meta_iobj", 1);
        }//isCFG
        vo.bind("useSharedHeap", om.findStrict("ti.runtime.ompbios.OpenMP.useSharedHeap", "ti.runtime.ompbios"));
        vo.bind("setProcId", om.findStrict("ti.runtime.ompbios.OpenMP.setProcId", "ti.runtime.ompbios"));
        vo.bind("$$fxntab", Global.newArray("ti_runtime_ompbios_OpenMP_Module__startupDone__E", "ti_runtime_ompbios_OpenMP_useSharedHeap__E"));
        vo.bind("$$logEvtCfgs", Global.newArray());
        vo.bind("$$errorDescCfgs", Global.newArray());
        vo.bind("$$assertDescCfgs", Global.newArray());
        Value.Map atmap = (Value.Map)vo.getv("$attr");
        atmap.seal("length");
        vo.bind("MODULE_STARTUP$", 0);
        vo.bind("PROXY$", 0);
        loggables.clear();
        loggables.add(Global.newObject("name", "useSharedHeap", "entry", "", "exit", "%d"));
        vo.bind("$$loggables", loggables.toArray());
        pkgV.bind("OpenMP", vo);
        ((Value.Arr)pkgV.getv("$unitNames")).add("OpenMP");
    }

    void HeapOMP$$SINGLETONS()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("ti.runtime.ompbios.HeapOMP", "ti.runtime.ompbios");
        po = (Proto.Obj)om.findStrict("ti.runtime.ompbios.HeapOMP.Module", "ti.runtime.ompbios");
        vo.init2(po, "ti.runtime.ompbios.HeapOMP", $$DEFAULT, false);
        vo.bind("Module", po);
        vo.bind("$category", "Module");
        vo.bind("$capsule", om.findStrict("ti.runtime.ompbios.HeapOMP$$capsule", "ti.runtime.ompbios"));
        vo.bind("Instance", om.findStrict("ti.runtime.ompbios.HeapOMP.Instance", "ti.runtime.ompbios"));
        vo.bind("Params", om.findStrict("ti.runtime.ompbios.HeapOMP.Params", "ti.runtime.ompbios"));
        vo.bind("PARAMS", ((Proto.Str)om.findStrict("ti.runtime.ompbios.HeapOMP.Params", "ti.runtime.ompbios")).newInstance());
        vo.bind("Handle", om.findStrict("ti.runtime.ompbios.HeapOMP.Handle", "ti.runtime.ompbios"));
        vo.bind("$package", om.findStrict("ti.runtime.ompbios", "ti.runtime.ompbios"));
        tdefs.clear();
        proxies.clear();
        mcfgs.clear();
        icfgs.clear();
        inherits.clear();
        mcfgs.add("Module__diagsEnabled");
        icfgs.add("Module__diagsEnabled");
        mcfgs.add("Module__diagsIncluded");
        icfgs.add("Module__diagsIncluded");
        mcfgs.add("Module__diagsMask");
        icfgs.add("Module__diagsMask");
        mcfgs.add("Module__gateObj");
        icfgs.add("Module__gateObj");
        mcfgs.add("Module__gatePrms");
        icfgs.add("Module__gatePrms");
        mcfgs.add("Module__id");
        icfgs.add("Module__id");
        mcfgs.add("Module__loggerDefined");
        icfgs.add("Module__loggerDefined");
        mcfgs.add("Module__loggerObj");
        icfgs.add("Module__loggerObj");
        mcfgs.add("Module__loggerFxn0");
        icfgs.add("Module__loggerFxn0");
        mcfgs.add("Module__loggerFxn1");
        icfgs.add("Module__loggerFxn1");
        mcfgs.add("Module__loggerFxn2");
        icfgs.add("Module__loggerFxn2");
        mcfgs.add("Module__loggerFxn4");
        icfgs.add("Module__loggerFxn4");
        mcfgs.add("Module__loggerFxn8");
        icfgs.add("Module__loggerFxn8");
        mcfgs.add("Module__startupDoneFxn");
        icfgs.add("Module__startupDoneFxn");
        mcfgs.add("Object__count");
        icfgs.add("Object__count");
        mcfgs.add("Object__heap");
        icfgs.add("Object__heap");
        mcfgs.add("Object__sizeof");
        icfgs.add("Object__sizeof");
        mcfgs.add("Object__table");
        icfgs.add("Object__table");
        mcfgs.add("localHeapSize");
        mcfgs.add("sharedHeapSize");
        mcfgs.add("sharedRegionId");
        vo.bind("Instance_State", om.findStrict("ti.runtime.ompbios.HeapOMP.Instance_State", "ti.runtime.ompbios"));
        tdefs.add(om.findStrict("ti.runtime.ompbios.HeapOMP.Instance_State", "ti.runtime.ompbios"));
        vo.bind("$$tdefs", Global.newArray(tdefs.toArray()));
        vo.bind("$$proxies", Global.newArray(proxies.toArray()));
        vo.bind("$$mcfgs", Global.newArray(mcfgs.toArray()));
        vo.bind("$$icfgs", Global.newArray(icfgs.toArray()));
        inherits.add("xdc.runtime");
        inherits.add("xdc.runtime");
        vo.bind("$$inherits", Global.newArray(inherits.toArray()));
        ((Value.Arr)pkgV.getv("$modules")).add(vo);
        ((Value.Arr)om.findStrict("$modules", "ti.runtime.ompbios")).add(vo);
        vo.bind("$$instflag", 1);
        vo.bind("$$iobjflag", 1);
        vo.bind("$$sizeflag", 1);
        vo.bind("$$dlgflag", 0);
        vo.bind("$$iflag", 1);
        vo.bind("$$romcfgs", "|");
        vo.bind("$$nortsflag", 0);
        if (isCFG) {
            Proto.Str ps = (Proto.Str)vo.find("Module_State");
            if (ps != null) vo.bind("$object", ps.newInstance());
            vo.bind("$$meta_iobj", om.has("ti.runtime.ompbios.HeapOMP$$instance$static$init", null) ? 1 : 0);
            vo.bind("__initObject", Global.get("ti$runtime$ompbios$HeapOMP$$__initObject"));
        }//isCFG
        vo.bind("$$fxntab", Global.newArray("ti_runtime_ompbios_HeapOMP_Handle__label__E", "ti_runtime_ompbios_HeapOMP_Module__startupDone__E", "ti_runtime_ompbios_HeapOMP_Object__create__E", "ti_runtime_ompbios_HeapOMP_Object__delete__E", "ti_runtime_ompbios_HeapOMP_Object__destruct__E", "ti_runtime_ompbios_HeapOMP_Object__get__E", "ti_runtime_ompbios_HeapOMP_Object__first__E", "ti_runtime_ompbios_HeapOMP_Object__next__E", "ti_runtime_ompbios_HeapOMP_Params__init__E", "ti_runtime_ompbios_HeapOMP_isBlocking__E", "ti_runtime_ompbios_HeapOMP_getStats__E", "ti_runtime_ompbios_HeapOMP_alloc__E", "ti_runtime_ompbios_HeapOMP_free__E"));
        vo.bind("$$logEvtCfgs", Global.newArray());
        vo.bind("$$errorDescCfgs", Global.newArray());
        vo.bind("$$assertDescCfgs", Global.newArray());
        Value.Map atmap = (Value.Map)vo.getv("$attr");
        atmap.setElem("", true);
        atmap.seal("length");
        vo.bind("Object", om.findStrict("ti.runtime.ompbios.HeapOMP.Object", "ti.runtime.ompbios"));
        vo.bind("MODULE_STARTUP$", 0);
        vo.bind("PROXY$", 0);
        loggables.clear();
        vo.bind("$$loggables", loggables.toArray());
        pkgV.bind("HeapOMP", vo);
        ((Value.Arr)pkgV.getv("$unitNames")).add("HeapOMP");
    }

    void $$INITIALIZATION()
    {
        Value.Obj vo;

        if (isCFG) {
            Object srcP = ((XScriptO)om.findStrict("xdc.runtime.IInstance", "ti.runtime.ompbios")).findStrict("PARAMS", "ti.runtime.ompbios");
            Scriptable dstP;

            dstP = (Scriptable)((XScriptO)om.findStrict("ti.runtime.ompbios.HeapOMP", "ti.runtime.ompbios")).findStrict("PARAMS", "ti.runtime.ompbios");
            Global.put(dstP, "instance", srcP);
        }//isCFG
        Global.callFxn("module$meta$init", (Scriptable)om.findStrict("ti.runtime.ompbios.OpenMP", "ti.runtime.ompbios"));
        Global.callFxn("module$meta$init", (Scriptable)om.findStrict("ti.runtime.ompbios.HeapOMP", "ti.runtime.ompbios"));
        Global.callFxn("init", pkgV);
        ((Value.Obj)om.getv("ti.runtime.ompbios.OpenMP")).bless();
        ((Value.Obj)om.getv("ti.runtime.ompbios.HeapOMP")).bless();
        ((Value.Arr)om.findStrict("$packages", "ti.runtime.ompbios")).add(pkgV);
    }

    public void exec( Scriptable xdcO, Session ses )
    {
        this.xdcO = xdcO;
        this.ses = ses;
        om = (Value.Obj)xdcO.get("om", null);

        Object o = om.geto("$name");
        String s = o instanceof String ? (String)o : null;
        isCFG = s != null && s.equals("cfg");
        isROV = s != null && s.equals("rov");

        $$IMPORTS();
        $$OBJECTS();
        OpenMP$$OBJECTS();
        HeapOMP$$OBJECTS();
        OpenMP$$CONSTS();
        HeapOMP$$CONSTS();
        OpenMP$$CREATES();
        HeapOMP$$CREATES();
        OpenMP$$FUNCTIONS();
        HeapOMP$$FUNCTIONS();
        OpenMP$$SIZES();
        HeapOMP$$SIZES();
        OpenMP$$TYPES();
        HeapOMP$$TYPES();
        if (isROV) {
            OpenMP$$ROV();
            HeapOMP$$ROV();
        }//isROV
        $$SINGLETONS();
        OpenMP$$SINGLETONS();
        HeapOMP$$SINGLETONS();
        $$INITIALIZATION();
    }
}
