//pipes:between 2 related processes (parent,child)
#include<stdio.h>
#include<unistd.h>
#include<string.h>
main()
{
	int ret;
	pid_t pid;
	char buf[20];
	int fd[2];
	ret=pipe(fd);
	pid=fork();   //to create duplicate child process
	if(pid>0)   //parent
	{
		close(fd[0]);
		ret=write(fd[1],"hey you",strlen("hey you"));
	}
	else
	{
		close(fd[1]);       //child
                ret=read(fd[0],buf,20); //blocking call
                buf[ret]='\0';
		printf("%s\n",buf);
	}
}

