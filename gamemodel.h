#ifndef GAME_MODEL_H
#define GAME_MODEL_H

struct game_t;

typedef struct encounter_t
{
    const char *description;
    int choice_len;
    const char *choices[4];
    void (*callback[4])(struct game_t *game);
} encounter_t;

typedef struct game_t
{
    encounter_t *encounter;
} game_t;

#endif