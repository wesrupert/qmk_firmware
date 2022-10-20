// Copyright 2022 Wes Rupert (@wesrupert)
// SPDX-License-Identifier: GPL-3.0-or-later

#include QMK_KEYBOARD_H
#include "ora.h"
#include "version.h"

#define MC_FNES LT(LAYER_MACFUN, KC_ESC)
#define WN_FNES LT(LAYER_WINFUN, KC_ESC)
#define LT_SYEN LT(LAYER_SYMBOLS, KC_ENT)
#define LT_NMPD TT(LAYER_NUMPAD)
#define MT_LSSP LSFT_T(KC_SPC)
#define MT_RSSP RSFT_T(KC_SPC)
#define MT_LCES LCTL_T(KC_ESC)
#define MT_RCEN RCTL_T(KC_ENT)

// Expand key groups before passing into layout macro.
#define L(...) LAYOUT_ergodox_pretty(__VA_ARGS__)

// clang-format off

// __{LAYER} macros so we can use set_single_persistent_default_layer without writing the base layer twice. {{{
// ...Not that it does anything for this profile, it doesn't look like Hotdox v1 has EEPROM support?

#define __BASE(OS) \
    KC_DEL,                  __QWER_L1__,                                             __QWER_R1__,        KC_LBRC, KC_RBRC, KC_BSPC, \
    KC_TAB,                  __QWER_L2__,                 KC_MINS,    KC_EQL,         __QWER_R2__,                          KC_BSLS, \
    MT_LCES,                 __QWER_L3__,                                             __QWER_R3__,                 KC_QUOT, MT_RCEN, \
    KC_LSFT,                 __QWER_L4__,                 KC_GRV,     KC_SCLN,        __QWER_R4__,                          KC_RSFT, \
    KC_LALT,      __MDIA_##OS##__,      KC_LGUI,                                        KC_RGUI, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, \
                                                 LT_NMPD, TD_DMC1,    TD_DMC2, KC_LOCK,          \
                                        /*-----\ /-----*/ TD_LCLD,    TD_RCLD, /*-----\ /-----*/ \
                                        MT_LSSP, LT_SYEN, OS##_FNES,OS##_FNES, LT_SYEN, MT_RSSP

#define __FUNCTION(OS) \
    KC_ESC,                  __FUNC_L1__,                                                      __FUNC_R1__,                 KC_DEL,  \
    XXXXXXX, XXXXXXX,        __FUNC_L2__,                 XXXXXXX,    XXXXXXX,                 __FUNC_R2__,      OS##_PSCR, KC_CAPS, \
    KC_CAPS, OS##_SALL,      __FUNC_L3__,                                                      __FUNC_R3__,      OS##_PSCF, KC_RCTL, \
    _______, OS##_UNDO,    __CLIP_##OS##__,      XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    _______,      __VOLM_##OS##__,      _______,                                      TD_PLPS,OS##_MPRV,OS##_VOLD,OS##_VOLU,OS##_MNXT, \
                                                 _______, _______,    _______, OS##_LOCK,        \
                                        /*-----\ /-----*/ _______,    _______, /*-----\ /-----*/ \
                                        _______, _______, _______,    _______, _______, _______

// }}}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LAYER_WIN] = L(__BASE(WN)),
[LAYER_WINFUN] = L(__FUNCTION(WN)),
[LAYER_MAC] = L(__BASE(MC)),
[LAYER_MACFUN] = L(__FUNCTION(MC)),
[LAYER_GAMES] = L( // {{{
    KC_GRV,  _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
    KC_LCTL, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_HOME,    _______, _______, _______, _______, _______, _______, _______,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                          _______, _______, _______, _______, _______,
                                                 WN_MPLY, WN_MNXT,    _______, _______,
                                        /*-----\ /-----*/ WN_FNES,    _______, /*-----\ /-----*/
                                        KC_SPC,  KC_LALT, KC_ESC,     _______, _______, _______),
// }}}
[LAYER_SYMBOLS] = L( // {{{
    _______,                               __SYMB_L1__,                          __SYMB_R1__,                               _______,
    _______,                 __SYMB_L2__,                 KC_UNDS,    KC_PLUS,                 __SYMB_R2__,                 _______,
    _______,                 __SYMB_L3__,                                                      __SYMB_R3__,                 _______,
    _______,                 __SYMB_L4__,                 KC_TILD,    KC_COLN,                 __SYMB_R4__,                 _______,
    _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______,
                                                 _______, _______,    _______, _______,
                                        /*-----\ /-----*/ _______,    _______, /*-----\ /-----*/
                                        _______, _______, _______,    _______, _______, _______),
// }}}
[LAYER_NUMPAD] = L( // {{{
     XXXXXXX,             __NMPD_L1__,            XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,            __NMPD_R1__,             XXXXXXX,
     KC_NLCK,             __NMPD_L2__,            XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,            __NMPD_R2__,             KC_NLCK,
     _______,             __NMPD_L3__,            XXXXXXX,                      XXXXXXX,            __NMPD_R3__,             _______,
     _______,             __NMPD_L4__,            XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,            __NMPD_R4__,             _______,
     _______,             __NMPD_L5__,            XXXXXXX,                      XXXXXXX,            __NMPD_R5__,             _______,
                                                  _______, _______,    _______, _______,
                                         /*-----\ /-----*/ _______,    _______, /*-----\ /-----*/
                                         KC_SPC,  KC_PENT, KC_BSPC,    KC_BSPC, KC_PENT, KC_SPC)
// }}}
//[LAYER_] = L( // {{{
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

// clang-format off

// vim: foldmethod=marker cursorcolumn
