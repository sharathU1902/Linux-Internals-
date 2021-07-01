#include<stdio.h>
#include<stdlib.h>

int main()
{
	printf("Running ps with system\n");
	system("ps al");
	printf("Done");
	exit(0);
	return 0;
}
