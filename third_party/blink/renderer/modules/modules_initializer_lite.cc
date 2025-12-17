// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.


#include "third_party/blink/renderer/modules/modules_initializer.h"

#include <memory>

#include "base/feature_list.h"
#include "base/task/thread_pool.h"
#include "base/files/file_util.h"
#include "build/android_buildflags.h"
#include "build/build_config.h"
#include "mojo/public/cpp/bindings/binder_map.h"
#include "third_party/blink/public/mojom/dom_storage/session_storage_namespace.mojom-blink.h"
#include "third_party/blink/public/mojom/filesystem/file_system.mojom-blink.h"
#include "third_party/blink/public/platform/file_path_conversion.h"
#include "third_party/blink/public/platform/interface_registry.h"
#include "third_party/blink/public/platform/web_security_origin.h"
#include "third_party/blink/public/platform/web_string.h"
#include "third_party/blink/public/web/web_local_frame_client.h"
#include "third_party/blink/public/web/web_view_client.h"
#include "third_party/blink/public/mojom/blob/data_element.mojom-blink.h"
#include "third_party/blink/renderer/bindings/modules/v8/module_bindings_initializer.h"
#include "third_party/blink/renderer/core/css/background_color_paint_image_generator.h"
#include "third_party/blink/renderer/core/css/clip_path_paint_image_generator.h"
#include "third_party/blink/renderer/core/css/css_paint_image_generator.h"
#include "third_party/blink/renderer/core/dom/document.h"
#include "third_party/blink/renderer/core/editing/suggestion/text_suggestion_backend_impl.h"
#include "third_party/blink/renderer/core/event_type_names.h"
#include "third_party/blink/renderer/core/exported/web_shared_worker_impl.h"
#include "third_party/blink/renderer/core/frame/local_frame.h"
#include "third_party/blink/renderer/core/frame/settings.h"
#include "third_party/blink/renderer/core/frame/web_local_frame_impl.h"
#include "third_party/blink/renderer/core/html/canvas/html_canvas_element.h"
#include "third_party/blink/renderer/core/html/media/html_media_element.h"
#include "third_party/blink/renderer/core/inspector/devtools_session.h"
#include "third_party/blink/renderer/core/inspector/inspector_media_context_impl.h"
#include "third_party/blink/renderer/core/loader/document_loader.h"
#include "third_party/blink/renderer/core/offscreencanvas/offscreen_canvas.h"
#include "third_party/blink/renderer/core/page/chrome_client.h"
#include "third_party/blink/renderer/core/page/page.h"
#include "third_party/blink/renderer/core/scheduler/task_attribution_tracker_impl.h"
#include "third_party/blink/renderer/modules/accessibility/ax_object_cache_impl.h"
#include "third_party/blink/renderer/modules/accessibility/inspector_accessibility_agent.h"
#include "third_party/blink/renderer/modules/app_banner/app_banner_controller.h"
#include "third_party/blink/renderer/modules/audio_output_devices/html_media_element_audio_output_device.h"
#include "third_party/blink/renderer/modules/cache_storage/inspector_cache_storage_agent.h"
#include "third_party/blink/renderer/modules/canvas/canvas2d/canvas_rendering_context_2d.h"
#include "third_party/blink/renderer/modules/canvas/imagebitmap/image_bitmap_rendering_context.h"
#include "third_party/blink/renderer/modules/canvas/offscreencanvas2d/offscreen_canvas_rendering_context_2d.h"
#include "third_party/blink/renderer/modules/content_extraction/inner_html_agent.h"
#include "third_party/blink/renderer/modules/content_extraction/inner_text_agent.h"
#include "third_party/blink/renderer/modules/csspaint/css_paint_image_generator_impl.h"
#include "third_party/blink/renderer/modules/csspaint/nativepaint/background_color_paint_image_generator_impl.h"
#include "third_party/blink/renderer/modules/csspaint/nativepaint/clip_path_paint_image_generator_impl.h"
#include "third_party/blink/renderer/modules/device_orientation/device_motion_controller.h"
#include "third_party/blink/renderer/modules/device_orientation/device_orientation_absolute_controller.h"
#include "third_party/blink/renderer/modules/device_orientation/device_orientation_controller.h"
#include "third_party/blink/renderer/modules/device_orientation/device_orientation_inspector_agent.h"
#include "third_party/blink/renderer/modules/document_metadata/document_metadata_server.h"
#include "third_party/blink/renderer/modules/document_picture_in_picture/picture_in_picture_controller_impl.h"
#include "third_party/blink/renderer/modules/encryptedmedia/html_media_element_encrypted_media.h"
#include "third_party/blink/renderer/modules/event_interface_modules_names.h"
#include "third_party/blink/renderer/modules/event_modules_factory.h"
#include "third_party/blink/renderer/modules/event_target_modules_names.h"
#include "third_party/blink/renderer/modules/exported/web_embedded_worker_impl.h"
#include "third_party/blink/renderer/modules/file_system_access/bucket_file_system_agent.h"
#include "third_party/blink/renderer/modules/filesystem/dragged_isolated_file_system_impl.h"
#include "third_party/blink/renderer/modules/filesystem/file_system_dispatcher.h"
//#include "third_party/blink/renderer/modules/gamepad/navigator_gamepad.h"
#include "third_party/blink/renderer/modules/image_downloader/image_downloader_impl.h"
#include "third_party/blink/renderer/modules/indexed_db_names.h"
#include "third_party/blink/renderer/modules/indexeddb/inspector_indexed_db_agent.h"
#include "third_party/blink/renderer/modules/installation/installation_service_impl.h"
#include "third_party/blink/renderer/modules/launch/web_launch_service_impl.h"
#include "third_party/blink/renderer/modules/manifest/manifest_manager.h"
#include "third_party/blink/renderer/modules/media/audio/audio_renderer_sink_cache.h"
#include "third_party/blink/renderer/modules/media_capabilities_names.h"
#include "third_party/blink/renderer/modules/media_controls/media_controls_impl.h"
#include "third_party/blink/renderer/modules/mediasource/media_source_registry_impl.h"
// #include "third_party/blink/renderer/modules/peerconnection/peer_connection_tracker.h"
// #include "third_party/blink/renderer/modules/presentation/presentation.h"
#include "third_party/blink/renderer/modules/push_messaging/push_messaging_client.h"
#include "third_party/blink/renderer/modules/remoteplayback/html_media_element_remote_playback.h"
#include "third_party/blink/renderer/modules/remoteplayback/remote_playback.h"
#include "third_party/blink/renderer/modules/screen_details/screen_details.h"
#include "third_party/blink/renderer/modules/screen_details/window_screen_details.h"
#include "third_party/blink/renderer/modules/screen_orientation/screen_orientation_controller.h"
#include "third_party/blink/renderer/modules/service_worker/navigator_service_worker.h"
#include "third_party/blink/renderer/modules/speech/speech_synthesis.h"
#include "third_party/blink/renderer/modules/storage/dom_window_storage.h"
#include "third_party/blink/renderer/modules/storage/dom_window_storage_controller.h"
#include "third_party/blink/renderer/modules/storage/inspector_dom_storage_agent.h"
#include "third_party/blink/renderer/modules/storage/storage_namespace.h"
#include "third_party/blink/renderer/modules/webaudio/audio_graph_tracer.h"
#include "third_party/blink/renderer/modules/webaudio/inspector_web_audio_agent.h"
#include "third_party/blink/renderer/modules/webdatabase/database_client.h"
#include "third_party/blink/renderer/modules/webdatabase/inspector_database_agent.h"
#include "third_party/blink/renderer/modules/webdatabase/web_database_host.h"
#include "third_party/blink/renderer/modules/webdatabase/web_database_impl.h"
//#include "third_party/blink/renderer/modules/webgl/webgl2_rendering_context.h"
#include "third_party/blink/renderer/modules/webgl/webgl_rendering_context.h"
//#include "third_party/blink/renderer/modules/webgpu/gpu_canvas_context.h"
#include "third_party/blink/renderer/modules/worklet/animation_and_paint_worklet_thread.h"
#include "third_party/blink/renderer/platform/heap/garbage_collected.h"
#include "third_party/blink/renderer/platform/heap/persistent.h"
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"
#include "third_party/blink/renderer/platform/scheduler/public/thread_scheduler.h"
#include "third_party/blink/renderer/platform/widget/compositing/blink_categorized_worker_pool_delegate.h"
#include "third_party/blink/renderer/platform/widget/frame_widget.h"
#include "third_party/blink/renderer/platform/wtf/cross_thread_functional.h"
#include "third_party/blink/renderer/platform/wtf/functional.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
//#include "third_party/webrtc_overrides/init_webrtc.h"
#include "ui/accessibility/accessibility_features.h"

