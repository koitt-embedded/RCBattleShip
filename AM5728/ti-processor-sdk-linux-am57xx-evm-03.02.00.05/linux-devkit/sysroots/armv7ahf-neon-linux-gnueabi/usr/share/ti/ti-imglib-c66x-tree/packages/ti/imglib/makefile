#*******************************************************************************
#* FILE PURPOSE: Top level makefile for Creating Kernel CCS Projects
#*******************************************************************************
#* FILE NAME: makefile
#*
#* DESCRIPTION: Defines Compiler tools paths, CCS path and rule to create and build CCS projects 
#*
#*
#* This is an auto-generated file             
#*******************************************************************************
#*
# (Mandatory) Specify where various tools are installed.

# CCSCGTVER   - Code Generation version to be used for building CCS project
export CCSCGTVER ?= 7.2.6

# CCS_INSTALL_DIR   - TI Code Composer Studio install directory
export CCSV4_INSTALL_DIR ?= C:/Program Files/Texas Instruments/ccsv4
export CCSV5_INSTALL_DIR ?= C:/Program Files/Texas Instruments/ccsv5

ifneq ($(findstring $(CCSVERSION), CCSV4.2),)
	export CCS_INSTALL_DIR ?= $(CCSV4_INSTALL_DIR)
	export ECLIPSE_CMD ?= java -jar "$(CCS_INSTALL_DIR)/eclipse/startup.jar"
endif

ifneq ($(findstring $(CCSVERSION), CCSV5),)
	export CCS_INSTALL_DIR ?= $(CCSV5_INSTALL_DIR)
	export ECLIPSE_CMD ?= "$(CCS_INSTALL_DIR)/eclipse/eclipsec.exe" -noSplash
endif

# IMGLIB_INSTALL_DIR   - IMGLIB install directory
export IMGLIB_INSTALL_DIR ?= C:/ti/imglib_c66x_3_1_1_0/packages

# Common Macros used in make

ifndef RMDIR
export RMDIR = DEL /Q /F /S
endif

ifneq ($(findstring $(SHELL), sh.exe),)
	quote = "
else
	quote = '
endif

# PHONY Targets
.PHONY: all clean cleanall 

# FORCE Targets
FORCE: 

# all rule
all: .executables
.executables: .projects
.projects:
.xdcenv.mak:

#############################################################

# Rule to Build Project IMG_boundary_16s_66_LE_COFF

#############################################################

all: ./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_COFF/Release/IMG_boundary_16s_66_LE_COFF.out

./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_boundary_16s_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_BOUNDARY_16S_66_LE_COFF_SRCIMG_BOUNDARY_16S/IMG_boundary_16s_cn.c -ccs.linkFile EXT_ROOT__IMG_BOUNDARY_16S_66_LE_COFF_SRCIMG_BOUNDARY_16S/IMG_boundary_16s_d.c -ccs.linkFile EXT_ROOT__IMG_BOUNDARY_16S_66_LE_COFF_SRCIMG_BOUNDARY_16S/IMG_boundary_16s_idat.c -ccs.linkFile EXT_ROOT__IMG_BOUNDARY_16S_66_LE_COFF_SRCIMG_BOUNDARY_16S/IMG_boundary_16s_odat.c -ccs.linkFile EXT_ROOT__IMG_BOUNDARY_16S_66_LE_COFF/IMG_boundary_16s.c -ccs.linkFile EXT_ROOT__IMG_BOUNDARY_16S_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_BOUNDARY_16S_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_BOUNDARY_16S_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_BOUNDARY_16S_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_BOUNDARY_16S_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_boundary_16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_BOUNDARY_16S_66_LE_COFF_SRCIMG_BOUNDARY_16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_boundary_16s" -ccs.definePathVariable EXT_ROOT__IMG_BOUNDARY_16S_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_BOUNDARY_16S_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_boundary_16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_BOUNDARY_16S_66_LE_COFF=.././ >> ./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_BOUNDARY_16S_66_LE_COFF_SRCIMG_BOUNDARY_16S=../../ >> ./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_BOUNDARY_16S_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_BOUNDARY_16S_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_COFF/Release/IMG_boundary_16s_66_LE_COFF.out: ./src/IMG_boundary_16s/IMG_boundary_16s.h
./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_COFF/Release/IMG_boundary_16s_66_LE_COFF.out: ./src/IMG_boundary_16s/IMG_boundary_16s_cn.c
./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_COFF/Release/IMG_boundary_16s_66_LE_COFF.out: ./src/IMG_boundary_16s/IMG_boundary_16s_cn.h
./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_COFF/Release/IMG_boundary_16s_66_LE_COFF.out: ./src/IMG_boundary_16s/IMG_boundary_16s_d.c
./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_COFF/Release/IMG_boundary_16s_66_LE_COFF.out: ./src/IMG_boundary_16s/IMG_boundary_16s_idat.c
./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_COFF/Release/IMG_boundary_16s_66_LE_COFF.out: ./src/IMG_boundary_16s/IMG_boundary_16s_odat.c
./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_COFF/Release/IMG_boundary_16s_66_LE_COFF.out: ./src/IMG_boundary_16s//c66/IMG_boundary_16s.c
./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_COFF/Release/IMG_boundary_16s_66_LE_COFF.out: ./src/IMG_boundary_16s//c66/IMG_boundary_16s.h
./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_COFF/Release/IMG_boundary_16s_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_COFF/Release/IMG_boundary_16s_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_COFF/Release/IMG_boundary_16s_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_COFF/Release/IMG_boundary_16s_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_COFF/Release/IMG_boundary_16s_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_COFF/Release/IMG_boundary_16s_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_COFF/Release/IMG_boundary_16s_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_COFF/Release/IMG_boundary_16s_66_LE_COFF.out: ./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_COFF/.project
	-@ echo Importing Project IMG_boundary_16s_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_boundary_16s_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_boundary_16s/c66/IMG_boundary_16s_66_LE_COFF"
	-@ echo Building Project IMG_boundary_16s_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_boundary_16s_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_boundary_16s_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_COFF/.settings"

	-@ echo Project IMG_boundary_16s_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_boundary_16s_66_LE_ELF

#############################################################

all: ./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_ELF/Release/IMG_boundary_16s_66_LE_ELF.out

./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_boundary_16s_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_BOUNDARY_16S_66_LE_ELF_SRCIMG_BOUNDARY_16S/IMG_boundary_16s_cn.c -ccs.linkFile EXT_ROOT__IMG_BOUNDARY_16S_66_LE_ELF_SRCIMG_BOUNDARY_16S/IMG_boundary_16s_d.c -ccs.linkFile EXT_ROOT__IMG_BOUNDARY_16S_66_LE_ELF_SRCIMG_BOUNDARY_16S/IMG_boundary_16s_idat.c -ccs.linkFile EXT_ROOT__IMG_BOUNDARY_16S_66_LE_ELF_SRCIMG_BOUNDARY_16S/IMG_boundary_16s_odat.c -ccs.linkFile EXT_ROOT__IMG_BOUNDARY_16S_66_LE_ELF/IMG_boundary_16s.c -ccs.linkFile EXT_ROOT__IMG_BOUNDARY_16S_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_BOUNDARY_16S_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_BOUNDARY_16S_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_BOUNDARY_16S_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_BOUNDARY_16S_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_boundary_16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_BOUNDARY_16S_66_LE_ELF_SRCIMG_BOUNDARY_16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_boundary_16s" -ccs.definePathVariable EXT_ROOT__IMG_BOUNDARY_16S_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_BOUNDARY_16S_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_boundary_16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_BOUNDARY_16S_66_LE_ELF=.././ >> ./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_BOUNDARY_16S_66_LE_ELF_SRCIMG_BOUNDARY_16S=../../ >> ./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_BOUNDARY_16S_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_BOUNDARY_16S_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_ELF/Release/IMG_boundary_16s_66_LE_ELF.out: ./src/IMG_boundary_16s/IMG_boundary_16s.h
./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_ELF/Release/IMG_boundary_16s_66_LE_ELF.out: ./src/IMG_boundary_16s/IMG_boundary_16s_cn.c
./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_ELF/Release/IMG_boundary_16s_66_LE_ELF.out: ./src/IMG_boundary_16s/IMG_boundary_16s_cn.h
./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_ELF/Release/IMG_boundary_16s_66_LE_ELF.out: ./src/IMG_boundary_16s/IMG_boundary_16s_d.c
./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_ELF/Release/IMG_boundary_16s_66_LE_ELF.out: ./src/IMG_boundary_16s/IMG_boundary_16s_idat.c
./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_ELF/Release/IMG_boundary_16s_66_LE_ELF.out: ./src/IMG_boundary_16s/IMG_boundary_16s_odat.c
./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_ELF/Release/IMG_boundary_16s_66_LE_ELF.out: ./src/IMG_boundary_16s//c66/IMG_boundary_16s.c
./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_ELF/Release/IMG_boundary_16s_66_LE_ELF.out: ./src/IMG_boundary_16s//c66/IMG_boundary_16s.h
./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_ELF/Release/IMG_boundary_16s_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_ELF/Release/IMG_boundary_16s_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_ELF/Release/IMG_boundary_16s_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_ELF/Release/IMG_boundary_16s_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_ELF/Release/IMG_boundary_16s_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_ELF/Release/IMG_boundary_16s_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_ELF/Release/IMG_boundary_16s_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_ELF/Release/IMG_boundary_16s_66_LE_ELF.out: ./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_ELF/.project
	-@ echo Importing Project IMG_boundary_16s_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_boundary_16s_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_boundary_16s/c66/IMG_boundary_16s_66_LE_ELF"
	-@ echo Building Project IMG_boundary_16s_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_boundary_16s_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_boundary_16s_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_ELF/.settings"

	-@ echo Project IMG_boundary_16s_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_boundary_16s//c66//IMG_boundary_16s_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_boundary_8_66_LE_COFF

#############################################################

all: ./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_COFF/Release/IMG_boundary_8_66_LE_COFF.out

./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_boundary_8_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_BOUNDARY_8_66_LE_COFF_SRCIMG_BOUNDARY_8/IMG_boundary_8_cn.c -ccs.linkFile EXT_ROOT__IMG_BOUNDARY_8_66_LE_COFF_SRCIMG_BOUNDARY_8/IMG_boundary_8_d.c -ccs.linkFile EXT_ROOT__IMG_BOUNDARY_8_66_LE_COFF_SRCIMG_BOUNDARY_8/IMG_boundary_8_idat.c -ccs.linkFile EXT_ROOT__IMG_BOUNDARY_8_66_LE_COFF_SRCIMG_BOUNDARY_8/IMG_boundary_8_odat.c -ccs.linkFile EXT_ROOT__IMG_BOUNDARY_8_66_LE_COFF/IMG_boundary_8.c -ccs.linkFile EXT_ROOT__IMG_BOUNDARY_8_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_BOUNDARY_8_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_BOUNDARY_8_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_BOUNDARY_8_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_BOUNDARY_8_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_boundary_8/c66" -ccs.definePathVariable EXT_ROOT__IMG_BOUNDARY_8_66_LE_COFF_SRCIMG_BOUNDARY_8 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_boundary_8" -ccs.definePathVariable EXT_ROOT__IMG_BOUNDARY_8_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_BOUNDARY_8_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_boundary_8.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_BOUNDARY_8_66_LE_COFF=.././ >> ./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_BOUNDARY_8_66_LE_COFF_SRCIMG_BOUNDARY_8=../../ >> ./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_BOUNDARY_8_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_BOUNDARY_8_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_COFF/Release/IMG_boundary_8_66_LE_COFF.out: ./src/IMG_boundary_8/IMG_boundary_8.h
./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_COFF/Release/IMG_boundary_8_66_LE_COFF.out: ./src/IMG_boundary_8/IMG_boundary_8_cn.c
./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_COFF/Release/IMG_boundary_8_66_LE_COFF.out: ./src/IMG_boundary_8/IMG_boundary_8_cn.h
./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_COFF/Release/IMG_boundary_8_66_LE_COFF.out: ./src/IMG_boundary_8/IMG_boundary_8_d.c
./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_COFF/Release/IMG_boundary_8_66_LE_COFF.out: ./src/IMG_boundary_8/IMG_boundary_8_idat.c
./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_COFF/Release/IMG_boundary_8_66_LE_COFF.out: ./src/IMG_boundary_8/IMG_boundary_8_odat.c
./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_COFF/Release/IMG_boundary_8_66_LE_COFF.out: ./src/IMG_boundary_8//c66/IMG_boundary_8.c
./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_COFF/Release/IMG_boundary_8_66_LE_COFF.out: ./src/IMG_boundary_8//c66/IMG_boundary_8.h
./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_COFF/Release/IMG_boundary_8_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_COFF/Release/IMG_boundary_8_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_COFF/Release/IMG_boundary_8_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_COFF/Release/IMG_boundary_8_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_COFF/Release/IMG_boundary_8_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_COFF/Release/IMG_boundary_8_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_COFF/Release/IMG_boundary_8_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_COFF/Release/IMG_boundary_8_66_LE_COFF.out: ./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_COFF/.project
	-@ echo Importing Project IMG_boundary_8_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_boundary_8_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_boundary_8/c66/IMG_boundary_8_66_LE_COFF"
	-@ echo Building Project IMG_boundary_8_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_boundary_8_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_boundary_8_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_COFF/.settings"

	-@ echo Project IMG_boundary_8_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_boundary_8_66_LE_ELF

#############################################################

all: ./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_ELF/Release/IMG_boundary_8_66_LE_ELF.out

./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_boundary_8_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_BOUNDARY_8_66_LE_ELF_SRCIMG_BOUNDARY_8/IMG_boundary_8_cn.c -ccs.linkFile EXT_ROOT__IMG_BOUNDARY_8_66_LE_ELF_SRCIMG_BOUNDARY_8/IMG_boundary_8_d.c -ccs.linkFile EXT_ROOT__IMG_BOUNDARY_8_66_LE_ELF_SRCIMG_BOUNDARY_8/IMG_boundary_8_idat.c -ccs.linkFile EXT_ROOT__IMG_BOUNDARY_8_66_LE_ELF_SRCIMG_BOUNDARY_8/IMG_boundary_8_odat.c -ccs.linkFile EXT_ROOT__IMG_BOUNDARY_8_66_LE_ELF/IMG_boundary_8.c -ccs.linkFile EXT_ROOT__IMG_BOUNDARY_8_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_BOUNDARY_8_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_BOUNDARY_8_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_BOUNDARY_8_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_BOUNDARY_8_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_boundary_8/c66" -ccs.definePathVariable EXT_ROOT__IMG_BOUNDARY_8_66_LE_ELF_SRCIMG_BOUNDARY_8 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_boundary_8" -ccs.definePathVariable EXT_ROOT__IMG_BOUNDARY_8_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_BOUNDARY_8_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_boundary_8.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_BOUNDARY_8_66_LE_ELF=.././ >> ./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_BOUNDARY_8_66_LE_ELF_SRCIMG_BOUNDARY_8=../../ >> ./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_BOUNDARY_8_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_BOUNDARY_8_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_ELF/Release/IMG_boundary_8_66_LE_ELF.out: ./src/IMG_boundary_8/IMG_boundary_8.h
./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_ELF/Release/IMG_boundary_8_66_LE_ELF.out: ./src/IMG_boundary_8/IMG_boundary_8_cn.c
./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_ELF/Release/IMG_boundary_8_66_LE_ELF.out: ./src/IMG_boundary_8/IMG_boundary_8_cn.h
./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_ELF/Release/IMG_boundary_8_66_LE_ELF.out: ./src/IMG_boundary_8/IMG_boundary_8_d.c
./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_ELF/Release/IMG_boundary_8_66_LE_ELF.out: ./src/IMG_boundary_8/IMG_boundary_8_idat.c
./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_ELF/Release/IMG_boundary_8_66_LE_ELF.out: ./src/IMG_boundary_8/IMG_boundary_8_odat.c
./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_ELF/Release/IMG_boundary_8_66_LE_ELF.out: ./src/IMG_boundary_8//c66/IMG_boundary_8.c
./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_ELF/Release/IMG_boundary_8_66_LE_ELF.out: ./src/IMG_boundary_8//c66/IMG_boundary_8.h
./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_ELF/Release/IMG_boundary_8_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_ELF/Release/IMG_boundary_8_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_ELF/Release/IMG_boundary_8_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_ELF/Release/IMG_boundary_8_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_ELF/Release/IMG_boundary_8_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_ELF/Release/IMG_boundary_8_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_ELF/Release/IMG_boundary_8_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_ELF/Release/IMG_boundary_8_66_LE_ELF.out: ./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_ELF/.project
	-@ echo Importing Project IMG_boundary_8_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_boundary_8_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_boundary_8/c66/IMG_boundary_8_66_LE_ELF"
	-@ echo Building Project IMG_boundary_8_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_boundary_8_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_boundary_8_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_ELF/.settings"

	-@ echo Project IMG_boundary_8_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_boundary_8//c66//IMG_boundary_8_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_clipping_16s_66_LE_COFF

#############################################################

all: ./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_COFF/Release/IMG_clipping_16s_66_LE_COFF.out

./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_clipping_16s_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CLIPPING_16S_66_LE_COFF_SRCIMG_CLIPPING_16S/IMG_clipping_16s_cn.c -ccs.linkFile EXT_ROOT__IMG_CLIPPING_16S_66_LE_COFF_SRCIMG_CLIPPING_16S/IMG_clipping_16s_d.c -ccs.linkFile EXT_ROOT__IMG_CLIPPING_16S_66_LE_COFF_SRCIMG_CLIPPING_16S/IMG_clipping_16s_idat.c -ccs.linkFile EXT_ROOT__IMG_CLIPPING_16S_66_LE_COFF_SRCIMG_CLIPPING_16S/IMG_clipping_16s_odat.c -ccs.linkFile EXT_ROOT__IMG_CLIPPING_16S_66_LE_COFF/IMG_clipping_16s.c -ccs.linkFile EXT_ROOT__IMG_CLIPPING_16S_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CLIPPING_16S_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CLIPPING_16S_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CLIPPING_16S_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_CLIPPING_16S_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_clipping_16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_CLIPPING_16S_66_LE_COFF_SRCIMG_CLIPPING_16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_clipping_16s" -ccs.definePathVariable EXT_ROOT__IMG_CLIPPING_16S_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CLIPPING_16S_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_clipping_16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CLIPPING_16S_66_LE_COFF=.././ >> ./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CLIPPING_16S_66_LE_COFF_SRCIMG_CLIPPING_16S=../../ >> ./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CLIPPING_16S_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CLIPPING_16S_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_COFF/Release/IMG_clipping_16s_66_LE_COFF.out: ./src/IMG_clipping_16s/IMG_clipping_16s.h
./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_COFF/Release/IMG_clipping_16s_66_LE_COFF.out: ./src/IMG_clipping_16s/IMG_clipping_16s_cn.c
./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_COFF/Release/IMG_clipping_16s_66_LE_COFF.out: ./src/IMG_clipping_16s/IMG_clipping_16s_cn.h
./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_COFF/Release/IMG_clipping_16s_66_LE_COFF.out: ./src/IMG_clipping_16s/IMG_clipping_16s_d.c
./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_COFF/Release/IMG_clipping_16s_66_LE_COFF.out: ./src/IMG_clipping_16s/IMG_clipping_16s_idat.c
./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_COFF/Release/IMG_clipping_16s_66_LE_COFF.out: ./src/IMG_clipping_16s/IMG_clipping_16s_odat.c
./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_COFF/Release/IMG_clipping_16s_66_LE_COFF.out: ./src/IMG_clipping_16s//c66/IMG_clipping_16s.c
./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_COFF/Release/IMG_clipping_16s_66_LE_COFF.out: ./src/IMG_clipping_16s//c66/IMG_clipping_16s.h
./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_COFF/Release/IMG_clipping_16s_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_COFF/Release/IMG_clipping_16s_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_COFF/Release/IMG_clipping_16s_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_COFF/Release/IMG_clipping_16s_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_COFF/Release/IMG_clipping_16s_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_COFF/Release/IMG_clipping_16s_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_COFF/Release/IMG_clipping_16s_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_COFF/Release/IMG_clipping_16s_66_LE_COFF.out: ./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_COFF/.project
	-@ echo Importing Project IMG_clipping_16s_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_clipping_16s_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_clipping_16s/c66/IMG_clipping_16s_66_LE_COFF"
	-@ echo Building Project IMG_clipping_16s_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_clipping_16s_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_clipping_16s_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_COFF/.settings"

	-@ echo Project IMG_clipping_16s_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_clipping_16s_66_LE_ELF

#############################################################

all: ./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_ELF/Release/IMG_clipping_16s_66_LE_ELF.out

./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_clipping_16s_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CLIPPING_16S_66_LE_ELF_SRCIMG_CLIPPING_16S/IMG_clipping_16s_cn.c -ccs.linkFile EXT_ROOT__IMG_CLIPPING_16S_66_LE_ELF_SRCIMG_CLIPPING_16S/IMG_clipping_16s_d.c -ccs.linkFile EXT_ROOT__IMG_CLIPPING_16S_66_LE_ELF_SRCIMG_CLIPPING_16S/IMG_clipping_16s_idat.c -ccs.linkFile EXT_ROOT__IMG_CLIPPING_16S_66_LE_ELF_SRCIMG_CLIPPING_16S/IMG_clipping_16s_odat.c -ccs.linkFile EXT_ROOT__IMG_CLIPPING_16S_66_LE_ELF/IMG_clipping_16s.c -ccs.linkFile EXT_ROOT__IMG_CLIPPING_16S_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CLIPPING_16S_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CLIPPING_16S_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CLIPPING_16S_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_CLIPPING_16S_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_clipping_16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_CLIPPING_16S_66_LE_ELF_SRCIMG_CLIPPING_16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_clipping_16s" -ccs.definePathVariable EXT_ROOT__IMG_CLIPPING_16S_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CLIPPING_16S_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_clipping_16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CLIPPING_16S_66_LE_ELF=.././ >> ./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CLIPPING_16S_66_LE_ELF_SRCIMG_CLIPPING_16S=../../ >> ./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CLIPPING_16S_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CLIPPING_16S_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_ELF/Release/IMG_clipping_16s_66_LE_ELF.out: ./src/IMG_clipping_16s/IMG_clipping_16s.h
./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_ELF/Release/IMG_clipping_16s_66_LE_ELF.out: ./src/IMG_clipping_16s/IMG_clipping_16s_cn.c
./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_ELF/Release/IMG_clipping_16s_66_LE_ELF.out: ./src/IMG_clipping_16s/IMG_clipping_16s_cn.h
./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_ELF/Release/IMG_clipping_16s_66_LE_ELF.out: ./src/IMG_clipping_16s/IMG_clipping_16s_d.c
./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_ELF/Release/IMG_clipping_16s_66_LE_ELF.out: ./src/IMG_clipping_16s/IMG_clipping_16s_idat.c
./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_ELF/Release/IMG_clipping_16s_66_LE_ELF.out: ./src/IMG_clipping_16s/IMG_clipping_16s_odat.c
./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_ELF/Release/IMG_clipping_16s_66_LE_ELF.out: ./src/IMG_clipping_16s//c66/IMG_clipping_16s.c
./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_ELF/Release/IMG_clipping_16s_66_LE_ELF.out: ./src/IMG_clipping_16s//c66/IMG_clipping_16s.h
./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_ELF/Release/IMG_clipping_16s_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_ELF/Release/IMG_clipping_16s_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_ELF/Release/IMG_clipping_16s_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_ELF/Release/IMG_clipping_16s_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_ELF/Release/IMG_clipping_16s_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_ELF/Release/IMG_clipping_16s_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_ELF/Release/IMG_clipping_16s_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_ELF/Release/IMG_clipping_16s_66_LE_ELF.out: ./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_ELF/.project
	-@ echo Importing Project IMG_clipping_16s_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_clipping_16s_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_clipping_16s/c66/IMG_clipping_16s_66_LE_ELF"
	-@ echo Building Project IMG_clipping_16s_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_clipping_16s_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_clipping_16s_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_ELF/.settings"

	-@ echo Project IMG_clipping_16s_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_clipping_16s//c66//IMG_clipping_16s_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_conv_11x11_i16s_c16s_66_LE_COFF

#############################################################

all: ./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_COFF/Release/IMG_conv_11x11_i16s_c16s_66_LE_COFF.out

./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_conv_11x11_i16s_c16s_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CONV_11X11_I16S_C16S_66_LE_COFF_SRCIMG_CONV_11X11_I16S_C16S/IMG_conv_11x11_i16s_c16s_cn.c -ccs.linkFile EXT_ROOT__IMG_CONV_11X11_I16S_C16S_66_LE_COFF_SRCIMG_CONV_11X11_I16S_C16S/IMG_conv_11x11_i16s_c16s_d.c -ccs.linkFile EXT_ROOT__IMG_CONV_11X11_I16S_C16S_66_LE_COFF_SRCIMG_CONV_11X11_I16S_C16S/IMG_conv_11x11_i16s_c16s_idat.c -ccs.linkFile EXT_ROOT__IMG_CONV_11X11_I16S_C16S_66_LE_COFF_SRCIMG_CONV_11X11_I16S_C16S/IMG_conv_11x11_i16s_c16s_odat.c -ccs.linkFile EXT_ROOT__IMG_CONV_11X11_I16S_C16S_66_LE_COFF/IMG_conv_11x11_i16s_c16s.c -ccs.linkFile EXT_ROOT__IMG_CONV_11X11_I16S_C16S_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CONV_11X11_I16S_C16S_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CONV_11X11_I16S_C16S_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CONV_11X11_I16S_C16S_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_CONV_11X11_I16S_C16S_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_11x11_i16s_c16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_CONV_11X11_I16S_C16S_66_LE_COFF_SRCIMG_CONV_11X11_I16S_C16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_11x11_i16s_c16s" -ccs.definePathVariable EXT_ROOT__IMG_CONV_11X11_I16S_C16S_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CONV_11X11_I16S_C16S_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_conv_11x11_i16s_c16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CONV_11X11_I16S_C16S_66_LE_COFF=.././ >> ./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CONV_11X11_I16S_C16S_66_LE_COFF_SRCIMG_CONV_11X11_I16S_C16S=../../ >> ./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CONV_11X11_I16S_C16S_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CONV_11X11_I16S_C16S_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_COFF/Release/IMG_conv_11x11_i16s_c16s_66_LE_COFF.out: ./src/IMG_conv_11x11_i16s_c16s/IMG_conv_11x11_i16s_c16s.h
./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_COFF/Release/IMG_conv_11x11_i16s_c16s_66_LE_COFF.out: ./src/IMG_conv_11x11_i16s_c16s/IMG_conv_11x11_i16s_c16s_cn.c
./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_COFF/Release/IMG_conv_11x11_i16s_c16s_66_LE_COFF.out: ./src/IMG_conv_11x11_i16s_c16s/IMG_conv_11x11_i16s_c16s_cn.h
./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_COFF/Release/IMG_conv_11x11_i16s_c16s_66_LE_COFF.out: ./src/IMG_conv_11x11_i16s_c16s/IMG_conv_11x11_i16s_c16s_d.c
./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_COFF/Release/IMG_conv_11x11_i16s_c16s_66_LE_COFF.out: ./src/IMG_conv_11x11_i16s_c16s/IMG_conv_11x11_i16s_c16s_idat.c
./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_COFF/Release/IMG_conv_11x11_i16s_c16s_66_LE_COFF.out: ./src/IMG_conv_11x11_i16s_c16s/IMG_conv_11x11_i16s_c16s_odat.c
./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_COFF/Release/IMG_conv_11x11_i16s_c16s_66_LE_COFF.out: ./src/IMG_conv_11x11_i16s_c16s//c66/IMG_conv_11x11_i16s_c16s.c
./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_COFF/Release/IMG_conv_11x11_i16s_c16s_66_LE_COFF.out: ./src/IMG_conv_11x11_i16s_c16s//c66/IMG_conv_11x11_i16s_c16s.h
./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_COFF/Release/IMG_conv_11x11_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_COFF/Release/IMG_conv_11x11_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_COFF/Release/IMG_conv_11x11_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_COFF/Release/IMG_conv_11x11_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_COFF/Release/IMG_conv_11x11_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_COFF/Release/IMG_conv_11x11_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_COFF/Release/IMG_conv_11x11_i16s_c16s_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_COFF/Release/IMG_conv_11x11_i16s_c16s_66_LE_COFF.out: ./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_COFF/.project
	-@ echo Importing Project IMG_conv_11x11_i16s_c16s_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_conv_11x11_i16s_c16s_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_11x11_i16s_c16s/c66/IMG_conv_11x11_i16s_c16s_66_LE_COFF"
	-@ echo Building Project IMG_conv_11x11_i16s_c16s_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_conv_11x11_i16s_c16s_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_conv_11x11_i16s_c16s_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_COFF/.settings"

	-@ echo Project IMG_conv_11x11_i16s_c16s_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_conv_11x11_i16s_c16s_66_LE_ELF

#############################################################

all: ./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_ELF/Release/IMG_conv_11x11_i16s_c16s_66_LE_ELF.out

./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_conv_11x11_i16s_c16s_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CONV_11X11_I16S_C16S_66_LE_ELF_SRCIMG_CONV_11X11_I16S_C16S/IMG_conv_11x11_i16s_c16s_cn.c -ccs.linkFile EXT_ROOT__IMG_CONV_11X11_I16S_C16S_66_LE_ELF_SRCIMG_CONV_11X11_I16S_C16S/IMG_conv_11x11_i16s_c16s_d.c -ccs.linkFile EXT_ROOT__IMG_CONV_11X11_I16S_C16S_66_LE_ELF_SRCIMG_CONV_11X11_I16S_C16S/IMG_conv_11x11_i16s_c16s_idat.c -ccs.linkFile EXT_ROOT__IMG_CONV_11X11_I16S_C16S_66_LE_ELF_SRCIMG_CONV_11X11_I16S_C16S/IMG_conv_11x11_i16s_c16s_odat.c -ccs.linkFile EXT_ROOT__IMG_CONV_11X11_I16S_C16S_66_LE_ELF/IMG_conv_11x11_i16s_c16s.c -ccs.linkFile EXT_ROOT__IMG_CONV_11X11_I16S_C16S_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CONV_11X11_I16S_C16S_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CONV_11X11_I16S_C16S_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CONV_11X11_I16S_C16S_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_CONV_11X11_I16S_C16S_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_11x11_i16s_c16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_CONV_11X11_I16S_C16S_66_LE_ELF_SRCIMG_CONV_11X11_I16S_C16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_11x11_i16s_c16s" -ccs.definePathVariable EXT_ROOT__IMG_CONV_11X11_I16S_C16S_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CONV_11X11_I16S_C16S_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_conv_11x11_i16s_c16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CONV_11X11_I16S_C16S_66_LE_ELF=.././ >> ./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CONV_11X11_I16S_C16S_66_LE_ELF_SRCIMG_CONV_11X11_I16S_C16S=../../ >> ./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CONV_11X11_I16S_C16S_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CONV_11X11_I16S_C16S_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_ELF/Release/IMG_conv_11x11_i16s_c16s_66_LE_ELF.out: ./src/IMG_conv_11x11_i16s_c16s/IMG_conv_11x11_i16s_c16s.h
./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_ELF/Release/IMG_conv_11x11_i16s_c16s_66_LE_ELF.out: ./src/IMG_conv_11x11_i16s_c16s/IMG_conv_11x11_i16s_c16s_cn.c
./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_ELF/Release/IMG_conv_11x11_i16s_c16s_66_LE_ELF.out: ./src/IMG_conv_11x11_i16s_c16s/IMG_conv_11x11_i16s_c16s_cn.h
./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_ELF/Release/IMG_conv_11x11_i16s_c16s_66_LE_ELF.out: ./src/IMG_conv_11x11_i16s_c16s/IMG_conv_11x11_i16s_c16s_d.c
./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_ELF/Release/IMG_conv_11x11_i16s_c16s_66_LE_ELF.out: ./src/IMG_conv_11x11_i16s_c16s/IMG_conv_11x11_i16s_c16s_idat.c
./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_ELF/Release/IMG_conv_11x11_i16s_c16s_66_LE_ELF.out: ./src/IMG_conv_11x11_i16s_c16s/IMG_conv_11x11_i16s_c16s_odat.c
./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_ELF/Release/IMG_conv_11x11_i16s_c16s_66_LE_ELF.out: ./src/IMG_conv_11x11_i16s_c16s//c66/IMG_conv_11x11_i16s_c16s.c
./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_ELF/Release/IMG_conv_11x11_i16s_c16s_66_LE_ELF.out: ./src/IMG_conv_11x11_i16s_c16s//c66/IMG_conv_11x11_i16s_c16s.h
./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_ELF/Release/IMG_conv_11x11_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_ELF/Release/IMG_conv_11x11_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_ELF/Release/IMG_conv_11x11_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_ELF/Release/IMG_conv_11x11_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_ELF/Release/IMG_conv_11x11_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_ELF/Release/IMG_conv_11x11_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_ELF/Release/IMG_conv_11x11_i16s_c16s_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_ELF/Release/IMG_conv_11x11_i16s_c16s_66_LE_ELF.out: ./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_ELF/.project
	-@ echo Importing Project IMG_conv_11x11_i16s_c16s_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_conv_11x11_i16s_c16s_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_11x11_i16s_c16s/c66/IMG_conv_11x11_i16s_c16s_66_LE_ELF"
	-@ echo Building Project IMG_conv_11x11_i16s_c16s_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_conv_11x11_i16s_c16s_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_conv_11x11_i16s_c16s_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_ELF/.settings"

	-@ echo Project IMG_conv_11x11_i16s_c16s_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_conv_11x11_i16s_c16s//c66//IMG_conv_11x11_i16s_c16s_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_conv_11x11_i8_c8s_66_LE_COFF

#############################################################

all: ./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_COFF/Release/IMG_conv_11x11_i8_c8s_66_LE_COFF.out

./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_conv_11x11_i8_c8s_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CONV_11X11_I8_C8S_66_LE_COFF_SRCIMG_CONV_11X11_I8_C8S/IMG_conv_11x11_i8_c8s_cn.c -ccs.linkFile EXT_ROOT__IMG_CONV_11X11_I8_C8S_66_LE_COFF_SRCIMG_CONV_11X11_I8_C8S/IMG_conv_11x11_i8_c8s_d.c -ccs.linkFile EXT_ROOT__IMG_CONV_11X11_I8_C8S_66_LE_COFF_SRCIMG_CONV_11X11_I8_C8S/IMG_conv_11x11_i8_c8s_idat.c -ccs.linkFile EXT_ROOT__IMG_CONV_11X11_I8_C8S_66_LE_COFF_SRCIMG_CONV_11X11_I8_C8S/IMG_conv_11x11_i8_c8s_odat.c -ccs.linkFile EXT_ROOT__IMG_CONV_11X11_I8_C8S_66_LE_COFF/IMG_conv_11x11_i8_c8s.c -ccs.linkFile EXT_ROOT__IMG_CONV_11X11_I8_C8S_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CONV_11X11_I8_C8S_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CONV_11X11_I8_C8S_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CONV_11X11_I8_C8S_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_CONV_11X11_I8_C8S_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_11x11_i8_c8s/c66" -ccs.definePathVariable EXT_ROOT__IMG_CONV_11X11_I8_C8S_66_LE_COFF_SRCIMG_CONV_11X11_I8_C8S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_11x11_i8_c8s" -ccs.definePathVariable EXT_ROOT__IMG_CONV_11X11_I8_C8S_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CONV_11X11_I8_C8S_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_conv_11x11_i8_c8s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CONV_11X11_I8_C8S_66_LE_COFF=.././ >> ./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CONV_11X11_I8_C8S_66_LE_COFF_SRCIMG_CONV_11X11_I8_C8S=../../ >> ./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CONV_11X11_I8_C8S_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CONV_11X11_I8_C8S_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_COFF/Release/IMG_conv_11x11_i8_c8s_66_LE_COFF.out: ./src/IMG_conv_11x11_i8_c8s/IMG_conv_11x11_i8_c8s.h
./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_COFF/Release/IMG_conv_11x11_i8_c8s_66_LE_COFF.out: ./src/IMG_conv_11x11_i8_c8s/IMG_conv_11x11_i8_c8s_cn.c
./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_COFF/Release/IMG_conv_11x11_i8_c8s_66_LE_COFF.out: ./src/IMG_conv_11x11_i8_c8s/IMG_conv_11x11_i8_c8s_cn.h
./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_COFF/Release/IMG_conv_11x11_i8_c8s_66_LE_COFF.out: ./src/IMG_conv_11x11_i8_c8s/IMG_conv_11x11_i8_c8s_d.c
./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_COFF/Release/IMG_conv_11x11_i8_c8s_66_LE_COFF.out: ./src/IMG_conv_11x11_i8_c8s/IMG_conv_11x11_i8_c8s_idat.c
./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_COFF/Release/IMG_conv_11x11_i8_c8s_66_LE_COFF.out: ./src/IMG_conv_11x11_i8_c8s/IMG_conv_11x11_i8_c8s_odat.c
./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_COFF/Release/IMG_conv_11x11_i8_c8s_66_LE_COFF.out: ./src/IMG_conv_11x11_i8_c8s//c66/IMG_conv_11x11_i8_c8s.c
./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_COFF/Release/IMG_conv_11x11_i8_c8s_66_LE_COFF.out: ./src/IMG_conv_11x11_i8_c8s//c66/IMG_conv_11x11_i8_c8s.h
./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_COFF/Release/IMG_conv_11x11_i8_c8s_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_COFF/Release/IMG_conv_11x11_i8_c8s_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_COFF/Release/IMG_conv_11x11_i8_c8s_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_COFF/Release/IMG_conv_11x11_i8_c8s_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_COFF/Release/IMG_conv_11x11_i8_c8s_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_COFF/Release/IMG_conv_11x11_i8_c8s_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_COFF/Release/IMG_conv_11x11_i8_c8s_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_COFF/Release/IMG_conv_11x11_i8_c8s_66_LE_COFF.out: ./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_COFF/.project
	-@ echo Importing Project IMG_conv_11x11_i8_c8s_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_conv_11x11_i8_c8s_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_11x11_i8_c8s/c66/IMG_conv_11x11_i8_c8s_66_LE_COFF"
	-@ echo Building Project IMG_conv_11x11_i8_c8s_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_conv_11x11_i8_c8s_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_conv_11x11_i8_c8s_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_COFF/.settings"

	-@ echo Project IMG_conv_11x11_i8_c8s_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_conv_11x11_i8_c8s_66_LE_ELF

#############################################################

all: ./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_ELF/Release/IMG_conv_11x11_i8_c8s_66_LE_ELF.out

./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_conv_11x11_i8_c8s_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CONV_11X11_I8_C8S_66_LE_ELF_SRCIMG_CONV_11X11_I8_C8S/IMG_conv_11x11_i8_c8s_cn.c -ccs.linkFile EXT_ROOT__IMG_CONV_11X11_I8_C8S_66_LE_ELF_SRCIMG_CONV_11X11_I8_C8S/IMG_conv_11x11_i8_c8s_d.c -ccs.linkFile EXT_ROOT__IMG_CONV_11X11_I8_C8S_66_LE_ELF_SRCIMG_CONV_11X11_I8_C8S/IMG_conv_11x11_i8_c8s_idat.c -ccs.linkFile EXT_ROOT__IMG_CONV_11X11_I8_C8S_66_LE_ELF_SRCIMG_CONV_11X11_I8_C8S/IMG_conv_11x11_i8_c8s_odat.c -ccs.linkFile EXT_ROOT__IMG_CONV_11X11_I8_C8S_66_LE_ELF/IMG_conv_11x11_i8_c8s.c -ccs.linkFile EXT_ROOT__IMG_CONV_11X11_I8_C8S_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CONV_11X11_I8_C8S_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CONV_11X11_I8_C8S_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CONV_11X11_I8_C8S_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_CONV_11X11_I8_C8S_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_11x11_i8_c8s/c66" -ccs.definePathVariable EXT_ROOT__IMG_CONV_11X11_I8_C8S_66_LE_ELF_SRCIMG_CONV_11X11_I8_C8S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_11x11_i8_c8s" -ccs.definePathVariable EXT_ROOT__IMG_CONV_11X11_I8_C8S_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CONV_11X11_I8_C8S_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_conv_11x11_i8_c8s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CONV_11X11_I8_C8S_66_LE_ELF=.././ >> ./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CONV_11X11_I8_C8S_66_LE_ELF_SRCIMG_CONV_11X11_I8_C8S=../../ >> ./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CONV_11X11_I8_C8S_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CONV_11X11_I8_C8S_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_ELF/Release/IMG_conv_11x11_i8_c8s_66_LE_ELF.out: ./src/IMG_conv_11x11_i8_c8s/IMG_conv_11x11_i8_c8s.h
./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_ELF/Release/IMG_conv_11x11_i8_c8s_66_LE_ELF.out: ./src/IMG_conv_11x11_i8_c8s/IMG_conv_11x11_i8_c8s_cn.c
./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_ELF/Release/IMG_conv_11x11_i8_c8s_66_LE_ELF.out: ./src/IMG_conv_11x11_i8_c8s/IMG_conv_11x11_i8_c8s_cn.h
./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_ELF/Release/IMG_conv_11x11_i8_c8s_66_LE_ELF.out: ./src/IMG_conv_11x11_i8_c8s/IMG_conv_11x11_i8_c8s_d.c
./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_ELF/Release/IMG_conv_11x11_i8_c8s_66_LE_ELF.out: ./src/IMG_conv_11x11_i8_c8s/IMG_conv_11x11_i8_c8s_idat.c
./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_ELF/Release/IMG_conv_11x11_i8_c8s_66_LE_ELF.out: ./src/IMG_conv_11x11_i8_c8s/IMG_conv_11x11_i8_c8s_odat.c
./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_ELF/Release/IMG_conv_11x11_i8_c8s_66_LE_ELF.out: ./src/IMG_conv_11x11_i8_c8s//c66/IMG_conv_11x11_i8_c8s.c
./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_ELF/Release/IMG_conv_11x11_i8_c8s_66_LE_ELF.out: ./src/IMG_conv_11x11_i8_c8s//c66/IMG_conv_11x11_i8_c8s.h
./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_ELF/Release/IMG_conv_11x11_i8_c8s_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_ELF/Release/IMG_conv_11x11_i8_c8s_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_ELF/Release/IMG_conv_11x11_i8_c8s_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_ELF/Release/IMG_conv_11x11_i8_c8s_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_ELF/Release/IMG_conv_11x11_i8_c8s_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_ELF/Release/IMG_conv_11x11_i8_c8s_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_ELF/Release/IMG_conv_11x11_i8_c8s_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_ELF/Release/IMG_conv_11x11_i8_c8s_66_LE_ELF.out: ./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_ELF/.project
	-@ echo Importing Project IMG_conv_11x11_i8_c8s_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_conv_11x11_i8_c8s_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_11x11_i8_c8s/c66/IMG_conv_11x11_i8_c8s_66_LE_ELF"
	-@ echo Building Project IMG_conv_11x11_i8_c8s_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_conv_11x11_i8_c8s_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_conv_11x11_i8_c8s_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_ELF/.settings"

	-@ echo Project IMG_conv_11x11_i8_c8s_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_conv_11x11_i8_c8s//c66//IMG_conv_11x11_i8_c8s_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_conv_3x3_i16s_c16s_66_LE_COFF

#############################################################

all: ./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_COFF/Release/IMG_conv_3x3_i16s_c16s_66_LE_COFF.out

./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_conv_3x3_i16s_c16s_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I16S_C16S_66_LE_COFF_SRCIMG_CONV_3X3_I16S_C16S/IMG_conv_3x3_i16s_c16s_cn.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I16S_C16S_66_LE_COFF_SRCIMG_CONV_3X3_I16S_C16S/IMG_conv_3x3_i16s_c16s_d.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I16S_C16S_66_LE_COFF_SRCIMG_CONV_3X3_I16S_C16S/IMG_conv_3x3_i16s_c16s_idat.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I16S_C16S_66_LE_COFF_SRCIMG_CONV_3X3_I16S_C16S/IMG_conv_3x3_i16s_c16s_odat.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I16S_C16S_66_LE_COFF/IMG_conv_3x3_i16s_c16s.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I16S_C16S_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I16S_C16S_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I16S_C16S_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I16S_C16S_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_CONV_3X3_I16S_C16S_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_3x3_i16s_c16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_CONV_3X3_I16S_C16S_66_LE_COFF_SRCIMG_CONV_3X3_I16S_C16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_3x3_i16s_c16s" -ccs.definePathVariable EXT_ROOT__IMG_CONV_3X3_I16S_C16S_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CONV_3X3_I16S_C16S_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_conv_3x3_i16s_c16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CONV_3X3_I16S_C16S_66_LE_COFF=.././ >> ./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CONV_3X3_I16S_C16S_66_LE_COFF_SRCIMG_CONV_3X3_I16S_C16S=../../ >> ./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CONV_3X3_I16S_C16S_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CONV_3X3_I16S_C16S_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_COFF/Release/IMG_conv_3x3_i16s_c16s_66_LE_COFF.out: ./src/IMG_conv_3x3_i16s_c16s/IMG_conv_3x3_i16s_c16s.h
./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_COFF/Release/IMG_conv_3x3_i16s_c16s_66_LE_COFF.out: ./src/IMG_conv_3x3_i16s_c16s/IMG_conv_3x3_i16s_c16s_cn.c
./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_COFF/Release/IMG_conv_3x3_i16s_c16s_66_LE_COFF.out: ./src/IMG_conv_3x3_i16s_c16s/IMG_conv_3x3_i16s_c16s_cn.h
./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_COFF/Release/IMG_conv_3x3_i16s_c16s_66_LE_COFF.out: ./src/IMG_conv_3x3_i16s_c16s/IMG_conv_3x3_i16s_c16s_d.c
./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_COFF/Release/IMG_conv_3x3_i16s_c16s_66_LE_COFF.out: ./src/IMG_conv_3x3_i16s_c16s/IMG_conv_3x3_i16s_c16s_idat.c
./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_COFF/Release/IMG_conv_3x3_i16s_c16s_66_LE_COFF.out: ./src/IMG_conv_3x3_i16s_c16s/IMG_conv_3x3_i16s_c16s_odat.c
./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_COFF/Release/IMG_conv_3x3_i16s_c16s_66_LE_COFF.out: ./src/IMG_conv_3x3_i16s_c16s//c66/IMG_conv_3x3_i16s_c16s.c
./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_COFF/Release/IMG_conv_3x3_i16s_c16s_66_LE_COFF.out: ./src/IMG_conv_3x3_i16s_c16s//c66/IMG_conv_3x3_i16s_c16s.h
./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_COFF/Release/IMG_conv_3x3_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_COFF/Release/IMG_conv_3x3_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_COFF/Release/IMG_conv_3x3_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_COFF/Release/IMG_conv_3x3_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_COFF/Release/IMG_conv_3x3_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_COFF/Release/IMG_conv_3x3_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_COFF/Release/IMG_conv_3x3_i16s_c16s_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_COFF/Release/IMG_conv_3x3_i16s_c16s_66_LE_COFF.out: ./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_COFF/.project
	-@ echo Importing Project IMG_conv_3x3_i16s_c16s_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_conv_3x3_i16s_c16s_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_3x3_i16s_c16s/c66/IMG_conv_3x3_i16s_c16s_66_LE_COFF"
	-@ echo Building Project IMG_conv_3x3_i16s_c16s_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_conv_3x3_i16s_c16s_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_conv_3x3_i16s_c16s_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_COFF/.settings"

	-@ echo Project IMG_conv_3x3_i16s_c16s_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_conv_3x3_i16s_c16s_66_LE_ELF

#############################################################

all: ./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_ELF/Release/IMG_conv_3x3_i16s_c16s_66_LE_ELF.out

./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_conv_3x3_i16s_c16s_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I16S_C16S_66_LE_ELF_SRCIMG_CONV_3X3_I16S_C16S/IMG_conv_3x3_i16s_c16s_cn.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I16S_C16S_66_LE_ELF_SRCIMG_CONV_3X3_I16S_C16S/IMG_conv_3x3_i16s_c16s_d.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I16S_C16S_66_LE_ELF_SRCIMG_CONV_3X3_I16S_C16S/IMG_conv_3x3_i16s_c16s_idat.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I16S_C16S_66_LE_ELF_SRCIMG_CONV_3X3_I16S_C16S/IMG_conv_3x3_i16s_c16s_odat.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I16S_C16S_66_LE_ELF/IMG_conv_3x3_i16s_c16s.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I16S_C16S_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I16S_C16S_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I16S_C16S_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I16S_C16S_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_CONV_3X3_I16S_C16S_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_3x3_i16s_c16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_CONV_3X3_I16S_C16S_66_LE_ELF_SRCIMG_CONV_3X3_I16S_C16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_3x3_i16s_c16s" -ccs.definePathVariable EXT_ROOT__IMG_CONV_3X3_I16S_C16S_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CONV_3X3_I16S_C16S_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_conv_3x3_i16s_c16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CONV_3X3_I16S_C16S_66_LE_ELF=.././ >> ./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CONV_3X3_I16S_C16S_66_LE_ELF_SRCIMG_CONV_3X3_I16S_C16S=../../ >> ./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CONV_3X3_I16S_C16S_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CONV_3X3_I16S_C16S_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_ELF/Release/IMG_conv_3x3_i16s_c16s_66_LE_ELF.out: ./src/IMG_conv_3x3_i16s_c16s/IMG_conv_3x3_i16s_c16s.h
./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_ELF/Release/IMG_conv_3x3_i16s_c16s_66_LE_ELF.out: ./src/IMG_conv_3x3_i16s_c16s/IMG_conv_3x3_i16s_c16s_cn.c
./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_ELF/Release/IMG_conv_3x3_i16s_c16s_66_LE_ELF.out: ./src/IMG_conv_3x3_i16s_c16s/IMG_conv_3x3_i16s_c16s_cn.h
./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_ELF/Release/IMG_conv_3x3_i16s_c16s_66_LE_ELF.out: ./src/IMG_conv_3x3_i16s_c16s/IMG_conv_3x3_i16s_c16s_d.c
./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_ELF/Release/IMG_conv_3x3_i16s_c16s_66_LE_ELF.out: ./src/IMG_conv_3x3_i16s_c16s/IMG_conv_3x3_i16s_c16s_idat.c
./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_ELF/Release/IMG_conv_3x3_i16s_c16s_66_LE_ELF.out: ./src/IMG_conv_3x3_i16s_c16s/IMG_conv_3x3_i16s_c16s_odat.c
./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_ELF/Release/IMG_conv_3x3_i16s_c16s_66_LE_ELF.out: ./src/IMG_conv_3x3_i16s_c16s//c66/IMG_conv_3x3_i16s_c16s.c
./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_ELF/Release/IMG_conv_3x3_i16s_c16s_66_LE_ELF.out: ./src/IMG_conv_3x3_i16s_c16s//c66/IMG_conv_3x3_i16s_c16s.h
./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_ELF/Release/IMG_conv_3x3_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_ELF/Release/IMG_conv_3x3_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_ELF/Release/IMG_conv_3x3_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_ELF/Release/IMG_conv_3x3_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_ELF/Release/IMG_conv_3x3_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_ELF/Release/IMG_conv_3x3_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_ELF/Release/IMG_conv_3x3_i16s_c16s_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_ELF/Release/IMG_conv_3x3_i16s_c16s_66_LE_ELF.out: ./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_ELF/.project
	-@ echo Importing Project IMG_conv_3x3_i16s_c16s_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_conv_3x3_i16s_c16s_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_3x3_i16s_c16s/c66/IMG_conv_3x3_i16s_c16s_66_LE_ELF"
	-@ echo Building Project IMG_conv_3x3_i16s_c16s_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_conv_3x3_i16s_c16s_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_conv_3x3_i16s_c16s_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_ELF/.settings"

	-@ echo Project IMG_conv_3x3_i16s_c16s_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_conv_3x3_i16s_c16s//c66//IMG_conv_3x3_i16s_c16s_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_conv_3x3_i16_c16s_66_LE_COFF

#############################################################

all: ./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_COFF/Release/IMG_conv_3x3_i16_c16s_66_LE_COFF.out

./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_conv_3x3_i16_c16s_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I16_C16S_66_LE_COFF_SRCIMG_CONV_3X3_I16_C16S/IMG_conv_3x3_i16_c16s_cn.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I16_C16S_66_LE_COFF_SRCIMG_CONV_3X3_I16_C16S/IMG_conv_3x3_i16_c16s_d.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I16_C16S_66_LE_COFF_SRCIMG_CONV_3X3_I16_C16S/IMG_conv_3x3_i16_c16s_idat.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I16_C16S_66_LE_COFF_SRCIMG_CONV_3X3_I16_C16S/IMG_conv_3x3_i16_c16s_odat.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I16_C16S_66_LE_COFF/IMG_conv_3x3_i16_c16s.sa -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I16_C16S_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I16_C16S_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I16_C16S_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I16_C16S_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_CONV_3X3_I16_C16S_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_3x3_i16_c16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_CONV_3X3_I16_C16S_66_LE_COFF_SRCIMG_CONV_3X3_I16_C16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_3x3_i16_c16s" -ccs.definePathVariable EXT_ROOT__IMG_CONV_3X3_I16_C16S_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CONV_3X3_I16_C16S_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_conv_3x3_i16_c16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CONV_3X3_I16_C16S_66_LE_COFF=.././ >> ./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CONV_3X3_I16_C16S_66_LE_COFF_SRCIMG_CONV_3X3_I16_C16S=../../ >> ./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CONV_3X3_I16_C16S_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CONV_3X3_I16_C16S_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_COFF/Release/IMG_conv_3x3_i16_c16s_66_LE_COFF.out: ./src/IMG_conv_3x3_i16_c16s/IMG_conv_3x3_i16_c16s.h
./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_COFF/Release/IMG_conv_3x3_i16_c16s_66_LE_COFF.out: ./src/IMG_conv_3x3_i16_c16s/IMG_conv_3x3_i16_c16s_cn.c
./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_COFF/Release/IMG_conv_3x3_i16_c16s_66_LE_COFF.out: ./src/IMG_conv_3x3_i16_c16s/IMG_conv_3x3_i16_c16s_cn.h
./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_COFF/Release/IMG_conv_3x3_i16_c16s_66_LE_COFF.out: ./src/IMG_conv_3x3_i16_c16s/IMG_conv_3x3_i16_c16s_d.c
./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_COFF/Release/IMG_conv_3x3_i16_c16s_66_LE_COFF.out: ./src/IMG_conv_3x3_i16_c16s/IMG_conv_3x3_i16_c16s_idat.c
./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_COFF/Release/IMG_conv_3x3_i16_c16s_66_LE_COFF.out: ./src/IMG_conv_3x3_i16_c16s/IMG_conv_3x3_i16_c16s_odat.c
./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_COFF/Release/IMG_conv_3x3_i16_c16s_66_LE_COFF.out: ./src/IMG_conv_3x3_i16_c16s//c66/IMG_conv_3x3_i16_c16s.h
./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_COFF/Release/IMG_conv_3x3_i16_c16s_66_LE_COFF.out: ./src/IMG_conv_3x3_i16_c16s//c66/IMG_conv_3x3_i16_c16s.sa
./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_COFF/Release/IMG_conv_3x3_i16_c16s_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_COFF/Release/IMG_conv_3x3_i16_c16s_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_COFF/Release/IMG_conv_3x3_i16_c16s_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_COFF/Release/IMG_conv_3x3_i16_c16s_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_COFF/Release/IMG_conv_3x3_i16_c16s_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_COFF/Release/IMG_conv_3x3_i16_c16s_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_COFF/Release/IMG_conv_3x3_i16_c16s_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_COFF/Release/IMG_conv_3x3_i16_c16s_66_LE_COFF.out: ./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_COFF/.project
	-@ echo Importing Project IMG_conv_3x3_i16_c16s_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_conv_3x3_i16_c16s_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_3x3_i16_c16s/c66/IMG_conv_3x3_i16_c16s_66_LE_COFF"
	-@ echo Building Project IMG_conv_3x3_i16_c16s_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_conv_3x3_i16_c16s_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_conv_3x3_i16_c16s_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_COFF/.settings"

	-@ echo Project IMG_conv_3x3_i16_c16s_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_conv_3x3_i16_c16s_66_LE_ELF

#############################################################

all: ./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_ELF/Release/IMG_conv_3x3_i16_c16s_66_LE_ELF.out

./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_conv_3x3_i16_c16s_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I16_C16S_66_LE_ELF_SRCIMG_CONV_3X3_I16_C16S/IMG_conv_3x3_i16_c16s_cn.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I16_C16S_66_LE_ELF_SRCIMG_CONV_3X3_I16_C16S/IMG_conv_3x3_i16_c16s_d.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I16_C16S_66_LE_ELF_SRCIMG_CONV_3X3_I16_C16S/IMG_conv_3x3_i16_c16s_idat.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I16_C16S_66_LE_ELF_SRCIMG_CONV_3X3_I16_C16S/IMG_conv_3x3_i16_c16s_odat.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I16_C16S_66_LE_ELF/IMG_conv_3x3_i16_c16s.sa -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I16_C16S_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I16_C16S_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I16_C16S_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I16_C16S_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_CONV_3X3_I16_C16S_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_3x3_i16_c16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_CONV_3X3_I16_C16S_66_LE_ELF_SRCIMG_CONV_3X3_I16_C16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_3x3_i16_c16s" -ccs.definePathVariable EXT_ROOT__IMG_CONV_3X3_I16_C16S_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CONV_3X3_I16_C16S_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_conv_3x3_i16_c16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CONV_3X3_I16_C16S_66_LE_ELF=.././ >> ./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CONV_3X3_I16_C16S_66_LE_ELF_SRCIMG_CONV_3X3_I16_C16S=../../ >> ./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CONV_3X3_I16_C16S_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CONV_3X3_I16_C16S_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_ELF/Release/IMG_conv_3x3_i16_c16s_66_LE_ELF.out: ./src/IMG_conv_3x3_i16_c16s/IMG_conv_3x3_i16_c16s.h
./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_ELF/Release/IMG_conv_3x3_i16_c16s_66_LE_ELF.out: ./src/IMG_conv_3x3_i16_c16s/IMG_conv_3x3_i16_c16s_cn.c
./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_ELF/Release/IMG_conv_3x3_i16_c16s_66_LE_ELF.out: ./src/IMG_conv_3x3_i16_c16s/IMG_conv_3x3_i16_c16s_cn.h
./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_ELF/Release/IMG_conv_3x3_i16_c16s_66_LE_ELF.out: ./src/IMG_conv_3x3_i16_c16s/IMG_conv_3x3_i16_c16s_d.c
./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_ELF/Release/IMG_conv_3x3_i16_c16s_66_LE_ELF.out: ./src/IMG_conv_3x3_i16_c16s/IMG_conv_3x3_i16_c16s_idat.c
./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_ELF/Release/IMG_conv_3x3_i16_c16s_66_LE_ELF.out: ./src/IMG_conv_3x3_i16_c16s/IMG_conv_3x3_i16_c16s_odat.c
./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_ELF/Release/IMG_conv_3x3_i16_c16s_66_LE_ELF.out: ./src/IMG_conv_3x3_i16_c16s//c66/IMG_conv_3x3_i16_c16s.h
./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_ELF/Release/IMG_conv_3x3_i16_c16s_66_LE_ELF.out: ./src/IMG_conv_3x3_i16_c16s//c66/IMG_conv_3x3_i16_c16s.sa
./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_ELF/Release/IMG_conv_3x3_i16_c16s_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_ELF/Release/IMG_conv_3x3_i16_c16s_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_ELF/Release/IMG_conv_3x3_i16_c16s_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_ELF/Release/IMG_conv_3x3_i16_c16s_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_ELF/Release/IMG_conv_3x3_i16_c16s_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_ELF/Release/IMG_conv_3x3_i16_c16s_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_ELF/Release/IMG_conv_3x3_i16_c16s_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_ELF/Release/IMG_conv_3x3_i16_c16s_66_LE_ELF.out: ./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_ELF/.project
	-@ echo Importing Project IMG_conv_3x3_i16_c16s_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_conv_3x3_i16_c16s_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_3x3_i16_c16s/c66/IMG_conv_3x3_i16_c16s_66_LE_ELF"
	-@ echo Building Project IMG_conv_3x3_i16_c16s_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_conv_3x3_i16_c16s_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_conv_3x3_i16_c16s_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_ELF/.settings"

	-@ echo Project IMG_conv_3x3_i16_c16s_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_conv_3x3_i16_c16s//c66//IMG_conv_3x3_i16_c16s_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_conv_3x3_i8_c8s_66_LE_COFF

#############################################################

all: ./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_COFF/Release/IMG_conv_3x3_i8_c8s_66_LE_COFF.out

./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_conv_3x3_i8_c8s_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I8_C8S_66_LE_COFF_SRCIMG_CONV_3X3_I8_C8S/IMG_conv_3x3_i8_c8s_cn.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I8_C8S_66_LE_COFF_SRCIMG_CONV_3X3_I8_C8S/IMG_conv_3x3_i8_c8s_d.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I8_C8S_66_LE_COFF_SRCIMG_CONV_3X3_I8_C8S/IMG_conv_3x3_i8_c8s_idat.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I8_C8S_66_LE_COFF_SRCIMG_CONV_3X3_I8_C8S/IMG_conv_3x3_i8_c8s_odat.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I8_C8S_66_LE_COFF/IMG_conv_3x3_i8_c8s.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I8_C8S_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I8_C8S_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I8_C8S_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I8_C8S_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_CONV_3X3_I8_C8S_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_3x3_i8_c8s/c66" -ccs.definePathVariable EXT_ROOT__IMG_CONV_3X3_I8_C8S_66_LE_COFF_SRCIMG_CONV_3X3_I8_C8S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_3x3_i8_c8s" -ccs.definePathVariable EXT_ROOT__IMG_CONV_3X3_I8_C8S_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CONV_3X3_I8_C8S_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_conv_3x3_i8_c8s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CONV_3X3_I8_C8S_66_LE_COFF=.././ >> ./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CONV_3X3_I8_C8S_66_LE_COFF_SRCIMG_CONV_3X3_I8_C8S=../../ >> ./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CONV_3X3_I8_C8S_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CONV_3X3_I8_C8S_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_COFF/Release/IMG_conv_3x3_i8_c8s_66_LE_COFF.out: ./src/IMG_conv_3x3_i8_c8s/IMG_conv_3x3_i8_c8s.h
./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_COFF/Release/IMG_conv_3x3_i8_c8s_66_LE_COFF.out: ./src/IMG_conv_3x3_i8_c8s/IMG_conv_3x3_i8_c8s_cn.c
./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_COFF/Release/IMG_conv_3x3_i8_c8s_66_LE_COFF.out: ./src/IMG_conv_3x3_i8_c8s/IMG_conv_3x3_i8_c8s_cn.h
./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_COFF/Release/IMG_conv_3x3_i8_c8s_66_LE_COFF.out: ./src/IMG_conv_3x3_i8_c8s/IMG_conv_3x3_i8_c8s_d.c
./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_COFF/Release/IMG_conv_3x3_i8_c8s_66_LE_COFF.out: ./src/IMG_conv_3x3_i8_c8s/IMG_conv_3x3_i8_c8s_idat.c
./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_COFF/Release/IMG_conv_3x3_i8_c8s_66_LE_COFF.out: ./src/IMG_conv_3x3_i8_c8s/IMG_conv_3x3_i8_c8s_odat.c
./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_COFF/Release/IMG_conv_3x3_i8_c8s_66_LE_COFF.out: ./src/IMG_conv_3x3_i8_c8s//c66/IMG_conv_3x3_i8_c8s.c
./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_COFF/Release/IMG_conv_3x3_i8_c8s_66_LE_COFF.out: ./src/IMG_conv_3x3_i8_c8s//c66/IMG_conv_3x3_i8_c8s.h
./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_COFF/Release/IMG_conv_3x3_i8_c8s_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_COFF/Release/IMG_conv_3x3_i8_c8s_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_COFF/Release/IMG_conv_3x3_i8_c8s_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_COFF/Release/IMG_conv_3x3_i8_c8s_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_COFF/Release/IMG_conv_3x3_i8_c8s_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_COFF/Release/IMG_conv_3x3_i8_c8s_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_COFF/Release/IMG_conv_3x3_i8_c8s_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_COFF/Release/IMG_conv_3x3_i8_c8s_66_LE_COFF.out: ./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_COFF/.project
	-@ echo Importing Project IMG_conv_3x3_i8_c8s_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_conv_3x3_i8_c8s_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_3x3_i8_c8s/c66/IMG_conv_3x3_i8_c8s_66_LE_COFF"
	-@ echo Building Project IMG_conv_3x3_i8_c8s_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_conv_3x3_i8_c8s_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_conv_3x3_i8_c8s_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_COFF/.settings"

	-@ echo Project IMG_conv_3x3_i8_c8s_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_conv_3x3_i8_c8s_66_LE_ELF

#############################################################

all: ./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_ELF/Release/IMG_conv_3x3_i8_c8s_66_LE_ELF.out

./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_conv_3x3_i8_c8s_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I8_C8S_66_LE_ELF_SRCIMG_CONV_3X3_I8_C8S/IMG_conv_3x3_i8_c8s_cn.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I8_C8S_66_LE_ELF_SRCIMG_CONV_3X3_I8_C8S/IMG_conv_3x3_i8_c8s_d.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I8_C8S_66_LE_ELF_SRCIMG_CONV_3X3_I8_C8S/IMG_conv_3x3_i8_c8s_idat.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I8_C8S_66_LE_ELF_SRCIMG_CONV_3X3_I8_C8S/IMG_conv_3x3_i8_c8s_odat.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I8_C8S_66_LE_ELF/IMG_conv_3x3_i8_c8s.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I8_C8S_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I8_C8S_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I8_C8S_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CONV_3X3_I8_C8S_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_CONV_3X3_I8_C8S_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_3x3_i8_c8s/c66" -ccs.definePathVariable EXT_ROOT__IMG_CONV_3X3_I8_C8S_66_LE_ELF_SRCIMG_CONV_3X3_I8_C8S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_3x3_i8_c8s" -ccs.definePathVariable EXT_ROOT__IMG_CONV_3X3_I8_C8S_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CONV_3X3_I8_C8S_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_conv_3x3_i8_c8s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CONV_3X3_I8_C8S_66_LE_ELF=.././ >> ./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CONV_3X3_I8_C8S_66_LE_ELF_SRCIMG_CONV_3X3_I8_C8S=../../ >> ./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CONV_3X3_I8_C8S_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CONV_3X3_I8_C8S_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_ELF/Release/IMG_conv_3x3_i8_c8s_66_LE_ELF.out: ./src/IMG_conv_3x3_i8_c8s/IMG_conv_3x3_i8_c8s.h
./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_ELF/Release/IMG_conv_3x3_i8_c8s_66_LE_ELF.out: ./src/IMG_conv_3x3_i8_c8s/IMG_conv_3x3_i8_c8s_cn.c
./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_ELF/Release/IMG_conv_3x3_i8_c8s_66_LE_ELF.out: ./src/IMG_conv_3x3_i8_c8s/IMG_conv_3x3_i8_c8s_cn.h
./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_ELF/Release/IMG_conv_3x3_i8_c8s_66_LE_ELF.out: ./src/IMG_conv_3x3_i8_c8s/IMG_conv_3x3_i8_c8s_d.c
./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_ELF/Release/IMG_conv_3x3_i8_c8s_66_LE_ELF.out: ./src/IMG_conv_3x3_i8_c8s/IMG_conv_3x3_i8_c8s_idat.c
./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_ELF/Release/IMG_conv_3x3_i8_c8s_66_LE_ELF.out: ./src/IMG_conv_3x3_i8_c8s/IMG_conv_3x3_i8_c8s_odat.c
./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_ELF/Release/IMG_conv_3x3_i8_c8s_66_LE_ELF.out: ./src/IMG_conv_3x3_i8_c8s//c66/IMG_conv_3x3_i8_c8s.c
./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_ELF/Release/IMG_conv_3x3_i8_c8s_66_LE_ELF.out: ./src/IMG_conv_3x3_i8_c8s//c66/IMG_conv_3x3_i8_c8s.h
./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_ELF/Release/IMG_conv_3x3_i8_c8s_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_ELF/Release/IMG_conv_3x3_i8_c8s_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_ELF/Release/IMG_conv_3x3_i8_c8s_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_ELF/Release/IMG_conv_3x3_i8_c8s_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_ELF/Release/IMG_conv_3x3_i8_c8s_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_ELF/Release/IMG_conv_3x3_i8_c8s_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_ELF/Release/IMG_conv_3x3_i8_c8s_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_ELF/Release/IMG_conv_3x3_i8_c8s_66_LE_ELF.out: ./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_ELF/.project
	-@ echo Importing Project IMG_conv_3x3_i8_c8s_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_conv_3x3_i8_c8s_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_3x3_i8_c8s/c66/IMG_conv_3x3_i8_c8s_66_LE_ELF"
	-@ echo Building Project IMG_conv_3x3_i8_c8s_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_conv_3x3_i8_c8s_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_conv_3x3_i8_c8s_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_ELF/.settings"

	-@ echo Project IMG_conv_3x3_i8_c8s_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_conv_3x3_i8_c8s//c66//IMG_conv_3x3_i8_c8s_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_conv_5x5_i16s_c16s_66_LE_COFF

#############################################################

all: ./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_COFF/Release/IMG_conv_5x5_i16s_c16s_66_LE_COFF.out

./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_conv_5x5_i16s_c16s_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I16S_C16S_66_LE_COFF_SRCIMG_CONV_5X5_I16S_C16S/IMG_conv_5x5_i16s_c16s_cn.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I16S_C16S_66_LE_COFF_SRCIMG_CONV_5X5_I16S_C16S/IMG_conv_5x5_i16s_c16s_d.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I16S_C16S_66_LE_COFF_SRCIMG_CONV_5X5_I16S_C16S/IMG_conv_5x5_i16s_c16s_idat.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I16S_C16S_66_LE_COFF_SRCIMG_CONV_5X5_I16S_C16S/IMG_conv_5x5_i16s_c16s_odat.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I16S_C16S_66_LE_COFF/IMG_conv_5x5_i16s_c16s.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I16S_C16S_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I16S_C16S_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I16S_C16S_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I16S_C16S_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_CONV_5X5_I16S_C16S_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_5x5_i16s_c16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_CONV_5X5_I16S_C16S_66_LE_COFF_SRCIMG_CONV_5X5_I16S_C16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_5x5_i16s_c16s" -ccs.definePathVariable EXT_ROOT__IMG_CONV_5X5_I16S_C16S_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CONV_5X5_I16S_C16S_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_conv_5x5_i16s_c16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CONV_5X5_I16S_C16S_66_LE_COFF=.././ >> ./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CONV_5X5_I16S_C16S_66_LE_COFF_SRCIMG_CONV_5X5_I16S_C16S=../../ >> ./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CONV_5X5_I16S_C16S_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CONV_5X5_I16S_C16S_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_COFF/Release/IMG_conv_5x5_i16s_c16s_66_LE_COFF.out: ./src/IMG_conv_5x5_i16s_c16s/IMG_conv_5x5_i16s_c16s.h
./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_COFF/Release/IMG_conv_5x5_i16s_c16s_66_LE_COFF.out: ./src/IMG_conv_5x5_i16s_c16s/IMG_conv_5x5_i16s_c16s_cn.c
./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_COFF/Release/IMG_conv_5x5_i16s_c16s_66_LE_COFF.out: ./src/IMG_conv_5x5_i16s_c16s/IMG_conv_5x5_i16s_c16s_cn.h
./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_COFF/Release/IMG_conv_5x5_i16s_c16s_66_LE_COFF.out: ./src/IMG_conv_5x5_i16s_c16s/IMG_conv_5x5_i16s_c16s_d.c
./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_COFF/Release/IMG_conv_5x5_i16s_c16s_66_LE_COFF.out: ./src/IMG_conv_5x5_i16s_c16s/IMG_conv_5x5_i16s_c16s_idat.c
./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_COFF/Release/IMG_conv_5x5_i16s_c16s_66_LE_COFF.out: ./src/IMG_conv_5x5_i16s_c16s/IMG_conv_5x5_i16s_c16s_odat.c
./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_COFF/Release/IMG_conv_5x5_i16s_c16s_66_LE_COFF.out: ./src/IMG_conv_5x5_i16s_c16s//c66/IMG_conv_5x5_i16s_c16s.c
./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_COFF/Release/IMG_conv_5x5_i16s_c16s_66_LE_COFF.out: ./src/IMG_conv_5x5_i16s_c16s//c66/IMG_conv_5x5_i16s_c16s.h
./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_COFF/Release/IMG_conv_5x5_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_COFF/Release/IMG_conv_5x5_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_COFF/Release/IMG_conv_5x5_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_COFF/Release/IMG_conv_5x5_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_COFF/Release/IMG_conv_5x5_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_COFF/Release/IMG_conv_5x5_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_COFF/Release/IMG_conv_5x5_i16s_c16s_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_COFF/Release/IMG_conv_5x5_i16s_c16s_66_LE_COFF.out: ./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_COFF/.project
	-@ echo Importing Project IMG_conv_5x5_i16s_c16s_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_conv_5x5_i16s_c16s_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_5x5_i16s_c16s/c66/IMG_conv_5x5_i16s_c16s_66_LE_COFF"
	-@ echo Building Project IMG_conv_5x5_i16s_c16s_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_conv_5x5_i16s_c16s_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_conv_5x5_i16s_c16s_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_COFF/.settings"

	-@ echo Project IMG_conv_5x5_i16s_c16s_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_conv_5x5_i16s_c16s_66_LE_ELF

#############################################################

all: ./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_ELF/Release/IMG_conv_5x5_i16s_c16s_66_LE_ELF.out

./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_conv_5x5_i16s_c16s_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I16S_C16S_66_LE_ELF_SRCIMG_CONV_5X5_I16S_C16S/IMG_conv_5x5_i16s_c16s_cn.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I16S_C16S_66_LE_ELF_SRCIMG_CONV_5X5_I16S_C16S/IMG_conv_5x5_i16s_c16s_d.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I16S_C16S_66_LE_ELF_SRCIMG_CONV_5X5_I16S_C16S/IMG_conv_5x5_i16s_c16s_idat.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I16S_C16S_66_LE_ELF_SRCIMG_CONV_5X5_I16S_C16S/IMG_conv_5x5_i16s_c16s_odat.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I16S_C16S_66_LE_ELF/IMG_conv_5x5_i16s_c16s.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I16S_C16S_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I16S_C16S_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I16S_C16S_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I16S_C16S_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_CONV_5X5_I16S_C16S_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_5x5_i16s_c16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_CONV_5X5_I16S_C16S_66_LE_ELF_SRCIMG_CONV_5X5_I16S_C16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_5x5_i16s_c16s" -ccs.definePathVariable EXT_ROOT__IMG_CONV_5X5_I16S_C16S_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CONV_5X5_I16S_C16S_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_conv_5x5_i16s_c16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CONV_5X5_I16S_C16S_66_LE_ELF=.././ >> ./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CONV_5X5_I16S_C16S_66_LE_ELF_SRCIMG_CONV_5X5_I16S_C16S=../../ >> ./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CONV_5X5_I16S_C16S_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CONV_5X5_I16S_C16S_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_ELF/Release/IMG_conv_5x5_i16s_c16s_66_LE_ELF.out: ./src/IMG_conv_5x5_i16s_c16s/IMG_conv_5x5_i16s_c16s.h
./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_ELF/Release/IMG_conv_5x5_i16s_c16s_66_LE_ELF.out: ./src/IMG_conv_5x5_i16s_c16s/IMG_conv_5x5_i16s_c16s_cn.c
./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_ELF/Release/IMG_conv_5x5_i16s_c16s_66_LE_ELF.out: ./src/IMG_conv_5x5_i16s_c16s/IMG_conv_5x5_i16s_c16s_cn.h
./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_ELF/Release/IMG_conv_5x5_i16s_c16s_66_LE_ELF.out: ./src/IMG_conv_5x5_i16s_c16s/IMG_conv_5x5_i16s_c16s_d.c
./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_ELF/Release/IMG_conv_5x5_i16s_c16s_66_LE_ELF.out: ./src/IMG_conv_5x5_i16s_c16s/IMG_conv_5x5_i16s_c16s_idat.c
./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_ELF/Release/IMG_conv_5x5_i16s_c16s_66_LE_ELF.out: ./src/IMG_conv_5x5_i16s_c16s/IMG_conv_5x5_i16s_c16s_odat.c
./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_ELF/Release/IMG_conv_5x5_i16s_c16s_66_LE_ELF.out: ./src/IMG_conv_5x5_i16s_c16s//c66/IMG_conv_5x5_i16s_c16s.c
./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_ELF/Release/IMG_conv_5x5_i16s_c16s_66_LE_ELF.out: ./src/IMG_conv_5x5_i16s_c16s//c66/IMG_conv_5x5_i16s_c16s.h
./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_ELF/Release/IMG_conv_5x5_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_ELF/Release/IMG_conv_5x5_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_ELF/Release/IMG_conv_5x5_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_ELF/Release/IMG_conv_5x5_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_ELF/Release/IMG_conv_5x5_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_ELF/Release/IMG_conv_5x5_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_ELF/Release/IMG_conv_5x5_i16s_c16s_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_ELF/Release/IMG_conv_5x5_i16s_c16s_66_LE_ELF.out: ./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_ELF/.project
	-@ echo Importing Project IMG_conv_5x5_i16s_c16s_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_conv_5x5_i16s_c16s_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_5x5_i16s_c16s/c66/IMG_conv_5x5_i16s_c16s_66_LE_ELF"
	-@ echo Building Project IMG_conv_5x5_i16s_c16s_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_conv_5x5_i16s_c16s_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_conv_5x5_i16s_c16s_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_ELF/.settings"

	-@ echo Project IMG_conv_5x5_i16s_c16s_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_conv_5x5_i16s_c16s//c66//IMG_conv_5x5_i16s_c16s_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_conv_5x5_i8_c16s_66_LE_COFF

#############################################################

all: ./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_COFF/Release/IMG_conv_5x5_i8_c16s_66_LE_COFF.out

./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_conv_5x5_i8_c16s_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I8_C16S_66_LE_COFF_SRCIMG_CONV_5X5_I8_C16S/IMG_conv_5x5_i8_c16s_cn.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I8_C16S_66_LE_COFF_SRCIMG_CONV_5X5_I8_C16S/IMG_conv_5x5_i8_c16s_d.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I8_C16S_66_LE_COFF_SRCIMG_CONV_5X5_I8_C16S/IMG_conv_5x5_i8_c16s_idat.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I8_C16S_66_LE_COFF_SRCIMG_CONV_5X5_I8_C16S/IMG_conv_5x5_i8_c16s_odat.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I8_C16S_66_LE_COFF/IMG_conv_5x5_i8_c16s.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I8_C16S_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I8_C16S_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I8_C16S_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I8_C16S_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_CONV_5X5_I8_C16S_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_5x5_i8_c16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_CONV_5X5_I8_C16S_66_LE_COFF_SRCIMG_CONV_5X5_I8_C16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_5x5_i8_c16s" -ccs.definePathVariable EXT_ROOT__IMG_CONV_5X5_I8_C16S_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CONV_5X5_I8_C16S_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_conv_5x5_i8_c16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CONV_5X5_I8_C16S_66_LE_COFF=.././ >> ./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CONV_5X5_I8_C16S_66_LE_COFF_SRCIMG_CONV_5X5_I8_C16S=../../ >> ./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CONV_5X5_I8_C16S_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CONV_5X5_I8_C16S_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_COFF/Release/IMG_conv_5x5_i8_c16s_66_LE_COFF.out: ./src/IMG_conv_5x5_i8_c16s/IMG_conv_5x5_i8_c16s.h
./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_COFF/Release/IMG_conv_5x5_i8_c16s_66_LE_COFF.out: ./src/IMG_conv_5x5_i8_c16s/IMG_conv_5x5_i8_c16s_cn.c
./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_COFF/Release/IMG_conv_5x5_i8_c16s_66_LE_COFF.out: ./src/IMG_conv_5x5_i8_c16s/IMG_conv_5x5_i8_c16s_cn.h
./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_COFF/Release/IMG_conv_5x5_i8_c16s_66_LE_COFF.out: ./src/IMG_conv_5x5_i8_c16s/IMG_conv_5x5_i8_c16s_d.c
./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_COFF/Release/IMG_conv_5x5_i8_c16s_66_LE_COFF.out: ./src/IMG_conv_5x5_i8_c16s/IMG_conv_5x5_i8_c16s_idat.c
./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_COFF/Release/IMG_conv_5x5_i8_c16s_66_LE_COFF.out: ./src/IMG_conv_5x5_i8_c16s/IMG_conv_5x5_i8_c16s_odat.c
./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_COFF/Release/IMG_conv_5x5_i8_c16s_66_LE_COFF.out: ./src/IMG_conv_5x5_i8_c16s//c66/IMG_conv_5x5_i8_c16s.c
./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_COFF/Release/IMG_conv_5x5_i8_c16s_66_LE_COFF.out: ./src/IMG_conv_5x5_i8_c16s//c66/IMG_conv_5x5_i8_c16s.h
./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_COFF/Release/IMG_conv_5x5_i8_c16s_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_COFF/Release/IMG_conv_5x5_i8_c16s_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_COFF/Release/IMG_conv_5x5_i8_c16s_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_COFF/Release/IMG_conv_5x5_i8_c16s_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_COFF/Release/IMG_conv_5x5_i8_c16s_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_COFF/Release/IMG_conv_5x5_i8_c16s_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_COFF/Release/IMG_conv_5x5_i8_c16s_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_COFF/Release/IMG_conv_5x5_i8_c16s_66_LE_COFF.out: ./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_COFF/.project
	-@ echo Importing Project IMG_conv_5x5_i8_c16s_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_conv_5x5_i8_c16s_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_5x5_i8_c16s/c66/IMG_conv_5x5_i8_c16s_66_LE_COFF"
	-@ echo Building Project IMG_conv_5x5_i8_c16s_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_conv_5x5_i8_c16s_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_conv_5x5_i8_c16s_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_COFF/.settings"

	-@ echo Project IMG_conv_5x5_i8_c16s_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_conv_5x5_i8_c16s_66_LE_ELF

#############################################################

all: ./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_ELF/Release/IMG_conv_5x5_i8_c16s_66_LE_ELF.out

./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_conv_5x5_i8_c16s_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I8_C16S_66_LE_ELF_SRCIMG_CONV_5X5_I8_C16S/IMG_conv_5x5_i8_c16s_cn.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I8_C16S_66_LE_ELF_SRCIMG_CONV_5X5_I8_C16S/IMG_conv_5x5_i8_c16s_d.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I8_C16S_66_LE_ELF_SRCIMG_CONV_5X5_I8_C16S/IMG_conv_5x5_i8_c16s_idat.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I8_C16S_66_LE_ELF_SRCIMG_CONV_5X5_I8_C16S/IMG_conv_5x5_i8_c16s_odat.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I8_C16S_66_LE_ELF/IMG_conv_5x5_i8_c16s.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I8_C16S_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I8_C16S_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I8_C16S_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I8_C16S_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_CONV_5X5_I8_C16S_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_5x5_i8_c16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_CONV_5X5_I8_C16S_66_LE_ELF_SRCIMG_CONV_5X5_I8_C16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_5x5_i8_c16s" -ccs.definePathVariable EXT_ROOT__IMG_CONV_5X5_I8_C16S_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CONV_5X5_I8_C16S_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_conv_5x5_i8_c16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CONV_5X5_I8_C16S_66_LE_ELF=.././ >> ./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CONV_5X5_I8_C16S_66_LE_ELF_SRCIMG_CONV_5X5_I8_C16S=../../ >> ./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CONV_5X5_I8_C16S_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CONV_5X5_I8_C16S_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_ELF/Release/IMG_conv_5x5_i8_c16s_66_LE_ELF.out: ./src/IMG_conv_5x5_i8_c16s/IMG_conv_5x5_i8_c16s.h
./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_ELF/Release/IMG_conv_5x5_i8_c16s_66_LE_ELF.out: ./src/IMG_conv_5x5_i8_c16s/IMG_conv_5x5_i8_c16s_cn.c
./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_ELF/Release/IMG_conv_5x5_i8_c16s_66_LE_ELF.out: ./src/IMG_conv_5x5_i8_c16s/IMG_conv_5x5_i8_c16s_cn.h
./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_ELF/Release/IMG_conv_5x5_i8_c16s_66_LE_ELF.out: ./src/IMG_conv_5x5_i8_c16s/IMG_conv_5x5_i8_c16s_d.c
./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_ELF/Release/IMG_conv_5x5_i8_c16s_66_LE_ELF.out: ./src/IMG_conv_5x5_i8_c16s/IMG_conv_5x5_i8_c16s_idat.c
./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_ELF/Release/IMG_conv_5x5_i8_c16s_66_LE_ELF.out: ./src/IMG_conv_5x5_i8_c16s/IMG_conv_5x5_i8_c16s_odat.c
./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_ELF/Release/IMG_conv_5x5_i8_c16s_66_LE_ELF.out: ./src/IMG_conv_5x5_i8_c16s//c66/IMG_conv_5x5_i8_c16s.c
./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_ELF/Release/IMG_conv_5x5_i8_c16s_66_LE_ELF.out: ./src/IMG_conv_5x5_i8_c16s//c66/IMG_conv_5x5_i8_c16s.h
./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_ELF/Release/IMG_conv_5x5_i8_c16s_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_ELF/Release/IMG_conv_5x5_i8_c16s_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_ELF/Release/IMG_conv_5x5_i8_c16s_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_ELF/Release/IMG_conv_5x5_i8_c16s_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_ELF/Release/IMG_conv_5x5_i8_c16s_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_ELF/Release/IMG_conv_5x5_i8_c16s_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_ELF/Release/IMG_conv_5x5_i8_c16s_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_ELF/Release/IMG_conv_5x5_i8_c16s_66_LE_ELF.out: ./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_ELF/.project
	-@ echo Importing Project IMG_conv_5x5_i8_c16s_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_conv_5x5_i8_c16s_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_5x5_i8_c16s/c66/IMG_conv_5x5_i8_c16s_66_LE_ELF"
	-@ echo Building Project IMG_conv_5x5_i8_c16s_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_conv_5x5_i8_c16s_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_conv_5x5_i8_c16s_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_ELF/.settings"

	-@ echo Project IMG_conv_5x5_i8_c16s_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_conv_5x5_i8_c16s//c66//IMG_conv_5x5_i8_c16s_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_conv_5x5_i8_c8s_66_LE_COFF

#############################################################

all: ./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_COFF/Release/IMG_conv_5x5_i8_c8s_66_LE_COFF.out

./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_conv_5x5_i8_c8s_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I8_C8S_66_LE_COFF_SRCIMG_CONV_5X5_I8_C8S/IMG_conv_5x5_i8_c8s_cn.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I8_C8S_66_LE_COFF_SRCIMG_CONV_5X5_I8_C8S/IMG_conv_5x5_i8_c8s_d.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I8_C8S_66_LE_COFF_SRCIMG_CONV_5X5_I8_C8S/IMG_conv_5x5_i8_c8s_idat.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I8_C8S_66_LE_COFF_SRCIMG_CONV_5X5_I8_C8S/IMG_conv_5x5_i8_c8s_odat.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I8_C8S_66_LE_COFF/IMG_conv_5x5_i8_c8s.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I8_C8S_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I8_C8S_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I8_C8S_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I8_C8S_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_CONV_5X5_I8_C8S_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_5x5_i8_c8s/c66" -ccs.definePathVariable EXT_ROOT__IMG_CONV_5X5_I8_C8S_66_LE_COFF_SRCIMG_CONV_5X5_I8_C8S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_5x5_i8_c8s" -ccs.definePathVariable EXT_ROOT__IMG_CONV_5X5_I8_C8S_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CONV_5X5_I8_C8S_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_conv_5x5_i8_c8s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CONV_5X5_I8_C8S_66_LE_COFF=.././ >> ./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CONV_5X5_I8_C8S_66_LE_COFF_SRCIMG_CONV_5X5_I8_C8S=../../ >> ./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CONV_5X5_I8_C8S_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CONV_5X5_I8_C8S_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_COFF/Release/IMG_conv_5x5_i8_c8s_66_LE_COFF.out: ./src/IMG_conv_5x5_i8_c8s/IMG_conv_5x5_i8_c8s.h
./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_COFF/Release/IMG_conv_5x5_i8_c8s_66_LE_COFF.out: ./src/IMG_conv_5x5_i8_c8s/IMG_conv_5x5_i8_c8s_cn.c
./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_COFF/Release/IMG_conv_5x5_i8_c8s_66_LE_COFF.out: ./src/IMG_conv_5x5_i8_c8s/IMG_conv_5x5_i8_c8s_cn.h
./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_COFF/Release/IMG_conv_5x5_i8_c8s_66_LE_COFF.out: ./src/IMG_conv_5x5_i8_c8s/IMG_conv_5x5_i8_c8s_d.c
./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_COFF/Release/IMG_conv_5x5_i8_c8s_66_LE_COFF.out: ./src/IMG_conv_5x5_i8_c8s/IMG_conv_5x5_i8_c8s_idat.c
./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_COFF/Release/IMG_conv_5x5_i8_c8s_66_LE_COFF.out: ./src/IMG_conv_5x5_i8_c8s/IMG_conv_5x5_i8_c8s_odat.c
./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_COFF/Release/IMG_conv_5x5_i8_c8s_66_LE_COFF.out: ./src/IMG_conv_5x5_i8_c8s//c66/IMG_conv_5x5_i8_c8s.c
./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_COFF/Release/IMG_conv_5x5_i8_c8s_66_LE_COFF.out: ./src/IMG_conv_5x5_i8_c8s//c66/IMG_conv_5x5_i8_c8s.h
./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_COFF/Release/IMG_conv_5x5_i8_c8s_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_COFF/Release/IMG_conv_5x5_i8_c8s_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_COFF/Release/IMG_conv_5x5_i8_c8s_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_COFF/Release/IMG_conv_5x5_i8_c8s_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_COFF/Release/IMG_conv_5x5_i8_c8s_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_COFF/Release/IMG_conv_5x5_i8_c8s_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_COFF/Release/IMG_conv_5x5_i8_c8s_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_COFF/Release/IMG_conv_5x5_i8_c8s_66_LE_COFF.out: ./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_COFF/.project
	-@ echo Importing Project IMG_conv_5x5_i8_c8s_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_conv_5x5_i8_c8s_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_5x5_i8_c8s/c66/IMG_conv_5x5_i8_c8s_66_LE_COFF"
	-@ echo Building Project IMG_conv_5x5_i8_c8s_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_conv_5x5_i8_c8s_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_conv_5x5_i8_c8s_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_COFF/.settings"

	-@ echo Project IMG_conv_5x5_i8_c8s_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_conv_5x5_i8_c8s_66_LE_ELF

#############################################################

all: ./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_ELF/Release/IMG_conv_5x5_i8_c8s_66_LE_ELF.out

./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_conv_5x5_i8_c8s_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I8_C8S_66_LE_ELF_SRCIMG_CONV_5X5_I8_C8S/IMG_conv_5x5_i8_c8s_cn.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I8_C8S_66_LE_ELF_SRCIMG_CONV_5X5_I8_C8S/IMG_conv_5x5_i8_c8s_d.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I8_C8S_66_LE_ELF_SRCIMG_CONV_5X5_I8_C8S/IMG_conv_5x5_i8_c8s_idat.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I8_C8S_66_LE_ELF_SRCIMG_CONV_5X5_I8_C8S/IMG_conv_5x5_i8_c8s_odat.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I8_C8S_66_LE_ELF/IMG_conv_5x5_i8_c8s.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I8_C8S_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I8_C8S_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I8_C8S_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CONV_5X5_I8_C8S_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_CONV_5X5_I8_C8S_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_5x5_i8_c8s/c66" -ccs.definePathVariable EXT_ROOT__IMG_CONV_5X5_I8_C8S_66_LE_ELF_SRCIMG_CONV_5X5_I8_C8S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_5x5_i8_c8s" -ccs.definePathVariable EXT_ROOT__IMG_CONV_5X5_I8_C8S_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CONV_5X5_I8_C8S_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_conv_5x5_i8_c8s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CONV_5X5_I8_C8S_66_LE_ELF=.././ >> ./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CONV_5X5_I8_C8S_66_LE_ELF_SRCIMG_CONV_5X5_I8_C8S=../../ >> ./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CONV_5X5_I8_C8S_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CONV_5X5_I8_C8S_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_ELF/Release/IMG_conv_5x5_i8_c8s_66_LE_ELF.out: ./src/IMG_conv_5x5_i8_c8s/IMG_conv_5x5_i8_c8s.h
./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_ELF/Release/IMG_conv_5x5_i8_c8s_66_LE_ELF.out: ./src/IMG_conv_5x5_i8_c8s/IMG_conv_5x5_i8_c8s_cn.c
./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_ELF/Release/IMG_conv_5x5_i8_c8s_66_LE_ELF.out: ./src/IMG_conv_5x5_i8_c8s/IMG_conv_5x5_i8_c8s_cn.h
./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_ELF/Release/IMG_conv_5x5_i8_c8s_66_LE_ELF.out: ./src/IMG_conv_5x5_i8_c8s/IMG_conv_5x5_i8_c8s_d.c
./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_ELF/Release/IMG_conv_5x5_i8_c8s_66_LE_ELF.out: ./src/IMG_conv_5x5_i8_c8s/IMG_conv_5x5_i8_c8s_idat.c
./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_ELF/Release/IMG_conv_5x5_i8_c8s_66_LE_ELF.out: ./src/IMG_conv_5x5_i8_c8s/IMG_conv_5x5_i8_c8s_odat.c
./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_ELF/Release/IMG_conv_5x5_i8_c8s_66_LE_ELF.out: ./src/IMG_conv_5x5_i8_c8s//c66/IMG_conv_5x5_i8_c8s.c
./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_ELF/Release/IMG_conv_5x5_i8_c8s_66_LE_ELF.out: ./src/IMG_conv_5x5_i8_c8s//c66/IMG_conv_5x5_i8_c8s.h
./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_ELF/Release/IMG_conv_5x5_i8_c8s_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_ELF/Release/IMG_conv_5x5_i8_c8s_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_ELF/Release/IMG_conv_5x5_i8_c8s_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_ELF/Release/IMG_conv_5x5_i8_c8s_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_ELF/Release/IMG_conv_5x5_i8_c8s_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_ELF/Release/IMG_conv_5x5_i8_c8s_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_ELF/Release/IMG_conv_5x5_i8_c8s_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_ELF/Release/IMG_conv_5x5_i8_c8s_66_LE_ELF.out: ./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_ELF/.project
	-@ echo Importing Project IMG_conv_5x5_i8_c8s_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_conv_5x5_i8_c8s_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_5x5_i8_c8s/c66/IMG_conv_5x5_i8_c8s_66_LE_ELF"
	-@ echo Building Project IMG_conv_5x5_i8_c8s_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_conv_5x5_i8_c8s_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_conv_5x5_i8_c8s_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_ELF/.settings"

	-@ echo Project IMG_conv_5x5_i8_c8s_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_conv_5x5_i8_c8s//c66//IMG_conv_5x5_i8_c8s_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_conv_7x7_i16s_c16s_66_LE_COFF

#############################################################

all: ./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_COFF/Release/IMG_conv_7x7_i16s_c16s_66_LE_COFF.out

./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_conv_7x7_i16s_c16s_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I16S_C16S_66_LE_COFF_SRCIMG_CONV_7X7_I16S_C16S/IMG_conv_7x7_i16s_c16s_cn.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I16S_C16S_66_LE_COFF_SRCIMG_CONV_7X7_I16S_C16S/IMG_conv_7x7_i16s_c16s_d.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I16S_C16S_66_LE_COFF_SRCIMG_CONV_7X7_I16S_C16S/IMG_conv_7x7_i16s_c16s_idat.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I16S_C16S_66_LE_COFF_SRCIMG_CONV_7X7_I16S_C16S/IMG_conv_7x7_i16s_c16s_odat.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I16S_C16S_66_LE_COFF/IMG_conv_7x7_i16s_c16s.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I16S_C16S_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I16S_C16S_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I16S_C16S_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I16S_C16S_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_CONV_7X7_I16S_C16S_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_7x7_i16s_c16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_CONV_7X7_I16S_C16S_66_LE_COFF_SRCIMG_CONV_7X7_I16S_C16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_7x7_i16s_c16s" -ccs.definePathVariable EXT_ROOT__IMG_CONV_7X7_I16S_C16S_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CONV_7X7_I16S_C16S_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_conv_7x7_i16s_c16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CONV_7X7_I16S_C16S_66_LE_COFF=.././ >> ./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CONV_7X7_I16S_C16S_66_LE_COFF_SRCIMG_CONV_7X7_I16S_C16S=../../ >> ./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CONV_7X7_I16S_C16S_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CONV_7X7_I16S_C16S_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_COFF/Release/IMG_conv_7x7_i16s_c16s_66_LE_COFF.out: ./src/IMG_conv_7x7_i16s_c16s/IMG_conv_7x7_i16s_c16s.h
./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_COFF/Release/IMG_conv_7x7_i16s_c16s_66_LE_COFF.out: ./src/IMG_conv_7x7_i16s_c16s/IMG_conv_7x7_i16s_c16s_cn.c
./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_COFF/Release/IMG_conv_7x7_i16s_c16s_66_LE_COFF.out: ./src/IMG_conv_7x7_i16s_c16s/IMG_conv_7x7_i16s_c16s_cn.h
./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_COFF/Release/IMG_conv_7x7_i16s_c16s_66_LE_COFF.out: ./src/IMG_conv_7x7_i16s_c16s/IMG_conv_7x7_i16s_c16s_d.c
./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_COFF/Release/IMG_conv_7x7_i16s_c16s_66_LE_COFF.out: ./src/IMG_conv_7x7_i16s_c16s/IMG_conv_7x7_i16s_c16s_idat.c
./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_COFF/Release/IMG_conv_7x7_i16s_c16s_66_LE_COFF.out: ./src/IMG_conv_7x7_i16s_c16s/IMG_conv_7x7_i16s_c16s_odat.c
./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_COFF/Release/IMG_conv_7x7_i16s_c16s_66_LE_COFF.out: ./src/IMG_conv_7x7_i16s_c16s//c66/IMG_conv_7x7_i16s_c16s.c
./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_COFF/Release/IMG_conv_7x7_i16s_c16s_66_LE_COFF.out: ./src/IMG_conv_7x7_i16s_c16s//c66/IMG_conv_7x7_i16s_c16s.h
./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_COFF/Release/IMG_conv_7x7_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_COFF/Release/IMG_conv_7x7_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_COFF/Release/IMG_conv_7x7_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_COFF/Release/IMG_conv_7x7_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_COFF/Release/IMG_conv_7x7_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_COFF/Release/IMG_conv_7x7_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_COFF/Release/IMG_conv_7x7_i16s_c16s_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_COFF/Release/IMG_conv_7x7_i16s_c16s_66_LE_COFF.out: ./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_COFF/.project
	-@ echo Importing Project IMG_conv_7x7_i16s_c16s_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_conv_7x7_i16s_c16s_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_7x7_i16s_c16s/c66/IMG_conv_7x7_i16s_c16s_66_LE_COFF"
	-@ echo Building Project IMG_conv_7x7_i16s_c16s_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_conv_7x7_i16s_c16s_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_conv_7x7_i16s_c16s_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_COFF/.settings"

	-@ echo Project IMG_conv_7x7_i16s_c16s_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_conv_7x7_i16s_c16s_66_LE_ELF

#############################################################

all: ./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_ELF/Release/IMG_conv_7x7_i16s_c16s_66_LE_ELF.out

./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_conv_7x7_i16s_c16s_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I16S_C16S_66_LE_ELF_SRCIMG_CONV_7X7_I16S_C16S/IMG_conv_7x7_i16s_c16s_cn.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I16S_C16S_66_LE_ELF_SRCIMG_CONV_7X7_I16S_C16S/IMG_conv_7x7_i16s_c16s_d.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I16S_C16S_66_LE_ELF_SRCIMG_CONV_7X7_I16S_C16S/IMG_conv_7x7_i16s_c16s_idat.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I16S_C16S_66_LE_ELF_SRCIMG_CONV_7X7_I16S_C16S/IMG_conv_7x7_i16s_c16s_odat.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I16S_C16S_66_LE_ELF/IMG_conv_7x7_i16s_c16s.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I16S_C16S_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I16S_C16S_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I16S_C16S_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I16S_C16S_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_CONV_7X7_I16S_C16S_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_7x7_i16s_c16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_CONV_7X7_I16S_C16S_66_LE_ELF_SRCIMG_CONV_7X7_I16S_C16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_7x7_i16s_c16s" -ccs.definePathVariable EXT_ROOT__IMG_CONV_7X7_I16S_C16S_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CONV_7X7_I16S_C16S_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_conv_7x7_i16s_c16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CONV_7X7_I16S_C16S_66_LE_ELF=.././ >> ./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CONV_7X7_I16S_C16S_66_LE_ELF_SRCIMG_CONV_7X7_I16S_C16S=../../ >> ./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CONV_7X7_I16S_C16S_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CONV_7X7_I16S_C16S_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_ELF/Release/IMG_conv_7x7_i16s_c16s_66_LE_ELF.out: ./src/IMG_conv_7x7_i16s_c16s/IMG_conv_7x7_i16s_c16s.h
./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_ELF/Release/IMG_conv_7x7_i16s_c16s_66_LE_ELF.out: ./src/IMG_conv_7x7_i16s_c16s/IMG_conv_7x7_i16s_c16s_cn.c
./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_ELF/Release/IMG_conv_7x7_i16s_c16s_66_LE_ELF.out: ./src/IMG_conv_7x7_i16s_c16s/IMG_conv_7x7_i16s_c16s_cn.h
./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_ELF/Release/IMG_conv_7x7_i16s_c16s_66_LE_ELF.out: ./src/IMG_conv_7x7_i16s_c16s/IMG_conv_7x7_i16s_c16s_d.c
./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_ELF/Release/IMG_conv_7x7_i16s_c16s_66_LE_ELF.out: ./src/IMG_conv_7x7_i16s_c16s/IMG_conv_7x7_i16s_c16s_idat.c
./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_ELF/Release/IMG_conv_7x7_i16s_c16s_66_LE_ELF.out: ./src/IMG_conv_7x7_i16s_c16s/IMG_conv_7x7_i16s_c16s_odat.c
./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_ELF/Release/IMG_conv_7x7_i16s_c16s_66_LE_ELF.out: ./src/IMG_conv_7x7_i16s_c16s//c66/IMG_conv_7x7_i16s_c16s.c
./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_ELF/Release/IMG_conv_7x7_i16s_c16s_66_LE_ELF.out: ./src/IMG_conv_7x7_i16s_c16s//c66/IMG_conv_7x7_i16s_c16s.h
./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_ELF/Release/IMG_conv_7x7_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_ELF/Release/IMG_conv_7x7_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_ELF/Release/IMG_conv_7x7_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_ELF/Release/IMG_conv_7x7_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_ELF/Release/IMG_conv_7x7_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_ELF/Release/IMG_conv_7x7_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_ELF/Release/IMG_conv_7x7_i16s_c16s_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_ELF/Release/IMG_conv_7x7_i16s_c16s_66_LE_ELF.out: ./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_ELF/.project
	-@ echo Importing Project IMG_conv_7x7_i16s_c16s_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_conv_7x7_i16s_c16s_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_7x7_i16s_c16s/c66/IMG_conv_7x7_i16s_c16s_66_LE_ELF"
	-@ echo Building Project IMG_conv_7x7_i16s_c16s_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_conv_7x7_i16s_c16s_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_conv_7x7_i16s_c16s_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_ELF/.settings"

	-@ echo Project IMG_conv_7x7_i16s_c16s_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_conv_7x7_i16s_c16s//c66//IMG_conv_7x7_i16s_c16s_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_conv_7x7_i8_c16s_66_LE_COFF

#############################################################

all: ./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_COFF/Release/IMG_conv_7x7_i8_c16s_66_LE_COFF.out

./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_conv_7x7_i8_c16s_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I8_C16S_66_LE_COFF_SRCIMG_CONV_7X7_I8_C16S/IMG_conv_7x7_i8_c16s_cn.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I8_C16S_66_LE_COFF_SRCIMG_CONV_7X7_I8_C16S/IMG_conv_7x7_i8_c16s_d.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I8_C16S_66_LE_COFF_SRCIMG_CONV_7X7_I8_C16S/IMG_conv_7x7_i8_c16s_idat.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I8_C16S_66_LE_COFF_SRCIMG_CONV_7X7_I8_C16S/IMG_conv_7x7_i8_c16s_odat.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I8_C16S_66_LE_COFF/IMG_conv_7x7_i8_c16s.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I8_C16S_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I8_C16S_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I8_C16S_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I8_C16S_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_CONV_7X7_I8_C16S_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_7x7_i8_c16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_CONV_7X7_I8_C16S_66_LE_COFF_SRCIMG_CONV_7X7_I8_C16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_7x7_i8_c16s" -ccs.definePathVariable EXT_ROOT__IMG_CONV_7X7_I8_C16S_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CONV_7X7_I8_C16S_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_conv_7x7_i8_c16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CONV_7X7_I8_C16S_66_LE_COFF=.././ >> ./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CONV_7X7_I8_C16S_66_LE_COFF_SRCIMG_CONV_7X7_I8_C16S=../../ >> ./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CONV_7X7_I8_C16S_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CONV_7X7_I8_C16S_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_COFF/Release/IMG_conv_7x7_i8_c16s_66_LE_COFF.out: ./src/IMG_conv_7x7_i8_c16s/IMG_conv_7x7_i8_c16s.h
./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_COFF/Release/IMG_conv_7x7_i8_c16s_66_LE_COFF.out: ./src/IMG_conv_7x7_i8_c16s/IMG_conv_7x7_i8_c16s_cn.c
./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_COFF/Release/IMG_conv_7x7_i8_c16s_66_LE_COFF.out: ./src/IMG_conv_7x7_i8_c16s/IMG_conv_7x7_i8_c16s_cn.h
./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_COFF/Release/IMG_conv_7x7_i8_c16s_66_LE_COFF.out: ./src/IMG_conv_7x7_i8_c16s/IMG_conv_7x7_i8_c16s_d.c
./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_COFF/Release/IMG_conv_7x7_i8_c16s_66_LE_COFF.out: ./src/IMG_conv_7x7_i8_c16s/IMG_conv_7x7_i8_c16s_idat.c
./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_COFF/Release/IMG_conv_7x7_i8_c16s_66_LE_COFF.out: ./src/IMG_conv_7x7_i8_c16s/IMG_conv_7x7_i8_c16s_odat.c
./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_COFF/Release/IMG_conv_7x7_i8_c16s_66_LE_COFF.out: ./src/IMG_conv_7x7_i8_c16s//c66/IMG_conv_7x7_i8_c16s.c
./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_COFF/Release/IMG_conv_7x7_i8_c16s_66_LE_COFF.out: ./src/IMG_conv_7x7_i8_c16s//c66/IMG_conv_7x7_i8_c16s.h
./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_COFF/Release/IMG_conv_7x7_i8_c16s_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_COFF/Release/IMG_conv_7x7_i8_c16s_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_COFF/Release/IMG_conv_7x7_i8_c16s_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_COFF/Release/IMG_conv_7x7_i8_c16s_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_COFF/Release/IMG_conv_7x7_i8_c16s_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_COFF/Release/IMG_conv_7x7_i8_c16s_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_COFF/Release/IMG_conv_7x7_i8_c16s_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_COFF/Release/IMG_conv_7x7_i8_c16s_66_LE_COFF.out: ./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_COFF/.project
	-@ echo Importing Project IMG_conv_7x7_i8_c16s_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_conv_7x7_i8_c16s_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_7x7_i8_c16s/c66/IMG_conv_7x7_i8_c16s_66_LE_COFF"
	-@ echo Building Project IMG_conv_7x7_i8_c16s_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_conv_7x7_i8_c16s_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_conv_7x7_i8_c16s_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_COFF/.settings"

	-@ echo Project IMG_conv_7x7_i8_c16s_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_conv_7x7_i8_c16s_66_LE_ELF

#############################################################

all: ./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_ELF/Release/IMG_conv_7x7_i8_c16s_66_LE_ELF.out

./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_conv_7x7_i8_c16s_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I8_C16S_66_LE_ELF_SRCIMG_CONV_7X7_I8_C16S/IMG_conv_7x7_i8_c16s_cn.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I8_C16S_66_LE_ELF_SRCIMG_CONV_7X7_I8_C16S/IMG_conv_7x7_i8_c16s_d.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I8_C16S_66_LE_ELF_SRCIMG_CONV_7X7_I8_C16S/IMG_conv_7x7_i8_c16s_idat.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I8_C16S_66_LE_ELF_SRCIMG_CONV_7X7_I8_C16S/IMG_conv_7x7_i8_c16s_odat.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I8_C16S_66_LE_ELF/IMG_conv_7x7_i8_c16s.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I8_C16S_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I8_C16S_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I8_C16S_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I8_C16S_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_CONV_7X7_I8_C16S_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_7x7_i8_c16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_CONV_7X7_I8_C16S_66_LE_ELF_SRCIMG_CONV_7X7_I8_C16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_7x7_i8_c16s" -ccs.definePathVariable EXT_ROOT__IMG_CONV_7X7_I8_C16S_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CONV_7X7_I8_C16S_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_conv_7x7_i8_c16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CONV_7X7_I8_C16S_66_LE_ELF=.././ >> ./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CONV_7X7_I8_C16S_66_LE_ELF_SRCIMG_CONV_7X7_I8_C16S=../../ >> ./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CONV_7X7_I8_C16S_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CONV_7X7_I8_C16S_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_ELF/Release/IMG_conv_7x7_i8_c16s_66_LE_ELF.out: ./src/IMG_conv_7x7_i8_c16s/IMG_conv_7x7_i8_c16s.h
./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_ELF/Release/IMG_conv_7x7_i8_c16s_66_LE_ELF.out: ./src/IMG_conv_7x7_i8_c16s/IMG_conv_7x7_i8_c16s_cn.c
./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_ELF/Release/IMG_conv_7x7_i8_c16s_66_LE_ELF.out: ./src/IMG_conv_7x7_i8_c16s/IMG_conv_7x7_i8_c16s_cn.h
./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_ELF/Release/IMG_conv_7x7_i8_c16s_66_LE_ELF.out: ./src/IMG_conv_7x7_i8_c16s/IMG_conv_7x7_i8_c16s_d.c
./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_ELF/Release/IMG_conv_7x7_i8_c16s_66_LE_ELF.out: ./src/IMG_conv_7x7_i8_c16s/IMG_conv_7x7_i8_c16s_idat.c
./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_ELF/Release/IMG_conv_7x7_i8_c16s_66_LE_ELF.out: ./src/IMG_conv_7x7_i8_c16s/IMG_conv_7x7_i8_c16s_odat.c
./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_ELF/Release/IMG_conv_7x7_i8_c16s_66_LE_ELF.out: ./src/IMG_conv_7x7_i8_c16s//c66/IMG_conv_7x7_i8_c16s.c
./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_ELF/Release/IMG_conv_7x7_i8_c16s_66_LE_ELF.out: ./src/IMG_conv_7x7_i8_c16s//c66/IMG_conv_7x7_i8_c16s.h
./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_ELF/Release/IMG_conv_7x7_i8_c16s_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_ELF/Release/IMG_conv_7x7_i8_c16s_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_ELF/Release/IMG_conv_7x7_i8_c16s_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_ELF/Release/IMG_conv_7x7_i8_c16s_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_ELF/Release/IMG_conv_7x7_i8_c16s_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_ELF/Release/IMG_conv_7x7_i8_c16s_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_ELF/Release/IMG_conv_7x7_i8_c16s_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_ELF/Release/IMG_conv_7x7_i8_c16s_66_LE_ELF.out: ./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_ELF/.project
	-@ echo Importing Project IMG_conv_7x7_i8_c16s_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_conv_7x7_i8_c16s_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_7x7_i8_c16s/c66/IMG_conv_7x7_i8_c16s_66_LE_ELF"
	-@ echo Building Project IMG_conv_7x7_i8_c16s_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_conv_7x7_i8_c16s_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_conv_7x7_i8_c16s_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_ELF/.settings"

	-@ echo Project IMG_conv_7x7_i8_c16s_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_conv_7x7_i8_c16s//c66//IMG_conv_7x7_i8_c16s_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_conv_7x7_i8_c8s_66_LE_COFF

#############################################################

all: ./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_COFF/Release/IMG_conv_7x7_i8_c8s_66_LE_COFF.out

./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_conv_7x7_i8_c8s_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I8_C8S_66_LE_COFF_SRCIMG_CONV_7X7_I8_C8S/IMG_conv_7x7_i8_c8s_cn.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I8_C8S_66_LE_COFF_SRCIMG_CONV_7X7_I8_C8S/IMG_conv_7x7_i8_c8s_d.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I8_C8S_66_LE_COFF_SRCIMG_CONV_7X7_I8_C8S/IMG_conv_7x7_i8_c8s_idat.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I8_C8S_66_LE_COFF_SRCIMG_CONV_7X7_I8_C8S/IMG_conv_7x7_i8_c8s_odat.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I8_C8S_66_LE_COFF/IMG_conv_7x7_i8_c8s.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I8_C8S_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I8_C8S_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I8_C8S_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I8_C8S_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_CONV_7X7_I8_C8S_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_7x7_i8_c8s/c66" -ccs.definePathVariable EXT_ROOT__IMG_CONV_7X7_I8_C8S_66_LE_COFF_SRCIMG_CONV_7X7_I8_C8S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_7x7_i8_c8s" -ccs.definePathVariable EXT_ROOT__IMG_CONV_7X7_I8_C8S_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CONV_7X7_I8_C8S_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_conv_7x7_i8_c8s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CONV_7X7_I8_C8S_66_LE_COFF=.././ >> ./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CONV_7X7_I8_C8S_66_LE_COFF_SRCIMG_CONV_7X7_I8_C8S=../../ >> ./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CONV_7X7_I8_C8S_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CONV_7X7_I8_C8S_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_COFF/Release/IMG_conv_7x7_i8_c8s_66_LE_COFF.out: ./src/IMG_conv_7x7_i8_c8s/IMG_conv_7x7_i8_c8s.h
./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_COFF/Release/IMG_conv_7x7_i8_c8s_66_LE_COFF.out: ./src/IMG_conv_7x7_i8_c8s/IMG_conv_7x7_i8_c8s_cn.c
./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_COFF/Release/IMG_conv_7x7_i8_c8s_66_LE_COFF.out: ./src/IMG_conv_7x7_i8_c8s/IMG_conv_7x7_i8_c8s_cn.h
./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_COFF/Release/IMG_conv_7x7_i8_c8s_66_LE_COFF.out: ./src/IMG_conv_7x7_i8_c8s/IMG_conv_7x7_i8_c8s_d.c
./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_COFF/Release/IMG_conv_7x7_i8_c8s_66_LE_COFF.out: ./src/IMG_conv_7x7_i8_c8s/IMG_conv_7x7_i8_c8s_idat.c
./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_COFF/Release/IMG_conv_7x7_i8_c8s_66_LE_COFF.out: ./src/IMG_conv_7x7_i8_c8s/IMG_conv_7x7_i8_c8s_odat.c
./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_COFF/Release/IMG_conv_7x7_i8_c8s_66_LE_COFF.out: ./src/IMG_conv_7x7_i8_c8s//c66/IMG_conv_7x7_i8_c8s.c
./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_COFF/Release/IMG_conv_7x7_i8_c8s_66_LE_COFF.out: ./src/IMG_conv_7x7_i8_c8s//c66/IMG_conv_7x7_i8_c8s.h
./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_COFF/Release/IMG_conv_7x7_i8_c8s_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_COFF/Release/IMG_conv_7x7_i8_c8s_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_COFF/Release/IMG_conv_7x7_i8_c8s_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_COFF/Release/IMG_conv_7x7_i8_c8s_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_COFF/Release/IMG_conv_7x7_i8_c8s_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_COFF/Release/IMG_conv_7x7_i8_c8s_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_COFF/Release/IMG_conv_7x7_i8_c8s_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_COFF/Release/IMG_conv_7x7_i8_c8s_66_LE_COFF.out: ./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_COFF/.project
	-@ echo Importing Project IMG_conv_7x7_i8_c8s_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_conv_7x7_i8_c8s_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_7x7_i8_c8s/c66/IMG_conv_7x7_i8_c8s_66_LE_COFF"
	-@ echo Building Project IMG_conv_7x7_i8_c8s_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_conv_7x7_i8_c8s_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_conv_7x7_i8_c8s_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_COFF/.settings"

	-@ echo Project IMG_conv_7x7_i8_c8s_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_conv_7x7_i8_c8s_66_LE_ELF

#############################################################

all: ./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_ELF/Release/IMG_conv_7x7_i8_c8s_66_LE_ELF.out

./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_conv_7x7_i8_c8s_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I8_C8S_66_LE_ELF_SRCIMG_CONV_7X7_I8_C8S/IMG_conv_7x7_i8_c8s_cn.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I8_C8S_66_LE_ELF_SRCIMG_CONV_7X7_I8_C8S/IMG_conv_7x7_i8_c8s_d.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I8_C8S_66_LE_ELF_SRCIMG_CONV_7X7_I8_C8S/IMG_conv_7x7_i8_c8s_idat.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I8_C8S_66_LE_ELF_SRCIMG_CONV_7X7_I8_C8S/IMG_conv_7x7_i8_c8s_odat.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I8_C8S_66_LE_ELF/IMG_conv_7x7_i8_c8s.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I8_C8S_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I8_C8S_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I8_C8S_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CONV_7X7_I8_C8S_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_CONV_7X7_I8_C8S_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_7x7_i8_c8s/c66" -ccs.definePathVariable EXT_ROOT__IMG_CONV_7X7_I8_C8S_66_LE_ELF_SRCIMG_CONV_7X7_I8_C8S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_7x7_i8_c8s" -ccs.definePathVariable EXT_ROOT__IMG_CONV_7X7_I8_C8S_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CONV_7X7_I8_C8S_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_conv_7x7_i8_c8s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CONV_7X7_I8_C8S_66_LE_ELF=.././ >> ./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CONV_7X7_I8_C8S_66_LE_ELF_SRCIMG_CONV_7X7_I8_C8S=../../ >> ./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CONV_7X7_I8_C8S_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CONV_7X7_I8_C8S_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_ELF/Release/IMG_conv_7x7_i8_c8s_66_LE_ELF.out: ./src/IMG_conv_7x7_i8_c8s/IMG_conv_7x7_i8_c8s.h
./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_ELF/Release/IMG_conv_7x7_i8_c8s_66_LE_ELF.out: ./src/IMG_conv_7x7_i8_c8s/IMG_conv_7x7_i8_c8s_cn.c
./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_ELF/Release/IMG_conv_7x7_i8_c8s_66_LE_ELF.out: ./src/IMG_conv_7x7_i8_c8s/IMG_conv_7x7_i8_c8s_cn.h
./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_ELF/Release/IMG_conv_7x7_i8_c8s_66_LE_ELF.out: ./src/IMG_conv_7x7_i8_c8s/IMG_conv_7x7_i8_c8s_d.c
./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_ELF/Release/IMG_conv_7x7_i8_c8s_66_LE_ELF.out: ./src/IMG_conv_7x7_i8_c8s/IMG_conv_7x7_i8_c8s_idat.c
./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_ELF/Release/IMG_conv_7x7_i8_c8s_66_LE_ELF.out: ./src/IMG_conv_7x7_i8_c8s/IMG_conv_7x7_i8_c8s_odat.c
./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_ELF/Release/IMG_conv_7x7_i8_c8s_66_LE_ELF.out: ./src/IMG_conv_7x7_i8_c8s//c66/IMG_conv_7x7_i8_c8s.c
./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_ELF/Release/IMG_conv_7x7_i8_c8s_66_LE_ELF.out: ./src/IMG_conv_7x7_i8_c8s//c66/IMG_conv_7x7_i8_c8s.h
./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_ELF/Release/IMG_conv_7x7_i8_c8s_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_ELF/Release/IMG_conv_7x7_i8_c8s_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_ELF/Release/IMG_conv_7x7_i8_c8s_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_ELF/Release/IMG_conv_7x7_i8_c8s_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_ELF/Release/IMG_conv_7x7_i8_c8s_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_ELF/Release/IMG_conv_7x7_i8_c8s_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_ELF/Release/IMG_conv_7x7_i8_c8s_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_ELF/Release/IMG_conv_7x7_i8_c8s_66_LE_ELF.out: ./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_ELF/.project
	-@ echo Importing Project IMG_conv_7x7_i8_c8s_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_conv_7x7_i8_c8s_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_conv_7x7_i8_c8s/c66/IMG_conv_7x7_i8_c8s_66_LE_ELF"
	-@ echo Building Project IMG_conv_7x7_i8_c8s_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_conv_7x7_i8_c8s_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_conv_7x7_i8_c8s_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_ELF/.settings"

	-@ echo Project IMG_conv_7x7_i8_c8s_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_conv_7x7_i8_c8s//c66//IMG_conv_7x7_i8_c8s_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_corr_11x11_i16s_c16s_66_LE_COFF

#############################################################

all: ./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_COFF/Release/IMG_corr_11x11_i16s_c16s_66_LE_COFF.out

./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_corr_11x11_i16s_c16s_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CORR_11X11_I16S_C16S_66_LE_COFF_SRCIMG_CORR_11X11_I16S_C16S/IMG_corr_11x11_i16s_c16s_cn.c -ccs.linkFile EXT_ROOT__IMG_CORR_11X11_I16S_C16S_66_LE_COFF_SRCIMG_CORR_11X11_I16S_C16S/IMG_corr_11x11_i16s_c16s_d.c -ccs.linkFile EXT_ROOT__IMG_CORR_11X11_I16S_C16S_66_LE_COFF_SRCIMG_CORR_11X11_I16S_C16S/IMG_corr_11x11_i16s_c16s_idat.c -ccs.linkFile EXT_ROOT__IMG_CORR_11X11_I16S_C16S_66_LE_COFF_SRCIMG_CORR_11X11_I16S_C16S/IMG_corr_11x11_i16s_c16s_odat.c -ccs.linkFile EXT_ROOT__IMG_CORR_11X11_I16S_C16S_66_LE_COFF/IMG_corr_11x11_i16s_c16s.c -ccs.linkFile EXT_ROOT__IMG_CORR_11X11_I16S_C16S_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CORR_11X11_I16S_C16S_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CORR_11X11_I16S_C16S_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CORR_11X11_I16S_C16S_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_CORR_11X11_I16S_C16S_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_11x11_i16s_c16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_CORR_11X11_I16S_C16S_66_LE_COFF_SRCIMG_CORR_11X11_I16S_C16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_11x11_i16s_c16s" -ccs.definePathVariable EXT_ROOT__IMG_CORR_11X11_I16S_C16S_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CORR_11X11_I16S_C16S_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_corr_11x11_i16s_c16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CORR_11X11_I16S_C16S_66_LE_COFF=.././ >> ./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CORR_11X11_I16S_C16S_66_LE_COFF_SRCIMG_CORR_11X11_I16S_C16S=../../ >> ./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CORR_11X11_I16S_C16S_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CORR_11X11_I16S_C16S_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_COFF/Release/IMG_corr_11x11_i16s_c16s_66_LE_COFF.out: ./src/IMG_corr_11x11_i16s_c16s/IMG_corr_11x11_i16s_c16s.h
./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_COFF/Release/IMG_corr_11x11_i16s_c16s_66_LE_COFF.out: ./src/IMG_corr_11x11_i16s_c16s/IMG_corr_11x11_i16s_c16s_cn.c
./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_COFF/Release/IMG_corr_11x11_i16s_c16s_66_LE_COFF.out: ./src/IMG_corr_11x11_i16s_c16s/IMG_corr_11x11_i16s_c16s_cn.h
./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_COFF/Release/IMG_corr_11x11_i16s_c16s_66_LE_COFF.out: ./src/IMG_corr_11x11_i16s_c16s/IMG_corr_11x11_i16s_c16s_d.c
./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_COFF/Release/IMG_corr_11x11_i16s_c16s_66_LE_COFF.out: ./src/IMG_corr_11x11_i16s_c16s/IMG_corr_11x11_i16s_c16s_idat.c
./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_COFF/Release/IMG_corr_11x11_i16s_c16s_66_LE_COFF.out: ./src/IMG_corr_11x11_i16s_c16s/IMG_corr_11x11_i16s_c16s_odat.c
./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_COFF/Release/IMG_corr_11x11_i16s_c16s_66_LE_COFF.out: ./src/IMG_corr_11x11_i16s_c16s//c66/IMG_corr_11x11_i16s_c16s.c
./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_COFF/Release/IMG_corr_11x11_i16s_c16s_66_LE_COFF.out: ./src/IMG_corr_11x11_i16s_c16s//c66/IMG_corr_11x11_i16s_c16s.h
./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_COFF/Release/IMG_corr_11x11_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_COFF/Release/IMG_corr_11x11_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_COFF/Release/IMG_corr_11x11_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_COFF/Release/IMG_corr_11x11_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_COFF/Release/IMG_corr_11x11_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_COFF/Release/IMG_corr_11x11_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_COFF/Release/IMG_corr_11x11_i16s_c16s_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_COFF/Release/IMG_corr_11x11_i16s_c16s_66_LE_COFF.out: ./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_COFF/.project
	-@ echo Importing Project IMG_corr_11x11_i16s_c16s_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_corr_11x11_i16s_c16s_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_11x11_i16s_c16s/c66/IMG_corr_11x11_i16s_c16s_66_LE_COFF"
	-@ echo Building Project IMG_corr_11x11_i16s_c16s_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_corr_11x11_i16s_c16s_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_corr_11x11_i16s_c16s_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_COFF/.settings"

	-@ echo Project IMG_corr_11x11_i16s_c16s_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_corr_11x11_i16s_c16s_66_LE_ELF

#############################################################

all: ./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_ELF/Release/IMG_corr_11x11_i16s_c16s_66_LE_ELF.out

./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_corr_11x11_i16s_c16s_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CORR_11X11_I16S_C16S_66_LE_ELF_SRCIMG_CORR_11X11_I16S_C16S/IMG_corr_11x11_i16s_c16s_cn.c -ccs.linkFile EXT_ROOT__IMG_CORR_11X11_I16S_C16S_66_LE_ELF_SRCIMG_CORR_11X11_I16S_C16S/IMG_corr_11x11_i16s_c16s_d.c -ccs.linkFile EXT_ROOT__IMG_CORR_11X11_I16S_C16S_66_LE_ELF_SRCIMG_CORR_11X11_I16S_C16S/IMG_corr_11x11_i16s_c16s_idat.c -ccs.linkFile EXT_ROOT__IMG_CORR_11X11_I16S_C16S_66_LE_ELF_SRCIMG_CORR_11X11_I16S_C16S/IMG_corr_11x11_i16s_c16s_odat.c -ccs.linkFile EXT_ROOT__IMG_CORR_11X11_I16S_C16S_66_LE_ELF/IMG_corr_11x11_i16s_c16s.c -ccs.linkFile EXT_ROOT__IMG_CORR_11X11_I16S_C16S_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CORR_11X11_I16S_C16S_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CORR_11X11_I16S_C16S_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CORR_11X11_I16S_C16S_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_CORR_11X11_I16S_C16S_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_11x11_i16s_c16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_CORR_11X11_I16S_C16S_66_LE_ELF_SRCIMG_CORR_11X11_I16S_C16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_11x11_i16s_c16s" -ccs.definePathVariable EXT_ROOT__IMG_CORR_11X11_I16S_C16S_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CORR_11X11_I16S_C16S_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_corr_11x11_i16s_c16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CORR_11X11_I16S_C16S_66_LE_ELF=.././ >> ./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CORR_11X11_I16S_C16S_66_LE_ELF_SRCIMG_CORR_11X11_I16S_C16S=../../ >> ./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CORR_11X11_I16S_C16S_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CORR_11X11_I16S_C16S_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_ELF/Release/IMG_corr_11x11_i16s_c16s_66_LE_ELF.out: ./src/IMG_corr_11x11_i16s_c16s/IMG_corr_11x11_i16s_c16s.h
./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_ELF/Release/IMG_corr_11x11_i16s_c16s_66_LE_ELF.out: ./src/IMG_corr_11x11_i16s_c16s/IMG_corr_11x11_i16s_c16s_cn.c
./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_ELF/Release/IMG_corr_11x11_i16s_c16s_66_LE_ELF.out: ./src/IMG_corr_11x11_i16s_c16s/IMG_corr_11x11_i16s_c16s_cn.h
./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_ELF/Release/IMG_corr_11x11_i16s_c16s_66_LE_ELF.out: ./src/IMG_corr_11x11_i16s_c16s/IMG_corr_11x11_i16s_c16s_d.c
./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_ELF/Release/IMG_corr_11x11_i16s_c16s_66_LE_ELF.out: ./src/IMG_corr_11x11_i16s_c16s/IMG_corr_11x11_i16s_c16s_idat.c
./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_ELF/Release/IMG_corr_11x11_i16s_c16s_66_LE_ELF.out: ./src/IMG_corr_11x11_i16s_c16s/IMG_corr_11x11_i16s_c16s_odat.c
./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_ELF/Release/IMG_corr_11x11_i16s_c16s_66_LE_ELF.out: ./src/IMG_corr_11x11_i16s_c16s//c66/IMG_corr_11x11_i16s_c16s.c
./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_ELF/Release/IMG_corr_11x11_i16s_c16s_66_LE_ELF.out: ./src/IMG_corr_11x11_i16s_c16s//c66/IMG_corr_11x11_i16s_c16s.h
./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_ELF/Release/IMG_corr_11x11_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_ELF/Release/IMG_corr_11x11_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_ELF/Release/IMG_corr_11x11_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_ELF/Release/IMG_corr_11x11_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_ELF/Release/IMG_corr_11x11_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_ELF/Release/IMG_corr_11x11_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_ELF/Release/IMG_corr_11x11_i16s_c16s_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_ELF/Release/IMG_corr_11x11_i16s_c16s_66_LE_ELF.out: ./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_ELF/.project
	-@ echo Importing Project IMG_corr_11x11_i16s_c16s_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_corr_11x11_i16s_c16s_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_11x11_i16s_c16s/c66/IMG_corr_11x11_i16s_c16s_66_LE_ELF"
	-@ echo Building Project IMG_corr_11x11_i16s_c16s_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_corr_11x11_i16s_c16s_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_corr_11x11_i16s_c16s_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_ELF/.settings"

	-@ echo Project IMG_corr_11x11_i16s_c16s_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_corr_11x11_i16s_c16s//c66//IMG_corr_11x11_i16s_c16s_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_corr_11x11_i8_c16s_66_LE_COFF

#############################################################

all: ./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_COFF/Release/IMG_corr_11x11_i8_c16s_66_LE_COFF.out

./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_corr_11x11_i8_c16s_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CORR_11X11_I8_C16S_66_LE_COFF_SRCIMG_CORR_11X11_I8_C16S/IMG_corr_11x11_i8_c16s_cn.c -ccs.linkFile EXT_ROOT__IMG_CORR_11X11_I8_C16S_66_LE_COFF_SRCIMG_CORR_11X11_I8_C16S/IMG_corr_11x11_i8_c16s_d.c -ccs.linkFile EXT_ROOT__IMG_CORR_11X11_I8_C16S_66_LE_COFF_SRCIMG_CORR_11X11_I8_C16S/IMG_corr_11x11_i8_c16s_idat.c -ccs.linkFile EXT_ROOT__IMG_CORR_11X11_I8_C16S_66_LE_COFF_SRCIMG_CORR_11X11_I8_C16S/IMG_corr_11x11_i8_c16s_odat.c -ccs.linkFile EXT_ROOT__IMG_CORR_11X11_I8_C16S_66_LE_COFF/IMG_corr_11x11_i8_c16s.c -ccs.linkFile EXT_ROOT__IMG_CORR_11X11_I8_C16S_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CORR_11X11_I8_C16S_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CORR_11X11_I8_C16S_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CORR_11X11_I8_C16S_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_CORR_11X11_I8_C16S_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_11x11_i8_c16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_CORR_11X11_I8_C16S_66_LE_COFF_SRCIMG_CORR_11X11_I8_C16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_11x11_i8_c16s" -ccs.definePathVariable EXT_ROOT__IMG_CORR_11X11_I8_C16S_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CORR_11X11_I8_C16S_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_corr_11x11_i8_c16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CORR_11X11_I8_C16S_66_LE_COFF=.././ >> ./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CORR_11X11_I8_C16S_66_LE_COFF_SRCIMG_CORR_11X11_I8_C16S=../../ >> ./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CORR_11X11_I8_C16S_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CORR_11X11_I8_C16S_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_COFF/Release/IMG_corr_11x11_i8_c16s_66_LE_COFF.out: ./src/IMG_corr_11x11_i8_c16s/IMG_corr_11x11_i8_c16s.h
./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_COFF/Release/IMG_corr_11x11_i8_c16s_66_LE_COFF.out: ./src/IMG_corr_11x11_i8_c16s/IMG_corr_11x11_i8_c16s_cn.c
./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_COFF/Release/IMG_corr_11x11_i8_c16s_66_LE_COFF.out: ./src/IMG_corr_11x11_i8_c16s/IMG_corr_11x11_i8_c16s_cn.h
./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_COFF/Release/IMG_corr_11x11_i8_c16s_66_LE_COFF.out: ./src/IMG_corr_11x11_i8_c16s/IMG_corr_11x11_i8_c16s_d.c
./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_COFF/Release/IMG_corr_11x11_i8_c16s_66_LE_COFF.out: ./src/IMG_corr_11x11_i8_c16s/IMG_corr_11x11_i8_c16s_idat.c
./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_COFF/Release/IMG_corr_11x11_i8_c16s_66_LE_COFF.out: ./src/IMG_corr_11x11_i8_c16s/IMG_corr_11x11_i8_c16s_odat.c
./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_COFF/Release/IMG_corr_11x11_i8_c16s_66_LE_COFF.out: ./src/IMG_corr_11x11_i8_c16s//c66/IMG_corr_11x11_i8_c16s.c
./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_COFF/Release/IMG_corr_11x11_i8_c16s_66_LE_COFF.out: ./src/IMG_corr_11x11_i8_c16s//c66/IMG_corr_11x11_i8_c16s.h
./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_COFF/Release/IMG_corr_11x11_i8_c16s_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_COFF/Release/IMG_corr_11x11_i8_c16s_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_COFF/Release/IMG_corr_11x11_i8_c16s_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_COFF/Release/IMG_corr_11x11_i8_c16s_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_COFF/Release/IMG_corr_11x11_i8_c16s_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_COFF/Release/IMG_corr_11x11_i8_c16s_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_COFF/Release/IMG_corr_11x11_i8_c16s_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_COFF/Release/IMG_corr_11x11_i8_c16s_66_LE_COFF.out: ./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_COFF/.project
	-@ echo Importing Project IMG_corr_11x11_i8_c16s_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_corr_11x11_i8_c16s_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_11x11_i8_c16s/c66/IMG_corr_11x11_i8_c16s_66_LE_COFF"
	-@ echo Building Project IMG_corr_11x11_i8_c16s_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_corr_11x11_i8_c16s_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_corr_11x11_i8_c16s_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_COFF/.settings"

	-@ echo Project IMG_corr_11x11_i8_c16s_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_corr_11x11_i8_c16s_66_LE_ELF

#############################################################

all: ./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_ELF/Release/IMG_corr_11x11_i8_c16s_66_LE_ELF.out

./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_corr_11x11_i8_c16s_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CORR_11X11_I8_C16S_66_LE_ELF_SRCIMG_CORR_11X11_I8_C16S/IMG_corr_11x11_i8_c16s_cn.c -ccs.linkFile EXT_ROOT__IMG_CORR_11X11_I8_C16S_66_LE_ELF_SRCIMG_CORR_11X11_I8_C16S/IMG_corr_11x11_i8_c16s_d.c -ccs.linkFile EXT_ROOT__IMG_CORR_11X11_I8_C16S_66_LE_ELF_SRCIMG_CORR_11X11_I8_C16S/IMG_corr_11x11_i8_c16s_idat.c -ccs.linkFile EXT_ROOT__IMG_CORR_11X11_I8_C16S_66_LE_ELF_SRCIMG_CORR_11X11_I8_C16S/IMG_corr_11x11_i8_c16s_odat.c -ccs.linkFile EXT_ROOT__IMG_CORR_11X11_I8_C16S_66_LE_ELF/IMG_corr_11x11_i8_c16s.c -ccs.linkFile EXT_ROOT__IMG_CORR_11X11_I8_C16S_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CORR_11X11_I8_C16S_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CORR_11X11_I8_C16S_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CORR_11X11_I8_C16S_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_CORR_11X11_I8_C16S_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_11x11_i8_c16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_CORR_11X11_I8_C16S_66_LE_ELF_SRCIMG_CORR_11X11_I8_C16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_11x11_i8_c16s" -ccs.definePathVariable EXT_ROOT__IMG_CORR_11X11_I8_C16S_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CORR_11X11_I8_C16S_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_corr_11x11_i8_c16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CORR_11X11_I8_C16S_66_LE_ELF=.././ >> ./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CORR_11X11_I8_C16S_66_LE_ELF_SRCIMG_CORR_11X11_I8_C16S=../../ >> ./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CORR_11X11_I8_C16S_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CORR_11X11_I8_C16S_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_ELF/Release/IMG_corr_11x11_i8_c16s_66_LE_ELF.out: ./src/IMG_corr_11x11_i8_c16s/IMG_corr_11x11_i8_c16s.h
./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_ELF/Release/IMG_corr_11x11_i8_c16s_66_LE_ELF.out: ./src/IMG_corr_11x11_i8_c16s/IMG_corr_11x11_i8_c16s_cn.c
./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_ELF/Release/IMG_corr_11x11_i8_c16s_66_LE_ELF.out: ./src/IMG_corr_11x11_i8_c16s/IMG_corr_11x11_i8_c16s_cn.h
./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_ELF/Release/IMG_corr_11x11_i8_c16s_66_LE_ELF.out: ./src/IMG_corr_11x11_i8_c16s/IMG_corr_11x11_i8_c16s_d.c
./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_ELF/Release/IMG_corr_11x11_i8_c16s_66_LE_ELF.out: ./src/IMG_corr_11x11_i8_c16s/IMG_corr_11x11_i8_c16s_idat.c
./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_ELF/Release/IMG_corr_11x11_i8_c16s_66_LE_ELF.out: ./src/IMG_corr_11x11_i8_c16s/IMG_corr_11x11_i8_c16s_odat.c
./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_ELF/Release/IMG_corr_11x11_i8_c16s_66_LE_ELF.out: ./src/IMG_corr_11x11_i8_c16s//c66/IMG_corr_11x11_i8_c16s.c
./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_ELF/Release/IMG_corr_11x11_i8_c16s_66_LE_ELF.out: ./src/IMG_corr_11x11_i8_c16s//c66/IMG_corr_11x11_i8_c16s.h
./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_ELF/Release/IMG_corr_11x11_i8_c16s_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_ELF/Release/IMG_corr_11x11_i8_c16s_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_ELF/Release/IMG_corr_11x11_i8_c16s_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_ELF/Release/IMG_corr_11x11_i8_c16s_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_ELF/Release/IMG_corr_11x11_i8_c16s_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_ELF/Release/IMG_corr_11x11_i8_c16s_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_ELF/Release/IMG_corr_11x11_i8_c16s_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_ELF/Release/IMG_corr_11x11_i8_c16s_66_LE_ELF.out: ./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_ELF/.project
	-@ echo Importing Project IMG_corr_11x11_i8_c16s_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_corr_11x11_i8_c16s_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_11x11_i8_c16s/c66/IMG_corr_11x11_i8_c16s_66_LE_ELF"
	-@ echo Building Project IMG_corr_11x11_i8_c16s_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_corr_11x11_i8_c16s_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_corr_11x11_i8_c16s_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_ELF/.settings"

	-@ echo Project IMG_corr_11x11_i8_c16s_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_corr_11x11_i8_c16s//c66//IMG_corr_11x11_i8_c16s_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_corr_3x3_i16s_c16s_66_LE_COFF

#############################################################

all: ./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_COFF/Release/IMG_corr_3x3_i16s_c16s_66_LE_COFF.out

./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_corr_3x3_i16s_c16s_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I16S_C16S_66_LE_COFF_SRCIMG_CORR_3X3_I16S_C16S/IMG_corr_3x3_i16s_c16s_cn.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I16S_C16S_66_LE_COFF_SRCIMG_CORR_3X3_I16S_C16S/IMG_corr_3x3_i16s_c16s_d.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I16S_C16S_66_LE_COFF_SRCIMG_CORR_3X3_I16S_C16S/IMG_corr_3x3_i16s_c16s_idat.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I16S_C16S_66_LE_COFF_SRCIMG_CORR_3X3_I16S_C16S/IMG_corr_3x3_i16s_c16s_odat.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I16S_C16S_66_LE_COFF/IMG_corr_3x3_i16s_c16s.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I16S_C16S_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I16S_C16S_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I16S_C16S_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I16S_C16S_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_CORR_3X3_I16S_C16S_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_3x3_i16s_c16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_CORR_3X3_I16S_C16S_66_LE_COFF_SRCIMG_CORR_3X3_I16S_C16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_3x3_i16s_c16s" -ccs.definePathVariable EXT_ROOT__IMG_CORR_3X3_I16S_C16S_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CORR_3X3_I16S_C16S_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_corr_3x3_i16s_c16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CORR_3X3_I16S_C16S_66_LE_COFF=.././ >> ./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CORR_3X3_I16S_C16S_66_LE_COFF_SRCIMG_CORR_3X3_I16S_C16S=../../ >> ./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CORR_3X3_I16S_C16S_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CORR_3X3_I16S_C16S_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_COFF/Release/IMG_corr_3x3_i16s_c16s_66_LE_COFF.out: ./src/IMG_corr_3x3_i16s_c16s/IMG_corr_3x3_i16s_c16s.h
./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_COFF/Release/IMG_corr_3x3_i16s_c16s_66_LE_COFF.out: ./src/IMG_corr_3x3_i16s_c16s/IMG_corr_3x3_i16s_c16s_cn.c
./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_COFF/Release/IMG_corr_3x3_i16s_c16s_66_LE_COFF.out: ./src/IMG_corr_3x3_i16s_c16s/IMG_corr_3x3_i16s_c16s_cn.h
./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_COFF/Release/IMG_corr_3x3_i16s_c16s_66_LE_COFF.out: ./src/IMG_corr_3x3_i16s_c16s/IMG_corr_3x3_i16s_c16s_d.c
./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_COFF/Release/IMG_corr_3x3_i16s_c16s_66_LE_COFF.out: ./src/IMG_corr_3x3_i16s_c16s/IMG_corr_3x3_i16s_c16s_idat.c
./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_COFF/Release/IMG_corr_3x3_i16s_c16s_66_LE_COFF.out: ./src/IMG_corr_3x3_i16s_c16s/IMG_corr_3x3_i16s_c16s_odat.c
./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_COFF/Release/IMG_corr_3x3_i16s_c16s_66_LE_COFF.out: ./src/IMG_corr_3x3_i16s_c16s//c66/IMG_corr_3x3_i16s_c16s.c
./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_COFF/Release/IMG_corr_3x3_i16s_c16s_66_LE_COFF.out: ./src/IMG_corr_3x3_i16s_c16s//c66/IMG_corr_3x3_i16s_c16s.h
./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_COFF/Release/IMG_corr_3x3_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_COFF/Release/IMG_corr_3x3_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_COFF/Release/IMG_corr_3x3_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_COFF/Release/IMG_corr_3x3_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_COFF/Release/IMG_corr_3x3_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_COFF/Release/IMG_corr_3x3_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_COFF/Release/IMG_corr_3x3_i16s_c16s_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_COFF/Release/IMG_corr_3x3_i16s_c16s_66_LE_COFF.out: ./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_COFF/.project
	-@ echo Importing Project IMG_corr_3x3_i16s_c16s_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_corr_3x3_i16s_c16s_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_3x3_i16s_c16s/c66/IMG_corr_3x3_i16s_c16s_66_LE_COFF"
	-@ echo Building Project IMG_corr_3x3_i16s_c16s_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_corr_3x3_i16s_c16s_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_corr_3x3_i16s_c16s_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_COFF/.settings"

	-@ echo Project IMG_corr_3x3_i16s_c16s_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_corr_3x3_i16s_c16s_66_LE_ELF

#############################################################

all: ./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_ELF/Release/IMG_corr_3x3_i16s_c16s_66_LE_ELF.out

./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_corr_3x3_i16s_c16s_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I16S_C16S_66_LE_ELF_SRCIMG_CORR_3X3_I16S_C16S/IMG_corr_3x3_i16s_c16s_cn.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I16S_C16S_66_LE_ELF_SRCIMG_CORR_3X3_I16S_C16S/IMG_corr_3x3_i16s_c16s_d.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I16S_C16S_66_LE_ELF_SRCIMG_CORR_3X3_I16S_C16S/IMG_corr_3x3_i16s_c16s_idat.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I16S_C16S_66_LE_ELF_SRCIMG_CORR_3X3_I16S_C16S/IMG_corr_3x3_i16s_c16s_odat.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I16S_C16S_66_LE_ELF/IMG_corr_3x3_i16s_c16s.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I16S_C16S_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I16S_C16S_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I16S_C16S_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I16S_C16S_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_CORR_3X3_I16S_C16S_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_3x3_i16s_c16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_CORR_3X3_I16S_C16S_66_LE_ELF_SRCIMG_CORR_3X3_I16S_C16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_3x3_i16s_c16s" -ccs.definePathVariable EXT_ROOT__IMG_CORR_3X3_I16S_C16S_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CORR_3X3_I16S_C16S_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_corr_3x3_i16s_c16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CORR_3X3_I16S_C16S_66_LE_ELF=.././ >> ./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CORR_3X3_I16S_C16S_66_LE_ELF_SRCIMG_CORR_3X3_I16S_C16S=../../ >> ./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CORR_3X3_I16S_C16S_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CORR_3X3_I16S_C16S_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_ELF/Release/IMG_corr_3x3_i16s_c16s_66_LE_ELF.out: ./src/IMG_corr_3x3_i16s_c16s/IMG_corr_3x3_i16s_c16s.h
./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_ELF/Release/IMG_corr_3x3_i16s_c16s_66_LE_ELF.out: ./src/IMG_corr_3x3_i16s_c16s/IMG_corr_3x3_i16s_c16s_cn.c
./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_ELF/Release/IMG_corr_3x3_i16s_c16s_66_LE_ELF.out: ./src/IMG_corr_3x3_i16s_c16s/IMG_corr_3x3_i16s_c16s_cn.h
./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_ELF/Release/IMG_corr_3x3_i16s_c16s_66_LE_ELF.out: ./src/IMG_corr_3x3_i16s_c16s/IMG_corr_3x3_i16s_c16s_d.c
./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_ELF/Release/IMG_corr_3x3_i16s_c16s_66_LE_ELF.out: ./src/IMG_corr_3x3_i16s_c16s/IMG_corr_3x3_i16s_c16s_idat.c
./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_ELF/Release/IMG_corr_3x3_i16s_c16s_66_LE_ELF.out: ./src/IMG_corr_3x3_i16s_c16s/IMG_corr_3x3_i16s_c16s_odat.c
./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_ELF/Release/IMG_corr_3x3_i16s_c16s_66_LE_ELF.out: ./src/IMG_corr_3x3_i16s_c16s//c66/IMG_corr_3x3_i16s_c16s.c
./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_ELF/Release/IMG_corr_3x3_i16s_c16s_66_LE_ELF.out: ./src/IMG_corr_3x3_i16s_c16s//c66/IMG_corr_3x3_i16s_c16s.h
./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_ELF/Release/IMG_corr_3x3_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_ELF/Release/IMG_corr_3x3_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_ELF/Release/IMG_corr_3x3_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_ELF/Release/IMG_corr_3x3_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_ELF/Release/IMG_corr_3x3_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_ELF/Release/IMG_corr_3x3_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_ELF/Release/IMG_corr_3x3_i16s_c16s_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_ELF/Release/IMG_corr_3x3_i16s_c16s_66_LE_ELF.out: ./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_ELF/.project
	-@ echo Importing Project IMG_corr_3x3_i16s_c16s_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_corr_3x3_i16s_c16s_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_3x3_i16s_c16s/c66/IMG_corr_3x3_i16s_c16s_66_LE_ELF"
	-@ echo Building Project IMG_corr_3x3_i16s_c16s_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_corr_3x3_i16s_c16s_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_corr_3x3_i16s_c16s_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_ELF/.settings"

	-@ echo Project IMG_corr_3x3_i16s_c16s_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_corr_3x3_i16s_c16s//c66//IMG_corr_3x3_i16s_c16s_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_corr_3x3_i16_c16_66_LE_COFF

#############################################################

all: ./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_COFF/Release/IMG_corr_3x3_i16_c16_66_LE_COFF.out

./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_corr_3x3_i16_c16_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I16_C16_66_LE_COFF_SRCIMG_CORR_3X3_I16_C16/IMG_corr_3x3_i16_c16_cn.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I16_C16_66_LE_COFF_SRCIMG_CORR_3X3_I16_C16/IMG_corr_3x3_i16_c16_d.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I16_C16_66_LE_COFF_SRCIMG_CORR_3X3_I16_C16/IMG_corr_3x3_i16_c16_idat.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I16_C16_66_LE_COFF_SRCIMG_CORR_3X3_I16_C16/IMG_corr_3x3_i16_c16_odat.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I16_C16_66_LE_COFF/IMG_corr_3x3_i16_c16.sa -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I16_C16_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I16_C16_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I16_C16_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I16_C16_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_CORR_3X3_I16_C16_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_3x3_i16_c16/c66" -ccs.definePathVariable EXT_ROOT__IMG_CORR_3X3_I16_C16_66_LE_COFF_SRCIMG_CORR_3X3_I16_C16 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_3x3_i16_c16" -ccs.definePathVariable EXT_ROOT__IMG_CORR_3X3_I16_C16_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CORR_3X3_I16_C16_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_corr_3x3_i16_c16.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CORR_3X3_I16_C16_66_LE_COFF=.././ >> ./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CORR_3X3_I16_C16_66_LE_COFF_SRCIMG_CORR_3X3_I16_C16=../../ >> ./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CORR_3X3_I16_C16_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CORR_3X3_I16_C16_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_COFF/Release/IMG_corr_3x3_i16_c16_66_LE_COFF.out: ./src/IMG_corr_3x3_i16_c16/IMG_corr_3x3_i16_c16.h
./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_COFF/Release/IMG_corr_3x3_i16_c16_66_LE_COFF.out: ./src/IMG_corr_3x3_i16_c16/IMG_corr_3x3_i16_c16_cn.c
./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_COFF/Release/IMG_corr_3x3_i16_c16_66_LE_COFF.out: ./src/IMG_corr_3x3_i16_c16/IMG_corr_3x3_i16_c16_cn.h
./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_COFF/Release/IMG_corr_3x3_i16_c16_66_LE_COFF.out: ./src/IMG_corr_3x3_i16_c16/IMG_corr_3x3_i16_c16_d.c
./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_COFF/Release/IMG_corr_3x3_i16_c16_66_LE_COFF.out: ./src/IMG_corr_3x3_i16_c16/IMG_corr_3x3_i16_c16_idat.c
./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_COFF/Release/IMG_corr_3x3_i16_c16_66_LE_COFF.out: ./src/IMG_corr_3x3_i16_c16/IMG_corr_3x3_i16_c16_odat.c
./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_COFF/Release/IMG_corr_3x3_i16_c16_66_LE_COFF.out: ./src/IMG_corr_3x3_i16_c16//c66/IMG_corr_3x3_i16_c16.h
./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_COFF/Release/IMG_corr_3x3_i16_c16_66_LE_COFF.out: ./src/IMG_corr_3x3_i16_c16//c66/IMG_corr_3x3_i16_c16.sa
./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_COFF/Release/IMG_corr_3x3_i16_c16_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_COFF/Release/IMG_corr_3x3_i16_c16_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_COFF/Release/IMG_corr_3x3_i16_c16_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_COFF/Release/IMG_corr_3x3_i16_c16_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_COFF/Release/IMG_corr_3x3_i16_c16_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_COFF/Release/IMG_corr_3x3_i16_c16_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_COFF/Release/IMG_corr_3x3_i16_c16_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_COFF/Release/IMG_corr_3x3_i16_c16_66_LE_COFF.out: ./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_COFF/.project
	-@ echo Importing Project IMG_corr_3x3_i16_c16_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_corr_3x3_i16_c16_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_3x3_i16_c16/c66/IMG_corr_3x3_i16_c16_66_LE_COFF"
	-@ echo Building Project IMG_corr_3x3_i16_c16_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_corr_3x3_i16_c16_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_corr_3x3_i16_c16_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_COFF/.settings"

	-@ echo Project IMG_corr_3x3_i16_c16_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_corr_3x3_i16_c16_66_LE_ELF

#############################################################

all: ./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_ELF/Release/IMG_corr_3x3_i16_c16_66_LE_ELF.out

./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_corr_3x3_i16_c16_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I16_C16_66_LE_ELF_SRCIMG_CORR_3X3_I16_C16/IMG_corr_3x3_i16_c16_cn.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I16_C16_66_LE_ELF_SRCIMG_CORR_3X3_I16_C16/IMG_corr_3x3_i16_c16_d.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I16_C16_66_LE_ELF_SRCIMG_CORR_3X3_I16_C16/IMG_corr_3x3_i16_c16_idat.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I16_C16_66_LE_ELF_SRCIMG_CORR_3X3_I16_C16/IMG_corr_3x3_i16_c16_odat.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I16_C16_66_LE_ELF/IMG_corr_3x3_i16_c16.sa -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I16_C16_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I16_C16_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I16_C16_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I16_C16_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_CORR_3X3_I16_C16_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_3x3_i16_c16/c66" -ccs.definePathVariable EXT_ROOT__IMG_CORR_3X3_I16_C16_66_LE_ELF_SRCIMG_CORR_3X3_I16_C16 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_3x3_i16_c16" -ccs.definePathVariable EXT_ROOT__IMG_CORR_3X3_I16_C16_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CORR_3X3_I16_C16_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_corr_3x3_i16_c16.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CORR_3X3_I16_C16_66_LE_ELF=.././ >> ./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CORR_3X3_I16_C16_66_LE_ELF_SRCIMG_CORR_3X3_I16_C16=../../ >> ./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CORR_3X3_I16_C16_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CORR_3X3_I16_C16_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_ELF/Release/IMG_corr_3x3_i16_c16_66_LE_ELF.out: ./src/IMG_corr_3x3_i16_c16/IMG_corr_3x3_i16_c16.h
./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_ELF/Release/IMG_corr_3x3_i16_c16_66_LE_ELF.out: ./src/IMG_corr_3x3_i16_c16/IMG_corr_3x3_i16_c16_cn.c
./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_ELF/Release/IMG_corr_3x3_i16_c16_66_LE_ELF.out: ./src/IMG_corr_3x3_i16_c16/IMG_corr_3x3_i16_c16_cn.h
./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_ELF/Release/IMG_corr_3x3_i16_c16_66_LE_ELF.out: ./src/IMG_corr_3x3_i16_c16/IMG_corr_3x3_i16_c16_d.c
./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_ELF/Release/IMG_corr_3x3_i16_c16_66_LE_ELF.out: ./src/IMG_corr_3x3_i16_c16/IMG_corr_3x3_i16_c16_idat.c
./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_ELF/Release/IMG_corr_3x3_i16_c16_66_LE_ELF.out: ./src/IMG_corr_3x3_i16_c16/IMG_corr_3x3_i16_c16_odat.c
./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_ELF/Release/IMG_corr_3x3_i16_c16_66_LE_ELF.out: ./src/IMG_corr_3x3_i16_c16//c66/IMG_corr_3x3_i16_c16.h
./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_ELF/Release/IMG_corr_3x3_i16_c16_66_LE_ELF.out: ./src/IMG_corr_3x3_i16_c16//c66/IMG_corr_3x3_i16_c16.sa
./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_ELF/Release/IMG_corr_3x3_i16_c16_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_ELF/Release/IMG_corr_3x3_i16_c16_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_ELF/Release/IMG_corr_3x3_i16_c16_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_ELF/Release/IMG_corr_3x3_i16_c16_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_ELF/Release/IMG_corr_3x3_i16_c16_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_ELF/Release/IMG_corr_3x3_i16_c16_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_ELF/Release/IMG_corr_3x3_i16_c16_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_ELF/Release/IMG_corr_3x3_i16_c16_66_LE_ELF.out: ./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_ELF/.project
	-@ echo Importing Project IMG_corr_3x3_i16_c16_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_corr_3x3_i16_c16_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_3x3_i16_c16/c66/IMG_corr_3x3_i16_c16_66_LE_ELF"
	-@ echo Building Project IMG_corr_3x3_i16_c16_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_corr_3x3_i16_c16_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_corr_3x3_i16_c16_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_ELF/.settings"

	-@ echo Project IMG_corr_3x3_i16_c16_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_corr_3x3_i16_c16//c66//IMG_corr_3x3_i16_c16_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_corr_3x3_i8_c16s_66_LE_COFF

#############################################################

all: ./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_COFF/Release/IMG_corr_3x3_i8_c16s_66_LE_COFF.out

./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_corr_3x3_i8_c16s_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I8_C16S_66_LE_COFF_SRCIMG_CORR_3X3_I8_C16S/IMG_corr_3x3_i8_c16s_cn.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I8_C16S_66_LE_COFF_SRCIMG_CORR_3X3_I8_C16S/IMG_corr_3x3_i8_c16s_d.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I8_C16S_66_LE_COFF_SRCIMG_CORR_3X3_I8_C16S/IMG_corr_3x3_i8_c16s_idat.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I8_C16S_66_LE_COFF_SRCIMG_CORR_3X3_I8_C16S/IMG_corr_3x3_i8_c16s_odat.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I8_C16S_66_LE_COFF/IMG_corr_3x3_i8_c16s.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I8_C16S_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I8_C16S_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I8_C16S_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I8_C16S_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_CORR_3X3_I8_C16S_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_3x3_i8_c16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_CORR_3X3_I8_C16S_66_LE_COFF_SRCIMG_CORR_3X3_I8_C16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_3x3_i8_c16s" -ccs.definePathVariable EXT_ROOT__IMG_CORR_3X3_I8_C16S_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CORR_3X3_I8_C16S_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_corr_3x3_i8_c16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CORR_3X3_I8_C16S_66_LE_COFF=.././ >> ./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CORR_3X3_I8_C16S_66_LE_COFF_SRCIMG_CORR_3X3_I8_C16S=../../ >> ./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CORR_3X3_I8_C16S_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CORR_3X3_I8_C16S_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_COFF/Release/IMG_corr_3x3_i8_c16s_66_LE_COFF.out: ./src/IMG_corr_3x3_i8_c16s/IMG_corr_3x3_i8_c16s.h
./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_COFF/Release/IMG_corr_3x3_i8_c16s_66_LE_COFF.out: ./src/IMG_corr_3x3_i8_c16s/IMG_corr_3x3_i8_c16s_cn.c
./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_COFF/Release/IMG_corr_3x3_i8_c16s_66_LE_COFF.out: ./src/IMG_corr_3x3_i8_c16s/IMG_corr_3x3_i8_c16s_cn.h
./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_COFF/Release/IMG_corr_3x3_i8_c16s_66_LE_COFF.out: ./src/IMG_corr_3x3_i8_c16s/IMG_corr_3x3_i8_c16s_d.c
./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_COFF/Release/IMG_corr_3x3_i8_c16s_66_LE_COFF.out: ./src/IMG_corr_3x3_i8_c16s/IMG_corr_3x3_i8_c16s_idat.c
./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_COFF/Release/IMG_corr_3x3_i8_c16s_66_LE_COFF.out: ./src/IMG_corr_3x3_i8_c16s/IMG_corr_3x3_i8_c16s_odat.c
./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_COFF/Release/IMG_corr_3x3_i8_c16s_66_LE_COFF.out: ./src/IMG_corr_3x3_i8_c16s//c66/IMG_corr_3x3_i8_c16s.c
./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_COFF/Release/IMG_corr_3x3_i8_c16s_66_LE_COFF.out: ./src/IMG_corr_3x3_i8_c16s//c66/IMG_corr_3x3_i8_c16s.h
./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_COFF/Release/IMG_corr_3x3_i8_c16s_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_COFF/Release/IMG_corr_3x3_i8_c16s_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_COFF/Release/IMG_corr_3x3_i8_c16s_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_COFF/Release/IMG_corr_3x3_i8_c16s_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_COFF/Release/IMG_corr_3x3_i8_c16s_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_COFF/Release/IMG_corr_3x3_i8_c16s_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_COFF/Release/IMG_corr_3x3_i8_c16s_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_COFF/Release/IMG_corr_3x3_i8_c16s_66_LE_COFF.out: ./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_COFF/.project
	-@ echo Importing Project IMG_corr_3x3_i8_c16s_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_corr_3x3_i8_c16s_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_3x3_i8_c16s/c66/IMG_corr_3x3_i8_c16s_66_LE_COFF"
	-@ echo Building Project IMG_corr_3x3_i8_c16s_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_corr_3x3_i8_c16s_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_corr_3x3_i8_c16s_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_COFF/.settings"

	-@ echo Project IMG_corr_3x3_i8_c16s_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_corr_3x3_i8_c16s_66_LE_ELF

#############################################################

all: ./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_ELF/Release/IMG_corr_3x3_i8_c16s_66_LE_ELF.out

./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_corr_3x3_i8_c16s_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I8_C16S_66_LE_ELF_SRCIMG_CORR_3X3_I8_C16S/IMG_corr_3x3_i8_c16s_cn.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I8_C16S_66_LE_ELF_SRCIMG_CORR_3X3_I8_C16S/IMG_corr_3x3_i8_c16s_d.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I8_C16S_66_LE_ELF_SRCIMG_CORR_3X3_I8_C16S/IMG_corr_3x3_i8_c16s_idat.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I8_C16S_66_LE_ELF_SRCIMG_CORR_3X3_I8_C16S/IMG_corr_3x3_i8_c16s_odat.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I8_C16S_66_LE_ELF/IMG_corr_3x3_i8_c16s.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I8_C16S_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I8_C16S_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I8_C16S_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I8_C16S_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_CORR_3X3_I8_C16S_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_3x3_i8_c16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_CORR_3X3_I8_C16S_66_LE_ELF_SRCIMG_CORR_3X3_I8_C16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_3x3_i8_c16s" -ccs.definePathVariable EXT_ROOT__IMG_CORR_3X3_I8_C16S_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CORR_3X3_I8_C16S_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_corr_3x3_i8_c16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CORR_3X3_I8_C16S_66_LE_ELF=.././ >> ./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CORR_3X3_I8_C16S_66_LE_ELF_SRCIMG_CORR_3X3_I8_C16S=../../ >> ./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CORR_3X3_I8_C16S_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CORR_3X3_I8_C16S_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_ELF/Release/IMG_corr_3x3_i8_c16s_66_LE_ELF.out: ./src/IMG_corr_3x3_i8_c16s/IMG_corr_3x3_i8_c16s.h
./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_ELF/Release/IMG_corr_3x3_i8_c16s_66_LE_ELF.out: ./src/IMG_corr_3x3_i8_c16s/IMG_corr_3x3_i8_c16s_cn.c
./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_ELF/Release/IMG_corr_3x3_i8_c16s_66_LE_ELF.out: ./src/IMG_corr_3x3_i8_c16s/IMG_corr_3x3_i8_c16s_cn.h
./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_ELF/Release/IMG_corr_3x3_i8_c16s_66_LE_ELF.out: ./src/IMG_corr_3x3_i8_c16s/IMG_corr_3x3_i8_c16s_d.c
./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_ELF/Release/IMG_corr_3x3_i8_c16s_66_LE_ELF.out: ./src/IMG_corr_3x3_i8_c16s/IMG_corr_3x3_i8_c16s_idat.c
./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_ELF/Release/IMG_corr_3x3_i8_c16s_66_LE_ELF.out: ./src/IMG_corr_3x3_i8_c16s/IMG_corr_3x3_i8_c16s_odat.c
./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_ELF/Release/IMG_corr_3x3_i8_c16s_66_LE_ELF.out: ./src/IMG_corr_3x3_i8_c16s//c66/IMG_corr_3x3_i8_c16s.c
./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_ELF/Release/IMG_corr_3x3_i8_c16s_66_LE_ELF.out: ./src/IMG_corr_3x3_i8_c16s//c66/IMG_corr_3x3_i8_c16s.h
./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_ELF/Release/IMG_corr_3x3_i8_c16s_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_ELF/Release/IMG_corr_3x3_i8_c16s_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_ELF/Release/IMG_corr_3x3_i8_c16s_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_ELF/Release/IMG_corr_3x3_i8_c16s_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_ELF/Release/IMG_corr_3x3_i8_c16s_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_ELF/Release/IMG_corr_3x3_i8_c16s_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_ELF/Release/IMG_corr_3x3_i8_c16s_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_ELF/Release/IMG_corr_3x3_i8_c16s_66_LE_ELF.out: ./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_ELF/.project
	-@ echo Importing Project IMG_corr_3x3_i8_c16s_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_corr_3x3_i8_c16s_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_3x3_i8_c16s/c66/IMG_corr_3x3_i8_c16s_66_LE_ELF"
	-@ echo Building Project IMG_corr_3x3_i8_c16s_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_corr_3x3_i8_c16s_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_corr_3x3_i8_c16s_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_ELF/.settings"

	-@ echo Project IMG_corr_3x3_i8_c16s_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_corr_3x3_i8_c16s//c66//IMG_corr_3x3_i8_c16s_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_corr_3x3_i8_c8_66_LE_COFF

#############################################################

all: ./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_COFF/Release/IMG_corr_3x3_i8_c8_66_LE_COFF.out

./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_corr_3x3_i8_c8_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I8_C8_66_LE_COFF_SRCIMG_CORR_3X3_I8_C8/IMG_corr_3x3_i8_c8_cn.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I8_C8_66_LE_COFF_SRCIMG_CORR_3X3_I8_C8/IMG_corr_3x3_i8_c8_d.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I8_C8_66_LE_COFF_SRCIMG_CORR_3X3_I8_C8/IMG_corr_3x3_i8_c8_idat.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I8_C8_66_LE_COFF_SRCIMG_CORR_3X3_I8_C8/IMG_corr_3x3_i8_c8_odat.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I8_C8_66_LE_COFF/IMG_corr_3x3_i8_c8.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I8_C8_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I8_C8_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I8_C8_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I8_C8_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_CORR_3X3_I8_C8_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_3x3_i8_c8/c66" -ccs.definePathVariable EXT_ROOT__IMG_CORR_3X3_I8_C8_66_LE_COFF_SRCIMG_CORR_3X3_I8_C8 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_3x3_i8_c8" -ccs.definePathVariable EXT_ROOT__IMG_CORR_3X3_I8_C8_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CORR_3X3_I8_C8_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_corr_3x3_i8_c8.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CORR_3X3_I8_C8_66_LE_COFF=.././ >> ./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CORR_3X3_I8_C8_66_LE_COFF_SRCIMG_CORR_3X3_I8_C8=../../ >> ./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CORR_3X3_I8_C8_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CORR_3X3_I8_C8_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_COFF/Release/IMG_corr_3x3_i8_c8_66_LE_COFF.out: ./src/IMG_corr_3x3_i8_c8/IMG_corr_3x3_i8_c8.h
./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_COFF/Release/IMG_corr_3x3_i8_c8_66_LE_COFF.out: ./src/IMG_corr_3x3_i8_c8/IMG_corr_3x3_i8_c8_cn.c
./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_COFF/Release/IMG_corr_3x3_i8_c8_66_LE_COFF.out: ./src/IMG_corr_3x3_i8_c8/IMG_corr_3x3_i8_c8_cn.h
./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_COFF/Release/IMG_corr_3x3_i8_c8_66_LE_COFF.out: ./src/IMG_corr_3x3_i8_c8/IMG_corr_3x3_i8_c8_d.c
./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_COFF/Release/IMG_corr_3x3_i8_c8_66_LE_COFF.out: ./src/IMG_corr_3x3_i8_c8/IMG_corr_3x3_i8_c8_idat.c
./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_COFF/Release/IMG_corr_3x3_i8_c8_66_LE_COFF.out: ./src/IMG_corr_3x3_i8_c8/IMG_corr_3x3_i8_c8_odat.c
./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_COFF/Release/IMG_corr_3x3_i8_c8_66_LE_COFF.out: ./src/IMG_corr_3x3_i8_c8//c66/IMG_corr_3x3_i8_c8.c
./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_COFF/Release/IMG_corr_3x3_i8_c8_66_LE_COFF.out: ./src/IMG_corr_3x3_i8_c8//c66/IMG_corr_3x3_i8_c8.h
./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_COFF/Release/IMG_corr_3x3_i8_c8_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_COFF/Release/IMG_corr_3x3_i8_c8_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_COFF/Release/IMG_corr_3x3_i8_c8_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_COFF/Release/IMG_corr_3x3_i8_c8_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_COFF/Release/IMG_corr_3x3_i8_c8_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_COFF/Release/IMG_corr_3x3_i8_c8_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_COFF/Release/IMG_corr_3x3_i8_c8_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_COFF/Release/IMG_corr_3x3_i8_c8_66_LE_COFF.out: ./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_COFF/.project
	-@ echo Importing Project IMG_corr_3x3_i8_c8_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_corr_3x3_i8_c8_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_3x3_i8_c8/c66/IMG_corr_3x3_i8_c8_66_LE_COFF"
	-@ echo Building Project IMG_corr_3x3_i8_c8_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_corr_3x3_i8_c8_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_corr_3x3_i8_c8_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_COFF/.settings"

	-@ echo Project IMG_corr_3x3_i8_c8_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_corr_3x3_i8_c8_66_LE_ELF

#############################################################

all: ./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_ELF/Release/IMG_corr_3x3_i8_c8_66_LE_ELF.out

./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_corr_3x3_i8_c8_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I8_C8_66_LE_ELF_SRCIMG_CORR_3X3_I8_C8/IMG_corr_3x3_i8_c8_cn.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I8_C8_66_LE_ELF_SRCIMG_CORR_3X3_I8_C8/IMG_corr_3x3_i8_c8_d.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I8_C8_66_LE_ELF_SRCIMG_CORR_3X3_I8_C8/IMG_corr_3x3_i8_c8_idat.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I8_C8_66_LE_ELF_SRCIMG_CORR_3X3_I8_C8/IMG_corr_3x3_i8_c8_odat.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I8_C8_66_LE_ELF/IMG_corr_3x3_i8_c8.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I8_C8_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I8_C8_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I8_C8_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CORR_3X3_I8_C8_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_CORR_3X3_I8_C8_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_3x3_i8_c8/c66" -ccs.definePathVariable EXT_ROOT__IMG_CORR_3X3_I8_C8_66_LE_ELF_SRCIMG_CORR_3X3_I8_C8 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_3x3_i8_c8" -ccs.definePathVariable EXT_ROOT__IMG_CORR_3X3_I8_C8_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CORR_3X3_I8_C8_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_corr_3x3_i8_c8.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CORR_3X3_I8_C8_66_LE_ELF=.././ >> ./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CORR_3X3_I8_C8_66_LE_ELF_SRCIMG_CORR_3X3_I8_C8=../../ >> ./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CORR_3X3_I8_C8_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CORR_3X3_I8_C8_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_ELF/Release/IMG_corr_3x3_i8_c8_66_LE_ELF.out: ./src/IMG_corr_3x3_i8_c8/IMG_corr_3x3_i8_c8.h
./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_ELF/Release/IMG_corr_3x3_i8_c8_66_LE_ELF.out: ./src/IMG_corr_3x3_i8_c8/IMG_corr_3x3_i8_c8_cn.c
./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_ELF/Release/IMG_corr_3x3_i8_c8_66_LE_ELF.out: ./src/IMG_corr_3x3_i8_c8/IMG_corr_3x3_i8_c8_cn.h
./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_ELF/Release/IMG_corr_3x3_i8_c8_66_LE_ELF.out: ./src/IMG_corr_3x3_i8_c8/IMG_corr_3x3_i8_c8_d.c
./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_ELF/Release/IMG_corr_3x3_i8_c8_66_LE_ELF.out: ./src/IMG_corr_3x3_i8_c8/IMG_corr_3x3_i8_c8_idat.c
./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_ELF/Release/IMG_corr_3x3_i8_c8_66_LE_ELF.out: ./src/IMG_corr_3x3_i8_c8/IMG_corr_3x3_i8_c8_odat.c
./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_ELF/Release/IMG_corr_3x3_i8_c8_66_LE_ELF.out: ./src/IMG_corr_3x3_i8_c8//c66/IMG_corr_3x3_i8_c8.c
./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_ELF/Release/IMG_corr_3x3_i8_c8_66_LE_ELF.out: ./src/IMG_corr_3x3_i8_c8//c66/IMG_corr_3x3_i8_c8.h
./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_ELF/Release/IMG_corr_3x3_i8_c8_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_ELF/Release/IMG_corr_3x3_i8_c8_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_ELF/Release/IMG_corr_3x3_i8_c8_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_ELF/Release/IMG_corr_3x3_i8_c8_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_ELF/Release/IMG_corr_3x3_i8_c8_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_ELF/Release/IMG_corr_3x3_i8_c8_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_ELF/Release/IMG_corr_3x3_i8_c8_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_ELF/Release/IMG_corr_3x3_i8_c8_66_LE_ELF.out: ./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_ELF/.project
	-@ echo Importing Project IMG_corr_3x3_i8_c8_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_corr_3x3_i8_c8_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_3x3_i8_c8/c66/IMG_corr_3x3_i8_c8_66_LE_ELF"
	-@ echo Building Project IMG_corr_3x3_i8_c8_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_corr_3x3_i8_c8_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_corr_3x3_i8_c8_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_ELF/.settings"

	-@ echo Project IMG_corr_3x3_i8_c8_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_corr_3x3_i8_c8//c66//IMG_corr_3x3_i8_c8_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_corr_5x5_i16s_c16s_66_LE_COFF

#############################################################

all: ./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_COFF/Release/IMG_corr_5x5_i16s_c16s_66_LE_COFF.out

./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_corr_5x5_i16s_c16s_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CORR_5X5_I16S_C16S_66_LE_COFF_SRCIMG_CORR_5X5_I16S_C16S/IMG_corr_5x5_i16s_c16s_cn.c -ccs.linkFile EXT_ROOT__IMG_CORR_5X5_I16S_C16S_66_LE_COFF_SRCIMG_CORR_5X5_I16S_C16S/IMG_corr_5x5_i16s_c16s_d.c -ccs.linkFile EXT_ROOT__IMG_CORR_5X5_I16S_C16S_66_LE_COFF_SRCIMG_CORR_5X5_I16S_C16S/IMG_corr_5x5_i16s_c16s_idat.c -ccs.linkFile EXT_ROOT__IMG_CORR_5X5_I16S_C16S_66_LE_COFF_SRCIMG_CORR_5X5_I16S_C16S/IMG_corr_5x5_i16s_c16s_odat.c -ccs.linkFile EXT_ROOT__IMG_CORR_5X5_I16S_C16S_66_LE_COFF/IMG_corr_5x5_i16s_c16s.c -ccs.linkFile EXT_ROOT__IMG_CORR_5X5_I16S_C16S_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CORR_5X5_I16S_C16S_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CORR_5X5_I16S_C16S_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CORR_5X5_I16S_C16S_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_CORR_5X5_I16S_C16S_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_5x5_i16s_c16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_CORR_5X5_I16S_C16S_66_LE_COFF_SRCIMG_CORR_5X5_I16S_C16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_5x5_i16s_c16s" -ccs.definePathVariable EXT_ROOT__IMG_CORR_5X5_I16S_C16S_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CORR_5X5_I16S_C16S_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_corr_5x5_i16s_c16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CORR_5X5_I16S_C16S_66_LE_COFF=.././ >> ./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CORR_5X5_I16S_C16S_66_LE_COFF_SRCIMG_CORR_5X5_I16S_C16S=../../ >> ./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CORR_5X5_I16S_C16S_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CORR_5X5_I16S_C16S_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_COFF/Release/IMG_corr_5x5_i16s_c16s_66_LE_COFF.out: ./src/IMG_corr_5x5_i16s_c16s/IMG_corr_5x5_i16s_c16s.h
./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_COFF/Release/IMG_corr_5x5_i16s_c16s_66_LE_COFF.out: ./src/IMG_corr_5x5_i16s_c16s/IMG_corr_5x5_i16s_c16s_cn.c
./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_COFF/Release/IMG_corr_5x5_i16s_c16s_66_LE_COFF.out: ./src/IMG_corr_5x5_i16s_c16s/IMG_corr_5x5_i16s_c16s_cn.h
./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_COFF/Release/IMG_corr_5x5_i16s_c16s_66_LE_COFF.out: ./src/IMG_corr_5x5_i16s_c16s/IMG_corr_5x5_i16s_c16s_d.c
./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_COFF/Release/IMG_corr_5x5_i16s_c16s_66_LE_COFF.out: ./src/IMG_corr_5x5_i16s_c16s/IMG_corr_5x5_i16s_c16s_idat.c
./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_COFF/Release/IMG_corr_5x5_i16s_c16s_66_LE_COFF.out: ./src/IMG_corr_5x5_i16s_c16s/IMG_corr_5x5_i16s_c16s_odat.c
./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_COFF/Release/IMG_corr_5x5_i16s_c16s_66_LE_COFF.out: ./src/IMG_corr_5x5_i16s_c16s//c66/IMG_corr_5x5_i16s_c16s.c
./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_COFF/Release/IMG_corr_5x5_i16s_c16s_66_LE_COFF.out: ./src/IMG_corr_5x5_i16s_c16s//c66/IMG_corr_5x5_i16s_c16s.h
./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_COFF/Release/IMG_corr_5x5_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_COFF/Release/IMG_corr_5x5_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_COFF/Release/IMG_corr_5x5_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_COFF/Release/IMG_corr_5x5_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_COFF/Release/IMG_corr_5x5_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_COFF/Release/IMG_corr_5x5_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_COFF/Release/IMG_corr_5x5_i16s_c16s_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_COFF/Release/IMG_corr_5x5_i16s_c16s_66_LE_COFF.out: ./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_COFF/.project
	-@ echo Importing Project IMG_corr_5x5_i16s_c16s_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_corr_5x5_i16s_c16s_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_5x5_i16s_c16s/c66/IMG_corr_5x5_i16s_c16s_66_LE_COFF"
	-@ echo Building Project IMG_corr_5x5_i16s_c16s_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_corr_5x5_i16s_c16s_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_corr_5x5_i16s_c16s_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_COFF/.settings"

	-@ echo Project IMG_corr_5x5_i16s_c16s_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_corr_5x5_i16s_c16s_66_LE_ELF

#############################################################

all: ./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_ELF/Release/IMG_corr_5x5_i16s_c16s_66_LE_ELF.out

./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_corr_5x5_i16s_c16s_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CORR_5X5_I16S_C16S_66_LE_ELF_SRCIMG_CORR_5X5_I16S_C16S/IMG_corr_5x5_i16s_c16s_cn.c -ccs.linkFile EXT_ROOT__IMG_CORR_5X5_I16S_C16S_66_LE_ELF_SRCIMG_CORR_5X5_I16S_C16S/IMG_corr_5x5_i16s_c16s_d.c -ccs.linkFile EXT_ROOT__IMG_CORR_5X5_I16S_C16S_66_LE_ELF_SRCIMG_CORR_5X5_I16S_C16S/IMG_corr_5x5_i16s_c16s_idat.c -ccs.linkFile EXT_ROOT__IMG_CORR_5X5_I16S_C16S_66_LE_ELF_SRCIMG_CORR_5X5_I16S_C16S/IMG_corr_5x5_i16s_c16s_odat.c -ccs.linkFile EXT_ROOT__IMG_CORR_5X5_I16S_C16S_66_LE_ELF/IMG_corr_5x5_i16s_c16s.c -ccs.linkFile EXT_ROOT__IMG_CORR_5X5_I16S_C16S_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CORR_5X5_I16S_C16S_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CORR_5X5_I16S_C16S_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CORR_5X5_I16S_C16S_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_CORR_5X5_I16S_C16S_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_5x5_i16s_c16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_CORR_5X5_I16S_C16S_66_LE_ELF_SRCIMG_CORR_5X5_I16S_C16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_5x5_i16s_c16s" -ccs.definePathVariable EXT_ROOT__IMG_CORR_5X5_I16S_C16S_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CORR_5X5_I16S_C16S_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_corr_5x5_i16s_c16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CORR_5X5_I16S_C16S_66_LE_ELF=.././ >> ./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CORR_5X5_I16S_C16S_66_LE_ELF_SRCIMG_CORR_5X5_I16S_C16S=../../ >> ./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CORR_5X5_I16S_C16S_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CORR_5X5_I16S_C16S_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_ELF/Release/IMG_corr_5x5_i16s_c16s_66_LE_ELF.out: ./src/IMG_corr_5x5_i16s_c16s/IMG_corr_5x5_i16s_c16s.h
./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_ELF/Release/IMG_corr_5x5_i16s_c16s_66_LE_ELF.out: ./src/IMG_corr_5x5_i16s_c16s/IMG_corr_5x5_i16s_c16s_cn.c
./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_ELF/Release/IMG_corr_5x5_i16s_c16s_66_LE_ELF.out: ./src/IMG_corr_5x5_i16s_c16s/IMG_corr_5x5_i16s_c16s_cn.h
./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_ELF/Release/IMG_corr_5x5_i16s_c16s_66_LE_ELF.out: ./src/IMG_corr_5x5_i16s_c16s/IMG_corr_5x5_i16s_c16s_d.c
./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_ELF/Release/IMG_corr_5x5_i16s_c16s_66_LE_ELF.out: ./src/IMG_corr_5x5_i16s_c16s/IMG_corr_5x5_i16s_c16s_idat.c
./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_ELF/Release/IMG_corr_5x5_i16s_c16s_66_LE_ELF.out: ./src/IMG_corr_5x5_i16s_c16s/IMG_corr_5x5_i16s_c16s_odat.c
./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_ELF/Release/IMG_corr_5x5_i16s_c16s_66_LE_ELF.out: ./src/IMG_corr_5x5_i16s_c16s//c66/IMG_corr_5x5_i16s_c16s.c
./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_ELF/Release/IMG_corr_5x5_i16s_c16s_66_LE_ELF.out: ./src/IMG_corr_5x5_i16s_c16s//c66/IMG_corr_5x5_i16s_c16s.h
./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_ELF/Release/IMG_corr_5x5_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_ELF/Release/IMG_corr_5x5_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_ELF/Release/IMG_corr_5x5_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_ELF/Release/IMG_corr_5x5_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_ELF/Release/IMG_corr_5x5_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_ELF/Release/IMG_corr_5x5_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_ELF/Release/IMG_corr_5x5_i16s_c16s_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_ELF/Release/IMG_corr_5x5_i16s_c16s_66_LE_ELF.out: ./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_ELF/.project
	-@ echo Importing Project IMG_corr_5x5_i16s_c16s_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_corr_5x5_i16s_c16s_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_5x5_i16s_c16s/c66/IMG_corr_5x5_i16s_c16s_66_LE_ELF"
	-@ echo Building Project IMG_corr_5x5_i16s_c16s_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_corr_5x5_i16s_c16s_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_corr_5x5_i16s_c16s_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_ELF/.settings"

	-@ echo Project IMG_corr_5x5_i16s_c16s_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_corr_5x5_i16s_c16s//c66//IMG_corr_5x5_i16s_c16s_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_corr_gen_i16s_c16s_66_LE_COFF

#############################################################

all: ./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_COFF/Release/IMG_corr_gen_i16s_c16s_66_LE_COFF.out

./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_corr_gen_i16s_c16s_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CORR_GEN_I16S_C16S_66_LE_COFF_SRCIMG_CORR_GEN_I16S_C16S/IMG_corr_gen_i16s_c16s_cn.c -ccs.linkFile EXT_ROOT__IMG_CORR_GEN_I16S_C16S_66_LE_COFF_SRCIMG_CORR_GEN_I16S_C16S/IMG_corr_gen_i16s_c16s_d.c -ccs.linkFile EXT_ROOT__IMG_CORR_GEN_I16S_C16S_66_LE_COFF_SRCIMG_CORR_GEN_I16S_C16S/IMG_corr_gen_i16s_c16s_idat.c -ccs.linkFile EXT_ROOT__IMG_CORR_GEN_I16S_C16S_66_LE_COFF_SRCIMG_CORR_GEN_I16S_C16S/IMG_corr_gen_i16s_c16s_odat.c -ccs.linkFile EXT_ROOT__IMG_CORR_GEN_I16S_C16S_66_LE_COFF/IMG_corr_gen_i16s_c16s.c -ccs.linkFile EXT_ROOT__IMG_CORR_GEN_I16S_C16S_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CORR_GEN_I16S_C16S_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CORR_GEN_I16S_C16S_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CORR_GEN_I16S_C16S_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_CORR_GEN_I16S_C16S_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_gen_i16s_c16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_CORR_GEN_I16S_C16S_66_LE_COFF_SRCIMG_CORR_GEN_I16S_C16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_gen_i16s_c16s" -ccs.definePathVariable EXT_ROOT__IMG_CORR_GEN_I16S_C16S_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CORR_GEN_I16S_C16S_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_corr_gen_i16s_c16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CORR_GEN_I16S_C16S_66_LE_COFF=.././ >> ./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CORR_GEN_I16S_C16S_66_LE_COFF_SRCIMG_CORR_GEN_I16S_C16S=../../ >> ./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CORR_GEN_I16S_C16S_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CORR_GEN_I16S_C16S_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_COFF/Release/IMG_corr_gen_i16s_c16s_66_LE_COFF.out: ./src/IMG_corr_gen_i16s_c16s/IMG_corr_gen_i16s_c16s.h
./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_COFF/Release/IMG_corr_gen_i16s_c16s_66_LE_COFF.out: ./src/IMG_corr_gen_i16s_c16s/IMG_corr_gen_i16s_c16s_cn.c
./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_COFF/Release/IMG_corr_gen_i16s_c16s_66_LE_COFF.out: ./src/IMG_corr_gen_i16s_c16s/IMG_corr_gen_i16s_c16s_cn.h
./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_COFF/Release/IMG_corr_gen_i16s_c16s_66_LE_COFF.out: ./src/IMG_corr_gen_i16s_c16s/IMG_corr_gen_i16s_c16s_d.c
./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_COFF/Release/IMG_corr_gen_i16s_c16s_66_LE_COFF.out: ./src/IMG_corr_gen_i16s_c16s/IMG_corr_gen_i16s_c16s_idat.c
./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_COFF/Release/IMG_corr_gen_i16s_c16s_66_LE_COFF.out: ./src/IMG_corr_gen_i16s_c16s/IMG_corr_gen_i16s_c16s_odat.c
./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_COFF/Release/IMG_corr_gen_i16s_c16s_66_LE_COFF.out: ./src/IMG_corr_gen_i16s_c16s//c66/IMG_corr_gen_i16s_c16s.c
./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_COFF/Release/IMG_corr_gen_i16s_c16s_66_LE_COFF.out: ./src/IMG_corr_gen_i16s_c16s//c66/IMG_corr_gen_i16s_c16s.h
./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_COFF/Release/IMG_corr_gen_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_COFF/Release/IMG_corr_gen_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_COFF/Release/IMG_corr_gen_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_COFF/Release/IMG_corr_gen_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_COFF/Release/IMG_corr_gen_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_COFF/Release/IMG_corr_gen_i16s_c16s_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_COFF/Release/IMG_corr_gen_i16s_c16s_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_COFF/Release/IMG_corr_gen_i16s_c16s_66_LE_COFF.out: ./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_COFF/.project
	-@ echo Importing Project IMG_corr_gen_i16s_c16s_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_corr_gen_i16s_c16s_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_gen_i16s_c16s/c66/IMG_corr_gen_i16s_c16s_66_LE_COFF"
	-@ echo Building Project IMG_corr_gen_i16s_c16s_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_corr_gen_i16s_c16s_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_corr_gen_i16s_c16s_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_COFF/.settings"

	-@ echo Project IMG_corr_gen_i16s_c16s_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_corr_gen_i16s_c16s_66_LE_ELF

#############################################################

all: ./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_ELF/Release/IMG_corr_gen_i16s_c16s_66_LE_ELF.out

./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_corr_gen_i16s_c16s_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CORR_GEN_I16S_C16S_66_LE_ELF_SRCIMG_CORR_GEN_I16S_C16S/IMG_corr_gen_i16s_c16s_cn.c -ccs.linkFile EXT_ROOT__IMG_CORR_GEN_I16S_C16S_66_LE_ELF_SRCIMG_CORR_GEN_I16S_C16S/IMG_corr_gen_i16s_c16s_d.c -ccs.linkFile EXT_ROOT__IMG_CORR_GEN_I16S_C16S_66_LE_ELF_SRCIMG_CORR_GEN_I16S_C16S/IMG_corr_gen_i16s_c16s_idat.c -ccs.linkFile EXT_ROOT__IMG_CORR_GEN_I16S_C16S_66_LE_ELF_SRCIMG_CORR_GEN_I16S_C16S/IMG_corr_gen_i16s_c16s_odat.c -ccs.linkFile EXT_ROOT__IMG_CORR_GEN_I16S_C16S_66_LE_ELF/IMG_corr_gen_i16s_c16s.c -ccs.linkFile EXT_ROOT__IMG_CORR_GEN_I16S_C16S_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CORR_GEN_I16S_C16S_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CORR_GEN_I16S_C16S_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CORR_GEN_I16S_C16S_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_CORR_GEN_I16S_C16S_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_gen_i16s_c16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_CORR_GEN_I16S_C16S_66_LE_ELF_SRCIMG_CORR_GEN_I16S_C16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_gen_i16s_c16s" -ccs.definePathVariable EXT_ROOT__IMG_CORR_GEN_I16S_C16S_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CORR_GEN_I16S_C16S_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_corr_gen_i16s_c16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CORR_GEN_I16S_C16S_66_LE_ELF=.././ >> ./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CORR_GEN_I16S_C16S_66_LE_ELF_SRCIMG_CORR_GEN_I16S_C16S=../../ >> ./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CORR_GEN_I16S_C16S_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CORR_GEN_I16S_C16S_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_ELF/Release/IMG_corr_gen_i16s_c16s_66_LE_ELF.out: ./src/IMG_corr_gen_i16s_c16s/IMG_corr_gen_i16s_c16s.h
./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_ELF/Release/IMG_corr_gen_i16s_c16s_66_LE_ELF.out: ./src/IMG_corr_gen_i16s_c16s/IMG_corr_gen_i16s_c16s_cn.c
./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_ELF/Release/IMG_corr_gen_i16s_c16s_66_LE_ELF.out: ./src/IMG_corr_gen_i16s_c16s/IMG_corr_gen_i16s_c16s_cn.h
./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_ELF/Release/IMG_corr_gen_i16s_c16s_66_LE_ELF.out: ./src/IMG_corr_gen_i16s_c16s/IMG_corr_gen_i16s_c16s_d.c
./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_ELF/Release/IMG_corr_gen_i16s_c16s_66_LE_ELF.out: ./src/IMG_corr_gen_i16s_c16s/IMG_corr_gen_i16s_c16s_idat.c
./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_ELF/Release/IMG_corr_gen_i16s_c16s_66_LE_ELF.out: ./src/IMG_corr_gen_i16s_c16s/IMG_corr_gen_i16s_c16s_odat.c
./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_ELF/Release/IMG_corr_gen_i16s_c16s_66_LE_ELF.out: ./src/IMG_corr_gen_i16s_c16s//c66/IMG_corr_gen_i16s_c16s.c
./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_ELF/Release/IMG_corr_gen_i16s_c16s_66_LE_ELF.out: ./src/IMG_corr_gen_i16s_c16s//c66/IMG_corr_gen_i16s_c16s.h
./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_ELF/Release/IMG_corr_gen_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_ELF/Release/IMG_corr_gen_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_ELF/Release/IMG_corr_gen_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_ELF/Release/IMG_corr_gen_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_ELF/Release/IMG_corr_gen_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_ELF/Release/IMG_corr_gen_i16s_c16s_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_ELF/Release/IMG_corr_gen_i16s_c16s_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_ELF/Release/IMG_corr_gen_i16s_c16s_66_LE_ELF.out: ./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_ELF/.project
	-@ echo Importing Project IMG_corr_gen_i16s_c16s_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_corr_gen_i16s_c16s_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_gen_i16s_c16s/c66/IMG_corr_gen_i16s_c16s_66_LE_ELF"
	-@ echo Building Project IMG_corr_gen_i16s_c16s_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_corr_gen_i16s_c16s_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_corr_gen_i16s_c16s_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_ELF/.settings"

	-@ echo Project IMG_corr_gen_i16s_c16s_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_corr_gen_i16s_c16s//c66//IMG_corr_gen_i16s_c16s_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_corr_gen_iq_66_LE_COFF

#############################################################

all: ./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_COFF/Release/IMG_corr_gen_iq_66_LE_COFF.out

./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_corr_gen_iq_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CORR_GEN_IQ_66_LE_COFF_SRCIMG_CORR_GEN_IQ/IMG_corr_gen_iq_cn.c -ccs.linkFile EXT_ROOT__IMG_CORR_GEN_IQ_66_LE_COFF_SRCIMG_CORR_GEN_IQ/IMG_corr_gen_iq_d.c -ccs.linkFile EXT_ROOT__IMG_CORR_GEN_IQ_66_LE_COFF_SRCIMG_CORR_GEN_IQ/IMG_corr_gen_iq_idat.c -ccs.linkFile EXT_ROOT__IMG_CORR_GEN_IQ_66_LE_COFF_SRCIMG_CORR_GEN_IQ/IMG_corr_gen_iq_odat.c -ccs.linkFile EXT_ROOT__IMG_CORR_GEN_IQ_66_LE_COFF/IMG_corr_gen_iq.c -ccs.linkFile EXT_ROOT__IMG_CORR_GEN_IQ_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CORR_GEN_IQ_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CORR_GEN_IQ_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CORR_GEN_IQ_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_CORR_GEN_IQ_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_gen_iq/c66" -ccs.definePathVariable EXT_ROOT__IMG_CORR_GEN_IQ_66_LE_COFF_SRCIMG_CORR_GEN_IQ "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_gen_iq" -ccs.definePathVariable EXT_ROOT__IMG_CORR_GEN_IQ_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CORR_GEN_IQ_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_corr_gen_iq.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CORR_GEN_IQ_66_LE_COFF=.././ >> ./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CORR_GEN_IQ_66_LE_COFF_SRCIMG_CORR_GEN_IQ=../../ >> ./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CORR_GEN_IQ_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_CORR_GEN_IQ_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_COFF/Release/IMG_corr_gen_iq_66_LE_COFF.out: ./src/IMG_corr_gen_iq/IMG_corr_gen_iq.h
./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_COFF/Release/IMG_corr_gen_iq_66_LE_COFF.out: ./src/IMG_corr_gen_iq/IMG_corr_gen_iq_cn.c
./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_COFF/Release/IMG_corr_gen_iq_66_LE_COFF.out: ./src/IMG_corr_gen_iq/IMG_corr_gen_iq_cn.h
./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_COFF/Release/IMG_corr_gen_iq_66_LE_COFF.out: ./src/IMG_corr_gen_iq/IMG_corr_gen_iq_d.c
./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_COFF/Release/IMG_corr_gen_iq_66_LE_COFF.out: ./src/IMG_corr_gen_iq/IMG_corr_gen_iq_idat.c
./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_COFF/Release/IMG_corr_gen_iq_66_LE_COFF.out: ./src/IMG_corr_gen_iq/IMG_corr_gen_iq_odat.c
./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_COFF/Release/IMG_corr_gen_iq_66_LE_COFF.out: ./src/IMG_corr_gen_iq//c66/IMG_corr_gen_iq.c
./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_COFF/Release/IMG_corr_gen_iq_66_LE_COFF.out: ./src/IMG_corr_gen_iq//c66/IMG_corr_gen_iq.h
./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_COFF/Release/IMG_corr_gen_iq_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_COFF/Release/IMG_corr_gen_iq_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_COFF/Release/IMG_corr_gen_iq_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_COFF/Release/IMG_corr_gen_iq_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_COFF/Release/IMG_corr_gen_iq_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_COFF/Release/IMG_corr_gen_iq_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_COFF/Release/IMG_corr_gen_iq_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_COFF/Release/IMG_corr_gen_iq_66_LE_COFF.out: ./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_COFF/.project
	-@ echo Importing Project IMG_corr_gen_iq_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_corr_gen_iq_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_gen_iq/c66/IMG_corr_gen_iq_66_LE_COFF"
	-@ echo Building Project IMG_corr_gen_iq_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_corr_gen_iq_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_corr_gen_iq_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_COFF/.settings"

	-@ echo Project IMG_corr_gen_iq_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_corr_gen_iq_66_LE_ELF

#############################################################

all: ./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_ELF/Release/IMG_corr_gen_iq_66_LE_ELF.out

./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_corr_gen_iq_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_CORR_GEN_IQ_66_LE_ELF_SRCIMG_CORR_GEN_IQ/IMG_corr_gen_iq_cn.c -ccs.linkFile EXT_ROOT__IMG_CORR_GEN_IQ_66_LE_ELF_SRCIMG_CORR_GEN_IQ/IMG_corr_gen_iq_d.c -ccs.linkFile EXT_ROOT__IMG_CORR_GEN_IQ_66_LE_ELF_SRCIMG_CORR_GEN_IQ/IMG_corr_gen_iq_idat.c -ccs.linkFile EXT_ROOT__IMG_CORR_GEN_IQ_66_LE_ELF_SRCIMG_CORR_GEN_IQ/IMG_corr_gen_iq_odat.c -ccs.linkFile EXT_ROOT__IMG_CORR_GEN_IQ_66_LE_ELF/IMG_corr_gen_iq.c -ccs.linkFile EXT_ROOT__IMG_CORR_GEN_IQ_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_CORR_GEN_IQ_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_CORR_GEN_IQ_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_CORR_GEN_IQ_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_CORR_GEN_IQ_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_gen_iq/c66" -ccs.definePathVariable EXT_ROOT__IMG_CORR_GEN_IQ_66_LE_ELF_SRCIMG_CORR_GEN_IQ "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_gen_iq" -ccs.definePathVariable EXT_ROOT__IMG_CORR_GEN_IQ_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_CORR_GEN_IQ_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_corr_gen_iq.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_CORR_GEN_IQ_66_LE_ELF=.././ >> ./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CORR_GEN_IQ_66_LE_ELF_SRCIMG_CORR_GEN_IQ=../../ >> ./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CORR_GEN_IQ_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_CORR_GEN_IQ_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_ELF/Release/IMG_corr_gen_iq_66_LE_ELF.out: ./src/IMG_corr_gen_iq/IMG_corr_gen_iq.h
./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_ELF/Release/IMG_corr_gen_iq_66_LE_ELF.out: ./src/IMG_corr_gen_iq/IMG_corr_gen_iq_cn.c
./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_ELF/Release/IMG_corr_gen_iq_66_LE_ELF.out: ./src/IMG_corr_gen_iq/IMG_corr_gen_iq_cn.h
./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_ELF/Release/IMG_corr_gen_iq_66_LE_ELF.out: ./src/IMG_corr_gen_iq/IMG_corr_gen_iq_d.c
./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_ELF/Release/IMG_corr_gen_iq_66_LE_ELF.out: ./src/IMG_corr_gen_iq/IMG_corr_gen_iq_idat.c
./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_ELF/Release/IMG_corr_gen_iq_66_LE_ELF.out: ./src/IMG_corr_gen_iq/IMG_corr_gen_iq_odat.c
./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_ELF/Release/IMG_corr_gen_iq_66_LE_ELF.out: ./src/IMG_corr_gen_iq//c66/IMG_corr_gen_iq.c
./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_ELF/Release/IMG_corr_gen_iq_66_LE_ELF.out: ./src/IMG_corr_gen_iq//c66/IMG_corr_gen_iq.h
./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_ELF/Release/IMG_corr_gen_iq_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_ELF/Release/IMG_corr_gen_iq_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_ELF/Release/IMG_corr_gen_iq_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_ELF/Release/IMG_corr_gen_iq_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_ELF/Release/IMG_corr_gen_iq_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_ELF/Release/IMG_corr_gen_iq_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_ELF/Release/IMG_corr_gen_iq_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_ELF/Release/IMG_corr_gen_iq_66_LE_ELF.out: ./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_ELF/.project
	-@ echo Importing Project IMG_corr_gen_iq_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_corr_gen_iq_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_corr_gen_iq/c66/IMG_corr_gen_iq_66_LE_ELF"
	-@ echo Building Project IMG_corr_gen_iq_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_corr_gen_iq_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_corr_gen_iq_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_ELF/.settings"

	-@ echo Project IMG_corr_gen_iq_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_corr_gen_iq//c66//IMG_corr_gen_iq_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_dilate_bin_66_LE_COFF

#############################################################

all: ./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_COFF/Release/IMG_dilate_bin_66_LE_COFF.out

./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_dilate_bin_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_DILATE_BIN_66_LE_COFF_SRCIMG_DILATE_BIN/IMG_dilate_bin_cn.c -ccs.linkFile EXT_ROOT__IMG_DILATE_BIN_66_LE_COFF_SRCIMG_DILATE_BIN/IMG_dilate_bin_d.c -ccs.linkFile EXT_ROOT__IMG_DILATE_BIN_66_LE_COFF_SRCIMG_DILATE_BIN/IMG_dilate_bin_idat.c -ccs.linkFile EXT_ROOT__IMG_DILATE_BIN_66_LE_COFF_SRCIMG_DILATE_BIN/IMG_dilate_bin_odat.c -ccs.linkFile EXT_ROOT__IMG_DILATE_BIN_66_LE_COFF/IMG_dilate_bin.c -ccs.linkFile EXT_ROOT__IMG_DILATE_BIN_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_DILATE_BIN_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_DILATE_BIN_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_DILATE_BIN_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_DILATE_BIN_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_dilate_bin/c66" -ccs.definePathVariable EXT_ROOT__IMG_DILATE_BIN_66_LE_COFF_SRCIMG_DILATE_BIN "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_dilate_bin" -ccs.definePathVariable EXT_ROOT__IMG_DILATE_BIN_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_DILATE_BIN_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_dilate_bin.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_DILATE_BIN_66_LE_COFF=.././ >> ./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_DILATE_BIN_66_LE_COFF_SRCIMG_DILATE_BIN=../../ >> ./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_DILATE_BIN_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_DILATE_BIN_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_COFF/Release/IMG_dilate_bin_66_LE_COFF.out: ./src/IMG_dilate_bin/IMG_dilate_bin.h
./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_COFF/Release/IMG_dilate_bin_66_LE_COFF.out: ./src/IMG_dilate_bin/IMG_dilate_bin_cn.c
./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_COFF/Release/IMG_dilate_bin_66_LE_COFF.out: ./src/IMG_dilate_bin/IMG_dilate_bin_cn.h
./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_COFF/Release/IMG_dilate_bin_66_LE_COFF.out: ./src/IMG_dilate_bin/IMG_dilate_bin_d.c
./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_COFF/Release/IMG_dilate_bin_66_LE_COFF.out: ./src/IMG_dilate_bin/IMG_dilate_bin_idat.c
./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_COFF/Release/IMG_dilate_bin_66_LE_COFF.out: ./src/IMG_dilate_bin/IMG_dilate_bin_odat.c
./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_COFF/Release/IMG_dilate_bin_66_LE_COFF.out: ./src/IMG_dilate_bin//c66/IMG_dilate_bin.c
./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_COFF/Release/IMG_dilate_bin_66_LE_COFF.out: ./src/IMG_dilate_bin//c66/IMG_dilate_bin.h
./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_COFF/Release/IMG_dilate_bin_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_COFF/Release/IMG_dilate_bin_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_COFF/Release/IMG_dilate_bin_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_COFF/Release/IMG_dilate_bin_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_COFF/Release/IMG_dilate_bin_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_COFF/Release/IMG_dilate_bin_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_COFF/Release/IMG_dilate_bin_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_COFF/Release/IMG_dilate_bin_66_LE_COFF.out: ./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_COFF/.project
	-@ echo Importing Project IMG_dilate_bin_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_dilate_bin_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_dilate_bin/c66/IMG_dilate_bin_66_LE_COFF"
	-@ echo Building Project IMG_dilate_bin_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_dilate_bin_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_dilate_bin_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_COFF/.settings"

	-@ echo Project IMG_dilate_bin_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_dilate_bin_66_LE_ELF

#############################################################

all: ./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_ELF/Release/IMG_dilate_bin_66_LE_ELF.out

./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_dilate_bin_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_DILATE_BIN_66_LE_ELF_SRCIMG_DILATE_BIN/IMG_dilate_bin_cn.c -ccs.linkFile EXT_ROOT__IMG_DILATE_BIN_66_LE_ELF_SRCIMG_DILATE_BIN/IMG_dilate_bin_d.c -ccs.linkFile EXT_ROOT__IMG_DILATE_BIN_66_LE_ELF_SRCIMG_DILATE_BIN/IMG_dilate_bin_idat.c -ccs.linkFile EXT_ROOT__IMG_DILATE_BIN_66_LE_ELF_SRCIMG_DILATE_BIN/IMG_dilate_bin_odat.c -ccs.linkFile EXT_ROOT__IMG_DILATE_BIN_66_LE_ELF/IMG_dilate_bin.c -ccs.linkFile EXT_ROOT__IMG_DILATE_BIN_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_DILATE_BIN_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_DILATE_BIN_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_DILATE_BIN_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_DILATE_BIN_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_dilate_bin/c66" -ccs.definePathVariable EXT_ROOT__IMG_DILATE_BIN_66_LE_ELF_SRCIMG_DILATE_BIN "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_dilate_bin" -ccs.definePathVariable EXT_ROOT__IMG_DILATE_BIN_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_DILATE_BIN_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_dilate_bin.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_DILATE_BIN_66_LE_ELF=.././ >> ./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_DILATE_BIN_66_LE_ELF_SRCIMG_DILATE_BIN=../../ >> ./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_DILATE_BIN_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_DILATE_BIN_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_ELF/Release/IMG_dilate_bin_66_LE_ELF.out: ./src/IMG_dilate_bin/IMG_dilate_bin.h
./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_ELF/Release/IMG_dilate_bin_66_LE_ELF.out: ./src/IMG_dilate_bin/IMG_dilate_bin_cn.c
./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_ELF/Release/IMG_dilate_bin_66_LE_ELF.out: ./src/IMG_dilate_bin/IMG_dilate_bin_cn.h
./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_ELF/Release/IMG_dilate_bin_66_LE_ELF.out: ./src/IMG_dilate_bin/IMG_dilate_bin_d.c
./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_ELF/Release/IMG_dilate_bin_66_LE_ELF.out: ./src/IMG_dilate_bin/IMG_dilate_bin_idat.c
./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_ELF/Release/IMG_dilate_bin_66_LE_ELF.out: ./src/IMG_dilate_bin/IMG_dilate_bin_odat.c
./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_ELF/Release/IMG_dilate_bin_66_LE_ELF.out: ./src/IMG_dilate_bin//c66/IMG_dilate_bin.c
./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_ELF/Release/IMG_dilate_bin_66_LE_ELF.out: ./src/IMG_dilate_bin//c66/IMG_dilate_bin.h
./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_ELF/Release/IMG_dilate_bin_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_ELF/Release/IMG_dilate_bin_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_ELF/Release/IMG_dilate_bin_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_ELF/Release/IMG_dilate_bin_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_ELF/Release/IMG_dilate_bin_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_ELF/Release/IMG_dilate_bin_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_ELF/Release/IMG_dilate_bin_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_ELF/Release/IMG_dilate_bin_66_LE_ELF.out: ./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_ELF/.project
	-@ echo Importing Project IMG_dilate_bin_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_dilate_bin_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_dilate_bin/c66/IMG_dilate_bin_66_LE_ELF"
	-@ echo Building Project IMG_dilate_bin_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_dilate_bin_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_dilate_bin_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_ELF/.settings"

	-@ echo Project IMG_dilate_bin_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_dilate_bin//c66//IMG_dilate_bin_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_erode_bin_66_LE_COFF

#############################################################

all: ./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_COFF/Release/IMG_erode_bin_66_LE_COFF.out

./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_erode_bin_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_ERODE_BIN_66_LE_COFF_SRCIMG_ERODE_BIN/IMG_erode_bin_cn.c -ccs.linkFile EXT_ROOT__IMG_ERODE_BIN_66_LE_COFF_SRCIMG_ERODE_BIN/IMG_erode_bin_d.c -ccs.linkFile EXT_ROOT__IMG_ERODE_BIN_66_LE_COFF_SRCIMG_ERODE_BIN/IMG_erode_bin_idat.c -ccs.linkFile EXT_ROOT__IMG_ERODE_BIN_66_LE_COFF_SRCIMG_ERODE_BIN/IMG_erode_bin_odat.c -ccs.linkFile EXT_ROOT__IMG_ERODE_BIN_66_LE_COFF/IMG_erode_bin.c -ccs.linkFile EXT_ROOT__IMG_ERODE_BIN_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_ERODE_BIN_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_ERODE_BIN_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_ERODE_BIN_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_ERODE_BIN_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_erode_bin/c66" -ccs.definePathVariable EXT_ROOT__IMG_ERODE_BIN_66_LE_COFF_SRCIMG_ERODE_BIN "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_erode_bin" -ccs.definePathVariable EXT_ROOT__IMG_ERODE_BIN_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_ERODE_BIN_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_erode_bin.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_ERODE_BIN_66_LE_COFF=.././ >> ./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_ERODE_BIN_66_LE_COFF_SRCIMG_ERODE_BIN=../../ >> ./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_ERODE_BIN_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_ERODE_BIN_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_COFF/Release/IMG_erode_bin_66_LE_COFF.out: ./src/IMG_erode_bin/IMG_erode_bin.h
./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_COFF/Release/IMG_erode_bin_66_LE_COFF.out: ./src/IMG_erode_bin/IMG_erode_bin_cn.c
./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_COFF/Release/IMG_erode_bin_66_LE_COFF.out: ./src/IMG_erode_bin/IMG_erode_bin_cn.h
./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_COFF/Release/IMG_erode_bin_66_LE_COFF.out: ./src/IMG_erode_bin/IMG_erode_bin_d.c
./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_COFF/Release/IMG_erode_bin_66_LE_COFF.out: ./src/IMG_erode_bin/IMG_erode_bin_idat.c
./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_COFF/Release/IMG_erode_bin_66_LE_COFF.out: ./src/IMG_erode_bin/IMG_erode_bin_odat.c
./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_COFF/Release/IMG_erode_bin_66_LE_COFF.out: ./src/IMG_erode_bin//c66/IMG_erode_bin.c
./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_COFF/Release/IMG_erode_bin_66_LE_COFF.out: ./src/IMG_erode_bin//c66/IMG_erode_bin.h
./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_COFF/Release/IMG_erode_bin_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_COFF/Release/IMG_erode_bin_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_COFF/Release/IMG_erode_bin_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_COFF/Release/IMG_erode_bin_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_COFF/Release/IMG_erode_bin_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_COFF/Release/IMG_erode_bin_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_COFF/Release/IMG_erode_bin_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_COFF/Release/IMG_erode_bin_66_LE_COFF.out: ./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_COFF/.project
	-@ echo Importing Project IMG_erode_bin_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_erode_bin_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_erode_bin/c66/IMG_erode_bin_66_LE_COFF"
	-@ echo Building Project IMG_erode_bin_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_erode_bin_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_erode_bin_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_COFF/.settings"

	-@ echo Project IMG_erode_bin_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_erode_bin_66_LE_ELF

#############################################################

all: ./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_ELF/Release/IMG_erode_bin_66_LE_ELF.out

./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_erode_bin_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_ERODE_BIN_66_LE_ELF_SRCIMG_ERODE_BIN/IMG_erode_bin_cn.c -ccs.linkFile EXT_ROOT__IMG_ERODE_BIN_66_LE_ELF_SRCIMG_ERODE_BIN/IMG_erode_bin_d.c -ccs.linkFile EXT_ROOT__IMG_ERODE_BIN_66_LE_ELF_SRCIMG_ERODE_BIN/IMG_erode_bin_idat.c -ccs.linkFile EXT_ROOT__IMG_ERODE_BIN_66_LE_ELF_SRCIMG_ERODE_BIN/IMG_erode_bin_odat.c -ccs.linkFile EXT_ROOT__IMG_ERODE_BIN_66_LE_ELF/IMG_erode_bin.c -ccs.linkFile EXT_ROOT__IMG_ERODE_BIN_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_ERODE_BIN_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_ERODE_BIN_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_ERODE_BIN_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_ERODE_BIN_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_erode_bin/c66" -ccs.definePathVariable EXT_ROOT__IMG_ERODE_BIN_66_LE_ELF_SRCIMG_ERODE_BIN "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_erode_bin" -ccs.definePathVariable EXT_ROOT__IMG_ERODE_BIN_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_ERODE_BIN_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_erode_bin.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_ERODE_BIN_66_LE_ELF=.././ >> ./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_ERODE_BIN_66_LE_ELF_SRCIMG_ERODE_BIN=../../ >> ./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_ERODE_BIN_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_ERODE_BIN_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_ELF/Release/IMG_erode_bin_66_LE_ELF.out: ./src/IMG_erode_bin/IMG_erode_bin.h
./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_ELF/Release/IMG_erode_bin_66_LE_ELF.out: ./src/IMG_erode_bin/IMG_erode_bin_cn.c
./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_ELF/Release/IMG_erode_bin_66_LE_ELF.out: ./src/IMG_erode_bin/IMG_erode_bin_cn.h
./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_ELF/Release/IMG_erode_bin_66_LE_ELF.out: ./src/IMG_erode_bin/IMG_erode_bin_d.c
./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_ELF/Release/IMG_erode_bin_66_LE_ELF.out: ./src/IMG_erode_bin/IMG_erode_bin_idat.c
./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_ELF/Release/IMG_erode_bin_66_LE_ELF.out: ./src/IMG_erode_bin/IMG_erode_bin_odat.c
./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_ELF/Release/IMG_erode_bin_66_LE_ELF.out: ./src/IMG_erode_bin//c66/IMG_erode_bin.c
./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_ELF/Release/IMG_erode_bin_66_LE_ELF.out: ./src/IMG_erode_bin//c66/IMG_erode_bin.h
./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_ELF/Release/IMG_erode_bin_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_ELF/Release/IMG_erode_bin_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_ELF/Release/IMG_erode_bin_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_ELF/Release/IMG_erode_bin_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_ELF/Release/IMG_erode_bin_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_ELF/Release/IMG_erode_bin_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_ELF/Release/IMG_erode_bin_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_ELF/Release/IMG_erode_bin_66_LE_ELF.out: ./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_ELF/.project
	-@ echo Importing Project IMG_erode_bin_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_erode_bin_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_erode_bin/c66/IMG_erode_bin_66_LE_ELF"
	-@ echo Building Project IMG_erode_bin_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_erode_bin_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_erode_bin_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_ELF/.settings"

	-@ echo Project IMG_erode_bin_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_erode_bin//c66//IMG_erode_bin_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_errdif_bin_16_66_LE_COFF

#############################################################

all: ./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_COFF/Release/IMG_errdif_bin_16_66_LE_COFF.out

./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_errdif_bin_16_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_ERRDIF_BIN_16_66_LE_COFF_SRCIMG_ERRDIF_BIN_16/IMG_errdif_bin_16_cn.c -ccs.linkFile EXT_ROOT__IMG_ERRDIF_BIN_16_66_LE_COFF_SRCIMG_ERRDIF_BIN_16/IMG_errdif_bin_16_d.c -ccs.linkFile EXT_ROOT__IMG_ERRDIF_BIN_16_66_LE_COFF/IMG_errdif_bin_16.sa -ccs.linkFile EXT_ROOT__IMG_ERRDIF_BIN_16_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_ERRDIF_BIN_16_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_ERRDIF_BIN_16_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_ERRDIF_BIN_16_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_ERRDIF_BIN_16_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_errdif_bin_16/c66" -ccs.definePathVariable EXT_ROOT__IMG_ERRDIF_BIN_16_66_LE_COFF_SRCIMG_ERRDIF_BIN_16 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_errdif_bin_16" -ccs.definePathVariable EXT_ROOT__IMG_ERRDIF_BIN_16_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_ERRDIF_BIN_16_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_errdif_bin_16.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_ERRDIF_BIN_16_66_LE_COFF=.././ >> ./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_ERRDIF_BIN_16_66_LE_COFF_SRCIMG_ERRDIF_BIN_16=../../ >> ./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_ERRDIF_BIN_16_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_ERRDIF_BIN_16_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_COFF/Release/IMG_errdif_bin_16_66_LE_COFF.out: ./src/IMG_errdif_bin_16/IMG_errdif_bin_16.h
./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_COFF/Release/IMG_errdif_bin_16_66_LE_COFF.out: ./src/IMG_errdif_bin_16/IMG_errdif_bin_16_cn.c
./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_COFF/Release/IMG_errdif_bin_16_66_LE_COFF.out: ./src/IMG_errdif_bin_16/IMG_errdif_bin_16_cn.h
./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_COFF/Release/IMG_errdif_bin_16_66_LE_COFF.out: ./src/IMG_errdif_bin_16/IMG_errdif_bin_16_d.c
./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_COFF/Release/IMG_errdif_bin_16_66_LE_COFF.out: ./src/IMG_errdif_bin_16//c66/IMG_errdif_bin_16.h
./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_COFF/Release/IMG_errdif_bin_16_66_LE_COFF.out: ./src/IMG_errdif_bin_16//c66/IMG_errdif_bin_16.sa
./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_COFF/Release/IMG_errdif_bin_16_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_COFF/Release/IMG_errdif_bin_16_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_COFF/Release/IMG_errdif_bin_16_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_COFF/Release/IMG_errdif_bin_16_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_COFF/Release/IMG_errdif_bin_16_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_COFF/Release/IMG_errdif_bin_16_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_COFF/Release/IMG_errdif_bin_16_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_COFF/Release/IMG_errdif_bin_16_66_LE_COFF.out: ./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_COFF/.project
	-@ echo Importing Project IMG_errdif_bin_16_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_errdif_bin_16_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_errdif_bin_16/c66/IMG_errdif_bin_16_66_LE_COFF"
	-@ echo Building Project IMG_errdif_bin_16_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_errdif_bin_16_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_errdif_bin_16_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_COFF/.settings"

	-@ echo Project IMG_errdif_bin_16_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_errdif_bin_16_66_LE_ELF

#############################################################

all: ./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_ELF/Release/IMG_errdif_bin_16_66_LE_ELF.out

./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_errdif_bin_16_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_ERRDIF_BIN_16_66_LE_ELF_SRCIMG_ERRDIF_BIN_16/IMG_errdif_bin_16_cn.c -ccs.linkFile EXT_ROOT__IMG_ERRDIF_BIN_16_66_LE_ELF_SRCIMG_ERRDIF_BIN_16/IMG_errdif_bin_16_d.c -ccs.linkFile EXT_ROOT__IMG_ERRDIF_BIN_16_66_LE_ELF/IMG_errdif_bin_16.sa -ccs.linkFile EXT_ROOT__IMG_ERRDIF_BIN_16_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_ERRDIF_BIN_16_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_ERRDIF_BIN_16_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_ERRDIF_BIN_16_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_ERRDIF_BIN_16_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_errdif_bin_16/c66" -ccs.definePathVariable EXT_ROOT__IMG_ERRDIF_BIN_16_66_LE_ELF_SRCIMG_ERRDIF_BIN_16 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_errdif_bin_16" -ccs.definePathVariable EXT_ROOT__IMG_ERRDIF_BIN_16_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_ERRDIF_BIN_16_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_errdif_bin_16.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_ERRDIF_BIN_16_66_LE_ELF=.././ >> ./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_ERRDIF_BIN_16_66_LE_ELF_SRCIMG_ERRDIF_BIN_16=../../ >> ./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_ERRDIF_BIN_16_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_ERRDIF_BIN_16_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_ELF/Release/IMG_errdif_bin_16_66_LE_ELF.out: ./src/IMG_errdif_bin_16/IMG_errdif_bin_16.h
./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_ELF/Release/IMG_errdif_bin_16_66_LE_ELF.out: ./src/IMG_errdif_bin_16/IMG_errdif_bin_16_cn.c
./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_ELF/Release/IMG_errdif_bin_16_66_LE_ELF.out: ./src/IMG_errdif_bin_16/IMG_errdif_bin_16_cn.h
./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_ELF/Release/IMG_errdif_bin_16_66_LE_ELF.out: ./src/IMG_errdif_bin_16/IMG_errdif_bin_16_d.c
./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_ELF/Release/IMG_errdif_bin_16_66_LE_ELF.out: ./src/IMG_errdif_bin_16//c66/IMG_errdif_bin_16.h
./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_ELF/Release/IMG_errdif_bin_16_66_LE_ELF.out: ./src/IMG_errdif_bin_16//c66/IMG_errdif_bin_16.sa
./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_ELF/Release/IMG_errdif_bin_16_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_ELF/Release/IMG_errdif_bin_16_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_ELF/Release/IMG_errdif_bin_16_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_ELF/Release/IMG_errdif_bin_16_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_ELF/Release/IMG_errdif_bin_16_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_ELF/Release/IMG_errdif_bin_16_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_ELF/Release/IMG_errdif_bin_16_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_ELF/Release/IMG_errdif_bin_16_66_LE_ELF.out: ./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_ELF/.project
	-@ echo Importing Project IMG_errdif_bin_16_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_errdif_bin_16_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_errdif_bin_16/c66/IMG_errdif_bin_16_66_LE_ELF"
	-@ echo Building Project IMG_errdif_bin_16_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_errdif_bin_16_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_errdif_bin_16_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_ELF/.settings"

	-@ echo Project IMG_errdif_bin_16_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_errdif_bin_16//c66//IMG_errdif_bin_16_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_errdif_bin_8_66_LE_COFF

#############################################################

all: ./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_COFF/Release/IMG_errdif_bin_8_66_LE_COFF.out

./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_errdif_bin_8_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_ERRDIF_BIN_8_66_LE_COFF_SRCIMG_ERRDIF_BIN_8/IMG_errdif_bin_8_cn.c -ccs.linkFile EXT_ROOT__IMG_ERRDIF_BIN_8_66_LE_COFF_SRCIMG_ERRDIF_BIN_8/IMG_errdif_bin_8_d.c -ccs.linkFile EXT_ROOT__IMG_ERRDIF_BIN_8_66_LE_COFF/IMG_errdif_bin_8.c -ccs.linkFile EXT_ROOT__IMG_ERRDIF_BIN_8_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_ERRDIF_BIN_8_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_ERRDIF_BIN_8_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_ERRDIF_BIN_8_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_ERRDIF_BIN_8_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_errdif_bin_8/c66" -ccs.definePathVariable EXT_ROOT__IMG_ERRDIF_BIN_8_66_LE_COFF_SRCIMG_ERRDIF_BIN_8 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_errdif_bin_8" -ccs.definePathVariable EXT_ROOT__IMG_ERRDIF_BIN_8_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_ERRDIF_BIN_8_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_errdif_bin_8.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_ERRDIF_BIN_8_66_LE_COFF=.././ >> ./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_ERRDIF_BIN_8_66_LE_COFF_SRCIMG_ERRDIF_BIN_8=../../ >> ./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_ERRDIF_BIN_8_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_ERRDIF_BIN_8_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_COFF/Release/IMG_errdif_bin_8_66_LE_COFF.out: ./src/IMG_errdif_bin_8/IMG_errdif_bin_8.h
./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_COFF/Release/IMG_errdif_bin_8_66_LE_COFF.out: ./src/IMG_errdif_bin_8/IMG_errdif_bin_8_cn.c
./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_COFF/Release/IMG_errdif_bin_8_66_LE_COFF.out: ./src/IMG_errdif_bin_8/IMG_errdif_bin_8_cn.h
./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_COFF/Release/IMG_errdif_bin_8_66_LE_COFF.out: ./src/IMG_errdif_bin_8/IMG_errdif_bin_8_d.c
./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_COFF/Release/IMG_errdif_bin_8_66_LE_COFF.out: ./src/IMG_errdif_bin_8//c66/IMG_errdif_bin_8.c
./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_COFF/Release/IMG_errdif_bin_8_66_LE_COFF.out: ./src/IMG_errdif_bin_8//c66/IMG_errdif_bin_8.h
./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_COFF/Release/IMG_errdif_bin_8_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_COFF/Release/IMG_errdif_bin_8_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_COFF/Release/IMG_errdif_bin_8_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_COFF/Release/IMG_errdif_bin_8_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_COFF/Release/IMG_errdif_bin_8_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_COFF/Release/IMG_errdif_bin_8_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_COFF/Release/IMG_errdif_bin_8_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_COFF/Release/IMG_errdif_bin_8_66_LE_COFF.out: ./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_COFF/.project
	-@ echo Importing Project IMG_errdif_bin_8_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_errdif_bin_8_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_errdif_bin_8/c66/IMG_errdif_bin_8_66_LE_COFF"
	-@ echo Building Project IMG_errdif_bin_8_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_errdif_bin_8_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_errdif_bin_8_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_COFF/.settings"

	-@ echo Project IMG_errdif_bin_8_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_errdif_bin_8_66_LE_ELF

#############################################################

all: ./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_ELF/Release/IMG_errdif_bin_8_66_LE_ELF.out

./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_errdif_bin_8_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_ERRDIF_BIN_8_66_LE_ELF_SRCIMG_ERRDIF_BIN_8/IMG_errdif_bin_8_cn.c -ccs.linkFile EXT_ROOT__IMG_ERRDIF_BIN_8_66_LE_ELF_SRCIMG_ERRDIF_BIN_8/IMG_errdif_bin_8_d.c -ccs.linkFile EXT_ROOT__IMG_ERRDIF_BIN_8_66_LE_ELF/IMG_errdif_bin_8.c -ccs.linkFile EXT_ROOT__IMG_ERRDIF_BIN_8_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_ERRDIF_BIN_8_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_ERRDIF_BIN_8_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_ERRDIF_BIN_8_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_ERRDIF_BIN_8_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_errdif_bin_8/c66" -ccs.definePathVariable EXT_ROOT__IMG_ERRDIF_BIN_8_66_LE_ELF_SRCIMG_ERRDIF_BIN_8 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_errdif_bin_8" -ccs.definePathVariable EXT_ROOT__IMG_ERRDIF_BIN_8_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_ERRDIF_BIN_8_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_errdif_bin_8.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_ERRDIF_BIN_8_66_LE_ELF=.././ >> ./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_ERRDIF_BIN_8_66_LE_ELF_SRCIMG_ERRDIF_BIN_8=../../ >> ./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_ERRDIF_BIN_8_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_ERRDIF_BIN_8_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_ELF/Release/IMG_errdif_bin_8_66_LE_ELF.out: ./src/IMG_errdif_bin_8/IMG_errdif_bin_8.h
./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_ELF/Release/IMG_errdif_bin_8_66_LE_ELF.out: ./src/IMG_errdif_bin_8/IMG_errdif_bin_8_cn.c
./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_ELF/Release/IMG_errdif_bin_8_66_LE_ELF.out: ./src/IMG_errdif_bin_8/IMG_errdif_bin_8_cn.h
./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_ELF/Release/IMG_errdif_bin_8_66_LE_ELF.out: ./src/IMG_errdif_bin_8/IMG_errdif_bin_8_d.c
./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_ELF/Release/IMG_errdif_bin_8_66_LE_ELF.out: ./src/IMG_errdif_bin_8//c66/IMG_errdif_bin_8.c
./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_ELF/Release/IMG_errdif_bin_8_66_LE_ELF.out: ./src/IMG_errdif_bin_8//c66/IMG_errdif_bin_8.h
./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_ELF/Release/IMG_errdif_bin_8_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_ELF/Release/IMG_errdif_bin_8_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_ELF/Release/IMG_errdif_bin_8_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_ELF/Release/IMG_errdif_bin_8_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_ELF/Release/IMG_errdif_bin_8_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_ELF/Release/IMG_errdif_bin_8_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_ELF/Release/IMG_errdif_bin_8_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_ELF/Release/IMG_errdif_bin_8_66_LE_ELF.out: ./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_ELF/.project
	-@ echo Importing Project IMG_errdif_bin_8_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_errdif_bin_8_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_errdif_bin_8/c66/IMG_errdif_bin_8_66_LE_ELF"
	-@ echo Building Project IMG_errdif_bin_8_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_errdif_bin_8_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_errdif_bin_8_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_ELF/.settings"

	-@ echo Project IMG_errdif_bin_8_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_errdif_bin_8//c66//IMG_errdif_bin_8_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_fdct_8x8_66_LE_COFF

#############################################################

all: ./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_COFF/Release/IMG_fdct_8x8_66_LE_COFF.out

./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_fdct_8x8_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_FDCT_8X8_66_LE_COFF_SRCIMG_FDCT_8X8/IMG_fdct_8x8_cn.c -ccs.linkFile EXT_ROOT__IMG_FDCT_8X8_66_LE_COFF_SRCIMG_FDCT_8X8/IMG_fdct_8x8_d.c -ccs.linkFile EXT_ROOT__IMG_FDCT_8X8_66_LE_COFF_SRCIMG_FDCT_8X8/IMG_fdct_8x8_idat.c -ccs.linkFile EXT_ROOT__IMG_FDCT_8X8_66_LE_COFF_SRCIMG_FDCT_8X8/IMG_fdct_8x8_odat.c -ccs.linkFile EXT_ROOT__IMG_FDCT_8X8_66_LE_COFF/IMG_fdct_8x8.s -ccs.linkFile EXT_ROOT__IMG_FDCT_8X8_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_FDCT_8X8_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_FDCT_8X8_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_FDCT_8X8_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_FDCT_8X8_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_fdct_8x8/c66" -ccs.definePathVariable EXT_ROOT__IMG_FDCT_8X8_66_LE_COFF_SRCIMG_FDCT_8X8 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_fdct_8x8" -ccs.definePathVariable EXT_ROOT__IMG_FDCT_8X8_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_FDCT_8X8_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_fdct_8x8.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_FDCT_8X8_66_LE_COFF=.././ >> ./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_FDCT_8X8_66_LE_COFF_SRCIMG_FDCT_8X8=../../ >> ./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_FDCT_8X8_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_FDCT_8X8_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_COFF/Release/IMG_fdct_8x8_66_LE_COFF.out: ./src/IMG_fdct_8x8/IMG_fdct_8x8.h
./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_COFF/Release/IMG_fdct_8x8_66_LE_COFF.out: ./src/IMG_fdct_8x8/IMG_fdct_8x8_cn.c
./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_COFF/Release/IMG_fdct_8x8_66_LE_COFF.out: ./src/IMG_fdct_8x8/IMG_fdct_8x8_cn.h
./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_COFF/Release/IMG_fdct_8x8_66_LE_COFF.out: ./src/IMG_fdct_8x8/IMG_fdct_8x8_d.c
./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_COFF/Release/IMG_fdct_8x8_66_LE_COFF.out: ./src/IMG_fdct_8x8/IMG_fdct_8x8_idat.c
./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_COFF/Release/IMG_fdct_8x8_66_LE_COFF.out: ./src/IMG_fdct_8x8/IMG_fdct_8x8_odat.c
./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_COFF/Release/IMG_fdct_8x8_66_LE_COFF.out: ./src/IMG_fdct_8x8//c66/IMG_fdct_8x8.h
./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_COFF/Release/IMG_fdct_8x8_66_LE_COFF.out: ./src/IMG_fdct_8x8//c66/IMG_fdct_8x8.s
./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_COFF/Release/IMG_fdct_8x8_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_COFF/Release/IMG_fdct_8x8_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_COFF/Release/IMG_fdct_8x8_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_COFF/Release/IMG_fdct_8x8_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_COFF/Release/IMG_fdct_8x8_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_COFF/Release/IMG_fdct_8x8_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_COFF/Release/IMG_fdct_8x8_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_COFF/Release/IMG_fdct_8x8_66_LE_COFF.out: ./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_COFF/.project
	-@ echo Importing Project IMG_fdct_8x8_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_fdct_8x8_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_fdct_8x8/c66/IMG_fdct_8x8_66_LE_COFF"
	-@ echo Building Project IMG_fdct_8x8_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_fdct_8x8_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_fdct_8x8_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_COFF/.settings"

	-@ echo Project IMG_fdct_8x8_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_fdct_8x8_66_LE_ELF

#############################################################

all: ./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_ELF/Release/IMG_fdct_8x8_66_LE_ELF.out

./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_fdct_8x8_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_FDCT_8X8_66_LE_ELF_SRCIMG_FDCT_8X8/IMG_fdct_8x8_cn.c -ccs.linkFile EXT_ROOT__IMG_FDCT_8X8_66_LE_ELF_SRCIMG_FDCT_8X8/IMG_fdct_8x8_d.c -ccs.linkFile EXT_ROOT__IMG_FDCT_8X8_66_LE_ELF_SRCIMG_FDCT_8X8/IMG_fdct_8x8_idat.c -ccs.linkFile EXT_ROOT__IMG_FDCT_8X8_66_LE_ELF_SRCIMG_FDCT_8X8/IMG_fdct_8x8_odat.c -ccs.linkFile EXT_ROOT__IMG_FDCT_8X8_66_LE_ELF/IMG_fdct_8x8.s -ccs.linkFile EXT_ROOT__IMG_FDCT_8X8_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_FDCT_8X8_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_FDCT_8X8_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_FDCT_8X8_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_FDCT_8X8_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_fdct_8x8/c66" -ccs.definePathVariable EXT_ROOT__IMG_FDCT_8X8_66_LE_ELF_SRCIMG_FDCT_8X8 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_fdct_8x8" -ccs.definePathVariable EXT_ROOT__IMG_FDCT_8X8_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_FDCT_8X8_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_fdct_8x8.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_FDCT_8X8_66_LE_ELF=.././ >> ./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_FDCT_8X8_66_LE_ELF_SRCIMG_FDCT_8X8=../../ >> ./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_FDCT_8X8_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_FDCT_8X8_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_ELF/Release/IMG_fdct_8x8_66_LE_ELF.out: ./src/IMG_fdct_8x8/IMG_fdct_8x8.h
./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_ELF/Release/IMG_fdct_8x8_66_LE_ELF.out: ./src/IMG_fdct_8x8/IMG_fdct_8x8_cn.c
./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_ELF/Release/IMG_fdct_8x8_66_LE_ELF.out: ./src/IMG_fdct_8x8/IMG_fdct_8x8_cn.h
./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_ELF/Release/IMG_fdct_8x8_66_LE_ELF.out: ./src/IMG_fdct_8x8/IMG_fdct_8x8_d.c
./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_ELF/Release/IMG_fdct_8x8_66_LE_ELF.out: ./src/IMG_fdct_8x8/IMG_fdct_8x8_idat.c
./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_ELF/Release/IMG_fdct_8x8_66_LE_ELF.out: ./src/IMG_fdct_8x8/IMG_fdct_8x8_odat.c
./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_ELF/Release/IMG_fdct_8x8_66_LE_ELF.out: ./src/IMG_fdct_8x8//c66/IMG_fdct_8x8.h
./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_ELF/Release/IMG_fdct_8x8_66_LE_ELF.out: ./src/IMG_fdct_8x8//c66/IMG_fdct_8x8.s
./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_ELF/Release/IMG_fdct_8x8_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_ELF/Release/IMG_fdct_8x8_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_ELF/Release/IMG_fdct_8x8_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_ELF/Release/IMG_fdct_8x8_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_ELF/Release/IMG_fdct_8x8_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_ELF/Release/IMG_fdct_8x8_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_ELF/Release/IMG_fdct_8x8_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_ELF/Release/IMG_fdct_8x8_66_LE_ELF.out: ./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_ELF/.project
	-@ echo Importing Project IMG_fdct_8x8_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_fdct_8x8_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_fdct_8x8/c66/IMG_fdct_8x8_66_LE_ELF"
	-@ echo Building Project IMG_fdct_8x8_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_fdct_8x8_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_fdct_8x8_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_ELF/.settings"

	-@ echo Project IMG_fdct_8x8_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_fdct_8x8//c66//IMG_fdct_8x8_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_histogram_16_66_LE_COFF

#############################################################

all: ./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_COFF/Release/IMG_histogram_16_66_LE_COFF.out

./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_histogram_16_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_HISTOGRAM_16_66_LE_COFF_SRCIMG_HISTOGRAM_16/IMG_histogram_16_cn.c -ccs.linkFile EXT_ROOT__IMG_HISTOGRAM_16_66_LE_COFF_SRCIMG_HISTOGRAM_16/IMG_histogram_16_d.c -ccs.linkFile EXT_ROOT__IMG_HISTOGRAM_16_66_LE_COFF_SRCIMG_HISTOGRAM_16/IMG_histogram_16_idat.c -ccs.linkFile EXT_ROOT__IMG_HISTOGRAM_16_66_LE_COFF_SRCIMG_HISTOGRAM_16/IMG_histogram_16_odat.c -ccs.linkFile EXT_ROOT__IMG_HISTOGRAM_16_66_LE_COFF/IMG_histogram_16.c -ccs.linkFile EXT_ROOT__IMG_HISTOGRAM_16_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_HISTOGRAM_16_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_HISTOGRAM_16_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_HISTOGRAM_16_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_HISTOGRAM_16_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_histogram_16/c66" -ccs.definePathVariable EXT_ROOT__IMG_HISTOGRAM_16_66_LE_COFF_SRCIMG_HISTOGRAM_16 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_histogram_16" -ccs.definePathVariable EXT_ROOT__IMG_HISTOGRAM_16_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_HISTOGRAM_16_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_histogram_16.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_HISTOGRAM_16_66_LE_COFF=.././ >> ./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_HISTOGRAM_16_66_LE_COFF_SRCIMG_HISTOGRAM_16=../../ >> ./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_HISTOGRAM_16_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_HISTOGRAM_16_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_COFF/Release/IMG_histogram_16_66_LE_COFF.out: ./src/IMG_histogram_16/IMG_histogram_16.h
./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_COFF/Release/IMG_histogram_16_66_LE_COFF.out: ./src/IMG_histogram_16/IMG_histogram_16_cn.c
./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_COFF/Release/IMG_histogram_16_66_LE_COFF.out: ./src/IMG_histogram_16/IMG_histogram_16_cn.h
./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_COFF/Release/IMG_histogram_16_66_LE_COFF.out: ./src/IMG_histogram_16/IMG_histogram_16_d.c
./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_COFF/Release/IMG_histogram_16_66_LE_COFF.out: ./src/IMG_histogram_16/IMG_histogram_16_idat.c
./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_COFF/Release/IMG_histogram_16_66_LE_COFF.out: ./src/IMG_histogram_16/IMG_histogram_16_odat.c
./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_COFF/Release/IMG_histogram_16_66_LE_COFF.out: ./src/IMG_histogram_16//c66/IMG_histogram_16.c
./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_COFF/Release/IMG_histogram_16_66_LE_COFF.out: ./src/IMG_histogram_16//c66/IMG_histogram_16.h
./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_COFF/Release/IMG_histogram_16_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_COFF/Release/IMG_histogram_16_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_COFF/Release/IMG_histogram_16_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_COFF/Release/IMG_histogram_16_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_COFF/Release/IMG_histogram_16_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_COFF/Release/IMG_histogram_16_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_COFF/Release/IMG_histogram_16_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_COFF/Release/IMG_histogram_16_66_LE_COFF.out: ./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_COFF/.project
	-@ echo Importing Project IMG_histogram_16_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_histogram_16_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_histogram_16/c66/IMG_histogram_16_66_LE_COFF"
	-@ echo Building Project IMG_histogram_16_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_histogram_16_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_histogram_16_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_COFF/.settings"

	-@ echo Project IMG_histogram_16_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_histogram_16_66_LE_ELF

#############################################################

all: ./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_ELF/Release/IMG_histogram_16_66_LE_ELF.out

./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_histogram_16_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_HISTOGRAM_16_66_LE_ELF_SRCIMG_HISTOGRAM_16/IMG_histogram_16_cn.c -ccs.linkFile EXT_ROOT__IMG_HISTOGRAM_16_66_LE_ELF_SRCIMG_HISTOGRAM_16/IMG_histogram_16_d.c -ccs.linkFile EXT_ROOT__IMG_HISTOGRAM_16_66_LE_ELF_SRCIMG_HISTOGRAM_16/IMG_histogram_16_idat.c -ccs.linkFile EXT_ROOT__IMG_HISTOGRAM_16_66_LE_ELF_SRCIMG_HISTOGRAM_16/IMG_histogram_16_odat.c -ccs.linkFile EXT_ROOT__IMG_HISTOGRAM_16_66_LE_ELF/IMG_histogram_16.c -ccs.linkFile EXT_ROOT__IMG_HISTOGRAM_16_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_HISTOGRAM_16_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_HISTOGRAM_16_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_HISTOGRAM_16_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_HISTOGRAM_16_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_histogram_16/c66" -ccs.definePathVariable EXT_ROOT__IMG_HISTOGRAM_16_66_LE_ELF_SRCIMG_HISTOGRAM_16 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_histogram_16" -ccs.definePathVariable EXT_ROOT__IMG_HISTOGRAM_16_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_HISTOGRAM_16_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_histogram_16.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_HISTOGRAM_16_66_LE_ELF=.././ >> ./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_HISTOGRAM_16_66_LE_ELF_SRCIMG_HISTOGRAM_16=../../ >> ./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_HISTOGRAM_16_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_HISTOGRAM_16_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_ELF/Release/IMG_histogram_16_66_LE_ELF.out: ./src/IMG_histogram_16/IMG_histogram_16.h
./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_ELF/Release/IMG_histogram_16_66_LE_ELF.out: ./src/IMG_histogram_16/IMG_histogram_16_cn.c
./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_ELF/Release/IMG_histogram_16_66_LE_ELF.out: ./src/IMG_histogram_16/IMG_histogram_16_cn.h
./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_ELF/Release/IMG_histogram_16_66_LE_ELF.out: ./src/IMG_histogram_16/IMG_histogram_16_d.c
./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_ELF/Release/IMG_histogram_16_66_LE_ELF.out: ./src/IMG_histogram_16/IMG_histogram_16_idat.c
./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_ELF/Release/IMG_histogram_16_66_LE_ELF.out: ./src/IMG_histogram_16/IMG_histogram_16_odat.c
./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_ELF/Release/IMG_histogram_16_66_LE_ELF.out: ./src/IMG_histogram_16//c66/IMG_histogram_16.c
./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_ELF/Release/IMG_histogram_16_66_LE_ELF.out: ./src/IMG_histogram_16//c66/IMG_histogram_16.h
./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_ELF/Release/IMG_histogram_16_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_ELF/Release/IMG_histogram_16_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_ELF/Release/IMG_histogram_16_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_ELF/Release/IMG_histogram_16_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_ELF/Release/IMG_histogram_16_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_ELF/Release/IMG_histogram_16_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_ELF/Release/IMG_histogram_16_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_ELF/Release/IMG_histogram_16_66_LE_ELF.out: ./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_ELF/.project
	-@ echo Importing Project IMG_histogram_16_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_histogram_16_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_histogram_16/c66/IMG_histogram_16_66_LE_ELF"
	-@ echo Building Project IMG_histogram_16_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_histogram_16_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_histogram_16_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_ELF/.settings"

	-@ echo Project IMG_histogram_16_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_histogram_16//c66//IMG_histogram_16_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_histogram_8_66_LE_COFF

#############################################################

all: ./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_COFF/Release/IMG_histogram_8_66_LE_COFF.out

./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_histogram_8_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_HISTOGRAM_8_66_LE_COFF_SRCIMG_HISTOGRAM_8/IMG_histogram_8_cn.c -ccs.linkFile EXT_ROOT__IMG_HISTOGRAM_8_66_LE_COFF_SRCIMG_HISTOGRAM_8/IMG_histogram_8_d.c -ccs.linkFile EXT_ROOT__IMG_HISTOGRAM_8_66_LE_COFF_SRCIMG_HISTOGRAM_8/IMG_histogram_8_idat.c -ccs.linkFile EXT_ROOT__IMG_HISTOGRAM_8_66_LE_COFF_SRCIMG_HISTOGRAM_8/IMG_histogram_8_odat.c -ccs.linkFile EXT_ROOT__IMG_HISTOGRAM_8_66_LE_COFF/IMG_histogram_8.c -ccs.linkFile EXT_ROOT__IMG_HISTOGRAM_8_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_HISTOGRAM_8_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_HISTOGRAM_8_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_HISTOGRAM_8_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_HISTOGRAM_8_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_histogram_8/c66" -ccs.definePathVariable EXT_ROOT__IMG_HISTOGRAM_8_66_LE_COFF_SRCIMG_HISTOGRAM_8 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_histogram_8" -ccs.definePathVariable EXT_ROOT__IMG_HISTOGRAM_8_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_HISTOGRAM_8_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_histogram_8.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_HISTOGRAM_8_66_LE_COFF=.././ >> ./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_HISTOGRAM_8_66_LE_COFF_SRCIMG_HISTOGRAM_8=../../ >> ./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_HISTOGRAM_8_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_HISTOGRAM_8_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_COFF/Release/IMG_histogram_8_66_LE_COFF.out: ./src/IMG_histogram_8/IMG_histogram_8.h
./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_COFF/Release/IMG_histogram_8_66_LE_COFF.out: ./src/IMG_histogram_8/IMG_histogram_8_cn.c
./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_COFF/Release/IMG_histogram_8_66_LE_COFF.out: ./src/IMG_histogram_8/IMG_histogram_8_cn.h
./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_COFF/Release/IMG_histogram_8_66_LE_COFF.out: ./src/IMG_histogram_8/IMG_histogram_8_d.c
./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_COFF/Release/IMG_histogram_8_66_LE_COFF.out: ./src/IMG_histogram_8/IMG_histogram_8_idat.c
./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_COFF/Release/IMG_histogram_8_66_LE_COFF.out: ./src/IMG_histogram_8/IMG_histogram_8_odat.c
./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_COFF/Release/IMG_histogram_8_66_LE_COFF.out: ./src/IMG_histogram_8//c66/IMG_histogram_8.c
./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_COFF/Release/IMG_histogram_8_66_LE_COFF.out: ./src/IMG_histogram_8//c66/IMG_histogram_8.h
./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_COFF/Release/IMG_histogram_8_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_COFF/Release/IMG_histogram_8_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_COFF/Release/IMG_histogram_8_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_COFF/Release/IMG_histogram_8_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_COFF/Release/IMG_histogram_8_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_COFF/Release/IMG_histogram_8_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_COFF/Release/IMG_histogram_8_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_COFF/Release/IMG_histogram_8_66_LE_COFF.out: ./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_COFF/.project
	-@ echo Importing Project IMG_histogram_8_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_histogram_8_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_histogram_8/c66/IMG_histogram_8_66_LE_COFF"
	-@ echo Building Project IMG_histogram_8_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_histogram_8_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_histogram_8_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_COFF/.settings"

	-@ echo Project IMG_histogram_8_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_histogram_8_66_LE_ELF

#############################################################

all: ./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_ELF/Release/IMG_histogram_8_66_LE_ELF.out

./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_histogram_8_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_HISTOGRAM_8_66_LE_ELF_SRCIMG_HISTOGRAM_8/IMG_histogram_8_cn.c -ccs.linkFile EXT_ROOT__IMG_HISTOGRAM_8_66_LE_ELF_SRCIMG_HISTOGRAM_8/IMG_histogram_8_d.c -ccs.linkFile EXT_ROOT__IMG_HISTOGRAM_8_66_LE_ELF_SRCIMG_HISTOGRAM_8/IMG_histogram_8_idat.c -ccs.linkFile EXT_ROOT__IMG_HISTOGRAM_8_66_LE_ELF_SRCIMG_HISTOGRAM_8/IMG_histogram_8_odat.c -ccs.linkFile EXT_ROOT__IMG_HISTOGRAM_8_66_LE_ELF/IMG_histogram_8.c -ccs.linkFile EXT_ROOT__IMG_HISTOGRAM_8_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_HISTOGRAM_8_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_HISTOGRAM_8_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_HISTOGRAM_8_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_HISTOGRAM_8_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_histogram_8/c66" -ccs.definePathVariable EXT_ROOT__IMG_HISTOGRAM_8_66_LE_ELF_SRCIMG_HISTOGRAM_8 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_histogram_8" -ccs.definePathVariable EXT_ROOT__IMG_HISTOGRAM_8_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_HISTOGRAM_8_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_histogram_8.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_HISTOGRAM_8_66_LE_ELF=.././ >> ./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_HISTOGRAM_8_66_LE_ELF_SRCIMG_HISTOGRAM_8=../../ >> ./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_HISTOGRAM_8_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_HISTOGRAM_8_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_ELF/Release/IMG_histogram_8_66_LE_ELF.out: ./src/IMG_histogram_8/IMG_histogram_8.h
./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_ELF/Release/IMG_histogram_8_66_LE_ELF.out: ./src/IMG_histogram_8/IMG_histogram_8_cn.c
./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_ELF/Release/IMG_histogram_8_66_LE_ELF.out: ./src/IMG_histogram_8/IMG_histogram_8_cn.h
./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_ELF/Release/IMG_histogram_8_66_LE_ELF.out: ./src/IMG_histogram_8/IMG_histogram_8_d.c
./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_ELF/Release/IMG_histogram_8_66_LE_ELF.out: ./src/IMG_histogram_8/IMG_histogram_8_idat.c
./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_ELF/Release/IMG_histogram_8_66_LE_ELF.out: ./src/IMG_histogram_8/IMG_histogram_8_odat.c
./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_ELF/Release/IMG_histogram_8_66_LE_ELF.out: ./src/IMG_histogram_8//c66/IMG_histogram_8.c
./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_ELF/Release/IMG_histogram_8_66_LE_ELF.out: ./src/IMG_histogram_8//c66/IMG_histogram_8.h
./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_ELF/Release/IMG_histogram_8_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_ELF/Release/IMG_histogram_8_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_ELF/Release/IMG_histogram_8_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_ELF/Release/IMG_histogram_8_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_ELF/Release/IMG_histogram_8_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_ELF/Release/IMG_histogram_8_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_ELF/Release/IMG_histogram_8_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_ELF/Release/IMG_histogram_8_66_LE_ELF.out: ./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_ELF/.project
	-@ echo Importing Project IMG_histogram_8_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_histogram_8_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_histogram_8/c66/IMG_histogram_8_66_LE_ELF"
	-@ echo Building Project IMG_histogram_8_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_histogram_8_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_histogram_8_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_ELF/.settings"

	-@ echo Project IMG_histogram_8_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_histogram_8//c66//IMG_histogram_8_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_idct_8x8_12q4_66_LE_COFF

#############################################################

all: ./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_COFF/Release/IMG_idct_8x8_12q4_66_LE_COFF.out

./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_idct_8x8_12q4_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_IDCT_8X8_12Q4_66_LE_COFF_SRCIMG_IDCT_8X8_12Q4/IMG_idct_8x8_12q4_cn.c -ccs.linkFile EXT_ROOT__IMG_IDCT_8X8_12Q4_66_LE_COFF_SRCIMG_IDCT_8X8_12Q4/IMG_idct_8x8_12q4_d.c -ccs.linkFile EXT_ROOT__IMG_IDCT_8X8_12Q4_66_LE_COFF_SRCIMG_IDCT_8X8_12Q4/IMG_idct_8x8_12q4_idat.c -ccs.linkFile EXT_ROOT__IMG_IDCT_8X8_12Q4_66_LE_COFF_SRCIMG_IDCT_8X8_12Q4/IMG_idct_8x8_12q4_odat.c -ccs.linkFile EXT_ROOT__IMG_IDCT_8X8_12Q4_66_LE_COFF/IMG_idct_8x8_12q4.s -ccs.linkFile EXT_ROOT__IMG_IDCT_8X8_12Q4_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_IDCT_8X8_12Q4_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_IDCT_8X8_12Q4_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_IDCT_8X8_12Q4_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_IDCT_8X8_12Q4_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_idct_8x8_12q4/c66" -ccs.definePathVariable EXT_ROOT__IMG_IDCT_8X8_12Q4_66_LE_COFF_SRCIMG_IDCT_8X8_12Q4 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_idct_8x8_12q4" -ccs.definePathVariable EXT_ROOT__IMG_IDCT_8X8_12Q4_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_IDCT_8X8_12Q4_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_idct_8x8_12q4.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_IDCT_8X8_12Q4_66_LE_COFF=.././ >> ./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_IDCT_8X8_12Q4_66_LE_COFF_SRCIMG_IDCT_8X8_12Q4=../../ >> ./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_IDCT_8X8_12Q4_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_IDCT_8X8_12Q4_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_COFF/Release/IMG_idct_8x8_12q4_66_LE_COFF.out: ./src/IMG_idct_8x8_12q4/IMG_idct_8x8_12q4.h
./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_COFF/Release/IMG_idct_8x8_12q4_66_LE_COFF.out: ./src/IMG_idct_8x8_12q4/IMG_idct_8x8_12q4_cn.c
./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_COFF/Release/IMG_idct_8x8_12q4_66_LE_COFF.out: ./src/IMG_idct_8x8_12q4/IMG_idct_8x8_12q4_cn.h
./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_COFF/Release/IMG_idct_8x8_12q4_66_LE_COFF.out: ./src/IMG_idct_8x8_12q4/IMG_idct_8x8_12q4_d.c
./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_COFF/Release/IMG_idct_8x8_12q4_66_LE_COFF.out: ./src/IMG_idct_8x8_12q4/IMG_idct_8x8_12q4_idat.c
./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_COFF/Release/IMG_idct_8x8_12q4_66_LE_COFF.out: ./src/IMG_idct_8x8_12q4/IMG_idct_8x8_12q4_odat.c
./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_COFF/Release/IMG_idct_8x8_12q4_66_LE_COFF.out: ./src/IMG_idct_8x8_12q4//c66/IMG_idct_8x8_12q4.h
./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_COFF/Release/IMG_idct_8x8_12q4_66_LE_COFF.out: ./src/IMG_idct_8x8_12q4//c66/IMG_idct_8x8_12q4.s
./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_COFF/Release/IMG_idct_8x8_12q4_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_COFF/Release/IMG_idct_8x8_12q4_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_COFF/Release/IMG_idct_8x8_12q4_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_COFF/Release/IMG_idct_8x8_12q4_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_COFF/Release/IMG_idct_8x8_12q4_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_COFF/Release/IMG_idct_8x8_12q4_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_COFF/Release/IMG_idct_8x8_12q4_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_COFF/Release/IMG_idct_8x8_12q4_66_LE_COFF.out: ./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_COFF/.project
	-@ echo Importing Project IMG_idct_8x8_12q4_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_idct_8x8_12q4_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_idct_8x8_12q4/c66/IMG_idct_8x8_12q4_66_LE_COFF"
	-@ echo Building Project IMG_idct_8x8_12q4_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_idct_8x8_12q4_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_idct_8x8_12q4_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_COFF/.settings"

	-@ echo Project IMG_idct_8x8_12q4_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_idct_8x8_12q4_66_LE_ELF

#############################################################

all: ./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_ELF/Release/IMG_idct_8x8_12q4_66_LE_ELF.out

./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_idct_8x8_12q4_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_IDCT_8X8_12Q4_66_LE_ELF_SRCIMG_IDCT_8X8_12Q4/IMG_idct_8x8_12q4_cn.c -ccs.linkFile EXT_ROOT__IMG_IDCT_8X8_12Q4_66_LE_ELF_SRCIMG_IDCT_8X8_12Q4/IMG_idct_8x8_12q4_d.c -ccs.linkFile EXT_ROOT__IMG_IDCT_8X8_12Q4_66_LE_ELF_SRCIMG_IDCT_8X8_12Q4/IMG_idct_8x8_12q4_idat.c -ccs.linkFile EXT_ROOT__IMG_IDCT_8X8_12Q4_66_LE_ELF_SRCIMG_IDCT_8X8_12Q4/IMG_idct_8x8_12q4_odat.c -ccs.linkFile EXT_ROOT__IMG_IDCT_8X8_12Q4_66_LE_ELF/IMG_idct_8x8_12q4.s -ccs.linkFile EXT_ROOT__IMG_IDCT_8X8_12Q4_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_IDCT_8X8_12Q4_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_IDCT_8X8_12Q4_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_IDCT_8X8_12Q4_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_IDCT_8X8_12Q4_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_idct_8x8_12q4/c66" -ccs.definePathVariable EXT_ROOT__IMG_IDCT_8X8_12Q4_66_LE_ELF_SRCIMG_IDCT_8X8_12Q4 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_idct_8x8_12q4" -ccs.definePathVariable EXT_ROOT__IMG_IDCT_8X8_12Q4_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_IDCT_8X8_12Q4_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_idct_8x8_12q4.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_IDCT_8X8_12Q4_66_LE_ELF=.././ >> ./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_IDCT_8X8_12Q4_66_LE_ELF_SRCIMG_IDCT_8X8_12Q4=../../ >> ./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_IDCT_8X8_12Q4_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_IDCT_8X8_12Q4_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_ELF/Release/IMG_idct_8x8_12q4_66_LE_ELF.out: ./src/IMG_idct_8x8_12q4/IMG_idct_8x8_12q4.h
./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_ELF/Release/IMG_idct_8x8_12q4_66_LE_ELF.out: ./src/IMG_idct_8x8_12q4/IMG_idct_8x8_12q4_cn.c
./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_ELF/Release/IMG_idct_8x8_12q4_66_LE_ELF.out: ./src/IMG_idct_8x8_12q4/IMG_idct_8x8_12q4_cn.h
./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_ELF/Release/IMG_idct_8x8_12q4_66_LE_ELF.out: ./src/IMG_idct_8x8_12q4/IMG_idct_8x8_12q4_d.c
./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_ELF/Release/IMG_idct_8x8_12q4_66_LE_ELF.out: ./src/IMG_idct_8x8_12q4/IMG_idct_8x8_12q4_idat.c
./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_ELF/Release/IMG_idct_8x8_12q4_66_LE_ELF.out: ./src/IMG_idct_8x8_12q4/IMG_idct_8x8_12q4_odat.c
./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_ELF/Release/IMG_idct_8x8_12q4_66_LE_ELF.out: ./src/IMG_idct_8x8_12q4//c66/IMG_idct_8x8_12q4.h
./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_ELF/Release/IMG_idct_8x8_12q4_66_LE_ELF.out: ./src/IMG_idct_8x8_12q4//c66/IMG_idct_8x8_12q4.s
./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_ELF/Release/IMG_idct_8x8_12q4_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_ELF/Release/IMG_idct_8x8_12q4_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_ELF/Release/IMG_idct_8x8_12q4_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_ELF/Release/IMG_idct_8x8_12q4_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_ELF/Release/IMG_idct_8x8_12q4_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_ELF/Release/IMG_idct_8x8_12q4_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_ELF/Release/IMG_idct_8x8_12q4_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_ELF/Release/IMG_idct_8x8_12q4_66_LE_ELF.out: ./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_ELF/.project
	-@ echo Importing Project IMG_idct_8x8_12q4_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_idct_8x8_12q4_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_idct_8x8_12q4/c66/IMG_idct_8x8_12q4_66_LE_ELF"
	-@ echo Building Project IMG_idct_8x8_12q4_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_idct_8x8_12q4_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_idct_8x8_12q4_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_ELF/.settings"

	-@ echo Project IMG_idct_8x8_12q4_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_idct_8x8_12q4//c66//IMG_idct_8x8_12q4_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_mad_16x16_66_LE_COFF

#############################################################

all: ./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_COFF/Release/IMG_mad_16x16_66_LE_COFF.out

./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_mad_16x16_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_MAD_16X16_66_LE_COFF_SRCIMG_MAD_16X16/IMG_mad_16x16_cn.c -ccs.linkFile EXT_ROOT__IMG_MAD_16X16_66_LE_COFF_SRCIMG_MAD_16X16/IMG_mad_16x16_d.c -ccs.linkFile EXT_ROOT__IMG_MAD_16X16_66_LE_COFF/IMG_mad_16x16.s -ccs.linkFile EXT_ROOT__IMG_MAD_16X16_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_MAD_16X16_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_MAD_16X16_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_MAD_16X16_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_MAD_16X16_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_mad_16x16/c66" -ccs.definePathVariable EXT_ROOT__IMG_MAD_16X16_66_LE_COFF_SRCIMG_MAD_16X16 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_mad_16x16" -ccs.definePathVariable EXT_ROOT__IMG_MAD_16X16_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_MAD_16X16_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_mad_16x16.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_MAD_16X16_66_LE_COFF=.././ >> ./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_MAD_16X16_66_LE_COFF_SRCIMG_MAD_16X16=../../ >> ./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_MAD_16X16_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_MAD_16X16_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_COFF/Release/IMG_mad_16x16_66_LE_COFF.out: ./src/IMG_mad_16x16/IMG_mad_16x16.h
./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_COFF/Release/IMG_mad_16x16_66_LE_COFF.out: ./src/IMG_mad_16x16/IMG_mad_16x16_cn.c
./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_COFF/Release/IMG_mad_16x16_66_LE_COFF.out: ./src/IMG_mad_16x16/IMG_mad_16x16_cn.h
./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_COFF/Release/IMG_mad_16x16_66_LE_COFF.out: ./src/IMG_mad_16x16/IMG_mad_16x16_d.c
./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_COFF/Release/IMG_mad_16x16_66_LE_COFF.out: ./src/IMG_mad_16x16//c66/IMG_mad_16x16.h
./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_COFF/Release/IMG_mad_16x16_66_LE_COFF.out: ./src/IMG_mad_16x16//c66/IMG_mad_16x16.s
./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_COFF/Release/IMG_mad_16x16_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_COFF/Release/IMG_mad_16x16_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_COFF/Release/IMG_mad_16x16_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_COFF/Release/IMG_mad_16x16_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_COFF/Release/IMG_mad_16x16_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_COFF/Release/IMG_mad_16x16_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_COFF/Release/IMG_mad_16x16_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_COFF/Release/IMG_mad_16x16_66_LE_COFF.out: ./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_COFF/.project
	-@ echo Importing Project IMG_mad_16x16_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_mad_16x16_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_mad_16x16/c66/IMG_mad_16x16_66_LE_COFF"
	-@ echo Building Project IMG_mad_16x16_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_mad_16x16_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_mad_16x16_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_COFF/.settings"

	-@ echo Project IMG_mad_16x16_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_mad_16x16_66_LE_ELF

#############################################################

all: ./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_ELF/Release/IMG_mad_16x16_66_LE_ELF.out

./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_mad_16x16_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_MAD_16X16_66_LE_ELF_SRCIMG_MAD_16X16/IMG_mad_16x16_cn.c -ccs.linkFile EXT_ROOT__IMG_MAD_16X16_66_LE_ELF_SRCIMG_MAD_16X16/IMG_mad_16x16_d.c -ccs.linkFile EXT_ROOT__IMG_MAD_16X16_66_LE_ELF/IMG_mad_16x16.s -ccs.linkFile EXT_ROOT__IMG_MAD_16X16_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_MAD_16X16_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_MAD_16X16_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_MAD_16X16_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_MAD_16X16_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_mad_16x16/c66" -ccs.definePathVariable EXT_ROOT__IMG_MAD_16X16_66_LE_ELF_SRCIMG_MAD_16X16 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_mad_16x16" -ccs.definePathVariable EXT_ROOT__IMG_MAD_16X16_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_MAD_16X16_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_mad_16x16.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_MAD_16X16_66_LE_ELF=.././ >> ./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_MAD_16X16_66_LE_ELF_SRCIMG_MAD_16X16=../../ >> ./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_MAD_16X16_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_MAD_16X16_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_ELF/Release/IMG_mad_16x16_66_LE_ELF.out: ./src/IMG_mad_16x16/IMG_mad_16x16.h
./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_ELF/Release/IMG_mad_16x16_66_LE_ELF.out: ./src/IMG_mad_16x16/IMG_mad_16x16_cn.c
./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_ELF/Release/IMG_mad_16x16_66_LE_ELF.out: ./src/IMG_mad_16x16/IMG_mad_16x16_cn.h
./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_ELF/Release/IMG_mad_16x16_66_LE_ELF.out: ./src/IMG_mad_16x16/IMG_mad_16x16_d.c
./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_ELF/Release/IMG_mad_16x16_66_LE_ELF.out: ./src/IMG_mad_16x16//c66/IMG_mad_16x16.h
./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_ELF/Release/IMG_mad_16x16_66_LE_ELF.out: ./src/IMG_mad_16x16//c66/IMG_mad_16x16.s
./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_ELF/Release/IMG_mad_16x16_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_ELF/Release/IMG_mad_16x16_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_ELF/Release/IMG_mad_16x16_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_ELF/Release/IMG_mad_16x16_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_ELF/Release/IMG_mad_16x16_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_ELF/Release/IMG_mad_16x16_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_ELF/Release/IMG_mad_16x16_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_ELF/Release/IMG_mad_16x16_66_LE_ELF.out: ./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_ELF/.project
	-@ echo Importing Project IMG_mad_16x16_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_mad_16x16_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_mad_16x16/c66/IMG_mad_16x16_66_LE_ELF"
	-@ echo Building Project IMG_mad_16x16_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_mad_16x16_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_mad_16x16_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_ELF/.settings"

	-@ echo Project IMG_mad_16x16_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_mad_16x16//c66//IMG_mad_16x16_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_mad_8x8_66_LE_COFF

#############################################################

all: ./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_COFF/Release/IMG_mad_8x8_66_LE_COFF.out

./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_mad_8x8_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_MAD_8X8_66_LE_COFF_SRCIMG_MAD_8X8/IMG_mad_8x8_cn.c -ccs.linkFile EXT_ROOT__IMG_MAD_8X8_66_LE_COFF_SRCIMG_MAD_8X8/IMG_mad_8x8_d.c -ccs.linkFile EXT_ROOT__IMG_MAD_8X8_66_LE_COFF/IMG_mad_8x8.s -ccs.linkFile EXT_ROOT__IMG_MAD_8X8_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_MAD_8X8_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_MAD_8X8_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_MAD_8X8_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_MAD_8X8_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_mad_8x8/c66" -ccs.definePathVariable EXT_ROOT__IMG_MAD_8X8_66_LE_COFF_SRCIMG_MAD_8X8 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_mad_8x8" -ccs.definePathVariable EXT_ROOT__IMG_MAD_8X8_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_MAD_8X8_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_mad_8x8.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_MAD_8X8_66_LE_COFF=.././ >> ./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_MAD_8X8_66_LE_COFF_SRCIMG_MAD_8X8=../../ >> ./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_MAD_8X8_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_MAD_8X8_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_COFF/Release/IMG_mad_8x8_66_LE_COFF.out: ./src/IMG_mad_8x8/IMG_mad_8x8.h
./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_COFF/Release/IMG_mad_8x8_66_LE_COFF.out: ./src/IMG_mad_8x8/IMG_mad_8x8_cn.c
./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_COFF/Release/IMG_mad_8x8_66_LE_COFF.out: ./src/IMG_mad_8x8/IMG_mad_8x8_cn.h
./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_COFF/Release/IMG_mad_8x8_66_LE_COFF.out: ./src/IMG_mad_8x8/IMG_mad_8x8_d.c
./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_COFF/Release/IMG_mad_8x8_66_LE_COFF.out: ./src/IMG_mad_8x8//c66/IMG_mad_8x8.h
./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_COFF/Release/IMG_mad_8x8_66_LE_COFF.out: ./src/IMG_mad_8x8//c66/IMG_mad_8x8.s
./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_COFF/Release/IMG_mad_8x8_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_COFF/Release/IMG_mad_8x8_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_COFF/Release/IMG_mad_8x8_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_COFF/Release/IMG_mad_8x8_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_COFF/Release/IMG_mad_8x8_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_COFF/Release/IMG_mad_8x8_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_COFF/Release/IMG_mad_8x8_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_COFF/Release/IMG_mad_8x8_66_LE_COFF.out: ./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_COFF/.project
	-@ echo Importing Project IMG_mad_8x8_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_mad_8x8_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_mad_8x8/c66/IMG_mad_8x8_66_LE_COFF"
	-@ echo Building Project IMG_mad_8x8_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_mad_8x8_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_mad_8x8_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_COFF/.settings"

	-@ echo Project IMG_mad_8x8_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_mad_8x8_66_LE_ELF

#############################################################

all: ./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_ELF/Release/IMG_mad_8x8_66_LE_ELF.out

./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_mad_8x8_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_MAD_8X8_66_LE_ELF_SRCIMG_MAD_8X8/IMG_mad_8x8_cn.c -ccs.linkFile EXT_ROOT__IMG_MAD_8X8_66_LE_ELF_SRCIMG_MAD_8X8/IMG_mad_8x8_d.c -ccs.linkFile EXT_ROOT__IMG_MAD_8X8_66_LE_ELF/IMG_mad_8x8.s -ccs.linkFile EXT_ROOT__IMG_MAD_8X8_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_MAD_8X8_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_MAD_8X8_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_MAD_8X8_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_MAD_8X8_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_mad_8x8/c66" -ccs.definePathVariable EXT_ROOT__IMG_MAD_8X8_66_LE_ELF_SRCIMG_MAD_8X8 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_mad_8x8" -ccs.definePathVariable EXT_ROOT__IMG_MAD_8X8_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_MAD_8X8_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_mad_8x8.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_MAD_8X8_66_LE_ELF=.././ >> ./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_MAD_8X8_66_LE_ELF_SRCIMG_MAD_8X8=../../ >> ./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_MAD_8X8_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_MAD_8X8_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_ELF/Release/IMG_mad_8x8_66_LE_ELF.out: ./src/IMG_mad_8x8/IMG_mad_8x8.h
./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_ELF/Release/IMG_mad_8x8_66_LE_ELF.out: ./src/IMG_mad_8x8/IMG_mad_8x8_cn.c
./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_ELF/Release/IMG_mad_8x8_66_LE_ELF.out: ./src/IMG_mad_8x8/IMG_mad_8x8_cn.h
./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_ELF/Release/IMG_mad_8x8_66_LE_ELF.out: ./src/IMG_mad_8x8/IMG_mad_8x8_d.c
./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_ELF/Release/IMG_mad_8x8_66_LE_ELF.out: ./src/IMG_mad_8x8//c66/IMG_mad_8x8.h
./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_ELF/Release/IMG_mad_8x8_66_LE_ELF.out: ./src/IMG_mad_8x8//c66/IMG_mad_8x8.s
./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_ELF/Release/IMG_mad_8x8_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_ELF/Release/IMG_mad_8x8_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_ELF/Release/IMG_mad_8x8_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_ELF/Release/IMG_mad_8x8_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_ELF/Release/IMG_mad_8x8_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_ELF/Release/IMG_mad_8x8_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_ELF/Release/IMG_mad_8x8_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_ELF/Release/IMG_mad_8x8_66_LE_ELF.out: ./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_ELF/.project
	-@ echo Importing Project IMG_mad_8x8_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_mad_8x8_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_mad_8x8/c66/IMG_mad_8x8_66_LE_ELF"
	-@ echo Building Project IMG_mad_8x8_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_mad_8x8_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_mad_8x8_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_ELF/.settings"

	-@ echo Project IMG_mad_8x8_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_mad_8x8//c66//IMG_mad_8x8_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_median_3x3_16s_66_LE_COFF

#############################################################

all: ./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_COFF/Release/IMG_median_3x3_16s_66_LE_COFF.out

./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_median_3x3_16s_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_16S_66_LE_COFF_SRCIMG_MEDIAN_3X3_16S/IMG_median_3x3_16s_cn.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_16S_66_LE_COFF_SRCIMG_MEDIAN_3X3_16S/IMG_median_3x3_16s_d.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_16S_66_LE_COFF_SRCIMG_MEDIAN_3X3_16S/IMG_median_3x3_16s_idat.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_16S_66_LE_COFF_SRCIMG_MEDIAN_3X3_16S/IMG_median_3x3_16s_odat.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_16S_66_LE_COFF/IMG_median_3x3_16s.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_16S_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_16S_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_16S_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_16S_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_MEDIAN_3X3_16S_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_median_3x3_16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_MEDIAN_3X3_16S_66_LE_COFF_SRCIMG_MEDIAN_3X3_16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_median_3x3_16s" -ccs.definePathVariable EXT_ROOT__IMG_MEDIAN_3X3_16S_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_MEDIAN_3X3_16S_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_median_3x3_16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_MEDIAN_3X3_16S_66_LE_COFF=.././ >> ./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_MEDIAN_3X3_16S_66_LE_COFF_SRCIMG_MEDIAN_3X3_16S=../../ >> ./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_MEDIAN_3X3_16S_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_MEDIAN_3X3_16S_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_COFF/Release/IMG_median_3x3_16s_66_LE_COFF.out: ./src/IMG_median_3x3_16s/IMG_median_3x3_16s.h
./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_COFF/Release/IMG_median_3x3_16s_66_LE_COFF.out: ./src/IMG_median_3x3_16s/IMG_median_3x3_16s_cn.c
./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_COFF/Release/IMG_median_3x3_16s_66_LE_COFF.out: ./src/IMG_median_3x3_16s/IMG_median_3x3_16s_cn.h
./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_COFF/Release/IMG_median_3x3_16s_66_LE_COFF.out: ./src/IMG_median_3x3_16s/IMG_median_3x3_16s_d.c
./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_COFF/Release/IMG_median_3x3_16s_66_LE_COFF.out: ./src/IMG_median_3x3_16s/IMG_median_3x3_16s_idat.c
./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_COFF/Release/IMG_median_3x3_16s_66_LE_COFF.out: ./src/IMG_median_3x3_16s/IMG_median_3x3_16s_odat.c
./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_COFF/Release/IMG_median_3x3_16s_66_LE_COFF.out: ./src/IMG_median_3x3_16s//c66/IMG_median_3x3_16s.c
./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_COFF/Release/IMG_median_3x3_16s_66_LE_COFF.out: ./src/IMG_median_3x3_16s//c66/IMG_median_3x3_16s.h
./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_COFF/Release/IMG_median_3x3_16s_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_COFF/Release/IMG_median_3x3_16s_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_COFF/Release/IMG_median_3x3_16s_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_COFF/Release/IMG_median_3x3_16s_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_COFF/Release/IMG_median_3x3_16s_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_COFF/Release/IMG_median_3x3_16s_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_COFF/Release/IMG_median_3x3_16s_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_COFF/Release/IMG_median_3x3_16s_66_LE_COFF.out: ./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_COFF/.project
	-@ echo Importing Project IMG_median_3x3_16s_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_median_3x3_16s_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_median_3x3_16s/c66/IMG_median_3x3_16s_66_LE_COFF"
	-@ echo Building Project IMG_median_3x3_16s_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_median_3x3_16s_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_median_3x3_16s_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_COFF/.settings"

	-@ echo Project IMG_median_3x3_16s_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_median_3x3_16s_66_LE_ELF

#############################################################

all: ./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_ELF/Release/IMG_median_3x3_16s_66_LE_ELF.out

./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_median_3x3_16s_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_16S_66_LE_ELF_SRCIMG_MEDIAN_3X3_16S/IMG_median_3x3_16s_cn.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_16S_66_LE_ELF_SRCIMG_MEDIAN_3X3_16S/IMG_median_3x3_16s_d.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_16S_66_LE_ELF_SRCIMG_MEDIAN_3X3_16S/IMG_median_3x3_16s_idat.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_16S_66_LE_ELF_SRCIMG_MEDIAN_3X3_16S/IMG_median_3x3_16s_odat.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_16S_66_LE_ELF/IMG_median_3x3_16s.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_16S_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_16S_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_16S_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_16S_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_MEDIAN_3X3_16S_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_median_3x3_16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_MEDIAN_3X3_16S_66_LE_ELF_SRCIMG_MEDIAN_3X3_16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_median_3x3_16s" -ccs.definePathVariable EXT_ROOT__IMG_MEDIAN_3X3_16S_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_MEDIAN_3X3_16S_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_median_3x3_16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_MEDIAN_3X3_16S_66_LE_ELF=.././ >> ./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_MEDIAN_3X3_16S_66_LE_ELF_SRCIMG_MEDIAN_3X3_16S=../../ >> ./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_MEDIAN_3X3_16S_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_MEDIAN_3X3_16S_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_ELF/Release/IMG_median_3x3_16s_66_LE_ELF.out: ./src/IMG_median_3x3_16s/IMG_median_3x3_16s.h
./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_ELF/Release/IMG_median_3x3_16s_66_LE_ELF.out: ./src/IMG_median_3x3_16s/IMG_median_3x3_16s_cn.c
./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_ELF/Release/IMG_median_3x3_16s_66_LE_ELF.out: ./src/IMG_median_3x3_16s/IMG_median_3x3_16s_cn.h
./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_ELF/Release/IMG_median_3x3_16s_66_LE_ELF.out: ./src/IMG_median_3x3_16s/IMG_median_3x3_16s_d.c
./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_ELF/Release/IMG_median_3x3_16s_66_LE_ELF.out: ./src/IMG_median_3x3_16s/IMG_median_3x3_16s_idat.c
./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_ELF/Release/IMG_median_3x3_16s_66_LE_ELF.out: ./src/IMG_median_3x3_16s/IMG_median_3x3_16s_odat.c
./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_ELF/Release/IMG_median_3x3_16s_66_LE_ELF.out: ./src/IMG_median_3x3_16s//c66/IMG_median_3x3_16s.c
./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_ELF/Release/IMG_median_3x3_16s_66_LE_ELF.out: ./src/IMG_median_3x3_16s//c66/IMG_median_3x3_16s.h
./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_ELF/Release/IMG_median_3x3_16s_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_ELF/Release/IMG_median_3x3_16s_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_ELF/Release/IMG_median_3x3_16s_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_ELF/Release/IMG_median_3x3_16s_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_ELF/Release/IMG_median_3x3_16s_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_ELF/Release/IMG_median_3x3_16s_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_ELF/Release/IMG_median_3x3_16s_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_ELF/Release/IMG_median_3x3_16s_66_LE_ELF.out: ./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_ELF/.project
	-@ echo Importing Project IMG_median_3x3_16s_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_median_3x3_16s_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_median_3x3_16s/c66/IMG_median_3x3_16s_66_LE_ELF"
	-@ echo Building Project IMG_median_3x3_16s_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_median_3x3_16s_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_median_3x3_16s_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_ELF/.settings"

	-@ echo Project IMG_median_3x3_16s_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_median_3x3_16s//c66//IMG_median_3x3_16s_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_median_3x3_16_66_LE_COFF

#############################################################

all: ./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_COFF/Release/IMG_median_3x3_16_66_LE_COFF.out

./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_median_3x3_16_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_16_66_LE_COFF_SRCIMG_MEDIAN_3X3_16/IMG_median_3x3_16_cn.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_16_66_LE_COFF_SRCIMG_MEDIAN_3X3_16/IMG_median_3x3_16_d.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_16_66_LE_COFF_SRCIMG_MEDIAN_3X3_16/IMG_median_3x3_16_idat.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_16_66_LE_COFF_SRCIMG_MEDIAN_3X3_16/IMG_median_3x3_16_odat.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_16_66_LE_COFF/IMG_median_3x3_16.sa -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_16_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_16_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_16_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_16_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_MEDIAN_3X3_16_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_median_3x3_16/c66" -ccs.definePathVariable EXT_ROOT__IMG_MEDIAN_3X3_16_66_LE_COFF_SRCIMG_MEDIAN_3X3_16 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_median_3x3_16" -ccs.definePathVariable EXT_ROOT__IMG_MEDIAN_3X3_16_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_MEDIAN_3X3_16_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_median_3x3_16.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_MEDIAN_3X3_16_66_LE_COFF=.././ >> ./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_MEDIAN_3X3_16_66_LE_COFF_SRCIMG_MEDIAN_3X3_16=../../ >> ./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_MEDIAN_3X3_16_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_MEDIAN_3X3_16_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_COFF/Release/IMG_median_3x3_16_66_LE_COFF.out: ./src/IMG_median_3x3_16/IMG_median_3x3_16.h
./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_COFF/Release/IMG_median_3x3_16_66_LE_COFF.out: ./src/IMG_median_3x3_16/IMG_median_3x3_16_cn.c
./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_COFF/Release/IMG_median_3x3_16_66_LE_COFF.out: ./src/IMG_median_3x3_16/IMG_median_3x3_16_cn.h
./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_COFF/Release/IMG_median_3x3_16_66_LE_COFF.out: ./src/IMG_median_3x3_16/IMG_median_3x3_16_d.c
./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_COFF/Release/IMG_median_3x3_16_66_LE_COFF.out: ./src/IMG_median_3x3_16/IMG_median_3x3_16_idat.c
./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_COFF/Release/IMG_median_3x3_16_66_LE_COFF.out: ./src/IMG_median_3x3_16/IMG_median_3x3_16_odat.c
./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_COFF/Release/IMG_median_3x3_16_66_LE_COFF.out: ./src/IMG_median_3x3_16//c66/IMG_median_3x3_16.h
./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_COFF/Release/IMG_median_3x3_16_66_LE_COFF.out: ./src/IMG_median_3x3_16//c66/IMG_median_3x3_16.sa
./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_COFF/Release/IMG_median_3x3_16_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_COFF/Release/IMG_median_3x3_16_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_COFF/Release/IMG_median_3x3_16_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_COFF/Release/IMG_median_3x3_16_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_COFF/Release/IMG_median_3x3_16_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_COFF/Release/IMG_median_3x3_16_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_COFF/Release/IMG_median_3x3_16_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_COFF/Release/IMG_median_3x3_16_66_LE_COFF.out: ./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_COFF/.project
	-@ echo Importing Project IMG_median_3x3_16_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_median_3x3_16_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_median_3x3_16/c66/IMG_median_3x3_16_66_LE_COFF"
	-@ echo Building Project IMG_median_3x3_16_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_median_3x3_16_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_median_3x3_16_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_COFF/.settings"

	-@ echo Project IMG_median_3x3_16_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_median_3x3_16_66_LE_ELF

#############################################################

all: ./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_ELF/Release/IMG_median_3x3_16_66_LE_ELF.out

./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_median_3x3_16_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_16_66_LE_ELF_SRCIMG_MEDIAN_3X3_16/IMG_median_3x3_16_cn.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_16_66_LE_ELF_SRCIMG_MEDIAN_3X3_16/IMG_median_3x3_16_d.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_16_66_LE_ELF_SRCIMG_MEDIAN_3X3_16/IMG_median_3x3_16_idat.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_16_66_LE_ELF_SRCIMG_MEDIAN_3X3_16/IMG_median_3x3_16_odat.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_16_66_LE_ELF/IMG_median_3x3_16.sa -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_16_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_16_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_16_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_16_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_MEDIAN_3X3_16_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_median_3x3_16/c66" -ccs.definePathVariable EXT_ROOT__IMG_MEDIAN_3X3_16_66_LE_ELF_SRCIMG_MEDIAN_3X3_16 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_median_3x3_16" -ccs.definePathVariable EXT_ROOT__IMG_MEDIAN_3X3_16_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_MEDIAN_3X3_16_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_median_3x3_16.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_MEDIAN_3X3_16_66_LE_ELF=.././ >> ./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_MEDIAN_3X3_16_66_LE_ELF_SRCIMG_MEDIAN_3X3_16=../../ >> ./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_MEDIAN_3X3_16_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_MEDIAN_3X3_16_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_ELF/Release/IMG_median_3x3_16_66_LE_ELF.out: ./src/IMG_median_3x3_16/IMG_median_3x3_16.h
./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_ELF/Release/IMG_median_3x3_16_66_LE_ELF.out: ./src/IMG_median_3x3_16/IMG_median_3x3_16_cn.c
./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_ELF/Release/IMG_median_3x3_16_66_LE_ELF.out: ./src/IMG_median_3x3_16/IMG_median_3x3_16_cn.h
./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_ELF/Release/IMG_median_3x3_16_66_LE_ELF.out: ./src/IMG_median_3x3_16/IMG_median_3x3_16_d.c
./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_ELF/Release/IMG_median_3x3_16_66_LE_ELF.out: ./src/IMG_median_3x3_16/IMG_median_3x3_16_idat.c
./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_ELF/Release/IMG_median_3x3_16_66_LE_ELF.out: ./src/IMG_median_3x3_16/IMG_median_3x3_16_odat.c
./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_ELF/Release/IMG_median_3x3_16_66_LE_ELF.out: ./src/IMG_median_3x3_16//c66/IMG_median_3x3_16.h
./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_ELF/Release/IMG_median_3x3_16_66_LE_ELF.out: ./src/IMG_median_3x3_16//c66/IMG_median_3x3_16.sa
./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_ELF/Release/IMG_median_3x3_16_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_ELF/Release/IMG_median_3x3_16_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_ELF/Release/IMG_median_3x3_16_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_ELF/Release/IMG_median_3x3_16_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_ELF/Release/IMG_median_3x3_16_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_ELF/Release/IMG_median_3x3_16_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_ELF/Release/IMG_median_3x3_16_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_ELF/Release/IMG_median_3x3_16_66_LE_ELF.out: ./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_ELF/.project
	-@ echo Importing Project IMG_median_3x3_16_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_median_3x3_16_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_median_3x3_16/c66/IMG_median_3x3_16_66_LE_ELF"
	-@ echo Building Project IMG_median_3x3_16_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_median_3x3_16_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_median_3x3_16_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_ELF/.settings"

	-@ echo Project IMG_median_3x3_16_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_median_3x3_16//c66//IMG_median_3x3_16_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_median_3x3_8_66_LE_COFF

#############################################################

all: ./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_COFF/Release/IMG_median_3x3_8_66_LE_COFF.out

./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_median_3x3_8_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_8_66_LE_COFF_SRCIMG_MEDIAN_3X3_8/IMG_median_3x3_8_cn.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_8_66_LE_COFF_SRCIMG_MEDIAN_3X3_8/IMG_median_3x3_8_d.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_8_66_LE_COFF_SRCIMG_MEDIAN_3X3_8/IMG_median_3x3_8_idat.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_8_66_LE_COFF_SRCIMG_MEDIAN_3X3_8/IMG_median_3x3_8_odat.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_8_66_LE_COFF/IMG_median_3x3_8.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_8_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_8_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_8_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_8_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_MEDIAN_3X3_8_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_median_3x3_8/c66" -ccs.definePathVariable EXT_ROOT__IMG_MEDIAN_3X3_8_66_LE_COFF_SRCIMG_MEDIAN_3X3_8 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_median_3x3_8" -ccs.definePathVariable EXT_ROOT__IMG_MEDIAN_3X3_8_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_MEDIAN_3X3_8_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_median_3x3_8.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_MEDIAN_3X3_8_66_LE_COFF=.././ >> ./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_MEDIAN_3X3_8_66_LE_COFF_SRCIMG_MEDIAN_3X3_8=../../ >> ./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_MEDIAN_3X3_8_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_MEDIAN_3X3_8_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_COFF/Release/IMG_median_3x3_8_66_LE_COFF.out: ./src/IMG_median_3x3_8/IMG_median_3x3_8.h
./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_COFF/Release/IMG_median_3x3_8_66_LE_COFF.out: ./src/IMG_median_3x3_8/IMG_median_3x3_8_cn.c
./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_COFF/Release/IMG_median_3x3_8_66_LE_COFF.out: ./src/IMG_median_3x3_8/IMG_median_3x3_8_cn.h
./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_COFF/Release/IMG_median_3x3_8_66_LE_COFF.out: ./src/IMG_median_3x3_8/IMG_median_3x3_8_d.c
./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_COFF/Release/IMG_median_3x3_8_66_LE_COFF.out: ./src/IMG_median_3x3_8/IMG_median_3x3_8_idat.c
./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_COFF/Release/IMG_median_3x3_8_66_LE_COFF.out: ./src/IMG_median_3x3_8/IMG_median_3x3_8_odat.c
./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_COFF/Release/IMG_median_3x3_8_66_LE_COFF.out: ./src/IMG_median_3x3_8//c66/IMG_median_3x3_8.c
./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_COFF/Release/IMG_median_3x3_8_66_LE_COFF.out: ./src/IMG_median_3x3_8//c66/IMG_median_3x3_8.h
./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_COFF/Release/IMG_median_3x3_8_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_COFF/Release/IMG_median_3x3_8_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_COFF/Release/IMG_median_3x3_8_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_COFF/Release/IMG_median_3x3_8_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_COFF/Release/IMG_median_3x3_8_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_COFF/Release/IMG_median_3x3_8_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_COFF/Release/IMG_median_3x3_8_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_COFF/Release/IMG_median_3x3_8_66_LE_COFF.out: ./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_COFF/.project
	-@ echo Importing Project IMG_median_3x3_8_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_median_3x3_8_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_median_3x3_8/c66/IMG_median_3x3_8_66_LE_COFF"
	-@ echo Building Project IMG_median_3x3_8_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_median_3x3_8_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_median_3x3_8_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_COFF/.settings"

	-@ echo Project IMG_median_3x3_8_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_median_3x3_8_66_LE_ELF

#############################################################

all: ./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_ELF/Release/IMG_median_3x3_8_66_LE_ELF.out

./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_median_3x3_8_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_8_66_LE_ELF_SRCIMG_MEDIAN_3X3_8/IMG_median_3x3_8_cn.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_8_66_LE_ELF_SRCIMG_MEDIAN_3X3_8/IMG_median_3x3_8_d.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_8_66_LE_ELF_SRCIMG_MEDIAN_3X3_8/IMG_median_3x3_8_idat.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_8_66_LE_ELF_SRCIMG_MEDIAN_3X3_8/IMG_median_3x3_8_odat.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_8_66_LE_ELF/IMG_median_3x3_8.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_8_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_8_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_8_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_MEDIAN_3X3_8_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_MEDIAN_3X3_8_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_median_3x3_8/c66" -ccs.definePathVariable EXT_ROOT__IMG_MEDIAN_3X3_8_66_LE_ELF_SRCIMG_MEDIAN_3X3_8 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_median_3x3_8" -ccs.definePathVariable EXT_ROOT__IMG_MEDIAN_3X3_8_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_MEDIAN_3X3_8_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_median_3x3_8.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_MEDIAN_3X3_8_66_LE_ELF=.././ >> ./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_MEDIAN_3X3_8_66_LE_ELF_SRCIMG_MEDIAN_3X3_8=../../ >> ./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_MEDIAN_3X3_8_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_MEDIAN_3X3_8_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_ELF/Release/IMG_median_3x3_8_66_LE_ELF.out: ./src/IMG_median_3x3_8/IMG_median_3x3_8.h
./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_ELF/Release/IMG_median_3x3_8_66_LE_ELF.out: ./src/IMG_median_3x3_8/IMG_median_3x3_8_cn.c
./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_ELF/Release/IMG_median_3x3_8_66_LE_ELF.out: ./src/IMG_median_3x3_8/IMG_median_3x3_8_cn.h
./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_ELF/Release/IMG_median_3x3_8_66_LE_ELF.out: ./src/IMG_median_3x3_8/IMG_median_3x3_8_d.c
./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_ELF/Release/IMG_median_3x3_8_66_LE_ELF.out: ./src/IMG_median_3x3_8/IMG_median_3x3_8_idat.c
./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_ELF/Release/IMG_median_3x3_8_66_LE_ELF.out: ./src/IMG_median_3x3_8/IMG_median_3x3_8_odat.c
./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_ELF/Release/IMG_median_3x3_8_66_LE_ELF.out: ./src/IMG_median_3x3_8//c66/IMG_median_3x3_8.c
./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_ELF/Release/IMG_median_3x3_8_66_LE_ELF.out: ./src/IMG_median_3x3_8//c66/IMG_median_3x3_8.h
./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_ELF/Release/IMG_median_3x3_8_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_ELF/Release/IMG_median_3x3_8_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_ELF/Release/IMG_median_3x3_8_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_ELF/Release/IMG_median_3x3_8_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_ELF/Release/IMG_median_3x3_8_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_ELF/Release/IMG_median_3x3_8_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_ELF/Release/IMG_median_3x3_8_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_ELF/Release/IMG_median_3x3_8_66_LE_ELF.out: ./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_ELF/.project
	-@ echo Importing Project IMG_median_3x3_8_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_median_3x3_8_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_median_3x3_8/c66/IMG_median_3x3_8_66_LE_ELF"
	-@ echo Building Project IMG_median_3x3_8_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_median_3x3_8_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_median_3x3_8_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_ELF/.settings"

	-@ echo Project IMG_median_3x3_8_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_median_3x3_8//c66//IMG_median_3x3_8_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_perimeter_16_66_LE_COFF

#############################################################

all: ./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_COFF/Release/IMG_perimeter_16_66_LE_COFF.out

./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_perimeter_16_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_PERIMETER_16_66_LE_COFF_SRCIMG_PERIMETER_16/IMG_perimeter_16_cn.c -ccs.linkFile EXT_ROOT__IMG_PERIMETER_16_66_LE_COFF_SRCIMG_PERIMETER_16/IMG_perimeter_16_d.c -ccs.linkFile EXT_ROOT__IMG_PERIMETER_16_66_LE_COFF_SRCIMG_PERIMETER_16/IMG_perimeter_16_idat.c -ccs.linkFile EXT_ROOT__IMG_PERIMETER_16_66_LE_COFF_SRCIMG_PERIMETER_16/IMG_perimeter_16_odat.c -ccs.linkFile EXT_ROOT__IMG_PERIMETER_16_66_LE_COFF/IMG_perimeter_16.c -ccs.linkFile EXT_ROOT__IMG_PERIMETER_16_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_PERIMETER_16_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_PERIMETER_16_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_PERIMETER_16_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_PERIMETER_16_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_perimeter_16/c66" -ccs.definePathVariable EXT_ROOT__IMG_PERIMETER_16_66_LE_COFF_SRCIMG_PERIMETER_16 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_perimeter_16" -ccs.definePathVariable EXT_ROOT__IMG_PERIMETER_16_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_PERIMETER_16_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_perimeter_16.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_PERIMETER_16_66_LE_COFF=.././ >> ./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_PERIMETER_16_66_LE_COFF_SRCIMG_PERIMETER_16=../../ >> ./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_PERIMETER_16_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_PERIMETER_16_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_COFF/Release/IMG_perimeter_16_66_LE_COFF.out: ./src/IMG_perimeter_16/IMG_perimeter_16.h
./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_COFF/Release/IMG_perimeter_16_66_LE_COFF.out: ./src/IMG_perimeter_16/IMG_perimeter_16_cn.c
./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_COFF/Release/IMG_perimeter_16_66_LE_COFF.out: ./src/IMG_perimeter_16/IMG_perimeter_16_cn.h
./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_COFF/Release/IMG_perimeter_16_66_LE_COFF.out: ./src/IMG_perimeter_16/IMG_perimeter_16_d.c
./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_COFF/Release/IMG_perimeter_16_66_LE_COFF.out: ./src/IMG_perimeter_16/IMG_perimeter_16_idat.c
./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_COFF/Release/IMG_perimeter_16_66_LE_COFF.out: ./src/IMG_perimeter_16/IMG_perimeter_16_odat.c
./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_COFF/Release/IMG_perimeter_16_66_LE_COFF.out: ./src/IMG_perimeter_16//c66/IMG_perimeter_16.c
./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_COFF/Release/IMG_perimeter_16_66_LE_COFF.out: ./src/IMG_perimeter_16//c66/IMG_perimeter_16.h
./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_COFF/Release/IMG_perimeter_16_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_COFF/Release/IMG_perimeter_16_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_COFF/Release/IMG_perimeter_16_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_COFF/Release/IMG_perimeter_16_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_COFF/Release/IMG_perimeter_16_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_COFF/Release/IMG_perimeter_16_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_COFF/Release/IMG_perimeter_16_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_COFF/Release/IMG_perimeter_16_66_LE_COFF.out: ./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_COFF/.project
	-@ echo Importing Project IMG_perimeter_16_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_perimeter_16_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_perimeter_16/c66/IMG_perimeter_16_66_LE_COFF"
	-@ echo Building Project IMG_perimeter_16_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_perimeter_16_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_perimeter_16_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_COFF/.settings"

	-@ echo Project IMG_perimeter_16_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_perimeter_16_66_LE_ELF

#############################################################

all: ./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_ELF/Release/IMG_perimeter_16_66_LE_ELF.out

./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_perimeter_16_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_PERIMETER_16_66_LE_ELF_SRCIMG_PERIMETER_16/IMG_perimeter_16_cn.c -ccs.linkFile EXT_ROOT__IMG_PERIMETER_16_66_LE_ELF_SRCIMG_PERIMETER_16/IMG_perimeter_16_d.c -ccs.linkFile EXT_ROOT__IMG_PERIMETER_16_66_LE_ELF_SRCIMG_PERIMETER_16/IMG_perimeter_16_idat.c -ccs.linkFile EXT_ROOT__IMG_PERIMETER_16_66_LE_ELF_SRCIMG_PERIMETER_16/IMG_perimeter_16_odat.c -ccs.linkFile EXT_ROOT__IMG_PERIMETER_16_66_LE_ELF/IMG_perimeter_16.c -ccs.linkFile EXT_ROOT__IMG_PERIMETER_16_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_PERIMETER_16_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_PERIMETER_16_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_PERIMETER_16_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_PERIMETER_16_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_perimeter_16/c66" -ccs.definePathVariable EXT_ROOT__IMG_PERIMETER_16_66_LE_ELF_SRCIMG_PERIMETER_16 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_perimeter_16" -ccs.definePathVariable EXT_ROOT__IMG_PERIMETER_16_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_PERIMETER_16_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_perimeter_16.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_PERIMETER_16_66_LE_ELF=.././ >> ./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_PERIMETER_16_66_LE_ELF_SRCIMG_PERIMETER_16=../../ >> ./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_PERIMETER_16_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_PERIMETER_16_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_ELF/Release/IMG_perimeter_16_66_LE_ELF.out: ./src/IMG_perimeter_16/IMG_perimeter_16.h
./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_ELF/Release/IMG_perimeter_16_66_LE_ELF.out: ./src/IMG_perimeter_16/IMG_perimeter_16_cn.c
./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_ELF/Release/IMG_perimeter_16_66_LE_ELF.out: ./src/IMG_perimeter_16/IMG_perimeter_16_cn.h
./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_ELF/Release/IMG_perimeter_16_66_LE_ELF.out: ./src/IMG_perimeter_16/IMG_perimeter_16_d.c
./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_ELF/Release/IMG_perimeter_16_66_LE_ELF.out: ./src/IMG_perimeter_16/IMG_perimeter_16_idat.c
./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_ELF/Release/IMG_perimeter_16_66_LE_ELF.out: ./src/IMG_perimeter_16/IMG_perimeter_16_odat.c
./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_ELF/Release/IMG_perimeter_16_66_LE_ELF.out: ./src/IMG_perimeter_16//c66/IMG_perimeter_16.c
./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_ELF/Release/IMG_perimeter_16_66_LE_ELF.out: ./src/IMG_perimeter_16//c66/IMG_perimeter_16.h
./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_ELF/Release/IMG_perimeter_16_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_ELF/Release/IMG_perimeter_16_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_ELF/Release/IMG_perimeter_16_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_ELF/Release/IMG_perimeter_16_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_ELF/Release/IMG_perimeter_16_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_ELF/Release/IMG_perimeter_16_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_ELF/Release/IMG_perimeter_16_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_ELF/Release/IMG_perimeter_16_66_LE_ELF.out: ./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_ELF/.project
	-@ echo Importing Project IMG_perimeter_16_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_perimeter_16_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_perimeter_16/c66/IMG_perimeter_16_66_LE_ELF"
	-@ echo Building Project IMG_perimeter_16_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_perimeter_16_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_perimeter_16_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_ELF/.settings"

	-@ echo Project IMG_perimeter_16_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_perimeter_16//c66//IMG_perimeter_16_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_perimeter_8_66_LE_COFF

#############################################################

all: ./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_COFF/Release/IMG_perimeter_8_66_LE_COFF.out

./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_perimeter_8_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_PERIMETER_8_66_LE_COFF_SRCIMG_PERIMETER_8/IMG_perimeter_8_cn.c -ccs.linkFile EXT_ROOT__IMG_PERIMETER_8_66_LE_COFF_SRCIMG_PERIMETER_8/IMG_perimeter_8_d.c -ccs.linkFile EXT_ROOT__IMG_PERIMETER_8_66_LE_COFF_SRCIMG_PERIMETER_8/IMG_perimeter_8_idat.c -ccs.linkFile EXT_ROOT__IMG_PERIMETER_8_66_LE_COFF_SRCIMG_PERIMETER_8/IMG_perimeter_8_odat.c -ccs.linkFile EXT_ROOT__IMG_PERIMETER_8_66_LE_COFF/IMG_perimeter_8.c -ccs.linkFile EXT_ROOT__IMG_PERIMETER_8_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_PERIMETER_8_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_PERIMETER_8_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_PERIMETER_8_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_PERIMETER_8_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_perimeter_8/c66" -ccs.definePathVariable EXT_ROOT__IMG_PERIMETER_8_66_LE_COFF_SRCIMG_PERIMETER_8 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_perimeter_8" -ccs.definePathVariable EXT_ROOT__IMG_PERIMETER_8_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_PERIMETER_8_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_perimeter_8.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_PERIMETER_8_66_LE_COFF=.././ >> ./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_PERIMETER_8_66_LE_COFF_SRCIMG_PERIMETER_8=../../ >> ./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_PERIMETER_8_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_PERIMETER_8_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_COFF/Release/IMG_perimeter_8_66_LE_COFF.out: ./src/IMG_perimeter_8/IMG_perimeter_8.h
./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_COFF/Release/IMG_perimeter_8_66_LE_COFF.out: ./src/IMG_perimeter_8/IMG_perimeter_8_cn.c
./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_COFF/Release/IMG_perimeter_8_66_LE_COFF.out: ./src/IMG_perimeter_8/IMG_perimeter_8_cn.h
./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_COFF/Release/IMG_perimeter_8_66_LE_COFF.out: ./src/IMG_perimeter_8/IMG_perimeter_8_d.c
./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_COFF/Release/IMG_perimeter_8_66_LE_COFF.out: ./src/IMG_perimeter_8/IMG_perimeter_8_idat.c
./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_COFF/Release/IMG_perimeter_8_66_LE_COFF.out: ./src/IMG_perimeter_8/IMG_perimeter_8_odat.c
./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_COFF/Release/IMG_perimeter_8_66_LE_COFF.out: ./src/IMG_perimeter_8//c66/IMG_perimeter_8.c
./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_COFF/Release/IMG_perimeter_8_66_LE_COFF.out: ./src/IMG_perimeter_8//c66/IMG_perimeter_8.h
./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_COFF/Release/IMG_perimeter_8_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_COFF/Release/IMG_perimeter_8_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_COFF/Release/IMG_perimeter_8_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_COFF/Release/IMG_perimeter_8_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_COFF/Release/IMG_perimeter_8_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_COFF/Release/IMG_perimeter_8_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_COFF/Release/IMG_perimeter_8_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_COFF/Release/IMG_perimeter_8_66_LE_COFF.out: ./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_COFF/.project
	-@ echo Importing Project IMG_perimeter_8_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_perimeter_8_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_perimeter_8/c66/IMG_perimeter_8_66_LE_COFF"
	-@ echo Building Project IMG_perimeter_8_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_perimeter_8_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_perimeter_8_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_COFF/.settings"

	-@ echo Project IMG_perimeter_8_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_perimeter_8_66_LE_ELF

#############################################################

all: ./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_ELF/Release/IMG_perimeter_8_66_LE_ELF.out

./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_perimeter_8_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_PERIMETER_8_66_LE_ELF_SRCIMG_PERIMETER_8/IMG_perimeter_8_cn.c -ccs.linkFile EXT_ROOT__IMG_PERIMETER_8_66_LE_ELF_SRCIMG_PERIMETER_8/IMG_perimeter_8_d.c -ccs.linkFile EXT_ROOT__IMG_PERIMETER_8_66_LE_ELF_SRCIMG_PERIMETER_8/IMG_perimeter_8_idat.c -ccs.linkFile EXT_ROOT__IMG_PERIMETER_8_66_LE_ELF_SRCIMG_PERIMETER_8/IMG_perimeter_8_odat.c -ccs.linkFile EXT_ROOT__IMG_PERIMETER_8_66_LE_ELF/IMG_perimeter_8.c -ccs.linkFile EXT_ROOT__IMG_PERIMETER_8_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_PERIMETER_8_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_PERIMETER_8_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_PERIMETER_8_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_PERIMETER_8_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_perimeter_8/c66" -ccs.definePathVariable EXT_ROOT__IMG_PERIMETER_8_66_LE_ELF_SRCIMG_PERIMETER_8 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_perimeter_8" -ccs.definePathVariable EXT_ROOT__IMG_PERIMETER_8_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_PERIMETER_8_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_perimeter_8.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_PERIMETER_8_66_LE_ELF=.././ >> ./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_PERIMETER_8_66_LE_ELF_SRCIMG_PERIMETER_8=../../ >> ./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_PERIMETER_8_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_PERIMETER_8_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_ELF/Release/IMG_perimeter_8_66_LE_ELF.out: ./src/IMG_perimeter_8/IMG_perimeter_8.h
./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_ELF/Release/IMG_perimeter_8_66_LE_ELF.out: ./src/IMG_perimeter_8/IMG_perimeter_8_cn.c
./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_ELF/Release/IMG_perimeter_8_66_LE_ELF.out: ./src/IMG_perimeter_8/IMG_perimeter_8_cn.h
./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_ELF/Release/IMG_perimeter_8_66_LE_ELF.out: ./src/IMG_perimeter_8/IMG_perimeter_8_d.c
./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_ELF/Release/IMG_perimeter_8_66_LE_ELF.out: ./src/IMG_perimeter_8/IMG_perimeter_8_idat.c
./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_ELF/Release/IMG_perimeter_8_66_LE_ELF.out: ./src/IMG_perimeter_8/IMG_perimeter_8_odat.c
./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_ELF/Release/IMG_perimeter_8_66_LE_ELF.out: ./src/IMG_perimeter_8//c66/IMG_perimeter_8.c
./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_ELF/Release/IMG_perimeter_8_66_LE_ELF.out: ./src/IMG_perimeter_8//c66/IMG_perimeter_8.h
./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_ELF/Release/IMG_perimeter_8_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_ELF/Release/IMG_perimeter_8_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_ELF/Release/IMG_perimeter_8_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_ELF/Release/IMG_perimeter_8_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_ELF/Release/IMG_perimeter_8_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_ELF/Release/IMG_perimeter_8_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_ELF/Release/IMG_perimeter_8_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_ELF/Release/IMG_perimeter_8_66_LE_ELF.out: ./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_ELF/.project
	-@ echo Importing Project IMG_perimeter_8_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_perimeter_8_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_perimeter_8/c66/IMG_perimeter_8_66_LE_ELF"
	-@ echo Building Project IMG_perimeter_8_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_perimeter_8_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_perimeter_8_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_ELF/.settings"

	-@ echo Project IMG_perimeter_8_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_perimeter_8//c66//IMG_perimeter_8_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_pix_expand_66_LE_COFF

#############################################################

all: ./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_COFF/Release/IMG_pix_expand_66_LE_COFF.out

./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_pix_expand_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_PIX_EXPAND_66_LE_COFF_SRCIMG_PIX_EXPAND/IMG_pix_expand_cn.c -ccs.linkFile EXT_ROOT__IMG_PIX_EXPAND_66_LE_COFF_SRCIMG_PIX_EXPAND/IMG_pix_expand_d.c -ccs.linkFile EXT_ROOT__IMG_PIX_EXPAND_66_LE_COFF_SRCIMG_PIX_EXPAND/IMG_pix_expand_idat.c -ccs.linkFile EXT_ROOT__IMG_PIX_EXPAND_66_LE_COFF_SRCIMG_PIX_EXPAND/IMG_pix_expand_odat.c -ccs.linkFile EXT_ROOT__IMG_PIX_EXPAND_66_LE_COFF/IMG_pix_expand.c -ccs.linkFile EXT_ROOT__IMG_PIX_EXPAND_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_PIX_EXPAND_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_PIX_EXPAND_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_PIX_EXPAND_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_PIX_EXPAND_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_pix_expand/c66" -ccs.definePathVariable EXT_ROOT__IMG_PIX_EXPAND_66_LE_COFF_SRCIMG_PIX_EXPAND "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_pix_expand" -ccs.definePathVariable EXT_ROOT__IMG_PIX_EXPAND_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_PIX_EXPAND_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_pix_expand.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_PIX_EXPAND_66_LE_COFF=.././ >> ./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_PIX_EXPAND_66_LE_COFF_SRCIMG_PIX_EXPAND=../../ >> ./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_PIX_EXPAND_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_PIX_EXPAND_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_COFF/Release/IMG_pix_expand_66_LE_COFF.out: ./src/IMG_pix_expand/IMG_pix_expand.h
./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_COFF/Release/IMG_pix_expand_66_LE_COFF.out: ./src/IMG_pix_expand/IMG_pix_expand_cn.c
./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_COFF/Release/IMG_pix_expand_66_LE_COFF.out: ./src/IMG_pix_expand/IMG_pix_expand_cn.h
./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_COFF/Release/IMG_pix_expand_66_LE_COFF.out: ./src/IMG_pix_expand/IMG_pix_expand_d.c
./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_COFF/Release/IMG_pix_expand_66_LE_COFF.out: ./src/IMG_pix_expand/IMG_pix_expand_idat.c
./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_COFF/Release/IMG_pix_expand_66_LE_COFF.out: ./src/IMG_pix_expand/IMG_pix_expand_odat.c
./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_COFF/Release/IMG_pix_expand_66_LE_COFF.out: ./src/IMG_pix_expand//c66/IMG_pix_expand.c
./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_COFF/Release/IMG_pix_expand_66_LE_COFF.out: ./src/IMG_pix_expand//c66/IMG_pix_expand.h
./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_COFF/Release/IMG_pix_expand_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_COFF/Release/IMG_pix_expand_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_COFF/Release/IMG_pix_expand_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_COFF/Release/IMG_pix_expand_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_COFF/Release/IMG_pix_expand_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_COFF/Release/IMG_pix_expand_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_COFF/Release/IMG_pix_expand_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_COFF/Release/IMG_pix_expand_66_LE_COFF.out: ./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_COFF/.project
	-@ echo Importing Project IMG_pix_expand_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_pix_expand_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_pix_expand/c66/IMG_pix_expand_66_LE_COFF"
	-@ echo Building Project IMG_pix_expand_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_pix_expand_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_pix_expand_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_COFF/.settings"

	-@ echo Project IMG_pix_expand_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_pix_expand_66_LE_ELF

#############################################################

all: ./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_ELF/Release/IMG_pix_expand_66_LE_ELF.out

./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_pix_expand_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_PIX_EXPAND_66_LE_ELF_SRCIMG_PIX_EXPAND/IMG_pix_expand_cn.c -ccs.linkFile EXT_ROOT__IMG_PIX_EXPAND_66_LE_ELF_SRCIMG_PIX_EXPAND/IMG_pix_expand_d.c -ccs.linkFile EXT_ROOT__IMG_PIX_EXPAND_66_LE_ELF_SRCIMG_PIX_EXPAND/IMG_pix_expand_idat.c -ccs.linkFile EXT_ROOT__IMG_PIX_EXPAND_66_LE_ELF_SRCIMG_PIX_EXPAND/IMG_pix_expand_odat.c -ccs.linkFile EXT_ROOT__IMG_PIX_EXPAND_66_LE_ELF/IMG_pix_expand.c -ccs.linkFile EXT_ROOT__IMG_PIX_EXPAND_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_PIX_EXPAND_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_PIX_EXPAND_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_PIX_EXPAND_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_PIX_EXPAND_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_pix_expand/c66" -ccs.definePathVariable EXT_ROOT__IMG_PIX_EXPAND_66_LE_ELF_SRCIMG_PIX_EXPAND "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_pix_expand" -ccs.definePathVariable EXT_ROOT__IMG_PIX_EXPAND_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_PIX_EXPAND_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_pix_expand.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_PIX_EXPAND_66_LE_ELF=.././ >> ./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_PIX_EXPAND_66_LE_ELF_SRCIMG_PIX_EXPAND=../../ >> ./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_PIX_EXPAND_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_PIX_EXPAND_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_ELF/Release/IMG_pix_expand_66_LE_ELF.out: ./src/IMG_pix_expand/IMG_pix_expand.h
./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_ELF/Release/IMG_pix_expand_66_LE_ELF.out: ./src/IMG_pix_expand/IMG_pix_expand_cn.c
./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_ELF/Release/IMG_pix_expand_66_LE_ELF.out: ./src/IMG_pix_expand/IMG_pix_expand_cn.h
./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_ELF/Release/IMG_pix_expand_66_LE_ELF.out: ./src/IMG_pix_expand/IMG_pix_expand_d.c
./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_ELF/Release/IMG_pix_expand_66_LE_ELF.out: ./src/IMG_pix_expand/IMG_pix_expand_idat.c
./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_ELF/Release/IMG_pix_expand_66_LE_ELF.out: ./src/IMG_pix_expand/IMG_pix_expand_odat.c
./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_ELF/Release/IMG_pix_expand_66_LE_ELF.out: ./src/IMG_pix_expand//c66/IMG_pix_expand.c
./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_ELF/Release/IMG_pix_expand_66_LE_ELF.out: ./src/IMG_pix_expand//c66/IMG_pix_expand.h
./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_ELF/Release/IMG_pix_expand_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_ELF/Release/IMG_pix_expand_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_ELF/Release/IMG_pix_expand_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_ELF/Release/IMG_pix_expand_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_ELF/Release/IMG_pix_expand_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_ELF/Release/IMG_pix_expand_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_ELF/Release/IMG_pix_expand_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_ELF/Release/IMG_pix_expand_66_LE_ELF.out: ./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_ELF/.project
	-@ echo Importing Project IMG_pix_expand_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_pix_expand_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_pix_expand/c66/IMG_pix_expand_66_LE_ELF"
	-@ echo Building Project IMG_pix_expand_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_pix_expand_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_pix_expand_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_ELF/.settings"

	-@ echo Project IMG_pix_expand_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_pix_expand//c66//IMG_pix_expand_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_pix_sat_66_LE_COFF

#############################################################

all: ./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_COFF/Release/IMG_pix_sat_66_LE_COFF.out

./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_pix_sat_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_PIX_SAT_66_LE_COFF_SRCIMG_PIX_SAT/IMG_pix_sat_cn.c -ccs.linkFile EXT_ROOT__IMG_PIX_SAT_66_LE_COFF_SRCIMG_PIX_SAT/IMG_pix_sat_d.c -ccs.linkFile EXT_ROOT__IMG_PIX_SAT_66_LE_COFF_SRCIMG_PIX_SAT/IMG_pix_sat_idat.c -ccs.linkFile EXT_ROOT__IMG_PIX_SAT_66_LE_COFF_SRCIMG_PIX_SAT/IMG_pix_sat_odat.c -ccs.linkFile EXT_ROOT__IMG_PIX_SAT_66_LE_COFF/IMG_pix_sat.c -ccs.linkFile EXT_ROOT__IMG_PIX_SAT_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_PIX_SAT_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_PIX_SAT_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_PIX_SAT_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_PIX_SAT_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_pix_sat/c66" -ccs.definePathVariable EXT_ROOT__IMG_PIX_SAT_66_LE_COFF_SRCIMG_PIX_SAT "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_pix_sat" -ccs.definePathVariable EXT_ROOT__IMG_PIX_SAT_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_PIX_SAT_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_pix_sat.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_PIX_SAT_66_LE_COFF=.././ >> ./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_PIX_SAT_66_LE_COFF_SRCIMG_PIX_SAT=../../ >> ./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_PIX_SAT_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_PIX_SAT_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_COFF/Release/IMG_pix_sat_66_LE_COFF.out: ./src/IMG_pix_sat/IMG_pix_sat.h
./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_COFF/Release/IMG_pix_sat_66_LE_COFF.out: ./src/IMG_pix_sat/IMG_pix_sat_cn.c
./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_COFF/Release/IMG_pix_sat_66_LE_COFF.out: ./src/IMG_pix_sat/IMG_pix_sat_cn.h
./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_COFF/Release/IMG_pix_sat_66_LE_COFF.out: ./src/IMG_pix_sat/IMG_pix_sat_d.c
./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_COFF/Release/IMG_pix_sat_66_LE_COFF.out: ./src/IMG_pix_sat/IMG_pix_sat_idat.c
./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_COFF/Release/IMG_pix_sat_66_LE_COFF.out: ./src/IMG_pix_sat/IMG_pix_sat_odat.c
./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_COFF/Release/IMG_pix_sat_66_LE_COFF.out: ./src/IMG_pix_sat//c66/IMG_pix_sat.c
./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_COFF/Release/IMG_pix_sat_66_LE_COFF.out: ./src/IMG_pix_sat//c66/IMG_pix_sat.h
./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_COFF/Release/IMG_pix_sat_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_COFF/Release/IMG_pix_sat_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_COFF/Release/IMG_pix_sat_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_COFF/Release/IMG_pix_sat_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_COFF/Release/IMG_pix_sat_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_COFF/Release/IMG_pix_sat_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_COFF/Release/IMG_pix_sat_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_COFF/Release/IMG_pix_sat_66_LE_COFF.out: ./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_COFF/.project
	-@ echo Importing Project IMG_pix_sat_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_pix_sat_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_pix_sat/c66/IMG_pix_sat_66_LE_COFF"
	-@ echo Building Project IMG_pix_sat_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_pix_sat_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_pix_sat_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_COFF/.settings"

	-@ echo Project IMG_pix_sat_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_pix_sat_66_LE_ELF

#############################################################

all: ./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_ELF/Release/IMG_pix_sat_66_LE_ELF.out

./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_pix_sat_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_PIX_SAT_66_LE_ELF_SRCIMG_PIX_SAT/IMG_pix_sat_cn.c -ccs.linkFile EXT_ROOT__IMG_PIX_SAT_66_LE_ELF_SRCIMG_PIX_SAT/IMG_pix_sat_d.c -ccs.linkFile EXT_ROOT__IMG_PIX_SAT_66_LE_ELF_SRCIMG_PIX_SAT/IMG_pix_sat_idat.c -ccs.linkFile EXT_ROOT__IMG_PIX_SAT_66_LE_ELF_SRCIMG_PIX_SAT/IMG_pix_sat_odat.c -ccs.linkFile EXT_ROOT__IMG_PIX_SAT_66_LE_ELF/IMG_pix_sat.c -ccs.linkFile EXT_ROOT__IMG_PIX_SAT_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_PIX_SAT_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_PIX_SAT_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_PIX_SAT_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_PIX_SAT_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_pix_sat/c66" -ccs.definePathVariable EXT_ROOT__IMG_PIX_SAT_66_LE_ELF_SRCIMG_PIX_SAT "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_pix_sat" -ccs.definePathVariable EXT_ROOT__IMG_PIX_SAT_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_PIX_SAT_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_pix_sat.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_PIX_SAT_66_LE_ELF=.././ >> ./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_PIX_SAT_66_LE_ELF_SRCIMG_PIX_SAT=../../ >> ./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_PIX_SAT_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_PIX_SAT_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_ELF/Release/IMG_pix_sat_66_LE_ELF.out: ./src/IMG_pix_sat/IMG_pix_sat.h
./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_ELF/Release/IMG_pix_sat_66_LE_ELF.out: ./src/IMG_pix_sat/IMG_pix_sat_cn.c
./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_ELF/Release/IMG_pix_sat_66_LE_ELF.out: ./src/IMG_pix_sat/IMG_pix_sat_cn.h
./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_ELF/Release/IMG_pix_sat_66_LE_ELF.out: ./src/IMG_pix_sat/IMG_pix_sat_d.c
./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_ELF/Release/IMG_pix_sat_66_LE_ELF.out: ./src/IMG_pix_sat/IMG_pix_sat_idat.c
./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_ELF/Release/IMG_pix_sat_66_LE_ELF.out: ./src/IMG_pix_sat/IMG_pix_sat_odat.c
./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_ELF/Release/IMG_pix_sat_66_LE_ELF.out: ./src/IMG_pix_sat//c66/IMG_pix_sat.c
./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_ELF/Release/IMG_pix_sat_66_LE_ELF.out: ./src/IMG_pix_sat//c66/IMG_pix_sat.h
./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_ELF/Release/IMG_pix_sat_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_ELF/Release/IMG_pix_sat_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_ELF/Release/IMG_pix_sat_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_ELF/Release/IMG_pix_sat_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_ELF/Release/IMG_pix_sat_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_ELF/Release/IMG_pix_sat_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_ELF/Release/IMG_pix_sat_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_ELF/Release/IMG_pix_sat_66_LE_ELF.out: ./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_ELF/.project
	-@ echo Importing Project IMG_pix_sat_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_pix_sat_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_pix_sat/c66/IMG_pix_sat_66_LE_ELF"
	-@ echo Building Project IMG_pix_sat_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_pix_sat_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_pix_sat_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_ELF/.settings"

	-@ echo Project IMG_pix_sat_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_pix_sat//c66//IMG_pix_sat_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_quantize_66_LE_COFF

#############################################################

all: ./src/IMG_quantize//c66//IMG_quantize_66_LE_COFF/Release/IMG_quantize_66_LE_COFF.out

./src/IMG_quantize//c66//IMG_quantize_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_quantize_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_QUANTIZE_66_LE_COFF_SRCIMG_QUANTIZE/IMG_quantize_cn.c -ccs.linkFile EXT_ROOT__IMG_QUANTIZE_66_LE_COFF_SRCIMG_QUANTIZE/IMG_quantize_d.c -ccs.linkFile EXT_ROOT__IMG_QUANTIZE_66_LE_COFF/IMG_quantize.s -ccs.linkFile EXT_ROOT__IMG_QUANTIZE_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_QUANTIZE_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_QUANTIZE_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_QUANTIZE_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_quantize//c66//IMG_quantize_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_QUANTIZE_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_quantize/c66" -ccs.definePathVariable EXT_ROOT__IMG_QUANTIZE_66_LE_COFF_SRCIMG_QUANTIZE "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_quantize" -ccs.definePathVariable EXT_ROOT__IMG_QUANTIZE_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_QUANTIZE_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_quantize.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_QUANTIZE_66_LE_COFF=.././ >> ./src/IMG_quantize//c66//IMG_quantize_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_QUANTIZE_66_LE_COFF_SRCIMG_QUANTIZE=../../ >> ./src/IMG_quantize//c66//IMG_quantize_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_QUANTIZE_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_quantize//c66//IMG_quantize_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_QUANTIZE_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_quantize//c66//IMG_quantize_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_quantize//c66//IMG_quantize_66_LE_COFF/Release/IMG_quantize_66_LE_COFF.out: ./src/IMG_quantize/IMG_quantize.h
./src/IMG_quantize//c66//IMG_quantize_66_LE_COFF/Release/IMG_quantize_66_LE_COFF.out: ./src/IMG_quantize/IMG_quantize_cn.c
./src/IMG_quantize//c66//IMG_quantize_66_LE_COFF/Release/IMG_quantize_66_LE_COFF.out: ./src/IMG_quantize/IMG_quantize_cn.h
./src/IMG_quantize//c66//IMG_quantize_66_LE_COFF/Release/IMG_quantize_66_LE_COFF.out: ./src/IMG_quantize/IMG_quantize_d.c
./src/IMG_quantize//c66//IMG_quantize_66_LE_COFF/Release/IMG_quantize_66_LE_COFF.out: ./src/IMG_quantize//c66/IMG_quantize.h
./src/IMG_quantize//c66//IMG_quantize_66_LE_COFF/Release/IMG_quantize_66_LE_COFF.out: ./src/IMG_quantize//c66/IMG_quantize.s
./src/IMG_quantize//c66//IMG_quantize_66_LE_COFF/Release/IMG_quantize_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_quantize//c66//IMG_quantize_66_LE_COFF/Release/IMG_quantize_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_quantize//c66//IMG_quantize_66_LE_COFF/Release/IMG_quantize_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_quantize//c66//IMG_quantize_66_LE_COFF/Release/IMG_quantize_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_quantize//c66//IMG_quantize_66_LE_COFF/Release/IMG_quantize_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_quantize//c66//IMG_quantize_66_LE_COFF/Release/IMG_quantize_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_quantize//c66//IMG_quantize_66_LE_COFF/Release/IMG_quantize_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_quantize//c66//IMG_quantize_66_LE_COFF/Release/IMG_quantize_66_LE_COFF.out: ./src/IMG_quantize//c66//IMG_quantize_66_LE_COFF/.project
	-@ echo Importing Project IMG_quantize_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_quantize_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_quantize/c66/IMG_quantize_66_LE_COFF"
	-@ echo Building Project IMG_quantize_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_quantize_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_quantize_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_quantize//c66//IMG_quantize_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_quantize//c66//IMG_quantize_66_LE_COFF/.settings"

	-@ echo Project IMG_quantize_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_quantize//c66//IMG_quantize_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_quantize_66_LE_ELF

#############################################################

all: ./src/IMG_quantize//c66//IMG_quantize_66_LE_ELF/Release/IMG_quantize_66_LE_ELF.out

./src/IMG_quantize//c66//IMG_quantize_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_quantize_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_QUANTIZE_66_LE_ELF_SRCIMG_QUANTIZE/IMG_quantize_cn.c -ccs.linkFile EXT_ROOT__IMG_QUANTIZE_66_LE_ELF_SRCIMG_QUANTIZE/IMG_quantize_d.c -ccs.linkFile EXT_ROOT__IMG_QUANTIZE_66_LE_ELF/IMG_quantize.s -ccs.linkFile EXT_ROOT__IMG_QUANTIZE_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_QUANTIZE_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_QUANTIZE_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_QUANTIZE_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_quantize//c66//IMG_quantize_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_QUANTIZE_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_quantize/c66" -ccs.definePathVariable EXT_ROOT__IMG_QUANTIZE_66_LE_ELF_SRCIMG_QUANTIZE "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_quantize" -ccs.definePathVariable EXT_ROOT__IMG_QUANTIZE_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_QUANTIZE_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_quantize.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_QUANTIZE_66_LE_ELF=.././ >> ./src/IMG_quantize//c66//IMG_quantize_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_QUANTIZE_66_LE_ELF_SRCIMG_QUANTIZE=../../ >> ./src/IMG_quantize//c66//IMG_quantize_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_QUANTIZE_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_quantize//c66//IMG_quantize_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_QUANTIZE_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_quantize//c66//IMG_quantize_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_quantize//c66//IMG_quantize_66_LE_ELF/Release/IMG_quantize_66_LE_ELF.out: ./src/IMG_quantize/IMG_quantize.h
./src/IMG_quantize//c66//IMG_quantize_66_LE_ELF/Release/IMG_quantize_66_LE_ELF.out: ./src/IMG_quantize/IMG_quantize_cn.c
./src/IMG_quantize//c66//IMG_quantize_66_LE_ELF/Release/IMG_quantize_66_LE_ELF.out: ./src/IMG_quantize/IMG_quantize_cn.h
./src/IMG_quantize//c66//IMG_quantize_66_LE_ELF/Release/IMG_quantize_66_LE_ELF.out: ./src/IMG_quantize/IMG_quantize_d.c
./src/IMG_quantize//c66//IMG_quantize_66_LE_ELF/Release/IMG_quantize_66_LE_ELF.out: ./src/IMG_quantize//c66/IMG_quantize.h
./src/IMG_quantize//c66//IMG_quantize_66_LE_ELF/Release/IMG_quantize_66_LE_ELF.out: ./src/IMG_quantize//c66/IMG_quantize.s
./src/IMG_quantize//c66//IMG_quantize_66_LE_ELF/Release/IMG_quantize_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_quantize//c66//IMG_quantize_66_LE_ELF/Release/IMG_quantize_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_quantize//c66//IMG_quantize_66_LE_ELF/Release/IMG_quantize_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_quantize//c66//IMG_quantize_66_LE_ELF/Release/IMG_quantize_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_quantize//c66//IMG_quantize_66_LE_ELF/Release/IMG_quantize_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_quantize//c66//IMG_quantize_66_LE_ELF/Release/IMG_quantize_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_quantize//c66//IMG_quantize_66_LE_ELF/Release/IMG_quantize_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_quantize//c66//IMG_quantize_66_LE_ELF/Release/IMG_quantize_66_LE_ELF.out: ./src/IMG_quantize//c66//IMG_quantize_66_LE_ELF/.project
	-@ echo Importing Project IMG_quantize_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_quantize_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_quantize/c66/IMG_quantize_66_LE_ELF"
	-@ echo Building Project IMG_quantize_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_quantize_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_quantize_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_quantize//c66//IMG_quantize_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_quantize//c66//IMG_quantize_66_LE_ELF/.settings"

	-@ echo Project IMG_quantize_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_quantize//c66//IMG_quantize_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_sad_16x16_66_LE_COFF

#############################################################

all: ./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_COFF/Release/IMG_sad_16x16_66_LE_COFF.out

./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_sad_16x16_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_SAD_16X16_66_LE_COFF_SRCIMG_SAD_16X16/IMG_sad_16x16_cn.c -ccs.linkFile EXT_ROOT__IMG_SAD_16X16_66_LE_COFF_SRCIMG_SAD_16X16/IMG_sad_16x16_d.c -ccs.linkFile EXT_ROOT__IMG_SAD_16X16_66_LE_COFF/IMG_sad_16x16.s -ccs.linkFile EXT_ROOT__IMG_SAD_16X16_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_SAD_16X16_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_SAD_16X16_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_SAD_16X16_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_SAD_16X16_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sad_16x16/c66" -ccs.definePathVariable EXT_ROOT__IMG_SAD_16X16_66_LE_COFF_SRCIMG_SAD_16X16 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sad_16x16" -ccs.definePathVariable EXT_ROOT__IMG_SAD_16X16_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_SAD_16X16_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_sad_16x16.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_SAD_16X16_66_LE_COFF=.././ >> ./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_SAD_16X16_66_LE_COFF_SRCIMG_SAD_16X16=../../ >> ./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_SAD_16X16_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_SAD_16X16_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_COFF/Release/IMG_sad_16x16_66_LE_COFF.out: ./src/IMG_sad_16x16/IMG_sad_16x16.h
./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_COFF/Release/IMG_sad_16x16_66_LE_COFF.out: ./src/IMG_sad_16x16/IMG_sad_16x16_cn.c
./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_COFF/Release/IMG_sad_16x16_66_LE_COFF.out: ./src/IMG_sad_16x16/IMG_sad_16x16_cn.h
./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_COFF/Release/IMG_sad_16x16_66_LE_COFF.out: ./src/IMG_sad_16x16/IMG_sad_16x16_d.c
./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_COFF/Release/IMG_sad_16x16_66_LE_COFF.out: ./src/IMG_sad_16x16//c66/IMG_sad_16x16.h
./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_COFF/Release/IMG_sad_16x16_66_LE_COFF.out: ./src/IMG_sad_16x16//c66/IMG_sad_16x16.s
./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_COFF/Release/IMG_sad_16x16_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_COFF/Release/IMG_sad_16x16_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_COFF/Release/IMG_sad_16x16_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_COFF/Release/IMG_sad_16x16_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_COFF/Release/IMG_sad_16x16_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_COFF/Release/IMG_sad_16x16_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_COFF/Release/IMG_sad_16x16_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_COFF/Release/IMG_sad_16x16_66_LE_COFF.out: ./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_COFF/.project
	-@ echo Importing Project IMG_sad_16x16_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_sad_16x16_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sad_16x16/c66/IMG_sad_16x16_66_LE_COFF"
	-@ echo Building Project IMG_sad_16x16_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_sad_16x16_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_sad_16x16_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_COFF/.settings"

	-@ echo Project IMG_sad_16x16_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_sad_16x16_66_LE_ELF

#############################################################

all: ./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_ELF/Release/IMG_sad_16x16_66_LE_ELF.out

./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_sad_16x16_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_SAD_16X16_66_LE_ELF_SRCIMG_SAD_16X16/IMG_sad_16x16_cn.c -ccs.linkFile EXT_ROOT__IMG_SAD_16X16_66_LE_ELF_SRCIMG_SAD_16X16/IMG_sad_16x16_d.c -ccs.linkFile EXT_ROOT__IMG_SAD_16X16_66_LE_ELF/IMG_sad_16x16.s -ccs.linkFile EXT_ROOT__IMG_SAD_16X16_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_SAD_16X16_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_SAD_16X16_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_SAD_16X16_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_SAD_16X16_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sad_16x16/c66" -ccs.definePathVariable EXT_ROOT__IMG_SAD_16X16_66_LE_ELF_SRCIMG_SAD_16X16 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sad_16x16" -ccs.definePathVariable EXT_ROOT__IMG_SAD_16X16_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_SAD_16X16_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_sad_16x16.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_SAD_16X16_66_LE_ELF=.././ >> ./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_SAD_16X16_66_LE_ELF_SRCIMG_SAD_16X16=../../ >> ./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_SAD_16X16_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_SAD_16X16_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_ELF/Release/IMG_sad_16x16_66_LE_ELF.out: ./src/IMG_sad_16x16/IMG_sad_16x16.h
./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_ELF/Release/IMG_sad_16x16_66_LE_ELF.out: ./src/IMG_sad_16x16/IMG_sad_16x16_cn.c
./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_ELF/Release/IMG_sad_16x16_66_LE_ELF.out: ./src/IMG_sad_16x16/IMG_sad_16x16_cn.h
./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_ELF/Release/IMG_sad_16x16_66_LE_ELF.out: ./src/IMG_sad_16x16/IMG_sad_16x16_d.c
./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_ELF/Release/IMG_sad_16x16_66_LE_ELF.out: ./src/IMG_sad_16x16//c66/IMG_sad_16x16.h
./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_ELF/Release/IMG_sad_16x16_66_LE_ELF.out: ./src/IMG_sad_16x16//c66/IMG_sad_16x16.s
./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_ELF/Release/IMG_sad_16x16_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_ELF/Release/IMG_sad_16x16_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_ELF/Release/IMG_sad_16x16_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_ELF/Release/IMG_sad_16x16_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_ELF/Release/IMG_sad_16x16_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_ELF/Release/IMG_sad_16x16_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_ELF/Release/IMG_sad_16x16_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_ELF/Release/IMG_sad_16x16_66_LE_ELF.out: ./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_ELF/.project
	-@ echo Importing Project IMG_sad_16x16_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_sad_16x16_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sad_16x16/c66/IMG_sad_16x16_66_LE_ELF"
	-@ echo Building Project IMG_sad_16x16_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_sad_16x16_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_sad_16x16_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_ELF/.settings"

	-@ echo Project IMG_sad_16x16_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_sad_16x16//c66//IMG_sad_16x16_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_sad_8x8_66_LE_COFF

#############################################################

all: ./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_COFF/Release/IMG_sad_8x8_66_LE_COFF.out

./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_sad_8x8_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_SAD_8X8_66_LE_COFF_SRCIMG_SAD_8X8/IMG_sad_8x8_cn.c -ccs.linkFile EXT_ROOT__IMG_SAD_8X8_66_LE_COFF_SRCIMG_SAD_8X8/IMG_sad_8x8_d.c -ccs.linkFile EXT_ROOT__IMG_SAD_8X8_66_LE_COFF/IMG_sad_8x8.s -ccs.linkFile EXT_ROOT__IMG_SAD_8X8_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_SAD_8X8_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_SAD_8X8_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_SAD_8X8_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_SAD_8X8_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sad_8x8/c66" -ccs.definePathVariable EXT_ROOT__IMG_SAD_8X8_66_LE_COFF_SRCIMG_SAD_8X8 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sad_8x8" -ccs.definePathVariable EXT_ROOT__IMG_SAD_8X8_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_SAD_8X8_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_sad_8x8.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_SAD_8X8_66_LE_COFF=.././ >> ./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_SAD_8X8_66_LE_COFF_SRCIMG_SAD_8X8=../../ >> ./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_SAD_8X8_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_SAD_8X8_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_COFF/Release/IMG_sad_8x8_66_LE_COFF.out: ./src/IMG_sad_8x8/IMG_sad_8x8.h
./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_COFF/Release/IMG_sad_8x8_66_LE_COFF.out: ./src/IMG_sad_8x8/IMG_sad_8x8_cn.c
./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_COFF/Release/IMG_sad_8x8_66_LE_COFF.out: ./src/IMG_sad_8x8/IMG_sad_8x8_cn.h
./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_COFF/Release/IMG_sad_8x8_66_LE_COFF.out: ./src/IMG_sad_8x8/IMG_sad_8x8_d.c
./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_COFF/Release/IMG_sad_8x8_66_LE_COFF.out: ./src/IMG_sad_8x8//c66/IMG_sad_8x8.h
./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_COFF/Release/IMG_sad_8x8_66_LE_COFF.out: ./src/IMG_sad_8x8//c66/IMG_sad_8x8.s
./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_COFF/Release/IMG_sad_8x8_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_COFF/Release/IMG_sad_8x8_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_COFF/Release/IMG_sad_8x8_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_COFF/Release/IMG_sad_8x8_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_COFF/Release/IMG_sad_8x8_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_COFF/Release/IMG_sad_8x8_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_COFF/Release/IMG_sad_8x8_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_COFF/Release/IMG_sad_8x8_66_LE_COFF.out: ./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_COFF/.project
	-@ echo Importing Project IMG_sad_8x8_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_sad_8x8_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sad_8x8/c66/IMG_sad_8x8_66_LE_COFF"
	-@ echo Building Project IMG_sad_8x8_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_sad_8x8_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_sad_8x8_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_COFF/.settings"

	-@ echo Project IMG_sad_8x8_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_sad_8x8_66_LE_ELF

#############################################################

all: ./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_ELF/Release/IMG_sad_8x8_66_LE_ELF.out

./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_sad_8x8_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_SAD_8X8_66_LE_ELF_SRCIMG_SAD_8X8/IMG_sad_8x8_cn.c -ccs.linkFile EXT_ROOT__IMG_SAD_8X8_66_LE_ELF_SRCIMG_SAD_8X8/IMG_sad_8x8_d.c -ccs.linkFile EXT_ROOT__IMG_SAD_8X8_66_LE_ELF/IMG_sad_8x8.s -ccs.linkFile EXT_ROOT__IMG_SAD_8X8_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_SAD_8X8_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_SAD_8X8_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_SAD_8X8_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_SAD_8X8_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sad_8x8/c66" -ccs.definePathVariable EXT_ROOT__IMG_SAD_8X8_66_LE_ELF_SRCIMG_SAD_8X8 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sad_8x8" -ccs.definePathVariable EXT_ROOT__IMG_SAD_8X8_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_SAD_8X8_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_sad_8x8.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_SAD_8X8_66_LE_ELF=.././ >> ./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_SAD_8X8_66_LE_ELF_SRCIMG_SAD_8X8=../../ >> ./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_SAD_8X8_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_SAD_8X8_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_ELF/Release/IMG_sad_8x8_66_LE_ELF.out: ./src/IMG_sad_8x8/IMG_sad_8x8.h
./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_ELF/Release/IMG_sad_8x8_66_LE_ELF.out: ./src/IMG_sad_8x8/IMG_sad_8x8_cn.c
./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_ELF/Release/IMG_sad_8x8_66_LE_ELF.out: ./src/IMG_sad_8x8/IMG_sad_8x8_cn.h
./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_ELF/Release/IMG_sad_8x8_66_LE_ELF.out: ./src/IMG_sad_8x8/IMG_sad_8x8_d.c
./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_ELF/Release/IMG_sad_8x8_66_LE_ELF.out: ./src/IMG_sad_8x8//c66/IMG_sad_8x8.h
./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_ELF/Release/IMG_sad_8x8_66_LE_ELF.out: ./src/IMG_sad_8x8//c66/IMG_sad_8x8.s
./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_ELF/Release/IMG_sad_8x8_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_ELF/Release/IMG_sad_8x8_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_ELF/Release/IMG_sad_8x8_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_ELF/Release/IMG_sad_8x8_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_ELF/Release/IMG_sad_8x8_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_ELF/Release/IMG_sad_8x8_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_ELF/Release/IMG_sad_8x8_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_ELF/Release/IMG_sad_8x8_66_LE_ELF.out: ./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_ELF/.project
	-@ echo Importing Project IMG_sad_8x8_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_sad_8x8_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sad_8x8/c66/IMG_sad_8x8_66_LE_ELF"
	-@ echo Building Project IMG_sad_8x8_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_sad_8x8_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_sad_8x8_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_ELF/.settings"

	-@ echo Project IMG_sad_8x8_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_sad_8x8//c66//IMG_sad_8x8_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_sobel_3x3_16s_66_LE_COFF

#############################################################

all: ./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_COFF/Release/IMG_sobel_3x3_16s_66_LE_COFF.out

./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_sobel_3x3_16s_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_16S_66_LE_COFF_SRCIMG_SOBEL_3X3_16S/IMG_sobel_3x3_16s_cn.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_16S_66_LE_COFF_SRCIMG_SOBEL_3X3_16S/IMG_sobel_3x3_16s_d.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_16S_66_LE_COFF_SRCIMG_SOBEL_3X3_16S/IMG_sobel_3x3_16s_idat.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_16S_66_LE_COFF_SRCIMG_SOBEL_3X3_16S/IMG_sobel_3x3_16s_odat.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_16S_66_LE_COFF/IMG_sobel_3x3_16s.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_16S_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_16S_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_16S_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_16S_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_3X3_16S_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sobel_3x3_16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_3X3_16S_66_LE_COFF_SRCIMG_SOBEL_3X3_16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sobel_3x3_16s" -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_3X3_16S_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_3X3_16S_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_sobel_3x3_16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_SOBEL_3X3_16S_66_LE_COFF=.././ >> ./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_SOBEL_3X3_16S_66_LE_COFF_SRCIMG_SOBEL_3X3_16S=../../ >> ./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_SOBEL_3X3_16S_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_SOBEL_3X3_16S_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_COFF/Release/IMG_sobel_3x3_16s_66_LE_COFF.out: ./src/IMG_sobel_3x3_16s/IMG_sobel_3x3_16s.h
./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_COFF/Release/IMG_sobel_3x3_16s_66_LE_COFF.out: ./src/IMG_sobel_3x3_16s/IMG_sobel_3x3_16s_cn.c
./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_COFF/Release/IMG_sobel_3x3_16s_66_LE_COFF.out: ./src/IMG_sobel_3x3_16s/IMG_sobel_3x3_16s_cn.h
./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_COFF/Release/IMG_sobel_3x3_16s_66_LE_COFF.out: ./src/IMG_sobel_3x3_16s/IMG_sobel_3x3_16s_d.c
./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_COFF/Release/IMG_sobel_3x3_16s_66_LE_COFF.out: ./src/IMG_sobel_3x3_16s/IMG_sobel_3x3_16s_idat.c
./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_COFF/Release/IMG_sobel_3x3_16s_66_LE_COFF.out: ./src/IMG_sobel_3x3_16s/IMG_sobel_3x3_16s_odat.c
./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_COFF/Release/IMG_sobel_3x3_16s_66_LE_COFF.out: ./src/IMG_sobel_3x3_16s//c66/IMG_sobel_3x3_16s.c
./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_COFF/Release/IMG_sobel_3x3_16s_66_LE_COFF.out: ./src/IMG_sobel_3x3_16s//c66/IMG_sobel_3x3_16s.h
./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_COFF/Release/IMG_sobel_3x3_16s_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_COFF/Release/IMG_sobel_3x3_16s_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_COFF/Release/IMG_sobel_3x3_16s_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_COFF/Release/IMG_sobel_3x3_16s_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_COFF/Release/IMG_sobel_3x3_16s_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_COFF/Release/IMG_sobel_3x3_16s_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_COFF/Release/IMG_sobel_3x3_16s_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_COFF/Release/IMG_sobel_3x3_16s_66_LE_COFF.out: ./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_COFF/.project
	-@ echo Importing Project IMG_sobel_3x3_16s_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_sobel_3x3_16s_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sobel_3x3_16s/c66/IMG_sobel_3x3_16s_66_LE_COFF"
	-@ echo Building Project IMG_sobel_3x3_16s_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_sobel_3x3_16s_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_sobel_3x3_16s_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_COFF/.settings"

	-@ echo Project IMG_sobel_3x3_16s_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_sobel_3x3_16s_66_LE_ELF

#############################################################

all: ./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_ELF/Release/IMG_sobel_3x3_16s_66_LE_ELF.out

./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_sobel_3x3_16s_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_16S_66_LE_ELF_SRCIMG_SOBEL_3X3_16S/IMG_sobel_3x3_16s_cn.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_16S_66_LE_ELF_SRCIMG_SOBEL_3X3_16S/IMG_sobel_3x3_16s_d.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_16S_66_LE_ELF_SRCIMG_SOBEL_3X3_16S/IMG_sobel_3x3_16s_idat.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_16S_66_LE_ELF_SRCIMG_SOBEL_3X3_16S/IMG_sobel_3x3_16s_odat.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_16S_66_LE_ELF/IMG_sobel_3x3_16s.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_16S_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_16S_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_16S_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_16S_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_3X3_16S_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sobel_3x3_16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_3X3_16S_66_LE_ELF_SRCIMG_SOBEL_3X3_16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sobel_3x3_16s" -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_3X3_16S_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_3X3_16S_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_sobel_3x3_16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_SOBEL_3X3_16S_66_LE_ELF=.././ >> ./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_SOBEL_3X3_16S_66_LE_ELF_SRCIMG_SOBEL_3X3_16S=../../ >> ./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_SOBEL_3X3_16S_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_SOBEL_3X3_16S_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_ELF/Release/IMG_sobel_3x3_16s_66_LE_ELF.out: ./src/IMG_sobel_3x3_16s/IMG_sobel_3x3_16s.h
./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_ELF/Release/IMG_sobel_3x3_16s_66_LE_ELF.out: ./src/IMG_sobel_3x3_16s/IMG_sobel_3x3_16s_cn.c
./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_ELF/Release/IMG_sobel_3x3_16s_66_LE_ELF.out: ./src/IMG_sobel_3x3_16s/IMG_sobel_3x3_16s_cn.h
./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_ELF/Release/IMG_sobel_3x3_16s_66_LE_ELF.out: ./src/IMG_sobel_3x3_16s/IMG_sobel_3x3_16s_d.c
./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_ELF/Release/IMG_sobel_3x3_16s_66_LE_ELF.out: ./src/IMG_sobel_3x3_16s/IMG_sobel_3x3_16s_idat.c
./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_ELF/Release/IMG_sobel_3x3_16s_66_LE_ELF.out: ./src/IMG_sobel_3x3_16s/IMG_sobel_3x3_16s_odat.c
./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_ELF/Release/IMG_sobel_3x3_16s_66_LE_ELF.out: ./src/IMG_sobel_3x3_16s//c66/IMG_sobel_3x3_16s.c
./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_ELF/Release/IMG_sobel_3x3_16s_66_LE_ELF.out: ./src/IMG_sobel_3x3_16s//c66/IMG_sobel_3x3_16s.h
./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_ELF/Release/IMG_sobel_3x3_16s_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_ELF/Release/IMG_sobel_3x3_16s_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_ELF/Release/IMG_sobel_3x3_16s_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_ELF/Release/IMG_sobel_3x3_16s_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_ELF/Release/IMG_sobel_3x3_16s_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_ELF/Release/IMG_sobel_3x3_16s_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_ELF/Release/IMG_sobel_3x3_16s_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_ELF/Release/IMG_sobel_3x3_16s_66_LE_ELF.out: ./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_ELF/.project
	-@ echo Importing Project IMG_sobel_3x3_16s_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_sobel_3x3_16s_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sobel_3x3_16s/c66/IMG_sobel_3x3_16s_66_LE_ELF"
	-@ echo Building Project IMG_sobel_3x3_16s_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_sobel_3x3_16s_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_sobel_3x3_16s_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_ELF/.settings"

	-@ echo Project IMG_sobel_3x3_16s_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_sobel_3x3_16s//c66//IMG_sobel_3x3_16s_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_sobel_3x3_16_66_LE_COFF

#############################################################

all: ./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_COFF/Release/IMG_sobel_3x3_16_66_LE_COFF.out

./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_sobel_3x3_16_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_16_66_LE_COFF_SRCIMG_SOBEL_3X3_16/IMG_sobel_3x3_16_cn.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_16_66_LE_COFF_SRCIMG_SOBEL_3X3_16/IMG_sobel_3x3_16_d.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_16_66_LE_COFF_SRCIMG_SOBEL_3X3_16/IMG_sobel_3x3_16_idat.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_16_66_LE_COFF_SRCIMG_SOBEL_3X3_16/IMG_sobel_3x3_16_odat.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_16_66_LE_COFF/IMG_sobel_3x3_16.sa -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_16_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_16_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_16_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_16_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_3X3_16_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sobel_3x3_16/c66" -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_3X3_16_66_LE_COFF_SRCIMG_SOBEL_3X3_16 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sobel_3x3_16" -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_3X3_16_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_3X3_16_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_sobel_3x3_16.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_SOBEL_3X3_16_66_LE_COFF=.././ >> ./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_SOBEL_3X3_16_66_LE_COFF_SRCIMG_SOBEL_3X3_16=../../ >> ./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_SOBEL_3X3_16_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_SOBEL_3X3_16_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_COFF/Release/IMG_sobel_3x3_16_66_LE_COFF.out: ./src/IMG_sobel_3x3_16/IMG_sobel_3x3_16.h
./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_COFF/Release/IMG_sobel_3x3_16_66_LE_COFF.out: ./src/IMG_sobel_3x3_16/IMG_sobel_3x3_16_cn.c
./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_COFF/Release/IMG_sobel_3x3_16_66_LE_COFF.out: ./src/IMG_sobel_3x3_16/IMG_sobel_3x3_16_cn.h
./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_COFF/Release/IMG_sobel_3x3_16_66_LE_COFF.out: ./src/IMG_sobel_3x3_16/IMG_sobel_3x3_16_d.c
./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_COFF/Release/IMG_sobel_3x3_16_66_LE_COFF.out: ./src/IMG_sobel_3x3_16/IMG_sobel_3x3_16_idat.c
./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_COFF/Release/IMG_sobel_3x3_16_66_LE_COFF.out: ./src/IMG_sobel_3x3_16/IMG_sobel_3x3_16_odat.c
./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_COFF/Release/IMG_sobel_3x3_16_66_LE_COFF.out: ./src/IMG_sobel_3x3_16//c66/IMG_sobel_3x3_16.h
./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_COFF/Release/IMG_sobel_3x3_16_66_LE_COFF.out: ./src/IMG_sobel_3x3_16//c66/IMG_sobel_3x3_16.sa
./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_COFF/Release/IMG_sobel_3x3_16_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_COFF/Release/IMG_sobel_3x3_16_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_COFF/Release/IMG_sobel_3x3_16_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_COFF/Release/IMG_sobel_3x3_16_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_COFF/Release/IMG_sobel_3x3_16_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_COFF/Release/IMG_sobel_3x3_16_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_COFF/Release/IMG_sobel_3x3_16_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_COFF/Release/IMG_sobel_3x3_16_66_LE_COFF.out: ./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_COFF/.project
	-@ echo Importing Project IMG_sobel_3x3_16_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_sobel_3x3_16_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sobel_3x3_16/c66/IMG_sobel_3x3_16_66_LE_COFF"
	-@ echo Building Project IMG_sobel_3x3_16_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_sobel_3x3_16_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_sobel_3x3_16_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_COFF/.settings"

	-@ echo Project IMG_sobel_3x3_16_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_sobel_3x3_16_66_LE_ELF

#############################################################

all: ./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_ELF/Release/IMG_sobel_3x3_16_66_LE_ELF.out

./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_sobel_3x3_16_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_16_66_LE_ELF_SRCIMG_SOBEL_3X3_16/IMG_sobel_3x3_16_cn.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_16_66_LE_ELF_SRCIMG_SOBEL_3X3_16/IMG_sobel_3x3_16_d.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_16_66_LE_ELF_SRCIMG_SOBEL_3X3_16/IMG_sobel_3x3_16_idat.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_16_66_LE_ELF_SRCIMG_SOBEL_3X3_16/IMG_sobel_3x3_16_odat.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_16_66_LE_ELF/IMG_sobel_3x3_16.sa -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_16_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_16_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_16_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_16_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_3X3_16_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sobel_3x3_16/c66" -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_3X3_16_66_LE_ELF_SRCIMG_SOBEL_3X3_16 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sobel_3x3_16" -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_3X3_16_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_3X3_16_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_sobel_3x3_16.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_SOBEL_3X3_16_66_LE_ELF=.././ >> ./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_SOBEL_3X3_16_66_LE_ELF_SRCIMG_SOBEL_3X3_16=../../ >> ./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_SOBEL_3X3_16_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_SOBEL_3X3_16_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_ELF/Release/IMG_sobel_3x3_16_66_LE_ELF.out: ./src/IMG_sobel_3x3_16/IMG_sobel_3x3_16.h
./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_ELF/Release/IMG_sobel_3x3_16_66_LE_ELF.out: ./src/IMG_sobel_3x3_16/IMG_sobel_3x3_16_cn.c
./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_ELF/Release/IMG_sobel_3x3_16_66_LE_ELF.out: ./src/IMG_sobel_3x3_16/IMG_sobel_3x3_16_cn.h
./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_ELF/Release/IMG_sobel_3x3_16_66_LE_ELF.out: ./src/IMG_sobel_3x3_16/IMG_sobel_3x3_16_d.c
./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_ELF/Release/IMG_sobel_3x3_16_66_LE_ELF.out: ./src/IMG_sobel_3x3_16/IMG_sobel_3x3_16_idat.c
./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_ELF/Release/IMG_sobel_3x3_16_66_LE_ELF.out: ./src/IMG_sobel_3x3_16/IMG_sobel_3x3_16_odat.c
./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_ELF/Release/IMG_sobel_3x3_16_66_LE_ELF.out: ./src/IMG_sobel_3x3_16//c66/IMG_sobel_3x3_16.h
./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_ELF/Release/IMG_sobel_3x3_16_66_LE_ELF.out: ./src/IMG_sobel_3x3_16//c66/IMG_sobel_3x3_16.sa
./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_ELF/Release/IMG_sobel_3x3_16_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_ELF/Release/IMG_sobel_3x3_16_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_ELF/Release/IMG_sobel_3x3_16_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_ELF/Release/IMG_sobel_3x3_16_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_ELF/Release/IMG_sobel_3x3_16_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_ELF/Release/IMG_sobel_3x3_16_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_ELF/Release/IMG_sobel_3x3_16_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_ELF/Release/IMG_sobel_3x3_16_66_LE_ELF.out: ./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_ELF/.project
	-@ echo Importing Project IMG_sobel_3x3_16_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_sobel_3x3_16_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sobel_3x3_16/c66/IMG_sobel_3x3_16_66_LE_ELF"
	-@ echo Building Project IMG_sobel_3x3_16_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_sobel_3x3_16_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_sobel_3x3_16_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_ELF/.settings"

	-@ echo Project IMG_sobel_3x3_16_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_sobel_3x3_16//c66//IMG_sobel_3x3_16_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_sobel_3x3_8_66_LE_COFF

#############################################################

all: ./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_COFF/Release/IMG_sobel_3x3_8_66_LE_COFF.out

./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_sobel_3x3_8_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_8_66_LE_COFF_SRCIMG_SOBEL_3X3_8/IMG_sobel_3x3_8_cn.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_8_66_LE_COFF_SRCIMG_SOBEL_3X3_8/IMG_sobel_3x3_8_d.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_8_66_LE_COFF_SRCIMG_SOBEL_3X3_8/IMG_sobel_3x3_8_idat.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_8_66_LE_COFF_SRCIMG_SOBEL_3X3_8/IMG_sobel_3x3_8_odat.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_8_66_LE_COFF/IMG_sobel_3x3_8.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_8_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_8_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_8_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_8_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_3X3_8_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sobel_3x3_8/c66" -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_3X3_8_66_LE_COFF_SRCIMG_SOBEL_3X3_8 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sobel_3x3_8" -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_3X3_8_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_3X3_8_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_sobel_3x3_8.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_SOBEL_3X3_8_66_LE_COFF=.././ >> ./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_SOBEL_3X3_8_66_LE_COFF_SRCIMG_SOBEL_3X3_8=../../ >> ./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_SOBEL_3X3_8_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_SOBEL_3X3_8_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_COFF/Release/IMG_sobel_3x3_8_66_LE_COFF.out: ./src/IMG_sobel_3x3_8/IMG_sobel_3x3_8.h
./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_COFF/Release/IMG_sobel_3x3_8_66_LE_COFF.out: ./src/IMG_sobel_3x3_8/IMG_sobel_3x3_8_cn.c
./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_COFF/Release/IMG_sobel_3x3_8_66_LE_COFF.out: ./src/IMG_sobel_3x3_8/IMG_sobel_3x3_8_cn.h
./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_COFF/Release/IMG_sobel_3x3_8_66_LE_COFF.out: ./src/IMG_sobel_3x3_8/IMG_sobel_3x3_8_d.c
./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_COFF/Release/IMG_sobel_3x3_8_66_LE_COFF.out: ./src/IMG_sobel_3x3_8/IMG_sobel_3x3_8_idat.c
./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_COFF/Release/IMG_sobel_3x3_8_66_LE_COFF.out: ./src/IMG_sobel_3x3_8/IMG_sobel_3x3_8_odat.c
./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_COFF/Release/IMG_sobel_3x3_8_66_LE_COFF.out: ./src/IMG_sobel_3x3_8//c66/IMG_sobel_3x3_8.c
./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_COFF/Release/IMG_sobel_3x3_8_66_LE_COFF.out: ./src/IMG_sobel_3x3_8//c66/IMG_sobel_3x3_8.h
./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_COFF/Release/IMG_sobel_3x3_8_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_COFF/Release/IMG_sobel_3x3_8_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_COFF/Release/IMG_sobel_3x3_8_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_COFF/Release/IMG_sobel_3x3_8_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_COFF/Release/IMG_sobel_3x3_8_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_COFF/Release/IMG_sobel_3x3_8_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_COFF/Release/IMG_sobel_3x3_8_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_COFF/Release/IMG_sobel_3x3_8_66_LE_COFF.out: ./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_COFF/.project
	-@ echo Importing Project IMG_sobel_3x3_8_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_sobel_3x3_8_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sobel_3x3_8/c66/IMG_sobel_3x3_8_66_LE_COFF"
	-@ echo Building Project IMG_sobel_3x3_8_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_sobel_3x3_8_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_sobel_3x3_8_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_COFF/.settings"

	-@ echo Project IMG_sobel_3x3_8_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_sobel_3x3_8_66_LE_ELF

#############################################################

all: ./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_ELF/Release/IMG_sobel_3x3_8_66_LE_ELF.out

./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_sobel_3x3_8_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_8_66_LE_ELF_SRCIMG_SOBEL_3X3_8/IMG_sobel_3x3_8_cn.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_8_66_LE_ELF_SRCIMG_SOBEL_3X3_8/IMG_sobel_3x3_8_d.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_8_66_LE_ELF_SRCIMG_SOBEL_3X3_8/IMG_sobel_3x3_8_idat.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_8_66_LE_ELF_SRCIMG_SOBEL_3X3_8/IMG_sobel_3x3_8_odat.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_8_66_LE_ELF/IMG_sobel_3x3_8.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_8_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_8_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_8_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_3X3_8_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_3X3_8_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sobel_3x3_8/c66" -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_3X3_8_66_LE_ELF_SRCIMG_SOBEL_3X3_8 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sobel_3x3_8" -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_3X3_8_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_3X3_8_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_sobel_3x3_8.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_SOBEL_3X3_8_66_LE_ELF=.././ >> ./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_SOBEL_3X3_8_66_LE_ELF_SRCIMG_SOBEL_3X3_8=../../ >> ./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_SOBEL_3X3_8_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_SOBEL_3X3_8_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_ELF/Release/IMG_sobel_3x3_8_66_LE_ELF.out: ./src/IMG_sobel_3x3_8/IMG_sobel_3x3_8.h
./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_ELF/Release/IMG_sobel_3x3_8_66_LE_ELF.out: ./src/IMG_sobel_3x3_8/IMG_sobel_3x3_8_cn.c
./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_ELF/Release/IMG_sobel_3x3_8_66_LE_ELF.out: ./src/IMG_sobel_3x3_8/IMG_sobel_3x3_8_cn.h
./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_ELF/Release/IMG_sobel_3x3_8_66_LE_ELF.out: ./src/IMG_sobel_3x3_8/IMG_sobel_3x3_8_d.c
./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_ELF/Release/IMG_sobel_3x3_8_66_LE_ELF.out: ./src/IMG_sobel_3x3_8/IMG_sobel_3x3_8_idat.c
./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_ELF/Release/IMG_sobel_3x3_8_66_LE_ELF.out: ./src/IMG_sobel_3x3_8/IMG_sobel_3x3_8_odat.c
./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_ELF/Release/IMG_sobel_3x3_8_66_LE_ELF.out: ./src/IMG_sobel_3x3_8//c66/IMG_sobel_3x3_8.c
./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_ELF/Release/IMG_sobel_3x3_8_66_LE_ELF.out: ./src/IMG_sobel_3x3_8//c66/IMG_sobel_3x3_8.h
./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_ELF/Release/IMG_sobel_3x3_8_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_ELF/Release/IMG_sobel_3x3_8_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_ELF/Release/IMG_sobel_3x3_8_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_ELF/Release/IMG_sobel_3x3_8_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_ELF/Release/IMG_sobel_3x3_8_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_ELF/Release/IMG_sobel_3x3_8_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_ELF/Release/IMG_sobel_3x3_8_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_ELF/Release/IMG_sobel_3x3_8_66_LE_ELF.out: ./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_ELF/.project
	-@ echo Importing Project IMG_sobel_3x3_8_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_sobel_3x3_8_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sobel_3x3_8/c66/IMG_sobel_3x3_8_66_LE_ELF"
	-@ echo Building Project IMG_sobel_3x3_8_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_sobel_3x3_8_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_sobel_3x3_8_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_ELF/.settings"

	-@ echo Project IMG_sobel_3x3_8_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_sobel_3x3_8//c66//IMG_sobel_3x3_8_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_sobel_5x5_16s_66_LE_COFF

#############################################################

all: ./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_COFF/Release/IMG_sobel_5x5_16s_66_LE_COFF.out

./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_sobel_5x5_16s_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_SOBEL_5X5_16S_66_LE_COFF_SRCIMG_SOBEL_5X5_16S/IMG_sobel_5x5_16s_cn.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_5X5_16S_66_LE_COFF_SRCIMG_SOBEL_5X5_16S/IMG_sobel_5x5_16s_d.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_5X5_16S_66_LE_COFF_SRCIMG_SOBEL_5X5_16S/IMG_sobel_5x5_16s_idat.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_5X5_16S_66_LE_COFF_SRCIMG_SOBEL_5X5_16S/IMG_sobel_5x5_16s_odat.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_5X5_16S_66_LE_COFF/IMG_sobel_5x5_16s.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_5X5_16S_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_5X5_16S_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_5X5_16S_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_5X5_16S_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_5X5_16S_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sobel_5x5_16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_5X5_16S_66_LE_COFF_SRCIMG_SOBEL_5X5_16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sobel_5x5_16s" -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_5X5_16S_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_5X5_16S_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_sobel_5x5_16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_SOBEL_5X5_16S_66_LE_COFF=.././ >> ./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_SOBEL_5X5_16S_66_LE_COFF_SRCIMG_SOBEL_5X5_16S=../../ >> ./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_SOBEL_5X5_16S_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_SOBEL_5X5_16S_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_COFF/Release/IMG_sobel_5x5_16s_66_LE_COFF.out: ./src/IMG_sobel_5x5_16s/IMG_sobel_5x5_16s.h
./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_COFF/Release/IMG_sobel_5x5_16s_66_LE_COFF.out: ./src/IMG_sobel_5x5_16s/IMG_sobel_5x5_16s_cn.c
./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_COFF/Release/IMG_sobel_5x5_16s_66_LE_COFF.out: ./src/IMG_sobel_5x5_16s/IMG_sobel_5x5_16s_cn.h
./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_COFF/Release/IMG_sobel_5x5_16s_66_LE_COFF.out: ./src/IMG_sobel_5x5_16s/IMG_sobel_5x5_16s_d.c
./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_COFF/Release/IMG_sobel_5x5_16s_66_LE_COFF.out: ./src/IMG_sobel_5x5_16s/IMG_sobel_5x5_16s_idat.c
./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_COFF/Release/IMG_sobel_5x5_16s_66_LE_COFF.out: ./src/IMG_sobel_5x5_16s/IMG_sobel_5x5_16s_odat.c
./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_COFF/Release/IMG_sobel_5x5_16s_66_LE_COFF.out: ./src/IMG_sobel_5x5_16s//c66/IMG_sobel_5x5_16s.c
./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_COFF/Release/IMG_sobel_5x5_16s_66_LE_COFF.out: ./src/IMG_sobel_5x5_16s//c66/IMG_sobel_5x5_16s.h
./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_COFF/Release/IMG_sobel_5x5_16s_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_COFF/Release/IMG_sobel_5x5_16s_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_COFF/Release/IMG_sobel_5x5_16s_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_COFF/Release/IMG_sobel_5x5_16s_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_COFF/Release/IMG_sobel_5x5_16s_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_COFF/Release/IMG_sobel_5x5_16s_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_COFF/Release/IMG_sobel_5x5_16s_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_COFF/Release/IMG_sobel_5x5_16s_66_LE_COFF.out: ./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_COFF/.project
	-@ echo Importing Project IMG_sobel_5x5_16s_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_sobel_5x5_16s_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sobel_5x5_16s/c66/IMG_sobel_5x5_16s_66_LE_COFF"
	-@ echo Building Project IMG_sobel_5x5_16s_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_sobel_5x5_16s_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_sobel_5x5_16s_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_COFF/.settings"

	-@ echo Project IMG_sobel_5x5_16s_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_sobel_5x5_16s_66_LE_ELF

#############################################################

all: ./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_ELF/Release/IMG_sobel_5x5_16s_66_LE_ELF.out

./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_sobel_5x5_16s_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_SOBEL_5X5_16S_66_LE_ELF_SRCIMG_SOBEL_5X5_16S/IMG_sobel_5x5_16s_cn.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_5X5_16S_66_LE_ELF_SRCIMG_SOBEL_5X5_16S/IMG_sobel_5x5_16s_d.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_5X5_16S_66_LE_ELF_SRCIMG_SOBEL_5X5_16S/IMG_sobel_5x5_16s_idat.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_5X5_16S_66_LE_ELF_SRCIMG_SOBEL_5X5_16S/IMG_sobel_5x5_16s_odat.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_5X5_16S_66_LE_ELF/IMG_sobel_5x5_16s.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_5X5_16S_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_5X5_16S_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_5X5_16S_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_5X5_16S_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_5X5_16S_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sobel_5x5_16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_5X5_16S_66_LE_ELF_SRCIMG_SOBEL_5X5_16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sobel_5x5_16s" -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_5X5_16S_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_5X5_16S_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_sobel_5x5_16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_SOBEL_5X5_16S_66_LE_ELF=.././ >> ./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_SOBEL_5X5_16S_66_LE_ELF_SRCIMG_SOBEL_5X5_16S=../../ >> ./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_SOBEL_5X5_16S_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_SOBEL_5X5_16S_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_ELF/Release/IMG_sobel_5x5_16s_66_LE_ELF.out: ./src/IMG_sobel_5x5_16s/IMG_sobel_5x5_16s.h
./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_ELF/Release/IMG_sobel_5x5_16s_66_LE_ELF.out: ./src/IMG_sobel_5x5_16s/IMG_sobel_5x5_16s_cn.c
./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_ELF/Release/IMG_sobel_5x5_16s_66_LE_ELF.out: ./src/IMG_sobel_5x5_16s/IMG_sobel_5x5_16s_cn.h
./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_ELF/Release/IMG_sobel_5x5_16s_66_LE_ELF.out: ./src/IMG_sobel_5x5_16s/IMG_sobel_5x5_16s_d.c
./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_ELF/Release/IMG_sobel_5x5_16s_66_LE_ELF.out: ./src/IMG_sobel_5x5_16s/IMG_sobel_5x5_16s_idat.c
./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_ELF/Release/IMG_sobel_5x5_16s_66_LE_ELF.out: ./src/IMG_sobel_5x5_16s/IMG_sobel_5x5_16s_odat.c
./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_ELF/Release/IMG_sobel_5x5_16s_66_LE_ELF.out: ./src/IMG_sobel_5x5_16s//c66/IMG_sobel_5x5_16s.c
./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_ELF/Release/IMG_sobel_5x5_16s_66_LE_ELF.out: ./src/IMG_sobel_5x5_16s//c66/IMG_sobel_5x5_16s.h
./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_ELF/Release/IMG_sobel_5x5_16s_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_ELF/Release/IMG_sobel_5x5_16s_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_ELF/Release/IMG_sobel_5x5_16s_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_ELF/Release/IMG_sobel_5x5_16s_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_ELF/Release/IMG_sobel_5x5_16s_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_ELF/Release/IMG_sobel_5x5_16s_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_ELF/Release/IMG_sobel_5x5_16s_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_ELF/Release/IMG_sobel_5x5_16s_66_LE_ELF.out: ./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_ELF/.project
	-@ echo Importing Project IMG_sobel_5x5_16s_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_sobel_5x5_16s_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sobel_5x5_16s/c66/IMG_sobel_5x5_16s_66_LE_ELF"
	-@ echo Building Project IMG_sobel_5x5_16s_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_sobel_5x5_16s_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_sobel_5x5_16s_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_ELF/.settings"

	-@ echo Project IMG_sobel_5x5_16s_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_sobel_5x5_16s//c66//IMG_sobel_5x5_16s_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_sobel_7x7_16s_66_LE_COFF

#############################################################

all: ./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_COFF/Release/IMG_sobel_7x7_16s_66_LE_COFF.out

./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_sobel_7x7_16s_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_SOBEL_7X7_16S_66_LE_COFF_SRCIMG_SOBEL_7X7_16S/IMG_sobel_7x7_16s_cn.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_7X7_16S_66_LE_COFF_SRCIMG_SOBEL_7X7_16S/IMG_sobel_7x7_16s_d.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_7X7_16S_66_LE_COFF_SRCIMG_SOBEL_7X7_16S/IMG_sobel_7x7_16s_idat.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_7X7_16S_66_LE_COFF_SRCIMG_SOBEL_7X7_16S/IMG_sobel_7x7_16s_odat.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_7X7_16S_66_LE_COFF/IMG_sobel_7x7_16s.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_7X7_16S_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_7X7_16S_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_7X7_16S_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_7X7_16S_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_7X7_16S_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sobel_7x7_16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_7X7_16S_66_LE_COFF_SRCIMG_SOBEL_7X7_16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sobel_7x7_16s" -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_7X7_16S_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_7X7_16S_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_sobel_7x7_16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_SOBEL_7X7_16S_66_LE_COFF=.././ >> ./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_SOBEL_7X7_16S_66_LE_COFF_SRCIMG_SOBEL_7X7_16S=../../ >> ./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_SOBEL_7X7_16S_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_SOBEL_7X7_16S_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_COFF/Release/IMG_sobel_7x7_16s_66_LE_COFF.out: ./src/IMG_sobel_7x7_16s/IMG_sobel_7x7_16s.h
./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_COFF/Release/IMG_sobel_7x7_16s_66_LE_COFF.out: ./src/IMG_sobel_7x7_16s/IMG_sobel_7x7_16s_cn.c
./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_COFF/Release/IMG_sobel_7x7_16s_66_LE_COFF.out: ./src/IMG_sobel_7x7_16s/IMG_sobel_7x7_16s_cn.h
./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_COFF/Release/IMG_sobel_7x7_16s_66_LE_COFF.out: ./src/IMG_sobel_7x7_16s/IMG_sobel_7x7_16s_d.c
./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_COFF/Release/IMG_sobel_7x7_16s_66_LE_COFF.out: ./src/IMG_sobel_7x7_16s/IMG_sobel_7x7_16s_idat.c
./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_COFF/Release/IMG_sobel_7x7_16s_66_LE_COFF.out: ./src/IMG_sobel_7x7_16s/IMG_sobel_7x7_16s_odat.c
./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_COFF/Release/IMG_sobel_7x7_16s_66_LE_COFF.out: ./src/IMG_sobel_7x7_16s//c66/IMG_sobel_7x7_16s.c
./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_COFF/Release/IMG_sobel_7x7_16s_66_LE_COFF.out: ./src/IMG_sobel_7x7_16s//c66/IMG_sobel_7x7_16s.h
./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_COFF/Release/IMG_sobel_7x7_16s_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_COFF/Release/IMG_sobel_7x7_16s_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_COFF/Release/IMG_sobel_7x7_16s_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_COFF/Release/IMG_sobel_7x7_16s_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_COFF/Release/IMG_sobel_7x7_16s_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_COFF/Release/IMG_sobel_7x7_16s_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_COFF/Release/IMG_sobel_7x7_16s_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_COFF/Release/IMG_sobel_7x7_16s_66_LE_COFF.out: ./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_COFF/.project
	-@ echo Importing Project IMG_sobel_7x7_16s_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_sobel_7x7_16s_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sobel_7x7_16s/c66/IMG_sobel_7x7_16s_66_LE_COFF"
	-@ echo Building Project IMG_sobel_7x7_16s_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_sobel_7x7_16s_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_sobel_7x7_16s_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_COFF/.settings"

	-@ echo Project IMG_sobel_7x7_16s_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_sobel_7x7_16s_66_LE_ELF

#############################################################

all: ./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_ELF/Release/IMG_sobel_7x7_16s_66_LE_ELF.out

./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_sobel_7x7_16s_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_SOBEL_7X7_16S_66_LE_ELF_SRCIMG_SOBEL_7X7_16S/IMG_sobel_7x7_16s_cn.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_7X7_16S_66_LE_ELF_SRCIMG_SOBEL_7X7_16S/IMG_sobel_7x7_16s_d.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_7X7_16S_66_LE_ELF_SRCIMG_SOBEL_7X7_16S/IMG_sobel_7x7_16s_idat.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_7X7_16S_66_LE_ELF_SRCIMG_SOBEL_7X7_16S/IMG_sobel_7x7_16s_odat.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_7X7_16S_66_LE_ELF/IMG_sobel_7x7_16s.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_7X7_16S_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_7X7_16S_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_7X7_16S_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_SOBEL_7X7_16S_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_7X7_16S_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sobel_7x7_16s/c66" -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_7X7_16S_66_LE_ELF_SRCIMG_SOBEL_7X7_16S "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sobel_7x7_16s" -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_7X7_16S_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_SOBEL_7X7_16S_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_sobel_7x7_16s.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_SOBEL_7X7_16S_66_LE_ELF=.././ >> ./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_SOBEL_7X7_16S_66_LE_ELF_SRCIMG_SOBEL_7X7_16S=../../ >> ./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_SOBEL_7X7_16S_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_SOBEL_7X7_16S_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_ELF/Release/IMG_sobel_7x7_16s_66_LE_ELF.out: ./src/IMG_sobel_7x7_16s/IMG_sobel_7x7_16s.h
./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_ELF/Release/IMG_sobel_7x7_16s_66_LE_ELF.out: ./src/IMG_sobel_7x7_16s/IMG_sobel_7x7_16s_cn.c
./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_ELF/Release/IMG_sobel_7x7_16s_66_LE_ELF.out: ./src/IMG_sobel_7x7_16s/IMG_sobel_7x7_16s_cn.h
./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_ELF/Release/IMG_sobel_7x7_16s_66_LE_ELF.out: ./src/IMG_sobel_7x7_16s/IMG_sobel_7x7_16s_d.c
./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_ELF/Release/IMG_sobel_7x7_16s_66_LE_ELF.out: ./src/IMG_sobel_7x7_16s/IMG_sobel_7x7_16s_idat.c
./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_ELF/Release/IMG_sobel_7x7_16s_66_LE_ELF.out: ./src/IMG_sobel_7x7_16s/IMG_sobel_7x7_16s_odat.c
./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_ELF/Release/IMG_sobel_7x7_16s_66_LE_ELF.out: ./src/IMG_sobel_7x7_16s//c66/IMG_sobel_7x7_16s.c
./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_ELF/Release/IMG_sobel_7x7_16s_66_LE_ELF.out: ./src/IMG_sobel_7x7_16s//c66/IMG_sobel_7x7_16s.h
./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_ELF/Release/IMG_sobel_7x7_16s_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_ELF/Release/IMG_sobel_7x7_16s_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_ELF/Release/IMG_sobel_7x7_16s_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_ELF/Release/IMG_sobel_7x7_16s_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_ELF/Release/IMG_sobel_7x7_16s_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_ELF/Release/IMG_sobel_7x7_16s_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_ELF/Release/IMG_sobel_7x7_16s_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_ELF/Release/IMG_sobel_7x7_16s_66_LE_ELF.out: ./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_ELF/.project
	-@ echo Importing Project IMG_sobel_7x7_16s_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_sobel_7x7_16s_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_sobel_7x7_16s/c66/IMG_sobel_7x7_16s_66_LE_ELF"
	-@ echo Building Project IMG_sobel_7x7_16s_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_sobel_7x7_16s_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_sobel_7x7_16s_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_ELF/.settings"

	-@ echo Project IMG_sobel_7x7_16s_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_sobel_7x7_16s//c66//IMG_sobel_7x7_16s_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_thr_gt2max_16_66_LE_COFF

#############################################################

all: ./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_COFF/Release/IMG_thr_gt2max_16_66_LE_COFF.out

./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_thr_gt2max_16_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_THR_GT2MAX_16_66_LE_COFF_SRCIMG_THR_GT2MAX_16/IMG_thr_gt2max_16_cn.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2MAX_16_66_LE_COFF_SRCIMG_THR_GT2MAX_16/IMG_thr_gt2max_16_d.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2MAX_16_66_LE_COFF_SRCIMG_THR_GT2MAX_16/IMG_thr_gt2max_16_idat.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2MAX_16_66_LE_COFF_SRCIMG_THR_GT2MAX_16/IMG_thr_gt2max_16_odat.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2MAX_16_66_LE_COFF/IMG_thr_gt2max_16.sa -ccs.linkFile EXT_ROOT__IMG_THR_GT2MAX_16_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2MAX_16_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2MAX_16_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2MAX_16_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_THR_GT2MAX_16_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_gt2max_16/c66" -ccs.definePathVariable EXT_ROOT__IMG_THR_GT2MAX_16_66_LE_COFF_SRCIMG_THR_GT2MAX_16 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_gt2max_16" -ccs.definePathVariable EXT_ROOT__IMG_THR_GT2MAX_16_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_THR_GT2MAX_16_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_thr_gt2max_16.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_THR_GT2MAX_16_66_LE_COFF=.././ >> ./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_THR_GT2MAX_16_66_LE_COFF_SRCIMG_THR_GT2MAX_16=../../ >> ./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_THR_GT2MAX_16_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_THR_GT2MAX_16_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_COFF/Release/IMG_thr_gt2max_16_66_LE_COFF.out: ./src/IMG_thr_gt2max_16/IMG_thr_gt2max_16.h
./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_COFF/Release/IMG_thr_gt2max_16_66_LE_COFF.out: ./src/IMG_thr_gt2max_16/IMG_thr_gt2max_16_cn.c
./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_COFF/Release/IMG_thr_gt2max_16_66_LE_COFF.out: ./src/IMG_thr_gt2max_16/IMG_thr_gt2max_16_cn.h
./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_COFF/Release/IMG_thr_gt2max_16_66_LE_COFF.out: ./src/IMG_thr_gt2max_16/IMG_thr_gt2max_16_d.c
./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_COFF/Release/IMG_thr_gt2max_16_66_LE_COFF.out: ./src/IMG_thr_gt2max_16/IMG_thr_gt2max_16_idat.c
./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_COFF/Release/IMG_thr_gt2max_16_66_LE_COFF.out: ./src/IMG_thr_gt2max_16/IMG_thr_gt2max_16_odat.c
./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_COFF/Release/IMG_thr_gt2max_16_66_LE_COFF.out: ./src/IMG_thr_gt2max_16//c66/IMG_thr_gt2max_16.h
./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_COFF/Release/IMG_thr_gt2max_16_66_LE_COFF.out: ./src/IMG_thr_gt2max_16//c66/IMG_thr_gt2max_16.sa
./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_COFF/Release/IMG_thr_gt2max_16_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_COFF/Release/IMG_thr_gt2max_16_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_COFF/Release/IMG_thr_gt2max_16_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_COFF/Release/IMG_thr_gt2max_16_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_COFF/Release/IMG_thr_gt2max_16_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_COFF/Release/IMG_thr_gt2max_16_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_COFF/Release/IMG_thr_gt2max_16_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_COFF/Release/IMG_thr_gt2max_16_66_LE_COFF.out: ./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_COFF/.project
	-@ echo Importing Project IMG_thr_gt2max_16_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_thr_gt2max_16_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_gt2max_16/c66/IMG_thr_gt2max_16_66_LE_COFF"
	-@ echo Building Project IMG_thr_gt2max_16_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_thr_gt2max_16_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_thr_gt2max_16_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_COFF/.settings"

	-@ echo Project IMG_thr_gt2max_16_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_thr_gt2max_16_66_LE_ELF

#############################################################

all: ./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_ELF/Release/IMG_thr_gt2max_16_66_LE_ELF.out

./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_thr_gt2max_16_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_THR_GT2MAX_16_66_LE_ELF_SRCIMG_THR_GT2MAX_16/IMG_thr_gt2max_16_cn.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2MAX_16_66_LE_ELF_SRCIMG_THR_GT2MAX_16/IMG_thr_gt2max_16_d.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2MAX_16_66_LE_ELF_SRCIMG_THR_GT2MAX_16/IMG_thr_gt2max_16_idat.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2MAX_16_66_LE_ELF_SRCIMG_THR_GT2MAX_16/IMG_thr_gt2max_16_odat.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2MAX_16_66_LE_ELF/IMG_thr_gt2max_16.sa -ccs.linkFile EXT_ROOT__IMG_THR_GT2MAX_16_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2MAX_16_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2MAX_16_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2MAX_16_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_THR_GT2MAX_16_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_gt2max_16/c66" -ccs.definePathVariable EXT_ROOT__IMG_THR_GT2MAX_16_66_LE_ELF_SRCIMG_THR_GT2MAX_16 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_gt2max_16" -ccs.definePathVariable EXT_ROOT__IMG_THR_GT2MAX_16_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_THR_GT2MAX_16_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_thr_gt2max_16.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_THR_GT2MAX_16_66_LE_ELF=.././ >> ./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_THR_GT2MAX_16_66_LE_ELF_SRCIMG_THR_GT2MAX_16=../../ >> ./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_THR_GT2MAX_16_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_THR_GT2MAX_16_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_ELF/Release/IMG_thr_gt2max_16_66_LE_ELF.out: ./src/IMG_thr_gt2max_16/IMG_thr_gt2max_16.h
./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_ELF/Release/IMG_thr_gt2max_16_66_LE_ELF.out: ./src/IMG_thr_gt2max_16/IMG_thr_gt2max_16_cn.c
./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_ELF/Release/IMG_thr_gt2max_16_66_LE_ELF.out: ./src/IMG_thr_gt2max_16/IMG_thr_gt2max_16_cn.h
./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_ELF/Release/IMG_thr_gt2max_16_66_LE_ELF.out: ./src/IMG_thr_gt2max_16/IMG_thr_gt2max_16_d.c
./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_ELF/Release/IMG_thr_gt2max_16_66_LE_ELF.out: ./src/IMG_thr_gt2max_16/IMG_thr_gt2max_16_idat.c
./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_ELF/Release/IMG_thr_gt2max_16_66_LE_ELF.out: ./src/IMG_thr_gt2max_16/IMG_thr_gt2max_16_odat.c
./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_ELF/Release/IMG_thr_gt2max_16_66_LE_ELF.out: ./src/IMG_thr_gt2max_16//c66/IMG_thr_gt2max_16.h
./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_ELF/Release/IMG_thr_gt2max_16_66_LE_ELF.out: ./src/IMG_thr_gt2max_16//c66/IMG_thr_gt2max_16.sa
./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_ELF/Release/IMG_thr_gt2max_16_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_ELF/Release/IMG_thr_gt2max_16_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_ELF/Release/IMG_thr_gt2max_16_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_ELF/Release/IMG_thr_gt2max_16_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_ELF/Release/IMG_thr_gt2max_16_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_ELF/Release/IMG_thr_gt2max_16_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_ELF/Release/IMG_thr_gt2max_16_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_ELF/Release/IMG_thr_gt2max_16_66_LE_ELF.out: ./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_ELF/.project
	-@ echo Importing Project IMG_thr_gt2max_16_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_thr_gt2max_16_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_gt2max_16/c66/IMG_thr_gt2max_16_66_LE_ELF"
	-@ echo Building Project IMG_thr_gt2max_16_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_thr_gt2max_16_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_thr_gt2max_16_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_ELF/.settings"

	-@ echo Project IMG_thr_gt2max_16_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_thr_gt2max_16//c66//IMG_thr_gt2max_16_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_thr_gt2max_8_66_LE_COFF

#############################################################

all: ./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_COFF/Release/IMG_thr_gt2max_8_66_LE_COFF.out

./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_thr_gt2max_8_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_THR_GT2MAX_8_66_LE_COFF_SRCIMG_THR_GT2MAX_8/IMG_thr_gt2max_8_cn.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2MAX_8_66_LE_COFF_SRCIMG_THR_GT2MAX_8/IMG_thr_gt2max_8_d.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2MAX_8_66_LE_COFF_SRCIMG_THR_GT2MAX_8/IMG_thr_gt2max_8_idat.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2MAX_8_66_LE_COFF_SRCIMG_THR_GT2MAX_8/IMG_thr_gt2max_8_odat.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2MAX_8_66_LE_COFF/IMG_thr_gt2max_8.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2MAX_8_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2MAX_8_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2MAX_8_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2MAX_8_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_THR_GT2MAX_8_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_gt2max_8/c66" -ccs.definePathVariable EXT_ROOT__IMG_THR_GT2MAX_8_66_LE_COFF_SRCIMG_THR_GT2MAX_8 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_gt2max_8" -ccs.definePathVariable EXT_ROOT__IMG_THR_GT2MAX_8_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_THR_GT2MAX_8_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_thr_gt2max_8.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_THR_GT2MAX_8_66_LE_COFF=.././ >> ./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_THR_GT2MAX_8_66_LE_COFF_SRCIMG_THR_GT2MAX_8=../../ >> ./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_THR_GT2MAX_8_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_THR_GT2MAX_8_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_COFF/Release/IMG_thr_gt2max_8_66_LE_COFF.out: ./src/IMG_thr_gt2max_8/IMG_thr_gt2max_8.h
./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_COFF/Release/IMG_thr_gt2max_8_66_LE_COFF.out: ./src/IMG_thr_gt2max_8/IMG_thr_gt2max_8_cn.c
./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_COFF/Release/IMG_thr_gt2max_8_66_LE_COFF.out: ./src/IMG_thr_gt2max_8/IMG_thr_gt2max_8_cn.h
./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_COFF/Release/IMG_thr_gt2max_8_66_LE_COFF.out: ./src/IMG_thr_gt2max_8/IMG_thr_gt2max_8_d.c
./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_COFF/Release/IMG_thr_gt2max_8_66_LE_COFF.out: ./src/IMG_thr_gt2max_8/IMG_thr_gt2max_8_idat.c
./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_COFF/Release/IMG_thr_gt2max_8_66_LE_COFF.out: ./src/IMG_thr_gt2max_8/IMG_thr_gt2max_8_odat.c
./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_COFF/Release/IMG_thr_gt2max_8_66_LE_COFF.out: ./src/IMG_thr_gt2max_8//c66/IMG_thr_gt2max_8.c
./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_COFF/Release/IMG_thr_gt2max_8_66_LE_COFF.out: ./src/IMG_thr_gt2max_8//c66/IMG_thr_gt2max_8.h
./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_COFF/Release/IMG_thr_gt2max_8_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_COFF/Release/IMG_thr_gt2max_8_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_COFF/Release/IMG_thr_gt2max_8_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_COFF/Release/IMG_thr_gt2max_8_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_COFF/Release/IMG_thr_gt2max_8_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_COFF/Release/IMG_thr_gt2max_8_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_COFF/Release/IMG_thr_gt2max_8_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_COFF/Release/IMG_thr_gt2max_8_66_LE_COFF.out: ./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_COFF/.project
	-@ echo Importing Project IMG_thr_gt2max_8_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_thr_gt2max_8_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_gt2max_8/c66/IMG_thr_gt2max_8_66_LE_COFF"
	-@ echo Building Project IMG_thr_gt2max_8_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_thr_gt2max_8_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_thr_gt2max_8_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_COFF/.settings"

	-@ echo Project IMG_thr_gt2max_8_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_thr_gt2max_8_66_LE_ELF

#############################################################

all: ./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_ELF/Release/IMG_thr_gt2max_8_66_LE_ELF.out

./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_thr_gt2max_8_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_THR_GT2MAX_8_66_LE_ELF_SRCIMG_THR_GT2MAX_8/IMG_thr_gt2max_8_cn.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2MAX_8_66_LE_ELF_SRCIMG_THR_GT2MAX_8/IMG_thr_gt2max_8_d.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2MAX_8_66_LE_ELF_SRCIMG_THR_GT2MAX_8/IMG_thr_gt2max_8_idat.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2MAX_8_66_LE_ELF_SRCIMG_THR_GT2MAX_8/IMG_thr_gt2max_8_odat.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2MAX_8_66_LE_ELF/IMG_thr_gt2max_8.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2MAX_8_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2MAX_8_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2MAX_8_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2MAX_8_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_THR_GT2MAX_8_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_gt2max_8/c66" -ccs.definePathVariable EXT_ROOT__IMG_THR_GT2MAX_8_66_LE_ELF_SRCIMG_THR_GT2MAX_8 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_gt2max_8" -ccs.definePathVariable EXT_ROOT__IMG_THR_GT2MAX_8_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_THR_GT2MAX_8_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_thr_gt2max_8.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_THR_GT2MAX_8_66_LE_ELF=.././ >> ./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_THR_GT2MAX_8_66_LE_ELF_SRCIMG_THR_GT2MAX_8=../../ >> ./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_THR_GT2MAX_8_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_THR_GT2MAX_8_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_ELF/Release/IMG_thr_gt2max_8_66_LE_ELF.out: ./src/IMG_thr_gt2max_8/IMG_thr_gt2max_8.h
./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_ELF/Release/IMG_thr_gt2max_8_66_LE_ELF.out: ./src/IMG_thr_gt2max_8/IMG_thr_gt2max_8_cn.c
./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_ELF/Release/IMG_thr_gt2max_8_66_LE_ELF.out: ./src/IMG_thr_gt2max_8/IMG_thr_gt2max_8_cn.h
./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_ELF/Release/IMG_thr_gt2max_8_66_LE_ELF.out: ./src/IMG_thr_gt2max_8/IMG_thr_gt2max_8_d.c
./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_ELF/Release/IMG_thr_gt2max_8_66_LE_ELF.out: ./src/IMG_thr_gt2max_8/IMG_thr_gt2max_8_idat.c
./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_ELF/Release/IMG_thr_gt2max_8_66_LE_ELF.out: ./src/IMG_thr_gt2max_8/IMG_thr_gt2max_8_odat.c
./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_ELF/Release/IMG_thr_gt2max_8_66_LE_ELF.out: ./src/IMG_thr_gt2max_8//c66/IMG_thr_gt2max_8.c
./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_ELF/Release/IMG_thr_gt2max_8_66_LE_ELF.out: ./src/IMG_thr_gt2max_8//c66/IMG_thr_gt2max_8.h
./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_ELF/Release/IMG_thr_gt2max_8_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_ELF/Release/IMG_thr_gt2max_8_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_ELF/Release/IMG_thr_gt2max_8_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_ELF/Release/IMG_thr_gt2max_8_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_ELF/Release/IMG_thr_gt2max_8_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_ELF/Release/IMG_thr_gt2max_8_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_ELF/Release/IMG_thr_gt2max_8_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_ELF/Release/IMG_thr_gt2max_8_66_LE_ELF.out: ./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_ELF/.project
	-@ echo Importing Project IMG_thr_gt2max_8_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_thr_gt2max_8_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_gt2max_8/c66/IMG_thr_gt2max_8_66_LE_ELF"
	-@ echo Building Project IMG_thr_gt2max_8_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_thr_gt2max_8_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_thr_gt2max_8_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_ELF/.settings"

	-@ echo Project IMG_thr_gt2max_8_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_thr_gt2max_8//c66//IMG_thr_gt2max_8_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_thr_gt2thr_16_66_LE_COFF

#############################################################

all: ./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_COFF/Release/IMG_thr_gt2thr_16_66_LE_COFF.out

./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_thr_gt2thr_16_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_THR_GT2THR_16_66_LE_COFF_SRCIMG_THR_GT2THR_16/IMG_thr_gt2thr_16_cn.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2THR_16_66_LE_COFF_SRCIMG_THR_GT2THR_16/IMG_thr_gt2thr_16_d.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2THR_16_66_LE_COFF_SRCIMG_THR_GT2THR_16/IMG_thr_gt2thr_16_idat.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2THR_16_66_LE_COFF_SRCIMG_THR_GT2THR_16/IMG_thr_gt2thr_16_odat.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2THR_16_66_LE_COFF/IMG_thr_gt2thr_16.sa -ccs.linkFile EXT_ROOT__IMG_THR_GT2THR_16_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2THR_16_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2THR_16_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2THR_16_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_THR_GT2THR_16_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_gt2thr_16/c66" -ccs.definePathVariable EXT_ROOT__IMG_THR_GT2THR_16_66_LE_COFF_SRCIMG_THR_GT2THR_16 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_gt2thr_16" -ccs.definePathVariable EXT_ROOT__IMG_THR_GT2THR_16_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_THR_GT2THR_16_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_thr_gt2thr_16.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_THR_GT2THR_16_66_LE_COFF=.././ >> ./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_THR_GT2THR_16_66_LE_COFF_SRCIMG_THR_GT2THR_16=../../ >> ./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_THR_GT2THR_16_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_THR_GT2THR_16_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_COFF/Release/IMG_thr_gt2thr_16_66_LE_COFF.out: ./src/IMG_thr_gt2thr_16/IMG_thr_gt2thr_16.h
./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_COFF/Release/IMG_thr_gt2thr_16_66_LE_COFF.out: ./src/IMG_thr_gt2thr_16/IMG_thr_gt2thr_16_cn.c
./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_COFF/Release/IMG_thr_gt2thr_16_66_LE_COFF.out: ./src/IMG_thr_gt2thr_16/IMG_thr_gt2thr_16_cn.h
./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_COFF/Release/IMG_thr_gt2thr_16_66_LE_COFF.out: ./src/IMG_thr_gt2thr_16/IMG_thr_gt2thr_16_d.c
./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_COFF/Release/IMG_thr_gt2thr_16_66_LE_COFF.out: ./src/IMG_thr_gt2thr_16/IMG_thr_gt2thr_16_idat.c
./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_COFF/Release/IMG_thr_gt2thr_16_66_LE_COFF.out: ./src/IMG_thr_gt2thr_16/IMG_thr_gt2thr_16_odat.c
./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_COFF/Release/IMG_thr_gt2thr_16_66_LE_COFF.out: ./src/IMG_thr_gt2thr_16//c66/IMG_thr_gt2thr_16.h
./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_COFF/Release/IMG_thr_gt2thr_16_66_LE_COFF.out: ./src/IMG_thr_gt2thr_16//c66/IMG_thr_gt2thr_16.sa
./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_COFF/Release/IMG_thr_gt2thr_16_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_COFF/Release/IMG_thr_gt2thr_16_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_COFF/Release/IMG_thr_gt2thr_16_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_COFF/Release/IMG_thr_gt2thr_16_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_COFF/Release/IMG_thr_gt2thr_16_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_COFF/Release/IMG_thr_gt2thr_16_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_COFF/Release/IMG_thr_gt2thr_16_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_COFF/Release/IMG_thr_gt2thr_16_66_LE_COFF.out: ./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_COFF/.project
	-@ echo Importing Project IMG_thr_gt2thr_16_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_thr_gt2thr_16_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_gt2thr_16/c66/IMG_thr_gt2thr_16_66_LE_COFF"
	-@ echo Building Project IMG_thr_gt2thr_16_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_thr_gt2thr_16_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_thr_gt2thr_16_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_COFF/.settings"

	-@ echo Project IMG_thr_gt2thr_16_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_thr_gt2thr_16_66_LE_ELF

#############################################################

all: ./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_ELF/Release/IMG_thr_gt2thr_16_66_LE_ELF.out

./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_thr_gt2thr_16_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_THR_GT2THR_16_66_LE_ELF_SRCIMG_THR_GT2THR_16/IMG_thr_gt2thr_16_cn.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2THR_16_66_LE_ELF_SRCIMG_THR_GT2THR_16/IMG_thr_gt2thr_16_d.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2THR_16_66_LE_ELF_SRCIMG_THR_GT2THR_16/IMG_thr_gt2thr_16_idat.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2THR_16_66_LE_ELF_SRCIMG_THR_GT2THR_16/IMG_thr_gt2thr_16_odat.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2THR_16_66_LE_ELF/IMG_thr_gt2thr_16.sa -ccs.linkFile EXT_ROOT__IMG_THR_GT2THR_16_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2THR_16_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2THR_16_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2THR_16_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_THR_GT2THR_16_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_gt2thr_16/c66" -ccs.definePathVariable EXT_ROOT__IMG_THR_GT2THR_16_66_LE_ELF_SRCIMG_THR_GT2THR_16 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_gt2thr_16" -ccs.definePathVariable EXT_ROOT__IMG_THR_GT2THR_16_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_THR_GT2THR_16_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_thr_gt2thr_16.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_THR_GT2THR_16_66_LE_ELF=.././ >> ./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_THR_GT2THR_16_66_LE_ELF_SRCIMG_THR_GT2THR_16=../../ >> ./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_THR_GT2THR_16_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_THR_GT2THR_16_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_ELF/Release/IMG_thr_gt2thr_16_66_LE_ELF.out: ./src/IMG_thr_gt2thr_16/IMG_thr_gt2thr_16.h
./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_ELF/Release/IMG_thr_gt2thr_16_66_LE_ELF.out: ./src/IMG_thr_gt2thr_16/IMG_thr_gt2thr_16_cn.c
./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_ELF/Release/IMG_thr_gt2thr_16_66_LE_ELF.out: ./src/IMG_thr_gt2thr_16/IMG_thr_gt2thr_16_cn.h
./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_ELF/Release/IMG_thr_gt2thr_16_66_LE_ELF.out: ./src/IMG_thr_gt2thr_16/IMG_thr_gt2thr_16_d.c
./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_ELF/Release/IMG_thr_gt2thr_16_66_LE_ELF.out: ./src/IMG_thr_gt2thr_16/IMG_thr_gt2thr_16_idat.c
./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_ELF/Release/IMG_thr_gt2thr_16_66_LE_ELF.out: ./src/IMG_thr_gt2thr_16/IMG_thr_gt2thr_16_odat.c
./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_ELF/Release/IMG_thr_gt2thr_16_66_LE_ELF.out: ./src/IMG_thr_gt2thr_16//c66/IMG_thr_gt2thr_16.h
./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_ELF/Release/IMG_thr_gt2thr_16_66_LE_ELF.out: ./src/IMG_thr_gt2thr_16//c66/IMG_thr_gt2thr_16.sa
./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_ELF/Release/IMG_thr_gt2thr_16_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_ELF/Release/IMG_thr_gt2thr_16_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_ELF/Release/IMG_thr_gt2thr_16_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_ELF/Release/IMG_thr_gt2thr_16_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_ELF/Release/IMG_thr_gt2thr_16_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_ELF/Release/IMG_thr_gt2thr_16_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_ELF/Release/IMG_thr_gt2thr_16_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_ELF/Release/IMG_thr_gt2thr_16_66_LE_ELF.out: ./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_ELF/.project
	-@ echo Importing Project IMG_thr_gt2thr_16_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_thr_gt2thr_16_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_gt2thr_16/c66/IMG_thr_gt2thr_16_66_LE_ELF"
	-@ echo Building Project IMG_thr_gt2thr_16_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_thr_gt2thr_16_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_thr_gt2thr_16_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_ELF/.settings"

	-@ echo Project IMG_thr_gt2thr_16_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_thr_gt2thr_16//c66//IMG_thr_gt2thr_16_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_thr_gt2thr_8_66_LE_COFF

#############################################################

all: ./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_COFF/Release/IMG_thr_gt2thr_8_66_LE_COFF.out

./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_thr_gt2thr_8_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_THR_GT2THR_8_66_LE_COFF_SRCIMG_THR_GT2THR_8/IMG_thr_gt2thr_8_cn.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2THR_8_66_LE_COFF_SRCIMG_THR_GT2THR_8/IMG_thr_gt2thr_8_d.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2THR_8_66_LE_COFF_SRCIMG_THR_GT2THR_8/IMG_thr_gt2thr_8_idat.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2THR_8_66_LE_COFF_SRCIMG_THR_GT2THR_8/IMG_thr_gt2thr_8_odat.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2THR_8_66_LE_COFF/IMG_thr_gt2thr_8.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2THR_8_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2THR_8_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2THR_8_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2THR_8_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_THR_GT2THR_8_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_gt2thr_8/c66" -ccs.definePathVariable EXT_ROOT__IMG_THR_GT2THR_8_66_LE_COFF_SRCIMG_THR_GT2THR_8 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_gt2thr_8" -ccs.definePathVariable EXT_ROOT__IMG_THR_GT2THR_8_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_THR_GT2THR_8_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_thr_gt2thr_8.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_THR_GT2THR_8_66_LE_COFF=.././ >> ./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_THR_GT2THR_8_66_LE_COFF_SRCIMG_THR_GT2THR_8=../../ >> ./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_THR_GT2THR_8_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_THR_GT2THR_8_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_COFF/Release/IMG_thr_gt2thr_8_66_LE_COFF.out: ./src/IMG_thr_gt2thr_8/IMG_thr_gt2thr_8.h
./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_COFF/Release/IMG_thr_gt2thr_8_66_LE_COFF.out: ./src/IMG_thr_gt2thr_8/IMG_thr_gt2thr_8_cn.c
./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_COFF/Release/IMG_thr_gt2thr_8_66_LE_COFF.out: ./src/IMG_thr_gt2thr_8/IMG_thr_gt2thr_8_cn.h
./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_COFF/Release/IMG_thr_gt2thr_8_66_LE_COFF.out: ./src/IMG_thr_gt2thr_8/IMG_thr_gt2thr_8_d.c
./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_COFF/Release/IMG_thr_gt2thr_8_66_LE_COFF.out: ./src/IMG_thr_gt2thr_8/IMG_thr_gt2thr_8_idat.c
./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_COFF/Release/IMG_thr_gt2thr_8_66_LE_COFF.out: ./src/IMG_thr_gt2thr_8/IMG_thr_gt2thr_8_odat.c
./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_COFF/Release/IMG_thr_gt2thr_8_66_LE_COFF.out: ./src/IMG_thr_gt2thr_8//c66/IMG_thr_gt2thr_8.c
./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_COFF/Release/IMG_thr_gt2thr_8_66_LE_COFF.out: ./src/IMG_thr_gt2thr_8//c66/IMG_thr_gt2thr_8.h
./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_COFF/Release/IMG_thr_gt2thr_8_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_COFF/Release/IMG_thr_gt2thr_8_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_COFF/Release/IMG_thr_gt2thr_8_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_COFF/Release/IMG_thr_gt2thr_8_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_COFF/Release/IMG_thr_gt2thr_8_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_COFF/Release/IMG_thr_gt2thr_8_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_COFF/Release/IMG_thr_gt2thr_8_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_COFF/Release/IMG_thr_gt2thr_8_66_LE_COFF.out: ./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_COFF/.project
	-@ echo Importing Project IMG_thr_gt2thr_8_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_thr_gt2thr_8_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_gt2thr_8/c66/IMG_thr_gt2thr_8_66_LE_COFF"
	-@ echo Building Project IMG_thr_gt2thr_8_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_thr_gt2thr_8_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_thr_gt2thr_8_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_COFF/.settings"

	-@ echo Project IMG_thr_gt2thr_8_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_thr_gt2thr_8_66_LE_ELF

#############################################################

all: ./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_ELF/Release/IMG_thr_gt2thr_8_66_LE_ELF.out

./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_thr_gt2thr_8_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_THR_GT2THR_8_66_LE_ELF_SRCIMG_THR_GT2THR_8/IMG_thr_gt2thr_8_cn.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2THR_8_66_LE_ELF_SRCIMG_THR_GT2THR_8/IMG_thr_gt2thr_8_d.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2THR_8_66_LE_ELF_SRCIMG_THR_GT2THR_8/IMG_thr_gt2thr_8_idat.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2THR_8_66_LE_ELF_SRCIMG_THR_GT2THR_8/IMG_thr_gt2thr_8_odat.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2THR_8_66_LE_ELF/IMG_thr_gt2thr_8.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2THR_8_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2THR_8_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2THR_8_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_THR_GT2THR_8_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_THR_GT2THR_8_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_gt2thr_8/c66" -ccs.definePathVariable EXT_ROOT__IMG_THR_GT2THR_8_66_LE_ELF_SRCIMG_THR_GT2THR_8 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_gt2thr_8" -ccs.definePathVariable EXT_ROOT__IMG_THR_GT2THR_8_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_THR_GT2THR_8_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_thr_gt2thr_8.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_THR_GT2THR_8_66_LE_ELF=.././ >> ./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_THR_GT2THR_8_66_LE_ELF_SRCIMG_THR_GT2THR_8=../../ >> ./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_THR_GT2THR_8_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_THR_GT2THR_8_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_ELF/Release/IMG_thr_gt2thr_8_66_LE_ELF.out: ./src/IMG_thr_gt2thr_8/IMG_thr_gt2thr_8.h
./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_ELF/Release/IMG_thr_gt2thr_8_66_LE_ELF.out: ./src/IMG_thr_gt2thr_8/IMG_thr_gt2thr_8_cn.c
./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_ELF/Release/IMG_thr_gt2thr_8_66_LE_ELF.out: ./src/IMG_thr_gt2thr_8/IMG_thr_gt2thr_8_cn.h
./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_ELF/Release/IMG_thr_gt2thr_8_66_LE_ELF.out: ./src/IMG_thr_gt2thr_8/IMG_thr_gt2thr_8_d.c
./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_ELF/Release/IMG_thr_gt2thr_8_66_LE_ELF.out: ./src/IMG_thr_gt2thr_8/IMG_thr_gt2thr_8_idat.c
./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_ELF/Release/IMG_thr_gt2thr_8_66_LE_ELF.out: ./src/IMG_thr_gt2thr_8/IMG_thr_gt2thr_8_odat.c
./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_ELF/Release/IMG_thr_gt2thr_8_66_LE_ELF.out: ./src/IMG_thr_gt2thr_8//c66/IMG_thr_gt2thr_8.c
./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_ELF/Release/IMG_thr_gt2thr_8_66_LE_ELF.out: ./src/IMG_thr_gt2thr_8//c66/IMG_thr_gt2thr_8.h
./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_ELF/Release/IMG_thr_gt2thr_8_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_ELF/Release/IMG_thr_gt2thr_8_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_ELF/Release/IMG_thr_gt2thr_8_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_ELF/Release/IMG_thr_gt2thr_8_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_ELF/Release/IMG_thr_gt2thr_8_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_ELF/Release/IMG_thr_gt2thr_8_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_ELF/Release/IMG_thr_gt2thr_8_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_ELF/Release/IMG_thr_gt2thr_8_66_LE_ELF.out: ./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_ELF/.project
	-@ echo Importing Project IMG_thr_gt2thr_8_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_thr_gt2thr_8_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_gt2thr_8/c66/IMG_thr_gt2thr_8_66_LE_ELF"
	-@ echo Building Project IMG_thr_gt2thr_8_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_thr_gt2thr_8_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_thr_gt2thr_8_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_ELF/.settings"

	-@ echo Project IMG_thr_gt2thr_8_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_thr_gt2thr_8//c66//IMG_thr_gt2thr_8_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_thr_le2min_16_66_LE_COFF

#############################################################

all: ./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_COFF/Release/IMG_thr_le2min_16_66_LE_COFF.out

./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_thr_le2min_16_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_THR_LE2MIN_16_66_LE_COFF_SRCIMG_THR_LE2MIN_16/IMG_thr_le2min_16_cn.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2MIN_16_66_LE_COFF_SRCIMG_THR_LE2MIN_16/IMG_thr_le2min_16_d.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2MIN_16_66_LE_COFF_SRCIMG_THR_LE2MIN_16/IMG_thr_le2min_16_idat.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2MIN_16_66_LE_COFF_SRCIMG_THR_LE2MIN_16/IMG_thr_le2min_16_odat.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2MIN_16_66_LE_COFF/IMG_thr_le2min_16.sa -ccs.linkFile EXT_ROOT__IMG_THR_LE2MIN_16_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2MIN_16_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2MIN_16_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2MIN_16_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_THR_LE2MIN_16_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_le2min_16/c66" -ccs.definePathVariable EXT_ROOT__IMG_THR_LE2MIN_16_66_LE_COFF_SRCIMG_THR_LE2MIN_16 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_le2min_16" -ccs.definePathVariable EXT_ROOT__IMG_THR_LE2MIN_16_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_THR_LE2MIN_16_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_thr_le2min_16.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_THR_LE2MIN_16_66_LE_COFF=.././ >> ./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_THR_LE2MIN_16_66_LE_COFF_SRCIMG_THR_LE2MIN_16=../../ >> ./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_THR_LE2MIN_16_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_THR_LE2MIN_16_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_COFF/Release/IMG_thr_le2min_16_66_LE_COFF.out: ./src/IMG_thr_le2min_16/IMG_thr_le2min_16.h
./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_COFF/Release/IMG_thr_le2min_16_66_LE_COFF.out: ./src/IMG_thr_le2min_16/IMG_thr_le2min_16_cn.c
./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_COFF/Release/IMG_thr_le2min_16_66_LE_COFF.out: ./src/IMG_thr_le2min_16/IMG_thr_le2min_16_cn.h
./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_COFF/Release/IMG_thr_le2min_16_66_LE_COFF.out: ./src/IMG_thr_le2min_16/IMG_thr_le2min_16_d.c
./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_COFF/Release/IMG_thr_le2min_16_66_LE_COFF.out: ./src/IMG_thr_le2min_16/IMG_thr_le2min_16_idat.c
./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_COFF/Release/IMG_thr_le2min_16_66_LE_COFF.out: ./src/IMG_thr_le2min_16/IMG_thr_le2min_16_odat.c
./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_COFF/Release/IMG_thr_le2min_16_66_LE_COFF.out: ./src/IMG_thr_le2min_16//c66/IMG_thr_le2min_16.h
./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_COFF/Release/IMG_thr_le2min_16_66_LE_COFF.out: ./src/IMG_thr_le2min_16//c66/IMG_thr_le2min_16.sa
./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_COFF/Release/IMG_thr_le2min_16_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_COFF/Release/IMG_thr_le2min_16_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_COFF/Release/IMG_thr_le2min_16_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_COFF/Release/IMG_thr_le2min_16_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_COFF/Release/IMG_thr_le2min_16_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_COFF/Release/IMG_thr_le2min_16_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_COFF/Release/IMG_thr_le2min_16_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_COFF/Release/IMG_thr_le2min_16_66_LE_COFF.out: ./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_COFF/.project
	-@ echo Importing Project IMG_thr_le2min_16_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_thr_le2min_16_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_le2min_16/c66/IMG_thr_le2min_16_66_LE_COFF"
	-@ echo Building Project IMG_thr_le2min_16_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_thr_le2min_16_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_thr_le2min_16_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_COFF/.settings"

	-@ echo Project IMG_thr_le2min_16_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_thr_le2min_16_66_LE_ELF

#############################################################

all: ./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_ELF/Release/IMG_thr_le2min_16_66_LE_ELF.out

./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_thr_le2min_16_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_THR_LE2MIN_16_66_LE_ELF_SRCIMG_THR_LE2MIN_16/IMG_thr_le2min_16_cn.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2MIN_16_66_LE_ELF_SRCIMG_THR_LE2MIN_16/IMG_thr_le2min_16_d.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2MIN_16_66_LE_ELF_SRCIMG_THR_LE2MIN_16/IMG_thr_le2min_16_idat.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2MIN_16_66_LE_ELF_SRCIMG_THR_LE2MIN_16/IMG_thr_le2min_16_odat.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2MIN_16_66_LE_ELF/IMG_thr_le2min_16.sa -ccs.linkFile EXT_ROOT__IMG_THR_LE2MIN_16_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2MIN_16_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2MIN_16_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2MIN_16_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_THR_LE2MIN_16_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_le2min_16/c66" -ccs.definePathVariable EXT_ROOT__IMG_THR_LE2MIN_16_66_LE_ELF_SRCIMG_THR_LE2MIN_16 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_le2min_16" -ccs.definePathVariable EXT_ROOT__IMG_THR_LE2MIN_16_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_THR_LE2MIN_16_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_thr_le2min_16.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_THR_LE2MIN_16_66_LE_ELF=.././ >> ./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_THR_LE2MIN_16_66_LE_ELF_SRCIMG_THR_LE2MIN_16=../../ >> ./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_THR_LE2MIN_16_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_THR_LE2MIN_16_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_ELF/Release/IMG_thr_le2min_16_66_LE_ELF.out: ./src/IMG_thr_le2min_16/IMG_thr_le2min_16.h
./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_ELF/Release/IMG_thr_le2min_16_66_LE_ELF.out: ./src/IMG_thr_le2min_16/IMG_thr_le2min_16_cn.c
./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_ELF/Release/IMG_thr_le2min_16_66_LE_ELF.out: ./src/IMG_thr_le2min_16/IMG_thr_le2min_16_cn.h
./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_ELF/Release/IMG_thr_le2min_16_66_LE_ELF.out: ./src/IMG_thr_le2min_16/IMG_thr_le2min_16_d.c
./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_ELF/Release/IMG_thr_le2min_16_66_LE_ELF.out: ./src/IMG_thr_le2min_16/IMG_thr_le2min_16_idat.c
./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_ELF/Release/IMG_thr_le2min_16_66_LE_ELF.out: ./src/IMG_thr_le2min_16/IMG_thr_le2min_16_odat.c
./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_ELF/Release/IMG_thr_le2min_16_66_LE_ELF.out: ./src/IMG_thr_le2min_16//c66/IMG_thr_le2min_16.h
./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_ELF/Release/IMG_thr_le2min_16_66_LE_ELF.out: ./src/IMG_thr_le2min_16//c66/IMG_thr_le2min_16.sa
./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_ELF/Release/IMG_thr_le2min_16_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_ELF/Release/IMG_thr_le2min_16_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_ELF/Release/IMG_thr_le2min_16_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_ELF/Release/IMG_thr_le2min_16_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_ELF/Release/IMG_thr_le2min_16_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_ELF/Release/IMG_thr_le2min_16_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_ELF/Release/IMG_thr_le2min_16_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_ELF/Release/IMG_thr_le2min_16_66_LE_ELF.out: ./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_ELF/.project
	-@ echo Importing Project IMG_thr_le2min_16_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_thr_le2min_16_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_le2min_16/c66/IMG_thr_le2min_16_66_LE_ELF"
	-@ echo Building Project IMG_thr_le2min_16_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_thr_le2min_16_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_thr_le2min_16_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_ELF/.settings"

	-@ echo Project IMG_thr_le2min_16_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_thr_le2min_16//c66//IMG_thr_le2min_16_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_thr_le2min_8_66_LE_COFF

#############################################################

all: ./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_COFF/Release/IMG_thr_le2min_8_66_LE_COFF.out

./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_thr_le2min_8_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_THR_LE2MIN_8_66_LE_COFF_SRCIMG_THR_LE2MIN_8/IMG_thr_le2min_8_cn.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2MIN_8_66_LE_COFF_SRCIMG_THR_LE2MIN_8/IMG_thr_le2min_8_d.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2MIN_8_66_LE_COFF_SRCIMG_THR_LE2MIN_8/IMG_thr_le2min_8_idat.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2MIN_8_66_LE_COFF_SRCIMG_THR_LE2MIN_8/IMG_thr_le2min_8_odat.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2MIN_8_66_LE_COFF/IMG_thr_le2min_8.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2MIN_8_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2MIN_8_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2MIN_8_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2MIN_8_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_THR_LE2MIN_8_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_le2min_8/c66" -ccs.definePathVariable EXT_ROOT__IMG_THR_LE2MIN_8_66_LE_COFF_SRCIMG_THR_LE2MIN_8 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_le2min_8" -ccs.definePathVariable EXT_ROOT__IMG_THR_LE2MIN_8_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_THR_LE2MIN_8_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_thr_le2min_8.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_THR_LE2MIN_8_66_LE_COFF=.././ >> ./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_THR_LE2MIN_8_66_LE_COFF_SRCIMG_THR_LE2MIN_8=../../ >> ./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_THR_LE2MIN_8_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_THR_LE2MIN_8_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_COFF/Release/IMG_thr_le2min_8_66_LE_COFF.out: ./src/IMG_thr_le2min_8/IMG_thr_le2min_8.h
./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_COFF/Release/IMG_thr_le2min_8_66_LE_COFF.out: ./src/IMG_thr_le2min_8/IMG_thr_le2min_8_cn.c
./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_COFF/Release/IMG_thr_le2min_8_66_LE_COFF.out: ./src/IMG_thr_le2min_8/IMG_thr_le2min_8_cn.h
./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_COFF/Release/IMG_thr_le2min_8_66_LE_COFF.out: ./src/IMG_thr_le2min_8/IMG_thr_le2min_8_d.c
./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_COFF/Release/IMG_thr_le2min_8_66_LE_COFF.out: ./src/IMG_thr_le2min_8/IMG_thr_le2min_8_idat.c
./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_COFF/Release/IMG_thr_le2min_8_66_LE_COFF.out: ./src/IMG_thr_le2min_8/IMG_thr_le2min_8_odat.c
./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_COFF/Release/IMG_thr_le2min_8_66_LE_COFF.out: ./src/IMG_thr_le2min_8//c66/IMG_thr_le2min_8.c
./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_COFF/Release/IMG_thr_le2min_8_66_LE_COFF.out: ./src/IMG_thr_le2min_8//c66/IMG_thr_le2min_8.h
./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_COFF/Release/IMG_thr_le2min_8_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_COFF/Release/IMG_thr_le2min_8_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_COFF/Release/IMG_thr_le2min_8_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_COFF/Release/IMG_thr_le2min_8_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_COFF/Release/IMG_thr_le2min_8_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_COFF/Release/IMG_thr_le2min_8_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_COFF/Release/IMG_thr_le2min_8_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_COFF/Release/IMG_thr_le2min_8_66_LE_COFF.out: ./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_COFF/.project
	-@ echo Importing Project IMG_thr_le2min_8_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_thr_le2min_8_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_le2min_8/c66/IMG_thr_le2min_8_66_LE_COFF"
	-@ echo Building Project IMG_thr_le2min_8_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_thr_le2min_8_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_thr_le2min_8_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_COFF/.settings"

	-@ echo Project IMG_thr_le2min_8_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_thr_le2min_8_66_LE_ELF

#############################################################

all: ./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_ELF/Release/IMG_thr_le2min_8_66_LE_ELF.out

./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_thr_le2min_8_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_THR_LE2MIN_8_66_LE_ELF_SRCIMG_THR_LE2MIN_8/IMG_thr_le2min_8_cn.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2MIN_8_66_LE_ELF_SRCIMG_THR_LE2MIN_8/IMG_thr_le2min_8_d.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2MIN_8_66_LE_ELF_SRCIMG_THR_LE2MIN_8/IMG_thr_le2min_8_idat.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2MIN_8_66_LE_ELF_SRCIMG_THR_LE2MIN_8/IMG_thr_le2min_8_odat.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2MIN_8_66_LE_ELF/IMG_thr_le2min_8.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2MIN_8_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2MIN_8_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2MIN_8_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2MIN_8_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_THR_LE2MIN_8_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_le2min_8/c66" -ccs.definePathVariable EXT_ROOT__IMG_THR_LE2MIN_8_66_LE_ELF_SRCIMG_THR_LE2MIN_8 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_le2min_8" -ccs.definePathVariable EXT_ROOT__IMG_THR_LE2MIN_8_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_THR_LE2MIN_8_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_thr_le2min_8.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_THR_LE2MIN_8_66_LE_ELF=.././ >> ./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_THR_LE2MIN_8_66_LE_ELF_SRCIMG_THR_LE2MIN_8=../../ >> ./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_THR_LE2MIN_8_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_THR_LE2MIN_8_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_ELF/Release/IMG_thr_le2min_8_66_LE_ELF.out: ./src/IMG_thr_le2min_8/IMG_thr_le2min_8.h
./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_ELF/Release/IMG_thr_le2min_8_66_LE_ELF.out: ./src/IMG_thr_le2min_8/IMG_thr_le2min_8_cn.c
./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_ELF/Release/IMG_thr_le2min_8_66_LE_ELF.out: ./src/IMG_thr_le2min_8/IMG_thr_le2min_8_cn.h
./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_ELF/Release/IMG_thr_le2min_8_66_LE_ELF.out: ./src/IMG_thr_le2min_8/IMG_thr_le2min_8_d.c
./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_ELF/Release/IMG_thr_le2min_8_66_LE_ELF.out: ./src/IMG_thr_le2min_8/IMG_thr_le2min_8_idat.c
./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_ELF/Release/IMG_thr_le2min_8_66_LE_ELF.out: ./src/IMG_thr_le2min_8/IMG_thr_le2min_8_odat.c
./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_ELF/Release/IMG_thr_le2min_8_66_LE_ELF.out: ./src/IMG_thr_le2min_8//c66/IMG_thr_le2min_8.c
./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_ELF/Release/IMG_thr_le2min_8_66_LE_ELF.out: ./src/IMG_thr_le2min_8//c66/IMG_thr_le2min_8.h
./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_ELF/Release/IMG_thr_le2min_8_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_ELF/Release/IMG_thr_le2min_8_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_ELF/Release/IMG_thr_le2min_8_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_ELF/Release/IMG_thr_le2min_8_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_ELF/Release/IMG_thr_le2min_8_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_ELF/Release/IMG_thr_le2min_8_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_ELF/Release/IMG_thr_le2min_8_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_ELF/Release/IMG_thr_le2min_8_66_LE_ELF.out: ./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_ELF/.project
	-@ echo Importing Project IMG_thr_le2min_8_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_thr_le2min_8_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_le2min_8/c66/IMG_thr_le2min_8_66_LE_ELF"
	-@ echo Building Project IMG_thr_le2min_8_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_thr_le2min_8_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_thr_le2min_8_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_ELF/.settings"

	-@ echo Project IMG_thr_le2min_8_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_thr_le2min_8//c66//IMG_thr_le2min_8_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_thr_le2thr_16_66_LE_COFF

#############################################################

all: ./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_COFF/Release/IMG_thr_le2thr_16_66_LE_COFF.out

./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_thr_le2thr_16_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_THR_LE2THR_16_66_LE_COFF_SRCIMG_THR_LE2THR_16/IMG_thr_le2thr_16_cn.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2THR_16_66_LE_COFF_SRCIMG_THR_LE2THR_16/IMG_thr_le2thr_16_d.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2THR_16_66_LE_COFF_SRCIMG_THR_LE2THR_16/IMG_thr_le2thr_16_idat.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2THR_16_66_LE_COFF_SRCIMG_THR_LE2THR_16/IMG_thr_le2thr_16_odat.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2THR_16_66_LE_COFF/IMG_thr_le2thr_16.sa -ccs.linkFile EXT_ROOT__IMG_THR_LE2THR_16_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2THR_16_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2THR_16_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2THR_16_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_THR_LE2THR_16_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_le2thr_16/c66" -ccs.definePathVariable EXT_ROOT__IMG_THR_LE2THR_16_66_LE_COFF_SRCIMG_THR_LE2THR_16 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_le2thr_16" -ccs.definePathVariable EXT_ROOT__IMG_THR_LE2THR_16_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_THR_LE2THR_16_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_thr_le2thr_16.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_THR_LE2THR_16_66_LE_COFF=.././ >> ./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_THR_LE2THR_16_66_LE_COFF_SRCIMG_THR_LE2THR_16=../../ >> ./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_THR_LE2THR_16_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_THR_LE2THR_16_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_COFF/Release/IMG_thr_le2thr_16_66_LE_COFF.out: ./src/IMG_thr_le2thr_16/IMG_thr_le2thr_16.h
./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_COFF/Release/IMG_thr_le2thr_16_66_LE_COFF.out: ./src/IMG_thr_le2thr_16/IMG_thr_le2thr_16_cn.c
./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_COFF/Release/IMG_thr_le2thr_16_66_LE_COFF.out: ./src/IMG_thr_le2thr_16/IMG_thr_le2thr_16_cn.h
./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_COFF/Release/IMG_thr_le2thr_16_66_LE_COFF.out: ./src/IMG_thr_le2thr_16/IMG_thr_le2thr_16_d.c
./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_COFF/Release/IMG_thr_le2thr_16_66_LE_COFF.out: ./src/IMG_thr_le2thr_16/IMG_thr_le2thr_16_idat.c
./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_COFF/Release/IMG_thr_le2thr_16_66_LE_COFF.out: ./src/IMG_thr_le2thr_16/IMG_thr_le2thr_16_odat.c
./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_COFF/Release/IMG_thr_le2thr_16_66_LE_COFF.out: ./src/IMG_thr_le2thr_16//c66/IMG_thr_le2thr_16.h
./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_COFF/Release/IMG_thr_le2thr_16_66_LE_COFF.out: ./src/IMG_thr_le2thr_16//c66/IMG_thr_le2thr_16.sa
./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_COFF/Release/IMG_thr_le2thr_16_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_COFF/Release/IMG_thr_le2thr_16_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_COFF/Release/IMG_thr_le2thr_16_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_COFF/Release/IMG_thr_le2thr_16_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_COFF/Release/IMG_thr_le2thr_16_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_COFF/Release/IMG_thr_le2thr_16_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_COFF/Release/IMG_thr_le2thr_16_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_COFF/Release/IMG_thr_le2thr_16_66_LE_COFF.out: ./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_COFF/.project
	-@ echo Importing Project IMG_thr_le2thr_16_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_thr_le2thr_16_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_le2thr_16/c66/IMG_thr_le2thr_16_66_LE_COFF"
	-@ echo Building Project IMG_thr_le2thr_16_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_thr_le2thr_16_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_thr_le2thr_16_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_COFF/.settings"

	-@ echo Project IMG_thr_le2thr_16_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_thr_le2thr_16_66_LE_ELF

#############################################################

all: ./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_ELF/Release/IMG_thr_le2thr_16_66_LE_ELF.out

./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_thr_le2thr_16_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_THR_LE2THR_16_66_LE_ELF_SRCIMG_THR_LE2THR_16/IMG_thr_le2thr_16_cn.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2THR_16_66_LE_ELF_SRCIMG_THR_LE2THR_16/IMG_thr_le2thr_16_d.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2THR_16_66_LE_ELF_SRCIMG_THR_LE2THR_16/IMG_thr_le2thr_16_idat.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2THR_16_66_LE_ELF_SRCIMG_THR_LE2THR_16/IMG_thr_le2thr_16_odat.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2THR_16_66_LE_ELF/IMG_thr_le2thr_16.sa -ccs.linkFile EXT_ROOT__IMG_THR_LE2THR_16_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2THR_16_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2THR_16_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2THR_16_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_THR_LE2THR_16_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_le2thr_16/c66" -ccs.definePathVariable EXT_ROOT__IMG_THR_LE2THR_16_66_LE_ELF_SRCIMG_THR_LE2THR_16 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_le2thr_16" -ccs.definePathVariable EXT_ROOT__IMG_THR_LE2THR_16_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_THR_LE2THR_16_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_thr_le2thr_16.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_THR_LE2THR_16_66_LE_ELF=.././ >> ./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_THR_LE2THR_16_66_LE_ELF_SRCIMG_THR_LE2THR_16=../../ >> ./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_THR_LE2THR_16_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_THR_LE2THR_16_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_ELF/Release/IMG_thr_le2thr_16_66_LE_ELF.out: ./src/IMG_thr_le2thr_16/IMG_thr_le2thr_16.h
./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_ELF/Release/IMG_thr_le2thr_16_66_LE_ELF.out: ./src/IMG_thr_le2thr_16/IMG_thr_le2thr_16_cn.c
./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_ELF/Release/IMG_thr_le2thr_16_66_LE_ELF.out: ./src/IMG_thr_le2thr_16/IMG_thr_le2thr_16_cn.h
./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_ELF/Release/IMG_thr_le2thr_16_66_LE_ELF.out: ./src/IMG_thr_le2thr_16/IMG_thr_le2thr_16_d.c
./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_ELF/Release/IMG_thr_le2thr_16_66_LE_ELF.out: ./src/IMG_thr_le2thr_16/IMG_thr_le2thr_16_idat.c
./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_ELF/Release/IMG_thr_le2thr_16_66_LE_ELF.out: ./src/IMG_thr_le2thr_16/IMG_thr_le2thr_16_odat.c
./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_ELF/Release/IMG_thr_le2thr_16_66_LE_ELF.out: ./src/IMG_thr_le2thr_16//c66/IMG_thr_le2thr_16.h
./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_ELF/Release/IMG_thr_le2thr_16_66_LE_ELF.out: ./src/IMG_thr_le2thr_16//c66/IMG_thr_le2thr_16.sa
./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_ELF/Release/IMG_thr_le2thr_16_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_ELF/Release/IMG_thr_le2thr_16_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_ELF/Release/IMG_thr_le2thr_16_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_ELF/Release/IMG_thr_le2thr_16_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_ELF/Release/IMG_thr_le2thr_16_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_ELF/Release/IMG_thr_le2thr_16_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_ELF/Release/IMG_thr_le2thr_16_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_ELF/Release/IMG_thr_le2thr_16_66_LE_ELF.out: ./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_ELF/.project
	-@ echo Importing Project IMG_thr_le2thr_16_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_thr_le2thr_16_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_le2thr_16/c66/IMG_thr_le2thr_16_66_LE_ELF"
	-@ echo Building Project IMG_thr_le2thr_16_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_thr_le2thr_16_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_thr_le2thr_16_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_ELF/.settings"

	-@ echo Project IMG_thr_le2thr_16_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_thr_le2thr_16//c66//IMG_thr_le2thr_16_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_thr_le2thr_8_66_LE_COFF

#############################################################

all: ./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_COFF/Release/IMG_thr_le2thr_8_66_LE_COFF.out

./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_thr_le2thr_8_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_THR_LE2THR_8_66_LE_COFF_SRCIMG_THR_LE2THR_8/IMG_thr_le2thr_8_cn.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2THR_8_66_LE_COFF_SRCIMG_THR_LE2THR_8/IMG_thr_le2thr_8_d.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2THR_8_66_LE_COFF_SRCIMG_THR_LE2THR_8/IMG_thr_le2thr_8_idat.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2THR_8_66_LE_COFF_SRCIMG_THR_LE2THR_8/IMG_thr_le2thr_8_odat.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2THR_8_66_LE_COFF/IMG_thr_le2thr_8.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2THR_8_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2THR_8_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2THR_8_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2THR_8_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_THR_LE2THR_8_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_le2thr_8/c66" -ccs.definePathVariable EXT_ROOT__IMG_THR_LE2THR_8_66_LE_COFF_SRCIMG_THR_LE2THR_8 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_le2thr_8" -ccs.definePathVariable EXT_ROOT__IMG_THR_LE2THR_8_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_THR_LE2THR_8_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_thr_le2thr_8.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_THR_LE2THR_8_66_LE_COFF=.././ >> ./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_THR_LE2THR_8_66_LE_COFF_SRCIMG_THR_LE2THR_8=../../ >> ./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_THR_LE2THR_8_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_THR_LE2THR_8_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_COFF/Release/IMG_thr_le2thr_8_66_LE_COFF.out: ./src/IMG_thr_le2thr_8/IMG_thr_le2thr_8.h
./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_COFF/Release/IMG_thr_le2thr_8_66_LE_COFF.out: ./src/IMG_thr_le2thr_8/IMG_thr_le2thr_8_cn.c
./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_COFF/Release/IMG_thr_le2thr_8_66_LE_COFF.out: ./src/IMG_thr_le2thr_8/IMG_thr_le2thr_8_cn.h
./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_COFF/Release/IMG_thr_le2thr_8_66_LE_COFF.out: ./src/IMG_thr_le2thr_8/IMG_thr_le2thr_8_d.c
./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_COFF/Release/IMG_thr_le2thr_8_66_LE_COFF.out: ./src/IMG_thr_le2thr_8/IMG_thr_le2thr_8_idat.c
./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_COFF/Release/IMG_thr_le2thr_8_66_LE_COFF.out: ./src/IMG_thr_le2thr_8/IMG_thr_le2thr_8_odat.c
./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_COFF/Release/IMG_thr_le2thr_8_66_LE_COFF.out: ./src/IMG_thr_le2thr_8//c66/IMG_thr_le2thr_8.c
./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_COFF/Release/IMG_thr_le2thr_8_66_LE_COFF.out: ./src/IMG_thr_le2thr_8//c66/IMG_thr_le2thr_8.h
./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_COFF/Release/IMG_thr_le2thr_8_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_COFF/Release/IMG_thr_le2thr_8_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_COFF/Release/IMG_thr_le2thr_8_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_COFF/Release/IMG_thr_le2thr_8_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_COFF/Release/IMG_thr_le2thr_8_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_COFF/Release/IMG_thr_le2thr_8_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_COFF/Release/IMG_thr_le2thr_8_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_COFF/Release/IMG_thr_le2thr_8_66_LE_COFF.out: ./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_COFF/.project
	-@ echo Importing Project IMG_thr_le2thr_8_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_thr_le2thr_8_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_le2thr_8/c66/IMG_thr_le2thr_8_66_LE_COFF"
	-@ echo Building Project IMG_thr_le2thr_8_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_thr_le2thr_8_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_thr_le2thr_8_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_COFF/.settings"

	-@ echo Project IMG_thr_le2thr_8_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_thr_le2thr_8_66_LE_ELF

#############################################################

all: ./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_ELF/Release/IMG_thr_le2thr_8_66_LE_ELF.out

./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_thr_le2thr_8_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_THR_LE2THR_8_66_LE_ELF_SRCIMG_THR_LE2THR_8/IMG_thr_le2thr_8_cn.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2THR_8_66_LE_ELF_SRCIMG_THR_LE2THR_8/IMG_thr_le2thr_8_d.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2THR_8_66_LE_ELF_SRCIMG_THR_LE2THR_8/IMG_thr_le2thr_8_idat.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2THR_8_66_LE_ELF_SRCIMG_THR_LE2THR_8/IMG_thr_le2thr_8_odat.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2THR_8_66_LE_ELF/IMG_thr_le2thr_8.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2THR_8_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2THR_8_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2THR_8_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_THR_LE2THR_8_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_THR_LE2THR_8_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_le2thr_8/c66" -ccs.definePathVariable EXT_ROOT__IMG_THR_LE2THR_8_66_LE_ELF_SRCIMG_THR_LE2THR_8 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_le2thr_8" -ccs.definePathVariable EXT_ROOT__IMG_THR_LE2THR_8_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_THR_LE2THR_8_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_thr_le2thr_8.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_THR_LE2THR_8_66_LE_ELF=.././ >> ./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_THR_LE2THR_8_66_LE_ELF_SRCIMG_THR_LE2THR_8=../../ >> ./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_THR_LE2THR_8_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_THR_LE2THR_8_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_ELF/Release/IMG_thr_le2thr_8_66_LE_ELF.out: ./src/IMG_thr_le2thr_8/IMG_thr_le2thr_8.h
./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_ELF/Release/IMG_thr_le2thr_8_66_LE_ELF.out: ./src/IMG_thr_le2thr_8/IMG_thr_le2thr_8_cn.c
./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_ELF/Release/IMG_thr_le2thr_8_66_LE_ELF.out: ./src/IMG_thr_le2thr_8/IMG_thr_le2thr_8_cn.h
./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_ELF/Release/IMG_thr_le2thr_8_66_LE_ELF.out: ./src/IMG_thr_le2thr_8/IMG_thr_le2thr_8_d.c
./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_ELF/Release/IMG_thr_le2thr_8_66_LE_ELF.out: ./src/IMG_thr_le2thr_8/IMG_thr_le2thr_8_idat.c
./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_ELF/Release/IMG_thr_le2thr_8_66_LE_ELF.out: ./src/IMG_thr_le2thr_8/IMG_thr_le2thr_8_odat.c
./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_ELF/Release/IMG_thr_le2thr_8_66_LE_ELF.out: ./src/IMG_thr_le2thr_8//c66/IMG_thr_le2thr_8.c
./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_ELF/Release/IMG_thr_le2thr_8_66_LE_ELF.out: ./src/IMG_thr_le2thr_8//c66/IMG_thr_le2thr_8.h
./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_ELF/Release/IMG_thr_le2thr_8_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_ELF/Release/IMG_thr_le2thr_8_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_ELF/Release/IMG_thr_le2thr_8_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_ELF/Release/IMG_thr_le2thr_8_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_ELF/Release/IMG_thr_le2thr_8_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_ELF/Release/IMG_thr_le2thr_8_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_ELF/Release/IMG_thr_le2thr_8_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_ELF/Release/IMG_thr_le2thr_8_66_LE_ELF.out: ./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_ELF/.project
	-@ echo Importing Project IMG_thr_le2thr_8_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_thr_le2thr_8_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_thr_le2thr_8/c66/IMG_thr_le2thr_8_66_LE_ELF"
	-@ echo Building Project IMG_thr_le2thr_8_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_thr_le2thr_8_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_thr_le2thr_8_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_ELF/.settings"

	-@ echo Project IMG_thr_le2thr_8_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_thr_le2thr_8//c66//IMG_thr_le2thr_8_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_wave_horz_66_LE_COFF

#############################################################

all: ./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_COFF/Release/IMG_wave_horz_66_LE_COFF.out

./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_wave_horz_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_WAVE_HORZ_66_LE_COFF_SRCIMG_WAVE_HORZ/IMG_wave_horz_cn.c -ccs.linkFile EXT_ROOT__IMG_WAVE_HORZ_66_LE_COFF_SRCIMG_WAVE_HORZ/IMG_wave_horz_d.c -ccs.linkFile EXT_ROOT__IMG_WAVE_HORZ_66_LE_COFF/IMG_wave_horz.sa -ccs.linkFile EXT_ROOT__IMG_WAVE_HORZ_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_WAVE_HORZ_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_WAVE_HORZ_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_WAVE_HORZ_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_WAVE_HORZ_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_wave_horz/c66" -ccs.definePathVariable EXT_ROOT__IMG_WAVE_HORZ_66_LE_COFF_SRCIMG_WAVE_HORZ "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_wave_horz" -ccs.definePathVariable EXT_ROOT__IMG_WAVE_HORZ_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_WAVE_HORZ_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_wave_horz.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_WAVE_HORZ_66_LE_COFF=.././ >> ./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_WAVE_HORZ_66_LE_COFF_SRCIMG_WAVE_HORZ=../../ >> ./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_WAVE_HORZ_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_WAVE_HORZ_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_COFF/Release/IMG_wave_horz_66_LE_COFF.out: ./src/IMG_wave_horz/IMG_wave_horz.h
./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_COFF/Release/IMG_wave_horz_66_LE_COFF.out: ./src/IMG_wave_horz/IMG_wave_horz_cn.c
./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_COFF/Release/IMG_wave_horz_66_LE_COFF.out: ./src/IMG_wave_horz/IMG_wave_horz_cn.h
./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_COFF/Release/IMG_wave_horz_66_LE_COFF.out: ./src/IMG_wave_horz/IMG_wave_horz_d.c
./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_COFF/Release/IMG_wave_horz_66_LE_COFF.out: ./src/IMG_wave_horz//c66/IMG_wave_horz.h
./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_COFF/Release/IMG_wave_horz_66_LE_COFF.out: ./src/IMG_wave_horz//c66/IMG_wave_horz.sa
./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_COFF/Release/IMG_wave_horz_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_COFF/Release/IMG_wave_horz_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_COFF/Release/IMG_wave_horz_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_COFF/Release/IMG_wave_horz_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_COFF/Release/IMG_wave_horz_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_COFF/Release/IMG_wave_horz_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_COFF/Release/IMG_wave_horz_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_COFF/Release/IMG_wave_horz_66_LE_COFF.out: ./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_COFF/.project
	-@ echo Importing Project IMG_wave_horz_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_wave_horz_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_wave_horz/c66/IMG_wave_horz_66_LE_COFF"
	-@ echo Building Project IMG_wave_horz_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_wave_horz_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_wave_horz_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_COFF/.settings"

	-@ echo Project IMG_wave_horz_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_wave_horz_66_LE_ELF

#############################################################

all: ./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_ELF/Release/IMG_wave_horz_66_LE_ELF.out

./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_wave_horz_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_WAVE_HORZ_66_LE_ELF_SRCIMG_WAVE_HORZ/IMG_wave_horz_cn.c -ccs.linkFile EXT_ROOT__IMG_WAVE_HORZ_66_LE_ELF_SRCIMG_WAVE_HORZ/IMG_wave_horz_d.c -ccs.linkFile EXT_ROOT__IMG_WAVE_HORZ_66_LE_ELF/IMG_wave_horz.sa -ccs.linkFile EXT_ROOT__IMG_WAVE_HORZ_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_WAVE_HORZ_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_WAVE_HORZ_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_WAVE_HORZ_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_WAVE_HORZ_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_wave_horz/c66" -ccs.definePathVariable EXT_ROOT__IMG_WAVE_HORZ_66_LE_ELF_SRCIMG_WAVE_HORZ "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_wave_horz" -ccs.definePathVariable EXT_ROOT__IMG_WAVE_HORZ_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_WAVE_HORZ_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_wave_horz.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_WAVE_HORZ_66_LE_ELF=.././ >> ./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_WAVE_HORZ_66_LE_ELF_SRCIMG_WAVE_HORZ=../../ >> ./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_WAVE_HORZ_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_WAVE_HORZ_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_ELF/Release/IMG_wave_horz_66_LE_ELF.out: ./src/IMG_wave_horz/IMG_wave_horz.h
./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_ELF/Release/IMG_wave_horz_66_LE_ELF.out: ./src/IMG_wave_horz/IMG_wave_horz_cn.c
./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_ELF/Release/IMG_wave_horz_66_LE_ELF.out: ./src/IMG_wave_horz/IMG_wave_horz_cn.h
./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_ELF/Release/IMG_wave_horz_66_LE_ELF.out: ./src/IMG_wave_horz/IMG_wave_horz_d.c
./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_ELF/Release/IMG_wave_horz_66_LE_ELF.out: ./src/IMG_wave_horz//c66/IMG_wave_horz.h
./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_ELF/Release/IMG_wave_horz_66_LE_ELF.out: ./src/IMG_wave_horz//c66/IMG_wave_horz.sa
./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_ELF/Release/IMG_wave_horz_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_ELF/Release/IMG_wave_horz_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_ELF/Release/IMG_wave_horz_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_ELF/Release/IMG_wave_horz_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_ELF/Release/IMG_wave_horz_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_ELF/Release/IMG_wave_horz_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_ELF/Release/IMG_wave_horz_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_ELF/Release/IMG_wave_horz_66_LE_ELF.out: ./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_ELF/.project
	-@ echo Importing Project IMG_wave_horz_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_wave_horz_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_wave_horz/c66/IMG_wave_horz_66_LE_ELF"
	-@ echo Building Project IMG_wave_horz_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_wave_horz_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_wave_horz_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_ELF/.settings"

	-@ echo Project IMG_wave_horz_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_wave_horz//c66//IMG_wave_horz_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_wave_vert_66_LE_COFF

#############################################################

all: ./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_COFF/Release/IMG_wave_vert_66_LE_COFF.out

./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_wave_vert_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_WAVE_VERT_66_LE_COFF_SRCIMG_WAVE_VERT/IMG_wave_vert_cn.c -ccs.linkFile EXT_ROOT__IMG_WAVE_VERT_66_LE_COFF_SRCIMG_WAVE_VERT/IMG_wave_vert_d.c -ccs.linkFile EXT_ROOT__IMG_WAVE_VERT_66_LE_COFF/IMG_wave_vert.sa -ccs.linkFile EXT_ROOT__IMG_WAVE_VERT_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_WAVE_VERT_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_WAVE_VERT_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_WAVE_VERT_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_WAVE_VERT_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_wave_vert/c66" -ccs.definePathVariable EXT_ROOT__IMG_WAVE_VERT_66_LE_COFF_SRCIMG_WAVE_VERT "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_wave_vert" -ccs.definePathVariable EXT_ROOT__IMG_WAVE_VERT_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_WAVE_VERT_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_wave_vert.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_WAVE_VERT_66_LE_COFF=.././ >> ./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_WAVE_VERT_66_LE_COFF_SRCIMG_WAVE_VERT=../../ >> ./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_WAVE_VERT_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_WAVE_VERT_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_COFF/Release/IMG_wave_vert_66_LE_COFF.out: ./src/IMG_wave_vert/IMG_wave_vert.h
./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_COFF/Release/IMG_wave_vert_66_LE_COFF.out: ./src/IMG_wave_vert/IMG_wave_vert_cn.c
./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_COFF/Release/IMG_wave_vert_66_LE_COFF.out: ./src/IMG_wave_vert/IMG_wave_vert_cn.h
./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_COFF/Release/IMG_wave_vert_66_LE_COFF.out: ./src/IMG_wave_vert/IMG_wave_vert_d.c
./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_COFF/Release/IMG_wave_vert_66_LE_COFF.out: ./src/IMG_wave_vert//c66/IMG_wave_vert.h
./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_COFF/Release/IMG_wave_vert_66_LE_COFF.out: ./src/IMG_wave_vert//c66/IMG_wave_vert.sa
./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_COFF/Release/IMG_wave_vert_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_COFF/Release/IMG_wave_vert_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_COFF/Release/IMG_wave_vert_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_COFF/Release/IMG_wave_vert_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_COFF/Release/IMG_wave_vert_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_COFF/Release/IMG_wave_vert_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_COFF/Release/IMG_wave_vert_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_COFF/Release/IMG_wave_vert_66_LE_COFF.out: ./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_COFF/.project
	-@ echo Importing Project IMG_wave_vert_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_wave_vert_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_wave_vert/c66/IMG_wave_vert_66_LE_COFF"
	-@ echo Building Project IMG_wave_vert_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_wave_vert_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_wave_vert_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_COFF/.settings"

	-@ echo Project IMG_wave_vert_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_wave_vert_66_LE_ELF

#############################################################

all: ./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_ELF/Release/IMG_wave_vert_66_LE_ELF.out

./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_wave_vert_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_WAVE_VERT_66_LE_ELF_SRCIMG_WAVE_VERT/IMG_wave_vert_cn.c -ccs.linkFile EXT_ROOT__IMG_WAVE_VERT_66_LE_ELF_SRCIMG_WAVE_VERT/IMG_wave_vert_d.c -ccs.linkFile EXT_ROOT__IMG_WAVE_VERT_66_LE_ELF/IMG_wave_vert.sa -ccs.linkFile EXT_ROOT__IMG_WAVE_VERT_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_WAVE_VERT_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_WAVE_VERT_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_WAVE_VERT_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_WAVE_VERT_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_wave_vert/c66" -ccs.definePathVariable EXT_ROOT__IMG_WAVE_VERT_66_LE_ELF_SRCIMG_WAVE_VERT "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_wave_vert" -ccs.definePathVariable EXT_ROOT__IMG_WAVE_VERT_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_WAVE_VERT_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_wave_vert.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_WAVE_VERT_66_LE_ELF=.././ >> ./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_WAVE_VERT_66_LE_ELF_SRCIMG_WAVE_VERT=../../ >> ./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_WAVE_VERT_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_WAVE_VERT_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_ELF/Release/IMG_wave_vert_66_LE_ELF.out: ./src/IMG_wave_vert/IMG_wave_vert.h
./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_ELF/Release/IMG_wave_vert_66_LE_ELF.out: ./src/IMG_wave_vert/IMG_wave_vert_cn.c
./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_ELF/Release/IMG_wave_vert_66_LE_ELF.out: ./src/IMG_wave_vert/IMG_wave_vert_cn.h
./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_ELF/Release/IMG_wave_vert_66_LE_ELF.out: ./src/IMG_wave_vert/IMG_wave_vert_d.c
./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_ELF/Release/IMG_wave_vert_66_LE_ELF.out: ./src/IMG_wave_vert//c66/IMG_wave_vert.h
./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_ELF/Release/IMG_wave_vert_66_LE_ELF.out: ./src/IMG_wave_vert//c66/IMG_wave_vert.sa
./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_ELF/Release/IMG_wave_vert_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_ELF/Release/IMG_wave_vert_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_ELF/Release/IMG_wave_vert_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_ELF/Release/IMG_wave_vert_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_ELF/Release/IMG_wave_vert_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_ELF/Release/IMG_wave_vert_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_ELF/Release/IMG_wave_vert_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_ELF/Release/IMG_wave_vert_66_LE_ELF.out: ./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_ELF/.project
	-@ echo Importing Project IMG_wave_vert_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_wave_vert_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_wave_vert/c66/IMG_wave_vert_66_LE_ELF"
	-@ echo Building Project IMG_wave_vert_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_wave_vert_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_wave_vert_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_ELF/.settings"

	-@ echo Project IMG_wave_vert_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_wave_vert//c66//IMG_wave_vert_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_ycbcr422pl_to_rgb565_66_LE_COFF

#############################################################

all: ./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_COFF/Release/IMG_ycbcr422pl_to_rgb565_66_LE_COFF.out

./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_ycbcr422pl_to_rgb565_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_YCBCR422PL_TO_RGB565_66_LE_COFF_SRCIMG_YCBCR422PL_TO_RGB565/IMG_ycbcr422pl_to_rgb565_cn.c -ccs.linkFile EXT_ROOT__IMG_YCBCR422PL_TO_RGB565_66_LE_COFF_SRCIMG_YCBCR422PL_TO_RGB565/IMG_ycbcr422pl_to_rgb565_d.c -ccs.linkFile EXT_ROOT__IMG_YCBCR422PL_TO_RGB565_66_LE_COFF_SRCIMG_YCBCR422PL_TO_RGB565/IMG_ycbcr422pl_to_rgb565_idat.c -ccs.linkFile EXT_ROOT__IMG_YCBCR422PL_TO_RGB565_66_LE_COFF_SRCIMG_YCBCR422PL_TO_RGB565/IMG_ycbcr422pl_to_rgb565_odat.c -ccs.linkFile EXT_ROOT__IMG_YCBCR422PL_TO_RGB565_66_LE_COFF/IMG_ycbcr422pl_to_rgb565.c -ccs.linkFile EXT_ROOT__IMG_YCBCR422PL_TO_RGB565_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_YCBCR422PL_TO_RGB565_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_YCBCR422PL_TO_RGB565_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_YCBCR422PL_TO_RGB565_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_YCBCR422PL_TO_RGB565_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_ycbcr422pl_to_rgb565/c66" -ccs.definePathVariable EXT_ROOT__IMG_YCBCR422PL_TO_RGB565_66_LE_COFF_SRCIMG_YCBCR422PL_TO_RGB565 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_ycbcr422pl_to_rgb565" -ccs.definePathVariable EXT_ROOT__IMG_YCBCR422PL_TO_RGB565_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_YCBCR422PL_TO_RGB565_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_ycbcr422pl_to_rgb565.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_YCBCR422PL_TO_RGB565_66_LE_COFF=.././ >> ./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_YCBCR422PL_TO_RGB565_66_LE_COFF_SRCIMG_YCBCR422PL_TO_RGB565=../../ >> ./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_YCBCR422PL_TO_RGB565_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_YCBCR422PL_TO_RGB565_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_COFF/Release/IMG_ycbcr422pl_to_rgb565_66_LE_COFF.out: ./src/IMG_ycbcr422pl_to_rgb565/IMG_ycbcr422pl_to_rgb565.h
./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_COFF/Release/IMG_ycbcr422pl_to_rgb565_66_LE_COFF.out: ./src/IMG_ycbcr422pl_to_rgb565/IMG_ycbcr422pl_to_rgb565_cn.c
./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_COFF/Release/IMG_ycbcr422pl_to_rgb565_66_LE_COFF.out: ./src/IMG_ycbcr422pl_to_rgb565/IMG_ycbcr422pl_to_rgb565_cn.h
./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_COFF/Release/IMG_ycbcr422pl_to_rgb565_66_LE_COFF.out: ./src/IMG_ycbcr422pl_to_rgb565/IMG_ycbcr422pl_to_rgb565_d.c
./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_COFF/Release/IMG_ycbcr422pl_to_rgb565_66_LE_COFF.out: ./src/IMG_ycbcr422pl_to_rgb565/IMG_ycbcr422pl_to_rgb565_idat.c
./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_COFF/Release/IMG_ycbcr422pl_to_rgb565_66_LE_COFF.out: ./src/IMG_ycbcr422pl_to_rgb565/IMG_ycbcr422pl_to_rgb565_odat.c
./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_COFF/Release/IMG_ycbcr422pl_to_rgb565_66_LE_COFF.out: ./src/IMG_ycbcr422pl_to_rgb565//c66/IMG_ycbcr422pl_to_rgb565.c
./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_COFF/Release/IMG_ycbcr422pl_to_rgb565_66_LE_COFF.out: ./src/IMG_ycbcr422pl_to_rgb565//c66/IMG_ycbcr422pl_to_rgb565.h
./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_COFF/Release/IMG_ycbcr422pl_to_rgb565_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_COFF/Release/IMG_ycbcr422pl_to_rgb565_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_COFF/Release/IMG_ycbcr422pl_to_rgb565_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_COFF/Release/IMG_ycbcr422pl_to_rgb565_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_COFF/Release/IMG_ycbcr422pl_to_rgb565_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_COFF/Release/IMG_ycbcr422pl_to_rgb565_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_COFF/Release/IMG_ycbcr422pl_to_rgb565_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_COFF/Release/IMG_ycbcr422pl_to_rgb565_66_LE_COFF.out: ./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_COFF/.project
	-@ echo Importing Project IMG_ycbcr422pl_to_rgb565_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_ycbcr422pl_to_rgb565_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_ycbcr422pl_to_rgb565/c66/IMG_ycbcr422pl_to_rgb565_66_LE_COFF"
	-@ echo Building Project IMG_ycbcr422pl_to_rgb565_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_ycbcr422pl_to_rgb565_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_ycbcr422pl_to_rgb565_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_COFF/.settings"

	-@ echo Project IMG_ycbcr422pl_to_rgb565_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_ycbcr422pl_to_rgb565_66_LE_ELF

#############################################################

all: ./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_ELF/Release/IMG_ycbcr422pl_to_rgb565_66_LE_ELF.out

./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_ycbcr422pl_to_rgb565_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_YCBCR422PL_TO_RGB565_66_LE_ELF_SRCIMG_YCBCR422PL_TO_RGB565/IMG_ycbcr422pl_to_rgb565_cn.c -ccs.linkFile EXT_ROOT__IMG_YCBCR422PL_TO_RGB565_66_LE_ELF_SRCIMG_YCBCR422PL_TO_RGB565/IMG_ycbcr422pl_to_rgb565_d.c -ccs.linkFile EXT_ROOT__IMG_YCBCR422PL_TO_RGB565_66_LE_ELF_SRCIMG_YCBCR422PL_TO_RGB565/IMG_ycbcr422pl_to_rgb565_idat.c -ccs.linkFile EXT_ROOT__IMG_YCBCR422PL_TO_RGB565_66_LE_ELF_SRCIMG_YCBCR422PL_TO_RGB565/IMG_ycbcr422pl_to_rgb565_odat.c -ccs.linkFile EXT_ROOT__IMG_YCBCR422PL_TO_RGB565_66_LE_ELF/IMG_ycbcr422pl_to_rgb565.c -ccs.linkFile EXT_ROOT__IMG_YCBCR422PL_TO_RGB565_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_YCBCR422PL_TO_RGB565_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_YCBCR422PL_TO_RGB565_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_YCBCR422PL_TO_RGB565_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_YCBCR422PL_TO_RGB565_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_ycbcr422pl_to_rgb565/c66" -ccs.definePathVariable EXT_ROOT__IMG_YCBCR422PL_TO_RGB565_66_LE_ELF_SRCIMG_YCBCR422PL_TO_RGB565 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_ycbcr422pl_to_rgb565" -ccs.definePathVariable EXT_ROOT__IMG_YCBCR422PL_TO_RGB565_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_YCBCR422PL_TO_RGB565_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_ycbcr422pl_to_rgb565.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_YCBCR422PL_TO_RGB565_66_LE_ELF=.././ >> ./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_YCBCR422PL_TO_RGB565_66_LE_ELF_SRCIMG_YCBCR422PL_TO_RGB565=../../ >> ./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_YCBCR422PL_TO_RGB565_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_YCBCR422PL_TO_RGB565_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_ELF/Release/IMG_ycbcr422pl_to_rgb565_66_LE_ELF.out: ./src/IMG_ycbcr422pl_to_rgb565/IMG_ycbcr422pl_to_rgb565.h
./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_ELF/Release/IMG_ycbcr422pl_to_rgb565_66_LE_ELF.out: ./src/IMG_ycbcr422pl_to_rgb565/IMG_ycbcr422pl_to_rgb565_cn.c
./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_ELF/Release/IMG_ycbcr422pl_to_rgb565_66_LE_ELF.out: ./src/IMG_ycbcr422pl_to_rgb565/IMG_ycbcr422pl_to_rgb565_cn.h
./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_ELF/Release/IMG_ycbcr422pl_to_rgb565_66_LE_ELF.out: ./src/IMG_ycbcr422pl_to_rgb565/IMG_ycbcr422pl_to_rgb565_d.c
./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_ELF/Release/IMG_ycbcr422pl_to_rgb565_66_LE_ELF.out: ./src/IMG_ycbcr422pl_to_rgb565/IMG_ycbcr422pl_to_rgb565_idat.c
./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_ELF/Release/IMG_ycbcr422pl_to_rgb565_66_LE_ELF.out: ./src/IMG_ycbcr422pl_to_rgb565/IMG_ycbcr422pl_to_rgb565_odat.c
./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_ELF/Release/IMG_ycbcr422pl_to_rgb565_66_LE_ELF.out: ./src/IMG_ycbcr422pl_to_rgb565//c66/IMG_ycbcr422pl_to_rgb565.c
./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_ELF/Release/IMG_ycbcr422pl_to_rgb565_66_LE_ELF.out: ./src/IMG_ycbcr422pl_to_rgb565//c66/IMG_ycbcr422pl_to_rgb565.h
./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_ELF/Release/IMG_ycbcr422pl_to_rgb565_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_ELF/Release/IMG_ycbcr422pl_to_rgb565_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_ELF/Release/IMG_ycbcr422pl_to_rgb565_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_ELF/Release/IMG_ycbcr422pl_to_rgb565_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_ELF/Release/IMG_ycbcr422pl_to_rgb565_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_ELF/Release/IMG_ycbcr422pl_to_rgb565_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_ELF/Release/IMG_ycbcr422pl_to_rgb565_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_ELF/Release/IMG_ycbcr422pl_to_rgb565_66_LE_ELF.out: ./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_ELF/.project
	-@ echo Importing Project IMG_ycbcr422pl_to_rgb565_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_ycbcr422pl_to_rgb565_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_ycbcr422pl_to_rgb565/c66/IMG_ycbcr422pl_to_rgb565_66_LE_ELF"
	-@ echo Building Project IMG_ycbcr422pl_to_rgb565_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_ycbcr422pl_to_rgb565_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_ycbcr422pl_to_rgb565_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_ELF/.settings"

	-@ echo Project IMG_ycbcr422pl_to_rgb565_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_ycbcr422pl_to_rgb565//c66//IMG_ycbcr422pl_to_rgb565_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_yc_demux_be16_16_66_LE_COFF

#############################################################

all: ./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_COFF/Release/IMG_yc_demux_be16_16_66_LE_COFF.out

./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_yc_demux_be16_16_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_BE16_16_66_LE_COFF_SRCIMG_YC_DEMUX_BE16_16/IMG_yc_demux_be16_16_cn.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_BE16_16_66_LE_COFF_SRCIMG_YC_DEMUX_BE16_16/IMG_yc_demux_be16_16_d.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_BE16_16_66_LE_COFF_SRCIMG_YC_DEMUX_BE16_16/IMG_yc_demux_be16_16_idat.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_BE16_16_66_LE_COFF_SRCIMG_YC_DEMUX_BE16_16/IMG_yc_demux_be16_16_odat.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_BE16_16_66_LE_COFF/IMG_yc_demux_be16_16.sa -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_BE16_16_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_BE16_16_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_BE16_16_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_BE16_16_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_YC_DEMUX_BE16_16_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_yc_demux_be16_16/c66" -ccs.definePathVariable EXT_ROOT__IMG_YC_DEMUX_BE16_16_66_LE_COFF_SRCIMG_YC_DEMUX_BE16_16 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_yc_demux_be16_16" -ccs.definePathVariable EXT_ROOT__IMG_YC_DEMUX_BE16_16_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_YC_DEMUX_BE16_16_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_yc_demux_be16_16.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_YC_DEMUX_BE16_16_66_LE_COFF=.././ >> ./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_YC_DEMUX_BE16_16_66_LE_COFF_SRCIMG_YC_DEMUX_BE16_16=../../ >> ./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_YC_DEMUX_BE16_16_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_YC_DEMUX_BE16_16_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_COFF/Release/IMG_yc_demux_be16_16_66_LE_COFF.out: ./src/IMG_yc_demux_be16_16/IMG_yc_demux_be16_16.h
./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_COFF/Release/IMG_yc_demux_be16_16_66_LE_COFF.out: ./src/IMG_yc_demux_be16_16/IMG_yc_demux_be16_16_cn.c
./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_COFF/Release/IMG_yc_demux_be16_16_66_LE_COFF.out: ./src/IMG_yc_demux_be16_16/IMG_yc_demux_be16_16_cn.h
./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_COFF/Release/IMG_yc_demux_be16_16_66_LE_COFF.out: ./src/IMG_yc_demux_be16_16/IMG_yc_demux_be16_16_d.c
./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_COFF/Release/IMG_yc_demux_be16_16_66_LE_COFF.out: ./src/IMG_yc_demux_be16_16/IMG_yc_demux_be16_16_idat.c
./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_COFF/Release/IMG_yc_demux_be16_16_66_LE_COFF.out: ./src/IMG_yc_demux_be16_16/IMG_yc_demux_be16_16_odat.c
./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_COFF/Release/IMG_yc_demux_be16_16_66_LE_COFF.out: ./src/IMG_yc_demux_be16_16//c66/IMG_yc_demux_be16_16.h
./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_COFF/Release/IMG_yc_demux_be16_16_66_LE_COFF.out: ./src/IMG_yc_demux_be16_16//c66/IMG_yc_demux_be16_16.sa
./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_COFF/Release/IMG_yc_demux_be16_16_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_COFF/Release/IMG_yc_demux_be16_16_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_COFF/Release/IMG_yc_demux_be16_16_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_COFF/Release/IMG_yc_demux_be16_16_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_COFF/Release/IMG_yc_demux_be16_16_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_COFF/Release/IMG_yc_demux_be16_16_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_COFF/Release/IMG_yc_demux_be16_16_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_COFF/Release/IMG_yc_demux_be16_16_66_LE_COFF.out: ./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_COFF/.project
	-@ echo Importing Project IMG_yc_demux_be16_16_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_yc_demux_be16_16_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_yc_demux_be16_16/c66/IMG_yc_demux_be16_16_66_LE_COFF"
	-@ echo Building Project IMG_yc_demux_be16_16_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_yc_demux_be16_16_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_yc_demux_be16_16_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_COFF/.settings"

	-@ echo Project IMG_yc_demux_be16_16_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_yc_demux_be16_16_66_LE_ELF

#############################################################

all: ./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_ELF/Release/IMG_yc_demux_be16_16_66_LE_ELF.out

./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_yc_demux_be16_16_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_BE16_16_66_LE_ELF_SRCIMG_YC_DEMUX_BE16_16/IMG_yc_demux_be16_16_cn.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_BE16_16_66_LE_ELF_SRCIMG_YC_DEMUX_BE16_16/IMG_yc_demux_be16_16_d.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_BE16_16_66_LE_ELF_SRCIMG_YC_DEMUX_BE16_16/IMG_yc_demux_be16_16_idat.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_BE16_16_66_LE_ELF_SRCIMG_YC_DEMUX_BE16_16/IMG_yc_demux_be16_16_odat.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_BE16_16_66_LE_ELF/IMG_yc_demux_be16_16.sa -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_BE16_16_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_BE16_16_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_BE16_16_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_BE16_16_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_YC_DEMUX_BE16_16_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_yc_demux_be16_16/c66" -ccs.definePathVariable EXT_ROOT__IMG_YC_DEMUX_BE16_16_66_LE_ELF_SRCIMG_YC_DEMUX_BE16_16 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_yc_demux_be16_16" -ccs.definePathVariable EXT_ROOT__IMG_YC_DEMUX_BE16_16_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_YC_DEMUX_BE16_16_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_yc_demux_be16_16.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_YC_DEMUX_BE16_16_66_LE_ELF=.././ >> ./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_YC_DEMUX_BE16_16_66_LE_ELF_SRCIMG_YC_DEMUX_BE16_16=../../ >> ./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_YC_DEMUX_BE16_16_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_YC_DEMUX_BE16_16_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_ELF/Release/IMG_yc_demux_be16_16_66_LE_ELF.out: ./src/IMG_yc_demux_be16_16/IMG_yc_demux_be16_16.h
./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_ELF/Release/IMG_yc_demux_be16_16_66_LE_ELF.out: ./src/IMG_yc_demux_be16_16/IMG_yc_demux_be16_16_cn.c
./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_ELF/Release/IMG_yc_demux_be16_16_66_LE_ELF.out: ./src/IMG_yc_demux_be16_16/IMG_yc_demux_be16_16_cn.h
./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_ELF/Release/IMG_yc_demux_be16_16_66_LE_ELF.out: ./src/IMG_yc_demux_be16_16/IMG_yc_demux_be16_16_d.c
./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_ELF/Release/IMG_yc_demux_be16_16_66_LE_ELF.out: ./src/IMG_yc_demux_be16_16/IMG_yc_demux_be16_16_idat.c
./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_ELF/Release/IMG_yc_demux_be16_16_66_LE_ELF.out: ./src/IMG_yc_demux_be16_16/IMG_yc_demux_be16_16_odat.c
./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_ELF/Release/IMG_yc_demux_be16_16_66_LE_ELF.out: ./src/IMG_yc_demux_be16_16//c66/IMG_yc_demux_be16_16.h
./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_ELF/Release/IMG_yc_demux_be16_16_66_LE_ELF.out: ./src/IMG_yc_demux_be16_16//c66/IMG_yc_demux_be16_16.sa
./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_ELF/Release/IMG_yc_demux_be16_16_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_ELF/Release/IMG_yc_demux_be16_16_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_ELF/Release/IMG_yc_demux_be16_16_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_ELF/Release/IMG_yc_demux_be16_16_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_ELF/Release/IMG_yc_demux_be16_16_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_ELF/Release/IMG_yc_demux_be16_16_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_ELF/Release/IMG_yc_demux_be16_16_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_ELF/Release/IMG_yc_demux_be16_16_66_LE_ELF.out: ./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_ELF/.project
	-@ echo Importing Project IMG_yc_demux_be16_16_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_yc_demux_be16_16_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_yc_demux_be16_16/c66/IMG_yc_demux_be16_16_66_LE_ELF"
	-@ echo Building Project IMG_yc_demux_be16_16_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_yc_demux_be16_16_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_yc_demux_be16_16_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_ELF/.settings"

	-@ echo Project IMG_yc_demux_be16_16_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_yc_demux_be16_16//c66//IMG_yc_demux_be16_16_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_yc_demux_be16_8_66_LE_COFF

#############################################################

all: ./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_COFF/Release/IMG_yc_demux_be16_8_66_LE_COFF.out

./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_yc_demux_be16_8_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_BE16_8_66_LE_COFF_SRCIMG_YC_DEMUX_BE16_8/IMG_yc_demux_be16_8_cn.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_BE16_8_66_LE_COFF_SRCIMG_YC_DEMUX_BE16_8/IMG_yc_demux_be16_8_d.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_BE16_8_66_LE_COFF_SRCIMG_YC_DEMUX_BE16_8/IMG_yc_demux_be16_8_idat.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_BE16_8_66_LE_COFF_SRCIMG_YC_DEMUX_BE16_8/IMG_yc_demux_be16_8_odat.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_BE16_8_66_LE_COFF/IMG_yc_demux_be16_8.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_BE16_8_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_BE16_8_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_BE16_8_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_BE16_8_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_YC_DEMUX_BE16_8_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_yc_demux_be16_8/c66" -ccs.definePathVariable EXT_ROOT__IMG_YC_DEMUX_BE16_8_66_LE_COFF_SRCIMG_YC_DEMUX_BE16_8 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_yc_demux_be16_8" -ccs.definePathVariable EXT_ROOT__IMG_YC_DEMUX_BE16_8_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_YC_DEMUX_BE16_8_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_yc_demux_be16_8.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_YC_DEMUX_BE16_8_66_LE_COFF=.././ >> ./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_YC_DEMUX_BE16_8_66_LE_COFF_SRCIMG_YC_DEMUX_BE16_8=../../ >> ./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_YC_DEMUX_BE16_8_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_YC_DEMUX_BE16_8_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_COFF/Release/IMG_yc_demux_be16_8_66_LE_COFF.out: ./src/IMG_yc_demux_be16_8/IMG_yc_demux_be16_8.h
./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_COFF/Release/IMG_yc_demux_be16_8_66_LE_COFF.out: ./src/IMG_yc_demux_be16_8/IMG_yc_demux_be16_8_cn.c
./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_COFF/Release/IMG_yc_demux_be16_8_66_LE_COFF.out: ./src/IMG_yc_demux_be16_8/IMG_yc_demux_be16_8_cn.h
./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_COFF/Release/IMG_yc_demux_be16_8_66_LE_COFF.out: ./src/IMG_yc_demux_be16_8/IMG_yc_demux_be16_8_d.c
./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_COFF/Release/IMG_yc_demux_be16_8_66_LE_COFF.out: ./src/IMG_yc_demux_be16_8/IMG_yc_demux_be16_8_idat.c
./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_COFF/Release/IMG_yc_demux_be16_8_66_LE_COFF.out: ./src/IMG_yc_demux_be16_8/IMG_yc_demux_be16_8_odat.c
./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_COFF/Release/IMG_yc_demux_be16_8_66_LE_COFF.out: ./src/IMG_yc_demux_be16_8//c66/IMG_yc_demux_be16_8.c
./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_COFF/Release/IMG_yc_demux_be16_8_66_LE_COFF.out: ./src/IMG_yc_demux_be16_8//c66/IMG_yc_demux_be16_8.h
./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_COFF/Release/IMG_yc_demux_be16_8_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_COFF/Release/IMG_yc_demux_be16_8_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_COFF/Release/IMG_yc_demux_be16_8_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_COFF/Release/IMG_yc_demux_be16_8_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_COFF/Release/IMG_yc_demux_be16_8_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_COFF/Release/IMG_yc_demux_be16_8_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_COFF/Release/IMG_yc_demux_be16_8_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_COFF/Release/IMG_yc_demux_be16_8_66_LE_COFF.out: ./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_COFF/.project
	-@ echo Importing Project IMG_yc_demux_be16_8_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_yc_demux_be16_8_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_yc_demux_be16_8/c66/IMG_yc_demux_be16_8_66_LE_COFF"
	-@ echo Building Project IMG_yc_demux_be16_8_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_yc_demux_be16_8_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_yc_demux_be16_8_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_COFF/.settings"

	-@ echo Project IMG_yc_demux_be16_8_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_yc_demux_be16_8_66_LE_ELF

#############################################################

all: ./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_ELF/Release/IMG_yc_demux_be16_8_66_LE_ELF.out

./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_yc_demux_be16_8_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_BE16_8_66_LE_ELF_SRCIMG_YC_DEMUX_BE16_8/IMG_yc_demux_be16_8_cn.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_BE16_8_66_LE_ELF_SRCIMG_YC_DEMUX_BE16_8/IMG_yc_demux_be16_8_d.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_BE16_8_66_LE_ELF_SRCIMG_YC_DEMUX_BE16_8/IMG_yc_demux_be16_8_idat.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_BE16_8_66_LE_ELF_SRCIMG_YC_DEMUX_BE16_8/IMG_yc_demux_be16_8_odat.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_BE16_8_66_LE_ELF/IMG_yc_demux_be16_8.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_BE16_8_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_BE16_8_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_BE16_8_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_BE16_8_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_YC_DEMUX_BE16_8_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_yc_demux_be16_8/c66" -ccs.definePathVariable EXT_ROOT__IMG_YC_DEMUX_BE16_8_66_LE_ELF_SRCIMG_YC_DEMUX_BE16_8 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_yc_demux_be16_8" -ccs.definePathVariable EXT_ROOT__IMG_YC_DEMUX_BE16_8_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_YC_DEMUX_BE16_8_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_yc_demux_be16_8.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_YC_DEMUX_BE16_8_66_LE_ELF=.././ >> ./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_YC_DEMUX_BE16_8_66_LE_ELF_SRCIMG_YC_DEMUX_BE16_8=../../ >> ./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_YC_DEMUX_BE16_8_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_YC_DEMUX_BE16_8_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_ELF/Release/IMG_yc_demux_be16_8_66_LE_ELF.out: ./src/IMG_yc_demux_be16_8/IMG_yc_demux_be16_8.h
./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_ELF/Release/IMG_yc_demux_be16_8_66_LE_ELF.out: ./src/IMG_yc_demux_be16_8/IMG_yc_demux_be16_8_cn.c
./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_ELF/Release/IMG_yc_demux_be16_8_66_LE_ELF.out: ./src/IMG_yc_demux_be16_8/IMG_yc_demux_be16_8_cn.h
./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_ELF/Release/IMG_yc_demux_be16_8_66_LE_ELF.out: ./src/IMG_yc_demux_be16_8/IMG_yc_demux_be16_8_d.c
./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_ELF/Release/IMG_yc_demux_be16_8_66_LE_ELF.out: ./src/IMG_yc_demux_be16_8/IMG_yc_demux_be16_8_idat.c
./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_ELF/Release/IMG_yc_demux_be16_8_66_LE_ELF.out: ./src/IMG_yc_demux_be16_8/IMG_yc_demux_be16_8_odat.c
./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_ELF/Release/IMG_yc_demux_be16_8_66_LE_ELF.out: ./src/IMG_yc_demux_be16_8//c66/IMG_yc_demux_be16_8.c
./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_ELF/Release/IMG_yc_demux_be16_8_66_LE_ELF.out: ./src/IMG_yc_demux_be16_8//c66/IMG_yc_demux_be16_8.h
./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_ELF/Release/IMG_yc_demux_be16_8_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_ELF/Release/IMG_yc_demux_be16_8_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_ELF/Release/IMG_yc_demux_be16_8_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_ELF/Release/IMG_yc_demux_be16_8_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_ELF/Release/IMG_yc_demux_be16_8_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_ELF/Release/IMG_yc_demux_be16_8_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_ELF/Release/IMG_yc_demux_be16_8_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_ELF/Release/IMG_yc_demux_be16_8_66_LE_ELF.out: ./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_ELF/.project
	-@ echo Importing Project IMG_yc_demux_be16_8_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_yc_demux_be16_8_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_yc_demux_be16_8/c66/IMG_yc_demux_be16_8_66_LE_ELF"
	-@ echo Building Project IMG_yc_demux_be16_8_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_yc_demux_be16_8_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_yc_demux_be16_8_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_ELF/.settings"

	-@ echo Project IMG_yc_demux_be16_8_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_yc_demux_be16_8//c66//IMG_yc_demux_be16_8_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_yc_demux_le16_16_66_LE_COFF

#############################################################

all: ./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_COFF/Release/IMG_yc_demux_le16_16_66_LE_COFF.out

./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_yc_demux_le16_16_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_LE16_16_66_LE_COFF_SRCIMG_YC_DEMUX_LE16_16/IMG_yc_demux_le16_16_cn.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_LE16_16_66_LE_COFF_SRCIMG_YC_DEMUX_LE16_16/IMG_yc_demux_le16_16_d.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_LE16_16_66_LE_COFF_SRCIMG_YC_DEMUX_LE16_16/IMG_yc_demux_le16_16_idat.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_LE16_16_66_LE_COFF_SRCIMG_YC_DEMUX_LE16_16/IMG_yc_demux_le16_16_odat.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_LE16_16_66_LE_COFF/IMG_yc_demux_le16_16.sa -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_LE16_16_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_LE16_16_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_LE16_16_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_LE16_16_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_YC_DEMUX_LE16_16_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_yc_demux_le16_16/c66" -ccs.definePathVariable EXT_ROOT__IMG_YC_DEMUX_LE16_16_66_LE_COFF_SRCIMG_YC_DEMUX_LE16_16 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_yc_demux_le16_16" -ccs.definePathVariable EXT_ROOT__IMG_YC_DEMUX_LE16_16_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_YC_DEMUX_LE16_16_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_yc_demux_le16_16.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_YC_DEMUX_LE16_16_66_LE_COFF=.././ >> ./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_YC_DEMUX_LE16_16_66_LE_COFF_SRCIMG_YC_DEMUX_LE16_16=../../ >> ./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_YC_DEMUX_LE16_16_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_YC_DEMUX_LE16_16_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_COFF/Release/IMG_yc_demux_le16_16_66_LE_COFF.out: ./src/IMG_yc_demux_le16_16/IMG_yc_demux_le16_16.h
./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_COFF/Release/IMG_yc_demux_le16_16_66_LE_COFF.out: ./src/IMG_yc_demux_le16_16/IMG_yc_demux_le16_16_cn.c
./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_COFF/Release/IMG_yc_demux_le16_16_66_LE_COFF.out: ./src/IMG_yc_demux_le16_16/IMG_yc_demux_le16_16_cn.h
./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_COFF/Release/IMG_yc_demux_le16_16_66_LE_COFF.out: ./src/IMG_yc_demux_le16_16/IMG_yc_demux_le16_16_d.c
./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_COFF/Release/IMG_yc_demux_le16_16_66_LE_COFF.out: ./src/IMG_yc_demux_le16_16/IMG_yc_demux_le16_16_idat.c
./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_COFF/Release/IMG_yc_demux_le16_16_66_LE_COFF.out: ./src/IMG_yc_demux_le16_16/IMG_yc_demux_le16_16_odat.c
./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_COFF/Release/IMG_yc_demux_le16_16_66_LE_COFF.out: ./src/IMG_yc_demux_le16_16//c66/IMG_yc_demux_le16_16.h
./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_COFF/Release/IMG_yc_demux_le16_16_66_LE_COFF.out: ./src/IMG_yc_demux_le16_16//c66/IMG_yc_demux_le16_16.sa
./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_COFF/Release/IMG_yc_demux_le16_16_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_COFF/Release/IMG_yc_demux_le16_16_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_COFF/Release/IMG_yc_demux_le16_16_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_COFF/Release/IMG_yc_demux_le16_16_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_COFF/Release/IMG_yc_demux_le16_16_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_COFF/Release/IMG_yc_demux_le16_16_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_COFF/Release/IMG_yc_demux_le16_16_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_COFF/Release/IMG_yc_demux_le16_16_66_LE_COFF.out: ./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_COFF/.project
	-@ echo Importing Project IMG_yc_demux_le16_16_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_yc_demux_le16_16_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_yc_demux_le16_16/c66/IMG_yc_demux_le16_16_66_LE_COFF"
	-@ echo Building Project IMG_yc_demux_le16_16_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_yc_demux_le16_16_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_yc_demux_le16_16_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_COFF/.settings"

	-@ echo Project IMG_yc_demux_le16_16_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_yc_demux_le16_16_66_LE_ELF

#############################################################

all: ./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_ELF/Release/IMG_yc_demux_le16_16_66_LE_ELF.out

./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_yc_demux_le16_16_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_LE16_16_66_LE_ELF_SRCIMG_YC_DEMUX_LE16_16/IMG_yc_demux_le16_16_cn.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_LE16_16_66_LE_ELF_SRCIMG_YC_DEMUX_LE16_16/IMG_yc_demux_le16_16_d.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_LE16_16_66_LE_ELF_SRCIMG_YC_DEMUX_LE16_16/IMG_yc_demux_le16_16_idat.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_LE16_16_66_LE_ELF_SRCIMG_YC_DEMUX_LE16_16/IMG_yc_demux_le16_16_odat.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_LE16_16_66_LE_ELF/IMG_yc_demux_le16_16.sa -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_LE16_16_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_LE16_16_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_LE16_16_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_LE16_16_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_YC_DEMUX_LE16_16_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_yc_demux_le16_16/c66" -ccs.definePathVariable EXT_ROOT__IMG_YC_DEMUX_LE16_16_66_LE_ELF_SRCIMG_YC_DEMUX_LE16_16 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_yc_demux_le16_16" -ccs.definePathVariable EXT_ROOT__IMG_YC_DEMUX_LE16_16_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_YC_DEMUX_LE16_16_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_yc_demux_le16_16.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_YC_DEMUX_LE16_16_66_LE_ELF=.././ >> ./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_YC_DEMUX_LE16_16_66_LE_ELF_SRCIMG_YC_DEMUX_LE16_16=../../ >> ./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_YC_DEMUX_LE16_16_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_YC_DEMUX_LE16_16_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_ELF/Release/IMG_yc_demux_le16_16_66_LE_ELF.out: ./src/IMG_yc_demux_le16_16/IMG_yc_demux_le16_16.h
./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_ELF/Release/IMG_yc_demux_le16_16_66_LE_ELF.out: ./src/IMG_yc_demux_le16_16/IMG_yc_demux_le16_16_cn.c
./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_ELF/Release/IMG_yc_demux_le16_16_66_LE_ELF.out: ./src/IMG_yc_demux_le16_16/IMG_yc_demux_le16_16_cn.h
./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_ELF/Release/IMG_yc_demux_le16_16_66_LE_ELF.out: ./src/IMG_yc_demux_le16_16/IMG_yc_demux_le16_16_d.c
./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_ELF/Release/IMG_yc_demux_le16_16_66_LE_ELF.out: ./src/IMG_yc_demux_le16_16/IMG_yc_demux_le16_16_idat.c
./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_ELF/Release/IMG_yc_demux_le16_16_66_LE_ELF.out: ./src/IMG_yc_demux_le16_16/IMG_yc_demux_le16_16_odat.c
./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_ELF/Release/IMG_yc_demux_le16_16_66_LE_ELF.out: ./src/IMG_yc_demux_le16_16//c66/IMG_yc_demux_le16_16.h
./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_ELF/Release/IMG_yc_demux_le16_16_66_LE_ELF.out: ./src/IMG_yc_demux_le16_16//c66/IMG_yc_demux_le16_16.sa
./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_ELF/Release/IMG_yc_demux_le16_16_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_ELF/Release/IMG_yc_demux_le16_16_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_ELF/Release/IMG_yc_demux_le16_16_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_ELF/Release/IMG_yc_demux_le16_16_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_ELF/Release/IMG_yc_demux_le16_16_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_ELF/Release/IMG_yc_demux_le16_16_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_ELF/Release/IMG_yc_demux_le16_16_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_ELF/Release/IMG_yc_demux_le16_16_66_LE_ELF.out: ./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_ELF/.project
	-@ echo Importing Project IMG_yc_demux_le16_16_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_yc_demux_le16_16_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_yc_demux_le16_16/c66/IMG_yc_demux_le16_16_66_LE_ELF"
	-@ echo Building Project IMG_yc_demux_le16_16_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_yc_demux_le16_16_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_yc_demux_le16_16_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_ELF/.settings"

	-@ echo Project IMG_yc_demux_le16_16_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_yc_demux_le16_16//c66//IMG_yc_demux_le16_16_66_LE_ELF"


#############################################################

# Rule to Build Project IMG_yc_demux_le16_8_66_LE_COFF

#############################################################

all: ./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_COFF/Release/IMG_yc_demux_le16_8_66_LE_COFF.out

./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_COFF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_yc_demux_le16_8_66_LE_COFF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_LE16_8_66_LE_COFF_SRCIMG_YC_DEMUX_LE16_8/IMG_yc_demux_le16_8_cn.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_LE16_8_66_LE_COFF_SRCIMG_YC_DEMUX_LE16_8/IMG_yc_demux_le16_8_d.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_LE16_8_66_LE_COFF_SRCIMG_YC_DEMUX_LE16_8/IMG_yc_demux_le16_8_idat.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_LE16_8_66_LE_COFF_SRCIMG_YC_DEMUX_LE16_8/IMG_yc_demux_le16_8_odat.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_LE16_8_66_LE_COFF/IMG_yc_demux_le16_8.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_LE16_8_66_LE_COFF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_LE16_8_66_LE_COFF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_LE16_8_66_LE_COFF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_LE16_8_66_LE_COFF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_COFF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat coff -ccs.definePathVariable EXT_ROOT__IMG_YC_DEMUX_LE16_8_66_LE_COFF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_yc_demux_le16_8/c66" -ccs.definePathVariable EXT_ROOT__IMG_YC_DEMUX_LE16_8_66_LE_COFF_SRCIMG_YC_DEMUX_LE16_8 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_yc_demux_le16_8" -ccs.definePathVariable EXT_ROOT__IMG_YC_DEMUX_LE16_8_66_LE_COFF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_YC_DEMUX_LE16_8_66_LE_COFF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.a66 IMG_yc_demux_le16_8.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_YC_DEMUX_LE16_8_66_LE_COFF=.././ >> ./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_YC_DEMUX_LE16_8_66_LE_COFF_SRCIMG_YC_DEMUX_LE16_8=../../ >> ./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_YC_DEMUX_LE16_8_66_LE_COFF_SRCCOMMON=../../../common >> ./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_COFF/macros.ini
	echo EXT_ROOT__IMG_YC_DEMUX_LE16_8_66_LE_COFF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_COFF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_COFF/Release/IMG_yc_demux_le16_8_66_LE_COFF.out: ./src/IMG_yc_demux_le16_8/IMG_yc_demux_le16_8.h
./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_COFF/Release/IMG_yc_demux_le16_8_66_LE_COFF.out: ./src/IMG_yc_demux_le16_8/IMG_yc_demux_le16_8_cn.c
./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_COFF/Release/IMG_yc_demux_le16_8_66_LE_COFF.out: ./src/IMG_yc_demux_le16_8/IMG_yc_demux_le16_8_cn.h
./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_COFF/Release/IMG_yc_demux_le16_8_66_LE_COFF.out: ./src/IMG_yc_demux_le16_8/IMG_yc_demux_le16_8_d.c
./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_COFF/Release/IMG_yc_demux_le16_8_66_LE_COFF.out: ./src/IMG_yc_demux_le16_8/IMG_yc_demux_le16_8_idat.c
./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_COFF/Release/IMG_yc_demux_le16_8_66_LE_COFF.out: ./src/IMG_yc_demux_le16_8/IMG_yc_demux_le16_8_odat.c
./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_COFF/Release/IMG_yc_demux_le16_8_66_LE_COFF.out: ./src/IMG_yc_demux_le16_8//c66/IMG_yc_demux_le16_8.c
./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_COFF/Release/IMG_yc_demux_le16_8_66_LE_COFF.out: ./src/IMG_yc_demux_le16_8//c66/IMG_yc_demux_le16_8.h
./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_COFF/Release/IMG_yc_demux_le16_8_66_LE_COFF.out: ./src/common/IMG_profile.c
./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_COFF/Release/IMG_yc_demux_le16_8_66_LE_COFF.out: ./src/common/IMG_profile.h
./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_COFF/Release/IMG_yc_demux_le16_8_66_LE_COFF.out: ./src/common/IMG_utility.c
./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_COFF/Release/IMG_yc_demux_le16_8_66_LE_COFF.out: ./src/common/IMG_utility.h
./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_COFF/Release/IMG_yc_demux_le16_8_66_LE_COFF.out: ./src/common/IMG_memory.c
./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_COFF/Release/IMG_yc_demux_le16_8_66_LE_COFF.out: ./src/common/IMG_memory.h
./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_COFF/Release/IMG_yc_demux_le16_8_66_LE_COFF.out: ./src/common//c66/lnk.cmd
./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_COFF/Release/IMG_yc_demux_le16_8_66_LE_COFF.out: ./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_COFF/.project
	-@ echo Importing Project IMG_yc_demux_le16_8_66_LE_COFF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_yc_demux_le16_8_66_LE_COFF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_yc_demux_le16_8/c66/IMG_yc_demux_le16_8_66_LE_COFF"
	-@ echo Building Project IMG_yc_demux_le16_8_66_LE_COFF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_yc_demux_le16_8_66_LE_COFF -ccs.configuration Release
	-@ echo Cleaning Project IMG_yc_demux_le16_8_66_LE_COFF ...
	-$(RMDIR) "./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_COFF/Release"

	-$(RMDIR) "./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_COFF/.settings"

	-@ echo Project IMG_yc_demux_le16_8_66_LE_COFF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_COFF"


#############################################################

# Rule to Build Project IMG_yc_demux_le16_8_66_LE_ELF

#############################################################

all: ./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_ELF/Release/IMG_yc_demux_le16_8_66_LE_ELF.out

./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_ELF/.project: .xdcenv.mak Package.bld Package.mak
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectCreate -ccs.name IMG_yc_demux_le16_8_66_LE_ELF -ccs.device com.ti.ccstudio.deviceModel.C6000.CustomC6000Device -ccs.endianness little -ccs.kind com.ti.ccstudio.managedbuild.core.ProjectKind_Executable -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_LE16_8_66_LE_ELF_SRCIMG_YC_DEMUX_LE16_8/IMG_yc_demux_le16_8_cn.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_LE16_8_66_LE_ELF_SRCIMG_YC_DEMUX_LE16_8/IMG_yc_demux_le16_8_d.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_LE16_8_66_LE_ELF_SRCIMG_YC_DEMUX_LE16_8/IMG_yc_demux_le16_8_idat.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_LE16_8_66_LE_ELF_SRCIMG_YC_DEMUX_LE16_8/IMG_yc_demux_le16_8_odat.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_LE16_8_66_LE_ELF/IMG_yc_demux_le16_8.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_LE16_8_66_LE_ELF_SRCCOMMON/IMG_profile.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_LE16_8_66_LE_ELF_SRCCOMMON/IMG_utility.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_LE16_8_66_LE_ELF_SRCCOMMON/IMG_memory.c -ccs.linkFile EXT_ROOT__IMG_YC_DEMUX_LE16_8_66_LE_ELF_SRCCOMMONC66/lnk.cmd -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -g  -i../../../../../../../" @configurations Debug -ccs.setCompilerOptions "-mv6600 -k  -mw --mem_model:data=far -o3 --symdebug:none  -i../../../../../../../" @configurations Release -ccs.location ./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_ELF -ccs.overwrite full -ccs.rts libc.a -ccs.cgtVersion $(CCSCGTVER) -ccs.outputFormat elf -ccs.definePathVariable EXT_ROOT__IMG_YC_DEMUX_LE16_8_66_LE_ELF "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_yc_demux_le16_8/c66" -ccs.definePathVariable EXT_ROOT__IMG_YC_DEMUX_LE16_8_66_LE_ELF_SRCIMG_YC_DEMUX_LE16_8 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_yc_demux_le16_8" -ccs.definePathVariable EXT_ROOT__IMG_YC_DEMUX_LE16_8_66_LE_ELF_SRCCOMMON "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common" -ccs.definePathVariable EXT_ROOT__IMG_YC_DEMUX_LE16_8_66_LE_ELF_SRCCOMMONC66 "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/common/c66" -ccs.setPostBuildStep $(quote)$${C6000_CG_ROOT}/bin/ar6x rq ../../../../../../../../lib/imglib.ae66 IMG_yc_demux_le16_8.obj$(quote) @configurations Release
	echo EXT_ROOT__IMG_YC_DEMUX_LE16_8_66_LE_ELF=.././ >> ./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_YC_DEMUX_LE16_8_66_LE_ELF_SRCIMG_YC_DEMUX_LE16_8=../../ >> ./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_YC_DEMUX_LE16_8_66_LE_ELF_SRCCOMMON=../../../common >> ./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_ELF/macros.ini
	echo EXT_ROOT__IMG_YC_DEMUX_LE16_8_66_LE_ELF_SRCCOMMONC66=../../../common/c66 >> ./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_ELF/macros.ini
	-$(RMDIR) "C:/Temp/workspace"
./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_ELF/Release/IMG_yc_demux_le16_8_66_LE_ELF.out: ./src/IMG_yc_demux_le16_8/IMG_yc_demux_le16_8.h
./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_ELF/Release/IMG_yc_demux_le16_8_66_LE_ELF.out: ./src/IMG_yc_demux_le16_8/IMG_yc_demux_le16_8_cn.c
./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_ELF/Release/IMG_yc_demux_le16_8_66_LE_ELF.out: ./src/IMG_yc_demux_le16_8/IMG_yc_demux_le16_8_cn.h
./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_ELF/Release/IMG_yc_demux_le16_8_66_LE_ELF.out: ./src/IMG_yc_demux_le16_8/IMG_yc_demux_le16_8_d.c
./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_ELF/Release/IMG_yc_demux_le16_8_66_LE_ELF.out: ./src/IMG_yc_demux_le16_8/IMG_yc_demux_le16_8_idat.c
./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_ELF/Release/IMG_yc_demux_le16_8_66_LE_ELF.out: ./src/IMG_yc_demux_le16_8/IMG_yc_demux_le16_8_odat.c
./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_ELF/Release/IMG_yc_demux_le16_8_66_LE_ELF.out: ./src/IMG_yc_demux_le16_8//c66/IMG_yc_demux_le16_8.c
./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_ELF/Release/IMG_yc_demux_le16_8_66_LE_ELF.out: ./src/IMG_yc_demux_le16_8//c66/IMG_yc_demux_le16_8.h
./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_ELF/Release/IMG_yc_demux_le16_8_66_LE_ELF.out: ./src/common/IMG_profile.c
./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_ELF/Release/IMG_yc_demux_le16_8_66_LE_ELF.out: ./src/common/IMG_profile.h
./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_ELF/Release/IMG_yc_demux_le16_8_66_LE_ELF.out: ./src/common/IMG_utility.c
./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_ELF/Release/IMG_yc_demux_le16_8_66_LE_ELF.out: ./src/common/IMG_utility.h
./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_ELF/Release/IMG_yc_demux_le16_8_66_LE_ELF.out: ./src/common/IMG_memory.c
./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_ELF/Release/IMG_yc_demux_le16_8_66_LE_ELF.out: ./src/common/IMG_memory.h
./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_ELF/Release/IMG_yc_demux_le16_8_66_LE_ELF.out: ./src/common//c66/lnk.cmd
./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_ELF/Release/IMG_yc_demux_le16_8_66_LE_ELF.out: ./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_ELF/.project
	-@ echo Importing Project IMG_yc_demux_le16_8_66_LE_ELF into workspace ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectImport -ccs.projects IMG_yc_demux_le16_8_66_LE_ELF -ccs.location "$(IMGLIB_INSTALL_DIR)/ti/imglib/src/IMG_yc_demux_le16_8/c66/IMG_yc_demux_le16_8_66_LE_ELF"
	-@ echo Building Project IMG_yc_demux_le16_8_66_LE_ELF ...
	$(ECLIPSE_CMD)  -data "C:/Temp/workspace" -application com.ti.ccstudio.apps.projectBuild -ccs.projects IMG_yc_demux_le16_8_66_LE_ELF -ccs.configuration Release
	-@ echo Cleaning Project IMG_yc_demux_le16_8_66_LE_ELF ...
	-$(RMDIR) "./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_ELF/Release"

	-$(RMDIR) "./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_ELF/.settings"

	-@ echo Project IMG_yc_demux_le16_8_66_LE_ELF Completed ...
	-@ echo ########################################
	-$(RMDIR) "C:/Temp/workspace"

clean::
	-$(RMDIR) "./src/IMG_yc_demux_le16_8//c66//IMG_yc_demux_le16_8_66_LE_ELF"

