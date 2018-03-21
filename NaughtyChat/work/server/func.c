#include"func.h"

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

