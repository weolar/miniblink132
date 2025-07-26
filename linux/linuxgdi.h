
#ifndef linux_linuxwinimpl_h
#define linux_linuxwinimpl_h

#include <gtk/gtk.h>
#include <unistd.h>
#include <map>
#include <set>
#include <pthread.h>
#include "windows.h"

class ShaderGl;

class HwndLinux {
public:
    GtkWidget* m_window = nullptr;

    GtkWidget* getDrawingAreaOrGl()
    {
        if (m_drawingArea)
            return m_drawingArea;
        return m_glArea;
    }

    GtkWidget* m_drawingArea = nullptr;
    GtkWidget* m_glArea = nullptr;

    WNDPROC m_wndProc;
    LPVOID m_userdata;

    //unsigned int m_glPositionBuffer = 0;
    //unsigned int m_glProgram = 0;
    ShaderGl* m_glShader = nullptr;
    unsigned int m_glTexture = 0;

    cairo_surface_t* m_surface;

    DWORD m_style;
    DWORD m_styleex;

    DWORD m_threadId;

    HwndLinux();
    ~HwndLinux();

    void updataPosOnScreen();

    /* Redraw the screen from the surface. Note that the ::draw
    * signal receives a ready-to-be-used cairo_t that is already
    * clipped to only draw the exposed areas of the widget
    */
    static gboolean onDraw(GtkWidget* widget, cairo_t* cr, gpointer data);
    static gboolean onExposeEvent(GtkWidget* widget, GdkEventExpose* event, gpointer data);

    static gboolean onRenderGlTextures(GtkGLArea* area, GdkGLContext* context, gpointer data);

    /* Create a new surface of the appropriate size to store our scribbles */
    static void onDestroy(GtkWidget* widget, gpointer data);
    static gboolean onDeleteEvent(GtkWidget* widget, GdkEvent* event, gpointer data);
    static gboolean onConfigureEvent(GtkWidget* widget, GdkEventConfigure* event, gpointer data);
    static gboolean onMotionNotifyEvent(GtkWidget* widget, GdkEventMotion* event, gpointer data);
    static gboolean onButtonPressEvent(GtkWidget* widget, GdkEventButton* event, gpointer data);
    static gboolean onButtonReleaseEvent(GtkWidget* widget, GdkEventButton* event, gpointer data);
    static gboolean onScroll(GtkWidget* widget, GdkEventScroll* event, gpointer data);
    static gboolean onKeyPress(GtkWidget* widget, GdkEventKey* event, gpointer data);
    static gboolean onKeyRelease(GtkWidget* widget, GdkEventKey* event, gpointer data);
    static gboolean onFocusOut(GtkWidget* widget, GdkEventFocus* event, gpointer data);

    void clearSurface(void);

    void* m_msgPtr; // 不同消息不同含义的指针
    pthread_mutex_t m_propsMutex;
    std::map<unsigned int, void*> m_props;

    int m_rootX;
    int m_rootY;

    static void destroy(HWND hWnd, bool forceDelete);
    HWND m_hWnd = nullptr; // 以后会把HWND和HwndLinux区分开。现在暂时是同一个值。
    bool m_autoHandleClose = false; // true表示整个窗口mb接管；false表示窗口是外部创建好的，外部负责关闭
    bool m_isDestroying;

    static std::map<int, WNDCLASSEXW*>* s_wndClassMap;
    static std::set<HWND>* s_hwnds;
    static pthread_mutex_t s_hwndMutex;
};

#endif // linux_linuxwinimpl_h