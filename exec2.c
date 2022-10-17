#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	printf("new one\n");
	printf("pid=%d\n",getpid());
	return 0;
}
