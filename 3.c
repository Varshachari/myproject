#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
int main(int argc, char *argv[])
{
	int ret,ret1,ret2;
	if(argc!=3)
	{
		printf("cant kill\n");
		return -1;
	}
	ret1=atoi(argv[1]);    //ascii to int 
	ret2=atoi(argv[2]);
	ret=kill(ret2,ret1);
        if(ret<0)
	{
		printf("failed to kill\n");
		return -1;
	}
	printf("killed successfully\n");
}
