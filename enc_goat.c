#include "enc_goat.h"

#include <ncurses.h>
#include <math.h>

#include "ui.h"
#include "encounters.h"
#include "states.h"
#include "statemachine.h"

void _enc_goat_truth(game_t *game)
{
    game->power -= 100;
    game->good_vibes += 5;
    game->bad_vibes -= 5;

    game->msg.lines[0] = "You feel a surge of mythical goat energy run through your body";
    game->msg.lines_len = 1;
    game->msg.next_state = STATE_GAMEPLAY;

    sm_set_state(STATE_MESSAGE);
}

int _enc_goat_truth_can_execute(game_t *game)
{
    return game->power >= 100;
}

void _enc_goat_pass(game_t *game)
{}

int _enc_goat_pass_can_execute(game_t *game)
{
    return 1;
}

static float render_timer;
static int render_dir = 1;
static int sprite_len = 1;
static const char *sprites[1][32];

static int curr_sprite;

void _enc_goat_render(float delta)
{
    render_timer += delta / 100000.0;
    ui_clear_sprite(60, 2, 80, 32);
    ui_draw_sprite(100 + 15 * sinf(render_timer), 2, sprites[0], 32);
}

void _enc_goat_init()
{
    render_timer = 0;

    sprites[0][0] = "      dy/  /yd";
    sprites[0][1] = "      doy//yod";
    sprites[0][2] = "    :y:+::::+:y:";
    sprites[0][3] = " :++/:........:/++:";
    sprites[0][4] = "o:::o.````````.o:::o";
    sprites[0][5] = ":+: o.````````.o :+:";
    sprites[0][6] = "    d--.````.--d";
    sprites[0][7] = "     d.-.``.-.d";
    sprites[0][8] = "     d::-..-::d";
    sprites[0][9] = "    /y..````..y/";
    sprites[0][10] = "   do+........+od";
    sprites[0][11] = "  do+....``....+od";
    sprites[0][12] = " do:-..``````..-:od";
    sprites[0][13] = "/y+:````````````:+y/";
    sprites[0][14] = "do:```.``````.```:od";
    sprites[0][15] = "/y+....``````....+od";
    sprites[0][16] = "do:..``````````..:od";
    sprites[0][17] = "do.``````````````.y/";
    sprites[0][18] = "do```````````````.y/";
    sprites[0][19] = "d-`..``````````...-d";
    sprites[0][20] = "ds::::-..`.`.-::::sd";
    sprites[0][21] = " d::-:::::::::::::d";
    sprites[0][22] = " d+o+::+o+++/::+o+d";
    sprites[0][23] = " doooo+++oo+++ooood";
    sprites[0][24] = "  moooooooooooooom";
    sprites[0][25] = "  m++++d/::/do/::m";
    sprites[0][26] = "  m/--s+    +h.``m";
    sprites[0][27] = "  m...m      m--.m";
    sprites[0][28] = "  m-/+m      mmddd";
    sprites[0][29] = "  dddmm      +mmmm";
    sprites[0][30] = "  mmmm+";
    sprites[0][31] = "";

}

encounter_t *encounter_create_goat(encounter_t *encounter)
{
    encounter->description = "You are now inside of a goat. Congratulations.";

    encounter->choices[0] = "(+5 Good Vibes, -5 Bad Vibes, -100 Power) Find absolute truth";
    encounter->callback[0] = _enc_goat_truth;
    encounter->can_execute[0] = _enc_goat_truth_can_execute;
    encounter->custom_scene_change[0] = 1;

    encounter->choices[1] = "Let enlightenment pass you by";
    encounter->callback[1] = _enc_goat_pass;
    encounter->can_execute[1] = _enc_goat_pass_can_execute;

    encounter->choice_len = 2;

    encounter->init = _enc_goat_init;
    encounter->render = _enc_goat_render;

    return encounter;
}
