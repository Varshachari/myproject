#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void myhandler(int signo);
main()
{
	//int ret;
	//ret=signal(3,SIG_IGN);
	//printf("%d\n",ret);
	myhandler(3);
	while(1)
	{
		printf("1");
	}

}
void myhandler(int signo)
{
	printf("received signal:%d\n",signo);
//	sleep(5);
}

