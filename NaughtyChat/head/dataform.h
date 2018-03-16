#ifndef dataform_h
#define dataform_h
#include<stdio.h>
#include<stdlib.h>
#include<gtk/gtk.h>

typedef char dataf;
typedef char chatf;
typedef struct{
	dataf confirm[16];
	int length;
	dataf sender[16];
	dataf recver[16];
	chatf message[32];
	dataf ender;
}datas;

typedef struct{
	int *argc;
	char ***argv;
	datas* recv;
	datas* send;
	dataf sign[16];
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
