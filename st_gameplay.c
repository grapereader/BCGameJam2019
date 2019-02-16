#include "st_gameplay.h"

#include <stdio.h>
#include <math.h>
#include <ncurses.h>
#include <stdlib.h>

#include "const.h"
#include "ui.h"
#include "input.h"
#include "states.h"

#include "rd_chad.h"

#define BOTTOM_PANEL_HEIGHT 15
#define RIGHT_PANEL_WIDTH 30

static void draw_ui(float delta) {
    ui_draw_border();
    ui_draw_debug(delta);

    attron(COLOR_PAIR(PAIR_GREEN));
    move(HEIGHT - BOTTOM_PANEL_HEIGHT, 1);
    hline('-', WIDTH - 2);
    move(HEIGHT - BOTTOM_PANEL_HEIGHT + 2, 2);
    addstr("SOME DESCRIPTION HERE");

    move(1, WIDTH - RIGHT_PANEL_WIDTH - 2);
    vline('|', HEIGHT - BOTTOM_PANEL_HEIGHT);

    move(2, WIDTH - RIGHT_PANEL_WIDTH + 2);
    addstr("STATUS");
    attroff(COLOR_PAIR(PAIR_GREEN));
}

void st_gameplay_enter(game_t *game)
{
    clear();

}

void st_gameplay_run(game_t *game, float delta)
{
    draw_ui(delta);

    rd_chad(delta);

    if (CURR_KEY == KEY_LEFT)
    {
        sm_set_state(STATE_MENU);
    }
}

void st_gameplay_exit(game_t *game)
{
}