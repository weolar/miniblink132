
#ifndef WINDOWS_FOR_LINUX_H
#define WINDOWS_FOR_LINUX_H

#if defined(_WIN32)
#include <windows.h>
#else
#include <stdint.h>
#include <pthread.h>

//#include "content/common/mbchar.h"

#ifndef WINAPI
#if defined(__clang__) || defined(__GNUC__)
#define WINAPI __attribute__((stdcall))
#else
#define WINAPI __stdcall
#endif
#endif

#ifndef CALLBACK
#if __SIZEOF_LONG__ == 8
#define CALLBACK
#else
#if defined(__clang__) || defined(__GNUC__)
#define CALLBACK __attribute__((stdcall))
#else
#define CALLBACK __stdcall
#endif
#endif
#endif // CALLBACK

#ifndef EXTERN_C
#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C extern
#endif
#endif

#ifndef DECLSPEC_IMPORT
#define DECLSPEC_IMPORT
#endif

#ifndef CONST
#define CONST const
#endif

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#define LOGPIXELSX 88
#define LOGPIXELSY 90

#define BI_RGB 0L
#define BI_RLE8 1L
#define BI_RLE4 2L
#define BI_BITFIELDS 3L
#define BI_JPEG 4L
#define BI_PNG 5L

#define OBJ_BITMAP 7
#define TRANSPARENT 1

#define RGB(r, g, b) ((COLORREF)(((BYTE)(r) | ((WORD)((BYTE)(g)) << 8)) | (((DWORD)(BYTE)(b)) << 16)))
#define SRCCOPY (DWORD)0x00CC0020
#define SRCAND (DWORD)0x008800C6

#define SW_SHOW 5
#define SW_HIDE 0
#define SW_SHOWNORMAL 1
#define SW_SHOWNOACTIVATE 4

#define CP_ACP 0
#define CP_UTF8 65001
#define PM_REMOVE 0x0001

#define FAILED(hr) (((HRESULT)(hr)) < 0)

#define MAKEINTRESOURCEW(i) ((LPWSTR)((ULONG_PTR)((WORD)(i))))
#define MAKEINTRESOURCE MAKEINTRESOURCEW
#define IDI_APPLICATION MAKEINTRESOURCE(32512)
#define IDC_ARROW MAKEINTRESOURCE(32512)
#define IDC_IBEAM MAKEINTRESOURCE(32513)
#define IDC_APPSTARTING MAKEINTRESOURCE(32650)
#define IDC_CROSS MAKEINTRESOURCE(32515)
#define IDC_SIZEALL MAKEINTRESOURCE(32646)
#define IDC_SIZEWE MAKEINTRESOURCE(32644)
#define IDC_SIZENS MAKEINTRESOURCE(32645)
#define IDC_HAND MAKEINTRESOURCE(32649)
#define IDC_WAIT MAKEINTRESOURCE(32514)
#define IDC_HELP MAKEINTRESOURCE(32651)
#define IDC_SIZEWE MAKEINTRESOURCE(32644)
#define IDC_SIZENS MAKEINTRESOURCE(32645)
#define IDC_SIZENESW MAKEINTRESOURCE(32643)
#define IDC_SIZENS MAKEINTRESOURCE(32645)
#define IDC_SIZENWSE MAKEINTRESOURCE(32642)
#define IDC_SIZEWE MAKEINTRESOURCE(32644)
#define IDC_SIZEALL MAKEINTRESOURCE(32646)
#define IDC_NO MAKEINTRESOURCE(32648)

#define COLOR_WINDOW 5
#define GWL_EXSTYLE (-20)
#define GWLP_USERDATA (-21)

#define HIWORD(l) ((WORD)((((DWORD_PTR)(l)) >> 16) & 0xffff))
#define LOWORD(l) ((WORD)(((DWORD_PTR)(l)) & 0xffff))
#define MAKELONG(a, b) ((LONG)(((WORD)(((DWORD_PTR)(a)) & 0xffff)) | ((DWORD)((WORD)(((DWORD_PTR)(b)) & 0xffff))) << 16))
#define MAKEWPARAM(l, h) ((WPARAM)(DWORD)MAKELONG(l, h))
#define MAKELPARAM(l, h) ((LPARAM)(DWORD)MAKELONG(l, h))

#define MAKEWORD(a, b) ((WORD)(((BYTE)(((DWORD_PTR)(a)) & 0xff)) | ((WORD)((BYTE)(((DWORD_PTR)(b)) & 0xff))) << 8))
#define MAKELONG(a, b) ((LONG)(((WORD)(((DWORD_PTR)(a)) & 0xffff)) | ((DWORD)((WORD)(((DWORD_PTR)(b)) & 0xffff))) << 16))
#define LOBYTE(w) ((BYTE)(((DWORD_PTR)(w)) & 0xff))
#define HIBYTE(w) ((BYTE)((((DWORD_PTR)(w)) >> 8) & 0xff))

/*
* WM_SIZE message wParam values
*/
#define SIZE_RESTORED 0
#define SIZE_MINIMIZED 1
#define SIZE_MAXIMIZED 2
#define SIZE_MAXSHOW 3
#define SIZE_MAXHIDE 4

#define SW_MAXIMIZE 3
#define SW_RESTORE 9
#define SW_MINIMIZE 6
#define SC_CLOSE 0xF060

#define IDC_SMALL 2

#define MF_BYCOMMAND 0x00000000L
#define MF_GRAYED 0x00000001L
#define HWND_NOTOPMOST ((HWND)-2)
#define WS_EX_ACCEPTFILES 0x00000010L

#define WM_NULL 0x0000
#define WM_GETMINMAXINFO 0x0024
#define WM_MOVE 0x0003
#define WM_TIMER 0x0113
#define WM_PAINT 0x000F
#define WM_CLOSE 0x0010
#define WM_LBUTTONUP 0x0202
#define WM_MOUSEMOVE 0x0200
#define WM_MBUTTONUP 0x0208
#define WM_RBUTTONUP 0x0205
#define WM_SETCURSOR 0x0020
#define WM_LBUTTONDOWN 0x0201

#define WM_NCLBUTTONDOWN 0x00A1
#define WM_NCRBUTTONDOWN 0x00A4
#define WM_NCLBUTTONDBLCLK 0x00A3
#define WM_NCRBUTTONUP 0x00A5
#define WM_NCMBUTTONUP 0x00A8
#define WM_NCLBUTTONUP 0x00A2
#define WM_NCRBUTTONDBLCLK 0x00A6
#define WM_NCMBUTTONDOWN 0x00A7
#define WM_NCMBUTTONDBLCLK 0x00A9

#define WM_IME_CHAR 0x0286
#define WM_SYSCOMMAND 0x0112
#define WM_MOUSELEAVE 0x02A3
#define WM_NCMOUSEMOVE 0x00A0
#define WM_NCMOUSEHOVER 0x02A0
#define WM_NCHITTEST 0x0084
#define WM_MBUTTONDOWN 0x0207
#define WM_RBUTTONDOWN 0x0204
#define WM_LBUTTONDBLCLK 0x0203
#define WM_COMMAND 0x0111
#define WM_EXITMENULOOP 0x0212
#define WM_RENDERFORMAT 0x0305
#define WM_RENDERALLFORMATS 0x0306
#define WM_DRAWCLIPBOARD 0x0308
#define WM_DESTROY 0x0002
#define WM_CHANGECBCHAIN 0x030D
#define WM_SIZE 0x0005
#define WM_CANCELMODE 0x001F
#define WM_MOUSEWHEEL 0x020A
#define WM_KEYUP 0x0101
#define WM_KEYDOWN 0x0100
#define WM_CHAR 0x0102
#define WM_SETFOCUS 0x0007
#define WM_KILLFOCUS 0x0008
#define WM_CREATE 0x0001
#define WM_NCPAINT 0x0085
#define WM_ERASEBKGND 0x0014
#define WM_CREATE 0x0001
#define WM_DROPFILES 0x0233
#define WM_NCDESTROY 0x0082
#define WM_SYSKEYDOWN 0x0104
#define WM_SYSKEYUP 0x0105
#define WM_MBUTTONDBLCLK 0x0209
#define WM_RBUTTONDBLCLK 0x0206
#define WM_IME_COMPOSITION 0x010F
#define WM_QUIT 0x0012
#define WM_USER 0x0400
#define WM_SETFONT 0x0030
#define WM_TOUCH 0x0240
#define WM_CAPTURECHANGED 0x0215

