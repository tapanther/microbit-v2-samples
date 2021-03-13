/**
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

#include <cstdio>
#include "ManagedPrintf.h"
#include "MicroBit.h"

extern MicroBit uBit;

ManagedString ManagedPrintf::printf(const char *format, ...)
{
    ManagedString rtn;
    std::va_list arg;
    va_start(arg, format);
    // find how long the temp_str needs to be
    int len = vsnprintf(nullptr, 0, format, arg);
    if (len < MANAGED_PRINT_MAX_ON_STACK) {
        char temp_str[MANAGED_PRINT_MAX_ON_STACK];
        vsprintf(temp_str, format, arg);
        rtn = ManagedString(temp_str);
    } else {
        char *temp_str = new char[len + 1];
        vsprintf(temp_str, format, arg);
        rtn = ManagedString(temp_str);
        delete[] temp_str;
    }
    va_end(arg);
    return rtn;
}

ManagedString ManagedPrintf::getAddress(void *obj)
{
    if (obj == nullptr) {
        return ManagedString("NULL");
    } else {
        return printf("%p", obj);
    }
}

void ManagedPrintf::printFloat(double number, uint8_t digits)
{
    size_t n = 0;

    if (isnan(number)) return uBit.serial.printf("nan");
    if (isinf(number)) return uBit.serial.printf("inf");
    if (number > 4294967040.0) return uBit.serial.printf("ovf");  // constant determined empirically
    if (number <-4294967040.0) return uBit.serial.printf("ovf");  // constant determined empirically

    // Handle negative numbers
    if (number < 0.0)
    {
        uBit.serial.printf("-");
        number = -number;
    }

    // Round correctly so that print(1.999, 2) prints as "2.00"
    double rounding = 0.5;
    for (uint8_t i=0; i<digits; ++i)
        rounding /= 10.0;

    number += rounding;

    // Extract the integer part of the number and print it
    auto int_part = (unsigned long)number;
    double remainder = number - (double)int_part;
    uBit.serial.printf("%lu",int_part);

    // Print the decimal point, but only if there are digits beyond
    if (digits > 0) {
        uBit.serial.printf(".");
    }

    // Extract digits from the remainder one at a time
    while (digits-- > 0)
    {
        remainder *= 10.0;
        int toPrint = int(remainder);
        uBit.serial.printf("%d",toPrint);
        remainder -= toPrint;
    }
}