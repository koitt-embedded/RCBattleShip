
INCDIR := $(XDC_DIR)/packages;$(BIOS_DIR)/packages;$(XDAIS_DIR)/packages;$(CGTROOT)/include;$(PDK_DIR)/packages;$(FC_DIR)/packages;$(TI_OCL_INSTALL_DIR)

INCS = -I. -I$(strip $(subst ;, -I,$(subst $(space),$(space),$(INCDIR))))

CL6X_FLAGS = $(INCS) --use_g2 -D$(TARGET) -D$(LIBOS)

CL6X  = cl6x -mv6600 --abi=eabi

DSP_LIB_DIR = ../lib
DSP_LIB = $(DSP_LIB_DIR)/libarch.ae66

OBJS = lib_cachecfg.obj lib_memmgt.obj

all: lib
cross: lib

lib: $(OBJS)
	@echo; echo "Building DSP lib: $(DSP_LIB)"
	mkdir -p $(DSP_LIB_DIR)
	$(AR) -cr $(DSP_LIB) $(OBJS)

clean:
	rm *.obj; rm $(DSP_LIB)

%.obj: %.c
	@echo Compiling $<
	$(CL6X) -c $(CL6X_FLAGS) $<
