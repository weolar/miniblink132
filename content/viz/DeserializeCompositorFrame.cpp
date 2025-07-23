
#include "content/viz/SerializeCF.h"

#include "base/pickle.h"
#include "ui/gfx/geometry/point_f.h"
#include "ui/gfx/geometry/size_f.h"
#include "ui/latency/latency_info.h"
#include "cc/paint/display_item_list.h"
#include "cc/paint/paint_op_buffer_serializer.h"
#include "components/viz/common/quads/compositor_frame.h"
#include "components/viz/common/quads/picture_draw_quad.h"
#include "components/viz/common/quads/solid_color_draw_quad.h"
#include <windows.h>

namespace ui {

class LatencyInfo;
enum LatencyComponentType;

struct LatencyInfoTest {
    static void deserializeUiLatencyInfo(LatencyInfo* out, base::PickleIterator& pickleIn)
    {
        DebugBreak();
//         uint32_t componentsSize = 0;
//         CHECK(pickleIn.ReadUInt32(&componentsSize));
//         for (size_t i = 0; i < componentsSize; ++i) {
//             LatencyComponentType type;
//             int64_t time;
// 
//             CHECK(pickleIn.ReadInt((int*)&type));
//             CHECK(pickleIn.ReadInt64(&time));
//             out->latency_components_.insert_or_assign(type, base::TimeTicks::FromInternalValue(time));
//         }
// 
//         CHECK(pickleIn.ReadInt64(&out->trace_id_));
//         CHECK(pickleIn.ReadInt64(&out->ukm_source_id_));
//         CHECK(pickleIn.ReadBool(&out->coalesced_));
//         CHECK(pickleIn.ReadBool(&out->began_));
//         CHECK(pickleIn.ReadBool(&out->terminated_));
//         int val = 0;
//         CHECK(pickleIn.ReadInt((int*)(&val)));
//         out->source_event_type_ = (ui::SourceEventType)val;
//         CHECK(pickleIn.ReadInt64(&out->gesture_scroll_id_));
//         CHECK(pickleIn.ReadInt64(&out->touch_trace_id_));
    }
};
}

