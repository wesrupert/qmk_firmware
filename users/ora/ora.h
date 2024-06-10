// Copyright 2022 Wes Rupert (@wesrupert)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include QMK_KEYBOARD_H
#include "quantum.h"
#include "action.h"
#include "version.h"

#if defined(OS_DETECTION_ENABLE)
#include "os_detection.h"
#endif

#if !defined(SUPER_TAB_SWITCHER_TERM)
#define SUPER_TAB_SWITCHER_TERM 500
#endif

bool force_mac_maps;
bool force_win_maps;
bool is_tab_switcher_active;
uint16_t tab_switcher_timer;

// clang-format off

enum layers_user {
    LAYER_BASE = 0,
    LAYER_GAMES,
    LAYER_ENUM_END_USER,
};

enum keycodes_user {
    // General macros
    MA_LAUNCH = SAFE_RANGE,
    MA_OR, MA_AND,
    MA_PBRC, MA_PCBR, MA_PPRN, MA_PABK,
    MA_LMBD, MA_LMBP, MA_BRNL, MA_PCMT,
    
    // Platform keys
    PK_LOCK, PK_TABN,
    PK_PSCF, PK_PSCR,
    PK_MPRV, PK_MNXT,
    PK_VOLD, PK_MUTE, PK_VOLU,
    PK_MONT, PK_SYST,

#if defined(RGB_MATRIX_ENABLE)
    LI_VALU, LI_VALD,
    LI_HUEU, LI_HUED,
    LI_SATU, LI_SATD,
    LI_NEXT, LI_PREV,
    LI_FAST, LI_SLOW,
#endif // RGB_MATRIX_ENABLE

    SAFE_RANGE_USER,
};

// clang-format on

#define _TO_DO_ KC_NO

// Common tap keys
#define LC_TAB C(KC_TAB)
#define CS_TAB C(S(KC_TAB))

#define MT_LABS LALT_T(KC_BSPC)
#define MT_LCEN LCTL_T(KC_ENT)
#define MT_LCES LCTL_T(KC_ESC)
#define MT_LCSP LCTL_T(KC_SPC)
#define MT_LCTB LCTL_T(KC_TAB)
#define MT_RCEN RCTL_T(KC_ENT)
#define MT_RCES RCTL_T(KC_ESC)
#define MT_RCSP RCTL_T(KC_SPC)
#define MT_RCTB RCTL_T(KC_TAB)

#define MT_LAEN LALT_T(KC_ENT)
#define MT_LAES LALT_T(KC_ESC)
#define MT_LASP LALT_T(KC_SPC)
#define MT_LATB LALT_T(KC_TAB)
#define MT_RAEN RALT_T(KC_ENT)
#define MT_RAES RALT_T(KC_ESC)
#define MT_RASP RALT_T(KC_SPC)
#define MT_RATB RALT_T(KC_TAB)

#define MT_LSEN LSFT_T(KC_ENT)
#define MT_LSES LSFT_T(KC_ESC)
#define MT_LSSP LSFT_T(KC_SPC)
#define MT_LSTB LSFT_T(KC_TAB)
#define MT_RSEN RSFT_T(KC_ENT)
#define MT_RSES RSFT_T(KC_ESC)
#define MT_RSSP RSFT_T(KC_SPC)
#define MT_RSTB RSFT_T(KC_TAB)

// Common colors

#define CV_TRANS 255
#define HSV_IS_TRANS(hsv) hsv.h == CV_TRANS && hsv.s == CV_TRANS && hsv.v == CV_TRANS

#define C______ { CV_TRANS, CV_TRANS, CV_TRANS }
#define C_XXXXX { HSV_OFF }
#define C_TO_DO C_XXXXX
#define C_RED   { HSV_RED }
#define C_CORAL { HSV_CORAL }
#define C_ORANG { HSV_ORANGE }
#define C_GLDNR { HSV_GOLDENROD }
#define C_GOLD  { HSV_GOLD }
#define C_YELLW { HSV_YELLOW }
#define C_CHTRS { HSV_CHARTREUSE }
#define C_GREEN { HSV_GREEN }
#define C_SPGRN { HSV_SPRINGGREEN }
#define C_TRQUS { HSV_TURQUOISE }
#define C_TEAL  { HSV_TEAL }
#define C_CYAN  { HSV_CYAN }
#define C_AZURE { HSV_AZURE }
#define C_BLUE  { HSV_BLUE }
#define C_PRPLE { HSV_PURPLE }
#define C_MGNTA { HSV_MAGENTA }
#define C_PINK  { HSV_PINK }
#define C_BLACK { HSV_BLACK }