#if BUILDFLAG(IS_ANDROID)
#include "third_party/blink/public/platform/modules/video_capture/web_video_capture_impl_manager.h"
#include "third_party/blink/public/platform/platform.h"
#include "third_party/blink/public/web/modules/mediastream/web_media_stream_device_observer.h"
#include "third_party/blink/renderer/core/page/page_visibility_observer.h"
#include "third_party/blink/renderer/modules/remote_objects/remote_object_gateway_impl.h"
#endif
#include "content/renderer/RenderThreadImpl.h"
#include <windows.h>

namespace blink {
namespace {

// Controls whether media players use base::ThreadPool or (legacy) the
// CategorizedWorkerPool, which predates the base thread pool.
BASE_FEATURE(kBlinkMediaPlayerUsesBaseThreadPool, "BlinkMediaPlayerUsesThreadPool", base::FEATURE_ENABLED_BY_DEFAULT);

// #if BUILDFLAG(IS_ANDROID)
//
// class SuspendCaptureObserver : public GarbageCollected<SuspendCaptureObserver>, public Supplement<Page>, public PageVisibilityObserver {
// public:
//     static const char kSupplementName[];
//
//     explicit SuspendCaptureObserver(Page& page)
//         : Supplement<Page>(page)
//         , PageVisibilityObserver(&page)
//     {
//     }
//
//     // PageVisibilityObserver overrides:
//     void PageVisibilityChanged() override
//     {
//         // TODO(crbug.com/487935): We don't yet suspend video capture devices for
//         // OOPIFs.
//         WebLocalFrameImpl* frame = WebLocalFrameImpl::FromFrame(DynamicTo<LocalFrame>(GetPage()->MainFrame()));
//         if (!frame)
//             return;
//         WebMediaStreamDeviceObserver* media_stream_device_observer = frame->Client()->MediaStreamDeviceObserver();
//         if (!media_stream_device_observer)
//             return;
//         // Don't suspend media capture devices if page visibility is
//         // PageVisibilityState::kHiddenButPainting (e.g. Picture-in-Picture).
//         // TODO(crbug.com/1339252): Add tests.
//         bool suspend = (GetPage()->GetVisibilityState() == mojom::blink::PageVisibilityState::kHidden);
//         MediaStreamDevices video_devices = media_stream_device_observer->GetNonScreenCaptureDevices();
//         Platform::Current()->GetVideoCaptureImplManager()->SuspendDevices(video_devices, suspend);
//     }
//
//     void Trace(Visitor* visitor) const override
//     {
//         Supplement<Page>::Trace(visitor);
//         PageVisibilityObserver::Trace(visitor);
//     }
// };
//
// const char SuspendCaptureObserver::kSupplementName[] = "SuspendCaptureObserver";
// #endif // BUILDFLAG(IS_ANDROID)

} // namespace

void ModulesInitializer::Initialize()
{
    // Strings must be initialized before calling CoreInitializer::init().
    const unsigned kModulesStaticStringsCount
        = event_interface_names::kModulesNamesCount + event_target_names::kModulesNamesCount + indexed_db_names::kNamesCount;
    StringImpl::ReserveStaticStringsCapacityForSize(kModulesStaticStringsCount + StringImpl::AllStaticStrings().size());

    OutputDebugStringA("ModulesInitializer::Initialize not impl\n");
    event_interface_names::InitModules();
    event_target_names::InitModules();
    Document::RegisterEventFactory(EventModulesFactory::Create());
    ModuleBindingsInitializer::Init();
    indexed_db_names::Init();
    media_capabilities_names::Init();
    //     AXObjectCache::Init(AXObjectCacheImpl::Create);
    //     DraggedIsolatedFileSystem::Init(DraggedIsolatedFileSystemImpl::PrepareForDataObject);
    //     CSSPaintImageGenerator::Init(CSSPaintImageGeneratorImpl::Create);
    //     BackgroundColorPaintImageGenerator::Init(BackgroundColorPaintImageGeneratorImpl::Create);
    //     ClipPathPaintImageGenerator::Init(ClipPathPaintImageGeneratorImpl::Create);
    //     WebDatabaseHost::GetInstance().Init();
    //     MediaSourceRegistryImpl::Init();
    //     if (::features::IsTextBasedAudioDescriptionEnabled())
    //         SpeechSynthesisBase::Init(SpeechSynthesis::Create);

    CoreInitializer::Initialize();
    //
    //     // Canvas context types must be registered with the HTMLCanvasElement.
    HTMLCanvasElement::RegisterRenderingContextFactory(std::make_unique<CanvasRenderingContext2D::Factory>());
    //     HTMLCanvasElement::RegisterRenderingContextFactory(std::make_unique<WebGLRenderingContext::Factory>());
    //     HTMLCanvasElement::RegisterRenderingContextFactory(std::make_unique<WebGL2RenderingContext::Factory>());
    HTMLCanvasElement::RegisterRenderingContextFactory(std::make_unique<ImageBitmapRenderingContext::Factory>());
    //     HTMLCanvasElement::RegisterRenderingContextFactory(std::make_unique<GPUCanvasContext::Factory>());
    //
    //     // OffscreenCanvas context types must be registered with the OffscreenCanvas.
    OffscreenCanvas::RegisterRenderingContextFactory(std::make_unique<OffscreenCanvasRenderingContext2D::Factory>());
    //     OffscreenCanvas::RegisterRenderingContextFactory(std::make_unique<WebGLRenderingContext::Factory>());
    //     OffscreenCanvas::RegisterRenderingContextFactory(std::make_unique<WebGL2RenderingContext::Factory>());
    OffscreenCanvas::RegisterRenderingContextFactory(std::make_unique<ImageBitmapRenderingContext::Factory>());
    //     OffscreenCanvas::RegisterRenderingContextFactory(std::make_unique<GPUCanvasContext::Factory>());
    
    //ThreadScheduler::Current()->InitializeTaskAttributionTracker(std::make_unique<scheduler::TaskAttributionTrackerImpl>());
    V8PerIsolateData::SetTaskAttributionTrackerFactory(&scheduler::TaskAttributionTrackerImpl::Create);
}

void ModulesInitializer::InitLocalFrame(LocalFrame& frame) const
{
//     AssociatedInterfaceProvider* associatedInterfaceProvider = frame.GetRemoteNavigationAssociatedInterfaces();
//     content::RenderThreadImpl::get()->OverrideAssociatedInterfaceProvider(associatedInterfaceProvider);

    //     if (frame.IsMainFrame()) {
    //         frame.GetInterfaceRegistry()->AddInterface(WTF::BindRepeating(&DocumentMetadataServer::BindReceiver, WrapWeakPersistent(&frame)));
    //     }
    //     frame.GetInterfaceRegistry()->AddAssociatedInterface(WTF::BindRepeating(&WebLaunchServiceImpl::BindReceiver, WrapWeakPersistent(&frame)));
    //
    //     frame.GetInterfaceRegistry()->AddInterface(WTF::BindRepeating(&InstallationServiceImpl::BindReceiver, WrapWeakPersistent(&frame)));
    //     // TODO(dominickn): This interface should be document-scoped rather than
    //     // frame-scoped, as the resulting banner event is dispatched to
    //     // frame()->document().
    //     frame.GetInterfaceRegistry()->AddInterface(WTF::BindRepeating(&AppBannerController::BindReceiver, WrapWeakPersistent(&frame)));
    //     frame.GetInterfaceRegistry()->AddInterface(WTF::BindRepeating(&TextSuggestionBackendImpl::Bind, WrapWeakPersistent(&frame)));
    // #if BUILDFLAG(IS_ANDROID)
    //     frame.GetInterfaceRegistry()->AddInterface(WTF::BindRepeating(&RemoteObjectGatewayFactoryImpl::Bind, WrapWeakPersistent(&frame)));
    // #endif // BUILDFLAG(IS_ANDROID)
    //
    //     frame.GetInterfaceRegistry()->AddInterface(WTF::BindRepeating(&PeerConnectionTracker::BindToFrame, WrapCrossThreadWeakPersistent(&frame)));
}

void ModulesInitializer::InstallSupplements(LocalFrame& frame) const
{
    //     DCHECK(WebLocalFrameImpl::FromFrame(&frame)->Client());
    //     InspectorAccessibilityAgent::ProvideTo(&frame);
    //     ImageDownloaderImpl::ProvideTo(frame);
    //     AudioRendererSinkCache::InstallWindowObserver(*frame.DomWindow());
}

MediaControls* ModulesInitializer::CreateMediaControls(HTMLMediaElement& media_element, ShadowRoot& shadow_root) const
{
    return MediaControlsImpl::Create(media_element, shadow_root);
}

PictureInPictureController* ModulesInitializer::CreatePictureInPictureController(Document& document) const
{
    //return MakeGarbageCollected<PictureInPictureControllerImpl>(document);
    OutputDebugStringA("ModulesInitializer::CreatePictureInPictureController not impl\n");
    return nullptr;
}

void ModulesInitializer::InitInspectorAgentSession(
    DevToolsSession* session, bool allow_view_agents, InspectorDOMAgent* dom_agent, InspectedFrames* inspected_frames, Page* page) const
{
    //     session->CreateAndAppend<InspectorIndexedDBAgent>(inspected_frames, session->V8Session());
    //     session->CreateAndAppend<DeviceOrientationInspectorAgent>(inspected_frames);
    //     session->CreateAndAppend<InspectorDOMStorageAgent>(inspected_frames);
    //     session->CreateAndAppend<InspectorAccessibilityAgent>(inspected_frames, dom_agent);
    //     session->CreateAndAppend<InspectorWebAudioAgent>(page);
    //     if (allow_view_agents) {
    //         session->CreateAndAppend<InspectorDatabaseAgent>(page);
    //         session->CreateAndAppend<InspectorCacheStorageAgent>(inspected_frames);
    //     }
}

void ModulesInitializer::OnClearWindowObjectInMainWorld(Document& document, const Settings& settings) const
{
    //     LocalDOMWindow& window = *document.domWindow();
    //     DeviceMotionController::From(window);
    //     DeviceOrientationController::From(window);
    //     DeviceOrientationAbsoluteController::From(window);
    //     NavigatorGamepad::From(*window.navigator());
    //
    //     // TODO(nhiroki): Figure out why ServiceWorkerContainer needs to be eagerly
    //     // initialized.
    //     if (!document.IsInitialEmptyDocument())
    //         NavigatorServiceWorker::From(window);
    //
    //     DOMWindowStorageController::From(window);
    //     if (RuntimeEnabledFeatures::PresentationEnabled() && settings.GetPresentationReceiver()) {
    //         // We eagerly create Presentation and associated PresentationReceiver so
    //         // that the frame creating the presentation can offer a connection to the
    //         // presentation receiver.
    //         Presentation::presentation(*window.navigator());
    //     }
    //     ManifestManager::From(window);
    //
    // #if BUILDFLAG(IS_ANDROID)
    //     LocalFrame* frame = window.GetFrame();
    //     DCHECK(frame);
    //     if (auto* gateway = RemoteObjectGatewayImpl::From(*frame))
    //         gateway->OnClearWindowObjectInMainWorld();
    // #endif // BUILDFLAG(IS_ANDROID)
}

std::unique_ptr<WebMediaPlayer> ModulesInitializer::CreateWebMediaPlayer(WebLocalFrameClient* web_frame_client, HTMLMediaElement& html_media_element,
    const WebMediaPlayerSource& source, WebMediaPlayerClient* media_player_client) const
{
    return nullptr;
    //     HTMLMediaElementEncryptedMedia& encrypted_media = HTMLMediaElementEncryptedMedia::From(html_media_element);
    //     WebString sink_id(HTMLMediaElementAudioOutputDevice::sinkId(html_media_element));
    //     MediaInspectorContextImpl* context_impl = MediaInspectorContextImpl::From(*To<LocalDOMWindow>(html_media_element.GetExecutionContext()));
    //     FrameWidget* frame_widget = html_media_element.GetDocument().GetFrame()->GetWidgetForLocalRoot();
    //     return base::WrapUnique(web_frame_client->CreateMediaPlayer(source, media_player_client, context_impl, &encrypted_media, encrypted_media.ContentDecryptionModule(), sink_id,
    //         frame_widget->GetLayerTreeSettings(),
    //         base::FeatureList::IsEnabled(kBlinkMediaPlayerUsesBaseThreadPool) ? base::ThreadPool::CreateTaskRunner(base::TaskTraits {}) : CategorizedWorkerPool::GetOrCreate()));
}

// class WebRemotePlaybackClientImpl : public blink::WebRemotePlaybackClient {
// public:
//     ~WebRemotePlaybackClientImpl() override
//     {
// 
//     }
// 
//     // Returns if the remote playback available for this media element.
//     bool RemotePlaybackAvailable() const override
//     {
//         return false;
//     }
// 
//     // Notifies the client that the source of the HTMLMediaElement has changed as
//     // well as if the new source is supported for remote playback.
//     void SourceChanged(const blink::WebURL&, bool is_source_supported) override
//     {
// 
//     }
// 
//     blink::WebString GetPresentationId() override
//     {
//         return  blink::WebString::FromASCII("123");
//     }
// };
// 
// WebRemotePlaybackClient* ModulesInitializer::CreateWebRemotePlaybackClient(HTMLMediaElement& html_media_element) const
// {
//     //return &RemotePlayback::From(html_media_element);
//     static WebRemotePlaybackClient* s_empty = nullptr;
//     if (s_empty)
//         return s_empty;
// 
//     s_empty = new WebRemotePlaybackClientImpl();
//     return s_empty;
// }

void ModulesInitializer::ProvideModulesToPage(Page& page, const SessionStorageNamespaceId& namespace_id) const
{
    //     MediaKeysController::ProvideMediaKeysTo(page);
    //     ::blink::ProvideContextFeaturesTo(page, std::make_unique<ContextFeaturesClientImpl>());
    //     ::blink::ProvideDatabaseClientTo(page, MakeGarbageCollected<DatabaseClient>());
    StorageNamespace::ProvideSessionStorageNamespaceTo(page, namespace_id);
    //     AudioGraphTracer::ProvideAudioGraphTracerTo(page);
    // #if BUILDFLAG(IS_ANDROID)
    //     page.ProvideSupplement(MakeGarbageCollected<SuspendCaptureObserver>(page));
    // #endif // BUILDFLAG(IS_ANDROID)
}

void ModulesInitializer::ForceNextWebGLContextCreationToFail() const
{
    // WebGLRenderingContext::ForceNextWebGLContextCreationToFail();
}

void ModulesInitializer::CollectAllGarbageForAnimationAndPaintWorkletForTesting() const
{
    AnimationAndPaintWorkletThread::CollectAllGarbageForTesting();
}

void ModulesInitializer::CloneSessionStorage(Page* clone_from_page, const SessionStorageNamespaceId& clone_to_namespace)
{
    StorageNamespace* storage_namespace = StorageNamespace::From(clone_from_page);
    if (storage_namespace)
        storage_namespace->CloneTo(WebString::FromLatin1(clone_to_namespace));
}

void ModulesInitializer::EvictSessionStorageCachedData(Page* page)
{
    StorageNamespace* storage_namespace = StorageNamespace::From(page);
    if (storage_namespace)
        storage_namespace->EvictSessionStorageCachedData();
}

void ModulesInitializer::DidChangeManifest(LocalFrame& frame)
{
    //ManifestManager::From(*frame.DomWindow())->DidChangeManifest();
}

void ModulesInitializer::NotifyOrientationChanged(LocalFrame& frame)
{
    //ScreenOrientationController::From(*frame.DomWindow())->NotifyOrientationChanged();
}

void ModulesInitializer::DidUpdateScreens(LocalFrame& frame, const display::ScreenInfos& screen_infos)
{
    //     auto* window = frame.DomWindow();
    //     if (auto* supplement = Supplement<LocalDOMWindow>::From<WindowScreens>(window)) {
    //         // screen_details() may be null if permission has not been granted.
    //         if (auto* screen_details = supplement->screen_details()) {
    //             screen_details->UpdateScreenInfos(window, screen_infos);
    //         }
    //     }
}

void ModulesInitializer::SetLocalStorageArea(LocalFrame& frame, mojo::PendingRemote<mojom::blink::StorageArea> local_storage_area)
{
    if (!frame.DomWindow())
        return;
    DOMWindowStorage::From(*frame.DomWindow()).InitLocalStorage(std::move(local_storage_area));
}

void ModulesInitializer::SetSessionStorageArea(LocalFrame& frame, mojo::PendingRemote<mojom::blink::StorageArea> session_storage_area)
{
    if (!frame.DomWindow())
        return;
    DOMWindowStorage::From(*frame.DomWindow()).InitSessionStorage(std::move(session_storage_area));
}

RemotePlaybackClient* ModulesInitializer::CreateRemotePlaybackClient(HTMLMediaElement& html_media_element) const
{
    return nullptr;
}

bool mojom::blink::FileSystemManager::Open(const ::scoped_refptr<const ::blink::SecurityOrigin>& origin, FileSystemType file_system_type, WTF::String* out_name,
    ::blink::KURL* out_root_url, ::base::File::Error* out_error_code)
{
    NOTREACHED();
    return false;
}

void mojom::blink::FileSystemManager::Open(const ::scoped_refptr<const ::blink::SecurityOrigin>& origin, FileSystemType file_system_type, OpenCallback callback)
{
    NOTREACHED();
}

bool mojom::blink::FileSystemManager::ResolveURL(const ::blink::KURL& filesystem_url, FileSystemInfoPtr* out_info, ::base::FilePath* out_file_path, bool* out_is_directory,
    ::base::File::Error* out_error_code)
{
    NOTREACHED();
    return false;
}

// using ResolveURLCallback = base::OnceCallback<void(FileSystemInfoPtr, const ::base::FilePath&, bool, ::base::File::Error)>;
void mojom::blink::FileSystemManager::ResolveURL(const ::blink::KURL& filesystem_url, ResolveURLCallback callback)
{
    NOTREACHED();
}

bool mojom::blink::FileSystemManager::Move(const ::blink::KURL& src_path, const ::blink::KURL& dest_path, ::base::File::Error* out_error_code)
{
    NOTREACHED();
    return false;
}

// using MoveCallback = base::OnceCallback<void(::base::File::Error)>;
void mojom::blink::FileSystemManager::Move(const ::blink::KURL& src_path, const ::blink::KURL& dest_path, MoveCallback callback)
{
    NOTREACHED();
}

bool mojom::blink::FileSystemManager::Copy(const ::blink::KURL& src_path, const ::blink::KURL& dest_path, ::base::File::Error* out_error_code)
{
    NOTREACHED();
    return false;
}

// using CopyCallback = base::OnceCallback<void(::base::File::Error)>;
void mojom::blink::FileSystemManager::Copy(const ::blink::KURL& src_path, const ::blink::KURL& dest_path, CopyCallback callback)
{
    NOTREACHED();
}

bool mojom::blink::FileSystemManager::Remove(const ::blink::KURL& path, bool recursive, ::base::File::Error* out_error_code)
{
    NOTREACHED();
    return false;
}

//using RemoveCallback = base::OnceCallback<void(::base::File::Error)>;
void mojom::blink::FileSystemManager::Remove(const ::blink::KURL& path, bool recursive, RemoveCallback callback)
{
    NOTREACHED();
}

bool mojom::blink::FileSystemManager::ReadMetadata(const ::blink::KURL& path, ::base::File::Info* out_file_info, ::base::File::Error* out_error_code)
{
    NOTREACHED();
    return false;
}

//using ReadMetadataCallback = base::OnceCallback<void(const ::base::File::Info&, ::base::File::Error)>;
void mojom::blink::FileSystemManager::ReadMetadata(const ::blink::KURL& path, ReadMetadataCallback callback)
{
    NOTREACHED();
}

bool mojom::blink::FileSystemManager::Create(const ::blink::KURL& path, bool exclusive, bool is_directory, bool recursive, ::base::File::Error* out_error_code)
{
    NOTREACHED();
    return false;
}

//using CreateCallback = base::OnceCallback<void(::base::File::Error)>;
void mojom::blink::FileSystemManager::Create(const ::blink::KURL& path, bool exclusive, bool is_directory, bool recursive, CreateCallback callback)
{
    NOTREACHED();
}

bool mojom::blink::FileSystemManager::Exists(const ::blink::KURL& path, bool is_directory, ::base::File::Error* out_error_code)
{
    NOTREACHED();
    return false;
}

//using ExistsCallback = base::OnceCallback<void(::base::File::Error)>;
void mojom::blink::FileSystemManager::Exists(const ::blink::KURL& path, bool is_directory, ExistsCallback callback)
{
    NOTREACHED();
}

void mojom::blink::FileSystemManager::ReadDirectory(const ::blink::KURL& path, ::mojo::PendingRemote<FileSystemOperationListener> listener)
{
    NOTREACHED();
}

bool mojom::blink::FileSystemManager::ReadDirectorySync(
    const ::blink::KURL& path, WTF::Vector<::filesystem::mojom::blink::DirectoryEntryPtr>* out_entries, ::base::File::Error* out_error_code)
{
    NOTREACHED();
    return false;
}

//using ReadDirectorySyncCallback = base::OnceCallback<void(WTF::Vector<::filesystem::mojom::blink::DirectoryEntryPtr>, ::base::File::Error)>;
void mojom::blink::FileSystemManager::ReadDirectorySync(const ::blink::KURL& path, ReadDirectorySyncCallback callback)
{
    NOTREACHED();
}

void Write(const ::blink::KURL& file_path, ::mojo::PendingRemote<::blink::mojom::blink::Blob> blob, int64_t position,
    ::mojo::PendingReceiver<mojom::blink::FileSystemCancellableOperation> op_receiver, ::mojo::PendingRemote<mojom::blink::FileSystemOperationListener> listener)
{
    NOTREACHED();
}

bool mojom::blink::FileSystemManager::WriteSync(const ::blink::KURL& file_path, ::mojo::PendingRemote<::blink::mojom::blink::Blob> blob, int64_t position, int64_t* out_byte_count,
    ::base::File::Error* out_error_code)
{
    NOTREACHED();
    return false;
}

//using WriteSyncCallback = base::OnceCallback<void(int64_t, ::base::File::Error)>;
void mojom::blink::FileSystemManager::WriteSync(
    const ::blink::KURL& file_path, ::mojo::PendingRemote<::blink::mojom::blink::Blob> blob, int64_t position, WriteSyncCallback callback)
{
    NOTREACHED();
}

//using TruncateCallback = base::OnceCallback<void(::base::File::Error)>;
void mojom::blink::FileSystemManager::Truncate(
    const ::blink::KURL& file_path, int64_t length, ::mojo::PendingReceiver<FileSystemCancellableOperation> op_receiver, TruncateCallback callback)
{
    NOTREACHED();
}

bool mojom::blink::FileSystemManager::TruncateSync(const ::blink::KURL& file_path, int64_t length, ::base::File::Error* out_error_code)
{
    NOTREACHED();
    return false;
}

//using TruncateSyncCallback = base::OnceCallback<void(::base::File::Error)>;
void mojom::blink::FileSystemManager::TruncateSync(const ::blink::KURL& file_path, int64_t length, TruncateSyncCallback callback)
{
    NOTREACHED();
}

bool mojom::blink::FileSystemManager::CreateSnapshotFile(const ::blink::KURL& file_path, ::base::File::Info* out_file_info, ::base::FilePath* out_platform_path,
    ::base::File::Error* out_error_code, ::mojo::PendingRemote<ReceivedSnapshotListener>* out_snapshot_listener)
{
    NOTREACHED();
    return false;
}

// using CreateSnapshotFileCallback
// = base::OnceCallback<void(const ::base::File::Info&, const ::base::FilePath&, ::base::File::Error, ::mojo::PendingRemote<ReceivedSnapshotListener>)>;
void mojom::blink::FileSystemManager::CreateSnapshotFile(const ::blink::KURL& file_path, CreateSnapshotFileCallback callback)
{
    NOTREACHED();
}

bool mojom::blink::FileSystemManager::GetPlatformPath(const ::blink::KURL& file_path, ::base::FilePath* out_platform_path)
{
    NOTREACHED();
    return false;
}

//using GetPlatformPathCallback = base::OnceCallback<void(const ::base::FilePath&)>;
void mojom::blink::FileSystemManager::GetPlatformPath(const ::blink::KURL& file_path, GetPlatformPathCallback callback)
{
    NOTREACHED();
}

bool mojom::blink::FileSystemManager::RegisterBlob(const WTF::String& content_type, const ::blink::KURL& url, uint64_t length,
    std::optional<::base::Time> expected_modification_time, ::scoped_refptr<::blink::BlobDataHandle>* out_blob)
{
    NOTREACHED();
    return false;
}

// using RegisterBlobCallback = base::OnceCallback<void(const ::scoped_refptr<::blink::BlobDataHandle>&)>;
void mojom::blink::FileSystemManager::RegisterBlob(const WTF::String& content_type, const ::blink::KURL& url, uint64_t length,
    std::optional<::base::Time> expected_modification_time, RegisterBlobCallback callback)
{
    NOTREACHED();
}

static String GetContentTypeFromFileName(const String& name, File::ContentTypeLookupPolicy policy)
{
    String type;
    int index = name.ReverseFind('.');
    if (index != -1) {
        if (policy == File::kWellKnownContentTypes)
            type = MIMETypeRegistry::GetWellKnownMIMETypeForExtension(name.Substring(index + 1));
        else {
            DCHECK(policy == File::kAllContentTypes);
            type = MIMETypeRegistry::GetMIMETypeForExtension(name.Substring(index + 1));
        }
    }
    return type;
}

bool GetFileSystemUrlSize(const String& path, int64_t* file_size)
{
    String path_temp = path;
    if (path_temp.StartsWith("file:///"))
        path_temp = path_temp.Right(path_temp.length() - sizeof("file:///") + 1);

    std::optional<int64_t> file_size_opt = base::GetFileSize(StringToFilePath(path_temp));
    if (file_size_opt.has_value()) {
        *file_size = file_size_opt.value();
        return true;
    }
    String path_escape = blink::DecodeURLEscapeSequences(path_temp, url::DecodeURLMode::kUTF8OrIsomorphic);
    file_size_opt = base::GetFileSize(StringToFilePath(path_escape));
    if (file_size_opt.has_value()) {
        *file_size = file_size_opt.value();
        return true;
    }
    return false;
}

class FileSystemManagerStub : public mojom::blink::FileSystemManager {
public:

