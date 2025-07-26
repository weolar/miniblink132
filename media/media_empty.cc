// Copyright 2013 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "media/renderers/video_resource_updater.h"

#include <stddef.h>
#include <stdint.h>

#include <string>
#include "base/atomic_sequence_num.h"
#include "base/bind.h"
#include "base/containers/contains.h"
#include "base/containers/cxx20_erase.h"
#include "base/logging.h"
#include "base/memory/raw_ptr.h"
#include "base/memory/shared_memory_mapping.h"
#include "base/memory/unsafe_shared_memory_region.h"
#include "base/ranges/algorithm.h"
#include "base/strings/stringprintf.h"
#include "base/threading/thread_task_runner_handle.h"
#include "base/trace_event/memory_dump_manager.h"
#include "base/trace_event/process_memory_dump.h"
#include "base/trace_event/trace_event.h"
#include "build/build_config.h"
#include "cc/base/math_util.h"
#include "cc/paint/skia_paint_canvas.h"
#include "cc/paint/texture_backing.h"
#include "components/viz/client/client_resource_provider.h"
#include "components/viz/client/shared_bitmap_reporter.h"
#include "components/viz/common/gpu/context_provider.h"
#include "components/viz/common/gpu/raster_context_provider.h"
#include "components/viz/common/quads/compositor_render_pass.h"
#include "components/viz/common/quads/texture_draw_quad.h"
#include "components/viz/common/quads/video_hole_draw_quad.h"
#include "components/viz/common/quads/yuv_video_draw_quad.h"
#include "components/viz/common/resources/bitmap_allocation.h"
#include "components/viz/common/resources/resource_sizes.h"
#include "gpu/GLES2/gl2extchromium.h"
#include "gpu/command_buffer/client/context_support.h"
#include "gpu/command_buffer/client/shared_image_interface.h"
#include "gpu/command_buffer/common/shared_image_trace_utils.h"
#include "gpu/command_buffer/common/shared_image_usage.h"
#include "media/base/format_utils.h"
#include "media/base/video_frame.h"
#include "media/base/audio_parameters.h"
#include "media/base/audio_codecs.h"
#include "media/base/video_codecs.h"
#include "media/base/pipeline_status.h"
#include "media/base/video_frame_pool.h"
#include "media/base/status.h"
#include "media/base/video_frame_layout.h"
#include "media/capture/video/video_capture_device_descriptor.h"
#include "media/renderers/paint_canvas_video_renderer.h"
#include "media/video/half_float_maker.h"
#include "media/renderers/video_frame_yuv_mailboxes_holder.h"
#include "media/base/wait_and_replace_sync_token_client.h"
#include "third_party/khronos/GLES2/gl2.h"
#include "third_party/khronos/GLES2/gl2ext.h"
#include "third_party/khronos/GLES3/gl3.h"
#include "third_party/libyuv/include/libyuv.h"
#include "third_party/skia/include/core/SkCanvas.h"
#include "ui/gfx/geometry/size_conversions.h"
#include "ui/gfx/geometry/skia_conversions.h"
#include "ui/gfx/video_types.h"
#include "ui/gl/gl_enums.h"
#include "ui/gl/trace_util.h"
#include "third_party/inspector_protocol/crdtp/status.h"
#include <windows.h>

