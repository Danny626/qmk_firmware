#pragma once
#include "snowe.h"

/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/
#if (!defined(LAYOUT) && defined(KEYMAP))
#   define LAYOUT KEYMAP
#endif

//#define LAYOUT_ergodox_wrapper(...)          LAYOUT_ergodox(__VA_ARGS__)
//#define LAYOUT_ergodox_pretty_wrapper(...)   LAYOUT_ergodox_pretty(__VA_ARGS__)
#define KEYMAP_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)
//#define LAYOUT_ortho_4x12_wrapper(...)       LAYOUT_ortho_4x12(__VA_ARGS__)
//#define LAYOUT_ortho_5x12_wrapper(...)       LAYOUT_ortho_5x12(__VA_ARGS__)
//#define LAYOUT_gergo_wrapper(...)            LAYOUT_gergo(__VA_ARGS__)

/*
Blocks for each of the four major keyboard layouts
Organized so we can quickly adapt and modify all of them
at once, rather than for each keyboard, one at a time.
And this allows for much cleaner blocks in the keymaps.
For instance Tap/Hold for Control on all of the layouts

NOTE: These are all the same length.  If you do a search/replace
  then you need to add/remove underscores to keep the
  lengths consistent.
*/

/* #define _________________QWERTY_L1_________________     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________     KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________     KC_Y,        KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________     KC_H,        KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________     KC_N,        KC_M,    KC_COMM, KC_DOT,  KC_SLASH 

#define ________________NUMBER_LEFT________________       KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________       KC_6,    KC_7,    KC_8,    KC_9,    KC_0
//#define ________________NUMBER_RIGHT_______________       KC_6,    KC_7,    TD(TD_8_UP),    KC_9,    KC_0
#define _________________FUNC_LEFT_________________       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10

#define ___________________BLANK___________________        _______, _______, _______, _______, _______


#define _________________LOWER_L1__________________        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _________________LOWER_L2__________________        _________________FUNC_LEFT_________________
#define _________________LOWER_L3__________________        _________________FUNC_RIGHT________________

#define _________________LOWER_R1__________________        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN
#define _________________LOWER_R2__________________        _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR
#define _________________LOWER_R3__________________        _______, KC_LEFT, KC_UP  , KC_DOWN, KC_RGHT


#define _________________RAISE_L1__________________        ________________NUMBER_LEFT________________
#define _________________RAISE_L2__________________        _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC
#define _________________RAISE_L3__________________        ___________________BLANK___________________

#define _________________RAISE_R1__________________        ________________NUMBER_RIGHT_______________
#define _________________RAISE_R2__________________        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______
#define _________________RAISE_R3__________________        _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END



#define _________________ADJUST_L1_________________        RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG
#define _________________ADJUST_L2_________________        MU_TOG , CK_TOGG, AU_ON,   AU_OFF,  AG_NORM
#define _________________ADJUST_L3_________________        RGB_RMOD,RGB_HUD,RGB_SAD, RGB_VAD, _______
#define _________________ADJUST_R1_________________        _______, _______, _______, _______, _______
#define _________________ADJUST_R2_________________        RESET,   CG_TOGG, _______, _______, _______
#define _________________ADJUST_R3_________________        _______, KC_MNXT, KC_VOLU, KC_VOLD, KC_MPLY
*/

#define _________________DVORAK_L1_________________       KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y
#define _________________DVORAK_L2_________________       KC_A,    KC_O,    KC_E,    KC_U,    KC_I
#define _________________DVORAK_L3_________________       KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X

#define _________________DVORAK_R1_________________       KC_F,    KC_G,    KC_C,    KC_R,    KC_L
#define _________________DVORAK_R2_________________       KC_D,    KC_H,    KC_T,    KC_N,    KC_S
#define _________________DVORAK_R3_________________       KC_B,    KC_M,    KC_W,    KC_V,    KC_Z



#define _________________NUMPAD_L1_________________       ___________________BLANK___________________
#define _________________NUMPAD_L2_________________       ___________________BLANK___________________
#define _________________NUMPAD_L3_________________       ___________________BLANK___________________

#define _________________NUMPAD_R1_________________       KC_PPLS, KC_7,    KC_8,    KC_9,    KC_MINS
#define _________________NUMPAD_R2_________________       KC_PAST, KC_4,    KC_5,    KC_6,    KC_SLSH
#define _________________NUMPAD_R3_________________       _______, KC_1,    KC_2,    KC_3,    KC_0



#define ___________________BLANK___________________       _______, _______, _______, _______, _______



#define ________________SYMBOLS_L1_________________       KC_EXLM, KC_AT,   KC_LPRN, KC_RPRN, KC_PERC
#define ________________SYMBOLS_L2_________________       _______, _______, KC_LCBR, KC_RCBR, _______
#define ________________SYMBOLS_L3_________________       _______, _______, KC_LBRC, KC_RBRC, _______

#define ________________SYMBOLS_R1_________________       KC_EQL,  KC_NO,   KC_NO,   KC_NO,   KC_NO
#define ________________SYMBOLS_R2_________________       KC_EXLM, KC_HASH, KC_SLSH, KC_BSLS, KC_PIPE
#define ________________SYMBOLS_R3_________________       _______, KC_GRV,  KC_CIRC, KC_AT,   KC_AMPR



#define ________________NAVIGATE_L1________________       ___________________BLANK___________________
#define ________________NAVIGATE_L2________________       _______, KC_LSFT, KC_LALT, KC_LCTL, _______
#define ________________NAVIGATE_L3________________       KC_BRMU, _______, _______, _______, KC_VOLD

#define ________________NAVIGATE_R1________________       _______, _______,   KC_UP, _______, _______
#define ________________NAVIGATE_R2________________       _______, KC_LEFT, KC_DOWN, KC_RIGHT,_______
#define ________________NAVIGATE_R3________________       KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, _______



#define _________________ADJUST_L1_________________       _______, _______, _______, _______, _______
#define _________________ADJUST_L2_________________       RGB_HUI, RGB_SAI, RGB_VAI, _______, _______
#define _________________ADJUST_L3_________________       RGB_HUD, RGB_SAD, RGB_VAD, _______, _______

#define _________________ADJUST_R1_________________       ___________________BLANK___________________
#define _________________ADJUST_R2_________________       ___________________BLANK___________________
#define _________________ADJUST_R3_________________       ___________________BLANK___________________
