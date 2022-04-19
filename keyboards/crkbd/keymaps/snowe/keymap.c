#include QMK_KEYBOARD_H
#include "snowe.h"

// Tap Dance declarations
/* enum {
    TD_LSFT_CAPS,
}; */

// Custom keycodes for layer keys
// Dual function escape with left command
// #define KC_LGESC LGUI_T(KC_ESC)

// Symbols chart
// ↯ hyper key (ctrl, alt, shift, super)
// ⌘ command
// ⌥ option
// ⌃ control
// ⇧ shift
// ⌫ backspace
// ⌦ delete
// ⎋ escape
// ↩ enter

/* Wrapper
 * ,-----------------------------------------------. .-----------------------------------------------.
 * |  Tab  |  K01  |  K02  |  K03  |  K04  |  K05  | |  K06  |  K07  |  K08  |  K09  |  K0A  |       |
 * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
 * |  ⌘/⎋  | ⌃/K11 |  K12  |  K13  |  K14  |  K15  | |  K16  |  K17  |  K18  |  K19  | ⌥/K1A |       |
 * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
 * |  ↯/⌦  | ⌥/K21 |  K22  |  K23  |  K24  |  K25  | |  K26  |  K27  |  K28  |  K29  | ⌃/K2A |       |
 * `-----------------------.                       | |                       .-----------------------'
 *                         |-------+-------+-------| |-------+-------+-------|
 *                         |   ⌃   |  ⇧/↩  | ⌫/LWR | | ␣/RAY |   ␣   |  R ⌥  |
 *                         `-----------------------' '-----------------------'
 */
// clang-format off
#define LAYOUT_crkbd_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_wrapper( \
    LT(_NUMPAD,KC_ESC), K01, K02, K03, K04, K05,     K06, K07, K08, K09, K0A, KC_BSPC, \
    LCTL_T(KC_TAB),    K11, K12, K13, K14, K15,     K16, K17, K18, K19, K1A, KC_MINS, \
    KC_LSFT,           K21, K22, K23, K24, K25,     K26, K27, K28, K29, K2A, KC_RSFT, \
          KC_LGUI, LT(_SYMBOLS,KC_DEL), SH_BKSP,   KC_ENTER, LT(_NAVIGATE,KC_SPC), KC_RALT \
  )
// clang-format on
#define LAYOUT_crkbd_base_wrapper(...) LAYOUT_crkbd_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    /* QWERTY
     * ,-----------------------------------------------. .-----------------------------------------------.
     * |       |   Q   |   W   |   E   |   R   |   T   | |   Y   |   U   |   I   |   O   |   P   |       |
     * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
     * |       |   A   |   S   |   D   |   F   |   G   | |   H   |   J   |   K   |   L   |   ;   |  '    |
     * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
     * |       |   Z   |   X   |   C   |   V   |   B   | |   N   |   M   |   ,   |   .   |   /   |       |
     * `-----------------------.                       | |                       .-----------------------'
     *                         |-------+-------+-------| |-------+-------+-------|
     *                         |       |       |       | |       |       |       |
     *                         `-----------------------' '-----------------------'
     */
    /* [_MAIN] = LAYOUT_crkbd_base_wrapper(
        _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
        _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
        _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
    ), */
    /* [_MAIN] = LAYOUT_crkbd_base_wrapper(
        LT(NUMPAD,KC_ESC),  _________________DVORAK_L1_________________,        _________________DVORAK_R1_________________, KC_BSPC,
        LCTL_T(KC_TAB),     _________________DVORAK_L2_________________,        _________________DVORAK_R2_________________, KC_MINS,
        TD(TD_LSFT_CAPS),   _________________DVORAK_L3_________________,        _________________DVORAK_R3_________________, KC_RSFT,
                                              KC_LGUI, MO(LOWER), KC_SPC,  KC_SPC, LT(RAISE,KC_ENT), KC_RALT
    ), */

    [_DVORAK] = LAYOUT_crkbd_base_wrapper(
        _________________DVORAK_L1_________________,        _________________DVORAK_R1_________________,
        _________________DVORAK_L2_________________,        _________________DVORAK_R2_________________,
        _________________DVORAK_L3_________________,        _________________DVORAK_R3_________________
    ),

    /* Lower
     * ,-----------------------------------------------. .-----------------------------------------------.
     * |   ~   |   !   |   @   |   #   |   $   |   %   | |   ^   |   &   |   *   |   (   |   )   |       |
     * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
     * |       |       |       |       |       |       | |       |   _   |   +   |   [   |   ]   |       |
     * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
     * |       |       |       |       |       |       | |       |   ←   |   ↑   |   ↓   |   →   |       |
     * `-----------------------.                       | |                       .-----------------------'
     *                         |-------+-------+-------| |-------+-------+-------|
     *                         |       |       |       | |       |       |       |
     *                         `-----------------------' '-----------------------'
     */
    [_SYMBOLS] = LAYOUT_wrapper(
        _______, ________________SYMBOLS_L1_________________,                   ________________SYMBOLS_R1_________________, KC_BSPC,
        _______, ________________SYMBOLS_L2_________________,                   ________________SYMBOLS_R2_________________, KC_DLR,
        _______, ________________SYMBOLS_L3_________________,                   ________________SYMBOLS_R3_________________, KC_TILD,
                                         KC_LGUI, KC_TRNS, SH_BKSP,        KC_ENTER, MO(_ADJUST), KC_RALT
    ),

    /* Raise
     * ,-----------------------------------------------. .-----------------------------------------------.
     * |   `   |   1   |   2   |   3   |   4   |   5   | |   6   |   7   |   8   |   9   |   0   |       |
     * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
     * |       |       |       |       |       |       | |       |   ←   |   ↑   |   ↓   |   →   |       |
     * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
     * |       |       |       |       |       |       | |       | home  |pg down| pg up |  end  |       |
     * `-----------------------.                       | |                       .-----------------------'
     *                         |-------+-------+-------| |-------+-------+-------|
     *                         |       |       |       | |       |       |       |
     *                         `-----------------------' '-----------------------'
     */
    [_NAVIGATE] = LAYOUT_wrapper( \
        _______, ________________NAVIGATE_L1________________,                    ________________NAVIGATE_R1________________, _______,
        _______, ________________NAVIGATE_L2________________,                    ________________NAVIGATE_R2________________, _______,
        KC_BRMD, ________________NAVIGATE_L3________________,                    ________________NAVIGATE_R3________________, _______,
                                       KC_LGUI, MO(_ADJUST), SH_BKSP,        KC_ENTER, _______, KC_RALT
    ),

    [_NUMPAD] = LAYOUT_wrapper(
        _______, _________________NUMPAD_L1_________________,                   _________________NUMPAD_R1_________________, KC_BSPC,
        _______, _________________NUMPAD_L2_________________,                   _________________NUMPAD_R2_________________, KC_MINS,
        _______, _________________NUMPAD_L3_________________,                   _________________NUMPAD_R3_________________, KC_RSFT,
                                        KC_LGUI, _______, SH_BKSP,        KC_ENTER, _______, KC_RALT
    ),

    

    [_ADJUST] = LAYOUT_wrapper( \
          RESET, _________________ADJUST_L1_________________,                         _________________ADJUST_R1_________________, _______,
        RGB_TOG, _________________ADJUST_L2_________________,                         _________________ADJUST_R2_________________, _______,
        RGB_MOD, _________________ADJUST_L3_________________,                         _________________ADJUST_R3_________________, _______,
                                            KC_LGUI, _______, SH_BKSP,        KC_ENTER, _______, KC_RALT
    )
    // clang-format on
};

