GENCCODE_ASSEMBLY_TYPE=-a gcc
SO=so
SOBJ=so
A=a
LIBPREFIX=lib
LIB_EXT_ORDER=.56.1
COMPILE=arm-linux-gnueabihf-gcc  -march=armv7-a -marm -mfpu=neon  -mfloat-abi=hard --sysroot=/home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/am57xx-evm -isystem/home/gtbldadm/tools/linaro-2016.02/arm-linux-gnueabihf/include  -D_REENTRANT  -DU_HAVE_ELF_H=1 -DU_HAVE_ATOMIC=1  -DU_ATTRIBUTE_DEPRECATED= -isystem/home/gtbldadm/tools/linaro-2016.02/arm-linux-gnueabihf/include  -O2 -pipe -g -feliminate-unused-debug-types -fdebug-prefix-map=/home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/work/armv7ahf-neon-linux-gnueabi/icu/56.1-r0=/usr/src/debug/icu/56.1-r0 -fdebug-prefix-map=/home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/x86_64-linux= -fdebug-prefix-map=/home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/am57xx-evm=  -std=c99 -Wall -pedantic -Wshadow -Wpointer-arith -Wmissing-prototypes -Wwrite-strings   -c
LIBFLAGS=-I/usr/include -DPIC -fPIC
GENLIB=arm-linux-gnueabihf-gcc  -march=armv7-a -marm -mfpu=neon  -mfloat-abi=hard --sysroot=/home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/am57xx-evm -isystem/home/gtbldadm/tools/linaro-2016.02/arm-linux-gnueabihf/include  -O2 -pipe -g -feliminate-unused-debug-types -fdebug-prefix-map=/home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/work/armv7ahf-neon-linux-gnueabi/icu/56.1-r0=/usr/src/debug/icu/56.1-r0 -fdebug-prefix-map=/home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/x86_64-linux= -fdebug-prefix-map=/home/gtbldadm/processor-sdk-linux-krogoth-build/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/am57xx-evm=  -std=c99 -Wall -pedantic -Wshadow -Wpointer-arith -Wmissing-prototypes -Wwrite-strings   -L/home/gtbldadm/tools/linaro-2016.02/arm-linux-gnueabihf/lib -Wl,-rpath-link,/home/gtbldadm/tools/linaro-2016.02/arm-linux-gnueabihf/lib -Wl,-O1 -Wl,--hash-style=gnu  -shared -Wl,-Bsymbolic
LDICUDTFLAGS=
LD_SONAME=-Wl,-soname -Wl,
RPATH_FLAGS=
BIR_LDFLAGS=-Wl,-Bsymbolic
AR=arm-linux-gnueabihf-ar
ARFLAGS=r
RANLIB=arm-linux-gnueabihf-ranlib
INSTALL_CMD=/usr/bin/install -c
