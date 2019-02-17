#ifndef AUDIO_H
#define AUDIO_H

#define SOUND_BTN_UP 0
#define SOUND_BTN_DOWN 1
#define SOUND_MSG 2
#define SOUND_ENCOUNTER 3

#define SOUND_SELECT 4

#define MUSIC_LOSS 0
#define MUSIC_WIN 1
#define MUSIC_MENU 2
#define MUSIC_MENU_BROKEN 3
#define MUSIC_BG 4
#define MUSIC_BG_BROKEN 5
#define MUSIC_BG2 6

void audio_init();

void audio_sound_play(int id);

void audio_music_play(int id);
void audio_music_stop();
int audio_music_current();

#endif