namespace rbi {

bool checkDebugFlag(base::PickleIterator& pickleIn)
{
    uint32_t debugFlag = 0;
    CHECK(pickleIn.ReadUInt32(&debugFlag));
    CHECK(debugFlag == kDebugFlag);
    return debugFlag == kDebugFlag;
}

void deserializeGfxPointF(gfx::PointF* out, base::PickleIterator& pickleIn)
{
    float x;
    float y;
    CHECK(pickleIn.ReadFloat(&x));
    CHECK(pickleIn.ReadFloat(&y));
    out->set_x(x);
    out->set_y(y);
}

void deserializeGfxSizeF(gfx::SizeF* out, base::PickleIterator& pickleIn)
{
    float width;
    float height;
    CHECK(pickleIn.ReadFloat(&width));
    CHECK(pickleIn.ReadFloat(&height));
    out->set_width(width);
    out->set_height(height);
}

void deserializeGfxRectF(gfx::RectF* out, base::PickleIterator& pickleIn)
{
    float x;
    float y;
    float width;
    float height;

    CHECK(pickleIn.ReadFloat(&x));
    CHECK(pickleIn.ReadFloat(&y));
    CHECK(pickleIn.ReadFloat(&width));
    CHECK(pickleIn.ReadFloat(&height));
    out->SetRect(x, y, width, height);
}

void deserializeGfxRect(gfx::Rect* out, base::PickleIterator& pickleIn)
{
    int x;
    int y;
    int width;
    int height;

    CHECK(pickleIn.ReadInt(&x));
    CHECK(pickleIn.ReadInt(&y));
    CHECK(pickleIn.ReadInt(&width));
    CHECK(pickleIn.ReadInt(&height));
    out->SetRect(x, y, width, height);
}

void deserializeGfxSize(gfx::Size* out, base::PickleIterator& pickleIn)
{
    int width;
    int height;
    CHECK(pickleIn.ReadInt(&width));
    CHECK(pickleIn.ReadInt(&height));
    out->set_width(width);
    out->set_height(height);
}

void deserializeGfxTransform(gfx::Transform* out, base::PickleIterator& pickleIn)
{
    SkScalar r0c0, r0c1, r0c2, r0c3, r1c0, r1c1, r1c2, r1c3, r2c0, r2c1, r2c2, r2c3, r3c0, r3c1, r3c2, r3c3;

    CHECK(pickleIn.ReadFloat(&r0c0));
    CHECK(pickleIn.ReadFloat(&r0c1));
    CHECK(pickleIn.ReadFloat(&r0c2));
    CHECK(pickleIn.ReadFloat(&r0c3));
    CHECK(pickleIn.ReadFloat(&r1c0));
    CHECK(pickleIn.ReadFloat(&r1c1));
    CHECK(pickleIn.ReadFloat(&r1c2));
    CHECK(pickleIn.ReadFloat(&r1c3));
    CHECK(pickleIn.ReadFloat(&r2c0));
    CHECK(pickleIn.ReadFloat(&r2c1));
    CHECK(pickleIn.ReadFloat(&r2c2));
    CHECK(pickleIn.ReadFloat(&r2c3));
    CHECK(pickleIn.ReadFloat(&r3c0));
    CHECK(pickleIn.ReadFloat(&r3c1));
    CHECK(pickleIn.ReadFloat(&r3c2));
    CHECK(pickleIn.ReadFloat(&r3c3));

    *out = gfx::Transform::RowMajor(r0c0, r0c1, r0c2, r0c3, r1c0, r1c1, r1c2, r1c3, r2c0, r2c1, r2c2, r2c3, r3c0, r3c1, r3c2, r3c3);
}

void deserializeSkColor4f(SkColor4f* out, base::PickleIterator& pickleIn)
{
    float r, g, b, a = 0;
    CHECK(pickleIn.ReadFloat(&r));
    CHECK(pickleIn.ReadFloat(&g));
    CHECK(pickleIn.ReadFloat(&b));
    CHECK(pickleIn.ReadFloat(&a));

    out->fR = r;
    out->fG = g;
    out->fB = b;
    out->fA = a;
}

void deserializeVizFrameSinkId(viz::FrameSinkId* out, base::PickleIterator& pickleIn)
{
    uint32_t client_id;
    uint32_t sink_id;
    CHECK(pickleIn.ReadUInt32(&client_id));
    CHECK(pickleIn.ReadUInt32(&sink_id));
    *out = viz::FrameSinkId(client_id, sink_id);
}

void deserializeBaseUnguessableToken(base::UnguessableToken* out, base::PickleIterator& pickleIn)
{
//     uint64_t high;
//     uint64_t low;
//     CHECK(pickleIn.ReadUInt64(&high));
//     CHECK(pickleIn.ReadUInt64(&low));
// 
//     *out = base::UnguessableToken::Deserialize(high, low);
}

void deserializeVizLocalSurfaceId(viz::LocalSurfaceId* out, base::PickleIterator& pickleIn)
{
    uint32_t parent_sequence_number;
    uint32_t child_sequence_number;

    CHECK(pickleIn.ReadUInt32(&parent_sequence_number));
    CHECK(pickleIn.ReadUInt32(&child_sequence_number));

    base::UnguessableToken embed_token;
    deserializeBaseUnguessableToken(&embed_token, pickleIn);

    *out = viz::LocalSurfaceId(parent_sequence_number, child_sequence_number, embed_token);
}

void deserializeVizSurfaceId(viz::SurfaceId* out, base::PickleIterator& pickleIn)
{
    viz::FrameSinkId fid;
    deserializeVizFrameSinkId(&fid, pickleIn);

    viz::LocalSurfaceId sid;
    deserializeVizLocalSurfaceId(&sid, pickleIn);

    *out = viz::SurfaceId(fid, sid);
}

void deserializeVizSurfaceRange(viz::SurfaceRange* out, base::PickleIterator& pickleIn)
{
    absl::optional<viz::SurfaceId> start;

    bool isStart = false;
    CHECK(pickleIn.ReadBool(&isStart));
    if (isStart) {
        viz::SurfaceId id;
        deserializeVizSurfaceId(&id, pickleIn);

        start.emplace(id);
        DebugBreak();
    }

    viz::SurfaceId end;
    deserializeVizSurfaceId(&end, pickleIn);
    *out = viz::SurfaceRange(start, end);
}

void deserializeVizFrameDeadline(viz::FrameDeadline* out, base::PickleIterator& pickleIn)
{
    int64_t frameStartTime;
    CHECK(pickleIn.ReadInt64(&frameStartTime));

    uint32_t deadlineInFrames;
    CHECK(pickleIn.ReadUInt32(&deadlineInFrames));

    int64_t frameInterval;
    CHECK(pickleIn.ReadInt64(&frameInterval));

    bool useDefaultLowerBoundDeadline = false;
    CHECK(pickleIn.ReadBool(&useDefaultLowerBoundDeadline));

    *out = viz::FrameDeadline(
        base::TimeTicks::FromInternalValue(frameStartTime), deadlineInFrames, base::TimeDelta::FromInternalValue(frameInterval), useDefaultLowerBoundDeadline);
}

void deserializeVizBeginFrameId(viz::BeginFrameId* out, base::PickleIterator& pickleIn)
{
    uint64_t sourceId = 0;
    uint64_t sequenceNumber = 0;
    CHECK(pickleIn.ReadUInt64(&sourceId));
    CHECK(pickleIn.ReadUInt64(&sequenceNumber));

    *out = viz::BeginFrameId(sourceId, sequenceNumber);
}

void deserializeVizBeginFrameAck(viz::BeginFrameAck* out, base::PickleIterator& pickleIn)
{
    viz::BeginFrameId id;
    deserializeVizBeginFrameId(&id, pickleIn);

    int64_t trace_id;
    bool has_damage;
    CHECK(pickleIn.ReadInt64(&trace_id));
    CHECK(pickleIn.ReadBool(&has_damage));

    *out = viz::BeginFrameAck(id.source_id, id.sequence_number, has_damage, trace_id);
}

void deserializeVizSharedImageFormat(viz::SharedImageFormat* in, base::PickleIterator& pickleIn)
{
    const char* data;
    int size = 0;
    CHECK(pickleIn.ReadInt(&size));
    CHECK(size == sizeof(viz::SharedImageFormat));
    CHECK(pickleIn.ReadBytes(&data, sizeof(viz::SharedImageFormat)));
    memcpy(in, data, sizeof(viz::SharedImageFormat));
}

void deserializeGfxColorSpace(gfx::ColorSpace* out, base::PickleIterator& pickleIn)
{
    DebugBreak();

    const char* data;
    int size = 0;
    CHECK(pickleIn.ReadInt(&size));
    CHECK(size == sizeof(gfx::ColorSpace));

    CHECK(pickleIn.ReadBytes(&data, sizeof(gfx::ColorSpace)));
    memcpy(out, data, sizeof(gfx::ColorSpace));
}

void deserializeGpuMailboxHolder(gpu::MailboxHolder* out, base::PickleIterator& pickleIn)
{
    const char* data;
    int size = 0;
    CHECK(pickleIn.ReadInt(&size));
    CHECK(size == sizeof(gpu::MailboxHolder));

    CHECK(pickleIn.ReadBytes(&data, sizeof(gpu::MailboxHolder)));
    memcpy(out, data, sizeof(gpu::MailboxHolder));
}

void deserializeVizTransferableResource(viz::TransferableResource* out, base::PickleIterator& pickleIn)
{
//     int64_t id = 0;
//     CHECK(pickleIn.ReadInt64(&id));
// 
//     bool isSoftware = false;
//     CHECK(pickleIn.ReadBool(&isSoftware));
// 
//     gfx::Size size;
//     deserializeGfxSize(&size, pickleIn);
// 
//     viz::SharedImageFormat format;
//     deserializeVizSharedImageFormat(&format, pickleIn);
// 
//     gpu::MailboxHolder holder;
//     deserializeGpuMailboxHolder(&holder, pickleIn);
// 
//     gfx::ColorSpace colorSpace;
//     deserializeGfxColorSpace(&colorSpace, pickleIn);
// 
//     //     CHECK(!in.color_space_when_sampled.has_value());
//     //     CHECK(!in.hdr_metadata.has_value());
//     //     bool isOverlayCandidate = false;
//     //     pickleIn.ReadBool(&isOverlayCandidate);
//     //
//     //     uint32_t filter = 0;
//     //     pickleIn.ReadUInt32(&filter);
//     //
//     //     uint32_t synchronizationType = 0;
//     //     pickleIn.ReadUInt32(&synchronizationType);
// 
//     *out = viz::TransferableResource::MakeSoftware(holder.mailbox, size, format);
}

void deserializeCompositorFrameMetadata(viz::CompositorFrameMetadata* metadataIn, base::PickleIterator& pickleIn)
{
//     CHECK(pickleIn.ReadFloat(&metadataIn->device_scale_factor));
//     deserializeGfxPointF(&metadataIn->root_scroll_offset, pickleIn);
//     CHECK(pickleIn.ReadFloat(&metadataIn->page_scale_factor));
// 
//     deserializeGfxSizeF(&metadataIn->scrollable_viewport_size, pickleIn);
//     int contentColorUsage = 0;
//     CHECK(pickleIn.ReadInt(&contentColorUsage));
//     metadataIn->content_color_usage = (gfx::ContentColorUsage)contentColorUsage;
//     CHECK(pickleIn.ReadBool(&metadataIn->may_contain_video));
//     CHECK(pickleIn.ReadBool(&metadataIn->may_throttle_if_undrawn_frames));
//     CHECK(pickleIn.ReadBool(&metadataIn->is_resourceless_software_draw_with_scroll_or_animation));
//     deserializeSkColor4f(&metadataIn->root_background_color, pickleIn);
// 
//     //CHECK(metadataIn.latency_info.size() < 0xffff);
//     uint16_t latencyInfoSize = 0;
//     CHECK(pickleIn.ReadUInt16(&latencyInfoSize));
//     for (size_t i = 0; i < latencyInfoSize; ++i) {
//         ui::LatencyInfo info;
//         ui::LatencyInfoTest::deserializeUiLatencyInfo(&info, pickleIn);
// 
//         metadataIn->latency_info.push_back(info);
//     }
// 
//     uint16_t referencedSurfacesSize = 0;
//     CHECK(pickleIn.ReadUInt16(&referencedSurfacesSize));
//     for (size_t i = 0; i < referencedSurfacesSize /*metadataIn.referenced_surfaces.size()*/; ++i) {
//         viz::SurfaceRange range;
//         deserializeVizSurfaceRange(&range, pickleIn);
//         metadataIn->referenced_surfaces.push_back(range);
//     }
// 
//     uint16_t activationDependenciesSize = 0;
//     CHECK(pickleIn.ReadUInt16(&activationDependenciesSize));
//     for (size_t i = 0; i < activationDependenciesSize; ++i) {
//         viz::SurfaceId id;
//         deserializeVizSurfaceId(&id /*metadataIn.activation_dependencies[i]*/, pickleIn);
//         metadataIn->activation_dependencies.push_back(id);
//     }
// 
//     deserializeVizFrameDeadline(&metadataIn->deadline, pickleIn);
//     deserializeVizBeginFrameAck(&metadataIn->begin_frame_ack, pickleIn);
// 
//     CHECK(pickleIn.ReadUInt32(&metadataIn->frame_token));
//     CHECK(pickleIn.ReadBool(&metadataIn->send_frame_token_to_embedder));
//     CHECK(pickleIn.ReadFloat(&metadataIn->min_page_scale_factor));
// 
//     checkDebugFlag(pickleIn);
    // 剩下的先不管了
}

void deserializeCcFilterOperation(cc::FilterOperation* out, base::PickleIterator& pickleIn)
{
    DebugBreak();
}

void deserializeCcFilterOperations(cc::FilterOperations* out, base::PickleIterator& pickleIn)
{
    //DebugBreak();
}

void deserializeGfxRRectF(gfx::RRectF* out, base::PickleIterator& pickleIn)
{
    const char* data;
    int size = 0;
    CHECK(pickleIn.ReadInt(&size));
    CHECK(size == SkRRect::kSizeInMemory);

    CHECK(pickleIn.ReadBytes(&data, SkRRect::kSizeInMemory));
    memcpy(out, data, SkRRect::kSizeInMemory);

    SkRRect rr;
    rr.readFromMemory(data, SkRRect::kSizeInMemory);
    *out = gfx::RRectF(rr);
}

void deserializeGfxLinearGradient(gfx::LinearGradient* out, base::PickleIterator& pickleIn)
{
    uint16_t angle = 0;
    CHECK(pickleIn.ReadUInt16(&angle));
    out->set_angle(angle);

    //CHECK(in.steps().size() < 0xffff);
    uint16_t stepSize = 0;
    CHECK(pickleIn.ReadUInt16(&stepSize));
    for (size_t i = 0; i < stepSize; ++i) {
        gfx::LinearGradient::Step step;
        float fraction;
        uint16_t alpha;

        CHECK(pickleIn.ReadFloat(&fraction));
        CHECK(pickleIn.ReadUInt16(&alpha));

        step.fraction = fraction;
        step.alpha = alpha;

        out->steps()[i].fraction = fraction;
        out->steps()[i].alpha = alpha;
    }
}

void deserializeGfxMaskFilterInfo(gfx::MaskFilterInfo* out, base::PickleIterator& pickleIn)
{
    gfx::RRectF rrect;
    deserializeGfxRRectF(&rrect, pickleIn);

    bool hasGradientMask = false;
    CHECK(pickleIn.ReadBool(&hasGradientMask));
    gfx::LinearGradient gradient;
    if (hasGradientMask) {
        deserializeGfxLinearGradient(&gradient, pickleIn);
        *out = gfx::MaskFilterInfo(rrect, gradient);
    } else {
        *out = gfx::MaskFilterInfo(rrect);
    }
}

void deserializeVizSharedQuadState(viz::SharedQuadState* out, base::PickleIterator& pickleIn)
{
    deserializeGfxTransform(&out->quad_to_target_transform, pickleIn);
    deserializeGfxRect(&out->quad_layer_rect, pickleIn);
    deserializeGfxRect(&out->visible_quad_layer_rect, pickleIn);
    deserializeGfxMaskFilterInfo(&out->mask_filter_info, pickleIn);
    bool hasClipRect = false;
    CHECK(pickleIn.ReadBool(&hasClipRect));
    if (hasClipRect) {
        gfx::Rect r;
        deserializeGfxRect(&r, pickleIn);
        out->clip_rect.emplace(r);
    }
    CHECK(pickleIn.ReadBool(&out->are_contents_opaque));
    CHECK(pickleIn.ReadFloat(&out->opacity));
    uint32_t blendMode = 0;
    CHECK(pickleIn.ReadUInt32(&blendMode));
    out->blend_mode = (SkBlendMode)blendMode;
    CHECK(pickleIn.ReadInt(&out->sorting_context_id));
    CHECK(pickleIn.ReadBool(&out->is_fast_rounded_corner));

    checkDebugFlag(pickleIn);
}

void deserializeVizDrawQuadResources(viz::DrawQuad::Resources* out, base::PickleIterator& pickleIn)
{
    const char* data;
    int size = 0;
    CHECK(pickleIn.ReadInt(&size));
    CHECK(size == sizeof(viz::DrawQuad::Resources));

    CHECK(pickleIn.ReadBytes(&data, sizeof(viz::DrawQuad::Resources)));
    memcpy(out, data, sizeof(viz::DrawQuad::Resources));
}

} // rbi

