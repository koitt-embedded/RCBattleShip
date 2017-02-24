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
 * --/COPYRIGHT--*/
/*
 *  ======== OpenMP.xs ========
 */

var OpenMP        = null;
var MultiProc     = null;
var SharedRegion  = null;
var Ipc           = null;


/*
 *  ======== module$meta$init ========
 */
function module$meta$init()
{
    /* Only process during "cfg" phase */
    if (xdc.om.$name != "cfg") {
        return;
    }

    OpenMP = this;
}

/*
 *  ======== module$use ========
 */
function module$use()
{
    // Who sets the Program var?
    var BIOS = xdc.useModule('ti.sysbios.BIOS');
    var Program = xdc.useModule('xdc.cfg.Program');
    var ompSettings = xdc.module('ti.runtime.openmp.Settings');
    var deviceName = String(Program.cpu.deviceName);

    if (ompSettings.usingOpenCL == false)
    {
       if (deviceName.search("DRA7XX") != -1)
       {
          var MultiProc = xdc.useModule('ti.sdo.utils.MultiProc');
          MultiProc.setConfig(null, ["HOST", "IPU2", "IPU1", "DSP2", "DSP1"]);

          /* Set the MultiProc core Id on startup */
          var Startup = xdc.useModule('xdc.runtime.Startup');
          Startup.firstFxns.$add(OpenMP.setProcId);

          // Skip the Timer frequency verification check. 
          // Need to remove this later */
          var Timer = xdc.useModule('ti.sysbios.timers.dmtimer.Timer');
          Timer.checkFrequency = false;

          // Match this to the SYS_CLK frequency sourcing the dmTimers.
          // Not needed once the SYS/BIOS family settings is updated.
          Timer.intFreq.hi = 0;
          Timer.intFreq.lo = 19200000;
       }

       // The function __TI_omp_reset_rtsc_mode must be called after reset
       var Reset = xdc.useModule('xdc.runtime.Reset');
       Reset.fxns.$add('&__TI_omp_reset_rtsc_mode');
    }

    // Setup IPC between the cores participating in the runtime. This is
    // required to initialize a SharedRegion which contains a shared heap,
    // HeapMemMP. When the OpenMP runtime is in RTSC mode, the HeapMemMP is
    // used to support malloc's from shared memory.
    if (OpenMP.useIpcSharedHeap)
       configureIpc(OpenMP.masterCoreIdx, OpenMP.numCores);
    else
    {
       // Default local heap internal to bios
       if (OpenMP.allocateLocalHeap == true)
       {
          var Memory = xdc.useModule('xdc.runtime.Memory');
          var HeapMem = xdc.useModule('ti.sysbios.heaps.HeapMem');
          var heapMemParams = new HeapMem.Params();
          heapMemParams.size = OpenMP.allocateLocalHeapSize;
          Memory.defaultHeapInstance = HeapMem.create(heapMemParams);
       }

       // DSP shared heap for malloc
       if (OpenMP.allocateSharedHeap == true)
       {
          var MemAlloc = xdc.useModule('ti.sysbios.rts.MemAlloc');
          MemAlloc.generateFunctions = false;
          Program.heap = OpenMP.allocateSharedHeapSize;
          xdc.useModule('xdc.runtime.HeapStd');
       }
    }

    // If OpenMP thread stacks are placed in L2SRAM, the runtime will set
    // SP to the global address E.g. on Core 0, 0x800000 is converted to
    // 0x10800000
    // This conversion breaks the initialization routine for BIOS stack check - 
    // ti_sysbios_hal_Hwi_initStack. E.g., on Core 0, STACK_BASE is 0x800000, 
    // local stack is 0x10800000 and MSMC is overwritten by:
    // while (curStack-- > (UArg)STACK_BASE) 
    if (OpenMP.allocateStackFromHeap == false)
    {
        var Hwi = xdc.useModule('ti.sysbios.hal.Hwi');
        Hwi.initStackFlag = false;
        var Task = xdc.useModule('ti.sysbios.knl.Task');
        Task.checkStackFlag = false;
        Task.initStackFlag = false;
    }

    // Reserve HW Semaphores used by the OpenMP runtime
    if (deviceName.search("DRA7XX") == -1)
    {
       var GateHWSem = xdc.useModule('ti.sdo.ipc.gates.GateHWSem');
       if (ompSettings.usingOpenCL == true)
       {
           GateHWSem.setReserved(0);
           GateHWSem.setReserved(1);
           GateHWSem.setReserved(2);
       }
       for (var i = 0; i < OpenMP.hwSemCount; i++) 
       {
           GateHWSem.setReserved(OpenMP.hwSemBaseIdx + i);
       }
    }
    else
    {
       var GateHWSpinlock = xdc.useModule('ti.sdo.ipc.gates.GateHWSpinlock');
       if (ompSettings.usingOpenCL == true)
       {
           GateHWSpinlock.setReserved(0);
           GateHWSpinlock.setReserved(1);
           GateHWSpinlock.setReserved(2);
       }
       for (var i = 0; i < OpenMP.hwSemCount; i++) 
       {
           GateHWSpinlock.setReserved(OpenMP.hwSemBaseIdx + i);
       }
    }

    //Capture CPU clock frequency information from the platform file. 
    //clockFreq is used by the OpenMP runtime timing functions: 
    //omp_get_wtime() and omp_get_wtick()
    OpenMP.clockFreq = Program.cpu.clockRate;
}


