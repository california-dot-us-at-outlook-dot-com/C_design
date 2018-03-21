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
//typedef struct _client client;

//定义用户数据区
client user[MAX_USERS];

//定义服务线程
void do_service(gpointer id){
    gint j;
    char tobuf[1024];

    while(read(user[GPOINTER_TO_INT(id)].sd,user[GPOINTER_TO_INT(id)].buf,1024)!=-1){
        sprintf(tobuf,"%s: %s\n",user[GPOINTER_TO_INT(id)].name,user[GPOINTER_TO_INT(id)].buf);
        for(j=0;j<MAX_USERS;j++){
            if(user[j].in_use){
                write(user[j].sd,tobuf,1024);
                g_print("%s",tobuf);
            }
        }
    }
    user[GPOINTER_TO_INT(id)].in_use=FALSE;
    close(user[GPOINTER_TO_INT(id)].sd);
    //exit(0);
}

int main(int argc,char**argv){
    gint sd,newsd;
    struct sockaddr_in*sin;
    gint slen;
    gint count=0;
    gint flags;
    gchar buf[1024];
    gchar tobuf[1024];
    gint length,i,j;

    if(!g_thread_supported()){
        g_thread_init(NULL);
    }
    else{
        g_print("thread not supported\n");
    }

    sd=socket(AF_INET,SOCK_STREAM,0);
    if(sd==-1){
        g_print("create socket error!\n");
        return -1;
    }
    sin=g_new(struct sockaddr_in,1);
    sin->sin_family=AF_INET;
    sin->sin_port=OURPORT;
    slen=sizeof(struct sockaddr_in);

    if(bind(sd,sin,slen)<0){
        g_print("bind error!\n");
        return -1;
    }

    if(listen(sd,8)<0){
        g_print("listen error!\n");
        return -1;
    }

    for(i=0;i<MAX_USERS;i++){
        user[i].in_use=FALSE;
    }
    flags=fcntl(sd,F_GETFL);
    fcntl(sd,F_SETFL,flags&~O_NDELAY);

    for(;;){
        newsd=accept(sd,sin,&slen);
        if(newsd==-1){
            g_print("accept error!\n");
            break;
        }
        else{
            if(count>=MAX_USERS){
                sprintf(buf,"用户已满\n");
                write(newsd,buf,1024);
                close(newsd);
            }
            else{
                flags=fcntl(user[i].sd,F_GETFL);
                fcntl(user[i].sd,F_SETFL,O_NONBLOCK);
                user[count].sd=newsd;
                user[count].in_use=TRUE;
                read(newsd,user[count].name,64);

                //创建用户服务的线程
                g_thread_create((GThreadFunc)do_service,(gpointer)count,TRUE,NULL);
                count++;
            }
        }
    }
    close(sd);
    g_free(sin);
}