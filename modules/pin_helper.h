
#ifndef PIN_HELPER_H
#define PIN_HELPER_H

#include <stdbool.h>

#include "pico/stdlib.h"

#include "types.h"

void gp_in(u8 gpio) {
    gpio_init(gpio);
    gpio_set_dir(gpio, GPIO_IN);
}

void gp_out(u8 gpio) {
    gpio_init(gpio);
    gpio_set_dir(gpio, GPIO_OUT);
}

void gps_in(u8 gpio_0, u8 n_gpio) {
    for(u8 i = 0; i < n_gpio; ++i) {
        gp_in(gpio_0 + i);
    }
}

void gps_out(u8 gpio_0, u8 n_gpio) {
    for(u8 i = 0; i < n_gpio; ++i) {
        gp_out(gpio_0 + i);
    }
}

void gp_on(u8 gpio) {
    gpio_put(gpio, true);
}

void gp_off(u8 gpio) {
    gpio_put(gpio, false);
}

bool gp_get(u8 gpio) {
    return gpio_get(gpio);
}

#endif // PIN_HELPER_H