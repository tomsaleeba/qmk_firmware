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
      break;
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
    SEQ_ONE_KEY(KC_B) {
      sendTwoKeys(KC_LALT, KC_LEFT);
    }

    // fat arrow
    SEQ_ONE_KEY(KC_DOT) {
      sendThreeKeys(KC_EQL, KC_LSHIFT, KC_DOT);
    }

    // alt tab
    SEQ_ONE_KEY(KC_LALT) {
      sendTwoKeys(KC_LALT, KC_TAB);
    }

    // rofi-pass
    SEQ_ONE_KEY(KC_D) {
      sendThreeKeys(KC_LGUI, KC_LSHIFT, KC_D);
    }

    // new terminal in i3
    SEQ_ONE_KEY(KC_T) {
      sendTwoKeys(KC_LGUI, KC_ENT);
    }

    // i3 "move workspace to monitor"
    SEQ_ONE_KEY(KC_LEFT) {
      // don't need one for right. On two monitors, it's the same
      sendThreeKeys(KC_LCTL, KC_LGUI, KC_LEFT);
    }

    // i3 "toggle scratchpad"
    SEQ_ONE_KEY(KC_QUOT) {
      sendTwoKeys(KC_LGUI, KC_MINS);
    }

    // i3 "move window to workspace"
    SEQ_ONE_KEY(KC_1) { sendThreeKeys(KC_LSHIFT, KC_LGUI, KC_1); }
    SEQ_ONE_KEY(KC_2) { sendThreeKeys(KC_LSHIFT, KC_LGUI, KC_2); }
    SEQ_ONE_KEY(KC_3) { sendThreeKeys(KC_LSHIFT, KC_LGUI, KC_3); }
    SEQ_ONE_KEY(KC_4) { sendThreeKeys(KC_LSHIFT, KC_LGUI, KC_4); }
    SEQ_ONE_KEY(KC_5) { sendThreeKeys(KC_LSHIFT, KC_LGUI, KC_5); }
  }
}

uint16_t get_tapping_term(uint16_t keycode) {
  switch (keycode) {
    case MED_ESC:
      return 150;
    default:
      return TAPPING_TERM;
  }
}
