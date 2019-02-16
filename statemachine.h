#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

typedef struct game_t
{
} game_t;


typedef struct state_t
{
    void (*enter)(game_t *game);
    void (*run)(game_t *game, float delta);
    void (*exit)(game_t *game);
} state_t;

state_t *sm_create_state(
    void (*enter)(game_t *game),
    void (*run)(game_t *game, float delta),
    void (*exit)(game_t *game)
);

void sm_init(game_t *game);
void sm_set_state(int state_id);
void sm_add_state(int state_id, state_t *state);

void sm_run(float delta);

#endif