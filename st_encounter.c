#include "st_encounter.h"

#include <stdlib.h>

#include "states.h"
#include "input.h"
#include "ui.h"
#include "rd_chad.h"
#include "const.h"

int curr_choice = 0;

void st_encounter_enter(game_t *game)
{
    if (game->encounter == NULL)
    {
        sm_set_state(STATE_GAMEPLAY);
    }

    curr_choice = 0;
}

static void draw_selection_menu(encounter_t *encounter)
{
    attron(COLOR_PAIR(PAIR_CYAN));
    move(HEIGHT - BOTTOM_PANEL_HEIGHT + 2, 3);
    addstr(encounter->description);
    attroff(COLOR_PAIR(PAIR_CYAN));

    for (int i = 0; i < encounter->choice_len; i++)
    {
        move(HEIGHT - BOTTOM_PANEL_HEIGHT + 4 + (2 * i), 3);
        attron(COLOR_PAIR(i == curr_choice ? PAIR_SELECTION_ON : PAIR_SELECTION_OFF));
        addstr(encounter->choices[i]);
        attroff(COLOR_PAIR(i == curr_choice ? PAIR_SELECTION_ON : PAIR_SELECTION_OFF));
    }
}

void st_encounter_run(game_t *game, float delta)
{
    ui_draw_debug(delta);
    ui_draw_border();

    if (CURR_KEY == KEY_DOWN)
    {
        if (curr_choice < game->encounter->choice_len - 1)
        {
            curr_choice++;
        }
    } else if (CURR_KEY == KEY_UP) {
        if (curr_choice > 0)
        {
            curr_choice--;
        }
    }

    if (CURR_KEY == KEY_RIGHT) {
        game->encounter->callback[curr_choice](game);
        sm_set_state(STATE_GAMEPLAY);
    }

    draw_selection_menu(game->encounter);

    rd_chad(delta);
}

void st_encounter_exit(game_t *game)
{
}