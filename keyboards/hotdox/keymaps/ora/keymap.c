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
    TAP_DANCE_LEADER_LGUI = 0,
    TAP_DANCE_LEADER_RGUI,
    TAP_DANCE_DMACRO_LALT,
    TAP_DANCE_DMACRO_RALT,
    TAP_DANCE_NUMPAD_LCTL,
    TAP_DANCE_NUMPAD_RCTL,
    X_TAP_DANCE
};

// Advance key aliases
#define TT_NMPD TT(LAYER_NUMPAD)
#define TT_FUNC TT(LAYER_FUNCTION)
#define LT_SYEN LT(LAYER_SYMBOLS, KC_ENT)

#define MT_LCES LCTL_T(KC_ESC)
#define MT_RCEN RCTL_T(KC_ENT)
#define MT_MHES MEH_T(KC_ESC)

#define TD_LGLD TD(TAP_DANCE_LEADER_LGUI)
#define TD_RGLD TD(TAP_DANCE_LEADER_RGUI)
#define TD_LAMC TD(TAP_DANCE_DMACRO_LALT)
#define TD_RAMC TD(TAP_DANCE_DMACRO_RALT)
#define TD_LCNP TD(TAP_DANCE_NUMPAD_LCTL)
#define TD_RCNP TD(TAP_DANCE_NUMPAD_RCTL)

#define ____________HOTDOX_VOLUME_SYSTEM___________ \
        PK_MONT, __________VOLUM__________, PK_SYST
#define ____________HOTDOX_VOLUME_MEDIA____________ \
        PK_MPRV, PK_VOLD, PK_VOLU, PK_MNXT, KC_MPLY

// clang-format off

// TODO: Investigate "Instant tap" mod taps for home-row mods:
// https://github.com/filterpaper/qmk_userspace/blob/11cb3970e89760039b940f5de84e31c08aea4b68/readme.md?#contextual-mod-taps

#define LAYOUT_ergodox_pretty(                                                 \
      L00,L01,L02,L03,L04,L05,L06,              R00,R01,R02,R03,R04,R05,R06,   \
      L10,L11,L12,L13,L14,L15,L16,              R10,R11,R12,R13,R14,R15,R16,   \
      L20,L21,L22,L23,L24,L25,                      R21,R22,R23,R24,R25,R26,   \
      L30,L31,L32,L33,L34,L35,L36,              R30,R31,R32,R33,R34,R35,R36,   \
      L40,L41,L42,L43,L44,                              R42,R43,R44,R45,R46,   \
                              L55,L56,      R50,R51,                           \
                                  L54,      R52,                               \
                          L51,L52,L53,      R53,R54,R55 )                      \
   {                         /* matrix positions */                            \
    { L00,L01,L02,L03,L04,L05,L06,              R00,R01,R02,R03,R04,R05,R06 }, \
    { L10,L11,L12,L13,L14,L15,L16,              R10,R11,R12,R13,R14,R15,R16 }, \
    { L20,L21,L22,L23,L24,L25,KC_NO,          KC_NO,R21,R22,R23,R24,R25,R26 }, \
    { L30,L31,L32,L33,L34,L35,L36,              R30,R31,R32,R33,R34,R35,R36 }, \
    { L40,L41,L42,L43,L44,KC_NO,KC_NO,      KC_NO,KC_NO,R42,R43,R44,R45,R46 }, \
    { KC_NO,L51,L52,L53,L54,L55,L56,          R50,R51,R52,R53,R54,R55,KC_NO }  \
   }
#define L(...) LAYOUT_ergodox_pretty(__VA_ARGS__)

// Expand key groups before passing into layout macro.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LAYER_BASE] = L(
    KC_DEL,  __________________QWER_L1__________________, KC_LBRC,    KC_RBRC, __________________QWER_R1__________________, KC_BSPC,
    KC_TAB,  __________________QWER_L2__________________, KC_MINS,    KC_EQL,  __________________QWER_R2__________________, KC_BSLS,
    MT_LCES, __________________QWER_L3__________________,                      _____________QWER__R3_____________, KC_QUOT, MT_RCEN,
    KC_LSFT, __________________QWER_L4__________________, KC_GRV,     KC_SCLN, __________________QWER_R4__________________, KC_RSFT,
    KC_LALT, __________MEDIA__________, KC_LGUI,                                        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_RALT,
                                                 TD_LGLD, TD_LAMC,    TD_RAMC, TD_RGLD,
                                        /*-----\ /-----*/ TD_LCNP,    TD_RCNP, /*-----\ /-----*/
                                        MT_LSSP, LT_SYEN, MT_MHES,    MT_MHES, LT_SYEN, MT_RSSP),

[LAYER_GAMES] = L(
    KC_0,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,    _______, _______, _______, _______, _______, _______, _______,
    KC_TAB,  _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
    KC_LCTL, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
    KC_LALT, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
    KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_F4,                                          ____________HOTDOX_VOLUME_MEDIA____________,
                                                 KC_F5,   KC_F6,      _______, _______,
                                        /*-----\ /-----*/ KC_F7,      _______, /*-----\ /-----*/
                                        KC_SPC,  KC_LSFT, KC_F8,      _______, _______, _______),

