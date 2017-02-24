
ifeq ($(SOC),$(filter $(SOC), k2h k2k k2l k2e k2g c6678))

PACKAGE_SRCS_COMMON += csl_cpsgmiiAux.h  csl_cpsgmii_def.h  csl_cpsgmii.h  cslr_cpsgmii.h
PACKAGE_SRCS_COMMON += src/ip/sgmii/V0/csl_cpsgmiiAux.h src/ip/sgmii/V0/csl_cpsgmii.h  src/ip/sgmii/V0/cslr_cpsgmii.h
PACKAGE_SRCS_COMMON += src/ip/sgmii/src_files_sgmii.mk src/ip/sgmii/V0

ifneq ($(SOC), $(filter $(SOC), k2l k2e))
  SRCS_COMMON += csl_cpsgmii.c
endif

ifneq ($(SOC), $(filter $(SOC), k2g))
  SRCS_COMMON += cslr_cpsgmii_resetread.c  
endif

SRCDIR += src/ip/sgmii/V0

ifeq ($(SOC), $(filter $(SOC), k2l k2e k2g))
  INCDIR += . src/ip/sgmii/V1
else
  INCDIR += . src/ip/sgmii/V0
endif

endif
