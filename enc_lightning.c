#include "enc_lightning.h"

#include <ncurses.h>

#include "ui.h"
#include "encounters.h"

void _enc_lightning_sap(game_t *game)
{
    game->power += 20;
}

void _enc_lightning_watch(game_t *game)
{
    game->good_vibes += 3;
}

void _enc_lightning_dance(game_t *game)
{
    game->bad_vibes -= 3;
}

void _enc_lightning_redirect(game_t *game)
{
    game->power += 100;
    game->bad_vibes += 3;
}

static float render_timer;
static int render_dir = 1;
static int sprite_len = 2;
static const char *sprites[2][27];

static int curr_sprite;

void _enc_lightning_render(float delta)
{
    render_timer += delta;

    if (render_timer > 0.2f * 1000000)
    {
        curr_sprite++;
        if (curr_sprite >= sprite_len)
        {
            curr_sprite = 0;
        }
        ui_clear_sprite(65, 4, 50, 27);
    }

    ui_draw_sprite(65, 4, sprites[curr_sprite], 27);
}

void _enc_lightning_init()
{
    curr_sprite = 0;
    render_timer = 0;

    sprites[0][0] = "";
    sprites[0][1] = "";
    sprites[0][2] = "";
    sprites[0][3] = "";
    sprites[0][4] = "";
    sprites[0][5] = "";
    sprites[0][6] = "";
    sprites[0][7] = "";
    sprites[0][8] = "";
    sprites[0][9] = "";
    sprites[0][10] = "";
    sprites[0][11] = "                                  \\";
    sprites[0][12] = "                                   \\ o /-";
    sprites[0][13] = "                                    ooo ---";
    sprites[0][14] = "                                     o";
    sprites[0][15] = "                                   /   \\";
    sprites[0][16] = "";
    sprites[0][17] = "";
    sprites[0][18] = "";
    sprites[0][19] = "";
    sprites[0][20] = "";
    sprites[0][21] = "";
    sprites[0][22] = "";
    sprites[0][23] = "";
    sprites[0][24] = "";
    sprites[0][25] = "";
    sprites[0][26] = "";

    sprites[1][0] = "";
    sprites[1][1] = "";
    sprites[1][2] = "";
    sprites[1][3] = "";
    sprites[1][4] = "";
    sprites[1][5] = "";
    sprites[1][6] = "";
    sprites[1][7] = "";
    sprites[1][8] = "";
    sprites[1][9] = "";
    sprites[1][10] = "                                __";
    sprites[1][11] = "                                  \\      /";
    sprites[1][12] = "                                   \\ooo/-";
    sprites[1][13] = "                                   ooooo----";
    sprites[1][14] = "                                    ooo";
    sprites[1][15] = "                                   /   \\";
    sprites[1][16] = "                                  /     \\";
    sprites[1][17] = "";
    sprites[1][18] = "";
    sprites[1][19] = "";
    sprites[1][20] = "";
    sprites[1][21] = "";
    sprites[1][22] = "";
    sprites[1][23] = "";
    sprites[1][24] = "";
    sprites[1][25] = "";
    sprites[1][26] = "";
}

encounter_t *encounter_create_lightning(encounter_t *encounter)
{
    encounter->description = "You are passing directly through the core of a bolt of lightning. As if getting struck by lightning wasn't already rare enough. Maybe you should take out a lottery ticket?";

    encounter->choices[0] = "(+20 Power) Sap the lightning for power";
    encounter->callback[0] = _enc_lightning_sap;

    encounter->choices[1] = "(+3 Good Vibes) Look at the pretty lights!!!";
    encounter->callback[1] = _enc_lightning_watch;
    
    encounter->choices[2] = "(-3 Bad Vibes) Dance in middle of the electric firestorm to cleanse yourself of bad vibes";
    encounter->callback[2] = _enc_lightning_dance;

    encounter->choices[3] = "(+100 Power, +3 Bad Vibes) Redirect the lightning to hit unsuspecting three-dimensional lifeforms.";
    encounter->callback[3] = _enc_lightning_redirect;

    encounter->choice_len = 4;

    encounter->init = _enc_lightning_init;
    encounter->render = _enc_lightning_render;

    return encounter;
}
