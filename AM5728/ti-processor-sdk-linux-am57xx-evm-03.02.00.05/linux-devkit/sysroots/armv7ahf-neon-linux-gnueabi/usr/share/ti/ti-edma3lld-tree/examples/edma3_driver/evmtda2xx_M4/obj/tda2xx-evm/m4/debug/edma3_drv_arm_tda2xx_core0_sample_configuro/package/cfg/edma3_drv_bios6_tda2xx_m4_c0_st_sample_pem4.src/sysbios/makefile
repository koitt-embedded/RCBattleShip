
XOPTS = -I"/home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/am57xx-evm/usr/share/ti/ti-xdctools-tree/packages/" -Dxdc_target_types__=/home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/am57xx-evm/usr/share/ti/ti-sysbios-tree/packages/ti/targets/arm/elf/std.h -Dxdc_target_name__=M4

vpath % /home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/am57xx-evm/usr/share/ti/ti-sysbios-tree/packages/ti/sysbios/
vpath %.c /home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/am57xx-evm/usr/share/ti/ti-xdctools-tree/packages/

CCOPTS    = --endian=little -mv7M4 --float_support=vfplib --abi=eabi -q -ms --opt_for_speed=2  --program_level_compile -o3 -g --optimize_with_debug  -Dti_sysbios_knl_Task_minimizeLatency__D=FALSE -Dti_sysbios_family_arm_ducati_GateDualCore_enableStats__D=FALSE -Dti_sysbios_knl_Clock_stopCheckNext__D=FALSE -Dti_sysbios_family_arm_m3_Hwi_enableException__D=TRUE -Dti_sysbios_family_arm_m3_Hwi_disablePriority__D=16U -Dti_sysbios_family_arm_m3_Hwi_numSparseInterrupts__D=0U -Dti_sysbios_family_arm_ducati_Core_initStackFlag__D=TRUE

XDC_ROOT  = /home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/am57xx-evm/usr/share/ti/ti-xdctools-tree/packages/

BIOS_ROOT = /home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/am57xx-evm/usr/share/ti/ti-sysbios-tree/packages/ti/sysbios/

BIOS_DEFS =  -Dti_sysbios_BIOS_swiEnabled__D=TRUE -Dti_sysbios_BIOS_taskEnabled__D=TRUE -Dti_sysbios_BIOS_clockEnabled__D=TRUE -Dti_sysbios_BIOS_runtimeCreatesEnabled__D=TRUE -Dti_sysbios_knl_Task_moduleStateCheckFlag__D=FALSE -Dti_sysbios_knl_Task_objectCheckFlag__D=FALSE -Dti_sysbios_hal_Hwi_DISABLE_ALL_HOOKS -Dti_sysbios_knl_Swi_DISABLE_ALL_HOOKS -Dti_sysbios_BIOS_smpEnabled__D=FALSE -Dti_sysbios_Build_useHwiMacros -Dti_sysbios_knl_Swi_numPriorities__D=16 -Dti_sysbios_knl_Task_deleteTerminatedTasks__D=FALSE -Dti_sysbios_knl_Task_numPriorities__D=16 -Dti_sysbios_knl_Task_checkStackFlag__D=FALSE -Dti_sysbios_knl_Task_initStackFlag__D=FALSE -Dti_sysbios_knl_Task_DISABLE_ALL_HOOKS -Dti_sysbios_knl_Clock_TICK_SOURCE=ti_sysbios_knl_Clock_TickSource_TIMER -Dti_sysbios_knl_Clock_TICK_MODE=ti_sysbios_knl_Clock_TickMode_PERIODIC -Dti_sysbios_hal_Core_delegate_getId=ti_sysbios_family_arm_ducati_Core_getId__E -Dti_sysbios_hal_Core_delegate_interruptCore=ti_sysbios_family_arm_ducati_Core_interruptCore__E -Dti_sysbios_hal_Core_delegate_lock=ti_sysbios_family_arm_ducati_Core_lock__E -Dti_sysbios_hal_Core_delegate_unlock=ti_sysbios_family_arm_ducati_Core_unlock__E -Dti_sysbios_hal_Core_numCores__D=2 -Dti_sysbios_family_arm_ducati_Core_numCores__D=2 -Dti_sysbios_utils_Load_taskEnabled__D=TRUE -Dti_sysbios_utils_Load_swiEnabled__D=FALSE -Dti_sysbios_utils_Load_hwiEnabled__D=FALSE -Dti_sysbios_family_arm_m3_Hwi_dispatcherSwiSupport__D=TRUE -Dti_sysbios_family_arm_m3_Hwi_dispatcherTaskSupport__D=TRUE -Dti_sysbios_family_arm_m3_Hwi_dispatcherAutoNestingSupport__D=TRUE -Dti_sysbios_family_arm_m3_Hwi_dispatcherIrpTrackingSupport__D=TRUE -Dti_sysbios_knl_Semaphore_supportsEvents__D=FALSE -Dti_sysbios_knl_Semaphore_supportsPriority__D=TRUE