#define HTERROR (-2)
#define HTTRANSPARENT (-1)
#define HTNOWHERE 0
#define HTCLIENT 1
#define HTCAPTION 2
#define HTSYSMENU 3
#define HTGROWBOX 4
#define HTSIZE HTGROWBOX
#define HTMENU 5
#define HTHSCROLL 6
#define HTVSCROLL 7
#define HTMINBUTTON 8
#define HTMAXBUTTON 9
#define HTLEFT 10
#define HTRIGHT 11
#define HTTOP 12
#define HTTOPLEFT 13
#define HTTOPRIGHT 14
#define HTBOTTOM 15
#define HTBOTTOMLEFT 16
#define HTBOTTOMRIGHT 17
#define HTBORDER 18
#define HTREDUCE HTMINBUTTON
#define HTZOOM HTMAXBUTTON
#define HTSIZEFIRST HTLEFT
#define HTSIZELAST HTBOTTOMRIGHT

#define WHITE_BRUSH 0
#define ES_AUTOHSCROLL 0x0080L
#define SS_CENTER 0x00000001L
#define BS_PUSHBUTTON 0x00000000L
#define ES_LEFT 0x0000L
#define ES_AUTOVSCROLL 0x0040L
#define FW_DONTCARE 0
#define DEFAULT_CHARSET 1
#define DEFAULT_PITCH 0
#define FF_DONTCARE (0 << 4)

#define CFS_FORCE_POSITION 0x0020
#define CFS_POINT 0x0002
#define WM_CONTEXTMENU 0x007B
#define WM_IME_STARTCOMPOSITION 0x010D

#define SC_RESTORE 0xF120

#define MB_OK 0x00000000L
#define MINSHORT 0x8000
#define MAKEWPARAM(l, h) ((WPARAM)(DWORD)MAKELONG(l, h))
#define KF_REPEAT 0x4000

#define MK_MBUTTON 0x0010
#define MK_RBUTTON 0x0002
#define MK_SHIFT 0x0004
#define HTCAPTION 2
#define SC_MOVE 0xF010
#define HTCLIENT 1
#define MK_CONTROL 0x0008
#define MF_STRING 0x00000000L
#define WHEEL_PAGESCROLL (UINT_MAX)
#define TPM_RIGHTBUTTON 0x0002L
#define TPM_TOPALIGN 0x0000L
#define TPM_VERPOSANIMATION 0x1000L
#define TPM_HORIZONTAL 0x0000L
#define TPM_LEFTALIGN 0x0000L
#define TPM_HORPOSANIMATION 0x0400L
#define SWP_NOOWNERZORDER 0x0200
#define SWP_NOREPOSITION SWP_NOOWNERZORDER

#define MB_OKCANCEL 0x00000001L
#define MB_YESNO 0x00000004L
#define IDYES 6

#define VK_RETURN 0x0D
#define IDOK 1

#define CF_UNICODETEXT 13
#define CF_TEXT 1
#define ULW_ALPHA 0x00000002
#define GENERIC_READ (0x80000000L)
#define GENERIC_WRITE (0x40000000L)
#define CREATE_NEW 1
#define FILE_SHARE_READ 0x00000001
#define OPEN_EXISTING 3
#define FILE_ATTRIBUTE_NORMAL 0x00000080
#define WM_CTLCOLORSTATIC 0x0138

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#define LOCALE_SSHORTDATE 0x0000001F
#define LOCALE_SYEARMONTH 0x00001006
#define LOCALE_STIMEFORMAT 0x00001003

#define LOCALE_SSHORTTIME 0x00000079
#define LOCALE_STIME 0x0000001E
#define LOCALE_S1159 0x00000028
#define LOCALE_S2359 0x00000029
#define LOCALE_IDIGITSUBSTITUTION 0x00001014
#define LOCALE_SNATIVEDIGITS 0x00000013
#define LOCALE_SDECIMAL 0x0000000E
#define LOCALE_STHOUSAND 0x0000000F
#define LOCALE_SNEGATIVESIGN 0x00000051
#define LOCALE_INEGNUMBER 0x00001010

#define LOCALE_SDAYNAME1 0x0000002A // long name for Monday
#define LOCALE_SDAYNAME2 0x0000002B // long name for Tuesday
#define LOCALE_SDAYNAME3 0x0000002C // long name for Wednesday
#define LOCALE_SDAYNAME4 0x0000002D // long name for Thursday
#define LOCALE_SDAYNAME5 0x0000002E // long name for Friday
#define LOCALE_SDAYNAME6 0x0000002F // long name for Saturday
#define LOCALE_SDAYNAME7 0x00000030 // long name for Sunday
#define LOCALE_SABBREVDAYNAME1 0x00000031 // abbreviated name for Monday
#define LOCALE_SABBREVDAYNAME2 0x00000032 // abbreviated name for Tuesday
#define LOCALE_SABBREVDAYNAME3 0x00000033 // abbreviated name for Wednesday
#define LOCALE_SABBREVDAYNAME4 0x00000034 // abbreviated name for Thursday
#define LOCALE_SABBREVDAYNAME5 0x00000035 // abbreviated name for Friday
#define LOCALE_SABBREVDAYNAME6 0x00000036 // abbreviated name for Saturday
#define LOCALE_SABBREVDAYNAME7 0x00000037 // abbreviated name for Sunday
#define LOCALE_SMONTHNAME1 0x00000038 // long name for January
#define LOCALE_SMONTHNAME2 0x00000039 // long name for February
#define LOCALE_SMONTHNAME3 0x0000003A // long name for March
#define LOCALE_SMONTHNAME4 0x0000003B // long name for April
#define LOCALE_SMONTHNAME5 0x0000003C // long name for May
#define LOCALE_SMONTHNAME6 0x0000003D // long name for June
#define LOCALE_SMONTHNAME7 0x0000003E // long name for July
#define LOCALE_SMONTHNAME8 0x0000003F // long name for August
#define LOCALE_SMONTHNAME9 0x00000040 // long name for September
#define LOCALE_SMONTHNAME10 0x00000041 // long name for October
#define LOCALE_SMONTHNAME11 0x00000042 // long name for November
#define LOCALE_SMONTHNAME12 0x00000043 // long name for December
#define LOCALE_SMONTHNAME13 0x0000100E // long name for 13th month (if exists)
#define LOCALE_SABBREVMONTHNAME1 0x00000044 // abbreviated name for January
#define LOCALE_SABBREVMONTHNAME2 0x00000045 // abbreviated name for February
#define LOCALE_SABBREVMONTHNAME3 0x00000046 // abbreviated name for March
#define LOCALE_SABBREVMONTHNAME4 0x00000047 // abbreviated name for April
#define LOCALE_SABBREVMONTHNAME5 0x00000048 // abbreviated name for May
#define LOCALE_SABBREVMONTHNAME6 0x00000049 // abbreviated name for June
#define LOCALE_SABBREVMONTHNAME7 0x0000004A // abbreviated name for July
#define LOCALE_SABBREVMONTHNAME8 0x0000004B // abbreviated name for August
#define LOCALE_SABBREVMONTHNAME9 0x0000004C // abbreviated name for September
#define LOCALE_SABBREVMONTHNAME10 0x0000004D // abbreviated name for October
#define LOCALE_SABBREVMONTHNAME11 0x0000004E // abbreviated name for November
#define LOCALE_SABBREVMONTHNAME12 0x0000004F // abbreviated name for December
#define LOCALE_SABBREVMONTHNAME13 0x0000100F // abbreviated name for 13th month (if exists)

#define LOCALE_RETURN_NUMBER 0x20000000
#define LOCALE_IFIRSTDAYOFWEEK 0x0000100C
#define LOCALE_NOUSEROVERRIDE 0x80000000
#define LOCALE_SISO639LANGNAME 0x00000059
#define LOCALE_NAME_MAX_LENGTH 85
#define MAKELANGID(p, s) ((((WORD)(s)) << 10) | (WORD)(p))
#define SUBLANG_DEFAULT 0x01
#define LANG_NEUTRAL 0x00
#define SORT_DEFAULT 0x0
#define LANG_USER_DEFAULT (MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT))
#define MAKELCID(lgid, srtid) ((DWORD)((((DWORD)((WORD)(srtid))) << 16) | ((DWORD)((WORD)(lgid)))))
#define LOCALE_USER_DEFAULT (MAKELCID(LANG_USER_DEFAULT, SORT_DEFAULT))

/* Region Flags */
//#define ERROR               0
#define NULLREGION 1
#define SIMPLEREGION 2
#define COMPLEXREGION 3
#define RGN_ERROR ERROR
#define ERROR_SUCCESS 0L
#define INVALID_SET_FILE_POINTER ((DWORD)-1)
#define NO_ERROR 0L

#define R2_COPYPEN 13
#define OPAQUE 2
#define CLR_INVALID 0xFFFFFFFF
#define AD_CLOCKWISE 2
#define SECTION_MAP_WRITE 0x0002
#define FILE_MAP_WRITE SECTION_MAP_WRITE

