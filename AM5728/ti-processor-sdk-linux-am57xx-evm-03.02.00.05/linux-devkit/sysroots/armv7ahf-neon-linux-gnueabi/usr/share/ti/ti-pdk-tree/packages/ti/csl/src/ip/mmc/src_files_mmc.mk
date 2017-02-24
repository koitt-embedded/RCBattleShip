
ifeq ($(SOC),$(filter $(SOC), tda2xx dra75x tda2ex am571x am572x tda3xx am335x am437x dra78x))
PACKAGE_SRCS_COMMON += cslr_mmc.h cslr_mmchs.h csl_mmcsd.h src/ip/mmc/src_files_mmc.mk src/ip/mmc/V0
SRCS_COMMON += mmcsd.c
SRCDIR += src/ip/mmc/V0/priv
INCDIR += . src/ip/mmc/V0
endif
