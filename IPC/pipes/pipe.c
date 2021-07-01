#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>

int main()
{
	int a[2];
	char buff[100];
	if(pipe(a)==-1)
	{
		perror("pipe"); //error in pipe
		exit(1);
	}
	write(a[1],"Hello..",10);
	printf("Data is written\n");
	read(a[0],buff,10);
	printf("Read data is: %s\n",buff);
	return 0;
}
