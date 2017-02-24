#
#  ======== readme.txt ========
#

hello - Send one-way messages from writer to reader

Overview
=========================================================================
This is the "Hello World" example for IPC. It is a very simple example
to help you get started. It is a two processor example. You can build
it for any two processors on your device, but only for two at a time.

It uses the reader/writer design pattern. One processor will be the reader
and the other will be the writer. The reader creates a message queue and
waits on it for messages. The writer opens the reader's message queue
and sends messages to it. The writer allocates the message from a shared
message pool and the reader returns the message to the pool. Thus, messages
are sent in only one direction, but they are recycled back to the pool.


Build Instructions
=========================================================================
 1. Create a work folder on your file system.

    mkdir work

 2. Extract this example into your work folder.

    cd work
    unzip <...>/ex01_hello.zip

 3. Setup the build environment. Edit products.mak and set the install paths
    as defined by your physical development area. Each example has its own
    products.mak file; you may also create a products.mak file in the parent
    directory which will be used by all examples.

    edit ex01_hello/products.mak

        IPC_INSTALL_DIR  = <...>/ipc_m_mm_pp_bb
        BIOS_INSTALL_DIR = <...>/bios_m_mm_pp_bb
        XDC_INSTALL_DIR  = <...>/xdctools_m_mm_pp_bb

    The compilers ship with CCS. You can use them to build this example.

    edit ex01_hello/products.mak

        CCS = <...>/ccsv6/tools/compiler

        gnu.targets.arm.A15F           = $(CCS)/gcc_arm_none_eabi_m_m_p
        ti.targets.elf.C66             = $(CCS)/c6000_m_m_p
        ti.targets.arm.elf.M4          = $(CCS)/arm_m_m_p
        ti.targets.arp32.elf.ARP32_far = $(CCS)/arp32_m_m_p

 4. Build the example. This will build debug versions of the executables.
    Edit the lower makefiles and uncomment the release goals to build both
    debug and release executables.

    cd ex01_hello
    make

    By default, the example builds for dsp1 and dsp2. Look in the following
    folders for the executables.

    ex01_hello/dsp1/bin/debug/hello_dsp1.xe66
    ex01_hello/dsp2/bin/debug/hello_dsp2.xe66

    Issue the following commands to clean your example.

    cd ex01_hello
    make clean


Build Configuration
=========================================================================
This example can be built for any two processors. However, you must ensure
that each processor is assigned the appropriate role. One processor must
be the writer and the other processor must be the reader. In addition, you
must tell each processor the name of its peer. This is how IPC will make
the correct connections between processors.

 1. Specify which two processors to build. Edit the top-level makefile and
    modify the PROCLIST macro to specify which processors to build. The
    list of available processors in defined in the ALL macro. For example,
    to build for dsp1 and eve1, make the following changes.

    edit ex01_hello/makefile

        PROCLIST = dsp1 eve1

 2. Specify the role for each processor. You need to edit the source file
    for each processor and specify its role and name its peer.

    edit ex01_hello/dsp1/HelloDsp1.c

        Int role = Role_WRITER;
        String peer = "EVE1";

    edit ex01_hello/eve1/HelloEve1.c

        Int role = Role_READER;
        String peer = "DSP1";

    Remove the error directive. This was added as a marker in case you
    forgot to specify the role or peer. Delete the following line:

        #error Must define role and peer

 3. Specify the owner of SharedRegion zero. IPC uses a block of memory
    commonly referred to as SR-Zero. This is the first entry in the array
    of shared regions. This region must have an owner. One of the two
    processors you are using must be assigned as the owner. It does not
    matter which one.

    Edit the shared configuration file and specify the name of the
    processor which is to be the owner. Look for the ownerProcId
    property of the SharedRegion.Entry.

    edit ex01_hello/shared/ipc.cfg.xs

        ownerProcId: MultiProc_getIdMeta("DSP1"),

 4. Clean and build your example.

    cd ex01_hello
    make clean
    make


