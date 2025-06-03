// Copyright 2025 Wes Rupert (@wesrupert)
// SPDX-License-Identifier: GPL-3.0-or-later
#include "action_layer.h"
#include "ora.h"

enum layers {
    LAYER_ENUM_END = LAYER_ENUM_END_USER,
};

enum tap_dances {
    DANCE_RGUI_RALT_LEAD = 0,
    DANCE_LCTL_LGUI_DMC1,
    DANCE_RCTL_RGUI_DMC2,
    X_TAP_DANCE
};

// Advance key aliases
#define LI_ANIT RGB_TOG
#define LI_LDLT LED_LEVEL
#define LI_LYRT TOGGLE_LAYER_COLOR
#define LT_FNEN LT(LAYER_FUNCTION, KC_ENT)
#define LT_FNES LT(LAYER_FUNCTION, KC_ESC)
#define MT_LAEQ LALT_T(KC_EQL)
#define MT_LGEQ LGUI_T(KC_EQL)
#define MT_LCEQ LCTL_T(KC_EQL)
#define MT_LAMN LALT_T(KC_MINS)
#define MT_LGMN LGUI_T(KC_MINS)
#define MT_LCMN LCTL_T(KC_MINS)
#define MT_RABL RALT_T(KC_BSLS)
#define MT_RGBL RGUI_T(KC_BSLS)
#define MT_RCBL RCTL_T(KC_BSLS)
#define MT_RAQT RALT_T(KC_QUOT)
#define MT_RGQT RGUI_T(KC_QUOT)
#define MT_RCQT RCTL_T(KC_QUOT)
#define TD_R2LD TD(DANCE_RGUI_RALT_LEAD)
#define TD_LCM1 TD(DANCE_LCTL_LGUI_DMC1)
#define TD_RCM2 TD(DANCE_RCTL_RGUI_DMC2)
#define TG_NMPD TG(LAYER_NUMPAD)
#define TT_FUNC TT(LAYER_FUNCTION)
#define TT_NUMP TT(LAYER_NUMPAD)

// Include after key definitions in order to use them in the def file
#include "g/keymap_combo.h"

#define ____________HOTDOX_VOLUME_SYSTEM___________ \
        PK_MONT, __________VOLUM__________, PK_SYST
#define ____________HOTDOX_VOLUME_MEDIA____________ \
        PK_MPRV, PK_VOLD, PK_VOLU, PK_MNXT, KC_MPLY

// clang-format off

/*
#define LAYOUT_ergodox_pretty(                                                 \
      L00,L01,L02,L03,L04,L05,L06,              R00,R01,R02,R03,R04,R05,R06,   \
      L10,L11,L12,L13,L14,L15,L16,              R10,R11,R12,R13,R14,R15,R16,   \
      L20,L21,L22,L23,L24,L25,                      R21,R22,R23,R24,R25,R26,   \
      L30,L31,L32,L33,L34,L35,L36,              R30,R31,R32,R33,R34,R35,R36,   \
      L40,L41,L42,L43,L44,                              R42,R43,R44,R45,R46,   \
                              L55,L56,      R50,R51,                           \
                                  L54,      R52,                               \
                          L51,L52,L53,      R53,R54,R55)                       \
   {                        / * matrix positions * /                           \
    { L00,L01,L02,L03,L04,L05,L06,              R00,R01,R02,R03,R04,R05,R06 }, \
    { L10,L11,L12,L13,L14,L15,L16,              R10,R11,R12,R13,R14,R15,R16 }, \
    { L20,L21,L22,L23,L24,L25,KC_NO,          KC_NO,R21,R22,R23,R24,R25,R26 }, \
    { L30,L31,L32,L33,L34,L35,L36,              R30,R31,R32,R33,R34,R35,R36 }, \
    { L40,L41,L42,L43,L44,KC_NO,KC_NO,      KC_NO,KC_NO,R42,R43,R44,R45,R46 }, \
    { KC_NO,L51,L52,L53,L54,L55,L56,          R50,R51,R52,R53,R54,R55,KC_NO }  \
   }
*/

