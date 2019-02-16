
#ifndef ST_ENCOUNTER_H
#define ST_ENCOUNTER_H

#include "statemachine.h"

void st_encounter_enter(game_t *);
void st_encounter_run(game_t *, float delta);
void st_encounter_exit(game_t *);

#endif