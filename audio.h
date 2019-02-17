#ifndef AUDIO_H
#define AUDIO_H

#define SOUND_BTN_UP 0
#define SOUND_BTN_DOWN 1
#define SOUND_MSG 2
#define SOUND_ENCOUNTER 3

void audio_init();

void audio_play(int id);
void audio_stop(int id);

#endif