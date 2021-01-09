/*
Implement producer consumer problem using circular buffer operations using semaphores
*/

#include<stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <pthread.h>

# define size 10

sem_t empty;
sem_t full;

int circularbuffer[size];
int producerptr = -1;
int consumerptr = -1;

void push(int item){
   if((consumerptr == 0 && producerptr == size-1) || (consumerptr == producerptr + 1)){
      printf("Buffer Overflow\n");
      return;
   }

   if(producerptr == -1){
      producerptr = 0;
      consumerptr = 0;
   }
   else if(producerptr == size-1){
      producerptr = 0;
   }
   else{
      producerptr += 1;
   }

   circularbuffer[producerptr] = item;
   printf("Producer wrote %d\n",item);
}

void pop(){
   if(producerptr == -1){
      printf("Buffer Underflown");
      return ;
   }
   printf("Consumer read %d\n",circularbuffer[consumerptr]);
   if(consumerptr == producerptr){
      producerptr = -1;
      consumerptr = -1;
   }
   else if(consumerptr == size-1){
      consumerptr = 0;   
   }
   else{
      consumerptr += 1;
   }
}

int i = 0, j = 0, count = 1;

void* producer(void* pv){ 
   while(i < 10){
      sem_wait(&empty);
      push(count);
      sem_post(&full);
      sleep(1);
      count++;
      i++;
   }
}

void* consumer(void* pv){
   while(j < 5){
      sem_wait(&full);
      pop();
      sem_post(&empty);
      sleep(1);
      j++;
   }
}

int main(){
   int item;
   sem_init(&empty,0,size);
   sem_init(&full,0,0);
   pthread_t pr, cn;
   pthread_create(&pr, NULL, producer, NULL);
   pthread_create(&cn, NULL, consumer, NULL);
   pthread_join(pr, NULL);
   pthread_join(cn, NULL);
   sem_destroy(&empty);
   sem_destroy(&full);
   return 0;
}
