#include QMK_KEYBOARD_H
#include "ora.h"
#include "version.h"

#define LT_FNES LT(LAYER_FUNCTION, KC_ESC)
#define LT_WFNE LT(LAYER_WINFUN, KC_ESC)
#define LT_SYEN LT(LAYER_SYMBOLS, KC_ENT)
#define LT_NMPD TT(LAYER_NUMPAD)
#define MT_LSSP LSFT_T(KC_SPC)
#define MT_RSSP RSFT_T(KC_SPC)
#define MT_LCES LCTL_T(KC_ESC)
#define MT_RCEN RCTL_T(KC_ENT)

// Expand key groups before passing into layout macro.
#define LAYOUT_wrapper(...) LAYOUT_ergodox_pretty(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LAYER_BASE] = LAYOUT_wrapper( // {{{
    KC_DEL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,       KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC, KC_RBRC, KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS,    KC_EQL,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    MT_LCES, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, MT_RCEN,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_GRV,     KC_SCLN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LALT, MC_MPRV, TD_MPLS, MC_MNXT, KC_LGUI,                                        KC_RGUI, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
                                                 LT_NMPD, TD_DMC1,    TD_DMC2, KC_LOCK,
                                        /*-----\ /-----*/ KC_LEAD,    KC_LEAD, /*-----\ /-----*/
                                        MT_LSSP, LT_SYEN, LT_FNES,    LT_FNES, LT_SYEN, MT_RSSP)
, // }}}
[LAYER_WIN] = LAYOUT_wrapper( // {{{
    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
    _______, WN_MPRV, TD_WPLS, WN_MNXT, _______,                                        _______, _______, _______, _______, _______,
                                                 _______, _______,    _______, _______,
                                        /*-----\ /-----*/ _______,    _______, /*-----\ /-----*/
                                        _______, _______, LT_WFNE,    LT_WFNE, _______, _______)
, // }}}
[LAYER_GAMES] = LAYOUT_wrapper( // {{{
    KC_GRV,  _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
    KC_LCTL, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_HOME,    _______, _______, _______, _______, _______, _______, _______,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                          _______, _______, _______, _______, _______,
                                                 WN_MPLY, WN_MNXT,    _______, _______,
                                        /*-----\ /-----*/ LT_WFNE,    _______, /*-----\ /-----*/
                                        KC_SPC,  KC_LALT, KC_ESC,     _______, _______, _______)
, // }}}
[LAYER_FUNCTION] = LAYOUT_wrapper( // {{{
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  RESET,
    KC_CAPS, XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  XXXXXXX,    XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  MC_PSCR, KC_CAPS,
    KC_LCTL, XXXXXXX, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, MC_PSCF, KC_RCTL,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, MC_VOLD, MC_MUTE, MC_VOLU, _______,                                        MC_MPLY, MC_MPRV, MC_VOLD, MC_VOLU, MC_MNXT,
                                                 _______, _______,    _______, MC_LOCK,
                                        /*-----\ /-----*/ _______,    _______, /*-----\ /-----*/
                                        _______, _______, _______,    _______, _______, _______)
, // }}}
[LAYER_WINFUN] = LAYOUT_wrapper( // {{{
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  RESET,
    KC_CAPS, XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  XXXXXXX,    XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  WN_PSCR, KC_CAPS,
    KC_LCTL, XXXXXXX, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, WN_PSCF, KC_RCTL,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, WN_VOLD, WN_MUTE, WN_VOLU, _______,                                        WN_MPLY, WN_MPRV, WN_VOLD, WN_VOLU, WN_MNXT,
                                                 _______, _______,    _______, WN_LOCK,
                                        /*-----\ /-----*/ _______,    _______, /*-----\ /-----*/
                                        _______, _______, _______,    _______, _______, _______)
, // }}}
[LAYER_SYMBOLS] = LAYOUT_wrapper( // {{{
    _______,                               __SYM1L__,                              __SYM1R__,                               _______,
    _______,                  __SYM2L__,                  KC_UNDS,    KC_PLUS,                   __SYM2R__,                 _______,
    _______,                  __SYM3L__,                                                         __SYM3R__,                 _______,
    _______,                  __SYM4L__,                  KC_TILD,    KC_COLN,                   __SYM4R__,                 _______,
    _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______,
                                                 _______, _______,    _______, _______,
                                        /*-----\ /-----*/ _______,    _______, /*-----\ /-----*/
                                        _______, _______, _______,    _______, _______, _______)
, // }}}
[LAYER_NUMPAD] = LAYOUT_wrapper( // {{{
     KC_BSPC, KC_DEL,  XXXXXXX, KC_PSLS, KC_PSLS, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, KC_PSLS, KC_PSLS, XXXXXXX, KC_BSPC, KC_DEL,
     KC_NLCK, KC_P7,   KC_P8,   KC_P9,   KC_PAST, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, KC_PAST, KC_P7,   KC_P8,   KC_P9,   KC_NLCK,
     _______, KC_P4,   KC_P5,   KC_P6,   KC_PMNS, XXXXXXX,                      XXXXXXX, KC_PMNS, KC_P4,   KC_P5,   KC_P6,   _______,
     _______, KC_P1,   KC_P2,   KC_P3,   KC_PPLS, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, KC_PPLS, KC_P1,   KC_P2,   KC_P3,   _______,
     _______, XXXXXXX, KC_PDOT, KC_P0,   KC_PEQL,                                        KC_PEQL, KC_P0,   KC_PDOT, XXXXXXX, _______,
                                                  _______, _______,    _______, _______,
                                         /*-----\ /-----*/ _______,    _______, /*-----\ /-----*/
                                         KC_SPC,  KC_PENT, _______,    _______, KC_PENT, KC_SPC)
//, // }}}
//[LAYER_] = LAYOUT_wrapper( // {{{
//    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
//    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
//    _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
//    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
//    _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______,
//                                                 _______, _______,    _______, _______,
//                                        /*-----\ /-----*/ _______,    _______, /*-----\ /-----*/
//                                        _______, _______, _______,    _______, _______, _______)
//, // }}}
};


// vim: foldmethod=marker cursorcolumn
