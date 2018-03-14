#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#define PORT 5678
#define remote "101.132.123.155"
int main(){
	int sock;
	int nsock;
	sock=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in addr;
	int addr_len=sizeof(struct sockaddr_in);
	bzero(&addr,sizeof(struct sockaddr_in));
	addr.sin_family=AF_INET;	//设置addr的成员信息
	addr.sin_port=htons(PORT);	//设置addr的PORT
	addr.sin_addr.s_addr=htonl(INADDR_ANY);	//IP设为本机
	bind(sock,(struct sockaddr*)(&addr),sizeof(struct sockaddr));
	//#<sys/socket.h> int listen(int sock,int backlog);//backlog为最大请求数
	//<sys/socket.h><sys/types.h> int accept(int sock,struct sockaddr *addr ,socketlen_t *addrlen);
	listen(sock,5);
	nsock=accept(sock,(struct sockaddr*)(&addr),&addr_len);
	//if success return >0
	
	
	//client没有bind和listen以及accept
	//addr.sin_addr.s_addr=inet_addr(remote);
	//connect(int sock,(struct sockaddr*)(&addr),sizeof(struct sockaddr));
	


	//int send(int sock,const void*msg,int len,unsigned int flags);
	//int recv(int sock,void*buf,int len,unsigned int flags);
	char buf[256];
	char buff[256]="HTTP1.1 200 OK\r\n\r\n";
	recv(nsock,buf,sizeof(buf),0);
	printf("%s\n",buf);
	send(nsock,buff,sizeof(buff),0);

}
