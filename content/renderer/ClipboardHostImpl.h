
#ifndef content_renderer_ClipboardHostImpl_h
#define content_renderer_ClipboardHostImpl_h

#include "third_party/blink/public/mojom/clipboard/clipboard.mojom-blink.h"
#include <windows.h>

namespace content {

// This type designates which clipboard the action should be applied to.
// Only platforms that use the X Window System support the selection buffer.
// Drag type is only supported on Mac OS X.
enum ClipboardType { CLIPBOARD_TYPE_COPY_PASTE, CLIPBOARD_TYPE_SELECTION, CLIPBOARD_TYPE_DRAG, CLIPBOARD_TYPE_LAST = CLIPBOARD_TYPE_DRAG };

class ClipboardHostImpl : public ::blink::mojom::blink::ClipboardHost {
public:
    bool GetSequenceNumber(::blink::mojom::blink::ClipboardBuffer buffer, ::blink::ClipboardSequenceNumberToken* out_result) override;

    //using GetSequenceNumberCallback = base::OnceCallback<void(const ::blink::ClipboardSequenceNumberToken&)>;
    void GetSequenceNumber(::blink::mojom::blink::ClipboardBuffer buffer, GetSequenceNumberCallback callback) override;

    bool IsFormatAvailable(::blink::mojom::blink::ClipboardFormat format, ::blink::mojom::blink::ClipboardBuffer buffer, bool* out_result) override;

    //using IsFormatAvailableCallback = base::OnceCallback<void(bool)>;
    void IsFormatAvailable(
        ::blink::mojom::blink::ClipboardFormat format, ::blink::mojom::blink::ClipboardBuffer buffer, IsFormatAvailableCallback callback) override;

    bool ReadAvailableTypes(::blink::mojom::blink::ClipboardBuffer buffer, WTF::Vector<::WTF::String>* out_types) override;

    //using ReadAvailableTypesCallback = base::OnceCallback<void(const WTF::Vector<::WTF::String>&)>;
    void ReadAvailableTypes(::blink::mojom::blink::ClipboardBuffer buffer, ReadAvailableTypesCallback callback) override;

    bool ReadText(::blink::mojom::blink::ClipboardBuffer buffer, ::WTF::String* out_result) override;

    //using ReadTextCallback = base::OnceCallback<void(const ::WTF::String&)>;
    void ReadText(::blink::mojom::blink::ClipboardBuffer buffer, ReadTextCallback callback) override;

    bool ReadHtml(::blink::mojom::blink::ClipboardBuffer buffer, ::WTF::String* out_markup, ::blink::KURL* out_url, uint32_t* out_fragment_start,
        uint32_t* out_fragment_end) override;

    //using ReadHtmlCallback = base::OnceCallback<void(const ::WTF::String&, const ::blink::KURL&, uint32_t, uint32_t)>;
    void ReadHtml(::blink::mojom::blink::ClipboardBuffer buffer, ReadHtmlCallback callback) override;

    //using ReadSvgCallback = base::OnceCallback<void(const ::WTF::String&)>;
    void ReadSvg(::blink::mojom::blink::ClipboardBuffer buffer, ReadSvgCallback callback) override;

    bool ReadRtf(::blink::mojom::blink::ClipboardBuffer buffer, ::WTF::String* out_result) override;

    //using ReadRtfCallback = base::OnceCallback<void(const ::WTF::String&)>;
    void ReadRtf(::blink::mojom::blink::ClipboardBuffer buffer, ReadRtfCallback callback) override;

    bool ReadPng(::blink::mojom::blink::ClipboardBuffer buffer, ::mojo_base::BigBuffer* out_png) override;

    //using ReadPngCallback = base::OnceCallback<void(::mojo_base::BigBuffer)>;
    void ReadPng(::blink::mojom::blink::ClipboardBuffer buffer, ReadPngCallback callback) override;

    bool ReadFiles(::blink::mojom::blink::ClipboardBuffer buffer, ::blink::mojom::blink::ClipboardFilesPtr* out_result) override;

    //using ReadFilesCallback = base::OnceCallback<void(ClipboardFilesPtr)>;
    void ReadFiles(::blink::mojom::blink::ClipboardBuffer buffer, ReadFilesCallback callback) override;

//     bool ReadCustomData(::blink::mojom::blink::ClipboardBuffer buffer, const ::WTF::String& type, ::WTF::String* out_result) override;
// 
//     void ReadCustomData(::blink::mojom::blink::ClipboardBuffer buffer, const ::WTF::String& type, ReadCustomDataCallback callback) override;

    bool ReadAvailableCustomAndStandardFormats(WTF::Vector<::WTF::String>* out_format_types) override;

    //using ReadAvailableCustomAndStandardFormatsCallback = base::OnceCallback<void(const WTF::Vector<::WTF::String>&)>;
    void ReadAvailableCustomAndStandardFormats(ReadAvailableCustomAndStandardFormatsCallback callback) override;

    //using ReadUnsanitizedCustomFormatCallback = base::OnceCallback<void(::mojo_base::BigBuffer)>;
    void ReadUnsanitizedCustomFormat(const ::WTF::String& format, ReadUnsanitizedCustomFormatCallback callback) override;

    bool ReadDataTransferCustomData(blink::mojom::blink::ClipboardBuffer buffer, const ::WTF::String& type, ::WTF::String* out_result) override;

    void ReadDataTransferCustomData(blink::mojom::blink::ClipboardBuffer buffer, const ::WTF::String& type, ReadDataTransferCustomDataCallback callback) override;
    
    void WriteDataTransferCustomData(const WTF::HashMap<::WTF::String, ::WTF::String>& data) override;

    void WriteText(const ::WTF::String& text) override;

    void WriteHtml(const ::WTF::String& markup, const ::blink::KURL& url) override;

    void WriteSvg(const ::WTF::String& markup) override;

    void WriteSmartPasteMarker() override;

    void WriteBookmark(const WTF::String& url, const ::WTF::String& title) override;

    void WriteImage(const ::SkBitmap& image) override;

    void WriteUnsanitizedCustomFormat(const ::WTF::String& format, ::mojo_base::BigBuffer data) override;

    void CommitWrite() override;

private:
    HWND getClipboardWindow();
    void readAvailableTypes(ClipboardType type, WTF::Vector<WTF::String>* types, bool* containsFilenames) const;
    void writeToClipboardInternal(unsigned int format, HANDLE handle);
    void writeTextInternal(const WTF::String& string);

    static HWND m_clipboardOwner;
};

}

#endif // content_renderer_ClipboardHostImpl_h