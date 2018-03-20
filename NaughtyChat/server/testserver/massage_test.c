#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<gtk/gtk.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include"../../head/dataform.h"
datas sedata;
int getconnect(char*ip){
	struct sockaddr_in addr;
	int sock=socket(AF_INET,SOCK_STREAM,0);
	int addr_len=sizeof(struct sockaddr_in);
	bzero(&addr,sizeof(struct sockaddr_in));
	addr.sin_family=AF_INET;
	addr.sin_port=htons(56789);
	addr.sin_addr.s_addr=inet_addr(ip);
	
	connect(sock,(struct sockaddr*)(&addr),sizeof(struct sockaddr));
	
    return sock;
}
int main(){
int sock=0;
while(1){
        printf("正在连接服务器\n");
        if((sock=getconnect("127.0.0.1"))>0){
            break;
        }
    }
    printf("成功连接到服务器\n");
    for(int i=0;i<144;i++){
        
        strcpy(sedata.confirm,"message");
        strcpy(sedata.message,"nihao");
        send(sock,&sedata,sizeof(datas),0);
    }
    sleep(1);
}