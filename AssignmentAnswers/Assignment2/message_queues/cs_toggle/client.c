/*
Implement a simple client-server scenario using message queues
   * Client process send a string over message queue
   * Server process toggles the string and send back to client.
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
   printf("Write Message : ");
   fgets(msg.message, 100, stdin);
   printf("Sent message is : %s \n", msg.message);
   msgsnd(msg_id, &msg, sizeof(msg), 0); //send message
   msgrcv(msg_id, &msg, sizeof(msg), 1, 0); //used to receive message
   // display the message
   printf("Received Message is : %s \n", msg.message);
   return 0;
}