namespace cc {

static size_t calcPadding(const void* ptr)
{
    uintptr_t memory = (uintptr_t)ptr;
    size_t padding = base::bits::AlignUp(memory, (size_t)8) - memory; // SimpleBufferSerializer貌似需要8字节对齐
    return padding;
}

void DisplayItemListTest::deserializeCcDisplayItemList(::cc::DisplayItemList* out, base::PickleIterator& pickleIn)
{
// #if 1
//     const char* rtreeHeadData = nullptr;
//     size_t length = 0;
//     CHECK(pickleIn.ReadData(&rtreeHeadData, &length));
//     ::cc::RTreeSize::FlatHead* rtreeHead = (::cc::RTreeSize::FlatHead*)rtreeHeadData;
//     CHECK(rtreeHead->size == length);
//     //out->rtree_.Deserialize(rtreeHead); // weolar
// #endif
// 
//     size_t strikeSize = 0;
//     const char* strikeData = nullptr;
//     //CHECK(pickleIn.ReadData(&strikeData, &strikeSize));
// 
//     SkStrikeClient* strikeClient = nullptr;
//     if (strikeSize > 0) {
//         strikeClient = new SkStrikeClient(sk_sp(new TestDiscardableManager())); // 内存泄露
//         strikeClient->readStrikeData(strikeData, strikeSize);
//     }
// 
//     size_t paintOpDataSize = 0;
//     const char* paintOpData = nullptr;
//     CHECK(pickleIn.ReadData(&paintOpData, &paintOpDataSize));
// 
//     size_t padding = calcPadding(paintOpData);
// 
//     const char* newPaintOpData = paintOpData;
//     std::vector<char> buf;
//     if (padding > 0) {
//         CHECK(padding < 16);
//         buf.resize(paintOpDataSize + 16);
// 
//         char* newData = buf.data();
//         padding = calcPadding(newData);
//         CHECK(padding < 16);
// 
//         newPaintOpData = newData + padding;
//         memcpy((void*)(newPaintOpData), paintOpData, paintOpDataSize);
//     }
// 
//     if (paintOpDataSize > 0) {
//         std::vector<uint8_t> scratchBuffer;
//         ::cc::PaintOp::DeserializeOptions options(nullptr, nullptr, strikeClient, &scratchBuffer, false, nullptr);
//         out->paint_op_buffer_.Deserialize(newPaintOpData, paintOpDataSize, options);
//     }
}

}

