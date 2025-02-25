# $ISUHPC / lectures / lecture11 / codes / linked_list / Makefile
CC = gcc
FFLAGS = -O3 -Wall
LFFLAG =
OBJECTS = main.o \
GenerateList .o \
Print .o \
getKey .o \
searchList .o \
deleteList .o

.PHONY: clean help

main.exe: $( OBJECTS ) 
    $(CC) $( LFLAGS ) $( OBJECTS ) -o .\c\lab_11\main.exe

%.o: %.c
    $(CC) $( FFLAGS ) -c $<

clean :
    rm -f $( OBJECTS ) main.exe

