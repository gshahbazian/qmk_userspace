#include "rgb_layers.h"
#include "layers.h"

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            for (uint8_t i = led_min; i < led_max; i++) {
                rgb_matrix_set_color(i, RGB_WHITE);
            }
            break;
        case _NUM_SYM:
            for (uint8_t i = led_min; i < led_max; i++) {
                rgb_matrix_set_color(i, RGB_GREEN);
            }
            break;
        case _NAV:
            for (uint8_t i = led_min; i < led_max; i++) {
                rgb_matrix_set_color(i, RGB_BLUE);
            }
            break;
        case _ADJUST:
            for (uint8_t i = led_min; i < led_max; i++) {
                rgb_matrix_set_color(i, RGB_RED);
            }
            break;
        default:
            break;
    }
    return false;
}
