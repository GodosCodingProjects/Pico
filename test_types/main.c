
#include <stdio.h>

#include "pico/stdlib.h"

#include "types.h"

const u8 pin = 25;

/*
*   HARDWARE REQUIREMENTS
*   None
*/

int main() {
    stdio_init_all();

    gpio_init(pin);
    gpio_set_dir(pin, 1);
    gpio_put(pin, 1);

    u8 u8 = -1;
    i8 i8 = -1;
    unsigned char uc = -1;
    signed char sc = -1;
    
    u16 u16 = -1;
    i16 i16 = -1;
    unsigned short us = -1;
    signed short ss = -1;

    u32 u32 = -1;
    i32 i32 = -1;
    unsigned int ui = -1;
    signed int si = -1;

    u64 u64 = -1;
    i64 i64 = -1;
    unsigned long ul = -1;
    signed long sl = -1;

    while(1) {
        if(u8 != uc || sizeof(u8) != sizeof(uc)) {
            gpio_put(pin, 0);
            printf("Incorrect definition of the type: u8\n");
        }

        if(i8 != sc || sizeof(i8) != sizeof(sc)) {
            gpio_put(pin, 0);
            printf("Incorrect definition of the type: i8\n");
        }

        if(u16 != us || sizeof(u16) != sizeof(us)) {
            gpio_put(pin, 0);
            printf("Incorrect definition of the type: u16\n");
        }

        if(i16 != ss || sizeof(i16) != sizeof(ss)) {
            gpio_put(pin, 0);
            printf("Incorrect definition of the type: i16\n");
        }

        if(u32 != ui || sizeof(u32) != sizeof(ui)) {
            gpio_put(pin, 0);
            printf("Incorrect definition of the type: u32\n");
        }

        if(i32 != si || sizeof(i32) != sizeof(si)) {
            gpio_put(pin, 0);
            printf("Incorrect definition of the type: i32\n");
        }

        if(u64 != ul || sizeof(u64) != sizeof(ul)) {
            gpio_put(pin, 0);
            printf("Incorrect definition of the type: u64\n");
        }

        if(i64 != sl || sizeof(i64) != sizeof(sl)) {
            gpio_put(pin, 0);
            printf("Incorrect definition of the type: i64\n");
        }

        sleep_ms(500);
        gpio_put(pin, 1);
        sleep_ms(500);
    }

    return 0;
}