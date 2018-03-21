#include<glib.h>
#include<stdio.h>
#include<fcntl.h>
#include<signal.h>
#include<sys/socket.h>
#include<sys/time.h>
#include<unistd.h>
#include<netdb.h>
#include<netinet/in.h>

#define OURPORT 8088
#define MAX_USERS 8

typedef struct client{
    gint sd;
    gboolean in_use;
    gchar name[64];
    gchar buf[1024];
}client;

//定义用户数据区
client user[MAX_USERS];

//定义服务线程
void do_service(gpointer);
