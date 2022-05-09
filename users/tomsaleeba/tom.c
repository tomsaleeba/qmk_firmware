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

void clear_oneshots(void) {
  clear_oneshot_locked_mods();
  clear_oneshot_mods();
  unregister_mods(get_mods());
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
    case ALT_TAB:
      if (record->event.pressed) {
        register_code(KC_LALT);
        register_code(KC_TAB);
        unregister_code(KC_TAB);
        unregister_code(KC_LALT);
      }
      return false;
    case CLROSM:
      if (record->event.pressed) {
        clear_oneshots();
      }
      return false;
    case FAT_ARW:
      if (record->event.pressed) {
        SEND_STRING("() => {}");
        tap_code(KC_LEFT);
      }
      return false;
    case IIFEJS:
      if (record->event.pressed) {
        SEND_STRING("(() => {})()");
        tap_code(KC_LEFT);
        tap_code(KC_LEFT);
        tap_code(KC_LEFT);
        tap_code(KC_LEFT);
      }
      return false;
    // tried to hook KC_ESC like users/dshields/dshields.c but the locked mods
    // weren't unlocking. Ended up solving it in the combo handler for Esc lower.
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

    // emoji
    SEQ_ONE_KEY(KC_F) { send_unicode_string("(╯°□°)╯︵ ┻━┻"); }
    SEQ_TWO_KEYS(KC_E, KC_A) { send_unicode_string("🍆"); }
    SEQ_TWO_KEYS(KC_E, KC_C) { send_unicode_string("✅"); }
    SEQ_TWO_KEYS(KC_E, KC_D) { send_unicode_string("👎"); }
    SEQ_TWO_KEYS(KC_E, KC_E) { send_unicode_string("🤯"); }
    SEQ_TWO_KEYS(KC_E, KC_F) { send_unicode_string("🤦"); }
    SEQ_TWO_KEYS(KC_E, KC_G) { send_unicode_string("😬"); }
    SEQ_TWO_KEYS(KC_E, KC_H) { send_unicode_string("😍"); }
    SEQ_TWO_KEYS(KC_E, KC_L) { send_unicode_string("🥺"); }
    SEQ_TWO_KEYS(KC_E, KC_M) { send_unicode_string("💪"); }
    SEQ_TWO_KEYS(KC_E, KC_N) { send_unicode_string("😁"); }
    SEQ_TWO_KEYS(KC_E, KC_O) { send_unicode_string("👌"); }
    SEQ_TWO_KEYS(KC_E, KC_P) { send_unicode_string("💩"); }
    SEQ_TWO_KEYS(KC_E, KC_S) { send_unicode_string("🤷"); }
    SEQ_TWO_KEYS(KC_E, KC_T) { send_unicode_string("🤔"); }
    SEQ_TWO_KEYS(KC_E, KC_U) { send_unicode_string("👍"); }
  }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
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
  CMB_BACKSPACE_Q,
  CMB_BACKSPACE_Q2,
  CMB_BACKSPACE_C,
  CMB_BRKT_C,
  CMB_BRKT_Q,
  CMB_BRKT_Q2,
  CMB_DQUOT,
  CMB_END_C,
  CMB_END_Q_OR_QUOT_Q2,
  CMB_ESC,
  CMB_HOME_C,
  CMB_HOME_Q,
  CMB_HOME_Q2,
  CMB_MINUS_Q,
  CMB_MINUS_Q2,
  CMB_MINUS_C,
  CMB_MOUS_Q,
  CMB_MOUS_Q2,
  CMB_PGDN_Q_OR_PGUP_Q2,
  CMB_PGUP_Q_OR_PGDN_Q2,
  CMB_QUOT_C,
  CMB_QUOT_Q_OR_MOUS_C_OR_END_Q2,
  CMB_RCTL,
  CMB_UNDERSCORE,
  CMB_VIM_EASYMOTION_Q,
};

