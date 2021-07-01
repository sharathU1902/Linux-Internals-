#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
 
int main()
{
    if (fork()== 0)
        printf("Hello from child\n");
    else
    {
        printf("Hello from parent\n");
        wait(NULL);
        printf("Child has terminated\n");
    }
 
    printf("Bye\n");
    return 0;
}
