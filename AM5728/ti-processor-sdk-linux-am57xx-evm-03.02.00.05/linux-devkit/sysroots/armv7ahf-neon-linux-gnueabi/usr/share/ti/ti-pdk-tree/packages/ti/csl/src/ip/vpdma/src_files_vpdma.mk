
ifeq ($(SOC),$(filter $(SOC), tda2xx am572x dra75x tda2ex am571x tda3xx dra78x))
PACKAGE_SRCS_COMMON += cslr_vpdma.h src/ip/vpdma/src_files_vpdma.mk src/ip/vpdma/V0
endif
