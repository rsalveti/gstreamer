/* GStreamer
 * Copyright (C) 2012 Smart TV Alliance
 *  Author: Thiago Sousa Santos <thiago.sousa.santos@collabora.com>, Collabora Ltd.
 *
 * gstmssmanifest.h:
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef __GST_MSS_MANIFEST_H__
#define __GST_MSS_MANIFEST_H__

#include <glib.h>
#include <gio/gio.h>
#include <gst/gst.h>

G_BEGIN_DECLS

typedef struct _GstMssManifest GstMssManifest;
typedef struct _GstMssStream GstMssStream;

typedef enum _GstMssStreamType {
  MSS_STREAM_TYPE_UNKNOWN = 0,
  MSS_STREAM_TYPE_VIDEO = 1,
  MSS_STREAM_TYPE_AUDIO = 2
} GstMssStreamType;

GstMssManifest * gst_mss_manifest_new (const GstBuffer * data);
void gst_mss_manifest_free (GstMssManifest * manifest);
GSList * gst_mss_manifest_get_streams (GstMssManifest * manifest);
guint64 gst_mss_manifest_get_timescale (GstMssManifest * manifest);
guint64 gst_mss_manifest_get_duration (GstMssManifest * manifest);
GstClockTime gst_mss_manifest_get_gst_duration (GstMssManifest * manifest);
gboolean gst_mss_manifest_seek (GstMssManifest * manifest, guint64 time);
gboolean gst_mss_manifest_change_bitrate (GstMssManifest *manifest, guint64 bitrate);
guint64 gst_mss_manifest_get_current_bitrate (GstMssManifest * manifest);

GstMssStreamType gst_mss_stream_get_type (GstMssStream *stream);
GstCaps * gst_mss_stream_get_caps (GstMssStream * stream);
void gst_mss_stream_set_active (GstMssStream * stream, gboolean active);
guint64 gst_mss_stream_get_timescale (GstMssStream * stream);
GstFlowReturn gst_mss_stream_get_fragment_url (GstMssStream * stream, gchar ** url);
GstClockTime gst_mss_stream_get_fragment_gst_timestamp (GstMssStream * stream);
GstClockTime gst_mss_stream_get_fragment_gst_duration (GstMssStream * stream);
GstFlowReturn gst_mss_stream_advance_fragment (GstMssStream * stream);
gboolean gst_mss_stream_seek (GstMssStream * stream, guint64 time);

const gchar * gst_mss_stream_type_name (GstMssStreamType streamtype);

G_END_DECLS
#endif /* __GST_MSS_MANIFEST_H__ */
