#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
void *function(void *arg)
{
	//sleep(2);
	printf("I am new Thread\n");

	int x=10;

	void *p=x;
	pthread_exit(p);
}

int main()
{
	void *data;
	pthread_t thread_id;
	printf("I am main thread\n");

	pthread_create(&thread_id,NULL,function,NULL);

	pthread_join(thread_id,&data);

	printf("Return data from new Thread is: %d\n",(int *)data);
}
