#include "keypad.h"

#define _XTAL_FREQ 4000000

char Keypad_GetKey() {
    for (char row = 0; row < 4; row++) {
        PORTD = (unsigned char)(1 << row); // Set one row high at a time
        __delay_us(50);

        for (char col = 0; col < 4; col++) {
            if ((PORTD >> 4) & (1 << col)) {
                while ((PORTD >> 4) & (1 << col)); // Wait for key release
                return (row * 4 + col + 1); // Return key number
            }
        }
    }
    return 0; // No key pressed
}
