
#ifndef content_renderer_PermissionServiceImpl_h
#define content_renderer_PermissionServiceImpl_h

#include "gen/third_party/blink/public/mojom/permissions/permission.mojom-blink.h"
#include "base/task/sequenced_task_runner.h"

class PermissionServiceImpl : public ::blink::mojom::blink::PermissionService {
    //using HasPermissionCallback = base::OnceCallback<void(::blink::mojom::blink::PermissionStatus)>;
    /*virtual*/ void HasPermission(::blink::mojom::blink::PermissionDescriptorPtr permission, HasPermissionCallback callback) override
    {
        base::SequencedTaskRunner::GetCurrentDefault()->PostTask(FROM_HERE, base::BindOnce([](
            ::blink::mojom::blink::PermissionService::HasPermissionCallback cb) {
            std::move(cb).Run(::blink::mojom::blink::PermissionStatus::GRANTED);
        }, std::move(callback)));
    }

    /*virtual*/ void RegisterPageEmbeddedPermissionControl(
        WTF::Vector<::blink::mojom::blink::PermissionDescriptorPtr> permissions, ::mojo::PendingRemote<::blink::mojom::blink::EmbeddedPermissionControlClient> client) override
    {

    }

    //using RequestPageEmbeddedPermissionCallback = base::OnceCallback<void(EmbeddedPermissionControlResult)>;
    /*virtual*/ void RequestPageEmbeddedPermission(::blink::mojom::blink::EmbeddedPermissionRequestDescriptorPtr descriptor,
        ::blink::mojom::blink::PermissionService::RequestPageEmbeddedPermissionCallback callback) override
    {
        base::SequencedTaskRunner::GetCurrentDefault()->PostTask(FROM_HERE, base::BindOnce([](
            ::blink::mojom::blink::PermissionService::RequestPageEmbeddedPermissionCallback cb) {
            std::move(cb).Run(::blink::mojom::blink::EmbeddedPermissionControlResult::kGranted);
        }, std::move(callback)));
    }

    //using RequestPermissionCallback = base::OnceCallback<void(::blink::mojom::blink::PermissionStatus)>;
    /*virtual*/ void RequestPermission(::blink::mojom::blink::PermissionDescriptorPtr permission, bool user_gesture, RequestPermissionCallback callback) override
    {
        base::SequencedTaskRunner::GetCurrentDefault()->PostTask(FROM_HERE, base::BindOnce([](
            ::blink::mojom::blink::PermissionService::RequestPermissionCallback cb) {
            std::move(cb).Run(::blink::mojom::blink::PermissionStatus::GRANTED);
        }, std::move(callback)));
    }

    //using RequestPermissionsCallback = base::OnceCallback<void(const WTF::Vector<::blink::mojom::blink::PermissionStatus>&)>;
    /*virtual*/ void RequestPermissions(WTF::Vector<::blink::mojom::blink::PermissionDescriptorPtr> permission,
        bool user_gesture, RequestPermissionsCallback callback) override
    {
        *(int*)1 = 1;
//         base::SequencedTaskRunner::GetCurrentDefault()->PostTask(MB_FROM_HERE, base::BindOnce([](
//             ::blink::mojom::blink::PermissionService::RequestPermissionCallback cb) {
//                 std::move(cb).Run(::blink::mojom::blink::PermissionStatus::GRANTED);
//             }, std::move(callback)));
    }

    //using RevokePermissionCallback = base::OnceCallback<void(::blink::mojom::blink::PermissionStatus)>;
    /*virtual*/ void RevokePermission(::blink::mojom::blink::PermissionDescriptorPtr permission,
        ::blink::mojom::blink::PermissionService::RevokePermissionCallback callback) override
    {
        base::SequencedTaskRunner::GetCurrentDefault()->PostTask(FROM_HERE, base::BindOnce([](
            ::blink::mojom::blink::PermissionService::RevokePermissionCallback cb) {
            std::move(cb).Run(::blink::mojom::blink::PermissionStatus::GRANTED);
        }, std::move(callback)));
    }

    /*virtual*/ void AddPermissionObserver(
        ::blink::mojom::blink::PermissionDescriptorPtr permission, ::blink::mojom::blink::PermissionStatus last_known_status,
        ::mojo::PendingRemote<::blink::mojom::blink::PermissionObserver> observer) override
    {

    }

    /*virtual*/ void AddPageEmbeddedPermissionObserver(
        ::blink::mojom::blink::PermissionDescriptorPtr permission, ::blink::mojom::blink::PermissionStatus last_known_status,
        ::mojo::PendingRemote<::blink::mojom::blink::PermissionObserver> observer) override
    {

    }

    /*virtual*/ void NotifyEventListener(::blink::mojom::blink::PermissionDescriptorPtr permission, const WTF::String& event_type, bool is_added) override
    {

    }
};

#endif // content_renderer_PermissionServiceImpl_h
