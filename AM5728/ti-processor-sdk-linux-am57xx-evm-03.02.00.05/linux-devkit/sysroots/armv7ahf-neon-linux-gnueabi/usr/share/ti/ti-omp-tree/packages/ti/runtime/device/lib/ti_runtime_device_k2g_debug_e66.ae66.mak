#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = ti.targets.elf.C66{1,0,8.1,0
#
ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/ti_runtime_device_k2g_debug_e66/package/package_ti.runtime.device.oe66.dep
package/lib/lib/ti_runtime_device_k2g_debug_e66/package/package_ti.runtime.device.oe66.dep: ;
endif

package/lib/lib/ti_runtime_device_k2g_debug_e66/package/package_ti.runtime.device.oe66: | .interfaces
package/lib/lib/ti_runtime_device_k2g_debug_e66/package/package_ti.runtime.device.oe66: package/package_ti.runtime.device.c lib/ti_runtime_device_k2g_debug_e66.ae66.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle66 $< ...
	$(ti.targets.elf.C66.rootDir)/bin/cl6x -c  --gcc --mem_model:data=far --verbose_diagnostics --display_error_number --diag_error=225 -k --diag_error=9 --diag_warning=179 --diag_remark=188 --diag_suppress=880  -mv6600 --abi=eabi -eo.oe66 -ea.se66  -DTI_66AK2G -DDEVICE_K2G=1 -DTOMP_TRACE_LEVEL=0 -DTOMP_CHECK_LEVEL=1 -Dxdc_target_name__=C66 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_ti_runtime_device_k2g_debug -Dxdc_bld__vers_1_0_8_1_0 -g --opt_level=0 --gen_func_subsections=on   $(XDCINCS) -I$(ti.targets.elf.C66.rootDir)/include -fs=./package/lib/lib/ti_runtime_device_k2g_debug_e66/package -fr=./package/lib/lib/ti_runtime_device_k2g_debug_e66/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/ti_runtime_device_k2g_debug_e66/package -s oe66 $< -C   --gcc --mem_model:data=far --verbose_diagnostics --display_error_number --diag_error=225 -k --diag_error=9 --diag_warning=179 --diag_remark=188 --diag_suppress=880  -mv6600 --abi=eabi -eo.oe66 -ea.se66  -DTI_66AK2G -DDEVICE_K2G=1 -DTOMP_TRACE_LEVEL=0 -DTOMP_CHECK_LEVEL=1 -Dxdc_target_name__=C66 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_ti_runtime_device_k2g_debug -Dxdc_bld__vers_1_0_8_1_0 -g --opt_level=0 --gen_func_subsections=on   $(XDCINCS) -I$(ti.targets.elf.C66.rootDir)/include -fs=./package/lib/lib/ti_runtime_device_k2g_debug_e66/package -fr=./package/lib/lib/ti_runtime_device_k2g_debug_e66/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/ti_runtime_device_k2g_debug_e66/package/package_ti.runtime.device.oe66: export C_DIR=
package/lib/lib/ti_runtime_device_k2g_debug_e66/package/package_ti.runtime.device.oe66: PATH:=$(ti.targets.elf.C66.rootDir)/bin/:$(PATH)

