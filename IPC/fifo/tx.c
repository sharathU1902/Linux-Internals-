#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#include<sys/stat.h>  // for mkfifo
#include<sys/fcntl.h> // for open()

void main()
{
	int ret;
	int fd;
	ret=mkfifo("fifo",0666);
	if(ret<0)
		perror("mkfifo error");
	fd=open("fifo",O_WRONLY);
	write(fd,"hello...",10);
	close(fd);
	unlink("fifo");
}
