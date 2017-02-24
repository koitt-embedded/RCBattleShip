
ifeq ($(SOC),$(filter $(SOC), tda2xx am572x dra75x tda2ex am571x tda3xx dra78x))
PACKAGE_SRCS_COMMON += cslr_vip.h cslr_vip_parser.h src/ip/vip/src_files_vip.mk src/ip/vip/V0
endif
