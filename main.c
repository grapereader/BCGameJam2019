#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>

#include <ncurses.h>

#include "statemachine.h"
#include "states.h"
#include "input.h"
#include "const.h"

game_t game_state;

void runGame() {
    struct timeval curr_time;
    struct timespec sleep_time;
    sleep_time.tv_sec = 0;
    sleep_time.tv_nsec = 3000000;

    uint64_t last_time;

    gettimeofday(&curr_time, NULL);
    last_time = curr_time.tv_sec * 1000000 + curr_time.tv_usec;

    input_init();

    sm_init(&game_state);
    states_init();

    sm_set_state(STATE_MENU);

    int i = 0;

    init_pair(PAIR_GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(PAIR_BLUE, COLOR_BLUE, COLOR_BLACK);
    init_pair(PAIR_CYAN, COLOR_CYAN, COLOR_BLACK);
    init_pair(PAIR_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(PAIR_RED, COLOR_RED, COLOR_BLACK);
    init_pair(PAIR_WHITE, COLOR_WHITE, COLOR_BLACK);

    init_pair(PAIR_SELECTION_OFF, COLOR_YELLOW, COLOR_BLACK);
    init_pair(PAIR_SELECTION_ON, COLOR_BLACK, COLOR_YELLOW);

    while (true) {
        gettimeofday(&curr_time, NULL);

        uint64_t curr = curr_time.tv_sec * 1000000 + curr_time.tv_usec;
        float delta = (float) (curr - last_time);
        last_time = curr;

        input_run();
        sm_run(delta);


        refresh();

        if (CURR_KEY == KEY_BACKSPACE) {
            break;
        }
        nanosleep(&sleep_time, NULL);
    }
}

int main(int argc, char **argv)
{
    srand(time(NULL));
    stdscr = initscr();

    curs_set(0);
    start_color();

    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    noecho();

    runGame();

    endwin();
    return 0;
}
