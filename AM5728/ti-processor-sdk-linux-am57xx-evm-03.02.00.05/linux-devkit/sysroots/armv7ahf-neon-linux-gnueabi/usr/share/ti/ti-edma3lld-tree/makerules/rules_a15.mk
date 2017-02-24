# Filename: rules_a15.mk
#
# Make rules for A15 - This file has all the common rules and defines required
#                     for Cortex-A15 ISA
#
# This file needs to change when:
#     1. Code generation tool chain changes (This file uses Code Sourcery)
#     2. Internal switches (which are normally not touched) has to change
#     3. XDC specific switches change
#     4. a rule common for A15 ISA has to be added or modified

# Set compiler/archiver/linker commands and include paths
CODEGEN_INCLUDE = $(CODEGEN_PATH_A15)/arm-none-eabi/include
CC = $(CODEGEN_PATH_A15)/bin/arm-none-eabi-gcc 
AR = $(CODEGEN_PATH_A15)/bin/arm-none-eabi-ar
#LNK = $(CODEGEN_PATH_A15)/bin/arm-none-eabi-ld
LNK = $(CODEGEN_PATH_A15)/bin/arm-none-eabi-gcc

# XDC Specific defines
ifneq ($(XDC_CFG_FILE_$(CORE)),)
  ifeq ($(PROFILE_$(CORE)),debug)
#    CFG_CFILENAMEPART_XDC =p$(FORMAT_EXT)a15f
    CFG_CFILENAMEPART_XDC =pa15fg
  endif
  ifeq ($(PROFILE_$(CORE)),release)
#    CFG_CFILENAMEPART_XDC =p$(FORMAT_EXT)a15f
    CFG_CFILENAMEPART_XDC =pa15fg
  endif
  ifeq ($(PROFILE_$(CORE)),whole_program_debug)
    CFG_CFILENAMEPART_XDC =p$(FORMAT_EXT)a15f$(ENDIAN_EXT)
    CFG_LNKFILENAMEPART_XDC=_x
  endif
  CFG_CFILE_XDC =$(patsubst %.cfg,%_$(CFG_CFILENAMEPART_XDC).c,$(notdir $(XDC_CFG_FILE_$(CORE))))
  CFG_C_XDC = $(addprefix $(CONFIGURO_DIR)/package/cfg/,$(CFG_CFILE_XDC))
  XDCLNKCMD_FILE =$(patsubst %.c, %$(CFG_LNKFILENAMEPART_XDC)_x.xdl, $(CFG_C_XDC))
# CFG_COBJ_XDC = $(patsubst %.c,%.$(OBJEXT),$(CFG_CFILE_XDC))
  CFG_COBJ_XDC = $(patsubst %.c,%.oa15fg,$(CFG_CFILE_XDC))
#  OBJ_PATHS += $(CFG_COBJ_XDC)
  LNKCMD_FILE = $(CONFIGURO_DIR)/linker.cmd
  SPACE := 
  SPACE += 
  XDC_GREP_STRING = $(CONFIGURO_DIRNAME)
#  XDC_GREP_STRING = $(subst $(SPACE),\|,$(COMP_LIST_$(CORE)))
#  XDC_GREP_STRING += \|$(CONFIGURO_DIRNAME)
endif
# Internal CFLAGS - normally doesn't change
CFLAGS_INTERNAL = -Wall -Wunknown-pragmas -c -mcpu=cortex-a15 -g -mfpu=neon -mfloat-abi=hard -mabi=aapcs -mapcs-frame  -Wswitch
#-ffunction-sections -fdata-sections
CFLAGS_DIROPTS =

LNKFLAGS_INTERNAL = -nostartfiles -static -Wl,--gc-sections -mfloat-abi=hard

# CFLAGS based on profile selected
CFLAGS_XDCINTERNAL = -Dxdc_target_name__=A15F -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_cfg__header__='$(CONFIGURO_DIR)/package/cfg/$(XDC_CFG_BASE_FILE_NAME)_xem3.h'
# Following 'if...' block is for an application; to add a #define for each
#   component in the build. This is required to know - at compile time - which
#   components are on which core.
ifndef MODULE_NAME
  # Derive list of all packages from each of the components needed by the app
  PKG_LIST_LOCAL = $(foreach COMP,$(COMP_LIST_$(CORE)),$($(COMP)_PKG_LIST))
  
  # Defines for the app and cfg source code to know which components/packages
  # are included in the build for the local CORE...
  CFLAGS_APP_DEFINES = $(foreach PKG,$(PKG_LIST_LOCAL),-D_LOCAL_$(PKG)_)
  CFLAGS_APP_DEFINES += $(foreach PKG,$(PKG_LIST_LOCAL),-D_BUILD_$(PKG)_)
  
  ifeq ($(CORE),a15host)
    PKG_LIST_REMOTE = $(foreach COMP,$(COMP_LIST_a15host),$($(COMP)_PKG_LIST))
    CFLAGS_APP_DEFINES += -D_LOCAL_CORE_a15host_
  endif

  # Defines for the app and cfg source code to know which components/packages
  # are included in the build for the remote CORE...
  CFLAGS_APP_DEFINES += $(foreach PKG,$(PKG_LIST_REMOTE),-D_REMOTE_$(PKG)_)
  CFLAGS_APP_DEFINES += $(foreach PKG,$(PKG_LIST_REMOTE),-D_BUILD_$(PKG)_)
