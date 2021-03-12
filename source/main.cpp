#include "MicroBit.h"
#include "analogAudio.h"
#include "graphics.h"

extern Pin *speakerPin;

MicroBit uBit;

static int x_pos = 0;
static int y_pos = 0;
static bool x_mode = true;
static bool play_song = false;
static bool prev_sound_enable;

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

inline void enableSound()
{
    if(!uBit.audio.isPinEnabled())
    {
        uBit.audio.setPinEnabled(true);
    }
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
void playBeep()
{
    while (true)
    {
        fiber_wait_for_event(WAKEUP_BEEP_EVENT_ID, WAKEUP_BEEP_EVENT_VALUE);
        uBit.serial.printf("Beep!");
        prev_sound_enable = uBit.audio.isPinEnabled();
        enableSound();
        analogPitch(200, 50);
        uBit.audio.setPinEnabled(prev_sound_enable);
    }
}

void doClock()
{
    MicroBitImage clock_anim((ImageData*)clock_v2);
    int clock_anim_h = clock_v2_h;
    int clock_anim_w = clock_v2_w;

    int direction;
    int start = 0;
    int frame = 0;

    while(true)
    {
        direction = x_mode ? -clock_anim_w : clock_anim_w;
        frame += direction;
        frame = (frame > 0) ? -(clock_anim_h - clock_anim_w) :
                            ((frame < -(clock_anim_h - clock_anim_w)) ? 0 :
                                                                      frame);
        start = x_mode ? 0 : -40;
        uBit.display.print(clock_anim, 0, frame);
        fiber_sleep(50);
    }
}

void sing()
{
    using namespace aAudio;

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
    uBit.audio.setSpeakerEnabled(false);

    //MicroBitImage tick_anim((ImageData*)tick);

    uBit.init();

    uBit.serial.printf("Waking up!");

    uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, changeXMode);
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_CLICK, toggleSinging);
    uBit.messageBus.listen(MICROBIT_ID_FACE, MICROBIT_BUTTON_EVT_CLICK, changeXMode);

    create_fiber(playBeep);
    create_fiber(doClock);
    create_fiber(sing);

    release_fiber();
}
#pragma clang diagnostic pop
