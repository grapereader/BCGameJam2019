#include "ui.h"

#include <ncurses.h>

#include "const.h"

void ui_draw_border()
{
    move(0, 0);
    vline('*', HEIGHT);
    hline('*', WIDTH);

    move(0, 5);
    addstr("CHAD'S WORLD V 0.1");

    move(HEIGHT, 0);
    hline('*', WIDTH);

    move(0, WIDTH);
    vline('*', HEIGHT);
}