namespace media {

// static
// void PaintCanvasVideoRenderer::ConvertVideoFrameToRGBPixels(
//     const VideoFrame* video_frame,
//     void* rgb_pixels,
//     size_t row_bytes,
//     bool premultiply_alpha,
//     FilterMode filter,
//     bool disable_threading) {
//     if (!video_frame->IsMappable()) {
//         NOTREACHED_IN_MIGRATION()
//             << "Cannot extract pixels from non-CPU frame formats.";
//         return;
//     }
//
//     scoped_refptr<VideoFrame> temporary_frame;
//     // TODO(thomasanderson): Parallelize converting these formats.
//     switch (video_frame->format()) {
//     case PIXEL_FORMAT_YUV420P9:
//     case PIXEL_FORMAT_YUV422P9:
//     case PIXEL_FORMAT_YUV444P9:
//     case PIXEL_FORMAT_YUV422P12:
//     case PIXEL_FORMAT_YUV444P12:
//         temporary_frame = DownShiftHighbitVideoFrame(video_frame);
//         video_frame = temporary_frame.get();
//         break;
//     case PIXEL_FORMAT_YUV420P10:
//     case PIXEL_FORMAT_YUV420P12:
//         // In AV1, a monochrome (grayscale) frame is represented as a YUV 4:2:0
//         // frame with no U and V planes. Since there are no 10-bit and 12-bit
//         // versions of libyuv::I400ToARGBMatrix(), convert the frame to an 8-bit
//         // YUV 4:2:0 frame with U and V planes.
//         if (!video_frame->data(VideoFrame::Plane::kU) &&
//             !video_frame->data(VideoFrame::Plane::kV)) {
//             temporary_frame = DownShiftHighbitVideoFrame(video_frame);
//             video_frame = temporary_frame.get();
//         }
//         break;
//     case PIXEL_FORMAT_Y16:
//         // Since it is grayscale conversion, we disregard
//         // SK_PMCOLOR_BYTE_ORDER and always use GL_RGBA.
//         FlipAndConvertY16(video_frame, static_cast<uint8_t*>(rgb_pixels), GL_RGBA, GL_UNSIGNED_BYTE, false /*flip_y*/, row_bytes);
//         return;
//     default:
//         break;
//     }
//
//     const size_t n_tasks = disable_threading ? 1 : NumConvertVideoFrameToRGBPixelsTasks(video_frame);
//     base::WaitableEvent event;
//     base::RepeatingClosure barrier = base::BarrierClosure(
//         n_tasks,
//         base::BindOnce(&base::WaitableEvent::Signal, base::Unretained(&event)));
//
//     const libyuv::FilterMode libyuv_filter = ToLibyuvFilterMode(filter);
//     for (size_t i = 1; i < n_tasks; ++i) {
//         base::ThreadPool::PostTask(
//             FROM_HERE,
//             base::BindOnce(ConvertVideoFrameToRGBPixelsTask,
//                 base::Unretained(video_frame), rgb_pixels, row_bytes,
//                 premultiply_alpha, libyuv_filter, i, n_tasks, &barrier));
//     }
//     ConvertVideoFrameToRGBPixelsTask(video_frame, rgb_pixels, row_bytes, premultiply_alpha, libyuv_filter, 0, n_tasks, &barrier);
//     {
//         base::ScopedAllowBaseSyncPrimitivesOutsideBlockingScope allow_wait;
//         event.Wait();
//     }
// }

void VideoResourceUpdater::AppendQuads(viz::CompositorRenderPass*, scoped_refptr<VideoFrame>, gfx::Transform, gfx::Rect, gfx::Rect, gfx::MaskFilterInfo const&,
    absl::optional<gfx::Rect>, bool, float, int)
{
    *(int*)1 = 1;
}
void VideoResourceUpdater::ObtainFrameResources(scoped_refptr<VideoFrame>)
{
    *(int*)1 = 1;
}
void VideoResourceUpdater::ReleaseFrameResources(void)
{
    *(int*)1 = 1;
}

// scoped_refptr<VideoFrame> CreateFromSkImage(sk_sp<SkImage>, gfx::Rect const&, gfx::Size const&, base::TimeDelta, bool)
// {
//     *(int*)1 = 1;
//     return nullptr;
// }

std::string GetCodecName(AudioCodec)
{
    *(int*)1 = 1;
    return "";
}

std::string GetCodecName(VideoCodec)
{
    *(int*)1 = 1;
    return "";
}

// VideoPixelFormat VideoPixelFormatFromSkColorType(SkColorType, bool)
// {
//     *(int*)1 = 1;
//     return PIXEL_FORMAT_UNKNOWN;
// }

AudioParameters::AudioParameters(AudioParameters const&)
{
    *(int*)1 = 1;
}

AudioParameters::AudioParameters(AudioParameters::Format, ChannelLayoutConfig, int, int)
{
    *(int*)1 = 1;
}
AudioParameters::~AudioParameters(void)
{
    *(int*)1 = 1;
}
ChannelLayoutConfig::ChannelLayoutConfig(ChannelLayoutConfig const&)
{
    *(int*)1 = 1;
}

PipelineStatistics::PipelineStatistics(void)
{
    *(int*)1 = 1;
}

PipelineStatistics::~PipelineStatistics(void)
{
    *(int*)1 = 1;
}

class VideoFramePool::PoolImpl : public base::RefCountedThreadSafe<VideoFramePool::PoolImpl> {
public:
    PoolImpl()
    {
    }
    PoolImpl(const PoolImpl&) = delete;
    PoolImpl& operator=(const PoolImpl&) = delete;