    bool Open(const ::scoped_refptr<const ::blink::SecurityOrigin>& origin, ::blink::mojom::blink::FileSystemType file_system_type, WTF::String* out_name,
        ::blink::KURL* out_root_url, ::base::File::Error* out_error_code) override
    {
        DebugBreak();
        return false;
    }

    //using OpenCallback = base::OnceCallback<void(const WTF::String&, const ::blink::KURL&, ::base::File::Error)>;
    void Open(const ::scoped_refptr<const ::blink::SecurityOrigin>& origin, ::blink::mojom::blink::FileSystemType file_system_type, OpenCallback callback) override
    {
        DebugBreak();
    }


    bool ResolveURL(const ::blink::KURL& filesystem_url, ::blink::mojom::blink::FileSystemInfoPtr* out_info, ::base::FilePath* out_file_path, bool* out_is_directory,
        ::base::File::Error* out_error_code) override
    {
        DebugBreak();
        return false;
    }

    //using ResolveURLCallback = base::OnceCallback<void(FileSystemInfoPtr, const ::base::FilePath&, bool, ::base::File::Error)>;
    void ResolveURL(const ::blink::KURL& filesystem_url, ResolveURLCallback callback) override
    {
        DebugBreak();
    }

    bool Move(const ::blink::KURL& src_path, const ::blink::KURL& dest_path, ::base::File::Error* out_error_code) override
    {
        DebugBreak();
        return false;
    }