#define L(...) LAYOUT_ergodox_pretty(__VA_ARGS__)

// Handedness definition
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = L(
      'L','L','L','L','L','L','L',              'R','R','R','R','R','R','R',
      'L','L','L','L','L','L','L',              'R','R','R','R','R','R','R',
      'L','L','L','L','L','L',                      'R','R','R','R','R','R',
      'L','L','L','L','L','L','L',              'R','R','R','R','R','R','R',
      'L','L','L','L','L',                              'R','R','R','R','R',
                              '*','*',      '*','*',
                                  '*',      '*',
                          '*','*','*',      '*','*','*');

#define _DUNNO_ _______

#define _LAYER_BASE [LAYER_BASE] = L(                                                                                                \
    KC_DEL,  __________________QWER_L1__________________, KC_LBRC,    KC_RBRC, __________________QWER_R1__________________, KC_BSPC, \
    MT_LGTB, __________________QWER_L2__________________, KC_MINS,    KC_GRV,  __________________QWER_R2__________________, TD_R2LD, \
    MT_LCMN, __________________QWER_L3__________________,                      _____________QWER__R3_____________, KC_SCLN, MT_RCQT, \
    MT_LAEQ, __________________QWER_L4__________________, KC_EQL,     KC_QUOT, __________________QWER_R4__________________, MT_RABL, \
    _DUNNO_, __________MEDIA__________, KC_LGUI,                                        KC_RGUI, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, \
                                                 _DUNNO_, _DUNNO_,    _DUNNO_, _DUNNO_,                                              \
                                        /*-----\ /-----*/ _DUNNO_,    _DUNNO_, /*-----\ /-----*/                                     \
                                        LT_FNES, MT_LSSP, _DUNNO_,    _DUNNO_, MT_RSSP, LT_FNEN)

#define _LAYER_MAC [LAYER_MAC] = L(                                                                                                   \
    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, \
    MT_LATB, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, \
    MT_LGMN, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, MT_RGQT, \
    MT_LCEQ, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, MT_RCBL, \
    _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, \
                                                 _______, _______,    _______, _______,                                              \
                                        /*-----\ /-----*/ _______,    _______, /*-----\ /-----*/                                     \
                                        _______, _______, _______,    _______, _______, _______)

#define _LAYER_GAMES [LAYER_GAMES] = L(                                                                                              \
    KC_GRV,  __________________QWER_L1__________________, KC_LBRC,    KC_RBRC, __________________QWER_R1__________________, KC_BSPC, \
    KC_TAB,  __________________QWER_L2__________________, KC_MINS,    KC_EQL,  __________________QWER_R2__________________, TD_R2LD, \
    KC_LCTL, __________________QWER_L3__________________,                      _____________QWER__R3_____________, KC_QUOT, MT_RCQT, \
    KC_LALT, __________________QWER_L4__________________, KC_GRV,     KC_SCLN, __________________QWER_R4__________________, MT_RABL, \
    KC_F5,   KC_F1,   KC_F2,   KC_F3,   KC_F4,                                          ____________HOTDOX_VOLUME_MEDIA____________, \
                                                 _DUNNO_, _DUNNO_,    _DUNNO_, _DUNNO_,                                              \
                                        /*-----\ /-----*/ _DUNNO_,    _DUNNO_, /*-----\ /-----*/                                     \
                                        KC_LSFT, KC_SPC,  _DUNNO_,    _DUNNO_, MT_RSSP, LT_FNES)

