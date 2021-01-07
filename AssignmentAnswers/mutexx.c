#include<pthread.h>
#include<stdio.h>

int val =100;

pthread_mutex_t m1=PTHREAD_MUTEX_INITIALIZER;

void* task_body1(void* pv)
{
	for(int i=1;i<=10;i++)
    val++;
}

void* task_body2(void* pv)
{
	for(int i=1;i<=10;i++)
    val--;
}

int main()
{
	pthread_t pt1,pt2;	//thread handle

	pthread_create(&pt1,NULL,task_body1,NULL);
	pthread_create(&pt2,NULL,task_body2,NULL);
	
    pthread_join(pt1,NULL);
	pthread_join(pt2,NULL);
	
    printf("val = %d\n", val);
	return 0;	//exit(0);
}

