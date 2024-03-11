
#include <stdio.h>

#include "pico/stdlib.h"

#include "timer.h"


/*
*   HARDWARE REQUIREMENTS
*   None
*/

int main() {
    stdio_init_all();

    gpio_init(25);
    gpio_set_dir(25, 1);
    gpio_put(25, 1);

    struct cooldown_timer s_timer;
    s_timer.cooldown = 1000;

    struct cooldown_timer no_timer;
    no_timer.cooldown = 0;


    while(1) {
        if(!update_cooldown_timer(&s_timer)) {
            printf("s_timer should have reached its next update, but indicates it hasn't\n%d, %d, %d\n", s_timer.cooldown, s_timer.last_update, board_millis());
            gpio_put(25, 0);
        }

        if(update_cooldown_timer(&no_timer)) {
            printf("no_timer should not update, but indicates it has\n");
            gpio_put(25, 0);
        }

        sleep_ms(500);
        gpio_put(25, 1);
        sleep_ms(500);
    }

    return 0;
}