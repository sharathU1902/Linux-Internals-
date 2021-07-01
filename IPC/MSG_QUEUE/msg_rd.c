#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 20

struct msgbuf
{
	long mtype;  // must be >0
	char mtext[SIZE];
};
int main()
{
	key_t key = ftok("/home/sharath/AES/linux_internals/IPC/MSG_QUEUE",65);
	
	int qid = msgget(key,IPC_CREAT|0666);
	
	printf("qid=%d\n",qid);
	
	struct msgbuf msg;
	
	msgrcv(qid,&msg,SIZE,10,0);
	
	printf("Message received :%s\n",msg.mtext);
	
	return 0;
}