    //using MoveCallback = base::OnceCallback<void(::base::File::Error)>;
    void Move(const ::blink::KURL& src_path, const ::blink::KURL& dest_path, MoveCallback callback) override
    {
        DebugBreak();
    }

    bool Copy(const ::blink::KURL& src_path, const ::blink::KURL& dest_path, ::base::File::Error* out_error_code) override
    {
        DebugBreak();
        return false;
    }

    //using CopyCallback = base::OnceCallback<void(::base::File::Error)>;
    void Copy(const ::blink::KURL& src_path, const ::blink::KURL& dest_path, CopyCallback callback) override
    {
        DebugBreak();
    }

    bool Remove(const ::blink::KURL& path, bool recursive, ::base::File::Error* out_error_code) override
    {
        DebugBreak();
        return false;
    }

    //using RemoveCallback = base::OnceCallback<void(::base::File::Error)>;
    void Remove(const ::blink::KURL& path, bool recursive, RemoveCallback callback) override
    {
        DebugBreak();
    }

    bool ReadMetadata(const ::blink::KURL& path, ::base::File::Info* out_file_info, ::base::File::Error* out_error_code) override
    {
        DebugBreak();
        return false;
    }

    //using ReadMetadataCallback = base::OnceCallback<void(const ::base::File::Info&, ::base::File::Error)>;
    void ReadMetadata(const ::blink::KURL& path, ReadMetadataCallback callback) override
    {
        DebugBreak();
    }

