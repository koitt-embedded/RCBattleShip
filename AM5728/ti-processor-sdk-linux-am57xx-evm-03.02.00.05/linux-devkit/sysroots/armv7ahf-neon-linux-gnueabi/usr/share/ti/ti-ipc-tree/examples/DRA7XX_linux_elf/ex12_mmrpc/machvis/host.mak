#
#  Copyright (c) 2013-2014, Texas Instruments Incorporated
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
#  ======== host.mak ========
#


EXBASE = ..
include $(EXBASE)/products.mak
-include $(addprefix lib/$(PROFILE)/obj/,$(patsubst %.c,%.ov7A.dep,$(srcs)))

srcs = MachVis.c
objs = $(addprefix lib/$(PROFILE)/obj/,$(patsubst %.c,%.ov7A,$(srcs)))

PKGPATH := $(IPC_INSTALL_DIR)/packages

all:
	@$(ECHO) "#"
	@$(ECHO) "# Making $@ ..."
	$(MAKE) -f host.mak PROFILE=debug machvis.a
	$(MAKE) -f host.mak PROFILE=release machvis.a

help:
	@$(ECHO) "make                  # build library"
	@$(ECHO) "make clean            # clean everything"

clean::
	$(RMDIR) lib

#
#  ======== rules ========
#
machvis.a: lib/$(PROFILE)/machvis.av7A
lib/$(PROFILE)/machvis.av7A: $(objs)
	@$(ECHO) "#"
	@$(ECHO) "# Making $@ ..."
	$(AR) $@ $^

lib/$(PROFILE)/obj/%.ov7A: %.c
	@$(ECHO) "#"
	@$(ECHO) "# Making $@ ..."
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $<

#  ======== toolchain macros ========
CC = $(TOOLCHAIN_PREFIX)gcc -c -MD -MF $@.dep
AR = $(TOOLCHAIN_PREFIX)ar cr

CPPFLAGS = -D_REENTRANT

CFLAGS = -Wall -ffloat-store -fPIC -Wunused -Dfar= $(CCPROFILE_$(PROFILE)) \
    -I. $(addprefix -I,$(subst +, ,$(PKGPATH)))

CCPROFILE_debug = -ggdb -D DEBUG
CCPROFILE_release = -O3 -D NDEBUG

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
ifeq (,$(wildcard lib/$(PROFILE)/obj))
    $(shell $(MKDIR) -p lib/$(PROFILE)/obj)
endif
endif
endif
