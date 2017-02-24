
ifeq ($(SOC),$(filter $(SOC), tda2xx dra75x tda2ex am571x am572x tda3xx dra78x))
PACKAGE_SRCS_COMMON += cslr_mcasp.h csl_mcasp.h src/ip/mcasp/src_files_mcasp.mk src/ip/mcasp/V0
SRCS_COMMON += mcasp.c
SRCDIR += src/ip/mcasp/V0/priv
INCDIR += . src/ip/mcasp/V0
endif

ifeq ($(SOC),$(filter $(SOC), am335x am437x k2g))
PACKAGE_SRCS_COMMON += cslr_mcasp.h csl_mcasp.h src/ip/mcasp/src_files_mcasp.mk src/ip/mcasp/V1
SRCS_COMMON += mcasp.c
SRCDIR += src/ip/mcasp/V1/priv
INCDIR += . src/ip/mcasp/V1
endif
