#ifndef func_h
#define func_h
#include<stdio.h>
#include<stdlib.h>
#include<gtk/gtk.h>
#include<pthread.h>
#include"dataform.h"
int mgtk_window_hide(GtkWidget*,GtkWidget*);
int mgtk_window_signup();
void* mgtk_window_send(void*);
int to_signup();
void* mgtk_window_signin(void*);
int movedata(int,datas*,datas*);
int getconnect(char*);
char*getip();
#endif
