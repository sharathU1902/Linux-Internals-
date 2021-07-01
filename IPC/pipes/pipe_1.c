#include<stdio.h>
#include<unistd.h>

int main()
{
	int arr[2];
	char msg[200];
	char rcv[200];
	
	printf("Enter message :");
	scanf("%s",msg);
	
	int ret=pipe(arr);  // creating a pipe 
	
	printf("write descriptor: %d\n ",arr[1]);
	printf("read descriptor: %d\n ",arr[0]);

	int ret1 = write(arr[1],msg,sizeof(msg));

	printf("return value of write :%d\n",ret1);

	if(ret1<0)
	{
		printf("Error in writing\n");
	}

	int ret2=read(arr[0],rcv,ret2);

	printf("return value for read:%d\n",ret2);

	if(ret2<0)
	{
		printf("Error in reading\n");
	}

	printf("Received data :%s\n",rcv);

	close(arr[0]);
	close(arr[1]);
	return 0;
}


