#include "rd_chad.h"

#include <ncurses.h>

#include "const.h"

#define CHAD_X 90
#define CHAD_Y 10

float chad_offset = 0.0;
float chad_timer = 0;

static void draw_chad(int x, int y)
{
    attron(COLOR_PAIR(PAIR_MAGENTA));

    const char *lines[13];

    lines[0] = "     ````````````````````     ";
    lines[1] = "    /o+++++++/::/+++++++o/    ";
    lines[2] = "  `+oo++++++/::::/++++++oo+`  ";
    lines[3] = " .ooooo+++/::::::::/+++ooooo. ";
    lines[3] = ":ooooooo+/::::::::::/+ooooooo:";
    lines[4] = ".osssssssoooooooooooossssssso.";
    lines[5] = "  :sssssssoooooooooosssssss:  ";
    lines[6] = "   `+ssssssoooooooossssss+`   ";
    lines[7] = "     -ssssssoooooossssss-     ";
    lines[8] = "      `/ssssoooooossss/`      ";
    lines[9] = "        .osssoooossso.        ";
    lines[10] = "          :sssoosss:          ";
    lines[11] = "           `+soos+`           ";
    lines[12] = "             -oo-             ";

    ui_draw_sprite(x, y, lines, 13);

    attroff(COLOR_PAIR(PAIR_MAGENTA));
}

void rd_chad_init()
{

}

void rd_chad(float delta)
{
    ui_clear_sprite(CHAD_X, CHAD_Y + ((int) chad_offset), 30, 13);

    chad_timer += (delta / 1000000);
    chad_offset = 2 * sinf(chad_timer);

    draw_chad(CHAD_X, CHAD_Y + ((int) chad_offset));
}