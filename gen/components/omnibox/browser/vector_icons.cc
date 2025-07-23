// Copyright 2017 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// vector_icons.cc.template is used to generate vector_icons.cc. Edit the former
// rather than the latter.

#include "components/omnibox/browser/vector_icons.h"

#include "components/vector_icons/cc_macros.h"
#include "ui/gfx/vector_icon_types.h"

#define DECLARE_VECTOR_COMMAND(x) using gfx::x;
DECLARE_VECTOR_COMMANDS

namespace omnibox {

VECTOR_ICON_REP_TEMPLATE(kAnswerCalculatorPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 3, 5, R_H_LINE_TO, 10, R_V_LINE_TO, 2, H_LINE_TO, 3, V_LINE_TO, 5, CLOSE,
    R_MOVE_TO, 0, 4, R_H_LINE_TO, 10, R_V_LINE_TO, 2, H_LINE_TO, 3, V_LINE_TO, 9, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kAnswerCalculatorRepList, kAnswerCalculatorIcon, { kAnswerCalculatorPath, std::size(kAnswerCalculatorPath) })
VECTOR_ICON_REP_TEMPLATE(kAnswerCurrencyPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 8, 3.64f, R_V_LINE_TO, 2.18f, R_LINE_TO, 3, -2.91f, LINE_TO, 8, 0, R_V_LINE_TO,
    2.18f, CUBIC_TO, 4.68f, 2.18f, 2, 4.79f, 2, 8, R_CUBIC_TO, 0, 1.14f, 0.35f, 2.2f, 0.93f, 3.1f, R_LINE_TO, 1.1f, -1.06f, ARC_TO, 4.17f, 4.17f, 0, 0, 1, 3.5f,
    8, R_CUBIC_TO, 0, -2.41f, 2.02f, -4.36f, 4.5f, -4.36f, CLOSE, R_MOVE_TO, 5.07f, 1.27f, R_LINE_TO, -1.09f, 1.06f, R_CUBIC_TO, 0.33f, 0.61f, 0.53f, 1.3f,
    0.53f, 2.04f, R_CUBIC_TO, 0, 2.41f, -2.02f, 4.36f, -4.5f, 4.36f, R_V_LINE_TO, -2.18f, LINE_TO, 5, 13.09f, LINE_TO, 8, 16, R_V_LINE_TO, -2.18f, R_CUBIC_TO,
    3.32f, 0, 6, -2.6f, 6, -5.82f, R_ARC_TO, 5.64f, 5.64f, 0, 0, 0, -0.93f, -3.1f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kAnswerCurrencyRepList, kAnswerCurrencyIcon, { kAnswerCurrencyPath, std::size(kAnswerCurrencyPath) })
VECTOR_ICON_REP_TEMPLATE(kAnswerCurrencyChromeRefreshPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 3.77f, 10.39f, R_ARC_TO, 5.41f, 5.41f, 0, 0, 1, -0.48f, -1.13f,
    R_ARC_TO, 4.37f, 4.37f, 0, 0, 1, -0.18f, -1.27f, R_CUBIC_TO, 0, -1.36f, 0.48f, -2.52f, 1.44f, -3.49f, R_CUBIC_TO, 0.96f, -0.96f, 2.13f, -1.43f, 3.51f,
    -1.39f, R_H_LINE_TO, 0, R_LINE_TO, -0.89f, -0.89f, R_LINE_TO, 0.89f, -0.89f, LINE_TO, 10.54f, 3.8f, LINE_TO, 8.07f, 6.27f, R_LINE_TO, -0.89f, -0.89f,
    R_LINE_TO, 0.89f, -0.89f, R_H_LINE_TO, 0.01f, R_CUBIC_TO, -1.01f, -0.02f, -1.85f, 0.31f, -2.55f, 1, R_CUBIC_TO, -0.69f, 0.7f, -1.03f, 1.52f, -1.03f, 2.5f,
    R_CUBIC_TO, 0, 0.25f, 0.02f, 0.49f, 0.07f, 0.72f, R_CUBIC_TO, 0.05f, 0.23f, 0.12f, 0.45f, 0.22f, 0.67f, CLOSE, R_MOVE_TO, 4.16f, 4.29f, R_LINE_TO, -2.47f,
    -2.47f, R_LINE_TO, 2.47f, -2.48f, R_LINE_TO, 0.89f, 0.89f, R_LINE_TO, -0.89f, 0.89f, H_LINE_TO, 7.93f, R_CUBIC_TO, 1.01f, 0.02f, 1.86f, -0.31f, 2.55f,
    -1.01f, R_ARC_TO, 3.41f, 3.41f, 0, 0, 0, 1.03f, -2.5f, R_ARC_TO, 3.6f, 3.6f, 0, 0, 0, -0.07f, -0.72f, R_ARC_TO, 3.51f, 3.51f, 0, 0, 0, -0.22f, -0.67f,
    R_LINE_TO, 1.01f, -1, R_CUBIC_TO, 0.2f, 0.36f, 0.36f, 0.73f, 0.48f, 1.13f, R_CUBIC_TO, 0.12f, 0.4f, 0.18f, 0.82f, 0.18f, 1.26f, R_CUBIC_TO, 0, 1.35f,
    -0.48f, 2.51f, -1.44f, 3.48f, R_CUBIC_TO, -0.96f, 0.97f, -2.13f, 1.44f, -3.51f, 1.41f, R_H_LINE_TO, 0, R_LINE_TO, 0.89f, 0.89f, CLOSE, R_MOVE_TO, 0, 0,
    CLOSE)
VECTOR_ICON_TEMPLATE_CC(
    kAnswerCurrencyChromeRefreshRepList, kAnswerCurrencyChromeRefreshIcon, { kAnswerCurrencyChromeRefreshPath, std::size(kAnswerCurrencyChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kAnswerDefaultPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 8.14f, 9.33f, V_LINE_TO, 6.73f, R_H_LINE_TO, 6.68f, R_CUBIC_TO, 0.1f, 0.44f, 0.18f,
    0.85f, 0.18f, 1.44f, CUBIC_TO, 15, 12.16f, 12.27f, 15, 8.15f, 15, CUBIC_TO, 4.2f, 15, 1, 11.86f, 1, 8, R_CUBIC_TO, 0, -3.86f, 3.2f, -7, 7.14f, -7,
    R_CUBIC_TO, 1.93f, 0, 3.54f, 0.69f, 4.78f, 1.83f, R_LINE_TO, -2.03f, 1.93f, R_CUBIC_TO, -0.51f, -0.48f, -1.41f, -1.04f, -2.75f, -1.04f, ARC_TO, 4.3f, 4.3f,
    0, 0, 0, 3.85f, 8, R_ARC_TO, 4.3f, 4.3f, 0, 0, 0, 4.29f, 4.28f, R_CUBIC_TO, 2.74f, 0, 3.74f, -1.85f, 3.93f, -2.95f, H_LINE_TO, 8.14f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kAnswerDefaultRepList, kAnswerDefaultIcon, { kAnswerDefaultPath, std::size(kAnswerDefaultPath) })
VECTOR_ICON_REP_TEMPLATE(kAnswerDictionaryPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 13, 1, H_LINE_TO, 3, R_CUBIC_TO, -0.6f, 0, -1, 0.4f, -1, 1, R_V_LINE_TO, 12,
    R_CUBIC_TO, 0, 0.6f, 0.4f, 1, 1, 1, R_H_LINE_TO, 10, R_CUBIC_TO, 0.6f, 0, 1, -0.4f, 1, -1, V_LINE_TO, 2, R_CUBIC_TO, 0, -0.6f, -0.4f, -1, -1, -1, CLOSE,
    R_MOVE_TO, -1, 12, H_LINE_TO, 4, V_LINE_TO, 3, R_H_LINE_TO, 1, R_V_LINE_TO, 6, R_LINE_TO, 2, -1.1f, LINE_TO, 9, 9, V_LINE_TO, 3, R_H_LINE_TO, 3,
    R_V_LINE_TO, 10, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kAnswerDictionaryRepList, kAnswerDictionaryIcon, { kAnswerDictionaryPath, std::size(kAnswerDictionaryPath) })
VECTOR_ICON_REP_TEMPLATE(kAnswerDictionaryChromeRefreshPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 4.44f, 14.54f, R_CUBIC_TO, -0.38f, 0, -0.71f, -0.13f, -0.98f,
    -0.4f, R_ARC_TO, 1.35f, 1.35f, 0, 0, 1, -0.4f, -0.98f, V_LINE_TO, 2.85f, R_CUBIC_TO, 0, -0.38f, 0.13f, -0.71f, 0.4f, -0.98f, R_CUBIC_TO, 0.27f, -0.27f,
    0.6f, -0.4f, 0.98f, -0.4f, R_H_LINE_TO, 7.11f, R_CUBIC_TO, 0.38f, 0, 0.71f, 0.13f, 0.98f, 0.4f, R_CUBIC_TO, 0.27f, 0.27f, 0.4f, 0.6f, 0.4f, 0.98f,
    R_V_LINE_TO, 10.31f, R_CUBIC_TO, 0, 0.38f, -0.13f, 0.71f, -0.4f, 0.98f, R_CUBIC_TO, -0.27f, 0.27f, -0.6f, 0.4f, -0.98f, 0.4f, CLOSE, R_MOVE_TO, 0.01f,
    -1.38f, R_H_LINE_TO, 7.1f, V_LINE_TO, 2.85f, R_H_LINE_TO, -1.14f, R_V_LINE_TO, 5.2f, R_LINE_TO, -1.6f, -0.8f, R_LINE_TO, -1.6f, 0.8f, R_V_LINE_TO, -5.2f,
    H_LINE_TO, 4.45f, CLOSE, R_MOVE_TO, 0, 0, V_LINE_TO, 2.85f, CLOSE, R_MOVE_TO, 2.76f, -5.11f, R_LINE_TO, 1.6f, -0.8f, R_LINE_TO, 1.6f, 0.8f, R_LINE_TO,
    -1.6f, -0.8f, CLOSE, R_MOVE_TO, 0, 0, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kAnswerDictionaryChromeRefreshRepList, kAnswerDictionaryChromeRefreshIcon,
    { kAnswerDictionaryChromeRefreshPath, std::size(kAnswerDictionaryChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kAnswerFinancePath, CANVAS_DIMENSIONS, 16, MOVE_TO, 9, 12, V_LINE_TO, 7, R_H_LINE_TO, 2, R_V_LINE_TO, 5, R_H_LINE_TO, 2, R_LINE_TO, -3,
    3, R_LINE_TO, -3, -3, R_H_LINE_TO, 2, CLOSE, MOVE_TO, 7, 4, R_V_LINE_TO, 5, H_LINE_TO, 5, V_LINE_TO, 4, H_LINE_TO, 3, R_LINE_TO, 3, -3, R_LINE_TO, 3, 3,
    H_LINE_TO, 7, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kAnswerFinanceRepList, kAnswerFinanceIcon, { kAnswerFinancePath, std::size(kAnswerFinancePath) })
VECTOR_ICON_REP_TEMPLATE(kAnswerFinanceChromeRefreshPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 5.31f, 8.78f, V_LINE_TO, 4, LINE_TO, 3.65f, 5.66f, R_LINE_TO, -0.98f,
    -0.98f, LINE_TO, 6, 1.36f, R_LINE_TO, 3.33f, 3.33f, R_LINE_TO, -0.98f, 0.98f, R_LINE_TO, -1.66f, -1.66f, R_V_LINE_TO, 4.77f, CLOSE, MOVE_TO, 10, 14.65f,
    R_LINE_TO, -3.33f, -3.33f, R_LINE_TO, 0.98f, -0.98f, R_LINE_TO, 1.66f, 1.66f, V_LINE_TO, 7.22f, R_H_LINE_TO, 1.38f, R_V_LINE_TO, 4.77f, R_LINE_TO, 1.66f,
    -1.66f, R_LINE_TO, 0.98f, 0.98f, CLOSE, R_MOVE_TO, 0, 0, CLOSE)
VECTOR_ICON_TEMPLATE_CC(
    kAnswerFinanceChromeRefreshRepList, kAnswerFinanceChromeRefreshIcon, { kAnswerFinanceChromeRefreshPath, std::size(kAnswerFinanceChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kAnswerSunrisePath, CANVAS_DIMENSIONS, 16, MOVE_TO, 8, 4, CUBIC_TO, 5.79f, 4, 4, 5.79f, 4, 8, R_CUBIC_TO, 0, 2.21f, 1.79f, 4, 4, 4,
    R_CUBIC_TO, 2.21f, 0, 4, -1.79f, 4, -4, R_CUBIC_TO, 0, -2.21f, -1.79f, -4, -4, -4, CLOSE, R_MOVE_TO, 1, -4, R_V_LINE_TO, 2, H_LINE_TO, 7, V_LINE_TO, 0,
    R_H_LINE_TO, 2, CLOSE, R_MOVE_TO, 0, 14, R_V_LINE_TO, 2, H_LINE_TO, 7, R_V_LINE_TO, -2, R_H_LINE_TO, 2, CLOSE, MOVE_TO, 0, 7, R_H_LINE_TO, 2, R_V_LINE_TO,
    2, H_LINE_TO, 0, V_LINE_TO, 7, CLOSE, R_MOVE_TO, 14, 0, R_H_LINE_TO, 2, R_V_LINE_TO, 2, R_H_LINE_TO, -2, V_LINE_TO, 7, CLOSE, MOVE_TO, 3.05f, 1.64f,
    LINE_TO, 4.46f, 3.05f, LINE_TO, 3.05f, 4.46f, LINE_TO, 1.64f, 3.05f, LINE_TO, 3.05f, 1.64f, CLOSE, R_MOVE_TO, 9.9f, 9.9f, R_LINE_TO, 1.41f, 1.41f,
    R_LINE_TO, -1.41f, 1.41f, R_LINE_TO, -1.41f, -1.41f, R_LINE_TO, 1.41f, -1.41f, CLOSE, MOVE_TO, 1.64f, 12.95f, R_LINE_TO, 1.41f, -1.41f, R_LINE_TO, 1.41f,
    1.41f, R_LINE_TO, -1.41f, 1.41f, R_LINE_TO, -1.41f, -1.41f, CLOSE, R_MOVE_TO, 9.9f, -9.9f, R_LINE_TO, 1.41f, -1.41f, R_LINE_TO, 1.41f, 1.41f, R_LINE_TO,
    -1.41f, 1.41f, R_LINE_TO, -1.41f, -1.41f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kAnswerSunriseRepList, kAnswerSunriseIcon, { kAnswerSunrisePath, std::size(kAnswerSunrisePath) })
VECTOR_ICON_REP_TEMPLATE(kAnswerSunriseChromeRefreshPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 7.31f, 2.86f, V_LINE_TO, 0.68f, H_LINE_TO, 8.69f, R_V_LINE_TO, 2.18f,
    CLOSE, R_MOVE_TO, 0, 12.46f, R_V_LINE_TO, -2.18f, H_LINE_TO, 8.69f, R_V_LINE_TO, 2.18f, CLOSE, R_MOVE_TO, 5.83f, -6.63f, V_LINE_TO, 7.31f, R_H_LINE_TO,
    2.18f, V_LINE_TO, 8.69f, CLOSE, R_MOVE_TO, -12.46f, 0, V_LINE_TO, 7.31f, R_H_LINE_TO, 2.18f, V_LINE_TO, 8.69f, CLOSE, MOVE_TO, 12.12f, 4.86f, R_LINE_TO,
    -0.98f, -0.98f, LINE_TO, 12.67f, 2.3f, R_LINE_TO, 1.03f, 1.03f, CLOSE, MOVE_TO, 3.35f, 13.68f, LINE_TO, 2.32f, 12.65f, R_LINE_TO, 1.56f, -1.51f, R_LINE_TO,
    0.98f, 0.98f, CLOSE, R_MOVE_TO, 9.32f, 0, R_LINE_TO, -1.53f, -1.56f, R_LINE_TO, 0.98f, -0.98f, R_LINE_TO, 1.58f, 1.52f, CLOSE, MOVE_TO, 3.88f, 4.86f,
    LINE_TO, 2.32f, 3.33f, R_LINE_TO, 1.03f, -1.03f, R_LINE_TO, 1.52f, 1.58f, CLOSE, MOVE_TO, 8, 12, R_CUBIC_TO, -1.11f, 0, -2.06f, -0.39f, -2.83f, -1.17f,
    CUBIC_TO, 4.39f, 10.06f, 4, 9.11f, 4, 8, R_CUBIC_TO, 0, -1.11f, 0.39f, -2.06f, 1.17f, -2.83f, CUBIC_TO, 5.95f, 4.39f, 6.89f, 4, 8, 4, R_CUBIC_TO, 1.11f, 0,
    2.06f, 0.39f, 2.83f, 1.17f, CUBIC_TO, 11.61f, 5.95f, 12, 6.89f, 12, 8, R_CUBIC_TO, 0, 1.11f, -0.39f, 2.06f, -1.17f, 2.83f, CUBIC_TO, 10.06f, 11.61f, 9.11f,
    12, 8, 12, CLOSE, R_MOVE_TO, 0, -1.37f, R_ARC_TO, 2.53f, 2.53f, 0, 0, 0, 1.86f, -0.77f, R_ARC_TO, 2.56f, 2.56f, 0, 0, 0, 0.76f, -1.87f, R_CUBIC_TO, 0,
    -0.73f, -0.25f, -1.35f, -0.76f, -1.85f, R_ARC_TO, 2.52f, 2.52f, 0, 0, 0, -1.85f, -0.76f, R_CUBIC_TO, -0.73f, 0, -1.35f, 0.25f, -1.86f, 0.76f, R_CUBIC_TO,
    -0.51f, 0.5f, -0.76f, 1.12f, -0.76f, 1.85f, R_CUBIC_TO, 0, 0.73f, 0.25f, 1.35f, 0.76f, 1.87f, R_ARC_TO, 2.5f, 2.5f, 0, 0, 0, 1.85f, 0.77f, CLOSE, R_MOVE_TO,
    0.02f, -2.65f, CLOSE, R_MOVE_TO, 0, 0, CLOSE)
VECTOR_ICON_TEMPLATE_CC(
    kAnswerSunriseChromeRefreshRepList, kAnswerSunriseChromeRefreshIcon, { kAnswerSunriseChromeRefreshPath, std::size(kAnswerSunriseChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kAnswerTranslationPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 8.6f, 10.3f, LINE_TO, 6.9f, 8.7f, R_CUBIC_TO, 1.2f, -1.2f, 2, -2.7f, 2.4f,
    -4.2f, R_H_LINE_TO, 1.9f, V_LINE_TO, 3.3f, H_LINE_TO, 6.7f, V_LINE_TO, 2, H_LINE_TO, 5.5f, R_V_LINE_TO, 1.3f, H_LINE_TO, 1, R_V_LINE_TO, 1.3f, R_H_LINE_TO,
    7.1f, R_CUBIC_TO, -0.4f, 1.2f, -1.1f, 2.3f, -2, 3.3f, R_CUBIC_TO, -0.6f, -0.6f, -1.1f, -1.3f, -1.5f, -2.1f, H_LINE_TO, 3.3f, R_CUBIC_TO, 0.5f, 1, 1.1f, 2,
    1.9f, 2.9f, LINE_TO, 2, 11.9f, R_LINE_TO, 0.9f, 0.9f, R_LINE_TO, 3.2f, -3.2f, R_LINE_TO, 2, 2, R_LINE_TO, 0.5f, -1.3f, CLOSE, R_MOVE_TO, 3.5f, -3.2f,
    R_H_LINE_TO, -1.2f, LINE_TO, 8, 14.7f, R_H_LINE_TO, 1.3f, R_LINE_TO, 0.7f, -1.9f, R_H_LINE_TO, 3, R_LINE_TO, 0.7f, 1.9f, H_LINE_TO, 15, R_LINE_TO, -2.9f,
    -7.6f, CLOSE, R_MOVE_TO, -1.6f, 4.4f, R_LINE_TO, 1, -2.8f, R_LINE_TO, 1, 2.8f, R_H_LINE_TO, -2, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kAnswerTranslationRepList, kAnswerTranslationIcon, { kAnswerTranslationPath, std::size(kAnswerTranslationPath) })
VECTOR_ICON_REP_TEMPLATE(kAnswerTranslationChromeRefreshPath, CANVAS_DIMENSIONS, 16, R_MOVE_TO, 8.13f, 14.52f, R_LINE_TO, 2.91f, -7.75f, R_H_LINE_TO, 1.39f,
    R_LINE_TO, 2.91f, 7.75f, R_H_LINE_TO, -1.34f, R_LINE_TO, -0.69f, -1.99f, R_H_LINE_TO, -3.12f, R_LINE_TO, -0.7f, 1.99f, CLOSE, R_MOVE_TO, 2.45f, -3.11f,
    R_H_LINE_TO, 2.31f, LINE_TO, 11.77f, 8.2f, R_H_LINE_TO, -0.07f, CLOSE, R_MOVE_TO, -7.86f, 1.07f, R_LINE_TO, -0.85f, -0.87f, R_LINE_TO, 3.27f, -3.23f,
    R_ARC_TO, 15.27f, 15.27f, 0, 0, 1, -1.14f, -1.34f, R_ARC_TO, 9.15f, 9.15f, 0, 0, 1, -0.91f, -1.51f, R_H_LINE_TO, 1.39f, R_CUBIC_TO, 0.21f, 0.36f, 0.44f,
    0.7f, 0.7f, 1.02f, R_CUBIC_TO, 0.26f, 0.32f, 0.52f, 0.63f, 0.79f, 0.93f, ARC_TO, 15.29f, 15.29f, 0, 0, 0, 7.16f, 6, R_CUBIC_TO, 0.36f, -0.52f, 0.66f,
    -1.07f, 0.89f, -1.67f, H_LINE_TO, 0.66f, V_LINE_TO, 3.1f, R_H_LINE_TO, 4.69f, V_LINE_TO, 1.48f, R_H_LINE_TO, 1.22f, R_V_LINE_TO, 1.63f, R_H_LINE_TO, 4.69f,
    R_V_LINE_TO, 1.23f, R_H_LINE_TO, -1.93f, R_ARC_TO, 7.96f, 7.96f, 0, 0, 1, -1.04f, 2.16f, R_CUBIC_TO, -0.45f, 0.67f, -0.95f, 1.3f, -1.5f, 1.9f, R_LINE_TO,
    1.55f, 1.53f, R_LINE_TO, -0.47f, 1.26f, R_LINE_TO, -1.91f, -1.9f, CLOSE, R_MOVE_TO, 0, 0, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kAnswerTranslationChromeRefreshRepList, kAnswerTranslationChromeRefreshIcon,
    { kAnswerTranslationChromeRefreshPath, std::size(kAnswerTranslationChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kAnswerWhenIsPath, CANVAS_DIMENSIONS, 16, CIRCLE, 10, 10, 2, MOVE_TO, 13.7f, 2, H_LINE_TO, 13, V_LINE_TO, 1, R_H_LINE_TO, -2,
    R_V_LINE_TO, 1, H_LINE_TO, 5, V_LINE_TO, 1, H_LINE_TO, 3, R_V_LINE_TO, 1, R_H_LINE_TO, -0.7f, CUBIC_TO, 1.6f, 2, 1, 2.6f, 1, 3.3f, R_V_LINE_TO, 10.3f,
    R_CUBIC_TO, 0, 0.8f, 0.6f, 1.4f, 1.3f, 1.4f, R_H_LINE_TO, 11.3f, R_CUBIC_TO, 0.7f, 0, 1.3f, -0.6f, 1.3f, -1.3f, V_LINE_TO, 3.3f, R_CUBIC_TO, 0.1f, -0.7f,
    -0.5f, -1.3f, -1.2f, -1.3f, CLOSE, MOVE_TO, 13, 13, H_LINE_TO, 3, V_LINE_TO, 5, R_H_LINE_TO, 10, R_V_LINE_TO, 8, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kAnswerWhenIsRepList, kAnswerWhenIsIcon, { kAnswerWhenIsPath, std::size(kAnswerWhenIsPath) })
VECTOR_ICON_REP_TEMPLATE(kAnswerWhenIsChromeRefreshPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 9.61f, 12, R_CUBIC_TO, -0.45f, 0, -0.83f, -0.16f, -1.14f, -0.46f,
    ARC_TO, 1.54f, 1.54f, 0, 0, 1, 8, 10.4f, R_CUBIC_TO, 0, -0.44f, 0.16f, -0.82f, 0.47f, -1.14f, ARC_TO, 1.54f, 1.54f, 0, 0, 1, 9.6f, 8.8f, R_CUBIC_TO, 0.45f,
    0, 0.82f, 0.15f, 1.14f, 0.46f, R_CUBIC_TO, 0.31f, 0.31f, 0.47f, 0.69f, 0.47f, 1.13f, R_CUBIC_TO, 0, 0.45f, -0.15f, 0.83f, -0.46f, 1.14f, ARC_TO, 1.55f,
    1.55f, 0, 0, 1, 9.6f, 12, CLOSE, R_MOVE_TO, -5.96f, 2.54f, R_CUBIC_TO, -0.38f, 0, -0.71f, -0.14f, -0.98f, -0.41f, R_ARC_TO, 1.34f, 1.34f, 0, 0, 1, -0.4f,
    -0.97f, V_LINE_TO, 4.45f, R_CUBIC_TO, 0, -0.37f, 0.13f, -0.7f, 0.4f, -0.97f, R_CUBIC_TO, 0.27f, -0.27f, 0.6f, -0.41f, 0.98f, -0.41f, R_H_LINE_TO, 1.15f,
    V_LINE_TO, 1.46f, H_LINE_TO, 6.09f, R_V_LINE_TO, 1.6f, R_H_LINE_TO, 3.82f, V_LINE_TO, 1.47f, R_H_LINE_TO, 1.29f, R_V_LINE_TO, 1.6f, R_H_LINE_TO, 1.15f,
    R_CUBIC_TO, 0.38f, 0, 0.71f, 0.14f, 0.98f, 0.41f, R_CUBIC_TO, 0.27f, 0.27f, 0.4f, 0.6f, 0.4f, 0.97f, R_V_LINE_TO, 8.7f, R_CUBIC_TO, 0, 0.38f, -0.13f, 0.7f,
    -0.4f, 0.97f, R_CUBIC_TO, -0.27f, 0.27f, -0.6f, 0.41f, -0.98f, 0.41f, CLOSE, R_MOVE_TO, 0, -1.38f, R_H_LINE_TO, 8.7f, V_LINE_TO, 7.2f, H_LINE_TO, 3.65f,
    CLOSE, R_MOVE_TO, 0, -7.15f, R_H_LINE_TO, 8.7f, V_LINE_TO, 4.45f, H_LINE_TO, 3.65f, CLOSE, R_MOVE_TO, 0, 0, V_LINE_TO, 4.45f, CLOSE, R_MOVE_TO, 0, 0, CLOSE)
VECTOR_ICON_TEMPLATE_CC(
    kAnswerWhenIsChromeRefreshRepList, kAnswerWhenIsChromeRefreshIcon, { kAnswerWhenIsChromeRefreshPath, std::size(kAnswerWhenIsChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(
    kArrowDownChromeRefreshPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 8, 9.73f, LINE_TO, 4.58f, 6.31f, R_H_LINE_TO, 6.84f, CLOSE, R_MOVE_TO, 0, 0, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kArrowDownChromeRefreshRepList, kArrowDownChromeRefreshIcon, { kArrowDownChromeRefreshPath, std::size(kArrowDownChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(
    kArrowUpChromeRefreshPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 4.58f, 9.69f, LINE_TO, 8, 6.27f, R_LINE_TO, 3.42f, 3.42f, CLOSE, R_MOVE_TO, 0, 0, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kArrowUpChromeRefreshRepList, kArrowUpChromeRefreshIcon, { kArrowUpChromeRefreshPath, std::size(kArrowUpChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kBookmarkPath, CANVAS_DIMENSIONS, 20, MOVE_TO, 10, 18, R_ARC_TO, 8, 8, 0, 1, 1, 0, -16, R_ARC_TO, 8, 8, 0, 0, 1, 0, 16, CLOSE,
    R_MOVE_TO, 0, -4.96f, LINE_TO, 13.09f, 15, R_LINE_TO, -0.82f, -3.7f, LINE_TO, 15, 8.81f, R_LINE_TO, -3.59f, -0.32f, LINE_TO, 10, 5, LINE_TO, 8.6f, 8.49f,
    LINE_TO, 5, 8.81f, R_LINE_TO, 2.73f, 2.49f, R_LINE_TO, -0.82f, 3.7f, LINE_TO, 10, 13.04f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kBookmarkRepList, kBookmarkIcon, { kBookmarkPath, std::size(kBookmarkPath) })
VECTOR_ICON_REP_TEMPLATE(kBookmarkChromeRefreshPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 5.94f, 11.81f, LINE_TO, 8, 10.59f, R_LINE_TO, 2.07f, 1.22f, R_LINE_TO,
    -0.55f, -2.31f, R_LINE_TO, 1.79f, -1.53f, R_LINE_TO, -2.36f, -0.21f, LINE_TO, 8, 5.57f, LINE_TO, 7.05f, 7.77f, R_LINE_TO, -2.36f, 0.2f, R_LINE_TO, 1.8f,
    1.52f, CLOSE, R_MOVE_TO, -2.09f, 2.87f, R_LINE_TO, 1.11f, -4.66f, R_LINE_TO, -3.68f, -3.14f, R_LINE_TO, 4.83f, -0.41f, LINE_TO, 8, 2.06f, R_LINE_TO, 1.89f,
    4.42f, R_LINE_TO, 4.83f, 0.4f, R_LINE_TO, -3.68f, 3.14f, R_LINE_TO, 1.11f, 4.66f, LINE_TO, 8, 12.2f, CLOSE, MOVE_TO, 8, 8.86f, CLOSE, R_MOVE_TO, 0, 0,
    CLOSE)
VECTOR_ICON_TEMPLATE_CC(kBookmarkChromeRefreshRepList, kBookmarkChromeRefreshIcon, { kBookmarkChromeRefreshPath, std::size(kBookmarkChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kCalculatorPath, CANVAS_DIMENSIONS, 32, MOVE_TO, 8, 12, LINE_TO, 24, 12, LINE_TO, 24, 15, LINE_TO, 8, 15, LINE_TO, 8, 12, LINE_TO, 8,
    12, CLOSE, MOVE_TO, 8, 18, LINE_TO, 24, 18, LINE_TO, 24, 21, LINE_TO, 8, 21, LINE_TO, 8, 18, LINE_TO, 8, 18, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kCalculator16Path, CANVAS_DIMENSIONS, 16, MOVE_TO, 4, 5, LINE_TO, 12, 5, LINE_TO, 12, 7, LINE_TO, 4, 7, LINE_TO, 4, 5, LINE_TO, 4, 5,
    CLOSE, MOVE_TO, 4, 9, LINE_TO, 12, 9, LINE_TO, 12, 11, LINE_TO, 4, 11, LINE_TO, 4, 9, LINE_TO, 4, 9, CLOSE)
VECTOR_ICON_TEMPLATE_CC(
    kCalculatorRepList, kCalculatorIcon, { kCalculatorPath, std::size(kCalculatorPath) }, { kCalculator16Path, std::size(kCalculator16Path) })
VECTOR_ICON_REP_TEMPLATE(kCalculatorChromeRefreshPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 3.11f, 11.29f, V_LINE_TO, 9.11f, R_H_LINE_TO, 9.78f, R_V_LINE_TO, 2.18f,
    CLOSE, R_MOVE_TO, 0, -4.4f, V_LINE_TO, 4.71f, R_H_LINE_TO, 9.78f, R_V_LINE_TO, 2.18f, CLOSE, R_MOVE_TO, 0, 0, CLOSE)
VECTOR_ICON_TEMPLATE_CC(
    kCalculatorChromeRefreshRepList, kCalculatorChromeRefreshIcon, { kCalculatorChromeRefreshPath, std::size(kCalculatorChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kChevronPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 12.88f, 16.12f, CUBIC_TO, 12.66f, 16.36f, 12.35f, 16.5f, 12, 16.5f, CUBIC_TO, 11.66f,
    16.5f, 11.34f, 16.36f, 11.12f, 16.12f, LINE_TO, 4.87f, 9.69f, CUBIC_TO, 4.64f, 9.46f, 4.5f, 9.14f, 4.5f, 8.79f, CUBIC_TO, 4.5f, 8.08f, 5.06f, 7.5f, 5.75f,
    7.5f, CUBIC_TO, 6.1f, 7.5f, 6.41f, 7.64f, 6.63f, 7.88f, LINE_TO, 12, 13.4f, LINE_TO, 17.37f, 7.88f, CUBIC_TO, 17.59f, 7.64f, 17.91f, 7.5f, 18.25f, 7.5f,
    CUBIC_TO, 18.94f, 7.5f, 19.5f, 8.08f, 19.5f, 8.79f, CUBIC_TO, 19.5f, 9.14f, 19.36f, 9.46f, 19.13f, 9.69f, LINE_TO, 12.88f, 16.12f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kChevronRepList, kChevronIcon, { kChevronPath, std::size(kChevronPath) })
VECTOR_ICON_REP_TEMPLATE(kClearPath, CANVAS_DIMENSIONS, 26, MOVE_TO, 7.92f, 20.5f, R_ARC_TO, 126.99f, 126.99f, 0, 0, 1, -5.77f, -5.01f, R_ARC_TO, 3.27f, 3.27f,
    0, 0, 1, -0.3f, -4.7f, R_CUBIC_TO, 0.06f, -0.07f, 2.08f, -1.82f, 6.06f, -5.24f, R_CUBIC_TO, 0.71f, -0.61f, 1.52f, -0.54f, 2.54f, -0.54f, R_CUBIC_TO, 0.01f,
    -0.01f, 2.04f, -0.01f, 6.1f, 0, CUBIC_TO, 21.28f, 5, 24.99f, 8.38f, 25, 12.97f, CUBIC_TO, 25, 17.6f, 21.29f, 21, 16.55f, 21, R_H_LINE_TO, -6.13f,
    R_CUBIC_TO, -0.98f, 0, -2, 0, -2.5f, -0.5f, CLOSE, MOVE_TO, 21, 9.97f, LINE_TO, 20.03f, 9, LINE_TO, 17, 12.03f, LINE_TO, 13.97f, 9, R_LINE_TO, -0.97f,
    0.97f, LINE_TO, 16.03f, 13, LINE_TO, 13, 16.03f, R_LINE_TO, 0.97f, 0.97f, LINE_TO, 17, 13.97f, LINE_TO, 20.03f, 17, R_LINE_TO, 0.97f, -0.97f, LINE_TO,
    17.97f, 13, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kClearRepList, kClearIcon, { kClearPath, std::size(kClearPath) })
VECTOR_ICON_REP_TEMPLATE(kClockPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 7.99f, 1, ARC_TO, 7, 7, 0, 0, 1, 15, 8, R_CUBIC_TO, 0, 3.86f, -3.14f, 7, -7.01f, 7, ARC_TO,
    7, 7, 0, 0, 1, 1, 8, R_CUBIC_TO, 0, -3.86f, 3.13f, -7, 6.99f, -7, CLOSE, MOVE_TO, 8, 13.6f, R_CUBIC_TO, 3.09f, 0, 5.6f, -2.51f, 5.6f, -5.6f,
    CUBIC_TO_SHORTHAND, 11.09f, 2.4f, 8, 2.4f, ARC_TO, 5.6f, 5.6f, 0, 0, 0, 2.4f, 8, R_CUBIC_TO, 0, 3.09f, 2.51f, 5.6f, 5.6f, 5.6f, CLOSE, R_MOVE_TO, 0.35f,
    -9.1f, R_V_LINE_TO, 3.68f, R_LINE_TO, 3.15f, 1.87f, R_LINE_TO, -0.52f, 0.86f, LINE_TO, 7.3f, 8.7f, V_LINE_TO, 4.5f, R_H_LINE_TO, 1.05f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kClockRepList, kClockIcon, { kClockPath, std::size(kClockPath) })
VECTOR_ICON_REP_TEMPLATE(kClockChromeRefreshPath, CANVAS_DIMENSIONS, 16, R_MOVE_TO, 10.17f, 10.86f, R_LINE_TO, 0.94f, -0.93f, LINE_TO, 8.66f, 7.47f,
    R_V_LINE_TO, -3.45f, H_LINE_TO, 7.34f, R_V_LINE_TO, 4, CLOSE, MOVE_TO, 8, 14.54f, R_CUBIC_TO, -0.9f, 0, -1.75f, -0.17f, -2.54f, -0.51f, R_ARC_TO, 6.55f,
    6.55f, 0, 0, 1, -2.08f, -1.4f, R_ARC_TO, 6.52f, 6.52f, 0, 0, 1, -1.4f, -2.08f, R_ARC_TO, 6.33f, 6.33f, 0, 0, 1, -0.51f, -2.55f, R_CUBIC_TO, 0, -0.91f,
    0.17f, -1.75f, 0.51f, -2.55f, R_ARC_TO, 6.4f, 6.4f, 0, 0, 1, 1.4f, -2.07f, ARC_TO, 6.63f, 6.63f, 0, 0, 1, 5.46f, 1.98f, R_ARC_TO, 6.33f, 6.33f, 0, 0, 1,
    2.55f, -0.51f, R_ARC_TO, 6.33f, 6.33f, 0, 0, 1, 2.55f, 0.52f, R_ARC_TO, 6.55f, 6.55f, 0, 0, 1, 2.07f, 1.4f, R_ARC_TO, 6.59f, 6.59f, 0, 0, 1, 1.39f, 2.07f,
    R_CUBIC_TO, 0.34f, 0.79f, 0.51f, 1.65f, 0.51f, 2.55f, R_CUBIC_TO, 0, 0.9f, -0.17f, 1.75f, -0.51f, 2.54f, R_ARC_TO, 6.66f, 6.66f, 0, 0, 1, -1.39f, 2.08f,
    R_ARC_TO, 6.4f, 6.4f, 0, 0, 1, -2.07f, 1.4f, ARC_TO, 6.38f, 6.38f, 0, 0, 1, 8, 14.54f, CLOSE, MOVE_TO, 8, 8, CLOSE, R_MOVE_TO, 0.01f, 5.15f, R_CUBIC_TO,
    1.43f, 0, 2.64f, -0.5f, 3.64f, -1.51f, R_CUBIC_TO, 1, -1.01f, 1.5f, -2.22f, 1.5f, -3.65f, R_CUBIC_TO, 0, -1.43f, -0.5f, -2.64f, -1.5f, -3.64f, R_CUBIC_TO,
    -1, -1, -2.21f, -1.5f, -3.64f, -1.5f, R_CUBIC_TO, -1.43f, 0, -2.64f, 0.5f, -3.65f, 1.5f, R_CUBIC_TO, -1.01f, 1, -1.51f, 2.22f, -1.51f, 3.64f, R_CUBIC_TO, 0,
    1.43f, 0.5f, 2.65f, 1.51f, 3.65f, R_CUBIC_TO, 1.01f, 1, 2.22f, 1.51f, 3.65f, 1.51f, CLOSE, R_MOVE_TO, 0, 0, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kClockChromeRefreshRepList, kClockChromeRefreshIcon, { kClockChromeRefreshPath, std::size(kClockChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kCookieChromeRefreshPath, CANVAS_DIMENSIONS, 20, MOVE_TO, 8.75f, 8.5f, R_CUBIC_TO, 0.35f, 0, 0.64f, -0.12f, 0.89f, -0.36f, R_CUBIC_TO,
    0.25f, -0.24f, 0.36f, -0.54f, 0.36f, -0.89f, R_CUBIC_TO, 0, -0.35f, -0.12f, -0.64f, -0.36f, -0.89f, CUBIC_TO_SHORTHAND, 9.1f, 6, 8.75f, 6, R_CUBIC_TO,
    -0.35f, 0, -0.64f, 0.12f, -0.89f, 0.36f, R_CUBIC_TO, -0.25f, 0.24f, -0.36f, 0.54f, -0.36f, 0.89f, R_CUBIC_TO, 0, 0.35f, 0.12f, 0.64f, 0.36f, 0.89f,
    R_CUBIC_TO, 0.24f, 0.25f, 0.54f, 0.36f, 0.89f, 0.36f, CLOSE, R_MOVE_TO, -2, 4, R_CUBIC_TO, 0.35f, 0, 0.64f, -0.12f, 0.89f, -0.36f, R_CUBIC_TO, 0.25f,
    -0.24f, 0.36f, -0.54f, 0.36f, -0.89f, R_CUBIC_TO, 0, -0.35f, -0.12f, -0.64f, -0.36f, -0.89f, CUBIC_TO_SHORTHAND, 7.1f, 10, 6.75f, 10, R_CUBIC_TO, -0.35f, 0,
    -0.64f, 0.12f, -0.89f, 0.36f, R_CUBIC_TO, -0.25f, 0.24f, -0.36f, 0.54f, -0.36f, 0.89f, R_CUBIC_TO, 0, 0.35f, 0.12f, 0.64f, 0.36f, 0.89f, R_CUBIC_TO, 0.24f,
    0.25f, 0.54f, 0.36f, 0.89f, 0.36f, CLOSE, R_MOVE_TO, 5.75f, 0.75f, R_CUBIC_TO, 0.21f, 0, 0.39f, -0.07f, 0.54f, -0.21f, R_CUBIC_TO, 0.15f, -0.14f, 0.22f,
    -0.32f, 0.22f, -0.53f, R_CUBIC_TO, 0, -0.21f, -0.07f, -0.39f, -0.21f, -0.54f, R_CUBIC_TO, -0.14f, -0.15f, -0.32f, -0.22f, -0.53f, -0.22f, R_CUBIC_TO,
    -0.21f, 0, -0.39f, 0.07f, -0.54f, 0.21f, R_CUBIC_TO, -0.15f, 0.14f, -0.22f, 0.32f, -0.22f, 0.53f, R_CUBIC_TO, 0, 0.21f, 0.07f, 0.39f, 0.21f, 0.54f,
    R_CUBIC_TO, 0.14f, 0.15f, 0.32f, 0.22f, 0.53f, 0.22f, CLOSE, MOVE_TO, 10, 18, R_CUBIC_TO, -1.1f, 0, -2.14f, -0.21f, -3.11f, -0.63f, R_CUBIC_TO, -0.97f,
    -0.42f, -1.82f, -0.99f, -2.55f, -1.72f, R_CUBIC_TO, -0.73f, -0.73f, -1.3f, -1.58f, -1.72f, -2.55f, R_CUBIC_TO, -0.42f, -0.97f, -0.63f, -2.01f, -0.63f,
    -3.11f, R_CUBIC_TO, 0, -1.29f, 0.28f, -2.49f, 0.84f, -3.59f, R_CUBIC_TO, 0.56f, -1.1f, 1.3f, -2.02f, 2.22f, -2.76f, CUBIC_TO, 5.97f, 2.9f, 7, 2.39f, 8.15f,
    2.1f, R_CUBIC_TO, 1.15f, -0.29f, 2.32f, -0.27f, 3.5f, 0.06f, R_CUBIC_TO, -0.11f, 0.61f, -0.08f, 1.17f, 0.1f, 1.69f, R_CUBIC_TO, 0.18f, 0.52f, 0.47f, 0.94f,
    0.85f, 1.28f, R_CUBIC_TO, 0.38f, 0.34f, 0.86f, 0.58f, 1.42f, 0.71f, R_CUBIC_TO, 0.56f, 0.13f, 1.15f, 0.12f, 1.77f, -0.03f, R_CUBIC_TO, -0.35f, 0.79f, -0.3f,
    1.55f, 0.16f, 2.26f, R_CUBIC_TO, 0.45f, 0.72f, 1.11f, 1.09f, 1.99f, 1.11f, R_CUBIC_TO, 0.13f, 1.18f, 0, 2.3f, -0.38f, 3.37f, R_CUBIC_TO, -0.38f, 1.06f,
    -0.93f, 2, -1.65f, 2.8f, R_CUBIC_TO, -0.73f, 0.81f, -1.6f, 1.45f, -2.62f, 1.93f, R_CUBIC_TO, -1.02f, 0.48f, -2.12f, 0.72f, -3.31f, 0.72f, CLOSE, R_MOVE_TO,
    0, -1.5f, R_CUBIC_TO, 1.74f, 0, 3.23f, -0.59f, 4.47f, -1.76f, R_CUBIC_TO, 1.24f, -1.17f, 1.92f, -2.63f, 2.03f, -4.36f, R_CUBIC_TO, -0.63f, -0.25f, -1.15f,
    -0.64f, -1.56f, -1.16f, R_CUBIC_TO, -0.41f, -0.52f, -0.68f, -1.11f, -0.79f, -1.78f, R_CUBIC_TO, -1.06f, -0.15f, -1.95f, -0.59f, -2.69f, -1.31f, R_CUBIC_TO,
    -0.74f, -0.72f, -1.17f, -1.6f, -1.31f, -2.63f, R_CUBIC_TO, -0.88f, -0.06f, -1.71f, 0.08f, -2.51f, 0.41f, R_ARC_TO, 6.71f, 6.71f, 0, 0, 0, -3.6f, 3.5f,
    R_CUBIC_TO, -0.36f, 0.81f, -0.54f, 1.68f, -0.54f, 2.59f, R_CUBIC_TO, 0, 1.8f, 0.63f, 3.33f, 1.9f, 4.6f, R_CUBIC_TO, 1.27f, 1.27f, 2.8f, 1.9f, 4.6f, 1.9f,
    CLOSE)
VECTOR_ICON_TEMPLATE_CC(kCookieChromeRefreshRepList, kCookieChromeRefreshIcon, { kCookieChromeRefreshPath, std::size(kCookieChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kDinoPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 14.67f, 3.67f, R_V_LINE_TO, -3, H_LINE_TO, 14, V_LINE_TO, 0, H_LINE_TO, 8.67f, R_V_LINE_TO,
    0.67f, H_LINE_TO, 8, V_LINE_TO, 5, R_H_LINE_TO, -0.67f, R_V_LINE_TO, 0.67f, R_H_LINE_TO, -1, R_V_LINE_TO, 0.67f, R_H_LINE_TO, -1, V_LINE_TO, 7, R_H_LINE_TO,
    -0.67f, R_V_LINE_TO, 0.67f, H_LINE_TO, 3.33f, V_LINE_TO, 7, R_H_LINE_TO, -0.67f, R_V_LINE_TO, -0.67f, H_LINE_TO, 2, V_LINE_TO, 5, R_H_LINE_TO, -0.67f,
    R_V_LINE_TO, 4, H_LINE_TO, 2, R_V_LINE_TO, 0.67f, R_H_LINE_TO, 0.67f, R_V_LINE_TO, 0.67f, R_H_LINE_TO, 0.67f, V_LINE_TO, 11, H_LINE_TO, 4, R_V_LINE_TO,
    0.67f, R_H_LINE_TO, 0.67f, R_V_LINE_TO, 2.67f, H_LINE_TO, 6, R_V_LINE_TO, -0.67f, R_H_LINE_TO, -0.67f, V_LINE_TO, 13, H_LINE_TO, 6, R_V_LINE_TO, -0.67f,
    R_H_LINE_TO, 0.67f, R_V_LINE_TO, -0.67f, R_H_LINE_TO, 0.67f, R_V_LINE_TO, 0.67f, H_LINE_TO, 8, R_V_LINE_TO, 2, R_H_LINE_TO, 1.33f, R_V_LINE_TO, -0.67f,
    R_H_LINE_TO, -0.67f, V_LINE_TO, 11, R_H_LINE_TO, 0.67f, R_V_LINE_TO, -0.67f, H_LINE_TO, 10, R_V_LINE_TO, -1, R_H_LINE_TO, 0.67f, V_LINE_TO, 7, R_H_LINE_TO,
    0.67f, R_V_LINE_TO, 0.67f, H_LINE_TO, 12, V_LINE_TO, 6.33f, R_H_LINE_TO, -1.33f, V_LINE_TO, 5, R_H_LINE_TO, 2.67f, R_V_LINE_TO, -0.67f, R_H_LINE_TO, -2,
    R_V_LINE_TO, -0.67f, R_H_LINE_TO, 3.33f, CLOSE, R_MOVE_TO, -4.67f, -2, R_H_LINE_TO, -0.67f, V_LINE_TO, 1, H_LINE_TO, 10, R_V_LINE_TO, 0.67f, CLOSE, MOVE_TO,
    3.33f, 12.33f, H_LINE_TO, 0.67f, V_LINE_TO, 12, R_H_LINE_TO, 2.67f, R_V_LINE_TO, 0.33f, CLOSE, R_MOVE_TO, 12, 0, H_LINE_TO, 10, V_LINE_TO, 12, R_H_LINE_TO,
    5.33f, R_V_LINE_TO, 0.33f, CLOSE, MOVE_TO, 4, 13.67f, H_LINE_TO, 2.67f, R_V_LINE_TO, -0.33f, H_LINE_TO, 4, R_V_LINE_TO, 0.33f, CLOSE, R_MOVE_TO, -2, 1,
    H_LINE_TO, 0.67f, R_V_LINE_TO, -0.33f, H_LINE_TO, 2, R_V_LINE_TO, 0.33f, CLOSE, R_MOVE_TO, 12.67f, -0.33f, R_H_LINE_TO, -0.33f, V_LINE_TO, 14, R_H_LINE_TO,
    0.33f, R_V_LINE_TO, 0.33f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kDinoRepList, kDinoIcon, { kDinoPath, std::size(kDinoPath) })
VECTOR_ICON_REP_TEMPLATE(kDinoCr2023Path, CANVAS_DIMENSIONS, 16, MOVE_TO, 4.75f, 15.25f, R_V_LINE_TO, -2.6f, R_H_LINE_TO, -0.65f, V_LINE_TO, 12, R_H_LINE_TO,
    -0.65f, R_V_LINE_TO, -0.65f, R_H_LINE_TO, -0.65f, R_V_LINE_TO, -0.66f, R_H_LINE_TO, -0.66f, R_V_LINE_TO, -0.65f, R_H_LINE_TO, -0.65f, V_LINE_TO, 6.13f,
    R_H_LINE_TO, 0.65f, R_V_LINE_TO, 1.3f, R_H_LINE_TO, 0.65f, R_V_LINE_TO, 0.65f, R_H_LINE_TO, 0.65f, R_V_LINE_TO, 0.64f, R_H_LINE_TO, 1.31f, R_V_LINE_TO,
    -0.64f, R_H_LINE_TO, 0.64f, R_LINE_TO, 0.01f, -0.64f, H_LINE_TO, 6.45f, V_LINE_TO, 6.79f, R_H_LINE_TO, 1.06f, R_V_LINE_TO, -0.66f, R_H_LINE_TO, 0.64f,
    V_LINE_TO, 1.96f, R_H_LINE_TO, 0.65f, R_V_LINE_TO, -0.65f, R_H_LINE_TO, 5.09f, R_V_LINE_TO, 0.65f, R_H_LINE_TO, 0.65f, V_LINE_TO, 4.82f, R_H_LINE_TO,
    -3.26f, R_V_LINE_TO, 0.65f, R_H_LINE_TO, 1.95f, R_V_LINE_TO, 0.66f, H_LINE_TO, 10.62f, R_V_LINE_TO, 1.3f, R_H_LINE_TO, 1.3f, R_V_LINE_TO, 1.3f, R_H_LINE_TO,
    -0.65f, R_V_LINE_TO, -0.65f, R_H_LINE_TO, -0.65f, V_LINE_TO, 10.3f, R_H_LINE_TO, -0.65f, R_V_LINE_TO, 0.91f, R_H_LINE_TO, -0.65f, R_V_LINE_TO, 0.65f,
    R_H_LINE_TO, -0.66f, R_V_LINE_TO, 2.75f, R_H_LINE_TO, 0.66f, R_V_LINE_TO, 0.65f, H_LINE_TO, 8.02f, R_V_LINE_TO, -1.94f, R_H_LINE_TO, -0.65f, R_V_LINE_TO,
    -0.65f, R_H_LINE_TO, -0.66f, R_V_LINE_TO, 0.65f, R_H_LINE_TO, -0.66f, R_V_LINE_TO, 0.65f, R_H_LINE_TO, -0.66f, R_V_LINE_TO, 0.65f, R_H_LINE_TO, 0.66f,
    R_V_LINE_TO, 0.65f, CLOSE, MOVE_TO, 9.3f, 2.96f, R_H_LINE_TO, 0.65f, V_LINE_TO, 2.3f, R_H_LINE_TO, -0.64f, CLOSE, MOVE_TO, 0.85f, 13.37f, R_H_LINE_TO, 2.6f,
    R_V_LINE_TO, -0.32f, H_LINE_TO, 0.84f, CLOSE, R_MOVE_TO, 9.12f, 0, R_H_LINE_TO, 5.19f, R_V_LINE_TO, -0.32f, H_LINE_TO, 9.97f, CLOSE, MOVE_TO, 2.8f, 14.68f,
    R_H_LINE_TO, 1.3f, R_V_LINE_TO, -0.32f, H_LINE_TO, 2.8f, CLOSE, R_MOVE_TO, -1.96f, 0.98f, R_H_LINE_TO, 1.29f, R_V_LINE_TO, -0.34f, H_LINE_TO, 0.84f, CLOSE,
    R_MOVE_TO, 13.37f, -0.34f, R_H_LINE_TO, 0.32f, V_LINE_TO, 15, R_H_LINE_TO, -0.32f, CLOSE, R_MOVE_TO, 0, 0, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kDinoCr2023RepList, kDinoCr2023Icon, { kDinoCr2023Path, std::size(kDinoCr2023Path) })
VECTOR_ICON_REP_TEMPLATE(kDriveDocsPath, CANVAS_DIMENSIONS, 16, PATH_COLOR_ARGB, 0xFF, 0x42, 0x85, 0xF4, MOVE_TO, 14, 0, H_LINE_TO, 2, CUBIC_TO, 0.9f, 0, 0,
    0.9f, 0, 2, R_V_LINE_TO, 12, R_CUBIC_TO, 0, 1.1f, 0.9f, 2, 2, 2, R_H_LINE_TO, 12, R_CUBIC_TO, 1.1f, 0, 2, -0.9f, 2, -2, V_LINE_TO, 2, R_CUBIC_TO, 0, -1.1f,
    -0.9f, -2, -2, -2, CLOSE, MOVE_TO, 3, 3, H_LINE_TO, 13, V_LINE_TO, 5, H_LINE_TO, 3, CLOSE, MOVE_TO, 3, 7, H_LINE_TO, 13, V_LINE_TO, 9, H_LINE_TO, 3, CLOSE,
    MOVE_TO, 3, 11, H_LINE_TO, 9, V_LINE_TO, 13, H_LINE_TO, 3, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kDriveDocsRepList, kDriveDocsIcon, { kDriveDocsPath, std::size(kDriveDocsPath) })
VECTOR_ICON_REP_TEMPLATE(kDriveFolderPath, PATH_COLOR_ARGB, 0xFF, 0x5F, 0x63, 0x68, MOVE_TO, 20, 8, H_LINE_TO, 8, R_CUBIC_TO, -2.21f, 0, -3.98f, 1.79f, -3.98f,
    4, LINE_TO, 4, 36, R_CUBIC_TO, 0, 2.21f, 1.79f, 4, 4, 4, R_H_LINE_TO, 32, R_CUBIC_TO, 2.21f, 0, 4, -1.79f, 4, -4, V_LINE_TO, 16, R_CUBIC_TO, 0, -2.21f,
    -1.79f, -4, -4, -4, H_LINE_TO, 24, R_LINE_TO, -4, -4, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kDriveFolderRepList, kDriveFolderIcon, { kDriveFolderPath, std::size(kDriveFolderPath) })
VECTOR_ICON_REP_TEMPLATE(kDriveFormsPath, CANVAS_DIMENSIONS, 18, PATH_COLOR_ARGB, 0xFF, 0x67, 0x3A, 0xB7, MOVE_TO, 16, 0, H_LINE_TO, 2, CUBIC_TO, 0.9f, 0, 0,
    0.9f, 0, 2, R_V_LINE_TO, 14, R_CUBIC_TO, 0, 1.1f, 0.9f, 2, 2, 2, R_H_LINE_TO, 14, R_CUBIC_TO, 1.1f, 0, 2, -0.9f, 2, -2, V_LINE_TO, 2, R_CUBIC_TO, 0, -1.1f,
    -0.9f, -2, -2, -2, CLOSE, MOVE_TO, 6, 14, H_LINE_TO, 4, R_V_LINE_TO, -2, R_H_LINE_TO, 2, CLOSE, R_MOVE_TO, 0, -4, H_LINE_TO, 4, V_LINE_TO, 8, R_H_LINE_TO,
    2, CLOSE, R_MOVE_TO, 0, -4, H_LINE_TO, 4, V_LINE_TO, 4, R_H_LINE_TO, 2, CLOSE, R_MOVE_TO, 8, 8, H_LINE_TO, 7, R_V_LINE_TO, -2, R_H_LINE_TO, 7, CLOSE,
    R_MOVE_TO, 0, -4, H_LINE_TO, 7, V_LINE_TO, 8, R_H_LINE_TO, 7, CLOSE, R_MOVE_TO, 0, -4, H_LINE_TO, 7, V_LINE_TO, 4, R_H_LINE_TO, 7, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kDriveFormsRepList, kDriveFormsIcon, { kDriveFormsPath, std::size(kDriveFormsPath) })
VECTOR_ICON_REP_TEMPLATE(kDriveImagePath, CANVAS_DIMENSIONS, 16, PATH_COLOR_ARGB, 0xFF, 0xD9, 0x30, 0x25, MOVE_TO, 16, 14, V_LINE_TO, 2, R_CUBIC_TO, 0, -1, -1,
    -2, -2, -2, H_LINE_TO, 2, CUBIC_TO, 1, 0, 0, 1, 0, 2, V_LINE_TO, 14, R_CUBIC_TO, 0, 1, 1, 2, 2, 2, H_LINE_TO, 14, R_CUBIC_TO, 1, 0, 2, -1, 2, -2, CLOSE,
    MOVE_TO, 5, 9, R_LINE_TO, 2, 3, R_LINE_TO, 3, -4, R_LINE_TO, 4, 5, H_LINE_TO, 2, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kDriveImageRepList, kDriveImageIcon, { kDriveImagePath, std::size(kDriveImagePath) })
VECTOR_ICON_REP_TEMPLATE(kDriveLogoPath, CANVAS_DIMENSIONS, 192, PATH_COLOR_ARGB, 0xFF, 0x42, 0x85, 0xF4, MOVE_TO, 33, 124, R_V_LINE_TO, 52, R_H_LINE_TO, 126,
    R_LINE_TO, 29, -52, H_LINE_TO, 33, NEW_PATH, PATH_COLOR_ARGB, 0xFF, 0x0F, 0x9D, 0x58, MOVE_TO, 66, 16, LINE_TO, 4, 124, R_LINE_TO, 29, 52, R_LINE_TO, 71,
    -122, R_LINE_TO, -38, -38, NEW_PATH, PATH_COLOR_ARGB, 0xFF, 0xFC, 0xB7, 0x00, MOVE_TO, 126, 16, H_LINE_TO, 66, R_LINE_TO, 63, 108, R_H_LINE_TO, 59, LINE_TO,
    126, 16, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kDriveLogoRepList, kDriveLogoIcon, { kDriveLogoPath, std::size(kDriveLogoPath) })
VECTOR_ICON_REP_TEMPLATE(kDrivePdfPath, CANVAS_DIMENSIONS, 32, PATH_COLOR_ARGB, 0xFF, 0xEA, 0x43, 0x35, MOVE_TO, 7.1f, 15.1f, H_LINE_TO, 9, R_V_LINE_TO, -1.8f,
    H_LINE_TO, 7, CLOSE, MOVE_TO, 28.4f, 0, H_LINE_TO, 3.6f, CUBIC_TO, 1.6f, 0, 0, 1.6f, 0, 3.6f, R_V_LINE_TO, 24.8f, R_CUBIC_TO, 0, 2, 1.6f, 3.6f, 3.6f, 3.6f,
    R_H_LINE_TO, 24.8f, R_CUBIC_TO, 2, 0, 3.6f, -1.6f, 3.6f, -3.6f, V_LINE_TO, 3.6f, R_CUBIC_TO, 0, -2, -1.6f, -3.6f, -3.6f, -3.6f, CLOSE, MOVE_TO, 11.6f,
    15.1f, R_CUBIC_TO, 0, 1.5f, -1.2f, 2.7f, -2.7f, 2.7f, H_LINE_TO, 7, R_V_LINE_TO, 3.5f, H_LINE_TO, 4.4f, V_LINE_TO, 10.7f, H_LINE_TO, 9, R_CUBIC_TO, 1.5f, 0,
    2.7f, 1.2f, 2.7f, 2.6f, CLOSE, R_MOVE_TO, 17.7f, -1.8f, H_LINE_TO, 25, R_V_LINE_TO, 1.8f, R_H_LINE_TO, 2.7f, R_V_LINE_TO, 2.7f, R_H_LINE_TO, -2.7f,
    R_V_LINE_TO, 3.5f, R_H_LINE_TO, -2.7f, V_LINE_TO, 10.7f, R_H_LINE_TO, 7.1f, CLOSE, R_MOVE_TO, -8.9f, 5.4f, R_CUBIC_TO, 0, 1.4f, -1.1f, 2.6f, -2.6f, 2.6f,
    R_H_LINE_TO, -4.5f, V_LINE_TO, 10.7f, R_H_LINE_TO, 4.5f, R_CUBIC_TO, 1.5f, 0, 2.6f, 1.2f, 2.6f, 2.6f, CLOSE, R_MOVE_TO, -4.4f, 0, R_H_LINE_TO, 1.8f,
    R_V_LINE_TO, -5.4f, H_LINE_TO, 16, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kDrivePdfRepList, kDrivePdfIcon, { kDrivePdfPath, std::size(kDrivePdfPath) })
VECTOR_ICON_REP_TEMPLATE(kDriveSheetsPath, CANVAS_DIMENSIONS, 16, PATH_COLOR_ARGB, 0xFF, 0x0F, 0x9D, 0x58, MOVE_TO, 14, 0, H_LINE_TO, 2, CUBIC_TO, 0.9f, 0, 0,
    0.9f, 0, 2, R_V_LINE_TO, 12, R_CUBIC_TO, 0, 1.1f, 0.9f, 2, 2, 2, R_H_LINE_TO, 12, R_CUBIC_TO, 1.1f, 0, 2, -0.9f, 2, -2, V_LINE_TO, 2, R_CUBIC_TO, 0, -1.1f,
    -0.9f, -2, -2, -2, CLOSE, MOVE_TO, 2, 5, H_LINE_TO, 14, R_V_LINE_TO, 2, H_LINE_TO, 2, MOVE_TO, 5, 2, R_H_LINE_TO, 2, V_LINE_TO, 5, R_H_LINE_TO, -2, MOVE_TO,
    5, 7, R_H_LINE_TO, 2, V_LINE_TO, 14, R_H_LINE_TO, -2, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kDriveSheetsRepList, kDriveSheetsIcon, { kDriveSheetsPath, std::size(kDriveSheetsPath) })
VECTOR_ICON_REP_TEMPLATE(kDriveSlidesPath, CANVAS_DIMENSIONS, 16, PATH_COLOR_ARGB, 0xFF, 0xF4, 0xB4, 0x00, MOVE_TO, 14, 0, H_LINE_TO, 2, CUBIC_TO, 0.9f, 0, 0,
    0.9f, 0, 2, R_V_LINE_TO, 12, R_CUBIC_TO, 0, 1.1f, 0.9f, 2, 2, 2, R_H_LINE_TO, 12, R_CUBIC_TO, 1.1f, 0, 2, -0.9f, 2, -2, V_LINE_TO, 2, R_CUBIC_TO, 0, -1.1f,
    -0.9f, -2, -2, -2, CLOSE, MOVE_TO, 2, 4, H_LINE_TO, 14, V_LINE_TO, 12, H_LINE_TO, 2, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kDriveSlidesRepList, kDriveSlidesIcon, { kDriveSlidesPath, std::size(kDriveSlidesPath) })
VECTOR_ICON_REP_TEMPLATE(kDriveVideoPath, CANVAS_DIMENSIONS, 16, PATH_COLOR_ARGB, 0xFF, 0xEA, 0x43, 0x35, MOVE_TO, 12.8f, 2, R_LINE_TO, 1.6f, 2.6f, H_LINE_TO,
    12, LINE_TO, 10.4f, 2, H_LINE_TO, 8.8f, R_LINE_TO, 1.6f, 2.6f, H_LINE_TO, 8, LINE_TO, 6.4f, 2, H_LINE_TO, 4.8f, R_LINE_TO, 1.6f, 2.6f, H_LINE_TO, 4,
    LINE_TO, 2.4f, 2, R_H_LINE_TO, -0.8f, CUBIC_TO, 0.7f, 2, 0, 2.7f, 0, 3.5f, R_V_LINE_TO, 9, R_CUBIC_TO, 0, 0.8f, 0.7f, 1.5f, 1.6f, 1.5f, R_H_LINE_TO, 12.8f,
    R_CUBIC_TO, 0.9f, 0, 1.6f, -0.7f, 1.6f, -1.5f, V_LINE_TO, 2, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kDriveVideoRepList, kDriveVideoIcon, { kDriveVideoPath, std::size(kDriveVideoPath) })
VECTOR_ICON_REP_TEMPLATE(kEnterprisePath, CANVAS_DIMENSIONS, 24, MOVE_TO, 16, 17, R_H_LINE_TO, 2, R_V_LINE_TO, -2, R_H_LINE_TO, -2, R_V_LINE_TO, 2, CLOSE,
    R_MOVE_TO, 0, -4, R_H_LINE_TO, 2, R_V_LINE_TO, -2, R_H_LINE_TO, -2, R_V_LINE_TO, 2, CLOSE, R_MOVE_TO, 4, 6, R_H_LINE_TO, -8, R_V_LINE_TO, -2, R_H_LINE_TO,
    2, R_V_LINE_TO, -2, R_H_LINE_TO, -2, R_V_LINE_TO, -2, R_H_LINE_TO, 2, R_V_LINE_TO, -2, R_H_LINE_TO, -2, V_LINE_TO, 9, R_H_LINE_TO, 8, R_V_LINE_TO, 10,
    CLOSE, MOVE_TO, 8, 7, R_H_LINE_TO, 2, V_LINE_TO, 5, H_LINE_TO, 8, R_V_LINE_TO, 2, CLOSE, R_MOVE_TO, 0, 4, R_H_LINE_TO, 2, V_LINE_TO, 9, H_LINE_TO, 8,
    R_V_LINE_TO, 2, CLOSE, R_MOVE_TO, 0, 4, R_H_LINE_TO, 2, R_V_LINE_TO, -2, H_LINE_TO, 8, R_V_LINE_TO, 2, CLOSE, R_MOVE_TO, 0, 4, R_H_LINE_TO, 2, R_V_LINE_TO,
    -2, H_LINE_TO, 8, R_V_LINE_TO, 2, CLOSE, MOVE_TO, 4, 7, R_H_LINE_TO, 2, V_LINE_TO, 5, H_LINE_TO, 4, R_V_LINE_TO, 2, CLOSE, R_MOVE_TO, 0, 4, R_H_LINE_TO, 2,
    V_LINE_TO, 9, H_LINE_TO, 4, R_V_LINE_TO, 2, CLOSE, R_MOVE_TO, 0, 4, R_H_LINE_TO, 2, R_V_LINE_TO, -2, H_LINE_TO, 4, R_V_LINE_TO, 2, CLOSE, R_MOVE_TO, 0, 4,
    R_H_LINE_TO, 2, R_V_LINE_TO, -2, H_LINE_TO, 4, R_V_LINE_TO, 2, CLOSE, R_MOVE_TO, 8, -12, V_LINE_TO, 3, H_LINE_TO, 2, R_V_LINE_TO, 18, R_H_LINE_TO, 20,
    V_LINE_TO, 7, H_LINE_TO, 12, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kEnterprise12Path, CANVAS_DIMENSIONS, 12, MOVE_TO, 8, 9, R_H_LINE_TO, 1, V_LINE_TO, 8, H_LINE_TO, 8, R_V_LINE_TO, 1, CLOSE, R_MOVE_TO,
    0, -2, R_H_LINE_TO, 1, V_LINE_TO, 6, H_LINE_TO, 8, R_V_LINE_TO, 1, CLOSE, MOVE_TO, 4, 4, R_H_LINE_TO, 1, V_LINE_TO, 3, H_LINE_TO, 4, R_V_LINE_TO, 1, CLOSE,
    R_MOVE_TO, 0, 2, R_H_LINE_TO, 1, V_LINE_TO, 5, H_LINE_TO, 4, R_V_LINE_TO, 1, CLOSE, R_MOVE_TO, 0, 2, R_H_LINE_TO, 1, V_LINE_TO, 7, H_LINE_TO, 4,
    R_V_LINE_TO, 1, CLOSE, R_MOVE_TO, 0, 2, R_H_LINE_TO, 1, V_LINE_TO, 9, H_LINE_TO, 4, R_V_LINE_TO, 1, CLOSE, MOVE_TO, 2, 4, R_H_LINE_TO, 1, V_LINE_TO, 3,
    H_LINE_TO, 2, R_V_LINE_TO, 1, CLOSE, R_MOVE_TO, 0, 2, R_H_LINE_TO, 1, V_LINE_TO, 5, H_LINE_TO, 2, R_V_LINE_TO, 1, CLOSE, R_MOVE_TO, 0, 2, R_H_LINE_TO, 1,
    V_LINE_TO, 7, H_LINE_TO, 2, R_V_LINE_TO, 1, CLOSE, R_MOVE_TO, 0, 2, R_H_LINE_TO, 1, V_LINE_TO, 9, H_LINE_TO, 2, R_V_LINE_TO, 1, CLOSE, R_MOVE_TO, 4, -6,
    V_LINE_TO, 2, H_LINE_TO, 1, R_V_LINE_TO, 9, R_H_LINE_TO, 10, V_LINE_TO, 4, H_LINE_TO, 6, CLOSE, R_MOVE_TO, 4, 6, H_LINE_TO, 6, V_LINE_TO, 9, R_H_LINE_TO, 1,
    V_LINE_TO, 8, H_LINE_TO, 6, V_LINE_TO, 7, R_H_LINE_TO, 1, V_LINE_TO, 6, H_LINE_TO, 6, V_LINE_TO, 5, R_H_LINE_TO, 4, R_V_LINE_TO, 5, CLOSE)
VECTOR_ICON_TEMPLATE_CC(
    kEnterpriseRepList, kEnterpriseIcon, { kEnterprisePath, std::size(kEnterprisePath) }, { kEnterprise12Path, std::size(kEnterprise12Path) })
VECTOR_ICON_REP_TEMPLATE(kExtensionAppPath, CANVAS_DIMENSIONS, 32, MOVE_TO, 24, 14, LINE_TO, 24, 10, CUBIC_TO, 24, 9, 23, 8, 22, 8, LINE_TO, 18, 8, LINE_TO, 18,
    6, CUBIC_TO, 17.57f, 4.28f, 16.5f, 3, 15, 3, CUBIC_TO, 13.5f, 3, 11.86f, 4.28f, 12, 6, LINE_TO, 12, 8, LINE_TO, 7, 8, CUBIC_TO, 6, 8, 5, 9, 5, 10, LINE_TO,
    5, 14, LINE_TO, 7, 14, CUBIC_TO, 8.42f, 14.2f, 9.8f, 15.58f, 10, 17, CUBIC_TO, 9.8f, 18.99f, 8.42f, 20.37f, 7, 20, LINE_TO, 5, 20, LINE_TO, 5, 25, CUBIC_TO,
    5, 25.97f, 6.03f, 27, 7, 27, LINE_TO, 12, 27, LINE_TO, 12, 25, CUBIC_TO, 11.63f, 23.58f, 13.01f, 22.2f, 15, 22, CUBIC_TO, 16.42f, 22.2f, 17.8f, 23.58f, 18,
    25, LINE_TO, 18, 27, LINE_TO, 22, 27, CUBIC_TO, 23, 27, 24, 26, 24, 25, LINE_TO, 24, 20, LINE_TO, 26, 20, CUBIC_TO, 27.72f, 20.14f, 29, 18.5f, 29, 17,
    CUBIC_TO, 29, 15.5f, 27.72f, 14.43f, 26, 14, LINE_TO, 24, 14, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kExtensionApp16Path, CANVAS_DIMENSIONS, 16, MOVE_TO, 12.71f, 6.71f, LINE_TO, 12.71f, 4.43f, CUBIC_TO, 12.71f, 3.8f, 12.2f, 3.29f,
    11.57f, 3.29f, LINE_TO, 9.29f, 3.29f, LINE_TO, 9.29f, 2.43f, CUBIC_TO, 9.29f, 1.64f, 8.65f, 1, 7.86f, 1, CUBIC_TO, 7.07f, 1, 6.43f, 1.64f, 6.43f, 2.43f,
    LINE_TO, 6.43f, 3.29f, LINE_TO, 4.14f, 3.29f, CUBIC_TO, 3.51f, 3.29f, 3.01f, 3.8f, 3.01f, 4.43f, LINE_TO, 3.01f, 6.6f, LINE_TO, 3.86f, 6.6f, CUBIC_TO,
    4.71f, 6.6f, 5.4f, 7.29f, 5.4f, 8.14f, CUBIC_TO, 5.4f, 8.99f, 4.71f, 9.69f, 3.86f, 9.69f, LINE_TO, 3, 9.69f, LINE_TO, 3, 11.86f, CUBIC_TO, 3, 12.49f, 3.51f,
    13, 4.14f, 13, LINE_TO, 6.31f, 13, LINE_TO, 6.31f, 12.14f, CUBIC_TO, 6.31f, 11.29f, 7.01f, 10.6f, 7.86f, 10.6f, CUBIC_TO, 8.71f, 10.6f, 9.4f, 11.29f, 9.4f,
    12.14f, LINE_TO, 9.4f, 13, LINE_TO, 11.57f, 13, CUBIC_TO, 12.2f, 13, 12.71f, 12.49f, 12.71f, 11.86f, LINE_TO, 12.71f, 9.57f, LINE_TO, 13.57f, 9.57f,
    CUBIC_TO, 14.36f, 9.57f, 15, 8.93f, 15, 8.14f, CUBIC_TO, 15, 7.35f, 14.36f, 6.71f, 13.57f, 6.71f, LINE_TO, 12.71f, 6.71f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(
    kExtensionAppRepList, kExtensionAppIcon, { kExtensionAppPath, std::size(kExtensionAppPath) }, { kExtensionApp16Path, std::size(kExtensionApp16Path) })
VECTOR_ICON_REP_TEMPLATE(kFindInPageChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, R_MOVE_TO, 12.33f, 16.5f, R_LINE_TO, 1.5f, 1.5f, H_LINE_TO,
    5.5f, R_CUBIC_TO, -0.41f, 0, -0.77f, -0.15f, -1.06f, -0.44f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 4, 16.5f, R_V_LINE_TO, -13, R_CUBIC_TO, 0, -0.41f, 0.15f,
    -0.77f, 0.44f, -1.06f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 5.5f, 2, H_LINE_TO, 12, R_LINE_TO, 4, 4, R_V_LINE_TO, 9.92f, R_CUBIC_TO, 0, 0.5f, -0.04f, 0.88f,
    -0.11f, 1.13f, R_CUBIC_TO, -0.08f, 0.25f, -0.19f, 0.43f, -0.34f, 0.54f, R_LINE_TO, -4.02f, -4.02f, R_CUBIC_TO, -0.21f, 0.14f, -0.44f, 0.24f, -0.71f, 0.3f,
    R_ARC_TO, 3.53f, 3.53f, 0, 0, 1, -0.81f, 0.09f, R_CUBIC_TO, -0.83f, 0, -1.54f, -0.29f, -2.12f, -0.87f, ARC_TO, 2.89f, 2.89f, 0, 0, 1, 7, 10.96f, R_CUBIC_TO,
    0, -0.83f, 0.29f, -1.54f, 0.88f, -2.12f, ARC_TO, 2.9f, 2.9f, 0, 0, 1, 10, 7.96f, R_CUBIC_TO, 0.83f, 0, 1.54f, 0.29f, 2.13f, 0.88f, R_CUBIC_TO, 0.58f, 0.59f,
    0.88f, 1.29f, 0.88f, 2.13f, R_CUBIC_TO, 0, 0.28f, -0.04f, 0.56f, -0.1f, 0.82f, R_CUBIC_TO, -0.07f, 0.27f, -0.17f, 0.51f, -0.31f, 0.72f, R_LINE_TO, 1.92f,
    1.92f, V_LINE_TO, 6.63f, LINE_TO, 11.38f, 3.5f, H_LINE_TO, 5.5f, R_V_LINE_TO, 13, CLOSE, R_MOVE_TO, -2.33f, -4.04f, R_CUBIC_TO, 0.41f, 0, 0.77f, -0.14f,
    1.06f, -0.44f, R_CUBIC_TO, 0.29f, -0.29f, 0.44f, -0.65f, 0.44f, -1.06f, R_CUBIC_TO, 0, -0.41f, -0.15f, -0.76f, -0.44f, -1.06f, R_ARC_TO, 1.47f, 1.47f, 0, 0,
    0, -1.06f, -0.44f, R_CUBIC_TO, -0.41f, 0, -0.77f, 0.15f, -1.06f, 0.44f, R_ARC_TO, 1.46f, 1.46f, 0, 0, 0, -0.44f, 1.06f, R_CUBIC_TO, 0, 0.41f, 0.15f, 0.77f,
    0.44f, 1.06f, R_CUBIC_TO, 0.3f, 0.29f, 0.65f, 0.44f, 1.06f, 0.44f, CLOSE, MOVE_TO, 10, 10.75f, CLOSE, R_MOVE_TO, 0, 0, CLOSE)
VECTOR_ICON_TEMPLATE_CC(
    kFindInPageChromeRefreshRepList, kFindInPageChromeRefreshIcon, { kFindInPageChromeRefreshPath, std::size(kFindInPageChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kHttpPath, CANVAS_DIMENSIONS, 32, MOVE_TO, 16.5f, 3, CUBIC_TO, 9.05f, 3, 3, 9.05f, 3, 16.5f, CUBIC_TO, 3, 23.95f, 9.05f, 30, 16.5f, 30,
    CUBIC_TO, 23.95f, 30, 30, 23.95f, 30, 16.5f, CUBIC_TO, 30, 9.05f, 23.95f, 3, 16.5f, 3, MOVE_TO, 6, 16.5f, CUBIC_TO, 6, 10.71f, 10.71f, 6, 16.5f, 6,
    CUBIC_TO, 22.29f, 6, 27, 10.71f, 27, 16.5f, CUBIC_TO, 27, 22.29f, 22.29f, 27, 16.5f, 27, CUBIC_TO, 10.71f, 27, 6, 22.29f, 6, 16.5f, MOVE_TO, 15, 23,
    LINE_TO, 18, 23, LINE_TO, 18, 15, LINE_TO, 15, 15, LINE_TO, 15, 23, MOVE_TO, 15, 13, LINE_TO, 18, 13, LINE_TO, 18, 10, LINE_TO, 15, 10, LINE_TO, 15, 13,
    CLOSE)
VECTOR_ICON_REP_TEMPLATE(kHttp20Path, CANVAS_DIMENSIONS, 20, MOVE_TO, 10, 2, R_CUBIC_TO, -4.42f, 0, -8, 3.58f, -8, 8, R_CUBIC_TO, 0, 4.42f, 3.58f, 8, 8, 8,
    R_CUBIC_TO, 4.42f, 0, 8, -3.58f, 8, -8, R_CUBIC_TO, 0, -4.42f, -3.58f, -8, -8, -8, CLOSE, R_MOVE_TO, -6, 8, R_CUBIC_TO, 0, -3.31f, 2.69f, -6, 6, -6,
    R_CUBIC_TO, 3.31f, 0, 6, 2.69f, 6, 6, R_CUBIC_TO, 0, 3.31f, -2.69f, 6, -6, 6, R_CUBIC_TO, -3.31f, 0, -6, -2.69f, -6, -6, CLOSE, R_MOVE_TO, 7, 4, V_LINE_TO,
    9, H_LINE_TO, 9, R_V_LINE_TO, 5, R_H_LINE_TO, 2, CLOSE, MOVE_TO, 9, 8, R_H_LINE_TO, 2, V_LINE_TO, 6, H_LINE_TO, 9, R_V_LINE_TO, 2, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kHttp16Path, CANVAS_DIMENSIONS, 16, MOVE_TO, 8, 1, CUBIC_TO, 4.14f, 1, 1, 4.14f, 1, 8, CUBIC_TO, 1, 11.86f, 4.14f, 15, 8, 15, CUBIC_TO,
    11.86f, 15, 15, 11.86f, 15, 8, CUBIC_TO, 15, 4.14f, 11.86f, 1, 8, 1, MOVE_TO, 2.5f, 8, CUBIC_TO, 2.5f, 4.97f, 4.97f, 2.5f, 8, 2.5f, CUBIC_TO, 11.03f, 2.5f,
    13.5f, 4.97f, 13.5f, 8, CUBIC_TO, 13.5f, 11.03f, 11.03f, 13.5f, 8, 13.5f, CUBIC_TO, 4.97f, 13.5f, 2.5f, 11.03f, 2.5f, 8, MOVE_TO, 9, 12, LINE_TO, 9, 7,
    LINE_TO, 7, 7, LINE_TO, 7, 12, LINE_TO, 9, 12, MOVE_TO, 7, 6, LINE_TO, 9, 6, LINE_TO, 9, 4, LINE_TO, 7, 4, LINE_TO, 7, 6, CLOSE)
VECTOR_ICON_TEMPLATE_CC(
    kHttpRepList, kHttpIcon, { kHttpPath, std::size(kHttpPath) }, { kHttp20Path, std::size(kHttp20Path) }, { kHttp16Path, std::size(kHttp16Path) })
VECTOR_ICON_REP_TEMPLATE(kHttpChromeRefreshPath, CANVAS_DIMENSIONS, 16, FILL_RULE_NONZERO, MOVE_TO, 7.34f, 11.26f, R_H_LINE_TO, 1.32f, V_LINE_TO, 7.2f,
    H_LINE_TO, 7.34f, CLOSE, R_MOVE_TO, 0.66f, -5.18f, R_ARC_TO, 0.66f, 0.66f, 0, 0, 0, 0.48f, -0.19f, R_ARC_TO, 0.66f, 0.66f, 0, 0, 0, 0.2f, -0.48f, R_ARC_TO,
    0.67f, 0.67f, 0, 0, 0, -0.2f, -0.48f, R_ARC_TO, 0.64f, 0.64f, 0, 0, 0, -0.48f, -0.2f, R_ARC_TO, 0.66f, 0.66f, 0, 0, 0, -0.48f, 0.2f, R_ARC_TO, 0.64f, 0.64f,
    0, 0, 0, -0.2f, 0.48f, R_CUBIC_TO, 0, 0.2f, 0.07f, 0.36f, 0.2f, 0.49f, R_ARC_TO, 0.64f, 0.64f, 0, 0, 0, 0.48f, 0.2f, CLOSE, R_MOVE_TO, 0.01f, 8.46f,
    R_CUBIC_TO, -0.9f, 0, -1.75f, -0.17f, -2.54f, -0.51f, R_ARC_TO, 6.52f, 6.52f, 0, 0, 1, -2.08f, -1.4f, R_ARC_TO, 6.52f, 6.52f, 0, 0, 1, -1.4f, -2.08f,
    R_ARC_TO, 6.33f, 6.33f, 0, 0, 1, -0.51f, -2.55f, R_CUBIC_TO, 0, -0.91f, 0.17f, -1.75f, 0.51f, -2.54f, ARC_TO, 6.53f, 6.53f, 0, 0, 1, 3.38f, 3.38f, ARC_TO,
    6.52f, 6.52f, 0, 0, 1, 5.46f, 1.98f, R_ARC_TO, 6.33f, 6.33f, 0, 0, 1, 2.55f, -0.51f, R_CUBIC_TO, 0.91f, 0, 1.75f, 0.17f, 2.54f, 0.51f, R_CUBIC_TO, 0.79f,
    0.34f, 1.48f, 0.8f, 2.07f, 1.4f, R_ARC_TO, 6.5f, 6.5f, 0, 0, 1, 1.4f, 2.08f, R_ARC_TO, 6.29f, 6.29f, 0, 0, 1, 0.51f, 2.54f, R_CUBIC_TO, 0, 0.9f, -0.17f,
    1.75f, -0.51f, 2.54f, R_ARC_TO, 6.52f, 6.52f, 0, 0, 1, -1.4f, 2.08f, R_ARC_TO, 6.5f, 6.5f, 0, 0, 1, -2.08f, 1.4f, R_ARC_TO, 6.29f, 6.29f, 0, 0, 1, -2.54f,
    0.51f, CLOSE, MOVE_TO, 8, 13.15f, R_CUBIC_TO, 1.43f, 0, 2.65f, -0.5f, 3.65f, -1.5f, R_CUBIC_TO, 1, -1, 1.5f, -2.22f, 1.5f, -3.65f, R_CUBIC_TO, 0, -1.43f,
    -0.5f, -2.65f, -1.5f, -3.65f, CUBIC_TO_SHORTHAND, 9.43f, 2.85f, 8, 2.85f, R_CUBIC_TO, -1.43f, 0, -2.65f, 0.5f, -3.65f, 1.5f, CUBIC_TO_SHORTHAND, 2.85f,
    6.57f, 2.85f, 8, R_CUBIC_TO, 0, 1.43f, 0.5f, 2.65f, 1.5f, 3.65f, R_CUBIC_TO, 1, 1, 2.22f, 1.5f, 3.65f, 1.5f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kHttpChromeRefreshRepList, kHttpChromeRefreshIcon, { kHttpChromeRefreshPath, std::size(kHttpChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kIncognitoPath, CANVAS_DIMENSIONS, 16, NEW_PATH, PATH_COLOR_ARGB, 0xFF, 242, 246, 245, CIRCLE, 8, 8, 8, NEW_PATH, PATH_COLOR_ARGB,
    0xFF, 38, 40, 42, MOVE_TO, 13, 7.16f, H_LINE_TO, 3, R_V_LINE_TO, 0.54f, R_H_LINE_TO, 10, R_V_LINE_TO, -0.54f, CLOSE, MOVE_TO, /* 11.12f, 6.63f, */ 9.85f,
    3.35f, R_ARC_TO, 0.56f, 0.56f, 0, 0, 0, -0.69f, -0.32f, LINE_TO, 8, 3.4f, R_LINE_TO, -1.16f, -0.38f, R_ARC_TO, 0.56f, 0.56f, 0, 0, 0, -0.69f, 0.32f,
    LINE_TO, 4.88f, 6.63f, R_H_LINE_TO, 6.24f, CLOSE, MOVE_TO, 10.5f, 8.24f, R_CUBIC_TO, -0.92f, 0, -1.69f, 0.62f, -1.89f, 1.46f, R_CUBIC_TO, -0.47f, -0.19f,
    -0.9f, -0.14f, -1.22f, 0, ARC_TO, 1.93f, 1.93f, 0, 0, 0, 5.5f, 8.24f, R_CUBIC_TO, -1.07f, 0, -1.94f, 0.84f, -1.94f, 1.88f, CUBIC_TO, 3.56f, 11.16f, 4.43f,
    12, 5.5f, 12, R_CUBIC_TO, 1.02f, 0, 1.85f, -0.76f, 1.93f, -1.73f, R_CUBIC_TO, 0.17f, -0.11f, 0.61f, -0.32f, 1.14f, 0.01f, R_CUBIC_TO, 0.09f, 0.96f, 0.91f,
    1.72f, 1.93f, 1.72f, R_CUBIC_TO, 1.07f, 0, 1.94f, -0.84f, 1.94f, -1.88f, R_CUBIC_TO, 0, -1.04f, -0.87f, -1.88f, -1.94f, -1.88f, CLOSE, R_MOVE_TO, -5, 3.22f,
    R_CUBIC_TO, -0.77f, 0, -1.39f, -0.6f, -1.39f, -1.34f, R_CUBIC_TO, 0, -0.74f, 0.62f, -1.34f, 1.39f, -1.34f, R_CUBIC_TO, 0.77f, 0, 1.39f, 0.6f, 1.39f, 1.34f,
    R_CUBIC_TO, 0, 0.74f, -0.62f, 1.34f, -1.39f, 1.34f, CLOSE, R_MOVE_TO, 5, 0, R_CUBIC_TO, -0.77f, 0, -1.39f, -0.6f, -1.39f, -1.34f, R_CUBIC_TO, 0, -0.74f,
    0.62f, -1.34f, 1.39f, -1.34f, R_CUBIC_TO, 0.77f, 0, 1.39f, 0.6f, 1.39f, 1.34f, R_CUBIC_TO, 0, 0.74f, -0.62f, 1.34f, -1.39f, 1.34f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kIncognitoRepList, kIncognitoIcon, { kIncognitoPath, std::size(kIncognitoPath) })
VECTOR_ICON_REP_TEMPLATE(kIncognitoCr2023Path, CANVAS_DIMENSIONS, 16, MOVE_TO, 5.16f, 12.83f, R_ARC_TO, 1.95f, 1.95f, 0, 0, 1, -1.44f, -0.59f, R_ARC_TO, 1.96f,
    1.96f, 0, 0, 1, -0.59f, -1.44f, R_CUBIC_TO, 0, -0.57f, 0.2f, -1.05f, 0.59f, -1.44f, R_CUBIC_TO, 0.39f, -0.39f, 0.87f, -0.59f, 1.44f, -0.59f, R_CUBIC_TO,
    0.42f, 0, 0.8f, 0.12f, 1.14f, 0.36f, R_CUBIC_TO, 0.34f, 0.24f, 0.59f, 0.55f, 0.75f, 0.93f, R_ARC_TO, 2.38f, 2.38f, 0, 0, 1, 0.91f, -0.18f, R_ARC_TO, 2.43f,
    2.43f, 0, 0, 1, 0.92f, 0.18f, R_ARC_TO, 2.1f, 2.1f, 0, 0, 1, 0.74f, -0.93f, R_CUBIC_TO, 0.34f, -0.24f, 0.72f, -0.36f, 1.14f, -0.36f, R_CUBIC_TO, 0.57f, 0,
    1.04f, 0.2f, 1.44f, 0.59f, R_CUBIC_TO, 0.4f, 0.4f, 0.59f, 0.88f, 0.59f, 1.44f, R_CUBIC_TO, 0, 0.57f, -0.2f, 1.05f, -0.59f, 1.44f, R_CUBIC_TO, -0.39f, 0.4f,
    -0.87f, 0.59f, -1.44f, 0.59f, R_CUBIC_TO, -0.43f, 0, -0.82f, -0.12f, -1.16f, -0.36f, R_ARC_TO, 1.89f, 1.89f, 0, 0, 1, -0.73f, -0.95f, R_ARC_TO, 1.25f,
    1.25f, 0, 0, 0, -1.41f, -0.28f, R_CUBIC_TO, -0.16f, 0.07f, -0.29f, 0.16f, -0.41f, 0.28f, R_CUBIC_TO, -0.14f, 0.39f, -0.38f, 0.71f, -0.73f, 0.95f, R_ARC_TO,
    2, 2, 0, 0, 1, -1.16f, 0.36f, CLOSE, R_MOVE_TO, 0, -1.27f, R_ARC_TO, 0.74f, 0.74f, 0, 0, 0, 0.54f, -0.22f, R_ARC_TO, 0.74f, 0.74f, 0, 0, 0, 0.23f, -0.54f,
    R_ARC_TO, 0.74f, 0.74f, 0, 0, 0, -0.23f, -0.54f, R_ARC_TO, 0.73f, 0.73f, 0, 0, 0, -0.54f, -0.23f, R_ARC_TO, 0.73f, 0.73f, 0, 0, 0, -0.54f, 0.23f, R_ARC_TO,
    0.75f, 0.75f, 0, 0, 0, -0.23f, 0.54f, R_CUBIC_TO, 0, 0.21f, 0.08f, 0.39f, 0.23f, 0.54f, R_ARC_TO, 0.74f, 0.74f, 0, 0, 0, 0.54f, 0.22f, CLOSE, R_MOVE_TO,
    5.6f, 0, R_ARC_TO, 0.75f, 0.75f, 0, 0, 0, 0.54f, -0.22f, R_ARC_TO, 0.74f, 0.74f, 0, 0, 0, 0.23f, -0.54f, R_ARC_TO, 0.73f, 0.73f, 0, 0, 0, -0.23f, -0.54f,
    R_ARC_TO, 0.74f, 0.74f, 0, 0, 0, -0.54f, -0.23f, R_ARC_TO, 0.73f, 0.73f, 0, 0, 0, -0.54f, 0.23f, R_ARC_TO, 0.73f, 0.73f, 0, 0, 0, -0.23f, 0.54f, R_CUBIC_TO,
    0, 0.21f, 0.08f, 0.39f, 0.23f, 0.54f, R_ARC_TO, 0.74f, 0.74f, 0, 0, 0, 0.54f, 0.22f, CLOSE, MOVE_TO, 2.3f, 8, V_LINE_TO, 6.68f, R_H_LINE_TO, 2.04f, LINE_TO,
    5.59f, 2.78f, R_ARC_TO, 1.04f, 1.04f, 0, 0, 1, 0.45f, -0.52f, R_CUBIC_TO, 0.2f, -0.11f, 0.42f, -0.14f, 0.68f, -0.08f, R_LINE_TO, 1.25f, 0.33f, R_LINE_TO,
    1.25f, -0.33f, R_ARC_TO, 0.91f, 0.91f, 0, 0, 1, 0.67f, 0.08f, R_CUBIC_TO, 0.2f, 0.11f, 0.35f, 0.28f, 0.45f, 0.52f, R_LINE_TO, 1.26f, 3.9f, R_H_LINE_TO,
    2.12f, V_LINE_TO, 8, CLOSE, R_MOVE_TO, 3.5f, -1.32f, R_H_LINE_TO, 4.33f, R_LINE_TO, -0.99f, -3.05f, R_LINE_TO, -1.18f, 0.31f, R_LINE_TO, -1.18f, -0.31f,
    CLOSE, R_MOVE_TO, 2.18f, -0.07f,
    /*
Skiafy incorrectly produces a 2-arg call to R_H_LINE_TO:
R_H_LINE_TO, 2.19f, -4.39f,
The following two lines are the correctecd commmands:
*/
    R_H_LINE_TO, 2.19f, R_H_LINE_TO, -4.39f, CLOSE, R_MOVE_TO, 0, 0, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kIncognitoCr2023RepList, kIncognitoCr2023Icon, { kIncognitoCr2023Path, std::size(kIncognitoCr2023Path) })
VECTOR_ICON_REP_TEMPLATE(kInstallDesktopPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 6.42f, 2, R_V_LINE_TO, 1.2f, H_LINE_TO, 2.19f, R_V_LINE_TO, 8.44f, R_H_LINE_TO,
    11.61f, V_LINE_TO, 9.58f, H_LINE_TO, 14.99f, R_V_LINE_TO, 1.81f, R_ARC_TO, 1.45f, 1.45f, 0, 0, 1, -1.31f, 1.44f, R_LINE_TO, -0.14f, 0.01f, H_LINE_TO,
    11.74f, R_LINE_TO, 0.65f, 0.72f, V_LINE_TO, 15, H_LINE_TO, 3.6f, R_V_LINE_TO, -1.44f, R_LINE_TO, 0.65f, -0.72f, H_LINE_TO, 2.44f, R_ARC_TO, 1.44f, 1.44f, 0,
    0, 1, -1.44f, -1.31f, LINE_TO, 1, 11.39f, V_LINE_TO, 3.44f, R_CUBIC_TO, 0, -0.75f, 0.57f, -1.37f, 1.31f, -1.44f, LINE_TO, 2.44f, 2, R_H_LINE_TO, 3.97f,
    CLOSE, MOVE_TO, 11.2f, 2, R_V_LINE_TO, 5.1f, R_LINE_TO, 1.75f, -1.81f, LINE_TO, 14, 6.37f, LINE_TO, 10.5f, 10, LINE_TO, 7, 6.37f, R_LINE_TO, 1.05f, -1.09f,
    LINE_TO, 9.8f, 7.1f, V_LINE_TO, 2, R_H_LINE_TO, 1.4f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kInstallDesktopRepList, kInstallDesktopIcon, { kInstallDesktopPath, std::size(kInstallDesktopPath) })
VECTOR_ICON_REP_TEMPLATE(kJourneysPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 19, 21, R_QUADRATIC_TO, -0.97f, 0, -1.75f, -0.56f, R_QUADRATIC_TO, -0.77f, -0.56f,
    -1.07f, -1.44f, H_LINE_TO, 11, R_QUADRATIC_TO, -1.65f, 0, -2.82f, -1.17f, QUADRATIC_TO, 7, 16.65f, 7, 15, R_QUADRATIC_TO, 0, -1.65f, 1.18f, -2.82f,
    QUADRATIC_TO, 9.35f, 11, 11, 11, R_H_LINE_TO, 2, R_QUADRATIC_TO, 0.83f, 0, 1.41f, -0.59f, QUADRATIC_TO, 15, 9.82f, 15, 9, R_QUADRATIC_TO, 0, -0.82f, -0.59f,
    -1.41f, QUADRATIC_TO, 13.83f, 7, 13, 7, H_LINE_TO, 7.83f, R_QUADRATIC_TO, -0.32f, 0.88f, -1.09f, 1.44f, QUADRATIC_TO, 5.98f, 9, 5, 9, R_QUADRATIC_TO,
    -1.25f, 0, -2.12f, -0.87f, QUADRATIC_TO_SHORTHAND, 2, 6, R_QUADRATIC_TO, 0, -1.25f, 0.88f, -2.12f, QUADRATIC_TO_SHORTHAND, 5, 3, R_QUADRATIC_TO, 0.98f, 0,
    1.74f, 0.56f, QUADRATIC_TO, 7.5f, 4.13f, 7.83f, 5, H_LINE_TO, 13, R_QUADRATIC_TO, 1.65f, 0, 2.83f, 1.18f, QUADRATIC_TO, 17, 7.35f, 17, 9, R_QUADRATIC_TO, 0,
    1.65f, -1.17f, 2.83f, QUADRATIC_TO, 14.65f, 13, 13, 13, R_H_LINE_TO, -2, R_QUADRATIC_TO, -0.82f, 0, -1.41f, 0.59f, QUADRATIC_TO, 9, 14.18f, 9, 15,
    R_QUADRATIC_TO, 0, 0.83f, 0.59f, 1.41f, QUADRATIC_TO, 10.18f, 17, 11, 17, R_H_LINE_TO, 5.18f, R_QUADRATIC_TO, 0.33f, -0.87f, 1.09f, -1.44f, QUADRATIC_TO,
    18.02f, 15, 19, 15, R_QUADRATIC_TO, 1.25f, 0, 2.13f, 0.88f, QUADRATIC_TO_SHORTHAND, 22, 18, R_QUADRATIC_TO, 0, 1.25f, -0.87f, 2.13f, QUADRATIC_TO_SHORTHAND,
    19, 21, CLOSE, MOVE_TO, 5, 7, R_QUADRATIC_TO, 0.43f, 0, 0.71f, -0.29f, QUADRATIC_TO, 6, 6.43f, 6, 6, R_QUADRATIC_TO, 0, -0.43f, -0.29f, -0.71f,
    QUADRATIC_TO, 5.43f, 5, 5, 5, R_QUADRATIC_TO, -0.43f, 0, -0.71f, 0.29f, QUADRATIC_TO, 4, 5.58f, 4, 6, R_QUADRATIC_TO, 0, 0.42f, 0.29f, 0.71f, QUADRATIC_TO,
    4.58f, 7, 5, 7, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kJourneysRepList, kJourneysIcon, { kJourneysPath, std::size(kJourneysPath) })
VECTOR_ICON_REP_TEMPLATE(kJourneysChromeRefreshPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 12.4f, 13.72f, R_CUBIC_TO, -0.49f, 0, -0.92f, -0.14f, -1.28f, -0.43f,
    R_CUBIC_TO, -0.36f, -0.29f, -0.6f, -0.64f, -0.73f, -1.06f, H_LINE_TO, 6.6f, R_ARC_TO, 2.15f, 2.15f, 0, 0, 1, -1.58f, -0.65f, R_ARC_TO, 2.17f, 2.17f, 0, 0,
    1, -0.65f, -1.59f, R_CUBIC_TO, 0, -0.62f, 0.22f, -1.14f, 0.65f, -1.58f, R_CUBIC_TO, 0.43f, -0.43f, 0.96f, -0.65f, 1.58f, -0.65f, R_H_LINE_TO, 2, R_CUBIC_TO,
    0.38f, 0, 0.7f, -0.14f, 0.96f, -0.41f, R_CUBIC_TO, 0.27f, -0.26f, 0.4f, -0.59f, 0.4f, -0.97f, R_ARC_TO, 1.3f, 1.3f, 0, 0, 0, -0.4f, -0.96f, R_ARC_TO, 1.33f,
    1.33f, 0, 0, 0, -0.96f, -0.4f, R_H_LINE_TO, -2.98f, R_ARC_TO, 2.09f, 2.09f, 0, 0, 1, -0.73f, 1.06f, R_CUBIC_TO, -0.36f, 0.29f, -0.79f, 0.43f, -1.28f, 0.43f,
    R_ARC_TO, 2.04f, 2.04f, 0, 0, 1, -1.5f, -0.62f, R_ARC_TO, 2.04f, 2.04f, 0, 0, 1, -0.62f, -1.5f, R_CUBIC_TO, 0, -0.59f, 0.21f, -1.09f, 0.62f, -1.5f,
    R_CUBIC_TO, 0.41f, -0.41f, 0.92f, -0.62f, 1.51f, -0.62f, R_CUBIC_TO, 0.49f, 0, 0.92f, 0.14f, 1.29f, 0.43f, R_CUBIC_TO, 0.36f, 0.29f, 0.61f, 0.64f, 0.73f,
    1.06f, R_H_LINE_TO, 2.98f, R_CUBIC_TO, 0.73f, 0, 1.35f, 0.25f, 1.86f, 0.77f, R_CUBIC_TO, 0.51f, 0.52f, 0.77f, 1.13f, 0.77f, 1.86f, R_CUBIC_TO, 0, 0.74f,
    -0.25f, 1.36f, -0.76f, 1.87f, R_ARC_TO, 2.54f, 2.54f, 0, 0, 1, -1.86f, 0.77f, R_H_LINE_TO, -2, R_ARC_TO, 0.93f, 0.93f, 0, 0, 0, -0.68f, 0.28f, R_ARC_TO,
    0.93f, 0.93f, 0, 0, 0, -0.28f, 0.68f, R_CUBIC_TO, 0, 0.27f, 0.09f, 0.5f, 0.28f, 0.68f, R_ARC_TO, 0.93f, 0.93f, 0, 0, 0, 0.68f, 0.28f, R_H_LINE_TO, 3.78f,
    R_CUBIC_TO, 0.13f, -0.42f, 0.37f, -0.77f, 0.73f, -1.06f, R_CUBIC_TO, 0.36f, -0.29f, 0.79f, -0.43f, 1.29f, -0.43f, R_CUBIC_TO, 0.59f, 0, 1.09f, 0.21f, 1.5f,
    0.62f, R_CUBIC_TO, 0.41f, 0.41f, 0.62f, 0.92f, 0.62f, 1.51f, R_CUBIC_TO, 0, 0.59f, -0.21f, 1.09f, -0.62f, 1.5f, R_CUBIC_TO, -0.41f, 0.41f, -0.91f, 0.62f,
    -1.5f, 0.62f, CLOSE, MOVE_TO, 3.6f, 5.2f, R_ARC_TO, 0.77f, 0.77f, 0, 0, 0, 0.57f, -0.23f, R_ARC_TO, 0.77f, 0.77f, 0, 0, 0, 0.23f, -0.57f, R_ARC_TO, 0.78f,
    0.78f, 0, 0, 0, -0.23f, -0.57f, R_ARC_TO, 0.78f, 0.78f, 0, 0, 0, -0.57f, -0.23f, R_ARC_TO, 0.77f, 0.77f, 0, 0, 0, -0.57f, 0.23f, R_ARC_TO, 0.77f, 0.77f, 0,
    0, 0, -0.23f, 0.57f, R_CUBIC_TO, 0, 0.23f, 0.07f, 0.42f, 0.23f, 0.57f, R_CUBIC_TO, 0.15f, 0.16f, 0.34f, 0.23f, 0.57f, 0.23f, CLOSE, R_MOVE_TO, 0, 0, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kJourneysChromeRefreshRepList, kJourneysChromeRefreshIcon, { kJourneysChromeRefreshPath, std::size(kJourneysChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kOfflinePinPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 12, 2, CUBIC_TO, 6.5f, 2, 2, 6.5f, 2, 12, R_CUBIC_TO, 0, 5.5f, 4.5f, 10, 10, 10,
    R_CUBIC_TO, 5.5f, 0, 10, -4.5f, 10, -10, R_CUBIC_TO, 0, -5.5f, -4.5f, -10, -10, -10, CLOSE, R_MOVE_TO, 5, 16, H_LINE_TO, 7, R_V_LINE_TO, -2, R_H_LINE_TO,
    10, R_V_LINE_TO, 2, CLOSE, R_MOVE_TO, -6.7f, -4, LINE_TO, 7, 10.7f, R_LINE_TO, 1.4f, -1.4f, R_LINE_TO, 1.9f, 1.9f, R_LINE_TO, 5.3f, -5.3f, LINE_TO, 17,
    7.3f, LINE_TO, 10.3f, 14, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kOfflinePinRepList, kOfflinePinIcon, { kOfflinePinPath, std::size(kOfflinePinPath) })
VECTOR_ICON_REP_TEMPLATE(kPagePath, CANVAS_DIMENSIONS, 24, MOVE_TO, 12, 2, R_CUBIC_TO, 5.52f, 0, 10, 4.48f, 10, 10, R_CUBIC_TO, 0, 5.52f, -4.48f, 10, -10, 10,
    CUBIC_TO_SHORTHAND, 2, 17.52f, 2, 12, CUBIC_TO_SHORTHAND, 6.48f, 2, 12, 2, CLOSE, MOVE_TO, 4, 12, R_H_LINE_TO, 4.4f, R_CUBIC_TO, 3.41f, 0.02f, 4.92f, 1.73f,
    4.54f, 5.13f, H_LINE_TO, 9.49f, R_V_LINE_TO, 2.47f, R_ARC_TO, 8, 8, 0, 0, 0, 10.5f, -8.08f, CUBIC_TO, 19.33f, 12.5f, 18.33f, 13, 17, 13, R_CUBIC_TO, -2.14f,
    0, -3.21f, -0.92f, -3.21f, -2.75f, R_H_LINE_TO, -3.75f, R_CUBIC_TO, -0.27f, -2.73f, 0.68f, -4.09f, 2.87f, -4.09f, R_CUBIC_TO, 0, -0.97f, 0.33f, -1.6f,
    0.81f, -1.97f, ARC_TO, 8, 8, 0, 0, 0, 4, 12, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kPageRepList, kPageIcon, { kPagePath, std::size(kPagePath) })
VECTOR_ICON_REP_TEMPLATE(kPageChromeRefreshPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 8.01f, 14.54f, R_ARC_TO, 6.38f, 6.38f, 0, 0, 1, -2.54f, -0.51f, R_ARC_TO,
    6.59f, 6.59f, 0, 0, 1, -2.08f, -1.41f, R_ARC_TO, 6.66f, 6.66f, 0, 0, 1, -1.41f, -2.09f, R_ARC_TO, 6.39f, 6.39f, 0, 0, 1, -0.51f, -2.54f, R_CUBIC_TO, 0,
    -0.9f, 0.17f, -1.75f, 0.51f, -2.53f, R_ARC_TO, 6.59f, 6.59f, 0, 0, 1, 3.49f, -3.48f, R_ARC_TO, 6.39f, 6.39f, 0, 0, 1, 2.54f, -0.51f, R_CUBIC_TO, 0.9f, 0,
    1.75f, 0.17f, 2.54f, 0.51f, R_ARC_TO, 6.63f, 6.63f, 0, 0, 1, 3.48f, 3.49f, R_CUBIC_TO, 0.34f, 0.79f, 0.51f, 1.64f, 0.51f, 2.54f, R_ARC_TO, 6.38f, 6.38f, 0,
    0, 1, -0.51f, 2.54f, R_ARC_TO, 6.59f, 6.59f, 0, 0, 1, -3.49f, 3.49f, R_CUBIC_TO, -0.79f, 0.34f, -1.63f, 0.51f, -2.53f, 0.51f, CLOSE, R_MOVE_TO, -0.8f,
    -1.45f, R_V_LINE_TO, -1.13f, R_ARC_TO, 0.76f, 0.76f, 0, 0, 1, -0.56f, -0.23f, R_ARC_TO, 0.77f, 0.77f, 0, 0, 1, -0.23f, -0.56f, R_V_LINE_TO, -0.79f,
    R_LINE_TO, -3.45f, -3.45f, R_ARC_TO, 6.23f, 6.23f, 0, 0, 0, -0.09f, 0.57f, R_ARC_TO, 5.58f, 5.58f, 0, 0, 0, -0.02f, 0.49f, R_CUBIC_TO, 0, 1.27f, 0.41f,
    2.39f, 1.23f, 3.36f, R_CUBIC_TO, 0.82f, 0.97f, 1.86f, 1.55f, 3.13f, 1.73f, CLOSE, R_MOVE_TO, 4.76f, -1.8f, R_CUBIC_TO, 0.2f, -0.23f, 0.37f, -0.47f, 0.52f,
    -0.73f, R_CUBIC_TO, 0.14f, -0.25f, 0.27f, -0.52f, 0.37f, -0.8f, R_ARC_TO, 5.32f, 5.32f, 0, 0, 0, 0.3f, -1.77f, R_CUBIC_TO, 0, -1.04f, -0.28f, -1.99f,
    -0.85f, -2.85f, R_ARC_TO, 5.05f, 5.05f, 0, 0, 0, -2.31f, -1.9f, R_V_LINE_TO, 0.4f, R_CUBIC_TO, 0, 0.32f, -0.12f, 0.61f, -0.35f, 0.84f, R_CUBIC_TO, -0.23f,
    0.23f, -0.52f, 0.35f, -0.84f, 0.35f, H_LINE_TO, 7.21f, R_V_LINE_TO, 0.79f, R_ARC_TO, 0.77f, 0.77f, 0, 0, 1, -0.23f, 0.57f, R_ARC_TO, 0.77f, 0.77f, 0, 0, 1,
    -0.57f, 0.23f, R_H_LINE_TO, -0.78f, R_V_LINE_TO, 1.59f, H_LINE_TO, 9.59f, R_CUBIC_TO, 0.23f, 0, 0.41f, 0.08f, 0.57f, 0.23f, R_CUBIC_TO, 0.16f, 0.15f, 0.23f,
    0.34f, 0.23f, 0.57f, R_V_LINE_TO, 1.58f, R_H_LINE_TO, 0.67f, R_ARC_TO, 0.87f, 0.87f, 0, 0, 1, 0.65f, 0.27f, R_CUBIC_TO, 0.18f, 0.18f, 0.26f, 0.39f, 0.26f,
    0.65f, CLOSE, R_MOVE_TO, 0, 0, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kPageChromeRefreshRepList, kPageChromeRefreshIcon, { kPageChromeRefreshPath, std::size(kPageChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kPedalPath, CANVAS_DIMENSIONS, 16, NEW_PATH, PATH_COLOR_ARGB, 0xFF, 0xFC, 0xC3, 0x1C, MOVE_TO, 7.73f, 15.92f, R_CUBIC_TO, -0.06f,
    -0.01f, -0.06f, -0.01f, 1.56f, -2.84f, R_CUBIC_TO, 0.89f, -1.55f, 1.62f, -2.84f, 1.63f, -2.87f, R_ARC_TO, 0.34f, 0.34f, 0, 0, 1, 0.06f, -0.1f, R_CUBIC_TO,
    1.62f, -2.1f, -0.03f, -5.53f, -2.69f, -5.6f, R_CUBIC_TO, -0.09f, 0, -0.1f, 0, -0.04f, -0.01f, R_CUBIC_TO, 0.11f, -0.01f, 0.51f, 0.03f, 0.66f, 0.06f,
    R_ARC_TO, 0.59f, 0.59f, 0, 0, 0, 0.14f, 0.02f, R_CUBIC_TO, 0.01f, 0, 0, -0.01f, -0.01f, -0.01f, R_CUBIC_TO, -0.02f, 0, -0.02f, 0, 0, -0.02f, R_CUBIC_TO,
    0.03f, -0.03f, 1.23f, -0.04f, 3.84f, -0.05f, R_CUBIC_TO, 2.33f, 0, 2.17f, 0.01f, 2.11f, -0.12f, R_CUBIC_TO, -0.53f, -1.08f, -1.69f, -2.32f, -2.79f, -2.99f,
    R_ARC_TO, 37.47f, 37.47f, 0, 0, 1, -0.32f, -0.19f, CUBIC_TO, 10.18f, 0.14f, 7.44f, -0.08f, 5.35f, 0.69f, CUBIC_TO, 4.59f, 0.97f, 3.03f, 1.87f, 2.96f, 2.08f,
    R_ARC_TO, 3.43f, 3.43f, 0, 0, 1, -0.23f, 0.21f, R_CUBIC_TO, -0.3f, 0.26f, -0.69f, 0.69f, -1, 1.1f, R_CUBIC_TO, -0.26f, 0.35f, -0.3f, 0.39f, -0.24f, 0.31f,
    R_CUBIC_TO, 0.7f, -1.12f, 2.53f, -2.61f, 3.58f, -2.92f, R_CUBIC_TO, 0.06f, -0.02f, 0.26f, -0.09f, 0.51f, -0.19f, R_CUBIC_TO, 0.07f, -0.03f, 0.23f, -0.07f,
    0.34f, -0.1f, R_LINE_TO, 0.37f, -0.09f, R_CUBIC_TO, 4.13f, -1.1f, 8.79f, 1.96f, 9.49f, 6.23f, R_CUBIC_TO, 0.16f, 1, 0.18f, 1.75f, 0.04f, 2.63f, R_ARC_TO,
    7.85f, 7.85f, 0, 0, 1, -6.59f, 6.58f, R_CUBIC_TO, -0.52f, 0.08f, -1.26f, 0.12f, -1.48f, 0.08f, CLOSE, NEW_PATH, PATH_COLOR_ARGB, 0xFF, 0xFC, 0xC3, 0x1C,
    MOVE_TO, 4.7f, 15.19f, R_ARC_TO, 1.17f, 1.17f, 0, 0, 1, -0.18f, -0.1f, R_CUBIC_TO, 0.01f, 0, 0.1f, 0.05f, 0.21f, 0.1f, R_CUBIC_TO, 0.11f, 0.05f, 0.19f,
    0.1f, 0.18f, 0.1f, R_CUBIC_TO, -0.01f, 0, -0.1f, -0.04f, -0.21f, -0.1f, CLOSE, R_MOVE_TO, -0.34f, -0.16f, R_ARC_TO, 0.62f, 0.62f, 0, 0, 1, -0.11f, -0.07f,
    R_CUBIC_TO, 0, -0.01f, 0.23f, 0.1f, 0.25f, 0.12f, R_CUBIC_TO, 0.02f, 0.02f, -0.04f, 0, -0.14f, -0.05f, CLOSE, NEW_PATH, PATH_COLOR_ARGB, 0xFF, 0x1A, 0x73,
    0xE8, MOVE_TO, 0.92f, 11.44f, R_ARC_TO, 2.96f, 2.96f, 0, 0, 1, -0.11f, -0.24f, R_CUBIC_TO, 0, -0.01f, 0.05f, 0.09f, 0.12f, 0.22f, R_CUBIC_TO, 0.06f, 0.13f,
    0.11f, 0.24f, 0.11f, 0.24f, R_ARC_TO, 1.96f, 1.96f, 0, 0, 1, -0.12f, -0.22f, CLOSE, R_MOVE_TO, 7.04f, 0.2f, R_ARC_TO, 0.96f, 0.96f, 0, 0, 1, 0.14f, 0,
    R_CUBIC_TO, 0.04f, 0, 0.01f, 0.01f, -0.07f, 0.01f, R_CUBIC_TO, -0.08f, 0, -0.11f, 0, -0.07f, -0.01f, CLOSE, R_MOVE_TO, -1.55f, -0.38f, R_ARC_TO, 3.66f,
    3.66f, 0, 0, 1, -1.34f, -1.16f, R_CUBIC_TO, -0.01f, -0.01f, -0.01f, -0.02f, -0.01f, -0.02f, R_CUBIC_TO, 0, 0, 0.06f, 0.07f, 0.13f, 0.16f, R_CUBIC_TO, 0.31f,
    0.41f, 0.72f, 0.75f, 1.23f, 1.02f, R_CUBIC_TO, 0.12f, 0.06f, 0.21f, 0.11f, 0.2f, 0.11f, R_CUBIC_TO, -0.01f, 0, -0.11f, -0.05f, -0.22f, -0.1f, CLOSE,
    R_MOVE_TO, 1.43f, -0.34f, R_CUBIC_TO, -2.47f, -0.23f, -3.57f, -3.14f, -1.83f, -4.88f, R_CUBIC_TO, 1.66f, -1.65f, 4.46f, -0.73f, 4.85f, 1.59f, R_CUBIC_TO,
    0.3f, 1.76f, -1.26f, 3.45f, -3.02f, 3.29f, CLOSE, R_MOVE_TO, 2.55f, -0.18f, R_CUBIC_TO, 0.07f, -0.07f, 0.15f, -0.13f, 0.17f, -0.15f, R_CUBIC_TO, 0.04f,
    -0.03f, -0.16f, 0.16f, -0.24f, 0.23f, R_CUBIC_TO, -0.03f, 0.03f, 0, -0.01f, 0.07f, -0.08f, CLOSE, NEW_PATH, PATH_COLOR_ARGB, 0xFF, 0x1A, 0x73, 0xE8,
    MOVE_TO, 0.5f, 5.76f, R_CUBIC_TO, 0, -0.1f, 0.56f, -1.41f, 0.67f, -1.56f, R_ARC_TO, 4.8f, 4.8f, 0, 0, 1, -0.18f, 0.38f, R_ARC_TO, 7.43f, 7.43f, 0, 0, 0,
    -0.33f, 0.75f, R_CUBIC_TO, -0.13f, 0.36f, -0.17f, 0.45f, -0.17f, 0.43f, CLOSE, NEW_PATH, PATH_COLOR_ARGB, 0xFF, 0xE2, 0x3A, 0x2D, MOVE_TO, 4.43f, 8.98f,
    LINE_TO, 2.87f, 6.31f, ARC_TO, 668.22f, 668.22f, 0, 0, 0, 1.54f, 4.02f, R_CUBIC_TO, -0.14f, -0.23f, -0.16f, -0.17f, 0.19f, -0.63f, R_CUBIC_TO, 0.31f,
    -0.41f, 0.7f, -0.84f, 1, -1.1f, R_CUBIC_TO, 0.12f, -0.1f, 0.23f, -0.2f, 0.23f, -0.21f, CUBIC_TO, 3.03f, 1.87f, 4.59f, 0.97f, 5.35f, 0.69f, R_CUBIC_TO,
    2.09f, -0.77f, 4.83f, -0.55f, 6.52f, 0.51f, R_CUBIC_TO, 0.04f, 0.02f, 0.18f, 0.11f, 0.32f, 0.2f, R_CUBIC_TO, 1.1f, 0.67f, 2.26f, 1.91f, 2.79f, 2.99f,
    R_CUBIC_TO, 0.06f, 0.13f, 0.22f, 0.12f, -2.11f, 0.12f, R_CUBIC_TO, -2.62f, 0, -3.81f, 0.02f, -3.84f, 0.05f, R_CUBIC_TO, -0.02f, 0.02f, -0.02f, 0.02f, 0,
    0.02f, R_CUBIC_TO, 0.01f, 0, 0.02f, 0, 0.02f, 0.01f, R_ARC_TO, 0.59f, 0.59f, 0, 0, 1, -0.14f, -0.02f, R_CUBIC_TO, -1.86f, -0.44f, -3.82f, 0.73f, -4.32f,
    2.59f, R_CUBIC_TO, -0.2f, 0.75f, -0.12f, 1.81f, 0.19f, 2.37f, R_CUBIC_TO, 0.01f, 0.02f, 0.01f, 0.03f, 0.01f, 0.03f, R_CUBIC_TO, 0, 0, -0.16f, -0.26f,
    -0.35f, -0.58f, CLOSE, NEW_PATH, PATH_COLOR_ARGB, 0xFF, 0x29, 0x9B, 0x49, MOVE_TO, 7.33f, 15.9f, CUBIC_TO, 4.08f, 15.64f, 1.21f, 13.19f, 0.41f, 9.99f,
    R_CUBIC_TO, -0.5f, -2.01f, -0.16f, -4.3f, 0.88f, -5.94f, R_CUBIC_TO, 0.15f, -0.24f, 0.09f, -0.31f, 0.71f, 0.76f, R_ARC_TO, 778.74f, 778.74f, 0, 0, 1, 2.84f,
    4.89f, R_CUBIC_TO, 1.15f, 2.29f, 4.3f, 2.63f, 5.96f, 0.65f, R_CUBIC_TO, 0.07f, -0.08f, 0.12f, -0.14f, 0.12f, -0.14f, R_CUBIC_TO, 0, 0.02f, -0.32f, 0.58f,
    -1.8f, 3.17f, R_CUBIC_TO, -1.64f, 2.87f, -1.42f, 2.55f, -1.79f, 2.52f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kPedalRepList, kPedalIcon, { kPedalPath, std::size(kPedalPath) })
VECTOR_ICON_REP_TEMPLATE(kPriceTrackingDisabledPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 16, 14, R_V_LINE_TO, 3, H_LINE_TO, 8, R_V_LINE_TO, -7, R_CUBIC_TO, 0,
    -2.21f, 1.79f, -4, 4, -4, R_CUBIC_TO, 0.85f, 0, 1.64f, 0.26f, 2.28f, 0.72f, R_LINE_TO, 1.43f, -1.43f, R_CUBIC_TO, -0.64f, -0.51f, -1.39f, -0.88f, -2.21f,
    -1.09f, V_LINE_TO, 3.5f, CUBIC_TO, 13.5f, 2.67f, 12.83f, 2, 12, 2, R_CUBIC_TO, -0.83f, 0, -1.5f, 0.67f, -1.5f, 1.5f, R_V_LINE_TO, 0.7f, CUBIC_TO, 7.91f,
    4.86f, 6, 7.21f, 6, 10, R_V_LINE_TO, 7, H_LINE_TO, 4, R_V_LINE_TO, 2, R_H_LINE_TO, 16, R_V_LINE_TO, -2, R_H_LINE_TO, -2, R_V_LINE_TO, -3, H_LINE_TO, 16,
    CLOSE, MOVE_TO, 12, 22, R_CUBIC_TO, 1.1f, 0, 2, -0.9f, 2, -2, R_H_LINE_TO, -4, CUBIC_TO, 10, 21.1f, 10.9f, 22, 12, 22, CLOSE, MOVE_TO, 24, 8, R_H_LINE_TO,
    -3, V_LINE_TO, 5, R_H_LINE_TO, -2, R_V_LINE_TO, 3, R_H_LINE_TO, -3, R_V_LINE_TO, 2, R_H_LINE_TO, 3, R_V_LINE_TO, 3, R_H_LINE_TO, 2, R_V_LINE_TO, -3,
    R_H_LINE_TO, 3, V_LINE_TO, 8, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kPriceTrackingDisabledRepList, kPriceTrackingDisabledIcon, { kPriceTrackingDisabledPath, std::size(kPriceTrackingDisabledPath) })
VECTOR_ICON_REP_TEMPLATE(kPriceTrackingDisabledRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 10, 9.75f, CLOSE, MOVE_TO, 10, 18, R_CUBIC_TO,
    -0.41f, 0, -0.77f, -0.15f, -1.06f, -0.44f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 8.5f, 16.5f, R_H_LINE_TO, 3, R_CUBIC_TO, 0, 0.42f, -0.15f, 0.77f, -0.44f, 1.06f,
    ARC_TO, 1.45f, 1.45f, 0, 0, 1, 10, 18, CLOSE, R_MOVE_TO, 5.25f, -7, V_LINE_TO, 8.69f, H_LINE_TO, 13, V_LINE_TO, 7.31f, R_H_LINE_TO, 2.25f, V_LINE_TO, 5,
    R_H_LINE_TO, 1.5f, R_V_LINE_TO, 2.31f, H_LINE_TO, 19, R_V_LINE_TO, 1.38f, R_H_LINE_TO, -2.25f, V_LINE_TO, 11, CLOSE, MOVE_TO, 4, 15.5f, V_LINE_TO, 14,
    R_H_LINE_TO, 1, V_LINE_TO, 9, R_CUBIC_TO, 0, -1.21f, 0.37f, -2.27f, 1.11f, -3.19f, CUBIC_TO, 6.86f, 4.9f, 7.82f, 4.33f, 9, 4.11f, V_LINE_TO, 3, R_CUBIC_TO,
    0, -0.28f, 0.1f, -0.52f, 0.29f, -0.71f, ARC_TO, 0.96f, 0.96f, 0, 0, 1, 10, 2, R_CUBIC_TO, 0.28f, 0, 0.52f, 0.1f, 0.71f, 0.29f, R_CUBIC_TO, 0.2f, 0.19f,
    0.29f, 0.43f, 0.29f, 0.71f, R_V_LINE_TO, 1.11f, R_CUBIC_TO, 0.32f, 0.07f, 0.63f, 0.16f, 0.93f, 0.28f, R_CUBIC_TO, 0.3f, 0.12f, 0.59f, 0.27f, 0.87f, 0.45f,
    R_ARC_TO, 4.17f, 4.17f, 0, 0, 0, -0.85f, 1.25f, R_ARC_TO, 3.78f, 3.78f, 0, 0, 0, -0.91f, -0.43f, ARC_TO, 3.35f, 3.35f, 0, 0, 0, 10, 5.5f, R_CUBIC_TO,
    -0.97f, 0, -1.8f, 0.34f, -2.48f, 1.02f, CUBIC_TO, 6.84f, 7.2f, 6.5f, 8.03f, 6.5f, 9, R_V_LINE_TO, 5, R_H_LINE_TO, 7, R_V_LINE_TO, -2.25f, R_CUBIC_TO, 0.23f,
    0.15f, 0.48f, 0.28f, 0.72f, 0.39f, R_CUBIC_TO, 0.24f, 0.1f, 0.5f, 0.19f, 0.78f, 0.26f, V_LINE_TO, 14, R_H_LINE_TO, 1, R_V_LINE_TO, 1.5f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kPriceTrackingDisabledRefreshRepList, kPriceTrackingDisabledRefreshIcon,
    { kPriceTrackingDisabledRefreshPath, std::size(kPriceTrackingDisabledRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kPriceTrackingEnabledRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 2, 9, R_CUBIC_TO, 0, -1.23f, 0.25f, -2.35f, 0.74f,
    -3.38f, R_ARC_TO, 8.17f, 8.17f, 0, 0, 1, 2.06f, -2.66f, LINE_TO, 5.86f, 4, R_ARC_TO, 6.48f, 6.48f, 0, 0, 0, -1.72f, 2.2f, ARC_TO, 6.27f, 6.27f, 0, 0, 0,
    3.5f, 9, CLOSE, R_MOVE_TO, 14.5f, 0, R_CUBIC_TO, 0, -1.02f, -0.21f, -1.95f, -0.64f, -2.82f, R_ARC_TO, 6.42f, 6.42f, 0, 0, 0, -1.74f, -2.2f, R_LINE_TO,
    1.08f, -1.06f, R_ARC_TO, 7.99f, 7.99f, 0, 0, 1, 2.04f, 2.68f, CUBIC_TO, 17.75f, 6.64f, 18, 7.78f, 18, 9, CLOSE, MOVE_TO, 4, 15.5f, V_LINE_TO, 14,
    R_H_LINE_TO, 1, V_LINE_TO, 9, R_CUBIC_TO, 0, -1.21f, 0.37f, -2.27f, 1.11f, -3.19f, CUBIC_TO, 6.86f, 4.9f, 7.82f, 4.33f, 9, 4.11f, V_LINE_TO, 3, R_CUBIC_TO,
    0, -0.28f, 0.1f, -0.52f, 0.29f, -0.71f, ARC_TO, 0.96f, 0.96f, 0, 0, 1, 10, 2, R_CUBIC_TO, 0.28f, 0, 0.52f, 0.1f, 0.71f, 0.29f, R_CUBIC_TO, 0.2f, 0.19f,
    0.29f, 0.43f, 0.29f, 0.71f, R_V_LINE_TO, 1.11f, R_CUBIC_TO, 1.18f, 0.22f, 2.14f, 0.79f, 2.89f, 1.71f, CUBIC_TO, 14.63f, 6.73f, 15, 7.79f, 15, 9,
    R_V_LINE_TO, 5, R_H_LINE_TO, 1, R_V_LINE_TO, 1.5f, CLOSE, R_MOVE_TO, 6, -5.75f, CLOSE, MOVE_TO, 10, 18, R_CUBIC_TO, -0.41f, 0, -0.77f, -0.15f, -1.06f,
    -0.44f, ARC_TO, 1.44f, 1.44f, 0, 0, 1, 8.5f, 16.5f, R_H_LINE_TO, 3, R_CUBIC_TO, 0, 0.42f, -0.15f, 0.77f, -0.44f, 1.06f, ARC_TO, 1.45f, 1.45f, 0, 0, 1, 10,
    18, CLOSE, MOVE_TO, 6.5f, 14, R_H_LINE_TO, 7, V_LINE_TO, 9, R_CUBIC_TO, 0, -0.97f, -0.34f, -1.8f, -1.02f, -2.48f, R_CUBIC_TO, -0.68f, -0.68f, -1.51f,
    -1.02f, -2.48f, -1.02f, R_CUBIC_TO, -0.97f, 0, -1.8f, 0.34f, -2.48f, 1.02f, CUBIC_TO, 6.84f, 7.2f, 6.5f, 8.03f, 6.5f, 9, CLOSE)
VECTOR_ICON_TEMPLATE_CC(
    kPriceTrackingEnabledRefreshRepList, kPriceTrackingEnabledRefreshIcon, { kPriceTrackingEnabledRefreshPath, std::size(kPriceTrackingEnabledRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kProductPath, CANVAS_DIMENSIONS, 32, MOVE_TO, 8.82f, 14.1f, CUBIC_TO, 9.25f, 12.52f, 10.18f, 11.12f, 11.48f, 10.13f, CUBIC_TO, 12.77f,
    9.13f, 14.36f, 8.59f, 16, 8.59f, H_LINE_TO, 27.85f, CUBIC_TO, 26.65f, 6.68f, 25.02f, 5.09f, 23.08f, 3.95f, CUBIC_TO, 21.14f, 2.81f, 18.96f, 2.16f, 16.71f,
    2.04f, CUBIC_TO, 14.47f, 1.93f, 12.23f, 2.36f, 10.18f, 3.3f, CUBIC_TO, 8.14f, 4.23f, 6.35f, 5.65f, 4.97f, 7.43f, LINE_TO, 8.82f, 14.1f, CLOSE, NEW_PATH,
    MOVE_TO, 17.92f, 23.2f, CUBIC_TO, 16.34f, 23.63f, 14.66f, 23.53f, 13.15f, 22.9f, CUBIC_TO, 11.64f, 22.28f, 10.38f, 21.16f, 9.56f, 19.74f, LINE_TO, 9.56f,
    19.75f, LINE_TO, 3.63f, 9.48f, CUBIC_TO, 2.58f, 11.47f, 2.02f, 13.68f, 2, 15.93f, CUBIC_TO, 1.98f, 18.18f, 2.51f, 20.4f, 3.54f, 22.4f, CUBIC_TO, 4.56f,
    24.4f, 6.05f, 26.13f, 7.89f, 27.43f, CUBIC_TO, 9.72f, 28.73f, 11.84f, 29.57f, 14.07f, 29.88f, LINE_TO, 17.92f, 23.2f, CLOSE, NEW_PATH, MOVE_TO, 21.27f,
    10.78f, CUBIC_TO, 22.42f, 11.93f, 23.16f, 13.44f, 23.38f, 15.06f, CUBIC_TO, 23.59f, 16.68f, 23.26f, 18.33f, 22.44f, 19.74f, LINE_TO, 22.44f, 19.75f,
    LINE_TO, 16.52f, 30, CUBIC_TO, 18.77f, 29.92f, 20.97f, 29.3f, 22.92f, 28.19f, CUBIC_TO, 24.88f, 27.08f, 26.53f, 25.52f, 27.76f, 23.63f, CUBIC_TO, 28.98f,
    21.74f, 29.73f, 19.59f, 29.94f, 17.35f, CUBIC_TO, 30.15f, 15.11f, 29.82f, 12.86f, 28.97f, 10.78f, H_LINE_TO, 21.27f, CLOSE, NEW_PATH, MOVE_TO, 16, 21.28f,
    CUBIC_TO, 18.9f, 21.28f, 21.25f, 18.93f, 21.25f, 16.03f, CUBIC_TO, 21.25f, 13.13f, 18.9f, 10.78f, 16, 10.78f, CUBIC_TO, 13.1f, 10.78f, 10.75f, 13.13f,
    10.75f, 16.03f, CUBIC_TO, 10.75f, 18.93f, 13.1f, 21.28f, 16, 21.28f, CLOSE, NEW_PATH)
VECTOR_ICON_REP_TEMPLATE(kProduct16Path, CANVAS_DIMENSIONS, 16, MOVE_TO, 10.93f, 5.38f, CUBIC_TO, 11.49f, 5.99f, 11.83f, 6.77f, 11.92f, 7.59f, CUBIC_TO, 12,
    8.42f, 11.82f, 9.25f, 11.41f, 9.97f, H_LINE_TO, 11.41f, LINE_TO, 8.52f, 14.98f, CUBIC_TO, 9.62f, 14.9f, 10.68f, 14.56f, 11.62f, 13.99f, CUBIC_TO, 12.57f,
    13.42f, 13.36f, 12.63f, 13.94f, 11.7f, CUBIC_TO, 14.53f, 10.76f, 14.88f, 9.7f, 14.97f, 8.6f, CUBIC_TO, 15.07f, 7.5f, 14.9f, 6.4f, 14.49f, 5.38f, H_LINE_TO,
    10.93f, CLOSE, NEW_PATH, MOVE_TO, 4.26f, 6.77f, CUBIC_TO, 4.52f, 5.98f, 5.02f, 5.3f, 5.69f, 4.81f, CUBIC_TO, 6.36f, 4.32f, 7.17f, 4.06f, 8, 4.06f,
    H_LINE_TO, 13.79f, CUBIC_TO, 13.17f, 3.15f, 12.34f, 2.4f, 11.37f, 1.87f, CUBIC_TO, 10.41f, 1.34f, 9.33f, 1.04f, 8.23f, 1, CUBIC_TO, 7.13f, 0.97f, 6.03f,
    1.19f, 5.03f, 1.66f, CUBIC_TO, 4.04f, 2.13f, 3.16f, 2.82f, 2.48f, 3.69f, LINE_TO, 4.26f, 6.77f, CLOSE, NEW_PATH, MOVE_TO, 8.81f, 11.85f, CUBIC_TO, 7.99f,
    12.02f, 7.15f, 11.93f, 6.39f, 11.59f, CUBIC_TO, 5.64f, 11.26f, 5.01f, 10.69f, 4.59f, 9.97f, V_LINE_TO, 9.97f, LINE_TO, 1.7f, 4.96f, CUBIC_TO, 1.22f, 5.95f,
    0.98f, 7.04f, 1, 8.14f, CUBIC_TO, 1.02f, 9.25f, 1.31f, 10.33f, 1.83f, 11.3f, CUBIC_TO, 2.35f, 12.27f, 3.09f, 13.11f, 3.99f, 13.74f, CUBIC_TO, 4.9f, 14.37f,
    5.94f, 14.78f, 7.03f, 14.93f, LINE_TO, 8.81f, 11.85f, CLOSE, NEW_PATH, MOVE_TO, 8, 10.63f, CUBIC_TO, 9.45f, 10.63f, 10.63f, 9.45f, 10.63f, 8, CUBIC_TO,
    10.63f, 6.55f, 9.45f, 5.38f, 8, 5.38f, CUBIC_TO, 6.55f, 5.38f, 5.38f, 6.55f, 5.38f, 8, CUBIC_TO, 5.38f, 9.45f, 6.55f, 10.63f, 8, 10.63f, CLOSE, NEW_PATH)
VECTOR_ICON_TEMPLATE_CC(kProductRepList, kProductIcon, { kProductPath, std::size(kProductPath) }, { kProduct16Path, std::size(kProduct16Path) })
VECTOR_ICON_REP_TEMPLATE(kProductChromeRefreshPath, CANVAS_DIMENSIONS, 15, MOVE_TO, 4.92f, 7.5f, R_CUBIC_TO, 0, 0.71f, 0.25f, 1.31f, 0.76f, 1.82f, R_CUBIC_TO,
    0.51f, 0.51f, 1.12f, 0.76f, 1.82f, 0.76f, R_CUBIC_TO, 0.7f, 0, 1.31f, -0.25f, 1.82f, -0.76f, R_CUBIC_TO, 0.51f, -0.51f, 0.76f, -1.12f, 0.76f, -1.82f,
    R_CUBIC_TO, 0, -0.7f, -0.25f, -1.31f, -0.76f, -1.82f, R_ARC_TO, 2.49f, 2.49f, 0, 0, 0, -1.82f, -0.76f, R_CUBIC_TO, -0.7f, 0, -1.31f, 0.25f, -1.82f, 0.76f,
    R_ARC_TO, 2.49f, 2.49f, 0, 0, 0, -0.76f, 1.82f, CLOSE, MOVE_TO, 7.5f, 11.48f, R_CUBIC_TO, 0.14f, 0, 0.28f, 0, 0.41f, -0.02f, R_CUBIC_TO, 0.13f, -0.01f,
    0.26f, -0.04f, 0.39f, -0.07f, LINE_TO, 6.77f, 14.06f, R_CUBIC_TO, -1.65f, -0.19f, -3.04f, -0.89f, -4.15f, -2.12f, CUBIC_TO, 1.5f, 10.71f, 0.94f, 9.24f,
    0.94f, 7.55f, R_CUBIC_TO, 0, -0.46f, 0.05f, -0.9f, 0.13f, -1.33f, R_CUBIC_TO, 0.08f, -0.44f, 0.22f, -0.85f, 0.39f, -1.25f, R_LINE_TO, 2.63f, 4.55f,
    R_CUBIC_TO, 0.34f, 0.59f, 0.81f, 1.07f, 1.41f, 1.43f, R_CUBIC_TO, 0.6f, 0.36f, 1.26f, 0.54f, 2.01f, 0.54f, CLOSE, R_MOVE_TO, 0, -7.87f, R_CUBIC_TO, -0.87f,
    0, -1.65f, 0.25f, -2.33f, 0.77f, R_ARC_TO, 3.95f, 3.95f, 0, 0, 0, -1.42f, 1.94f, LINE_TO, 2.21f, 3.66f, R_ARC_TO, 6.79f, 6.79f, 0, 0, 1, 2.27f, -1.94f,
    CUBIC_TO, 5.4f, 1.22f, 6.4f, 0.98f, 7.5f, 0.98f, R_CUBIC_TO, 1.1f, 0, 2.08f, 0.24f, 2.99f, 0.72f, ARC_TO, 6.66f, 6.66f, 0, 0, 1, 12.76f, 3.6f, H_LINE_TO,
    7.51f, R_LINE_TO, -0.01f, 0.01f, CLOSE, R_MOVE_TO, 6.01f, 1.31f, R_CUBIC_TO, 0.19f, 0.4f, 0.32f, 0.83f, 0.41f, 1.27f, R_CUBIC_TO, 0.09f, 0.44f, 0.15f,
    0.89f, 0.15f, 1.36f, R_CUBIC_TO, 0, 1.7f, -0.55f, 3.16f, -1.68f, 4.38f, R_CUBIC_TO, -1.11f, 1.23f, -2.47f, 1.93f, -4.1f, 2.13f, R_LINE_TO, 2.63f, -4.55f,
    R_CUBIC_TO, 0.17f, -0.28f, 0.29f, -0.59f, 0.38f, -0.92f, R_CUBIC_TO, 0.09f, -0.34f, 0.15f, -0.69f, 0.15f, -1.05f, R_CUBIC_TO, 0, -0.52f, -0.09f, -0.99f,
    -0.28f, -1.42f, R_ARC_TO, 3.96f, 3.96f, 0, 0, 0, -0.74f, -1.2f, R_H_LINE_TO, 3.08f, R_V_LINE_TO, 0.01f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kProductChromeRefreshRepList, kProductChromeRefreshIcon, { kProductChromeRefreshPath, std::size(kProductChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kProductSpecificationsAddPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 4.17f, 18, CUBIC_TO, 3.71f, 18, 3.32f, 17.84f, 2.99f,
    17.51f, CUBIC_TO, 2.66f, 17.19f, 2.5f, 16.79f, 2.5f, 16.34f, V_LINE_TO, 4.67f, CUBIC_TO, 2.5f, 4.21f, 2.66f, 3.82f, 2.99f, 3.49f, CUBIC_TO, 3.32f, 3.17f,
    3.71f, 3, 4.17f, 3, H_LINE_TO, 10.02f, CUBIC_TO, 9.87f, 3.25f, 9.73f, 3.52f, 9.6f, 3.79f, CUBIC_TO, 9.48f, 4.07f, 9.38f, 4.36f, 9.31f, 4.67f, H_LINE_TO,
    4.17f, V_LINE_TO, 7.17f, H_LINE_TO, 9.31f, CUBIC_TO, 9.38f, 7.47f, 9.48f, 7.77f, 9.59f, 8.04f, CUBIC_TO, 9.71f, 8.32f, 9.85f, 8.59f, 10.02f, 8.84f,
    H_LINE_TO, 7.92f, V_LINE_TO, 16.34f, H_LINE_TO, 12.08f, V_LINE_TO, 10.73f, CUBIC_TO, 12.35f, 10.87f, 12.62f, 10.99f, 12.9f, 11.08f, CUBIC_TO, 13.17f,
    11.17f, 13.46f, 11.23f, 13.75f, 11.27f, V_LINE_TO, 16.34f, H_LINE_TO, 15.83f, V_LINE_TO, 11.19f, CUBIC_TO, 16.14f, 11.12f, 16.43f, 11.02f, 16.71f, 10.9f,
    CUBIC_TO, 16.99f, 10.77f, 17.25f, 10.63f, 17.5f, 10.48f, V_LINE_TO, 16.34f, CUBIC_TO, 17.5f, 16.79f, 17.34f, 17.19f, 17.01f, 17.51f, CUBIC_TO, 16.68f,
    17.84f, 16.29f, 18, 15.83f, 18, H_LINE_TO, 4.17f, CLOSE, MOVE_TO, 4.17f, 16.34f, H_LINE_TO, 6.25f, V_LINE_TO, 8.84f, H_LINE_TO, 4.17f, V_LINE_TO, 16.34f,
    CLOSE, MOVE_TO, 4.17f, 18, H_LINE_TO, 6.25f, H_LINE_TO, 2.5f, H_LINE_TO, 4.17f, CLOSE, MOVE_TO, 14.58f, 10.5f, CUBIC_TO, 14.58f, 9.22f, 14.14f, 8.14f,
    13.25f, 7.25f, CUBIC_TO, 12.36f, 6.36f, 11.28f, 5.92f, 10, 5.92f, CUBIC_TO, 11.28f, 5.92f, 12.36f, 5.47f, 13.25f, 4.59f, CUBIC_TO, 14.14f, 3.7f, 14.58f,
    2.61f, 14.58f, 1.34f, CUBIC_TO, 14.58f, 2.61f, 15.03f, 3.7f, 15.92f, 4.59f, CUBIC_TO, 16.81f, 5.47f, 17.89f, 5.92f, 19.17f, 5.92f, CUBIC_TO, 17.89f, 5.92f,
    16.81f, 6.36f, 15.92f, 7.25f, CUBIC_TO, 15.03f, 8.14f, 14.58f, 9.22f, 14.58f, 10.5f, CLOSE, NEW_PATH)
VECTOR_ICON_TEMPLATE_CC(
    kProductSpecificationsAddRepList, kProductSpecificationsAddIcon, { kProductSpecificationsAddPath, std::size(kProductSpecificationsAddPath) })
VECTOR_ICON_REP_TEMPLATE(kProductSpecificationsAddedPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 4.17f, 18.5f, CUBIC_TO, 3.71f, 18.5f, 3.32f,
    18.34f, 2.99f, 18.01f, CUBIC_TO, 2.66f, 17.69f, 2.5f, 17.29f, 2.5f, 16.84f, V_LINE_TO, 5.17f, CUBIC_TO, 2.5f, 4.71f, 2.66f, 4.32f, 2.99f, 3.99f, CUBIC_TO,
    3.32f, 3.67f, 3.71f, 3.5f, 4.17f, 3.5f, H_LINE_TO, 10.02f, CUBIC_TO, 9.87f, 3.75f, 9.73f, 4.02f, 9.6f, 4.29f, CUBIC_TO, 9.48f, 4.57f, 9.38f, 4.86f, 9.31f,
    5.17f, H_LINE_TO, 4.17f, V_LINE_TO, 7.67f, H_LINE_TO, 9.31f, CUBIC_TO, 9.38f, 7.97f, 9.48f, 8.27f, 9.59f, 8.54f, CUBIC_TO, 9.71f, 8.82f, 9.85f, 9.09f,
    10.02f, 9.34f, H_LINE_TO, 7.92f, V_LINE_TO, 16.84f, H_LINE_TO, 12.08f, V_LINE_TO, 11.23f, CUBIC_TO, 12.35f, 11.37f, 12.62f, 11.48f, 12.9f, 11.57f, CUBIC_TO,
    13.17f, 11.67f, 13.46f, 11.73f, 13.75f, 11.77f, V_LINE_TO, 16.84f, H_LINE_TO, 15.83f, V_LINE_TO, 11.69f, CUBIC_TO, 16.14f, 11.62f, 16.43f, 11.52f, 16.71f,
    11.4f, CUBIC_TO, 16.99f, 11.27f, 17.25f, 11.13f, 17.5f, 10.98f, V_LINE_TO, 16.84f, CUBIC_TO, 17.5f, 17.29f, 17.34f, 17.69f, 17.01f, 18.01f, CUBIC_TO,
    16.68f, 18.34f, 16.29f, 18.5f, 15.83f, 18.5f, H_LINE_TO, 4.17f, CLOSE, MOVE_TO, 4.17f, 16.84f, H_LINE_TO, 6.25f, V_LINE_TO, 9.34f, H_LINE_TO, 4.17f,
    V_LINE_TO, 16.84f, CLOSE, MOVE_TO, 4.17f, 18.5f, H_LINE_TO, 6.25f, H_LINE_TO, 2.5f, H_LINE_TO, 4.17f, CLOSE, NEW_PATH, FILL_RULE_NONZERO, MOVE_TO, 14.16f,
    9.61f, LINE_TO, 11.25f, 6.7f, LINE_TO, 12.69f, 5.24f, LINE_TO, 14.16f, 6.7f, LINE_TO, 17.78f, 3.05f, LINE_TO, 19.25f, 4.52f, LINE_TO, 14.16f, 9.61f, CLOSE,
    NEW_PATH)
VECTOR_ICON_TEMPLATE_CC(
    kProductSpecificationsAddedRepList, kProductSpecificationsAddedIcon, { kProductSpecificationsAddedPath, std::size(kProductSpecificationsAddedPath) })
VECTOR_ICON_REP_TEMPLATE(kSearchSparkPath, CANVAS_DIMENSIONS, 960, FILL_RULE_NONZERO, MOVE_TO, 784, 840, LINE_TO, 532, 588, R_QUADRATIC_TO, -30, 24, -69, 38,
    R_QUADRATIC_TO, -39, 14, -83, 14, R_QUADRATIC_TO, -109, 0, -184.5f, -75.5f, QUADRATIC_TO_SHORTHAND, 120, 380, R_QUADRATIC_TO, 0, -109, 75.5f, -184.5f,
    QUADRATIC_TO_SHORTHAND, 380, 120, R_QUADRATIC_TO, 31, 0, 60, 6.5f, R_QUADRATIC_TO, 29, 6.5f, 55, 19.5f, R_LINE_TO, -62, 62, R_QUADRATIC_TO, -13, -4, -26,
    -6, R_QUADRATIC_TO, -13, -2, -27, -2, R_QUADRATIC_TO, -75, 0, -127.5f, 52.5f, QUADRATIC_TO_SHORTHAND, 200, 380, R_QUADRATIC_TO, 0, 75, 52.5f, 127.5f,
    QUADRATIC_TO_SHORTHAND, 380, 560, R_QUADRATIC_TO, 70, 0, 120.5f, -45.5f, QUADRATIC_TO_SHORTHAND, 559, 400, R_H_LINE_TO, 80, R_QUADRATIC_TO, -3, 38, -16.5f,
    72, QUADRATIC_TO_SHORTHAND, 588, 532, R_LINE_TO, 252, 252, R_LINE_TO, -56, 56, CLOSE, R_MOVE_TO, -84, -360, R_QUADRATIC_TO, 0, -92, -64, -156,
    R_QUADRATIC_TO, -64, -64, -156, -64, R_QUADRATIC_TO, 92, 0, 156, -64, R_QUADRATIC_TO, 64, -64, 64, -156, R_QUADRATIC_TO, 0, 92, 64, 156, R_QUADRATIC_TO, 64,
    64, 156, 64, R_QUADRATIC_TO, -92, 0, -156, 64, R_QUADRATIC_TO, -64, 64, -64, 156, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kSearchSparkRepList, kSearchSparkIcon, { kSearchSparkPath, std::size(kSearchSparkPath) })
VECTOR_ICON_REP_TEMPLATE(kSecurePageInfoChromeRefreshPath, CANVAS_DIMENSIONS, 16, FILL_RULE_NONZERO, MOVE_TO, 11.66f, 13.77f, R_CUBIC_TO, -0.69f, 0, -1.28f,
    -0.24f, -1.75f, -0.71f, R_ARC_TO, 2.38f, 2.38f, 0, 0, 1, -0.72f, -1.75f, R_CUBIC_TO, 0, -0.69f, 0.24f, -1.28f, 0.72f, -1.75f, R_CUBIC_TO, 0.48f, -0.48f,
    1.06f, -0.72f, 1.75f, -0.72f, R_CUBIC_TO, 0.69f, 0, 1.27f, 0.24f, 1.75f, 0.72f, R_ARC_TO, 2.39f, 2.39f, 0, 0, 1, 0.72f, 1.75f, R_CUBIC_TO, 0, 0.69f, -0.24f,
    1.27f, -0.72f, 1.75f, R_ARC_TO, 2.39f, 2.39f, 0, 0, 1, -1.75f, 0.71f, CLOSE, R_MOVE_TO, 0, -1.34f, R_CUBIC_TO, 0.31f, 0, 0.58f, -0.11f, 0.8f, -0.33f,
    R_ARC_TO, 1.1f, 1.1f, 0, 0, 0, 0.33f, -0.8f, R_CUBIC_TO, 0, -0.31f, -0.11f, -0.58f, -0.33f, -0.8f, R_ARC_TO, 1.09f, 1.09f, 0, 0, 0, -0.8f, -0.33f,
    R_CUBIC_TO, -0.31f, 0, -0.58f, 0.11f, -0.8f, 0.33f, R_ARC_TO, 1.09f, 1.09f, 0, 0, 0, -0.33f, 0.8f, R_CUBIC_TO, 0, 0.31f, 0.11f, 0.58f, 0.33f, 0.8f,
    R_CUBIC_TO, 0.22f, 0.22f, 0.49f, 0.33f, 0.8f, 0.33f, CLOSE, R_MOVE_TO, -9.16f, -0.44f, R_V_LINE_TO, -1.38f, R_H_LINE_TO, 5.49f, R_V_LINE_TO, 1.38f, CLOSE,
    R_MOVE_TO, 1.83f, -4.83f, R_ARC_TO, 2.38f, 2.38f, 0, 0, 1, -1.75f, -0.72f, R_ARC_TO, 2.39f, 2.39f, 0, 0, 1, -0.72f, -1.75f, R_CUBIC_TO, 0, -0.69f, 0.24f,
    -1.27f, 0.72f, -1.75f, R_ARC_TO, 2.39f, 2.39f, 0, 0, 1, 1.75f, -0.71f, R_CUBIC_TO, 0.69f, 0, 1.28f, 0.24f, 1.75f, 0.71f, R_CUBIC_TO, 0.48f, 0.48f, 0.72f,
    1.06f, 0.72f, 1.75f, R_CUBIC_TO, 0, 0.69f, -0.24f, 1.28f, -0.72f, 1.75f, R_CUBIC_TO, -0.48f, 0.48f, -1.06f, 0.72f, -1.75f, 0.72f, CLOSE, R_MOVE_TO, 0,
    -1.34f, R_CUBIC_TO, 0.31f, 0, 0.58f, -0.11f, 0.8f, -0.33f, R_CUBIC_TO, 0.22f, -0.22f, 0.33f, -0.48f, 0.33f, -0.8f, R_CUBIC_TO, 0, -0.31f, -0.11f, -0.58f,
    -0.33f, -0.8f, R_ARC_TO, 1.1f, 1.1f, 0, 0, 0, -0.8f, -0.33f, R_CUBIC_TO, -0.31f, 0, -0.58f, 0.11f, -0.8f, 0.33f, R_ARC_TO, 1.1f, 1.1f, 0, 0, 0, -0.33f,
    0.8f, R_CUBIC_TO, 0, 0.31f, 0.11f, 0.58f, 0.33f, 0.8f, R_CUBIC_TO, 0.22f, 0.22f, 0.49f, 0.33f, 0.8f, 0.33f, CLOSE, R_MOVE_TO, 3.67f, -0.44f, V_LINE_TO, 4,
    R_H_LINE_TO, 5.49f, R_V_LINE_TO, 1.38f, CLOSE, R_MOVE_TO, 3.66f, 5.92f, CLOSE, R_MOVE_TO, -7.33f, -6.61f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(
    kSecurePageInfoChromeRefreshRepList, kSecurePageInfoChromeRefreshIcon, { kSecurePageInfoChromeRefreshPath, std::size(kSecurePageInfoChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kSharePath, CANVAS_DIMENSIONS, 16, MOVE_TO, 12, 10.72f, CUBIC_TO, 11.49f, 10.72f, 11.04f, 10.92f, 10.69f, 11.23f, LINE_TO, 5.94f,
    8.47f, CUBIC_TO, 5.97f, 8.31f, 6, 8.16f, 6, 8, CUBIC_TO, 6, 7.84f, 5.97f, 7.69f, 5.94f, 7.53f, LINE_TO, 10.64f, 4.79f, CUBIC_TO, 11, 5.13f, 11.47f, 5.33f,
    12, 5.33f, CUBIC_TO, 13.11f, 5.33f, 14, 4.44f, 14, 3.33f, CUBIC_TO, 14, 2.23f, 13.11f, 1.33f, 12, 1.33f, CUBIC_TO, 10.89f, 1.33f, 10, 2.23f, 10, 3.33f,
    CUBIC_TO, 10, 3.49f, 10.03f, 3.65f, 10.06f, 3.8f, LINE_TO, 5.36f, 6.54f, CUBIC_TO, 5, 6.21f, 4.53f, 6, 4, 6, CUBIC_TO, 2.89f, 6, 2, 6.89f, 2, 8, CUBIC_TO,
    2, 9.11f, 2.89f, 10, 4, 10, CUBIC_TO, 4.53f, 10, 5, 9.79f, 5.36f, 9.46f, LINE_TO, 10.11f, 12.23f, CUBIC_TO, 10.07f, 12.37f, 10.05f, 12.52f, 10.05f, 12.67f,
    CUBIC_TO, 10.05f, 13.74f, 10.93f, 14.61f, 12, 14.61f, CUBIC_TO, 13.07f, 14.61f, 13.95f, 13.74f, 13.95f, 12.67f, CUBIC_TO, 13.95f, 11.59f, 13.07f, 10.72f,
    12, 10.72f, LINE_TO, 12, 10.72f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kShareRepList, kShareIcon, { kSharePath, std::size(kSharePath) })
VECTOR_ICON_REP_TEMPLATE(kShareChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 14.5f, 18, R_ARC_TO, 2.4f, 2.4f, 0, 0, 1, -1.77f, -0.73f,
    ARC_TO, 2.4f, 2.4f, 0, 0, 1, 12, 15.5f, R_CUBIC_TO, 0, -0.11f, 0.01f, -0.21f, 0.02f, -0.3f, R_CUBIC_TO, 0.02f, -0.09f, 0.04f, -0.19f, 0.06f, -0.3f,
    R_LINE_TO, -4.96f, -3.02f, R_ARC_TO, 1.78f, 1.78f, 0, 0, 1, -0.74f, 0.48f, R_ARC_TO, 2.69f, 2.69f, 0, 0, 1, -0.89f, 0.14f, R_ARC_TO, 2.4f, 2.4f, 0, 0, 1,
    -1.77f, -0.73f, ARC_TO, 2.4f, 2.4f, 0, 0, 1, 3, 10, R_CUBIC_TO, 0, -0.69f, 0.24f, -1.28f, 0.73f, -1.77f, ARC_TO, 2.4f, 2.4f, 0, 0, 1, 5.5f, 7.5f,
    R_CUBIC_TO, 0.31f, 0, 0.6f, 0.05f, 0.89f, 0.16f, R_CUBIC_TO, 0.28f, 0.11f, 0.53f, 0.26f, 0.74f, 0.47f, R_LINE_TO, 4.96f, -3.02f, R_ARC_TO, 4.75f, 4.75f, 0,
    0, 1, -0.06f, -0.3f, ARC_TO, 2.33f, 2.33f, 0, 0, 1, 12, 4.5f, R_CUBIC_TO, 0, -0.69f, 0.24f, -1.28f, 0.73f, -1.77f, ARC_TO, 2.4f, 2.4f, 0, 0, 1, 14.5f, 2,
    R_CUBIC_TO, 0.7f, 0, 1.29f, 0.24f, 1.77f, 0.73f, R_CUBIC_TO, 0.49f, 0.49f, 0.73f, 1.08f, 0.73f, 1.77f, R_CUBIC_TO, 0, 0.7f, -0.24f, 1.29f, -0.73f, 1.77f,
    ARC_TO, 2.4f, 2.4f, 0, 0, 1, 14.5f, 7, R_CUBIC_TO, -0.31f, 0, -0.6f, -0.05f, -0.89f, -0.14f, R_ARC_TO, 1.78f, 1.78f, 0, 0, 1, -0.74f, -0.48f, R_LINE_TO,
    -4.96f, 3.02f, R_CUBIC_TO, 0.03f, 0.11f, 0.05f, 0.21f, 0.06f, 0.3f, R_ARC_TO, 2.33f, 2.33f, 0, 0, 1, 0, 0.6f, R_CUBIC_TO, -0.01f, 0.09f, -0.04f, 0.19f,
    -0.06f, 0.3f, R_LINE_TO, 4.96f, 3.02f, R_CUBIC_TO, 0.21f, -0.23f, 0.45f, -0.4f, 0.74f, -0.49f, R_CUBIC_TO, 0.28f, -0.09f, 0.58f, -0.14f, 0.89f, -0.14f,
    R_CUBIC_TO, 0.7f, 0, 1.29f, 0.24f, 1.77f, 0.73f, R_CUBIC_TO, 0.49f, 0.49f, 0.73f, 1.08f, 0.73f, 1.77f, R_CUBIC_TO, 0, 0.7f, -0.24f, 1.29f, -0.73f, 1.77f,
    R_ARC_TO, 2.4f, 2.4f, 0, 0, 1, -1.77f, 0.73f, CLOSE, R_MOVE_TO, 0, -12.5f, R_CUBIC_TO, 0.28f, 0, 0.52f, -0.1f, 0.71f, -0.29f, R_ARC_TO, 0.96f, 0.96f, 0, 0,
    0, 0.29f, -0.71f, R_ARC_TO, 0.96f, 0.96f, 0, 0, 0, -0.29f, -0.71f, R_ARC_TO, 0.96f, 0.96f, 0, 0, 0, -0.71f, -0.29f, R_ARC_TO, 0.96f, 0.96f, 0, 0, 0, -0.71f,
    0.29f, R_ARC_TO, 0.96f, 0.96f, 0, 0, 0, -0.29f, 0.71f, R_CUBIC_TO, 0, 0.28f, 0.1f, 0.52f, 0.29f, 0.71f, R_CUBIC_TO, 0.19f, 0.19f, 0.43f, 0.29f, 0.71f,
    0.29f, CLOSE, R_MOVE_TO, -9, 5.5f, R_CUBIC_TO, 0.28f, 0, 0.52f, -0.1f, 0.71f, -0.29f, ARC_TO, 0.96f, 0.96f, 0, 0, 0, 6.5f, 10, R_ARC_TO, 0.96f, 0.96f, 0, 0,
    0, -0.29f, -0.71f, ARC_TO, 0.96f, 0.96f, 0, 0, 0, 5.5f, 9, R_ARC_TO, 0.96f, 0.96f, 0, 0, 0, -0.71f, 0.29f, R_ARC_TO, 0.96f, 0.96f, 0, 0, 0, -0.29f, 0.71f,
    R_CUBIC_TO, 0, 0.28f, 0.1f, 0.52f, 0.29f, 0.71f, R_CUBIC_TO, 0.19f, 0.19f, 0.43f, 0.29f, 0.71f, 0.29f, CLOSE, R_MOVE_TO, 9, 5.5f, R_CUBIC_TO, 0.28f, 0,
    0.52f, -0.1f, 0.71f, -0.29f, R_ARC_TO, 0.96f, 0.96f, 0, 0, 0, 0.29f, -0.71f, R_ARC_TO, 0.96f, 0.96f, 0, 0, 0, -0.29f, -0.71f, R_ARC_TO, 0.96f, 0.96f, 0, 0,
    0, -0.71f, -0.29f, R_ARC_TO, 0.96f, 0.96f, 0, 0, 0, -0.71f, 0.29f, R_ARC_TO, 0.96f, 0.96f, 0, 0, 0, -0.29f, 0.71f, R_CUBIC_TO, 0, 0.28f, 0.1f, 0.52f, 0.29f,
    0.71f, R_CUBIC_TO, 0.19f, 0.19f, 0.43f, 0.29f, 0.71f, 0.29f, CLOSE, R_MOVE_TO, 0, -12, CLOSE, R_MOVE_TO, -9, 5.5f, CLOSE, R_MOVE_TO, 9, 5.5f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kShareChromeRefreshRepList, kShareChromeRefreshIcon, { kShareChromeRefreshPath, std::size(kShareChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kSparkPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 8, 15.2f, CUBIC_TO, 8, 14.2f, 7.81f, 13.27f, 7.44f, 12.41f, CUBIC_TO, 7.06f, 11.53f, 6.54f,
    10.77f, 5.88f, 10.12f, CUBIC_TO, 5.23f, 9.46f, 4.47f, 8.94f, 3.59f, 8.56f, CUBIC_TO, 2.73f, 8.19f, 1.8f, 8, 0.8f, 8, CUBIC_TO, 1.8f, 8, 2.73f, 7.81f, 3.59f,
    7.44f, CUBIC_TO, 4.47f, 7.06f, 5.23f, 6.55f, 5.88f, 5.9f, CUBIC_TO, 6.54f, 5.24f, 7.06f, 4.47f, 7.44f, 3.59f, CUBIC_TO, 7.81f, 2.72f, 8, 1.79f, 8, 0.8f,
    CUBIC_TO, 8, 1.79f, 8.19f, 2.72f, 8.56f, 3.59f, CUBIC_TO, 8.94f, 4.47f, 9.45f, 5.24f, 10.1f, 5.9f, CUBIC_TO, 10.76f, 6.55f, 11.53f, 7.06f, 12.41f, 7.44f,
    CUBIC_TO, 13.28f, 7.81f, 14.21f, 8, 15.2f, 8, CUBIC_TO, 14.21f, 8, 13.28f, 8.19f, 12.41f, 8.56f, CUBIC_TO, 11.53f, 8.94f, 10.76f, 9.46f, 10.1f, 10.12f,
    CUBIC_TO, 9.45f, 10.77f, 8.94f, 11.53f, 8.56f, 12.41f, CUBIC_TO, 8.19f, 13.27f, 8, 14.2f, 8, 15.2f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kSparkRepList, kSparkIcon, { kSparkPath, std::size(kSparkPath) })
VECTOR_ICON_REP_TEMPLATE(kStarPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 8, 4, LINE_TO, 9.12f, 6.79f, LINE_TO, 12, 7.05f, LINE_TO, 9.82f, 9.04f, LINE_TO, 10.47f, 12,
    LINE_TO, 8, 10.43f, LINE_TO, 5.53f, 12, LINE_TO, 6.18f, 9.04f, LINE_TO, 4, 7.05f, LINE_TO, 6.88f, 6.79f, LINE_TO, 8, 4, MOVE_TO, 8, 0.5f, LINE_TO, 5.89f,
    5.56f, LINE_TO, 0.5f, 6.03f, LINE_TO, 4.59f, 9.64f, LINE_TO, 3.37f, 15, LINE_TO, 8, 12.16f, LINE_TO, 12.64f, 15, LINE_TO, 11.41f, 9.64f, LINE_TO, 15.5f,
    6.03f, LINE_TO, 10.11f, 5.56f, LINE_TO, 8, 0.5f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kStarRepList, kStarIcon, { kStarPath, std::size(kStarPath) })
VECTOR_ICON_REP_TEMPLATE(kStarActivePath, CANVAS_DIMENSIONS, 16, MOVE_TO, 8, 0.5f, LINE_TO, 5.89f, 5.56f, LINE_TO, 0.5f, 6.03f, LINE_TO, 4.59f, 9.64f, LINE_TO,
    3.37f, 15, LINE_TO, 8, 12.16f, LINE_TO, 12.64f, 15, LINE_TO, 11.41f, 9.64f, LINE_TO, 15.5f, 6.03f, LINE_TO, 10.11f, 5.56f, LINE_TO, 8, 0.5f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kStarActiveRepList, kStarActiveIcon, { kStarActivePath, std::size(kStarActivePath) })
VECTOR_ICON_REP_TEMPLATE(kStarActiveChromeRefreshPath, CANVAS_DIMENSIONS, 20, MOVE_TO, 5.06f, 18, LINE_TO, 6.38f, 12.46f, LINE_TO, 2, 8.73f, LINE_TO, 7.75f,
    8.23f, LINE_TO, 10, 3, LINE_TO, 12.25f, 8.25f, LINE_TO, 18, 8.73f, LINE_TO, 13.63f, 12.46f, LINE_TO, 14.94f, 18, LINE_TO, 10, 15.06f, LINE_TO, 5.06f, 18,
    CLOSE)
VECTOR_ICON_TEMPLATE_CC(
    kStarActiveChromeRefreshRepList, kStarActiveChromeRefreshIcon, { kStarActiveChromeRefreshPath, std::size(kStarActiveChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kStarChromeRefreshPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 7.33f, 13.9f, LINE_TO, 10, 12.31f, R_LINE_TO, 2.69f, 1.58f,
    R_LINE_TO, -0.71f, -3, R_LINE_TO, 2.31f, -1.98f, R_LINE_TO, -3.06f, -0.27f, LINE_TO, 10, 5.79f, LINE_TO, 8.77f, 8.65f, R_LINE_TO, -3.06f, 0.27f, R_LINE_TO,
    2.34f, 1.98f, CLOSE, MOVE_TO, 5.06f, 17, R_LINE_TO, 1.31f, -5.54f, LINE_TO, 2, 7.73f, R_LINE_TO, 5.75f, -0.5f, LINE_TO, 10, 2, R_LINE_TO, 2.25f, 5.25f,
    R_LINE_TO, 5.75f, 0.48f, R_LINE_TO, -4.37f, 3.73f, LINE_TO, 14.94f, 17, LINE_TO, 10, 14.06f, CLOSE, MOVE_TO, 10, 10.06f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kStarChromeRefreshRepList, kStarChromeRefreshIcon, { kStarChromeRefreshPath, std::size(kStarChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kSummarizeAutoPath, CANVAS_DIMENSIONS, 20, FILL_RULE_NONZERO, MOVE_TO, 6.75f, 14, CUBIC_TO, 6.96f, 14, 7.14f, 13.93f, 7.28f, 13.79f,
    CUBIC_TO, 7.43f, 13.64f, 7.5f, 13.46f, 7.5f, 13.25f, CUBIC_TO, 7.5f, 13.04f, 7.43f, 12.86f, 7.29f, 12.72f, CUBIC_TO, 7.14f, 12.57f, 6.96f, 12.5f, 6.75f,
    12.5f, CUBIC_TO, 6.54f, 12.5f, 6.36f, 12.57f, 6.22f, 12.71f, CUBIC_TO, 6.07f, 12.86f, 6, 13.04f, 6, 13.25f, CUBIC_TO, 6, 13.46f, 6.07f, 13.64f, 6.21f,
    13.78f, CUBIC_TO, 6.36f, 13.93f, 6.54f, 14, 6.75f, 14, CLOSE, MOVE_TO, 6.75f, 10.75f, CUBIC_TO, 6.96f, 10.75f, 7.14f, 10.68f, 7.28f, 10.54f, CUBIC_TO,
    7.43f, 10.39f, 7.5f, 10.21f, 7.5f, 10, CUBIC_TO, 7.5f, 9.79f, 7.43f, 9.61f, 7.29f, 9.47f, CUBIC_TO, 7.14f, 9.32f, 6.96f, 9.25f, 6.75f, 9.25f, CUBIC_TO,
    6.54f, 9.25f, 6.36f, 9.32f, 6.22f, 9.46f, CUBIC_TO, 6.07f, 9.61f, 6, 9.79f, 6, 10, CUBIC_TO, 6, 10.21f, 6.07f, 10.39f, 6.21f, 10.53f, CUBIC_TO, 6.36f,
    10.68f, 6.54f, 10.75f, 6.75f, 10.75f, CLOSE, MOVE_TO, 6.75f, 7.5f, CUBIC_TO, 6.96f, 7.5f, 7.14f, 7.43f, 7.28f, 7.29f, CUBIC_TO, 7.43f, 7.14f, 7.5f, 6.96f,
    7.5f, 6.75f, CUBIC_TO, 7.5f, 6.54f, 7.43f, 6.36f, 7.29f, 6.22f, CUBIC_TO, 7.14f, 6.07f, 6.96f, 6, 6.75f, 6, CUBIC_TO, 6.54f, 6, 6.36f, 6.07f, 6.22f, 6.21f,
    CUBIC_TO, 6.07f, 6.36f, 6, 6.54f, 6, 6.75f, CUBIC_TO, 6, 6.96f, 6.07f, 7.14f, 6.21f, 7.28f, CUBIC_TO, 6.36f, 7.43f, 6.54f, 7.5f, 6.75f, 7.5f, CLOSE,
    MOVE_TO, 9, 14, LINE_TO, 14, 14, LINE_TO, 14, 12.5f, LINE_TO, 9, 12.5f, CLOSE, MOVE_TO, 9, 10.75f, LINE_TO, 13, 10.75f, LINE_TO, 13, 9.25f, LINE_TO, 9,
    9.25f, CLOSE, MOVE_TO, 4.5f, 17, CUBIC_TO, 4.09f, 17, 3.73f, 16.85f, 3.44f, 16.55f, CUBIC_TO, 3.15f, 16.25f, 3, 15.9f, 3, 15.5f, LINE_TO, 3, 4.5f, CUBIC_TO,
    3, 4.1f, 3.15f, 3.75f, 3.44f, 3.45f, CUBIC_TO, 3.73f, 3.15f, 4.09f, 3, 4.5f, 3, LINE_TO, 11, 3, LINE_TO, 11, 4.5f, LINE_TO, 4.5f, 4.5f, LINE_TO, 4.5f,
    15.5f, LINE_TO, 15.5f, 15.5f, LINE_TO, 15.5f, 9, LINE_TO, 17, 9, LINE_TO, 17, 15.5f, CUBIC_TO, 17, 15.9f, 16.85f, 16.25f, 16.56f, 16.55f, CUBIC_TO, 16.27f,
    16.85f, 15.91f, 17, 15.5f, 17, CLOSE, MOVE_TO, 14.5f, 10, CUBIC_TO, 14.5f, 8.75f, 14.06f, 7.68f, 13.19f, 6.81f, CUBIC_TO, 12.32f, 5.94f, 11.25f, 5.5f, 10,
    5.5f, CUBIC_TO, 11.25f, 5.5f, 12.32f, 5.06f, 13.19f, 4.19f, CUBIC_TO, 14.06f, 3.32f, 14.5f, 2.25f, 14.5f, 1, CUBIC_TO, 14.5f, 2.25f, 14.94f, 3.32f, 15.81f,
    4.19f, CUBIC_TO, 16.68f, 5.06f, 17.75f, 5.5f, 19, 5.5f, CUBIC_TO, 17.75f, 5.5f, 16.68f, 5.94f, 15.81f, 6.81f, CUBIC_TO, 14.94f, 7.68f, 14.5f, 8.75f, 14.5f,
    10, CLOSE, MOVE_TO, 10, 10, CLOSE, MOVE_TO, 10, 10, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kSummarizeAutoRepList, kSummarizeAutoIcon, { kSummarizeAutoPath, std::size(kSummarizeAutoPath) })
VECTOR_ICON_REP_TEMPLATE(kSwitchPath, CANVAS_DIMENSIONS, 32, MOVE_TO, 25.33f, 5.33f, CUBIC_TO, 26.8f, 5.33f, 28, 6.53f, 28, 8, R_V_LINE_TO, 16, R_CUBIC_TO, 0,
    1.47f, -1.2f, 2.67f, -2.67f, 2.67f, H_LINE_TO, 6.67f, ARC_TO, 2.68f, 2.68f, 0, 0, 1, 4, 24, V_LINE_TO, 8, R_CUBIC_TO, 0, -1.47f, 1.2f, -2.67f, 2.67f,
    -2.67f, R_H_LINE_TO, 18.67f, CLOSE, R_MOVE_TO, 0, 18.67f, V_LINE_TO, 13.33f, R_H_LINE_TO, -8, V_LINE_TO, 8, H_LINE_TO, 6.67f, R_V_LINE_TO, 16, R_H_LINE_TO,
    18.67f, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kSwitch16Path, CANVAS_DIMENSIONS, 16, R_MOVE_TO, 13.44f, 2, R_CUBIC_TO, 0.86f, 0, 1.56f, 0.68f, 1.56f, 1.5f, R_V_LINE_TO, 9,
    R_CUBIC_TO, 0, 0.83f, -0.7f, 1.5f, -1.56f, 1.5f, R_H_LINE_TO, -10.89f, R_CUBIC_TO, -0.86f, 0, -1.56f, -0.67f, -1.56f, -1.5f, R_V_LINE_TO, -9, R_CUBIC_TO, 0,
    -0.82f, 0.7f, -1.5f, 1.56f, -1.5f, CLOSE, R_MOVE_TO, -0.44f, 10, R_V_LINE_TO, -5, R_H_LINE_TO, -4, R_V_LINE_TO, -3, R_H_LINE_TO, -6, R_V_LINE_TO, 8, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kSwitchRepList, kSwitchIcon, { kSwitchPath, std::size(kSwitchPath) }, { kSwitch16Path, std::size(kSwitch16Path) })
VECTOR_ICON_REP_TEMPLATE(kSwitchCr2023Path, CANVAS_DIMENSIONS, 16, MOVE_TO, 2.85f, 11.55f, R_H_LINE_TO, 10.3f, V_LINE_TO, 7.2f, H_LINE_TO, 8.8f, V_LINE_TO,
    4.45f, H_LINE_TO, 2.85f, CLOSE, R_MOVE_TO, 0, 1.38f, R_CUBIC_TO, -0.38f, 0, -0.71f, -0.13f, -0.98f, -0.4f, R_ARC_TO, 1.34f, 1.34f, 0, 0, 1, -0.4f, -0.98f,
    V_LINE_TO, 4.44f, R_CUBIC_TO, 0, -0.38f, 0.13f, -0.71f, 0.4f, -0.98f, R_CUBIC_TO, 0.27f, -0.27f, 0.6f, -0.4f, 0.98f, -0.4f, R_H_LINE_TO, 10.31f, R_CUBIC_TO,
    0.38f, 0, 0.71f, 0.13f, 0.98f, 0.4f, R_CUBIC_TO, 0.27f, 0.27f, 0.4f, 0.6f, 0.4f, 0.98f, R_V_LINE_TO, 7.11f, R_CUBIC_TO, 0, 0.38f, -0.13f, 0.71f, -0.4f,
    0.98f, R_CUBIC_TO, -0.27f, 0.27f, -0.6f, 0.4f, -0.98f, 0.4f, CLOSE, R_MOVE_TO, 0, -1.38f, V_LINE_TO, 4.45f, CLOSE, R_MOVE_TO, 0, 0, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kSwitchCr2023RepList, kSwitchCr2023Icon, { kSwitchCr2023Path, std::size(kSwitchCr2023Path) })
VECTOR_ICON_REP_TEMPLATE(kTabPath, CANVAS_DIMENSIONS, 32, MOVE_TO, 3, 26, LINE_TO, 7, 12, LINE_TO, 24, 12, LINE_TO, 28, 26, LINE_TO, 24, 26, LINE_TO, 22, 16,
    LINE_TO, 9, 16, LINE_TO, 7, 26, LINE_TO, 3, 26, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kTabRepList, kTabIcon, { kTabPath, std::size(kTabPath) })
VECTOR_ICON_REP_TEMPLATE(kTrendingUpPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 10.8f, 4, R_V_LINE_TO, 1.33f, R_H_LINE_TO, 1.81f, LINE_TO, 8.99f, 8.78f, R_LINE_TO,
    -2.8f, -2.67f, LINE_TO, 1, 11.06f, R_LINE_TO, 0.99f, 0.94f, R_LINE_TO, 4.2f, -4, R_LINE_TO, 2.8f, 2.67f, LINE_TO, 13.6f, 6.28f, V_LINE_TO, 8, H_LINE_TO, 15,
    V_LINE_TO, 4, R_H_LINE_TO, -4.2f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kTrendingUpRepList, kTrendingUpIcon, { kTrendingUpPath, std::size(kTrendingUpPath) })
VECTOR_ICON_REP_TEMPLATE(kTrendingUpChromeRefreshPath, CANVAS_DIMENSIONS, 16, R_MOVE_TO, 2.47f, 12.09f, R_LINE_TO, -0.98f, -0.98f, R_LINE_TO, 4.82f, -4.81f,
    R_LINE_TO, 2.53f, 2.53f, R_LINE_TO, 3.31f, -3.3f, R_H_LINE_TO, -1.91f, V_LINE_TO, 4.16f, R_H_LINE_TO, 4.27f, R_V_LINE_TO, 4.27f, R_H_LINE_TO, -1.38f,
    V_LINE_TO, 6.52f, R_LINE_TO, -4.29f, 4.28f, R_LINE_TO, -2.53f, -2.53f, CLOSE, R_MOVE_TO, 0, 0, CLOSE)
VECTOR_ICON_TEMPLATE_CC(
    kTrendingUpChromeRefreshRepList, kTrendingUpChromeRefreshIcon, { kTrendingUpChromeRefreshPath, std::size(kTrendingUpChromeRefreshPath) })
VECTOR_ICON_REP_TEMPLATE(kShareWinPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 10.71f, 2.47f, CUBIC_TO, 10.71f, 3.28f, 10.7f, 3.95f, 10.69f, 3.95f, CUBIC_TO, 10.69f,
    3.96f, 10.56f, 3.97f, 10.42f, 3.98f, CUBIC_TO, 9.83f, 4.02f, 9.31f, 4.1f, 8.96f, 4.2f, CUBIC_TO, 8.92f, 4.22f, 8.83f, 4.25f, 8.76f, 4.26f, CUBIC_TO, 8.7f,
    4.28f, 8.58f, 4.32f, 8.5f, 4.35f, CUBIC_TO, 8.41f, 4.38f, 8.34f, 4.41f, 8.34f, 4.41f, CUBIC_TO, 8.28f, 4.41f, 7.64f, 4.72f, 7.35f, 4.89f, CUBIC_TO, 5.7f,
    5.83f, 4.37f, 7.73f, 4.05f, 9.57f, CUBIC_TO, 3.94f, 10.24f, 3.93f, 10.38f, 3.92f, 11.22f, CUBIC_TO, 3.91f, 12.08f, 3.88f, 12.01f, 4.11f, 11.77f, CUBIC_TO,
    4.45f, 11.42f, 4.99f, 10.96f, 5.42f, 10.66f, CUBIC_TO, 5.48f, 10.62f, 5.55f, 10.57f, 5.57f, 10.55f, CUBIC_TO, 5.61f, 10.52f, 5.73f, 10.45f, 5.99f, 10.29f,
    CUBIC_TO, 6.22f, 10.15f, 6.58f, 9.96f, 6.99f, 9.76f, CUBIC_TO, 7.23f, 9.65f, 7.82f, 9.43f, 8.05f, 9.36f, CUBIC_TO, 8.1f, 9.35f, 8.16f, 9.33f, 8.19f, 9.32f,
    CUBIC_TO, 8.33f, 9.28f, 8.57f, 9.22f, 8.64f, 9.21f, CUBIC_TO, 8.68f, 9.2f, 8.75f, 9.18f, 8.78f, 9.18f, CUBIC_TO, 9.05f, 9.12f, 9.21f, 9.09f, 9.36f, 9.07f,
    CUBIC_TO, 9.77f, 9.01f, 10.24f, 8.97f, 10.5f, 8.98f, LINE_TO, 10.7f, 8.98f, LINE_TO, 10.7f, 10.45f, CUBIC_TO, 10.71f, 11.25f, 10.71f, 11.92f, 10.72f,
    11.93f, CUBIC_TO, 10.72f, 11.95f, 15.99f, 6.51f, 16, 6.48f, CUBIC_TO, 16.01f, 6.46f, 10.74f, 1, 10.72f, 1, CUBIC_TO, 10.71f, 1, 10.71f, 1.66f, 10.71f,
    2.47f, MOVE_TO, 13.18f, 4.92f, CUBIC_TO, 13.99f, 5.77f, 14.66f, 6.47f, 14.66f, 6.48f, CUBIC_TO, 14.65f, 6.51f, 11.69f, 9.56f, 11.68f, 9.55f, CUBIC_TO,
    11.67f, 9.55f, 11.66f, 9.27f, 11.66f, 8.77f, LINE_TO, 11.65f, 8, LINE_TO, 10.79f, 8.01f, CUBIC_TO, 10.32f, 8.01f, 9.87f, 8.02f, 9.8f, 8.03f, CUBIC_TO,
    9.72f, 8.04f, 9.58f, 8.06f, 9.48f, 8.07f, CUBIC_TO, 9.38f, 8.08f, 9.26f, 8.09f, 9.21f, 8.1f, CUBIC_TO, 9.17f, 8.11f, 9.06f, 8.13f, 8.97f, 8.14f, CUBIC_TO,
    8.88f, 8.16f, 8.72f, 8.19f, 8.61f, 8.21f, CUBIC_TO, 8.5f, 8.23f, 8.4f, 8.26f, 8.37f, 8.26f, CUBIC_TO, 8.34f, 8.27f, 7.98f, 8.36f, 7.86f, 8.4f, CUBIC_TO,
    7.68f, 8.45f, 7.1f, 8.65f, 6.97f, 8.71f, CUBIC_TO, 6.94f, 8.72f, 6.89f, 8.74f, 6.84f, 8.76f, CUBIC_TO, 6.36f, 8.95f, 5.75f, 9.27f, 5.28f, 9.58f, CUBIC_TO,
    5.23f, 9.61f, 5.16f, 9.66f, 5.12f, 9.68f, CUBIC_TO, 4.96f, 9.79f, 4.96f, 9.75f, 5.14f, 9.13f, CUBIC_TO, 5.54f, 7.75f, 6.64f, 6.38f, 7.9f, 5.68f, CUBIC_TO,
    7.97f, 5.64f, 8.04f, 5.61f, 8.05f, 5.6f, CUBIC_TO, 8.1f, 5.57f, 8.4f, 5.43f, 8.46f, 5.41f, CUBIC_TO, 8.5f, 5.39f, 8.55f, 5.37f, 8.59f, 5.35f, CUBIC_TO,
    8.78f, 5.27f, 9.23f, 5.13f, 9.55f, 5.07f, CUBIC_TO, 9.59f, 5.06f, 9.66f, 5.05f, 9.71f, 5.04f, CUBIC_TO, 9.97f, 4.99f, 10.48f, 4.96f, 11.12f, 4.96f, LINE_TO,
    11.65f, 4.96f, LINE_TO, 11.65f, 4.2f, CUBIC_TO, 11.65f, 3.48f, 11.66f, 3.38f, 11.68f, 3.38f, CUBIC_TO, 11.69f, 3.38f, 12.36f, 4.07f, 13.18f, 4.92f, MOVE_TO,
    1.01f, 4.98f, CUBIC_TO, 1, 4.99f, 1, 7.25f, 1, 10, LINE_TO, 1, 15, LINE_TO, 6.81f, 15, LINE_TO, 12.63f, 15, LINE_TO, 12.63f, 13.53f, CUBIC_TO, 12.63f,
    12.72f, 12.62f, 12.05f, 12.61f, 12.05f, CUBIC_TO, 12.61f, 12.04f, 12.39f, 12.26f, 12.14f, 12.53f, LINE_TO, 11.68f, 13.01f, LINE_TO, 11.67f, 13.51f, LINE_TO,
    11.66f, 14.02f, LINE_TO, 6.81f, 14.02f, LINE_TO, 1.97f, 14.02f, LINE_TO, 1.96f, 9.5f, LINE_TO, 1.95f, 4.98f, LINE_TO, 1.49f, 4.98f, CUBIC_TO, 1.23f, 4.97f,
    1.02f, 4.98f, 1.01f, 4.98f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kShareWinRepList, kShareWinIcon, { kShareWinPath, std::size(kShareWinPath) })
VECTOR_ICON_REP_TEMPLATE(kShareWinChromeRefreshPath, CANVAS_DIMENSIONS, 20, MOVE_TO, 14.5f, 15.5f, R_H_LINE_TO, -10, V_LINE_TO, 4, H_LINE_TO, 3, R_V_LINE_TO,
    11.5f, R_CUBIC_TO, 0, 0.83f, 0.67f, 1.5f, 1.5f, 1.5f, R_H_LINE_TO, 10, R_CUBIC_TO, 0.83f, 0, 1.5f, -0.67f, 1.5f, -1.5f, V_LINE_TO, 12, R_H_LINE_TO, -1.5f,
    R_V_LINE_TO, 3.5f, CLOSE, NEW_PATH, MOVE_TO, 7.5f, 7.25f, R_H_LINE_TO, 6.63f, R_LINE_TO, -1.69f, 1.69f, LINE_TO, 13.5f, 10, LINE_TO, 17, 6.5f, LINE_TO,
    13.5f, 3, R_LINE_TO, -1.06f, 1.06f, R_LINE_TO, 1.69f, 1.69f, H_LINE_TO, 7.5f, R_CUBIC_TO, -0.83f, 0, -1.5f, 0.67f, -1.5f, 1.5f, R_V_LINE_TO, 4.25f,
    R_H_LINE_TO, 1.5f, V_LINE_TO, 7.25f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kShareWinChromeRefreshRepList, kShareWinChromeRefreshIcon, { kShareWinChromeRefreshPath, std::size(kShareWinChromeRefreshPath) })

}
