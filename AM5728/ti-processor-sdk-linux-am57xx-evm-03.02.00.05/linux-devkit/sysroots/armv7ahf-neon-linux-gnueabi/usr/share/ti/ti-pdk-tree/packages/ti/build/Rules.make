#
# Copyright (c) 2013-2016, Texas Instruments Incorporated
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
# *  Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#
# *  Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# *  Neither the name of Texas Instruments Incorporated nor the names of
#    its contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
# THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
# CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
# OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
# WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
# OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
# EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#

ifeq ($(pdk_PATH), )

#Default build environment, windows or linux
ifeq ($(OS),)
  #if nothing is defined, default to linux
  OS ?= linux
endif

#Default BUILD_OS_TYPE (tirtos/baremetal)
BUILD_OS_TYPE ?= tirtos

# Default board
# Supported values: tda2xx-evm, am572x-evm, dra75x-evm, tda3xx-evm, dra78x-evm,
#                   am572x-idk am571x-evm,  evmAM572x, idkAM571x, idkAM572x
#                   evmK2H, evmK2K, evmK2E, evmK2L, evmK2G, evmC6678, evmC6657,
#                   evmAM335x, icev2AM335x, skAM335x, bbbAM335x,
#                   evmAM437x idkAM437x skAM437x
#
BOARD ?= tda2xx
SOC ?= tda2xx

ifeq ($(OS),Windows_NT)
#Paths for windows machine
  TOOLCHAIN_PATH_GCC ?= c:/ti/ccsv5/tools/compiler/gcc-arm-none-eabi-4_9-2015q3
  TOOLCHAIN_PATH_TI_CGT ?= c:/ti/ti-cgt-arm_15.12.1.LTS
  C6X_GEN_INSTALL_PATH ?= c:/ti/ti-cgt-c6000_8.1.0
  TOOLCHAIN_PATH_EVE ?= c:/ti/arp32_1.0.7
  PDK_INSTALL_PATH ?= c:/ti/pdk
  BIOS_INSTALL_PATH ?= c:/ti/bios_6_46_00_23
  XDC_INSTALL_PATH ?= c:/ti/xdctools_3_32_00_06_core
  EDMA3LLD_BIOS6_INSTALLDIR ?= c:/ti/edma3_lld_02_12_00_20
  NDK_INSTALL_PATH ?=  c:/ti/ndk_2_24_03_35
  utils_PATH ?= $(XDC_INSTALL_PATH)/bin
  export utils_PATH
else
#Paths for linux machine
  TOOLCHAIN_PATH_GCC ?= /opt/tools/gcc-arm-none-eabi-4_9-2015q3
  TOOLCHAIN_PATH_TI_CGT ?= /opt/tools/cgtools/ti-cgt-arm_15.12.1.LTS
  C6X_GEN_INSTALL_PATH ?= /opt/tools/cgtools/ti-cgt-c6000_8.1.0
  TOOLCHAIN_PATH_EVE ?= /opt/tools/cgtools/arp32_1.0.7
  PDK_INSTALL_PATH ?= /opt/ti/pdk
  BIOS_INSTALL_PATH ?= /opt/tools/bios6/bios_6_46_00_23
  XDC_INSTALL_PATH ?= /opt/tools/xdc/xdctools_3_32_00_06_core
  EDMA3LLD_BIOS6_INSTALLDIR ?= /opt/tools/edma3/edma3_lld_02_12_00_20
  NDK_INSTALL_PATH ?= /opt/tools/ndk/ndk_2_24_03_35
endif

TOOLCHAIN_PATH_A8 ?= $(TOOLCHAIN_PATH_GCC)
TOOLCHAIN_PATH_A9 ?= $(TOOLCHAIN_PATH_GCC)
TOOLCHAIN_PATH_A15 ?= $(TOOLCHAIN_PATH_GCC)
TOOLCHAIN_PATH_M4 ?= $(TOOLCHAIN_PATH_TI_CGT)

