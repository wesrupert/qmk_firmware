// Copyright 2022 Wes Rupert (@wesrupert)
// SPDX-License-Identifier: GPL-3.0-or-later

#include QMK_KEYBOARD_H
#include "ora.h"
#include "version.h"

#define MC_FNES LT(LAYER_MACFUN, KC_ESC)
#define WN_FNES LT(LAYER_WINFUN, KC_ESC)
#define LT_SYEN LT(LAYER_SYMBOLS, KC_ENT)

// Expand key groups before passing into layout macro.
#define L(...) LAYOUT(__VA_ARGS__)
#define MT_LCLA C(KC_LALT)

// clang-format off

// __{LAYER} macros so we can use set_single_persistent_default_layer without writing the base layer twice. {{{

#define __BASE(OS) \
    KC_GRV,                        __QWER_L1__,                   __QWER_R1__,                KC_MINS,KC_EQL, KC_BSPC,KC_DEL,TD_DMC1,   \
    KC_TAB,                        __QWER_L2__,                   __QWER_R2__,                  KC_LBRC,KC_RBRC,KC_BSLS,     OS##_MPLY, \
    OS##_FNES,                     __QWER_L3__,                   __QWER_R3__,            KC_SCLN,KC_QUOT,__MIS__,  LT_SYEN, OS##_MNXT, \
    KC_LSFT,__MIS__,               __QWER_L4__,                   __QWER_R4__,                           KC_RSFT,     KC_UP, OS##_MPRV, \
    KC_LCTL,KC_LALT,KC_LGUI,                       KC_SPC,                         KC_RGUI,TD_RCLD,__MIS__,  KC_LEFT,KC_DOWN,KC_RGHT

#define __FUNCTION(OS) \
    OS##_LOCK,                     __FUNC_L1__,                   __FUNC_R1__,                                KC_DEL, TD_DMC2,OS##_LOCK, \
    KC_CAPS,XXXXXXX,               __FUNC_L2__,                   __FUNC_R2__,      OS##_PSCR,OS##_PSCF,XXXXXXX,XXXXXXX,      OS##_MUTE, \
    XXXXXXX,OS##_SALL,             __FUNC_L3__,                   __FUNC_R3__,            XXXXXXX,XXXXXXX,__MIS__,  _______,  OS##_VOLU, \
    _______,__MIS__,OS##_UNDO,   __CLIP_##OS##__,   XXXXXXX,XXXXXXX,XXXXXXX,    __VOLM_##OS##__,         _______,     KC_PGUP,OS##_VOLD, \
    _______,_______,_______,                        _______,                        _______,_______,__MIS__,  KC_HOME,KC_PGDN,KC_END

// }}}

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LAYER_WIN] = L(__BASE(WN)),
[LAYER_WINFUN] = L(__FUNCTION(WN)),
[LAYER_MAC] = L(__BASE(MC)),
[LAYER_MACFUN] = L(__FUNCTION(MC)),
[LAYER_GAMES] = L( // {{{
    _______,  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_ESC,
    _______,    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,      _______,
    KC_LCTL,      _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,__MIS__,  _______,  _______,
    KC_LSFT,__MIS__,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     _______,     _______,_______,
    KC_LALT,KC_MEH ,MT_LCLA,                         _______,                        KC_RGUI,_______,__MIS__,  _______,_______,_______),
// }}}
[LAYER_SYMBOLS] = L( // {{{
    KC_TILD,                       __SYMB_L1__,                   __SYMB_R1__,                                _______,_______,_______,
    _______,                       __SYMB_L2__,                   __SYMB_R2__,                  KC_LPRN,KC_RPRN,_______,      _______,
    _______,                       __SYMB_L3__,                   __SYMB_R3__,                    KC_DQUO,__MIS__,  _______,  _______,
    _______,__MIS__,               __SYMB_L4__,                   __SYMB_R4__,                           _______,     _______,_______,
    _______,_______,_______,                        _______,                        _______,_______,__MIS__,  _______,_______,_______),
// }}}
[LAYER_NUMPAD] = L( // {{{
    KC_NLCK,           __NMPD_L1__,           XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,
    KC_BSPC,           __NMPD_L2__,             XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,      XXXXXXX,
    _______,           __NMPD_L3__,               XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,__MIS__,  _______,  _______,
    _______,__MIS__,   __NMPD_L4__,                 XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,     _______,     _______,_______,
    _______,           __NMPD_L5__,                                                 KC_P0,  KC_PDOT,__MIS__,  _______,_______,_______),
// }}}
/* [LAYER_TYPE] = L( // {{{
    _______,  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,      _______,
    _______,      _______,_______,_______,___F___,_______,_______,___J___,_______,_______,_______,_______,__MIS__,  _______,  _______,
    _______,__MIS__,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     _______,     _______,_______,
    _______,_______,_______,                        _______,                        _______,_______,__MIS__,  _______,_______,_______), */
// }}}
};

// clang-format on

// vim: foldmethod=marker cursorcolumn