endif
ifeq ($(PROFILE_$(CORE)), debug)
CFLAGS_INTERNAL += -D_DEBUG_=1
endif
ifeq ($(PROFILE_$(CORE)), release)
  CFLAGS_INTERNAL += -O2 -s -DNDEBUG
  LNKFLAGS_INTERNAL_PROFILE = -O2
endif

# Assemble CFLAGS from all other CFLAGS definitions
_CFLAGS = $(CFLAGS_INTERNAL) $(CFLAGS_XDCINTERNAL) $(CFLAGS_GLOBAL_$(CORE)) $(CFLAGS_LOCAL_COMMON) $(CFLAGS_LOCAL_$(CORE)) $(CFLAGS_LOCAL_$(PLATFORM)) $(CFLAGS_LOCAL_$(SOC)) $(CFLAGS_APP_DEFINES) $(CFLAGS_COMP_COMMON) $(CFLAGS_GLOBAL_$(PLATFORM))

# Object file creation
# The second $(CC) compiles the source to generate object
$(OBJ_PATHS): $(OBJDIR)/%.$(OBJEXT): %.c
	$(ECHO) \# Compiling $(PLATFORM):$(CORE):$(PROFILE_$(CORE)):$(APP_NAME)$(MODULE_NAME): $<
	$(CC) -c -MD -MF $@.dep $(_CFLAGS) $(INCLUDES) -o $(OBJDIR)/$(basename $(notdir $<)).$(OBJEXT) $<

ASMFLAGS =
# Object file creation
$(OBJ_PATHS_ASM): $(OBJDIR)/%.$(OBJEXT): %.asm
	$(ECHO) \# Compiling $(PLATFORM):$(CORE):$(PROFILE_$(CORE)):$(APP_NAME)$(MODULE_NAME): $<
	$(CC) -c -x assembler-with-cpp $(_CFLAGS) $(ASMFLAGS) $(INCLUDES) -o $(OBJDIR)/$(basename $(notdir $<)).$(OBJEXT) $<

$(PACKAGE_PATHS): $(PACKAGEDIR)/%: %
	$(ECHO) \# Copying $(PACKAGE_NAME)/$($(MODULE_NAME)_RELPATH)/$<
	$(MKDIR) -p $(DEST_ROOT)/package/$(PACKAGE_SELECT)/$(PACKAGE_NAME)/$($(MODULE_NAME)_RELPATH)
	$(CP) --parents -rf $< $(DEST_ROOT)/package/$(PACKAGE_SELECT)/$(PACKAGE_NAME)/$($(MODULE_NAME)_RELPATH)

# Archive flags - normally doesn't change
ARFLAGS = cr

# Archive/library file creation
$(LIBDIR)/$(MODULE_NAME).$(LIBEXT) : $(OBJ_PATHS_ASM) $(OBJ_PATHS)
	$(ECHO) \#
	$(ECHO) \# Archiving $(PLATFORM):$(CORE):$(PROFILE_$(CORE)):$(MODULE_NAME)
	$(ECHO) \#
	$(AR) $(ARFLAGS) $@ $(OBJ_PATHS_ASM) $(OBJ_PATHS)

# Linker options and rules
LNKFLAGS_INTERNAL_COMMON =

# Assemble Linker flags from all other LNKFLAGS definitions
_LNKFLAGS = $(LNKFLAGS_INTERNAL) $(LNKFLAGS_INTERNAL_COMMON) $(LNKFLAGS_INTERNAL_PROFILE) $(LNKFLAGS_GLOBAL_$(CORE)) $(LNKFLAGS_LOCAL_COMMON) $(LNKFLAGS_LOCAL_$(CORE))

# Path of the RTS library - normally doesn't change for a given tool-chain
RTSLIB_PATH =
BIOS_RUNTIME_PATH = $(bios_PATH)/packages/gnu/targets/arm/libs/install-native/arm-none-eabi/lib/fpu
LIB_PATHS += $(BIOS_RUNTIME_PATH)/libc.a $(BIOS_RUNTIME_PATH)/libm.a $(BIOS_RUNTIME_PATH)/librdimon.a $(BIOS_RUNTIME_PATH)/libg.a


LNK_LIBS = $(addprefix -l,$(LIB_PATHS))
# Linker - to create executable file