package/lib/lib/ti_runtime_device_k2g_debug_e66/package/package_ti.runtime.device.se66: | .interfaces
package/lib/lib/ti_runtime_device_k2g_debug_e66/package/package_ti.runtime.device.se66: package/package_ti.runtime.device.c lib/ti_runtime_device_k2g_debug_e66.ae66.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle66 -n $< ...
	$(ti.targets.elf.C66.rootDir)/bin/cl6x -c -n -s --symdebug:none --gcc --mem_model:data=far --verbose_diagnostics --display_error_number --diag_error=225 -k --diag_error=9 --diag_warning=179 --diag_remark=188 --diag_suppress=880  -mv6600 --abi=eabi -eo.oe66 -ea.se66  -DTI_66AK2G -DDEVICE_K2G=1 -DTOMP_TRACE_LEVEL=0 -DTOMP_CHECK_LEVEL=1 -Dxdc_target_name__=C66 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_ti_runtime_device_k2g_debug -Dxdc_bld__vers_1_0_8_1_0 -g --opt_level=0 --gen_func_subsections=on   $(XDCINCS) -I$(ti.targets.elf.C66.rootDir)/include -fs=./package/lib/lib/ti_runtime_device_k2g_debug_e66/package -fr=./package/lib/lib/ti_runtime_device_k2g_debug_e66/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/ti_runtime_device_k2g_debug_e66/package -s oe66 $< -C  -n -s --symdebug:none --gcc --mem_model:data=far --verbose_diagnostics --display_error_number --diag_error=225 -k --diag_error=9 --diag_warning=179 --diag_remark=188 --diag_suppress=880  -mv6600 --abi=eabi -eo.oe66 -ea.se66  -DTI_66AK2G -DDEVICE_K2G=1 -DTOMP_TRACE_LEVEL=0 -DTOMP_CHECK_LEVEL=1 -Dxdc_target_name__=C66 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_ti_runtime_device_k2g_debug -Dxdc_bld__vers_1_0_8_1_0 -g --opt_level=0 --gen_func_subsections=on   $(XDCINCS) -I$(ti.targets.elf.C66.rootDir)/include -fs=./package/lib/lib/ti_runtime_device_k2g_debug_e66/package -fr=./package/lib/lib/ti_runtime_device_k2g_debug_e66/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/ti_runtime_device_k2g_debug_e66/package/package_ti.runtime.device.se66: export C_DIR=
