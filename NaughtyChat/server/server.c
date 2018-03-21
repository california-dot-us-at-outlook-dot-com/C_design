#include<stdio.h>
#include<pthread.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<errno.h>
#include"func.h"
#include"../head/dataser.h"


int main(){
	server_get_memory_init();
	//rdata=(serverdata*)malloc(sizeof(datas)*s64);
	//sdata=(serverdata*)malloc(sizeof(datas)*s64);
	int sock;
	sock=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in addr;
	int addr_len=sizeof(struct sockaddr_in);
	bzero(&addr,sizeof(struct sockaddr_in));
	addr.sin_family=AF_INET;
	addr.sin_port=htons(56789);
	addr.sin_addr.s_addr=htonl(INADDR_ANY);
	bind(sock,(struct sockaddr*)(&addr),sizeof(struct sockaddr));
	listen(sock,s64);
	
	for(int i=0;i<s64;i++){
		alldata->nsock[i]=-1;
	}
//	pthread_t *htid=(pthread_t*)malloc(sizeof(pthread_t));
//	pthread_create(htid,NULL,handle_data,rdata);
	while(1){
		for(int i=0;i<s64;i++){
			int a=i;
			if(alldata->nsock[i]<0){
				alldata->nsock[i]=accept(sock,(struct sockaddr*)(&addr),&addr_len);
				printf("accept到新client\n");
				alldata->rtid[i]=(pthread_t*)malloc(sizeof(pthread_t));
				int sof_a=pthread_create(alldata->rtid[i],NULL,send_data,&a);
				printf("发送线程:%d\n",sof_a);
				alldata->ntid[i]=(pthread_t*)malloc(sizeof(pthread_t));
				int sof_b=pthread_create(alldata->ntid[i],NULL,func,(void*)&a);
				printf("接收数据线程:%d\n",sof_b);
				printf("\t%d\n\n",alldata->nsock[i]);
			
			}
		}
	}
}
