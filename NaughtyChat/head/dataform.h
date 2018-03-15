#ifndef dataform_h
#define dataform_h
#include<stdio.h>
#include<stdlib.h>
#include<gtk/gtk.h>

typedef char* dataf;
typedef char* chatf;
typedef struct{
	dataf confirm;
	int length;
	dataf sender;
	dataf recver;
	chatf message;
	dataf ender;
}datas;

typedef struct{
	int *argc;
	char ***argv;
	datas* recv;
	datas* send;
	GtkWidget* g1;
	GtkWidget*g2;
}inthread;

typedef struct{
	GtkWidget* g1;
	GtkWidget* g2;
	GtkWidget* g3;
	GtkWidget* g4;
}gtk_p;



#endif
