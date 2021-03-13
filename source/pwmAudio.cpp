//
// Created by jsierra on 3/8/21.
//

#include "pwmAudio.h"
#include "MicroBit.h"

extern MicroBit uBit;

Pin *speakerPin = nullptr;

bool play_song = false;
bool prev_sound_enable;

static uint8_t pitchVolume = 0xff;

void enableSound()
{
    if(!uBit.audio.isPinEnabled())
    {
        uBit.audio.setPinEnabled(true);
    }
}

// Pin control as per MakeCode.
void analogPitch(int frequency, int ms) {
    if (frequency <= 0 || pitchVolume == 0) {
        speakerPin->setAnalogValue(0);
    } else {
        // I don't understand the logic of this value.
        // It is much louder on the real pin.
        int v = 1 << (pitchVolume >> 5);
        // If you flip the order of these they crash on the real pin with E030.
        speakerPin->setAnalogValue(v);
        speakerPin->setAnalogPeriodUs(1000000/frequency);
    }
    if (ms > 0) {
        fiber_sleep(ms);
        speakerPin->setAnalogValue(0);
        speakerPin->setAnalogPeriodUs(0);
        fiber_sleep(20);
    }
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
void sing()
{
    using namespace AudioTypes;

    int song_pos = 0;
    const int beat = 80;
    const int len = sizeof(song) / sizeof(song[0]);

    while(true)
    {
        if(play_song)
        {
            enableSound();
            analogPitch(song[song_pos].note,
                        beat*song[song_pos].quarter_beats);
            song_pos++;
            song_pos = song_pos >= len ? 0 : song_pos;
        }
        else
        {
            uBit.audio.setPinEnabled(false);
            fiber_sleep(200);
        }
    }
}
#pragma clang diagnostic pop