#include QMK_KEYBOARD_H
#include "tom.h"

#define SWAP 5 // swap hands (one handed mode)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT_ergodox(
// left hand
// ,--------+------+------+------+------+------+------.
      ___,    ___,   ___,   ___,   ___,   ___,   ___,
// |--------+------+------+------+------+-------------|
      ___,    KC_Q,  KC_W,  KC_E,  KC_R,  KC_T, TT(SWAP),
// |--------+------+------+------+------+------|      |
    KC_TAB,   KC_A,  KC_S,  KC_D,  KC_F,  KC_G,//-----|
// |--------+------+------+------+------+------|      |
    KC_LSFT,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  ___,
// `--------+------+------+------+------+-------------'
    KC_LCTL,KC_LEAD,KC_LALT,MS_DEL,KC_BSPC,
//   `----------------------------------'     ,------+------.
                                                ___,   ___,
//                                     ,------|------|------|
                                                       ___,
//                                     |      |      |------|
                                      MO(NUMB),MED_ESC,KC_ESC,
//                                     `--------------------'
// right hand
//                                   ,------+------+------+------+------+------+--------.
                                       ___,   KC_6,  KC_7,  KC_8,  KC_9,  KC_0,   ___,
//                                   |------+------+------+------+------+------+--------|
                                    TT(SWAP), KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,   ___,
//                                   |      |------+------+------+------+------+--------|
                                   /*|------*/KC_H,  KC_J,  KC_K,  KC_L,MSE_CLN,  ___,
//                                   |      |------+------+------+------+------+--------|
                                       ___,   KC_N,  KC_M,KC_COMM,KC_DOT,BRK_SLS,KC_RSFT,
//                                   `-------------+------+------+------+------+--------'
                                                   KC_LEFT,KC_DOWN,KC_UP,KC_RGHT, ___,
//                         ,-------------.         `----------------------------------'
                            RESET,  ___,
//                         |------+------+------.
                             ___, /*     |     */
//                         |------|      |      |
                            KC_ENT,GUI_ENT,KC_SPC
//                         `--------------------'
),
/* Media and F-keys
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  U   |  I   |CtlSft|AltTab|  F11 |------|           |------| F12  | Home | PgDn | PgUp | End  |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |  M   |Ctl+/ | Del  | Enter|      |           |      |      |      | Prev | Next | Mute |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |Reset |Versn |                                       |      |VolDn |VolUp |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MDIA] = LAYOUT_ergodox(
        // left hand
        ___,      ___,     ___,     ___,     ___,      ___,       ___,
        ___,      KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,     ___,
        ___,      KC_U,    KC_I,  C(KC_LSFT),A(KC_TAB),KC_F11,
        ___,      ___,     KC_M,  C(KC_SLSH),___,      KC_ENT,    ___,
        ___,      ___,     ___,    RESET,    VRSN,
                                                       ___,       ___,
                                                                  ___,
                                             ___,      ___,       ___,
        // right hand
        ___,      ___,     ___,     ___,     ___,      ___,       ___,
        ___,      KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,    ___,
                  KC_F12,  KC_HOME, KC_PGDN, KC_PGUP,  KC_END,    KC_MPLY,
        ___,      ___,     ___,     KC_MPRV, KC_MNXT,  KC_MUTE,   ___,
                           ___,     KC_VOLD, KC_VOLU,  ___,       ___,
        ___,      ___,
        ___,
        ___,      ___,     ___
),
// Numbers and symbols
[NUMB] = LAYOUT_ergodox_wrapper(
// ,--------+------+------+------+------+------+------.
      ___,    ___,   ___,   ___,   ___,   ___,   ___,
// |--------+------+------+------+------+-------------|
      ___,            NUMB_L1_5COL,              ___,
// |--------+------+------+------+------+------|      |
      ___,            NUMB_L2_5COL,            //-----|
// |--------+------+------+------+------+------|      |
      ___,            NUMB_L3_5COL,              ___,
// `--------+------+------+------+------+-------------'
       ___,   ___,   ___,   ___,   ___,
//   `----------------------------------'     ,------+------.
                                                ___,   ___,
//                                     ,------|------|------|
                                                       ___,
                                         ___,   ___, //-----|
                                                       ___,
//                                     `--------------------'
// right hand
//                                   ,------+------+------+------+------+------+--------.
                                       ___,   ___,   ___,   ___,   ___,   ___,    ___,
//                                   |------+------+------+------+------+------+--------|
                                       ___,           NUMB_R1_5COL,               ___,
//                                   |      |------+------+------+------+------+--------|
                                   /*|------*/        NUMB_R2_5COL,               ___,
//                                   |      |------+------+------+------+------+--------|
                                       ___,           NUMB_R3_5COL,               ___,
//                                   `-------------+------+------+------+------+--------'
                                                      NUMB_R4_4COL,               ___,
//                         ,-------------.         `----------------------------------'
                             ___,   ___,
//                         |------+------+------.
                             ___, /*     |     */
//                         |------|      |      |
                             ___,   ___,   ___
