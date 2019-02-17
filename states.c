#include "states.h"

#include "statemachine.h"
#include "st_gameplay.h"
#include "st_menu.h"
#include "st_encounter.h"
#include "st_score.h"
#include "st_message.h"

void states_init()
{
    state_t *menu = sm_create_state(st_menu_enter, st_menu_run, st_menu_exit);
    state_t *gameplay = sm_create_state(st_gameplay_enter, st_gameplay_run, st_gameplay_exit);
    state_t *encounter = sm_create_state(st_encounter_enter, st_encounter_run, st_encounter_exit);
    state_t *score = sm_create_state(st_score_enter, st_score_run, st_score_exit);
    state_t *message = sm_create_state(st_message_enter, st_message_run, st_message_exit);

    sm_add_state(STATE_MENU, menu);
    sm_add_state(STATE_GAMEPLAY, gameplay);
    sm_add_state(STATE_ENCOUNTER, encounter);
    sm_add_state(STATE_SCORE, score);
    sm_add_state(STATE_MESSAGE, message);
}