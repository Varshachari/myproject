#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
main()
{
	int ret;
	ret=mkdir("makedir",0664); //created makedir
//	ret=rename("makedir","createdir");   //rename createdir
	printf("%d\n",ret);
//	ret=rmdir("makedir");   //removed
//	remove("makedir.txt");   //text file is removed
//	printf("%d\n",ret);
}
