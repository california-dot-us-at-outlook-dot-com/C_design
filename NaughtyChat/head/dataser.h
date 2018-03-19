#ifndef dataform_h
#define dataform_h
#include<stdio.h>
#include<stdlib.h>


#define s64 64
typedef char dataf;
typedef char chatf;

typedef struct{
	dataf confirm[16];
//	int length;
	dataf sender[16];
	dataf recver[16];
	chatf message[32];
//	dataf ender;
}datas;


//////////////////////////////////////////////////

typedef struct{
	int nsock[64];
	dataf client[64][16];
	datas* send[64];
	datas* recv[64];
	pthread_t* ntid[64];
	pthread_t* rtid[64];
}serverdata;

typedef struct{
	int sock;
	char user[16];
}user;
typedef struct{
	dataf user[16];
	dataf passwd[32];
//	dataf exist[16];
	int exist;
}confirm;

typedef struct{
	int wp;
	int rp;
	datas* message[s64];
}offlinemessage;

//////////////////////////////////////////

offlinemessage *offline[s64];
confirm* condata[64];
serverdata* alldata;
int nsock[64];
datas *rdata;
datas *sdata[64];



#endif
