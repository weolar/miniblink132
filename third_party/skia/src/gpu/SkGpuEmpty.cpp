/*
 * Copyright 2016 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/core/SkColor.h"
#include "include/core/SkPaint.h"
#include "include/core/SkShader.h"
#include "include/core/SkBlender.h"
#include "include/core/SkPicture.h"
//#include "include/private/SkTo.h"
#include "include/effects/SkPerlinNoiseShader.h"
#include "include/effects/SkGradientShader.h"
#include "include/gpu/ganesh/GrDirectContext.h"

//#include "src/core/SkArenaAlloc.h"
#include "src/core/SkBlendModePriv.h"
#include "src/core/SkBlitter.h"
//#include "src/core/SkColorFilterBase.h"
#include "src/core/SkColorSpacePriv.h"
#include "src/core/SkColorSpaceXformSteps.h"
//#include "src/core/SkMatrixProvider.h"
#include "src/core/SkOpts.h"
#include "src/core/SkRasterPipeline.h"
//#include "src/core/SkUtils.h"
#include "src/core/SkStrikeSpec.h"
#include "src/core/SkStrikeCache.h"
#include "src/shaders/SkShaderBase.h"
#include "src/shaders/SkColorFilterShader.h"
#include "src/shaders/SkImageShader.h"
#include "src/lazy/SkDiscardableMemoryPool.h"

#define SK_BLITTER_TRACE_IS_RASTER_PIPELINE
//#include "src/utils/SkBlitterTrace.h"

#include "src/text/StrikeForGPU.h"

#if 0

bool SkColorFilterShader::isOpaque(void)const
{
    *(int*)1 = 1;
    return false;
}

void SkColorFilterShader::flatten(SkWriteBuffer&)const
{
    *(int*)1 = 1;
}

bool SkColorFilterShader::onAppendStages(SkStageRec const&)const
{
    *(int*)1 = 1;
    return false;
}

sk_sp<SkShader> SkShader::makeWithLocalMatrix(class SkMatrix const&)const
{
    *(int*)1 = 1;
    return nullptr;
}

skvm::Color SkColorFilterShader::onProgram(skvm::Builder*,
    skvm::Coord, skvm::Coord, skvm::Color, SkMatrixProvider const&,
    SkMatrix const*, SkColorInfo const&, skvm::Uniforms*, SkArenaAlloc*)const
{
    *(int*)1 = 1;
    return skvm::Color();
}

sk_sp<SkFlattenable> SkColorFilterShader::CreateProc(SkReadBuffer&)
{
    *(int*)1 = 1;
    return nullptr;
}

sk_sp<SkShader> SkPicture::makeShader(SkTileMode, SkTileMode, SkFilterMode, SkMatrix const*, SkRect const*)const
{
    *(int*)1 = 1;
    return nullptr;
}

extern "C" void __stdcall OutputDebugStringA(const char* lpOutputString);

sk_sp<SkShader> SkMakeBitmapShaderForPaint(const SkPaint& paint, const SkBitmap& src,
    SkTileMode tmx, SkTileMode tmy,
    const SkSamplingOptions& sampling,
    const SkMatrix* localMatrix, SkCopyPixelsMode mode)
{
    OutputDebugStringA("SkMakeBitmapShaderForPaint is empty\n");
    return nullptr;
}

SkColorFilterShader::SkColorFilterShader(class sk_sp<class SkShader>, float, class sk_sp<class SkColorFilter>)
{
    *(int*)1 = 1;
}

bool SkShaderBase::appendStages(SkStageRec const&) const
{
    *(int*)1 = 1;
    return false;
}
bool SkShaderBase::asLuminanceColor(unsigned int*) const
{
    *(int*)1 = 1;
    return false;
}

SkShaderBase::SkShaderBase(void) { *(int*)1 = 1; }

bool SkShaderBase::onAppendStages(struct SkStageRec const&) const
{
    *(int*)1 = 1;
    return false;
}

void SkShaderBase::flatten(class SkWriteBuffer&) const { *(int*)1 = 1; }

SkShaderBase::Context* SkShaderBase::makeContext(SkShaderBase::ContextRec const&, SkArenaAlloc*) const
{
    *(int*)1 = 1;
    return nullptr;
}

SkUpdatableShader* SkShaderBase::updatableShader(SkArenaAlloc*) const
{
    *(int*)1 = 1;
    return nullptr;
}

sk_sp<SkShader> SkShaderBase::makeInvertAlpha(void) const
{
    *(int*)1 = 1;
    return nullptr;
}
sk_sp<SkShader> SkShaderBase::makeWithCTM(SkMatrix const&) const
{
    *(int*)1 = 1;
    return nullptr;
}

void SkShaderBase::RegisterFlattenables(void) { *(int*)1 = 1; }

skvm::Color __thiscall SkShaderBase::program(
    skvm::Builder*, skvm::Coord, skvm::Coord, skvm::Color, SkMatrixProvider const&, SkMatrix const*, SkColorInfo const&, skvm::Uniforms*, SkArenaAlloc*) const
{
    *(int*)1 = 1;
    skvm::Color c = { 0 };
    return c;
}

SkShaderBase::~SkShaderBase(void) { *(int*)1 = 1; }

SkUpdatableShader* SkShaderBase::onUpdatableShader(class SkArenaAlloc*) const
{
    *(int*)1 = 1;
    return nullptr;
}

sk_sp<class SkShader> SkShaderBase::makeAsALocalMatrixShader(class SkMatrix*) const
{
    *(int*)1 = 1;
    return nullptr;
}

// sk_sp<SkShader> SkGradientShader::MakeLinear(const SkPoint pts[2], const SkColor4f colors[], sk_sp<SkColorSpace> colorSpace, const SkScalar pos[], int count, SkTileMode mode,
//     const Interpolation& interpolation, const SkMatrix* localMatrix)
// {
//     *(int*)1 = 1;
//     return nullptr;
// }

sk_sp<SkShader> SkGradientShader::MakeRadial(const SkPoint& center, SkScalar radius, const SkColor4f colors[], sk_sp<SkColorSpace> colorSpace, const SkScalar pos[], int count,
    SkTileMode mode, const Interpolation& interpolation, const SkMatrix* localMatrix)
{
    *(int*)1 = 1;
    return nullptr;
}

sk_sp<SkShader> SkGradientShader::MakeSweep(float, float, unsigned int const* const, float const* const, int, SkTileMode, float, float, unsigned int, SkMatrix const*)
{
    *(int*)1 = 1;
    return nullptr;
}

sk_sp<SkShader> SkGradientShader::MakeLinear(const SkPoint pts[2], const SkColor4f colors[], sk_sp<SkColorSpace> colorSpace, const SkScalar pos[], int count, SkTileMode mode,
    const Interpolation& interpolation, const SkMatrix* localMatrix)
{
    *(int*)1 = 1;
    return nullptr;
}

sk_sp<SkShader> SkGradientShader::MakeLinear(SkPoint const* const, unsigned int const* const, float const* const, int, enum SkTileMode, unsigned int, SkMatrix const*)
{
    *(int*)1 = 1;
    return nullptr;
}

sk_sp<SkShader> SkGradientShader::MakeSweep(SkScalar cx, SkScalar cy, const SkColor4f colors[], sk_sp<SkColorSpace> colorSpace, const SkScalar pos[], int count, SkTileMode mode,
    SkScalar startAngle, SkScalar endAngle, const Interpolation& interpolation, const SkMatrix* localMatrix)
{
    *(int*)1 = 1;
    return nullptr;
}
sk_sp<SkShader> SkGradientShader::MakeTwoPointConical(const SkPoint& start, SkScalar startRadius, const SkPoint& end, SkScalar endRadius, const SkColor4f colors[],
    sk_sp<SkColorSpace> colorSpace, const SkScalar pos[], int count, SkTileMode mode, const Interpolation& interpolation, const SkMatrix* localMatrix)
{
    *(int*)1 = 1;
    return nullptr;
}
sk_sp<SkShader> SkImageShader::Make(class sk_sp<class SkImage>, enum SkTileMode, enum SkTileMode, struct SkSamplingOptions const&, class SkMatrix const*, bool) {
    *(int*)1 = 1;
    return nullptr;
}
sk_sp<SkShader> SkImageShader::MakeRaw(class sk_sp<class SkImage>, enum SkTileMode, enum SkTileMode, struct SkSamplingOptions const&, class SkMatrix const*) {
    *(int*)1 = 1;
    return nullptr;
}
sk_sp<SkShader> SkPerlinNoiseShader::MakeFractalNoise(float, float, int, float, struct SkISize const*)
{
    *(int*)1 = 1;
    return nullptr;
}
sk_sp<SkShader> SkPerlinNoiseShader::MakeTurbulence(float, float, int, float, struct SkISize const*)
{
    *(int*)1 = 1;
    return nullptr;
}
sk_sp<SkShader> SkShaders::Blend(sk_sp<SkBlender>, sk_sp<SkShader>, sk_sp<SkShader>)
{
    *(int*)1 = 1;
    return nullptr;
}
sk_sp<SkShader> SkShaders::Blend(SkBlendMode, sk_sp<SkShader>, sk_sp<SkShader>)
{
    *(int*)1 = 1;
    return nullptr;
}

sk_sp<SkShader> SkShaders::Color(const SkColor4f&, sk_sp<SkColorSpace>)
{
    *(int*)1 = 1;
    return nullptr;
}
sk_sp<SkShader> SkShaders::Color(unsigned int)
{
    *(int*)1 = 1;
    return nullptr;
}
sk_sp<SkShader> SkShaders::Empty(void)
{
    *(int*)1 = 1;
    return nullptr;
}

#else

// SkDiscardableMemoryPool* SkGetGlobalDiscardableMemoryPool(void)
// {
//     *(int*)1 = 1;
//     return nullptr;
// }

GrSemaphoresSubmitted GrDirectContext::flush(GrFlushInfo const&)
{
    *(int*)1 = 1;
    return GrSemaphoresSubmitted::kNo;
}

// sk_sp<SkSurface> SkSurface::MakeFromBackendTexture(class GrRecordingContext*, class GrBackendTexture const&, enum GrSurfaceOrigin, int, enum SkColorType,
//     class sk_sp<class SkColorSpace>, class SkSurfaceProps const*, void(__cdecl*)(void*), void*)
// {
//     *(int*)1 = 1;
//     return nullptr;
// }

bool GrDirectContext::submit(const GrSubmitInfo&)
{
    *(int*)1 = 1;
    return false;
}

// sktext::SkStrikePromise::SkStrikePromise(SkStrikeSpec const&)
// {
//     *(int*)1 = 1;
// }
// 
// sktext::SkStrikePromise::SkStrikePromise(class sk_sp<class SkStrike>&&)
// {
//     *(int*)1 = 1;
// }

#endif

//////////////////////////////////////////////////////////////////////////
