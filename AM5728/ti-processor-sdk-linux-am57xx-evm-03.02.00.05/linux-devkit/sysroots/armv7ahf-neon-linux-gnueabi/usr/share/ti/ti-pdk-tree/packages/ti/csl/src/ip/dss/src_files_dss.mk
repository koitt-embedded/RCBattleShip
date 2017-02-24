
ifeq ($(SOC),$(filter $(SOC), tda2xx am572x dra75x tda2ex am571x tda3xx dra78x))
PACKAGE_SRCS_COMMON += cslr_dss.h src/ip/dss/src_files_dss.mk
endif

ifeq ($(SOC),$(filter $(SOC), tda2xx am572x dra75x tda2ex am571x))
PACKAGE_SRCS_COMMON += src/ip/dss/V1
endif

ifeq ($(SOC),$(filter $(SOC), tda3xx dra78x))
PACKAGE_SRCS_COMMON += src/ip/dss/V2
endif
