#
#  ======== readme.txt ========
#

ping - Send a message between all cores in the system

Overview
=========================================================================
This example is used to exercise every communication path between all
processors in the system (including local delivery on the current
processor). The example is also organized in a suitable manner to develop
an application with different compute units on each processor.

Each executable will create two tasks: 1) the server task, and 2) the
application task. The server task creates a message queue and then waits
on that queue for incoming messages. When a message is received, the
server task simply sends it back to the original sender.

The application task creates its own message queue and then opens every
server message queue in the system (including the server queue on the
local processor). The task sends a message to a server and waits for the
message to be returned. This is repeated for each server in the system
(including the local server).


Build Instructions
=========================================================================

 1. Setup a development area. A typical setup might look like this. The
    Depot folder contains installed products. The work folder contains
    each of the examples (eg. hello, ping, etc.). Each example contains
    its own products.mak file which will include a parent products.mak
    file if it exists. The parent file must be created by you.

    testbench/
     |_ Depot/
     |   |_ bios_m_mm_pp_bb/
     |   |_ gnu_arm_vv_bb/
     |   |_ ipc_m_mm_pp_bb/
     |   |_ ti_arp32_m_m_p/
     |   |_ ti_c6x_m_m_p/
     |   |_ ti_tms470_m_m_p/
     |   |_ xdctools_m_mm_pp_bb/
     |
     |_ work/
         |_ ping/
         |   |_ dsp1/
         |   |_ dsp2/
         |   |_ eve1/
         |   |_ eve2/
         |   |_ eve3/
         |   |_ eve4/
         |   |_ host/
         |   |_ ipu1/
         |   |_ ipu1-0/
         |   |_ ipu1-1/
         |   |_ ipu2/
         |   |_ shared/
         |   |_ makefile
         |   |_ products.mak
         |   |_ readme.txt
         |
         |_ products.mak

    In the ping example, there is a top-level makefile which simply builds
    each of the lower directories. There is a directory for each processor
    named by the IPC processor name. The folder named 'shared' contains
    common files used by all executables, such as config.bld which defines
    the memory map.

 2. Unpack the ping.zip file into the work folder.

    cd work
    unzip <...>/ping.zip

 3. Setup the build environment. Edit products.mak and set the install paths
    as defined by your physical development area. Each example has its own
    products.mak file; you may also create a products.mak file in the parent
    directory which will be used by all examples.

    DEPOT = /testbench/Depot

    BIOS_INSTALL_DIR                = $(DEPOT)/bios_m_mm_pp_bb
    IPC_INSTALL_DIR                 = $(DEPOT)/ipc_m_mm_pp_bb
    XDC_INSTALL_DIR                 = $(DEPOT)/xdctools_m_mm_pp_bb
    gnu.targets.arm.A15F            = $(DEPOT)/gnu_arm_vv_bb
    ti.targets.elf.C66              = $(DEPOT)/ti_c6x_m_m_p
    ti.targets.arm.elf.M4           = $(DEPOT)/ti_tms470_m_m_p
    ti.targets.arp32.elf.ARP32_far  = $(DEPOT)/ti_arp32_m_m_p

 4. Build the example. This will build only debug versions of the executables.
    Edit the lower makefiles and uncomment the release goals to build both
    debug and release executables.

    cd ping
    make

    Look in the following folders for the generated files. All executables
    are copied to these folders for convenience; it makes it easier when
    loading them into CCS.

    install/ping/debug/
    install/ping/release/

 5. Optional. Use the install goal to copy the executables to a specific
    folder of your choice.

    cd ping
    make install EXEC_DIR=/<full pathname>/<platform>

    The executables are copied to the following folders.

    /<full pathname>/<platform>/ping/debug
    /<full pathname>/<platform>/ping/release


Build Configuration
=========================================================================

This example can be built for a subset of all available processors. For
example, you might want to build and run this example for the following
processors: DSP1, EVE1, EVE2. Use the following instructions to configure
this example for a subset of processors.

Note: you must always run the set of processors you configured and built.
In this example, you must run the DSP1, EVE1, and EVE2 executables; you
cannot run just one of them. Because the IPC has been configured for
ProcSync_ALL, all processors must participate in the call to Ipc_start().

 1. Specify the processor list in the top-level makefile.

    edit ping/makefile

    Edit the list of processors in the PROCLIST variable.

# ipu1: implies smp mode
# ipu1-0 ipu1-1: implies non-smp mode
# eve1, eve2, eve3, eve4 not added by default. Can be added as needed.
# PROCLIST = dsp1 dsp2 eve1 eve2 eve3 eve4 ipu1 ipu2 host
PROCLIST = dsp1 dsp2 ipu1 ipu2 host

 2. Clean and rebuild the example.

    cd ping
    make clean
    make

    Look in the following folders for the generated files.

    ping/install/ping/debug
    ping/install/ping/release


