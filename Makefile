# Makefile for compiling C code using the Clang compiler
all: main

CC = clang

CCFLAGS = -Wextra -Wall -Wpendatic

SRC = src/main.c

PROGRAM = staffsync

main: $(SRC)
	$(CC) $(CCFLAGS) $(SRC) -o $(PROGRAM)

debug:$(SRC)
	$(CC) $(CCFLAGS) $(SRC) -o $(PROGRAM) -g

run:
	./staffsync

clean:
	rm -f $(PROGAM)