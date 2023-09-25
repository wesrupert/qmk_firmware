// Copyright 2022 Wes Rupert (@wesrupert)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#define COMBO_SHOULD_TRIGGER

#include QMK_KEYBOARD_H
#include "quantum.h"
#include "action.h"
#include "version.h"

// clang-format off

enum keycodes {
    QWERTY = SAFE_RANGE, COLEMAK, DVORAK, PLOVER, LOWER, RAISE, BACKLIT, EXT_PLV,
    MA_OR, MA_AND, MA_PBRC, MA_PCBR, MA_PPRN, MA_PABK, MA_LMBD, MA_BRNL, MA_PCMT
};

// clang-format on

#if defined(TAP_DANCE_ENABLE)

#define WN_PLPS TD(TAP_DANCE_PLAY_PAUSE_SPOTIFY)
#define MC_PLPS WN_PLPS

#else

#define WN_PLPS WN_MPLY
#define MC_PLPS MC_MPLY

#endif // TAP_DANCE_ENABLE

// clang-format off

enum layers {
    LAYER_WIN = 0, LAYER_MAC,
    LAYER_GAMES, LAYER_NUMPAD, LAYER_SYMBOLS,
    LAYER_WINFUN, LAYER_MACFUN,
    LAYER_ENUM_END
};

// clang-format on

#define LAUNCH_APP_RET(WNAPP, MCAPP)  \
    do {                              \
        if (IS_LAYER_ON(LAYER_WIN)) { \
            SEND_STRING(WN_LAUNCH);   \
            wait_ms(250);             \
            SEND_STRING(WNAPP);       \
        } else {                      \
            SEND_STRING(MC_LAUNCH);   \
            wait_ms(250);             \
            SEND_STRING(MCAPP);       \
        }                             \
        wait_ms(250);                 \
        SEND_STRING(SS_TAP(X_ENTER)); \
        return;                       \
    } while (false)

// Common tap keys
#define LT_SYEN LT(LAYER_SYMBOLS, KC_ENT)
#define LT_SYES LT(LAYER_SYMBOLS, KC_ESC)
#define LT_SYSP LT(LAYER_SYMBOLS, KC_SPC)
#define TT_NMPD TT(LAYER_NUMPAD)
#define MT_LABS LALT_T(KC_BSPC)

#define MT_LCEN LCTL_T(KC_ENT)
#define MT_LCES LCTL_T(KC_ESC)
#define MT_LCSP LCTL_T(KC_SPC)
#define MT_RCEN RCTL_T(KC_ENT)
#define MT_RCES RCTL_T(KC_ESC)
#define MT_RCSP RCTL_T(KC_SPC)

#define MT_LAEN LALT_T(KC_ENT)
#define MT_LAES LALT_T(KC_ESC)
#define MT_LASP LALT_T(KC_SPC)
#define MT_RAEN RALT_T(KC_ENT)
#define MT_RAES RALT_T(KC_ESC)
#define MT_RASP RALT_T(KC_SPC)

#define MT_LSEN LSFT_T(KC_ENT)
#define MT_LSES LSFT_T(KC_ESC)
#define MT_LSSP LSFT_T(KC_SPC)
#define MT_RSEN RSFT_T(KC_ENT)
#define MT_RSES RSFT_T(KC_ESC)
#define MT_RSSP RSFT_T(KC_SPC)

// Platform-specific keys
#define MC_LAUNCH SS_LGUI(" ")
#define MC_COPY LGUI(KC_C)
#define MC_CUT LGUI(KC_X)
#define MC_SALL LGUI(KC_A)
#define MC_PSTE LGUI(KC_V)
#define MC_UNDO LGUI(KC_Z)

#define MC_LOCK LGUI(LCTL(KC_Q))
#define MC_MNXT KC_MFFD
#define MC_MPLY KC_MPLY
#define MC_MPRV KC_MRWD
#define MC_MUTE KC_KB_MUTE
#define MC_PSCF LGUI(LSFT(KC_4))
#define MC_PSCR LGUI(LCTL(LSFT(KC_4)))
#define MC_VOLD KC_KB_VOLUME_DOWN
#define MC_VOLU KC_KB_VOLUME_UP
#define MC_FNES LT(LAYER_MACFUN, KC_ESC)
#define MC_FNEN LT(LAYER_MACFUN, KC_ENT)
#define MC_FNSP LT(LAYER_MACFUN, KC_SPC)

#define WN_LAUNCH SS_LGUI(" ")
#define WN_COPY LCTL(KC_C)
#define WN_CUT LCTL(KC_X)
#define WN_SALL LCTL(KC_A)
#define WN_PSTE LCTL(KC_V)
#define WN_UNDO LGUI(KC_Z)

