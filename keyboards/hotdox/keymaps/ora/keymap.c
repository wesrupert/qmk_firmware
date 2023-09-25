// Copyright 2023 Wes Rupert (@wesrupert)
// SPDX-License-Identifier: GPL-3.0-or-later
#include "ora.h"
#include "./wrappers.h"

#define HOTDOX_USE_AS_VOYAGER
#if defined(HOTDOX_USE_AS_VOYAGER)

enum tap_dances {
    TAP_DANCE_PLAY_PAUSE_SPOTIFY = 0,
    TAP_DANCE_LEADER_LGUI,
    TAP_DANCE_DYN_MACRO_1_RALT,
    X_TAP_DANCE
};

// Advance key aliases
#define TD_LGLD TD(TAP_DANCE_LEADER_LGUI)
#define TD_RAMC TD(TAP_DANCE_DYN_MACRO_1_RALT)

// __{LAYER} macros so we can use OS-variant keys without writing the layers twice.
// Layers are copies instead of layered so we can use set_single_persistent_default_layer.
// ...Not that it does anything for this profile, it doesn't look like Hotdox v1 has EEPROM support?
// clang-format off

#define __BASE(OS) \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
    KC_TAB,  __________________QWER_L2__________________,                      __________________QWER_R2__________________, KC_BSLS, \
    MT_LCES, __________________QWER_L3__________________,                      _____________QWER__R3_____________, KC_SCLN, KC_QUOT, \
    TD_LGLD, __________________QWER_L4__________________,                      __________________QWER_R4__________________, TD_RAMC, \
                                                 MT_LSSP, OS##_FNES,  LT_SYEN, MT_RSSP

#define __FUNCTION(OS) \
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,  \
    KC_DEL,  KC_ESC,  _____________FUNC__L2_____________,                      _____________FUNC__R2_____________,OS##_PSCR,KC_F12,  \
    CW_TOGG,OS##_SALL,_____________FUNC__L3_____________,                      _____________FUNC__R3_____________,OS##_PSCF,CW_TOGG, \
    KC_CAPS,OS##_UNDO,_________VOLM_##OS##_________,OS##_LOCK,              OS##_LOCK,_________MDIA_##OS##_________,TT_NMPD,KC_RALT, \
                                                 CW_TOGG, KC_TRNS,    KC_BSPC, KC_DEL

#define __SYMBOLS \
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS, \
    XXXXXXX, __________________SYMB_L2__________________,                      __________________SYMB_R2__________________, KC_UNDS, \
    CW_TOGG, __________________SYMB_L3__________________,                      __________________SYMB_R3__________________, KC_DQUO, \
    TT_NMPD, __________________SYMB_L4__________________,                      __________________SYMB_R4__________________, KC_PIPE, \
                                                 KC_DEL,  KC_BSPC,    KC_TRNS, CW_TOGG

#define __NUMPAD \
    KC_NUM,  ______________NMPD_2______________, KC_BSPC,                      KC_NUM,  ______________NMPD_2______________, KC_BSPC, \
    KC_PAST, ______________NMPD_3______________, KC_PPLS,                      KC_PAST, ______________NMPD_3______________, KC_PPLS, \
    KC_PSLS, __________NMPD_4_________, KC_UP,   KC_PMNS,                      KC_PSLS, KC_UP,   __________NMPD_4_________, KC_PMNS, \
    TT_NMPD, _____NMPD_5_____, KC_LEFT, KC_DOWN, KC_RGHT,                      KC_LEFT, KC_DOWN, KC_RGHT, _____NMPD_5_____, TT_NMPD, \
                                                 KC_PENT, KC_SPC,     KC_SPC,  KC_PENT

#define __GAMES \
    _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, \
    KC_LCTL, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, \
    KC_LSFT, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, \
                                                 KC_SPC,  KC_ENT,     TD_LGLD, KC_ESC

/* #define __LAYER \
    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, \
                                                 _______, _______,     _______, _______
*/

// Expand key groups before passing into layout macro.
#define L(...) LAYOUT_ergodox_pretty_AS_voyager(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_WIN]     = L(__BASE(WN)),
    [LAYER_MAC]     = L(__BASE(MC)),
    [LAYER_NUMPAD]  = L(__NUMPAD),
    [LAYER_GAMES]   = L(__GAMES),
    [LAYER_SYMBOLS] = L(__SYMBOLS),
    [LAYER_WINFUN]  = L(__FUNCTION(WN)),
    [LAYER_MACFUN]  = L(__FUNCTION(MC))
};

DANCE_SPOTIFY
DANCE_LEAD(l, L, gui, GUI)
DANCE_MCRO(1, r, R, alt, ALT)

tap_dance_action_t tap_dance_actions[] = {
    [TAP_DANCE_PLAY_PAUSE_SPOTIFY] = ACTION_TAP_DANCE_FN(dance_playpause_spotify),
    [TAP_DANCE_LEADER_LGUI       ] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_lead_l_gui_finished, dance_lead_l_gui_reset),
    [TAP_DANCE_DYN_MACRO_1_RALT  ] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_dm_1_r_alt_finished, dance_dm_1_r_alt_reset),
};

