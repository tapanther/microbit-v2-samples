#include "MicroBit.h"
#include "analogAudio.h"
#include "graphics.h"

extern Pin *speakerPin;

MicroBit uBit;

static int x_pos = 0;
static int y_pos = 0;
static bool x_mode = true;
static bool play_song = false;

const int WAKEUP_BEEP_EVENT_ID = MICROBIT_ID_NOTIFY + 10;
const int WAKEUP_BEEP_EVENT_VALUE = 1;

void onPressedA(MicroBitEvent e)
{
    if (x_mode)
        x_pos--;
    else
        y_pos--;
}

void onPressedB(MicroBitEvent e)
{
    if (x_mode)
        x_pos++;
    else
        y_pos++;
}

void changeXMode(MicroBitEvent e)
{
    x_mode = !x_mode;
    MicroBitEvent(WAKEUP_BEEP_EVENT_ID, WAKEUP_BEEP_EVENT_VALUE);
}

void toggleSinging(MicroBitEvent e)
{
    play_song = !play_song;
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
void playBeep()
{
    while (true)
    {
        fiber_wait_for_event(WAKEUP_BEEP_EVENT_ID, WAKEUP_BEEP_EVENT_VALUE);
        analogPitch(200, 50);
    }
}

void doClock()
{
    MicroBitImage clock_anim((ImageData*)clock);

    int direction;
    int start = 0;
    int frame = 0;

    while(true)
    {
        direction = x_mode ? -5 : 5;
        frame += direction;
        frame = (frame > 0) ? -35 : ((frame < -35) ? 0 : frame);
        start = x_mode ? 0 : -40;
        uBit.display.print(clock_anim, 0, frame);
        fiber_sleep(100);
    }
}

void sing()
{
    using namespace aAudio;

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

    int song_pos = 0;
    const int beat = 80;
    const int len = sizeof(song) / sizeof(song[0]);

    while(true)
    {
        if(play_song)
        {
            analogPitch(song[song_pos].note,
                        beat*song[song_pos].quarter_beats);
            song_pos++;
            song_pos = song_pos >= len ? 0 : song_pos;
        }
        else
        {
            fiber_sleep(200);
        }
    }
}

#pragma clang diagnostic pop



void fireWakeupEvent(MicroBitEvent e)
{
    MicroBitEvent(WAKEUP_BEEP_EVENT_ID, WAKEUP_BEEP_EVENT_VALUE);
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
int main()
{
    speakerPin = &uBit.audio.virtualOutputPin;
    uBit.audio.setVolume(25);

    //MicroBitImage tick_anim((ImageData*)tick);

    uBit.init();

    uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, changeXMode);
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_CLICK, toggleSinging);
    uBit.messageBus.listen(MICROBIT_ID_FACE, MICROBIT_BUTTON_EVT_CLICK, changeXMode);

    create_fiber(playBeep);
    create_fiber(doClock);
    create_fiber(sing);

    release_fiber();
}
#pragma clang diagnostic pop
