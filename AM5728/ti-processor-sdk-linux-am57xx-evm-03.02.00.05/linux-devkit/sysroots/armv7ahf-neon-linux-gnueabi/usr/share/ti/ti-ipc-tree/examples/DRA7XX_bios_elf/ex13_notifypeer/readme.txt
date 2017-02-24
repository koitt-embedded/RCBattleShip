#
#  ======== readme.txt ========
#
notify peer - use only notify to communicate to a peer processor

Overview
=========================================================================
This is an example of IPC Scalability. It uses the client/server design
pattern. Initially, the example builds only for two processors: HOST and
DSP1. The client runs on HOST and the server runs on DSP1.

The client (HOST) creates an anonymous message queue. The client also
creates and manages its own message pool. And it opens the server message
queue using its name. The client initiates the data flow by allocating
a message from the pool, placing its return address in the message header
and sending the message to the server. It then waits for the message to
be returned. When it receives the return message, the message is returned
to the pool. The client repeats this in a loop.

The server (DSP1) creates a named message queue, then waits on it for
messages. When a message arrives, the server performs the requested work.
When the work is done, the server extracts the return address from the
message header and sends the message back to the client. The server never
opens any message queues and does not access the message pool.

Build and run the example to become familiar with the execution flow.

In part 2, you will add EVE1 as a peer processor to DSP1. However, the
DSP1 to EVE1 transport will be scaled down to just the notify layer. DSP1
will use EVE1 to help processes the messages received from the client.

Since DSP1 will need to wait on both the message queue and the notify queue,
we introduce events. The SYS/BIOS event object can be used to wait on
multiple input sources.


Build Instructions
=========================================================================

 1. Create a work folder on your file system.

    mkdir work

 2. Extract this example into your work folder.

    cd work
    unzip .../ex13_notifypeer.zip

 3. Setup the build environment. Edit products.mak and set the install paths
    as defined by your physical development area. Each example has its own
    products.mak file; you may also create a products.mak file in the parent
    directory which will be used by all examples.

    edit ex13_notifypeer/products.mak

    IPC_INSTALL_DIR  = .../ipc_m_mm_pp_bb
    BIOS_INSTALL_DIR = .../bios_m_mm_pp_bb
    XDC_INSTALL_DIR  = .../xdctools_m_mm_pp_bb

    The compilers ship with CCS. You can use them to build this example.

    edit ex13_notifypeer/products.mak

    CCS = .../ccsv6/tools/compiler

    gnu.targets.arm.A15F           = $(CCS)/gcc_arm_none_eabi_m_m_p
    ti.targets.elf.C66             = $(CCS)/c6000_m_m_p
    ti.targets.arm.elf.M4          = $(CCS)/arm_m_m_p
    ti.targets.arp32.elf.ARP32_far = $(CCS)/arp32_m_m_p

 4. Build the example. This will build only debug versions of the executables.
    Edit the lower makefiles and uncomment the release goals to build both
    debug and release executables.

    cd ex13_notifypeer
    make

    By default, the example builds for host and dsp1. Look in the following
    folders for the executables.

    ex13_notifypeer/host/bin/debug/app_host.xa15fg
    ex13_notifypeer/dsp1/bin/debug/server_dsp1.xe66

 5. Issue the following commands to clean your example.

    cd ex13_notifypeer
    make clean


Part 2: Adding EVE1
=========================================================================
To add EVE1 as a peer processor to DSP1, you will need to modify the
top-level makefile and the DSP1 source file. Follow the instructions
below.

 1. Add eve1 to the processor list. Edit the top-level makefile and
    add eve1 the the PROCLIST macro. This will instruct make to also
    build in the eve1 folder.

    edit ex13_notifypeer/makefile

    PROCLIST = dsp1 eve1 host

 2. Enable eve1 communication in the dsp1 source file. Edit the server
    source file and uncomment the EVE macro.

    edit ex13_notifypeer/dsp1/Server.c

    /* define the EVE peer */
    #define EVE "EVE1"

 3. Rebuild the example.

    cd ex13_notifypeer
    make

    You should see a rebuild of dsp1 and a new build of eve1. Look for the
    new eve executable in the following folder.

    ex13_notifypeer/eve1/bin/debug/alg_eve1.xearp32F
