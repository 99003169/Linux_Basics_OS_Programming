/*
Write a program to print current time periodically (Hint:- alarm, time, ctime)
*/

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<signal.h>
#include<time.h>

void* thread1(void* arr){
    while(1){
        alarm(2);
        sleep(2);
    }
    pthread_exit(NULL);
}

void* thread2(void* arr){
    while(1){
        alarm(2);
        sleep(2);
    }
    pthread_exit(NULL);
}

void alarm_handler(int signum){
    time_t * currtime;
    time(currtime);
    printf("Current Time : %s\n",ctime(currtime));
}

int main(){
    signal(SIGALRM, alarm_handler);

    pthread_t th[2];
    pthread_create(&th[0],NULL,thread1,NULL);
    pthread_create(&th[1],NULL,thread2,NULL);

    pthread_join(th[0],NULL);
    pthread_join(th[1],NULL);
   
    printf("Main --- Thank You!");
	return 0;
}