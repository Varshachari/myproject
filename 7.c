#include<stdio.h>
#include<fcntl.h>
main()
{
	int ret;
	ret=open("1.txt",O_CREAT|O_RDWR,0664);
	printf("%d\n",ret);
}