// Tap Dance definitions
/* qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Left Shift, twice for Caps Lock
    [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
}; */

// Setting ADJUST layer RGB back to default
void update_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3, uint8_t layer4) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer4);
  } else {
    layer_off(layer4);
  }
}

// layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, _NUMPAD, _LOWER, _UPPER, _ADJUST); }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    /* static uint16_t my_colon_timer; */

    switch (keycode) {
        case NAVIGATE:
            if (record->event.pressed) {
                layer_on(_NAVIGATE);
                update_layer_RGB(_NAVIGATE, _SYMBOLS, _NUMPAD, _ADJUST);
            } else {
                layer_off(_NAVIGATE);
                update_layer_RGB(_NAVIGATE, _SYMBOLS, _NUMPAD, _ADJUST);
            }
            return false;
        case SYMBOLS:
            if (record->event.pressed) {
                layer_on(_SYMBOLS);
                update_layer_RGB(_NAVIGATE, _SYMBOLS, _NUMPAD, _ADJUST);
            } else {
                layer_off(_SYMBOLS);
                update_layer_RGB(_NAVIGATE, _SYMBOLS, _NUMPAD, _ADJUST);
            }
            return false;
        case NUMPAD:
            if (record->event.pressed) {
                layer_on(_NUMPAD);
                update_layer_RGB(_NAVIGATE, _SYMBOLS, _NUMPAD, _ADJUST);
            } else {
                layer_off(_NUMPAD);
                update_layer_RGB(_NAVIGATE, _SYMBOLS, _NUMPAD, _ADJUST);
            }
            return false;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        /* case KC_RACL:
            if (record->event.pressed) {
                my_colon_timer = timer_read();
                register_code(KC_RALT);
            } else {
                unregister_code(KC_RALT);
                if (timer_elapsed(my_colon_timer) < TAPPING_TERM) {
                SEND_STRING(":"); // Change the character(s) to be sent on tap here
                }
            }
                return false; */
        /* case RGBRST:
            #ifdef RGBLIGHT_ENABLE
                if (record->event.pressed) {
                eeconfig_update_rgblight_default();
                rgblight_enable();
                RGB_current_mode = rgblight_config.mode;
                }
            #endif
            #ifdef RGB_MATRIX_ENABLE
                if (record->event.pressed) {
                eeconfig_update_rgb_matrix_default();
                rgb_matrix_enable();
                }
            #endif 
        break; */

        case KC_LCTL:
        case KC_RCTL:
            #ifdef OCEAN_DREAM_ENABLE
                is_calm = (record->event.pressed) ? true : false;
            #endif
            #ifdef LUNA_ENABLE
                if (record->event.pressed) {
                    isSneaking = true;
                } else {
                    isSneaking = false;
                }
            #endif
        break;
        case KC_SPC:
            #ifdef LUNA_ENABLE
                if (record->event.pressed) {
                    isJumping  = true;
                    showedJump = false;
                } else {
                    isJumping = false;
                }
            #endif
        break;
        
    }
    return true;
}

// uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
//    switch (keycode) {
//        case ALT_T(KC_A):
//        case SH_BKSP:
//            return TAPPING_TERM + 500;
//        default:
//            return TAPPING_TERM;
//    }
//}
//
// bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
//    switch (keycode) {
//        case ALT_T(KC_A):
//        case SH_BKSP:
//            return true;
//        default:
//            return false;
//    }
//}