#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = ti.targets.arm.elf.Arm9{1,0,15.12,1
#
ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.oe9.dep
package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.oe9.dep: ;
endif

package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.oe9: | .interfaces
package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.oe9: package/package_ti.sdo.edma3.drv.sample.c lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample.ae9.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle9 $< ...
	$(ti.targets.arm.elf.Arm9.rootDir)/bin/armcl -c  -qq -pdsw225 -me -mv5e --abi=eabi -eo.oe9 -ea.se9   -D_DEBUG_=1 -DCHIP_AM437X -Dxdc_target_name__=Arm9 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_15_12_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.Arm9.rootDir)/include  -fs=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/package -fr=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/package -s oe9 $< -C   -qq -pdsw225 -me -mv5e --abi=eabi -eo.oe9 -ea.se9   -D_DEBUG_=1 -DCHIP_AM437X -Dxdc_target_name__=Arm9 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_15_12_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.Arm9.rootDir)/include  -fs=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/package -fr=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.oe9: export C_DIR=
package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.oe9: PATH:=$(ti.targets.arm.elf.Arm9.rootDir)/bin/:$(PATH)

package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.se9: | .interfaces
package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.se9: package/package_ti.sdo.edma3.drv.sample.c lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample.ae9.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle9 -n $< ...
	$(ti.targets.arm.elf.Arm9.rootDir)/bin/armcl -c -n -s --symdebug:none -qq -pdsw225 -me -mv5e --abi=eabi -eo.oe9 -ea.se9   -D_DEBUG_=1 -DCHIP_AM437X -Dxdc_target_name__=Arm9 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_15_12_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.Arm9.rootDir)/include  -fs=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/package -fr=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/package -s oe9 $< -C  -n -s --symdebug:none -qq -pdsw225 -me -mv5e --abi=eabi -eo.oe9 -ea.se9   -D_DEBUG_=1 -DCHIP_AM437X -Dxdc_target_name__=Arm9 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_15_12_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.Arm9.rootDir)/include  -fs=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/package -fr=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.se9: export C_DIR=
package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.se9: PATH:=$(ti.targets.arm.elf.Arm9.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_am437x_cfg.oe9.dep
package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_am437x_cfg.oe9.dep: ;
endif

package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_am437x_cfg.oe9: | .interfaces
package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_am437x_cfg.oe9: src/platforms/sample_am437x_cfg.c lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample.ae9.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle9 $< ...
	$(ti.targets.arm.elf.Arm9.rootDir)/bin/armcl -c  -qq -pdsw225 -me -mv5e --abi=eabi -eo.oe9 -ea.se9   -D_DEBUG_=1 -DCHIP_AM437X -Dxdc_target_name__=Arm9 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_15_12_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.Arm9.rootDir)/include  -fs=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms -s oe9 $< -C   -qq -pdsw225 -me -mv5e --abi=eabi -eo.oe9 -ea.se9   -D_DEBUG_=1 -DCHIP_AM437X -Dxdc_target_name__=Arm9 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_15_12_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.Arm9.rootDir)/include  -fs=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_am437x_cfg.oe9: export C_DIR=
package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_am437x_cfg.oe9: PATH:=$(ti.targets.arm.elf.Arm9.rootDir)/bin/:$(PATH)

package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_am437x_cfg.se9: | .interfaces
package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_am437x_cfg.se9: src/platforms/sample_am437x_cfg.c lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample.ae9.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle9 -n $< ...
	$(ti.targets.arm.elf.Arm9.rootDir)/bin/armcl -c -n -s --symdebug:none -qq -pdsw225 -me -mv5e --abi=eabi -eo.oe9 -ea.se9   -D_DEBUG_=1 -DCHIP_AM437X -Dxdc_target_name__=Arm9 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_15_12_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.Arm9.rootDir)/include  -fs=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms -s oe9 $< -C  -n -s --symdebug:none -qq -pdsw225 -me -mv5e --abi=eabi -eo.oe9 -ea.se9   -D_DEBUG_=1 -DCHIP_AM437X -Dxdc_target_name__=Arm9 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_15_12_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.Arm9.rootDir)/include  -fs=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_am437x_cfg.se9: export C_DIR=
