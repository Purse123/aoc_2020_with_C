CC = gcc
CFLAGS = -Wall
LIBS = -lc 

all: part1 part2

part1: part1.c
	$(CC) -o part1 part1.c $(CFLAGS)

part2: part2.c validation.c parser.c
	$(CC) part2.c validation.c parser.c -o part2 $(CFLAGS) $(LIBS)

clean:
	rm -f part1 part2
