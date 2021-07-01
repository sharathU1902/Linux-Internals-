#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>  // for mkfifo

#include<sys/fcntl.h> // for opem()

void main()
{
	int ret=open("fifo",O_RDONLY);
	if(ret<0)
		perror("error in open..");
	char data[100];
	read(ret,data,100);

	printf("received = %s\n",data);

	close(ret);
	unlink("fifo");
}
