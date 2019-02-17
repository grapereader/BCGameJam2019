all: game

main.o: main.f90
	f95 -c main.f90 -o main.o

ui.o: ui.f90
	f95 -c ui.f90 -o ui.o

game.o: game.f90
	f95 -c game.f90 -o game.o

states.o: states.f90
	f95 -c states.f90 -o states.o

macros.o: macros.c
	gcc -c macros.c -o macros.o

cfuncs.o: cfuncs.c
	gcc -c cfuncs.c -o cfuncs.o

ncurses.o: ncurses.f90
	f95 -c ncurses.f90 -o ncurses.o

game: cfuncs.o macros.o ncurses.o ui.o states.o game.o main.o
	f95 -Wl,-rpath=/usr/local/lib/gcc8/ -I. -L/usr/local/lib/ cfuncs.o main.o ui.o game.o states.o ncurses.o macros.o -lncurses -o game

clean:
	rm -rf *.mod *.o game

