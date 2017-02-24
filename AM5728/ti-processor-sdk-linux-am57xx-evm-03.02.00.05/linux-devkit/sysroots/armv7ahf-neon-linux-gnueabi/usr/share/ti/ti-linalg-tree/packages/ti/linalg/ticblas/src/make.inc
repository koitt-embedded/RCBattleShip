
# Defines
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
	rm $(DSP_LIB)