all: build

build: server.c client.c
	gcc server.c -o s.out
	gcc client.c -o c.out

run_server: s.out 
	./s.out

run_client: c.out
	./c.out
	

