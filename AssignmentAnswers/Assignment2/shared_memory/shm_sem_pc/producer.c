/*
Implement producer consumer problem between two processes using shared memory and named semaphores (POSIX APIs)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <unistd.h> // for close

int main()
{
    const char * name = "shared_memory";
    const char * sema1= "fill";
    const char * sema2= "avail";
    const char * sema3= "mutex";
    int shm_fd;   //shared memory file discriptor
    int * shelf;
    int loop=6;  
    sem_t * fill, * avail, * mutex;
    /* make * shelf shared between processes*/
    //create the shared memory segment
    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    //configure the size of the shared memory segment
    ftruncate(shm_fd,sizeof(int));
    //map the shared memory segment in process address space
    shelf = mmap(0,sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    /* creat/open semaphores*/
    //producer post semaphore fill after producing the item
    fill = sem_open(sema1, O_CREAT,0666,0);
    //consumer post semaphore avail consuming the item
    avail = sem_open(sema2, O_CREAT, 0666, 1);
    //mutex for mutual exclusion of shelf
    mutex = sem_open(sema3,O_CREAT,0666,1);
    printf("\nProducer: I have started Producing.\n");
    while(loop--){
        sem_wait(avail);
        sleep(rand()%2+1);
        sem_wait(mutex);
        (* shelf)++;
        sem_post(mutex);
        printf("Producer: production finish, there are %d items now\n", * shelf);
        sem_post(fill);
    }
    printf("Producer: Time is up. I produced 6 items. %d are left.\n", * shelf);
      /* close and unlink semaphores*/
    sem_close(fill);
    sem_close(avail);
    sem_close(mutex);
    sem_unlink(sema1);
    sem_unlink(sema2);
    sem_unlink(sema3);
      /* close and unlink shared memory*/
      munmap(shelf, sizeof(int));
    close(shm_fd);
    shm_unlink(name);
    return 0;
}


