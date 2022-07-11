#include QMK_KEYBOARD_H

#include <keymap_spanish.h>
#include "keymap_latam.h"

#define MOUSEKEY_MAX_SPEED 5
#define MOUSEKEY_DELAY 10
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MOVE_DELTA 1

enum unicode_names {
  ACCNT,
  RQTN,
  enye,
  ENYE
};

const uint32_t PROGMEM unicode_map[] = {
 [ACCNT] = 0x00b4,
 [RQTN] = 0x2e2e,
 [enye] = 0x00f1,
 [ENYE] = 0x00d1,
};

enum layer_number {
  _QWERTY = 0,
  _SYMBOLS,
  _NUMPAD,
  _NAVIGATE,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  ¨   |
 * | LALT |   q  |   w  |   e  |      |   t  |                    |      |      |      |      |      |  ´   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   Ñ  |  ~   |
 * |      |   a  |   s  |   d  |   f  |   g  |       |    |       |   h  |   h  |   k  |   l  |   ñ  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LCTRL |  Z   |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |  ;   |   :  |   >  |ALTGR |
 * |      |  z   |   x  |   c  |   v  |   b  |       |    |       |      |      |  ,   |   .  |   <  | - _  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | LGUI |NUMPAD| /Enter  /       \Space \  |Back  | DEL  |      |
 *                   |      |      |  /   |/NAVIGAT/         \SYMBOL\ |Space |      |      | 
 *                   `----------------------------'           '------''--------------------'
 */
 [_QWERTY] = LAYOUT(
  XXXXXXX,           KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
  LALT_T(KC_ESC),    KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    LA_ACUT,
  KC_LSPO,           KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,    KC_K,    KC_L,    ES_NTIL, LA_TILD,
  LCTL_T(LA_BSLS),   KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, XXXXXXX,      XXXXXXX,   KC_N,    KC_M,    KC_COMM, KC_DOT,  ES_LABK, ALGR_T(LA_MINS),
        XXXXXXX, KC_LGUI, LT(_NUMPAD, KC_PSLS), LT(_NAVIGATE, KC_ENT),       LT(_SYMBOLS, KC_SPC), KC_BSPC, KC_DEL, XXXXXXX
),


/* NUMPAD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  |      |  F1  |  F2  |  F3  |  F4  |                    |  *   |   7  |  8   |  9   |  +   |  -   |
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShfit|LCtrl |  F5  |  F6  |  F7  |  F8  |-------.    ,-------|   /  |   4  |  5   |  6   |LALT  |RShift|
 * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LCTRL |      |  F9  |  F10 | F11  | F12  |-------|    |-------|  %   |   1  |  2   |  3   |  0   |  =   |
 * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | LGUI |NUMPAD| /Enter  /       \Space \  |Back  | DEL  |      |
 *                   |      |      |  /   |/NAVIGAT/         \SYMBOL\ |Space |      |      | 
 *                   `----------------------------'           '------''--------------------'
 */
[_NUMPAD]= LAYOUT(
  _______, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,
  _______, XXXXXXX,   KC_F1,   KC_F2, KC_F3,    KC_F4,                   LA_ASTR,    KC_7,    KC_8, KC_9,  LA_PLUS,  LA_MINS,
  _______, KC_LCTRL,  KC_F5,   KC_F4, KC_F5,    KC_F6,                   KC_PSLS,    KC_4,    KC_5, KC_6,  KC_LALT,  KC_RSFT,
  _______, XXXXXXX,   KC_F9,   KC_F10,KC_F11,  KC_F12, _______, _______,KC_PERCENT,  KC_1,    KC_2, KC_3,  KC_0,     LA_EQL,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),


/* SYMBOLS
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  |   (  |   )  |   ¿  |   ?  |  $   |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   [  |   ]  |   !  |   ¡  |  ^   |-------.    ,-------|  `   |      |      |      |      |      |
 * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LCTRL |   {  |   }  |  |   |   &  |  #   |-------|    |-------|      |      |      |      |      |      |
 * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | LGUI |NUMPAD| /Enter  /       \Space \  |Back  | DEL  |      |
 *                   |      |      |  /   |/NAVIGAT/         \SYMBOL\ |Space |      |      | 
 *                   `----------------------------'           '------''--------------------'
 */

[_SYMBOLS] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______, ES_LPRN, ES_RPRN, LA_IQUE, LA_QUES, LA_DLR,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, LA_LCBR, LA_RCBR, LA_IEXL, LA_EXLM, LA_CIRC,                     LA_GRV,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, LA_LBRK, LA_RBRK, LA_PIPE, LA_AMPR, LA_HASH, _______, _______,   LA_HASH, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),


/* NAVIGATE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  |Wheel |Wheel |Mouse |LShift|Wheel |                    |      |Left  |  Up  |Right |Brillo|      |
 * | LALT |Left  |Right |  Up  | F10  | Up   |                    |      |Click |      |Click |Up    |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift| LALT |Mouse	|Mouse |Mouse |Wheel |-------.    ,-------|      | Left | Down |Right |Brillo|      |
 * |      |      |Left  | Down | Right| Down |       |    |       |      |      |      |      |Down  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LCTRL |LCTRL |LCTRL |LCTRL |LCTRL |Print |-------|    |-------|  TAB | LTAB |  TAB |      |      | Ins  |
 * |      |LShift|LShift|LShift|LShift|Screen|       |    |       |      |      |      |      |      |      |
 * |      |z     |x     |c     |v     |      |       |    |       |      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | LGUI |NUMPAD| /Enter  /       \Space \  |Back  | DEL  |      |
 *                   |      |      |  /   |/NAVIGAT/         \SYMBOL\ |Space |      |      | 
 *                   `----------------------------'           '------''--------------------'
 */
  [_NAVIGATE] = LAYOUT(
  _______, _______,      _______,   _______,     _______,    _______,                    _______,     _______,   _______, _______, _______, _______,
  _______, KC_WH_L,      KC_WH_R,   KC_MS_U,     S(KC_F10),  KC_WH_U,                    KC_VOLU,     KC_BTN1,   KC_UP,   KC_BTN2, KC_BRIU, XXXXXXX,
  _______, KC_LALT,      KC_MS_L,   KC_MS_D,     KC_MS_R,    KC_WH_D,                    KC_VOLD,     KC_LEFT,   KC_DOWN, KC_RGHT, KC_BRID, XXXXXXX,
  _______, C(S(KC_Z)),   C(S(KC_X)), C(S(KC_C)), C(S(KC_V)), KC_PSCR, _______, _______,  KC_TAB, C(S(KC_TAB)), C(KC_TAB), XXXXXXX, XXXXXXX, KC_INS,  
                                  _______, _______, _______, _______,      _______,   _______, _______, _______
  ),


  [_ADJUST] = LAYOUT( \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               _______, _______, _______, _______, _______,  _______, _______, _______
  )

};

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
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
