
ifeq ($(SOC),$(filter $(SOC), tda2xx dra75x tda2ex am571x am572x tda3xx dra78x))
PACKAGE_SRCS_COMMON += cslr_synctimer.h src/ip/synctimer/src_files_synctimer.mk src/ip/synctimer/V0
endif
