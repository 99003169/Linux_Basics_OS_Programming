/*
Repeat above two problem by replacing semaphores with mutex wherever possible
	--> Implement producer consumer problem using Stack operations using semaphores
*/

#include<pthread.h>
#include<semaphore.h>
#include<stdio.h>

#define stackdepth 10

int mystack[stackdepth];     
int stackptr = -1; 

int isempty() {
    if(stackptr == -1)
        return 1;
    else
        return 0;
}
   
int isfull() {
    if(stackptr == stackdepth)
        return 1;
    else
        return 0;
}

int peek() {
    if(!isempty())
        return mystack[stackptr];
    else
        printf("Couldn't retrieve data, Stack is empty.\n");
}

int pop() {
    int data;
    if(!isempty()) {
        data = mystack[stackptr];
        stackptr -= 1;   
        return data;
    } 
    else {
        printf("Couldn't retrieve data, Stack is empty.\n");
    }
}

int push(int data) {
    if(!isfull()) {
        stackptr += 1;   
        mystack[stackptr] = data;
    } 
    else {
        printf("Couldn't insert data, Stack is full.\n");
    }
}

const int max=10;
pthread_mutex_t m1=PTHREAD_MUTEX_INITIALIZER;
sem_t s1;

void* producer_push(void* pv){
	int i;
	pthread_mutex_lock(&m1);
	printf("Producer pushing 2\n");
	push(2);
	printf("Producer pushing 3\n");
	push(3);
	printf("Producer pushing 4\n");
	push(4);
	pthread_mutex_unlock(&m1);
	printf("Producer posting semaphore\n");
	sem_post(&s1);
	pthread_exit(NULL);
}

void* consumer_pop(void* pv){
	int i;
	printf("Consumer waiting for semaphore\n");
	sem_wait(&s1);	
	printf("Consumer acquired semaphore\n");
	pthread_mutex_lock(&m1);
	printf("Consumer poping %d\n", pop());
	printf("Consumer poping %d\n", pop());
	pthread_mutex_unlock(&m1);
	pthread_exit(NULL);
}

int main(){
	pthread_t pt1,pt2;	//thread handles
	sem_init(&s1,0,0);
	pthread_create(&pt1,NULL,producer_push,NULL);
	pthread_create(&pt2,NULL,consumer_pop,NULL);
	pthread_join(pt1,NULL);
	pthread_join(pt2,NULL);
	printf("Element at top of the stack: %d\n" ,peek());
	printf("Stack full: %s\n" , isfull()?"true":"false");
   	printf("Stack empty: %s\n" , isempty()?"true":"false");
	sem_destroy(&s1);
	pthread_mutex_destroy(&m1);
	return 0;
}