    bool Create(const ::blink::KURL& path, bool exclusive, bool is_directory, bool recursive, ::base::File::Error* out_error_code) override
    {
        DebugBreak();
        return false;
    }

    //using CreateCallback = base::OnceCallback<void(::base::File::Error)>;
    void Create(const ::blink::KURL& path, bool exclusive, bool is_directory, bool recursive, CreateCallback callback) override
    {

        DebugBreak();
    }

    bool Exists(const ::blink::KURL& path, bool is_directory, ::base::File::Error* out_error_code) override
    {
        DebugBreak();
        return false;
    }

    //using ExistsCallback = base::OnceCallback<void(::base::File::Error)>;
    void Exists(const ::blink::KURL& path, bool is_directory, ExistsCallback callback) override
    {
        DebugBreak();
    }

    void ReadDirectory(const ::blink::KURL& path, ::mojo::PendingRemote<::blink::mojom::blink::FileSystemOperationListener> listener) override
    {
        DebugBreak();
    }

    bool ReadDirectorySync(
        const ::blink::KURL& path, WTF::Vector<::filesystem::mojom::blink::DirectoryEntryPtr>* out_entries, ::base::File::Error* out_error_code) override
    {
        DebugBreak();
        return false;
    }

    //using ReadDirectorySyncCallback = base::OnceCallback<void(WTF::Vector<::filesystem::mojom::blink::DirectoryEntryPtr>, ::base::File::Error)>;
    void ReadDirectorySync(const ::blink::KURL& path, ReadDirectorySyncCallback callback) override
    {
        DebugBreak();
    }

