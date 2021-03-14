#include "MicroBit.h"
#include "pwmAudio.h"
#include "graphics.h"
#include "boot.h"
#include "radioHelper.h"

//---------------------------------
// Externals and Globals
//---------------------------------

extern Pin *speakerPin;
extern bool prev_sound_enable;
extern bool play_song;

MicroBit uBit;

static bool x_mode = true;

const int WAKEUP_BEEP_EVENT_ID = MICROBIT_ID_NOTIFY + 10;
const int WAKEUP_BEEP_EVENT_VALUE = 1;

//---------------------------------
// Event Handlers
//---------------------------------

void changeXMode(__unused MicroBitEvent e)
{
    x_mode = !x_mode;
    MicroBitEvent(WAKEUP_BEEP_EVENT_ID, WAKEUP_BEEP_EVENT_VALUE);
}

void toggleSinging(__unused MicroBitEvent e)
{
    play_song = !play_song;
}

inline void sendString(uint8_t* send_string, int length)
{
    uBit.radio.datagram.send(send_string, length);
    uBit.sleep(100);
}

void sendButtonA(__unused MicroBitEvent e)
{
    uint8_t buttonA[] = "ButtonA\0";
    sendString(buttonA, sizeof(buttonA));
}

void sendButtonB(__unused MicroBitEvent e)
{
    uint8_t buttonB[] = "ButtonB\0";
    sendString(buttonB, sizeof(buttonB));
}

void onRadioData(__unused MicroBitEvent e)
{
    PacketBuffer recBytes = uBit.radio.datagram.recv();
    ManagedString st = getManagedStringFromPacketBuffer(recBytes);

    uBit.serial.send(st);
    uBit.display.scroll(st, 50);
}

void recalibrateCompass(__unused MicroBitEvent)
{
    uint8_t recal[] = "RECAL\0";
    sendString(recal, sizeof(recal));
    uBit.compass.calibrate();
}

//---------------------------------
// Fibers
//---------------------------------

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
void playBeep()
{
    while (true)
    {
        fiber_wait_for_event(WAKEUP_BEEP_EVENT_ID, WAKEUP_BEEP_EVENT_VALUE);
        uBit.serial.printf("Beep!\n");
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
    int frame = 0;

    while(true)
    {
        direction = x_mode ? -clock_anim_w : clock_anim_w;
        frame += direction;
        frame = (frame > 0) ? -(clock_anim_h - clock_anim_w) :
                            ((frame < -(clock_anim_h - clock_anim_w)) ? 0 :
                                                                      frame);
        uBit.display.print(clock_anim, 0, frame);
        fiber_sleep(50);
    }
}

void showCompass()
{
    int quadrant;
    float heading;

    int frame;
    MicroBitImage clock_anim((ImageData*)compass_v2);

    if (!uBit.compass.isCalibrated())
    {
        uBit.compass.calibrate();
    }

    while(true)
    {
        heading = (float) uBit.compass.heading();
        quadrant = static_cast<int>((heading - 11.25f) / 22.5f);
//        uBit.display.print(quadrant);
        frame = -5 * quadrant;
        uBit.display.print(clock_anim, 0, frame);
        fiber_sleep(10);
    }
}

#pragma clang diagnostic pop

int main()
{
    speakerPin = &uBit.audio.virtualOutputPin;
    uBit.audio.setVolume(25);
    uBit.audio.setSpeakerEnabled(false);

    uBit.init();



    int asm_out = 0;
    int asm_in = 42;

    asm("movs    %[asm_out], #21\n"
        "MY_LABEL:\n\t"
        "add     %[asm_out], %[asm_in]"
        : [asm_out] "+r" (asm_out)
        : [asm_in] "r" (asm_in)
        : "cc"
        );

    uBit.display.scroll(asm_out);

    uBit.sleep(2000);

    uBit.radio.enable();

    boot_anim();

    uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, sendButtonA);
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_CLICK, sendButtonB);
    uBit.messageBus.listen(MICROBIT_ID_FACE, MICROBIT_BUTTON_EVT_CLICK, recalibrateCompass);
    uBit.messageBus.listen(MICROBIT_ID_RADIO, MICROBIT_RADIO_EVT_DATAGRAM, onRadioData);

    create_fiber(playBeep);
    create_fiber(showCompass);
//    create_fiber(doClock);
//    create_fiber(sing);

    release_fiber();
}

