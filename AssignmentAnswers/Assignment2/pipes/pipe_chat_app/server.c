/*
Write a program to implement simple chat application between two processes using named pipes (FIFOs)
*/

//server_chat

#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<linux/stat.h>

#define FIFO "MYFIFO"

int main(void)
{
   FILE *fptr;
   char read_buffer[80],a[40];
   umask(0);
   mknod(FIFO,S_IFIFO|0666,1);
   start:
      fptr=fopen(FIFO,"r");
      fgets(read_buffer,80,fptr);
      printf("Client :%s\n",read_buffer);
      fclose(fptr);
      sleep(1);
      printf("Server : ");
      gets(a);
      fptr=fopen(FIFO,"r+");
      if(a[strlen(a)-1]=='.')
      {
         fputs(a,fptr);
         fclose(fptr);
         return 0;
       }
      fputs(a,fptr);
      fclose(fptr);
      sleep(1);
      goto start;
   return 0;
}

