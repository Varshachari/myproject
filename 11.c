#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
int MAX=100;
int count=0;
void *printevennum(void *ptr);
void *printoddnum(void *ptr);
main()
{
	pthread_t ti1,ti2;
	int *ptr;
	pthread_create(&ti1,NULL,&printevennum,NULL);
	pthread_create(&ti2,NULL,&printoddnum,NULL);
	pthread_join(ti1,&ptr);
	pthread_join(ti2,&ptr);
}
void *printevennum(void *ptr)
{
	while(count <MAX)
	{
		if (count %2==0)
		{
			printf("even:%d\n",count);
			count++;
		}
	}
		pthread_exit(0);
	
}
void *printoddnum(void *ptr)
{
	while(count <MAX)
	{
		if (count %2==1)
		{
			printf("odd:%d\n",count);
			count++;
		}
	}
		pthread_exit(0);
	
}



