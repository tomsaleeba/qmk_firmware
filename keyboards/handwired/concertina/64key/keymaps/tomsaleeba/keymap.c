#include QMK_KEYBOARD_H
#include <keymap_colemak.h>
#include <sendstring_colemak.h>
#include "tom.h"

#define MO_MDIA MO(MDIA)
#define ESC_BRKT LT(BRKT, KC_ESC)
#define MO_ARRW MO(ARRW)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// FIXME might want to put escape on the same key as MO_BRKT

[BASE] = LAYOUT_64key(
                      _______, _______, _______,                          _______, _______, _______,
                      GUI_ENT, MO_MDIA, _______, _______,        _______, ALT_TABT,_______, MO_ARRW,
                               KC_LSFT, KC_LCTL, ESC_BRKT,       ALT_TAB, NMB_ENT, KC_SPC,

                      KC_W,    KC_E,    KC_R,    KC_T,           KC_Y,    KC_U,    KC_I,    KC_O,
    _______, KC_Q,    KC_S,    KC_D,    KC_F,    KC_G,           KC_H,    KC_J,    KC_K,    KC_L,    KC_P,    _______,
    _______, KC_A,    KC_X,    KC_C,    KC_V,    KC_B,           KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SCLN, _______,
    _______, KC_Z,    _______, _______, _______,                          _______, _______, _______, KC_SLSH, _______,
                               _______,                                            _______
),

[MDIA] = LAYOUT_64key(
                      _______, _______, _______,                          _______, _______, _______,
                      _______, _______, _______, RESET,          _______, _______, _______, _______,
                               _______, _______, _______,        _______, _______, _______,

                      KC_F2,   KC_F3,   KC_F4,   KC_F5,          KC_F6,   KC_F7,   KC_F8,   KC_F9,
    _______, KC_F1,   KC_PLUS, KC_MINS, KC_DOT,  KC_F11,         KC_F12,  KC_HOME, KC_PGDN, KC_PGUP, KC_F10,  _______,
    _______, KC_COMM, KC_2,    KC_3,    KC_4,    KC_5,           KC_COLN, KC_TILD, KC_VOLD, KC_VOLU, KC_END,  _______,
    _______, KC_1,    _______, _______, _______,                          _______, _______, _______, KC_MUTE, _______,
                               _______,                                            _______
),

[NUMB] = LAYOUT_64key(
                      _______, _______, _______,                          _______, _______, _______,
                      _______, _______, _______, _______,        _______, _______, _______, _______,
                               _______, _______, _______,        _______, _______, _______,

                      KC_AT,   KC_HASH, KC_DLR,  KC_PERC,        KC_CIRC, KC_AMPR, KC_ASTR, KC_BSLS,
    _______, KC_EXLM, KC_2,    KC_3,    KC_4,    KC_5,           KC_6,    KC_7,    KC_8,    KC_9,    KC_PIPE, _______,
    _______, KC_1,    KC_MINS, KC_PLUS, KC_EQL,  KC_GRV,         KC_COLN, KC_TILD, _______, _______, KC_0,    _______,
    _______, KC_UNDS, _______, _______, _______,                          _______, _______, _______, _______, _______,
                               _______,                                            _______ // FIXME add '">
),

[BRKT] = LAYOUT_64key(
                      _______, _______, _______,                          _______, _______, _______,
                      _______, _______, _______, _______,        _______, _______, _______, _______,
                               _______, _______, _______,        _______, _______, _______,

                      _______, CS_PGUP,  _______, A_PGUP,        _______, KC_LCBR, KC_RCBR, _______,
    _______, _______, CS_LEFT, CS_PGDN,  CS_RGHT, A_PGDN,        _______, KC_LPRN, KC_RPRN, _______, _______, _______,
    _______, _______, _______, _______,  C_PGUP,  C_PGDN,        _______, KC_LBRC, KC_RBRC, _______, _______, _______,
    _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______,
                               _______,                                            _______
),

[ARRW] = LAYOUT_64key(
                      _______, _______, _______,                          _______, _______, _______,
                      _______, _______, _______, _______,        _______, _______, _______, _______,
                               _______, _______, _______,        _______, _______, _______,

                      _______, _______, _______, _______,        KC_NO,   AS_LEFT, AS_DOWN, AS_UP,
    _______, _______, _______, _______, _______, _______,        KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   AS_RGHT, _______,
    _______, _______, _______, _______, _______, _______,        KC_NO,   CS_LEFT, A_LEFT,  A_RGHT,  KC_RGHT, _______,
    _______, _______, _______, _______, _______,                          _______, _______, _______, CS_RGHT, _______,
                               _______,                                            _______
),
};