/*
 *  ======== module$static$init ========
 */
function module$static$init(mod, params)
{
    mod.useSharedHeap = false;
}

/*
 *  ======== configureIpc ========
 */
function configureIpc(masterCoreIdx, numCores)
{
    var IpcSettings = xdc.useModule('ti.sdo.ipc.family.Settings');
    var procNames   = IpcSettings.getDeviceProcNames().sort();

    // On heterogenous SoCs, exclude HOST cores. The DSPs are named
    // CORE0 through COREn
    var dspNames = [];
    for (coreIdx in procNames) {
       if (procNames[coreIdx].match("CORE"))
           dspNames.push(procNames[coreIdx]);
    }


    if (dspNames.length < numCores) {
        throw("ERROR: Too many processors requested: " + numCores);
    }

    // Configure MultiProc with the base index and number of cores
    var MultiProc   = xdc.useModule('ti.sdo.utils.MultiProc');
    MultiProc.baseIdOfCluster = masterCoreIdx;

    // Total number of processors available in the system
    MultiProc.numProcessors = dspNames.length;

    // Number of processors in cluster set by setConfig
    var endIndex = MultiProc.baseIdOfCluster + numCores;
    MultiProc.setConfig(null,
                 dspNames.slice(MultiProc.baseIdOfCluster, endIndex));


    // Avoid wasting shared memory for MessageQ transports or notify.
    // Ipc is used exclusively to set up a HeapMemMP in the specified
    // Shared Region to support a shared heap for malloc's
    var Ipc         = xdc.useModule('ti.sdo.ipc.Ipc');
    for (var i = 0; i < MultiProc.numProcsInCluster; i++) {
        Ipc.setEntryMeta({
                remoteProcId: i,
                setupMessageQ: false,
                setupNotify: false,
        });
    }

    // Attach and synchronize all cores configured via MultiProc
    Ipc.procSync = Ipc.ProcSync_ALL;
}



/*
 *  ======== module$validate ========
 */
function module$validate()
{
    var ompSettings = xdc.module('ti.runtime.openmp.Settings');
    var deviceName  = String(Program.cpu.deviceName);

    if (ompSettings.usingOpenCL == false)
    {
        if (OpenMP.numCores == 0)
            OpenMP.$logFatal("Set numCores in config file", OpenMP);

        if (OpenMP.clockFreq == 0)
            OpenMP.$logFatal("Set CPU clock rate in Platform file", OpenMP);

    if (deviceName.search("DRA7XX") == -1 && deviceName.search("K2G") == -1) 
    {
        if (OpenMP.msmcBase == 0)
            OpenMP.$logFatal("Set msmcBase in config file", OpenMP);

        if (OpenMP.msmcNoCachePhysicalBase == 0)
            OpenMP.$logFatal("Set msmcNoCacheBase in config file", OpenMP);

        if (OpenMP.msmcSize == 0)
            OpenMP.$logFatal("Set msmcSize in config file", OpenMP);

        if (OpenMP.msmcNoCacheVirtualBase == 0)
            OpenMP.$logFatal("Set msmcNoCacheBase in config file", OpenMP);

        if (OpenMP.msmcNoCacheVirtualSize == 0)
            OpenMP.$logFatal("Set msmcNoCacheSize in config file", OpenMP);
    }
        if (OpenMP.ddrBase == 0)
            OpenMP.$logFatal("Set ddrBase in config file", OpenMP);

        if (OpenMP.ddrSize == 0)
            OpenMP.$logFatal("Set ddrSize in config file", OpenMP);

        if ((OpenMP.allocateStackFromHeap == true) && 
           (OpenMP.allocateStackFromHeapSize == 0))
            OpenMP.$logFatal("Stack size cannot be 0", OpenMP);
    }
}
