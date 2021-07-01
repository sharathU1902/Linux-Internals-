#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>


void function(int signal)
{
	printf("child process got terminated ");
	printf("with a Signal=%d\n",signal);
}





int main()
{
	pid_t pid;
	printf("Fork program was starting\n");
	pid=fork();
	if(pid==0){
		printf("I am child proces\n");
		printf("child is killed himself in 5 sec\n");
		int i;
		for(i=5;i>0;i--)
		{
			printf("%d\n",i);
			sleep(1);
		}
	}
	else{

		int status;
		signal(SIGCHLD,function);
		wait(&status);
		printf("Parent got terminated\n");
	}

	return 0;
}
