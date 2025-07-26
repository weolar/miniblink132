
#include "mojo/public/cpp/base/big_buffer.h"
#include "mojo/public/cpp/base/big_buffer_mojom_traits.h"
#include "mojo/public/cpp/bindings/associated_group.h"
#include "mojo/public/cpp/bindings/associated_receiver.h"
#include "mojo/public/cpp/bindings/async_flusher.h"
#include "mojo/public/cpp/bindings/connector.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/generic_pending_receiver.h"
#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/associated_interface_ptr_state.h"
#include "mojo/public/cpp/bindings/lib/binding_state.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/interface_ptr_state.h"
#include "mojo/public/cpp/bindings/lib/message_quota_checker.h"
#include "mojo/public/cpp/bindings/lib/pending_receiver_state.h"
#include "mojo/public/cpp/bindings/lib/pending_remote_state.h"
#include "mojo/public/cpp/bindings/lib/unserialized_message_context.h"
#include "mojo/public/cpp/bindings/lib/task_runner_helper.h"
#include "mojo/public/cpp/bindings/message.h"
#include "mojo/public/cpp/bindings/receiver_set.h"
#include "mojo/public/cpp/bindings/scoped_interface_endpoint_handle.h"
#include "mojo/public/cpp/bindings/sync_handle_watcher.h"
#include "mojo/public/cpp/system/buffer.h"
#include "mojo/public/cpp/system/data_pipe_drainer.h"
#include "mojo/public/cpp/system/handle.h"
#include "mojo/public/cpp/system/wait.h"
#include "mojo/public/cpp/system/wait_set.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/struct_ptr.h"
#include "mojo/public/mojom/base/big_buffer.mojom-shared-internal.h"
#include "mojo/public/mojom/base/big_buffer.mojom-shared.h"
#include "skia/public/mojom/image_info.mojom-shared.h"
#include "services/viz/public/mojom/compositing/layer_context.mojom.h"
#include "services/viz/privileged/mojom/compositing/frame_sink_manager_test_api.mojom.h"
#include "services/viz/privileged/mojom/compositing/frame_sinks_metrics_recorder.mojom.h"
#include "services/network/public/mojom/trust_token_access_observer.mojom.h"
#include "services/network/public/mojom/shared_dictionary_access_observer.mojom.h"
#include "services/network/public/mojom/devtools_observer.mojom.h"
#include "services/network/public/mojom/cross_origin_embedder_policy.mojom.h"
#include "services/network/public/mojom/cookie_access_observer.mojom.h"
#include "services/network/public/mojom/cookie_manager.mojom-blink.h"
#include "services/network/public/mojom/accept_ch_frame_observer.mojom.h"
#include "ui/gfx/mojom/delegated_ink_point_renderer.mojom.h"
#include "third_party/blink/public/mojom/conversions/conversions.mojom-blink.h"
#include "third_party/blink/public/mojom/payments/payment_app.mojom-blink.h"
#include "third_party/blink/public/mojom/device_posture/device_posture_provider.mojom-blink.h"
#include "third_party/blink/public/mojom/loader/fetch_later.mojom.h"
#include "third_party/blink/public/mojom/worker/worklet_global_scope_creation_params.mojom-blink.h"
#include "third_party/blink/public/mojom/service_worker/service_worker_stream_handle.mojom-blink.h"
#include "third_party/blink/public/mojom/service_worker/service_worker_registration.mojom-blink.h"
#include "third_party/blink/public/mojom/service_worker/service_worker_object.mojom-blink.h"
#include "third_party/blink/public/mojom/service_worker/service_worker_installed_scripts_manager.mojom-blink.h"
#include "third_party/blink/public/mojom/service_worker/service_worker.mojom-blink.h"
#include "third_party/blink/public/mojom/service_worker/service_worker_fetch_response_callback.mojom-blink.h"
#include "third_party/blink/public/mojom/loader/fetch_later.mojom-blink.h"
#include "third_party/blink/public/mojom/lcp_critical_path_predictor/lcp_critical_path_predictor.mojom-blink.h"
#include "third_party/blink/public/mojom/presentation/presentation.mojom-blink.h"
#include "third_party/blink/public/mojom/origin_trials/origin_trial_state_host.mojom-blink.h"
#include "third_party/blink/public/mojom/permissions/permission.mojom-blink.h"
#include "third_party/blink/public/mojom/frame/frame.mojom-blink.h"
#include "third_party/blink/public/mojom/loader/keep_alive_handle.mojom-blink.h"
#include "third_party/blink/public/mojom/idle/idle_manager.mojom-blink.h"
#include "third_party/blink/public/mojom/file_system_access/file_system_access_transfer_token.mojom-blink.h"
#include "third_party/blink/public/mojom/file_system_access/file_system_access_manager.mojom-blink.h"
#include "third_party/blink/public/mojom/permissions/permission.mojom-blink.h"
#include "third_party/blink/public/mojom/cookie_store/cookie_store.mojom-blink.h"
#include "third_party/blink/public/mojom/service_worker/controller_service_worker.mojom-blink.h"
#include "third_party/blink/public/mojom/call_stack_generator/call_stack_generator.mojom-blink.h"
#include "third_party/blink/public/mojom/browser_interface_broker.mojom-blink.h"
#include "third_party/blink/public/mojom/background_fetch/background_fetch.mojom-blink.h"
#include "third_party/blink/public/mojom/background_fetch/background_fetch.mojom-blink.h"
#include "third_party/blink/public/mojom/associated_interfaces/associated_interfaces.mojom-blink.h"
#include "third_party/blink/public/mojom/blob/file_backed_blob_factory.mojom-blink.h"
#include "components/viz/service/debugger/mojom/viz_debugger.mojom.h"
#include "components/attribution_reporting/data_host.mojom-blink.h"
#include "components/performance_manager/public/mojom/coordination_unit.mojom-blink.h"
#include "mojo/public/mojom/base/big_buffer.mojom-shared-internal.h"
#include "mojo/public/mojom/base/string16.mojom-shared-internal.h"
#include "mojo/public/mojom/base/time.mojom-shared-internal.h"
#include "mojo/public/mojom/base/unguessable_token.mojom-shared-internal.h"
#include "services/media_session/public/mojom/media_session.mojom-blink.h"
#include "services/network/public/mojom/content_security_policy.mojom-blink.h"
#include "services/network/public/mojom/content_security_policy.mojom.h"
#include "services/network/public/mojom/timing_allow_origin.mojom-blink.h"
#include "services/network/public/mojom/timing_allow_origin.mojom.h"
#include "services/viz/public/mojom/compositing/frame_sink_bundle.mojom-blink.h"
#include "skia/public/mojom/bitmap.mojom-shared-internal.h"
#include "skia/public/mojom/image_info.mojom-shared-internal.h"
#include "third_party/blink/public/mojom/dom_storage/storage_area.mojom-blink.h"
#include "third_party/blink/public/mojom/dom_storage/session_storage_namespace.mojom-blink.h"
#include "third_party/blink/public/mojom/dom_storage/dom_storage.mojom-blink.h"
#include "third_party/blink/public/mojom/array_buffer/array_buffer_contents.mojom-shared-internal.h"
#include "third_party/blink/public/mojom/blob/data_element.mojom-blink.h"
#include "third_party/blink/public/mojom/blob/data_element.mojom.h"
#include "third_party/blink/public/mojom/choosers/file_chooser.mojom-blink.h"
#include "third_party/blink/public/mojom/messaging/cloneable_message.mojom-shared-internal.h"
#include "third_party/blink/public/mojom/messaging/cloneable_message.mojom-shared.h"
#include "third_party/blink/public/common/messaging/cloneable_message.h"
#include "third_party/blink/public/mojom/broadcastchannel/broadcast_channel.mojom-blink.h"
#include "third_party/blink/public/mojom/messaging/message_port_descriptor.mojom-shared-internal.h"
#include "third_party/blink/public/mojom/messaging/task_attribution_id.mojom-shared-internal.h"
#include "third_party/blink/public/mojom/messaging/transferable_message.mojom-shared-internal.h"
#include "third_party/blink/public/mojom/messaging/user_activation_snapshot.mojom-shared-internal.h"
#include "third_party/blink/public/mojom/page_state/page_state.mojom-shared-internal.h"
#include "third_party/blink/public/mojom/page_state/page_state.mojom.h"
#include "third_party/blink/public/mojom/permissions/permission.mojom-blink.h"
#include "third_party/blink/public/mojom/leak_detector/leak_detector.mojom-blink.h"
#include "third_party/blink/public/mojom/crash/crash_memory_metrics_reporter.mojom-blink.h"
#include "third_party/blink/public/mojom/performance_manager/v8_detailed_memory_reporter.mojom-blink.h"
#include "third_party/blink/public/mojom/input/input_messages.mojom-blink.h"
#include "third_party/blink/public/mojom/frame/reporting_observer.mojom-blink.h"
#include "third_party/blink/public/mojom/close_watcher/close_listener.mojom-blink.h"
#include "third_party/blink/public/mojom/choosers/popup_menu.mojom-blink.h"
#include "third_party/blink/public/mojom/worker/shared_worker_client.mojom-blink.h"
#include "third_party/blink/public/mojom/service_worker/service_worker_worker_client.mojom-blink.h"
#include "third_party/blink/public/mojom/worker/subresource_loader_updater.mojom-blink.h"
#include "third_party/blink/public/mojom/blob/blob.mojom.h"
#include "third_party/blink/public/mojom/page/page.mojom-blink.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_union_arraybuffer_arraybufferview.h"
#include "third_party/blink/renderer/core/mojo/mojo_watcher.h"
#include "third_party/blink/renderer/core/mojo/mojo_handle.h"
#include "third_party/blink/renderer/core/mojo/test/mojo_interface_request_event.h"
#include "third_party/blink/renderer/core/mojo/test/mojo_interface_interceptor.h"
#include "third_party/blink/renderer/platform/weborigin/security_origin.h"
#include "third_party/blink/public/common/messaging/cloneable_message_mojom_traits.h"
#include "third_party/blink/public/mojom/messaging/transferable_message.mojom-blink.h"
#include "third_party/blink/public/mojom/quota/quota_manager_host.mojom-blink.h"
#include "third_party/blink/public/mojom/blob/blob_registry.mojom.h"
#include "third_party/blink/public/mojom/associated_interfaces/associated_interfaces.mojom.h"
#include "third_party/blink/public/mojom/associated_interfaces/associated_interfaces.mojom-blink.h"
#include "third_party/blink/public/mojom/blob/blob.mojom-blink.h"
#include "third_party/blink/public/mojom/browser_interface_broker.mojom.h"
#include "third_party/blink/public/mojom/loader/code_cache.mojom.h"
#include "third_party/blink/public/mojom/loader/keep_alive_handle_factory.mojom-blink.h"
#include "third_party/blink/public/mojom/loader/resource_load_info_notifier.mojom-blink.h"
//#include "third_party/blink/public/mojom/loader/anchor_element_interaction_host.mojom-blink.h"
#include "third_party/blink/public/mojom/loader/navigation_predictor.mojom-blink.h"
#include "third_party/blink/public/mojom/annotation/annotation.mojom-blink.h"
//#include "third_party/blink/public/mojom/conversions/attribution_data_host.mojom-blink.h"
#include "third_party/blink/public/mojom/frame/back_forward_cache_controller.mojom-blink.h"
#include "third_party/blink/public/mojom/blob/blob.mojom-blink.h"
#include "third_party/blink/public/mojom/blob/blob_registry.mojom-blink.h"
#include "third_party/blink/public/mojom/blob/blob_url_store.mojom-blink.h"
#include "third_party/blink/public/mojom/blob/blob_url_store.mojom-blink.h"
#include "third_party/blink/public/mojom/clipboard/clipboard.mojom-blink.h"
#include "third_party/blink/public/mojom/clipboard/clipboard.mojom-blink.h"
#include "third_party/blink/public/mojom/loader/content_security_notifier.mojom-blink.h"
#include "third_party/blink/public/mojom/conversions/conversions.mojom-blink.h"
#include "third_party/blink/public/mojom/context_menu/context_menu.mojom-blink.h"
#include "third_party/blink/public/mojom/dwrite_font_proxy/dwrite_font_proxy.mojom-blink.h"
#include "third_party/blink/public/mojom/worker/dedicated_worker_host.mojom-blink.h"
#include "third_party/blink/public/mojom/choosers/date_time_chooser.mojom-blink.h"
#include "third_party/blink/public/mojom/devtools/devtools_agent.mojom-blink.h"
#include "third_party/blink/public/mojom/devtools/devtools_frontend.mojom-blink.h"
#include "third_party/blink/public/mojom/devtools/devtools_agent.mojom-blink.h"
#include "third_party/blink/public/mojom/page/display_cutout.mojom-blink.h"
#include "third_party/blink/public/mojom/frame_sinks/embedded_frame_sink.mojom-blink.h"
#include "third_party/blink/public/mojom/choosers/color_chooser.mojom-blink.h"
#include "third_party/blink/public/mojom/fenced_frame/fenced_frame.mojom-blink.h"
#include "third_party/blink/public/mojom/fenced_frame/fenced_frame.mojom.h"
#include "third_party/blink/public/mojom/fenced_frame/fenced_frame.mojom-blink.h"
#include "third_party/blink/public/mojom/loader/code_cache.mojom-blink.h"
#include "third_party/blink/public/mojom/loader/resource_load_info_notifier.mojom.h"
#include "third_party/blink/public/mojom/file_system_access/file_system_access_transfer_token.mojom-blink.h"
#include "third_party/blink/public/mojom/file_system_access/file_system_access_data_transfer_token.mojom-blink.h"
#include "third_party/blink/public/mojom/file/file_utilities.mojom-blink.h"
#include "third_party/blink/public/mojom/frame/find_in_page.mojom-blink.h"
#include "third_party/blink/public/mojom/page/widget.mojom-blink.h"
#include "third_party/blink/public/mojom/gpu/gpu.mojom-blink.h"
#include "third_party/blink/public/mojom/frame/frame.mojom-blink.h"
#include "third_party/blink/public/mojom/loader/pause_subresource_loading_handle.mojom-blink.h"
#include "third_party/blink/public/mojom/oom_intervention/oom_intervention.mojom-blink.h"
//#include "third_party/blink/public/mojom/frame/pending_beacon.mojom-blink.h"
#include "third_party/blink/public/mojom/plugins/plugin_registry.mojom-blink.h"
#include "third_party/blink/public/mojom/permissions/permission.mojom-blink.h"
#include "third_party/blink/public/mojom/frame/policy_container.mojom.h"
#include "third_party/blink/public/mojom/input/pointer_lock_context.mojom-blink.h"
#include "third_party/blink/public/mojom/page/widget.mojom-blink.h"
#include "third_party/blink/public/mojom/media/fullscreen_video_element.mojom-blink.h"
#include "third_party/blink/public/mojom/mime/mime_registry.mojom-blink.h"
#include "third_party/blink/public/mojom/prerender/prerender.mojom-blink.h"
#include "third_party/blink/public/mojom/frame/policy_container.mojom-blink.h"
//#include "third_party/blink/public/mojom/portal/portal.mojom-blink.h"
#include "third_party/blink/public/mojom/blob/blob_registry.mojom-blink.h"
#include "third_party/blink/public/mojom/frame/remote_frame.mojom-blink.h"
#include "third_party/blink/public/mojom/renderer_preference_watcher.mojom-blink.h"
#include "third_party/blink/public/mojom/reporting/reporting.mojom-blink.h"
#include "third_party/blink/public/mojom/service_worker/service_worker_worker_client_registry.mojom-blink.h"
#include "third_party/blink/public/mojom/worker/shared_worker_connector.mojom-blink.h"
#include "third_party/blink/public/mojom/worker/shared_worker_host.mojom-blink.h"
#include "third_party/blink/public/mojom/speculation_rules/speculation_rules.mojom-blink.h"
#include "third_party/blink/public/mojom/frame_sinks/embedded_frame_sink.mojom-blink.h"
#include "third_party/blink/public/mojom/link_to_text/link_to_text.mojom-blink.h"
#include "third_party/blink/public/mojom/input/input_host.mojom-blink.h"
#include "third_party/blink/public/mojom/wake_lock/wake_lock.mojom-blink.h"
#include "third_party/blink/public/mojom/widget/platform_widget.mojom-blink.h"
#include "third_party/blink/public/mojom/input/input_handler.mojom-blink.h"
#include "third_party/blink/public/mojom/worker/worker_content_settings_proxy.mojom-blink.h"
//#include "third_party/blink/public/mojom/conversions/attribution_reporting_automation.mojom-blink.h"
#include "third_party/blink/public/mojom/disk_allocator.mojom-blink.h"
#include "third_party/blink/public/mojom/websockets/websocket_connector.mojom-blink.h"
#include "services/network/public/mojom/websocket.mojom-blink.h"
#include "cc/mojom/render_frame_metadata.mojom-blink.h"
#include "media/mojo/mojom/watch_time_recorder.mojom.h"
#include "media/mojo/mojom/media_player.mojom-blink.h"
#include "services/device/public/mojom/screen_orientation.mojom-blink.h"
#include "services/device/public/mojom/time_zone_monitor.mojom-blink.h"
#include "services/device/public/mojom/wake_lock.mojom-blink.h"
#include "services/network/public/mojom/url_loader.mojom-blink.h"
#include "services/network/public/mojom/url_loader.mojom.h"
#include "services/network/public/mojom/data_pipe_getter.mojom.h"
#include "services/network/public/mojom/url_loader.mojom.h"
#include "services/network/public/mojom/url_loader_factory.mojom.h"
#include "services/network/public/mojom/chunked_data_pipe_getter.mojom-blink.h"
#include "services/network/public/mojom/cross_origin_opener_policy.mojom-blink.h"
#include "services/network/public/mojom/data_pipe_getter.mojom-blink.h"
#include "services/network/public/mojom/restricted_cookie_manager.mojom-blink.h"
#include "services/network/public/mojom/trust_tokens.mojom-blink.h"
#include "services/network/public/mojom/url_loader_factory.mojom-blink.h"
#include "services/network/public/mojom/web_bundle_handle.mojom-blink.h"
#include "services/viz/public/mojom/compositing/video_detector_observer.mojom.h"
#include "services/viz/public/mojom/compositing/compositor_frame_sink.mojom-blink.h"
#include "services/viz/public/mojom/compositing/compositor_frame_sink.mojom.h"
#include "services/viz/public/mojom/compositing/frame_sink_bundle.mojom-blink.h"
#include "services/viz/public/mojom/compositing/frame_sink_bundle.mojom.h"
#include "services/viz/public/mojom/hit_test/input_target_client.mojom-blink.h"
#include "services/viz/privileged/mojom/viz_main.mojom.h"
#include "services/viz/privileged/mojom/compositing/vsync_parameter_observer.mojom.h"
#include "services/viz/privileged/mojom/compositing/begin_frame_observer.mojom.h"
#include "services/viz/privileged/mojom/compositing/display_private.mojom.h"
#include "services/viz/privileged/mojom/compositing/frame_sink_manager.mojom.h"
#include "services/viz/privileged/mojom/compositing/layered_window_updater.mojom.h"
#include "services/viz/privileged/mojom/compositing/frame_sink_video_capture.mojom.h"
#include "services/viz/privileged/mojom/compositing/external_begin_frame_controller.mojom.h"
#include "third_party/skia/include/core/SkAlphaType.h"
#include "ui/gfx/geometry/mojom/geometry.mojom-shared-internal.h"
#include "url/mojom/origin.mojom-shared-internal.h"
#include <windows.h>

