#include<stdio.h>
#include<pthread.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<errno.h>
#include"../head/dataser.h"
#include<string.h>

int main(){
    datas recva;
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
    int nsock=accept(sock,(struct sockaddr*)(&addr),&addr_len);
    while(1){
        recv(nsock,&recva,sizeof(datas),0);
		if(strcmp(recva.confirm,"")!=0){
			printf("%s . %s\n\n",recva.confirm,recva.message);
            strcpy(recva.confirm,"");
		}
    }
}