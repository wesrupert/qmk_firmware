#include QMK_KEYBOARD_H
#include "ora.h"
#include "version.h"

#define LT_FNSP LT(LAYER_FUNCTION, KC_SPC)
#define LT_FNES LT(LAYER_FUNCTION, KC_ESC)
#define LT_WFNS LT(LAYER_WINFUN, KC_SPC)
#define LT_SYES LT(LAYER_SYMBOLS, KC_ESC)
#define LT_SYBS LT(LAYER_SYMBOLS, KC_BSPC)
#define MT_LCES LCTL_T(KC_ESC)
#define MT_RCEN RCTL_T(KC_ENT)

// Expand key groups before passing into layout macro.
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LAYER_BASE] = LAYOUT_wrapper( // {{{
    KC_GRV,                        __QWER_L1__,                   __QWER_R1__,                KC_MINS,KC_EQL, KC_BSPC,KC_LEAD,TD_DMC1,
    KC_TAB,                        __QWER_L2__,                   __QWER_R2__,                  KC_LBRC,KC_RBRC,KC_BSLS,      MC_MPLY,
    MT_LCES,                       __QWER_L3__,                   __QWER_R3__,            KC_SCLN,KC_QUOT,__MIS__,  MT_RCEN,  MC_MNXT,
    KC_LSFT,__MIS__,               __QWER_L4__,                   __QWER_R4__,                           KC_RSFT,     KC_UP,  MC_MPRV,
    KC_LALT,KC_LGUI,LT_SYES,                       LT_FNSP,                        LT_SYBS,KC_RGUI,__MIS__,  KC_LEFT,KC_DOWN,KC_RGHT),
// }}}
[LAYER_WIN] = LAYOUT_wrapper( // {{{
    _______,  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,WN_LOCK,
    _______,    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,      WN_MPLY,
    _______,      _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,__MIS__,  _______,  WN_MNXT,
    _______,__MIS__,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     _______,     _______,WN_MPRV,
    _______,_______,_______,                        LT_WFNS,                        _______,_______,__MIS__,  _______,_______,_______),
// }}}
[LAYER_GAMES] = LAYOUT_wrapper( // {{{
    KC_GRV,   _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,      _______,
    KC_LCTL,      _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,__MIS__,  _______,  _______,
    KC_LSFT,__MIS__,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     _______,     _______,_______,
    KC_LALT,KC_LGUI,KC_ESC,                         KC_SPC,                         LT_FNES,_______,__MIS__,  _______,_______,_______),
// }}}
[LAYER_FUNCTION] = LAYOUT_wrapper( // {{{
    KC_GRV,                        __FUNC_L1__,                   __FUNC_R1__,                                KC_DEL, TD_DMC2,MC_LOCK,
    _______,XXXXXXX,               __FUNC_L2__,                   __FUNC_R2__,          MC_PSCR,MC_PSCF,XXXXXXX,XXXXXXX,      MC_MUTE,
    KC_CAPS,XXXXXXX,               __FUNC_L3__,                   __FUNC_R3__,            XXXXXXX,XXXXXXX,__MIS__,  _______,  MC_VOLU,
    _______,__MIS__,     __VOLM_MC__,       XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,      __VOLM_MC__,           _______,     KC_PGUP,MC_VOLD,
    _______,_______,_______,                        _______,                        _______,_______,__MIS__,  KC_HOME,KC_PGDN,KC_END),
// }}}
[LAYER_WINFUN] = LAYOUT_wrapper( // {{{
    KC_GRV,                        __FUNC_L1__,                   __FUNC_R1__,                                KC_DEL, TD_DMC2,WN_LOCK,
    _______,XXXXXXX,               __FUNC_L2__,                   __FUNC_R2__,          WN_PSCR,WN_PSCF,XXXXXXX,XXXXXXX,      WN_MUTE,
    KC_CAPS,XXXXXXX,               __FUNC_L3__,                   __FUNC_R3__,            XXXXXXX,XXXXXXX,__MIS__,  _______,  WN_VOLU,
    _______,__MIS__,     __VOLM_WN__,       XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,      __VOLM_WN__,           _______,     KC_PGUP,WN_VOLD,
    _______,_______,_______,                        _______,                        _______,_______,__MIS__,  KC_HOME,KC_PGDN,KC_END),
// }}}
[LAYER_SYMBOLS] = LAYOUT_wrapper( // {{{
    KC_TILD,                       __SYMB_L1__,                   __SYMB_R1__,                                _______,_______,_______,
    _______,                       __SYMB_L2__,                   __SYMB_R2__,                  KC_LPRN,KC_RPRN,_______,      _______,
    _______,                       __SYMB_L3__,                   __SYMB_R3__,                    KC_DQUO,__MIS__,  _______,  _______,
    _______,__MIS__,               __SYMB_L4__,                   __SYMB_R4__,                           _______,     _______,_______,
    _______,_______,_______,                        _______,                        _______,_______,__MIS__,  _______,_______,_______),
// }}}
[LAYER_NUMPAD] = LAYOUT_wrapper( // {{{
    KC_NLCK,           __NMPD_L1__,           XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,
    KC_BSPC,           __NMPD_L2__,             XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,      XXXXXXX,
    _______,           __NMPD_L3__,               XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,__MIS__,  _______,  _______,
    _______,__MIS__,   __NMPD_L4__,                 XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,     _______,     _______,_______,
    _______,           __NMPD_L5__,                                                 KC_P0,  KC_PDOT,__MIS__,  _______,_______,_______),
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