ifeq ($(SOC),$(filter $(SOC), am335x))
  FPULIB_PATH ?= $(TOOLCHAIN_PATH_A8)/lib/gcc/arm-none-eabi/4.9.3/fpu
else ifeq  ($(SOC),$(filter $(SOC), am437x))
  FPULIB_PATH ?= $(TOOLCHAIN_PATH_A9)/lib/gcc/arm-none-eabi/4.9.3/fpu
else
  FPULIB_PATH ?= $(TOOLCHAIN_PATH_A15)/lib/gcc/arm-none-eabi/4.9.3/fpu
endif

# Default to m4 build depending on BOARD selected!!
ifeq ($(BOARD),$(filter $(BOARD), evmAM572x idkAM572x idkAM571x ))
  CORE ?= a15_0
endif
CORE ?= ipu1_0

# Default Build Profile
# Supported Values: debug | release
BUILD_PROFILE ?= release

# Set Core Build Profile depending on BUILD_PROFILE value
BUILD_PROFILE_$(CORE) ?= $(BUILD_PROFILE)

# Default PACKAGE_SELECT build flag
# Supported values: all, vps-hal-only, vps-vip-only, vps-vpe-only, vps-dss-only, vps-vip-dss, vps-vip-vpe
PACKAGE_SELECT ?= all

TREAT_WARNINGS_AS_ERROR ?= yes

# Disable recursive building of example dependencies
DISABLE_RECURSE_DEPS ?= no

# Default C++ build flag, yes or no
CPLUSPLUS_BUILD ?= no

#use <module>_PATH variable as makefile internally expects PATH variable this way for external component path
pdk_PATH := $(PDK_INSTALL_PATH)
bios_PATH := $(BIOS_INSTALL_PATH)
xdc_PATH := $(XDC_INSTALL_PATH)
edma3_lld_PATH := $(EDMA3LLD_BIOS6_INSTALLDIR)
ndk_PATH := $(NDK_INSTALL_PATH)

ROOTDIR := $(pdk_PATH)
XDCPATH =
ifeq ($(BUILD_OS_TYPE),tirtos)
  XDCPATH = $(bios_PATH)/packages;$(xdc_PATH)/packages;$(edma3_lld_PATH)/packages;$(ndk_PATH)/packages;$(pdk_PATH);
endif

#Default SECTTI SIZE INFORMATION
SECTTI_SIZE_INFO ?= no

#Default SECTTI tool
SECTI ?= sectti

