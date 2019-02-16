all: game

main.o: main.f90
	f95 -fbackslash -c main.f90 -o main.o

macros.o: macros.c
	gcc -c macros.c -o macros.o

cfuncs.o: cfuncs.c
	gcc -c cfuncs.c -o cfuncs.o

ncurses.o: ncurses.f90
	f95 -c ncurses.f90 -o ncurses.o

game: cfuncs.o main.o ncurses.o macros.o
	f95 -Wl,-rpath=/usr/local/lib/gcc8/ -I. -L/usr/local/lib/ cfuncs.o main.o ncurses.o macros.o -lncurses -o game

clean:
	rm -rf *.mod *.o game

