//
// Created by jsierra on 3/12/2021.
//

#include "serialHelper.h"
#include "MicroBit.h"

extern MicroBit uBit;

void loopUntilSent(const codal::ManagedString& str) {
    int rtn = uBit.serial.send(str);
    while(rtn == MICROBIT_SERIAL_IN_USE) {
        uBit.sleep(0); // let other tasks run
        rtn = uBit.serial.send(str);
    }
}
