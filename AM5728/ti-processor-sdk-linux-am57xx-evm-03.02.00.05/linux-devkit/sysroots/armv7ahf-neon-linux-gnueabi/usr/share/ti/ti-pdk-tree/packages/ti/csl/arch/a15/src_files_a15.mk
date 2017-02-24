
ifeq ($(SOC),$(filter $(SOC),tda2xx dra75x tda2ex am572x am571x k2h k2k k2l k2e k2g))

  PACKAGE_SRCS_COMMON += csl_a15.h csl_armGic.h csl_armGicAux.h arch/a15 src/ip/arm_gic/V0
  ifeq ($(ARCH),armv7a)
    SRCDIR += ./arch/a15/src ./arch/a15/V0
    INCDIR += ./arch/a15 ./arch/a15/V0

    ifeq ($(SOC),$(filter $(SOC),tda2xx dra75x tda2ex am572x am571x))
      SRCS_COMMON += mpu_wugen.c interrupt.c
    endif

    SRCS_COMMON += csl_a15.c csl_a15AsmUtils.c
    SRCS_ASM_COMMON += csl_a15Asm.asm
  endif

endif
