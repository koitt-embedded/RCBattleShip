
add_library(Qt5:: MODULE IMPORTED)

_populate_Compositor_plugin_properties( RELEASE "wayland-graphics-integration-server/libwayland-egl.so")

list(APPEND Qt5Compositor_PLUGINS Qt5::)
