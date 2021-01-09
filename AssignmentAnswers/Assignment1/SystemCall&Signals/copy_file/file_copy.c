/*
Write a program to copy one file contents to other using open,read,write,close system calls 
(like cp command, which takes source, destination files as cmd line args)
*/

#include "file_copy.h"

void copyfile(void){
    int fr;
    fr = open("input.txt", O_RDONLY);
    if(fr<0){
        perror("open");
        exit(1);
    }
    int fw, rdret, wrret, maxsize = 128;
    char buf[maxsize]; 
    fw = open("output.txt", O_WRONLY|O_CREAT, 0666);
    rdret = read(fr, buf, maxsize);
    if(rdret < 0){
        perror("read");
        exit(2);
    }
    wrret = write(fw, buf, rdret);
    if(wrret < 0){
        perror("write");
        exit(3);
    }
    close(fr);
    close(fw);
    return 0;
}