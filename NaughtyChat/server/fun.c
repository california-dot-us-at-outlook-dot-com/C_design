#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include"../head.h"
int func(int i){
	

	while(1){
		recv(alldata->nsock[i],alldata->recv[i],sizeof(alldata->recv[i]),0);
		//如果是消息，则转发，离线储存
		int getclient=0;
		if(strcmp(alldata->recv[i]->confirm,"message")){
			//先在在线用户中查找
			for(int j=0;j<s64;j++){
				if(strcmp(alldata->client[j],alldata->recv[i]->recver)==0){
					memcpy(alldata->send[j],alldata->recv[i]);
					strcpy(alldata->recv[i]->confirm,"");
					getuser=1;
					break;
				}
			}
			if(getglient==0){
				int getuser=0;
				//再到所有用户中查找，并存到离线消息
				for(int j=0;j<s64;j++){
					if(strcmp(alldata->recv[i]->recver,condata->user[j])==0){
						
							
						memcpy(offline[j]->message[(offline[j]->wp)%64],alldata->recv[i]);
						(offline[j]->wp)++;
						getuser=1;
						break;

					}
				}
				if(getuser==0){
					strcpy(alldata->send[j]->confirm,"usernotfound");
				}
			}
		}
		//if message，zhuanfa
		//如果是登录，则验证密码并回复结果
		if(strcmp(alldata->recv[i]->confirm,"signin")==0){
			for(int j=0;j<s64;j++){
				if(strcmp(alldata->recv[i]->sender,condata[j]->user)==0){
					if(strcmp(alldata->recv[i]->message,condata[j]->passwd)==0){
						strcpy(alldata->send[i]->confirm,"signinS");
					}
					else{
						strcpy(alldata->send[i]->confirm,"wrongpasswd");
					}
				}
				else{
					strcpy(alldata->send[i]->sonfirm,"nosuchuser");
				}
			}
	}
		if(strcmp(alldata->recv[i]->confirm,"signup")==0){
			for(int signup=0;signup<64;signup++){
				if(condata[j]
		}
}
