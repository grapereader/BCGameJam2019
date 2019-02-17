all: game

OBJECTS=main.o \
	ui.o \
	input.o \
	audio.o \
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
	enc_goat.o \
	enc_core.o

%.o: %.c
	$(CC) -g $(shell pkg-config --cflags sdl2 SDL2_mixer) -c $< -o $@

game: $(OBJECTS)
	$(CC) -g $^ $(shell pkg-config --libs sdl2 SDL2_mixer) -lncurses -lm -o game

clean:
	rm -rf *.o game