class mojo::WaitSet::State : public base::RefCountedThreadSafe<mojo::WaitSet::State> {
public:
    State()

    {
    }

    State(const State&) = delete;
    State& operator=(const State&) = delete;

    void Wait(
        base::WaitableEvent** ready_event, size_t* num_ready_handles, Handle* ready_handles, MojoResult* ready_results, MojoHandleSignalsState* signals_states)
    {
    }

private:
    friend class base::RefCountedThreadSafe<State>;

    ~State()
    {
    }
};

bool mojo::EnumTraits<mojo_base::mojom::TextDirection, base::i18n::TextDirection>::FromMojom(mojo_base::mojom::TextDirection, base::i18n::TextDirection*)
{
    *(int*)1 = 1;
    return false;
}

bool mojo::EnumTraits<network::mojom::RequestPriority, net::RequestPriority>::FromMojom(network::mojom::RequestPriority, net::RequestPriority*)
{
    *(int*)1 = 1;
    return false;
}
bool mojo::EnumTraits<ui::mojom::TextInputAction, ui::TextInputAction>::FromMojom(ui::mojom::TextInputAction mtype, ui::TextInputAction* type)
{
    switch (mtype) {
    case ui::mojom::TextInputAction::kDefault:
        *type = ui::TextInputAction::kDefault;
        break;
    case ui::mojom::TextInputAction::kEnter:
        *type = ui::TextInputAction::kEnter;
        break;
    case ui::mojom::TextInputAction::kDone:
        *type = ui::TextInputAction::kDone;
        break;
    case ui::mojom::TextInputAction::kGo:
        *type = ui::TextInputAction::kGo;
        break;
    case ui::mojom::TextInputAction::kNext:
        *type = ui::TextInputAction::kNext;
        break;
    case ui::mojom::TextInputAction::kPrevious:
        *type = ui::TextInputAction::kPrevious;
        break;
    case ui::mojom::TextInputAction::kSearch:
        *type = ui::TextInputAction::kSearch;
        break;
    case ui::mojom::TextInputAction::kSend:
        *type = ui::TextInputAction::kSend;
        break;
    default:
        return false;
        break;
    }

    return true;
}
bool mojo::EnumTraits<ui::mojom::TextInputMode, ui::TextInputMode>::FromMojom(ui::mojom::TextInputMode mtype, ui::TextInputMode* type)
{
    switch (mtype) {
    case ui::mojom::TextInputMode::kDefault:
        *type = ui::TextInputMode::TEXT_INPUT_MODE_DEFAULT;
        break;
    case ui::mojom::TextInputMode::kNone:
        *type = ui::TextInputMode::TEXT_INPUT_MODE_NONE;
        break;
    case ui::mojom::TextInputMode::kText:
        *type = ui::TextInputMode::TEXT_INPUT_MODE_TEXT;
        break;
    case ui::mojom::TextInputMode::kTel:
        *type = ui::TextInputMode::TEXT_INPUT_MODE_TEL;
        break;
    case ui::mojom::TextInputMode::kUrl:
        *type = ui::TextInputMode::TEXT_INPUT_MODE_URL;
        break;
    case ui::mojom::TextInputMode::kEmail:
        *type = ui::TextInputMode::TEXT_INPUT_MODE_EMAIL;
        break;
    case ui::mojom::TextInputMode::kNumeric:
        *type = ui::TextInputMode::TEXT_INPUT_MODE_NUMERIC;
        break;
    case ui::mojom::TextInputMode::kDecimal:
        *type = ui::TextInputMode::TEXT_INPUT_MODE_DECIMAL;
        break;
    case ui::mojom::TextInputMode::kSearch:
        *type = ui::TextInputMode::TEXT_INPUT_MODE_SEARCH;
        break;
    default:
        return false;
        break;
    }

    return true;
}
bool mojo::EnumTraits<ui::mojom::TextInputType, ui::TextInputType>::FromMojom(ui::mojom::TextInputType mtype, ui::TextInputType* type)
{
    // ash/components/arc/mojom/ime_mojom_traits.h
    switch (mtype) {
    case ui::mojom::TextInputType::NONE:
        *type = ui::TextInputType::TEXT_INPUT_TYPE_NONE;
        break;
    case ui::mojom::TextInputType::TEXT:
        *type = ui::TextInputType::TEXT_INPUT_TYPE_TEXT;
        break;
    case ui::mojom::TextInputType::PASSWORD:
        *type = ui::TextInputType::TEXT_INPUT_TYPE_PASSWORD;
        break;
    case ui::mojom::TextInputType::SEARCH:
        *type = ui::TextInputType::TEXT_INPUT_TYPE_SEARCH;
        break;
    case ui::mojom::TextInputType::EMAIL:
        *type = ui::TextInputType::TEXT_INPUT_TYPE_EMAIL;
        break;
    case ui::mojom::TextInputType::NUMBER:
        *type = ui::TextInputType::TEXT_INPUT_TYPE_NUMBER;
        break;
    case ui::mojom::TextInputType::TELEPHONE:
        *type = ui::TextInputType::TEXT_INPUT_TYPE_TELEPHONE;
        break;
    case ui::mojom::TextInputType::URL:
        *type = ui::TextInputType::TEXT_INPUT_TYPE_URL;
        break;
    case ui::mojom::TextInputType::DATE:
        *type = ui::TextInputType::TEXT_INPUT_TYPE_DATE;
        break;
    case ui::mojom::TextInputType::DATE_TIME:
        *type = ui::TextInputType::TEXT_INPUT_TYPE_DATE_TIME;
        break;
    case ui::mojom::TextInputType::DATE_TIME_LOCAL:
        *type = ui::TextInputType::TEXT_INPUT_TYPE_DATE_TIME_LOCAL;
        break;
    case ui::mojom::TextInputType::MONTH:
        *type = ui::TextInputType::TEXT_INPUT_TYPE_MONTH;
        break;
    case ui::mojom::TextInputType::TIME:
        *type = ui::TextInputType::TEXT_INPUT_TYPE_TIME;
        break;
    case ui::mojom::TextInputType::WEEK:
        *type = ui::TextInputType::TEXT_INPUT_TYPE_WEEK;
        break;
    case ui::mojom::TextInputType::TEXT_AREA:
        *type = ui::TextInputType::TEXT_INPUT_TYPE_TEXT_AREA;
        break;
    case ui::mojom::TextInputType::CONTENT_EDITABLE:
        *type = ui::TextInputType::TEXT_INPUT_TYPE_CONTENT_EDITABLE;
        break;
    case ui::mojom::TextInputType::DATE_TIME_FIELD:
        *type = ui::TextInputType::TEXT_INPUT_TYPE_DATE_TIME_FIELD;
        break;
    case ui::mojom::TextInputType::TYPE_NULL:
        *type = ui::TextInputType::TEXT_INPUT_TYPE_NULL;
        break;
    default:
        return false;
        break;
    }

    return true;
}

