# invoke SourceDir generated makefile for edma3_drv_bios6_tda2xx_m4_c1_st_sample.pem4
edma3_drv_bios6_tda2xx_m4_c1_st_sample.pem4: .libraries,edma3_drv_bios6_tda2xx_m4_c1_st_sample.pem4
.libraries,edma3_drv_bios6_tda2xx_m4_c1_st_sample.pem4: package/cfg/edma3_drv_bios6_tda2xx_m4_c1_st_sample_pem4.xdl
	$(MAKE) -f package/cfg/edma3_drv_bios6_tda2xx_m4_c1_st_sample_pem4.src/makefile.libs

clean::
	$(MAKE) -f package/cfg/edma3_drv_bios6_tda2xx_m4_c1_st_sample_pem4.src/makefile.libs clean

