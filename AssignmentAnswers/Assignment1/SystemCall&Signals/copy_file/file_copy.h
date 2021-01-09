/*
Write a program to copy one file contents to other using open,read,write,close system calls 
(like cp command, which takes source, destination files as cmd line args)
*/

#ifndef FILE_COPY_H_
#define FILE_COPY_H_

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

void copyfile(void);

#endif