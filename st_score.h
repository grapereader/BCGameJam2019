#ifndef SCORE_H
#define SCORE_H

#include "statemachine.h"

void st_score_enter(game_t *);
void st_score_run(game_t *, float delta);
void st_score_exit(game_t *);

#endif