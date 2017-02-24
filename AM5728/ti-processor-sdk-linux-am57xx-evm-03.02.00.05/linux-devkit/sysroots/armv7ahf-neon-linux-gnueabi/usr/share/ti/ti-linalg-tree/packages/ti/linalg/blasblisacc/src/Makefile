include ../../make.inc

PATH:=$(CGTROOT)/bin:$(PATH)

# Defines
TI_CBLAS_FAT_BINARY = 1
ARM_PLUS_DSP_LIB_DIR = ../lib

INCDIR := $(CGTROOT)/include
INCDIR += -I$(OMP_DIR)/packages/ti/runtime/openmp
INCDIR += -I$(FC_DIR)/packages
INCDIR += -I$(XDC_DIR)/packages
INCDIR += -I$(BIOS_DIR)/packages
INCDIR += -I$(XDAIS_DIR)/packages
INCDIR += -I$(LIBARCH_DIR)/packages
INCDIR += -I$(PDK_DIR)/packages
INCDIR += -I$(TI_OCL_INSTALL_DIR)

INCS = -I. -I$(strip $(subst ;, -I,$(subst $(space),$(space),$(INCDIR))))
OBJS = ti_cblas_initfini.o

# CBLAS and BLIS directories
CBLAS_DSP_LIB = ../../cblas/lib/C66/libcblas.ae66 
TICBLAS_DSP_LIB = ../../ticblas/lib/libticblas.ae66
CBLAS_ARM_LIB = ../../cblas/lib/ARM/libcblas_ARM.a
LIBARCH_LIB = $(LIBARCH_DIR)/packages/ti/libarch/lib/libarch.ae66

ifeq ($(MEM_MODEL),Large)
BLIS_DSP_LIB  = ../../blis/install/c66xLarge/lib/libblis.ae66
else ifeq ($(MEM_MODEL),Medium)
BLIS_DSP_LIB = ../../blis/install/c66xMedium/lib/libblis.ae66
else ifeq ($(MEM_MODEL),Small)
BLIS_DSP_LIB = ../../blis/install/c66xSmall/lib/libblis.ae66
#else ifeq ($(MEM_MODEL),Tiny)
endif

CPP_DEBUG   = -g
CPP_FLAGS   = -D_LITTLE_ENDIAN -D__ARMv7 -DMEM_MODEL_${MEM_MODEL} -I../../cblas/include -I../../blis/install/arm/include/blis/ -fopenmp 
CL6X_FLAGS  = $(INCS) --openmp --use_g2 -D$(TARGET) -DLIB_OPENCL
CLOCL_FLAGS = 
OBJCOPY_ARGS=
ARM_PLUS_DSP_LIB= $(ARM_PLUS_DSP_LIB_DIR)/libcblas_armplusdsp.a

# OpenCL libraries included in make.inc
LIBS += -lpthread

OCL_BIN = ti_cblas_kernel.out

ifeq ($(TI_CBLAS_FAT_BINARY), 1)
  CPP_FLAGS += -DTI_CBLAS_FAT_BINARY
  OCL_BIN = ti_cblas_kernel.dsp_h
endif


ifneq ($(TI_CBLAS_OFFLOAD),)
  CPP_FLAGS += -DTI_CBLAS_OFFLOAD=\"$(TI_CBLAS_OFFLOAD)\"
endif

