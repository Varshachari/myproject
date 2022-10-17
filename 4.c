#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void *small(void *ptr);
void *capital(void *ptr);
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
main()
{
	char wrd[20];
	pthread_t ti1,ti2;
	char *ptr;
	printf("enter the letter\n");
	scanf("%s",&wrd);
	pthread_create(&ti1,NULL,small,NULL);
	pthread_create(&ti2,NULL,capital,NULL);
	pthread_join(&ti1,&ptr);
	pthread_join(&ti2,&ptr);
}
void *capital(void *ptr)
{
	int i,wrd;
	pthread_mutex_lock(&mutex);
	for(i=0;wrd[i]!='\0';i++)
	{
		sleep(1);
		if(wrd[i]>=65 && wrd[i]<=90)
		{
			printf("capital letters\n",wrd[i]);
		}
		pthread_mutex_unlock(&mutex);
	}
}
void *small(void *ptr)
{
	int i,wrd;
	pthread_mutex_lock(&mutex);
	for(i=0;wrd[i]!='\0';i++)
	{
		sleep(1);
		if(wrd[i]>=97 && wrd[i]<=122)
		{
			printf("small letters\n",wrd[i]);
		}
		pthread_mutex_unlock(&mutex);
	}
}
