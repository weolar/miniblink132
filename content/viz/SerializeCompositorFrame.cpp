
#include "content/viz/SerializeCF.h"

#include "base/pickle.h"
#include "ui/gfx/geometry/point_f.h"
#include "ui/gfx/geometry/size_f.h"
#include "cc/paint/display_item_list.h"
#include "cc/paint/paint_op_buffer_serializer.h"
#include "cc/paint/paint_cache.h"
#include "components/viz/common/quads/compositor_frame.h"
#include "components/viz/common/quads/picture_draw_quad.h"
#include "components/viz/common/quads/solid_color_draw_quad.h"
#include "base/bits.h"
#include <windows.h>

namespace rbi {

// void serializeGfxPointF(const gfx::PointF& pointIn, base::Pickle* pickleOut)
// {
//     pickleOut->WriteFloat(pointIn.x());
//     pickleOut->WriteFloat(pointIn.y());
// }
// 
// void serializeGfxSizeF(const gfx::SizeF& pointIn, base::Pickle* pickleOut)
// {
//     pickleOut->WriteFloat(pointIn.width());
//     pickleOut->WriteFloat(pointIn.height());
// }
// 
// void serializeGfxRect(const gfx::Rect& in, base::Pickle* pickleOut)
// {
//     pickleOut->WriteInt(in.x());
//     pickleOut->WriteInt(in.y());
//     pickleOut->WriteInt(in.width());
//     pickleOut->WriteInt(in.height());
// }
// 
// void serializeGfxRectF(const gfx::RectF& in, base::Pickle* pickleOut)
// {
//     pickleOut->WriteFloat(in.x());
//     pickleOut->WriteFloat(in.y());
//     pickleOut->WriteFloat(in.width());
//     pickleOut->WriteFloat(in.height());
// }
// 
// void serializeGfxSize(const gfx::Size& pointIn, base::Pickle* pickleOut)
// {
//     pickleOut->WriteInt(pointIn.width());
//     pickleOut->WriteInt(pointIn.height());
// }
// 
// void serializeGfxTransform(const gfx::Transform& in, base::Pickle* pickleOut)
// {
//     pickleOut->WriteFloat(in.rc(0, 0));
//     pickleOut->WriteFloat(in.rc(0, 1));
//     pickleOut->WriteFloat(in.rc(0, 2));
//     pickleOut->WriteFloat(in.rc(0, 3));
//     pickleOut->WriteFloat(in.rc(1, 0));
//     pickleOut->WriteFloat(in.rc(1, 1));
//     pickleOut->WriteFloat(in.rc(1, 2));
//     pickleOut->WriteFloat(in.rc(1, 3));
//     pickleOut->WriteFloat(in.rc(2, 0));
//     pickleOut->WriteFloat(in.rc(2, 1));
//     pickleOut->WriteFloat(in.rc(2, 2));
//     pickleOut->WriteFloat(in.rc(2, 3));
//     pickleOut->WriteFloat(in.rc(3, 0));
//     pickleOut->WriteFloat(in.rc(3, 1));
//     pickleOut->WriteFloat(in.rc(3, 2));
//     pickleOut->WriteFloat(in.rc(3, 3));
// }
// 
// void serializeSkColor4f(const SkColor4f& skColor4fIn, base::Pickle* pickleOut)
// {
//     pickleOut->WriteFloat(skColor4fIn.fR);
//     pickleOut->WriteFloat(skColor4fIn.fG);
//     pickleOut->WriteFloat(skColor4fIn.fB);
//     pickleOut->WriteFloat(skColor4fIn.fA);
// }
// 
// void serializeUiLatencyInfo(const ui::LatencyInfo& infoIn, base::Pickle* pickleOut)
// {
//     const ui::LatencyInfo::LatencyMap& components = infoIn.latency_components();
// 
//     pickleOut->WriteUInt32(components.size());
//     for (ui::LatencyInfo::LatencyMap::const_iterator it = components.begin(); it != components.end(); ++it) {
//         ui::LatencyComponentType type = it->first;
//         int64_t time = it->second.ToInternalValue();
// 
//         pickleOut->WriteInt((int)type);
//         pickleOut->WriteInt64(time);
//     }
// 
//     pickleOut->WriteInt64(infoIn.trace_id());
//     pickleOut->WriteInt64(infoIn.ukm_source_id());
//     pickleOut->WriteBool(infoIn.coalesced());
//     pickleOut->WriteBool(infoIn.began());
//     pickleOut->WriteBool(infoIn.terminated());
//     pickleOut->WriteInt((int)(infoIn.source_event_type()));
//     pickleOut->WriteInt64(infoIn.gesture_scroll_id());
//     pickleOut->WriteInt64(infoIn.touch_trace_id());
// }
// 
// void serializeVizFrameSinkId(const viz::FrameSinkId& in, base::Pickle* pickleOut)
// {
//     pickleOut->WriteUInt32(in.client_id());
//     pickleOut->WriteUInt32(in.sink_id());
// }
// 
// void serializeBaseUnguessableToken(const base::UnguessableToken& in, base::Pickle* pickleOut)
// {
//     pickleOut->WriteUInt64(in.GetHighForSerialization());
//     pickleOut->WriteUInt64(in.GetLowForSerialization());
// }
// 
// void serializeVizLocalSurfaceId(const viz::LocalSurfaceId& in, base::Pickle* pickleOut)
// {
//     pickleOut->WriteUInt32(in.parent_sequence_number());
//     pickleOut->WriteUInt32(in.child_sequence_number());
//     serializeBaseUnguessableToken(in.embed_token(), pickleOut);
// }
// 
// void serializeVizSurfaceId(const viz::SurfaceId& in, base::Pickle* pickleOut)
// {
//     serializeVizFrameSinkId(in.frame_sink_id(), pickleOut);
//     serializeVizLocalSurfaceId(in.local_surface_id(), pickleOut);
// }
// 
// void serializeVizSurfaceRange(const viz::SurfaceRange& in, base::Pickle* pickleOut)
// {
//     const absl::optional<viz::SurfaceId>& start = in.start();
//     pickleOut->WriteBool(start.has_value());
//     if (start.has_value())
//         serializeVizSurfaceId(start.value(), pickleOut);
// 
//     serializeVizSurfaceId(in.end(), pickleOut);
// }
// 
// void serializeVizFrameDeadline(const viz::FrameDeadline& in, base::Pickle* pickleOut)
// {
//     pickleOut->WriteInt64(in.frame_start_time().ToInternalValue());
//     pickleOut->WriteUInt32(in.deadline_in_frames());
//     pickleOut->WriteInt64(in.frame_interval().ToInternalValue());
//     pickleOut->WriteBool(in.use_default_lower_bound_deadline());
// }
// 
// void serializeVizBeginFrameId(const viz::BeginFrameId& in, base::Pickle* pickleOut)
// {
//     pickleOut->WriteUInt64(in.source_id);
//     pickleOut->WriteUInt64(in.sequence_number);
// }
// 
// void serializeVizBeginFrameAck(const viz::BeginFrameAck& in, base::Pickle* pickleOut)
// {
//     serializeVizBeginFrameId(in.frame_id, pickleOut);
//     pickleOut->WriteInt64(in.trace_id);
//     pickleOut->WriteBool(in.has_damage);
// }
// 
// void serializeVizSharedImageFormat(const viz::SharedImageFormat& in, base::Pickle* pickleOut)
// {
//     //     pickleOut->WriteUInt16(in.plane_type());
//     //     pickleOut->WriteUInt32((uint32_t)(in.multiplanar_format().resource_format()));
//     pickleOut->WriteData((const char*)&in, sizeof(viz::SharedImageFormat));
// }
// 
// void serializeGfxColorSpace(const gfx::ColorSpace& in, base::Pickle* pickleOut)
// {
//     //     pickleOut->WriteUInt16((uint16_t)in.GetPrimaryID());
//     //     pickleOut->WriteUInt16((uint16_t)in.GetTransferID());
//     //     pickleOut->WriteUInt16((uint16_t)in.GetMatrixID());
//     //     pickleOut->WriteUInt16((uint16_t)in.GetRangeID());
//     //
//     //     pickleOut->Write Bytes((const void*)in.get_custom_primary_matrix_for_test(), sizeof(float) * 9);
//     //     pickleOut->Write Bytes((const void*)in.get_transfer_params_for_test(), sizeof(float) * 7);
// 
//     pickleOut->WriteData((const char*)&in, sizeof(gfx::ColorSpace));
// }
// 
// void serializeGpuMailboxHolder(const gpu::MailboxHolder& in, base::Pickle* pickleOut)
// {
//     pickleOut->WriteData((const char*)&in, sizeof(gpu::MailboxHolder));
// }
// 
// void serializeVizTransferableResource(const viz::TransferableResource& in, base::Pickle* pickleOut)
// {
//     pickleOut->WriteInt64(in.id.value());
//     pickleOut->WriteBool(in.is_software);
//     serializeGfxSize(in.size, pickleOut);
//     serializeVizSharedImageFormat(in.format, pickleOut);
//     //CHECK(!in.mailbox_holder.sync_token.HasData());
//     serializeGpuMailboxHolder(in.mailbox_holder, pickleOut);
//     serializeGfxColorSpace(in.color_space, pickleOut);
// 
//     CHECK(!in.color_space_when_sampled.has_value());
//     CHECK(!in.hdr_metadata.has_value());
// 
//     //     pickleOut->WriteBool(in.is_overlay_candidate);
//     //     pickleOut->WriteUInt32(in.filter);
//     //     pickleOut->WriteUInt32((uint32_t)in.synchronization_type);
// }
// 
// void serializeCompositorFrameMetadata(const viz::CompositorFrameMetadata& metadataIn, base::Pickle* pickleOut)
// {
//     pickleOut->WriteFloat(metadataIn.device_scale_factor);
//     serializeGfxPointF(metadataIn.root_scroll_offset, pickleOut);
//     pickleOut->WriteFloat(metadataIn.page_scale_factor);
//     serializeGfxSizeF(metadataIn.scrollable_viewport_size, pickleOut);
//     pickleOut->WriteInt((int)metadataIn.content_color_usage);
//     pickleOut->WriteBool(metadataIn.may_contain_video);
//     pickleOut->WriteBool(metadataIn.may_throttle_if_undrawn_frames);
//     pickleOut->WriteBool(metadataIn.is_resourceless_software_draw_with_scroll_or_animation);
//     serializeSkColor4f(metadataIn.root_background_color, pickleOut);
// 
//     CHECK(metadataIn.latency_info.size() < 0xffff);
//     pickleOut->WriteUInt16((uint16_t)metadataIn.latency_info.size());
//     for (size_t i = 0; i < metadataIn.latency_info.size(); ++i) {
//         serializeUiLatencyInfo(metadataIn.latency_info[i], pickleOut);
//     }
// 
//     pickleOut->WriteUInt16((uint16_t)metadataIn.referenced_surfaces.size());
//     for (size_t i = 0; i < metadataIn.referenced_surfaces.size(); ++i) {
//         serializeVizSurfaceRange(metadataIn.referenced_surfaces[i], pickleOut);
//     }
// 
//     pickleOut->WriteUInt16((uint16_t)metadataIn.activation_dependencies.size());
//     for (size_t i = 0; i < metadataIn.activation_dependencies.size(); ++i) {
//         serializeVizSurfaceId(metadataIn.activation_dependencies[i], pickleOut);
//     }
// 
//     serializeVizFrameDeadline(metadataIn.deadline, pickleOut);
//     serializeVizBeginFrameAck(metadataIn.begin_frame_ack, pickleOut);
// 
//     pickleOut->WriteUInt32(metadataIn.frame_token);
//     pickleOut->WriteBool(metadataIn.send_frame_token_to_embedder);
//     pickleOut->WriteFloat(metadataIn.min_page_scale_factor);
// 
//     pickleOut->WriteUInt32(kDebugFlag);
//     // 剩下的先不管了
// }
// 
// void serializeCcFilterOperation(const ::cc::FilterOperation& in, base::Pickle* pickleOut)
// {
//     DebugBreak();
// }
// 
// void serializeCcFilterOperations(const ::cc::FilterOperations& in, base::Pickle* pickleOut)
// {
//     if (in.size() != 0)
//         OutputDebugStringA("serializeCcFilterOperation not impl\n");
// 
//     //     pickleOut->WriteUInt32(in.Operations().size());
//     //
//     //     for (size_t i = 0; i < in.Operations().size(); ++i) {
//     //         viz::FilterOperation op = in.Operations()[i];
//     //         serializeCcFilterOperation(op, pickleOut);
//     //     }
// }
// 
// void serializeGfxRRectF(const gfx::RRectF& in, base::Pickle* pickleOut)
// {
//     SkRRect rr = (SkRRect)in;
//     std::vector<char> buf;
//     buf.resize(SkRRect::kSizeInMemory);
//     rr.writeToMemory(buf.data());
//     pickleOut->WriteData((const char*)buf.data(), SkRRect::kSizeInMemory);
// }
// 
// void serializeGfxLinearGradient(const gfx::LinearGradient& in, base::Pickle* pickleOut)
// {
//     CHECK(in.steps().size() == gfx::LinearGradient::kMaxStepSize);
// 
//     pickleOut->WriteUInt16(in.angle());
//     pickleOut->WriteUInt16((uint16_t)in.step_count());
// 
//     for (size_t i = 0; i < in.step_count(); ++i) {
//         const gfx::LinearGradient::Step& step = in.steps()[i];
//         pickleOut->WriteFloat(step.fraction);
//         pickleOut->WriteUInt16(step.alpha);
//     }
// }
// 
// void serializeGfxMaskFilterInfo(const gfx::MaskFilterInfo& in, base::Pickle* pickleOut)
// {
//     serializeGfxRRectF(in.rounded_corner_bounds(), pickleOut);
// 
//     pickleOut->WriteBool(in.gradient_mask().has_value());
//     if (in.gradient_mask().has_value())
//         serializeGfxLinearGradient(in.gradient_mask().value(), pickleOut);
// }
// 
// void serializeVizSharedQuadState(const viz::SharedQuadState& in, base::Pickle* pickleOut)
// {
//     serializeGfxTransform(in.quad_to_target_transform, pickleOut);
//     serializeGfxRect(in.quad_layer_rect, pickleOut);
//     serializeGfxRect(in.visible_quad_layer_rect, pickleOut);
//     serializeGfxMaskFilterInfo(in.mask_filter_info, pickleOut);
//     pickleOut->WriteBool(in.clip_rect.has_value());
//     if (in.clip_rect.has_value())
//         serializeGfxRect(in.clip_rect.value(), pickleOut);
//     pickleOut->WriteBool(in.are_contents_opaque);
//     pickleOut->WriteFloat(in.opacity);
//     pickleOut->WriteUInt32((uint32_t)in.blend_mode);
//     pickleOut->WriteInt(in.sorting_context_id);
//     pickleOut->WriteBool(in.is_fast_rounded_corner);
// 
//     pickleOut->WriteUInt32(kDebugFlag);
// }
// 
// }
// 
// #include "components/viz/common/quads/picture_draw_quad.h"
// 
// namespace cc {
// 
// class PaintOpBufferOffsetsTest {
// public:
//     static void setSizes(std::vector<size_t>* offsets)
//     {
//         offsets->push_back(0);
//         offsets->push_back(8);
//         offsets->push_back(16);
//         offsets->push_back(24);
//         offsets->push_back(32);
//         offsets->push_back(40);
//         offsets->push_back(48);
//         offsets->push_back(56);
//         offsets->push_back(64);
//         offsets->push_back(72);
//         offsets->push_back(80);
//         offsets->push_back(88);
//         offsets->push_back(96);
//         offsets->push_back(104);
//         offsets->push_back(112);
//         offsets->push_back(120);
//         offsets->push_back(128);
//     }
//     static void test(const void* data, size_t size, const ::cc::DisplayItemList& in, PaintOpBuffer* paint_op_buffer)
//     {
//         std::vector<uint8_t> scratchBuffer;
//         ::cc::PaintOp::DeserializeOptions options(nullptr, nullptr, nullptr, &scratchBuffer, false, nullptr);
// 
//         std::vector<size_t> offsets;
//         gfx::Rect canvas_playback_rect(-1, -1, 902, 482);
//         //in.rtree_.Search(canvas_playback_rect, &offsets);
//         setSizes(&offsets);
// 
//         SkCanvas raster_canvas(900, 480);
// 
//         ::cc::DisplayItemList* inDisplay = (::cc::DisplayItemList*)(&in);
//         paint_op_buffer->Reset();
//         paint_op_buffer->Deserialize(data, size, options);
//         //inDisplay->Raster(&raster_canvas, nullptr);
//         paint_op_buffer->Playback(&raster_canvas, PlaybackParams(nullptr), &offsets);
// 
//         //         cc::DisplayItemList test;
//         //         test.rtree_.Deserialize(rtreeHead);
// 
//         //         PaintOpBuffer paint_op_buffer2;
//         //         paint_op_buffer2.Deserialize(data, size, options);
// 
//         //test.Raster(&raster_canvas, nullptr);
//     }
// };
// 
// void DisplayItemListTest::serializeCcDisplayItemList(const ::cc::DisplayItemList& in, base::Pickle* pickleOut)
// {
// #if 1
//     ::cc::RTreeSize::FlatHead* rtreeHead = in.rtree_.Serialize();
//     pickleOut->WriteData((const char*)rtreeHead, rtreeHead->size);
// #endif
//     std::vector<char> buf;
//     buf.resize(0x10000);
//     void* ptr = buf.data();
// 
//     cc::PaintOp::SerializeOptions serializeOptions;
//     serializeOptions.can_use_lcd_text = true;
//     serializeOptions.strike_server = new SkStrikeServer(new TestDiscardableManager()); // 内存泄露
//     serializeOptions.paint_cache = new cc::ClientPaintCache(0);
// 
//     std::vector<uint8_t> strikeData;
//     serializeOptions.strike_server->writeStrikeData(&strikeData);
//     //pickleOut->WriteData((const char*)strikeData.data(), strikeData.size());
// 
//     ::cc::SimpleBufferSerializer serializer(ptr, buf.size(), serializeOptions);
//     serializer.Serialize(&in.paint_op_buffer_);
// 
//     //--
//     if (0) {
//         PaintOpBufferOffsetsTest::test(ptr, serializer.written(), in, (PaintOpBuffer*)(&in.paint_op_buffer_));
//     }
//     //--
// 
//     pickleOut->WriteData(buf.data(), serializer.written());
// #if 1
//     free(rtreeHead);
// #endif
// }
// 
// }
// 
// namespace rbi {
// 
// void serializeContentDrawQuadBase(const viz::ContentDrawQuadBase& in, base::Pickle* pickleOut)
// {
//     serializeGfxRectF(in.tex_coord_rect, pickleOut);
//     serializeGfxSize(in.texture_size, pickleOut);
//     pickleOut->WriteBool(in.is_premultiplied);
//     pickleOut->WriteBool(in.nearest_neighbor);
//     pickleOut->WriteBool(in.force_anti_aliasing_off);
// 
//     pickleOut->WriteUInt32(kDebugFlag);
// }
// 
// void serializeVizDrawQuadResources(const viz::DrawQuad::Resources& in, base::Pickle* pickleOut)
// {
//     pickleOut->WriteData((const char*)&in, sizeof(viz::DrawQuad::Resources));
// }
// 
// void serializeVizPictureDrawQuad(const viz::PictureDrawQuad& in, base::Pickle* pickleOut)
// {
//     serializeContentDrawQuadBase(in, pickleOut);
//     serializeGfxRect(in.content_rect, pickleOut);
//     pickleOut->WriteFloat(in.contents_scale);
// 
//     CHECK(in.image_animation_map.size() < 0xffff);
//     pickleOut->WriteUInt16(in.image_animation_map.size());
//     for (viz::PictureDrawQuad::ImageAnimationMap::const_iterator it = in.image_animation_map.begin(); it != in.image_animation_map.end(); ++it) {
//         ::cc::PaintImage::Id id = it->first;
//         size_t size = it->second;
//         pickleOut->WriteInt(id);
//         pickleOut->WriteUInt32(size);
//     }
// 
//     cc::DisplayItemListTest::serializeCcDisplayItemList(*(in.display_item_list.get()), pickleOut);
//     pickleOut->WriteUInt16(in.texture_format);
// }
// 
// static int findSharedQuadStateListPos(const viz::SharedQuadStateList& stateList, const viz::SharedQuadState* state)
// {
//     int pos = 0;
//     for (viz::SharedQuadStateList::ConstIterator it = stateList.begin(); it != stateList.end(); ++it, ++pos) {
//         const viz::SharedQuadState* shared_quad_state = *it;
//         if (state == shared_quad_state)
//             return pos;
//     }
//     DebugBreak();
//     return -1;
// }
// 
// void serializeVizQuadList(const viz::SharedQuadStateList& stateList, const viz::QuadList& in, base::Pickle* pickleOut)
// {
//     CHECK(in.size() < 0xffff);
//     pickleOut->WriteUInt16(in.size());
// 
//     for (viz::QuadList::ConstIterator it = in.begin(); it != in.end(); ++it) {
//         const viz::DrawQuad* quad = *it;
//         pickleOut->WriteUInt16((uint16_t)quad->material);
// 
//         serializeGfxRect(quad->rect, pickleOut);
//         serializeGfxRect(quad->visible_rect, pickleOut);
//         pickleOut->WriteBool(quad->needs_blending);
//         serializeVizDrawQuadResources(quad->resources, pickleOut);
//         pickleOut->WriteUInt32(kDebugFlag);
// 
//         //serializeVizSharedQuadState(*quad->shared_quad_state, pickleOut);
//         int pos = findSharedQuadStateListPos(stateList, quad->shared_quad_state);
//         pickleOut->WriteUInt16((uint16_t)pos);
// 
//         switch (quad->material) {
//         case viz::DrawQuad::Material::kDebugBorder:
//             //quad_list.AllocateAndCopyFrom(DebugBorderDrawQuad::MaterialCast(quad));
//             break;
//         case viz::DrawQuad::Material::kPictureContent: {
//             //quad_list.AllocateAndCopyFrom(PictureDrawQuad::MaterialCast(quad));
//             const viz::PictureDrawQuad* q = viz::PictureDrawQuad::MaterialCast(quad);
//             serializeVizPictureDrawQuad(*q, pickleOut);
// 
//         } break;
//         case viz::DrawQuad::Material::kTextureContent:
//             //quad_list.AllocateAndCopyFrom(TextureDrawQuad::MaterialCast(quad));
//             break;
//         case viz::DrawQuad::Material::kSolidColor: {
//             const viz::SolidColorDrawQuad* solid = viz::SolidColorDrawQuad::MaterialCast(quad);
//             serializeSkColor4f(solid->color, pickleOut);
//             pickleOut->WriteBool(solid->force_anti_aliasing_off);
//         } break;
//         case viz::DrawQuad::Material::kTiledContent:
//             //quad_list.AllocateAndCopyFrom(TileDrawQuad::MaterialCast(quad));
//             break;
//         case viz::DrawQuad::Material::kSurfaceContent:
//             //quad_list.AllocateAndCopyFrom(SurfaceDrawQuad::MaterialCast(quad));
//             break;
//         case viz::DrawQuad::Material::kVideoHole:
//             //quad_list.AllocateAndCopyFrom(VideoHoleDrawQuad::MaterialCast(quad));
//             break;
//         case viz::DrawQuad::Material::kYuvVideoContent:
//             //quad_list.AllocateAndCopyFrom(YUVVideoDrawQuad::MaterialCast(quad));
//             break;
//         case viz::DrawQuad::Material::kSharedElement:
//             //quad_list.AllocateAndCopyFrom(SharedElementDrawQuad::MaterialCast(quad));
//             break;
//             // RenderPass quads need to use specific CopyFrom function.
//         case viz::DrawQuad::Material::kAggregatedRenderPass:
//         case viz::DrawQuad::Material::kCompositorRenderPass:
//         case viz::DrawQuad::Material::kInvalid:
//             // TODO(danakj): Why is this a check instead of dcheck, and validate from IPC?
//             CHECK(false); // Invalid DrawQuad material.
//             break;
//         }
//     }
// }
// 
// void serializeVizSharedQuadStateList(const viz::SharedQuadStateList& stateList, base::Pickle* pickleOut)
// {
//     pickleOut->WriteUInt16(stateList.size());
//     for (viz::SharedQuadStateList::ConstIterator it = stateList.begin(); it != stateList.end(); ++it) {
//         const viz::SharedQuadState* shared_quad_state = *it;
//         serializeVizSharedQuadState(*shared_quad_state, pickleOut);
//     }
// }
// 
// void serializeVizCompositorRenderPass(const viz::CompositorRenderPass& in, base::Pickle* pickleOut)
// {
//     pickleOut->WriteUInt64(in.id.value());
//     pickleOut->WriteUInt32(in.subtree_capture_id.subtree_id());
//     serializeGfxSize(in.subtree_size, pickleOut);
//     pickleOut->WriteUInt32(in.shared_element_resource_id.id());
//     pickleOut->WriteBool(in.has_per_quad_damage);
//     serializeGfxRect(in.output_rect, pickleOut);
//     serializeGfxRect(in.damage_rect, pickleOut);
// 
//     serializeGfxTransform(in.transform_to_root_target, pickleOut);
// 
//     serializeCcFilterOperations(in.filters, pickleOut);
//     serializeCcFilterOperations(in.backdrop_filters, pickleOut);
// 
//     pickleOut->WriteBool(in.backdrop_filter_bounds.has_value());
//     if (in.backdrop_filter_bounds.has_value()) {
//         gfx::RRectF rr = in.backdrop_filter_bounds.value();
//         serializeGfxRRectF(rr, pickleOut);
//     }
//     pickleOut->WriteBool(in.has_transparent_background);
//     pickleOut->WriteBool(in.cache_render_pass);
//     pickleOut->WriteBool(in.has_damage_from_contributing_content);
//     pickleOut->WriteBool(in.generate_mipmap);
// 
//     CHECK(in.copy_requests.size() == 0);
// 
//     serializeVizSharedQuadStateList(in.shared_quad_state_list, pickleOut);
//     serializeVizQuadList(in.shared_quad_state_list, in.quad_list, pickleOut);
//     pickleOut->WriteUInt32(kDebugFlag);
// }
// 
// void serializeVizCompositorFrame(const viz::CompositorFrame& frameIn, base::Pickle* pickleOut)
// {
//     //base::Pickle* pickle = new base::Pickle(sizeof(CompositorFrameHead));
//     serializeCompositorFrameMetadata(frameIn.metadata, pickleOut);
// 
//     pickleOut->WriteUInt32((uint32_t)frameIn.resource_list.size());
//     for (size_t i = 0; i < frameIn.resource_list.size(); ++i) {
//         serializeVizTransferableResource(frameIn.resource_list[i], pickleOut);
//     }
// 
//     pickleOut->WriteUInt32((uint32_t)frameIn.render_pass_list.size());
//     for (size_t i = 0; i < frameIn.render_pass_list.size(); ++i) {
//         serializeVizCompositorRenderPass(*(frameIn.render_pass_list[i].get()), pickleOut);
//     }
// }

}