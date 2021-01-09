all: build

build: producer.c consumer.c
	gcc producer.c -o p.out -lpthread -lrt
	gcc consumer.c -o c.out -lpthread -lrt

run_producer: p.out 
	./p.out

run_consumer: c.out
	./c.out
	

