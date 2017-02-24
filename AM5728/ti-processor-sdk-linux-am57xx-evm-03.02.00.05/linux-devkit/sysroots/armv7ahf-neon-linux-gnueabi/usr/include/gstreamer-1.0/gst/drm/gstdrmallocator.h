/*
 * GStreamer
 *
 * Copyright (C) 2012 Texas Instruments
 *
 * Authors:
 *  Pooja Prajod <poojaprajod@ti.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation
 * version 2.1 of the License.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

/**
 * SECTION:GstDRMAllocator
 * @short_description: GStreamer DRM allocator support
 *
 * Since: 1.6.3
 */

#ifndef __GSTDRMALLOCATOR_H__
#define __GSTDRMALLOCATOR_H__

#include <gst/gst.h>
#include <gst/video/video.h>
#include <gst/allocators/allocators.h>
#include <stdint.h>

#include <xf86drm.h>
#include <xf86drmMode.h>
#include <fcntl.h>

G_BEGIN_DECLS

#define GST_TYPE_DRM_ALLOCATOR                  (gst_drm_allocator_get_type ())
#define GST_DRM_ALLOCATOR(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), GST_TYPE_DRM_ALLOCATOR, GstDRMAllocator))
#define GST_IS_DRM_ALLOCATOR(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GST_TYPE_DRM_ALLOCATOR))
#define GST_DRM_ALLOCATOR_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), GST_TYPE_DRM_ALLOCATOR, GstDRMAllocatorClass))
#define GST_IS_DRM_ALLOCATOR_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), GST_TYPE_DRM_ALLOCATOR))
#define GST_DRM_ALLOCATOR_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), GST_TYPE_DRM_ALLOCATOR, GstDRMAllocatorClass))

#define GST_ALLOCATOR_DRM "DRM"

typedef struct _GstDRMAllocator GstDRMAllocator;
typedef struct _GstDRMAllocatorClass GstDRMAllocatorClass;

struct _GstDRMAllocator
{
  GstFdAllocator parent;
  int DrmDeviceFD;
};

struct _GstDRMAllocatorClass
{
  GstFdAllocatorClass parent_class;
};

void gst_drm_allocator_register (void);
GstAllocator * gst_drm_allocator_get (void);

gboolean gst_is_drm_memory (GstMemory * mem);

GType gst_drm_allocator_get_type (void);

G_END_DECLS

#endif /* __GSTDRMALLOCATOR_H__ */
