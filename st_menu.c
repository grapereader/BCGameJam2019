#include "st_menu.h"

#include <stdio.h>
#include <ncurses.h>

#include "states.h"
#include "input.h"
#include "const.h"
#include "ui.h"

static void draw_ui(float delta) {
    ui_draw_border();

    move(1, WIDTH + 2);

    char buffer[32];
    snprintf(buffer, 32, "%f", delta);

    addstr(buffer);
}

void st_menu_enter(game_t *game)
{
    clear();
}

void st_menu_run(game_t *game, float delta)
{
    draw_ui(delta);

    if (CURR_KEY == KEY_RIGHT)
    {
        sm_set_state(STATE_GAMEPLAY);
    }
}

void st_menu_exit(game_t *game)
{
}