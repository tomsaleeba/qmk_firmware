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

#include "tom.h"
#include "version.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
  }
  return true;
}

void sendKeys(int keys[], int keyCount) {
  for (int i = 0; i < keyCount; ++i) {
    register_code(keys[i]);
  }
  for (int i = keyCount-1; i >= 0; --i) {
    unregister_code(keys[i]);
  }
}

void sendTwoKeys(int key1, int key2) {
  int keys[] = {key1, key2};
  sendKeys(keys, 2);
}

void sendThreeKeys(int key1, int key2, int key3) {
  int keys[] = {key1, key2, key3};
  sendKeys(keys, 3);
}

LEADER_EXTERNS();
// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    // browser back
    SEQ_ONE_KEY(KC_B) { sendTwoKeys(KC_LALT, KC_LEFT); }

    // fat arrow
    SEQ_ONE_KEY(KC_DOT) { sendThreeKeys(KC_EQL, KC_LSHIFT, KC_DOT); }

    // rofi-pass
    SEQ_ONE_KEY(KC_D) { sendThreeKeys(KC_LGUI, KC_LSHIFT, KC_D); }

    // new terminal in i3
    SEQ_ONE_KEY(KC_N) { sendTwoKeys(KC_LGUI, KC_ENT); }

    // kitty copy
    SEQ_ONE_KEY(KC_C) { sendThreeKeys(KC_LCTL, KC_LSHIFT, KC_C); }

    // kitty paste
    SEQ_ONE_KEY(KC_V) { sendThreeKeys(KC_LCTL, KC_LSHIFT, KC_V); }

    // kitty new tab
    SEQ_ONE_KEY(KC_T) { sendThreeKeys(KC_LCTL, KC_LSHIFT, KC_T); }

    // i3 "move workspace to monitor"
    // we don't need one for right. On two monitors, it's the same
    SEQ_ONE_KEY(KC_LEFT) { sendThreeKeys(KC_LCTL, KC_LGUI, KC_LEFT); }

    // i3 "toggle scratchpad"
    SEQ_ONE_KEY(KC_J) { sendTwoKeys(KC_LGUI, KC_MINS); }

    // i3 "move window to workspace"
    SEQ_ONE_KEY(KC_1) { sendThreeKeys(KC_LSHIFT, KC_LGUI, KC_1); }
    SEQ_ONE_KEY(KC_2) { sendThreeKeys(KC_LSHIFT, KC_LGUI, KC_2); }
    SEQ_ONE_KEY(KC_3) { sendThreeKeys(KC_LSHIFT, KC_LGUI, KC_3); }
    SEQ_ONE_KEY(KC_4) { sendThreeKeys(KC_LSHIFT, KC_LGUI, KC_4); }
    SEQ_ONE_KEY(KC_5) { sendThreeKeys(KC_LSHIFT, KC_LGUI, KC_5); }
    SEQ_ONE_KEY(KC_6) { sendThreeKeys(KC_LSHIFT, KC_LGUI, KC_6); }
    SEQ_ONE_KEY(KC_7) { sendThreeKeys(KC_LSHIFT, KC_LGUI, KC_7); }
    SEQ_ONE_KEY(KC_8) { sendThreeKeys(KC_LSHIFT, KC_LGUI, KC_8); }
    SEQ_ONE_KEY(KC_9) { sendThreeKeys(KC_LSHIFT, KC_LGUI, KC_9); }
    SEQ_ONE_KEY(KC_0) { sendThreeKeys(KC_LSHIFT, KC_LGUI, KC_0); }
  }
}

uint16_t get_tapping_term(uint16_t keycode) {
  switch (keycode) {
    case CTL_ESC:
    case MED_TAB:
      return 150;
    default:
      return TAPPING_TERM;
  }
}

enum combo_events {
  A_SCLN,
  DK,
  DOTCOMMA,
  FBSPC,
  FJ,
  LCLN,
  M_SLSH,
  XC,
  ZV,
  Z_SLSH,
};

const uint16_t PROGMEM a_cln_combo[] = {KC_A, KC_SCLN, COMBO_END};
const uint16_t PROGMEM dk_combo[] = {KC_D, KC_K, COMBO_END};
const uint16_t PROGMEM dotcomma_combo[] = {KC_DOT, KC_COMM, COMBO_END};
const uint16_t PROGMEM fbksp_combo[] = {KC_F, KC_BSPC, COMBO_END};
const uint16_t PROGMEM fj_combo[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM lcln_combo[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM m_slsh_combo[] = {KC_M, KC_SLSH, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM z_slsh_combo[] = {KC_Z, KC_SLSH, COMBO_END};
const uint16_t PROGMEM zv_combo[] = {KC_Z, KC_V, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [A_SCLN] = COMBO_ACTION(a_cln_combo),
  [DK] = COMBO_ACTION(dk_combo),
  [DOTCOMMA] = COMBO_ACTION(dotcomma_combo),
  [FBSPC] = COMBO_ACTION(fbksp_combo),
  [FJ] = COMBO_ACTION(fj_combo),
  [LCLN] = COMBO_ACTION(lcln_combo),
  [M_SLSH] = COMBO_ACTION(m_slsh_combo),
  [XC] = COMBO_ACTION(xc_combo),
  [ZV] = COMBO_ACTION(zv_combo),
  [Z_SLSH] = COMBO_ACTION(z_slsh_combo),
};

void process_combo_event(uint8_t combo_index, bool pressed) {
  switch(combo_index) {
    case FBSPC:
      if (pressed) {
        layer_on(BRKT);
      } else {
        layer_off(BRKT);
      }
      break;
    case LCLN:
      if (pressed) {
        layer_on(MOUS);
      } else {
        layer_off(MOUS);
      }
      break;
    case FJ:
      if (pressed) {
        tap_code16(KC_ENT);
      }
      break;
    case DK:
      if (pressed) {
        tap_code16(KC_TAB);
      }
      break;
    case ZV:
      if (pressed) {
        tap_code16(LALT(KC_TAB));
      }
      break;
    case XC:
      if (pressed) {
        tap_code16(KC_MINS);
      }
      break;
    case DOTCOMMA:
      if (pressed) {
        tap_code16(KC_QUOT);
      }
      break;
    case A_SCLN:
      if (pressed) {
        tap_code16(KC_ESC);
      }
      break;
    case Z_SLSH:
      if (pressed) {
        tap_code16(KC_BSPC);
      }
      break;
    case M_SLSH:
      if (pressed) {
        tap_code16(KC_SPC);
      }
      break;
  }
}
