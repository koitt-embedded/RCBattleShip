/*
 * Do not modify this file; it is automatically generated from the template
 * linkcmd.xdt in the ti.targets.elf package and will be overwritten.
 */

/*
 * put '"'s around paths because, without this, the linker
 * considers '-' as minus operator, not a file name character.
 */


-l"/home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/work/am57xx_evm-linux-gnueabi/edma3-lld-rtos/2.12.02.26-r0.0/git/examples/edma3_driver/evmtda2xx/obj/tda2xx-evm/c6xdsp/release/edma3_drv_tda2xx_sample_configuro/package/cfg/edma3_drv_bios6_tda2xx_st_sample_pe66.oe66"
-l"/home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/work/am57xx_evm-linux-gnueabi/edma3-lld-rtos/2.12.02.26-r0.0/git/examples/edma3_driver/evmtda2xx/obj/tda2xx-evm/c6xdsp/release/edma3_drv_tda2xx_sample_configuro/package/cfg/edma3_drv_bios6_tda2xx_st_sample_pe66.src/sysbios/sysbios.ae66"
-l"/home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/am57xx-evm/usr/share/ti/ti-sysbios-tree/packages/ti/targets/rts6000/lib/ti.targets.rts6000.ae66"
-l"/home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/am57xx-evm/usr/share/ti/ti-sysbios-tree/packages/ti/targets/rts6000/lib/boot.ae66"

--retain="*(xdc.meta)"


--args 0x0
-heap  0x0
-stack 0x1000

MEMORY
{
    L2SRAM (RWX) : org = 0x800000, len = 0x40000
    OCMC_RAM1 (RWX) : org = 0x40300000, len = 0x80000
    OCMC_RAM2 (RWX) : org = 0x40400000, len = 0x100000
    OCMC_RAM3 (RWX) : org = 0x40500000, len = 0x100000
    CODE_CORE_DSP1 (RWX) : org = 0x83100000, len = 0x700000
    PRIVATE_DATA_CORE_DSP1 (RWX) : org = 0x83800000, len = 0x800000
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

/* Content from ti.targets.elf (null): */

/* Content from xdc.rov (null): */

/* Content from xdc.runtime (null): */

/* Content from ti.targets.rts6000 (null): */

/* Content from ti.sysbios.interfaces (null): */

/* Content from ti.sysbios.family (null): */

/* Content from xdc.services.getset (null): */

/* Content from ti.sysbios.family.c62 (null): */

/* Content from xdc.runtime.knl (null): */

/* Content from ti.catalog.c6000 (null): */

/* Content from ti.catalog (null): */

/* Content from ti.catalog.peripherals.hdvicp2 (null): */

/* Content from xdc.platform (null): */

/* Content from xdc.cfg (null): */

/* Content from ti.catalog.arp32 (null): */

/* Content from ti.catalog.arm.cortexm4 (null): */

/* Content from ti.catalog.arm.cortexa15 (null): */

/* Content from ti.platforms.evmDRA7XX (null): */

/* Content from ti.sysbios.hal (null): */

/* Content from ti.sysbios.knl (null): */

/* Content from ti.sysbios.family.c64p (ti/sysbios/family/c64p/linkcmd.xdt): */

/* Content from ti.sysbios.family.c66 (ti/sysbios/family/c66/linkcmd.xdt): */
ti_sysbios_family_c66_Cache_l1dSize = 32768;
ti_sysbios_family_c66_Cache_l1pSize = 32768;
ti_sysbios_family_c66_Cache_l2Size = 0;

/* Content from ti.sysbios (null): */

/* Content from ti.sysbios.rts (ti/sysbios/rts/linkcmd.xdt): */

/* Content from ti.sysbios.rts.ti (ti/sysbios/rts/ti/linkcmd.xdt): */

/* Content from ti.sysbios.timers.dmtimer (null): */

/* Content from ti.sysbios.family.shared.vayu (null): */

/* Content from ti.sysbios.gates (null): */

/* Content from ti.sysbios.xdcruntime (null): */

/* Content from ti.sysbios.heaps (null): */

/* Content from ti.sysbios.utils (null): */

/* Content from edma3_drv_tda2xx_sample_configuro (null): */

/* Content from xdc.services.io (null): */


/*
 * symbolic aliases for static instance objects
 */
xdc_runtime_Startup__EXECFXN__C = 1;
xdc_runtime_Startup__RESETFXN__C = 1;

SECTIONS
{
    .text: load >> CODE_CORE_DSP1
    .ti.decompress: load > CODE_CORE_DSP1
    .stack: load > PRIVATE_DATA_CORE_DSP1
    GROUP: load > PRIVATE_DATA_CORE_DSP1
    {
        .bss:
        .neardata:
        .rodata:
    }
    .cinit: load > CODE_CORE_DSP1
    .pinit: load >> PRIVATE_DATA_CORE_DSP1
    .init_array: load > PRIVATE_DATA_CORE_DSP1
    .const: load >> PRIVATE_DATA_CORE_DSP1
    .data: load >> PRIVATE_DATA_CORE_DSP1
    .fardata: load >> PRIVATE_DATA_CORE_DSP1
    .switch: load >> PRIVATE_DATA_CORE_DSP1
    .sysmem: load > PRIVATE_DATA_CORE_DSP1
    .far: load >> CODE_CORE_DSP1
    .args: load > CODE_CORE_DSP1 align = 0x4, fill = 0 {_argsize = 0x0; }
    .cio: load >> PRIVATE_DATA_CORE_DSP1
    .ti.handler_table: load > PRIVATE_DATA_CORE_DSP1
    .c6xabi.exidx: load > PRIVATE_DATA_CORE_DSP1
    .c6xabi.extab: load >> PRIVATE_DATA_CORE_DSP1
    .vecs: load > CODE_CORE_DSP1
    .text:_c_int00: load > CODE_CORE_DSP1 align = 0x400
    .systemHeap: load > PRIVATE_DATA_CORE_DSP1
    .stackMemory: load > PRIVATE_DATA_CORE_DSP1
    .bss:taskStackSection: load > PRIVATE_DATA_CORE_DSP1
    .plt: load > PRIVATE_DATA_CORE_DSP1
    .my_sect_iram: load > PRIVATE_DATA_CORE_DSP1
    .my_sect_ddr: load > PRIVATE_DATA_CORE_DSP1
    xdc.meta: load > PRIVATE_DATA_CORE_DSP1, type = COPY

}
