
.PHONY: clean ARMonly linalg cleanall install build prebuild

LINALG_BLIS_DIR     = blis
LINALG_CBLAS_DIR    = cblas
LINALG_TICBLAS_DIR  = ticblas
LINALG_BLASACC_DIR  = blasblisacc
LINALG_CLAPACK_DIR  = clapack
BLIS_VERSION = $(shell cat $(LINALG_BLIS_DIR)/version)

CBLAS_HEADERS  =$(LINALG_CBLAS_DIR)/include/cblas.h
CLAPACK_HEADERS =$(LINALG_CLAPACK_DIR)/INCLUDE/blaswrap.h  
CLAPACK_HEADERS+=$(LINALG_CLAPACK_DIR)/INCLUDE/clapack.h  
CLAPACK_HEADERS+=$(LINALG_CLAPACK_DIR)/INCLUDE/f2c.h  

ifneq (,$(findstring DSP,$(MAKECMDGOALS)))

ifeq ($(LIBOS),LIB_RTOS)
CBLAS_HEADERS +=$(LINALG_TICBLAS_DIR)/ticblas.h
endif

ifeq ($(TARGET),SOC_K2H)
NUM_ARM_CORES=4
NUM_DSP_CORES=8
else ifeq ($(TARGET),SOC_C6678)
NUM_DSP_CORES=8
else ifeq ($(TARGET),SOC_AM572x)
NUM_ARM_CORES=2
NUM_DSP_CORES=2
else
$(call error, ERROR - TARGET NOT DEFINED. Must specify one of: TARGET=SOC_K2H, TARGET=SOC_C6678, TARGET=SOC_AM572x)
endif

endif

# MEM_MODEL needs to be defined for both build and clean
ifeq ($(MEM_MODEL),Large)
BLIS_CFG   = c66xLarge
else ifeq ($(MEM_MODEL),Medium)
BLIS_CFG   = c66xMedium
else ifeq ($(MEM_MODEL),Small)
BLIS_CFG   = c66xSmall
else
$(call error, ERROR - MEM_MODEL NOT DEFINED. Must specify one of: MEM_MODEL=Large, MEM_MODEL=Medium, MEM_MODEL=Small)
endif