OBJCOPY_ARGS += --redefine-sym=cblas_caxpy=__real_cblas_caxpy
OBJS += ti_cblas_cblas_caxpy.o
OBJCOPY_ARGS += --redefine-sym=cblas_ccopy=__real_cblas_ccopy
OBJS += ti_cblas_cblas_ccopy.o
OBJCOPY_ARGS += --redefine-sym=cblas_cdotc_sub=__real_cblas_cdotc_sub
OBJS += ti_cblas_cblas_cdotc_sub.o
OBJCOPY_ARGS += --redefine-sym=cblas_cdotu_sub=__real_cblas_cdotu_sub
OBJS += ti_cblas_cblas_cdotu_sub.o
OBJCOPY_ARGS += --redefine-sym=cblas_cgbmv=__real_cblas_cgbmv
OBJS += ti_cblas_cblas_cgbmv.o
OBJCOPY_ARGS += --redefine-sym=cblas_cgemm=__real_cblas_cgemm
OBJS += ti_cblas_cblas_cgemm.o
OBJCOPY_ARGS += --redefine-sym=cblas_cgemv=__real_cblas_cgemv
OBJS += ti_cblas_cblas_cgemv.o
OBJCOPY_ARGS += --redefine-sym=cblas_cgerc=__real_cblas_cgerc
OBJS += ti_cblas_cblas_cgerc.o
OBJCOPY_ARGS += --redefine-sym=cblas_cgeru=__real_cblas_cgeru
OBJS += ti_cblas_cblas_cgeru.o
OBJCOPY_ARGS += --redefine-sym=cblas_chbmv=__real_cblas_chbmv
OBJS += ti_cblas_cblas_chbmv.o
OBJCOPY_ARGS += --redefine-sym=cblas_chemm=__real_cblas_chemm
OBJS += ti_cblas_cblas_chemm.o
OBJCOPY_ARGS += --redefine-sym=cblas_chemv=__real_cblas_chemv
OBJS += ti_cblas_cblas_chemv.o
OBJCOPY_ARGS += --redefine-sym=cblas_cher=__real_cblas_cher
OBJS += ti_cblas_cblas_cher.o
OBJCOPY_ARGS += --redefine-sym=cblas_cher2=__real_cblas_cher2
OBJS += ti_cblas_cblas_cher2.o
OBJCOPY_ARGS += --redefine-sym=cblas_cher2k=__real_cblas_cher2k
OBJS += ti_cblas_cblas_cher2k.o
OBJCOPY_ARGS += --redefine-sym=cblas_cherk=__real_cblas_cherk
OBJS += ti_cblas_cblas_cherk.o
OBJCOPY_ARGS += --redefine-sym=cblas_chpmv=__real_cblas_chpmv
OBJS += ti_cblas_cblas_chpmv.o
OBJCOPY_ARGS += --redefine-sym=cblas_chpr=__real_cblas_chpr
OBJS += ti_cblas_cblas_chpr.o
OBJCOPY_ARGS += --redefine-sym=cblas_chpr2=__real_cblas_chpr2
OBJS += ti_cblas_cblas_chpr2.o
OBJCOPY_ARGS += --redefine-sym=cblas_cscal=__real_cblas_cscal
OBJS += ti_cblas_cblas_cscal.o
OBJCOPY_ARGS += --redefine-sym=cblas_csscal=__real_cblas_csscal
OBJS += ti_cblas_cblas_csscal.o
OBJCOPY_ARGS += --redefine-sym=cblas_cswap=__real_cblas_cswap
OBJS += ti_cblas_cblas_cswap.o
OBJCOPY_ARGS += --redefine-sym=cblas_csymm=__real_cblas_csymm
OBJS += ti_cblas_cblas_csymm.o
OBJCOPY_ARGS += --redefine-sym=cblas_csyr2k=__real_cblas_csyr2k
OBJS += ti_cblas_cblas_csyr2k.o
OBJCOPY_ARGS += --redefine-sym=cblas_csyrk=__real_cblas_csyrk
OBJS += ti_cblas_cblas_csyrk.o
OBJCOPY_ARGS += --redefine-sym=cblas_ctbmv=__real_cblas_ctbmv
OBJS += ti_cblas_cblas_ctbmv.o
OBJCOPY_ARGS += --redefine-sym=cblas_ctbsv=__real_cblas_ctbsv
OBJS += ti_cblas_cblas_ctbsv.o
OBJCOPY_ARGS += --redefine-sym=cblas_ctpmv=__real_cblas_ctpmv
OBJS += ti_cblas_cblas_ctpmv.o
OBJCOPY_ARGS += --redefine-sym=cblas_ctpsv=__real_cblas_ctpsv
OBJS += ti_cblas_cblas_ctpsv.o
OBJCOPY_ARGS += --redefine-sym=cblas_ctrmm=__real_cblas_ctrmm
OBJS += ti_cblas_cblas_ctrmm.o
OBJCOPY_ARGS += --redefine-sym=cblas_ctrmv=__real_cblas_ctrmv
OBJS += ti_cblas_cblas_ctrmv.o
OBJCOPY_ARGS += --redefine-sym=cblas_ctrsm=__real_cblas_ctrsm
OBJS += ti_cblas_cblas_ctrsm.o
OBJCOPY_ARGS += --redefine-sym=cblas_ctrsv=__real_cblas_ctrsv
OBJS += ti_cblas_cblas_ctrsv.o
OBJCOPY_ARGS += --redefine-sym=cblas_dasum=__real_cblas_dasum
OBJS += ti_cblas_cblas_dasum.o
OBJCOPY_ARGS += --redefine-sym=cblas_daxpy=__real_cblas_daxpy
OBJS += ti_cblas_cblas_daxpy.o
OBJCOPY_ARGS += --redefine-sym=cblas_dcopy=__real_cblas_dcopy
OBJS += ti_cblas_cblas_dcopy.o
OBJCOPY_ARGS += --redefine-sym=cblas_ddot=__real_cblas_ddot
OBJS += ti_cblas_cblas_ddot.o
OBJCOPY_ARGS += --redefine-sym=cblas_dgbmv=__real_cblas_dgbmv
OBJS += ti_cblas_cblas_dgbmv.o
OBJCOPY_ARGS += --redefine-sym=cblas_dgemm=__real_cblas_dgemm
OBJS += ti_cblas_cblas_dgemm.o
OBJCOPY_ARGS += --redefine-sym=cblas_dgemv=__real_cblas_dgemv
OBJS += ti_cblas_cblas_dgemv.o
OBJCOPY_ARGS += --redefine-sym=cblas_dger=__real_cblas_dger
OBJS += ti_cblas_cblas_dger.o
OBJCOPY_ARGS += --redefine-sym=cblas_dnrm2=__real_cblas_dnrm2
OBJS += ti_cblas_cblas_dnrm2.o
OBJCOPY_ARGS += --redefine-sym=cblas_drot=__real_cblas_drot
OBJS += ti_cblas_cblas_drot.o
OBJCOPY_ARGS += --redefine-sym=cblas_drotg=__real_cblas_drotg
OBJS += ti_cblas_cblas_drotg.o
OBJCOPY_ARGS += --redefine-sym=cblas_drotm=__real_cblas_drotm
OBJS += ti_cblas_cblas_drotm.o
OBJCOPY_ARGS += --redefine-sym=cblas_drotmg=__real_cblas_drotmg
OBJS += ti_cblas_cblas_drotmg.o
OBJCOPY_ARGS += --redefine-sym=cblas_dsbmv=__real_cblas_dsbmv
OBJS += ti_cblas_cblas_dsbmv.o
OBJCOPY_ARGS += --redefine-sym=cblas_dscal=__real_cblas_dscal
OBJS += ti_cblas_cblas_dscal.o
OBJCOPY_ARGS += --redefine-sym=cblas_dsdot=__real_cblas_dsdot
OBJS += ti_cblas_cblas_dsdot.o
OBJCOPY_ARGS += --redefine-sym=cblas_dspmv=__real_cblas_dspmv
OBJS += ti_cblas_cblas_dspmv.o
OBJCOPY_ARGS += --redefine-sym=cblas_dspr=__real_cblas_dspr
OBJS += ti_cblas_cblas_dspr.o
OBJCOPY_ARGS += --redefine-sym=cblas_dspr2=__real_cblas_dspr2
OBJS += ti_cblas_cblas_dspr2.o
OBJCOPY_ARGS += --redefine-sym=cblas_dswap=__real_cblas_dswap
OBJS += ti_cblas_cblas_dswap.o
OBJCOPY_ARGS += --redefine-sym=cblas_dsymm=__real_cblas_dsymm
OBJS += ti_cblas_cblas_dsymm.o
OBJCOPY_ARGS += --redefine-sym=cblas_dsymv=__real_cblas_dsymv
OBJS += ti_cblas_cblas_dsymv.o
OBJCOPY_ARGS += --redefine-sym=cblas_dsyr=__real_cblas_dsyr
OBJS += ti_cblas_cblas_dsyr.o
OBJCOPY_ARGS += --redefine-sym=cblas_dsyr2=__real_cblas_dsyr2
OBJS += ti_cblas_cblas_dsyr2.o
OBJCOPY_ARGS += --redefine-sym=cblas_dsyr2k=__real_cblas_dsyr2k
OBJS += ti_cblas_cblas_dsyr2k.o
OBJCOPY_ARGS += --redefine-sym=cblas_dsyrk=__real_cblas_dsyrk
OBJS += ti_cblas_cblas_dsyrk.o
OBJCOPY_ARGS += --redefine-sym=cblas_dtbmv=__real_cblas_dtbmv
OBJS += ti_cblas_cblas_dtbmv.o
OBJCOPY_ARGS += --redefine-sym=cblas_dtbsv=__real_cblas_dtbsv
OBJS += ti_cblas_cblas_dtbsv.o
OBJCOPY_ARGS += --redefine-sym=cblas_dtpmv=__real_cblas_dtpmv
OBJS += ti_cblas_cblas_dtpmv.o
OBJCOPY_ARGS += --redefine-sym=cblas_dtpsv=__real_cblas_dtpsv
OBJS += ti_cblas_cblas_dtpsv.o
OBJCOPY_ARGS += --redefine-sym=cblas_dtrmm=__real_cblas_dtrmm
OBJS += ti_cblas_cblas_dtrmm.o
OBJCOPY_ARGS += --redefine-sym=cblas_dtrmv=__real_cblas_dtrmv
OBJS += ti_cblas_cblas_dtrmv.o
OBJCOPY_ARGS += --redefine-sym=cblas_dtrsm=__real_cblas_dtrsm
OBJS += ti_cblas_cblas_dtrsm.o
OBJCOPY_ARGS += --redefine-sym=cblas_dtrsv=__real_cblas_dtrsv
OBJS += ti_cblas_cblas_dtrsv.o
OBJCOPY_ARGS += --redefine-sym=cblas_dzasum=__real_cblas_dzasum
OBJS += ti_cblas_cblas_dzasum.o
OBJCOPY_ARGS += --redefine-sym=cblas_dznrm2=__real_cblas_dznrm2
OBJS += ti_cblas_cblas_dznrm2.o
OBJCOPY_ARGS += --redefine-sym=cblas_xerbla=__real_cblas_xerbla
OBJS += ti_cblas_cblas_xerbla.o
OBJCOPY_ARGS += --redefine-sym=cblas_icamax=__real_cblas_icamax
OBJS += ti_cblas_cblas_icamax.o
OBJCOPY_ARGS += --redefine-sym=cblas_idamax=__real_cblas_idamax
OBJS += ti_cblas_cblas_idamax.o
OBJCOPY_ARGS += --redefine-sym=cblas_isamax=__real_cblas_isamax
OBJS += ti_cblas_cblas_isamax.o
OBJCOPY_ARGS += --redefine-sym=cblas_izamax=__real_cblas_izamax
OBJS += ti_cblas_cblas_izamax.o
OBJCOPY_ARGS += --redefine-sym=cblas_sasum=__real_cblas_sasum
OBJS += ti_cblas_cblas_sasum.o
OBJCOPY_ARGS += --redefine-sym=cblas_saxpy=__real_cblas_saxpy
OBJS += ti_cblas_cblas_saxpy.o
OBJCOPY_ARGS += --redefine-sym=cblas_scasum=__real_cblas_scasum
OBJS += ti_cblas_cblas_scasum.o
OBJCOPY_ARGS += --redefine-sym=cblas_scnrm2=__real_cblas_scnrm2
OBJS += ti_cblas_cblas_scnrm2.o
OBJCOPY_ARGS += --redefine-sym=cblas_scopy=__real_cblas_scopy
OBJS += ti_cblas_cblas_scopy.o
OBJCOPY_ARGS += --redefine-sym=cblas_sdot=__real_cblas_sdot
OBJS += ti_cblas_cblas_sdot.o
OBJCOPY_ARGS += --redefine-sym=cblas_sdsdot=__real_cblas_sdsdot
OBJS += ti_cblas_cblas_sdsdot.o
OBJCOPY_ARGS += --redefine-sym=cblas_sgbmv=__real_cblas_sgbmv
OBJS += ti_cblas_cblas_sgbmv.o
OBJCOPY_ARGS += --redefine-sym=cblas_sgemm=__real_cblas_sgemm
OBJS += ti_cblas_cblas_sgemm.o
OBJCOPY_ARGS += --redefine-sym=cblas_sgemv=__real_cblas_sgemv
OBJS += ti_cblas_cblas_sgemv.o
OBJCOPY_ARGS += --redefine-sym=cblas_sger=__real_cblas_sger
OBJS += ti_cblas_cblas_sger.o
OBJCOPY_ARGS += --redefine-sym=cblas_snrm2=__real_cblas_snrm2
OBJS += ti_cblas_cblas_snrm2.o
OBJCOPY_ARGS += --redefine-sym=cblas_srot=__real_cblas_srot
OBJS += ti_cblas_cblas_srot.o
OBJCOPY_ARGS += --redefine-sym=cblas_srotg=__real_cblas_srotg
OBJS += ti_cblas_cblas_srotg.o
OBJCOPY_ARGS += --redefine-sym=cblas_srotm=__real_cblas_srotm
OBJS += ti_cblas_cblas_srotm.o
OBJCOPY_ARGS += --redefine-sym=cblas_srotmg=__real_cblas_srotmg
OBJS += ti_cblas_cblas_srotmg.o
OBJCOPY_ARGS += --redefine-sym=cblas_ssbmv=__real_cblas_ssbmv
OBJS += ti_cblas_cblas_ssbmv.o
OBJCOPY_ARGS += --redefine-sym=cblas_sscal=__real_cblas_sscal
OBJS += ti_cblas_cblas_sscal.o
OBJCOPY_ARGS += --redefine-sym=cblas_sspmv=__real_cblas_sspmv
OBJS += ti_cblas_cblas_sspmv.o
OBJCOPY_ARGS += --redefine-sym=cblas_sspr=__real_cblas_sspr
OBJS += ti_cblas_cblas_sspr.o
OBJCOPY_ARGS += --redefine-sym=cblas_sspr2=__real_cblas_sspr2
OBJS += ti_cblas_cblas_sspr2.o
OBJCOPY_ARGS += --redefine-sym=cblas_sswap=__real_cblas_sswap
OBJS += ti_cblas_cblas_sswap.o
OBJCOPY_ARGS += --redefine-sym=cblas_ssymm=__real_cblas_ssymm
OBJS += ti_cblas_cblas_ssymm.o
OBJCOPY_ARGS += --redefine-sym=cblas_ssymv=__real_cblas_ssymv
OBJS += ti_cblas_cblas_ssymv.o
OBJCOPY_ARGS += --redefine-sym=cblas_ssyr=__real_cblas_ssyr
OBJS += ti_cblas_cblas_ssyr.o
OBJCOPY_ARGS += --redefine-sym=cblas_ssyr2=__real_cblas_ssyr2
OBJS += ti_cblas_cblas_ssyr2.o
OBJCOPY_ARGS += --redefine-sym=cblas_ssyr2k=__real_cblas_ssyr2k
OBJS += ti_cblas_cblas_ssyr2k.o
OBJCOPY_ARGS += --redefine-sym=cblas_ssyrk=__real_cblas_ssyrk
OBJS += ti_cblas_cblas_ssyrk.o
OBJCOPY_ARGS += --redefine-sym=cblas_stbmv=__real_cblas_stbmv
OBJS += ti_cblas_cblas_stbmv.o
OBJCOPY_ARGS += --redefine-sym=cblas_stbsv=__real_cblas_stbsv
OBJS += ti_cblas_cblas_stbsv.o
OBJCOPY_ARGS += --redefine-sym=cblas_stpmv=__real_cblas_stpmv
OBJS += ti_cblas_cblas_stpmv.o
OBJCOPY_ARGS += --redefine-sym=cblas_stpsv=__real_cblas_stpsv
OBJS += ti_cblas_cblas_stpsv.o
OBJCOPY_ARGS += --redefine-sym=cblas_strmm=__real_cblas_strmm
OBJS += ti_cblas_cblas_strmm.o
OBJCOPY_ARGS += --redefine-sym=cblas_strmv=__real_cblas_strmv
OBJS += ti_cblas_cblas_strmv.o
OBJCOPY_ARGS += --redefine-sym=cblas_strsm=__real_cblas_strsm
OBJS += ti_cblas_cblas_strsm.o
OBJCOPY_ARGS += --redefine-sym=cblas_strsv=__real_cblas_strsv
OBJS += ti_cblas_cblas_strsv.o
OBJCOPY_ARGS += --redefine-sym=cblas_zaxpy=__real_cblas_zaxpy
OBJS += ti_cblas_cblas_zaxpy.o
OBJCOPY_ARGS += --redefine-sym=cblas_zcopy=__real_cblas_zcopy
OBJS += ti_cblas_cblas_zcopy.o
OBJCOPY_ARGS += --redefine-sym=cblas_zdotc_sub=__real_cblas_zdotc_sub
OBJS += ti_cblas_cblas_zdotc_sub.o
OBJCOPY_ARGS += --redefine-sym=cblas_zdotu_sub=__real_cblas_zdotu_sub
OBJS += ti_cblas_cblas_zdotu_sub.o
OBJCOPY_ARGS += --redefine-sym=cblas_zdscal=__real_cblas_zdscal
OBJS += ti_cblas_cblas_zdscal.o
OBJCOPY_ARGS += --redefine-sym=cblas_zgbmv=__real_cblas_zgbmv
OBJS += ti_cblas_cblas_zgbmv.o
OBJCOPY_ARGS += --redefine-sym=cblas_zgemm=__real_cblas_zgemm
OBJS += ti_cblas_cblas_zgemm.o
OBJCOPY_ARGS += --redefine-sym=cblas_zgemv=__real_cblas_zgemv
OBJS += ti_cblas_cblas_zgemv.o
OBJCOPY_ARGS += --redefine-sym=cblas_zgerc=__real_cblas_zgerc
OBJS += ti_cblas_cblas_zgerc.o
OBJCOPY_ARGS += --redefine-sym=cblas_zgeru=__real_cblas_zgeru
OBJS += ti_cblas_cblas_zgeru.o
OBJCOPY_ARGS += --redefine-sym=cblas_zhbmv=__real_cblas_zhbmv
OBJS += ti_cblas_cblas_zhbmv.o
OBJCOPY_ARGS += --redefine-sym=cblas_zhemm=__real_cblas_zhemm
OBJS += ti_cblas_cblas_zhemm.o
OBJCOPY_ARGS += --redefine-sym=cblas_zhemv=__real_cblas_zhemv
OBJS += ti_cblas_cblas_zhemv.o
OBJCOPY_ARGS += --redefine-sym=cblas_zher=__real_cblas_zher
OBJS += ti_cblas_cblas_zher.o
OBJCOPY_ARGS += --redefine-sym=cblas_zher2=__real_cblas_zher2
OBJS += ti_cblas_cblas_zher2.o
OBJCOPY_ARGS += --redefine-sym=cblas_zher2k=__real_cblas_zher2k
OBJS += ti_cblas_cblas_zher2k.o
OBJCOPY_ARGS += --redefine-sym=cblas_zherk=__real_cblas_zherk
OBJS += ti_cblas_cblas_zherk.o
OBJCOPY_ARGS += --redefine-sym=cblas_zhpmv=__real_cblas_zhpmv
OBJS += ti_cblas_cblas_zhpmv.o
OBJCOPY_ARGS += --redefine-sym=cblas_zhpr=__real_cblas_zhpr
OBJS += ti_cblas_cblas_zhpr.o
OBJCOPY_ARGS += --redefine-sym=cblas_zhpr2=__real_cblas_zhpr2
OBJS += ti_cblas_cblas_zhpr2.o
OBJCOPY_ARGS += --redefine-sym=cblas_zscal=__real_cblas_zscal
OBJS += ti_cblas_cblas_zscal.o
OBJCOPY_ARGS += --redefine-sym=cblas_zswap=__real_cblas_zswap
OBJS += ti_cblas_cblas_zswap.o
OBJCOPY_ARGS += --redefine-sym=cblas_zsymm=__real_cblas_zsymm
OBJS += ti_cblas_cblas_zsymm.o
OBJCOPY_ARGS += --redefine-sym=cblas_zsyr2k=__real_cblas_zsyr2k
OBJS += ti_cblas_cblas_zsyr2k.o
OBJCOPY_ARGS += --redefine-sym=cblas_zsyrk=__real_cblas_zsyrk
OBJS += ti_cblas_cblas_zsyrk.o
OBJCOPY_ARGS += --redefine-sym=cblas_ztbmv=__real_cblas_ztbmv
OBJS += ti_cblas_cblas_ztbmv.o
OBJCOPY_ARGS += --redefine-sym=cblas_ztbsv=__real_cblas_ztbsv
OBJS += ti_cblas_cblas_ztbsv.o
OBJCOPY_ARGS += --redefine-sym=cblas_ztpmv=__real_cblas_ztpmv
OBJS += ti_cblas_cblas_ztpmv.o
OBJCOPY_ARGS += --redefine-sym=cblas_ztpsv=__real_cblas_ztpsv
OBJS += ti_cblas_cblas_ztpsv.o
OBJCOPY_ARGS += --redefine-sym=cblas_ztrmm=__real_cblas_ztrmm
OBJS += ti_cblas_cblas_ztrmm.o
OBJCOPY_ARGS += --redefine-sym=cblas_ztrmv=__real_cblas_ztrmv
OBJS += ti_cblas_cblas_ztrmv.o
OBJCOPY_ARGS += --redefine-sym=cblas_ztrsm=__real_cblas_ztrsm
OBJS += ti_cblas_cblas_ztrsm.o
OBJCOPY_ARGS += --redefine-sym=cblas_ztrsv=__real_cblas_ztrsv
OBJS += ti_cblas_cblas_ztrsv.o
OBJCOPY_ARGS += --redefine-sym=cblas_crotg=__real_cblas_crotg
OBJS += ti_cblas_cblas_crotg.o
OBJCOPY_ARGS += --redefine-sym=cblas_zrotg=__real_cblas_zrotg
OBJS += ti_cblas_cblas_zrotg.o
OBJS += ti_l3_offload.o
OBJS += ofld_tbl_cgemm.o
OBJS += ofld_tbl_dgemm.o
OBJS += ofld_tbl_sgemm.o
OBJS += ofld_tbl_zgemm.o
OBJS += ofld_tbl_csyrk.o
OBJS += ofld_tbl_dsyrk.o
OBJS += ofld_tbl_ssyrk.o
OBJS += ofld_tbl_zsyrk.o
OBJS += ofld_tbl_ctrmm.o
OBJS += ofld_tbl_dtrmm.o
OBJS += ofld_tbl_strmm.o
OBJS += ofld_tbl_ztrmm.o
OBJS += ofld_tbl_ctrsm.o
OBJS += ofld_tbl_dtrsm.o
OBJS += ofld_tbl_strsm.o
OBJS += ofld_tbl_ztrsm.o

