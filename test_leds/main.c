
#include <stdio.h>

#include "pico/stdlib.h"

#include "debug_led.h"
#include "leds.h"


/*
*   HARDWARE REQUIREMENTS
*   Pins 16 & 17 are connected to pins 14 & 15 through buttons, as a 2x2 matrix.
*   Also, connect the led strip to pin 2, a ground pin and 3V3_out.
*/

int main() {
    stdio_init_all();

    debug_led_init();
    debug_led_set_interval(1000);

    struct led_strip leds;
    leds.count = 2;
    leds.pio_pin = 2;
    leds.pio = 0;
    leds.sm = 0;
    leds_init(&leds);

    leds_update(&leds, 0);

    gps_out(16, 2);

    gps_in(14, 2);

    u8 color_mode;
    u8 old_color_mode;
    while(1) {
        color_mode = 0;

        gp_on(16);
        sleep_us(20);
        if(gp_get(14)) {
            color_mode = 1;
        }
        if(gp_get(15)) {
            color_mode = 2;
        }
        gp_off(16);

        gp_on(17);
        sleep_us(20);
        if(gp_get(14)) {
            color_mode = 3;
        }
        if(gp_get(15)) {
            color_mode = 4;
        }
        gp_off(17);

        if(color_mode != old_color_mode) {
            leds_update(&leds, color_mode);
            old_color_mode = color_mode;
        }

        debug_led_update();
    }

    return 0;
}