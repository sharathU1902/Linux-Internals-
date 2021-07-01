#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main()
{
	int shmid;
	char *str;
	shmid = shmget((key_t)6,1024,IPC_CREAT|0666);

	str=(char*)shmat(shmid,(void*)0,0);

	printf("Enter data:\n");

	fgets(str,sizeof(str),stdin);

	printf("Data successfully written into the memory\n");
	return 0;
}
