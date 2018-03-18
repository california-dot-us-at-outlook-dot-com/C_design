    #include <gtk/gtk.h>  
      
    GtkWidget *window;  
    GtkWidget *label;  
      
    void hello(){  
        int i;  
        for(i=0;;i++){  
            /*使用gdk_thread_*()将要刷新的界面*/  
            char buf[6];  
            sprintf(buf,"%d",(int)i);  
            /*睡眠一下*/  
            sleep(1);  
//            gdk_threads_enter();  
            gtk_label_set_text(GTK_LABEL(label),buf);  
//            gdk_threads_leave();  
            if(i==100)i=0;  
        }  
    }  
      
    int main( int   argc,char *argv[] ){  
        gtk_init (NULL,NULL);//这个函数这样使用不好，但在此例中简写它了  
        /* 创建一个新窗口 */  
        window = gtk_window_new (GTK_WINDOW_TOPLEVEL);  
        gtk_window_set_title(GTK_WINDOW(window),"thread number");  
        gtk_widget_set_usize(GTK_WIDGET(window),200,60);  
        /*创建一个标签*/  
        label=gtk_label_new("0");  
        gtk_container_add (GTK_CONTAINER (window), label);  
        gtk_widget_show (label);  
        gtk_widget_show (window);  
        g_signal_connect (G_OBJECT (window), "destroy",G_CALLBACK(gtk_main_quit), NULL);  
          
        /*线程的初始化*/  
        if(!g_thread_supported()) g_thread_init(NULL);  
        gdk_threads_init();  
        /*创建线程*/  
        g_thread_create((GThreadFunc)hello, NULL, FALSE, NULL);  
          
        gdk_threads_enter();  
        gtk_main ();  
        gdk_threads_leave();     
          
        return 0;  
    }  