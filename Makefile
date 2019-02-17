all: game

OBJECTS=main.o \
	ui.o \
	input.o \
	encounters.o \
	statemachine.o \
	states.o \
	st_gameplay.o \
	st_menu.o \
	st_encounter.o \
	st_score.o \
	st_message.o \
	rd_chad.o \
	enc_tree.o \
	enc_lightning.o \
	enc_goat.o

%.o: %.c
	$(CC) -g -c $< -o $@

game: $(OBJECTS)
	$(CC) -g $^ -lncurses -lm -o game

clean:
	rm -rf *.o game