all: armplusdsp
cross: armplusdsp

crossC66x: BLIS_DSP_LIB = ../../blis/install/c66x/lib/libblis.ae66
#crossC66x: CL6X_FLAGS+= -I../../blis/install/c66x/include/blis/
crossC66x: cross $(OCL_BIN) $(OBJS)

crossAM57x: BLIS_DSP_LIB = ../../blis/install/am57x/lib/libblis.ae66
#crossAM57x: CL6X_FLAGS+= -I../../blis/install/am57x/include/blis/
crossAM57x: cross $(OCL_BIN) $(OBJS)

crossShannon: BLIS_DSP_LIB = ../../blis/install/shannon/lib/libblis.ae66
#crossShannon: CL6X_FLAGS+= -I../../blis/install/shannon/include/blis/
crossShannon: cross $(OCL_BIN) $(OBJS)

debug: CPP_FLAGS += -DTI_CBLAS_DEBUG $(CPP_DEBUG) #-DTI_CBLAS_PROFILE
debug: cross
debug: CL6X_FLAGS += -DTI_CBLAS_DEBUG

profile: CPP_FLAGS += -DTI_CBLAS_PROFILE
profile: armplusdsp

armplusdsp: $(OCL_BIN) $(OBJS)
	@echo; echo "Building hybrid ARM+DSP lib: $(ARM_PLUS_DSP_LIB)"
	mkdir -p $(ARM_PLUS_DSP_LIB_DIR)
	$(OBJCOPY) $(OBJCOPY_ARGS) $(CBLAS_ARM_LIB) $(ARM_PLUS_DSP_LIB)
	$(AR) -cr $(ARM_PLUS_DSP_LIB) $(OBJS)

