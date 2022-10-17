#include<stdio.h>
#include<sys/shm.h>
#define KEY 0X19980
main()
{
	char *ptr;
	int shmid;  //access the shared memory region
	shmid=shmget(KEY,100,0);  //create
	ptr=shmat(shmid,NULL,0);  //attach
	strcpy(ptr,"hii");
	shmdt(ptr);        //detach
}
