/* 
 * Copyright (C) 2015 The Qt Company Ltd.
 * Contact: http://www.qt.io/licensing/
 * 
 * This file is part of the plugins of the Qt Toolkit.
 * 
 * $QT_BEGIN_LICENSE:BSD$
 * You may use this file under the terms of the BSD license as follows:
 * 
 * "Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in
 * the documentation and/or other materials provided with the
 * distribution.
 * * Neither the name of The Qt Company Ltd nor the names of its
 * contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * 
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
 * 
 * $QT_END_LICENSE$
 */

#ifndef TOUCH_EXTENSION_CLIENT_PROTOCOL_H
#define TOUCH_EXTENSION_CLIENT_PROTOCOL_H

#ifdef  __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>
#include "wayland-client.h"

struct wl_client;
struct wl_resource;

struct qt_touch_extension;

extern const struct wl_interface qt_touch_extension_interface;

#ifndef QT_TOUCH_EXTENSION_FLAGS_ENUM
#define QT_TOUCH_EXTENSION_FLAGS_ENUM
enum qt_touch_extension_flags {
	QT_TOUCH_EXTENSION_FLAGS_MOUSE_FROM_TOUCH = 0x1,
};
#endif /* QT_TOUCH_EXTENSION_FLAGS_ENUM */

struct qt_touch_extension_listener {
	/**
	 * touch - (none)
	 * @time: (none)
	 * @id: (none)
	 * @state: (none)
	 * @x: (none)
	 * @y: (none)
	 * @normalized_x: (none)
	 * @normalized_y: (none)
	 * @width: (none)
	 * @height: (none)
	 * @pressure: (none)
	 * @velocity_x: (none)
	 * @velocity_y: (none)
	 * @flags: (none)
	 * @rawdata: (none)
	 */
	void (*touch)(void *data,
		      struct qt_touch_extension *qt_touch_extension,
		      uint32_t time,
		      uint32_t id,
		      uint32_t state,
		      int32_t x,
		      int32_t y,
		      int32_t normalized_x,
		      int32_t normalized_y,
		      int32_t width,
		      int32_t height,
		      uint32_t pressure,
		      int32_t velocity_x,
		      int32_t velocity_y,
		      uint32_t flags,
		      struct wl_array *rawdata);
	/**
	 * configure - (none)
	 * @flags: (none)
	 */
	void (*configure)(void *data,
			  struct qt_touch_extension *qt_touch_extension,
			  uint32_t flags);
};

static inline int
qt_touch_extension_add_listener(struct qt_touch_extension *qt_touch_extension,
				const struct qt_touch_extension_listener *listener, void *data)
{
	return wl_proxy_add_listener((struct wl_proxy *) qt_touch_extension,
				     (void (**)(void)) listener, data);
}

#define QT_TOUCH_EXTENSION_DUMMY	0

static inline void
qt_touch_extension_set_user_data(struct qt_touch_extension *qt_touch_extension, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) qt_touch_extension, user_data);
}

static inline void *
qt_touch_extension_get_user_data(struct qt_touch_extension *qt_touch_extension)
{
	return wl_proxy_get_user_data((struct wl_proxy *) qt_touch_extension);
}

static inline void
qt_touch_extension_destroy(struct qt_touch_extension *qt_touch_extension)
{
	wl_proxy_destroy((struct wl_proxy *) qt_touch_extension);
}

static inline void
qt_touch_extension_dummy(struct qt_touch_extension *qt_touch_extension)
{
	wl_proxy_marshal((struct wl_proxy *) qt_touch_extension,
			 QT_TOUCH_EXTENSION_DUMMY);
}

#ifdef  __cplusplus
}
#endif

#endif
