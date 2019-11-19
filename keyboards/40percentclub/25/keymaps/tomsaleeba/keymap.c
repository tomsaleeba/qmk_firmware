#include QMK_KEYBOARD_H
#include "tom.h"

extern keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_25_wrapper(
             BASE_L1_5COL,                                             BASE_R1_5COL,
             BASE_L2_5COL,                                             BASE_R2_5COL,
             BASE_L3_5COL,                                             BASE_R3_5COL,
    KC_LEAD, KC_LALT, LFT_DEL, KC_BSPC, CTL_ESC,     KC_RSFT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
    MO(MDIA),KC_TAB,  KC_LALT, KC_LSFT, MO(NUMB),    KC_RSFT, _______, _______, GUI_ENT, KC_SPC
  ),

  [MDIA] = LAYOUT_25_wrapper(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    _______, _______, _______, _______, KC_F11,      KC_F12,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,
    _______, _______, _______, _______, KC_ENT,      _______, _______, _______, _______, KC_MUTE,
    _______, RESET,   VRSN,    _______, _______,     _______, _______, KC_VOLD, KC_VOLU, _______,
    _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  ),

  [NUMB] = LAYOUT_25_wrapper(
             NUMB_L1_5COL,                                             NUMB_R1_5COL,
             NUMB_L2_5COL,                                             NUMB_R2_5COL,
             NUMB_L3_5COL,                                             NUMB_R3_5COL,
    _______, _______, _______, _______, _______,                       NUMB_R4_4COL,     _______,
    _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  ),
};