#define R_SILVR { 0,   0,   111 }
#define R_RED   { 0,   255, 255 }
#define R_ORANG { 13,  255, 255 }
#define R_YELLW { 41,  255, 255 }
#define R_YLGRN { 64,  255, 255 }
#define R_GREEN { 86,  255, 255 }
#define R_AQGRN { 107, 255, 255 }
#define R_AQUA  { 129, 255, 255 }
#define R_AQBLU { 150, 255, 255 }
#define R_BLUE  { 174, 255, 255 }
#define R_PURPL { 217, 255, 255 }
#define R_MGNTA { 246, 255, 255 }

#define CL_BASE R_BLUE
#define CL_GAME R_GREEN
#define CL_FUNC R_PURPL
#define CL_NMPD R_ORANG

#define CK_ALPH R_SILVR
#define CK_MODS R_BLUE
#define CK_MODT R_MGNTA
#define CK_NAVG R_AQGRN
#define CK_META R_PURPL
#define CK_MDIA R_AQUA
#define CK_MOUS R_ORANG
#define CK_WARN R_RED

// clang-format off

// Base Layer
#define __________________QWER_L1__________________ \
        KC_1   , KC_2   , KC_3   , KC_4   , KC_5
#define __________________QWER_R1__________________ \
        KC_6,    KC_7   , KC_8   , KC_9   , KC_0
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
#define __________MEDIA__________ \
        PK_MPRV, KC_MPLY, PK_MNXT
//        PREV    PAUSE     NEXT
#define __________VOLUM__________ \
        PK_VOLD, PK_MUTE, PK_VOLU
//        VOLU     MUTE     VOLD

// Function Layer
#define __________________FUNC_L1__________________ \
        KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5
//        F1       F2       F3       F4       F5
#define __________________FUNC_R1__________________ \
        KC_F6,   KC_F7  , KC_F8  , KC_F9  , KC_F10
//        F6,      F7       F8       F9       F10
#define FUNC_11 \
        KC_F11
//        F11
#define FUNC_12 \
        KC_F12
//        F12
#define _____________FUNC__L2_____________ \
        KC_HOME, KC_PGUP, KC_PGDN, KC_END
//       HOME     PGUP     PGDN      END
#define _____________FUNC__R2_____________ \
        KC_HOME, KC_PGDN, KC_PGUP, KC_END
//       HOME     PGDN     PGUP      END
#define _____________FUNC__L3_____________ \
        KC_LEFT, KC_UP  , KC_DOWN, KC_RGHT
//       LEFT      UP      DOWN     RIGHT
#define _____________FUNC__R3_____________ \
        KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
//       LEFT     DOWN      UP      RIGHT

// Symbol Layer
#define __________________SYMB_L1__________________ \
        KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC
//         !        @        #        $        %
#define __________________SYMB_R1__________________ \
        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN
//          ^       &        *        (        )
#define SYM_SL1 \
        MA_BRNL
//       {\n}
#define SYM_SR1 \
        MA_LMBD
//      ()=>{}
#define __________________SYMB_L2__________________ \
        MA_AND , KC_SLSH, KC_AMPR, KC_MINS, KC_UNDS
//        &&        /        &        -        _
#define __________________SYMB_R2__________________ \
        KC_EQL,  KC_PLUS, KC_PIPE, KC_BSLS, MA_OR
//         =        +        |        \       ||
#define __________________SYMB_L3__________________ \
        MA_AND , KC_LBRC, KC_LCBR, KC_LPRN, KC_LABK
//         &&       [        {        (        <
#define __________________SYMB_R3__________________ \
        KC_RABK, KC_RPRN, KC_RCBR, KC_RBRC, MA_OR
//         >        )        }        ]        ||
#define __________________SYMB_L4__________________ \
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5
//         1        2        3        4        5
#define __________________SYMB_R4__________________ \
        KC_6,    KC_7,    KC_8,    KC_9,    KC_0
//         6        7        8        9        0

// Numpad Layer Left
#define __________NMPD_1_________ \
        KC_P7  , KC_P8  , KC_P9
//         7        8        9
#define __________NMPD_2_________ \
        KC_P4  , KC_P5  , KC_P6
//         4        5        6
#define __________NMPD_3_________ \
        KC_P1  , KC_P2  , KC_P3
//         1        2        3
#define NMPD__4 \
        KC_P0