#define CSIDL_APPDATA 0x001a
#define CSIDL_LOCAL_APPDATA 0x001c
#define INFINITE 0xFFFFFFFF
#define INVALID_HANDLE_VALUE ((HANDLE)(LONG_PTR)-1)
#define E_INVALIDARG ((HRESULT)0x80000003L)
#define ERROR_ALREADY_EXISTS 183L
#define ERROR_FILE_EXISTS 80L
#define CSIDL_FLAG_CREATE 0x8000
#define FILE_BEGIN 0
#define FILE_CURRENT 1
#define FILE_END 2
#define FILE_SHARE_WRITE 0x00000002
#define CREATE_ALWAYS 2
#define CF_BITMAP 2
#define SM_CXSCREEN 0
#define GMEM_MOVEABLE 0x0002
#define GMEM_DDESHARE 0x2000
#define CP_ACP 0
#define ERROR_CLIPBOARD_NOT_OPEN 1418L
#define CF_DIB 8
#define AC_SRC_OVER 0x00
#define AC_SRC_ALPHA 0x01
#define DIB_RGB_COLORS 0
#define HWND_MESSAGE ((HWND)-3)
#define MAKEINTATOM(i) (LPWSTR)((ULONG_PTR)((WORD)(i)))

#define DLGC_WANTARROWS 0x0001
#define DLGC_WANTALLKEYS 0x0004
#define DLGC_WANTCHARS 0x0080
#define GCS_RESULTSTR 0x0800
#define SWP_NOZORDER 0x0004
#define GWL_STYLE (-16)
#define SM_CYSCREEN 1
#define GCS_COMPSTR 0x0008
#define WM_GETDLGCODE 0x0087

#define WS_EX_LAYERED 0x00080000
#define WS_OVERLAPPED 0x00000000L
#define WS_POPUP 0x80000000L
#define WS_CHILD 0x40000000L
#define WS_MINIMIZE 0x20000000L
#define WS_VISIBLE 0x10000000L
#define WS_DISABLED 0x08000000L
#define WS_CLIPSIBLINGS 0x04000000L
#define WS_CLIPCHILDREN 0x02000000L
#define WS_MAXIMIZE 0x01000000L
#define WS_CAPTION 0x00C00000L /* WS_BORDER | WS_DLGFRAME  */
#define WS_BORDER 0x00800000L
#define WS_DLGFRAME 0x00400000L
#define WS_VSCROLL 0x00200000L
#define WS_HSCROLL 0x00100000L
#define WS_SYSMENU 0x00080000L
#define WS_THICKFRAME 0x00040000L
#define WS_GROUP 0x00020000L
#define WS_TABSTOP 0x00010000L

#define WS_MINIMIZEBOX 0x00020000L
#define WS_MAXIMIZEBOX 0x00010000L

#define WS_TILED WS_OVERLAPPED
#define WS_ICONIC WS_MINIMIZE
#define WS_SIZEBOX WS_THICKFRAME
#define WS_TILEDWINDOW WS_OVERLAPPEDWINDOW
#define WS_EX_TOOLWINDOW 0x00000080L
#define FW_THIN 100
#define GB2312_CHARSET 134
#define OUT_DEFAULT_PRECIS 0
#define CLIP_DEFAULT_PRECIS 0
#define DEFAULT_QUALITY 0
#define FIXED_PITCH 1
#define FF_MODERN (3 << 4)

#define WS_OVERLAPPEDWINDOW (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX)

#define CW_USEDEFAULT ((int)0x80000000)
#define HWND_DESKTOP ((HWND)0)
#define LOGPIXELSX 88
#define CS_HREDRAW 0x0002
#define CS_VREDRAW 0x0001
#define CS_DROPSHADOW 0x00020000
#define PS_SOLID 0
#define SWP_NOACTIVATE 0x0010

#define MK_LBUTTON 0x0001
#define SPI_GETWHEELSCROLLLINES 0x0068
#define SPI_GETWHEELSCROLLCHARS 0x006C
#define GET_WHEEL_DELTA_WPARAM(wParam) ((short)HIWORD(wParam))
#define WHEEL_DELTA 120

#define CreateWindowW(lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)                                        \
    CreateWindowExW(0L, lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)

#define HWND_TOPMOST ((HWND)-1)
#define SWP_NOMOVE 0x0002
#define SWP_NOSIZE 0x0001

#define RGN_OR 2
#define RGN_DIFF 4

#define MONITOR_DEFAULTTOPRIMARY 0x00000001

#define MAX_PATH 260

/*
* Virtual Keys, Standard Set
*/
#define VK_LBUTTON 0x01
#define VK_RBUTTON 0x02
#define VK_CANCEL 0x03
#define VK_MBUTTON 0x04 /* NOT contiguous with L & RBUTTON */

#if (_WIN32_WINNT >= 0x0500)
#define VK_XBUTTON1 0x05 /* NOT contiguous with L & RBUTTON */
#define VK_XBUTTON2 0x06 /* NOT contiguous with L & RBUTTON */
#endif /* _WIN32_WINNT >= 0x0500 */

/*
* 0x07 : unassigned
*/

#define VK_BACK 0x08
#define VK_TAB 0x09

/*
* 0x0A - 0x0B : reserved
*/

#define VK_CLEAR 0x0C
#define VK_RETURN 0x0D

#define VK_SHIFT 0x10
#define VK_CONTROL 0x11
#define VK_MENU 0x12
#define VK_PAUSE 0x13
#define VK_CAPITAL 0x14

#define VK_KANA 0x15
#define VK_HANGEUL 0x15 /* old name - should be here for compatibility */
#define VK_HANGUL 0x15
#define VK_JUNJA 0x17
#define VK_FINAL 0x18
#define VK_HANJA 0x19
#define VK_KANJI 0x19

#define VK_ESCAPE 0x1B

#define VK_CONVERT 0x1C
#define VK_NONCONVERT 0x1D
#define VK_ACCEPT 0x1E
#define VK_MODECHANGE 0x1F

#define VK_SPACE 0x20
#define VK_PRIOR 0x21
#define VK_NEXT 0x22
#define VK_END 0x23
#define VK_HOME 0x24
#define VK_LEFT 0x25
#define VK_UP 0x26
#define VK_RIGHT 0x27
#define VK_DOWN 0x28
#define VK_SELECT 0x29
#define VK_PRINT 0x2A
#define VK_EXECUTE 0x2B
#define VK_SNAPSHOT 0x2C
#define VK_INSERT 0x2D
#define VK_DELETE 0x2E
#define VK_HELP 0x2F

/*
* VK_0 - VK_9 are the same as ASCII '0' - '9' (0x30 - 0x39)
* 0x40 : unassigned
* VK_A - VK_Z are the same as ASCII 'A' - 'Z' (0x41 - 0x5A)
*/

#define VK_LWIN 0x5B
#define VK_RWIN 0x5C
#define VK_APPS 0x5D

/*
* 0x5E : reserved
*/

#define VK_SLEEP 0x5F

#define VK_NUMPAD0 0x60
#define VK_NUMPAD1 0x61
#define VK_NUMPAD2 0x62
#define VK_NUMPAD3 0x63
#define VK_NUMPAD4 0x64
#define VK_NUMPAD5 0x65
#define VK_NUMPAD6 0x66
#define VK_NUMPAD7 0x67
#define VK_NUMPAD8 0x68
#define VK_NUMPAD9 0x69
#define VK_MULTIPLY 0x6A
#define VK_ADD 0x6B
#define VK_SEPARATOR 0x6C
#define VK_SUBTRACT 0x6D
#define VK_DECIMAL 0x6E
#define VK_DIVIDE 0x6F
#define VK_F1 0x70
#define VK_F2 0x71
#define VK_F3 0x72
#define VK_F4 0x73
#define VK_F5 0x74
#define VK_F6 0x75
#define VK_F7 0x76
#define VK_F8 0x77
#define VK_F9 0x78
#define VK_F10 0x79
#define VK_F11 0x7A
#define VK_F12 0x7B
#define VK_F13 0x7C
#define VK_F14 0x7D
#define VK_F15 0x7E
#define VK_F16 0x7F
#define VK_F17 0x80
#define VK_F18 0x81
#define VK_F19 0x82
#define VK_F20 0x83
#define VK_F21 0x84
#define VK_F22 0x85
#define VK_F23 0x86
#define VK_F24 0x87

/*
* 0x88 - 0x8F : unassigned
*/

#define VK_NUMLOCK 0x90
#define VK_SCROLL 0x91

/*
* NEC PC-9800 kbd definitions
*/
#define VK_OEM_NEC_EQUAL 0x92 // '=' key on numpad

/*
* Fujitsu/OASYS kbd definitions
*/
#define VK_OEM_FJ_JISHO 0x92 // 'Dictionary' key
#define VK_OEM_FJ_MASSHOU 0x93 // 'Unregister word' key
#define VK_OEM_FJ_TOUROKU 0x94 // 'Register word' key
#define VK_OEM_FJ_LOYA 0x95 // 'Left OYAYUBI' key
#define VK_OEM_FJ_ROYA 0x96 // 'Right OYAYUBI' key

