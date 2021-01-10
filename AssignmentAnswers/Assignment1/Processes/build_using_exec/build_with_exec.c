/*
Write a program to compile & link any c/c++ program within child process by launching gcc using execl/execlp.
*/

#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>

int main()
{
	int ret,returni;
	ret=fork();
	if(ret<0)
	{
		perror("fork");
		exit(1);
	}
	if(ret==0)
	{ 
    	execl("/bin/gcc","gcc","hello.c","-o","hello.out",NULL) ; 
	}
	else	
	{
		waitpid(ret, &returni, 0); 
		execl("./hello.out","./hello.out",NULL) ; 
	}
	exit(0);
}