namespace rbi {

void deserializeContentDrawQuadBase(viz::ContentDrawQuadBase* out, base::PickleIterator& pickleIn)
{
    deserializeGfxRectF(&out->tex_coord_rect, pickleIn);
    deserializeGfxSize(&out->texture_size, pickleIn);
    CHECK(pickleIn.ReadBool(&out->is_premultiplied));
    CHECK(pickleIn.ReadBool(&out->nearest_neighbor));
    CHECK(pickleIn.ReadBool(&out->force_anti_aliasing_off));
    checkDebugFlag(pickleIn);
}

void deserializeVizPictureDrawQuad(viz::PictureDrawQuad* out, base::PickleIterator& pickleIn)
{
//     deserializeContentDrawQuadBase(out, pickleIn);
//     deserializeGfxRect(&out->content_rect, pickleIn);
//     CHECK(pickleIn.ReadFloat(&out->contents_scale));
// 
//     //CHECK(in.image_animation_map.size() < 0xffff);
//     uint16_t imageAnimationMapSize = 0;
//     CHECK(pickleIn.ReadUInt16(&imageAnimationMapSize));
//     for (size_t i = 0; i < imageAnimationMapSize; ++i) {
//         cc::PaintImage::Id id;
//         uint32_t size;
//         CHECK(pickleIn.ReadInt(&id));
//         CHECK(pickleIn.ReadUInt32(&size));
// 
//         out->image_animation_map.insert_or_assign(id, size);
//     }
// 
//     out->display_item_list = base::MakeRefCounted<cc::DisplayItemList>();
//     cc::DisplayItemListTest::deserializeCcDisplayItemList(out->display_item_list.get(), pickleIn);
//     uint16_t format = 0;
//     CHECK(pickleIn.ReadUInt16(&format));
//     out->texture_format = (viz::ResourceFormat)format;
}

const viz::SharedQuadState* findQuadStatePtr(const viz::SharedQuadStateList& stateList, int pos)
{
    int i = 0;
    for (viz::SharedQuadStateList::ConstIterator it = stateList.begin(); it != stateList.end(); ++it, ++i) {
        const viz::SharedQuadState* quadState = *it;
        if (i == pos)
            return quadState;
    }
    DebugBreak();
    return nullptr;
}

void deserializeVizQuadListPre(viz::QuadList* out, const viz::SharedQuadStateList& sharedQuadStateList, viz::DrawQuad* quad, base::PickleIterator& pickleIn)
{
    gfx::Rect rect;
    gfx::Rect visibleRect;
    deserializeGfxRect(&rect, pickleIn);
    deserializeGfxRect(&visibleRect, pickleIn);
    bool needsBlending = false;
    CHECK(pickleIn.ReadBool(&needsBlending));

    viz::DrawQuad::Resources res;
    deserializeVizDrawQuadResources(&res, pickleIn);
    checkDebugFlag(pickleIn);

    uint16_t pos = 0;
    CHECK(pickleIn.ReadUInt16(&pos));
    const viz::SharedQuadState* state = findQuadStatePtr(sharedQuadStateList, pos);

    quad->rect = rect;
    quad->visible_rect = visibleRect;
    quad->needs_blending = needsBlending;
    quad->shared_quad_state = state;
    quad->resources = res;
}

void deserializeVizQuadList(const viz::SharedQuadStateList& sharedQuadStateList, viz::QuadList* out, base::PickleIterator& pickleIn)
{
    //CHECK(in.size() < 0xffff);
//     uint16_t size = 0;
//     CHECK(pickleIn.ReadUInt16(&size));
// 
//     for (size_t i = 0; i < size; ++i) {
//         uint16_t material;
//         CHECK(pickleIn.ReadUInt16(&material));
// 
//         switch ((viz::DrawQuad::Material)material) {
//         case viz::DrawQuad::Material::kDebugBorder:
//             DebugBreak();
//             //quad_list.AllocateAndCopyFrom(DebugBorderDrawQuad::MaterialCast(quad));
//             break;
//         case viz::DrawQuad::Material::kPictureContent: {
//             viz::PictureDrawQuad* quad = out->AllocateAndConstruct<viz::PictureDrawQuad>();
//             quad->material = (viz::DrawQuad::Material)material;
//             deserializeVizQuadListPre(out, sharedQuadStateList, quad, pickleIn);
//             deserializeVizPictureDrawQuad(quad, pickleIn);
//         } break;
//         case viz::DrawQuad::Material::kTextureContent:
//             //quad_list.AllocateAndCopyFrom(TextureDrawQuad::MaterialCast(quad));
//             DebugBreak();
//             break;
//         case viz::DrawQuad::Material::kSolidColor: {
//             viz::SolidColorDrawQuad* quad = out->AllocateAndConstruct<viz::SolidColorDrawQuad>();
//             quad->material = (viz::DrawQuad::Material)material;
//             deserializeVizQuadListPre(out, sharedQuadStateList, quad, pickleIn);
//             deserializeSkColor4f(&quad->color, pickleIn);
//             CHECK(pickleIn.ReadBool(&quad->force_anti_aliasing_off));
//         } break;
//         case viz::DrawQuad::Material::kTiledContent:
//             DebugBreak();
//             //quad_list.AllocateAndCopyFrom(TileDrawQuad::MaterialCast(quad));
//             break;
//         case viz::DrawQuad::Material::kSurfaceContent:
//             DebugBreak();
//             //quad_list.AllocateAndCopyFrom(SurfaceDrawQuad::MaterialCast(quad));
//             break;
//         case viz::DrawQuad::Material::kVideoHole:
//             DebugBreak();
//             //quad_list.AllocateAndCopyFrom(VideoHoleDrawQuad::MaterialCast(quad));
//             break;
//         case viz::DrawQuad::Material::kYuvVideoContent:
//             DebugBreak();
//             //quad_list.AllocateAndCopyFrom(YUVVideoDrawQuad::MaterialCast(quad));
//             break;
//         case viz::DrawQuad::Material::kSharedElement:
//             DebugBreak();
//             //quad_list.AllocateAndCopyFrom(SharedElementDrawQuad::MaterialCast(quad));
//             break;
//             // RenderPass quads need to use specific CopyFrom function.
//         case viz::DrawQuad::Material::kAggregatedRenderPass:
//         case viz::DrawQuad::Material::kCompositorRenderPass:
//         case viz::DrawQuad::Material::kInvalid:
//             DebugBreak();
//             // TODO(danakj): Why is this a check instead of dcheck, and validate from IPC?
//             CHECK(false); // Invalid DrawQuad material.
//             break;
//         }
//     }
}

void deserializeVizSharedQuadStateList(viz::SharedQuadStateList* out, base::PickleIterator& pickleIn)
{
    uint16_t size = 0;
    CHECK(pickleIn.ReadUInt16(&size));
    for (size_t i = 0; i < size; ++i) {
        viz::SharedQuadState* state = out->AllocateAndConstruct<viz::SharedQuadState>();
        deserializeVizSharedQuadState(state, pickleIn);
    }
}

void deserializeVizCompositorRenderPass(viz::CompositorRenderPass* out, base::PickleIterator& pickleIn)
{
//     uint64_t id = 0;
//     CHECK(pickleIn.ReadUInt64(&id));
//     out->id.FromUnsafeValue(id);
// 
//     uint32_t subtree_id = 0;
//     CHECK(pickleIn.ReadUInt32(&subtree_id));
//     deserializeGfxSize(&out->subtree_size, pickleIn);
//     out->subtree_capture_id = viz::SubtreeCaptureId(subtree_id);
// 
//     uint32_t shared_element_resource_id = 0;
//     CHECK(pickleIn.ReadUInt32(&shared_element_resource_id));
//     out->shared_element_resource_id = viz::SharedElementResourceId(shared_element_resource_id);
// 
//     bool has_per_quad_damage = false;
//     CHECK(pickleIn.ReadBool(&has_per_quad_damage));
//     out->has_per_quad_damage = has_per_quad_damage;
// 
//     deserializeGfxRect(&out->output_rect, pickleIn);
//     deserializeGfxRect(&out->damage_rect, pickleIn);
//     deserializeGfxTransform(&out->transform_to_root_target, pickleIn);
//     deserializeCcFilterOperations(&out->filters, pickleIn);
//     deserializeCcFilterOperations(&out->backdrop_filters, pickleIn);
// 
//     bool backdrop_filter_bounds = false;
//     CHECK(pickleIn.ReadBool(&backdrop_filter_bounds));
//     if (backdrop_filter_bounds) {
//         gfx::RRectF rr;
//         deserializeGfxRRectF(&rr, pickleIn);
//         out->backdrop_filter_bounds.emplace(rr);
//     }
//     CHECK(pickleIn.ReadBool(&out->has_transparent_background));
//     CHECK(pickleIn.ReadBool(&out->cache_render_pass));
//     CHECK(pickleIn.ReadBool(&out->has_damage_from_contributing_content));
//     CHECK(pickleIn.ReadBool(&out->generate_mipmap));
// 
//     //CHECK(in.copy_requests.size() == 0);
//     deserializeVizSharedQuadStateList(&out->shared_quad_state_list, pickleIn);
//     deserializeVizQuadList(out->shared_quad_state_list, &out->quad_list, pickleIn);
//     checkDebugFlag(pickleIn);
}

void deserializeVizCompositorFrame(viz::CompositorFrame* frameIn, base::PickleIterator& pickleIn)
{
    //base::Pickle* pickle = new base::Pickle(sizeof(CompositorFrameHead));
    deserializeCompositorFrameMetadata(&frameIn->metadata, pickleIn);

    uint32_t resourceListSize = 0;
    CHECK(pickleIn.ReadUInt32(&resourceListSize));
    for (size_t i = 0; i < resourceListSize; ++i) {
        viz::TransferableResource res;
        deserializeVizTransferableResource(&res, pickleIn);
        frameIn->resource_list.push_back(res);
    }

    uint32_t renderPassListSize = 0;
    CHECK(pickleIn.ReadUInt32(&renderPassListSize));
    for (size_t i = 0; i < renderPassListSize; ++i) {
        std::unique_ptr<viz::CompositorRenderPass> pass = viz::CompositorRenderPass::Create();
        deserializeVizCompositorRenderPass(pass.get(), pickleIn);
        frameIn->render_pass_list.push_back(std::move(pass));
    }
}

}