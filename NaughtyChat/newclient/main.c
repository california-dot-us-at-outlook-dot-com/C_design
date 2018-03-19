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


//发消息g窗口的组件
	GtkWidget* table;            //(sizeof(GtkWidget));;
	GtkWidget* button_message;
	GtkWidget* window;            //(sizeof(GtkWidget));
	GtkWidget* label_name;            //(sizeof(GtkWidget));
	GtkWidget* label_getm;            //(sizeof(GtkWidget));
	GtkWidget* entry_name;            //(sizeof(GtkWidget));
	GtkWidget* entry_input;            //(sizeof(GtkWidget));
	GtkWidget* button_commit;            //(sizeof(GtkWidget));
	GtkWidget* button_quit;            //(sizeof(GtkWidget));
	GtkWidget* button_list;   

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


datas sedata;
datas redata;



void se_s_si_h(){
    gdk_threads_enter();
    gtk_widget_show_all(window);
    gtk_widget_hide(si_window);
    gdk_threads_leave();
}

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

//套接字 sock
int sock;
///////////////////////////////////////////////////
void f_send_message(){
    strcpy(sedata.confirm,"message");
    gdk_threads_enter();
    strcpy(sedata.sender,gtk_entry_get_text((GtkEntry*)si_entry_name));
    strcpy(sedata.recver,gtk_entry_get_text((GtkEntry*)entry_name));
    strcpy(sedata.message,gtk_entry_get_text((GtkEntry*)entry_input));
    
    gdk_threads_leave();
    send(sock,&sedata,sizeof(sedata),0);
}

void f_window_send(){

	button_message=gtk_button_new_with_label("消息窗口");
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),g_locale_to_utf8("发送消息",-1,NULL,NULL,NULL));
	label_name=gtk_label_new("向此用户发送:");
	label_getm=gtk_label_new("请输入消息:");
	table=gtk_table_new(36,36,TRUE);
	button_commit=gtk_button_new_with_label("发送");
	entry_name=gtk_entry_new_with_max_length(16);
	entry_input=gtk_entry_new_with_max_length(32);
	button_quit=gtk_button_new_with_label("退出");
	button_list=gtk_button_new_with_label("历史联系人");
	
	gtk_table_attach_defaults((GtkTable*)table,label_name,0,12,12,16);
	gtk_table_attach_defaults((GtkTable*)table,label_getm,0,8,18,22);
	gtk_table_attach_defaults((GtkTable*)table,entry_name,13,25,12,16);
	gtk_table_attach_defaults((GtkTable*)table,entry_input,9,30,17,22);
	gtk_table_attach_defaults((GtkTable*)table,button_commit,31,36,18,22);
	gtk_table_attach_defaults((GtkTable*)table,button_list,26,34,12,16);
	gtk_table_attach_defaults((GtkTable*)table,button_message,22,36,23,28);
	gtk_table_attach_defaults((GtkTable*)table,button_quit,24,28,32,35);
	gtk_widget_set_size_request(window,320,480);
//	gtk_widget_set_size_request(entry_input,32,32);
	gtk_container_add(GTK_CONTAINER(window),table);
	//gtk_widget_show(table);
	gtk_widget_show_all(window);

	gtk_signal_connect((GtkObject*)button_commit,"clicked",G_CALLBACK(f_send_message),NULL);

}


void f_send_signup(){
    
    strcpy(sedata.confirm,"signup");
    gdk_threads_enter();
    if(strcmp(gtk_entry_get_text((GtkEntry*)su_entry_passwd),gtk_entry_get_text((GtkEntry*)su_entry_cpasswd))!=0){
        gdk_threads_enter();
        gtk_entry_set_text((GtkEntry*)su_entry_cpasswd,"两次密码输入不一致！");
        gdk_threads_leave();
    }else{
        gdk_threads_enter();
        strcpy(sedata.sender,gtk_entry_get_text((GtkEntry*)su_entry_name));
        strcpy(sedata.message,gtk_entry_get_text((GtkEntry*)su_entry_passwd));
        gdk_threads_leave();
        send(sock,&sedata,sizeof(sedata),0);
    }
    gdk_threads_leave();
}

