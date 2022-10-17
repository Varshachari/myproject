#include<stdio.h> 
#include<stdlib.h>
    // Taking argument as command line 
int main(int argc, char *argv[])  
{ 
     int a,b;
     if(arg<3)
{
	     printf("enter 2 arguments");
	     return 0;
}
a=atoi(argv[1]);

b=atoi(argv[2]);

printf("values are = %d %d", a, b);

}


