#ifndef ST_MENU_H
#define ST_MENU_H

#include "statemachine.h"

void st_menu_enter(game_t *);
void st_menu_run(game_t *, float delta);
void st_menu_exit(game_t *);

#endif