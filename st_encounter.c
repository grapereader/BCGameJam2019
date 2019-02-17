#include "st_encounter.h"

#include <stdlib.h>

#include "states.h"
#include "input.h"
#include "ui.h"
#include "rd_chad.h"
#include "const.h"

#include "audio.h"

int curr_choice = 0;

int max_choice = 0;

void st_encounter_enter(game_t *game)
{
    if (game->encounter == NULL)
    {
        sm_set_state(STATE_GAMEPLAY);
    }

    game->encounter->init();

    curr_choice = 0;

    audio_sound_play(SOUND_ENCOUNTER);
}

static void draw_selection_menu(game_t *game, encounter_t *encounter)
{
    attron(COLOR_PAIR(PAIR_CYAN));
    move(HEIGHT - BOTTOM_PANEL_HEIGHT + 2, 3);
    addstr(encounter->description);
    attroff(COLOR_PAIR(PAIR_CYAN));

    int offset = 0;
    for (int i = 0; i < encounter->choice_len; i++)
    {
        if (encounter->can_execute[i](game))
        {
            move(HEIGHT - BOTTOM_PANEL_HEIGHT + 4 + (2 * offset), 3);
            attron(COLOR_PAIR(offset == curr_choice ? PAIR_SELECTION_ON : PAIR_SELECTION_OFF));
            addstr(encounter->choices[i]);
            attroff(COLOR_PAIR(offset == curr_choice ? PAIR_SELECTION_ON : PAIR_SELECTION_OFF));

            offset++;
        }
    }

    max_choice = offset;
}

void st_encounter_run(game_t *game, float delta)
{
    ui_draw_debug(delta);
    ui_draw_border();

    if (CURR_KEY == KEY_DOWN)
    {
        if (curr_choice < max_choice - 1)
        {
            curr_choice++;
            audio_sound_play(SOUND_SELECT);
        }
    } else if (CURR_KEY == KEY_UP) {
        if (curr_choice > 0)
        {
            curr_choice--;
            audio_sound_play(SOUND_SELECT);
        }
    }

    draw_selection_menu(game, game->encounter);

    rd_chad(delta);

    game->encounter->render(delta);

    if (CURR_KEY == 10) {
        int offset = 0;
        int skip_scene_change = 0;
        for (int i = 0; i < game->encounter->choice_len; i++)
        {
            if (game->encounter->can_execute[i](game))
            {
                if (offset == curr_choice)
                {
                    game->encounter->callback[i](game);
                    skip_scene_change = game->encounter->custom_scene_change[i];
                    break;
                }
                offset++;
            }
        }
        if (!skip_scene_change)
        {
            sm_set_state(STATE_GAMEPLAY);
        }
    }
}

void st_encounter_exit(game_t *game)
{
}