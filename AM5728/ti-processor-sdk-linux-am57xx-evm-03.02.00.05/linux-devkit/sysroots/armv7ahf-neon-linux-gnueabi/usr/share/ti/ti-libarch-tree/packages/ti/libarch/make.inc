DSP_INCLUDE  = -I$(TARGET_ROOTDIR)/usr/share/ti/cgt-c6x/include
DSP_INCLUDE += -I$(TARGET_ROOTDIR)/usr/share/ti/opencl

CPP   = g++
CL6X  = cl6x -mv6600 --abi=eabi $(DSP_INCLUDE)
CLOCL = clocl

LIBS  = -lOpenCL -locl_util #-lstdc++ -lrt 

UNAME_M :=$(shell uname -m)

OBJCOPY = $(TARGET_ROOTDIR)/usr/bin/arm-linux-gnueabihf-objcopy

ifneq (,$(findstring 86, $(UNAME_M)))
    .DEFAULT_GOAL := cross
    OBJCOPY = $(TOOLCHAIN_DIR)/arm-linux-gnueabihf/bin/objcopy

    # In a cross compile environment we are assuming that the EVM file system
    # is located on the build host and necessary ARM libraries are installed
    # on that file system. 
    ifneq ($(MAKECMDGOALS),clean)
       ifeq ($(TARGET_ROOTDIR),)
         $(error Environment variable TARGET_ROOTDIR must be defined. Set it to point at the EVM root file system)
       endif
       ifeq ($(OMP_DIR),)
         $(error Environment variable OMP_DIR must be defined. Set it to point at the OpenMP for DSP Installation Directory, or run the setup_hpc_env script available in the MCSDK-HPC installation)
       endif
    endif

    # gcc ARM cross compiler will not, by default, search the host's
    # /usr/include.  Explicitly specify here to find dependent vendor headers
    cross: override CPP = arm-linux-gnueabihf-g++
    cross: CPP_FLAGS += -I$(TARGET_ROOTDIR)/usr/include -idirafter /usr/include
    #cross: CL6X_FLAGS += -I$(OMP_DIR)/packages/ti/runtime/openmp

    # If cross-compilineg, provide path to dependent ARM libraries on the 
    # target filesystem
    cross: LD_FLAGS = -L$(TARGET_ROOTDIR)/lib -L$(TARGET_ROOTDIR)/usr/lib -Wl,-rpath-link,$(TARGET_ROOTDIR)/lib -Wl,-rpath-link,$(TARGET_ROOTDIR)/usr/lib 
endif

define FIND_DSP_PKG
  export $(1)?=$$(patsubst %/$(3),%,$$(lastword $$(sort $$(wildcard $$(TI_INSTALL_DIR)/$(2)/$(3)))))
  ifeq ($$($(1)),)
    $$(error ERROR - $(1) is not defined and could not be found in $(TI_INSTALL_DIR)/ )
  else
    ifeq ($$(wildcard $$($(1))/$(3)),)
      $$(error ERROR - "$(1) = $$($(1))" Is not valid!)
    endif
  endif
  $$(info Using $(1) = $$($(1)))
endef

ifeq ($(TARGET_OS), TI_RTOS)
  $(eval $(call FIND_DSP_PKG,PDK_DIR,pdk_C6678*,packages))
  DSP_INCLUDE += -I$(PDK_DIR)/packages
endif

%.o: %.cpp
	@echo Compiling $<
	$(CPP) -c $(CPP_FLAGS) $<

%.o: %.c
	@echo Compiling $<
	$(CPP) -c $(CPP_FLAGS) $<

%.obj: %.c
	@echo Compiling $<
	$(CL6X) -c $(CL6X_FLAGS) $<

%.out: %.cl
	@echo Compiling $< 
	@$(CLOCL) $(CLOCL_FLAGS) $^

%.dsp_h: %.cl
	@echo Compiling $< 
	@$(CLOCL) -t $(CLOCL_FLAGS) $^

$(EXE):

cross: $(EXE)

clean::
	@rm -f $(EXE) *.o *.obj *.out *.asm *.if *.opt *.bc *.objc *.map *.bin *.dsp_h

test: clean $(EXE)
	@echo Running   $(EXE)
	@./$(EXE) >> /dev/null
	@if [ $$? -ne 0 ] ; then echo "FAILED !!!" ; fi