BIOS_INC  = -I"/home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/am57xx-evm/usr/share/ti/ti-sysbios-tree/packages/"

TARGET_INC = -I"/home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/am57xx-evm/usr/share/ti/ti-sysbios-tree/packages/"

INCS = $(BIOS_INC) $(TARGET_INC)  

CC = /home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/x86_64-linux/usr/share/ti/ti-cgt-arm/bin/armcl -c $(CCOPTS) -I /home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/x86_64-linux/usr/share/ti/ti-cgt-arm/include
ASM = /home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/x86_64-linux/usr/share/ti/ti-cgt-arm/bin/armcl -c $(CCOPTS) -I /home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/x86_64-linux/usr/share/ti/ti-cgt-arm/include
AR = /home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/x86_64-linux/usr/share/ti/ti-cgt-arm/bin/armar rq

DEL = rm -f
CP = cp -f

define RM
	$(if $(wildcard $1),$(DEL) $1,:)
endef

define ASSEMBLE
	@echo asmem4 $< ...
	@$(ASM) $(BIOS_DEFS) $(XOPTS) $(INCS) $<
endef

all: sysbios.aem4

m3_Hwi_asm.obj: family/arm/m3/Hwi_asm.sv7M makefile
	@-$(call RM, $@)
	$(ASSEMBLE) --output_file=m3_Hwi_asm.obj

m3_Hwi_asm_switch.obj: family/arm/m3/Hwi_asm_switch.sv7M makefile
	@-$(call RM, $@)
	$(ASSEMBLE) --output_file=m3_Hwi_asm_switch.obj

m3_IntrinsicsSupport_asm.obj: family/arm/m3/IntrinsicsSupport_asm.sv7M makefile
	@-$(call RM, $@)
	$(ASSEMBLE) --output_file=m3_IntrinsicsSupport_asm.obj

m3_TaskSupport_asm.obj: family/arm/m3/TaskSupport_asm.sv7M makefile
	@-$(call RM, $@)
	$(ASSEMBLE) --output_file=m3_TaskSupport_asm.obj

ducati_Core_asm.obj: family/arm/ducati/Core_asm.sv7M makefile
	@-$(call RM, $@)
	$(ASSEMBLE) --output_file=ducati_Core_asm.obj


BIOS.obj: BIOS.c knl/Clock.c knl/Idle.c knl/Intrinsics.c knl/Queue.c knl/Semaphore.c knl/Swi.c knl/Swi_andn.c knl/Task.c hal/Cache.c hal/Hwi.c hal/Hwi_stack.c hal/Hwi_startup.c family/arm/m3/Hwi.c family/arm/m3/TaskSupport.c family/shared/vayu/IntXbar.c family/arm/ducati/Core.c family/arm/ducati/GateDualCore.c family/arm/ducati/Timer.c hal/unicache/Cache.c hal/ammu/AMMU.c gates/GateHwi.c gates/GateMutex.c heaps/HeapMem.c makefile
	@-$(call RM, $@)
	@echo clem4 $< ...
	@$(CC) $(BIOS_DEFS) $(XOPTS) $(INCS) \
	$(BIOS_ROOT)BIOS.c \
	$(BIOS_ROOT)knl/Clock.c \
	$(BIOS_ROOT)knl/Idle.c \
	$(BIOS_ROOT)knl/Intrinsics.c \
	$(BIOS_ROOT)knl/Queue.c \
	$(BIOS_ROOT)knl/Semaphore.c \
	$(BIOS_ROOT)knl/Swi.c \
	$(BIOS_ROOT)knl/Swi_andn.c \
	$(BIOS_ROOT)knl/Task.c \
	$(BIOS_ROOT)hal/Cache.c \
	$(BIOS_ROOT)hal/Hwi.c \
	$(BIOS_ROOT)hal/Hwi_stack.c \
	$(BIOS_ROOT)hal/Hwi_startup.c \
	$(BIOS_ROOT)family/arm/m3/Hwi.c \
	$(BIOS_ROOT)family/arm/m3/TaskSupport.c \
	$(BIOS_ROOT)family/shared/vayu/IntXbar.c \
	$(BIOS_ROOT)family/arm/ducati/Core.c \
	$(BIOS_ROOT)family/arm/ducati/GateDualCore.c \
	$(BIOS_ROOT)family/arm/ducati/Timer.c \
	$(BIOS_ROOT)hal/unicache/Cache.c \
	$(BIOS_ROOT)hal/ammu/AMMU.c \
	$(BIOS_ROOT)gates/GateHwi.c \
	$(BIOS_ROOT)gates/GateMutex.c \
	$(BIOS_ROOT)heaps/HeapMem.c \

sysbios.aem4: BIOS.obj m3_Hwi_asm.obj m3_Hwi_asm_switch.obj m3_IntrinsicsSupport_asm.obj m3_TaskSupport_asm.obj ducati_Core_asm.obj
	@-$(call RM, $@)
	@echo arem4 $^ ...
	@$(AR) $@ $^


clean:
	@$(DEL) ../makefile.libs
	@-$(call RM, *)
