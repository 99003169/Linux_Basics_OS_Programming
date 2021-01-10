/*
Write a program to build multifile program using fork & exec as follows
   * There are multiple source files holding some functions
   * Create multiple child processes to compile each source file (execl/execlp)
   * On successful completion, launch another child process for linking
   * On successful linking, launch another child process for executing
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
	int child1=fork();
	int child2;
	int child3;
	int child4;
	int child5;
	
	if(child1<0){
	    perror("fork");
	    exit(1);
	}
	if(child1==0){ 
	    execl("/bin/gcc","gcc","-c","maths.c",NULL);
    }
    else{
    	waitpid(child1, &returni, 0);
    	child2=fork();
		if(child2<0){
	    	perror("fork");
	    	exit(2);
		}
    }
	if(child2==0){
        execl("/bin/gcc","gcc","-c","addition.c",NULL);
    }
    else{
        waitpid(child2, &returni, 0);
    	child3=fork();
		if(child3<0){
	    	perror("fork");
	    	exit(3);
		}
    }
	if(child3==0){
        execl("/bin/gcc","gcc","maths.o","addition.o","-o","maths.out",NULL);
    }
  	else{
        waitpid(child3, &returni, 0);
		child4=fork();
		if(child4<0){
	    	perror("fork");
	    	exit(4);
		} 
    } 
	if(child4==0){
        execl("./maths.out", "./maths.out", NULL); 
    }
  	else{
        waitpid(child4, &returni, 0);  
    } 
	exit(0);
}

