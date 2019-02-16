#ifndef ST_GAMEPLAY_H
#define ST_GAMEPLAY_H

#include "statemachine.h"

void st_gameplay_enter(game_t *);
void st_gameplay_run(game_t *, float delta);
void st_gameplay_exit(game_t *);

#endif