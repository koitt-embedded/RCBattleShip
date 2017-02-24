
ifeq ($(SOC),$(filter $(SOC), am572x am571x))
PACKAGE_SRCS_COMMON += cslr_ecap.h src/ip/ecap/src_files_ecap.mk
PACKAGE_SRCS_COMMON += src/ip/ecap/V0/ecap.h src/ip/ecap/V0/priv
endif

ifeq ($(SOC),$(filter $(SOC), am572x am571x))
PACKAGE_SRCS_COMMON += src/ip/ecap/V0
SRCDIR += src/ip/ecap/V0/priv
INCDIR += src/ip/ecap/V0
SRCS_COMMON += ecap.c
INCDIR += . src/ip/ecap/V0
endif
