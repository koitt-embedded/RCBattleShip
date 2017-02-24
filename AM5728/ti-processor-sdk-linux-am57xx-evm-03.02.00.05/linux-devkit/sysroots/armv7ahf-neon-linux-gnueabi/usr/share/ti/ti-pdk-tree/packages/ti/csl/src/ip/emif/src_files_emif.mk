
ifeq ($(SOC),$(filter $(SOC), tda2xx dra75x tda2ex tda3xx dra78x))
PACKAGE_SRCS_COMMON += cslr_emif.h csl_emif.h src/ip/emif/src_files_emif.mk
PACKAGE_SRCS_COMMON += src/ip/emif/V0/emif.h src/ip/emif/V0/priv
SRCDIR += src/ip/emif/V0/priv
INCDIR += src/ip/emif/V0
SRCS_COMMON += emif.c
endif

ifeq ($(SOC),$(filter $(SOC), tda2xx dra75x tda2ex))
PACKAGE_SRCS_COMMON += src/ip/emif/V0/V0_0
INCDIR += src/ip/emif/V0/V0_0
endif

ifeq ($(SOC),$(filter $(SOC), tda3xx dra78x))
PACKAGE_SRCS_COMMON += src/ip/emif/V0/V0_1
INCDIR += src/ip/emif/V0/V0_1
endif
