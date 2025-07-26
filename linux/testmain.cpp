#if !defined(WIN32)

#include "../../mbvip/core/mb.h"

#include <windows.h>
#include <string>
#include <vector>
#include <unistd.h>
#include <gtk/gtk.h>

#include <stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int testmain();

void createSimpleMb()
{
    //     int fp = open("/home/daniel/Desktop/test_web/flash.html", 0/*O_RDONLY*/);
    //     printf("fp:%d\n", fp);
    //     __debugbreak();

    //mbWebView view = mbCreateWebWindow(MB_WINDOW_TYPE_POPUP, NULL, 0, 0, 840, 680);

    mbWebView view = mbCreateWebWindow(MB_WINDOW_TYPE_POPUP, NULL, 100, 100, 300, 400);
    HWND hWnd = mbGetHostHWND(view);

    ::SetPropW(hWnd, u16("mb"), (HANDLE)view);
    ::mbSetTransparent(view, FALSE);
    ::mbSetHandle(view, hWnd);
    //     ::mbOnPaintUpdated(view, handlePaintUpdatedCallback, hWnd);
    //     ::mbOnPaintBitUpdated(view, onPaintBitUpdatedCallback, nullptr);

    //     ::mbOnDocumentReady(view, handleDocumentReady, (void*)view);
    //     ::mbOnLoadingFinish(view, handleLoadingFinish, (void*)view);
    //     ::mbOnCreateView(view, handleCreateView, (void*)view);
    //     ::mbSetNavigationToNewWindowEnable(view, true);
    //     ::mbSetCspCheckEnable(view, false);

    RECT rc = { 0 };
    ::GetClientRect(hWnd, &rc);
    ::mbResize(view, rc.right, rc.bottom);

    //mbMoveToCenter(view);
    mbShowWindow(view, TRUE);
    ::ShowWindow(hWnd, SW_SHOW);
    //mbSetHeadlessEnabled(view, TRUE);

    //::mbLoadHTML(view, "<html><head><style></style><script type=\"text/javascript\">var test = 'test';</script></head><body></body></html>");
    //https://www.baidu.com/s?wd=123

    //::mbLoadURL(view, "file:///home/daniel/Desktop/test_web/flash.html");
    //::mbLoadURL(view, "http://miniblink.net/");
    ::mbLoadURL(view, "https://baidu.com/");
    //::mbLoadURL(view, "http://192.168.222.1:8000/baidu.htm");
    //::mbLoadURL(view, "http://192.168.222.1:8000/index2.html");
    //     //::mbLoadURL(view, "https://passport.csdn.net/account/login");//http://www.17sucai.com/pins/demo-show?id=23150
    //
    //     mbOnJsQuery(view, onJsQuery, (void*)1);
}

void ASSERT(bool b)
{
    if (!b)
        DebugBreak();
}

int main222(int argc, char* argv[])
{
    gtk_init(&argc, &argv);
    mbSettings* settings = new mbSettings();
    memset(settings, 0, sizeof(mbSettings));

    settings->version = kMbVersion;
    settings->config = "{}";

    mbInit(settings);
    //mbSetUserAgent(NULL_WEBVIEW, "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like XSD) Chrome/79.0.3945.130 Safari/537.36");

    //mbEnableHighDPISupport();
    //mbSetNpapiPluginsEnabled(NULL_WEBVIEW, false);

#if 1
    createSimpleMb();
#else
    testmain();
    gtk_main();
#endif

    printf("mbRunMessageLoop begin\n");
    mbRunMessageLoop();
    printf("mbRunMessageLoop end\n");

    return 0;
}

//////////////////////////////////////////////////////////////////////////

/* Surface to store current scribbles */
static cairo_surface_t* g_surface = NULL;
//GdkPixmap* pixmap_
static void activate(GtkApplication* app, gpointer user_data);
static void close_window(void);
static gboolean motion_notify_event_cb(GtkWidget* widget, GdkEventMotion* event, gpointer data);
static gboolean button_press_event_cb(GtkWidget* widget, GdkEventButton* event, gpointer data);
static void draw_brush(GtkWidget* widget, gdouble x, gdouble y);
static gboolean draw_cb(GtkWidget* widget, cairo_t* cr, gpointer data);
static gboolean configure_event_cb(GtkWidget* widget, GdkEventConfigure* event, gpointer data);
static void clear_surface(void);

static gboolean on_expose_event(cairo_t* cr)
{
    //     int width, height;
    //     gtk_window_get_size(GTK_WINDOW(widget), &width, &height);

    cairo_set_source_rgb(cr, 0.5, 0.5, 1);
    cairo_rectangle(cr, 20.0, 20.0, 100.0, 100.0);
    cairo_fill(cr);

    //     cairo_set_source_rgb(cr, 0.6, 0.6, 0.6);
    //     cairo_rectangle(cr, 150, 20, 100, 100);
    //     cairo_fill(cr);
    //
    //     cairo_set_source_rgb(cr, 0, 0.3, 0);
    //     cairo_rectangle(cr, 20, 140, 100, 100);
    //     cairo_fill(cr);
    //
    //     cairo_set_source_rgb(cr, 1, 0, 0.5);
    //     cairo_rectangle(cr, 150, 140, 100, 100);
    //     cairo_fill(cr);

    //     unsigned char* byteData = cairo_image_surface_get_data(g_surface);
    //     cairo_surface_flush(g_surface);
    //     memset(byteData, 0xAA, 0x200);
    //     cairo_surface_mark_dirty(g_surface);

    return FALSE;
}

