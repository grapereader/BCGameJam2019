#include "st_gameplay.h"

#include <stdio.h>
#include <math.h>
#include <ncurses.h>
#include <stdlib.h>

#include "const.h"
#include "ui.h"
#include "input.h"
#include "states.h"
#include "encounters.h"

#include "rd_chad.h"

float encounter_timer = 0;
float income_timer = 0;

static void draw_ui(float delta) {
    ui_draw_border();
    ui_draw_debug(delta);

    attron(COLOR_PAIR(PAIR_GREEN));
    move(HEIGHT - BOTTOM_PANEL_HEIGHT, 1);
    hline('-', WIDTH - 2);
    move(HEIGHT - BOTTOM_PANEL_HEIGHT + 2, 2);

    move(1, WIDTH - RIGHT_PANEL_WIDTH - 2);
    vline('|', HEIGHT - BOTTOM_PANEL_HEIGHT);

    attroff(COLOR_PAIR(PAIR_GREEN));
}

void st_gameplay_enter(game_t *game)
{
    clear();
    encounter_timer = 0;
    income_timer = 0;
}

static void add_int(int val)
{
    char buffer[32];
    snprintf(buffer, 32, "%d", val);
    addstr(buffer);
}

void st_gameplay_run(game_t *game, float delta)
{
    draw_ui(delta);

    rd_chad(delta);

    attron(COLOR_PAIR(PAIR_GREEN));
    move(2, WIDTH - RIGHT_PANEL_WIDTH + 2);
    addstr("POSITIVE ENERGY");
    move(5, WIDTH - RIGHT_PANEL_WIDTH + 2);
    addstr("POWER");
    move(8, WIDTH - RIGHT_PANEL_WIDTH + 2);
    addstr("GOOD VIBES");
    move(11, WIDTH - RIGHT_PANEL_WIDTH + 2);
    addstr("BAD VIBES");
    attroff(COLOR_PAIR(PAIR_GREEN));

    attron(COLOR_PAIR(PAIR_YELLOW));
    move(3, WIDTH - RIGHT_PANEL_WIDTH + 2);
    add_int(game->energy);
    move(6, WIDTH - RIGHT_PANEL_WIDTH + 2);
    add_int(game->power);
    move(9, WIDTH - RIGHT_PANEL_WIDTH + 2);
    add_int(game->good_vibes);
    move(12, WIDTH - RIGHT_PANEL_WIDTH + 2);
    add_int(game->bad_vibes);
    attroff(COLOR_PAIR(PAIR_YELLOW));

    encounter_timer += delta;
    income_timer += delta;

    if (income_timer > 3 * 1000000)
    {
        game->energy += game->good_vibes;

        game->good_vibes -= game->bad_vibes;

        game->power += game->energy / 2;

        income_timer = 0;
    }

    if (encounter_timer > 4 * 1000000)
    {
        encounter_t *enc = get_random_encounter();
        game->encounter = enc;

        sm_set_state(STATE_ENCOUNTER);
    }

    if (CURR_KEY == KEY_BACKSPACE)
    {
        sm_set_state(STATE_MENU);
    }
}

void st_gameplay_exit(game_t *game)
{
}