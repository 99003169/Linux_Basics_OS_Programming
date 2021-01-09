/*
Implement a simple client-server scenario using message queues
   * Client process send requested command over message queue
   * Server process receives requested command over message queue and executes in a child process using execl/execlp
*/

// server

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<unistd.h>
#include <sys/wait.h>

struct message_buffer {
   long message_type;
   char message[100];
} msg;

int main() {
   key_t my_key;
   int msg_id;
   int c,s,ret;
   my_key = ftok("progfile", 65); //create unique key
   msg_id = msgget(my_key, 0666 | IPC_CREAT); //create message queue and return id
   msgrcv(msg_id, &msg, sizeof(msg), 1, 0); //used to receive message
   printf("Received Command is : %s \n", msg.message);
   c=fork();
   if(c==0)
      s=execl("/bin/sh","sh","-c",msg.message,NULL);
   else{
      waitpid(c, &ret, 0); 
      return 0;
   }
}
