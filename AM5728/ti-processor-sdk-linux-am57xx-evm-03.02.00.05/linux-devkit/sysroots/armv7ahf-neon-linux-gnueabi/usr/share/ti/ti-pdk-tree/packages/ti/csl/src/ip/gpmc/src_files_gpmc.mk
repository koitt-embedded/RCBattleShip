
ifeq ($(SOC),$(filter $(SOC), tda2xx dra75x tda2ex am571x am572x tda3xx am335x am437x dra78x))
PACKAGE_SRCS_COMMON += cslr_gpmc.h csl_gpmc.h src/ip/gpmc/src_files_gpmc.mk src/ip/gpmc/V1
SRCS_COMMON += gpmc.c
SRCDIR += src/ip/gpmc/V1/priv
INCDIR += . src/ip/gpmc/V1
endif
