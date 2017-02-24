
ifeq ($(SOC),$(filter $(SOC), tda2xx dra75x tda2ex am571x am572x tda3xx dra78x))
PACKAGE_SRCS_COMMON += cslr_mmu.h csl_mmu.h src/ip/mmu/src_files_mmu.mk src/ip/mmu/dsp/V0 src/ip/mmu/ipu/V0
SRCDIR += src/ip/mmu/dsp/V0/priv
INCDIR += . src/ip/mmu/dsp/V0
SRCS_COMMON += mmu.c
endif
