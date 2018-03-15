#ifndef func_h
#define func_h
#include<stdio.h>
#include<stdlib.h>
#include<gtk/gtk.h>
#include<pthread.h>
#include"dataform.h"
int gtk_window_hide(GtkWidget*,GtkWidget*);
int gtk_window_signup();
void* gtk_window_send(void*);
int to_signup();
void* gtk_window_signin(void*);
int movedata(int,datas*,datas*);
int getconnect(char*);
char*getip();
#endif
