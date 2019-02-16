#include "statemachine.h"

#include <stdlib.h>

game_t *game_state;

int *id_list;
state_t **state_list;

int state_list_length;

state_t *current_state;
int current_state_id;

state_t *sm_create_state(
    void (*fn_enter)(game_t *game),
    void (*fn_run)(game_t *game, float delta),
    void (*fn_exit)(game_t *game))
{
    state_t *state = (state_t *) malloc(sizeof(state_t));

    state->enter = fn_enter;
    state->run = fn_run;
    state->exit = fn_exit;

    return state;
}

void sm_init(game_t *game)
{
    game_state = game;

    id_list = NULL;
    state_list = NULL;

    state_list_length = 0;

    current_state = NULL;
    current_state_id = -1;
}

void state_transition(state_t *prev_state, state_t *next_state)
{
    if (prev_state != NULL)
    {
        prev_state->exit(game_state);
    }
    next_state->enter(game_state);
}

void sm_set_state(int state_id)
{
    if (state_id == current_state_id)
    {
        return;
    }

    for (int i = 0; i < state_list_length; i++)
    {
        int id = id_list[i];

        if (id == state_id) {
            state_t *state = state_list[i];

            state_transition(current_state, state);
            current_state = state;
            current_state_id = state_id;
        }
    }
}

void sm_add_state(int state_id, state_t *state)
{
    id_list = (int *) realloc(id_list, (state_list_length + 1) * sizeof(int));
    state_list = (state_t **) realloc(state_list, (state_list_length + 1) * sizeof(state_t *));

    id_list[state_list_length] = state_id;
    state_list[state_list_length] = state;

    state_list_length++;
}

void sm_run(float delta)
{
    if (current_state != NULL)
    {
        current_state->run(game_state, delta);
    }
}

int sm_dbg_getstate()
{
    return current_state_id;
}