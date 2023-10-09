// Copyright 2023 Wes Rupert (@wesrupert)
// SPDX-License-Identifier: GPL-3.0-or-later
#include "ora.h"
#include "./wrappers.h"

enum tap_dances {
    TAP_DANCE_DMACRO_LGUI = 0,
    TAP_DANCE_DMACRO_RGUI,
    TAP_DANCE_LEADER_LCTL,
    TAP_DANCE_LEADER_RCTL,
    TAP_DANCE_NUMPAD_LALT,
    TAP_DANCE_NUMPAD_RALT,
    X_TAP_DANCE
};

// Advance key aliases
#define TD_LGMC TD(TAP_DANCE_DMACRO_LGUI)
#define TD_RGMC TD(TAP_DANCE_DMACRO_RGUI)
#define TD_LCLD TD(TAP_DANCE_LEADER_LCTL)
#define TD_RCLD TD(TAP_DANCE_LEADER_RCTL)
#define TD_LANP TD(TAP_DANCE_NUMPAD_LALT)
#define TD_RANP TD(TAP_DANCE_NUMPAD_RALT)

// clang-format off

// Expand key groups before passing into layout macro.
#define L(...) LAYOUT_ergodox_pretty(__VA_ARGS__)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[LAYER_BASE] = L(
    KC_DEL,  __________________QWER_L1__________________, KC_LBRC,    KC_RBRC, __________________QWER_R1__________________, KC_BSPC,
    KC_TAB,  __________________QWER_L2__________________, KC_GRV,     KC_EQL,  __________________QWER_R2__________________, KC_BSLS,
    KC_LCTL, __________________QWER_L3__________________,                      _____________QWER__R3_____________, KC_QUOT, KC_RCTL,
    KC_LSFT, __________________QWER_L4__________________, KC_SCLN,    KC_MINS, __________________QWER_R4__________________, KC_RSFT,
    KC_LALT, KC_LGUI, __________MEDIA__________,                                        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_RALT,
                                                 TD_LGMC, TD_LANP,    TD_RANP, TD_RGMC,
                                        /*-----\ /-----*/ TD_LCLD,    TD_RCLD, /*-----\ /-----*/
                                        MT_LSSP, LT_SYEN, LT_FNES,    LT_FNES, LT_SYEN, MT_RSSP),

[LAYER_NUMPAD] = L(
    KC_NUM,  KC_PAST, __________NMPD_1_________, KC_PPLS, XXXXXXX,     XXXXXXX, KC_PPLS, __________NMPD_1_________, KC_PAST, KC_NUM,
    KC_BSPC, KC_PSLS, __________NMPD_2_________, KC_PMNS, XXXXXXX,     XXXXXXX, KC_PMNS, __________NMPD_2_________, KC_PSLS, KC_BSPC,
    KC_DEL,  KC_UP,   __________NMPD_3_________, KC_PEQL,                       KC_PEQL, __________NMPD_3_________, KC_UP,   KC_DEL,
    KC_LEFT, KC_DOWN, KC_RGHT, NMPD__4, KC_PDOT, KC_TAB,  XXXXXXX,     XXXXXXX, KC_TAB,  KC_PDOT, KC_P0,   KC_LEFT, KC_DOWN, KC_RGHT,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                  XXXXXXX, TT_NMPD,    TT_NMPD, XXXXXXX,
                                         /*-----\ /-----*/ XXXXXXX,    XXXXXXX, /*-----\ /-----*/
                                         KC_SPC,  KC_PENT, XXXXXXX,    XXXXXXX, KC_PENT, KC_SPC),

[LAYER_GAMES] = L(
    KC_F12,  _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
    KC_TAB,  _______, _______, _______, _______, _______, KC_F10,     _______, _______, _______, _______, _______, _______, _______,
    KC_LCTL, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
    KC_LSFT, _______, _______, _______, _______, _______, KC_F11,     _______, _______, _______, _______, _______, _______, _______,
    KC_LALT, KC_F1,   KC_F2,   KC_F3,   KC_F4,                                          _______, _______, _______, _______, _______,
                                                 KC_F6,   KC_F7,      KC_MPLY, PK_MNXT,
                                        /*-----\ /-----*/ KC_F8,      TD_RCLD, /*-----\ /-----*/
                                        KC_SPC,  KC_F5,   KC_F9,      KC_ESC,  LT_FNEN, _______),

