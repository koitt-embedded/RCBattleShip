/*
 * Do not modify this file; it is automatically generated from the template
 * linkcmd.xdt in the ti.targets.elf package and will be overwritten.
 */

/*
 * put '"'s around paths because, without this, the linker
 * considers '-' as minus operator, not a file name character.
 */


-l"/home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/work/am57xx_evm-linux-gnueabi/edma3-lld-rtos/2.12.02.26-r0.0/git/examples/edma3_driver/evmtda2xx_M4/obj/tda2xx-evm/m4/debug/edma3_drv_arm_tda2xx_core0_sample_configuro/package/cfg/edma3_drv_bios6_tda2xx_m4_c0_st_sample_pem4.oem4"
-l"/home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/work/am57xx_evm-linux-gnueabi/edma3-lld-rtos/2.12.02.26-r0.0/git/examples/edma3_driver/evmtda2xx_M4/obj/tda2xx-evm/m4/debug/edma3_drv_arm_tda2xx_core0_sample_configuro/package/cfg/edma3_drv_bios6_tda2xx_m4_c0_st_sample_pem4.src/sysbios/sysbios.aem4"
-l"/home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/am57xx-evm/usr/share/ti/ti-sysbios-tree/packages/ti/targets/arm/rtsarm/lib/ti.targets.arm.rtsarm.aem4"
-l"/home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/am57xx-evm/usr/share/ti/ti-sysbios-tree/packages/ti/targets/arm/rtsarm/lib/boot.aem4"
-l"/home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/am57xx-evm/usr/share/ti/ti-sysbios-tree/packages/ti/targets/arm/rtsarm/lib/auto_init.aem4"

--retain="*(xdc.meta)"

/* C6x Elf symbols */
--symbol_map __TI_STACK_SIZE=__STACK_SIZE
--symbol_map __TI_STACK_BASE=__stack
--symbol_map _stack=__stack



--args 0x0
-heap  0x0
-stack 0x4000

MEMORY
{
    L2_ROM : org = 0x0, len = 0x4000
    L2_RAM : org = 0x20000000, len = 0x10000
    OCMC_RAM1 : org = 0x40300000, len = 0x80000
    OCMC_RAM2 : org = 0x40400000, len = 0x100000
    OCMC_RAM3 : org = 0x40500000, len = 0x100000
    CODE_CORE_IPU1_0 (RWX) : org = 0x84000000, len = 0x1000000
    PRIVATE_DATA_CORE_IPU1_0 (RWX) : org = 0x85000000, len = 0x1800000
    HDVPSS_DESCRIPTOR_NON_CACHED (RWX) : org = 0xa1800000, len = 0x800000
    SHARED_MEM (RWX) : org = 0xa2000000, len = 0x1000000
    SHARED_FRAME_BUFFER (RWX) : org = 0x8a000000, len = 0x4000000
    SHARED_CTRL (RWX) : org = 0xa0000000, len = 0x1000000
    SHARED_LOG_MEM (RWX) : org = 0xa1000000, len = 0x700000
}

/*
 * Linker command file contributions from all loaded packages:
 */

/* Content from xdc.services.global (null): */

/* Content from xdc (null): */

/* Content from xdc.corevers (null): */

/* Content from xdc.shelf (null): */

/* Content from xdc.services.spec (null): */

/* Content from xdc.services.intern.xsr (null): */

/* Content from xdc.services.intern.gen (null): */

/* Content from xdc.services.intern.cmd (null): */

/* Content from xdc.bld (null): */

/* Content from ti.targets (null): */

/* Content from ti.targets.arm.elf (null): */

/* Content from xdc.rov (null): */

/* Content from xdc.runtime (null): */

/* Content from ti.targets.arm.rtsarm (null): */

/* Content from ti.sysbios.interfaces (null): */

/* Content from ti.sysbios.family (null): */

/* Content from ti.sysbios.family.arm (ti/sysbios/family/arm/linkcmd.xdt): */
--retain "*(.vecs)"

/* Content from xdc.services.getset (null): */

/* Content from ti.sysbios.hal.ammu (ti/sysbios/hal/ammu/linkcmd.xdt): */
ti_sysbios_hal_ammu_AMMU_mmu = 1073743872;

/* Content from ti.sysbios.rts (ti/sysbios/rts/linkcmd.xdt): */

