#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = ti.targets.elf.C64P_big_endian{1,0,8.1,0
#
ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.oe64Pe.dep
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.oe64Pe.dep: ;
endif

package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.oe64Pe: | .interfaces
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.oe64Pe: package/package_ti.sdo.edma3.rm.c lib/c6472-evm/64p/release/ti.sdo.edma3.rm.ae64Pe.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle64Pe $< ...
	$(ti.targets.elf.C64P_big_endian.rootDir)/bin/cl6x -c  -qq -pdsw225 -me -mv64p --abi=eabi -eo.oe64Pe -ea.se64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_1_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package -s oe64Pe $< -C   -qq -pdsw225 -me -mv64p --abi=eabi -eo.oe64Pe -ea.se64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_1_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.oe64Pe: export C_DIR=
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.oe64Pe: PATH:=$(ti.targets.elf.C64P_big_endian.rootDir)/bin/:$(PATH)

package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.se64Pe: | .interfaces
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.se64Pe: package/package_ti.sdo.edma3.rm.c lib/c6472-evm/64p/release/ti.sdo.edma3.rm.ae64Pe.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle64Pe -n $< ...
	$(ti.targets.elf.C64P_big_endian.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -me -mv64p --abi=eabi -eo.oe64Pe -ea.se64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_1_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package -s oe64Pe $< -C  -n -s --symdebug:none -qq -pdsw225 -me -mv64p --abi=eabi -eo.oe64Pe -ea.se64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_1_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.se64Pe: export C_DIR=
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.se64Pe: PATH:=$(ti.targets.elf.C64P_big_endian.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs/edma3_c6472_cfg.oe64Pe.dep
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs/edma3_c6472_cfg.oe64Pe.dep: ;
endif

package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs/edma3_c6472_cfg.oe64Pe: | .interfaces
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs/edma3_c6472_cfg.oe64Pe: src/configs/edma3_c6472_cfg.c lib/c6472-evm/64p/release/ti.sdo.edma3.rm.ae64Pe.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle64Pe $< ...
	$(ti.targets.elf.C64P_big_endian.rootDir)/bin/cl6x -c  -qq -pdsw225 -me -mv64p --abi=eabi -eo.oe64Pe -ea.se64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_1_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs -s oe64Pe $< -C   -qq -pdsw225 -me -mv64p --abi=eabi -eo.oe64Pe -ea.se64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_1_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs/edma3_c6472_cfg.oe64Pe: export C_DIR=
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs/edma3_c6472_cfg.oe64Pe: PATH:=$(ti.targets.elf.C64P_big_endian.rootDir)/bin/:$(PATH)

package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs/edma3_c6472_cfg.se64Pe: | .interfaces
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs/edma3_c6472_cfg.se64Pe: src/configs/edma3_c6472_cfg.c lib/c6472-evm/64p/release/ti.sdo.edma3.rm.ae64Pe.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle64Pe -n $< ...
	$(ti.targets.elf.C64P_big_endian.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -me -mv64p --abi=eabi -eo.oe64Pe -ea.se64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_1_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs -s oe64Pe $< -C  -n -s --symdebug:none -qq -pdsw225 -me -mv64p --abi=eabi -eo.oe64Pe -ea.se64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_1_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs/edma3_c6472_cfg.se64Pe: export C_DIR=
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs/edma3_c6472_cfg.se64Pe: PATH:=$(ti.targets.elf.C64P_big_endian.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.oe64Pe.dep
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.oe64Pe.dep: ;
endif

package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.oe64Pe: | .interfaces
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.oe64Pe: src/edma3resmgr.c lib/c6472-evm/64p/release/ti.sdo.edma3.rm.ae64Pe.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle64Pe $< ...
	$(ti.targets.elf.C64P_big_endian.rootDir)/bin/cl6x -c  -qq -pdsw225 -me -mv64p --abi=eabi -eo.oe64Pe -ea.se64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_1_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src -s oe64Pe $< -C   -qq -pdsw225 -me -mv64p --abi=eabi -eo.oe64Pe -ea.se64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_1_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.oe64Pe: export C_DIR=
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.oe64Pe: PATH:=$(ti.targets.elf.C64P_big_endian.rootDir)/bin/:$(PATH)

package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.se64Pe: | .interfaces
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.se64Pe: src/edma3resmgr.c lib/c6472-evm/64p/release/ti.sdo.edma3.rm.ae64Pe.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle64Pe -n $< ...
	$(ti.targets.elf.C64P_big_endian.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -me -mv64p --abi=eabi -eo.oe64Pe -ea.se64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_1_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src -s oe64Pe $< -C  -n -s --symdebug:none -qq -pdsw225 -me -mv64p --abi=eabi -eo.oe64Pe -ea.se64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_1_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.se64Pe: export C_DIR=
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.se64Pe: PATH:=$(ti.targets.elf.C64P_big_endian.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.oe64Pe.dep
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.oe64Pe.dep: ;
endif

package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.oe64Pe: | .interfaces
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.oe64Pe: src/edma3_rm_gbl_data.c lib/c6472-evm/64p/release/ti.sdo.edma3.rm.ae64Pe.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle64Pe $< ...
	$(ti.targets.elf.C64P_big_endian.rootDir)/bin/cl6x -c  -qq -pdsw225 -me -mv64p --abi=eabi -eo.oe64Pe -ea.se64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_1_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src -s oe64Pe $< -C   -qq -pdsw225 -me -mv64p --abi=eabi -eo.oe64Pe -ea.se64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_1_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.oe64Pe: export C_DIR=
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.oe64Pe: PATH:=$(ti.targets.elf.C64P_big_endian.rootDir)/bin/:$(PATH)

package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.se64Pe: | .interfaces
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.se64Pe: src/edma3_rm_gbl_data.c lib/c6472-evm/64p/release/ti.sdo.edma3.rm.ae64Pe.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle64Pe -n $< ...
	$(ti.targets.elf.C64P_big_endian.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -me -mv64p --abi=eabi -eo.oe64Pe -ea.se64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_1_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src -s oe64Pe $< -C  -n -s --symdebug:none -qq -pdsw225 -me -mv64p --abi=eabi -eo.oe64Pe -ea.se64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_1_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.se64Pe: export C_DIR=
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.se64Pe: PATH:=$(ti.targets.elf.C64P_big_endian.rootDir)/bin/:$(PATH)

clean,e64Pe ::
	-$(RM) package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.oe64Pe
	-$(RM) package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs/edma3_c6472_cfg.oe64Pe
	-$(RM) package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.oe64Pe
	-$(RM) package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.oe64Pe
	-$(RM) package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.se64Pe
	-$(RM) package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs/edma3_c6472_cfg.se64Pe
	-$(RM) package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.se64Pe
	-$(RM) package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.se64Pe

lib/c6472-evm/64p/release/ti.sdo.edma3.rm.ae64Pe: package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.oe64Pe package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs/edma3_c6472_cfg.oe64Pe package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.oe64Pe package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.oe64Pe lib/c6472-evm/64p/release/ti.sdo.edma3.rm.ae64Pe.mak

clean::
	-$(RM) lib/c6472-evm/64p/release/ti.sdo.edma3.rm.ae64Pe.mak
