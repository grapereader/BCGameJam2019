#include "st_message.h"

#include <ncurses.h>
#include <string.h>

#include "ui.h"
#include "const.h"
#include "input.h"

float msg_timer;

void st_message_enter(game_t *game)
{
    clear();
    msg_timer = 0;

    ui_draw_border();

    int line_height = 4;
    int height = game->msg.lines_len * line_height;

    int y = HEIGHT / 2 - (height / 2);

    attron(COLOR_PAIR(PAIR_WHITE));
    for (int i = 0; i < game->msg.lines_len; i++)
    {
        const char *line = game->msg.lines[i];
        int width = strlen(line);

        move(y + i * line_height, WIDTH / 2 - width / 2);
        addstr(line);
    }
    attroff(COLOR_PAIR(PAIR_WHITE));
}

void st_message_run(game_t *game, float delta)
{
    msg_timer += delta;

    if (msg_timer > 5 * 1000000 || CURR_KEY != ERR)
    {
        sm_set_state(game->msg.next_state);
    }
}

void st_message_exit(game_t *game)
{

}
