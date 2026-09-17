// Copyright 2026 Wes Rupert (@wesrupert)
// SPDX-License-Identifier: GPL-3.0-or-later
#include "action_layer.h"
#include "keycodes.h"
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
#define LI_ANIT QK_RGB_MATRIX_TOGGLE
#define LI_LDLT LED_LEVEL
#define LI_LYRT TOGGLE_LAYER_COLOR
#define LT_FNEN LT(LAYER_FUNCTION, KC_ENT)
#define LT_FNES LT(LAYER_FUNCTION, KC_ESC)
#define TD_R2LD TD(DANCE_RGUI_RALT_LEAD)
#define TD_LCM1 TD(DANCE_LCTL_LGUI_DMC1)
#define TD_RCM2 TD(DANCE_RCTL_RGUI_DMC2)
#define TG_NMPD TG(LAYER_NUMPAD)
#define TT_NUMP TT(LAYER_NUMPAD)

// Homerow mods
// TODO: 'as'/'sa' bridges keep misfiring mods.
// Investigate custom timing for A?
#undef  KM_A
#define KM_A    KC_A
#undef  KM_S
#define KM_S    LCTL_T(KC_S)
#undef  KM_D
#define KM_D    LGUI_T(KC_D)
#undef  KM_F
#define KM_F    LSFT_T(KC_F)
#undef  KM_G
#define KM_G    LALT_T(KC_G)
#undef  KM_H
#define KM_H    LALT_T(KC_H)
#undef  KM_J
#define KM_J    RSFT_T(KC_J)
#undef  KM_K
#define KM_K    RGUI_T(KC_K)
#undef  KM_L
#define KM_L    RCTL_T(KC_L)
#undef  KM_SC
#define KM_SC   LT(LAYER_FUNCTION, KC_SCLN)
#undef  KM_LEAD
#define KM_LEAD TD_R2LD

// Include after key definitions in order to use them in the def file
#include "g/keymap_combo.h"

// Expand key groups before passing into layout macro
#define KL(...) LAYOUT(__VA_ARGS__)

// clang-format off

// Handedness definition
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = KL(
      '*',     'L',     'L',     'L',     'L',     'L',                          'R',     'R',     'R',     'R',     'R',     '*',
      '*',     'L',     'L',     'L',     'L',     'L',                          'R',     'R',     'R',     'R',     'R',     '*',
      'L',     'L',     'L',     'L',     'L',     'L',                          'R',     'R',     'R',     'R',     'R',     'R',
      'L',     'L',     'L',     'L',     'L',     'L',                          'R',     'R',     'R',     'R',     'R',     'R',
                        'L',     'L',     'L',      '*',     '*',      '*',     '*',      'R',     'R',     'R');

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = KL(
    KM_DEL,  __________________QWER_L1__________________,                      __________________QWER_R1__________________, KM_BSPC,
    KM_TAB,  __________________QWER_L2__________________, /*      BASE      */ __________________QWER_R2__________________, KM_LEAD,
    KM_MINS, KM_A,    KM_S,    KM_D,    KM_F,    KM_G,                         KM_H,    KM_J,    KM_K,    KM_L,    KM_SC,   KM_QUOT,
    KM_EQL,  __________________QWER_L4__________________,                      __________________QWER_R4__________________, KM_BSLS,
                      __________MEDIA__________,  LT_FNES, MT_LSSP,  MT_RSSP, LT_FNEN,  KC_LEFT, KC_DOWN, KC_RGHT)
  ,
  [LAYER_GAMES] = KL(
    KC_GRV,  __________________QWER_L1__________________,                      _______, _______, _______, _______, _______, _______,
    KC_TAB,  __________________QWER_L2__________________, /*      GAME      */ _______, _______, _______, _______, _______, _______,
    KC_LCTL, __________________QWER_L3__________________,                      _______, _______, _______, _______, _______, _______,
    KC_LALT, __________________QWER_L4__________________,                      _______, _______, _______, _______, _______, _______,
                      KC_F1,   KC_F2,   KC_F3,    KC_LSFT, KC_SPC,   _______, _______,  _______, _______, _______)
  ,
  [LAYER_FUNCTION] = KL(
    FUNC_11, __________________FUNC_L1__________________,                      __________________FUNC_R1__________________, FUNC_12,
    KC_LGUI, __________________FUNC_L2__________________, /*    FUNCTION    */ __________________FUNC_R2__________________, _______,
    KC_LCTL, PK_PSCR, _____________FUNC__L3_____________,                      _____________FUNC__R3_____________, PK_PSCF, KC_RCTL,
    KC_LALT, TD_LCM1, XXXXXXX, XXXXXXX, XXXXXXX, PK_LOCK,                      PK_LOCK, XXXXXXX, KC_PGUP, XXXXXXX, TD_RCM2, KC_RALT,
                      __________VOLUM__________,  TT_NUMP, CW_TOGG,  CW_TOGG, TT_NUMP,  KC_HOME, KC_PGDN, KC_END)
  ,
  [LAYER_NUMPAD] = KL(
    KC_BSPC, KC_PMNS, __________NMPD_1_________, KC_PPLS,                      KC_PPLS, __________NMPD_1_________, KC_PMNS, KC_BSPC,
    KC_DEL,  KC_PAST, __________NMPD_2_________, KC_PCMM, /*     NUMPAD     */ KC_PCMM, __________NMPD_2_________, KC_PAST, _______,
    MT_LCES, KC_PSLS, __________NMPD_3_________, KC_PEQL,                      KC_PEQL, __________NMPD_3_________, KC_PSLS, MT_RCES,
    KC_LALT, KC_LGUI, NMPD__4, KC_UP,   KC_PDOT, KC_PENT,                      KC_PENT, NMPD__4, KC_UP,   KC_PDOT, KC_RGUI, KC_RALT,
                      KC_LEFT, KC_DOWN, KC_RGHT,  MT_LATB, MT_LSSP,  MT_RCEN, TG_NMPD,  KC_LEFT, KC_DOWN, KC_RGHT)

/*  [LAYER_TEMPLATE] = KL(
    _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_,                      _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_,
    _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, / *     TODO     * / _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _______,
    _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_,                      _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_,
    _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_,                      _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_,
                      _TO_DO_, _TO_DO_, _TO_DO_,  _TO_DO_, _TO_DO_,  _TO_DO_, _TO_DO_,  _TO_DO_, _TO_DO_, _TO_DO_) */
};

// clang-format on

DANCE_PLATMOD_MACRO(LCTL, LGUI, 1)
DANCE_PLATMOD_MACRO(RCTL, RGUI, 2)
DANCE_PLATMOD_LEADER(RGUI, RALT)

tap_dance_action_t tap_dance_actions[] = {
    [DANCE_LCTL_LGUI_DMC1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_DMC1_LCTL_LGUI_finished, dance_DMC1_LCTL_LGUI_reset),
    [DANCE_RCTL_RGUI_DMC2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_DMC2_RCTL_RGUI_finished, dance_DMC2_RCTL_RGUI_reset),
    [DANCE_RGUI_RALT_LEAD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_LEAD_RGUI_RALT_finished, dance_LEAD_RGUI_RALT_reset),
};
