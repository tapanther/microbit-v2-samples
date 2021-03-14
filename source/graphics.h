//
// Created by jsierra on 3/9/21.
//

#ifndef CODAL_GRAPHICS_H
#define CODAL_GRAPHICS_H

const uint8_t tick[] __attribute__ ((aligned (4))) = {
    0xff, 0xff, 15, 0, 15, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

const uint8_t smile[] __attribute__ ((aligned (4))) = {
    0xff, 0xff, 5, 0, 40, 0,

    0, 1, 0, 1, 0,
    0, 1, 0, 1, 0,
    1, 0, 0, 0, 1,
    1, 1, 0, 1, 1,
    0, 1, 1, 1, 0,
};

const uint8_t clock[] __attribute__ ((aligned (4))) = {
    0xff, 0xff, 5, 0, 40, 0,

    0, 0, 1, 0, 0,
    0, 0, 1, 0, 0,
    0, 0, 1, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,

    0, 0, 0, 0, 1,
    0, 0, 0, 1, 0,
    0, 0, 1, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,

    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 1, 1, 1,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,

    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 1, 0, 0,
    0, 0, 0, 1, 0,
    0, 0, 0, 0, 1,

    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 1, 0, 0,
    0, 0, 1, 0, 0,
    0, 0, 1, 0, 0,

    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 1, 0, 0,
    0, 1, 0, 0, 0,
    1, 0, 0, 0, 0,

    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    1, 1, 1, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,

    1, 0, 0, 0, 0,
    0, 1, 0, 0, 0,
    0, 0, 1, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,

};

const uint8_t compass[] __attribute__ ((aligned (4))) = {
    0xff, 0xff, 5, 0, 40, 0,

    0, 0, 1, 0, 0,
    0, 0, 1, 0, 0,
    0, 0, 1, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,

    1, 0, 0, 0, 0,
    0, 1, 0, 0, 0,
    0, 0, 1, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,

    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    1, 1, 1, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,

    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 1, 0, 0,
    0, 1, 0, 0, 0,
    1, 0, 0, 0, 0,

    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 1, 0, 0,
    0, 0, 1, 0, 0,
    0, 0, 1, 0, 0,

    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 1, 0, 0,
    0, 0, 0, 1, 0,
    0, 0, 0, 0, 1,

    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 1, 1, 1,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,

    0, 0, 0, 0, 1,
    0, 0, 0, 1, 0,
    0, 0, 1, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,

};

const int clock_v2_w = 5;
const int clock_v2_h = 80;

const uint8_t clock_v2[] __attribute__ ((aligned (4))) = {
    0xff, 0xff, clock_v2_w, 0, clock_v2_h, 0,

    0, 0, 9, 0, 0,
    0, 0, 9, 0, 0,
    0, 0, 9, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,

    0, 0, 0, 9, 0,
    0, 0, 4, 4, 0,
    0, 0, 9, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,

    0, 0, 0, 0, 9,
    0, 0, 0, 9, 0,
    0, 0, 9, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,

    0, 0, 0, 0, 0,
    0, 0, 0, 4, 9,
    0, 0, 9, 4, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,

    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 9, 9, 9,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,

    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 9, 4, 0,
    0, 0, 0, 4, 9,
    0, 0, 0, 0, 0,

    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 9, 0, 0,
    0, 0, 0, 9, 0,
    0, 0, 0, 0, 9,

    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 9, 0, 0,
    0, 0, 4, 4, 0,
    0, 0, 0, 9, 0,

    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 9, 0, 0,
    0, 0, 9, 0, 0,
    0, 0, 9, 0, 0,

    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 9, 0, 0,
    0, 4, 4, 0, 0,
    0, 9, 0, 0, 0,

    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 9, 0, 0,
    0, 9, 0, 0, 0,
    9, 0, 0, 0, 0,

    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 4, 9, 0, 0,
    9, 4, 0, 0, 0,
    0, 0, 0, 0, 0,

    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    9, 9, 9, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,

    0, 0, 0, 0, 0,
    9, 4, 0, 0, 0,
    0, 4, 9, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,

    9, 0, 0, 0, 0,
    0, 9, 0, 0, 0,
    0, 0, 9, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,

    0, 9, 0, 0, 0,
    0, 4, 4, 0, 0,
    0, 0, 9, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0

};

const uint8_t compass_v2[] __attribute__ ((aligned (4))) = {
    0xff, 0xff, clock_v2_w, 0, clock_v2_h, 0,

    0, 0, 9, 0, 0,
    0, 0, 9, 0, 0,
    0, 0, 9, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,

    0, 9, 0, 0, 0,
    0, 4, 4, 0, 0,
    0, 0, 9, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,

    9, 0, 0, 0, 0,
    0, 9, 0, 0, 0,
    0, 0, 9, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,

    0, 0, 0, 0, 0,
    9, 4, 0, 0, 0,
    0, 4, 9, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,

    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    9, 9, 9, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,

    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 4, 9, 0, 0,
    9, 4, 0, 0, 0,
    0, 0, 0, 0, 0,

    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 9, 0, 0,
    0, 9, 0, 0, 0,
    9, 0, 0, 0, 0,

    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 9, 0, 0,
    0, 4, 4, 0, 0,
    0, 9, 0, 0, 0,

    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 9, 0, 0,
    0, 0, 9, 0, 0,
    0, 0, 9, 0, 0,

    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 9, 0, 0,
    0, 0, 4, 4, 0,
    0, 0, 0, 9, 0,

    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 9, 0, 0,
    0, 0, 0, 9, 0,
    0, 0, 0, 0, 9,

    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 9, 4, 0,
    0, 0, 0, 4, 9,
    0, 0, 0, 0, 0,

    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 9, 9, 9,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,

    0, 0, 0, 0, 0,
    0, 0, 0, 4, 9,
    0, 0, 9, 4, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,

    0, 0, 0, 0, 9,
    0, 0, 0, 9, 0,
    0, 0, 9, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,

    0, 0, 0, 9, 0,
    0, 0, 4, 4, 0,
    0, 0, 9, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,

};

#endif // CODAL_GRAPHICS_H
