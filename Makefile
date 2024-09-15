C = gcc
CFLAGS = -Wall -Wextra -std=c99 `sdl2-config --cflags`
LIBS = `sdl2-config --libs`

all: game

game: main.o
	$(CC) $(CFLAGS) main.o -o game $(LIBS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o game
