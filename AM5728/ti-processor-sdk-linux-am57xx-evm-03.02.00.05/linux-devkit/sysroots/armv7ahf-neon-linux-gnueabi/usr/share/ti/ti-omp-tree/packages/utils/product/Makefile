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
##  ======== Makefile.libs ========
##

# Makefile to build the OpenMP DSP libraries for TCI6636KH, TMS320C6678,
# TMS320C6670 and TMS320C6657

#
# Environment variables that have to be set
#

# Path to C6000 compiler tools
ifeq ($(XDCCGROOT),)
$(call error,ERROR - XDCCGROOT NOT DEFINED)
endif

ifeq ($(XDC_DIR),)
$(call error,ERROR - XDC_DIR NOT DEFINED)
endif

ifeq ($(BUILD_AM572),1)
ifeq ($(AM572_PDK_DIR),)
$(error,ERROR - AM572_PDK_DIR NOT DEFINED)
endif
endif

ifeq ($(BUILD_K2G),1)
ifeq ($(K2G_PDK_DIR),)
$(error,ERROR - K2G_PDK_DIR NOT DEFINED)
endif
endif

ifeq ($(BUILD_C6670), 1)
ifeq ($(C6670_PDK_DIR),)
$(error,ERROR - C6670_PDK_DIR NOT DEFINED)
endif
endif

ifeq ($(BUILD_C6678), 1)
ifeq ($(C6678_PDK_DIR),)
$(error,ERROR - C6678_PDK_DIR NOT DEFINED)
endif
endif

ifeq ($(BUILD_C6657), 1)
ifeq ($(C6657_PDK_DIR),)
$(error,ERROR - C6657_PDK_DIR NOT DEFINED)
endif
endif

ifeq ($(BUILD_K2H), 1)
ifeq ($(C6636_PDK_DIR),)
$(error,ERROR - C6636_PDK_DIR NOT DEFINED)
endif
endif

ifeq ($(SRC_PREFIX),)
SRC_PREFIX=packages
endif

all: 
	$(error must specify one of: \
            BUILD_AM572=1 \
            BUILD_K2G=1 \
            BUILD_K2H=1 \
            BUILD_C6678=1 \
            BUILD_C6670=1 \
            BUILD_C6657=1)
	
clean: .clean_libs

XDC=$(XDC_DIR)/xdc
XS=$(XDC_DIR)/xs
XDCPKG=$(XDC_DIR)/bin/xdcpkg

.clean_libs:
	$(XDC) clean -k -PR $(SRC_PREFIX)

.libs_k2h: .clean_libs openmp_hawking device_hawking .build_rts6000 .build_ompbios .build_argsmain cio_hawking

.libs_am57: .clean_libs openmp_vayu device_vayu .build_rts6000 .build_ompbios .build_argsmain

.libs_k2g: .clean_libs openmp_k2g device_k2g .build_rts6000 .build_ompbios .build_argsmain

.libs_c6678: .clean_libs openmp_shannon device_shannon .build_rts6000 .build_ompbios .build_argsmain

.libs_c6670: .clean_libs openmp_nyquist device_nyquist .build_rts6000 .build_ompbios .build_argsmain

.libs_c6657: .clean_libs openmp_gauss device_gauss .build_rts6000 .build_ompbios .build_argsmain

openmp_vayu:
	cd $(SRC_PREFIX)/ti/runtime/openmp; $(XDC) --xdcpath="$(AM572_PDK_DIR)/packages;$(BIOS_DIR)/packages" lib/ti_runtime_openmp_am57x_debug_e66.ae66
	cd $(SRC_PREFIX)/ti/runtime/openmp; $(XDC) --xdcpath="$(AM572_PDK_DIR)/packages;$(BIOS_DIR)/packages" lib/ti_runtime_openmp_am57x_release_e66.ae66

openmp_k2g:
	cd $(SRC_PREFIX)/ti/runtime/openmp; $(XDC) --xdcpath="$(K2G_PDK_DIR)/packages;$(BIOS_DIR)/packages" lib/ti_runtime_openmp_k2g_debug_e66.ae66
	cd $(SRC_PREFIX)/ti/runtime/openmp; $(XDC) --xdcpath="$(K2G_PDK_DIR)/packages;$(BIOS_DIR)/packages" lib/ti_runtime_openmp_k2g_release_e66.ae66

