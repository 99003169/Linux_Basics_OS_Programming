/*
Implement a simple client-server scenario using message queues
   * Client process send requested command over message queue
   * Server process receives requested command over message queue and executes in a child process using execl/execlp
*/

// client

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct message_buffer {
   long message_type;
   char message[100];
} msg;

int main() {
   key_t my_key;
   int msg_id;
   my_key = ftok("progfile", 65); //create unique key
   msg_id = msgget(my_key, 0666 | IPC_CREAT); //create message queue and return id
   msg.message_type = 1;
   printf("Enter Command: ");
   fgets(msg.message, 100, stdin);
   msgsnd(msg_id, &msg, sizeof(msg), 0); //send message
   return 0;
}
