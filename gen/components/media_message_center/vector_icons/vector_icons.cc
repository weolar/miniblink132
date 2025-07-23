// Copyright 2020 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// vector_icons.cc.template is used to generate vector_icons.cc. Edit the former
// rather than the latter.

#include "components/media_message_center/vector_icons/vector_icons.h"

#include "components/vector_icons/cc_macros.h"
#include "ui/gfx/vector_icon_types.h"

#define DECLARE_VECTOR_COMMAND(x) using gfx::x;
DECLARE_VECTOR_COMMANDS

namespace media_message_center {

VECTOR_ICON_REP_TEMPLATE(kChevronRightPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 10, 6, LINE_TO, 8.59f, 7.41f, LINE_TO, 13.17f, 12, R_LINE_TO, -4.58f, 4.59f,
    LINE_TO, 10, 18, R_LINE_TO, 6, -6, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kChevronRightRepList, kChevronRightIcon, { kChevronRightPath, std::size(kChevronRightPath) })
VECTOR_ICON_REP_TEMPLATE(kMediaCastStartPath, MOVE_TO, 42, 6, H_LINE_TO, 6, R_CUBIC_TO, -2.2f, 0, -4, 1.8f, -4, 4, R_V_LINE_TO, 6, R_H_LINE_TO, 4, R_V_LINE_TO,
    -6, R_H_LINE_TO, 36, R_V_LINE_TO, 28, H_LINE_TO, 28, R_V_LINE_TO, 4, R_H_LINE_TO, 14, R_CUBIC_TO, 2.2f, 0, 4, -1.8f, 4, -4, V_LINE_TO, 10, R_CUBIC_TO, 0,
    -2.2f, -1.8f, -4, -4, -4, CLOSE, MOVE_TO, 2, 36, R_V_LINE_TO, 6, R_H_LINE_TO, 6, R_CUBIC_TO, 0, -3.3f, -2.7f, -6, -6, -6, CLOSE, R_MOVE_TO, 0, -8,
    R_V_LINE_TO, 4, R_CUBIC_TO, 5.5f, 0, 10, 4.5f, 10, 10, R_H_LINE_TO, 4, R_CUBIC_TO, 0, -7.7f, -6.3f, -14, -14, -14, CLOSE, R_MOVE_TO, 0, -8, R_V_LINE_TO, 4,
    R_CUBIC_TO, 9.9f, 0, 18, 8.1f, 18, 18, R_H_LINE_TO, 4, R_CUBIC_TO, 0, -12.2f, -9.9f, -22, -22, -22, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kMediaCastStartRepList, kMediaCastStartIcon, { kMediaCastStartPath, std::size(kMediaCastStartPath) })
VECTOR_ICON_REP_TEMPLATE(kMediaCastStopPath, CANVAS_DIMENSIONS, 20, MOVE_TO, 7, 13, R_H_LINE_TO, 6, V_LINE_TO, 7, H_LINE_TO, 7, R_V_LINE_TO, 6, CLOSE,
    R_MOVE_TO, 3, 5, R_ARC_TO, 7.8f, 7.8f, 0, 0, 1, -3.1f, -0.62f, R_ARC_TO, 8.28f, 8.28f, 0, 0, 1, -2.56f, -1.71f, R_ARC_TO, 8.28f, 8.28f, 0, 0, 1, -1.71f,
    -2.56f, ARC_TO, 7.8f, 7.8f, 0, 0, 1, 2, 10, R_ARC_TO, 7.7f, 7.7f, 0, 0, 1, 0.63f, -3.1f, R_ARC_TO, 8.03f, 8.03f, 0, 0, 1, 4.27f, -4.27f, ARC_TO, 7.8f, 7.8f,
    0, 0, 1, 10, 2, R_ARC_TO, 7.7f, 7.7f, 0, 0, 1, 3.1f, 0.63f, R_CUBIC_TO, 0.97f, 0.42f, 1.82f, 0.99f, 2.54f, 1.73f, R_ARC_TO, 7.86f, 7.86f, 0, 0, 1, 1.73f,
    2.54f, ARC_TO, 7.7f, 7.7f, 0, 0, 1, 18, 10, R_ARC_TO, 7.8f, 7.8f, 0, 0, 1, -0.62f, 3.1f, R_ARC_TO, 8.03f, 8.03f, 0, 0, 1, -4.27f, 4.27f, R_ARC_TO, 7.7f,
    7.7f, 0, 0, 1, -3.1f, 0.63f, CLOSE, R_MOVE_TO, 0, -1.5f, R_CUBIC_TO, 1.81f, 0, 3.34f, -0.63f, 4.6f, -1.9f, CUBIC_TO, 15.87f, 13.34f, 16.5f, 11.81f, 16.5f,
    10, R_CUBIC_TO, 0, -1.81f, -0.63f, -3.34f, -1.9f, -4.6f, CUBIC_TO, 13.34f, 4.13f, 11.81f, 3.5f, 10, 3.5f, R_CUBIC_TO, -1.81f, 0, -3.34f, 0.63f, -4.6f, 1.9f,
    CUBIC_TO, 4.13f, 6.66f, 3.5f, 8.19f, 3.5f, 10, R_CUBIC_TO, 0, 1.81f, 0.63f, 3.34f, 1.9f, 4.6f, CUBIC_TO, 6.66f, 15.87f, 8.19f, 16.5f, 10, 16.5f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kMediaCastStopRepList, kMediaCastStopIcon, { kMediaCastStopPath, std::size(kMediaCastStopPath) })
VECTOR_ICON_REP_TEMPLATE(kMediaEnterPipPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 12, 7, H_LINE_TO, 7, R_V_LINE_TO, 4, R_H_LINE_TO, 5, V_LINE_TO, 7, CLOSE,
    R_MOVE_TO, 3, 5.67f, V_LINE_TO, 3.32f, CUBIC_TO, 15, 2.59f, 14.43f, 2, 13.73f, 2, H_LINE_TO, 2.27f, CUBIC_TO, 1.57f, 2, 1, 2.59f, 1, 3.32f, R_V_LINE_TO,
    9.35f, CUBIC_TO, 1, 13.4f, 1.57f, 14, 2.27f, 14, R_H_LINE_TO, 11.45f, R_CUBIC_TO, 0.7f, 0, 1.27f, -0.6f, 1.27f, -1.33f, CLOSE, R_MOVE_TO, -1.5f, -0.17f,
    R_H_LINE_TO, -11, R_V_LINE_TO, -9, R_H_LINE_TO, 11, R_V_LINE_TO, 9, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kMediaEnterPipRepList, kMediaEnterPipIcon, { kMediaEnterPipPath, std::size(kMediaEnterPipPath) })
VECTOR_ICON_REP_TEMPLATE(kMediaExitPipPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 13.73f, 2, R_CUBIC_TO, 0.7f, 0, 1.27f, 0.59f, 1.27f, 1.32f, V_LINE_TO, 9,
    R_H_LINE_TO, -1.5f, V_LINE_TO, 3.5f, R_H_LINE_TO, -11, R_V_LINE_TO, 9, H_LINE_TO, 9, V_LINE_TO, 14, H_LINE_TO, 2.27f, CUBIC_TO, 1.57f, 14, 1, 13.4f, 1,
    12.67f, V_LINE_TO, 3.32f, CUBIC_TO, 1, 2.59f, 1.57f, 2, 2.27f, 2, CLOSE, MOVE_TO, 9, 5, H_LINE_TO, 4, R_V_LINE_TO, 4, R_H_LINE_TO, 5, CLOSE, MOVE_TO, 12,
    10, R_V_LINE_TO, 4, R_H_LINE_TO, -1, R_V_LINE_TO, -4, CLOSE, MOVE_TO, 11.71f, 10, R_LINE_TO, 4.24f, 4.24f, R_LINE_TO, -0.71f, 0.71f, LINE_TO, 11, 10.71f,
    CLOSE, MOVE_TO, 11, 10, R_H_LINE_TO, 4, R_V_LINE_TO, 1, R_H_LINE_TO, -4, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kMediaExitPipRepList, kMediaExitPipIcon, { kMediaExitPipPath, std::size(kMediaExitPipPath) })
VECTOR_ICON_REP_TEMPLATE(kMediaNextTrackPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 3, 13, LINE_TO, 9, 8, LINE_TO, 3, 3, LINE_TO, 3, 13, CLOSE, MOVE_TO, 11, 3,
    LINE_TO, 11, 13, LINE_TO, 13, 13, LINE_TO, 13, 3, LINE_TO, 11, 3, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kMediaNextTrackRepList, kMediaNextTrackIcon, { kMediaNextTrackPath, std::size(kMediaNextTrackPath) })
VECTOR_ICON_REP_TEMPLATE(kMediaPreviousTrackPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 3, 3, LINE_TO, 5, 3, LINE_TO, 5, 13, LINE_TO, 3, 13, LINE_TO, 3, 3, CLOSE,
    MOVE_TO, 7, 8, LINE_TO, 13, 13, LINE_TO, 13, 3, LINE_TO, 7, 8, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kMediaPreviousTrackRepList, kMediaPreviousTrackIcon, { kMediaPreviousTrackPath, std::size(kMediaPreviousTrackPath) })
VECTOR_ICON_REP_TEMPLATE(kMediaSeekBackwardPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 8, 13, LINE_TO, 8, 3, LINE_TO, 2, 8, LINE_TO, 8, 13, CLOSE, MOVE_TO, 8, 8,
    LINE_TO, 14, 13, LINE_TO, 14, 3, LINE_TO, 8, 8, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kMediaSeekBackwardRepList, kMediaSeekBackwardIcon, { kMediaSeekBackwardPath, std::size(kMediaSeekBackwardPath) })
VECTOR_ICON_REP_TEMPLATE(kMediaSeekForwardPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 2, 13, LINE_TO, 8, 8, LINE_TO, 2, 3, LINE_TO, 2, 13, CLOSE, MOVE_TO, 8, 3,
    LINE_TO, 8, 13, LINE_TO, 14, 8, LINE_TO, 8, 3, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kMediaSeekForwardRepList, kMediaSeekForwardIcon, { kMediaSeekForwardPath, std::size(kMediaSeekForwardPath) })
VECTOR_ICON_REP_TEMPLATE(kPausePath, CANVAS_DIMENSIONS, 16, MOVE_TO, 7, 2, LINE_TO, 7, 14, LINE_TO, 4, 14, LINE_TO, 4, 2, LINE_TO, 7, 2, CLOSE, MOVE_TO, 12, 2,
    LINE_TO, 12, 14, LINE_TO, 9, 14, LINE_TO, 9, 2, LINE_TO, 12, 2, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kPauseRepList, kPauseIcon, { kPausePath, std::size(kPausePath) })
VECTOR_ICON_REP_TEMPLATE(kPlayArrowPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 6, 13, R_LINE_TO, 6, -5, R_LINE_TO, -6, -5, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kPlayArrowRepList, kPlayArrowIcon, { kPlayArrowPath, std::size(kPlayArrowPath) })

}