package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_am437x_cfg.se9: PATH:=$(ti.targets.arm.elf.Arm9.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_am437x_arm_int_reg.oe9.dep
package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_am437x_arm_int_reg.oe9.dep: ;
endif

package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_am437x_arm_int_reg.oe9: | .interfaces
package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_am437x_arm_int_reg.oe9: src/platforms/sample_am437x_arm_int_reg.c lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample.ae9.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle9 $< ...
	$(ti.targets.arm.elf.Arm9.rootDir)/bin/armcl -c  -qq -pdsw225 -me -mv5e --abi=eabi -eo.oe9 -ea.se9   -D_DEBUG_=1 -DCHIP_AM437X -Dxdc_target_name__=Arm9 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_15_12_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.Arm9.rootDir)/include  -fs=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms -s oe9 $< -C   -qq -pdsw225 -me -mv5e --abi=eabi -eo.oe9 -ea.se9   -D_DEBUG_=1 -DCHIP_AM437X -Dxdc_target_name__=Arm9 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_15_12_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.Arm9.rootDir)/include  -fs=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_am437x_arm_int_reg.oe9: export C_DIR=
package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_am437x_arm_int_reg.oe9: PATH:=$(ti.targets.arm.elf.Arm9.rootDir)/bin/:$(PATH)

package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_am437x_arm_int_reg.se9: | .interfaces
package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_am437x_arm_int_reg.se9: src/platforms/sample_am437x_arm_int_reg.c lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample.ae9.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle9 -n $< ...
	$(ti.targets.arm.elf.Arm9.rootDir)/bin/armcl -c -n -s --symdebug:none -qq -pdsw225 -me -mv5e --abi=eabi -eo.oe9 -ea.se9   -D_DEBUG_=1 -DCHIP_AM437X -Dxdc_target_name__=Arm9 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_15_12_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.Arm9.rootDir)/include  -fs=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms -s oe9 $< -C  -n -s --symdebug:none -qq -pdsw225 -me -mv5e --abi=eabi -eo.oe9 -ea.se9   -D_DEBUG_=1 -DCHIP_AM437X -Dxdc_target_name__=Arm9 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_15_12_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.Arm9.rootDir)/include  -fs=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_am437x_arm_int_reg.se9: export C_DIR=
package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_am437x_arm_int_reg.se9: PATH:=$(ti.targets.arm.elf.Arm9.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/sample_arm_cs.oe9.dep
package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/sample_arm_cs.oe9.dep: ;
endif

package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/sample_arm_cs.oe9: | .interfaces
package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/sample_arm_cs.oe9: src/sample_arm_cs.c lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample.ae9.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle9 $< ...
	$(ti.targets.arm.elf.Arm9.rootDir)/bin/armcl -c  -qq -pdsw225 -me -mv5e --abi=eabi -eo.oe9 -ea.se9   -D_DEBUG_=1 -DCHIP_AM437X -Dxdc_target_name__=Arm9 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_15_12_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.Arm9.rootDir)/include  -fs=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src -s oe9 $< -C   -qq -pdsw225 -me -mv5e --abi=eabi -eo.oe9 -ea.se9   -D_DEBUG_=1 -DCHIP_AM437X -Dxdc_target_name__=Arm9 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_15_12_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.Arm9.rootDir)/include  -fs=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/sample_arm_cs.oe9: export C_DIR=
package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/sample_arm_cs.oe9: PATH:=$(ti.targets.arm.elf.Arm9.rootDir)/bin/:$(PATH)

