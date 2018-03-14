#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<ctype.h>
#include<pthread.h>
#include<unistd.h>

char* getip(){
	char i[6];
	return fgets(i,1,stdin);
}

int getconnect(char*ip){
	struct sockaddr_in addr;
	int sock=socket(AF_INET,SOCK_STREAM,0);
	int addr_len=sizeof(struct sockaddr_in);
	bzero(&addr,sizeof(struct sockaddr_in));
	addr.sin_family=AF_INET;
	addr.sin_port=htons(80);
	addr.sin_addr.s_addr=inet_addr(ip);
	
	connect(sock,(struct sockaddr*)(&addr),sizeof(struct sockaddr));
	
return sock;
}

int movedata(int sock,datas*datasend,datas*datarecv){
	datas* tmpdata=(datas*)malloc(sizeof(datas));
	while(1){
		if(strcmp(datasend->confirm,"")!=0){
			send(sock,datasend,sizeof(datas),0);
			datas->confirm="";
		}	
		recv(sock,tmpdata,sizeof(datas),0);
		if(strcmp(tmpdata->confirm,"")!=0){
			memcpy(datarecv,tmpdata,sizeof(datas);
			}
		}
	}
}
//test
/*
int main(){
	char buff[256]="";
	int sock=getconnect("192.168.2.1\n");
	printf("%d\n\n",sock);
	char *buf="HTTP1.1 GET / \r\n\r\n";
	send(sock,buf,sizeof(buf),0);	
	recv(sock,buff,sizeof(buff),0);
	printf("%s\n",buff);
}*/
