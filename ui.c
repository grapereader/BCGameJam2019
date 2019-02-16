#include "ui.h"

#include <ncurses.h>

#include "const.h"
#include "statemachine.h"

void ui_draw_border()
{
    attron(COLOR_PAIR(1));
    move(0, 0);
    vline('*', HEIGHT);
    hline('*', WIDTH);

    move(0, 5);
    addstr("CHAD'S WORLD V 0.1");

    move(HEIGHT, 0);
    hline('*', WIDTH);

    move(0, WIDTH);
    vline('*', HEIGHT);
    attroff(COLOR_PAIR(1));
}

void ui_draw_debug(float delta)
{
    attron(COLOR_PAIR(2));
    move(1, WIDTH + 3);

    char buffer[32];
    snprintf(buffer, 32, "FPS: %f", 1000000.0 / delta);

    addstr(buffer);

    move(2, WIDTH + 3);
    snprintf(buffer, 32, "STATE: %d", sm_dbg_getstate());
    
    addstr(buffer);
    attroff(COLOR_PAIR(2));
}

void ui_draw_sprite(int x, int y, const char **lines, int len)
{
    for (int i = 0; i < len; i++)
    {
        move(i + y, x);
        addstr(lines[i]);
    }
}

void ui_clear_sprite(int x, int y, int width, int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            move(y + i, x + j);
            addstr(" ");
        }
    }
}