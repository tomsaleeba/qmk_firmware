#include QMK_KEYBOARD_H
#include "tom.h"

#define ROW4_LEFT QK_LEAD, KC_LALT,  KC_DEL,   GUI_ENT, KC_LSFT,   KC_LCTL
#define ROW4_RGHT                                          NMB_ENT,  KC_SPC,  MO(ARRW), KC_CAPS, OSM(MOD_LSFT), OSM(MOD_LCTL)

#define ROW5_L_PARTIAL               KC_SPC,   KC_ESC,  MO(MDIA),  MO(BRKT)
#define ROW5_R_PARTIAL                                     ALT_TABT, ALT_TAB, KC_APP,   CLROSM

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_ergoslab_wrapper(
             BASE_L1_5COL,                                                                  BASE_R1_5COL,
             BASE_L2_5COL,                                                                  BASE_R2_5COL,
             BASE_L3_5COL,                                                                  BASE_R3_5COL,
             ROW4_LEFT,                                                                     ROW4_RGHT,
             TG(GAME),      ROW5_L_PARTIAL,                                 ROW5_R_PARTIAL,           TO(CMAK)
  ),

  [CMAK] = LAYOUT_ergoslab_wrapper(
    _______, S(KC_SPC),C(KC_PLUS), C(KC_SPC),  _______,                     _______,  _______,  _______,  _______, _______,
    KC_A,    KC_X,     C(KC_MINS), KC_SPC,     _______,                     _______,  _______,  _______,  _______, _______,
    C(KC_Z), RCS(KC_Z),_______,    _______,    KC_B,                        _______,  _______,  _______,  _______, _______,
             ROW4_LEFT,                                                                     ROW4_RGHT,
             _______,       ROW5_L_PARTIAL,                                 ROW5_R_PARTIAL,           TO(BASE)
  ),

  [QWDF] = LAYOUT_ergoslab_wrapper(
             QWDF_L1_5COL,                                                                  QWDF_R1_5COL,
             QWDF_L2_5COL,                                                                  QWDF_R2_5COL,
             QWDF_L3_5COL,                                                                  QWDF_R3_5COL,
             ROW4_LEFT,                                                                     ROW4_RGHT,
             _______,       ROW5_L_PARTIAL,                                 ROW5_R_PARTIAL,           TO(BASE)
  ),

  [MDIA] = LAYOUT_ergoslab_wrapper(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                          KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,
    KC_COMM, KC_PLUS, KC_MINS, KC_DOT,  KC_F11,                         KC_F12,   KC_HOME,  KC_PGDN,  KC_PGUP, KC_END,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           RGB_TOG,  _______,  KC_BRID,  KC_BRIU, KC_MUTE,
    KC_0,    QK_BOOT, VRSN,    KC_DOT,  _______, _______,     _______,  _______,  _______,  KC_VOLD,  KC_VOLU, _______,
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
    KC_ACL0, _______, _______, _______, _______, _______,     KC_BTN2,  KC_BTN1,  _______,  _______,  _______, _______,
             _______, _______, _______, _______, _______,     _______,  _______,  _______,  _______,  _______
  ),

  [BRKT] = LAYOUT_ergoslab_wrapper(
             BRKT_L1_5COL,                                                                  BRKT_R1_5COL,
             BRKT_L2_5COL,                                                                  BRKT_R2_5COL,
             BRKT_L3_5COL,                                                                  BRKT_R3_5COL,
    _______, _______, _______, _______, _______, _______,     _______,  _______,  _______,  _______,  _______, _______,
             _______, _______, _______, _______, _______,     _______,  _______,  _______,  _______,  _______
  ),

  [GAME] = LAYOUT_ergoslab_wrapper(
             BASE_L1_5COL,                                              _______,  _______,  KC_KP_8,  _______, _______,
             BASE_L2_5COL,                                              _______,  KC_KP_4,  KC_KP_5,  KC_KP_6, _______,
             BASE_L3_5COL,                                                                  BASE_R3_5COL,
    _______, _______, _______, KC_TAB,  _______, _______,     KC_ENT,   _______,  KC_LEFT,  KC_DOWN,  KC_UP,   KC_RGHT,
             _______, _______, _______, _______, KC_SPACE,    KC_TAB,   KC_ESC,   _______,  _______,  _______
  ),

  [ARRW] = LAYOUT_ergoslab_wrapper(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   W_THE,                          KC_NO,    AS_LEFT,  AS_DOWN,  AS_UP,   AS_RGHT,
  LGUI(KC_1),LGUI(KC_2),LGUI(KC_3),LGUI(KC_4),LGUI(KC_5),          LGUI(KC_6),    KC_LEFT,  KC_DOWN,  KC_UP,   KC_RGHT,
    W_AND,   KC_NO,   W_CONST, KC_NO,   KC_NO,                          KC_NO,    CS_LEFT,  A_LEFT,   A_RGHT,  CS_RGHT,
    _______, _______, KC_NO,   _______, _______, _______,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,
             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO
  ),
};

#if defined(RGBLIGHT_ENABLE)
  layer_state_t layer_state_set_user(layer_state_t state) {
    if (get_oneshot_locked_mods() ||
        (get_oneshot_mods() && !has_oneshot_mods_timed_out())) {
      return state;
    }
    uint8_t layer = biton32(state);
    switch (layer) {
      case BASE:
        rgblight_sethsv_noeeprom(HSV_TOM_ORANGE);
        break;
      case CMAK:
        rgblight_sethsv_noeeprom(HSV_TOM_BLUE);
        break;
      case QWDF:
        rgblight_sethsv_noeeprom(HSV_TOM_DIM_GREEN);
        break;
      case MDIA:
        rgblight_sethsv_noeeprom(HSV_TOM_RED);
        break;
      case NUMB:
        rgblight_sethsv_noeeprom(HSV_TOM_GREEN);
        break;
      case MOUS:
        rgblight_sethsv_noeeprom(HSV_TOM_CYAN);
        break;
      case BRKT:
        rgblight_sethsv_noeeprom(HSV_TOM_PURPLE);
        break;
      case GAME:
        rgblight_sethsv_noeeprom(HSV_TOM_DIM_PURPLE);
        break;
      case ARRW:
        rgblight_sethsv_noeeprom(HSV_TOM_YELLOW);
        break;
      default:
        rgblight_sethsv_noeeprom(HSV_MAGENTA);
        break;
    }
    return state;
  };

  void oneshot_mods_changed_user(uint8_t mods) {
    if (mods & MOD_MASK_SHIFT || mods & MOD_MASK_CTRL || mods & MOD_MASK_GUI) {
      rgblight_sethsv_noeeprom(HSV_TOM_WHITE);
      return;
    }
    layer_state_set_user(layer_state | default_layer_state);
  }

  void oneshot_locked_mods_changed_user(uint8_t mods) {
    oneshot_mods_changed_user(mods);
  }

  void keyboard_post_init_user(void) {
    rgblight_sethsv_noeeprom(HSV_TOM_ORANGE);
  }

  // FIXME it works for turning on, but turning off is harder because we have to figure
  //  out what to go back to (layers) and when to do it (not on every record)
  // void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
  //   if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
  //     // FIXME might be a bit wasteful to check on every record
  //     rgblight_sethsv_noeeprom(HSV_TOM_WHITE);
  //   }
  // }
#endif
