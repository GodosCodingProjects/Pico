
#ifndef KEY_STATE_H
#define KEY_STATE_H

#include <stdbool.h>

#include "tusb.h"

#include "types.h"

#define COLS 6
#define ROWS 7

#define DEBOUNCE_CYCLES 1

enum key_event {
    KEY_RELEASE_EVENT = -1,
    NO_EVENT,
    KEY_PRESS_EVENT,
    KEY_HOLD_EVENT
};

struct key_state {
    bool is_pressed;

    /*
    *   For falling edge, -1 or lower, for rising edge, +1 or higher
    *   The amount is equal to the number of cycles since the edge detection
    *   (for debounce purposes)
    */
    i8 edge;
};

const u8 keymap[ROWS][COLS] = {
    // Left
    { HID_KEY_F1, HID_KEY_Q, HID_KEY_W, HID_KEY_F, HID_KEY_P, HID_KEY_B },
    { HID_KEY_F2, HID_KEY_A, HID_KEY_R, HID_KEY_S, HID_KEY_T, HID_KEY_G },
    { HID_KEY_F3, HID_KEY_Z, HID_KEY_X, HID_KEY_C, HID_KEY_D, HID_KEY_V },

    // Thumbs (3 firsts -> right thumb, 3 lasts -> left thumb)
    { HID_KEY_ALT_RIGHT, HID_KEY_SPACE, HID_KEY_ENTER, HID_KEY_DELETE, HID_KEY_BACKSPACE, HID_KEY_ALT_LEFT },

    // Right (written from bottom to top)
    { HID_KEY_K, HID_KEY_H, HID_KEY_COMMA, HID_KEY_STOP, HID_KEY_SLASH, HID_KEY_F4 },
    { HID_KEY_M, HID_KEY_N, HID_KEY_E, HID_KEY_I, HID_KEY_O, HID_KEY_F5 },
    { HID_KEY_J, HID_KEY_L, HID_KEY_U, HID_KEY_Y, HID_KEY_SEMICOLON, HID_KEY_F6 }
};

static struct key_state keyboard_state[ROWS][COLS];

/*
*   Called for every key, each cycle
*   Keeps track of how many cycles passed since a rising or falling edge
*
*   Returns the key_event detected
*/
enum key_event update_key(u8 i, u8 j, bool pressed) {
    keyboard_state[i][j].is_pressed = pressed;
    
    if(keyboard_state[i][j].edge <= 0) {
        if(pressed) {
            keyboard_state[i][j].edge = 1;
        }
        else {
            --keyboard_state[i][j].edge;
        }
    }
    else if(keyboard_state[i][j].edge > 0) {
        if(pressed) {
            ++keyboard_state[i][j].edge;
        }
        else {
            keyboard_state[i][j].edge = -1;
        }
    }

    if(keyboard_state[i][j].edge == DEBOUNCE_CYCLES) {
        return KEY_PRESS_EVENT;
    }
    else if (keyboard_state[i][j].edge == -DEBOUNCE_CYCLES) {
        return KEY_RELEASE_EVENT;
    }

    return NO_EVENT;
}

#endif // KEY_STATE_H