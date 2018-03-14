//gcc xxx.c -o xxx `pkg-config --libs --cflags gtk+-2.0`
//
#include<gtk/gtk.h>
#include<pthread.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
void func(GtkWidget *botton,gpointer entry){
	g_print("CallBack Successfully!");
	gtk_entry_set_text(entry,"你好哦");
	gtk_main_quit();
}
int main(int argc,char*argv[]){
	GtkWidget*window;//指向窗口的指针
	GtkWidget*table;//指向表格的指针
	GtkWidget*label;//指标签的指针
	GtkWidget*entry;//指向文本框的指针
	GtkWidget*botton;//指向按钮的指针
	gtk_init(&argc,&argv);//初始化图形显示环境
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);//窗口
	gtk_window_set_title(GTK_WINDOW(window),g_locale_to_utf8("用户登录",-1,NULL,NULL,NULL));//设置窗口标题
	//gtk_widget_show(window);//显示窗口
	entry=gtk_entry_new_with_max_length(50);//新建有字数限制的文本框
	table=gtk_table_new(2,3,FALSE);//新建table
	GtkWidget*hbox=gtk_hbox_new(TRUE,10);
	GtkWidget*entry2;
	entry2=gtk_entry_new_with_max_length(20);
	gtk_widget_show(entry2);
	gtk_container_add(GTK_CONTAINER(window),hbox);
	gtk_widget_show(hbox);
	gtk_container_add(GTK_CONTAINER(hbox),entry);//将entry放入hbox中
	gtk_container_add(GTK_CONTAINER(hbox),entry2);
	botton=gtk_button_new_with_label("Hello");
	gtk_container_add(GTK_CONTAINER(hbox),botton);
	gtk_container_add(GTK_CONTAINER(window),table);
	gtk_widget_show(botton);
	gtk_widget_show(window);
	gtk_widget_show(entry);
	g_signal_connect(botton,"pressed",G_CALLBACK(func),entry);
	gtk_main();
	system("dolphin");
	return 0;
	
}
