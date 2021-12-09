# Compiler and necessary flags
CC = gcc
CFLAGS = -Wall -g -O3
LDFLAGS = --std=c99 

# Link together all executables and build them into the final executable
main: main.o linked_list.o parse.o matrix.o
	$(CC) $(CFLAGS) -o main main.o linked_list.o parse.o matrix.o $(LDFLAGS)

# Make an executable for each of the following c files
main.o: main.c
	$(CC) $(CFLAGS) -c main.c $(LDFLAGS)

linked_list.o: linked_list.c
	$(CC) $(CFLAGS) -c linked_list.c $(LDFLAGS)

parse.o: parse.c
	$(CC) $(CFLAGS) -c parse.c $(LDFLAGS)

matrix.o: matrix.c
	$(CC) $(CFLAGS) -c matrix.c $(LDFLAGS)

# make clean option
clean:
	rm -f main main.o linked_list.o parse.o matrix.o
