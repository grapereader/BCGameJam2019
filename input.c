#include "input.h"

void input_init() {
    CURR_KEY = 0;
}

void input_run() {
    CURR_KEY = getch();
}