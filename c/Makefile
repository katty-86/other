CC = gcc
CFLAGS = -Wall -Wextra -pedantic
OBJECTS = main.o kk_list.o

list : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o list

main.o : main.c
	$(CC) $(CFLAGS) -c main.c

kk_list.o : kk_list.c
	$(CC) $(CFLAGS) -c kk_list.c kk_list.h

clean:
	rm kk_list.o main.o
