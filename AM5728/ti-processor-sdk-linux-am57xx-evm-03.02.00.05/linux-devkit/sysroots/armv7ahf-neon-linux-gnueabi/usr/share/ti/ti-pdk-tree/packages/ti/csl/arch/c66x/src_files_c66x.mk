
ifeq ($(SOC),$(filter $(SOC), tda2xx dra75x tda2ex tda3xx am572x am571x dra78x))

PACKAGE_SRCS_COMMON += arch/c66x
ifeq ($(ARCH),c66x)
SRCDIR += ./arch/c66x/src
INCDIR += ./arch/c66x
SRCS_COMMON += interrupt.c dsp_wugen.c dsp_config.c
endif

endif
