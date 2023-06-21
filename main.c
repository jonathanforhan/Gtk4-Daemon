#include <gtk/gtk.h>
#include <unistd.h>

#define CHILD 0

static GtkApplication *app;
static int status;

static void
activate(GtkApplication *app, gpointer data)
{
    g_print("Daemon started with pid: %d\n", getpid());
}

int
main(int argc, char *argv[])
{
    app = gtk_application_new("org.gtk4daemon.sleeper", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
