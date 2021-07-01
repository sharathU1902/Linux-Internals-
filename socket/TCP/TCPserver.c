#include<stdio.h>
#include<netdb.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

// function designed for chat between client and server 

void chatfunc(int sockfd)
{
	char buff[MAX];
	int n;

	for(;;){

		bzero(buff,MAX); 
	/*The bzero() function  erases  the  data  in the n bytes of the memory
       starting at the location pointed to by s, by writing zeros (bytes  con‐
       taining '\0') to that area.*/

		//read the message fom client and copy it in buffer
		read(sockfd,buff,sizeof(buff));

		//print buffer which contains the client contents
		printf("From client:%s\t To client: ",buff);
		bzero(buff,MAX);
		n=0;

		//copy server message in the buffer 
		while((buff[n++]=getchar())!='\n');

		//send that buffer to client
		write(sockfd,buff,sizeof(buff));

		//if msg contains "Exit" then server exit and chat ended
		if(strncmp("exit",buff,4)==0)
		{
			printf("Server Exit...\n");
			break;
		}
	}
}


//main funtion


int main()
{
	int sockfd,connfd,len;
	struct sockaddr_in servaddr, cli;

	// socket create and verification
	
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd==-1)
	{
		printf("Socket creation failed..\n");
		exit(0);
	}
	else
		printf("Socket successfully created..\n");
	bzero(&servaddr,sizeof(servaddr));

	//assign IP PORT
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port=htons(PORT);

	//Binding
	if((bind(sockfd,(SA*)&servaddr,sizeof(servaddr)))!=0)
	{
		printf("Socket bind failed..\n");
		exit(0);
	}
	else 
		printf("Socket successfully binded..\n");

	//now server is ready to listen
	if((listen(sockfd,5))!=0)
	{
		printf("Listen failed..\n");
		exit(0);
	}
	else 
		printf("Server listening..\n");

	connfd=accept(sockfd,(SA*)&cli,&len);
	if(connfd<0)
	{
		printf("server accept failed..\n");
		exit(0);
	}
	else
		printf("server accept the client...\n");

	chatfunc(connfd);  // function for chatting between cilent and server 

	close(sockfd); // after chatting close the socket
}


