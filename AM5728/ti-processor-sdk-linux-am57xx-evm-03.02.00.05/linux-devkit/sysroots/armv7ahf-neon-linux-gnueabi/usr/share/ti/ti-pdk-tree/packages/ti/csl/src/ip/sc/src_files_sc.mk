
ifeq ($(SOC),$(filter $(SOC), tda2xx am572x dra75x tda2ex am571x tda3xx dra78x))
PACKAGE_SRCS_COMMON += cslr_sc.h src/ip/sc/src_files_sc.mk src/ip/sc/V0
endif