/*
* 0x97 - 0x9F : unassigned
*/

/*
* VK_L* & VK_R* - left and right Alt, Ctrl and Shift virtual keys.
* Used only as parameters to GetAsyncKeyState() and GetKeyState().
* No other API or message will distinguish left and right keys in this way.
*/
#define VK_LSHIFT 0xA0
#define VK_RSHIFT 0xA1
#define VK_LCONTROL 0xA2
#define VK_RCONTROL 0xA3
#define VK_LMENU 0xA4
#define VK_RMENU 0xA5

#if (_WIN32_WINNT >= 0x0500)
#define VK_BROWSER_BACK 0xA6
#define VK_BROWSER_FORWARD 0xA7
#define VK_BROWSER_REFRESH 0xA8
#define VK_BROWSER_STOP 0xA9
#define VK_BROWSER_SEARCH 0xAA
#define VK_BROWSER_FAVORITES 0xAB
#define VK_BROWSER_HOME 0xAC

#define VK_VOLUME_MUTE 0xAD
#define VK_VOLUME_DOWN 0xAE
#define VK_VOLUME_UP 0xAF
#define VK_MEDIA_NEXT_TRACK 0xB0
#define VK_MEDIA_PREV_TRACK 0xB1
#define VK_MEDIA_STOP 0xB2
#define VK_MEDIA_PLAY_PAUSE 0xB3
#define VK_LAUNCH_MAIL 0xB4
#define VK_LAUNCH_MEDIA_SELECT 0xB5
#define VK_LAUNCH_APP1 0xB6
#define VK_LAUNCH_APP2 0xB7

#endif /* _WIN32_WINNT >= 0x0500 */

/*
* 0xB8 - 0xB9 : reserved
*/

#define VK_OEM_1 0xBA // ';:' for US
#define VK_OEM_PLUS 0xBB // '+' any country
#define VK_OEM_COMMA 0xBC // ',' any country
#define VK_OEM_MINUS 0xBD // '-' any country
#define VK_OEM_PERIOD 0xBE // '.' any country
#define VK_OEM_2 0xBF // '/?' for US
#define VK_OEM_3 0xC0 // '`~' for US

/*
* 0xC1 - 0xD7 : reserved
*/

/*
* 0xD8 - 0xDA : unassigned
*/

#define VK_OEM_4 0xDB //  '[{' for US
#define VK_OEM_5 0xDC //  '\|' for US
#define VK_OEM_6 0xDD //  ']}' for US
#define VK_OEM_7 0xDE //  ''"' for US
#define VK_OEM_8 0xDF

/*
* 0xE0 : reserved
*/

/*
* Various extended or enhanced keyboards
*/
#define VK_OEM_AX 0xE1 //  'AX' key on Japanese AX kbd
#define VK_OEM_102 0xE2 //  "<>" or "\|" on RT 102-key kbd.
#define VK_ICO_HELP 0xE3 //  Help key on ICO
#define VK_ICO_00 0xE4 //  00 key on ICO

#if (WINVER >= 0x0400)
#define VK_PROCESSKEY 0xE5
#endif /* WINVER >= 0x0400 */

#define VK_ICO_CLEAR 0xE6

#if (_WIN32_WINNT >= 0x0500)
#define VK_PACKET 0xE7
#endif /* _WIN32_WINNT >= 0x0500 */

/*
* 0xE8 : unassigned
*/

/*
* Nokia/Ericsson definitions
*/
#define VK_OEM_RESET 0xE9
#define VK_OEM_JUMP 0xEA
#define VK_OEM_PA1 0xEB
#define VK_OEM_PA2 0xEC
#define VK_OEM_PA3 0xED
#define VK_OEM_WSCTRL 0xEE
#define VK_OEM_CUSEL 0xEF
#define VK_OEM_ATTN 0xF0
#define VK_OEM_FINISH 0xF1
#define VK_OEM_COPY 0xF2
#define VK_OEM_AUTO 0xF3
#define VK_OEM_ENLW 0xF4
#define VK_OEM_BACKTAB 0xF5

#define VK_ATTN 0xF6
#define VK_CRSEL 0xF7
#define VK_EXSEL 0xF8
#define VK_EREOF 0xF9
#define VK_PLAY 0xFA
#define VK_ZOOM 0xFB
#define VK_NONAME 0xFC
#define VK_PA1 0xFD
#define VK_OEM_CLEAR 0xFE

#define KF_EXTENDED 0x0100

#define LOBYTE(w) ((BYTE)(((DWORD_PTR)(w)) & 0xff))

#define GetRValue(rgb) (LOBYTE(rgb))
#define GetGValue(rgb) (LOBYTE(((WORD)(rgb)) >> 8))
#define GetBValue(rgb) (LOBYTE((rgb) >> 16))
#define GM_ADVANCED 2
#define HALFTONE 4

#define MIIM_STATE 0x00000001
#define MIIM_ID 0x00000002
#define MIIM_SUBMENU 0x00000004
#define MIIM_CHECKMARKS 0x00000008
#define MIIM_TYPE 0x00000010
#define MIIM_DATA 0x00000020
#define MIIM_STRING 0x00000040
#define MIIM_BITMAP 0x00000080
#define MIIM_FTYPE 0x00000100

#define MF_UNCHECKED 0x00000000L
#define MF_CHECKED 0x00000008L
#define MF_SEPARATOR 0x00000800L
#define MF_STRING 0x00000000L
#define MF_ENABLED 0x00000000L

#define MFS_GRAYED 0x00000003L
#define MFS_DISABLED MFS_GRAYED
#define MFS_ENABLED MF_ENABLED
#define MFT_SEPARATOR MF_SEPARATOR
#define MFT_STRING MF_STRING
#define MFS_CHECKED MF_CHECKED
#define MFS_UNCHECKED MF_UNCHECKED

typedef unsigned short WORD;

typedef void* HDC;
typedef void* HRGN;

#define VOID void
typedef char CHAR;
typedef short SHORT;
typedef int32_t LONG;
typedef int32_t INT;
typedef unsigned int UINT;
typedef uint32_t DWORD;
typedef DWORD COLORREF;
typedef unsigned char BYTE;
#ifdef __cplusplus
//typedef wchar_t WCHAR;
typedef char16_t WCHAR;
#else
typedef unsigned short WCHAR;
#endif
typedef CONST WCHAR *LPCWSTR, *PCWSTR;
typedef WCHAR *NWPSTR, *LPWSTR, *PWSTR;
typedef unsigned short USHORT;
typedef DWORD* LPDWORD;
typedef signed char int8_t;
typedef unsigned char UCHAR;

#if __SIZEOF_POINTER__ == 8
typedef long long INT_PTR, *PINT_PTR;
typedef unsigned long long UINT_PTR, *PUINT_PTR, ULONGLONG;

typedef long long LONG_PTR, *PLONG_PTR;
typedef unsigned long long ULONG_PTR, *PULONG_PTR;
typedef long long __int3264;
#else
typedef int INT_PTR, *PINT_PTR;
typedef unsigned int UINT_PTR, *PUINT_PTR;

typedef long LONG_PTR, *PLONG_PTR;
typedef unsigned long ULONG_PTR, *PULONG_PTR;
typedef int32_t __int3264;
#endif // __WORDSIZE__

typedef ULONG_PTR SIZE_T, *PSIZE_T;
typedef ULONG_PTR DWORD_PTR, *PDWORD_PTR;

typedef const CHAR *LPCSTR, *PCSTR;

typedef unsigned char uint8;
typedef BYTE* PBYTE;

typedef DWORD LCID;
typedef DWORD LCTYPE;

typedef LONG_PTR LRESULT;
typedef LONG HRESULT;
typedef unsigned long ULONG;
typedef ULONG* PULONG;
typedef BYTE* LPBYTE;
typedef void* PVOID;
typedef UINT_PTR WPARAM;
typedef LONG_PTR LPARAM;
typedef int BOOL;
typedef void* HINSTANCE;
typedef HINSTANCE HMODULE;
typedef void* HICON;
typedef void* HRGN;
typedef void* HGDIOBJ;
typedef void* HBITMAP;
typedef void* LPVOID;
typedef void* HANDLE;
typedef void* HCURSOR;
typedef void* HBRUSH;
typedef void* HMENU;
typedef void* HPEN;
typedef void* HFONT;
typedef void* HMONITOR;
typedef void* HWND;
typedef void* HDROP;
typedef void* HIMC;
typedef void* HKEY;

typedef WORD ATOM;

typedef HANDLE HGLOBAL;

typedef /* [hidden] */ struct tagXFORM {
    float eM11;
    float eM12;
    float eM21;
    float eM22;
    float eDx;
    float eDy;
} XFORM;

typedef struct _SYSTEMTIME {
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
} SYSTEMTIME, *PSYSTEMTIME, *LPSYSTEMTIME;

