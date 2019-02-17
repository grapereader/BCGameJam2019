#include "st_score.h"

#include <ncurses.h>
#include <string.h>

#include "states.h"
#include "const.h"
#include "ui.h"
#include "input.h"
#include "audio.h"

static float score_timer;

void st_score_enter(game_t *game)
{
    score_timer = 0;

    const char *win_line1 = "Wow. Look at you go. You've built up enough positive energy to break free from the shackles of 2D existence.";
    const char *win_line2 = "Congratulations. Enjoy your enlightenment.";

    const char *loss_line1 = "Oof. Not only did you fail to ascend, you've built up so much negative energy you'll be stuck in 2D for eternity";
    const char *loss_line2 = "Too bad. Try again!";
    clear();
    ui_draw_border();

    attron(COLOR_PAIR(PAIR_YELLOW));
    if (game->energy > 0)
    {
        move(HEIGHT / 2 - 2, WIDTH / 2 - strlen(win_line1) / 2);
        addstr(win_line1);

        move(HEIGHT / 2 + 2, WIDTH / 2 - strlen(win_line2) / 2);
        addstr(win_line2);

        audio_music_play(MUSIC_WIN);
    }
    else
    {
        move(HEIGHT / 2 - 2, WIDTH / 2 - strlen(loss_line1) / 2);
        addstr(loss_line1);

        move(HEIGHT / 2 + 2, WIDTH / 2 - strlen(loss_line2) / 2);
        addstr(loss_line2);

        audio_music_play(MUSIC_LOSS);
    }
    attroff(COLOR_PAIR(PAIR_YELLOW));
}

void st_score_run(game_t *game, float delta)
{
    score_timer += delta;

    if (score_timer > 30 * 1000000 || CURR_KEY != ERR)
    {
        sm_set_state(STATE_MENU);
    }
}

void st_score_exit(game_t *game)
{
}