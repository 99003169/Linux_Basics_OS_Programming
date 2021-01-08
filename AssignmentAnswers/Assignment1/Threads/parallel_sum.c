/*
Write a program to compute parallel sum of large array using threads. 
For e.g. if there are 1000 elements in array, you may create 10 threads where each thread will compute some of 100 elements each, 
on completion of threads main thread will consolidate final total
*/

#include<stdio.h>
#include<pthread.h>

void* total(void* arr){
    int* arry = arr;
    int sum = 0;
    for(int x=0; x<100; x++){
        sum += *arry;
        arry++;
    }
    pthread_exit((void*)sum);
}

int main(){
    int arr[1000];
    for(int i = 0; i < 1000; i++){
        arr[i] = i;
    }
    
    pthread_t th[10];
    int k = 0;
    for(int j = 0; j <10; j++){
        pthread_create(&th[j],NULL,total,&arr[k]);
        k += 100;
    }
    int parallelsum = 0;
    void* sum;
    for(int i = 0; i < 10; i++){
	    pthread_join(th[i],&sum);
        parallelsum += (int) sum;
    }
    printf("Sum = %d\n", parallelsum);
	printf("main--thank you\n");
	return 0;
}