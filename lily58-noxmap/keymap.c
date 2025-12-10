#include QMK_KEYBOARD_H

#include <keymap_extras/keymap_spanish_latin_america.h>
//#include "keymap_latam.h"


enum layer_number {
  _QWERTY_WIN = 0,  // win/linux
  _SYMBOLS,
  _NUMPAD,
  _NAVIGATE_WIN,
  _QWERTY_MAC,      //macOS
  _NAVIGATE_MAC,
  _ADJUST,
  _ADJUST2,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY_WIN] = LAYOUT(
  KC_ESC,           KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
  LALT_T(KC_ESC),   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    ES_ACUT,
  SC_LSPO,          KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L,    ES_NTIL, ES_TILD,
  LCTL_T(ES_BSLS),  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, DF(_QWERTY_WIN),    DF(_QWERTY_MAC),   KC_N,    KC_M,    KC_COMM, KC_DOT,  ES_LABK, ALGR_T(ES_MINS),
        XXXXXXX, KC_LGUI, LT(_NUMPAD, KC_PSLS), LT(_NAVIGATE_WIN, KC_ENT),       LT(_SYMBOLS, KC_SPC), KC_BSPC, KC_DEL, XXXXXXX
),

[_QWERTY_MAC] = LAYOUT(
  KC_ESC,           KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
  LALT_T(KC_ESC),    KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    ES_ACUT,
  SC_LSPO,           KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,    KC_K,    KC_L,    ES_NTIL, ES_TILD,
  LCTL_T(ES_BSLS),   KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, DF(_QWERTY_WIN),   DF(_QWERTY_MAC),  KC_N,    KC_M,    KC_COMM, KC_DOT,  ES_LABK, ALGR_T(ES_MINS),
        XXXXXXX, KC_LGUI, LT(_NUMPAD, KC_PSLS), LT(_NAVIGATE_MAC, KC_ENT),       LT(_SYMBOLS, KC_SPC), KC_BSPC, KC_DEL, XXXXXXX
),

[_NUMPAD]= LAYOUT(
  _______, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,
  _______, XXXXXXX,   KC_F1,   KC_F2, KC_F3,    KC_F4,                   ES_ASTR,    KC_7,    KC_8, KC_9,  ES_PLUS,  ES_MINS,
  _______, KC_LCTL,   KC_F5,   KC_F6, KC_F7,    KC_F8,                   KC_PSLS,    KC_4,    KC_5, KC_6,  KC_LALT,  KC_RSFT,
  _______, XXXXXXX,   KC_F9,   KC_F10,KC_F11,  KC_F12, _______, _______,KC_PERCENT,  KC_1,    KC_2, KC_3,  KC_0,     ES_EQL,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),

[_SYMBOLS] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______, ES_LPRN, ES_RPRN, ES_IQUE, ES_QUES, ES_CIRC,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, ES_LBRC, ES_LBRC, ES_IEXL, ES_EXLM, ES_DLR,                      ES_GRV,  XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT, KC_RSFT,
  _______, ES_LCBR, ES_RCBR, ES_PIPE, ES_AMPR, ES_NUMB, _______, _______,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),

[_NAVIGATE_WIN] = LAYOUT(
  _______, _______,      _______,   _______,     _______,    _______,                    _______,     _______,   _______, _______, _______, _______,
  _______, MS_WHLL,      MS_WHLR,     MS_UP,     S(KC_F10),  MS_WHLU,                    KC_PSCR,     MS_BTN1,   XXXXXXX, MS_BTN2, KC_BRIU, XXXXXXX,
  _______, KC_LALT,      MS_LEFT,   MS_DOWN,     MS_RGHT,    MS_WHLD,                    KC_LEFT,     KC_DOWN,   KC_UP,   KC_RGHT, KC_BRID, XXXXXXX,
  _______, C(S(KC_Z)),   C(S(KC_X)), C(S(KC_C)), C(S(KC_V)), KC_LGUI, _______, _______,  KC_TAB, C(S(KC_TAB)), C(KC_TAB), XXXXXXX, XXXXXXX, KC_INS,
                                  _______, _______, _______, _______,      _______,   _______, _______, _______
  ),

/* NAVIGATE_MAC  (solo cambia los atajos de edición a Cmd+Shift+Z/X/C/V)
 *  - OJO: mantenemos Ctrl+Tab / Ctrl+Shift+Tab porque en macOS
 *    los navegadores también usan esas combinaciones para pestañas.
 */
  [_NAVIGATE_MAC] = LAYOUT(
  _______, _______,      _______,   _______,     _______,    _______,                    _______,     _______,   _______, _______, _______, _______,
  _______, MS_WHLL,      MS_WHLR,     MS_UP,     S(KC_F10),  MS_WHLU,                    KC_PSCR,     MS_BTN1,   XXXXXXX, MS_BTN2, KC_BRIU, XXXXXXX,
  _______, KC_LALT,      MS_LEFT,   MS_DOWN,     MS_RGHT,    MS_WHLD,                    KC_LEFT,     KC_DOWN,   KC_UP,   KC_RGHT, KC_BRID, XXXXXXX,
  _______, LGUI(S(KC_Z)), LGUI(S(KC_X)), LGUI(S(KC_C)), LGUI(S(KC_V)), KC_LGUI, _______, _______, KC_TAB, C(S(KC_TAB)), C(KC_TAB), XXXXXXX, XXXXXXX, KC_INS,
                                  _______, _______, _______, _______,      _______,   _______, _______, _______
  ),

[_ADJUST] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, DF(_QWERTY_WIN), DF(_QWERTY_MAC), XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               _______, _______, _______, _______, _______,  _______, _______, _______
  ),

[_ADJUST2] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               _______, _______, _______, _______, _______,  _______, _______, _______
  )

};


// OLED (igual que tu original)
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;
  return rotation;
}

const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}

