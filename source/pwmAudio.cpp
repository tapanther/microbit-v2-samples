//
// Created by jsierra on 3/8/21.
//

#include "pwmAudio.h"
#include "MicroBit.h"

Pin *speakerPin = NULL;
static uint8_t pitchVolume = 0xff;

void stopAnalogPitch() {
    speakerPin->setAnalogValue(0);
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
//        speakerPin->setDigitalValue(1);
        fiber_sleep(20);
    }
}

void playScale() {
    const int beat = 500;
    analogPitch(aAudio::Note::C5, beat);
    analogPitch(aAudio::Note::B, beat);
    analogPitch(aAudio::Note::A, beat);
    analogPitch(aAudio::Note::G, beat);
    analogPitch(aAudio::Note::F, beat);
    analogPitch(aAudio::Note::E, beat);
    analogPitch(aAudio::Note::D, beat);
    analogPitch(aAudio::Note::C, beat);
}

void audio_virtual_pin_melody()
{
    playScale();
}