# Individual component path, needed to build a component in a different location
# as that of PDK
PDK_CSL_ROOT_PATH ?= $(pdk_PATH)
PDK_CSL_COMP_PATH = $(PDK_CSL_ROOT_PATH)/ti/csl
export PDK_CSL_COMP_PATH
PDK_PM_ROOT_PATH ?= $(pdk_PATH)
PDK_PM_COMP_PATH = $(PDK_PM_ROOT_PATH)/ti/drv/pm
export PDK_PM_COMP_PATH
PDK_OSAL_ROOT_PATH ?= $(pdk_PATH)
PDK_OSAL_COMP_PATH = $(PDK_OSAL_ROOT_PATH)/ti/osal
export PDK_OSAL_COMP_PATH
PDK_I2C_ROOT_PATH ?= $(pdk_PATH)
PDK_I2C_COMP_PATH = $(PDK_I2C_ROOT_PATH)/ti/drv/i2c
export PDK_I2C_COMP_PATH
PDK_VPS_ROOT_PATH ?= $(pdk_PATH)
PDK_VPS_COMP_PATH = $(PDK_VPS_ROOT_PATH)/ti/drv/vps
export PDK_VPS_COMP_PATH
PDK_GPIO_ROOT_PATH ?= $(pdk_PATH)
PDK_GPIO_COMP_PATH = $(PDK_GPIO_ROOT_PATH)/ti/drv/gpio
export PDK_GPIO_COMP_PATH
PDK_FATFS_ROOT_PATH ?= $(pdk_PATH)
PDK_FATFS_COMP_PATH = $(PDK_FATFS_ROOT_PATH)/ti/fs/fatfs
export PDK_FATFS_COMP_PATH
PDK_MMCSD_ROOT_PATH ?= $(pdk_PATH)
PDK_MMCSD_COMP_PATH = $(PDK_MMCSD_ROOT_PATH)/ti/drv/mmcsd
export PDK_MMCSD_COMP_PATH
PDK_PCIE_ROOT_PATH ?= $(pdk_PATH)
PDK_PCIE_COMP_PATH = $(PDK_PCIE_ROOT_PATH)/ti/drv/pcie
export PDK_PCIE_COMP_PATH
PDK_USB_ROOT_PATH ?= $(pdk_PATH)
PDK_USB_COMP_PATH = $(PDK_USB_ROOT_PATH)/ti/drv/usb
export PDK_USB_COMP_PATH
PDK_MCASP_ROOT_PATH ?= $(pdk_PATH)
PDK_MCASP_COMP_PATH = $(PDK_MCASP_ROOT_PATH)/ti/drv/mcasp
export PDK_MCASP_COMP_PATH
PDK_PROFILING_ROOT_PATH ?= $(pdk_PATH)
PDK_PROFILING_COMP_PATH = $(PDK_PROFILING_ROOT_PATH)/ti/utils/profiling
export PDK_PROFILING_COMP_PATH
PDK_PRUSS_ROOT_PATH ?= $(pdk_PATH)
PDK_PRUSS_COMP_PATH = $(PDK_PRUSS_ROOT_PATH)/ti/drv/pruss
export PDK_PRUSS_COMP_PATH
PDK_NIMU_ROOT_PATH ?= $(pdk_PATH)
PDK_NIMU_COMP_PATH = $(PDK_NIMU_ROOT_PATH)/ti/transport/ndk/nimu
export PDK_NIMU_COMP_PATH
PDK_NIMU_ICSS_ROOT_PATH ?= $(pdk_PATH)
PDK_NIMU_ICSS_COMP_PATH = $(PDK_NIMU_ICSS_ROOT_PATH)/ti/transport/ndk/nimu_icss
export PDK_NIMU_ICSS_COMP_PATH
PDK_ICSS_EMAC_ROOT_PATH ?= $(pdk_PATH)
PDK_ICSS_EMAC_COMP_PATH = $(PDK_ICSS_EMAC_ROOT_PATH)/ti/drv/icss_emac
export PDK_ICSS_EMAC_COMP_PATH
PDK_EMAC_ROOT_PATH ?= $(pdk_PATH)
PDK_EMAC_COMP_PATH = $(PDK_EMAC_ROOT_PATH)/ti/drv/emac
export PDK_EMAC_COMP_PATH
PDK_UART_ROOT_PATH ?= $(pdk_PATH)
PDK_UART_COMP_PATH = $(PDK_UART_ROOT_PATH)/ti/drv/uart
export PDK_UART_COMP_PATH
PDK_SPI_ROOT_PATH ?= $(pdk_PATH)
PDK_SPI_COMP_PATH = $(PDK_SPI_ROOT_PATH)/ti/drv/spi
export PDK_SPI_COMP_PATH
PDK_BOARD_ROOT_PATH ?= $(pdk_PATH)
PDK_BOARD_COMP_PATH = $(PDK_BOARD_ROOT_PATH)/ti/board
export PDK_BOARD_COMP_PATH
PDK_GPMC_ROOT_PATH ?= $(pdk_PATH)
PDK_GPMC_COMP_PATH = $(PDK_GPMC_ROOT_PATH)/ti/drv/gpmc
export PDK_GPMC_COMP_PATH
PDK_AUDK2G_ROOT_PATH ?= $(pdk_PATH)
PDK_AUDK2G_COMP_PATH = $(PDK_AUDK2G_ROOT_PATH)/ti/addon/audk2g
export PDK_AUDK2G_COMP_PATH
PDK_SBL_ROOT_PATH ?= $(pdk_PATH)
PDK_SBL_COMP_PATH = $(PDK_SBL_ROOT_PATH)/ti/boot/sbl/
export PDK_SBL_COMP_PATH

