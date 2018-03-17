#include<gtk/gtk.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include"../../head/dataform.h"
#include"../../head/func.h"
#include<string.h>

void* commitmessage(GtkWidget*b,inthread*nai){
	
	strcpy(nai->send->recver,gtk_entry_get_text((GtkEntry*)(nai->g1)));	
	strcpy(nai->send->message,gtk_entry_get_text((GtkEntry*)(nai->g2)));
	strcpy(nai->send->confirm,nai->sign);
	gtk_entry_set_text((GtkEntry*)(nai->g2),"");
}

int mgtk_window_hide(GtkWidget*b,GtkWidget*window){
	gtk_widget_hide(window);
}
int mgtk_window_signup(GtkWidget*b,inthread*inT){
	inthread*nap=(inthread*)malloc(sizeof(inthread));
	strcpy(nap->sign,"signup");
	nap->recv=inT->recv;
	nap->send=inT->send;
	GtkWidget* window;
	GtkWidget* label_name;
	GtkWidget* label_passwd;
	GtkWidget* entry_name;
	GtkWidget* entry_passwd;
	GtkWidget* button_signin;
	GtkWidget* button_signup;
	GtkWidget* other;
	
	gtk_init(nap->argc,nap->argv);//初始化图形界面显示环境
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	label_name=gtk_label_new("用户名：");
	gtk_widget_show(label_name);
	label_passwd=gtk_label_new("密码：");
//	gtk_widget_show(label_passwd);
	gtk_window_set_title(GTK_WINDOW(window),g_locale_to_utf8("用户注册",-1,NULL,NULL,NULL));//设置窗口标题
	GtkWidget* table=gtk_table_new(36,36,TRUE);
	entry_name=gtk_entry_new_with_max_length(20);
	entry_passwd=gtk_entry_new_with_max_length(20);
	//button_signin=gtk_button_new_with_label("登入");
	button_signup=gtk_button_new_with_label("注册");
	GtkWidget* label_title=gtk_label_new("聊天软件系统注册界面");
	GtkWidget* button_quit=gtk_button_new_with_label("取消");
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
	
	gtk_signal_connect((GtkObject*)button_quit,"clicked",G_CALLBACK(mgtk_window_hide),window);//点击“取消”按钮退出
	
	nap->g1=entry_name;
	nap->g2=entry_passwd;
	gtk_signal_connect((GtkObject*)button_signup,"clicked",G_CALLBACK(commitmessage),nap);
	//gtk_main();
}

void main_quit(GtkWidget*b,inthread*inT){
	strcpy(inT->send->confirm,"Quit\n");
	//printf("\n\n%s",inT->send->confirm);
}

void* mgtk_window_signin(void*ino){
//	inthread*inT;
//	inT=(inthread*)ino;

/*	inT->argc=((inthread*)ino)->argc;
	inT->argv=((inthread*)ino)->argv;
	inT->send=((inthread*)ino)->send;
	strcpy(inT->sign,"signin");
*/	GtkWidget* window;
	GtkWidget* label_title;
	GtkWidget* label_name;
	GtkWidget* label_passwd;
	GtkWidget* entry_name;
	GtkWidget* entry_passwd;
	GtkWidget* button_signin;
	GtkWidget* button_signup;
	GtkWidget* table;
	GtkWidget* button_quit;
	inthread* inthr;

	gtk_init(((inthread*)ino)->argc,((inthread*)ino)->argv);//初始化图形界面显示环境
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	label_name=gtk_label_new("用户名：");
//	gtk_widget_show(label_name);
	label_passwd=gtk_label_new("密码：");
//	gtk_widget_show(label_passwd);
	gtk_window_set_title(GTK_WINDOW(window),"用户登入");//设置窗口标题
	table=gtk_table_new(36,36,TRUE);
	entry_name=gtk_entry_new_with_max_length(16);
	entry_passwd=gtk_entry_new_with_max_length(16);
	button_signin=gtk_button_new_with_label("登入");
	button_signup=gtk_button_new_with_label("注册");
	label_title=gtk_label_new("聊天软件系统登入界面");
	button_quit=gtk_button_new_with_label("退出");

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
	
/*	gtk_signal_connect((GtkObject*)button_quit,"clicked",G_CALLBACK(main_quit),inT);

	gtk_signal_connect((GtkObject*)button_signup,"clicked",G_CALLBACK(mgtk_window_signup),inT);
	g_signal_connect_swapped(G_OBJECT(window),"destroy",G_CALLBACK(main_quit),inT);
*/
	//	inthr=inT;
//	inthr->g1=entry_name;
//	inthr->g2=entry_passwd;
//	gtk_signal_connect((GtkObject*)button_signin,"clicked",G_CALLBACK(commitmessage),inthr);
	gtk_main();
}

int mgtk_window_yorn(){

}
/*void* commitmessage(GtkWidget*b,inthread*nai){
	
	strcpy(nai->send->recver,gtk_entry_get_text((GtkEntry*)(nai->g1)));	
	strcpy(nai->send->message,gtk_entry_get_text((GtkEntry*)(nai->g2)));
	strcpy(nai->send->confirm,nai->sign);
	gtk_entry_set_text((GtkEntry*)(nai->g2),"");
}*/

void* mgtk_window_send(void*ino){
	inthread*inT=(inthread*)malloc(sizeof(inthread));
	inT=(inthread*)ino;
	inT->argc=((inthread*)ino)->argc;
	inT->argv=((inthread*)ino)->argv;
	strcpy(inT->sign,"message");
	GtkWidget* window=(GtkWidget*)malloc(sizeof(GtkWidget));
	GtkWidget* label_name=(GtkWidget*)malloc(sizeof(GtkWidget));
	GtkWidget* label_getm=(GtkWidget*)malloc(sizeof(GtkWidget));
	GtkWidget* entry_name=(GtkWidget*)malloc(sizeof(GtkWidget));
	GtkWidget* entry_input=(GtkWidget*)malloc(sizeof(GtkWidget));
	GtkWidget* button_commit=(GtkWidget*)malloc(sizeof(GtkWidget));
	GtkWidget* button_quit=(GtkWidget*)malloc(sizeof(GtkWidget));
	GtkWidget* button_list=(GtkWidget*)malloc(sizeof(GtkWidget));
	//GtkWidget* other;
	GtkWidget* table=(GtkWidget*)malloc(sizeof(GtkWidget));;
	GtkWidget* button_message;
	gtk_init(inT->argc,inT->argv);
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
	inthread *nai=(inthread*)malloc(sizeof(gtk_p));
	nai->g1=entry_name;
	nai->g2=entry_input;
	nai->recv=inT->recv;
	nai->send=inT->send;
	gtk_signal_connect((GtkObject*)button_commit,"clicked",G_CALLBACK(commitmessage),nai);
	gtk_main();

}
//test
/*
int main(int argc,char**argv){
	inthread *ino=(inthread*)malloc(sizeof(inthread));;
	ino->argc=&argc;
	ino->argv=&argv;
	mgtk_window_send((void*)ino);
	
	return 0;
}*/
