#include QMK_KEYBOARD_H
#include "ora.h"
#include "version.h"

#define LT_FNES LT(LAYER_FUNCTION, KC_ESC)
#define LT_WFNE LT(LAYER_WINFUN, KC_ESC)
#define LT_SYEN LT(LAYER_SYMBOLS, KC_ENT)
#define LT_NMPD TT(LAYER_NUMPAD)
#define MT_LSSP LSFT_T(KC_SPC)
#define MT_RSSP RSFT_T(KC_SPC)
#define MT_LCES LCTL_T(KC_ESC)
#define MT_RCEN RCTL_T(KC_ENT)

// Expand key groups before passing into layout macro.
#define LAYOUT_wrapper(...) LAYOUT_ergodox_pretty(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LAYER_BASE] = LAYOUT_wrapper( // {{{
    KC_DEL,                  __QWER_L1__,                                             __QWER_R1__,        KC_LBRC, KC_RBRC, KC_BSPC,
    KC_TAB,                  __QWER_L2__,                 KC_MINS,    KC_EQL,         __QWER_R2__,                          KC_BSLS,
    MT_LCES,                 __QWER_L3__,                                             __QWER_R3__,                 KC_QUOT, MT_RCEN,
    KC_LSFT,                 __QWER_L4__,                 KC_GRV,     KC_SCLN,        __QWER_R4__,                          KC_RSFT,
    KC_LALT,        __MDIA_MC__,        KC_LGUI,                                        KC_RGUI, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
                                                 LT_NMPD, TD_DMC1,    TD_DMC2, KC_LOCK,
                                        /*-----\ /-----*/ KC_LEAD,    KC_LEAD, /*-----\ /-----*/
                                        MT_LSSP, LT_SYEN, LT_FNES,    LT_FNES, LT_SYEN, MT_RSSP),
// }}}
[LAYER_WIN] = LAYOUT_wrapper( // {{{
    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
    _______,        __MDIA_WN__,        _______,                                        _______, _______, _______, _______, _______,
                                                 _______, _______,    _______, _______,
                                        /*-----\ /-----*/ _______,    _______, /*-----\ /-----*/
                                        _______, _______, LT_WFNE,    LT_WFNE, _______, _______),
// }}}
[LAYER_GAMES] = LAYOUT_wrapper( // {{{
    KC_GRV,  _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
    KC_LCTL, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_HOME,    _______, _______, _______, _______, _______, _______, _______,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                          _______, _______, _______, _______, _______,
                                                 WN_MPLY, WN_MNXT,    _______, _______,
                                        /*-----\ /-----*/ LT_WFNE,    _______, /*-----\ /-----*/
                                        KC_SPC,  KC_LALT, KC_ESC,     _______, _______, _______),
// }}}
[LAYER_FUNCTION] = LAYOUT_wrapper( // {{{
    KC_ESC,                  __FUNC_L1__,                                                      __FUNC_R1__,                 RESET,
    KC_CAPS, XXXXXXX,        __FUNC_L2__,                 XXXXXXX,    XXXXXXX,                 __FUNC_R2__,        MC_PSCR, KC_CAPS,
    KC_LCTL, XXXXXXX,        __FUNC_L3__,                                                      __FUNC_R3__,        MC_PSCF, KC_RCTL,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______,        __VOLM_MC__,        _______,                                        TD_MPLS, MC_MPRV, MC_VOLD, MC_VOLU, MC_MNXT,
                                                 _______, _______,    _______, MC_LOCK,
                                        /*-----\ /-----*/ _______,    _______, /*-----\ /-----*/
                                        _______, _______, _______,    _______, _______, _______),
// }}}
[LAYER_WINFUN] = LAYOUT_wrapper( // {{{
    KC_ESC,                  __FUNC_L1__,                                                      __FUNC_R1__,                 RESET,
    KC_CAPS, XXXXXXX,        __FUNC_L2__,                 XXXXXXX,    XXXXXXX,                 __FUNC_R2__,        MC_PSCR, KC_CAPS,
    KC_LCTL, XXXXXXX,        __FUNC_L3__,                                                      __FUNC_R3__,        MC_PSCF, KC_RCTL,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______,        __VOLM_WN__,        _______,                                        TD_WPLS, WN_MPRV, WN_VOLD, WN_VOLU, WN_MNXT,
                                                 _______, _______,    _______, WN_LOCK,
                                        /*-----\ /-----*/ _______,    _______, /*-----\ /-----*/
                                        _______, _______, _______,    _______, _______, _______),
// }}}
[LAYER_SYMBOLS] = LAYOUT_wrapper( // {{{
    _______,                               __SYMB_L1__,                          __SYMB_R1__,                               _______,
    _______,                 __SYMB_L2__,                 KC_UNDS,    KC_PLUS,                 __SYMB_R2__,                 _______,
    _______,                 __SYMB_L3__,                                                      __SYMB_R3__,                 _______,
    _______,                 __SYMB_L4__,                 KC_TILD,    KC_COLN,                 __SYMB_R4__,                 _______,
    _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______,
                                                 _______, _______,    _______, _______,
                                        /*-----\ /-----*/ _______,    _______, /*-----\ /-----*/
                                        _______, _______, _______,    _______, _______, _______),
// }}}
[LAYER_NUMPAD] = LAYOUT_wrapper( // {{{
     XXXXXXX,             __NMPD_L1__,            XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,            __NMPD_R1__,             XXXXXXX,
     KC_NLCK,             __NMPD_L2__,            XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,            __NMPD_R2__,             KC_NLCK,
     _______,             __NMPD_L3__,            XXXXXXX,                      XXXXXXX,            __NMPD_R3__,             _______,
     _______,             __NMPD_L4__,            XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,            __NMPD_R4__,             _______,
     _______,             __NMPD_L5__,            XXXXXXX,                      XXXXXXX,            __NMPD_R5__,             _______,
                                                  _______, _______,    _______, _______,
                                         /*-----\ /-----*/ _______,    _______, /*-----\ /-----*/
                                         KC_SPC,  KC_PENT, _______,    _______, KC_PENT, KC_SPC)
// }}}
//[LAYER_] = LAYOUT_wrapper( // {{{
//    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
//    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
//    _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
//    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
//    _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______,
//                                                 _______, _______,    _______, _______,
//                                        /*-----\ /-----*/ _______,    _______, /*-----\ /-----*/
//                                        _______, _______, _______,    _______, _______, _______) COMMA???
//// }}}
};


// vim: foldmethod=marker cursorcolumn