    void Write(const ::blink::KURL& file_path, ::mojo::PendingRemote<::blink::mojom::blink::Blob> blob, int64_t position,
        ::mojo::PendingReceiver<::blink::mojom::blink::FileSystemCancellableOperation> op_receiver, ::mojo::PendingRemote<::blink::mojom::blink::FileSystemOperationListener> listener)
        override
    {
        DebugBreak();
    }

    bool WriteSync(const ::blink::KURL& file_path, ::mojo::PendingRemote<::blink::mojom::blink::Blob> blob, int64_t position, int64_t* out_byte_count,
        ::base::File::Error* out_error_code) override
    {
        DebugBreak();
        return false;
    }

    //using WriteSyncCallback = base::OnceCallback<void(int64_t, ::base::File::Error)>;
    void WriteSync(
        const ::blink::KURL& file_path, ::mojo::PendingRemote<::blink::mojom::blink::Blob> blob, int64_t position, WriteSyncCallback callback)
        override
    {
        DebugBreak();
    }

    //using TruncateCallback = base::OnceCallback<void(::base::File::Error)>;
    void Truncate(
        const ::blink::KURL& file_path, int64_t length, ::mojo::PendingReceiver<::blink::mojom::blink::FileSystemCancellableOperation> op_receiver, TruncateCallback callback)
        override
    {
        DebugBreak();
    }