// M:\chromium\cef111\mojo\public\cpp\base\string16_mojom_traits.cc
bool mojo::StructTraits<mojo_base::mojom::String16DataView, std::u16string>::Read(mojo_base::mojom::String16DataView data, std::u16string* out)
{
    mojo::ArrayDataView<uint16_t> view;
    data.GetDataDataView(&view);
    out->assign(reinterpret_cast<const char16_t*>(view.data()), view.size());
    return true;
}

bool mojo::StructTraits<blink::mojom::FrameStateDataView, mojo::StructPtr<blink::mojom::FrameState>>::Read(
    blink::mojom::FrameStateDataView input, mojo::StructPtr<blink::mojom::FrameState>* output)
{
    bool success = true;
    ::blink::mojom::FrameStatePtr result(::blink::mojom::FrameState::New());

    if (success && !input.ReadUrlString(&result->url_string))
        success = false;
    if (success && !input.ReadReferrer(&result->referrer))
        success = false;
    if (success && !input.ReadTarget(&result->target))
        success = false;
    if (success && !input.ReadStateObject(&result->state_object))
        success = false;
    if (success && !input.ReadDocumentState(&result->document_state))
        success = false;
    if (success && !input.ReadScrollRestorationType(&result->scroll_restoration_type))
        success = false;
    //     if (success && !input.ReadViewState(&result->view_state))
    //         success = false;
    if (success)
        result->item_sequence_number = input.item_sequence_number();
    if (success)
        result->document_sequence_number = input.document_sequence_number();
    if (success && !input.ReadReferrerPolicy(&result->referrer_policy))
        success = false;
    //     if (success && !input.ReadHttpBody(&result->http_body))
    //         success = false;
    if (success && !input.ReadChildren(&result->children))
        success = false;
    if (success && !input.ReadInitiatorOrigin(&result->initiator_origin))
        success = false;
    if (success && !input.ReadNavigationApiKey(&result->navigation_api_key))
        success = false;
    if (success && !input.ReadNavigationApiId(&result->navigation_api_id))
        success = false;
    if (success && !input.ReadNavigationApiState(&result->navigation_api_state))
        success = false;
    if (success)
        result->protect_url_in_navigation_api = input.protect_url_in_navigation_api();
    //     if (success && !input.ReadInitiatorBaseUrlString(&result->initiator_base_url_string))
    //         success = false;
    *output = std::move(result);
    return success;
}

bool mojo::StructTraits<blink::mojom::PageStateDataView, mojo::StructPtr<blink::mojom::PageState>>::Read(
    blink::mojom::PageStateDataView input, mojo::StructPtr<blink::mojom::PageState>* output)
{
    bool success = true;
    ::blink::mojom::PageStatePtr result(::blink::mojom::PageState::New());

    if (success && !input.ReadReferencedFiles(&result->referenced_files))
        success = false;
    if (success && !input.ReadTop(&result->top))
        success = false;
    *output = std::move(result);
    return success;
}

// bool mojo::UnionTraits<mojo_base::mojom::BigBufferDataView, mojo_base::BigBuffer>::invalid_buffer(mojo_base::BigBuffer&)
// {
//     *(int*)1 = 1;
//     return false;
// }
// bool mojo::UnionTraits<mojo_base::mojom::BigBufferDataView, mojo_base::BigBufferView>::invalid_buffer(mojo_base::BigBufferView&)
// {
//     *(int*)1 = 1;
//     return false;
// }
bool mojo::UnionTraits<network::mojom::DataElementDataView, network::DataElement>::Read(network::mojom::DataElementDataView, class network::DataElement*)
{
    *(int*)1 = 1;
    return false;
}

bool viz::mojom::blink::CompositorFrameSink::SubmitCompositorFrameSync(const ::viz::LocalSurfaceId& local_surface_id, ::viz::CompositorFrame frame,
    absl::optional<::viz::HitTestRegionList> hit_test_region_list, uint64_t submit_time, WTF::Vector<::viz::ReturnedResource>* out_resources)
{
    *(int*)1 = 1;
    return false;
}

// network::mojom::blink::AllowCSPFromHeaderValue::AllowCSPFromHeaderValue(void)
// {
//     *(int*)1 = 1;
// }
// 
// network::mojom::AllowCSPFromHeaderValue::AllowCSPFromHeaderValue(void)
// {
//     *(int*)1 = 1;
// }

network::mojom::TimingAllowOrigin::TimingAllowOrigin(void)
{
    *(int*)1 = 1;
}

int64_t mojo::StructTraits<mojo_base::mojom::TimeDataView, base::Time>::internal_value(base::Time const&)
{
    *(int*)1 = 1;
    return 0;
}

void mojo::internal::RecordInvalidStringDeserialization()
{
    ;
}

// WTF::Vector<SkBitmap, 0, WTF::PartitionAllocator>
// mojo::StructTraits<class blink::mojom::TransferableMessageDataView, struct blink::BlinkTransferableMessage>::image_bitmap_contents_array(struct blink::BlinkCloneableMessage const&)
// {
//     return WTF::Vector<SkBitmap, 0, WTF::PartitionAllocator>(); // 暂时不搞图片的序列化了
// }

bool mojo::StructTraits<skia::mojom::BitmapN32DataView, SkBitmap>::Read(skia::mojom::BitmapN32DataView, SkBitmap*)
{
    DebugBreak();
    return false;
}

bool mojo::StructTraits<blink::mojom::UserActivationSnapshotDataView, mojo::InlinedStructPtr<blink::mojom::blink::UserActivationSnapshot>>::Read(
    blink::mojom::UserActivationSnapshotDataView, mojo::InlinedStructPtr<blink::mojom::blink::UserActivationSnapshot>*)
{
    DebugBreak();
    return false;
}

// template<>
// bool mojo::internal::Serializer<mojo_base::mojom::BigBufferSharedMemoryRegionDataView, mojo_base::internal::BigBufferSharedMemoryRegion>::
// Deserialize(mojo_base::mojom::internal::BigBufferSharedMemoryRegion_Data* data, mojo_base::internal::BigBufferSharedMemoryRegion*, mojo::Message* out)
// {
//     DebugBreak();
//     return false;
// }

// bool mojo::UnionTraits<mojo_base::mojom::BigBufferDataView, mojo_base::BigBufferView>::Read(
//     mojo_base::mojom::BigBufferDataView data, mojo_base::BigBufferView* out)
// {
//     switch (data.tag()) {
//         case mojo_base::mojom::BigBufferDataView::Tag::kBytes:
//         {
//             mojo::ArrayDataView<uint8_t> bytes_view;
//             data.GetBytesDataView(&bytes_view);
//             out->SetBytes(bytes_view);
//             return true;
//         }
//
//         case mojo_base::mojom::BigBufferDataView::Tag::kSharedMemory:
//         {
//             mojo_base::internal::BigBufferSharedMemoryRegion shared_memory;
//             if (!data.ReadSharedMemory(&shared_memory))
//                 return false;
//             out->SetSharedMemory(std::move(shared_memory));
//             return true;
//         }
//
//         case mojo_base::mojom::BigBufferDataView::Tag::kInvalidBuffer:
//         // Always reject an invalid buffer in deserialization.
//         return false;
//     }
//
//     return false;
// }

bool mojo::StructTraits<blink::mojom::SerializedBlobDataView, scoped_refptr<blink::BlobDataHandle>>::Read(
    blink::mojom::SerializedBlobDataView, scoped_refptr<blink::BlobDataHandle>* handle)
{
    DebugBreak();
    return false;
}

