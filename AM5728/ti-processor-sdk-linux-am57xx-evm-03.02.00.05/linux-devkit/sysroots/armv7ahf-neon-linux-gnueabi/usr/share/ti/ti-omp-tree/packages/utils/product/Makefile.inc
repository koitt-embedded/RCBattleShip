##
##  Copyright (c) 2015, Texas Instruments Incorporated
##
##  Redistribution and use in source and binary forms, with or without
##  modification, are permitted provided that the following conditions
##  are met:
##
##  *  Redistributions of source code must retain the above copyright
##     notice, this list of conditions and the following disclaimer.
##
##  *  Redistributions in binary form must reproduce the above copyright
##     notice, this list of conditions and the following disclaimer in the
##     documentation and/or other materials provided with the distribution.
##
##  *  Neither the name of Texas Instruments Incorporated nor the names of
##     its contributors may be used to endorse or promote products derived
##     from this software without specific prior written permission.
##
##  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
##  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
##  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
##  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
##  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
##  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
##  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
##  OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
##  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
##  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
##  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
##
##  ======== Makefile.inc ========
##

# TI C6x CGT
export XDCCGROOT ?= /cgnas/ti-cgt-c6000-8.1.0-release-linux
PSDK_VERSION ?= 03.01.00.06-release

ifeq ($(BUILD_AM572),1)
RTOS_SDK_DIR ?= /cgnas/ti-processor-sdk-rtos-am57xx-evm-$(PSDK_VERSION)
export AM572_PDK_DIR ?= $(wildcard $(RTOS_SDK_DIR)/pdk_am57xx_*)
DEVICE=am57xx
else ifeq ($(BUILD_C6678),1)
RTOS_SDK_DIR ?= /cgnas/ti-processor-sdk-rtos-c667x-evm-$(PSDK_VERSION)
export C6678_PDK_DIR ?= $(wildcard $(RTOS_SDK_DIR)/pdk_c667x_*)
DEVICE=c667x
else ifeq ($(BUILD_C6670),1)
$(call error,ERROR - Processor SDK does not support C6670)
else ifeq ($(BUILD_C6657),1)
RTOS_SDK_DIR ?= /cgnas/ti-processor-sdk-rtos-c665x-evm-$(PSDK_VERSION)
export C6657_PDK_DIR ?= $(wildcard $(RTOS_SDK_DIR)/pdk_c665x_*)
DEVICE=c665x
else ifeq ($(BUILD_K2H),1)
LINUX_SDK_DIR ?= /cgnas/ti-processor-sdk-linux-k2hk-evm-$(PSDK_VERSION)
RTOS_SDK_DIR  ?= /cgnas/ti-processor-sdk-rtos-k2hk-evm-$(PSDK_VERSION)
export C6636_PDK_DIR  ?= $(wildcard $(RTOS_SDK_DIR)/pdk_k2hk_*)
DEVICE=k2x
else ifeq ($(BUILD_K2L),1)
LINUX_SDK_DIR ?= /cgnas/ti-processor-sdk-linux-k2l-evm-$(PSDK_VERSION)
RTOS_SDK_DIR  ?= /cgnas/ti-processor-sdk-rtos-k2l-evm-$(PSDK_VERSION)
export C6636_PDK_DIR  ?= $(wildcard $(RTOS_SDK_DIR)/pdk_k2l_*)
DEVICE=k2x
else ifeq ($(BUILD_K2G),1)
LINUX_SDK_DIR ?= /cgnas/ti-processor-sdk-linux-k2g-evm-$(PSDK_VERSION)
RTOS_SDK_DIR  ?= /cgnas/ti-processor-sdk-rtos-k2g-evm-$(PSDK_VERSION)
export K2G_PDK_DIR  ?= $(wildcard $(RTOS_SDK_DIR)/pdk_k2g_*)
DEVICE=k2g
endif

export BIOS_DIR       ?= $(wildcard $(RTOS_SDK_DIR)/bios_*)
export IPC_DIR        ?= $(wildcard $(RTOS_SDK_DIR)/ipc_*)
export XDC_DIR        ?= $(wildcard $(RTOS_SDK_DIR)/xdctools_*)