# if we have a fat binary header then the initfini file needs it
ti_cblas_initfini.o: $(OCL_BIN)

# target for fat binary
ti_cblas_kernel.dsp_h: ti_cblas_kernel.cl facade.obj ti_cblas_mem_config.obj $(CBLAS_DSP_LIB) $(BLIS_DSP_LIB) $(TICBLAS_DSP_LIB) $(LIBARCH_LIB)
	@echo; echo Building $@
	@rm -f ti_cblas_kernel.out
	@echo Building fat binary header
	clocl --txt -g $^ 

# target if fat binary not used
ti_cblas_kernel.out: ti_cblas_kernel.cl facade.obj $(CBLAS_DSP_LIB) $(BLIS_DSP_LIB)
	@echo; echo Building $@
	clocl $^ 
	mkdir -p $(ARM_PLUS_DSP_LIB_DIR)
	cp $(OCL_BIN) $(ARM_PLUS_DSP_LIB_DIR)/$(OCL_BIN)

ofld_tbl_%.o: ofld_tbls_$(TARGET)/ofld_tbl_%.c
	@echo Compiling $<
	$(CPP) -c $(CPP_FLAGS) $<

clean::
	@rm -f $(ARM_PLUS_DSP_LIB) $(OBJS) $(OCL_BIN) $(ARM_PLUS_DSP_LIB_DIR)/$(OCL_BIN)
	@rm -rf /tmp/opencl*

cleanObj:
	@rm -f $(OBJS) $(OCL_BIN)