// bool mojo::StructTraits<mojo_base::mojom::UnguessableTokenDataView, base::UnguessableToken>::Read(
//     mojo_base::mojom::UnguessableTokenDataView view, base::UnguessableToken* token)
// {
//     DebugBreak();
//     return false;
// }

// bool mojo::StructTraits<blink::mojom::MessagePortDescriptorDataView, blink::MessagePortDescriptor>::Read(
//     blink::mojom::MessagePortDescriptorDataView, blink::MessagePortDescriptor*)
// {
//     DebugBreak();
//     return false;
// }
// WTF::Vector<scoped_refptr<blink::BlobDataHandle>, 0, WTF::PartitionAllocator>
// mojo::StructTraits<blink::mojom::CloneableMessageDataView, blink::BlinkCloneableMessage>::blobs(struct blink::BlinkCloneableMessage&)
// {
//     *(int*)1 = 1;
//     return WTF::Vector<scoped_refptr<blink::BlobDataHandle>, 0, WTF::PartitionAllocator>();
// }
//
//// bool mojo::StructTraits<blink::mojom::TransferableMessageDataView, blink::TransferableMessage>::Read(
////     blink::mojom::TransferableMessageDataView view, blink::TransferableMessage* msg)
//// {
////
//// }
//
// base::UnguessableToken mojo::StructTraits<blink::mojom::MessagePortDescriptorDataView, blink::MessagePortDescriptor>::id(blink::MessagePortDescriptor&)
// {
//     *(int*)1 = 1;
//     return base::UnguessableToken();
// }
//
// mojo::ScopedHandleBase<mojo::MessagePipeHandle> mojo::StructTraits<blink::mojom::MessagePortDescriptorDataView, blink::MessagePortDescriptor>::pipe_handle(blink::MessagePortDescriptor&)
// {
//     *(int*)1 = 1;
//     return mojo::ScopedHandleBase<mojo::MessagePipeHandle>();
// }
//
// uint64_t mojo::StructTraits<blink::mojom::MessagePortDescriptorDataView, blink::MessagePortDescriptor>::sequence_number(blink::MessagePortDescriptor&)
// {
//     *(int*)1 = 1;
//     return 0;
// }
//
// mojo_base::BigBufferView mojo::StructTraits<blink::mojom::CloneableMessageDataView, blink::CloneableMessage>::encoded_message(blink::CloneableMessage&)
// {
//     *(int*)1 = 1;
//     return mojo_base::BigBufferView();
// }

void mojo::Connector::ResumeIncomingMethodCallProcessing(void)
{
}

bool mojo::StructTraits<blink::mojom::SerializedBlobDataView, mojo::StructPtr<blink::mojom::SerializedBlob>>::Read(
    blink::mojom::SerializedBlobDataView view, mojo::StructPtr<blink::mojom::SerializedBlob>* out)
{
    DebugBreak();
    return false;
}

bool mojo::StructTraits<blink::mojom::SerializedArrayBufferContentsDataView, mojo::StructPtr<blink::mojom::SerializedArrayBufferContents>>::Read(
    blink::mojom::SerializedArrayBufferContentsDataView view, mojo::StructPtr<blink::mojom::SerializedArrayBufferContents>* out)
{
    DebugBreak();
    return false;
}

bool mojo::StructTraits<blink::mojom::UserActivationSnapshotDataView, mojo::InlinedStructPtr<blink::mojom::UserActivationSnapshot>>::Read(
    blink::mojom::UserActivationSnapshotDataView view, mojo::InlinedStructPtr<blink::mojom::UserActivationSnapshot>* out)
{
    DebugBreak();
    return false;
}

void mojo::Connector::PauseIncomingMethodCallProcessing(void)
{
}

base::StringPiece mojo::StructTraits<url::mojom::UrlDataView, GURL>::url(GURL const&) {
    *(int*)1 = 1;
    return base::StringPiece();
}

uint32_t
mojo::StructTraits<skia::mojom::ImageInfoDataView, SkImageInfo>::height(SkImageInfo const&)
{
    *(int*)1 = 1;
    return 0;
}

uint32_t mojo::StructTraits<skia::mojom::ImageInfoDataView, SkImageInfo>::width(SkImageInfo const&)
{
    *(int*)1 = 1;
    return 0;
}

mojo_base::BigBufferView mojo::StructTraits<skia::mojom::BitmapN32DataView, SkBitmap>::pixel_data(SkBitmap const&)
{
    *(int*)1 = 1;
    return mojo_base::BigBufferView();
}

// base::span<const uint8_t> mojo::UnionTraits<mojo_base::mojom::BigBufferDataView, mojo_base::BigBuffer>::bytes(const mojo_base::BigBuffer& buffer)
// {
//     //*(int*)1 = 1;
//     return buffer.byte_span();
//     //return base::span<const uint8_t>();
// }
//
// base::span<const uint8_t> mojo::UnionTraits<mojo_base::mojom::BigBufferDataView, mojo_base::BigBufferView>::bytes(mojo_base::BigBufferView const&)
// {
//     *(int*)1 = 1;
//     return base::span<const uint8_t>();
// }

absl::optional<std::vector<float>> mojo::StructTraits<skia::mojom::ImageInfoDataView, SkImageInfo>::color_to_xyz_matrix(SkImageInfo const&)
{
    *(int*)1 = 1;
    return absl::nullopt;
}
absl::optional<std::vector<float>> mojo::StructTraits<skia::mojom::ImageInfoDataView, SkImageInfo>::color_transfer_function(SkImageInfo const&)
{
    *(int*)1 = 1;
    return absl::nullopt;
}

network::mojom::blink::TimingAllowOrigin::TimingAllowOrigin()
    : tag_(Tag::kSerializedOrigins)
{
    data_.serialized_origins = new WTF::Vector<WTF::String>;
}

network::mojom::blink::TimingAllowOrigin::~TimingAllowOrigin()
{
    DestroyActive();
}

void network::mojom::blink::TimingAllowOrigin::DestroyActive()
{
    switch (tag_) {
        case Tag::kSerializedOrigins:
            delete data_.serialized_origins;
            break;
        case Tag::kAll:
            break;
    }
}

void network::mojom::blink::TimingAllowOrigin::set_all(uint8_t all)
{
    if (tag_ != Tag::kAll) {
        DestroyActive();
        tag_ = Tag::kAll;
    }
    data_.all = all;
}

mojo::WaitSet::~WaitSet(void)
{
    *(int*)1 = 1;
}

mojo::SyncHandleRegistry::~SyncHandleRegistry(void)
{
    *(int*)1 = 1;
}

scoped_refptr<mojo::internal::MultiplexRouter> mojo::internal::MultiplexRouter::CreateAndStartReceiving(
    mojo::ScopedHandleBase<mojo::MessagePipeHandle>, mojo::internal::MultiplexRouter::Config, bool, scoped_refptr<base::SequencedTaskRunner>, char const*)
{
    *(int*)1 = 1;
    return nullptr;
}

std::unique_ptr<void, mojo::internal::Unmapper> mojo::SharedBufferHandle::Map(uint64_t size) const
{
    *(int*)1 = 1;
    return nullptr;
}

mojo::HandleSignalTracker::~HandleSignalTracker(void)
{
    *(int*)1 = 1;
}

mojo::internal::MessageQuotaChecker::~MessageQuotaChecker(void)
{
    *(int*)1 = 1;
}

mojo::SyncHandleWatcher::~SyncHandleWatcher(void)
{
    *(int*)1 = 1;
}

void blink::MojoInterfaceRequestEvent::Trace(class cppgc::Visitor*) const
{
    *(int*)1 = 1;
}

// bool mojo::internal::IsHandleOrInterfaceValid(struct mojo::internal::Handle_Data const&)
// {
//     *(int*)1 = 1;
//     return false;
// }
// bool mojo::internal::IsHandleOrInterfaceValid(struct mojo::internal::Interface_Data const&)
// {
//     *(int*)1 = 1;
//     return false;
// }

bool mojo::internal::ReportSerializationWarning(enum mojo::internal::ValidationError)
{
    *(int*)1 = 1;
    return false;
}

bool blink::mojom::PageState::Validate(void const*, class mojo::internal::ValidationContext*)
{
    return true;
}

skia::mojom::AlphaType mojo::EnumTraits<skia::mojom::AlphaType, SkAlphaType>::ToMojom(enum SkAlphaType)
{
    *(int*)1 = 1;
    return skia::mojom::AlphaType::UNKNOWN;
}

bool blink::mojom::blink::TransferableMessage::Validate(void const*, mojo::internal::ValidationContext*)
{
    //*(int*)1 = 1;
    return true;
}

std::basic_ostream<char, struct std::char_traits<char>>& network::mojom::operator<<(
    std::basic_ostream<char, std::char_traits<char>>& other, network::mojom::CSPDirectiveName) {
    *(int*)1 = 1;
    return other;
}

WTF::StringUTF8Adaptor
mojo::StringTraits<WTF::String>::GetUTF8(const WTF::String& str)
{
    return WTF::StringUTF8Adaptor(WTF::StringView(str));
}

bool ::blink::mojom::blink::DataElementBlob::Validate(const void* data, mojo::internal::ValidationContext* validation_context)
{
    //return Data_::Validate(data, validation_context);
    *(int*)1 = 1;
    return false;
}

bool ::blink::mojom::internal::DataElement_Data::Validate(const void* data, mojo::internal::ValidationContext* validation_context, bool inlined)
{
    *(int*)1 = 1;
    return false;
}

// blink::mojom::blink::DataElement::DataElement()
//     : tag_(Tag::kBytes)
// {
//     data_.bytes = new DataElementBytesPtr;
// }

//blink::mojom::blink::DataElement::~DataElement() { DestroyActive(); }

void ::blink::mojom::blink::DataElement::set_bytes(::blink::mojom::blink::DataElementBytesPtr bytes)
{
    if (tag_ == Tag::kBytes) {
        *(data_.bytes) = std::move(bytes);
    } else {
        DestroyActive();
        tag_ = Tag::kBytes;
        data_.bytes = new DataElementBytesPtr(std::move(bytes));
    }
}

void ::blink::mojom::blink::DataElement::set_file(::blink::mojom::blink::DataElementFilePtr file)
{
    if (tag_ == Tag::kFile) {
        *(data_.file) = std::move(file);
    } else {
        DestroyActive();
        tag_ = Tag::kFile;
        data_.file = new ::blink::mojom::blink::DataElementFilePtr(std::move(file));
    }
}

void ::blink::mojom::blink::DataElement::set_blob(::blink::mojom::blink::DataElementBlobPtr blob)
{
    if (tag_ == Tag::kBlob) {
        *(data_.blob) = std::move(blob);
    } else {
        DestroyActive();
        tag_ = Tag::kBlob;
        data_.blob = new DataElementBlobPtr(std::move(blob));
    }
}

void ::blink::mojom::blink::DataElement::DestroyActive()
{
    switch (tag_) {
    case Tag::kBytes:
        delete data_.bytes;
        break;
    case Tag::kFile:
        delete data_.file;
        break;
    case Tag::kBlob:
        delete data_.blob;
        break;
    }
}

bool blink::mojom::blink::DataElement::Validate(const void* data, mojo::internal::ValidationContext* validation_context)
{
    return Data_::Validate(data, validation_context, false);
}
//const char BytesProvider::Name_[] = "blink.mojom.BytesProvider";

