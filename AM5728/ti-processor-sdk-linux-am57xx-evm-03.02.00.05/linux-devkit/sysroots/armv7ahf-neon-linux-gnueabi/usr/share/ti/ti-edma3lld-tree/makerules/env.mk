# File: env.mk. This file contains all the paths and other ENV variables

#
# Module paths
#

# Directory where all internal software packages are located; typically 
#  those that are checked into version controlled repository. In this case all
#  the OMX components and SDK/OMX demo.
INTERNAL_SW_ROOT ?= E:/EDMA/edma3_lld_02_12_01_25

# Directory where all external (imported) software packages are located; typically 
#  those that are NOT checked into version controlled repository. In this case,
#  compiler tool chains, BIOS, XDC, Syslink, IPC, FC, CE, drivers, codecs, etc.
EXTERNAL_SW_ROOT ?= C:/PROGRA~2/TEXASI~1

# Destination root directory.
#   - specify the directory where you want to place the object, archive/library,
#     binary and other generated files in a different location than source tree
#   - or leave it blank to place then in the same tree as the source
#DEST_ROOT = E:/Temp/edma3_lld_02_11_02_03

# Utilities directory. This is required only if the build machine is Windows.
#   - specify the installation directory of utility which supports POSIX commands
#     (eg: Cygwin installation or MSYS installation).
UTILS_INSTALL_DIR = /home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/am57xx-evm/usr/share/ti/ti-xdctools-tree

# Set path separator, etc based on the OS
# On windows if sh.exe is installed (cygwin installs) make will execute
# commands on sh or it executes on windows cmd prompt. When executing on sh,
# unix style command seperator is used.
ifeq ($(OS),Windows_NT)
  PATH_SEPARATOR = ;
  UTILSPATH = $(UTILS_INSTALL_DIR)/bin/
  ifeq (cygwin,$(findstring cygwin,$(PATH)))
  COMMAND_SEPERATOR = ;
  else
  COMMAND_SEPERATOR = &
  endif
else 
  # else, assume it is linux
  PATH_SEPARATOR = :
  COMMAND_SEPERATOR = ;
endif

# BIOS
bios_PATH = /home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/am57xx-evm/usr/share/ti/ti-sysbios-tree
bios_INCLUDE = $(bios_PATH)/packages

# XDC
xdc_PATH = /home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/am57xx-evm/usr/share/ti/ti-xdctools-tree
xdc_INCLUDE = $(xdc_PATH)/packages

# EDMA3 LLD
edma3_lld_PATH = /home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/work/am57xx_evm-linux-gnueabi/edma3-lld-rtos/2.12.02.26-r0.0/git
include $(edma3_lld_PATH)/packages/component.mk

#
# Tools paths
#
# Cortex-M3
CODEGEN_PATH_M3 = /home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/x86_64-linux/usr/share/ti/ti-cgt-arm
# Cortex-M4
CODEGEN_PATH_M4 = /home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/x86_64-linux/usr/share/ti/ti-cgt-arm
# Cortex-A8
CODEGEN_PATH_A8 = /home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/x86_64-linux/usr/share/ti/ti-cgt-arm
# Cortex-A8 GCC
CODEGEN_PATH_A8_GCC = /home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/x86_64-linux/usr/share/ti/gcc-arm-none-eabi

# Cortex-A15
CODEGEN_PATH_A15 = /home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/x86_64-linux/usr/share/ti/gcc-arm-none-eabi
# Cortex-A15_GCC
CODEGEN_PATH_A15_GCC = /home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/x86_64-linux/usr/share/ti/gcc-arm-none-eabi

# ARM-9
CODEGEN_PATH_ARM9 = /home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/x86_64-linux/usr/share/ti/ti-cgt-arm
# ARM-9 GCC
CODEGEN_PATH_A9_GCC = /home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/x86_64-linux/usr/share/ti/gcc-arm-none-eabi

# DSP - Since same toolchain does not support COFF and ELF, there are two entries
#        This would go away when one version supports both formats
CODEGEN_PATH_DSP = /home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/x86_64-linux/usr/share/ti/cgt-c6x
CODEGEN_PATH_DSPELF = /home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/x86_64-linux/usr/share/ti/cgt-c6x

# ARP32
CODEGEN_PATH_ARP32 = $(EXTERNAL_SW_ROOT)/ARP32_1.0.2

# Commands commonly used within the make files

RM = $(UTILSPATH)rm
RMDIR = $(UTILSPATH)rm -rf
MKDIR = $(UTILSPATH)mkdir
ECHO = @$(UTILSPATH)echo
# MAKE = $(UTILSPATH)make
EGREP = $(UTILSPATH)egrep
CP = $(UTILSPATH)cp

# This is to avoid using full blown cygwin - chmod is really needed only linux
ifeq ($(OS),Windows_NT)
CHMOD = @echo
else
CHMOD = $(UTILSPATH)chmod
endif

#
# XDC specific ENV variables
#

# XDC Config.bld file (required for configuro) ; Derives from top-level omx_PATH
CONFIG_BLD_XDC_674 = $(edma3_lld_PATH)/packages/config.bld
CONFIG_BLD_XDC_64p = $(edma3_lld_PATH)/packages/config.bld
CONFIG_BLD_XDC_64t = $(edma3_lld_PATH)/packages/config.bld
CONFIG_BLD_XDC_a8 = $(edma3_lld_PATH)/packages/config.bld
CONFIG_BLD_XDC_arm9 = $(edma3_lld_PATH)/packages/config.bld
CONFIG_BLD_XDC_66 = $(edma3_lld_PATH)/packages/config.bld
CONFIG_BLD_XDC_m3 = $(edma3_lld_PATH)/packages/config.bld
CONFIG_BLD_XDC_m4 = $(edma3_lld_PATH)/packages/config.bld
CONFIG_BLD_XDC_a15 = $(edma3_lld_PATH)/packages/config.bld

XDCPATH = $(bios_PATH)/packages;$(xdc_PATH)/packages;$(edma3_lld_PATH)/packages;
export XDCPATH

XDCROOT = $(xdc_PATH)
XDCTOOLS = $(xdc_PATH)
export XDCROOT
export XDCTOOLS

TMS470_CGTOOLS = $(CODEGEN_PATH_M3)
CGTOOLS = $(CODEGEN_PATH_DSP)
CGTOOLS_ELF = $(CODEGEN_PATH_DSPELF)
export TMS470_CGTOOLS

CODESOURCERYCGTOOLS = $(CODEGEN_PATH_A8)
export CODESOURCERYCGTOOLS

# Nothing beyond this point
