#include QMK_KEYBOARD_H
#include "tom.h"

extern keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_ergotravel_grid_wrapper(
   _______,          BASE_L1_5COL,                       KC_TAB,            RGB_TOG,                   BASE_R1_5COL,              _______,
   _______,          BASE_L2_5COL,                       MO(MDIA),          RESET,                     BASE_R2_5COL,              _______,
   _______,          BASE_L3_5COL,                       MO(NUMB),          GUI_ENT,                   BASE_R3_5COL,              _______,
   _______, KC_LEAD, KC_LALT, KC_DEL,           CTL_ESC, KC_LSFT,           KC_SPC,           KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______
  ),

  [MDIA] = LAYOUT(
   _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,          _______,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  RESET,
   _______, RGB_MOD, _______, _______, _______, KC_F11,  _______,          _______,  KC_F12,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_MPLY,
   _______, RGB_VAI, _______, _______, _______, _______, _______,          _______,  _______, _______, _______, _______, KC_MUTE, _______,
   _______, RGB_VAD, RESET,   VRSN,             _______, _______,          _______,  _______,          KC_VOLD, KC_VOLU, _______, _______
  ),

  [NUMB] = LAYOUT_ergotravel_grid_wrapper(
   _______,          NUMB_L1_5COL,                       _______,          _______,                    NUMB_R1_5COL,              _______,
   _______,          NUMB_L2_5COL,                       _______,          _______,                    NUMB_R2_5COL,              _______,
   _______,          NUMB_L3_5COL,                       _______,          _______,                    NUMB_R3_5COL,              _______,
   _______, _______, _______, _______,          _______, _______,          _______,                    NUMB_R4_4COL,              _______
  ),

  [MOUS] = LAYOUT_ergotravel_grid_wrapper(
   _______,          MOUS_L1_5COL,                       _______,          _______,                    MOUS_R1_5COL,              _______,
   _______,          MOUS_L2_5COL,                       _______,          _______,                    MOUS_R2_5COL,              _______,
   _______,          MOUS_L3_5COL,                       _______,          KC_BTN2,                    MOUS_R3_5COL,              _______,
   _______, _______, _______, _______,          KC_ACL2, _______,          KC_BTN1,  _______,          _______, _______, _______, _______
  ),

  [BRKT] = LAYOUT(
   _______,          BRKT_L1_5COL,                       _______,          _______,                    BRKT_R1_5COL,              _______,
   _______,          BRKT_L2_5COL,                       _______,          _______,                    BRKT_R2_5COL,              _______,
   _______,          BRKT_L3_5COL,                       _______,          _______,                    BRKT_R3_5COL,              _______,
   _______, _______, _______, _______,          _______, _______,          _______,  KC_LT,            KC_GT,   _______, _______, _______
  )

};
