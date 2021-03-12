//
// Created by jsier on 3/12/2021.
//

#include "boot.h"
#include "MicroBit.h"

extern MicroBit uBit;

void boot_anim()
{
    uBit.serial.printf("Waking up!");
    uBit.display.scroll("HELLO WORLD!!!", 60);
}