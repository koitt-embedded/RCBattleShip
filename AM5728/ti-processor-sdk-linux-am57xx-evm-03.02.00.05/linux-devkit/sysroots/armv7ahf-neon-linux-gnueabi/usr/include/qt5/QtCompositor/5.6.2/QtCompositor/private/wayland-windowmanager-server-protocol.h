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

#ifndef WINDOWMANAGER_SERVER_PROTOCOL_H
#define WINDOWMANAGER_SERVER_PROTOCOL_H

#ifdef  __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>
#include "wayland-server.h"

struct wl_client;
struct wl_resource;

struct qt_windowmanager;

extern const struct wl_interface qt_windowmanager_interface;

struct qt_windowmanager_interface {
	/**
	 * open_url - client requests a url to be opened
	 * @remaining: (none)
	 * @url: (none)
	 *
	 * If remaining is not 0 this is a multipart request, and the
	 * server must concatenate subsequent requst urls to and including
	 * a request where remaining is set to 0, before it can handle the
	 * url.
	 */
	void (*open_url)(struct wl_client *client,
			 struct wl_resource *resource,
			 uint32_t remaining,
			 const char *url);
};

#define QT_WINDOWMANAGER_HINTS	0
#define QT_WINDOWMANAGER_QUIT	1

#define QT_WINDOWMANAGER_HINTS_SINCE_VERSION	1
#define QT_WINDOWMANAGER_QUIT_SINCE_VERSION	1

static inline void
qt_windowmanager_send_hints(struct wl_resource *resource_, int32_t show_is_fullscreen)
{
	wl_resource_post_event(resource_, QT_WINDOWMANAGER_HINTS, show_is_fullscreen);
}

static inline void
qt_windowmanager_send_quit(struct wl_resource *resource_)
{
	wl_resource_post_event(resource_, QT_WINDOWMANAGER_QUIT);
}

#ifdef  __cplusplus
}
#endif

#endif
