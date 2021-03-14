//
// Created by jsier on 3/12/2021.
//

#include "boot.h"
#include "MicroBit.h"
#include "serialHelper.h"
#include "graphics.h"

extern MicroBit uBit;

void boot_anim()
{
    MicroBitImage smile_img((ImageData*)smile);
    loopUntilSent("Waking up!");
//    uBit.display.scroll("HELLO WORLD!!!", 60);
    uBit.display.print(smile_img);
}