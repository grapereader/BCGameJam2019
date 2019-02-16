#include <stdio.h>
#include <sys/time.h>
#include <time.h>

#include <ncurses.h>

#include "statemachine.h"
#include "states.h"
#include "input.h"

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

    while (true) {
        init_pair(1, COLOR_GREEN, COLOR_BLACK);
        attron(COLOR_PAIR(1));

        gettimeofday(&curr_time, NULL);

        uint64_t curr = curr_time.tv_sec * 1000000 + curr_time.tv_usec;
        float delta = (float) (curr - last_time);
        last_time = curr;

        input_run();
        sm_run(delta);

        attroff(COLOR_PAIR(1));

        refresh();

        if (CURR_KEY == KEY_BACKSPACE) {
            break;
        }
        nanosleep(&sleep_time, NULL);
    }
}

int main(int argc, char **argv)
{
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
