
ifeq ($(SOC),$(filter $(SOC), tda2xx am572x dra75x tda2ex am571x tda3xx dra78x))
PACKAGE_SRCS_COMMON += cslr_csc.h src/ip/csc/src_files_csc.mk src/ip/csc/V0
endif
