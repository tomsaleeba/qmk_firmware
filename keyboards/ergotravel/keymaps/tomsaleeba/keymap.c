#include QMK_KEYBOARD_H
#include "tom.h"

extern keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_TAB,           _______,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    MO(MDIA),          RESET,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    CTL_ESC,           GUI_ENT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, KC_LEAD, KC_LALT, LFT_DEL,          KC_BSPC, MO(NUMB),          KC_SPC,           KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  ),

  [MDIA] = LAYOUT(
   _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,          _______,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
   _______, _______, _______, _______, _______, KC_F11,  _______,          _______,  KC_F12,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_MPLY,
   _______, _______, _______, _______, _______, KC_ENT,  _______,          _______,  _______, _______, _______, _______, KC_MUTE, _______,
   _______, _______, RESET,   VRSN,             _______, _______,          _______,  _______,          KC_VOLD, KC_VOLU, _______, _______
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

  [LFTH] = LAYOUT_ergotravel_grid_wrapper(
   _______,          LFTH_L1_5COL,                       _______,          _______,                    LFTH_R1_5COL,              _______,
   _______,          LFTH_L2_5COL,                       _______,          _______,                    LFTH_R2_5COL,              _______,
   _______,          LFTH_L3_5COL,                       _______,          _______,                    LFTH_R3_5COL,              _______,
   _______, _______, _______, _______,          _______, _______,          _______,  _______,          _______, _______, _______, _______
  ),

  [BRKT] = LAYOUT(
   _______, _______, _______, _______, _______, _______, _______,          _______,  _______, KC_LCBR, KC_RCBR, _______, _______, _______,
   _______, _______, _______, _______, _______, _______, _______,          _______,  _______, KC_LPRN, KC_RPRN, _______, _______, _______,
   _______, _______, _______, _______, _______, _______, _______,          _______,  _______, KC_LBRC, KC_RBRC, _______, _______, _______,
   _______, _______, _______, _______,          _______, _______,          _______,  KC_LT,            KC_GT,   _______, _______, _______
  )

};
