all: build

build: file_copy main 

file_copy: file_copy.c
	gcc -c file_copy.c -o file_copy.o

main: main.c 
	gcc -c main.c -o main.o

run: file_copy.o main.o
 	gcc file_copy.o main.o -o a.out
	./a.out



