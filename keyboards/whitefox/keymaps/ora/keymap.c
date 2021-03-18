#include QMK_KEYBOARD_H
#include "ora.h"
#include "version.h"

#define LT_FNSP LT(LAYER_FUNCTION, KC_SPC)
#define LT_WFNS LT(LAYER_WINFUN, KC_SPC)
#define LT_SYES LT(LAYER_SYMBOLS, KC_ESC)
#define MT_LCES LCTL_T(KC_ESC)
#define MT_RCEN RCTL_T(KC_ENT)

// Expand key groups before passing into layout macro.
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LAYER_BASE] = LAYOUT_wrapper( // {{{
    KC_GRV,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,KC_LEAD,MC_LOCK,
    KC_TAB,     KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,      TD_DMC1,
    MT_LCES,      KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,__MIS__,  MT_RCEN,  KC_PGUP,
    KC_LSFT,__MIS__,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,     KC_RSFT,     KC_UP,  KC_PGDN,
    KC_LALT,KC_LGUI,LT_SYES,                        LT_FNSP,                        LT_SYES,KC_RGUI,__MIS__,  KC_LEFT,KC_DOWN,KC_RGHT),
// }}}
[LAYER_WIN] = LAYOUT_wrapper( // {{{
    _______,  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,WN_LOCK,
    _______,    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,      _______,
    _______,      _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,__MIS__,  _______,  _______,
    _______,__MIS__,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     _______,     _______,_______,
    _______,_______,_______,                        LT_WFNS,                        _______,_______,__MIS__,  _______,_______,_______),
// }}}
[LAYER_GAMES] = LAYOUT_wrapper( // {{{
    KC_GRV,   _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,      _______,
    KC_LCTL,      _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,__MIS__,  _______,  _______,
    KC_LSFT,__MIS__,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     _______,     _______,_______,
    KC_LALT,KC_LGUI,KC_ESC,                         _______,                        _______,_______,__MIS__,  _______,_______,_______),
// }}}
[LAYER_FUNCTION] = LAYOUT_wrapper( // {{{
    KC_GRV,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_DEL, XXXXXXX,XXXXXXX,
    KC_CAPS,    MC_MPRV,MC_MPLY,MC_MNXT,XXXXXXX,XXXXXXX,KC_HOME,KC_PGDN,KC_PGUP,KC_END, MC_PSCR,MC_PSCF,XXXXXXX,XXXXXXX,      TD_DMC2,
    KC_CAPS,      MC_VOLD,MC_MUTE,MC_VOLU,XXXXXXX,XXXXXXX,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,XXXXXXX,XXXXXXX,__MIS__,  MC_MUTE,  KC_PGUP,
    _______,__MIS__,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,     MC_MPLY,     MC_VOLU,KC_PGDN,
    _______,_______,_______,                        _______,                        _______,_______,__MIS__,  MC_MPRV,MC_VOLD,MC_MNXT),
// }}}
[LAYER_WINFUN] = LAYOUT_wrapper( // {{{
    KC_GRV,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_DEL, XXXXXXX,XXXXXXX,
    KC_CAPS,    WN_MPRV,WN_MPLY,WN_MNXT,XXXXXXX,XXXXXXX,KC_HOME,KC_PGDN,KC_PGUP,KC_END, WN_PSCR,WN_PSCF,XXXXXXX,XXXXXXX,      TD_DMC2,
    KC_CAPS,      WN_VOLD,WN_MUTE,WN_VOLU,XXXXXXX,XXXXXXX,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,XXXXXXX,XXXXXXX,__MIS__,  WN_MUTE,  KC_PGUP,
    _______,__MIS__,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,     WN_MPLY,     WN_VOLU,KC_PGDN,
    _______,_______,_______,                        _______,                        _______,_______,__MIS__,  WN_MPRV,WN_VOLD,WN_MNXT),
// }}}
[LAYER_SYMBOLS] = LAYOUT_wrapper( // {{{
    KC_TILD,                           __SYM1L__,                           __SYM1R__,                        _______,_______,_______,
    _______,                        __SYM2L__,                    __SYM2R__,                    KC_LPRN,KC_RPRN,_______,      _______,
    _______,                          __SYM3L__,                    __SYM3R__,                    KC_DQUO,__MIS__,  _______,  _______,
    _______,__MIS__,                    __SYM4L__,                     __SYM4R__,                        _______,     _______,_______,
    _______,_______,_______,                        _______,                        _______,_______,__MIS__,  _______,_______,_______),
// }}}
[LAYER_NUMPAD] = LAYOUT_wrapper( // {{{
    KC_NLCK,  KC_PMNS,KC_PPLS,KC_PSLS,KC_PAST,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,
    KC_BSPC,    KC_P7,  KC_P8,  KC_P9,  KC_PEQL,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,      XXXXXXX,
    _______,      KC_P4,  KC_P5,  KC_P6,  KC_PCMM,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,__MIS__,  _______,  _______,
    _______,__MIS__,KC_P1,  KC_P2,  KC_P3,  KC_PDOT,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,     _______,     _______,_______,
    _______,_______,KC_P0,                          KC_PENT,                        _______,_______,__MIS__,  _______,_______,_______),
// }}}
/* [LAYER_TYPE] = LAYOUT_wrapper( // {{{
    _______,  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,      _______,
    _______,      _______,_______,_______,___F___,_______,_______,___J___,_______,_______,_______,_______,__MIS__,  _______,  _______,
    _______,__MIS__,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     _______,     _______,_______,
    _______,_______,_______,                        _______,                        _______,_______,__MIS__,  _______,_______,_______), */
// }}}
};

// vim: foldmethod=marker cursorcolumn
