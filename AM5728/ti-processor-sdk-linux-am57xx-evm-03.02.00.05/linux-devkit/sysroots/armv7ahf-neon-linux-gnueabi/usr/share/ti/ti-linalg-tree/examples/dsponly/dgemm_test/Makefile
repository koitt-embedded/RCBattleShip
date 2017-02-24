
COMMON_FOLDER = ../common
testfiles_obj = dgemm_test.obj 
outfile = dgemm_test.out
CL_OPTS = 
LINALG_LIB  = $(LINALG_DIR)/packages/ti/linalg/lib/libcblas.ae66

include $(COMMON_FOLDER)/Makefile.common

%.obj: %.c
	$(CL) $(CL_OPTS) $<
	echo Compiling $<

