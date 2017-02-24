#
#  Copyright (c) 2012-2014 Texas Instruments Incorporated - http://www.ti.com
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
#  ======== makefile ========
#

EXBASE = ..
include $(EXBASE)/products.mak

srcs = HelloHost.c
objs = $(addprefix bin/$(PROFILE)/obj/,$(patsubst %.c,%.oa15fg,$(srcs)))
CONFIG = bin/$(PROFILE)/configuro

-include $(addprefix bin/$(PROFILE)/obj/,$(patsubst %.c,%.oa15fg.dep,$(srcs)))

.PRECIOUS: %/compiler.opt %/linker.cmd

all:
	$(MAKE) PROFILE=debug hello_host.x
#	$(MAKE) PROFILE=release hello_host.x

hello_host.x: bin/$(PROFILE)/hello_host.xa15fg
bin/$(PROFILE)/hello_host.xa15fg: $(objs) $(libs) $(CONFIG)/linker.cmd
	@$(ECHO) "#"
	@$(ECHO) "# Making $@ ..."
	$(LD) -o $@ $(LDFLAGS) $(objs) $(libs) -Wl,-T,$(CONFIG)/linker.cmd \
		-lgcc -lc -lm -lnosys $(LDLIBS)

bin/$(PROFILE)/obj/%.oa15fg: %.c $(CONFIG)/compiler.opt
	@$(ECHO) "#"
	@$(ECHO) "# Making $@ ..."
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $<

%/compiler.opt: %/linker.cmd ;
%/linker.cmd: Host.cfg ../shared/config.bld
	@$(ECHO) "#"
	@$(ECHO) "# Making $@ ..."
	$(XDC_INSTALL_DIR)/xs --xdcpath="$(subst +,;,$(PKGPATH))" \
            xdc.tools.configuro -o $(CONFIG) \
            -t gnu.targets.arm.A15F \
            -c $(gnu.targets.arm.A15F) \
            -p ti.platforms.evmDRA7XX:host \
            -b ../shared/config.bld -r release \
            --cfgArgs "{ \
                profile: \"$(PROFILE)\" \
            }" Host.cfg

install:
	@$(ECHO) "#"
	@$(ECHO) "# Making $@ ..."
	@$(MKDIR) $(EXEC_DIR)/debug
	$(CP) bin/debug/hello_host.xa15fg $(EXEC_DIR)/debug
	@$(MKDIR) $(EXEC_DIR)/release
	$(CP) bin/release/hello_host.xa15fg $(EXEC_DIR)/release

help:
	@$(ECHO) "make                   # build executable"
	@$(ECHO) "make clean             # clean everything"

clean::
	$(RMDIR) bin

PKGPATH := $(BIOS_INSTALL_DIR)/packages
PKGPATH := $(PKGPATH)+$(IPC_INSTALL_DIR)/packages
PKGPATH := $(PKGPATH)+$(XDC_INSTALL_DIR)/packages

#  ======== install validation ========
ifeq (install,$(MAKECMDGOALS))
ifeq (,$(EXEC_DIR))
$(error must specify EXEC_DIR)
endif
endif

#  ======== toolchain macros ========
CC = $(gnu.targets.arm.A15F)/bin/arm-none-eabi-gcc -c -MD -MF $@.dep
LD = $(gnu.targets.arm.A15F)/bin/arm-none-eabi-gcc

CPPFLAGS = -Dfar= -D__DYNAMIC_REENT__
CFLAGS = -Wall -Wunused -Wunknown-pragmas -ffunction-sections -fdata-sections $(CCPROFILE_$(PROFILE)) @$(CONFIG)/compiler.opt -I.

LDFLAGS = $(LDPROFILE_$(PROFILE)) -mfloat-abi=hard -nostartfiles -Wl,-static -Wl,--gc-sections -Wl,-Map=$(@D)/obj/$(@F).map
LDLIBS = -L$(XDC_INSTALL_DIR)/packages/gnu/targets/arm/libs/install-native/arm-none-eabi/lib/fpu

CCPROFILE_debug = -g -ggdb -D_DEBUG_=1
CCPROFILE_release = -O2

LDPROFILE_debug = -g -ggdb
LDPROFILE_release =

#  ======== standard macros ========
ifneq (,$(wildcard $(XDC_INSTALL_DIR)/bin/echo.exe))
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
ifeq (,$(wildcard bin/$(PROFILE)/obj))
    $(shell $(MKDIR) -p bin/$(PROFILE)/obj)
endif
endif
endif
