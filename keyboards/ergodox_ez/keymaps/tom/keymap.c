#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define MDIA 1 // media keys
#define SYMB 2 // numpad
#define MOUS 3 // mouse
#define SWAP 4 // swap hands (one handed mode)

// A 'transparent' key code (that falls back to the layers below it).
#define ___ KC_TRANSPARENT

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | ESC  |           | ~L2  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   \    |   Q  |   W  |   E  |   R  |   T  | Swap |           |  {   |   Y  |   U  |   I  |   O  |   P  |   }    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Tab    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L3|   '    |
 * |--------+------+------+------+------+------|  L1  |           | Swap |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl |Grv/L1| Alt  | Left | Right|                                       | Left | Down | Up   | Right| RGUI |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  F2  | LAlt |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | BkSp | Del  |------|       |------| Enter  | Space|
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_EQL,      KC_1,            KC_2,    KC_3,    KC_4,   KC_5,              KC_ESC,
        KC_BSLS,     KC_Q,            KC_W,    KC_E,    KC_R,   KC_T,              TT(SWAP),
        KC_TAB,      KC_A,            KC_S,    KC_D,    KC_F,   KC_G,
        KC_LSFT,     KC_Z,            KC_X,    KC_C,    KC_V,   KC_B,              MO(MDIA),
        KC_LCTL,     KC_GRV,          KC_LALT, KC_LEFT, KC_RGHT,
                                                                KC_F2,             KC_LALT,
                                                                                   KC_HOME,
                                                        KC_BSPC,KC_DELT,           KC_END,
        // right hand
        TG(SYMB),    KC_6,            KC_7,    KC_8,    KC_9,   KC_0,              KC_MINS,
        KC_LBRC,     KC_Y,            KC_U,    KC_I,    KC_O,   KC_P,              KC_RBRC,
                     KC_H,            KC_J,    KC_K,    KC_L,   LT(MOUS, KC_SCLN), KC_QUOT,
        TT(SWAP),    KC_N,            KC_M,    KC_COMM, KC_DOT, CTL_T(KC_SLSH),    KC_RSFT,
                                      KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT,           KC_RGUI,
        KC_LALT,     KC_RCTL,
        KC_PGUP,
        KC_PGDN,     KC_ENT,          KC_SPC
    ),
/* Keymap 1: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Version |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |           | F12  |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | PgUp |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      | Enter|------|           |------|      | Home | PgDn | End  |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |  /   |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |VolDn |VolUp | Mute |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       | PRSC | Calc |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
        // left hand
        VRSN,     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,
        ___,      ___,     ___,     ___,     ___,     ___,     ___,
        ___,      ___,     ___,     ___,     ___,     KC_ENT ,
        ___,      ___,     ___,     ___,     ___,     KC_SLSH, ___,
        ___,      ___,     ___,     ___,     ___,
                                                      ___,     ___,
                                                               ___,
                                             ___,     ___,     ___,
        // right hand
        KC_F12,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  ___,
        ___,      ___,     ___,     KC_PGUP, ___,     ___,     ___,
                  ___,     KC_HOME, KC_PGDN, KC_END,  ___,     KC_MPLY,
        ___,      ___,     ___,     KC_MPRV, KC_MNXT, ___,     ___,
                           ___,     KC_VOLD, KC_VOLU, KC_MUTE, ___,
        KC_PSCR,  KC_CALC,
        ___,
        ___,      ___,     KC_TRNS
),
/* Keymap 2: Numpad Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |   /  |   *  |   -  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   7  |   8  |   9  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |   4  |   5  |   6  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   1  |   2  |   3  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | Space|      |   .  | Enter|      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       | EPRM |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |   0  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
        // left hand
        ___,      ___,     ___,     ___,     ___,     ___,     ___,
        ___,      ___,     ___,     ___,     ___,     ___,     ___,
        ___,      ___,     ___,     ___,     ___,     ___,
        ___,      ___,     ___,     ___,     ___,     ___,     ___,
        ___,      ___,     ___,     ___,     ___,
                                                      ___,     ___,
                                                               ___,
                                             ___,     ___,     ___,
        // right hand
        ___,      ___,     ___,     KC_SLSH, KC_ASTR, KC_MINS, ___,
        ___,      ___,     KC_7,    KC_8,    KC_9,    KC_PLUS, ___,
                  ___,     KC_4,    KC_5,    KC_6,    KC_PLUS, ___,
        ___,      KC_AMPR, KC_1,    KC_2,    KC_3,    ___,     ___,
                           KC_SPC,  ___,     KC_DOT,  KC_ENT,  ___,
        EPRM,     ___,
        ___,
        ___,      ___,     KC_0
),
/* Keymap 3: Mouse
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |MsScUp|      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      | Mclk |MsScDn|      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------| Rclk | Lclk |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MOUSE
[MOUS] = LAYOUT_ergodox(
        // left hand
        ___,      ___,     ___,     ___,     ___,     ___,     ___,
        ___,      ___,     ___,     KC_MS_U, ___,     ___,     ___,
        ___,      ___,     KC_MS_L, KC_MS_D, KC_MS_R, KC_ENT ,
        ___,      ___,     ___,     ___,     ___,     KC_SLSH, ___,
        ___,      ___,     ___,     ___,     ___,
                                                      ___,     ___,
                                                               ___,
                                             ___,     ___,     ___,
        // right hand
        ___,      ___,     ___,     ___,     ___,     ___,     ___,
        ___,      ___,     ___,     KC_WH_U, ___,     ___,     ___,
                  ___,     KC_BTN3, KC_WH_D, ___,     ___,     ___,
        ___,      ___,     ___,     ___,     ___,     ___,     ___,
                           ___,     ___,     ___,     ___,     ___,
        ___,      ___,
        ___,
        ___,      KC_BTN2, KC_BTN1
),
// Layer 4: hand swap, all keys are mirrored to the other side of the keyboard
// except for the layer toggle itself
[SWAP] = LAYOUT_ergodox(
  /* left hand */
  ___, ___, ___, ___, ___, ___, ___,
  ___, ___, ___, ___, ___, ___, ___,
  ___, ___, ___, ___, ___, ___,
  ___, ___, ___, ___, ___, ___, TT(SWAP),
  ___, ___, ___, ___, ___,
                                ___, ___,
                                     ___,
                           ___, ___, ___,
  /* right hand */
       ___, ___, ___, ___, ___, ___, ___,
  TT(SWAP), ___, ___, ___, ___, ___, ___,
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

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 2 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

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
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
