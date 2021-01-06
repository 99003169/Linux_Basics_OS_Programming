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
    int  rdret, ccount = 0, lcount = 0, wcount = 0;
    char buf;
    while(1){
        rdret = read(fr, &buf, 1);
        if(rdret < 0){
            perror("read");
            exit(2);
        }
        if(buf != '0'){
            ccount++;
            if(buf == '\n'){
                lcount++;
            }else if(buf == ' '){
                wcount++;
            }
        }else{
            break;
        }
    }
    printf("line count = %d\n", lcount);
    printf("word count = %d\n", wcount+lcount);
    printf("character count = %d", ccount);
    close(fr);
    return 0;
}