//         0

// clang-format on

#if defined(TAP_DANCE_ENABLE)

typedef enum {
    TD_NONE, TD_UNKNOWN,
    TD_SINGLE_TAP, TD_SINGLE_HOLD,
    TD_DOUBLE_TAP, TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP,
    TD_TRIPLE_TAP, TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool       is_press_action;
    td_state_t state;
} td_tap_t;

td_state_t cur_dance(tap_dance_state_t *state);
td_state_t hold_cur_dance(tap_dance_state_t *state);

// clang-format off

#define PLATFORM_IS_MAC !force_win_maps && (force_mac_maps || OS_MACOS == detected_host_os())

#define MACRO_SEND_ON_PRESS(KEY, STRING) \
    case KEY: if (record->event.pressed) { SEND_STRING(STRING); return false; } return true

#define MACRO_SEND_PLAT_ON_PRESS(KEY, WIN, MAC) \
    case KEY: if (record->event.pressed) { \
        if (PLATFORM_IS_MAC) SEND_STRING(MAC); \
        else SEND_STRING(WIN); \
        return false; \
    } return true

#define DANCE_MACRO_MOD(NR, MOD) \
        td_state_t dance_DMCRO##NR##_##MOD##_state = 0; \
        void dance_DMCRO##NR##_##MOD##_finished(tap_dance_state_t *state, void *user_data) { \
            dance_DMCRO##NR##_##MOD##_state = hold_cur_dance(state); \
            keyrecord_t kr; \
            kr.event.pressed = false; \
            switch (dance_DMCRO##NR##_##MOD##_state) { \
                case TD_SINGLE_HOLD: \
                    register_code(KC_##MOD); \
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
        void dance_DMCRO##NR##_##MOD##_reset(tap_dance_state_t *state, void *user_data) { \
            switch (dance_DMCRO##NR##_##MOD##_state) { \
                case TD_SINGLE_HOLD: \
                    unregister_code(KC_##MOD); \
                    break; \
                default: \
                    break; \
            } \
            dance_DMCRO##NR##_##MOD##_state = 0; \
        }

#define DANCE_LEADER_MOD(MOD) \
        td_state_t dance_LEADER_##MOD##_state = 0; \
        void dance_LEADER_##MOD##_finished(tap_dance_state_t *state, void *user_data) { \
            dance_LEADER_##MOD##_state = hold_cur_dance(state); \
            switch (dance_LEADER_##MOD##_state) { \
                case TD_SINGLE_TAP: \
                    leader_start(); \
                    break; \
                case TD_DOUBLE_TAP: \
                    tap_code(KC_ESC); \
                    break; \
                case TD_SINGLE_HOLD: \
                    register_code(KC_##MOD); \
                    break; \
                default: /* PK_LOCK */ \
                    if (PLATFORM_IS_MAC) SEND_STRING(SS_LGUI(SS_LCTL("q"))); \
                    else SEND_STRING(SS_LGUI("l")); \
                    break; \
            } \
        } \
        void dance_LEADER_##MOD##_reset(tap_dance_state_t *state, void *user_data) { \
            switch (dance_LEADER_##MOD##_state) { \
                case TD_SINGLE_HOLD: \
                    unregister_code(KC_##MOD); \
                    break; \
                default: \
                    break; \
            } \
            dance_LEADER_##MOD##_state = 0; \
        } \

#define DANCE_MOD_TAP_LAYER_TOGGLE(MOD, LAYER) \
        td_state_t dance_##LAYER##_##MOD##_state = 0; \
        void dance_##LAYER##_##MOD##_finished(tap_dance_state_t *state, void *user_data) { \
            dance_##LAYER##_##MOD##_state = hold_cur_dance(state); \
            switch (dance_##LAYER##_##MOD##_state) { \
                case TD_SINGLE_TAP: \
                    layer_invert(LAYER); \
                    break; \
                case TD_SINGLE_HOLD: \
                    register_code(KC_##MOD); \
                    break; \
                default: \
                    break; \
            } \
        } \
        void dance_##LAYER##_##MOD##_reset(tap_dance_state_t *state, void *user_data) { \
            switch (dance_##LAYER##_##MOD##_state) { \
                case TD_SINGLE_HOLD: \
                    unregister_code(KC_##MOD); \
                    break; \
                default: \
                    break; \
            } \
            dance_##LAYER##_##MOD##_state = 0; \
        }

// clang-format on

#endif // TAP_DANCE_ENABLE