    bool TruncateSync(const ::blink::KURL& file_path, int64_t length, ::base::File::Error* out_error_code) override
    {
        DebugBreak();
        return false;
    }

    //using TruncateSyncCallback = base::OnceCallback<void(::base::File::Error)>;
    void TruncateSync(const ::blink::KURL& file_path, int64_t length, TruncateSyncCallback callback) override
    {
        DebugBreak();
    }

    bool CreateSnapshotFile(const ::blink::KURL& file_path, ::base::File::Info* out_file_info, ::base::FilePath* out_platform_path,
        ::base::File::Error* out_error_code, ::mojo::PendingRemote<::blink::mojom::blink::ReceivedSnapshotListener>* out_snapshot_listener) override
    {
        DebugBreak();
        return false;
    }

//     using CreateSnapshotFileCallback
//         = base::OnceCallback<void(const ::base::File::Info&, const ::base::FilePath&, ::base::File::Error, ::mojo::PendingRemote<ReceivedSnapshotListener>)>;

    void CreateSnapshotFile(const ::blink::KURL& file_path, CreateSnapshotFileCallback callback) override
    {
        DebugBreak();
    }

    bool GetPlatformPath(const ::blink::KURL& file_path, ::base::FilePath* out_platform_path) override
    {
        DebugBreak();
        return false;
    }