/* Content from xdc.runtime.knl (null): */

/* Content from ti.catalog (null): */

/* Content from ti.catalog.arm.cortexm4 (null): */

/* Content from ti.catalog.peripherals.hdvicp2 (null): */

/* Content from xdc.platform (null): */

/* Content from xdc.cfg (null): */

/* Content from ti.catalog.arp32 (null): */

/* Content from ti.catalog.c6000 (null): */

/* Content from ti.catalog.arm.cortexa15 (null): */

/* Content from ti.platforms.evmDRA7XX (null): */

/* Content from ti.sysbios (null): */

/* Content from ti.sysbios.hal (null): */

/* Content from ti.sysbios.family.arm.ducati (ti/sysbios/family/arm/ducati/linkcmd.xdt): */
--diag_suppress=10063
--entry_point=ti_sysbios_family_arm_ducati_Core_reset
ti_sysbios_family_arm_ducati_CTM_ctm = 0x40000400;

/* Content from ti.sysbios.family.arm.m3 (ti/sysbios/family/arm/m3/linkcmd.xdt): */
-u _c_int00
ti_sysbios_family_arm_m3_Hwi_nvic = 0xe000e000;

/* Content from ti.sysbios.knl (null): */

/* Content from ti.sysbios.family.shared.vayu (null): */

/* Content from ti.sysbios.hal.unicache (ti/sysbios/hal/unicache/linkcmd.xdt): */
ti_sysbios_hal_unicache_Cache_cache = 1073741824;

/* Content from ti.sysbios.gates (null): */

/* Content from ti.sysbios.xdcruntime (null): */

/* Content from ti.sysbios.heaps (null): */

/* Content from ti.sysbios.family.arm.ducati.smp (null): */

/* Content from ti.sysbios.utils (null): */

/* Content from edma3_drv_arm_tda2xx_core0_sample_configuro (null): */

/* Content from xdc.services.io (null): */


/*
 * symbolic aliases for static instance objects
 */
xdc_runtime_Startup__EXECFXN__C = 1;
xdc_runtime_Startup__RESETFXN__C = 1;

SECTIONS
{
    .text: load >> CODE_CORE_IPU1_0
    .stack: load > PRIVATE_DATA_CORE_IPU1_0
    GROUP: load > PRIVATE_DATA_CORE_IPU1_0
    {
        .bss:
        .neardata:
        .rodata:
    }
    .binit: load > CODE_CORE_IPU1_0
    .cinit: load > CODE_CORE_IPU1_0
    .init_array: load > CODE_CORE_IPU1_0
    .const: load >> PRIVATE_DATA_CORE_IPU1_0
    .data: load >> PRIVATE_DATA_CORE_IPU1_0
    .fardata: load >> PRIVATE_DATA_CORE_IPU1_0
    .switch: load >> PRIVATE_DATA_CORE_IPU1_0
    .sysmem: load > PRIVATE_DATA_CORE_IPU1_0
    .far: load >> PRIVATE_DATA_CORE_IPU1_0
    .args: load > CODE_CORE_IPU1_0 align = 0x4, fill = 0 {_argsize = 0x0; }
    .cio: load >> PRIVATE_DATA_CORE_IPU1_0
    .ARM.exidx: load > PRIVATE_DATA_CORE_IPU1_0
    .ARM.extab: load >> PRIVATE_DATA_CORE_IPU1_0
    .bootVecs:  type = DSECT
    .resetVecs: load > 0x400
    .vecs: load > 0x400, type = DSECT
    .pinit: load > CODE_CORE_IPU1_0
    .systemHeap: load > PRIVATE_DATA_CORE_IPU1_0
    .stackMemory: load > PRIVATE_DATA_CORE_IPU1_0
    .bss:taskStackSection: load > PRIVATE_DATA_CORE_IPU1_0
    .bss:extMemNonCache:heap: load > HDVPSS_DESCRIPTOR_NON_CACHED
    .plt: load > PRIVATE_DATA_CORE_IPU1_0
    .my_sect_ddr: load > PRIVATE_DATA_CORE_IPU1_0
    .ducatiBoot: load > 0x0
    .ducatiGates: load > 0x7f0, type = NOINIT
    xdc.meta: load > PRIVATE_DATA_CORE_IPU1_0, type = COPY

}