// blink::mojom::Element::Element(void)
// {
//     *(int*)1 = 1;
// }
// blink::mojom::blink::DataElement::DataElement(void) { *(int*)1 = 1; }
// void blink::mojom::blink::DataElement::set_blob(mojo::StructPtr<::blink::mojom::blink::DataElementBlob>) { *(int*)1 = 1; }
// void blink::mojom::blink::DataElement::set_bytes(mojo::StructPtr<::blink::mojom::blink::DataElementBytes>) { *(int*)1 = 1; }
// void blink::mojom::blink::DataElement::set_file(mojo::StructPtr<::blink::mojom::blink::DataElementFile>) { *(int*)1 = 1; }
// blink::mojom::blink::FileChooserFileInfo::FileChooserFileInfo(void) { *(int*)1 = 1; }

// blink::mojom::blink::FileChooserResult::FileChooserResult()
//     : files(),
//     base_directory() {}
//
// blink::mojom::blink::FileChooserResult::FileChooserResult(
//     WTF::Vector<blink::mojom::blink::FileChooserFileInfoPtr> files_in,
//     const ::base::FilePath& base_directory_in)
//     : files(std::move(files_in)),
//     base_directory(std::move(base_directory_in)) {}
//
// blink::mojom::blink::FileChooserResult::~FileChooserResult() = default;

// blink::mojom::blink::PermissionDescriptorExtension::PermissionDescriptorExtension(void)
// {
//     *(int*)1 = 1;
// }

void blink::mojom::Element::set_bytes(std::vector<unsigned char, std::allocator<unsigned char>>)
{
    *(int*)1 = 1;
}
void blink::mojom::Element::set_file(mojo::StructPtr<::blink::mojom::File>)
{
    *(int*)1 = 1;
}

// void blink::mojom::blink::FileChooserFileInfo::set_file_system(mojo::StructPtr<::blink::mojom::blink::FileSystemFileInfo>) { *(int*)1 = 1; }
// void blink::mojom::blink::FileChooserFileInfo::set_native_file(mojo::StructPtr<::blink::mojom::blink::NativeFileInfo>) { *(int*)1 = 1; }

// blink::mojom::blink::FileChooserFileInfo::FileChooserFileInfo()
//     : tag_(Tag::kNativeFile)
// {
//     data_.native_file = new NativeFileInfoPtr;
// }
//
// blink::mojom::blink::FileChooserFileInfo::~FileChooserFileInfo()
// {
//     DestroyActive();
// }

void blink::mojom::DataElement::DestroyActive(void)
{
    DebugBreak();
}

//bool __thiscall blink::mojom::blink::FileSystemManager::RegisterBlob

void blink::mojom::blink::FileChooserFileInfo::set_native_file(mojo::StructPtr<::blink::mojom::blink::NativeFileInfo> native_file)
{
    if (tag_ == Tag::kNativeFile) {
        *(data_.native_file) = std::move(native_file);
    } else {
        DestroyActive();
        tag_ = Tag::kNativeFile;
        data_.native_file = new mojo::StructPtr<::blink::mojom::blink::NativeFileInfo>(std::move(native_file));
    }
}
void blink::mojom::blink::FileChooserFileInfo::set_file_system(mojo::StructPtr<::blink::mojom::blink::FileSystemFileInfo> file_system)
{
    if (tag_ == Tag::kFileSystem) {
        *(data_.file_system) = std::move(file_system);
    } else {
        DestroyActive();
        tag_ = Tag::kFileSystem;
        data_.file_system = new mojo::StructPtr<::blink::mojom::blink::FileSystemFileInfo>(std::move(file_system));
    }
}

void blink::mojom::blink::FileChooserFileInfo::DestroyActive()
{
    switch (tag_) {
    case Tag::kNativeFile:
        delete data_.native_file;
        break;
    case Tag::kFileSystem:
        delete data_.file_system;
        break;
    }
}

// void blink::mojom::blink::PermissionDescriptorExtension::set_storage_access(mojo::StructPtr<::blink::mojom::blink::StorageAccessPermissionDescriptor>)
// {
//     *(int*)1 = 1;
// }

void mojo::ReportBadMessage(base::StringPiece)
{
    *(int*)1 = 1;
}

void mojo::internal::SerializeInterfaceInfo(
    mojo::ScopedHandleBase<mojo::MessagePipeHandle>, unsigned int, mojo::Message&, struct mojo::internal::Interface_Data&)
{
    *(int*)1 = 1;
}

mojo::ScopedHandleBase<mojo::SharedBufferHandle> __cdecl mojo::SharedBufferHandle::Create(uint64_t)
{
    *(int*)1 = 1;
    return mojo::ScopedHandleBase<mojo::SharedBufferHandle>();
}
// mojo::ScopedHandleBase<mojo::SharedBufferHandle> __cdecl mojo::StructTraits<mojo_base::mojom::BigBufferSharedMemoryRegionDataView,
//     mojo_base::internal::BigBufferSharedMemoryRegion>::buffer_handle(mojo_base::internal::BigBufferSharedMemoryRegion&)
// {
//     *(int*)1 = 1;
//     return mojo::ScopedHandleBase<mojo::SharedBufferHandle>();
// }
//
// mojo_base::internal::BigBufferSharedMemoryRegion& __cdecl mojo::UnionTraits<mojo_base::mojom::BigBufferDataView, mojo_base::BigBuffer>::shared_memory(mojo_base::BigBuffer&)
// {
//     *(int*)1 = 1;
//     mojo_base::internal::BigBufferSharedMemoryRegion* reg = new mojo_base::internal::BigBufferSharedMemoryRegion();
//     return *reg;
// }
//
// mojo_base::internal::BigBufferSharedMemoryRegion& __cdecl mojo::UnionTraits<mojo_base::mojom::BigBufferDataView, mojo_base::BigBufferView>::shared_memory(mojo_base::BigBufferView&)
// {
//     *(int*)1 = 1;
//     mojo_base::internal::BigBufferSharedMemoryRegion* reg = new mojo_base::internal::BigBufferSharedMemoryRegion();
//     return *reg;
// }

mojo::internal::ValidationContext::ValidationContext(const void* data, size_t data_num_bytes, size_t num_handles, size_t num_associated_endpoint_handles,
    mojo::Message* message, const char* description, int stack_depth, mojo::internal::ValidationContext::ValidatorType validator_type)
    : message_(message)
    , description_(description)
    , validator_type_(validator_type)
    , data_begin_(reinterpret_cast<uintptr_t>(data))
    , data_end_(data_begin_ + data_num_bytes)
    , handle_begin_(0)
    , handle_end_(static_cast<uint32_t>(num_handles))
    , associated_endpoint_handle_begin_(0)
    , associated_endpoint_handle_end_(static_cast<uint32_t>(num_associated_endpoint_handles))
    , stack_depth_(stack_depth)
{
}

mojo::internal::ValidationContext::~ValidationContext(void)
{
}

bool mojo::internal::ReceiverImplBase::HasAssociatedInterfaces(void) const
{
    *(int*)1 = 1;
    return false;
}

bool mojo::internal::ReceiverImplBase::WaitForIncomingMethodCall(void)
{
    OutputDebugStringA("mojo::internal::ReceiverImplBase::WaitForIncomingMethodCall not impl\n");
    return true;
}

bool mojo::internal::MultiplexRouter::HasAssociatedEndpoints(void) const
{
    *(int*)1 = 1;
    return false;
}

void blink::MojoHandle::close(void)
{
    *(int*)1 = 1;
}
void blink::MojoInterfaceInterceptor::start(class blink::ExceptionState&)
{
    *(int*)1 = 1;
}
void blink::MojoInterfaceInterceptor::stop(void)
{
    *(int*)1 = 1;
}

//

void mojo::Message::SerializeHandles(mojo::AssociatedGroupController*)
{
    OutputDebugStringA("mojo::Message::SerializeHandles not impl\n");
}

// void mojo::internal::AssociatedReceiverBase::FlushForTesting(void) { *(int*)1 = 1; }
// void mojo::internal::AssociatedReceiverBase::ResetWithReason(unsigned int, base::BasicStringPiece<char, std::char_traits<char>>) { *(int*)1 = 1; }
// void mojo::internal::AssociatedReceiverBase::SetFilter(std::unique_ptr<mojo::MessageFilter, std::default_delete<mojo::MessageFilter>>) { *(int*)1 = 1; }
// void mojo::internal::AssociatedReceiverBase::reset(void)
// {
//     impl_ = nullptr;
// }

void mojo::internal::ReceiverImplBase::EnableBatchDispatch(void)
{

}
void mojo::internal::ReceiverImplBase::FlushForTesting(void)
{
    *(int*)1 = 1;
}
void mojo::internal::ReceiverImplBase::PauseIncomingMethodCallProcessing(void)
{
    *(int*)1 = 1;
}
void mojo::internal::ReceiverImplBase::ResumeIncomingMethodCallProcessing(void)
{
    *(int*)1 = 1;
}
void mojo::internal::ReceiverImplBase::SetFilter(std::unique_ptr<mojo::MessageFilter, std::default_delete<mojo::MessageFilter>>)
{
}

bool mojo::MessageReceiver::PrefersSerializedMessages(void)
{
    *(int*)1 = 1;
    return false;
}

// mojo_base::mojom::internal::BigBuffer_Data::BigBuffer_Tag mojo::UnionTraits<mojo_base::mojom::BigBufferDataView, mojo_base::BigBuffer>::GetTag(
//     const mojo_base::BigBuffer& buffer)
// {
//     switch (buffer.storage_type()) {
//     case mojo_base::BigBuffer::StorageType::kBytes:
//         return mojo_base::mojom::BigBufferDataView::Tag::kBytes;
//     case mojo_base::BigBuffer::StorageType::kSharedMemory:
//         return mojo_base::mojom::BigBufferDataView::Tag::kSharedMemory;
//     case mojo_base::BigBuffer::StorageType::kInvalidBuffer:
//         return mojo_base::mojom::BigBufferDataView::Tag::kInvalidBuffer;
//     }
//     return mojo_base::mojom::BigBufferDataView::Tag::kBytes;
// }
//
// mojo_base::mojom::internal::BigBuffer_Data::BigBuffer_Tag mojo::UnionTraits<mojo_base::mojom::BigBufferDataView, mojo_base::BigBufferView>::GetTag(mojo_base::BigBufferView const&)
// {
//     *(int*)1 = 1;
//     return mojo_base::mojom::internal::BigBuffer_Data::BigBuffer_Tag::kBytes;
// }
//
// unsigned int __cdecl mojo::StructTraits<mojo_base::mojom::BigBufferSharedMemoryRegionDataView, mojo_base::internal::BigBufferSharedMemoryRegion>::size(
//     mojo_base::internal::BigBufferSharedMemoryRegion const&)
// {
//     *(int*)1 = 1;
//     return 0;
// }

char const* mojo::internal::ValidationErrorToString(enum mojo::internal::ValidationError)
{
    *(int*)1 = 1;
    return "";
}

media_session::mojom::blink::MediaPosition::MediaPosition(double, class base::TimeDelta, class base::TimeDelta, class base::TimeTicks, bool)
{
    *(int*)1 = 1;
}

// viz::mojom::blink::BundledFrameSubmissionData::BundledFrameSubmissionData(void)
// {
//     *(int*)1 = 1;
// }

unsigned int blink::MojoWatcher::cancel(void)
{
    *(int*)1 = 1;
    return 0;
}

