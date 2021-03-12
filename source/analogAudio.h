//
// Created by jsierra on 3/8/21.
//

#ifndef CODAL_ANALOGAUDIO_H
#define CODAL_ANALOGAUDIO_H

#include "MicroBit.h"

namespace aAudio {
    enum Note {
        C = 262,
        CSharp = 277,
        D = 294,
        Eb = 311,
        E = 330,
        F = 349,
        FSharp = 370,
        G = 392,
        GSharp = 415,
        A = 440,
        Bb = 466,
        B = 494,
        C3 = 131,
        CSharp3 = 139,
        D3 = 147,
        Eb3 = 156,
        E3 = 165,
        F3 = 175,
        FSharp3 = 185,
        G3 = 196,
        GSharp3 = 208,
        A3 = 220,
        Bb3 = 233,
        B3 = 247,
        C4 = 262,
        CSharp4 = 277,
        D4 = 294,
        Eb4 = 311,
        E4 = 330,
        F4 = 349,
        FSharp4 = 370,
        G4 = 392,
        GSharp4 = 415,
        A4 = 440,
        Bb4 = 466,
        B4 = 494,
        C5 = 523,
        CSharp5 = 555,
        D5 = 587,
        Eb5 = 622,
        E5 = 659,
        F5 = 698,
        FSharp5 = 740,
        G5 = 784,
        GSharp5 = 831,
        A5 = 880,
        Bb5 = 932,
        B5 = 988,
    };

    struct MusicNote
    {
        aAudio::Note note;
        int quarter_beats;
    };

    // "Prerecorded songs"

    constexpr MusicNote song[] = {
        {Note::B3, 4},
        {Note::B3, 4},
        {Note::C, 4},
        {Note::D, 4},
        {Note::D, 4},
        {Note::C, 4},
        {Note::B3, 4},
        {Note::A3, 4},
        {Note::G3, 4},
        {Note::G3, 4},
        {Note::A3, 4},
        {Note::B3, 6},
        {Note::B3, 6},
        {Note::A3, 2},
        {Note::A3, 8},
        {Note::B3, 4},
        {Note::B3, 4},
        {Note::C, 4},
        {Note::D, 4},
        {Note::D, 4},
        {Note::C, 4},
        {Note::B3, 4},
        {Note::A3, 4},
        {Note::G3, 4},
        {Note::G3, 4},
        {Note::A3, 4},
        {Note::B3, 4},
        {Note::A3, 6},
        {Note::G3, 2},
        {Note::G3, 8},
        {Note::A3, 4},
        {Note::A3, 4},
        {Note::B3, 4},
        {Note::G3, 4},
        {Note::A3, 4},
        {Note::B3, 2},
        {Note::C, 2},
        {Note::B3, 4},
        {Note::G3, 4},
        {Note::A3, 4},
        {Note::B3, 2},
        {Note::C, 2},
        {Note::B3, 4},
        {Note::A3, 4},
        {Note::G3, 4},
        {Note::A3, 4},
        {Note::D3, 8},
        {Note::B3, 4},
        {Note::B3, 4},
        {Note::C, 4},
        {Note::D, 4},
        {Note::D, 4},
        {Note::C, 4},
        {Note::B3, 4},
        {Note::A3, 4},
        {Note::G3, 4},
        {Note::G3, 4},
        {Note::A3, 4},
        {Note::B3, 4},
        {Note::A3, 6},
        {Note::G3, 2},
        {Note::G3, 8}
    };

}



void stopAnalogPitch();

void analogPitch(int frequency, int ms);

void playScale();

void audio_virtual_pin_melody();


#endif // CODAL_ANALOGAUDIO_H
