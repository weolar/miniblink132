
#ifndef content_renderer_ScreenOrientationImpl_h
#define content_renderer_ScreenOrientationImpl_h

#include "services/device/public/mojom/screen_orientation.mojom-blink.h"
#include "services/device/public/mojom/screen_orientation_lock_types.mojom-shared.h"

namespace content {

class ScreenOrientationImpl : public ::device::mojom::blink::ScreenOrientation {
public:
    void LockOrientation(::device::mojom::blink::ScreenOrientationLockType orientation, LockOrientationCallback callback) override
    {
        std::move(callback).Run(::device::mojom::ScreenOrientationLockResult::SCREEN_ORIENTATION_LOCK_RESULT_SUCCESS);
    }

    void UnlockOrientation() override
    {
    }
};

}

#endif // content_renderer_ClipboardHostImpl_h