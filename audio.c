#include "audio.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#define RESERVE_CHANNELS 16
static int channels;
static int curr_channel;
static int audio_enabled;
static int curr_music;

Mix_Chunk *sounds[5];
Mix_Music *music[7];

void audio_init()
{
    audio_enabled = 0;
    curr_channel = 0;

    curr_music = -1;

    if (SDL_Init(SDL_INIT_AUDIO) < 0)
    {
        return;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
    {
        return;
    }

    channels = Mix_ReserveChannels(RESERVE_CHANNELS);

    sounds[SOUND_BTN_UP] = Mix_LoadWAV("sounds/btn-up.wav");
    sounds[SOUND_BTN_DOWN] = Mix_LoadWAV("sounds/btn-down.wav");
    sounds[SOUND_MSG] = Mix_LoadWAV("sounds/alert.wav");
    sounds[SOUND_ENCOUNTER] = Mix_LoadWAV("sounds/encounter.wav");

    sounds[SOUND_SELECT] = Mix_LoadWAV("sounds/select.wav");

    music[MUSIC_LOSS] = Mix_LoadMUS("sounds/loss.wav");
    music[MUSIC_WIN] = Mix_LoadMUS("sounds/win.wav");
    music[MUSIC_MENU] = Mix_LoadMUS("sounds/menu.wav");
    music[MUSIC_MENU_BROKEN] = Mix_LoadMUS("sounds/menu-broken.wav");
    music[MUSIC_BG] = Mix_LoadMUS("sounds/bg.wav");
    music[MUSIC_BG_BROKEN] = Mix_LoadMUS("sounds/bg-broken.wav");
    music[MUSIC_BG2] = Mix_LoadMUS("sounds/bg2.wav");

    //Mix_LoadWAV("sounds/alert-long.wav");

    //Mix_Music *music = Mix_LoadMUS("test.mp3");
    //Mix_PlayMusic(music, 1);
    audio_enabled = 1;
}

void audio_sound_play(int id)
{
    if (!audio_enabled)
    {
        return;
    }

    if (curr_channel >= channels)
    {
        curr_channel = 0;
    }

    Mix_PlayChannel(curr_channel, sounds[id], 0);
    curr_channel++;
}

void audio_music_play(int id)
{
    if (!audio_enabled)
    {
        return;
    }

    Mix_PlayMusic(music[id], -1);
    curr_music = id;
}

void audio_music_stop()
{
    if (!audio_enabled)
    {
        return;
    }

    Mix_HaltMusic();
    curr_music = -1;
}

int audio_music_current()
{
    return curr_music;
}