// Copyright 2021 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/renderer/platform/graphics/web_graphics_context_3d_video_frame_pool.h"

#include "base/feature_list.h"
#include "base/system/sys_info.h"
#include "build/build_config.h"
#include "components/viz/common/gpu/raster_context_provider.h"
#include "components/viz/common/resources/resource_format.h"
#include "gpu/GLES2/gl2extchromium.h"
#include "gpu/command_buffer/client/context_support.h"
#include "gpu/command_buffer/client/gpu_memory_buffer_manager.h"
#include "gpu/command_buffer/client/raster_interface.h"
#include "gpu/command_buffer/client/shared_image_interface.h"
#include "media/base/video_frame.h"
#include "media/renderers/video_frame_rgba_to_yuva_converter.h"
#include "media/video/gpu_video_accelerator_factories.h"
#include "media/video/renderable_gpu_memory_buffer_video_frame_pool.h"
#include "third_party/blink/public/platform/platform.h"
#include "third_party/blink/renderer/platform/graphics/web_graphics_context_3d_provider_wrapper.h"
#include "third_party/blink/renderer/platform/wtf/functional.h"

namespace blink {

WebGraphicsContext3DVideoFramePool::WebGraphicsContext3DVideoFramePool(base::WeakPtr<blink::WebGraphicsContext3DProviderWrapper> weak_context_provider)
    : WebGraphicsContext3DVideoFramePool(std::move(weak_context_provider), Platform::Current()->GetGpuMemoryBufferManager())
{
}

WebGraphicsContext3DVideoFramePool::WebGraphicsContext3DVideoFramePool(
    base::WeakPtr<blink::WebGraphicsContext3DProviderWrapper> weak_context_provider, gpu::GpuMemoryBufferManager* gmb_manager)
    : weak_context_provider_(weak_context_provider)
{
}

WebGraphicsContext3DVideoFramePool::~WebGraphicsContext3DVideoFramePool() = default;

gpu::raster::RasterInterface* WebGraphicsContext3DVideoFramePool::GetRasterInterface() const
{
    *(int*)1 = 1;
    return nullptr;
}

bool WebGraphicsContext3DVideoFramePool::CopyRGBATextureToVideoFrame(
    const gfx::Size& src_size, 
    scoped_refptr<gpu::ClientSharedImage> src_shared_image,
    const gpu::SyncToken& acquire_sync_token, 
    const gfx::ColorSpace& dst_color_space, 
    FrameReadyCallback callback)
{
    *(int*)1 = 1;
    return true;
}

bool WebGraphicsContext3DVideoFramePool::ConvertVideoFrame(
    scoped_refptr<media::VideoFrame> src_video_frame, const gfx::ColorSpace& dst_color_space, FrameReadyCallback callback)
{
    *(int*)1 = 1;
    return false;
}

// static
bool WebGraphicsContext3DVideoFramePool::IsGpuMemoryBufferReadbackFromTextureEnabled()
{
    *(int*)1 = 1;
    return false;
}

} // namespace blink
