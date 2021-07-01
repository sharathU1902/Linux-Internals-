#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

int main()
{
	pid_t cpid;
	cpid=fork();
	if(cpid!=0)
	{
		sleep(5);
		printf("pid of parent = %d\n",getpid());
		printf("pid of child = %d\n",cpid);
	
		kill(getpid(),SIGSEGV);
	
		printf("Parent killed child\n");
	}
	else
	{
		printf("I am child\n");
		for(int i=0;i<=10;i++)
		{
			printf("I am in loop\n");
			sleep(1);
		}
	}
	return 0;
	
}
