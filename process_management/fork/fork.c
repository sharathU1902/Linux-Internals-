#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	fork();
	printf("Hello world!\n PID:%d\n",getpid());
	return 0;
}
