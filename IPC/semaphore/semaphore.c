#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/sem.h>


static void del_semvalue(void);
static int semapore_lock(void);
static int semapore_unlock(void);
static int sem_id;

union semun
{
	int val;
	struct semid_ds *buf;
	unsigned short * array;
	struct seminfo *__buf;
};


void del_semvalue(void)
{
	union semun sem_union;
	if(semctl(sem_id,1,IPC_RMID,sem_union)==-1)
		fprintf(stderr,"Failed to delete semaphore..\n");
}

int semapore_lock(void)
{
	struct sembuf sem_b;
	sem_b.sem_num=0;
	sem_b.sem_op=-1;
	sem_b.sem_flg=SEM_UNDO;

	if(semop(sem_id,&sem_b,1)==-1)
	{
		fprintf(stderr,"semaphore_lock failed!..\n");
		return 0;
	}
	return -1;
}

int semapore_unlock(void)
{
	struct sembuf sem_b;
	sem_b.sem_num=0;
	sem_b.sem_op=1;
	sem_b.sem_flg=SEM_UNDO;

	if(semop(sem_id,&sem_b,1)==-1)
	{
		fprintf(stderr,"Semaphore_unlock failed!..\n");
		return 0;
	}
	return 1;
}

int main()
{
	int i;
	pid_t pid;

	sem_id=semget((key_t)12,1,0666|IPC_CREAT);
	printf("sem_id is :%d\n",sem_id);

	pid=fork();
	printf("Child pid:%d\n",pid);
	if(pid==0)
	{
		printf("I am child..\n");
		for(i=0;i<5;i++)
		{
			printf("child process is running..\n");
			sleep(1);
		}
		semapore_unlock();  // releasing the semaphore.. giving access to next process
		exit(0);
	}
	else
	{
		semapore_lock();  // aquiring the semaphore... & make parent in waiting list 
		printf("Parent id:%d\n",getpid());
		printf("I am parent..\n");

	}

	del_semvalue();
}
