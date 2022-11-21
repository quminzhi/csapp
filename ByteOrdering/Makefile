.PHONY: run clean

CFLAGS = -g -Wall -Werror -std=c11 -O2
CC = gcc
LD = gcc

main: bytes.o test.o
	$(LD) $(LDFLAGS) -o main bytes.o test.o

bytes.o: bytes.c bytes.h
	$(CC) $(CFLAGS) -c -o bytes.o bytes.c

test.o: test.c
	$(CC) $(CFLAGS) -c -o test.o test.c

run: main
	@./main

clean:
	rm -f main *.o
