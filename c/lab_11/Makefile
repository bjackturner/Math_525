CC = gcc
CFLAGS = -O3 -Wall
LFLAGS =
OBJECTS = main.o \
          generateList.o \
          Print.o \
          getKey.o \
          searchList.o \
          deleteList.o

.PHONY: clean help

main.exe: $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -o main.exe

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) main.exe

