#include "audio.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

static int audio_enabled;

Mix_Chunk *loaded[5];

void audio_init()
{
    audio_enabled = 0;

    if (SDL_Init(SDL_INIT_AUDIO) < 0)
    {
        return;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
    {
        return;
    }

    loaded[SOUND_BTN_UP] = Mix_LoadWAV("sounds/btn-up.wav");
    loaded[SOUND_BTN_DOWN] = Mix_LoadWAV("sounds/btn-down.wav");
    loaded[SOUND_MSG] = Mix_LoadWAV("sounds/alert.wav");
    loaded[SOUND_ENCOUNTER] = Mix_LoadWAV("sounds/encounter.wav");

    //Mix_LoadWAV("sounds/alert-long.wav");

    //Mix_Music *music = Mix_LoadMUS("test.mp3");
    //Mix_PlayMusic(music, 1);
    audio_enabled = 1;
}



void audio_play(int id)
{
    Mix_PlayChannel(0, loaded[id], 0);
}

void audio_stop(int id)
{
}