[LAYER_SYMBOLS] = L(
    KC_ESC,  __________________SYMB_L1__________________, SYM_SL1,    SYM_SR1, __________________SYMB_R1__________________, KC_DEL,
    PK_TABN, __________________SYMB_L2__________________, KC_TILD,    KC_PLUS, __________________SYMB_R2__________________, PK_TABN,
    LC_TAB,  __________________SYMB_L3__________________,                      __________________SYMB_R3__________________, LC_TAB,
    CS_TAB,  __________________SYMB_L4__________________, KC_COLN,    KC_UNDS, __________________SYMB_R4__________________, CS_TAB,
    PK_MONT, PK_SYST, __________VOLUM__________,                                        PK_MPRV, PK_VOLD, PK_VOLU, PK_MNXT, KC_MPLY,
                                                 PK_LOCK, TT_NMPD,    TT_NMPD, PK_LOCK,
                                        /*-----\ /-----*/ XXXXXXX,    XXXXXXX, /*-----\ /-----*/
                                        KC_DEL,  KC_TRNS, CW_TOGG,    CW_TOGG, KC_TRNS, KC_BSPC),

[LAYER_FUNCTION] = L(
    KC_ESC,  __________________FUNC_L1__________________, FUNC_11,    FUNC_12, __________________FUNC_R1__________________, KC_DEL,
    PK_TABN, XXXXXXX, _____________FUNC__L2_____________, XXXXXXX,    XXXXXXX, _____________FUNC__R2_____________, PK_PSCR, PK_TABN,
    LC_TAB,  XXXXXXX, _____________FUNC__L3_____________,                      _____________FUNC__R3_____________, PK_PSCF, LC_TAB,
    CS_TAB,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CS_TAB,
    PK_MONT, PK_SYST, __________VOLUM__________,                                        PK_MPRV, PK_VOLD, PK_VOLU, PK_MNXT, KC_MPLY,
                                                 PK_LOCK, TT_NMPD,    TT_NMPD, PK_LOCK,
                                        /*-----\ /-----*/ XXXXXXX,    XXXXXXX, /*-----\ /-----*/
                                        KC_DEL,  CW_TOGG, KC_TRNS,    KC_TRNS, CW_TOGG, KC_BSPC),

/* [LAYER_] = L(
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,
                                                 _______, _______,     _______, _______,
                                        / *-----\ /-----* / _______,     _______, / *-----\ /-----* /
                                        _______, _______, _______,     _______, _______, _______), */

};

// clang-format on

DANCE_MCRO(1, l, L, gui, GUI)
DANCE_MCRO(2, r, R, gui, GUI)
DANCE_LEAD(l, L, ctl, CTL)
DANCE_LEAD(r, R, ctl, CTL)
DANCE_NUMP(l, L, alt, ALT)
DANCE_NUMP(r, R, alt, ALT)

tap_dance_action_t tap_dance_actions[] = {
    [TAP_DANCE_DMACRO_LGUI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_dm_1_l_gui_finished, dance_dm_1_l_gui_reset),
    [TAP_DANCE_DMACRO_RGUI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_dm_2_r_gui_finished, dance_dm_2_r_gui_reset),
    [TAP_DANCE_LEADER_LCTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_lead_l_ctl_finished, dance_lead_l_ctl_reset),
    [TAP_DANCE_LEADER_RCTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_lead_r_ctl_finished, dance_lead_r_ctl_reset),
    [TAP_DANCE_NUMPAD_LALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_nump_l_alt_finished, dance_nump_l_alt_reset),
    [TAP_DANCE_NUMPAD_RALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_nump_r_alt_finished, dance_nump_r_alt_reset),
};
