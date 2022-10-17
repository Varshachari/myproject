#include<stdio.h>
#include<unistd.h>   //for exec family of calls
#include<stdlib.h>
int main(int argc,char *argv[])
{
	printf("pid=%d\n",getpid());
	char *args[]={"hii","varsha",NULL};
	execv("./hii",args);
	printf("how r u doing");
	return 0;
}

