#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define MDIA 1 // media keys
#define NUMB 2 // minimal numbers test
#define MOUS 3 // mouse
#define SWAP 4 // swap hands (one handed mode)
#define ARRW 5 // arrows

// A 'transparent' key code (that falls back to the layers below it).
#define ___ KC_TRANSPARENT

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

// tapdance keycodes
enum td_keycodes {
  F_ARROWS
};

// define a type containing as many tapdance states as you need
typedef enum {
  SINGLE_TAP,
  SINGLE_HOLD,
  DOUBLE_SINGLE_TAP,
} td_state_t;

// create a global instance of the tapdance state type
static td_state_t td_state;

// declare your tapdance functions:

// function to determine the current tapdance state
int cur_dance (qk_tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void farrows_finished (qk_tap_dance_state_t *state, void *user_data);
void farrows_reset (qk_tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   \    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |  Swap  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Tab/L1 |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L3|   '    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl |      |  Alt |  Del |  L2  |                                       | Left | Down | Up   | Right|Arrows|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | BkSp |  L1  |------|       |------| Enter| Space|
 *                                 |      | /Esc |      |       |      | /RGUI|      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        ___,              ___,             ___,         ___,     ___,    ___,      ___,
        KC_BSLS,          KC_Q,            KC_W,        KC_E,    KC_R,   KC_T,     ___,
        LT(MDIA,KC_TAB),  KC_A,            KC_S,        KC_D,    KC_F,   KC_G,
        KC_LSFT,          KC_Z,            KC_X,        KC_C,    KC_V,   KC_B,     ___,
        KC_LCTL,          ___,             KC_LALT,     KC_DEL,  MO(NUMB),
                                                             ___,              ___,
                                                                               ___,
                                                   KC_BSPC,  LT(MDIA,KC_ESC),  ___,
        // right hand
        ___,         ___,             ___,     ___,     ___,    ___,               ___,
        ___,         KC_Y,            KC_U,    KC_I,    KC_O,   KC_P,              TT(SWAP),
                     KC_H,            KC_J,    KC_K,    KC_L,   LT(MOUS, KC_SCLN), KC_QUOT,
        TT(SWAP),    KC_N,            KC_M,    KC_COMM, KC_DOT, RCTL_T(KC_SLSH),   KC_RSFT,
                                      KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT,           TT(ARRW),
        ___,         ___,
        ___,
        ___,         RGUI_T(KC_ENT),  KC_SPC
    ),
/* Keymap 1: Media and F-keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |Version |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |CtlSft|AltTab|  F11 |------|           |------| F12  | Home | PgDn | PgUp | End  |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |Ctl+/ | Del  | Enter|      |           |      |      |      | Prev | Next | Mute |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |VolDn |VolUp |      |      |
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
        VRSN,     KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,     ___,
        ___,      ___,     ___,   C(KC_LSFT),A(KC_TAB),KC_F11,
        ___,      ___,     ___,   C(KC_SLSH),KC_DEL,   KC_ENT,    ___,
        ___,      ___,     ___,     ___,     ___,
                                                       ___,       ___,
                                                                  ___,
                                             ___,      ___,       ___,
        // right hand
        ___,      ___,     ___,     ___,     ___,      ___,       ___,
        KC_F12,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,    ___,
                  ___,     KC_HOME, KC_PGDN, KC_PGUP,  KC_END,    KC_MPLY,
        ___,      ___,     ___,     KC_MPRV, KC_MNXT,  KC_MUTE,   ___,
                           ___,     KC_VOLD, KC_VOLU,  ___,       ___,
        ___,      ___,
        ___,
        ___,      ___,     KC_TRNS
),
/* Keymap 2: Numbers and symbols
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   +    |  !   |  @   |  #   |  $   |  %   |      |           |      |  ^   |  &   |  *   |  (   |  )   |   _    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   =    |  1   |  2   |  3   |  4   |  5   |------|           |------|  6   |  7   |  8   |  9   |  0   |   -    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | End  | PgUp | PgDn | Home | ` ~  |      |           |      |  [   |  ]   |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NUMB] = LAYOUT_ergodox(
        // left hand
        ___,          ___,        ___,        ___,         ___,         ___,         ___,
        LSFT(KC_EQL), LSFT(KC_1), LSFT(KC_2), LSFT(KC_3),  LSFT(KC_4),  LSFT(KC_5),  ___,
        KC_EQL,       KC_1,       KC_2,       KC_3,        KC_4,        KC_5,
        ___,          KC_END,     KC_PGUP,    KC_PGDN,     KC_HOME,     KC_GRV,      ___,
        ___,          ___,        ___,        ___,         ___,
                                                                        ___,         ___,
                                                                                     ___,
                                                           ___,         ___,         ___,
        // right hand
        ___,      ___,         ___,        ___,         ___,         ___,         ___,
        ___,      LSFT(KC_6),  LSFT(KC_7), LSFT(KC_8),  LSFT(KC_9),  LSFT(KC_0),  LSFT(KC_MINS),
                  KC_6,        KC_7,       KC_8,        KC_9,        KC_0,        KC_MINS,
        ___,      KC_LBRC,     KC_RBRC,    ___,         ___,         ___,         ___,
                               ___,        ___,         ___,         ___,         ___,
        ___,      ___,
        ___,
        ___,      ___,         KC_TRNS
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
/* Keymap 5: Arrows
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      | Left | Down |  Up  | Right|        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[ARRW] = LAYOUT_ergodox(
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
        ___,      ___,     ___,     ___,     ___,     ___,     ___,
        ___,      ___,     ___,     ___,     ___,     ___,     ___,
                  ___,     KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT,  ___,
        ___,      ___,     ___,     ___,     ___,     ___,     ___,
                           ___,     ___,     ___,     ___,     ___,
        ___,      ___,
        ___,
        ___,      ___,     ___
),
};
// The current set of active layers (as a bitmask).
// There is a global 'layer_state' variable but it is set after the call
// to layer_state_set_user().
static uint32_t current_layer_state = 0;

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

// determine the tapdance state to return
int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) { return SINGLE_TAP; }
    else { return SINGLE_HOLD; }
  }
  return DOUBLE_SINGLE_TAP;
}

// handle the possible states for each tapdance keycode you define:

void farrows_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
    case SINGLE_TAP:
      register_code16(KC_F);
      break;
    case SINGLE_HOLD:
      register_mods(MOD_BIT(KC_LCTL));
      register_mods(MOD_BIT(KC_LSHIFT));
      layer_on(ARRW);
      break;
    case DOUBLE_SINGLE_TAP:
      register_code16(KC_F);
      unregister_code16(KC_F);
      register_code16(KC_F);
      break;
  }
}

void farrows_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
    case SINGLE_TAP:
      unregister_code16(KC_F);
      break;
    case SINGLE_HOLD:
      unregister_mods(MOD_BIT(KC_LCTL));
      unregister_mods(MOD_BIT(KC_LSHIFT));
      layer_off(ARRW);
      break;
    case DOUBLE_SINGLE_TAP:
      unregister_code16(KC_F);
      break;
  }
}

// define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
qk_tap_dance_action_t tap_dance_actions[] = {
  [F_ARROWS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, farrows_finished, farrows_reset)
};
