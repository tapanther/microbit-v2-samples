#ifndef MANAGED_PRINTF_H
#define MANAGED_PRINTF_H

/**
 * ManagedPrintf V1.2 added getAddress(void*)
 *
 * ManagedPrintf::printf(const char *format, ...) returns a ManagedString
 * !! NOTE: DO NOT use double formats  %f %F %e %E %g %G %a %A 
 * The underlying mbed compiler does not support them
 * 
 * @param format,  printf format 
 * @param ... ,  extra args for printf
 * @return ManagedString
 * 
 * Example:
 *    ManagedString mStr = ManagedPrintf::printf("loop count:%lu\n", counter);
 *    uBit.serial.send(mStr);
 * OR
 *    uBit.serial.send(ManagedPrintf::printf("loop count:%lu\n", counter));
 * 
 * (c)2016 Forward Computing and Control Pty. Ltd.
 * This code may be freely used for both private and commercial use.
 * Provide this copyright is maintained.
 */

#include <cstdarg>
#include "ManagedString.h"

class ManagedPrintf {
public:
    static codal::ManagedString printf(const char *format, ...);
    static codal::ManagedString getAddress(void* obj);
    static void printFloat(double number, uint8_t digits);
    static const int MANAGED_PRINT_MAX_ON_STACK = 60;
};
#endif
