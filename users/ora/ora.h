#pragma once

#include QMK_KEYBOARD_H
#include "quantum.h"
#include "action.h"
#include "version.h"

enum keycodes {
    QWERTY = SAFE_RANGE, COLEMAK, DVORAK, PLOVER, LOWER, RAISE, BACKLIT, EXT_PLV,
    MA_OR, MA_AND, MA_PBRC, MA_PCBR, MA_PPRN, MA_PABK, MA_LMBD, MA_BRNL, MA_PCMT
};

enum tap_dances {
    TAP_DANCE_LAYERS = 0,
    TAP_DANCE_DYN_MACRO_1,
    TAP_DANCE_DYN_MACRO_2,
    TAP_DANCE_MAC_PLAYPAUSE_SPOTIFY,
    TAP_DANCE_WIN_PLAYPAUSE_SPOTIFY,
    X_TAP_DANCE
};


enum layers {
    LAYER_BASE = 0, LAYER_WIN, LAYER_GAMES, LAYER_FUNCTION, LAYER_WINFUN,
    LAYER_SYMBOLS, LAYER_NUMPAD, LAYER_ENUM_END
};

#define LAUNCH_APP(string) do { \
    if (IS_LAYER_ON(LAYER_WIN)) { SEND_STRING(WN_LAUNCH); } else { SEND_STRING(MC_LAUNCH); } \
    wait_ms(250); SEND_STRING(string); wait_ms(250); \
    SEND_STRING(SS_TAP(X_ENTER)); \
} while (false)

// Platform-specific keys
#define MC_LAUNCH SS_LGUI(" ")
#define MC_LOCK LGUI(LCTL(KC_Q))
#define MC_MNXT KC_MFFD
#define MC_MPLY KC_MPLY
#define MC_MPRV KC_MRWD
#define MC_MUTE KC__MUTE
#define MC_PSCF LGUI(LSFT(KC_4))
#define MC_PSCR LGUI(LCTL(LSFT(KC_4)))
#define MC_VOLD KC__VOLDOWN
#define MC_VOLU KC__VOLUP

#define WN_LAUNCH SS_TAP(X_LGUI)
#define WN_LOCK LGUI(KC_L)
#define WN_MNXT KC_MNXT
#define WN_MPLY KC_MPLY
#define WN_MPRV KC_MPRV
#define WN_MUTE KC_MUTE
#define WN_PSCF LGUI(KC_PSCR)
#define WN_PSCR KC_PSCR
#define WN_VOLD KC_VOLD
#define WN_VOLU KC_VOLU

#define DM_RCRD DYN_REC_START1
#define DM_STOP DYN_REC_STOP

#define TD_DMC1 TD(TAP_DANCE_DYN_MACRO_1)
#define TD_DMC2 TD(TAP_DANCE_DYN_MACRO_2)
#define TD_MPLS TD(TAP_DANCE_MAC_PLAYPAUSE_SPOTIFY)
#define TD_WPLS TD(TAP_DANCE_WIN_PLAYPAUSE_SPOTIFY)

// XY_ABCD alternates
#define __MIS__ KC_NO

// Common key groupings

// Symbol Layers
//                   !       @       #       $       %
#define __SYM1L__ KC_EXLM,KC_AT,  KC_HASH,KC_DLR, KC_PERC
//                  ||       |       /       -       ?
#define __SYM2L__ MA_OR,  KC_PIPE,KC_SLSH,KC_MINS,KC_QUES
//                  &&       [       {       (       <
#define __SYM3L__ MA_AND, KC_LBRC,KC_LCBR,KC_LPRN,KC_LABK
//                 /*  */    []     {  }     ()      <>
#define __SYM4L__ MA_PCMT,MA_PBRC,MA_PCBR,MA_PPRN,MA_PABK

//                   ^       &      *       (        )      {\n}   ()=>{}
#define __SYM1R__ KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,MA_BRNL,MA_LMBD
//                   !       +       *       &      &&
#define __SYM2R__ KC_EXLM,KC_PLUS,KC_ASTR,KC_AMPR,MA_AND
//                   >       )       }       ]      ||
#define __SYM3R__ KC_RABK,KC_RPRN,KC_RCBR,KC_RBRC,MA_OR
//                  <>      ()     {  }     []   /*  */
#define __SYM4R__ MA_PABK,MA_PPRN,MA_PCBR,MA_PBRC,MA_PCMT

