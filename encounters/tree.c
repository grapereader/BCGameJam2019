#include "../encounters.h"

void _enc_tree_magic(game_t *game)
{

}

void _enc_tree_steal(game_t *game)
{

}

void _enc_tree_omg(game_t *game)
{

}

encounter_t *encounter_create_tree(encounter_t *encounter)
{
    encounter->description = "You find yourself slowly passing through some weird morphing starlike object. It might be a tree! What do you choose?";

    encounter->choices[0] = "Use your magic interdimensional abilities to accellerate the tree's photosynthesis process";
    encounter->callback[0] = _enc_tree_magic;

    encounter->choices[1] = "Steal water from the tree";
    encounter->callback[1] = _enc_tree_steal;
    
    encounter->choices[2] = "AAHH OMG WHAT THE FRICK?!?!";
    encounter->callback[2] = _enc_tree_omg;

    encounter->choice_len = 3;

    return encounter;
}