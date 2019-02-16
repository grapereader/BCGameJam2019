all: game

OBJECTS=main.o ui.o input.o statemachine.o states.o st_gameplay.o st_menu.o st_score.o

%.o: %.c
	$(CC) -c $< -o $@

game: $(OBJECTS)
	$(CC) $^ -lncurses -o game

clean:
	rm -rf *.o game