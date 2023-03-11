// Copyright 2023 Wes Rupert (@wesrupert)
// SPDX-License-Identifier: GPL-3.0-or-later
#include "ora.h"

#define MC_FNES LT(LAYER_MACFUN, KC_ESC)
#define WN_FNES LT(LAYER_WINFUN, KC_ESC)
#define LT_SYEN LT(LAYER_SYMBOLS, KC_ENT)
#define TT_NMPD TT(LAYER_NUMPAD)

// Expand key groups before passing into layout macro.
#define L(...) LAYOUT(__VA_ARGS__)
#define MT_LCLA C(KC_LALT)

// XY_ABCD alternates
#define _M_ KC_NO

// __{LAYER} macros so we can use OS-variant keys without writing the layers twice.
// clang-format off

#define __BASE(OS) \
    KC_GRV,  ______________________QWER__L1______________________, _____________QWER__R1_____________, KC_MINS, KC_EQL , KC_BSPC, KC_DEL , TD_DMC1, \
    KC_TAB,    __________________QWER_L2__________________, __________________QWER_R2__________________, KC_LBRC, KC_RBRC,     KC_BSLS,    OS##_MPLY, \
    OS##_FNES,   __________________QWER_L3__________________, _____________QWER__R3_____________, KC_SCLN, KC_QUOT,    _M_, LT_SYEN,       OS##_MNXT, \
    KC_LSFT, _M_,   __________________QWER_L4__________________, __________________QWER_R4__________________,      KC_RSFT,       KC_UP,   OS##_MPRV, \
    TD_LCLD,   TD_LANP,   KC_LGUI,                        KC_SPC,                         KC_RGUI,   TD_RCLD,    _M_,    KC_LEFT, KC_DOWN, KC_RGHT

#define __NUMPAD \
    KC_BSPC, ______________NMPD_1______________, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    KC_TAB ,   ______________NMPD_2______________, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,    XXXXXXX, \
    _______,     ______________NMPD_3______________, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    _M_, _______,       _______, \
    _______, _M_,   __________NMPD_4_________, KC_PDOT, KC_PEQL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      _______,       _______, _______, \
    _______,   _______,   KC_P0  ,                        KC_PENT,                        XXXXXXX,   XXXXXXX,    _M_,    _______, _______, _______  \

#define __GAMES \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_ESC,  \
    _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______,    _______, \
    KC_LCTL,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _M_, _______,       _______, \
    KC_LSFT, _M_,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______,       _______, _______, \
    KC_LALT,   KC_MEH ,   MT_LCLA,                        _______,                        KC_RGUI,   TD_RCLD,    _M_,    _______, _______, _______

#define __SYMBOLS \
    KC_TILD, ______________________SYMB__L1______________________, ______________________SYMB__R1______________________, _______, _______, _______, \
    _______,   __________________SYMB_L2__________________, __________________SYMB_R2__________________, KC_LPRN, KC_RPRN,     _______,    _______, \
    _______,     __________________SYMB_L3__________________, __________________SYMB_R3__________________, KC_DQUO,    _M_,  _______,      _______, \
    _______, _M_,   __________________SYMB_L4__________________, __________________SYMB_R4__________________,      _______,       _______, _______, \
    _______,   _______,   _______,                        _______,                        _______,   _______,    _M_,    _______, _______, _______  \

#define __FUNCTION(OS) \
    OS##_LOCK,______________________FUNC__L1______________________,______________________FUNC__R1______________________, KC_DEL , TD_DMC2, OS##_LOCK, \
    KC_CAPS,   XXXXXXX, _____________FUNC__L2_____________, _____________FUNC__R2_____________,OS##_PSCR,OS##_PSCF,XXXXXXX,    XXXXXXX,    OS##_MUTE, \
    XXXXXXX,   OS##_SALL, _____________FUNC__L3_____________, _____________FUNC__R3_____________, XXXXXXX, XXXXXXX,    _M_, _______,       OS##_VOLU, \
    _______, _M_, OS##_UNDO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TT_NMPD, XXXXXXX, _________VOLM_##MC##_________,  _______,       KC_PGUP, OS##_VOLD, \
    _______,   _______,   _______,                        _______,                        _______,   _______,    _M_,    KC_HOME, KC_PGDN, KC_END

/* #define __LAYER \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______,    _______, \
    _______,     _______, _______, _______, ___F___, _______, _______, ___J___, _______, _______, _______, _______,    _M_, _______,       _______, \
    _______, _M_,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______,       _______, _______, \
    _______,   _______,   _______,                        _______,                        _______,   _______,    _M_,    _______, _______, _______ */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_WIN] = L(__BASE(WN)),
    [LAYER_MAC] = L(__BASE(MC)),
    [LAYER_NUMPAD] = L(__NUMPAD),
    [LAYER_GAMES] = L(__GAMES),
    [LAYER_SYMBOLS] = L(__SYMBOLS),
    [LAYER_WINFUN] = L(__FUNCTION(WN)),
    [LAYER_MACFUN] = L(__FUNCTION(MC))
};

// clang-format on
