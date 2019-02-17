#include "enc_goat.h"

#include <ncurses.h>

#include "ui.h"
#include "encounters.h"

void _enc_goat_truth(game_t *game)
{
    game->power -= 100;
    game->good_vibes += 5;
}

static float render_timer;
static int render_dir = 1;
static int sprite_len = 2;
static const char *sprites[2][27];

static int curr_sprite;

void _enc_goat_render(float delta)
{
}

void _enc_goat_init()
{
}

encounter_t *encounter_create_goat(encounter_t *encounter)
{
    encounter->description = "You are now inside of a goat. Congratulations.";

    encounter->choices[0] = "(+5 Good Vibes, -100 Power) Find absolute truth";
    encounter->callback[0] = _enc_goat_truth;

    encounter->choice_len = 1;

    encounter->init = _enc_goat_init;
    encounter->render = _enc_goat_render;

    return encounter;
}