    void Shutdown()
    {
    }

private:
    friend class base::RefCountedThreadSafe<VideoFramePool::PoolImpl>;
    ~PoolImpl()
    {
    }
};

class VideoResourceUpdater::PlaneResource {
public:
    PlaneResource(uint32_t plane_resource_id, const gfx::Size& resource_size, viz::ResourceFormat resource_format, bool is_software)
    {
    }

    PlaneResource(const PlaneResource&) = delete;
    PlaneResource& operator=(const PlaneResource&) = delete;

    virtual ~PlaneResource() = default;

private:
};

VideoFramePool::VideoFramePool(void)
{
    *(int*)1 = 1;
}

VideoFramePool::~VideoFramePool(void)
{
    *(int*)1 = 1;
}

AudioParameters& AudioParameters::operator=(AudioParameters const& other)
{
    *(int*)1 = 1;
    AudioParameters* ptr = new AudioParameters();
    return *ptr;
}

//media::AudioParameters blink::MediaStreamAudioTrack::GetOutputFormat(void)const

// PaintCanvasVideoRenderer::~PaintCanvasVideoRenderer(void)
// {
//     *(int*)1 = 1;
// }

class VideoTextureBacking : public cc::TextureBacking {
public:
    explicit VideoTextureBacking()
    {
    }

    ~VideoTextureBacking() override
    {
    }

    const SkImageInfo& GetSkImageInfo() override
    {
        return SkImageInfo();
    }
    gpu::Mailbox GetMailbox() const override
    {
        return gpu::Mailbox();
    }
    sk_sp<SkImage> GetAcceleratedSkImage() override
    {
        return nullptr;
    }

    sk_sp<SkImage> GetSkImageViaReadback() override
    {
        return nullptr;
    }

    bool readPixels(const SkImageInfo& dst_info, void* dst_pixels, size_t dst_row_bytes, int src_x, int src_y) override
    {
        return true;
    }

