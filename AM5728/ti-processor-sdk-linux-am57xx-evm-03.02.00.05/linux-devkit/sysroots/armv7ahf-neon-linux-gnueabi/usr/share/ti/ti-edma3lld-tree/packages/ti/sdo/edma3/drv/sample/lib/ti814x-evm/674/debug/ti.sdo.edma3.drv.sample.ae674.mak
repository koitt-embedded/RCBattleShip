#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = ti.targets.elf.C674{1,0,8.1,0
#
ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.oe674.dep
package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.oe674.dep: ;
endif

package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.oe674: | .interfaces
package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.oe674: package/package_ti.sdo.edma3.drv.sample.c lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample.ae674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle674 $< ...
	$(ti.targets.elf.C674.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -mi10 -mo  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_8_1_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/package -fr=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/package -s oe674 $< -C   -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -mi10 -mo  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_8_1_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/package -fr=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.oe674: export C_DIR=
package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.oe674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.se674: | .interfaces
package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.se674: package/package_ti.sdo.edma3.drv.sample.c lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample.ae674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle674 -n $< ...
	$(ti.targets.elf.C674.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -mi10 -mo  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_8_1_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/package -fr=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/package -s oe674 $< -C  -n -s --symdebug:none -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -mi10 -mo  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_8_1_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/package -fr=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.se674: export C_DIR=
package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.se674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_ti814x_cfg.oe674.dep
package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_ti814x_cfg.oe674.dep: ;
endif

package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_ti814x_cfg.oe674: | .interfaces
package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_ti814x_cfg.oe674: src/platforms/sample_ti814x_cfg.c lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample.ae674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle674 $< ...
	$(ti.targets.elf.C674.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -mi10 -mo  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_8_1_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms -s oe674 $< -C   -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -mi10 -mo  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_8_1_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_ti814x_cfg.oe674: export C_DIR=
package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_ti814x_cfg.oe674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_ti814x_cfg.se674: | .interfaces
package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_ti814x_cfg.se674: src/platforms/sample_ti814x_cfg.c lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample.ae674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle674 -n $< ...
	$(ti.targets.elf.C674.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -mi10 -mo  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_8_1_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms -s oe674 $< -C  -n -s --symdebug:none -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -mi10 -mo  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_8_1_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_ti814x_cfg.se674: export C_DIR=
package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_ti814x_cfg.se674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_ti814x_int_reg.oe674.dep
package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_ti814x_int_reg.oe674.dep: ;
endif

package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_ti814x_int_reg.oe674: | .interfaces
package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_ti814x_int_reg.oe674: src/platforms/sample_ti814x_int_reg.c lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample.ae674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle674 $< ...
	$(ti.targets.elf.C674.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -mi10 -mo  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_8_1_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms -s oe674 $< -C   -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -mi10 -mo  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_8_1_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_ti814x_int_reg.oe674: export C_DIR=
package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_ti814x_int_reg.oe674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_ti814x_int_reg.se674: | .interfaces
package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_ti814x_int_reg.se674: src/platforms/sample_ti814x_int_reg.c lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample.ae674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle674 -n $< ...
	$(ti.targets.elf.C674.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -mi10 -mo  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_8_1_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms -s oe674 $< -C  -n -s --symdebug:none -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -mi10 -mo  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_8_1_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_ti814x_int_reg.se674: export C_DIR=
package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_ti814x_int_reg.se674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/sample_cs.oe674.dep
package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/sample_cs.oe674.dep: ;
endif

package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/sample_cs.oe674: | .interfaces
package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/sample_cs.oe674: src/sample_cs.c lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample.ae674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle674 $< ...
	$(ti.targets.elf.C674.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -mi10 -mo  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_8_1_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src -s oe674 $< -C   -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -mi10 -mo  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_8_1_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/sample_cs.oe674: export C_DIR=
package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/sample_cs.oe674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/sample_cs.se674: | .interfaces
package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/sample_cs.se674: src/sample_cs.c lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample.ae674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle674 -n $< ...
	$(ti.targets.elf.C674.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -mi10 -mo  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_8_1_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src -s oe674 $< -C  -n -s --symdebug:none -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -mi10 -mo  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_8_1_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/sample_cs.se674: export C_DIR=
package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/sample_cs.se674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/sample_init.oe674.dep
package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/sample_init.oe674.dep: ;
endif

package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/sample_init.oe674: | .interfaces
package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/sample_init.oe674: src/sample_init.c lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample.ae674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle674 $< ...
	$(ti.targets.elf.C674.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -mi10 -mo  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_8_1_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src -s oe674 $< -C   -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -mi10 -mo  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_8_1_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/sample_init.oe674: export C_DIR=
package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/sample_init.oe674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/sample_init.se674: | .interfaces
package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/sample_init.se674: src/sample_init.c lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample.ae674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle674 -n $< ...
	$(ti.targets.elf.C674.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -mi10 -mo  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_8_1_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src -s oe674 $< -C  -n -s --symdebug:none -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -mi10 -mo  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_8_1_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/sample_init.se674: export C_DIR=
package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/sample_init.se674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

clean,e674 ::
	-$(RM) package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.oe674
	-$(RM) package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_ti814x_cfg.oe674
	-$(RM) package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_ti814x_int_reg.oe674
	-$(RM) package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/sample_cs.oe674
	-$(RM) package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/sample_init.oe674
	-$(RM) package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.se674
	-$(RM) package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_ti814x_cfg.se674
	-$(RM) package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_ti814x_int_reg.se674
	-$(RM) package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/sample_cs.se674
	-$(RM) package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/sample_init.se674

lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample.ae674: package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.oe674 package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_ti814x_cfg.oe674 package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_ti814x_int_reg.oe674 package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/sample_cs.oe674 package/lib/lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample/src/sample_init.oe674 lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample.ae674.mak

clean::
	-$(RM) lib/ti814x-evm/674/debug/ti.sdo.edma3.drv.sample.ae674.mak
