#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
main()
{
	int sfd,cfd,ret,buff;
	char wbuff[10],rbuff[10];
//        buff[4]="bye";
	mkfifo("srvfifo",0660);
	while(1)
	{
		sfd=open("srvfifo",O_RDONLY);
		ret=read(sfd,rbuff,9);
		rbuff[ret]='\0';
		close(sfd);
		if(strcmp(buff,rbuff)==0)
			exit(0);
		printf("%s\n",rbuff);
		scanf("%s",wbuff);
		cfd=open("clififo",O_WRONLY);
		ret=write(cfd,wbuff,strlen(wbuff));
		close(cfd);
	}
}
