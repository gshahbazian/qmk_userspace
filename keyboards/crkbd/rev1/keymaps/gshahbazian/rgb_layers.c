#include "rgb_layers.h"
#include "layers.h"

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} layer_rgb_t;

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    static const layer_rgb_t layer_colors[] = {
        [_BASE]    = {48, 48, 48},   // soft white to keep current draw down
        [_NUM_SYM] = {0, 64, 0},     // green
        [_NAV]     = {0, 0, 64},     // blue
        [_ADJUST]  = {64, 0, 0},     // red
    };
    static const layer_rgb_t underglow_color = {48, 48, 48};

    uint8_t highest_layer = get_highest_layer(layer_state | default_layer_state);
    if (highest_layer >= ARRAY_SIZE(layer_colors)) {
        return false;
    }

    layer_rgb_t color = layer_colors[highest_layer];

    for (uint8_t index = led_min; index < led_max; ++index) {
        if (g_led_config.flags[index] & LED_FLAG_UNDERGLOW) {
            rgb_matrix_set_color(index, underglow_color.r, underglow_color.g, underglow_color.b);
            continue;
        }
        if (g_led_config.flags[index] & LED_FLAG_KEYLIGHT) {
            rgb_matrix_set_color(index, color.r, color.g, color.b);
        }
    }

    return false;
}
