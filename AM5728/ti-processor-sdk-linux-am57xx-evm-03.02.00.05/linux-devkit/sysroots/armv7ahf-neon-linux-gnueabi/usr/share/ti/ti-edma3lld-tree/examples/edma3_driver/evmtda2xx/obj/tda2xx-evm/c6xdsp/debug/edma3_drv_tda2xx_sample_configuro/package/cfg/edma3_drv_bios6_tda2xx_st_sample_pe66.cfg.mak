# invoke SourceDir generated makefile for edma3_drv_bios6_tda2xx_st_sample.pe66
edma3_drv_bios6_tda2xx_st_sample.pe66: .libraries,edma3_drv_bios6_tda2xx_st_sample.pe66
.libraries,edma3_drv_bios6_tda2xx_st_sample.pe66: package/cfg/edma3_drv_bios6_tda2xx_st_sample_pe66.xdl
	$(MAKE) -f package/cfg/edma3_drv_bios6_tda2xx_st_sample_pe66.src/makefile.libs

clean::
	$(MAKE) -f package/cfg/edma3_drv_bios6_tda2xx_st_sample_pe66.src/makefile.libs clean

