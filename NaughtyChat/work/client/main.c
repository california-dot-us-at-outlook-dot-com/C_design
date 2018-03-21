#include"func.h"

int main(int argc,char **argv){
    GtkWidget*window;
    GtkWidget*vbox,*hbox,*button,*label,*view;
    if(!g_thread_supported()){
        g_thread_init(NULL);
    }
    gtk_init(&argc,&argv);

    window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),"客户端");
    g_signal_connect(G_OBJECT(window),"delete_event",G_CALLBACK(on_delete_event),NULL);
    gtk_container_set_border_width(GTK_CONTAINER(window),10);

    vbox=gtk_vbox_new(FALSE,0);
    gtk_container_add(GTK_CONTAINER(window),vbox);

    hbox=gtk_hbox_new(FALSE,0);
    gtk_box_pack_start(GTK_BOX(vbox),hbox,FALSE,FALSE,5);
    label=gtk_label_new("点击登录服务器");
    gtk_box_pack_start(GTK_BOX(hbox),label,FALSE,FALSE,5);
    login_button=gtk_button_new_with_label("登录");
    gtk_box_pack_start(GTK_BOX(hbox),login_button,FALSE,FALSE,5);
    g_signal_connect(G_OBJECT(login_button),"clicked",G_CALLBACK(on_login),NULL);
    view=gtk_scrolled_window_new(NULL,NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(view),GTK_POLICY_AUTOMATIC,GTK_POLICY_AUTOMATIC);
    text=gtk_text_view_new();
    gtk_box_pack_start(GTK_BOX(vbox),view,TRUE,TRUE,5);
    gtk_container_add(GTK_CONTAINER(view),text);
    buffer=gtk_text_view_get_buffer(GTK_TEXT_VIEW(text));

    hbox=gtk_hbox_new(FALSE,0);
    gtk_box_pack_start(GTK_BOX(vbox),hbox,FALSE,FALSE,5);
    label=gtk_label_new("输入消息:");
    gtk_box_pack_start(GTK_BOX(hbox),label,FALSE,FALSE,5);

    message_entry=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox),message_entry,FALSE,FALSE,5);

    button=gtk_button_new_with_label("发送");
    gtk_box_pack_start(GTK_BOX(hbox),button,FALSE,FALSE,5);
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(on_send),NULL);

    gtk_widget_show_all(window);

    gdk_threads_enter();
    gtk_main();
    gdk_threads_leave();

    return FALSE;

}