#pragma pack(push, 8)
typedef struct _RTL_CRITICAL_SECTION {
    /*PRTL_CRITICAL_SECTION_DEBUG*/ void* DebugInfo;
    /*LONG*/ int32_t LockCount;
    /*LONG*/ int32_t RecursionCount;
    /*HANDLE*/ uintptr_t OwningThread; // from the thread's ClientId->UniqueThread
    /*HANDLE*/ uintptr_t LockSemaphore;
    /*ULONG_PTR*/ uintptr_t SpinCount; // force size on 64-bit systems when packed
    //pthread_mutex_t mutex;
} CRITICAL_SECTION;
#pragma pack(pop)

typedef struct _SECURITY_ATTRIBUTES* LPSECURITY_ATTRIBUTES;

typedef struct tagPOINT {
    LONG x;
    LONG y;
} POINT, *PPOINT, *NPPOINT, *LPPOINT;

typedef struct _POINTL { /* ptl  */
    LONG x;
    LONG y;
} POINTL, *PPOINTL;

typedef struct tagSIZE {
    LONG cx;
    LONG cy;
} SIZE, *PSIZE, *LPSIZE;

typedef struct tagINITCOMMONCONTROLSEX {
    DWORD dwSize; // size of this structure
    DWORD dwICC; // flags indicating which classes to be initialized
} INITCOMMONCONTROLSEX, *LPINITCOMMONCONTROLSEX;

#define TOUCHEVENTF_MOVE 0x0001
#define TOUCHEVENTF_DOWN 0x0002
#define TOUCHEVENTF_UP 0x0004
#define TOUCHEVENTF_INRANGE 0x0008
#define TOUCHEVENTF_PRIMARY 0x0010
#define TOUCHEVENTF_NOCOALESCE 0x0020
#define TOUCHEVENTF_PEN 0x0040
#define TOUCHEVENTF_PALM 0x0080

/*
* Touch input mask values (TOUCHINPUT.dwMask)
*/
#define TOUCHINPUTMASKF_TIMEFROMSYSTEM 0x0001 // the dwTime field contains a system generated value
#define TOUCHINPUTMASKF_EXTRAINFO 0x0002 // the dwExtraInfo field is valid
#define TOUCHINPUTMASKF_CONTACTAREA 0x0004 // the cxContact and cyContact fields are valid

typedef HANDLE HTOUCHINPUT;

typedef struct tagTOUCHINPUT {
    LONG x;
    LONG y;
    HANDLE hSource;
    DWORD dwID;
    DWORD dwFlags;
    DWORD dwMask;
    DWORD dwTime;
    ULONG_PTR dwExtraInfo;
    DWORD cxContact;
    DWORD cyContact;
} TOUCHINPUT, *PTOUCHINPUT;
typedef TOUCHINPUT const* PCTOUCHINPUT;

typedef struct tagMSG {
    HWND hwnd;
    UINT message;
    WPARAM wParam;
    LPARAM lParam;
    DWORD time;
    POINT pt;
} MSG;

#define LF_FACESIZE 32

typedef struct tagLOGFONTW {
    LONG lfHeight;
    LONG lfWidth;
    LONG lfEscapement;
    LONG lfOrientation;
    LONG lfWeight;
    BYTE lfItalic;
    BYTE lfUnderline;
    BYTE lfStrikeOut;
    BYTE lfCharSet;
    BYTE lfOutPrecision;
    BYTE lfClipPrecision;
    BYTE lfQuality;
    BYTE lfPitchAndFamily;
    WCHAR lfFaceName[LF_FACESIZE];
} LOGFONTW, *PLOGFONTW, *NPLOGFONTW, *LPLOGFONTW;

typedef struct tagBITMAP {
    LONG bmType;
    LONG bmWidth;
    LONG bmHeight;
    LONG bmWidthBytes;
    WORD bmPlanes;
    WORD bmBitsPixel;
    LPVOID bmBits;
} BITMAP, *PBITMAP, *NPBITMAP, *LPBITMAP;

typedef struct tagWINDOWPOS {
    HWND hwnd;
    HWND hwndInsertAfter;
    int x;
    int y;
    int cx;
    int cy;
    UINT flags;
} WINDOWPOS, *LPWINDOWPOS, *PWINDOWPOS;

typedef struct tagRECT {
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
} RECT, *LPRECT;

typedef struct tagCOMPOSITIONFORM {
    DWORD dwStyle;
    POINT ptCurrentPos;
    RECT rcArea;
} COMPOSITIONFORM, *PCOMPOSITIONFORM, *NPCOMPOSITIONFORM, *LPCOMPOSITIONFORM;

typedef struct tagCOPYDATASTRUCT {
    ULONG_PTR dwData;
    DWORD cbData;
    PVOID lpData;
} COPYDATASTRUCT, *PCOPYDATASTRUCT;

typedef struct tagMENUITEMINFOW {
    UINT cbSize;
    UINT fMask;
    UINT fType; // used if MIIM_TYPE (4.0) or MIIM_FTYPE (>4.0)
    UINT fState; // used if MIIM_STATE
    UINT wID; // used if MIIM_ID
    HMENU hSubMenu; // used if MIIM_SUBMENU
    HBITMAP hbmpChecked; // used if MIIM_CHECKMARKS
    HBITMAP hbmpUnchecked; // used if MIIM_CHECKMARKS
    ULONG_PTR dwItemData; // used if MIIM_DATA
    LPWSTR dwTypeData; // used if MIIM_TYPE (4.0) or MIIM_STRING (>4.0)
    UINT cch; // used if MIIM_TYPE (4.0) or MIIM_STRING (>4.0)
    HBITMAP hbmpItem; // used if MIIM_BITMAP
} MENUITEMINFOW, *LPMENUITEMINFOW;

typedef struct _STARTUPINFOW {
    DWORD cb;
    LPWSTR lpReserved;
    LPWSTR lpDesktop;
    LPWSTR lpTitle;
    DWORD dwX;
    DWORD dwY;
    DWORD dwXSize;
    DWORD dwYSize;
    DWORD dwXCountChars;
    DWORD dwYCountChars;
    DWORD dwFillAttribute;
    DWORD dwFlags;
    WORD wShowWindow;
    WORD cbReserved2;
    LPBYTE lpReserved2;
    HANDLE hStdInput;
    HANDLE hStdOutput;
    HANDLE hStdError;
} STARTUPINFOW, *LPSTARTUPINFOW;

typedef struct tagBITMAPCOREHEADER {
    DWORD bcSize; /* used to get to color table */
    WORD bcWidth;
    WORD bcHeight;
    WORD bcPlanes;
    WORD bcBitCount;
} BITMAPCOREHEADER, *LPBITMAPCOREHEADER, *PBITMAPCOREHEADER;

typedef struct tagBITMAPINFOHEADER {
    DWORD biSize;
    LONG biWidth;
    LONG biHeight;
    WORD biPlanes;
    WORD biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG biXPelsPerMeter;
    LONG biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
} BITMAPINFOHEADER, *LPBITMAPINFOHEADER, *PBITMAPINFOHEADER;

typedef struct tagRGBQUAD {
    BYTE rgbBlue;
    BYTE rgbGreen;
    BYTE rgbRed;
    BYTE rgbReserved;
} RGBQUAD;
typedef RGBQUAD* LPRGBQUAD;

typedef struct _BLENDFUNCTION {
    BYTE BlendOp;
    BYTE BlendFlags;
    BYTE SourceConstantAlpha;
    BYTE AlphaFormat;
} BLENDFUNCTION, *PBLENDFUNCTION;

typedef struct tagCREATESTRUCTW {
    LPVOID lpCreateParams;
    HINSTANCE hInstance;
    HMENU hMenu;
    HWND hwndParent;
    int cy;
    int cx;
    int y;
    int x;
    LONG style;
    LPCWSTR lpszName;
    LPCWSTR lpszClass;
    DWORD dwExStyle;
} CREATESTRUCTW, *LPCREATESTRUCTW;

typedef struct tagBITMAPINFO {
    BITMAPINFOHEADER bmiHeader;
    RGBQUAD bmiColors[1];
} BITMAPINFO, *LPBITMAPINFO, *PBITMAPINFO;

typedef struct _ICONINFO {
    BOOL fIcon;
    DWORD xHotspot;
    DWORD yHotspot;
    HBITMAP hbmMask;
    HBITMAP hbmColor;
} ICONINFO;
typedef ICONINFO* PICONINFO;

typedef struct tagTPMPARAMS {
    UINT cbSize; /* Size of structure */
    RECT rcExclude; /* Screen coordinates of rectangle to exclude when positioning */
} TPMPARAMS;
typedef TPMPARAMS* LPTPMPARAMS;

typedef LRESULT (*WNDPROC)(HWND, UINT, WPARAM, LPARAM);
typedef BYTE BOOLEAN;

