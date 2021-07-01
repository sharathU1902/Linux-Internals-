#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	pid_t pid;
	char *message;
	int n;

	printf("Fork program starting\n");
	pid=fork();
	switch(pid)
	{
		case -1:
			perror("Fork failed");
			exit(1);
			break;
		case 0:
			message="This is child";
			n=5;
			break;
		default:
			message="This is parent";
			n=3;
			break;
		}
	for(;n>0;n--)
	{
		puts(message);
		sleep(1);
	}
	return 0;
}