// common
const uint16_t PROGMEM i_o_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM k_l_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM f_g_combo[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM r_t_combo[] = {KC_R, KC_T, COMBO_END};
// QWERTY
const uint16_t PROGMEM d_f_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM dot_comma_combo[] = {KC_DOT, KC_COMM, COMBO_END};
const uint16_t PROGMEM h_j_combo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM l_cln_combo[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM q_w_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM s_d_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM v_b_combo[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM w_e_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM x_c_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM z_x_combo[] = {KC_Z, KC_X, COMBO_END};
// Colemak DHm
// const uint16_t PROGMEM e_i_combo[] = {KC_E, KC_I, COMBO_END};
// const uint16_t PROGMEM m_n_combo[] = {KC_M, KC_N, COMBO_END};
// const uint16_t PROGMEM r_s_combo[] = {KC_R, KC_S, COMBO_END};
// const uint16_t PROGMEM s_t_combo[] = {KC_S, KC_T, COMBO_END};
// const uint16_t PROGMEM u_y_combo[] = {KC_U, KC_Y, COMBO_END};
// const uint16_t PROGMEM w_f_combo[] = {KC_W, KC_F, COMBO_END};
// QWDFGY
// const uint16_t PROGMEM w_d_combo[] = {KC_W, KC_D, COMBO_END};
// const uint16_t PROGMEM s_e_combo[] = {KC_S, KC_E, COMBO_END};
// const uint16_t PROGMEM o_p_combo[] = {KC_O, KC_P, COMBO_END};
// const uint16_t PROGMEM e_r_combo[] = {KC_E, KC_R, COMBO_END};
// const uint16_t PROGMEM h_u_combo[] = {KC_H, KC_U, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  // [CMB_BACKSPACE_C] = COMBO_ACTION(r_s_combo),
  [CMB_BACKSPACE_Q] = COMBO_ACTION(s_d_combo),
  // [CMB_BACKSPACE_Q2] = COMBO_ACTION(s_e_combo),
  // [CMB_BRKT_C] = COMBO_ACTION(s_t_combo),
  [CMB_BRKT_Q] = COMBO_ACTION(d_f_combo),
  // [CMB_BRKT_Q2] = COMBO_ACTION(e_r_combo),
  [CMB_DQUOT] = COMBO_ACTION(dot_comma_combo),
  // [CMB_END_C] = COMBO_ACTION(e_i_combo),
  [CMB_END_Q_OR_QUOT_Q2] = COMBO_ACTION(k_l_combo),
  [CMB_ESC] = COMBO_ACTION(q_w_combo),
  // [CMB_HOME_C] = COMBO_ACTION(m_n_combo),
  [CMB_HOME_Q] = COMBO_ACTION(h_j_combo),
  // [CMB_HOME_Q2] = COMBO_ACTION(h_u_combo),
  // [CMB_MINUS_C] = COMBO_ACTION(w_f_combo),
  [CMB_MINUS_Q] = COMBO_ACTION(w_e_combo),
  // [CMB_MINUS_Q2] = COMBO_ACTION(w_d_combo),
  [CMB_MOUS_Q] = COMBO_ACTION(l_cln_combo),
  // [CMB_MOUS_Q2] = COMBO_ACTION(o_p_combo),
  [CMB_PGDN_Q_OR_PGUP_Q2] = COMBO_ACTION(f_g_combo),
  [CMB_PGUP_Q_OR_PGDN_Q2] = COMBO_ACTION(r_t_combo),
  // [CMB_QUOT_C] = COMBO_ACTION(u_y_combo),
  [CMB_QUOT_Q_OR_MOUS_C_OR_END_Q2] = COMBO_ACTION(i_o_combo),
  [CMB_RCTL] = COMBO_ACTION(z_x_combo),
  [CMB_UNDERSCORE] = COMBO_ACTION(x_c_combo),
  [CMB_VIM_EASYMOTION_Q] = COMBO_ACTION(v_b_combo),
};


void do_combo_keypress(uint16_t kc, bool pressed) {
  if (pressed) {
    register_code16(kc);
  } else {
    unregister_code16(kc);
  }
}

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch (combo_index) {
    case CMB_DQUOT:
      return do_combo_keypress(KC_DQT, pressed);
    case CMB_ESC:
      if (get_oneshot_locked_mods() ||
          (get_oneshot_mods() && !has_oneshot_mods_timed_out())) {
        return clear_oneshots();
      }
      return do_combo_keypress(KC_ESC, pressed);
    case CMB_UNDERSCORE:
      return do_combo_keypress(KC_UNDS, pressed);
    case CMB_RCTL:
      return do_combo_keypress(KC_RCTL, pressed);
  }
  // bool isColemak = layer_state_is(CMAK);
  // if (isColemak) {
  //   switch(combo_index) {
  //     case CMB_BRKT_C:
  //       if (pressed) {
  //         layer_on(BRKT);
  //       } else {
  //         layer_off(BRKT);
  //       }
  //       break;
  //     case CMB_HOME_C:
  //       return do_combo_keypress(KC_HOME, pressed);
  //     case CMB_QUOT_Q_OR_MOUS_C_OR_END_Q2:
  //       if (pressed) {
  //         layer_invert(MOUS);
  //       }
  //       break;
  //     case CMB_QUOT_C:
  //       return do_combo_keypress(KC_QUOT, pressed);
  //     case CMB_END_C:
  //       return do_combo_keypress(KC_END, pressed);
  //     case CMB_BACKSPACE_C:
  //       return do_combo_keypress(KC_BSPC, pressed);
  //     case CMB_MINUS_C:
  //       return do_combo_keypress(KC_MINS, pressed);
  //   }
  //   return;
  // }
  // bool isQwdfgy = layer_state_is(QWDF);
  // if (isQwdfgy) {
  //   switch(combo_index) {
  //     // QWDFGY combos
  //   case CMB_PGDN_Q_OR_PGUP_Q2:
  //     return do_combo_keypress(KC_PGUP, pressed);
  //   case CMB_BRKT_Q2:
  //     if (pressed) {
  //       layer_on(BRKT);
  //     } else {
  //       layer_off(BRKT);
  //     }
  //     break;
  //   case CMB_PGUP_Q_OR_PGDN_Q2:
  //     return do_combo_keypress(KC_PGDN, pressed);
  //   case CMB_HOME_Q2:
  //     return do_combo_keypress(KC_HOME, pressed);
  //   case CMB_QUOT_Q_OR_MOUS_C_OR_END_Q2:
  //     return do_combo_keypress(KC_END, pressed);
  //   case CMB_END_Q_OR_QUOT_Q2:
  //     return do_combo_keypress(KC_QUOT, pressed);
  //   case CMB_MOUS_Q2:
  //     if (pressed) {
  //       layer_invert(MOUS);
  //     }
  //     break;
  //   case CMB_BACKSPACE_Q2:
  //     return do_combo_keypress(KC_BSPC, pressed);
  //   case CMB_MINUS_Q2:
  //     return do_combo_keypress(KC_MINS, pressed);
  //   }
  // }
  switch(combo_index) {
    // QWERTY combos
  case CMB_VIM_EASYMOTION_Q:
    if (pressed) {
      tap_code(KC_COMM);
      tap_code(KC_COMM);
      tap_code(KC_S);
    }
    return;
  case CMB_PGDN_Q_OR_PGUP_Q2:
    return do_combo_keypress(KC_PGDN, pressed);
  case CMB_BRKT_Q:
    if (pressed) {
      layer_on(BRKT);
    } else {
      layer_off(BRKT);
    }
    break;
  case CMB_PGUP_Q_OR_PGDN_Q2:
    return do_combo_keypress(KC_PGUP, pressed);
  case CMB_HOME_Q:
    return do_combo_keypress(KC_HOME, pressed);
  case CMB_QUOT_Q_OR_MOUS_C_OR_END_Q2:
    return do_combo_keypress(KC_QUOT, pressed);
  case CMB_END_Q_OR_QUOT_Q2:
    return do_combo_keypress(KC_END, pressed);
  case CMB_MOUS_Q:
    if (pressed) {
      layer_invert(MOUS);
    }
    break;
  case CMB_BACKSPACE_Q:
    return do_combo_keypress(KC_BSPC, pressed);
  case CMB_MINUS_Q:
    return do_combo_keypress(KC_MINS, pressed);
  }
}
