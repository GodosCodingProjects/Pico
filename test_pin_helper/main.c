
#include <stdio.h>

#include "pico/stdlib.h"

#include "pin_helper.h"


/*
*   HARDWARE REQUIREMENTS
*   Connect pin 28 to VCC
*   Disconnect other pins
*/

int main() {
    stdio_init_all();

    gp_out(25);
    gp_on(25);

    gps_out(10, 6);
    gp_on(10);
    gp_off(11);
    gp_on(12);
    gp_off(13);
    gp_on(14);
    gp_off(15);

    gps_in(27, 2);

    while(1) {
        if(!gp_get(10)) {
            printf("pin 10 should be on, but indicates off\n");
            gp_off(25);
        }
        if(gp_get(11)) {
            printf("pin 11 should be off, but indicates on\n");
            gp_off(25);
        }
        if(!gp_get(12)) {
            printf("pin 12 should be on, but indicates off\n");
            gp_off(25);
        }
        if(gp_get(13)) {
            printf("pin 13 should be off, but indicates on\n");
            gp_off(25);
        }
        if(!gp_get(14)) {
            printf("pin 14 should be on, but indicates off\n");
            gp_off(25);
        }
        if(gp_get(15)) {
            printf("pin 15 should be off, but indicates on\n");
            gp_off(25);
        }

        if(gp_get(27)) {
            printf("pin 27 should not receive voltage, but indicates it does\n");
            gp_off(25);
        }
        if(!gp_get(28)) {
            printf("pin 28 should receive voltage, but indicates it doesn't\n");
            gp_off(25);
        }

        sleep_ms(500);
        gp_on(25);
        sleep_ms(500);
    }

    return 0;
}