int testmain()
{
    GtkWidget* window;
    GtkWidget* frame;
    GtkWidget* drawing_area;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Drawing Area");
    g_signal_connect(window, "destroy", G_CALLBACK(close_window), NULL);
    gtk_container_set_border_width(GTK_CONTAINER(window), 16);

    // »­¸ö¿ò×Ó
    frame = gtk_frame_new(NULL);
    gtk_frame_set_shadow_type(GTK_FRAME(frame), GTK_SHADOW_IN);
    gtk_container_add(GTK_CONTAINER(window), frame);

    drawing_area = gtk_drawing_area_new();
    /* set a minimum size */
    gtk_widget_set_size_request(drawing_area, 150, 150);
    gtk_container_add(GTK_CONTAINER(frame), drawing_area);
    /* Signals used to handle the backing surface */
    g_signal_connect(drawing_area, "draw", G_CALLBACK(draw_cb), NULL);
    g_signal_connect(drawing_area, "configure-event", G_CALLBACK(configure_event_cb), NULL);
    /* Event signals */
    g_signal_connect(drawing_area, "motion-notify-event", G_CALLBACK(motion_notify_event_cb), NULL);
    g_signal_connect(drawing_area, "button-press-event", G_CALLBACK(button_press_event_cb), NULL);

    printf("testmain 1\n");

    /* Ask to receive events the drawing area doesn't normally
    * subscribe to. In particular, we need to ask for the
    * button press and motion notify events that want to handle.
    */
    gtk_widget_set_events(drawing_area, gtk_widget_get_events(drawing_area) | GDK_BUTTON_PRESS_MASK | GDK_POINTER_MOTION_MASK);

    printf("testmain 2\n");
    gtk_widget_show_all(window);
    printf("testmain 333\n");

    //gtk_main();
    return 0;
}

static void close_window(void)
{
    if (g_surface)
        cairo_surface_destroy(g_surface);

    gtk_main_quit();
}

/* Handle motion events by continuing to draw if button 1 is
* still held down. The ::motion-notify signal handler receives
* a GdkEventMotion struct which contains this information.
*/
static gboolean motion_notify_event_cb(GtkWidget* widget, GdkEventMotion* event, gpointer data)
{
    /* paranoia check, in case we haven't gotten a configure event */
    if (g_surface == NULL)
        return FALSE;

    if (event->state & GDK_BUTTON1_MASK)
        draw_brush(widget, event->x, event->y);

    /* We've handled it, stop processing */
    return TRUE;
}

/* Handle button press events by either drawing a rectangle
* or clearing the surface, depending on which button was pressed.
* The ::button-press signal handler receives a GdkEventButton
* struct which contains this information.
*/
static gboolean button_press_event_cb(GtkWidget* widget, GdkEventButton* event, gpointer data)
{
    /* paranoia check, in case we haven't gotten a configure event */
    if (g_surface == NULL)
        return FALSE;

    if (event->button == GDK_BUTTON_PRIMARY) {
        draw_brush(widget, event->x, event->y);
    } else if (event->button == GDK_BUTTON_SECONDARY) {
        clear_surface();
        gtk_widget_queue_draw(widget);
    }

    /* We've handled the event, stop processing */
    return TRUE;
}

/* Draw a rectangle on the surface at the given position */
static void draw_brush(GtkWidget* widget, gdouble x, gdouble y)
{
    cairo_t* cr;

    /* Paint to the surface, where we store our state */
    cr = cairo_create(g_surface);

    cairo_rectangle(cr, x - 3, y - 3, 6, 6);
    cairo_fill(cr);

    cairo_destroy(cr);
    /* Now invalidate the affected region of the drawing area. */
    gtk_widget_queue_draw_area(widget, x - 3, y - 3, 6, 6);

    gtk_widget_queue_draw_area(widget, 0, 0, 500, 600);
}

/* Redraw the screen from the surface. Note that the ::draw
* signal receives a ready-to-be-used cairo_t that is already
* clipped to only draw the exposed areas of the widget
*/
static gboolean draw_cb(GtkWidget* widget, cairo_t* cr, gpointer data)
{
    cairo_t* memoryCr = cairo_create(g_surface);
    on_expose_event(memoryCr);
    cairo_destroy(memoryCr);

    cairo_set_source_surface(cr, g_surface, 0, 0);
    cairo_paint(cr);

    return FALSE;
}

/* Create a new surface of the appropriate size to store our scribbles */
static gboolean configure_event_cb(GtkWidget* widget, GdkEventConfigure* event, gpointer data)
{
    if (g_surface)
        cairo_surface_destroy(g_surface);

    //     g_surface = gdk_window_create_similar_surface(
    //         gtk_widget_get_window(widget),
    //         CAIRO_CONTENT_COLOR,
    //         gtk_widget_get_allocated_width(widget),
    //         gtk_widget_get_allocated_height(widget));
    g_surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, gtk_widget_get_allocated_width(widget), gtk_widget_get_allocated_height(widget));

    /* Initialize the surface to white */
    clear_surface();

    /* We've handled the configure event, no need for further processing. */
    return TRUE;
}

static void clear_surface(void)
{
    cairo_t* cr;

    cr = cairo_create(g_surface);
    cairo_set_source_rgb(cr, 1, 1, 1);
    cairo_paint(cr);
    cairo_destroy(cr);
}

#endif