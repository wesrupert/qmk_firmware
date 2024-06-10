// Copyright 2023 Wes Rupert (@wesrupert)
// SPDX-License-Identifier: GPL-3.0-or-later
#include "ora.h"
#include "g/keymap_combo.h"

enum layers {
    LAYER_SYMBOLS = LAYER_ENUM_END_USER,
    LAYER_FUNCTION,
    LAYER_NUMPAD,
    LAYER_ENUM_END,
};

enum tap_dances {
    TAP_DANCE_DMACRO_ESC = 0,
    TAP_DANCE_LEADER_RGUI,
    TAP_DANCE_NUMPAD_RCTL,
    X_TAP_DANCE
};

// Advance key aliases
#define TT_NMPD TT(LAYER_NUMPAD)
#define LT_FNES LT(LAYER_FUNCTION, KC_ESC)
#define LT_SYEN LT(LAYER_SYMBOLS, KC_ENT)

#define TD_RGLD TD(TAP_DANCE_LEADER_RGUI)
#define TD_RCNP TD(TAP_DANCE_NUMPAD_RCTL)
#define TD_ESMC TD(TAP_DANCE_DMACRO_ESC)

// XY_ABCD alternates
#define _M_ KC_NO

// Expand key groups before passing into layout macro.
#define L(...) LAYOUT(__VA_ARGS__)

// clang-format off


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LAYER_BASE] = L(
    KC_GRV,  __________________QWER_L1__________________, __________________QWER_R1__________________, KC_MINS, KC_EQL , KC_BSPC, KC_DEL , TD_ESMC,
    KC_TAB,    __________________QWER_L2__________________, __________________QWER_R2__________________, KC_LBRC, KC_RBRC,     KC_BSLS,    KC_MPLY,
    LT_FNES,     __________________QWER_L3__________________, _____________QWER__R3_____________, KC_SCLN, KC_QUOT,    _M_, LT_SYEN,       PK_MNXT,
    KC_LSFT, _M_,   __________________QWER_L4__________________, __________________QWER_R4__________________,      KC_RSFT,       KC_UP,   PK_MPRV,
    KC_LCTL,   KC_LALT,   KC_LGUI,                        KC_SPC,                         TD_RGLD,   TD_RCNP,    _M_,    KC_LEFT, KC_DOWN, KC_RGHT)
,
[LAYER_GAMES] = L(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_ESC,
    _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______,    _______,
    KC_LCTL,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _M_, _______,       _______,
    KC_LSFT, _M_,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______,       _______, _______,
    KC_MEH,    KC_LALT,   KC_LCTL,                        _______,                        _______,   _______,    _M_,    _______, _______, _______)
,
[LAYER_NUMPAD] = L(
    KC_BSPC, KC_NUM,  KC_PSLS, KC_PAST, KC_PPLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TT_NMPD,
    KC_TAB ,   __________NMPD_1_________, KC_PMNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,    XXXXXXX,
    KC_PENT,     __________NMPD_2_________, KC_PEQL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    _M_, _______,       _______,
    KC_LSFT, _M_,   __________NMPD_3_________, KC_PEQL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      _______,       _______, _______,
    KC_LCTL,   KC_PDOT,   NMPD__4,                        KC_PENT,                        XXXXXXX,   XXXXXXX,    _M_,    _______, _______, _______)
,
[LAYER_SYMBOLS] = L(
    KC_TILD, __________________SYMB_L1__________________, SYM_SL1, SYM_SR1, __________________SYMB_R1__________________, _______, _______, _______,
    _______,   __________________SYMB_L2__________________, __________________SYMB_R2__________________, KC_LPRN, KC_RPRN,     _______,    _______,
    KC_BSPC,     __________________SYMB_L3__________________, __________________SYMB_R3__________________, KC_DQUO,    _M_,  _______,      _______,
    _______, _M_,   __________________SYMB_L4__________________, __________________SYMB_R4__________________,      _______,       _______, _______,
    _______,   _______,   _______,                        _______,                        _______,   _______,    _M_,    _______, _______, _______)
,
[LAYER_FUNCTION] = L(
    PK_LOCK, __________________FUNC_L1__________________, __________________FUNC_R1__________________, FUNC_11, FUNC_12, _______, _______, PK_LOCK,
    KC_CAPS,   XXXXXXX, _____________FUNC__L2_____________, _____________FUNC__R2_____________,  PK_PSCR,  PK_PSCF,XXXXXXX,    XXXXXXX,    PK_MUTE,
    XXXXXXX,     XXXXXXX, _____________FUNC__L3_____________, _____________FUNC__R3_____________, XXXXXXX, XXXXXXX,    _M_, KC_DEL,        PK_VOLU,
    _______, _M_,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TT_NMPD, XXXXXXX, __________VOLUM__________,      _______,       KC_PGUP, PK_VOLD,
    _______,   _______,   _______,                        _______,                        _______,   _______,    _M_,    KC_HOME, KC_PGDN, KC_END)
,
/* [LAYER_TEMPLATE] = L(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______,    _______,
    _______,     _______, _______, _______, ___F___, _______, _______, ___J___, _______, _______, _______, _______,    _M_, _______,       _______,
    _______, _M_,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______,       _______, _______,
    _______,   _______,   _______,                        _______,                        _______,   _______,    _M_,    _______, _______, _______) */
};

// clang-format on

DANCE_MOD_TAP_LAYER_TOGGLE(RCTL, LAYER_NUMPAD)
DANCE_MACRO_MOD(1, ESC)
DANCE_LEADER_MOD(RGUI)

tap_dance_action_t tap_dance_actions[] = {
    [TAP_DANCE_DMACRO_ESC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_DMCRO1_ESC_finished, dance_DMCRO1_ESC_reset),
    [TAP_DANCE_LEADER_RGUI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_LEADER_RGUI_finished, dance_LEADER_RGUI_reset),
    [TAP_DANCE_NUMPAD_RCTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_LAYER_NUMPAD_RCTL_finished, dance_LAYER_NUMPAD_RCTL_reset),
};