typedef struct tagWNDCLASSW {
    UINT style;
    WNDPROC lpfnWndProc;
    int cbClsExtra;
    int cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCWSTR lpszMenuName;
    LPCWSTR lpszClassName;
} WNDCLASSW, *PWNDCLASSW, *NPWNDCLASSW, *LPWNDCLASSW;

typedef struct tagMINMAXINFO {
    POINT ptReserved;
    POINT ptMaxSize;
    POINT ptMaxPosition;
    POINT ptMinTrackSize;
    POINT ptMaxTrackSize;
} MINMAXINFO, *PMINMAXINFO, *LPMINMAXINFO;

typedef struct tagWNDCLASSEXW {
    UINT cbSize;
    /* Win 3.x */
    UINT style;
    WNDPROC lpfnWndProc;
    int cbClsExtra;
    int cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCWSTR lpszMenuName;
    LPCWSTR lpszClassName;
    /* Win 4.0 */
    HICON hIconSm;
} WNDCLASSEXW, *PWNDCLASSEXW, *NPWNDCLASSEXW, *LPWNDCLASSEXW;

typedef WNDCLASSW WNDCLASS;

typedef struct tagPAINTSTRUCT {
    HDC hdc;
    BOOL fErase;
    RECT rcPaint;
    BOOL fRestore;
    BOOL fIncUpdate;
    BYTE rgbReserved[32];
} PAINTSTRUCT, *PPAINTSTRUCT, *NPPAINTSTRUCT, *LPPAINTSTRUCT;

typedef struct tagMONITORINFO {
    DWORD cbSize;
    RECT rcMonitor;
    RECT rcWork;
    DWORD dwFlags;
} MONITORINFO, *LPMONITORINFO;

typedef union _ULARGE_INTEGER {
    struct {
        DWORD LowPart;
        DWORD HighPart;
    } u;
    unsigned __int64 QuadPart;
} ULARGE_INTEGER;

typedef union _LARGE_INTEGER {
    struct {
        DWORD LowPart;
        LONG HighPart;
    } u;
    unsigned __int64 QuadPart;
} LARGE_INTEGER;

typedef struct _FILETIME {
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
} FILETIME, *PFILETIME, *LPFILETIME;

typedef struct _WIN32_FIND_DATAW {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
    DWORD dwReserved0;
    DWORD dwReserved1;
    WCHAR cFileName[MAX_PATH];
    WCHAR cAlternateFileName[14];
} WIN32_FIND_DATAW, *PWIN32_FIND_DATAW, *LPWIN32_FIND_DATAW;

typedef struct _BY_HANDLE_FILE_INFORMATION {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD dwVolumeSerialNumber;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
    DWORD nNumberOfLinks;
    DWORD nFileIndexHigh;
    DWORD nFileIndexLow;
} BY_HANDLE_FILE_INFORMATION, *PBY_HANDLE_FILE_INFORMATION, *LPBY_HANDLE_FILE_INFORMATION;

typedef struct tagBITMAPFILEHEADER {
    WORD bfType;
    DWORD bfSize;
    WORD bfReserved1;
    WORD bfReserved2;
    DWORD bfOffBits;
} BITMAPFILEHEADER, *LPBITMAPFILEHEADER, *PBITMAPFILEHEADER;

typedef INT_PTR (*FARPROC)(void);

typedef VOID (*TIMERPROC)(HWND, UINT, UINT_PTR, DWORD);

typedef DWORD (*PTHREAD_START_ROUTINE)(LPVOID lpThreadParameter);
typedef PTHREAD_START_ROUTINE LPTHREAD_START_ROUTINE;

typedef INT_PTR (*PROC)(void);
//-----

EXTERN_C void DebugBreak();
EXTERN_C VOID OutputDebugStringA(LPCSTR lpOutputString);
EXTERN_C VOID OutputDebugStringW(LPCWSTR lpOutputString);
EXTERN_C HMODULE GetModuleHandleW(LPCWSTR lpModuleName);

EXTERN_C BOOL SetForegroundWindow(HWND hWnd);

EXTERN_C BOOL PostMessageW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
EXTERN_C BOOL TextOutW(HDC hdc, int x, int y, LPCWSTR lpString, int c);
EXTERN_C BOOL GetClientRect(HWND hWnd, LPRECT lpRect);
EXTERN_C HPEN CreatePen(int iStyle, int cWidth, COLORREF color);
EXTERN_C ATOM RegisterClassExW(CONST WNDCLASSEXW*);
EXTERN_C int GetObject(HANDLE h, int c, LPVOID pv);
EXTERN_C BOOL DeleteObject(HGDIOBJ ho);
EXTERN_C HDC GetDC(HWND hWnd);
EXTERN_C HDC GetDCEx(HWND hWnd, HRGN hrgnClip, DWORD flags);
EXTERN_C int ReleaseDC(HWND hWnd, HDC hDC);
EXTERN_C void* GetProcAddress(HMODULE hModule, LPCSTR lpProcName);
EXTERN_C HDC CreateCompatibleDC(HDC hdc);
EXTERN_C HGDIOBJ GetCurrentObject(HDC hdc, UINT type);
EXTERN_C HGDIOBJ SelectObject(HDC hdc, HGDIOBJ h);
EXTERN_C int SetBkMode(HDC hdc, int mode);
EXTERN_C COLORREF SetBkColor(HDC hdc, COLORREF color);
EXTERN_C HBITMAP CreateBitmap(int nWidth, int nHeight, UINT nPlanes, UINT nBitCount, const void* lpBits);
EXTERN_C HICON CreateIconIndirect(PICONINFO piconinfo);
EXTERN_C HBITMAP CreateCompatibleBitmap(HDC hdc, int cx, int cy);
EXTERN_C COLORREF SetTextColor(HDC hdc, COLORREF color);
EXTERN_C BOOL BitBlt(HDC hdc, int x, int y, int cx, int cy, HDC hdcSrc, int x1, int y1, DWORD rop);
EXTERN_C BOOL TranslateMessage(CONST MSG* lpMsg);
EXTERN_C BOOL PeekMessageW(MSG* lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg);
EXTERN_C LRESULT DispatchMessageW(CONST MSG* lpMsg);
EXTERN_C VOID Sleep(DWORD dwMilliseconds);
EXTERN_C LRESULT DefWindowProcW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
EXTERN_C ATOM RegisterClassW(CONST WNDCLASSW* lpWndClass);
EXTERN_C HICON LoadIconW(HINSTANCE hInstance, LPCWSTR lpIconName);
EXTERN_C HCURSOR LoadCursorW(HINSTANCE hInstance, LPCWSTR lpCursorName);
EXTERN_C HANDLE CreateEventW(LPSECURITY_ATTRIBUTES lpEventAttributes, BOOL bManualReset, BOOL bInitialState, LPCWSTR lpName);
EXTERN_C HANDLE FindFirstFileW(LPCWSTR lpFileName, LPWIN32_FIND_DATAW lpFindFileData);
EXTERN_C BOOL FindClose(HANDLE hFindFile);
EXTERN_C BOOL PathAppendW(LPWSTR pszPath, LPCWSTR pMore);
EXTERN_C DWORD GetTempPathW(DWORD nBufferLength, LPWSTR lpBuffer);
EXTERN_C BOOL FindNextFileW(HANDLE hFindFile, LPWIN32_FIND_DATAW lpFindFileData);
EXTERN_C HWND CreateWindowExW(DWORD dwExStyle, LPCWSTR lpClassName, LPCWSTR lpWindowName, DWORD dwStyle, int X, int Y, int nWidth, int nHeight, HWND hWndParent,
    HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam);
EXTERN_C BOOL ShowWindow(HWND hWnd, int nCmdShow);

EXTERN_C HFONT CreateFontW(int cHeight, int cWidth, int cEscapement, int cOrientation, int cWeight, DWORD bItalic, DWORD bUnderline, DWORD bStrikeOut,
    DWORD iCharSet, DWORD iOutPrecision, DWORD iClipPrecision, DWORD iQuality, DWORD iPitchAndFamily, LPCWSTR pszFaceName);

EXTERN_C BOOL CloseHandle(HANDLE hObject);
EXTERN_C BOOL SetWindowPos(HWND hWnd, HWND hWndInsertAfter, int X, int Y, int cx, int cy, UINT uFlags);
EXTERN_C HANDLE CreateThread(
    void* lpThreadAttributes, SIZE_T dwStackSize, LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId);
EXTERN_C BOOL PathRemoveFileSpecW(LPWSTR pszPath);
EXTERN_C DWORD GetModuleFileNameW(HMODULE hModule, LPWSTR lpFilename, DWORD nSize);
EXTERN_C HMODULE LoadLibraryW(LPCWSTR lpLibFileName);
EXTERN_C int MessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType);
EXTERN_C int MessageBoxW(HWND hWnd, LPCWSTR lpText, LPCWSTR lpCaption, UINT uType);
EXTERN_C BOOL SetPropW(HWND hWnd, LPCWSTR lpString, HANDLE hData);
EXTERN_C HANDLE GetPropW(HWND hWnd, LPCWSTR lpString);

