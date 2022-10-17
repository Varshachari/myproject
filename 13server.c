#include<stdio.h>
#include<sys/shm.h>
#define KEY 0X19980
main()
{
	char *ptr;
	int shmid=shmget(KEY,100,IPC_CREAT|0640);  //create shared memory
	ptr=shmat(shmid,NULL,0);   //attach 
	while(ptr[0]!='h');  //blocking call
	printf("%s\n",ptr); 
	shmdt(ptr);    //detach
}