# Build DSP code for DSP-only platforms and for ARM+DSP platforms. 
# All object binaries are added to a singl archive: lib/libcblas.ae66, which includes:
#    - CBLAS 
#    - BLIS for specified TARGET, MEM_MODEL, LIBOS (BIOS or OPENCL), NUM_DSP_CORES
#    - TICBLAS for specified TARGET, MEM_MODEL, LIBOS (BIOS or OPENCL)
DSPlibs:
	cd $(LINALG_CBLAS_DIR); make arch=C66 alllib  || exit 1; \
	cd ../$(LINALG_BLIS_DIR); ./configure -p install/$(BLIS_CFG) c66x; \
	make -j8 MEM_MODEL=$(MEM_MODEL) TARGET=$(TARGET) LIBOS=$(LIBOS) NUM_DSP_CORES=$(NUM_DSP_CORES) || exit 1; make install; \
	cd ../$(LINALG_TICBLAS_DIR)/src; make MEM_MODEL=$(MEM_MODEL) TARGET=$(TARGET) LIBOS=$(LIBOS) NUM_DSP_CORES=$(NUM_DSP_CORES) || exit 1; cd ../lib; \
	echo "combining BLIS, CBLAS, and TICBLAS libraries into one: libcblas.ae66"; \
	rm -rf blas_objs blis_objs; mkdir blas_objs blis_objs; cd blis_objs; ar x ../../../blis/install/$(BLIS_CFG)/lib/libblis.ae66; chmod +rw *; \
	cd ../blas_objs; ar -x ../../../cblas/lib/C66/libcblas.ae66; ar -x ../libticblas.ae66; chmod +rw *; cd ../../..; \
	rm -rf lib; mkdir lib; cd lib; ar -cr libcblas.ae66 ../ticblas/lib/blas_objs/*; ar -q libcblas.ae66 ../ticblas/lib/blis_objs/*; cd ..; \
	rm -rf include; mkdir include; cp $(CBLAS_HEADERS) include

# Build ARM code for ARM+DSP platforms
ARMlibs:
	cd $(LINALG_CBLAS_DIR); make arch=ARM alllib || exit 1; \
	cd ../$(LINALG_BLIS_DIR); ./configure -p install/arm cortex-a15; make -j8 NUM_ARM_CORES=$(NUM_ARM_CORES) || exit 1; make install; \
	cd ../$(LINALG_CLAPACK_DIR); make f2clib || exit 1; make cblaswrap || exit 1; cd SRC; make -j8 || exit 1; cd ..

# Build host-callable libraries for ARM+DSP platforms. 
# BLAS has a single archive: libcblas_armplusdsp.a, which includes:
#    - CBLAS ARM code
#    - BLIS ARM code for specified NUM_ARM_CORES
#    - BLAS wrapper (accelerator) code
#    - DSP code built by DSPlibs
# LAPACK has 3 archives: 
#    - liblapack.a: CLAPACK ARM library
#    - libcblaswr.a: CBLAS wrapper library used by CLAPACK
#    - libf2c.a: F2C library used by CLAPACK
ARMplusDSP: DSPlibs ARMlibs
	cd $(LINALG_BLASACC_DIR)/src; make MEM_MODEL=$(MEM_MODEL) TARGET=$(TARGET) || exit 1; cd ../..; \
	cd lib; rm -rf *; mkdir blis_objs blas_acc_objs; \
	cp ../$(LINALG_BLASACC_DIR)/lib/libcblas_armplusdsp.a blas_acc_objs; \
	cp ../$(LINALG_BLIS_DIR)/install/arm/lib/libblis.a blis_objs; \
	cd blis_objs; ar -x libblis.a; cd ../blas_acc_objs; ar -x libcblas_armplusdsp.a; cd ../; \
	ar -cr libcblas_armplusdsp.a blas_acc_objs/*.o; ar -q libcblas_armplusdsp.a blis_objs/*.o; rm -r blas_acc_objs blis_objs; cd ..; \
	cp $(LINALG_CLAPACK_DIR)/lapack_ARM.a ./lib/liblapack.a; \
	cp $(LINALG_CLAPACK_DIR)/libcblaswr_ARM.a ./lib/libcblaswr.a; \
	cp $(LINALG_CLAPACK_DIR)/F2CLIBS/libf2c_ARM.a ./lib/libf2c.a; \
	cp $(CLAPACK_HEADERS) include

cleanDSPlibs:
	rm -f lib/*
	cd $(LINALG_CBLAS_DIR); make arch=C66 clean; \
	cd ../$(LINALG_BLIS_DIR); ./configure -p install/$(BLIS_CFG) c66x; make -j8 clean; rm -r install/$(BLIS_CFG); \
	cd ../$(LINALG_TICBLAS_DIR)/src; make clean; 

cleanARMlibs:
	cd $(LINALG_CBLAS_DIR); make arch=ARM clean; \
	cd ../$(LINALG_BLIS_DIR); ./configure -p install/arm cortex-a15; make clean; rm -r install/arm; \
	cd ../$(LINALG_BLASACC_DIR); make clean; \
	cd ../$(LINALG_BLIS_DIR)/testsuite; make clean; \
	cd ../../$(LINALG_CLAPACK_DIR); make clean

BLIStest:
	cd $(LINALG_BLIS_DIR); ./configure -p install/arm cortex-a15; \
	cd testsuite; make lib=OpenCLCBLAS -j8 

BLIStestDSP:
	cd $(LINALG_BLIS_DIR); ./configure -p install/$(BLIS_CFG) c66x; \
	cd testsuite/dsponly; make MEM_MODEL=$(MEM_MODEL) TARGET=$(TARGET) LIBOS=$(LIBOS) NUM_DSP_CORES=$(NUM_DSP_CORES)

BLAStest:
	cd $(LINALG_CLAPACK_DIR)/BLAS/TESTING; make -f Makeblat1; make -f Makeblat2; make -f Makeblat3

CLAPACKtest:
	cd $(LINALG_CLAPACK_DIR)/TESTING/MATGEN; make 
	cd $(LINALG_CLAPACK_DIR)/TESTING/LIN; make
	cd $(LINALG_CLAPACK_DIR)/TESTING/EIG; make


cleanARMplusDSP: cleanDSPlibs cleanARMlibs

docs: doxygen/doxycfg.txt doxygen/mainpage.dox
	doxygen ./docs/doxygen/doxycfg.txt

installDSPlib:
	install -m 755 -d ${DESTDIR}/include
	install -m 755 -d ${DESTDIR}/lib
	cp include/* ${DESTDIR}/include
	cp ./lib/libcblas.ae66 ${DESTDIR}/lib
	cp -r docs ${DESTDIR}

installARMplusDSPlib:
	install -m 755 -d ${DESTDIR}/include
	install -m 755 -d ${DESTDIR}/lib
	cp include/* ${DESTDIR}/include
	cp ./lib/libcblas_armplusdsp.a ${DESTDIR}/lib
	cp ./lib/liblapack.a ${DESTDIR}/lib
	cp ./lib/libcblaswr.a ${DESTDIR}/lib
	cp ./lib/libf2c.a ${DESTDIR}/lib
	cp -r docs ${DESTDIR}
