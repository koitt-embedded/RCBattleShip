
ifeq ($(SOC),$(filter $(SOC), tda2xx am572x dra75x tda2ex am571x))
PACKAGE_SRCS_COMMON += cslr_dei.h src/ip/dei/src_files_dei.mk src/ip/dei/V0
endif