Running the example
=========================================================================
Use CCS to load and run the executables. These instructions assume the
default build configuration. Substitute the actual programs you have built.

 1. Launch CCS. Connect to the two processors you have built for. Your
    specific connect sequence will depend on your setup.

 2. IPU only. Before loading a program on the IPU processor, you must
    program its AMMU. Use the gel file provided with the example.

    Select IPU1_C0 in the Debug window

    Open the GEL Files window

        Tools > GEL Files

    Load the gel file provided in the example.

        ex01_hello/ipu1/ex01_hello_ipu1.gel

    Run the script to configure the AMMU.

        Scripts > ex01_hello > ex01_hello_ipu1_ammu_config

    The IPU is now ready for program loading.

 3. EVE only. Before loading a program on the EVE processor, you must
    program its MMU. Use the gel file provided with the example.

    You must be disconnected from the processor before you program its
    MMU because the gel script will reset the processor. Disconnect from
    the processor now.

    Use the DebugSS device to load and run the gel file.

        Debug > Right-Mouse-Button > Show all cores
        Select DebugSS (open Non Debuggable Devices)

    Open the GEL Files window

        Tools > GEL Files

    Load the gel file provided in the example.

        ex01_hello/eve1/ex01_hello_eve1.gel

    Run the script to configure the AMMU.

        Scripts > EVE MMU Configuration > ex01_hello_eve1_ammu_config

    Now you can select the EVE processor and connect to it. The EVE is
    now ready for program loading.

 4. Load the programs. Select the processor and load the program. The
    programs are located at the following locations.

    ex01_hello/dsp1/bin/debug/hello_dsp1.xe66
    ex01_hello/dsp2/bin/debug/hello_dsp2.xe66

 5. Run the example. Select the two processors and run them. The example
    completes quickly, but there is no visual indication. Pause both
    processors after a few seconds.

 6. Use the RTOS Object View to inspect the results. Each processor will
    write log events which you can inspect in the ROV window. Open this
    tool and select the LoggerBuf module. Open the Records tab to see the
    individual log events. Do this for both the writer program and the
    reader program.

    Select DSP1 in the Debug window

    Open the RTOS Object View

        Tools > RTOS Object View (ROV)

    Select the LoggerBuf module in the object browser
    Click on the Records tab
    Select the AppLog item

    For the writer, you should see the following events (partial list):

    1   66013  xdc.runtime.Main  main: -->
    2   79408  xdc.runtime.Main  App_taskFxn: -->
    3  337945  xdc.runtime.Main  App_taskFxn: ipc ready
    4  338463  xdc.runtime.Main  App_writer: -->
    5  676262  xdc.runtime.Main  App_writer: opened reader queue
    6  681172  xdc.runtime.Main  App_writer: sending job=1
    7  693607  xdc.runtime.Main  App_writer: sending job=2
    8  706192  xdc.runtime.Main  App_writer: sending job=3
    ...

    For the reader, you should see the following events (partial list):

    1   54682  xdc.runtime.Main  main: -->
    2   68095  xdc.runtime.Main  App_taskFxn: -->
    3  325859  xdc.runtime.Main  App_taskFxn: ipc ready
    4  326320  xdc.runtime.Main  App_reader: -->
    5  359969  xdc.runtime.Main  App_reader: reader is ready
    6  798508  xdc.runtime.Main  App_reader: received job=1
    7  807514  xdc.runtime.Main  App_reader: received job=2
    8  813934  xdc.runtime.Main  App_reader: received job=3
    ...

 7. Inspect the role variable. If you want to verify the role performed
    by each processor, you can use the CCS Expressions window. Enter the
    name of the variable (role) into this window. Then select one of the
    processors. CCS will display the value of this variable. You should
    see the following values:

    role = 1    (reader)
    role = 2    (writer)
