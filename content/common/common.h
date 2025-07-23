#ifdef _WIN32
#include "base/win/scoped_gdi_object.h"
#endif

class SkBitmap;

namespace gfx {
class Point;
}

namespace content {

void printFuncName(const char* name, bool needPrint, bool needBreak);

#ifdef _WIN32
base::win::ScopedHICON IconUtil_CreateCursorFromSkBitmap(
    const SkBitmap& bitmap,
    const gfx::Point& hotspot);
#endif

}