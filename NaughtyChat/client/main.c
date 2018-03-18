#include"../head/func.h"
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<gtk/gtk.h>

int main(int argc,char**argv){
	if(!g_thread_supported()){
		g_thread_init(NULL);
	}
	gdk_threads_init();
	gtk_init(&argc,&argv);
	datas*datarecv=(datas*)malloc(sizeof(datas*));
	datas*datasend=(datas*)malloc(sizeof(datas*));
	inthread inT;
	inT.argc=&argc;
	inT.argv=&argv;
	inT.recv=datarecv;
	inT.send=datasend;
	//datarecv->confirm="";
	//datasend->confirm="";
	char*ip=getip();
	int sock=getconnect(ip);
	pthread_t *thread_1=(pthread_t*)malloc(sizeof(pthread_t));
	pthread_t *thread_2=(pthread_t*)malloc(sizeof(pthread_t));
	pthread_create(thread_1,NULL,mgtk_window_signin,(void*)&inT);
//	pthread_create(thread_2,NULL,mgtk_window_send,(void*)&inT);


	movedata(sock,datasend,datarecv);
}
