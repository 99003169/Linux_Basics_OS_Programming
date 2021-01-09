/*
Write a program to retrieve file attributes using message queue as follows
   * Client process sends requested file name to server over message queue
   * Server process retrieves file attributes using lstat and send back to client
   * Client will display the file attributes
*/

// client

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <time.h>
#include<unistd.h>
#include <sys/wait.h>
#include <string.h>

void printFileProperties(struct stat stats);

struct msg_buffer {
   long message_type;
   char message[100];
   struct stat stats;
} msg;

int main() {
   key_t my_key;
   int msg_id;
   my_key = ftok("progfile", 65); //create unique key
   msg_id = msgget(my_key, 0666 | IPC_CREAT); //create message queue and return id
   msg.message_type = 1;
   printf("Enter File path: ");
   fgets(msg.message, 100, stdin);
   msgsnd(msg_id, &msg, sizeof(msg), 0); //send message
   msgrcv(msg_id, &msg, sizeof(msg), 1, 0); 
   printFileProperties(msg.stats);
   //printFileProperties(message.stats);
   return 0;
}

void printFileProperties(struct stat stats)
{
    struct tm dt;

    // File permissions
    printf("\nFile access: ");
    if (stats.st_mode & R_OK)
        printf("read ");
    if (stats.st_mode & W_OK)
        printf("write ");
    if (stats.st_mode & X_OK)
        printf("execute");

    // File size
    printf("\nFile size: %ld", stats.st_size);

    // Get file creation time in seconds and 
    // convert seconds to date and time format
    dt = *(gmtime(&stats.st_ctime));
    printf("\nCreated on: %d-%d-%d %d:%d:%d", dt.tm_mday, dt.tm_mon, dt.tm_year + 1900, 
                                              dt.tm_hour, dt.tm_min, dt.tm_sec);

    // File modification time
    dt = *(gmtime(&stats.st_mtime));
    printf("\nModified on: %d-%d-%d %d:%d:%d \n", dt.tm_mday, dt.tm_mon, dt.tm_year + 1900, 
                                              dt.tm_hour, dt.tm_min, dt.tm_sec);

}
