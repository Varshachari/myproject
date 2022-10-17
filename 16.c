#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
int min,max;
int x=0;
void *threadeven(void *ptr);
void *threadodd(void *ptr);
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
void main()
{

	pthread_t ti1,ti2;
	printf("enter min and max values\n");
	scanf("%d %d", &min,&max);
	pthread_create(&ti1,NULL,threadeven,NULL);
	pthread_create(&ti1,NULL,threadodd,NULL);
	pthread_join(ti1,NULL);
	pthread_join(ti2,NULL);
	
}
void *threadeven(void *ptr)
{
	int i;
	for(i=min;i<=max;i++)
	{
//		sleep(1);
		pthread_mutex_lock(&mutex);
		if(x==0)
		{
//		printf("wait\n");
	        pthread_cond_wait(&cond,&mutex);
//		printf("signal received\n");
		}
		if(i%2==0)
		{
			printf("thread 1:%d\n",i);
		}
		pthread_mutex_unlock(&mutex);
	}
//	printf("execution done\n");
	return 0;
}
void *threadodd(void *ptr)
{
	int i;
	for(i=min;i<=max;i++)
//	printf("odd thread:%d\n",i)
	{
//		sleep(1);
		pthread_mutex_lock(&mutex);
		if(i%2!=0)
		{
			printf("thread 2:%d\n",i);
		}
		pthread_mutex_unlock(&mutex);
		pthread_cond_signal(&cond);
		x++;

	}
	return 0;
}


