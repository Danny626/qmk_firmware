#pragma once
#include QMK_KEYBOARD_H

#ifndef QMK_FIRMWARE_SNOWE_H
#    define QMK_FIRMWARE_SNOWE_H ;
#endif  // QMK_FIRMWARE_SNOWE_H

#include "wrappers.h"
#include "keycode_aliases.h"

#define IGNORE_MOD_TAP_INTERRUPT
#undef PERMISSIVE_HOLD

//#if defined(RGBLIGHT_ENABLE)
//#    include "rgb_stuff.h"
//#endif
//#if defined(RGB_MATRIX_ENABLE)
//#    include "rgb_matrix_stuff.h"
//#endif
#ifdef OLED_ENABLE
#    include "oled_setup.h"
#endif


enum layers { _DVORAK, _SYMBOLS, _NAVIGATE, _NUMPAD, _ADJUST };

// Custom keycodes for layer keys
// Dual function escape with left command
// #define KC_LGESC LGUI_T(KC_ESC)
enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  SYMBOLS,
  NAVIGATE,
  NUMPAD,
  ADJUST,
  RGBRST,
  KC_RACL // right alt / colon
};