void* si_s_su_h(){
    
    gdk_threads_enter();
    gtk_widget_show_all(si_window);
    gtk_widget_hide(su_window);
    gdk_threads_leave();
}
//注册界面
void* f_window_signup(){

//	gtk_init(nargc,nargv);//初始化图形界面显示环境
	su_window =gtk_window_new(GTK_WINDOW_TOPLEVEL);
	su_label_name=gtk_label_new("用户名：");
//	gtk_widget_show(su_label_name);
	su_label_passwd=gtk_label_new("密码：");
//	gtk_widget_show(label_passwd);
	gtk_window_set_title(GTK_WINDOW(su_window),g_locale_to_utf8("用户登入",-1,NULL,NULL,NULL));//设置窗口标题
	su_table=gtk_table_new(36,36,TRUE);
	su_entry_name=gtk_entry_new_with_max_length(16);
	su_entry_passwd=gtk_entry_new_with_max_length(16);
    su_entry_cpasswd=gtk_entry_new_with_max_length(16);
    su_label_cpasswd=gtk_label_new("重复密码：");
//  su_button_signin=gtk_button_new_with_label("登入");
	su_button_signup=gtk_button_new_with_label("注册");
	su_label_title=gtk_label_new("聊天软件系统注册界面");
	su_button_quit=gtk_button_new_with_label("退出");

	gtk_table_attach_defaults((GtkTable*)su_table,su_label_title,8,28,6,10);
	gtk_table_attach_defaults((GtkTable*)su_table,su_label_name,6,12,12,16);
	gtk_table_attach_defaults((GtkTable*)su_table,su_label_passwd,6,12,18,22);
	gtk_table_attach_defaults((GtkTable*)su_table,su_label_cpasswd,6,12,22,26);
    gtk_table_attach_defaults((GtkTable*)su_table,su_entry_name,12,24,12,18);
	gtk_table_attach_defaults((GtkTable*)su_table,su_entry_passwd,12,24,18,24);
	gtk_table_attach_defaults((GtkTable*)su_table,su_entry_cpasswd,12,24,25,30);
    gtk_table_attach_defaults((GtkTable*)su_table,su_button_signup,14,18,30,36);
//	gtk_table_attach_defaults((GtkTable*)su_table,su_button_signin,18,23,30,36);
	gtk_table_attach_defaults((GtkTable*)su_table,su_button_quit,26,29,30,36);
	gtk_widget_set_size_request(su_window,480,320);

	gtk_container_add(GTK_CONTAINER(su_window),su_table);

	gtk_entry_set_visibility((GtkEntry*)su_entry_passwd,FALSE);

//	gtk_widget_show_all(su_window);
	
	gtk_signal_connect((GtkObject*)su_button_quit,"clicked",G_CALLBACK(si_s_su_h),NULL);
//    gtk_signal_connect((GtkObject*)su_button_signin,"clicked",G_CALLBACK(f_send_signin),NULL);
	gtk_signal_connect((GtkObject*)su_button_signup,"clicked",G_CALLBACK(f_send_signup),NULL);
	g_signal_connect_swapped(G_OBJECT(su_window),"destroy",G_CALLBACK(si_s_su_h),NULL);
//	gtk_main();
}

void* su_s_si_h(){
    f_window_signup();
    gdk_threads_enter();
    gtk_widget_show_all(su_window);
    gtk_widget_hide(si_window);
    gdk_threads_leave();
}

void f_send_signin(){
    
    strcpy(sedata.confirm,"signin");
    gdk_threads_enter();
    strcpy(sedata.sender,gtk_entry_get_text((GtkEntry*)si_entry_name));
    strcpy(sedata.message,gtk_entry_get_text((GtkEntry*)si_entry_passwd));
    
    gdk_threads_leave();
    send(sock,&sedata,sizeof(sedata),0);
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
	
	gtk_signal_connect((GtkObject*)si_button_quit,"clicked",G_CALLBACK(gtk_main_quit),NULL);
    gtk_signal_connect((GtkObject*)si_button_signin,"clicked",G_CALLBACK(f_send_signin),NULL);
	gtk_signal_connect((GtkObject*)si_button_signup,"clicked",G_CALLBACK(su_s_si_h),NULL);
	g_signal_connect_swapped(G_OBJECT(si_window),"destroy",G_CALLBACK(gtk_main_quit),NULL);
//	gtk_main();
}
////////////////////////////////////////////////////////////////

void* recv_message(void*i){
    char* sender=(char*)malloc(sizeof(char)*16);
    char* message=(char*)malloc(sizeof(char)*32);
    while(1){
	sleep(1);
        recv(sock,&redata,sizeof(datas),0);

        if(strcmp(redata.confirm,"message")==0){
		strcpy(message,redata.message);
            FILE*f=fopen("a.txt","a");
//          fprintf(f,"%s -> ",redata.confirm);
//	    fprintf(f,"%s ","hello,world");
	    printf("%s",sender);
	    printf("%s",redata.message);
	    fprintf(f,"%s ",redata.confirm);
            fprintf(f,"%s ",redata.sender);
            fprintf(f,"%s ",redata.message);
            fclose(f);
            system("firefox a.txt");
	    strcpy(redata.confirm,"");
        }
    }
}




int main(int argc,char**argv){
    pthread_t *ntid=(pthread_t*)malloc(sizeof(pthread_t));
    pthread_t *mtid=(pthread_t*)malloc(sizeof(pthread_t));
    int i=0;
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
    pthread_create(ntid,NULL,recv_message,NULL);
    printf("recving\n");
    gtk_init(NULL,NULL);
    if(quit==1){
        return 0;
    }
    /*线程的初始化*/  
/*    if(!g_thread_supported()){
        g_thread_init(NULL); 
    } 
    gdk_thread_init();  
  */    /*创建线程*/  
//    g_thread_create((GThreadFunc)recvm, NULL, FALSE, NULL);  
//    g_thread_create((GThreadFunc)f_window_signin, NULL, FALSE, NULL);  
//    g_thread_create((GThreadFunc)f_window_signup, NULL, FALSE, NULL);  
//    g_thread_create((GThreadFunc)f_window_sendm, NULL, FALSE, NULL);  
//    g_thread_create((GThreadFunc)f_window_xianshi, NULL, FALSE, NULL);  

//    system("firefox");
    gdk_threads_enter();

    f_window_signin();
    f_window_send();
//    f_window_signup();
//    sleep(10);
    gtk_main();
    gdk_threads_leave();
        if(i<60){
            return 0;
        }
    i++;
    return 0;
}