#define WN_LOCK LGUI(KC_L)
#define WN_MNXT KC_MNXT
#define WN_MPLY KC_MPLY
#define WN_MPRV KC_MPRV
#define WN_MUTE KC_MUTE
#define WN_PSCF LGUI(KC_PSCR)
#define WN_PSCR KC_PSCR
#define WN_VOLD KC_VOLD
#define WN_VOLU KC_VOLU
#define WN_FNES LT(LAYER_WINFUN, KC_ESC)
#define WN_FNEN LT(LAYER_WINFUN, KC_ENT)
#define WN_FNSP LT(LAYER_WINFUN, KC_SPC)

// Common key groupings
// clang-format off

// Base Layer
#define ______________________QWER__L1______________________ \
        KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6
#define _____________QWER__R1_____________ \
        KC_7   , KC_8   , KC_9   , KC_0
#define __________________QWER_L2__________________ \
        KC_Q   , KC_W   , KC_E   , KC_R   , KC_T
#define __________________QWER_R2__________________ \
        KC_Y   , KC_U   , KC_I   , KC_O   , KC_P
#define __________________QWER_L3__________________ \
        KC_A   , KC_S   , KC_D   , KC_F   , KC_G
#define _____________QWER__R3_____________ \
        KC_H   , KC_J   , KC_K   , KC_L
#define __________________QWER_L4__________________ \
        KC_Z   , KC_X   , KC_C   , KC_V   , KC_B
#define __________________QWER_R4__________________ \
        KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH

// Media
//        PREV    PAUSE     NEXT
#define _________MDIA_MC_________ \
        MC_MPRV, MC_PLPS, MC_MNXT
//        PREV    PAUSE     NEXT
#define _________MDIA_WN_________ \
        WN_MPRV, WN_PLPS, WN_MNXT
//        VOLU     MUTE     VOLD
#define _________VOLM_MC_________ \
        MC_VOLD, MC_MUTE, MC_VOLU
//        VOLU     MUTE     VOLD
#define _________VOLM_WN_________ \
        WN_VOLD, WN_MUTE, WN_VOLU

// Function Layer
//        F1       F2       F3       F4       F5       F6
#define ______________________FUNC__L1______________________ \
        KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6
//        F7       F8       F9       F10      F11      F12
#define ______________________FUNC__R1______________________ \
        KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12
//       HOME     PGUP     PGDN      END
#define _____________FUNC__L2_____________ \
        KC_HOME, KC_PGUP, KC_PGDN, KC_END
//       HOME     PGDN     PGUP      END
#define _____________FUNC__R2_____________ \
        KC_HOME, KC_PGDN, KC_PGUP, KC_END
//       LEFT      UP      DOWN     RIGHT
#define _____________FUNC__L3_____________ \
        KC_LEFT, KC_UP  , KC_DOWN, KC_RGHT
//       LEFT     DOWN      UP      RIGHT
#define _____________FUNC__R3_____________ \
        KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT

// Symbol Layer
//         !        @        #        $        %        ^
#define ______________________SYMB__L1______________________ \
        KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC
//         &        *        (        )      {\n}    ()=>{}
#define ______________________SYMB__R1______________________ \
        KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, MA_BRNL, MA_LMBD
//        ||        |        /        -        ?
#define __________________SYMB_L2__________________ \
        MA_OR  , KC_PIPE, KC_SLSH, KC_MINS, KC_QUES
//         !        +        *        &       &&
#define __________________SYMB_R2__________________ \
        KC_EXLM, KC_PLUS, KC_ASTR, KC_AMPR, MA_AND
//         &&       [        {        (        <
#define __________________SYMB_L3__________________ \
        MA_AND , KC_LBRC, KC_LCBR, KC_LPRN, KC_LABK
//         >        )        }        ]        ||
#define __________________SYMB_R3__________________ \
        KC_RABK, KC_RPRN, KC_RCBR, KC_RBRC, MA_OR
//       /*   */     []      {   }     ()      <>
#define __________________SYMB_L4__________________ \
        MA_PCMT, MA_PBRC, MA_PCBR, MA_PPRN, MA_PABK
//         <>       ()      {   }      []    /*  */
#define __________________SYMB_R4__________________ \
        MA_PABK, MA_PPRN, MA_PCBR, MA_PBRC, MA_PCMT

// Numpad Layer Left
//        NumLk     /        *        -
#define ______________NMPD_1______________ \
        KC_NUM , KC_PSLS, KC_PAST, KC_PMNS
//         7        8        9        +
#define ______________NMPD_2______________ \
        KC_P7  , KC_P8  , KC_P9  , KC_PPLS
//         4        5        6      enter
#define ______________NMPD_3______________ \
        KC_P4  , KC_P5  , KC_P6  , KC_PENT
//         1        2        3
#define __________NMPD_4_________ \
        KC_P1  , KC_P2  , KC_P3