unsigned int blink::MojoHandle::writeMessage(
    //     blink::V8UnionArrayBufferOrArrayBufferView const*,
    //     blink::HeapVector<
    //         cppgc::internal::BasicMember<blink::MojoHandle, cppgc::internal::StrongMemberTag, cppgc::internal::DijkstraWriteBarrierPolicy, cppgc::internal::DisabledCheckingPolicy>,
    //         0> const&
    const blink::V8BufferSource* buffer, const blink::HeapVector<blink::Member<blink::MojoHandle>>& handles)
{
    *(int*)1 = 1;
    return 0;
}

blink::MojoInterfaceRequestEvent::~MojoInterfaceRequestEvent(void)
{
    *(int*)1 = 1;
}

blink::mojom::internal::CloneableMessage_Data::CloneableMessage_Data()
    : header_({ sizeof(*this), 0 })
{
}
blink::mojom::internal::DEPRECATED_FileSystemFile_Data::DEPRECATED_FileSystemFile_Data(void)
    : header_({ sizeof(*this), 0 })
{
}
blink::mojom::internal::File_Data::File_Data(void)
    : header_({ sizeof(*this), 0 })
{
}
blink::mojom::internal::FrameState_Data::FrameState_Data(void)
    : header_({ sizeof(*this), 0 })
{
}
blink::mojom::internal::HttpBody_Data::HttpBody_Data(void)
    : header_({ sizeof(*this), 0 })
{
}
blink::mojom::internal::MessagePortDescriptor_Data::MessagePortDescriptor_Data(void)
    : header_({ sizeof(*this), 0 })
{
}
blink::mojom::internal::PageState_Data::PageState_Data(void)
    : header_({ sizeof(*this), 0 })
{
}
blink::mojom::internal::RequestBody_Data::RequestBody_Data(void)
    : header_({ sizeof(*this), 0 })
{
}
blink::mojom::internal::SerializedArrayBufferContents_Data::SerializedArrayBufferContents_Data(void)
    : header_({ sizeof(*this), 0 })
{
}
blink::mojom::internal::SerializedBlob_Data::SerializedBlob_Data(void)
    : header_({ sizeof(*this), 0 })
{
}
blink::mojom::internal::TaskAttributionId_Data::TaskAttributionId_Data(void)
    : header_({ sizeof(*this), 0 })
{
}
blink::mojom::internal::TransferableMessage_Data::TransferableMessage_Data(void)
    : header_({ sizeof(*this), 0 })
{
}
blink::mojom::internal::UserActivationSnapshot_Data::UserActivationSnapshot_Data(void)
    : header_({ sizeof(*this), 0 })
{
}
blink::mojom::internal::ViewState_Data::ViewState_Data(void)
    : header_({ sizeof(*this), 0 })
{
}
gfx::mojom::internal::PointF_Data::PointF_Data(void)
    : header_({ sizeof(*this), 0 })
{
}
gfx::mojom::internal::Point_Data::Point_Data(void)
    : header_({ sizeof(*this), 0 })
{
}
mojo_base::mojom::internal::BigBufferSharedMemoryRegion_Data::BigBufferSharedMemoryRegion_Data(void)
    : header_({ sizeof(*this), 0 })
{
}
mojo_base::mojom::internal::String16_Data::String16_Data(void)
    : header_({ sizeof(*this), 0 })
{
}
mojo_base::mojom::internal::Time_Data::Time_Data(void)
    : header_({ sizeof(*this), 0 })
{
}
mojo_base::mojom::internal::UnguessableToken_Data::UnguessableToken_Data(void)
    : header_({ sizeof(*this), 0 })
{
}
skia::mojom::internal::BitmapN32ImageInfo_Data::BitmapN32ImageInfo_Data(void)
    : header_({ sizeof(*this), 0 })
{
}
skia::mojom::internal::BitmapN32_Data::BitmapN32_Data(void)
    : header_({ sizeof(*this), 0 })
{
}
url::mojom::internal::Origin_Data::Origin_Data(void)
    : header_({ sizeof(*this), 0 })
{
}

// void viz::mojom::blink::BundledFrameSubmissionData::set_did_delete_shared_bitmap(struct gpu::Mailbox const&)
// {
//     *(int*)1 = 1;
// }
void viz::mojom::blink::BundledFrameSubmissionData::set_did_not_produce_frame(struct viz::BeginFrameAck const&)
{
    *(int*)1 = 1;
}
void viz::mojom::blink::BundledFrameSubmissionData::set_frame(class mojo::StructPtr<class viz::mojom::blink::BundledCompositorFrame>)
{
    *(int*)1 = 1;
}

// network::mojom::AllowCSPFromHeaderValue::AllowCSPFromHeaderValue()
//     : tag_(Tag::kAllowStar)
// {
//     data_.allow_star = bool();
// }
// 
// network::mojom::AllowCSPFromHeaderValue::~AllowCSPFromHeaderValue()
// {
//     DestroyActive();
// }

void network::mojom::AllowCSPFromHeaderValue::set_allow_star(bool allow_star)
{
    if (tag_ != Tag::kAllowStar) {
        DestroyActive();
        tag_ = Tag::kAllowStar;
    }
    data_.allow_star = allow_star;
}

void network::mojom::AllowCSPFromHeaderValue::set_origin(const ::url::Origin& origin)
{
    if (tag_ == Tag::kOrigin) {
        *(data_.origin) = std::move(origin);
    } else {
        DestroyActive();
        tag_ = Tag::kOrigin;
        data_.origin = new ::url::Origin(std::move(origin));
    }
}

void network::mojom::AllowCSPFromHeaderValue::set_error_message(const std::string& error_message)
{
    if (tag_ == Tag::kErrorMessage) {
        *(data_.error_message) = std::move(error_message);
    } else {
        DestroyActive();
        tag_ = Tag::kErrorMessage;
        data_.error_message = new std::string(std::move(error_message));
    }
}

void network::mojom::AllowCSPFromHeaderValue::DestroyActive()
{
    switch (tag_) {
        case Tag::kAllowStar:
            break;
        case Tag::kOrigin:
            delete data_.origin;
            break;
        case Tag::kErrorMessage:
            delete data_.error_message;
            break;
    }
}

void network::mojom::blink::AllowCSPFromHeaderValue::set_allow_star(bool allow_star)
{
    if (tag_ != Tag::kAllowStar) {
        DestroyActive();
        tag_ = Tag::kAllowStar;
    }
    data_.allow_star = allow_star;
}
void network::mojom::blink::AllowCSPFromHeaderValue::set_error_message(WTF::String const& error_message)
{
    if (tag_ == Tag::kErrorMessage) {
        *(data_.error_message) = std::move(error_message);
    } else {
        DestroyActive();
        tag_ = Tag::kErrorMessage;
        data_.error_message = new WTF::String(std::move(error_message));
    }
}
void network::mojom::blink::AllowCSPFromHeaderValue::set_origin(scoped_refptr<::blink::SecurityOrigin const> const& origin)
{
    if (tag_ == Tag::kOrigin) {
        *(data_.origin) = std::move(origin);
    } else {
        DestroyActive();
        tag_ = Tag::kOrigin;
        data_.origin = new ::scoped_refptr<const ::blink::SecurityOrigin>(std::move(origin));
    }
}

void network::mojom::TimingAllowOrigin::set_serialized_origins(std::vector<std::string> serialized_origins)
{
    if (tag_ == Tag::kSerializedOrigins) {
        *(data_.serialized_origins) = std::move(serialized_origins);
    } else {
        DestroyActive();
        tag_ = Tag::kSerializedOrigins;
        data_.serialized_origins = new std::vector<std::string>(std::move(serialized_origins));
    }
}

void network::mojom::TimingAllowOrigin::set_all(uint8_t all)
{
    if (tag_ != Tag::kAll) {
        DestroyActive();
        tag_ = Tag::kAll;
    }
    data_.all = all;
}

void network::mojom::blink::TimingAllowOrigin::set_serialized_origins(WTF::Vector<WTF::String, 0, WTF::PartitionAllocator> serialized_origins)
{
    if (tag_ == Tag::kSerializedOrigins) {
        *(data_.serialized_origins) = std::move(serialized_origins);
    } else {
        DestroyActive();
        tag_ = Tag::kSerializedOrigins;
        data_.serialized_origins = new WTF::Vector<WTF::String>(std::move(serialized_origins));
    }
}

network::mojom::TimingAllowOrigin::~TimingAllowOrigin(void)
{
    DestroyActive();
}

void network::mojom::TimingAllowOrigin::DestroyActive()
{
    switch (tag_) {

        case Tag::kSerializedOrigins:

            delete data_.serialized_origins;
            break;
        case Tag::kAll:

            break;
    }
}


// unsigned int mojo::Wait(mojo::Handle, unsigned int, unsigned int, MojoHandleSignalsState*)
// {
//     *(int*)1 = 1;
//     return 0;
// }

bool viz::mojom::FrameSinkManager::DestroyCompositorFrameSink(const viz::FrameSinkId&)
{
    *(int*)1 = 1;
    return false;
}

// bool viz::mojom::FrameSinkManager::EvictBackBuffer(unsigned int)
// {
//     *(int*)1 = 1;
//     return false;
// }

bool viz::mojom::CompositorFrameSink::SubmitCompositorFrameSync(const ::viz::LocalSurfaceId& local_surface_id, ::viz::CompositorFrame frame,
    absl::optional<::viz::HitTestRegionList> hit_test_region_list, uint64_t submit_time, std::vector<::viz::ReturnedResource>* out_resources)
{
    *(int*)1 = 1;
    return false;
}

bool viz::mojom::DisplayPrivate::DisableSwapUntilResize(void)
{
    *(int*)1 = 1;
    return false;
}

mojo::native::NativeStruct::~NativeStruct(void) = default;
mojo::native::SerializedHandle::~SerializedHandle(void) = default;

const char device::mojom::blink::ScreenOrientation::Name_[] = "device.mojom.blink.ScreenOrientation";
const char network::mojom::blink::URLLoader::Name_[] = "network.mojom.blink.URLLoader";

