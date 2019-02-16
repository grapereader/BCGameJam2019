all: game

OBJECTS=main.o \
	ui.o \
	input.o \
	statemachine.o \
	states.o \
	st_gameplay.o \
	st_menu.o \
	st_score.o \
	rd_chad.o

%.o: %.c
	$(CC) -c $< -o $@

game: $(OBJECTS)
	$(CC) $^ -lncurses -lm -o game

clean:
	rm -rf *.o game