// Copyright (c) 2013 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef ATOM_COMMON_PLATFORM_UTIL_H_
#define ATOM_COMMON_PLATFORM_UTIL_H_

#include "build/build_config.h"

#if defined(OS_WIN)
#include <windows.h>
#include <xstring>
#endif

class GURL;
class SkBitmap;

namespace base {
class FilePath;
}

namespace platform_util {

// Show the given file in a file manager. If possible, select the file.
// Must be called from the UI thread.
void showItemInFolder(const base::FilePath& full_path);

// Open the given file in the desktop's default manner.
// Must be called from the UI thread.
void openItem(const base::FilePath& full_path);

// Open the given external protocol URL in the desktop's default manner.
// (For example, mailto: URLs in the default mail user agent.)
bool openExternal(
#if defined(OS_WIN)
    const std::u16string& url,
#else
    const GURL& url,
#endif
    bool activate);

#if defined(OS_WIN)
void moveToCenter(HWND hWnd);
#endif

// Move a file to trash.
bool moveItemToTrash(const base::FilePath& full_path);

void beep();

bool parseBMPToSkBitmap(const uint8_t* bmpData, size_t bmpSize, SkBitmap* outBitmap);
bool loadIconFromICOToSkBitmap(const uint8_t* data, size_t dataSize, SkBitmap* outBitmap);

void* loadIconFromMemory(const uint8_t* pData, size_t dwSize, void* hIcon);
void loadIconFromMemoryFree(void* picture);

} // namespace platform_util

#endif // ATOM_COMMON_PLATFORM_UTIL_H_
