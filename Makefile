# Makefile for compiling C code using the Clang compiler
all: main

CC = clang

CCFLAGS = -Wextra -Wall -Wpedantic

SRC = src/main.c -lcdk -lncurses

PROGRAM = staffsync

main: $(SRC)
	$(CC) $(CCFLAGS) $(SRC) -o $(PROGRAM)

debug:$(SRC)
	$(CC) $(CCFLAGS) $(SRC) -o $(PROGRAM) -g

run:
	./$(PROGRAM)

clean:
	rm -f $(PROGRAM)