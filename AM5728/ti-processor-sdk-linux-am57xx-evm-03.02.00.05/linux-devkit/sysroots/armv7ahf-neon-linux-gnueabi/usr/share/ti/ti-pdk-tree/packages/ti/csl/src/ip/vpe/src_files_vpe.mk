
ifeq ($(SOC),$(filter $(SOC), tda2xx am572x dra75x tda2ex am571x))
PACKAGE_SRCS_COMMON += cslr_vpe.h src/ip/vpe/src_files_vpe.mk src/ip/vpe/V0
endif