#define _LAYER_FUNCTION [LAYER_FUNCTION] = L(                                                                                        \
    FUNC_11, __________________FUNC_L1__________________, _DUNNO_,    _DUNNO_, __________________FUNC_R1__________________, FUNC_12, \
    KC_LGUI, PK_ASST, _____________FUNC__L2_____________, _DUNNO_,    _DUNNO_, _____________FUNC__R2_____________, PK_PSCR, _______, \
    KC_LCTL, QK_LOCK, _____________FUNC__L3_____________,                      _____________FUNC__R3_____________, PK_PSCF, KC_RCTL, \
    KC_LALT, TD_LCM1, _DUNNO_, _DUNNO_, _DUNNO_, PK_LOCK, _DUNNO_,    _DUNNO_, PK_LOCK, _DUNNO_, _DUNNO_, _DUNNO_, TD_RCM2, KC_RALT, \
    ____________HOTDOX_VOLUME_SYSTEM___________,                                        ____________HOTDOX_VOLUME_MEDIA____________, \
                                                 KC_LGUI, KC_LALT,    KC_RALT, KC_RGUI,                                              \
                                        /*-----\ /-----*/ KC_LCTL,    KC_RCTL, /*-----\ /-----*/                                     \
                                        TT_NUMP, CW_TOGG, KC_ESC,     KC_ESC, CW_TOGG,  TT_NUMP)

#define _LAYER_NUMPAD [LAYER_NUMPAD] = L(                                                                                            \
    KC_DEL,  KC_PSLS, __________NMPD_1_________, KC_PMNS, _______,    _______, KC_PMNS, __________NMPD_1_________, KC_PAST, KC_DEL,  \
    KC_BSPC, KC_PAST, __________NMPD_2_________, KC_PPLS, _______,    _______, KC_PPLS, __________NMPD_2_________, KC_PSLS, KC_BSPC, \
    MT_LCES, KC_UP,   __________NMPD_3_________, KC_PEQL,                      KC_PEQL, __________NMPD_3_________, KC_UP,   MT_RCES, \
    KC_LEFT, KC_DOWN, KC_RGHT, NMPD__4, KC_PDOT, KC_PENT, _______,    _______, KC_PENT, KC_PDOT, NMPD__4, KC_LEFT, KC_DOWN, KC_RGHT, \
    ____________HOTDOX_VOLUME_SYSTEM___________,                                        ____________HOTDOX_VOLUME_MEDIA____________, \
                                                 _______, _______,    _______, _______,                                              \
                                        /*-----\ /-----*/ TT_NUMP,    TT_NUMP, /*-----\ /-----*/                                     \
                                        MT_LATB, MT_LSSP, _______,    _______, MT_RSSP, MT_RATB)

/* #define _LAYER_X [LAYER_X] = L(                                                                                            \
    _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_,    _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_,
    _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_,    _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_,
    _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_,                      _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_,
    _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_,    _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_,
    _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_,                                        _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_,
                                                 _TO_DO_, _TO_DO_,    _TO_DO_, _TO_DO_,
                                        / *-----\ /-----* / _TO_DO_,    _TO_DO_, / *-----\ /-----* /
                                        _TO_DO_, _TO_DO_, _TO_DO_,    _TO_DO_, _TO_DO_, _TO_DO_), */

// clang-format on

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    _LAYER_BASE,
    _LAYER_MAC,
    _LAYER_GAMES,
    _LAYER_FUNCTION,
    _LAYER_NUMPAD,
};

DANCE_PLATMOD_MACRO(LCTL, LGUI, 1)
DANCE_PLATMOD_MACRO(RCTL, RGUI, 2)
DANCE_PLATMOD_LEADER(RGUI, RALT)

tap_dance_action_t tap_dance_actions[] = {
    [DANCE_LCTL_LGUI_DMC1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_DMC1_LCTL_LGUI_finished, dance_DMC1_LCTL_LGUI_reset),
    [DANCE_RCTL_RGUI_DMC2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_DMC2_RCTL_RGUI_finished, dance_DMC2_RCTL_RGUI_reset),
    [DANCE_RGUI_RALT_LEAD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_LEAD_RGUI_RALT_finished, dance_LEAD_RGUI_RALT_reset),
};
