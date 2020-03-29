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

    // restart command in terminal
    SEQ_ONE_KEY(KC_UP) {
      sendTwoKeys(KC_LCTL, KC_C);
      sendTwoKeys(KC_UP, KC_ENT);
    }

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
    case NMB_ENT:
      return 120;
    default:
      return TAPPING_TERM;
  }
}

enum combo_events {
  CMB_BACKSPACE1,
  CMB_BACKSPACE2,
  CMB_BRKT,
  CMB_DQUOT,
  CMB_END,
  CMB_ESC1,
  CMB_HOME,
  CMB_MINUS1,
  CMB_MINUS2,
  CMB_MOUS,
  CMB_PGDN,
  CMB_PGUP,
  CMB_QUOT,
  CMB_RCTL,
  CMB_TAB,
  CMB_UNDERSCORE,
  CMB_VIM_EASYMOTION1,
};

// QWERTY
const uint16_t PROGMEM d_f_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM d_k_combo[] = {KC_D, KC_K, COMBO_END};
const uint16_t PROGMEM dot_comma_combo[] = {KC_DOT, KC_COMM, COMBO_END};
const uint16_t PROGMEM f_g_combo[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM h_j_combo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM i_o_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM k_l_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM l_cln_combo[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM q_w_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM r_t_combo[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM s_d_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM v_b_combo[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM w_e_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM x_c_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM z_x_combo[] = {KC_Z, KC_X, COMBO_END};
// Colemak DH
const uint16_t PROGMEM r_s_combo[] = {KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM w_f_combo[] = {KC_W, KC_F, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [CMB_BACKSPACE1] = COMBO_ACTION(s_d_combo),
  [CMB_BACKSPACE2] = COMBO_ACTION(r_s_combo),
  [CMB_BRKT] = COMBO_ACTION(d_f_combo),
  [CMB_DQUOT] = COMBO_ACTION(dot_comma_combo),
  [CMB_END] = COMBO_ACTION(k_l_combo),
  [CMB_ESC1] = COMBO_ACTION(q_w_combo),
  [CMB_HOME] = COMBO_ACTION(h_j_combo),
  [CMB_MINUS1] = COMBO_ACTION(w_e_combo),
  [CMB_MINUS2] = COMBO_ACTION(w_f_combo),
  [CMB_MOUS] = COMBO_ACTION(l_cln_combo),
  [CMB_PGDN] = COMBO_ACTION(f_g_combo),
  [CMB_PGUP] = COMBO_ACTION(r_t_combo),
  [CMB_QUOT] = COMBO_ACTION(i_o_combo),
  [CMB_RCTL] = COMBO_ACTION(z_x_combo),
  [CMB_TAB] = COMBO_ACTION(d_k_combo),
  [CMB_UNDERSCORE] = COMBO_ACTION(x_c_combo),
  [CMB_VIM_EASYMOTION1] = COMBO_ACTION(v_b_combo),
};


void do_combo_keypress(uint16_t kc, bool pressed) {
  if (pressed) {
    register_code16(kc);
  } else {
    unregister_code16(kc);
  }

}

void process_combo_event(uint8_t combo_index, bool pressed) {
  switch(combo_index) {
    case CMB_VIM_EASYMOTION1:
      if (pressed) {
        tap_code(KC_COMM);
        tap_code(KC_COMM);
        tap_code(KC_S);
      }
      return;
    case CMB_PGDN:
      return do_combo_keypress(KC_PGDN, pressed);
    case CMB_BRKT:
      if (pressed) {
        layer_on(BRKT);
      } else {
        layer_off(BRKT);
      }
      break;
    case CMB_DQUOT:
      return do_combo_keypress(KC_DQT, pressed);
    case CMB_ESC1:
      return do_combo_keypress(KC_ESC, pressed);
    case CMB_TAB:
      return do_combo_keypress(KC_TAB, pressed);
    case CMB_PGUP:
      return do_combo_keypress(KC_PGUP, pressed);
    case CMB_HOME:
      return do_combo_keypress(KC_HOME, pressed);
    case CMB_QUOT:
      return do_combo_keypress(KC_QUOT, pressed);
    case CMB_END:
      return do_combo_keypress(KC_END, pressed);
    case CMB_MOUS:
      if (pressed) {
        layer_on(MOUS);
      } else {
        layer_off(MOUS);
      }
      break;
    case CMB_BACKSPACE1:
    case CMB_BACKSPACE2:
      return do_combo_keypress(KC_BSPC, pressed);
    case CMB_MINUS1:
    case CMB_MINUS2:
      return do_combo_keypress(KC_MINS, pressed);
    case CMB_UNDERSCORE:
      return do_combo_keypress(KC_UNDS, pressed);
    case CMB_RCTL:
      return do_combo_keypress(KC_RCTL, pressed);
  }
}