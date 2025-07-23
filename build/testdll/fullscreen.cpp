#include <windows.h>

void RegisterMyClass();
LRESULT CALLBACK MainWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
    // 注册窗口类
    RegisterMyClass();

    // 创建窗口
    HWND hwnd = CreateWindow(TEXT("MainWindow"), // 类名
        L"我的应用程序", // 窗口标题文字
        WS_POPUP, // 窗口外观样式
        0, //38, // 窗口相对于父级的x坐标
        10, //20, // 窗口相对于父级的y坐标 GetSystemMetrics (SM_CXSCREEN)：获取屏幕宽度
        GetSystemMetrics(SM_CXSCREEN), //480, // 窗口的宽度 GetSystemMetrics(SM_CYSCREEN)：获取屏幕高度
        GetSystemMetrics(SM_CYSCREEN), //250, // 窗口的高度
        NULL, // 没有父窗口
        NULL, // 没有菜单
        hInstance, // 当前应用程序的实例句柄
        NULL); // 没有附加数据

    if (hwnd == NULL) {
        return 0;
    }

    // 显示窗口
    ShowWindow(hwnd, SW_NORMAL);

    // 更新窗口
    UpdateWindow(hwnd);

    // 消息循环
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

void RegisterMyClass()
{
    WNDCLASS wc;

    wc.lpszClassName = TEXT("MainWindow");
    wc.lpfnWndProc = MainWndProc;
    wc.style = CS_OWNDC | CS_VREDRAW | CS_HREDRAW;
    wc.hInstance = NULL;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    /*
    白色画刷 (HBRUSH)(COLOR_WINDOW + 1);
    黑色画刷
    */
    wc.hbrBackground = (HBRUSH)(GetStockObject(BLACK_BRUSH));
    wc.lpszMenuName = TEXT("FirstWin32");
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;

    RegisterClass(&wc);
}

LRESULT CALLBACK MainWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) {
    case WM_PAINT:
        break;
    case WM_DESTROY:
        PostQuitMessage(uMsg);
        break;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
        break;
    }
}