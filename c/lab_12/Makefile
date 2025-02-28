CC = gcc
CFLAGS = -O3 -Wall
LFLAGS =
OBJECTS = main.o \
          Option.o \
          DisplayOptions.o \
          Push.o \
          Pop.o \
          Peek.o \
          DisplayStack.o \
          GetStackSize.o \
          DeleteStack.o

.PHONY: clean help

main.exe: $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -o main.exe

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJECTS) main.exe

help:
	@echo "Makefile for managing the compilation of the program."