EXTERN_C BOOL DestroyWindow(HWND hWnd);
EXTERN_C int GetDeviceCaps(HDC hdc, int index);
EXTERN_C BOOL GetTextExtentPoint32W(HDC hdc, LPCWSTR lpString, int c, LPSIZE psizl);
EXTERN_C BOOL GetCursorPos(POINT* lpPoint);
EXTERN_C BOOL ClientToScreen(HWND hWnd, LPPOINT lpPoint);
EXTERN_C HWND GetActiveWindow();
EXTERN_C HWND GetParent(HWND hWnd);
EXTERN_C BOOL EnableWindow(HWND hWnd, BOOL bEnable);

EXTERN_C VOID SetLastError(DWORD dwErrCode);

EXTERN_C BOOL SetRectRgn(HRGN hrgn, int left, int top, int right, int bottom);
EXTERN_C int CombineRgn(HRGN hrgnDst, HRGN hrgnSrc1, HRGN hrgnSrc2, int iMode);

EXTERN_C DWORD GetClipboardSequenceNumber();
EXTERN_C BOOL IsClipboardFormatAvailable(UINT format);

EXTERN_C HMONITOR MonitorFromPoint(POINT pt, DWORD dwFlags);
EXTERN_C BOOL GetMonitorInfoW(HMONITOR hMonitor, LPMONITORINFO lpmi);
EXTERN_C DWORD GetCurrentThreadId();
EXTERN_C DWORD GetWindowThreadProcessId(HWND hWnd, LPDWORD lpdwProcessId);
EXTERN_C UINT_PTR SetTimer(HWND hWnd, UINT_PTR nIDEvent, UINT uElapse, TIMERPROC lpTimerFunc);
EXTERN_C HDC BeginPaint(HWND hWnd, LPPAINTSTRUCT lpPaint);
EXTERN_C BOOL EndPaint(HWND hWnd, CONST PAINTSTRUCT* lpPaint);
EXTERN_C BOOL Rectangle(HDC hdc, int left, int top, int right, int bottom);
EXTERN_C BOOL UpdateWindow(HWND hWnd);
EXTERN_C HRGN CreateRectRgn(int x1, int y1, int x2, int y2);
EXTERN_C BOOL KillTimer(HWND hWnd, UINT_PTR uIDEvent);
EXTERN_C BOOL IsWindow(HWND hWnd);
EXTERN_C HRESULT RevokeDragDrop(HWND hwnd);
EXTERN_C BOOL GetWindowRect(HWND hWnd, LPRECT lpRect);
#define GetWindowLongPtrW GetWindowLongW
#define SetWindowLongPtrW SetWindowLongW
EXTERN_C LONG SetWindowLongW(HWND hWnd, int nIndex, LONG dwNewLong);
EXTERN_C LONG GetWindowLongW(HWND hWnd, int nIndex);
EXTERN_C BOOL DestroyIcon(HICON hIcon);
EXTERN_C HCURSOR SetCursor(HCURSOR hCursor);
EXTERN_C HCURSOR linuxSetCursor(HWND hWnd, HCURSOR hCursor);
EXTERN_C HWND GetFocus();
EXTERN_C BOOL ScreenToClient(HWND hWnd, LPPOINT lpPoint);
EXTERN_C HRESULT OleInitialize(IN LPVOID pvReserved);
#if defined(__cplusplus)
class IDropTarget;
HRESULT RegisterDragDrop(HWND hwnd, IDropTarget* pDropTarget);
#endif
EXTERN_C SHORT GetKeyState(int nVirtKey);

EXTERN_C DWORD TlsAlloc();
EXTERN_C LPVOID TlsGetValue(DWORD dwTlsIndex);
EXTERN_C BOOL TlsSetValue(DWORD dwTlsIndex, LPVOID lpTlsValue);
EXTERN_C BOOL TlsFree(DWORD dwTlsIndex);

EXTERN_C uintptr_t MbTlsAlloc();
EXTERN_C LPVOID MbTlsGetValue(uintptr_t dwTlsIndex);
EXTERN_C BOOL MbTlsSetValue(uintptr_t dwTlsIndex, LPVOID lpTlsValue);
EXTERN_C BOOL MbTlsFree(uintptr_t dwTlsIndex);

EXTERN_C DWORD GetFileSize(HANDLE hFile, LPDWORD lpFileSizeHigh);
EXTERN_C BOOL ReadFile(HANDLE hFile, LPVOID lpBuffer, DWORD nNumberOfBytesToRead, LPDWORD lpNumberOfBytesRead, void* lpOverlapped);
EXTERN_C DWORD GetCurrentProcessId();
EXTERN_C HANDLE CreateFileA(LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile);
EXTERN_C HANDLE CreateFileW(LPCWSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile);
EXTERN_C BOOL WriteFile(HANDLE hFile, const VOID* lpBuffer, DWORD nNumberOfBytesToWrite, LPDWORD lpNumberOfBytesWritten, void* lpOverlapped);
EXTERN_C LPWSTR PathFindFileNameW(LPWSTR pszPath);

EXTERN_C LPVOID GlobalLock(HGLOBAL hMem);
EXTERN_C BOOL GlobalUnlock(HGLOBAL hMem);
EXTERN_C HGLOBAL GlobalFree(HGLOBAL hMem);
EXTERN_C HGLOBAL GlobalAlloc(UINT uFlags, SIZE_T dwBytes);
EXTERN_C SIZE_T GlobalSize(HGLOBAL hMem);
EXTERN_C BOOL EmptyClipboard();
EXTERN_C HANDLE SetClipboardData(UINT uFormat, HANDLE hMem);
EXTERN_C BOOL DeleteDC(HDC hdc);

EXTERN_C BOOL ImpersonateAnonymousToken(HANDLE ThreadHandle);

EXTERN_C HANDLE GetCurrentThread();
EXTERN_C BOOL RevertToSelf();
EXTERN_C BOOL OpenClipboard(HWND hWndNewOwner);
EXTERN_C BOOL CloseClipboard();

EXTERN_C void InitializeCriticalSection(CRITICAL_SECTION* lpCriticalSection);
EXTERN_C void EnterCriticalSection(CRITICAL_SECTION* lpCriticalSection);
EXTERN_C void LeaveCriticalSection(CRITICAL_SECTION* lpCriticalSection);
EXTERN_C VOID DeleteCriticalSection(CRITICAL_SECTION* lpCriticalSection);
EXTERN_C BOOL TryEnterCriticalSection(CRITICAL_SECTION* lpCriticalSection);
EXTERN_C BOOL AppendMenuW(HMENU hMenu, UINT uFlags, UINT_PTR uIDNewItem, LPCWSTR lpNewItem);
EXTERN_C BOOL DestroyMenu(HMENU hMenu);
EXTERN_C HMENU CreatePopupMenu();
EXTERN_C int GetMenuItemCount(HMENU hMenu);
EXTERN_C BOOL ReleaseCapture();
EXTERN_C HWND SetCapture(HWND hWnd);
EXTERN_C BOOL PtInRect(CONST RECT* lprc, POINT pt);
EXTERN_C BOOL IsWindowVisible(HWND hWnd);
EXTERN_C UINT GetDoubleClickTime();
EXTERN_C HWND SetFocus(HWND hWnd);
EXTERN_C BOOL SystemParametersInfoW(UINT uiAction, UINT uiParam, PVOID pvParam, UINT fWinIni);
EXTERN_C BOOL TrackPopupMenuEx(HMENU, UINT, int, int, HWND, LPTPMPARAMS);
EXTERN_C HRESULT CoInitializeEx(LPVOID pvReserved, DWORD dwCoInit);
EXTERN_C DWORD GetLastError(VOID);
EXTERN_C void PathStripPathW(LPWSTR pszPath);

EXTERN_C DWORD WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds);
EXTERN_C BOOL UnregisterClassW(LPCWSTR lpClassName, HINSTANCE hInstance);
EXTERN_C UINT RegisterWindowMessageW(LPCWSTR lpString);
EXTERN_C BOOL SetEvent(HANDLE hEvent);
EXTERN_C UINT timeBeginPeriod(UINT uPeriod);
EXTERN_C UINT timeEndPeriod(UINT uPeriod);
EXTERN_C HANDLE GetClipboardData(UINT uFormat);
EXTERN_C BOOL QueryPerformanceCounter(LARGE_INTEGER* lpPerformanceCount);
EXTERN_C DWORD GetTickCount();
EXTERN_C BOOL AlphaBlend(
    HDC hdcDest, int xoriginDest, int yoriginDest, int wDest, int hDest, HDC hdcSrc, int xoriginSrc, int yoriginSrc, int wSrc, int hSrc, BLENDFUNCTION ftn);
