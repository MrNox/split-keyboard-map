#pragma once

#include <keymap.h>


#define LA_0    KC_0          // 0
#define LA_1    KC_1          // 1
#define LA_2    KC_2          // 2
#define LA_3    KC_3          // 3
#define LA_4    KC_4          // 4

#define LA_TILD ALGR(KC_RBRC) // ~
#define LA_AT   ALGR(KC_Q)    // @
#define LA_ACUT KC_LBRC       // ´

#define LA_MINS KC_SLSH       // -
#define LA_PLUS KC_RBRC       // +
#define LA_EQL  S(LA_0)       // =
#define LA_ASTR S(LA_PLUS)    // *

#define LA_LBRK KC_QUOT       // {
#define LA_RBRK KC_BSLS       // }
#define LA_LCBR S(LA_LBRK)    // [ 
#define LA_RCBR S(LA_RBRK)    // [ 

#define LA_QUOT KC_MINS       // '
#define LA_DQUO S(LA_2)       // "
#define LA_IQUE KC_EQL        // ¿
#define LA_QUES S(LA_QUOT)    // ?
#define LA_IEXL S(LA_IQUE)    // ¡
#define LA_EXLM S(KC_1)       // !

#define LA_HASH S(LA_3)       // #
#define LA_GRV  ALGR(KC_BSLS) // `
#define LA_PIPE KC_GRV        // |
#define LA_AMPR S(KC_6)       // &
#define LA_BSLS ALGR(LA_QUOT) // (backslash)
#define LA_CIRC ALGR(LA_LBRK) // ^
#define LA_DLR  S(LA_4)       // $