ifeq ($(LOCAL_APP_NAME),)
 EXE_NAME = $(BINDIR)/$(APP_NAME)_$(CORE)_$(PROFILE_$(CORE)).$(EXEEXT)
else
 ifeq ($(PROFILE_$(CORE)),prod_release)
  EXE_NAME = $(BINDIR)/$(LOCAL_APP_NAME).$(EXEEXT)
 else
  EXE_NAME = $(BINDIR)/$(LOCAL_APP_NAME)_$(PROFILE_$(CORE)).$(EXEEXT)
 endif
endif

$(EXE_NAME) : $(OBJ_PATHS_ASM) $(OBJ_PATHS) $(LIB_PATHS) $(LNKCMD_FILE)  $(CONFIGURO_DIR)/package/cfg/$(CFG_COBJ_XDC)
	$(ECHO) \# Linking into $(EXE_NAME)...
	$(ECHO) \#
	$(LNK) $(_LNKFLAGS) $(OBJ_PATHS_ASM) $(OBJ_PATHS) -Wl,-T,$(LNKCMD_FILE) -Wl,-Map,$@.map $(LIB_PATHS) -o $@
	$(ECHO) \#
	$(ECHO) \# $@ created.
	$(ECHO) \#

ifeq ($(CONFIG_BLD_XDC_CUSTOM),)
  CONFIG_BLD_FILE = $(CONFIG_BLD_XDC_$(ISA))
else
  CONFIG_BLD_FILE = $(CONFIG_BLD_XDC_CUSTOM)
endif
ifeq ($(PLATFORM_XDC_CUSTOM),)
  PLATFORM_XDC_NAME = $(PLATFORM_XDC)
else
  PLATFORM_XDC_NAME = $(PLATFORM_XDC_CUSTOM)
endif

# XDC specific - assemble XDC-Configuro command
CONFIGURO_CMD = $(xdc_PATH)/xs xdc.tools.configuro -o $(CONFIGURO_DIR) -t $(TARGET_XDC) -p "$(PLATFORM_XDC_NAME)" \
               -r $(PROFILE_$(CORE)) -c $(CODEGEN_PATH_A15) -b $(CONFIG_BLD_FILE) $(XDC_CFG_FILE_NAME)
_XDC_GREP_STRING = \"$(XDC_GREP_STRING)\"
EGREP_CMD = $(EGREP) -ivw $(XDC_GREP_STRING) $(XDCLNKCMD_FILE)

ifneq ($(DEST_ROOT),)
 DEST_ROOT += /
endif
# Invoke configuro for the rest of the components
#  NOTE: 1. String handling is having issues with various make versions when the 
#           cammand is directly tried to be given below. Hence, as a work-around, 
#           the command is re-directed to a file (shell or batch file) and then 
#           executed
#        2. The linker.cmd file generated, includes the libraries generated by
#           XDC. An egrep to search for these and omit in the .cmd file is added
#           after configuro is done
#$(CFG_CFILE_XDC) : $(XDC_CFG_FILE)
xdc_configuro : $(XDC_CFG_FILE)
	$(ECHO) \# Invoking configuro...
	$(ECHO) -e $(CONFIGURO_CMD) > $(DEST_ROOT)maketemp_configuro_cmd_$(CORE).bat
ifeq ($(OS),Windows_NT)
	CACLS $(DEST_ROOT)maketemp_configuro_cmd_$(CORE).bat /E /P Everyone:F
	$(DEST_ROOT)maketemp_configuro_cmd_$(CORE).bat
else
	$(CHMOD) a+x $(DEST_ROOT)maketemp_configuro_cmd_$(CORE).bat
	./$(DEST_ROOT)maketemp_configuro_cmd_$(CORE).bat
endif
#	$(CP) $(XDCLNKCMD_FILE) $(LNKCMD_FILE)
#	$(ECHO) @ $(EGREP_CMD) > maketemp_egrep_cmd.bat
#	./maketemp_egrep_cmd.bat | $(CYGWINPATH)/bin/tail -n+3 > $(LNKCMD_FILE)
#	$(EGREP_CMD) > $(LNKCMD_FILE)
#	$(EGREP) -iv "$(XDC_GREP_STRING)" $(XDCLNKCMD_FILE) > $(LNKCMD_FILE)
	$(ECHO) \# Configuro done!

$(LNKCMD_FILE) :
#	$(CP) $(XDCLNKCMD_FILE) $(LNKCMD_FILE)
#	$(ECHO) @ $(EGREP_CMD) > maketemp_egrep_cmd.bat
#	./maketemp_egrep_cmd.bat | $(CYGWINPATH)/bin/tail -n+3 > $(LNKCMD_FILE)
#	$(EGREP_CMD) > $(LNKCMD_FILE)
 
# Include dependency make files that were generated by $(CC)
-include $(SRCS:%.c=$(DEPDIR)/%.P)
# Nothing beyond this point
