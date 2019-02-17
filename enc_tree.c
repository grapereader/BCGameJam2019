#include "enc_tree.h"

#include <ncurses.h>

#include "ui.h"
#include "encounters.h"

void _enc_tree_magic(game_t *game)
{
    game->good_vibes += 1;
    game->power -= 5;
}

int _enc_tree_magic_can_execute(game_t *game)
{
    return game->power > 5;
}

void _enc_tree_steal(game_t *game)
{
    game->power += 10;
    game->bad_vibes += 1;
}

int _enc_tree_steal_can_execute(game_t *game)
{
    return 1;
}

void _enc_tree_omg(game_t *game)
{
    game->good_vibes -= 1;
}

int _enc_tree_omg_can_execute(game_t *game)
{
    return 1;
}

static float render_timer;
static int render_dir = 1;
static int sprite_len = 4;
static const char *sprites[4][27];

static int alternate = 0;

static int curr_sprite;

void _enc_tree_render(float delta)
{
    render_timer += delta;

    if (render_timer > 1 * 1000000)
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
        ui_clear_sprite(65, 4, 50, 27);
    }

    ui_draw_sprite(65, 4, sprites[curr_sprite], 27);
}

void _enc_tree_init()
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

    sprites[2][0] = "";
    sprites[2][1] = "";
    sprites[2][2] = "";
    sprites[2][3] = "";
    sprites[2][4] = "";
    sprites[2][5] = "";
    sprites[2][6] = "";
    sprites[2][7] = "                              \\__";
    sprites[2][8] = "                                 \\ /            /";
    sprites[2][9] = "                                  |        ------";
    sprites[2][10] = "                              ____|        //";
    sprites[2][11] = "                            _/    \\\\ooo  //";
    sprites[2][12] = "                           /      ooooooo -----\\";
    sprites[2][13] = "                                 0ooooooo0--    \\";
    sprites[2][14] = "                              ----ooooooo        \\";
    sprites[2][15] = "                             //   //ooo\\";
    sprites[2][16] = "                                 //  \\\\  \\---\\";
    sprites[2][17] = "                                 /    ||      \\";
    sprites[2][18] = "                                 |     ||";
    sprites[2][19] = "                                /";
    sprites[2][20] = "";
    sprites[2][21] = "";
    sprites[2][22] = "";
    sprites[2][23] = "";
    sprites[2][24] = "";
    sprites[2][25] = "";
    sprites[2][26] = "";

    sprites[3][0] = "";
    sprites[3][1] = "";
    sprites[3][2] = "";
    sprites[3][3] = "";
    sprites[3][4] = "";
    sprites[3][5] = "";
    sprites[3][6] = "";
    sprites[3][7] = "                              \\*_  */*-          *";
    sprites[3][8] = "                                 \\*/            /";
    sprites[3][9] = "                                 ||        ------*-";
    sprites[3][10] = "                              ___||        //--";
    sprites[3][11] = "                            _//   \\\\ooo  // *";
    sprites[3][12] = "                        *__/*     ooooooo -----\\";
    sprites[3][13] = "                         *|      0ooooooo0--    \\";
    sprites[3][14] = "                          *   ----ooooooo        \\";
    sprites[3][15] = "                            -//  *//ooo\\";
    sprites[3][16] = "                            /*-  //  \\\\  \\---\\ -*";
    sprites[3][17] = "                          _//    /   -||-      \\";
    sprites[3][18] = "                            |    |     ||";
    sprites[3][19] = "                                /        -*";
    sprites[3][20] = "";
    sprites[3][21] = "";
    sprites[3][22] = "";
    sprites[3][23] = "";
    sprites[3][24] = "";
    sprites[3][25] = "";
    sprites[3][26] = "";
}

encounter_t *encounter_create_tree(encounter_t *encounter)
{
    encounter->description = "You find yourself slowly passing through some weird morphing starlike object. It might be a tree! What do you choose?";

    encounter->choices[0] = "(+1 Good Vibes, -5 Power) Use your magic interdimensional abilities to accellerate the tree's photosynthesis process";
    encounter->callback[0] = _enc_tree_magic;
    encounter->can_execute[0] = _enc_tree_magic_can_execute;

    encounter->choices[1] = "(+10 Power, +1 Bad Vibes) Steal water from the tree";
    encounter->callback[1] = _enc_tree_steal;
    encounter->can_execute[1] = _enc_tree_steal_can_execute;
    
    encounter->choices[2] = "(-1 Good Vibes) AAHH OMG WHAT THE FRICK?!?!";
    encounter->callback[2] = _enc_tree_omg;
    encounter->can_execute[2] = _enc_tree_omg_can_execute;

    encounter->choice_len = 3;

    encounter->init = _enc_tree_init;
    encounter->render = _enc_tree_render;

    return encounter;
}