openmp_shannon:
	cd $(SRC_PREFIX)/ti/runtime/openmp; $(XDC) --xdcpath="$(C6678_PDK_DIR)/packages;$(BIOS_DIR)/packages" lib/ti_runtime_openmp_c6678_debug_e66.ae66
	cd $(SRC_PREFIX)/ti/runtime/openmp; $(XDC) --xdcpath="$(C6678_PDK_DIR)/packages;$(BIOS_DIR)/packages" lib/ti_runtime_openmp_c6678_release_e66.ae66

openmp_nyquist:
	cd $(SRC_PREFIX)/ti/runtime/openmp; $(XDC) --xdcpath="$(C6670_PDK_DIR)/packages;$(BIOS_DIR)/packages" lib/ti_runtime_openmp_c6670_debug_e66.ae66
	cd $(SRC_PREFIX)/ti/runtime/openmp; $(XDC) --xdcpath="$(C6670_PDK_DIR)/packages;$(BIOS_DIR)/packages" lib/ti_runtime_openmp_c6670_release_e66.ae66

openmp_gauss:
	cd $(SRC_PREFIX)/ti/runtime/openmp; $(XDC) --xdcpath="$(C6657_PDK_DIR)/packages;$(BIOS_DIR)/packages" lib/ti_runtime_openmp_c6657_debug_e66.ae66
	cd $(SRC_PREFIX)/ti/runtime/openmp; $(XDC) --xdcpath="$(C6657_PDK_DIR)/packages;$(BIOS_DIR)/packages" lib/ti_runtime_openmp_c6657_release_e66.ae66

openmp_hawking:
	cd $(SRC_PREFIX)/ti/runtime/openmp; $(XDC) --xdcpath="$(C6636_PDK_DIR)/packages;$(BIOS_DIR)/packages" lib/ti_runtime_openmp_c6636_debug_e66.ae66
	cd $(SRC_PREFIX)/ti/runtime/openmp; $(XDC) --xdcpath="$(C6636_PDK_DIR)/packages;$(BIOS_DIR)/packages" lib/ti_runtime_openmp_c6636_release_e66.ae66


.build_device: device_shannon device_nyquist device_gauss device_hawking

device_vayu:
	cd $(SRC_PREFIX)/ti/runtime/device; $(XDC) --xdcpath="$(AM572_PDK_DIR)/packages;$(BIOS_DIR)/packages" lib/ti_runtime_device_am57x_debug_e66.ae66
	cd $(SRC_PREFIX)/ti/runtime/device; $(XDC) --xdcpath="$(AM572_PDK_DIR)/packages;$(BIOS_DIR)/packages" lib/ti_runtime_device_am57x_release_e66.ae66

device_k2g:
	cd $(SRC_PREFIX)/ti/runtime/device; $(XDC) --xdcpath="$(K2G_PDK_DIR)/packages;$(BIOS_DIR)/packages" lib/ti_runtime_device_k2g_debug_e66.ae66
	cd $(SRC_PREFIX)/ti/runtime/device; $(XDC) --xdcpath="$(K2G_PDK_DIR)/packages;$(BIOS_DIR)/packages" lib/ti_runtime_device_k2g_release_e66.ae66

device_shannon:
	cd $(SRC_PREFIX)/ti/runtime/device; $(XDC) --xdcpath="$(C6678_PDK_DIR)/packages;$(BIOS_DIR)/packages" lib/ti_runtime_device_c6678_debug_e66.ae66
	cd $(SRC_PREFIX)/ti/runtime/device; $(XDC) --xdcpath="$(C6678_PDK_DIR)/packages;$(BIOS_DIR)/packages" lib/ti_runtime_device_c6678_release_e66.ae66

device_nyquist:
	cd $(SRC_PREFIX)/ti/runtime/device; $(XDC) --xdcpath="$(C6670_PDK_DIR)/packages;$(BIOS_DIR)/packages" lib/ti_runtime_device_c6670_debug_e66.ae66
	cd $(SRC_PREFIX)/ti/runtime/device; $(XDC) --xdcpath="$(C6670_PDK_DIR)/packages;$(BIOS_DIR)/packages" lib/ti_runtime_device_c6670_release_e66.ae66

