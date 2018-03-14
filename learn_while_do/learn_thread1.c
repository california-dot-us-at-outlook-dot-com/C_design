#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
/*
pthread_t pthread_self(void);	//用于获得线程自身的线程标识符
int pthread_eaual(pthread_t tid1, pthread_t tid2);	//比较两个线程标识符，if equal return 0,else return !0

typedef struct{
	int detachstate;
	int schedpolicy;
	structsched_param schedparam;
	int inheritsched;
	int scope;
	size_tguardsize;
	int stackaddr_set;
	void *stackaddr;
	size_tstacksize;
}pthread_attr_t;
//线程的属性通过如上的struct定义。

//用gcc编译多线程时，必须与pthread函数链接。命令为：gcc -lphtread

int pthread_create(pthread_t *thread,pthread_attr_t *attr,void *(*start_routine)(void*),void*arg);//创建新的线程，success return 0

*/
int main(){
	pthread_t *ntid=(pthread_t*)malloc(sizeof(pthread_t));
	pthread_t *ntie=(pthread_t*)malloc(sizeof(pthread_t));
	int i=5;
	int j=7;
	void *func(int*arg){
		//int*arg=(int*)malloc(sizeof(int));
		//*arg=9;
		for(int i=0;i<10000;i++){
			printf("%d+in_thread\n",*arg);
		//	sleep(*arg);
		}
		
	}
	int a=pthread_create(ntid,NULL,func,&i);
	int b=pthread_create(ntie,NULL,func,&j);
	printf("%d,%d\n",a,b);
//	sleep(1000);
	return 0;
}

