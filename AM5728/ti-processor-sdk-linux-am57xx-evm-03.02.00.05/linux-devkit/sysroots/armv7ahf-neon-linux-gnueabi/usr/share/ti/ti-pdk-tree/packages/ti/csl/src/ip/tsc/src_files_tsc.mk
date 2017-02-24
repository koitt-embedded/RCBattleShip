
ifeq ($(SOC),$(filter $(SOC), am571x am572x k2h k2k k2l k2e k2g c6678 c6657))
PACKAGE_SRCS_COMMON += src/ip/tsc/V0
SRCDIR += src/ip/tsc/V0
INCDIR += src/ip/tsc/V0

ifeq ($(CORE),c66x)
SRCS_ASM_COMMON += csl_tsc.asm
INCDIR += . src/ip/tsc/V0
endif

endif

