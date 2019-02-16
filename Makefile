all: game

main.o: main.c
	$(CC) -c main.c -o main.o

game: main.o
	$(CC) main.o -lncurses -o game

clean:
	rm -rf *.o game