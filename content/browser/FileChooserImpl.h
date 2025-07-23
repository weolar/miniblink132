
#ifndef content_browser_FileChooserImpl_h
#define content_browser_FileChooserImpl_h

#include "third_party/blink/public/mojom/choosers/file_chooser.mojom-blink.h"

namespace content {

class FileChooserImpl : public ::blink::mojom::blink::FileChooser {
public:
    FileChooserImpl(int64_t mbwebviewId);

    void OpenFileChooser(::blink::mojom::blink::FileChooserParamsPtr params, ::blink::mojom::blink::FileChooser::OpenFileChooserCallback callback) override;

    void EnumerateChosenDirectory(
        const ::base::FilePath& directory_path, ::blink::mojom::blink::FileChooser::EnumerateChosenDirectoryCallback callback) override;

private:
    int64_t m_webviewId = 0;
};

}

#endif
