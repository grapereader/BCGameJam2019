#include <stdio.h>

#include <ncurses.h>

#define WIDTH 180
#define HEIGHT 50
#define BOTTOM_PANEL_HEIGHT 15
#define RIGHT_PANEL_WIDTH 30

void drawUi() {
    move(0, 0);
    vline('*', HEIGHT);
    hline('*', WIDTH);

    move(0, 5);
    addstr("CHAD'S WORLD V 0.1");

    move(HEIGHT, 0);
    hline('*', WIDTH);

    move(0, WIDTH);
    vline('*', HEIGHT);

    move(HEIGHT - BOTTOM_PANEL_HEIGHT, 1);
    hline('-', WIDTH - 2);
    move(HEIGHT - BOTTOM_PANEL_HEIGHT + 2, 2);
    addstr("SOME DESCRIPTION HERE");

    move(1, WIDTH - RIGHT_PANEL_WIDTH - 2);
    vline('|', HEIGHT - BOTTOM_PANEL_HEIGHT);

    move(2, WIDTH - RIGHT_PANEL_WIDTH + 2);
    addstr("STATUS");
}

void runGame() {
    stdscr = initscr();

    curs_set(0);
    start_color();

    keypad(stdscr, TRUE);

    int x = 10; 
    int y = 10;

    while (true) {
        init_pair(1, COLOR_GREEN, COLOR_BLACK);
        move(y, x);
        attron(COLOR_PAIR(1));

        addstr("@@@");
        drawUi();

        attroff(COLOR_PAIR(1));

        refresh();

        chtype k = getch();

        if (k == KEY_LEFT) {
            x = x - 1;
        }

        if (k == KEY_RIGHT) {
            x = x + 1;
        }

        if (k == KEY_UP) {
            y = y - 1;
        }

        if (k == KEY_DOWN) {
            y = y + 1;
        }

        if (k == KEY_BACKSPACE) {
            break;
        }
    }

    endwin();
}

int main(int argc, char **argv)
{
    runGame();
    return 0;
}