Running with CCS on Virtio VPVayu simulator
=========================================================================
 1. Launch Virtio VPVayu

    Start > Innovator
    File > Open Project or File > C:/Virtio/Platforms/VPVayu/VPVayu.vsp

    Toolbar > vayu_general (Platform)

    If you are using the CortexA15_0 core (with HOST):
        Params > User Parameters
        ArmCortexA15_DebugEnable: true

        Params > VPVayu SDP > Vayu > CPU_SS
        InitValue_Core0: 0

    If you are *not* using the CortexA15_0 core (no host):
        Params > User Parameters
        ArmCortexA15_DebugEnable: false

        Params > VPVayu SDP > Vayu > CPU_SS
        InitValue_Core0: 1

    Build/Run > Start or Go (F5), this launches the Virtio Vayu simulator

    Wait for the following message in the Output Window
    CortexA15x2CT_FM: CADI Debug Server started

    Minimize the windows.
    * note: The Cockpit::VPVayu window will indicate '(Not Responding)'.

 2. Launch CCS

    Start > CCS_5_3_0
    Launch one of the following target configurations:
    + VPVayu_5.2
    + VPVayu_5.2_no_host

 3. Place HOST in non-secure mode. If you forget this, the SYS/BIOS tick
    will not run

    In Debug window, select CortexA15_0
    Scripts > Vayu Configuration > enterNonSecureMode

 4. Hide unused cores. This just removes clutter from the Debug window.
    Select any cores you will not be using, then select RMB > Hide Cores.

 5. Group remaining cores. This is more of a convenience than a necessity.

    In Debug window, select cores:
    + IPU1_core_0
    + IPU1_core_1
    RMB > Group cores

    In Debug window, select cores:
    + IPU2_core_0
    + IPU2_core_1
    RMB > Group cores

    In Debug window, select cores:
    + DSP_1
    + DSP_2
    + EVE_1
    + EVE_2
    + EVE_3
    + EVE_4
    RMB > Group cores

 6. Load each executable onto its respective processor. Note that the CCS
    processor name may not match exactly with the executable name. Use
    the following mapping.

    server_dsp1.xe66      --> DSP_1
    server_dsp2.xe66      --> DSP_2
    server_eve1.xearp32f  --> EVE_1
    server_eve2.xearp32f  --> EVE_2
    server_eve3.xearp32f  --> EVE_3
    server_eve4.xearp32f  --> EVE_4
    server_ipu1.xem4      --> IPU1_core_0
    server_ipu2.xem4      --> IPU2_core_0
    server_host.xa15fg    --> CortexA15_0

    When loading the executable onto IPU1 or IPU2, you only need to load
    core_0, not both cores. After loading core_0, select core_1 and just
    load symbols, then restart the core to update the PC register.

 7. Set a software breakpoint in each executable's "done" function. Use the
    CCS Disassembly window. For the Benelli processors, you will need to set
    the same breakpoint on both cores. Use the following mapping of CCS
    processor names to function names.

    DSP_1        --> MainDsp1_done
    DSP_2        --> MainDsp2_done
    EVE_1        --> MainEve1_done
    EVE_2        --> MainEve2_done
    EVE_3        --> MainEve3_done
    EVE_4        --> MainEve4_done
    IPU1_core_0  --> MainIpu1_done
    IPU1_core_1  --> MainIpu1_done
    IPU2_core_0  --> MainIpu2_done
    IPU2_core_1  --> MainIpu2_done
    CortexA15_0  --> MainHost_done

 8. Run the processors. I recommend running CortexA15_0 first, then other
    processors. As each processor hits the "done" breakpoint, make a note
    and let the processor continue. Do this for each processor. If the
    CortexA15_0 status shows 'Suspended - Cross-triggering', then simply
    run it again.

    Select CortexA15_0 > Run > Resume (F8)
    Select Group3 > Run > Resume (F8)
    Select Group2 (Synchronous) > Run > Resume (F8)
    Select Group1 (Synchronous) > Run > Resume (F8)

 9. Inspecting log events. Use the CCS RTOS Object View (ROV) to inspect
    the LoggerBuf module for each processor. You should see log events from
    both the server task and the application task.

    Select CortexA15_0 > Run > Suspend
    Select Group3 > Run > Suspend
    Select Group2 > Run > Suspend
    Select Group1 > Run > Suspend

    Select CortexA15_0
    Open ROV window
    Select LoggerBuf module

    There should be several log events in window. Repeat this for each
    processor. The number of events will depend on how many processors
    are configured into your configuration.
