
#include "content/browser/WidgetHostForPopup.h"
#include "content/common/common.h"
#include "ui/base/ime/mojom/text_input_state.mojom-blink.h"
#include "windows.h"

namespace content {

WidgetHostForPopup::WidgetHostForPopup()
{
}

WidgetHostForPopup::~WidgetHostForPopup()
{
}

void WidgetHostForPopup::SetCursor(const ::ui::Cursor& cursor)
{
    printFuncName(__FUNCTION__, true, true);
}

void WidgetHostForPopup::UpdateTooltipUnderCursor(const ::WTF::String& tooltip_text, ::base::i18n::TextDirection text_direction_hint)
{
    printFuncName(__FUNCTION__, true, true);
}

void WidgetHostForPopup::UpdateTooltipFromKeyboard(
    const ::WTF::String& tooltip_text, ::base::i18n::TextDirection text_direction_hint, const ::gfx::Rect& bounds)
{
    printFuncName(__FUNCTION__, true, true);
}

void WidgetHostForPopup::ClearKeyboardTriggeredTooltip()
{
    printFuncName(__FUNCTION__, true, true);
}

void WidgetHostForPopup::TextInputStateChanged(::ui::mojom::blink::TextInputStatePtr state)
{
    printFuncName(__FUNCTION__, true, true);
}

void WidgetHostForPopup::SelectionBoundsChanged(const ::gfx::Rect& anchor_rect, ::base::i18n::TextDirection anchor_dir, const ::gfx::Rect& focus_rect,
    ::base::i18n::TextDirection focus_dir, const ::gfx::Rect& bounding_box_rect, bool is_anchor_first)
{
    printFuncName(__FUNCTION__, true, true);
}

void WidgetHostForPopup::CreateFrameSink(::mojo::PendingReceiver<::viz::mojom::blink::CompositorFrameSink> compositor_frame_sink_receiver,
    ::mojo::PendingRemote<::viz::mojom::blink::CompositorFrameSinkClient> compositor_frame_sink_client)
{
    printFuncName(__FUNCTION__, true, true);
}

void WidgetHostForPopup::RegisterRenderFrameMetadataObserver(
    ::mojo::PendingReceiver<::cc::mojom::blink::RenderFrameMetadataObserverClient> render_frame_metadata_observer_client_receiver,
    ::mojo::PendingRemote<::cc::mojom::blink::RenderFrameMetadataObserver> render_frame_metadata_observer)
{
    printFuncName(__FUNCTION__, true, true);
}

}