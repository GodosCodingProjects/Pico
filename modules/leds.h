
#ifndef LEDS_H
#define LEDS_H

#include <stdbool.h>
#include <stdio.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2812.pio.h"

#include "types.h"

#define IS_RGBW false

struct led_strip {
    u8 count;
    u8 pio_pin;

    PIO pio; // leave at 0, unless you need to use pio 1
    u8 sm; // leave at 0, unless you need more than one sm
};

static inline void put_pixel(struct led_strip* leds, u32 pixel_grb) {
    pio_sm_put_blocking(leds->pio, leds->sm, pixel_grb << 8u);
}

static inline u32 urgb_u32(u8 r, u8 g, u8 b) {
    return
            ((u32) (r) << 8) |
            ((u32) (g) << 16) |
            (u32) (b);
}

void leds_init(struct led_strip* leds) {
    if(!leds->pio)
        leds->pio = pio0;
    u32 offset = pio_add_program(leds->pio, &ws2812_program);

    printf("leds_init: %d, %d, %d, %d\n", leds->count, leds->pio, leds->pio_pin, leds->sm);

    ws2812_program_init(leds->pio, leds->sm, offset, leds->pio_pin, 800000, IS_RGBW);
}

void leds_same_color(struct led_strip* leds, u32 pixel_grb) {
    for(u8 i = 0; i < leds->count; ++i) {
        printf("leds_same_color: %d\n", i);
        put_pixel(leds, pixel_grb);
    }
}

void leds_update(struct led_strip *leds, u8 pattern) {
    printf("leds_update: %d\n", pattern);
    switch(pattern) {
        case 0:
            leds_same_color(leds, urgb_u32(10, 0, 0));
            break;
        case 1:
            leds_same_color(leds, urgb_u32(0, 10, 0));
            break;
        case 2:
            leds_same_color(leds, urgb_u32(0, 0, 10));
            break;
        case 3:
            leds_same_color(leds, urgb_u32(6, 4, 4));
            break;
        case 4:
            leds_same_color(leds, urgb_u32(7, 2, 2));
            break;
        default:
            break;
    }
}

#endif // LEDS_H