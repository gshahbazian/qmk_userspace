/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "rgb_layers.h"
#include "layers.h"

// Key aliases for better readability in layout comments
#define ALT_A   LALT_T(KC_A)
#define CTL_S   LCTL_T(KC_S)
#define SFT_D   LSFT_T(KC_D)
#define GUI_F   LGUI_T(KC_F)
#define NAV_G   LT(_NAV, KC_G)
#define GUI_J   RGUI_T(KC_J)
#define SFT_K   RSFT_T(KC_K)
#define CTL_L   RCTL_T(KC_L)
#define ALT_SCL RALT_T(KC_SCLN)
#define NUM_SYM MO(_NUM_SYM)
#define NAV_MO  MO(_NAV)
#define ADJUST  MO(_ADJUST)
#define ALT_1   LALT_T(KC_1)
#define CTL_2   LCTL_T(KC_2)
#define SFT_3   LSFT_T(KC_3)
#define GUI_4   LGUI_T(KC_4)
#define GUI_7   RGUI_T(KC_7)
#define SFT_8   RSFT_T(KC_8)
#define CTL_9   RCTL_T(KC_9)
#define ALT_0   RALT_T(KC_0)
#define TAB_L   LGUI(LSFT(KC_LBRC))
#define TAB_R   LGUI(LSFT(KC_RBRC))
#define OSM_ALT OSM(MOD_LALT)
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_SFT OSM(MOD_LSFT)
#define OSM_GUI OSM(MOD_LGUI)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_MINS,   ALT_A,   CTL_S,   SFT_D,   GUI_F,   NAV_G,                         KC_H,   GUI_J,   SFT_K,   CTL_L, ALT_SCL, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_EQL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_HYPR, NUM_SYM,  KC_ENT,     KC_SPC,  NAV_MO,  KC_MEH
                                      //`--------------------------'  `--------------------------'

  ),

    [_NUM_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LBRC,   ALT_1,   CTL_2,   SFT_3,   GUI_4,    KC_5,                         KC_6,   GUI_7,   SFT_8,   CTL_9,   ALT_0, KC_RBRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LPRN, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_PIPE,                      KC_BSLS, KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX, KC_RPRN,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_HYPR, _______,  KC_ENT,     KC_SPC,  ADJUST,  KC_MEH
                                      //`--------------------------'  `--------------------------'
  ),

    [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT,                      XXXXXXX,  KC_END, KC_HOME, XXXXXXX, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, OSM_ALT, OSM_CTL, OSM_SFT, OSM_GUI, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU,                        TAB_L, KC_PGDN, KC_PGUP,   TAB_R, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_HYPR,  ADJUST,  KC_ENT,     KC_SPC, _______,  KC_MEH
                                      //`--------------------------'  `--------------------------'
  ),

    [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_NEXT, RM_HUED, RM_SATD, RM_VALD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_HYPR, _______,  KC_ENT,     KC_SPC, _______,  KC_MEH
                                      //`--------------------------'  `--------------------------'
  )
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT_split_3x6_3(
  'L', 'L', 'L', 'L', 'L', 'L',                    'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'L',                    'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'L',                    'R', 'R', 'R', 'R', 'R', 'R',
                      '*', '*', '*',          '*', '*', '*'
);

const uint16_t PROGMEM combo_rf[] = { KC_R, GUI_F, COMBO_END};
const uint16_t PROGMEM combo_ed[] = { KC_E, SFT_D, COMBO_END};
const uint16_t PROGMEM combo_tg[] = { KC_T, NAV_G, COMBO_END};
const uint16_t PROGMEM combo_df[] = { SFT_D, GUI_F, COMBO_END};
const uint16_t PROGMEM combo_sd[] = { CTL_S, SFT_D, COMBO_END};
const uint16_t PROGMEM combo_uj[] = { KC_U, GUI_J, COMBO_END};
const uint16_t PROGMEM combo_ik[] = { KC_I, SFT_K, COMBO_END};
const uint16_t PROGMEM combo_yh[] = { KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM combo_jk[] = { GUI_J, SFT_K, COMBO_END};
const uint16_t PROGMEM combo_kl[] = { SFT_K, CTL_L, COMBO_END};
const uint16_t PROGMEM combo_caps_word[] = { KC_MINS, KC_QUOT, COMBO_END};

// Need to keep this in sync with COMBO_COUNT in config.h
combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_rf, KC_LBRC),
    COMBO(combo_ed, KC_LPRN),
    COMBO(combo_tg, KC_LCBR),
    COMBO(combo_df, KC_ESC),
    COMBO(combo_sd, KC_TAB),
    COMBO(combo_uj, KC_RBRC),
    COMBO(combo_ik, KC_RPRN),
    COMBO(combo_yh, KC_RCBR),
    COMBO(combo_jk, KC_ESC),
    COMBO(combo_kl, KC_TAB),
    COMBO(combo_caps_word, CW_TOGG),
};

bool get_speculative_hold(uint16_t keycode, keyrecord_t* record) {
  return (
    QK_MOD_TAP_GET_MODS(keycode) &
    (MOD_LALT | MOD_LGUI | MOD_LCTL | MOD_LSFT | MOD_RALT | MOD_RGUI | MOD_RCTL | MOD_RSFT)
  ) == 0;
}
