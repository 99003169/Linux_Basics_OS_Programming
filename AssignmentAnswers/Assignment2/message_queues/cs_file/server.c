/*
Write a program to retrieve file attributes using message queue as follows
   * Client process sends requested file name to server over message queue
   * Server process retrieves file attributes using lstat and send back to client
   * Client will display the file attributes
*/

// server

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>

void printFileProperties(struct stat stats);

struct msg_buffer {
   long message_type;
   char message[100];
   struct stat stats;
} msg;

int main()
{
  
    struct stat stats;

   key_t my_key;
   int msg_id;
   int c,s,ret,i,j=0;
   char path[100];
   my_key = ftok("progfile", 65); //create unique key
   msg_id = msgget(my_key, 0666 | IPC_CREAT); //create message queue and return id
   msgrcv(msg_id, &msg, sizeof(msg), 1, 0);
   for(i=0;i<strlen(msg.message);i++)
   {
   if(msg.message[i]==39||msg.message[i]=='\n')
   {}
   else
   {
   path[j]=msg.message[i];
   j++;}
   }
    // stat() returns 0 on successful operation,
    // otherwise returns -1 if unable to get file properties.
    if (stat(path, &msg.stats) == 0)
    {
        
        msgsnd(msg_id, &msg, sizeof(msg), 0);
    }
    else
    {
        printf("Unable to get file properties.\n");
        printf("Please check whether '%s' file exists.\n", path);
    }
    return 0;
}