//                         `--------------------'
),
// Mouse + paging
[MOUS] = LAYOUT_ergodox_wrapper(
// ,--------+------+------+------+------+------+------.
      ___,    ___,   ___,   ___,   ___,   ___,   ___,
// |--------+------+------+------+------+-------------|
      ___,            MOUS_L1_5COL,              ___,
// |--------+------+------+------+------+------|      |
      ___,            MOUS_L2_5COL,            //-----|
// |--------+------+------+------+------+------|      |
      ___,            MOUS_L3_5COL,              ___,
// `--------+------+------+------+------+-------------'
       ___,   ___,   ___,   ___, KC_ACL2,
//   `----------------------------------'     ,------+------.
                                                ___,   ___,
//                                     ,------|------|------|
                                                       ___,
                                         ___,   ___, //-----|
                                                       ___,
//                                     `--------------------'
// right hand
//                                   ,------+------+------+------+------+------+--------.
                                       ___,   ___,   ___,   ___,   ___,   ___,    ___,
//                                   |------+------+------+------+------+------+--------|
                                       ___,           MOUS_R1_5COL,               ___,
//                                   |      |------+------+------+------+------+--------|
                                   /*|------*/        MOUS_R2_5COL,               ___,
//                                   |      |------+------+------+------+------+--------|
                                       ___,           MOUS_R3_5COL,               ___,
//                                   `-------------+------+------+------+------+--------'
                                                     ___,   ___,   ___,   ___,    ___,
//                         ,-------------.         `----------------------------------'
                             ___,   ___,
//                         |------+------+------.
                             ___, /*     |     */
//                         |------|      |      |
                             ___, KC_BTN2,KC_BTN1
//                         `--------------------'
),
[BRKT] = LAYOUT_ergodox(
// left hand
// ,--------+------+------+------+------+------+------.
      ___,    ___,   ___,   ___,   ___,   ___,   ___,
// |--------+------+------+------+------+-------------|
      ___,    ___,   ___,   ___,   ___,   ___,   ___,
// |--------+------+------+------+------+------|      |
      ___,    ___,   ___,   ___,   ___,   ___, //-----|
// |--------+------+------+------+------+------|      |
      ___,    ___,   ___,   ___,   ___,   ___,   ___,
// `--------+------+------+------+------+-------------'
       ___,   ___,   ___,   ___,   ___,
//   `----------------------------------'     ,------+------.
                                                ___,   ___,
//                                     ,------|------|------|
                                                       ___,
                                         ___,   ___, //-----|
                                                       ___,
//                                     `--------------------'
// right hand
//                                   ,------+------+------+------+------+------+--------.
                                       ___,   ___,   ___,   ___,   ___,   ___,    ___,
//                                   |------+------+------+------+------+------+--------|
                                       ___,   ___, KC_LCBR,KC_RCBR,___,   ___,    ___,
//                                   |      |------+------+------+------+------+--------|
                                   /*|------*/___, KC_LPRN,KC_RPRN,___,   ___,    ___,
//                                   |      |------+------+------+------+------+--------|
                                       ___,   ___, KC_LBRC,KC_RBRC,___,   ___,    ___,
//                                   `-------------+------+------+------+------+--------'
                                                    KC_LT,  KC_GT, ___,   ___,    ___,
//                         ,-------------.         `----------------------------------'
                             ___,   ___,
//                         |------+------+------.
                             ___, /*     |     */
//                         |------|      |      |
                             ___,   ___,   ___
//                         `--------------------'
),
// Swap Layer: hand swap, all keys are mirrored to the other side of the keyboard
// except for the layer toggle itself
[SWAP] = LAYOUT_ergodox(
  /* left hand */
  ___, ___, ___, ___, ___, ___, ___,
  ___, ___, ___, ___, ___, ___, ___,
  ___, ___, ___, ___, ___, ___,
  ___, ___, ___, ___, ___, ___, ___,
  ___, ___, ___, ___, ___,
                                ___, ___,
                                     ___,
                           ___, ___, ___,
  /* right hand */
       ___, ___, ___, ___, ___, ___, ___,
       ___, ___, ___, ___, ___, ___, ___,
            ___, ___, ___, ___, ___, ___,
       ___, ___, ___, ___, ___, ___, ___,
                 ___, ___, ___, ___, ___,
  ___, ___,
  ___,
  ___, ___, ___
),
};
// The current set of active layers (as a bitmask).
// There is a global 'layer_state' variable but it is set after the call
// to layer_state_set_user().
static uint32_t current_layer_state = 0;

// Whether the given layer (one of the constant defined at the top) is active.
#define LAYER_ON(layer) (current_layer_state & (1<<layer))
// Runs whenever there is a layer state change.

uint32_t layer_state_set_user(uint32_t state) {
  current_layer_state = state;
  swap_hands = LAYER_ON(SWAP) && !LAYER_ON(MOUS); // can't deal with mirrored mouse

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        break;
      case 1:
        ergodox_right_led_1_on();
        break;
      case 2:
        ergodox_right_led_2_on();
        break;
      case 3:
        ergodox_right_led_3_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }
  return state;
};