#else // !defined(HOTDOX_USE_AS_VOYAGER)

enum tap_dances {
    TAP_DANCE_PLAY_PAUSE_SPOTIFY = 0,
    TAP_DANCE_DYN_MACRO_1,
    TAP_DANCE_DYN_MACRO_2,
    TAP_DANCE_LEADER_LCTL,
    TAP_DANCE_LEADER_RCTL,
    TAP_DANCE_NUMPAD_LALT,
    X_TAP_DANCE
};

// Advance key aliases
#define TD_DMC1 TD(TAP_DANCE_DYN_MACRO_1)
#define TD_DMC2 TD(TAP_DANCE_DYN_MACRO_2)
#define TD_LCLD TD(TAP_DANCE_LEADER_LCTL)
#define TD_RCLD TD(TAP_DANCE_LEADER_RCTL)
#define TD_LANP TD(TAP_DANCE_NUMPAD_LALT)

// __{LAYER} macros so we can use OS-variant keys without writing the layers twice.
// Layers are copies instead of layered so we can use set_single_persistent_default_layer.
// ...Not that it does anything for this profile, it doesn't look like Hotdox v1 has EEPROM support?
// clang-format off

#define __BASE(OS) \
    KC_DEL,  __________________QWER__L1_________________, QWER_S1,    _____________QWER__R1_____________, KC_LBRC, KC_RBRC, KC_BSPC, \
    KC_TAB,  __________________QWER_L2__________________, KC_MINS,    KC_EQL,  __________________QWER_R2__________________, KC_BSLS, \
    MT_LCES, __________________QWER_L3__________________,                      _____________QWER__R3_____________, KC_QUOT, MT_RCES, \
    MT_LSEN, __________________QWER_L4__________________, KC_GRV,     KC_SCLN, __________________QWER_R4__________________, MT_RSEN, \
    MT_LABS,_________MDIA_##OS##_________,KC_LGUI,                                      KC_RGUI, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, \
                                                 TD_DMC1, TD_LANP,    TD_RANP, TD_DMC2,          \
                                        /*-----\ /-----*/ TD_LCLD,    TD_RCLD, /*-----\ /-----*/ \
                                        MT_LSSP, LT_SYEN,OS##_FNES,  OS##_FNES,LT_SYEN, MT_RSSP

#define __FUNCTION(OS) \
    KC_ESC,  ______________________FUNC__L1______________________,    ______________________FUNC__R1______________________, KC_DEL,  \
    XXXXXXX, XXXXXXX, _____________FUNC__L2_____________, XXXXXXX,    XXXXXXX, _____________FUNC__R2_____________,OS##_PSCR,KC_CAPS, \
    KC_CAPS,OS##_SALL,_____________FUNC__L3_____________,                      _____________FUNC__R3_____________,OS##_PSCF,KC_RCTL, \
    CW_TOGG,OS##_UNDO,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, TT_NMPD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CW_TOGG, \
    _______,_________VOLM_##OS##_________,_______,                                  TD_PLPS,OS##_MPRV,OS##_VOLD,OS##_VOLU,OS##_MNXT, \
                                                OS##_LOCK,_______,    _______,OS##_LOCK,         \
                                        /*-----\ /-----*/ _______,    _______, /*-----\ /-----*/ \
                                        _______, _______, _______,    _______, _______, _______

#define __SYMBOLS \
    _______, ______________________SYMB__L1______________________,    ______________________SYMB__R1______________________, _______, \
    _______, __________________SYMB_L2__________________, KC_UNDS,    KC_PLUS, __________________SYMB_R2__________________, _______, \
    _______, __________________SYMB_L3__________________,                      __________________SYMB_R3__________________, _______, \
    _______, __________________SYMB_L4__________________, KC_TILD,    KC_COLN, __________________SYMB_R4__________________, _______, \
    _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, \
                                                 _______, _______,    _______, _______, \
                                        /*-----\ /-----*/ _______,    _______, /*-----\ /-----*/ \
                                        _______, _______, _______,    _______, _______, _______

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
                                        KC_SPC,  KC_F5,   KC_F9,      KC_ESC,  WN_FNEN, _______

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

// Expand key groups before passing into layout macro.
#define L(...) LAYOUT_ergodox_pretty(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_WIN]     = L(__BASE(WN)),
    [LAYER_MAC]     = L(__BASE(MC)),
    [LAYER_NUMPAD]  = L(__NUMPAD),
    [LAYER_GAMES]   = L(__GAMES),
    [LAYER_SYMBOLS] = L(__SYMBOLS),
    [LAYER_WINFUN]  = L(__FUNCTION(WN)),
    [LAYER_MACFUN]  = L(__FUNCTION(MC))
};

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

#endif // HOTDOX_USE_AS_VOYAGER
