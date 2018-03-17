#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<pthread.h>
#include<sys/wait.h>
#include<string.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include"../../head/dataser.h"
datas a;
int main(){
	struct sockaddr_in addr;
	int sock=socket(AF_INET,SOCK_STREAM,0);
	int addr_len=sizeof(struct sockaddr_in);
	bzero(&addr,sizeof(struct sockaddr_in));
	addr.sin_family=AF_INET;
	addr.sin_port=htons(56789);
	addr.sin_addr.s_addr=inet_addr("127.0.0.1");

	connect(sock,(struct sockaddr*)(&addr),sizeof(struct sockaddr));

//	strcpy(a.confirm,"are_you");
//	strcpy(a.sender,"qwwww");
//	strcpy(a.message,"qaeee");
//	send(sock,&a,sizeof(a),0);
	for(int i=0;i<5;i++){
	strcpy(a.confirm,"signup");
	strcpy(a.sender,"uee");
	strcpy(a.message,"eee");
	send(sock,&a,sizeof(a),0);
//	sleep(1);
	recv(sock,&a,sizeof(a),0);
//	strcpy(a.confirm,"signin");
//	strcpy(a.sender,"a");
//	strcpy(a.message,"a");
//	send(sock,&a,sizeof(a),0);
	//sleep(2);
//	recv(sock,&a,sizeof(a),0);
	
	printf("\t%s\n",a.confirm);
	printf("\t%s\n",a.confirm);
	printf("\t%s\n",a.confirm);
	}
}
