
#include <stdio.h>

#include "pico/stdlib.h"

#include "debug_led.h"


/*
*   HARDWARE REQUIREMENTS
*   None
*/

int main() {
    stdio_init_all();

    debug_led_init();
    debug_led_set_interval(1000);

    while(1) {
        debug_led_update();

        // Check the state of the debug led timer
        printf("%d, %d, %d\n", debug_led_cdt.cooldown, debug_led_cdt.last_update, board_millis());

        sleep_ms(100);
    }

    return 0;
}