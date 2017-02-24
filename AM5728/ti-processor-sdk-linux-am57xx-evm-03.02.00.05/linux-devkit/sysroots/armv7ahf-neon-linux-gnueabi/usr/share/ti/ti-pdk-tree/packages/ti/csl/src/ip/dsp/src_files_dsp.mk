
ifeq ($(SOC),$(filter $(SOC), tda2xx am572x dra75x tda2ex am571x tda3xx dra78x))
PACKAGE_SRCS_COMMON += cslr_dsp.h src/ip/dsp/src_files_dsp.mk src/ip/dsp/V0
endif