    void FlushPendingSkiaOps() override
    {
    }
};

VideoFrameYUVConverter::~VideoFrameYUVConverter(void)
{
    *(int*)1 = 1;
}

// PaintCanvasVideoRenderer::Cache::~Cache(void)
// {
//     *(int*)1 = 1;
// }
//
// PaintCanvasVideoRenderer::YUVTextureCache::~YUVTextureCache(void)
// {
//     *(int*)1 = 1;
// }

AudioParameters::AudioParameters(void)
{
    *(int*)1 = 1;
}
ChannelLayoutConfig::ChannelLayoutConfig(void)
{
    *(int*)1 = 1;
}
ChannelLayoutConfig::~ChannelLayoutConfig(void)
{
    *(int*)1 = 1;
}

VideoResourceUpdater::VideoResourceUpdater(viz::ContextProvider* context_provider, viz::RasterContextProvider* raster_context_provider,
    viz::SharedBitmapReporter* shared_bitmap_reporter, viz::ClientResourceProvider* resource_provider, bool use_stream_video_draw_quad,
    bool use_gpu_memory_buffer_resources, bool use_r16_texture, int max_resource_size)
    : context_provider_(context_provider)
    , raster_context_provider_(raster_context_provider)
    , shared_bitmap_reporter_(shared_bitmap_reporter)
    , resource_provider_(resource_provider)
    , use_stream_video_draw_quad_(use_stream_video_draw_quad)
    , use_gpu_memory_buffer_resources_(use_gpu_memory_buffer_resources)
    , use_r16_texture_(use_r16_texture)
    , max_resource_size_(max_resource_size)
    , tracing_id_(-1)
{
    *(int*)1 = 1;
}

VideoResourceUpdater::~VideoResourceUpdater(void)
{
    *(int*)1 = 1;
}

bool VideoResourceUpdater::OnMemoryDump(struct base::trace_event::MemoryDumpArgs const&, class base::trace_event::ProcessMemoryDump*)
{
    *(int*)1 = 1;
    return false;
}

// internal::StatusData::~StatusData(void)
// {
//     *(int*)1 = 1;
// }

bool AudioParameters::IsValid(void) const
{
    *(int*)1 = 1;
    return false;
}

// gfx::ColorSpace VideoFrame::ColorSpace(void)const
// {
//     *(int*)1 = 1;
//     return gfx::ColorSpace();
// }

scoped_refptr<VideoFrame> VideoFramePool::CreateFrame(VideoPixelFormat, gfx::Size const&, gfx::Rect const&, gfx::Size const&, base::TimeDelta)
{
    *(int*)1 = 1;
    return nullptr;
}

std::string VideoCaptureDeviceDescriptor::GetNameAndModel(void) const
{
    *(int*)1 = 1;
    return "";
}

// std::unique_ptr<media::internal::StatusData> internal::StatusData::copy(void) const
// {
//     *(int*)1 = 1;
//     return nullptr;
// }

// uint8_t* VideoFrame::GetWritableVisibleData(size_t)
// {
//     *(int*)1 = 1;
//     return nullptr;
// }
//
// size_t VideoFrame::NumTextures() const
// {
//     *(int*)1 = 1;
//     return 0;
// }
//
// bool VideoFrame::IsValidPlane(VideoPixelFormat, size_t)
// {
//     *(int*)1 = 1;
//     return false;
// }
//
// bool VideoFrame::IsValidSize(gfx::Size const&, gfx::Rect const&, gfx::Size const&)
// {
//     *(int*)1 = 1;
//     return false;
// }

media::VideoFrameYUVMailboxesHolder::~VideoFrameYUVMailboxesHolder(void)
{
    *(int*)1 = 1;
}

// gpu::MailboxHolder const& VideoFrame::mailbox_holder(size_t) const
// {
//     *(int*)1 = 1;
//     return gpu::MailboxHolder();
// }

AudioParameters AudioParameters::UnavailableDeviceParams(void)
{
    *(int*)1 = 1;
    return AudioParameters();
}

// static
// bool VideoFrame::IsValidConfigInternal(VideoPixelFormat format,
//     FrameControlType frame_control_type,
//     const gfx::Size& coded_size,
//     const gfx::Rect& visible_rect,
//     const gfx::Size& natural_size)
// {
//     // Check maximum limits for all formats.
//     if (!IsValidSize(coded_size, visible_rect, natural_size)) {
//         return false;
//     }
//
//     switch (frame_control_type) {
//     case FrameControlType::kNone:
//         // Check that software-allocated buffer formats are not empty.
//         return !coded_size.IsEmpty() && !visible_rect.IsEmpty() && !natural_size.IsEmpty();
//     case FrameControlType::kEos:
//         DCHECK_EQ(format, PIXEL_FORMAT_UNKNOWN);
//         return coded_size.IsEmpty() && visible_rect.IsEmpty() && natural_size.IsEmpty();
//     case FrameControlType::kVideoHole:
//         DCHECK_EQ(format, PIXEL_FORMAT_UNKNOWN);
//         return !coded_size.IsEmpty() && !visible_rect.IsEmpty() && !natural_size.IsEmpty();
//     }
// }
//
// bool VideoFrame::IsValidConfig(VideoPixelFormat format,
//     StorageType storage_type,
//     const gfx::Size& coded_size,
//     const gfx::Rect& visible_rect,
//     const gfx::Size& natural_size)
// {
//     return IsValidConfigInternal(format, FrameControlType::kNone, coded_size, visible_rect, natural_size);
// }
//
// scoped_refptr<VideoFrame> VideoFrame::WrapExternalYuvDataWithLayout(
//     const VideoFrameLayout& layout,
//     const gfx::Rect& visible_rect,
//     const gfx::Size& natural_size,
//     uint8_t* y_data,
//     uint8_t* u_data,
//     uint8_t* v_data,
//     base::TimeDelta timestamp)
// {
//     const StorageType storage = STORAGE_UNOWNED_MEMORY;
//     const VideoPixelFormat format = layout.format();
//     if (!IsValidConfig(format, storage, layout.coded_size(), visible_rect,
//         natural_size)) {
//         DLOG(ERROR) << __func__ << " Invalid config." << ConfigToString(format, storage, layout.coded_size(), visible_rect, natural_size);
//         return nullptr;
//     }
//     if (!IsYuvPlanar(format)) {
//         DLOG(ERROR) << __func__ << " Format is not YUV. " << format;
//         return nullptr;
//     }
//
//     DCHECK_LE(NumPlanes(format), 3u);
//     scoped_refptr<VideoFrame> frame(new VideoFrame(layout, storage, visible_rect, natural_size, timestamp));
//     frame->data_[kYPlane] = y_data;
//     frame->data_[kUPlane] = u_data;
//     frame->data_[kVPlane] = v_data;
//     return frame;
// }
//
// absl::optional<VideoFrameLayout> VideoFrameLayout::CreateWithPlanes(
//     VideoPixelFormat format,
//     const gfx::Size& coded_size,
//     std::vector<ColorPlaneLayout> planes,
//     size_t buffer_addr_align,
//     uint64_t modifier)
// {
//     // NOTE: Even if format is UNKNOWN, it is valid if coded_sizes is not Empty().
//     // TODO(crbug.com/41421131): Return std::nullopt,
//     // if (format != PIXEL_FORMAT_UNKNOWN || !coded_sizes.IsEmpty())
//     // TODO(crbug.com/41421131): Return std::nullopt,
//     // if (planes.size() != NumPlanes(format))
//     return VideoFrameLayout(format, coded_size, std::move(planes), false /*is_multi_planar */, buffer_addr_align, modifier);
// }
//
// std::vector<ColorPlaneLayout> PlanesFromStrides(const std::vector<int32_t> strides)
// {
//     std::vector<ColorPlaneLayout> planes(strides.size());
//     for (size_t i = 0; i < strides.size(); i++) {
//         planes[i].stride = strides[i];
//     }
//     return planes;
// }
//
// absl::optional<VideoFrameLayout> VideoFrameLayout::CreateWithStrides(
//     VideoPixelFormat format,
//     const gfx::Size& coded_size,
//     std::vector<int32_t> strides,
//     size_t buffer_addr_align,
//     uint64_t modifier)
// {
//     return CreateWithPlanes(format, coded_size, PlanesFromStrides(strides), buffer_addr_align, modifier);
// }
//
// scoped_refptr<VideoFrame> VideoFrame::WrapExternalYuvaData(
//     VideoPixelFormat format, const gfx::Size& coded_size, const gfx::Rect& visible_rect, const gfx::Size& natural_size,
//     int32_t y_stride, int32_t u_stride, int32_t v_stride, int32_t a_stride, uint8_t* y_data, uint8_t* u_data, uint8_t* v_data, uint8_t* a_data, base::TimeDelta timestamp)
// {
//     absl::optional<VideoFrameLayout> layout = VideoFrameLayout::CreateWithStrides(format, coded_size, { y_stride, u_stride, v_stride });
//     if (!layout) {
//         DLOG(ERROR) << "Invalid layout.";
//         return nullptr;
//     }
//
//     return WrapExternalYuvDataWithLayout(*layout, visible_rect, natural_size, y_data, u_data, v_data, timestamp);
// }

VideoFrameYUVConverter::VideoFrameYUVConverter()
{
    DebugBreak();
}

WaitAndReplaceSyncTokenClient::WaitAndReplaceSyncTokenClient(gpu::InterfaceBase*)
{
    DebugBreak();
}

void WaitAndReplaceSyncTokenClient::WaitSyncToken(gpu::SyncToken const&)
{
    DebugBreak();
}

void WaitAndReplaceSyncTokenClient::GenerateSyncToken(gpu::SyncToken*)
{
    DebugBreak();
}

// internal::StatusData::StatusData(base::BasicStringPiece<char, struct std::char_traits<char>>, unsigned short, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, unsigned __int64)	maindll	W : \mycode\mb108\build\maindll\lld - link	1

// DataBuffer::DataBuffer(int)
// {
//
// }

// void internal::StatusData::AddLocation(base::Location const&)
// {
//     DebugBreak();
// }

void VideoFrameYUVConverter::ReleaseCachedData(void)
{
    DebugBreak();
}

bool VideoFrameYUVConverter::IsVideoFrameFormatSupported(VideoFrame const&)
{
    DebugBreak();
    return false;
}
bool VideoFrameYUVConverter::ConvertYUVVideoFrameNoCaching(
    VideoFrame const*, viz::RasterContextProvider*, gpu::MailboxHolder const&, absl::optional<struct media::VideoFrameYUVConverter::GrParams>)
{
    DebugBreak();
    return false;
}

bool VideoFrameYUVConverter::ConvertYUVVideoFrame(
    VideoFrame const*, viz::RasterContextProvider*, gpu::MailboxHolder const&, absl::optional<VideoFrameYUVConverter::GrParams>)
{
    DebugBreak();
    return false;
}

}

// std::string crdtp::Status::Message(void) const
// {
//     DebugBreak();
//     return "";
// }
//
// std::string crdtp::Status::ToASCIIString(void) const
// {
//     DebugBreak();
//     return "";
// }
