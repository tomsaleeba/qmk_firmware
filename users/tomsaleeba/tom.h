/* Copyright 2018 Tom Saleeba
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"


// A 'transparent' key code (that falls back to the layers below it).
#ifndef ___
  #define ___ KC_TRANSPARENT
#endif

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  VRSN,
  CLROSM,
  ALT_TAB,
  FAT_ARW,
  IIFEJS,
  W_THE,
  W_CONST,
  W_AND,
};

enum layer_names {
  BASE,
  CMAK,
  QWDF,
  ARRW,
  SWAP,
  MDIA,
  NUMB,
  MOUS,
  BRKT,
  GAME,
  LFTH,  // only for ergodox
};

#define CTL_ESC  CTL_T(KC_ESC)
#define GUI_ENT  RGUI_T(KC_ENT)
#define MED_TAB  LT(MDIA, KC_TAB)
#define NMB_ENT  LT(NUMB, KC_ENT)
#define ALT_TABT ALT_T(KC_TAB)
#define CS_LEFT  LCTL(LSFT(KC_LEFT))
#define CS_RGHT  LCTL(LSFT(KC_RGHT))
#define CS_PGUP  LCTL(LSFT(KC_PGUP))
#define CS_PGDN  LCTL(LSFT(KC_PGDN))
#define C_PGUP   LCTL(KC_PGUP)
#define C_PGDN   LCTL(KC_PGDN)
#define A_PGUP   LALT(KC_PGUP)
#define A_PGDN   LALT(KC_PGDN)
#define A_LEFT   LALT(KC_LEFT)
#define A_RGHT   LALT(KC_RGHT)
#define G_LEFT   LGUI(KC_LEFT)
#define G_RGHT   LGUI(KC_RGHT)
#define AS_LEFT  LALT(LSFT(KC_LEFT))
#define AS_RGHT  LALT(LSFT(KC_RGHT))
#define AS_UP    LALT(LSFT(KC_UP))
#define AS_DOWN  LALT(LSFT(KC_DOWN))

// from quantum/rgblight_list.h
#define HSV_TOM_ORANGE 28, 255, 16
#define HSV_TOM_BLUE 170, 255, 16
#define HSV_TOM_DIM_PURPLE 210, 255, 16
#define HSV_TOM_DIM_GREEN 85, 255, 16

#define TOM_BRIGHTNESS 112
#define HSV_TOM_WHITE 0, 0, TOM_BRIGHTNESS
#define HSV_TOM_RED 0, 255, TOM_BRIGHTNESS
#define HSV_TOM_GREEN 85, 255, TOM_BRIGHTNESS
#define HSV_TOM_CYAN 128, 255, TOM_BRIGHTNESS
#define HSV_TOM_PURPLE 191, 255, TOM_BRIGHTNESS
#define HSV_TOM_YELLOW 43, 255, TOM_BRIGHTNESS

// Wrappers
#define LAYOUT_ergodox_wrapper(...)              LAYOUT_ergodox(__VA_ARGS__)
#define LAYOUT_ergotravel_grid_wrapper(...)      LAYOUT(__VA_ARGS__)
#define LAYOUT_25_wrapper(...)                   LAYOUT_split(__VA_ARGS__)
#define LAYOUT_ergoslab_wrapper(...)             LAYOUT_ergoslab(__VA_ARGS__)

#define BASE_L1_5COL   KC_Q,     KC_W,    KC_E,     KC_R,    KC_T
#define BASE_L2_5COL   KC_A,     KC_S,    KC_D,     KC_F,    KC_G
#define BASE_L3_5COL   KC_Z,     KC_X,    KC_C,     KC_V,    KC_B

#define BASE_R1_5COL                                                 KC_Y,     KC_U,     KC_I,     KC_O,     KC_P
#define BASE_R2_5COL                                                 KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN
#define BASE_R3_5COL                                                 KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH

// Colemak DHm (AKA Mod-DH Rev 1) https://colemakmods.github.io/mod-dh/keyboards.html
#define CMAK_L1_5COL   KC_Q,     KC_W,    KC_F,     KC_P,    KC_B
#define CMAK_L2_5COL   KC_A,     KC_R,    KC_S,     KC_T,    KC_G
#define CMAK_L3_5COL   KC_Z,     KC_X,    KC_C,     KC_D,    KC_V

#define CMAK_R1_5COL                                                 KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN
#define CMAK_R2_5COL                                                 KC_M,     KC_N,     KC_E,     KC_I,     KC_O
#define CMAK_R3_5COL                                                 KC_K,     KC_H,     KC_COMM,  KC_DOT,   KC_SLSH

// QWDFGY row swap https://www.reddit.com/r/Colemak/comments/jm9m3j/wow_check_out_this_layout_qwdfgy_row_swap/
#define QWDF_L1_5COL   KC_Q,     KC_W,    KC_D,     KC_F,    KC_G
#define QWDF_L2_5COL   KC_A,     KC_S,    KC_E,     KC_R,    KC_T
#define QWDF_L3_5COL   KC_Z,     KC_X,    KC_C,     KC_V,    KC_B

#define QWDF_R1_5COL                                                 KC_Y,     KC_J,     KC_K,     KC_L,     KC_SCLN
#define QWDF_R2_5COL                                                 KC_H,     KC_U,     KC_I,     KC_O,     KC_P
#define QWDF_R3_5COL                                                 KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH

#define NUMB_L1_5COL   KC_EXLM,  KC_AT,   KC_HASH,  KC_DLR,  KC_PERC
#define NUMB_L2_5COL   KC_1,     KC_2,    KC_3,     KC_4,    KC_5
#define NUMB_L3_5COL   KC_UNDS,  KC_MINS, KC_PLUS,  KC_EQL,  KC_GRV

#define NUMB_R1_5COL                                                 KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_BSLS,  KC_PIPE
#define NUMB_R2_5COL                                                 KC_6,     KC_7,     KC_8,     KC_9,     KC_0
#define NUMB_R3_5COL                                                 KC_COLN,  KC_TILD,  _______,  _______,  _______
#define NUMB_R4_4COL                                                           KC_QUOT,  KC_DQT,   KC_GT,    _______

#define MOUS_L1_5COL   _______,  _______, KC_MS_U,  _______, _______
#define MOUS_L2_5COL   _______,  KC_MS_L, KC_MS_D,  KC_MS_R, _______
#define MOUS_L3_5COL   _______,  _______, _______,  _______, _______

#define MOUS_R1_5COL                                                 _______,  _______,  KC_WH_U,  _______,  _______
#define MOUS_R2_5COL                                                 _______,  KC_BTN3,  KC_WH_D,  _______,  _______
#define MOUS_R3_5COL                                                 _______,  _______,  _______,  _______,  _______

#define BRKT_L1_5COL   _______,  _______, CS_PGUP,  _______, A_PGUP
#define BRKT_L2_5COL   _______,  CS_LEFT, CS_PGDN,  CS_RGHT, A_PGDN
#define BRKT_L3_5COL   _______,  _______, _______,  C_PGUP,  C_PGDN

#define BRKT_R1_5COL                                                 _______, KC_LCBR, KC_RCBR, _______, _______
#define BRKT_R2_5COL                                                 FAT_ARW, KC_LPRN, KC_RPRN, _______, _______
#define BRKT_R3_5COL                                                 IIFEJS,  KC_LBRC, KC_RBRC, _______, _______

#endif
