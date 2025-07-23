// Copyright 2020 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// vector_icons.h.template is used to generate vector_icons.h. Edit the former
// rather than the latter.

#ifndef COMPONENTS_MEDIA_MESSAGE_CENTER_VECTOR_ICONS_H_
#define COMPONENTS_MEDIA_MESSAGE_CENTER_VECTOR_ICONS_H_

namespace gfx {
struct VectorIcon;
}

namespace media_message_center {

#define VECTOR_ICON_TEMPLATE_H(icon_name) extern const gfx::VectorIcon icon_name;

VECTOR_ICON_TEMPLATE_H(kChevronRightIcon)
VECTOR_ICON_TEMPLATE_H(kMediaCastStartIcon)
VECTOR_ICON_TEMPLATE_H(kMediaCastStopIcon)
VECTOR_ICON_TEMPLATE_H(kMediaEnterPipIcon)
VECTOR_ICON_TEMPLATE_H(kMediaExitPipIcon)
VECTOR_ICON_TEMPLATE_H(kMediaNextTrackIcon)
VECTOR_ICON_TEMPLATE_H(kMediaPreviousTrackIcon)
VECTOR_ICON_TEMPLATE_H(kMediaSeekBackwardIcon)
VECTOR_ICON_TEMPLATE_H(kMediaSeekForwardIcon)
VECTOR_ICON_TEMPLATE_H(kPauseIcon)
VECTOR_ICON_TEMPLATE_H(kPlayArrowIcon)

#undef VECTOR_ICON_TEMPLATE_H

}

#endif // COMPONENTS_MEDIA_MESSAGE_CENTER_VECTOR_ICONS_H_
