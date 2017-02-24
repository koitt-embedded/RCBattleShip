ifeq ($(SOC),$(filter $(SOC), am572x am571x k2h k2k k2l k2e k2g c6678 c6657))

ifeq ($(CORE),$(filter $(CORE), c66x))
PACKAGE_SRCS_COMMON += csl_intcAsmUtils.h csl_intcAux.h _csl_intc.h csl_intc.h cslr_intc.h src_files_intc.mk
SRCDIR += src/intc
INCDIR += src/intc
SRCS_COMMON += csl_intcAsmUtils.c _csl_intcCombEventDispatcher.c csl_intcExcep.c csl_intcHookIsr.c csl_intcInit.c csl_intcPlugEventHandler.c 
SRCS_COMMON += csl_intcClose.c _csl_intcDispatcher.c csl_intcGetHwStatus.c  csl_intcHwControl.c  csl_intcOpen.c  _csl_intcResource.c
SRCS_ASM_COMMON += _csl_intcIntrEnDisRes.asm  _csl_intcIsrDispatch.asm  _csl_intcNmiDummy.asm
endif

endif

