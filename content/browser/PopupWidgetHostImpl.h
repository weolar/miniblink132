
#ifndef content_browser_PopupWidgetHostImpl_h
#define content_browser_PopupWidgetHostImpl_h

#include "third_party/blink/public/mojom/page/widget.mojom-blink.h"

namespace content {

class PopupWidgetHostImpl : public blink::mojom::blink::PopupWidgetHost {
public:
    PopupWidgetHostImpl();
    ~PopupWidgetHostImpl();

    void RequestClosePopup() override;

    //using ShowPopupCallback = base::OnceCallback<void()>;
    void ShowPopup(const ::gfx::Rect& initial_rect, const ::gfx::Rect& anchor_rect, ShowPopupCallback callback) override;

    //using SetPopupBoundsCallback = base::OnceCallback<void()>;
    void SetPopupBounds(const ::gfx::Rect& bounds, SetPopupBoundsCallback callback) override;
};

}

#endif // content_browser_WidgetHostForPopup_h
