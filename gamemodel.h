#ifndef GAME_MODEL_H
#define GAME_MODEL_H

struct game_t;

typedef struct encounter_t
{
    const char *description;
    int choice_len;
    const char *choices[4];
    void (*callback[4])(struct game_t *game);
    int (*can_execute[4])(struct game_t *game);
    int custom_scene_change[4];
    void (*init)();
    void (*render)(float delta);
} encounter_t;

typedef struct message_t
{
    const char *lines[10];
    int lines_len;
    int next_state;
} message_t;

typedef struct game_t
{
    encounter_t *encounter;
    message_t msg;

    int energy;
    int power;

    int good_vibes;
    int bad_vibes;

    int exit;
} game_t;

#endif