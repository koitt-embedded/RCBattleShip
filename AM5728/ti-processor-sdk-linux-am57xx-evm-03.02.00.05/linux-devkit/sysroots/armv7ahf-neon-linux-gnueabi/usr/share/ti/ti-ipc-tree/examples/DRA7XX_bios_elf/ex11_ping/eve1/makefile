#
#  Copyright (c) 2012-2015 Texas Instruments Incorporated - http://www.ti.com
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

srcs = MainEve1.c SvrEve1.c AppEve1.c
objs = $(addprefix bin/$(PROFILE)/obj/,$(patsubst %.c,%.oearp32F,$(srcs)))
libs =
CONFIG = bin/$(PROFILE)/configuro

-include $(addprefix bin/$(PROFILE)/obj/,$(patsubst %.c,%.oearp32F.dep,$(srcs)))

.PRECIOUS: %/compiler.opt %/linker.cmd

all:
	$(MAKE) PROFILE=debug PROCLIST="$(PROCLIST)" server_eve1.x
#	$(MAKE) PROFILE=release PROCLIST="$(PROCLIST)" server_eve1.x

server_eve1.x: bin/$(PROFILE)/server_eve1.xearp32F
bin/$(PROFILE)/server_eve1.xearp32F: $(objs) $(libs) $(CONFIG)/linker.cmd
	@$(ECHO) "#"
	@$(ECHO) "# Making $@ ..."
	$(LD) $(LDFLAGS) -o $@ $^ $(LDLIBS)

bin/$(PROFILE)/obj/%.oearp32F: %.c $(CONFIG)/compiler.opt
	@$(ECHO) "#"
	@$(ECHO) "# Making $@ ..."
	$(CC) $(CPPFLAGS) $(CFLAGS) --output_file=$@ -fc $<

%/compiler.opt: %/linker.cmd ;
%/linker.cmd: Eve1.cfg ../shared/config.bld
	@$(ECHO) "#"
	@$(ECHO) "# Making $@ ..."
	$(XDC_INSTALL_DIR)/xs --xdcpath="$(subst +,;,$(PKGPATH))" \
            xdc.tools.configuro -o $(CONFIG) \
            -t ti.targets.arp32.elf.ARP32_far \
            -c $(ti.targets.arp32.elf.ARP32_far) \
            -p ti.platforms.evmDRA7XX:eve1 \
            -b ../shared/config.bld -r release \
            --cfgArgs "{ \
                procList: \"$(PROCLIST)\", \
                profile: \"$(PROFILE)\" \
            }" Eve1.cfg

install:
	@$(ECHO) "#"
	@$(ECHO) "# Making $@ ..."
	@$(MKDIR) $(EXEC_DIR)/debug
	$(CP) bin/debug/server_eve1.xearp32F $(EXEC_DIR)/debug
	$(CP) ex11_ping_eve1.gel $(EXEC_DIR)/debug
	@$(MKDIR) $(EXEC_DIR)/release
	$(CP) bin/release/server_eve1.xearp32F $(EXEC_DIR)/release
	$(CP) ex11_ping_eve1.gel $(EXEC_DIR)/release

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
CGTOOLS = $(ti.targets.arp32.elf.ARP32_far)

CC = $(CGTOOLS)/bin/cl-arp32 -c
LD = $(CGTOOLS)/bin/cl-arp32 -z

CPPFLAGS =
CFLAGS = -qq -pdsw225 -ppd=$@.dep -ppa $(CCPROFILE_$(PROFILE)) -@$(CONFIG)/compiler.opt -I.

LDFLAGS = -w -q -c -m $(@D)/obj/$(@F).map
LDLIBS = -l $(CGTOOLS)/lib/libc.a

CCPROFILE_debug = -D_DEBUG_=1 --symdebug:dwarf
CCPROFILE_release = -O2

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
ifeq (,$(wildcard bin/$(PROFILE)/obj))
    $(shell $(MKDIR) -p bin/$(PROFILE)/obj)
endif
endif
endif
