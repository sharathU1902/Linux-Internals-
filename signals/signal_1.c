#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void int_signal(int sig)
{
	printf("I got a signal:%d\n",sig);
	(void) signal(SIGINT,SIG_DFL);
}

int main()
{
	(void) signal(SIGINT,int_signal);
	while(1)
	{
		printf("Hello world\n");
		sleep(1);
	}
	return 0;
}
