// Copyright 2022 Wes Rupert (@wesrupert)
// SPDX-License-Identifier: GPL-3.0-or-later

#include QMK_KEYBOARD_H
#include "ora.h"
#include "version.h"

#define MC_FNES LT(LAYER_MACFUN, KC_ESC)
#define WN_FNES LT(LAYER_WINFUN, KC_ESC)
#define LT_SYEN LT(LAYER_SYMBOLS, KC_ENT)
#define TT_NMPD TT(LAYER_NUMPAD)
#define MT_LCES LCTL_T(KC_ESC)
#define MT_RCES RCTL_T(KC_ESC)
#define MT_LSSP LSFT_T(KC_SPC)
#define MT_RSSP RSFT_T(KC_SPC)
#define MT_LSEN LSFT_T(KC_ENT)
#define MT_RSEN RSFT_T(KC_ENT)

// Expand key groups before passing into layout macro.
#define L(...) LAYOUT_ergodox_pretty(__VA_ARGS__)

// clang-format off

// __{LAYER} macros so we can use set_single_persistent_default_layer without writing the base layer twice.
// ...Not that it does anything for this profile, it doesn't look like Hotdox v1 has EEPROM support?

#define __BASE(OS) \
    KC_DEL,  ______________________QWER__L1______________________,    _____________QWER__R1_____________, KC_LBRC, KC_RBRC, KC_BSPC, \
    KC_TAB,  __________________QWER_L2__________________, KC_MINS,    KC_EQL,  __________________QWER_R2__________________, KC_BSLS, \
    MT_LCES, __________________QWER_L3__________________,                      _____________QWER__R3_____________, KC_QUOT, MT_RCES, \
    MT_LSEN, __________________QWER_L4__________________, KC_GRV,     KC_SCLN, __________________QWER_R4__________________, MT_RSEN, \
    KC_MEH ,_________MDIA_##OS##_________,KC_LGUI,                                      KC_RGUI, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, \
                                                 TD_DMC1, TD_LANP,    TD_RANP, TD_DMC2,          \
                                        /*-----\ /-----*/ TD_LCLD,    TD_RCLD, /*-----\ /-----*/ \
                                        MT_LSSP, LT_SYEN,OS##_FNES,  OS##_FNES,LT_SYEN, MT_RSSP

#define __NUMPAD \
    KC_BSPC, ______________NMPD_1______________, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, ______________NMPD_1______________, KC_BSPC, \
    KC_TAB,  ______________NMPD_2______________, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, ______________NMPD_2______________, KC_TAB,  \
    _______, ______________NMPD_3______________, KC_UP,                        KC_UP,   ______________NMPD_3______________, _______, \
    _______, __________NMPD_4_________,KC_LEFT,  KC_DOWN, KC_RGHT,    KC_LEFT, KC_DOWN, KC_RGHT, __________NMPD_4_________, _______, \
    _______, _____NMPD_5_____, KC_PEQL, KC_PENT,                                        KC_PENT, KC_PEQL, _____NMPD_5_____, _______, \
                                                  _______, _______,    _______, _______, \
                                         /*-----\ /-----*/ _______,    _______, /*-----\ /-----*/ \
                                         KC_SPC,  KC_PENT, _______,    _______, KC_PENT, KC_SPC

#define __GAMES \
    KC_F12,  _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, \
    KC_TAB,  _______, _______, _______, _______, _______, KC_F10,     _______, _______, _______, _______, _______, _______, _______, \
    KC_LCTL, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, \
    KC_LSFT, _______, _______, _______, _______, _______, KC_F11,     _______, _______, _______, _______, _______, _______, _______, \
    KC_LALT, KC_F1,   KC_F2,   KC_F3,   KC_F4,                                          _______, _______, _______, _______, _______, \
                                                 KC_F6,   KC_F7,      WN_MPLY, WN_MNXT, \
                                        /*-----\ /-----*/ KC_F8,      TD_RCLD, /*-----\ /-----*/ \
                                        KC_SPC,  KC_F5,   KC_F9,      _______, _______, _______

#define __SYMBOLS \
    _______, ______________________SYMB__L1______________________,    ______________________SYMB__R1______________________, _______, \
    _______, __________________SYMB_L2__________________, KC_UNDS,    KC_PLUS, __________________SYMB_R2__________________, _______, \
    _______, __________________SYMB_L3__________________,                      __________________SYMB_R3__________________, _______, \
    _______, __________________SYMB_L4__________________, KC_TILD,    KC_COLN, __________________SYMB_R4__________________, _______, \
    _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, \
                                                 _______, _______,    _______, _______, \
                                        /*-----\ /-----*/ _______,    _______, /*-----\ /-----*/ \
                                        _______, _______, _______,    _______, _______, _______

#define __FUNCTION(OS) \
    KC_ESC,  ______________________FUNC__L1______________________,    ______________________FUNC__R1______________________, KC_DEL,  \
    XXXXXXX, XXXXXXX, _____________FUNC__L2_____________, XXXXXXX,    XXXXXXX, _____________FUNC__R2_____________,OS##_PSCR,KC_CAPS, \
    KC_CAPS,OS##_SALL,_____________FUNC__L3_____________,                      _____________FUNC__R3_____________,OS##_PSCF,KC_RCTL, \
    CW_TOGG,OS##_UNDO,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, TT_NMPD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CW_TOGG, \
    _______,_________VOLM_##OS##_________,_______,                                  TD_PLPS,OS##_MPRV,OS##_VOLD,OS##_VOLU,OS##_MNXT, \
                                                OS##_LOCK,_______,    _______,OS##_LOCK,         \
                                        /*-----\ /-----*/ _______,    _______, /*-----\ /-----*/ \
                                        _______, _______, _______,    _______, _______, _______

/* #define __LAYER \
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, \
                                                 _______, _______,     _______, _______, \
                                        / *-----\ /-----* / _______,     _______, / *-----\ /-----* / \
                                        _______, _______, _______,     _______, _______, _______
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_WIN] = L(__BASE(WN)),
    [LAYER_MAC] = L(__BASE(MC)),
    [LAYER_NUMPAD] = L(__NUMPAD),
    [LAYER_GAMES] = L(__GAMES),
    [LAYER_SYMBOLS] = L(__SYMBOLS),
    [LAYER_WINFUN] = L(__FUNCTION(WN)),
    [LAYER_MACFUN] = L(__FUNCTION(MC))
};

// clang-format off

// vim: foldmethod=marker cursorcolumn
