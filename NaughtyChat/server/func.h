#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<pthread.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<errno.h>
#include"../head/dataform.h"

#ifndef func_h
#define func_h

int server_get_memory_init();

void* func(void*);

#endif


