#include "encounters.h"

#include <stdlib.h>

#include "encounters/tree.c"

int encounter_list_len;
encounter_t **encounter_list;

static void add_encounter(encounter_t *encounter)
{
    encounter_list = (encounter_t **) realloc(encounter_list, (encounter_list_len + 1) * sizeof(encounter_t*));
    encounter_list[encounter_list_len++] = encounter;
}

static encounter_t *create_encounter()
{
    encounter_t *encounter = (encounter_t *) malloc(sizeof(encounter_t));
    encounter->choice_len = 0;
    return encounter;
}

void encounters_init()
{
    encounter_list = NULL;
    encounter_list_len = 0;

    add_encounter(encounter_create_tree(create_encounter()));
}

encounter_t *get_random_encounter()
{
    float r = ((float) rand()) / ((float) RAND_MAX);

    int index = (int) (r * ((float) encounter_list_len));

    if (index < encounter_list_len)
    {
        return encounter_list[index];
    }
    return NULL;
}