//         0        .
#define _____NMPD_5_____ \
        KC_PDOT, KC_P0

// clang-format on

#if defined(TAP_DANCE_ENABLE)

typedef enum {
    TD_NONE, TD_UNKNOWN,
    TD_SINGLE_TAP, TD_SINGLE_HOLD,
    TD_DOUBLE_TAP, TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP,
    TD_TRIPLE_TAP, TD_TRIPLE_HOLD
} td_state_t;

// clang-format on
typedef struct {
    bool       is_press_action;
    td_state_t state;
} td_tap_t;

td_state_t cur_dance(tap_dance_state_t *state);
td_state_t hold_cur_dance(tap_dance_state_t *state);

// clang-format off

#define DANCE_SPOTIFY \
        void dance_playpause_spotify(tap_dance_state_t *state, void *user_data) { \
            if (state->count == 1) { \
                if (IS_LAYER_ON(LAYER_WIN)) { \
                    tap_code(WN_MPLY); \
                } else { \
                    tap_code(MC_MPLY); \
                } \
            } else if (state->count == 2) { \
                LAUNCH_APP_RET("spotify", "spotify"); \
            } \
        } \

#define DANCE_MCRO(NR, hand, HAND, mod, MOD) \
        td_state_t dance_dm_##NR##_##hand##_##mod##_state = 0; \
        void dance_dm_##NR##_##hand##_##mod##_finished(tap_dance_state_t *state, void *user_data) { \
            dance_dm_##NR##_##hand##_##mod##_state = hold_cur_dance(state); \
            keyrecord_t kr; \
            kr.event.pressed = false; \
            switch (dance_dm_##NR##_##hand##_##mod##_state) { \
                case TD_SINGLE_HOLD: \
                    register_code(KC_##HAND##MOD); \
                    break; \
                case TD_SINGLE_TAP: \
                    process_dynamic_macro(DM_PLY##NR, &kr); \
                    break; \
                case TD_DOUBLE_TAP: \
                    kr.event.pressed = true; \
                    process_dynamic_macro(DM_RSTP, &kr); \
                    break; \
                case TD_TRIPLE_TAP: \
                    process_dynamic_macro(DM_REC##NR, &kr); \
                    break; \
                default: \
                    break; \
            } \
        } \
        void dance_dm_##NR##_##hand##_##mod##_reset(tap_dance_state_t *state, void *user_data) { \
            switch (dance_dm_##NR##_##hand##_##mod##_state) { \
                case TD_SINGLE_HOLD: \
                    unregister_code(KC_##HAND##MOD); \
                    break; \
                default: \
                    break; \
            } \
            dance_dm_##NR##_##hand##_##mod##_state = 0; \
        }

#define DANCE_LEAD(hand, HAND, mod, MOD) \
        td_state_t dance_lead_##hand##_##mod##_state = 0; \
        void dance_lead_##hand##_##mod##_finished(tap_dance_state_t *state, void *user_data) { \
            dance_lead_##hand##_##mod##_state = hold_cur_dance(state); \
            switch (dance_lead_##hand##_##mod##_state) { \
                case TD_SINGLE_TAP: \
                    leader_start(); \
                    break; \
                case TD_SINGLE_HOLD: \
                    register_code(KC_##HAND##MOD); \
                    break; \
                default: \
                    break; \
            } \
        } \
        void dance_lead_##hand##_##mod##_reset(tap_dance_state_t *state, void *user_data) { \
            switch (dance_lead_##hand##_##mod##_state) { \
                case TD_SINGLE_HOLD: \
                    unregister_code(KC_##HAND##MOD); \
                    break; \
                default: \
                    break; \
            } \
            dance_lead_##hand##_##mod##_state = 0; \
        }

#define DANCE_NUMP(hand, HAND, mod, MOD) \
        td_state_t dance_nump_##hand##_##mod##_state = 0; \
        void dance_nump_##hand##_##mod##_finished(tap_dance_state_t *state, void *user_data) { \
            dance_nump_##hand##_##mod##_state = hold_cur_dance(state); \
            switch (dance_nump_##hand##_##mod##_state) { \
                case TD_SINGLE_TAP: \
                    layer_invert(LAYER_NUMPAD); \
                    break; \
                case TD_SINGLE_HOLD: \
                    register_code(KC_##HAND##MOD); \
                    break; \
                default: \
                    break; \
            } \
        } \
        void dance_nump_##hand##_##mod##_reset(tap_dance_state_t *state, void *user_data) { \
            switch (dance_nump_##hand##_##mod##_state) { \
                case TD_SINGLE_HOLD: \
                    unregister_code(KC_##HAND##MOD); \
                    break; \
                default: \
                    break; \
            } \
            dance_nump_##hand##_##mod##_state = 0; \
        }

// clang-format on

#endif // TAP_DANCE_ENABLE
