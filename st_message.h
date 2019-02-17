#ifndef ST_MESSAGE_H
#define ST_MESSAGE_H

#include "statemachine.h"

void st_message_enter(game_t *);
void st_message_run(game_t *, float delta);
void st_message_exit(game_t *);

#endif