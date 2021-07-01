#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

void *ThreadFunction(void *argp)
{
	for(int i=0;i<5;i++){
		printf("Hello Threading\n");
	sleep(2);
	}
	return NULL;
}

int main()
{

	pthread_t thread_id;	
	printf("We are in threading\n");

	pthread_create(&thread_id,NULL,ThreadFunction,NULL);  // create a thread

	pthread_join(thread_id,NULL);
	printf("Exit from threading\n");
	exit(0);
}
