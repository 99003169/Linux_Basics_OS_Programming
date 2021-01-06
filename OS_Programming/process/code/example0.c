#include<unistd.h>

int main()
{
	printf("welcome..pid=%d\n",getpid());
	int ret=fork();
	printf("thank you,pid=%d,ppid=%d, ret =%d\n", 
			getpid(),getppid(),ret);
	return 0;
}