[LAYER_NUMPAD] = L(
    KC_NUM,  KC_PAST, __________NMPD_1_________, KC_PPLS, _______,    _______, KC_PPLS, __________NMPD_1_________, KC_PAST, KC_NUM,
    KC_BSPC, KC_PSLS, __________NMPD_2_________, KC_PMNS, _______,    _______, KC_PMNS, __________NMPD_2_________, KC_PSLS, KC_BSPC,
    KC_DEL,  KC_UP,   __________NMPD_3_________, KC_PEQL,                      KC_PEQL, __________NMPD_3_________, KC_UP,   KC_DEL,
    KC_LEFT, KC_DOWN, KC_RGHT, NMPD__4, KC_PDOT, KC_TAB,  _______,    _______, KC_TAB,  KC_PDOT, KC_P0,   KC_LEFT, KC_DOWN, KC_RGHT,
    PK_VOLD, __________MEDIA__________, PK_VOLU,                                        ____________HOTDOX_VOLUME_MEDIA____________,
                                                 _______, _______,    _______, _______,
                                        /*-----\ /-----*/ TT_NMPD,    TT_NMPD, /*-----\ /-----*/
                                        KC_SPC,  KC_PENT, _______,    _______, KC_PENT, KC_SPC),

[LAYER_SYMBOLS] = L(
    KC_BSPC, __________________SYMB_L1__________________, SYM_SL1,    SYM_SR1, __________________SYMB_R1__________________, KC_DEL,
    PK_TABN, __________________SYMB_L2__________________, KC_UNDS,    KC_PLUS, __________________SYMB_R2__________________, PK_TABN,
    LC_TAB,  __________________SYMB_L3__________________,                      __________________SYMB_R3__________________, LC_TAB,
    CS_TAB,  __________________SYMB_L4__________________, KC_TILD,    KC_COLN, __________________SYMB_R4__________________, CS_TAB,
    ____________HOTDOX_VOLUME_SYSTEM___________,                                        ____________HOTDOX_VOLUME_MEDIA____________,
                                                 _______, _______,    _______, _______,
                                        /*-----\ /-----*/ _______,    _______, /*-----\ /-----*/
                                        KC_BSPC, TT_FUNC, _______,    _______, TT_FUNC, KC_DEL),

[LAYER_FUNCTION] = L(
    KC_ESC,  __________________FUNC_L1__________________, FUNC_11,    FUNC_12, __________________FUNC_R1__________________, KC_ESC,
    PK_TABN, XXXXXXX, _____________FUNC__L2_____________, XXXXXXX,    XXXXXXX, _____________FUNC__R2_____________, PK_PSCR, PK_TABN,
    LC_TAB,  XXXXXXX, _____________FUNC__L3_____________,                      _____________FUNC__R3_____________, PK_PSCF, LC_TAB,
    CS_TAB,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CS_TAB,
    ____________HOTDOX_VOLUME_SYSTEM___________,                                        ____________HOTDOX_VOLUME_MEDIA____________,
                                                 KC_LGUI, PK_LOCK,    PK_LOCK, KC_RGUI,
                                        /*-----\ /-----*/ KC_LCTL,    KC_RCTL, /*-----\ /-----*/
                                        CW_TOGG, TT_FUNC, KC_ESC,     KC_ESC,  TT_FUNC, CW_TOGG),

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

layer_state_t last_layer_state;
layer_state_t layer_state_set_user(layer_state_t state) {
    if (!layer_state_cmp(state, LAYER_SYMBOLS) && layer_state_cmp(last_layer_state, LAYER_SYMBOLS)) {
        // Double up done => "tri"-layer state off
        state = state & ~((layer_state_t)1 << LAYER_FUNCTION);
    }
    return last_layer_state = state;
}

DANCE_LEADER_MOD(LGUI)
DANCE_LEADER_MOD(RGUI)
DANCE_MACRO_MOD(1, LALT)
DANCE_MACRO_MOD(2, RALT)
DANCE_MOD_TAP_LAYER_TOGGLE(LCTL, LAYER_NUMPAD)
DANCE_MOD_TAP_LAYER_TOGGLE(RCTL, LAYER_NUMPAD)

tap_dance_action_t tap_dance_actions[] = {
    [TAP_DANCE_LEADER_LGUI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_LEADER_LGUI_finished, dance_LEADER_LGUI_reset),
    [TAP_DANCE_LEADER_RGUI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_LEADER_RGUI_finished, dance_LEADER_RGUI_reset),
    [TAP_DANCE_DMACRO_LALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_DMCRO1_LALT_finished, dance_DMCRO1_LALT_reset),
    [TAP_DANCE_DMACRO_RALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_DMCRO2_RALT_finished, dance_DMCRO2_RALT_reset),
    [TAP_DANCE_NUMPAD_LCTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_LAYER_NUMPAD_LCTL_finished, dance_LAYER_NUMPAD_LCTL_reset),
    [TAP_DANCE_NUMPAD_RCTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_LAYER_NUMPAD_RCTL_finished, dance_LAYER_NUMPAD_RCTL_reset),
};
