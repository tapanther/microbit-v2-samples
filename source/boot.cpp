//
// Created by jsier on 3/12/2021.
//

#include "boot.h"
#include "MicroBit.h"
#include "serialHelper.h"

extern MicroBit uBit;

void boot_anim()
{
    loopUntilSent("Waking up!");
    uBit.display.scroll("HELLO WORLD!!!", 60);
}