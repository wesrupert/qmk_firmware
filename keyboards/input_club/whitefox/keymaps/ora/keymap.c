// Copyright 2023 Wes Rupert (@wesrupert)
// SPDX-License-Identifier: GPL-3.0-or-later
#include "ora.h"

// Expand key groups before passing into layout macro.
#define L(...) LAYOUT(__VA_ARGS__)
#define MT_LCRA C(KC_LALT)

enum tap_dances {
    TAP_DANCE_PLAY_PAUSE_SPOTIFY = 0,
    TAP_DANCE_DYN_MACRO_1,
    TAP_DANCE_DYN_MACRO_2,
    TAP_DANCE_LEADER_LCTL,
    TAP_DANCE_LEADER_RCTL,
    TAP_DANCE_NUMPAD_LALT,
    X_TAP_DANCE
};

// Common tap dances
#define TD_DMC1 TD(TAP_DANCE_DYN_MACRO_1)
#define TD_DMC2 TD(TAP_DANCE_DYN_MACRO_2)
#define TD_LCLD TD(TAP_DANCE_LEADER_LCTL)
#define TD_RCLD TD(TAP_DANCE_LEADER_RCTL)
#define TD_LANP TD(TAP_DANCE_NUMPAD_LALT)

// XY_ABCD alternates
#define _M_ KC_NO

// clang-format off

#define __BASE \
    KC_GRV,  ______________________QWER__L1______________________, _____________QWER__R1_____________, KC_MINS, KC_EQL , KC_BSPC, KC_DEL , TD_DMC1, \
    KC_TAB,    __________________QWER_L2__________________, __________________QWER_R2__________________, KC_LBRC, KC_RBRC,     KC_BSLS,    KC_MPLY, \
    LT_FNES,     __________________QWER_L3__________________, _____________QWER__R3_____________, KC_SCLN, KC_QUOT,    _M_, LT_SYEN,       PK_MNXT, \
    KC_LSFT, _M_,   __________________QWER_L4__________________, __________________QWER_R4__________________,      KC_RSFT,       KC_UP,   PK_MPRV, \
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
    KC_MEH,    KC_LALT,   MT_LCRA,                        _______,                        KC_RGUI,   TD_RCLD,    _M_,    _______, _______, _______

#define __SYMBOLS \
    KC_TILD, ______________________SYMB__L1______________________, ______________________SYMB__R1______________________, _______, _______, _______, \
    _______,   __________________SYMB_L2__________________, __________________SYMB_R2__________________, KC_LPRN, KC_RPRN,     _______,    _______, \
    _______,     __________________SYMB_L3__________________, __________________SYMB_R3__________________, KC_DQUO,    _M_,  _______,      _______, \
    _______, _M_,   __________________SYMB_L4__________________, __________________SYMB_R4__________________,      _______,       _______, _______, \
    _______,   _______,   _______,                        _______,                        _______,   _______,    _M_,    _______, _______, _______  \

#define __FUNCTION \
    PK_LOCK, ______________________FUNC__L1______________________, ______________________FUNC__R1______________________, KC_DEL , TD_DMC2, PK_LOCK, \
    KC_CAPS,   XXXXXXX, _____________FUNC__L2_____________, _____________FUNC__R2_____________,  PK_PSCR,  PK_PSCF,XXXXXXX,    XXXXXXX,    PK_MUTE, \
    XXXXXXX,     XXXXXXX, _____________FUNC__L3_____________, _____________FUNC__R3_____________, XXXXXXX, XXXXXXX,    _M_, _______,       PK_VOLU, \
    _______, _M_,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TT_NMPD, XXXXXXX, __________VOLUM__________,      _______,       KC_PGUP, PK_VOLD, \
    _______,   _______,   _______,                        _______,                        _______,   _______,    _M_,    KC_HOME, KC_PGDN, KC_END

/* #define __LAYER \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______,    _______, \
    _______,     _______, _______, _______, ___F___, _______, _______, ___J___, _______, _______, _______, _______,    _M_, _______,       _______, \
    _______, _M_,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______,       _______, _______, \
    _______,   _______,   _______,                        _______,                        _______,   _______,    _M_,    _______, _______, _______ */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_BASE] = L(__BASE),
    [LAYER_NUMPAD] = L(__NUMPAD),
    [LAYER_GAMES] = L(__GAMES),
    [LAYER_SYMBOLS] = L(__SYMBOLS),
    [LAYER_FUNCTION] = L(__FUNCTION),
};

// clang-format on

DANCE_SPOTIFY
DANCE_MCRO(1, l, L, gui, GUI)
DANCE_MCRO(2, r, R, gui, GUI)
DANCE_LEAD(l, L, ctl, CTL)
DANCE_LEAD(r, R, ctl, CTL)
DANCE_NUMP(l, L, alt, ALT)

tap_dance_action_t tap_dance_actions[] = {
    [TAP_DANCE_PLAY_PAUSE_SPOTIFY] = ACTION_TAP_DANCE_FN(dance_playpause_spotify),
    [TAP_DANCE_DYN_MACRO_1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_dm_1_l_gui_finished, dance_dm_1_l_gui_reset),
    [TAP_DANCE_DYN_MACRO_2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_dm_2_r_gui_finished, dance_dm_2_r_gui_reset),
    [TAP_DANCE_LEADER_LCTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_lead_l_ctl_finished, dance_lead_l_ctl_reset),
    [TAP_DANCE_LEADER_RCTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_lead_r_ctl_finished, dance_lead_r_ctl_reset),
    [TAP_DANCE_NUMPAD_LALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_nump_l_alt_finished, dance_nump_l_alt_reset),
};
