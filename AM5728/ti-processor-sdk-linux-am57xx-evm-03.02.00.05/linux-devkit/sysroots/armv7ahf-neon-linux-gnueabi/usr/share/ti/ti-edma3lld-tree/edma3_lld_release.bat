set PATH=C:/PROGRA~2/TEXASI~1/xdctools_3_22_04_46
set XDCPATH=C:/PROGRA~2/TEXASI~1/bios_6_40_03_39/packages;%PATH%

set ROOTDIR=E:/EDMA/edma3_lld_02_11_03_01

cd packages

gmake libs PLATFORM=ti814x-evm TARGET=a8 TOOLCHAIN_a8=GCC FORMAT=ELF
gmake libs FORMAT=ELF
gmake libs FORMAT=COFF

set CGTOOLS=C:/PROGRA~2/TEXASI~1/C6000_7.4.4
set CGTOOLS_ELF=C:/PROGRA~2/TEXASI~1/C6000_7.4.4
set TMS470_CGTOOLS=C:/PROGRA~2/TEXASI~1/TIARMC~1.5

xdc .interfaces -PR .
del /s /q ".interfaces"
del /AH /s /q ".xdcenv.mak"
del /s /q "package.mak"

rename config.bld _config.bld
