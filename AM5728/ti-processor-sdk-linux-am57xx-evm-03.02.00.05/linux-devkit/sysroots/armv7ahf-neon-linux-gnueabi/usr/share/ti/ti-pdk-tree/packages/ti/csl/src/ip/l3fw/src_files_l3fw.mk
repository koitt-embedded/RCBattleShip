
ifeq ($(SOC),$(filter $(SOC), tda2xx dra75x tda2ex am571x am572x tda3xx dra78x))
PACKAGE_SRCS_COMMON += cslr_l3fw.h csl_l3fw.h src/ip/l3fw/src_files_l3fw.mk src/ip/l3fw/V0
SRCDIR += src/ip/l3fw/V0/priv
INCDIR += src/ip/l3fw/V0
SRCS_COMMON += l3fw.c
endif
