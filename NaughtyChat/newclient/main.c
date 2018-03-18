#include<stdio.h>
#include<stdlib.h>
#include<gtk/gtk.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include"../head/dataform.h"

int quit;

int *nargc;
char***nargv;

//登入窗口的组件
GtkWidget*si_window;
GtkWidget*si_label_name;
GtkWidget*si_label_passwd;
GtkWidget*si_entry_name;
GtkWidget*si_entry_passwd;
GtkWidget*si_button_signin;
GtkWidget*si_button_signup;
GtkWidget*si_label_title;
GtkWidget*si_table;
GtkWidget*si_button_quit;


//注册窗口的组件
GtkWidget*su_window;
GtkWidget*su_label_name;
GtkWidget*su_label_passwd;
GtkWidget*su_entry_name;
GtkWidget*su_entry_passwd;
GtkWidget*other;
GtkWidget*su_button_signup;
GtkWidget*su_label_title;
GtkWidget*su_label_cpasswd;
GtkWidget*su_entry_cpasswd;
GtkWidget*su_table;
GtkWidget*su_button_quit;



//datas recv;

void f_quit(){
    quit=1;
}
int conn;
int getconnect(char*ip){
	struct sockaddr_in addr;
	int sock=socket(AF_INET,SOCK_STREAM,0);
	int addr_len=sizeof(struct sockaddr_in);
	bzero(&addr,sizeof(struct sockaddr_in));
	addr.sin_family=AF_INET;
	addr.sin_port=htons(56789);
	addr.sin_addr.s_addr=inet_addr(ip);
	
	conn=connect(sock,(struct sockaddr*)(&addr),sizeof(struct sockaddr));
	
    return sock;
}
int sock;
///////////////////////////////////////////////////

void f_send_signin(){
    
    return;
}

//登录界面
void* f_window_signin(){

//	gtk_init(nargc,nargv);//初始化图形界面显示环境
	si_window =gtk_window_new(GTK_WINDOW_TOPLEVEL);
	si_label_name=gtk_label_new("用户名：");
//	gtk_widget_show(si_label_name);
	si_label_passwd=gtk_label_new("密码：");
//	gtk_widget_show(label_passwd);
	gtk_window_set_title(GTK_WINDOW(si_window),g_locale_to_utf8("用户登入",-1,NULL,NULL,NULL));//设置窗口标题
	si_table=gtk_table_new(36,36,TRUE);
	si_entry_name=gtk_entry_new_with_max_length(16);
	si_entry_passwd=gtk_entry_new_with_max_length(16);
	si_button_signin=gtk_button_new_with_label("登入");
	si_button_signup=gtk_button_new_with_label("注册");
	si_label_title=gtk_label_new("聊天软件系统登入界面");
	si_button_quit=gtk_button_new_with_label("退出");

	gtk_table_attach_defaults((GtkTable*)si_table,si_label_title,8,28,6,10);
	gtk_table_attach_defaults((GtkTable*)si_table,si_label_name,6,12,12,16);
	gtk_table_attach_defaults((GtkTable*)si_table,si_label_passwd,6,12,18,22);
	gtk_table_attach_defaults((GtkTable*)si_table,si_entry_name,12,24,12,18);
	gtk_table_attach_defaults((GtkTable*)si_table,si_entry_passwd,12,24,18,24);
	gtk_table_attach_defaults((GtkTable*)si_table,si_button_signup,14,18,30,36);
	gtk_table_attach_defaults((GtkTable*)si_table,si_button_signin,18,23,30,36);
	gtk_table_attach_defaults((GtkTable*)si_table,si_button_quit,26,29,30,36);
	gtk_widget_set_size_request(si_window,480,320);

	gtk_container_add(GTK_CONTAINER(si_window),si_table);

	gtk_entry_set_visibility((GtkEntry*)si_entry_passwd,FALSE);

	gtk_widget_show_all(si_window);
	
/*	gtk_signal_connect((GtkObject*)si_button_quit,"clicked",G_CALLBACK(f_quit),NULL);
    gtk_signal_connect((GtkObject*)si_button_signin,"clicked",G_CALLBACK(f_send_signin),NULL);
	gtk_signal_connect((GtkObject*)si_button_signup,"clicked",G_CALLBACK(f_window_signup),NULL);
	g_signal_connect_swapped(G_OBJECT(si_window),"destroy",G_CALLBACK(gtk_main_quit),NULL);
*///	gtk_main();
}
////////////////////////////////////////////////////////////////


int main(int argc,char**argv){
    conn=-1;
    while(1){
        printf("正在连接服务器\n");
        if(((sock=getconnect("101.132.123.155"))>0)&&(conn==0)){
            break;
        }
    }
    printf("成功连接到服务器\n");
    nargc=&argc;
    nargv=&argv;
    quit=0;

    gtk_init(NULL,NULL);
    if(quit==1){
        return 0;
    }
    /*线程的初始化*/  
/*    if(!g_thread_supported()){
        g_thread_init(NULL); 
    } 
    gdk_threads_init();  
 */     /*创建线程*/  
//    g_thread_create((GThreadFunc)recvm, NULL, FALSE, NULL);  
//    g_thread_create((GThreadFunc)f_window_signin, NULL, FALSE, NULL);  
//    g_thread_create((GThreadFunc)f_window_signup, NULL, FALSE, NULL);  
//    g_thread_create((GThreadFunc)f_window_sendm, NULL, FALSE, NULL);  
//    g_thread_create((GThreadFunc)f_window_xianshi, NULL, FALSE, NULL);  
    f_window_signin();

    gdk_threads_enter();
    gtk_main();
    gdk_threads_leave();

    return 0;
}