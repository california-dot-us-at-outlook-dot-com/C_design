#include<gtk/gtk.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>


int gtk_window_logup(int *argc,char***argv){
	GtkWidget* window;
	GtkWidget* label_name;
	GtkWidget* label_passwd;
	GtkWidget* entry_name;
	GtkWidget* entry_passwd;
	GtkWidget* button_signin;
	GtkWidget* button_signup;
	GtkWidget* other;
	gtk_init(argc,argv);//初始化图形界面显示环境
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	label_name=gtk_label_new("用户名：");
	gtk_widget_show(label_name);
	label_passwd=gtk_label_new("密码：");
	gtk_widget_show(label_passwd);
	gtk_window_set_title(GTK_WINDOW(window),g_locale_to_utf8("用户注册",-1,NULL,NULL,NULL));//设置窗口标题
	GtkWidget* table=gtk_table_new(36,36,TRUE);
	entry_name=gtk_entry_new_with_max_length(20);
	entry_passwd=gtk_entry_new_with_max_length(20);
	//button_signin=gtk_button_new_with_label("登入");
	button_signup=gtk_button_new_with_label("注册");
	GtkWidget* label_title=gtk_label_new("聊天软件系统注册界面");
	GtkWidget* button_quit=gtk_button_new_with_label("退出");
	GtkWidget* label_cpasswd=gtk_label_new("重复密码：");
	GtkWidget* entry_cpasswd=gtk_entry_new_with_max_length(20);

	gtk_table_attach_defaults((GtkTable*)table,label_title,8,28,6,10);
	gtk_table_attach_defaults((GtkTable*)table,label_name,6,12,12,16);
	gtk_table_attach_defaults((GtkTable*)table,label_passwd,6,12,18,22);
	gtk_table_attach_defaults((GtkTable*)table,entry_name,12,24,12,18);
	gtk_table_attach_defaults((GtkTable*)table,entry_cpasswd,12,24,23,25);
	gtk_table_attach_defaults((GtkTable*)table,label_cpasswd,6,12,23,25);
	gtk_table_attach_defaults((GtkTable*)table,entry_passwd,12,24,18,24);
	gtk_table_attach_defaults((GtkTable*)table,button_signup,14,18,30,36);
//	gtk_table_attach_defaults((GtkTable*)table,button_signin,18,23,30,36);
	gtk_table_attach_defaults((GtkTable*)table,button_quit,26,29,30,36);
	gtk_widget_set_size_request(window,480,320);

	gtk_container_add(GTK_CONTAINER(window),table);

	gtk_entry_set_visibility((GtkEntry*)entry_passwd,FALSE);
	gtk_entry_set_visibility((GtkEntry*)entry_cpasswd,FALSE);

	gtk_widget_show_all(window);

	gtk_main();
}

int gtk_window_login(int *argc,char***argv){
	GtkWidget* window;
	GtkWidget* label_name;
	GtkWidget* label_passwd;
	GtkWidget* entry_name;
	GtkWidget* entry_passwd;
	GtkWidget* button_signin;
	GtkWidget* button_signup;
	GtkWidget* other;
	gtk_init(argc,argv);//初始化图形界面显示环境
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	label_name=gtk_label_new("用户名：");
	gtk_widget_show(label_name);
	label_passwd=gtk_label_new("密码：");
	gtk_widget_show(label_passwd);
	gtk_window_set_title(GTK_WINDOW(window),g_locale_to_utf8("用户登入",-1,NULL,NULL,NULL));//设置窗口标题
	GtkWidget* table=gtk_table_new(36,36,TRUE);
	entry_name=gtk_entry_new_with_max_length(20);
	entry_passwd=gtk_entry_new_with_max_length(20);
	button_signin=gtk_button_new_with_label("登入");
	button_signup=gtk_button_new_with_label("注册");
	GtkWidget* label_title=gtk_label_new("聊天软件系统登入界面");
	GtkWidget* button_quit=gtk_button_new_with_label("退出");

	gtk_table_attach_defaults((GtkTable*)table,label_title,8,28,6,10);
	gtk_table_attach_defaults((GtkTable*)table,label_name,6,12,12,16);
	gtk_table_attach_defaults((GtkTable*)table,label_passwd,6,12,18,22);
	gtk_table_attach_defaults((GtkTable*)table,entry_name,12,24,12,18);
	gtk_table_attach_defaults((GtkTable*)table,entry_passwd,12,24,18,24);
	gtk_table_attach_defaults((GtkTable*)table,button_signup,14,18,30,36);
	gtk_table_attach_defaults((GtkTable*)table,button_signin,18,23,30,36);
	gtk_table_attach_defaults((GtkTable*)table,button_quit,26,29,30,36);
	gtk_widget_set_size_request(window,480,320);

	gtk_container_add(GTK_CONTAINER(window),table);

	gtk_entry_set_visibility((GtkEntry*)entry_passwd,FALSE);

	gtk_widget_show_all(window);

	gtk_main();
}


//test
/**/
int main(int argc,char**argv){
	//gtk_window_login(&argc,&argv);
	gtk_window_logup(&argc,&argv);
	return 0;
}