/*
Write a program to count no.of lines, words, characters in given file (like wc command)
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    int fr;
    fr = open("input.txt", O_RDONLY);
    if(fr < 0){
        perror("open");
        exit(1);
    }
    int  rdret, len, lcount = 0, wcount = 0;
    char buf[1000];
    rdret = read(fr, &buf, 128);
    if(rdret < 0){
        perror("read");
        exit(2);
    }
    for(int i = 0; i < rdret; i++){
        if(buf[i] == '\n'){
            lcount++;
        }
        else if(buf[i] == ' '){
            wcount++;
        }
    }
    lcount += 1;
    wcount += lcount;
    printf("line count = %d\n", lcount);
    printf("word count = %d\n", wcount);
    printf("character count = %d", rdret);
    close(fr);
    return 0;
}