    //using GetPlatformPathCallback = base::OnceCallback<void(const ::base::FilePath&)>;
    void GetPlatformPath(const ::blink::KURL& file_path, GetPlatformPathCallback callback) override
    {

        DebugBreak();
    }

    bool RegisterBlob(const WTF::String& content_type, const ::blink::KURL& url, uint64_t length,
        std::optional<::base::Time> expected_modification_time, ::scoped_refptr<::blink::BlobDataHandle>* out_blob) override
    {
        String path = url.GetString();
        std::unique_ptr<BlobData> blob_data;
        int64_t file_size = 0;
        if (!GetFileSystemUrlSize(path, &file_size)) {
            file_size = std::numeric_limits<uint64_t>::max();
        }

        *out_blob = BlobDataHandle::CreateForFile(nullptr, path, 0, file_size, expected_modification_time, content_type);

        return true;
    }

    //using RegisterBlobCallback = base::OnceCallback<void(const ::scoped_refptr<::blink::BlobDataHandle>&)>;
    void RegisterBlob(const WTF::String& content_type, const ::blink::KURL& url, uint64_t length,
        std::optional<::base::Time> expected_modification_time, RegisterBlobCallback callback) override
    {
        DebugBreak();
    }
};

mojom::blink::FileSystemManager& ModulesInitializer::GetFileSystemManager(ExecutionContext* context)
{
    FileSystemManagerStub* stub = new FileSystemManagerStub();
    return *stub;
}

void ModulesInitializer::RegisterInterfaces(mojo::BinderMap& binders)
{
    DCHECK(Platform::Current());
    OutputDebugStringA("ModulesInitializer::RegisterInterfaces not impl\n");
    //     binders.Add<mojom::blink::WebDatabase>(ConvertToBaseRepeatingCallback(CrossThreadBindRepeating(&WebDatabaseImpl::Bind)), Platform::Current()->GetIOTaskRunner());
}

} // namespace blink
