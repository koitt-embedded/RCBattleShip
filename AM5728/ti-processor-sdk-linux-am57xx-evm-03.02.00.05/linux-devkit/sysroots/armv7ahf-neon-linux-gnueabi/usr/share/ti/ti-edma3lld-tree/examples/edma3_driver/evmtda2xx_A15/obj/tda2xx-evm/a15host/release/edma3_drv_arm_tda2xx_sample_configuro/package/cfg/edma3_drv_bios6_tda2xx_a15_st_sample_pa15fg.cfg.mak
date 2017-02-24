# invoke SourceDir generated makefile for edma3_drv_bios6_tda2xx_a15_st_sample.pa15fg
edma3_drv_bios6_tda2xx_a15_st_sample.pa15fg: .libraries,edma3_drv_bios6_tda2xx_a15_st_sample.pa15fg
.libraries,edma3_drv_bios6_tda2xx_a15_st_sample.pa15fg: package/cfg/edma3_drv_bios6_tda2xx_a15_st_sample_pa15fg.xdl
	$(MAKE) -f package/cfg/edma3_drv_bios6_tda2xx_a15_st_sample_pa15fg.src/makefile.libs

clean::
	$(MAKE) -f package/cfg/edma3_drv_bios6_tda2xx_a15_st_sample_pa15fg.src/makefile.libs clean

