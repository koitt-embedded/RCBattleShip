#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = ti.targets.C64P_big_endian{1,0,8.1,0
#
ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.o64Pe.dep
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.o64Pe.dep: ;
endif

package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.o64Pe: | .interfaces
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.o64Pe: package/package_ti.sdo.edma3.drv.sample.c lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample.a64Pe.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64Pe $< ...
	$(ti.targets.C64P_big_endian.rootDir)/bin/cl6x -c  -qq -pdsw225 -me -mv64p -eo.o64Pe -ea.s64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_1_0 -O2  $(XDCINCS) -I$(ti.targets.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/package -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/package -s o64Pe $< -C   -qq -pdsw225 -me -mv64p -eo.o64Pe -ea.s64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_1_0 -O2  $(XDCINCS) -I$(ti.targets.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/package -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.o64Pe: export C_DIR=
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.o64Pe: PATH:=$(ti.targets.C64P_big_endian.rootDir)/bin/:$(PATH)

package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.s64Pe: | .interfaces
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.s64Pe: package/package_ti.sdo.edma3.drv.sample.c lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample.a64Pe.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64Pe -n $< ...
	$(ti.targets.C64P_big_endian.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -me -mv64p -eo.o64Pe -ea.s64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_1_0 -O2  $(XDCINCS) -I$(ti.targets.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/package -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/package -s o64Pe $< -C  -n -s --symdebug:none -qq -pdsw225 -me -mv64p -eo.o64Pe -ea.s64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_1_0 -O2  $(XDCINCS) -I$(ti.targets.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/package -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.s64Pe: export C_DIR=
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.s64Pe: PATH:=$(ti.targets.C64P_big_endian.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6472_cfg.o64Pe.dep
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6472_cfg.o64Pe.dep: ;
endif

package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6472_cfg.o64Pe: | .interfaces
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6472_cfg.o64Pe: src/platforms/sample_c6472_cfg.c lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample.a64Pe.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64Pe $< ...
	$(ti.targets.C64P_big_endian.rootDir)/bin/cl6x -c  -qq -pdsw225 -me -mv64p -eo.o64Pe -ea.s64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_1_0 -O2  $(XDCINCS) -I$(ti.targets.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms -s o64Pe $< -C   -qq -pdsw225 -me -mv64p -eo.o64Pe -ea.s64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_1_0 -O2  $(XDCINCS) -I$(ti.targets.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6472_cfg.o64Pe: export C_DIR=
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6472_cfg.o64Pe: PATH:=$(ti.targets.C64P_big_endian.rootDir)/bin/:$(PATH)

package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6472_cfg.s64Pe: | .interfaces
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6472_cfg.s64Pe: src/platforms/sample_c6472_cfg.c lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample.a64Pe.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64Pe -n $< ...
	$(ti.targets.C64P_big_endian.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -me -mv64p -eo.o64Pe -ea.s64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_1_0 -O2  $(XDCINCS) -I$(ti.targets.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms -s o64Pe $< -C  -n -s --symdebug:none -qq -pdsw225 -me -mv64p -eo.o64Pe -ea.s64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_1_0 -O2  $(XDCINCS) -I$(ti.targets.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6472_cfg.s64Pe: export C_DIR=
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6472_cfg.s64Pe: PATH:=$(ti.targets.C64P_big_endian.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6472_int_reg.o64Pe.dep
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6472_int_reg.o64Pe.dep: ;
endif

package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6472_int_reg.o64Pe: | .interfaces
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6472_int_reg.o64Pe: src/platforms/sample_c6472_int_reg.c lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample.a64Pe.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64Pe $< ...
	$(ti.targets.C64P_big_endian.rootDir)/bin/cl6x -c  -qq -pdsw225 -me -mv64p -eo.o64Pe -ea.s64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_1_0 -O2  $(XDCINCS) -I$(ti.targets.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms -s o64Pe $< -C   -qq -pdsw225 -me -mv64p -eo.o64Pe -ea.s64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_1_0 -O2  $(XDCINCS) -I$(ti.targets.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6472_int_reg.o64Pe: export C_DIR=
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6472_int_reg.o64Pe: PATH:=$(ti.targets.C64P_big_endian.rootDir)/bin/:$(PATH)

package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6472_int_reg.s64Pe: | .interfaces
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6472_int_reg.s64Pe: src/platforms/sample_c6472_int_reg.c lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample.a64Pe.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64Pe -n $< ...
	$(ti.targets.C64P_big_endian.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -me -mv64p -eo.o64Pe -ea.s64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_1_0 -O2  $(XDCINCS) -I$(ti.targets.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms -s o64Pe $< -C  -n -s --symdebug:none -qq -pdsw225 -me -mv64p -eo.o64Pe -ea.s64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_1_0 -O2  $(XDCINCS) -I$(ti.targets.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6472_int_reg.s64Pe: export C_DIR=
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6472_int_reg.s64Pe: PATH:=$(ti.targets.C64P_big_endian.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/sample_cs.o64Pe.dep
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/sample_cs.o64Pe.dep: ;
endif

package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/sample_cs.o64Pe: | .interfaces
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/sample_cs.o64Pe: src/sample_cs.c lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample.a64Pe.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64Pe $< ...
	$(ti.targets.C64P_big_endian.rootDir)/bin/cl6x -c  -qq -pdsw225 -me -mv64p -eo.o64Pe -ea.s64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_1_0 -O2  $(XDCINCS) -I$(ti.targets.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src -s o64Pe $< -C   -qq -pdsw225 -me -mv64p -eo.o64Pe -ea.s64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_1_0 -O2  $(XDCINCS) -I$(ti.targets.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/sample_cs.o64Pe: export C_DIR=
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/sample_cs.o64Pe: PATH:=$(ti.targets.C64P_big_endian.rootDir)/bin/:$(PATH)

package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/sample_cs.s64Pe: | .interfaces
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/sample_cs.s64Pe: src/sample_cs.c lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample.a64Pe.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64Pe -n $< ...
	$(ti.targets.C64P_big_endian.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -me -mv64p -eo.o64Pe -ea.s64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_1_0 -O2  $(XDCINCS) -I$(ti.targets.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src -s o64Pe $< -C  -n -s --symdebug:none -qq -pdsw225 -me -mv64p -eo.o64Pe -ea.s64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_1_0 -O2  $(XDCINCS) -I$(ti.targets.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/sample_cs.s64Pe: export C_DIR=
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/sample_cs.s64Pe: PATH:=$(ti.targets.C64P_big_endian.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/sample_init.o64Pe.dep
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/sample_init.o64Pe.dep: ;
endif

package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/sample_init.o64Pe: | .interfaces
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/sample_init.o64Pe: src/sample_init.c lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample.a64Pe.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64Pe $< ...
	$(ti.targets.C64P_big_endian.rootDir)/bin/cl6x -c  -qq -pdsw225 -me -mv64p -eo.o64Pe -ea.s64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_1_0 -O2  $(XDCINCS) -I$(ti.targets.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src -s o64Pe $< -C   -qq -pdsw225 -me -mv64p -eo.o64Pe -ea.s64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_1_0 -O2  $(XDCINCS) -I$(ti.targets.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/sample_init.o64Pe: export C_DIR=
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/sample_init.o64Pe: PATH:=$(ti.targets.C64P_big_endian.rootDir)/bin/:$(PATH)

package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/sample_init.s64Pe: | .interfaces
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/sample_init.s64Pe: src/sample_init.c lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample.a64Pe.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64Pe -n $< ...
	$(ti.targets.C64P_big_endian.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -me -mv64p -eo.o64Pe -ea.s64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_1_0 -O2  $(XDCINCS) -I$(ti.targets.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src -s o64Pe $< -C  -n -s --symdebug:none -qq -pdsw225 -me -mv64p -eo.o64Pe -ea.s64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_1_0 -O2  $(XDCINCS) -I$(ti.targets.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/sample_init.s64Pe: export C_DIR=
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/sample_init.s64Pe: PATH:=$(ti.targets.C64P_big_endian.rootDir)/bin/:$(PATH)

clean,64Pe ::
	-$(RM) package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.o64Pe
	-$(RM) package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6472_cfg.o64Pe
	-$(RM) package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6472_int_reg.o64Pe
	-$(RM) package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/sample_cs.o64Pe
	-$(RM) package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/sample_init.o64Pe
	-$(RM) package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.s64Pe
	-$(RM) package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6472_cfg.s64Pe
	-$(RM) package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6472_int_reg.s64Pe
	-$(RM) package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/sample_cs.s64Pe
	-$(RM) package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/sample_init.s64Pe

lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample.a64Pe: package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.o64Pe package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6472_cfg.o64Pe package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6472_int_reg.o64Pe package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/sample_cs.o64Pe package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample/src/sample_init.o64Pe lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample.a64Pe.mak

clean::
	-$(RM) lib/c6472-evm/64p/release/ti.sdo.edma3.drv.sample.a64Pe.mak
