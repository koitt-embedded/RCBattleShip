#
#  Copyright (c) 2013, Texas Instruments Incorporated
#  All rights reserved.
#
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions
#  are met:
#
#  *  Redistributions of source code must retain the above copyright
#     notice, this list of conditions and the following disclaimer.
#
#  *  Redistributions in binary form must reproduce the above copyright
#     notice, this list of conditions and the following disclaimer in the
#     documentation and/or other materials provided with the distribution.
#
#  *  Neither the name of Texas Instruments Incorporated nor the names of
#     its contributors may be used to endorse or promote products derived
#     from this software without specific prior written permission.
#
#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
#  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
#  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
#  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
#  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
#  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
#  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
#  OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
#  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
#  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
#  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#

#
#  ======== ipu.mak ========
#

EXBASE = ..
include $(EXBASE)/products.mak

srcs = MachVis_skel.c MachVis_ipu.c
objs = $(addprefix lib/$(PROFILE)/obj/,$(patsubst %.c,%.oem4,$(srcs)))

PKGPATH := $(BIOS_INSTALL_DIR)/packages
PKGPATH := $(PKGPATH)+$(IPC_INSTALL_DIR)/packages
PKGPATH := $(PKGPATH)+$(XDC_INSTALL_DIR)/packages

-include $(addprefix bin/$(PROFILE)/obj/,$(patsubst %.c,%.oem4.dep,$(srcs)))

all:
	@$(ECHO) "#"
	@$(ECHO) "# Making $@ ..."
	$(MAKE) -f ipu.mak PROFILE=debug libmachvis_ipu.a
	$(MAKE) -f ipu.mak PROFILE=release libmachvis_ipu.a

clean::
	$(RMDIR) lib

libmachvis_ipu.a: lib/$(PROFILE)/libmachvis_ipu.aem4
lib/$(PROFILE)/libmachvis_ipu.aem4: $(objs)
	@$(ECHO) "#"
	@$(ECHO) "# Making $@ ..."
	$(AR) $@ $^

lib/$(PROFILE)/obj/%.oem4: %.h
lib/$(PROFILE)/obj/%.oem4: %.c
	@$(ECHO) "#"
	@$(ECHO) "# Making $@ ..."
	$(CC) $(CPPFLAGS) $(CFLAGS) --output_file=$@ -fc $<

#  ======== toolchain macros ========
CGTOOLS = $(ti.targets.arm.elf.M4)

CC = $(CGTOOLS)/bin/armcl -c --endian=little -mv7M4 --float_support=vfplib \
        --abi=eabi
AR = $(CGTOOLS)/bin/armar rq

CPPFLAGS = -Dxdc_target_types__="ti/targets/arm/elf/std.h" \
        -Dxdc_target_name__=M4
CFLAGS = -qq -pdsw225 -ppd=$@.dep -ppa $(CCPROFILE_$(PROFILE)) -I. \
    $(addprefix -I,$(subst +, ,$(PKGPATH))) -I$(CGTOOLS)/include

CCPROFILE_debug = -D_DEBUG_=1 --symdebug:dwarf
CCPROFILE_release = -O2 -Dxdc_runtime_Log_DISABLE_ALL \
    -Dxdc_runtime_Assert_DISABLE_ALL

#  ======== standard macros ========
ifneq (,$(wildcard $(XDC_INSTALL_DIR)/xdc.exe))
    # use these on Windows
    CP      = $(XDC_INSTALL_DIR)/bin/cp
    ECHO    = $(XDC_INSTALL_DIR)/bin/echo
    MKDIR   = $(XDC_INSTALL_DIR)/bin/mkdir -p
    RM      = $(XDC_INSTALL_DIR)/bin/rm -f
    RMDIR   = $(XDC_INSTALL_DIR)/bin/rm -rf
else
    # use these on Linux
    CP      = cp
    ECHO    = echo
    MKDIR   = mkdir -p
    RM      = rm -f
    RMDIR   = rm -rf
endif

#  ======== create output directories ========
ifneq (clean,$(MAKECMDGOALS))
ifneq (,$(PROFILE))
ifeq (,$(wildcard lib/$(PROFILE)/obj))
    $(shell $(MKDIR) -p lib/$(PROFILE)/obj)
endif
endif
endif
