#include"func.h"


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