#Below applicable only for TDA devices
PDK_SAFETY_DIAG_ROOT_PATH ?= $(pdk_PATH)
PDK_SAFETY_DIAG_COMP_PATH = $(PDK_SAFETY_DIAG_ROOT_PATH)/ti/drv/safety/diag
export PDK_SAFETY_DIAG_COMP_PATH
PDK_FIREWALL_ROOT_PATH ?= $(pdk_PATH)
PDK_FIREWALL_COMP_PATH = $(PDK_FIREWALL_ROOT_PATH)/ti/drv/safety/fw
export PDK_FIREWALL_COMP_PATH
PDK_IPC_ROOT_PATH ?= $(pdk_PATH)
PDK_IPC_COMP_PATH = $(PDK_IPC_ROOT_PATH)/ti/drv/safety/ipc
export PDK_IPC_COMP_PATH
PDK_SECURITY_ROOT_PATH ?= $(pdk_PATH)
PDK_SECURITY_COMP_PATH = $(PDK_SECURITY_ROOT_PATH)/ti/drv/security
export PDK_SECURITY_COMP_PATH

#Below applicable only for TDA devices for backward compatibility;not applicable for PRSDK
PDK_NORFLASH_ROOT_PATH ?= $(pdk_PATH)
PDK_NORFLASH_COMP_PATH = $(PDK_NORFLASH_ROOT_PATH)/ti/boot/sbl/norflash
export PDK_NORFLASH_COMP_PATH
PDK_QSPIFLASH_ROOT_PATH ?= $(pdk_PATH)
PDK_QSPIFLASH_COMP_PATH = $(PDK_QSPIFLASH_ROOT_PATH)/ti/boot/sbl/qspiflash
export PDK_QSPIFLASH_COMP_PATH
PDK_STW_LLD_ROOT_PATH ?= $(pdk_PATH)
PDK_STW_LLD_COMP_PATH = $(PDK_STW_LLD_ROOT_PATH)/ti/drv/stw_lld
export PDK_STW_LLD_COMP_PATH
PDK_BSP_LLD_ROOT_PATH ?= $(pdk_PATH)
PDK_BSP_LLD_COMP_PATH = $(PDK_BSP_LLD_ROOT_PATH)/ti/drv/bsp_lld
export PDK_BSP_LLD_COMP_PATH

export OS
export BUILD_OS_TYPE
export BOARD
export SOC
export CORE
export BUILD_PROFILE
export BUILD_PROFILE_$(CORE)
export TOOLCHAIN_PATH_A15
export TOOLCHAIN_PATH_A8
export TOOLCHAIN_PATH_A9
export TOOLCHAIN_PATH_M4
export TOOLCHAIN_PATH_EVE
export FPULIB_PATH
export C6X_GEN_INSTALL_PATH
export PDK_INSTALL_PATH
export bios_PATH
export xdc_PATH
export pdk_PATH
export edma3_lld_PATH
export ndk_PATH
export ROOTDIR
export XDCPATH
export PACKAGE_SELECT
export TREAT_WARNINGS_AS_ERROR
export DISABLE_RECURSE_DEPS
export CPLUSPLUS_BUILD
export SECTTI_SIZE_INFO
export SECTTI

endif

ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(ROOTDIR)/ti/build/makerules
  export MAKERULEDIR
endif

include $(MAKERULEDIR)/build_config.mk
include $(MAKERULEDIR)/platform.mk
include $(MAKERULEDIR)/env.mk
