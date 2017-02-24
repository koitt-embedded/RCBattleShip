#
#  ======== readme.txt ========
#

mmrpc - Illustrate how to use the MmRcp module to invoke remote functions

Overview
=========================================================================
This example illustrates how to use the MmRpc module as an "RPC" framework.
The application runs on the host processor and the server executable runs
on a slave processor (the IPU in this example). The application calls into
a sample module called MachVis (Machine Vision) which has been implemented
as an RPC stub function. It is the MachVis module which uses the MmRpc module
to marshal the function parameters into a message and to send the message to
the remote processor by calling the MmRpc_call API. The application does not
use MmRpc directly.


         HOST Processor             |            IPU Processor
    --------------------------------|------------------------------
                                    |
       +---------------+            |
       |  Application  |            |
       +---------------+            |
               |                    |
               V                    |
       +---------------+            |           +---------------+
       |    MachVis    |            |           |  MachVis_ipu  |
       +---------------+            |           +---------------+
               |                    |                   ^
               V                    |                   |
       +---------------+            |           +---------------+
       |     MmRpc     |----------------------->| MachVis_skel  |
       +---------------+            |           +---------------+


When the message is received on the IPU processor, the framework will
invoke the appropriate "skel" function and pass the message as an argument.
The skel function will unmarshal the arguments from the message and invoke
the actual MachVis library function. In the illustration above, the skel
function is impelmented in 'MachVis_skel' and the MachVis library functions
are implemented in 'MachVis_ipu'.

When the MachVis library function returns, the call path unwinds. The skel
function will marshal the return values into the message and send the
message back to the HOST processor. When the return message is received on
the HOST, the MmRpc_call API will return back into the MachVis stub function
which will unmarshal the return values and finally return to the application.

Discussion Points
=========================================================================
The MachVis abstraction is in the folder ex12_mmrpc/machvis. This folder
contains both the stub and skel functions as well as the actual MachVis
library implementation. The stub functions are in MachVis.c which is built
into a library for the application. The skel functions are in MachVis_skel.c
which is built into a library for the server executable.

The file MachVis_skel.c also contains a startup function, MachVis_startup
in this example, which is invoked by SYS/BIOS. This function registers the
MachVis service which allows the MachVis module on the host to establish a
communication channel between the host and slave processors. Look in
ex12_mmrpc/ipu/Ipu.cfg to see how the startup function is configured.

The file MachVis_skel.h contains the MachVis service name and the skel
function identifiers. This header file is used by the MachVis module to
identify the service name and to specify which skel function to invoke.


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
     |   |_ ipc_m_mm_pp_bb/
     |   |_ qnx_m_m_b/
     |   |_ ti_c6x_m_m_p/
     |   |_ ti_tms470_m_m_p/
     |   |_ xdctools_m_mm_pp_bb/
     |
     |_ work/
         |_ ex12_mmrpc/
         |   |_ host/
         |   |_ ipu/
         |   |_ machvis/
         |   |_ makefile
         |   |_ products.mak
         |   |_ readme.txt
         |
         |_ products.mak

    In the example, there is a top-level makefile which builds each of the
    lower directories. Some folders are processor specific, such as 'host'
    and 'ipu'. Others build code for multiple processors, such as 'machvis'.
    The folder named 'shared' contains common files used by all executables,
    such as config.bld which defines the memory map.

 2. Unpack the ex12_mmrpc.zip file into the work folder.

    cd work
    unzip <...>/ex12_mmrpc.zip

 3. Setup the build environment. Edit products.mak and set the install paths
    as defined by your physical development area. Each example has its own
    products.mak file; you may also create a products.mak file in the parent
    directory which will be used by all examples.

    DEPOT = /testbench/Depot

    BIOS_INSTALL_DIR                = $(DEPOT)/bios_m_mm_pp_bb
    IPC_INSTALL_DIR                 = $(DEPOT)/ipc_m_mm_pp_bb
    QNX_INSTALL_DIR                 = $(DEPOT)/qnx_m_m_b
    XDC_INSTALL_DIR                 = $(DEPOT)/xdctools_m_mm_pp_bb
    ti.targets.arm.elf.M4           = $(DEPOT)/ti_tms470_m_m_p

 4. Build the example. This will build both debug and release versions.
    The default goal is the 'install' goal. Run 'make help' to see all
    available options.

    cd ex12_mmrpc
    make

    Look in the following folders for the generated files. All executables
    are copied to these folders for convenience; it makes it easier when
    loading them into CCS.

    install/ex12_mmrpc/debug/
    install/ex12_mmrpc/release/

 5. Optional. Use the install goal to copy the executables to a specific
    folder of your choice.

    cd ex12_mmrpc
    make install EXEC_DIR=/<destination folder>

    The executables are copied to the following folders.

    /<destination folder>/ex12_mmrpc/debug
    /<destination folder>/ex12_mmrpc/release


Running the example
=========================================================================
Copy the example program files to your target file system. Execute the
following commands in a shell running on your target.

 1. Launch the shared memory allocator (for QNX only). This example uses
    the shared memory allocator to illustrate the marshalling of embedded
    pointers. The shared memory allocator must be running before you run
    this example.

    cd .../armle-v7/bin
    ./shmemallocator

 2. Load the IPU processor with the server program.

    cd .../ex12_mmrpc/debug
    .../armle-v7/bin/syslink -f server_ipu.xem4

 3. Run the host side application program.

    cd .../ex12_mmrpc/debug
    ./app_host

 4. You should see output on your console similar to the following:

    --> main:
    App_main: MachVis_add(44, 66), status=110
    App_main: compute->coef=0xe0400000
    App_main: compute->key=0xaba0
    App_main: compute->size=0x1000
    App_main: compute->inBuf=0x28001000
    App_main: compute->outBuf=0x28005000
    App_main: MachVis_compute(0x28000000)
    App_main: compute->coef=0xe0400000
    App_main: compute->key=0xa0a0 (expect 0xa0a0)
    App_main: compute->size=0x1000
    App_main: compute->inBuf=0x28001000
    App_main: compute->outBuf=0x28005000
    App_main: compute->inBuf[0]=0x2010 (expect 0x2010)
    App_main: compute->outBuf[0]=0xe0402010 (expect 0xe0402010)
    <-- main: status=0
