#include "ui.h"

#include <ncurses.h>

#include "const.h"
#include "statemachine.h"

#define DEBUG 0

void ui_draw_help()
{
    const char *lines[19];

    lines[0] = "Your goal is to get";
    lines[1] = "your positive energy";
    lines[2] = "over 30, so you can";
    lines[3] = "ascend from this 2D";
    lines[4] = "plane and move to more";
    lines[5] = "amicable dimensions";
    lines[6] = "";
    lines[7] = "Income is calculated";
    lines[8] = "after every encounter:";
    lines[9] = "";
    lines[10] = "Bad Vibes subtract from";
    lines[11] = "Good Vibes";
    lines[12] = "";
    lines[13] = "Good Vibes add to";
    lines[14] = "positive energy and can";
    lines[15] = "go negative.";
    lines[16] = "";
    lines[17] = "Positive energy adds";
    lines[18] = "to power.";

    int x = WIDTH - RIGHT_PANEL_WIDTH + 3;
    int y = HEIGHT - BOTTOM_PANEL_HEIGHT - 21;

    attron(COLOR_PAIR(PAIR_WHITE));
    for (int i = 0; i < 19; i++)
    {
        move(y + i, x);
        addstr(lines[i]);
    }
    attroff(COLOR_PAIR(PAIR_WHITE));
}

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
    if (!DEBUG)
    {
        return;
    }

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