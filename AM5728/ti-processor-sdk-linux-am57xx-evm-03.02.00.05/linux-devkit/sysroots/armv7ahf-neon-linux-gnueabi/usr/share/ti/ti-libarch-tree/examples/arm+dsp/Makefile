
# Defines
TEST_FAT_BINARY = 1

INCDIR := $(XDC_DIR)/packages;$(BIOS_DIR)/packages;$(XDAIS_DIR)/packages;$(CGTROOT)/include;$(PDK_DIR)/packages;$(FC_DIR)/packages;$(TI_OCL_INSTALL_DIR);$(OMP_DIR)/packages/ti/runtime/openmp;$(LIBARCH_DIR)/packages

INCS = -I. -I$(strip $(subst ;, -I,$(subst $(space),$(space),$(INCDIR))))
OBJS = test_app_arm.o test_lib_arm.o

LD_FLAGS=-L$(TARGET_ROOTDIR)/lib -L$(TARGET_ROOTDIR)/usr/lib -Wl,-rpath-link,$(TARGET_ROOTDIR)/lib -Wl,-rpath-link,$(TARGET_ROOTDIR)/usr/lib

CL6X  = cl6x -mv6600 --abi=eabi
CPP = arm-linux-gnueabihf-g++
LINK_FLAGS = -lOpenCL -locl_util -lstdc++ -lrt -lm -lgomp -lpthread -ldl
CPP_DEBUG   = -g
CPP_FLAGS   = -D_LITTLE_ENDIAN -D__ARMv7 -I$(TARGET_ROOTDIR)/usr/include
CL6X_FLAGS  = $(INCS) --openmp --use_g2 -D$(TARGET) -D$(LIBOS)
ARM_PLUS_DSP_EXE= libarch_test

LIBFW_LIB = $(LIBARCH_DIR)/packages/ti/libarch/lib/libarch.ae66
OCL_BIN = test_lib_ocl.out

ifeq ($(TEST_FAT_BINARY), 1)
  CPP_FLAGS += -DTEST_FAT_BINARY
  OCL_BIN = test_lib_ocl.dsp_h
endif

all: libarch_test
cross: libarch_test

$(ARM_PLUS_DSP_EXE): $(OCL_BIN) $(OBJS)
	@echo; echo "Building hybrid ARM+DSP executable: $(ARM_PLUS_DSP_EXE)"
	$(CPP) $(CPPFLAGS) $(LD_FLAGS) $(OBJS) $(LINK_FLAGS) -o $@

# if we have a fat binary header then the initfini file needs it
test_app_arm.o: test_app_arm.cpp
	@echo Compiling $<
	$(CPP) -c $(CPP_FLAGS) $<

test_lib_arm.o: test_lib_arm.cpp
	@echo Compiling $<
	$(CPP) -c $(CPP_FLAGS) $<

# target for fat binary
test_lib_ocl.dsp_h: test_lib_dsp.obj test_lib_ocl.cl test_dsp_kernel.obj
	@echo; echo Building $@
	@rm -f test_lib_ocl.out
	@echo Building fat binary header
	clocl --txt -g $^ $(LIBFW_LIB)

# target if fat binary not used
test_lib_ocl.out: test_lib_dsp.obj test_lib_ocl.cl test_dsp_kernel.obj
	@echo; echo Building $@
	clocl $^ 

test_dsp_kernel.obj: ../common/test_dsp_kernel.c
	$(CL6X) -c $(CL6X_FLAGS) $<

test_lib_dsp.obj: ./test_lib_dsp.c
	$(CL6X) -c $(CL6X_FLAGS) $<

clean:
	@rm -f $(OBJS) $(OCL_BIN) *.obj *.out
	@rm -f $(ARM_PLUS_DSP_EXE)

%.obj: %.c
	@echo Compiling $<
	$(CL6X) -c $(CL6X_FLAGS) $<