EXTERN_C BOOL GdiAlphaBlend(
    HDC hdcDest, int xoriginDest, int yoriginDest, int wDest, int hDest, HDC hdcSrc, int xoriginSrc, int yoriginSrc, int wSrc, int hSrc, BLENDFUNCTION ftn);
EXTERN_C HBITMAP CreateDIBSection(HDC hdc, CONST BITMAPINFO* lpbmi, UINT usage, VOID** ppvBits, HANDLE hSection, DWORD offset);
EXTERN_C BOOL UpdateLayeredWindow(
    HWND hWnd, HDC hdcDst, POINT* pptDst, SIZE* psize, HDC hdcSrc, POINT* pptSrc, COLORREF crKey, BLENDFUNCTION* pblend, DWORD dwFlags);

EXTERN_C VOID GetSystemTime(SYSTEMTIME* lpSystemTime);
EXTERN_C BOOL QueryPerformanceFrequency(LARGE_INTEGER* lpFrequency);

EXTERN_C /*FILE*/ void* _wfopen(const WCHAR* _FileName, const WCHAR* _Mode);
EXTERN_C HINSTANCE ShellExecuteA(HWND hwnd, LPCSTR lpOperation, LPCSTR lpFile, LPCSTR lpParameters, LPCSTR lpDirectory, INT nShowCmd);
EXTERN_C BOOL PathFileExistsW(LPCWSTR pszPath);
EXTERN_C DWORD GetCurrentDirectoryW(DWORD nBufferLength, LPWSTR lpBuffer);
EXTERN_C BOOL InvalidateRect(HWND hWnd, CONST RECT* lpRect, BOOL bErase);
EXTERN_C BOOL GetClassInfoExW(HINSTANCE hInstance, LPCWSTR lpszClass, LPWNDCLASSEXW lpwcx);
EXTERN_C BOOL GetClassInfoW(HINSTANCE hInstance, LPCWSTR lpClassName, LPWNDCLASSW lpWndClass);
EXTERN_C void DragAcceptFiles(HWND hWnd, BOOL fAccept);
EXTERN_C HANDLE RemovePropW(HWND hWnd, LPCWSTR lpString);
EXTERN_C BOOL IntersectRect(LPRECT lprcDst, CONST RECT* lprcSrc1, CONST RECT* lprcSrc2);
EXTERN_C UINT DragQueryFileW(HDROP hDrop, UINT iFile, LPWSTR lpszFile, UINT cch);
EXTERN_C BOOL SetWindowTextW(HWND hWnd, LPCWSTR lpString);
EXTERN_C void DragFinish(HDROP hDrop);
EXTERN_C HGDIOBJ GetStockObject(int i);

EXTERN_C int GetSystemMetrics(int nIndex);
EXTERN_C BOOL MoveWindow(HWND hWnd, int X, int Y, int nWidth, int nHeight, BOOL bRepaint);
EXTERN_C LONG ImmGetCompositionStringW(HIMC, DWORD, LPVOID lpBuf, DWORD dwBufLen);
EXTERN_C BOOL DeleteFileW(LPCWSTR lpFileName);
EXTERN_C BOOL TerminateProcess(HANDLE hProcess, UINT uExitCode);
EXTERN_C void CoUninitialize(void);
EXTERN_C VOID GetLocalTime(LPSYSTEMTIME lpSystemTime);
EXTERN_C BOOL PostThreadMessageW(DWORD idThread, UINT Msg, WPARAM wParam, LPARAM lParam);
EXTERN_C BOOL GetMessageW(MSG* lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax);
EXTERN_C int GetWindowTextW(HWND hWnd, LPWSTR lpString, int nMaxCount);
EXTERN_C VOID PostQuitMessage(int nExitCode);
EXTERN_C HBRUSH CreateSolidBrush(COLORREF color);
EXTERN_C int FillRect(HDC hDC, CONST RECT* lprc, HBRUSH hbr);
EXTERN_C LRESULT SendMessageW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
EXTERN_C BOOL PtInRegion(HRGN hrgn, int x, int y);
EXTERN_C HRGN CreateRectRgnIndirect(CONST RECT* lprect);
EXTERN_C BOOL SetWorldTransform(HDC hdc, CONST XFORM* lpxf);
EXTERN_C BOOL GdiFlush(void);
EXTERN_C BOOL UnmapViewOfFile(const void* lpBaseAddress);
EXTERN_C void* MapViewOfFile(HANDLE hFileMappingObject, DWORD dwDesiredAccess, DWORD dwFileOffsetHigh, DWORD dwFileOffsetLow, SIZE_T dwNumberOfBytesToMap);
EXTERN_C int SelectClipRgn(HDC hdc, HRGN hrgn);
EXTERN_C BOOL SetBrushOrgEx(HDC hdc, int x, int y, LPPOINT lppt);
EXTERN_C COLORREF SetDCBrushColor(HDC hdc, COLORREF color);
EXTERN_C COLORREF SetDCPenColor(HDC hdc, COLORREF color);
EXTERN_C int SetGraphicsMode(HDC hdc, int iMode);
EXTERN_C int SetStretchBltMode(HDC hdc, int mode);
EXTERN_C int SetArcDirection(HDC hdc, int dir);
EXTERN_C int SetROP2(HDC hdc, int rop2);
EXTERN_C BOOL CreateDirectoryW(LPCWSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes);
EXTERN_C BOOL RemoveDirectoryW(LPCWSTR lpPathName);
EXTERN_C int SHCreateDirectoryExW(HWND hwnd, LPCWSTR pszPath, const void* psa);
EXTERN_C BOOL GetFileInformationByHandle(HANDLE hFile, LPBY_HANDLE_FILE_INFORMATION lpFileInformation);
EXTERN_C BOOL FreeLibrary(HMODULE hLibModule);
EXTERN_C HRESULT SHGetFolderPathW(HWND hwnd, int csidl, HANDLE hToken, DWORD dwFlags, LPWSTR pszPath);
EXTERN_C DWORD SetFilePointer(HANDLE hFile, LONG lDistanceToMove, LONG* lpDistanceToMoveHigh, DWORD dwMoveMethod);
EXTERN_C int GetLocaleInfoW(LCID Locale, LCTYPE LCType, LPWSTR lpLCData, int cchData);
EXTERN_C BOOL PathIsDirectoryW(LPCWSTR pszPath);
EXTERN_C HIMC ImmGetContext(HWND);
EXTERN_C BOOL ImmSetCompositionWindow(HIMC, LPCOMPOSITIONFORM lpCompForm);
EXTERN_C BOOL ImmReleaseContext(HWND, HIMC);

EXTERN_C void ExitProcess(UINT uExitCode);
EXTERN_C BOOL IsZoomed(HWND hWnd);
EXTERN_C BOOL IsIconic(HWND hWnd);
EXTERN_C HIMC ImmAssociateContext(HWND, HIMC);
EXTERN_C BOOL IsWindowEnabled(HWND hWnd);
EXTERN_C BOOL SetMenu(HWND hWnd, HMENU hMenu);
EXTERN_C BOOL TrackPopupMenu(HMENU hMenu, UINT uFlags, int x, int y, int nReserved, HWND hWnd, const RECT* prcRect);
EXTERN_C BOOL SetMenuItemInfoW(HMENU hmenu, UINT item, BOOL fByPositon, MENUITEMINFOW* lpmii);
EXTERN_C BOOL GetMenuItemInfoW(HMENU hmenu, UINT item, BOOL fByPosition, MENUITEMINFOW* lpmii);
EXTERN_C HMENU CreateMenu();
EXTERN_C BOOL InsertMenuItemW(HMENU hmenu, UINT item, BOOL fByPosition, MENUITEMINFOW* lpmi);
EXTERN_C BOOL EnableMenuItem(HMENU hMenu, UINT uIDEnableItem, UINT uEnable);
EXTERN_C HMENU GetSystemMenu(HWND hWnd, BOOL bRevert);
//////////////////////////////////////////////////////////////////////////
typedef struct _cairo_surface cairo_surface_t;

void SetLinuxOpenglDraw(BOOL b);
BOOL IsLinuxOpenglDraw();
EXTERN_C cairo_surface_t* LinuxGdiCreateSurfaceByHwnd(HWND hwnd, int w, int h);
EXTERN_C HWND LinuxGdiBindWindowByGtk(
    void* rootWindow, void* drawingArea, BOOL isGl, DWORD dwExStyle, LPCWSTR lpClassName, DWORD dwStyle, int nWidth, int nHeight, LPVOID lpParam);

void* HwndToGtkWindow(HWND hwnd);

#endif // _WIN32
#endif // WINDOWS_FOR_LINUX_H