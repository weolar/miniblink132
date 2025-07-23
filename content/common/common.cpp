
#include "content/common/common.h"

#include "base/win/scoped_gdi_object.h"
#include "base/win/scoped_hdc.h"
#include "ui/gfx/geometry/point.h"
#include "skia/ext/skia_utils_win.h"
#include <windows.h>
#include <string>

namespace content {

void printFuncName(const char* name, bool needPrint, bool needBreak)
{
    if (needPrint) {
        std::string output("printFuncName:");
        output += name;
        output += "\n";
        OutputDebugStringA(output.c_str());
    }

    if (needBreak)
        DebugBreak();
}

// ui\gfx\icon_util.cc
#ifdef _WIN32
base::win::ScopedHICON IconUtil_CreateCursorFromSkBitmap(
    const SkBitmap& bitmap,
    const gfx::Point& hotspot)
{
    if (bitmap.empty())
        return base::win::ScopedHICON();

    // Only 32 bit ARGB bitmaps are supported.
    if (bitmap.colorType() != kN32_SkColorType) {
        //NOTIMPLEMENTED() << " unsupported color type: " << bitmap.colorType();
        return base::win::ScopedHICON();
    }

    BITMAPINFO icon_bitmap_info = {};
    skia::CreateBitmapHeaderForN32SkBitmap(bitmap, reinterpret_cast<BITMAPINFOHEADER*>(&icon_bitmap_info));

    base::win::ScopedCreateDC working_dc;
    base::win::ScopedBitmap bitmap_handle;
    {
        base::win::ScopedGetDC dc(nullptr);
        working_dc = base::win::ScopedCreateDC(::CreateCompatibleDC(dc));
        bitmap_handle = base::win::ScopedBitmap(::CreateDIBSection(dc, &icon_bitmap_info, DIB_RGB_COLORS, 0, 0, 0));
    }
    ::SetDIBits(0, bitmap_handle.get(), 0, bitmap.height(), bitmap.getPixels(), &icon_bitmap_info, DIB_RGB_COLORS);

    HBITMAP old_bitmap = reinterpret_cast<HBITMAP>(::SelectObject(working_dc.Get(), bitmap_handle.get()));
    ::SetBkMode(working_dc.Get(), TRANSPARENT);
    ::SelectObject(working_dc.Get(), old_bitmap);

    base::win::ScopedBitmap mask(::CreateBitmap(bitmap.width(), bitmap.height(), 1, 1, nullptr));
    ICONINFO ii = { 0 };
    ii.fIcon = FALSE;
    ii.xHotspot = hotspot.x();
    ii.yHotspot = hotspot.y();
    ii.hbmMask = mask.get();
    ii.hbmColor = bitmap_handle.get();

    return base::win::ScopedHICON(CreateIconIndirect(&ii));
}
#endif // _WIN32

}