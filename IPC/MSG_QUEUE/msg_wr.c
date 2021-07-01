#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 20

/*#include <sys/types.h>
#include <sys/ipc.h>

key_t ftok (const char *pathname, int proj_id);
*/

/* structure of msg buffer 
 * struct msgbuf
{
        long mtype;  // must be >0
        char mtext[SIZE];
};*/




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
	
	struct msgbuf msg1;
	
	msg1.mtype=10;   // used by receving process for msg selection
	
	strcpy(msg1.mtext,"Hello");
	
	msgsnd(qid,&msg1,sizeof(msg1.mtext),1);
	
	return 0;
}
