#include "states.h"

#include "statemachine.h"
#include "st_gameplay.h"
#include "st_menu.h"

void states_init()
{
    state_t *menu = sm_create_state(st_menu_enter, st_menu_run, st_menu_exit);
    state_t *gameplay = sm_create_state(st_gameplay_enter, st_gameplay_run, st_gameplay_exit);

    sm_add_state(STATE_MENU, menu);
    sm_add_state(STATE_GAMEPLAY, gameplay);
}