namespace blink {
namespace mojom {

const char AssociatedInterfaceProvider::Name_[] = "blink.mojom.AssociatedInterfaceProvider";
const char Blob::Name_[] = "blink.mojom.AssociatedInterfaceProvider";
const char BlobRegistry::Name_[] = "blink.mojom.BlobRegistry";
const char BrowserInterfaceBroker::Name_[] = "blink.mojom.BrowserInterfaceBroker";
const char CodeCacheHost::Name_[] = "blink.mojom.CodeCacheHost";
const char FileSystemAccessTransferToken::Name_[] = "blink.mojom.FileSystemAccessTransferToken";
const char ResourceLoadInfoNotifier::Name_[] = "blink.mojom.ResourceLoadInfoNotifier";
const char BlobReaderClient::Name_[] = "blink.mojom.BlobReaderClient";

namespace blink {
//const char QuotaChangeListener::Name_[] = "blink.mojom.QuotaChangeListener";
const char QuotaManagerHost::Name_[] = "blink.mojom.QuotaManagerHost";
const char AnchorElementInteractionHost::Name_[] = "blink.mojom.AnchorElementInteractionHost";
const char AnchorElementMetricsHost::Name_[] = "blink.mojom.AnchorElementMetricsHost";
const char AnnotationAgentContainer::Name_[] = "blink.mojom.AnnotationAgentContainer";
const char AnnotationAgentHost::Name_[] = "blink.mojom.AnnotationAgentHost";
//const char AttributionDataHost::Name_[] = "blink.mojom.AttributionDataHost";
const char BackForwardCacheControllerHost::Name_[] = "blink.mojom.BackForwardCacheControllerHost";
const char Blob::Name_[] = "blink.mojom.Blob";
const char BlobRegistry::Name_[] = "blink.mojom.BlobRegistry";
const char BlobURLStore::Name_[] = "blink.mojom.BlobURLStore";
const char BlobURLToken::Name_[] = "blink.mojom.BlobURLToken";
const char ClipboardHost::Name_[] = "blink.mojom.ClipboardHost";
const char ContentSecurityNotifier::Name_[] = "blink.mojom.ContentSecurityNotifier";
const char ContextMenuClient::Name_[] = "blink.mojom.ContextMenuClient";
//const char ConversionHost::Name_[] = "blink.mojom.ConversionHost";
const char DWriteFontProxy::Name_[] = "blink.mojom.DWriteFontProxy";
const char DateTimeChooser::Name_[] = "blink.mojom.DateTimeChooser";
const char DedicatedWorkerHost::Name_[] = "blink.mojom.DedicatedWorkerHost";
const char DevToolsAgentHost::Name_[] = "blink.mojom.DevToolsAgentHost";
const char DevToolsFrontend::Name_[] = "blink.mojom.DevToolsFrontend";
const char DevToolsFrontendHost::Name_[] = "blink.mojom.DevToolsFrontendHost";
const char DevToolsSessionHost::Name_[] = "blink.mojom.DevToolsSessionHost";
const char DisplayCutoutClient::Name_[] = "blink.mojom.DisplayCutoutClient";
const char DisplayCutoutHost::Name_[] = "blink.mojom.DisplayCutoutHost";
const char EmbeddedFrameSinkProvider::Name_[] = "blink.mojom.EmbeddedFrameSinkProvider";
const char EyeDropperChooser::Name_[] = "blink.mojom.EyeDropperChooser";
const char FencedFrameOwnerHost::Name_[] = "blink.mojom.FencedFrameOwnerHost";
const char FileChooser::Name_[] = "blink.mojom.FileChooser";
const char FileSystemAccessDataTransferToken::Name_[] = "blink.mojom.FileSystemAccessDataTransferToken";
const char FileUtilitiesHost::Name_[] = "blink.mojom.FileUtilitiesHost";
const char FindInPage::Name_[] = "blink.mojom.FindInPage";
const char FindInPageClient::Name_[] = "blink.mojom.FindInPageClient";
const char FrameWidgetHost::Name_[] = "blink.mojom.FrameWidgetHost";
const char FullscreenVideoElementHandler::Name_[] = "blink.mojom.FullscreenVideoElementHandler";
const char GpuDataManager::Name_[] = "blink.mojom.GpuDataManager";
//const char HighPriorityLocalFrame::Name_[] = "blink.mojom.HighPriorityLocalFrame";
const char KeepAliveHandleFactory::Name_[] = "blink.mojom.KeepAliveHandleFactory";
const char LocalFrame::Name_[] = "blink.mojom.LocalFrame";
const char LocalFrameHost::Name_[] = "blink.mojom.LocalFrameHost";
const char LocalMainFrame::Name_[] = "blink.mojom.LocalMainFrame";
const char LocalMainFrameHost::Name_[] = "blink.mojom.LocalMainFrameHost";
const char MimeRegistry::Name_[] = "blink.mojom.MimeRegistry";
const char NoStatePrefetchProcessor::Name_[] = "blink.mojom.NoStatePrefetchProcessor";
const char OomInterventionHost::Name_[] = "blink.mojom.OomInterventionHost";
const char PauseSubresourceLoadingHandle::Name_[] = "blink.mojom.PauseSubresourceLoadingHandle";
// const char PendingBeacon::Name_[] = "blink.mojom.PendingBeacon";
// const char PendingBeaconHost::Name_[] = "blink.mojom.PendingBeaconHost";
const char PermissionService::Name_[] = "blink.mojom.PermissionService";
const char PluginRegistry::Name_[] = "blink.mojom.PluginRegistry";
const char PointerLockContext::Name_[] = "blink.mojom.PointerLockContext";
const char PolicyContainerHost::Name_[] = "blink.mojom.PolicyContainerHost";
const char PopupWidgetHost::Name_[] = "blink.mojom.PopupWidgetHost";
// const char Portal::Name_[] = "blink.mojom.Portal";
// const char PortalHost::Name_[] = "blink.mojom.PortalHost";
const char ProgressClient::Name_[] = "blink.mojom.ProgressClient";
const char RemoteFrameHost::Name_[] = "blink.mojom.RemoteFrameHost";
const char RemoteMainFrameHost::Name_[] = "blink.mojom.RemoteMainFrameHost";
const char RendererPreferenceWatcher::Name_[] = "blink.mojom.RendererPreferenceWatcher";
const char ReportingServiceProxy::Name_[] = "blink.mojom.ReportingServiceProxy";
const char ServiceWorkerWorkerClientRegistry::Name_[] = "blink.mojom.ServiceWorkerWorkerClientRegistry";
const char SharedWorkerConnector::Name_[] = "blink.mojom.SharedWorkerConnector";
const char SharedWorkerHost::Name_[] = "blink.mojom.SharedWorkerHost";
const char SpeculationHost::Name_[] = "blink.mojom.SpeculationHost";
const char SurfaceEmbedder::Name_[] = "blink.mojom.SurfaceEmbedder";
const char TextFragmentReceiver::Name_[] = "blink.mojom.TextFragmentReceiver";
const char TextSuggestionHost::Name_[] = "blink.mojom.TextSuggestionHost";
const char WakeLockService::Name_[] = "blink.mojom.WakeLockService";
const char WidgetHost::Name_[] = "blink.mojom.WidgetHost";
const char WidgetInputHandlerHost::Name_[] = "blink.mojom.WidgetInputHandlerHost";
const char WorkerContentSettingsProxy::Name_[] = "blink.mojom.WorkerContentSettingsProxy";
const char DiskAllocator::Name_[] = "blink.mojom.DiskAllocator";
const char WidgetInputHandler::Name_[] = "blink.mojom.WidgetInputHandler";
const char LeakDetector::Name_[] = "blink.mojom.LeakDetector";
const char CrashMemoryMetricsReporter::Name_[] = "blink.mojom.CrashMemoryMetricsReporter";
const char OomIntervention::Name_[] = "blink.mojom.OomIntervention";
const char V8DetailedMemoryReporter::Name_[] = "blink.mojom.V8DetailedMemoryReporter";
const char AnnotationAgent::Name_[] = "blink.mojom.AnnotationAgent";
const char TextSuggestionBackend::Name_[] = "blink.mojom.TextSuggestionBackend";
const char BlobReaderClient::Name_[] = "blink.mojom.BlobReaderClient";
const char ReportingObserver::Name_[] = "blink.mojom.ReportingObserver";
const char CloseListener::Name_[] = "blink.mojom.CloseListener";
const char PopupMenuClient::Name_[] = "blink.mojom.PopupMenuClient";
const char DevToolsAgent::Name_[] = "blink.mojom.DevToolsAgent";
const char DevToolsSession::Name_[] = "blink.mojom.DevToolsSession";
const char SharedWorkerClient::Name_[] = "blink.mojom.SharedWorkerClient";
const char BytesProvider::Name_[] = "blink.mojom.BytesProvider";
const char EmbeddedFrameSinkClient::Name_[] = "blink.mojom.EmbeddedFrameSinkClient";
const char ServiceWorkerWorkerClient::Name_[] = "blink.mojom.ServiceWorkerWorkerClient";
const char SubresourceLoaderUpdater::Name_[] = "blink.mojom.SubresourceLoaderUpdater";
const char WidgetCompositor::Name_[] = "blink.mojom.WidgetCompositor";

const char FrameWidget::Name_[] = "blink.mojom.FrameWidget";
const char FrameWidgetInputHandler::Name_[] = "blink.mojom.FrameWidgetInputHandler";
const char PageBroadcast::Name_[] = "blink.mojom.PageBroadcast";
//const char PortalClient::Name_[] = "blink.mojom.PortalClient";
const char RemoteFrame::Name_[] = "blink.mojom.RemoteFrame";
const char RemoteMainFrame::Name_[] = "blink.mojom.RemoteMainFrame";
const char Widget::Name_[] = "blink.mojom.Widget";

} // blink
} // mojom
} // blink

const char viz::mojom::VSyncParameterObserver::Name_[] = "media.mojom.VSyncParameterObserver";
const char media::mojom::blink::MediaPlayer::Name_[] = "media.mojom.MediaPlayer";
const char viz::mojom::CompositorFrameSinkClient::Name_[] = "viz.mojom.blink.CompositorFrameSinkClient";
const char viz::mojom::blink::FrameSinkBundleClient::Name_[] = "viz.mojom.blink.FrameSinkBundleClient";
const char viz::mojom::blink::CompositorFrameSinkClient::Name_[] = "viz.mojom.blink.CompositorFrameSinkClient";
const char device::mojom::blink::TimeZoneMonitorClient::Name_[] = "device.mojom.blink.TimeZoneMonitorClient";
const char viz::mojom::blink::InputTargetClient::Name_[] = "viz.mojom.blink.InputTargetClient";
const char cc::mojom::blink::RenderFrameMetadataObserver::Name_[] = "cc.mojom.blink.RenderFrameMetadataObserver";
const char viz::mojom::FrameSinkBundle::Name_[] = "viz.mojom.FrameSinkBundle";
const char viz::mojom::BeginFrameObserver::Name_[] = "viz.mojom.BeginFrameObserver";
const char viz::mojom::VideoDetectorObserver::Name_[] = "viz.mojom.VideoDetectorObserver";
const char viz::mojom::FrameSinkBundleClient::Name_[] = "viz.mojom.FrameSinkBundleClient";
//const char viz::mojom::VizDebugOutput::Name_[] = "viz.mojom.VizDebugOutput";
const char viz::mojom::ExternalBeginFrameController::Name_[] = "viz.mojom.ExternalBeginFrameController";

const char network::mojom::URLLoaderNetworkServiceObserver::Name_[] = "network.mojom.URLLoaderNetworkServiceObserver";
const char network::mojom::WebBundleHandle::Name_[] = "network.mojom.WebBundleHandle";

