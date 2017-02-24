#configuration
CONFIG +=  cross_compile shared qpa no_mocdepend release qt_no_framework
host_build {
    QT_ARCH = arm
    QT_TARGET_ARCH = arm
} else {
    QT_ARCH = arm
    QMAKE_DEFAULT_LIBDIRS = /home/gtbldadm/tools/linaro-2016.02/lib/gcc/arm-linux-gnueabihf/5.3.1 /home/gtbldadm/tools/linaro-2016.02/lib/gcc/arm-linux-gnueabihf /home/gtbldadm/tools/linaro-2016.02/lib/gcc /home/gtbldadm/tools/linaro-2016.02/arm-linux-gnueabihf/lib $$[QT_SYSROOT]/lib $$[QT_SYSROOT]/usr/lib
    QMAKE_DEFAULT_INCDIRS = /home/gtbldadm/tools/linaro-2016.02/arm-linux-gnueabihf/include /home/gtbldadm/tools/linaro-2016.02/arm-linux-gnueabihf/include/c++/5.3.1 /home/gtbldadm/tools/linaro-2016.02/arm-linux-gnueabihf/include/c++/5.3.1/arm-linux-gnueabihf /home/gtbldadm/tools/linaro-2016.02/arm-linux-gnueabihf/include/c++/5.3.1/backward /home/gtbldadm/tools/linaro-2016.02/lib/gcc/arm-linux-gnueabihf/5.3.1/include /home/gtbldadm/tools/linaro-2016.02/lib/gcc/arm-linux-gnueabihf/5.3.1/include-fixed $$[QT_SYSROOT]/usr/include
}
QT_CONFIG +=  minimal-config small-config medium-config large-config full-config libudev evdev gbm linuxfb kms c++11 c++14 c++1z egl eglfs eglfs_gbm opengl opengles2 shared qpa reduce_exports clock-gettime clock-monotonic posix_fallocate mremap getaddrinfo ipv6ifname getifaddrs inotify eventfd threadsafe-cloexec system-jpeg system-png png freetype no-harfbuzz system-zlib dbus dbus-linked openssl pulseaudio gstreamer-1.0 icu concurrent audio-backend release

#versioning
QT_VERSION = 5.6.2
QT_MAJOR_VERSION = 5
QT_MINOR_VERSION = 6
QT_PATCH_VERSION = 2

#namespaces
QT_LIBINFIX = 
QT_NAMESPACE = 

QT_EDITION = OpenSource

# pkgconfig
PKG_CONFIG_SYSROOT_DIR = $$[QT_SYSROOT]
PKG_CONFIG_LIBDIR = $$[QT_SYSROOT]/usr/lib/pkgconfig

QT_COMPILER_STDCXX = 199711
QT_GCC_MAJOR_VERSION = 5
QT_GCC_MINOR_VERSION = 3
QT_GCC_PATCH_VERSION = 1
