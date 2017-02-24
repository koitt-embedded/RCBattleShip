/******************************************************************************
 * FILE PURPOSE: CSL example module specification file.
 ******************************************************************************
 * FILE NAME: module.xs
 *
 * DESCRIPTION: 
 *  This file contains the module specification for the CSL examples .
 *
 * Copyright (C) 2008, Texas Instruments, Inc.
 *****************************************************************************/

/* Load the library utility. */
var libUtility = xdc.loadCapsule ("../build/buildlib.xs");

/**************************************************************************
 * FUNCTION NAME : modBuild
 **************************************************************************
 * DESCRIPTION   :
 *  The function is used to add all the source files in the example 
 *  directory into the package.
 **************************************************************************/
function modBuild() 
{
    Pkg.otherFiles[Pkg.otherFiles.length++] = "./example/dcan/dcanLoopback";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "./example/edma/edma_polled_mode_test";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "./example/gpio/gpio_toggle";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "./example/mailbox/mailbox_sender_receiver_app";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "./example/mmu/mmu_tlb_twl";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "./example/mmcsd/mmc_raw_access";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "./example/pcie/write_loopback";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "./example/timer/timer_app";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "./example/qspi/qspi_test";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "./example/wdtimer/wdtimer_reset_app";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "./example/spinlock/spinlock_test";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "./example/uart/uart_test";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "./example/i2c/i2c_led_blink";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "./example/utils";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "./example/lnk_a15.cmd";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "./example/lnk_dsp.cmd";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "./example/lnk_m4.cmd";
}
