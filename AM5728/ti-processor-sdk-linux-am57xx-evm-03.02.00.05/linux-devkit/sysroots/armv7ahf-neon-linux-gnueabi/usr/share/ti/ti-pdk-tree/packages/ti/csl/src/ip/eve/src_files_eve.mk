
ifeq ($(SOC),$(filter $(SOC), tda2xx am572x dra75x tda2ex am571x tda3xx dra78x))
PACKAGE_SRCS_COMMON += cslr_eve.h src/ip/eve/src_files_eve.mk src/ip/eve/V0
endif
