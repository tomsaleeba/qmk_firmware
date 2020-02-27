#include QMK_KEYBOARD_H
#include "tom.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_ergoslab_wrapper(
             BASE_L1_5COL,                                                                  BASE_R1_5COL,
             BASE_L2_5COL,                                                                  BASE_R2_5COL,
             BASE_L3_5COL,                                                                  BASE_R3_5COL,
    KC_LEAD, KC_LALT, KC_DEL,  GUI_ENT, KC_LSFT, KC_LCTL,     NMB_ENT,  KC_SPC,   KC_LEFT,  KC_DOWN,  KC_UP,   KC_RGHT,
             DF(CMAK),TG(SWAP),KC_ESC , MO(MDIA),MO(BRKT),    KC_TAB,   ALT_TAB,  KC_BSPC,  TG(SWAP), TG(CMAK)
  ),

  [CMAK] = LAYOUT_ergoslab_wrapper(
             CMAK_L1_5COL,                                                                  CMAK_R1_5COL,
             CMAK_L2_5COL,                                                                  CMAK_R2_5COL,
             CMAK_L3_5COL,                                                                  CMAK_R3_5COL,
    KC_LEAD, KC_LALT, KC_DEL,  GUI_ENT, KC_LSFT, KC_LCTL,     NMB_ENT,  KC_SPC,   KC_LEFT,  KC_DOWN,  KC_UP,   KC_RGHT,
             DF(BASE),TG(SWAP),MO(BRKT),MO(MDIA),KC_ESC,      KC_TAB,   ALT_TAB,  KC_BSPC,  TG(SWAP), _______
  ),

  [MDIA] = LAYOUT_ergoslab_wrapper(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                          KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,
    KC_COMM, KC_PLUS, KC_MINS, KC_DOT,  KC_F11,                         KC_F12,   KC_HOME,  KC_PGDN,  KC_PGUP, KC_END,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           RGB_TOG,  _______,  _______,  _______, KC_MUTE,
    KC_0,    RESET,   VRSN,    KC_COMM, KC_DOT,  _______,     _______,  _______,  _______,  KC_VOLD,  KC_VOLU, _______,
             _______, _______, _______, _______, _______,     _______,  _______,  _______,  _______,  _______
  ),

  [NUMB] = LAYOUT_ergoslab_wrapper(
             NUMB_L1_5COL,                                                                  NUMB_R1_5COL,
             NUMB_L2_5COL,                                                                  NUMB_R2_5COL,
             NUMB_L3_5COL,                                                                  NUMB_R3_5COL,
    _______, _______, _______, _______, _______, _______,     _______,  _______,            NUMB_R4_4COL,
             _______, _______, _______, _______, _______,     _______,  _______,  _______,  _______,  _______
  ),

  [MOUS] = LAYOUT_ergoslab_wrapper(
             MOUS_L1_5COL,                                                                  MOUS_R1_5COL,
             MOUS_L2_5COL,                                                                  MOUS_R2_5COL,
             MOUS_L3_5COL,                                                                  MOUS_R3_5COL,
    _______, _______, _______, _______, KC_ACL0, _______,     KC_BTN2,  KC_BTN1,  _______,  _______,  _______, _______,
             _______, _______, _______, _______, _______,     _______,  _______,  _______,  _______,  _______
  ),

  [BRKT] = LAYOUT_ergoslab_wrapper(
             BRKT_L1_5COL,                                                                  BRKT_R1_5COL,
             BRKT_L2_5COL,                                                                  BRKT_R2_5COL,
             BRKT_L3_5COL,                                                                  BRKT_R3_5COL,
    _______, _______, _______, _______, _______, _______,     _______,  _______,  KC_LT,    KC_GT,    _______, _______,
             _______, _______, _______, _______, _______,     _______,  _______,  _______,  _______,  _______
  ),

  [SWAP] = LAYOUT_ergoslab_wrapper(
    _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,  _______,     _______, _______, _______, _______, _______, _______,
             _______, _______, _______, _______,  _______,     _______, _______, _______, _______, _______
  ),
};

#ifdef SWAP_HANDS_ENABLE
  // The current set of active layers (as a bitmask).
  // There is a global 'layer_state' variable but it is set after the call
  // to layer_state_set_user().
  static uint32_t current_layer_state = 0;

  // Whether the given layer (one of the constant defined at the top) is active.
  #define LAYER_ON(layer) (current_layer_state & (1<<layer))
#endif

#if defined(RGBLIGHT_ENABLE)
uint32_t layer_state_set_user(uint32_t state) {
  #ifdef SWAP_HANDS_ENABLE
    current_layer_state = state;
    swap_hands = LAYER_ON(SWAP) && !LAYER_ON(MOUS); // can't deal with mirrored mouse
  #endif
  uint8_t layer = biton32(state);
  switch (layer) {
      case BASE:
          rgblight_sethsv(HSV_TOM_ORANGE);
        break;
      case MDIA:
          rgblight_sethsv(HSV_TOM_RED);
        break;
      case NUMB:
          rgblight_sethsv(HSV_TOM_GREEN);
        break;
      case MOUS:
          rgblight_sethsv(HSV_TOM_CYAN);
        break;
      case BRKT:
          rgblight_sethsv(HSV_TOM_PURPLE);
        break;
      case CMAK:
          rgblight_sethsv(HSV_TOM_YELLOW);
        break;
      case SWAP:
          rgblight_sethsv(HSV_TOM_WHITE);
        break;
      default:
        break;
    }
  return state;
};
#endif
