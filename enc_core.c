#include "enc_core.h"

#include <ncurses.h>

#include "ui.h"
#include "encounters.h"
#include "const.h"

void _enc_core_protect(game_t *game)
{
    game->power -= 70;
}

int _enc_core_protect_can_execute(game_t *game)
{
    return game->power >= 70;
}

void _enc_core_maintain(game_t *game)
{
    game->bad_vibes += 2;
}

int _enc_core_maintain_can_execute(game_t *game)
{
    return 1;
}

void _enc_core_blackhole(game_t *game)
{
    game->good_vibes -= 5;
}

int _enc_core_blackhole_can_execute(game_t *game)
{
    return 1;
}

void _enc_core_sucks(game_t *game)
{
    game->energy -= 10;
}

int _enc_core_sucks_can_execute(game_t *game)
{
    return 1;
}

static float render_timer;
static int render_dir = 1;
static int sprite_len = 6;
static const char *sprites[6][15];

static int alternate = 0;

static int curr_sprite;

void _enc_core_render(float delta)
{
    render_timer += delta;

    if (render_timer > 0.2 * 1000000)
    {
        render_timer = 0;
        
        if (alternate && curr_sprite <= sprite_len - 2)
        {
            render_dir = 1;
        }

        if (curr_sprite >= sprite_len - 1)
        {
            render_dir = -1;
            alternate = 1;
        }
        curr_sprite += render_dir;
        ui_clear_sprite(84, 10, 40, 16);
    }

    attron(COLOR_PAIR(PAIR_YELLOW));
    ui_draw_sprite(84, 10, sprites[curr_sprite], 15);
    attroff(COLOR_PAIR(PAIR_YELLOW));
}

