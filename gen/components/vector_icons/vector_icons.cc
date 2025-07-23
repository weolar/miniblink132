// Copyright 2017 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// vector_icons.cc.template is used to generate vector_icons.cc. Edit the former
// rather than the latter.

#include "components/vector_icons/vector_icons.h"

#include "components/vector_icons/cc_macros.h"
#include "ui/gfx/vector_icon_types.h"

#define DECLARE_VECTOR_COMMAND(x) using gfx::x;
DECLARE_VECTOR_COMMANDS

namespace vector_icons {

VECTOR_ICON_REP_TEMPLATE(kProductPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 12, 7.5f, R_H_LINE_TO, 8.9f, CUBIC_TO, 19.3f, 4.2f, 15.9f, 2, 12, 2, CUBIC_TO, 8.9f, 2,
    6.1f, 3.4f, 4.3f, 5.6f, R_LINE_TO, 3.3f, 5.7f, R_CUBIC_TO, 0.3f, -2.1f, 2.2f, -3.8f, 4.4f, -3.8f, CLOSE, R_MOVE_TO, 0, 9, R_CUBIC_TO, -1.7f, 0, -3.1f,
    -0.9f, -3.9f, -2.3f, LINE_TO, 3.6f, 6.5f, CUBIC_TO, 2.6f, 8.1f, 2, 10, 2, 12, R_CUBIC_TO, 0, 5, 3.6f, 9.1f, 8.4f, 9.9f, R_LINE_TO, 3.3f, -5.7f, R_CUBIC_TO,
    -0.6f, 0.2f, -1.1f, 0.3f, -1.7f, 0.3f, CLOSE, R_MOVE_TO, 4.5f, -4.5f, R_CUBIC_TO, 0, 0.8f, -0.2f, 1.6f, -0.6f, 2.2f, LINE_TO, 11.4f, 22, R_H_LINE_TO, 0.6f,
    R_CUBIC_TO, 5.5f, 0, 10, -4.5f, 10, -10, R_CUBIC_TO, 0, -1.2f, -0.2f, -2.4f, -0.6f, -3.5f, R_H_LINE_TO, -6.6f, R_CUBIC_TO, 1, 0.8f, 1.7f, 2.1f, 1.7f, 3.5f,
    CLOSE, CIRCLE, 12, 12, 3.5)
VECTOR_ICON_TEMPLATE_CC(kProductRepList, kProductIcon, { kProductPath, std::size(kProductPath) })
VECTOR_ICON_REP_TEMPLATE(kProductRefreshPath, CANVAS_DIMENSIONS, 24, FILL_RULE_NONZERO, PATH_COLOR_ARGB, 0xFF, 0xFF, 0xFF, 0xFF, MOVE_TO, 12, 17.99f, CUBIC_TO,
    15.31f, 17.99f, 18, 15.31f, 18, 11.99f, CUBIC_TO, 18, 8.68f, 15.31f, 5.99f, 12, 5.99f, CUBIC_TO, 8.69f, 5.99f, 6, 8.68f, 6, 11.99f, CUBIC_TO, 6, 15.31f,
    8.69f, 17.99f, 12, 17.99f, CLOSE, NEW_PATH, FILL_RULE_NONZERO, PATH_COLOR_ARGB, 0xFF, 0xAE, 0xCB, 0xFA, MOVE_TO, 17.2f, 15, LINE_TO, 12.01f, 23.99f,
    CUBIC_TO, 14.11f, 23.99f, 16.18f, 23.44f, 18, 22.39f, CUBIC_TO, 19.83f, 21.33f, 21.34f, 19.82f, 22.4f, 18, CUBIC_TO, 23.45f, 16.17f, 24, 14.1f, 24, 12,
    CUBIC_TO, 24, 9.89f, 23.44f, 7.82f, 22.38f, 6, LINE_TO, 12, 6, LINE_TO, 11.99f, 6.01f, CUBIC_TO, 13.05f, 6, 14.08f, 6.28f, 15, 6.8f, CUBIC_TO, 15.91f,
    7.33f, 16.67f, 8.08f, 17.2f, 9, CUBIC_TO, 17.73f, 9.91f, 18, 10.94f, 18, 12, CUBIC_TO, 18, 13.05f, 17.72f, 14.09f, 17.2f, 15, V_LINE_TO, 15, CLOSE,
    NEW_PATH, FILL_RULE_NONZERO, PATH_COLOR_ARGB, 0xFF, 0x66, 0x9D, 0xF6, MOVE_TO, 6.8f, 15, LINE_TO, 1.61f, 6.01f, CUBIC_TO, 0.56f, 7.83f, 0, 9.9f, 0, 12.01f,
    CUBIC_TO, 0, 14.11f, 0.56f, 16.18f, 1.61f, 18.01f, CUBIC_TO, 2.66f, 19.83f, 4.18f, 21.34f, 6.01f, 22.39f, CUBIC_TO, 7.83f, 23.44f, 9.9f, 23.99f, 12.01f,
    23.99f, LINE_TO, 17.2f, 15, V_LINE_TO, 14.99f, CUBIC_TO, 16.67f, 15.9f, 15.92f, 16.66f, 15, 17.19f, CUBIC_TO, 14.09f, 17.72f, 13.06f, 18, 12, 18, CUBIC_TO,
    10.95f, 18, 9.91f, 17.73f, 9, 17.2f, CUBIC_TO, 8.09f, 16.67f, 7.33f, 15.91f, 6.8f, 15, V_LINE_TO, 15, CLOSE, NEW_PATH, FILL_RULE_NONZERO, PATH_COLOR_ARGB,
    0xFF, 0x1A, 0x73, 0xE8, MOVE_TO, 12, 16.75f, CUBIC_TO, 14.62f, 16.75f, 16.75f, 14.62f, 16.75f, 12, CUBIC_TO, 16.75f, 9.38f, 14.62f, 7.25f, 12, 7.25f,
    CUBIC_TO, 9.38f, 7.25f, 7.25f, 9.38f, 7.25f, 12, CUBIC_TO, 7.25f, 14.62f, 9.38f, 16.75f, 12, 16.75f, CLOSE, NEW_PATH, FILL_RULE_NONZERO, PATH_COLOR_ARGB,
    0xFF, 0x19, 0x67, 0xD2, MOVE_TO, 12, 6, H_LINE_TO, 22.38f, CUBIC_TO, 21.33f, 4.18f, 19.82f, 2.66f, 17.99f, 1.61f, CUBIC_TO, 16.17f, 0.55f, 14.1f, 0, 11.99f,
    0, CUBIC_TO, 9.89f, 0, 7.82f, 0.56f, 6, 1.61f, CUBIC_TO, 4.17f, 2.67f, 2.66f, 4.18f, 1.61f, 6.01f, LINE_TO, 6.8f, 15, LINE_TO, 6.81f, 15, CUBIC_TO, 6.28f,
    14.09f, 6, 13.06f, 6, 12, CUBIC_TO, 6, 10.95f, 6.27f, 9.91f, 6.8f, 9, CUBIC_TO, 7.33f, 8.09f, 8.08f, 7.33f, 9, 6.8f, CUBIC_TO, 9.91f, 6.28f, 10.95f, 6, 12,
    6, V_LINE_TO, 6, CLOSE, NEW_PATH)
VECTOR_ICON_TEMPLATE_CC(kProductRefreshRepList, kProductRefreshIcon, { kProductRefreshPath, std::size(kProductRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kAccountCirclePath, CANVAS_DIMENSIONS, 24, MOVE_TO, 5.85f, 17.1f, R_QUADRATIC_TO, 1.27f, -0.97f, 2.85f, -1.54f, QUADRATIC_TO, 10.28f,
    15, 12, 15, R_QUADRATIC_TO, 1.73f, 0, 3.3f, 0.56f, R_QUADRATIC_TO, 1.58f, 0.56f, 2.85f, 1.54f, R_QUADRATIC_TO, 0.88f, -1.02f, 1.36f, -2.33f, QUADRATIC_TO,
    20, 13.48f, 20, 12, R_QUADRATIC_TO, 0, -3.32f, -2.34f, -5.66f, QUADRATIC_TO, 15.33f, 4, 12, 4, QUADRATIC_TO_SHORTHAND, 6.34f, 6.34f, QUADRATIC_TO, 4, 8.68f,
    4, 12, R_QUADRATIC_TO, 0, 1.48f, 0.49f, 2.78f, R_QUADRATIC_TO, 0.49f, 1.3f, 1.36f, 2.33f, CLOSE, MOVE_TO, 12, 13, R_QUADRATIC_TO, -1.47f, 0, -2.49f, -1.01f,
    QUADRATIC_TO, 8.5f, 10.98f, 8.5f, 9.5f, R_QUADRATIC_TO, 0, -1.48f, 1.01f, -2.49f, QUADRATIC_TO, 10.53f, 6, 12, 6, R_QUADRATIC_TO, 1.47f, 0, 2.49f, 1.01f,
    QUADRATIC_TO, 15.5f, 8.03f, 15.5f, 9.5f, R_QUADRATIC_TO, 0, 1.47f, -1.01f, 2.49f, QUADRATIC_TO, 13.48f, 13, 12, 13, CLOSE, R_MOVE_TO, 0, 9, R_QUADRATIC_TO,
    -2.08f, 0, -3.9f, -0.79f, R_QUADRATIC_TO, -1.82f, -0.79f, -3.17f, -2.14f, R_QUADRATIC_TO, -1.35f, -1.35f, -2.14f, -3.17f, QUADRATIC_TO, 2, 14.08f, 2, 12,
    R_QUADRATIC_TO, 0, -2.08f, 0.79f, -3.9f, R_QUADRATIC_TO, 0.79f, -1.82f, 2.14f, -3.17f, R_QUADRATIC_TO, 1.35f, -1.35f, 3.18f, -2.14f, QUADRATIC_TO, 9.93f, 2,
    12, 2, R_QUADRATIC_TO, 2.07f, 0, 3.9f, 0.79f, R_QUADRATIC_TO, 1.83f, 0.79f, 3.18f, 2.14f, R_QUADRATIC_TO, 1.35f, 1.35f, 2.14f, 3.18f, QUADRATIC_TO, 22,
    9.93f, 22, 12, R_QUADRATIC_TO, 0, 2.07f, -0.79f, 3.9f, R_QUADRATIC_TO, -0.79f, 1.83f, -2.14f, 3.18f, R_QUADRATIC_TO, -1.35f, 1.35f, -3.17f, 2.14f,
    QUADRATIC_TO, 14.08f, 22, 12, 22, CLOSE, R_MOVE_TO, 0, -2, R_QUADRATIC_TO, 1.33f, 0, 2.5f, -0.39f, R_QUADRATIC_TO, 1.18f, -0.39f, 2.15f, -1.11f,
    R_QUADRATIC_TO, -0.97f, -0.72f, -2.15f, -1.11f, QUADRATIC_TO, 13.33f, 17, 12, 17, R_QUADRATIC_TO, -1.33f, 0, -2.5f, 0.39f, R_QUADRATIC_TO, -1.17f, 0.39f,
    -2.15f, 1.11f, R_QUADRATIC_TO, 0.98f, 0.73f, 2.15f, 1.11f, QUADRATIC_TO, 10.68f, 20, 12, 20, CLOSE, R_MOVE_TO, 0, -9, R_QUADRATIC_TO, 0.65f, 0, 1.08f,
    -0.42f, R_QUADRATIC_TO, 0.43f, -0.42f, 0.43f, -1.07f, R_QUADRATIC_TO, 0, -0.65f, -0.42f, -1.07f, QUADRATIC_TO, 12.65f, 8, 12, 8, R_QUADRATIC_TO, -0.65f, 0,
    -1.07f, 0.43f, QUADRATIC_TO, 10.5f, 8.85f, 10.5f, 9.5f, R_QUADRATIC_TO, 0, 0.65f, 0.43f, 1.08f, QUADRATIC_TO, 11.35f, 11, 12, 11, CLOSE, R_MOVE_TO, 0,
    -1.5f, CLOSE, R_MOVE_TO, 0, 9, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kAccountCircleRepList, kAccountCircleIcon, { kAccountCirclePath, std::size(kAccountCirclePath) })
VECTOR_ICON_REP_TEMPLATE(kAccountCircleChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 4.94f, 14.06f, R_ARC_TO, 8.24f, 8.24f, 0, 0, 1,
    2.41f, -1.18f, ARC_TO, 9.14f, 9.14f, 0, 0, 1, 10, 12.5f, R_CUBIC_TO, 0.92f, 0, 1.8f, 0.13f, 2.66f, 0.39f, R_ARC_TO, 8.24f, 8.24f, 0, 0, 1, 2.41f, 1.18f,
    R_ARC_TO, 5.78f, 5.78f, 0, 0, 0, 1.08f, -1.89f, ARC_TO, 6.64f, 6.64f, 0, 0, 0, 16.5f, 10, R_CUBIC_TO, 0, -1.8f, -0.63f, -3.34f, -1.9f, -4.6f, CUBIC_TO,
    13.33f, 4.13f, 11.8f, 3.5f, 10, 3.5f, R_CUBIC_TO, -1.8f, 0, -3.34f, 0.63f, -4.6f, 1.9f, CUBIC_TO, 4.13f, 6.66f, 3.5f, 8.2f, 3.5f, 10, R_CUBIC_TO, 0, 0.75f,
    0.12f, 1.47f, 0.36f, 2.17f, R_ARC_TO, 5.78f, 5.78f, 0, 0, 0, 1.08f, 1.9f, CLOSE, MOVE_TO, 10, 11.5f, R_ARC_TO, 2.9f, 2.9f, 0, 0, 1, -2.12f, -0.87f, ARC_TO,
    2.9f, 2.9f, 0, 0, 1, 7, 8.5f, R_CUBIC_TO, 0, -0.83f, 0.29f, -1.54f, 0.88f, -2.12f, ARC_TO, 2.9f, 2.9f, 0, 0, 1, 10, 5.5f, R_CUBIC_TO, 0.83f, 0, 1.54f,
    0.29f, 2.13f, 0.88f, R_CUBIC_TO, 0.58f, 0.58f, 0.88f, 1.29f, 0.88f, 2.13f, R_CUBIC_TO, 0, 0.83f, -0.29f, 1.54f, -0.87f, 2.13f, ARC_TO, 2.9f, 2.9f, 0, 0, 1,
    10, 11.5f, CLOSE, R_MOVE_TO, 0, 6.5f, R_ARC_TO, 7.8f, 7.8f, 0, 0, 1, -3.11f, -0.62f, R_ARC_TO, 8.07f, 8.07f, 0, 0, 1, -2.55f, -1.72f, R_ARC_TO, 8.07f,
    8.07f, 0, 0, 1, -1.72f, -2.55f, ARC_TO, 7.8f, 7.8f, 0, 0, 1, 2, 9.99f, R_CUBIC_TO, 0, -1.1f, 0.21f, -2.14f, 0.63f, -3.1f, R_ARC_TO, 8.12f, 8.12f, 0, 0, 1,
    1.72f, -2.54f, R_CUBIC_TO, 0.73f, -0.73f, 1.58f, -1.3f, 2.55f, -1.72f, ARC_TO, 7.8f, 7.8f, 0, 0, 1, 10.01f, 2, R_CUBIC_TO, 1.11f, 0, 2.14f, 0.21f, 3.11f,
    0.63f, R_ARC_TO, 8.12f, 8.12f, 0, 0, 1, 2.54f, 1.72f, R_CUBIC_TO, 0.73f, 0.73f, 1.3f, 1.58f, 1.72f, 2.55f, R_CUBIC_TO, 0.42f, 0.97f, 0.63f, 2, 0.63f, 3.11f,
    R_ARC_TO, 7.8f, 7.8f, 0, 0, 1, -0.62f, 3.11f, R_ARC_TO, 8.07f, 8.07f, 0, 0, 1, -1.72f, 2.55f, R_CUBIC_TO, -0.73f, 0.73f, -1.58f, 1.3f, -2.55f, 1.72f,
    R_ARC_TO, 7.75f, 7.75f, 0, 0, 1, -3.1f, 0.63f, CLOSE, MOVE_TO, 10, 16.5f, R_CUBIC_TO, 0.72f, 0, 1.42f, -0.11f, 2.08f, -0.34f, R_ARC_TO, 6.62f, 6.62f, 0, 0,
    0, 1.88f, -1.01f, R_ARC_TO, 7.36f, 7.36f, 0, 0, 0, -1.89f, -0.85f, ARC_TO, 7.31f, 7.31f, 0, 0, 0, 10, 14, R_CUBIC_TO, -0.71f, 0, -1.4f, 0.09f, -2.07f,
    0.28f, R_CUBIC_TO, -0.67f, 0.19f, -1.3f, 0.48f, -1.88f, 0.86f, R_ARC_TO, 6.62f, 6.62f, 0, 0, 0, 1.88f, 1.01f, R_CUBIC_TO, 0.66f, 0.23f, 1.36f, 0.34f, 2.08f,
    0.34f, CLOSE, R_MOVE_TO, 0, -6.5f, R_CUBIC_TO, 0.42f, 0, 0.77f, -0.14f, 1.06f, -0.44f, R_CUBIC_TO, 0.29f, -0.29f, 0.44f, -0.64f, 0.44f, -1.06f, R_CUBIC_TO,
    0, -0.42f, -0.14f, -0.77f, -0.44f, -1.06f, ARC_TO, 1.44f, 1.44f, 0, 0, 0, 10, 7, R_CUBIC_TO, -0.42f, 0, -0.77f, 0.14f, -1.06f, 0.44f, ARC_TO, 1.44f, 1.44f,
    0, 0, 0, 8.5f, 8.5f, R_CUBIC_TO, 0, 0.42f, 0.14f, 0.77f, 0.44f, 1.06f, R_CUBIC_TO, 0.29f, 0.29f, 0.64f, 0.44f, 1.06f, 0.44f, CLOSE, R_MOVE_TO, 0, -1.5f,
    CLOSE, R_MOVE_TO, 0, 6.65f, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kAccountCircleChromeRefresh16Path, CANVAS_DIMENSIONS, 16, FILL_RULE_NONZERO, MOVE_TO, 3.97f, 11.19f, R_ARC_TO, 6.59f, 6.59f, 0, 0, 1,
    1.92f, -0.92f, R_CUBIC_TO, 0.68f, -0.2f, 1.38f, -0.3f, 2.11f, -0.3f, R_CUBIC_TO, 0.73f, 0, 1.44f, 0.1f, 2.12f, 0.31f, R_CUBIC_TO, 0.68f, 0.21f, 1.32f,
    0.51f, 1.91f, 0.93f, R_CUBIC_TO, 0.38f, -0.46f, 0.66f, -0.96f, 0.84f, -1.5f, ARC_TO, 5.23f, 5.23f, 0, 0, 0, 13.15f, 8, R_CUBIC_TO, 0, -1.43f, -0.5f, -2.64f,
    -1.51f, -3.64f, R_CUBIC_TO, -1.01f, -1, -2.22f, -1.51f, -3.65f, -1.51f, R_CUBIC_TO, -1.43f, 0, -2.64f, 0.5f, -3.64f, 1.51f, CUBIC_TO, 3.35f, 5.36f, 2.85f,
    6.58f, 2.85f, 8, R_CUBIC_TO, 0, 0.59f, 0.09f, 1.15f, 0.27f, 1.69f, R_CUBIC_TO, 0.18f, 0.54f, 0.47f, 1.04f, 0.85f, 1.5f, CLOSE, MOVE_TO, 8, 9.23f,
    R_CUBIC_TO, -0.68f, 0, -1.25f, -0.23f, -1.72f, -0.7f, R_ARC_TO, 2.35f, 2.35f, 0, 0, 1, -0.71f, -1.72f, R_CUBIC_TO, 0, -0.68f, 0.24f, -1.25f, 0.71f, -1.72f,
    ARC_TO, 2.35f, 2.35f, 0, 0, 1, 8, 4.38f, R_CUBIC_TO, 0.68f, 0, 1.25f, 0.24f, 1.72f, 0.71f, R_CUBIC_TO, 0.47f, 0.47f, 0.71f, 1.04f, 0.71f, 1.72f, R_CUBIC_TO,
    0, 0.68f, -0.24f, 1.25f, -0.71f, 1.72f, ARC_TO, 2.36f, 2.36f, 0, 0, 1, 8, 9.23f, CLOSE, R_MOVE_TO, 0, 5.3f, R_ARC_TO, 6.38f, 6.38f, 0, 0, 1, -2.54f, -0.51f,
    R_ARC_TO, 6.59f, 6.59f, 0, 0, 1, -3.49f, -3.49f, R_ARC_TO, 6.39f, 6.39f, 0, 0, 1, -0.51f, -2.54f, R_CUBIC_TO, 0, -0.9f, 0.17f, -1.75f, 0.51f, -2.53f,
    R_ARC_TO, 6.6f, 6.6f, 0, 0, 1, 3.49f, -3.48f, R_ARC_TO, 6.39f, 6.39f, 0, 0, 1, 2.54f, -0.51f, R_CUBIC_TO, 0.9f, 0, 1.75f, 0.17f, 2.54f, 0.51f, R_ARC_TO,
    6.6f, 6.6f, 0, 0, 1, 3.48f, 3.49f, R_CUBIC_TO, 0.34f, 0.79f, 0.51f, 1.64f, 0.51f, 2.54f, R_ARC_TO, 6.38f, 6.38f, 0, 0, 1, -0.51f, 2.54f, R_ARC_TO, 6.59f,
    6.59f, 0, 0, 1, -3.49f, 3.49f, R_CUBIC_TO, -0.79f, 0.34f, -1.64f, 0.51f, -2.53f, 0.51f, CLOSE, MOVE_TO, 8, 13.15f, R_CUBIC_TO, 0.57f, 0, 1.11f, -0.09f,
    1.62f, -0.26f, R_ARC_TO, 5.38f, 5.38f, 0, 0, 0, 1.48f, -0.78f, R_ARC_TO, 6.2f, 6.2f, 0, 0, 0, -1.49f, -0.66f, ARC_TO, 5.74f, 5.74f, 0, 0, 0, 8, 11.22f,
    R_CUBIC_TO, -0.56f, 0, -1.1f, 0.07f, -1.61f, 0.21f, R_ARC_TO, 5.29f, 5.29f, 0, 0, 0, -1.48f, 0.67f, R_CUBIC_TO, 0.46f, 0.34f, 0.96f, 0.61f, 1.47f, 0.78f,
    ARC_TO, 4.99f, 4.99f, 0, 0, 0, 8, 13.15f, CLOSE, R_MOVE_TO, 0, -5.17f, R_CUBIC_TO, 0.32f, 0, 0.6f, -0.11f, 0.82f, -0.34f, R_CUBIC_TO, 0.23f, -0.23f, 0.34f,
    -0.5f, 0.34f, -0.82f, R_CUBIC_TO, 0, -0.32f, -0.11f, -0.6f, -0.34f, -0.83f, R_CUBIC_TO, -0.23f, -0.23f, -0.5f, -0.34f, -0.82f, -0.34f, R_CUBIC_TO, -0.32f,
    0, -0.6f, 0.11f, -0.82f, 0.34f, R_CUBIC_TO, -0.23f, 0.23f, -0.34f, 0.5f, -0.34f, 0.83f, R_CUBIC_TO, 0, 0.32f, 0.11f, 0.6f, 0.34f, 0.82f, R_CUBIC_TO, 0.23f,
    0.23f, 0.5f, 0.34f, 0.82f, 0.34f, CLOSE, R_MOVE_TO, 0, -1.17f, CLOSE, R_MOVE_TO, 0, 5.3f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kAccountCircleChromeRefreshRepList, kAccountCircleChromeRefreshIcon,
    { kAccountCircleChromeRefreshPath, std::size(kAccountCircleChromeRefreshPath) },
    { kAccountCircleChromeRefresh16Path, std::size(kAccountCircleChromeRefresh16Path) })
VECTOR_ICON_REP_TEMPLATE(kAccountCircleOffChromeRefreshPath, CANVAS_DIMENSIONS, 24, FILL_RULE_NONZERO, MOVE_TO, 13.55f, 10.45f, CLOSE, R_MOVE_TO, -2.97f, 2.97f,
    CLOSE, MOVE_TO, 12, 19.93f, R_CUBIC_TO, 0.82f, 0, 1.62f, -0.12f, 2.39f, -0.38f, R_ARC_TO, 8.23f, 8.23f, 0, 0, 0, 2.16f, -1.07f, R_ARC_TO, 8.18f, 8.18f, 0,
    0, 0, -2.16f, -1.07f, ARC_TO, 7.67f, 7.67f, 0, 0, 0, 12, 17.04f, R_CUBIC_TO, -0.82f, 0, -1.62f, 0.13f, -2.39f, 0.38f, R_CUBIC_TO, -0.76f, 0.25f, -1.48f,
    0.61f, -2.16f, 1.07f, R_CUBIC_TO, 0.67f, 0.47f, 1.39f, 0.82f, 2.16f, 1.07f, R_ARC_TO, 7.54f, 7.54f, 0, 0, 0, 2.39f, 0.38f, CLOSE, R_MOVE_TO, 2.78f, -8.21f,
    R_LINE_TO, -1.53f, -1.54f, R_ARC_TO, 1.51f, 1.51f, 0, 0, 0, 0.15f, -0.32f, R_CUBIC_TO, 0.04f, -0.12f, 0.06f, -0.23f, 0.06f, -0.34f, R_CUBIC_TO, 0, -0.41f,
    -0.14f, -0.75f, -0.43f, -1.03f, ARC_TO, 1.39f, 1.39f, 0, 0, 0, 12, 8.06f, R_CUBIC_TO, -0.12f, 0, -0.23f, 0.02f, -0.35f, 0.06f, R_CUBIC_TO, -0.11f, 0.04f,
    -0.22f, 0.09f, -0.32f, 0.16f, LINE_TO, 9.8f, 6.74f, R_ARC_TO, 3.12f, 3.12f, 0, 0, 1, 1.03f, -0.58f, ARC_TO, 3.58f, 3.58f, 0, 0, 1, 12, 5.97f, R_CUBIC_TO,
    0.98f, 0, 1.82f, 0.34f, 2.51f, 1.03f, R_CUBIC_TO, 0.69f, 0.69f, 1.03f, 1.53f, 1.03f, 2.51f, R_CUBIC_TO, 0, 0.41f, -0.06f, 0.8f, -0.19f, 1.18f, R_CUBIC_TO,
    -0.12f, 0.37f, -0.32f, 0.71f, -0.58f, 1.02f, CLOSE, R_MOVE_TO, 5.8f, 5.81f, R_LINE_TO, -1.67f, -1.67f, R_ARC_TO, 7.47f, 7.47f, 0, 0, 0, 0.77f, -1.86f,
    ARC_TO, 7.94f, 7.94f, 0, 0, 0, 19.93f, 12, R_CUBIC_TO, 0, -2.21f, -0.77f, -4.08f, -2.31f, -5.62f, CUBIC_TO, 16.08f, 4.84f, 14.21f, 4.07f, 12, 4.07f,
    R_CUBIC_TO, -0.68f, 0, -1.35f, 0.09f, -2, 0.25f, R_ARC_TO, 7.66f, 7.66f, 0, 0, 0, -1.86f, 0.76f, LINE_TO, 6.48f, 3.42f, R_ARC_TO, 10.73f, 10.73f, 0, 0, 1,
    2.64f, -1.21f, ARC_TO, 10.07f, 10.07f, 0, 0, 1, 12, 1.8f, R_CUBIC_TO, 1.41f, 0, 2.74f, 0.27f, 3.98f, 0.8f, R_ARC_TO, 10.35f, 10.35f, 0, 0, 1, 3.24f, 2.18f,
    R_CUBIC_TO, 0.92f, 0.92f, 1.65f, 2, 2.18f, 3.24f, R_CUBIC_TO, 0.54f, 1.24f, 0.8f, 2.57f, 0.8f, 3.98f, R_CUBIC_TO, 0, 0.99f, -0.14f, 1.95f, -0.42f, 2.88f,
    R_CUBIC_TO, -0.28f, 0.93f, -0.68f, 1.81f, -1.21f, 2.64f, CLOSE, MOVE_TO, 12, 22.2f, R_ARC_TO, 9.92f, 9.92f, 0, 0, 1, -3.98f, -0.8f, R_ARC_TO, 10.35f,
    10.35f, 0, 0, 1, -3.24f, -2.18f, R_CUBIC_TO, -0.92f, -0.92f, -1.65f, -2, -2.18f, -3.24f, ARC_TO, 9.92f, 9.92f, 0, 0, 1, 1.8f, 12, R_CUBIC_TO, 0, -1, 0.14f,
    -1.98f, 0.43f, -2.94f, R_CUBIC_TO, 0.28f, -0.96f, 0.7f, -1.86f, 1.25f, -2.71f, LINE_TO, 0.65f, 3.5f, R_LINE_TO, 1.48f, -1.48f, LINE_TO, 22.06f, 21.94f,
    R_LINE_TO, -1.48f, 1.49f, LINE_TO, 5.14f, 8.02f, ARC_TO, 7.85f, 7.85f, 0, 0, 0, 4.07f, 12, R_CUBIC_TO, 0, 0.93f, 0.16f, 1.82f, 0.47f, 2.67f, R_ARC_TO,
    7.95f, 7.95f, 0, 0, 0, 1.34f, 2.34f, R_ARC_TO, 10.51f, 10.51f, 0, 0, 1, 2.9f, -1.54f, ARC_TO, 9.99f, 9.99f, 0, 0, 1, 12, 14.95f, R_CUBIC_TO, 0.65f, 0,
    1.29f, 0.07f, 1.94f, 0.2f, R_CUBIC_TO, 0.64f, 0.14f, 1.26f, 0.33f, 1.87f, 0.57f, R_LINE_TO, 3.45f, 3.45f, ARC_TO, 10.15f, 10.15f, 0, 0, 1, 12, 22.2f, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kAccountCircleOffChromeRefresh20Path, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 11.06f, 8.77f, CLOSE, R_MOVE_TO, -2.33f, 2.5f,
    CLOSE, MOVE_TO, 10, 16.44f, R_CUBIC_TO, 0.7f, 0, 1.38f, -0.11f, 2.04f, -0.34f, R_ARC_TO, 6.72f, 6.72f, 0, 0, 0, 1.84f, -0.97f, R_ARC_TO, 7.35f, 7.35f, 0, 0,
    0, -1.86f, -0.82f, ARC_TO, 7.4f, 7.4f, 0, 0, 0, 10, 14.03f, R_CUBIC_TO, -0.69f, 0, -1.36f, 0.09f, -2.02f, 0.27f, R_CUBIC_TO, -0.66f, 0.18f, -1.28f, 0.46f,
    -1.85f, 0.83f, R_CUBIC_TO, 0.57f, 0.43f, 1.18f, 0.75f, 1.84f, 0.97f, R_ARC_TO, 6.24f, 6.24f, 0, 0, 0, 2.03f, 0.34f, CLOSE, R_MOVE_TO, 2.5f, -6.22f,
    R_LINE_TO, -1.17f, -1.18f, R_ARC_TO, 0.84f, 0.84f, 0, 0, 0, 0.11f, -0.26f, R_CUBIC_TO, 0.02f, -0.09f, 0.03f, -0.18f, 0.03f, -0.27f, R_CUBIC_TO, 0, -0.41f,
    -0.14f, -0.75f, -0.43f, -1.04f, R_ARC_TO, 1.41f, 1.41f, 0, 0, 0, -1.31f, -0.4f, R_ARC_TO, 0.72f, 0.72f, 0, 0, 0, -0.26f, 0.11f, LINE_TO, 8.29f, 6.01f,
    R_CUBIC_TO, 0.26f, -0.17f, 0.53f, -0.3f, 0.82f, -0.4f, R_CUBIC_TO, 0.29f, -0.09f, 0.59f, -0.14f, 0.89f, -0.14f, R_CUBIC_TO, 0.84f, 0, 1.56f, 0.3f, 2.15f,
    0.89f, R_CUBIC_TO, 0.59f, 0.59f, 0.89f, 1.31f, 0.89f, 2.15f, R_ARC_TO, 3.02f, 3.02f, 0, 0, 1, -0.54f, 1.71f, CLOSE, R_MOVE_TO, 4.29f, 4.29f, R_LINE_TO,
    -1.26f, -1.26f, R_ARC_TO, 6.37f, 6.37f, 0, 0, 0, 0.68f, -1.56f, ARC_TO, 6.16f, 6.16f, 0, 0, 0, 16.44f, 10, R_CUBIC_TO, 0, -1.78f, -0.63f, -3.3f, -1.88f,
    -4.56f, CUBIC_TO, 13.31f, 4.19f, 11.79f, 3.56f, 10, 3.56f, R_ARC_TO, 6.16f, 6.16f, 0, 0, 0, -1.69f, 0.23f, R_ARC_TO, 6.51f, 6.51f, 0, 0, 0, -1.56f, 0.67f,
    LINE_TO, 5.48f, 3.21f, ARC_TO, 8.01f, 8.01f, 0, 0, 1, 10, 1.83f, R_ARC_TO, 7.93f, 7.93f, 0, 0, 1, 3.18f, 0.64f, R_ARC_TO, 8.29f, 8.29f, 0, 0, 1, 2.6f,
    1.75f, R_ARC_TO, 8.29f, 8.29f, 0, 0, 1, 1.75f, 2.6f, R_ARC_TO, 7.93f, 7.93f, 0, 0, 1, 0.64f, 3.18f, R_ARC_TO, 8.01f, 8.01f, 0, 0, 1, -1.37f, 4.52f, CLOSE,
    MOVE_TO, 10, 18.17f, R_ARC_TO, 7.93f, 7.93f, 0, 0, 1, -3.17f, -0.64f, R_ARC_TO, 8.23f, 8.23f, 0, 0, 1, -2.6f, -1.75f, R_ARC_TO, 8.23f, 8.23f, 0, 0, 1,
    -1.75f, -2.6f, ARC_TO, 7.93f, 7.93f, 0, 0, 1, 1.83f, 10, R_CUBIC_TO, 0, -0.82f, 0.12f, -1.62f, 0.36f, -2.39f, ARC_TO, 8.48f, 8.48f, 0, 0, 1, 3.25f, 5.42f,
    LINE_TO, 1.85f, 4, LINE_TO, 2.96f, 2.89f, R_LINE_TO, 14.23f, 14.23f, R_LINE_TO, -1.11f, 1.11f, LINE_TO, 4.49f, 6.66f, R_ARC_TO, 6.37f, 6.37f, 0, 0, 0,
    -0.7f, 1.6f, ARC_TO, 6.42f, 6.42f, 0, 0, 0, 3.56f, 10, R_CUBIC_TO, 0, 0.73f, 0.12f, 1.44f, 0.35f, 2.12f, R_CUBIC_TO, 0.23f, 0.68f, 0.58f, 1.31f, 1.06f,
    1.87f, R_ARC_TO, 8.37f, 8.37f, 0, 0, 1, 2.39f, -1.16f, R_ARC_TO, 9.27f, 9.27f, 0, 0, 1, 2.64f, -0.37f, R_CUBIC_TO, 0.53f, 0, 1.05f, 0.04f, 1.56f, 0.14f,
    R_CUBIC_TO, 0.51f, 0.09f, 1.01f, 0.23f, 1.5f, 0.4f, R_LINE_TO, 2.75f, 2.75f, R_ARC_TO, 8.05f, 8.05f, 0, 0, 1, -2.65f, 1.79f, R_CUBIC_TO, -1, 0.42f, -2.05f,
    0.63f, -3.15f, 0.63f, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kAccountCircleOffChromeRefresh16Path, CANVAS_DIMENSIONS, 16, FILL_RULE_NONZERO, MOVE_TO, 8.95f, 6.92f, CLOSE, MOVE_TO, 6.97f, 9.03f,
    CLOSE, MOVE_TO, 8, 13.09f, R_CUBIC_TO, 0.54f, 0, 1.06f, -0.09f, 1.57f, -0.25f, R_ARC_TO, 5.39f, 5.39f, 0, 0, 0, 1.43f, -0.74f, ARC_TO, 5.86f, 5.86f, 0, 0,
    0, 8, 11.26f, R_ARC_TO, 6.01f, 6.01f, 0, 0, 0, -1.56f, 0.2f, R_CUBIC_TO, -0.51f, 0.14f, -0.99f, 0.35f, -1.44f, 0.63f, R_CUBIC_TO, 0.45f, 0.32f, 0.92f,
    0.57f, 1.43f, 0.74f, R_ARC_TO, 4.95f, 4.95f, 0, 0, 0, 1.57f, 0.25f, CLOSE, R_MOVE_TO, 2.11f, -4.98f, LINE_TO, 9.08f, 7.06f, R_ARC_TO, 0.29f, 0.29f, 0, 0, 0,
    0.04f, -0.12f, R_CUBIC_TO, 0, -0.04f, 0, -0.08f, 0, -0.12f, R_CUBIC_TO, 0, -0.32f, -0.11f, -0.59f, -0.33f, -0.8f, R_ARC_TO, 1.09f, 1.09f, 0, 0, 0, -0.93f,
    -0.32f, R_ARC_TO, 0.31f, 0.31f, 0, 0, 0, -0.12f, 0.05f, LINE_TO, 6.72f, 4.7f, R_CUBIC_TO, 0.2f, -0.12f, 0.41f, -0.21f, 0.63f, -0.27f, ARC_TO, 2.53f, 2.53f,
    0, 0, 1, 8, 4.34f, R_CUBIC_TO, 0.69f, 0, 1.27f, 0.24f, 1.75f, 0.72f, R_CUBIC_TO, 0.48f, 0.48f, 0.72f, 1.06f, 0.72f, 1.75f, R_CUBIC_TO, 0, 0.22f, -0.03f,
    0.43f, -0.09f, 0.66f, R_ARC_TO, 2.68f, 2.68f, 0, 0, 1, -0.27f, 0.63f, CLOSE, R_MOVE_TO, 3.53f, 3.53f, R_LINE_TO, -1.21f, -1.21f, R_CUBIC_TO, 0.21f, -0.36f,
    0.38f, -0.75f, 0.48f, -1.16f, R_CUBIC_TO, 0.11f, -0.41f, 0.17f, -0.83f, 0.17f, -1.26f, R_CUBIC_TO, 0, -1.41f, -0.5f, -2.6f, -1.49f, -3.6f, CUBIC_TO, 10.61f,
    3.41f, 9.41f, 2.91f, 8, 2.91f, R_CUBIC_TO, -0.43f, 0, -0.85f, 0.06f, -1.26f, 0.17f, R_CUBIC_TO, -0.41f, 0.11f, -0.8f, 0.27f, -1.16f, 0.47f, LINE_TO, 4.37f,
    2.36f, R_ARC_TO, 6.56f, 6.56f, 0, 0, 1, 1.74f, -0.8f, ARC_TO, 6.53f, 6.53f, 0, 0, 1, 8, 1.28f, R_ARC_TO, 6.48f, 6.48f, 0, 0, 1, 2.61f, 0.52f, ARC_TO, 6.69f,
    6.69f, 0, 0, 1, 12.75f, 3.25f, R_ARC_TO, 6.69f, 6.69f, 0, 0, 1, 1.45f, 2.14f, ARC_TO, 6.48f, 6.48f, 0, 0, 1, 14.72f, 8, R_ARC_TO, 6.53f, 6.53f, 0, 0, 1,
    -0.27f, 1.89f, R_ARC_TO, 6.56f, 6.56f, 0, 0, 1, -0.8f, 1.74f, CLOSE, MOVE_TO, 8, 14.72f, R_ARC_TO, 6.52f, 6.52f, 0, 0, 1, -2.61f, -0.52f, R_ARC_TO, 6.7f,
    6.7f, 0, 0, 1, -2.14f, -1.44f, R_ARC_TO, 6.7f, 6.7f, 0, 0, 1, -1.44f, -2.14f, ARC_TO, 6.52f, 6.52f, 0, 0, 1, 1.28f, 8, R_CUBIC_TO, 0, -0.68f, 0.1f, -1.33f,
    0.31f, -1.97f, R_CUBIC_TO, 0.21f, -0.64f, 0.5f, -1.24f, 0.88f, -1.8f, LINE_TO, 1.45f, 3.2f, R_LINE_TO, 0.95f, -0.94f, R_LINE_TO, 11.5f, 11.5f, R_LINE_TO,
    -0.95f, 0.95f, R_LINE_TO, -9.32f, -9.3f, R_ARC_TO, 5.17f, 5.17f, 0, 0, 0, -0.54f, 1.25f, R_CUBIC_TO, -0.12f, 0.43f, -0.18f, 0.89f, -0.18f, 1.35f,
    R_CUBIC_TO, 0, 0.57f, 0.09f, 1.12f, 0.27f, 1.65f, R_CUBIC_TO, 0.18f, 0.53f, 0.45f, 1.02f, 0.81f, 1.46f, R_ARC_TO, 6.58f, 6.58f, 0, 0, 1, 1.9f, -0.9f,
    R_ARC_TO, 7.36f, 7.36f, 0, 0, 1, 2.1f, -0.3f, R_CUBIC_TO, 0.44f, 0, 0.86f, 0.04f, 1.28f, 0.11f, R_CUBIC_TO, 0.42f, 0.08f, 0.82f, 0.19f, 1.22f, 0.34f,
    R_LINE_TO, 2.31f, 2.31f, R_ARC_TO, 6.71f, 6.71f, 0, 0, 1, -2.19f, 1.51f, R_CUBIC_TO, -0.83f, 0.35f, -1.7f, 0.53f, -2.62f, 0.53f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kAccountCircleOffChromeRefreshRepList, kAccountCircleOffChromeRefreshIcon,
    { kAccountCircleOffChromeRefreshPath, std::size(kAccountCircleOffChromeRefreshPath) },
    { kAccountCircleOffChromeRefresh20Path, std::size(kAccountCircleOffChromeRefresh20Path) },
    { kAccountCircleOffChromeRefresh16Path, std::size(kAccountCircleOffChromeRefresh16Path) })
VECTOR_ICON_REP_TEMPLATE(kAddPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 13, 7.2f, H_LINE_TO, 8.8f, V_LINE_TO, 3, H_LINE_TO, 7.2f, R_V_LINE_TO, 4.2f, H_LINE_TO, 3,
    R_V_LINE_TO, 1.7f, R_H_LINE_TO, 4.2f, V_LINE_TO, 13, R_H_LINE_TO, 1.7f, V_LINE_TO, 8.8f, H_LINE_TO, 13, V_LINE_TO, 7.2f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kAddRepList, kAddIcon, { kAddPath, std::size(kAddPath) })
VECTOR_ICON_REP_TEMPLATE(kAdsPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 4, 2, R_ARC_TO, 2, 2, 0, 0, 0, -2, 2, R_V_LINE_TO, 8, R_ARC_TO, 2, 2, 0, 0, 0, 2, 2,
    R_H_LINE_TO, 8, R_ARC_TO, 2, 2, 0, 0, 0, 2, -2, V_LINE_TO, 4, R_ARC_TO, 2, 2, 0, 0, 0, -2, -2, H_LINE_TO, 4, CLOSE, R_MOVE_TO, 8, 10, H_LINE_TO, 4,
    V_LINE_TO, 6, R_H_LINE_TO, 8, R_V_LINE_TO, 6, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kAdsRepList, kAdsIcon, { kAdsPath, std::size(kAdsPath) })
VECTOR_ICON_REP_TEMPLATE(kAdsChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 4.5f, 17, R_ARC_TO, 1.42f, 1.42f, 0, 0, 1, -1.06f, -0.45f,
    ARC_TO, 1.45f, 1.45f, 0, 0, 1, 3, 15.5f, R_V_LINE_TO, -11, R_CUBIC_TO, 0, -0.4f, 0.15f, -0.75f, 0.44f, -1.05f, CUBIC_TO, 3.73f, 3.15f, 4.09f, 3, 4.5f, 3,
    R_H_LINE_TO, 11, R_CUBIC_TO, 0.41f, 0, 0.77f, 0.15f, 1.06f, 0.45f, R_CUBIC_TO, 0.29f, 0.3f, 0.44f, 0.65f, 0.44f, 1.05f, R_V_LINE_TO, 11, R_CUBIC_TO, 0,
    0.4f, -0.15f, 0.75f, -0.44f, 1.05f, R_CUBIC_TO, -0.29f, 0.3f, -0.64f, 0.45f, -1.06f, 0.45f, CLOSE, R_MOVE_TO, 0, -1.5f, R_H_LINE_TO, 11, V_LINE_TO, 7,
    R_H_LINE_TO, -11, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kAdsChromeRefreshRepList, kAdsChromeRefreshIcon, { kAdsChromeRefreshPath, std::size(kAdsChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kAdsClickPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 11.71f, 17.99f, CUBIC_TO, 8.53f, 17.84f, 6, 15.22f, 6, 12, R_CUBIC_TO, 0, -3.31f, 2.69f,
    -6, 6, -6, R_CUBIC_TO, 3.22f, 0, 5.84f, 2.53f, 5.99f, 5.71f, R_LINE_TO, -2.1f, -0.63f, CUBIC_TO, 15.48f, 9.31f, 13.89f, 8, 12, 8, R_CUBIC_TO, -2.21f, 0, -4,
    1.79f, -4, 4, R_CUBIC_TO, 0, 1.89f, 1.31f, 3.48f, 3.08f, 3.89f, LINE_TO, 11.71f, 17.99f, CLOSE, MOVE_TO, 22, 12, R_CUBIC_TO, 0, 0.3f, -0.01f, 0.6f, -0.04f,
    0.9f, R_LINE_TO, -1.97f, -0.59f, CUBIC_TO, 20, 12.21f, 20, 12.1f, 20, 12, R_CUBIC_TO, 0, -4.42f, -3.58f, -8, -8, -8, R_CUBIC_TO, -4.42f, 0, -8, 3.58f, -8,
    8, R_CUBIC_TO, 0, 4.42f, 3.58f, 8, 8, 8, R_CUBIC_TO, 0.1f, 0, 0.21f, 0, 0.31f, -0.01f, R_LINE_TO, 0.59f, 1.97f, CUBIC_TO, 12.6f, 21.99f, 12.3f, 22, 12, 22,
    CUBIC_TO, 6.48f, 22, 2, 17.52f, 2, 12, CUBIC_TO, 2, 6.48f, 6.48f, 2, 12, 2, CUBIC_TO_SHORTHAND, 22, 6.48f, 22, 12, CLOSE, MOVE_TO, 18.23f, 16.26f, LINE_TO,
    22, 15, R_LINE_TO, -10, -3, R_LINE_TO, 3, 10, R_LINE_TO, 1.26f, -3.77f, R_LINE_TO, 4.27f, 4.27f, R_LINE_TO, 1.98f, -1.98f, LINE_TO, 18.23f, 16.26f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kAdsClickRepList, kAdsClickIcon, { kAdsClickPath, std::size(kAdsClickPath) })
VECTOR_ICON_REP_TEMPLATE(kAdsOffChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 16.02f, 18.13f, LINE_TO, 14.88f, 17, H_LINE_TO, 4.5f,
    R_CUBIC_TO, -0.41f, 0, -0.77f, -0.15f, -1.06f, -0.44f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 3, 15.5f, V_LINE_TO, 5.13f, LINE_TO, 1.88f, 4, R_LINE_TO, 1.06f,
    -1.06f, R_LINE_TO, 14.12f, 14.15f, CLOSE, MOVE_TO, 4.5f, 15.5f, R_H_LINE_TO, 8.88f, LINE_TO, 4.5f, 6.63f, CLOSE, R_MOVE_TO, 12.5f, -0.62f, R_LINE_TO, -1.5f,
    -1.5f, V_LINE_TO, 7, H_LINE_TO, 9.13f, R_LINE_TO, -4, -4, H_LINE_TO, 15.5f, R_CUBIC_TO, 0.41f, 0, 0.77f, 0.15f, 1.06f, 0.44f, R_CUBIC_TO, 0.29f, 0.29f,
    0.44f, 0.65f, 0.44f, 1.06f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kAdsOffChromeRefreshRepList, kAdsOffChromeRefreshIcon, { kAdsOffChromeRefreshPath, std::size(kAdsOffChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kArrowBackPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 13.33f, 7.33f, H_LINE_TO, 5.22f, R_LINE_TO, 3.73f, -3.73f, LINE_TO, 8, 2.67f, LINE_TO,
    2.67f, 8, LINE_TO, 8, 13.33f, R_LINE_TO, 0.94f, -0.94f, R_LINE_TO, -3.72f, -3.73f, R_H_LINE_TO, 8.11f, V_LINE_TO, 7.33f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kArrowBackRepList, kArrowBackIcon, { kArrowBackPath, std::size(kArrowBackPath) })
VECTOR_ICON_REP_TEMPLATE(kArrowBackChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, R_MOVE_TO, 6.88f, 10.75f, R_LINE_TO, 4.19f, 4.19f, LINE_TO, 10,
    16, R_LINE_TO, -6, -6, R_LINE_TO, 6, -6, R_LINE_TO, 1.06f, 1.06f, LINE_TO, 6.88f, 9.25f, H_LINE_TO, 16, R_V_LINE_TO, 1.5f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kArrowBackChromeRefreshRepList, kArrowBackChromeRefreshIcon, { kArrowBackChromeRefreshPath, std::size(kArrowBackChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kArrowRightAltPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, R_MOVE_TO, 12, 14, R_LINE_TO, -1.06f, -1.06f, LINE_TO, 13.13f, 10.75f,
    H_LINE_TO, 4, R_V_LINE_TO, -1.5f, R_H_LINE_TO, 9.13f, R_LINE_TO, -2.19f, -2.19f, LINE_TO, 12, 6, R_LINE_TO, 4, 4, CLOSE, R_MOVE_TO, 0, 0, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kArrowRightAltRepList, kArrowRightAltIcon, { kArrowRightAltPath, std::size(kArrowRightAltPath) })
VECTOR_ICON_REP_TEMPLATE(kBackArrowPath, CANVAS_DIMENSIONS, 32, MOVE_TO, 4.22f, 14.03f, CUBIC_TO, 3.53f, 14.15f, 3, 14.77f, 3, 15.5f, CUBIC_TO, 3, 16.25f,
    3.53f, 16.86f, 4.24f, 16.98f, LINE_TO, 4.02f, 17.19f, LINE_TO, 14.36f, 27.51f, CUBIC_TO, 14.65f, 27.81f, 15.05f, 28, 15.5f, 28, CUBIC_TO, 16.33f, 28, 17,
    27.33f, 17, 26.5f, CUBIC_TO, 17, 26.05f, 16.8f, 25.65f, 16.49f, 25.38f, LINE_TO, 16.55f, 25.32f, LINE_TO, 8.22f, 17, LINE_TO, 27.51f, 17, CUBIC_TO, 28.33f,
    17, 29, 16.33f, 29, 15.5f, CUBIC_TO, 29, 14.67f, 28.33f, 14, 27.51f, 14, LINE_TO, 8.2f, 14, LINE_TO, 16.55f, 5.66f, CUBIC_TO, 16.81f, 5.34f, 17, 4.94f, 17,
    4.5f, CUBIC_TO, 17, 3.68f, 16.33f, 3, 15.5f, 3, CUBIC_TO, 15.06f, 3, 14.66f, 3.2f, 14.39f, 3.5f, LINE_TO, 14.36f, 3.47f, LINE_TO, 4, 13.81f, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kBackArrow16Path, CANVAS_DIMENSIONS, 16, MOVE_TO, 9, 13.51f, LINE_TO, 4.49f, 9, LINE_TO, 14, 9, CUBIC_TO, 14.55f, 9, 15, 8.55f, 15, 8,
    CUBIC_TO, 15, 7.45f, 14.55f, 7, 14, 7, LINE_TO, 4.49f, 7, LINE_TO, 9, 2.49f, CUBIC_TO, 8.97f, 2.28f, 9, 2.14f, 9, 2, CUBIC_TO, 9, 1.45f, 8.55f, 1, 8, 1,
    CUBIC_TO, 7.86f, 1, 7.72f, 1.03f, 7.59f, 1.09f, LINE_TO, 7.51f, 1, LINE_TO, 1, 7.51f, CUBIC_TO, 1.03f, 7.72f, 1, 7.85f, 1, 8, CUBIC_TO, 1, 8.15f, 1.03f,
    8.28f, 1.09f, 8.41f, LINE_TO, 1, 8.49f, LINE_TO, 7.51f, 15, CUBIC_TO, 7.72f, 14.97f, 7.86f, 15, 8, 15, CUBIC_TO, 8.55f, 15, 9, 14.55f, 9, 14, CUBIC_TO, 9,
    13.86f, 8.97f, 13.72f, 8.91f, 13.59f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kBackArrowRepList, kBackArrowIcon, { kBackArrowPath, std::size(kBackArrowPath) }, { kBackArrow16Path, std::size(kBackArrow16Path) })
VECTOR_ICON_REP_TEMPLATE(kBackArrowChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, R_MOVE_TO, 6.88f, 10.75f, R_LINE_TO, 4.19f, 4.19f, LINE_TO, 10,
    16, R_LINE_TO, -6, -6, R_LINE_TO, 6, -6, R_LINE_TO, 1.06f, 1.06f, LINE_TO, 6.88f, 9.25f, H_LINE_TO, 16, R_V_LINE_TO, 1.5f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kBackArrowChromeRefreshRepList, kBackArrowChromeRefreshIcon, { kBackArrowChromeRefreshPath, std::size(kBackArrowChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kBackToTabPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 5.2f, 12.14f, V_LINE_TO, 13.4f, R_ARC_TO, 1, 1, 0, 0, 0, 1, 1, R_H_LINE_TO, 6,
    R_ARC_TO, 1, 1, 0, 0, 0, 1, -1, V_LINE_TO, 9, R_ARC_TO, 1, 1, 0, 0, 0, -1, -1, R_H_LINE_TO, -6, R_ARC_TO, 1, 1, 0, 0, 0, -1, 1, R_V_LINE_TO, 1.84f,
    H_LINE_TO, 2.13f, V_LINE_TO, 7.6f, H_LINE_TO, 0.8f, R_V_LINE_TO, 3.21f, R_CUBIC_TO, 0, 0.73f, 0.6f, 1.33f, 1.33f, 1.33f, R_H_LINE_TO, 3.07f, CLOSE,
    R_MOVE_TO, 6.67f, -9.21f, V_LINE_TO, 6.8f, H_LINE_TO, 13.2f, V_LINE_TO, 2.93f, R_CUBIC_TO, 0, -0.73f, -0.59f, -1.33f, -1.33f, -1.33f, H_LINE_TO, 6.8f,
    R_V_LINE_TO, 1.33f, R_H_LINE_TO, 5.07f, CLOSE, NEW_PATH, MOVE_TO, 5.48f, 2.93f, V_LINE_TO, 1.6f, H_LINE_TO, 0.82f, R_V_LINE_TO, 4.67f, H_LINE_TO, 2.15f,
    V_LINE_TO, 3.87f, R_LINE_TO, 4.05f, 4.05f, R_CUBIC_TO, 0.2f, -0.41f, 0.53f, -0.74f, 0.95f, -0.93f, LINE_TO, 3.09f, 2.93f, R_H_LINE_TO, 2.39f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kBackToTabRepList, kBackToTabIcon, { kBackToTabPath, std::size(kBackToTabPath) })
VECTOR_ICON_REP_TEMPLATE(kBackToTabChromeRefreshPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 5.67f, 7.71f, LINE_TO, 2.33f, 4.38f, LINE_TO, 2.33f, 7.33f, LINE_TO,
    1.33f, 7.33f, LINE_TO, 1.33f, 2.67f, LINE_TO, 6, 2.67f, LINE_TO, 6, 3.67f, LINE_TO, 3.04f, 3.67f, LINE_TO, 6.38f, 7, CLOSE, MOVE_TO, 2.33f, 13.33f,
    CUBIC_TO, 2.07f, 13.33f, 1.83f, 13.23f, 1.63f, 13.04f, CUBIC_TO, 1.43f, 12.83f, 1.33f, 12.6f, 1.33f, 12.33f, LINE_TO, 1.33f, 8.5f, LINE_TO, 2.33f, 8.5f,
    LINE_TO, 2.33f, 12.33f, LINE_TO, 8, 12.33f, LINE_TO, 8, 13.33f, CLOSE, MOVE_TO, 13.67f, 8.67f, LINE_TO, 13.67f, 3.67f, LINE_TO, 7.17f, 3.67f, LINE_TO,
    7.17f, 2.67f, LINE_TO, 13.67f, 2.67f, CUBIC_TO, 13.93f, 2.67f, 14.17f, 2.77f, 14.37f, 2.96f, CUBIC_TO, 14.57f, 3.17f, 14.67f, 3.4f, 14.67f, 3.67f, LINE_TO,
    14.67f, 8.67f, CLOSE, MOVE_TO, 14.67f, 9.67f, LINE_TO, 14.67f, 13.33f, LINE_TO, 9, 13.33f, LINE_TO, 9, 9.67f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kBackToTabChromeRefreshRepList, kBackToTabChromeRefreshIcon, { kBackToTabChromeRefreshPath, std::size(kBackToTabChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kBlockedBadgePath, CANVAS_DIMENSIONS, 32, PATH_MODE_CLEAR, MOVE_TO, 32, 32, LINE_TO, 16, 32, LINE_TO, 16, 18, CUBIC_TO, 16, 16.9f,
    16.9f, 16, 18, 16, LINE_TO, 32, 16, CLOSE, NEW_PATH, PATH_COLOR_ARGB, 0xFF, 0xDB, 0x44, 0x37, MOVE_TO, 30, 32, LINE_TO, 20, 32, CUBIC_TO, 18.9f, 32, 18,
    31.1f, 18, 30, LINE_TO, 18, 20, CUBIC_TO, 18, 18.9f, 18.9f, 18, 20, 18, LINE_TO, 30, 18, CUBIC_TO, 31.1f, 18, 32, 18.9f, 32, 20, LINE_TO, 32, 30, CUBIC_TO,
    32, 31.1f, 31.1f, 32, 30, 32, CLOSE, NEW_PATH, PATH_COLOR_ARGB, 0xFF, 0xFF, 0xFF, 0xFF, MOVE_TO, 26.8f, 22, LINE_TO, 25, 23.8f, LINE_TO, 23.2f, 22,
    CUBIC_TO, 22.87f, 21.66f, 22.33f, 21.66f, 22, 22, CUBIC_TO, 21.66f, 22.33f, 21.66f, 22.87f, 22, 23.2f, LINE_TO, 23.8f, 25, LINE_TO, 22, 26.8f, CUBIC_TO,
    21.66f, 27.13f, 21.66f, 27.67f, 22, 28, CUBIC_TO, 22.33f, 28.34f, 22.87f, 28.34f, 23.2f, 28, LINE_TO, 25, 26.2f, LINE_TO, 26.8f, 28, CUBIC_TO, 27.13f,
    28.34f, 27.67f, 28.34f, 28, 28, CUBIC_TO, 28.34f, 27.67f, 28.34f, 27.13f, 28, 26.8f, LINE_TO, 26.2f, 25, LINE_TO, 28, 23.2f, CUBIC_TO, 28.34f, 22.87f,
    28.34f, 22.33f, 28, 22, CUBIC_TO, 27.67f, 21.66f, 27.13f, 21.66f, 26.8f, 22, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kBlockedBadgeRepList, kBlockedBadgeIcon, { kBlockedBadgePath, std::size(kBlockedBadgePath) })
VECTOR_ICON_REP_TEMPLATE(kBluetoothPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 17.71f, 7.71f, LINE_TO, 12, 2, R_H_LINE_TO, -1, R_V_LINE_TO, 7.59f, LINE_TO, 6.41f, 5,
    LINE_TO, 5, 6.41f, LINE_TO, 10.59f, 12, LINE_TO, 5, 17.59f, LINE_TO, 6.41f, 19, LINE_TO, 11, 14.41f, V_LINE_TO, 22, R_H_LINE_TO, 1, R_LINE_TO, 5.71f,
    -5.71f, R_LINE_TO, -4.3f, -4.29f, R_LINE_TO, 4.3f, -4.29f, CLOSE, MOVE_TO, 13, 5.83f, R_LINE_TO, 1.88f, 1.88f, LINE_TO, 13, 9.59f, V_LINE_TO, 5.83f, CLOSE,
    R_MOVE_TO, 1.88f, 10.46f, LINE_TO, 13, 18.17f, R_V_LINE_TO, -3.76f, R_LINE_TO, 1.88f, 1.88f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kBluetoothRepList, kBluetoothIcon, { kBluetoothPath, std::size(kBluetoothPath) })
VECTOR_ICON_REP_TEMPLATE(kBluetoothChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 9, 18, R_V_LINE_TO, -5.87f, R_LINE_TO, -3.56f, 3.56f,
    R_LINE_TO, -1.06f, -1.06f, LINE_TO, 9, 10, LINE_TO, 4.38f, 5.38f, R_LINE_TO, 1.06f, -1.06f, LINE_TO, 9, 7.88f, V_LINE_TO, 2, R_H_LINE_TO, 1.13f, R_LINE_TO,
    4.5f, 4.5f, R_LINE_TO, -3.5f, 3.5f, R_LINE_TO, 3.5f, 3.5f, R_LINE_TO, -4.5f, 4.5f, CLOSE, R_MOVE_TO, 1.5f, -9.5f, R_LINE_TO, 2, -2, R_LINE_TO, -2, -2,
    CLOSE, R_MOVE_TO, 0, 7, R_LINE_TO, 2, -2, R_LINE_TO, -2, -2, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kBluetoothChromeRefreshRepList, kBluetoothChromeRefreshIcon, { kBluetoothChromeRefreshPath, std::size(kBluetoothChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kBluetoothConnectedPath, MOVE_TO, 14, 24, R_LINE_TO, -4, -4, R_LINE_TO, -4, 4, R_LINE_TO, 4, 4, R_LINE_TO, 4, -4, CLOSE, R_MOVE_TO,
    21.41f, -8.59f, LINE_TO, 24, 4, R_H_LINE_TO, -2, R_V_LINE_TO, 15.17f, LINE_TO, 12.83f, 10, LINE_TO, 10, 12.83f, LINE_TO, 21.17f, 24, LINE_TO, 10, 35.17f,
    LINE_TO, 12.83f, 38, LINE_TO, 22, 28.83f, V_LINE_TO, 44, R_H_LINE_TO, 2, R_LINE_TO, 11.41f, -11.41f, LINE_TO, 26.83f, 24, R_LINE_TO, 8.58f, -8.59f, CLOSE,
    MOVE_TO, 26, 11.66f, R_LINE_TO, 3.76f, 3.76f, LINE_TO, 26, 19.17f, R_V_LINE_TO, -7.51f, CLOSE, R_MOVE_TO, 3.76f, 20.93f, LINE_TO, 26, 36.34f, R_V_LINE_TO,
    -7.52f, R_LINE_TO, 3.76f, 3.77f, CLOSE, MOVE_TO, 38, 20, R_LINE_TO, -4, 4, R_LINE_TO, 4, 4, R_LINE_TO, 4, -4, R_LINE_TO, -4, -4, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kBluetoothConnectedRepList, kBluetoothConnectedIcon, { kBluetoothConnectedPath, std::size(kBluetoothConnectedPath) })
VECTOR_ICON_REP_TEMPLATE(kBluetoothOffChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, R_MOVE_TO, 16, 18.13f, R_LINE_TO, -3, -3, LINE_TO, 10.13f,
    18, H_LINE_TO, 9, R_V_LINE_TO, -5.87f, R_LINE_TO, -3.56f, 3.56f, R_LINE_TO, -1.06f, -1.06f, R_LINE_TO, 4.06f, -4.06f, LINE_TO, 1.88f, 3.98f, R_LINE_TO,
    1.06f, -1.06f, R_LINE_TO, 14.12f, 14.15f, CLOSE, MOVE_TO, 10.5f, 15.5f, R_LINE_TO, 1.44f, -1.44f, R_LINE_TO, -1.44f, -1.44f, CLOSE, R_MOVE_TO, 1.13f, -6,
    LINE_TO, 10.5f, 8.38f, R_LINE_TO, 2, -1.87f, R_LINE_TO, -2, -2, R_V_LINE_TO, 3.88f, LINE_TO, 9, 6.88f, V_LINE_TO, 2, R_H_LINE_TO, 1.13f, R_LINE_TO, 4.5f,
    4.5f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(
    kBluetoothOffChromeRefreshRepList, kBluetoothOffChromeRefreshIcon, { kBluetoothOffChromeRefreshPath, std::size(kBluetoothOffChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kBluetoothScanningPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 14.24f, 12.01f, R_LINE_TO, 2.32f, 2.32f, R_CUBIC_TO, 0.28f, -0.72f, 0.44f,
    -1.51f, 0.44f, -2.33f, R_CUBIC_TO, 0, -0.82f, -0.16f, -1.59f, -0.43f, -2.31f, R_LINE_TO, -2.33f, 2.32f, CLOSE, R_MOVE_TO, 5.29f, -5.3f, R_LINE_TO, -1.26f,
    1.26f, R_CUBIC_TO, 0.63f, 1.21f, 0.98f, 2.57f, 0.98f, 4.02f, R_CUBIC_TO, 0, 1.45f, -0.36f, 2.82f, -0.98f, 4.02f, R_LINE_TO, 1.2f, 1.2f, R_ARC_TO, 9.94f,
    9.94f, 0, 0, 0, 1.54f, -5.31f, R_CUBIC_TO, -0.01f, -1.89f, -0.55f, -3.67f, -1.48f, -5.19f, CLOSE, R_MOVE_TO, -3.82f, 1, LINE_TO, 10, 2, H_LINE_TO, 9,
    R_V_LINE_TO, 7.59f, LINE_TO, 4.41f, 5, LINE_TO, 3, 6.41f, LINE_TO, 8.59f, 12, LINE_TO, 3, 17.59f, LINE_TO, 4.41f, 19, LINE_TO, 9, 14.41f, V_LINE_TO, 22,
    R_H_LINE_TO, 1, R_LINE_TO, 5.71f, -5.71f, R_LINE_TO, -4.3f, -4.29f, R_LINE_TO, 4.3f, -4.29f, CLOSE, MOVE_TO, 11, 5.83f, R_LINE_TO, 1.88f, 1.88f, LINE_TO,
    11, 9.59f, V_LINE_TO, 5.83f, CLOSE, R_MOVE_TO, 1.88f, 10.46f, LINE_TO, 11, 18.17f, R_V_LINE_TO, -3.76f, R_LINE_TO, 1.88f, 1.88f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kBluetoothScanningRepList, kBluetoothScanningIcon, { kBluetoothScanningPath, std::size(kBluetoothScanningPath) })
VECTOR_ICON_REP_TEMPLATE(kBluetoothScanningChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 7.5f, 18, R_V_LINE_TO, -5.87f, R_LINE_TO,
    -3.56f, 3.56f, R_LINE_TO, -1.06f, -1.06f, LINE_TO, 7.5f, 10, LINE_TO, 2.88f, 5.38f, R_LINE_TO, 1.06f, -1.06f, LINE_TO, 7.5f, 7.88f, V_LINE_TO, 2,
    R_H_LINE_TO, 1.13f, R_LINE_TO, 4.5f, 4.5f, R_LINE_TO, -3.5f, 3.5f, R_LINE_TO, 3.5f, 3.5f, R_LINE_TO, -4.5f, 4.5f, CLOSE, MOVE_TO, 9, 8.5f, R_LINE_TO, 2, -2,
    R_LINE_TO, -2, -2, CLOSE, R_MOVE_TO, 0, 7, R_LINE_TO, 2, -2, R_LINE_TO, -2, -2, CLOSE, R_MOVE_TO, 4.69f, -3.81f, LINE_TO, 12, 10, R_LINE_TO, 1.69f, -1.69f,
    R_CUBIC_TO, 0.11f, 0.28f, 0.19f, 0.56f, 0.24f, 0.83f, R_CUBIC_TO, 0.05f, 0.28f, 0.07f, 0.56f, 0.07f, 0.86f, R_CUBIC_TO, 0, 0.29f, -0.02f, 0.58f, -0.07f,
    0.86f, R_ARC_TO, 4.17f, 4.17f, 0, 0, 1, -0.24f, 0.83f, CLOSE, R_MOVE_TO, 2.27f, 2.27f, R_LINE_TO, -1.12f, -1.12f, R_CUBIC_TO, 0.24f, -0.44f, 0.41f, -0.91f,
    0.51f, -1.38f, R_ARC_TO, 6.75f, 6.75f, 0, 0, 0, 0, -2.9f, R_ARC_TO, 5.32f, 5.32f, 0, 0, 0, -0.51f, -1.38f, R_LINE_TO, 1.13f, -1.12f, R_ARC_TO, 6.82f, 6.82f,
    0, 0, 1, 0.79f, 1.89f, R_CUBIC_TO, 0.17f, 0.67f, 0.25f, 1.36f, 0.25f, 2.06f, R_CUBIC_TO, 0, 0.71f, -0.08f, 1.4f, -0.25f, 2.06f, R_ARC_TO, 6.82f, 6.82f, 0,
    0, 1, -0.79f, 1.89f, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kBluetoothScanningChromeRefresh16Path, CANVAS_DIMENSIONS, 16, FILL_RULE_NONZERO, R_MOVE_TO, 5.95f, 14.45f, R_LINE_TO, 0, -4.67f,
    R_LINE_TO, -2.82f, 2.82f, R_LINE_TO, -0.89f, -0.89f, LINE_TO, 5.94f, 8, LINE_TO, 2.24f, 4.3f, R_LINE_TO, 0.9f, -0.89f, R_LINE_TO, 2.82f, 2.82f, R_LINE_TO,
    0, -4.67f, R_H_LINE_TO, 0.93f, R_LINE_TO, 3.64f, 3.64f, LINE_TO, 7.73f, 8, R_LINE_TO, 2.8f, 2.8f, R_LINE_TO, -3.64f, 3.65f, CLOSE, R_MOVE_TO, 1.26f, -7.72f,
    R_LINE_TO, 1.52f, -1.53f, R_LINE_TO, -1.52f, -1.53f, CLOSE, R_MOVE_TO, 0, 5.6f, R_LINE_TO, 1.52f, -1.53f, R_LINE_TO, -1.52f, -1.53f, CLOSE, R_MOVE_TO,
    3.77f, -2.92f, LINE_TO, 9.59f, 8, R_LINE_TO, 1.4f, -1.41f, R_CUBIC_TO, 0.1f, 0.23f, 0.16f, 0.47f, 0.2f, 0.7f, R_ARC_TO, 4.34f, 4.34f, 0, 0, 1, 0, 1.43f,
    R_CUBIC_TO, -0.04f, 0.23f, -0.1f, 0.46f, -0.2f, 0.69f, CLOSE, R_MOVE_TO, 1.81f, 1.81f, R_LINE_TO, -0.93f, -0.94f, R_ARC_TO, 4.31f, 4.31f, 0, 0, 0, 0.41f,
    -1.11f, R_CUBIC_TO, 0.09f, -0.39f, 0.13f, -0.77f, 0.13f, -1.16f, R_CUBIC_TO, 0, -0.39f, -0.04f, -0.78f, -0.12f, -1.16f, R_ARC_TO, 4.28f, 4.28f, 0, 0, 0,
    -0.41f, -1.11f, R_LINE_TO, 0.94f, -0.95f, R_CUBIC_TO, 0.3f, 0.49f, 0.51f, 1, 0.65f, 1.54f, R_ARC_TO, 6.85f, 6.85f, 0, 0, 1, 0, 3.36f, R_ARC_TO, 5.62f,
    5.62f, 0, 0, 1, -0.66f, 1.55f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kBluetoothScanningChromeRefreshRepList, kBluetoothScanningChromeRefreshIcon,
    { kBluetoothScanningChromeRefreshPath, std::size(kBluetoothScanningChromeRefreshPath) },
    { kBluetoothScanningChromeRefresh16Path, std::size(kBluetoothScanningChromeRefresh16Path) })
VECTOR_ICON_REP_TEMPLATE(kBusinessPath, MOVE_TO, 24, 14, V_LINE_TO, 6, H_LINE_TO, 4, R_V_LINE_TO, 36, R_H_LINE_TO, 40, V_LINE_TO, 14, H_LINE_TO, 24, CLOSE,
    MOVE_TO, 12, 38, H_LINE_TO, 8, R_V_LINE_TO, -4, R_H_LINE_TO, 4, R_V_LINE_TO, 4, CLOSE, R_MOVE_TO, 0, -8, H_LINE_TO, 8, R_V_LINE_TO, -4, R_H_LINE_TO, 4,
    R_V_LINE_TO, 4, CLOSE, R_MOVE_TO, 0, -8, H_LINE_TO, 8, R_V_LINE_TO, -4, R_H_LINE_TO, 4, R_V_LINE_TO, 4, CLOSE, R_MOVE_TO, 0, -8, H_LINE_TO, 8, R_V_LINE_TO,
    -4, R_H_LINE_TO, 4, R_V_LINE_TO, 4, CLOSE, R_MOVE_TO, 8, 24, R_H_LINE_TO, -4, R_V_LINE_TO, -4, R_H_LINE_TO, 4, R_V_LINE_TO, 4, CLOSE, R_MOVE_TO, 0, -8,
    R_H_LINE_TO, -4, R_V_LINE_TO, -4, R_H_LINE_TO, 4, R_V_LINE_TO, 4, CLOSE, R_MOVE_TO, 0, -8, R_H_LINE_TO, -4, R_V_LINE_TO, -4, R_H_LINE_TO, 4, R_V_LINE_TO, 4,
    CLOSE, R_MOVE_TO, 0, -8, R_H_LINE_TO, -4, R_V_LINE_TO, -4, R_H_LINE_TO, 4, R_V_LINE_TO, 4, CLOSE, R_MOVE_TO, 20, 24, H_LINE_TO, 24, R_V_LINE_TO, -4,
    R_H_LINE_TO, 4, R_V_LINE_TO, -4, R_H_LINE_TO, -4, R_V_LINE_TO, -4, R_H_LINE_TO, 4, R_V_LINE_TO, -4, R_H_LINE_TO, -4, R_V_LINE_TO, -4, R_H_LINE_TO, 16,
    R_V_LINE_TO, 20, CLOSE, R_MOVE_TO, -4, -16, R_H_LINE_TO, -4, R_V_LINE_TO, 4, R_H_LINE_TO, 4, R_V_LINE_TO, -4, CLOSE, R_MOVE_TO, 0, 8, R_H_LINE_TO, -4,
    R_V_LINE_TO, 4, R_H_LINE_TO, 4, R_V_LINE_TO, -4, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kBusinessRepList, kBusinessIcon, { kBusinessPath, std::size(kBusinessPath) })
VECTOR_ICON_REP_TEMPLATE(kBusinessChromeRefreshPath, CANVAS_DIMENSIONS, 16, FILL_RULE_NONZERO, MOVE_TO, 1.48f, 13.79f, V_LINE_TO, 2.34f, R_H_LINE_TO, 6.65f,
    R_V_LINE_TO, 2.4f, R_H_LINE_TO, 6.4f, R_V_LINE_TO, 9.05f, CLOSE, MOVE_TO, 2.8f, 12.46f, H_LINE_TO, 4, R_V_LINE_TO, -1.2f, H_LINE_TO, 2.8f, CLOSE, R_MOVE_TO,
    0, -2.53f, H_LINE_TO, 4, R_V_LINE_TO, -1.2f, H_LINE_TO, 2.8f, CLOSE, R_MOVE_TO, 0, -2.53f, H_LINE_TO, 4, V_LINE_TO, 6.19f, H_LINE_TO, 2.8f, CLOSE,
    R_MOVE_TO, 0, -2.54f, H_LINE_TO, 4, V_LINE_TO, 3.66f, H_LINE_TO, 2.8f, CLOSE, R_MOVE_TO, 2.8f, 7.6f, R_H_LINE_TO, 1.2f, R_V_LINE_TO, -1.2f, H_LINE_TO, 5.6f,
    CLOSE, R_MOVE_TO, 0, -2.53f, R_H_LINE_TO, 1.2f, R_V_LINE_TO, -1.2f, H_LINE_TO, 5.6f, CLOSE, R_MOVE_TO, 0, -2.53f, R_H_LINE_TO, 1.2f, V_LINE_TO, 6.19f,
    H_LINE_TO, 5.6f, CLOSE, R_MOVE_TO, 0, -2.54f, R_H_LINE_TO, 1.2f, V_LINE_TO, 3.66f, H_LINE_TO, 5.6f, CLOSE, MOVE_TO, 8, 12.46f, R_H_LINE_TO, 5.2f, V_LINE_TO,
    6.06f, H_LINE_TO, 8, R_V_LINE_TO, 1.34f, R_H_LINE_TO, 1.2f, R_V_LINE_TO, 1.2f, H_LINE_TO, 8, R_V_LINE_TO, 1.33f, R_H_LINE_TO, 1.2f, R_V_LINE_TO, 1.2f,
    H_LINE_TO, 8, CLOSE, R_MOVE_TO, 2.8f, -3.87f, R_V_LINE_TO, -1.2f, H_LINE_TO, 12, R_V_LINE_TO, 1.2f, CLOSE, R_MOVE_TO, 0, 2.53f, R_V_LINE_TO, -1.2f,
    H_LINE_TO, 12, R_V_LINE_TO, 1.2f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kBusinessChromeRefreshRepList, kBusinessChromeRefreshIcon, { kBusinessChromeRefreshPath, std::size(kBusinessChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kCallPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 20.01f, 15.38f, R_CUBIC_TO, -1.23f, 0, -2.42f, -0.2f, -3.53f, -0.56f, R_CUBIC_TO, -0.35f,
    -0.12f, -0.74f, -0.03f, -1.01f, 0.24f, R_LINE_TO, -1.57f, 1.97f, R_CUBIC_TO, -2.83f, -1.35f, -5.48f, -3.9f, -6.89f, -6.83f, R_LINE_TO, 1.95f, -1.66f,
    R_CUBIC_TO, 0.27f, -0.28f, 0.35f, -0.67f, 0.24f, -1.02f, R_CUBIC_TO, -0.37f, -1.11f, -0.56f, -2.3f, -0.56f, -3.53f, R_CUBIC_TO, 0, -0.54f, -0.45f, -0.99f,
    -0.99f, -0.99f, H_LINE_TO, 4.19f, CUBIC_TO, 3.65f, 3, 3, 3.24f, 3, 3.99f, CUBIC_TO, 3, 13.28f, 10.73f, 21, 20.01f, 21, R_CUBIC_TO, 0.71f, 0, 0.99f, -0.63f,
    0.99f, -1.18f, R_V_LINE_TO, -3.45f, R_CUBIC_TO, 0, -0.54f, -0.45f, -0.99f, -0.99f, -0.99f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kCallRepList, kCallIcon, { kCallPath, std::size(kCallPath) })
VECTOR_ICON_REP_TEMPLATE(kCallEndPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 23.62f, 11.27f, R_CUBIC_TO, -2.03f, -1.72f, -4.46f, -3, -7.12f, -3.69f, CUBIC_TO, 15.06f,
    7.21f, 13.56f, 7, 12, 7, R_CUBIC_TO, -1.56f, 0, -3.06f, 0.21f, -4.5f, 0.58f, R_CUBIC_TO, -2.66f, 0.69f, -5.08f, 1.96f, -7.12f, 3.69f, R_CUBIC_TO, -0.45f,
    0.38f, -0.5f, 1.07f, -0.08f, 1.49f, R_LINE_TO, 0.67f, 0.67f, R_LINE_TO, 2.26f, 2.26f, R_CUBIC_TO, 0.33f, 0.33f, 0.85f, 0.39f, 1.25f, 0.13f, R_LINE_TO,
    2.56f, -1.64f, R_CUBIC_TO, 0.29f, -0.18f, 0.46f, -0.5f, 0.46f, -0.84f, V_LINE_TO, 9.65f, CUBIC_TO, 8.93f, 9.23f, 10.44f, 9, 12, 9, R_CUBIC_TO, 1.56f, 0,
    3.07f, 0.23f, 4.5f, 0.65f, R_V_LINE_TO, 3.68f, R_CUBIC_TO, 0, 0.34f, 0.17f, 0.66f, 0.46f, 0.84f, R_LINE_TO, 2.56f, 1.64f, R_CUBIC_TO, 0.4f, 0.25f, 0.92f,
    0.2f, 1.25f, -0.13f, R_LINE_TO, 2.26f, -2.26f, R_LINE_TO, 0.67f, -0.67f, R_CUBIC_TO, 0.41f, -0.41f, 0.37f, -1.1f, -0.08f, -1.48f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kCallEndRepList, kCallEndIcon, { kCallEndPath, std::size(kCallEndPath) })
VECTOR_ICON_REP_TEMPLATE(kCallRefreshPath, CANVAS_DIMENSIONS, 20, MOVE_TO, 15.9f, 17.13f, R_ARC_TO, 13.89f, 13.89f, 0, 0, 1, -4.9f, -1.3f, R_ARC_TO, 14.17f,
    14.17f, 0, 0, 1, -4.04f, -2.84f, R_ARC_TO, 14.69f, 14.69f, 0, 0, 1, -2.84f, -4.05f, R_ARC_TO, 13.54f, 13.54f, 0, 0, 1, -1.28f, -4.89f, R_ARC_TO, 1.11f,
    1.11f, 0, 0, 1, 0.3f, -0.87f, R_CUBIC_TO, 0.23f, -0.25f, 0.52f, -0.37f, 0.86f, -0.37f, R_H_LINE_TO, 2.83f, R_CUBIC_TO, 0.31f, 0, 0.57f, 0.09f, 0.79f, 0.25f,
    R_CUBIC_TO, 0.21f, 0.17f, 0.36f, 0.4f, 0.43f, 0.71f, R_LINE_TO, 0.49f, 2.13f, R_CUBIC_TO, 0.04f, 0.22f, 0.04f, 0.43f, -0.02f, 0.63f, R_ARC_TO, 1.11f, 1.11f,
    0, 0, 1, -0.32f, 0.53f, R_LINE_TO, -2.05f, 2, R_CUBIC_TO, 0.56f, 1, 1.23f, 1.89f, 2.03f, 2.69f, R_ARC_TO, 12.11f, 12.11f, 0, 0, 0, 2.67f, 2.01f, R_LINE_TO,
    2.1f, -2.02f, R_CUBIC_TO, 0.18f, -0.17f, 0.36f, -0.28f, 0.56f, -0.32f, R_CUBIC_TO, 0.2f, -0.04f, 0.4f, -0.04f, 0.61f, 0, R_LINE_TO, 2.09f, 0.47f,
    R_CUBIC_TO, 0.31f, 0.07f, 0.54f, 0.22f, 0.71f, 0.43f, R_CUBIC_TO, 0.17f, 0.22f, 0.25f, 0.48f, 0.25f, 0.79f, R_V_LINE_TO, 2.87f, R_CUBIC_TO, 0, 0.42f,
    -0.15f, 0.73f, -0.44f, 0.91f, R_CUBIC_TO, -0.29f, 0.18f, -0.57f, 0.27f, -0.82f, 0.25f, CLOSE, MOVE_TO, 5.34f, 7.41f, LINE_TO, 6.8f, 6, R_LINE_TO, -0.35f,
    -1.46f, H_LINE_TO, 4.61f, R_CUBIC_TO, 0.06f, 0.5f, 0.15f, 0.99f, 0.27f, 1.47f, R_CUBIC_TO, 0.12f, 0.48f, 0.27f, 0.95f, 0.46f, 1.41f, CLOSE, R_MOVE_TO,
    7.18f, 7.18f, R_CUBIC_TO, 0.47f, 0.19f, 0.95f, 0.34f, 1.43f, 0.45f, R_CUBIC_TO, 0.49f, 0.11f, 0.98f, 0.21f, 1.48f, 0.28f, V_LINE_TO, 13.48f, R_LINE_TO,
    -1.46f, -0.32f, CLOSE, R_MOVE_TO, -7.18f, -7.18f, CLOSE, R_MOVE_TO, 7.18f, 7.18f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kCallRefreshRepList, kCallRefreshIcon, { kCallRefreshPath, std::size(kCallRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kCancelPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 12, 2, CUBIC_TO, 6.47f, 2, 2, 6.47f, 2, 12, R_CUBIC_TO, 0, 5.53f, 4.47f, 10, 10, 10,
    R_CUBIC_TO, 5.53f, 0, 10, -4.47f, 10, -10, CUBIC_TO, 22, 6.47f, 17.53f, 2, 12, 2, CLOSE, MOVE_TO, 17, 15.59f, LINE_TO, 15.59f, 17, LINE_TO, 12, 13.41f,
    LINE_TO, 8.41f, 17, LINE_TO, 7, 15.59f, LINE_TO, 10.59f, 12, LINE_TO, 7, 8.41f, LINE_TO, 8.41f, 7, LINE_TO, 12, 10.59f, LINE_TO, 15.59f, 7, LINE_TO, 17,
    8.41f, LINE_TO, 13.41f, 12, LINE_TO, 17, 15.59f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kCancelRepList, kCancelIcon, { kCancelPath, std::size(kCancelPath) })
VECTOR_ICON_REP_TEMPLATE(kCancelChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 7.06f, 14, LINE_TO, 10, 11.06f, LINE_TO, 12.94f, 14,
    LINE_TO, 14, 12.94f, LINE_TO, 11.06f, 10, LINE_TO, 14, 7.06f, LINE_TO, 12.94f, 6, LINE_TO, 10, 8.94f, LINE_TO, 7.06f, 6, LINE_TO, 6, 7.06f, LINE_TO, 8.94f,
    10, LINE_TO, 6, 12.94f, CLOSE, MOVE_TO, 10, 18, R_ARC_TO, 7.78f, 7.78f, 0, 0, 1, -3.1f, -0.62f, R_ARC_TO, 8.07f, 8.07f, 0, 0, 1, -2.55f, -1.72f, R_ARC_TO,
    8.07f, 8.07f, 0, 0, 1, -1.72f, -2.55f, ARC_TO, 7.78f, 7.78f, 0, 0, 1, 2, 10, R_CUBIC_TO, 0, -1.11f, 0.21f, -2.15f, 0.63f, -3.11f, R_ARC_TO, 8.12f, 8.12f, 0,
    0, 1, 1.72f, -2.54f, R_CUBIC_TO, 0.73f, -0.73f, 1.58f, -1.3f, 2.55f, -1.72f, ARC_TO, 7.78f, 7.78f, 0, 0, 1, 10, 2, R_ARC_TO, 7.75f, 7.75f, 0, 0, 1, 3.11f,
    0.63f, R_ARC_TO, 8.12f, 8.12f, 0, 0, 1, 2.54f, 1.72f, R_CUBIC_TO, 0.73f, 0.73f, 1.3f, 1.58f, 1.72f, 2.54f, ARC_TO, 7.75f, 7.75f, 0, 0, 1, 18, 10, R_ARC_TO,
    7.78f, 7.78f, 0, 0, 1, -0.62f, 3.11f, R_ARC_TO, 8.07f, 8.07f, 0, 0, 1, -1.72f, 2.55f, R_CUBIC_TO, -0.73f, 0.73f, -1.58f, 1.3f, -2.54f, 1.72f, ARC_TO, 7.75f,
    7.75f, 0, 0, 1, 10, 18, CLOSE, R_MOVE_TO, 0, -1.5f, R_CUBIC_TO, 1.81f, 0, 3.34f, -0.63f, 4.61f, -1.89f, CUBIC_TO, 15.87f, 13.34f, 16.5f, 11.81f, 16.5f, 10,
    R_CUBIC_TO, 0, -1.8f, -0.63f, -3.34f, -1.89f, -4.61f, CUBIC_TO, 13.34f, 4.13f, 11.81f, 3.5f, 10, 3.5f, R_CUBIC_TO, -1.8f, 0, -3.34f, 0.63f, -4.61f, 1.9f,
    CUBIC_TO, 4.13f, 6.66f, 3.5f, 8.2f, 3.5f, 10, R_CUBIC_TO, 0, 1.81f, 0.63f, 3.34f, 1.9f, 4.61f, CUBIC_TO, 6.66f, 15.87f, 8.2f, 16.5f, 10, 16.5f, CLOSE,
    R_MOVE_TO, 0, -6.5f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kCancelChromeRefreshRepList, kCancelChromeRefreshIcon, { kCancelChromeRefreshPath, std::size(kCancelChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kCapturePath, CANVAS_DIMENSIONS, 20, MOVE_TO, 1.83f, 16.17f, V_LINE_TO, 3.83f, R_H_LINE_TO, 16.34f, R_V_LINE_TO, 12.34f, CLOSE,
    R_MOVE_TO, 1.73f, -1.73f, H_LINE_TO, 16.44f, V_LINE_TO, 5.56f, H_LINE_TO, 3.56f, CLOSE, R_MOVE_TO, 1.5f, -1.5f, R_H_LINE_TO, 9.88f, V_LINE_TO, 7.06f,
    H_LINE_TO, 5.06f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kCaptureRepList, kCaptureIcon, { kCapturePath, std::size(kCapturePath) })
VECTOR_ICON_REP_TEMPLATE(kCardboardPath, CANVAS_DIMENSIONS, 20, MOVE_TO, 4.29f, 13.12f, R_H_LINE_TO, 3.3f, R_V_LINE_TO, -0.01f, R_LINE_TO, 0.66f, -1.26f,
    R_CUBIC_TO, 0.18f, -0.33f, 0.42f, -0.6f, 0.73f, -0.79f, ARC_TO, 1.91f, 1.91f, 0, 0, 1, 10, 10.77f, R_CUBIC_TO, 0.38f, 0, 0.72f, 0.09f, 1.03f, 0.28f,
    R_CUBIC_TO, 0.31f, 0.19f, 0.56f, 0.45f, 0.73f, 0.78f, R_LINE_TO, 0.66f, 1.28f, R_V_LINE_TO, 0.01f, R_H_LINE_TO, 3.3f, V_LINE_TO, 6.88f, H_LINE_TO, 4.29f,
    CLOSE, R_MOVE_TO, 2.1f, -1.56f, R_CUBIC_TO, 0.43f, 0, 0.8f, -0.15f, 1.1f, -0.46f, R_CUBIC_TO, 0.31f, -0.31f, 0.46f, -0.68f, 0.46f, -1.11f, R_CUBIC_TO, 0,
    -0.43f, -0.16f, -0.8f, -0.46f, -1.1f, R_ARC_TO, 1.52f, 1.52f, 0, 0, 0, -1.11f, -0.45f, R_CUBIC_TO, -0.43f, 0, -0.8f, 0.15f, -1.1f, 0.46f, R_ARC_TO, 1.52f,
    1.52f, 0, 0, 0, -0.46f, 1.11f, R_CUBIC_TO, 0, 0.43f, 0.15f, 0.8f, 0.46f, 1.1f, R_CUBIC_TO, 0.31f, 0.3f, 0.68f, 0.45f, 1.11f, 0.45f, CLOSE, R_MOVE_TO, -2.1f,
    3.13f, R_ARC_TO, 1.51f, 1.51f, 0, 0, 1, -1.1f, -0.46f, R_ARC_TO, 1.52f, 1.52f, 0, 0, 1, -0.46f, -1.1f, V_LINE_TO, 6.88f, R_CUBIC_TO, 0, -0.42f, 0.16f,
    -0.78f, 0.46f, -1.09f, R_CUBIC_TO, 0.31f, -0.31f, 0.68f, -0.47f, 1.09f, -0.47f, R_H_LINE_TO, 11.43f, R_CUBIC_TO, 0.42f, 0, 0.79f, 0.16f, 1.09f, 0.47f,
    R_CUBIC_TO, 0.31f, 0.31f, 0.46f, 0.68f, 0.46f, 1.1f, R_V_LINE_TO, 6.24f, R_CUBIC_TO, 0, 0.42f, -0.16f, 0.79f, -0.46f, 1.09f, R_ARC_TO, 1.5f, 1.5f, 0, 0, 1,
    -1.1f, 0.47f, R_H_LINE_TO, -3.29f, R_CUBIC_TO, -0.3f, 0, -0.58f, -0.08f, -0.83f, -0.24f, R_ARC_TO, 1.52f, 1.52f, 0, 0, 1, -0.57f, -0.61f, R_LINE_TO, -0.66f,
    -1.26f, R_ARC_TO, 0.54f, 0.54f, 0, 0, 0, -0.16f, -0.17f, R_ARC_TO, 0.37f, 0.37f, 0, 0, 0, -0.21f, -0.07f, R_ARC_TO, 0.46f, 0.46f, 0, 0, 0, -0.38f, 0.24f,
    R_LINE_TO, -0.64f, 1.27f, R_CUBIC_TO, -0.12f, 0.25f, -0.31f, 0.46f, -0.57f, 0.61f, R_CUBIC_TO, -0.25f, 0.16f, -0.53f, 0.24f, -0.83f, 0.24f, CLOSE,
    R_MOVE_TO, 9.34f, -3.12f, R_CUBIC_TO, 0.43f, 0, 0.8f, -0.15f, 1.1f, -0.46f, R_CUBIC_TO, 0.3f, -0.31f, 0.46f, -0.68f, 0.46f, -1.11f, R_CUBIC_TO, 0, -0.43f,
    -0.15f, -0.8f, -0.46f, -1.1f, R_ARC_TO, 1.52f, 1.52f, 0, 0, 0, -1.11f, -0.45f, R_CUBIC_TO, -0.43f, 0, -0.8f, 0.15f, -1.1f, 0.46f, R_ARC_TO, 1.52f, 1.52f, 0,
    0, 0, -0.46f, 1.11f, R_CUBIC_TO, 0, 0.43f, 0.16f, 0.8f, 0.46f, 1.1f, R_CUBIC_TO, 0.31f, 0.3f, 0.68f, 0.45f, 1.11f, 0.45f, CLOSE, MOVE_TO, 10, 10, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kCardboardRepList, kCardboardIcon, { kCardboardPath, std::size(kCardboardPath) })
VECTOR_ICON_REP_TEMPLATE(kCaretDownPath, CANVAS_DIMENSIONS, 32, STROKE, 3, MOVE_TO, 8.5f, 12.5f, R_LINE_TO, 7.5f, 8, R_LINE_TO, 7.5f, -8, CLIP, 7, 11, 18, 11, )
VECTOR_ICON_REP_TEMPLATE(kCaretDown16Path, CANVAS_DIMENSIONS, 16, STROKE, 1.765f, MOVE_TO, 4, 6, R_LINE_TO, 4, 4, R_LINE_TO, 4, -4, )
VECTOR_ICON_TEMPLATE_CC(kCaretDownRepList, kCaretDownIcon, { kCaretDownPath, std::size(kCaretDownPath) }, { kCaretDown16Path, std::size(kCaretDown16Path) })
VECTOR_ICON_REP_TEMPLATE(kCaretUpPath, CANVAS_DIMENSIONS, 32, CLIP, 7, 10, 18, 11, STROKE, 3, MOVE_TO, 8.5f, 19.5f, R_LINE_TO, 7.5f, -8, R_LINE_TO, 7.5f, 8, )
VECTOR_ICON_REP_TEMPLATE(kCaretUp16Path, CANVAS_DIMENSIONS, 16, STROKE, 1.765f, MOVE_TO, 4, 10, R_LINE_TO, 4, -4, R_LINE_TO, 4, 4, )
VECTOR_ICON_TEMPLATE_CC(kCaretUpRepList, kCaretUpIcon, { kCaretUpPath, std::size(kCaretUpPath) }, { kCaretUp16Path, std::size(kCaretUp16Path) })
VECTOR_ICON_REP_TEMPLATE(kCastPath, CANVAS_DIMENSIONS, 960, FILL_RULE_NONZERO, MOVE_TO, 480, 480, CLOSE, R_MOVE_TO, 320, 320, H_LINE_TO, 600, R_QUADRATIC_TO, 0,
    -20, -1.5f, -40, R_QUADRATIC_TO, -1.5f, -20, -4.5f, -40, R_H_LINE_TO, 206, R_V_LINE_TO, -480, H_LINE_TO, 160, R_V_LINE_TO, 46, R_QUADRATIC_TO, -20, -3, -40,
    -4.5f, QUADRATIC_TO_SHORTHAND, 80, 280, R_V_LINE_TO, -40, R_QUADRATIC_TO, 0, -33, 23.5f, -56.5f, QUADRATIC_TO_SHORTHAND, 160, 160, R_H_LINE_TO, 640,
    R_QUADRATIC_TO, 33, 0, 56.5f, 23.5f, QUADRATIC_TO_SHORTHAND, 880, 240, R_V_LINE_TO, 480, R_QUADRATIC_TO, 0, 33, -23.5f, 56.5f, QUADRATIC_TO_SHORTHAND, 800,
    800, CLOSE, R_MOVE_TO, -720, 0, R_V_LINE_TO, -120, R_QUADRATIC_TO, 50, 0, 85, 35, R_QUADRATIC_TO, 35, 35, 35, 85, H_LINE_TO, 80, CLOSE, R_MOVE_TO, 200, 0,
    R_QUADRATIC_TO, 0, -83, -58.5f, -141.5f, QUADRATIC_TO_SHORTHAND, 80, 600, R_V_LINE_TO, -80, R_QUADRATIC_TO, 117, 0, 198.5f, 81.5f, QUADRATIC_TO_SHORTHAND,
    360, 800, R_H_LINE_TO, -80, CLOSE, R_MOVE_TO, 160, 0, R_QUADRATIC_TO, 0, -75, -28.5f, -140.5f, R_QUADRATIC_TO, -28.5f, -65.5f, -77, -114, R_QUADRATIC_TO,
    -48.5f, -48.5f, -114, -77, QUADRATIC_TO_SHORTHAND, 80, 440, R_V_LINE_TO, -80, R_QUADRATIC_TO, 91, 0, 171, 34.5f, QUADRATIC_TO_SHORTHAND, 391, 489,
    R_QUADRATIC_TO, 60, 60, 94.5f, 140, QUADRATIC_TO_SHORTHAND, 520, 800, R_H_LINE_TO, -80, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kCastRepList, kCastIcon, { kCastPath, std::size(kCastPath) })
VECTOR_ICON_REP_TEMPLATE(kCastWarningPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 10, 10, CLOSE, R_MOVE_TO, -8, 4, R_CUBIC_TO, 0.56f, 0, 1.03f,
    0.2f, 1.42f, 0.58f, R_CUBIC_TO, 0.39f, 0.39f, 0.58f, 0.86f, 0.58f, 1.42f, H_LINE_TO, 2, CLOSE, R_MOVE_TO, 0, -3, R_CUBIC_TO, 1.39f, 0, 2.57f, 0.48f, 3.54f,
    1.46f, CUBIC_TO, 6.52f, 13.43f, 7, 14.61f, 7, 16, H_LINE_TO, 5.5f, R_CUBIC_TO, 0, -0.97f, -0.34f, -1.8f, -1.02f, -2.48f, ARC_TO, 3.38f, 3.38f, 0, 0, 0, 2,
    12.5f, CLOSE, R_MOVE_TO, 0, -3, R_CUBIC_TO, 1.11f, 0, 2.15f, 0.21f, 3.12f, 0.63f, ARC_TO, 8.09f, 8.09f, 0, 0, 1, 7.66f, 10.34f, R_ARC_TO, 8.09f, 8.09f, 0,
    0, 1, 1.72f, 2.54f, CUBIC_TO, 9.79f, 13.85f, 10, 14.89f, 10, 16, H_LINE_TO, 8.5f, R_ARC_TO, 6.3f, 6.3f, 0, 0, 0, -0.51f, -2.53f, R_ARC_TO, 6.56f, 6.56f, 0,
    0, 0, -1.39f, -2.07f, R_ARC_TO, 6.56f, 6.56f, 0, 0, 0, -2.07f, -1.39f, ARC_TO, 6.3f, 6.3f, 0, 0, 0, 2, 9.5f, CLOSE, R_MOVE_TO, 14.5f, 8, R_H_LINE_TO, -5,
    R_CUBIC_TO, 0, -0.25f, -0.01f, -0.5f, -0.03f, -0.75f, R_CUBIC_TO, -0.02f, -0.25f, -0.05f, -0.5f, -0.09f, -0.75f, H_LINE_TO, 16.5f, R_V_LINE_TO, -3.87f,
    R_CUBIC_TO, 0.28f, -0.1f, 0.54f, -0.23f, 0.79f, -0.37f, ARC_TO, 4.05f, 4.05f, 0, 0, 0, 18, 9.75f, R_V_LINE_TO, 4.75f, R_CUBIC_TO, 0, 0.42f, -0.15f, 0.77f,
    -0.44f, 1.06f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 16.5f, 16, CLOSE, MOVE_TO, 2, 6.5f, R_V_LINE_TO, -1, R_CUBIC_TO, 0, -0.41f, 0.15f, -0.77f, 0.44f, -1.06f,
    ARC_TO, 1.44f, 1.44f, 0, 0, 1, 3.5f, 4, R_H_LINE_TO, 5.71f, R_ARC_TO, 5.64f, 5.64f, 0, 0, 0, -0.16f, 0.73f, CUBIC_TO, 9.02f, 4.98f, 9, 5.24f, 9, 5.5f,
    H_LINE_TO, 3.5f, R_V_LINE_TO, 1.13f, R_CUBIC_TO, -0.25f, -0.04f, -0.5f, -0.07f, -0.75f, -0.09f, R_CUBIC_TO, -0.25f, -0.02f, -0.5f, -0.03f, -0.75f, -0.03f,
    CLOSE, R_MOVE_TO, 12.5f, 3, R_CUBIC_TO, -1.11f, 0, -2.05f, -0.39f, -2.83f, -1.17f, ARC_TO, 3.87f, 3.87f, 0, 0, 1, 10.5f, 5.5f, R_CUBIC_TO, 0, -1.11f, 0.39f,
    -2.05f, 1.17f, -2.83f, ARC_TO, 3.87f, 3.87f, 0, 0, 1, 14.5f, 1.5f, R_CUBIC_TO, 1.11f, 0, 2.05f, 0.39f, 2.83f, 1.17f, ARC_TO, 3.87f, 3.87f, 0, 0, 1, 18.5f,
    5.5f, R_CUBIC_TO, 0, 1.11f, -0.39f, 2.05f, -1.17f, 2.83f, ARC_TO, 3.87f, 3.87f, 0, 0, 1, 14.5f, 9.5f, CLOSE, R_MOVE_TO, 0, -2, R_CUBIC_TO, 0.13f, 0, 0.25f,
    -0.05f, 0.35f, -0.15f, ARC_TO, 0.49f, 0.49f, 0, 0, 0, 15, 7, R_CUBIC_TO, 0, -0.13f, -0.05f, -0.25f, -0.15f, -0.35f, ARC_TO, 0.49f, 0.49f, 0, 0, 0, 14.5f,
    6.5f, R_CUBIC_TO, -0.13f, 0, -0.25f, 0.05f, -0.35f, 0.15f, ARC_TO, 0.49f, 0.49f, 0, 0, 0, 14, 7, R_CUBIC_TO, 0, 0.13f, 0.05f, 0.25f, 0.15f, 0.35f, R_ARC_TO,
    0.49f, 0.49f, 0, 0, 0, 0.35f, 0.15f, CLOSE, R_MOVE_TO, -0.5f, -2, R_H_LINE_TO, 1, R_V_LINE_TO, -2, R_H_LINE_TO, -1, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kCastWarningRepList, kCastWarningIcon, { kCastWarningPath, std::size(kCastWarningPath) })
VECTOR_ICON_REP_TEMPLATE(kCelebrationPath, CANVAS_DIMENSIONS, 24, NEW_PATH, MOVE_TO, 2, 22, R_LINE_TO, 14, -5, LINE_TO, 7, 8, LINE_TO, 2, 22, CLOSE, MOVE_TO,
    12.35f, 16.18f, LINE_TO, 5.3f, 18.7f, R_LINE_TO, 2.52f, -7.05f, LINE_TO, 12.35f, 16.18f, CLOSE, NEW_PATH, MOVE_TO, 14.53f, 12.53f, R_LINE_TO, 5.59f, -5.59f,
    R_CUBIC_TO, 0.49f, -0.49f, 1.28f, -0.49f, 1.77f, 0, R_LINE_TO, 0.59f, 0.59f, R_LINE_TO, 1.06f, -1.06f, R_LINE_TO, -0.59f, -0.59f, R_CUBIC_TO, -1.07f,
    -1.07f, -2.82f, -1.07f, -3.89f, 0, R_LINE_TO, -5.59f, 5.59f, LINE_TO, 14.53f, 12.53f, CLOSE, NEW_PATH, MOVE_TO, 10.06f, 6.88f, LINE_TO, 9.47f, 7.47f,
    R_LINE_TO, 1.06f, 1.06f, R_LINE_TO, 0.59f, -0.59f, R_CUBIC_TO, 1.07f, -1.07f, 1.07f, -2.82f, 0, -3.89f, R_LINE_TO, -0.59f, -0.59f, LINE_TO, 9.47f, 4.53f,
    R_LINE_TO, 0.59f, 0.59f, CUBIC_TO, 10.54f, 5.6f, 10.54f, 6.4f, 10.06f, 6.88f, CLOSE, NEW_PATH, MOVE_TO, 17.06f, 11.88f, R_LINE_TO, -1.59f, 1.59f, R_LINE_TO,
    1.06f, 1.06f, R_LINE_TO, 1.59f, -1.59f, R_CUBIC_TO, 0.49f, -0.49f, 1.28f, -0.49f, 1.77f, 0, R_LINE_TO, 1.61f, 1.61f, R_LINE_TO, 1.06f, -1.06f, R_LINE_TO,
    -1.61f, -1.61f, CUBIC_TO, 19.87f, 10.81f, 18.13f, 10.81f, 17.06f, 11.88f, CLOSE, NEW_PATH, MOVE_TO, 15.06f, 5.88f, R_LINE_TO, -3.59f, 3.59f, R_LINE_TO,
    1.06f, 1.06f, R_LINE_TO, 3.59f, -3.59f, R_CUBIC_TO, 1.07f, -1.07f, 1.07f, -2.82f, 0, -3.89f, R_LINE_TO, -1.59f, -1.59f, R_LINE_TO, -1.06f, 1.06f, R_LINE_TO,
    1.59f, 1.59f, CUBIC_TO, 15.54f, 4.6f, 15.54f, 5.4f, 15.06f, 5.88f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kCelebrationRepList, kCelebrationIcon, { kCelebrationPath, std::size(kCelebrationPath) })
VECTOR_ICON_REP_TEMPLATE(kCertificatePath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 3.5f, 16, R_CUBIC_TO, -0.41f, 0, -0.77f, -0.15f, -1.06f, -0.44f,
    ARC_TO, 1.45f, 1.45f, 0, 0, 1, 2, 14.5f, V_LINE_TO, 5.49f, R_CUBIC_TO, 0, -0.41f, 0.15f, -0.76f, 0.44f, -1.05f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 3.5f, 4,
    R_H_LINE_TO, 13, R_CUBIC_TO, 0.41f, 0, 0.77f, 0.15f, 1.06f, 0.44f, R_CUBIC_TO, 0.29f, 0.29f, 0.44f, 0.65f, 0.44f, 1.06f, R_V_LINE_TO, 9.01f, R_CUBIC_TO, 0,
    0.41f, -0.15f, 0.76f, -0.44f, 1.06f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 16.5f, 16, CLOSE, R_MOVE_TO, 0, -1.5f, R_H_LINE_TO, 13, V_LINE_TO, 7, R_H_LINE_TO, -13,
    CLOSE, R_MOVE_TO, 5.63f, -0.83f, R_LINE_TO, -2.83f, -2.84f, LINE_TO, 7.36f, 9.77f, R_LINE_TO, 1.77f, 1.77f, LINE_TO, 12.65f, 8, R_LINE_TO, 1.06f, 1.06f,
    CLOSE, MOVE_TO, 3.5f, 14.5f, R_V_LINE_TO, -9, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kCertificateRepList, kCertificateIcon, { kCertificatePath, std::size(kCertificatePath) })
VECTOR_ICON_REP_TEMPLATE(kCertificateOffPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 16.73f, 18.83f, LINE_TO, 13.88f, 16, H_LINE_TO, 3.5f,
    R_CUBIC_TO, -0.42f, 0, -0.77f, -0.14f, -1.06f, -0.44f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 2, 14.5f, R_V_LINE_TO, -9, R_CUBIC_TO, 0, -0.42f, 0.15f, -0.77f,
    0.46f, -1.06f, ARC_TO, 1.55f, 1.55f, 0, 0, 1, 3.56f, 4, R_H_LINE_TO, 0.23f, R_V_LINE_TO, 1.9f, LINE_TO, 1.17f, 3.27f, LINE_TO, 2.23f, 2.23f, R_LINE_TO,
    15.54f, 15.54f, CLOSE, MOVE_TO, 3.5f, 14.5f, R_H_LINE_TO, 8.88f, LINE_TO, 4.88f, 7, H_LINE_TO, 3.5f, CLOSE, R_MOVE_TO, 14.13f, 1, LINE_TO, 16.5f, 14.38f,
    V_LINE_TO, 7, H_LINE_TO, 9.13f, R_LINE_TO, -3, -3, H_LINE_TO, 16.5f, R_CUBIC_TO, 0.42f, 0, 0.77f, 0.14f, 1.06f, 0.44f, R_CUBIC_TO, 0.29f, 0.29f, 0.44f,
    0.64f, 0.44f, 1.06f, R_V_LINE_TO, 9, R_CUBIC_TO, 0, 0.2f, -0.04f, 0.38f, -0.1f, 0.56f, R_CUBIC_TO, -0.07f, 0.18f, -0.16f, 0.33f, -0.27f, 0.44f, CLOSE,
    R_MOVE_TO, -5.17f, -5.17f, LINE_TO, 11.4f, 9.27f, LINE_TO, 12.65f, 8, R_LINE_TO, 1.06f, 1.06f, CLOSE, R_MOVE_TO, -1.06f, 1.06f, R_LINE_TO, -2.27f, 2.27f,
    R_LINE_TO, -2.83f, -2.84f, LINE_TO, 7.36f, 9.77f, R_LINE_TO, 1.77f, 1.77f, R_LINE_TO, 1.21f, -1.21f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kCertificateOffRepList, kCertificateOffIcon, { kCertificateOffPath, std::size(kCertificateOffPath) })
VECTOR_ICON_REP_TEMPLATE(kCheckCirclePath, CIRCLE, 24, 24, 20, MOVE_TO, 20, 34, LINE_TO, 10, 24, R_LINE_TO, 2.83f, -2.83f, LINE_TO, 20, 28.34f, R_LINE_TO,
    15.17f, -15.17f, LINE_TO, 38, 16, LINE_TO, 20, 34)
VECTOR_ICON_TEMPLATE_CC(kCheckCircleRepList, kCheckCircleIcon, { kCheckCirclePath, std::size(kCheckCirclePath) })
VECTOR_ICON_REP_TEMPLATE(kClosePath, CANVAS_DIMENSIONS, 24, MOVE_TO, 19, 6.41f, LINE_TO, 17.59f, 5, LINE_TO, 12, 10.59f, LINE_TO, 6.41f, 5, LINE_TO, 5, 6.41f,
    LINE_TO, 10.59f, 12, LINE_TO, 5, 17.59f, LINE_TO, 6.41f, 19, LINE_TO, 12, 13.41f, LINE_TO, 17.59f, 19, LINE_TO, 19, 17.59f, LINE_TO, 13.41f, 12, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kClose16Path, CANVAS_DIMENSIONS, 16, STROKE, 1.85f, MOVE_TO, 4, 4, R_LINE_TO, 8, 8, MOVE_TO, 4, 12, R_LINE_TO, 8, -8)
VECTOR_ICON_TEMPLATE_CC(kCloseRepList, kCloseIcon, { kClosePath, std::size(kClosePath) }, { kClose16Path, std::size(kClose16Path) })
VECTOR_ICON_REP_TEMPLATE(kCloseChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 6.06f, 15, LINE_TO, 5, 13.94f, LINE_TO, 8.94f, 10, LINE_TO,
    5, 6.06f, LINE_TO, 6.06f, 5, LINE_TO, 10, 8.94f, LINE_TO, 13.94f, 5, LINE_TO, 15, 6.06f, LINE_TO, 11.06f, 10, LINE_TO, 15, 13.94f, LINE_TO, 13.94f, 15,
    LINE_TO, 10, 11.06f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kCloseChromeRefreshRepList, kCloseChromeRefreshIcon, { kCloseChromeRefreshPath, std::size(kCloseChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(
    kCloseRoundedPath, CANVAS_DIMENSIONS, 32, STROKE, 3.5f, MOVE_TO, 8.75f, 8.75f, R_LINE_TO, 14.5f, 14.5f, MOVE_TO, 8.75f, 23.25f, R_LINE_TO, 14.5f, -14.5f)
VECTOR_ICON_REP_TEMPLATE(kCloseRounded16Path, CANVAS_DIMENSIONS, 16, STROKE, 1.85f, MOVE_TO, 4, 4, R_LINE_TO, 8, 8, MOVE_TO, 4, 12, R_LINE_TO, 8, -8)
VECTOR_ICON_TEMPLATE_CC(
    kCloseRoundedRepList, kCloseRoundedIcon, { kCloseRoundedPath, std::size(kCloseRoundedPath) }, { kCloseRounded16Path, std::size(kCloseRounded16Path) })
VECTOR_ICON_REP_TEMPLATE(kCloseSmallPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 7.04f, 14, LINE_TO, 6, 12.96f, LINE_TO, 8.94f, 10, LINE_TO, 6,
    7.06f, LINE_TO, 7.04f, 6.02f, LINE_TO, 10, 8.96f, R_LINE_TO, 2.94f, -2.94f, R_LINE_TO, 1.04f, 1.04f, LINE_TO, 11.04f, 10, R_LINE_TO, 2.94f, 2.96f, LINE_TO,
    12.94f, 14, LINE_TO, 10, 11.06f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kCloseSmallRepList, kCloseSmallIcon, { kCloseSmallPath, std::size(kCloseSmallPath) })
VECTOR_ICON_REP_TEMPLATE(kCodePath, MOVE_TO, 18.8f, 33.2f, LINE_TO, 9.7f, 24, R_LINE_TO, 9.2f, -9.2f, LINE_TO, 16, 12, LINE_TO, 4, 24, R_LINE_TO, 12, 12,
    R_LINE_TO, 2.8f, -2.8f, CLOSE, R_MOVE_TO, 10.4f, 0, R_LINE_TO, 9.2f, -9.2f, R_LINE_TO, -9.2f, -9.2f, LINE_TO, 32, 12, R_LINE_TO, 12, 12, R_LINE_TO, -12, 12,
    R_LINE_TO, -2.8f, -2.8f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kCodeRepList, kCodeIcon, { kCodePath, std::size(kCodePath) })
VECTOR_ICON_REP_TEMPLATE(kCodeChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, R_MOVE_TO, 7, 15, R_LINE_TO, -5, -5, R_LINE_TO, 5, -5, R_LINE_TO,
    1.06f, 1.06f, LINE_TO, 4.12f, 10, R_LINE_TO, 3.94f, 3.94f, CLOSE, R_MOVE_TO, 6, 0, R_LINE_TO, -1.06f, -1.06f, LINE_TO, 15.88f, 10, R_LINE_TO, -3.94f,
    -3.94f, LINE_TO, 13, 5, R_LINE_TO, 5, 5, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kCodeChromeRefreshRepList, kCodeChromeRefreshIcon, { kCodeChromeRefreshPath, std::size(kCodeChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kCodeOffChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, R_MOVE_TO, 16, 18.13f, R_LINE_TO, -10, -10, LINE_TO, 4.13f, 10,
    R_LINE_TO, 3.94f, 3.94f, LINE_TO, 7, 15, R_LINE_TO, -5, -5, R_LINE_TO, 2.94f, -2.94f, LINE_TO, 1.87f, 4, R_LINE_TO, 1.06f, -1.06f, R_LINE_TO, 14.12f,
    14.13f, CLOSE, R_MOVE_TO, -0.94f, -5.19f, LINE_TO, 14, 11.88f, LINE_TO, 15.88f, 10, R_LINE_TO, -3.94f, -3.94f, LINE_TO, 13, 5, R_LINE_TO, 5, 5, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kCodeOffChromeRefreshRepList, kCodeOffChromeRefreshIcon, { kCodeOffChromeRefreshPath, std::size(kCodeOffChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kContentCopyPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 9, 18, R_QUADRATIC_TO, -0.82f, 0, -1.41f, -0.59f, QUADRATIC_TO, 7, 16.83f, 7, 16,
    V_LINE_TO, 4, R_QUADRATIC_TO, 0, -0.82f, 0.59f, -1.41f, QUADRATIC_TO, 8.18f, 2, 9, 2, R_H_LINE_TO, 9, R_QUADRATIC_TO, 0.83f, 0, 1.41f, 0.59f, QUADRATIC_TO,
    20, 3.18f, 20, 4, R_V_LINE_TO, 12, R_QUADRATIC_TO, 0, 0.83f, -0.59f, 1.41f, QUADRATIC_TO, 18.83f, 18, 18, 18, CLOSE, R_MOVE_TO, 0, -2, R_H_LINE_TO, 9,
    V_LINE_TO, 4, H_LINE_TO, 9, R_V_LINE_TO, 12, CLOSE, R_MOVE_TO, -4, 6, R_QUADRATIC_TO, -0.82f, 0, -1.41f, -0.59f, QUADRATIC_TO, 3, 20.83f, 3, 20, V_LINE_TO,
    6, R_H_LINE_TO, 2, R_V_LINE_TO, 14, R_H_LINE_TO, 11, R_V_LINE_TO, 2, CLOSE, MOVE_TO, 9, 4, R_V_LINE_TO, 12, V_LINE_TO, 4, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kContentCopyRepList, kContentCopyIcon, { kContentCopyPath, std::size(kContentCopyPath) })
VECTOR_ICON_REP_TEMPLATE(kContentPastePath, CANVAS_DIMENSIONS, 24, FILL_RULE_NONZERO, MOVE_TO, 5, 21, R_CUBIC_TO, -0.55f, 0, -1.02f, -0.19f, -1.41f, -0.59f,
    ARC_TO, 1.94f, 1.94f, 0, 0, 1, 3, 19, V_LINE_TO, 5, R_CUBIC_TO, 0, -0.55f, 0.2f, -1.02f, 0.59f, -1.41f, CUBIC_TO, 3.98f, 3.2f, 4.45f, 3, 5, 3, R_H_LINE_TO,
    4.18f, R_ARC_TO, 2.72f, 2.72f, 0, 0, 1, 1.07f, -1.44f, ARC_TO, 2.98f, 2.98f, 0, 0, 1, 12, 1, R_CUBIC_TO, 0.67f, 0, 1.26f, 0.19f, 1.79f, 0.56f, R_CUBIC_TO,
    0.52f, 0.38f, 0.88f, 0.86f, 1.06f, 1.44f, H_LINE_TO, 19, R_CUBIC_TO, 0.55f, 0, 1.02f, 0.2f, 1.41f, 0.59f, R_CUBIC_TO, 0.39f, 0.39f, 0.59f, 0.86f, 0.59f,
    1.41f, R_V_LINE_TO, 14, R_CUBIC_TO, 0, 0.55f, -0.19f, 1.02f, -0.59f, 1.41f, R_CUBIC_TO, -0.39f, 0.39f, -0.86f, 0.59f, -1.41f, 0.59f, CLOSE, R_MOVE_TO, 0,
    -2, R_H_LINE_TO, 14, V_LINE_TO, 5, R_H_LINE_TO, -2, R_V_LINE_TO, 3, H_LINE_TO, 7, V_LINE_TO, 5, H_LINE_TO, 5, CLOSE, R_MOVE_TO, 7, -14, R_CUBIC_TO, 0.28f,
    0, 0.52f, -0.1f, 0.71f, -0.29f, ARC_TO, 0.96f, 0.96f, 0, 0, 0, 13, 4, R_ARC_TO, 0.96f, 0.96f, 0, 0, 0, -0.29f, -0.71f, ARC_TO, 0.96f, 0.96f, 0, 0, 0, 12, 3,
    R_ARC_TO, 0.96f, 0.96f, 0, 0, 0, -0.71f, 0.29f, ARC_TO, 0.96f, 0.96f, 0, 0, 0, 11, 4, R_CUBIC_TO, 0, 0.28f, 0.1f, 0.52f, 0.29f, 0.71f, R_CUBIC_TO, 0.19f,
    0.19f, 0.43f, 0.29f, 0.71f, 0.29f, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kContentPaste20Path, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 4.5f, 17, R_CUBIC_TO, -0.41f, 0, -0.77f, -0.15f, -1.06f,
    -0.44f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 3, 15.5f, R_V_LINE_TO, -11, R_CUBIC_TO, 0, -0.41f, 0.15f, -0.77f, 0.44f, -1.06f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 4.5f,
    3, R_H_LINE_TO, 3.56f, R_CUBIC_TO, 0.11f, -0.43f, 0.34f, -0.79f, 0.7f, -1.07f, ARC_TO, 1.91f, 1.91f, 0, 0, 1, 10, 1.5f, R_CUBIC_TO, 0.47f, 0, 0.89f, 0.14f,
    1.24f, 0.43f, R_CUBIC_TO, 0.36f, 0.28f, 0.59f, 0.64f, 0.7f, 1.07f, H_LINE_TO, 15.5f, R_CUBIC_TO, 0.41f, 0, 0.77f, 0.15f, 1.06f, 0.44f, R_CUBIC_TO, 0.29f,
    0.29f, 0.44f, 0.65f, 0.44f, 1.06f, R_V_LINE_TO, 11, R_CUBIC_TO, 0, 0.41f, -0.15f, 0.77f, -0.44f, 1.06f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 15.5f, 17, CLOSE,
    R_MOVE_TO, 0, -1.5f, R_H_LINE_TO, 11, R_V_LINE_TO, -11, H_LINE_TO, 14, V_LINE_TO, 7, H_LINE_TO, 6, V_LINE_TO, 4.5f, H_LINE_TO, 4.5f, CLOSE, R_MOVE_TO, 5.5f,
    -11, R_CUBIC_TO, 0.21f, 0, 0.39f, -0.07f, 0.54f, -0.21f, R_ARC_TO, 0.72f, 0.72f, 0, 0, 0, 0.22f, -0.53f, R_CUBIC_TO, 0, -0.21f, -0.07f, -0.39f, -0.21f,
    -0.53f, ARC_TO, 0.72f, 0.72f, 0, 0, 0, 10, 3, R_CUBIC_TO, -0.21f, 0, -0.39f, 0.07f, -0.53f, 0.22f, R_ARC_TO, 0.72f, 0.72f, 0, 0, 0, -0.22f, 0.53f,
    R_CUBIC_TO, 0, 0.21f, 0.07f, 0.39f, 0.22f, 0.54f, R_CUBIC_TO, 0.14f, 0.14f, 0.32f, 0.22f, 0.53f, 0.22f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(
    kContentPasteRepList, kContentPasteIcon, { kContentPastePath, std::size(kContentPastePath) }, { kContentPaste20Path, std::size(kContentPaste20Path) })
VECTOR_ICON_REP_TEMPLATE(kContentPasteOffPath, CANVAS_DIMENSIONS, 24, FILL_RULE_NONZERO, R_MOVE_TO, 21, 18.15f, R_LINE_TO, -2, -2, V_LINE_TO, 5, R_H_LINE_TO,
    -2, R_V_LINE_TO, 3, R_H_LINE_TO, -6.15f, R_LINE_TO, -5, -5, R_H_LINE_TO, 3.32f, R_ARC_TO, 2.72f, 2.72f, 0, 0, 1, 1.07f, -1.44f, ARC_TO, 2.98f, 2.98f, 0, 0,
    1, 12, 1, R_CUBIC_TO, 0.67f, 0, 1.26f, 0.19f, 1.79f, 0.56f, R_CUBIC_TO, 0.52f, 0.38f, 0.88f, 0.86f, 1.06f, 1.44f, H_LINE_TO, 19, R_CUBIC_TO, 0.55f, 0,
    1.02f, 0.2f, 1.41f, 0.59f, R_CUBIC_TO, 0.39f, 0.39f, 0.59f, 0.86f, 0.59f, 1.41f, CLOSE, MOVE_TO, 12, 5, R_CUBIC_TO, 0.28f, 0, 0.52f, -0.1f, 0.71f, -0.29f,
    ARC_TO, 0.96f, 0.96f, 0, 0, 0, 13, 4, R_ARC_TO, 0.96f, 0.96f, 0, 0, 0, -0.29f, -0.71f, ARC_TO, 0.96f, 0.96f, 0, 0, 0, 12, 3, R_ARC_TO, 0.96f, 0.96f, 0, 0,
    0, -0.71f, 0.29f, ARC_TO, 0.96f, 0.96f, 0, 0, 0, 11, 4, R_CUBIC_TO, 0, 0.28f, 0.1f, 0.52f, 0.29f, 0.71f, R_CUBIC_TO, 0.19f, 0.19f, 0.43f, 0.29f, 0.71f,
    0.29f, CLOSE, R_MOVE_TO, 4.15f, 14, LINE_TO, 5, 7.85f, V_LINE_TO, 19, CLOSE, MOVE_TO, 5, 21, R_CUBIC_TO, -0.55f, 0, -1.02f, -0.19f, -1.41f, -0.59f, ARC_TO,
    1.94f, 1.94f, 0, 0, 1, 3, 19, V_LINE_TO, 5.85f, LINE_TO, 1.38f, 4.23f, LINE_TO, 2.8f, 2.8f, R_LINE_TO, 18.4f, 18.4f, R_LINE_TO, -1.43f, 1.43f, LINE_TO,
    18.15f, 21, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kContentPasteOff20Path, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, R_MOVE_TO, 17, 14.88f, R_LINE_TO, -1.5f, -1.5f, V_LINE_TO, 4.5f,
    H_LINE_TO, 14, V_LINE_TO, 7, H_LINE_TO, 9.13f, R_LINE_TO, -4, -4, R_H_LINE_TO, 2.94f, R_CUBIC_TO, 0.15f, -0.44f, 0.39f, -0.8f, 0.72f, -1.08f, CUBIC_TO,
    9.11f, 1.64f, 9.52f, 1.5f, 10, 1.5f, R_CUBIC_TO, 0.48f, 0, 0.9f, 0.14f, 1.23f, 0.41f, R_CUBIC_TO, 0.33f, 0.27f, 0.57f, 0.64f, 0.71f, 1.09f, H_LINE_TO,
    15.5f, R_CUBIC_TO, 0.41f, 0, 0.77f, 0.15f, 1.06f, 0.44f, R_CUBIC_TO, 0.29f, 0.29f, 0.44f, 0.65f, 0.44f, 1.06f, CLOSE, MOVE_TO, 10, 4.5f, R_CUBIC_TO, 0.21f,
    0, 0.39f, -0.07f, 0.54f, -0.21f, R_ARC_TO, 0.72f, 0.72f, 0, 0, 0, 0.22f, -0.53f, R_CUBIC_TO, 0, -0.21f, -0.07f, -0.39f, -0.21f, -0.53f, ARC_TO, 0.72f,
    0.72f, 0, 0, 0, 10, 3, R_CUBIC_TO, -0.21f, 0, -0.39f, 0.07f, -0.53f, 0.22f, R_ARC_TO, 0.72f, 0.72f, 0, 0, 0, -0.22f, 0.53f, R_CUBIC_TO, 0, 0.21f, 0.07f,
    0.39f, 0.22f, 0.54f, R_CUBIC_TO, 0.14f, 0.14f, 0.32f, 0.22f, 0.53f, 0.22f, CLOSE, R_MOVE_TO, 3.38f, 11, LINE_TO, 4.5f, 6.63f, V_LINE_TO, 15.5f, CLOSE,
    MOVE_TO, 4.5f, 17, R_CUBIC_TO, -0.41f, 0, -0.77f, -0.15f, -1.06f, -0.44f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 3, 15.5f, V_LINE_TO, 5.13f, LINE_TO, 1.88f, 4,
    R_LINE_TO, 1.06f, -1.06f, R_LINE_TO, 14.12f, 14.13f, LINE_TO, 16, 18.13f, LINE_TO, 14.88f, 17, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kContentPasteOffRepList, kContentPasteOffIcon, { kContentPasteOffPath, std::size(kContentPasteOffPath) },
    { kContentPasteOff20Path, std::size(kContentPasteOff20Path) })
VECTOR_ICON_REP_TEMPLATE(kCookiePath, MOVE_TO, 31, 15, LINE_TO, 31, 14, CUBIC_TO, 31, 12.04f, 30, 11, 28, 11, LINE_TO, 27, 11, CUBIC_TO, 26.45f, 11, 26, 10.55f,
    26, 10, LINE_TO, 26, 6, CUBIC_TO, 26, 4.04f, 24, 4, 24, 4, CUBIC_TO, 12.6f, 4, 3.42f, 13.54f, 4.03f, 25.08f, CUBIC_TO, 4.56f, 35.17f, 12.83f, 43.44f,
    22.92f, 43.97f, CUBIC_TO, 34.46f, 44.58f, 44, 35.4f, 44, 24, LINE_TO, 44, 22, CUBIC_TO, 44, 20.9f, 43.11f, 20, 42, 20, LINE_TO, 38, 20, CUBIC_TO, 37.45f,
    20, 37, 19.55f, 37, 19, LINE_TO, 37, 18, CUBIC_TO, 37, 16.13f, 36.04f, 15.04f, 34, 15, LINE_TO, 31, 15, LINE_TO, 31, 15, CLOSE, MOVE_TO, 11.59f, 24.94f,
    CUBIC_TO, 9.47f, 25.35f, 7.66f, 23.53f, 8.06f, 21.41f, CUBIC_TO, 8.28f, 20.24f, 9.24f, 19.28f, 10.41f, 19.06f, CUBIC_TO, 12.53f, 18.66f, 14.35f, 20.47f,
    13.94f, 22.59f, CUBIC_TO, 13.72f, 23.76f, 12.76f, 24.72f, 11.59f, 24.94f, LINE_TO, 11.59f, 24.94f, CLOSE, MOVE_TO, 15.06f, 14.59f, CUBIC_TO, 14.66f, 12.47f,
    16.47f, 10.66f, 18.59f, 11.06f, CUBIC_TO, 19.76f, 11.28f, 20.72f, 12.24f, 20.94f, 13.41f, CUBIC_TO, 21.35f, 15.53f, 19.53f, 17.35f, 17.41f, 16.94f,
    CUBIC_TO, 16.24f, 16.72f, 15.28f, 15.76f, 15.06f, 14.59f, LINE_TO, 15.06f, 14.59f, CLOSE, MOVE_TO, 22.59f, 38.94f, CUBIC_TO, 20.47f, 39.35f, 18.66f, 37.53f,
    19.06f, 35.41f, CUBIC_TO, 19.28f, 34.24f, 20.24f, 33.28f, 21.41f, 33.06f, CUBIC_TO, 23.53f, 32.66f, 25.35f, 34.47f, 24.94f, 36.59f, CUBIC_TO, 24.72f,
    37.76f, 23.76f, 38.72f, 22.59f, 38.94f, LINE_TO, 22.59f, 38.94f, CLOSE, MOVE_TO, 23, 28, CUBIC_TO, 21.34f, 28, 20, 26.66f, 20, 25, CUBIC_TO, 20, 23.34f,
    21.34f, 22, 23, 22, CUBIC_TO, 24.66f, 22, 26, 23.34f, 26, 25, CUBIC_TO, 26, 26.66f, 24.66f, 28, 23, 28, LINE_TO, 23, 28, CLOSE, MOVE_TO, 33, 32, CUBIC_TO,
    31.34f, 32, 30, 30.66f, 30, 29, CUBIC_TO, 30, 27.34f, 31.34f, 26, 33, 26, CUBIC_TO, 34.66f, 26, 36, 27.34f, 36, 29, CUBIC_TO, 36, 30.66f, 34.66f, 32, 33,
    32, LINE_TO, 33, 32, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kCookieRepList, kCookieIcon, { kCookiePath, std::size(kCookiePath) })
VECTOR_ICON_REP_TEMPLATE(kCookieChromeRefreshPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 10.5f, 10, R_CUBIC_TO, 0.42f, 0, 0.77f, -0.14f, 1.06f, -0.44f, R_CUBIC_TO,
    0.29f, -0.29f, 0.44f, -0.64f, 0.44f, -1.06f, R_CUBIC_TO, 0, -0.42f, -0.14f, -0.77f, -0.44f, -1.06f, ARC_TO, 1.44f, 1.44f, 0, 0, 0, 10.5f, 7, R_CUBIC_TO,
    -0.42f, 0, -0.77f, 0.14f, -1.06f, 0.44f, ARC_TO, 1.44f, 1.44f, 0, 0, 0, 9, 8.5f, R_CUBIC_TO, 0, 0.42f, 0.14f, 0.77f, 0.44f, 1.06f, R_CUBIC_TO, 0.29f, 0.29f,
    0.64f, 0.44f, 1.06f, 0.44f, CLOSE, R_MOVE_TO, -2, 5, R_CUBIC_TO, 0.42f, 0, 0.77f, -0.14f, 1.06f, -0.44f, R_CUBIC_TO, 0.29f, -0.29f, 0.44f, -0.64f, 0.44f,
    -1.06f, R_CUBIC_TO, 0, -0.42f, -0.14f, -0.77f, -0.44f, -1.06f, ARC_TO, 1.44f, 1.44f, 0, 0, 0, 8.5f, 12, R_CUBIC_TO, -0.42f, 0, -0.77f, 0.14f, -1.06f, 0.44f,
    ARC_TO, 1.44f, 1.44f, 0, 0, 0, 7, 13.5f, R_CUBIC_TO, 0, 0.42f, 0.14f, 0.77f, 0.44f, 1.06f, R_CUBIC_TO, 0.29f, 0.29f, 0.64f, 0.44f, 1.06f, 0.44f, CLOSE,
    R_MOVE_TO, 6.5f, 1, R_CUBIC_TO, 0.28f, 0, 0.52f, -0.1f, 0.71f, -0.29f, ARC_TO, 0.96f, 0.96f, 0, 0, 0, 16, 15, R_ARC_TO, 0.96f, 0.96f, 0, 0, 0, -0.29f,
    -0.71f, ARC_TO, 0.96f, 0.96f, 0, 0, 0, 15, 14, R_ARC_TO, 0.96f, 0.96f, 0, 0, 0, -0.71f, 0.29f, R_ARC_TO, 0.96f, 0.96f, 0, 0, 0, -0.29f, 0.71f, R_CUBIC_TO,
    0, 0.28f, 0.1f, 0.52f, 0.29f, 0.71f, R_CUBIC_TO, 0.19f, 0.19f, 0.43f, 0.29f, 0.71f, 0.29f, CLOSE, R_MOVE_TO, -3, 6.14f, R_ARC_TO, 9.89f, 9.89f, 0, 0, 1,
    -3.95f, -0.8f, R_ARC_TO, 10.2f, 10.2f, 0, 0, 1, -3.22f, -2.17f, R_ARC_TO, 10.2f, 10.2f, 0, 0, 1, -2.17f, -3.22f, ARC_TO, 9.89f, 9.89f, 0, 0, 1, 1.86f, 12,
    R_CUBIC_TO, 0, -1.48f, 0.32f, -2.89f, 0.95f, -4.25f, R_ARC_TO, 10.3f, 10.3f, 0, 0, 1, 2.62f, -3.48f, R_CUBIC_TO, 1.11f, -0.96f, 2.42f, -1.66f, 3.93f, -2.1f,
    R_CUBIC_TO, 1.5f, -0.43f, 3.13f, -0.46f, 4.88f, -0.08f, R_CUBIC_TO, -0.16f, 0.76f, -0.12f, 1.47f, 0.11f, 2.13f, R_CUBIC_TO, 0.23f, 0.66f, 0.59f, 1.21f,
    1.07f, 1.65f, R_CUBIC_TO, 0.49f, 0.45f, 1.07f, 0.75f, 1.76f, 0.91f, R_CUBIC_TO, 0.68f, 0.16f, 1.41f, 0.13f, 2.18f, -0.12f, R_CUBIC_TO, -0.48f, 1.15f,
    -0.38f, 2.14f, 0.28f, 2.95f, R_CUBIC_TO, 0.67f, 0.82f, 1.48f, 1.23f, 2.43f, 1.24f, R_CUBIC_TO, 0.16f, 1.51f, 0.01f, 2.95f, -0.45f, 4.32f, R_CUBIC_TO,
    -0.46f, 1.36f, -1.15f, 2.56f, -2.07f, 3.59f, R_ARC_TO, 10.28f, 10.28f, 0, 0, 1, -3.32f, 2.45f, R_CUBIC_TO, -1.3f, 0.61f, -2.71f, 0.91f, -4.23f, 0.91f,
    CLOSE, R_MOVE_TO, 0, -2.27f, R_CUBIC_TO, 1.98f, 0, 3.75f, -0.68f, 5.29f, -2.03f, R_CUBIC_TO, 1.54f, -1.35f, 2.39f, -3.09f, 2.56f, -5.19f, R_CUBIC_TO,
    -0.81f, -0.37f, -1.45f, -0.87f, -1.92f, -1.5f, R_ARC_TO, 5.38f, 5.38f, 0, 0, 1, -0.96f, -2.09f, R_ARC_TO, 5.84f, 5.84f, 0, 0, 1, -3.28f, -1.65f, R_ARC_TO,
    5.97f, 5.97f, 0, 0, 1, -1.73f, -3.27f, R_CUBIC_TO, -1.26f, -0.02f, -2.38f, 0.23f, -3.35f, 0.72f, R_ARC_TO, 7.97f, 7.97f, 0, 0, 0, -2.45f, 1.91f, R_ARC_TO,
    8.47f, 8.47f, 0, 0, 0, -1.5f, 2.56f, R_CUBIC_TO, -0.34f, 0.93f, -0.51f, 1.82f, -0.51f, 2.68f, R_CUBIC_TO, 0, 2.18f, 0.77f, 4.04f, 2.3f, 5.57f, R_CUBIC_TO,
    1.53f, 1.53f, 3.39f, 2.3f, 5.57f, 2.3f, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kCookieChromeRefresh20Path, CANVAS_DIMENSIONS, 20, MOVE_TO, 8.75f, 8.5f, R_CUBIC_TO, 0.35f, 0, 0.64f, -0.12f, 0.89f, -0.36f,
    R_CUBIC_TO, 0.24f, -0.25f, 0.36f, -0.54f, 0.36f, -0.89f, R_CUBIC_TO, 0, -0.35f, -0.12f, -0.64f, -0.36f, -0.89f, ARC_TO, 1.22f, 1.22f, 0, 0, 0, 8.75f, 6,
    R_CUBIC_TO, -0.35f, 0, -0.64f, 0.12f, -0.89f, 0.36f, R_CUBIC_TO, -0.24f, 0.25f, -0.36f, 0.54f, -0.36f, 0.89f, R_CUBIC_TO, 0, 0.35f, 0.12f, 0.64f, 0.36f,
    0.89f, R_CUBIC_TO, 0.25f, 0.24f, 0.54f, 0.36f, 0.89f, 0.36f, CLOSE, R_MOVE_TO, -2, 4, R_CUBIC_TO, 0.35f, 0, 0.64f, -0.12f, 0.89f, -0.36f, R_CUBIC_TO, 0.24f,
    -0.25f, 0.36f, -0.54f, 0.36f, -0.89f, R_CUBIC_TO, 0, -0.35f, -0.12f, -0.64f, -0.36f, -0.89f, ARC_TO, 1.22f, 1.22f, 0, 0, 0, 6.75f, 10, R_CUBIC_TO, -0.35f,
    0, -0.64f, 0.12f, -0.89f, 0.36f, R_CUBIC_TO, -0.24f, 0.25f, -0.36f, 0.54f, -0.36f, 0.89f, R_CUBIC_TO, 0, 0.35f, 0.12f, 0.64f, 0.36f, 0.89f, R_CUBIC_TO,
    0.25f, 0.24f, 0.54f, 0.36f, 0.89f, 0.36f, CLOSE, R_MOVE_TO, 5.75f, 0.75f, R_CUBIC_TO, 0.21f, 0, 0.39f, -0.07f, 0.54f, -0.21f, R_ARC_TO, 0.72f, 0.72f, 0, 0,
    0, 0.22f, -0.53f, R_CUBIC_TO, 0, -0.21f, -0.07f, -0.39f, -0.21f, -0.53f, R_ARC_TO, 0.72f, 0.72f, 0, 0, 0, -0.53f, -0.22f, R_CUBIC_TO, -0.21f, 0, -0.39f,
    0.07f, -0.53f, 0.22f, R_ARC_TO, 0.72f, 0.72f, 0, 0, 0, -0.22f, 0.53f, R_CUBIC_TO, 0, 0.21f, 0.07f, 0.39f, 0.22f, 0.54f, R_CUBIC_TO, 0.14f, 0.14f, 0.32f,
    0.22f, 0.53f, 0.22f, CLOSE, MOVE_TO, 10, 18.11f, R_ARC_TO, 7.92f, 7.92f, 0, 0, 1, -3.15f, -0.63f, R_ARC_TO, 8.16f, 8.16f, 0, 0, 1, -4.33f, -4.33f, ARC_TO,
    7.92f, 7.92f, 0, 0, 1, 1.89f, 10, R_CUBIC_TO, 0, -1.35f, 0.29f, -2.59f, 0.89f, -3.72f, R_CUBIC_TO, 0.59f, -1.12f, 1.36f, -2.05f, 2.31f, -2.79f, ARC_TO,
    8.23f, 8.23f, 0, 0, 1, 8.27f, 1.98f, R_ARC_TO, 6.82f, 6.82f, 0, 0, 1, 3.53f, 0.1f, R_CUBIC_TO, -0.11f, 0.62f, -0.09f, 1.19f, 0.08f, 1.7f, R_CUBIC_TO, 0.16f,
    0.51f, 0.44f, 0.94f, 0.82f, 1.27f, R_CUBIC_TO, 0.38f, 0.33f, 0.84f, 0.57f, 1.4f, 0.7f, R_CUBIC_TO, 0.56f, 0.13f, 1.15f, 0.13f, 1.8f, -0.02f, R_CUBIC_TO,
    -0.32f, 0.79f, -0.26f, 1.55f, 0.16f, 2.27f, R_CUBIC_TO, 0.43f, 0.72f, 1.1f, 1.08f, 2.01f, 1.09f, R_ARC_TO, 7.82f, 7.82f, 0, 0, 1, -0.36f, 3.44f, R_ARC_TO,
    8.37f, 8.37f, 0, 0, 1, -1.66f, 2.88f, R_ARC_TO, 8.21f, 8.21f, 0, 0, 1, -2.66f, 1.98f, R_CUBIC_TO, -1.04f, 0.49f, -2.17f, 0.74f, -3.39f, 0.74f, CLOSE,
    R_MOVE_TO, 0, -1.73f, R_CUBIC_TO, 1.7f, 0, 3.15f, -0.57f, 4.36f, -1.71f, R_CUBIC_TO, 1.21f, -1.14f, 1.88f, -2.55f, 2.01f, -4.24f, R_ARC_TO, 3.8f, 3.8f, 0,
    0, 1, -1.53f, -1.16f, R_ARC_TO, 3.86f, 3.86f, 0, 0, 1, -0.79f, -1.75f, R_ARC_TO, 4.86f, 4.86f, 0, 0, 1, -2.67f, -1.31f, R_ARC_TO, 4.42f, 4.42f, 0, 0, 1,
    -1.34f, -2.6f, R_ARC_TO, 5.58f, 5.58f, 0, 0, 0, -2.37f, 0.41f, R_CUBIC_TO, -0.77f, 0.31f, -1.46f, 0.75f, -2.06f, 1.32f, R_ARC_TO, 6.35f, 6.35f, 0, 0, 0,
    -1.45f, 2.05f, ARC_TO, 6.23f, 6.23f, 0, 0, 0, 3.61f, 10, R_CUBIC_TO, 0, 1.77f, 0.63f, 3.28f, 1.87f, 4.52f, R_CUBIC_TO, 1.24f, 1.24f, 2.75f, 1.87f, 4.52f,
    1.87f, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kCookieChromeRefresh16Path, CANVAS_DIMENSIONS, 16, MOVE_TO, 7, 6.8f, R_ARC_TO, 0.96f, 0.96f, 0, 0, 0, 0.71f, -0.29f, ARC_TO, 0.96f,
    0.96f, 0, 0, 0, 8, 5.8f, R_ARC_TO, 0.97f, 0.97f, 0, 0, 0, -0.29f, -0.71f, ARC_TO, 0.97f, 0.97f, 0, 0, 0, 7, 4.8f, R_ARC_TO, 0.97f, 0.97f, 0, 0, 0, -0.71f,
    0.29f, ARC_TO, 0.97f, 0.97f, 0, 0, 0, 6, 5.8f, R_CUBIC_TO, 0, 0.28f, 0.1f, 0.51f, 0.29f, 0.71f, R_CUBIC_TO, 0.19f, 0.2f, 0.43f, 0.29f, 0.71f, 0.29f, CLOSE,
    MOVE_TO, 5.4f, 10, R_ARC_TO, 0.96f, 0.96f, 0, 0, 0, 0.71f, -0.29f, ARC_TO, 0.95f, 0.95f, 0, 0, 0, 6.4f, 9, R_ARC_TO, 0.95f, 0.95f, 0, 0, 0, -0.29f, -0.71f,
    ARC_TO, 0.96f, 0.96f, 0, 0, 0, 5.4f, 8, R_ARC_TO, 0.96f, 0.96f, 0, 0, 0, -0.71f, 0.29f, R_ARC_TO, 0.96f, 0.96f, 0, 0, 0, -0.29f, 0.71f, R_CUBIC_TO, 0,
    0.28f, 0.1f, 0.52f, 0.29f, 0.71f, R_CUBIC_TO, 0.2f, 0.2f, 0.43f, 0.29f, 0.71f, 0.29f, CLOSE, R_MOVE_TO, 4.6f, 0.6f, R_ARC_TO, 0.6f, 0.6f, 0, 0, 0, 0.43f,
    -0.17f, R_ARC_TO, 0.58f, 0.58f, 0, 0, 0, 0.18f, -0.43f, R_ARC_TO, 0.6f, 0.6f, 0, 0, 0, -0.17f, -0.43f, R_ARC_TO, 0.58f, 0.58f, 0, 0, 0, -0.43f, -0.18f,
    R_ARC_TO, 0.6f, 0.6f, 0, 0, 0, -0.43f, 0.17f, R_ARC_TO, 0.58f, 0.58f, 0, 0, 0, -0.18f, 0.43f, R_CUBIC_TO, 0, 0.17f, 0.06f, 0.31f, 0.17f, 0.43f, R_ARC_TO,
    0.58f, 0.58f, 0, 0, 0, 0.43f, 0.18f, CLOSE, MOVE_TO, 8, 14.62f, R_CUBIC_TO, -0.91f, 0, -1.77f, -0.17f, -2.57f, -0.51f, R_ARC_TO, 6.61f, 6.61f, 0, 0, 1,
    -2.11f, -1.42f, R_ARC_TO, 6.61f, 6.61f, 0, 0, 1, -1.42f, -2.11f, ARC_TO, 6.46f, 6.46f, 0, 0, 1, 1.38f, 8, R_CUBIC_TO, 0, -1.15f, 0.25f, -2.19f, 0.75f,
    -3.11f, ARC_TO, 6.85f, 6.85f, 0, 0, 1, 4.08f, 2.63f, ARC_TO, 6.79f, 6.79f, 0, 0, 1, 6.73f, 1.44f, R_ARC_TO, 5.67f, 5.67f, 0, 0, 1, 2.86f, 0.12f, R_CUBIC_TO,
    -0.09f, 0.51f, -0.09f, 0.97f, 0.03f, 1.38f, R_CUBIC_TO, 0.11f, 0.41f, 0.32f, 0.75f, 0.61f, 1.01f, R_CUBIC_TO, 0.29f, 0.26f, 0.66f, 0.45f, 1.1f, 0.55f,
    R_CUBIC_TO, 0.44f, 0.1f, 0.93f, 0.1f, 1.47f, -0.01f, R_CUBIC_TO, -0.22f, 0.64f, -0.18f, 1.24f, 0.14f, 1.82f, R_CUBIC_TO, 0.32f, 0.57f, 0.86f, 0.86f, 1.64f,
    0.84f, R_ARC_TO, 6.49f, 6.49f, 0, 0, 1, -0.26f, 2.83f, R_ARC_TO, 6.79f, 6.79f, 0, 0, 1, -1.34f, 2.38f, ARC_TO, 6.68f, 6.68f, 0, 0, 1, 10.79f, 14,
    R_CUBIC_TO, -0.85f, 0.41f, -1.78f, 0.62f, -2.79f, 0.62f, CLOSE, R_MOVE_TO, 0, -1.63f, R_CUBIC_TO, 1.31f, 0, 2.44f, -0.44f, 3.37f, -1.3f, R_CUBIC_TO, 0.94f,
    -0.87f, 1.47f, -1.95f, 1.58f, -3.25f, R_ARC_TO, 3.13f, 3.13f, 0, 0, 1, -1.18f, -0.92f, R_ARC_TO, 3.05f, 3.05f, 0, 0, 1, -0.63f, -1.37f, ARC_TO, 4.05f,
    4.05f, 0, 0, 1, 9.03f, 5.09f, ARC_TO, 3.55f, 3.55f, 0, 0, 1, 7.93f, 3.04f, R_ARC_TO, 4.47f, 4.47f, 0, 0, 0, -1.75f, 0.32f, R_CUBIC_TO, -0.58f, 0.23f,
    -1.11f, 0.56f, -1.58f, 0.99f, R_CUBIC_TO, -0.47f, 0.43f, -0.86f, 0.95f, -1.14f, 1.57f, R_CUBIC_TO, -0.29f, 0.62f, -0.43f, 1.31f, -0.43f, 2.07f, R_CUBIC_TO,
    0, 1.38f, 0.49f, 2.56f, 1.46f, 3.53f, R_CUBIC_TO, 0.97f, 0.97f, 2.15f, 1.46f, 3.53f, 1.46f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kCookieChromeRefreshRepList, kCookieChromeRefreshIcon, { kCookieChromeRefreshPath, std::size(kCookieChromeRefreshPath) },
    { kCookieChromeRefresh20Path, std::size(kCookieChromeRefresh20Path) }, { kCookieChromeRefresh16Path, std::size(kCookieChromeRefresh16Path) })
VECTOR_ICON_REP_TEMPLATE(kCookieOffChromeRefreshPath, CANVAS_DIMENSIONS, 24, R_MOVE_TO, 20.55f, 17.47f, R_LINE_TO, -1.66f, -1.66f, R_CUBIC_TO, 0.26f, -0.47f,
    0.48f, -0.98f, 0.64f, -1.51f, R_CUBIC_TO, 0.16f, -0.53f, 0.27f, -1.09f, 0.32f, -1.66f, R_CUBIC_TO, -0.81f, -0.37f, -1.45f, -0.87f, -1.92f, -1.5f, R_ARC_TO,
    5.38f, 5.38f, 0, 0, 1, -0.96f, -2.09f, R_ARC_TO, 5.84f, 5.84f, 0, 0, 1, -3.28f, -1.65f, R_ARC_TO, 5.97f, 5.97f, 0, 0, 1, -1.73f, -3.27f, R_ARC_TO, 6.8f,
    6.8f, 0, 0, 0, -2.04f, 0.24f, R_ARC_TO, 7.57f, 7.57f, 0, 0, 0, -1.74f, 0.73f, R_LINE_TO, -1.64f, -1.64f, R_CUBIC_TO, 1.05f, -0.7f, 2.22f, -1.18f, 3.52f,
    -1.44f, R_CUBIC_TO, 1.3f, -0.26f, 2.7f, -0.23f, 4.18f, 0.08f, R_CUBIC_TO, -0.16f, 0.76f, -0.12f, 1.47f, 0.11f, 2.13f, R_CUBIC_TO, 0.23f, 0.66f, 0.59f,
    1.21f, 1.07f, 1.65f, R_CUBIC_TO, 0.49f, 0.45f, 1.07f, 0.75f, 1.76f, 0.91f, R_CUBIC_TO, 0.68f, 0.16f, 1.41f, 0.13f, 2.18f, -0.12f, R_CUBIC_TO, -0.48f, 1.15f,
    -0.38f, 2.14f, 0.28f, 2.95f, R_CUBIC_TO, 0.67f, 0.82f, 1.48f, 1.23f, 2.43f, 1.24f, R_ARC_TO, 9.48f, 9.48f, 0, 0, 1, -0.21f, 3.5f, R_ARC_TO, 10.67f, 10.67f,
    0, 0, 1, -1.32f, 3.1f, CLOSE, MOVE_TO, 8.5f, 15, R_CUBIC_TO, -0.42f, 0, -0.77f, -0.14f, -1.06f, -0.44f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 7, 13.5f, R_CUBIC_TO,
    0, -0.42f, 0.14f, -0.77f, 0.44f, -1.06f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 8.5f, 12, R_CUBIC_TO, 0.42f, 0, 0.77f, 0.14f, 1.06f, 0.44f, R_CUBIC_TO, 0.29f,
    0.29f, 0.44f, 0.64f, 0.44f, 1.06f, R_CUBIC_TO, 0, 0.42f, -0.14f, 0.77f, -0.44f, 1.06f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 8.5f, 15, CLOSE, R_MOVE_TO, 12.07f,
    8.43f, R_LINE_TO, -2.92f, -2.91f, R_CUBIC_TO, -0.82f, 0.55f, -1.7f, 0.97f, -2.64f, 1.25f, R_CUBIC_TO, -0.95f, 0.29f, -1.95f, 0.44f, -3.01f, 0.44f,
    R_CUBIC_TO, -1.41f, 0, -2.74f, -0.26f, -3.98f, -0.8f, R_ARC_TO, 10.38f, 10.38f, 0, 0, 1, -3.24f, -2.17f, R_CUBIC_TO, -0.91f, -0.92f, -1.64f, -2, -2.17f,
    -3.24f, R_CUBIC_TO, -0.54f, -1.24f, -0.8f, -2.57f, -0.8f, -3.98f, R_CUBIC_TO, 0, -1.06f, 0.14f, -2.06f, 0.44f, -3.01f, R_ARC_TO, 9.96f, 9.96f, 0, 0, 1,
    1.25f, -2.64f, LINE_TO, 0.65f, 3.5f, R_LINE_TO, 1.48f, -1.48f, LINE_TO, 22.06f, 21.94f, CLOSE, MOVE_TO, 12, 19.93f, R_CUBIC_TO, 0.73f, 0, 1.43f, -0.1f,
    2.1f, -0.29f, R_ARC_TO, 8.27f, 8.27f, 0, 0, 0, 1.88f, -0.8f, LINE_TO, 5.16f, 8.02f, R_CUBIC_TO, -0.34f, 0.59f, -0.61f, 1.21f, -0.8f, 1.88f, ARC_TO, 7.57f,
    7.57f, 0, 0, 0, 4.07f, 12, R_CUBIC_TO, 0, 2.2f, 0.77f, 4.07f, 2.32f, 5.61f, CUBIC_TO, 7.93f, 19.16f, 9.81f, 19.93f, 12, 19.93f, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kCookieOffChromeRefresh20Path, CANVAS_DIMENSIONS, 20, R_MOVE_TO, 16.77f, 14.47f, R_LINE_TO, -1.28f, -1.28f, R_CUBIC_TO, 0.24f, -0.41f,
    0.44f, -0.84f, 0.59f, -1.3f, R_ARC_TO, 6.24f, 6.24f, 0, 0, 0, 0.29f, -1.45f, R_ARC_TO, 3.8f, 3.8f, 0, 0, 1, -1.53f, -1.16f, R_ARC_TO, 3.86f, 3.86f, 0, 0, 1,
    -0.79f, -1.75f, R_ARC_TO, 4.86f, 4.86f, 0, 0, 1, -2.67f, -1.31f, R_ARC_TO, 4.42f, 4.42f, 0, 0, 1, -1.34f, -2.6f, R_ARC_TO, 5.69f, 5.69f, 0, 0, 0, -1.71f,
    0.18f, R_ARC_TO, 5.89f, 5.89f, 0, 0, 0, -1.56f, 0.67f, LINE_TO, 5.49f, 3.19f, R_ARC_TO, 8, 8, 0, 0, 1, 3.02f, -1.28f, R_ARC_TO, 6.69f, 6.69f, 0, 0, 1,
    3.29f, 0.17f, R_CUBIC_TO, -0.11f, 0.62f, -0.09f, 1.19f, 0.07f, 1.7f, R_CUBIC_TO, 0.16f, 0.51f, 0.44f, 0.94f, 0.82f, 1.27f, R_CUBIC_TO, 0.38f, 0.33f, 0.84f,
    0.57f, 1.4f, 0.7f, R_CUBIC_TO, 0.56f, 0.13f, 1.15f, 0.13f, 1.8f, -0.02f, R_CUBIC_TO, -0.32f, 0.79f, -0.26f, 1.55f, 0.16f, 2.27f, R_CUBIC_TO, 0.43f, 0.72f,
    1.1f, 1.08f, 2.01f, 1.09f, R_ARC_TO, 7.82f, 7.82f, 0, 0, 1, -0.18f, 2.87f, R_ARC_TO, 8.05f, 8.05f, 0, 0, 1, -1.12f, 2.52f, CLOSE, MOVE_TO, 6.75f, 12.5f,
    R_CUBIC_TO, -0.35f, 0, -0.64f, -0.12f, -0.89f, -0.36f, R_ARC_TO, 1.22f, 1.22f, 0, 0, 1, -0.36f, -0.89f, R_CUBIC_TO, 0, -0.35f, 0.12f, -0.64f, 0.36f, -0.89f,
    R_CUBIC_TO, 0.25f, -0.24f, 0.54f, -0.36f, 0.89f, -0.36f, R_CUBIC_TO, 0.35f, 0, 0.64f, 0.12f, 0.89f, 0.36f, R_CUBIC_TO, 0.24f, 0.25f, 0.36f, 0.54f, 0.36f,
    0.89f, R_CUBIC_TO, 0, 0.35f, -0.12f, 0.64f, -0.36f, 0.89f, R_CUBIC_TO, -0.25f, 0.24f, -0.54f, 0.36f, -0.89f, 0.36f, CLOSE, R_MOVE_TO, 9.2f, 5.61f,
    R_LINE_TO, -1.35f, -1.35f, R_ARC_TO, 8.76f, 8.76f, 0, 0, 1, -2.2f, 1.05f, R_ARC_TO, 8.01f, 8.01f, 0, 0, 1, -2.4f, 0.36f, R_ARC_TO, 7.97f, 7.97f, 0, 0, 1,
    -3.18f, -0.64f, R_ARC_TO, 8.2f, 8.2f, 0, 0, 1, -2.6f, -1.75f, R_ARC_TO, 8.2f, 8.2f, 0, 0, 1, -1.75f, -2.6f, ARC_TO, 7.97f, 7.97f, 0, 0, 1, 1.83f, 10,
    R_CUBIC_TO, 0, -0.83f, 0.12f, -1.62f, 0.36f, -2.4f, R_ARC_TO, 8.76f, 8.76f, 0, 0, 1, 1.05f, -2.2f, R_LINE_TO, -1.26f, -1.27f, R_LINE_TO, 1.11f, -1.11f,
    R_LINE_TO, 13.98f, 13.98f, CLOSE, R_MOVE_TO, -5.95f, -1.66f, R_CUBIC_TO, 0.6f, 0, 1.17f, -0.09f, 1.74f, -0.26f, R_ARC_TO, 8.67f, 8.67f, 0, 0, 0, 1.62f,
    -0.69f, LINE_TO, 4.51f, 6.64f, R_ARC_TO, 8.82f, 8.82f, 0, 0, 0, -0.69f, 1.62f, R_ARC_TO, 5.89f, 5.89f, 0, 0, 0, -0.26f, 1.74f, R_CUBIC_TO, 0, 1.79f, 0.63f,
    3.31f, 1.88f, 4.56f, R_CUBIC_TO, 1.25f, 1.25f, 2.78f, 1.88f, 4.56f, 1.88f, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kCookieOffChromeRefresh16Path, CANVAS_DIMENSIONS, 16, R_MOVE_TO, 13.57f, 11.54f, R_LINE_TO, -1.22f, -1.21f, R_ARC_TO, 4.42f, 4.42f, 0,
    0, 0, 0.4f, -0.9f, R_CUBIC_TO, 0.1f, -0.32f, 0.17f, -0.65f, 0.2f, -1, R_ARC_TO, 3.13f, 3.13f, 0, 0, 1, -1.18f, -0.92f, R_ARC_TO, 3.05f, 3.05f, 0, 0, 1,
    -0.63f, -1.37f, ARC_TO, 4.05f, 4.05f, 0, 0, 1, 9.03f, 5.09f, ARC_TO, 3.55f, 3.55f, 0, 0, 1, 7.93f, 3.04f, R_ARC_TO, 4.42f, 4.42f, 0, 0, 0, -2.28f, 0.58f,
    LINE_TO, 4.42f, 2.4f, ARC_TO, 6.57f, 6.57f, 0, 0, 1, 6.92f, 1.39f, R_ARC_TO, 5.42f, 5.42f, 0, 0, 1, 2.67f, 0.17f, R_CUBIC_TO, -0.09f, 0.51f, -0.09f, 0.97f,
    0.03f, 1.38f, R_CUBIC_TO, 0.11f, 0.41f, 0.32f, 0.75f, 0.61f, 1.01f, R_CUBIC_TO, 0.29f, 0.26f, 0.66f, 0.45f, 1.1f, 0.55f, R_CUBIC_TO, 0.44f, 0.1f, 0.93f,
    0.1f, 1.47f, -0.01f, R_CUBIC_TO, -0.22f, 0.64f, -0.18f, 1.24f, 0.14f, 1.82f, R_CUBIC_TO, 0.32f, 0.57f, 0.86f, 0.85f, 1.64f, 0.84f, R_ARC_TO, 6.59f, 6.59f,
    0, 0, 1, -0.12f, 2.34f, R_ARC_TO, 6.64f, 6.64f, 0, 0, 1, -0.87f, 2.06f, CLOSE, MOVE_TO, 5.4f, 10, R_ARC_TO, 0.96f, 0.96f, 0, 0, 1, -0.71f, -0.29f, ARC_TO,
    0.96f, 0.96f, 0, 0, 1, 4.4f, 9, R_CUBIC_TO, 0, -0.28f, 0.1f, -0.52f, 0.29f, -0.71f, ARC_TO, 0.96f, 0.96f, 0, 0, 1, 5.4f, 8, R_CUBIC_TO, 0.28f, 0, 0.52f,
    0.1f, 0.71f, 0.29f, R_CUBIC_TO, 0.2f, 0.19f, 0.29f, 0.43f, 0.29f, 0.71f, R_ARC_TO, 0.95f, 0.95f, 0, 0, 1, -0.29f, 0.71f, R_ARC_TO, 0.96f, 0.96f, 0, 0, 1,
    -0.71f, 0.29f, CLOSE, R_MOVE_TO, 7.45f, 4.6f, R_LINE_TO, -1.05f, -1.04f, R_ARC_TO, 7.28f, 7.28f, 0, 0, 1, -1.81f, 0.86f, R_CUBIC_TO, -0.64f, 0.2f, -1.3f,
    0.3f, -1.98f, 0.3f, R_ARC_TO, 6.51f, 6.51f, 0, 0, 1, -2.62f, -0.52f, R_ARC_TO, 6.7f, 6.7f, 0, 0, 1, -2.14f, -1.44f, R_ARC_TO, 6.7f, 6.7f, 0, 0, 1, -1.44f,
    -2.14f, ARC_TO, 6.51f, 6.51f, 0, 0, 1, 1.28f, 8, R_CUBIC_TO, 0, -0.68f, 0.1f, -1.34f, 0.3f, -1.98f, R_ARC_TO, 7.28f, 7.28f, 0, 0, 1, 0.86f, -1.81f,
    R_LINE_TO, -0.89f, -0.9f, R_LINE_TO, 0.94f, -0.95f, R_LINE_TO, 11.3f, 11.3f, CLOSE, MOVE_TO, 8, 13.09f, R_ARC_TO, 4.8f, 4.8f, 0, 0, 0, 1.36f, -0.19f,
    R_ARC_TO, 6.43f, 6.43f, 0, 0, 0, 1.27f, -0.53f, R_LINE_TO, -6.98f, -6.99f, R_ARC_TO, 6.5f, 6.5f, 0, 0, 0, -0.53f, 1.26f, ARC_TO, 4.84f, 4.84f, 0, 0, 0,
    2.91f, 8, R_CUBIC_TO, 0, 1.41f, 0.5f, 2.62f, 1.48f, 3.61f, R_CUBIC_TO, 0.99f, 0.99f, 2.2f, 1.48f, 3.6f, 1.48f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kCookieOffChromeRefreshRepList, kCookieOffChromeRefreshIcon, { kCookieOffChromeRefreshPath, std::size(kCookieOffChromeRefreshPath) },
    { kCookieOffChromeRefresh20Path, std::size(kCookieOffChromeRefresh20Path) }, { kCookieOffChromeRefresh16Path, std::size(kCookieOffChromeRefresh16Path) })
VECTOR_ICON_REP_TEMPLATE(kDangerousPath, CANVAS_DIMENSIONS, 20, MOVE_TO, 6.18f, 19.24f, LINE_TO, 0.76f, 13.8f, V_LINE_TO, 6.18f, LINE_TO, 6.18f, 0.76f,
    R_H_LINE_TO, 7.65f, LINE_TO, 19.24f, 6.18f, R_V_LINE_TO, 7.65f, LINE_TO, 13.8f, 19.24f, CLOSE, MOVE_TO, 7.06f, 14.32f, LINE_TO, 10, 11.4f, LINE_TO, 12.94f,
    14.32f, LINE_TO, 14.32f, 12.94f, LINE_TO, 11.4f, 10, LINE_TO, 14.32f, 7.06f, LINE_TO, 12.94f, 5.68f, LINE_TO, 10, 8.6f, LINE_TO, 7.06f, 5.68f, LINE_TO,
    5.68f, 7.06f, LINE_TO, 8.6f, 10, LINE_TO, 5.68f, 12.94f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kDangerousRepList, kDangerousIcon, { kDangerousPath, std::size(kDangerousPath) })
VECTOR_ICON_REP_TEMPLATE(kDangerousChromeRefreshPath, CANVAS_DIMENSIONS, 20, MOVE_TO, 7.11f, 17, LINE_TO, 3, 12.88f, LINE_TO, 3, 7.11f, LINE_TO, 7.11f, 3,
    LINE_TO, 12.89f, 3, LINE_TO, 17, 7.11f, LINE_TO, 17, 12.89f, LINE_TO, 12.88f, 17, CLOSE, MOVE_TO, 7.77f, 13.27f, LINE_TO, 10, 11.06f, LINE_TO, 12.23f,
    13.27f, LINE_TO, 13.27f, 12.23f, LINE_TO, 11.06f, 10, LINE_TO, 13.27f, 7.77f, LINE_TO, 12.23f, 6.73f, LINE_TO, 10, 8.94f, LINE_TO, 7.77f, 6.73f, LINE_TO,
    6.73f, 7.77f, LINE_TO, 8.94f, 10, LINE_TO, 6.73f, 12.23f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kDangerousChromeRefreshRepList, kDangerousChromeRefreshIcon, { kDangerousChromeRefreshPath, std::size(kDangerousChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kDatabasePath, CANVAS_DIMENSIONS, 24, FILL_RULE_NONZERO, MOVE_TO, 12, 21, R_CUBIC_TO, -2.52f, 0, -4.64f, -0.39f, -6.39f, -1.16f,
    CUBIC_TO, 3.87f, 19.06f, 3, 18.12f, 3, 17, V_LINE_TO, 7, R_CUBIC_TO, 0, -1.1f, 0.88f, -2.04f, 2.64f, -2.82f, CUBIC_TO, 7.4f, 3.39f, 9.52f, 3, 12, 3,
    R_CUBIC_TO, 2.48f, 0, 4.61f, 0.39f, 6.36f, 1.18f, CUBIC_TO, 20.12f, 4.96f, 21, 5.9f, 21, 7, R_V_LINE_TO, 10, R_CUBIC_TO, 0, 1.12f, -0.87f, 2.06f, -2.61f,
    2.84f, CUBIC_TO, 16.65f, 20.61f, 14.52f, 21, 12, 21, CLOSE, R_MOVE_TO, 0, -11.98f, R_CUBIC_TO, 1.48f, 0, 2.98f, -0.21f, 4.48f, -0.64f, R_CUBIC_TO, 1.5f,
    -0.43f, 2.34f, -0.88f, 2.52f, -1.36f, R_CUBIC_TO, -0.18f, -0.48f, -1.02f, -0.94f, -2.51f, -1.37f, ARC_TO, 16.01f, 16.01f, 0, 0, 0, 12, 5, R_CUBIC_TO,
    -1.52f, 0, -3, 0.21f, -4.46f, 0.64f, R_CUBIC_TO, -1.46f, 0.43f, -2.31f, 0.89f, -2.54f, 1.39f, R_CUBIC_TO, 0.23f, 0.5f, 1.08f, 0.96f, 2.54f, 1.38f,
    R_CUBIC_TO, 1.46f, 0.42f, 2.94f, 0.63f, 4.46f, 0.63f, CLOSE, MOVE_TO, 12, 14, R_CUBIC_TO, 0.7f, 0, 1.38f, -0.04f, 2.02f, -0.1f, R_CUBIC_TO, 0.65f, -0.07f,
    1.27f, -0.16f, 1.86f, -0.28f, R_ARC_TO, 13.4f, 13.4f, 0, 0, 0, 1.68f, -0.46f, ARC_TO, 9.95f, 9.95f, 0, 0, 0, 19, 12.52f, R_V_LINE_TO, -3, R_ARC_TO, 9.95f,
    9.95f, 0, 0, 1, -1.44f, 0.63f, R_CUBIC_TO, -0.52f, 0.18f, -1.08f, 0.34f, -1.67f, 0.47f, R_CUBIC_TO, -0.59f, 0.13f, -1.21f, 0.22f, -1.86f, 0.28f, CUBIC_TO,
    13.38f, 10.97f, 12.7f, 11, 12, 11, R_CUBIC_TO, -0.7f, 0, -1.38f, -0.04f, -2.05f, -0.1f, R_ARC_TO, 17.58f, 17.58f, 0, 0, 1, -1.89f, -0.28f, R_ARC_TO, 13.21f,
    13.21f, 0, 0, 1, -1.66f, -0.46f, ARC_TO, 9.08f, 9.08f, 0, 0, 1, 5, 9.52f, R_V_LINE_TO, 3, R_CUBIC_TO, 0.42f, 0.24f, 0.88f, 0.44f, 1.4f, 0.63f, R_CUBIC_TO,
    0.52f, 0.18f, 1.08f, 0.34f, 1.67f, 0.47f, R_CUBIC_TO, 0.59f, 0.13f, 1.22f, 0.22f, 1.89f, 0.28f, R_CUBIC_TO, 0.67f, 0.07f, 1.35f, 0.1f, 2.05f, 0.1f, CLOSE,
    R_MOVE_TO, 0, 5, R_CUBIC_TO, 0.77f, 0, 1.55f, -0.06f, 2.34f, -0.18f, R_CUBIC_TO, 0.79f, -0.12f, 1.52f, -0.27f, 2.19f, -0.46f, R_CUBIC_TO, 0.67f, -0.19f,
    1.23f, -0.41f, 1.68f, -0.65f, R_CUBIC_TO, 0.45f, -0.24f, 0.72f, -0.48f, 0.8f, -0.73f, R_V_LINE_TO, -2.45f, R_ARC_TO, 9.95f, 9.95f, 0, 0, 1, -1.44f, 0.63f,
    R_CUBIC_TO, -0.52f, 0.18f, -1.08f, 0.34f, -1.67f, 0.47f, R_CUBIC_TO, -0.59f, 0.13f, -1.21f, 0.22f, -1.86f, 0.28f, CUBIC_TO, 13.38f, 15.97f, 12.7f, 16, 12,
    16, R_CUBIC_TO, -0.7f, 0, -1.38f, -0.04f, -2.05f, -0.1f, R_ARC_TO, 17.58f, 17.58f, 0, 0, 1, -1.89f, -0.28f, R_ARC_TO, 13.21f, 13.21f, 0, 0, 1, -1.66f,
    -0.46f, ARC_TO, 9.08f, 9.08f, 0, 0, 1, 5, 14.52f, V_LINE_TO, 17, R_CUBIC_TO, 0.08f, 0.25f, 0.35f, 0.49f, 0.79f, 0.73f, R_CUBIC_TO, 0.44f, 0.23f, 1, 0.45f,
    1.66f, 0.64f, R_CUBIC_TO, 0.67f, 0.19f, 1.4f, 0.34f, 2.2f, 0.46f, R_CUBIC_TO, 0.8f, 0.12f, 1.59f, 0.18f, 2.35f, 0.18f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kDatabaseRepList, kDatabaseIcon, { kDatabasePath, std::size(kDatabasePath) })
VECTOR_ICON_REP_TEMPLATE(kDatabaseOffPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 3.57f, 2.56f, LINE_TO, 2.15f, 3.98f, R_LINE_TO, 18.59f, 18.59f, R_LINE_TO, 1.41f,
    -1.41f, LINE_TO, 3.57f, 2.56f, CLOSE, NEW_PATH, MOVE_TO, 5.31f, 4.3f, CUBIC_TO, 4.27f, 4.96f, 3.75f, 5.71f, 3.75f, 6.56f, R_V_LINE_TO, 10, R_CUBIC_TO, 0,
    1.12f, 0.87f, 2.07f, 2.6f, 2.85f, R_CUBIC_TO, 1.75f, 0.77f, 3.88f, 1.15f, 6.4f, 1.15f, R_CUBIC_TO, 2.52f, 0, 4.64f, -0.38f, 6.38f, -1.15f, R_CUBIC_TO,
    0.32f, -0.14f, 0.6f, -0.29f, 0.86f, -0.44f, R_LINE_TO, -1.48f, -1.48f, R_CUBIC_TO, -0.36f, 0.16f, -0.77f, 0.3f, -1.23f, 0.44f, R_CUBIC_TO, -0.67f, 0.18f,
    -1.4f, 0.33f, -2.2f, 0.45f, R_ARC_TO, 15.76f, 15.76f, 0, 0, 1, -2.33f, 0.17f, R_CUBIC_TO, -0.77f, 0, -1.55f, -0.06f, -2.35f, -0.17f, R_CUBIC_TO, -0.8f,
    -0.12f, -1.53f, -0.27f, -2.2f, -0.45f, R_CUBIC_TO, -0.67f, -0.2f, -1.23f, -0.42f, -1.67f, -0.65f, R_CUBIC_TO, -0.43f, -0.23f, -0.69f, -0.47f, -0.77f,
    -0.72f, R_V_LINE_TO, -2.47f, R_CUBIC_TO, 0.42f, 0.23f, 0.88f, 0.44f, 1.4f, 0.63f, R_CUBIC_TO, 0.52f, 0.18f, 1.07f, 0.34f, 1.65f, 0.48f, R_ARC_TO, 20.81f,
    20.81f, 0, 0, 0, 3.95f, 0.37f, R_ARC_TO, 19.84f, 19.84f, 0, 0, 0, 3.52f, -0.31f, LINE_TO, 14.5f, 13.49f, R_CUBIC_TO, -0.56f, 0.05f, -1.15f, 0.07f, -1.75f,
    0.07f, R_ARC_TO, 20.81f, 20.81f, 0, 0, 1, -3.95f, -0.37f, R_ARC_TO, 14.79f, 14.79f, 0, 0, 1, -1.65f, -0.47f, R_ARC_TO, 9.07f, 9.07f, 0, 0, 1, -1.4f, -0.62f,
    R_V_LINE_TO, -3, R_CUBIC_TO, 0.42f, 0.23f, 0.88f, 0.44f, 1.4f, 0.63f, R_CUBIC_TO, 0.52f, 0.18f, 1.07f, 0.34f, 1.65f, 0.48f, R_ARC_TO, 20.81f, 20.81f, 0, 0,
    0, 2.74f, 0.34f, LINE_TO, 9.21f, 8.2f, R_ARC_TO, 16.62f, 16.62f, 0, 0, 1, -0.94f, -0.24f, R_CUBIC_TO, -1.45f, -0.42f, -2.29f, -0.87f, -2.52f, -1.37f,
    R_CUBIC_TO, 0.14f, -0.29f, 0.48f, -0.57f, 1.02f, -0.83f, LINE_TO, 5.31f, 4.3f, CLOSE, R_MOVE_TO, 3.57f, 0.75f, LINE_TO, 7.24f, 3.4f, R_CUBIC_TO, 1.58f,
    -0.56f, 3.42f, -0.83f, 5.51f, -0.83f, R_CUBIC_TO, 2.48f, 0, 4.6f, 0.39f, 6.35f, 1.17f, R_CUBIC_TO, 1.77f, 0.78f, 2.65f, 1.73f, 2.65f, 2.83f, R_V_LINE_TO,
    10, R_CUBIC_TO, 0, 0.37f, -0.1f, 0.72f, -0.29f, 1.06f, R_LINE_TO, -1.71f, -1.71f, R_V_LINE_TO, -1.82f, R_ARC_TO, 9.49f, 9.49f, 0, 0, 1, -1.26f, 0.56f,
    R_LINE_TO, -1.53f, -1.54f, R_CUBIC_TO, 0.48f, -0.12f, 0.93f, -0.25f, 1.35f, -0.4f, R_ARC_TO, 9.73f, 9.73f, 0, 0, 0, 1.45f, -0.62f, R_V_LINE_TO, -3,
    R_ARC_TO, 9.73f, 9.73f, 0, 0, 1, -1.45f, 0.63f, R_CUBIC_TO, -0.52f, 0.18f, -1.07f, 0.34f, -1.67f, 0.48f, R_ARC_TO, 19.68f, 19.68f, 0, 0, 1, -2.28f, 0.31f,
    R_LINE_TO, -1.92f, -1.92f, R_CUBIC_TO, 0.11f, 0, 0.22f, 0, 0.33f, 0, R_CUBIC_TO, 1.48f, 0, 2.98f, -0.21f, 4.47f, -0.62f, R_CUBIC_TO, 1.5f, -0.43f, 2.34f,
    -0.89f, 2.53f, -1.37f, R_CUBIC_TO, -0.18f, -0.48f, -1.02f, -0.94f, -2.52f, -1.37f, R_ARC_TO, 15.89f, 15.89f, 0, 0, 0, -4.47f, -0.65f, R_CUBIC_TO, -1.31f, 0,
    -2.59f, 0.16f, -3.86f, 0.48f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kDatabaseOffRepList, kDatabaseOffIcon, { kDatabaseOffPath, std::size(kDatabaseOffPath) })
VECTOR_ICON_REP_TEMPLATE(kDescriptionPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 8, 16, R_H_LINE_TO, 8, R_V_LINE_TO, 2, H_LINE_TO, 8, R_V_LINE_TO, -2, CLOSE,
    R_MOVE_TO, 0, -4, R_H_LINE_TO, 8, R_V_LINE_TO, 2, H_LINE_TO, 8, R_V_LINE_TO, -2, CLOSE, R_MOVE_TO, 6, -10, H_LINE_TO, 6, R_CUBIC_TO, -1.1f, 0, -2, 0.9f, -2,
    2, R_V_LINE_TO, 16, R_CUBIC_TO, 0, 1.1f, 0.89f, 2, 1.99f, 2, H_LINE_TO, 18, R_CUBIC_TO, 1.1f, 0, 2, -0.9f, 2, -2, V_LINE_TO, 8, R_LINE_TO, -6, -6, CLOSE,
    R_MOVE_TO, 4, 18, H_LINE_TO, 6, V_LINE_TO, 4, R_H_LINE_TO, 7, R_V_LINE_TO, 5, R_H_LINE_TO, 5, R_V_LINE_TO, 11, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kDescriptionRepList, kDescriptionIcon, { kDescriptionPath, std::size(kDescriptionPath) })
VECTOR_ICON_REP_TEMPLATE(kDevicesPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 1.91f, 20.27f, V_LINE_TO, 17, R_H_LINE_TO, 2, V_LINE_TO, 6, R_CUBIC_TO, 0, -0.63f, 0.22f,
    -1.17f, 0.66f, -1.61f, R_CUBIC_TO, 0.45f, -0.44f, 0.98f, -0.66f, 1.61f, -0.66f, H_LINE_TO, 21, V_LINE_TO, 6, H_LINE_TO, 6.18f, R_V_LINE_TO, 11, R_H_LINE_TO,
    5.73f, R_V_LINE_TO, 3.27f, CLOSE, R_MOVE_TO, 12.95f, 0, R_CUBIC_TO, -0.3f, 0, -0.55f, -0.1f, -0.75f, -0.3f, R_CUBIC_TO, -0.2f, -0.2f, -0.3f, -0.45f, -0.3f,
    -0.75f, V_LINE_TO, 8.95f, R_CUBIC_TO, 0, -0.3f, 0.1f, -0.54f, 0.3f, -0.74f, R_CUBIC_TO, 0.2f, -0.2f, 0.45f, -0.3f, 0.75f, -0.3f, R_H_LINE_TO, 6.18f,
    R_CUBIC_TO, 0.3f, 0, 0.54f, 0.1f, 0.74f, 0.3f, R_CUBIC_TO, 0.2f, 0.2f, 0.3f, 0.45f, 0.3f, 0.74f, R_V_LINE_TO, 10.27f, R_CUBIC_TO, 0, 0.3f, -0.1f, 0.55f,
    -0.3f, 0.75f, R_CUBIC_TO, -0.2f, 0.2f, -0.44f, 0.3f, -0.74f, 0.3f, CLOSE, MOVE_TO, 15.91f, 17, H_LINE_TO, 20, R_V_LINE_TO, -7, R_H_LINE_TO, -4.09f, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kDevices20Path, CANVAS_DIMENSIONS, 20, MOVE_TO, 1.93f, 16.23f, V_LINE_TO, 14, R_H_LINE_TO, 2, V_LINE_TO, 5.5f, R_CUBIC_TO, 0, -0.48f,
    0.17f, -0.89f, 0.5f, -1.22f, R_CUBIC_TO, 0.34f, -0.34f, 0.75f, -0.51f, 1.23f, -0.51f, H_LINE_TO, 17, V_LINE_TO, 5.5f, H_LINE_TO, 5.66f, V_LINE_TO, 14,
    R_H_LINE_TO, 4.27f, R_V_LINE_TO, 2.23f, CLOSE, R_MOVE_TO, 10.96f, 0, R_CUBIC_TO, -0.3f, 0, -0.54f, -0.1f, -0.74f, -0.3f, R_CUBIC_TO, -0.2f, -0.2f, -0.3f,
    -0.45f, -0.3f, -0.74f, V_LINE_TO, 7.96f, R_CUBIC_TO, 0, -0.29f, 0.1f, -0.54f, 0.3f, -0.74f, R_CUBIC_TO, 0.2f, -0.2f, 0.45f, -0.3f, 0.74f, -0.3f,
    R_H_LINE_TO, 4.15f, R_CUBIC_TO, 0.29f, 0, 0.54f, 0.1f, 0.74f, 0.3f, R_CUBIC_TO, 0.2f, 0.2f, 0.3f, 0.45f, 0.3f, 0.74f, R_V_LINE_TO, 7.23f, R_CUBIC_TO, 0,
    0.3f, -0.1f, 0.54f, -0.3f, 0.74f, R_CUBIC_TO, -0.2f, 0.2f, -0.44f, 0.3f, -0.74f, 0.3f, CLOSE, R_MOVE_TO, 0.54f, -2.23f, H_LINE_TO, 16.5f, V_LINE_TO, 8.5f,
    R_H_LINE_TO, -3.07f, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kDevices16Path, CANVAS_DIMENSIONS, 16, MOVE_TO, 1.46f, 13.23f, V_LINE_TO, 11.2f, R_H_LINE_TO, 1.6f, V_LINE_TO, 4.4f, R_CUBIC_TO, 0,
    -0.45f, 0.16f, -0.84f, 0.48f, -1.16f, R_ARC_TO, 1.58f, 1.58f, 0, 0, 1, 1.16f, -0.48f, R_H_LINE_TO, 8.91f, R_V_LINE_TO, 1.63f, R_H_LINE_TO, -8.91f,
    V_LINE_TO, 11.2f, H_LINE_TO, 7.86f, R_V_LINE_TO, 2.04f, CLOSE, R_MOVE_TO, 8.73f, 0, R_ARC_TO, 0.85f, 0.85f, 0, 0, 1, -0.62f, -0.25f, R_ARC_TO, 0.84f, 0.84f,
    0, 0, 1, -0.25f, -0.62f, V_LINE_TO, 6.32f, R_CUBIC_TO, 0, -0.25f, 0.08f, -0.45f, 0.25f, -0.62f, R_ARC_TO, 0.86f, 0.86f, 0, 0, 1, 0.63f, -0.25f, R_H_LINE_TO,
    3.49f, R_CUBIC_TO, 0.25f, 0, 0.45f, 0.09f, 0.62f, 0.25f, R_CUBIC_TO, 0.16f, 0.17f, 0.25f, 0.37f, 0.25f, 0.62f, R_V_LINE_TO, 6.04f, R_ARC_TO, 0.86f, 0.86f,
    0, 0, 1, -0.25f, 0.62f, R_ARC_TO, 0.84f, 0.84f, 0, 0, 1, -0.62f, 0.25f, CLOSE, R_MOVE_TO, 0.48f, -2.03f, R_H_LINE_TO, 2.54f, V_LINE_TO, 6.8f, R_H_LINE_TO,
    -2.54f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kDevicesRepList, kDevicesIcon, { kDevicesPath, std::size(kDevicesPath) }, { kDevices20Path, std::size(kDevices20Path) },
    { kDevices16Path, std::size(kDevices16Path) })
VECTOR_ICON_REP_TEMPLATE(kDevicesOffPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 7.63f, 5.5f, LINE_TO, 6.13f, 4, H_LINE_TO, 17, R_V_LINE_TO, 1.5f,
    CLOSE, MOVE_TO, 18, 15.5f, LINE_TO, 16.5f, 14, V_LINE_TO, 8.5f, R_H_LINE_TO, -3, R_V_LINE_TO, 2.88f, R_LINE_TO, -1.5f, -1.5f, V_LINE_TO, 7.75f, R_CUBIC_TO,
    0, -0.21f, 0.07f, -0.39f, 0.22f, -0.53f, ARC_TO, 0.72f, 0.72f, 0, 0, 1, 12.75f, 7, R_H_LINE_TO, 4.49f, R_ARC_TO, 0.73f, 0.73f, 0, 0, 1, 0.54f, 0.22f,
    R_ARC_TO, 0.73f, 0.73f, 0, 0, 1, 0.22f, 0.54f, CLOSE, R_MOVE_TO, -2, 2.63f, LINE_TO, 13.88f, 16, H_LINE_TO, 12.75f, R_CUBIC_TO, -0.21f, 0, -0.39f, -0.07f,
    -0.53f, -0.21f, ARC_TO, 0.73f, 0.73f, 0, 0, 1, 12, 15.25f, R_V_LINE_TO, -1.12f, R_LINE_TO, -6.5f, -6.5f, V_LINE_TO, 14, H_LINE_TO, 10, R_V_LINE_TO, 2,
    H_LINE_TO, 2, R_V_LINE_TO, -2, R_H_LINE_TO, 2, V_LINE_TO, 6.13f, LINE_TO, 1.88f, 4, R_LINE_TO, 1.06f, -1.06f, R_LINE_TO, 14.12f, 14.13f, CLOSE, R_MOVE_TO,
    -1, -5.44f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kDevicesOffRepList, kDevicesOffIcon, { kDevicesOffPath, std::size(kDevicesOffPath) })
VECTOR_ICON_REP_TEMPLATE(kDocumentScannerPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 4.67f, 2, H_LINE_TO, 2.67f, V_LINE_TO, 4, H_LINE_TO, 1.33f, V_LINE_TO, 0.67f,
    H_LINE_TO, 4.67f, V_LINE_TO, 2, CLOSE, MOVE_TO, 14.67f, 4, V_LINE_TO, 0.67f, H_LINE_TO, 11.33f, V_LINE_TO, 2, H_LINE_TO, 13.33f, V_LINE_TO, 4, H_LINE_TO,
    14.67f, CLOSE, MOVE_TO, 4.67f, 14, H_LINE_TO, 2.67f, V_LINE_TO, 12, H_LINE_TO, 1.33f, V_LINE_TO, 15.33f, H_LINE_TO, 4.67f, V_LINE_TO, 14, CLOSE, MOVE_TO,
    13.33f, 12, V_LINE_TO, 14, H_LINE_TO, 11.33f, V_LINE_TO, 15.33f, H_LINE_TO, 14.67f, V_LINE_TO, 12, H_LINE_TO, 13.33f, CLOSE, MOVE_TO, 11.33f, 4, H_LINE_TO,
    4.67f, V_LINE_TO, 12, H_LINE_TO, 11.33f, V_LINE_TO, 4, CLOSE, MOVE_TO, 12.67f, 12, CUBIC_TO, 12.67f, 12.73f, 12.07f, 13.33f, 11.33f, 13.33f, H_LINE_TO,
    4.67f, CUBIC_TO, 3.93f, 13.33f, 3.33f, 12.73f, 3.33f, 12, V_LINE_TO, 4, CUBIC_TO, 3.33f, 3.27f, 3.93f, 2.67f, 4.67f, 2.67f, H_LINE_TO, 11.33f, CUBIC_TO,
    12.07f, 2.67f, 12.67f, 3.27f, 12.67f, 4, V_LINE_TO, 12, CLOSE, MOVE_TO, 10, 5.33f, H_LINE_TO, 6, V_LINE_TO, 6.67f, H_LINE_TO, 10, V_LINE_TO, 5.33f, CLOSE,
    MOVE_TO, 10, 7.33f, H_LINE_TO, 6, V_LINE_TO, 8.67f, H_LINE_TO, 10, V_LINE_TO, 7.33f, CLOSE, MOVE_TO, 10, 9.33f, H_LINE_TO, 6, V_LINE_TO, 10.67f, H_LINE_TO,
    10, V_LINE_TO, 9.33f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kDocumentScannerRepList, kDocumentScannerIcon, { kDocumentScannerPath, std::size(kDocumentScannerPath) })
VECTOR_ICON_REP_TEMPLATE(kDogfoodPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 9.75f, 9.25f, CUBIC_TO, 10.72f, 9.25f, 11.5f, 8.47f, 11.5f, 7.5f, CUBIC_TO, 11.5f, 6.53f,
    10.72f, 5.75f, 9.75f, 5.75f, CUBIC_TO, 8.78f, 5.75f, 8, 6.53f, 8, 7.5f, CUBIC_TO, 8, 8.47f, 8.78f, 9.25f, 9.75f, 9.25f, CLOSE, MOVE_TO, 6.88f, 12.25f,
    CUBIC_TO, 7.85f, 12.25f, 8.63f, 11.47f, 8.63f, 10.5f, CUBIC_TO, 8.63f, 9.53f, 7.85f, 8.75f, 6.88f, 8.75f, CUBIC_TO, 5.91f, 8.75f, 5.13f, 9.53f, 5.13f,
    10.5f, CUBIC_TO, 5.13f, 11.47f, 5.91f, 12.25f, 6.88f, 12.25f, CLOSE, MOVE_TO, 15.75f, 7.5f, CUBIC_TO, 15.75f, 8.47f, 14.97f, 9.25f, 14, 9.25f, CUBIC_TO,
    13.03f, 9.25f, 12.25f, 8.47f, 12.25f, 7.5f, CUBIC_TO, 12.25f, 6.53f, 13.03f, 5.75f, 14, 5.75f, CUBIC_TO, 14.97f, 5.75f, 15.75f, 6.53f, 15.75f, 7.5f, CLOSE,
    MOVE_TO, 17.12f, 12.25f, CUBIC_TO, 18.09f, 12.25f, 18.87f, 11.47f, 18.87f, 10.5f, CUBIC_TO, 18.87f, 9.53f, 18.09f, 8.75f, 17.12f, 8.75f, CUBIC_TO, 16.15f,
    8.75f, 15.37f, 9.53f, 15.37f, 10.5f, CUBIC_TO, 15.37f, 11.47f, 16.15f, 12.25f, 17.12f, 12.25f, CLOSE, MOVE_TO, 12.63f, 10.36f, CUBIC_TO, 13.17f, 10.54f,
    13.54f, 10.9f, 13.89f, 11.3f, CUBIC_TO, 14.07f, 11.51f, 14.24f, 11.72f, 14.42f, 11.93f, CUBIC_TO, 14.79f, 12.38f, 15.16f, 12.83f, 15.58f, 13.25f, CUBIC_TO,
    15.67f, 13.34f, 15.76f, 13.43f, 15.85f, 13.52f, CUBIC_TO, 16.7f, 14.38f, 17.59f, 15.27f, 17.34f, 16.54f, CUBIC_TO, 17.18f, 17.34f, 16.65f, 17.96f, 15.81f,
    18.22f, CUBIC_TO, 15.58f, 18.29f, 15.05f, 18.22f, 14.35f, 18.13f, CUBIC_TO, 13.62f, 18.04f, 12.72f, 17.92f, 11.81f, 17.92f, CUBIC_TO, 10.88f, 17.92f, 10,
    18.04f, 9.31f, 18.13f, CUBIC_TO, 8.68f, 18.22f, 8.19f, 18.29f, 7.97f, 18.22f, CUBIC_TO, 7.13f, 17.96f, 6.59f, 17.34f, 6.43f, 16.54f, CUBIC_TO, 6.18f,
    15.26f, 7.07f, 14.37f, 7.92f, 13.51f, CUBIC_TO, 8.01f, 13.42f, 8.09f, 13.34f, 8.18f, 13.25f, CUBIC_TO, 8.56f, 12.86f, 8.91f, 12.44f, 9.25f, 12.01f,
    CUBIC_TO, 9.45f, 11.77f, 9.64f, 11.53f, 9.84f, 11.3f, CUBIC_TO, 10.19f, 10.9f, 10.52f, 10.54f, 11.06f, 10.36f, CUBIC_TO, 11.3f, 10.29f, 11.55f, 10.25f,
    11.8f, 10.25f, CUBIC_TO, 11.8f, 10.25f, 12.39f, 10.28f, 12.63f, 10.36f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kDogfoodRepList, kDogfoodIcon, { kDogfoodPath, std::size(kDogfoodPath) })
VECTOR_ICON_REP_TEMPLATE(kEditPath, CANVAS_DIMENSIONS, 48, MOVE_TO, 6, 34.51f, LINE_TO, 6, 42.01f, LINE_TO, 13.5f, 42.01f, LINE_TO, 35.62f, 19.89f, LINE_TO,
    28.12f, 12.39f, LINE_TO, 6, 34.51f, CLOSE, MOVE_TO, 41.42f, 14.09f, CUBIC_TO, 42.2f, 13.31f, 42.2f, 12.05f, 41.42f, 11.27f, LINE_TO, 36.74f, 6.59f,
    CUBIC_TO, 35.96f, 5.81f, 34.7f, 5.81f, 33.92f, 6.59f, LINE_TO, 30.26f, 10.25f, LINE_TO, 37.76f, 17.75f, LINE_TO, 41.42f, 14.09f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kEditRepList, kEditIcon, { kEditPath, std::size(kEditPath) })
VECTOR_ICON_REP_TEMPLATE(kEditChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 4.5f, 15.5f, R_H_LINE_TO, 1.06f, R_LINE_TO, 7.81f, -7.81f,
    R_LINE_TO, -1.06f, -1.06f, LINE_TO, 4.5f, 14.44f, CLOSE, MOVE_TO, 3, 17, R_V_LINE_TO, -3.19f, LINE_TO, 13.38f, 3.44f, R_CUBIC_TO, 0.15f, -0.15f, 0.32f,
    -0.27f, 0.5f, -0.33f, R_ARC_TO, 1.55f, 1.55f, 0, 0, 1, 1.13f, 0, R_CUBIC_TO, 0.18f, 0.07f, 0.35f, 0.18f, 0.5f, 0.33f, LINE_TO, 16.56f, 4.5f, R_ARC_TO, 1.4f,
    1.4f, 0, 0, 1, 0.33f, 0.5f, R_ARC_TO, 1.56f, 1.56f, 0, 0, 1, 0, 1.13f, R_CUBIC_TO, -0.07f, 0.18f, -0.18f, 0.35f, -0.33f, 0.5f, LINE_TO, 6.19f, 17, CLOSE,
    MOVE_TO, 15.5f, 5.56f, LINE_TO, 14.44f, 4.5f, CLOSE, R_MOVE_TO, -2.66f, 1.6f, R_LINE_TO, -0.52f, -0.54f, R_LINE_TO, 1.06f, 1.06f, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kEditChromeRefresh16Path, CANVAS_DIMENSIONS, 16, FILL_RULE_NONZERO, MOVE_TO, 3.65f, 12.35f, R_H_LINE_TO, 0.85f, R_LINE_TO, 5.98f,
    -5.98f, R_LINE_TO, -0.85f, -0.85f, R_LINE_TO, -5.98f, 5.99f, CLOSE, R_MOVE_TO, -1.38f, 1.38f, V_LINE_TO, 10.93f, R_LINE_TO, 8.29f, -8.3f, R_CUBIC_TO, 0.13f,
    -0.13f, 0.27f, -0.22f, 0.42f, -0.28f, R_CUBIC_TO, 0.15f, -0.06f, 0.31f, -0.09f, 0.48f, -0.09f, R_CUBIC_TO, 0.16f, 0, 0.32f, 0.03f, 0.47f, 0.09f, R_CUBIC_TO,
    0.15f, 0.06f, 0.29f, 0.15f, 0.43f, 0.28f, LINE_TO, 13.37f, 3.64f, R_CUBIC_TO, 0.13f, 0.13f, 0.22f, 0.27f, 0.28f, 0.43f, R_CUBIC_TO, 0.06f, 0.15f, 0.09f,
    0.31f, 0.09f, 0.47f, R_ARC_TO, 1.25f, 1.25f, 0, 0, 1, -0.37f, 0.91f, R_LINE_TO, -8.29f, 8.29f, CLOSE, R_MOVE_TO, 10.05f, -9.19f, R_LINE_TO, -0.85f, -0.86f,
    CLOSE, R_MOVE_TO, -2.26f, 1.41f, R_LINE_TO, -0.42f, -0.43f, R_LINE_TO, 0.85f, 0.85f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kEditChromeRefreshRepList, kEditChromeRefreshIcon, { kEditChromeRefreshPath, std::size(kEditChromeRefreshPath) },
    { kEditChromeRefresh16Path, std::size(kEditChromeRefresh16Path) })
VECTOR_ICON_REP_TEMPLATE(kEmailPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 20, 4, H_LINE_TO, 4, R_CUBIC_TO, -1.1f, 0, -1.99f, 0.9f, -1.99f, 2, LINE_TO, 2, 18,
    R_CUBIC_TO, 0, 1.1f, 0.9f, 2, 2, 2, R_H_LINE_TO, 16, R_CUBIC_TO, 1.1f, 0, 2, -0.9f, 2, -2, V_LINE_TO, 6, R_CUBIC_TO, 0, -1.1f, -0.9f, -2, -2, -2, CLOSE,
    R_MOVE_TO, 0, 4, R_LINE_TO, -8, 5, R_LINE_TO, -8, -5, V_LINE_TO, 6, R_LINE_TO, 8, 5, R_LINE_TO, 8, -5, R_V_LINE_TO, 2, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kEmailRepList, kEmailIcon, { kEmailPath, std::size(kEmailPath) })
VECTOR_ICON_REP_TEMPLATE(kEmailOutlinePath, CANVAS_DIMENSIONS, 24, MOVE_TO, 20, 4, H_LINE_TO, 4, R_CUBIC_TO, -1.1f, 0, -2, 0.9f, -2, 2, R_V_LINE_TO, 12,
    R_CUBIC_TO, 0, 1.1f, 0.9f, 2, 2, 2, R_H_LINE_TO, 16, R_CUBIC_TO, 1.1f, 0, 2, -0.9f, 2, -2, V_LINE_TO, 6, R_CUBIC_TO, 0, -1.1f, -0.9f, -2, -2, -2, CLOSE,
    R_MOVE_TO, -0.8f, 2, LINE_TO, 12, 10.8f, LINE_TO, 4.8f, 6, R_H_LINE_TO, 14.4f, CLOSE, MOVE_TO, 4, 18, V_LINE_TO, 7.87f, R_LINE_TO, 8, 5.33f, R_LINE_TO, 8,
    -5.33f, V_LINE_TO, 18, H_LINE_TO, 4, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kEmailOutlineRepList, kEmailOutlineIcon, { kEmailOutlinePath, std::size(kEmailOutlinePath) })
VECTOR_ICON_REP_TEMPLATE(kErrorPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 8, 0.91f, CUBIC_TO, 4.07f, 0.91f, 0.89f, 4.1f, 0.89f, 8.03f, CUBIC_TO, 0.89f, 11.96f,
    4.07f, 15.14f, 8, 15.14f, CUBIC_TO, 11.93f, 15.14f, 15.11f, 11.96f, 15.11f, 8.03f, CUBIC_TO, 15.11f, 4.1f, 11.93f, 0.91f, 8, 0.91f, CLOSE, MOVE_TO, 8.89f,
    11.55f, LINE_TO, 7.11f, 11.55f, LINE_TO, 7.11f, 9.78f, LINE_TO, 8.89f, 9.78f, CLOSE, MOVE_TO, 8.89f, 8.89f, LINE_TO, 7.11f, 8.89f, LINE_TO, 7.11f, 4.45f,
    LINE_TO, 8.89f, 4.45f, CLOSE, MOVE_TO, 8.89f, 8.89f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kErrorRepList, kErrorIcon, { kErrorPath, std::size(kErrorPath) })
VECTOR_ICON_REP_TEMPLATE(kErrorOutlinePath, CANVAS_DIMENSIONS, 24, MOVE_TO, 11, 15, R_H_LINE_TO, 2, R_V_LINE_TO, 2, R_H_LINE_TO, -2, R_V_LINE_TO, -2, CLOSE,
    R_MOVE_TO, 0, -8, R_H_LINE_TO, 2, R_V_LINE_TO, 6, R_H_LINE_TO, -2, V_LINE_TO, 7, CLOSE, R_MOVE_TO, 0.99f, -5, CUBIC_TO, 6.47f, 2, 2, 6.48f, 2, 12,
    R_CUBIC_TO, 0, 5.52f, 4.47f, 10, 9.99f, 10, CUBIC_TO, 17.52f, 22, 22, 17.52f, 22, 12, CUBIC_TO_SHORTHAND, 17.52f, 2, 11.99f, 2, CLOSE, MOVE_TO, 12, 20,
    R_CUBIC_TO, -4.42f, 0, -8, -3.58f, -8, -8, R_CUBIC_TO, 0, -4.42f, 3.58f, -8, 8, -8, R_CUBIC_TO, 4.42f, 0, 8, 3.58f, 8, 8, R_CUBIC_TO, 0, 4.42f, -3.58f, 8,
    -8, 8, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kErrorOutlineRepList, kErrorOutlineIcon, { kErrorOutlinePath, std::size(kErrorOutlinePath) })
VECTOR_ICON_REP_TEMPLATE(kEthernetPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 17, 6, R_LINE_TO, -1.41f, 1.41f, LINE_TO, 20.17f, 12, R_LINE_TO, -4.58f, 4.59f, LINE_TO,
    17, 18, R_LINE_TO, 6, -6, R_LINE_TO, -6, -6, CLOSE, MOVE_TO, 8.41f, 7.41f, LINE_TO, 7, 6, R_LINE_TO, -6, 6, R_LINE_TO, 6, 6, R_LINE_TO, 1.41f, -1.41f,
    LINE_TO, 3.83f, 12, R_LINE_TO, 4.58f, -4.59f, CLOSE, MOVE_TO, 8, 13, R_CUBIC_TO, 0.55f, 0, 1, -0.45f, 1, -1, R_CUBIC_TO, 0, -0.55f, -0.45f, -1, -1, -1,
    R_CUBIC_TO, -0.55f, 0, -1, 0.45f, -1, 1, R_CUBIC_TO, 0, 0.55f, 0.45f, 1, 1, 1, CLOSE, R_MOVE_TO, 4, 0, R_CUBIC_TO, 0.55f, 0, 1, -0.45f, 1, -1, R_CUBIC_TO,
    0, -0.55f, -0.45f, -1, -1, -1, R_CUBIC_TO, -0.55f, 0, -1, 0.45f, -1, 1, R_CUBIC_TO, 0, 0.55f, 0.45f, 1, 1, 1, CLOSE, R_MOVE_TO, 4, 0, R_CUBIC_TO, 0.55f, 0,
    1, -0.45f, 1, -1, R_CUBIC_TO, 0, -0.55f, -0.45f, -1, -1, -1, R_CUBIC_TO, -0.55f, 0, -1, 0.45f, -1, 1, R_CUBIC_TO, 0, 0.55f, 0.45f, 1, 1, 1, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kEthernetRepList, kEthernetIcon, { kEthernetPath, std::size(kEthernetPath) })
VECTOR_ICON_REP_TEMPLATE(kExpandMorePath, CANVAS_DIMENSIONS, 16, R_MOVE_TO, 8, 10.74f, R_LINE_TO, -4.3f, -4.3f, R_LINE_TO, 1.15f, -1.15f, LINE_TO, 8, 8.44f,
    R_LINE_TO, 3.15f, -3.15f, R_LINE_TO, 1.15f, 1.15f, CLOSE, R_MOVE_TO, 0, 0, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kExpandMoreRepList, kExpandMoreIcon, { kExpandMorePath, std::size(kExpandMorePath) })
VECTOR_ICON_REP_TEMPLATE(kExtensionPath, MOVE_TO, 41, 22, R_H_LINE_TO, -3, R_V_LINE_TO, -8, R_CUBIC_TO, 0, -2.21f, -1.79f, -4, -4, -4, R_H_LINE_TO, -8,
    V_LINE_TO, 7, R_CUBIC_TO, 0, -2.76f, -2.24f, -5, -5, -5, R_CUBIC_TO, -2.76f, 0, -5, 2.24f, -5, 5, R_V_LINE_TO, 3, H_LINE_TO, 8, R_CUBIC_TO, -2.21f, 0,
    -3.98f, 1.79f, -3.98f, 4, R_LINE_TO, -0.01f, 7.6f, H_LINE_TO, 7, R_CUBIC_TO, 2.98f, 0, 5.4f, 2.42f, 5.4f, 5.4f, R_CUBIC_TO, 0, 2.98f, -2.42f, 5.4f, -5.4f,
    5.4f, H_LINE_TO, 4.01f, LINE_TO, 4, 40, R_CUBIC_TO, 0, 2.21f, 1.79f, 4, 4, 4, R_H_LINE_TO, 7.6f, R_V_LINE_TO, -3, R_CUBIC_TO, 0, -2.98f, 2.42f, -5.4f, 5.4f,
    -5.4f, R_CUBIC_TO, 2.98f, 0, 5.4f, 2.42f, 5.4f, 5.4f, R_V_LINE_TO, 3, H_LINE_TO, 34, R_CUBIC_TO, 2.21f, 0, 4, -1.79f, 4, -4, R_V_LINE_TO, -8, R_H_LINE_TO,
    3, R_CUBIC_TO, 2.76f, 0, 5, -2.24f, 5, -5, R_CUBIC_TO, 0, -2.76f, -2.24f, -5, -5, -5, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kExtensionRepList, kExtensionIcon, { kExtensionPath, std::size(kExtensionPath) })
VECTOR_ICON_REP_TEMPLATE(kExtensionChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 4.5f, 17, R_CUBIC_TO, -0.41f, 0, -0.77f, -0.15f,
    -1.06f, -0.44f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 3, 15.5f, V_LINE_TO, 12, R_ARC_TO, 2.12f, 2.12f, 0, 0, 0, 1.42f, -0.61f, ARC_TO, 1.88f, 1.88f, 0, 0, 0, 5,
    10, R_ARC_TO, 1.88f, 1.88f, 0, 0, 0, -0.58f, -1.39f, ARC_TO, 2.12f, 2.12f, 0, 0, 0, 3, 8, V_LINE_TO, 4.5f, R_CUBIC_TO, 0, -0.41f, 0.15f, -0.77f, 0.44f,
    -1.06f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 4.5f, 3, H_LINE_TO, 8, R_CUBIC_TO, 0, -0.56f, 0.19f, -1.03f, 0.58f, -1.42f, ARC_TO, 1.93f, 1.93f, 0, 0, 1, 10, 1,
    R_CUBIC_TO, 0.56f, 0, 1.03f, 0.19f, 1.42f, 0.58f, R_CUBIC_TO, 0.39f, 0.39f, 0.58f, 0.86f, 0.58f, 1.42f, R_H_LINE_TO, 3.5f, R_CUBIC_TO, 0.41f, 0, 0.77f,
    0.15f, 1.06f, 0.44f, R_CUBIC_TO, 0.29f, 0.29f, 0.44f, 0.65f, 0.44f, 1.06f, V_LINE_TO, 8, R_ARC_TO, 1.94f, 1.94f, 0, 0, 1, 1.42f, 0.58f, R_CUBIC_TO, 0.39f,
    0.39f, 0.58f, 0.86f, 0.58f, 1.42f, R_CUBIC_TO, 0, 0.56f, -0.19f, 1.03f, -0.58f, 1.42f, ARC_TO, 1.94f, 1.94f, 0, 0, 1, 17, 12, R_V_LINE_TO, 3.5f, R_CUBIC_TO,
    0, 0.41f, -0.15f, 0.77f, -0.44f, 1.06f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 15.5f, 17, CLOSE, R_MOVE_TO, 0, -1.5f, R_H_LINE_TO, 11, R_V_LINE_TO, -11,
    R_H_LINE_TO, -11, R_V_LINE_TO, 2.33f, R_ARC_TO, 3.23f, 3.23f, 0, 0, 1, 1.47f, 1.28f, CUBIC_TO, 6.32f, 8.69f, 6.5f, 9.32f, 6.5f, 10, R_CUBIC_TO, 0, 0.7f,
    -0.18f, 1.33f, -0.53f, 1.91f, ARC_TO, 3.12f, 3.12f, 0, 0, 1, 4.5f, 13.17f, CLOSE, MOVE_TO, 10, 10, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kExtensionChromeRefresh16Path, CANVAS_DIMENSIONS, 16, FILL_RULE_NONZERO, MOVE_TO, 3.6f, 13.73f, R_CUBIC_TO, -0.37f, 0, -0.69f, -0.13f,
    -0.95f, -0.39f, R_ARC_TO, 1.28f, 1.28f, 0, 0, 1, -0.39f, -0.95f, R_V_LINE_TO, -2.87f, R_CUBIC_TO, 0.42f, -0.02f, 0.77f, -0.18f, 1.05f, -0.47f, ARC_TO,
    1.46f, 1.46f, 0, 0, 0, 3.75f, 8, R_CUBIC_TO, 0, -0.41f, -0.14f, -0.76f, -0.43f, -1.05f, R_ARC_TO, 1.51f, 1.51f, 0, 0, 0, -1.05f, -0.47f, V_LINE_TO, 3.6f,
    R_CUBIC_TO, 0, -0.37f, 0.13f, -0.69f, 0.39f, -0.95f, R_CUBIC_TO, 0.26f, -0.26f, 0.57f, -0.39f, 0.95f, -0.39f, R_H_LINE_TO, 2.68f, R_CUBIC_TO, 0.03f, -0.46f,
    0.21f, -0.84f, 0.53f, -1.16f, R_ARC_TO, 1.63f, 1.63f, 0, 0, 1, 1.18f, -0.47f, R_CUBIC_TO, 0.46f, 0, 0.86f, 0.16f, 1.18f, 0.47f, R_CUBIC_TO, 0.33f, 0.31f,
    0.51f, 0.7f, 0.54f, 1.16f, R_H_LINE_TO, 2.68f, R_CUBIC_TO, 0.37f, 0, 0.69f, 0.13f, 0.95f, 0.39f, R_CUBIC_TO, 0.26f, 0.26f, 0.39f, 0.57f, 0.39f, 0.95f,
    R_V_LINE_TO, 2.68f, R_CUBIC_TO, 0.46f, 0.03f, 0.84f, 0.21f, 1.16f, 0.53f, R_CUBIC_TO, 0.32f, 0.33f, 0.47f, 0.72f, 0.47f, 1.18f, R_CUBIC_TO, 0, 0.46f,
    -0.16f, 0.86f, -0.47f, 1.18f, R_CUBIC_TO, -0.31f, 0.33f, -0.7f, 0.51f, -1.16f, 0.54f, R_V_LINE_TO, 2.68f, R_CUBIC_TO, 0, 0.37f, -0.13f, 0.69f, -0.39f,
    0.95f, R_CUBIC_TO, -0.26f, 0.26f, -0.57f, 0.39f, -0.95f, 0.39f, CLOSE, R_MOVE_TO, 0.05f, -1.38f, R_H_LINE_TO, 8.7f, V_LINE_TO, 3.65f, H_LINE_TO, 3.65f,
    R_V_LINE_TO, 1.81f, R_CUBIC_TO, 0.47f, 0.25f, 0.83f, 0.61f, 1.09f, 1.07f, R_CUBIC_TO, 0.26f, 0.46f, 0.39f, 0.95f, 0.39f, 1.48f, R_CUBIC_TO, 0, 0.54f,
    -0.13f, 1.05f, -0.39f, 1.5f, R_ARC_TO, 2.58f, 2.58f, 0, 0, 1, -1.09f, 1.04f, CLOSE, MOVE_TO, 8, 8, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kExtensionChromeRefreshRepList, kExtensionChromeRefreshIcon, { kExtensionChromeRefreshPath, std::size(kExtensionChromeRefreshPath) },
    { kExtensionChromeRefresh16Path, std::size(kExtensionChromeRefresh16Path) })
VECTOR_ICON_REP_TEMPLATE(kExtensionOffPath, CANVAS_DIMENSIONS, 20, MOVE_TO, 18.6f, 9.5f, R_CUBIC_TO, -0.4f, -0.4f, -0.9f, -0.6f, -1.5f, -0.7f, V_LINE_TO, 5.5f,
    R_CUBIC_TO, 0, -0.5f, -0.2f, -0.8f, -0.5f, -1.2f, CUBIC_TO_SHORTHAND, 16, 3.8f, 15.5f, 3.8f, R_H_LINE_TO, -3.4f, R_CUBIC_TO, 0, -0.6f, -0.3f, -1.1f, -0.7f,
    -1.5f, CUBIC_TO, 11, 2, 10.6f, 1.8f, 10, 1.8f, CUBIC_TO_SHORTHAND, 8.9f, 2, 8.5f, 2.4f, CUBIC_TO, 8.1f, 2.8f, 7.9f, 3.2f, 7.8f, 3.8f, H_LINE_TO, 5.1f,
    R_LINE_TO, 1.7f, 1.7f, R_H_LINE_TO, 8.6f, R_V_LINE_TO, 8.6f, R_LINE_TO, 1.7f, 1.7f, R_H_LINE_TO, 0, R_V_LINE_TO, -2.7f, R_CUBIC_TO, 0.6f, 0, 1.1f, -0.3f,
    1.5f, -0.7f, R_CUBIC_TO, 0.4f, -0.4f, 0.6f, -0.9f, 0.6f, -1.5f, CUBIC_TO_SHORTHAND, 19, 9.9f, 18.6f, 9.5f, CLOSE, NEW_PATH, MOVE_TO, 2.8f, 3.7f, LINE_TO,
    1.7f, 4.8f, LINE_TO, 2.8f, 6, R_V_LINE_TO, 3.1f, R_CUBIC_TO, 0.5f, 0, 1, 0.2f, 1.3f, 0.6f, CUBIC_TO, 4.5f, 10, 4.7f, 10.5f, 4.7f, 11, R_CUBIC_TO, 0, 0.5f,
    -0.2f, 1, -0.5f, 1.3f, R_CUBIC_TO, -0.4f, 0.4f, -0.8f, 0.6f, -1.3f, 0.6f, R_V_LINE_TO, 3.6f, R_CUBIC_TO, 0, 0.5f, 0.2f, 0.9f, 0.5f, 1.2f, CUBIC_TO, 3.6f,
    18, 4, 18.2f, 4.5f, 18.2f, H_LINE_TO, 15, R_LINE_TO, 1.2f, 1.2f, R_LINE_TO, 1.1f, -1.1f, LINE_TO, 2.8f, 3.7f, CLOSE, MOVE_TO, 4.6f, 16.4f, R_V_LINE_TO,
    -2.3f, R_CUBIC_TO, 0.6f, -0.3f, 1, -0.7f, 1.4f, -1.3f, R_CUBIC_TO, 0.3f, -0.6f, 0.5f, -1.2f, 0.5f, -1.9f, R_CUBIC_TO, 0, -0.7f, -0.2f, -1.3f, -0.5f, -1.8f,
    R_CUBIC_TO, 0, -0.1f, -0.1f, -0.2f, -0.1f, -0.2f, R_LINE_TO, 7.5f, 7.5f, H_LINE_TO, 4.6f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kExtensionOffRepList, kExtensionOffIcon, { kExtensionOffPath, std::size(kExtensionOffPath) })
VECTOR_ICON_REP_TEMPLATE(kExtensionOnPath, CANVAS_DIMENSIONS, 20, MOVE_TO, 19.2f, 11, R_CUBIC_TO, 0, 0.57f, -0.19f, 1.06f, -0.58f, 1.47f, R_CUBIC_TO, -0.39f,
    0.41f, -0.88f, 0.64f, -1.45f, 0.68f, R_V_LINE_TO, 3.35f, R_CUBIC_TO, 0, 0.46f, -0.16f, 0.85f, -0.49f, 1.18f, R_CUBIC_TO, -0.31f, 0.32f, -0.74f, 0.5f,
    -1.18f, 0.49f, H_LINE_TO, 5.53f, R_LINE_TO, 0.32f, -0.32f, R_LINE_TO, 1.41f, -1.41f, H_LINE_TO, 15.44f, V_LINE_TO, 5.56f, H_LINE_TO, 4.56f, R_V_LINE_TO,
    2.26f, R_CUBIC_TO, 0.57f, 0.31f, 1.05f, 0.77f, 1.37f, 1.33f, R_CUBIC_TO, 0.07f, 0.12f, 0.13f, 0.25f, 0.18f, 0.38f, R_LINE_TO, -0.6f, 0.59f, R_LINE_TO,
    -0.83f, 0.82f, R_CUBIC_TO, -0.01f, -0.49f, -0.19f, -0.9f, -0.53f, -1.26f, R_CUBIC_TO, -0.35f, -0.36f, -0.82f, -0.57f, -1.32f, -0.59f, R_V_LINE_TO, -3.59f,
    R_CUBIC_TO, 0, -0.46f, 0.16f, -0.86f, 0.49f, -1.18f, R_CUBIC_TO, 0.31f, -0.32f, 0.74f, -0.5f, 1.18f, -0.49f, R_H_LINE_TO, 3.36f, R_CUBIC_TO, 0.02f, -0.55f,
    0.26f, -1.07f, 0.66f, -1.44f, R_CUBIC_TO, 0.41f, -0.4f, 0.91f, -0.59f, 1.48f, -0.59f, R_CUBIC_TO, 0.57f, 0, 1.06f, 0.19f, 1.47f, 0.58f, R_CUBIC_TO, 0.41f,
    0.39f, 0.64f, 0.88f, 0.68f, 1.45f, R_H_LINE_TO, 3.35f, R_CUBIC_TO, 0.46f, 0, 0.85f, 0.16f, 1.18f, 0.49f, R_CUBIC_TO, 0.33f, 0.33f, 0.49f, 0.72f, 0.49f,
    1.18f, R_V_LINE_TO, 3.36f, R_CUBIC_TO, 0.55f, 0.02f, 1.07f, 0.26f, 1.44f, 0.66f, R_CUBIC_TO, 0.4f, 0.41f, 0.59f, 0.91f, 0.59f, 1.48f, CLOSE, R_MOVE_TO,
    -11.59f, -0.52f, R_LINE_TO, -3.83f, 3.81f, R_LINE_TO, -1.71f, -1.71f, R_LINE_TO, -1.18f, 1.2f, R_LINE_TO, 2.89f, 2.91f, R_LINE_TO, 5.03f, -5.04f, R_LINE_TO,
    -1.2f, -1.17f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kExtensionOnRepList, kExtensionOnIcon, { kExtensionOnPath, std::size(kExtensionOnPath) })
VECTOR_ICON_REP_TEMPLATE(kFamilyLinkPath, CANVAS_DIMENSIONS, 20, R_MOVE_TO, 4.63f, 8, R_LINE_TO, 5.69f, -6, LINE_TO, 16, 8, R_LINE_TO, -5.81f, 8.87f,
    R_CUBIC_TO, -0.08f, 0.12f, -0.18f, 0.24f, -0.28f, 0.35f, R_ARC_TO, 2.44f, 2.44f, 0, 0, 1, -1.78f, 0.78f, R_ARC_TO, 2.44f, 2.44f, 0, 0, 1, -1.78f, -0.78f,
    R_ARC_TO, 2.72f, 2.72f, 0, 0, 1, -0.74f, -1.88f, R_CUBIC_TO, 0, -0.36f, -0.13f, -0.69f, -0.37f, -0.94f, R_ARC_TO, 1.21f, 1.21f, 0, 0, 0, -0.89f, -0.39f,
    H_LINE_TO, 4, R_V_LINE_TO, -1.33f, R_H_LINE_TO, 0.33f, R_CUBIC_TO, 0.68f, 0, 1.31f, 0.28f, 1.78f, 0.78f, R_CUBIC_TO, 0.48f, 0.5f, 0.74f, 1.17f, 0.74f,
    1.88f, R_CUBIC_TO, 0, 0.36f, 0.13f, 0.69f, 0.37f, 0.95f, R_CUBIC_TO, 0.24f, 0.26f, 0.55f, 0.39f, 0.9f, 0.39f, R_CUBIC_TO, 0.34f, 0, 0.65f, -0.14f, 0.9f,
    -0.39f, R_LINE_TO, 0.04f, -0.04f, R_CUBIC_TO, 0.04f, -0.04f, 0.07f, -0.09f, 0.11f, -0.14f, R_LINE_TO, 0.4f, -0.6f, LINE_TO, 4.63f, 8, CLOSE, R_MOVE_TO,
    5.69f, 5.94f, LINE_TO, 6.54f, 8.17f, R_LINE_TO, 3.78f, -3.99f, R_LINE_TO, 3.78f, 3.99f, R_LINE_TO, -3.78f, 5.77f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kFamilyLinkRepList, kFamilyLinkIcon, { kFamilyLinkPath, std::size(kFamilyLinkPath) })
VECTOR_ICON_REP_TEMPLATE(kFileDownloadPath, MOVE_TO, 38, 18, R_H_LINE_TO, -8, V_LINE_TO, 6, H_LINE_TO, 18, R_V_LINE_TO, 12, R_H_LINE_TO, -8, R_LINE_TO, 14, 14,
    R_LINE_TO, 14, -14, CLOSE, MOVE_TO, 10, 36, R_V_LINE_TO, 4, R_H_LINE_TO, 28, R_V_LINE_TO, -4, H_LINE_TO, 10, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kFileDownloadRepList, kFileDownloadIcon, { kFileDownloadPath, std::size(kFileDownloadPath) })
VECTOR_ICON_REP_TEMPLATE(kFileDownloadChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 10, 13, LINE_TO, 6, 9, R_LINE_TO, 1.06f, -1.06f,
    R_LINE_TO, 2.19f, 2.19f, V_LINE_TO, 3, R_H_LINE_TO, 1.5f, R_V_LINE_TO, 7.13f, R_LINE_TO, 2.19f, -2.19f, LINE_TO, 14, 9, CLOSE, R_MOVE_TO, -4.51f, 3,
    R_ARC_TO, 1.44f, 1.44f, 0, 0, 1, -1.05f, -0.44f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 4, 14.5f, V_LINE_TO, 13, R_H_LINE_TO, 1.5f, R_V_LINE_TO, 1.5f, R_H_LINE_TO,
    9, V_LINE_TO, 13, H_LINE_TO, 16, R_V_LINE_TO, 1.5f, R_CUBIC_TO, 0, 0.41f, -0.15f, 0.77f, -0.44f, 1.06f, ARC_TO, 1.45f, 1.45f, 0, 0, 1, 14.5f, 16, CLOSE)
VECTOR_ICON_TEMPLATE_CC(
    kFileDownloadChromeRefreshRepList, kFileDownloadChromeRefreshIcon, { kFileDownloadChromeRefreshPath, std::size(kFileDownloadChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kFileDownloadOffChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 16, 18.13f, LINE_TO, 13.88f, 16, H_LINE_TO, 5.5f,
    R_CUBIC_TO, -0.41f, 0, -0.77f, -0.15f, -1.06f, -0.44f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 4, 14.5f, V_LINE_TO, 13, R_H_LINE_TO, 1.5f, R_V_LINE_TO, 1.5f,
    R_H_LINE_TO, 6.88f, R_LINE_TO, -1.94f, -1.94f, LINE_TO, 10, 13, LINE_TO, 6, 9, R_LINE_TO, 0.44f, -0.44f, LINE_TO, 1.88f, 4, R_LINE_TO, 1.06f, -1.06f,
    R_LINE_TO, 14.12f, 14.13f, CLOSE, R_MOVE_TO, -3.44f, -7.69f, LINE_TO, 11.5f, 9.38f, R_LINE_TO, 1.44f, -1.44f, LINE_TO, 14, 9, CLOSE, MOVE_TO, 10.75f, 8.63f,
    R_LINE_TO, -1.5f, -1.5f, V_LINE_TO, 3, R_H_LINE_TO, 1.5f, CLOSE, R_MOVE_TO, 5.25f, 5.25f, LINE_TO, 15.13f, 13, H_LINE_TO, 16, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kFileDownloadOffChromeRefreshRepList, kFileDownloadOffChromeRefreshIcon,
    { kFileDownloadOffChromeRefreshPath, std::size(kFileDownloadOffChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kFingerprintPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 10, 4, R_CUBIC_TO, 1.6f, 0, 3.07f, 0.34f, 4.42f, 1.02f,
    R_CUBIC_TO, 1.35f, 0.68f, 2.35f, 1.59f, 3.02f, 2.73f, R_CUBIC_TO, 0.07f, 0.11f, 0.08f, 0.23f, 0.04f, 0.38f, R_ARC_TO, 0.55f, 0.55f, 0, 0, 1, -0.23f, 0.31f,
    R_ARC_TO, 0.46f, 0.46f, 0, 0, 1, -0.37f, 0.04f, R_ARC_TO, 0.56f, 0.56f, 0, 0, 1, -0.29f, -0.23f, R_CUBIC_TO, -0.58f, -1, -1.47f, -1.79f, -2.66f, -2.37f,
    CUBIC_TO, 12.74f, 5.29f, 11.43f, 5, 10, 5, R_CUBIC_TO, -1.43f, 0, -2.74f, 0.29f, -3.93f, 0.88f, CUBIC_TO, 4.89f, 6.46f, 4, 7.25f, 3.42f, 8.25f, R_ARC_TO,
    0.48f, 0.48f, 0, 0, 1, -0.67f, 0.19f, R_ARC_TO, 0.55f, 0.55f, 0, 0, 1, -0.23f, -0.31f, R_ARC_TO, 0.44f, 0.44f, 0, 0, 1, 0.04f, -0.37f, R_CUBIC_TO, 0.67f,
    -1.14f, 1.67f, -2.05f, 3.02f, -2.73f, CUBIC_TO, 6.93f, 4.34f, 8.4f, 4, 10, 4, CLOSE, R_MOVE_TO, 0, 2, R_CUBIC_TO, 1.79f, 0, 3.32f, 0.63f, 4.58f, 1.9f,
    R_CUBIC_TO, 1.27f, 1.26f, 1.9f, 2.8f, 1.9f, 4.61f, R_CUBIC_TO, 0, 0.7f, -0.24f, 1.29f, -0.72f, 1.77f, R_CUBIC_TO, -0.48f, 0.49f, -1.07f, 0.73f, -1.76f,
    0.73f, R_ARC_TO, 2.4f, 2.4f, 0, 0, 1, -1.77f, -0.73f, R_ARC_TO, 2.4f, 2.4f, 0, 0, 1, -0.73f, -1.77f, R_CUBIC_TO, 0, -0.42f, -0.14f, -0.77f, -0.44f, -1.06f,
    ARC_TO, 1.42f, 1.42f, 0, 0, 0, 10.02f, 11, R_CUBIC_TO, -0.4f, 0, -0.75f, 0.14f, -1.05f, 0.44f, R_CUBIC_TO, -0.3f, 0.29f, -0.45f, 0.64f, -0.45f, 1.06f,
    R_CUBIC_TO, 0, 1.48f, 0.42f, 2.61f, 1.24f, 3.36f, CUBIC_TO, 10.59f, 16.62f, 11.5f, 17, 12.5f, 17, R_ARC_TO, 0.48f, 0.48f, 0, 0, 1, 0.36f, 0.14f, R_ARC_TO,
    0.48f, 0.48f, 0, 0, 1, 0.14f, 0.36f, R_ARC_TO, 0.48f, 0.48f, 0, 0, 1, -0.14f, 0.36f, R_ARC_TO, 0.48f, 0.48f, 0, 0, 1, -0.35f, 0.14f, R_CUBIC_TO, -1.22f, 0,
    -2.36f, -0.47f, -3.41f, -1.41f, R_CUBIC_TO, -1.05f, -0.94f, -1.57f, -2.3f, -1.57f, -4.09f, R_CUBIC_TO, 0, -0.69f, 0.24f, -1.28f, 0.72f, -1.77f, ARC_TO,
    2.37f, 2.37f, 0, 0, 1, 10, 10, R_CUBIC_TO, 0.7f, 0, 1.29f, 0.24f, 1.77f, 0.73f, R_CUBIC_TO, 0.49f, 0.49f, 0.73f, 1.08f, 0.73f, 1.77f, R_CUBIC_TO, 0, 0.42f,
    0.14f, 0.77f, 0.44f, 1.06f, R_CUBIC_TO, 0.29f, 0.29f, 0.64f, 0.44f, 1.04f, 0.44f, R_CUBIC_TO, 0.4f, 0, 0.75f, -0.14f, 1.05f, -0.44f, R_CUBIC_TO, 0.3f,
    -0.29f, 0.45f, -0.64f, 0.45f, -1.06f, R_CUBIC_TO, 0, -1.52f, -0.54f, -2.81f, -1.61f, -3.89f, CUBIC_TO, 12.81f, 7.54f, 11.52f, 7, 10, 7, R_CUBIC_TO, -1.52f,
    0, -2.8f, 0.54f, -3.87f, 1.61f, CUBIC_TO, 5.06f, 9.67f, 4.52f, 10.97f, 4.52f, 12.5f, R_CUBIC_TO, 0, 0.4f, 0.04f, 0.8f, 0.13f, 1.18f, R_CUBIC_TO, 0.09f,
    0.38f, 0.21f, 0.75f, 0.38f, 1.12f, R_CUBIC_TO, 0.07f, 0.13f, 0.08f, 0.25f, 0.03f, 0.38f, R_ARC_TO, 0.53f, 0.53f, 0, 0, 1, -0.26f, 0.29f, R_ARC_TO, 0.49f,
    0.49f, 0, 0, 1, -0.39f, 0.01f, R_ARC_TO, 0.47f, 0.47f, 0, 0, 1, -0.28f, -0.26f, R_ARC_TO, 6.54f, 6.54f, 0, 0, 1, -0.44f, -1.32f, R_ARC_TO, 6.55f, 6.55f, 0,
    0, 1, -0.14f, -1.39f, R_CUBIC_TO, 0, -1.8f, 0.63f, -3.34f, 1.88f, -4.61f, CUBIC_TO, 6.68f, 6.63f, 8.21f, 6, 10, 6, CLOSE, R_MOVE_TO, 0, -4, R_CUBIC_TO,
    0.96f, 0, 1.88f, 0.12f, 2.77f, 0.36f, R_CUBIC_TO, 0.89f, 0.24f, 1.71f, 0.57f, 2.46f, 1.02f, R_CUBIC_TO, 0.13f, 0.07f, 0.2f, 0.17f, 0.23f, 0.3f, R_ARC_TO,
    0.54f, 0.54f, 0, 0, 1, -0.06f, 0.39f, R_ARC_TO, 0.53f, 0.53f, 0, 0, 1, -0.3f, 0.23f, R_ARC_TO, 0.48f, 0.48f, 0, 0, 1, -0.39f, -0.04f, R_ARC_TO, 8, 8, 0, 0,
    0, -2.22f, -0.91f, ARC_TO, 10.21f, 10.21f, 0, 0, 0, 10, 3.04f, R_CUBIC_TO, -0.85f, 0, -1.68f, 0.1f, -2.49f, 0.3f, R_ARC_TO, 8, 8, 0, 0, 0, -2.22f, 0.91f,
    R_ARC_TO, 0.5f, 0.5f, 0, 0, 1, -0.69f, -0.19f, R_ARC_TO, 0.47f, 0.47f, 0, 0, 1, -0.06f, -0.36f, R_ARC_TO, 0.44f, 0.44f, 0, 0, 1, 0.23f, -0.3f, R_ARC_TO,
    9.2f, 9.2f, 0, 0, 1, 2.46f, -1.04f, ARC_TO, 10.64f, 10.64f, 0, 0, 1, 10, 2, CLOSE, R_MOVE_TO, 0, 6, R_CUBIC_TO, 1.06f, 0, 1.99f, 0.36f, 2.8f, 1.08f,
    R_CUBIC_TO, 0.81f, 0.72f, 1.34f, 1.66f, 1.58f, 2.81f, R_CUBIC_TO, 0.03f, 0.14f, 0, 0.27f, -0.07f, 0.39f, R_ARC_TO, 0.48f, 0.48f, 0, 0, 1, -0.32f, 0.22f,
    R_ARC_TO, 0.47f, 0.47f, 0, 0, 1, -0.38f, -0.07f, R_ARC_TO, 0.48f, 0.48f, 0, 0, 1, -0.21f, -0.32f, R_CUBIC_TO, -0.19f, -0.92f, -0.6f, -1.66f, -1.23f, -2.24f,
    CUBIC_TO, 11.54f, 9.29f, 10.82f, 9, 10, 9, R_CUBIC_TO, -0.96f, 0, -1.78f, 0.39f, -2.46f, 1.17f, R_CUBIC_TO, -0.68f, 0.78f, -1.02f, 1.72f, -1.02f, 2.83f,
    R_CUBIC_TO, 0, 0.75f, 0.16f, 1.48f, 0.49f, 2.19f, R_CUBIC_TO, 0.32f, 0.71f, 0.76f, 1.27f, 1.3f, 1.69f, R_ARC_TO, 0.51f, 0.51f, 0, 0, 1, 0.2f, 0.33f,
    R_ARC_TO, 0.49f, 0.49f, 0, 0, 1, -0.09f, 0.38f, R_ARC_TO, 0.45f, 0.45f, 0, 0, 1, -0.34f, 0.19f, R_ARC_TO, 0.52f, 0.52f, 0, 0, 1, -0.37f, -0.1f, R_CUBIC_TO,
    -0.66f, -0.53f, -1.19f, -1.22f, -1.59f, -2.06f, ARC_TO, 6.08f, 6.08f, 0, 0, 1, 5.52f, 13, R_CUBIC_TO, 0, -1.39f, 0.43f, -2.57f, 1.3f, -3.54f, CUBIC_TO,
    7.69f, 8.48f, 8.75f, 8, 10, 8, CLOSE, R_MOVE_TO, 0, 4, R_ARC_TO, 0.48f, 0.48f, 0, 0, 1, 0.36f, 0.14f, R_ARC_TO, 0.48f, 0.48f, 0, 0, 1, 0.14f, 0.36f,
    R_CUBIC_TO, 0, 1.04f, 0.36f, 1.83f, 1.08f, 2.38f, R_ARC_TO, 3.9f, 3.9f, 0, 0, 0, 2.4f, 0.81f, R_CUBIC_TO, 0.15f, 0, 0.3f, -0.02f, 0.45f, -0.04f, R_LINE_TO,
    0.43f, -0.08f, R_ARC_TO, 0.52f, 0.52f, 0, 0, 1, 0.37f, 0.06f, R_CUBIC_TO, 0.13f, 0.07f, 0.2f, 0.17f, 0.23f, 0.31f, R_ARC_TO, 0.53f, 0.53f, 0, 0, 1, -0.06f,
    0.39f, R_ARC_TO, 0.44f, 0.44f, 0, 0, 1, -0.31f, 0.22f, R_CUBIC_TO, -0.19f, 0.04f, -0.38f, 0.07f, -0.55f, 0.1f, R_CUBIC_TO, -0.17f, 0.03f, -0.36f, 0.04f,
    -0.55f, 0.04f, R_CUBIC_TO, -1.32f, 0, -2.4f, -0.4f, -3.23f, -1.21f, R_CUBIC_TO, -0.83f, -0.81f, -1.25f, -1.8f, -1.25f, -2.98f, R_ARC_TO, 0.48f, 0.48f, 0, 0,
    1, 0.14f, -0.35f, ARC_TO, 0.48f, 0.48f, 0, 0, 1, 10, 12, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kFingerprintRepList, kFingerprintIcon, { kFingerprintPath, std::size(kFingerprintPath) })
VECTOR_ICON_REP_TEMPLATE(kFingerprintOffPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, R_MOVE_TO, 17.06f, 18.48f, R_LINE_TO, -7.42f, -7.44f, R_ARC_TO, 1.55f,
    1.55f, 0, 0, 0, -0.81f, 0.52f, R_ARC_TO, 1.41f, 1.41f, 0, 0, 0, -0.33f, 0.94f, R_CUBIC_TO, 0, 1.48f, 0.41f, 2.61f, 1.24f, 3.36f, R_CUBIC_TO, 0.83f, 0.76f,
    1.74f, 1.14f, 2.74f, 1.14f, R_CUBIC_TO, 0.14f, 0, 0.25f, 0.05f, 0.35f, 0.14f, R_ARC_TO, 0.48f, 0.48f, 0, 0, 1, 0.15f, 0.36f, R_CUBIC_TO, 0, 0.14f, -0.05f,
    0.26f, -0.15f, 0.36f, R_ARC_TO, 0.48f, 0.48f, 0, 0, 1, -0.35f, 0.14f, R_CUBIC_TO, -1.22f, 0, -2.36f, -0.47f, -3.41f, -1.41f, CUBIC_TO, 8.02f, 15.66f, 7.5f,
    14.29f, 7.5f, 12.5f, R_CUBIC_TO, 0, -0.48f, 0.13f, -0.93f, 0.39f, -1.32f, R_CUBIC_TO, 0.25f, -0.39f, 0.59f, -0.7f, 0.99f, -0.91f, R_LINE_TO, -0.69f, -0.66f,
    R_CUBIC_TO, -0.5f, 0.36f, -0.9f, 0.84f, -1.21f, 1.43f, R_CUBIC_TO, -0.31f, 0.59f, -0.46f, 1.25f, -0.46f, 1.97f, R_CUBIC_TO, 0, 0.75f, 0.16f, 1.48f, 0.49f,
    2.19f, R_CUBIC_TO, 0.32f, 0.71f, 0.76f, 1.27f, 1.3f, 1.69f, R_ARC_TO, 0.51f, 0.51f, 0, 0, 1, 0.2f, 0.33f, R_ARC_TO, 0.49f, 0.49f, 0, 0, 1, -0.09f, 0.38f,
    R_ARC_TO, 0.45f, 0.45f, 0, 0, 1, -0.34f, 0.19f, R_ARC_TO, 0.52f, 0.52f, 0, 0, 1, -0.37f, -0.1f, R_CUBIC_TO, -0.66f, -0.53f, -1.19f, -1.22f, -1.59f, -2.06f,
    ARC_TO, 6.08f, 6.08f, 0, 0, 1, 5.52f, 13, R_CUBIC_TO, 0, -0.86f, 0.18f, -1.65f, 0.53f, -2.36f, R_CUBIC_TO, 0.36f, -0.71f, 0.83f, -1.3f, 1.41f, -1.74f,
    R_LINE_TO, -0.75f, -0.77f, R_ARC_TO, 5.58f, 5.58f, 0, 0, 0, -1.59f, 1.89f, ARC_TO, 5.29f, 5.29f, 0, 0, 0, 4.52f, 12.5f, R_CUBIC_TO, 0, 0.4f, 0.04f, 0.8f,
    0.13f, 1.18f, R_CUBIC_TO, 0.09f, 0.38f, 0.21f, 0.75f, 0.38f, 1.12f, R_CUBIC_TO, 0.07f, 0.13f, 0.08f, 0.25f, 0.03f, 0.38f, R_ARC_TO, 0.53f, 0.53f, 0, 0, 1,
    -0.26f, 0.29f, R_ARC_TO, 0.49f, 0.49f, 0, 0, 1, -0.39f, 0.01f, R_ARC_TO, 0.47f, 0.47f, 0, 0, 1, -0.28f, -0.26f, R_ARC_TO, 6.54f, 6.54f, 0, 0, 1, -0.44f,
    -1.32f, R_ARC_TO, 6.55f, 6.55f, 0, 0, 1, -0.14f, -1.39f, R_CUBIC_TO, 0, -1.04f, 0.22f, -2, 0.66f, -2.87f, ARC_TO, 6.63f, 6.63f, 0, 0, 1, 6, 7.42f, LINE_TO,
    5.08f, 6.5f, R_CUBIC_TO, -0.35f, 0.25f, -0.66f, 0.52f, -0.94f, 0.81f, R_ARC_TO, 4.76f, 4.76f, 0, 0, 0, -0.72f, 0.94f, R_ARC_TO, 0.48f, 0.48f, 0, 0, 1,
    -0.67f, 0.19f, R_ARC_TO, 0.56f, 0.56f, 0, 0, 1, -0.23f, -0.3f, R_ARC_TO, 0.48f, 0.48f, 0, 0, 1, 0.04f, -0.39f, R_ARC_TO, 7.06f, 7.06f, 0, 0, 1, 1.81f,
    -1.96f, LINE_TO, 1.5f, 2.94f, R_LINE_TO, 0.73f, -0.71f, R_LINE_TO, 15.54f, 15.54f, CLOSE, MOVE_TO, 13.98f, 12.5f, R_ARC_TO, 0.47f, 0.47f, 0, 0, 1, -0.37f,
    -0.07f, R_ARC_TO, 0.48f, 0.48f, 0, 0, 1, -0.21f, -0.32f, R_CUBIC_TO, -0.16f, -0.84f, -0.52f, -1.53f, -1.05f, -2.08f, R_CUBIC_TO, -0.53f, -0.55f, -1.16f,
    -0.88f, -1.89f, -0.99f, R_LINE_TO, -0.98f, -0.98f, R_CUBIC_TO, 0.1f, -0.03f, 0.18f, -0.05f, 0.26f, -0.05f, ARC_TO, 2.63f, 2.63f, 0, 0, 1, 10, 8, R_CUBIC_TO,
    1.06f, 0, 1.99f, 0.36f, 2.8f, 1.08f, R_CUBIC_TO, 0.81f, 0.72f, 1.34f, 1.66f, 1.58f, 2.81f, R_CUBIC_TO, 0.03f, 0.14f, 0, 0.27f, -0.07f, 0.39f, R_ARC_TO,
    0.48f, 0.48f, 0, 0, 1, -0.32f, 0.22f, CLOSE, MOVE_TO, 10, 2, R_CUBIC_TO, 0.96f, 0, 1.88f, 0.12f, 2.77f, 0.36f, R_CUBIC_TO, 0.89f, 0.24f, 1.71f, 0.57f,
    2.46f, 1.02f, R_CUBIC_TO, 0.13f, 0.07f, 0.2f, 0.17f, 0.23f, 0.3f, R_ARC_TO, 0.54f, 0.54f, 0, 0, 1, -0.06f, 0.39f, R_ARC_TO, 0.53f, 0.53f, 0, 0, 1, -0.3f,
    0.23f, R_ARC_TO, 0.48f, 0.48f, 0, 0, 1, -0.39f, -0.04f, R_ARC_TO, 8.03f, 8.03f, 0, 0, 0, -2.21f, -0.91f, R_ARC_TO, 10.1f, 10.1f, 0, 0, 0, -2.48f, -0.3f,
    R_CUBIC_TO, -0.8f, 0, -1.59f, 0.09f, -2.36f, 0.27f, R_CUBIC_TO, -0.77f, 0.18f, -1.48f, 0.45f, -2.14f, 0.81f, R_LINE_TO, -0.73f, -0.75f, R_ARC_TO, 9.62f,
    9.62f, 0, 0, 1, 2.44f, -1.02f, ARC_TO, 10.56f, 10.56f, 0, 0, 1, 10, 2, CLOSE, R_MOVE_TO, 0, 2, R_CUBIC_TO, 1.6f, 0, 3.07f, 0.34f, 4.42f, 1.02f, R_CUBIC_TO,
    1.35f, 0.68f, 2.35f, 1.59f, 3.02f, 2.73f, R_ARC_TO, 0.5f, 0.5f, 0, 0, 1, -0.19f, 0.69f, R_ARC_TO, 0.46f, 0.46f, 0, 0, 1, -0.37f, 0.04f, R_ARC_TO, 0.56f,
    0.56f, 0, 0, 1, -0.29f, -0.23f, R_CUBIC_TO, -0.58f, -1, -1.47f, -1.79f, -2.66f, -2.37f, CUBIC_TO, 12.74f, 5.29f, 11.43f, 5, 10, 5, R_ARC_TO, 9.45f, 9.45f,
    0, 0, 0, -3.06f, 0.52f, R_LINE_TO, -0.75f, -0.75f, ARC_TO, 9.73f, 9.73f, 0, 0, 1, 10, 4, CLOSE, R_MOVE_TO, 0, 2, R_CUBIC_TO, 1.79f, 0, 3.32f, 0.63f, 4.57f,
    1.9f, R_CUBIC_TO, 1.25f, 1.26f, 1.88f, 2.8f, 1.88f, 4.61f, R_CUBIC_TO, 0, 0.36f, -0.07f, 0.69f, -0.19f, 0.99f, R_CUBIC_TO, -0.13f, 0.3f, -0.32f, 0.57f,
    -0.56f, 0.81f, LINE_TO, 15, 13.58f, R_CUBIC_TO, 0.15f, -0.14f, 0.27f, -0.3f, 0.36f, -0.48f, R_ARC_TO, 1.46f, 1.46f, 0, 0, 0, 0.13f, -0.6f, R_CUBIC_TO, 0,
    -1.52f, -0.53f, -2.81f, -1.6f, -3.89f, CUBIC_TO, 12.81f, 7.54f, 11.52f, 7, 10, 7, R_CUBIC_TO, -0.23f, 0, -0.47f, 0.02f, -0.71f, 0.04f, R_ARC_TO, 3.64f,
    3.64f, 0, 0, 0, -0.69f, 0.14f, R_LINE_TO, -0.79f, -0.79f, R_ARC_TO, 6.79f, 6.79f, 0, 0, 1, 1.06f, -0.29f, CUBIC_TO, 9.24f, 6.04f, 9.61f, 6, 10, 6, CLOSE,
    R_MOVE_TO, 3.98f, 10.67f, R_CUBIC_TO, -1.22f, 0, -2.28f, -0.37f, -3.16f, -1.12f, R_CUBIC_TO, -0.88f, -0.75f, -1.32f, -1.78f, -1.32f, -3.09f, R_CUBIC_TO, 0,
    -0.12f, 0.05f, -0.23f, 0.14f, -0.32f, ARC_TO, 0.47f, 0.47f, 0, 0, 1, 9.98f, 12, R_CUBIC_TO, 0.14f, 0, 0.26f, 0.04f, 0.36f, 0.11f, R_ARC_TO, 0.36f, 0.36f, 0,
    0, 1, 0.16f, 0.31f, R_CUBIC_TO, 0, 1.03f, 0.34f, 1.82f, 1.03f, 2.4f, R_CUBIC_TO, 0.69f, 0.57f, 1.5f, 0.86f, 2.45f, 0.86f, R_CUBIC_TO, 0.14f, 0, 0.28f,
    -0.01f, 0.41f, -0.02f, R_CUBIC_TO, 0.14f, -0.01f, 0.28f, -0.04f, 0.42f, -0.06f, R_ARC_TO, 0.35f, 0.35f, 0, 0, 1, 0.33f, 0.09f, R_CUBIC_TO, 0.1f, 0.09f,
    0.16f, 0.2f, 0.19f, 0.32f, R_ARC_TO, 0.43f, 0.43f, 0, 0, 1, -0.06f, 0.34f, R_ARC_TO, 0.44f, 0.44f, 0, 0, 1, -0.29f, 0.2f, R_CUBIC_TO, -0.17f, 0.04f, -0.33f,
    0.07f, -0.5f, 0.09f, R_ARC_TO, 4.35f, 4.35f, 0, 0, 1, -0.5f, 0.03f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kFingerprintOffRepList, kFingerprintOffIcon, { kFingerprintOffPath, std::size(kFingerprintOffPath) })
VECTOR_ICON_REP_TEMPLATE(kFolderPath, CANVAS_DIMENSIONS, 32, MOVE_TO, 4.8f, 5, CUBIC_TO, 3.26f, 5, 2.01f, 6.29f, 2.01f, 7.88f, LINE_TO, 2, 25.13f, CUBIC_TO, 2,
    26.71f, 3.26f, 28, 4.8f, 28, LINE_TO, 27.2f, 28, CUBIC_TO, 28.74f, 28, 30, 26.71f, 30, 25.13f, LINE_TO, 30, 10.75f, CUBIC_TO, 30, 9.17f, 28.54f, 8, 27, 8,
    LINE_TO, 16, 8, LINE_TO, 13.2f, 5, LINE_TO, 4.8f, 5, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kFolder16Path, CANVAS_DIMENSIONS, 16, MOVE_TO, 2.5f, 2, CUBIC_TO, 1.73f, 2, 1.01f, 3.15f, 1.01f, 3.94f, LINE_TO, 1, 12.56f, CUBIC_TO,
    1, 13.35f, 1.63f, 14, 2.4f, 14, LINE_TO, 13.6f, 14, CUBIC_TO, 14.37f, 14, 15, 13.35f, 15, 12.56f, LINE_TO, 15, 5.38f, CUBIC_TO, 15, 4.58f, 14.27f, 4, 13.5f,
    4, LINE_TO, 9, 4, LINE_TO, 7, 2, LINE_TO, 2.5f, 2, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kFolderRepList, kFolderIcon, { kFolderPath, std::size(kFolderPath) }, { kFolder16Path, std::size(kFolder16Path) })
VECTOR_ICON_REP_TEMPLATE(kFolderChromeRefreshPath, CANVAS_DIMENSIONS, 24, FILL_RULE_NONZERO, MOVE_TO, 4, 20, R_CUBIC_TO, -0.55f, 0, -1.02f, -0.19f, -1.41f,
    -0.59f, ARC_TO, 1.94f, 1.94f, 0, 0, 1, 2, 18, V_LINE_TO, 6, R_CUBIC_TO, 0, -0.55f, 0.2f, -1.02f, 0.59f, -1.41f, CUBIC_TO, 2.98f, 4.2f, 3.45f, 4, 4, 4,
    R_H_LINE_TO, 6, R_LINE_TO, 2, 2, R_H_LINE_TO, 8, R_CUBIC_TO, 0.55f, 0, 1.02f, 0.2f, 1.41f, 0.59f, R_CUBIC_TO, 0.39f, 0.39f, 0.59f, 0.86f, 0.59f, 1.41f,
    R_V_LINE_TO, 10, R_CUBIC_TO, 0, 0.55f, -0.19f, 1.02f, -0.59f, 1.41f, R_CUBIC_TO, -0.39f, 0.39f, -0.86f, 0.59f, -1.41f, 0.59f, CLOSE, R_MOVE_TO, 0, -2,
    R_H_LINE_TO, 16, V_LINE_TO, 8, R_H_LINE_TO, -8.82f, R_LINE_TO, -2, -2, H_LINE_TO, 4, CLOSE, R_MOVE_TO, 0, 0, V_LINE_TO, 6, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kFolderChromeRefresh20Path, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 3.5f, 16, R_CUBIC_TO, -0.4f, 0, -0.75f, -0.15f, -1.05f,
    -0.45f, R_CUBIC_TO, -0.3f, -0.3f, -0.45f, -0.65f, -0.45f, -1.05f, R_V_LINE_TO, -9, R_CUBIC_TO, 0, -0.41f, 0.15f, -0.77f, 0.45f, -1.06f, ARC_TO, 1.45f,
    1.45f, 0, 0, 1, 3.5f, 4, H_LINE_TO, 8, R_LINE_TO, 2, 2, R_H_LINE_TO, 6.5f, R_CUBIC_TO, 0.41f, 0, 0.77f, 0.15f, 1.06f, 0.44f, R_CUBIC_TO, 0.29f, 0.29f,
    0.44f, 0.65f, 0.44f, 1.06f, R_V_LINE_TO, 7, R_CUBIC_TO, 0, 0.4f, -0.15f, 0.75f, -0.44f, 1.05f, R_CUBIC_TO, -0.29f, 0.3f, -0.64f, 0.45f, -1.06f, 0.45f,
    CLOSE, R_MOVE_TO, 0, -1.5f, R_H_LINE_TO, 13, R_V_LINE_TO, -7, H_LINE_TO, 9.38f, R_LINE_TO, -2, -2, H_LINE_TO, 3.5f, CLOSE, R_MOVE_TO, 0, 0, R_V_LINE_TO, -9,
    CLOSE)
VECTOR_ICON_TEMPLATE_CC(kFolderChromeRefreshRepList, kFolderChromeRefreshIcon, { kFolderChromeRefreshPath, std::size(kFolderChromeRefreshPath) },
    { kFolderChromeRefresh20Path, std::size(kFolderChromeRefresh20Path) })
VECTOR_ICON_REP_TEMPLATE(kFolderManagedRefreshPath, CANVAS_DIMENSIONS, 24, FILL_RULE_NONZERO, R_MOVE_TO, 17, 22, R_LINE_TO, -0.3f, -1.5f, R_ARC_TO, 7.56f,
    7.56f, 0, 0, 1, -0.56f, -0.26f, R_ARC_TO, 4.18f, 4.18f, 0, 0, 1, -0.53f, -0.34f, R_LINE_TO, -1.45f, 0.45f, R_LINE_TO, -1, -1.7f, R_LINE_TO, 1.15f, -1,
    R_CUBIC_TO, -0.04f, -0.2f, -0.05f, -0.41f, -0.05f, -0.65f, R_CUBIC_TO, 0, -0.23f, 0.02f, -0.45f, 0.05f, -0.65f, R_LINE_TO, -1.15f, -1, R_LINE_TO, 1, -1.7f,
    R_LINE_TO, 1.45f, 0.45f, R_CUBIC_TO, 0.18f, -0.14f, 0.36f, -0.25f, 0.54f, -0.34f, R_CUBIC_TO, 0.18f, -0.09f, 0.36f, -0.18f, 0.56f, -0.26f, LINE_TO, 17, 12,
    R_H_LINE_TO, 2, R_LINE_TO, 0.3f, 1.5f, R_CUBIC_TO, 0.2f, 0.08f, 0.39f, 0.17f, 0.56f, 0.26f, R_CUBIC_TO, 0.18f, 0.09f, 0.35f, 0.2f, 0.54f, 0.34f, R_LINE_TO,
    1.45f, -0.45f, R_LINE_TO, 1, 1.7f, R_LINE_TO, -1.15f, 1, R_CUBIC_TO, 0.04f, 0.2f, 0.05f, 0.41f, 0.05f, 0.65f, R_CUBIC_TO, 0, 0.23f, -0.02f, 0.45f, -0.05f,
    0.65f, R_LINE_TO, 1.15f, 1, R_LINE_TO, -1, 1.7f, R_LINE_TO, -1.45f, -0.45f, R_CUBIC_TO, -0.18f, 0.14f, -0.36f, 0.25f, -0.53f, 0.34f, R_ARC_TO, 7.56f, 7.56f,
    0, 0, 1, -0.56f, 0.26f, LINE_TO, 19, 22, CLOSE, R_MOVE_TO, 1, -3, R_CUBIC_TO, 0.55f, 0, 1.02f, -0.19f, 1.41f, -0.59f, R_CUBIC_TO, 0.39f, -0.39f, 0.59f,
    -0.86f, 0.59f, -1.41f, R_CUBIC_TO, 0, -0.55f, -0.19f, -1.02f, -0.59f, -1.41f, ARC_TO, 1.94f, 1.94f, 0, 0, 0, 18, 15, R_CUBIC_TO, -0.55f, 0, -1.02f, 0.2f,
    -1.41f, 0.59f, R_CUBIC_TO, -0.39f, 0.39f, -0.59f, 0.86f, -0.59f, 1.41f, R_CUBIC_TO, 0, 0.55f, 0.2f, 1.02f, 0.59f, 1.41f, R_CUBIC_TO, 0.39f, 0.39f, 0.86f,
    0.59f, 1.41f, 0.59f, CLOSE, MOVE_TO, 4, 18, V_LINE_TO, 6, R_V_LINE_TO, 4.3f, R_V_LINE_TO, -0.3f, CLOSE, R_MOVE_TO, 0, 2, R_CUBIC_TO, -0.55f, 0, -1.02f,
    -0.19f, -1.41f, -0.59f, ARC_TO, 1.94f, 1.94f, 0, 0, 1, 2, 18, V_LINE_TO, 6, R_CUBIC_TO, 0, -0.55f, 0.2f, -1.02f, 0.59f, -1.41f, CUBIC_TO, 2.98f, 4.2f,
    3.45f, 4, 4, 4, R_H_LINE_TO, 6, R_LINE_TO, 2, 2, R_H_LINE_TO, 8, R_CUBIC_TO, 0.55f, 0, 1.02f, 0.2f, 1.41f, 0.59f, R_CUBIC_TO, 0.39f, 0.39f, 0.59f, 0.86f,
    0.59f, 1.41f, R_V_LINE_TO, 3.27f, R_ARC_TO, 6.46f, 6.46f, 0, 0, 0, -0.95f, -0.56f, ARC_TO, 8.89f, 8.89f, 0, 0, 0, 20, 10.3f, V_LINE_TO, 8, R_H_LINE_TO,
    -8.82f, R_LINE_TO, -2, -2, H_LINE_TO, 4, R_V_LINE_TO, 12, R_H_LINE_TO, 7.07f, R_CUBIC_TO, 0.05f, 0.35f, 0.13f, 0.69f, 0.24f, 1.02f, R_CUBIC_TO, 0.11f,
    0.34f, 0.24f, 0.66f, 0.39f, 0.98f, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kFolderManagedRefresh20Path, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, R_MOVE_TO, 14.83f, 18, R_LINE_TO, -0.27f, -1.17f, R_ARC_TO,
    3.9f, 3.9f, 0, 0, 1, -0.55f, -0.24f, R_ARC_TO, 2.19f, 2.19f, 0, 0, 1, -0.49f, -0.34f, R_LINE_TO, -1.14f, 0.36f, R_LINE_TO, -0.67f, -1.15f, R_LINE_TO, 0.86f,
    -0.83f, R_ARC_TO, 2.73f, 2.73f, 0, 0, 1, -0.06f, -0.61f, R_CUBIC_TO, 0, -0.22f, 0.02f, -0.42f, 0.06f, -0.62f, R_LINE_TO, -0.86f, -0.81f, R_LINE_TO, 0.67f,
    -1.14f, R_LINE_TO, 1.13f, 0.33f, R_CUBIC_TO, 0.15f, -0.15f, 0.32f, -0.28f, 0.5f, -0.37f, R_CUBIC_TO, 0.18f, -0.1f, 0.37f, -0.17f, 0.56f, -0.23f, LINE_TO,
    14.83f, 10, R_H_LINE_TO, 1.34f, R_LINE_TO, 0.27f, 1.17f, R_CUBIC_TO, 0.2f, 0.07f, 0.39f, 0.15f, 0.57f, 0.24f, R_CUBIC_TO, 0.19f, 0.09f, 0.35f, 0.21f, 0.49f,
    0.36f, R_LINE_TO, 1.13f, -0.31f, R_LINE_TO, 0.67f, 1.15f, R_LINE_TO, -0.84f, 0.79f, R_CUBIC_TO, 0.04f, 0.19f, 0.06f, 0.39f, 0.06f, 0.61f, R_CUBIC_TO, 0,
    0.22f, -0.02f, 0.43f, -0.06f, 0.62f, R_LINE_TO, 0.86f, 0.81f, R_LINE_TO, -0.67f, 1.14f, R_LINE_TO, -1.14f, -0.33f, R_CUBIC_TO, -0.15f, 0.14f, -0.32f, 0.25f,
    -0.5f, 0.34f, R_ARC_TO, 4.5f, 4.5f, 0, 0, 1, -0.56f, 0.24f, LINE_TO, 16.17f, 18, CLOSE, R_MOVE_TO, 0.67f, -2.5f, R_CUBIC_TO, 0.41f, 0, 0.77f, -0.15f, 1.06f,
    -0.44f, R_CUBIC_TO, 0.29f, -0.3f, 0.44f, -0.65f, 0.44f, -1.06f, R_CUBIC_TO, 0, -0.41f, -0.15f, -0.77f, -0.44f, -1.06f, R_ARC_TO, 1.45f, 1.45f, 0, 0, 0,
    -1.06f, -0.44f, R_CUBIC_TO, -0.41f, 0, -0.77f, 0.15f, -1.06f, 0.44f, ARC_TO, 1.45f, 1.45f, 0, 0, 0, 14, 14, R_CUBIC_TO, 0, 0.41f, 0.15f, 0.77f, 0.44f,
    1.06f, R_CUBIC_TO, 0.3f, 0.29f, 0.65f, 0.44f, 1.06f, 0.44f, CLOSE, MOVE_TO, 3.5f, 14.5f, R_V_LINE_TO, -9, R_V_LINE_TO, 3.11f, V_LINE_TO, 8.5f, CLOSE,
    R_MOVE_TO, 0, 1.5f, R_CUBIC_TO, -0.4f, 0, -0.75f, -0.15f, -1.05f, -0.45f, R_CUBIC_TO, -0.3f, -0.3f, -0.45f, -0.65f, -0.45f, -1.05f, R_V_LINE_TO, -9,
    R_CUBIC_TO, 0, -0.41f, 0.15f, -0.77f, 0.45f, -1.06f, ARC_TO, 1.45f, 1.45f, 0, 0, 1, 3.5f, 4, H_LINE_TO, 8, R_LINE_TO, 2, 2, R_H_LINE_TO, 6.5f, R_CUBIC_TO,
    0.41f, 0, 0.77f, 0.15f, 1.06f, 0.44f, R_CUBIC_TO, 0.29f, 0.29f, 0.44f, 0.65f, 0.44f, 1.06f, R_V_LINE_TO, 1.65f, R_ARC_TO, 5.86f, 5.86f, 0, 0, 0, -0.72f,
    -0.32f, R_ARC_TO, 5.07f, 5.07f, 0, 0, 0, -0.78f, -0.22f, V_LINE_TO, 7.5f, H_LINE_TO, 9.38f, R_LINE_TO, -2, -2, H_LINE_TO, 3.5f, R_V_LINE_TO, 9, R_H_LINE_TO,
    6.52f, R_CUBIC_TO, 0.03f, 0.26f, 0.07f, 0.52f, 0.14f, 0.77f, R_CUBIC_TO, 0.06f, 0.25f, 0.14f, 0.5f, 0.24f, 0.73f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kFolderManagedRefreshRepList, kFolderManagedRefreshIcon, { kFolderManagedRefreshPath, std::size(kFolderManagedRefreshPath) },
    { kFolderManagedRefresh20Path, std::size(kFolderManagedRefresh20Path) })
VECTOR_ICON_REP_TEMPLATE(kFolderOpenPath, MOVE_TO, 40, 12, H_LINE_TO, 24, R_LINE_TO, -4, -4, H_LINE_TO, 8, R_CUBIC_TO, -2.21f, 0, -3.98f, 1.79f, -3.98f, 4,
    LINE_TO, 4, 36, R_CUBIC_TO, 0, 2.21f, 1.79f, 4, 4, 4, R_H_LINE_TO, 32, R_CUBIC_TO, 2.21f, 0, 4, -1.79f, 4, -4, V_LINE_TO, 16, R_CUBIC_TO, 0, -2.21f, -1.79f,
    -4, -4, -4, CLOSE, R_MOVE_TO, 0, 24, H_LINE_TO, 8, V_LINE_TO, 16, R_H_LINE_TO, 32, R_V_LINE_TO, 20, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kFolderOpenRepList, kFolderOpenIcon, { kFolderOpenPath, std::size(kFolderOpenPath) })
VECTOR_ICON_REP_TEMPLATE(kFontDownloadPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 20, 2, H_LINE_TO, 4, R_CUBIC_TO, -1.1f, 0, -2, 0.9f, -2, 2, R_V_LINE_TO, 16,
    R_CUBIC_TO, 0, 1.1f, 0.9f, 2, 2, 2, R_H_LINE_TO, 16, R_CUBIC_TO, 1.1f, 0, 2, -0.9f, 2, -2, V_LINE_TO, 4, R_CUBIC_TO, 0, -1.1f, -0.9f, -2, -2, -2, CLOSE,
    R_MOVE_TO, 0, 18, H_LINE_TO, 4, V_LINE_TO, 4, R_H_LINE_TO, 16, R_V_LINE_TO, 16, CLOSE, MOVE_TO, 10.69f, 6, R_H_LINE_TO, 2.6f, R_LINE_TO, 4.51f, 12,
    R_H_LINE_TO, -2.5f, R_LINE_TO, -1.01f, -2.87f, H_LINE_TO, 9.7f, LINE_TO, 8.7f, 18, H_LINE_TO, 6.2f, R_LINE_TO, 4.49f, -12, CLOSE, R_MOVE_TO, 2.87f, 7.06f,
    R_LINE_TO, -1.06f, -3.02f, R_LINE_TO, -0.43f, -1.44f, R_H_LINE_TO, -0.13f, R_LINE_TO, -0.44f, 1.44f, R_LINE_TO, -1.07f, 3.02f, R_H_LINE_TO, 3.13f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kFontDownloadRepList, kFontDownloadIcon, { kFontDownloadPath, std::size(kFontDownloadPath) })
VECTOR_ICON_REP_TEMPLATE(kFontDownloadChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 5.36f, 15, H_LINE_TO, 7.09f, LINE_TO, 8, 12.44f,
    R_H_LINE_TO, 4.02f, LINE_TO, 12.92f, 15, R_H_LINE_TO, 1.72f, R_LINE_TO, -3.75f, -10, R_H_LINE_TO, -1.79f, CLOSE, MOVE_TO, 8.5f, 11, R_LINE_TO, 1.46f,
    -4.14f, R_H_LINE_TO, 0.06f, LINE_TO, 11.48f, 11, CLOSE, R_MOVE_TO, -5, 7, R_CUBIC_TO, -0.41f, 0, -0.77f, -0.15f, -1.06f, -0.44f, ARC_TO, 1.44f, 1.44f, 0, 0,
    1, 2, 16.5f, R_V_LINE_TO, -13, R_CUBIC_TO, 0, -0.41f, 0.15f, -0.77f, 0.44f, -1.06f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 3.5f, 2, R_H_LINE_TO, 13, R_CUBIC_TO,
    0.41f, 0, 0.77f, 0.15f, 1.06f, 0.44f, R_CUBIC_TO, 0.29f, 0.29f, 0.44f, 0.65f, 0.44f, 1.06f, R_V_LINE_TO, 13, R_CUBIC_TO, 0, 0.41f, -0.15f, 0.77f, -0.44f,
    1.06f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 16.5f, 18, CLOSE, R_MOVE_TO, 0, -1.5f, R_H_LINE_TO, 13, R_V_LINE_TO, -13, R_H_LINE_TO, -13, CLOSE, R_MOVE_TO, 0, -13,
    R_V_LINE_TO, 13, CLOSE)
VECTOR_ICON_TEMPLATE_CC(
    kFontDownloadChromeRefreshRepList, kFontDownloadChromeRefreshIcon, { kFontDownloadChromeRefreshPath, std::size(kFontDownloadChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kFontDownloadOffChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 16.73f, 18.83f, LINE_TO, 15.88f, 18, H_LINE_TO,
    3.5f, R_CUBIC_TO, -0.41f, 0, -0.77f, -0.15f, -1.06f, -0.44f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 2, 16.5f, V_LINE_TO, 4.13f, R_LINE_TO, -0.83f, -0.85f, LINE_TO,
    2.23f, 2.23f, R_LINE_TO, 15.54f, 15.54f, CLOSE, MOVE_TO, 3.5f, 16.5f, R_H_LINE_TO, 10.88f, LINE_TO, 3.5f, 5.63f, CLOSE, R_MOVE_TO, 14.5f, -0.62f, R_LINE_TO,
    -1.5f, -1.5f, V_LINE_TO, 3.5f, H_LINE_TO, 5.63f, LINE_TO, 4.13f, 2, H_LINE_TO, 16.5f, R_CUBIC_TO, 0.41f, 0, 0.77f, 0.15f, 1.06f, 0.44f, R_CUBIC_TO, 0.29f,
    0.29f, 0.44f, 0.65f, 0.44f, 1.06f, CLOSE, R_MOVE_TO, -4.83f, -4.83f, LINE_TO, 10.61f, 8.48f, R_LINE_TO, -0.56f, -1.62f, R_H_LINE_TO, -0.09f, R_LINE_TO,
    -0.25f, 0.73f, R_LINE_TO, -1.14f, -1.14f, LINE_TO, 9.11f, 5, R_H_LINE_TO, 1.79f, CLOSE, R_MOVE_TO, -4.27f, 0.04f, CLOSE, R_MOVE_TO, 1.71f, -2.58f, CLOSE,
    R_MOVE_TO, 2.19f, 6.27f, R_LINE_TO, -1.06f, -3.04f, R_LINE_TO, 2.71f, 2.71f, R_LINE_TO, 0.13f, 0.33f, CLOSE, MOVE_TO, 5.33f, 15, LINE_TO, 7.98f, 7.98f,
    R_LINE_TO, 1.19f, 1.19f, LINE_TO, 8.52f, 11, R_H_LINE_TO, 2.48f, R_LINE_TO, 1.43f, 1.44f, H_LINE_TO, 8.06f, LINE_TO, 7.17f, 15, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kFontDownloadOffChromeRefreshRepList, kFontDownloadOffChromeRefreshIcon,
    { kFontDownloadOffChromeRefreshPath, std::size(kFontDownloadOffChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kForward10Path, CANVAS_DIMENSIONS, 960, MOVE_TO, 360, 640, R_V_LINE_TO, -180, R_H_LINE_TO, -60, R_V_LINE_TO, -60, R_H_LINE_TO, 120,
    R_V_LINE_TO, 240, R_H_LINE_TO, -60, CLOSE, R_MOVE_TO, 140, 0, R_QUADRATIC_TO, -17, 0, -28.5f, -11.5f, QUADRATIC_TO_SHORTHAND, 460, 600, R_V_LINE_TO, -160,
    R_QUADRATIC_TO, 0, -17, 11.5f, -28.5f, QUADRATIC_TO_SHORTHAND, 500, 400, R_H_LINE_TO, 80, R_QUADRATIC_TO, 17, 0, 28.5f, 11.5f, QUADRATIC_TO_SHORTHAND, 620,
    440, R_V_LINE_TO, 160, R_QUADRATIC_TO, 0, 17, -11.5f, 28.5f, QUADRATIC_TO_SHORTHAND, 580, 640, R_H_LINE_TO, -80, CLOSE, R_MOVE_TO, 20, -60, R_H_LINE_TO, 40,
    R_V_LINE_TO, -120, R_H_LINE_TO, -40, R_V_LINE_TO, 120, CLOSE, MOVE_TO, 480, 880, R_QUADRATIC_TO, -75, 0, -140.5f, -28.5f, R_QUADRATIC_TO, -65.5f, -28.5f,
    -114, -77, R_QUADRATIC_TO, -48.5f, -48.5f, -77, -114, QUADRATIC_TO_SHORTHAND, 120, 520, R_QUADRATIC_TO, 0, -75, 28.5f, -140.5f, R_QUADRATIC_TO, 28.5f,
    -65.5f, 77, -114, R_QUADRATIC_TO, 48.5f, -48.5f, 114, -77, QUADRATIC_TO_SHORTHAND, 480, 160, R_H_LINE_TO, 6, R_LINE_TO, -62, -62, R_LINE_TO, 56, -58,
    R_LINE_TO, 160, 160, R_LINE_TO, -160, 160, R_LINE_TO, -56, -58, R_LINE_TO, 62, -62, R_H_LINE_TO, -6, R_QUADRATIC_TO, -117, 0, -198.5f, 81.5f,
    QUADRATIC_TO_SHORTHAND, 200, 520, R_QUADRATIC_TO, 0, 117, 81.5f, 198.5f, QUADRATIC_TO_SHORTHAND, 480, 800, R_QUADRATIC_TO, 117, 0, 198.5f, -81.5f,
    QUADRATIC_TO_SHORTHAND, 760, 520, R_H_LINE_TO, 80, R_QUADRATIC_TO, 0, 75, -28.5f, 140.5f, R_QUADRATIC_TO, -28.5f, 65.5f, -77, 114, R_QUADRATIC_TO, -48.5f,
    48.5f, -114, 77, QUADRATIC_TO_SHORTHAND, 480, 880, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kForward10RepList, kForward10Icon, { kForward10Path, std::size(kForward10Path) })
VECTOR_ICON_REP_TEMPLATE(kForwardArrowPath, CANVAS_DIMENSIONS, 32, MOVE_TO, 27.78f, 14.03f, CUBIC_TO, 28.47f, 14.15f, 29, 14.77f, 29, 15.5f, CUBIC_TO, 29,
    16.25f, 28.47f, 16.86f, 27.76f, 16.98f, LINE_TO, 27.98f, 17.19f, LINE_TO, 17.64f, 27.51f, CUBIC_TO, 17.35f, 27.81f, 16.95f, 28, 16.5f, 28, CUBIC_TO, 15.67f,
    28, 15, 27.33f, 15, 26.5f, CUBIC_TO, 15, 26.05f, 15.2f, 25.65f, 15.51f, 25.38f, LINE_TO, 15.45f, 25.32f, LINE_TO, 23.78f, 17, LINE_TO, 4.49f, 17, CUBIC_TO,
    3.67f, 17, 3, 16.33f, 3, 15.5f, CUBIC_TO, 3, 14.67f, 3.67f, 14, 4.49f, 14, LINE_TO, 23.8f, 14, LINE_TO, 15.45f, 5.66f, CUBIC_TO, 15.19f, 5.34f, 15, 4.94f,
    15, 4.5f, CUBIC_TO, 15, 3.68f, 15.67f, 3, 16.5f, 3, CUBIC_TO, 16.94f, 3, 17.34f, 3.2f, 17.61f, 3.5f, LINE_TO, 17.64f, 3.47f, LINE_TO, 28, 13.81f, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kForwardArrow16Path, CANVAS_DIMENSIONS, 16, MOVE_TO, 7, 13.51f, LINE_TO, 11.51f, 9, LINE_TO, 2, 9, CUBIC_TO, 1.45f, 9, 1, 8.55f, 1, 8,
    CUBIC_TO, 1, 7.45f, 1.45f, 7, 2, 7, LINE_TO, 11.51f, 7, LINE_TO, 7, 2.49f, CUBIC_TO, 7.03f, 2.28f, 7, 2.14f, 7, 2, CUBIC_TO, 7, 1.45f, 7.45f, 1, 8, 1,
    CUBIC_TO, 8.14f, 1, 8.28f, 1.03f, 8.41f, 1.09f, LINE_TO, 8.49f, 1, LINE_TO, 15, 7.51f, LINE_TO, 14.91f, 7.59f, CUBIC_TO, 14.97f, 7.72f, 15, 7.85f, 15, 8,
    CUBIC_TO, 15, 8.15f, 14.97f, 8.28f, 14.91f, 8.41f, LINE_TO, 15, 8.49f, LINE_TO, 8.49f, 15, CUBIC_TO, 8.28f, 14.97f, 8.14f, 15, 8, 15, CUBIC_TO, 7.45f, 15,
    7, 14.55f, 7, 14, CUBIC_TO, 7, 13.86f, 7.03f, 13.72f, 7.09f, 13.59f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(
    kForwardArrowRepList, kForwardArrowIcon, { kForwardArrowPath, std::size(kForwardArrowPath) }, { kForwardArrow16Path, std::size(kForwardArrow16Path) })
VECTOR_ICON_REP_TEMPLATE(kForwardArrowChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 13.13f, 10.75f, H_LINE_TO, 4, R_V_LINE_TO, -1.5f,
    R_H_LINE_TO, 9.13f, LINE_TO, 8.94f, 5.06f, LINE_TO, 10, 4, R_LINE_TO, 6, 6, R_LINE_TO, -6, 6, R_LINE_TO, -1.06f, -1.06f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(
    kForwardArrowChromeRefreshRepList, kForwardArrowChromeRefreshIcon, { kForwardArrowChromeRefreshPath, std::size(kForwardArrowChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kGlobePath, CANVAS_DIMENSIONS, 16, FILL_RULE_NONZERO, MOVE_TO, 8, 14.54f, R_CUBIC_TO, -0.9f, 0, -1.75f, -0.17f, -2.54f, -0.51f,
    R_ARC_TO, 6.52f, 6.52f, 0, 0, 1, -2.08f, -1.4f, R_ARC_TO, 6.52f, 6.52f, 0, 0, 1, -1.4f, -2.08f, R_ARC_TO, 6.33f, 6.33f, 0, 0, 1, -0.51f, -2.55f, R_CUBIC_TO,
    0, -0.91f, 0.17f, -1.75f, 0.51f, -2.54f, ARC_TO, 6.53f, 6.53f, 0, 0, 1, 3.38f, 3.38f, ARC_TO, 6.52f, 6.52f, 0, 0, 1, 5.46f, 1.98f, R_ARC_TO, 6.33f, 6.33f,
    0, 0, 1, 2.55f, -0.51f, R_CUBIC_TO, 0.91f, 0, 1.75f, 0.17f, 2.54f, 0.51f, R_CUBIC_TO, 0.79f, 0.34f, 1.48f, 0.8f, 2.07f, 1.4f, R_ARC_TO, 6.5f, 6.5f, 0, 0, 1,
    1.4f, 2.08f, R_ARC_TO, 6.29f, 6.29f, 0, 0, 1, 0.51f, 2.54f, R_CUBIC_TO, 0, 0.9f, -0.17f, 1.75f, -0.51f, 2.54f, R_ARC_TO, 6.52f, 6.52f, 0, 0, 1, -1.4f,
    2.08f, R_ARC_TO, 6.5f, 6.5f, 0, 0, 1, -2.08f, 1.4f, R_ARC_TO, 6.29f, 6.29f, 0, 0, 1, -2.54f, 0.51f, CLOSE, MOVE_TO, 8, 13.15f, R_CUBIC_TO, 1.3f, 0, 2.42f,
    -0.41f, 3.37f, -1.25f, R_ARC_TO, 5.06f, 5.06f, 0, 0, 0, 1.72f, -3.1f, R_CUBIC_TO, 0, 0.02f, 0, 0.04f, 0, 0.06f, R_V_LINE_TO, 0.05f, R_ARC_TO, 1.72f, 1.72f,
    0, 0, 1, -0.34f, 0.09f, R_CUBIC_TO, -0.11f, 0.02f, -0.23f, 0.03f, -0.36f, 0.03f, R_H_LINE_TO, -2.37f, R_ARC_TO, 1.2f, 1.2f, 0, 0, 1, -0.88f, -0.37f,
    R_ARC_TO, 1.21f, 1.21f, 0, 0, 1, -0.36f, -0.88f, R_V_LINE_TO, -0.82f, H_LINE_TO, 5.87f, V_LINE_TO, 5.34f, R_CUBIC_TO, 0, -0.34f, 0.13f, -0.64f, 0.37f,
    -0.88f, R_CUBIC_TO, 0.25f, -0.25f, 0.54f, -0.37f, 0.88f, -0.37f, R_H_LINE_TO, 0.82f, R_V_LINE_TO, -0.4f, R_CUBIC_TO, 0, -0.17f, 0.03f, -0.33f, 0.09f,
    -0.48f, R_ARC_TO, 0.89f, 0.89f, 0, 0, 1, 0.24f, -0.35f, R_ARC_TO, 0.76f, 0.76f, 0, 0, 0, -0.16f, -0.01f, H_LINE_TO, 8, R_CUBIC_TO, -1.43f, 0, -2.65f, 0.5f,
    -3.65f, 1.5f, CUBIC_TO_SHORTHAND, 2.85f, 6.57f, 2.85f, 8, R_CUBIC_TO, 0, 0.01f, 0, 0.03f, 0, 0.04f, R_V_LINE_TO, 0.04f, R_H_LINE_TO, 3.36f, R_CUBIC_TO,
    0.7f, 0, 1.29f, 0.24f, 1.77f, 0.73f, R_CUBIC_TO, 0.48f, 0.48f, 0.73f, 1.07f, 0.73f, 1.77f, R_V_LINE_TO, 0.82f, H_LINE_TO, 6.23f, R_V_LINE_TO, 1.45f,
    R_CUBIC_TO, 0.27f, 0.11f, 0.56f, 0.18f, 0.85f, 0.23f, R_CUBIC_TO, 0.29f, 0.05f, 0.6f, 0.07f, 0.91f, 0.07f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kGlobeRepList, kGlobeIcon, { kGlobePath, std::size(kGlobePath) })
VECTOR_ICON_REP_TEMPLATE(kGoogleColorPath, PATH_COLOR_ARGB, 0xFF, 0x42, 0x85, 0xF4, MOVE_TO, 43.5f, 20, H_LINE_TO, 24, R_V_LINE_TO, 8, R_H_LINE_TO, 11.6f,
    R_CUBIC_TO, -0.5f, 2.5f, -2.2f, 4.7f, -4.3f, 6.1f, R_LINE_TO, 6.6f, 5, R_CUBIC_TO, 3.9f, -3.5f, 6.1f, -8.6f, 6.1f, -14.7f, CUBIC_TO, 44, 23, 43.7f, 21.3f,
    43.5f, 20, CLOSE, NEW_PATH, PATH_COLOR_ARGB, 0xFF, 0x0F, 0x9D, 0x58, MOVE_TO, 24.4f, 36.1f, R_CUBIC_TO, -5.3f, 0, -9.8f, -3.5f, -11.4f, -8.2f, R_H_LINE_TO,
    0, R_LINE_TO, -1.5f, 1.1f, R_LINE_TO, -5.3f, 4, R_V_LINE_TO, 0, R_CUBIC_TO, 3.4f, 6.5f, 10.2f, 11, 18.2f, 11, R_CUBIC_TO, 5.5f, 0, 10.1f, -1.8f, 13.5f,
    -4.8f, R_LINE_TO, -6.6f, -5, CUBIC_TO, 29.5f, 35.3f, 27.2f, 36.1f, 24.4f, 36.1f, CLOSE, NEW_PATH, PATH_COLOR_ARGB, 0xFF, 0xFF, 0xCD, 0x40, MOVE_TO, 13,
    27.8f, LINE_TO, 13, 27.8f, R_CUBIC_TO, -0.4f, -1.2f, -0.6f, -2.5f, -0.6f, -3.8f, R_CUBIC_TO, 0, -1.3f, 0.2f, -2.6f, 0.6f, -3.8f, LINE_TO, 6.2f, 15,
    CUBIC_TO, 4.8f, 17.7f, 4, 20.8f, 4, 24, R_CUBIC_TO, 0, 3.2f, 0.8f, 6.3f, 2.2f, 9, R_LINE_TO, 5.3f, -4, LINE_TO, 13, 27.8f, CLOSE, NEW_PATH, PATH_COLOR_ARGB,
    0xFF, 0xDB, 0x44, 0x37, MOVE_TO, 24.4f, 4, R_CUBIC_TO, -8, 0, -14.9f, 4.5f, -18.2f, 11, R_LINE_TO, 6.8f, 5.2f, R_CUBIC_TO, 1.6f, -4.7f, 6.1f, -8.2f, 11.4f,
    -8.2f, R_CUBIC_TO, 3, 0, 5.7f, 1, 7.8f, 3, R_LINE_TO, 5.8f, -5.7f, CUBIC_TO, 34.5f, 6, 29.9f, 4, 24.4f, 4, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kGoogleColor24Path, CANVAS_DIMENSIONS, 24, PATH_COLOR_ARGB, 0xFF, 0x42, 0x85, 0xF4, MOVE_TO, 21.73f, 10, LINE_TO, 12, 10, LINE_TO, 12,
    14, LINE_TO, 17.82f, 14, CUBIC_TO, 17.58f, 15.25f, 16.73f, 16.35f, 15.65f, 17.06f, LINE_TO, 15.65f, 19.58f, LINE_TO, 18.96f, 19.58f, CUBIC_TO, 20.89f,
    17.84f, 22, 15.27f, 22, 12.23f, CUBIC_TO, 22, 11.52f, 21.85f, 10.65f, 21.73f, 10, CLOSE, NEW_PATH, PATH_COLOR_ARGB, 0xFF, 0x0F, 0x9D, 0x58, MOVE_TO, 12.2f,
    22, CUBIC_TO, 14.96f, 22, 17.27f, 21.11f, 18.96f, 19.58f, LINE_TO, 15.65f, 17.06f, CUBIC_TO, 14.74f, 17.66f, 13.58f, 18.03f, 12.2f, 18.03f, CUBIC_TO, 9.55f,
    18.03f, 7.3f, 16.27f, 6.49f, 13.91f, LINE_TO, 3.09f, 13.91f, LINE_TO, 3.09f, 16.49f, CUBIC_TO, 4.77f, 19.75f, 8.22f, 22, 12.2f, 22, CLOSE, NEW_PATH,
    PATH_COLOR_ARGB, 0xFF, 0xFF, 0xCD, 0x40, MOVE_TO, 6.49f, 13.9f, CUBIC_TO, 6.29f, 13.3f, 6.17f, 12.66f, 6.17f, 12, CUBIC_TO, 6.17f, 11.34f, 6.29f, 10.7f,
    6.49f, 10.1f, LINE_TO, 6.49f, 7.52f, LINE_TO, 3.09f, 7.52f, CUBIC_TO, 2.4f, 8.86f, 2, 10.38f, 2, 12, CUBIC_TO, 2, 13.62f, 2.4f, 15.14f, 3.09f, 16.48f,
    LINE_TO, 5.74f, 14.46f, LINE_TO, 6.49f, 13.9f, CLOSE, NEW_PATH, PATH_COLOR_ARGB, 0xFF, 0xDB, 0x44, 0x37, MOVE_TO, 12.2f, 5.98f, CUBIC_TO, 13.71f, 5.98f,
    15.04f, 6.49f, 16.11f, 7.47f, LINE_TO, 19.03f, 4.61f, CUBIC_TO, 17.26f, 2.99f, 14.96f, 2, 12.2f, 2, CUBIC_TO, 8.22f, 2, 4.77f, 4.25f, 3.09f, 7.52f, LINE_TO,
    6.49f, 10.1f, CUBIC_TO, 7.3f, 7.74f, 9.55f, 5.98f, 12.2f, 5.98f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(
    kGoogleColorRepList, kGoogleColorIcon, { kGoogleColorPath, std::size(kGoogleColorPath) }, { kGoogleColor24Path, std::size(kGoogleColor24Path) })
VECTOR_ICON_REP_TEMPLATE(kGppMaybePath, CANVAS_DIMENSIONS, 24, MOVE_TO, 12, 4.24f, R_LINE_TO, 6, 3, R_V_LINE_TO, 4.1f, R_CUBIC_TO, 0, 3.9f, -2.55f, 7.5f, -6,
    8.59f, R_CUBIC_TO, -3.45f, -1.09f, -6, -4.7f, -6, -8.59f, R_V_LINE_TO, -4.1f, R_LINE_TO, 6, -3, MOVE_TO, 12, 2, LINE_TO, 4, 6, R_V_LINE_TO, 5.33f,
    R_CUBIC_TO, 0, 4.93f, 3.41f, 9.55f, 8, 10.67f, R_CUBIC_TO, 4.59f, -1.12f, 8, -5.73f, 8, -10.67f, V_LINE_TO, 6, R_LINE_TO, -8, -4, CLOSE, R_MOVE_TO, -1, 13,
    R_H_LINE_TO, 2, R_V_LINE_TO, 2, R_H_LINE_TO, -2, R_V_LINE_TO, -2, CLOSE, R_MOVE_TO, 2, -7, R_H_LINE_TO, -2, R_V_LINE_TO, 5, R_H_LINE_TO, 2, V_LINE_TO, 8,
    CLOSE)
VECTOR_ICON_TEMPLATE_CC(kGppMaybeRepList, kGppMaybeIcon, { kGppMaybePath, std::size(kGppMaybePath) })
VECTOR_ICON_REP_TEMPLATE(kHandGesturePath, CANVAS_DIMENSIONS, 24, FILL_RULE_NONZERO, MOVE_TO, 22, 5.02f, R_CUBIC_TO, 0, -0.85f, -0.29f, -1.57f, -0.87f, -2.15f,
    R_CUBIC_TO, -0.58f, -0.58f, -1.3f, -0.87f, -2.15f, -0.87f, V_LINE_TO, 0.5f, R_CUBIC_TO, 1.25f, 0, 2.32f, 0.44f, 3.2f, 1.32f, R_CUBIC_TO, 0.88f, 0.88f,
    1.32f, 1.95f, 1.32f, 3.2f, CLOSE, MOVE_TO, 6, 23, R_CUBIC_TO, -1.38f, 0, -2.56f, -0.49f, -3.54f, -1.46f, CUBIC_TO, 1.49f, 20.56f, 1, 19.38f, 1, 18,
    R_H_LINE_TO, 1.5f, R_CUBIC_TO, 0, 0.97f, 0.34f, 1.79f, 1.02f, 2.48f, ARC_TO, 3.38f, 3.38f, 0, 0, 0, 6, 21.5f, CLOSE, R_MOVE_TO, 4.05f, 0, R_CUBIC_TO, -0.5f,
    0, -0.97f, -0.11f, -1.4f, -0.34f, R_ARC_TO, 2.92f, 2.92f, 0, 0, 1, -1.07f, -0.96f, LINE_TO, 1.2f, 12.38f, R_LINE_TO, 0.6f, -0.57f, R_CUBIC_TO, 0.32f,
    -0.32f, 0.69f, -0.5f, 1.13f, -0.55f, R_CUBIC_TO, 0.43f, -0.05f, 0.82f, 0.05f, 1.18f, 0.3f, LINE_TO, 7, 13.58f, V_LINE_TO, 4, R_CUBIC_TO, 0, -0.28f, 0.1f,
    -0.52f, 0.29f, -0.71f, ARC_TO, 0.96f, 0.96f, 0, 0, 1, 8, 3, R_CUBIC_TO, 0.28f, 0, 0.52f, 0.1f, 0.71f, 0.29f, R_CUBIC_TO, 0.19f, 0.19f, 0.29f, 0.43f, 0.29f,
    0.71f, R_V_LINE_TO, 13.43f, R_LINE_TO, -3.7f, -2.6f, R_LINE_TO, 3.93f, 5.73f, R_ARC_TO, 0.99f, 0.99f, 0, 0, 0, 0.82f, 0.45f, LINE_TO, 17, 21, R_CUBIC_TO,
    0.55f, 0, 1.02f, -0.19f, 1.41f, -0.59f, R_CUBIC_TO, 0.39f, -0.39f, 0.59f, -0.86f, 0.59f, -1.41f, V_LINE_TO, 5, R_CUBIC_TO, 0, -0.28f, 0.1f, -0.52f, 0.29f,
    -0.71f, ARC_TO, 0.96f, 0.96f, 0, 0, 1, 20, 4, R_CUBIC_TO, 0.28f, 0, 0.52f, 0.1f, 0.71f, 0.29f, R_CUBIC_TO, 0.19f, 0.19f, 0.29f, 0.43f, 0.29f, 0.71f,
    R_V_LINE_TO, 14, R_CUBIC_TO, 0, 1.1f, -0.39f, 2.04f, -1.18f, 2.82f, CUBIC_TO, 19.04f, 22.61f, 18.1f, 23, 17, 23, CLOSE, MOVE_TO, 11, 12, V_LINE_TO, 2,
    R_CUBIC_TO, 0, -0.28f, 0.1f, -0.52f, 0.29f, -0.71f, ARC_TO, 0.96f, 0.96f, 0, 0, 1, 12, 1, R_CUBIC_TO, 0.28f, 0, 0.52f, 0.1f, 0.71f, 0.29f, R_CUBIC_TO,
    0.19f, 0.19f, 0.29f, 0.43f, 0.29f, 0.71f, R_V_LINE_TO, 10, CLOSE, R_MOVE_TO, 4, 0, V_LINE_TO, 3, R_CUBIC_TO, 0, -0.28f, 0.1f, -0.52f, 0.29f, -0.71f, ARC_TO,
    0.96f, 0.96f, 0, 0, 1, 16, 2, R_CUBIC_TO, 0.28f, 0, 0.52f, 0.1f, 0.71f, 0.29f, R_CUBIC_TO, 0.19f, 0.19f, 0.29f, 0.43f, 0.29f, 0.71f, R_V_LINE_TO, 9, CLOSE,
    R_MOVE_TO, -2.85f, 4.5f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kHandGestureRepList, kHandGestureIcon, { kHandGesturePath, std::size(kHandGesturePath) })
VECTOR_ICON_REP_TEMPLATE(kHandGestureOffPath, CANVAS_DIMENSIONS, 24, FILL_RULE_NONZERO, R_MOVE_TO, 21, 18.15f, R_LINE_TO, -2, -2, V_LINE_TO, 5, R_CUBIC_TO, 0,
    -0.28f, 0.1f, -0.52f, 0.29f, -0.71f, ARC_TO, 0.96f, 0.96f, 0, 0, 1, 20, 4, R_CUBIC_TO, 0.28f, 0, 0.52f, 0.1f, 0.71f, 0.29f, R_CUBIC_TO, 0.19f, 0.19f, 0.29f,
    0.43f, 0.29f, 0.71f, CLOSE, R_MOVE_TO, -12, -12, R_LINE_TO, -2, -2, V_LINE_TO, 4, R_CUBIC_TO, 0, -0.28f, 0.1f, -0.52f, 0.29f, -0.71f, ARC_TO, 0.96f, 0.96f,
    0, 0, 1, 8, 3, R_CUBIC_TO, 0.28f, 0, 0.52f, 0.1f, 0.71f, 0.29f, R_CUBIC_TO, 0.19f, 0.19f, 0.29f, 0.43f, 0.29f, 0.71f, CLOSE, R_MOVE_TO, 4, 4, R_LINE_TO, -2,
    -2, V_LINE_TO, 2, R_CUBIC_TO, 0, -0.28f, 0.1f, -0.52f, 0.29f, -0.71f, ARC_TO, 0.96f, 0.96f, 0, 0, 1, 12, 1, R_CUBIC_TO, 0.28f, 0, 0.52f, 0.1f, 0.71f, 0.29f,
    R_CUBIC_TO, 0.19f, 0.19f, 0.29f, 0.43f, 0.29f, 0.71f, CLOSE, R_MOVE_TO, 4, 1.88f, R_H_LINE_TO, -2, V_LINE_TO, 3, R_CUBIC_TO, 0, -0.28f, 0.1f, -0.52f, 0.29f,
    -0.71f, ARC_TO, 0.96f, 0.96f, 0, 0, 1, 16, 2, R_CUBIC_TO, 0.28f, 0, 0.52f, 0.1f, 0.71f, 0.29f, R_CUBIC_TO, 0.19f, 0.19f, 0.29f, 0.43f, 0.29f, 0.71f, CLOSE,
    R_MOVE_TO, 0.93f, 8.73f, LINE_TO, 9, 11.82f, R_V_LINE_TO, 6.3f, R_LINE_TO, -3.95f, -1.98f, R_LINE_TO, 4.43f, 4.4f, R_CUBIC_TO, 0.13f, 0.12f, 0.27f, 0.22f,
    0.4f, 0.31f, R_CUBIC_TO, 0.13f, 0.09f, 0.28f, 0.14f, 0.45f, 0.14f, H_LINE_TO, 17, R_CUBIC_TO, 0.17f, 0, 0.33f, -0.02f, 0.49f, -0.06f, R_CUBIC_TO, 0.16f,
    -0.04f, 0.31f, -0.1f, 0.44f, -0.19f, CLOSE, MOVE_TO, 10.32f, 23, R_CUBIC_TO, -0.4f, 0, -0.78f, -0.07f, -1.15f, -0.23f, R_ARC_TO, 2.91f, 2.91f, 0, 0, 1,
    -0.98f, -0.65f, LINE_TO, 0.98f, 14.9f, R_LINE_TO, 1.35f, -1.07f, R_CUBIC_TO, 0.3f, -0.23f, 0.64f, -0.37f, 1.03f, -0.41f, R_ARC_TO, 1.86f, 1.86f, 0, 0, 1,
    1.1f, 0.21f, LINE_TO, 7, 14.88f, R_V_LINE_TO, -5.05f, LINE_TO, 0.68f, 3.5f, R_LINE_TO, 1.43f, -1.43f, R_LINE_TO, 19.8f, 19.8f, R_LINE_TO, -1.42f, 1.43f,
    R_LINE_TO, -1.1f, -1.1f, R_CUBIC_TO, -0.33f, 0.25f, -0.7f, 0.45f, -1.1f, 0.59f, R_CUBIC_TO, -0.4f, 0.14f, -0.82f, 0.21f, -1.27f, 0.21f, CLOSE, MOVE_TO, 15,
    12.02f, CLOSE, R_MOVE_TO, 7, -7, R_CUBIC_TO, 0, -0.85f, -0.29f, -1.57f, -0.87f, -2.15f, R_CUBIC_TO, -0.58f, -0.58f, -1.3f, -0.87f, -2.15f, -0.87f,
    V_LINE_TO, 0.5f, R_CUBIC_TO, 1.25f, 0, 2.32f, 0.44f, 3.2f, 1.32f, R_CUBIC_TO, 0.88f, 0.88f, 1.32f, 1.95f, 1.32f, 3.2f, CLOSE, MOVE_TO, 6, 23, R_CUBIC_TO,
    -1.38f, 0, -2.56f, -0.49f, -3.54f, -1.46f, CUBIC_TO, 1.49f, 20.56f, 1, 19.38f, 1, 18, R_H_LINE_TO, 1.5f, R_CUBIC_TO, 0, 0.97f, 0.34f, 1.79f, 1.02f, 2.48f,
    ARC_TO, 3.38f, 3.38f, 0, 0, 0, 6, 21.5f, CLOSE, R_MOVE_TO, 7.6f, -6.6f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kHandGestureOffRepList, kHandGestureOffIcon, { kHandGestureOffPath, std::size(kHandGestureOffPath) })
VECTOR_ICON_REP_TEMPLATE(kHeadsetPath, CANVAS_DIMENSIONS, 20, MOVE_TO, 16, 15, R_CUBIC_TO, 0, 0.55f, -0.45f, 1, -1, 1, R_H_LINE_TO, -1, R_V_LINE_TO, -3,
    R_H_LINE_TO, 2, R_V_LINE_TO, 2, CLOSE, MOVE_TO, 6, 16, H_LINE_TO, 5, R_CUBIC_TO, -0.55f, 0, -1, -0.45f, -1, -1, R_V_LINE_TO, -2, R_H_LINE_TO, 2,
    R_V_LINE_TO, 3, CLOSE, MOVE_TO, 2, 9, R_V_LINE_TO, 6, R_CUBIC_TO, 0, 1.66f, 1.34f, 3, 3, 3, R_H_LINE_TO, 3, R_V_LINE_TO, -7, H_LINE_TO, 4, V_LINE_TO, 9,
    R_CUBIC_TO, 0, -3.87f, 2.13f, -5, 6, -5, R_CUBIC_TO, 3.87f, 0, 6, 1.13f, 6, 5, R_V_LINE_TO, 2, R_H_LINE_TO, -4, R_V_LINE_TO, 7, R_H_LINE_TO, 3, R_CUBIC_TO,
    1.66f, 0, 3, -1.34f, 3, -3, V_LINE_TO, 9, R_CUBIC_TO, 0, -4.97f, -3.03f, -7, -8, -7, R_CUBIC_TO, -4.97f, 0, -8, 2.03f, -8, 7, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kHeadsetRepList, kHeadsetIcon, { kHeadsetPath, std::size(kHeadsetPath) })
VECTOR_ICON_REP_TEMPLATE(kHelpPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 12, 2, CUBIC_TO, 6.48f, 2, 2, 6.48f, 2, 12, R_CUBIC_TO, 0, 5.52f, 4.48f, 10, 10, 10,
    R_CUBIC_TO, 5.52f, 0, 10, -4.48f, 10, -10, CUBIC_TO_SHORTHAND, 17.52f, 2, 12, 2, CLOSE, R_MOVE_TO, 1, 17, R_H_LINE_TO, -2, R_V_LINE_TO, -2, R_H_LINE_TO, 2,
    R_V_LINE_TO, 2, CLOSE, R_MOVE_TO, 2.07f, -7.75f, R_LINE_TO, -0.9f, 0.92f, CUBIC_TO, 13.45f, 12.9f, 13, 13.5f, 13, 15, R_H_LINE_TO, -2, R_V_LINE_TO, -0.5f,
    R_CUBIC_TO, 0, -1.1f, 0.45f, -2.1f, 1.17f, -2.83f, R_LINE_TO, 1.24f, -1.26f, R_CUBIC_TO, 0.37f, -0.36f, 0.59f, -0.86f, 0.59f, -1.41f, R_CUBIC_TO, 0, -1.1f,
    -0.9f, -2, -2, -2, R_CUBIC_TO, -1.1f, 0, -2, 0.9f, -2, 2, H_LINE_TO, 8, R_CUBIC_TO, 0, -2.21f, 1.79f, -4, 4, -4, R_CUBIC_TO, 2.21f, 0, 4, 1.79f, 4, 4,
    R_CUBIC_TO, 0, 0.88f, -0.36f, 1.68f, -0.93f, 2.25f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kHelpRepList, kHelpIcon, { kHelpPath, std::size(kHelpPath) })
VECTOR_ICON_REP_TEMPLATE(kHelpOutlinePath, CANVAS_DIMENSIONS, 24, MOVE_TO, 11, 18, R_H_LINE_TO, 2, R_V_LINE_TO, -2, R_H_LINE_TO, -2, R_V_LINE_TO, 2, CLOSE,
    R_MOVE_TO, 1, -16, CUBIC_TO, 6.48f, 2, 2, 6.48f, 2, 12, R_CUBIC_TO, 0, 5.52f, 4.48f, 10, 10, 10, R_CUBIC_TO, 5.52f, 0, 10, -4.48f, 10, -10,
    CUBIC_TO_SHORTHAND, 17.52f, 2, 12, 2, CLOSE, R_MOVE_TO, 0, 18, R_CUBIC_TO, -4.41f, 0, -8, -3.59f, -8, -8, R_CUBIC_TO, 0, -4.41f, 3.59f, -8, 8, -8,
    R_CUBIC_TO, 4.41f, 0, 8, 3.59f, 8, 8, R_CUBIC_TO, 0, 4.41f, -3.59f, 8, -8, 8, CLOSE, R_MOVE_TO, 0, -14, R_CUBIC_TO, -2.21f, 0, -4, 1.79f, -4, 4,
    R_H_LINE_TO, 2, R_CUBIC_TO, 0, -1.1f, 0.9f, -2, 2, -2, R_CUBIC_TO, 1.1f, 0, 2, 0.9f, 2, 2, R_CUBIC_TO, 0, 2, -3, 1.75f, -3, 5, R_H_LINE_TO, 2, R_CUBIC_TO,
    0, -2.25f, 3, -2.5f, 3, -5, R_CUBIC_TO, 0, -2.21f, -1.79f, -4, -4, -4, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kHelpOutline20Path, CANVAS_DIMENSIONS, 20, MOVE_TO, 10, 2, R_CUBIC_TO, 4.42f, 0, 8, 3.58f, 8, 8, R_CUBIC_TO, 0, 4.42f, -3.58f, 8, -8,
    8, R_CUBIC_TO, -4.42f, 0, -8, -3.58f, -8, -8, R_CUBIC_TO, 0, -4.42f, 3.58f, -8, 8, -8, CLOSE, R_MOVE_TO, 0, 14, R_CUBIC_TO, 3.31f, 0, 6, -2.69f, 6, -6,
    R_CUBIC_TO, 0, -3.31f, -2.69f, -6, -6, -6, R_CUBIC_TO, -3.31f, 0, -6, 2.69f, -6, 6, R_CUBIC_TO, 0, 3.31f, 2.69f, 6, 6, 6, CLOSE, R_MOVE_TO, -0.74f, -1.4f,
    R_V_LINE_TO, -1.39f, R_H_LINE_TO, 1.5f, R_V_LINE_TO, 1.39f, H_LINE_TO, 9.26f, CLOSE, MOVE_TO, 10, 5.6f, R_CUBIC_TO, 1.66f, 0, 3, 1.25f, 3, 2.8f, R_CUBIC_TO,
    0, 1.75f, -2.24f, 1.88f, -2.24f, 3.46f, H_LINE_TO, 9.26f, CUBIC_TO, 9.26f, 9.58f, 11.5f, 9.8f, 11.5f, 8.4f, R_CUBIC_TO, 0, -0.77f, -0.67f, -1.4f, -1.5f,
    -1.4f, R_CUBIC_TO, -0.83f, 0, -1.5f, 0.63f, -1.5f, 1.4f, H_LINE_TO, 7, R_CUBIC_TO, 0, -1.55f, 1.34f, -2.8f, 3, -2.8f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(
    kHelpOutlineRepList, kHelpOutlineIcon, { kHelpOutlinePath, std::size(kHelpOutlinePath) }, { kHelpOutline20Path, std::size(kHelpOutline20Path) })
VECTOR_ICON_REP_TEMPLATE(kHistoryPath, CANVAS_DIMENSIONS, 20, MOVE_TO, 10.81f, 17.5f, R_QUADRATIC_TO, -1.44f, 0, -2.76f, -0.53f, R_QUADRATIC_TO, -1.32f, -0.53f,
    -2.41f, -1.64f, R_LINE_TO, 1.23f, -1.23f, R_QUADRATIC_TO, 0.81f, 0.79f, 1.87f, 1.22f, R_QUADRATIC_TO, 1.05f, 0.43f, 2.11f, 0.43f, R_QUADRATIC_TO, 2.4f, 0,
    4.06f, -1.68f, R_QUADRATIC_TO, 1.67f, -1.68f, 1.67f, -4.07f, R_QUADRATIC_TO, 0, -2.4f, -1.67f, -4.07f, QUADRATIC_TO, 13.25f, 4.25f, 10.85f, 4.25f,
    R_QUADRATIC_TO, -2.37f, 0, -4.04f, 1.66f, R_QUADRATIC_TO, -1.67f, 1.66f, -1.67f, 4.28f, R_LINE_TO, 1.54f, -1.54f, R_LINE_TO, 1.21f, 1.21f, LINE_TO, 4.25f,
    13.5f, LINE_TO, 0.63f, 9.88f, R_LINE_TO, 1.23f, -1.23f, R_LINE_TO, 1.54f, 1.54f, R_QUADRATIC_TO, 0, -1.63f, 0.58f, -3.03f, R_QUADRATIC_TO, 0.58f, -1.41f,
    1.6f, -2.44f, R_QUADRATIC_TO, 1.02f, -1.03f, 2.38f, -1.62f, QUADRATIC_TO, 9.31f, 2.5f, 10.85f, 2.5f, R_QUADRATIC_TO, 1.54f, 0, 2.9f, 0.59f, R_QUADRATIC_TO,
    1.35f, 0.59f, 2.38f, 1.63f, R_QUADRATIC_TO, 1.02f, 1.03f, 1.61f, 2.38f, R_QUADRATIC_TO, 0.59f, 1.35f, 0.59f, 2.9f, R_QUADRATIC_TO, 0, 1.52f, -0.6f, 2.89f,
    R_QUADRATIC_TO, -0.6f, 1.36f, -1.62f, 2.4f, R_QUADRATIC_TO, -1.02f, 1.04f, -2.39f, 1.63f, R_QUADRATIC_TO, -1.36f, 0.59f, -2.91f, 0.59f, CLOSE, R_MOVE_TO,
    2.31f, -3.98f, R_LINE_TO, -3.15f, -3.19f, R_V_LINE_TO, -4.5f, R_H_LINE_TO, 1.75f, R_V_LINE_TO, 3.81f, R_LINE_TO, 2.63f, 2.65f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kHistoryRepList, kHistoryIcon, { kHistoryPath, std::size(kHistoryPath) })
VECTOR_ICON_REP_TEMPLATE(kHistoryChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 10, 17, R_CUBIC_TO, -1.94f, 0, -3.6f, -0.68f, -4.96f,
    -2.04f, CUBIC_TO, 3.68f, 13.6f, 3, 11.95f, 3, 10, R_H_LINE_TO, 1.5f, R_CUBIC_TO, 0, 1.52f, 0.54f, 2.81f, 1.61f, 3.89f, CUBIC_TO, 7.19f, 14.96f, 8.48f,
    15.5f, 10, 15.5f, R_CUBIC_TO, 1.52f, 0, 2.81f, -0.54f, 3.89f, -1.61f, CUBIC_TO, 14.96f, 12.81f, 15.5f, 11.52f, 15.5f, 10, R_CUBIC_TO, 0, -1.52f, -0.54f,
    -2.81f, -1.61f, -3.89f, CUBIC_TO, 12.81f, 5.04f, 11.52f, 4.5f, 10, 4.5f, R_CUBIC_TO, -0.86f, 0, -1.66f, 0.18f, -2.39f, 0.54f, ARC_TO, 5.33f, 5.33f, 0, 0, 0,
    5.77f, 6.5f, H_LINE_TO, 8, V_LINE_TO, 8, H_LINE_TO, 3, V_LINE_TO, 3, R_H_LINE_TO, 1.5f, R_V_LINE_TO, 2.71f, ARC_TO, 6.94f, 6.94f, 0, 0, 1, 6.89f, 3.73f,
    CUBIC_TO, 7.84f, 3.24f, 8.88f, 3, 10, 3, R_CUBIC_TO, 0.97f, 0, 1.88f, 0.18f, 2.73f, 0.56f, R_CUBIC_TO, 0.85f, 0.37f, 1.59f, 0.87f, 2.22f, 1.5f, R_ARC_TO,
    7.05f, 7.05f, 0, 0, 1, 1.5f, 2.22f, R_CUBIC_TO, 0.37f, 0.85f, 0.56f, 1.76f, 0.56f, 2.73f, R_CUBIC_TO, 0, 0.97f, -0.18f, 1.88f, -0.56f, 2.73f, R_ARC_TO,
    7.05f, 7.05f, 0, 0, 1, -1.5f, 2.22f, R_ARC_TO, 7.05f, 7.05f, 0, 0, 1, -2.22f, 1.5f, ARC_TO, 6.73f, 6.73f, 0, 0, 1, 10, 17, CLOSE, R_MOVE_TO, 2.08f, -4.17f,
    LINE_TO, 9.25f, 10, V_LINE_TO, 6, R_H_LINE_TO, 1.5f, R_V_LINE_TO, 3.38f, R_LINE_TO, 2.4f, 2.4f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kHistoryChromeRefreshRepList, kHistoryChromeRefreshIcon, { kHistoryChromeRefreshPath, std::size(kHistoryChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kHttpsValidPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 6.07f, 22.18f, R_ARC_TO, 2.19f, 2.19f, 0, 0, 1, -1.6f, -0.67f, R_ARC_TO, 2.19f, 2.19f,
    0, 0, 1, -0.67f, -1.61f, R_V_LINE_TO, -9.85f, R_CUBIC_TO, 0, -0.62f, 0.22f, -1.16f, 0.67f, -1.61f, R_ARC_TO, 2.19f, 2.19f, 0, 0, 1, 1.61f, -0.67f,
    R_H_LINE_TO, 0.84f, V_LINE_TO, 5.95f, R_CUBIC_TO, 0, -1.42f, 0.5f, -2.62f, 1.49f, -3.62f, CUBIC_TO, 9.39f, 1.34f, 10.59f, 0.84f, 12, 0.84f, R_CUBIC_TO,
    1.41f, 0, 2.61f, 0.5f, 3.6f, 1.49f, R_CUBIC_TO, 0.99f, 1, 1.49f, 2.2f, 1.49f, 3.62f, R_V_LINE_TO, 1.82f, R_H_LINE_TO, 0.84f, R_CUBIC_TO, 0.63f, 0, 1.16f,
    0.22f, 1.61f, 0.67f, R_CUBIC_TO, 0.45f, 0.45f, 0.67f, 0.99f, 0.67f, 1.61f, R_V_LINE_TO, 9.86f, R_ARC_TO, 2.19f, 2.19f, 0, 0, 1, -0.67f, 1.61f, R_ARC_TO,
    2.19f, 2.19f, 0, 0, 1, -1.6f, 0.67f, CLOSE, R_MOVE_TO, 0, -2.27f, R_H_LINE_TO, 11.86f, R_V_LINE_TO, -9.85f, H_LINE_TO, 6.07f, CLOSE, MOVE_TO, 12, 16.98f,
    R_CUBIC_TO, 0.55f, 0, 1.02f, -0.19f, 1.41f, -0.58f, R_CUBIC_TO, 0.39f, -0.39f, 0.59f, -0.86f, 0.59f, -1.41f, R_CUBIC_TO, 0, -0.55f, -0.19f, -1.02f, -0.59f,
    -1.41f, ARC_TO, 1.94f, 1.94f, 0, 0, 0, 12, 12.98f, R_CUBIC_TO, -0.55f, 0, -1.02f, 0.2f, -1.41f, 0.59f, R_CUBIC_TO, -0.39f, 0.39f, -0.59f, 0.86f, -0.59f,
    1.41f, R_CUBIC_TO, 0, 0.55f, 0.2f, 1.02f, 0.59f, 1.42f, R_CUBIC_TO, 0.39f, 0.39f, 0.86f, 0.59f, 1.41f, 0.59f, CLOSE, MOVE_TO, 9.18f, 7.78f, R_H_LINE_TO,
    5.63f, V_LINE_TO, 5.95f, R_CUBIC_TO, 0, -0.79f, -0.27f, -1.46f, -0.82f, -2.01f, ARC_TO, 2.7f, 2.7f, 0, 0, 0, 12, 3.12f, R_CUBIC_TO, -0.78f, 0, -1.45f,
    0.27f, -2, 0.82f, R_ARC_TO, 2.74f, 2.74f, 0, 0, 0, -0.82f, 2.01f, CLOSE, MOVE_TO, 6.07f, 19.91f, R_V_LINE_TO, -9.85f, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kHttpsValid20Path, CANVAS_DIMENSIONS, 20, MOVE_TO, 5.56f, 18.16f, R_CUBIC_TO, -0.48f, 0, -0.88f, -0.17f, -1.22f, -0.51f, R_ARC_TO,
    1.68f, 1.68f, 0, 0, 1, -0.5f, -1.22f, V_LINE_TO, 8.54f, R_CUBIC_TO, 0, -0.47f, 0.17f, -0.88f, 0.51f, -1.22f, R_CUBIC_TO, 0.34f, -0.34f, 0.75f, -0.51f,
    1.22f, -0.51f, R_H_LINE_TO, 0.37f, V_LINE_TO, 4.96f, R_CUBIC_TO, 0, -1.13f, 0.4f, -2.1f, 1.19f, -2.89f, CUBIC_TO, 7.91f, 1.27f, 8.88f, 0.87f, 10, 0.87f,
    R_CUBIC_TO, 1.13f, 0, 2.09f, 0.4f, 2.88f, 1.2f, R_CUBIC_TO, 0.79f, 0.8f, 1.19f, 1.76f, 1.19f, 2.9f, R_V_LINE_TO, 1.86f, R_H_LINE_TO, 0.37f, R_CUBIC_TO,
    0.47f, 0, 0.88f, 0.17f, 1.22f, 0.51f, R_CUBIC_TO, 0.34f, 0.34f, 0.51f, 0.75f, 0.51f, 1.22f, R_V_LINE_TO, 7.88f, R_CUBIC_TO, 0, 0.48f, -0.17f, 0.88f, -0.51f,
    1.22f, R_ARC_TO, 1.67f, 1.67f, 0, 0, 1, -1.22f, 0.51f, CLOSE, R_MOVE_TO, 0, -1.73f, R_H_LINE_TO, 8.88f, V_LINE_TO, 8.54f, H_LINE_TO, 5.56f, CLOSE,
    R_MOVE_TO, 4.45f, -2.44f, R_CUBIC_TO, 0.41f, 0, 0.77f, -0.15f, 1.06f, -0.44f, R_CUBIC_TO, 0.29f, -0.29f, 0.44f, -0.65f, 0.44f, -1.06f, R_CUBIC_TO, 0,
    -0.41f, -0.15f, -0.76f, -0.44f, -1.06f, R_ARC_TO, 1.47f, 1.47f, 0, 0, 0, -1.06f, -0.44f, R_CUBIC_TO, -0.41f, 0, -0.77f, 0.15f, -1.06f, 0.44f, R_ARC_TO,
    1.45f, 1.45f, 0, 0, 0, -0.44f, 1.06f, R_CUBIC_TO, 0, 0.41f, 0.15f, 0.77f, 0.44f, 1.06f, R_CUBIC_TO, 0.3f, 0.29f, 0.65f, 0.44f, 1.06f, 0.44f, CLOSE, MOVE_TO,
    7.66f, 6.82f, R_H_LINE_TO, 4.69f, V_LINE_TO, 4.96f, R_CUBIC_TO, 0, -0.66f, -0.23f, -1.22f, -0.68f, -1.67f, R_CUBIC_TO, -0.45f, -0.46f, -1.01f, -0.69f,
    -1.66f, -0.69f, R_CUBIC_TO, -0.66f, 0, -1.21f, 0.23f, -1.66f, 0.69f, R_ARC_TO, 2.29f, 2.29f, 0, 0, 0, -0.68f, 1.67f, CLOSE, R_MOVE_TO, -2.1f, 9.61f,
    V_LINE_TO, 8.54f, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kHttpsValid16Path, CANVAS_DIMENSIONS, 16, MOVE_TO, 4.51f, 14.69f, R_CUBIC_TO, -0.45f, 0, -0.83f, -0.16f, -1.15f, -0.48f, R_ARC_TO,
    1.58f, 1.58f, 0, 0, 1, -0.48f, -1.15f, V_LINE_TO, 6.89f, R_CUBIC_TO, 0, -0.45f, 0.16f, -0.84f, 0.48f, -1.16f, R_CUBIC_TO, 0.32f, -0.32f, 0.7f, -0.48f,
    1.15f, -0.48f, R_H_LINE_TO, 0.15f, V_LINE_TO, 3.93f, R_CUBIC_TO, 0, -0.94f, 0.32f, -1.73f, 0.97f, -2.39f, R_ARC_TO, 3.22f, 3.22f, 0, 0, 1, 2.37f, -0.98f,
    R_CUBIC_TO, 0.93f, 0, 1.72f, 0.33f, 2.37f, 0.98f, R_CUBIC_TO, 0.65f, 0.66f, 0.97f, 1.45f, 0.97f, 2.39f, V_LINE_TO, 5.25f, R_H_LINE_TO, 0.15f, R_CUBIC_TO,
    0.45f, 0, 0.83f, 0.16f, 1.15f, 0.48f, R_CUBIC_TO, 0.32f, 0.32f, 0.48f, 0.71f, 0.48f, 1.16f, R_V_LINE_TO, 6.17f, R_CUBIC_TO, 0, 0.45f, -0.16f, 0.83f, -0.48f,
    1.15f, R_CUBIC_TO, -0.32f, 0.32f, -0.7f, 0.48f, -1.16f, 0.48f, CLOSE, R_MOVE_TO, 0, -1.63f, R_H_LINE_TO, 6.98f, V_LINE_TO, 6.89f, H_LINE_TO, 4.51f, CLOSE,
    R_MOVE_TO, 3.49f, -1.89f, R_CUBIC_TO, 0.33f, 0, 0.61f, -0.12f, 0.85f, -0.36f, R_CUBIC_TO, 0.23f, -0.23f, 0.35f, -0.51f, 0.35f, -0.85f, R_CUBIC_TO, 0,
    -0.33f, -0.12f, -0.61f, -0.35f, -0.85f, R_ARC_TO, 1.17f, 1.17f, 0, 0, 0, -0.85f, -0.35f, R_CUBIC_TO, -0.33f, 0, -0.61f, 0.12f, -0.85f, 0.35f, R_CUBIC_TO,
    -0.23f, 0.23f, -0.35f, 0.52f, -0.35f, 0.85f, R_CUBIC_TO, 0, 0.33f, 0.12f, 0.61f, 0.35f, 0.84f, R_CUBIC_TO, 0.24f, 0.24f, 0.52f, 0.35f, 0.85f, 0.35f, CLOSE,
    MOVE_TO, 6.29f, 5.25f, R_H_LINE_TO, 3.41f, V_LINE_TO, 3.93f, R_CUBIC_TO, 0, -0.48f, -0.16f, -0.89f, -0.49f, -1.23f, ARC_TO, 1.62f, 1.62f, 0, 0, 0, 8, 2.19f,
    R_CUBIC_TO, -0.48f, 0, -0.89f, 0.17f, -1.22f, 0.51f, R_ARC_TO, 1.7f, 1.7f, 0, 0, 0, -0.49f, 1.23f, CLOSE, R_MOVE_TO, -1.78f, 7.81f, V_LINE_TO, 6.89f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kHttpsValidRepList, kHttpsValidIcon, { kHttpsValidPath, std::size(kHttpsValidPath) },
    { kHttpsValid20Path, std::size(kHttpsValid20Path) }, { kHttpsValid16Path, std::size(kHttpsValid16Path) })
VECTOR_ICON_REP_TEMPLATE(kIframePath, CANVAS_DIMENSIONS, 20, MOVE_TO, 10.09f, 10.91f, R_H_LINE_TO, 3.82f, V_LINE_TO, 9.59f, R_H_LINE_TO, -3.82f, CLOSE,
    R_MOVE_TO, -1.18f, 1.18f, V_LINE_TO, 8.41f, R_H_LINE_TO, 6.18f, R_V_LINE_TO, 3.68f, CLOSE, MOVE_TO, 3.56f, 16.17f, R_CUBIC_TO, -0.48f, 0, -0.89f, -0.17f,
    -1.22f, -0.5f, R_ARC_TO, 1.67f, 1.67f, 0, 0, 1, -0.5f, -1.23f, V_LINE_TO, 5.56f, R_CUBIC_TO, 0, -0.48f, 0.17f, -0.89f, 0.5f, -1.22f, R_CUBIC_TO, 0.34f,
    -0.34f, 0.75f, -0.5f, 1.22f, -0.5f, H_LINE_TO, 16.44f, R_CUBIC_TO, 0.48f, 0, 0.89f, 0.17f, 1.22f, 0.5f, R_CUBIC_TO, 0.34f, 0.34f, 0.5f, 0.75f, 0.5f, 1.23f,
    R_V_LINE_TO, 8.88f, R_CUBIC_TO, 0, 0.48f, -0.17f, 0.89f, -0.5f, 1.22f, R_CUBIC_TO, -0.34f, 0.34f, -0.75f, 0.5f, -1.22f, 0.5f, CLOSE, R_MOVE_TO, 0, -1.73f,
    H_LINE_TO, 16.44f, V_LINE_TO, 7.17f, H_LINE_TO, 3.56f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kIframeRepList, kIframeIcon, { kIframePath, std::size(kIframePath) })
VECTOR_ICON_REP_TEMPLATE(kIframeOffPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, R_MOVE_TO, 16.81f, 18.94f, R_LINE_TO, -2.79f, -2.77f, H_LINE_TO, 3.56f,
    R_CUBIC_TO, -0.48f, 0, -0.89f, -0.17f, -1.22f, -0.5f, R_ARC_TO, 1.67f, 1.67f, 0, 0, 1, -0.5f, -1.23f, V_LINE_TO, 5.56f, R_CUBIC_TO, 0, -0.45f, 0.16f,
    -0.84f, 0.48f, -1.17f, R_CUBIC_TO, 0.32f, -0.33f, 0.71f, -0.51f, 1.18f, -0.54f, R_H_LINE_TO, 0.23f, V_LINE_TO, 5.84f, LINE_TO, 1.14f, 3.27f, R_LINE_TO,
    1.11f, -1.09f, R_LINE_TO, 15.65f, 15.64f, CLOSE, MOVE_TO, 3.56f, 14.44f, R_H_LINE_TO, 8.73f, LINE_TO, 5.02f, 7.17f, H_LINE_TO, 3.56f, CLOSE, R_MOVE_TO,
    14.23f, 1.05f, R_LINE_TO, -1.35f, -1.35f, V_LINE_TO, 7.17f, H_LINE_TO, 9.47f, LINE_TO, 6.14f, 3.83f, H_LINE_TO, 16.44f, R_CUBIC_TO, 0.48f, 0, 0.89f, 0.17f,
    1.22f, 0.5f, R_CUBIC_TO, 0.34f, 0.34f, 0.5f, 0.75f, 0.5f, 1.22f, R_V_LINE_TO, 8.88f, R_CUBIC_TO, 0, 0.2f, -0.04f, 0.4f, -0.1f, 0.59f, R_CUBIC_TO, -0.07f,
    0.19f, -0.16f, 0.34f, -0.27f, 0.46f, CLOSE, R_MOVE_TO, -2.7f, -2.7f, R_LINE_TO, -1.18f, -1.18f, V_LINE_TO, 9.59f, R_H_LINE_TO, -2.01f, R_LINE_TO, -1.18f,
    -1.18f, R_H_LINE_TO, 4.38f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kIframeOffRepList, kIframeOffIcon, { kIframeOffPath, std::size(kIframeOffPath) })
VECTOR_ICON_REP_TEMPLATE(kImageSearchPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 3.6f, 14.4f, CUBIC_TO, 3.27f, 14.4f, 2.98f, 14.28f, 2.75f, 14.05f, CUBIC_TO, 2.52f,
    13.82f, 2.4f, 13.54f, 2.4f, 13.2f, LINE_TO, 2.4f, 4.4f, CUBIC_TO, 2.4f, 4.07f, 2.52f, 3.79f, 2.75f, 3.55f, CUBIC_TO, 2.98f, 3.32f, 3.27f, 3.2f, 3.6f, 3.2f,
    LINE_TO, 6.8f, 3.2f, LINE_TO, 6.8f, 4.4f, LINE_TO, 3.6f, 4.4f, LINE_TO, 3.6f, 13.2f, LINE_TO, 12.4f, 13.2f, LINE_TO, 12.4f, 9.35f, LINE_TO, 13.6f, 10.55f,
    LINE_TO, 13.6f, 13.2f, CUBIC_TO, 13.6f, 13.54f, 13.48f, 13.82f, 13.25f, 14.05f, CUBIC_TO, 13.02f, 14.28f, 12.73f, 14.4f, 12.4f, 14.4f, CLOSE, MOVE_TO, 4.4f,
    12, LINE_TO, 6.2f, 9.6f, LINE_TO, 7.4f, 11.2f, LINE_TO, 9.2f, 8.8f, LINE_TO, 11.6f, 12, CLOSE, MOVE_TO, 14.35f, 9.6f, LINE_TO, 12.3f, 7.55f, CUBIC_TO,
    12.08f, 7.7f, 11.84f, 7.8f, 11.59f, 7.88f, CUBIC_TO, 11.34f, 7.96f, 11.08f, 8, 10.8f, 8, CUBIC_TO, 10.02f, 8, 9.36f, 7.73f, 8.82f, 7.18f, CUBIC_TO, 8.27f,
    6.64f, 8, 5.98f, 8, 5.2f, CUBIC_TO, 8, 4.42f, 8.27f, 3.76f, 8.82f, 3.22f, CUBIC_TO, 9.36f, 2.67f, 10.02f, 2.4f, 10.8f, 2.4f, CUBIC_TO, 11.58f, 2.4f, 12.24f,
    2.67f, 12.78f, 3.22f, CUBIC_TO, 13.33f, 3.76f, 13.6f, 4.42f, 13.6f, 5.2f, CUBIC_TO, 13.6f, 5.48f, 13.56f, 5.74f, 13.48f, 5.99f, CUBIC_TO, 13.41f, 6.24f,
    13.29f, 6.48f, 13.15f, 6.7f, LINE_TO, 15.2f, 8.75f, CLOSE, MOVE_TO, 10.8f, 6.8f, CUBIC_TO, 11.25f, 6.8f, 11.62f, 6.64f, 11.93f, 6.33f, CUBIC_TO, 12.25f,
    6.02f, 12.4f, 5.64f, 12.4f, 5.2f, CUBIC_TO, 12.4f, 4.75f, 12.25f, 4.38f, 11.93f, 4.07f, CUBIC_TO, 11.62f, 3.75f, 11.25f, 3.6f, 10.8f, 3.6f, CUBIC_TO,
    10.36f, 3.6f, 9.98f, 3.75f, 9.67f, 4.07f, CUBIC_TO, 9.36f, 4.38f, 9.2f, 4.75f, 9.2f, 5.2f, CUBIC_TO, 9.2f, 5.64f, 9.36f, 6.02f, 9.67f, 6.33f, CUBIC_TO,
    9.98f, 6.64f, 10.36f, 6.8f, 10.8f, 6.8f, CLOSE, MOVE_TO, 10.8f, 6.8f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kImageSearchRepList, kImageSearchIcon, { kImageSearchPath, std::size(kImageSearchPath) })
VECTOR_ICON_REP_TEMPLATE(kInfoOutlinePath, CANVAS_DIMENSIONS, 32, MOVE_TO, 16, 2, CUBIC_TO, 8.27f, 2, 2, 8.27f, 2, 16, CUBIC_TO, 2, 23.73f, 8.27f, 30, 16, 30,
    CUBIC_TO, 23.73f, 30, 30, 23.73f, 30, 16, CUBIC_TO, 30, 8.27f, 23.73f, 2, 16, 2, CLOSE, MOVE_TO, 16, 27.2f, CUBIC_TO, 9.83f, 27.2f, 4.8f, 22.17f, 4.8f, 16,
    CUBIC_TO, 4.8f, 9.83f, 9.83f, 4.8f, 16, 4.8f, CUBIC_TO, 22.17f, 4.8f, 27.2f, 9.83f, 27.2f, 16, CUBIC_TO, 27.2f, 22.17f, 22.17f, 27.2f, 16, 27.2f, CLOSE,
    MOVE_TO, 14.6f, 23, LINE_TO, 17.4f, 23, LINE_TO, 17.4f, 14.6f, LINE_TO, 14.6f, 14.6f, LINE_TO, 14.6f, 23, CLOSE, MOVE_TO, 14.6f, 11.8f, LINE_TO, 17.4f,
    11.8f, LINE_TO, 17.4f, 9, LINE_TO, 14.6f, 9, LINE_TO, 14.6f, 11.8f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kInfoOutlineRepList, kInfoOutlineIcon, { kInfoOutlinePath, std::size(kInfoOutlinePath) })
VECTOR_ICON_REP_TEMPLATE(kInfoRefreshPath, CANVAS_DIMENSIONS, 16, FILL_RULE_NONZERO, MOVE_TO, 7.34f, 11.26f, R_H_LINE_TO, 1.32f, V_LINE_TO, 7.2f, H_LINE_TO,
    7.34f, CLOSE, R_MOVE_TO, 0.66f, -5.18f, R_ARC_TO, 0.66f, 0.66f, 0, 0, 0, 0.48f, -0.19f, R_ARC_TO, 0.66f, 0.66f, 0, 0, 0, 0.2f, -0.48f, R_ARC_TO, 0.67f,
    0.67f, 0, 0, 0, -0.2f, -0.48f, R_ARC_TO, 0.64f, 0.64f, 0, 0, 0, -0.48f, -0.2f, R_ARC_TO, 0.66f, 0.66f, 0, 0, 0, -0.48f, 0.2f, R_ARC_TO, 0.64f, 0.64f, 0, 0,
    0, -0.2f, 0.48f, R_CUBIC_TO, 0, 0.2f, 0.07f, 0.36f, 0.2f, 0.49f, R_ARC_TO, 0.64f, 0.64f, 0, 0, 0, 0.48f, 0.2f, CLOSE, R_MOVE_TO, 0.01f, 8.46f, R_CUBIC_TO,
    -0.9f, 0, -1.75f, -0.17f, -2.54f, -0.51f, R_ARC_TO, 6.52f, 6.52f, 0, 0, 1, -2.08f, -1.4f, R_ARC_TO, 6.52f, 6.52f, 0, 0, 1, -1.4f, -2.08f, R_ARC_TO, 6.33f,
    6.33f, 0, 0, 1, -0.51f, -2.55f, R_CUBIC_TO, 0, -0.91f, 0.17f, -1.75f, 0.51f, -2.54f, ARC_TO, 6.53f, 6.53f, 0, 0, 1, 3.38f, 3.38f, ARC_TO, 6.52f, 6.52f, 0,
    0, 1, 5.46f, 1.98f, R_ARC_TO, 6.33f, 6.33f, 0, 0, 1, 2.55f, -0.51f, R_CUBIC_TO, 0.91f, 0, 1.75f, 0.17f, 2.54f, 0.51f, R_CUBIC_TO, 0.79f, 0.34f, 1.48f, 0.8f,
    2.07f, 1.4f, R_ARC_TO, 6.5f, 6.5f, 0, 0, 1, 1.4f, 2.08f, R_ARC_TO, 6.29f, 6.29f, 0, 0, 1, 0.51f, 2.54f, R_CUBIC_TO, 0, 0.9f, -0.17f, 1.75f, -0.51f, 2.54f,
    R_ARC_TO, 6.52f, 6.52f, 0, 0, 1, -1.4f, 2.08f, R_ARC_TO, 6.5f, 6.5f, 0, 0, 1, -2.08f, 1.4f, R_ARC_TO, 6.29f, 6.29f, 0, 0, 1, -2.54f, 0.51f, CLOSE, MOVE_TO,
    8, 13.15f, R_CUBIC_TO, 1.43f, 0, 2.65f, -0.5f, 3.65f, -1.5f, R_CUBIC_TO, 1, -1, 1.5f, -2.22f, 1.5f, -3.65f, R_CUBIC_TO, 0, -1.43f, -0.5f, -2.65f, -1.5f,
    -3.65f, CUBIC_TO_SHORTHAND, 9.43f, 2.85f, 8, 2.85f, R_CUBIC_TO, -1.43f, 0, -2.65f, 0.5f, -3.65f, 1.5f, CUBIC_TO_SHORTHAND, 2.85f, 6.57f, 2.85f, 8,
    R_CUBIC_TO, 0, 1.43f, 0.5f, 2.65f, 1.5f, 3.65f, R_CUBIC_TO, 1, 1, 2.22f, 1.5f, 3.65f, 1.5f, CLOSE, MOVE_TO, 8, 8, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kInfoRefreshRepList, kInfoRefreshIcon, { kInfoRefreshPath, std::size(kInfoRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kInsertDriveFileOutlinePath, CANVAS_DIMENSIONS, 24, MOVE_TO, 14, 2, H_LINE_TO, 6, R_CUBIC_TO, -1.1f, 0, -1.99f, 0.9f, -1.99f, 2,
    LINE_TO, 4, 20, R_CUBIC_TO, 0, 1.1f, 0.89f, 2, 1.99f, 2, H_LINE_TO, 18, R_CUBIC_TO, 1.1f, 0, 2, -0.9f, 2, -2, V_LINE_TO, 8, R_LINE_TO, -6, -6, CLOSE,
    MOVE_TO, 6, 20, V_LINE_TO, 4, R_H_LINE_TO, 7, R_V_LINE_TO, 5, R_H_LINE_TO, 5, R_V_LINE_TO, 11, H_LINE_TO, 6, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kInsertDriveFileOutlineRepList, kInsertDriveFileOutlineIcon, { kInsertDriveFileOutlinePath, std::size(kInsertDriveFileOutlinePath) })
VECTOR_ICON_REP_TEMPLATE(kInstallDesktopPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 7, 17, R_V_LINE_TO, -2, H_LINE_TO, 3.5f, R_CUBIC_TO, -0.41f, 0,
    -0.77f, -0.15f, -1.06f, -0.44f, ARC_TO, 1.45f, 1.45f, 0, 0, 1, 2, 13.5f, V_LINE_TO, 4.49f, R_CUBIC_TO, 0, -0.41f, 0.15f, -0.76f, 0.44f, -1.05f, ARC_TO,
    1.44f, 1.44f, 0, 0, 1, 3.5f, 3, H_LINE_TO, 11, R_V_LINE_TO, 1.5f, H_LINE_TO, 3.5f, R_V_LINE_TO, 9, R_H_LINE_TO, 13, V_LINE_TO, 11, H_LINE_TO, 18,
    R_V_LINE_TO, 2.5f, R_CUBIC_TO, 0, 0.42f, -0.15f, 0.77f, -0.44f, 1.06f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 16.5f, 15, H_LINE_TO, 13, R_V_LINE_TO, 2, CLOSE,
    R_MOVE_TO, 7.48f, -6, LINE_TO, 11, 7.52f, R_LINE_TO, 1.06f, -1.06f, R_LINE_TO, 1.69f, 1.69f, V_LINE_TO, 3, R_H_LINE_TO, 1.5f, R_V_LINE_TO, 5.11f, R_LINE_TO,
    1.69f, -1.69f, LINE_TO, 18, 7.48f, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kInstallDesktop16Path, CANVAS_DIMENSIONS, 16, FILL_RULE_NONZERO, MOVE_TO, 5.53f, 13.73f, R_V_LINE_TO, -1.6f, R_H_LINE_TO, -2.68f,
    R_CUBIC_TO, -0.38f, 0, -0.71f, -0.14f, -0.98f, -0.41f, R_ARC_TO, 1.33f, 1.33f, 0, 0, 1, -0.4f, -0.98f, V_LINE_TO, 3.65f, R_CUBIC_TO, 0, -0.38f, 0.13f,
    -0.71f, 0.4f, -0.98f, R_CUBIC_TO, 0.27f, -0.27f, 0.6f, -0.4f, 0.98f, -0.4f, R_H_LINE_TO, 5.95f, R_V_LINE_TO, 1.38f, H_LINE_TO, 2.85f, R_V_LINE_TO, 7.11f,
    R_H_LINE_TO, 10.3f, V_LINE_TO, 8.68f, R_H_LINE_TO, 1.38f, R_V_LINE_TO, 2.07f, R_CUBIC_TO, 0, 0.38f, -0.13f, 0.71f, -0.4f, 0.98f, R_ARC_TO, 1.35f, 1.35f, 0,
    0, 1, -0.98f, 0.4f, R_H_LINE_TO, -2.68f, R_V_LINE_TO, 1.6f, CLOSE, R_MOVE_TO, 6.06f, -5, LINE_TO, 8.76f, 5.91f, R_LINE_TO, 0.89f, -0.89f, R_LINE_TO, 1.32f,
    1.32f, V_LINE_TO, 2.27f, R_H_LINE_TO, 1.26f, R_V_LINE_TO, 4.04f, R_LINE_TO, 1.32f, -1.32f, R_LINE_TO, 0.9f, 0.9f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kInstallDesktopRepList, kInstallDesktopIcon, { kInstallDesktopPath, std::size(kInstallDesktopPath) },
    { kInstallDesktop16Path, std::size(kInstallDesktop16Path) })
VECTOR_ICON_REP_TEMPLATE(kInstallDesktopOffPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, R_MOVE_TO, 14.36f, 15.64f, R_H_LINE_TO, -0.51f, R_V_LINE_TO, 2.54f,
    R_CUBIC_TO, 0, 0.39f, -0.32f, 0.71f, -0.71f, 0.71f, H_LINE_TO, 6.76f, R_CUBIC_TO, -0.39f, 0, -0.71f, -0.32f, -0.71f, -0.71f, R_V_LINE_TO, -2.54f,
    R_H_LINE_TO, -4.52f, R_CUBIC_TO, -0.85f, 0, -1.54f, -0.69f, -1.54f, -1.54f, V_LINE_TO, 2.65f, R_CUBIC_TO, 0, -0.85f, 0.69f, -1.54f, 1.54f, -1.54f,
    R_H_LINE_TO, 0.56f, R_LINE_TO, 0, 0, R_CUBIC_TO, 0.31f, -0.05f, 0.63f, 0.05f, 0.86f, 0.28f, LINE_TO, 19.03f, 17.46f, R_CUBIC_TO, 0.39f, 0.39f, 0.39f, 1.03f,
    0, 1.42f, R_CUBIC_TO, -0.39f, 0.39f, -1.03f, 0.39f, -1.42f, 0, CLOSE, MOVE_TO, 1.99f, 3.27f, R_CUBIC_TO, -0.03f, 0.07f, -0.04f, 0.14f, -0.04f, 0.22f,
    R_V_LINE_TO, 9.77f, R_CUBIC_TO, 0, 0.35f, 0.28f, 0.63f, 0.63f, 0.63f, H_LINE_TO, 12.61f, CLOSE, MOVE_TO, 4.77f, 1.11f, H_LINE_TO, 10.86f, V_LINE_TO, 2.86f,
    H_LINE_TO, 6.52f, CLOSE, MOVE_TO, 17.52f, 13.85f, R_CUBIC_TO, 0.25f, -0.08f, 0.43f, -0.32f, 0.43f, -0.6f, R_V_LINE_TO, -1.97f, R_H_LINE_TO, 1.95f,
    R_V_LINE_TO, 2.81f, R_CUBIC_TO, 0, 0.58f, -0.32f, 1.08f, -0.79f, 1.35f, CLOSE, MOVE_TO, 14.71f, 11, LINE_TO, 11.14f, 7.43f, R_CUBIC_TO, -0.39f, -0.39f,
    -0.39f, -1.03f, 0, -1.42f, R_CUBIC_TO, 0.39f, -0.39f, 1.03f, -0.39f, 1.42f, 0, R_LINE_TO, 1.85f, 1.85f, V_LINE_TO, 1.82f, R_CUBIC_TO, 0, -0.56f, 0.45f,
    -1.01f, 1.01f, -1.01f, R_CUBIC_TO, 0.56f, 0, 1.01f, 0.45f, 1.01f, 1.01f, V_LINE_TO, 7.86f, LINE_TO, 18.28f, 6, R_CUBIC_TO, 0.39f, -0.39f, 1.03f, -0.39f,
    1.42f, 0, R_CUBIC_TO, 0.39f, 0.39f, 0.39f, 1.03f, 0, 1.42f, R_LINE_TO, -3.57f, 3.57f, R_CUBIC_TO, -0.19f, 0.19f, -0.45f, 0.29f, -0.71f, 0.29f, R_CUBIC_TO,
    -0.26f, 0, -0.52f, -0.1f, -0.71f, -0.29f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kInstallDesktopOffRepList, kInstallDesktopOffIcon, { kInstallDesktopOffPath, std::size(kInstallDesktopOffPath) })
VECTOR_ICON_REP_TEMPLATE(kKeyboardPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 20, 7, R_V_LINE_TO, 10, H_LINE_TO, 4, V_LINE_TO, 7, R_H_LINE_TO, 16, R_MOVE_TO, 0, -2,
    H_LINE_TO, 4, R_CUBIC_TO, -1.1f, 0, -1.99f, 0.9f, -1.99f, 2, LINE_TO, 2, 17, R_CUBIC_TO, 0, 1.1f, 0.9f, 2, 2, 2, R_H_LINE_TO, 16, R_CUBIC_TO, 1.1f, 0, 2,
    -0.9f, 2, -2, V_LINE_TO, 7, R_CUBIC_TO, 0, -1.1f, -0.9f, -2, -2, -2, CLOSE, R_MOVE_TO, -9, 3, R_H_LINE_TO, 2, R_V_LINE_TO, 2, R_H_LINE_TO, -2, CLOSE,
    R_MOVE_TO, 0, 3, R_H_LINE_TO, 2, R_V_LINE_TO, 2, R_H_LINE_TO, -2, CLOSE, MOVE_TO, 8, 8, R_H_LINE_TO, 2, R_V_LINE_TO, 2, H_LINE_TO, 8, CLOSE, R_MOVE_TO, 0,
    3, R_H_LINE_TO, 2, R_V_LINE_TO, 2, H_LINE_TO, 8, CLOSE, R_MOVE_TO, -3, 0, R_H_LINE_TO, 2, R_V_LINE_TO, 2, H_LINE_TO, 5, CLOSE, R_MOVE_TO, 0, -3,
    R_H_LINE_TO, 2, R_V_LINE_TO, 2, H_LINE_TO, 5, CLOSE, R_MOVE_TO, 3, 6, R_H_LINE_TO, 8, R_V_LINE_TO, 2, H_LINE_TO, 8, CLOSE, R_MOVE_TO, 6, -3, R_H_LINE_TO, 2,
    R_V_LINE_TO, 2, R_H_LINE_TO, -2, CLOSE, R_MOVE_TO, 0, -3, R_H_LINE_TO, 2, R_V_LINE_TO, 2, R_H_LINE_TO, -2, CLOSE, R_MOVE_TO, 3, 3, R_H_LINE_TO, 2,
    R_V_LINE_TO, 2, R_H_LINE_TO, -2, CLOSE, R_MOVE_TO, 0, -3, R_H_LINE_TO, 2, R_V_LINE_TO, 2, R_H_LINE_TO, -2, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kKeyboardRepList, kKeyboardIcon, { kKeyboardPath, std::size(kKeyboardPath) })
VECTOR_ICON_REP_TEMPLATE(kKeyboardLockPath, CANVAS_DIMENSIONS, 960, FILL_RULE_NONZERO, MOVE_TO, 160, 680, R_V_LINE_TO, -400, R_V_LINE_TO, 400, CLOSE, R_MOVE_TO,
    40, -160, R_H_LINE_TO, 80, R_V_LINE_TO, -80, R_H_LINE_TO, -80, R_V_LINE_TO, 80, CLOSE, R_MOVE_TO, 120, 0, R_H_LINE_TO, 80, R_V_LINE_TO, -80, R_H_LINE_TO,
    -80, R_V_LINE_TO, 80, CLOSE, R_MOVE_TO, 120, 0, R_H_LINE_TO, 80, R_V_LINE_TO, -80, R_H_LINE_TO, -80, R_V_LINE_TO, 80, CLOSE, R_MOVE_TO, 120, 0, R_H_LINE_TO,
    80, R_V_LINE_TO, -80, R_H_LINE_TO, -80, R_V_LINE_TO, 80, CLOSE, MOVE_TO, 200, 400, R_H_LINE_TO, 80, R_V_LINE_TO, -80, R_H_LINE_TO, -80, R_V_LINE_TO, 80,
    CLOSE, R_MOVE_TO, 120, 0, R_H_LINE_TO, 80, R_V_LINE_TO, -80, R_H_LINE_TO, -80, R_V_LINE_TO, 80, CLOSE, R_MOVE_TO, 120, 0, R_H_LINE_TO, 80, R_V_LINE_TO, -80,
    R_H_LINE_TO, -80, R_V_LINE_TO, 80, CLOSE, R_MOVE_TO, 120, 0, R_H_LINE_TO, 80, R_V_LINE_TO, -80, R_H_LINE_TO, -80, R_V_LINE_TO, 80, CLOSE, R_MOVE_TO, 120, 0,
    R_H_LINE_TO, 80, R_V_LINE_TO, -80, R_H_LINE_TO, -80, R_V_LINE_TO, 80, CLOSE, R_MOVE_TO, 0, 97, R_QUADRATIC_TO, 18, -8, 38.5f, -12.5f,
    QUADRATIC_TO_SHORTHAND, 760, 480, R_V_LINE_TO, -40, R_H_LINE_TO, -80, R_V_LINE_TO, 57, CLOSE, MOVE_TO, 320, 640, R_H_LINE_TO, 244, R_QUADRATIC_TO, 5, -23,
    14, -43, R_QUADRATIC_TO, 9, -20, 22, -37, H_LINE_TO, 320, R_V_LINE_TO, 80, CLOSE, MOVE_TO, 160, 760, R_QUADRATIC_TO, -33, 0, -56.5f, -23.5f,
    QUADRATIC_TO_SHORTHAND, 80, 680, R_V_LINE_TO, -400, R_QUADRATIC_TO, 0, -33, 23.5f, -56.5f, QUADRATIC_TO_SHORTHAND, 160, 200, R_H_LINE_TO, 640,
    R_QUADRATIC_TO, 33, 0, 56.5f, 23.5f, QUADRATIC_TO_SHORTHAND, 880, 280, R_V_LINE_TO, 240, R_QUADRATIC_TO, -17, -13, -37, -22, R_QUADRATIC_TO, -20, -9, -43,
    -14, R_V_LINE_TO, -204, H_LINE_TO, 160, R_V_LINE_TO, 400, R_H_LINE_TO, 400, R_V_LINE_TO, 80, H_LINE_TO, 160, CLOSE, MOVE_TO, 674, 880, R_QUADRATIC_TO, -14,
    0, -24, -10, R_QUADRATIC_TO, -10, -10, -10, -24, R_V_LINE_TO, -132, R_QUADRATIC_TO, 0, -14, 10, -24, R_QUADRATIC_TO, 10, -10, 24, -10, R_H_LINE_TO, 6,
    R_V_LINE_TO, -40, R_QUADRATIC_TO, 0, -33, 23.5f, -56.5f, QUADRATIC_TO_SHORTHAND, 760, 560, R_QUADRATIC_TO, 33, 0, 56.5f, 23.5f, QUADRATIC_TO_SHORTHAND, 840,
    640, R_V_LINE_TO, 40, R_H_LINE_TO, 6, R_QUADRATIC_TO, 14, 0, 24, 10, R_QUADRATIC_TO, 10, 10, 10, 24, R_V_LINE_TO, 132, R_QUADRATIC_TO, 0, 14, -10, 24,
    R_QUADRATIC_TO, -10, 10, -24, 10, H_LINE_TO, 674, CLOSE, R_MOVE_TO, 46, -200, R_H_LINE_TO, 80, R_V_LINE_TO, -40, R_QUADRATIC_TO, 0, -17, -11.5f, -28.5f,
    QUADRATIC_TO_SHORTHAND, 760, 600, R_QUADRATIC_TO, -17, 0, -28.5f, 11.5f, QUADRATIC_TO_SHORTHAND, 720, 640, R_V_LINE_TO, 40, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kKeyboardLockRepList, kKeyboardLockIcon, { kKeyboardLockPath, std::size(kKeyboardLockPath) })
VECTOR_ICON_REP_TEMPLATE(kKeyboardLockOffPath, CANVAS_DIMENSIONS, 960, FILL_RULE_NONZERO, MOVE_TO, 360, 480, CLOSE, R_MOVE_TO, 167, 160, H_LINE_TO, 320,
    R_V_LINE_TO, -80, R_H_LINE_TO, 207, R_V_LINE_TO, 80, CLOSE, MOVE_TO, 200, 520, R_V_LINE_TO, -80, R_H_LINE_TO, 80, R_V_LINE_TO, 80, R_H_LINE_TO, -80, CLOSE,
    R_MOVE_TO, 120, 0, R_V_LINE_TO, -80, R_H_LINE_TO, 80, R_V_LINE_TO, 80, R_H_LINE_TO, -80, CLOSE, MOVE_TO, 200, 400, R_V_LINE_TO, -80, R_H_LINE_TO, 80,
    R_V_LINE_TO, 80, R_H_LINE_TO, -80, CLOSE, R_MOVE_TO, 360, 0, R_H_LINE_TO, 80, R_V_LINE_TO, -80, R_H_LINE_TO, -80, R_V_LINE_TO, 80, CLOSE, R_MOVE_TO, 120, 0,
    R_H_LINE_TO, 80, R_V_LINE_TO, -80, R_H_LINE_TO, -80, R_V_LINE_TO, 80, CLOSE, R_MOVE_TO, 0, 97, R_QUADRATIC_TO, 18, -8, 38.5f, -12.5f,
    QUADRATIC_TO_SHORTHAND, 760, 480, R_V_LINE_TO, -40, R_H_LINE_TO, -80, R_V_LINE_TO, 57, CLOSE, R_MOVE_TO, -40, 23, R_V_LINE_TO, -80, R_H_LINE_TO, -80,
    R_V_LINE_TO, 6, R_LINE_TO, 74, 74, R_H_LINE_TO, 6, CLOSE, MOVE_TO, 520, 400, R_V_LINE_TO, -80, R_H_LINE_TO, -80, R_V_LINE_TO, 6, R_LINE_TO, 74, 74,
    R_H_LINE_TO, 6, CLOSE, MOVE_TO, 819, 932, LINE_TO, 28, 140, R_LINE_TO, 56, -56, LINE_TO, 876, 876, R_LINE_TO, -57, 56, CLOSE, MOVE_TO, 516, 401, CLOSE,
    R_MOVE_TO, 364, 119, R_QUADRATIC_TO, -17, -13, -37, -22, R_QUADRATIC_TO, -20, -9, -43, -14, R_V_LINE_TO, -204, H_LINE_TO, 394, R_LINE_TO, -80, -80,
    R_H_LINE_TO, 486, R_QUADRATIC_TO, 33, 0, 56.5f, 23.5f, QUADRATIC_TO_SHORTHAND, 880, 280, R_V_LINE_TO, 240, CLOSE, MOVE_TO, 160, 760, R_QUADRATIC_TO, -33, 0,
    -56.5f, -23.5f, QUADRATIC_TO_SHORTHAND, 80, 680, R_V_LINE_TO, -400, R_QUADRATIC_TO, 0, -33, 23.5f, -56.5f, QUADRATIC_TO_SHORTHAND, 160, 200, R_H_LINE_TO,
    40, R_LINE_TO, 80, 80, H_LINE_TO, 160, R_V_LINE_TO, 400, R_H_LINE_TO, 400, R_V_LINE_TO, 80, H_LINE_TO, 160, CLOSE, MOVE_TO, 674, 880, R_QUADRATIC_TO, -14,
    0, -24, -10, R_QUADRATIC_TO, -10, -10, -10, -24, R_V_LINE_TO, -132, R_QUADRATIC_TO, 0, -14, 10, -24, R_QUADRATIC_TO, 10, -10, 24, -10, R_H_LINE_TO, 6,
    R_LINE_TO, 160, 160, R_V_LINE_TO, 40, H_LINE_TO, 674, CLOSE, R_MOVE_TO, 206, -114, R_LINE_TO, -80, -80, R_V_LINE_TO, -46, R_QUADRATIC_TO, 0, -17, -11.5f,
    -28.5f, QUADRATIC_TO_SHORTHAND, 760, 600, R_QUADRATIC_TO, -9, 0, -17.5f, 4, QUADRATIC_TO_SHORTHAND, 729, 615, R_LINE_TO, -28, -29, R_QUADRATIC_TO, 11, -12,
    26.5f, -19, R_QUADRATIC_TO, 15.5f, -7, 32.5f, -7, R_QUADRATIC_TO, 33, 0, 56.5f, 23.5f, QUADRATIC_TO_SHORTHAND, 840, 640, R_V_LINE_TO, 40, R_H_LINE_TO, 6,
    R_QUADRATIC_TO, 14, 0, 24, 10, R_QUADRATIC_TO, 10, 10, 10, 24, R_V_LINE_TO, 52, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kKeyboardLockOffRepList, kKeyboardLockOffIcon, { kKeyboardLockOffPath, std::size(kKeyboardLockOffPath) })
VECTOR_ICON_REP_TEMPLATE(kLaunchPath, CANVAS_DIMENSIONS, 18, FLIPS_IN_RTL, MOVE_TO, 13.5f, 13.5f, R_H_LINE_TO, -9, R_V_LINE_TO, -9, H_LINE_TO, 8, V_LINE_TO, 3,
    H_LINE_TO, 4.33f, CUBIC_TO, 3.59f, 3, 3, 3.6f, 3, 4.33f, R_V_LINE_TO, 9.33f, CUBIC_TO, 3, 14.4f, 3.59f, 15, 4.33f, 15, R_H_LINE_TO, 9.33f, CUBIC_TO, 14.4f,
    15, 15, 14.4f, 15, 13.67f, V_LINE_TO, 10, R_H_LINE_TO, -1.5f, CLOSE, MOVE_TO, 10, 3, R_V_LINE_TO, 1.5f, R_H_LINE_TO, 2.5f, R_LINE_TO, -6, 6, R_LINE_TO, 1,
    1, R_LINE_TO, 6, -6, V_LINE_TO, 8, H_LINE_TO, 15, V_LINE_TO, 3, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kLaunchRepList, kLaunchIcon, { kLaunchPath, std::size(kLaunchPath) })
VECTOR_ICON_REP_TEMPLATE(kLaunchChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, FLIPS_IN_RTL, MOVE_TO, 4.5f, 17, R_CUBIC_TO, -0.41f, 0, -0.77f,
    -0.15f, -1.06f, -0.44f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 3, 15.5f, R_V_LINE_TO, -11, R_CUBIC_TO, 0, -0.41f, 0.15f, -0.77f, 0.44f, -1.06f, ARC_TO, 1.44f,
    1.44f, 0, 0, 1, 4.5f, 3, H_LINE_TO, 10, R_V_LINE_TO, 1.5f, H_LINE_TO, 4.5f, R_V_LINE_TO, 11, R_H_LINE_TO, 11, V_LINE_TO, 10, H_LINE_TO, 17, R_V_LINE_TO,
    5.5f, R_CUBIC_TO, 0, 0.41f, -0.15f, 0.77f, -0.44f, 1.06f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 15.5f, 17, CLOSE, R_MOVE_TO, 3.56f, -4, LINE_TO, 7, 11.94f,
    LINE_TO, 14.44f, 4.5f, H_LINE_TO, 12, V_LINE_TO, 3, R_H_LINE_TO, 5, R_V_LINE_TO, 5, R_H_LINE_TO, -1.5f, V_LINE_TO, 5.56f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kLaunchChromeRefreshRepList, kLaunchChromeRefreshIcon, { kLaunchChromeRefreshPath, std::size(kLaunchChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kLaunchOffChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 16, 18.13f, LINE_TO, 14.88f, 17, H_LINE_TO, 4.5f,
    R_CUBIC_TO, -0.41f, 0, -0.77f, -0.15f, -1.06f, -0.44f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 3, 15.5f, V_LINE_TO, 5.13f, LINE_TO, 1.88f, 4, R_LINE_TO, 1.06f,
    -1.06f, R_LINE_TO, 14.12f, 14.13f, CLOSE, MOVE_TO, 4.5f, 15.5f, R_H_LINE_TO, 8.88f, LINE_TO, 9.48f, 11.58f, LINE_TO, 8.06f, 13, LINE_TO, 7, 11.94f,
    R_LINE_TO, 1.42f, -1.42f, LINE_TO, 4.5f, 6.63f, CLOSE, R_MOVE_TO, 2.13f, -11, LINE_TO, 5.13f, 3, H_LINE_TO, 10, R_V_LINE_TO, 1.5f, CLOSE, R_MOVE_TO, 4.96f,
    4.98f, LINE_TO, 10.52f, 8.42f, LINE_TO, 14.44f, 4.5f, H_LINE_TO, 12, V_LINE_TO, 3, R_H_LINE_TO, 5, R_V_LINE_TO, 5, R_H_LINE_TO, -1.5f, V_LINE_TO, 5.56f,
    CLOSE, MOVE_TO, 17, 14.88f, R_LINE_TO, -1.5f, -1.5f, V_LINE_TO, 10, H_LINE_TO, 17, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kLaunchOffChromeRefreshRepList, kLaunchOffChromeRefreshIcon, { kLaunchOffChromeRefreshPath, std::size(kLaunchOffChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kLightbulbOutlinePath, CANVAS_DIMENSIONS, 24, MOVE_TO, 9, 21, R_CUBIC_TO, 0, 0.55f, 0.45f, 1, 1, 1, R_H_LINE_TO, 4, R_CUBIC_TO, 0.55f,
    0, 1, -0.45f, 1, -1, R_V_LINE_TO, -1, H_LINE_TO, 9, R_V_LINE_TO, 1, CLOSE, R_MOVE_TO, 3, -19, CUBIC_TO, 8.14f, 2, 5, 5.14f, 5, 9, R_CUBIC_TO, 0, 2.38f,
    1.19f, 4.47f, 3, 5.74f, V_LINE_TO, 17, R_CUBIC_TO, 0, 0.55f, 0.45f, 1, 1, 1, R_H_LINE_TO, 6, R_CUBIC_TO, 0.55f, 0, 1, -0.45f, 1, -1, R_V_LINE_TO, -2.26f,
    R_CUBIC_TO, 1.81f, -1.27f, 3, -3.36f, 3, -5.74f, R_CUBIC_TO, 0, -3.86f, -3.14f, -7, -7, -7, CLOSE, R_MOVE_TO, 2.85f, 11.1f, R_LINE_TO, -0.85f, 0.6f,
    V_LINE_TO, 16, R_H_LINE_TO, -4, R_V_LINE_TO, -2.3f, R_LINE_TO, -0.85f, -0.6f, ARC_TO, 5, 5, 0, 0, 1, 7, 9, R_CUBIC_TO, 0, -2.76f, 2.24f, -5, 5, -5,
    R_CUBIC_TO, 2.76f, 0, 5, 2.24f, 5, 5, R_CUBIC_TO, 0, 1.63f, -0.8f, 3.16f, -2.15f, 4.1f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kLightbulbOutlineRepList, kLightbulbOutlineIcon, { kLightbulbOutlinePath, std::size(kLightbulbOutlinePath) })
VECTOR_ICON_REP_TEMPLATE(kLightbulbOutlineChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 10, 18, R_CUBIC_TO, -0.41f, 0, -0.77f, -0.15f,
    -1.06f, -0.44f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 8.5f, 16.5f, R_H_LINE_TO, 3, R_CUBIC_TO, 0, 0.42f, -0.15f, 0.77f, -0.44f, 1.06f, ARC_TO, 1.45f, 1.45f, 0, 0,
    1, 10, 18, CLOSE, MOVE_TO, 7, 15.5f, V_LINE_TO, 14, R_H_LINE_TO, 6, R_V_LINE_TO, 1.5f, CLOSE, MOVE_TO, 6.69f, 13, ARC_TO, 5.34f, 5.34f, 0, 0, 1, 4.7f,
    10.86f, ARC_TO, 6.12f, 6.12f, 0, 0, 1, 4, 8, R_CUBIC_TO, 0, -1.67f, 0.58f, -3.08f, 1.75f, -4.25f, CUBIC_TO, 6.92f, 2.58f, 8.33f, 2, 10, 2, R_CUBIC_TO,
    1.67f, 0, 3.08f, 0.58f, 4.25f, 1.75f, CUBIC_TO, 15.42f, 4.92f, 16, 6.33f, 16, 8, R_ARC_TO, 6.12f, 6.12f, 0, 0, 1, -0.7f, 2.86f, ARC_TO, 5.34f, 5.34f, 0, 0,
    1, 13.31f, 13, CLOSE, R_MOVE_TO, 0.48f, -1.5f, R_H_LINE_TO, 5.66f, R_ARC_TO, 4.52f, 4.52f, 0, 0, 0, 1.23f, -1.56f, R_CUBIC_TO, 0.29f, -0.61f, 0.44f, -1.26f,
    0.44f, -1.94f, R_CUBIC_TO, 0, -1.25f, -0.44f, -2.32f, -1.31f, -3.19f, R_CUBIC_TO, -0.87f, -0.87f, -1.93f, -1.31f, -3.19f, -1.31f, R_CUBIC_TO, -1.25f, 0,
    -2.32f, 0.44f, -3.19f, 1.31f, CUBIC_TO, 5.94f, 5.68f, 5.5f, 6.75f, 5.5f, 8, R_CUBIC_TO, 0, 0.68f, 0.14f, 1.33f, 0.44f, 1.94f, R_ARC_TO, 4.52f, 4.52f, 0, 0,
    0, 1.23f, 1.56f, CLOSE, R_MOVE_TO, 2.83f, 0, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kLightbulbOutlineChromeRefreshRepList, kLightbulbOutlineChromeRefreshIcon,
    { kLightbulbOutlineChromeRefreshPath, std::size(kLightbulbOutlineChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kLinkPath, CANVAS_DIMENSIONS, 20, MOVE_TO, 14, 8, H_LINE_TO, 12, V_LINE_TO, 6, H_LINE_TO, 14, CUBIC_TO, 16.21f, 6, 18, 7.79f, 18, 10,
    CUBIC_TO, 18, 12.21f, 16.21f, 14, 14, 14, H_LINE_TO, 12, V_LINE_TO, 12, H_LINE_TO, 14, CUBIC_TO, 15.1f, 12, 16, 11.1f, 16, 10, CUBIC_TO, 16, 8.9f, 15.1f, 8,
    14, 8, CLOSE, MOVE_TO, 8, 6, V_LINE_TO, 8, H_LINE_TO, 6, CUBIC_TO, 4.9f, 8, 4, 8.9f, 4, 10, CUBIC_TO, 4, 11.1f, 4.9f, 12, 6, 12, H_LINE_TO, 8, V_LINE_TO,
    14, H_LINE_TO, 6, CUBIC_TO, 3.79f, 14, 2, 12.21f, 2, 10, CUBIC_TO, 2, 7.79f, 3.79f, 6, 6, 6, H_LINE_TO, 8, CLOSE, MOVE_TO, 13, 9, H_LINE_TO, 7, V_LINE_TO,
    11, H_LINE_TO, 13, V_LINE_TO, 9, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kLinkRepList, kLinkIcon, { kLinkPath, std::size(kLinkPath) })
VECTOR_ICON_REP_TEMPLATE(kLiveCaptionOnPath, CANVAS_DIMENSIONS, 20, MOVE_TO, 2, 5.5f, ARC_TO, 1.5f, 1.5f, 0, 0, 1, 3.5f, 4, R_H_LINE_TO, 13, ARC_TO, 1.5f, 1.5f,
    0, 0, 1, 18, 5.5f, R_V_LINE_TO, 9, R_ARC_TO, 1.5f, 1.5f, 0, 0, 1, -1.5f, 1.5f, R_H_LINE_TO, -13, ARC_TO, 1.5f, 1.5f, 0, 0, 1, 2, 14.5f, R_V_LINE_TO, -9,
    CLOSE, MOVE_TO, 4, 6, R_H_LINE_TO, 12, R_V_LINE_TO, 8, H_LINE_TO, 4, V_LINE_TO, 6, CLOSE, R_MOVE_TO, 1, 2, R_H_LINE_TO, 4, R_V_LINE_TO, 2, H_LINE_TO, 5,
    V_LINE_TO, 8, CLOSE, R_MOVE_TO, 0, 3, R_H_LINE_TO, 7, R_V_LINE_TO, 2, H_LINE_TO, 5, R_V_LINE_TO, -2, CLOSE, R_MOVE_TO, 10, 0, R_H_LINE_TO, -2, R_V_LINE_TO,
    2, R_H_LINE_TO, 2, R_V_LINE_TO, -2, CLOSE, R_MOVE_TO, -5, -3, R_H_LINE_TO, 5, R_V_LINE_TO, 2, R_H_LINE_TO, -5, V_LINE_TO, 8, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kLiveCaptionOnRepList, kLiveCaptionOnIcon, { kLiveCaptionOnPath, std::size(kLiveCaptionOnPath) })
VECTOR_ICON_REP_TEMPLATE(kLocationOffChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, R_MOVE_TO, 14.06f, 11.92f, R_LINE_TO, -1.08f, -1.09f,
    R_ARC_TO, 7.11f, 7.11f, 0, 0, 0, 0.74f, -1.59f, ARC_TO, 5.59f, 5.59f, 0, 0, 0, 14, 7.5f, R_CUBIC_TO, 0, -1.1f, -0.39f, -2.05f, -1.17f, -2.83f, CUBIC_TO,
    12.05f, 3.89f, 11.11f, 3.5f, 10, 3.5f, R_CUBIC_TO, -0.58f, 0, -1.13f, 0.12f, -1.64f, 0.36f, ARC_TO, 4.34f, 4.34f, 0, 0, 0, 7, 4.88f, LINE_TO, 5.94f, 3.81f,
    ARC_TO, 5.46f, 5.46f, 0, 0, 1, 7.78f, 2.47f, ARC_TO, 5.4f, 5.4f, 0, 0, 1, 10, 2, R_CUBIC_TO, 1.53f, 0, 2.83f, 0.54f, 3.9f, 1.6f, CUBIC_TO, 14.97f, 4.67f,
    15.5f, 5.97f, 15.5f, 7.5f, R_CUBIC_TO, 0, 0.8f, -0.13f, 1.56f, -0.39f, 2.31f, R_ARC_TO, 9.12f, 9.12f, 0, 0, 1, -1.05f, 2.11f, CLOSE, R_MOVE_TO, -2.68f,
    -2.67f, R_CUBIC_TO, 0.19f, -0.19f, 0.34f, -0.42f, 0.45f, -0.67f, R_CUBIC_TO, 0.11f, -0.25f, 0.17f, -0.51f, 0.17f, -0.79f, R_ARC_TO, 1.93f, 1.93f, 0, 0, 0,
    -0.58f, -1.42f, ARC_TO, 1.94f, 1.94f, 0, 0, 0, 10, 5.79f, R_ARC_TO, 2.22f, 2.22f, 0, 0, 0, -0.8f, 0.14f, R_ARC_TO, 1.53f, 1.53f, 0, 0, 0, -0.66f, 0.48f,
    CLOSE, MOVE_TO, 16, 18.13f, R_LINE_TO, -3.69f, -3.71f, R_CUBIC_TO, -0.23f, 0.38f, -0.47f, 0.76f, -0.7f, 1.16f, R_CUBIC_TO, -0.23f, 0.4f, -0.44f, 0.81f,
    -0.63f, 1.24f, R_ARC_TO, 9.4f, 9.4f, 0, 0, 1, -0.37f, 0.8f, ARC_TO, 0.65f, 0.65f, 0, 0, 1, 10, 18, R_ARC_TO, 0.65f, 0.65f, 0, 0, 1, -0.61f, -0.39f,
    R_ARC_TO, 9.4f, 9.4f, 0, 0, 1, -0.37f, -0.8f, R_ARC_TO, 11.49f, 11.49f, 0, 0, 0, -1.13f, -2.08f, R_ARC_TO, 44.89f, 44.89f, 0, 0, 0, -1.39f, -1.89f,
    R_ARC_TO, 15.05f, 15.05f, 0, 0, 1, -1.41f, -2.54f, R_ARC_TO, 6.97f, 6.97f, 0, 0, 1, -0.57f, -3.22f, R_CUBIC_TO, 0, -0.13f, 0.02f, -0.27f, 0.05f, -0.4f,
    LINE_TO, 1.88f, 3.98f, R_LINE_TO, 1.06f, -1.06f, R_LINE_TO, 14.12f, 14.15f, CLOSE, R_MOVE_TO, -6, -2.73f, R_CUBIC_TO, 0.17f, -0.36f, 0.36f, -0.71f, 0.58f,
    -1.04f, R_LINE_TO, 0.67f, -1, R_LINE_TO, -5.21f, -5.21f, R_CUBIC_TO, 0.08f, 0.78f, 0.32f, 1.5f, 0.71f, 2.17f, R_CUBIC_TO, 0.39f, 0.67f, 0.81f, 1.32f, 1.25f,
    1.96f, R_CUBIC_TO, 0.38f, 0.5f, 0.73f, 1, 1.07f, 1.51f, R_CUBIC_TO, 0.34f, 0.51f, 0.65f, 1.05f, 0.93f, 1.61f, CLOSE, MOVE_TO, 8.67f, 11, CLOSE, R_MOVE_TO,
    1.38f, -3.08f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(
    kLocationOffChromeRefreshRepList, kLocationOffChromeRefreshIcon, { kLocationOffChromeRefreshPath, std::size(kLocationOffChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kLocationOnPath, MOVE_TO, 24, 4, R_CUBIC_TO, -7.73f, 0, -14, 6.27f, -14, 14, R_CUBIC_TO, 0, 10.5f, 14, 26, 14, 26, R_CUBIC_TO, 0, 0,
    14, -15.5f, 14, -26, R_CUBIC_TO, 0, -7.73f, -6.27f, -14, -14, -14, CLOSE, CIRCLE, 24, 18, 5)
VECTOR_ICON_REP_TEMPLATE(kLocationOn16Path, CANVAS_DIMENSIONS, 16, MOVE_TO, 8, 1, CUBIC_TO, 5.24f, 1, 3, 3.19f, 3, 5.9f, CUBIC_TO, 3, 9.57f, 8, 15, 8, 15,
    CUBIC_TO, 8, 15, 13, 9.57f, 13, 5.9f, CUBIC_TO, 13, 3.19f, 10.76f, 1, 8, 1, CLOSE, MOVE_TO, 8, 8, CUBIC_TO, 6.9f, 8, 6, 7.1f, 6, 6, CUBIC_TO, 6, 4.9f, 6.9f,
    4, 8, 4, CUBIC_TO, 9.1f, 4, 10, 4.9f, 10, 6, CUBIC_TO, 10, 7.1f, 9.1f, 8, 8, 8, CLOSE)
VECTOR_ICON_TEMPLATE_CC(
    kLocationOnRepList, kLocationOnIcon, { kLocationOnPath, std::size(kLocationOnPath) }, { kLocationOn16Path, std::size(kLocationOn16Path) })
VECTOR_ICON_REP_TEMPLATE(kLocationOnChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 10, 18, R_ARC_TO, 0.78f, 0.78f, 0, 0, 1, -0.49f,
    -0.16f, R_ARC_TO, 0.82f, 0.82f, 0, 0, 1, -0.29f, -0.41f, R_ARC_TO, 14.33f, 14.33f, 0, 0, 0, -0.95f, -2.09f, R_CUBIC_TO, -0.37f, -0.66f, -0.9f, -1.43f,
    -1.59f, -2.32f, R_CUBIC_TO, -0.68f, -0.87f, -1.23f, -1.71f, -1.66f, -2.52f, R_CUBIC_TO, -0.42f, -0.8f, -0.64f, -1.77f, -0.64f, -2.9f, R_CUBIC_TO, 0, -1.55f,
    0.55f, -2.87f, 1.63f, -3.96f, CUBIC_TO, 7.11f, 2.55f, 8.44f, 2, 10, 2, R_CUBIC_TO, 1.56f, 0, 2.89f, 0.54f, 3.97f, 1.63f, R_CUBIC_TO, 1.09f, 1.09f, 1.63f,
    2.42f, 1.63f, 3.98f, R_CUBIC_TO, 0, 1.22f, -0.23f, 2.22f, -0.7f, 3.02f, R_ARC_TO, 23.89f, 23.89f, 0, 0, 1, -1.59f, 2.38f, R_CUBIC_TO, -0.72f, 0.95f, -1.26f,
    1.74f, -1.64f, 2.39f, R_ARC_TO, 11.54f, 11.54f, 0, 0, 0, -0.91f, 2.03f, R_ARC_TO, 0.96f, 0.96f, 0, 0, 1, -0.3f, 0.41f, R_ARC_TO, 0.72f, 0.72f, 0, 0, 1,
    -0.46f, 0.16f, CLOSE, MOVE_TO, 10, 15.36f, R_CUBIC_TO, 0.23f, -0.47f, 0.5f, -0.94f, 0.8f, -1.4f, R_CUBIC_TO, 0.3f, -0.46f, 0.74f, -1.08f, 1.33f, -1.85f,
    R_CUBIC_TO, 0.58f, -0.75f, 1.06f, -1.45f, 1.43f, -2.09f, R_CUBIC_TO, 0.37f, -0.64f, 0.55f, -1.45f, 0.55f, -2.41f, R_CUBIC_TO, 0, -1.12f, -0.4f, -2.09f,
    -1.21f, -2.9f, CUBIC_TO, 12.09f, 3.9f, 11.12f, 3.5f, 9.99f, 3.5f, R_ARC_TO, 3.93f, 3.93f, 0, 0, 0, -2.89f, 1.21f, R_CUBIC_TO, -0.8f, 0.81f, -1.2f, 1.77f,
    -1.2f, 2.9f, R_CUBIC_TO, 0, 0.96f, 0.19f, 1.77f, 0.56f, 2.41f, R_CUBIC_TO, 0.38f, 0.64f, 0.85f, 1.34f, 1.42f, 2.09f, R_CUBIC_TO, 0.58f, 0.77f, 1.02f, 1.39f,
    1.32f, 1.85f, R_CUBIC_TO, 0.3f, 0.46f, 0.57f, 0.93f, 0.8f, 1.4f, CLOSE, R_MOVE_TO, 0, -5.75f, R_CUBIC_TO, 0.56f, 0, 1.03f, -0.19f, 1.42f, -0.58f, ARC_TO,
    1.93f, 1.93f, 0, 0, 0, 12, 7.61f, R_CUBIC_TO, 0, -0.56f, -0.19f, -1.03f, -0.58f, -1.42f, R_ARC_TO, 1.92f, 1.92f, 0, 0, 0, -1.42f, -0.58f, R_CUBIC_TO,
    -0.56f, 0, -1.03f, 0.19f, -1.42f, 0.58f, ARC_TO, 1.92f, 1.92f, 0, 0, 0, 8, 7.6f, R_CUBIC_TO, 0, 0.56f, 0.19f, 1.03f, 0.58f, 1.42f, R_CUBIC_TO, 0.39f, 0.39f,
    0.86f, 0.59f, 1.42f, 0.59f, CLOSE, MOVE_TO, 10, 7.58f, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kLocationOnChromeRefresh16Path, CANVAS_DIMENSIONS, 16, FILL_RULE_NONZERO, MOVE_TO, 8, 14.52f, R_ARC_TO, 0.74f, 0.74f, 0, 0, 1, -0.46f,
    -0.15f, R_ARC_TO, 0.86f, 0.86f, 0, 0, 1, -0.29f, -0.39f, R_CUBIC_TO, -0.25f, -0.64f, -0.52f, -1.21f, -0.8f, -1.72f, R_CUBIC_TO, -0.28f, -0.51f, -0.69f,
    -1.09f, -1.2f, -1.76f, R_CUBIC_TO, -0.55f, -0.71f, -1, -1.39f, -1.35f, -2.05f, R_CUBIC_TO, -0.34f, -0.66f, -0.51f, -1.44f, -0.51f, -2.37f, R_CUBIC_TO, 0,
    -1.28f, 0.45f, -2.37f, 1.34f, -3.27f, CUBIC_TO, 5.62f, 1.91f, 6.72f, 1.47f, 8, 1.47f, R_CUBIC_TO, 1.29f, 0, 2.38f, 0.45f, 3.27f, 1.35f, R_CUBIC_TO, 0.9f,
    0.9f, 1.34f, 1.99f, 1.34f, 3.28f, R_CUBIC_TO, 0, 1, -0.19f, 1.82f, -0.57f, 2.47f, R_ARC_TO, 19.3f, 19.3f, 0, 0, 1, -1.3f, 1.94f, R_CUBIC_TO, -0.53f, 0.69f,
    -0.94f, 1.29f, -1.23f, 1.79f, R_ARC_TO, 11.26f, 11.26f, 0, 0, 0, -0.78f, 1.69f, R_ARC_TO, 1.02f, 1.02f, 0, 0, 1, -0.3f, 0.4f, R_ARC_TO, 0.7f, 0.7f, 0, 0, 1,
    -0.44f, 0.15f, CLOSE, MOVE_TO, 8, 12.21f, R_CUBIC_TO, 0.19f, -0.38f, 0.4f, -0.75f, 0.63f, -1.12f, R_CUBIC_TO, 0.24f, -0.37f, 0.58f, -0.85f, 1.03f, -1.44f,
    R_CUBIC_TO, 0.47f, -0.59f, 0.84f, -1.15f, 1.14f, -1.66f, R_CUBIC_TO, 0.29f, -0.51f, 0.44f, -1.14f, 0.44f, -1.91f, R_CUBIC_TO, 0, -0.89f, -0.32f, -1.64f,
    -0.95f, -2.28f, R_ARC_TO, 3.11f, 3.11f, 0, 0, 0, -2.29f, -0.95f, R_CUBIC_TO, -0.89f, 0, -1.65f, 0.32f, -2.28f, 0.95f, R_ARC_TO, 3.13f, 3.13f, 0, 0, 0,
    -0.94f, 2.28f, R_CUBIC_TO, 0, 0.77f, 0.15f, 1.4f, 0.45f, 1.91f, R_CUBIC_TO, 0.3f, 0.51f, 0.68f, 1.07f, 1.13f, 1.66f, R_CUBIC_TO, 0.45f, 0.59f, 0.79f, 1.07f,
    1.03f, 1.44f, R_CUBIC_TO, 0.24f, 0.37f, 0.45f, 0.74f, 0.63f, 1.12f, CLOSE, R_MOVE_TO, 0, -4.51f, R_CUBIC_TO, 0.45f, 0, 0.83f, -0.16f, 1.15f, -0.46f,
    R_CUBIC_TO, 0.31f, -0.31f, 0.47f, -0.69f, 0.47f, -1.14f, R_CUBIC_TO, 0, -0.45f, -0.16f, -0.83f, -0.47f, -1.14f, R_ARC_TO, 1.54f, 1.54f, 0, 0, 0, -1.14f,
    -0.47f, R_CUBIC_TO, -0.45f, 0, -0.83f, 0.15f, -1.14f, 0.47f, R_ARC_TO, 1.55f, 1.55f, 0, 0, 0, -0.47f, 1.14f, R_CUBIC_TO, 0, 0.45f, 0.16f, 0.83f, 0.47f,
    1.15f, R_CUBIC_TO, 0.31f, 0.31f, 0.69f, 0.47f, 1.14f, 0.47f, CLOSE, MOVE_TO, 8, 6.07f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kLocationOnChromeRefreshRepList, kLocationOnChromeRefreshIcon,
    { kLocationOnChromeRefreshPath, std::size(kLocationOnChromeRefreshPath) }, { kLocationOnChromeRefresh16Path, std::size(kLocationOnChromeRefresh16Path) })
VECTOR_ICON_REP_TEMPLATE(kLockPath, MOVE_TO, 36, 16, R_H_LINE_TO, -2, R_V_LINE_TO, -4, R_CUBIC_TO, 0, -5.52f, -4.48f, -10, -10, -10, CUBIC_TO, 18.48f, 2, 14,
    6.48f, 14, 12, R_V_LINE_TO, 4, R_H_LINE_TO, -2, R_CUBIC_TO, -2.21f, 0, -4, 1.79f, -4, 4, R_V_LINE_TO, 20, R_CUBIC_TO, 0, 2.21f, 1.79f, 4, 4, 4, R_H_LINE_TO,
    24, R_CUBIC_TO, 2.21f, 0, 4, -1.79f, 4, -4, V_LINE_TO, 20, R_CUBIC_TO, 0, -2.21f, -1.79f, -4, -4, -4, CLOSE, MOVE_TO, 24, 34, R_CUBIC_TO, -2.21f, 0, -4,
    -1.79f, -4, -4, R_CUBIC_TO, 0, -2.21f, 1.79f, -4, 4, -4, R_CUBIC_TO, 2.21f, 0, 4, 1.79f, 4, 4, R_CUBIC_TO, 0, 2.21f, -1.79f, 4, -4, 4, CLOSE, R_MOVE_TO,
    6.2f, -18, H_LINE_TO, 17.8f, R_V_LINE_TO, -4, R_CUBIC_TO, 0, -3.42f, 2.78f, -6.2f, 6.2f, -6.2f, R_CUBIC_TO, 3.42f, 0, 6.2f, 2.78f, 6.2f, 6.2f, R_V_LINE_TO,
    4, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kLockRepList, kLockIcon, { kLockPath, std::size(kLockPath) })
VECTOR_ICON_REP_TEMPLATE(kMagicButtonPath, MOVE_TO, 32, 44.35f, LINE_TO, 26.41f, 38.76f, LINE_TO, 32, 33.18f, LINE_TO, 37.59f, 38.76f, CLOSE, MOVE_TO, 15.29f,
    37.6f, LINE_TO, 3.7f, 26, LINE_TO, 15.29f, 14.4f, LINE_TO, 26.88f, 26, CLOSE, MOVE_TO, 35, 23.48f, CUBIC_TO, 35, 20.56f, 33.98f, 18.09f, 31.95f, 16.05f,
    CUBIC_TO, 29.91f, 14.02f, 27.44f, 13, 24.52f, 13, CUBIC_TO, 27.44f, 13, 29.91f, 11.98f, 31.95f, 9.95f, CUBIC_TO, 33.98f, 7.91f, 35, 5.43f, 35, 2.51f,
    CUBIC_TO, 35, 5.43f, 36.02f, 7.91f, 38.05f, 9.95f, CUBIC_TO, 40.09f, 11.98f, 42.57f, 13, 45.49f, 13, CUBIC_TO, 42.57f, 13, 40.09f, 14.02f, 38.05f, 16.05f,
    CUBIC_TO, 36.02f, 18.09f, 35, 20.56f, 35, 23.48f, CLOSE, MOVE_TO, 35, 23.48f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kMagicButtonRepList, kMagicButtonIcon, { kMagicButtonPath, std::size(kMagicButtonPath) })
VECTOR_ICON_REP_TEMPLATE(kMediaNextTrackPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 6, 18, R_LINE_TO, 8.5f, -6, LINE_TO, 6, 6, R_V_LINE_TO, 12, CLOSE, MOVE_TO, 16, 6,
    R_V_LINE_TO, 12, R_H_LINE_TO, 2, V_LINE_TO, 6, R_H_LINE_TO, -2, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kMediaNextTrackRepList, kMediaNextTrackIcon, { kMediaNextTrackPath, std::size(kMediaNextTrackPath) })
VECTOR_ICON_REP_TEMPLATE(kMediaPreviousTrackPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 6, 6, R_H_LINE_TO, 2, R_V_LINE_TO, 12, H_LINE_TO, 6, CLOSE, R_MOVE_TO, 3.5f,
    6, R_LINE_TO, 8.5f, 6, V_LINE_TO, 6, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kMediaPreviousTrackRepList, kMediaPreviousTrackIcon, { kMediaPreviousTrackPath, std::size(kMediaPreviousTrackPath) })
VECTOR_ICON_REP_TEMPLATE(kMediaRouterActiveChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 15, 13, R_H_LINE_TO, -3.98f, R_ARC_TO, 6.57f,
    6.57f, 0, 0, 0, -0.3f, -0.78f, R_CUBIC_TO, -0.12f, -0.26f, -0.23f, -0.5f, -0.34f, -0.72f, H_LINE_TO, 13.5f, R_V_LINE_TO, -3, H_LINE_TO, 7.83f, R_ARC_TO,
    9.7f, 9.7f, 0, 0, 0, -1.31f, -0.85f, ARC_TO, 9.63f, 9.63f, 0, 0, 0, 5.06f, 7, H_LINE_TO, 15, CLOSE, R_MOVE_TO, -5, -3, CLOSE, R_MOVE_TO, -8, 6, R_V_LINE_TO,
    -2, R_CUBIC_TO, 0.56f, 0, 1.03f, 0.2f, 1.42f, 0.58f, R_CUBIC_TO, 0.39f, 0.39f, 0.58f, 0.86f, 0.58f, 1.42f, CLOSE, R_MOVE_TO, 3.5f, 0, R_CUBIC_TO, 0, -0.97f,
    -0.34f, -1.8f, -1.02f, -2.48f, ARC_TO, 3.38f, 3.38f, 0, 0, 0, 2, 12.5f, V_LINE_TO, 11, R_CUBIC_TO, 1.39f, 0, 2.57f, 0.48f, 3.54f, 1.46f, CUBIC_TO, 6.52f,
    13.43f, 7, 14.61f, 7, 16, CLOSE, R_MOVE_TO, 3, 0, R_ARC_TO, 6.3f, 6.3f, 0, 0, 0, -0.51f, -2.53f, R_ARC_TO, 6.56f, 6.56f, 0, 0, 0, -1.39f, -2.07f, R_ARC_TO,
    6.56f, 6.56f, 0, 0, 0, -2.07f, -1.39f, ARC_TO, 6.3f, 6.3f, 0, 0, 0, 2, 9.5f, V_LINE_TO, 8, R_CUBIC_TO, 1.11f, 0, 2.15f, 0.21f, 3.12f, 0.63f, ARC_TO, 8.09f,
    8.09f, 0, 0, 1, 7.66f, 10.34f, R_ARC_TO, 8.09f, 8.09f, 0, 0, 1, 1.72f, 2.54f, CUBIC_TO, 9.79f, 13.85f, 10, 14.89f, 10, 16, CLOSE, R_MOVE_TO, 8, 0,
    R_H_LINE_TO, -5, R_CUBIC_TO, 0, -0.25f, -0.01f, -0.5f, -0.03f, -0.75f, R_CUBIC_TO, -0.02f, -0.25f, -0.05f, -0.5f, -0.09f, -0.75f, H_LINE_TO, 16.5f,
    R_V_LINE_TO, -9, R_H_LINE_TO, -13, R_V_LINE_TO, 1.13f, R_CUBIC_TO, -0.25f, -0.04f, -0.5f, -0.07f, -0.75f, -0.09f, R_CUBIC_TO, -0.25f, -0.02f, -0.5f, -0.03f,
    -0.75f, -0.03f, R_V_LINE_TO, -1, R_CUBIC_TO, 0, -0.41f, 0.15f, -0.77f, 0.44f, -1.06f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 3.5f, 4, R_H_LINE_TO, 13, R_CUBIC_TO,
    0.41f, 0, 0.77f, 0.15f, 1.06f, 0.44f, R_CUBIC_TO, 0.29f, 0.29f, 0.44f, 0.65f, 0.44f, 1.06f, R_V_LINE_TO, 9.01f, R_CUBIC_TO, 0, 0.41f, -0.15f, 0.76f, -0.44f,
    1.06f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 16.5f, 16, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kMediaRouterActiveChromeRefreshRepList, kMediaRouterActiveChromeRefreshIcon,
    { kMediaRouterActiveChromeRefreshPath, std::size(kMediaRouterActiveChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kMediaRouterErrorPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 14.55f, 1.5f, H_LINE_TO, 1.45f, CUBIC_TO, 0.65f, 1.5f, 0, 2.15f, 0, 2.94f,
    R_V_LINE_TO, 2.18f, R_LINE_TO, 1.5f, 0, V_LINE_TO, 3, R_H_LINE_TO, 13, R_V_LINE_TO, 10, R_H_LINE_TO, -5, R_V_LINE_TO, 1.5f, R_H_LINE_TO, 5.05f, R_CUBIC_TO,
    0.8f, 0, 1.45f, -0.65f, 1.45f, -1.44f, V_LINE_TO, 2.94f, CUBIC_TO, 16, 2.15f, 15.35f, 1.5f, 14.55f, 1.5f, CLOSE, MOVE_TO, 0, 12.37f, R_V_LINE_TO, 2.13f,
    R_H_LINE_TO, 2.12f, CUBIC_TO, 2.12f, 13.3f, 1.21f, 12.37f, 0, 12.37f, CLOSE, MOVE_TO, 0, 9.37f, R_LINE_TO, 0, 1.5f, R_CUBIC_TO, 2.01f, 0, 3.62f, 1.63f,
    3.62f, 3.63f, R_H_LINE_TO, 1.5f, CUBIC_TO, 5.12f, 11.71f, 2.81f, 9.37f, 0, 9.37f, CLOSE, MOVE_TO, 0, 6.56f, V_LINE_TO, 8, R_CUBIC_TO, 3.61f, 0, 6.5f, 2.91f,
    6.5f, 6.5f, H_LINE_TO, 8, CUBIC_TO, 8, 10.11f, 4.41f, 6.56f, 0, 6.56f, CLOSE, MOVE_TO, 12.94f, 6, R_LINE_TO, -1.69f, 1.69f, LINE_TO, 9.56f, 6, LINE_TO,
    8.5f, 7.06f, R_LINE_TO, 1.69f, 1.69f, R_LINE_TO, -1.69f, 1.69f, R_LINE_TO, 1.06f, 1.06f, R_LINE_TO, 1.69f, -1.69f, R_LINE_TO, 1.69f, 1.69f, R_LINE_TO,
    1.06f, -1.06f, R_LINE_TO, -1.69f, -1.69f, R_LINE_TO, 1.69f, -1.69f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kMediaRouterErrorRepList, kMediaRouterErrorIcon, { kMediaRouterErrorPath, std::size(kMediaRouterErrorPath) })
VECTOR_ICON_REP_TEMPLATE(kMediaRouterIdlePath, CANVAS_DIMENSIONS, 16, MOVE_TO, 14.55f, 1.5f, H_LINE_TO, 1.45f, CUBIC_TO, 0.65f, 1.5f, 0, 2.15f, 0, 2.94f,
    R_V_LINE_TO, 2.18f, R_H_LINE_TO, 1.5f, V_LINE_TO, 3, R_H_LINE_TO, 13, R_V_LINE_TO, 10, R_H_LINE_TO, -5, R_V_LINE_TO, 1.5f, R_H_LINE_TO, 5.05f, R_CUBIC_TO,
    0.8f, 0, 1.45f, -0.65f, 1.45f, -1.44f, V_LINE_TO, 2.94f, R_CUBIC_TO, 0, -0.79f, -0.65f, -1.44f, -1.45f, -1.44f, CLOSE, MOVE_TO, 0, 12.37f, R_V_LINE_TO,
    2.13f, R_H_LINE_TO, 2.12f, R_CUBIC_TO, 0, -1.2f, -0.91f, -2.13f, -2.12f, -2.13f, CLOSE, R_MOVE_TO, 0, -3, R_V_LINE_TO, 1.5f, R_CUBIC_TO, 2.01f, 0, 3.62f,
    1.63f, 3.62f, 3.63f, R_H_LINE_TO, 1.5f, R_CUBIC_TO, 0, -2.79f, -2.31f, -5.13f, -5.12f, -5.13f, CLOSE, R_MOVE_TO, 0, -2.81f, V_LINE_TO, 8, R_CUBIC_TO, 3.61f,
    0, 6.5f, 2.91f, 6.5f, 6.5f, H_LINE_TO, 8, R_CUBIC_TO, 0, -4.39f, -3.59f, -7.94f, -8, -7.94f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kMediaRouterIdleRepList, kMediaRouterIdleIcon, { kMediaRouterIdlePath, std::size(kMediaRouterIdlePath) })
VECTOR_ICON_REP_TEMPLATE(kMediaRouterIdleChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 10, 10, CLOSE, R_MOVE_TO, 6.5f, 6, R_H_LINE_TO,
    -5, R_CUBIC_TO, 0, -0.25f, -0.01f, -0.5f, -0.03f, -0.75f, R_CUBIC_TO, -0.02f, -0.25f, -0.05f, -0.5f, -0.09f, -0.75f, H_LINE_TO, 16.5f, R_V_LINE_TO, -9,
    R_H_LINE_TO, -13, R_V_LINE_TO, 1.13f, R_CUBIC_TO, -0.25f, -0.04f, -0.5f, -0.07f, -0.75f, -0.09f, R_CUBIC_TO, -0.25f, -0.02f, -0.5f, -0.03f, -0.75f, -0.03f,
    R_V_LINE_TO, -1, R_CUBIC_TO, 0, -0.41f, 0.15f, -0.77f, 0.44f, -1.06f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 3.5f, 4, R_H_LINE_TO, 13, R_CUBIC_TO, 0.41f, 0, 0.77f,
    0.15f, 1.06f, 0.44f, R_CUBIC_TO, 0.29f, 0.29f, 0.44f, 0.65f, 0.44f, 1.06f, R_V_LINE_TO, 9.01f, R_CUBIC_TO, 0, 0.41f, -0.15f, 0.76f, -0.44f, 1.06f, ARC_TO,
    1.44f, 1.44f, 0, 0, 1, 16.5f, 16, CLOSE, MOVE_TO, 2, 16, R_V_LINE_TO, -2, R_CUBIC_TO, 0.56f, 0, 1.03f, 0.2f, 1.42f, 0.58f, R_CUBIC_TO, 0.39f, 0.39f, 0.58f,
    0.86f, 0.58f, 1.42f, CLOSE, R_MOVE_TO, 3.5f, 0, R_CUBIC_TO, 0, -0.97f, -0.34f, -1.8f, -1.02f, -2.48f, ARC_TO, 3.38f, 3.38f, 0, 0, 0, 2, 12.5f, V_LINE_TO,
    11, R_CUBIC_TO, 1.39f, 0, 2.57f, 0.48f, 3.54f, 1.46f, CUBIC_TO, 6.52f, 13.43f, 7, 14.61f, 7, 16, CLOSE, R_MOVE_TO, 3, 0, R_ARC_TO, 6.3f, 6.3f, 0, 0, 0,
    -0.51f, -2.53f, R_ARC_TO, 6.56f, 6.56f, 0, 0, 0, -1.39f, -2.07f, R_ARC_TO, 6.56f, 6.56f, 0, 0, 0, -2.07f, -1.39f, ARC_TO, 6.3f, 6.3f, 0, 0, 0, 2, 9.5f,
    V_LINE_TO, 8, R_CUBIC_TO, 1.11f, 0, 2.15f, 0.21f, 3.12f, 0.63f, ARC_TO, 8.09f, 8.09f, 0, 0, 1, 7.66f, 10.34f, R_ARC_TO, 8.09f, 8.09f, 0, 0, 1, 1.72f, 2.54f,
    CUBIC_TO, 9.79f, 13.85f, 10, 14.89f, 10, 16, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kMediaRouterIdleChromeRefreshRepList, kMediaRouterIdleChromeRefreshIcon,
    { kMediaRouterIdleChromeRefreshPath, std::size(kMediaRouterIdleChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kMediaRouterPausedPath, CANVAS_DIMENSIONS, 20, MOVE_TO, 15.13f, 7.19f, R_H_LINE_TO, 1.08f, V_LINE_TO, 3.61f, R_H_LINE_TO, -1.08f,
    CLOSE, R_MOVE_TO, -2, 0, R_H_LINE_TO, 1.08f, V_LINE_TO, 3.61f, R_H_LINE_TO, -1.08f, CLOSE, MOVE_TO, 10, 10, CLOSE, R_MOVE_TO, -8.17f, 4.09f, R_CUBIC_TO,
    0.58f, 0, 1.07f, 0.2f, 1.47f, 0.61f, R_CUBIC_TO, 0.4f, 0.41f, 0.61f, 0.9f, 0.61f, 1.47f, H_LINE_TO, 1.83f, CLOSE, R_MOVE_TO, 0, -3.07f, R_CUBIC_TO, 1.43f,
    0, 2.65f, 0.5f, 3.65f, 1.5f, R_CUBIC_TO, 1, 1, 1.5f, 2.22f, 1.5f, 3.65f, H_LINE_TO, 5.41f, R_CUBIC_TO, 0, -0.99f, -0.35f, -1.84f, -1.05f, -2.53f, R_ARC_TO,
    3.46f, 3.46f, 0, 0, 0, -2.53f, -1.04f, CLOSE, R_MOVE_TO, 0, -3.07f, R_CUBIC_TO, 1.15f, 0, 2.21f, 0.22f, 3.21f, 0.64f, R_ARC_TO, 8.32f, 8.32f, 0, 0, 1,
    2.61f, 1.77f, R_ARC_TO, 8.23f, 8.23f, 0, 0, 1, 1.77f, 2.61f, R_CUBIC_TO, 0.43f, 1, 0.64f, 2.07f, 0.64f, 3.21f, H_LINE_TO, 8.49f, R_CUBIC_TO, 0, -0.92f,
    -0.17f, -1.78f, -0.52f, -2.59f, R_ARC_TO, 6.8f, 6.8f, 0, 0, 0, -1.43f, -2.12f, R_ARC_TO, 6.8f, 6.8f, 0, 0, 0, -2.12f, -1.43f, R_ARC_TO, 6.45f, 6.45f, 0, 0,
    0, -2.59f, -0.52f, CLOSE, R_MOVE_TO, 14.61f, 8.23f, R_H_LINE_TO, -4.88f, R_ARC_TO, 9.06f, 9.06f, 0, 0, 0, -0.16f, -1.73f, R_H_LINE_TO, 5.05f, R_V_LINE_TO,
    -3.87f, R_CUBIC_TO, 0.32f, -0.1f, 0.62f, -0.22f, 0.91f, -0.37f, R_CUBIC_TO, 0.29f, -0.15f, 0.56f, -0.34f, 0.82f, -0.56f, R_V_LINE_TO, 4.79f, R_CUBIC_TO, 0,
    0.48f, -0.17f, 0.89f, -0.5f, 1.23f, R_CUBIC_TO, -0.34f, 0.34f, -0.75f, 0.5f, -1.22f, 0.5f, CLOSE, MOVE_TO, 1.83f, 6.44f, V_LINE_TO, 5.56f, R_CUBIC_TO, 0,
    -0.48f, 0.17f, -0.89f, 0.5f, -1.22f, R_ARC_TO, 1.67f, 1.67f, 0, 0, 1, 1.22f, -0.5f, R_H_LINE_TO, 5.84f, R_ARC_TO, 4.7f, 4.7f, 0, 0, 0, -0.18f, 0.84f,
    R_CUBIC_TO, -0.04f, 0.29f, -0.05f, 0.59f, -0.04f, 0.88f, H_LINE_TO, 3.56f, R_V_LINE_TO, 1.05f, R_ARC_TO, 9.19f, 9.19f, 0, 0, 0, -0.86f, -0.12f, R_ARC_TO,
    9.18f, 9.18f, 0, 0, 0, -0.86f, -0.04f, CLOSE, R_MOVE_TO, 12.83f, 2.96f, R_CUBIC_TO, -1.1f, 0, -2.05f, -0.39f, -2.83f, -1.17f, R_CUBIC_TO, -0.78f, -0.78f,
    -1.17f, -1.73f, -1.17f, -2.83f, R_CUBIC_TO, 0, -1.11f, 0.39f, -2.05f, 1.17f, -2.83f, R_CUBIC_TO, 0.78f, -0.78f, 1.73f, -1.17f, 2.84f, -1.17f, R_CUBIC_TO,
    1.11f, 0, 2.05f, 0.39f, 2.83f, 1.17f, R_CUBIC_TO, 0.78f, 0.78f, 1.16f, 1.73f, 1.16f, 2.84f, R_CUBIC_TO, 0, 1.11f, -0.39f, 2.05f, -1.17f, 2.83f, R_CUBIC_TO,
    -0.78f, 0.78f, -1.72f, 1.16f, -2.83f, 1.16f, CLOSE, R_MOVE_TO, 0, 0, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kMediaRouterPausedRepList, kMediaRouterPausedIcon, { kMediaRouterPausedPath, std::size(kMediaRouterPausedPath) })
VECTOR_ICON_REP_TEMPLATE(kMediaRouterWarningChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 10, 10, CLOSE, R_MOVE_TO, -8, 4, R_CUBIC_TO,
    0.56f, 0, 1.03f, 0.2f, 1.42f, 0.58f, R_CUBIC_TO, 0.39f, 0.39f, 0.58f, 0.86f, 0.58f, 1.42f, H_LINE_TO, 2, CLOSE, R_MOVE_TO, 0, -3, R_CUBIC_TO, 1.39f, 0,
    2.57f, 0.48f, 3.54f, 1.46f, CUBIC_TO, 6.52f, 13.43f, 7, 14.61f, 7, 16, H_LINE_TO, 5.5f, R_CUBIC_TO, 0, -0.97f, -0.34f, -1.8f, -1.02f, -2.48f, ARC_TO, 3.38f,
    3.38f, 0, 0, 0, 2, 12.5f, CLOSE, R_MOVE_TO, 0, -3, R_CUBIC_TO, 1.11f, 0, 2.15f, 0.21f, 3.12f, 0.63f, ARC_TO, 8.09f, 8.09f, 0, 0, 1, 7.66f, 10.34f, R_ARC_TO,
    8.09f, 8.09f, 0, 0, 1, 1.72f, 2.54f, CUBIC_TO, 9.79f, 13.85f, 10, 14.89f, 10, 16, H_LINE_TO, 8.5f, R_ARC_TO, 6.3f, 6.3f, 0, 0, 0, -0.51f, -2.53f, R_ARC_TO,
    6.56f, 6.56f, 0, 0, 0, -1.39f, -2.07f, R_ARC_TO, 6.56f, 6.56f, 0, 0, 0, -2.07f, -1.39f, ARC_TO, 6.3f, 6.3f, 0, 0, 0, 2, 9.5f, CLOSE, R_MOVE_TO, 14.5f, 8,
    R_H_LINE_TO, -5, R_CUBIC_TO, 0, -0.25f, -0.01f, -0.5f, -0.03f, -0.75f, R_CUBIC_TO, -0.02f, -0.25f, -0.05f, -0.5f, -0.09f, -0.75f, H_LINE_TO, 16.5f,
    R_V_LINE_TO, -3.87f, R_CUBIC_TO, 0.28f, -0.1f, 0.54f, -0.23f, 0.79f, -0.37f, ARC_TO, 4.05f, 4.05f, 0, 0, 0, 18, 9.75f, R_V_LINE_TO, 4.75f, R_CUBIC_TO, 0,
    0.42f, -0.15f, 0.77f, -0.44f, 1.06f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 16.5f, 16, CLOSE, MOVE_TO, 2, 6.5f, R_V_LINE_TO, -1, R_CUBIC_TO, 0, -0.41f, 0.15f,
    -0.77f, 0.44f, -1.06f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 3.5f, 4, R_H_LINE_TO, 5.71f, R_ARC_TO, 5.64f, 5.64f, 0, 0, 0, -0.16f, 0.73f, CUBIC_TO, 9.02f, 4.98f,
    9, 5.24f, 9, 5.5f, H_LINE_TO, 3.5f, R_V_LINE_TO, 1.13f, R_CUBIC_TO, -0.25f, -0.04f, -0.5f, -0.07f, -0.75f, -0.09f, R_CUBIC_TO, -0.25f, -0.02f, -0.5f,
    -0.03f, -0.75f, -0.03f, CLOSE, R_MOVE_TO, 12.5f, 3, R_CUBIC_TO, -1.11f, 0, -2.05f, -0.39f, -2.83f, -1.17f, ARC_TO, 3.87f, 3.87f, 0, 0, 1, 10.5f, 5.5f,
    R_CUBIC_TO, 0, -1.11f, 0.39f, -2.05f, 1.17f, -2.83f, ARC_TO, 3.87f, 3.87f, 0, 0, 1, 14.5f, 1.5f, R_CUBIC_TO, 1.11f, 0, 2.05f, 0.39f, 2.83f, 1.17f, ARC_TO,
    3.87f, 3.87f, 0, 0, 1, 18.5f, 5.5f, R_CUBIC_TO, 0, 1.11f, -0.39f, 2.05f, -1.17f, 2.83f, ARC_TO, 3.87f, 3.87f, 0, 0, 1, 14.5f, 9.5f, CLOSE, R_MOVE_TO, 0, -2,
    R_CUBIC_TO, 0.13f, 0, 0.25f, -0.05f, 0.35f, -0.15f, ARC_TO, 0.49f, 0.49f, 0, 0, 0, 15, 7, R_CUBIC_TO, 0, -0.13f, -0.05f, -0.25f, -0.15f, -0.35f, ARC_TO,
    0.49f, 0.49f, 0, 0, 0, 14.5f, 6.5f, R_CUBIC_TO, -0.13f, 0, -0.25f, 0.05f, -0.35f, 0.15f, ARC_TO, 0.49f, 0.49f, 0, 0, 0, 14, 7, R_CUBIC_TO, 0, 0.13f, 0.05f,
    0.25f, 0.15f, 0.35f, R_ARC_TO, 0.49f, 0.49f, 0, 0, 0, 0.35f, 0.15f, CLOSE, R_MOVE_TO, -0.5f, -2, R_H_LINE_TO, 1, R_V_LINE_TO, -2, R_H_LINE_TO, -1, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kMediaRouterWarningChromeRefreshRepList, kMediaRouterWarningChromeRefreshIcon,
    { kMediaRouterWarningChromeRefreshPath, std::size(kMediaRouterWarningChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kMediaSeekBackwardPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 11, 18, V_LINE_TO, 6, R_LINE_TO, -8.5f, 6, R_LINE_TO, 8.5f, 6, CLOSE,
    R_MOVE_TO, 0.5f, -6, R_LINE_TO, 8.5f, 6, V_LINE_TO, 6, R_LINE_TO, -8.5f, 6, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kMediaSeekBackwardRepList, kMediaSeekBackwardIcon, { kMediaSeekBackwardPath, std::size(kMediaSeekBackwardPath) })
VECTOR_ICON_REP_TEMPLATE(kMediaSeekForwardPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 4, 18, R_LINE_TO, 8.5f, -6, LINE_TO, 4, 6, R_V_LINE_TO, 12, CLOSE, R_MOVE_TO, 9,
    -12, R_V_LINE_TO, 12, R_LINE_TO, 8.5f, -6, LINE_TO, 13, 6, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kMediaSeekForwardRepList, kMediaSeekForwardIcon, { kMediaSeekForwardPath, std::size(kMediaSeekForwardPath) })
VECTOR_ICON_REP_TEMPLATE(kMicPath, MOVE_TO, 24, 30, R_CUBIC_TO, 3.31f, 0, 5.98f, -2.69f, 5.98f, -6, LINE_TO, 30, 12, R_CUBIC_TO, 0, -3.32f, -2.68f, -6, -6, -6,
    R_CUBIC_TO, -3.31f, 0, -6, 2.68f, -6, 6, R_V_LINE_TO, 12, R_CUBIC_TO, 0, 3.31f, 2.69f, 6, 6, 6, CLOSE, R_MOVE_TO, 10.6f, -6, R_CUBIC_TO, 0, 6, -5.07f,
    10.2f, -10.6f, 10.2f, R_CUBIC_TO, -5.52f, 0, -10.6f, -4.2f, -10.6f, -10.2f, H_LINE_TO, 10, R_CUBIC_TO, 0, 6.83f, 5.44f, 12.47f, 12, 13.44f, V_LINE_TO, 44,
    R_H_LINE_TO, 4, R_V_LINE_TO, -6.56f, R_CUBIC_TO, 6.56f, -0.97f, 12, -6.61f, 12, -13.44f, R_H_LINE_TO, -3.4f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kMicRepList, kMicIcon, { kMicPath, std::size(kMicPath) })
VECTOR_ICON_REP_TEMPLATE(kMicChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 10, 12, R_ARC_TO, 2.4f, 2.4f, 0, 0, 1, -1.77f, -0.73f,
    ARC_TO, 2.4f, 2.4f, 0, 0, 1, 7.5f, 9.5f, R_V_LINE_TO, -5, R_CUBIC_TO, 0, -0.69f, 0.24f, -1.28f, 0.73f, -1.77f, ARC_TO, 2.4f, 2.4f, 0, 0, 1, 10, 2,
    R_CUBIC_TO, 0.7f, 0, 1.29f, 0.24f, 1.77f, 0.73f, R_CUBIC_TO, 0.49f, 0.49f, 0.73f, 1.08f, 0.73f, 1.77f, R_V_LINE_TO, 5, R_CUBIC_TO, 0, 0.7f, -0.24f, 1.29f,
    -0.73f, 1.77f, ARC_TO, 2.4f, 2.4f, 0, 0, 1, 10, 12, CLOSE, R_MOVE_TO, 0, -5, CLOSE, R_MOVE_TO, -0.75f, 10, R_V_LINE_TO, -2.06f, R_CUBIC_TO, -1.37f, -0.18f,
    -2.51f, -0.78f, -3.4f, -1.81f, CUBIC_TO, 4.95f, 12.1f, 4.5f, 10.89f, 4.5f, 9.5f, H_LINE_TO, 6, R_CUBIC_TO, 0, 1.11f, 0.39f, 2.05f, 1.17f, 2.83f, R_CUBIC_TO,
    0.78f, 0.78f, 1.73f, 1.17f, 2.83f, 1.17f, R_CUBIC_TO, 1.11f, 0, 2.05f, -0.39f, 2.83f, -1.17f, CUBIC_TO, 13.61f, 11.55f, 14, 10.61f, 14, 9.5f, R_H_LINE_TO,
    1.5f, R_CUBIC_TO, 0, 1.39f, -0.45f, 2.6f, -1.35f, 3.63f, R_CUBIC_TO, -0.89f, 1.03f, -2.03f, 1.63f, -3.4f, 1.81f, V_LINE_TO, 17, CLOSE, R_MOVE_TO, 0.75f,
    -6.5f, R_CUBIC_TO, 0.28f, 0, 0.52f, -0.1f, 0.71f, -0.29f, ARC_TO, 0.96f, 0.96f, 0, 0, 0, 11, 9.5f, R_V_LINE_TO, -5, R_ARC_TO, 0.96f, 0.96f, 0, 0, 0, -0.29f,
    -0.71f, R_ARC_TO, 0.96f, 0.96f, 0, 0, 0, -0.71f, -0.29f, R_ARC_TO, 0.96f, 0.96f, 0, 0, 0, -0.71f, 0.29f, R_ARC_TO, 0.96f, 0.96f, 0, 0, 0, -0.29f, 0.71f,
    R_V_LINE_TO, 5, R_CUBIC_TO, 0, 0.28f, 0.1f, 0.52f, 0.29f, 0.71f, R_CUBIC_TO, 0.19f, 0.19f, 0.43f, 0.29f, 0.71f, 0.29f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kMicChromeRefreshRepList, kMicChromeRefreshIcon, { kMicChromeRefreshPath, std::size(kMicChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kMicOffPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 19, 11, R_H_LINE_TO, -2, R_CUBIC_TO, 0, 0.91f, -0.25f, 1.76f, -0.68f, 2.49f, R_LINE_TO,
    1.45f, 1.45f, CUBIC_TO, 18.54f, 13.82f, 19, 12.47f, 19, 11, CLOSE, MOVE_TO, 2.81f, 2.81f, LINE_TO, 1.39f, 4.22f, R_LINE_TO, 11.66f, 11.66f, CUBIC_TO,
    12.71f, 15.96f, 12.36f, 16, 12, 16, R_CUBIC_TO, -2.76f, 0, -5, -2.24f, -5, -5, H_LINE_TO, 5, R_CUBIC_TO, 0, 3.53f, 2.61f, 6.43f, 6, 6.92f, V_LINE_TO, 21,
    R_H_LINE_TO, 2, R_V_LINE_TO, -3.08f, R_CUBIC_TO, 0.57f, -0.08f, 1.12f, -0.24f, 1.64f, -0.45f, R_LINE_TO, 5.14f, 5.14f, R_LINE_TO, 1.41f, -1.41f, LINE_TO,
    2.81f, 2.81f, CLOSE, MOVE_TO, 15, 11, V_LINE_TO, 5, R_CUBIC_TO, 0, -1.66f, -1.34f, -3, -3, -3, CUBIC_TO_SHORTHAND, 9, 3.34f, 9, 5, R_V_LINE_TO, 1.17f,
    R_LINE_TO, 5.81f, 5.81f, CUBIC_TO, 14.92f, 11.67f, 15, 11.35f, 15, 11, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kMicOffRepList, kMicOffIcon, { kMicOffPath, std::size(kMicOffPath) })
VECTOR_ICON_REP_TEMPLATE(kMicOffChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 14.61f, 12.48f, LINE_TO, 13.5f, 11.38f, R_CUBIC_TO, 0.15f,
    -0.29f, 0.27f, -0.59f, 0.36f, -0.9f, R_CUBIC_TO, 0.09f, -0.31f, 0.13f, -0.64f, 0.13f, -0.97f, H_LINE_TO, 15.5f, R_CUBIC_TO, 0, 0.53f, -0.08f, 1.04f, -0.23f,
    1.55f, R_CUBIC_TO, -0.15f, 0.51f, -0.37f, 0.98f, -0.66f, 1.43f, CLOSE, MOVE_TO, 9.94f, 7.86f, CLOSE, R_MOVE_TO, 2.44f, 2.4f, LINE_TO, 11, 8.88f, V_LINE_TO,
    4.5f, R_ARC_TO, 0.96f, 0.96f, 0, 0, 0, -0.29f, -0.71f, R_ARC_TO, 0.96f, 0.96f, 0, 0, 0, -0.71f, -0.29f, R_ARC_TO, 0.96f, 0.96f, 0, 0, 0, -0.71f, 0.29f,
    R_ARC_TO, 0.96f, 0.96f, 0, 0, 0, -0.29f, 0.71f, R_V_LINE_TO, 2.38f, LINE_TO, 7.5f, 5.37f, V_LINE_TO, 4.5f, R_CUBIC_TO, 0, -0.69f, 0.24f, -1.28f, 0.73f,
    -1.77f, ARC_TO, 2.4f, 2.4f, 0, 0, 1, 10, 2, R_CUBIC_TO, 0.7f, 0, 1.29f, 0.24f, 1.77f, 0.73f, R_CUBIC_TO, 0.49f, 0.49f, 0.73f, 1.08f, 0.73f, 1.77f,
    R_V_LINE_TO, 5, R_ARC_TO, 2.43f, 2.43f, 0, 0, 1, -0.12f, 0.75f, CLOSE, MOVE_TO, 9.25f, 17, R_V_LINE_TO, -2.06f, R_CUBIC_TO, -1.37f, -0.17f, -2.51f, -0.76f,
    -3.41f, -1.8f, CUBIC_TO, 4.95f, 12.1f, 4.5f, 10.89f, 4.5f, 9.5f, H_LINE_TO, 6, R_CUBIC_TO, 0, 1.11f, 0.39f, 2.05f, 1.17f, 2.83f, CUBIC_TO, 7.95f, 13.11f,
    8.89f, 13.5f, 10, 13.5f, R_CUBIC_TO, 0.47f, 0, 0.92f, -0.09f, 1.34f, -0.27f, R_ARC_TO, 4.73f, 4.73f, 0, 0, 0, 1.18f, -0.73f, R_LINE_TO, 1.09f, 1.08f,
    R_ARC_TO, 6.51f, 6.51f, 0, 0, 1, -1.33f, 0.89f, R_ARC_TO, 4.8f, 4.8f, 0, 0, 1, -1.52f, 0.47f, V_LINE_TO, 17, CLOSE, MOVE_TO, 16, 18.13f, LINE_TO, 1.88f,
    3.98f, R_LINE_TO, 1.06f, -1.06f, R_LINE_TO, 14.12f, 14.15f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kMicOffChromeRefreshRepList, kMicOffChromeRefreshIcon, { kMicOffChromeRefreshPath, std::size(kMicOffChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kMidiPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 19, 3, H_LINE_TO, 5, CUBIC_TO, 3.9f, 3, 3, 3.9f, 3, 5, R_V_LINE_TO, 14, R_CUBIC_TO, 0, 1.1f,
    0.9f, 2, 2, 2, R_H_LINE_TO, 14, R_CUBIC_TO, 1.1f, 0, 2, -0.9f, 2, -2, V_LINE_TO, 5, CUBIC_TO, 21, 3.9f, 20.1f, 3, 19, 3, CLOSE, MOVE_TO, 14, 14.5f,
    R_H_LINE_TO, 0.25f, V_LINE_TO, 19, R_H_LINE_TO, -4.5f, R_V_LINE_TO, -4.5f, H_LINE_TO, 10, R_CUBIC_TO, 0.55f, 0, 1, -0.45f, 1, -1, V_LINE_TO, 5, R_H_LINE_TO,
    2, R_V_LINE_TO, 8.5f, CUBIC_TO, 13, 14.05f, 13.45f, 14.5f, 14, 14.5f, CLOSE, MOVE_TO, 5, 5, R_H_LINE_TO, 2, R_V_LINE_TO, 8.5f, R_CUBIC_TO, 0, 0.55f, 0.45f,
    1, 1, 1, R_H_LINE_TO, 0.25f, V_LINE_TO, 19, H_LINE_TO, 5, V_LINE_TO, 5, CLOSE, MOVE_TO, 19, 19, R_H_LINE_TO, -3.25f, R_V_LINE_TO, -4.5f, H_LINE_TO, 16,
    R_CUBIC_TO, 0.55f, 0, 1, -0.45f, 1, -1, V_LINE_TO, 5, R_H_LINE_TO, 2, V_LINE_TO, 19, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kMidiRepList, kMidiIcon, { kMidiPath, std::size(kMidiPath) })
VECTOR_ICON_REP_TEMPLATE(kMidiChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 4.5f, 17, R_CUBIC_TO, -0.4f, 0, -0.75f, -0.15f, -1.05f,
    -0.45f, R_CUBIC_TO, -0.3f, -0.3f, -0.45f, -0.65f, -0.45f, -1.05f, R_V_LINE_TO, -11, R_CUBIC_TO, 0, -0.41f, 0.15f, -0.77f, 0.45f, -1.06f, ARC_TO, 1.45f,
    1.45f, 0, 0, 1, 4.5f, 3, R_H_LINE_TO, 11, R_CUBIC_TO, 0.41f, 0, 0.77f, 0.15f, 1.06f, 0.44f, R_CUBIC_TO, 0.29f, 0.29f, 0.44f, 0.65f, 0.44f, 1.06f,
    R_V_LINE_TO, 11, R_CUBIC_TO, 0, 0.4f, -0.15f, 0.75f, -0.44f, 1.05f, R_CUBIC_TO, -0.29f, 0.3f, -0.64f, 0.45f, -1.06f, 0.45f, CLOSE, R_MOVE_TO, 0, -1.5f,
    H_LINE_TO, 7, V_LINE_TO, 12, R_H_LINE_TO, -0.5f, R_ARC_TO, 0.47f, 0.47f, 0, 0, 1, -0.35f, -0.14f, ARC_TO, 0.47f, 0.47f, 0, 0, 1, 6, 11.5f, R_V_LINE_TO, -7,
    H_LINE_TO, 4.5f, CLOSE, R_MOVE_TO, 8.5f, 0, R_H_LINE_TO, 2.5f, R_V_LINE_TO, -11, H_LINE_TO, 14, R_V_LINE_TO, 7, R_CUBIC_TO, 0, 0.14f, -0.05f, 0.26f, -0.14f,
    0.36f, ARC_TO, 0.47f, 0.47f, 0, 0, 1, 13.5f, 12, H_LINE_TO, 13, CLOSE, R_MOVE_TO, -5, 0, R_H_LINE_TO, 4, V_LINE_TO, 12, R_H_LINE_TO, -0.5f, R_ARC_TO, 0.47f,
    0.47f, 0, 0, 1, -0.35f, -0.14f, ARC_TO, 0.47f, 0.47f, 0, 0, 1, 11, 11.5f, R_V_LINE_TO, -7, H_LINE_TO, 9, R_V_LINE_TO, 7, R_CUBIC_TO, 0, 0.14f, -0.05f,
    0.26f, -0.14f, 0.36f, ARC_TO, 0.47f, 0.47f, 0, 0, 1, 8.5f, 12, H_LINE_TO, 8, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kMidiChromeRefreshRepList, kMidiChromeRefreshIcon, { kMidiChromeRefreshPath, std::size(kMidiChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kMidiOffChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 16, 18.13f, LINE_TO, 14.88f, 17, H_LINE_TO, 4.5f,
    R_CUBIC_TO, -0.41f, 0, -0.77f, -0.15f, -1.06f, -0.44f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 3, 15.5f, V_LINE_TO, 5.13f, LINE_TO, 1.88f, 4, R_LINE_TO, 1.06f,
    -1.06f, R_LINE_TO, 14.12f, 14.13f, CLOSE, R_MOVE_TO, 1, -3.25f, R_LINE_TO, -1.5f, -1.5f, V_LINE_TO, 4.5f, H_LINE_TO, 14, R_V_LINE_TO, 7, R_ARC_TO, 0.43f,
    0.43f, 0, 0, 1, -0.1f, 0.27f, LINE_TO, 11, 8.88f, V_LINE_TO, 4.5f, H_LINE_TO, 9, R_V_LINE_TO, 2.38f, LINE_TO, 5.13f, 3, H_LINE_TO, 15.5f, R_CUBIC_TO, 0.41f,
    0, 0.77f, 0.15f, 1.06f, 0.44f, R_CUBIC_TO, 0.29f, 0.29f, 0.44f, 0.65f, 0.44f, 1.06f, CLOSE, MOVE_TO, 4.5f, 15.5f, H_LINE_TO, 7, V_LINE_TO, 12, R_H_LINE_TO,
    -0.5f, R_ARC_TO, 0.47f, 0.47f, 0, 0, 1, -0.35f, -0.14f, ARC_TO, 0.47f, 0.47f, 0, 0, 1, 6, 11.5f, V_LINE_TO, 8.13f, R_LINE_TO, -1.5f, -1.5f, CLOSE,
    R_MOVE_TO, 3.5f, 0, R_H_LINE_TO, 4, R_V_LINE_TO, -1.37f, R_LINE_TO, -3, -3, R_V_LINE_TO, 0.38f, R_ARC_TO, 0.48f, 0.48f, 0, 0, 1, -0.14f, 0.36f, ARC_TO,
    0.48f, 0.48f, 0, 0, 1, 8.5f, 12, H_LINE_TO, 8, CLOSE, R_MOVE_TO, 5, -0.04f, R_H_LINE_TO, 0.19f, LINE_TO, 13, 15.27f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kMidiOffChromeRefreshRepList, kMidiOffChromeRefreshIcon, { kMidiOffChromeRefreshPath, std::size(kMidiOffChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kNotSecureWarningPath, CANVAS_DIMENSIONS, 32, MOVE_TO, 4, 27, R_H_LINE_TO, 25, LINE_TO, 16.5f, 5, LINE_TO, 4, 27, CLOSE, R_MOVE_TO, 14,
    -3, R_H_LINE_TO, -3, R_V_LINE_TO, -3, R_H_LINE_TO, 3, R_V_LINE_TO, 3, CLOSE, R_MOVE_TO, 0, -5, R_H_LINE_TO, -3, R_V_LINE_TO, -6, R_H_LINE_TO, 3,
    R_V_LINE_TO, 6, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kNotSecureWarning16Path, CANVAS_DIMENSIONS, 16, MOVE_TO, 0.5f, 14, R_H_LINE_TO, 15, LINE_TO, 8, 1, LINE_TO, 0.5f, 14, CLOSE, MOVE_TO,
    9, 12, H_LINE_TO, 7, R_V_LINE_TO, -2, R_H_LINE_TO, 2, R_V_LINE_TO, 2, CLOSE, R_MOVE_TO, 0, -3, H_LINE_TO, 7, V_LINE_TO, 6, R_H_LINE_TO, 2, R_V_LINE_TO, 3,
    CLOSE)
VECTOR_ICON_TEMPLATE_CC(kNotSecureWarningRepList, kNotSecureWarningIcon, { kNotSecureWarningPath, std::size(kNotSecureWarningPath) },
    { kNotSecureWarning16Path, std::size(kNotSecureWarning16Path) })
VECTOR_ICON_REP_TEMPLATE(kNotSecureWarningChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, R_MOVE_TO, 1, 17, R_LINE_TO, 9, -15, R_LINE_TO, 9, 15,
    CLOSE, R_MOVE_TO, 2.65f, -1.5f, R_H_LINE_TO, 12.71f, LINE_TO, 10, 4.92f, CLOSE, R_MOVE_TO, 6.35f, -1, R_CUBIC_TO, 0.21f, 0, 0.39f, -0.07f, 0.54f, -0.21f,
    R_ARC_TO, 0.72f, 0.72f, 0, 0, 0, 0.22f, -0.53f, R_CUBIC_TO, 0, -0.21f, -0.07f, -0.39f, -0.21f, -0.53f, R_ARC_TO, 0.72f, 0.72f, 0, 0, 0, -0.53f, -0.22f,
    R_CUBIC_TO, -0.21f, 0, -0.39f, 0.07f, -0.53f, 0.22f, R_ARC_TO, 0.72f, 0.72f, 0, 0, 0, -0.22f, 0.53f, R_CUBIC_TO, 0, 0.21f, 0.07f, 0.39f, 0.22f, 0.54f,
    R_CUBIC_TO, 0.14f, 0.14f, 0.32f, 0.22f, 0.53f, 0.22f, CLOSE, MOVE_TO, 9.25f, 12, R_H_LINE_TO, 1.5f, V_LINE_TO, 8, R_H_LINE_TO, -1.5f, CLOSE, R_MOVE_TO,
    0.75f, -1.79f, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kNotSecureWarningChromeRefresh16Path, CANVAS_DIMENSIONS, 16, FILL_RULE_NONZERO, MOVE_TO, 0.68f, 13.67f, LINE_TO, 8, 1.47f, R_LINE_TO,
    7.32f, 12.2f, CLOSE, R_MOVE_TO, 2.33f, -1.32f, R_H_LINE_TO, 9.97f, LINE_TO, 8, 4.05f, CLOSE, R_MOVE_TO, 4.98f, -0.75f, R_CUBIC_TO, 0.17f, 0, 0.32f, -0.06f,
    0.44f, -0.18f, R_ARC_TO, 0.6f, 0.6f, 0, 0, 0, 0.18f, -0.44f, R_ARC_TO, 0.62f, 0.62f, 0, 0, 0, -0.62f, -0.62f, R_ARC_TO, 0.6f, 0.6f, 0, 0, 0, -0.44f, 0.18f,
    R_ARC_TO, 0.58f, 0.58f, 0, 0, 0, -0.18f, 0.43f, R_ARC_TO, 0.62f, 0.62f, 0, 0, 0, 0.62f, 0.63f, CLOSE, R_MOVE_TO, -0.6f, -1.99f, R_H_LINE_TO, 1.2f,
    V_LINE_TO, 6.45f, H_LINE_TO, 7.4f, CLOSE, MOVE_TO, 8, 8.2f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kNotSecureWarningChromeRefreshRepList, kNotSecureWarningChromeRefreshIcon,
    { kNotSecureWarningChromeRefreshPath, std::size(kNotSecureWarningChromeRefreshPath) },
    { kNotSecureWarningChromeRefresh16Path, std::size(kNotSecureWarningChromeRefresh16Path) })
VECTOR_ICON_REP_TEMPLATE(kNotSecureWarningOffChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 10, 14.48f, R_ARC_TO, 0.76f, 0.76f, 0, 0, 1,
    -0.55f, -0.22f, R_ARC_TO, 0.74f, 0.74f, 0, 0, 1, -0.23f, -0.55f, R_CUBIC_TO, 0, -0.21f, 0.07f, -0.4f, 0.22f, -0.55f, R_ARC_TO, 0.73f, 0.73f, 0, 0, 1, 0.55f,
    -0.23f, R_CUBIC_TO, 0.22f, 0, 0.4f, 0.08f, 0.55f, 0.22f, R_ARC_TO, 0.73f, 0.73f, 0, 0, 1, 0.23f, 0.55f, R_ARC_TO, 0.76f, 0.76f, 0, 0, 1, -0.22f, 0.55f,
    R_ARC_TO, 0.73f, 0.73f, 0, 0, 1, -0.55f, 0.23f, CLOSE, MOVE_TO, 9.25f, 12, V_LINE_TO, 9.25f, R_LINE_TO, 1.5f, 1.5f, V_LINE_TO, 12, CLOSE, R_MOVE_TO, 9.78f,
    4.91f, R_LINE_TO, -4.8f, -4.8f, LINE_TO, 10, 5.06f, LINE_TO, 8.95f, 6.82f, LINE_TO, 7.73f, 5.6f, LINE_TO, 10, 1.83f, CLOSE, MOVE_TO, 3.77f, 15.43f,
    R_H_LINE_TO, 9.43f, LINE_TO, 7.3f, 9.54f, CLOSE, R_MOVE_TO, 13.31f, 3.88f, R_LINE_TO, -2.22f, -2.22f, R_H_LINE_TO, -14, LINE_TO, 6.11f, 8.34f, LINE_TO,
    0.7f, 2.93f, R_LINE_TO, 1.11f, -1.11f, R_LINE_TO, 16.38f, 16.38f, CLOSE, R_MOVE_TO, -6.82f, -6.82f, CLOSE, R_MOVE_TO, 1.34f, -3.03f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kNotSecureWarningOffChromeRefreshRepList, kNotSecureWarningOffChromeRefreshIcon,
    { kNotSecureWarningOffChromeRefreshPath, std::size(kNotSecureWarningOffChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kNotUploadedPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 16.5f, 18.83f, LINE_TO, 14.29f, 16.67f, H_LINE_TO, 5.42f, R_CUBIC_TO, -1.28f, 0,
    -2.36f, -0.44f, -3.25f, -1.33f, CUBIC_TO, 1.28f, 14.44f, 0.83f, 13.36f, 0.83f, 12.08f, R_CUBIC_TO, 0, -1.07f, 0.33f, -2.02f, 0.98f, -2.85f, R_CUBIC_TO,
    0.67f, -0.83f, 1.52f, -1.37f, 2.56f, -1.6f, R_CUBIC_TO, 0.04f, -0.11f, 0.08f, -0.21f, 0.13f, -0.31f, R_CUBIC_TO, 0.04f, -0.11f, 0.08f, -0.23f, 0.13f,
    -0.35f, LINE_TO, 1.17f, 3.5f, R_LINE_TO, 1.17f, -1.17f, R_LINE_TO, 15.33f, 15.33f, R_LINE_TO, -1.17f, 1.17f, CLOSE, MOVE_TO, 5.42f, 15, R_H_LINE_TO, 7.21f,
    LINE_TO, 5.92f, 8.29f, R_ARC_TO, 5.52f, 5.52f, 0, 0, 0, -0.06f, 0.44f, ARC_TO, 4.4f, 4.4f, 0, 0, 0, 5.83f, 9.17f, R_H_LINE_TO, -0.42f, R_CUBIC_TO, -0.81f,
    0, -1.49f, 0.28f, -2.06f, 0.85f, ARC_TO, 2.81f, 2.81f, 0, 0, 0, 2.5f, 12.08f, R_CUBIC_TO, 0, 0.81f, 0.28f, 1.49f, 0.85f, 2.06f, ARC_TO, 2.81f, 2.81f, 0, 0,
    0, 5.42f, 15, CLOSE, R_MOVE_TO, 12.58f, 0.63f, R_LINE_TO, -1.21f, -1.17f, R_CUBIC_TO, 0.24f, -0.19f, 0.41f, -0.42f, 0.52f, -0.67f, R_CUBIC_TO, 0.13f,
    -0.26f, 0.19f, -0.56f, 0.19f, -0.87f, R_CUBIC_TO, 0, -0.58f, -0.2f, -1.08f, -0.6f, -1.48f, CUBIC_TO, 16.49f, 11.04f, 16, 10.83f, 15.42f, 10.83f, H_LINE_TO,
    14.17f, R_V_LINE_TO, -1.67f, R_CUBIC_TO, 0, -1.15f, -0.41f, -2.13f, -1.23f, -2.94f, CUBIC_TO, 12.13f, 5.41f, 11.15f, 5, 10, 5, R_CUBIC_TO, -0.37f, 0,
    -0.74f, 0.05f, -1.08f, 0.15f, R_ARC_TO, 3.48f, 3.48f, 0, 0, 0, -1, 0.42f, R_LINE_TO, -1.21f, -1.21f, R_CUBIC_TO, 0.49f, -0.33f, 1, -0.58f, 1.54f, -0.75f,
    ARC_TO, 5.63f, 5.63f, 0, 0, 1, 10, 3.33f, R_CUBIC_TO, 1.63f, 0, 3, 0.57f, 4.13f, 1.71f, CUBIC_TO, 15.26f, 6.17f, 15.83f, 7.54f, 15.83f, 9.17f, R_CUBIC_TO,
    0.96f, 0.11f, 1.75f, 0.53f, 2.38f, 1.25f, R_CUBIC_TO, 0.64f, 0.71f, 0.96f, 1.54f, 0.96f, 2.5f, R_ARC_TO, 3.73f, 3.73f, 0, 0, 1, -0.31f, 1.52f, ARC_TO,
    3.66f, 3.66f, 0, 0, 1, 18, 15.63f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kNotUploadedRepList, kNotUploadedIcon, { kNotUploadedPath, std::size(kNotUploadedPath) })
VECTOR_ICON_REP_TEMPLATE(kNotificationWarningPath, CANVAS_DIMENSIONS, 96, MOVE_TO, 48, 8, R_CUBIC_TO, 22.08f, 0, 40, 17.92f, 40, 40, CUBIC_TO_SHORTHAND, 70.08f,
    88, 48, 88, CUBIC_TO_SHORTHAND, 8, 70.08f, 8, 48, CUBIC_TO_SHORTHAND, 25.92f, 8, 48, 8, CLOSE, R_MOVE_TO, -4, 20, R_V_LINE_TO, 24, R_H_LINE_TO, 8,
    V_LINE_TO, 28, R_H_LINE_TO, -8, CLOSE, R_MOVE_TO, 0, 32, R_V_LINE_TO, 8, R_H_LINE_TO, 8, R_V_LINE_TO, -8, R_H_LINE_TO, -8, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kNotificationWarningRepList, kNotificationWarningIcon, { kNotificationWarningPath, std::size(kNotificationWarningPath) })
VECTOR_ICON_REP_TEMPLATE(kNotificationsPath, MOVE_TO, 24, 44, R_CUBIC_TO, 2.21f, 0, 4, -1.49f, 4, -4, R_H_LINE_TO, -8, R_CUBIC_TO, 0, 2.21f, 1.79f, 4, 4, 4,
    CLOSE, R_MOVE_TO, 12, -12, V_LINE_TO, 22, R_CUBIC_TO, 0, -6.15f, -3.27f, -11.28f, -9, -12.64f, V_LINE_TO, 8, R_CUBIC_TO, 0, -1.66f, -1.34f, -3, -3, -3,
    R_CUBIC_TO, -1.66f, 0, -3, 1.34f, -3, 3, R_V_LINE_TO, 1.36f, R_CUBIC_TO, -5.73f, 1.36f, -9, 6.49f, -9, 12.64f, R_V_LINE_TO, 10, R_LINE_TO, -4, 4,
    R_V_LINE_TO, 2, R_H_LINE_TO, 32, R_V_LINE_TO, -2, R_LINE_TO, -4, -4)
VECTOR_ICON_TEMPLATE_CC(kNotificationsRepList, kNotificationsIcon, { kNotificationsPath, std::size(kNotificationsPath) })
VECTOR_ICON_REP_TEMPLATE(kNotificationsChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 4, 15.5f, V_LINE_TO, 14, R_H_LINE_TO, 1, V_LINE_TO,
    9, R_CUBIC_TO, 0, -1.21f, 0.37f, -2.27f, 1.11f, -3.19f, CUBIC_TO, 6.86f, 4.9f, 7.82f, 4.33f, 9, 4.11f, V_LINE_TO, 3, R_CUBIC_TO, 0, -0.28f, 0.1f, -0.52f,
    0.29f, -0.71f, ARC_TO, 0.96f, 0.96f, 0, 0, 1, 10, 2, R_CUBIC_TO, 0.28f, 0, 0.52f, 0.1f, 0.71f, 0.29f, R_CUBIC_TO, 0.2f, 0.19f, 0.29f, 0.43f, 0.29f, 0.71f,
    R_V_LINE_TO, 1.11f, R_CUBIC_TO, 1.18f, 0.22f, 2.14f, 0.79f, 2.89f, 1.71f, CUBIC_TO, 14.63f, 6.73f, 15, 7.79f, 15, 9, R_V_LINE_TO, 5, R_H_LINE_TO, 1,
    R_V_LINE_TO, 1.5f, CLOSE, R_MOVE_TO, 6, -5.75f, CLOSE, MOVE_TO, 10, 18, R_CUBIC_TO, -0.41f, 0, -0.77f, -0.15f, -1.06f, -0.44f, ARC_TO, 1.44f, 1.44f, 0, 0,
    1, 8.5f, 16.5f, R_H_LINE_TO, 3, R_CUBIC_TO, 0, 0.42f, -0.15f, 0.77f, -0.44f, 1.06f, ARC_TO, 1.45f, 1.45f, 0, 0, 1, 10, 18, CLOSE, MOVE_TO, 6.5f, 14,
    R_H_LINE_TO, 7, V_LINE_TO, 9, R_CUBIC_TO, 0, -0.97f, -0.34f, -1.8f, -1.02f, -2.48f, R_CUBIC_TO, -0.68f, -0.68f, -1.51f, -1.02f, -2.48f, -1.02f, R_CUBIC_TO,
    -0.97f, 0, -1.8f, 0.34f, -2.48f, 1.02f, CUBIC_TO, 6.84f, 7.2f, 6.5f, 8.03f, 6.5f, 9, CLOSE)
VECTOR_ICON_TEMPLATE_CC(
    kNotificationsChromeRefreshRepList, kNotificationsChromeRefreshIcon, { kNotificationsChromeRefreshPath, std::size(kNotificationsChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kNotificationsOffChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 4, 15.5f, V_LINE_TO, 14, R_H_LINE_TO, 1,
    V_LINE_TO, 9, R_CUBIC_TO, 0, -0.57f, 0.09f, -1.11f, 0.28f, -1.64f, R_CUBIC_TO, 0.19f, -0.52f, 0.44f, -1.01f, 0.76f, -1.47f, LINE_TO, 7.15f, 7, R_ARC_TO,
    3.46f, 3.46f, 0, 0, 0, -0.48f, 0.95f, ARC_TO, 3.32f, 3.32f, 0, 0, 0, 6.5f, 9, R_V_LINE_TO, 5, H_LINE_TO, 12, LINE_TO, 1.88f, 3.88f, R_LINE_TO, 1.06f,
    -1.08f, R_LINE_TO, 14.12f, 14.15f, LINE_TO, 16, 18, R_LINE_TO, -2.5f, -2.5f, CLOSE, R_MOVE_TO, 11, -2.75f, R_LINE_TO, -1.5f, -1.5f, V_LINE_TO, 9,
    R_CUBIC_TO, 0, -0.97f, -0.34f, -1.8f, -1.02f, -2.48f, R_CUBIC_TO, -0.68f, -0.68f, -1.51f, -1.02f, -2.48f, -1.02f, R_CUBIC_TO, -0.32f, 0, -0.62f, 0.04f,
    -0.91f, 0.13f, R_ARC_TO, 4.05f, 4.05f, 0, 0, 0, -0.86f, 0.36f, LINE_TO, 7.15f, 4.89f, R_CUBIC_TO, 0.28f, -0.2f, 0.57f, -0.37f, 0.89f, -0.49f, ARC_TO, 5.53f,
    5.53f, 0, 0, 1, 9, 4.11f, V_LINE_TO, 3, R_CUBIC_TO, 0, -0.28f, 0.1f, -0.52f, 0.29f, -0.71f, ARC_TO, 0.96f, 0.96f, 0, 0, 1, 10, 2, R_CUBIC_TO, 0.28f, 0,
    0.52f, 0.1f, 0.71f, 0.29f, R_CUBIC_TO, 0.2f, 0.19f, 0.29f, 0.43f, 0.29f, 0.71f, R_V_LINE_TO, 1.11f, R_CUBIC_TO, 1.18f, 0.22f, 2.14f, 0.79f, 2.89f, 1.71f,
    CUBIC_TO, 14.63f, 6.73f, 15, 7.79f, 15, 9, CLOSE, R_MOVE_TO, -5.75f, -1.5f, CLOSE, MOVE_TO, 10, 18, R_CUBIC_TO, -0.41f, 0, -0.77f, -0.15f, -1.06f, -0.44f,
    ARC_TO, 1.44f, 1.44f, 0, 0, 1, 8.5f, 16.5f, R_H_LINE_TO, 3, R_CUBIC_TO, 0, 0.42f, -0.15f, 0.77f, -0.44f, 1.06f, ARC_TO, 1.45f, 1.45f, 0, 0, 1, 10, 18,
    CLOSE, R_MOVE_TO, 0.88f, -9.39f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kNotificationsOffChromeRefreshRepList, kNotificationsOffChromeRefreshIcon,
    { kNotificationsOffChromeRefreshPath, std::size(kNotificationsOffChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kPageInfoContentPastePath, CANVAS_DIMENSIONS, 18, MOVE_TO, 6.71f, 3.25f, R_ARC_TO, 2.5f, 2.5f, 0, 0, 1, 4.58f, 0, H_LINE_TO, 14,
    R_ARC_TO, 1, 1, 0, 0, 1, 1, 1, R_V_LINE_TO, 11, R_ARC_TO, 1, 1, 0, 0, 1, -1, 1, H_LINE_TO, 4, R_ARC_TO, 1, 1, 0, 0, 1, -1, -1, R_V_LINE_TO, -11, R_ARC_TO,
    1, 1, 0, 0, 1, 1, -1, CLOSE, MOVE_TO, 9, 5.25f, R_ARC_TO, 1, 1, 0, 1, 0, 0, -2, R_ARC_TO, 1, 1, 0, 0, 0, 0, 2, CLOSE, R_MOVE_TO, -5, -0.5f, R_V_LINE_TO, 10,
    R_H_LINE_TO, 10, R_V_LINE_TO, -10, R_H_LINE_TO, -2, R_V_LINE_TO, 1.5f, R_ARC_TO, 1, 1, 0, 0, 1, -1, 1, H_LINE_TO, 7, R_ARC_TO, 1, 1, 0, 0, 1, -1, -1,
    R_V_LINE_TO, -1.5f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kPageInfoContentPasteRepList, kPageInfoContentPasteIcon, { kPageInfoContentPastePath, std::size(kPageInfoContentPastePath) })
VECTOR_ICON_REP_TEMPLATE(kPasskeyPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 11, 12, R_QUADRATIC_TO, -1.65f, 0, -2.81f, -1.17f, QUADRATIC_TO, 7.03f, 9.65f, 7.03f, 8,
    R_QUADRATIC_TO, 0, -1.65f, 1.16f, -2.82f, QUADRATIC_TO, 9.35f, 4, 11, 4, R_QUADRATIC_TO, 1.65f, 0, 2.83f, 1.18f, QUADRATIC_TO, 15, 6.35f, 15, 8,
    R_QUADRATIC_TO, 0, 1.65f, -1.17f, 2.83f, QUADRATIC_TO, 12.65f, 12, 11, 12, CLOSE, R_MOVE_TO, 7.25f, 9, LINE_TO, 17, 19.5f, R_V_LINE_TO, -3.67f,
    R_QUADRATIC_TO, -0.87f, -0.32f, -1.44f, -1.09f, QUADRATIC_TO, 15, 13.98f, 15, 13, R_QUADRATIC_TO, 0, -1.25f, 0.88f, -2.12f, QUADRATIC_TO_SHORTHAND, 18, 10,
    R_QUADRATIC_TO, 1.25f, 0, 2.13f, 0.88f, QUADRATIC_TO_SHORTHAND, 21, 13, R_QUADRATIC_TO, 0, 0.98f, -0.56f, 1.74f, R_QUADRATIC_TO, -0.56f, 0.76f, -1.44f,
    1.09f, V_LINE_TO, 16, R_LINE_TO, 1, 1, R_LINE_TO, -1, 1, R_LINE_TO, 1, 1, CLOSE, MOVE_TO, 3, 20, R_V_LINE_TO, -2.77f, R_QUADRATIC_TO, 0, -0.85f, 0.43f,
    -1.57f, R_QUADRATIC_TO, 0.43f, -0.72f, 1.18f, -1.1f, R_QUADRATIC_TO, 1.27f, -0.65f, 2.89f, -1.1f, QUADRATIC_TO, 9.1f, 13, 11, 13, R_QUADRATIC_TO, 0.53f, 0,
    1.02f, 0.04f, R_QUADRATIC_TO, 0.5f, 0.04f, 1, 0.11f, R_QUADRATIC_TO, 0.05f, 1.13f, 0.54f, 2.15f, R_QUADRATIC_TO, 0.49f, 1.02f, 1.44f, 1.68f, V_LINE_TO, 20,
    CLOSE, R_MOVE_TO, 15, -5.5f, R_QUADRATIC_TO, 0.63f, 0, 1.06f, -0.44f, R_QUADRATIC_TO, 0.44f, -0.44f, 0.44f, -1.06f, R_QUADRATIC_TO, 0, -0.62f, -0.44f,
    -1.06f, QUADRATIC_TO, 18.63f, 11.5f, 18, 11.5f, R_QUADRATIC_TO, -0.63f, 0, -1.06f, 0.44f, QUADRATIC_TO, 16.5f, 12.38f, 16.5f, 13, R_QUADRATIC_TO, 0, 0.62f,
    0.44f, 1.06f, R_QUADRATIC_TO, 0.44f, 0.44f, 1.06f, 0.44f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kPasskeyRepList, kPasskeyIcon, { kPasskeyPath, std::size(kPasskeyPath) })
VECTOR_ICON_REP_TEMPLATE(kPasswordManagerPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 6, 12, R_CUBIC_TO, 0.55f, 0, 1.02f, -0.19f, 1.41f, -0.59f,
    CUBIC_TO, 7.8f, 11.02f, 8, 10.55f, 8, 10, R_CUBIC_TO, 0, -0.55f, -0.19f, -1.02f, -0.59f, -1.41f, ARC_TO, 1.94f, 1.94f, 0, 0, 0, 6, 8, R_CUBIC_TO, -0.55f, 0,
    -1.02f, 0.2f, -1.41f, 0.59f, CUBIC_TO, 4.2f, 8.98f, 4, 9.45f, 4, 10, R_CUBIC_TO, 0, 0.55f, 0.2f, 1.02f, 0.59f, 1.41f, R_CUBIC_TO, 0.39f, 0.39f, 0.86f,
    0.59f, 1.41f, 0.59f, CLOSE, R_MOVE_TO, 0, 3, R_CUBIC_TO, -1.39f, 0, -2.57f, -0.48f, -3.54f, -1.46f, CUBIC_TO, 1.48f, 12.57f, 1, 11.39f, 1, 10, R_CUBIC_TO,
    0, -1.39f, 0.48f, -2.57f, 1.46f, -3.54f, CUBIC_TO, 3.43f, 5.48f, 4.61f, 5, 6, 5, R_CUBIC_TO, 1, 0, 1.91f, 0.27f, 2.73f, 0.81f, ARC_TO, 5.09f, 5.09f, 0, 0,
    1, 10.58f, 8, H_LINE_TO, 17.5f, R_CUBIC_TO, 0.41f, 0, 0.77f, 0.15f, 1.06f, 0.44f, R_CUBIC_TO, 0.29f, 0.29f, 0.44f, 0.65f, 0.44f, 1.06f, R_V_LINE_TO, 4,
    R_CUBIC_TO, 0, 0.41f, -0.15f, 0.77f, -0.44f, 1.06f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 17.5f, 15, R_H_LINE_TO, -3, R_CUBIC_TO, -0.41f, 0, -0.77f, -0.15f,
    -1.06f, -0.44f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 13, 13.5f, V_LINE_TO, 12, R_H_LINE_TO, -2.42f, R_ARC_TO, 5.09f, 5.09f, 0, 0, 1, -1.85f, 2.19f, ARC_TO, 4.84f,
    4.84f, 0, 0, 1, 6, 15, CLOSE, R_MOVE_TO, 3.46f, -4.5f, H_LINE_TO, 14.5f, R_V_LINE_TO, 3, R_H_LINE_TO, 1, V_LINE_TO, 12, R_CUBIC_TO, 0, -0.14f, 0.05f,
    -0.27f, 0.14f, -0.36f, R_ARC_TO, 0.49f, 0.49f, 0, 0, 1, 0.36f, -0.14f, R_CUBIC_TO, 0.14f, 0, 0.27f, 0.05f, 0.36f, 0.14f, R_CUBIC_TO, 0.09f, 0.09f, 0.14f,
    0.22f, 0.14f, 0.36f, R_V_LINE_TO, 1.5f, R_H_LINE_TO, 1, R_V_LINE_TO, -4, H_LINE_TO, 9.46f, R_ARC_TO, 3.27f, 3.27f, 0, 0, 0, -1.16f, -2.16f, ARC_TO, 3.45f,
    3.45f, 0, 0, 0, 6, 6.5f, R_CUBIC_TO, -0.97f, 0, -1.8f, 0.34f, -2.48f, 1.02f, CUBIC_TO, 2.84f, 8.2f, 2.5f, 9.03f, 2.5f, 10, R_CUBIC_TO, 0, 0.97f, 0.34f,
    1.8f, 1.02f, 2.48f, R_CUBIC_TO, 0.68f, 0.68f, 1.51f, 1.02f, 2.48f, 1.02f, R_CUBIC_TO, 0.87f, 0, 1.64f, -0.28f, 2.3f, -0.84f, ARC_TO, 3.27f, 3.27f, 0, 0, 0,
    9.46f, 10.5f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kPasswordManagerRepList, kPasswordManagerIcon, { kPasswordManagerPath, std::size(kPasswordManagerPath) })
VECTOR_ICON_REP_TEMPLATE(kPausePath, MOVE_TO, 12, 38, R_H_LINE_TO, 8, V_LINE_TO, 10, R_H_LINE_TO, -8, R_V_LINE_TO, 28, CLOSE, R_MOVE_TO, 16, -28, R_V_LINE_TO,
    28, R_H_LINE_TO, 8, V_LINE_TO, 10, R_H_LINE_TO, -8, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kPauseRepList, kPauseIcon, { kPausePath, std::size(kPausePath) })
VECTOR_ICON_REP_TEMPLATE(kPauseChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 11, 16, V_LINE_TO, 4, R_H_LINE_TO, 5, R_V_LINE_TO, 12,
    CLOSE, R_MOVE_TO, -7, 0, V_LINE_TO, 4, R_H_LINE_TO, 5, R_V_LINE_TO, 12, CLOSE, R_MOVE_TO, 8.5f, -1.5f, R_H_LINE_TO, 2, R_V_LINE_TO, -9, R_H_LINE_TO, -2,
    CLOSE, R_MOVE_TO, -7, 0, R_H_LINE_TO, 2, R_V_LINE_TO, -9, R_H_LINE_TO, -2, CLOSE, R_MOVE_TO, 0, -9, R_V_LINE_TO, 9, CLOSE, R_MOVE_TO, 7, 0, R_V_LINE_TO, 9,
    CLOSE)
VECTOR_ICON_TEMPLATE_CC(kPauseChromeRefreshRepList, kPauseChromeRefreshIcon, { kPauseChromeRefreshPath, std::size(kPauseChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kPhotoPath, CANVAS_DIMENSIONS, 18, MOVE_TO, 15, 13.67f, V_LINE_TO, 4.33f, CUBIC_TO, 15, 3.6f, 14.4f, 3, 13.67f, 3, H_LINE_TO, 4.33f,
    CUBIC_TO, 3.6f, 3, 3, 3.6f, 3, 4.33f, R_V_LINE_TO, 9.33f, CUBIC_TO, 3, 14.4f, 3.6f, 15, 4.33f, 15, R_H_LINE_TO, 9.33f, CUBIC_TO, 14.4f, 15, 15, 14.4f, 15,
    13.67f, CLOSE, MOVE_TO, 6.67f, 10, R_LINE_TO, 1.67f, 2.01f, LINE_TO, 10.67f, 9, R_LINE_TO, 3, 4, H_LINE_TO, 4.33f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kPhotoRepList, kPhotoIcon, { kPhotoPath, std::size(kPhotoPath) })
VECTOR_ICON_REP_TEMPLATE(kPhotoChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 4.5f, 17, R_ARC_TO, 1.42f, 1.42f, 0, 0, 1, -1.06f, -0.45f,
    ARC_TO, 1.45f, 1.45f, 0, 0, 1, 3, 15.5f, R_V_LINE_TO, -11, R_CUBIC_TO, 0, -0.4f, 0.15f, -0.75f, 0.44f, -1.05f, CUBIC_TO, 3.73f, 3.15f, 4.09f, 3, 4.5f, 3,
    R_H_LINE_TO, 11, R_CUBIC_TO, 0.41f, 0, 0.77f, 0.15f, 1.06f, 0.45f, R_CUBIC_TO, 0.29f, 0.3f, 0.44f, 0.65f, 0.44f, 1.05f, R_V_LINE_TO, 11, R_CUBIC_TO, 0,
    0.4f, -0.15f, 0.75f, -0.44f, 1.05f, R_CUBIC_TO, -0.29f, 0.3f, -0.64f, 0.45f, -1.06f, 0.45f, CLOSE, R_MOVE_TO, 0, -1.5f, R_H_LINE_TO, 11, R_V_LINE_TO, -11,
    R_H_LINE_TO, -11, CLOSE, R_MOVE_TO, 1, -1.5f, R_H_LINE_TO, 9, R_LINE_TO, -3, -4, R_LINE_TO, -2.25f, 3, R_LINE_TO, -1.5f, -2, CLOSE, R_MOVE_TO, -1, 1.5f,
    R_V_LINE_TO, -11, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kPhotoChromeRefreshRepList, kPhotoChromeRefreshIcon, { kPhotoChromeRefreshPath, std::size(kPhotoChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kPhotoOffChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, R_MOVE_TO, 17, 14.88f, R_LINE_TO, -1.5f, -1.5f, V_LINE_TO, 4.5f,
    H_LINE_TO, 6.63f, LINE_TO, 5.13f, 3, H_LINE_TO, 15.5f, R_CUBIC_TO, 0.4f, 0, 0.75f, 0.15f, 1.05f, 0.45f, R_CUBIC_TO, 0.3f, 0.3f, 0.45f, 0.65f, 0.45f, 1.05f,
    CLOSE, R_MOVE_TO, -1, 3.25f, LINE_TO, 14.88f, 17, H_LINE_TO, 4.5f, R_CUBIC_TO, -0.4f, 0, -0.75f, -0.15f, -1.05f, -0.45f, R_CUBIC_TO, -0.3f, -0.3f, -0.45f,
    -0.65f, -0.45f, -1.05f, V_LINE_TO, 5.13f, LINE_TO, 1.88f, 4, R_LINE_TO, 1.06f, -1.06f, R_LINE_TO, 14.12f, 14.13f, CLOSE, MOVE_TO, 5.5f, 14, R_LINE_TO,
    2.25f, -3, R_LINE_TO, 1.5f, 2, R_LINE_TO, 0.71f, -0.94f, LINE_TO, 4.5f, 6.63f, V_LINE_TO, 15.5f, R_H_LINE_TO, 8.88f, R_LINE_TO, -1.5f, -1.5f, CLOSE,
    MOVE_TO, 11, 9, CLOSE, R_MOVE_TO, -2.12f, 2.13f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kPhotoOffChromeRefreshRepList, kPhotoOffChromeRefreshIcon, { kPhotoOffChromeRefreshPath, std::size(kPhotoOffChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kPictureInPicturePath, CANVAS_DIMENSIONS, 24, MOVE_TO, 4, 20, R_CUBIC_TO, -0.55f, 0, -1.02f, -0.19f, -1.41f, -0.59f, ARC_TO, 1.94f,
    1.94f, 0, 0, 1, 2, 18, V_LINE_TO, 6, R_CUBIC_TO, 0, -0.55f, 0.2f, -1.02f, 0.59f, -1.41f, CUBIC_TO, 2.98f, 4.2f, 3.45f, 4, 4, 4, R_H_LINE_TO, 16, R_CUBIC_TO,
    0.55f, 0, 1.02f, 0.2f, 1.41f, 0.59f, R_CUBIC_TO, 0.39f, 0.39f, 0.59f, 0.86f, 0.59f, 1.41f, R_V_LINE_TO, 12, R_CUBIC_TO, 0, 0.55f, -0.19f, 1.02f, -0.59f,
    1.41f, R_CUBIC_TO, -0.39f, 0.39f, -0.86f, 0.59f, -1.41f, 0.59f, CLOSE, R_MOVE_TO, 0, -2, R_H_LINE_TO, 16, V_LINE_TO, 6, H_LINE_TO, 4, CLOSE, R_MOVE_TO, 0,
    0, V_LINE_TO, 6, CLOSE, R_MOVE_TO, 7, -5, R_H_LINE_TO, 8, V_LINE_TO, 7, R_H_LINE_TO, -8, CLOSE, R_MOVE_TO, 2, -2, V_LINE_TO, 9, R_H_LINE_TO, 4, R_V_LINE_TO,
    2, CLOSE, R_MOVE_TO, 0, 0, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kPictureInPictureRepList, kPictureInPictureIcon, { kPictureInPicturePath, std::size(kPictureInPicturePath) })
VECTOR_ICON_REP_TEMPLATE(kPictureInPictureAltPath, CANVAS_DIMENSIONS, 960, MOVE_TO, 160, 800, R_QUADRATIC_TO, -33, 0, -56.5f, -23.5f, QUADRATIC_TO_SHORTHAND,
    80, 720, R_V_LINE_TO, -480, R_QUADRATIC_TO, 0, -33, 23.5f, -56.5f, QUADRATIC_TO_SHORTHAND, 160, 160, R_H_LINE_TO, 640, R_QUADRATIC_TO, 33, 0, 56.5f, 23.5f,
    QUADRATIC_TO_SHORTHAND, 880, 240, R_V_LINE_TO, 480, R_QUADRATIC_TO, 0, 33, -23.5f, 56.5f, QUADRATIC_TO_SHORTHAND, 800, 800, H_LINE_TO, 160, CLOSE,
    R_MOVE_TO, 0, -80, R_H_LINE_TO, 640, R_V_LINE_TO, -480, H_LINE_TO, 160, R_V_LINE_TO, 480, CLOSE, R_MOVE_TO, 0, 0, R_V_LINE_TO, -480, R_V_LINE_TO, 480,
    CLOSE, R_MOVE_TO, 280, -40, R_H_LINE_TO, 320, R_V_LINE_TO, -240, H_LINE_TO, 440, R_V_LINE_TO, 240, CLOSE, R_MOVE_TO, 80, -80, R_V_LINE_TO, -80, R_H_LINE_TO,
    160, R_V_LINE_TO, 80, H_LINE_TO, 520, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kPictureInPictureAltRepList, kPictureInPictureAltIcon, { kPictureInPictureAltPath, std::size(kPictureInPictureAltPath) })
VECTOR_ICON_REP_TEMPLATE(kPipExitPath, CANVAS_DIMENSIONS, 960, FILL_RULE_NONZERO, MOVE_TO, 160, 800, R_QUADRATIC_TO, -33, 0, -56.5f, -23.5f,
    QUADRATIC_TO_SHORTHAND, 80, 720, R_V_LINE_TO, -280, R_H_LINE_TO, 80, R_V_LINE_TO, 280, R_H_LINE_TO, 640, R_V_LINE_TO, -480, H_LINE_TO, 440, R_V_LINE_TO,
    -80, R_H_LINE_TO, 360, R_QUADRATIC_TO, 33, 0, 56.5f, 23.5f, QUADRATIC_TO_SHORTHAND, 880, 240, R_V_LINE_TO, 480, R_QUADRATIC_TO, 0, 33, -23.5f, 56.5f,
    QUADRATIC_TO_SHORTHAND, 800, 800, H_LINE_TO, 160, CLOSE, R_MOVE_TO, 523, -140, R_LINE_TO, 57, -57, R_LINE_TO, -124, -123, R_H_LINE_TO, 104, R_V_LINE_TO,
    -80, H_LINE_TO, 480, R_V_LINE_TO, 240, R_H_LINE_TO, 80, R_V_LINE_TO, -103, R_LINE_TO, 123, 123, CLOSE, MOVE_TO, 80, 360, R_V_LINE_TO, -200, R_H_LINE_TO,
    280, R_V_LINE_TO, 200, H_LINE_TO, 80, CLOSE, R_MOVE_TO, 400, 120, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kPipExitRepList, kPipExitIcon, { kPipExitPath, std::size(kPipExitPath) })
VECTOR_ICON_REP_TEMPLATE(kPlayArrowPath, FLIPS_IN_RTL, MOVE_TO, 16, 10, R_V_LINE_TO, 28, R_LINE_TO, 22, -14, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kPlayArrowRepList, kPlayArrowIcon, { kPlayArrowPath, std::size(kPlayArrowPath) })
VECTOR_ICON_REP_TEMPLATE(kPlayArrowChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 7, 15.5f, R_V_LINE_TO, -11, R_LINE_TO, 8.5f, 5.5f,
    CLOSE, R_MOVE_TO, 1.52f, -5.52f, CLOSE, R_MOVE_TO, -0.02f, 2.77f, LINE_TO, 12.75f, 10, LINE_TO, 8.5f, 7.25f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kPlayArrowChromeRefreshRepList, kPlayArrowChromeRefreshIcon, { kPlayArrowChromeRefreshPath, std::size(kPlayArrowChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kPointerLockPath, CANVAS_DIMENSIONS, 960, FILL_RULE_NONZERO, MOVE_TO, 480, 440, CLOSE, R_MOVE_TO, 0, 440, R_QUADRATIC_TO, -116, 0,
    -198, -82, R_QUADRATIC_TO, -82, -82, -82, -198, R_V_LINE_TO, -240, R_QUADRATIC_TO, 0, -116, 82, -198, R_QUADRATIC_TO, 82, -82, 198, -82, R_QUADRATIC_TO,
    116, 0, 198, 82, R_QUADRATIC_TO, 82, 82, 82, 198, R_V_LINE_TO, 124, R_QUADRATIC_TO, -20, -4, -40, -4, R_QUADRATIC_TO, -20, 0, -40, 4, R_V_LINE_TO, -44,
    H_LINE_TO, 280, R_V_LINE_TO, 160, R_QUADRATIC_TO, 0, 83, 58.5f, 141.5f, QUADRATIC_TO_SHORTHAND, 480, 800, R_QUADRATIC_TO, 11, 0, 20.5f, -1, R_QUADRATIC_TO,
    9.5f, -1, 19.5f, -3, R_V_LINE_TO, 81, R_QUADRATIC_TO, -10, 2, -19.5f, 2.5f, QUADRATIC_TO_SHORTHAND, 480, 880, CLOSE, MOVE_TO, 280, 360, R_H_LINE_TO, 160,
    R_V_LINE_TO, -196, R_QUADRATIC_TO, -69, 14, -114.5f, 69, QUADRATIC_TO_SHORTHAND, 280, 360, CLOSE, R_MOVE_TO, 240, 0, R_H_LINE_TO, 160, R_QUADRATIC_TO, 0,
    -72, -45.5f, -127, QUADRATIC_TO_SHORTHAND, 520, 164, R_V_LINE_TO, 196, CLOSE, MOVE_TO, 634, 880, R_QUADRATIC_TO, -14, 0, -24, -10, R_QUADRATIC_TO, -10, -10,
    -10, -24, R_V_LINE_TO, -132, R_QUADRATIC_TO, 0, -14, 10, -24, R_QUADRATIC_TO, 10, -10, 24, -10, R_H_LINE_TO, 6, R_V_LINE_TO, -40, R_QUADRATIC_TO, 0, -33,
    23.5f, -56.5f, QUADRATIC_TO_SHORTHAND, 720, 560, R_QUADRATIC_TO, 33, 0, 56.5f, 23.5f, QUADRATIC_TO_SHORTHAND, 800, 640, R_V_LINE_TO, 40, R_H_LINE_TO, 6,
    R_QUADRATIC_TO, 14, 0, 24, 10, R_QUADRATIC_TO, 10, 10, 10, 24, R_V_LINE_TO, 132, R_QUADRATIC_TO, 0, 14, -10, 24, R_QUADRATIC_TO, -10, 10, -24, 10,
    H_LINE_TO, 634, CLOSE, R_MOVE_TO, 46, -200, R_H_LINE_TO, 80, R_V_LINE_TO, -40, R_QUADRATIC_TO, 0, -17, -11.5f, -28.5f, QUADRATIC_TO_SHORTHAND, 720, 600,
    R_QUADRATIC_TO, -17, 0, -28.5f, 11.5f, QUADRATIC_TO_SHORTHAND, 680, 640, R_V_LINE_TO, 40, CLOSE, MOVE_TO, 480, 440, CLOSE, R_MOVE_TO, 40, -80, CLOSE,
    R_MOVE_TO, -80, 0, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kPointerLockRepList, kPointerLockIcon, { kPointerLockPath, std::size(kPointerLockPath) })
VECTOR_ICON_REP_TEMPLATE(kPointerLockOffPath, CANVAS_DIMENSIONS, 960, FILL_RULE_NONZERO, MOVE_TO, 440, 328, CLOSE, R_MOVE_TO, 111, 112, CLOSE, R_MOVE_TO, -131,
    93, CLOSE, R_MOVE_TO, 20, -93, CLOSE, R_MOVE_TO, 0, 0, CLOSE, R_MOVE_TO, 80, -80, CLOSE, R_MOVE_TO, -40, -280, R_QUADRATIC_TO, 116, 0, 198, 82,
    R_QUADRATIC_TO, 82, 82, 82, 198, R_V_LINE_TO, 124, R_QUADRATIC_TO, -20, -4, -40, -4, R_QUADRATIC_TO, -20, 0, -40, 4, R_V_LINE_TO, -44, H_LINE_TO, 551,
    LINE_TO, 440, 328, R_V_LINE_TO, -164, R_QUADRATIC_TO, -31, 6, -57.5f, 21, QUADRATIC_TO_SHORTHAND, 335, 222, R_LINE_TO, -56, -57, R_QUADRATIC_TO, 38, -39,
    90, -62, R_QUADRATIC_TO, 52, -23, 111, -23, CLOSE, MOVE_TO, 231, 232, R_LINE_TO, 209, 208, H_LINE_TO, 280, R_V_LINE_TO, 160, R_QUADRATIC_TO, 0, 83, 58.5f,
    141.5f, QUADRATIC_TO_SHORTHAND, 480, 800, R_QUADRATIC_TO, 11, 0, 20.5f, -1, R_QUADRATIC_TO, 9.5f, -1, 19.5f, -3, R_V_LINE_TO, 81, R_QUADRATIC_TO, -10, 2,
    -19.5f, 2.5f, QUADRATIC_TO_SHORTHAND, 480, 880, R_QUADRATIC_TO, -116, 0, -198, -82, R_QUADRATIC_TO, -82, -82, -82, -198, R_V_LINE_TO, -240, R_QUADRATIC_TO,
    0, -35, 8, -67, R_QUADRATIC_TO, 8, -32, 23, -61, CLOSE, R_MOVE_TO, 289, 128, R_H_LINE_TO, 160, R_QUADRATIC_TO, 0, -72, -45.5f, -127, QUADRATIC_TO_SHORTHAND,
    520, 164, R_V_LINE_TO, 196, CLOSE, MOVE_TO, 819, 932, LINE_TO, 28, 140, R_LINE_TO, 56, -56, LINE_TO, 876, 876, R_LINE_TO, -57, 56, CLOSE, MOVE_TO, 634, 880,
    R_QUADRATIC_TO, -14, 0, -24, -10, R_QUADRATIC_TO, -10, -10, -10, -24, R_V_LINE_TO, -126, R_QUADRATIC_TO, 0, -17, 11.5f, -28.5f, QUADRATIC_TO_SHORTHAND, 640,
    680, R_H_LINE_TO, 40, R_LINE_TO, 160, 160, R_V_LINE_TO, 6, R_QUADRATIC_TO, 0, 14, -10, 24, R_QUADRATIC_TO, -10, 10, -24, 10, H_LINE_TO, 634, CLOSE,
    R_MOVE_TO, 166, -188, R_LINE_TO, -40, -40, R_V_LINE_TO, -12, R_QUADRATIC_TO, 0, -17, -11.5f, -28.5f, QUADRATIC_TO_SHORTHAND, 720, 600, R_H_LINE_TO, -5,
    R_QUADRATIC_TO, -3, 0, -5, 1, R_LINE_TO, -30, -30, R_QUADRATIC_TO, 9, -5, 19, -8, R_QUADRATIC_TO, 10, -3, 21, -3, R_QUADRATIC_TO, 33, 0, 56.5f, 23.5f,
    QUADRATIC_TO_SHORTHAND, 800, 640, R_V_LINE_TO, 52, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kPointerLockOffRepList, kPointerLockOffIcon, { kPointerLockOffPath, std::size(kPointerLockOffPath) })
VECTOR_ICON_REP_TEMPLATE(kPrinterPath, CANVAS_DIMENSIONS, 960, MOVE_TO, 640, 320, R_V_LINE_TO, -120, H_LINE_TO, 320, R_V_LINE_TO, 120, R_H_LINE_TO, -80,
    R_V_LINE_TO, -200, R_H_LINE_TO, 480, R_V_LINE_TO, 200, R_H_LINE_TO, -80, CLOSE, R_MOVE_TO, -480, 80, R_H_LINE_TO, 640, R_H_LINE_TO, -640, CLOSE, R_MOVE_TO,
    560, 100, R_QUADRATIC_TO, 17, 0, 28.5f, -11.5f, QUADRATIC_TO_SHORTHAND, 760, 460, R_QUADRATIC_TO, 0, -17, -11.5f, -28.5f, QUADRATIC_TO_SHORTHAND, 720, 420,
    R_QUADRATIC_TO, -17, 0, -28.5f, 11.5f, QUADRATIC_TO_SHORTHAND, 680, 460, R_QUADRATIC_TO, 0, 17, 11.5f, 28.5f, QUADRATIC_TO_SHORTHAND, 720, 500, CLOSE,
    R_MOVE_TO, -80, 260, R_V_LINE_TO, -160, H_LINE_TO, 320, R_V_LINE_TO, 160, R_H_LINE_TO, 320, CLOSE, R_MOVE_TO, 80, 80, H_LINE_TO, 240, R_V_LINE_TO, -160,
    H_LINE_TO, 80, R_V_LINE_TO, -240, R_QUADRATIC_TO, 0, -51, 35, -85.5f, R_QUADRATIC_TO, 35, -34.5f, 85, -34.5f, R_H_LINE_TO, 560, R_QUADRATIC_TO, 51, 0,
    85.5f, 34.5f, QUADRATIC_TO_SHORTHAND, 880, 440, R_V_LINE_TO, 240, H_LINE_TO, 720, R_V_LINE_TO, 160, CLOSE, R_MOVE_TO, 80, -240, R_V_LINE_TO, -160,
    R_QUADRATIC_TO, 0, -17, -11.5f, -28.5f, QUADRATIC_TO_SHORTHAND, 760, 400, H_LINE_TO, 200, R_QUADRATIC_TO, -17, 0, -28.5f, 11.5f, QUADRATIC_TO_SHORTHAND,
    160, 440, R_V_LINE_TO, 160, R_H_LINE_TO, 80, R_V_LINE_TO, -80, R_H_LINE_TO, 480, R_V_LINE_TO, 80, R_H_LINE_TO, 80, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kPrinterRepList, kPrinterIcon, { kPrinterPath, std::size(kPrinterPath) })
VECTOR_ICON_REP_TEMPLATE(kProtectedContentPath, CANVAS_DIMENSIONS, 18, MOVE_TO, 7.54f, 11.99f, R_LINE_TO, -0.81f, -0.81f, R_V_LINE_TO, 0, LINE_TO, 5.11f, 9.56f,
    R_LINE_TO, 0.71f, -0.71f, R_LINE_TO, 1.62f, 1.62f, R_LINE_TO, 4.24f, -4.24f, R_LINE_TO, 0.81f, 0.81f, R_LINE_TO, -4.95f, 4.95f, CLOSE, MOVE_TO, 15.86f, 3,
    H_LINE_TO, 2.14f, CUBIC_TO, 1.34f, 3, 1, 3.32f, 1, 4, R_V_LINE_TO, 10, R_CUBIC_TO, 0, 0.67f, 0.34f, 1, 1.14f, 1, H_LINE_TO, 5.57f, R_V_LINE_TO, 1,
    R_H_LINE_TO, 6.86f, R_V_LINE_TO, -1, R_H_LINE_TO, 3.43f, R_CUBIC_TO, 0.8f, 0, 1.14f, -0.33f, 1.14f, -1, V_LINE_TO, 4, R_CUBIC_TO, 0, -0.68f, -0.34f, -1,
    -1.14f, -1, CLOSE, MOVE_TO, 15, 13, H_LINE_TO, 3, V_LINE_TO, 5, R_H_LINE_TO, 12, R_V_LINE_TO, 8, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kProtectedContentRepList, kProtectedContentIcon, { kProtectedContentPath, std::size(kProtectedContentPath) })
VECTOR_ICON_REP_TEMPLATE(kProtocolHandlerPath, MOVE_TO, 43.44f, 22.66f, LINE_TO, 30.15f, 8.59f, CUBIC_TO, 29.42f, 7.82f, 28.14f, 7.81f, 27.39f, 8.57f, LINE_TO,
    24.05f, 12.01f, LINE_TO, 20.82f, 8.59f, CUBIC_TO, 20.08f, 7.81f, 18.79f, 7.81f, 18.06f, 8.57f, LINE_TO, 4.58f, 22.44f, CUBIC_TO, 4.21f, 22.82f, 4, 23.33f,
    4, 23.87f, CUBIC_TO, 4, 24.42f, 4.2f, 24.93f, 4.56f, 25.32f, LINE_TO, 17.85f, 39.39f, CUBIC_TO, 18.22f, 39.78f, 18.71f, 40, 19.24f, 40, CUBIC_TO, 19.75f,
    40, 20.24f, 39.79f, 20.61f, 39.41f, LINE_TO, 23.95f, 35.97f, LINE_TO, 27.18f, 39.39f, CUBIC_TO, 27.55f, 39.78f, 28.04f, 40, 28.57f, 40, CUBIC_TO, 29.09f,
    40, 29.58f, 39.79f, 29.94f, 39.41f, LINE_TO, 43.42f, 25.54f, CUBIC_TO, 44.18f, 24.76f, 44.19f, 23.46f, 43.44f, 22.66f, LINE_TO, 43.44f, 22.66f, LINE_TO,
    43.44f, 22.66f, CLOSE, MOVE_TO, 13.89f, 24.93f, LINE_TO, 21.21f, 32.5f, LINE_TO, 19.26f, 34.46f, LINE_TO, 8.71f, 23.54f, LINE_TO, 19.41f, 12.79f, LINE_TO,
    21.27f, 14.71f, LINE_TO, 13.92f, 22.11f, CUBIC_TO, 13.54f, 22.49f, 13.34f, 22.98f, 13.33f, 23.52f, CUBIC_TO, 13.33f, 24.05f, 13.53f, 24.55f, 13.89f, 24.93f,
    LINE_TO, 13.89f, 24.93f, LINE_TO, 13.89f, 24.93f, CLOSE, MOVE_TO, 28.59f, 34.46f, LINE_TO, 26.73f, 32.54f, LINE_TO, 34.09f, 25.14f, CUBIC_TO, 34.85f,
    24.37f, 34.86f, 23.1f, 34.11f, 22.32f, LINE_TO, 26.79f, 14.75f, LINE_TO, 28.74f, 12.79f, LINE_TO, 39.29f, 23.71f, LINE_TO, 28.59f, 34.46f, LINE_TO, 28.59f,
    34.46f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kProtocolHandlerRepList, kProtocolHandlerIcon, { kProtocolHandlerPath, std::size(kProtocolHandlerPath) })
VECTOR_ICON_REP_TEMPLATE(kProtocolHandlerChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 7.88f, 16.4f, R_ARC_TO, 0.97f, 0.97f, 0, 0, 1,
    -0.39f, -0.08f, R_ARC_TO, 1.18f, 1.18f, 0, 0, 1, -0.35f, -0.25f, LINE_TO, 2.25f, 10.67f, R_ARC_TO, 1.08f, 1.08f, 0, 0, 1, -0.19f, -0.32f, R_ARC_TO, 1, 1, 0,
    0, 1, 0.19f, -1.01f, R_LINE_TO, 4.88f, -5.39f, R_CUBIC_TO, 0.11f, -0.11f, 0.23f, -0.19f, 0.36f, -0.25f, R_ARC_TO, 0.97f, 0.97f, 0, 0, 1, 0.78f, 0,
    R_CUBIC_TO, 0.12f, 0.06f, 0.23f, 0.14f, 0.34f, 0.25f, LINE_TO, 10, 5.48f, R_LINE_TO, 1.4f, -1.54f, R_ARC_TO, 1.3f, 1.3f, 0, 0, 1, 0.34f, -0.25f, R_ARC_TO,
    0.97f, 0.97f, 0, 0, 1, 0.78f, 0, R_CUBIC_TO, 0.13f, 0.06f, 0.25f, 0.14f, 0.36f, 0.25f, R_LINE_TO, 4.88f, 5.4f, R_CUBIC_TO, 0.08f, 0.1f, 0.14f, 0.21f, 0.19f,
    0.32f, R_CUBIC_TO, 0.04f, 0.12f, 0.06f, 0.24f, 0.06f, 0.34f, R_ARC_TO, 1.08f, 1.08f, 0, 0, 1, -0.25f, 0.67f, R_LINE_TO, -4.87f, 5.4f, R_CUBIC_TO, -0.11f,
    0.11f, -0.23f, 0.2f, -0.35f, 0.25f, R_ARC_TO, 0.97f, 0.97f, 0, 0, 1, -0.78f, 0, R_ARC_TO, 1.3f, 1.3f, 0, 0, 1, -0.34f, -0.25f, LINE_TO, 10, 14.52f,
    R_LINE_TO, -1.39f, 1.54f, R_ARC_TO, 1.3f, 1.3f, 0, 0, 1, -0.34f, 0.25f, R_ARC_TO, 0.92f, 0.92f, 0, 0, 1, -0.39f, 0.08f, CLOSE, R_MOVE_TO, 0, -1.75f,
    LINE_TO, 9, 13.42f, R_LINE_TO, -2.5f, -2.75f, ARC_TO, 0.99f, 0.99f, 0, 0, 1, 6.25f, 10, R_CUBIC_TO, 0, -0.25f, 0.08f, -0.47f, 0.25f, -0.67f, LINE_TO, 9,
    6.58f, LINE_TO, 7.88f, 5.36f, LINE_TO, 3.67f, 10, CLOSE, R_MOVE_TO, 4.25f, 0, LINE_TO, 16.33f, 10, R_LINE_TO, -4.21f, -4.64f, LINE_TO, 11, 6.58f, R_LINE_TO,
    2.5f, 2.75f, R_CUBIC_TO, 0.17f, 0.2f, 0.25f, 0.42f, 0.25f, 0.67f, R_CUBIC_TO, 0, 0.25f, -0.08f, 0.47f, -0.25f, 0.67f, R_LINE_TO, -2.5f, 2.75f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kProtocolHandlerChromeRefreshRepList, kProtocolHandlerChromeRefreshIcon,
    { kProtocolHandlerChromeRefreshPath, std::size(kProtocolHandlerChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kProtocolHandlerOffChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 16, 18.13f, LINE_TO, 13.38f, 15.5f, R_LINE_TO,
    -0.5f, 0.56f, R_ARC_TO, 0.97f, 0.97f, 0, 0, 1, -0.33f, 0.25f, R_ARC_TO, 1.04f, 1.04f, 0, 0, 1, -0.42f, 0.08f, R_CUBIC_TO, -0.15f, 0, -0.29f, -0.03f, -0.42f,
    -0.08f, R_ARC_TO, 0.81f, 0.81f, 0, 0, 1, -0.31f, -0.25f, LINE_TO, 10, 14.52f, R_LINE_TO, -1.39f, 1.54f, R_ARC_TO, 0.98f, 0.98f, 0, 0, 1, -0.33f, 0.25f,
    R_ARC_TO, 1.04f, 1.04f, 0, 0, 1, -0.81f, 0, R_ARC_TO, 0.97f, 0.97f, 0, 0, 1, -0.33f, -0.25f, LINE_TO, 2.25f, 10.67f, R_ARC_TO, 0.84f, 0.84f, 0, 0, 1,
    -0.19f, -0.3f, ARC_TO, 1.05f, 1.05f, 0, 0, 1, 2, 10, R_ARC_TO, 0.99f, 0.99f, 0, 0, 1, 0.25f, -0.67f, LINE_TO, 4.61f, 6.73f, LINE_TO, 1.88f, 4, R_LINE_TO,
    1.06f, -1.06f, R_LINE_TO, 14.12f, 14.13f, CLOSE, R_MOVE_TO, -3.69f, -3.69f, R_LINE_TO, -1.17f, -1.19f, CLOSE, R_MOVE_TO, -4.44f, 0.21f, LINE_TO, 9, 13.42f,
    R_LINE_TO, -2.5f, -2.75f, ARC_TO, 0.99f, 0.99f, 0, 0, 1, 6.25f, 10, R_CUBIC_TO, 0, -0.25f, 0.08f, -0.47f, 0.25f, -0.67f, R_LINE_TO, 0.33f, -0.37f,
    R_LINE_TO, -1.16f, -1.16f, R_LINE_TO, -2, 2.21f, CLOSE, R_MOVE_TO, 7.52f, -1.37f, R_LINE_TO, -1.06f, -1.06f, R_LINE_TO, 2, -2.21f, R_LINE_TO, -4.35f, -4.5f,
    LINE_TO, 11, 6.58f, R_LINE_TO, 2.5f, 2.75f, R_CUBIC_TO, 0.17f, 0.2f, 0.25f, 0.42f, 0.25f, 0.67f, R_CUBIC_TO, 0, 0.25f, -0.08f, 0.47f, -0.25f, 0.67f,
    R_LINE_TO, -0.33f, 0.38f, LINE_TO, 6.63f, 4.5f, R_LINE_TO, 0.5f, -0.56f, R_CUBIC_TO, 0.11f, -0.11f, 0.23f, -0.19f, 0.34f, -0.25f, R_ARC_TO, 0.96f, 0.96f, 0,
    0, 1, 0.41f, -0.08f, R_CUBIC_TO, 0.14f, 0, 0.27f, 0.03f, 0.4f, 0.08f, R_CUBIC_TO, 0.13f, 0.05f, 0.24f, 0.14f, 0.34f, 0.25f, LINE_TO, 10, 5.48f, R_LINE_TO,
    1.4f, -1.54f, R_ARC_TO, 0.98f, 0.98f, 0, 0, 1, 0.34f, -0.25f, R_ARC_TO, 1.04f, 1.04f, 0, 0, 1, 0.81f, 0, R_CUBIC_TO, 0.13f, 0.06f, 0.23f, 0.14f, 0.33f,
    0.25f, R_LINE_TO, 4.88f, 5.4f, ARC_TO, 0.99f, 0.99f, 0, 0, 1, 18, 10, R_ARC_TO, 0.99f, 0.99f, 0, 0, 1, -0.25f, 0.67f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kProtocolHandlerOffChromeRefreshRepList, kProtocolHandlerOffChromeRefreshIcon,
    { kProtocolHandlerOffChromeRefreshPath, std::size(kProtocolHandlerOffChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kRadioButtonCheckedPath, CANVAS_DIMENSIONS, 20, MOVE_TO, 10, 14, R_CUBIC_TO, 1.11f, 0, 2.05f, -0.39f, 2.83f, -1.17f, ARC_TO, 3.87f,
    3.87f, 0, 0, 0, 14, 10, R_CUBIC_TO, 0, -1.11f, -0.39f, -2.05f, -1.17f, -2.83f, ARC_TO, 3.87f, 3.87f, 0, 0, 0, 10, 6, R_CUBIC_TO, -1.11f, 0, -2.05f, 0.39f,
    -2.83f, 1.17f, ARC_TO, 3.87f, 3.87f, 0, 0, 0, 6, 10, R_CUBIC_TO, 0, 1.11f, 0.39f, 2.05f, 1.17f, 2.83f, ARC_TO, 3.87f, 3.87f, 0, 0, 0, 10, 14, CLOSE,
    R_MOVE_TO, 0, 4.17f, R_ARC_TO, 7.99f, 7.99f, 0, 0, 1, -3.18f, -0.64f, R_ARC_TO, 8.22f, 8.22f, 0, 0, 1, -4.36f, -4.36f, R_ARC_TO, 7.99f, 7.99f, 0, 0, 1,
    -0.64f, -3.18f, R_CUBIC_TO, 0, -1.13f, 0.21f, -2.19f, 0.64f, -3.18f, ARC_TO, 8.22f, 8.22f, 0, 0, 1, 6.82f, 2.47f, R_ARC_TO, 7.99f, 7.99f, 0, 0, 1, 3.18f,
    -0.64f, R_CUBIC_TO, 1.13f, 0, 2.19f, 0.21f, 3.18f, 0.64f, R_ARC_TO, 8.22f, 8.22f, 0, 0, 1, 2.59f, 1.75f, R_ARC_TO, 8.2f, 8.2f, 0, 0, 1, 1.75f, 2.6f,
    R_CUBIC_TO, 0.43f, 0.99f, 0.64f, 2.05f, 0.64f, 3.18f, R_CUBIC_TO, 0, 1.13f, -0.21f, 2.19f, -0.64f, 3.18f, R_ARC_TO, 8.22f, 8.22f, 0, 0, 1, -4.35f, 4.36f,
    R_ARC_TO, 7.94f, 7.94f, 0, 0, 1, -3.18f, 0.64f, CLOSE, MOVE_TO, 10, 16.44f, R_CUBIC_TO, 1.79f, 0, 3.31f, -0.62f, 4.56f, -1.88f, R_CUBIC_TO, 1.25f, -1.25f,
    1.88f, -2.77f, 1.88f, -4.56f, R_CUBIC_TO, 0, -1.79f, -0.62f, -3.31f, -1.88f, -4.56f, CUBIC_TO, 13.31f, 4.18f, 11.79f, 3.56f, 10, 3.56f, R_CUBIC_TO, -1.79f,
    0, -3.31f, 0.63f, -4.56f, 1.88f, CUBIC_TO, 4.18f, 6.69f, 3.56f, 8.21f, 3.56f, 10, R_CUBIC_TO, 0, 1.79f, 0.63f, 3.31f, 1.88f, 4.56f, R_CUBIC_TO, 1.25f,
    1.25f, 2.77f, 1.88f, 4.56f, 1.88f, CLOSE, MOVE_TO, 10, 10, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kRadioButtonCheckedRepList, kRadioButtonCheckedIcon, { kRadioButtonCheckedPath, std::size(kRadioButtonCheckedPath) })
VECTOR_ICON_REP_TEMPLATE(kReloadPath, CANVAS_DIMENSIONS, 32, MOVE_TO, 25.1f, 20.15f, LINE_TO, 25.08f, 20.14f, CUBIC_TO, 23.51f, 23.59f, 20.04f, 26, 16, 26,
    CUBIC_TO, 10.48f, 26, 6, 21.52f, 6, 16, CUBIC_TO, 6, 10.48f, 10.48f, 6, 16, 6, CUBIC_TO, 19.02f, 6, 21.72f, 7.34f, 23.55f, 9.45f, LINE_TO, 23.55f, 9.45f,
    LINE_TO, 19, 14, LINE_TO, 25.8f, 14, LINE_TO, 28.83f, 14, LINE_TO, 30, 14, LINE_TO, 30, 3, LINE_TO, 25.67f, 7.33f, CUBIC_TO, 23.3f, 4.67f, 19.85f, 3, 16, 3,
    CUBIC_TO, 8.82f, 3, 3, 8.82f, 3, 16, CUBIC_TO, 3, 23.18f, 8.82f, 29, 16, 29, CUBIC_TO, 21.27f, 29, 25.8f, 25.86f, 27.84f, 21.34f, CUBIC_TO, 27.96f, 21.13f,
    28.03f, 20.88f, 28.03f, 20.61f, CUBIC_TO, 28.03f, 19.78f, 27.36f, 19.11f, 26.53f, 19.11f, CUBIC_TO, 25.87f, 19.11f, 25.3f, 19.55f, 25.1f, 20.15f, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kReload16Path, CANVAS_DIMENSIONS, 16, MOVE_TO, 15, 1, LINE_TO, 15, 7, LINE_TO, 9, 7, LINE_TO, 11.62f, 4.37f, CUBIC_TO, 10.67f, 3.43f,
    9.44f, 3, 8, 3, CUBIC_TO, 5.09f, 3, 3, 5.1f, 3, 8, CUBIC_TO, 3, 10.9f, 5.09f, 13, 8, 13, CUBIC_TO, 10.3f, 13, 12.08f, 11.81f, 12.75f, 9.83f, LINE_TO,
    12.77f, 9.79f, CUBIC_TO, 12.93f, 9.44f, 13.47f, 9.18f, 13.76f, 9.18f, CUBIC_TO, 14.15f, 9.18f, 14.79f, 9.41f, 14.79f, 10.01f, CUBIC_TO, 14.79f, 10.14f,
    14.71f, 10.46f, 14.66f, 10.57f, CUBIC_TO, 13.66f, 13.13f, 10.98f, 15, 8.03f, 15, CUBIC_TO, 4.15f, 15, 1, 11.87f, 1, 8, CUBIC_TO, 1, 4.13f, 4.15f, 1, 8.03f,
    1, CUBIC_TO, 9.96f, 1, 11.7f, 1.77f, 12.97f, 3.03f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kReloadRepList, kReloadIcon, { kReloadPath, std::size(kReloadPath) }, { kReload16Path, std::size(kReload16Path) })
VECTOR_ICON_REP_TEMPLATE(kReloadChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 10, 16, R_CUBIC_TO, -1.67f, 0, -3.08f, -0.58f, -4.25f,
    -1.75f, CUBIC_TO, 4.58f, 13.08f, 4, 11.67f, 4, 10, R_CUBIC_TO, 0, -1.67f, 0.58f, -3.08f, 1.75f, -4.25f, CUBIC_TO, 6.92f, 4.58f, 8.33f, 4, 10, 4, R_CUBIC_TO,
    0.9f, 0, 1.74f, 0.19f, 2.51f, 0.56f, R_CUBIC_TO, 0.77f, 0.38f, 1.43f, 0.88f, 1.99f, 1.5f, V_LINE_TO, 4, H_LINE_TO, 16, R_V_LINE_TO, 5, R_H_LINE_TO, -5,
    V_LINE_TO, 7.5f, R_H_LINE_TO, 2.73f, R_ARC_TO, 4.44f, 4.44f, 0, 0, 0, -1.58f, -1.46f, ARC_TO, 4.33f, 4.33f, 0, 0, 0, 10, 5.5f, R_CUBIC_TO, -1.25f, 0,
    -2.31f, 0.44f, -3.19f, 1.31f, CUBIC_TO_SHORTHAND, 5.5f, 8.75f, 5.5f, 10, R_CUBIC_TO, 0, 1.25f, 0.44f, 2.31f, 1.31f, 3.19f, CUBIC_TO, 7.69f, 14.06f, 8.75f,
    14.5f, 10, 14.5f, R_CUBIC_TO, 1.17f, 0, 2.17f, -0.39f, 3, -1.16f, R_ARC_TO, 4.43f, 4.43f, 0, 0, 0, 1.44f, -2.84f, R_H_LINE_TO, 1.54f, R_CUBIC_TO, -0.12f,
    1.56f, -0.76f, 2.86f, -1.9f, 3.92f, CUBIC_TO, 12.95f, 15.47f, 11.58f, 16, 10, 16, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kReloadChromeRefreshRepList, kReloadChromeRefreshIcon, { kReloadChromeRefreshPath, std::size(kReloadChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kReplayPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 12, 5, V_LINE_TO, 1, LINE_TO, 7, 6, R_LINE_TO, 5, 5, V_LINE_TO, 7, R_CUBIC_TO, 3.31f, 0,
    6, 2.69f, 6, 6, R_CUBIC_TO, 0, 3.31f, -2.69f, 6, -6, 6, R_CUBIC_TO, -3.31f, 0, -6, -2.69f, -6, -6, H_LINE_TO, 4, R_CUBIC_TO, 0, 4.42f, 3.58f, 8, 8, 8,
    R_CUBIC_TO, 4.42f, 0, 8, -3.58f, 8, -8, R_CUBIC_TO, 0, -4.42f, -3.58f, -8, -8, -8, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kReplayRepList, kReplayIcon, { kReplayPath, std::size(kReplayPath) })
VECTOR_ICON_REP_TEMPLATE(kReplay10Path, CANVAS_DIMENSIONS, 960, MOVE_TO, 480, 880, R_QUADRATIC_TO, -75, 0, -140.5f, -28.5f, R_QUADRATIC_TO, -65.5f, -28.5f,
    -114, -77, R_QUADRATIC_TO, -48.5f, -48.5f, -77, -114, QUADRATIC_TO_SHORTHAND, 120, 520, R_H_LINE_TO, 80, R_QUADRATIC_TO, 0, 117, 81.5f, 198.5f,
    QUADRATIC_TO_SHORTHAND, 480, 800, R_QUADRATIC_TO, 117, 0, 198.5f, -81.5f, QUADRATIC_TO_SHORTHAND, 760, 520, R_QUADRATIC_TO, 0, -117, -81.5f, -198.5f,
    QUADRATIC_TO_SHORTHAND, 480, 240, R_H_LINE_TO, -6, R_LINE_TO, 62, 62, R_LINE_TO, -56, 58, R_LINE_TO, -160, -160, R_LINE_TO, 160, -160, R_LINE_TO, 56, 58,
    R_LINE_TO, -62, 62, R_H_LINE_TO, 6, R_QUADRATIC_TO, 75, 0, 140.5f, 28.5f, R_QUADRATIC_TO, 65.5f, 28.5f, 114, 77, R_QUADRATIC_TO, 48.5f, 48.5f, 77, 114,
    QUADRATIC_TO_SHORTHAND, 840, 520, R_QUADRATIC_TO, 0, 75, -28.5f, 140.5f, R_QUADRATIC_TO, -28.5f, 65.5f, -77, 114, R_QUADRATIC_TO, -48.5f, 48.5f, -114, 77,
    QUADRATIC_TO_SHORTHAND, 480, 880, CLOSE, MOVE_TO, 360, 640, R_V_LINE_TO, -180, R_H_LINE_TO, -60, R_V_LINE_TO, -60, R_H_LINE_TO, 120, R_V_LINE_TO, 240,
    R_H_LINE_TO, -60, CLOSE, R_MOVE_TO, 140, 0, R_QUADRATIC_TO, -17, 0, -28.5f, -11.5f, QUADRATIC_TO_SHORTHAND, 460, 600, R_V_LINE_TO, -160, R_QUADRATIC_TO, 0,
    -17, 11.5f, -28.5f, QUADRATIC_TO_SHORTHAND, 500, 400, R_H_LINE_TO, 80, R_QUADRATIC_TO, 17, 0, 28.5f, 11.5f, QUADRATIC_TO_SHORTHAND, 620, 440, R_V_LINE_TO,
    160, R_QUADRATIC_TO, 0, 17, -11.5f, 28.5f, QUADRATIC_TO_SHORTHAND, 580, 640, R_H_LINE_TO, -80, CLOSE, R_MOVE_TO, 20, -60, R_H_LINE_TO, 40, R_V_LINE_TO,
    -120, R_H_LINE_TO, -40, R_V_LINE_TO, 120, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kReplay10RepList, kReplay10Icon, { kReplay10Path, std::size(kReplay10Path) })
VECTOR_ICON_REP_TEMPLATE(kSaveCloudPath, CANVAS_DIMENSIONS, 20, MOVE_TO, 5.02f, 16.17f, CUBIC_TO, 3.85f, 16.17f, 2.87f, 15.76f, 2.06f, 14.96f, CUBIC_TO, 1.26f,
    14.14f, 0.85f, 13.15f, 0.85f, 12, CUBIC_TO, 0.85f, 10.9f, 1.21f, 9.96f, 1.92f, 9.17f, CUBIC_TO, 2.64f, 8.36f, 3.54f, 7.92f, 4.63f, 7.85f, CUBIC_TO, 4.97f,
    6.66f, 5.64f, 5.69f, 6.63f, 4.96f, CUBIC_TO, 7.63f, 4.21f, 8.75f, 3.83f, 10, 3.83f, CUBIC_TO, 11.5f, 3.83f, 12.81f, 4.31f, 13.92f, 5.27f, CUBIC_TO, 15.03f,
    6.22f, 15.6f, 7.41f, 15.65f, 8.85f, CUBIC_TO, 16.63f, 8.9f, 17.46f, 9.27f, 18.13f, 9.98f, CUBIC_TO, 18.81f, 10.67f, 19.15f, 11.51f, 19.15f, 12.5f, CUBIC_TO,
    19.15f, 13.51f, 18.78f, 14.38f, 18.06f, 15.1f, CUBIC_TO, 17.35f, 15.81f, 16.49f, 16.17f, 15.48f, 16.17f, H_LINE_TO, 10.94f, CUBIC_TO, 10.47f, 16.17f,
    10.06f, 16, 9.71f, 15.67f, CUBIC_TO, 9.38f, 15.32f, 9.21f, 14.91f, 9.21f, 14.44f, V_LINE_TO, 11.13f, LINE_TO, 7.98f, 12.35f, LINE_TO, 6.88f, 11.23f,
    LINE_TO, 10, 8.1f, LINE_TO, 13.13f, 11.23f, LINE_TO, 12.02f, 12.35f, LINE_TO, 10.79f, 11.13f, V_LINE_TO, 14.44f, H_LINE_TO, 15.48f, CUBIC_TO, 16.02f,
    14.44f, 16.48f, 14.25f, 16.85f, 13.88f, CUBIC_TO, 17.23f, 13.5f, 17.42f, 13.04f, 17.42f, 12.5f, CUBIC_TO, 17.42f, 11.96f, 17.23f, 11.5f, 16.85f, 11.13f,
    CUBIC_TO, 16.48f, 10.75f, 16.02f, 10.56f, 15.48f, 10.56f, H_LINE_TO, 13.92f, V_LINE_TO, 8.98f, CUBIC_TO, 13.92f, 7.99f, 13.53f, 7.18f, 12.75f, 6.54f,
    CUBIC_TO, 11.97f, 5.89f, 11.05f, 5.56f, 9.98f, 5.56f, CUBIC_TO, 8.92f, 5.56f, 8.03f, 5.96f, 7.29f, 6.75f, CUBIC_TO, 6.57f, 7.53f, 6.13f, 8.47f, 5.98f,
    9.56f, H_LINE_TO, 5.02f, CUBIC_TO, 4.34f, 9.56f, 3.76f, 9.81f, 3.29f, 10.29f, CUBIC_TO, 2.82f, 10.76f, 2.58f, 11.33f, 2.58f, 12, CUBIC_TO, 2.58f, 12.68f,
    2.82f, 13.26f, 3.29f, 13.73f, CUBIC_TO, 3.76f, 14.2f, 4.34f, 14.44f, 5.02f, 14.44f, H_LINE_TO, 7.71f, V_LINE_TO, 16.17f, H_LINE_TO, 5.02f, CLOSE, NEW_PATH)
VECTOR_ICON_TEMPLATE_CC(kSaveCloudRepList, kSaveCloudIcon, { kSaveCloudPath, std::size(kSaveCloudPath) })
VECTOR_ICON_REP_TEMPLATE(kSciencePath, CANVAS_DIMENSIONS, 24, FILL_RULE_NONZERO, MOVE_TO, 5, 21, R_CUBIC_TO, -0.85f, 0, -1.45f, -0.38f, -1.81f, -1.14f,
    R_CUBIC_TO, -0.36f, -0.76f, -0.27f, -1.46f, 0.26f, -2.11f, LINE_TO, 9, 11, V_LINE_TO, 5, H_LINE_TO, 8, R_ARC_TO, 0.96f, 0.96f, 0, 0, 1, -0.71f, -0.29f,
    ARC_TO, 0.96f, 0.96f, 0, 0, 1, 7, 4, R_CUBIC_TO, 0, -0.28f, 0.1f, -0.52f, 0.29f, -0.71f, ARC_TO, 0.96f, 0.96f, 0, 0, 1, 8, 3, R_H_LINE_TO, 8, R_CUBIC_TO,
    0.28f, 0, 0.52f, 0.1f, 0.71f, 0.29f, R_CUBIC_TO, 0.19f, 0.19f, 0.29f, 0.43f, 0.29f, 0.71f, R_CUBIC_TO, 0, 0.28f, -0.1f, 0.52f, -0.29f, 0.71f, ARC_TO, 0.96f,
    0.96f, 0, 0, 1, 16, 5, R_H_LINE_TO, -1, R_V_LINE_TO, 6, R_LINE_TO, 5.55f, 6.75f, R_CUBIC_TO, 0.53f, 0.65f, 0.62f, 1.36f, 0.26f, 2.11f, CUBIC_TO, 20.45f,
    20.62f, 19.85f, 21, 19, 21, CLOSE, R_MOVE_TO, 0, -2, R_H_LINE_TO, 14, R_LINE_TO, -6, -7.3f, V_LINE_TO, 5, R_H_LINE_TO, -2, R_V_LINE_TO, 6.7f, CLOSE,
    R_MOVE_TO, 7, -7, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kScience20Path, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 4.5f, 17, R_CUBIC_TO, -0.64f, 0, -1.1f, -0.28f, -1.37f, -0.84f,
    R_CUBIC_TO, -0.28f, -0.56f, -0.21f, -1.09f, 0.19f, -1.58f, LINE_TO, 7.5f, 9.5f, R_V_LINE_TO, -5, R_H_LINE_TO, -0.75f, R_CUBIC_TO, -0.21f, 0, -0.39f, -0.07f,
    -0.53f, -0.21f, ARC_TO, 0.72f, 0.72f, 0, 0, 1, 6, 3.75f, R_CUBIC_TO, 0, -0.21f, 0.07f, -0.39f, 0.22f, -0.53f, ARC_TO, 0.73f, 0.73f, 0, 0, 1, 6.75f, 3,
    R_H_LINE_TO, 6.5f, R_CUBIC_TO, 0.21f, 0, 0.39f, 0.07f, 0.54f, 0.22f, R_CUBIC_TO, 0.14f, 0.14f, 0.22f, 0.32f, 0.22f, 0.53f, R_CUBIC_TO, 0, 0.21f, -0.07f,
    0.39f, -0.21f, 0.54f, R_ARC_TO, 0.73f, 0.73f, 0, 0, 1, -0.53f, 0.22f, R_H_LINE_TO, -0.75f, R_V_LINE_TO, 5, R_LINE_TO, 4.19f, 5.08f, R_CUBIC_TO, 0.39f,
    0.49f, 0.45f, 1.01f, 0.17f, 1.57f, R_CUBIC_TO, -0.28f, 0.56f, -0.73f, 0.84f, -1.35f, 0.84f, CLOSE, R_MOVE_TO, 0, -1.5f, R_H_LINE_TO, 11, LINE_TO, 11, 10,
    V_LINE_TO, 4.5f, H_LINE_TO, 9, V_LINE_TO, 10, CLOSE, R_MOVE_TO, 5.52f, -5.5f, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kScience16Path, CANVAS_DIMENSIONS, 16, FILL_RULE_NONZERO, MOVE_TO, 3.6f, 13.73f, R_CUBIC_TO, -0.57f, 0, -0.98f, -0.25f, -1.22f, -0.75f,
    R_CUBIC_TO, -0.25f, -0.5f, -0.19f, -0.97f, 0.17f, -1.41f, R_LINE_TO, 3.32f, -4.03f, V_LINE_TO, 3.69f, R_H_LINE_TO, -0.47f, R_ARC_TO, 0.68f, 0.68f, 0, 0, 1,
    -0.49f, -0.2f, R_ARC_TO, 0.67f, 0.67f, 0, 0, 1, -0.2f, -0.49f, R_ARC_TO, 0.67f, 0.67f, 0, 0, 1, 0.2f, -0.49f, R_ARC_TO, 0.66f, 0.66f, 0, 0, 1, 0.49f, -0.2f,
    R_H_LINE_TO, 5.23f, R_CUBIC_TO, 0.19f, 0, 0.36f, 0.07f, 0.49f, 0.2f, R_ARC_TO, 0.66f, 0.66f, 0, 0, 1, 0.2f, 0.49f, R_ARC_TO, 0.67f, 0.67f, 0, 0, 1, -0.2f,
    0.49f, R_ARC_TO, 0.66f, 0.66f, 0, 0, 1, -0.49f, 0.2f, R_H_LINE_TO, -0.48f, R_V_LINE_TO, 3.86f, R_LINE_TO, 3.32f, 4.03f, R_CUBIC_TO, 0.35f, 0.43f, 0.4f,
    0.9f, 0.15f, 1.4f, R_CUBIC_TO, -0.25f, 0.5f, -0.65f, 0.75f, -1.21f, 0.75f, CLOSE, R_MOVE_TO, 0.1f, -1.38f, R_H_LINE_TO, 8.59f, LINE_TO, 8.75f, 8.02f,
    V_LINE_TO, 3.69f, H_LINE_TO, 7.25f, V_LINE_TO, 8.02f, CLOSE, MOVE_TO, 8.02f, 8.02f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kScienceRepList, kScienceIcon, { kSciencePath, std::size(kSciencePath) }, { kScience20Path, std::size(kScience20Path) },
    { kScience16Path, std::size(kScience16Path) })
VECTOR_ICON_REP_TEMPLATE(kScreenSharePath, MOVE_TO, 40, 36, R_CUBIC_TO, 2.2f, 0, 3.98f, -1.8f, 3.98f, -4, LINE_TO, 44, 12, R_CUBIC_TO, 0, -2.22f, -1.8f, -4, -4,
    -4, H_LINE_TO, 8, R_CUBIC_TO, -2.22f, 0, -4, 1.78f, -4, 4, R_V_LINE_TO, 20, R_CUBIC_TO, 0, 2.2f, 1.78f, 4, 4, 4, H_LINE_TO, 0, R_V_LINE_TO, 4, R_H_LINE_TO,
    48, R_V_LINE_TO, -4, R_H_LINE_TO, -8, CLOSE, R_MOVE_TO, -14, -7.06f, R_V_LINE_TO, -4.38f, R_CUBIC_TO, -5.56f, 0, -9.22f, 1.7f, -12, 5.44f, R_CUBIC_TO,
    1.12f, -5.34f, 4.22f, -10.66f, 12, -11.74f, V_LINE_TO, 14, R_LINE_TO, 8, 7.46f, R_LINE_TO, -8, 7.48f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kScreenShareRepList, kScreenShareIcon, { kScreenSharePath, std::size(kScreenSharePath) })
VECTOR_ICON_REP_TEMPLATE(kSearchPath, CANVAS_DIMENSIONS, 32, MOVE_TO, 20.29f, 19.45f, LINE_TO, 19.93f, 19.09f, CUBIC_TO, 21.23f, 17.59f, 22.13f, 15.52f, 22.13f,
    12.96f, CUBIC_TO, 22.13f, 8.23f, 17.85f, 4, 13.07f, 4, CUBIC_TO, 8.28f, 4, 4, 8.23f, 4, 12.96f, CUBIC_TO, 4, 17.69f, 9.18f, 21.92f, 13.26f, 21.92f,
    CUBIC_TO, 15.66f, 21.92f, 17.51f, 21.26f, 18.98f, 20.02f, LINE_TO, 19.35f, 20.38f, LINE_TO, 19.35f, 21.42f, LINE_TO, 26.01f, 28, LINE_TO, 28, 26.04f,
    LINE_TO, 21.35f, 19.45f, LINE_TO, 20.29f, 19.45f, CLOSE, MOVE_TO, 13.07f, 19.36f, CUBIC_TO, 9.49f, 19.36f, 6.59f, 16.5f, 6.59f, 12.96f, CUBIC_TO, 6.59f,
    9.43f, 9.49f, 6.56f, 13.07f, 6.56f, CUBIC_TO, 16.64f, 6.56f, 19.54f, 9.43f, 19.54f, 12.96f, CUBIC_TO, 19.54f, 16.5f, 16.64f, 19.36f, 13.07f, 19.36f,
    LINE_TO, 13.07f, 19.36f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kSearchRepList, kSearchIcon, { kSearchPath, std::size(kSearchPath) })
VECTOR_ICON_REP_TEMPLATE(kSearchChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, R_MOVE_TO, 15.94f, 17, R_LINE_TO, -4.98f, -4.98f, R_ARC_TO, 4.99f,
    4.99f, 0, 0, 1, -1.37f, 0.72f, ARC_TO, 4.71f, 4.71f, 0, 0, 1, 8, 13, R_CUBIC_TO, -1.39f, 0, -2.57f, -0.48f, -3.54f, -1.46f, CUBIC_TO, 3.48f, 10.57f, 3,
    9.39f, 3, 8, R_CUBIC_TO, 0, -1.39f, 0.48f, -2.57f, 1.46f, -3.54f, CUBIC_TO, 5.43f, 3.48f, 6.61f, 3, 8, 3, R_CUBIC_TO, 1.39f, 0, 2.57f, 0.48f, 3.54f, 1.46f,
    CUBIC_TO, 12.52f, 5.43f, 13, 6.61f, 13, 8, R_CUBIC_TO, 0, 0.56f, -0.09f, 1.09f, -0.26f, 1.59f, R_CUBIC_TO, -0.17f, 0.5f, -0.41f, 0.96f, -0.72f, 1.37f,
    R_LINE_TO, 4.98f, 4.98f, CLOSE, MOVE_TO, 8, 11.5f, R_CUBIC_TO, 0.97f, 0, 1.8f, -0.34f, 2.48f, -1.02f, R_CUBIC_TO, 0.68f, -0.68f, 1.02f, -1.51f, 1.02f,
    -2.48f, R_CUBIC_TO, 0, -0.97f, -0.34f, -1.8f, -1.02f, -2.48f, CUBIC_TO, 9.8f, 4.84f, 8.97f, 4.5f, 8, 4.5f, R_CUBIC_TO, -0.97f, 0, -1.8f, 0.34f, -2.48f,
    1.02f, CUBIC_TO, 4.84f, 6.2f, 4.5f, 7.03f, 4.5f, 8, R_CUBIC_TO, 0, 0.97f, 0.34f, 1.8f, 1.02f, 2.48f, R_CUBIC_TO, 0.68f, 0.68f, 1.51f, 1.02f, 2.48f, 1.02f,
    CLOSE)
VECTOR_ICON_TEMPLATE_CC(kSearchChromeRefreshRepList, kSearchChromeRefreshIcon, { kSearchChromeRefreshPath, std::size(kSearchChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kSelectWindowPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 21, 1, H_LINE_TO, 8, R_CUBIC_TO, -1.1f, 0, -2, 0.9f, -2, 2, R_V_LINE_TO, 6,
    H_LINE_TO, 3, R_CUBIC_TO, -1.1f, 0, -2, 0.9f, -2, 2, R_V_LINE_TO, 10, R_CUBIC_TO, 0, 1.1f, 0.9f, 2, 2, 2, R_H_LINE_TO, 13, R_CUBIC_TO, 1.1f, 0, 2, -0.9f, 2,
    -2, R_V_LINE_TO, -6, R_H_LINE_TO, 3, R_CUBIC_TO, 1.1f, 0, 2, -0.9f, 2, -2, V_LINE_TO, 3, R_CUBIC_TO, 0, -1.1f, -0.9f, -2, -2, -2, CLOSE, R_MOVE_TO, -5, 20,
    H_LINE_TO, 3, R_V_LINE_TO, -8, R_H_LINE_TO, 13, R_V_LINE_TO, 8, CLOSE, R_MOVE_TO, 5, -8, R_H_LINE_TO, -3, R_V_LINE_TO, -2, R_CUBIC_TO, 0, -1.1f, -0.9f, -2,
    -2, -2, H_LINE_TO, 8, V_LINE_TO, 5, R_H_LINE_TO, 13, R_V_LINE_TO, 8, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kSelectWindowRepList, kSelectWindowIcon, { kSelectWindowPath, std::size(kSelectWindowPath) })
VECTOR_ICON_REP_TEMPLATE(kSelectWindowChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 3.5f, 18, R_CUBIC_TO, -0.41f, 0, -0.77f, -0.15f,
    -1.06f, -0.44f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 2, 16.5f, R_V_LINE_TO, -7, R_CUBIC_TO, 0, -0.41f, 0.15f, -0.77f, 0.44f, -1.06f, ARC_TO, 1.44f, 1.44f, 0, 0,
    1, 3.5f, 8, H_LINE_TO, 5, V_LINE_TO, 3.5f, R_CUBIC_TO, 0, -0.41f, 0.15f, -0.77f, 0.44f, -1.06f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 6.5f, 2, R_H_LINE_TO, 10,
    R_CUBIC_TO, 0.41f, 0, 0.77f, 0.15f, 1.06f, 0.44f, R_CUBIC_TO, 0.29f, 0.29f, 0.44f, 0.65f, 0.44f, 1.06f, R_V_LINE_TO, 7, R_CUBIC_TO, 0, 0.41f, -0.15f, 0.77f,
    -0.44f, 1.06f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 16.5f, 12, H_LINE_TO, 15, R_V_LINE_TO, 4.5f, R_CUBIC_TO, 0, 0.41f, -0.15f, 0.77f, -0.44f, 1.06f, ARC_TO,
    1.44f, 1.44f, 0, 0, 1, 13.5f, 18, CLOSE, R_MOVE_TO, 0, -1.5f, R_H_LINE_TO, 10, V_LINE_TO, 11, R_H_LINE_TO, -10, CLOSE, R_MOVE_TO, 11.5f, -6, R_H_LINE_TO,
    1.5f, V_LINE_TO, 5, R_H_LINE_TO, -10, R_V_LINE_TO, 3, R_H_LINE_TO, 7, R_CUBIC_TO, 0.41f, 0, 0.77f, 0.15f, 1.06f, 0.44f, R_CUBIC_TO, 0.29f, 0.29f, 0.44f,
    0.65f, 0.44f, 1.06f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(
    kSelectWindowChromeRefreshRepList, kSelectWindowChromeRefreshIcon, { kSelectWindowChromeRefreshPath, std::size(kSelectWindowChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kSelectWindowOffChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 16.73f, 18.83f, LINE_TO, 8.9f, 11, H_LINE_TO,
    3.5f, R_V_LINE_TO, 5.5f, R_H_LINE_TO, 10, R_V_LINE_TO, -3, R_LINE_TO, 1.5f, 1.5f, R_V_LINE_TO, 1.51f, R_CUBIC_TO, 0, 0.41f, -0.15f, 0.76f, -0.44f, 1.06f,
    ARC_TO, 1.44f, 1.44f, 0, 0, 1, 13.5f, 18, R_H_LINE_TO, -10, R_CUBIC_TO, -0.41f, 0, -0.77f, -0.15f, -1.06f, -0.44f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 2, 16.5f,
    V_LINE_TO, 9.5f, R_CUBIC_TO, 0, -0.43f, 0.14f, -0.79f, 0.44f, -1.09f, ARC_TO, 1.31f, 1.31f, 0, 0, 1, 3.5f, 8, H_LINE_TO, 5, R_V_LINE_TO, -0.87f, LINE_TO,
    1.17f, 3.27f, LINE_TO, 2.23f, 2.23f, R_LINE_TO, 15.54f, 15.54f, CLOSE, MOVE_TO, 15, 12.88f, LINE_TO, 10.13f, 8, H_LINE_TO, 13.5f, R_CUBIC_TO, 0.43f, 0,
    0.79f, 0.14f, 1.07f, 0.43f, R_CUBIC_TO, 0.28f, 0.28f, 0.43f, 0.64f, 0.43f, 1.07f, R_V_LINE_TO, 1, R_H_LINE_TO, 1.5f, V_LINE_TO, 5, H_LINE_TO, 7.13f,
    R_LINE_TO, -2.02f, -2.02f, R_CUBIC_TO, 0.1f, -0.31f, 0.27f, -0.55f, 0.53f, -0.72f, CUBIC_TO, 5.9f, 2.09f, 6.18f, 2, 6.5f, 2, R_H_LINE_TO, 10, R_CUBIC_TO,
    0.41f, 0, 0.77f, 0.15f, 1.06f, 0.44f, R_CUBIC_TO, 0.29f, 0.29f, 0.44f, 0.65f, 0.44f, 1.06f, R_V_LINE_TO, 7, R_CUBIC_TO, 0, 0.41f, -0.15f, 0.77f, -0.44f,
    1.06f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 16.5f, 12, H_LINE_TO, 15, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kSelectWindowOffChromeRefreshRepList, kSelectWindowOffChromeRefreshIcon,
    { kSelectWindowOffChromeRefreshPath, std::size(kSelectWindowOffChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kSendPath, CANVAS_DIMENSIONS, 20, MOVE_TO, 3, 3, LINE_TO, 18, 10, LINE_TO, 3, 17, V_LINE_TO, 3, CLOSE, MOVE_TO, 4.5f, 5.36f, LINE_TO,
    14.45f, 10, LINE_TO, 4.5f, 14.64f, V_LINE_TO, 12, LINE_TO, 9, 10, LINE_TO, 4.5f, 8, V_LINE_TO, 5.36f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kSendRepList, kSendIcon, { kSendPath, std::size(kSendPath) })
VECTOR_ICON_REP_TEMPLATE(kSensorsPath, CANVAS_DIMENSIONS, 18, MOVE_TO, 9, 7.6f, CUBIC_TO, 8.2f, 7.6f, 7.6f, 8.2f, 7.6f, 9, R_CUBIC_TO, 0, 0.8f, 0.6f, 1.4f,
    1.4f, 1.4f, R_CUBIC_TO, 0.8f, 0, 1.4f, -0.6f, 1.4f, -1.4f, CUBIC_TO_SHORTHAND, 9.8f, 7.6f, 9, 7.6f, CLOSE, MOVE_TO, 6.7f, 5.1f, CUBIC_TO, 5.4f, 5.9f, 4.5f,
    7.3f, 4.5f, 9, R_CUBIC_TO, 0, 1.7f, 0.9f, 3.2f, 2.2f, 4, R_LINE_TO, 0.7f, -1.3f, CUBIC_TO, 6.6f, 11.1f, 6, 10.1f, 6, 9, R_CUBIC_TO, 0, -1.1f, 0.6f, -2.1f,
    1.5f, -2.6f, LINE_TO, 6.7f, 5.1f, CLOSE, MOVE_TO, 13.5f, 9, R_CUBIC_TO, 0, -1.7f, -0.9f, -3.1f, -2.2f, -3.9f, R_LINE_TO, -0.8f, 1.3f, CUBIC_TO, 11.4f, 6.9f,
    12, 7.9f, 12, 9, R_CUBIC_TO, 0, 1.1f, -0.6f, 2.1f, -1.5f, 2.6f, R_LINE_TO, 0.8f, 1.3f, CUBIC_TO, 12.6f, 12.2f, 13.5f, 10.7f, 13.5f, 9, CLOSE, MOVE_TO, 5.2f,
    2.4f, CUBIC_TO, 3, 3.8f, 1.5f, 6.2f, 1.5f, 9, R_CUBIC_TO, 0, 2.8f, 1.5f, 5.3f, 3.7f, 6.6f, LINE_TO, 6, 14.2f, R_CUBIC_TO, -1.8f, -1.1f, -3, -3, -3, -5.3f,
    R_CUBIC_TO, 0, -2.2f, 1.2f, -4.2f, 3, -5.2f, LINE_TO, 5.2f, 2.4f, CLOSE, MOVE_TO, 12, 3.7f, R_CUBIC_TO, 1.8f, 1.1f, 3, 3, 3, 5.2f, R_CUBIC_TO, 0, 2.2f,
    -1.2f, 4.2f, -3, 5.3f, R_LINE_TO, 0.8f, 1.3f, R_CUBIC_TO, 2.2f, -1.3f, 3.8f, -3.8f, 3.8f, -6.6f, R_CUBIC_TO, 0, -2.8f, -1.5f, -5.2f, -3.7f, -6.6f, LINE_TO,
    12, 3.7f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kSensorsRepList, kSensorsIcon, { kSensorsPath, std::size(kSensorsPath) })
VECTOR_ICON_REP_TEMPLATE(kSensorsChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 4.36f, 15.65f, R_ARC_TO, 7.89f, 7.89f, 0, 0, 1, -1.73f,
    -2.53f, ARC_TO, 7.72f, 7.72f, 0, 0, 1, 2, 10.01f, R_CUBIC_TO, 0, -1.12f, 0.21f, -2.16f, 0.63f, -3.12f, R_ARC_TO, 8.37f, 8.37f, 0, 0, 1, 1.71f, -2.56f,
    R_LINE_TO, 1.06f, 1.06f, R_ARC_TO, 6.81f, 6.81f, 0, 0, 0, -1.38f, 2.08f, R_ARC_TO, 6.28f, 6.28f, 0, 0, 0, -0.51f, 2.52f, R_ARC_TO, 6.33f, 6.33f, 0, 0, 0,
    1.92f, 4.59f, CLOSE, R_MOVE_TO, 2.1f, -2.1f, R_ARC_TO, 5.5f, 5.5f, 0, 0, 1, -1.06f, -1.59f, ARC_TO, 4.85f, 4.85f, 0, 0, 1, 5, 10, R_CUBIC_TO, 0, -0.7f,
    0.13f, -1.36f, 0.4f, -1.96f, R_ARC_TO, 5.48f, 5.48f, 0, 0, 1, 1.06f, -1.59f, LINE_TO, 7.52f, 7.52f, R_ARC_TO, 3.59f, 3.59f, 0, 0, 0, -0.75f, 1.12f,
    R_ARC_TO, 3.4f, 3.4f, 0, 0, 0, -0.27f, 1.36f, R_CUBIC_TO, 0, 0.48f, 0.09f, 0.94f, 0.27f, 1.36f, R_CUBIC_TO, 0.18f, 0.42f, 0.43f, 0.8f, 0.75f, 1.12f, CLOSE,
    R_MOVE_TO, 3.54f, -1.79f, R_ARC_TO, 1.67f, 1.67f, 0, 0, 1, -1.24f, -0.52f, R_ARC_TO, 1.7f, 1.7f, 0, 0, 1, -0.51f, -1.24f, R_CUBIC_TO, 0, -0.48f, 0.17f,
    -0.89f, 0.52f, -1.23f, R_CUBIC_TO, 0.34f, -0.34f, 0.76f, -0.51f, 1.24f, -0.51f, R_CUBIC_TO, 0.48f, 0, 0.89f, 0.17f, 1.23f, 0.52f, R_CUBIC_TO, 0.34f, 0.34f,
    0.51f, 0.76f, 0.51f, 1.24f, R_CUBIC_TO, 0, 0.48f, -0.17f, 0.89f, -0.52f, 1.23f, R_CUBIC_TO, -0.34f, 0.34f, -0.76f, 0.51f, -1.24f, 0.51f, CLOSE, R_MOVE_TO,
    3.52f, 1.77f, R_LINE_TO, -1.04f, -1.04f, R_CUBIC_TO, 0.32f, -0.32f, 0.57f, -0.69f, 0.75f, -1.12f, R_ARC_TO, 3.4f, 3.4f, 0, 0, 0, 0.27f, -1.36f, R_CUBIC_TO,
    0, -0.48f, -0.09f, -0.94f, -0.27f, -1.36f, R_ARC_TO, 3.57f, 3.57f, 0, 0, 0, -0.75f, -1.12f, R_LINE_TO, 1.06f, -1.06f, R_CUBIC_TO, 0.44f, 0.46f, 0.8f, 0.99f,
    1.06f, 1.59f, ARC_TO, 4.89f, 4.89f, 0, 0, 1, 15, 10.01f, R_ARC_TO, 4.83f, 4.83f, 0, 0, 1, -1.48f, 3.51f, CLOSE, R_MOVE_TO, 2.13f, 2.13f, R_LINE_TO, -1.06f,
    -1.06f, R_ARC_TO, 6.33f, 6.33f, 0, 0, 0, 1.41f, -2.06f, R_CUBIC_TO, 0.34f, -0.78f, 0.51f, -1.62f, 0.51f, -2.52f, R_CUBIC_TO, 0, -0.9f, -0.17f, -1.75f,
    -0.51f, -2.54f, R_ARC_TO, 6.84f, 6.84f, 0, 0, 0, -1.38f, -2.07f, R_LINE_TO, 1.06f, -1.06f, R_ARC_TO, 8.37f, 8.37f, 0, 0, 1, 1.71f, 2.56f, R_ARC_TO, 7.76f,
    7.76f, 0, 0, 1, 0.63f, 3.12f, R_CUBIC_TO, 0, 1.11f, -0.21f, 2.14f, -0.62f, 3.11f, R_ARC_TO, 7.89f, 7.89f, 0, 0, 1, -1.73f, 2.53f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kSensorsChromeRefreshRepList, kSensorsChromeRefreshIcon, { kSensorsChromeRefreshPath, std::size(kSensorsChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kSensorsOffChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 16, 18.13f, LINE_TO, 6.71f, 8.83f, R_ARC_TO, 3.53f,
    3.53f, 0, 0, 0, -0.16f, 0.56f, R_CUBIC_TO, -0.04f, 0.2f, -0.05f, 0.4f, -0.05f, 0.61f, R_CUBIC_TO, 0, 0.48f, 0.09f, 0.94f, 0.27f, 1.36f, R_CUBIC_TO, 0.18f,
    0.43f, 0.43f, 0.8f, 0.75f, 1.12f, R_LINE_TO, -1.04f, 1.04f, ARC_TO, 4.86f, 4.86f, 0, 0, 1, 5, 10, R_CUBIC_TO, 0, -0.42f, 0.05f, -0.82f, 0.16f, -1.2f,
    R_ARC_TO, 5.72f, 5.72f, 0, 0, 1, 0.43f, -1.09f, LINE_TO, 4.48f, 6.58f, R_CUBIC_TO, -0.31f, 0.5f, -0.55f, 1.04f, -0.72f, 1.62f, ARC_TO, 6.12f, 6.12f, 0, 0,
    0, 3.5f, 10, R_ARC_TO, 6.36f, 6.36f, 0, 0, 0, 1.92f, 4.58f, R_LINE_TO, -1.06f, 1.06f, R_ARC_TO, 7.89f, 7.89f, 0, 0, 1, -1.73f, -2.53f, ARC_TO, 7.75f, 7.75f,
    0, 0, 1, 2, 10, R_ARC_TO, 7.92f, 7.92f, 0, 0, 1, 1.38f, -4.5f, LINE_TO, 1.88f, 4, R_LINE_TO, 1.06f, -1.06f, R_LINE_TO, 14.12f, 14.13f, CLOSE, R_MOVE_TO,
    0.63f, -3.62f, R_LINE_TO, -1.1f, -1.08f, R_CUBIC_TO, 0.31f, -0.5f, 0.55f, -1.04f, 0.72f, -1.62f, ARC_TO, 6.12f, 6.12f, 0, 0, 0, 16.5f, 10, R_ARC_TO, 6.36f,
    6.36f, 0, 0, 0, -1.92f, -4.58f, R_LINE_TO, 1.06f, -1.06f, R_ARC_TO, 7.89f, 7.89f, 0, 0, 1, 1.73f, 2.53f, ARC_TO, 7.75f, 7.75f, 0, 0, 1, 18, 10, R_CUBIC_TO,
    0, 0.83f, -0.12f, 1.63f, -0.35f, 2.4f, R_ARC_TO, 7.51f, 7.51f, 0, 0, 1, -1.02f, 2.11f, CLOSE, R_MOVE_TO, -2.19f, -2.19f, R_LINE_TO, -1.14f, -1.14f,
    R_CUBIC_TO, 0.07f, -0.19f, 0.12f, -0.39f, 0.16f, -0.57f, R_CUBIC_TO, 0.04f, -0.19f, 0.05f, -0.39f, 0.05f, -0.59f, R_CUBIC_TO, 0, -0.48f, -0.09f, -0.94f,
    -0.27f, -1.36f, R_ARC_TO, 3.6f, 3.6f, 0, 0, 0, -0.75f, -1.12f, R_LINE_TO, 1.04f, -1.04f, ARC_TO, 4.86f, 4.86f, 0, 0, 1, 15, 10, R_CUBIC_TO, 0, 0.42f,
    -0.05f, 0.82f, -0.14f, 1.21f, R_CUBIC_TO, -0.09f, 0.39f, -0.23f, 0.76f, -0.42f, 1.11f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(
    kSensorsOffChromeRefreshRepList, kSensorsOffChromeRefreshIcon, { kSensorsOffChromeRefreshPath, std::size(kSensorsOffChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kSerialPortPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 22, 9, V_LINE_TO, 7, R_H_LINE_TO, -2, V_LINE_TO, 5, R_CUBIC_TO, 0, -1.1f, -0.9f, -2,
    -2, -2, H_LINE_TO, 4, R_CUBIC_TO, -1.1f, 0, -2, 0.9f, -2, 2, R_V_LINE_TO, 14, R_CUBIC_TO, 0, 1.1f, 0.9f, 2, 2, 2, R_H_LINE_TO, 14, R_CUBIC_TO, 1.1f, 0, 2,
    -0.9f, 2, -2, R_V_LINE_TO, -2, R_H_LINE_TO, 2, R_V_LINE_TO, -2, R_H_LINE_TO, -2, R_V_LINE_TO, -2, R_H_LINE_TO, 2, R_V_LINE_TO, -2, R_H_LINE_TO, -2,
    V_LINE_TO, 9, R_H_LINE_TO, 2, CLOSE, R_MOVE_TO, -4, 10, H_LINE_TO, 4, V_LINE_TO, 5, R_H_LINE_TO, 14, R_V_LINE_TO, 14, CLOSE, MOVE_TO, 6, 13, R_H_LINE_TO, 5,
    R_V_LINE_TO, 4, H_LINE_TO, 6, CLOSE, R_MOVE_TO, 6, -6, R_H_LINE_TO, 4, R_V_LINE_TO, 3, R_H_LINE_TO, -4, CLOSE, MOVE_TO, 6, 7, R_H_LINE_TO, 5, R_V_LINE_TO,
    5, H_LINE_TO, 6, CLOSE, R_MOVE_TO, 6, 4, R_H_LINE_TO, 4, R_V_LINE_TO, 6, R_H_LINE_TO, -4, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kSerialPortRepList, kSerialPortIcon, { kSerialPortPath, std::size(kSerialPortPath) })
VECTOR_ICON_REP_TEMPLATE(kSerialPortChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 3.5f, 17, R_CUBIC_TO, -0.4f, 0, -0.75f, -0.15f,
    -1.05f, -0.45f, R_CUBIC_TO, -0.3f, -0.3f, -0.45f, -0.65f, -0.45f, -1.05f, R_V_LINE_TO, -11, R_CUBIC_TO, 0, -0.41f, 0.15f, -0.77f, 0.45f, -1.06f, ARC_TO,
    1.45f, 1.45f, 0, 0, 1, 3.5f, 3, R_H_LINE_TO, 11, R_CUBIC_TO, 0.4f, 0, 0.75f, 0.15f, 1.05f, 0.44f, R_CUBIC_TO, 0.3f, 0.29f, 0.45f, 0.65f, 0.45f, 1.06f,
    V_LINE_TO, 6, R_H_LINE_TO, 2, R_V_LINE_TO, 1.5f, R_H_LINE_TO, -2, R_V_LINE_TO, 1.75f, R_H_LINE_TO, 2, R_V_LINE_TO, 1.5f, R_H_LINE_TO, -2, R_V_LINE_TO,
    1.75f, R_H_LINE_TO, 2, V_LINE_TO, 14, R_H_LINE_TO, -2, R_V_LINE_TO, 1.49f, R_CUBIC_TO, 0, 0.41f, -0.15f, 0.77f, -0.45f, 1.06f, R_CUBIC_TO, -0.3f, 0.3f,
    -0.65f, 0.45f, -1.05f, 0.45f, CLOSE, R_MOVE_TO, 0, -1.5f, R_H_LINE_TO, 11, R_V_LINE_TO, -11, R_H_LINE_TO, -11, CLOSE, MOVE_TO, 5, 14, R_H_LINE_TO, 4,
    R_V_LINE_TO, -3, H_LINE_TO, 5, CLOSE, R_MOVE_TO, 5, -6, R_H_LINE_TO, 3, V_LINE_TO, 6, R_H_LINE_TO, -3, CLOSE, R_MOVE_TO, -5, 2, R_H_LINE_TO, 4, V_LINE_TO,
    6, H_LINE_TO, 5, CLOSE, R_MOVE_TO, 5, 4, R_H_LINE_TO, 3, V_LINE_TO, 9, R_H_LINE_TO, -3, CLOSE, MOVE_TO, 3.5f, 4.5f, R_V_LINE_TO, 11, CLOSE)
VECTOR_ICON_TEMPLATE_CC(
    kSerialPortChromeRefreshRepList, kSerialPortChromeRefreshIcon, { kSerialPortChromeRefreshPath, std::size(kSerialPortChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kSerialPortOffChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 16.73f, 18.83f, LINE_TO, 1.17f, 3.27f, LINE_TO,
    2.23f, 2.23f, R_LINE_TO, 15.54f, 15.54f, CLOSE, MOVE_TO, 5.13f, 3, R_H_LINE_TO, 9.37f, R_CUBIC_TO, 0.42f, 0, 0.78f, 0.15f, 1.07f, 0.45f, R_CUBIC_TO, 0.29f,
    0.3f, 0.44f, 0.65f, 0.44f, 1.06f, V_LINE_TO, 6, R_H_LINE_TO, 2, R_V_LINE_TO, 1.5f, R_H_LINE_TO, -2, R_V_LINE_TO, 1.75f, R_H_LINE_TO, 2, R_V_LINE_TO, 1.5f,
    R_H_LINE_TO, -2, R_V_LINE_TO, 1.75f, R_H_LINE_TO, 2, V_LINE_TO, 14, R_H_LINE_TO, -1.87f, LINE_TO, 14.5f, 12.38f, V_LINE_TO, 4.5f, H_LINE_TO, 6.63f, CLOSE,
    MOVE_TO, 9, 6.88f, LINE_TO, 8.13f, 6, H_LINE_TO, 9, CLOSE, MOVE_TO, 10.13f, 8, LINE_TO, 10, 7.88f, V_LINE_TO, 6, R_H_LINE_TO, 3, R_V_LINE_TO, 2, CLOSE,
    MOVE_TO, 13, 10.88f, LINE_TO, 11.13f, 9, H_LINE_TO, 13, CLOSE, R_MOVE_TO, -4, 0.25f, CLOSE, R_MOVE_TO, 1.69f, -2.54f, CLOSE, MOVE_TO, 5, 14, R_V_LINE_TO,
    -3, R_H_LINE_TO, 4, R_V_LINE_TO, 3, CLOSE, MOVE_TO, 3.13f, 3.13f, LINE_TO, 4.5f, 4.5f, R_H_LINE_TO, -1, R_V_LINE_TO, 11, R_H_LINE_TO, 11.02f, R_V_LINE_TO,
    -0.98f, LINE_TO, 16, 16, R_ARC_TO, 1.81f, 1.81f, 0, 0, 1, -0.61f, 0.7f, R_CUBIC_TO, -0.28f, 0.2f, -0.58f, 0.3f, -0.89f, 0.3f, R_H_LINE_TO, -11, R_CUBIC_TO,
    -0.4f, 0, -0.75f, -0.15f, -1.05f, -0.45f, R_CUBIC_TO, -0.3f, -0.3f, -0.45f, -0.65f, -0.45f, -1.05f, R_V_LINE_TO, -11, R_CUBIC_TO, 0, -0.32f, 0.11f, -0.59f,
    0.34f, -0.84f, R_CUBIC_TO, 0.23f, -0.25f, 0.49f, -0.43f, 0.78f, -0.53f, CLOSE, MOVE_TO, 10, 10, R_LINE_TO, 3.33f, 3.33f, V_LINE_TO, 14, H_LINE_TO, 10,
    CLOSE, MOVE_TO, 6, 6, R_LINE_TO, 3.29f, 3.29f, V_LINE_TO, 10, H_LINE_TO, 5, V_LINE_TO, 6, CLOSE)
VECTOR_ICON_TEMPLATE_CC(
    kSerialPortOffChromeRefreshRepList, kSerialPortOffChromeRefreshIcon, { kSerialPortOffChromeRefreshPath, std::size(kSerialPortOffChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kSettingsPath, MOVE_TO, 38.86f, 25.95f, R_CUBIC_TO, 0.08f, -0.64f, 0.14f, -1.29f, 0.14f, -1.95f, R_CUBIC_TO, 0, -0.66f, -0.06f, -1.31f,
    -0.14f, -1.95f, R_LINE_TO, 4.23f, -3.31f, R_CUBIC_TO, 0.38f, -0.3f, 0.49f, -0.84f, 0.24f, -1.28f, R_LINE_TO, -4, -6.93f, R_CUBIC_TO, -0.25f, -0.43f, -0.77f,
    -0.61f, -1.22f, -0.43f, R_LINE_TO, -4.98f, 2.01f, R_CUBIC_TO, -1.03f, -0.79f, -2.16f, -1.46f, -3.38f, -1.97f, LINE_TO, 29, 4.84f, R_CUBIC_TO, -0.09f,
    -0.47f, -0.5f, -0.84f, -1, -0.84f, R_H_LINE_TO, -8, R_CUBIC_TO, -0.5f, 0, -0.91f, 0.37f, -0.99f, 0.84f, R_LINE_TO, -0.75f, 5.3f, R_CUBIC_TO, -1.22f, 0.51f,
    -2.35f, 1.17f, -3.38f, 1.97f, LINE_TO, 9.9f, 10.1f, R_CUBIC_TO, -0.45f, -0.17f, -0.97f, 0, -1.22f, 0.43f, R_LINE_TO, -4, 6.93f, R_CUBIC_TO, -0.25f, 0.43f,
    -0.14f, 0.97f, 0.24f, 1.28f, R_LINE_TO, 4.22f, 3.31f, CUBIC_TO, 9.06f, 22.69f, 9, 23.34f, 9, 24, R_CUBIC_TO, 0, 0.66f, 0.06f, 1.31f, 0.14f, 1.95f,
    R_LINE_TO, -4.22f, 3.31f, R_CUBIC_TO, -0.38f, 0.3f, -0.49f, 0.84f, -0.24f, 1.28f, R_LINE_TO, 4, 6.93f, R_CUBIC_TO, 0.25f, 0.43f, 0.77f, 0.61f, 1.22f, 0.43f,
    R_LINE_TO, 4.98f, -2.01f, R_CUBIC_TO, 1.03f, 0.79f, 2.16f, 1.46f, 3.38f, 1.97f, R_LINE_TO, 0.75f, 5.3f, R_CUBIC_TO, 0.08f, 0.47f, 0.49f, 0.84f, 0.99f,
    0.84f, R_H_LINE_TO, 8, R_CUBIC_TO, 0.5f, 0, 0.91f, -0.37f, 0.99f, -0.84f, R_LINE_TO, 0.75f, -5.3f, R_CUBIC_TO, 1.22f, -0.51f, 2.35f, -1.17f, 3.38f, -1.97f,
    R_LINE_TO, 4.98f, 2.01f, R_CUBIC_TO, 0.45f, 0.17f, 0.97f, 0, 1.22f, -0.43f, R_LINE_TO, 4, -6.93f, R_CUBIC_TO, 0.25f, -0.43f, 0.14f, -0.97f, -0.24f, -1.28f,
    R_LINE_TO, -4.22f, -3.31f, CLOSE, MOVE_TO, 24, 31, R_CUBIC_TO, -3.87f, 0, -7, -3.13f, -7, -7, R_CUBIC_TO, 0, -3.87f, 3.13f, -7, 7, -7, R_CUBIC_TO, 3.87f, 0,
    7, 3.13f, 7, 7, R_CUBIC_TO, 0, 3.87f, -3.13f, 7, -7, 7, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kSettings16Path, CANVAS_DIMENSIONS, 16, MOVE_TO, 12.58f, 8.59f, CUBIC_TO, 12.61f, 8.4f, 12.63f, 8.2f, 12.63f, 8, CUBIC_TO, 12.63f,
    7.8f, 12.61f, 7.6f, 12.58f, 7.41f, LINE_TO, 13.89f, 6.42f, CUBIC_TO, 14, 6.33f, 14.03f, 6.17f, 13.96f, 6.04f, LINE_TO, 12.73f, 3.96f, CUBIC_TO, 12.65f,
    3.83f, 12.49f, 3.78f, 12.35f, 3.83f, LINE_TO, 10.81f, 4.43f, CUBIC_TO, 10.49f, 4.19f, 10.15f, 3.99f, 9.77f, 3.84f, LINE_TO, 9.54f, 2.25f, CUBIC_TO, 9.52f,
    2.11f, 9.39f, 2, 9.24f, 2, LINE_TO, 6.77f, 2, CUBIC_TO, 6.61f, 2, 6.48f, 2.11f, 6.47f, 2.25f, LINE_TO, 6.23f, 3.84f, CUBIC_TO, 5.85f, 3.99f, 5.51f, 4.2f,
    5.19f, 4.43f, LINE_TO, 3.65f, 3.83f, CUBIC_TO, 3.51f, 3.78f, 3.35f, 3.83f, 3.28f, 3.96f, LINE_TO, 2.04f, 6.04f, CUBIC_TO, 1.96f, 6.17f, 2, 6.33f, 2.12f,
    6.42f, LINE_TO, 3.42f, 7.41f, CUBIC_TO, 3.39f, 7.6f, 3.38f, 7.8f, 3.38f, 8, CUBIC_TO, 3.38f, 8.2f, 3.39f, 8.4f, 3.42f, 8.59f, LINE_TO, 2.12f, 9.58f,
    CUBIC_TO, 2, 9.67f, 1.97f, 9.83f, 2.04f, 9.96f, LINE_TO, 3.28f, 12.04f, CUBIC_TO, 3.35f, 12.17f, 3.52f, 12.22f, 3.65f, 12.17f, LINE_TO, 5.19f, 11.57f,
    CUBIC_TO, 5.51f, 11.81f, 5.85f, 12.01f, 6.23f, 12.16f, LINE_TO, 6.47f, 13.75f, CUBIC_TO, 6.48f, 13.89f, 6.61f, 14, 6.77f, 14, LINE_TO, 9.24f, 14, CUBIC_TO,
    9.39f, 14, 9.52f, 13.89f, 9.54f, 13.75f, LINE_TO, 9.77f, 12.16f, CUBIC_TO, 10.15f, 12.01f, 10.49f, 11.8f, 10.81f, 11.57f, LINE_TO, 12.35f, 12.17f, CUBIC_TO,
    12.49f, 12.22f, 12.65f, 12.17f, 12.73f, 12.04f, LINE_TO, 13.96f, 9.96f, CUBIC_TO, 14.03f, 9.83f, 14, 9.67f, 13.89f, 9.58f, LINE_TO, 12.58f, 8.59f, CLOSE,
    MOVE_TO, 8, 10, CUBIC_TO, 6.9f, 10, 6, 9.1f, 6, 8, CUBIC_TO, 6, 6.9f, 6.9f, 6, 8, 6, CUBIC_TO, 9.1f, 6, 10, 6.9f, 10, 8, CUBIC_TO, 10, 9.1f, 9.1f, 10, 8,
    10, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kSettingsRepList, kSettingsIcon, { kSettingsPath, std::size(kSettingsPath) }, { kSettings16Path, std::size(kSettings16Path) })
VECTOR_ICON_REP_TEMPLATE(kSettingsChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, R_MOVE_TO, 8.4f, 18, R_LINE_TO, -0.46f, -2.37f, R_ARC_TO, 7.16f,
    7.16f, 0, 0, 1, -0.93f, -0.44f, R_CUBIC_TO, -0.3f, -0.17f, -0.58f, -0.36f, -0.84f, -0.58f, R_LINE_TO, -2.29f, 0.77f, R_LINE_TO, -1.6f, -2.77f, R_LINE_TO,
    1.81f, -1.58f, R_ARC_TO, 6.99f, 6.99f, 0, 0, 1, -0.06f, -0.5f, R_ARC_TO, 7.33f, 7.33f, 0, 0, 1, 0, -1.04f, R_ARC_TO, 6.99f, 6.99f, 0, 0, 1, 0.06f, -0.5f,
    LINE_TO, 2.27f, 7.4f, R_LINE_TO, 1.61f, -2.77f, R_LINE_TO, 2.29f, 0.77f, R_CUBIC_TO, 0.26f, -0.22f, 0.54f, -0.41f, 0.84f, -0.58f, R_CUBIC_TO, 0.3f, -0.17f,
    0.61f, -0.31f, 0.93f, -0.44f, LINE_TO, 8.4f, 2, R_H_LINE_TO, 3.21f, R_LINE_TO, 0.46f, 2.38f, R_CUBIC_TO, 0.32f, 0.13f, 0.63f, 0.27f, 0.93f, 0.44f,
    R_CUBIC_TO, 0.3f, 0.17f, 0.58f, 0.36f, 0.84f, 0.58f, R_LINE_TO, 2.29f, -0.77f, R_LINE_TO, 1.61f, 2.77f, R_LINE_TO, -1.81f, 1.59f, R_CUBIC_TO, 0.03f, 0.17f,
    0.05f, 0.33f, 0.06f, 0.5f, R_ARC_TO, 7.33f, 7.33f, 0, 0, 1, 0, 1.04f, R_ARC_TO, 6.99f, 6.99f, 0, 0, 1, -0.06f, 0.5f, R_LINE_TO, 1.81f, 1.59f, R_LINE_TO,
    -1.6f, 2.77f, R_LINE_TO, -2.29f, -0.77f, R_ARC_TO, 5.23f, 5.23f, 0, 0, 1, -0.84f, 0.58f, R_ARC_TO, 7.16f, 7.16f, 0, 0, 1, -0.92f, 0.44f, LINE_TO, 11.6f, 18,
    CLOSE, R_MOVE_TO, 1.23f, -1.5f, R_H_LINE_TO, 0.75f, R_LINE_TO, 0.4f, -2.06f, R_ARC_TO, 4.59f, 4.59f, 0, 0, 0, 1.48f, -0.54f, R_ARC_TO, 4.31f, 4.31f, 0, 0,
    0, 1.19f, -1, R_LINE_TO, 2, 0.67f, R_LINE_TO, 0.37f, -0.63f, R_LINE_TO, -1.58f, -1.39f, R_CUBIC_TO, 0.08f, -0.24f, 0.15f, -0.48f, 0.2f, -0.74f, R_CUBIC_TO,
    0.05f, -0.25f, 0.07f, -0.52f, 0.07f, -0.8f, R_CUBIC_TO, 0, -0.28f, -0.02f, -0.55f, -0.07f, -0.8f, R_ARC_TO, 5.05f, 5.05f, 0, 0, 0, -0.2f, -0.74f, R_LINE_TO,
    1.58f, -1.39f, R_LINE_TO, -0.37f, -0.62f, R_LINE_TO, -2, 0.67f, R_ARC_TO, 4.31f, 4.31f, 0, 0, 0, -1.19f, -1, R_ARC_TO, 4.59f, 4.59f, 0, 0, 0, -1.48f,
    -0.54f, LINE_TO, 10.38f, 3.5f, R_H_LINE_TO, -0.75f, LINE_TO, 9.23f, 5.56f, R_ARC_TO, 4.59f, 4.59f, 0, 0, 0, -1.48f, 0.54f, R_ARC_TO, 4.31f, 4.31f, 0, 0, 0,
    -1.19f, 1, R_LINE_TO, -2, -0.67f, R_LINE_TO, -0.37f, 0.63f, LINE_TO, 5.77f, 8.46f, R_ARC_TO, 5.05f, 5.05f, 0, 0, 0, -0.2f, 0.74f, R_CUBIC_TO, -0.05f, 0.25f,
    -0.07f, 0.52f, -0.07f, 0.8f, R_CUBIC_TO, 0, 0.28f, 0.02f, 0.55f, 0.07f, 0.8f, R_CUBIC_TO, 0.05f, 0.26f, 0.11f, 0.51f, 0.2f, 0.74f, R_LINE_TO, -1.58f, 1.4f,
    R_LINE_TO, 0.38f, 0.62f, R_LINE_TO, 2, -0.67f, R_CUBIC_TO, 0.33f, 0.4f, 0.73f, 0.74f, 1.19f, 1, R_ARC_TO, 4.59f, 4.59f, 0, 0, 0, 1.48f, 0.54f, CLOSE,
    MOVE_TO, 10, 13, R_CUBIC_TO, 0.83f, 0, 1.54f, -0.29f, 2.13f, -0.87f, ARC_TO, 2.9f, 2.9f, 0, 0, 0, 13, 10, R_CUBIC_TO, 0, -0.83f, -0.29f, -1.54f, -0.87f,
    -2.12f, ARC_TO, 2.9f, 2.9f, 0, 0, 0, 10, 7, R_CUBIC_TO, -0.83f, 0, -1.54f, 0.29f, -2.12f, 0.88f, ARC_TO, 2.9f, 2.9f, 0, 0, 0, 7, 10, R_CUBIC_TO, 0, 0.83f,
    0.29f, 1.54f, 0.88f, 2.13f, ARC_TO, 2.9f, 2.9f, 0, 0, 0, 10, 13, CLOSE, R_MOVE_TO, 0, -3, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kSettingsChromeRefresh16Path, CANVAS_DIMENSIONS, 16, FILL_RULE_NONZERO, R_MOVE_TO, 6.6f, 14.54f, R_LINE_TO, -0.37f, -1.94f, R_CUBIC_TO,
    -0.23f, -0.09f, -0.46f, -0.2f, -0.68f, -0.32f, R_ARC_TO, 3.78f, 3.78f, 0, 0, 1, -0.62f, -0.43f, R_LINE_TO, -1.87f, 0.64f, R_LINE_TO, -1.4f, -2.43f,
    R_LINE_TO, 1.48f, -1.29f, R_ARC_TO, 6.3f, 6.3f, 0, 0, 1, -0.05f, -0.37f, ARC_TO, 4.13f, 4.13f, 0, 0, 1, 3.06f, 8, R_CUBIC_TO, 0, -0.13f, 0.01f, -0.26f,
    0.02f, -0.39f, R_CUBIC_TO, 0.01f, -0.12f, 0.03f, -0.24f, 0.05f, -0.37f, LINE_TO, 1.64f, 5.96f, R_LINE_TO, 1.4f, -2.43f, R_LINE_TO, 1.88f, 0.63f, R_CUBIC_TO,
    0.2f, -0.16f, 0.4f, -0.3f, 0.62f, -0.43f, R_CUBIC_TO, 0.22f, -0.12f, 0.45f, -0.23f, 0.68f, -0.32f, R_LINE_TO, 0.38f, -1.95f, R_H_LINE_TO, 2.8f, R_LINE_TO,
    0.38f, 1.95f, R_CUBIC_TO, 0.24f, 0.09f, 0.46f, 0.2f, 0.68f, 0.32f, R_CUBIC_TO, 0.22f, 0.12f, 0.43f, 0.26f, 0.63f, 0.43f, R_LINE_TO, 1.88f, -0.63f,
    R_LINE_TO, 1.4f, 2.43f, R_LINE_TO, -1.49f, 1.29f, R_ARC_TO, 4.15f, 4.15f, 0, 0, 1, 0.06f, 0.75f, R_ARC_TO, 4.15f, 4.15f, 0, 0, 1, -0.06f, 0.75f, R_LINE_TO,
    1.49f, 1.29f, R_LINE_TO, -1.41f, 2.43f, R_LINE_TO, -1.88f, -0.64f, R_ARC_TO, 4.07f, 4.07f, 0, 0, 1, -0.62f, 0.43f, R_ARC_TO, 5.2f, 5.2f, 0, 0, 1, -0.68f,
    0.32f, R_LINE_TO, -0.37f, 1.95f, CLOSE, R_MOVE_TO, 1.14f, -1.38f, R_H_LINE_TO, 0.51f, R_LINE_TO, 0.32f, -1.64f, R_ARC_TO, 3.73f, 3.73f, 0, 0, 0, 1.2f,
    -0.44f, R_ARC_TO, 3.28f, 3.28f, 0, 0, 0, 0.96f, -0.82f, R_LINE_TO, 1.59f, 0.53f, R_LINE_TO, 0.25f, -0.43f, R_LINE_TO, -1.25f, -1.11f, R_CUBIC_TO, 0.07f,
    -0.19f, 0.12f, -0.39f, 0.16f, -0.6f, R_CUBIC_TO, 0.04f, -0.21f, 0.06f, -0.42f, 0.06f, -0.65f, R_CUBIC_TO, 0, -0.23f, -0.02f, -0.44f, -0.06f, -0.65f,
    R_CUBIC_TO, -0.04f, -0.21f, -0.09f, -0.41f, -0.16f, -0.61f, R_LINE_TO, 1.26f, -1.11f, R_LINE_TO, -0.26f, -0.42f, R_LINE_TO, -1.59f, 0.53f, R_ARC_TO, 3.4f,
    3.4f, 0, 0, 0, -0.96f, -0.82f, R_ARC_TO, 3.72f, 3.72f, 0, 0, 0, -1.2f, -0.44f, R_LINE_TO, -0.32f, -1.64f, R_H_LINE_TO, -0.52f, LINE_TO, 7.43f, 4.48f,
    R_ARC_TO, 3.76f, 3.76f, 0, 0, 0, -1.21f, 0.44f, R_ARC_TO, 3.42f, 3.42f, 0, 0, 0, -0.96f, 0.82f, R_LINE_TO, -1.59f, -0.53f, R_LINE_TO, -0.26f, 0.43f,
    R_LINE_TO, 1.25f, 1.11f, R_ARC_TO, 4.45f, 4.45f, 0, 0, 0, -0.16f, 0.61f, R_CUBIC_TO, -0.04f, 0.21f, -0.06f, 0.43f, -0.06f, 0.65f, R_CUBIC_TO, 0, 0.23f,
    0.02f, 0.44f, 0.06f, 0.65f, R_CUBIC_TO, 0.04f, 0.21f, 0.09f, 0.41f, 0.16f, 0.61f, R_LINE_TO, -1.25f, 1.1f, R_LINE_TO, 0.26f, 0.43f, R_LINE_TO, 1.59f,
    -0.53f, R_CUBIC_TO, 0.27f, 0.33f, 0.59f, 0.6f, 0.97f, 0.81f, R_CUBIC_TO, 0.38f, 0.22f, 0.78f, 0.36f, 1.2f, 0.44f, CLOSE, R_MOVE_TO, 0.25f, -2.75f, R_ARC_TO,
    2.3f, 2.3f, 0, 0, 0, 1.7f, -0.7f, ARC_TO, 2.3f, 2.3f, 0, 0, 0, 10.39f, 8, R_ARC_TO, 2.3f, 2.3f, 0, 0, 0, -0.7f, -1.7f, R_ARC_TO, 2.3f, 2.3f, 0, 0, 0, -1.7f,
    -0.7f, R_CUBIC_TO, -0.66f, 0, -1.23f, 0.23f, -1.7f, 0.7f, ARC_TO, 2.3f, 2.3f, 0, 0, 0, 5.59f, 8, R_ARC_TO, 2.3f, 2.3f, 0, 0, 0, 0.7f, 1.7f, R_CUBIC_TO,
    0.47f, 0.47f, 1.03f, 0.7f, 1.7f, 0.7f, CLOSE, MOVE_TO, 8, 8, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kSettingsChromeRefreshRepList, kSettingsChromeRefreshIcon, { kSettingsChromeRefreshPath, std::size(kSettingsChromeRefreshPath) },
    { kSettingsChromeRefresh16Path, std::size(kSettingsChromeRefresh16Path) })
VECTOR_ICON_REP_TEMPLATE(kSettingsOutlinePath, CANVAS_DIMENSIONS, 20, MOVE_TO, 11.48f, 18, H_LINE_TO, 8.52f, R_CUBIC_TO, -0.59f, 0, -1.09f, -0.42f, -1.16f,
    -0.99f, R_LINE_TO, -0.22f, -1.48f, R_CUBIC_TO, -0.22f, -0.11f, -0.42f, -0.23f, -0.63f, -0.36f, R_LINE_TO, -1.44f, 0.56f, R_CUBIC_TO, -0.56f, 0.2f, -1.18f,
    -0.02f, -1.45f, -0.51f, R_LINE_TO, -1.46f, -2.48f, R_CUBIC_TO, -0.28f, -0.52f, -0.16f, -1.12f, 0.29f, -1.47f, R_LINE_TO, 1.22f, -0.93f, R_CUBIC_TO, -0.01f,
    -0.12f, -0.02f, -0.23f, -0.02f, -0.36f, R_CUBIC_TO, 0, -0.12f, 0.01f, -0.24f, 0.02f, -0.36f, R_LINE_TO, -1.22f, -0.93f, R_CUBIC_TO, -0.47f, -0.35f, -0.59f,
    -0.98f, -0.3f, -1.47f, R_LINE_TO, 1.48f, -2.49f, R_CUBIC_TO, 0.27f, -0.48f, 0.89f, -0.7f, 1.43f, -0.49f, R_LINE_TO, 1.45f, 0.57f, R_CUBIC_TO, 0.21f, -0.13f,
    0.42f, -0.25f, 0.62f, -0.36f, R_LINE_TO, 0.22f, -1.49f, CUBIC_TO, 7.43f, 2.43f, 7.93f, 2, 8.51f, 2, R_H_LINE_TO, 2.96f, R_CUBIC_TO, 0.59f, 0, 1.09f, 0.42f,
    1.16f, 0.99f, R_LINE_TO, 0.22f, 1.48f, R_CUBIC_TO, 0.22f, 0.11f, 0.42f, 0.23f, 0.63f, 0.36f, R_LINE_TO, 1.44f, -0.56f, R_CUBIC_TO, 0.57f, -0.2f, 1.18f,
    0.02f, 1.46f, 0.51f, R_LINE_TO, 1.47f, 2.48f, R_CUBIC_TO, 0.29f, 0.52f, 0.16f, 1.12f, -0.29f, 1.47f, R_LINE_TO, -1.22f, 0.93f, R_CUBIC_TO, 0.01f, 0.12f,
    0.02f, 0.23f, 0.02f, 0.36f, R_CUBIC_TO, 0, 0.12f, -0.01f, 0.24f, -0.02f, 0.36f, R_LINE_TO, 1.22f, 0.93f, R_CUBIC_TO, 0.45f, 0.35f, 0.58f, 0.96f, 0.3f,
    1.45f, R_LINE_TO, -1.49f, 2.51f, R_CUBIC_TO, -0.27f, 0.48f, -0.89f, 0.7f, -1.44f, 0.49f, R_LINE_TO, -1.44f, -0.56f, R_CUBIC_TO, -0.21f, 0.13f, -0.42f,
    0.25f, -0.62f, 0.36f, R_LINE_TO, -0.22f, 1.49f, CUBIC_TO, 12.57f, 17.58f, 12.07f, 18, 11.48f, 18, CLOSE, R_MOVE_TO, -2.53f, -2, R_H_LINE_TO, 2.11f,
    R_LINE_TO, 0.28f, -1.85f, R_LINE_TO, 0.41f, -0.16f, R_CUBIC_TO, 0.34f, -0.13f, 0.67f, -0.32f, 1.03f, -0.57f, R_LINE_TO, 0.34f, -0.25f, R_LINE_TO, 1.82f,
    0.7f, LINE_TO, 16, 12.12f, R_LINE_TO, -1.55f, -1.15f, R_LINE_TO, 0.05f, -0.41f, R_CUBIC_TO, 0.02f, -0.19f, 0.05f, -0.37f, 0.05f, -0.57f, R_CUBIC_TO, 0,
    -0.2f, -0.02f, -0.39f, -0.05f, -0.57f, R_LINE_TO, -0.05f, -0.41f, LINE_TO, 16, 7.88f, R_LINE_TO, -1.06f, -1.75f, R_LINE_TO, -1.83f, 0.7f, R_LINE_TO, -0.34f,
    -0.25f, R_CUBIC_TO, -0.32f, -0.23f, -0.67f, -0.42f, -1.02f, -0.56f, R_LINE_TO, -0.4f, -0.16f, LINE_TO, 11.06f, 4, H_LINE_TO, 8.95f, R_LINE_TO, -0.28f,
    1.85f, R_LINE_TO, -0.41f, 0.15f, R_CUBIC_TO, -0.34f, 0.14f, -0.67f, 0.32f, -1.03f, 0.57f, R_LINE_TO, -0.34f, 0.24f, R_LINE_TO, -1.82f, -0.69f, LINE_TO, 4,
    7.87f, R_LINE_TO, 1.55f, 1.15f, R_LINE_TO, -0.05f, 0.41f, R_CUBIC_TO, -0.02f, 0.19f, -0.05f, 0.39f, -0.05f, 0.57f, R_CUBIC_TO, 0, 0.19f, 0.02f, 0.39f,
    0.05f, 0.57f, R_LINE_TO, 0.05f, 0.41f, LINE_TO, 4, 12.12f, R_LINE_TO, 1.06f, 1.75f, R_LINE_TO, 1.83f, -0.7f, R_LINE_TO, 0.34f, 0.25f, R_CUBIC_TO, 0.33f,
    0.24f, 0.66f, 0.42f, 1.02f, 0.56f, R_LINE_TO, 0.41f, 0.16f, LINE_TO, 8.95f, 16, CLOSE, MOVE_TO, 10, 12.5f, R_CUBIC_TO, 1.38f, 0, 2.5f, -1.12f, 2.5f, -2.5f,
    R_CUBIC_TO, 0, -1.38f, -1.12f, -2.5f, -2.5f, -2.5f, R_CUBIC_TO, -1.38f, 0, -2.5f, 1.12f, -2.5f, 2.5f, R_CUBIC_TO, 0, 1.38f, 1.12f, 2.5f, 2.5f, 2.5f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kSettingsOutlineRepList, kSettingsOutlineIcon, { kSettingsOutlinePath, std::size(kSettingsOutlinePath) })
VECTOR_ICON_REP_TEMPLATE(kShoppingBagPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 18, 6, R_H_LINE_TO, -2, R_CUBIC_TO, 0, -2.21f, -1.79f, -4, -4, -4,
    CUBIC_TO_SHORTHAND, 8, 3.79f, 8, 6, H_LINE_TO, 6, R_CUBIC_TO, -1.1f, 0, -2, 0.9f, -2, 2, R_V_LINE_TO, 12, R_CUBIC_TO, 0, 1.1f, 0.9f, 2, 2, 2, R_H_LINE_TO,
    12, R_CUBIC_TO, 1.1f, 0, 2, -0.9f, 2, -2, V_LINE_TO, 8, R_CUBIC_TO, 0, -1.1f, -0.9f, -2, -2, -2, CLOSE, R_MOVE_TO, -6, -2, R_CUBIC_TO, 1.1f, 0, 2, 0.9f, 2,
    2, R_H_LINE_TO, -4, R_CUBIC_TO, 0, -1.1f, 0.9f, -2, 2, -2, CLOSE, R_MOVE_TO, 6, 16, H_LINE_TO, 6, V_LINE_TO, 8, R_H_LINE_TO, 2, R_V_LINE_TO, 2, R_CUBIC_TO,
    0, 0.55f, 0.45f, 1, 1, 1, R_CUBIC_TO, 0.55f, 0, 1, -0.45f, 1, -1, V_LINE_TO, 8, R_H_LINE_TO, 4, R_V_LINE_TO, 2, R_CUBIC_TO, 0, 0.55f, 0.45f, 1, 1, 1,
    R_CUBIC_TO, 0.55f, 0, 1, -0.45f, 1, -1, V_LINE_TO, 8, R_H_LINE_TO, 2, R_V_LINE_TO, 12, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kShoppingBagRepList, kShoppingBagIcon, { kShoppingBagPath, std::size(kShoppingBagPath) })
VECTOR_ICON_REP_TEMPLATE(kShoppingBagRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 5.49f, 18, R_ARC_TO, 1.44f, 1.44f, 0, 0, 1, -1.05f, -0.44f,
    ARC_TO, 1.44f, 1.44f, 0, 0, 1, 4, 16.5f, V_LINE_TO, 7, R_CUBIC_TO, 0, -0.41f, 0.15f, -0.77f, 0.44f, -1.06f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 5.5f, 5.5f,
    H_LINE_TO, 7, R_V_LINE_TO, -0.33f, R_CUBIC_TO, 0, -0.84f, 0.28f, -1.57f, 0.84f, -2.21f, CUBIC_TO, 8.41f, 2.32f, 9.13f, 2, 10, 2, R_CUBIC_TO, 0.83f, 0,
    1.54f, 0.29f, 2.13f, 0.88f, CUBIC_TO, 12.71f, 3.46f, 13, 4.17f, 13, 5, R_V_LINE_TO, 0.5f, R_H_LINE_TO, 1.5f, R_CUBIC_TO, 0.41f, 0, 0.77f, 0.15f, 1.06f,
    0.44f, R_CUBIC_TO, 0.29f, 0.29f, 0.44f, 0.65f, 0.44f, 1.06f, R_V_LINE_TO, 9.5f, R_CUBIC_TO, 0, 0.41f, -0.15f, 0.77f, -0.44f, 1.06f, ARC_TO, 1.45f, 1.45f, 0,
    0, 1, 14.5f, 18, CLOSE, R_MOVE_TO, 0.01f, -1.5f, R_H_LINE_TO, 9, V_LINE_TO, 7, H_LINE_TO, 13, R_V_LINE_TO, 1.25f, R_CUBIC_TO, 0, 0.21f, -0.07f, 0.39f,
    -0.21f, 0.54f, R_ARC_TO, 0.71f, 0.71f, 0, 0, 1, -0.53f, 0.22f, R_CUBIC_TO, -0.21f, 0, -0.39f, -0.07f, -0.53f, -0.21f, R_ARC_TO, 0.73f, 0.73f, 0, 0, 1,
    -0.22f, -0.53f, V_LINE_TO, 7, R_H_LINE_TO, -3, R_V_LINE_TO, 1.25f, R_CUBIC_TO, 0, 0.21f, -0.07f, 0.39f, -0.21f, 0.54f, ARC_TO, 0.71f, 0.71f, 0, 0, 1, 7.75f,
    9, R_CUBIC_TO, -0.21f, 0, -0.39f, -0.07f, -0.53f, -0.21f, ARC_TO, 0.73f, 0.73f, 0, 0, 1, 7, 8.25f, V_LINE_TO, 7, H_LINE_TO, 5.5f, CLOSE, R_MOVE_TO, 3, -11,
    R_H_LINE_TO, 3, V_LINE_TO, 5, R_CUBIC_TO, 0, -0.41f, -0.15f, -0.77f, -0.44f, -1.06f, ARC_TO, 1.46f, 1.46f, 0, 0, 0, 10, 3.5f, R_CUBIC_TO, -0.41f, 0, -0.77f,
    0.15f, -1.06f, 0.44f, ARC_TO, 1.44f, 1.44f, 0, 0, 0, 8.5f, 5, CLOSE, R_MOVE_TO, -3, 11, V_LINE_TO, 7, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kShoppingBagRefreshRepList, kShoppingBagRefreshIcon, { kShoppingBagRefreshPath, std::size(kShoppingBagRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kShoppingmodePath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 10.42f, 17.56f, ARC_TO, 1.45f, 1.45f, 0, 0, 1, 9.36f, 18,
    R_CUBIC_TO, -0.42f, 0, -0.77f, -0.14f, -1.06f, -0.44f, R_LINE_TO, -5.85f, -5.85f, ARC_TO, 1.42f, 1.42f, 0, 0, 1, 2, 10.65f, R_CUBIC_TO, 0, -0.42f, 0.14f,
    -0.77f, 0.44f, -1.07f, LINE_TO, 9.59f, 2.43f, R_CUBIC_TO, 0.15f, -0.15f, 0.31f, -0.26f, 0.49f, -0.32f, ARC_TO, 1.52f, 1.52f, 0, 0, 1, 10.65f, 2, H_LINE_TO,
    16.5f, R_CUBIC_TO, 0.41f, 0, 0.77f, 0.15f, 1.06f, 0.44f, R_CUBIC_TO, 0.29f, 0.29f, 0.44f, 0.65f, 0.44f, 1.06f, R_V_LINE_TO, 5.88f, R_ARC_TO, 1.45f, 1.45f,
    0, 0, 1, -0.44f, 1.04f, CLOSE, MOVE_TO, 14.5f, 6.75f, R_CUBIC_TO, 0.35f, 0, 0.64f, -0.12f, 0.89f, -0.36f, R_CUBIC_TO, 0.24f, -0.25f, 0.36f, -0.54f, 0.36f,
    -0.89f, R_CUBIC_TO, 0, -0.35f, -0.12f, -0.64f, -0.36f, -0.89f, R_ARC_TO, 1.22f, 1.22f, 0, 0, 0, -0.89f, -0.36f, R_CUBIC_TO, -0.35f, 0, -0.64f, 0.12f,
    -0.89f, 0.36f, R_CUBIC_TO, -0.24f, 0.25f, -0.36f, 0.54f, -0.36f, 0.89f, R_CUBIC_TO, 0, 0.35f, 0.12f, 0.64f, 0.36f, 0.89f, R_CUBIC_TO, 0.25f, 0.24f, 0.54f,
    0.36f, 0.89f, 0.36f, CLOSE, MOVE_TO, 9.36f, 16.5f, LINE_TO, 16.5f, 9.38f, V_LINE_TO, 3.5f, R_H_LINE_TO, -5.85f, LINE_TO, 3.5f, 10.65f, CLOSE, MOVE_TO,
    16.48f, 3.58f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kShoppingmodeRepList, kShoppingmodeIcon, { kShoppingmodePath, std::size(kShoppingmodePath) })
VECTOR_ICON_REP_TEMPLATE(kSkipNextPath, CANVAS_DIMENSIONS, 960, MOVE_TO, 660, 720, R_V_LINE_TO, -480, R_H_LINE_TO, 80, R_V_LINE_TO, 480, R_H_LINE_TO, -80,
    CLOSE, R_MOVE_TO, -440, 0, R_V_LINE_TO, -480, R_LINE_TO, 360, 240, R_LINE_TO, -360, 240, CLOSE, R_MOVE_TO, 80, -240, CLOSE, R_MOVE_TO, 0, 90, R_LINE_TO,
    136, -90, R_LINE_TO, -136, -90, R_V_LINE_TO, 180, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kSkipNextRepList, kSkipNextIcon, { kSkipNextPath, std::size(kSkipNextPath) })
VECTOR_ICON_REP_TEMPLATE(kSkipPreviousPath, CANVAS_DIMENSIONS, 960, MOVE_TO, 220, 720, R_V_LINE_TO, -480, R_H_LINE_TO, 80, R_V_LINE_TO, 480, R_H_LINE_TO, -80,
    CLOSE, R_MOVE_TO, 520, 0, LINE_TO, 380, 480, R_LINE_TO, 360, -240, R_V_LINE_TO, 480, CLOSE, R_MOVE_TO, -80, -240, CLOSE, R_MOVE_TO, 0, 90, R_V_LINE_TO,
    -180, R_LINE_TO, -136, 90, R_LINE_TO, 136, 90, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kSkipPreviousRepList, kSkipPreviousIcon, { kSkipPreviousPath, std::size(kSkipPreviousPath) })
VECTOR_ICON_REP_TEMPLATE(kSmartCardReaderPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 2, 18, R_V_LINE_TO, -2.5f, R_CUBIC_TO, 0, -0.42f, 0.15f,
    -0.77f, 0.44f, -1.06f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 3.5f, 14, R_H_LINE_TO, 13, R_CUBIC_TO, 0.41f, 0, 0.77f, 0.15f, 1.06f, 0.44f, R_CUBIC_TO, 0.29f, 0.29f,
    0.44f, 0.65f, 0.44f, 1.06f, V_LINE_TO, 18, CLOSE, R_MOVE_TO, 1.5f, -1.5f, R_H_LINE_TO, 13, R_V_LINE_TO, -1, R_H_LINE_TO, -13, CLOSE, R_MOVE_TO, 1, -3.5f,
    V_LINE_TO, 3.5f, R_CUBIC_TO, 0, -0.46f, 0.14f, -0.82f, 0.41f, -1.09f, CUBIC_TO, 5.18f, 2.14f, 5.54f, 2, 6, 2, R_H_LINE_TO, 8, R_CUBIC_TO, 0.46f, 0, 0.82f,
    0.14f, 1.09f, 0.41f, R_CUBIC_TO, 0.27f, 0.27f, 0.41f, 0.63f, 0.41f, 1.09f, V_LINE_TO, 13, H_LINE_TO, 14, V_LINE_TO, 3.5f, H_LINE_TO, 6, V_LINE_TO, 13,
    CLOSE, MOVE_TO, 7, 11.5f, R_H_LINE_TO, 0.43f, R_CUBIC_TO, 0.55f, 0, 0.99f, -0.27f, 1.32f, -0.82f, R_CUBIC_TO, 0.33f, -0.55f, 0.5f, -1.28f, 0.5f, -2.18f,
    R_CUBIC_TO, 0, -0.9f, -0.16f, -1.62f, -0.5f, -2.17f, R_CUBIC_TO, -0.33f, -0.55f, -0.77f, -0.82f, -1.32f, -0.82f, H_LINE_TO, 7, CLOSE, R_MOVE_TO, 4.5f,
    -1.5f, R_CUBIC_TO, 0.41f, 0, 0.77f, -0.15f, 1.06f, -0.44f, R_CUBIC_TO, 0.29f, -0.3f, 0.44f, -0.65f, 0.44f, -1.06f, R_CUBIC_TO, 0, -0.41f, -0.15f, -0.77f,
    -0.44f, -1.06f, ARC_TO, 1.45f, 1.45f, 0, 0, 0, 11.5f, 7, R_CUBIC_TO, -0.41f, 0, -0.77f, 0.15f, -1.06f, 0.44f, ARC_TO, 1.45f, 1.45f, 0, 0, 0, 10, 8.5f,
    R_CUBIC_TO, 0, 0.41f, 0.15f, 0.77f, 0.44f, 1.06f, R_CUBIC_TO, 0.3f, 0.29f, 0.65f, 0.44f, 1.06f, 0.44f, CLOSE, MOVE_TO, 10, 16.5f, CLOSE, R_MOVE_TO, 0,
    -8.25f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kSmartCardReaderRepList, kSmartCardReaderIcon, { kSmartCardReaderPath, std::size(kSmartCardReaderPath) })
VECTOR_ICON_REP_TEMPLATE(kSmartCardReaderOffPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 14, 1.17f, R_CUBIC_TO, 0.46f, 0, 0.82f, 0.13f, 1.09f,
    0.41f, R_CUBIC_TO, 0.27f, 0.27f, 0.41f, 0.63f, 0.41f, 1.09f, R_V_LINE_TO, 9.51f, R_H_LINE_TO, -0.39f, LINE_TO, 14, 11.06f, V_LINE_TO, 2.67f, H_LINE_TO,
    5.65f, LINE_TO, 4.75f, 1.77f, R_CUBIC_TO, 0.13f, -0.19f, 0.3f, -0.34f, 0.51f, -0.45f, R_CUBIC_TO, 0.22f, -0.1f, 0.46f, -0.16f, 0.74f, -0.16f, CLOSE,
    R_MOVE_TO, -1.98f, 7.91f, R_LINE_TO, -1.91f, -1.94f, R_ARC_TO, 1.56f, 1.56f, 0, 0, 1, 0.54f, -0.7f, R_ARC_TO, 1.38f, 1.38f, 0, 0, 1, 0.86f, -0.28f,
    R_CUBIC_TO, 0.41f, 0, 0.76f, 0.14f, 1.06f, 0.44f, R_CUBIC_TO, 0.29f, 0.29f, 0.44f, 0.65f, 0.44f, 1.06f, R_CUBIC_TO, 0, 0.32f, -0.09f, 0.61f, -0.28f, 0.87f,
    R_ARC_TO, 1.57f, 1.57f, 0, 0, 1, -0.7f, 0.55f, CLOSE, MOVE_TO, 7, 10.67f, R_V_LINE_TO, -4.5f, R_LINE_TO, 2.21f, 2.21f, R_CUBIC_TO, -0.08f, 0.71f, -0.28f,
    1.27f, -0.59f, 1.68f, R_CUBIC_TO, -0.31f, 0.41f, -0.71f, 0.62f, -1.18f, 0.62f, CLOSE, R_MOVE_TO, -3.5f, 5, R_H_LINE_TO, 10.88f, R_LINE_TO, -1, -1,
    H_LINE_TO, 3.5f, CLOSE, R_MOVE_TO, 13.23f, 2.35f, R_LINE_TO, -0.85f, -0.85f, H_LINE_TO, 2, R_V_LINE_TO, -2.5f, R_CUBIC_TO, 0, -0.41f, 0.15f, -0.77f, 0.44f,
    -1.06f, R_ARC_TO, 1.44f, 1.44f, 0, 0, 1, 1.06f, -0.44f, R_H_LINE_TO, 8.38f, LINE_TO, 6, 7.29f, R_V_LINE_TO, 4.88f, H_LINE_TO, 4.5f, V_LINE_TO, 5.79f,
    LINE_TO, 1.15f, 2.44f, R_LINE_TO, 1.06f, -1.06f, R_LINE_TO, 15.59f, 15.58f, CLOSE, R_MOVE_TO, -7.79f, -2.35f, CLOSE, R_MOVE_TO, 0.9f, -8.81f, CLOSE,
    MOVE_TO, 8.44f, 9.73f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kSmartCardReaderOffRepList, kSmartCardReaderOffIcon, { kSmartCardReaderOffPath, std::size(kSmartCardReaderOffPath) })
VECTOR_ICON_REP_TEMPLATE(kSmsPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 20, 2, H_LINE_TO, 4, R_CUBIC_TO, -1.1f, 0, -2, 0.9f, -2, 2, R_V_LINE_TO, 18, R_LINE_TO, 4,
    -4, R_H_LINE_TO, 14, R_CUBIC_TO, 1.1f, 0, 2, -0.9f, 2, -2, V_LINE_TO, 4, R_CUBIC_TO, 0, -1.1f, -0.9f, -2, -2, -2, CLOSE, R_MOVE_TO, 0, 14, H_LINE_TO, 6,
    R_LINE_TO, -2, 2, V_LINE_TO, 4, R_H_LINE_TO, 16, R_V_LINE_TO, 12, CLOSE, MOVE_TO, 7, 9, R_H_LINE_TO, 2, R_V_LINE_TO, 2, H_LINE_TO, 7, CLOSE, R_MOVE_TO, 4,
    0, R_H_LINE_TO, 2, R_V_LINE_TO, 2, R_H_LINE_TO, -2, CLOSE, R_MOVE_TO, 4, 0, R_H_LINE_TO, 2, R_V_LINE_TO, 2, R_H_LINE_TO, -2, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kSmsRepList, kSmsIcon, { kSmsPath, std::size(kSmsPath) })
VECTOR_ICON_REP_TEMPLATE(kStopCirclePath, CANVAS_DIMENSIONS, 960, FILL_RULE_NONZERO, MOVE_TO, 320, 640, R_H_LINE_TO, 320, R_V_LINE_TO, -320, H_LINE_TO, 320,
    R_V_LINE_TO, 320, CLOSE, MOVE_TO, 480, 880, R_QUADRATIC_TO, -83, 0, -156, -31.5f, QUADRATIC_TO_SHORTHAND, 197, 763, R_QUADRATIC_TO, -54, -54, -85.5f, -127,
    QUADRATIC_TO_SHORTHAND, 80, 480, R_QUADRATIC_TO, 0, -83, 31.5f, -156, QUADRATIC_TO_SHORTHAND, 197, 197, R_QUADRATIC_TO, 54, -54, 127, -85.5f,
    QUADRATIC_TO_SHORTHAND, 480, 80, R_QUADRATIC_TO, 83, 0, 156, 31.5f, QUADRATIC_TO_SHORTHAND, 763, 197, R_QUADRATIC_TO, 54, 54, 85.5f, 127,
    QUADRATIC_TO_SHORTHAND, 880, 480, R_QUADRATIC_TO, 0, 83, -31.5f, 156, QUADRATIC_TO_SHORTHAND, 763, 763, R_QUADRATIC_TO, -54, 54, -127, 85.5f,
    QUADRATIC_TO_SHORTHAND, 480, 880, CLOSE, R_MOVE_TO, 0, -80, R_QUADRATIC_TO, 134, 0, 227, -93, R_QUADRATIC_TO, 93, -93, 93, -227, R_QUADRATIC_TO, 0, -134,
    -93, -227, R_QUADRATIC_TO, -93, -93, -227, -93, R_QUADRATIC_TO, -134, 0, -227, 93, R_QUADRATIC_TO, -93, 93, -93, 227, R_QUADRATIC_TO, 0, 134, 93, 227,
    R_QUADRATIC_TO, 93, 93, 227, 93, CLOSE, R_MOVE_TO, 0, -320, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kStopCircleRepList, kStopCircleIcon, { kStopCirclePath, std::size(kStopCirclePath) })
VECTOR_ICON_REP_TEMPLATE(kStorageAccessPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 6.5f, 14.69f, R_ARC_TO, 6.46f, 6.46f, 0, 0, 1, -3.26f, -2.36f,
    ARC_TO, 6.34f, 6.34f, 0, 0, 1, 2, 8.5f, R_CUBIC_TO, 0, -1.8f, 0.63f, -3.34f, 1.9f, -4.61f, CUBIC_TO, 5.16f, 2.63f, 6.7f, 2, 8.5f, 2, R_ARC_TO, 6.34f, 6.34f,
    0, 0, 1, 3.82f, 1.24f, ARC_TO, 6.46f, 6.46f, 0, 0, 1, 14.69f, 6.5f, R_H_LINE_TO, -1.61f, R_ARC_TO, 4.92f, 4.92f, 0, 0, 0, -1.84f, -2.19f, ARC_TO, 4.87f,
    4.87f, 0, 0, 0, 8.5f, 3.5f, R_CUBIC_TO, -1.39f, 0, -2.57f, 0.48f, -3.54f, 1.46f, CUBIC_TO, 3.98f, 5.93f, 3.5f, 7.11f, 3.5f, 8.5f, R_CUBIC_TO, 0, 1, 0.27f,
    1.91f, 0.81f, 2.73f, ARC_TO, 4.97f, 4.97f, 0, 0, 0, 6.5f, 13.06f, CLOSE, MOVE_TO, 9.5f, 18, R_CUBIC_TO, -0.41f, 0, -0.77f, -0.15f, -1.06f, -0.44f, ARC_TO,
    1.44f, 1.44f, 0, 0, 1, 8, 16.5f, R_V_LINE_TO, -7, R_CUBIC_TO, 0, -0.41f, 0.15f, -0.77f, 0.44f, -1.06f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 9.5f, 8, R_H_LINE_TO,
    7, R_CUBIC_TO, 0.41f, 0, 0.77f, 0.15f, 1.06f, 0.44f, R_CUBIC_TO, 0.29f, 0.29f, 0.44f, 0.65f, 0.44f, 1.06f, R_V_LINE_TO, 7, R_CUBIC_TO, 0, 0.41f, -0.15f,
    0.77f, -0.44f, 1.06f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 16.5f, 18, CLOSE, R_MOVE_TO, 0, -1.5f, R_H_LINE_TO, 7, R_V_LINE_TO, -7, R_H_LINE_TO, -7, CLOSE,
    R_MOVE_TO, 0.5f, -1, R_H_LINE_TO, 6, LINE_TO, 14.11f, 13, R_LINE_TO, -1.5f, 1.98f, LINE_TO, 11.5f, 13.5f, CLOSE, R_MOVE_TO, 3, -2.5f, CLOSE, MOVE_TO, 8.29f,
    8.27f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kStorageAccessRepList, kStorageAccessIcon, { kStorageAccessPath, std::size(kStorageAccessPath) })
VECTOR_ICON_REP_TEMPLATE(kStorageAccessOffPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, R_MOVE_TO, 18, 15.88f, R_LINE_TO, -1.5f, -1.5f, V_LINE_TO, 9.5f,
    R_H_LINE_TO, -4.87f, R_LINE_TO, -1.5f, -1.5f, H_LINE_TO, 16.5f, R_CUBIC_TO, 0.41f, 0, 0.77f, 0.15f, 1.06f, 0.44f, R_CUBIC_TO, 0.29f, 0.29f, 0.44f, 0.65f,
    0.44f, 1.06f, CLOSE, MOVE_TO, 13.08f, 6.5f, R_ARC_TO, 4.92f, 4.92f, 0, 0, 0, -1.84f, -2.19f, ARC_TO, 4.87f, 4.87f, 0, 0, 0, 8.5f, 3.5f, R_CUBIC_TO, -0.4f,
    0, -0.79f, 0.05f, -1.18f, 0.14f, R_ARC_TO, 5.1f, 5.1f, 0, 0, 0, -1.12f, 0.44f, LINE_TO, 5.08f, 2.98f, R_ARC_TO, 6.9f, 6.9f, 0, 0, 1, 1.65f, -0.73f, ARC_TO,
    6.26f, 6.26f, 0, 0, 1, 8.5f, 2, R_ARC_TO, 6.34f, 6.34f, 0, 0, 1, 3.82f, 1.24f, ARC_TO, 6.46f, 6.46f, 0, 0, 1, 14.69f, 6.5f, CLOSE, R_MOVE_TO, -1.14f, 7.56f,
    CLOSE, R_MOVE_TO, 4.79f, 4.79f, LINE_TO, 15.88f, 18, H_LINE_TO, 9.5f, R_CUBIC_TO, -0.41f, 0, -0.77f, -0.15f, -1.06f, -0.44f, ARC_TO, 1.44f, 1.44f, 0, 0, 1,
    8, 16.5f, R_V_LINE_TO, -6.37f, LINE_TO, 4.06f, 6.19f, ARC_TO, 4.97f, 4.97f, 0, 0, 0, 3.5f, 8.5f, R_CUBIC_TO, 0, 1, 0.27f, 1.91f, 0.81f, 2.73f, ARC_TO,
    4.97f, 4.97f, 0, 0, 0, 6.5f, 13.06f, R_V_LINE_TO, 1.63f, R_ARC_TO, 6.46f, 6.46f, 0, 0, 1, -3.26f, -2.36f, ARC_TO, 6.34f, 6.34f, 0, 0, 1, 2, 8.5f,
    R_CUBIC_TO, 0, -0.63f, 0.08f, -1.23f, 0.25f, -1.8f, R_ARC_TO, 6.7f, 6.7f, 0, 0, 1, 0.71f, -1.61f, LINE_TO, 1.17f, 3.29f, LINE_TO, 2.23f, 2.23f, R_LINE_TO,
    15.56f, 15.56f, CLOSE, MOVE_TO, 9.04f, 6.54f, CLOSE, R_MOVE_TO, -1.6f, 0.89f, CLOSE, MOVE_TO, 10, 15.5f, R_LINE_TO, 1.48f, -2, R_LINE_TO, 1.27f, 1.29f,
    R_LINE_TO, 0.88f, -1.17f, LINE_TO, 15.5f, 15.5f, CLOSE, R_MOVE_TO, -0.5f, 1, R_H_LINE_TO, 4.88f, LINE_TO, 9.5f, 11.63f, CLOSE, R_MOVE_TO, 4.56f, -4.56f,
    CLOSE)
VECTOR_ICON_TEMPLATE_CC(kStorageAccessOffRepList, kStorageAccessOffIcon, { kStorageAccessOffPath, std::size(kStorageAccessOffPath) })
VECTOR_ICON_REP_TEMPLATE(kSubmenuArrowPath, CANVAS_DIMENSIONS, 16, FLIPS_IN_RTL, MOVE_TO, 3, 16, R_LINE_TO, 11, -8, LINE_TO, 3, 0, R_V_LINE_TO, 16, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kSubmenuArrow8Path, CANVAS_DIMENSIONS, 8, FLIPS_IN_RTL, MOVE_TO, 2, 8, R_LINE_TO, 5, -4, R_LINE_TO, -5, -4, R_V_LINE_TO, 8, CLOSE)
VECTOR_ICON_TEMPLATE_CC(
    kSubmenuArrowRepList, kSubmenuArrowIcon, { kSubmenuArrowPath, std::size(kSubmenuArrowPath) }, { kSubmenuArrow8Path, std::size(kSubmenuArrow8Path) })
VECTOR_ICON_REP_TEMPLATE(kSubmenuArrowChromeRefreshPath, CANVAS_DIMENSIONS, 16, FLIPS_IN_RTL, R_MOVE_TO, 6.4f, 12.13f, R_LINE_TO, -0.98f, -0.98f, LINE_TO,
    8.57f, 8, LINE_TO, 5.42f, 4.85f, R_LINE_TO, 0.98f, -0.98f, LINE_TO, 10.53f, 8, CLOSE)
VECTOR_ICON_TEMPLATE_CC(
    kSubmenuArrowChromeRefreshRepList, kSubmenuArrowChromeRefreshIcon, { kSubmenuArrowChromeRefreshPath, std::size(kSubmenuArrowChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kSyncPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 8, 3.27f, V_LINE_TO, 1.5f, LINE_TO, 5.5f, 3.86f, LINE_TO, 8, 6.23f, V_LINE_TO, 4.46f,
    R_CUBIC_TO, 2.07f, 0, 3.75f, 1.59f, 3.75f, 3.55f, R_CUBIC_TO, 0, 0.6f, -0.16f, 1.16f, -0.44f, 1.66f, R_LINE_TO, 0.91f, 0.86f, CUBIC_TO, 12.71f, 9.79f, 13,
    8.93f, 13, 8, R_CUBIC_TO, 0, -2.61f, -2.24f, -4.73f, -5, -4.73f, CLOSE, R_MOVE_TO, 0, 8.27f, R_CUBIC_TO, -2.07f, 0, -3.75f, -1.59f, -3.75f, -3.54f,
    R_CUBIC_TO, 0, -0.6f, 0.16f, -1.16f, 0.44f, -1.65f, R_LINE_TO, -0.91f, -0.86f, CUBIC_TO, 3.29f, 6.21f, 3, 7.07f, 3, 8, R_CUBIC_TO, 0, 2.61f, 2.24f, 4.73f,
    5, 4.73f, V_LINE_TO, 14.5f, R_LINE_TO, 2.5f, -2.36f, LINE_TO, 8, 9.77f, R_V_LINE_TO, 1.77f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kSyncRepList, kSyncIcon, { kSyncPath, std::size(kSyncPath) })
VECTOR_ICON_REP_TEMPLATE(kSyncChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 4.5f, 16, R_V_LINE_TO, -1.5f, R_H_LINE_TO, 1.54f, R_ARC_TO,
    6.27f, 6.27f, 0, 0, 1, -1.49f, -1.99f, ARC_TO, 5.78f, 5.78f, 0, 0, 1, 4, 10, R_CUBIC_TO, 0, -1.4f, 0.42f, -2.64f, 1.27f, -3.7f, ARC_TO, 5.92f, 5.92f, 0, 0,
    1, 8.5f, 4.21f, V_LINE_TO, 5.77f, R_CUBIC_TO, -0.87f, 0.32f, -1.59f, 0.86f, -2.16f, 1.62f, CUBIC_TO, 5.78f, 8.14f, 5.5f, 9.02f, 5.5f, 10, R_CUBIC_TO, 0,
    0.67f, 0.14f, 1.29f, 0.41f, 1.86f, ARC_TO, 4.5f, 4.5f, 0, 0, 0, 7, 13.31f, V_LINE_TO, 12, R_H_LINE_TO, 1.5f, R_V_LINE_TO, 4, CLOSE, R_MOVE_TO, 7, -0.21f,
    V_LINE_TO, 14.23f, R_ARC_TO, 4.61f, 4.61f, 0, 0, 0, 2.16f, -1.62f, R_CUBIC_TO, 0.56f, -0.75f, 0.84f, -1.63f, 0.84f, -2.61f, R_CUBIC_TO, 0, -0.67f, -0.14f,
    -1.28f, -0.41f, -1.85f, ARC_TO, 4.5f, 4.5f, 0, 0, 0, 13, 6.69f, V_LINE_TO, 8, R_H_LINE_TO, -1.5f, V_LINE_TO, 4, R_H_LINE_TO, 4, R_V_LINE_TO, 1.5f,
    R_H_LINE_TO, -1.54f, R_ARC_TO, 6.27f, 6.27f, 0, 0, 1, 1.49f, 1.99f, R_CUBIC_TO, 0.37f, 0.77f, 0.55f, 1.61f, 0.55f, 2.51f, R_CUBIC_TO, 0, 1.4f, -0.42f,
    2.64f, -1.27f, 3.7f, R_ARC_TO, 5.92f, 5.92f, 0, 0, 1, -3.23f, 2.09f, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kSyncChromeRefresh16Path, CANVAS_DIMENSIONS, 16, MOVE_TO, 3.62f, 12.99f, R_V_LINE_TO, -1.34f, R_H_LINE_TO, 0.93f, R_LINE_TO, 0.12f,
    0.09f, R_ARC_TO, 5.92f, 5.92f, 0, 0, 1, -1.23f, -1.68f, ARC_TO, 4.62f, 4.62f, 0, 0, 1, 2.96f, 8, R_CUBIC_TO, 0, -1.22f, 0.39f, -2.29f, 1.17f, -3.2f,
    R_ARC_TO, 5.07f, 5.07f, 0, 0, 1, 2.91f, -1.73f, R_V_LINE_TO, 1.68f, R_CUBIC_TO, -0.71f, 0.2f, -1.29f, 0.59f, -1.75f, 1.19f, ARC_TO, 3.28f, 3.28f, 0, 0, 0,
    4.6f, 8, R_CUBIC_TO, 0, 0.5f, 0.11f, 0.96f, 0.31f, 1.38f, R_CUBIC_TO, 0.21f, 0.43f, 0.48f, 0.8f, 0.82f, 1.11f, R_LINE_TO, -0.07f, -0.07f, R_V_LINE_TO,
    -0.81f, R_H_LINE_TO, 1.34f, R_V_LINE_TO, 3.39f, CLOSE, R_MOVE_TO, 5.35f, -0.06f, R_V_LINE_TO, -1.68f, R_CUBIC_TO, 0.71f, -0.2f, 1.29f, -0.59f, 1.75f,
    -1.19f, ARC_TO, 3.28f, 3.28f, 0, 0, 0, 11.4f, 8, R_CUBIC_TO, 0, -0.5f, -0.1f, -0.96f, -0.31f, -1.38f, R_ARC_TO, 3.57f, 3.57f, 0, 0, 0, -0.82f, -1.1f,
    R_LINE_TO, 0.07f, 0.07f, R_V_LINE_TO, 0.81f, R_H_LINE_TO, -1.34f, V_LINE_TO, 3.01f, R_H_LINE_TO, 3.38f, R_V_LINE_TO, 1.34f, R_H_LINE_TO, -0.93f, R_LINE_TO,
    -0.12f, -0.09f, R_CUBIC_TO, 0.52f, 0.47f, 0.93f, 1.03f, 1.24f, 1.67f, R_CUBIC_TO, 0.31f, 0.64f, 0.46f, 1.33f, 0.46f, 2.07f, R_CUBIC_TO, 0, 1.22f, -0.39f,
    2.29f, -1.16f, 3.2f, R_ARC_TO, 5.07f, 5.07f, 0, 0, 1, -2.91f, 1.73f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kSyncChromeRefreshRepList, kSyncChromeRefreshIcon, { kSyncChromeRefreshPath, std::size(kSyncChromeRefreshPath) },
    { kSyncChromeRefresh16Path, std::size(kSyncChromeRefresh16Path) })
VECTOR_ICON_REP_TEMPLATE(kSyncOffChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, R_MOVE_TO, 16, 17.06f, R_LINE_TO, -2.98f, -2.98f, R_CUBIC_TO,
    -0.23f, 0.14f, -0.48f, 0.27f, -0.73f, 0.39f, R_CUBIC_TO, -0.25f, 0.12f, -0.52f, 0.21f, -0.79f, 0.28f, R_V_LINE_TO, -1.58f, R_CUBIC_TO, 0.07f, -0.03f, 0.14f,
    -0.06f, 0.21f, -0.09f, R_CUBIC_TO, 0.07f, -0.04f, 0.14f, -0.07f, 0.21f, -0.09f, LINE_TO, 5.96f, 7, R_ARC_TO, 5.21f, 5.21f, 0, 0, 0, -0.33f, 0.93f, ARC_TO,
    4.15f, 4.15f, 0, 0, 0, 5.5f, 8.94f, R_CUBIC_TO, 0, 0.67f, 0.14f, 1.29f, 0.41f, 1.86f, ARC_TO, 4.5f, 4.5f, 0, 0, 0, 7, 12.25f, R_V_LINE_TO, -1.31f,
    R_H_LINE_TO, 1.5f, R_V_LINE_TO, 4, R_H_LINE_TO, -4, R_V_LINE_TO, -1.5f, R_H_LINE_TO, 1.54f, R_ARC_TO, 6.27f, 6.27f, 0, 0, 1, -1.49f, -1.99f, ARC_TO, 5.78f,
    5.78f, 0, 0, 1, 4, 8.94f, R_CUBIC_TO, 0, -0.56f, 0.07f, -1.09f, 0.22f, -1.61f, R_CUBIC_TO, 0.14f, -0.51f, 0.35f, -0.99f, 0.61f, -1.44f, LINE_TO, 1.88f,
    2.92f, R_LINE_TO, 1.06f, -1.06f, LINE_TO, 17.06f, 16, CLOSE, R_MOVE_TO, -0.83f, -5.08f, R_LINE_TO, -1.12f, -1.12f, R_CUBIC_TO, 0.14f, -0.29f, 0.25f, -0.6f,
    0.33f, -0.92f, R_ARC_TO, 4.33f, 4.33f, 0, 0, 0, -0.28f, -2.86f, ARC_TO, 4.43f, 4.43f, 0, 0, 0, 13, 5.61f, R_V_LINE_TO, 1.33f, R_H_LINE_TO, -1.5f,
    R_V_LINE_TO, -4, R_H_LINE_TO, 4, R_V_LINE_TO, 1.5f, R_H_LINE_TO, -1.54f, R_ARC_TO, 6.27f, 6.27f, 0, 0, 1, 1.49f, 1.99f, R_CUBIC_TO, 0.37f, 0.77f, 0.55f,
    1.61f, 0.55f, 2.51f, R_CUBIC_TO, 0, 0.56f, -0.07f, 1.09f, -0.22f, 1.61f, R_ARC_TO, 6.11f, 6.11f, 0, 0, 1, -0.61f, 1.44f, CLOSE, MOVE_TO, 8.08f, 4.89f,
    LINE_TO, 6.98f, 3.77f, R_CUBIC_TO, 0.24f, -0.14f, 0.48f, -0.26f, 0.73f, -0.37f, R_CUBIC_TO, 0.25f, -0.11f, 0.52f, -0.2f, 0.79f, -0.27f, R_V_LINE_TO, 1.58f,
    R_CUBIC_TO, -0.07f, 0.03f, -0.14f, 0.06f, -0.21f, 0.09f, R_CUBIC_TO, -0.07f, 0.04f, -0.14f, 0.07f, -0.21f, 0.09f, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kSyncOffChromeRefresh16Path, CANVAS_DIMENSIONS, 16, FILL_RULE_NONZERO, R_MOVE_TO, 12.77f, 13.69f, R_LINE_TO, -2.34f, -2.34f,
    R_CUBIC_TO, -0.21f, 0.13f, -0.43f, 0.24f, -0.65f, 0.34f, R_CUBIC_TO, -0.23f, 0.1f, -0.46f, 0.18f, -0.71f, 0.24f, R_V_LINE_TO, -1.45f, R_CUBIC_TO, 0.06f,
    -0.02f, 0.11f, -0.05f, 0.17f, -0.07f, R_CUBIC_TO, 0.06f, -0.03f, 0.11f, -0.05f, 0.17f, -0.07f, LINE_TO, 4.79f, 5.69f, R_ARC_TO, 3.69f, 3.69f, 0, 0, 0,
    -0.24f, 0.7f, R_CUBIC_TO, -0.06f, 0.24f, -0.09f, 0.5f, -0.09f, 0.76f, R_CUBIC_TO, 0, 0.52f, 0.11f, 1, 0.32f, 1.44f, R_CUBIC_TO, 0.21f, 0.45f, 0.5f, 0.82f,
    0.85f, 1.14f, R_LINE_TO, -0.03f, -0.03f, R_V_LINE_TO, -0.95f, R_H_LINE_TO, 1.26f, R_V_LINE_TO, 3.28f, R_H_LINE_TO, -3.28f, V_LINE_TO, 10.77f, R_H_LINE_TO,
    1.11f, R_LINE_TO, 0.05f, 0.04f, R_ARC_TO, 5.13f, 5.13f, 0, 0, 1, -1.21f, -1.62f, R_ARC_TO, 4.72f, 4.72f, 0, 0, 1, -0.45f, -2.04f, R_CUBIC_TO, 0, -0.45f,
    0.06f, -0.89f, 0.18f, -1.31f, R_CUBIC_TO, 0.12f, -0.42f, 0.29f, -0.81f, 0.5f, -1.17f, LINE_TO, 1.47f, 2.38f, R_LINE_TO, 0.89f, -0.89f, R_LINE_TO, 11.3f,
    11.32f, CLOSE, R_MOVE_TO, -0.58f, -4.07f, R_LINE_TO, -1.04f, -1.04f, R_ARC_TO, 3.39f, 3.39f, 0, 0, 0, 0.25f, -0.68f, R_ARC_TO, 3.37f, 3.37f, 0, 0, 0,
    -0.23f, -2.2f, R_ARC_TO, 3.53f, 3.53f, 0, 0, 0, -0.85f, -1.15f, R_LINE_TO, 0.03f, 0.03f, R_V_LINE_TO, 0.97f, H_LINE_TO, 9.09f, V_LINE_TO, 2.27f,
    R_H_LINE_TO, 3.28f, V_LINE_TO, 3.53f, R_H_LINE_TO, -1.1f, R_LINE_TO, -0.05f, -0.04f, R_CUBIC_TO, 0.51f, 0.46f, 0.91f, 1, 1.21f, 1.63f, R_CUBIC_TO, 0.3f,
    0.63f, 0.45f, 1.31f, 0.45f, 2.04f, R_CUBIC_TO, 0, 0.45f, -0.06f, 0.89f, -0.18f, 1.31f, R_ARC_TO, 4.65f, 4.65f, 0, 0, 1, -0.5f, 1.17f, CLOSE, MOVE_TO, 6.54f,
    3.97f, R_LINE_TO, -1.02f, -1.03f, R_CUBIC_TO, 0.21f, -0.12f, 0.42f, -0.23f, 0.65f, -0.33f, R_CUBIC_TO, 0.22f, -0.1f, 0.46f, -0.17f, 0.7f, -0.23f,
    R_V_LINE_TO, 1.45f, R_CUBIC_TO, -0.05f, 0.02f, -0.11f, 0.04f, -0.17f, 0.07f, R_ARC_TO, 1.48f, 1.48f, 0, 0, 1, -0.16f, 0.07f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kSyncOffChromeRefreshRepList, kSyncOffChromeRefreshIcon, { kSyncOffChromeRefreshPath, std::size(kSyncOffChromeRefreshPath) },
    { kSyncOffChromeRefresh16Path, std::size(kSyncOffChromeRefresh16Path) })
VECTOR_ICON_REP_TEMPLATE(kSyncProblemChromeRefreshPath, CANVAS_DIMENSIONS, 16, FILL_RULE_NONZERO, MOVE_TO, 2.75f, 12.88f, V_LINE_TO, 11.62f, R_H_LINE_TO, 1.11f,
    R_LINE_TO, 0.05f, 0.04f, R_ARC_TO, 5.3f, 5.3f, 0, 0, 1, -1.21f, -1.63f, R_CUBIC_TO, -0.3f, -0.62f, -0.45f, -1.3f, -0.45f, -2.03f, R_CUBIC_TO, 0, -1.16f,
    0.36f, -2.18f, 1.07f, -3.06f, R_ARC_TO, 4.88f, 4.88f, 0, 0, 1, 2.72f, -1.7f, R_V_LINE_TO, 1.43f, R_ARC_TO, 3.46f, 3.46f, 0, 0, 0, -1.73f, 1.25f, ARC_TO,
    3.36f, 3.36f, 0, 0, 0, 3.63f, 8, R_CUBIC_TO, 0, 0.52f, 0.11f, 1, 0.32f, 1.44f, R_CUBIC_TO, 0.21f, 0.45f, 0.5f, 0.83f, 0.85f, 1.14f, R_LINE_TO, -0.03f,
    -0.03f, V_LINE_TO, 9.6f, R_H_LINE_TO, 1.26f, R_V_LINE_TO, 3.28f, CLOSE, MOVE_TO, 8, 11.25f, R_ARC_TO, 0.62f, 0.62f, 0, 0, 1, -0.46f, -0.19f, R_ARC_TO,
    0.61f, 0.61f, 0, 0, 1, -0.19f, -0.46f, ARC_TO, 0.64f, 0.64f, 0, 0, 1, 8, 9.95f, R_CUBIC_TO, 0.18f, 0, 0.33f, 0.06f, 0.46f, 0.19f, R_ARC_TO, 0.61f, 0.61f, 0,
    0, 1, 0.19f, 0.46f, R_ARC_TO, 0.64f, 0.64f, 0, 0, 1, -0.65f, 0.65f, CLOSE, R_MOVE_TO, -0.63f, -2.41f, V_LINE_TO, 4.74f, R_H_LINE_TO, 1.27f, R_V_LINE_TO,
    4.09f, CLOSE, R_MOVE_TO, 2.59f, 3.93f, R_V_LINE_TO, -1.43f, R_ARC_TO, 3.46f, 3.46f, 0, 0, 0, 1.73f, -1.25f, R_CUBIC_TO, 0.45f, -0.6f, 0.68f, -1.29f, 0.68f,
    -2.07f, R_CUBIC_TO, 0, -0.52f, -0.1f, -1, -0.32f, -1.44f, R_ARC_TO, 3.54f, 3.54f, 0, 0, 0, -0.85f, -1.14f, R_LINE_TO, 0.03f, 0.03f, R_V_LINE_TO, 0.95f,
    H_LINE_TO, 9.97f, V_LINE_TO, 3.12f, R_H_LINE_TO, 3.28f, V_LINE_TO, 4.38f, R_H_LINE_TO, -1.1f, R_LINE_TO, -0.05f, -0.04f, R_CUBIC_TO, 0.51f, 0.45f, 0.91f, 1,
    1.21f, 1.63f, R_CUBIC_TO, 0.3f, 0.63f, 0.45f, 1.31f, 0.45f, 2.04f, R_CUBIC_TO, 0, 1.16f, -0.35f, 2.18f, -1.07f, 3.06f, R_ARC_TO, 4.88f, 4.88f, 0, 0, 1,
    -2.72f, 1.7f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(
    kSyncProblemChromeRefreshRepList, kSyncProblemChromeRefreshIcon, { kSyncProblemChromeRefreshPath, std::size(kSyncProblemChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kTenancyPath, CANVAS_DIMENSIONS, 20, MOVE_TO, 3.5f, 17, R_QUADRATIC_TO, -1.04f, 0, -1.77f, -0.73f, QUADRATIC_TO, 1, 15.54f, 1, 14.5f,
    R_QUADRATIC_TO, 0, -1.04f, 0.73f, -1.77f, QUADRATIC_TO, 2.46f, 12, 3.5f, 12, R_QUADRATIC_TO, 0.29f, 0, 0.57f, 0.06f, R_QUADRATIC_TO, 0.28f, 0.06f, 0.53f,
    0.19f, R_LINE_TO, 3.13f, -4.29f, R_QUADRATIC_TO, -0.35f, -0.4f, -0.54f, -0.9f, QUADRATIC_TO, 7, 6.56f, 7, 6, R_QUADRATIC_TO, 0, -1.25f, 0.88f, -2.12f,
    QUADRATIC_TO_SHORTHAND, 10, 3, R_QUADRATIC_TO, 1.25f, 0, 2.13f, 0.88f, QUADRATIC_TO_SHORTHAND, 13, 6, R_QUADRATIC_TO, 0, 0.56f, -0.19f, 1.06f,
    R_QUADRATIC_TO, -0.19f, 0.5f, -0.54f, 0.9f, R_LINE_TO, 3.13f, 4.29f, R_QUADRATIC_TO, 0.25f, -0.12f, 0.53f, -0.19f, R_QUADRATIC_TO, 0.28f, -0.06f, 0.57f,
    -0.06f, R_QUADRATIC_TO, 1.04f, 0, 1.77f, 0.73f, R_QUADRATIC_TO, 0.73f, 0.73f, 0.73f, 1.77f, R_QUADRATIC_TO, 0, 1.04f, -0.73f, 1.77f, QUADRATIC_TO, 17.54f,
    17, 16.5f, 17, R_QUADRATIC_TO, -1.04f, 0, -1.77f, -0.73f, QUADRATIC_TO, 14, 15.54f, 14, 14.5f, R_QUADRATIC_TO, 0, -0.33f, 0.08f, -0.62f, R_QUADRATIC_TO,
    0.08f, -0.29f, 0.23f, -0.56f, R_LINE_TO, -3.27f, -4.5f, R_QUADRATIC_TO, -0.08f, 0.04f, -0.15f, 0.05f, R_QUADRATIC_TO, -0.06f, 0.01f, -0.15f, 0.03f,
    R_V_LINE_TO, 3.23f, R_QUADRATIC_TO, 0.77f, 0.23f, 1.26f, 0.88f, R_QUADRATIC_TO, 0.49f, 0.65f, 0.49f, 1.5f, R_QUADRATIC_TO, 0, 1.04f, -0.73f, 1.77f,
    QUADRATIC_TO, 11.04f, 17, 10, 17, R_QUADRATIC_TO, -1.04f, 0, -1.77f, -0.73f, QUADRATIC_TO, 7.5f, 15.54f, 7.5f, 14.5f, R_QUADRATIC_TO, 0, -0.85f, 0.49f,
    -1.5f, R_QUADRATIC_TO, 0.49f, -0.65f, 1.26f, -0.87f, V_LINE_TO, 8.9f, R_QUADRATIC_TO, -0.08f, -0.02f, -0.16f, -0.03f, R_QUADRATIC_TO, -0.07f, -0.01f,
    -0.14f, -0.05f, R_LINE_TO, -3.25f, 4.5f, R_QUADRATIC_TO, 0.15f, 0.27f, 0.22f, 0.56f, R_QUADRATIC_TO, 0.07f, 0.29f, 0.07f, 0.63f, R_QUADRATIC_TO, 0, 1.04f,
    -0.73f, 1.77f, QUADRATIC_TO, 4.54f, 17, 3.5f, 17, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kTenancyRepList, kTenancyIcon, { kTenancyPath, std::size(kTenancyPath) })
VECTOR_ICON_REP_TEMPLATE(kThumbDownPath, CANVAS_DIMENSIONS, 24, FILL_RULE_NONZERO, MOVE_TO, 6, 3, R_H_LINE_TO, 11, R_V_LINE_TO, 13, R_LINE_TO, -7, 7, R_LINE_TO,
    -1.25f, -1.25f, R_ARC_TO, 1.45f, 1.45f, 0, 0, 1, -0.3f, -0.47f, R_CUBIC_TO, -0.07f, -0.2f, -0.1f, -0.39f, -0.1f, -0.57f, R_V_LINE_TO, -0.35f, LINE_TO,
    9.45f, 16, H_LINE_TO, 3, R_CUBIC_TO, -0.53f, 0, -1, -0.2f, -1.4f, -0.6f, R_CUBIC_TO, -0.4f, -0.4f, -0.6f, -0.87f, -0.6f, -1.4f, R_V_LINE_TO, -2, R_CUBIC_TO,
    0, -0.12f, 0.02f, -0.24f, 0.05f, -0.37f, R_CUBIC_TO, 0.03f, -0.13f, 0.07f, -0.26f, 0.1f, -0.37f, R_LINE_TO, 3, -7.05f, R_CUBIC_TO, 0.15f, -0.33f, 0.4f,
    -0.62f, 0.75f, -0.85f, CUBIC_TO, 5.25f, 3.12f, 5.62f, 3, 6, 3, CLOSE, R_MOVE_TO, 9, 2, H_LINE_TO, 6, R_LINE_TO, -3, 7, R_V_LINE_TO, 2, R_H_LINE_TO, 9,
    R_LINE_TO, -1.35f, 5.5f, LINE_TO, 15, 15.15f, V_LINE_TO, 5, CLOSE, R_MOVE_TO, 0, 10.15f, V_LINE_TO, 5, R_V_LINE_TO, 10.15f, CLOSE, R_MOVE_TO, 2, 0.85f,
    R_V_LINE_TO, -2, R_H_LINE_TO, 3, V_LINE_TO, 5, R_H_LINE_TO, -3, V_LINE_TO, 3, R_H_LINE_TO, 5, R_V_LINE_TO, 13, R_H_LINE_TO, -5, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kThumbDownRepList, kThumbDownIcon, { kThumbDownPath, std::size(kThumbDownPath) })
VECTOR_ICON_REP_TEMPLATE(kThumbDownFilledPath, CANVAS_DIMENSIONS, 24, FILL_RULE_NONZERO, MOVE_TO, 6, 3, R_H_LINE_TO, 10, R_V_LINE_TO, 13, R_LINE_TO, -7, 7,
    R_LINE_TO, -1.25f, -1.25f, R_ARC_TO, 1.34f, 1.34f, 0, 0, 1, -0.29f, -0.48f, R_ARC_TO, 1.66f, 1.66f, 0, 0, 1, -0.11f, -0.57f, R_V_LINE_TO, -0.35f, LINE_TO,
    8.45f, 16, H_LINE_TO, 3, R_CUBIC_TO, -0.53f, 0, -1, -0.2f, -1.4f, -0.6f, CUBIC_TO, 1.2f, 15, 1, 14.54f, 1, 14, R_V_LINE_TO, -2, R_CUBIC_TO, 0, -0.12f,
    0.01f, -0.24f, 0.04f, -0.37f, R_CUBIC_TO, 0.02f, -0.13f, 0.06f, -0.26f, 0.11f, -0.37f, R_LINE_TO, 3, -7.05f, R_CUBIC_TO, 0.15f, -0.33f, 0.4f, -0.62f, 0.75f,
    -0.85f, ARC_TO, 1.96f, 1.96f, 0, 0, 1, 6, 3, CLOSE, R_MOVE_TO, 12, 13, V_LINE_TO, 3, R_H_LINE_TO, 4, R_V_LINE_TO, 13, CLOSE, R_MOVE_TO, 0, 0, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kThumbDownFilledRepList, kThumbDownFilledIcon, { kThumbDownFilledPath, std::size(kThumbDownFilledPath) })
VECTOR_ICON_REP_TEMPLATE(kThumbUpPath, CANVAS_DIMENSIONS, 24, FILL_RULE_NONZERO, MOVE_TO, 18, 21, H_LINE_TO, 7, V_LINE_TO, 8, R_LINE_TO, 7, -7, R_LINE_TO,
    1.25f, 1.25f, R_CUBIC_TO, 0.12f, 0.12f, 0.21f, 0.28f, 0.28f, 0.48f, R_CUBIC_TO, 0.08f, 0.2f, 0.13f, 0.39f, 0.13f, 0.57f, R_V_LINE_TO, 0.35f, LINE_TO,
    14.55f, 8, H_LINE_TO, 21, R_CUBIC_TO, 0.53f, 0, 1, 0.2f, 1.4f, 0.6f, R_CUBIC_TO, 0.4f, 0.4f, 0.6f, 0.87f, 0.6f, 1.4f, R_V_LINE_TO, 2, R_CUBIC_TO, 0, 0.12f,
    -0.02f, 0.24f, -0.05f, 0.38f, R_CUBIC_TO, -0.03f, 0.14f, -0.07f, 0.26f, -0.1f, 0.38f, R_LINE_TO, -3, 7.05f, R_CUBIC_TO, -0.15f, 0.33f, -0.4f, 0.62f, -0.75f,
    0.85f, R_CUBIC_TO, -0.35f, 0.23f, -0.72f, 0.35f, -1.1f, 0.35f, CLOSE, R_MOVE_TO, -9, -2, R_H_LINE_TO, 9, R_LINE_TO, 3, -7, R_V_LINE_TO, -2, R_H_LINE_TO, -9,
    R_LINE_TO, 1.35f, -5.5f, LINE_TO, 9, 8.85f, V_LINE_TO, 19, CLOSE, MOVE_TO, 9, 8.85f, V_LINE_TO, 19, V_LINE_TO, 8.85f, CLOSE, MOVE_TO, 7, 8, R_V_LINE_TO, 2,
    H_LINE_TO, 4, R_V_LINE_TO, 9, R_H_LINE_TO, 3, R_V_LINE_TO, 2, H_LINE_TO, 2, V_LINE_TO, 8, R_H_LINE_TO, 5, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kThumbUpRepList, kThumbUpIcon, { kThumbUpPath, std::size(kThumbUpPath) })
VECTOR_ICON_REP_TEMPLATE(kThumbUpFilledPath, CANVAS_DIMENSIONS, 24, FILL_RULE_NONZERO, MOVE_TO, 18, 21, H_LINE_TO, 8, V_LINE_TO, 8, R_LINE_TO, 7, -7, R_LINE_TO,
    1.25f, 1.25f, R_CUBIC_TO, 0.12f, 0.12f, 0.21f, 0.27f, 0.29f, 0.48f, R_CUBIC_TO, 0.07f, 0.2f, 0.11f, 0.39f, 0.11f, 0.57f, R_V_LINE_TO, 0.35f, LINE_TO,
    15.55f, 8, H_LINE_TO, 21, R_CUBIC_TO, 0.54f, 0, 1, 0.2f, 1.4f, 0.6f, CUBIC_TO, 22.8f, 9, 23, 9.47f, 23, 10, R_V_LINE_TO, 2, R_CUBIC_TO, 0, 0.12f, -0.01f,
    0.24f, -0.04f, 0.38f, R_ARC_TO, 1.9f, 1.9f, 0, 0, 1, -0.11f, 0.38f, R_LINE_TO, -3, 7.05f, R_ARC_TO, 2.04f, 2.04f, 0, 0, 1, -0.75f, 0.85f, ARC_TO, 1.96f,
    1.96f, 0, 0, 1, 18, 21, CLOSE, MOVE_TO, 6, 8, R_V_LINE_TO, 13, H_LINE_TO, 2, V_LINE_TO, 8, CLOSE, R_MOVE_TO, 0, 0, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kThumbUpFilledRepList, kThumbUpFilledIcon, { kThumbUpFilledPath, std::size(kThumbUpFilledPath) })
VECTOR_ICON_REP_TEMPLATE(kTouchpadMousePath, CANVAS_DIMENSIONS, 24, MOVE_TO, 16.5f, 20, CUBIC_TO, 17.46f, 20, 18.29f, 19.66f, 18.98f, 18.98f, CUBIC_TO, 19.66f,
    18.29f, 20, 17.46f, 20, 16.5f, LINE_TO, 20, 15, LINE_TO, 13, 15, LINE_TO, 13, 16.5f, CUBIC_TO, 13, 17.46f, 13.34f, 18.29f, 14.02f, 18.98f, CUBIC_TO, 14.71f,
    19.66f, 15.54f, 20, 16.5f, 20, CLOSE, MOVE_TO, 13.02f, 13, LINE_TO, 15.5f, 13, LINE_TO, 15.5f, 10.15f, CUBIC_TO, 14.87f, 10.33f, 14.32f, 10.68f, 13.86f,
    11.2f, CUBIC_TO, 13.4f, 11.71f, 13.13f, 12.32f, 13.02f, 13, CLOSE, MOVE_TO, 17.5f, 13, LINE_TO, 19.98f, 13, CUBIC_TO, 19.88f, 12.32f, 19.6f, 11.71f, 19.14f,
    11.2f, CUBIC_TO, 18.68f, 10.68f, 18.13f, 10.33f, 17.5f, 10.15f, CLOSE, MOVE_TO, 16.5f, 22, CUBIC_TO, 14.96f, 22, 13.67f, 21.46f, 12.6f, 20.4f, CUBIC_TO,
    11.54f, 19.33f, 11, 18.04f, 11, 16.5f, LINE_TO, 11, 13.5f, CUBIC_TO, 11, 11.96f, 11.54f, 10.67f, 12.6f, 9.6f, CUBIC_TO, 13.67f, 8.54f, 14.96f, 8, 16.5f, 8,
    CUBIC_TO, 18.04f, 8, 19.33f, 8.54f, 20.4f, 9.6f, CUBIC_TO, 21.46f, 10.67f, 22, 11.96f, 22, 13.5f, LINE_TO, 22, 16.5f, CUBIC_TO, 22, 18.04f, 21.46f, 19.33f,
    20.4f, 20.4f, CUBIC_TO, 19.33f, 21.46f, 18.04f, 22, 16.5f, 22, CLOSE, MOVE_TO, 4, 18, LINE_TO, 4, 6, CLOSE, MOVE_TO, 4, 20, CUBIC_TO, 3.45f, 20, 2.98f,
    19.8f, 2.59f, 19.41f, CUBIC_TO, 2.2f, 19.02f, 2, 18.55f, 2, 18, LINE_TO, 2, 6, CUBIC_TO, 2, 5.45f, 2.2f, 4.98f, 2.59f, 4.59f, CUBIC_TO, 2.98f, 4.2f, 3.45f,
    4, 4, 4, LINE_TO, 20, 4, CUBIC_TO, 20.55f, 4, 21.02f, 4.2f, 21.41f, 4.59f, CUBIC_TO, 21.8f, 4.98f, 22, 5.45f, 22, 6, LINE_TO, 22, 8.4f, CUBIC_TO, 21.71f,
    8.08f, 21.41f, 7.8f, 21.07f, 7.54f, CUBIC_TO, 20.74f, 7.28f, 20.38f, 7.05f, 20, 6.85f, LINE_TO, 20, 6, LINE_TO, 4, 6, LINE_TO, 4, 18, LINE_TO, 9.15f, 18,
    CUBIC_TO, 9.23f, 18.35f, 9.33f, 18.69f, 9.44f, 19.02f, CUBIC_TO, 9.55f, 19.36f, 9.68f, 19.68f, 9.85f, 20, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kTouchpadMouseRepList, kTouchpadMouseIcon, { kTouchpadMousePath, std::size(kTouchpadMousePath) })
VECTOR_ICON_REP_TEMPLATE(kTouchpadMouseOffPath, CANVAS_DIMENSIONS, 24, FILL_RULE_NONZERO, MOVE_TO, 16.5f, 15.02f, CLOSE, R_MOVE_TO, 0, 0, CLOSE, R_MOVE_TO,
    3.98f, 8.28f, LINE_TO, 0.68f, 3.5f, R_LINE_TO, 1.43f, -1.43f, R_LINE_TO, 19.8f, 19.8f, CLOSE, MOVE_TO, 16.5f, 15.02f, CLOSE, R_MOVE_TO, 0, 0, CLOSE,
    R_MOVE_TO, 0, 6.98f, R_CUBIC_TO, -1.53f, 0, -2.83f, -0.53f, -3.9f, -1.6f, CUBIC_TO, 11.54f, 19.33f, 11, 18.04f, 11, 16.5f, R_V_LINE_TO, -3, R_CUBIC_TO, 0,
    -0.38f, 0.04f, -0.75f, 0.11f, -1.09f, R_CUBIC_TO, 0.08f, -0.34f, 0.18f, -0.68f, 0.31f, -1.02f, LINE_TO, 15.02f, 15, H_LINE_TO, 13, R_V_LINE_TO, 1.5f,
    R_CUBIC_TO, 0, 0.97f, 0.34f, 1.79f, 1.02f, 2.48f, ARC_TO, 3.38f, 3.38f, 0, 0, 0, 16.5f, 20, R_ARC_TO, 3.4f, 3.4f, 0, 0, 0, 1.36f, -0.27f, R_ARC_TO, 3.31f,
    3.31f, 0, 0, 0, 1.11f, -0.78f, R_LINE_TO, 1.42f, 1.43f, R_CUBIC_TO, -0.5f, 0.5f, -1.08f, 0.9f, -1.75f, 1.19f, ARC_TO, 5.27f, 5.27f, 0, 0, 1, 16.5f, 22,
    CLOSE, R_MOVE_TO, 5.05f, -3.32f, R_LINE_TO, -1.6f, -1.6f, R_CUBIC_TO, 0.02f, -0.1f, 0.03f, -0.19f, 0.04f, -0.28f, R_CUBIC_TO, 0.01f, -0.09f, 0.01f, -0.19f,
    0.01f, -0.29f, V_LINE_TO, 15, R_H_LINE_TO, -2.12f, LINE_TO, 15.5f, 12.63f, R_V_LINE_TO, -2.48f, R_ARC_TO, 3.52f, 3.52f, 0, 0, 0, -0.81f, 0.36f, R_ARC_TO,
    3.38f, 3.38f, 0, 0, 0, -0.71f, 0.59f, LINE_TO, 12.55f, 9.68f, R_ARC_TO, 5.6f, 5.6f, 0, 0, 1, 1.76f, -1.23f, CUBIC_TO, 14.99f, 8.15f, 15.72f, 8, 16.5f, 8,
    R_CUBIC_TO, 1.54f, 0, 2.83f, 0.54f, 3.9f, 1.6f, CUBIC_TO, 21.47f, 10.67f, 22, 11.97f, 22, 13.5f, R_V_LINE_TO, 3, R_CUBIC_TO, 0, 0.38f, -0.04f, 0.76f,
    -0.12f, 1.13f, R_ARC_TO, 6.99f, 6.99f, 0, 0, 1, -0.32f, 1.05f, CLOSE, MOVE_TO, 17.5f, 13, R_H_LINE_TO, 2.48f, R_ARC_TO, 3.39f, 3.39f, 0, 0, 0, -0.84f,
    -1.8f, R_ARC_TO, 3.44f, 3.44f, 0, 0, 0, -1.64f, -1.05f, CLOSE, MOVE_TO, 9.93f, 9.9f, CLOSE, R_MOVE_TO, 1.22f, -1.62f, CLOSE, MOVE_TO, 4, 20, R_CUBIC_TO,
    -0.55f, 0, -1.02f, -0.19f, -1.41f, -0.59f, ARC_TO, 1.94f, 1.94f, 0, 0, 1, 2, 18, V_LINE_TO, 6, R_CUBIC_TO, 0, -0.55f, 0.2f, -1.02f, 0.59f, -1.41f, CUBIC_TO,
    2.98f, 4.2f, 3.45f, 4, 4, 4, R_H_LINE_TO, 0.02f, R_LINE_TO, 2, 2, H_LINE_TO, 4, R_V_LINE_TO, 12, R_H_LINE_TO, 5.15f, R_CUBIC_TO, 0.09f, 0.35f, 0.18f, 0.69f,
    0.29f, 1.02f, R_CUBIC_TO, 0.11f, 0.34f, 0.25f, 0.66f, 0.41f, 0.98f, CLOSE, MOVE_TO, 22, 8.4f, R_ARC_TO, 6.88f, 6.88f, 0, 0, 0, -0.93f, -0.86f, ARC_TO,
    6.79f, 6.79f, 0, 0, 0, 20, 6.85f, V_LINE_TO, 6, H_LINE_TO, 8.88f, R_LINE_TO, -2, -2, H_LINE_TO, 20, R_CUBIC_TO, 0.55f, 0, 1.02f, 0.2f, 1.41f, 0.59f,
    R_CUBIC_TO, 0.39f, 0.39f, 0.59f, 0.86f, 0.59f, 1.41f, CLOSE, R_MOVE_TO, 0, 0, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kTouchpadMouseOffRepList, kTouchpadMouseOffIcon, { kTouchpadMouseOffPath, std::size(kTouchpadMouseOffPath) })
VECTOR_ICON_REP_TEMPLATE(kTranslatePath, CANVAS_DIMENSIONS, 20, R_MOVE_TO, 10, 18.16f, R_LINE_TO, -1.02f, -3.05f, H_LINE_TO, 3.38f, R_ARC_TO, 1.59f, 1.59f, 0,
    0, 1, -1.08f, -0.46f, R_ARC_TO, 1.46f, 1.46f, 0, 0, 1, -0.45f, -1.07f, V_LINE_TO, 3.38f, R_CUBIC_TO, 0, -0.41f, 0.15f, -0.77f, 0.45f, -1.07f, R_CUBIC_TO,
    0.3f, -0.3f, 0.66f, -0.46f, 1.08f, -0.46f, R_H_LINE_TO, 4.59f, R_LINE_TO, 1.01f, 3.05f, R_H_LINE_TO, 7.64f, R_CUBIC_TO, 0.41f, 0, 0.77f, 0.15f, 1.07f,
    0.46f, R_CUBIC_TO, 0.31f, 0.3f, 0.46f, 0.66f, 0.46f, 1.07f, R_V_LINE_TO, 10.2f, R_CUBIC_TO, 0, 0.43f, -0.15f, 0.79f, -0.46f, 1.08f, R_CUBIC_TO, -0.3f, 0.3f,
    -0.66f, 0.45f, -1.07f, 0.45f, CLOSE, MOVE_TO, 5.99f, 12.04f, R_CUBIC_TO, 0.81f, 0, 1.5f, -0.26f, 2.07f, -0.79f, R_CUBIC_TO, 0.57f, -0.53f, 0.86f, -1.27f,
    0.86f, -2.21f, R_CUBIC_TO, 0, -0.1f, 0, -0.2f, -0.01f, -0.29f, R_ARC_TO, 2.07f, 2.07f, 0, 0, 0, -0.05f, -0.32f, H_LINE_TO, 5.99f, R_V_LINE_TO, 1.04f,
    R_H_LINE_TO, 1.78f, R_CUBIC_TO, -0.05f, 0.47f, -0.24f, 0.83f, -0.58f, 1.09f, R_CUBIC_TO, -0.34f, 0.26f, -0.74f, 0.39f, -1.21f, 0.39f, R_CUBIC_TO, -0.54f, 0,
    -1, -0.19f, -1.37f, -0.57f, R_ARC_TO, 1.94f, 1.94f, 0, 0, 1, -0.56f, -1.4f, R_CUBIC_TO, 0, -0.54f, 0.19f, -1, 0.56f, -1.39f, R_CUBIC_TO, 0.38f, -0.39f,
    0.83f, -0.59f, 1.37f, -0.59f, R_CUBIC_TO, 0.23f, 0, 0.45f, 0.04f, 0.66f, 0.13f, R_ARC_TO, 2, 2, 0, 0, 1, 0.57f, 0.36f, R_LINE_TO, 0.81f, -0.79f, R_ARC_TO,
    2.75f, 2.75f, 0, 0, 0, -0.96f, -0.59f, R_ARC_TO, 3.26f, 3.26f, 0, 0, 0, -1.09f, -0.19f, R_CUBIC_TO, -0.85f, 0, -1.58f, 0.3f, -2.17f, 0.89f, R_ARC_TO, 2.95f,
    2.95f, 0, 0, 0, -0.89f, 2.17f, R_CUBIC_TO, 0, 0.84f, 0.3f, 1.57f, 0.89f, 2.16f, R_CUBIC_TO, 0.59f, 0.6f, 1.32f, 0.9f, 2.17f, 0.9f, CLOSE, R_MOVE_TO, 5.39f,
    0.72f, R_LINE_TO, 0.41f, -0.4f, R_ARC_TO, 5.65f, 5.65f, 0, 0, 1, -0.53f, -0.66f, R_ARC_TO, 7.64f, 7.64f, 0, 0, 1, -0.44f, -0.73f, CLOSE, R_MOVE_TO, 1,
    -1.04f, R_CUBIC_TO, 0.29f, -0.34f, 0.55f, -0.69f, 0.79f, -1.07f, R_CUBIC_TO, 0.24f, -0.37f, 0.42f, -0.79f, 0.53f, -1.24f, R_H_LINE_TO, -3.37f, R_LINE_TO,
    0.29f, 0.89f, R_LINE_TO, 0.83f, -0.02f, R_CUBIC_TO, 0.13f, 0.27f, 0.26f, 0.53f, 0.41f, 0.77f, R_CUBIC_TO, 0.15f, 0.24f, 0.32f, 0.46f, 0.52f, 0.68f, CLOSE,
    R_MOVE_TO, -1.36f, 5.43f, R_H_LINE_TO, 5.61f, R_ARC_TO, 0.52f, 0.52f, 0, 0, 0, 0.37f, -0.14f, R_ARC_TO, 0.5f, 0.5f, 0, 0, 0, 0.15f, -0.37f, R_V_LINE_TO,
    -10.2f, R_ARC_TO, 0.5f, 0.5f, 0, 0, 0, -0.52f, -0.51f, H_LINE_TO, 9.24f, R_LINE_TO, 0.81f, 2.62f, R_H_LINE_TO, 1.7f, R_V_LINE_TO, -0.87f, R_H_LINE_TO,
    0.85f, R_V_LINE_TO, 0.87f, R_H_LINE_TO, 3.07f, R_V_LINE_TO, 0.87f, H_LINE_TO, 14.59f, R_ARC_TO, 6.11f, 6.11f, 0, 0, 1, -0.64f, 1.58f, R_CUBIC_TO, -0.29f,
    0.49f, -0.61f, 0.95f, -0.98f, 1.37f, R_LINE_TO, 2.29f, 2.25f, R_LINE_TO, -0.61f, 0.61f, R_LINE_TO, -2.25f, -2.25f, R_LINE_TO, -0.74f, 0.73f, R_LINE_TO,
    0.76f, 2.41f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kTranslateRepList, kTranslateIcon, { kTranslatePath, std::size(kTranslatePath) })
VECTOR_ICON_REP_TEMPLATE(kUndoPath, CANVAS_DIMENSIONS, 960, MOVE_TO, 229.85f, 812.57f, R_V_LINE_TO, -71.25f, R_H_LINE_TO, 348.33f, R_CUBIC_TO, 56.25f, 0,
    104.66f, -18.41f, 145.24f, -55.23f, R_CUBIC_TO, 40.58f, -36.82f, 60.87f, -82.54f, 60.87f, -137.17f, R_CUBIC_TO, 0, -54.63f, -20.29f, -100.35f, -60.87f,
    -137.17f, R_CUBIC_TO, -40.58f, -36.82f, -88.99f, -55.22f, -145.24f, -55.22f, H_LINE_TO, 222.62f, R_LINE_TO, 137.4f, 135.39f, R_LINE_TO, -50.62f, 49.88f,
    LINE_TO, 85.21f, 320.9f, LINE_TO, 309.4f, 100, R_LINE_TO, 50.62f, 49.88f, R_LINE_TO, -137.4f, 135.39f, R_H_LINE_TO, 354.36f, R_CUBIC_TO, 76.33f, 0, 142.03f,
    25.33f, 197.07f, 76.01f, R_CUBIC_TO, 55.04f, 50.67f, 82.56f, 113.22f, 82.56f, 187.64f, R_CUBIC_TO, 0, 74.43f, -27.52f, 136.97f, -82.56f, 187.64f,
    R_CUBIC_TO, -55.04f, 50.67f, -120.73f, 76.01f, -197.06f, 76.01f, H_LINE_TO, 229.85f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kUndoRepList, kUndoIcon, { kUndoPath, std::size(kUndoPath) })
VECTOR_ICON_REP_TEMPLATE(kUsbPath, MOVE_TO, 30, 14, R_V_LINE_TO, 8, R_H_LINE_TO, 2, R_V_LINE_TO, 4, R_H_LINE_TO, -6, V_LINE_TO, 10, R_H_LINE_TO, 4, R_LINE_TO,
    -6, -8, R_LINE_TO, -6, 8, R_H_LINE_TO, 4, R_V_LINE_TO, 16, R_H_LINE_TO, -6, R_V_LINE_TO, -4.14f, R_CUBIC_TO, 1.41f, -0.73f, 2.4f, -2.16f, 2.4f, -3.86f,
    R_CUBIC_TO, 0, -2.43f, -1.97f, -4.4f, -4.4f, -4.4f, R_CUBIC_TO, -2.43f, 0, -4.4f, 1.97f, -4.4f, 4.4f, R_CUBIC_TO, 0, 1.7f, 0.99f, 3.13f, 2.4f, 3.86f,
    V_LINE_TO, 26, R_CUBIC_TO, 0, 2.21f, 1.79f, 4, 4, 4, R_H_LINE_TO, 6, R_V_LINE_TO, 6.1f, R_CUBIC_TO, -1.42f, 0.73f, -2.4f, 2.19f, -2.4f, 3.9f, R_CUBIC_TO, 0,
    2.43f, 1.97f, 4.4f, 4.4f, 4.4f, R_CUBIC_TO, 2.43f, 0, 4.4f, -1.97f, 4.4f, -4.4f, R_CUBIC_TO, 0, -1.71f, -0.98f, -3.17f, -2.4f, -3.9f, V_LINE_TO, 30,
    R_H_LINE_TO, 6, R_CUBIC_TO, 2.21f, 0, 4, -1.79f, 4, -4, R_V_LINE_TO, -4, R_H_LINE_TO, 2, R_V_LINE_TO, -8, R_H_LINE_TO, -8, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kUsbRepList, kUsbIcon, { kUsbPath, std::size(kUsbPath) })
VECTOR_ICON_REP_TEMPLATE(kUsbChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 10, 18, R_CUBIC_TO, -0.41f, 0, -0.77f, -0.15f, -1.06f,
    -0.44f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 8.5f, 16.5f, R_CUBIC_TO, 0, -0.27f, 0.07f, -0.52f, 0.2f, -0.75f, R_CUBIC_TO, 0.13f, -0.23f, 0.32f, -0.41f, 0.55f,
    -0.54f, V_LINE_TO, 13, R_H_LINE_TO, -2.5f, R_CUBIC_TO, -0.41f, 0, -0.77f, -0.14f, -1.06f, -0.44f, R_ARC_TO, 1.44f, 1.44f, 0, 0, 1, -0.44f, -1.05f,
    V_LINE_TO, 9.79f, R_ARC_TO, 1.36f, 1.36f, 0, 0, 1, -0.55f, -0.53f, R_CUBIC_TO, -0.13f, -0.23f, -0.2f, -0.48f, -0.2f, -0.76f, R_CUBIC_TO, 0, -0.41f, 0.15f,
    -0.77f, 0.44f, -1.06f, ARC_TO, 1.46f, 1.46f, 0, 0, 1, 6, 7, R_CUBIC_TO, 0.41f, 0, 0.77f, 0.15f, 1.06f, 0.44f, R_CUBIC_TO, 0.29f, 0.29f, 0.44f, 0.65f, 0.44f,
    1.06f, R_CUBIC_TO, 0, 0.28f, -0.07f, 0.53f, -0.2f, 0.76f, R_ARC_TO, 1.36f, 1.36f, 0, 0, 1, -0.55f, 0.53f, V_LINE_TO, 11.5f, R_H_LINE_TO, 2.5f, V_LINE_TO, 5,
    H_LINE_TO, 7.5f, LINE_TO, 10, 2, R_LINE_TO, 2.5f, 3, R_H_LINE_TO, -1.75f, R_V_LINE_TO, 6.5f, R_H_LINE_TO, 2.5f, V_LINE_TO, 10, R_H_LINE_TO, -0.75f,
    V_LINE_TO, 7, R_H_LINE_TO, 3, R_V_LINE_TO, 3, R_H_LINE_TO, -0.75f, R_V_LINE_TO, 1.5f, R_CUBIC_TO, 0, 0.41f, -0.15f, 0.77f, -0.44f, 1.06f, ARC_TO, 1.44f,
    1.44f, 0, 0, 1, 13.25f, 13, R_H_LINE_TO, -2.5f, R_V_LINE_TO, 2.21f, R_CUBIC_TO, 0.24f, 0.13f, 0.42f, 0.31f, 0.56f, 0.53f, R_CUBIC_TO, 0.13f, 0.23f, 0.2f,
    0.48f, 0.2f, 0.76f, R_CUBIC_TO, 0, 0.42f, -0.15f, 0.77f, -0.44f, 1.06f, ARC_TO, 1.45f, 1.45f, 0, 0, 1, 10, 18, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kUsbChromeRefreshRepList, kUsbChromeRefreshIcon, { kUsbChromeRefreshPath, std::size(kUsbChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kUsbOffChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 16, 18.13f, LINE_TO, 10.87f, 13, R_H_LINE_TO, -0.12f,
    R_V_LINE_TO, 2.21f, R_CUBIC_TO, 0.24f, 0.13f, 0.42f, 0.3f, 0.56f, 0.53f, R_CUBIC_TO, 0.13f, 0.23f, 0.2f, 0.49f, 0.2f, 0.76f, R_CUBIC_TO, 0, 0.41f, -0.15f,
    0.77f, -0.44f, 1.06f, ARC_TO, 1.46f, 1.46f, 0, 0, 1, 10, 18, R_CUBIC_TO, -0.41f, 0, -0.77f, -0.15f, -1.06f, -0.44f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 8.5f,
    16.5f, R_CUBIC_TO, 0, -0.28f, 0.07f, -0.53f, 0.2f, -0.75f, R_ARC_TO, 1.53f, 1.53f, 0, 0, 1, 0.55f, -0.54f, V_LINE_TO, 13, R_H_LINE_TO, -2.5f, R_CUBIC_TO,
    -0.41f, 0, -0.77f, -0.14f, -1.06f, -0.44f, R_ARC_TO, 1.44f, 1.44f, 0, 0, 1, -0.44f, -1.05f, V_LINE_TO, 9.79f, R_ARC_TO, 1.22f, 1.22f, 0, 0, 1, -0.55f,
    -0.53f, R_ARC_TO, 1.54f, 1.54f, 0, 0, 1, -0.2f, -0.77f, R_CUBIC_TO, 0, -0.23f, 0.06f, -0.46f, 0.18f, -0.68f, R_CUBIC_TO, 0.12f, -0.21f, 0.28f, -0.4f, 0.47f,
    -0.55f, LINE_TO, 1.88f, 4, R_LINE_TO, 1.06f, -1.06f, R_LINE_TO, 14.12f, 14.13f, CLOSE, R_MOVE_TO, -1.52f, -5.77f, R_LINE_TO, -1.23f, -1.23f, V_LINE_TO, 10,
    R_H_LINE_TO, -0.75f, V_LINE_TO, 7, R_H_LINE_TO, 3, R_V_LINE_TO, 3, R_H_LINE_TO, -0.75f, R_V_LINE_TO, 1.5f, R_CUBIC_TO, 0, 0.15f, -0.02f, 0.31f, -0.06f,
    0.45f, R_ARC_TO, 1.19f, 1.19f, 0, 0, 1, -0.21f, 0.41f, CLOSE, MOVE_TO, 6.75f, 11.5f, R_H_LINE_TO, 2.5f, R_V_LINE_TO, -0.12f, R_LINE_TO, -2.02f, -2.02f,
    R_ARC_TO, 1.31f, 1.31f, 0, 0, 1, -0.22f, 0.24f, R_ARC_TO, 6.41f, 6.41f, 0, 0, 1, -0.26f, 0.2f, CLOSE, R_MOVE_TO, 4, -2.87f, R_LINE_TO, -1.5f, -1.5f,
    V_LINE_TO, 5, H_LINE_TO, 7.5f, LINE_TO, 10, 2, R_LINE_TO, 2.5f, 3, R_H_LINE_TO, -1.75f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kUsbOffChromeRefreshRepList, kUsbOffChromeRefreshIcon, { kUsbOffChromeRefreshPath, std::size(kUsbOffChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kVideoLibraryPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 9.65f, 11.75f, LINE_TO, 14.55f, 8.6f, LINE_TO, 9.65f, 5.45f,
    V_LINE_TO, 11.75f, CLOSE, MOVE_TO, 7.2f, 14.2f, CUBIC_TO, 6.82f, 14.2f, 6.49f, 14.06f, 6.21f, 13.79f, CUBIC_TO, 5.94f, 13.51f, 5.8f, 13.19f, 5.8f, 12.8f,
    V_LINE_TO, 4.4f, CUBIC_TO, 5.8f, 4.01f, 5.94f, 3.69f, 6.21f, 3.41f, CUBIC_TO, 6.49f, 3.14f, 6.82f, 3, 7.2f, 3, H_LINE_TO, 15.6f, CUBIC_TO, 15.99f, 3,
    16.31f, 3.14f, 16.59f, 3.41f, CUBIC_TO, 16.86f, 3.69f, 17, 4.01f, 17, 4.4f, V_LINE_TO, 12.8f, CUBIC_TO, 17, 13.19f, 16.86f, 13.51f, 16.59f, 13.79f,
    CUBIC_TO, 16.31f, 14.06f, 15.99f, 14.2f, 15.6f, 14.2f, H_LINE_TO, 7.2f, CLOSE, MOVE_TO, 7.2f, 12.8f, H_LINE_TO, 15.6f, V_LINE_TO, 4.4f, H_LINE_TO, 7.2f,
    V_LINE_TO, 12.8f, CLOSE, MOVE_TO, 4.4f, 17, CUBIC_TO, 4.01f, 17, 3.69f, 16.86f, 3.41f, 16.59f, CUBIC_TO, 3.14f, 16.31f, 3, 15.99f, 3, 15.6f, V_LINE_TO,
    5.8f, H_LINE_TO, 4.4f, V_LINE_TO, 15.6f, H_LINE_TO, 14.2f, V_LINE_TO, 17, H_LINE_TO, 4.4f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kVideoLibraryRepList, kVideoLibraryIcon, { kVideoLibraryPath, std::size(kVideoLibraryPath) })
VECTOR_ICON_REP_TEMPLATE(kVideocamPath, MOVE_TO, 34, 21, R_V_LINE_TO, -7, R_CUBIC_TO, 0, -1.1f, -0.9f, -2, -2, -2, H_LINE_TO, 8, R_CUBIC_TO, -1.1f, 0, -2, 0.9f,
    -2, 2, R_V_LINE_TO, 20, R_CUBIC_TO, 0, 1.1f, 0.9f, 2, 2, 2, R_H_LINE_TO, 24, R_CUBIC_TO, 1.1f, 0, 2, -0.9f, 2, -2, R_V_LINE_TO, -7, R_LINE_TO, 8, 8,
    V_LINE_TO, 13, R_LINE_TO, -8, 8, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kVideocamRepList, kVideocamIcon, { kVideocamPath, std::size(kVideocamPath) })
VECTOR_ICON_REP_TEMPLATE(kVideocamChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 4.5f, 16, R_CUBIC_TO, -0.4f, 0, -0.75f, -0.15f, -1.05f,
    -0.45f, R_CUBIC_TO, -0.3f, -0.3f, -0.45f, -0.65f, -0.45f, -1.05f, R_V_LINE_TO, -9, R_CUBIC_TO, 0, -0.41f, 0.15f, -0.77f, 0.45f, -1.06f, ARC_TO, 1.45f,
    1.45f, 0, 0, 1, 4.5f, 4, R_H_LINE_TO, 9, R_CUBIC_TO, 0.41f, 0, 0.77f, 0.15f, 1.06f, 0.44f, R_CUBIC_TO, 0.29f, 0.29f, 0.44f, 0.65f, 0.44f, 1.06f, V_LINE_TO,
    9, R_LINE_TO, 3, -3, R_V_LINE_TO, 8, R_LINE_TO, -3, -3, R_V_LINE_TO, 3.5f, R_CUBIC_TO, 0, 0.4f, -0.15f, 0.75f, -0.44f, 1.05f, R_CUBIC_TO, -0.29f, 0.3f,
    -0.64f, 0.45f, -1.06f, 0.45f, CLOSE, R_MOVE_TO, 0, -1.5f, R_H_LINE_TO, 9, R_V_LINE_TO, -9, R_H_LINE_TO, -9, CLOSE, R_MOVE_TO, 0, 0, R_V_LINE_TO, -9, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kVideocamChromeRefreshRepList, kVideocamChromeRefreshIcon, { kVideocamChromeRefreshPath, std::size(kVideocamChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kVideocamOffPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 21, 18, LINE_TO, 9, 6, H_LINE_TO, 16, CUBIC_TO, 16.55f, 6, 17, 6.45f, 17, 7,
    V_LINE_TO, 10.5f, LINE_TO, 21, 6.5f, V_LINE_TO, 18, CLOSE, MOVE_TO, 21.8f, 21.6f, LINE_TO, 17, 16.8f, LINE_TO, 6.2f, 6, LINE_TO, 2.6f, 2.4f, LINE_TO, 1.2f,
    3.8f, LINE_TO, 3.53f, 6.13f, CUBIC_TO, 3.22f, 6.3f, 3, 6.62f, 3, 7, V_LINE_TO, 17, CUBIC_TO, 3, 17.55f, 3.45f, 18, 4, 18, H_LINE_TO, 15.4f, LINE_TO, 20.4f,
    23, LINE_TO, 21.8f, 21.6f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kVideocamOffRepList, kVideocamOffIcon, { kVideocamOffPath, std::size(kVideocamOffPath) })
VECTOR_ICON_REP_TEMPLATE(kVideocamOffChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, R_MOVE_TO, 18, 13.98f, R_LINE_TO, -3, -3, R_V_LINE_TO, 1.88f,
    R_LINE_TO, -1.5f, -1.5f, V_LINE_TO, 5.5f, H_LINE_TO, 7.63f, LINE_TO, 6.13f, 4, H_LINE_TO, 13.5f, R_CUBIC_TO, 0.41f, 0, 0.77f, 0.15f, 1.06f, 0.44f,
    R_CUBIC_TO, 0.29f, 0.29f, 0.44f, 0.65f, 0.44f, 1.06f, R_V_LINE_TO, 3.48f, R_LINE_TO, 3, -3, CLOSE, R_MOVE_TO, -1.27f, 4.83f, LINE_TO, 1.17f, 3.27f, LINE_TO,
    2.23f, 2.21f, LINE_TO, 17.79f, 17.75f, CLOSE, MOVE_TO, 10.56f, 8.42f, CLOSE, MOVE_TO, 8.46f, 10.52f, CLOSE, MOVE_TO, 4.04f, 4.04f, LINE_TO, 5.5f, 5.48f,
    R_H_LINE_TO, -1, R_V_LINE_TO, 9.02f, R_H_LINE_TO, 9, R_V_LINE_TO, -1.04f, R_LINE_TO, 1.5f, 1.5f, R_CUBIC_TO, -0.11f, 0.28f, -0.28f, 0.52f, -0.52f, 0.73f,
    R_CUBIC_TO, -0.24f, 0.21f, -0.56f, 0.31f, -0.98f, 0.31f, H_LINE_TO, 4.5f, R_ARC_TO, 1.45f, 1.45f, 0, 0, 1, -1.05f, -0.44f, R_CUBIC_TO, -0.3f, -0.29f,
    -0.45f, -0.65f, -0.45f, -1.06f, V_LINE_TO, 5.48f, R_CUBIC_TO, 0, -0.35f, 0.1f, -0.66f, 0.3f, -0.91f, R_CUBIC_TO, 0.2f, -0.25f, 0.45f, -0.42f, 0.74f, -0.52f,
    CLOSE)
VECTOR_ICON_TEMPLATE_CC(
    kVideocamOffChromeRefreshRepList, kVideocamOffChromeRefreshIcon, { kVideocamOffChromeRefreshPath, std::size(kVideocamOffChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kVideogameAssetPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 21, 6, H_LINE_TO, 3, R_CUBIC_TO, -1.1f, 0, -2, 0.9f, -2, 2, R_V_LINE_TO, 8,
    R_CUBIC_TO, 0, 1.1f, 0.9f, 2, 2, 2, R_H_LINE_TO, 18, R_CUBIC_TO, 1.1f, 0, 2, -0.9f, 2, -2, V_LINE_TO, 8, R_CUBIC_TO, 0, -1.1f, -0.9f, -2, -2, -2, CLOSE,
    R_MOVE_TO, -10, 7, H_LINE_TO, 8, R_V_LINE_TO, 3, H_LINE_TO, 6, R_V_LINE_TO, -3, H_LINE_TO, 3, R_V_LINE_TO, -2, R_H_LINE_TO, 3, V_LINE_TO, 8, R_H_LINE_TO, 2,
    R_V_LINE_TO, 3, R_H_LINE_TO, 3, R_V_LINE_TO, 2, CLOSE, R_MOVE_TO, 4.5f, 2, R_CUBIC_TO, -0.83f, 0, -1.5f, -0.67f, -1.5f, -1.5f, R_CUBIC_TO, 0, -0.83f, 0.67f,
    -1.5f, 1.5f, -1.5f, R_CUBIC_TO, 0.83f, 0, 1.5f, 0.67f, 1.5f, 1.5f, R_CUBIC_TO, 0, 0.83f, -0.67f, 1.5f, -1.5f, 1.5f, CLOSE, R_MOVE_TO, 4, -3, R_CUBIC_TO,
    -0.83f, 0, -1.5f, -0.67f, -1.5f, -1.5f, CUBIC_TO_SHORTHAND, 18.67f, 9, 19.5f, 9, R_CUBIC_TO, 0.83f, 0, 1.5f, 0.67f, 1.5f, 1.5f, R_CUBIC_TO, 0, 0.83f,
    -0.67f, 1.5f, -1.5f, 1.5f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kVideogameAssetRepList, kVideogameAssetIcon, { kVideogameAssetPath, std::size(kVideogameAssetPath) })
VECTOR_ICON_REP_TEMPLATE(kVideogameAssetChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 3.5f, 15, R_ARC_TO, 1.42f, 1.42f, 0, 0, 1, -1.06f,
    -0.45f, ARC_TO, 1.45f, 1.45f, 0, 0, 1, 2, 13.5f, R_V_LINE_TO, -7, R_CUBIC_TO, 0, -0.4f, 0.15f, -0.75f, 0.44f, -1.05f, CUBIC_TO, 2.73f, 5.15f, 3.09f, 5,
    3.5f, 5, R_H_LINE_TO, 13, R_CUBIC_TO, 0.41f, 0, 0.77f, 0.15f, 1.06f, 0.45f, R_CUBIC_TO, 0.29f, 0.3f, 0.44f, 0.65f, 0.44f, 1.05f, R_V_LINE_TO, 7, R_CUBIC_TO,
    0, 0.4f, -0.15f, 0.75f, -0.44f, 1.05f, R_CUBIC_TO, -0.29f, 0.3f, -0.64f, 0.45f, -1.06f, 0.45f, CLOSE, R_MOVE_TO, 0, -1.5f, R_H_LINE_TO, 13, R_V_LINE_TO, -7,
    R_H_LINE_TO, -13, CLOSE, R_MOVE_TO, 2.54f, -1, R_H_LINE_TO, 1.5f, R_V_LINE_TO, -1.75f, R_H_LINE_TO, 1.75f, R_V_LINE_TO, -1.5f, R_H_LINE_TO, -1.75f,
    V_LINE_TO, 7.5f, R_H_LINE_TO, -1.5f, R_V_LINE_TO, 1.75f, R_H_LINE_TO, -1.75f, R_V_LINE_TO, 1.5f, R_H_LINE_TO, 1.75f, CLOSE, MOVE_TO, 12, 12.25f, R_CUBIC_TO,
    0.35f, 0, 0.64f, -0.12f, 0.89f, -0.36f, R_CUBIC_TO, 0.24f, -0.25f, 0.36f, -0.54f, 0.36f, -0.89f, R_CUBIC_TO, 0, -0.35f, -0.12f, -0.64f, -0.36f, -0.89f,
    ARC_TO, 1.22f, 1.22f, 0, 0, 0, 12, 9.75f, R_CUBIC_TO, -0.35f, 0, -0.64f, 0.12f, -0.89f, 0.36f, R_CUBIC_TO, -0.24f, 0.25f, -0.36f, 0.54f, -0.36f, 0.89f,
    R_CUBIC_TO, 0, 0.35f, 0.12f, 0.64f, 0.36f, 0.89f, R_CUBIC_TO, 0.25f, 0.24f, 0.54f, 0.36f, 0.89f, 0.36f, CLOSE, R_MOVE_TO, 2.5f, -2, R_CUBIC_TO, 0.35f, 0,
    0.64f, -0.12f, 0.89f, -0.36f, R_CUBIC_TO, 0.24f, -0.25f, 0.36f, -0.54f, 0.36f, -0.89f, R_CUBIC_TO, 0, -0.35f, -0.12f, -0.64f, -0.36f, -0.89f, R_ARC_TO,
    1.22f, 1.22f, 0, 0, 0, -0.89f, -0.36f, R_CUBIC_TO, -0.35f, 0, -0.64f, 0.12f, -0.89f, 0.36f, R_CUBIC_TO, -0.24f, 0.25f, -0.36f, 0.54f, -0.36f, 0.89f,
    R_CUBIC_TO, 0, 0.35f, 0.12f, 0.64f, 0.36f, 0.89f, R_CUBIC_TO, 0.25f, 0.24f, 0.54f, 0.36f, 0.89f, 0.36f, CLOSE, R_MOVE_TO, -11, 3.25f, R_V_LINE_TO, -7,
    CLOSE)
VECTOR_ICON_TEMPLATE_CC(
    kVideogameAssetChromeRefreshRepList, kVideogameAssetChromeRefreshIcon, { kVideogameAssetChromeRefreshPath, std::size(kVideogameAssetChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kVideogameAssetOffChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 14.5f, 10.25f, R_CUBIC_TO, -0.35f, 0, -0.64f,
    -0.12f, -0.89f, -0.36f, ARC_TO, 1.22f, 1.22f, 0, 0, 1, 13.25f, 9, R_CUBIC_TO, 0, -0.35f, 0.12f, -0.64f, 0.36f, -0.89f, R_CUBIC_TO, 0.25f, -0.24f, 0.54f,
    -0.36f, 0.89f, -0.36f, R_CUBIC_TO, 0.35f, 0, 0.64f, 0.12f, 0.89f, 0.36f, R_CUBIC_TO, 0.24f, 0.25f, 0.36f, 0.54f, 0.36f, 0.89f, R_CUBIC_TO, 0, 0.35f, -0.12f,
    0.64f, -0.36f, 0.89f, R_CUBIC_TO, -0.25f, 0.24f, -0.54f, 0.36f, -0.89f, 0.36f, CLOSE, R_MOVE_TO, -6.64f, -0.17f, CLOSE, MOVE_TO, 6, 12.5f, R_V_LINE_TO,
    -1.75f, H_LINE_TO, 4.25f, R_V_LINE_TO, -1.5f, H_LINE_TO, 6, V_LINE_TO, 7.5f, R_H_LINE_TO, 1.5f, R_V_LINE_TO, 1.75f, R_H_LINE_TO, 1.75f, R_V_LINE_TO, 1.5f,
    H_LINE_TO, 7.5f, R_V_LINE_TO, 1.75f, CLOSE, MOVE_TO, 3.5f, 15, R_CUBIC_TO, -0.4f, 0, -0.75f, -0.15f, -1.05f, -0.45f, R_CUBIC_TO, -0.3f, -0.3f, -0.45f,
    -0.65f, -0.45f, -1.05f, R_V_LINE_TO, -7, R_CUBIC_TO, 0, -0.4f, 0.14f, -0.75f, 0.42f, -1.05f, R_CUBIC_TO, 0.28f, -0.3f, 0.62f, -0.45f, 1.01f, -0.45f,
    H_LINE_TO, 5, R_LINE_TO, 1.5f, 1.5f, R_H_LINE_TO, -3, R_V_LINE_TO, 7, R_H_LINE_TO, 7.88f, LINE_TO, 1.88f, 4, R_LINE_TO, 1.06f, -1.06f, R_LINE_TO, 14.12f,
    14.13f, LINE_TO, 16, 18.13f, LINE_TO, 12.88f, 15, CLOSE, MOVE_TO, 18, 13.5f, R_CUBIC_TO, 0, 0.32f, -0.08f, 0.61f, -0.25f, 0.86f, R_CUBIC_TO, -0.17f, 0.25f,
    -0.41f, 0.43f, -0.73f, 0.54f, R_LINE_TO, -0.52f, -0.52f, V_LINE_TO, 6.5f, H_LINE_TO, 8.63f, LINE_TO, 7.13f, 5, H_LINE_TO, 16.5f, R_CUBIC_TO, 0.4f, 0, 0.75f,
    0.15f, 1.05f, 0.45f, R_CUBIC_TO, 0.3f, 0.3f, 0.45f, 0.65f, 0.45f, 1.05f, CLOSE, R_MOVE_TO, -5.44f, -3.06f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kVideogameAssetOffChromeRefreshRepList, kVideogameAssetOffChromeRefreshIcon,
    { kVideogameAssetOffChromeRefreshPath, std::size(kVideogameAssetOffChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kViewInArChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, R_MOVE_TO, 9.25f, 16.42f, R_LINE_TO, -4.5f, -2.56f, R_ARC_TO,
    1.69f, 1.69f, 0, 0, 1, -0.55f, -0.57f, R_ARC_TO, 1.43f, 1.43f, 0, 0, 1, -0.2f, -0.75f, V_LINE_TO, 7.44f, R_CUBIC_TO, 0, -0.27f, 0.07f, -0.52f, 0.2f, -0.75f,
    R_ARC_TO, 1.51f, 1.51f, 0, 0, 1, 0.56f, -0.54f, R_LINE_TO, 4.5f, -2.58f, R_ARC_TO, 1.45f, 1.45f, 0, 0, 1, 0.75f, -0.21f, R_CUBIC_TO, 0.27f, 0, 0.52f, 0.07f,
    0.75f, 0.21f, R_LINE_TO, 4.5f, 2.58f, R_CUBIC_TO, 0.24f, 0.14f, 0.42f, 0.32f, 0.56f, 0.54f, R_CUBIC_TO, 0.13f, 0.23f, 0.2f, 0.48f, 0.2f, 0.75f, R_V_LINE_TO,
    5.13f, R_ARC_TO, 1.4f, 1.4f, 0, 0, 1, -0.2f, 0.73f, R_ARC_TO, 1.71f, 1.71f, 0, 0, 1, -0.55f, 0.56f, R_LINE_TO, -4.5f, 2.56f, R_ARC_TO, 1.47f, 1.47f, 0, 0,
    1, -1.5f, 0, CLOSE, R_MOVE_TO, 0, -1.71f, R_V_LINE_TO, -4.29f, LINE_TO, 5.5f, 8.17f, R_V_LINE_TO, 4.39f, CLOSE, R_MOVE_TO, 1.5f, 0, R_LINE_TO, 3.75f,
    -2.14f, V_LINE_TO, 8.19f, R_LINE_TO, -3.75f, 2.25f, CLOSE, MOVE_TO, 2, 6, V_LINE_TO, 3.5f, R_CUBIC_TO, 0, -0.42f, 0.15f, -0.77f, 0.44f, -1.06f, ARC_TO,
    1.44f, 1.44f, 0, 0, 1, 3.5f, 2, H_LINE_TO, 6, R_V_LINE_TO, 1.5f, H_LINE_TO, 3.5f, V_LINE_TO, 6, CLOSE, R_MOVE_TO, 4, 12, H_LINE_TO, 3.5f, R_CUBIC_TO,
    -0.42f, 0, -0.77f, -0.15f, -1.06f, -0.44f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 2, 16.5f, V_LINE_TO, 14, R_H_LINE_TO, 1.5f, R_V_LINE_TO, 2.5f, H_LINE_TO, 6,
    CLOSE, R_MOVE_TO, 8, 0, R_V_LINE_TO, -1.5f, R_H_LINE_TO, 2.5f, V_LINE_TO, 14, H_LINE_TO, 18, R_V_LINE_TO, 2.5f, R_CUBIC_TO, 0, 0.42f, -0.15f, 0.77f, -0.44f,
    1.06f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 16.5f, 18, CLOSE, R_MOVE_TO, 2.5f, -12, V_LINE_TO, 3.5f, H_LINE_TO, 14, V_LINE_TO, 2, R_H_LINE_TO, 2.5f, R_CUBIC_TO,
    0.42f, 0, 0.77f, 0.15f, 1.06f, 0.44f, R_CUBIC_TO, 0.29f, 0.29f, 0.44f, 0.65f, 0.44f, 1.06f, V_LINE_TO, 6, CLOSE, MOVE_TO, 10, 9.13f, R_LINE_TO, 3.63f,
    -2.17f, LINE_TO, 10, 4.88f, LINE_TO, 6.38f, 6.96f, CLOSE, R_MOVE_TO, 0, 0.83f, CLOSE, R_MOVE_TO, 0, -0.83f, CLOSE, R_MOVE_TO, 0.75f, 1.31f, CLOSE,
    R_MOVE_TO, -1.5f, -0.02f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kViewInArChromeRefreshRepList, kViewInArChromeRefreshIcon, { kViewInArChromeRefreshPath, std::size(kViewInArChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kViewInArOffChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 11.33f, 9.21f, CLOSE, MOVE_TO, 10, 10, CLOSE,
    R_MOVE_TO, 5.65f, 3.52f, LINE_TO, 6.98f, 4.86f, R_LINE_TO, 2.27f, -1.29f, R_ARC_TO, 1.45f, 1.45f, 0, 0, 1, 0.75f, -0.21f, R_CUBIC_TO, 0.27f, 0, 0.52f,
    0.07f, 0.75f, 0.21f, R_LINE_TO, 4.5f, 2.58f, ARC_TO, 1.48f, 1.48f, 0, 0, 1, 16, 7.44f, R_V_LINE_TO, 5.13f, R_CUBIC_TO, 0, 0.18f, -0.03f, 0.34f, -0.1f, 0.5f,
    R_CUBIC_TO, -0.06f, 0.16f, -0.15f, 0.31f, -0.26f, 0.45f, CLOSE, MOVE_TO, 9.25f, 16.42f, R_LINE_TO, -4.5f, -2.56f, R_ARC_TO, 1.68f, 1.68f, 0, 0, 1, -0.55f,
    -0.56f, R_ARC_TO, 1.44f, 1.44f, 0, 0, 1, -0.2f, -0.75f, V_LINE_TO, 7.44f, R_ARC_TO, 1.49f, 1.49f, 0, 0, 1, 0.75f, -1.29f, R_LINE_TO, 0.9f, -0.5f, R_LINE_TO,
    8.71f, 8.71f, R_LINE_TO, -3.6f, 2.06f, R_ARC_TO, 1.47f, 1.47f, 0, 0, 1, -1.5f, 0, CLOSE, R_MOVE_TO, 1.54f, -7.75f, CLOSE, R_MOVE_TO, -1.54f, 1.75f, CLOSE,
    R_MOVE_TO, 2.63f, -0.67f, CLOSE, R_MOVE_TO, -1.12f, 1, CLOSE, MOVE_TO, 8.11f, 5.98f, R_LINE_TO, 2.69f, 2.69f, R_LINE_TO, 2.83f, -1.71f, LINE_TO, 10, 4.88f,
    CLOSE, R_MOVE_TO, 1.15f, 8.73f, R_V_LINE_TO, -4.29f, LINE_TO, 5.5f, 8.17f, R_V_LINE_TO, 4.39f, CLOSE, R_MOVE_TO, 5.25f, -2.33f, V_LINE_TO, 8.19f, LINE_TO,
    11.88f, 9.75f, CLOSE, R_MOVE_TO, -3.75f, 2.33f, R_LINE_TO, 2.52f, -1.44f, R_LINE_TO, -2.52f, -2.52f, CLOSE, R_MOVE_TO, 5.98f, 4.13f, LINE_TO, 15.9f, 18,
    H_LINE_TO, 14, R_V_LINE_TO, -1.5f, R_H_LINE_TO, 0.56f, R_V_LINE_TO, 0.17f, LINE_TO, 3.21f, 5.31f, H_LINE_TO, 3.5f, V_LINE_TO, 6, H_LINE_TO, 2, V_LINE_TO,
    4.11f, R_LINE_TO, -0.83f, -0.83f, LINE_TO, 2.23f, 2.23f, R_LINE_TO, 15.54f, 15.54f, CLOSE, MOVE_TO, 18, 14, R_V_LINE_TO, 1.88f, R_LINE_TO, -1.5f, -1.5f,
    V_LINE_TO, 14, CLOSE, MOVE_TO, 6, 2, R_V_LINE_TO, 1.5f, R_H_LINE_TO, -0.37f, LINE_TO, 4.13f, 2, CLOSE, R_MOVE_TO, 0, 16, H_LINE_TO, 3.5f, R_CUBIC_TO,
    -0.42f, 0, -0.77f, -0.15f, -1.06f, -0.44f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 2, 16.5f, V_LINE_TO, 14, R_H_LINE_TO, 1.5f, R_V_LINE_TO, 2.5f, H_LINE_TO, 6,
    CLOSE, MOVE_TO, 16.5f, 6, V_LINE_TO, 3.5f, H_LINE_TO, 14, V_LINE_TO, 2, R_H_LINE_TO, 2.5f, R_CUBIC_TO, 0.42f, 0, 0.77f, 0.15f, 1.06f, 0.44f, R_CUBIC_TO,
    0.29f, 0.29f, 0.44f, 0.65f, 0.44f, 1.06f, V_LINE_TO, 6, CLOSE)
VECTOR_ICON_TEMPLATE_CC(
    kViewInArOffChromeRefreshRepList, kViewInArOffChromeRefreshIcon, { kViewInArOffChromeRefreshPath, std::size(kViewInArOffChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kVisibilityPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 12, 7, R_CUBIC_TO, -2.48f, 0, -4.5f, 2.02f, -4.5f, 4.5f, CUBIC_TO_SHORTHAND, 9.52f,
    16, 12, 16, R_CUBIC_TO, 2.48f, 0, 4.5f, -2.02f, 4.5f, -4.5f, CUBIC_TO_SHORTHAND, 14.48f, 7, 12, 7, CLOSE, R_MOVE_TO, 0, 7.2f, R_CUBIC_TO, -1.49f, 0, -2.7f,
    -1.21f, -2.7f, -2.7f, R_CUBIC_TO, 0, -1.49f, 1.21f, -2.7f, 2.7f, -2.7f, R_CUBIC_TO, 1.49f, 0, 2.7f, 1.21f, 2.7f, 2.7f, R_CUBIC_TO, 0, 1.49f, -1.21f, 2.7f,
    -2.7f, 2.7f, CLOSE, MOVE_TO, 12, 4, CUBIC_TO, 7, 4, 2.73f, 7.11f, 1, 11.5f, CUBIC_TO, 2.73f, 15.89f, 7, 19, 12, 19, R_CUBIC_TO, 5, 0, 9.27f, -3.11f, 11,
    -7.5f, CUBIC_TO, 21.27f, 7.11f, 17, 4, 12, 4, CLOSE, R_MOVE_TO, 0, 13, R_CUBIC_TO, -3.79f, 0, -7.17f, -2.13f, -8.82f, -5.5f, CUBIC_TO, 4.83f, 8.13f, 8.21f,
    6, 12, 6, R_CUBIC_TO, 3.79f, 0, 7.17f, 2.13f, 8.82f, 5.5f, CUBIC_TO, 19.17f, 14.87f, 15.79f, 17, 12, 17, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kVisibilityRepList, kVisibilityIcon, { kVisibilityPath, std::size(kVisibilityPath) })
VECTOR_ICON_REP_TEMPLATE(kVisibilityOffPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 10.58f, 7.25f, R_LINE_TO, 1.56f, 1.56f, R_CUBIC_TO, 1.38f, 0.07f, 2.47f, 1.17f,
    2.54f, 2.54f, R_LINE_TO, 1.56f, 1.56f, R_CUBIC_TO, 0.16f, -0.44f, 0.26f, -0.91f, 0.26f, -1.41f, CUBIC_TO, 16.5f, 9.02f, 14.48f, 7, 12, 7, R_CUBIC_TO, -0.5f,
    0, -0.97f, 0.1f, -1.42f, 0.25f, CLOSE, MOVE_TO, 12, 6, R_CUBIC_TO, 3.79f, 0, 7.17f, 2.13f, 8.82f, 5.5f, R_CUBIC_TO, -0.64f, 1.32f, -1.56f, 2.44f, -2.66f,
    3.33f, R_LINE_TO, 1.42f, 1.42f, R_CUBIC_TO, 1.51f, -1.26f, 2.7f, -2.89f, 3.43f, -4.74f, CUBIC_TO, 21.27f, 7.11f, 17, 4, 12, 4, R_CUBIC_TO, -1.4f, 0, -2.73f,
    0.25f, -3.98f, 0.7f, R_LINE_TO, 1.61f, 1.6f, CUBIC_TO, 10.4f, 6.12f, 11.19f, 6, 12, 6, CLOSE, R_MOVE_TO, 4.43f, 9.93f, R_LINE_TO, -1.25f, -1.25f, R_LINE_TO,
    -1.27f, -1.27f, R_LINE_TO, -3.82f, -3.82f, R_LINE_TO, -1.27f, -1.27f, R_LINE_TO, -1.25f, -1.25f, R_LINE_TO, -1.48f, -1.48f, R_LINE_TO, -2.78f, -2.78f,
    R_LINE_TO, -1.42f, 1.41f, R_LINE_TO, 2.53f, 2.53f, CUBIC_TO, 2.92f, 8.02f, 1.73f, 9.64f, 1, 11.5f, CUBIC_TO, 2.73f, 15.89f, 7, 19, 12, 19, R_CUBIC_TO, 1.4f,
    0, 2.73f, -0.25f, 3.98f, -0.7f, R_LINE_TO, 4.3f, 4.3f, R_LINE_TO, 1.41f, -1.41f, R_LINE_TO, -3.78f, -3.78f, R_LINE_TO, -1.48f, -1.48f, CLOSE, R_MOVE_TO,
    -4.57f, -1.74f, R_CUBIC_TO, -1.38f, -0.07f, -2.47f, -1.17f, -2.54f, -2.54f, R_LINE_TO, 2.54f, 2.54f, CLOSE, MOVE_TO, 12, 17, R_CUBIC_TO, -3.79f, 0, -7.17f,
    -2.13f, -8.82f, -5.5f, R_CUBIC_TO, 0.64f, -1.32f, 1.56f, -2.44f, 2.66f, -3.33f, R_LINE_TO, 1.91f, 1.91f, R_CUBIC_TO, -0.15f, 0.45f, -0.25f, 0.92f, -0.25f,
    1.42f, R_CUBIC_TO, 0, 2.48f, 2.02f, 4.5f, 4.5f, 4.5f, R_CUBIC_TO, 0.5f, 0, 0.97f, -0.1f, 1.42f, -0.25f, R_LINE_TO, 0.95f, 0.95f, R_CUBIC_TO, -0.77f, 0.18f,
    -1.56f, 0.3f, -2.37f, 0.3f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kVisibilityOffRepList, kVisibilityOffIcon, { kVisibilityOffPath, std::size(kVisibilityOffPath) })
VECTOR_ICON_REP_TEMPLATE(kVolumeOffChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, R_MOVE_TO, 16, 18.13f, R_LINE_TO, -2.23f, -2.23f, R_ARC_TO,
    6.93f, 6.93f, 0, 0, 1, -1.09f, 0.55f, R_CUBIC_TO, -0.42f, 0.17f, -0.82f, 0.3f, -1.18f, 0.38f, R_V_LINE_TO, -1.54f, R_CUBIC_TO, 0.17f, -0.07f, 0.36f, -0.15f,
    0.59f, -0.24f, R_CUBIC_TO, 0.23f, -0.09f, 0.42f, -0.18f, 0.57f, -0.26f, LINE_TO, 10, 12.13f, R_V_LINE_TO, 3.9f, R_LINE_TO, -4, -4, H_LINE_TO, 3,
    R_V_LINE_TO, -4, R_H_LINE_TO, 2.88f, R_LINE_TO, -4, -4.02f, R_LINE_TO, 1.06f, -1.06f, R_LINE_TO, 14.12f, 14.13f, CLOSE, R_MOVE_TO, -0.12f, -4.36f,
    R_LINE_TO, -1.08f, -1.08f, R_CUBIC_TO, 0.22f, -0.4f, 0.4f, -0.83f, 0.52f, -1.28f, R_CUBIC_TO, 0.12f, -0.45f, 0.19f, -0.91f, 0.19f, -1.39f, R_ARC_TO, 5.27f,
    5.27f, 0, 0, 0, -1.11f, -3.3f, ARC_TO, 5.64f, 5.64f, 0, 0, 0, 11.5f, 4.73f, V_LINE_TO, 3.19f, R_CUBIC_TO, 1.63f, 0.32f, 2.95f, 1.13f, 3.97f, 2.42f,
    CUBIC_TO, 16.49f, 6.9f, 17, 8.37f, 17, 10.02f, R_CUBIC_TO, 0, 0.67f, -0.1f, 1.32f, -0.29f, 1.95f, R_ARC_TO, 7.31f, 7.31f, 0, 0, 1, -0.83f, 1.8f, CLOSE,
    R_MOVE_TO, -2.58f, -2.58f, LINE_TO, 11.5f, 9.4f, R_V_LINE_TO, -2.54f, R_ARC_TO, 3.21f, 3.21f, 0, 0, 1, 1.47f, 1.28f, R_ARC_TO, 3.51f, 3.51f, 0, 0, 1, 0.53f,
    1.88f, R_CUBIC_TO, 0, 0.2f, -0.02f, 0.39f, -0.04f, 0.59f, R_ARC_TO, 2.37f, 2.37f, 0, 0, 1, -0.16f, 0.58f, CLOSE, MOVE_TO, 10, 7.89f, LINE_TO, 8.06f, 5.96f,
    LINE_TO, 10, 4.02f, CLOSE, R_MOVE_TO, -1.5f, 4.5f, R_V_LINE_TO, -1.77f, LINE_TO, 7, 9.13f, R_LINE_TO, -0.37f, 0.4f, H_LINE_TO, 4.5f, R_V_LINE_TO, 1,
    R_H_LINE_TO, 2.13f, CLOSE, R_MOVE_TO, -0.75f, -2.52f, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kVolumeOffChromeRefresh16Path, CANVAS_DIMENSIONS, 16, FILL_RULE_NONZERO, R_MOVE_TO, 12.84f, 14.63f, R_LINE_TO, -1.79f, -1.8f, R_ARC_TO,
    5.1f, 5.1f, 0, 0, 1, -0.84f, 0.41f, R_CUBIC_TO, -0.33f, 0.13f, -0.63f, 0.23f, -0.91f, 0.29f, R_V_LINE_TO, -1.3f, R_CUBIC_TO, 0.11f, -0.05f, 0.25f, -0.11f,
    0.41f, -0.17f, R_CUBIC_TO, 0.16f, -0.07f, 0.3f, -0.12f, 0.41f, -0.18f, LINE_TO, 8.1f, 9.86f, R_V_LINE_TO, 3.28f, LINE_TO, 4.71f, 9.75f, H_LINE_TO, 2.23f,
    V_LINE_TO, 6.28f, H_LINE_TO, 4.54f, LINE_TO, 1.36f, 3.07f, R_LINE_TO, 0.89f, -0.89f, R_LINE_TO, 11.48f, 11.56f, CLOSE, R_MOVE_TO, 0, -3.57f, R_LINE_TO,
    -0.91f, -0.92f, R_CUBIC_TO, 0.18f, -0.32f, 0.32f, -0.66f, 0.42f, -1.02f, R_CUBIC_TO, 0.1f, -0.36f, 0.15f, -0.73f, 0.15f, -1.1f, R_ARC_TO, 4.2f, 4.2f, 0, 0,
    0, -0.89f, -2.63f, R_ARC_TO, 4.57f, 4.57f, 0, 0, 0, -2.3f, -1.6f, V_LINE_TO, 2.48f, R_ARC_TO, 5.31f, 5.31f, 0, 0, 1, 3.22f, 1.96f, R_ARC_TO, 5.6f, 5.6f, 0,
    0, 1, 1.24f, 3.58f, R_CUBIC_TO, 0, 0.55f, -0.08f, 1.07f, -0.24f, 1.58f, R_CUBIC_TO, -0.16f, 0.51f, -0.39f, 1, -0.68f, 1.46f, CLOSE, MOVE_TO, 10.78f, 8.98f,
    R_LINE_TO, -1.48f, -1.49f, V_LINE_TO, 5.43f, R_ARC_TO, 2.82f, 2.82f, 0, 0, 1, 1.66f, 2.58f, R_CUBIC_TO, 0, 0.16f, -0.02f, 0.33f, -0.04f, 0.49f, R_ARC_TO,
    1.79f, 1.79f, 0, 0, 1, -0.14f, 0.48f, CLOSE, R_MOVE_TO, -2.68f, -2.7f, LINE_TO, 6.42f, 4.58f, R_LINE_TO, 1.69f, -1.68f, CLOSE, MOVE_TO, 6.72f, 9.8f,
    V_LINE_TO, 8.46f, LINE_TO, 5.61f, 7.35f, R_LINE_TO, -0.3f, 0.32f, H_LINE_TO, 3.62f, R_V_LINE_TO, 0.7f, R_H_LINE_TO, 1.67f, CLOSE, R_MOVE_TO, -0.55f, -1.9f,
    CLOSE)
VECTOR_ICON_TEMPLATE_CC(kVolumeOffChromeRefreshRepList, kVolumeOffChromeRefreshIcon, { kVolumeOffChromeRefreshPath, std::size(kVolumeOffChromeRefreshPath) },
    { kVolumeOffChromeRefresh16Path, std::size(kVolumeOffChromeRefresh16Path) })
VECTOR_ICON_REP_TEMPLATE(kVolumeUpPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 2, 5.95f, R_V_LINE_TO, 4.1f, R_H_LINE_TO, 2.67f, LINE_TO, 8, 13.47f, V_LINE_TO, 2.53f,
    R_LINE_TO, -3.33f, 3.42f, H_LINE_TO, 2, CLOSE, MOVE_TO, 11, 8, R_CUBIC_TO, 0, -1.21f, -0.68f, -2.25f, -1.67f, -2.76f, R_V_LINE_TO, 5.51f, CUBIC_TO, 10.32f,
    10.25f, 11, 9.21f, 11, 8, CLOSE, MOVE_TO, 9.33f, 2, R_V_LINE_TO, 1.41f, R_CUBIC_TO, 1.93f, 0.59f, 3.33f, 2.42f, 3.33f, 4.59f, R_CUBIC_TO, 0, 2.17f, -1.41f,
    4, -3.33f, 4.59f, V_LINE_TO, 14, CUBIC_TO, 12.01f, 13.38f, 14, 10.93f, 14, 8, R_CUBIC_TO, 0, -2.93f, -1.99f, -5.38f, -4.67f, -6, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kVolumeUpRepList, kVolumeUpIcon, { kVolumeUpPath, std::size(kVolumeUpPath) })
VECTOR_ICON_REP_TEMPLATE(kVolumeUpChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 11.5f, 16.83f, V_LINE_TO, 15.27f, R_ARC_TO, 5.18f,
    5.18f, 0, 0, 0, 2.9f, -1.94f, R_CUBIC_TO, 0.74f, -0.98f, 1.11f, -2.08f, 1.11f, -3.32f, R_CUBIC_TO, 0, -1.24f, -0.37f, -2.34f, -1.11f, -3.3f, ARC_TO, 5.67f,
    5.67f, 0, 0, 0, 11.5f, 4.71f, V_LINE_TO, 3.15f, R_CUBIC_TO, 1.61f, 0.35f, 2.93f, 1.16f, 3.96f, 2.44f, CUBIC_TO, 16.48f, 6.86f, 17, 8.33f, 17, 9.98f,
    R_CUBIC_TO, 0, 1.65f, -0.51f, 3.12f, -1.53f, 4.41f, R_CUBIC_TO, -1.02f, 1.29f, -2.34f, 2.1f, -3.97f, 2.44f, CLOSE, MOVE_TO, 3, 11.98f, R_V_LINE_TO, -4,
    R_H_LINE_TO, 3, R_LINE_TO, 4, -4, R_V_LINE_TO, 12, R_LINE_TO, -4, -4, CLOSE, R_MOVE_TO, 8.5f, 1.15f, V_LINE_TO, 6.83f, R_CUBIC_TO, 0.63f, 0.28f, 1.12f,
    0.71f, 1.47f, 1.28f, R_CUBIC_TO, 0.36f, 0.57f, 0.53f, 1.19f, 0.53f, 1.88f, R_CUBIC_TO, 0, 0.68f, -0.18f, 1.29f, -0.53f, 1.86f, R_ARC_TO, 3.3f, 3.3f, 0, 0,
    1, -1.47f, 1.28f, CLOSE, R_MOVE_TO, -3, -5.52f, LINE_TO, 6.63f, 9.48f, H_LINE_TO, 4.5f, R_V_LINE_TO, 1, R_H_LINE_TO, 2.13f, LINE_TO, 8.5f, 12.36f, CLOSE,
    MOVE_TO, 6.61f, 9.96f, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kVolumeUpChromeRefresh16Path, CANVAS_DIMENSIONS, 16, FILL_RULE_NONZERO, MOVE_TO, 9.31f, 13.54f, R_V_LINE_TO, -1.32f, R_ARC_TO, 4.19f,
    4.19f, 0, 0, 0, 2.31f, -1.56f, R_ARC_TO, 4.28f, 4.28f, 0, 0, 0, 0.89f, -2.65f, R_ARC_TO, 4.2f, 4.2f, 0, 0, 0, -0.89f, -2.64f, R_ARC_TO, 4.58f, 4.58f, 0, 0,
    0, -2.3f, -1.6f, V_LINE_TO, 2.45f, R_CUBIC_TO, 1.3f, 0.28f, 2.38f, 0.94f, 3.21f, 1.97f, R_CUBIC_TO, 0.84f, 1.03f, 1.25f, 2.22f, 1.25f, 3.56f, R_ARC_TO,
    5.57f, 5.57f, 0, 0, 1, -1.24f, 3.57f, R_CUBIC_TO, -0.83f, 1.04f, -1.9f, 1.7f, -3.21f, 1.98f, CLOSE, MOVE_TO, 2.24f, 9.72f, V_LINE_TO, 6.25f, R_H_LINE_TO,
    2.48f, R_LINE_TO, 3.39f, -3.39f, R_V_LINE_TO, 10.25f, LINE_TO, 4.72f, 9.72f, CLOSE, R_MOVE_TO, 7.07f, 0.83f, V_LINE_TO, 5.42f, R_CUBIC_TO, 0.51f, 0.23f,
    0.91f, 0.58f, 1.21f, 1.04f, R_CUBIC_TO, 0.3f, 0.46f, 0.45f, 0.97f, 0.45f, 1.54f, R_CUBIC_TO, 0, 0.55f, -0.15f, 1.06f, -0.45f, 1.52f, R_CUBIC_TO, -0.3f,
    0.46f, -0.7f, 0.81f, -1.21f, 1.04f, CLOSE, MOVE_TO, 6.72f, 6.2f, R_LINE_TO, -1.43f, 1.43f, H_LINE_TO, 3.62f, R_V_LINE_TO, 0.7f, H_LINE_TO, 5.29f, LINE_TO,
    6.72f, 9.77f, CLOSE, MOVE_TO, 5.25f, 7.97f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kVolumeUpChromeRefreshRepList, kVolumeUpChromeRefreshIcon, { kVolumeUpChromeRefreshPath, std::size(kVolumeUpChromeRefreshPath) },
    { kVolumeUpChromeRefresh16Path, std::size(kVolumeUpChromeRefresh16Path) })
VECTOR_ICON_REP_TEMPLATE(kVrHeadsetPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 20.91f, 6.68f, ARC_TO, 2.54f, 2.54f, 0, 0, 0, 19.16f, 6, H_LINE_TO, 4.9f, R_CUBIC_TO,
    -0.66f, 0, -1.28f, 0.24f, -1.75f, 0.68f, R_ARC_TO, 2.23f, 2.23f, 0, 0, 0, -0.72f, 1.64f, R_V_LINE_TO, 7.37f, R_CUBIC_TO, 0, 0.62f, 0.26f, 1.2f, 0.72f,
    1.64f, ARC_TO, 2.54f, 2.54f, 0, 0, 0, 4.9f, 18, R_H_LINE_TO, 3.42f, R_CUBIC_TO, 0.45f, 0, 0.88f, -0.11f, 1.27f, -0.33f, R_CUBIC_TO, 0.38f, -0.22f, 0.7f,
    -0.52f, 0.91f, -0.89f, R_LINE_TO, 0.97f, -1.68f, R_ARC_TO, 0.57f, 0.57f, 0, 0, 1, 0.16f, -0.74f, R_ARC_TO, 0.67f, 0.67f, 0, 0, 1, 0.81f, 0, R_CUBIC_TO,
    0.24f, 0.18f, 0.3f, 0.49f, 0.16f, 0.74f, R_LINE_TO, 0.97f, 1.68f, R_CUBIC_TO, 0.21f, 0.37f, 0.52f, 0.68f, 0.91f, 0.89f, R_CUBIC_TO, 0.38f, 0.22f, 0.82f,
    0.33f, 1.27f, 0.33f, R_H_LINE_TO, 3.42f, R_CUBIC_TO, 0.66f, 0, 1.28f, -0.24f, 1.75f, -0.68f, R_CUBIC_TO, 0.47f, -0.44f, 0.72f, -1.02f, 0.72f, -1.64f,
    R_V_LINE_TO, -7.37f, R_CUBIC_TO, 0, -0.62f, -0.26f, -1.2f, -0.72f, -1.64f, CLOSE, MOVE_TO, 7.83f, 13.8f, R_CUBIC_TO, -1.33f, 0, -2.4f, -1.08f, -2.4f, -2.4f,
    R_CUBIC_TO, 0, -1.32f, 1.08f, -2.4f, 2.4f, -2.4f, R_CUBIC_TO, 1.32f, 0, 2.4f, 1.08f, 2.4f, 2.4f, R_CUBIC_TO, 0, 1.32f, -1.07f, 2.4f, -2.4f, 2.4f, CLOSE,
    R_MOVE_TO, 8.4f, 0, R_CUBIC_TO, -1.33f, 0, -2.4f, -1.08f, -2.4f, -2.4f, R_CUBIC_TO, 0, -1.32f, 1.08f, -2.4f, 2.4f, -2.4f, R_CUBIC_TO, 1.32f, 0, 2.4f, 1.08f,
    2.4f, 2.4f, R_CUBIC_TO, 0, 1.32f, -1.07f, 2.4f, -2.4f, 2.4f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kVrHeadsetRepList, kVrHeadsetIcon, { kVrHeadsetPath, std::size(kVrHeadsetPath) })
VECTOR_ICON_REP_TEMPLATE(kVrHeadsetChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 4.5f, 13, R_H_LINE_TO, 3.19f, R_LINE_TO, 0.62f, -1.22f,
    R_ARC_TO, 1.95f, 1.95f, 0, 0, 1, 0.7f, -0.75f, ARC_TO, 1.82f, 1.82f, 0, 0, 1, 10, 10.75f, R_ARC_TO, 1.88f, 1.88f, 0, 0, 1, 1.69f, 1.02f, R_LINE_TO, 0.62f,
    1.23f, H_LINE_TO, 15.5f, V_LINE_TO, 7, R_H_LINE_TO, -11, CLOSE, R_MOVE_TO, 2, -1.5f, R_CUBIC_TO, 0.41f, 0, 0.77f, -0.15f, 1.06f, -0.44f, R_CUBIC_TO, 0.29f,
    -0.3f, 0.44f, -0.65f, 0.44f, -1.06f, R_CUBIC_TO, 0, -0.41f, -0.15f, -0.77f, -0.44f, -1.06f, ARC_TO, 1.45f, 1.45f, 0, 0, 0, 6.5f, 8.5f, R_CUBIC_TO, -0.41f,
    0, -0.77f, 0.15f, -1.06f, 0.44f, ARC_TO, 1.45f, 1.45f, 0, 0, 0, 5, 10, R_CUBIC_TO, 0, 0.41f, 0.15f, 0.77f, 0.44f, 1.06f, R_CUBIC_TO, 0.3f, 0.29f, 0.65f,
    0.44f, 1.06f, 0.44f, CLOSE, MOVE_TO, 3, 13, V_LINE_TO, 7, R_CUBIC_TO, 0, -0.41f, 0.15f, -0.77f, 0.44f, -1.06f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 4.5f, 5.5f,
    R_H_LINE_TO, 11, R_CUBIC_TO, 0.41f, 0, 0.77f, 0.15f, 1.06f, 0.44f, R_CUBIC_TO, 0.29f, 0.29f, 0.44f, 0.65f, 0.44f, 1.06f, R_V_LINE_TO, 6, R_CUBIC_TO, 0,
    0.41f, -0.15f, 0.77f, -0.44f, 1.06f, R_ARC_TO, 1.44f, 1.44f, 0, 0, 1, -1.06f, 0.44f, R_H_LINE_TO, -3.19f, R_CUBIC_TO, -0.28f, 0, -0.54f, -0.07f, -0.78f,
    -0.22f, R_ARC_TO, 1.42f, 1.42f, 0, 0, 1, -0.55f, -0.59f, R_LINE_TO, -0.62f, -1.21f, R_ARC_TO, 0.4f, 0.4f, 0, 0, 0, -0.15f, -0.17f, R_ARC_TO, 0.36f, 0.36f,
    0, 0, 0, -0.41f, 0, R_ARC_TO, 0.34f, 0.34f, 0, 0, 0, -0.15f, 0.17f, R_LINE_TO, -0.62f, 1.21f, R_CUBIC_TO, -0.12f, 0.25f, -0.31f, 0.45f, -0.55f, 0.59f,
    R_ARC_TO, 1.5f, 1.5f, 0, 0, 1, -0.78f, 0.22f, H_LINE_TO, 4.5f, R_CUBIC_TO, -0.41f, 0, -0.77f, -0.15f, -1.06f, -0.44f, ARC_TO, 1.45f, 1.45f, 0, 0, 1, 3, 13,
    CLOSE, R_MOVE_TO, 10.5f, -1.5f, R_CUBIC_TO, 0.41f, 0, 0.77f, -0.15f, 1.06f, -0.44f, R_CUBIC_TO, 0.29f, -0.3f, 0.44f, -0.65f, 0.44f, -1.06f, R_CUBIC_TO, 0,
    -0.41f, -0.15f, -0.77f, -0.44f, -1.06f, R_ARC_TO, 1.45f, 1.45f, 0, 0, 0, -1.06f, -0.44f, R_CUBIC_TO, -0.41f, 0, -0.77f, 0.15f, -1.06f, 0.44f, ARC_TO, 1.45f,
    1.45f, 0, 0, 0, 12, 10, R_CUBIC_TO, 0, 0.41f, 0.15f, 0.77f, 0.44f, 1.06f, R_CUBIC_TO, 0.3f, 0.29f, 0.65f, 0.44f, 1.06f, 0.44f, CLOSE, MOVE_TO, 10, 10,
    CLOSE)
VECTOR_ICON_TEMPLATE_CC(kVrHeadsetChromeRefreshRepList, kVrHeadsetChromeRefreshIcon, { kVrHeadsetChromeRefreshPath, std::size(kVrHeadsetChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kVrHeadsetOffChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 16, 18.13f, LINE_TO, 1.88f, 4, R_LINE_TO, 1.06f,
    -1.06f, R_LINE_TO, 14.12f, 14.13f, CLOSE, MOVE_TO, 7.88f, 10, CLOSE, R_MOVE_TO, 8.69f, 4.06f, LINE_TO, 15.5f, 13, V_LINE_TO, 7, H_LINE_TO, 9.11f, R_LINE_TO,
    -1.48f, -1.5f, H_LINE_TO, 15.5f, R_CUBIC_TO, 0.41f, 0, 0.77f, 0.15f, 1.06f, 0.44f, R_CUBIC_TO, 0.29f, 0.29f, 0.44f, 0.65f, 0.44f, 1.06f, R_V_LINE_TO, 5.99f,
    R_CUBIC_TO, 0, 0.22f, -0.04f, 0.41f, -0.11f, 0.59f, R_CUBIC_TO, -0.08f, 0.18f, -0.18f, 0.34f, -0.32f, 0.48f, CLOSE, MOVE_TO, 6.5f, 11.5f, R_CUBIC_TO,
    -0.41f, 0, -0.77f, -0.15f, -1.06f, -0.44f, ARC_TO, 1.45f, 1.45f, 0, 0, 1, 5, 10, R_CUBIC_TO, 0, -0.41f, 0.15f, -0.77f, 0.44f, -1.06f, ARC_TO, 1.45f, 1.45f,
    0, 0, 1, 6.5f, 8.5f, R_CUBIC_TO, 0.41f, 0, 0.77f, 0.15f, 1.06f, 0.44f, R_CUBIC_TO, 0.29f, 0.3f, 0.44f, 0.65f, 0.44f, 1.06f, R_CUBIC_TO, 0, 0.41f, -0.15f,
    0.77f, -0.44f, 1.06f, R_ARC_TO, 1.45f, 1.45f, 0, 0, 1, -1.06f, 0.44f, CLOSE, R_MOVE_TO, 7.05f, 0, LINE_TO, 12, 9.94f, R_CUBIC_TO, 0.03f, -0.4f, 0.18f,
    -0.74f, 0.47f, -1.02f, ARC_TO, 1.43f, 1.43f, 0, 0, 1, 13.5f, 8.5f, R_CUBIC_TO, 0.41f, 0, 0.77f, 0.15f, 1.06f, 0.44f, R_CUBIC_TO, 0.29f, 0.29f, 0.44f, 0.65f,
    0.44f, 1.06f, R_CUBIC_TO, 0, 0.4f, -0.14f, 0.75f, -0.43f, 1.04f, R_CUBIC_TO, -0.28f, 0.29f, -0.63f, 0.44f, -1.03f, 0.46f, CLOSE, R_MOVE_TO, -1.48f, -1.5f,
    CLOSE, MOVE_TO, 4.5f, 14.5f, R_CUBIC_TO, -0.41f, 0, -0.77f, -0.15f, -1.06f, -0.44f, ARC_TO, 1.45f, 1.45f, 0, 0, 1, 3, 13, V_LINE_TO, 7, R_CUBIC_TO, 0,
    -0.41f, 0.15f, -0.77f, 0.44f, -1.06f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 4.5f, 5.5f, R_H_LINE_TO, 1, LINE_TO, 7, 7, H_LINE_TO, 4.5f, R_V_LINE_TO, 6,
    R_H_LINE_TO, 3.19f, R_LINE_TO, 0.62f, -1.22f, R_ARC_TO, 1.95f, 1.95f, 0, 0, 1, 0.7f, -0.75f, ARC_TO, 1.82f, 1.82f, 0, 0, 1, 10, 10.75f, R_H_LINE_TO, 0.75f,
    R_LINE_TO, 3.75f, 3.75f, R_H_LINE_TO, -2.19f, R_CUBIC_TO, -0.28f, 0, -0.54f, -0.07f, -0.78f, -0.22f, R_ARC_TO, 1.42f, 1.42f, 0, 0, 1, -0.55f, -0.59f,
    R_LINE_TO, -0.62f, -1.21f, R_ARC_TO, 0.4f, 0.4f, 0, 0, 0, -0.15f, -0.17f, R_ARC_TO, 0.36f, 0.36f, 0, 0, 0, -0.41f, 0, R_ARC_TO, 0.34f, 0.34f, 0, 0, 0,
    -0.15f, 0.17f, R_LINE_TO, -0.62f, 1.21f, R_CUBIC_TO, -0.12f, 0.25f, -0.31f, 0.45f, -0.55f, 0.59f, R_ARC_TO, 1.5f, 1.5f, 0, 0, 1, -0.78f, 0.22f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(
    kVrHeadsetOffChromeRefreshRepList, kVrHeadsetOffChromeRefreshIcon, { kVrHeadsetOffChromeRefreshPath, std::size(kVrHeadsetOffChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kWarningPath, MOVE_TO, 2, 42, R_H_LINE_TO, 44, LINE_TO, 24, 4, LINE_TO, 2, 42, CLOSE, NEW_PATH, PATH_COLOR_ARGB, 0xFF, 0xFF, 0xFF,
    0xFF, MOVE_TO, 26, 36, R_H_LINE_TO, -4, R_V_LINE_TO, -4, R_H_LINE_TO, 4, R_V_LINE_TO, 4, CLOSE, R_MOVE_TO, 0, -8, R_H_LINE_TO, -4, R_V_LINE_TO, -8,
    R_H_LINE_TO, 4, R_V_LINE_TO, 8, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kWarningRepList, kWarningIcon, { kWarningPath, std::size(kWarningPath) })
VECTOR_ICON_REP_TEMPLATE(kWarningOutlinePath, CANVAS_DIMENSIONS, 20, MOVE_TO, 9.13f, 2.5f, CUBIC_TO, 9.52f, 1.83f, 10.48f, 1.83f, 10.87f, 2.5f, LINE_TO, 18.87f,
    16.5f, CUBIC_TO, 19.25f, 17.17f, 18.77f, 18, 18, 18, H_LINE_TO, 2, CUBIC_TO, 1.23f, 18, 0.75f, 17.17f, 1.13f, 16.5f, LINE_TO, 9.13f, 2.5f, CLOSE, MOVE_TO,
    10, 5.02f, LINE_TO, 3.72f, 16, H_LINE_TO, 16.28f, LINE_TO, 10, 5.02f, CLOSE, MOVE_TO, 11, 12, V_LINE_TO, 8, H_LINE_TO, 9, V_LINE_TO, 12, H_LINE_TO, 11,
    CLOSE, MOVE_TO, 11, 13, V_LINE_TO, 15, H_LINE_TO, 9, V_LINE_TO, 13, H_LINE_TO, 11, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kWarningOutlineRepList, kWarningOutlineIcon, { kWarningOutlinePath, std::size(kWarningOutlinePath) })

} // namespace vector_icons
