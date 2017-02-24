#
#  Copyright (c) 2013-2015, Texas Instruments Incorporated
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

# edit PROCLIST list to control how many executables to build
PROCLIST = ipu2 host

EXBASE = .
include $(EXBASE)/products.mak
.PHONY: $(PROCLIST)

.PHONY: install
.PHONY: machvis

all: machvis $(PROCLIST)

machvis:
	$(MAKE) -C machvis all

$(PROCLIST): machvis
	@$(ECHO) "#"
	@$(ECHO) "# Making $@ ..."
	$(MAKE) -C $@ PROCLIST="$(PROCLIST)"

help:
	@$(ECHO) "make                                  # build executables"
	@$(ECHO) "make clean                            # clean everything"
	@$(ECHO) "make install EXEC_DIR=/.../testbench  # install folder"

# setup install goal
EXEC_DIR=$(CURDIR)/install
override EXEC_DIR:=$(EXEC_DIR)/ex12_mmrpc

install: $(PROCLIST) $(addsuffix _install,$(PROCLIST))
$(addsuffix _install,$(PROCLIST)):
	@$(ECHO) "#"
	@$(ECHO) "# Making $@ ..."
	@$(MKDIR) $(EXEC_DIR)/debug
	@$(MKDIR) $(EXEC_DIR)/release
	$(MAKE) -C $(subst _install,,$@) EXEC_DIR=$(EXEC_DIR) install

clean: $(addsuffix _clean,$(PROCLIST))
	$(RMDIR) install
	$(MAKE) -C machvis clean

$(addsuffix _clean,$(PROCLIST)):
	$(MAKE) -C $(subst _clean,,$@) clean

#
#  ======== standard macros ========
#
ifneq (,$(wildcard $(XDC_INSTALL_DIR)/xdc.exe))
    # use these on Windows
    CP      = $(XDC_INSTALL_DIR)/bin/cp
    ECHO    = $(XDC_INSTALL_DIR)/bin/echo
    INSTALL = $(XDC_INSTALL_DIR)/bin/cp
    MKDIR   = $(XDC_INSTALL_DIR)/bin/mkdir -p
    RM      = $(XDC_INSTALL_DIR)/bin/rm -f
    RMDIR   = $(XDC_INSTALL_DIR)/bin/rm -rf
else
    # use these on Linux
    CP      = cp
    ECHO    = echo
    INSTALL = install
    MKDIR   = mkdir -p
    RM      = rm -f
    RMDIR   = rm -rf
endif
