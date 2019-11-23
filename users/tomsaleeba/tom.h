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
};

#define BASE 0
#define MDIA 1
#define NUMB 2
#define MOUS 3
#define BRKT 4
#define LFTH 5
#define SWAP 15 // swap hands (one handed mode)

#define CTL_ESC CTL_T(KC_ESC)
#define CTL_Z CTL_T(KC_Z)
#define GUI_ENT RGUI_T(KC_ENT)
#define LFT_DEL LT(LFTH, KC_DEL)
#define MED_TAB LT(MDIA, KC_TAB)

// Wrappers
#define LAYOUT_ergodox_wrapper(...)              LAYOUT_ergodox(__VA_ARGS__)
#define LAYOUT_ergotravel_grid_wrapper(...)      LAYOUT(__VA_ARGS__)
#define LAYOUT_25_wrapper(...)                   LAYOUT_split(__VA_ARGS__)

#define BASE_L1_5COL   KC_Q,     KC_W,    KC_E,     KC_R,    KC_T
#define BASE_L2_5COL   KC_A,     KC_S,    KC_D,     KC_F,    KC_G
#define BASE_L3_5COL  CTL_Z,     KC_X,    KC_C,     KC_V,    KC_B

#define BASE_R1_5COL                                                 KC_Y,     KC_U,     KC_I,     KC_O,     KC_P
#define BASE_R2_5COL                                                 KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN
#define BASE_R3_5COL                                                 KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH

#define NUMB_L1_5COL   KC_EXLM,  KC_AT,   KC_HASH,  KC_DLR,  KC_PERC
#define NUMB_L2_5COL   KC_1,     KC_2,    KC_3,     KC_4,    KC_5
#define NUMB_L3_5COL   KC_UNDS,  KC_MINS, KC_PLUS,  KC_EQL,  KC_GRV

#define NUMB_R1_5COL                                                 KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_BSLS,  KC_PIPE
#define NUMB_R2_5COL                                                 KC_6,     KC_7,     KC_8,     KC_9,     KC_0
#define NUMB_R3_5COL                                                 KC_COLN,  KC_TILD,  _______,  _______,  _______
#define NUMB_R4_4COL                                                 KC_QUOT,  KC_DQT,   KC_GT,    _______

#define MOUS_L1_5COL   _______,  _______, KC_MS_U,  _______, _______
#define MOUS_L2_5COL   _______,  KC_MS_L, KC_MS_D,  KC_MS_R, _______
#define MOUS_L3_5COL   _______,  _______, _______,  _______, _______

#define MOUS_R1_5COL                                                 _______,  _______,  KC_WH_U,  _______,  _______
#define MOUS_R2_5COL                                                 _______,  KC_BTN3,  KC_WH_D,  _______,  _______
#define MOUS_R3_5COL                                                 _______,  _______,  _______,  _______,  _______

#define LFTH_L1_5COL   C(S(KC_END)),C(S(KC_PGUP)),C(S(KC_PGDN)),C(S(KC_HOME)), _______
#define LFTH_L2_5COL   C(KC_END)   ,C(KC_PGUP),  C(KC_PGDN),    C(KC_HOME),    _______
#define LFTH_L3_5COL   KC_END,     KC_PGUP,      KC_PGDN,       KC_HOME,       _______

#define LFTH_R1_5COL                                                 _______,  _______,  _______,  _______,  _______
#define LFTH_R2_5COL                                                 _______,  _______,  _______,  _______,  _______
#define LFTH_R3_5COL                                                 _______,  _______,  _______,  _______,  _______

#endif