void _enc_core_init()
{
    curr_sprite = 0;
    render_timer = 0;

    sprites[0][0] = "";
    sprites[0][1] = "";
    sprites[0][2] = "";
    sprites[0][3] = "";
    sprites[0][4] = "";
    sprites[0][5] = "             :yNMMNy:";
    sprites[0][6] = "            sMMMMMMMMs";
    sprites[0][7] = "            MMMMMMMMMM";
    sprites[0][8] = "            sMMMMMMMMs";
    sprites[0][9] = "             :yNMMNy:";
    sprites[0][10] = "";
    sprites[0][11] = "";
    sprites[0][12] = "";
    sprites[0][13] = "";
    sprites[0][14] = "";

    sprites[1][0] = "";
    sprites[1][1] = "";
    sprites[1][2] = "";
    sprites[1][3] = "";
    sprites[1][4] = "            `+hNMMNh+`";
    sprites[1][5] = "           :NMMMMMMMMN:";
    sprites[1][6] = "           NMMMMMMMMMMN";
    sprites[1][7] = "           NMMMMMMMMMMN";
    sprites[1][8] = "           :NMMMMMMMMN:";
    sprites[1][9] = "            `+hNMMNh+`";
    sprites[1][10] = "";
    sprites[1][11] = "";
    sprites[1][12] = "";
    sprites[1][13] = "";
    sprites[1][14] = "";

    sprites[2][0] = "";
    sprites[2][1] = "";
    sprites[2][2] = "";
    sprites[2][3] = "            /ydNMMNdy/";
    sprites[2][4] = "          /NMMMMMMMMMMN/";
    sprites[2][5] = "         +MMMMMMMMMMMMMM+";
    sprites[2][6] = "         NMMMMMMMMMMMMMMN";
    sprites[2][7] = "         NMMMMMMMMMMMMMMN";
    sprites[2][8] = "         +MMMMMMMMMMMMMM+";
    sprites[2][9] = "          /NMMMMMMMMMMN/";
    sprites[2][10] = "            /ydNMMNdy/";
    sprites[2][11] = "";
    sprites[2][12] = "";
    sprites[2][13] = "";
    sprites[2][14] = "";

    sprites[3][0] = "";
    sprites[3][1] = "";
    sprites[3][2] = "           -ohmMMMMmho-";
    sprites[3][3] = "         /mMMMMMMMMMMMMm/";
    sprites[3][4] = "        yMMMMMMMMMMMMMMMMy";
    sprites[3][5] = "       sMMMMMMMMMMMMMMMMMMs";
    sprites[3][6] = "       MMMMMMMMMMMMMMMMMMMM";
    sprites[3][7] = "       MMMMMMMMMMMMMMMMMMMM";
    sprites[3][8] = "       sMMMMMMMMMMMMMMMMMMs";
    sprites[3][9] = "        yMMMMMMMMMMMMMMMMy";
    sprites[3][10] = "         /mMMMMMMMMMMMMm/";
    sprites[3][11] = "           -ohmMMMMmho-";
    sprites[3][12] = "";
    sprites[3][13] = "";
    sprites[3][14] = "";

    sprites[4][0] = "";
    sprites[4][1] = "          `/ydNMMMMNdy/`";
    sprites[4][2] = "        /hMMMMMMMMMMMMMMh/";
    sprites[4][3] = "      `hMMMMMMMMMMMMMMMMMMh`";
    sprites[4][4] = "     .mMMMMMMMMMMMMMMMMMMMMm.";
    sprites[4][5] = "     hMMMMMMMMMMMMMMMMMMMMMMh";
    sprites[4][6] = "     MMMMMMMMMMMMMMMMMMMMMMMM";
    sprites[4][7] = "     MMMMMMMMMMMMMMMMMMMMMMMM";
    sprites[4][8] = "     hMMMMMMMMMMMMMMMMMMMMMMh";
    sprites[4][9] = "     .mMMMMMMMMMMMMMMMMMMMMm.";
    sprites[4][10] = "      `hMMMMMMMMMMMMMMMMMMh`";
    sprites[4][11] = "        /hMMMMMMMMMMMMMMh/";
    sprites[4][12] = "          `/ydNMMMMNdy/`";
    sprites[4][13] = "";
    sprites[4][14] = "";

    sprites[5][0] = "         `:ohmNMMMMNmho:`";
    sprites[5][1] = "      `/hMMMMMMMMMMMMMMMMh/`";
    sprites[5][2] = "     +NMMMMMMMMMMMMMMMMMMMMN+";
    sprites[5][3] = "   `hMMMMMMMMMMMMMMMMMMMMMMMMh`";
    sprites[5][4] = "  `dMMMMMMMMMMMMMMMMMMMMMMMMMMd`";
    sprites[5][5] = "  sMMMMMMMMMMMMMMMMMMMMMMMMMMMMs";
    sprites[5][6] = "  NMMMMMMMMMMMMMMMMMMMMMMMMMMMMN";
    sprites[5][7] = "  MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM";
    sprites[5][8] = "  NMMMMMMMMMMMMMMMMMMMMMMMMMMMMN";
    sprites[5][9] = "  sMMMMMMMMMMMMMMMMMMMMMMMMMMMMs";
    sprites[5][10] = "  `dMMMMMMMMMMMMMMMMMMMMMMMMMMd`";
    sprites[5][11] = "   `hMMMMMMMMMMMMMMMMMMMMMMMMh`";
    sprites[5][12] = "     +NMMMMMMMMMMMMMMMMMMMMN+";
    sprites[5][13] = "      `/hMMMMMMMMMMMMMMMMh/`";
    sprites[5][14] = "         `:ohmNMMMMNmho:`";
}

encounter_t *encounter_create_core(encounter_t *encounter)
{
    encounter->description = "You are descending through the planet's core. Ouch!";

    encounter->choices[0] = "(-70 Power) Protect your positive energy at all cost!";
    encounter->callback[0] = _enc_core_protect;
    encounter->can_execute[0] = _enc_core_protect_can_execute;

    encounter->choices[1] = "(+2 Bad Vibes) Eek. Maintain your energy, but damn, it's sure getting hot in here.";
    encounter->callback[1] = _enc_core_maintain;
    encounter->can_execute[1] = _enc_core_maintain_can_execute;
    
    encounter->choices[2] = "(-5 Good Vibes) Well, at least it's not a black hole.";
    encounter->callback[2] = _enc_core_blackhole;
    encounter->can_execute[2] = _enc_core_blackhole_can_execute;

    encounter->choices[3] = "(-10 Positive Energy) Ugh. This sucks. Blehh.";
    encounter->callback[3] = _enc_core_sucks;
    encounter->can_execute[3] = _enc_core_sucks_can_execute;

    encounter->choice_len = 4;

    encounter->init = _enc_core_init;
    encounter->render = _enc_core_render;

    return encounter;
}