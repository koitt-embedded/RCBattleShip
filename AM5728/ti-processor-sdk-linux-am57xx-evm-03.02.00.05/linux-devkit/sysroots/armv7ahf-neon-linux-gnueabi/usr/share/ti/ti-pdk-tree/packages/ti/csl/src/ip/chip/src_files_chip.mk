
ifeq ($(SOC),$(filter $(SOC), am571x am572x k2h k2k k2l k2e k2g c6678 c6657))
PACKAGE_SRCS_COMMON += src/ip/chip/V0
SRCDIR += src/ip/chip/V0
INCDIR += src/ip/chip/V0

ifeq ($(CORE),c66x)
SRCS_COMMON += csl_chip.c
INCDIR += . src/ip/chip/V0
endif

endif