package/lib/lib/ti_runtime_device_k2g_debug_e66/package/package_ti.runtime.device.se66: PATH:=$(ti.targets.elf.C66.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/ti_runtime_device_k2g_debug_e66/src/qmss_device.oe66.dep
package/lib/lib/ti_runtime_device_k2g_debug_e66/src/qmss_device.oe66.dep: ;
endif

package/lib/lib/ti_runtime_device_k2g_debug_e66/src/qmss_device.oe66: | .interfaces
package/lib/lib/ti_runtime_device_k2g_debug_e66/src/qmss_device.oe66: src/qmss_device.c lib/ti_runtime_device_k2g_debug_e66.ae66.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle66 $< ...
	$(ti.targets.elf.C66.rootDir)/bin/cl6x -c  --gcc --mem_model:data=far --verbose_diagnostics --display_error_number --diag_error=225 -k --diag_error=9 --diag_warning=179 --diag_remark=188 --diag_suppress=880  -mv6600 --abi=eabi -eo.oe66 -ea.se66  -DTI_66AK2G -DDEVICE_K2G=1 -DTOMP_TRACE_LEVEL=0 -DTOMP_CHECK_LEVEL=1 -Dxdc_target_name__=C66 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_ti_runtime_device_k2g_debug -Dxdc_bld__vers_1_0_8_1_0 -g --opt_level=0 --gen_func_subsections=on   $(XDCINCS) -I$(ti.targets.elf.C66.rootDir)/include -fs=./package/lib/lib/ti_runtime_device_k2g_debug_e66/src -fr=./package/lib/lib/ti_runtime_device_k2g_debug_e66/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/ti_runtime_device_k2g_debug_e66/src -s oe66 $< -C   --gcc --mem_model:data=far --verbose_diagnostics --display_error_number --diag_error=225 -k --diag_error=9 --diag_warning=179 --diag_remark=188 --diag_suppress=880  -mv6600 --abi=eabi -eo.oe66 -ea.se66  -DTI_66AK2G -DDEVICE_K2G=1 -DTOMP_TRACE_LEVEL=0 -DTOMP_CHECK_LEVEL=1 -Dxdc_target_name__=C66 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_ti_runtime_device_k2g_debug -Dxdc_bld__vers_1_0_8_1_0 -g --opt_level=0 --gen_func_subsections=on   $(XDCINCS) -I$(ti.targets.elf.C66.rootDir)/include -fs=./package/lib/lib/ti_runtime_device_k2g_debug_e66/src -fr=./package/lib/lib/ti_runtime_device_k2g_debug_e66/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/ti_runtime_device_k2g_debug_e66/src/qmss_device.oe66: export C_DIR=
package/lib/lib/ti_runtime_device_k2g_debug_e66/src/qmss_device.oe66: PATH:=$(ti.targets.elf.C66.rootDir)/bin/:$(PATH)

package/lib/lib/ti_runtime_device_k2g_debug_e66/src/qmss_device.se66: | .interfaces
package/lib/lib/ti_runtime_device_k2g_debug_e66/src/qmss_device.se66: src/qmss_device.c lib/ti_runtime_device_k2g_debug_e66.ae66.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle66 -n $< ...
	$(ti.targets.elf.C66.rootDir)/bin/cl6x -c -n -s --symdebug:none --gcc --mem_model:data=far --verbose_diagnostics --display_error_number --diag_error=225 -k --diag_error=9 --diag_warning=179 --diag_remark=188 --diag_suppress=880  -mv6600 --abi=eabi -eo.oe66 -ea.se66  -DTI_66AK2G -DDEVICE_K2G=1 -DTOMP_TRACE_LEVEL=0 -DTOMP_CHECK_LEVEL=1 -Dxdc_target_name__=C66 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_ti_runtime_device_k2g_debug -Dxdc_bld__vers_1_0_8_1_0 -g --opt_level=0 --gen_func_subsections=on   $(XDCINCS) -I$(ti.targets.elf.C66.rootDir)/include -fs=./package/lib/lib/ti_runtime_device_k2g_debug_e66/src -fr=./package/lib/lib/ti_runtime_device_k2g_debug_e66/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/ti_runtime_device_k2g_debug_e66/src -s oe66 $< -C  -n -s --symdebug:none --gcc --mem_model:data=far --verbose_diagnostics --display_error_number --diag_error=225 -k --diag_error=9 --diag_warning=179 --diag_remark=188 --diag_suppress=880  -mv6600 --abi=eabi -eo.oe66 -ea.se66  -DTI_66AK2G -DDEVICE_K2G=1 -DTOMP_TRACE_LEVEL=0 -DTOMP_CHECK_LEVEL=1 -Dxdc_target_name__=C66 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_ti_runtime_device_k2g_debug -Dxdc_bld__vers_1_0_8_1_0 -g --opt_level=0 --gen_func_subsections=on   $(XDCINCS) -I$(ti.targets.elf.C66.rootDir)/include -fs=./package/lib/lib/ti_runtime_device_k2g_debug_e66/src -fr=./package/lib/lib/ti_runtime_device_k2g_debug_e66/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/ti_runtime_device_k2g_debug_e66/src/qmss_device.se66: export C_DIR=
package/lib/lib/ti_runtime_device_k2g_debug_e66/src/qmss_device.se66: PATH:=$(ti.targets.elf.C66.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/ti_runtime_device_k2g_debug_e66/src/osal.oe66.dep
package/lib/lib/ti_runtime_device_k2g_debug_e66/src/osal.oe66.dep: ;
endif

package/lib/lib/ti_runtime_device_k2g_debug_e66/src/osal.oe66: | .interfaces
package/lib/lib/ti_runtime_device_k2g_debug_e66/src/osal.oe66: src/osal.c lib/ti_runtime_device_k2g_debug_e66.ae66.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle66 $< ...
	$(ti.targets.elf.C66.rootDir)/bin/cl6x -c  --gcc --mem_model:data=far --verbose_diagnostics --display_error_number --diag_error=225 -k --diag_error=9 --diag_warning=179 --diag_remark=188 --diag_suppress=880  -mv6600 --abi=eabi -eo.oe66 -ea.se66  -DTI_66AK2G -DDEVICE_K2G=1 -DTOMP_TRACE_LEVEL=0 -DTOMP_CHECK_LEVEL=1 -Dxdc_target_name__=C66 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_ti_runtime_device_k2g_debug -Dxdc_bld__vers_1_0_8_1_0 -g --opt_level=0 --gen_func_subsections=on   $(XDCINCS) -I$(ti.targets.elf.C66.rootDir)/include -fs=./package/lib/lib/ti_runtime_device_k2g_debug_e66/src -fr=./package/lib/lib/ti_runtime_device_k2g_debug_e66/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/ti_runtime_device_k2g_debug_e66/src -s oe66 $< -C   --gcc --mem_model:data=far --verbose_diagnostics --display_error_number --diag_error=225 -k --diag_error=9 --diag_warning=179 --diag_remark=188 --diag_suppress=880  -mv6600 --abi=eabi -eo.oe66 -ea.se66  -DTI_66AK2G -DDEVICE_K2G=1 -DTOMP_TRACE_LEVEL=0 -DTOMP_CHECK_LEVEL=1 -Dxdc_target_name__=C66 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_ti_runtime_device_k2g_debug -Dxdc_bld__vers_1_0_8_1_0 -g --opt_level=0 --gen_func_subsections=on   $(XDCINCS) -I$(ti.targets.elf.C66.rootDir)/include -fs=./package/lib/lib/ti_runtime_device_k2g_debug_e66/src -fr=./package/lib/lib/ti_runtime_device_k2g_debug_e66/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/ti_runtime_device_k2g_debug_e66/src/osal.oe66: export C_DIR=
package/lib/lib/ti_runtime_device_k2g_debug_e66/src/osal.oe66: PATH:=$(ti.targets.elf.C66.rootDir)/bin/:$(PATH)

package/lib/lib/ti_runtime_device_k2g_debug_e66/src/osal.se66: | .interfaces
package/lib/lib/ti_runtime_device_k2g_debug_e66/src/osal.se66: src/osal.c lib/ti_runtime_device_k2g_debug_e66.ae66.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle66 -n $< ...
	$(ti.targets.elf.C66.rootDir)/bin/cl6x -c -n -s --symdebug:none --gcc --mem_model:data=far --verbose_diagnostics --display_error_number --diag_error=225 -k --diag_error=9 --diag_warning=179 --diag_remark=188 --diag_suppress=880  -mv6600 --abi=eabi -eo.oe66 -ea.se66  -DTI_66AK2G -DDEVICE_K2G=1 -DTOMP_TRACE_LEVEL=0 -DTOMP_CHECK_LEVEL=1 -Dxdc_target_name__=C66 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_ti_runtime_device_k2g_debug -Dxdc_bld__vers_1_0_8_1_0 -g --opt_level=0 --gen_func_subsections=on   $(XDCINCS) -I$(ti.targets.elf.C66.rootDir)/include -fs=./package/lib/lib/ti_runtime_device_k2g_debug_e66/src -fr=./package/lib/lib/ti_runtime_device_k2g_debug_e66/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/ti_runtime_device_k2g_debug_e66/src -s oe66 $< -C  -n -s --symdebug:none --gcc --mem_model:data=far --verbose_diagnostics --display_error_number --diag_error=225 -k --diag_error=9 --diag_warning=179 --diag_remark=188 --diag_suppress=880  -mv6600 --abi=eabi -eo.oe66 -ea.se66  -DTI_66AK2G -DDEVICE_K2G=1 -DTOMP_TRACE_LEVEL=0 -DTOMP_CHECK_LEVEL=1 -Dxdc_target_name__=C66 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_ti_runtime_device_k2g_debug -Dxdc_bld__vers_1_0_8_1_0 -g --opt_level=0 --gen_func_subsections=on   $(XDCINCS) -I$(ti.targets.elf.C66.rootDir)/include -fs=./package/lib/lib/ti_runtime_device_k2g_debug_e66/src -fr=./package/lib/lib/ti_runtime_device_k2g_debug_e66/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/ti_runtime_device_k2g_debug_e66/src/osal.se66: export C_DIR=
package/lib/lib/ti_runtime_device_k2g_debug_e66/src/osal.se66: PATH:=$(ti.targets.elf.C66.rootDir)/bin/:$(PATH)

clean,e66 ::
	-$(RM) package/lib/lib/ti_runtime_device_k2g_debug_e66/package/package_ti.runtime.device.oe66
	-$(RM) package/lib/lib/ti_runtime_device_k2g_debug_e66/src/qmss_device.oe66
	-$(RM) package/lib/lib/ti_runtime_device_k2g_debug_e66/src/osal.oe66
	-$(RM) package/lib/lib/ti_runtime_device_k2g_debug_e66/package/package_ti.runtime.device.se66
	-$(RM) package/lib/lib/ti_runtime_device_k2g_debug_e66/src/qmss_device.se66
	-$(RM) package/lib/lib/ti_runtime_device_k2g_debug_e66/src/osal.se66

lib/ti_runtime_device_k2g_debug_e66.ae66: package/lib/lib/ti_runtime_device_k2g_debug_e66/package/package_ti.runtime.device.oe66 package/lib/lib/ti_runtime_device_k2g_debug_e66/src/qmss_device.oe66 package/lib/lib/ti_runtime_device_k2g_debug_e66/src/osal.oe66 lib/ti_runtime_device_k2g_debug_e66.ae66.mak

clean::
	-$(RM) lib/ti_runtime_device_k2g_debug_e66.ae66.mak
