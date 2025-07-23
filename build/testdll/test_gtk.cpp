#if !defined(_WIN32)

#include <gtk/gtk.h>
#include "windows.h"

static void activate(GtkApplication* app, gpointer user_data) 
{
    GtkWidget* window;
    GtkWidget* label;
    GtkWidget* grid;

    // 创建一个新窗口，并设置其标题和默认大小
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Simple GTK3 Window");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    // 创建一个网格容器
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // 创建一个标签，并设置要显示的文字
    label = gtk_label_new("Hello, this is a simple GTK3 window!");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 1, 1);

    // 显示所有的部件
    gtk_widget_show_all(window);
}

void* threadProc(void* arg)
{
    GtkApplication* app;
    int status;

    // 初始化GTK应用程序
    app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    GMainContext* context = g_main_context_default();
    while (true) {
        g_main_context_iteration(context, FALSE);
        usleep(10);
    }
    
    //status = g_application_run(G_APPLICATION(app), 0, nullptr);
    //g_object_unref(app);
}

int main(int argc, char** argv)
{
    pthread_t tid;
    //pthread_create(&tid, NULL, &threadProc, nullptr);
    threadProc(nullptr);
    usleep(1000000000000);

    return 0;
}

#endif