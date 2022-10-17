#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
main()
{
	int cfd,sfd,ret;
	char wbuff[10],rbuff[10];
	mkfifo("clififo",0060);
	while(1)
	{
		sfd=open("srvfifo",O_WRONLY);
		scanf("%s", wbuff);
		ret=write(sfd,wbuff,strlen(wbuff));
		cfd=open("clififo",O_RDONLY);
		ret=read(cfd,rbuff,9);
		rbuff[ret]='\0';
		printf("%s\n",rbuff);
		close(sfd);
		close(cfd);
	}
}
 
