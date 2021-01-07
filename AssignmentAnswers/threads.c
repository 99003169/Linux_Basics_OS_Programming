#include<stdio.h>
#include<pthread.h>

void* total(void* arr,void* sum){
      
}

int main(){
    int arr[100];
    for(int i = 0; i < 100; i++){
        arr[i] = i;
    }
    pthread_t th[10];
    int k = 0, sum[10];
    for(int j = 0; j <10; j++){
        pthread_create(&th[j],NULL,total,arr[k],sum[j]);
        k += 10;
    }
    return 0;
}