device_gauss:
	cd $(SRC_PREFIX)/ti/runtime/device; $(XDC) --xdcpath="$(C6657_PDK_DIR)/packages;$(BIOS_DIR)/packages" lib/ti_runtime_device_c6657_debug_e66.ae66
	cd $(SRC_PREFIX)/ti/runtime/device; $(XDC) --xdcpath="$(C6657_PDK_DIR)/packages;$(BIOS_DIR)/packages" lib/ti_runtime_device_c6657_release_e66.ae66

device_hawking:
	cd $(SRC_PREFIX)/ti/runtime/device; $(XDC) --xdcpath="$(C6636_PDK_DIR)/packages;$(BIOS_DIR)/packages" lib/ti_runtime_device_c6636_debug_e66.ae66
	cd $(SRC_PREFIX)/ti/runtime/device; $(XDC) --xdcpath="$(C6636_PDK_DIR)/packages;$(BIOS_DIR)/packages" lib/ti_runtime_device_c6636_release_e66.ae66

cio_hawking:
	cd $(SRC_PREFIX)/ti/runtime/cio; $(XDC) --xdcpath="$(C6636_PDK_DIR)/packages;$(BIOS_DIR)/packages" lib/ti_runtime_cio_c6636_debug_e66.ae66
	cd $(SRC_PREFIX)/ti/runtime/cio; $(XDC) --xdcpath="$(C6636_PDK_DIR)/packages;$(BIOS_DIR)/packages" lib/ti_runtime_cio_c6636_release_e66.ae66


# Build of rts functionality (_c_int00) is not device specific
.build_rts6000: 
	cd $(SRC_PREFIX)/ti/runtime/rts6000; $(XDC) --xdcpath="$(BIOS_DIR)/packages" lib/ti_runtime_rts6000_debug_e66.ae66
	cd $(SRC_PREFIX)/ti/runtime/rts6000; $(XDC) --xdcpath="$(BIOS_DIR)/packages" lib/ti_runtime_rts6000_release_e66.ae66

.build_ompbios: 
	cd $(SRC_PREFIX)/ti/runtime/ompbios; $(XDC) --xdcpath="$(IPC_DIR)/packages;$(BIOS_DIR)/packages" lib/ti_runtime_ompbios_debug_e66.ae66
	cd $(SRC_PREFIX)/ti/runtime/ompbios; $(XDC) --xdcpath="$(IPC_DIR)/packages;$(BIOS_DIR)/packages" lib/ti_runtime_ompbios_release_e66.ae66


.build_argsmain: 
	cd $(SRC_PREFIX)/ti/runtime/argsmain; $(XDC) --xdcpath="$(BIOS_DIR)/packages" lib/ti_runtime_argsmain_debug_e66.ae66
	cd $(SRC_PREFIX)/ti/runtime/argsmain; $(XDC) --xdcpath="$(BIOS_DIR)/packages" lib/ti_runtime_argsmain_release_e66.ae66

.platforms:
	@echo "making platform directories ..."
	$(XDC) clean --xdcpath="$(BIOS_DIR)/packages" -PR $(SRC_PREFIX)/ti/runtime/openmp/platforms
	$(XDC) --xdcpath="$(BIOS_DIR)/packages" -PR $(SRC_PREFIX)/ti/runtime/openmp/platforms

.env:
	@echo XDCCGROOT    =$(XDCCGROOT)
	@echo BIOS_DIR     =$(BIOS_DIR)
	@echo XDC_DIR      =$(XDC_DIR)
	@echo IPC_DIR      =$(IPC_DIR)
	@echo C6636_PDK_DIR=$(C6636_PDK_DIR)
	@echo ULM_DIR      =$(ULM_DIR)
	@echo C6678_PDK_DIR=$(C6678_PDK_DIR)
	@echo C6657_PDK_DIR=$(C6657_PDK_DIR)
	@echo AM572_PDK_DIR=$(AM572_PDK_DIR)