//const char blink::test::mojom::blink::AttributionReportingAutomation::Name_[] = "blink.mojom.AttributionReportingAutomation";
const char cc::mojom::blink::RenderFrameMetadataObserverClient::Name_[] = "blink.mojom.RenderFrameMetadataObserverClient";
const char device::mojom::blink::TimeZoneMonitor::Name_[] = "device.blink.mojom.TimeZoneMonitor";
const char device::mojom::blink::WakeLock::Name_[] = "device.blink.mojom.WakeLock";
const char media::mojom::WatchTimeRecorder::Name_[] = "media.mojom.WatchTimeRecorder";
const char media::mojom::blink::MediaPlayerHost::Name_[] = "media.mojom.blink.MediaPlayerHost";
const char media::mojom::blink::MediaPlayerObserver::Name_[] = "media.mojom.blink.MediaPlayerObserver";
const char network::mojom::DataPipeGetter::Name_[] = "network.mojom.DataPipeGetter";
const char network::mojom::URLLoader::Name_[] = "network.mojom.URLLoader";
const char network::mojom::URLLoaderClient::Name_[] = "network.mojom.URLLoaderClient";
const char network::mojom::URLLoaderFactory::Name_[] = "network.mojom.URLLoaderFactory";
const char network::mojom::blink::ChunkedDataPipeGetter::Name_[] = "network.mojom.ChunkedDataPipeGetter";
const char network::mojom::blink::CrossOriginOpenerPolicyReporter::Name_[] = "network.mojom.CrossOriginOpenerPolicyReporter";
const char network::mojom::blink::DataPipeGetter::Name_[] = "network.mojom.DataPipeGetter";
const char network::mojom::blink::RestrictedCookieManager::Name_[] = "network.mojom.RestrictedCookieManager";
const char network::mojom::blink::TrustTokenQueryAnswerer::Name_[] = "network.mojom.TrustTokenQueryAnswerer";
const char network::mojom::blink::URLLoaderFactory::Name_[] = "network.mojom.URLLoaderFactory";
const char network::mojom::blink::WebBundleHandle::Name_[] = "network.mojom.WebBundleHandle";
const char performance_manager::mojom::blink::DocumentCoordinationUnit::Name_[] = "performance_manager.mojom.DocumentCoordinationUnit";
const char performance_manager::mojom::blink::ProcessCoordinationUnit::Name_[] = "performance_manager.mojom.ProcessCoordinationUnit";
const char viz::mojom::DisplayClient::Name_[] = "viz.mojom.DisplayClient";
const char viz::mojom::CompositorFrameSink::Name_[] = "viz.mojom.CompositorFrameSink";
const char viz::mojom::blink::CompositorFrameSink::Name_[] = "viz.mojom.CompositorFrameSink";
const char viz::mojom::blink::FrameSinkBundle::Name_[] = "viz.mojom.FrameSinkBundle";
const char viz::mojom::DisplayPrivate::Name_[] = "viz.mojom.DisplayPrivate";
const char viz::mojom::FrameSinkManager::Name_[] = "viz.mojom.FrameSinkManager";
const char viz::mojom::FrameSinkManagerClient::Name_[] = "viz.mojom.FrameSinkManagerClient";
const char viz::mojom::LayeredWindowUpdater::Name_[] = "viz.mojom.LayeredWindowUpdater";
const char viz::mojom::FrameSinkVideoConsumer::Name_[] = "viz.mojom.FrameSinkVideoConsumer";
const char viz::mojom::FrameSinkVideoCapturer::Name_[] = "viz.mojom.FrameSinkVideoCapturer";
const char viz::mojom::FrameSinkVideoCaptureOverlay::Name_[] = "viz.mojom.FrameSinkVideoCaptureOverlay";

const char blink::mojom::blink::SessionStorageNamespace::Name_[] = "blink.mojom.SessionStorageNamespace";
const char blink::mojom::blink::DomStorageProvider::Name_[] = "blink.mojom.DomStorageProvider";
const char blink::mojom::blink::DomStorage::Name_[] = "blink.mojom.DomStorage";
const char blink::mojom::blink::DomStorageClient::Name_[] = "blink.mojom.DomStorageClient";
const char blink::mojom::blink::StorageAreaObserver::Name_[] = "blink.mojom.StorageAreaObserver";
const char blink::mojom::blink::StorageArea::Name_[] = "blink.mojom.StorageArea";

const char blink::mojom::blink::BroadcastChannelClient::Name_[] = "blink.mojom.BroadcastChannelClient";
const char blink::mojom::blink::BroadcastChannelProvider::Name_[] = "blink.mojom.BroadcastChannelProvider";
//const char blink::mojom::blink::KeepAliveHandle::Name_[] = "blink.mojom.KeepAliveHandle";
const char blink::mojom::blink::CodeCacheHost::Name_[] = "blink.mojom.CodeCacheHost";

const char blink::mojom::blink::WebSocketConnector::Name_[] = "blink.mojom.WebSocketConnector";
const char network::mojom::blink::WebSocket::Name_[] = "network.mojom.WebSocket";
const char network::mojom::blink::WebSocketClient::Name_[] = "network.mojom.WebSocketClient";
const char network::mojom::blink::WebSocketHandshakeClient::Name_[] = "network.mojom.WebSocketHandshakeClient";

const char blink::mojom::blink::FileBackedBlobFactory::Name_[] = "blink.mojom.blink.FileBackedBlobFactory";
const char payments::mojom::blink::PaymentHandlerResponseCallback::Name_[] = "payments.mojom.blink.PaymentHandlerResponseCallback";
const char blink::mojom::blink::DevicePostureClient::Name_[] = "blink.mojom.blink.DevicePostureProvider";
const char blink::mojom::blink::DevicePostureProvider::Name_[] = "blink.mojom.blink.DevicePostureProvider";
const char viz::mojom::VizDebugOutput::Name_[] = "viz.mojom.VizDebugOutput";
const char viz::mojom::LayerContextClient::Name_[] = "viz.mojom.LayerContextClient";
const char viz::mojom::LayerContext::Name_[] = "viz.mojom.LayerContext";
const char viz::mojom::FrameSinksMetricsRecorder::Name_[] = "viz.mojom.FrameSinksMetricsRecorder";
const char viz::mojom::FrameSinkManagerTestApi::Name_[] = "viz.mojom.FrameSinkManagerTestApi";
const char network::mojom::TrustTokenAccessObserver::Name_[] = "network.mojom.TrustTokenAccessObserver";
const char network::mojom::SharedDictionaryAccessObserver::Name_[] = "network.mojom.SharedDictionaryAccessObserver";
const char network::mojom::DevToolsObserver::Name_[] = "network.mojom.DevToolsObserver";
const char network::mojom::CrossOriginEmbedderPolicyReporter::Name_[] = "network.mojom.CrossOriginEmbedderPolicyReporter";
const char network::mojom::CookieAccessObserver::Name_[] = "network.mojom.CookieAccessObserver";
const char network::mojom::blink::CookieChangeListener::Name_[] = "network.mojom.blink.CookieChangeListener";
const char network::mojom::AcceptCHFrameObserver::Name_[] = "network.mojom.AcceptCHFrameObserver";
//const char network::CrossOriginResourcePolicy::kHeaderName[] = "xxxxxx";
const char gfx::mojom::DelegatedInkPointRenderer::Name_[] = "gfx.mojom.DelegatedInkPointRenderer";
//const char blink::USB::kSupplementName[] = "xxxxxx";
const char blink::mojom::FetchLaterLoaderFactory::Name_[] = "blink.mojom.FetchLaterLoaderFactory";
const char blink::mojom::blink::WorkletDevToolsHost::Name_[] = "blink.mojom.blink.WorkletDevToolsHost";
const char blink::mojom::blink::ServiceWorkerStreamCallback::Name_[] = "blink.mojom.blink.ServiceWorkerStreamCallback";
const char blink::mojom::blink::ServiceWorkerRegistrationObjectHost::Name_[] = "blink.mojom.blink.ServiceWorkerRegistrationObjectHost";
const char blink::mojom::blink::ServiceWorkerRegistrationObject::Name_[] = "blink.mojom.blink.ServiceWorkerRegistrationObject";
const char blink::mojom::blink::ServiceWorkerObjectHost::Name_[] = "blink.mojom.blink.ServiceWorkerObjectHost";
const char blink::mojom::blink::ServiceWorkerObject::Name_[] = "blink.mojom.blink.ServiceWorkerObject";
const char blink::mojom::blink::ServiceWorkerInstalledScriptsManagerHost::Name_[] = "blink.mojom.blink.ServiceWorkerInstalledScriptsManagerHost";
const char blink::mojom::blink::ServiceWorkerInstalledScriptsManager::Name_[] = "blink.mojom.blink.ServiceWorkerInstalledScriptsManager";
const char blink::mojom::blink::ServiceWorkerHost::Name_[] = "blink.mojom.blink.ServiceWorkerHost";
const char blink::mojom::blink::ServiceWorkerFetchResponseCallback::Name_[] = "blink.mojom.blink.ServiceWorkerFetchResponseCallback";
const char blink::mojom::blink::ServiceWorker::Name_[] = "blink.mojom.blink.ServiceWorker";
const char blink::mojom::blink::RenderInputRouterClient::Name_[] = "blink.mojom.blink.RenderInputRouterClient";
const char blink::mojom::blink::PresentationConnection::Name_[] = "blink.mojom.blink.PresentationConnection";
const char blink::mojom::blink::PermissionObserver::Name_[] = "blink.mojom.blink.PermissionObserver";
const char blink::mojom::blink::OriginTrialStateHost::Name_[] = "blink.mojom.blink.OriginTrialStateHost";
const char blink::mojom::blink::NonAssociatedLocalFrameHost::Name_[] = "blink.mojom.blink.NonAssociatedLocalFrameHost";
const char blink::mojom::blink::LCPCriticalPathPredictorHost::Name_[] = "blink.mojom.blink.LCPCriticalPathPredictorHost";
const char blink::mojom::blink::KeepAliveHandle::Name_[] = "blink.mojom.blink.KeepAliveHandle";
const char blink::mojom::blink::IdleMonitor::Name_[] = "blink.mojom.blink.IdleMonitor";
const char blink::mojom::blink::IdleManager::Name_[] = "blink.mojom.blink.IdleManager";
const char blink::mojom::blink::FileSystemAccessTransferToken::Name_[] = "blink.mojom.blink.FileSystemAccessTransferToken";
const char blink::mojom::blink::FileSystemAccessManager::Name_[] = "blink.mojom.blink.FileSystemAccessManager";
const char blink::mojom::blink::FetchLaterLoader::Name_[] = "blink.mojom.blink.FetchLaterLoader";
const char blink::mojom::blink::EmbeddedPermissionControlClient::Name_[] = "blink.mojom.blink.EmbeddedPermissionControlClient";
// const char blink::mojom::blink::DevicePostureProvider::Name_[] = "xxxxxx";
// const char blink::mojom::blink::DevicePostureClient::Name_[] = "xxxxxx";
const char blink::mojom::blink::CookieStore::Name_[] = "blink.mojom.blink.CookieStore";
const char blink::mojom::blink::ControllerServiceWorker::Name_[] = "blink.mojom.blink.ControllerServiceWorker";
const char blink::mojom::blink::CallStackGenerator::Name_[] = "blink.mojom.blink.CallStackGenerator";
const char blink::mojom::blink::BrowserInterfaceBroker::Name_[] = "blink.mojom.blink.BrowserInterfaceBroker";
const char blink::mojom::blink::BackgroundFetchService::Name_[] = "blink.mojom.blink.BackgroundFetchService";
const char blink::mojom::blink::BackgroundFetchRegistrationService::Name_[] = "blink.mojom.blink.BackgroundFetchRegistrationService";
const char blink::mojom::blink::BackgroundFetchRegistrationObserver::Name_[] = "blink.mojom.blink.BackgroundFetchRegistrationObserver";
const char blink::mojom::blink::AssociatedInterfaceProvider::Name_[] = "blink.mojom.blink.AssociatedInterfaceProvider";
const char attribution_reporting::mojom::blink::DataHost::Name_[] = "attribution_reporting.mojom.blink.DataHost";
const char blink::mojom::blink::AttributionHost::Name_[] = "blink.mojom.blink.AttributionHost";