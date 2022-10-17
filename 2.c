#include<stdio.h>
#include<pthread.h>
void *thr_fun1(void *ptr);
void *thr_fun2(void *vr1);
int g=0;
pthread_mutex_t mutex1=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2=PTHREAD_MUTEX_INITIALIZER;
main()
{
	int p,q,r,s,x,loop=20;
	pthread_t ti1,ti2;
	int *vr;
	p=pthread_create(&ti1,NULL,thr_fun1,&loop);
	printf("successp:%d\n",p);
	printf("ti1:%d\n",ti1);
	printf("vr:%p\n",vr);
	q=pthread_create(&ti2,NULL,thr_fun2,&loop);
	printf("successq:%d\n",q);
	printf("ti2:%d\n",ti2);
	printf("vr2:%p\n",vr);
	r=pthread_join(ti1,&vr);
	printf("successr:%d\n",r);
	s=pthread_join(ti2,&vr);
	printf("successs:%d\n",s);
	printf("%d\n",g);
}
void *thr_fun1(void *ptr)
{
	int i,loop,l,x;
	loop=*(int*)ptr;
	for(i=0;i<loop;i++,printf("fun1-i:%d\n",i))
	{
		pthread_mutex_lock(&mutex1);
		l=g;
		printf("fun1 l-g:%d-%d\n",l,g);
		l++;
		printf("fun1 l:%d\n",l);
		g=l;
		printf("fun1 g-l:%d-%d\n",g,l);
		pthread_mutex_unlock(&mutex2);
	}
	return 0;
}
void *thr_fun2(void *vr1)
{
	int i,loop,l;
	loop=*(int*)vr1;
	for(i=0;i<loop;i++,printf("fun2-i:%d\n",i))
	{
		pthread_mutex_lock(&mutex2);
		l=g;
		printf("fun2 l-g:%d-%d\n",l,g);
		l++;
		printf("fun2 l:%d\n",l);
		g=l;
		printf("fun2 g-l:%d-%d\n",g,l);
		pthread_mutex_unlock(&mutex1);
	}
	return 0;
}
