/*
Write a program to send specific signal to a target process (with given id, like kill command)
*/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h> 

int main(int argc ,char *argv[])    //Pass PID and Signal no. as arguments to main() while executing
{
	int pid = atoi(argv[1]);
    int signalnum = atoi(argv[2]);
	switch(signalnum){
	    case 9:   
            printf("Killing the process\n");
		    kill(pid, 9);  //SIGNAL #9 - SIGKILL
	        break;
	    case 2:
            printf("Interupting the process");
		    kill(pid, 2);  //SIGNAL #2 - SIGINT
		    break;
	    case 3:
            printf("Quiting the process");
		    kill(pid, 3);  //SIGNAL #3 - SIGQUIT
		    break;
        case 6:
            printf("Aborting the process");
		    kill(pid, 6);  //SIGNAL #6 - SIGABRT
		    break;
	    default:
            printf("Signal executed");
		    kill(pid, signalnum); 
	}
    return 0;
}
