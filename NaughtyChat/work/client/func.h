#ifndef func_h
#define func_h
#include<gtk/gtk.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define OURPORT 8088

gint sd;
struct sockaddr_in s_in;
gchar username[64];
gchar buf[1024];
gchar get_buf[1048];
gboolean inconnected_1;

// static GtkWidget *text;
// static GtkTextBuffer *buffer;
// static GtkWidget *message_entry;
// static GtkWidget*name_entry;
// static GtkWidget*login_button;

 GtkWidget *text;
 GtkTextBuffer *buffer;
 GtkWidget *message_entry;
 GtkWidget*name_entry;
 GtkWidget*login_button;


void get_message(void);
void on_destroy(GtkWidget*,GdkEvent*,gpointer);
void on_button_clicked(GtkButton *,gpointer);
void create_win(void);
gboolean do_connect(void);
void on_send(GtkButton*,gpointer);
void on_login(GtkWidget*,gpointer);
void on_delete_event(GtkWidget*,GdkEvent*,gpointer);

#endif