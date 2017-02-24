## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,a15fg linker.cmd package/cfg/edma3_drv_bios6_tda2xx_a15_st_sample_pa15fg.oa15fg

# To simplify configuro usage in makefiles:
#     o create a generic linker command file name 
#     o set modification times of compiler.opt* files to be greater than
#       or equal to the generated config header
#
linker.cmd: package/cfg/edma3_drv_bios6_tda2xx_a15_st_sample_pa15fg.xdl
	$(SED) 's"^\"\(package/cfg/edma3_drv_bios6_tda2xx_a15_st_sample_pa15fgcfg.cmd\)\"$""\"/home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/work/am57xx_evm-linux-gnueabi/edma3-lld-rtos/2.12.02.26-r0.0/git/examples/edma3_driver/evmtda2xx_A15/obj/tda2xx-evm/a15host/debug/edma3_drv_arm_tda2xx_sample_configuro/\1\""' package/cfg/edma3_drv_bios6_tda2xx_a15_st_sample_pa15fg.xdl > $@
	-$(SETDATE) -r:max package/cfg/edma3_drv_bios6_tda2xx_a15_st_sample_pa15fg.h compiler.opt compiler.opt.defs
