#
#  ======== readme.txt ========
#

message queue - Send round-trip message from client to server and back


Overview
=========================================================================
This is a MessageQ example using the client/server pattern. It is a two
processor example. It only builds for the HOST and DSP processors. You can
build for either DSP1 or DSP2.

The DSP processor is the server. It will create a named message queue.
The server does not open any queues because it will extract the return
address from the message header. The server returns all messages to the
sender. It does not access the message pool.

The HOST processor is the client application. The client creates an
anonymous message queue. The client also creates and manages the message
pool. The client's return address is set in the message header for each
message before sending it to the server.


Build Instructions
=========================================================================

 1. Create a work folder on your file system.

    mkdir work

 2. Extract this example into your work folder.

    cd work
    unzip <...>/ex02_messageq.zip

 3. Setup the build environment. Edit products.mak and set the install paths
    as defined by your physical development area. Each example has its own
    products.mak file; you may also create a products.mak file in the parent
    directory which will be used by all examples.

    edit ex02_messageq/products.mak

    IPC_INSTALL_DIR  = <...>/ipc_m_mm_pp_bb
    BIOS_INSTALL_DIR = <...>/bios_m_mm_pp_bb
    XDC_INSTALL_DIR  = <...>/xdctools_m_mm_pp_bb

    The compilers ship with CCS. You can use them to build this example.

    edit ex02_messageq/products.mak

    CCS = <...>/ccsv6/tools/compiler

    gnu.targets.arm.A15F           = $(CCS)/gcc_arm_none_eabi_m_m_p
    ti.targets.elf.C66             = $(CCS)/c6000_m_m_p
    ti.targets.arm.elf.M4          = $(CCS)/arm_m_m_p
    ti.targets.arp32.elf.ARP32_far = $(CCS)/arp32_m_m_p

 4. Build the example. This will build only debug versions of the executables.
    Edit the lower makefiles and uncomment the release goals to build both
    debug and release executables.

    cd ex02_messageq
    make

    By default, the example builds for host and dsp1. Look in the following
    folders for the executables.

    ex02_messageq/host/bin/debug/app_host.xa15fg
    ex02_messageq/dsp1/bin/debug/server_dsp1.xe66

 5. Issue the following commands to clean your example.

    cd ex02_messageq
    make clean


Build Configuration
=========================================================================
When building, you can choose between dsp1 or dsp2. Use these instructions
to specify which processor to build and to configure the host to use the
correct server.

 1. Specify which two processors to build. Edit the top-level makefile and
    modify the PROCLIST macro to specify which processors to build. The
    list of available processors in defined in the ALL macro. However,
    the client must always run on the HOST. For example, follow these
    steps to build for dsp2.

    edit ex02_messageq/makefile

# ipu1: implies smp mode
# ipu1-0 ipu1-1: implies non-smp mode
ALL = dsp1 dsp2 host
PROCLIST = dsp1 dsp2 host

 2. Edit the client source file and specify the name of the server processor.

    edit ex02_messageq/host/MainHost.c

    /* define server processor name */
    #define SERVER "DSP2"

 3. Clean and build your example.

    cd ex02_messageq
    make clean
    make
