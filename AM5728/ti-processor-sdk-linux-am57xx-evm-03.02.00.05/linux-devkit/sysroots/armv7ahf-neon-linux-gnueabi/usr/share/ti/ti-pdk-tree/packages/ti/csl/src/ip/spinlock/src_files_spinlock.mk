
ifeq ($(SOC),$(filter $(SOC), tda2xx dra75x tda2ex am571x am572x tda3xx dra78x))
PACKAGE_SRCS_COMMON += cslr_spinlock.h csl_spinlock.h src/ip/spinlock/src_files_spinlock.mk src/ip/spinlock/V0
SRCS_COMMON += spinlock.c
SRCDIR += src/ip/spinlock/V0/priv
INCDIR += . src/ip/spinlock/V0
endif
