#include<stdio.h>
#include<pthread.h>
#include <sys/time.h>

pthread_t thread1;

pthread_mutex_t m;
int timer,timer_usec;
struct timeval tv;

void *test(){
	pthread_mutex_lock(&m);
		gettimeofday(&tv,0);
		int timer2=tv.tv_sec;
		int timer2_usec=tv.tv_usec;
		fprintf(stdout,"Curren time after switch:%d %d\n",timer2,timer2_usec);
		float timediff=(timer2-timer)*1000+((timer2_usec-timer_usec));
		fprintf(stdout,"time for switch:%f usec\n",timediff);
		fprintf(stdout,"In thread\n");
	pthread_mutex_unlock(&m);
}

int main(int argc,char *argv[]){
	pthread_mutex_init(&m,NULL);
	pthread_mutex_lock(&m);
	pthread_create(&thread1,NULL,test,NULL);
	gettimeofday(&tv,0);	
	timer=tv.tv_sec;
	timer_usec=tv.tv_usec;
	fprintf(stdout,"Current time:%d %d\n",timer,timer_usec);
	pthread_mutex_unlock(&m);
	pthread_join(thread1,NULL);
	fprintf(stdout,"In main thread\n");			
}



