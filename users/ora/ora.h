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
// Base Layer
#define __QWER_L1__ KC_1,   KC_2,   KC_3,   KC_4,   KC_5
#define __QWER_R1__ KC_6,   KC_7,   KC_8,   KC_9,   KC_0
#define __QWER_L2__ KC_Q,   KC_W,   KC_E,   KC_R,   KC_T
#define __QWER_R2__ KC_Y,   KC_U,   KC_I,   KC_O,   KC_P
#define __QWER_L3__ KC_A,   KC_S,   KC_D,   KC_F,   KC_G
#define __QWER_R3__ KC_H,   KC_J,   KC_K,   KC_L
#define __QWER_L4__ KC_Z,   KC_X,   KC_C,   KC_V,   KC_B
#define __QWER_R4__ KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH

// Media
#define __MDIA_MC__ MC_MPRV,TD_MPLS,MC_MNXT
#define __MDIA_WN__ WN_MPRV,TD_WPLS,WN_MNXT
#define __VOLM_MC__ MC_VOLD,MC_MUTE,MC_VOLU
#define __VOLM_WN__ WN_VOLD,WN_MUTE,WN_VOLU

// Function Layer
#define __FUNC_L1__ KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5
#define __FUNC_R1__ KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,  KC_F12
#define __FUNC_L2__ KC_HOME,KC_PGUP,KC_PGDN,KC_END
#define __FUNC_R2__ KC_HOME,KC_PGDN,KC_PGUP,KC_END
#define __FUNC_L3__ KC_LEFT,KC_UP,  KC_DOWN,KC_RGHT
#define __FUNC_R3__ KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT

// Symbol Layer
//                   !       @       #       $       %
//                   ^       &      *       (        )      {\n}   ()=>{}
#define __SYMB_L1__ KC_EXLM,KC_AT,  KC_HASH,KC_DLR, KC_PERC
#define __SYMB_R1__ KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,MA_BRNL,MA_LMBD
//                  ||       |       /       -       ?
//                   !       +       *       &      &&
#define __SYMB_L2__ MA_OR,  KC_PIPE,KC_SLSH,KC_MINS,KC_QUES
#define __SYMB_R2__ KC_EXLM,KC_PLUS,KC_ASTR,KC_AMPR,MA_AND
//                  &&       [       {       (       <
//                   >       )       }       ]      ||
#define __SYMB_L3__ MA_AND, KC_LBRC,KC_LCBR,KC_LPRN,KC_LABK
#define __SYMB_R3__ KC_RABK,KC_RPRN,KC_RCBR,KC_RBRC,MA_OR
//                 /*  */    []     {  }     ()      <>
//                  <>      ()     {  }     []   /*  */
#define __SYMB_L4__ MA_PCMT,MA_PBRC,MA_PCBR,MA_PPRN,MA_PABK
#define __SYMB_R4__ MA_PABK,MA_PPRN,MA_PCBR,MA_PBRC,MA_PCMT

// Numpad Layer
#define __NMPD_L1__ KC_BSPC,KC_DEL, KC_PENT,KC_PSLS
#define __NMPD_L2__ KC_P7,  KC_P8,  KC_P9,  KC_PAST
#define __NMPD_L3__ KC_P4,  KC_P5,  KC_P6,  KC_PMNS
#define __NMPD_L4__ KC_P1,  KC_P2,  KC_P3,  KC_PPLS
#define __NMPD_L5__ KC_PDOT,KC_P0,  KC_PEQL

#define __NMPD_R1__ KC_PSLS,KC_PENT,KC_BSPC,KC_DEL
#define __NMPD_R2__ KC_PAST,KC_P7,  KC_P8,  KC_P9
#define __NMPD_R3__ KC_PMNS,KC_P4,  KC_P5,  KC_P6
#define __NMPD_R4__ KC_PPLS,KC_P1,  KC_P2,  KC_P3
#define __NMPD_R5__         KC_PEQL,KC_P0,  KC_PDOT
