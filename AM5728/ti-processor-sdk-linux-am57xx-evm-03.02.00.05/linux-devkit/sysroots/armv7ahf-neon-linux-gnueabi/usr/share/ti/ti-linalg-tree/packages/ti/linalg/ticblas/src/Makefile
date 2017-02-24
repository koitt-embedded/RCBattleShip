
include ../../make.inc

INCDIR := $(CGTROOT)/include
INCDIR += -I$(OMP_DIR)/packages/ti/runtime/openmp
INCDIR += -I$(FC_DIR)/packages
INCDIR += -I$(XDC_DIR)/packages
INCDIR += -I$(BIOS_DIR)/packages
INCDIR += -I$(XDAIS_DIR)/packages
INCDIR += -I$(LIBARCH_DIR)/packages
INCDIR += -I$(PDK_DIR)/packages

ifeq ($(LIBOS),LIB_OPENCL)
INCDIR += -I$(TI_OCL_INSTALL_DIR)
endif

ifeq ($(MEM_MODEL),Large)
BLIS_INC = ../../blis/install/c66xLarge/include/blis/
BLIS_MEM_MODEL = MEM_MODEL_LARGE
else ifeq ($(MEM_MODEL),Medium)
BLIS_INC = ../../blis/install/c66xMedium/include/blis/
BLIS_MEM_MODEL = MEM_MODEL_MEDIUM
else ifeq ($(MEM_MODEL),Small)
BLIS_INC = ../../blis/install/c66xSmall/include/blis/
BLIS_MEM_MODEL = MEM_MODEL_SMALL
else ifeq ($(MEM_MODEL),Tiny)
BLIS_INC = ../../blis/install/c66xTiny/include/blis/
BLIS_MEM_MODEL = MEM_MODEL_TINY
endif

INCDIR += -I$(BLIS_INC)

INCS = -I. -I$(strip $(subst ;, -I,$(subst $(space),$(space),$(INCDIR))))

CL6X_FLAGS  = $(INCS) --openmp --use_g2 -D$(TARGET) -D$(LIBOS) -D$(BLIS_MEM_MODEL) -DBLIS_MAX_NUM_THREADS=${NUM_DSP_CORES}

DSP_LIB_DIR = ../lib
DSP_LIB = $(DSP_LIB_DIR)/libticblas.ae66

OBJS = ticblas.obj

all: lib
cross: lib

lib: $(OBJS)
	@echo; echo "Building DSP lib: $(DSP_LIB)"
	mkdir -p $(DSP_LIB_DIR)
	$(AR) -cr $(DSP_LIB) $(OBJS)

clean::
	rm -r $(DSP_LIB_DIR)