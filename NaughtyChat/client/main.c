#include"../head/func.h"
#include"../head/dataform.h"
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc,char**argv){
	datas*datarecv=(datas*)malloc(sizeof(datas*));
	datas*datasend=(datas*)malloc(sizeof(datas*));
	int sock;
	inthread *inT=(inthread*)malloc(sizeof(inthread));
	inT->argc=&argc;
	inT->argv=&argv;
	inT->recv=datarecv;
	inT->send=datasend;
	strcpy(datarecv->confirm,"");
	strcpy(datasend->confirm,"");
	char*ip=(char*)malloc(20);
	strcpy(ip,"127.0.0.1");
	sock=getconnect(ip);
	pthread_t *thread_1=(pthread_t*)malloc(sizeof(pthread_t));
	pthread_t *thread_2=(pthread_t*)malloc(sizeof(pthread_t));
	pthread_create(thread_1,NULL,mgtk_window_signin,(void*)&inT);
//	pthread_create(thread_2,NULL,mgtk_window_send,(void*)&inT);

	
	movedata(sock,datasend,datarecv);
	sleep(1000);
}