package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/sample_arm_cs.se9: | .interfaces
package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/sample_arm_cs.se9: src/sample_arm_cs.c lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample.ae9.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle9 -n $< ...
	$(ti.targets.arm.elf.Arm9.rootDir)/bin/armcl -c -n -s --symdebug:none -qq -pdsw225 -me -mv5e --abi=eabi -eo.oe9 -ea.se9   -D_DEBUG_=1 -DCHIP_AM437X -Dxdc_target_name__=Arm9 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_15_12_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.Arm9.rootDir)/include  -fs=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src -s oe9 $< -C  -n -s --symdebug:none -qq -pdsw225 -me -mv5e --abi=eabi -eo.oe9 -ea.se9   -D_DEBUG_=1 -DCHIP_AM437X -Dxdc_target_name__=Arm9 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_15_12_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.Arm9.rootDir)/include  -fs=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/sample_arm_cs.se9: export C_DIR=
package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/sample_arm_cs.se9: PATH:=$(ti.targets.arm.elf.Arm9.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/sample_arm_init.oe9.dep
package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/sample_arm_init.oe9.dep: ;
endif

package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/sample_arm_init.oe9: | .interfaces
package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/sample_arm_init.oe9: src/sample_arm_init.c lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample.ae9.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle9 $< ...
	$(ti.targets.arm.elf.Arm9.rootDir)/bin/armcl -c  -qq -pdsw225 -me -mv5e --abi=eabi -eo.oe9 -ea.se9   -D_DEBUG_=1 -DCHIP_AM437X -Dxdc_target_name__=Arm9 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_15_12_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.Arm9.rootDir)/include  -fs=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src -s oe9 $< -C   -qq -pdsw225 -me -mv5e --abi=eabi -eo.oe9 -ea.se9   -D_DEBUG_=1 -DCHIP_AM437X -Dxdc_target_name__=Arm9 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_15_12_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.Arm9.rootDir)/include  -fs=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/sample_arm_init.oe9: export C_DIR=
package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/sample_arm_init.oe9: PATH:=$(ti.targets.arm.elf.Arm9.rootDir)/bin/:$(PATH)

package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/sample_arm_init.se9: | .interfaces
package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/sample_arm_init.se9: src/sample_arm_init.c lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample.ae9.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle9 -n $< ...
	$(ti.targets.arm.elf.Arm9.rootDir)/bin/armcl -c -n -s --symdebug:none -qq -pdsw225 -me -mv5e --abi=eabi -eo.oe9 -ea.se9   -D_DEBUG_=1 -DCHIP_AM437X -Dxdc_target_name__=Arm9 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_15_12_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.Arm9.rootDir)/include  -fs=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src -s oe9 $< -C  -n -s --symdebug:none -qq -pdsw225 -me -mv5e --abi=eabi -eo.oe9 -ea.se9   -D_DEBUG_=1 -DCHIP_AM437X -Dxdc_target_name__=Arm9 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_15_12_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.Arm9.rootDir)/include  -fs=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/sample_arm_init.se9: export C_DIR=
package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/sample_arm_init.se9: PATH:=$(ti.targets.arm.elf.Arm9.rootDir)/bin/:$(PATH)

clean,e9 ::
	-$(RM) package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.oe9
	-$(RM) package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_am437x_cfg.oe9
	-$(RM) package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_am437x_arm_int_reg.oe9
	-$(RM) package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/sample_arm_cs.oe9
	-$(RM) package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/sample_arm_init.oe9
	-$(RM) package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.se9
	-$(RM) package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_am437x_cfg.se9
	-$(RM) package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_am437x_arm_int_reg.se9
	-$(RM) package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/sample_arm_cs.se9
	-$(RM) package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/sample_arm_init.se9

lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample.ae9: package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.oe9 package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_am437x_cfg.oe9 package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_am437x_arm_int_reg.oe9 package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/sample_arm_cs.oe9 package/lib/lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample/src/sample_arm_init.oe9 lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample.ae9.mak

clean::
	-$(RM) lib/am437x-evm/arm9/debug/ti.sdo.edma3.drv.sample.ae9.mak
