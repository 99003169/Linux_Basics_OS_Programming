/*
Write a program to implement simple chat application between two processes using named pipes (FIFOs)
*/

//client_chat

#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h> 
#include<linux/stat.h>

#define FIFO "MYFIFO" //create MYFIFO pipe before executin mkfifo MYFIFO

int main()
{
   FILE *fp;
   char a[40];
   char read_buffer[80];
   start:
      if((fp=fopen(FIFO,"r+"))==NULL)
      {
         perror("fopen");
         exit(1);
      }
      printf("Client: ");
      gets(a);
      if(a[strlen(a)-1]=='.')
      {
           fputs(a,fp);
           fclose(fp);
           return 0;
      }
      fputs(a,fp);
      fclose(fp);
      sleep(1);
      fp=fopen(FIFO,"r");
      fgets(read_buffer,80,fp);
      printf("Server :%s\n",read_buffer);
      fclose(fp);
      sleep(1);
      goto start;
   return 0;
}

