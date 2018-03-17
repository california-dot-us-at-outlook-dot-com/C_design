#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include"../head/dataform.h"
#include"func.h"
#include<errno.h>

int server_get_memory_init(){
	for(int i=0;i<64;i++){
		offline[i]=(offlinemessage*)malloc(sizeof(offlinemessage));
	}
	for(int i=0;i<64;i++){
		condata[i]=(confirm*)malloc(sizeof(confirm));
	}
	
	alldata=(serverdata*)malloc(sizeof(serverdata));
	
	for(int i=0;i<64;i++){
		alldata->send[i]=(datas*)malloc(sizeof(datas)*64);
		strcpy(alldata->send[i]->confirm,"");
	}
	for(int i=0;i<64;i++){
		alldata->recv[i]=(datas*)malloc(sizeof(datas)*64);
	}


}

void* func(void*n){
	int i=*((int*)n);
	

	while(1){
		int back=recv(alldata->nsock[i],alldata->recv[i],sizeof(alldata->recv[i]),0);
		//如果是消息，则转发，离线储存
		int getclient=0;
		if(strcmp(alldata->recv[i]->confirm,"message")==0){
			//先在在线用户中查找
			for(int j=0;j<s64;j++){
				if(strcmp(alldata->client[j],alldata->recv[i]->recver)==0){
					memcpy(alldata->send[j],alldata->recv[i],sizeof(datas)*64);
					strcpy(alldata->recv[i]->confirm,"");
					getclient=1;
					break;
				}
			}
			if(getclient==0){
				int getuser=0;
				//再到所有用户中查找，并存到离线消息
				for(int j=0;j<s64;j++){
					if(strcmp(alldata->recv[i]->recver,condata[j]->user)==0){
						
							
						memcpy(offline[j]->message[(offline[j]->wp)%64],alldata->recv[i],sizeof(datas)*64);
						(offline[j]->wp)++;
						getuser=1;
						break;

					}
				}
				if(getuser==0){
					strcpy(alldata->send[i]->confirm,"usernotfound");
				}
			}
		}
		//if message，zhuanfa
		//如果是登录，则验证密码并回复结果
		if(strcmp(alldata->recv[i]->confirm,"signin")==0){
			for(int j=0;j<s64;j++){
				if(strcmp(alldata->recv[i]->sender,condata[j]->user)==0){
					if(strcmp(alldata->recv[i]->message,condata[j]->passwd)==0){
						strcpy(alldata->send[i]->confirm,"signinS");//登入成功
					}
					else{
						strcpy(alldata->send[i]->confirm,"wrongpasswd");//密码错误
					}
				}
				else{
					strcpy(alldata->send[i]->confirm,"nosuchuser");//没有该用户，无法登入
				}
			}
		}
		//如果是注册，则保存用户信息
		if(strcmp(alldata->recv[i]->confirm,"signup")==0){
			for(int signup=0;signup<64;signup++){
				if(condata[signup]->exist!=1){
					strcpy(condata[signup]->user,alldata->recv[i]->sender);
					strcpy(condata[signup]->passwd,alldata->recv[i]->message);
					condata[signup]->exist=1;
				}
			}
		}


		//发送模块：如果send->confirm区域内有不为“”的内容，则发送
		if(strcmp(alldata->send[i]->confirm,"")!=0){
			send(alldata->nsock[i],alldata->send[i],sizeof(alldata->send[i]),0);
			strcpy(alldata->send[i]->confirm,"");
		}
	
		//如果socket连接断开，则释放资源
	
		if(back<0&&errno==EINTR){
			alldata->nsock[i]=-1;
		}
	
	
	
	
	
	
	}


}
