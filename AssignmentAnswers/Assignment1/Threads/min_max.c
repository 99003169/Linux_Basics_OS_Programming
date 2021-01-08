/*
Write a program to find min/max element from large array(1000 data points) using parallel computations (multthreading)
*/

#include<stdio.h>
#include<pthread.h>

void* min(void* arr){
    int* arry = arr;
    int min;
    for(int x=0; x<1000; x++){
        if(*arry < min){
            min = *arry;
        }
        arry++;
    }
    pthread_exit((void*)min);
}

void* max(void* arr){
    int* arry = arr;
    int max;
    for(int x=0; x<1000; x++){
        if(*arry > max){
            max = *arry;
        }
        arry++;
    }
    pthread_exit((void*)max);
}

int main(){
    int arr[1000];
    for(int i = 0; i < 1000; i++){
        arr[i] = i;
    }
    
    pthread_t th[2];
    pthread_create(&th[0],NULL,min,arr);
    pthread_create(&th[1],NULL,max,arr);

    void *min, *max;
    pthread_join(th[0],&min);
    pthread_join(th[1],&max);
   
    printf("Minimum = %d\n", (int) min);
    printf("Maximum = %d\n", (int) max);
	return 0;
}