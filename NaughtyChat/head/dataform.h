#ifndef dataform_h
#define dataform_h
#include<stdio.h>
#include<stdlib.h>

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
}inthread;



#endif
